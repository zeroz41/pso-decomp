#ifndef PSO_TECHNIQUE_TECHNIQUEPARAMS_H
#define PSO_TECHNIQUE_TECHNIQUEPARAMS_H

#include "types.h"

// One technique's parameters (0x2C bytes): a row of technique_param_table and
// the block calc_technique_parameters scales by the caster's level.
struct TechniqueParams {
    f32 pad_00;
    f32 pad_04;
    f32 pad_08;      // raised by pad_26 per level
    f32 pad_0C;
    s16 tp_cost;     // the TP the cast takes (callers subtract it from the player's TP)
    s16 pad_12;      // lowered per level above 4, at least 0
    s16 pad_14;      // raised by pad_28 per level
    s16 pad_16;
    s32 pad_18;      // degrees; some techniques turn it into angle units (65536 / 360)
    s32 pad_1C;
    s16 pad_20;      // lowered every 5 or 10 levels; 10 when it would drop to 0
    u8 pad_22;
    u8 tp_cost_percent;  // percent of a level added to tp_cost
    s16 pad_24;
    s16 pad_26;      // pad_08 per level
    s16 pad_28;      // pad_14 per level
    s16 pad_2A;      // pad_18 per 5 levels
};

// Per technique: the factor applied to tp_cost while TTecCtrl::is_technique_ready().
struct TechniqueCostScale {
    f32 pad_00;
    f32 tp_cost;
};

extern "C" {
extern TechniqueParams technique_param_table[];
extern TechniqueParams lbl_80515F90;
extern TechniqueCostScale lbl_804CC55C[];
TechniqueParams *calc_technique_parameters(s32 technique, s32 level, u16 client);
}

s32 clamp_nonnegative_int(s32 x);

#endif
