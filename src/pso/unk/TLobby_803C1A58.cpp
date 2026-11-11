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
Rec_803C3E88 adx_channel_record_pool[16];
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

void TLobby::dispatch_network_state() {
    u8 *arg0 = (u8 *)this;
    if ((s16) *(s16 *)((s8 *)arg0 + 0xAA) == 1) {
        decode_pcm8_stream();
        return;
    }
    copy_byteswapped_pcm_samples();
}

void TLobby::decode_pcm8_stream() {
    Strm_803C1A8C *o = (Strm_803C1A8C *)this;
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

#define o ((Obj_803C2174 *)arg0)
#define p ((u8 *)arg1)

typedef struct Snd_803C1DC4 Snd_803C1DC4;
void TLobby::copy_byteswapped_pcm_samples() {
    Snd_803C1DC4 *arg0 = (Snd_803C1DC4 *)this;
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

s32 TLobby::parse_stream_header(void *arg1, void *arg2) {
    void *arg0 = (void *)this;
    s32 d;
    s32 c;
    s32 b;
    s32 a;
    s16 len;
    s32 st;
    u8 *e;
    o->f2 = 1;
    if ((s32)arg2 < 0x1000) {
        len = 0;
        st = -1;
    } else if ((e = TLobby__sub_803C2388(p, &a, &b, &c, &d)) == NULL) {
        st = -1;
    } else if ((len = e - p) <= 0) {
        st = -1;
    } else {
        o->f14 = a;
        o->fe = b;
        o->fd = c;
        o->f18 = d;
        o->fc = -1;
        o->ff = (o->fe * o->fd) / 8;
        o->f10 = 1;
        st = 0;
    }
    if (st < 0) {
        return 0;
    }
    o->f1c = 0;
    o->f4a = 0;
    o->f48 = 0;
    o->f26 = 0;
    o->f24 = 0;
    o->f34 = 0;
    o->f30 = 0;
    o->f2c = 0;
    o->f28 = 0;
    o->f20 = 0;
    o->f58 = o->fe;
    o->f5c = o->ff;
    o->f60 = o->f10;
    o->f64 = o->f3c;
    o->f68 = o->f40;
    o->f6c = o->f44;
    o->f7c = o->f48;
    o->f7e = o->f4a;
    o->f80 = o->f4c;
    o->f9c = 0;
    o->f98 = 0;
    o->fa8 = 3;
    if (o->fd == 8) {
        o->faa = 1;
    } else {
        o->faa = 0;
    }
    memset((u8 *)arg0 + 0x4C, 0, 4);
    return len;
}
#undef o
#undef p

s32 TLobby::is_aiff_header() {
    u8 *arg0 = (u8 *)this;
    if (((s32)memcmp((const void *)(arg0), (const void *)(&lbl_805E0CC0), (unsigned long)(4))) == 0 && ((s32)memcmp((const void *)(arg0 + 8), (const void *)(&lbl_805E0CC8), (unsigned long)(4))) == 0) {
        return 1;
    }
    return 0;
}

// Little-endian reads of big-endian header fields, swapped in place afterwards.
#define READ_LE32(b) ((b)[0] | ((b)[1] << 8) | ((b)[2] << 16) | ((b)[3] << 24))
#define SWAP32(x) ((((x) >> 24) & 0xFF) | (((x) >> 8) & 0xFF00) | (((x) << 8) & 0xFF0000) | ((x) << 24))
#define READ_LE16(b) ((u16)(b)[0] | ((u16)(b)[1] << 8))
#define SWAP16(x) ((((x) >> 8) & 0xFF) | (((x) << 8) & 0xFF00))

// Walks the chunks of an AIFF ("FORM"/"AIFF") header, whose fields are big-endian: COMM gives
// the format, SSND the start of the sample data, which is returned (NULL if not an AIFF).
// (inferred name: parse_aiff_header; CRI original by shape: AIFF_GetInfo, adx_baif)
u8 *TLobby__sub_803C2388(u8 *hdr, s32 *rate, s32 *channels, s32 *bits, s32 *frames) {
    u8 *p;
    u8 *end;
    u8 *data;
    s32 id;
    s32 size;
    s32 type;
    s32 have_comm;
    s32 have_ssnd;
    u16 exponent;
    u16 mantissa;
    u32 offset;

    p = hdr + 12;
    have_comm = 0;
    have_ssnd = 0;
    data = NULL;
    id = READ_LE32(hdr);
    size = READ_LE32(hdr + 4);
    size = SWAP32(size);
    type = READ_LE32(hdr + 8);
    if (id != 0x4D524F46) {
        return NULL;
    }
    if (type != 0x46464941) {
        return NULL;
    }
    end = p + size - 4;
    while (p < end) {
        id = READ_LE32(p);
        size = READ_LE32(p + 4);
        size = SWAP32(size);
        p += 8;
        switch (id) {
        case 0x4D4D4F43:
            if (have_comm != 0) {
                break;
            }
            if (size < 18) {
                return NULL;
            }
            have_comm = 1;
            *channels = READ_LE16(p);
            *channels = SWAP16(*channels);
            *frames = READ_LE32(p + 2);
            *frames = SWAP32(*frames);
            *bits = READ_LE16(p + 6);
            *bits = SWAP16(*bits);
            exponent = READ_LE16(p + 8);
            exponent = SWAP16(exponent);
            mantissa = READ_LE16(p + 10);
            mantissa = SWAP16(mantissa);
            p += 18;
            *rate = mantissa >> (0x400E - exponent);
            if (have_ssnd != 0) {
                return data;
            }
            break;
        case 0x444E5353:
            if (have_ssnd != 0) {
                break;
            }
            have_ssnd = 1;
            offset = READ_LE32(p);
            offset = SWAP32(offset);
            p += 4;
            data = p + offset;
            if (have_comm != 0) {
                return data;
            }
            break;
        default:
            p += (size + 1) & ~1;
            break;
        }
    }
    return data;
}

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

void TLobby__sub_803C34F4(Obj_803C34F4 *lobby) {
    s16 s = lobby->state;
    if (s == 0) {
        TLobby__sub_803C3570((Strm_803C1A8C *)lobby);
    } else if (s == 10) {
        TLobby__sub_803C19D8(lobby);
    } else if (s == 2) {
        TLobby__sub_803C40D0(lobby);
    } else if (s == 3) {
        ((TLobby *)lobby)->dispatch_network_state();
    } else if (s == 4) {
        ((TLobby *)lobby)->dispatch_by_state();
    } else if (s == 1) {
        TLobby__sub_803C0B3C((u8 *)lobby);
    }
}

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off
// Queues n blocks of both channels in the decoder and starts it (inferred: ADXB's stereo entry).
inline void entry_stereo_3570(void *obj, s32 n) {
    Strm_803C1A8C *o = (Strm_803C1A8C *)obj;
    TLobby *lobby;
    s16 *dst;

    dst = o->buf + o->pos;
    lobby = (TLobby *)o->id;
    lobby->post_request((s32)o->src, n * 2, (s32)dst, (s32)(dst + o->rOff));
    TLobby__sub_803CB4A4((u8 *)lobby);
}

// Queues n blocks of one channel in the decoder and starts it (inferred: ADXB's mono entry).
inline void entry_mono_3570(void *obj, s32 n) {
    Strm_803C1A8C *o = (Strm_803C1A8C *)obj;
    TLobby *lobby;
    s16 *dst;

    dst = o->buf + o->pos;
    lobby = (TLobby *)o->id;
    lobby->try_post_command((s32)o->src, n, (s32)dst);
    TLobby__sub_803CB4A4((u8 *)lobby);
}

// Queues the next decode: the least of the input blocks, the blocks that fit the write window
// (extended by the end padding when the end is inside it), the blocks before the end and those up
// to the ring end (+1 when a block may straddle it) (inferred: ADXB_EvokeDecode).
inline void evoke_decode_3570(Strm_803C1A8C *o) {
    s32 n;
    s32 pad;
    s32 bufsmpl;
    s32 ofst;
    s32 x70;
    s32 nblk;
    s32 avail;
    s32 room;
    s32 pos;
    s32 blk;
    s32 room_end;

    blk = o->block_samples;
    pos = o->pos;
    bufsmpl = o->bufLen;
    avail = o->avail;
    n = o->maxLen / o->stream_channels;
    x70 = o->x78;
    ofst = x70 + blk - 1;
    nblk = ofst / blk;
    pad = (blk - 1) - ofst % blk;
    room = (blk + (bufsmpl - pos) - 1) / blk;
    room_end = room * blk;
    if (nblk < room && pos + room_end - pad < bufsmpl) {
        room++;
    }
    if (x70 < avail) {
        avail += pad;
    }
    if (n > avail / blk) {
        n = avail / blk;
    }
    if (n > nblk) {
        n = nblk;
    }
    if (n > room) {
        n = room;
    }
    if (o->stream_channels == 2) {
        entry_stereo_3570(o, n);
    } else {
        entry_mono_3570(o, n);
    }
}

// One step of the stream decoder (inferred: ADXB_ExecOneAdx, with ADXB_EvokeDecode inlined).
void TLobby__sub_803C3570(Strm_803C1A8C *o) {
    if (o->state == 1 && ((TLobby *)(o->id))->get_client_count() == 0) {
        o->read(o->readArg, &o->pos, &o->avail, &o->x78);
        evoke_decode_3570(o);
        o->state = 2;
    }
    if (o->state == 2) {
        ((TLobby *)(o->id))->update_receive_check();
        if (((TLobby *)(o->id))->get_client_count() == 3) {
            s32 rOff;
            s32 size;
            s32 pos;
            s16 *buf;
            s32 rem;
            s32 width;
            s32 blk;
            s32 last;
            s32 n;
            s32 got;
            s32 nblk;
            blk = o->block_samples;
            width = o->sample_bytes;
            pos = o->pos;
            last = o->x78 + blk - 1;
            nblk = last / blk;
            rem = (blk - 1) - last % blk;
            buf = o->buf;
            size = o->wrap_len;
            rOff = o->wrap_offset;
            got = ((TLobby *)(o->id))->get_size();
            n = got * blk / o->stream_channels;
            if (nblk * o->stream_channels <= got) {
                n -= rem;
            }
            o->n = n;
            pos += n;
            o->bytes = got * width;
            if (pos >= size) {
                s32 i;
                s16 *dst;
                s16 *src;
                pos -= size;
                if (o->stream_channels == 2) {
                    dst = buf;
                    src = buf + size;
                    for (i = pos; i > 0; i--) {
                        *dst++ = *src++;
                    }
                    src = buf + (rOff + size);
                    dst = buf + rOff;
                    for (i = pos; i > 0; i--) {
                        *dst++ = *src++;
                    }
                } else {
                    src = buf + size;
                    for (i = pos; i > 0; i--) {
                        *buf++ = *src++;
                    }
                }
            }
            ((TLobby *)(o->id))->reset_field_0C();
            o->done(o->doneArg, o->bytes, o->n);
            o->state = 3;
        }
    }
}

#pragma pop

s32 TLobby::get_field_a0() {
    u8 *arg0 = (u8 *)this;
    return *(s32 *)((s8 *)arg0 + 0xA0);
}

s32 TLobby::get_field_0xa4() {
    u8 *arg0 = (u8 *)this;
    return *(s32 *)((s8 *)arg0 + 0xA4);
}

void TLobby__sub_803C3984(u8 *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 4) == 3) {
        ((TLobby *)(*(s32 *)((s8 *)arg0 + 8)))->reset_field_0C();
        *(s32 *)((s8 *)arg0 + 0x9C) = 0;
        *(s32 *)((s8 *)arg0 + 4) = 0;
    }
}

