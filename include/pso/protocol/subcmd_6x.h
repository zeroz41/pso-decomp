/* PSO 0x60 game subcommand formats (G_*_6xNN).
 *
 * Shared PSO wire-protocol structures for Episode I & II Plus (GameCube / V3).
 * These command/subcommand formats are identical between server and client by
 * definition, so they are safe to use to type the GameCube client decomp's
 * network handlers.
 *
 * Field names and byte offsets are derived from newserv
 * (fuzziqersoftware/newserv), an MIT-licensed PSO server reimplementation, via
 * tools/newserv_match.py. newserv is MIT (Copyright (c) 2024 Martin Michelsen);
 * its LICENSE is bundled at reference/newserv-LICENSE and permits this reuse.
 *
 * The decomp's own integer types (u8/u16/u32/s8/s16/s32/f32 ...) replace
 * newserv's phosg le_/be_ wire-endian wrappers; on the big-endian PowerPC
 * client these are plain scalars. The `size 0xNN` trailer reflects newserv's
 * static_assert/check_struct_size (0 computed-vs-declared mismatches at
 * generation time). V3/GC-relevant structs are kept; BB/DC/Ep3/XB-only
 * variants are skipped.
 *
 * GENERATED — verify offsets against the DOL before relying on a field.
 */

#ifndef PSO_PROTOCOL_SUBCMD_6X_H
#define PSO_PROTOCOL_SUBCMD_6X_H

#include "types.h"
#include "pso/protocol/protocol_types.h"

struct G_6x70_Base_DCNTE {
 u16 client_id;
 u16 room_id;
 u32 game_flags;
 struct VectorXYZF pos;
 struct VectorXYZI angle;
 u16 phase;
 u16 current_hp;
};

struct G_6x70_Sub_Telepipe {
 struct TelepipeState state;
 u32 unknown_a4;
};

struct G_6x70_Base_V1 {
 struct G_6x70_Base_DCNTE base;
 u16 bonus_hp_from_materials;
 u16 bonus_tp_from_materials;
 struct StatusEffectState permanent_status_effect;
 struct StatusEffectState temporary_status_effect;
 struct StatusEffectState attack_status_effect;
 struct StatusEffectState defense_status_effect;
 struct StatusEffectState unknown_a1_status_effect;
 u32 language32;
 u32 player_tag;
 u32 guild_card_number;
 u32 unknown_a6;
 u32 battle_team_number;
 struct G_6x70_Sub_Telepipe telepipe;
 u32 death_flags;
 struct PlayerHoldState hold_state;
 u32 area;
 u32 player_flags;
 u8 technique_levels_v1[0x14];
};

struct G_ActivateMagEffect_6x61 {
 struct G_ClientIDHeader header;
 u32 mag_item_id;
 u32 effect_number;
 G_ActivateMagEffect_6x61();
 void bswap();
 void send();
};

struct G_AddBattleDamageScores_6x8F {
 struct G_ClientIDHeader header;
 u16 target_entity_id;
 u16 amount;
};

struct G_AddOrRemoveStatusEffect_6x0C_6x0D {
 struct G_ClientIDHeader header;
 u32 effect_type;
 f32 amount;
};

struct G_AttackFinished_Header_6x46 {
 struct G_ClientIDHeader header;
 u32 target_count;
};

struct G_Attack_6x43_6x44_6x45 {
 struct G_ClientIDHeader header;
 u16 angle_y;
 u16 unknown_a2;
};

struct G_BarbaRayBossActions_6xA9 {
 struct G_EntityIDHeader header;
 u16 what;
 u16 unknown_a2;
};

struct G_BarbaRayBossActions_6xAA {
 struct G_EntityIDHeader header;
 u16 what;
 u16 unknown_a2;
 u32 target_client_id;
};

struct G_BuyShopItem_6x5E {
 struct G_ClientIDHeader header;
 TItemData item_data;
 G_BuyShopItem_6x5E();
 void bswap();
 void send();
};

