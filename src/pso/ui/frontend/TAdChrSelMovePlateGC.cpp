#include "pso/ui/frontend/TAdChrSelMovePlateGC.h"
#include "pso/ui/frontend/TAdChrSelSlotGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC_802C6F88.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"

extern "C" {
const char *lbl_805D4190 = "TAdChrSelMovePlateGC";
s32 chr_sel_move_plate_texture;

void TAdChrSelMovePlateGC::draw_move_plate_quads() {
    u32 i;
    for (i = 0; i < count; i++) {
        begin_screen_draw(1);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(chr_sel_move_plate_texture));
        set_draw_texture_and_color(0, ((u32)opacity[i] << 24) | 0xFFFFFF);
        draw_textured_quad_at_depth(quads[i].values, 0.52f);
        TWindowSubStatusDisp::get_player();
    }
}

void TAdChrSelMovePlateGC::render() { if (TMainTask::get_render_pass() != 1) { draw_move_plate_quads(); } }
void TAdChrSelMovePlateGC::clear_entries() {
    u32 i;
    for (i = 0; i < count; i++) {
        opacity[i] = 0;
    }
    count = 0;
}

void TAdChrSelMovePlateGC::add_plate_rect(CharacterSlotPosition *position) {
    quads[count].values[0] = position->x;
    quads[count].values[1] = position->y;
    quads[count].values[2] = 180.0f + position->x;
    quads[count].values[3] = 38.0f + position->y;
    opacity[count] = 0;
    count++;
}

void TAdChrSelMovePlateGC::init_plate_rects() {
    s32 i;
    for (i = 0; i < 12; i++) {
        quads[i].values[4] = 0.0f;
        quads[i].values[5] = 0.59375f;
        quads[i].values[6] = 0.703125f;
        quads[i].values[7] = 0.7421875f;
    }
}
void TAdChrSelMovePlateGC::run_task() {
    u32 i;
    for (i = 0; i < count; i++) {
        s32 v;
        opacity[i] += 0x16;
        v = opacity[i];
        if (v > 0xFF) {
            v = 0xFF;
        }
        opacity[i] = v;
    }
}
TAdChrSelMovePlateGC::~TAdChrSelMovePlateGC() {}
TAdChrSelMovePlateGC::TAdChrSelMovePlateGC(TObject *parent) : TObject(parent) {
    s32 i;
    m_name = lbl_805D4190;
    chr_sel_move_plate_texture = TAdMultiPlyChrSelectGC__sub_802C6FA8();
    mode = -1;
    count = 0;
    init_plate_rects();
    TAdChrSelMovePlateGC *owner = this;
    for (i = 0; i < 12; i++) {
        owner->other[i] = 0;
        owner->opacity[i] = 0;
    }
}

}
