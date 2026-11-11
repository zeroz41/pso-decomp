// CRI adx_baif.c: the AIFF decoder (ADXB_ExecOneAiff and its 8/16-bit steps, header check and parse).
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

}