struct G_CardCounts_Ep3NTE_6xBC {
 u8 header[0x8];
 u8 card_counts[0x3E8];
};

struct G_CastTechniqueComplete_6x48 {
 struct G_ClientIDHeader header;
 u16 technique_number;
 u16 level;
};

struct G_CastTechnique_Header_6x47 {
 struct G_ClientIDHeader header;
 u8 technique_number;
 u8 unused;
 u8 level;
 u8 target_count;
};

struct G_ChangePlayerHP_6x2F {
 struct G_ClientIDHeader header;
 u32 type;
 s16 amount;
 u16 client_id;
};

struct G_ChangePlayerLevel_6x30 {
 struct G_ClientIDHeader header;
 u16 atp;
 u16 mst;
 u16 evp;
 u16 hp;
 u16 dfp;
 u16 ata;
 u16 level;
 u16 is_level_down;
};

struct G_ClearNegativeStatusEffects_6x0E {
 struct G_ClientIDHeader header;
};

struct G_ClearPhotonBlastReadyFlag_6x3A {
 struct G_ClientIDHeader header;
};

struct G_ClearTemporaryPhotonBlastStateFlags_6x3B {
 struct G_ClientIDHeader header;
};

struct G_CreateInventoryItem_DC_6x2B {
 struct G_ClientIDHeader header;
 TItemData item_data;
};

struct G_CreateInventoryItem_PC_V3_BB_6x2B {
 struct G_CreateInventoryItem_DC_6x2B __base_G_CreateInventoryItem_DC_6x2B;
 u8 unused1;
 u8 equip_item;
 u8 unused2[2];
};

struct G_CreateLobbyChair_6xAB {
 struct G_ClientIDHeader header;
 u16 animation_number;
 u16 flags;
};

struct G_DarkFalzActions_6x19 {
 struct G_EntityIDHeader header;
 u16 unknown_a2;
 u16 unknown_a3;
 u32 unknown_a4;
 u32 unused;
};

struct G_DeRolLeBossActionsWithTarget_6x14 {
 struct G_EntityIDHeader header;
 u16 phase;
 u16 unknown_a3;
 u32 target_client_id;
};

struct G_DeRolLeBossActions_6x13 {
 struct G_EntityIDHeader header;
 u16 phase;
 u16 unknown_a3;
};

struct G_DeleteInventoryItem_6x29 {
 struct G_ClientIDHeader header;
 u32 item_id;
 u32 amount;
};

struct G_DeleteMultipleInventoryItems_6xAC {
 struct G_ClientIDHeader header;
 u32 num_items;
 u32 item_ids[0x1E];
};

struct G_DestroyFloorItem_6x5C_6x63 {
 struct G_UnusedHeader header;
 u32 item_id;
 u32 floor;
};

struct G_DisableDropWeaponOnDeath_6x81 {
 struct G_ClientIDHeader header;
};

struct G_DisablePKModeForPlayer_6x1C {
 struct G_ClientIDHeader header;
};

struct G_DisableStealthSuitEffect_6x7B {
 struct G_ClientIDHeader header;
};

struct G_DonateToPhotonBlast_6x38 {
 struct G_ClientIDHeader header;
 u16 target_client_id;
 u16 unused;
};

struct G_DoneLoadingIntoGame_6x72 {
 struct G_UnusedHeader header;
};

struct G_DragonBossActions_6x10_6x11 {
 struct G_EntityIDHeader header;
 u16 unknown_a2;
 u16 unknown_a3;
 u32 unknown_a4;
};

struct G_DropItem_6x2A {
 struct G_ClientIDHeader header;
 u16 amount;
 u16 floor;
 u32 item_id;
 struct VectorXYZF pos;
};

struct G_DropItem_DC_6x5F {
 struct G_UnusedHeader header;
 struct FloorItem item;
};

struct G_DropItem_PC_V3_BB_6x5F {
 struct G_DropItem_DC_6x5F __base_G_DropItem_DC_6x5F;
 u32 unused3;
};

