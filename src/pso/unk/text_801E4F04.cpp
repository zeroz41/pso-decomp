#include "types.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/unk/TUnk_804C57F0.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

TUnk_804C57F0::~TUnk_804C57F0() {
    mem_free(tails);
    tails = NULL;
    mem_free(lists);
    lists = NULL;
}

TUnk_804C57F0::TUnk_804C57F0(TObject *parent, ParticleDefinition *sprite_definition) : TObject(parent) {
    s32 count;

    definition = sprite_definition;
    count = definition->uv_count;
    lists = (QuadSpriteNode *)mem_alloc(count * sizeof(QuadSpriteNode));
    tails = (QuadSpriteNode **)mem_alloc(count * sizeof(QuadSpriteNode *));
    quad_sprite_reset_entries();
}
