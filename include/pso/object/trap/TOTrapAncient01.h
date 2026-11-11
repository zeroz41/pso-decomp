#ifndef PSO_OBJECT_TRAP_TOTRAPANCIENT01_H
#define PSO_OBJECT_TRAP_TOTRAPANCIENT01_H

#include "types.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/render/RenderFadeState.h"

struct TOTrapAncient01 : public TOTrap {
    TOTrapAncient01(TObject *parent, void *set_data);
    virtual ~TOTrapAncient01();
    virtual void vfunc_82();
    virtual void vfunc_81();
    virtual void vfunc_84();
    virtual void play_sounds();
    virtual void vfunc_88();
    virtual void vfunc_86();
    virtual void vfunc_6(s16 *, s32);
    virtual f32 receive_physical_attack(void *, f32);
    virtual void render();
    DirectAttackPayload payload; // name inferred: sent to every player in reach by vfunc_82
    f32 scale_step; // name inferred: added to scale.y each frame by vfunc_81, -scale.y / scale.z in the ctor
    f32 damage_delay; // name inferred: 30 + set param 3 frames, damage_timer's reload value
    f32 damage_timer; // name inferred: counts down by 1 per vfunc_82 frame; at < 0 the trap strikes
    RenderFadeState fades[4];
    void release_trapped_player();
    void *create();
    static void release_static_resource();
    static void load_resources();
    static s32 check_trigger_flag(s32 arg0, s32 arg1);
};

typedef char TOTrapAncient01_size[sizeof(TOTrapAncient01) == 0x3C8 ? 1 : -1];

#endif
