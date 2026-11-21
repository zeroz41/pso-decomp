#ifndef PSO_NPC_NPC_ANIMATION_BINDING_H
#define PSO_NPC_NPC_ANIMATION_BINDING_H

#include "types.h"
#include <stddef.h>

struct BmlMotionEntry;
struct TObjMotionAction;

struct NpcAnimationBinding {
    BmlMotionEntry *motions;
    TObjMotionAction *actions;
    s16 default_action;
    s16 mode2_action;
    s16 debug_action_limit;

    NpcAnimationBinding &operator=(const NpcAnimationBinding &other);
};

LAYOUT_ASSERT(NpcAnimationBinding_size, sizeof(NpcAnimationBinding) == 0x10);
LAYOUT_ASSERT(NpcAnimationBinding_actions_offset, offsetof(NpcAnimationBinding, actions) == 4);
LAYOUT_ASSERT(NpcAnimationBinding_default_offset, offsetof(NpcAnimationBinding, default_action) == 8);
LAYOUT_ASSERT(NpcAnimationBinding_mode2_offset, offsetof(NpcAnimationBinding, mode2_action) == 0xA);
LAYOUT_ASSERT(NpcAnimationBinding_debug_limit_offset, offsetof(NpcAnimationBinding, debug_action_limit) == 0xC);

#endif
