#ifndef PSO_SYSTEM_RLC_ARCHIVE_H
#define PSO_SYSTEM_RLC_ARCHIVE_H

#include "types.h"

// RLC stores header and directory words in big-endian byte order.
struct RlcDirectoryEntry {
    s8 offset_be[4];
    s8 size_be[4];

    u32 get_size();
    u32 get_offset();
    u32 read_be32(const s8 *bytes);
};

struct RlcHeader {
    u8 m_00[0x10];
    s8 chunk_count_be[4];
    s8 directory_offset_be[4];
    u8 m_18[8];

    u32 get_directory_offset();
    u32 get_chunk_count();
    u32 read_be32(const s8 *bytes);
};

LAYOUT_ASSERT(RlcDirectoryEntry_size, sizeof(RlcDirectoryEntry) == 8);
LAYOUT_ASSERT(RlcHeader_size, sizeof(RlcHeader) == 0x20);

// An RLC archive read whole from a disc file (name inferred from its RlcHeader/RlcDirectoryEntry reads and
// TGStream::read_whole_file); TWindowSnapShot keeps one in shared_snapshot_capture. Its vtable
// (0x804DD098) holds only the destructor. CW places the vptr after the members
// declared before the first virtual, here at 0x3C.
class RlcArchive {
public:
    RlcHeader *header;            // 0x00 the archive header, at the start of buffer
    RlcDirectoryEntry *directory; // 0x04 buffer + the header's directory offset
    u8 *buffer;                   // 0x08 mem_alloc'd file image
    s32 file_size;                // 0x0C
    u8 pad_10[0x4];
    s32 loaded;                   // 0x14 set once start_capture has read the file
    s32 error;                    // 0x18 set_mode: 1 no size, 2 read failed, 3 no file, 4 no memory, 7 no header
    char name[0x20];              // 0x1C the file name, cut to 31 characters

    RlcArchive();
    virtual ~RlcArchive();
    s32 get_chunk_count();
    void set_directory_pointer();
    void set_header_pointer();
    void store_capture_filename(saddr file);
    void free_buffer();
    s32 alloc_buffer();
    s32 open_stream(saddr file);
    s32 init(saddr file);
    void reset();
    void update_both();
    s32 start_capture(saddr file);
    void set_mode(s32 v);
    s32 get_buffer_size();
    s32 has_resource_size();
    saddr get_size();
    saddr get_field_8();
};

LAYOUT_ASSERT(RlcArchive_size, sizeof(RlcArchive) == 0x40);

extern RlcArchive *shared_snapshot_capture;

#endif
