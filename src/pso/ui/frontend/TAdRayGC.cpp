#pragma readonly_strings on
#include "pso/ui/frontend/TAdRayGC.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/player/TObjPlayer_8023E480.h"

struct E_8029BCB4 { u8 b[0x14]; };

struct T_8029BCB4 { f32 v[8]; };

extern "C" {
void begin_screen_draw(s32 arg0);
s32 draw_textured_quad_at_depth(void *, f32);
s32 set_draw_texture_and_color(void *, void *);
extern T_8029BCB4 TAdRayGC_ray_quad_table[4];
u32 TAdRayGC__ray_texture_list;
void __ct__7TObjectFP7TObject(void *);
s32 queue_destruction__7TObjectFv();

void TAdRayGC::draw_ray_quads(s32 arg0, u8 *arg1, void *arg2, s32 arg3) {
    u32 i;
    E_8029BCB4 *p;
    switch (arg3) {
    case 0:
        p = (E_8029BCB4 *)arg1;
        for (i = 0; i < 2; i++) {
            begin_screen_draw(1);
            TObjFish::set_global_param((s32)((void *) TAdRayGC__ray_texture_list));
            set_draw_texture_and_color(p, arg2);
            draw_textured_quad_at_depth(&TAdRayGC_ray_quad_table[i], 0.007142857f);
            TWindowSubStatusDisp::get_player();
        }
        break;
    case 1:
        p = (E_8029BCB4 *)(arg1 + 0x14);
        for (i = 2; i < 4; i++) {
            begin_screen_draw(1);
            TObjFish::set_global_param((s32)((void *) TAdRayGC__ray_texture_list));
            set_draw_texture_and_color(p, arg2);
            draw_textured_quad_at_depth(&TAdRayGC_ray_quad_table[i], 0.007142857f);
            TWindowSubStatusDisp::get_player();
        }
        break;
    }
}

void TAdRayGC::render() {

    if (TMainTask::get_render_pass() != 1) {
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 0xA);
        switch (*(s32 *)((s8 *)this + 0x1C)) {
        case 0:
            TAdRayGC::draw_ray_quads((s32)this, (u8 *)(*(s32 *)((s8 *)this + 0x20)), (void *)(-1), 0);
            break;
        case 1:
            TAdRayGC::draw_ray_quads((s32)this, (u8 *)(*(s32 *)((s8 *)this + 0x20)), (void *)(-1), 0);
            TAdRayGC::draw_ray_quads((s32)this, (u8 *)(*(s32 *)((s8 *)this + 0x20) - 0xD), (void *)(-1), 1);
            break;
        case 2:
            TAdRayGC::draw_ray_quads((s32)this, (u8 *)(*(s32 *)((s8 *)this + 0x20) - 0xD), (void *)(-1), 1);
            break;
        }
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
    }
}

void TAdRayGC::run_task() {

    *(s32 *)((s8 *)this + 0x20) = (s32) (*(s32 *)((s8 *)this + 0x20) + 1);
    switch (*(s32 *)((s8 *)this + 0x1C)) {
    case 0:
        if ((s32) *(s32 *)((s8 *)this + 0x20) > 0xC) {
            *(s32 *)((s8 *)this + 0x1C) = 1;
        }
        break;
    case 1:
        if ((s32) *(s32 *)((s8 *)this + 0x20) > 0x12) {
            *(s32 *)((s8 *)this + 0x1C) = 2;
            return;
        }
        break;
    case 2:
        if ((s32) *(s32 *)((s8 *)this + 0x20) > 0x1F) {
            *(s32 *)((s8 *)this + 0x20) = 0x20;
            queue_destruction__7TObjectFv();
        }
        break;
    }
}

extern s32 __vt__8TAdRayGC[];
extern const char *TAdRayGC__name;

