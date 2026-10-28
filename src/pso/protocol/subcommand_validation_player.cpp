#include "pso/protocol/subcommand_validation.h"
#include "types.h"
#include "pso/protocol/subcmd_6x.h"
#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
s32 is_in_view__17TObjEneHoldEffectFv(s32);
s32 is_camera_visible__17TObjEneHoldEffectFv(s32);

u16 TObjRoomId__sub_801A1DB8(u16);
void *find_entity_by_id(u16 id);

s32 validate_attack_target_entry(void *parameters) {
    return ((u32) *(s16 *)((s8 *)parameters + 2) >> 0x1FU) ^ 1;
}

s32 validate_6x45_attack(G_ClientIDHeader *packet) {
    s16 temp_r3;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    temp_r3 = *(s16 *)((s8 *)packet + 6);
    if ((temp_r3 < 0) || (temp_r3 >= 3)) {
        return 0;
    }
    return 1;
}

s32 validate_6x44_attack(G_ClientIDHeader *packet) {
    s16 temp_r3;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    temp_r3 = *(s16 *)((s8 *)packet + 6);
    if ((temp_r3 < 0) || (temp_r3 >= 3)) {
        return 0;
    }
    return 1;
}

s32 validate_6x43_attack(G_ClientIDHeader *packet) {
    s16 temp_r3;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    temp_r3 = *(s16 *)((s8 *)packet + 6);
    if ((temp_r3 < 0) || (temp_r3 >= 3)) {
        return 0;
    }
    return 1;
}

s32 validate_6x42_move_to_position(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    return (u32) __cntlzw(is_camera_visible__17TObjEneHoldEffectFv((s32)packet + 4)) >> 5;
}

s32 validate_6x40_walk_to_position(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    return (u32)__cntlzw(is_camera_visible__17TObjEneHoldEffectFv((s32)packet + 4)) >> 5;
}

s32 validate_6x3F_set_position(G_ClientIDHeader *packet) {
    s16 temp_r3;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    temp_r3 = *(s16 *)((s8 *)((u8*)packet) + 4);
    if ((temp_r3 < 0) || (temp_r3 >= 2)) {
        return 0;
    }
    if ((s16) *(s16 *)((s8 *)((u8*)packet) + 8) > 0x12) {
        return 0;
    }
    return (u32)__cntlzw(is_in_view__17TObjEneHoldEffectFv((s32)((u8*)packet + 0xC))) >> 5;
}

s32 validate_6x3E_stop_at_position(G_ClientIDHeader *packet) {
    s16 temp_r3;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    temp_r3 = *(s16 *)((s8 *)((u8*)packet) + 4);
    if ((temp_r3 < 0) || (temp_r3 >= 2)) {
        return 0;
    }
    if ((s16) *(s16 *)((s8 *)((u8*)packet) + 8) > 0x12) {
        return 0;
    }
    return (u32)__cntlzw(is_in_view__17TObjEneHoldEffectFv((s32)((u8*)packet + 0xC))) >> 5;
}

s32 validate_6x88_restore_shrunken_player(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x87_shrink_player(G_ClientIDHeader *packet) {
    f32 temp_f1;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    temp_f1 = *(f32 *)((s8 *)packet + 4);
    if ((temp_f1 < 0.0f) || (temp_f1 > 1e+01f)) {
        return 0;
    }
    return 1;
}
}

s32 validate_6x83_place_trap(G_ClientIDHeader *packet) {
    s16 temp_r3;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    temp_r3 = *(s16 *)((s8 *)packet + 4);
    if ((temp_r3 < 0) || (temp_r3 >= 4)) {
        return 0;
    }
    return ((u32) *(s16 *)((s8 *)packet + 6) >> 0x1FU) ^ 1;
}

