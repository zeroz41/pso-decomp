#include "pso/network/protocol/subcommand_validation.h"
#include "pso/object/TObjRoomId.h"
#include "pso/network/protocol/subcommand_validation_player.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/render/render_util.h"
#include "types.h"
#include "pso/unk/TLobby_800FD78C.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/PlayerScaleState.h"
#include "pso/player/PlayerActionProvider.h"


s32 validate_attack_target_entry(void *parameters) {
    return ((u32) *(s16 *)((s8 *)parameters + 2) >> 0x1FU) ^ 1;
}

s32 validate_6x45_attack(G_Attack_6x43_6x44_6x45 *packet) {
    s16 action_type;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    action_type = packet->action_type;
    if ((action_type < 0) || (action_type >= 3)) {
        return 0;
    }
    return 1;
}

s32 validate_6x44_attack(G_Attack_6x43_6x44_6x45 *packet) {
    s16 action_type;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    action_type = packet->action_type;
    if ((action_type < 0) || (action_type >= 3)) {
        return 0;
    }
    return 1;
}

s32 validate_6x43_attack(G_Attack_6x43_6x44_6x45 *packet) {
    s16 action_type;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    action_type = packet->action_type;
    if ((action_type < 0) || (action_type >= 3)) {
        return 0;
    }
    return 1;
}

s32 validate_6x42_move_to_position(G_MoveToPosition_6x41_6x42 *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    return (u32) __cntlzw(has_nonfinite_position(&packet->pos.x)) >> 5;
}

s32 validate_6x40_walk_to_position(G_WalkToPosition_6x40 *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    return (u32)__cntlzw(has_nonfinite_position(&packet->pos.x)) >> 5;
}

s32 validate_6x3F_set_position(G_SetPosition_6x3F *packet) {
    s16 is_near_enemy;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    is_near_enemy = packet->is_near_enemy;
    if ((is_near_enemy < 0) || (is_near_enemy >= 2)) {
        return 0;
    }
    if (packet->floor > 0x12) {
        return 0;
    }
    return vec_has_nonfinite(&packet->pos) ? 0 : 1;
}

