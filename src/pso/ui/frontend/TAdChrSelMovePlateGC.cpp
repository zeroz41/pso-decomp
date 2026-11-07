#include "pso/ui/frontend/TAdChrSelMovePlateGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802C6F88.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"

struct Ent_80325660 { u8 b[0x20]; };

struct Obj_80325660 { u8 pad[0x20]; u32 count; u8 pad2[4]; Ent_80325660 ents[12]; u32 col[4]; };

struct T_8032572C { u8 pad[0x20]; u32 count; u8 pad24[0x184]; s32 arr[1]; };

struct R_803257E8 { f32 a; f32 b; f32 c; f32 d; u8 pad[0x10]; };

struct T_803257E8 { u8 pad[0x38]; R_803257E8 r[12]; };

struct O_80325824 { u8 pad[0x20]; u32 n; u8 pad2[0x1A8 - 0x24]; s32 v[1]; };

struct Ent_80325764 { f32 a, b, c, d; u8 pad[0x10]; };

struct Obj_80325764 { u8 pad[0x20]; s32 count; u8 pad2[4]; Ent_80325764 ents[12]; s32 col[12]; };

struct V2_80325764 { f32 x, y; };

struct Obj_803258C4 { s32 f0; u8 pad[0x18 - 4]; void *vt; u8 pad2[4]; s32 f20; s32 f24; u8 pad3[0x1A8 - 0x28]; s32 a[12]; s32 b[12]; };

extern "C" {
void add_plate_rect__20TAdChrSelMovePlateGCFPvPv(Obj_80325764 *arg0, V2_80325764 *arg1);
void __ct__7TObjectFP7TObject(void *);
extern u8 __vt__20TAdChrSelMovePlateGC[];
extern s32 lbl_805D4190;
extern s32 chr_sel_move_plate_texture;
Obj_803258C4 *__ct__20TAdChrSelMovePlateGCFv(Obj_803258C4 *arg0);
void TAdChrSelMovePlateGC::draw_move_plate_quads() {
    Obj_80325660 *arg0 = (Obj_80325660 *)this;
    u32 i;
    for (i = 0; i < arg0->count; i++) {
        begin_screen_draw(1);
        TObjFish::set_global_param(chr_sel_move_plate_texture);
        set_draw_texture_and_color(0, (arg0->col[i] << 24) | 0xFFFFFF);
        draw_textured_quad_at_depth((f32 *)&arg0->ents[i], 0.52f);
        TWindowSubStatusDisp::get_player();
    }
}

void TAdChrSelMovePlateGC::render() { if (TMainTask::get_render_pass() != 1) { draw_move_plate_quads(); } }
void TAdChrSelMovePlateGC::clear_entries() {
    T_8032572C *self = (T_8032572C *)this;
    u32 i;
    for (i = 0; i < self->count; i++) {
        self->arr[i] = 0;
    }
    self->count = 0;
}

void add_plate_rect__20TAdChrSelMovePlateGCFPvPv(Obj_80325764 *arg0, V2_80325764 *arg1) {
    arg0->ents[arg0->count].a = arg1->x;
    arg0->ents[arg0->count].b = arg1->y;
    arg0->ents[arg0->count].c = 180.0f + arg1->x;
    arg0->ents[arg0->count].d = 38.0f + arg1->y;
    arg0->col[arg0->count] = 0;
    arg0->count++;
}

void TAdChrSelMovePlateGC::init_plate_rects() {
    T_803257E8 *self = (T_803257E8 *)this;
    s32 i;
    for (i = 0; i < 12; i++) {
        self->r[i].a = 0.0f;
        self->r[i].b = 0.59375f;
        self->r[i].c = 0.703125f;
        self->r[i].d = 0.7421875f;
    }
}
void TAdChrSelMovePlateGC::run_task() {
    O_80325824 *arg0 = (O_80325824 *)this;
    u32 i;
    for (i = 0; i < arg0->n; i++) {
        s32 v;
        arg0->v[i] += 0x16;
        v = arg0->v[i];
        if (v > 0xFF) {
            v = 0xFF;
        }
        arg0->v[i] = v;
    }
}
TAdChrSelMovePlateGC::~TAdChrSelMovePlateGC() {}
Obj_803258C4 *__ct__20TAdChrSelMovePlateGCFv(Obj_803258C4 *arg0) {
    s32 i;
    __ct__7TObjectFP7TObject(arg0);
    arg0->vt = __vt__20TAdChrSelMovePlateGC;
    arg0->f0 = lbl_805D4190;
    chr_sel_move_plate_texture = TAdMultiPlyChrSelectGC__sub_802C6FA8();
    arg0->f24 = -1;
    arg0->f20 = 0;
    ((TAdChrSelMovePlateGC *)arg0)->init_plate_rects();
    for (i = 0; i < 12; i++) {
        arg0->b[i] = 0;
        arg0->a[i] = 0;
    }
    return arg0;
}

}
