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

struct O_80355148 { u8 pad[0x1c]; s32 state; };

// Frame thresholds at which run_task starts each of the five palette animations.
const u32 ply_plt_anim_time_threshold_table[5] = { 0, 2, 4, 6, 12 };

const char *TAdPlyPltAnimCtrlGC__class_name = "TAdPlyPltAnimCtrlGC";

extern "C" {
s32 TAdPlyPltAnimCtrlGC__sub_80355148(O_80355148 *self);
u32 plyplt_anim_ctrl_instance;

TAdPlyPltAnimGC *TAdPlyPltAnimCtrlGC::get_table_value(int a0) { return TAdPlyPltAnimGC__instances[a0]; }

u32 TAdPlyPltAnimCtrlGC::get_instance(saddr arg0) {
    uaddr ad_ply_plt_anim_ctrl_gc;

    if ((u32) plyplt_anim_ctrl_instance == 0U) {
        ad_ply_plt_anim_ctrl_gc = (uaddr)new TAdPlyPltAnimCtrlGC((TObject *)arg0);
        plyplt_anim_ctrl_instance = ad_ply_plt_anim_ctrl_gc;
    }
    return plyplt_anim_ctrl_instance;
}

TAdPlyPltAnimCtrlGC::TAdPlyPltAnimCtrlGC(TObject *parent) : TObject(parent) {
    s32 index;
    index = 0;
    m_name = TAdPlyPltAnimCtrlGC__class_name;
    m_1c = 0;
    m_20 = -1;
    do {
        TAdPlyPltAnimGC::get_or_create(this, index);
        index += 1;
    } while (index < 5);
}

TAdPlyPltAnimCtrlGC::~TAdPlyPltAnimCtrlGC() {
    if ((u32) plyplt_anim_ctrl_instance != 0U) {
        plyplt_anim_ctrl_instance = 0U;
    }
}

void TAdPlyPltAnimCtrlGC::run_task() {
    TAdPlyPltAnimGC *p;
    if ((s32)this->m_1c == 0) {
        return;
    }
    (this->m_20)++;
    switch (this->m_1c) {
    case 0:
        break;
    case 1:
        if (this->m_20 >= ply_plt_anim_time_threshold_table[0]) {
            if ((p = TAdPlyPltAnimCtrlGC::get_table_value(0)) != NULL) {
                p->start_anim_rect(&this->m_24);
            }
            this->m_1c = 2;
        }
        break;
    case 2:
        if (this->m_20 >= ply_plt_anim_time_threshold_table[1]) {
            if ((p = TAdPlyPltAnimCtrlGC::get_table_value(1)) != NULL) {
                p->start_anim_rect(&this->m_24);
            }
            this->m_1c = 3;
        }
        break;
    case 3:
        if (this->m_20 >= ply_plt_anim_time_threshold_table[2]) {
            if ((p = TAdPlyPltAnimCtrlGC::get_table_value(2)) != NULL) {
                p->start_anim_rect(&this->m_24);
            }
            this->m_1c = 4;
        }
        break;
    case 4:
        if (this->m_20 >= ply_plt_anim_time_threshold_table[3]) {
            if ((p = TAdPlyPltAnimCtrlGC::get_table_value(3)) != NULL) {
                p->start_anim_rect(&this->m_24);
            }
            this->m_1c = 5;
        }
        break;
    case 5:
        if (this->m_20 >= ply_plt_anim_time_threshold_table[4]) {
            if ((p = TAdPlyPltAnimCtrlGC::get_table_value(4)) != NULL) {
                p->start_anim_rect(&this->m_24);
            }
            this->m_1c = 6;
        }
        break;
    case 6:
        if (this->m_20 > 0x1A) {
            this->m_1c = 7;
        }
        break;
    case 7:
        break;
    }
}

void TAdPlyPltAnimCtrlGC::init(void* a1) { TAdPlyPltAnimCtrlGC__sub_80355168((u8 *)this); copy_vec2(((char*)this + 0x24), a1); this->m_1c = 1; }

void TAdPlyPltAnimCtrlGC__sub_80355168(u8 *arg0) {
    s32 i;
    i = 0;
    *(s32 *)((s8 *)arg0 + 0x1C) = 0;
    *(s32 *)((s8 *)arg0 + 0x20) = -1;
    do {
        TAdPlyPltAnimGC *anim = TAdPlyPltAnimCtrlGC::get_table_value(i);
        if (anim != NULL) {
            anim->sub_80355D38();
        }
        i += 1;
    } while (i < 5);
}

s32 TAdPlyPltAnimCtrlGC__sub_80355148(O_80355148 *self) {
    s32 r = 1;
    if (self->state == 7 || self->state == 0) {
        r = 0;
    }
    return r;
}

void TAdPlyPltAnimCtrlGC::render() {
    if (TMainTask::get_render_pass() == 1) {
        return;
    }
}

u8 fn_8035510C(s32 *arg0, s32 arg1) {
    return (u8) (arg1 == (arg1 & *arg0));
}
}
