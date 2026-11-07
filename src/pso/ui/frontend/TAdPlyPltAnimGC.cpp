#include "types.h"
#include "pso/ui/frontend/TAdPlyPltAnimGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"

#include "pso/ui/frontend/TAdPlyPltAnimCtrlGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/render/render_util.h"
#include "pso/render/GinjaTexture.h"

GinjaTextureEntry lbl_804F1418 = { "f256_player_prate", 0, NULL };
__declspec(section ".data") GinjaTextureList player_prate_texture_list = { &lbl_804F1418, 1 };
TAdPlyPltAnimGC *TAdPlyPltAnimGC__instances[5] = { NULL, NULL, NULL, NULL, NULL };
const PlyPltAnimVec2 ply_plt_anim_target_position_table[5] = {
    { 4.0f, 10.0f }, { 8.0f, 3.0f }, { 10.0f, 2.0f }, { 6.0f, 5.0f }, { 2.0f, 1.0f },
};
const u32 ply_plt_anim_duration_table[5] = { 16, 14, 12, 10, 14 };
// plate size in pixels (width, height)
static const PlyPltAnimVec2 lbl_80479350[1] = { { 180.0f, 38.0f } };
const char *TAdPlyPltAnimGC__class_name = "TAdPlyPltAnimGC";
GinjaTextureList *player_prate_texture_list_ptr;

#pragma push
#pragma fp_contract on
void TAdPlyPltAnimGC::render() {
    if (state != 0 && TMainTask::get_render_pass() != 1) {
        set_additive_blend();
        begin_screen_draw(1);
        TObjFish::set_global_param((s32)player_prate_texture_list_ptr);
        set_draw_texture_and_color(0, (alpha << 0x18) | 0xFF0000 | 0xFFFF);
        draw_textured_quad_at_depth(&quad.x0, (0.001f * (f32)index) + 0.99f);
        TWindowSubStatusDisp::get_player();
        set_default_alpha_blend();
    }
}
#pragma pop

void TAdPlyPltAnimGC::set_anim_state(s32 new_state) {
    if (new_state == 0) {
        frame = -1;
    }
    state = new_state;
}

void TAdPlyPltAnimGC::sub_80355D38() {
    set_anim_state(0);
}

#pragma push
#pragma fp_contract on
void TAdPlyPltAnimGC::start_anim_rect(PlyPltAnimVec2 *pos) {
    target.x0 = pos->x;
    target.y0 = pos->y;
    target.x1 = pos->x + lbl_80479350[0].x;
    target.y1 = pos->y + lbl_80479350[0].y;
    center_x = 0.5f * (target.x1 - target.x0) + target.x0;
    center_y = 0.5f * (target.y1 - target.y0) + target.y0;
    set_anim_state(1);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TAdPlyPltAnimGC::run_task() {
    if (state != 0) {
        frame++;
        if (frame < ply_plt_anim_duration_table[index] + 1) {
            f32 dx = (ply_plt_anim_target_position_table[index].x - 1.0f) / (f32)ply_plt_anim_duration_table[index];
            f32 dy = (ply_plt_anim_target_position_table[index].y - 1.0f) / (f32)ply_plt_anim_duration_table[index];
            scale_x = ply_plt_anim_target_position_table[index].x - dx * (f32)frame;
            scale_y = ply_plt_anim_target_position_table[index].y - dy * (f32)frame;
            f32 r = 1.0f / (f32)ply_plt_anim_duration_table[index];
            alpha = 255.0f * (1.0f - r * (f32)frame);
        } else {
            alpha = 0;
        }
        quad.x0 = scale_x * (target.x0 - center_x) + center_x;
        quad.y0 = scale_y * (target.y0 - center_y) + center_y;
        quad.x1 = scale_x * (target.x1 - center_x) + center_x;
        quad.y1 = scale_y * (target.y1 - center_y) + center_y;
    }
}
#pragma pop

TAdPlyPltAnimGC::~TAdPlyPltAnimGC() {
    s32 i;
    for (i = 0; i < 5; i++) {
        if (TAdPlyPltAnimGC__instances[i] != NULL) {
            TAdPlyPltAnimGC__instances[i] = NULL;
        }
    }
}

#pragma push
#pragma fp_contract on
TAdPlyPltAnimGC::TAdPlyPltAnimGC(TObject *parent, s32 plate) : TObject(parent) {
    m_name = TAdPlyPltAnimGC__class_name;
    frame = -1;
    state = 0;
    quad.u0 = 0.0f;
    quad.v0 = (f32)plate * lbl_80479350[0].y / 256.0f;
    quad.u1 = lbl_80479350[0].x / 256.0f;
    quad.v1 = ((f32)plate * lbl_80479350[0].y + lbl_80479350[0].y) / 256.0f;
    alpha = 0xFF;
    index = plate;
}
#pragma pop

TAdPlyPltAnimGC *TAdPlyPltAnimGC::get_or_create(TObject *parent, s32 index) {
    if (TAdPlyPltAnimGC__instances[index] == NULL) {
        TAdPlyPltAnimGC__instances[index] = new TAdPlyPltAnimGC(parent, index);
    }
    return TAdPlyPltAnimGC__instances[index];
}

void TAdPlyPltAnimGC__sub_8035615C(void) {
    if (player_prate_texture_list_ptr != NULL) {
        release_texture_list(player_prate_texture_list_ptr);
        player_prate_texture_list_ptr = NULL;
    }
}

void register_player_prate(void) {
    player_prate_texture_list_ptr = &player_prate_texture_list;
    TLobby__sub_8023E4B4((s32)"f256_player_prate", (s32)&player_prate_texture_list);
}
