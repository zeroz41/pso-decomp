#ifndef PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWAREAL_H
#define PSO_ENEMY_SHINOWA_TOBJENEME3SHINOWAREAL_H

#include "types.h"
#include "pso/enemy/shinowa/TObjEneMe3Shinowa.h"

struct TObjEneMe3ShinowaMirage;

struct TObjEneMe3ShinowaReal : public TObjEneMe3Shinowa {
    virtual ~TObjEneMe3ShinowaReal();
    virtual void vfunc_114(s32);
    virtual void vfunc_116(s32);
    virtual void vfunc_107();
    virtual void vfunc_111();
    void sub_800E7250();
    void vfunc_63();
    void vfunc_62();
    void spawn_mirages();
    TObjEneMe3ShinowaMirage *get_or_create_mirage(s32 index);
    void try_spawn_mirages();
    TObjEneMe3ShinowaReal *create();
    u16 m_42c[4];
};

typedef char TObjEneMe3ShinowaReal_size[sizeof(TObjEneMe3ShinowaReal) == 0x434 ? 1 : -1];
#endif
