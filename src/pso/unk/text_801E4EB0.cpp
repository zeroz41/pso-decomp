#include "types.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/unk/TUnk_804C57F0.h"

void TUnk_804C57F0::quad_sprite_reset_entries() {
    s32 i;
    for (i = 0; i < definition->uv_count; i++) {
        lists[i].next = NULL;
        tails[i] = &lists[i];
    }
    queued = 0;
}
