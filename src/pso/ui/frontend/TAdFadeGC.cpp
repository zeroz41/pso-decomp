#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/NinjaUtil.h"
#include "pso/render/Draw2D.h"
#include "pso/render/ColorLineList.h"
#include "pso/ui/frontend/TAdFadeGC.h"

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/collision/TObjTradeCollision.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/player/PlayerSlots.h"


extern "C" {
f32 fade_line_depth;
s8 fade_line_depth_ready;
extern const char TAdFadeGC__class_name_string[] = "TAdFadeGC";
}
const char *TAdFadeGC::name = TAdFadeGC__class_name_string;
extern "C" {

void TAdFadeGC::draw_fade() {
    ColorLineVertex pos[4];
    ColorLineList d;
    u32 col[4];
    u32 i;
    f32 y;
    f32 y2;
    u32 c;

    d.verts = pos;
    d.colors = col;
    d.tex = NULL;
    d.count = 4;
    switch (fade_mode) {
    case 0:
        set_color_blending_mode(0, 0xB);
        set_color_blending_mode(1, 4);
        for (i = 0; i < 120; i++) {
            d.verts[0].x = (0.0f);
            y = (8.0f) * (f32) i;
            d.verts[0].y = y;
            d.colors[0] = 0x0FFFFFFF;
            d.verts[1].x = wipe_width;
            d.verts[1].y = y;
            d.colors[1] = 0xFFFFFFFF;
            d.verts[2].x = (6.4e+02f);
            y2 = (4.0f) + y;
            d.verts[2].y = y2;
            d.colors[2] = 0xFFFFFFFF;
            d.verts[3].x = (6.4e+02f) - wipe_width;
            d.verts[3].y = y2;
            d.colors[3] = 0xFFFFFFFF;
            if (fade_line_depth_ready == 0) {
                fade_line_depth_ready = 1;
                fade_line_depth = (-1.0f);
            }
            draw_color_lines(&d, 4, 7, fade_line_depth);
        }
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        break;
    case 1:
    case 2:
        d.verts[0].x = (0.0f);
        d.verts[0].y = (0.0f);
        c = fade_color;
        d.colors[0] = (c << 8) | (c >> 24);
        d.verts[1].x = (0.0f);
        d.verts[1].y = (4.8e+02f);
        c = fade_color;
        d.colors[1] = (c << 8) | (c >> 24);
        d.verts[2].x = (6.4e+02f);
        d.verts[2].y = (4.8e+02f);
        c = fade_color;
        d.colors[2] = (c << 8) | (c >> 24);
        d.verts[3].x = (6.4e+02f);
        d.verts[3].y = (0.0f);
        c = fade_color;
        d.colors[3] = (c << 8) | (c >> 24);
        draw_polygon_2d(reinterpret_cast<NJS_POINT2COL *>(&d), 4, 7, -1.0f);
        break;
    }
}

void TAdFadeGC::render() { if (all_parents_unqueued_for_destruction() != 0) { draw_fade(); } }

void TAdFadeGC::run_task() {
    f32 temp_f0;
    f32 new_opacity;
    f32 var_f2;
    if (((s32)all_parents_unqueued_for_destruction()) != 0) {
        elapsed_frames = (elapsed_frames + 1);
        switch (fade_mode) {
        case 0:
            wipe_width += 60.0f;
            wipe_width = (wipe_width > (6.4e+02f)) ? (6.4e+02f) : wipe_width;
            return;
        case 1: {
            opacity = (f32) (opacity + opacity_step);
            if (opacity > 1.0f) {
                opacity = 1.0f;
                queue_destruction();
                return;
            }
            fade_color = (s32) (((s32) ((255.0f) * (opacity)) << 0x18) | 0xFF0000 | 0xFFFF);
            return;
        }
        case 2: {
            opacity = (f32) (opacity + opacity_step);
            new_opacity = opacity;
            if (new_opacity < 0.0f) {
                opacity = 0.0f;
                queue_destruction();
                return;
            }
            fade_color = (s32) ((s32) ((255.0f) * new_opacity) << 0x18);
            break;
        }
        }
    }
}

void TAdFadeGC::start_fade(s32 mode) {
    switch (mode) {
    case 0:
        break;
    case 1:
        opacity = (0.0f);
        fade_color = 0;
        opacity_step = (0.025f);
        break;
    case 2:
        opacity = (1.0f);
        fade_color = 0;
        opacity_step = -0.06666667f;
        break;
    }
}

TAdFadeGC::~TAdFadeGC() {}
}
TAdFadeGC::TAdFadeGC(TObject *parent, s32 mode) : TObject(parent) {
    m_name = TAdFadeGC::name;
    elapsed_frames = -1;
    wipe_width = (0.0f);
    fade_mode = mode;
    start_fade(fade_mode);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
bool TObjTradeCollision::is_player_outside_trade_radius(u32 client) {
    f32 radius;
    f32 radius_sq;
    s32 player_floor;
    TObjPlayer *player;
    player = get_player_by_client_id(client);
    if (player == 0) {
        return 0;
    }
    if (get_main_phase() != 0xF) {
        return 0;
    }
    player_floor = player->get_floor();
    if (player_floor != get_current_floor()) {
        return 0;
    }
    radius = trade_radius;
    radius_sq = radius * radius;
    return (xz_distance_squared(&player->position, &position) < radius_sq) == 0;
}
#pragma pop
