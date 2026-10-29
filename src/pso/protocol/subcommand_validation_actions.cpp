#include "pso/protocol/subcommand_validation.h"
#include "pso/render/render_util.h"
#include "pso/protocol/subcommand_validation_actions.h"
#include "pso/misc/TLobby.h"

extern "C" {
s32 is_action_id_none(s16);
s32 fn_800FD7C0(void *);

s32 validate_6xAB(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    if (((is_action_id_none(*(s16 *)((s8 *)packet + 4)) == 0) && (*(s16 *)((s8 *)packet + 4) < 0)) || (*(s16 *)((s8 *)packet + 4) >= TLobby::get_hold_effect_size_by_type())) {
        return 0;
    }
    return 1;
}

s32 validate_6x58_lobby_animation(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    if (((is_action_id_none(*(s16 *)((s8 *)packet + 4)) == 0) && (*(s16 *)((s8 *)packet + 4) < 0)) || (*(s16 *)((s8 *)packet + 4) >= TLobby::get_hold_effect_size_by_type())) {
        return 0;
    }
    return 1;
}

s32 validate_6x57(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x56_set_player_position_and_angle(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    return vec_has_nonfinite((Vec *)((u8 *)packet + 8)) ? 0 : 1;
}

s32 validate_6x55_intra_map_warp(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    if (vec_has_nonfinite((Vec *)((u8 *)packet + 8)) != 0) {
        return 0;
    }
    return vec_has_nonfinite((Vec *)((u8 *)packet + 0x14)) ? 0 : 1;
}

s32 validate_6x53(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x52_set_animation_state(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    if (((is_action_id_none(*(s16 *)((s8 *)packet + 4)) == 0) && (*(s16 *)((s8 *)packet + 4) < 0)) || (*(s16 *)((s8 *)packet + 4) >= TLobby::get_hold_effect_size_by_type())) {
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

s32 validate_6x4C_hit_by_enemy(G_ClientIDHeader *packet) {
    s16 v;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    v = *(s16 *)((s8 *)((u8*)packet) + 6);
    if (v < 0) {
        return 0;
    }
    return (u32) __cntlzw(fn_800FD7C0((u8*)packet + 8)) >> 5;
}

s32 validate_6x4B_hit_by_enemy(G_ClientIDHeader *packet) {
    s16 v;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    v = *(s16 *)((s8 *)((u8*)packet) + 6);
    if (v < 0) {
        return 0;
    }
    return (u32) __cntlzw(fn_800FD7C0((u8*)packet + 8)) >> 5;
}

s32 validate_6x4A_shield_attack(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}
}
