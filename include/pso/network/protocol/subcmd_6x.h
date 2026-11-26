/* The game subcommands (G_*_6xNN) of Episode I & II Plus on GameCube.
 *
 * Every subcommand starts with a G_ClientIDHeader (or G_EntityIDHeader) whose size counts 4-byte
 * words. dispatch_6x_subcommand and dispatch_pso_data_commands (TGameProtocol.cpp) hand a received
 * subcommand to its handler in pso_command_dispatch_table, unless the entry's area mask leaves out
 * the current floor. send_subcommand sends a packet and runs the local handler on it as well.
 *
 * The layouts started from newserv (MIT licence, Copyright (c) 2024 Martin Michelsen; see
 * third_party/LICENSES/newserv-MIT.txt). Where our code reads or sends a packet, the names and
 * sizes follow our code. Each struct says how far it is checked:
 *   "Size checked": a sender in our code sets the header size, and a LAYOUT_ASSERT holds it.
 *   "Used by our code": our code reads or sends it, but no sender fixes its size yet.
 *   "Layout from newserv, not used by our code yet."
 * Where our code carries a packet in a type of its own, only a pointer to that type is left here.
 * Our integer types replace newserv's little-endian wrappers; the senders and handlers swap the
 * bytes.
 */

#ifndef PSO_PROTOCOL_SUBCMD_6X_H
#define PSO_PROTOCOL_SUBCMD_6X_H

#include "types.h"
#include "pso/system/vector.h"
#include "pso/object/base/StatStatusReceipt.h"
#include <stddef.h>
#include "pso/network/protocol/protocol_types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/boss/galgryphon/Boss5GryphonMotionEntry.h"
#include "pso/network/protocol/cast_packets.h"
#include "pso/player/CapturedTargetList.h"
#include "pso/quest/challenge/ChallengeRecord.h"
#include "pso/player/BattleRanking.h"
#include "pso/ui/chat/SymbolChatPayload.h"

// 6x61: Activates the effect of a player's mag. Sent by TItem::send_activate_effect; received by
// handle_6x61_activate_item_effect. Size checked: its constructor sets the header size to 3 words.
struct G_ActivateMagEffect_6x61 {
 struct G_ClientIDHeader header;
 u32 mag_item_id;
 u32 effect_number;
 G_ActivateMagEffect_6x61();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_ActivateMagEffect_6x61Size, sizeof(G_ActivateMagEffect_6x61) == 0xC);

// 6x8F: Adds damage to a battle mode damage score. Sent by record_damage_stats; received by
// handle_6x8F_add_battle_damage_scores. Size checked: G_AddBattleDamageScores_6x8F::init sets the
// header size to 2 words.
struct G_AddBattleDamageScores_6x8F {
 struct G_ClientIDHeader header;
 u16 target_entity_id;
 s16 amount;
 void bswap();
 G_AddBattleDamageScores_6x8F &operator=(G_AddBattleDamageScores_6x8F &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_AddBattleDamageScores_6x8FSize, sizeof(G_AddBattleDamageScores_6x8F) == 0x8);

// Body of 6x0C/6x0D: the status effect the sender added or removed.
// Used by our code; size not checked against a sender yet.
struct StatusEffectChange : StatStatusReceipt {
 void bswap();
};

// 6x0C: Adds a status effect to a player. Sent by TObjPlayer::send_status_effect_add. Size
// checked: G_AddStatusEffect_6x0C::init sets the header size to 3 words.
struct G_AddStatusEffect_6x0C {
 struct G_ClientIDHeader header;
 struct StatusEffectChange effect;
 void bswap();
 G_AddStatusEffect_6x0C &operator=(G_AddStatusEffect_6x0C &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_AddStatusEffect_6x0CSize, sizeof(G_AddStatusEffect_6x0C) == 0xC);

// 6x0D: Removes a status effect from a player. Sent by TObjPlayer::send_status_effect_remove. Size
// checked: G_RemoveStatusEffect_6x0D::init sets the header size to 3 words.
struct G_RemoveStatusEffect_6x0D {
 struct G_ClientIDHeader header;
 struct StatusEffectChange effect;
 void bswap();
 G_RemoveStatusEffect_6x0D &operator=(G_RemoveStatusEffect_6x0D &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_RemoveStatusEffect_6x0DSize, sizeof(G_RemoveStatusEffect_6x0D) == 0xC);

// 6x0C/6x0D: The layout the receive handlers read. Received by
// handle_6x0C_add_or_remove_status_effect and handle_6x0D_add_or_remove_status_effect. Size
// checked: G_AddStatusEffect_6x0C::init and G_RemoveStatusEffect_6x0D::init set the header size to
// 3 words.
struct G_AddOrRemoveStatusEffect_6x0C_6x0D {
 struct G_ClientIDHeader header;
 u32 effect_type;
 f32 amount;
};
LAYOUT_ASSERT(G_AddOrRemoveStatusEffect_6x0C_6x0DSize, sizeof(G_AddOrRemoveStatusEffect_6x0C_6x0D) == 0xC);

// 6x46: a player's attack ends; the lock-on targets it hit follow the header.
// Sent by TObjPlayer::send_attack_target_packet; received by handle_6x46_attack_finished. Size
// checked: the G_AttackFinished_6x46 constructor sets the header size to 12 words.
struct G_AttackFinished_6x46 {
    G_AttackFinished_6x46();
    G_AttackFinished_6x46 &operator=(G_AttackFinished_6x46 &src);
    // The receive-side swap, as G_ExecutePhotonBlast_6x49::bswap_received.
    void bswap_received();
    // Bytes actually sent: the header, the count and count targets.
    u8 get_size();
    // Send-side swap, as G_ExecutePhotonBlast_6x49::bswap_for_send.
    void bswap_for_send();
    // Sets the header size, byte-swaps and sends the packet.
    void send();

