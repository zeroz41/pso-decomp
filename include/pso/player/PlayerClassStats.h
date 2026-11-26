#ifndef PSO_PLAYER_CLASS_STATS_H
#define PSO_PLAYER_CLASS_STATS_H
#include "pso/player/TPlyDispData.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/player/TPlyInventory.h"
#include <dolphin/mtx/GeoTypes.h>

struct PlayerProfessionStatFactors { f32 hp; f32 tp; };

// Record types of the class/motion tables; layouts from the original bytes and
// the accessors' strides, field meanings unknown.
struct PlayerAnimTableEntry {
    s16 unk0;
    s16 unk2;
};

struct PlayerCastMotionRecord {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
};

extern const PlayerProfessionStatFactors player_profession_stat_factors[3];
extern const player_stats player_class_stat_caps[12];
extern stats* player_class_base_stat_tables[12];
extern const ActorParamBlock class_defense_template_table[12];
extern const AttackParams class_attack_template_table[12];
extern const f32 attack_marker_table[19][3];
extern const f32 attack_marker_table_dagger[3][3];
extern const f32 attack_marker_table_double_saber[4][3];
extern const f32 twin_sword_male_marker_table[3][3];
extern const f32 twin_sword_female_marker_table[3][3];
extern const u8 attack_recovery_count_table[20][3];
extern const s32 footstep_floor_table_default[36][5];
extern const s32 footstep_floor_table_cast[36][5];
extern const s32 footstep_floor_table_racast[36][5];
extern const TObjMotionAction player_clamped_motion_actions_0[12];
extern const TObjMotionAction player_clamped_motion_actions_1[12];
extern const TObjMotionAction player_clamped_motion_actions_2[12];
extern const PlayerAnimTableEntry player_anim_table_0[12];
extern const PlayerAnimTableEntry player_anim_table_1[12];
extern const PlayerAnimTableEntry player_anim_table_2[12];
extern const PlayerCastMotionRecord player_cast_motion_records_0[19];
extern const PlayerCastMotionRecord player_cast_motion_records_1[19];
extern const PlayerCastMotionRecord player_cast_motion_records_2[19];
extern const PlayerCastMotionRecord player_cast_motion_records_3[19];
extern const TPlyInventoryItem humar_starting_inventory[5];
extern const TPlyInventoryItem hunewearl_starting_inventory[5];
extern const TPlyInventoryItem hucast_starting_inventory[5];
extern const TPlyInventoryItem ramar_starting_inventory[5];
extern const TPlyInventoryItem racast_starting_inventory[5];
extern const TPlyInventoryItem racaseal_starting_inventory[5];
extern const TPlyInventoryItem fomarl_starting_inventory[5];
extern const TPlyInventoryItem fonewm_starting_inventory[5];
extern const TPlyInventoryItem fonewearl_starting_inventory[5];
extern const TPlyInventoryItem hucaseal_starting_inventory[5];
extern const TPlyInventoryItem fomar_starting_inventory[5];
extern const TPlyInventoryItem ramarl_starting_inventory[5];
extern const Vec hospital_positions_ep1[4];
extern const Vec hospital_positions_ep2[4];
extern const s32 hospital_yaw_by_episode[2];
extern const Vec guild_return_positions_ep1[4];
extern const Vec guild_return_positions_ep2[4];
extern const s32 guild_return_yaw_by_episode[2];
extern const Vec lobby_entry_table[2];
extern const s32 lobby_entry_yaw_by_episode[2];
extern const s32 player_hurt_protection_ticks_table[4];
extern const s32 player_hurt_protection_ticks_table_flagged[4];
extern const s32 player_hurt_protection_ticks_table_phase15[4];
extern const s32 hurt_protection_ticks_table[4];
extern const s32 getup_protection_ticks_table_a[4];
extern const s32 getup_protection_ticks_table_b[4];
extern const s32 player_getup_protection_ticks_table[4];
extern const s32 player_getup_protection_ticks_table_flagged[4];

#endif
