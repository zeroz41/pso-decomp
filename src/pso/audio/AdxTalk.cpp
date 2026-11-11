#include <dolphin/os/OSThread.h>
#include "pso/unk/TLobby.h"
#include "pso/audio/AdxStreamRuntime.h"
#include "pso/audio/AdxmThreadStorage.h"
#include "pso/audio/LscStream.h"
#include "pso/audio/SjRingBuffer.h"

#include "types.h"
#include "pso/unk/text_803CBCA0.h"
#include "pso/unk/text_803D31A4.h"

struct Pair_803C8678 { u32 a, b; };

struct Strm_803C9104;
struct Buf_803C9104 {
    void *ptr;
    s32 size;
};

struct Vt_803C9104 {
    u8 pad[0x18];
    void (*lock)(Strm_803C9104 *, s32, s32, Buf_803C9104 *);
    void (*unlock)(Strm_803C9104 *, s32, Buf_803C9104 *);
    void (*write)(Strm_803C9104 *, s32, Buf_803C9104 *);
};

struct Strm_803C9104 {
    Vt_803C9104 *vt;
};

struct Obj_803C9104 {
    u8 pad[0x14];
    Strm_803C9104 *strm;
};

extern "C" {
s32 TLobby__sub_803D3130(void *, s32, Pair_803C8678 *, Pair_803C8678 *);
s32 memset(void *, int, int);
s32 TLobby__sub_803C9104(Obj_803C9104 *arg0, s32 arg1, s32 arg2);
}

extern "C" {
void TLobby__sub_803C89C4(u8 *arg0);
void TLobby__sub_803C8B38(u8 *arg0);
void TLobby__sub_803C9DB4(u8 *arg0);
s32 ARStartDMA(u8 *arg0, s32 arg1, s16 *arg2, u8 *arg3, s8 *arg4, s8 *arg5, u8 *arg6, s32 *arg7, s32 *arg8, s32 *arg9);
s32 adx_get_data_start_offset(u16 *arg0, s32 arg1, s32 *arg2);
s32 set_range__6TLobbyFPvii(u8 *arg0, s32 arg1, s32 arg2);
void TLobby__sub_803C9608(void);
s32 set_global_805D7520__6TLobbyFl();

}

