// CRI adx_bsc.c: the ADXB decoder handles (ADXB_ExecHndl, the ADX block step, header decode, create/destroy).
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

}
