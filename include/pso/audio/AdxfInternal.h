#ifndef PSO_AUDIO_ADXFINTERNAL_H
#define PSO_AUDIO_ADXFINTERNAL_H

#include "pso/audio/Adxf.h"
#include <stddef.h>

struct AdxStreamFile;
struct SjRingBuffer;

struct AdxfHandle {
    s8 used;
    s8 state;
    s8 external_buffer; // non-zero: the read buffer is the caller's, stop and the server keep it
    u8 f3;
    AdxStreamFile *stream;
    SjRingBuffer *buffer;
    s32 sector_count;
    s32 byte_size;
    s32 sector_position;
    s32 read_start_sector;
    s32 read_sector_count;
    s32 sectors_read;
    void *read_destination;
    s32 read_buffer_size;
    s32 requested_read_sectors;
    s32 archive_start_sector;
    u8 pad_34[0x138 - 0x34];
};

LAYOUT_ASSERT(AdxfHandleSize, sizeof(AdxfHandle) == 0x138);
LAYOUT_ASSERT(AdxfHandleByteSizeOffset, offsetof(AdxfHandle, byte_size) == 0x10);
LAYOUT_ASSERT(AdxfHandleReadDestinationOffset, offsetof(AdxfHandle, read_destination) == 0x24);

// The command journal stores raw sector/partition numbers or the native pointer
// for the recorded command, with one entry for each phase.
struct AdxfLogEntry {
    s8 type;
    s8 phase;
    u16 seq;
    union {
        s32 a;
        const void *name;
        AdxfHandle *handle;
    };
    s32 b;
    union {
        s32 c;
        void *destination;
    };

    void set_last_argument(s32 value) { c = value; }
    void set_last_argument(void *value) { destination = value; }
};

struct AdxfLogHeader {
    u16 reserved;
    u16 open_sequence;
    u16 afs_open_sequence;
    u16 close_sequence;
    u16 read_sequence;
    u16 stop_sequence;
    u16 seek_sequence;
    u8 remaining[0x12];
};

LAYOUT_ASSERT(AdxfLogEntrySize, sizeof(AdxfLogEntry) == 0x10);
LAYOUT_ASSERT(AdxfLogHandleOffset, offsetof(AdxfLogEntry, handle) == 0x4);
LAYOUT_ASSERT(AdxfLogDestinationOffset, offsetof(AdxfLogEntry, destination) == 0xC);
LAYOUT_ASSERT(AdxfLogHeaderSize, sizeof(AdxfLogHeader) == 0x20);
LAYOUT_ASSERT(AdxfLogSeekSequenceOffset, offsetof(AdxfLogHeader, seek_sequence) == 0xC);

extern "C" {
extern AdxfLogHeader adxf_log_header;
extern AdxfLogEntry adxf_log_entries[256];
extern AdxfHandle adxf_file_handle_pool[16];
extern AdxfHandle *lobby_adxf_open_file_handle;
}

// one table of contents per loaded AFS partition, indexed by partition id
extern AdxfPartitionInfo *afs_archive_toc_table[256];
extern s32 lobby_adxf_current_file_id;
extern s32 lobby_afs_toc_entry_index;
extern s32 adxf_log_write_index;
extern s32 adxf_invalidate_cache_flag;

#endif
