#ifndef PSO_OBJECT_TRAP_TOTRAPANCIENT01_H
#define PSO_OBJECT_TRAP_TOTRAPANCIENT01_H

#include "types.h"
#include "pso/object/trap/TOTrap.h"
#include "pso/render/RenderFadeState.h"

struct TOTrapAncient01 : public TOTrap {
    TOTrapAncient01(TObject *parent, void *set_data);
    virtual ~TOTrapAncient01();
    virtual void update_holding();
    virtual void update_springing();
    virtual void update_effects();
    virtual void play_sounds();
    virtual void run_demo();
    virtual void vfunc_86();
    virtual void apply_saved_state(s16 *, s32);
    virtual f32 receive_physical_attack(TObjChara *, f32);
    virtual void render();
    DirectAttackPayload payload; // name inferred: sent to every player in reach by update_holding
    f32 scale_step; // name inferred: added to scale.y each frame by update_springing, -scale.y / scale.z in the ctor
    f32 damage_delay; // name inferred: 30 + set param 3 frames, damage_timer's reload value
    f32 damage_timer; // name inferred: counts down by 1 per update_holding frame; at < 0 the trap strikes
    RenderFadeState fades[4];
    void release_trapped_player();
    static void *create(void *set_data);
    static void release_static_resource();
    static void load_resources();
};

LAYOUT_ASSERT(TOTrapAncient01_size, sizeof(TOTrapAncient01) == 0x3C8);

#endif
