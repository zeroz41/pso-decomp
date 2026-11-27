#include "pso/player/PlayerAttackParams.h"
#include "pso/player/PlayerRequirementStats.h"
#include "pso/player/PlayerLevelTable.h"
#include "pso/item/InventoryEntryCopy.h"
#include "types.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/item/TItem.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TObjEndingPlayer.h"
#include "pso/system/vector.h"
#include "pso/network/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerClassStats.h"
#include "pso/map/FloorArea.h"

#include <stddef.h>

#include "pso/item/TItemData.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"


#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/base/TObjBase.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/system/MallocLoadFilePrc.h"


extern "C" {
s32 clamp_class_index(s32);
s32 get_class_index__10TObjPlayerFv(TObjPlayer *player);
s32 get_class_max_exp(TObjPlayer *player);
}
// The PlyLevelTbl.cpt archive: its first word points to the per-class level rows.
PlayerLevelTableRow ***ply_level_table;
f32 lookup_attack_marker(s32 handle, s16 falz_phase, s16 strike_count, s32 class_flags);
extern PhotonBlastMotionTiming *photon_blast_motion_timing_tables[6];
extern const s32 (*player_footstep_floor_table[3])[5];
extern const TObjMotionAction *player_clamped_index_table_pointers[3];
extern const PlayerAnimTableEntry *player_anim_table_pointers[3];
extern const PlayerCastMotionRecord *player_cast_motion_record_table[6];
extern const TPlyInventoryItem *class_starting_inventory_table[12];
// Defined after their users, which keeps these 8-byte tables out of .sdata.
extern const Vec *hospital_position_table_by_episode[];
extern const Vec *guild_return_position_table_by_episode[];


s32 TObjPlayer::get_getup_protection_ticks() {
    if (get_main_phase() == 0xF) {
        if (obj_isState3_324() != 0) {
            return player_getup_protection_ticks_table_flagged[game_difficulty_selection];
        }
        return player_getup_protection_ticks_table[game_difficulty_selection];
    }
    if (obj_isState3_324() != 0) {
        return getup_protection_ticks_table_b[game_difficulty_selection];
    }
    return getup_protection_ticks_table_a[game_difficulty_selection];
}

s32 TObjPlayer::get_hurt_protection_ticks() {
    if (get_main_phase() == 0xF) {
        if (obj_isState3_324() != 0) {
            return hurt_protection_ticks_table[game_difficulty_selection];
        }
        return player_hurt_protection_ticks_table_phase15[game_difficulty_selection];
    }
    if (obj_isState3_324() != 0) {
        return player_hurt_protection_ticks_table_flagged[game_difficulty_selection];
    }
    return player_hurt_protection_ticks_table[game_difficulty_selection];
}

s32 TObjPlayer::get_lobby_entry_yaw() {
    return *(s32 *)((s8 *)lobby_entry_yaw_by_episode + (TLobby::get_instance() * 4));
}

u8 *TObjPlayer::get_lobby_entry_ptr() {
    return (u8 *)lobby_entry_table + (TLobby::get_instance() * 0xC);
}

s32 TObjPlayer::get_guild_return_yaw() {
    return *(s32 *)((s8 *)guild_return_yaw_by_episode + (TLobby::get_instance() * 4));
}

const Vec *TObjPlayer::get_guild_return_position() {
    return guild_return_position_table_by_episode[TLobby::get_instance()] + this->get_entity_id();
}

s32 TObjPlayer::get_hospital_yaw() {
    return *(s32 *)((s8 *)hospital_yaw_by_episode + (TLobby::get_instance() * 4));
}

u8 *TObjPlayer::get_hospital_position() {
    return (u8 *)hospital_position_table_by_episode[TLobby::get_instance()] + (this->get_entity_id() * 0xC);
}

const TPlyInventoryItem *get_class_starting_inventory(s32 cls) {
    clamp_class_index(cls);
    return class_starting_inventory_table[(s8)cls];
}

u8 * TObjPlayer::get_cast_motion_record() {
  s32 offset;
  s8 *table_slot;
  offset = this->get_handle_value() * 0x14;
  table_slot = ((s8 *)player_cast_motion_record_table) + (this->has_valid_handle() * 4);
  return *(u8 **)table_slot + offset;
}

long TObjPlayer::get_anim_table_entry(s32 picture) {
  int row_offset;
  row_offset = this->get_clamped_index() * 4;
  return (*((s32 *) (((s8 *)player_anim_table_pointers) + row_offset))) + (picture * 4);
}

saddr TObjPlayer::get_table_entry_by_clamped_index() {
    return *(s32 *)((s8 *)player_clamped_index_table_pointers + (this->get_clamped_index() * 4));
}

s32 TObjPlayer::get_footstep_floor_index() {
    s32 floor;
    const s32 (*table)[5];
    floor = get_current_floor_area();
    table = player_footstep_floor_table[classify_action_state()];
    if (floor == 0xE && TBoss4DarkFalz::get_instance_count() == 0) {
        floor = 1;
    }
    {
        s32 surf = get_floor_surface_type();
        return table[floor][surf];
    }
}

