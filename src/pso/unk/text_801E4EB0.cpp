#include "types.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/unk/TUnk_804C57F0.h"
struct Ent_801E4EB0 { s32 first; u8 rest[0x28]; };

struct Obj_801E4EB0 {
    u8 pad[0x1C];
    Ent_801E4EB0 *ents;
    Ent_801E4EB0 **ptrs;
    s32 f24;
    ParticleDefinition *definition;
};

void TUnk_804C57F0::quad_sprite_reset_entries() {
    Obj_801E4EB0 *o = (Obj_801E4EB0 *)this;
    s32 i;
    for (i = 0; i < o->definition->uv_count; i++) {
        o->ents[i].first = 0;
        o->ptrs[i] = &o->ents[i];
    }
    o->f24 = 0;
}