void TLobby__sub_803C39CC(u8 *arg0) {
    ((TLobby *)(*(s32 *)((s8 *)arg0 + 8)))->reset_client_state();
    *(s32 *)((s8 *)arg0 + 4) = 0;
}

void TLobby__sub_803C3A04(u8 *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 4) == 0) {
        *(s32 *)((s8 *)arg0 + 4) = 1;
    }
}

void TLobby::init_scroll(s32 arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    if (*(s16 *)((s8 *)arg0 + 0xA8) == 0) {
        *(s32 *)((s8 *)arg0 + 0x50) = arg1;
        *(s32 *)((s8 *)arg0 + 0x54) = (s32) (arg2 / (s8) *(u8 *)((s8 *)arg0 + 0xF));
        *(s32 *)((s8 *)arg0 + 0x84) = 0;
        *(s32 *)((s8 *)arg0 + 0xA0) = 0;
        *(s32 *)((s8 *)arg0 + 0xA4) = 0;
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x50) = arg1;
    *(s32 *)((s8 *)arg0 + 0x54) = (s32) (arg2 / (s32) (((s8) *(u8 *)((s8 *)arg0 + 0xD) / 8) * (s8) *(u8 *)((s8 *)arg0 + 0xE)));
    *(s32 *)((s8 *)arg0 + 0x84) = 0;
    *(s32 *)((s8 *)arg0 + 0xA0) = 0;
    *(s32 *)((s8 *)arg0 + 0xA4) = 0;
}

