#include "types.h"
#include "pso/system/vector.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TUnk_804B27D8.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TOHealGeneral.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {
void play_effect_default__10TObjPlayerFii(s32 arg0, s32 arg1);
void *get_player_by_client_id(s32);
extern s32 local_client_id;
u8 is_current_floor_switch_set(u16);
s32 is_any_player_within_radius_xz(u8 *self, f32 radius);

void TUnk_804B27D8::vfunc_16() {  }

void TUnk_804B27D8::vfunc_6(s16 *arg1, s32) {
    this->m_ac = (s32) *arg1;
}

void TOHealGeneral::accept_player(u16 arg1) {
    void *p;
    if (*(s32 *)((s8 *)this + 0xD8) > 0) {
        if (arg1 == local_client_id) {
            p = get_player_by_client_id(arg1);
            if (p == NULL || *(s32 *)&this->m_ac != 1) {
                return;
            }
            *(s32 *)&this->m_ac = 2;
            this->interactor = arg1;
            play_effect_default__10TObjPlayerFii((s32)p, -1);
        } else {
            this->interactor = 0xFFFF;
        }
    }
}

s32 TOHealGeneral::update_active_state() {

    switch (*(s32 *)&this->unk_C8) {
    case 1:
        if (is_any_player_within_radius_xz((u8 *)this, 4.9e+03f) != 0) {
            *(s32 *)&this->m_cc = 1;
        } else {
            *(s32 *)&this->m_cc = 0;
        }
        break;
    case 2:
        if (is_current_floor_switch_set((u16) *(s32 *)&this->_padD0) == 1) {
            *(s32 *)&this->m_cc = 1;
        } else {
            *(s32 *)&this->m_cc = 0;
        }
        break;
    }
    return *(s32 *)&this->m_cc;
}

void TOHealGeneral::set_enable_count(s32 arg1) {
    s32 var_r4;

    var_r4 = arg1;
    if (var_r4 < 0) {
        var_r4 = 0;
    }
    *(s32 *)((s8 *)this + 0xD8) = var_r4;
}

void TOHealGeneral::set_script_entry(s32 arg1) {
    s32 var_r4;

    var_r4 = arg1;
    if (var_r4 < 0) {
        var_r4 = 0;
    }
    *(s32 *)&this->m_d4 = var_r4;
}

s32 TOHealGeneral::update_heal_gauge_state() {
    s32 temp_r0;

    *(s32 *)&this->_padD0 = (s32) this->set_params[0];
    temp_r0 = *(s32 *)&this->_padD0;
    if (temp_r0 > 0xFF) {
        *(s32 *)&this->unk_C8 = 0;
    } else if (temp_r0 < 0) {
        *(s32 *)&this->unk_C8 = 1;
    } else {
        *(s32 *)&this->unk_C8 = 2;
    }
    set_script_entry((s32)this->set_params[1]);
    set_enable_count(this->set_params[2]);
    return *(s32 *)&this->_padD0;
}

}

struct Base { char pad[0x18]; };