struct G_DropStackedItem_DC_6x5D {
 struct G_ClientIDHeader header;
 s16 floor;
 s16 room_id;
 struct VectorXZF pos;
 TItemData item_data;
 G_DropStackedItem_DC_6x5D();
};

struct G_DropStackedItem_PC_V3_BB_6x5D : G_DropStackedItem_DC_6x5D {
 // The item data's version (2: v2 and later; a DC packet has none and is v0).
 u8 item_version;
 u8 unused3[3];
 G_DropStackedItem_PC_V3_BB_6x5D();
 void bswap();
 void send();
};

struct G_EnableDropWeaponOnDeath_6x82 {
 struct G_ClientIDHeader header;
};

struct G_EnablePKModeForPlayer_6x1B {
 struct G_ClientIDHeader header;
};

struct G_EnableStealthSuitEffect_6x7A {
 struct G_ClientIDHeader header;
};

struct G_EquipItem_6x25 {
 struct G_ClientIDHeader header;
 u32 item_id;
 u32 equip_slot;
};

struct G_ExecutePhotonBlast_Header_6x49 {
 struct G_ClientIDHeader header;
 s8 unknown_a1;
 u8 unused1;
 u16 target_count;
 u16 pb_meter_value;
 u16 unused2;
};

struct G_ExitQuest_6x73 {
 struct G_UnusedHeader header;
};

struct G_FeedMag_6x28 {
 struct G_ClientIDHeader header;
 u32 mag_item_id;
 u32 fed_item_id;
};

struct G_GalGryphonBossActions_6x9F {
 struct G_EntityIDHeader header;
 u32 unknown_a1;
 f32 unknown_a2;
 f32 unknown_a3;
};

struct G_GalGryphonBossActions_6xA0 {
 struct G_EntityIDHeader header;
 struct VectorXYZF pos;
 u32 angle_y;
 u16 phase;
 u16 unknown_a3;
 u32 unknown_a4[4];
};

struct G_GogoBall_6x79 {
 struct G_UnusedHeader header;
 u32 unknown_a1;
 u32 angle;
 struct VectorXZF ball_pos;
 u8 use_missile_sound;
 u8 unused[3];
};

struct G_HitByEnemy_6x4B_6x4C {
 struct G_ClientIDHeader header;
 u16 angle;
 u16 current_hp;
 struct VectorXZF velocity;
};

struct G_UpdateObjectState_6x0B {
 struct G_EntityIDHeader header;
 u32 flags;
 u32 object_index;
};

struct G_HitDestructibleObject_6x86 {
 struct G_UpdateObjectState_6x0B __base_G_UpdateObjectState_6x0B;
 u16 is_destroyed;
 u16 remaining_hits;
};

struct G_IdentifyItemRequest_6xB8 {
 struct G_UnusedHeader header;
 u32 item_id;
};

struct G_ImposeHold_6x2C {
 struct G_ClientIDHeader header;
 u16 unknown_a1;
 u16 unknown_a2;
 f32 x;
 f32 z;
 f32 trigger_radius2;
};

struct G_IncrementEnemyDamage_Extension_6xE4 {
 struct G_EntityIDHeader header;
 s16 hit_amount;
 u16 total_damage_before_hit;
 u16 current_hp_before_hit;
 u16 max_hp;
 f32 factor;
};

struct G_InterLevelWarp_6x21 {
 struct G_ClientIDHeader header;
 s32 floor;
};

struct G_InterLevelWarp_6x94 {
 struct G_UnusedHeader header;
 u16 floor;
 u8 unused[2];
};

struct G_IntraMapWarp_6x55 {
 struct G_ClientIDHeader header;
 u32 angle_y;
 struct VectorXYZF from_pos;
 struct VectorXYZF pos;
};

struct G_LegacyActivateSwitchByToken_6x04 {
 struct G_ParameterHeader header;
 u16 switch_token;
 u16 unused;
};

struct G_LegacyKillEnemy_6x09 {
 struct G_EntityIDHeader header;
};