f32 TObjPlayer::get_photon_blast_complete_threshold() {
    return photon_blast_motion_timing_tables[has_valid_handle()][get_handle_value()].complete_threshold;
}

f32 TObjPlayer::get_photon_blast_upper_bound() {
    return photon_blast_motion_timing_tables[has_valid_handle()][get_handle_value()].upper_bound;
}

f32 TObjPlayer::get_photon_blast_hold_frame() {
    s32 offset = get_handle_value() * sizeof(PhotonBlastMotionTiming);
    const u8 *table = (const u8 *)photon_blast_motion_timing_tables[has_valid_handle()];
    return ((const PhotonBlastMotionTiming *)(table + offset))->hold_frame;
}

f32 TObjPlayer::get_attack_recovery_count() {
    s32 falz_phase;
    falz_phase = get_falz_phase();
    return (f32)(s8)attack_recovery_count_table[get_handle_value()][falz_phase];
}

#pragma push
#pragma scheduling off
f32 TObjPlayer::select_normal_attack_marker() {
  s16 strike_count;
  s16 falz_phase;
  s16 stage_strikes;
  s32 class_flags;
  class_flags = get_class_flags();
  stage_strikes = attack_state.get_hit_count();
  strike_count = stage_strikes;
  falz_phase = this->get_falz_phase();
  return lookup_attack_marker((s32) get_handle_value(), falz_phase, strike_count, class_flags);
}

#pragma pop

f32 lookup_attack_marker(s32 handle, s16 falz_phase, s16 strike_count, s32 class_flags) {
    switch (handle) {
    case 3:
        return attack_marker_table_dagger[strike_count][falz_phase];
    case 14:
        return attack_marker_table_double_saber[strike_count][falz_phase];
    case 15:
        if (class_flags & CLASS_FLAG_MALE) {
            return twin_sword_male_marker_table[strike_count][falz_phase];
        }
        return twin_sword_female_marker_table[strike_count][falz_phase];
    default:
        return attack_marker_table[handle][falz_phase];
    }
}

// .data
PhotonBlastMotionTiming photon_blast_motion_timing_0[19] = {
    { 20.0f, 22.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 30.0f, 32.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 16.0f, 18.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 31.0f, 33.0f, 46.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 30.0f, 32.0f, 46.0f },
};
PhotonBlastMotionTiming photon_blast_motion_timing_1[19] = {
    { 24.0f, 26.0f, 40.0f },
    { 24.0f, 26.0f, 46.0f },
    { 16.0f, 18.0f, 44.0f },
    { 28.0f, 30.0f, 45.0f },
    { 30.0f, 32.0f, 44.0f },
    { 24.0f, 26.0f, 46.0f },
    { 30.0f, 32.0f, 43.0f },
    { 28.0f, 30.0f, 46.0f },
    { 28.0f, 30.0f, 44.0f },
    { 20.0f, 22.0f, 44.0f },
    { 24.0f, 26.0f, 45.0f },
    { 28.0f, 30.0f, 42.0f },
    { 22.0f, 24.0f, 44.0f },
    { 24.0f, 26.0f, 40.0f },
    { 22.0f, 24.0f, 44.0f },
    { 28.0f, 30.0f, 45.0f },
    { 24.0f, 26.0f, 46.0f },
    { 26.0f, 28.0f, 44.0f },
    { 28.0f, 30.0f, 42.0f },
};
PhotonBlastMotionTiming photon_blast_motion_timing_2[19] = {
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
    { 22.0f, 24.0f, 39.0f },
    { 28.0f, 30.0f, 42.0f },
    { 22.0f, 24.0f, 39.0f },
    { 24.0f, 26.0f, 42.0f },
    { 26.0f, 28.0f, 42.0f },
    { 26.0f, 28.0f, 42.0f },
    { 28.0f, 30.0f, 42.0f },
};
PhotonBlastMotionTiming *photon_blast_motion_timing_tables[6] = {
    photon_blast_motion_timing_0, photon_blast_motion_timing_1, photon_blast_motion_timing_2,
    photon_blast_motion_timing_0, photon_blast_motion_timing_1, photon_blast_motion_timing_1,
};
const s32 (*player_footstep_floor_table[3])[5] = {
    footstep_floor_table_default, footstep_floor_table_cast, footstep_floor_table_racast,
};
const TObjMotionAction *player_clamped_index_table_pointers[3] = {
    player_clamped_motion_actions_0, player_clamped_motion_actions_1, player_clamped_motion_actions_2,
};
const PlayerAnimTableEntry *player_anim_table_pointers[3] = {
    player_anim_table_0, player_anim_table_1, player_anim_table_2,
};
const PlayerCastMotionRecord *player_cast_motion_record_table[6] = {
    player_cast_motion_records_0, player_cast_motion_records_1, player_cast_motion_records_2,
    player_cast_motion_records_3, player_cast_motion_records_1, player_cast_motion_records_1,
};
const TPlyInventoryItem *class_starting_inventory_table[12] = {
    humar_starting_inventory, hunewearl_starting_inventory, hucast_starting_inventory, ramar_starting_inventory,
    racast_starting_inventory, racaseal_starting_inventory, fomarl_starting_inventory, fonewm_starting_inventory,
    fonewearl_starting_inventory, hucaseal_starting_inventory, fomar_starting_inventory, ramarl_starting_inventory,
};

