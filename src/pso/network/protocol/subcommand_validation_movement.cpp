#include "pso/network/protocol/subcommand_validation.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/render/render_util.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/network/protocol/subcmd_6x.h"

s32 validate_6x21_inter_level_warp(G_InterLevelWarp_6x21 *packet) {
    s32 floor;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    floor = packet->floor;
    if ((floor < 0) || (floor > 0x12)) {
        return 0;
    }
    return 1;
}

s32 validate_6x20_set_position(G_SetPosition_6x20 *packet) {
    s32 floor;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    floor = packet->floor;
    if ((floor < 0) || (floor > 0x12)) {
        return 0;
    }
    return vec_has_nonfinite(&packet->pos) ? 0 : 1;
}

s32 validate_6x1F_set_player_floor(G_SetPlayerFloor_6x1F *packet) {
    s32 floor;
    if (packet->header.is_local(packet->header.client_id) != 0) {
        return 0;
    }
    floor = packet->floor;
    if ((floor < 0) || (floor > 0x12)) {
        return 0;
    }
    return 1;
}

s32 validate_6x82_enable_drop_weapon_on_death(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x81_disable_drop_weapon_on_death(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x7B_disable_stealth_suit_effect(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x7A_enable_stealth_suit_effect(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x90_set_player_battle_team(G_SetPlayerBattleTeam_6x90 *packet) {
    s32 team;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    team = packet->team_number;
    if ((team < 0) || (team >= 0xD)) {
        return 0;
    }
    return 1;
}

s32 validate_6x8F_add_battle_damage_scores(G_AddBattleDamageScores_6x8F *packet) {
    if (find_entity_by_id(packet->target_entity_id) == 0U) {
        return 0;
    }
    return packet->amount < 0 ? 0 : 1;
}

s32 validate_6x1C_disable_pk_mode_for_player(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x1B_enable_pk_mode_for_player(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x9B_level_up_all_techniques(G_LevelUpAllTechniques_6x9B *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    return packet->num_levels <= 0x1D ? 1 : 0;
}

s32 validate_subcommand_client(G_ClientIDHeader *packet) {
    if (find_entity_by_id(packet->client_id) == 0U) {
        return 0;
    }
    return (u32) __cntlzw(packet->is_local(packet->client_id)) >> 5;
}

#pragma push
#pragma opt_common_subs off
s32 validate_attack_target_count(s32 *count) {
    u8 valid = 0;
    if (*count >= 0 && *count <= 10) {
        valid = 1;
    }
    return valid;
}
#pragma pop
