#ifndef PSO_PLAYER_TOBJPLAYER_80337348_H
#define PSO_PLAYER_TOBJPLAYER_80337348_H

#include "types.h"

// TObjPlayer + 0x374: the player's material usage counts. Name inferred from its API
// (get_total_materials_used sums counts[0..4]; try_add_item_count caps the sum at
// get_material_limit_for_class; can_use_more_materials). Its constructor
// (TObjPlayer__sub_803374C4) stores lbl_804C3E44, whose only slot is the destructor TObjPlayer__sub_801BEDC0,
// at +8.
struct MaterialUsage {
    u8 fn_801BED70();
    u8 fn_801BED78();
    u8 fn_801BED80();
    u8 fn_801BED88();
    u8 fn_801BED90();
    void fn_801BED98(u8 v);
    void fn_801BEDA0(u8 v);
    void fn_801BEDA8(u8 v);
    void fn_801BEDB0(u8 v);
    void fn_801BEDB8(u8 v);
    void add_item_count_kind4(s32 class_index, u8 amount);
    void try_add_item_count_kind3(s32 class_index, u8 amount);
    void try_add_item_count_type2(s32 class_index, u8 amount);
    void add_item_count(s32 class_index, u8 amount);
    void try_add_item(s32 class_index, u8 amount);
    s32 try_add_item_count(s32 class_index, s32 index, u8 amount);
    s32 can_use_more_materials(s32 class_index);
    u8 get_total_materials_used();
    void fn_803374F0(s32 index, u8 value);
    u8 fn_803374F8(s32 index);

    u8 counts[8];
    u8 pad_8[4];
};

u8 get_material_limit_for_class(s32 arg0);

#endif
