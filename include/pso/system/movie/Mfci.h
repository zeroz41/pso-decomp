#ifndef PSO_SYSTEM_MOVIE_MFCI_H
#define PSO_SYSTEM_MOVIE_MFCI_H
#include "types.h"
#include "pso/system/CvFsStreamHandle.h"

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
LAYOUT_ASSERT(MfciFileEntrySize, sizeof(MfciFileEntry) == 0x38);
LAYOUT_ASSERT(MfciFilePoolSize, sizeof(MfciFilePool) == 0x8C4);
#include <stddef.h>
LAYOUT_ASSERT(MfciFileNameOffset, offsetof(MfciFileEntry, name) == 0x1C);
LAYOUT_ASSERT(MfciReadOffset, offsetof(MfciFileEntry, read_offset) == 0x30);
LAYOUT_ASSERT(MfciRequestSizeOffset, offsetof(MfciFileEntry, request_size) == 0x34);

s32 mfci_get_num_transferred(void *handle); // inferred: mfCiGetNumTr
void mfci_set_sector_length(void *handle, s32 length); // inferred: mfCiSetSctLen
s32 mfci_get_sector_length(void *handle); // inferred: mfCiGetSctLen
s32 mfci_get_status(void *handle); // inferred: mfCiGetStat
void mfci_stop_transfer(void *handle); // inferred: mfCiStopTr
s32 mfci_request_read(void *handle, s32 sectors, void *buffer);
s32 mfci_get_position(void *handle);
s32 mfci_seek(void *handle, s32 sectors, s32 origin);
void mfci_close(void *handle);
void *mfci_open(const char* name, s32 entry, s32 mode);
s32 mfci_parse_file_size(char *name);
void mfci_set_error_callback(CvFsErrorCallback callback, s32 context);
void mfci_exec_server(void); // inferred: mfCiExecServer

extern CvFsDeviceInterface mfci_callback_table;
CvFsDeviceInterface *mfci_get_interface();

#endif
