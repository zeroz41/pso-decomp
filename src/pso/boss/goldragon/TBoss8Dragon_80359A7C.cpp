#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/TObjEnemy.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_80359A7C.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/hud/TRaderMapCore.h"


extern "C" {
extern s32 local_client_id;
extern s32 boss8_dragon_player_control;

void TUnk_804F1A78::run_task() {
    s16 mode;
    s32 state;
    s32 old_state;
    s32 teammate_state;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    if (this->flags & 8) {
        this->send_entity_set_flags();
        this->TObject::queue_destruction();
        return;
    }
    if (this->m_74c != 0) {
        this->freeze_player_at_self();
        this->m_754 = this->m_754 + 1;
    } else if ((TObjEneDD::is_main_phase_15() != 0) && (this->m_6d4 == 0)) {
        old_state = this->m_3e0;
        if (this->update_lobby_state() != 0) {
            this->m_3e0 = 0;
            if (this->m_3e0 != old_state) {
                this->m_8a0 = 1;
            }
        } else {
            this->m_3e0 = 1;
        }
    }
    teammate_state = TObjEneDD::query_teammate_state();
    this->update_attack_stat_status();
    this->update_defense_stat_status();
    if (teammate_state == 0) {
        mode = this->mode;
        if ((mode == 0x15) || (mode == 0x17)) {
            this->actorFlags |= 0x800;
        } else {
            this->actorFlags &= ~0x800;
        }
        if (this->m_74c != 0) {
            if (this->m_750 == local_client_id) {
                if (boss8_dragon_player_control == 0) {
                    this->release_grabbed_player();
                } else {
                    this->check_death();
                }
                this->dispatch_action(this->mode, 8);
                this->dispatch_action(this->mode, 0);
            } else {
                if (boss8_dragon_player_control == 0) {
                    this->release_grabbed_player();
                }
                this->dispatch_action(this->mode, 0);
            }
        } else {
            state = this->m_3e0;
            if (state != 1) {
                if (state == 2) {
                    this->dispatch_action(this->mode, 2);
                } else {
                    this->select_next_action();
                }
                this->dispatch_action(this->mode, 8);
                this->dispatch_action(this->mode, 0);
            } else {
                this->dispatch_action(this->mode, 0);
            }
        }
    }
    this->sub_800BBA0C();
    this->update_body_colliders();
    this->store_position();
    this->submit_default_cursor_candidate();
    add_radar_scaled_marker(&this->position, -0x5DB4, 1, 1, 2.0f);
    if (teammate_state == 0) {
        this->sub_tasks.run_tasks();
    }
    project_sound_origin_from_camera((saddr)&this->position, (u8 *)&this->sound_origin, 0.4f);
}

TUnk_804F1A78::~TUnk_804F1A78() {}

TUnk_804F1A78::TUnk_804F1A78(TObject *parent, void *set_data, s32 hp) : TBoss8Dragon(parent, set_data) {
    this->flags |= 0x40;
    this->finalHpThreshold = -1;
    this->hp = hp;
    this->hpmax = hp;
}

}
