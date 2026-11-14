#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/item/TItem.h"
#include "pso/player/TPlyCharData.h"
#include "pso/player/TUnk_804C4540.h"
#include "pso/system/vector.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerClassStats.h"
#include "pso/map/FloorArea.h"

#include <stddef.h>
#include "pso/map/FloorArea.h"
#include "pso/item/TItemData.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

#include "pso/boss/darkfalz/TBoss4DarkFalz.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct RecoveredGlobal_801D8ADC_lbl_8044929C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8ADC_lbl_804492AC {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8ADC_lbl_804492BC {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8ADC_lbl_804492CC {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_801D8B8C_lbl_8044925C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8B8C_lbl_8044926C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8B8C_lbl_8044927C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8B8C_lbl_8044928C {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_801D8C6C_lbl_8044923C {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_801D8D8C_lbl_804C49B0 {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_801D8E60_lbl_804C4980 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_801A51C0_lbl_80446980 {
    s32 value;
    u8 remaining[0x14];
};

struct RecoveredGlobal_801D92F4_lbl_804475B0 {
    s32 value;
    u8 remaining[0x23C];
};

struct RecoveredGlobal_801D9004_lbl_80447970 {
    s32 value;
    u8 remaining[0x38];
};

struct RecoveredGlobal_801D8DCC_lbl_804C4998
{
  s32 value;
  u8 remaining[0x14];
};

struct RecoveredGlobal_801D8E1C_lbl_804C498C
{
  s32 value;
  u8 remaining[0x8];
};

struct RecoveredGlobal_801D8FB4_lbl_804C495C
{
  s32 value;
  u8 remaining[0x14];
};

typedef struct Rec_801D8F0C { f32 a, b, c; } Rec_801D8F0C;

typedef struct Rec_801D8F60 { f32 a, b, c; } Rec_801D8F60;

extern "C" {
s8 TObjPlayer__sub_801AFDBC(s8);
u16 get_entity_id(void *);
s32 get_main_phase();
extern s32 game_difficulty_selection;
s32 get_class_starting_inventory(s8 arg0);
u8 *get_class_defense_template(TObjPlayer *arg0);
s32 TObjPlayer__sub_801D8C3C(void);
player_stats *get_class_stat_caps(s8 arg0);
u8 *get_class_attack_template(TObjPlayer *arg0);
stats *get_class_base_stats(s8 arg0);
s32 TObjPlayer__sub_801D8DCC(TObjPlayer *arg0);
s32 get_max_level__10TObjPlayerFv(s32);
s32 TObjPlayer__sub_801D91B8(s32 arg0);
const Vec_801D8CCC *get_guild_return_position__10TObjPlayerFPv(void *player);
s32 classify_action_state__10TObjPlayerFv(void *);
s32 TBoss4DarkFalz__sub_801D94C0(void* p);
void TObjPlayer__sub_801D92A4(void);
s32 get_contact_surface_type(s32 arg0);
int load_encrypted_archive_data(const char *);
}
int ply_level_table;
s32 get_ply_level_table_row(s8 arg0, s32 arg1);
f32 lookup_attack_marker(s32, s16, s16, s32);
extern Rec_801D8F0C *photon_blast_motion_timing_tables[6];
extern const s32 (*player_footstep_floor_table[3])[5];
extern const Rec_8044821C *player_clamped_index_table_pointers[3];
extern const Rec_8044845C *player_anim_table_pointers[3];
extern const Rec_804484EC *player_cast_motion_record_table[6];
extern const TPlyInventoryItem *class_starting_inventory_table[12];
// Defined after their users, which keeps these 8-byte tables out of .sdata.
extern const Vec_801D8CCC *hospital_position_table_by_episode[];
extern const Vec_801D8CCC *guild_return_position_table_by_episode[];


