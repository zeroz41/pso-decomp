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
    void set_technique_state(s32 v);
    void set_field18(f32 v);
    void set_field_1c(f32 v);
    void set_technique_level(s16 technique, u8 level);

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
    u8 pad_14[0x4];
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
    static s32 is_valid_technique_id(s16 technique);
    void clear_technique_level(s16 technique);
};

extern "C" void TObjPlayer__sub_801D9E10(PlayerTechniqueState *techs, s16 value);

LAYOUT_ASSERT(PlayerTechniqueStateSize, sizeof(PlayerTechniqueState) == 0x84);
LAYOUT_ASSERT(PlayerTechniqueStateLevels, offsetof(PlayerTechniqueState, levels) == 0x5C);

#endif
