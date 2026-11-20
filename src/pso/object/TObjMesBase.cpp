#include "types.h"
#include "pso/object/TObjMesBase.h"
#include "pso/object/TMotorcycle.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/quest/TQuestThread.h"

#include "pso/system/task/TObject.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"

#include "pso/unk/text_803D853C.h"

extern "C" {
extern void* quest_mission_manager;
extern void* quest_area_manager;
extern void* tl_00;
void *TObjMesBase__ct(TObjMesBase *arg0, s32 arg1, s32 arg2);
s32 __ct__14TObjCollidableFP7TObject();

const char *TObjMesBase__class_name = "TObjMesBase";

void TObjMesBase::debug_draw_label() {
    messageLabel = set_params[0];
    messageBank = set_params[2];
    if (messageBank < 0) {
        messageBank = 0;
    }
    if (messageBank > 1) {
        messageBank = 1;
    }
    const char *names[2] = {"QUEST", "RICO"};
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130020, "<- LABEL : %d", messageLabel);
    debug_printf_at(0x130022, "<- %s", names[messageBank]);
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


void *TObjMesBase__ct(TObjMesBase *mes_base, s32 arg1, saddr arg2) {
    __ct__14TObjCollidableFP7TObject();
    *(s32 **)((s8 *)mes_base + 0x18) = __vt__11TObjMesBase;
    mes_base->m_name = TObjMesBase__class_name;
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


