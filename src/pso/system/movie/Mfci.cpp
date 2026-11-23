// CRI MFCI ("MFCI/GC Ver.1.03", the banner that heads this file's string pool): the memory-file
// device of CRI's file system. A file name is "<address>.<size>" in hex and a read copies from that
// address. mfci_callback_table is the device's function table; mfci_get_interface
// returns it.
#include "types.h"
#include <stdio.h>
#include <string.h>
#include "pso/audio/CriSvm.h"
#include "pso/unk/TLobby.h"
#include "pso/system/movie/Mfci.h"

extern "C" unsigned long strtoul(const char *, char **, int);


// inferred: named after gcrna_version_pointer, the same banner pointer in GCRNA.
extern const char *const volatile mfci_version_pointer = "\nMFCI/GC Ver.1.03 Build:Jun 13 2002 19:01:04\n";

char mfci_error_message_buffer[0x12C];
MfciFilePool mfci_file_pool;
CvFsErrorCallback mfci_error_callback;
s32 mfci_error_callback_context;

inline MfciFileEntry *mfci_find_free_entry(void) {
    MfciFileEntry *r = 0;
    s32 i;
    for (i = 0; i < 40; i++) {
        if (mfci_file_pool.entries[i].used == 0) {
            r = &mfci_file_pool.entries[i];
            break;
        }
    }
    return r;
}

// mfCiOpenEntry, named by its error strings, was dead-stripped by the linker: only those strings
// survive, after the banner at the head of the pool. This body, modelled on mfci_open, is a
// reconstruction that keeps them there.
MfciFileEntry *mfci_open_entry(s32 entry, s32 mode) { // inferred: mfCiOpenEntry
    MfciFileEntry *f;
    if (entry < 0) {
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, "E1041001:invalid entry number.(mfCiOpenEntry)", 0);
        }
        return NULL;
    }
    if (mode != 0) {
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, "E1041002:rw is illigal.(mfCiOpenEntry)", 0);
        }
        return NULL;
    }
    f = mfci_find_free_entry();
    if (f == NULL) {
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, "E1041002:not enough handle resource.(mfCiOpenEntry)", 0);
        }
        return NULL;
    }
    return f;
}

// A file name is "<address>.<size>", two 8-digit hex numbers: returns the address, stores the size.
static u32 mfci_get_adr_size(char *fname, u32 *size) {
    char *end;
    u32 v;
    if (strlen(fname) != 17) {
        sprintf(mfci_error_message_buffer, "E01100308:length of '%s' is not 17 bytes.(mfci_get_adr_size)", fname);
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, mfci_error_message_buffer, 0);
        }
    }
    if (fname[8] != '.') {
        sprintf(mfci_error_message_buffer, "E01100309:illegal file name format '%s'(mfci_get_adr_size)", fname);
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, mfci_error_message_buffer, 0);
        }
    }
    end = fname;
    v = strtoul(fname, &end, 16);
    if (*end != 0) {
        end++;
    }
    if (size != NULL) {
        *size = strtoul(end, &end, 16);
    }
    return v;
}

// The five calls below take an MfciFileEntry handle: mfci_callback_table holds them next to
// mfci_open, mfci_close and mfci_request_read, and nothing else calls them (they were misowned as
// non-static TLobby members). inferred: CRI's mfCiGetNumTr, mfCiSetSctLen, mfCiGetSctLen,
// mfCiGetStat and mfCiStopTr, by their slots in that table.
s32 mfci_get_num_transferred(void *handle) {
    MfciFileEntry *file = static_cast<MfciFileEntry *>(handle);
    if (file == NULL) {
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, "E0092912:handl is null.", 0);
        }
        return 0;
    }
    return file->read_bytes;
}

