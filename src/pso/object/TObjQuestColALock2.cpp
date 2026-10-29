#include "pso/system/NinjaTypes.h"
#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/object/TObjQuestColALock2.h"
#include "pso/object/TObjQuestColBase.h"
#include "pso/TObject.h"
#include "pso/quest/TQuestThread.h"
#include "pso/object/TObjQuestCol.h"
#include "pso/player/TObjPlayer.h"

struct RecoveredGlobal_80195BEC_lbl_80445E84 { s32 value; u8 remaining[0x28]; };
typedef char RecoveredGlobal_80195BEC_lbl_80445E84_size[sizeof(RecoveredGlobal_80195BEC_lbl_80445E84) == 0x2C ? 1 : -1];

struct RecoveredGlobal_80195BEC___vt__18TObjQuestColALock2 { s32 value; u8 remaining[0x40]; };
typedef char RecoveredGlobal_80195BEC___vt__18TObjQuestColALock2_size[sizeof(RecoveredGlobal_80195BEC___vt__18TObjQuestColALock2) == 0x44 ? 1 : -1];

struct VBase_18_26a62c { char pad[0x18]; };

struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_801959A0_lbl_804A7428 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
void *__nw__7TObjectFUl(int);
extern s32 tl_00;
u8 *TObjQuestColALock2__vt14(TObjQuestColALock2 *arg0);
u32 init_collision_body_parts(void *, s32, s32);
u8 * TObjQuestColBase__ct(void *, s32);
extern RecoveredGlobal_80195BEC_lbl_80445E84 TObjQuestColALock__collision_desc;
extern s32 __vt__18TObjQuestColALock2[];
extern s32 lbl_805D3408;
extern s32 quest_mission_manager;
extern s32 quest_area_manager;
u8 *TObjQuestColALock2__ct(TObjQuestColALock2 *arg0, s32 arg1, s32 _w2);
s32 fn_80141CBC(void *, void *, int, f32);
void debug_draw_sphere(const Vec *pos, const NJS_ARGB *color, f32 radius);
extern RecoveredGlobal_801959A0_lbl_804A7428 debug_color_purple_half_alpha;
extern const NJS_ARGB debug_color_green_half_alpha;
extern const f32 lbl_805DBEF8;
extern const f32 lbl_805DBEFC;
extern const f32 lbl_805DBF00;
void *TObjQuestColALock2__create(void *arg0);
void *__dt__18TObjQuestColALock2Fv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
void enable_action_input__10TObjPlayerFPv(void *p);
s32 submit_cursor_candidate(void *, s32);
void *get_player_by_client_id(s32 i);
s32 TWindowShortListCtrl__check_controller_button(void *, s32);
s32 __dl__7TObjectFPv(void *);
u8 *__dt__16TObjQuestColBaseFv(u8 *arg0, s16 arg1);
s32 check_flag_100__10TObjPlayerFPv();

extern void *quest_collision_task_root;

void *TObjQuestColALock2__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC4);
    if (o != NULL) {
        o = TObjQuestColALock2__ct((TObjQuestColALock2 *)((u8 *)o), (s32)quest_collision_task_root, (s32)arg0);
    }
    return o;
}

extern s32 controller_input_state[];
extern s32 local_client_id;

typedef char RecoveredGlobal_801959A0_lbl_804A7428_size[sizeof(RecoveredGlobal_801959A0_lbl_804A7428) == 0x10 ? 1 : -1];
void TObjQuestColALock2::update_room_id_check() {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r5;
    if (((VObj_18_26a62c *)(arg0))->m8(lbl_805DBEF8, lbl_805DBEFC) != 0) {
        debug_draw_sphere(&position, &debug_color_green_half_alpha, lbl_805DBF00 * *(f32 *)&this->unk_AC);
        temp_r5 = (u8 *)this->bodies;
        fn_80141CBC((u8 *)&this->position, &debug_color_purple_half_alpha.value, (int)temp_r5, (f32) (lbl_805DBF00 * *(f32 *)((s8 *)temp_r5 + 0xC)));
    }
}

u8 *TObjQuestColALock2__vt14(TObjQuestColALock2 *quest_col_a_lock2) {
    TQuestThread *thread;
    TQuestThreadBoard::destroy_board();
    thread = NULL;
    if ((u32) *(u32 *)((s8 *)quest_col_a_lock2 + 0xBC) != 0U) {
        thread = new TQuestThread(*(TObject **)((s8 *)quest_col_a_lock2 + 0xBC), quest_col_a_lock2->m_b0);
        if (thread != NULL) {
            thread->set_parent((TObject *)tl_00);
        }
    }
    return (u8 *)thread;
}

int TObjQuestColALock2::vfunc_15() {
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

void *__dt__18TObjQuestColALock2Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TObjQuestColALock2;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__16TObjQuestColBaseFv((u8 *)arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TObjQuestColALock2__ct(TObjQuestColALock2 *quest_col_a_lock2, s32 arg1, s32 _w2) {
    u8 *temp_r4;
    TObjQuestColBase__ct(quest_col_a_lock2, arg1);
    *(s32 **)((s8 *)quest_col_a_lock2 + 0x18) = &(*(RecoveredGlobal_80195BEC___vt__18TObjQuestColALock2 *)&__vt__18TObjQuestColALock2).value;
    *(s32 *)((s8 *)quest_col_a_lock2 + 0) = (s32) lbl_805D3408;
    init_collision_body_parts(quest_col_a_lock2, (s32) &TObjQuestColALock__collision_desc.value, 1);
    ((TObjCollidable *)quest_col_a_lock2)->set_indexed_flags(0, 0xF0);
    temp_r4 = (u8 *)quest_col_a_lock2->bodies;
    *(f32 *)((s8 *)temp_r4 + 4) = (f32) (*(f32 *)((s8 *)temp_r4 + 4) + quest_col_a_lock2->scale.y);
    ((TObjCollidable *)quest_col_a_lock2)->refresh_collision_body_centers();
    quest_col_a_lock2->actorFlags = (s32) (quest_col_a_lock2->actorFlags | 0x40000000);
    ((TObjPlayer *)quest_col_a_lock2)->register_object_by_id();
    quest_col_a_lock2->m_c0 = (s32) *(s32 *)((s8 *)quest_col_a_lock2 + 0x88);
    if ((s32) quest_col_a_lock2->m_c0 < 0) {
        quest_col_a_lock2->m_c0 = 0;
    }
    if ((s32) quest_col_a_lock2->m_c0 > 1) {
        quest_col_a_lock2->m_c0 = 1;
    }
    switch (quest_col_a_lock2->m_c0) {
    case 0:
        *(s32 *)((s8 *)quest_col_a_lock2 + 0xBC) = (s32) quest_mission_manager;
        break;
    case 1:
        *(s32 *)((s8 *)quest_col_a_lock2 + 0xBC) = (s32) quest_area_manager;
        break;
    default:
        *(s32 *)((s8 *)quest_col_a_lock2 + 0xBC) = 0;
        break;
    }
    return (u8 *)quest_col_a_lock2;
}

}
