#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowCtrl_8024B1A0.h"
#include "pso/ui/window/TWindowFukidasi.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/system/NinjaTypes.h"
struct Ctrl_8024B1A0 { u8 pad[0x1C]; u16 flags; };

struct Win_8024B1A0 { u8 pad[0x40]; f32 x; f32 y; f32 w; f32 h; };

extern "C" {
extern const f32 lbl_805DCBE0;
extern const f32 lbl_805DCBE4;
#pragma push
#pragma fp_contract on
s8 TWindowFukidasi::alloc_nearest_free_slot() {
    s32 i;
    s32 mask;
    s8 best;
    f32 cx;
    f32 cy;
    f32 bestd;
    NJS_POINT2 *m;
    f32 dx;
    f32 dy;
    f32 d;
    if (TWindowCtrl::instance == NULL) {
        return 0;
    }
    if (get_flag_bit1() != 0) {
        TWindowCtrl::instance->flags |= 0x200;
        return 3;
    }
    mask = 0x40;
    best = -1;
    i = 0;
    cx = (lbl_805DCBE4 * ((Win_8024B1A0 *)this)->w) + ((Win_8024B1A0 *)this)->x;
    bestd = lbl_805DCBE0;
    cy = (lbl_805DCBE4 * ((Win_8024B1A0 *)this)->h) + ((Win_8024B1A0 *)this)->y;
    do {
        if (!(TWindowCtrl::instance->flags & mask)) {
            m = (NJS_POINT2 *)TWindowCtrl::get_message_by_type((s8)i, get_field_20());
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
    TWindowCtrl::instance->flags |= (0x40 << best);
    return best;
}
#pragma pop

void TWindowCtrl::set_field28(u16 arg0) {
    if (instance != NULL) {
        instance->window_id = arg0;
    }
}
u16 TWindowCtrl::get_window_id() {
    if (instance == NULL) {
        return 0xFFFFU;
    }
    return instance->window_id;
}

}

#include "pso/system/task/TObject.h"

struct Ctrl_8024B328 { u8 pad[0x84]; void *win[4]; };

struct Ctrl_8024B3B4 { u8 pad[0x84]; void *win[4]; };

struct Ctrl_8024B440 { u8 pad[0x84]; void *win[4]; };


void TWindowCtrl::close_windows_by_flags(u16 arg0) {
    u32 i;
    void *w;
    if (instance != NULL) {
        for (i = 0; i < 4; i++) {
            w = ((Ctrl_8024B328 *)instance)->win[i];
            if (w != NULL && ((TObject *)w)->all_parents_unqueued_for_destruction() != 0 && arg0 == reinterpret_cast<TWindowFukidasi *>(w)->get_speaker_id()) {
                ((TWindowBase *)w)->close();
            }
        }
    }
}

void complete_actor_speech_balloons(u16 id) {
    u32 i;
    void *w;
    if (TWindowCtrl::instance != NULL) {
        for (i = 0; i < 4; i++) {
            w = ((Ctrl_8024B3B4 *)TWindowCtrl::instance)->win[i];
            if (w != NULL && ((TObject *)w)->all_parents_unqueued_for_destruction() != 0 && id == reinterpret_cast<TWindowFukidasi *>(w)->get_speaker_id()) {
                complete_speech_balloon((u8 *)w);
            }
        }
    }
}

s32 is_actor_speech_balloon_done(u16 id) {
    u32 i;
    void *w;
    if (TWindowCtrl::instance == NULL) {
        return 1;
    }
    for (i = 0; i < 4; i++) {
        w = ((Ctrl_8024B440 *)TWindowCtrl::instance)->win[i];
        if (w != NULL && ((TObject *)w)->all_parents_unqueued_for_destruction() != 0 && id == reinterpret_cast<TWindowFukidasi *>(w)->get_speaker_id() && is_speech_balloon_ready((u8 *)w) == 0) {
            return 0;
        }
    }
    return 1;
}

s32 TWindowCtrl::open_balloon(u16 player, u8 *arg1, s32 flags, s32 arg3) {
    saddr temp_r3;
    if (instance == 0U) {
        return 0;
    }
    temp_r3 = reinterpret_cast<saddr>(instance->acquire_balloon_slot(player, flags, arg3));
    if (temp_r3 == 0) {
        return 0;
    }
    open__15TWindowFukidasiFPvPvi((u8 *)temp_r3, (u32 *)arg1, flags);
    return temp_r3;
}
