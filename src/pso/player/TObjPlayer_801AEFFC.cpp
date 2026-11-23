#include "pso/system/CharacterSaveRecordLookup.h"
#include "pso/player/TObjPlayer_80351748.h"
#include "types.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"
#include "pso/player/TObjPlayer.h"

#include "pso/technique/TTecCtrl.h"
#include "pso/object/base/TObjBase.h"

extern "C" {
s32 TObjPlayer__sub_801AF868(s32);
s32 check_flag_800000__10TObjPlayerFPv(s32);
void emit_idle_water_effect(saddr arg0);
int has_water_ground_flag(void *p);
void TObjPlayer__sub_801BEF60(void *p, s32 v);

s32 TObjPlayer::get_card_window_field_244() {
    return *(s32 *)((s8 *)(get_character_save_record((this->get_entity_id()))) + 0x244);
}

void TObjPlayer::init_local_pad_binding() {
    if (((s32)TObjPlayer::is_locally_controlled(this)) != 0) {
        init_pad_binding((u8 *)this + 0x550, (this->get_entity_id()), (int) ((s16) this->controller_port));
    }
}

void TObjPlayer::stop_force_if_alive() { if (TObjPlayer::is_locally_controlled(this) != 0) { TObjPlayer__sub_801BEF60((char*)this + 0x550, (saddr)(0)); } }
void TObjPlayer::update_battle_control_if_unlocked() { if (this->is_body_collision_inactive() == 0) { ((TObjPlayer *)((char*)this + 0x384))->prepare_heavy_attack_particles_default(); } }

void TObjPlayer::enemy_spawn_zalure_effect() {
    if (this->is_body_collision_inactive() != 0 || check_flag_800000__10TObjPlayerFPv((saddr)this) != 0) {
        return;
    }
    ((TObjPlayer *)(((u8 *)this) + 0x384))->emit_zalure_support_effect_at();
}

void TObjPlayer::trigger_switch_attack() {
    if (this->is_body_collision_inactive() != 0 || check_flag_800000__10TObjPlayerFPv((saddr)this) != 0) {
        return;
    }
    ((TObjPlayer *)(((u8 *)this) + 0x384))->emit_deband_support_effect_at();
}

void TObjPlayer::enemy_spawn_jellen_effect() {
    if (this->is_body_collision_inactive() != 0 || check_flag_800000__10TObjPlayerFPv((saddr)this) != 0) {
        return;
    }
    ((TObjPlayer *)(((u8 *)this) + 0x384))->emit_jellen_support_effect_default();
}
void TObjPlayer::apply_switch_attack() {
    if (this->is_body_collision_inactive() != 0 || check_flag_800000__10TObjPlayerFPv((saddr)this) != 0) {
        return;
    }
    ((TObjPlayer *)(((u8 *)this) + 0x384))->emit_shifta_support();
}

}

#include "pso/ui/hud/TRaderMapCore.h"

void TObjPlayer::update_movement_effects() {
    saddr player = (saddr)this;
    if ((TTecCtrl::is_technique_ready() != 0) && (TObjPlayer__sub_801AF868(player) == 0) && (((TObjPlayer *)player)->update_movement_by_screen() != 0) && (((TObjPlayer *)player)->test_action_mask(0x408000) == 0) && (((TObjPlayer *)player)->is_body_collision_inactive() == 0) && (check_flag_800000__10TObjPlayerFPv(player) == 0)) {
        ((TObjPlayer *)(player + 0x384))->emit_movement_effect_at();
    }
    if ((((TObjPlayer *)player)->is_body_collision_inactive() == 0) && (((TObjPlayer *)player)->test_action_mask(2) != 0) && (has_water_ground_flag((void *)(player + 0x360)) != 0)) {
        emit_idle_water_effect(player + 0x384);
    }
}
int TObjPlayer::get_max_level() { return 199; }