s32 TLobby::get_entry_id() {
    return *(s32 *)&this->m_flags;
}

s32 TLobby::get_field_34() {
    u8 *arg0 = (u8 *)this;
    return *(s32 *)((s8 *)arg0 + 0x34);
}

s32 TLobby::get_field30() {
    u8 *arg0 = (u8 *)this;
    return *(s32 *)((s8 *)arg0 + 0x30);
}

s32 TLobby::get_field_2c() {
    u8 *arg0 = (u8 *)this;
    return *(s32 *)((s8 *)arg0 + 0x2C);
}

s32 TLobby::get_field_28() {
    u8 *arg0 = (u8 *)this;
    return *(s32 *)((s8 *)arg0 + 0x28);
}

s16 TLobby::get_slot() {
    u8 *arg0 = (u8 *)this;
    return *(s16 *)((s8 *)arg0 + 0x24);
}

s32 TLobby__sub_803C3ABC(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x18);
}

s32 TLobby__sub_803C3AC4(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x10);
}

s32 TLobby::get_packet_flag_for_state() {
    Obj_803C3ACC *arg0 = (Obj_803C3ACC *)this;
    s16 s = arg0->state;
    if (s == 0) {
        return 0x10;
    }
    if (s == 2) {
        if (arg0->sub == 2) {
            return 4;
        }
        if (arg0->sub == 1) {
            return 8;
        }
        return 0x10;
    }
    if (s == 1) {
        if (arg0->sub == 2) {
            return 4;
        }
        return 0x10;
    }
    return 0x10;
}