void mfci_set_sector_length(void *handle, s32 length) {
    MfciFileEntry *file = static_cast<MfciFileEntry *>(handle);
    if (file == NULL) {
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, "E0040302:handl is null.", 0);
        }
    } else {
        s32 old = file->position_sector * file->block_size;
        file->block_size = length;
        file->sector_count = (file->block_size - 1 + file->file_size) / file->block_size;
        file->position_sector = old / file->block_size;
        file->read_bytes = file->read_sectors * length;
    }
}

s32 mfci_get_sector_length(void *handle) {
    MfciFileEntry *file = static_cast<MfciFileEntry *>(handle);
    if (file == NULL) {
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, "E0040301:handl is null.", 0);
        }
        return 0;
    }
    return file->block_size;
}

s32 mfci_get_status(void *handle) {
    MfciFileEntry *file = static_cast<MfciFileEntry *>(handle);
    if (file == NULL) {
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, "E0092912:handl is null.", 0);
        }
        return 0;
    }
    return file->state;
}

void mfci_stop_transfer(void *handle) {
    MfciFileEntry *file = static_cast<MfciFileEntry *>(handle);
    if (file == NULL) {
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, "E0092912:handl is null.", 0);
        }
    } else {
        svm_lock();
        file->state = 0;
        svm_unlock();
    }
}

s32 mfci_request_read(void *handle, s32 sectors, void *buffer) {
    MfciFileEntry *mfci_file_entry = (MfciFileEntry *)handle;
    uaddr data;
    u32 size;
    s32 copied;
    s32 bytes;
    s32 offset;
    if (mfci_file_entry == NULL) {
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, "E01100307:handl is null.", 0);
        }
        return 0;
    }
    if (sectors < 0) {
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, "E01100308:nsct < 0.(mfCiReqRd)", mfci_file_entry);
        }
        return 0;
    }
    if (buffer == NULL) {
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, "E01100309:buf is null.(mfCiReqRd)", mfci_file_entry);
        }
        return 0;
    }
    if (sectors == 0) {
        mfci_file_entry->state = 1;
        return 0;
    }
    svm_lock();
    mfci_file_entry->read_bytes = 0;
    mfci_file_entry->read_sectors = sectors < mfci_file_entry->sector_count - mfci_file_entry->position_sector
        ? sectors : mfci_file_entry->sector_count - mfci_file_entry->position_sector;
    offset = mfci_file_entry->position_sector * mfci_file_entry->block_size;
    bytes = mfci_file_entry->read_sectors * mfci_file_entry->block_size;
    if (bytes == 0) {
        mfci_file_entry->state = 1;
        svm_unlock();
        return 0;
    }
    mfci_file_entry->read_offset = offset;
    mfci_file_entry->request_size = bytes;
    mfci_file_entry->state = 2;
    data = mfci_get_adr_size(mfci_file_entry->name, &size);
    copied = mfci_file_entry->request_size > (s32)(size - mfci_file_entry->read_offset)
        ? (s32)(size - mfci_file_entry->read_offset) : mfci_file_entry->request_size;
    memcpy(buffer, (void *)(data + mfci_file_entry->read_offset), mfci_file_entry->request_size);
    memset((u8 *)buffer + copied, 0, mfci_file_entry->request_size - copied);
    mfci_file_entry->read_bytes = mfci_file_entry->read_sectors * mfci_file_entry->block_size;
    mfci_file_entry->position_sector = mfci_file_entry->position_sector + mfci_file_entry->read_sectors;
    mfci_file_entry->state = 1;
    svm_unlock();
    return mfci_file_entry->read_sectors;
}

s32 mfci_get_position(void *handle) {
    MfciFileEntry *mfci_file_entry = static_cast<MfciFileEntry *>(handle);
    if (mfci_file_entry == NULL) {
        if (mfci_error_callback != NULL) {
            mfci_error_callback(mfci_error_callback_context, "E01100306:handl is null.", 0);
        }
        return 0;
    }
    return mfci_file_entry->position_sector;
}

