#ifndef PSO_PLAYER_PLAYERTECHNIQUESTATE_H
#define PSO_PLAYER_PLAYERTECHNIQUESTATE_H

#include <stddef.h>
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include "pso/player/PhotonBlastGauge.h"

// A player's techniques (TObjPlayer + 0x428): the cast in progress, its
// targets and the level of each of the 19 techniques.
class PlayerTechniqueState {
public:
    PlayerTechniqueState();
    void reset_all_tech_slots();
    void reset_tech_state();
    void set_level(u8 v);
    void set_tech_override(u8 v);
    void set_technique_id(s16 v);
    s16 get_or_init_field_4();
    void set_tech_level(s16 lim);
    void reset_slots();
    s16 get_section_clamped();
    u8 get_valid_technique();
    u8 get_castable_technique_level();
    s32 check_technique_level(s16 technique, u8 level);
    PhotonBlastTarget *get_technique_data();
    void set_technique_state(s32 v);
    s32 get_state();
    void decrement_state();
    s32 test_flag_2();
    f32 get_charge_step();
    void set_charge_step(f32 step);
    void set_field18(f32 v);
    void set_field_1c(f32 v);
    void set_technique_level(s16 technique, u8 level);
    u8 get_technique_level(s16 technique) const;
    u8 get_learned_level(s16 technique) const;
    void set_learned_level(s16 technique, u8 level);
    void enable_techniques();
    void disable_techniques();

    u8 level;
    u8 level_override;
    u8 pad_2;
    u8 pad_3;
    s16 technique;
    s16 target_count;
    s16 pad_8;
    s16 pad_a;
    s32 state;
    FlagWord flags;
    f32 charge_step;
    f32 pad_18;
    f32 pad_1c;
    PhotonBlastTarget targets[10];
    u8 learned_levels[0x14];
    u8 levels[0x14];
    u8 caps[0x14];

    static s32 technique_count();
    PhotonBlastTarget *get_target(s32 slot);
    void set_target(s32 slot, s32 entity_id, s16 index);
    u8 clamp_to_max(u8 level, u8 max);
    u8 get_effective_technique_level(s16 technique);
    void set_technique_cap(s16 technique, u8 level);
    void set_all_technique_levels(u8 level);
    void copy_all_technique_entries(u8 level);
    void set_learned_technique_levels(u8 level);
    void level_up_all_techniques(u8 add);
    static s32 is_valid_technique_id(s16 technique);
    void clear_technique_level(s16 technique);
    void sub_801D9E10(s16 value);
};

LAYOUT_ASSERT(PlayerTechniqueStateSize, sizeof(PlayerTechniqueState) == 0x84);
LAYOUT_ASSERT(PlayerTechniqueStateLearnedLevels, offsetof(PlayerTechniqueState, learned_levels) == 0x48);
LAYOUT_ASSERT(PlayerTechniqueStateLevels, offsetof(PlayerTechniqueState, levels) == 0x5C);

#endif