s8 TLobby__sub_803C3B38(u8 *arg0) {
  s8 *new_var3;
  unsigned int new_var2;
  s8 *new_var4;
  u8 new_var;
  new_var4 = (s8 *) arg0;
  new_var3 = 0xE + new_var4;
  new_var = (*((u8 *) new_var3)) & 0xFFFFFFFFFFFFFFFFu;
  ;
  return (s8) (new_var & 0xFF);
}

s32 TLobby__sub_803C3B44(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x14);
}

s32 TLobby::get_field_a8() {
    u8 *arg0 = (u8 *)this;
    return *(s16 *)((s8 *)arg0 + 0xA8);
}

s32 TLobby::get_field_0x3c() {
    u8 *arg0 = (u8 *)this;
    return *(s32 *)((s8 *)arg0 + 0x3C);
}

void TLobby__sub_803C3B5C(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0x88) = arg1;
    *(s32 *)((s8 *)arg0 + 0x8C) = arg2;
}

s32 TLobby__sub_803C3B68(s32 arg0, u16 *hdr, s32 size) {
    if ((u16) *(u16 *)((s8 *)hdr + 0) == 0x8000) {
        return TRK__write_aram((void *)((void *)arg0), hdr, (void *)((void *)size));
    }
    if (((TLobby *)hdr)->is_spsd_header() != 0) {
        return TLobby__sub_803C43A8((void *)arg0, (void *)hdr, (void *)size);
    }
    if (((TLobby *)hdr)->is_riff_wave() != 0) {
        return DVDReadPrio((void *)arg0, (void *)hdr, (void *)size);
    }
    if (((TLobby *)hdr)->is_aiff_header() != 0) {
        return ((TLobby *)arg0)->parse_stream_header((void *)hdr, (void *)size);
    }
    if (((TLobby *)hdr)->is_snd_header() != 0) {
        return TLobby__sub_803C30E8((u8 *)arg0, (s32)hdr, (s32)size);
    }
    return 0;
}

