#include "types.h"
#include "pso/ui/TAdPlyPltAnimGC.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"

#include "pso/ui/TAdPlyPltAnimCtrlGC.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"

struct V2_80355D5C { f32 x, y; };
struct Obj_80355D5C { u8 pad0[0x3C]; f32 a, b, c, d; u8 pad4C[0x10]; f32 e, f; };
struct Pos_80355DE0 { f32 x, y; };
struct Anim_80355DE0 {
    u8 pad0[0x1C];
    f32 x1c, x20, x24, x28;
    u8 pad2c[0x3C - 0x2C];
    f32 x3c, x40, x44, x48;
    u8 pad4c[0x5C - 0x4C];
    f32 x5c, x60, x64, x68;
    u8 x6c;
    u8 pad6d[3];
    s32 idx;
    s32 active;
    s32 time;
};
struct TAdPlyPltAnimGC_8035601C {
    s32 x0;
    u8 pad4[0x14];
    void **vt;
    u8 pad1c[0x10];
    f32 x2c;
    f32 x30;
    f32 x34;
    f32 x38;
    u8 pad3c[0x30];
    u8 x6c;
    u8 pad6d[3];
    s32 x70;
    s32 x74;
    s32 x78;
};
struct RecoveredGlobal_803560F0_lbl_804F142C {
    s32 value;
    u8 remaining[0x10];
};

