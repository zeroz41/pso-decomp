#include <dolphin/os/OSThread.h>
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/unk/text_803D31A4.h"

struct AdxStreamFile {
    s8 used;
    s8 b1;
    s8 b2;
    u8 pad3;
    s32 arg;
    u32 handle;
    s32 fC;
    s32 f10;
    s32 size;
    u8 pad18[0x14];
    s32 f2C;
    s32 sectors;
    u8 pad34[0xC];
};

extern "C" {
AdxStreamFile *TLobby__sub_803C8BAC(const char *name, s32 arg);

}

struct VT_803C9FCC { u8 pad[0x14]; void (*update)(void *self); };

struct Part_803C9FCC { VT_803C9FCC *vt; };

struct Stream_803C9FCC {
    u8 f0;
    u8 active;
    u8 f2;
    s8 count;
    void *f4;
    void *f8;
    u8 padc[0x10 - 0xC];
    s32 f10;
    s32 f14;
    Part_803C9FCC *parts[9];
    s16 f3c;
    s16 f3e;
    u8 pad40[0x4C - 0x40];
    s32 f4c;
    u8 pad50[0x71 - 0x50];
    u8 f71;
    u8 pad72[0x8C - 0x72];
    s32 f8c;
    s32 f90;
    u8 pad94[0x9C - 0x94];
    s32 f9c;
    s32 fa0;
    s32 fa4;
};

struct Stream_803CA824 {
    u8 f0;
    u8 state;
    u8 pad2[0x8 - 0x2];
    void *handle;
    u8 padc[0x10 - 0xC];
    s32 f10;
    u8 pad14[0x60 - 0x14];
    s16 f60;
    u8 pad62[0x98 - 0x62];
    u8 f98;
};

typedef struct Ent_803CA774 {
    s32 off;
    s32 len;
} Ent_803CA774;

extern "C" {
void configure_audio_stream_output(Stream_803C9FCC *self);
void start_audio_stream_file(Stream_803CA824 *self, const char *name);
struct SjMemoryBuffer;
SjMemoryBuffer *sj_memory_buffer_create(void *arg0, s32 arg1);

}
void stop_audio_stream(u8 *arg0);
extern "C" {

struct Stream_803C9FCC;

void TLobby::adxt_start_mem_idx(u8 *arg1, s32 arg2) {
    s32 r;
    stop_audio_stream(((u8 *)this));
    if (arg2 >= ((Ent_803CA774 *)arg1)[0].len || arg2 < 0) {
        return;
    }
    TLobby::init_once();
    r = (s32)sj_memory_buffer_create(arg1 + *(s32 *)(arg1 + (arg2 + 1) * 8), 0x40000000);
    if (r == 0) {
        TLobby::release_ref();
        TLobby::notify_error("E8101207: can't create sj (ADXT_StartMemIdx)");
        return;
    }
    start_stream_playback(r);
    ((u8 *)this)[2] = 2;
    ((u8 *)this)[0x98] = 0;
    TLobby::release_ref();
}

void start_audio_stream_file(Stream_803CA824 *self, const char *name) {
    stop_audio_stream((u8 *)self);
    TLobby::init_once();
    if ((self->handle = TLobby__sub_803C8BAC(name, self->f10)) == 0) {
        TLobby::release_ref();
        TLobby::report_adx_error("E8101205 ADXT_StartFname: can't open ", name);
        self->f60 = -1;
        self->state = 6;
    } else {
        configure_audio_stream_output((Stream_803C9FCC *)self);
        self->f98 = 0;
        TLobby::release_ref();
    }
}

}
