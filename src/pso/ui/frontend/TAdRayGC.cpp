#define TOBJECT_OUT_OF_LINE_HELPERS
#pragma readonly_strings on
#include "pso/ui/frontend/TAdRayGC.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

extern "C" {
extern f32 TAdRayGC_ray_quad_table[4][8];
uaddr TAdRayGC__ray_texture_list;

void TAdRayGC::draw_ray_quads(s32 frame, s32 color, s32 side) {
    u32 texture;
    u32 i;
    switch (side) {
    case 0:
        texture = frame;
        for (i = 0; i < 2; i++) {
            begin_screen_draw(1);
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(TAdRayGC__ray_texture_list));
            set_draw_texture_and_color(texture, color);
            draw_textured_quad_at_depth(TAdRayGC_ray_quad_table[i], 0.007142857f);
            TWindowSubStatusDisp::get_player();
        }
        break;
    case 1:
        texture = frame + 0x14;
        for (i = 2; i < 4; i++) {
            begin_screen_draw(1);
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(TAdRayGC__ray_texture_list));
            set_draw_texture_and_color(texture, color);
            draw_textured_quad_at_depth(TAdRayGC_ray_quad_table[i], 0.007142857f);
            TWindowSubStatusDisp::get_player();
        }
        break;
    }
}

void TAdRayGC::render() {

    if (TMainTask::get_render_pass() != 1) {
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 0xA);
        switch (state) {
        case 0:
            draw_ray_quads(frames, -1, 0);
            break;
        case 1:
            draw_ray_quads(frames, -1, 0);
            draw_ray_quads(frames - 0xD, -1, 1);
            break;
        case 2:
            draw_ray_quads(frames - 0xD, -1, 1);
            break;
        }
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
    }
}

void TAdRayGC::run_task() {

    frames = frames + 1;
    switch (state) {
    case 0:
        if (frames > 0xC) {
            state = 1;
        }
        break;
    case 1:
        if (frames > 0x12) {
            state = 2;
            return;
        }
        break;
    case 2:
        if (frames > 0x1F) {
            frames = 0x20;
            queue_destruction();
        }
        break;
    }
}

extern const char *TAdRayGC__name;

TAdRayGC::~TAdRayGC() {}
TAdRayGC::TAdRayGC(TObject *parent) : TObject(parent) {
    m_name = TAdRayGC__name;
    state = 0;
    frames = -1;
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

f32 TAdRayGC_ray_quad_table[4][8] = {
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

void register_texture_f128_ray(void) { TAdRayGC__ray_texture_list = (uaddr)&lbl_804DC2D8; load_streamed_prs_texture((saddr)"f128_ray", (saddr)&lbl_804DC2D8); }
