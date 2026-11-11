// CRI adx_bau.c: the Sun/NeXT .snd (AU) decoder (ADXB_ExecOneAu: mu-law, 8 and 16 bit).
#include "types.h"
#include "pso/unk/TLobby_803C4698.h"
#include "pso/unk/TLobby_803BFE50.h"
#include "pso/unk/TLobby_803C1A58.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/unk/TLobby.h"

struct RecoveredGlobal_803C0AD8_lbl_80570AC0 {
    s32 value;
    u8 remaining[0x9BC];
};

struct Strm_803C1A8C {
    u8 pad0[4];
    s32 state;
    s32 id;
    u8 padC[2];
    s8 channels;
    u8 padF[0x40 - 0xF];
    s32 wrap_len;       // samples; data past it is copied back to the buffer start
    s32 wrap_offset;    // second channel's offset for that copy
    u8 pad48[0x50 - 0x48];
    u8 *src;
    s32 maxLen;
    s32 stream_channels; // 2 = two channel buffers, rOff apart
    s32 sample_bytes;
    s32 block_samples;
    s16 *buf;
    s32 bufLen;
    s32 rOff;
    s32 pos;
    s32 avail;
    s32 x78;
    u8 pad7C[0x88 - 0x7C];
    void (*read)(s32, s32 *, s32 *, s32 *);
    s32 readArg;
    void (*done)(s32, s32, s32);
    s32 doneArg;
    u8 pad98[0xA0 - 0x98];
    s32 n;
    s32 bytes;
};

struct Obj_803C34F4 { u8 pad[0xA8]; s16 state; };

struct Obj_803C3ACC { u8 pad[0xA8]; s16 state; s16 sub; };

struct Hdl_803C43A8 {
    u8 pad0[2];
    s16 f2;
    u8 pad4[8];
    s8 fc;
    s8 fd;
    s8 fe;
    s8 ff;
    s32 f10;
    s32 f14;
    s32 f18;
    s16 f1c;
    u8 pad1e[2];
    s32 f20;
    s16 f24;
    s16 f26;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    u8 pad38[4];
    s32 f3c;
    s32 f40;
    s32 f44;
    s16 f48;
    s16 f4a;
    u8 f4c[0xC];
    s32 f58;
    s32 f5c;
    s32 f60;
    s32 f64;
    s32 f68;
    s32 f6c;
    u8 pad70[0xC];
    s16 f7c;
    s16 f7e;
    u8 *f80;
    u8 pad84[0x14];
    s32 f98;
    s32 f9c;
    u8 padA0[8];
    s16 fa8;
    s16 faa;
};

struct Hdr_803C44C0 {
    u8 pad0[7];
    u8 f7;
    u8 f8;
    u8 f9;
    u8 padA[2];
    s32 fc;
    u8 pad10[0x1A];
    u16 f2a;
};

struct Obj_803C2174 {
    u8 pad_0[2]; s16 f2; u8 pad_4[8]; s8 fc; s8 fd; s8 fe; s8 ff; s32 f10; s32 f14; s32 f18;
    s16 f1c; u8 pad_1e[2]; s32 f20; s16 f24; s16 f26; s32 f28; s32 f2c; s32 f30; s32 f34;
    u8 pad_38[4]; s32 f3c; s32 f40; s32 f44; s16 f48; s16 f4a; u8 f4c[0xC];
    s32 f58; s32 f5c; s32 f60; s32 f64; s32 f68; s32 f6c; u8 pad_70[0xC];
    s16 f7c; s16 f7e; u8 *f80; u8 pad_84[0x98 - 0x84]; s32 f98; s32 f9c; u8 pad_a0[8];
    s16 fa8; s16 faa;
};

struct Rec_803C3E88 {
    s16 used; u8 pad_2[6]; u32 f8; u8 pad_c[0x38 - 0xC];
    s32 f38; s32 f3c; s32 f40; s32 f44; u8 pad_48[0x88 - 0x48];
    void *f88; void *f8c; void *f90; void *f94; u8 pad_98[0xB8 - 0x98];
};

struct Snd_803C1DC4
{
  u8 pad0[4];
  s32 state;
  s32 lobby;
  u8 pad0C[2];
  s8 channels;
  u8 pad0F[0x50 - 0x0F];
  u8 *src;
  s32 max;
  u8 pad58[0x64 - 0x58];
  s16 *dst;
  s32 size;
  s32 rofs;
  s32 pos;
  s32 avail;
  s32 unk78;
  u8 pad7C[0x88 - 0x7C];
  void (*get)(s32, s32 *, s32 *, s32 *);
  s32 getCtx;
  void (*put)(s32, s32, s32);
  s32 putCtx;
  u8 pad98[0xA0 - 0x98];
  s32 count;
  s32 bytes;
};

