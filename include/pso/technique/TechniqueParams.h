#ifndef PSO_TECHNIQUE_TECHNIQUEPARAMS_H
#define PSO_TECHNIQUE_TECHNIQUEPARAMS_H

#include "types.h"

// One technique's parameters (0x2C bytes): a row of technique_param_table and
// the block calc_technique_parameters scales by the caster's level.
struct TechniqueParams {
    f32 power;
    f32 speed;       // a shot's speed per frame (more above level 4 for Foie)
    f32 range;       // a shot's range, an area's radius; raised by range_step
    f32 pad_0C;
    s16 tp_cost;     // the TP the cast takes (callers subtract it from the player's TP)
    s16 pad_12;      // charge speed, "CH_SPD" in TTecShot's readout; lowered per level above 4, at least 0
                     // (named once PR 394, which reads it in TObjPlayer, lands)
    s16 mental;      // "MENTAL" in TTecShot's readout; raised by mental_per_level per level
    s16 pad_16;
    s32 angle;       // degrees in the table; Foie, Rafoie, Barta, Gibarta and Megid turn it into angle units (65536 / 360)
    s32 pad_1C;
    s16 pad_20;      // frames an area lasts (RaBarta); lowered every 5 or 10 levels, at least 10
    u8 pad_22;
    u8 tp_cost_percent;  // percent of a level added to tp_cost
    s16 power_per_level;  // added to power once per level
    s16 range_step;  // added to range per level above 4 or per 5 levels
    s16 mental_per_level;
    s16 angle_step;  // degrees added to angle per 5 levels

    void copy(TechniqueParams *src);
};

// Per technique: the factors applied to a cast's power and to tp_cost while
// TTecCtrl::is_technique_ready().
struct TechniqueCostScale {
    f32 power;
    f32 tp_cost;
};

// Per technique: the power of a cast at level 15 and up while not
// TTecCtrl::is_technique_ready(), base + per_level * level.
struct TechniqueLinearPower {
    s16 base;
    s16 per_level;
};

extern TechniqueParams technique_param_table[];
extern TechniqueLinearPower tech_high_level_linear_power_table[];
// The block calc_technique_parameters fills and returns.
extern TechniqueParams calculated_technique_params;
extern TechniqueCostScale technique_scale_table[];

extern "C" {
TechniqueParams *calc_technique_parameters(s32 technique, s32 level, u16 client);
}

s32 clamp_nonnegative_int(s32 x);

#endif
