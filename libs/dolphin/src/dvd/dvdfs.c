

#define DVDReadAbsAsyncPrio Dolphin_DVDReadAbsAsyncPrio
#define DVDReadPrio Dolphin_DVDReadPrio
#define cbForReadAsync dvdfs_cbForReadAsync
#define cbForReadSync dvdfs_cbForReadSync
#define currentDirectory lbl_805D7138
#define entryToPath dvdfs_entryToPath

#include <dolphin.h>
#include <dolphin/dvd.h>

#include "dvd/sdk2002/__dvd.h"

struct FSTEntry {
 u32 isDirAndStringOff;
 u32 parentOrPosition;
 u32 nextEntryOrLength;
};


static struct OSBootInfo_s * BootInfo;
static struct FSTEntry * FstStart;
static char * FstStringStart;
static unsigned long MaxEntryNum;
static unsigned long currentDirectory;
struct OSThreadQueue __DVDThreadQueue;
unsigned long __DVDLongFileNameFlag;


static inline BOOL isSame(const char* path, const char* string);
static inline u32 myStrncpy(char* dest, char* src, u32 maxlen);
static u32 entryToPath(u32 entry, char* path, u32 maxlen);
static inline BOOL DVDConvertEntrynumToPath(s32 entrynum, char* path, u32 maxlen);
static void cbForReadAsync(s32 result, DVDCommandBlock* block);
static void cbForReadSync();
static void cbForSeekAsync(long result, struct DVDCommandBlock * block);
static void cbForSeekSync();
static void cbForPrepareStreamAsync(s32 result, DVDCommandBlock* block);
static void cbForPrepareStreamSync();

void __DVDFSInit() {
    BootInfo = (void*)OSPhysicalToCached(0);
    FstStart = BootInfo->FSTLocation;
    if (FstStart) {
        MaxEntryNum = FstStart->nextEntryOrLength;
        FstStringStart = (char*)FstStart + (MaxEntryNum * 0xC);
    }
}


#define entryIsDir(i) (((FstStart[i].isDirAndStringOff & 0xff000000) == 0) ? FALSE : TRUE)
#define stringOff(i) (FstStart[i].isDirAndStringOff & ~0xff000000)
#define parentDir(i) (FstStart[i].parentOrPosition)
#define nextDir(i) (FstStart[i].nextEntryOrLength)
#define filePosition(i) (FstStart[i].parentOrPosition)
#define fileLength(i) (FstStart[i].nextEntryOrLength)

static inline BOOL isSame(const char* path, const char* string) {
    while (*string != '\0') {
        if (tolower(*path++) != tolower(*string++)) {
            return FALSE;
        }
    }

    if ((*path == '/') || (*path == '\0')) {
        return TRUE;
    }

    return FALSE;
}