struct G_LevelUpAllTechniques_6x9B {
 struct G_ClientIDHeader header;
 u8 num_levels;
 u8 unused[3];
};

struct G_LobbyAnimation_6x58 {
 struct G_ClientIDHeader header;
 u16 animation_number;
 u16 flags;
};

struct G_MedicalCenterReviveAllPlayers_6x32 {
 struct G_UnusedHeader header;
};

struct G_ModifyTradeProposal_6xA6 {
 struct G_ClientIDHeader header;
 u8 what;
 u8 result;
 u16 unknown_a1;
 u32 item_id;
 u32 amount;
};

struct G_MoveToPosition_6x41_6x42 {
 struct G_ClientIDHeader header;
 struct VectorXZF pos;
};

struct G_NPCControl_6x69 {
 struct G_UnusedHeader header;
 u16 param1;
 u16 param2;
 u16 command;
 u16 param3;
};

struct G_OlgaFlowBossActions_6xA3 {
 struct G_EntityIDHeader header;
 u8 unknown_a1;
 u8 unknown_a2;
 u8 unknown_a3[0x0E];
};

struct G_OlgaFlowBossActions_6xA4_6xA5 {
 struct G_EntityIDHeader header;
 u8 what;
 u8 pos_bytes[3];
 u8 state_bytes[3];
 u8 unused1;
 u8 ext_state_bytes[4];
 u8 unused2[4];
};

struct G_OlgaFlowSubordinateBossActions_6xAD {
 struct G_UnusedHeader header;
 u8 unknown_a1[0x40];
};

struct G_PartialPlayerData_DCProtos_6x1E {
 struct G_ClientIDHeader header;
 u16 floor;
 u16 num_items;
 struct VectorXYZF pos;
 u32 angle_y;
 u32 items[30];
};

struct G_PhotonBlast_6x37 {
 struct G_ClientIDHeader header;
 u16 amount;
 u16 unused;
};

struct G_PickUpItemRequest_6x5A {
 struct G_ClientIDHeader header;
 u32 item_id;
 u16 floor;
 u16 unused;
 G_PickUpItemRequest_6x5A();
 void bswap();
 void send();
};

struct G_PickUpItem_6x59 {
 struct G_ClientIDHeader header;
 u16 client_id2;
 s16 floor;
 u32 item_id;
 G_PickUpItem_6x59();
 void bswap();
 void send();
};

struct G_PlaceTrap_6x83 {
 struct G_ClientIDHeader header;
 u16 trap_type;
 u16 trap_index;
};

struct G_PlaySoundFromPlayer_6xB2 {
 struct G_UnusedHeader header;
 u8 area;
 u8 unused;
 u16 client_id;
 u32 sound_id;
};

struct G_PlayerCameraShutterSound_6x9E {
 struct G_ClientIDHeader header;
};

struct G_PlayerDied_6x4D {
 struct G_ClientIDHeader header;
 u32 death_flags;
};

struct G_PlayerRevivable_6x4E {
 struct G_ClientIDHeader header;
};

struct G_PlayerRevived_6x4F {
 struct G_ClientIDHeader header;
};

struct G_ReleaseHold_6x2D {
 struct G_ClientIDHeader header;
};

struct G_RequestPartialPlayerData_DCProtos_6x1D {
 struct G_UnusedHeader header;
};

struct G_RestoreShrunkenPlayer_6x88 {
 struct G_ClientIDHeader header;
};

struct G_RevivePlayer_6x33 {
 struct G_ClientIDHeader header;
 u16 client_id2;
 u16 unused;
};

struct G_RevivePlayer_V3_BB_6xA1 {
 struct G_ClientIDHeader header;
};

struct G_SelectChallengeModeFailureOption_6x97 {
 struct G_UnusedHeader header;
 u32 client_id;
 u32 is_retry;
 u32 unused1;
 u32 unused2;
};

struct G_SendGuildCard_GC_6x06 {
 struct G_UnusedHeader header;
 u8 guild_card[0x90];
};