TAdRayGC::~TAdRayGC() {}
void *__ct__8TAdRayGCFv(void *ad_ray_gc) {
    __ct__7TObjectFP7TObject(ad_ray_gc);
    *(s32 **)((s8 *)ad_ray_gc + 0x18) = __vt__8TAdRayGC;
    ((TAdRayGC *)ad_ray_gc)->m_name = TAdRayGC__name;
    *(u32 *)((s8 *)ad_ray_gc + 0x1C) = 0;
    *(u32 *)((s8 *)ad_ray_gc + 0x20) = -1;
    return ad_ray_gc;
}

struct TexName_804DC0F8 { const char *name; s32 a; s32 b; };
struct TexList_804DC2D8 { TexName_804DC0F8 *list; s32 n; };

TexName_804DC0F8 lbl_804DC0F8[40] = {
    { "f128_ray_left01", 0, 0 },
    { "f128_ray_left02", 0, 0 },
    { "f128_ray_left03", 0, 0 },
    { "f128_ray_left04", 0, 0 },
    { "f128_ray_left05", 0, 0 },
    { "f128_ray_left06", 0, 0 },
    { "f128_ray_left07", 0, 0 },
    { "f128_ray_left08", 0, 0 },
    { "f128_ray_left09", 0, 0 },
    { "f128_ray_left10", 0, 0 },
    { "f128_ray_left11", 0, 0 },
    { "f128_ray_left12", 0, 0 },
    { "f128_ray_left13", 0, 0 },
    { "f128_ray_left14", 0, 0 },
    { "f128_ray_left15", 0, 0 },
    { "f128_ray_left16", 0, 0 },
    { "f128_ray_left17", 0, 0 },
    { "f128_ray_left18", 0, 0 },
    { "f128_ray_left19", 0, 0 },
    { "f128_ray_left20", 0, 0 },
    { "f128_ray_right01", 0, 0 },
    { "f128_ray_right02", 0, 0 },
    { "f128_ray_right03", 0, 0 },
    { "f128_ray_right04", 0, 0 },
    { "f128_ray_right05", 0, 0 },
    { "f128_ray_right06", 0, 0 },
    { "f128_ray_right07", 0, 0 },
    { "f128_ray_right08", 0, 0 },
    { "f128_ray_right09", 0, 0 },
    { "f128_ray_right10", 0, 0 },
    { "f128_ray_right11", 0, 0 },
    { "f128_ray_right12", 0, 0 },
    { "f128_ray_right13", 0, 0 },
    { "f128_ray_right14", 0, 0 },
    { "f128_ray_right15", 0, 0 },
    { "f128_ray_right16", 0, 0 },
    { "f128_ray_right17", 0, 0 },
    { "f128_ray_right18", 0, 0 },
    { "f128_ray_right19", 0, 0 },
    { "f128_ray_right20", 0, 0 },
};
__declspec(section ".data") TexList_804DC2D8 lbl_804DC2D8 = { lbl_804DC0F8, 40 };

T_8029BCB4 TAdRayGC_ray_quad_table[4] = {
    { 0.0f, 0.0f, 319.0f, 239.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 0.0f, 479.0f, 319.0f, 240.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 320.0f, 0.0f, 639.0f, 239.0f, 0.0f, 0.0f, 1.0f, 1.0f },
    { 320.0f, 479.0f, 639.0f, 240.0f, 0.0f, 0.0f, 1.0f, 1.0f },
};

const char *TAdRayGC__name = "TAdRayGC";

void release_texture_list(void*);

void TAdRayGC::destroy_instance() {
    if (TAdRayGC__ray_texture_list != 0) {
        release_texture_list((void*)TAdRayGC__ray_texture_list);
        TAdRayGC__ray_texture_list = 0;
    }
}

}

void register_texture_f128_ray(void) { TAdRayGC__ray_texture_list = (u32)&lbl_804DC2D8; TLobby__sub_8023E4B4((s32)"f128_ray", (s32)&lbl_804DC2D8); }