    G_ClientIDHeader header;
    CapturedTargetList targets;
};
LAYOUT_ASSERT(G_AttackFinished_6x46Size, sizeof(G_AttackFinished_6x46) == 0x30);

// 6x43/6x44/6x45: The fields shared by the three attack stage packets. Size checked:
// G_Attack_6x43::init, G_Attack_6x44::init and G_Attack_6x45::init set the header size to 2 words.
struct G_Attack_6x43_6x44_6x45 {
 struct G_ClientIDHeader header;
 s16 angle_y;
 s16 action_type; // the receiver passes it to the attack state's set_attack_kind
};
LAYOUT_ASSERT(G_Attack_6x43_6x44_6x45Size, sizeof(G_Attack_6x43_6x44_6x45) == 0x8);

// The three stages of a physical attack combo (6x43, then 6x44, then 6x45),
// one packet class each over the same fields.
// Sent by TNpcPlayer::send_partner_attack_stage_request and
// TObjPlayer::request_normal_attack_stage1; received by handle_6x43_attack. Size checked:
// G_Attack_6x43::init sets the header size to 2 words.
struct G_Attack_6x43 : G_Attack_6x43_6x44_6x45 {
 void init();
 void bswap();
 void send();
 G_Attack_6x43 &operator=(G_Attack_6x43 &src);
};
LAYOUT_ASSERT(G_Attack_6x43Size, sizeof(G_Attack_6x43) == 0x8);

// 6x44: The second attack combo stage. Sent by TNpcPlayer::send_partner_attack_stage_request and
// TObjPlayer::send_attack_stage2_request; received by handle_6x44_attack. Size checked:
// G_Attack_6x44::init sets the header size to 2 words.
struct G_Attack_6x44 : G_Attack_6x43_6x44_6x45 {
 void init();
 void bswap();
 void send();
 G_Attack_6x44 &operator=(G_Attack_6x44 &src);
};
LAYOUT_ASSERT(G_Attack_6x44Size, sizeof(G_Attack_6x44) == 0x8);

// 6x45: The third attack combo stage. Sent by TNpcPlayer::send_partner_attack_stage_request and
// TObjPlayer::send_attack_stage3_request; received by handle_6x45_attack. Size checked:
// G_Attack_6x45::init sets the header size to 2 words.
struct G_Attack_6x45 : G_Attack_6x43_6x44_6x45 {
 void init();
 void bswap();
 void send();
 G_Attack_6x45 &operator=(G_Attack_6x45 &src);
};
LAYOUT_ASSERT(G_Attack_6x45Size, sizeof(G_Attack_6x45) == 0x8);

// 6xA9/6xAA: Barba Ray (TBoss7DeRolLeC) action changes. The client swaps
// their header through G_ClientIDHeader::bswap; client_id holds the boss's
// entity id.
// Sent by TBoss7DeRolLeC::set_state_and_send; received by handle_6xA9_barba_ray_boss_actions. Size
// checked: G_BarbaRayBossActions_6xA9::init sets the header size to 2 words.
struct G_BarbaRayBossActions_6xA9 {
 struct G_ClientIDHeader header;
 s16 what; // the boss state (transition_enemy_state)
 s16 action_index;
 void bswap();
 void send();
 void init();
};
LAYOUT_ASSERT(G_BarbaRayBossActions_6xA9Size, sizeof(G_BarbaRayBossActions_6xA9) == 0x8);

// 6xAA: Barba Ray's state with its parameters. Sent by TBoss7DeRolLeC::set_state_and_send; received
// by handle_6xAA_barba_ray_boss_actions. Size checked: G_BarbaRayBossActions_6xAA::init sets the
// header size to 3 words.
struct G_BarbaRayBossActions_6xAA {
 struct G_ClientIDHeader header;
 s16 what; // the boss state (transition_enemy_state)
 s16 action_index;
 u32 target_client_id;
 void bswap();
 void send();
 void init();
};
LAYOUT_ASSERT(G_BarbaRayBossActions_6xAASize, sizeof(G_BarbaRayBossActions_6xAA) == 0xC);

// 6x5E: A player buys an item from a shop. Sent by send_buy_shop_item; received by
// handle_6x5E_buy_shop_item. Size checked: its constructor sets the header size to 6 words.
struct G_BuyShopItem_6x5E {
 struct G_ClientIDHeader header;
 TItemData item_data;
 G_BuyShopItem_6x5E();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_BuyShopItem_6x5ESize, sizeof(G_BuyShopItem_6x5E) == 0x18);

// 6x48: A player finishes casting a technique. Sent by TObjPlayer::pay_tp_and_send_6x48_cast;
// received by handle_6x48_cast_technique_complete. Size checked:
// G_CastTechniqueComplete_6x48::init sets the header size to 2 words.
struct G_CastTechniqueComplete_6x48 {
 struct G_ClientIDHeader header;
 s16 technique_number;
 s16 level;
 void bswap();
 G_CastTechniqueComplete_6x48 &operator=(G_CastTechniqueComplete_6x48 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_CastTechniqueComplete_6x48Size, sizeof(G_CastTechniqueComplete_6x48) == 0x8);

// 6x47: our code carries this as G_CastTechnique_6x47 (pso/network/protocol/cast_packets.h).

// 6x2F: Changes a player's HP. Sent by TObjPlayer::send_name_and_state and
// send_6x2F_change_player_hp; received by handle_6x2F_change_player_hp. Size checked:
// G_ChangePlayerHP_6x2F::init sets the header size to 3 words.
struct G_ChangePlayerHP_6x2F {
 struct G_ClientIDHeader header;
 s32 type;
 s16 amount;
 u16 client_id;
 void bswap();
 G_ChangePlayerHP_6x2F &operator=(G_ChangePlayerHP_6x2F &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_ChangePlayerHP_6x2FSize, sizeof(G_ChangePlayerHP_6x2F) == 0xC);

// 6x30: A player's new level and stats after a level up. Sent by
// TObjPlayer::send_6x30_change_player_level; received by handle_6x30_change_player_level. Size
// checked: G_ChangePlayerLevel_6x30::init sets the header size to 5 words.
struct G_ChangePlayerLevel_6x30 {
 struct G_ClientIDHeader header;
 s16 atp;
 s16 mst;
 s16 evp;
 s16 hp;
 s16 dfp;
 s16 ata;
 s16 level;
 s16 is_level_down;
 G_ChangePlayerLevel_6x30 &operator=(G_ChangePlayerLevel_6x30 &src);
 void send();
 void bswap();
 void init();
};
LAYOUT_ASSERT(G_ChangePlayerLevel_6x30Size, sizeof(G_ChangePlayerLevel_6x30) == 0x14);

// 6x0E: Clears a player's negative status effects. Received by
// handle_6x0E_clear_negative_status_effects. Size checked: G_ClearNegativeStatusEffects_6x0E::init
// sets the header size to 1 word.
struct G_ClearNegativeStatusEffects_6x0E {
 struct G_ClientIDHeader header;
 G_ClearNegativeStatusEffects_6x0E &operator=(G_ClearNegativeStatusEffects_6x0E &src);
 void init();
};
LAYOUT_ASSERT(G_ClearNegativeStatusEffects_6x0ESize, sizeof(G_ClearNegativeStatusEffects_6x0E) == 0x4);

// 6x3A: Clears a player's photon blast ready flag. Sent by
// PhotonBlastGauge::send_6x3A_clear_photon_blast_ready_flag; received by
// handle_6x3A_clear_photon_blast_ready_flag. Size checked: G_ClearPhotonBlastReadyFlag_6x3A::init
// sets the header size to 1 word.
struct G_ClearPhotonBlastReadyFlag_6x3A {
 struct G_ClientIDHeader header;
 G_ClearPhotonBlastReadyFlag_6x3A &operator=(const G_ClearPhotonBlastReadyFlag_6x3A &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_ClearPhotonBlastReadyFlag_6x3ASize, sizeof(G_ClearPhotonBlastReadyFlag_6x3A) == 0x4);

// 6x3B: Clears a player's temporary photon blast state flags. Sent by
// PhotonBlastGauge::reinit_photon_blast_gauge; received by
// handle_6x3B_clear_temporary_photon_blast_state_flags. Size checked:
// G_ClearTemporaryPhotonBlastStateFlags_6x3B::init sets the header size to 1 word.
struct G_ClearTemporaryPhotonBlastStateFlags_6x3B {
 struct G_ClientIDHeader header;
 G_ClearTemporaryPhotonBlastStateFlags_6x3B &operator=(const G_ClearTemporaryPhotonBlastStateFlags_6x3B &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_ClearTemporaryPhotonBlastStateFlags_6x3BSize, sizeof(G_ClearTemporaryPhotonBlastStateFlags_6x3B) == 0x4);

// 6x2B: The 0x18-byte form of 6x2B; handle_6x2B_create_inventory_item checks the header size for
// it, and the full form adds equip_item. Size checked: G_CreateInventoryItem_DC_6x2B::init sets
// the header size to 6 words.
struct G_CreateInventoryItem_DC_6x2B {
 struct G_ClientIDHeader header;
 TItemData item_data;
 G_CreateInventoryItem_DC_6x2B &operator=(G_CreateInventoryItem_DC_6x2B &src);
 void init();
};
LAYOUT_ASSERT(G_CreateInventoryItem_DC_6x2BSize, sizeof(G_CreateInventoryItem_DC_6x2B) == 0x18);

// 6x2B: Creates an item in a player's inventory. Sent by TObjPlayer::request_inventory_item;
// received by handle_6x2B_create_inventory_item. Size checked:
// G_CreateInventoryItem_PC_V3_BB_6x2B::init sets the header size to 7 words.
struct G_CreateInventoryItem_PC_V3_BB_6x2B : G_CreateInventoryItem_DC_6x2B {
 u8 unused1;
 s8 equip_item;  // handle_6x2B_create_inventory_item sign-extends it
 u8 unused2[2];
 void bswap();
 G_CreateInventoryItem_PC_V3_BB_6x2B &operator=(G_CreateInventoryItem_PC_V3_BB_6x2B &src);
 G_CreateInventoryItem_PC_V3_BB_6x2B *init();
 void send();
};
LAYOUT_ASSERT(G_CreateInventoryItem_PC_V3_BB_6x2BSize, sizeof(G_CreateInventoryItem_PC_V3_BB_6x2B) == 0x1C);

// 6xAB: Creates a lobby chair under a player. Sent by TObjPlayer::send_state_sync; received by
// handle_6xAB. Size checked: G_CreateLobbyChair_6xAB::init sets the header size to 2 words.
struct G_CreateLobbyChair_6xAB {
 struct G_ClientIDHeader header;
 s16 animation_number;
 u16 flags; // bit 0: the sender has a keyboard; bit 1: the alternate chair animation
 void init();
 void bswap();
 void send();
 G_CreateLobbyChair_6xAB &operator=(G_CreateLobbyChair_6xAB &src);
 s32 has_keyboard();
 s32 uses_alt_chair();
 void set_keyboard();
 void set_alt_chair();
};
LAYOUT_ASSERT(G_CreateLobbyChair_6xABSize, sizeof(G_CreateLobbyChair_6xAB) == 0x8);

// 6x19: Sent by TBoss4DarkFalz::send_action_packet / send_code_25_4, read by
// handle_6x19_dark_falz_actions. The header holds the boss's entity id; its byte swap is
// G_ClientIDHeader's.
// Size checked: G_DarkFalzActions_6x19::init sets the header size to 4 words.
struct G_DarkFalzActions_6x19 {
 struct G_ClientIDHeader header;
 s16 state;       // dark_falz_state_table index to change to, -1 for none
 u16 unknown_a3;
 s32 form_action; // handed to the active form (Type1/2/3), -1 for none
 u32 unused;
 void init();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_DarkFalzActions_6x19Size, sizeof(G_DarkFalzActions_6x19) == 0x10);

// 6x14: our code carries this as DeRolLeActionTargetPacket (pso/boss/derolle/TBoss2DeRolLe.h),
// which handle_6x14_de_rol_le_boss_actions_with_target reads.

// 6x13: our code carries this as DeRolLeActionPacket (pso/boss/derolle/TBoss2DeRolLe.h), which
// handle_6x13_de_rol_le_boss_actions reads.

// 6x29: Deletes an item, or part of a stack, from a player's inventory. Sent by
// TObjPlayer::send_6x29_delete_item; received by handle_6x29_delete_inventory_item. Size checked:
// G_DeleteInventoryItem_6x29::init sets the header size to 3 words.
struct G_DeleteInventoryItem_6x29 {
 struct G_ClientIDHeader header;
 u32 item_id;
 u32 amount;
 void bswap();
 G_DeleteInventoryItem_6x29 &operator=(G_DeleteInventoryItem_6x29 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_DeleteInventoryItem_6x29Size, sizeof(G_DeleteInventoryItem_6x29) == 0xC);

// The item ids 6xAC deletes. Layout from newserv, not used by our code yet.
struct ItemIDList {
 u32 id[0x1E];
};

// 6xAC: Deletes several items from a player's inventory. Received by handle_6xAC. Size checked:
// G_DeleteMultipleInventoryItems_6xAC::init sets the header size to 32 words.
struct G_DeleteMultipleInventoryItems_6xAC {
 struct G_ClientIDHeader header;
 s32 num_items;
 struct ItemIDList item_ids;
 void bswap();
 G_DeleteMultipleInventoryItems_6xAC &operator=(G_DeleteMultipleInventoryItems_6xAC &src);
 void init();
};
LAYOUT_ASSERT(G_DeleteMultipleInventoryItems_6xACSize, sizeof(G_DeleteMultipleInventoryItems_6xAC) == 0x80);

// 6x5C/6x63: Destroys an item on the floor. Sent by build_6x63_packet; received by
// handle_6x5C_destroy_floor_item and handle_6x63_destroy_floor_item. Size checked:
// build_6x63_packet sets the header size to 3 words.
struct G_DestroyFloorItem_6x5C_6x63 {
 struct G_UnusedHeader header;
 u32 item_id;
 u32 floor;
};
LAYOUT_ASSERT(G_DestroyFloorItem_6x5C_6x63Size, sizeof(G_DestroyFloorItem_6x5C_6x63) == 0xC);

// 6x81: Stops a player from dropping their weapon on death. Sent by
// TObjPlayer::send_disable_drop_weapon_on_death; received by
// handle_6x81_disable_drop_weapon_on_death. Size checked: G_DisableDropWeaponOnDeath_6x81::init
// sets the header size to 1 word.
struct G_DisableDropWeaponOnDeath_6x81 {
 struct G_ClientIDHeader header;
 G_DisableDropWeaponOnDeath_6x81 &operator=(G_DisableDropWeaponOnDeath_6x81 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_DisableDropWeaponOnDeath_6x81Size, sizeof(G_DisableDropWeaponOnDeath_6x81) == 0x4);

// 6x1C: Turns PK mode off for a player. Sent by TObjPlayer::send_disable_pk_mode; received by
// handle_6x1C_disable_pk_mode_for_player. Size checked: G_DisablePKModeForPlayer_6x1C::init sets
// the header size to 1 word.
struct G_DisablePKModeForPlayer_6x1C {
 struct G_ClientIDHeader header;
 G_DisablePKModeForPlayer_6x1C &operator=(G_DisablePKModeForPlayer_6x1C &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_DisablePKModeForPlayer_6x1CSize, sizeof(G_DisablePKModeForPlayer_6x1C) == 0x4);

// 6x7B: Ends a player's stealth suit effect. Sent by TObjPlayer::send_disable_stealth_suit_effect;
// received by handle_6x7B_disable_stealth_suit_effect. Size checked:
// G_DisableStealthSuitEffect_6x7B::init sets the header size to 1 word.
struct G_DisableStealthSuitEffect_6x7B {
 struct G_ClientIDHeader header;
 G_DisableStealthSuitEffect_6x7B &operator=(G_DisableStealthSuitEffect_6x7B &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_DisableStealthSuitEffect_6x7BSize, sizeof(G_DisableStealthSuitEffect_6x7B) == 0x4);

// 6x38: A player donates to another player's photon blast gauge. Sent by
// PhotonBlastGauge::draw_party_label; received by handle_6x38_donate_to_photon_blast. Size
// checked: G_DonateToPhotonBlast_6x38::init_subcommand_6x38 sets the header size to 2 words.
struct G_DonateToPhotonBlast_6x38 {
 struct G_ClientIDHeader header;
 u16 target_client_id;
 s16 unused;
 void bswap_fields();
 void *copy_packet_header_6x38(void *src);
 void init_subcommand_6x38();
 void send_state();
};
LAYOUT_ASSERT(G_DonateToPhotonBlast_6x38Size, sizeof(G_DonateToPhotonBlast_6x38) == 0x8);

// 6x72: A joining player has finished loading into the game. Sent by TLobby::on_game_player_add and
// init_6x72_resume_packet; received by handle_6x72_done_loading_into_game. Size checked:
// init_6x72_resume_packet sets the header size to 1 word.
struct G_DoneLoadingIntoGame_6x72 {
 struct G_UnusedHeader header;
};
LAYOUT_ASSERT(G_DoneLoadingIntoGame_6x72Size, sizeof(G_DoneLoadingIntoGame_6x72) == 0x4);

// 6x10/6x11: The Dragon's action state and target. Received by handle_6x10_dragon_boss_actions and
// handle_6x11_dragon_boss_actions. Used by our code; size not checked against a sender yet.
struct G_DragonBossActions_6x10_6x11 {
 struct G_EntityIDHeader header;
 s16 state;
 s16 action_index;
 u32 target_id;
 void bswap_6x10();
 void bswap_6x11();
};

// 6x12: The Dragon's state with its position. Sent by TBoss1Dragon::send_state_sync and
// TBoss1Dragon::request_state_change; received by handle_6x12_dragon_boss_actions. Size checked:
// G_DragonBossActions_6x12::init sets the header size to 5 words.
struct G_DragonBossActions_6x12 {
 G_DragonBossActions_6x10_6x11 action;
 f32 x;
 f32 z;
 void init();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_DragonBossActions_6x12Size, sizeof(G_DragonBossActions_6x12) == 0x14);

// 6x2A: A player drops an inventory item on the floor. Sent by TObjPlayer::send_6x2A_drop_item;
// received by handle_6x2A_drop_item. Size checked: G_DropItem_6x2A::init sets the header size to 6
// words.
struct G_DropItem_6x2A {
 struct G_ClientIDHeader header;
 s16 amount;
 s16 floor;
 u32 item_id;
 Vec pos;
 void bswap();
 G_DropItem_6x2A &operator=(G_DropItem_6x2A &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_DropItem_6x2ASize, sizeof(G_DropItem_6x2A) == 0x18);

// 6x5F: The 0x28-byte form of 6x5F, its item in the old item format; handle_6x5F_drop_item checks
// the header size to tell the two forms apart. Received by handle_6x5F_drop_item. Size checked:
// its constructor sets the header size to 10 words.
struct G_DropItem_DC_6x5F {
 G_ClientIDHeader header;
 FloorItem item;
 G_DropItem_DC_6x5F();
};
LAYOUT_ASSERT(G_DropItem_DC_6x5FSize, sizeof(G_DropItem_DC_6x5F) == 0x28);

// 6x5F: An item drops on the floor from an enemy or a box. Sent by TLobby::drop_item_from_source
// and process_enemy_drop_request. Size checked: its constructor sets the header size to 11 words.
struct G_DropItem_PC_V3_BB_6x5F {
 G_DropItem_DC_6x5F __base_G_DropItem_DC_6x5F;
 u8 version[4];
 G_DropItem_PC_V3_BB_6x5F();
 void send();
};
LAYOUT_ASSERT(G_DropItem_PC_V3_BB_6x5FSize, sizeof(G_DropItem_PC_V3_BB_6x5F) == 0x2C);

// 6x5D: The 0x24-byte form of 6x5D, its item in the old item format; handle_6x5D_drop_stacked_item
// checks the header size to tell the two forms apart. Size checked: its constructor sets the
// header size to 9 words.
struct G_DropStackedItem_DC_6x5D {
 struct G_ClientIDHeader header;
 s16 floor;
 s16 room_id;
 struct VectorXZF pos;
 TItemData item_data;
 G_DropStackedItem_DC_6x5D();
};
LAYOUT_ASSERT(G_DropStackedItem_DC_6x5DSize, sizeof(G_DropStackedItem_DC_6x5D) == 0x24);

// 6x5D: Part of an item stack is dropped on the floor. Sent by send_drop_stacked_item; received by
// handle_6x5D_drop_stacked_item. Size checked: its constructor sets the header size to 10 words.
struct G_DropStackedItem_PC_V3_BB_6x5D : G_DropStackedItem_DC_6x5D {
 // The item data's version (2: v2 and later; a DC packet has none and is v0).
 u8 item_version;
 u8 unused3[3];
 G_DropStackedItem_PC_V3_BB_6x5D();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_DropStackedItem_PC_V3_BB_6x5DSize, sizeof(G_DropStackedItem_PC_V3_BB_6x5D) == 0x28);

// 6x82: Makes a player drop their weapon on death again. Sent by
// TObjPlayer::send_enable_drop_weapon_on_death; received by
// handle_6x82_enable_drop_weapon_on_death. Size checked: G_EnableDropWeaponOnDeath_6x82::init sets
// the header size to 1 word.
struct G_EnableDropWeaponOnDeath_6x82 {
 struct G_ClientIDHeader header;
 G_EnableDropWeaponOnDeath_6x82 &operator=(G_EnableDropWeaponOnDeath_6x82 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_EnableDropWeaponOnDeath_6x82Size, sizeof(G_EnableDropWeaponOnDeath_6x82) == 0x4);

// 6x1B: Turns PK mode on for a player. Sent by TObjPlayer::send_enable_pk_mode; received by
// handle_6x1B_enable_pk_mode_for_player. Size checked: G_EnablePKModeForPlayer_6x1B::init sets the
// header size to 1 word.
struct G_EnablePKModeForPlayer_6x1B {
 struct G_ClientIDHeader header;
 G_EnablePKModeForPlayer_6x1B &operator=(G_EnablePKModeForPlayer_6x1B &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_EnablePKModeForPlayer_6x1BSize, sizeof(G_EnablePKModeForPlayer_6x1B) == 0x4);

// 6x7A: Starts a player's stealth suit effect. Sent by
// TObjPlayer::send_enable_stealth_suit_effect; received by handle_6x7A_enable_stealth_suit_effect.
// Size checked: G_EnableStealthSuitEffect_6x7A::init sets the header size to 1 word.
struct G_EnableStealthSuitEffect_6x7A {
 struct G_ClientIDHeader header;
 G_EnableStealthSuitEffect_6x7A &operator=(G_EnableStealthSuitEffect_6x7A &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_EnableStealthSuitEffect_6x7ASize, sizeof(G_EnableStealthSuitEffect_6x7A) == 0x4);

// 6x25: A player equips an item. Sent by send_6x25_equip_item; received by handle_6x25_equip_item.
// Size checked: G_EquipItem_6x25::init sets the header size to 3 words.
struct G_EquipItem_6x25 {
 struct G_ClientIDHeader header;
 u32 item_id;
 s32 equip_slot;
 void bswap();
 G_EquipItem_6x25 &operator=(G_EquipItem_6x25 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_EquipItem_6x25Size, sizeof(G_EquipItem_6x25) == 0xC);

// 6x73: Leaves the current quest. Received by handle_6x73_exit_quest. Layout from newserv, not
// used by our code yet.
struct G_ExitQuest_6x73 {
 struct G_UnusedHeader header;
};

// 6x28: A player feeds an item to their mag. Sent by send_6x28_feed_mag; received by
// handle_6x28_feed_mag. Size checked: G_FeedMag_6x28::init sets the header size to 3 words.
struct G_FeedMag_6x28 {
 struct G_ClientIDHeader header;
 u32 mag_item_id;
 u32 fed_item_id;
 void bswap();
 G_FeedMag_6x28 &operator=(G_FeedMag_6x28 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_FeedMag_6x28Size, sizeof(G_FeedMag_6x28) == 0xC);

// 6x9F: The Gal Gryphon's target (TBoss5Gryphon::send_target_update, applied by
// TBoss5Gryphon::set_target_from_action); header.client_id holds the gryphon's entity id.
// Sent by TBoss5Gryphon::send_target_update; received by handle_6x9F_gal_gryphon_boss_actions.
// Size checked: G_GalGryphonBossActions_6x9F::init sets the header size to 4 words.
struct G_GalGryphonBossActions_6x9F {
 struct G_ClientIDHeader header;
 u32 target_id;
 f32 x;  // TBoss5Gryphon::destination
 f32 z;
 void init();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_GalGryphonBossActions_6x9FSize, sizeof(G_GalGryphonBossActions_6x9F) == 0x10);

// 6xA0: The Gal Gryphon's next motion entry and where it starts it
// (TBoss5Gryphon::copy_spawn_params, applied by TBoss5Gryphon::apply_remote_action).
// Sent by TBoss5Gryphon::copy_spawn_params; received by handle_6xA0_gal_gryphon_boss_actions. Size
// checked: G_GalGryphonBossActions_6xA0::init sets the header size to 10 words.
struct G_GalGryphonBossActions_6xA0 {
 struct G_ClientIDHeader header;
 Vec pos;
 s32 angle_y;
 Boss5GryphonMotionEntry motion;
 void init();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_GalGryphonBossActions_6xA0Size, sizeof(G_GalGryphonBossActions_6xA0) == 0x28);

// 6x79: our code carries this as G_GoGoBall_6x79 (pso/object/lobby/LobbyGoGoBall.h), which
// handle_6x79_gogo_ball reads.

// 6xA8: The Gol Dragon's next action (TBoss8Dragon::send_action_packet / send_6xA8_action,
// applied by TBoss8Dragon::apply_6xA8_action); header.client_id holds the dragon's entity id.
// Sent by TBoss8Dragon::send_6xA8_action and TBoss8Dragon::send_action_packet; received by
// handle_6xA8_gol_dragon_boss_actions. Size checked: G_GolDragonBossActions_6xA8::init sets the
// header size to 6 words.
struct G_GolDragonBossActions_6xA8 {
 struct G_ClientIDHeader header;
 s16 what;          // the boss state (transition_enemy_state)
 s16 action_index;  // TBoss8Dragon::sequenceCursor
 u32 target_id;
 f32 x;             // TBoss8Dragon::destinationX / destinationZ
 f32 z;
 s8 effect_mode;    // TBoss8Dragon::set_mode_params
 void bswap();
 void send();
 void init();
};
LAYOUT_ASSERT(G_GolDragonBossActions_6xA8Size, sizeof(G_GolDragonBossActions_6xA8) == 0x18);

// The velocity the hit packets carry: copied as two words and byte-swapped by
// its own helper, not by VectorXZF::bswap.
// Used by our code; size not checked against a sender yet.
struct PacketVelocityXZ {
 f32 xz[2];
 void bswap();
};

// 6x4B/6x4C: The fields shared by the two hit packets. Size checked: G_HitByEnemy_6x4B::init and
// G_HitByEnemy_6x4C::init set the header size to 4 words.
struct G_HitByEnemy_6x4B_6x4C {
 struct G_ClientIDHeader header;
 s16 angle;
 s16 current_hp;
 struct PacketVelocityXZ velocity;
};
LAYOUT_ASSERT(G_HitByEnemy_6x4B_6x4CSize, sizeof(G_HitByEnemy_6x4B_6x4C) == 0x10);

// 6x4B (hurt) and 6x4C (knocked down) share the hit fields; each has its own
// packet class.
// Sent by TObjPlayer::send_6x4B_hurt_reaction; received by handle_6x4B_hit_by_enemy. Size checked:
// G_HitByEnemy_6x4B::init sets the header size to 4 words.
struct G_HitByEnemy_6x4B : G_HitByEnemy_6x4B_6x4C {
 void bswap();
 G_HitByEnemy_6x4B &operator=(G_HitByEnemy_6x4B &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_HitByEnemy_6x4BSize, sizeof(G_HitByEnemy_6x4B) == 0x10);

// 6x4C: A player is knocked down by an enemy. Sent by TObjPlayer::begin_fall_reaction; received by
// handle_6x4C_hit_by_enemy. Size checked: G_HitByEnemy_6x4C::init sets the header size to 4 words.
struct G_HitByEnemy_6x4C : G_HitByEnemy_6x4B_6x4C {
 void bswap();
 void init();
 void send();
 G_HitByEnemy_6x4C &operator=(G_HitByEnemy_6x4C &src);
};
LAYOUT_ASSERT(G_HitByEnemy_6x4CSize, sizeof(G_HitByEnemy_6x4C) == 0x10);

// 6x0A: An enemy's state flags and HP. Sent by init_6x0A_enemy_state_packet and
// TObjEnemy::send_6x0A_enemy_state; received by handle_6x0A_update_enemy_state. Size checked:
// init_6x0A_enemy_state_packet sets the header size to 3 words.
struct G_UpdateEnemyState_6x0A {
 struct G_EntityIDHeader header;
 u16 enemy_index;
 s16 total_damage;
 u32 game_flags;
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_UpdateEnemyState_6x0ASize, sizeof(G_UpdateEnemyState_6x0A) == 0xC);

// 6x0B: An object's state flags. Sent by send_object_state,
// TObjCollidable::send_object_state_update, TODoorAncient08::door_ancient08_sync_state,
// TODoorAncient09::door_ancient09_sync_state and 1 more; received by
// handle_6x0B_update_object_state. Size checked: G_UpdateObjectState_6x0B::init sets the header
// size to 3 words.
struct G_UpdateObjectState_6x0B {
 struct G_EntityIDHeader header;
 u32 flags;
 u32 object_index;
 void bswap();
 void init();
 void send();
};
LAYOUT_ASSERT(G_UpdateObjectState_6x0BSize, sizeof(G_UpdateObjectState_6x0B) == 0xC);

// 6x86: A player hits a destructible object. Received by handle_6x86_hit_destructible_object.
// Layout from newserv. Size checked: WallHitPacket::init (TOVS2Wall01.cpp) sets the header size to
// 4 words.
struct G_HitDestructibleObject_6x86 {
 struct G_UpdateObjectState_6x0B __base_G_UpdateObjectState_6x0B;
 u16 is_destroyed;
 u16 remaining_hits;
};
LAYOUT_ASSERT(G_HitDestructibleObject_6x86Size, sizeof(G_HitDestructibleObject_6x86) == 0x10);

// 6x2C: Holds a player in place. Sent by send_6x2C_impose_hold; received by
// handle_6x2C_impose_hold. Size checked: G_ImposeHold_6x2C::init sets the header size to 5 words.
struct G_ImposeHold_6x2C {
 struct G_ClientIDHeader header;
 s16 frames;       // the receiver's movement_hold.set_frames
 s16 effect_type;  // the receiver's movement_hold.set_effect_type
 struct VectorXZF pos;
 f32 trigger_radius2;
 void bswap();
 void init();
 void send();
 G_ImposeHold_6x2C &operator=(G_ImposeHold_6x2C &src);
};
LAYOUT_ASSERT(G_ImposeHold_6x2CSize, sizeof(G_ImposeHold_6x2C) == 0x14);

// 6x21: A player warps to another floor. Sent by send_6x21_inter_level_warp; received by
// handle_6x21_inter_level_warp. Size checked: G_InterLevelWarp_6x21::init sets the header size to
// 2 words.
struct G_InterLevelWarp_6x21 {
 struct G_ClientIDHeader header;
 s32 floor;
 G_InterLevelWarp_6x21 &operator=(const G_InterLevelWarp_6x21 &src);
 void bswap();
 void init();
 void send();
};
LAYOUT_ASSERT(G_InterLevelWarp_6x21Size, sizeof(G_InterLevelWarp_6x21) == 0x8);

// 6x94: Warps a player to another floor. Received by handle_6x94_inter_level_warp. Used by our
// code; size not checked against a sender yet.
struct G_InterLevelWarp_6x94 {
 G_ClientIDHeader header; // This command leaves the client ID word unused.
 s16 floor;
 u8 unused[2];
};

LAYOUT_ASSERT(G_InterLevelWarp_6x94_size, sizeof(G_InterLevelWarp_6x94) == 8);
LAYOUT_ASSERT(G_InterLevelWarp_6x94_floor_offset, offsetof(G_InterLevelWarp_6x94, floor) == 4);

// 6x55: A player warps to another place on the same floor. Sent by send_6x55_intra_map_warp and
// TObjPlayer::send_warp_position; received by handle_6x55_intra_map_warp. Size checked:
// G_IntraMapWarp_6x55::init sets the header size to 8 words.
struct G_IntraMapWarp_6x55 {
 G_ClientIDHeader header;
 u32 angle_y;
 Vec from_pos;
 Vec pos;