struct G_SendGuildCard_PC_6x06 {
 struct G_UnusedHeader header;
 struct GuildCardPC guild_card;
};

struct G_SetAnimationState_6x52 {
 struct G_ClientIDHeader header;
 u16 animation;
 u16 unknown_a2;
 u32 angle;
};

struct G_SetAnimationState_6xAE {
 struct G_ClientIDHeader header;
 u16 animation_number;
 u16 unused;
 u32 player_flags;
 f32 animation_timer;
};

struct G_SetBattleModeData_6x7D {
 struct G_UnusedHeader header;
 u8 what;
 u8 unknown_a1;
 u8 unused;
 u8 is_alive;
 u32 params[4];
};

struct G_SetBossWarpFlags_6x6A {
 struct G_EntityIDHeader header;
 u16 flags;
 u16 unused;
};

struct G_SetChallengeDeadFlag_6x9D {
 struct G_UnusedHeader header;
 u32 client_id;
};

struct G_SetChallengeRecordsBase_6x7C {
 struct G_UnusedHeader header;
 u16 client_id;
 u8 unused[2];
};

struct G_SetChallengeRecords_PC_6x7C {
 struct G_SetChallengeRecordsBase_6x7C __base_G_SetChallengeRecordsBase_6x7C;
 u8 records[0xD8];
};

struct G_SetChallengeRecords_V3_6x7C {
 struct G_SetChallengeRecordsBase_6x7C __base_G_SetChallengeRecordsBase_6x7C;
 u8 records[0x100];
};

struct G_SetEnemyLowGameFlagsUltimate_6x9C {
 struct G_EntityIDHeader header;
 u32 status_effect_flags;
};

struct G_SetEntityPositionAndAngle_6x17 {
 struct G_EntityIDHeader header;
 struct VectorXYZF pos;
 u32 angle;
};

struct G_SetEntitySetFlags_6x76 {
 struct G_EntityIDHeader header;
 u16 floor;
 u16 flags;
};

struct G_SetKillerEntityID_6x89 {
 struct G_ClientIDHeader header;
 u16 killer_entity_id;
 u16 unused;
};

struct G_SetOrClearPlayerFlags_6x2E {
 struct G_ClientIDHeader header;
 u32 and_mask;
 u32 or_mask;
};

struct G_SetPhotonBlastReadyFlag_6x39 {
 struct G_ClientIDHeader header;
};

struct G_SetPlayerAngle_6x51 {
 struct G_ClientIDHeader header;
 u16 angle;
 u8 unused[2];
};

struct G_SetPlayerBattleTeam_6x90 {
 struct G_ClientIDHeader header;
 u32 team_number;
};

struct G_SetPlayerFloor_6x1F {
 struct G_ClientIDHeader header;
 s32 floor;
};

struct G_SetPlayerPositionAndAngle_6x56 {
 struct G_ClientIDHeader header;
 u32 angle_y;
 struct VectorXYZF pos;
};

struct G_SetPlayerVisibility_6x22_6x23 {
 struct G_ClientIDHeader header;
};

struct G_SetPosition_6x20 {
 struct G_ClientIDHeader header;
 s32 floor;
 struct VectorXYZF pos;
 u32 angle_y;
};

struct G_SetPosition_6x3F {
 struct G_ClientIDHeader header;
 u16 is_near_enemy;
 u16 angle;
 s16 floor;
 s16 room;
 struct VectorXYZF pos;
};

struct G_SetQuestFlags_V2_V3_6x6F {
 struct G_UnusedHeader header;
 u8 quest_flags[0x200];
};

struct G_SetSwitchFlagFromTimer_6x93 {
 struct G_UnusedHeader header;
 u16 switch_flag_floor;
 u16 switch_flag_num;
 u8 should_set;
 u8 unused[3];
};

struct G_SetTechniqueLevelOverride_6x8D {
 struct G_ClientIDHeader header;
 u8 level_upgrade;
 u8 unused1;
 u16 unused2;
};

