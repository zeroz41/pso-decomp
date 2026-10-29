#include "pso/protocol/subcommand_validation.h"

extern "C" {
s32 vec_has_nonfinite__FP3Vec(s32);
void *find_entity_by_id(u16 id);
s32 is_local__16G_ClientIDHeaderFUs(void *, u16);
}

s32 validate_6x21_inter_level_warp(G_ClientIDHeader *packet) {
    s32 temp_r0;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    temp_r0 = *(s32 *)((s8 *)packet + 4);
    if ((temp_r0 < 0) || (temp_r0 > 0x12)) {
        return 0;
    }
    return 1;
}

s32 validate_6x20_set_position(G_ClientIDHeader *packet) {
    s32 temp_r0;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    temp_r0 = *(s32 *)((s8 *)((u8*)packet) + 4);
    if ((temp_r0 < 0) || (temp_r0 > 0x12)) {
        return 0;
    }
    return ((u32)__cntlzw(vec_has_nonfinite__FP3Vec((s32)((u8*)packet + 8)))) >> 5;
}

s32 validate_6x1F_set_player_floor(G_ClientIDHeader *packet) {
    s32 temp_r0;
    if (is_local__16G_ClientIDHeaderFUs(packet, *(u16 *)((s8 *)packet + 2)) != 0) {
        return 0;
    }
    temp_r0 = *(s32 *)((s8 *)packet + 4);
    if ((temp_r0 < 0) || (temp_r0 > 0x12)) {
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

s32 validate_6x90_set_player_battle_team(G_ClientIDHeader *packet) {
    s32 temp_r0;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    temp_r0 = *(s32 *)((s8 *)packet + 4);
    if ((temp_r0 < 0) || (temp_r0 >= 0xD)) {
        return 0;
    }
    return 1;
}

s32 validate_6x8F_add_battle_damage_scores(G_ClientIDHeader *packet) {
    if (find_entity_by_id(*(u16 *)((s8 *)packet + 4)) == 0U) {
        return 0;
    }
    return ((u32) *(s16 *)((s8 *)packet + 6) >> 0x1FU) ^ 1;
}

s32 validate_6x1C_disable_pk_mode_for_player(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x1B_enable_pk_mode_for_player(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x9B_level_up_all_techniques(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    return (u8) *(u8 *)((s8 *)packet + 4) <= 0x1DU ? 1 : 0;
}

s32 validate_subcommand_client(G_ClientIDHeader *packet) {
    if (find_entity_by_id(packet->client_id) == 0U) {
        return 0;
    }
    return (u32) __cntlzw(is_local__16G_ClientIDHeaderFUs(packet, packet->client_id)) >> 5;
}