extern "C" {

void TLobby::on_set_mode() {
    set_global_805D7520__6TLobbyFl();
}

s32 TLobby__sub_803C9104(Obj_803C9104 *arg0, s32 arg1, s32 arg2) {
    s32 blk;
    s32 total;
    Strm_803C9104 *s;
    s32 n1;
    s32 n2;
    Buf_803C9104 a;
    Buf_803C9104 b;
    void *p = arg0->strm;
    s = (Strm_803C9104 *)p;
    if (p == NULL) {
        return 0;
    }
    blk = arg1 * 0x12;
    total = (arg2 / 32) * blk;
    s->vt->lock(s, 0, total, &a);
    n1 = blk * (a.size / blk);
    memset(a.ptr, 0, n1);
    TLobby__sub_803D3130(&a, n1, (Pair_803C8678 *)&a, (Pair_803C8678 *)&b);
    s->vt->write(s, 1, &a);
    s->vt->unlock(s, 0, &b);
    total = total - n1;
    s->vt->lock(s, 0, total, &a);
    n2 = blk * (a.size / blk);
    memset(a.ptr, 0, n2);
    TLobby__sub_803D3130(&a, n2, (Pair_803C8678 *)&a, (Pair_803C8678 *)&b);
    s->vt->write(s, 1, &a);
    s->vt->unlock(s, 0, &b);
    return ((n1 + n2) / blk) * 32;
}

s32 TLobby::check_packet_header_8001(u16 *p, s32 size, s32 *out) {
    if (size < 2) {
        return 0;
    }
    if (*p != 0x8001) {
        return 0;
    }
    *out = size;
    return 1;
}
s32 adx_get_data_start_offset(u16 *arg0, s32 arg1, s32 *arg2) {
    s32 a7;
    s32 a8;
    s32 a9;
    s16 len;
    u8 b3;
    s8 b4;
    s8 b5;
    u8 b6;
    if (arg1 < 2) {
        return 0;
    }
    if (*arg0 != 0x8000) {
        return 0;
    }
    if (ARStartDMA((u8 *)arg0, arg1, &len, &b3, &b4, &b5, &b6, &a7, &a8, &a9) < 0) {
        return 0;
    }
    *arg2 = len;
    return 1;
}
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

struct Obj_803C96E0 { u8 pad[0x42]; s16 vals[1]; };

struct S_803C96F0 { u8 pad0[3]; s8 count; u8 pad4[8]; void *p; u8 pad10[0x32]; s16 vals[1]; };

struct VT_803CA0C8 { u8 pad[0x14]; void (*update)(void *self); };

struct Part_803CA0C8 { VT_803CA0C8 *vt; };

struct Stream_803CA0C8 {
    u8 f0;
    u8 active;
    u8 f2;
    s8 count;
    void *f4;
    void *f8;
    u8 padc[0x10 - 0xC];
    s32 f10;
    s32 f14;
    Part_803CA0C8 *parts[9];
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

struct VObj_803C9E38;
struct VT_803C9E38 {
    void *pad[3];
    void (*fc)(VObj_803C9E38 *);
    void *pad10;
    void (*f14)(VObj_803C9E38 *);
};

struct VObj_803C9E38 { VT_803C9E38 *vt; };

struct Obj_803C9E38 {
    u8 f0; s8 f1; u8 f2; s8 f3; void *f4; void *f8; s32 fc; u8 pad_10[4];
    VObj_803C9E38 *f14; VObj_803C9E38 *objs[13]; s32 f4c; u8 pad_50[0x94 - 0x50];
    s32 f94; s8 f98; u8 pad_99[3]; s32 f9c; s32 fa0;
};

struct VObj_803CA194;
typedef void (*RecoveredCallback_2be3cacebb2e)(void);
struct VT_803CA194 {
    void *pad[3];
    void (*fc)(VObj_803CA194 *);
    void *pad10;
    void (*f14)(VObj_803CA194 *);
};

struct VObj_803CA194 { VT_803CA194 *vt; };

struct Obj_803CA194 {
    u8 f0; s8 f1; u8 f2; s8 f3; void *f4; void *f8; void *fc; VObj_803CA194 *f10;
    VObj_803CA194 *f14; VObj_803CA194 *objs[23]; void *f74; VObj_803CA194 *objs2[2]; VObj_803CA194 *objs3[4]; u8 pad_90[4];
    void *f94; s8 f98; u8 pad_99[3]; s32 f9c; s32 fa0;
};

struct Obj_803CA194;
struct Ch_803CA3C4 {
    s8 state;
    u8 f1, f2;
    s8 n;
    void *f4;
    void *f8;
    void *fc;
    void *f10;
    s32 f14;
    void *f18[2];
    s32 f20;
    s32 f24;
    s32 f28;
    s32 f2c;
    s32 f30;
    s32 f34;
    s32 f38;
    s16 f3c;
    s16 f3e;
    s16 f40;
    s16 f42[8];
    u8 pad52[2];
    s32 f54;
    s32 f58;
    s32 f5c;
    s16 f60;
    u8 pad62[2];
    s32 f64;
    s16 f68;
    s16 f6a;
    s8 f6c;
    s8 f6d;
    u8 pad6e[4];
    s8 f72;
    u8 pad73[0x88 - 0x73];
    s32 f88;
    u8 pad8c[0x94 - 0x8C];
    void *f94;
    s8 f98;
    u8 pad99[0xA8 - 0x99];
};

extern "C" {
extern const u32 lbl_805E0D58[1];

extern s32 lbl_805D7540;
}
extern const u32 lbl_805E0D5C[1];
extern const u32 lbl_805E0D60[1];
extern const u32 lbl_805E0D64[1];
#define lbl_805E0D58 (*(const f32 *)lbl_805E0D58)
#define lbl_805E0D5C (*(const f32 *)lbl_805E0D5C)
#define lbl_805E0D60 (*(const f32 *)lbl_805E0D60)
#define lbl_805E0D64 (*(const f32 *)lbl_805E0D64)

extern "C" {
s32 TLobby__sub_803CC030(int, int);
s32 dispatch_packet__6TLobbyFv(int, int);
s8 TLobby__sub_803C9CB0(u8 *arg0);
void TLobby__sub_803C0758(u8 *arg0);
void configure_audio_stream_output(Stream_803C9FCC *self);
s16 TLobby__sub_803C96E0(Obj_803C96E0 *self, s32 i);
s32 TLobby__sub_803CBF50(void *);
extern u8 adx_out_pan_parameter_error[];
void GXFlush(void);
void TLobby__sub_803CA8B4(Ent_803C9608 *);
extern Ent_803C9608 adx_stream_player_pool[16];
extern s32 lbl_805D7564;

void TLobby__sub_803C97F4(u8 *arg0, s32 *pos, s32 *rate);
s32 TLobby__sub_803CBF10(int);
extern s32 lbl_805D7560;
extern s32 lbl_805D7570;
s32 TLobby__sub_803C9358(u8 *arg0);
void TLobby__sub_803C94DC(u8 *arg0, s32 arg1);
void TLobby__sub_803C9E38(Obj_803C9E38 *arg0, VObj_803C9E38 *arg1);
extern RecoveredCallback_2be3cacebb2e lbl_805D7574;
void TLobby__sub_803CA194(Obj_803CA194 *arg0);
void *TLobby__sub_803C0848(void *, s32, void *);
void *run_step_5210__6TLobbyFv(void *, s32);
Ch_803CA3C4 *adx_create_stream_player(s32 n, s32 base, s32 size);
void TLobby__sub_803C9350(u8 *arg0, s32 arg1);
void TLobby__sub_803C94B8(void);
void TLobby__sub_803C94D8(void);
void TLobby__sub_803C96A8(u8 *arg0, s32 arg1);
s16 TLobby__sub_803C96B0(u8 *arg0);
s32 TLobby__sub_803C9740(u8 *arg0);
s32 TLobby__sub_803C97B8(u8 *arg0);
s32 notify_field_4__6TLobbyFv(int);
s32 send_packet_by_id__6TLobbyFv(int);
s32 send_with_offset4__6TLobbyFv(int);
s32 set_params__6TLobbyFll();
s32 trigger_sub_task__6TLobbyFv(int);

void TLobby::set_field98(s8 arg1) {
    *(s8 *)((s8 *)((u8 *)this) + 0x98) = arg1;
}

void TLobby__sub_803C9350(u8 *arg0, s32 arg1) {
    *(s32 *)((s8 *)arg0 + 0x88) = arg1;
}

inline void inl_803C9608(void) {
    s32 i;
    if (lbl_805D7564 == 0) {
        TLobby::init_once();
        lbl_805D7564 = 1;
        GXFlush();
        lbl_805D7564 = 2;
        for (i = 0; i < 16; i++) {
            if (adx_stream_player_pool[i].state == 1) {
                TLobby__sub_803CA8B4(&adx_stream_player_pool[i]);
            }
        }
        lbl_805D7564 = 3;
        TLobby::run_sequence();
        lbl_805D7564 = 0;
        TLobby::release_ref();
    }
}
s32 TLobby__sub_803C9358(u8 *arg0) {
    s32 ret;
    s32 save;
    s32 spC;
    s32 sp8;
    if (*(s8 *)((s8 *)arg0 + 0x72) == 0) {
        return 0;
    }
    ret = TLobby__sub_803CBF10(*(s32 *)((s8 *)arg0 + 0xC));
    inl_803C9608();
    save = lbl_805D7560;
    lbl_805D7560 = 0;
    TLobby__sub_803C97F4(arg0, &spC, &sp8);
    lbl_805D7560 = save;
    *(s32 *)((s8 *)arg0 + 0x9C) = (s32)((f32)lbl_805D7570 * ((f32)spC / (f32)sp8));
    *(s32 *)((s8 *)arg0 + 0xA0) = lbl_805D7540;
    return ret;
}

void TLobby__sub_803C94B8(void) {
    set_params__6TLobbyFll();
}

void TLobby__sub_803C94D8(void) {

}

void TLobby__sub_803C94DC(u8 *arg0, s32 arg1) {
    s32 spC;
    s32 sp8;
    s32 st;
    s32 save;
    st = *(s8 *)((s8 *)arg0 + 1);
    if (arg1 != *(s8 *)((s8 *)arg0 + 0x72)) {
        TLobby::init_once();
        *(s8 *)((s8 *)arg0 + 0x72) = arg1;
        if (st == 3 || st == 4) {
            if (arg1 == 1) {
                TLobby__sub_803CC030(*(s32 *)((s8 *)arg0 + 0xC), 0);
            } else {
                TLobby__sub_803CC030(*(s32 *)((s8 *)arg0 + 0xC), 1);
                *(s32 *)((s8 *)arg0 + 0xA0) = lbl_805D7540;
            }
            save = lbl_805D7560;
            lbl_805D7560 = 0;
            TLobby__sub_803C97F4(arg0, &spC, &sp8);
            lbl_805D7560 = save;
            *(s32 *)((s8 *)arg0 + 0x9C) = (s32)((f32)lbl_805D7570 * ((f32)spC / (f32)sp8));
        }
        TLobby::release_ref();
    }
}

s16 TLobby::get_field_60() {
    return *(s16 *)((s8 *)((u8 *)this) + 0x60);
}

void TLobby__sub_803C9608(void) {
    s32 i;
    if (lbl_805D7564 == 0) {
        TLobby::init_once();
        lbl_805D7564 = 1;
        GXFlush();
        lbl_805D7564 = 2;
        for (i = 0; i < 16; i++) {
            if (adx_stream_player_pool[i].state == 1) {
                TLobby__sub_803CA8B4(&adx_stream_player_pool[i]);
            }
        }
        lbl_805D7564 = 3;
        TLobby::run_sequence();
        lbl_805D7564 = 0;
        TLobby::release_ref();
    }
}

void TLobby::set_field_6d(s8 arg1) {
    *(s8 *)((s8 *)((u8 *)this) + 0x6D) = arg1;
}

void TLobby__sub_803C96A8(u8 *arg0, s32 arg1) {
    *(s32 *)((s8 *)arg0 + 0x38) = arg1;
}

s16 TLobby__sub_803C96B0(u8 *arg0) {
    return *(s16 *)((s8 *)arg0 + 0x40);
}

void TLobby::set_field_40_and_notify(s16 arg1) {
    *(s16 *)((s8 *)((u8 *)this) + 0x40) = arg1;
    trigger_sub_task__6TLobbyFv((int)this->m_next);
}

s16 TLobby__sub_803C96E0(Obj_803C96E0 *self, s32 i) {
    return self->vals[i];
}

void TLobby::adxt_set_out_pan(s32 arg1, s16 arg2) {
    S_803C96F0 *arg0 = (S_803C96F0 *)this;
    arg0->vals[arg1] = arg2;
    if (arg1 < arg0->count) {
        TLobby__sub_803CBF50(this->m_next);
        return;
    }
    TLobby::notify_error((const char *)adx_out_pan_parameter_error);
}

s32 TLobby__sub_803C9740(u8 *arg0) {
    if ((s8) *(u8 *)((s8 *)arg0 + 1) >= 2) {
        return send_with_offset4__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 4)));
    }
    return 0;
}