struct G_SetTelepipeState_6x68 {
 struct G_UnusedHeader header;
 struct TelepipeState state;
};

struct G_ShieldAttack_6x4A {
 struct G_ClientIDHeader header;
};

struct G_ShowChallengeTimeRecordsWindow_6x8A {
 struct G_ClientIDHeader header;
 u32 which;
};

struct G_ShrinkPlayer_6x87 {
 struct G_ClientIDHeader header;
 f32 size;
};

struct G_StandardDropItemRequest_DC_6x60 {
 struct G_UnusedHeader header;
 u8 floor;
 u8 rt_index;
 u16 entity_index;
 struct VectorXZF pos;
 u16 room;
 u16 ignore_def;
};

struct G_StandardDropItemRequest_PC_V3_BB_6x60 {
 struct G_StandardDropItemRequest_DC_6x60 __base_G_StandardDropItemRequest_DC_6x60;
 u8 effective_area;
 u8 unused[3];
};

struct G_SpecializableItemDropRequest_6xA2 {
 struct G_StandardDropItemRequest_PC_V3_BB_6x60 __base_G_StandardDropItemRequest_PC_V3_BB_6x60;
 f32 param3;
 s32 param4;
 s32 param5;
 s32 param6;
};

struct G_StopAtPosition_6x3E {
 struct G_ClientIDHeader header;
 u16 is_near_enemy;
 u16 angle;
 s16 floor;
 s16 room;
 struct VectorXYZF pos;
};

struct G_SwitchInteraction_6x50 {
 struct G_ClientIDHeader header;
 u32 angle_y;
};

struct G_SymbolChat_6x07 {
 struct G_UnusedHeader header;
 u32 client_id;
 u8 data[0x3C];
};

struct G_SyncGameStateHeader_6x6B_6x6C_6x6D_6x6E {
 u8 header[0x8];
 u32 decompressed_size;
 u32 compressed_size;
};

struct G_SyncItemState_6x6D_Decompressed {
 u16 next_drop_number_per_floor[16];
 u32 next_item_id_per_player[12];
 u32 floor_item_count_per_floor[15];
};

struct G_SyncPlayerDispAndInventory_DC112000_6x70 {
 u8 header[0x8];
 struct G_6x70_Base_DCNTE base;
 u16 bonus_hp_from_materials;
 u16 bonus_tp_from_materials;
 u8 unknown_a5[0x10];
 struct G_6x70_Sub_Telepipe telepipe;
 u32 death_flags;
 struct PlayerHoldState_DCProtos hold_state;
 u32 area;
 u32 player_flags;
 u8 visual[0x50];
 u8 stats[0x24];
 u32 num_items;
 u32 items[0x1E];
};

struct G_SyncPlayerDispAndInventory_DC_PC_6x70 {
 u8 header[0x8];
 struct G_6x70_Base_V1 base;
 u8 visual[0x50];
 u8 stats[0x24];
 u32 num_items;
 u32 items[0x1E];
};

struct G_SyncPlayerDispAndInventory_GC_6x70 {
 u8 header[0x8];
 struct G_6x70_Base_V1 base;
 u8 visual[0x50];
 u8 stats[0x24];
 u32 num_items;
 u32 items[0x1E];
 u32 floor;
};

struct G_SyncQuestRegister_6x77 {
 struct G_UnusedHeader header;
 u16 register_number;
 u16 unused;
 u8 _anon_u_8[0x4];
};

struct G_SyncSetFlagState_6x6E_Decompressed {
 u16 total_size;
 u16 entity_set_flags_size;
 u16 event_set_flags_size;
 u16 switch_flags_size;
};

struct G_TargetBase_6x3D {
 struct G_UnusedHeader header;
};

struct G_TeleportPlayer_6x24 {
 struct G_ClientIDHeader header;
 u32 angle_y;
 struct VectorXYZF pos;
};

