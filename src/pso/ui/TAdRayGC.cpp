#include "pso/TAdRayGC.h"
#include "pso/ui/TAdRayGC.h"

#include "types.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/system/ModelDrawContext.h"

struct E_8029BCB4 { u8 b[0x14]; };

struct T_8029BCB4 { u8 b[0x20]; };

extern "C" {
void begin_screen_draw(s32 arg0);
s32 draw_textured_quad_at_depth(void *, f32);
s32 set_draw_texture_and_color(void *, void *);
extern T_8029BCB4 TAdRayGC_ray_quad_table[];
extern s32 TAdRayGC__ray_texture_list;
extern const f32 lbl_805DDD10;
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
            draw_textured_quad_at_depth(&TAdRayGC_ray_quad_table[i], lbl_805DDD10);
            TWindowSubStatusDisp::get_player();
        }
        break;
    case 1:
        p = (E_8029BCB4 *)(arg1 + 0x14);
        for (i = 2; i < 4; i++) {
            begin_screen_draw(1);
            TObjFish::set_global_param((s32)((void *) TAdRayGC__ray_texture_list));
            set_draw_texture_and_color(p, arg2);
            draw_textured_quad_at_depth(&TAdRayGC_ray_quad_table[i], lbl_805DDD10);
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
extern void *TAdRayGC__name;

TAdRayGC::~TAdRayGC() {}
void *__ct__8TAdRayGCFv(void *ad_ray_gc) {
    __ct__7TObjectFP7TObject(ad_ray_gc);
    *(s32 **)((s8 *)ad_ray_gc + 0x18) = __vt__8TAdRayGC;
    *(void * *)&((TAdRayGC *)ad_ray_gc)->m_name = TAdRayGC__name;
    *(u32 *)((s8 *)ad_ray_gc + 0x1C) = 0;
    *(u32 *)((s8 *)ad_ray_gc + 0x20) = -1;
    return ad_ray_gc;
}

}