s32 TLobby::apply_if_v2() {
    if ((s8) *(u8 *)((s8 *)((u8 *)this) + 1) >= 2) {
        return notify_field_4__6TLobbyFv((int) (*(s32 *)&this->m_flags));
    }
    return 0;
}

s32 TLobby__sub_803C97B8(u8 *arg0) {
    if ((s8) *(u8 *)((s8 *)arg0 + 1) >= 2) {
        return send_packet_by_id__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 4)));
    }
    return 0;
}

struct Strm_803C97F4;

struct VT_803C97F4 {
    void *pad[9];
    s32 (*f24)(Strm_803C97F4 *, s32);
};

struct Strm_803C97F4 { VT_803C97F4 *vt; };

struct Adxt_803C97F4 {
    u8 pad_0[1];
    s8 f1;
    u8 pad_2[2];
    s32 f4;
    u8 pad_8[4];
    s32 fC;
    u8 pad_10[8];
    Strm_803C97F4 *f18;
    u8 pad_1c[0x72 - 0x1C];
    s8 f72;
    u8 pad_73[0x88 - 0x73];
    s32 f88;
    u8 pad_8c[0x9C - 0x8C];
    s32 f9C;
    s32 fA0;
    s32 fA4;
};

extern "C" {
s32 TLobby__sub_803C0010(u8 *arg0);
s32 send_packet_by_id_2__6TLobbyFv(int);
s32 query_available_size__6TLobbyFv(int);
extern f32 lbl_805D756C;
extern s32 lbl_805D7568;
extern u32 lbl_805D4678;
}

