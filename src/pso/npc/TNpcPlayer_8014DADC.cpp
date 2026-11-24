#include "types.h"
#include "pso/npc/TNpcPlayer_8014DADC.h"
#include "pso/render/render_util.h"
#include "pso/npc/TNpcPlayer.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/CapturedTargetList.h"
#include "pso/network/protocol/subcmd_6x.h"

extern "C" {
TObjCollidable *find_active_entity_by_id(u16 id);
s32 npc_counter_reset_if_reached(PartnerCounters *counters, s32 index, s32 limit);
s16 get_partner_counter(PartnerCounters *counters, s32 index);
void increment_partner_counter(PartnerCounters *counters, s32 index);
void reset_partner_counter(PartnerCounters *counters, s32 index);
void init_6x43_attack_packet(G_Attack_6x43_6x44_6x45 *cmd);
void init_6x44_attack_packet(G_Attack_6x43_6x44_6x45 *cmd);
void init_6x45_attack_packet(G_Attack_6x43_6x44_6x45 *cmd);
void set_technique_seed_level(PlayerTechniqueState *techniques, s16 technique, u8 level);
}
void set_partner_counter(saddr counters, s32 index, s16 value);

void TNpcPlayer::init_equipment() {
    TObjPlayer *player;
    s32 flags;

    flags = this->ai_params.technique_flags;
    player = this->self_view->player;
    if (flags & TECHNIQUE_FLAGS_FOIE_GIFOIE) {
        TObjPlayer::clamp_and_set_unit_value((saddr)player, this->ai_params.attack_technique_level, 0);
        TObjPlayer::clamp_and_set_unit_value((saddr)player, this->ai_params.attack_technique_level, 1);
        set_technique_seed_level(&player->technique_state, 0, this->ai_params.attack_technique_level);
        set_technique_seed_level(&player->technique_state, 1, this->ai_params.attack_technique_level);
    } else if (flags & TECHNIQUE_FLAGS_BARTA_GIBARTA) {
        TObjPlayer::clamp_and_set_unit_value((saddr)player, this->ai_params.attack_technique_level, 3);
        TObjPlayer::clamp_and_set_unit_value((saddr)player, this->ai_params.attack_technique_level, 4);
        set_technique_seed_level(&player->technique_state, 3, this->ai_params.attack_technique_level);
        set_technique_seed_level(&player->technique_state, 4, this->ai_params.attack_technique_level);
    } else if (flags & TECHNIQUE_FLAGS_ZONDE_RAZONDE) {
        TObjPlayer::clamp_and_set_unit_value((saddr)player, this->ai_params.attack_technique_level, 6);
        TObjPlayer::clamp_and_set_unit_value((saddr)player, this->ai_params.attack_technique_level, 8);
        set_technique_seed_level(&player->technique_state, 6, this->ai_params.attack_technique_level);
        set_technique_seed_level(&player->technique_state, 8, this->ai_params.attack_technique_level);
    }
    TObjPlayer::clamp_and_set_unit_value((saddr)player, this->ai_params.support_technique_level, 0xF);
    TObjPlayer::clamp_and_set_unit_value((saddr)player, this->ai_params.support_technique_level, 0x10);
    set_technique_seed_level(&player->technique_state, 0xF, this->ai_params.support_technique_level);
    set_technique_seed_level(&player->technique_state, 0x10, this->ai_params.support_technique_level);
}

void enable_quest_npc_visual() { quest_npc_visual_pending = 1; }

void TNpcPlayer::partner_request_technique_cast(s32 kind) { request_technique_cast(kind); }

void TNpcPlayer::send_partner_attack_stage_request() {
    G_Attack_6x43_6x44_6x45 cmd43;
    G_Attack_6x43_6x44_6x45 cmd44;
    G_Attack_6x43_6x44_6x45 cmd45;
    TObjPlayer *player;
    TObjCollidable *target;
    switch (get_partner_counter(&partner_counters, 1)) {
    case 0:
        init_6x43_attack_packet(&cmd43);
        if (self_view != NULL) {
            cmd43.header.client_id = self_view->get_client_id();
            cmd43.unknown_a2 = 0;
            target = find_active_entity_by_id(self_view->get_target_id());
            if (target != NULL) {
                cmd43.angle_y = calc_angle_to(&self_view->player->position, &target->position);
                player = self_view->player;
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->set_count(1);
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->entries[0].set_uid(self_view->get_target_id());
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->entries[0].set_collider_index(self_view->get_target_collider());
                ((TNpcPlayer *)&cmd43)->update_lobby();
                increment_partner_counter(&partner_counters, 1);
            }
        }
        break;
    case 1:
        init_6x44_attack_packet(&cmd44);
        if (self_view != NULL) {
            cmd44.header.client_id = self_view->get_client_id();
            cmd44.unknown_a2 = 1;
            target = find_active_entity_by_id(self_view->get_target_id());
            if (target != NULL) {
                cmd44.angle_y = calc_angle_to(&self_view->player->position, &target->position);
                player = self_view->player;
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->set_count(1);
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->entries[0].set_uid(self_view->get_target_id());
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->entries[0].set_collider_index(self_view->get_target_collider());
                ((TNpcPlayer *)&cmd44)->update_players();
                increment_partner_counter(&partner_counters, 1);
            }
        }
        break;
    case 2:
        init_6x45_attack_packet(&cmd45);
        if (self_view != NULL) {
            cmd45.header.client_id = self_view->get_client_id();
            cmd45.unknown_a2 = 1;
            target = find_active_entity_by_id(self_view->get_target_id());
            if (target != NULL) {
                cmd45.angle_y = calc_angle_to(&self_view->player->position, &target->position);
                player = self_view->player;
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->set_count(1);
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->entries[0].set_uid(self_view->get_target_id());
                ((CapturedTargetList *)((TObjPlayer *)&player->attack_state)->get_state_ptr())->entries[0].set_collider_index(self_view->get_target_collider());
                ((TNpcPlayer *)&cmd45)->update();
                reset_partner_counter(&partner_counters, 1);
                request_chatter(0xD);
            }
        }
        break;
    }
}

#pragma push
#pragma scheduling off
void TNpcPlayer::partner_request_physical_attack() {
    u32 prev_target;
    u32 target;
    prev_target = this->self_view->get_prev_target_id();
    target = this->self_view->get_target_id();
    if (target != prev_target) {
        set_partner_counter((saddr)&this->partner_counters, 1, 0);
    }
    npc_counter_reset_if_reached(&this->partner_counters, 1, 3);
    send_partner_attack_stage_request();
}
#pragma pop