extern "C" {
s32 memset(void *, int, int);
int memcmp(const void *a, const void *b, unsigned long n);
extern const char lbl_805E0CE0[4];
extern s32 lbl_805E0CC0;
extern s32 lbl_805E0CC8;
extern s32 lbl_805E0CD0;
extern s32 lbl_805E0CD8;
void TLobby__sub_803C19D8(void *);
void TLobby__sub_803C3570(Strm_803C1A8C *o);
void TLobby__sub_803C40D0(void *);
void TLobby__sub_803C34F4(Obj_803C34F4 *arg0);
s32 DVDReadPrio(void *, void *, void *);
s32 TLobby__sub_803C44C0(Hdr_803C44C0 *hdr, s32 arg1, s16 *arg2, s8 *arg3, s8 *arg4, s8 *arg5, s8 *arg6, s32 *arg7, s32 *arg8, s32 *arg9, s16 *arg10);
extern s32 lbl_8047C520[];
extern s32 lbl_8047C540[];
u32 adx_allocate_decoder_channel();
Rec_803C3E88 *alloc_record__6TLobbyFiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void process_byteswapped_pcm_transfer(Snd_803C1DC4 *arg0);
void TLobby__sub_803C2A00(Strm_803C1A8C *o);
/* mu-law sample expansion table (8-bit code -> s16 PCM) */
s16 stream_chunk_decode_table[256] = {
    -32124, -31100, -30076, -29052, -28028, -27004, -25980, -24956, -23932, -22908, -21884, -20860, -19836, -18812,
    -17788, -16764, -15996, -15484, -14972, -14460, -13948, -13436, -12924, -12412, -11900, -11388, -10876, -10364,
    -9852, -9340, -8828, -8316, -7932, -7676, -7420, -7164, -6908, -6652, -6396, -6140, -5884, -5628, -5372, -5116,
    -4860, -4604, -4348, -4092, -3900, -3772, -3644, -3516, -3388, -3260, -3132, -3004, -2876, -2748, -2620, -2492,
    -2364, -2236, -2108, -1980, -1884, -1820, -1756, -1692, -1628, -1564, -1500, -1436, -1372, -1308, -1244, -1180,
    -1116, -1052, -988, -924, -876, -844, -812, -780, -748, -716, -684, -652, -620, -588, -556, -524, -492, -460,
    -428, -396, -372, -356, -340, -324, -308, -292, -276, -260, -244, -228, -212, -196, -180, -164, -148, -132,
    -120, -112, -104, -96, -88, -80, -72, -64, -56, -48, -40, -32, -24, -16, -8, 0, 32124, 31100, 30076, 29052,
    28028, 27004, 25980, 24956, 23932, 22908, 21884, 20860, 19836, 18812, 17788, 16764, 15996, 15484, 14972, 14460,
    13948, 13436, 12924, 12412, 11900, 11388, 10876, 10364, 9852, 9340, 8828, 8316, 7932, 7676, 7420, 7164, 6908,
    6652, 6396, 6140, 5884, 5628, 5372, 5116, 4860, 4604, 4348, 4092, 3900, 3772, 3644, 3516, 3388, 3260, 3132,
    3004, 2876, 2748, 2620, 2492, 2364, 2236, 2108, 1980, 1884, 1820, 1756, 1692, 1628, 1564, 1500, 1436, 1372,
    1308, 1244, 1180, 1116, 1052, 988, 924, 876, 844, 812, 780, 748, 716, 684, 652, 620, 588, 556, 524, 492, 460,
    428, 396, 372, 356, 340, 324, 308, 292, 276, 260, 244, 228, 212, 196, 180, 164, 148, 132, 120, 112, 104, 96,
    88, 80, 72, 64, 56, 48, 40, 32, 24, 16, 8, 0
};

// Little-endian reads of big-endian header fields, swapped in place afterwards.
#define READ_LE32(b) ((b)[0] | ((b)[1] << 8) | ((b)[2] << 16) | ((b)[3] << 24))
#define SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))

void TLobby::dispatch_by_state() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;

    temp_r0 = *(s16 *)((s8 *)arg0 + 0xAA);
    if (temp_r0 == 2) {
        decode_stream_chunk();
        return;
    }
    if (temp_r0 == 1) {
        TLobby__sub_803C2A00((Strm_803C1A8C *)arg0);
        return;
    }
    process_byteswapped_pcm_transfer((Snd_803C1DC4 *)(arg0));
}

