#ifndef PSO_BOSS_GALGRYPHON_BOSS5GRYPHONACTIONSCRIPTS_H
#define PSO_BOSS_GALGRYPHON_BOSS5GRYPHONACTIONSCRIPTS_H
#include "types.h"

// One step of a TBoss5Gryphon action script. TBoss5Gryphon::m_778 points at the
// script list and m_774 walks a script 0x48 bytes at a time; command indexes the
// action table in TBoss8Dragon::run_action_script_step (0x21 picks the next script).
struct Boss5GryphonActionStep {
    s32 command;
    s16 base;    // rand_scaled_offset(base, spread)
    s16 spread;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14[5];
    f32 unk28;
    s32 unk2C;
    f32 unk30;
    s32 unk34[5];
};

typedef char Boss5GryphonActionStep_size[sizeof(Boss5GryphonActionStep) == 0x48 ? 1 : -1];

extern "C" Boss5GryphonActionStep *boss5_gryphon_action_scripts[30];

#endif