s32 DVDConvertPathToEntrynum(char* pathPtr) {
    const char* ptr;
    char* stringPtr;
    BOOL isDir;
    u32 length;
    u32 dirLookAt;
    u32 i;
    const char* origPathPtr = pathPtr;
    const char* extentionStart;
    BOOL illegal;
    BOOL extention;

    ASSERTMSGLINE(0x133, pathPtr, "DVDConvertPathToEntrynum(): null pointer is specified  ");

    dirLookAt = currentDirectory;

    while (1) {
        if (*pathPtr == '\0') {
            return (s32)dirLookAt;
        } else if (*pathPtr == '/') {
            dirLookAt = 0;
            pathPtr++;
            continue;
        } else if (*pathPtr == '.') {
            if (*(pathPtr + 1) == '.') {
                if (*(pathPtr + 2) == '/') {
                    dirLookAt = parentDir(dirLookAt);
                    pathPtr += 3;
                    continue;
                } else if (*(pathPtr + 2) == '\0') {
                    return (s32)parentDir(dirLookAt);
                }
            } else if (*(pathPtr + 1) == '/') {
                pathPtr += 2;
                continue;
            } else if (*(pathPtr + 1) == '\0') {
                return (s32)dirLookAt;
            }
        }

        if (__DVDLongFileNameFlag == 0) {
            extention = FALSE;
            illegal = FALSE;

            for (ptr = pathPtr; (*ptr != '\0') && (*ptr != '/'); ptr++) {
                if (*ptr == '.') {
                    if ((ptr - pathPtr > 8) || (extention == TRUE)) {
                        illegal = TRUE;
                        break;
                    }
                    extention = TRUE;
                    extentionStart = ptr + 1;

                } else if (*ptr == ' ')
                    illegal = TRUE;
            }

            if ((extention == TRUE) && (ptr - extentionStart > 3))
                illegal = TRUE;

            if (illegal)
                OSPanic(__FILE__, 0x178,
                    "DVDConvertEntrynumToPath(possibly DVDOpen or DVDChangeDir or DVDOpenDir): "
                    "specified directory or file (%s) doesn't match standard 8.3 format. This is a "
                    "temporary restriction and will be removed soon\n",
                    origPathPtr);
        } else {
            for (ptr = pathPtr; (*ptr != '\0') && (*ptr != '/'); ptr++)
                ;
        }

        isDir = (*ptr == '\0') ? FALSE : TRUE;
        length = (u32)(ptr - pathPtr);

        ptr = pathPtr;

        for (i = dirLookAt + 1; i < nextDir(dirLookAt); i = entryIsDir(i) ? nextDir(i) : (i + 1)) {
            if ((entryIsDir(i) == FALSE) && (isDir == TRUE)) {
                continue;
            }

            stringPtr = FstStringStart + stringOff(i);

            if (isSame(ptr, stringPtr) == TRUE) {
                goto next_hier;
            }
        }

        return -1;

next_hier:
        if (!isDir) {
            return (s32)i;
        }

        dirLookAt = i;
        pathPtr += length + 1;
    }
}



BOOL DVDOpen(char* fileName, DVDFileInfo* fileInfo) {
    s32 entry;
    char currentDir[128];

    ASSERTMSGLINE(0x1E0, fileName, "DVDOpen(): null pointer is specified to file name  ");
    ASSERTMSGLINE(0x1E1, fileInfo, "DVDOpen(): null pointer is specified to file info address  ");

    entry = DVDConvertPathToEntrynum(fileName);

    if (0 > entry) {
        DVDGetCurrentDir(currentDir, 128);
        OSReport("Warning: DVDOpen(): file '%s' was not found under %s.\n", fileName, currentDir);
        return FALSE;
    }

    if (entryIsDir(entry)) {
        ASSERTMSG1LINE(0x1EF, !entryIsDir(entry), "DVDOpen(): directory '%s' is specified as a filename  ", fileName);
        return FALSE;
    }

    fileInfo->startAddr = filePosition(entry);
    fileInfo->length = fileLength(entry);
    fileInfo->callback = (DVDCallback)NULL;
    fileInfo->cb.state = DVD_STATE_END;

    return TRUE;
}

BOOL DVDClose(DVDFileInfo* fileInfo) {
    ASSERTMSGLINE(0x207, fileInfo, "DVDClose(): null pointer is specified to file info address  ");
    DVDCancel(&(fileInfo->cb));
    return TRUE;
}

static inline u32 myStrncpy(char* dest, char* src, u32 maxlen) {
    u32 i = maxlen;

    while ((i > 0) && (*src != 0)) {
        *dest++ = *src++;
        i--;
    }

    return (maxlen - i);
}

static u32 entryToPath(u32 entry, char* path, u32 maxlen) {
    char* name;
    u32 loc;

    if (entry == 0) {
        return 0;
    }

    name = FstStringStart + stringOff(entry);

    loc = entryToPath(parentDir(entry), path, maxlen);

    if (loc == maxlen) {
        return loc;
    }

    *(path + loc++) = '/';

    loc += myStrncpy(path + loc, name, maxlen - loc);

    return loc;
}