inline void get_play_position_803C97F4(Adxt_803C97F4 *p, s32 *pos, s32 *rate) {
    s32 st = p->f1;
    if (st == 3 || st == 4) {
        s32 total;
        *rate = notify_field_4__6TLobbyFv(p->f4);
        total = TLobby__sub_803C0010((u8 *)p->f4);
        *pos = p->fA4 + (total - (query_available_size__6TLobbyFv(p->fC) + (p->f18 != NULL ? p->f18->vt->f24(p->f18, 1) / 2 : 0)));
    } else if (st == 5) {
        *pos = send_packet_by_id__6TLobbyFv(p->f4);
        *rate = notify_field_4__6TLobbyFv(p->f4);
        *pos *= 16 / send_packet_by_id_2__6TLobbyFv(p->f4);
        *pos += p->fA4;
    } else {
        *pos = 0;
        *rate = 1;
    }
    *pos += p->f88;
}

void TLobby__sub_803C97F4(u8 *arg0, s32 *pos, s32 *rate) {
    Adxt_803C97F4 *p = (Adxt_803C97F4 *)arg0;
    s32 cur_pos;
    s32 cur_rate;
    s32 st;

    if (lbl_805D7560 == 0) {
        get_play_position_803C97F4(p, pos, rate);
        return;
    }
    lbl_805D756C = lbl_805E0D58;
    st = p->f1;
    if (st == 3 || st == 4) {
        if (p->f72 == 0) {
            *pos = p->f9C + (lbl_805D7540 - p->fA0) * 100;
        } else {
            *pos = p->f9C;
        }
        get_play_position_803C97F4(p, &cur_pos, &cur_rate);
        lbl_805D756C = lbl_805E0D5C * ((f32)cur_pos / (f32)cur_rate - (f32)*pos / (f32)lbl_805D7570);
        if (lbl_805D756C > lbl_805E0D60 || lbl_805D756C < lbl_805E0D64) {
            if (lbl_805D4678 == 1) {
                s32 save = lbl_805D7560;
                lbl_805D7560 = 0;
                TLobby__sub_803C97F4(arg0, &cur_pos, &cur_rate);
                lbl_805D7560 = save;
                lbl_805D7568++;
            }
            p->f9C = (u32)((f32)lbl_805D7570 * ((f32)cur_pos / (f32)cur_rate));
            p->fA0 = lbl_805D7540;
        }
    } else if (st == 5) {
        cur_pos = send_packet_by_id__6TLobbyFv(p->f4);
        cur_rate = notify_field_4__6TLobbyFv(p->f4);
        cur_pos *= 16 / send_packet_by_id_2__6TLobbyFv(p->f4);
        *pos = (s32)((f32)lbl_805D7570 * ((f32)cur_pos / (f32)cur_rate));
        *pos += p->f9C + 1;
    } else {
        *pos = 0;
    }
    *pos += p->f88;
    *rate = lbl_805D7570;
}

