#include "types.h"
#include "pso/effect/particle/ParticleDefinition.h"
#include "pso/unk/TUnk_804C57F0.h"
#include "pso/unk/text_801E4F04.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"


TUnk_804C57F0::~TUnk_804C57F0() {
    mem_free(*(void **)((s8 *)this + 0x20));
    this->m_20 = 0;
    mem_free(*(void **)((s8 *)this + 0x1C));
    *(s32 *)((s8 *)this + 0x1C) = 0;
}


#define arg0 ((u8 *)this)
TUnk_804C57F0::TUnk_804C57F0(TObject *parent, ParticleDefinition *sprite_definition) : TObject(parent) {
    s32 temp_r31;

    ((TUnk_804C57F0 *)arg0)->definition = sprite_definition;
    temp_r31 = ((TUnk_804C57F0 *)arg0)->definition->uv_count;
    *(s32 *)((s8 *)arg0 + 0x1C) = (saddr)mem_alloc(temp_r31 * 0x2C);
    ((TUnk_804C57F0 *)arg0)->m_20 = (saddr)mem_alloc(temp_r31 * 4);
    ((TUnk_804C57F0 *)arg0)->quad_sprite_reset_entries();
}
#undef arg0

