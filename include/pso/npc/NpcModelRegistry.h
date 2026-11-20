#ifndef PSO_NPC_NPC_MODEL_REGISTRY_H
#define PSO_NPC_NPC_MODEL_REGISTRY_H

#include "types.h"

struct NpcAnimationBinding;
struct NJS_OBJECT;
struct GinjaTextureList;

struct NpcModelRegistry {
    static void register_animated_ginja(s16 id, NJS_OBJECT *model, GinjaTextureList *textures,
                                        const NpcAnimationBinding *animation,
                                        f32 collision_radius, f32 vertical_offset);
};

#endif
