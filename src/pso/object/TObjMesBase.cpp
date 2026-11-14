#include "types.h"
#include "pso/object/TObjMesBase.h"
#include "pso/object/TMotorcycle.h"
#include "pso/object/TObjMesBase.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/quest/TQuestThread.h"

#include "pso/system/task/TObject.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjMotion.h"

struct Pair_80194AEC { const char *s[2]; };

struct Mes_80194AEC { u8 pad0[0x84]; s32 f84; u8 pad88[4]; s32 f8C; u8 pad90[0x24]; s32 fB4; s32 fB8; };

extern "C" {
extern void* quest_mission_manager;
extern void* quest_area_manager;
extern void* tl_00;
void* __nw__7TObjectFUl(unsigned long);
void debug_printf_at(int, void *, ...);
extern Pair_80194AEC lbl_80445D94[];
extern u8 lbl_80445D9C[];
extern u8 lbl_80445DAC[];
void *TObjMesBase__ct(TObjMesBase *arg0, s32 arg1, s32 arg2);
void *__dt__11TObjMesBaseFv(void *arg0, s16 arg1);
s32 __ct__14TObjCollidableFP7TObject();
void __dl__7TObjectFPv(void *);

void TObjMesBase::debug_draw_label() {
    Mes_80194AEC *arg0 = (Mes_80194AEC *)this;
    arg0->fB4 = arg0->f84;
    arg0->fB8 = arg0->f8C;
    if (arg0->fB8 < 0) {
        arg0->fB8 = 0;
    }
    if (arg0->fB8 > 1) {
        arg0->fB8 = 1;
    }
    Pair_80194AEC names = lbl_80445D94[0];
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, lbl_80445D9C, arg0->fB4);
    debug_printf_at(0x130022, lbl_80445DAC, names.s[arg0->fB8]);
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TObjMesBase::interact(s32) {
    s32 label = messageLabel;
    if (label != 0) {
        void* root = 0;
        switch (messageBank) {
        case 0: root = quest_mission_manager; break;
        case 1: root = quest_area_manager; break;
        }
        switch (messagePhase) {
        case 0:
            if (!messageChild && label != 0 && root) {
                messageChild = new TQuestThread((TObject *)root, messageLabel);
                if (messageChild) ((TObject *)messageChild)->set_parent((TObject *)tl_00);
                messagePhase = 1;
            }
            break;
        case 1: break;
        }
    }
}
void TObjMesBase::clear_ref_if_destroyed() {
    void *p = this->messageChild;
    if ((p != 0) && (((TObject *)p)->all_parents_unqueued_for_destruction() == 0)) {
        this->messageChild = 0U;
        this->messagePhase = 0;
    }
}
void TObjMesBase::vfunc_14() {  }

void TObjMesBase::run_task() {

    switch (this->messagePhase) {
    case 0:
        this->vfunc_14();
        return;
    case 1:
        this->clear_ref_if_destroyed();
        return;
    }
}

extern s32 __vt__11TObjMesBase[];

}
TObjMesBase::~TObjMesBase() {

}
extern "C" {

extern s32 TObjMesBase__class_name;

void *TObjMesBase__ct(TObjMesBase *mes_base, s32 arg1, s32 arg2) {
    __ct__14TObjCollidableFP7TObject();
    *(s32 **)((s8 *)mes_base + 0x18) = __vt__11TObjMesBase;
    *(s32 *)((s8 *)mes_base + 0) = (s32) TObjMesBase__class_name;
    mes_base->apply_object_set_data((void *)arg2);
    mes_base->messageLabel = (s32) mes_base->set_params[0];
    mes_base->messageBank = (s32) mes_base->set_params[2];
    if ((s32) mes_base->messageBank < 0) {
        mes_base->messageBank = 0;
    }
    if ((s32) mes_base->messageBank > 1) {
        mes_base->messageBank = 1;
    }
    *(s32 *)((s8 *)mes_base + 0xAC) = 0;
    mes_base->messagePhase = 0;
    return mes_base;
}


}