s32 validate_6x3B_clear_temporary_photon_blast_state_flags(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x3A_clear_photon_blast_ready_flag(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x39_set_photon_blast_ready_flag(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x38_donate_to_photon_blast(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    return (u32) __cntlzw(TObjRoomId__sub_801A1DB8(*(u16 *)((s8 *)packet + 4))) >> 5;
}

s32 validate_6x37_photon_blast(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    return ((u32) *(s16 *)((s8 *)packet + 4) >> 0x1FU) ^ 1;
}

s32 validate_6x33_revive_player(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    return (u32) __cntlzw(TObjRoomId__sub_801A1DB8(*(u16 *)((s8 *)packet + 4))) >> 5;
}

s32 validate_6xA1_revive_player_v3(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x31_use_medical_center(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x30_change_player_level(G_ClientIDHeader *packet) {
    s16 temp_r3;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    if (*(s16 *)((s8 *)packet + 4) < 0) {
        return 0;
    }
    if (*(s16 *)((s8 *)packet + 6) < 0) {
        return 0;
    }
    if (*(s16 *)((s8 *)packet + 8) < 0) {
        return 0;
    }
    if (*(s16 *)((s8 *)packet + 0xA) < 0) {
        return 0;
    }
    if (*(s16 *)((s8 *)packet + 0xC) < 0) {
        return 0;
    }
    if (*(s16 *)((s8 *)packet + 0xE) < 0) {
        return 0;
    }
    if (*(s16 *)((s8 *)packet + 0x10) < 0) {
        return 0;
    }
    temp_r3 = *(s16 *)((s8 *)packet + 0x12);
    if ((temp_r3 < 0) || (temp_r3 >= 2)) {
        return 0;
    }
    return 1;
}

s32 validate_6x2F_change_player_hp(G_ClientIDHeader *packet) {
    s32 temp_r0;
    temp_r0 = *(s32 *)((s8 *)packet + 4);
    if ((temp_r0 < 0) || (temp_r0 >= 3)) {
        return 0;
    }
    if (*(s16 *)((s8 *)packet + 8) < 0) {
        return 0;
    }
    if (find_entity_by_id(*(u16 *)((s8 *)packet + 0xA)) == 0U) {
        return 0;
    }
    return (u32) __cntlzw((u32) TObjRoomId__sub_801A1DB8(*(u16 *)((s8 *)packet + 0xA))) >> 5;
}

s32 validate_6x2E_set_or_clear_player_flags(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x2D_release_hold(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x2C_impose_hold(G_ClientIDHeader *packet) {
    u32 cond;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    if (is_camera_visible__17TObjEneHoldEffectFv((s32)((u8*)packet + 8)) != 0) {
        return 0;
    }
    cond = (*(f32 *)((s8 *)((u8*)packet) + 0x10) < 0.0f);
    return (u32)__cntlzw(cond) >> 5;
}

s32 validate_6x2B_create_inventory_item(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x2A_drop_item(G_ClientIDHeader *packet) {
    s16 temp_r3;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    if (*(s16 *)((s8 *)((u8*)packet) + 4) < 0) {
        return 0;
    }
    temp_r3 = *(s16 *)((s8 *)((u8*)packet) + 6);
    if ((temp_r3 < 0) || (temp_r3 > 0x12)) {
        return 0;
    }
    return (u32)__cntlzw(is_in_view__17TObjEneHoldEffectFv((s32)((u8*)packet + 0xC))) >> 5;
}

s32 validate_6xAC(G_ClientIDHeader *packet) {
    s32 temp_r0;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    temp_r0 = *(s32 *)((s8 *)packet + 4);
    if ((temp_r0 < 0) || (temp_r0 > 0x1E)) {
        return 0;
    }
    return 1;
}

s32 validate_6x29_delete_inventory_item(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x28_feed_mag(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x27_use_item(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x26_unequip_item(G_ClientIDHeader *packet) {
    s32 temp_r0;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    temp_r0 = *(s32 *)((s8 *)packet + 8);
    if ((temp_r0 < 0) || (temp_r0 >= 0xD)) {
        return 0;
    }
    return 1;
}

s32 validate_6x25_equip_item(G_ClientIDHeader *packet) {
    s32 temp_r0;
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    temp_r0 = *(s32 *)((s8 *)packet + 8);
    if ((temp_r0 < 0) || (temp_r0 >= 0xD)) {
        return 0;
    }
    return 1;
}

s32 validate_6x24_teleport_player(G_ClientIDHeader *packet) {
    if (validate_subcommand_client(packet) == 0) {
        return 0;
    }
    return (u32)__cntlzw(is_in_view__17TObjEneHoldEffectFv((s32)packet + 8)) >> 5;
}

s32 validate_6x23_set_player_visible(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x22_set_player_invisible(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

struct LobbyAnimationState { G_ClientIDHeader header; s16 animation_number; u16 unused; u32 player_flags; f32 animation_timer; };

extern "C" {
s32 is_local__16G_ClientIDHeaderFUs(void *, u16);
s32 get_player_by_client_id(u16);
s32 is_action_id_none(s16);

s32 validate_6xAE_set_animation_state(LobbyAnimationState *arg0);
s32 validate_6xAE_set_animation_state(LobbyAnimationState *arg0) {
    s32 player;
    player = get_player_by_client_id(arg0->header.client_id);
    if (player == 0) {
        return 0;
    }
    if (is_local__16G_ClientIDHeaderFUs(arg0, arg0->header.client_id) != 0) {
        return 0;
    }
    if (((is_action_id_none(arg0->animation_number) == 0) && (arg0->animation_number < 0)) || (arg0->animation_number >= TLobby::get_hold_effect_size_by_type())) {
        return 0;
    }
    if ((arg0->animation_timer < 0.0f) || (arg0->animation_timer >= ((TObjPlayer *)player)->get_table_value_f32(arg0->animation_number))) {
        return 0;
    }
    return 1;
}

}
