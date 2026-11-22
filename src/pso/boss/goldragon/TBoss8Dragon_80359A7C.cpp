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
extern s32 TBoss8Dragon__data_805D69B8;

void TUnk_804F1A78::run_task() {
    u8 *boss8_dragon = (u8 *)this;
    s16 temp_r0;
    s32 temp_r0_2;
    s32 temp_r30;
    s32 temp_r30_2;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    if (*(s32 *)((s8 *)boss8_dragon + 0x3C0) & 8) {
        ((TObjEnemy *)boss8_dragon)->send_entity_set_flags();
        ((TObject *)boss8_dragon)->queue_destruction();
        return;
    }
    if ((s32) *(s32 *)((s8 *)boss8_dragon + 0x74C) != 0) {
        ((TBoss8Dragon *)boss8_dragon)->freeze_player_at_self();
        *(s32 *)((s8 *)boss8_dragon + 0x754) = (s32) (*(s32 *)((s8 *)boss8_dragon + 0x754) + 1);
    } else if ((TObjEneDD::is_main_phase_15() != 0) && ((s32) *(s32 *)((s8 *)boss8_dragon + 0x6D4) == 0)) {
        temp_r30 = *(s32 *)((s8 *)boss8_dragon + 0x3E0);
        if (((TObjEneDD *)boss8_dragon)->update_lobby_state() != 0) {
            *(s32 *)((s8 *)boss8_dragon + 0x3E0) = 0;
            if ((s32) *(s32 *)((s8 *)boss8_dragon + 0x3E0) != temp_r30) {
                *(s32 *)((s8 *)boss8_dragon + 0x8A0) = 1;
            }
        } else {
            *(s32 *)((s8 *)boss8_dragon + 0x3E0) = 1;
        }
    }
    temp_r30_2 = TObjEneDD::query_teammate_state();
    this->update_attack_stat_status();
    this->update_defense_stat_status();
    if (temp_r30_2 == 0) {
        temp_r0 = this->mode;
        if ((temp_r0 == 0x15) || (temp_r0 == 0x17)) {
            *(s32 *)((s8 *)boss8_dragon + 0x30) = (s32) (*(s32 *)((s8 *)boss8_dragon + 0x30) | 0x800);
        } else {
            *(s32 *)((s8 *)boss8_dragon + 0x30) = (s32) (*(s32 *)((s8 *)boss8_dragon + 0x30) & 0xFFFFF7FF);
        }
        if ((s32) *(s32 *)((s8 *)boss8_dragon + 0x74C) != 0) {
            if ((s32) *(u16 *)((s8 *)boss8_dragon + 0x750) == (s32) local_client_id) {
                if ((s32) TBoss8Dragon__data_805D69B8 == 0) {
                    ((TBoss8Dragon *)boss8_dragon)->release_grabbed_player();
                } else {
                    ((TBoss8Dragon *)boss8_dragon)->check_death();
                }
                this->dispatch_action(this->mode, 8);
                this->dispatch_action(this->mode, 0);
            } else {
                if ((s32) TBoss8Dragon__data_805D69B8 == 0) {
                    ((TBoss8Dragon *)boss8_dragon)->release_grabbed_player();
                }
                this->dispatch_action(this->mode, 0);
            }
        } else {
            temp_r0_2 = *(s32 *)((s8 *)boss8_dragon + 0x3E0);
            if (temp_r0_2 != 1) {
                if (temp_r0_2 == 2) {
                    this->dispatch_action(this->mode, 2);
                } else {
                    ((TBoss8Dragon *)boss8_dragon)->select_next_action();
                }
                this->dispatch_action(this->mode, 8);
                this->dispatch_action(this->mode, 0);
            } else {
                this->dispatch_action(this->mode, 0);
            }
        }
    }
    ((TObjEneDD *)boss8_dragon)->sub_800BBA0C();
    this->update_body_colliders();
    ((TBoss8Dragon *)boss8_dragon)->store_position();
    ((TObjEnemy *)boss8_dragon)->submit_default_cursor_candidate();
    add_radar_scaled_marker(&this->position, -0x5DB4, 1, 1, 2.0f);
    if (temp_r30_2 == 0) {
        this->sub_tasks.run_tasks();
    }
    project_sound_origin_from_camera((saddr)(boss8_dragon + 0x38), (u8 *)(boss8_dragon + 0x634), 0.4f);
}

TUnk_804F1A78::~TUnk_804F1A78() {}

TUnk_804F1A78::TUnk_804F1A78(TObject *parent, void *set_data, s32 hp) : TBoss8Dragon(parent, set_data) {
    this->flags |= 0x40;
    this->finalHpThreshold = -1;
    this->hp = hp;
    this->hpmax = hp;
}

}
