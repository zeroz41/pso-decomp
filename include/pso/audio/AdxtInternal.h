#ifndef PSO_AUDIO_ADXT_INTERNAL_H
#define PSO_AUDIO_ADXT_INTERNAL_H

#include <stddef.h>
#include "types.h"
#include "pso/audio/AdxAmp.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

struct AdxStreamFile;
struct GcrnaStream;

struct AdxtMemTableEntry {
    s32 offset;
    s32 length;
};

struct AdxtNotifyVtable {
    void *pad_00[3];
    void (*destroy)(void *);
    void *pad_10;
    void (*reset)(void *);
};

struct AdxtNotifyObj {
    AdxtNotifyVtable *vt;
};

struct AdxtPlayer {
    s8 used;                       /* 0x00 */
    s8 stat;                       /* 0x01 */
    u8 source_type;                /* 0x02 */
    s8 max_channels;               /* 0x03 */
    saddr decoder_handle;          /* 0x04 */
    AdxStreamFile *stream_file;    /* 0x08 */
    saddr rna_handle;              /* 0x0C */
    SjRingBuffer *input_ring;      /* 0x10 */
    AdxtNotifyObj *notify_obj;     /* 0x14 */
    SjRingBuffer *output_rings[2]; /* 0x18 */
    saddr input_buf_addr;          /* 0x20 */
    s32 input_buf_size;            /* 0x24 */
    s32 input_extra_size;          /* 0x28 */
    saddr output_buf_addr;         /* 0x2C */
    s32 output_buf_size;           /* 0x30 */
    s32 output_stride;             /* 0x34 */
    s32 server_freq;               /* 0x38 */
    s16 total_sectors;             /* 0x3C */
    s16 start_sectors;             /* 0x3E */
    s16 output_vol;                /* 0x40 */
    s16 out_pan[2];                /* 0x42 */
    u8 pad_46[2];                  /* 0x46 */
    s32 reserved_48;               /* 0x48 */
    s32 reserved_4C;               /* 0x4C */
    s32 reserved_50;               /* 0x50 */
    s32 reserved_54;               /* 0x54 */
    s32 reserved_58;               /* 0x58 */
    s32 reserved_5C;               /* 0x5C */
    s16 error_code;                /* 0x60 */
    u8 pad_62[2];                  /* 0x62 */
    s32 reserved_64;               /* 0x64 */
    s16 reserved_68;               /* 0x68 */
    s16 reserved_6A;               /* 0x6A */
    s8 reload_flag;                /* 0x6C */
    s8 auto_repeat;                /* 0x6D */
    u8 pad_6E[2];                  /* 0x6E */
    s8 auto_start_flag;            /* 0x70 */
    u8 started_playback;           /* 0x71 */
    s8 pause_flag;                 /* 0x72 */
    u8 pad_73;                     /* 0x73 */
    AdxAmp *amp;                   /* 0x74 */
    AdxtNotifyObj *extra_objs[2];  /* 0x78 */
    AdxtNotifyObj *extra_objs2[2]; /* 0x80 */
    s32 time_offset;               /* 0x88 */
    s32 total_pages;               /* 0x8C */
    s32 loop_end_sample;           /* 0x90 */
    LscStream *lsc_stream;         /* 0x94 */
    s8 sync_mode_flag;             /* 0x98 */
    u8 pad_99[3];                  /* 0x99 */
    s32 base_time;                 /* 0x9C */
    s32 base_vblank;               /* 0xA0 */
    s32 played_samples;            /* 0xA4 */
};

LAYOUT_ASSERT(AdxtPlayer_size, sizeof(AdxtPlayer) == 0xA8);
LAYOUT_ASSERT(AdxtPlayer_out_pan_offset, offsetof(AdxtPlayer, out_pan) == 0x42);
LAYOUT_ASSERT(AdxtPlayer_error_code_offset, offsetof(AdxtPlayer, error_code) == 0x60);
LAYOUT_ASSERT(AdxtPlayer_amp_offset, offsetof(AdxtPlayer, amp) == 0x74);
LAYOUT_ASSERT(AdxtPlayer_played_samples_offset, offsetof(AdxtPlayer, played_samples) == 0xA4);

typedef void (*AdxtStopHook)(void);

extern "C" {
void configure_audio_stream_output(AdxtPlayer *player);
void start_audio_stream_file(AdxtPlayer *player, const char *name);
}

#endif