 void init();
 void bswap();
 void send();
 G_IntraMapWarp_6x55 &operator=(G_IntraMapWarp_6x55 &src);
};

LAYOUT_ASSERT(G_IntraMapWarp_6x55_size, sizeof(G_IntraMapWarp_6x55) == 0x20);
LAYOUT_ASSERT(G_IntraMapWarp_6x55_position_offset, offsetof(G_IntraMapWarp_6x55, from_pos) == 0x8);
LAYOUT_ASSERT(G_IntraMapWarp_6x55_destination_offset, offsetof(G_IntraMapWarp_6x55, pos) == 0x14);

struct game_command_header;
void handle_6x94_inter_level_warp(game_command_header *command);
void send_6x55_intra_map_warp(u16 id, const Vec *destination, s32 yaw);
void handle_6x55_intra_map_warp(game_command_header *command);
void bswap_6x94_inter_level_warp(G_InterLevelWarp_6x94 *packet);
struct TObjPlayer;
void send_6x21_inter_level_warp(TObjPlayer *player, s32 floor);

// 6x04: Activates a switch by its token. Received by handle_6x04_legacy_activate_switch_by_token.
// Used by our code; size not checked against a sender yet.
struct G_LegacyActivateSwitchByToken_6x04 {
 struct G_ParameterHeader header;
 u16 switch_token;
 u16 unused;
 void bswap();
};

// 6x09: Kills an enemy. Received by handle_6x09_legacy_kill_enemy. Used by our code; size not
// checked against a sender yet.
struct G_LegacyKillEnemy_6x09 {
 struct G_EntityIDHeader header;
};

// 6x9B: Raises the level of all a player's techniques. Sent by
// TObjPlayer::send_level_up_all_techniques; received by handle_6x9B_level_up_all_techniques. Size
// checked: G_LevelUpAllTechniques_6x9B::init sets the header size to 2 words.
struct G_LevelUpAllTechniques_6x9B {
 struct G_ClientIDHeader header;
 u8 num_levels;
 u8 unused[3];
 G_LevelUpAllTechniques_6x9B &operator=(G_LevelUpAllTechniques_6x9B &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_LevelUpAllTechniques_6x9BSize, sizeof(G_LevelUpAllTechniques_6x9B) == 0x8);

// 6x58: A player plays a lobby animation. Sent by TObjPlayer::send_6x58_lobby_animation; received
// by handle_6x58_lobby_animation. Size checked: G_LobbyAnimation_6x58::init sets the header size
// to 2 words.
struct G_LobbyAnimation_6x58 {
 struct G_ClientIDHeader header;
 s16 animation_number;
 u16 flags; // bit 0: the sender has a keyboard
 void init();
 void bswap();
 void send();
 G_LobbyAnimation_6x58 &operator=(G_LobbyAnimation_6x58 &src);
 s32 has_keyboard();
 void set_keyboard();
};
LAYOUT_ASSERT(G_LobbyAnimation_6x58Size, sizeof(G_LobbyAnimation_6x58) == 0x8);

// 6x32: The medical center revives all players. Sent by
// TObjPlayer::send_medical_center_revive_all_players; received by
// handle_6x32_medical_center_revive_all_players. Size checked:
// G_MedicalCenterReviveAllPlayers_6x32::init sets the header size to 1 word.
struct G_MedicalCenterReviveAllPlayers_6x32 {
 struct G_UnusedHeader header;
 void send();
 void init();
};
LAYOUT_ASSERT(G_MedicalCenterReviveAllPlayers_6x32Size, sizeof(G_MedicalCenterReviveAllPlayers_6x32) == 0x4);

// 6xA6: Changes a trade proposal between two players. Sent by TLobby::send_trade_proposal_modify,
// cancel_trade_for_member_out_of_range, send_trade_busy_reply, TLobby::send_modify_trade_proposal
// and 2 more; received by handle_6xA6_modify_trade_proposal. Size checked:
// build_6xA6_modify_trade_proposal sets the header size to 4 words.
struct G_ModifyTradeProposal_6xA6 {
 struct G_ClientIDHeader header;
 u8 what;
 u8 result;
 // what 7: the member who left trade range.
 s16 out_of_range_client_id;
 u32 item_id;
 u32 amount;
 void bswap();
 // Stamps the local client id and byte-swaps the packet for sending.
 void prepare();
 void prepare_and_send(u32 client_id);
};
LAYOUT_ASSERT(G_ModifyTradeProposal_6xA6Size, sizeof(G_ModifyTradeProposal_6xA6) == 0x10);

// 6x41/6x42: A player runs to a position. Sent by TNpcPlayer::send_run_request,
// TObjPlayer::send_6x42_run_to_position and qst_op_run_to_coord; received by
// handle_6x41_move_to_position and handle_6x42_move_to_position. Size checked:
// G_MoveToPosition_6x41_6x42::init sets the header size to 3 words.
struct G_MoveToPosition_6x41_6x42 {
 struct G_ClientIDHeader header;
 struct VectorXZF pos;
 // Clears the position and sets the 6x42 header.
 void init();
 G_MoveToPosition_6x41_6x42 &operator=(const G_MoveToPosition_6x41_6x42 &src);
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_MoveToPosition_6x41_6x42Size, sizeof(G_MoveToPosition_6x41_6x42) == 0xC);

// 6x69: quest NPC partner control (create, release or take over an NPC player).
// Sent by send_npc_create, send_npc_control_notify_players, create_default_companion,
// create_companion and 3 more; received by handle_6x69_npc_control. Size checked:
// G_NPCControl_6x69::init sets the header size to 3 words.
struct G_NPCControl_6x69 {
 G_ClientIDHeader header;
 u16 controller_id;  // client that runs the NPC
 u16 npc_client_id;  // player slot of the NPC
 s16 command;        // 0/3 create, 1 release, 2 take over all NPCs
 s16 npc_type;       // load_npc_player_template index
 void init();
 void send();
 void bswap();
};
LAYOUT_ASSERT(G_NPCControl_6x69Size, sizeof(G_NPCControl_6x69) == 0xC);

// 6xA3: Olga Flow's action state. Received by handle_6xA3_olga_flow_boss_actions. Layout from
// newserv. Size checked: OlgaFlowPlotActionMsg::initialize sets the header size to 5 words.
struct G_OlgaFlowBossActions_6xA3 {
 struct G_EntityIDHeader header;
 u8 unknown_a1;
 u8 unknown_a2;
 u8 unknown_a3[0x0E];
};
LAYOUT_ASSERT(G_OlgaFlowBossActions_6xA3Size, sizeof(G_OlgaFlowBossActions_6xA3) == 0x14);

// 6xA4/6xA5: Olga Flow's action state with its parameters. Received by
// handle_6xA4_olga_flow_boss_actions and handle_6xA5_olga_flow_boss_actions. Layout from newserv.
// Size checked: OlgaFlowActionMsg::initialize (6xA4) and OlgaFlowType2ActionMsg::initialize (6xA5)
// set the header size to 5 words.
struct G_OlgaFlowBossActions_6xA4_6xA5 {
 struct G_EntityIDHeader header;
 u8 what;
 u8 pos_bytes[3];
 u8 state_bytes[3];
 u8 unused1;
 u8 ext_state_bytes[4];
 u8 unused2[4];
};
LAYOUT_ASSERT(G_OlgaFlowBossActions_6xA4_6xA5Size, sizeof(G_OlgaFlowBossActions_6xA4_6xA5) == 0x14);

// 6xAD: The actions of Olga Flow's subordinate parts. Received by
// handle_6xAD_olga_flow_subordinate_boss_actions. Used by our code; size not checked against a
// sender yet.
struct G_OlgaFlowSubordinateBossActions_6xAD {
 struct G_UnusedHeader header;
 s8 actions[0x40];
};

// 6x37: A player fires a photon blast. Sent by TObjPlayer::send_6x37_photon_blast; received by
// handle_6x37_photon_blast. Size checked: G_PhotonBlast_6x37::init sets the header size to 2
// words.
struct G_PhotonBlast_6x37 {
 struct G_ClientIDHeader header;
 s16 amount;
 s16 unused;
 void init();
 void bswap();
 void send();
 G_PhotonBlast_6x37 &operator=(G_PhotonBlast_6x37 &src);
};
LAYOUT_ASSERT(G_PhotonBlast_6x37Size, sizeof(G_PhotonBlast_6x37) == 0x8);

// 6x5A: A player asks to pick up a floor item. Sent by TItem::interact; received by
// handle_6x5A_pick_up_item_request. Size checked: its constructor sets the header size to 3 words.
struct G_PickUpItemRequest_6x5A {
 struct G_ClientIDHeader header;
 u32 item_id;
 s16 floor;
 u16 unused;
 G_PickUpItemRequest_6x5A();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_PickUpItemRequest_6x5ASize, sizeof(G_PickUpItemRequest_6x5A) == 0xC);

// 6x59: A player picks up a floor item. Received by handle_6x59_pick_up_item. Size checked: its
// constructor sets the header size to 3 words.
struct G_PickUpItem_6x59 {
 struct G_ClientIDHeader header;
 u16 client_id2;
 s16 floor;
 u32 item_id;
 G_PickUpItem_6x59();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_PickUpItem_6x59Size, sizeof(G_PickUpItem_6x59) == 0xC);

// 6x83: A player places a trap. Sent by TObjPlayer::send_trap_packet; received by
// handle_6x83_place_trap. Size checked: G_PlaceTrap_6x83::init sets the header size to 2 words.
struct G_PlaceTrap_6x83 {
 struct G_ClientIDHeader header;
 s16 trap_type;
 s16 trap_index;
 void bswap();
 G_PlaceTrap_6x83 &operator=(G_PlaceTrap_6x83 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_PlaceTrap_6x83Size, sizeof(G_PlaceTrap_6x83) == 0x8);

// 6xB2: our code carries this as G_PlaySound_6xB2 (pso/network/protocol/GameplaySoundPacket.h),
// which handle_6xB2_play_sound_from_player reads.

// 6x9E: Plays the camera shutter sound for a player. Received by
// handle_6x9E_player_camera_shutter_sound. Layout from newserv, not used by our code yet.
struct G_PlayerCameraShutterSound_6x9E {
 struct G_ClientIDHeader header;
};

// 6x4D: A player dies. Sent by TObjPlayer::prepare_death; received by handle_6x4D_player_died.
// Size checked: its constructor sets the header size to 2 words.
struct G_PlayerDied_6x4D {
 struct G_ClientIDHeader header;
 FlagWord death_flags;
 G_PlayerDied_6x4D();
 void bswap();
 void send();
 G_PlayerDied_6x4D &operator=(G_PlayerDied_6x4D &src);
};
LAYOUT_ASSERT(G_PlayerDied_6x4DSize, sizeof(G_PlayerDied_6x4D) == 0x8);

// 6x4E: A dead player can be revived. Sent by TObjPlayer::send_6x4E_player_revivable; received by
// handle_6x4E_player_revivable. Size checked: G_PlayerRevivable_6x4E::init sets the header size to
// 1 word.
struct G_PlayerRevivable_6x4E {
 struct G_ClientIDHeader header;
 void init();
 void send();
 G_PlayerRevivable_6x4E &operator=(const G_PlayerRevivable_6x4E &src);
};
LAYOUT_ASSERT(G_PlayerRevivable_6x4ESize, sizeof(G_PlayerRevivable_6x4E) == 0x4);

// 6x4F: A player is revived. Sent by TObjPlayer::send_6x4F_revived; received by
// handle_6x4F_player_revived. Size checked: G_PlayerRevived_6x4F::init sets the header size to 1
// word.
struct G_PlayerRevived_6x4F {
 struct G_ClientIDHeader header;
 void init();
 void send();
 G_PlayerRevived_6x4F &operator=(const G_PlayerRevived_6x4F &src);
};
LAYOUT_ASSERT(G_PlayerRevived_6x4FSize, sizeof(G_PlayerRevived_6x4F) == 0x4);

// 6x2D: Releases a held player. Sent by send_release_hold; received by handle_6x2D_release_hold.
// Size checked: G_ReleaseHold_6x2D::init sets the header size to 1 word.
struct G_ReleaseHold_6x2D {
 struct G_ClientIDHeader header;
 G_ReleaseHold_6x2D &operator=(G_ReleaseHold_6x2D &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_ReleaseHold_6x2DSize, sizeof(G_ReleaseHold_6x2D) == 0x4);

// 6x88: our code carries this as PlayerRestoreSizePacket (pso/player/PlayerScaleState.h), which
// handle_6x88_restore_shrunken_player reads.

// 6x33: Revives a player. Sent by send_6x33_revive_player; received by handle_6x33_revive_player.
// Size checked: G_RevivePlayer_6x33::init sets the header size to 2 words.
struct G_RevivePlayer_6x33 {
 struct G_ClientIDHeader header;
 u16 client_id2;
 s16 unused;
 void bswap();
 G_RevivePlayer_6x33 &operator=(G_RevivePlayer_6x33 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_RevivePlayer_6x33Size, sizeof(G_RevivePlayer_6x33) == 0x8);

// 6xA1: Revives a player. Sent by TObjPlayer::send_6xA1_player_id; received by
// handle_6xA1_revive_player_v3. Size checked: G_RevivePlayer_V3_BB_6xA1::init sets the header size
// to 1 word.
struct G_RevivePlayer_V3_BB_6xA1 {
 struct G_ClientIDHeader header;
 G_RevivePlayer_V3_BB_6xA1 &operator=(G_RevivePlayer_V3_BB_6xA1 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_RevivePlayer_V3_BB_6xA1Size, sizeof(G_RevivePlayer_V3_BB_6xA1) == 0x4);

// 6x97: A player's choice after failing a challenge mode stage. Sent by send_and_handle_60_wrapper
// and send_challenge_retry_cmd; received by handle_6x97_select_challenge_mode_failure_option. Size
// checked: build_6x97_packet sets the header size to 5 words.
struct G_SelectChallengeModeFailureOption_6x97 {
 struct G_UnusedHeader header;
 u32 client_id;
 u32 is_retry;
 u32 unused1;
 u32 unused2;
};
LAYOUT_ASSERT(G_SelectChallengeModeFailureOption_6x97Size, sizeof(G_SelectChallengeModeFailureOption_6x97) == 0x14);

// 6x06: our code carries this as G_SendGuildCard_6x06
// (pso/network/protocol/SendGuildCardPacket.h).

// 6x52: A player's animation state. Sent by TObjPlayer::send_6x52_animation_state; received by
// handle_6x52_set_animation_state. Size checked: G_SetAnimationState_6x52::init sets the header
// size to 3 words.
struct G_SetAnimationState_6x52 {
 struct G_ClientIDHeader header;
 s16 animation;
 s16 state;
 s32 angle;
 void init();
 void bswap();
 void send();
 G_SetAnimationState_6x52 &operator=(G_SetAnimationState_6x52 &src);
};
LAYOUT_ASSERT(G_SetAnimationState_6x52Size, sizeof(G_SetAnimationState_6x52) == 0xC);

// 6xAE: A player's animation state, sent to a joining player. Received by
// handle_6xAE_set_animation_state. Size checked: G_SetAnimationState_6xAE::init sets the header
// size to 4 words.
struct G_SetAnimationState_6xAE {
 struct G_ClientIDHeader header;
 s16 animation_number;
 u16 unused;
 u32 player_flags;
 f32 animation_timer;
 void bswap();
 G_SetAnimationState_6xAE &operator=(G_SetAnimationState_6xAE &src);
 void init();
 void send_to(u32 client);
};
LAYOUT_ASSERT(G_SetAnimationState_6xAESize, sizeof(G_SetAnimationState_6xAE) == 0x10);

// 6x7D: The client reads what, state and is_alive as signed bytes and the
// params as signed words.
// Sent by send_battle_mode_params, send_6x7D_set_battle_mode_data,
// TPlayerBattleCtrl::send_player_ready, TPlayerBattleCtrl::send_battle_mode_state and 1 more;
// received by handle_6x7D_set_battle_mode_data. Used by our code. Size checked:
// build_6x7D_set_battle_mode_data sets the header size to 6 words. The header is byte-swapped as a
// G_ClientIDHeader.
struct G_SetBattleModeData_6x7D {
 struct G_ClientIDHeader header;
 s8 what;
 s8 state;  // the controller state to switch to when what is 0
 u8 unused;
 s8 is_alive;
 s32 params[4];
 void send();
 void bswap();
 void send_to_leader();
};
LAYOUT_ASSERT(G_SetBattleModeData_6x7DSize, sizeof(G_SetBattleModeData_6x7D) == 0x18);

// 6x7F: The final places and scores of a battle, one row per player. Received by
// handle_6x7F_battle_scores, which copies the rows into duel_result_table; nothing in our code
// sends it. Used by our code; size not checked against a sender.
struct G_BattleScores_6x7F {
 struct G_ClientIDHeader header;
 BattleRanking rankings[4];
};
LAYOUT_ASSERT(G_BattleScores_6x7FSize, sizeof(G_BattleScores_6x7F) == 0x24);

// 6x6A: The boss warp flags. Sent by TObjCityMainWarpChallenge::send_6x6A_set_boss_warp_flags and
// TObjWarpBoss::send_cmd_6A; received by handle_6x6A_set_boss_warp_flags. Size checked:
// G_SetBossWarpFlags_6x6A::init sets the header size to 2 words.
struct G_SetBossWarpFlags_6x6A {
 struct G_EntityIDHeader header;
 s16 flags;  // signed on the client: handle_6x6A_set_boss_warp_flags reads it with lha into TObjWarpBoss::next_state
 u16 unused;
 void send();
 void bswap();
 void init();
};
LAYOUT_ASSERT(G_SetBossWarpFlags_6x6ASize, sizeof(G_SetBossWarpFlags_6x6A) == 0x8);

// 6x95: The challenge mode stage time. Sent by send_challenge_time; received by
// handle_6x95_set_challenge_time. Size checked: build_6x95_packet sets the header size to 5 words.
// The header is byte-swapped as a G_ClientIDHeader.
struct G_SetChallengeTime_6x95 {
 struct G_ClientIDHeader header;
 s32 client_id;
 s32 time;
 // Sent and byte-swapped (G_SetChallengeTime_6x95::bswap) but never set; newserv's 6x95 ends at time.
 u32 unused[2];
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_SetChallengeTime_6x95Size, sizeof(G_SetChallengeTime_6x95) == 0x14);

// 6x9D: A player has died in challenge mode. Sent by send_challenge_dead_flag_packet and
// send_challenge_dead_flag_cmd; received by handle_6x9D_set_challenge_dead_flag. Size checked:
// build_6x9D_packet sets the header size to 2 words.
struct G_SetChallengeDeadFlag_6x9D {
 struct G_ClientIDHeader header;
 u32 client_id;
 void bswap();
};
LAYOUT_ASSERT(G_SetChallengeDeadFlag_6x9DSize, sizeof(G_SetChallengeDeadFlag_6x9D) == 0x8);

// 6x7C: The start of 6x7C. Layout from newserv, not used by our code yet.
struct G_SetChallengeRecordsBase_6x7C {
 struct G_ClientIDHeader header;
 u16 client_id;
 u8 unused[2];
};

// 6x7C: A player's challenge mode records. Sent by TChallenge::send_6x7c_reset and
// TLobby::send_challenge_records; received by handle_6x7C_set_challenge_records. Size checked: its
// constructor sets the header size to 66 words.
struct G_SetChallengeRecords_V3_6x7C {
 struct G_SetChallengeRecordsBase_6x7C __base_G_SetChallengeRecordsBase_6x7C;
 ChallengeRecord records;
 G_SetChallengeRecords_V3_6x7C();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_SetChallengeRecords_V3_6x7CSize, sizeof(G_SetChallengeRecords_V3_6x7C) == 0x108);

// 6x9C: An enemy's low game flags in Ultimate. Sent by init_6x9C_enemy_low_game_flags_packet;
// received by handle_6x9C_set_enemy_low_game_flags_ultimate. Size checked:
// init_6x9C_enemy_low_game_flags_packet sets the header size to 2 words.
struct G_SetEnemyLowGameFlagsUltimate_6x9C {
 struct G_EntityIDHeader header;
 s32 status_effect_flags;
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_SetEnemyLowGameFlagsUltimate_6x9CSize, sizeof(G_SetEnemyLowGameFlagsUltimate_6x9C) == 0x8);

// 6x17: our code carries this as TBoss3VoloptPositionPacket (pso/boss/volopt/TBoss3Volopt.h),
// which handle_6x17_set_entity_position_and_angle reads.

// 6x76: An entity's set flags. Sent by send_6x76_set_entity_set_flags; received by
// handle_6x76_set_entity_set_flags. Used by our code. Size checked: build_6x76_set_entity_set_flags
// sets the header size to 2 words.
struct G_SetEntitySetFlags_6x76 {
 struct G_EntityIDHeader header;
 s16 floor;
 s16 flags;
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_SetEntitySetFlags_6x76Size, sizeof(G_SetEntitySetFlags_6x76) == 0x8);

// 6x89: The id of the entity that killed a player. Sent by TObjPlayer::prepare_death; received by
// handle_6x89_set_killer_entity_id. Size checked: G_SetKillerEntityID_6x89::init sets the header
// size to 2 words.
struct G_SetKillerEntityID_6x89 {
 struct G_ClientIDHeader header;
 u16 killer_entity_id;
 s16 unused;
 void init();
 void bswap();
 void send();
 G_SetKillerEntityID_6x89 &operator=(G_SetKillerEntityID_6x89 &src);
};
LAYOUT_ASSERT(G_SetKillerEntityID_6x89Size, sizeof(G_SetKillerEntityID_6x89) == 0x8);

// 6x2E: Sets or clears a player's flags. Received by handle_6x2E_set_or_clear_player_flags. Size
// checked: G_SetOrClearPlayerFlags_6x2E::init sets the header size to 3 words.
struct G_SetOrClearPlayerFlags_6x2E {
 struct G_ClientIDHeader header;
 u32 and_mask;
 u32 or_mask;
 void bswap();
 G_SetOrClearPlayerFlags_6x2E &operator=(G_SetOrClearPlayerFlags_6x2E &src);
 void init();
};
LAYOUT_ASSERT(G_SetOrClearPlayerFlags_6x2ESize, sizeof(G_SetOrClearPlayerFlags_6x2E) == 0xC);

// 6x39: Sets a player's photon blast ready flag. Sent by
// PhotonBlastGauge::send_6x39_photon_blast_ready; received by
// handle_6x39_set_photon_blast_ready_flag. Size checked: G_SetPhotonBlastReadyFlag_6x39::init sets
// the header size to 1 word.
struct G_SetPhotonBlastReadyFlag_6x39 {
 struct G_ClientIDHeader header;
 G_SetPhotonBlastReadyFlag_6x39 &operator=(const G_SetPhotonBlastReadyFlag_6x39 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_SetPhotonBlastReadyFlag_6x39Size, sizeof(G_SetPhotonBlastReadyFlag_6x39) == 0x4);

// 6x51: A player's facing angle. Sent by TObjPlayer::send_6x51_set_player_angle. Our dispatch
// table has no handler for it. Size checked: G_SetPlayerAngle_6x51::init sets the header size to 2
// words.
struct G_SetPlayerAngle_6x51 {
 struct G_ClientIDHeader header;
 u32 angle_y;
 void init();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_SetPlayerAngle_6x51Size, sizeof(G_SetPlayerAngle_6x51) == 0x8);

// 6x90: A player's battle team. Received by handle_6x90_set_player_battle_team. Size checked:
// G_SetPlayerBattleTeam_6x90::init sets the header size to 2 words.
struct G_SetPlayerBattleTeam_6x90 {
 struct G_ClientIDHeader header;
 u32 team_number;
 void bswap();
 G_SetPlayerBattleTeam_6x90 &operator=(G_SetPlayerBattleTeam_6x90 &src);
 void init();
};
LAYOUT_ASSERT(G_SetPlayerBattleTeam_6x90Size, sizeof(G_SetPlayerBattleTeam_6x90) == 0x8);

// 6x1F: The floor a player is on. Sent by TObjPlayer::apply_state_transform; received by
// handle_6x1F_set_player_floor. Size checked: G_SetPlayerFloor_6x1F::init sets the header size to
// 2 words.
struct G_SetPlayerFloor_6x1F {
 struct G_ClientIDHeader header;
 s32 floor;
 G_SetPlayerFloor_6x1F &operator=(const G_SetPlayerFloor_6x1F &src);
 void bswap();
 void init();
 void send();
};
LAYOUT_ASSERT(G_SetPlayerFloor_6x1FSize, sizeof(G_SetPlayerFloor_6x1F) == 0x8);

// 6x56: A player's position and angle. Sent by TObjPlayer::send_position_update; received by
// handle_6x56_set_player_position_and_angle. Size checked: G_SetPlayerPositionAndAngle_6x56::init
// sets the header size to 5 words.
struct G_SetPlayerPositionAndAngle_6x56 {
 struct G_ClientIDHeader header;
 u32 angle_y;
 Vec pos;
 void init();
 void bswap();
 void send();
 G_SetPlayerPositionAndAngle_6x56 &operator=(G_SetPlayerPositionAndAngle_6x56 &src);
};
LAYOUT_ASSERT(G_SetPlayerPositionAndAngle_6x56Size, sizeof(G_SetPlayerPositionAndAngle_6x56) == 0x14);

// 6x22: Makes a player invisible. Sent by TObjPlayer::send_local_player_invisible; received by
// handle_6x22_set_player_invisible. Size checked: G_SetPlayerInvisible_6x22::init sets the header
// size to 1 word.
struct G_SetPlayerInvisible_6x22 {
 struct G_ClientIDHeader header;
 void init();
 void send();
 G_SetPlayerInvisible_6x22 &operator=(const G_SetPlayerInvisible_6x22 &src);
};
LAYOUT_ASSERT(G_SetPlayerInvisible_6x22Size, sizeof(G_SetPlayerInvisible_6x22) == 0x4);

// 6x23: Makes a player visible. Sent by TObjPlayer::send_local_player_visible; received by
// handle_6x23_set_player_visible. Size checked: G_SetPlayerVisible_6x23::init sets the header size
// to 1 word.
struct G_SetPlayerVisible_6x23 {
 struct G_ClientIDHeader header;
 void init();
 void send();
 G_SetPlayerVisible_6x23 &operator=(const G_SetPlayerVisible_6x23 &src) {
  copy_subcommand_header(this, &src);
  return *this;
 }
};
LAYOUT_ASSERT(G_SetPlayerVisible_6x23Size, sizeof(G_SetPlayerVisible_6x23) == 0x4);

// 6x20: A player's position and floor. Received by handle_6x20_set_position. Size checked:
// G_SetPosition_6x20::init sets the header size to 6 words.
struct G_SetPosition_6x20 {
 struct G_ClientIDHeader header;
 s32 floor;
 Vec pos;
 u32 angle_y;
 void bswap();
 G_SetPosition_6x20 &operator=(G_SetPosition_6x20 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_SetPosition_6x20Size, sizeof(G_SetPosition_6x20) == 0x18);

// 6x3F: A player's position, floor and angle. Sent by TObjPlayer::send_6x3F_set_position and
// TObjPlayer::send_selected_spawn_position; received by handle_6x3F_set_position. Size checked:
// G_SetPosition_6x3F::init sets the header size to 6 words.
struct G_SetPosition_6x3F {
 struct G_ClientIDHeader header;
 s16 is_near_enemy;
 s16 angle;
 s16 floor;
 s16 room;
 Vec pos;
 void send();
 void bswap();
 void init();
 G_SetPosition_6x3F &operator=(G_SetPosition_6x3F &src);
};
LAYOUT_ASSERT(G_SetPosition_6x3FSize, sizeof(G_SetPosition_6x3F) == 0x18);

// 6x6F: All quest flags, sent to a joining player. Built by init_6x6F_quest_flags_packet and sent by
// send_6x6F_quest_flags; received by handle_6x6F_set_quest_flags_v2. Size
// checked: init_6x6F_quest_flags_packet sets the header size to sizeof / 4.
struct G_SetQuestFlags_V2_V3_6x6F {
 struct G_UnusedHeader header;
 u8 quest_flags[0x200];
};
LAYOUT_ASSERT(G_SetQuestFlags_V2_V3_6x6FSize, sizeof(G_SetQuestFlags_V2_V3_6x6F) == 0x204);

// 6x93: A switch flag set by a timer or a chat sensor. Sent by TOChatSensor::handle_chat_message
// and TOSwitchTimer::send_switch_states; received by handle_6x93_set_switch_flag_from_timer. Size
// checked: G_SetSwitchFlagFromTimer_6x93::init sets the header size to 3 words.
struct G_SetSwitchFlagFromTimer_6x93 {
 struct G_UnusedHeader header;
 s16 switch_flag_floor;
 u16 switch_flag_num;
 u8 should_set;
 u8 unused[3];
 void init();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_SetSwitchFlagFromTimer_6x93Size, sizeof(G_SetSwitchFlagFromTimer_6x93) == 0xC);

// 6x8D: Overrides the level of the technique a player casts next. Sent by
// TObjPlayer::request_technique_cast; received by handle_6x8D_set_technique_level_override. Size
// checked: G_SetTechniqueLevelOverride_6x8D::init sets the header size to 2 words.
struct G_SetTechniqueLevelOverride_6x8D {
 struct G_ClientIDHeader header;
 u8 level_upgrade;
 u8 unused1;
 s16 unused2;
 void bswap();
 G_SetTechniqueLevelOverride_6x8D &operator=(G_SetTechniqueLevelOverride_6x8D &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_SetTechniqueLevelOverride_6x8DSize, sizeof(G_SetTechniqueLevelOverride_6x8D) == 0x8);

// 6x68: A player's telepipe. Received by handle_6x68_set_telepipe_state. Size checked: its
// constructor sets the header size to 7 words.
struct G_SetTelepipeState_6x68 {
 struct G_ClientIDHeader header;
 struct TelepipeState state;
 G_SetTelepipeState_6x68();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_SetTelepipeState_6x68Size, sizeof(G_SetTelepipeState_6x68) == 0x1C);

// 6x4A: A player's shield blocks an attack. Sent by TObjPlayer::send_object_id_packet; received by
// handle_6x4A_shield_attack. Size checked: G_ShieldAttack_6x4A::init sets the header size to 1
// word.
struct G_ShieldAttack_6x4A {
 struct G_ClientIDHeader header;
 void init();
 void send();
 G_ShieldAttack_6x4A &operator=(const G_ShieldAttack_6x4A &src);
};
LAYOUT_ASSERT(G_ShieldAttack_6x4ASize, sizeof(G_ShieldAttack_6x4A) == 0x4);

// 6x8A: Shows the challenge mode time records window. Sent by TLobby::send_challenge_with_value;
// received by handle_6x8A_show_challenge_time_records_window. Size checked: build_6x8A_packet sets
// the header size to 2 words.
struct G_ShowChallengeTimeRecordsWindow_6x8A {
 struct G_ClientIDHeader header;
 s32 which;
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_ShowChallengeTimeRecordsWindow_6x8ASize, sizeof(G_ShowChallengeTimeRecordsWindow_6x8A) == 0x8);

// 6x87: our code carries this as PlayerShrinkPacket (pso/player/PlayerScaleState.h), which
// handle_6x87_shrink_player reads.

// 6x60: The 0x14-byte form of 6x60; handle_6x60_standard_drop_item_request checks the header size
// for it, and the full form adds effective_area. Sent by send_6x60_standard_drop_item_request and
// TObjChara::request_box_item_drop; received by handle_6x60_standard_drop_item_request. Size
// checked: G_StandardDropItemRequest_DC_6x60::init sets the header size to 5 words.
struct G_StandardDropItemRequest_DC_6x60 {
 struct G_UnusedHeader header;
 s8 floor;
 u8 rt_index;
 s16 entity_index;
 struct VectorXZF pos;
 s16 room;
 s16 ignore_def;
 void init();
 void bswap();
};
LAYOUT_ASSERT(G_StandardDropItemRequest_DC_6x60Size, sizeof(G_StandardDropItemRequest_DC_6x60) == 0x14);

// 6x60: Asks the game leader to drop an item from an enemy or a box. Sent by
// send_6x60_standard_drop_item_request and TObjChara::request_box_item_drop; received by
// handle_6x60_standard_drop_item_request. Size checked:
// G_StandardDropItemRequest_PC_V3_BB_6x60::init sets the header size to 6 words.
struct G_StandardDropItemRequest_PC_V3_BB_6x60 {
 struct G_StandardDropItemRequest_DC_6x60 __base_G_StandardDropItemRequest_DC_6x60;
 s8 effective_area;
 u8 unused[3];
 G_StandardDropItemRequest_PC_V3_BB_6x60 *init();
 void send();
};
LAYOUT_ASSERT(G_StandardDropItemRequest_PC_V3_BB_6x60Size, sizeof(G_StandardDropItemRequest_PC_V3_BB_6x60) == 0x18);

// 6xA2: Asks the game leader to drop an item from a box with fixed item parameters. Sent by
// TObjChara::request_box_item_drop; received by handle_6xA2_specializable_item_drop_request. Size
// checked: G_SpecializableItemDropRequest_6xA2::init sets the header size to 10 words.
struct G_SpecializableItemDropRequest_6xA2 {
 struct G_StandardDropItemRequest_PC_V3_BB_6x60 __base_G_StandardDropItemRequest_PC_V3_BB_6x60;
 // The box's object set entry: scale.z and set_params (params 3-6 of the .dat entry).
 f32 scale_z;
 s32 set_params[3];
 G_SpecializableItemDropRequest_6xA2 *init();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_SpecializableItemDropRequest_6xA2Size, sizeof(G_SpecializableItemDropRequest_6xA2) == 0x28);

// 6x3E: A player stops at a position. Sent by send_6x3e_to_all_players, send_stop_at_position,
// quest_player_look_at_partner, quest_player_face_actor and 2 more; received by
// handle_6x3E_stop_at_position. Size checked: G_StopAtPosition_6x3E::init sets the header size to 6
// words.
struct G_StopAtPosition_6x3E {
 struct G_ClientIDHeader header;
 s16 is_near_enemy;
 s16 angle;
 s16 floor;
 s16 room;
 Vec pos;
 void init();
 void bswap();
 void send();
 G_StopAtPosition_6x3E &operator=(G_StopAtPosition_6x3E &src);
};
LAYOUT_ASSERT(G_StopAtPosition_6x3ESize, sizeof(G_StopAtPosition_6x3E) == 0x18);

// 6x50: A player uses a switch. Sent by TObjPlayer::send_6x50_switch_interaction; received by
// handle_6x50_switch_interaction. Size checked: G_SwitchInteraction_6x50::init sets the header
// size to 2 words.
struct G_SwitchInteraction_6x50 {
 struct G_ClientIDHeader header;
 u32 angle_y;
 void init();
 void bswap();
 void send();
 G_SwitchInteraction_6x50 &operator=(const G_SwitchInteraction_6x50 &src);
};
LAYOUT_ASSERT(G_SwitchInteraction_6x50Size, sizeof(G_SwitchInteraction_6x50) == 0x8);

// 6x07: A symbol chat message. Sent by send_selected_symbol_chat; received by
// handle_6x07_symbol_chat. Used by our code. Size checked: init_symbol_chat_header sets the
// header size to 17 words. The header is byte-swapped as a G_ClientIDHeader.
struct G_SymbolChat_6x07 {
 struct G_ClientIDHeader header;
 u32 client_id;
 SymbolChatPayload data;
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_SymbolChat_6x07Size, sizeof(G_SymbolChat_6x07) == 0x44);

// 6x6B/6x6C/6x6D/6x6E: The game state sent to a joining player, LZ-compressed: enemies (6B), objects (6C),
// floor items (6D) and floor and switch flags (6E). The subcommand header's size is 0 and total_size holds
// the whole packet's size in bytes; the compressed data follows it. Sent by TLobby::send_cmd_6B,
// TLobby::send_compressed_packet_6c, TLobby::send_6x6D_item_state and TLobby::send_6x6E_sync_game_state;
// received by handle_6x6B_sync_game_state through handle_6x6E_sync_game_state. Used by our code; the data
// starts at offset 8 (the handlers decode total_size - 8 bytes from there).
struct CompressedSyncPacket {
 G_UnusedHeader header;
 s32 total_size;
 u8 data[1];
};
LAYOUT_ASSERT(CompressedSyncPacketDataOffset, offsetof(CompressedSyncPacket, data) == 8);

// 6x6D: The item state sent to a joining player, after decompression. Received by
// handle_6x6D_sync_game_state. Used by our code; size not checked against a sender yet.
struct G_SyncItemState_6x6D_Decompressed {
 u16 next_drop_number_per_floor[16];
 u32 next_item_id_per_player[12];
 u32 floor_item_count_per_floor[15];
};

// 6x70: carried as PlayerSyncPacket (pso/player/PlayerSyncRecord.h).

// 6x77: A quest register value. Sent by qst_op_sync_register; received by
// handle_6x77_sync_quest_register. Size checked: G_SyncQuestRegister_6x77::init sets the header
// size to 3 words.
struct G_SyncQuestRegister_6x77 {
 struct G_ClientIDHeader header;
 u16 register_number;
 u16 unused;
 u32 value;
 void send();
 void bswap();
 void init();
};
LAYOUT_ASSERT(G_SyncQuestRegister_6x77Size, sizeof(G_SyncQuestRegister_6x77) == 0xC);

// 6x6E: The set flag state sent to a joining player, after decompression. Received by
// handle_6x6E_sync_game_state. Layout from newserv, not used by our code yet.
struct G_SyncSetFlagState_6x6E_Decompressed {
 u16 total_size;
 u16 entity_set_flags_size;
 u16 event_set_flags_size;
 u16 switch_flags_size;
};

// 6x3D: A target id. Our dispatch table has no handler for it. Layout from newserv, not used by
// our code yet.
struct G_TargetBase_6x3D {
 struct G_UnusedHeader header;
};

// 6x24: Moves a player to a position. Sent by TObjPlayer::send_respawn_position and
// send_6x24_teleport_player; received by handle_6x24_teleport_player. Size checked:
// G_TeleportPlayer_6x24::init sets the header size to 5 words.
struct G_TeleportPlayer_6x24 {
 struct G_ClientIDHeader header;
 u32 angle_y;
 Vec pos;
 void bswap();
 G_TeleportPlayer_6x24 &operator=(G_TeleportPlayer_6x24 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_TeleportPlayer_6x24Size, sizeof(G_TeleportPlayer_6x24) == 0x14);

// 6x67: our code carries this as G_FloorEvent_6x67 (pso/network/FloorEventCommand.h), which
// handle_6x67_trigger_set_event reads.

// 6x80: A trap goes off. Sent by TOMineTrap::send_state_packet; received by
// handle_6x80_trigger_trap. Size checked: G_TriggerTrap_6x80::init sets the header size to 2
// words.
struct G_TriggerTrap_6x80 {
 struct G_ClientIDHeader header;
 u16 trap_number;
 u16 what;
 void init();
 void bswap();
 void send();
};

LAYOUT_ASSERT(TriggerTrapPacketSize, sizeof(G_TriggerTrap_6x80) == 8);

// 6xAF/6xB0: The fields shared by the lobby chair packets. Received by
// handle_6xAF_turn_or_move_lobby_chair and handle_6xB0_turn_or_move_lobby_chair. Size checked:
// G_TurnLobbyChair_6xAF::init and G_MoveLobbyChair_6xB0::init set the header size to 2 words.
struct G_TurnOrMoveLobbyChair_6xAF_6xB0 {
 struct G_ClientIDHeader header;
 u32 angle;
};
LAYOUT_ASSERT(G_TurnOrMoveLobbyChair_6xAF_6xB0Size, sizeof(G_TurnOrMoveLobbyChair_6xAF_6xB0) == 0x8);

// 6xAF: turn the lobby chair toward the stick angle.
// Sent by TObjPlayer::update_lobby_chair_controls. Size checked: G_TurnLobbyChair_6xAF::init sets
// the header size to 2 words.
struct G_TurnLobbyChair_6xAF : G_TurnOrMoveLobbyChair_6xAF_6xB0 {
 void init();
 void bswap();
 void send();
 G_TurnLobbyChair_6xAF &operator=(const G_TurnOrMoveLobbyChair_6xAF_6xB0 &src);
};
LAYOUT_ASSERT(G_TurnLobbyChair_6xAFSize, sizeof(G_TurnLobbyChair_6xAF) == 0x8);

// 6xB0: move the lobby chair along the stick angle.
// Sent by TObjPlayer::update_lobby_chair_controls. Size checked: G_MoveLobbyChair_6xB0::init sets
// the header size to 2 words.
struct G_MoveLobbyChair_6xB0 : G_TurnOrMoveLobbyChair_6xAF_6xB0 {
 void init();
 void bswap();
 void send();
 G_MoveLobbyChair_6xB0 &operator=(const G_TurnOrMoveLobbyChair_6xAF_6xB0 &src);
};
LAYOUT_ASSERT(G_MoveLobbyChair_6xB0Size, sizeof(G_MoveLobbyChair_6xB0) == 0x8);

// 6x71: Lets other players join the game again. Received by handle_6x71_unblock_game_join. Layout
// from newserv. Size checked: TLobby::send_6x71_to_player sets the header size to 1 word.
struct G_UnblockGameJoin_6x71 {
 struct G_UnusedHeader header;
};
LAYOUT_ASSERT(G_UnblockGameJoin_6x71Size, sizeof(G_UnblockGameJoin_6x71) == 0x4);

// 6x26: A player unequips an item. Sent by TObjPlayer::send_6x26_unequip_item and
// TObjPlayer::send_unequip_held_item; received by handle_6x26_unequip_item. Size checked:
// G_UnequipItem_6x26::init sets the header size to 3 words.
struct G_UnequipItem_6x26 {
 struct G_ClientIDHeader header;
 u32 item_id;
 s32 equip_slot;
 void send();
 void bswap();
 void init();
 G_UnequipItem_6x26 &operator=(G_UnequipItem_6x26 &src);
};
LAYOUT_ASSERT(G_UnequipItem_6x26Size, sizeof(G_UnequipItem_6x26) == 0xC);

// 6x02/6x03: Ignored: handle_6x02 and handle_6x03 are empty. Layout from newserv, not used by our
// code yet.
struct G_Unknown_6x02_6x03 {
 struct G_ClientIDHeader header;
 u16 unknown_a1;
 u16 unknown_a2;
 u32 unknown_a3;
 f32 unknown_a4;
 f32 unknown_a5;
};

// 6x36: Ignored: handle_6x36 is empty. Layout from newserv, not used by our code yet.
struct G_Unknown_6x36 {
 struct G_ParameterHeader header;
};

// 6x53: Runs action phase 0x13 on a player in the tl_03 state. Sent by
// TObjPlayer::send_name_and_state; received by handle_6x53. Size checked: G_Unknown_6x53::init
// sets the header size to 1 word.
struct G_Unknown_6x53 {
 struct G_ClientIDHeader header;
 void init();
 void send();
 G_Unknown_6x53 &operator=(const G_Unknown_6x53 &src);
};
LAYOUT_ASSERT(G_Unknown_6x53Size, sizeof(G_Unknown_6x53) == 0x4);

// 6x54: Ignored: handle_6x54 is empty. Layout from newserv, not used by our code yet.
struct G_Unknown_6x54 {
 struct G_ClientIDHeader header;
};

// 6x57: Runs action phase 0x16 on a player. Sent by TObjPlayer::send_6x57; received by
// handle_6x57. Size checked: G_Unknown_6x57::init sets the header size to 1 word.
struct G_Unknown_6x57 {
 struct G_ClientIDHeader header;
 void init();
 void send();
 G_Unknown_6x57 &operator=(const G_Unknown_6x57 &src);
};
LAYOUT_ASSERT(G_Unknown_6x57Size, sizeof(G_Unknown_6x57) == 0x4);

// 6x78: Toggles the TObjHashi entry of a client. Received by handle_6x78. Used by our code; size
// not checked against a sender yet. The header is byte-swapped as a G_ClientIDHeader.
struct G_Unknown_6x78 {
 struct G_ClientIDHeader header;
 u16 client_id;
 u16 unused1;
 u32 unused2;
 void bswap();
};

// 6x92: Sets one parameter of the online ending hex lines; the client id modulo 4 picks which.
// Sent by TObjOnlineEndingHexMove::run_task and TAdGameStartGC::init_6x92; received by
// handle_6x92. Size checked: TAdGameStartGC::init_6x92 sets the header size to 3 words.
struct G_Unknown_6x92 {
 struct G_UnusedHeader header;
 u32 client_id;
 f32 value;
};
LAYOUT_ASSERT(G_Unknown_6x92Size, sizeof(G_Unknown_6x92) == 0xC);

// 6x91: The state of an attackable wall or object. Sent by TOAttackableCol::send_state_change and
// init_6x91_subcommand; received by handle_6x91_update_attackable_col_state. Size checked:
// init_6x91_subcommand sets the header size to 5 words.
struct G_UpdateAttackableColState_6x91 : G_UpdateObjectState_6x0B {
 u16 is_destroyed;
 u16 remaining_hits;
 u16 switch_flag_num;
 u8 should_set;
 s8 floor;
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_UpdateAttackableColState_6x91Size, sizeof(G_UpdateAttackableColState_6x91) == 0x14);

// 6x9A: a player's HP, TP or meseta changes; the header carries the player's client id.
// Sent by TObjChara::send_update_entity_stat; received by handle_6x9A_update_entity_stat. Size
// checked: G_UpdateEntityStat_6x9A::init sets the header size to 2 words.
struct G_UpdateEntityStat_6x9A {
 struct G_ClientIDHeader header;
 u16 entity_index;
 u8 what;
 u8 amount;
 // Clears the packet and sets its header (subcommand 0x9A, size 2).
 void init();
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_UpdateEntityStat_6x9ASize, sizeof(G_UpdateEntityStat_6x9A) == 0x8);

// 6x75: The first part of 6x75: the flag and what to do with it. Layout from newserv, not used by
// our code yet.
struct G_UpdateQuestFlag_DC_PC_6x75 {
 struct G_UnusedHeader header;
 u16 flag;
 u16 action;
};

// 6x75: Sets or clears a quest flag. Sent by TLobby::send_6x75_quest_flag,
// TLobby::send_6x75_quest_flag_cur_difficulty, send_and_handle_6x75 and
// build_6x75_update_quest_flag_dc; received by handle_6x75_update_quest_flag_dc. Size checked:
// build_6x75_update_quest_flag_dc sets the header size to 3 words.
struct G_UpdateQuestFlag_V3_BB_6x75 {
 struct G_UpdateQuestFlag_DC_PC_6x75 __base_G_UpdateQuestFlag_DC_PC_6x75;
 s16 difficulty16;
 u16 unused;
 void bswap();
};
LAYOUT_ASSERT(G_UpdateQuestFlag_V3_BB_6x75Size, sizeof(G_UpdateQuestFlag_V3_BB_6x75) == 0xC);

// 6x27: A player uses an item. Sent by try_send_6x27_use_item; received by handle_6x27_use_item.
// Size checked: G_UseItem_6x27::init sets the header size to 2 words.
struct G_UseItem_6x27 {
 struct G_ClientIDHeader header;
 u32 item_id;
 void bswap();
 G_UseItem_6x27 &operator=(G_UseItem_6x27 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_UseItem_6x27Size, sizeof(G_UseItem_6x27) == 0x8);

// 6x31: A player uses the medical center. Sent by TObjPlayer::send_use_medical_center; received by
// handle_6x31_use_medical_center. Size checked: G_UseMedicalCenter_6x31::init sets the header size
// to 1 word.
struct G_UseMedicalCenter_6x31 {
 struct G_ClientIDHeader header;
 G_UseMedicalCenter_6x31 &operator=(G_UseMedicalCenter_6x31 &src);
 void init();
 void send();
};
LAYOUT_ASSERT(G_UseMedicalCenter_6x31Size, sizeof(G_UseMedicalCenter_6x31) == 0x4);

// 6x66: A player uses a star atomizer on the players near them. Sent by send_star_atomizer_targets
// and send_nearby_player_ids; received by handle_6x66_use_star_atomizer. Size checked:
// G_UseStarAtomizer_6x66::init_header sets the header size to 3 words.
struct G_UseStarAtomizer_6x66 {
 struct G_UnusedHeader header;
 // The user first; -1 for an empty slot (handle_6x66_use_star_atomizer).
 s16 target_client_ids[4];