s32 validate_6x3E_stop_at_position(G_StopAtPosition_6x3E *packet) {
    s16 is_near_enemy;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    is_near_enemy = packet->is_near_enemy;
    if ((is_near_enemy < 0) || (is_near_enemy >= 2)) {
        return 0;
    }
    if (packet->floor > 0x12) {
        return 0;
    }
    return vec_has_nonfinite(&packet->pos) ? 0 : 1;
}
s32 validate_6x88_restore_shrunken_player(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x87_shrink_player(PlayerShrinkPacket *packet) {
    f32 scalar;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    scalar = packet->scalar;
    if ((scalar < 0.0f) || (scalar > 1e+01f)) {
        return 0;
    }
    return 1;
}

s32 validate_6x83_place_trap(G_PlaceTrap_6x83 *packet) {
    s16 trap_type;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    trap_type = packet->trap_type;
    if ((trap_type < 0) || (trap_type >= 4)) {
        return 0;
    }
    return ((u32) packet->trap_index >> 0x1FU) ^ 1;
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

s32 validate_6x38_donate_to_photon_blast(G_DonateToPhotonBlast_6x38 *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    return (u32) __cntlzw(get_entity_id_kind(packet->target_client_id)) >> 5;
}

s32 validate_6x37_photon_blast(G_PhotonBlast_6x37 *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    return ((u32) packet->amount >> 0x1FU) ^ 1;
}

s32 validate_6x33_revive_player(G_RevivePlayer_6x33 *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    return (u32) __cntlzw(get_entity_id_kind(packet->client_id2)) >> 5;
}

s32 validate_6xA1_revive_player_v3(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x31_use_medical_center(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x30_change_player_level(G_ChangePlayerLevel_6x30 *packet) {
    s16 is_level_down;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    if (packet->atp < 0) {
        return 0;
    }
    if (packet->mst < 0) {
        return 0;
    }
    if (packet->evp < 0) {
        return 0;
    }
    if (packet->hp < 0) {
        return 0;
    }
    if (packet->dfp < 0) {
        return 0;
    }
    if (packet->ata < 0) {
        return 0;
    }
    if (packet->level < 0) {
        return 0;
    }
    is_level_down = packet->is_level_down;
    if ((is_level_down < 0) || (is_level_down >= 2)) {
        return 0;
    }
    return 1;
}

s32 validate_6x2F_change_player_hp(G_ChangePlayerHP_6x2F *packet) {
    s32 type;
    type = packet->type;
    if ((type < 0) || (type >= 3)) {
        return 0;
    }
    if (packet->amount < 0) {
        return 0;
    }
    if (find_entity_by_id(packet->client_id) == 0U) {
        return 0;
    }
    return (u32) __cntlzw((u32) get_entity_id_kind(packet->client_id)) >> 5;
}

s32 validate_6x2E_set_or_clear_player_flags(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x2D_release_hold(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x2C_impose_hold(G_ImposeHold_6x2C *packet) {
    u32 cond;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    if (has_nonfinite_position(&packet->pos.x) != 0) {
        return 0;
    }
    cond = (packet->trigger_radius2 < 0.0f);
    return (u32)__cntlzw(cond) >> 5;
}

s32 validate_6x2B_create_inventory_item(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x2A_drop_item(G_DropItem_6x2A *packet) {
    s16 floor;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    if (packet->amount < 0) {
        return 0;
    }
    floor = packet->floor;
    if ((floor < 0) || (floor > 0x12)) {
        return 0;
    }
    return vec_has_nonfinite(&packet->pos) ? 0 : 1;
}

s32 validate_6xAC(G_DeleteMultipleInventoryItems_6xAC *packet) {
    s32 num_items;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    num_items = packet->num_items;
    if ((num_items < 0) || (num_items > 0x1E)) {
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

s32 validate_6x26_unequip_item(G_UnequipItem_6x26 *packet) {
    s32 equip_slot;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    equip_slot = packet->equip_slot;
    if ((equip_slot < 0) || (equip_slot >= 0xD)) {
        return 0;
    }
    return 1;
}

s32 validate_6x25_equip_item(G_EquipItem_6x25 *packet) {
    s32 equip_slot;
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    equip_slot = packet->equip_slot;
    if ((equip_slot < 0) || (equip_slot >= 0xD)) {
        return 0;
    }
    return 1;
}

s32 validate_6x24_teleport_player(G_TeleportPlayer_6x24 *packet) {
    if (validate_subcommand_client(&packet->header) == 0) {
        return 0;
    }
    return vec_has_nonfinite(&packet->pos) ? 0 : 1;
}

s32 validate_6x23_set_player_visible(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

s32 validate_6x22_set_player_invisible(G_ClientIDHeader *packet) {
    return validate_subcommand_client(packet) ? 1 : 0;
}

struct LobbyAnimationState { G_ClientIDHeader header; s16 animation_number; u16 unused; u32 player_flags; f32 animation_timer; };

extern "C" {
s32 validate_6xAE_set_animation_state(LobbyAnimationState *arg0);
s32 validate_6xAE_set_animation_state(LobbyAnimationState *arg0) {
    saddr player;
    player = (saddr)get_player_by_client_id(arg0->header.client_id);
    if (player == 0) {
        return 0;
    }
    if (((G_ClientIDHeader *)arg0)->is_local(arg0->header.client_id) != 0) {
        return 0;
    }
    if (((is_action_id_none(arg0->animation_number) == 0) && (arg0->animation_number < 0)) || (arg0->animation_number >= get_player_action_motion_count())) {
        return 0;
    }
    if ((arg0->animation_timer < 0.0f) || (arg0->animation_timer >= ((TObjPlayer *)player)->get_action_frame_count(arg0->animation_number))) {
        return 0;
    }
    return 1;
}

}
