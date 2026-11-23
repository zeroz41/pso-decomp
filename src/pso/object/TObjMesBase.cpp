#include "pso/unk/TUnk_804C8678.h"
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
#include "pso/system/task/TMainTask.h"


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

void TObjMesBase::interact(u16) {
    s32 label = messageLabel;
    if (label != 0) {
        TUnk_804C8678 *root = NULL;
        switch (messageBank) {
        case 0: root = quest_mission_manager; break;
        case 1: root = quest_area_manager; break;
        }
        switch (messagePhase) {
        case 0:
            if (!messageChild && label != 0 && root) {
                messageChild = new TQuestThread(root, messageLabel);
                if (messageChild) messageChild->set_parent(tl_00);
                messagePhase = 1;
            }
            break;
        case 1: break;
        }
    }
}
void TObjMesBase::clear_ref_if_destroyed() {
    TQuestThread *p = this->messageChild;
    if ((p != 0) && (p->all_parents_unqueued_for_destruction() == 0)) {
        this->messageChild = NULL;
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


TObjMesBase::~TObjMesBase() {

}


TObjMesBase::TObjMesBase(TObject *parent, ObjectSetData *placement) : TObjCollidable(parent) {
    m_name = TObjMesBase__class_name;
    apply_object_set_data(placement);
    messageLabel = set_params[0];
    messageBank = set_params[2];
    if (messageBank < 0) {
        messageBank = 0;
    }
    if (messageBank > 1) {
        messageBank = 1;
    }
    messageChild = NULL;
    messagePhase = 0;
}
#undef mes_base