static inline BOOL DVDConvertEntrynumToPath(s32 entrynum, char* path, u32 maxlen) {
    u32 loc;

    ASSERTMSG1LINE(0x263, (entrynum >= 0) && (entrynum < MaxEntryNum), "DVDConvertEntrynumToPath: specified entrynum(%d) is out of range  ", entrynum);
    ASSERTMSG1LINE(0x265, maxlen > 1, "DVDConvertEntrynumToPath: maxlen should be more than 1 (%d is specified)", maxlen);
    ASSERTMSGLINE(0x26A, entryIsDir(entrynum), "DVDConvertEntrynumToPath: cannot convert an entry num for a file to path  ");

    loc = entryToPath((u32)entrynum, path, maxlen);

    if (loc == maxlen) {
        path[maxlen - 1] = '\0';
        return FALSE;
    }

    if (entryIsDir(entrynum)) {
        if (loc == maxlen - 1) {
            path[loc] = '\0';
            return FALSE;
        }

        path[loc++] = '/';
    }

    path[loc] = '\0';
    return TRUE;
}

BOOL DVDGetCurrentDir(char* path, u32 maxlen) {
    ASSERTMSG1LINE(0x294, (maxlen > 1), "DVDGetCurrentDir: maxlen should be more than 1 (%d is specified)", maxlen);
    return DVDConvertEntrynumToPath((s32)currentDirectory, path, maxlen);
}

BOOL DVDChangeDir(char* dirName) {
    s32 entry;
    char currentDir[128];

    ASSERTMSGLINE(0x2AA, dirName, "DVDChangeDir(): null pointer is specified to directory name  ");
    entry = DVDConvertPathToEntrynum(dirName);
    ASSERTMSG2LINE(0x2B2, entry >= 0, "DVDChangeDir(): directory '%s' is not found under %s  ", dirName, (DVDGetCurrentDir(currentDir, 128), currentDir));
    ASSERTMSG1LINE(0x2B6, entryIsDir(entry), "DVDChangeDir(): file '%s' is specified as a directory name  ", dirName);

    if ((entry < 0) || (entryIsDir(entry) == FALSE)) {
        return FALSE;
    }

    currentDirectory = (u32)entry;

    return TRUE;
}

BOOL DVDReadAsyncPrio(DVDFileInfo* fileInfo, void* addr, s32 length, s32 offset,
                      DVDCallback callback, s32 prio) {

        ASSERTMSGLINE(0x2D5, fileInfo, "DVDReadAsync(): null pointer is specified to file info address  ");
        ASSERTMSGLINE(0x2D6, addr, "DVDReadAsync(): null pointer is specified to addr  ");
        ASSERTMSGLINE(0x2DA, !OFFSET(addr, 32), "DVDReadAsync(): address must be aligned with 32 byte boundaries  ");
        ASSERTMSGLINE(0x2DC, !(length & 0x1F), "DVDReadAsync(): length must be  multiple of 32 byte  ");
        ASSERTMSGLINE(0x2DE, !(offset & 3), "DVDReadAsync(): offset must be multiple of 4 byte  ");

        if (!((0 <= offset) && (offset < fileInfo->length))) {
            OSPanic(__FILE__, 0x2E3, "DVDReadAsync(): specified area is out of the file  ");
        }

        if (!((0 <= offset + length) && (offset + length < fileInfo->length + DVD_MIN_TRANSFER_SIZE))) {
            OSPanic(__FILE__, 0x2E9, "DVDReadAsync(): specified area is out of the file  ");
        }

        fileInfo->callback = callback;
        DVDReadAbsAsyncPrio(&(fileInfo->cb), addr, length, (s32)(fileInfo->startAddr + offset),
                            cbForReadAsync, prio);

        return TRUE;
}
#ifndef offsetof
#define offsetof(type, memb) ((u32) & ((type*)0)->memb)
#endif

