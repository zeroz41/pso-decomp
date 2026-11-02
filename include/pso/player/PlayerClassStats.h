#ifndef PSO_PLAYER_CLASS_STATS_H
#define PSO_PLAYER_CLASS_STATS_H
#include "pso/TPlyDispData.h"

#include "pso/TPlyInventory.h"

struct PlayerProfessionStatFactors { f32 hp; f32 tp; };

// Record types of the class/motion tables; layouts from the original bytes and
// the accessors' strides, field meanings unknown.
struct Rec_804475B0 {
    s16 unk0;
    s16 unk2;
    s16 unk4;
    s16 unk6;
    f32 unk8;
    s32 unkC;
    f32 unk10;
    u8 pad_14[0x1C];
};

struct Rec_8044821C {
    u16 unk0;
    u16 unk2;
    s32 unk4;
    f32 unk8;
    u32 unkC;
};

struct Rec_8044845C {
    s16 unk0;
    s16 unk2;
};

struct Rec_804484EC {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    s32 unk10;
};

struct Vec_801D8CCC { f32 x, y, z; };
extern "C" {
extern const PlayerProfessionStatFactors player_profession_stat_factors[3];
extern const player_stats player_class_stat_caps[12];
extern stats* player_class_base_stat_tables[12];
extern const u8 class_defense_template_table[12][0x20];
extern const Rec_804475B0 class_attack_template_table[12];
extern const f32 attack_marker_table[19][3];
extern const f32 attack_marker_table_dagger[3][3];
extern const f32 attack_marker_table_double_saber[4][3];
extern const f32 twin_sword_male_marker_table[3][3];
extern const f32 twin_sword_female_marker_table[3][3];
extern const u8 attack_recovery_count_table[20][3];
extern const s32 lbl_804479AC[36][5];
extern const s32 lbl_80447C7C[36][5];
extern const s32 lbl_80447F4C[36][5];
extern const Rec_8044821C lbl_8044821C[12];
extern const Rec_8044821C lbl_804482DC[12];
extern const Rec_8044821C lbl_8044839C[12];
extern const Rec_8044845C lbl_8044845C[12];
extern const Rec_8044845C lbl_8044848C[12];
extern const Rec_8044845C lbl_804484BC[12];
extern const Rec_804484EC lbl_804484EC[19];
extern const Rec_804484EC lbl_80448668[19];
extern const Rec_804484EC lbl_804487E4[19];
extern const Rec_804484EC lbl_80448960[19];
extern const TPlyInventoryItem lbl_80448ADC[5];
extern const TPlyInventoryItem lbl_80448B68[5];
extern const TPlyInventoryItem lbl_80448BF4[5];
extern const TPlyInventoryItem lbl_80448C80[5];
extern const TPlyInventoryItem lbl_80448D0C[5];
extern const TPlyInventoryItem lbl_80448D98[5];
extern const TPlyInventoryItem lbl_80448E24[5];
extern const TPlyInventoryItem lbl_80448EB0[5];
extern const TPlyInventoryItem lbl_80448F3C[5];
extern const TPlyInventoryItem lbl_80448FC8[5];
extern const TPlyInventoryItem lbl_80449054[5];
extern const TPlyInventoryItem lbl_804490E0[5];
extern const Vec_801D8CCC lbl_8044916C[4];
extern const Vec_801D8CCC lbl_8044919C[4];
extern const s32 lbl_804491CC[2];
extern const Vec_801D8CCC lbl_804491D4[4];
extern const Vec_801D8CCC lbl_80449204[4];
extern const s32 lbl_80449234[2];
extern const Vec_801D8CCC lobby_entry_table[2];
extern const s32 lbl_80449254[2];
extern const s32 player_hurt_protection_ticks_table[4];
extern const s32 player_hurt_protection_ticks_table_flagged[4];
extern const s32 player_hurt_protection_ticks_table_phase15[4];
extern const s32 hurt_protection_ticks_table[4];
extern const s32 getup_protection_ticks_table_a[4];
extern const s32 getup_protection_ticks_table_b[4];
extern const s32 player_getup_protection_ticks_table[4];
extern const s32 player_getup_protection_ticks_table_flagged[4];
}
#endif
