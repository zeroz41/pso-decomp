#ifndef PSO_ENEMY_TOBJENEME3SHINOWAREAL_H
#define PSO_ENEMY_TOBJENEME3SHINOWAREAL_H

#include "types.h"
#include "pso/enemy/TObjEneMe3Shinowa.h"

struct TObjEneMe3ShinowaReal : public TObjEneMe3Shinowa {
    virtual ~TObjEneMe3ShinowaReal();
    virtual void vfunc_114(s32);
    virtual void vfunc_116(s32);
    virtual void vfunc_107();
    virtual void vfunc_111();
    void sub_800E7250();
    void vfunc_63();
    void vfunc_62();

    u8 _padAfterBaseFade[0x4];
    u32 m_424;
    void spawn_mirages();
    s32 get_or_create_mirage(s32 arg1);
    void try_spawn_mirages();
    void *create();
    static f32 get_random_float();
    u8 unk_40C[0x28];
};
typedef char TObjEneMe3ShinowaReal_m_424_offset[offsetof(TObjEneMe3ShinowaReal, m_424) == 0x408 ? 1 : -1];

typedef char TObjEneMe3ShinowaReal_size[sizeof(TObjEneMe3ShinowaReal) == 0x434 ? 1 : -1];
#endif