s32 TRK__write_aram(void *arg0p, void *hdr, void *size) {
    u8 *arg0 = (u8 *)arg0p;
    s32 sp18;
    s32 sp14;
    s16 sp10;
    u8 *temp_r3;
    *(s16 *)((s8 *)arg0 + 2) = 1;
    if (ARStartDMA((u8 *)hdr, (s32)size, (s16 *)&sp10, (u8 *)(arg0 + 0xC), (s8 *)(arg0 + 0xD), (s8 *)(arg0 + 0xF), (u8 *)(arg0 + 0xE), (s32 *)(arg0 + 0x14), (s32 *)(arg0 + 0x18), (s32 *)(arg0 + 0x10)) < 0) {
        return 0;
    }
    if ((s8) *(u8 *)((s8 *)arg0 + 0xC) > 4) {
        if ((u32) *(u32 *)((s8 *)arg0 + 0xAC) == 0U) {
            TLobby::report_adx_error((const char *)lbl_8047C520, (s32)lbl_8047C540);
            return 0;
        }
        *(s8 *)((s8 *)arg0 + 0xD) = 8;
        *(u8 *)((s8 *)arg0 + 0xF) = (u8) (*(u8 *)((s8 *)arg0 + 0xE) * 0xC0);
        *(s32 *)((s8 *)arg0 + 0x10) = 0x60;
        *(s16 *)((s8 *)arg0 + 0xA8) = 0xA;
        goto block_11;
    }
    if (TLobby__sub_803C48C8((u8 *)hdr, (s32)size, (u16 *)(arg0 + 0x1C)) < 0) {
        return 0;
    }
    if (((TLobby *)hdr)->parse_header_loop_points((s32)size, (u16 *)&sp18, (u16 *)&sp14) < 0) {
        return 0;
    }
    ((TLobby *)(*(s32 *)((s8 *)arg0 + 8)))->calc_adx_coeffs_at_offset((void *)(*(s32 *)((s8 *)arg0 + 0x14)), (s32)((int) (*(s16 *)((s8 *)arg0 + 0x1C))));
    TLobby__sub_803CB570((u8 *)(*(s32 *)((s8 *)arg0 + 8)), (u8 *)&sp18, (s16 *)&sp14);
    __DVDPrepareResetAsync((u8 *)hdr, (s32)size, (s32 *)(arg0 + 0x20), (s16 *)(arg0 + 0x24), (s16 *)(arg0 + 0x26), (s32 *)(arg0 + 0x28), (s32 *)(arg0 + 0x2C), (s32 *)(arg0 + 0x30), (s32 *)(arg0 + 0x34));
    *(s16 *)((s8 *)arg0 + 0xA8) = 0;
block_11:
    temp_r3 = (arg0 + 0x4C);
    *(s32 *)((s8 *)arg0 + 0x58) = (s32) (s8) *(u8 *)((s8 *)arg0 + 0xE);
    *(s32 *)((s8 *)arg0 + 0x5C) = (s32) (s8) *(u8 *)((s8 *)arg0 + 0xF);
    *(s32 *)((s8 *)arg0 + 0x60) = (s32) *(s32 *)((s8 *)arg0 + 0x10);
    *(s32 *)((s8 *)arg0 + 0x64) = (s32) *(s32 *)((s8 *)arg0 + 0x3C);
    *(s32 *)((s8 *)arg0 + 0x68) = (s32) *(s32 *)((s8 *)arg0 + 0x40);
    *(s32 *)((s8 *)arg0 + 0x6C) = (s32) *(s32 *)((s8 *)arg0 + 0x44);
    *(s16 *)((s8 *)arg0 + 0x7C) = (s16) *(s16 *)((s8 *)arg0 + 0x48);
    *(s16 *)((s8 *)arg0 + 0x7E) = (*(s16 *)((s8 *)arg0 + 0x4A));
    *(u8 **)((s8 *)arg0 + 0x80) = temp_r3;
    *(s32 *)((s8 *)arg0 + 0x9C) = 0;
    memset(temp_r3, 0, 4);
    return sp10;
}