s32 mfci_seek(void *handle, s32 sectors, s32 origin) {
    MfciFileEntry *mfci_file_entry = static_cast<MfciFileEntry *>(handle);
    if (mfci_file_entry == 0) {
        if (mfci_error_callback != 0) {
            mfci_error_callback(mfci_error_callback_context, "E01100305:handl is null.", 0);
        }
        return 0;
    }
    svm_lock();
    if (origin == 0) {
        mfci_file_entry->position_sector = sectors;
    } else if (origin == 2) {
        mfci_file_entry->position_sector = mfci_file_entry->sector_count + sectors;
    } else if (origin == 1) {
        mfci_file_entry->position_sector += sectors;
    }
    mfci_file_entry->position_sector = mfci_file_entry->position_sector < mfci_file_entry->sector_count ? mfci_file_entry->position_sector : mfci_file_entry->sector_count;
    mfci_file_entry->position_sector = mfci_file_entry->position_sector > 0 ? mfci_file_entry->position_sector : 0;
    svm_unlock();
    return mfci_file_entry->position_sector;
}

void mfci_close(void *handle) {
    MfciFileEntry *mfci_file_entry = static_cast<MfciFileEntry *>(handle);
    if (mfci_file_entry != 0) {
        if (mfci_file_entry == 0) {
            if (mfci_error_callback != 0) {
                mfci_error_callback(mfci_error_callback_context, "E0092912:handl is null.", 0);
            }
        } else {
            svm_lock();
            mfci_file_entry->state = 0;
            svm_unlock();
        }
        if ((s32)mfci_file_entry->used == 1) {
            mfci_file_entry->used = 0;
            memset(mfci_file_entry, 0, sizeof(MfciFileEntry));
        }
    }
}

void *mfci_open(const char *name, s32 entry, s32 mode) {
    MfciFileEntry *f;
    if (name == 0) {
        if (mfci_error_callback != 0) {
            mfci_error_callback(mfci_error_callback_context, "E01100301:fname is null.(mfCiOpen)", 0);
        }
        return 0;
    }
    if (mode != 0) {
        if (mfci_error_callback != 0) {
            mfci_error_callback(mfci_error_callback_context, "E01100302:rw is illigal.(mfCiOpen)", 0);
        }
        return 0;
    }
    f = mfci_find_free_entry();
    if (f == 0) {
        if (mfci_error_callback != 0) {
            mfci_error_callback(mfci_error_callback_context, "E01100303:not enough handle resource.(mfCiOpen)", 0);
        }
        return 0;
    }
    strcpy(f->name, name);
    f->block_size = 0x800;
    {
        u32 lo;
        mfci_get_adr_size(f->name, &lo);
        f->file_size = lo;
    }
    f->sector_count = (f->block_size - 1 + f->file_size) / f->block_size;
    f->position_sector = 0;
    f->read_sectors = 0;
    f->read_bytes = 0;
    f->state = 0;
    f->used = 1;
    return f;
}

s32 mfci_parse_file_size(char *s) {
    u32 lo;
    mfci_get_adr_size(s, &lo);
    return lo;
}

void mfci_set_error_callback(CvFsErrorCallback callback, s32 context) {
    mfci_error_callback = callback;
    mfci_error_callback_context = context;
}

void mfci_exec_server(void) {
    s32 i;
    for (i = 0x28; i != 0; i--) {
    }
}

CvFsDeviceInterface mfci_callback_table = {
    mfci_exec_server,
    mfci_set_error_callback,
    mfci_parse_file_size,
    NULL,
    mfci_open,
    mfci_close,
    mfci_seek,
    mfci_get_position,
    mfci_request_read,
    NULL,
    mfci_stop_transfer,
    mfci_get_status,
    mfci_get_sector_length,
    mfci_set_sector_length,
    mfci_get_num_transferred,
};

CvFsDeviceInterface *mfci_get_interface(void) {
    mfci_version_pointer;
    return &mfci_callback_table;
}
