#ifndef PSO_SYSTEM_MOVIE_MFCI_H
#define PSO_SYSTEM_MOVIE_MFCI_H
#include "types.h"

struct MfciFileEntry {
    s8 used;
    s8 state;
    u8 reserved_02[2];
    s32 block_size;
    s32 file_size;
    s32 sector_count;
    s32 position_sector;
    s32 read_bytes;
    s32 read_sectors;
    char name[0x14];
    s32 read_offset;
    s32 request_size;
};
struct MfciFilePool {
    MfciFileEntry entries[40];
    u8 unknown_tail[4];
};
typedef char MfciFileEntrySize[sizeof(MfciFileEntry) == 0x38 ? 1 : -1];
typedef char MfciFilePoolSize[sizeof(MfciFilePool) == 0x8C4 ? 1 : -1];
#include <stddef.h>
typedef char MfciFileNameOffset[offsetof(MfciFileEntry, name) == 0x1C ? 1 : -1];
typedef char MfciReadOffset[offsetof(MfciFileEntry, read_offset) == 0x30 ? 1 : -1];
typedef char MfciRequestSizeOffset[offsetof(MfciFileEntry, request_size) == 0x34 ? 1 : -1];

s32 mfci_get_num_transferred(MfciFileEntry *file); // inferred: mfCiGetNumTr
void mfci_set_sector_length(MfciFileEntry *file, s32 length); // inferred: mfCiSetSctLen
s32 mfci_get_sector_length(MfciFileEntry *file); // inferred: mfCiGetSctLen
s32 mfci_get_status(MfciFileEntry *file); // inferred: mfCiGetStat
void mfci_stop_transfer(MfciFileEntry *file); // inferred: mfCiStopTr
s32 mfci_request_read(void *handle, s32 sectors, void *buffer);
s32 mfci_get_position(MfciFileEntry* file);
s32 mfci_seek(MfciFileEntry* file, s32 sectors, s32 origin);
void mfci_close(MfciFileEntry* file);
MfciFileEntry* mfci_open(const char* name, s32 entry, s32 mode);
u32 mfci_parse_file_size(char* name);
void mfci_set_error_callback(s32 arg0, s32 arg1);
void mfci_exec_server(void); // inferred: mfCiExecServer

// The device's function table for CRI's file system: cvFsAddDev("MFS", mfci_get_interface, 0) registers
// it. Slot order follows the table at 0x804FA020; the NULL slots are calls this read-only memory device
// does not implement. Slot names inferred from the functions they hold.
struct MfciDeviceInterface {
    void (*exec_server)(void);
    void (*set_error_callback)(s32 callback, s32 context);
    u32 (*get_file_size)(char *name);
    void *pad_0c;
    MfciFileEntry *(*open)(const char *name, s32 entry, s32 mode);
    void (*close)(MfciFileEntry *file);
    s32 (*seek)(MfciFileEntry *file, s32 sectors, s32 origin);
    s32 (*tell)(MfciFileEntry *file);
    s32 (*request_read)(void *handle, s32 sectors, void *buffer);
    void *pad_24;
    void (*stop_transfer)(MfciFileEntry *file);
    s32 (*get_status)(MfciFileEntry *file);
    s32 (*get_sector_length)(MfciFileEntry *file);
    void (*set_sector_length)(MfciFileEntry *file, s32 length);
    s32 (*get_num_transferred)(MfciFileEntry *file);
    void *pad_3c[11];
};
typedef char MfciDeviceInterfaceSize[sizeof(MfciDeviceInterface) == 0x68 ? 1 : -1];

extern MfciDeviceInterface mfci_callback_table;
MfciDeviceInterface *mfci_get_interface(void); // inferred: mfCiGetInterface

#endif