s32 get_class_max_exp(TObjPlayer *player) {
    return TObjPlayer::get_current_state_field(get_class_index__10TObjPlayerFv(player), TObjPlayer::get_max_level());
}

s32 TObjPlayer::get_current_state_field(s32 cls, s32 lvl) {
    return get_ply_level_table_row(cls, lvl)->experience;
}

s32 TObjPlayer::get_class_state_field(s32 lvl) {
    return TObjPlayer::get_current_state_field(get_class_index__10TObjPlayerFv(this), lvl); }

PlayerLevelTableRow *get_ply_level_table_row(s32 cls, s32 level) {
    PlayerLevelTableRow **table = *ply_level_table;
    return &table[(s8)clamp_class_index(cls)][TObjPlayer::clamp_index_to_max(level)];
}

void free_ply_level_tbl() { TLobby::free_nodes_with_id(ply_level_table); }

void load_ply_level_tbl(void) { ply_level_table = (PlayerLevelTableRow ***)load_encrypted_archive_data("PlyLevelTbl.cpt"); }


AttackParams *get_class_attack_template(TObjPlayer *player) {
    return &((AttackParams *)class_attack_template_table)[static_cast<s8>(player->get_class_index())];
}

ActorParamBlock *get_class_defense_template(TObjPlayer *player) {
    return &((ActorParamBlock *)class_defense_template_table)[static_cast<s8>(player->get_class_index())];
}

stats *get_class_base_stats(s32 cls) {
    return player_class_base_stat_tables[(s8)clamp_class_index(cls)];
}

const player_stats *get_class_stat_caps(s32 cls) {
    return &player_class_stat_caps[(s8)clamp_class_index(cls)];
}

player_stats *TObjPlayer::get_class_stat_entry() {
    return (player_stats*)&player_class_stat_caps[(s8)get_class_index()];
}

f32 TObjPlayer::get_tp_class_factor() {
    if (this->appearance.classFlags & CLASS_FLAG_ANDROID) {
        return 0.0f;
    }
    return player_profession_stat_factors[this->get_clamped_index()].tp;
}

f32 TObjPlayer::get_class_hp_factor() {
    return player_profession_stat_factors[get_clamped_index()].hp;
}

int TObjPlayer::get_floor_surface_type() { return contact_surface.get_contact_surface_type(); }
s32 TObjPlayer::get_falz_phase() { return attack_state.get_begun_stage(); }

int TBoss4DarkFalz::get_instance_count() {  return dark_falz_form_index; }

s32 PlayerAttackController::get_begun_stage() { return begun_stage; }

const Vec *hospital_position_table_by_episode[2] = {
    hospital_positions_ep1, hospital_positions_ep2,
};
const Vec *guild_return_position_table_by_episode[2] = {
    guild_return_positions_ep1, guild_return_positions_ep2,
};

// Highest technique level per class (12 classes x 19 techniques, 0xFF = not learnable), read by
// get_class_technique_cap.
static const u8 humar_technique_caps[20] = { 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0xFF, 0xFF, 0x0E, 0x0E, 0xFF, 0x0E, 0x0E, 0x04, 0xFF, 0xFF, 0x00 };
static const u8 hunewearl_technique_caps[20] = { 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0xFF, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x06, 0xFF, 0xFF, 0x00 };
static const u8 hucast_technique_caps[20] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00 };
static const u8 ramar_technique_caps[20] = { 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0xFF, 0x0E, 0xFF, 0xFF, 0x0E, 0x0E, 0x0E, 0x04, 0xFF, 0xFF, 0x00 };
static const u8 racast_technique_caps[20] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00 };
static const u8 racaseal_technique_caps[20] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00 };
static const u8 fomarl_technique_caps[20] = { 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x06, 0x1D, 0x1D, 0x00 };
static const u8 fonewm_technique_caps[20] = { 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x06, 0x1D, 0x1D, 0x00 };
static const u8 fonewearl_technique_caps[20] = { 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x06, 0x1D, 0x1D, 0x00 };
static const u8 hucaseal_technique_caps[20] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00 };
static const u8 fomar_technique_caps[20] = { 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x06, 0x1D, 0x1D, 0x00 };
static const u8 ramarl_technique_caps[20] = { 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0xFF, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x06, 0xFF, 0xFF, 0x00 };
const u8 *class_technique_cap_table[12] = {
    humar_technique_caps, hunewearl_technique_caps, hucast_technique_caps, ramar_technique_caps, racast_technique_caps, racaseal_technique_caps,
    fomarl_technique_caps, fonewm_technique_caps, fonewearl_technique_caps, hucaseal_technique_caps, fomar_technique_caps, ramarl_technique_caps,
};
