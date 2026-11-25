#include "pso/network/protocol/subcommand_validation.h"
#include "pso/render/render_util.h"
#include "pso/player/PlayerActionProvider.h"
#include "pso/network/protocol/subcmd_6x.h"

extern "C" s32 is_action_id_none(s16);
extern "C" s32 fn_800FD7C0(f32 *xz);

s32 validate_6xAB(G_CreateLobbyChair_6xAB *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    if (((is_action_id_none(packet->animation_number) == 0) && (packet->animation_number < 0)) || (packet->animation_number >= get_player_action_motion_count())) {
        return 0;
    }
    return 1;
}

s32 validate_6x58_lobby_animation(G_LobbyAnimation_6x58 *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    if (((is_action_id_none(packet->animation_number) == 0) && (packet->animation_number < 0)) || (packet->animation_number >= get_player_action_motion_count())) {
        return 0;
    }
    return 1;
}

s32 validate_6x57(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x56_set_player_position_and_angle(G_SetPlayerPositionAndAngle_6x56 *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    return vec_has_nonfinite(&packet->pos) ? 0 : 1;
}

s32 validate_6x55_intra_map_warp(G_IntraMapWarp_6x55 *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    if (vec_has_nonfinite(&packet->from_pos) != 0) {
        return 0;
    }
    return vec_has_nonfinite(&packet->pos) ? 0 : 1;
}

s32 validate_6x53(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x52_set_animation_state(G_SetAnimationState_6x52 *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    if (((is_action_id_none(packet->animation) == 0) && (packet->animation < 0)) || (packet->animation >= get_player_action_motion_count())) {
        return 0;
    }
    return 1;
}

s32 validate_6x50_switch_interaction(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x4F_player_revived(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x4E_player_revivable(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x89_set_killer_entity_id(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x4D_player_died(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x4C_hit_by_enemy(G_HitByEnemy_6x4B_6x4C *packet) {
    s16 hp;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    hp = packet->current_hp;
    if (hp < 0) {
        return 0;
    }
    return (u32) __cntlzw(fn_800FD7C0(packet->velocity.xz)) >> 5;
}

s32 validate_6x4B_hit_by_enemy(G_HitByEnemy_6x4B_6x4C *packet) {
    s16 hp;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    hp = packet->current_hp;
    if (hp < 0) {
        return 0;
    }
    return (u32) __cntlzw(fn_800FD7C0(packet->velocity.xz)) >> 5;
}

s32 validate_6x4A_shield_attack(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}