void TLobby::decode_stream_chunk() {
    Strm_803C1A8C *o = (Strm_803C1A8C *)this;
    u8 *src = o->src;

    if (o->state == 1 && ((TLobby *)(o->id))->get_client_count() == 0) {
        s16 *dst;
        s16 *dst2;
        s32 i;
        s32 n;
        o->read(o->readArg, &o->pos, &o->avail, &o->x78);
        n = o->bufLen - o->pos;
        if (n > o->avail) {
            n = o->avail;
        }
        if (n > o->maxLen) {
            n = o->maxLen;
        }
        dst = o->buf + o->pos;
        if (o->channels == 2) {
            dst2 = o->buf + (o->rOff + o->pos);
            for (i = 0; i < n; i++) {
                dst[i] = stream_chunk_decode_table[src[i * 2]];
                dst2[i] = stream_chunk_decode_table[src[i * 2 + 1]];
            }
        } else {
            for (i = 0; i < n; i++) {
                dst[i] = stream_chunk_decode_table[src[i]];
            }
        }
        o->n = n;
        o->bytes = n * o->channels;
        o->state = 2;
    }
    if (o->state == 2) {
        o->done(o->doneArg, o->bytes, o->n);
        o->state = 3;
    }
}

void TLobby__sub_803C2A00(Strm_803C1A8C *o) {
    u8 *src = o->src;
    if (o->state == 1 && ((TLobby *)(o->id))->get_client_count() == 0) {
        s16 *l;
        s16 *r;
        s32 i;
        s32 n;
        o->read(o->readArg, &o->pos, &o->avail, &o->x78);
        n = o->bufLen - o->pos;
        if (n > o->avail) {
            n = o->avail;
        }
        if (n > o->maxLen) {
            n = o->maxLen;
        }
        l = o->buf + o->pos;
        if (o->channels == 2) {
            r = o->buf + (o->rOff + o->pos);
            for (i = 0; i < n; i++) {
                l[i] = (src[i * 2] << 8) & 0xFF00;
                r[i] = (src[i * 2 + 1] << 8) & 0xFF00;
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = (src[i] << 8) & 0xFF00;
            }
        }
        o->n = n;
        o->bytes = n * o->channels;
        o->state = 2;
    }
    if (o->state == 2) {
        o->done(o->doneArg, o->bytes, o->n);
        o->state = 3;
    }
}

void process_byteswapped_pcm_transfer(Snd_803C1DC4 *arg0) {
  u16 *src = (u16 *) arg0->src;
  u16 *l;
  s32 new_var;
  u16 *r;
  s32 i;
  s32 n;
  if ((arg0->state == 1) && (((TLobby *)(arg0->lobby))->get_client_count() == 0))
  {
    arg0->get(arg0->getCtx, &arg0->pos, &arg0->avail, &arg0->unk78);
    new_var = arg0->size;
    n = new_var - arg0->pos;
    if (n > arg0->avail)
    {
      n = arg0->avail;
    }
    if (n > arg0->max)
    {
      n = arg0->max;
    }
    l = ((u16 *) arg0->dst) + arg0->pos;
    if (arg0->channels == 2)
    {
      r = ((u16 *) arg0->dst) + (arg0->rofs + arg0->pos);
      for (i = 0; i < n; i++)
      {
        new_var = src[i * 2];
        l[i] = (src[i * 2] >> 8) | (new_var << 8);
        r[i] = (src[(i * 2) + 1] >> 8) | (src[(i * 2) + 1] << 8);
      }
    }
    else
    {
      for (i = 0; i < n; i++)
      {
        l[i] = (src[i] >> 8) | (src[i] << 8);
      }
    }
    arg0->count = n;
    arg0->bytes = arg0->channels * (n * 2);
    arg0->state = 2;
  }
  if (arg0->state == 2)
  {
    arg0->put(arg0->putCtx, arg0->bytes, arg0->count);
    arg0->state = 3;
  }
}

