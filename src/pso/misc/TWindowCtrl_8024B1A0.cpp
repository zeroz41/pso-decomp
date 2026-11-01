#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowCtrl_8024B1A0.h"
#include "pso/misc/TWindowFukidasi.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/misc/TUnk_804CF0B8.h"
struct Ctrl_8024B1A0 { u8 pad[0x1C]; u16 flags; };

struct Win_8024B1A0 { u8 pad[0x40]; f32 x; f32 y; f32 w; f32 h; };

struct Msg_8024B1A0 { f32 x; f32 y; };

extern "C" {
s32 get_flag_bit1__13TUnk_804CF0B8Fv();
extern Ctrl_8024B1A0 *TWindowCtrl__active_window;
extern const f32 lbl_805DCBE0;
extern const f32 lbl_805DCBE4;
#pragma push
#pragma fp_contract on
s8 TUnk_804CF0B8::alloc_nearest_free_slot() {
    s32 i;
    s32 mask;
    s8 best;
    f32 cx;
    f32 cy;
    f32 bestd;
    Msg_8024B1A0 *m;
    f32 dx;
    f32 dy;
    f32 d;
    if (TWindowCtrl__active_window == NULL) {
        return 0;
    }
    if (get_flag_bit1__13TUnk_804CF0B8Fv() != 0) {
        TWindowCtrl__active_window->flags |= 0x200;
        return 3;
    }
    mask = 0x40;
    best = -1;
    i = 0;
    cx = (lbl_805DCBE4 * ((Win_8024B1A0 *)this)->w) + ((Win_8024B1A0 *)this)->x;
    bestd = lbl_805DCBE0;
    cy = (lbl_805DCBE4 * ((Win_8024B1A0 *)this)->h) + ((Win_8024B1A0 *)this)->y;
    do {
        if (!(TWindowCtrl__active_window->flags & mask)) {
            m = (Msg_8024B1A0 *)TWindowCtrl::get_message_by_type((s8)i, get_field_20());
            if (m != NULL) {
                dx = cx - m->x;
                dy = cy - m->y;
                d = (dx * dx) + (dy * dy);
                if (!(bestd <= d)) {
                    best = (s8)i;
                    bestd = d;
                }
            }
        }
        i++;
        mask <<= 1;
    } while (i < 3);
    if (best == -1) {
        best = 3;
    }
    TWindowCtrl__active_window->flags |= (0x40 << best);
    return best;
}
#pragma pop

void TWindowCtrl::set_field28(s16 arg0) {
    if ((void *) (*(void * *)&TWindowCtrl__active_window) != NULL) {
        *(s16 *)((s8 *)(*(void * *)&TWindowCtrl__active_window) + 0x28) = arg0;
    }
}
u16 TWindowCtrl::get_window_id() {
    if ((void *) (*(void * *)&TWindowCtrl__active_window) == NULL) {
        return 0xFFFFU;
    }
    return *(u16 *)((s8 *)(*(void * *)&TWindowCtrl__active_window) + 0x28);
}

}

#include "pso/TObject.h"

struct Ctrl_8024B328 { u8 pad[0x84]; void *win[4]; };

struct Ctrl_8024B3B4 { u8 pad[0x84]; void *win[4]; };

struct Ctrl_8024B440 { u8 pad[0x84]; void *win[4]; };

extern "C" {
s32 acquire_balloon_slot__11TWindowCtrlFPviiPv(s32, u16, s32, s32);

void TWindowCtrl::close_windows_by_flags(u16 arg0) {
    u32 i;
    void *w;
    if ((*(u32 *)&TWindowCtrl__active_window) != 0) {
        for (i = 0; i < 4; i++) {
            w = ((Ctrl_8024B328 *)(*(u32 *)&TWindowCtrl__active_window))->win[i];
            if (w != NULL && ((TObject *)w)->all_parents_unqueued_for_destruction() != 0 && arg0 == ((TWindowCtrl *)w)->get_flags()) {
                ((TWindowBase *)w)->close();
            }
        }
    }
}

void complete_actor_speech_balloons(u16 arg0) {
    u32 i;
    void *w;
    if ((*(u32 *)&TWindowCtrl__active_window) != 0) {
        for (i = 0; i < 4; i++) {
            w = ((Ctrl_8024B3B4 *)(*(u32 *)&TWindowCtrl__active_window))->win[i];
            if (w != NULL && ((TObject *)w)->all_parents_unqueued_for_destruction() != 0 && arg0 == ((TWindowCtrl *)w)->get_flags()) {
                complete_speech_balloon((u8 *)w);
            }
        }
    }
}

s32 is_actor_speech_balloon_done(u16 arg0) {
    u32 i;
    void *w;
    if ((*(u32 *)&TWindowCtrl__active_window) == 0) {
        return 1;
    }
    for (i = 0; i < 4; i++) {
        w = ((Ctrl_8024B440 *)(*(u32 *)&TWindowCtrl__active_window))->win[i];
        if (w != NULL && ((TObject *)w)->all_parents_unqueued_for_destruction() != 0 && arg0 == ((TWindowCtrl *)w)->get_flags() && is_speech_balloon_ready((u8 *)w) == 0) {
            return 0;
        }
    }
    return 1;
}

s32 TWindowCtrl::open_balloon(u16 arg0, u8 *arg1, s32 arg2, s32 arg3) {
    s32 temp_r3;
    if ((u32) (*(u32 *)&TWindowCtrl__active_window) == 0U) {
        return 0;
    }
    temp_r3 = acquire_balloon_slot__11TWindowCtrlFPviiPv((s32) (*(u32 *)&TWindowCtrl__active_window), arg0, arg2, arg3);
    if (temp_r3 == 0) {
        return 0;
    }
    open__15TWindowFukidasiFPvPvi((u8 *)temp_r3, (u32 *)arg1, arg2);
    return temp_r3;
}

}
