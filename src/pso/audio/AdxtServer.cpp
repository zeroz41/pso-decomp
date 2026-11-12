#include <dolphin/os/OSThread.h>
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/unk/text_803D31A4.h"

struct Pair_803C8678 { u32 a, b; };

extern "C" {
s32 TLobby__sub_803D3130(void *, s32, Pair_803C8678 *, Pair_803C8678 *);
s32 memset(void *, int, int);
}

extern "C" {
s32 TLobby__sub_803C8B2C(u8 *arg0);

}

struct Strm_803CB20C;
struct Buf_803CB20C { void *data; s32 size; };

struct VT_803CB20C {
    void *pad[5];
    void (*m14)(Strm_803CB20C *);
    void (*lock)(Strm_803CB20C *, s32, s32, Buf_803CB20C *);
    void *pad1C;
    void (*commit)(Strm_803CB20C *, s32, Buf_803CB20C *);
};

struct Strm_803CB20C { VT_803CB20C *vt; };

struct Obj_803CB20C {
    u8 pad0[2]; u8 f2; u8 pad3; s32 f4; u32 f8; u8 padC[8]; Strm_803CB20C *f14;
    u8 pad18[0x4C - 0x18]; s32 f4C; s32 f50; u8 pad54[0x6C - 0x54]; s8 f6C;
    u8 pad6D[0x90 - 0x6D]; s32 f90;
};

extern "C" {
s32 dispatch_field4_event__6TLobbyFv(int);
s32 send_with_offset4_alt__6TLobbyFv(int);
s32 notify_client__6TLobbyFv(int);
s32 set_field_44__6TLobbyFl(int, int);
s32 set_field_40__6TLobbyFl(int, int);
s32 set_field_3c__6TLobbyFl(int, int);
s32 set_count__6TLobbyFl(int, int);
void adxt_trap_entry_update__6TLobbyFPv(Obj_803CB20C *arg0);

extern s32 lbl_805D7540;
}

