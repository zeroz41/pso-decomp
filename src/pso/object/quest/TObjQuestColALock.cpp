#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/quest/TObjQuestColALock.h"
#include "pso/object/quest/TObjQuestColBase.h"
#include "pso/object/quest/TObjQuestCol.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestThread.h"
#include "pso/player/TObjPlayer_801AF2F0.h"

extern "C" {
u32 init_collision_body_parts(void *, s32, s32);
u8 * TObjQuestColBase__ct(void *, s32);
extern s32 __vt__17TObjQuestColALock[];
extern s32 obj_quest_col_alock_class_name;
u8 *TObjQuestColALock__ct(TObjQuestColALock *arg0, s32 arg1);
void *__dt__17TObjQuestColALockFv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
void enable_action_input__10TObjPlayerFPv(void *p);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 __dl__7TObjectFPv(void *);
u8 *__dt__16TObjQuestColBaseFv(u8 *arg0, s16 arg1);
s32 check_flag_100__10TObjPlayerFPv();

int TObjQuestColALock::vfunc_16() { TQuestThreadBoard::destroy_board(); TQuestThread::create(this->m_b0); }

extern s32 controller_input_state[];
extern s32 local_client_id;

int TObjQuestColALock::vfunc_15() {
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
        submit_cursor_candidate(this, -1);
        temp_r3_2 = this->update_trigger_state(*(f32 *)&this->unk_AC);
        if (temp_r3_2 == 1) {
            ((TObjPlayer *)temp_r3)->disable_primary_action_input();
        }
        if (temp_r3_2 == 3) {
            enable_action_input__10TObjPlayerFPv((void *)temp_r3);
        }
        if (temp_r3_2 == 0) {
            ((TObjPlayer *)temp_r3)->disable_primary_action_input();
            if (TWindowShortListCtrl__check_controller_button((void *)((s8 *)controller_input_state + 0x20), 4) != 0) {
                return 1;
            }
        }
        goto block_12;
    }
block_12:
    return 0;
}

void *__dt__17TObjQuestColALockFv(void *quest_col_base, s16 arg1) {
    if (quest_col_base != NULL) {
        *(s32 **)((s8 *)quest_col_base + 0x18) = __vt__17TObjQuestColALock;
        ((TObjCollidable *)quest_col_base)->unregister_object_by_id();
        free_collision_body_parts(quest_col_base);
        __dt__16TObjQuestColBaseFv((u8 *)quest_col_base, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(quest_col_base);
        }
    }
    return quest_col_base;
}
u8 *TObjQuestColALock__ct(TObjQuestColALock *quest_col_a_lock, s32 arg1) {
    u8 *temp_r4;
    TObjQuestColBase__ct(quest_col_a_lock, arg1);
    *(s32 **)((s8 *)quest_col_a_lock + 0x18) = __vt__17TObjQuestColALock;
    *(s32 *)((s8 *)quest_col_a_lock + 0) = (s32) obj_quest_col_alock_class_name;
    init_collision_body_parts(quest_col_a_lock, (s32) &TObjQuestColALock__collision_desc.value, 1);
    ((TObjCollidable *)quest_col_a_lock)->set_indexed_flags(0, 0xF0);
    temp_r4 = (u8 *)quest_col_a_lock->bodies;
    *(f32 *)((s8 *)temp_r4 + 4) = (f32) (*(f32 *)((s8 *)temp_r4 + 4) + quest_col_a_lock->scale.y);
    ((TObjCollidable *)quest_col_a_lock)->refresh_collision_body_centers();
    quest_col_a_lock->actorFlags = (s32) (quest_col_a_lock->actorFlags | 0x40000000);
    ((TObjPlayer *)quest_col_a_lock)->register_object_by_id();
    return (u8 *)quest_col_a_lock;
}

}
