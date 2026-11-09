#include "types.h"
#include "pso/unk/text_803C1780.h"
#include "pso/unk/TLobby.h"

typedef void (*RecoveredCallback_1268626c296b)(void *);
struct Obj_803C1A24 { u8 pad[0xAC]; void *fac; };

extern RecoveredCallback_1268626c296b lbl_805D7514;
extern s32 (*lbl_805D7510)();

void TLobby__sub_803C19D8(void) {
    lbl_805D7510();
}
void TLobby__sub_803C1A00(u8 *arg0, s32 arg1) {
    *(s32 *)((s8 *)arg0 + 0xB0) = arg1;
    *(u32 *)((s8 *)arg0 + 0xB4) = (u32) (arg1 / 96);
}
void TLobby::invoke_notify_callback() {
    Obj_803C1A24 *arg0 = (Obj_803C1A24 *)this;
    if (arg0->fac != 0) {
        lbl_805D7514(arg0->fac);
    }
}

#include <string.h>

// Little-endian RIFF/WAVE fields read on the big-endian GameCube.
#define LE16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00))
#define LE32(x) (((x) >> 24) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))

// "fmt " chunk of a WAVE file.
struct WavFmtChunk {
    char id[4];
    u32 size;
    u16 format;
    u16 channels;
    u32 sample_rate;
    u32 byte_rate;
    u16 block_align;
    u16 bits;
};

extern char *lbl_805D4650; // "fmt "
extern char *lbl_805D4654; // "data"

s32 TLobby__sub_803C1780(s32 buf, s32 len, s16 *data_offset, s8 *marker, s8 *bits, s8 *block_align, s8 *channels,
                         s32 *sample_rate, s32 *sample_count, s32 *samples_per_block, s16 *encoding) {
    WavFmtChunk *fmt;
    u32 size;
    s32 i;

    for (i = 0; i < len; i++) {
        if (memcmp((void *)(buf + i), lbl_805D4650, 4) == 0) {
            break;
        }
    }
    if (i == len) {
        return -1;
    }
    if (i % 4 != 0) {
        return -1;
    }
    fmt = (WavFmtChunk *)(i + buf);
    if ((s16)LE16(fmt->format) > 1) {
        return -1;
    }
    for (i = 0; i < len; i++) {
        if (memcmp((void *)(buf + i), lbl_805D4654, 4) == 0) {
            break;
        }
    }
    if (i == len) {
        return -1;
    }
    size = LE32(*(u32 *)(i + 4 + buf)); // "data" chunk size
    *data_offset = i + 8;
    *marker = -1;
    *sample_rate = LE32(fmt->sample_rate);
    *channels = LE16(fmt->channels);
    *bits = LE16(fmt->bits);
    *block_align = LE16(fmt->block_align);
    *sample_count = (s32)size / *block_align;
    *samples_per_block = 1;
    if (*bits == 16) {
        *encoding = 0;
    } else if (*bits == 8) {
        *encoding = 1;
    } else if (*bits == 4) {
        *block_align = *channels * 2;
        *samples_per_block = 4;
        *sample_count = (s32)size / 2 / *channels;
        *bits = 16;
        *encoding = 2;
    }
    if (*bits == 0) {
        return -1;
    }
    if (*block_align == 0) {
        return -1;
    }
    if (*channels <= 0 || *channels > 2) {
        return -1;
    }
    return *sample_rate == 0 ? -1 : 0;
}
