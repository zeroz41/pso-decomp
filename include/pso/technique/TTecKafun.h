#ifndef PSO_TECHNIQUE_TTECKAFUN_H
#define PSO_TECHNIQUE_TTECKAFUN_H

#include "types.h"
#include "pso/technique/TTecCircle.h"

struct TTecKafun : public TTecCircle {
    virtual ~TTecKafun();
    virtual void apply_to_target(TObjChara *);
    f32 hit_value;         // apply_to_target passes it with hit_kind to the target
    s32 effect;            // particle effect run_task spawns at its position
    s32 second_effect;     // spawned too while has_second_effect is 1
    s32 hit_kind;          // apply_to_target sends 15..18 after a kind-0 hit
    s32 has_second_effect;
    virtual void render();
    virtual void run_task();
    TTecKafun(TObjBase *source, Vec *pos, s32 kind, s32 effect, s32 second_effect, s32 level, f32 value, f32 radius);
    TTecKafun(TObjBase *source, Vec *pos, s32 kind, s32 effect, s32 level, f32 value, f32 radius);
    // value before level: the Mericarol call evaluates its radius, level and value right to left in that order.
    static void create(TObjBase *source, Vec *pos, s32 kind, s32 effect, s32 second_effect, f32 value, s32 level, f32 radius);
    static void create(TObjBase *source, Vec *pos, s32 kind, s32 effect, s32 level, f32 value, f32 radius);
};

LAYOUT_ASSERT(TTecKafun_size, sizeof(TTecKafun) == 0x100);
#endif
