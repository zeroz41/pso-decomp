#include "types.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/misc/TWindowSubStatusDisp_8026F6DC.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSimpleStatus.h"
#include "pso/misc/TWindowDD.h"
#include "pso/misc/TWindowSubComCard.h"

struct SS_802705D8 { u8 pad0[0x18]; void *vt; u8 pad1c[0x64 - 0x1c]; void *w[4]; };

struct SS_80270668 { s32 f0; u8 pad4[0x14]; void *vt; s16 f1c; s16 f1e; s16 f20; u8 pad22[0x36]; f32 f58; u8 pad5c[4]; s32 f60; s32 w[5]; };

extern "C" {
s32 draw_default_entry__9TWindowDDFl();
s32 draw_visible_window_entries(void *, void *, int);
void __dl__7TObjectFPv(void *);
extern u8 __vt__19TWindowSimpleStatus[];
u8 *__dt__19TWindowSimpleStatusFv(SS_802705D8 *arg0, s16 arg1);
extern s32 TWindowSimpleStatus__name;
extern const f32 lbl_805DD3EC;
SS_80270668 *TWindowSimpleStatus__ct(SS_80270668 *arg0, void *arg1, s32 arg2, void *arg3);
s32 get_window_layout_position(s32);
void *__nw__7TObjectFUl(int);
s32 update_hp_tp_level__20TWindowSubStatusDispFv();

void render__19TWindowSimpleStatusFv(s32 arg0) {
    s32 ctx;
    ctx = draw_default_entry__9TWindowDDFl();
    ((TWindowSimpleStatus *)arg0)->draw_background((u8 *)ctx);
    draw_visible_window_entries((void *)arg0, (void *)(arg0 + 0x24), (int)ctx);
}

void TWindowSimpleStatus::run_task() {
    s32 arg0 = (s32)this;
    update_hp_tp_level__20TWindowSubStatusDispFv();
    update_lockon_window((u8 *)arg0);
    update_status_help_item(arg0);
    ((TWindowSimpleStatus *)arg0)->update_status_icons((void *)(get_window_layout_position(0x1D)));
    ((TWindowDD *)arg0)->initialize_subwindow();
    ((TWindowBase *)arg0)->update_fade();
    ((TWindowBase *)arg0)->update_window_entry_list((void *)(arg0 + 0x24));
    ((TWindowSimpleStatus *)arg0)->apply_random_shake();
}

extern unsigned char simple_status_window_layout[];

u8 *__dt__19TWindowSimpleStatusFv(SS_802705D8 *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        arg0->vt = __vt__19TWindowSimpleStatus;
        for (i = 0; i < 4; i++) {
            if (arg0->w[i] != NULL) {
                ((TWindowBase *)(arg0->w[i]))->close();
                arg0->w[i] = NULL;
            }
        }
        ((TWindowDD *)arg0)->destroy_window_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return (u8 *)arg0;
}

SS_80270668 *TWindowSimpleStatus__ct(SS_80270668 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 i;
    ((TWindowDD *)arg0)->construct_base((u8 *)arg3, (s16)arg2, (u8 *)arg1);
    arg0->vt = __vt__19TWindowSimpleStatus;
    arg0->f0 = TWindowSimpleStatus__name;
    arg0->f20 = arg2;
    arg0->f60 = 0;
    arg0->f58 = lbl_805DD3EC;
    for (i = 0; i < 5; i++) {
        arg0->w[i] = 0;
    }
    return arg0;
}

void *TWindowSimpleStatus::create(void *arg1) {
    void *o;
    o = __nw__7TObjectFUl(0x78);
    if (o != NULL) {
        o = TWindowSimpleStatus__ct((SS_80270668 *)(o), (void *)this, (s32)arg1, (void *)simple_status_window_layout);
    }
    return o;
}

}
