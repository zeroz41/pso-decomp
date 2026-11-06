#ifndef PSO_SYSTEM_TGSTREAM_H
#define PSO_SYSTEM_TGSTREAM_H

#include "pso/system/GslArchive.h"
#include <stddef.h>

// A disc or GSL-archive file opened for streaming reads. Stack objects: the
// ctor opens the file (from the loaded GSL archive when the name is found there),
// the dtor closes it.
class TGStream {
public:
    TGStream(void *name, s32 direct_read_mode);
    ~TGStream();

    static s32 load_file(s32 name);
    static s32 read_whole_file(s32 name, u8 *dst);
    static s32 load_sct_file(s32 name, s32 dst);
    void read_sectors_sync(s32 sector_count, s32 destination);
    static void reset();
    s32 get_file_size();
    void align_read_offset(s32 alignment);
    s32 read_data(s32 destination, s32 byte_count);

    char name[0x20];
    s32 adxf_handle;
    s32 direct_read_mode;
    GslArchiveEntry *archive_entry;
};
typedef char TGStreamExtent[sizeof(TGStream) == 0x2C ? 1 : -1];
typedef char TGStreamHandleOffset[offsetof(TGStream, adxf_handle) == 0x20 ? 1 : -1];
typedef char TGStreamReadModeOffset[offsetof(TGStream, direct_read_mode) == 0x24 ? 1 : -1];
typedef char TGStreamEntryOffset[offsetof(TGStream, archive_entry) == 0x28 ? 1 : -1];

extern "C" {
void reset_gstream_buffer(void);
void TGStream__sub_800FDD64(void);
void load_area_gsl(void);
void TItemDrop__sub_800FE2D8(void);
}
s32 get_gstream_buffered_bytes(void);
s32 refill_gstream_buffer(s32 adxf_handle);
void reset_gstream_globals(void);
extern u8 gstream_sector_buffer[0x2000];

#endif
