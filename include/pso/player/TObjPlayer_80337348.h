#ifndef PSO_PLAYER_TOBJPLAYER_80337348_H
#define PSO_PLAYER_TOBJPLAYER_80337348_H

#include "types.h"

// TObjPlayer + 0x374: how many stat materials the player has used, per material:
// counts[0] power, [1] mind, [2] evade, [3] def, [4] luck. The sum is capped at
// get_material_limit_for_class (250 for humans, 150 for newmans and androids).
struct MaterialUsage {
    u8 get_luck_used();
    u8 get_def_used();
    u8 get_evade_used();
    u8 get_mind_used();
    u8 get_power_used();
    void set_luck_used(u8 v);
    void set_def_used(u8 v);
    void set_evade_used(u8 v);
    void set_mind_used(u8 v);
    void set_power_used(u8 v);
    void add_item_count_kind4(s32 class_index, u8 amount);
    void try_add_item_count_kind3(s32 class_index, u8 amount);
    void try_add_item_count_type2(s32 class_index, u8 amount);
    void add_item_count(s32 class_index, u8 amount);
    void try_add_item(s32 class_index, u8 amount);
    s32 try_add_item_count(s32 class_index, s32 index, u8 amount);
    s32 can_use_more_materials(s32 class_index);
    u8 get_total_materials_used();
    void set_count(s32 index, u8 count);
    u8 get_count(s32 index);

    u8 counts[8];

    MaterialUsage();
    virtual ~MaterialUsage();
};

LAYOUT_ASSERT(MaterialUsage_size, sizeof(MaterialUsage) == 0xC);

u8 get_material_limit_for_class(s32 class_index);

#endif