s32 TLobby__sub_803C30E8(u8 *arg0, s32 arg1, s32 arg2) {
    s32 sp18;
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    s16 var_r31;
    s32 var_r5;
    u32 temp_r3;
    u8 *temp_r3_2;
    *(s16 *)((s8 *)arg0 + 2) = 1;
    if (arg2 < 8) {
        var_r31 = 0;
        var_r5 = -1;
    } else {
        temp_r3 = (u32)fn_803C32EC((u8 *)arg1, arg2, &sp8, &spC, &sp10, &sp14, &sp18);
        if (temp_r3 == 0U) {
            var_r5 = -1;
        } else {
            var_r31 = (s16)(temp_r3 - arg1);
            if (var_r31 <= 0) {
                var_r5 = -1;
            } else {
                var_r5 = 0;
                *(s32 *)((s8 *)arg0 + 0x14) = sp8;
                *(u8 *)((s8 *)arg0 + 0xE) = (u8) spC;
                *(u8 *)((s8 *)arg0 + 0xD) = (u8) sp10;
                *(s32 *)((s8 *)arg0 + 0x18) = sp14;
                *(s8 *)((s8 *)arg0 + 0xC) = -1;
                *(u8 *)((s8 *)arg0 + 0xF) = (u8) ((s32) (*(s8 *)((s8 *)arg0 + 0xE) * *(s8 *)((s8 *)arg0 + 0xD)) / 8);
                *(s32 *)((s8 *)arg0 + 0x10) = 1;
            }
        }
    }
    if (var_r5 < 0) {
        return 0;
    }
    temp_r3_2 = (arg0 + 0x4C);
    *(s16 *)((s8 *)arg0 + 0x1C) = 0;
    *(s16 *)((s8 *)arg0 + 0x4A) = 0;
    *(s16 *)((s8 *)arg0 + 0x48) = 0;
    *(s16 *)((s8 *)arg0 + 0x26) = 0;
    *(s16 *)((s8 *)arg0 + 0x24) = 0;
    *(s32 *)((s8 *)arg0 + 0x34) = 0;
    *(s32 *)((s8 *)arg0 + 0x30) = 0;
    *(s32 *)((s8 *)arg0 + 0x2C) = 0;
    *(s32 *)((s8 *)arg0 + 0x28) = 0;
    *(s32 *)((s8 *)arg0 + 0x20) = 0;
    *(s32 *)((s8 *)arg0 + 0x58) = (s32) (s8) *(u8 *)((s8 *)arg0 + 0xE);
    *(s32 *)((s8 *)arg0 + 0x5C) = (s32) (s8) *(u8 *)((s8 *)arg0 + 0xF);
    *(s32 *)((s8 *)arg0 + 0x60) = (s32) *(s32 *)((s8 *)arg0 + 0x10);
    *(s32 *)((s8 *)arg0 + 0x64) = (s32) *(s32 *)((s8 *)arg0 + 0x3C);
    *(s32 *)((s8 *)arg0 + 0x68) = (s32) *(s32 *)((s8 *)arg0 + 0x40);
    *(s32 *)((s8 *)arg0 + 0x6C) = (s32) *(s32 *)((s8 *)arg0 + 0x44);
    *(s16 *)((s8 *)arg0 + 0x7C) = (s16) *(s16 *)((s8 *)arg0 + 0x48);
    *(s16 *)((s8 *)arg0 + 0x7E) = (*(s16 *)((s8 *)arg0 + 0x4A));
    *(u8 **)((s8 *)arg0 + 0x80) = temp_r3_2;
    *(s32 *)((s8 *)arg0 + 0x9C) = 0;
    *(s32 *)((s8 *)arg0 + 0x98) = 0;
    *(s16 *)((s8 *)arg0 + 0xA8) = 4;
    *(s16 *)((s8 *)arg0 + 0xAA) = (s16) sp18;
    memset(temp_r3_2, 0, 4);
    return var_r31;
}

s32 TLobby::is_snd_header() {
    u8 *arg0 = (u8 *)this;
    if (((s32)memcmp((const void *)(arg0), (const void *)(&lbl_805E0CD0), (unsigned long)(4))) == 0 || ((s32)memcmp((const void *)(arg0), (const void *)(&lbl_805E0CD8), (unsigned long)(4))) == 0) {
        return 1;
    }
    return 0;
}

// Reads a Sun/NeXT ".snd" (AU) header, whose fields are big-endian; returns the start of
// the sample data, or NULL when the magic, data offset or encoding is not supported.
// (inferred name: parse_snd_header)
u8 *fn_803C32EC(u8 *hdr, s32 size, s32 *rate, s32 *channels, s32 *bits, s32 *samples, s32 *format) {
    u32 magic;
    u32 offset;
    u32 data_size;
    u32 encoding;

    magic = READ_LE32(hdr);
    if (magic != 0x0064732E && magic != 0x646E732E) {
        return NULL;
    }
    offset = READ_LE32(hdr + 4);
    offset = SWAP32(offset);
    if ((s32)offset > size) {
        return NULL;
    }
    data_size = READ_LE32(hdr + 8);
    data_size = SWAP32(data_size);
    encoding = READ_LE32(hdr + 12);
    encoding = SWAP32(encoding);
    switch (encoding) {
    case 1:
        *format = 2;
        *bits = 8;
        break;
    case 2:
        *format = 1;
        *bits = 8;
        break;
    case 3:
        *format = 0;
        *bits = 16;
        break;
    default:
        return NULL;
    }
    *rate = READ_LE32(hdr + 16);
    *rate = SWAP32(*rate);
    *channels = READ_LE32(hdr + 20);
    *channels = SWAP32(*channels);
    if (*format == 2) {
        *samples = (s32)data_size / *channels;
    } else if (*format == 1) {
        *samples = (s32)data_size / *channels;
    } else if (*format == 0) {
        *samples = (s32)data_size / 2 / *channels;
    } else {
        *samples = 0x7FFF0000;
    }
    return hdr + offset;
}

}