extern "C" {
s32 TLobby__sub_803CC030(int, int);
s32 dispatch_packet__6TLobbyFv(int, int);
void TLobby__sub_803CB194(u8 *arg0);
void TLobby__sub_803C0758(u8 *arg0);
s32 TLobby__sub_803CBF50(void *);
void TLobby__sub_803CA8B4(Ent_803C9608 *);

s32 TLobby__sub_803C9740(u8 *arg0);
s32 notify_field_4__6TLobbyFv(int);
s32 send_packet_by_id__6TLobbyFv(int);
s32 send_with_offset4__6TLobbyFv(int);
s32 trigger_sub_task__6TLobbyFv(int);

extern "C" {
s32 TLobby__sub_803C0010(u8 *arg0);
s32 send_packet_by_id_2__6TLobbyFv(int);
s32 query_available_size__6TLobbyFv(int);
}

}
void stop_audio_stream(u8 *arg0);
extern "C" {

struct Strm_803CAB38 {
    u8 f0;
    s8 f1;
    u8 f2;
    s8 f3;
    s32 f4;
    void *f8;
    s32 fc;
    u8 pad10[0x28];
    s32 f38;
    s16 f3c_pad;
    s16 f3e_pad;
    s16 f40;
    s16 f42;
    s16 f44;
    s16 pad46;
    s32 f48;
    s32 pad4c;
    s32 f50;
    u8 pad54[0x20];
    void *f74;
    u8 pad78[0x14];
    s32 f8c;
    s32 f90;
};

s32 TLobby__sub_803BFE58(int);
s32 TLobby__sub_803BFEE8(int);
s32 notify_field_4_alt__6TLobbyFv(int);
s32 send_packet_by_id_2__6TLobbyFv(int);
s32 TLobby__sub_803BFFC0(int);
void TLobby__sub_803BFFFC(u8 *arg0, s32 arg1, s32 arg2);
s32 TLobby__sub_803C07E8(int);
s32 run_step_4430__6TLobbyFv(int, int);
s32 TLobby__sub_803CBF0C(int, int);
s32 TLobby__sub_803CBF30(int, int);
s32 TLobby__sub_803CBF90(int, int);
s32 TLobby__sub_803CBFB0(int, int);
struct Conn_803CAEB4;
void TLobby__sub_803CAEB4(Conn_803CAEB4 *arg0);

void TLobby__sub_803CAB38(Strm_803CAB38 *self);
s32 TLobby__sub_803CBFF0(int);
s32 lbl_805D7578;
s32 lbl_805D757C;
s32 lbl_805D7580;

// Inferred: CRI adxt_stat_prep (wait until every output SJ holds data, then start the RNA).
inline void prep_803CA8B4(Ent_803C9608 *self) {
    s32 n;
    s32 i;
    if (TLobby__sub_803C07E8(self->f4) == 3) {
        n = send_with_offset4__6TLobbyFv(self->f4);
        lbl_805D7580 = n;
        for (i = 0; i < n; i++) {
            lbl_805D757C = self->f18[i]->interface->get_available(self->f18[i], 1);
            if (lbl_805D757C >= 0x40) {
                break;
            }
        }
        if (i == n) {
            dispatch_packet__6TLobbyFv(self->fC, 0);
            self->stat = 4;
        }
    }
}
// Inferred: CRI adxt_stat_playing (start playback once enough is decoded; pad the end with silence).
inline void dec_803CA8B4(Ent_803C9608 *self) {
    s32 rna = self->fC;
    s32 sjd = self->f4;
    s32 i;
    s32 avail;
    s32 nbyte;
    s32 size;
    s32 nch;
    SjRingBuffer *sj;
    SjChunk ck;
    avail = query_available_size__6TLobbyFv(rna);
    size = TLobby__sub_803CBFF0(rna);
    if (avail >= self->f48 * 2 || size <= notify_field_4_alt__6TLobbyFv(sjd) ||
        TLobby__sub_803C07E8(self->f4) == 3) {
        if (self->f70 == 0) {
            if (self->f72 == 0) {
                TLobby__sub_803CC030(rna, 1);
                self->f9C = 0;
                self->fA0 = lbl_805D7540;
            }
            self->stat = 3;
        }
        self->f71 = 1;
    }
    if (TLobby__sub_803C07E8(self->f4) == 3) {
        nch = TLobby__sub_803C9740((u8 *)self);
        nbyte = self->f48 * nch * 2;
        for (i = 0; i < nch; i++) {
            sj = self->f18[i];
            sj->interface->get_chunk(sj, 0, nbyte, &ck);
            memset(ck.data, 0, ck.size);
            sj->interface->put_chunk(sj, 1, &ck);
        }
    }
}
// Inferred: CRI adxt_stat_playend (stop the RNA once its queue is empty).
inline void end_803CA8B4(Ent_803C9608 *self) {
    lbl_805D7578 = query_available_size__6TLobbyFv(self->fC);
    if (query_available_size__6TLobbyFv(self->fC) <= 0) {
        TLobby__sub_803CC030(self->fC, 0);
        self->stat = 5;
    }
}
#pragma push
#pragma opt_common_subs off
// Inferred: CRI ADXT_ExecHndl (per-handle state step of the ADXT server).
void TLobby__sub_803CA8B4(Ent_803C9608 *self) {
    s8 stat = self->stat;
    if (stat == 3) {
        prep_803CA8B4(self);
    } else if (stat == 1) {
        TLobby__sub_803CAB38((Strm_803CAB38 *)self);
    } else if (stat == 2) {
        dec_803CA8B4(self);
    } else if (stat == 4) {
        end_803CA8B4(self);
    }
    if (self->f8 != NULL && TLobby__sub_803C8B2C(self->f8) == 4) {
        self->f60 = -1;
        self->stat = 6;
    }
    if (self->f94 != NULL && lsc_get_state(self->f94) == 3) {
        self->f60 = -1;
        self->stat = 6;
    }
}
#pragma pop

#define SBF50 TLobby__sub_803CBF50

void TLobby__sub_803CAB38(Strm_803CAB38 *self) {
#define arg0 ((u8 *)self)
    s32 TLobby__sub_803CBF50(s32, s32, s32);
    s32 trigger_sub_task__6TLobbyFv(int, int);
    s32 t = self->f4;
    s32 k;
    s32 n1;
    char buf[32];

    if (TLobby__sub_803C07E8(t) == 2) {
        s32 v = send_with_offset4__6TLobbyFv(t);
        if (v > self->f3) {
            TLobby::format_number_pair(v, self->f3, buf, 0x10);
            TLobby::report_adx_error("E9081001 adxt_stat_decinfo: can't play this number of channels", buf);
            stop_audio_stream(arg0);
            return;
        }
        n1 = notify_field_4__6TLobbyFv(t);
        k = TLobby__sub_803BFEE8(t);
        if (k > 0) {
            self->f48 = (n1 / self->f38) * 3;
        } else {
            self->f48 = ((n1 / self->f38) * 3) / 2;
        }
        {
            s32 a = notify_field_4_alt__6TLobbyFv(t) * 2;
            self->f48 = a * ((self->f48 + a) / a);
        }
        ((TLobby *)t)->set_network_result(self->f48);
        if (k > 0) {
            if ((s32) self->f2 == 2) {
                self->f50 = 0;
            } else {
                s32 x = TLobby__sub_803BFE58(t);
                s32 pages;
                self->f50 = 0x800 - x % 0x800;
                pages = (x + 0x7FF) / 0x800;
                self->f50 = self->f50 % 0x800;
                self->f8c = pages;
                ((TLobby *)(self->f8))->set_scroll_position(pages);
                ((TLobby *)(self->f8))->set_coords((s32)((void *)TLobby__sub_803CB194), (s32)arg0);
            }
            s32 e = dispatch_field4_event__6TLobbyFv(t);
            self->f90 = e;
            set_field_3c__6TLobbyFl(t, e);
            set_field_44__6TLobbyFl(t, 0);
            set_field_40__6TLobbyFl(t, 0);
            TLobby__sub_803BFFFC((u8 *)t, (s32)adxt_trap_entry_update__6TLobbyFPv, (s32)arg0);
        } else {
            if (self->f8 != NULL) {
                ((TLobby *)(self->f8))->set_scroll_position(0x7FFFFFFF);
            }
            set_field_3c__6TLobbyFl(t, send_packet_by_id__6TLobbyFv(t));
            set_field_44__6TLobbyFl(t, 0);
            set_field_40__6TLobbyFl(t, 0);
            TLobby__sub_803BFFFC((u8 *)t, (s32)TLobby__sub_803CAEB4, (s32)arg0);
        }
        k = notify_field_4__6TLobbyFv(t);
        n1 = send_with_offset4__6TLobbyFv(t);
        s32 pid = send_packet_by_id__6TLobbyFv(t);
        s32 p2 = send_packet_by_id_2__6TLobbyFv(t);
        TLobby__sub_803CBF30(self->fc, p2);
        TLobby__sub_803CBF90(self->fc, k);
        TLobby__sub_803CBFB0(self->fc, n1);
        TLobby__sub_803CBF0C(self->fc, pid);
        trigger_sub_task__6TLobbyFv(self->fc, self->f40);
        if (send_with_offset4__6TLobbyFv(self->f4) == 1) {
            if (self->f42 == -0x80) {
                SBF50(self->fc, 0, 0);
            } else {
                SBF50(self->fc, 0, self->f42);
            }
        } else {
            if (self->f42 == -0x80) {
                SBF50(self->fc, 0, -0xF);
            } else {
                SBF50(self->fc, 0, self->f42);
            }
            if (self->f44 == -0x80) {
                SBF50(self->fc, 1, 0xF);
            } else {
                SBF50(self->fc, 1, self->f44);
            }
        }
        if (self->f74 != NULL) {
            ((TLobby *)(self->f74))->set_packet_flags(k);
        }
        if (TLobby__sub_803BFFC0(t) == 2) {
            s32 o = ((TLobby *)t)->get_offset_58();
            run_step_4430__6TLobbyFv(self->fc, o);
        }
        dispatch_packet__6TLobbyFv(self->fc, 1);
        self->f1 = 2;
    }
}
#undef arg0
#undef SBF50

extern "C" {

typedef struct Buf_803CAEB4 Buf_803CAEB4;
typedef struct Conn_803CAEB4 Conn_803CAEB4;
typedef struct RingVt_803CAEB4 RingVt_803CAEB4;
typedef struct Ring_803CAEB4 Ring_803CAEB4;
struct Buf_803CAEB4
{
  u8 *p;
  s32 len;
};
struct Ring_803CAEB4;
struct RingVt_803CAEB4
{
  u8 pad0[0x18];
  void (*m4)(Ring_803CAEB4 *, s32, s32, Buf_803CAEB4 *);
  void (*m5)(Ring_803CAEB4 *, s32, Buf_803CAEB4 *);
  void (*m6)(Ring_803CAEB4 *, s32, Buf_803CAEB4 *);
};
struct Ring_803CAEB4
{
  RingVt_803CAEB4 *vt;
};
struct Conn_803CAEB4
{
  u8 pad0[4];
  s32 lobby;
  u8 pad8[0x14 - 0x8];
  Ring_803CAEB4 *ring;
  u8 pad18[0x48 - 0x18];
  s32 f48;
  u8 pad4C[0x98 - 0x4C];
  s8 active;
  u8 pad99[0xA4 - 0x99];
  s32 fA4;
};
s32 TLobby__sub_803C0010(u8 *arg0);
s32 process_audio_stream_input(int);

void TLobby__sub_803CAEB4(Conn_803CAEB4 *o) {
  s32 lobby = o->lobby;
  Ring_803CAEB4 *ring = o->ring;
  Buf_803CAEB4 a;
  Buf_803CAEB4 c;
  Buf_803CAEB4 b;
  Buf_803CAEB4 d;
  s16 hlen;
  s16 tlen;
  s32 r1;
  s32 r2;
  s32 n;
  s32 m;
  if (o->active != 0)
  {
    tlen = 0;
    ring->vt->m4(ring, 1, 0x7FFFFFFF, &a);
    ring->vt->m4(ring, 1, 0x7FFFFFFF, &b);
    if (((TLobby *)(a.p))->parse_packet_header_len(a.len, &hlen) != 0)
    {
      o->active = 0;
      ring->vt->m5(ring, 1, &b);
      ring->vt->m5(ring, 1, &a);
      return;
    }
    n = hlen;
    r1 = TLobby::find_terminator_index((s16 *)(a.p + n), (s32)(a.len - n), &hlen);
    if (r1 == 0)
    {
      r2 = -1;
    }
    else
    {
      r2 = TLobby::find_terminator_index((s16 *)b.p, (s32)b.len, &tlen);
    }
    n += hlen;
    m = tlen & 0xFFFFFFFFFFFFFFFFu;
    if ((r1 != 0) && (r2 != 0))
    {
      ring->vt->m5(ring, 1, &b);
      ring->vt->m5(ring, 1, &a);
      o->active = 0;
      return;
    }
    if (r1 == 0)
    {
      ring->vt->m5(ring, 1, &b);
      TLobby__sub_803D3130(&a, n, (Pair_803C8678 *)&a, (Pair_803C8678 *)&c);
      ring->vt->m6(ring, 0, &a);
      ring->vt->m5(ring, 1, &c);
    }
    else
    {
      ring->vt->m6(ring, 0, &a);
      TLobby__sub_803D3130(&b, m, (Pair_803C8678 *)&b, (Pair_803C8678 *)&d);
      ring->vt->m6(ring, 0, &b);
      ring->vt->m5(ring, 1, &d);
    }
    o->fA4 += TLobby__sub_803C0010((u8 *)lobby);
    ((TLobby *)lobby)->reset_flag();
    TLobby__sub_803C0758((u8 *)lobby);
    process_audio_stream_input(lobby);
    if (TLobby__sub_803C07E8(lobby) != 2)
    {
      o->active = 0;
      return;
    }
    ((TLobby *)lobby)->set_network_result(o->f48);
    set_field_3c__6TLobbyFl(lobby, send_packet_by_id__6TLobbyFv(lobby));
    set_field_44__6TLobbyFl(lobby, 0);
    set_field_40__6TLobbyFl(lobby, 0);
  }
}

}

void TLobby__sub_803CB194(u8 *arg0) {
    s32 temp_r3;
    u8 *lobby;
    lobby = (u8 *)(*(u8 **)((s8 *)arg0 + 8));
    temp_r3 = send_with_offset4_alt__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 4)));
    if ((s8) *(u8 *)((s8 *)arg0 + 0x6C) == 0) {
        set_field_3c__6TLobbyFl((int) (*(s32 *)((s8 *)arg0 + 4)), -1);
        ((TLobby *)(*(u8 **)((s8 *)arg0 + 8)))->set_scroll_position(0x7FFFFFFF);
        return;
    }
    ((TLobby *)lobby)->set_scroll_offset(temp_r3 / 2048);
}

