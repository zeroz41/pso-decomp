#ifndef PSO_ENEMY_TOBJENEME3SHINOWAREAL_H
#define PSO_ENEMY_TOBJENEME3SHINOWAREAL_H

#include "types.h"
#include "pso/enemy/TObjEneMe3Shinowa.h"

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
    u8 _pad3EC[0x10];
    u32 m_3fc;
    u8 _pad400[0x4];
    u32 m_404;
    u8 _pad408[0x1C];
    u32 m_424;
    void spawn_mirages();
    TObjEneMe3ShinowaMirage *get_or_create_mirage(s32 index);
    void try_spawn_mirages();
    void *create();
    u8 unk_40C[0x28];
};

typedef char TObjEneMe3ShinowaReal_size[sizeof(TObjEneMe3ShinowaReal) == 0x434 ? 1 : -1];
#endif