void TLobby::clear_record() {
    u8 *arg0 = (u8 *)this;
    if (arg0 != NULL) {
        ((TLobby *)(*(s32 *)&this->m_prev))->clear_record_data();
        memset(arg0, 0, 0xB8);
        *(s16 *)&this->m_name = 0;
    }
}

#pragma push
#pragma inline_depth(4)
#pragma dont_inline off
inline void free_803C3E88(Rec_803C3E88 *r) {
    if (r != NULL) {
        ((TLobby *)(r->f8))->clear_record_data();
        memset(r, 0, 0xB8);
        r->used = 0;
    }
}
Rec_803C3E88 *alloc_record__6TLobbyFiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 i;
    Rec_803C3E88 *r;
    for (i = 0; i < 16; i++) {
        if (adx_channel_record_pool[i].used == 0) {
            break;
        }
    }
    if (i == 16) {
        return NULL;
    }
    r = &adx_channel_record_pool[i];
    memset(r, 0, 0xB8);
    r->used = 1;
    r->f8 = adx_allocate_decoder_channel();
    if (r->f8 == 0) {
        free_803C3E88(r);
        return NULL;
    }
    r->f38 = arg0;
    r->f3c = arg1;
    r->f40 = arg2;
    r->f44 = arg3;
    r->f88 = (void *)get_progress_info__6TLobbyFPvPvPvPv;
    r->f8c = r;
    r->f90 = (void *)TLobby__sub_803C4020;
    r->f94 = r;
    return r;
}
#pragma pop

void TLobby__sub_803C4020(u8 *arg0, s32 arg1, s32 arg2) {
    *(s32 *)((s8 *)arg0 + 0x9C) = (s32) (*(s32 *)((s8 *)arg0 + 0x9C) + arg2);
    *(s32 *)((s8 *)arg0 + 0x98) = (s32) (*(s32 *)((s8 *)arg0 + 0x98) + arg2);
}