void adxt_trap_entry_update__6TLobbyFPv(Obj_803CB20C *arg0) {
    Buf_803CB20C b;
    Strm_803CB20C *s;
    s32 off;
    s32 total;
    s32 id;
    s32 c;
    id = arg0->f4;
    s = arg0->f14;
    c = notify_client__6TLobbyFv(id);
    off = send_with_offset4_alt__6TLobbyFv(id);
    total = dispatch_field4_event__6TLobbyFv(id);
    if (arg0->f8 == 0U && arg0->f6C == 0) {
        set_field_3c__6TLobbyFl(arg0->f4, -1);
        return;
    }
    s->vt->lock(s, 1, arg0->f50, &b);
    if (b.size < arg0->f50) {
        TLobby::notify_error("E8101201 adxt_trap_entry: not enough data");
    }
    s->vt->commit(s, 0, &b);
    set_field_40__6TLobbyFl(id, 0);
    set_field_3c__6TLobbyFl(id, arg0->f90 = total - c);
    set_field_44__6TLobbyFl(id, off);
    set_count__6TLobbyFl(id, c);
    if ((s32)arg0->f2 == 2) {
        s->vt->m14(s);
        s->vt->lock(s, 1, off, &b);
        s->vt->commit(s, 0, &b);
    }
    arg0->f4C += 1;
}

}