struct VObj : Base {
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

extern "C" {
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
}
void draw_chunk_model(void *arg0);
extern "C" {
void draw_chunk_object(void *child);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
s32 submit_cursor_candidate(void *, int);
s32 check_player_flag1__6TLobbyFv();
void end_conversation_camera(void);
void begin_conversation_camera(void);
s32 is_any_player_within_radius_xz(u8 *self, f32 radius);
void *get_player_by_client_id(s32 i);
u8 *__ct__12TQuestThreadFv(u8 *arg0, s32 arg1, s32 arg2);
u32 __nw__7TObjectFUl(int);
extern s32 local_client_id;
extern u32 quest_mission_manager;
extern u32 quest_area_manager;
extern s32 tl_00;

void TUnk_804B27D8::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;
    f32 temp_f1;
    s32 temp_r0_2;
    s32 player;
    u32 temp_r3;
    u32 dc;
    u32 temp_r3_3;
    u32 temp_r3_4;
    u32 temp_r3_5;
    u32 var_r0;
    u32 var_r0_2;
    if (TObjPlayer::check_demo_mode() == 1) {
        this->vfunc_16();
        return;
    }
    switch (*(s32 *)&this->m_ac) {
    case 0:
        if ((this->update_active_state() != 0) && (is_any_player_within_radius_xz((arg0), 4.9e+03f) != 0) && ((s32) *(s32 *)&this->unk_D8 > 0)) {
            *(s32 *)&this->m_ac = 1;
        }
        break;
    case 1:
        submit_cursor_candidate(arg0, -1);
        break;
    case 2:
        if ((s32) this->interactor == (s32) local_client_id) {
            *(s32 *)&this->m_ac = 3;
            begin_conversation_camera();
            temp_r0_2 = this->m_d4;
            if ((temp_r0_2 >= 0x64) && (temp_r0_2 < 0x3E8) && ((u32) quest_mission_manager != 0U) && (((TObject *)quest_mission_manager)->all_parents_unqueued_for_destruction() != 0)) {
                temp_r3 = __nw__7TObjectFUl(0x194);
                var_r0 = temp_r3;
                if (var_r0 != 0U) {
                    var_r0 = (u32)__ct__12TQuestThreadFv((u8 *)temp_r3, (quest_mission_manager), (*(s32 *)&this->unk_D8));
                }
                this->m_dc = var_r0;
                dc = this->m_dc;
                if (dc != 0U) {
                    ((TObject *)dc)->set_parent((TObject *)tl_00);
                }
            } else if (((u32) quest_area_manager != 0U) && (((TObject *)quest_area_manager)->all_parents_unqueued_for_destruction() != 0)) {
                temp_r3_3 = __nw__7TObjectFUl(0x194);
                var_r0_2 = temp_r3_3;
                if (var_r0_2 != 0U) {
                    var_r0_2 = (u32)__ct__12TQuestThreadFv((u8 *)temp_r3_3, (quest_area_manager), (*(s32 *)&this->unk_D8));
                }
                this->m_dc = var_r0_2;
                temp_r3_4 = this->m_dc;
                if (temp_r3_4 != 0U) {
                    ((TObject *)temp_r3_4)->set_parent((TObject *)tl_00);
                }
            }
        } else {
            *(s32 *)&this->m_ac = 1;
            this->interactor = 0xFFFFU;
        }
        break;
    case 3:
        temp_r3_5 = this->m_dc;
        if (((temp_r3_5 != 0U) && (((TObject *)temp_r3_5)->all_parents_unqueued_for_destruction() == 0)) || ((u32) this->m_dc == 0U)) {
            *(s32 *)&this->m_ac = 0;
            this->m_dc = 0U;
            end_conversation_camera();
            if ((s32) this->interactor == (s32) local_client_id) {
                player = (s32)get_player_by_client_id((local_client_id));
                if ((player != 0) && (check_player_flag1__6TLobbyFv() != 0)) {
                    TObjPlayer::send_code_45_1(player);
                }
            }
        }
        break;
    }
    this->m_b0 += 1.0f;
    temp_f1 = *(f32 *)&this->m_b4;
    temp_f0 = this->m_b0;
    if (temp_f1 < temp_f0) {
        this->m_b0 = (f32) (temp_f0 - temp_f1);
    }
    this->vfunc_15();
}

#pragma push
#pragma fp_contract on
void TUnk_804B27D8::render() {
    u8 *arg0 = (u8 *)this;
    this->m_e0 = ((VObj *)arg0)->m8(this->m_c0, *(f32 *)&this->m_c4);
    if ((s32) this->m_e0 == 1) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texture_id);
        if ((s32) this->m_cc == 1) {
            void *p = *(void * *)&this->m_bc;
            if (p != NULL) {
                draw_model_motion(*(void * *)&this->model, p, this->m_b0);
            } else {
                draw_chunk_object(*(void * *)&this->model);
            }
        } else {
            draw_chunk_model((void *)(*(s32 *)((s8 *)(*(void * *)&this->model) + 4)));
        }
        pop_matrix();
    }
}
}
#pragma pop