void TLobby::set_rate_mode(s32 arg0) {
    if (arg0 == 1) {
        lbl_805D7570 = 0x176A;
    } else if (arg0 == 2) {
        lbl_805D7570 = 0x1388;
    }
    lbl_805D7560 = arg0;
}

s8 TLobby__sub_803C9CB0(u8 *arg0) {
  u8 new_var2;
  u8 new_var;
  new_var = (((((((*((u8 *) (((s8 *) arg0) + 1))) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu) & 0xFFFFFFFFFFFFFFFFu;
  new_var2 = new_var;
  return (s8) new_var2;
}
}
void stop_audio_stream(u8 *arg0);
#pragma push
#pragma fp_contract on
void stop_audio_stream(u8 *arg0) {
    void **temp_r3;
    void **temp_r3_2;
    void **temp_r3_3;
    u8 *temp_r4;
    u8 *temp_r4_2;
    u8 *temp_r4_3;
    if (*(void **)((s8 *)arg0 + 8) != NULL) {
        TLobby__sub_803C89C4((u8 *)(*(void **)((s8 *)arg0 + 8)));
        TLobby__sub_803C8B38((u8 *)((int) (*(u32 *)((s8 *)arg0 + 8))));
        temp_r3 = *(void ***)((s8 *)arg0 + 0x14);
        if (temp_r3 != NULL) {
            temp_r4 = (u8 *)(*temp_r3);
            (*(s32 (**)(void *, void *))((s8 *)temp_r4 + 0x14))(temp_r3, temp_r4);
        }
        *(u32 *)((s8 *)arg0 + 8) = 0U;
    }
    TLobby::init_once();
    if ((s32) *(u8 *)((s8 *)arg0 + 2) == 4) {
        lsc_stop((LscStream*) (*(s32 *)((s8 *)arg0 + 0x94)));
        temp_r3_2 = *(void ***)((s8 *)arg0 + 0x14);
        if (temp_r3_2 != NULL) {
            temp_r4_2 = (u8 *)(*temp_r3_2);
            (*(s32 (**)(void *, void *))((s8 *)temp_r4_2 + 0x14))(temp_r3_2, temp_r4_2);
        }
    }
    TLobby::init_once();
    dispatch_packet__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 0xC)), 0);
    TLobby__sub_803CC030((int) (*(s32 *)((s8 *)arg0 + 0xC)), 0);
    ((TLobby *)(*(s32 *)((s8 *)arg0 + 4)))->reset_flag();
    if ((s32) *(u8 *)((s8 *)arg0 + 2) == 2) {
        temp_r3_3 = *(void ***)((s8 *)arg0 + 0x14);
        if (temp_r3_3 != NULL) {
            temp_r4_3 = (u8 *)(*temp_r3_3);
            (*(s32 (**)(void *, void *))((s8 *)temp_r4_3 + 0xC))(temp_r3_3, temp_r4_3);
        }
    }
    *(void ***)((s8 *)arg0 + 0x14) = NULL;
    *(s8 *)((s8 *)arg0 + 1) = 0;
    TLobby::release_ref();
    TLobby::release_ref();
}
#pragma pop
extern "C" {

void TLobby__sub_803C9DB4(u8 *arg0) {
    void **temp_r3;
    TLobby::init_once();
    dispatch_packet__6TLobbyFv((int) (*(s32 *)((s8 *)arg0 + 0xC)), 0);
    TLobby__sub_803CC030((int) (*(s32 *)((s8 *)arg0 + 0xC)), 0);
    ((TLobby *)(*(s32 *)((s8 *)arg0 + 4)))->reset_flag();
    if ((s32) *(u8 *)((s8 *)arg0 + 2) == 2) {
        temp_r3 = *(void ***)((s8 *)arg0 + 0x14);
        if (temp_r3 != NULL) {
            (*(s32 (**)(void *))((s8 *)((unsigned char *) (*temp_r3)) + 0xC))(temp_r3);
        }
    }
    *(void ***)((s8 *)arg0 + 0x14) = NULL;
    *(s8 *)((s8 *)arg0 + 1) = 0;
    TLobby::release_ref();
}

void TLobby__sub_803C9E38(Obj_803C9E38 *arg0, VObj_803C9E38 *arg1) {
    s32 i;
    if (arg0->f8 != NULL) {
        TLobby__sub_803C89C4((u8 *)arg0->f8);
        TLobby__sub_803C8B38((u8 *)((int)arg0->f8));
        if (arg0->f14 != NULL) {
            arg0->f14->vt->f14(arg0->f14);
        }
        arg0->f8 = NULL;
    }
    TLobby::init_once();
    if ((s32)arg0->f2 == 4) {
        lsc_stop((LscStream*)arg0->f94);
        if (arg0->f14 != NULL) {
            arg0->f14->vt->f14(arg0->f14);
        }
    }
    TLobby::init_once();
    dispatch_packet__6TLobbyFv(arg0->fc, 0);
    TLobby__sub_803CC030(arg0->fc, 0);
    ((TLobby *)((int)arg0->f4))->reset_flag();
    if ((s32)arg0->f2 == 2) {
        if (arg0->f14 != NULL) {
            arg0->f14->vt->fc(arg0->f14);
        }
    }
    arg0->f14 = NULL;
    arg0->f1 = 0;
    TLobby::release_ref();
    TLobby::release_ref();
    TLobby::init_once();
    for (i = 0; i < arg0->f3; i++) {
        arg0->objs[i]->vt->f14(arg0->objs[i]);
    }
    ((TLobby *)(arg0->f4))->set_param_and_notify((int)arg1);
    arg0->f14 = arg1;
    TLobby__sub_803C0758((u8 *)arg0->f4);
    arg0->f1 = 1;
    arg0->f2 = 3;
    arg0->f4c = 0;
    arg0->f98 = 1;
    arg0->f9c = 0;
    arg0->fa0 = lbl_805D7540;
    TLobby::release_ref();
}

void configure_audio_stream_output(Stream_803C9FCC *self) {
    s32 i;
    s32 v;
    Stream_803C9FCC *pp;
    set_range__6TLobbyFPvii((u8 *)self->f8, self->f3e << 11, self->f3c << 11);
    ((TLobby *)(self->f8))->set_scroll_position(0x19);
    ((TLobby *)(self->f8))->init_stream_position();
    v = self->f10;
    pp = self;
    for (i = 0; i < self->count; i++) {
        pp->parts[0]->vt->update(pp->parts[0]);
        pp = (Stream_803C9FCC *)((u8 *)pp + 4);
    }
    ((TLobby *)(self->f4))->set_param_and_notify(v);
    self->f14 = v;
    TLobby__sub_803C0758((u8 *)self->f4);
    self->active = 1;
    self->f4c = 0;
    self->f71 = 0;
    self->f8c = 0x7FFFFFFF;
    self->f90 = -1;
    self->f9c = 0;
    self->fa4 = 0;
    self->fa0 = lbl_805D7540;
    self->f2 = 0;
}

struct Stream_803C9FCC;

void TLobby::start_stream_playback(s32 arg1) {
    s32 i;
    for (i = 0; i < ((Stream_803CA0C8 *)this)->count; i++) {
        ((Stream_803CA0C8 *)this)->parts[i]->vt->update(((Stream_803CA0C8 *)this)->parts[i]);
    }
    ((TLobby *)(((Stream_803CA0C8 *)this)->f4))->set_param_and_notify(arg1);
    ((Stream_803CA0C8 *)this)->f14 = arg1;
    TLobby__sub_803C0758((u8 *)(((Stream_803CA0C8 *)this)->f4));
    ((Stream_803CA0C8 *)this)->active = 1;
    ((Stream_803CA0C8 *)this)->f4c = 0;
    ((Stream_803CA0C8 *)this)->f71 = 0;
    ((Stream_803CA0C8 *)this)->f8c = 0x7FFFFFFF;
    ((Stream_803CA0C8 *)this)->f90 = -1;
    ((Stream_803CA0C8 *)this)->f9c = 0;
    ((Stream_803CA0C8 *)this)->fa4 = 0;
    ((Stream_803CA0C8 *)this)->fa0 = lbl_805D7540;
}

void TLobby__sub_803CA194(Obj_803CA194 *arg0) {
    s32 i;
    if (arg0 == NULL) {
        return;
    }
    if (lbl_805D7574 != NULL) {
        lbl_805D7574();
    }
    if ((s32)arg0->f0 == 1) {
        if (arg0->f8 != NULL) {
            TLobby__sub_803C89C4((u8 *)arg0->f8);
            TLobby__sub_803C8B38((u8 *)((int)arg0->f8));
            if (arg0->f14 != NULL) {
                arg0->f14->vt->f14(arg0->f14);
            }
            arg0->f8 = NULL;
        }
        TLobby::init_once();
        if ((s32)arg0->f2 == 4) {
            lsc_stop((LscStream*)arg0->f94);
            if (arg0->f14 != NULL) {
                arg0->f14->vt->f14(arg0->f14);
            }
        }
        TLobby::init_once();
        dispatch_packet__6TLobbyFv((int)arg0->fc, 0);
        TLobby__sub_803CC030((int)arg0->fc, 0);
        ((TLobby *)((int)arg0->f4))->reset_flag();
        if ((s32)arg0->f2 == 2) {
            if (arg0->f14 != NULL) {
                arg0->f14->vt->fc(arg0->f14);
            }
        }
        arg0->f14 = NULL;
        arg0->f1 = 0;
        TLobby::release_ref();
        TLobby::release_ref();
    }
    if (arg0->fc != NULL) {
        ((TLobby *)(arg0->fc))->unregister_si_polling();
    }
    if (arg0->f4 != NULL) {
        ((TLobby *)(arg0->f4))->reset_entry();
    }
    if (arg0->f8 != NULL) {
        TLobby__sub_803C8B38((u8 *)((int)arg0->f8));
    }
    if (arg0->f94 != NULL) {
        lsc_destroy((LscStream*)arg0->f94);
    }
    TLobby::init_once();
    if (arg0->f10 != NULL) {
        arg0->f10->vt->fc(arg0->f10);
    }
    for (i = 0; i < arg0->f3; i++) {
        if (arg0->objs[i] != NULL) {
            arg0->objs[i]->vt->fc(arg0->objs[i]);
        }
        if (arg0->objs2[i] != NULL) {
            arg0->objs2[i]->vt->fc(arg0->objs2[i]);
        }
        if (arg0->objs3[i] != NULL) {
            arg0->objs3[i]->vt->fc(arg0->objs3[i]);
        }
    }
    if (arg0->f74 != NULL) {
        ((TLobby *)(arg0->f74))->clear_entry();
    }
    memset(arg0, 0, 0xA8);
    arg0->f0 = 0;
    TLobby::release_ref();
}

#undef lbl_805E0D58
#undef lbl_805E0D5C
#undef lbl_805E0D60
#undef lbl_805E0D64
__declspec(section ".sdata2") extern const u32 lbl_805E0D58[1] = { 0x00000000 };
__declspec(section ".sdata2") extern const u32 lbl_805E0D5C[1] = { 0x447a0000 };
__declspec(section ".sdata2") extern const u32 lbl_805E0D60[1] = { 0x42700000 };
__declspec(section ".sdata2") extern const u32 lbl_805E0D64[1] = { 0xc2700000 };
#define lbl_805E0D58 (*(const f32 *)lbl_805E0D58)
#define lbl_805E0D5C (*(const f32 *)lbl_805E0D5C)
#define lbl_805E0D60 (*(const f32 *)lbl_805E0D60)
#define lbl_805E0D64 (*(const f32 *)lbl_805E0D64)

Ch_803CA3C4 *adx_create_stream_player(s32 n, s32 base, s32 size) {
    Ch_803CA3C4 *c;
    s32 aligned = (base + 0x3F) & ~0x3F;
    s32 rem = size - (aligned - base);
    s32 i;
    s32 t;
    for (i = 0; i < 16; i++) {
        if (adx_stream_player_pool[i].state == 0) {
            break;
        }
    }
    if (i == 16) {
        return NULL;
    }
    c = (Ch_803CA3C4 *)&adx_stream_player_pool[i];
    memset(c, 0, 0xA8);
    c->n = n;
    t = (n * 0x2060) << 1;
    c->f20 = aligned + t;
    c->f24 = (rem - t - 0x24) / 2048 * 2048;
    c->f28 = 0x24;
    c->f2c = aligned;
    c->f30 = 0x2000;
    c->f34 = 0x2060;
    c->f14 = 0;
    c->f10 = sj_ring_buffer_create((void *)c->f20, c->f24, c->f28);
    if (c->f10 == NULL) {
        TLobby__sub_803CA194((Obj_803CA194 *)c);
        return NULL;
    }
    for (i = 0; i < n; i++) {
        c->f18[i] = sj_ring_buffer_create((void *)(c->f2c + c->f34 * i * 2), c->f30 * 2, (c->f34 - c->f30) * 2);
        if (c->f18[i] == NULL) {
            TLobby__sub_803CA194((Obj_803CA194 *)c);
            return NULL;
        }
    }
    if ((c->f4 = TLobby__sub_803C0848(c->f10, n, c->f18)) == NULL) {
        TLobby__sub_803CA194((Obj_803CA194 *)c);
        return NULL;
    }
    if ((c->fc = run_step_5210__6TLobbyFv(c->f18, n)) == NULL) {
        TLobby__sub_803CA194((Obj_803CA194 *)c);
        return NULL;
    }
    if ((c->f94 = lsc_create(c->f10)) == NULL) {
        TLobby__sub_803CA194((Obj_803CA194 *)c);
        return NULL;
    }
    c->f38 = 0x3C;
    c->f3c = c->f24 / 2048;
    c->f3e = 0.85 * c->f3c;
    c->f40 = 0;
    for (i = 0; i < n; i++) {
        c->f42[i] = -0x80;
    }
    c->f6c = 1;
    c->f54 = 0;
    c->f58 = 0;
    c->f5c = 0;
    c->f60 = 0;
    c->f64 = 0;
    c->f68 = 0;
    c->f6a = 0;
    c->f6d = 1;
    c->f72 = 0;
    c->f88 = 0;
    c->f98 = 1;
    c->state = 1;
    return c;
}

s32 send_packet_by_id_2__6TLobbyFv(int);

extern "C" {

s32 TLobby__sub_803C0010(u8 *arg0);

}

}
