#include "types.h"
#include "pso/unk/text_80087278.h"
#include "pso/effect/TParticleCtrl.h"
struct Data_8008741C { u8 pad[0x98]; };

struct Ent_80087350 { u8 data[0x98]; };

extern "C" {
extern s32 particle_pool_limit;
extern Data_8008741C *particle_global_entry_table;
extern Data_8008741C *particle_area_entry_table;
void *__nw__7TObjectFUl(u32);
void *initialize_with_flags__13TParticleCtrlFPCvlllllUs(void *, void *, void *, s32, s32, s32, s32, s32);

#pragma push
#pragma opt_propagation off
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags) {
    void *p;
    s32 idx = id;
    if (particle_pool_limit > idx) {
        p = __nw__7TObjectFUl((u32)(0x78));
        if (p != 0) {
            p = initialize_with_flags__13TParticleCtrlFPCvlllllUs(p, pos, &particle_global_entry_table[idx], 1, 0, 0, 0, flags);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > idx) {
        idx -= 0x200;
        p = __nw__7TObjectFUl((u32)(0x78));
        if (p != 0) {
            p = initialize_with_flags__13TParticleCtrlFPCvlllllUs(p, pos, &particle_area_entry_table[idx], 1, 0, 0, 0, flags);
        }
        return p;
    }
    return 0;
}
#pragma pop

void *spawn_particle_effect(void *pos, s32 id) {
    void *p;
    if (particle_pool_limit > id) {
        p = __nw__7TObjectFUl((u32)(0x78));
        if (p != 0) {
            p = ((TParticleCtrl *)p)->initialize((const void *)pos, (s32)(&(*(Ent_80087350 * *)&particle_global_entry_table)[id]), 1, 0, 0, 0);
        }
        return p;
    }
    if (particle_pool_limit + 0x40 > id) {
        s32 idx = id - 0x200;
        p = __nw__7TObjectFUl((u32)(0x78));
        if (p != 0) {
            p = ((TParticleCtrl *)p)->initialize((const void *)pos, (s32)(&(*(Ent_80087350 * *)&particle_area_entry_table)[idx]), 1, 0, 0, 0);
        }
        return p;
    }
    return 0;
}

TParticleCtrl *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags) {
    void *p;
    if (particle_pool_limit > idx) {
        p = __nw__7TObjectFUl(0x78);
        if (p != 0) {
            p = initialize_with_flags__13TParticleCtrlFPCvlllllUs(p, parent, &particle_global_entry_table[idx], 0, 0, 0, 0, flags);
        }
        return (TParticleCtrl *)p;
    } else if (particle_pool_limit + 0x40 > idx) {
        s32 j = idx - 0x200;
        p = __nw__7TObjectFUl(0x78);
        if (p != 0) {
            p = initialize_with_flags__13TParticleCtrlFPCvlllllUs(p, parent, &particle_area_entry_table[j], 0, 0, 0, 0, flags);
        }
        return (TParticleCtrl *)p;
    } else {
        return 0;
    }
}

}
