#ifndef PSO_BOSS_GALGRYPHON_BOSS5GRYPHONACTIONSCRIPTS_H
#define PSO_BOSS_GALGRYPHON_BOSS5GRYPHONACTIONSCRIPTS_H
#include "types.h"

// One step of a TBoss5Gryphon action script. TBoss5Gryphon::action_scripts points at the
// script list and script_entry walks a script one step at a time; command indexes the
// action table in TBoss8Dragon::run_action_script_step (0x21 picks the next script).
struct Boss5GryphonIntRange {
    s32 min;
    s32 range;
};

struct Boss5GryphonFloatRange {
    f32 min;
    f32 range;
};

struct Boss5GryphonActionStep {
    u32 command;  // the state the step runs (0x21 picks the next script); indexes the step actions
    s16 base;    // rand_scaled_offset(base, spread)
    s16 spread;
    Boss5GryphonIntRange ints[4];      // random_in_table_range(step, i)
    Boss5GryphonFloatRange floats[4];  // random_float_in_table_range(step, i)
};

LAYOUT_ASSERT(Boss5GryphonActionStep_size, sizeof(Boss5GryphonActionStep) == 0x48);

extern "C" Boss5GryphonActionStep *boss5_gryphon_action_scripts[30];

#endif