 void bswap();
 void send();
 void init_header();
};
LAYOUT_ASSERT(G_UseStarAtomizer_6x66Size, sizeof(G_UseStarAtomizer_6x66) == 0xC);

// 6x18: our code carries this as VoloptPartsMessage (pso/boss/volopt/TBoss3VoloptP02.h), which
// handle_6x18_vol_opt2_boss_actions reads.

// 6x15: our code carries this as TBoss3VoloptActionPacket (pso/boss/volopt/TBoss3Volopt.h), which
// handle_6x15_vol_opt_boss_actions reads.

// 6x16: our code carries this as TBoss3VoloptTargetsPacket (pso/boss/volopt/TBoss3Volopt.h), which
// handle_6x16_vol_opt_boss_actions reads.

// 6x84: our code carries this as TBoss3VoloptAttackPacket (pso/boss/volopt/TBoss3Volopt.h), which
// handle_6x84_vol_opt_boss_actions reads.

// 6x85: our code carries this as VoloptPhase2Message (pso/boss/volopt/TBoss3VoloptP02.h), which
// handle_6x85_vol_opt_phase2_boss_actions reads.

// 6x40: A player walks to a position. Sent by TNpcPlayer::send_walk_request,
// TObjGoGoBall::send_local_player_walk, TObjPlayer::send_6x40_walk_to_position and qst_op_pl_walk;
// received by handle_6x40_walk_to_position. Size checked: G_WalkToPosition_6x40::init sets the
// header size to 4 words.
struct G_WalkToPosition_6x40 {
 struct G_ClientIDHeader header;
 struct VectorXZF pos;
 u32 flags;
 // Clears the packet and sets its header (subcommand 0x40, size 4).
 void init();
 G_WalkToPosition_6x40 &operator=(G_WalkToPosition_6x40 &src);
 void bswap();
 void send();
};
LAYOUT_ASSERT(G_WalkToPosition_6x40Size, sizeof(G_WalkToPosition_6x40) == 0x10);

// 6x05: our code carries this as G_SwitchStateChanged_6x05
// (pso/network/protocol/protocol_types.h).

// Subcommands the dispatch table sends to empty handlers. Neither our code nor other PSO versions
// give them a layout.
// 6x34: handled by handle_6x34 (ignored); no known layout.
// 6x62: handled by handle_6x62 (ignored); no known layout.
// 6x64: handled by handle_6x64 (ignored); no known layout.
// 6x65: handled by handle_6x65 (ignored); no known layout.
// 6x7E: handled by handle_6x7E (ignored); no known layout.
// 6x8B: handled by handle_6x8B (ignored); no known layout.
// 6x8C: handled by handle_6x8C (ignored); no known layout.
// 6x8E: handled by handle_6x8E (ignored); no known layout.
// 6x96: handled by handle_6x96 (ignored); no known layout.
// 6x98: handled by handle_6x98 (ignored); no known layout.
// 6x99: handled by handle_6x99 (ignored); no known layout.
// 6xA7: handled by handle_6xA7 (ignored); no known layout.
// 6xB1: handled by handle_6xB1 (ignored); no known layout.

#endif
