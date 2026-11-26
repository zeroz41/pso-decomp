#pragma defer_codegen on

#include "types.h"
#include "pso/ui/frontend/TAdPlyPltAnimCtrlGC.h"
#include "pso/ui/frontend/TAdPlyPltAnimGC.h"
#include "pso/ui/frontend/TAdRicoRing.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"

// Frame thresholds at which run_task starts each of the five palette animations.
const u32 ply_plt_anim_time_threshold_table[5] = { 0, 2, 4, 6, 12 };

const char *TAdPlyPltAnimCtrlGC::class_name = "TAdPlyPltAnimCtrlGC";

u32 plyplt_anim_ctrl_instance;

TAdPlyPltAnimGC *TAdPlyPltAnimCtrlGC::get_table_value(int index) { return TAdPlyPltAnimGC::instances[index]; }

u32 TAdPlyPltAnimCtrlGC::get_instance(saddr parent) {
    uaddr ad_ply_plt_anim_ctrl_gc;

    if (plyplt_anim_ctrl_instance == 0U) {
        ad_ply_plt_anim_ctrl_gc = (uaddr)new TAdPlyPltAnimCtrlGC((TObject *)parent);
        plyplt_anim_ctrl_instance = ad_ply_plt_anim_ctrl_gc;
    }
    return plyplt_anim_ctrl_instance;
}

TAdPlyPltAnimCtrlGC::TAdPlyPltAnimCtrlGC(TObject *parent) : TObject(parent) {
    s32 index;
    index = 0;
    m_name = TAdPlyPltAnimCtrlGC::class_name;
    state = 0;
    frame = -1;
    do {
        TAdPlyPltAnimGC::get_or_create(this, index);
        index += 1;
    } while (index < 5);
}

TAdPlyPltAnimCtrlGC::~TAdPlyPltAnimCtrlGC() {
    if (plyplt_anim_ctrl_instance != 0U) {
        plyplt_anim_ctrl_instance = 0U;
    }
}

void TAdPlyPltAnimCtrlGC::run_task() {
    TAdPlyPltAnimGC *p;
    if ((s32)this->state == 0) {
        return;
    }
    (this->frame)++;
    switch (this->state) {
    case 0:
        break;
    case 1:
        if (this->frame >= ply_plt_anim_time_threshold_table[0]) {
            if ((p = TAdPlyPltAnimCtrlGC::get_table_value(0)) != NULL) {
                p->start_anim_rect(&this->plate_position);
            }
            this->state = 2;
        }
        break;
    case 2:
        if (this->frame >= ply_plt_anim_time_threshold_table[1]) {
            if ((p = TAdPlyPltAnimCtrlGC::get_table_value(1)) != NULL) {
                p->start_anim_rect(&this->plate_position);
            }
            this->state = 3;
        }
        break;
    case 3:
        if (this->frame >= ply_plt_anim_time_threshold_table[2]) {
            if ((p = TAdPlyPltAnimCtrlGC::get_table_value(2)) != NULL) {
                p->start_anim_rect(&this->plate_position);
            }
            this->state = 4;
        }
        break;
    case 4:
        if (this->frame >= ply_plt_anim_time_threshold_table[3]) {
            if ((p = TAdPlyPltAnimCtrlGC::get_table_value(3)) != NULL) {
                p->start_anim_rect(&this->plate_position);
            }
            this->state = 5;
        }
        break;
    case 5:
        if (this->frame >= ply_plt_anim_time_threshold_table[4]) {
            if ((p = TAdPlyPltAnimCtrlGC::get_table_value(4)) != NULL) {
                p->start_anim_rect(&this->plate_position);
            }
            this->state = 6;
        }
        break;
    case 6:
        if (this->frame > 0x1A) {
            this->state = 7;
        }
        break;
    case 7:
        break;
    }
}

void TAdPlyPltAnimCtrlGC::init(void* a1) { reset_plate_animations(this); copy_vec2(((char*)this + 0x24), a1); this->state = 1; }

void reset_plate_animations(TAdPlyPltAnimCtrlGC *ctrl) {
    s32 i;
    i = 0;
    ctrl->state = 0;
    ctrl->frame = -1;
    do {
        TAdPlyPltAnimGC *anim = TAdPlyPltAnimCtrlGC::get_table_value(i);
        if (anim != NULL) {
            anim->reset_to_idle();
        }
        i += 1;
    } while (i < 5);
}
extern "C" {

s32 is_plate_animation_running(TAdPlyPltAnimCtrlGC *self) {
    s32 r = 1;
    if ((s32)self->state == 7 || (s32)self->state == 0) {
        r = 0;
    }
    return r;
}
}

void TAdPlyPltAnimCtrlGC::render() {
    if (TMainTask::get_render_pass() == 1) {
        return;
    }
}

s32 test_flags_all(s32 *flags, s32 mask) {
    return (u8) (mask == (mask & *flags));
}