struct G_TriggerSetEvent_6x67 {
 struct G_EntityIDHeader header;
 u32 floor;
 u32 event_id;
 u32 client_id;
};

struct G_TriggerTrap_6x80 {
 struct G_ClientIDHeader header;
 u16 trap_number;
 u16 what;
};

struct G_TurnOrMoveLobbyChair_6xAF_6xB0 {
 struct G_ClientIDHeader header;
 u32 angle;
};

struct G_UnblockGameJoin_6x71 {
 struct G_UnusedHeader header;
};

struct G_UnequipItem_6x26 {
 struct G_ClientIDHeader header;
 u32 item_id;
 u32 unused;
};

struct G_Unknown_6x02_6x03 {
 struct G_ClientIDHeader header;
 u16 unknown_a1;
 u16 unknown_a2;
 u32 unknown_a3;
 f32 unknown_a4;
 f32 unknown_a5;
};

struct G_Unknown_6x36 {
 struct G_ParameterHeader header;
};

struct G_Unknown_6x53 {
 struct G_ClientIDHeader header;
};

struct G_Unknown_6x54 {
 struct G_ClientIDHeader header;
};

struct G_Unknown_6x57 {
 struct G_ClientIDHeader header;
};

struct G_Unknown_6x78 {
 struct G_UnusedHeader header;
 u16 client_id;
 u16 unused1;
 u32 unused2;
};

struct G_Unknown_6x92 {
 struct G_UnusedHeader header;
 u32 client_id;
 f32 unknown_a2;
};

struct G_UpdateAttackableColState_6x91 {
 struct G_UpdateObjectState_6x0B __base_G_UpdateObjectState_6x0B;
 u16 is_destroyed;
 u16 remaining_hits;
 u16 switch_flag_num;
 u8 should_set;
 u8 floor;
};

struct G_UpdateEntityStat_6x9A {
 struct G_EntityIDHeader header;
 u16 entity_index;
 u8 what;
 u8 amount;
};

struct G_UpdateQuestFlag_DC_PC_6x75 {
 struct G_UnusedHeader header;
 u16 flag;
 u16 action;
};

struct G_UpdateQuestFlag_V3_BB_6x75 {
 struct G_UpdateQuestFlag_DC_PC_6x75 __base_G_UpdateQuestFlag_DC_PC_6x75;
 u16 difficulty16;
 u16 unused;
};

struct G_UseItem_6x27 {
 struct G_ClientIDHeader header;
 u32 item_id;
};

struct G_UseMedicalCenter_6x31 {
 struct G_ClientIDHeader header;
};

struct G_UseStarAtomizer_6x66 {
 struct G_UnusedHeader header;
 // The user first; -1 for an empty slot (handle_6x66_use_star_atomizer).
 s16 target_client_ids[4];
};

struct G_VolOpt2BossActions_6x18 {
 struct G_EntityIDHeader header;
 u16 unknown_a2[4];
};

struct G_VolOptBossActions_6x15 {
 struct G_EntityIDHeader header;
 u16 action;
 u16 unknown_a3;
 u16 unknown_a4;
 u16 unknown_a5;
};

struct G_VolOptBossActions_6x16 {
 struct G_EntityIDHeader header;
 u8 entity_index_table[6];
 u16 entity_index_count;
};

struct G_VolOptBossActions_6x84 {
 struct G_VolOptBossActions_6x16 __base_G_VolOptBossActions_6x16;
 u16 unknown_a3;
 u16 unused;
};

struct G_VolOptPhase2BossActions_6x85 {
 struct G_UnusedHeader header;
 u16 unknown_a1;
 u16 unknown_a2[7];
};

struct G_WalkToPosition_6x40 {
 struct G_ClientIDHeader header;
 struct VectorXZF pos;
 u32 flags;
};

struct G_WriteSwitchFlag_6x05 {
 struct G_EntityIDHeader header;
 u16 client_id;
 u16 unused;
 u16 switch_flag_num;
 u8 switch_flag_floor;
 u8 flags;
};

#endif