static void cbForReadAsync(s32 result, DVDCommandBlock* block) {
  DVDFileInfo* fileInfo;

  fileInfo = (DVDFileInfo*)((char*)block - offsetof(DVDFileInfo, cb));
  ASSERTLINE(0x2FB, (void*) &fileInfo->cb == (void*) block);
  if (fileInfo->callback) {
    (fileInfo->callback)(result, fileInfo);
  }
}

long DVDReadPrio(struct DVDFileInfo * fileInfo, void * addr, long length, long offset, long prio) {
    int result;
    struct DVDCommandBlock * block;
    long state;
    int enabled;
    long retVal;

    ASSERTMSGLINE(0x31B, fileInfo, "DVDRead(): null pointer is specified to file info address  ");
    ASSERTMSGLINE(0x31C, addr, "DVDRead(): null pointer is specified to addr  ");
    ASSERTMSGLINE(0x320, !OFFSET(addr, 32), "DVDRead(): address must be aligned with 32 byte boundaries  ");
    ASSERTMSGLINE(0x322, !(length & 0x1F), "DVDRead(): length must be  multiple of 32 byte  ");
    ASSERTMSGLINE(0x324, !(offset & 3), "DVDRead(): offset must be multiple of 4 byte  ");

    if (!((0 <= offset) && (offset < fileInfo->length))) {
        OSPanic(__FILE__, 0x329, "DVDRead(): specified area is out of the file  ");
    }

    if (!((0 <= offset + length) && (offset + length < fileInfo->length + DVD_MIN_TRANSFER_SIZE))) {
        OSPanic(__FILE__, 0x32F, "DVDRead(): specified area is out of the file  ");
    }

    block = &fileInfo->cb;
    result = DVDReadAbsAsyncPrio(block, addr, length, fileInfo->startAddr + offset, cbForReadSync, prio);
    if (result == 0) {
        return -1;
    }
    enabled = OSDisableInterrupts();

    while(1) {
        state = ((volatile DVDCommandBlock*)block)->state;
        if (state == 0) {
            retVal = (s32)block->transferredSize;
            break;
        } else if (state == -1) {
            retVal = -1;
            break;
        } else if (state == 10) {
            retVal = -3;
            break;
        }
        OSSleepThread(&__DVDThreadQueue);
    }
    OSRestoreInterrupts(enabled);
    return retVal;
}

static void cbForReadSync() {
    OSWakeupThread(&__DVDThreadQueue);
}























#define RoundUp32KB(x) (((u32)(x) + 32 * 1024 - 1) & ~(32 * 1024 - 1))
#define Is32KBAligned(x) (((u32)(x) & (32 * 1024 - 1)) == 0)










s32 DVDGetTransferredSize(DVDFileInfo* fileinfo) {
    s32 bytes;
    DVDCommandBlock* cb;

    cb = &(fileinfo->cb);

    switch (cb->state) {
        case DVD_STATE_COVER_CLOSED:
        case DVD_STATE_NO_DISK:
        case DVD_STATE_COVER_OPEN:
        case DVD_STATE_WRONG_DISK:
        case DVD_STATE_FATAL_ERROR:
        case DVD_STATE_MOTOR_STOPPED:
        case DVD_STATE_CANCELED:
        case DVD_STATE_RETRY:
        case DVD_STATE_END:
            bytes = (s32)cb->transferredSize;
            break;
        case DVD_STATE_WAITING:
            bytes = 0;
            break;
        case DVD_STATE_BUSY:
            bytes = (s32)(cb->transferredSize + (cb->currTransferSize - __DIRegs[6]));
            break;
        default:
            ASSERTMSG1LINE(0x556, FALSE, "DVDGetTransferredSize(): Illegal state (%d)", cb->state);
            break;
  }
  return bytes;
}
