#ifndef PSO_SYSTEM_BML_RESOURCE_H
#define PSO_SYSTEM_BML_RESOURCE_H

#include "types.h"

struct BmlModelEntry {
    s32 m_0;
    s32 m_4;
    saddr model;
    saddr m_c;
};

struct AnimationMotion;
struct BmlMotionEntry {
    u32 unknown;
    AnimationMotion *motion;
};

struct BmlResource {
    u8 m_0[0x42C];
    BmlModelEntry *models;
    BmlMotionEntry *motions;
};

extern "C" saddr get_bml_model(BmlResource *resource, s32 index);

#endif