s32 get_progress_info__6TLobbyFPvPvPvPv(u8 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    *arg1 = *(s32 *)((s8 *)arg0 + 0x9C);
    *arg2 = *(s32 *)((s8 *)arg0 + 0x40) - *(s32 *)((s8 *)arg0 + 0x9C);
    *arg3 = *(s32 *)((s8 *)arg0 + 0x18) - *(s32 *)((s8 *)arg0 + 0x98);
    return *(s32 *)((s8 *)arg0 + 0x3C);
}
typedef char RecoveredGlobal_803C0AD8_lbl_80570AC0_size[sizeof(RecoveredGlobal_803C0AD8_lbl_80570AC0) == 0x9C0 ? 1 : -1];
void TLobby__sub_803C406C(void) {
    TLobby::clear_buffer_340();
    memset(adx_channel_record_pool, 0, sizeof(adx_channel_record_pool));
}
s32 TLobby::is_spsd_header() {
    if (memcmp(this, lbl_805E0CE0, 4) == 0) {
        return 1;
    }
    return 0;
}
void TLobby__sub_803C40D0(void *arg) {
    Strm_803C1A8C *o = (Strm_803C1A8C *)arg;
    u16 *src = (u16 *)o->src;
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
                l[i] = src[i * 2];
                r[i] = src[i * 2 + 1];
            }
        } else {
            for (i = 0; i < n; i++) {
                l[i] = src[i];
            }
        }
        o->n = n;
        o->bytes = o->channels * (n * 2);
        o->state = 2;
    }
    if (o->state == 2) {
        o->done(o->doneArg, o->bytes, o->n);
        o->state = 3;
    }
}

struct Hdr_803C44C0;
s32 TLobby__sub_803C43A8(void *arg0, void *hdr, void *arg2) {
    Hdl_803C43A8 *h = (Hdl_803C43A8 *)arg0;
    s16 n;
    h->f2 = 1;
    if (TLobby__sub_803C44C0((Hdr_803C44C0 *)((Hdr_803C44C0 *)hdr), (s32)((s32)arg2), &n, &h->fc, &h->fd, &h->ff, &h->fe, &h->f14, &h->f18, &h->f10, &h->faa) < 0) {
        return 0;
    }
    h->f1c = 0;
    h->f4a = 0;
    h->f48 = 0;
    h->f26 = 0;
    h->f24 = 0;
    h->f34 = 0;
    h->f30 = 0;
    h->f2c = 0;
    h->f28 = 0;
    h->f20 = 0;
    h->f58 = h->fe;
    h->f5c = h->ff;
    h->f60 = h->f10;
    h->f64 = h->f3c;
    h->f68 = h->f40;
    h->f6c = h->f44;
    h->f7c = h->f48;
    h->f7e = h->f4a;
    h->f80 = h->f4c;
    h->f9c = 0;
    h->f98 = 0;
    h->fa8 = 2;
    memset(h->f4c, 0, 4);
    return n;
}
s32 TLobby__sub_803C44C0(Hdr_803C44C0 *hdr, s32 arg1, s16 *arg2, s8 *arg3, s8 *arg4, s8 *arg5, s8 *arg6, s32 *arg7, s32 *arg8, s32 *arg9, s16 *arg10) {
    *arg2 = hdr->f7 * 0x10;
    *arg6 = (hdr->f9 & 3) + 1;
    *arg7 = hdr->f2a;
    switch (hdr->f8) {
    case 0:
        *arg4 = 0x10;
        *arg5 = *arg6 * 2;
        *arg9 = 1;
        *arg8 = hdr->fc / 2;
        *arg10 = 0;
        break;
    case 1:
        *arg4 = 8;
        *arg5 = *arg6;
        *arg9 = 1;
        *arg8 = hdr->fc;
        *arg10 = 1;
        break;
    case 2:
    case 3:
        *arg4 = 4;
        *arg5 = *arg6;
        *arg9 = 2;
        *arg8 = hdr->fc * 2;
        *arg10 = 2;
        break;
    }
    *arg5 = 2;
    *arg9 = 1;
    *arg8 = hdr->fc / 2;
    *arg4 = 0x10;
    *arg3 = -1;
    return 0;
}

}
