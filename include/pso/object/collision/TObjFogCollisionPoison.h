#ifndef PSO_OBJECT_COLLISION_TOBJFOGCOLLISIONPOISON_H
#define PSO_OBJECT_COLLISION_TOBJFOGCOLLISIONPOISON_H

#include "types.h"
#include "pso/object/collision/TObjFogCollisionSwitch.h"

struct TObjFogCollisionPoison : public TObjFogCollisionSwitch {
    virtual ~TObjFogCollisionPoison();
    virtual void vfunc_14();
    virtual void vfunc_13(s32);
    virtual void run_task();
    u32 m_98;
    static void create();
    static void clear_state_array();
    u8 check_switch();
    void apply_poison_damage(s32 arg1);
    void record_poison_hit(u16 arg1);
};

typedef char TObjFogCollisionPoison_size[sizeof(TObjFogCollisionPoison) == 0x9C ? 1 : -1];
extern "C" {
void TObjFogCollisionPoison__sub_801533BC(void);
void TObjFogCollisionPoison__sub_80153520(s32 arg0);
void TObjFogCollisionPoison__sub_801535D0(s32 arg0);
void record_fog_collision_hit(s32 arg0, s32 arg1, s32 arg2);
}

#endif
