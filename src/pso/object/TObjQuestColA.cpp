#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjQuestColA.h"
#include "pso/object/TObjQuestColBase.h"
#include "pso/object/TObjQuestCol.h"
#include "pso/quest/TQuestThread.h"

extern "C" {

void *TObjQuestColA__ct(void *arg0);
void enable_action_input__10TObjPlayerFPv(void *p);
void TObjQuestColBase__ct(void *);
void *get_player_by_client_id(s32 i);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 check_flag_100__10TObjPlayerFPv();

int TObjQuestColA::vfunc_16() { TQuestThreadBoard::destroy_board(); TQuestThread::create(this->m_b0); }

extern s8 controller_input_state[];
extern s32 local_client_id;

int TObjQuestColA::vfunc_15() {
    s32 temp_r3;
    s32 temp_r3_2;

    temp_r3 = (s32)get_player_by_client_id(local_client_id);
    if (temp_r3 != 0) {
        if (check_flag_100__10TObjPlayerFPv() != 0) {
            enable_action_input__10TObjPlayerFPv((void *)temp_r3);
            return 0;
        }
        if (((TObjPlayer *)temp_r3)->is_quest_interaction_blocked() != 0) {
            enable_action_input__10TObjPlayerFPv((void *)temp_r3);
            return 0;
        }
        temp_r3_2 = this->update_trigger_state(*(f32 *)&this->unk_AC);
        if (temp_r3_2 == 1) {
            ((TObjPlayer *)temp_r3)->disable_primary_action_input();
        }
        if (temp_r3_2 == 3) {
            enable_action_input__10TObjPlayerFPv((void *)temp_r3);
        }
        if (temp_r3_2 == 0) {
            ((TObjPlayer *)temp_r3)->disable_primary_action_input();
            if (TWindowShortListCtrl__check_controller_button(controller_input_state + 0x20, 4) != 0) {
                return 1;
            }
        }
        goto block_12;
    }
block_12:
    return 0;
}

extern s32 __vt__13TObjQuestColA[];
extern void *TObjQuestColA__class_name;

void *TObjQuestColA__ct(void *quest_col_a) {
    TObjQuestColBase__ct(quest_col_a);
    *(s32 **)((s8 *)quest_col_a + 0x18) = __vt__13TObjQuestColA;
    *(void * *)&((TObjQuestColA *)quest_col_a)->m_name = TObjQuestColA__class_name;
    return quest_col_a;
}

}