typedef char RecoveredGlobal_801D8ADC_lbl_8044929C_size[sizeof(RecoveredGlobal_801D8ADC_lbl_8044929C) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801D8ADC_lbl_804492AC_size[sizeof(RecoveredGlobal_801D8ADC_lbl_804492AC) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801D8ADC_lbl_804492BC_size[sizeof(RecoveredGlobal_801D8ADC_lbl_804492BC) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801D8ADC_lbl_804492CC_size[sizeof(RecoveredGlobal_801D8ADC_lbl_804492CC) == 0x14 ? 1 : -1];
s32 *TObjPlayer::get_getup_protection_ticks() {
    s32 *arg0 = (s32 *)this;
    s32 *var_r31;
    s32 *var_r3;
    var_r31 = arg0;
    if (get_main_phase() == 0xF) {
        var_r3 = var_r31;
        if (((TObjChara *)var_r3)->obj_isState3_324() != 0) {
            var_r3 = (s32 *)player_getup_protection_ticks_table_flagged;
            var_r3 = (s32 *)player_getup_protection_ticks_table_flagged;
            var_r3 = (s32 *)(*(s32 *)((s8 *)player_getup_protection_ticks_table_flagged + (game_difficulty_selection * 4)));
            return var_r3;
        }
        var_r3 = (s32 *)player_getup_protection_ticks_table;
        var_r3 = (s32 *)player_getup_protection_ticks_table;
        var_r3 = (s32 *)(*(s32 *)((s8 *)player_getup_protection_ticks_table + (game_difficulty_selection * 4)));
        return var_r3;
    }
    var_r3 = var_r31;
    if (((TObjChara *)var_r3)->obj_isState3_324() != 0) {
        var_r3 = (s32 *)getup_protection_ticks_table_b;
        var_r3 = (s32 *)getup_protection_ticks_table_b;
        var_r3 = (s32 *)(*(s32 *)((s8 *)getup_protection_ticks_table_b + (game_difficulty_selection * 4)));
        return var_r3;
    }
    var_r3 = (s32 *)getup_protection_ticks_table_a;
    var_r3 = (s32 *)getup_protection_ticks_table_a;
    var_r3 = (s32 *)(*(s32 *)((s8 *)getup_protection_ticks_table_a + (game_difficulty_selection * 4)));
    return var_r3;
}

typedef char RecoveredGlobal_801D8B8C_lbl_8044925C_size[sizeof(RecoveredGlobal_801D8B8C_lbl_8044925C) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801D8B8C_lbl_8044926C_size[sizeof(RecoveredGlobal_801D8B8C_lbl_8044926C) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801D8B8C_lbl_8044927C_size[sizeof(RecoveredGlobal_801D8B8C_lbl_8044927C) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_801D8B8C_lbl_8044928C_size[sizeof(RecoveredGlobal_801D8B8C_lbl_8044928C) == 0x10 ? 1 : -1];
s32 *TObjPlayer::get_hurt_protection_ticks() {
    s32 *arg0 = (s32 *)this;
    s32 *var_r31;
    s32 *var_r3;
    var_r31 = arg0;
    if (get_main_phase() == 0xF) {
        var_r3 = var_r31;
        if (((TObjChara *)var_r3)->obj_isState3_324() != 0) {
            var_r3 = (s32 *)hurt_protection_ticks_table;
            var_r3 = (s32 *)hurt_protection_ticks_table;
            var_r3 = (s32 *)(*(s32 *)((s8 *)hurt_protection_ticks_table + (game_difficulty_selection * 4)));
            return var_r3;
        }
        var_r3 = (s32 *)player_hurt_protection_ticks_table_phase15;
        var_r3 = (s32 *)player_hurt_protection_ticks_table_phase15;
        var_r3 = (s32 *)(*(s32 *)((s8 *)player_hurt_protection_ticks_table_phase15 + (game_difficulty_selection * 4)));
        return var_r3;
    }
    var_r3 = var_r31;
    if (((TObjChara *)var_r3)->obj_isState3_324() != 0) {
        var_r3 = (s32 *)player_hurt_protection_ticks_table_flagged;
        var_r3 = (s32 *)player_hurt_protection_ticks_table_flagged;
        var_r3 = (s32 *)(*(s32 *)((s8 *)player_hurt_protection_ticks_table_flagged + (game_difficulty_selection * 4)));
        return var_r3;
    }
    var_r3 = (s32 *)player_hurt_protection_ticks_table;
    var_r3 = (s32 *)player_hurt_protection_ticks_table;
    var_r3 = (s32 *)(*(s32 *)((s8 *)player_hurt_protection_ticks_table + (game_difficulty_selection * 4)));
    return var_r3;
}

typedef char RecoveredGlobal_801D8C6C_lbl_8044923C_size[sizeof(RecoveredGlobal_801D8C6C_lbl_8044923C) == 0x18 ? 1 : -1];

typedef char RecoveredGlobal_801A51C0_lbl_80446980_size[sizeof(RecoveredGlobal_801A51C0_lbl_80446980) == 0x18 ? 1 : -1];
s32 TObjPlayer__sub_801D8C3C(void) {
    return *(s32 *)((s8 *)lbl_80449254 + (TLobby::get_instance() * 4));
}

u8 *TObjPlayer::get_lobby_entry_ptr() {
    return (u8 *)lobby_entry_table + (TLobby::get_instance() * 0xC);
}

typedef char RecoveredGlobal_801D8D8C_lbl_804C49B0_size[sizeof(RecoveredGlobal_801D8D8C_lbl_804C49B0) == 0x30 ? 1 : -1];

s32 TObjPlayer::get_guild_return_yaw() {
    return *(s32 *)((s8 *)lbl_80449234 + (TLobby::get_instance() * 4));
}

const Vec_801D8CCC *get_guild_return_position__10TObjPlayerFPv(void *player) {
    return guild_return_position_table_by_episode[TLobby::get_instance()] + get_entity_id(player);
}

s32 TObjPlayer::get_hospital_yaw() {
    return *(s32 *)((s8 *)lbl_804491CC + (TLobby::get_instance() * 4));
}

u8 *TObjPlayer::get_hospital_position() {
    return (u8 *)hospital_position_table_by_episode[TLobby::get_instance()] + (get_entity_id(this) * 0xC);
}

s32 get_class_starting_inventory(s8 arg0) {
    TObjPlayer__sub_801AFDBC(arg0);
    return *(s32 *)((s8 *)class_starting_inventory_table + (arg0 * 4));
}

typedef char RecoveredGlobal_801D8E60_lbl_804C4980_size[sizeof(RecoveredGlobal_801D8E60_lbl_804C4980) == 0xC ? 1 : -1];

typedef struct RecoveredGlobal_801D8DCC_lbl_804C4998 RecoveredGlobal_801D8DCC_lbl_804C4998;
typedef char RecoveredGlobal_801D8DCC_lbl_804C4998_size[((sizeof(RecoveredGlobal_801D8DCC_lbl_804C4998)) == 0x18) ? (1) : (-1)];
s32 TObjPlayer__sub_801D8DCC(TObjPlayer *player) {
  s32 temp_r31;
  s8 *new_var;
  temp_r31 = player->get_handle_value() * 0x14;
  new_var = ((s8 *)player_cast_motion_record_table) + (player->has_valid_handle() * 4);
  return (*((s32 *) new_var)) + temp_r31;
}

typedef struct RecoveredGlobal_801D8E1C_lbl_804C498C RecoveredGlobal_801D8E1C_lbl_804C498C;
typedef char RecoveredGlobal_801D8E1C_lbl_804C498C_size[((sizeof(RecoveredGlobal_801D8E1C_lbl_804C498C)) == 0xC) ? (1) : (-1)];
long TObjPlayer::get_anim_table_entry(s32 arg1) {
    u8 *arg0 = (u8 *)this;
  int new_var;
  new_var = ((TObjPlayer *)arg0)->get_clamped_index() * 4;
  return (*((s32 *) (((s8 *)player_anim_table_pointers) + new_var))) + (arg1 * 4);
}

s32 TObjPlayer::get_table_entry_by_clamped_index() {
    u8 *arg0 = (u8 *)this;
    return *(s32 *)((s8 *)player_clamped_index_table_pointers + (((TObjPlayer *)arg0)->get_clamped_index() * 4));
}

typedef char RecoveredGlobal_801D9004_lbl_80447970_size[sizeof(RecoveredGlobal_801D9004_lbl_80447970) == 0x3C ? 1 : -1];

typedef struct RecoveredGlobal_801D8FB4_lbl_804C495C RecoveredGlobal_801D8FB4_lbl_804C495C;
typedef char RecoveredGlobal_801D8FB4_lbl_804C495C_size[((sizeof(RecoveredGlobal_801D8FB4_lbl_804C495C)) == 0x18) ? (1) : (-1)];

s32 TObjPlayer::get_footstep_floor_index() {
    s32 floor;
    const s32 (*table)[5];
    floor = get_current_floor_area();
    table = player_footstep_floor_table[classify_action_state__10TObjPlayerFv(this)];
    if (floor == 0xE && TBoss4DarkFalz::get_instance_count() == 0) {
        floor = 1;
    }
    {
        s32 surf = get_floor_surface_type();
        return table[floor][surf];
    }
}

f32 TObjPlayer::get_photon_blast_complete_threshold() {
  return ((Rec_801D8F0C * *)&photon_blast_motion_timing_tables)[has_valid_handle()][get_handle_value()].c;
}

f32 TObjPlayer::get_photon_blast_upper_bound() {
  return ((Rec_801D8F60 * *)&photon_blast_motion_timing_tables)[has_valid_handle()][get_handle_value()].b;
}

f32 TObjPlayer::get_photon_blast_hold_frame() {
    s32 arg0 = (s32)this;
  s32 temp_r31;
  s32 *new_var;
  temp_r31 = ((TObjPlayer *)arg0)->get_handle_value() * 0xC;
  new_var = (s32 *) (((s8 *) (((u8 *)photon_blast_motion_timing_tables) + (((s32)((TObjPlayer *)arg0)->has_valid_handle()) * 4))) + 0);
  return *((f32 *) (((s8 *) ((*new_var) + temp_r31)) + 0));
}

f32 TObjPlayer::get_attack_recovery_count() {
    s32 arg0 = (s32)this;
    s32 falz_phase;
    falz_phase = get_falz_phase();
    return (f32) (s8) *(u8 *)((s8 *)((u8 *)(((u8 *)attack_recovery_count_table + (((TObjPlayer *)arg0)->get_handle_value() * 3))) + falz_phase) + 0);
}

#pragma push
#pragma scheduling off
f32 TObjPlayer::select_normal_attack_marker() {
  s16 temp_r30;
  s16 falz_phase;
  s16 new_var;
  s32 class_flags;
  class_flags = get_class_flags();
  new_var = ((TObjPlayer *)(((u8 *)this) + 0x7CC))->get_stage_strike_count();
  temp_r30 = new_var;
  falz_phase = this->get_falz_phase();
  return lookup_attack_marker((s32) get_handle_value(), falz_phase, temp_r30, class_flags);
}

#pragma pop

f32 lookup_attack_marker(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    switch (arg0) {
    case 3:
        return *(f32 *)((s8 *)((u8 *)(((u8 *)attack_marker_table_dagger + (arg2 * 0xC))) + (arg1 * 4)) + 0);
    case 14:
        return *(f32 *)((s8 *)((u8 *)(((u8 *)attack_marker_table_double_saber + (arg2 * 0xC))) + (arg1 * 4)) + 0);
    case 15:
        if (arg3 & CLASS_FLAG_MALE) {
            return *(f32 *)((s8 *)((u8 *)(((u8 *)twin_sword_male_marker_table + (arg2 * 0xC))) + (arg1 * 4)) + 0);
        }
        return *(f32 *)((s8 *)((u8 *)(((u8 *)twin_sword_female_marker_table + (arg2 * 0xC))) + (arg1 * 4)) + 0);
    default:
        return *(f32 *)((s8 *)((u8 *)(((u8 *)attack_marker_table + (arg0 * 0xC))) + (arg1 * 4)) + 0);
    }
}

// .data
Rec_801D8F0C lbl_804C46B0[19] = {
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
Rec_801D8F0C lbl_804C4794[19] = {
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
Rec_801D8F0C lbl_804C4878[19] = {
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
Rec_801D8F0C *photon_blast_motion_timing_tables[6] = {
    lbl_804C46B0, lbl_804C4794, lbl_804C4878,
    lbl_804C46B0, lbl_804C4794, lbl_804C4794,
};
const s32 (*player_footstep_floor_table[3])[5] = {
    lbl_804479AC, lbl_80447C7C, lbl_80447F4C,
};
const Rec_8044821C *player_clamped_index_table_pointers[3] = {
    lbl_8044821C, lbl_804482DC, lbl_8044839C,
};
const Rec_8044845C *player_anim_table_pointers[3] = {
    lbl_8044845C, lbl_8044848C, lbl_804484BC,
};
const Rec_804484EC *player_cast_motion_record_table[6] = {
    lbl_804484EC, lbl_80448668, lbl_804487E4,
    lbl_80448960, lbl_80448668, lbl_80448668,
};
const TPlyInventoryItem *class_starting_inventory_table[12] = {
    lbl_80448ADC, lbl_80448B68, lbl_80448BF4, lbl_80448C80,
    lbl_80448D0C, lbl_80448D98, lbl_80448E24, lbl_80448EB0,
    lbl_80448F3C, lbl_80448FC8, lbl_80449054, lbl_804490E0,
};

s32 TObjPlayer__sub_801D91B8(s32 arg0) {
    return TObjPlayer::get_current_state_field(((TObjPlayer *)arg0)->get_class_index(), get_max_level__10TObjPlayerFv(arg0));
}

s32 TObjPlayer::get_current_state_field(s8 _w0, s32 _w1) {
    return *(s32 *)((s8 *)(get_ply_level_table_row(_w0, _w1)) + 8);
}

s32 TObjPlayer::get_class_state_field(s32 arg1) {
    s32 arg0 = (s32)this; return TObjPlayer::get_current_state_field(((TObjPlayer *)arg0)->get_class_index(), arg1); }

s32 get_ply_level_table_row(s8 arg0, s32 arg1) {
  s32 temp_r30;
  s32 temp_r31;
  temp_r30 = *(*(s32 * *)&ply_level_table);
  ;
  return (*((s32 *) (((s8 *) temp_r30) + (TObjPlayer__sub_801AFDBC(arg0) * 4)))) + (TObjPlayer::clamp_index_to_max(arg1) * 0xC);
}

void TObjPlayer__sub_801D92A4(void) { TLobby::free_nodes_with_id(ply_level_table); }

void load_ply_level_tbl(void) { ply_level_table = load_encrypted_archive_data("PlyLevelTbl.cpt"); }


typedef char RecoveredGlobal_801D92F4_lbl_804475B0_size[sizeof(RecoveredGlobal_801D92F4_lbl_804475B0) == 0x240 ? 1 : -1];

u8 *get_class_attack_template(TObjPlayer *player) {
    return (u8 *)class_attack_template_table + (player->get_class_index() * 0x30);
}

u8 *get_class_defense_template(TObjPlayer *player) {
    return (u8 *)class_defense_template_table + (player->get_class_index() << 5);
}

stats *get_class_base_stats(s8 arg0) {
    return player_class_base_stat_tables[TObjPlayer__sub_801AFDBC(arg0)];
}

player_stats *get_class_stat_caps(s8 arg0) {
    return (player_stats*)&player_class_stat_caps[TObjPlayer__sub_801AFDBC(arg0)];
}

player_stats *TObjPlayer::get_class_stat_entry(u8 *player) {
    return (player_stats*)&player_class_stat_caps[((TObjPlayer *)player)->get_class_index()];
}

f32 TObjPlayer::get_tp_class_factor() {
    u8 *arg0 = (u8 *)this;
    if (this->class_flags & CLASS_FLAG_ANDROID) {
        return 0.0f;
    }
    return player_profession_stat_factors[((TObjPlayer *)arg0)->get_clamped_index()].tp;
}

f32 TObjPlayer::get_class_hp_factor() {
    return player_profession_stat_factors[get_clamped_index()].hp;
}

int TObjPlayer::get_floor_surface_type() { return get_contact_surface_type((s32)((char*)this + 0x360)); }
s32 TObjPlayer::get_falz_phase() { return TBoss4DarkFalz__sub_801D94C0((void*)((char*)this + 0x7cc)); }

    extern int dark_falz_form_index;
int TBoss4DarkFalz::get_instance_count() {  return dark_falz_form_index; }

s32 TBoss4DarkFalz__sub_801D94C0(void* p) { return *(s32*)((char*)p + 0x14); }

const Vec_801D8CCC *hospital_position_table_by_episode[2] = {
    lbl_8044916C, lbl_8044919C,
};
const Vec_801D8CCC *guild_return_position_table_by_episode[2] = {
    lbl_804491D4, lbl_80449204,
};

// Highest technique level per class (12 classes x 19 techniques, 0xFF = not learnable), read by
// TObjPlayer__sub_801D9514.
static const u8 lbl_804492F8[20] = { 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0xFF, 0xFF, 0x0E, 0x0E, 0xFF, 0x0E, 0x0E, 0x04, 0xFF, 0xFF, 0x00 };
static const u8 lbl_8044930C[20] = { 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0xFF, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x06, 0xFF, 0xFF, 0x00 };
static const u8 lbl_80449320[20] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00 };
static const u8 lbl_80449334[20] = { 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0x0E, 0xFF, 0x0E, 0xFF, 0xFF, 0x0E, 0x0E, 0x0E, 0x04, 0xFF, 0xFF, 0x00 };
static const u8 lbl_80449348[20] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00 };
static const u8 lbl_8044935C[20] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00 };
static const u8 lbl_80449370[20] = { 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x06, 0x1D, 0x1D, 0x00 };
static const u8 lbl_80449384[20] = { 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x06, 0x1D, 0x1D, 0x00 };
static const u8 lbl_80449398[20] = { 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x06, 0x1D, 0x1D, 0x00 };
static const u8 lbl_804493AC[20] = { 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00 };
static const u8 lbl_804493C0[20] = { 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x1D, 0x06, 0x1D, 0x1D, 0x00 };
static const u8 lbl_804493D4[20] = { 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0xFF, 0x13, 0x13, 0x13, 0x13, 0x13, 0x13, 0x06, 0xFF, 0xFF, 0x00 };
const u8 *class_technique_cap_table[12] = {
    lbl_804492F8, lbl_8044930C, lbl_80449320, lbl_80449334, lbl_80449348, lbl_8044935C,
    lbl_80449370, lbl_80449384, lbl_80449398, lbl_804493AC, lbl_804493C0, lbl_804493D4,
};
