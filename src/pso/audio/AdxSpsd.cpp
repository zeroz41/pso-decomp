// CRI adx_bsps.c: the SPSD decoder (ADXB_CheckSpsd, ADXB_ExecOneSpsd, header decode and info).
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
void TLobby__sub_803C19D8(void *);
void TLobby__sub_803C3570(Strm_803C1A8C *o);
void TLobby__sub_803C40D0(void *);
void TLobby__sub_803C34F4(Obj_803C34F4 *arg0);
s32 DVDReadPrio(void *, void *, void *);
s32 TLobby__sub_803C44C0(Hdr_803C44C0 *hdr, s32 arg1, s16 *arg2, s8 *arg3, s8 *arg4, s8 *arg5, s8 *arg6, s32 *arg7, s32 *arg8, s32 *arg9, s16 *arg10);
u32 adx_allocate_decoder_channel();
Rec_803C3E88 *alloc_record__6TLobbyFiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void process_byteswapped_pcm_transfer(Snd_803C1DC4 *arg0);
void TLobby__sub_803C2A00(Strm_803C1A8C *o);

s32 TLobby::is_spsd_header() {
    if (memcmp(this, "SPSD", 4) == 0) {
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
