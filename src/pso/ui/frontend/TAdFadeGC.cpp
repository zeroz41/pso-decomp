#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/render/Draw2D.h"
#include "pso/render/ColorLineList.h"
#include "pso/ui/frontend/TAdFadeGC.h"

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/object/collision/TObjTradeCollision.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/player/PlayerSlots.h"


extern "C" {
f32 xz_distance_squared(void *, void *);
f32 lbl_805D6800;
s8 lbl_805D6804;
extern const char TAdFadeGC__class_name_string[] = "TAdFadeGC";
const char *TAdFadeGC__name = TAdFadeGC__class_name_string;

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
            if (lbl_805D6804 == 0) {
                lbl_805D6804 = 1;
                lbl_805D6800 = (-1.0f);
            }
            draw_color_lines(&d, 4, 7, lbl_805D6800);
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
    f32 temp_f1_2;
    f32 var_f2;
    if (((s32)all_parents_unqueued_for_destruction()) != 0) {
        elapsed_frames = (s32) (elapsed_frames + 1);
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
            temp_f1_2 = opacity;
            if (temp_f1_2 < 0.0f) {
                opacity = 0.0f;
                queue_destruction();
                return;
            }
            fade_color = (s32) ((s32) ((255.0f) * temp_f1_2) << 0x18);
            break;
        }
        }
    }
}

void TAdFadeGC::start_fade(void *arg1) {
    switch ((saddr)arg1) {
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
TAdFadeGC::TAdFadeGC(TObject *object, void *arg2) : TObject(object) {
    m_name = TAdFadeGC__name;
    elapsed_frames = -1;
    wipe_width = (0.0f);
    fade_mode = reinterpret_cast<saddr>(arg2);
    start_fade(reinterpret_cast<void *>(fade_mode));
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_dead_assignments off
bool TObjTradeCollision::is_player_outside_trade_radius(u32 client) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;
    f32 temp_f31;
    s32 temp_r31;
    saddr player;
    player = (saddr)get_player_by_client_id(client);
    if (player == 0) {
        return 0;
    }
    if (get_main_phase() != 0xF) {
        return 0;
    }
    temp_r31 = ((TObjPlayer *)player)->get_floor();
    if (temp_r31 != get_current_floor()) {
        return 0;
    }
    temp_f0 = *(f32 *)&this->unk_AC;
    temp_f31 = temp_f0 * temp_f0;
    return (xz_distance_squared((void *)(player + 0x38), (void *)(arg0 + 0x38)) < temp_f31) == 0;
}
#pragma pop