extern "C" {
extern s32 player_prate_texture_list_ptr;
extern const f32 lbl_805DFFC8;
extern const f32 lbl_805DFFCC;
extern const V2_80355D5C lbl_80479350[];
extern const f32 lbl_805DFFD0;
void start_anim_rect__19TAdPlyPltAnimCtrlGCFPvPv(Obj_80355D5C *o, V2_80355D5C *p);
extern Pos_80355DE0 ply_plt_anim_target_position_table[];
extern u32 ply_plt_anim_duration_table[];
extern const f32 lbl_805DFFD4;
extern const f32 lbl_805DFFD8;
extern RecoveredGlobal_803560F0_lbl_804F142C TAdPlyPltAnimGC__instances;
extern void *__vt__15TAdPlyPltAnimGC[];
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 lbl_805D43A0;
extern const f32 lbl_805DFFDC;
extern const f32 lbl_805DFFE0;
s32 __nw__7TObjectFUl(int);
void release_texture_list(void*);

#pragma push
#pragma fp_contract on
void TAdPlyPltAnimGC::render() {
    u8 *arg0 = (u8 *)this;
    if (((s32) *(s32 *)((s8 *)arg0 + 0x74) != 0) && (TMainTask::get_render_pass() != 1)) {
        set_additive_blend();
        begin_screen_draw(1);
        TObjFish::set_global_param(player_prate_texture_list_ptr);
        set_draw_texture_and_color(0, (*(u8 *)((s8 *)arg0 + 0x6C) << 0x18) | 0xFF0000 | 0xFFFF);
        draw_textured_quad_at_depth((f32 *)(arg0 + 0x1C), (lbl_805DFFCC * (f32) *(s32 *)((s8 *)arg0 + 0x70)) + lbl_805DFFC8);
        TWindowSubStatusDisp::get_player();
        set_default_alpha_blend();
    }
}
#pragma pop

void TAdPlyPltAnimCtrlGC::set_anim_state(s32 arg1) {
    if (arg1 == 0) {
        *(s32 *)((s8 *)this + 0x78) = -1;
    }
    *(s32 *)((s8 *)this + 0x74) = arg1;
}

void TAdPlyPltAnimCtrlGC__sub_80355D38(TAdPlyPltAnimCtrlGC *ad_ply_plt_anim_ctrl_gc) {
    ad_ply_plt_anim_ctrl_gc->set_anim_state(0);
}
#pragma push
#pragma fp_contract on
void start_anim_rect__19TAdPlyPltAnimCtrlGCFPvPv(Obj_80355D5C *o, V2_80355D5C *p) {
    o->a = p->x;
    o->b = p->y;
    o->c = p->x + lbl_80479350[0].x;
    o->d = p->y + lbl_80479350[0].y;
    o->e = lbl_805DFFD0 * (o->c - o->a) + o->a;
    o->f = lbl_805DFFD0 * (o->d - o->b) + o->b;
    ((TAdPlyPltAnimCtrlGC *)o)->set_anim_state(1);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TAdPlyPltAnimGC::run_task() {
    Anim_80355DE0 *o = (Anim_80355DE0 *)this;
    if (o->active != 0) {
        o->time++;
        if (o->time < ply_plt_anim_duration_table[o->idx] + 1) {
            f32 dx = (ply_plt_anim_target_position_table[o->idx].x - lbl_805DFFD4) / (f32)ply_plt_anim_duration_table[o->idx];
            f32 dy = (ply_plt_anim_target_position_table[o->idx].y - lbl_805DFFD4) / (f32)ply_plt_anim_duration_table[o->idx];
            o->x64 = ply_plt_anim_target_position_table[o->idx].x - dx * (f32)o->time;
            o->x68 = ply_plt_anim_target_position_table[o->idx].y - dy * (f32)o->time;
            f32 r = lbl_805DFFD4 / (f32)ply_plt_anim_duration_table[o->idx];
            o->x6c = lbl_805DFFD8 * (lbl_805DFFD4 - r * (f32)o->time);
        } else {
            o->x6c = 0;
        }
        o->x1c = o->x64 * (o->x3c - o->x5c) + o->x5c;
        o->x20 = o->x68 * (o->x40 - o->x60) + o->x60;
        o->x24 = o->x64 * (o->x44 - o->x5c) + o->x5c;
        o->x28 = o->x68 * (o->x48 - o->x60) + o->x60;
    }
}
#pragma pop

}
TAdPlyPltAnimGC::~TAdPlyPltAnimGC() {
    s32 i;
    for (i = 0; i < 5; i++) {
        if ((u32)(&TAdPlyPltAnimGC__instances.value)[i] != 0U) {
            (&TAdPlyPltAnimGC__instances.value)[i] = 0;
        }
    }
}


#pragma push
#pragma fp_contract on
s32 TAdPlyPltAnimGC__ct(int arg0, void *arg1, void *arg2) {
    __ct__7TObjectFP7TObject((void *)arg0, arg1);
    ((TAdPlyPltAnimGC_8035601C *)arg0)->vt = __vt__15TAdPlyPltAnimGC;
    ((TAdPlyPltAnimGC_8035601C *)arg0)->x0 = lbl_805D43A0;
    ((TAdPlyPltAnimGC_8035601C *)arg0)->x78 = -1;
    ((TAdPlyPltAnimGC_8035601C *)arg0)->x74 = 0;
    ((TAdPlyPltAnimGC_8035601C *)arg0)->x2c = lbl_805DFFDC;
    {
        f32 y0 = (f32)(s32)arg2 * lbl_80479350[0].y;
        ((TAdPlyPltAnimGC_8035601C *)arg0)->x30 = y0 * lbl_805DFFE0;
    }
    ((TAdPlyPltAnimGC_8035601C *)arg0)->x34 = lbl_80479350[0].x * lbl_805DFFE0;
    {
        f32 y1 = (f32)(s32)arg2 * lbl_80479350[0].y + lbl_80479350[0].y;
        ((TAdPlyPltAnimGC_8035601C *)arg0)->x38 = y1 * lbl_805DFFE0;
    }
    ((TAdPlyPltAnimGC_8035601C *)arg0)->x6c = 0xFF;
    ((TAdPlyPltAnimGC_8035601C *)arg0)->x70 = (s32)arg2;
    return arg0;
}

#pragma pop

typedef char RecoveredGlobal_803560F0_lbl_804F142C_size[sizeof(RecoveredGlobal_803560F0_lbl_804F142C) == 0x14 ? 1 : -1];
s32 get_or_create__15TAdPlyPltAnimGCFii(s32 arg0, s32 arg1) {
    s32 temp_r30;
    s32 temp_r3;
    s32 var_r0;
    temp_r30 = arg1 * 4;
    if ((u32) *(s32 *)((s8 *)(&TAdPlyPltAnimGC__instances.value) + temp_r30) == 0U) {
        temp_r3 = __nw__7TObjectFUl(0x7C);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = TAdPlyPltAnimGC__ct((int)temp_r3, (void *)arg0, (void *)arg1);
        }
        *(s32 *)((s8 *)(&TAdPlyPltAnimGC__instances.value) + temp_r30) = var_r0;
    }
    return *(s32 *)((s8 *)(&TAdPlyPltAnimGC__instances.value) + temp_r30);
}

void TAdPlyPltAnimGC__sub_8035615C(void) {
    if ((u32) player_prate_texture_list_ptr != 0U) {
        release_texture_list((void*)player_prate_texture_list_ptr);
        player_prate_texture_list_ptr = 0U;
    }
}

