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

s32 mfci_get_position(MfciFileEntry* file);
s32 mfci_seek(MfciFileEntry* file, s32 sectors, s32 origin);
void mfci_close(MfciFileEntry* file);
MfciFileEntry* mfci_open(const char* name, s32 entry, s32 mode);
u32 mfci_parse_file_size(char* name);
void mfci_set_error_callback(s32 arg0, s32 arg1);

extern "C" {
s32 mfci_request_read(void *handle, s32 sectors, void *buffer);
void TLobby__sub_803D43A8(void);
char *TLobby__sub_803D43B8(void);
}

#endif
