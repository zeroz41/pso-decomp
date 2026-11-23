#include "types.h"
#include "pso/render/ColorCopy.h"
#include "pso/render/Draw2D.h"
#include <stddef.h>
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/ui/frontend/TAdPlyChrSelPlateGC.h"
#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"
#include "pso/system/vector.h"

const char *TAdPlyChrSelPlateGC__name = "TAdPlyChrSelPlateGC";

#pragma push
#pragma fp_contract on
void draw_selection_plate(TAdPlyChrSelPlateGC *plate, NJS_POINT2 *pos, NJS_COLOR color, u32 depth) {
    NJS_POINT2COL fan;
    NJS_POINT2 *xyp;
    NJS_COLOR col[4];
    NJS_POINT2 xy[4];
    f32 y;
    f32 x;

    x = pos->x;
    y = pos->y;
    fan.col = col;
    xyp = xy;
    if ((!&color && !&color) && !&color) {
    }
    fan.p = xyp;
    fan.tex = NULL;
    fan.num = 4;
    fan.p[0].x = x;
    fan.p[0].y = y;
    copy4(&fan.col[0], &color);
    fan.p[1].x = fan.p[0].x;
    fan.p[1].y = fan.p[0].y + plate->plate_size.y;
    copy4(&fan.col[1], &color);
    fan.p[2].x = fan.p[0].x + plate->plate_size.x;
    fan.p[2].y = fan.p[0].y + plate->plate_size.y;
    copy4(&fan.col[2], &color);
    fan.p[3].x = fan.p[0].x + plate->plate_size.x;
    fan.p[3].y = fan.p[0].y;
    copy4(&fan.col[3], &color);
    draw_polygon_2d(&fan, 4, 7, 0.001f * (f32)depth + (-30.0f));
}
#pragma pop

void TAdPlyChrSelPlateGC::render() {
    u32 i;

    if (TMainTask::get_render_pass() != 1) {
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 10);
        for (i = 0; i < plate_count; i++) {
            if (plate_shown[i] != 0) {
                u8 *pos = (u8 *)this;
                pos += i * sizeof(NJS_POINT2);
                pos += offsetof(TAdPlyChrSelPlateGC, plate_pos);
                draw_selection_plate(this, (NJS_POINT2 *)pos, plate_color[i], i);
            }
        }
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
    }
}

extern "C" {
void copy_vec2__FPvPv(NJS_POINT2 *destination, const f32 *source);

s32 TAdPlyChrSelPlateGC::is_slot_value_ready(s32 i) {
    return plate_progress[i] >= 127.5f ? 1 : 0;
}

void TAdPlyChrSelPlateGC::reset_selection_slots() {
    s32 i;
    animation_frame = -1;
    plate_count = 0;
    for (i = 0; i < 32; i++) {
        plate_shown[i] = 0;
        plate_progress[i] = 0.0f;
        plate_color[i].argb.a = 0;
        plate_color[i].argb.r = 0;
        plate_color[i].argb.g = 0;
        plate_color[i].argb.b = 0;
    }
}

void TAdPlyChrSelPlateGC::push_plate_position(const CharacterSlotPosition *position) {
    if ((s32)plate_count < 32) {
        copy_vec2__FPvPv(&target_pos[plate_count], &position->x);
        copy_vec2__FPvPv(&plate_pos[plate_count], &target_pos[0].x);
        plate_count = plate_count + 1;
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_propagation off
void TAdPlyChrSelPlateGC::run_task() {
    s32 half;
    s32 m;
    u32 i;
    s32 j;
    if (animation_frame < (s32)plate_count * 2 + 1) {
        animation_frame = animation_frame + 1;
    }
    for (i = 0; i < 32; i++) {
        if (plate_shown[i] != 0) {
            if (plate_shown[i] == -1) {
                plate_color[i].argb.g = 0xFF;
                plate_color[i].argb.r = 0xFF;
                plate_color[i].argb.a = 0xFF;
                plate_color[i].argb.b = 0x22;
                plate_shown[i] = 1;
            } else {
                plate_progress[i] += 255.0f;
                plate_progress[i] = (plate_progress[i] > 127.5f) ? 127.5f : plate_progress[i];
                plate_color[i].argb.g = active_color.argb.g;
                plate_color[i].argb.r = active_color.argb.r;
                plate_color[i].argb.a = active_color.argb.a;
                plate_color[i].argb.b = (s32)plate_progress[i];
            }
            for (j = 0; j < 32; j++) {
                s32 k = 0;
                plate_pos[j].x = target_pos[j].x;
                plate_pos[j].y += (target_pos[j].y - target_pos[0].y) / (5.0f * (f32)k + 30.0f);
                plate_pos[j].y = (plate_pos[j].y > target_pos[j].y) ? target_pos[j].y : plate_pos[j].y;
            }
        }
    }
    if (animation_frame % 2 == 0) {
        half = animation_frame / 2;
        m = half - 1;
        if (m < (s32)plate_count && half - 1 >= 0 && m < 32) {
            plate_shown[half - 1] = 1;
        }
    }
}
#pragma pop

}

TAdPlyChrSelPlateGC::~TAdPlyChrSelPlateGC() {}

// The original loop advances one word through three separate arrays in the plate.
struct SelectionPlateInit {
    const char *name;
    u8 prefix[0x224 - 4];
    s32 count;
    s32 shown[32];
    f32 progress[32];
    u8 color[32][4];
    u8 active_color[4];
    s32 frame;
    s32 settings;
};

TAdPlyChrSelPlateGC::TAdPlyChrSelPlateGC(TObject *parent, const ChrSelPlateLayout *layout)
    : TObject(parent) {
    SelectionPlateInit *state = reinterpret_cast<SelectionPlateInit *>(this);
    s32 i;
    // Keep the initial name store before the settings read in the retail instruction order.
    reinterpret_cast<volatile SelectionPlateInit *>(this)->name = TAdPlyChrSelPlateGC__name;
    state->settings = reinterpret_cast<const volatile ChrSelPlateLayout *>(layout)->settings;
    state->frame = -1;
    state->count = 0;
    for (i = 0; i < 32; ++i) {
        state->shown[i] = 0;
        state->progress[i] = 0.0f;
        state->color[i][0] = 0;
        state->color[i][1] = 0;
        state->color[i][2] = 0;
        state->color[i][3] = 0;
    }
    copy_vec2__FPvPv(&plate_size, &layout->width);
    copy4(&active_color, layout->color);
}
