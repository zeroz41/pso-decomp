#ifndef PSO_OBJECT_TRAP_TOTRAPSEABED01_H
#define PSO_OBJECT_TRAP_TOTRAPSEABED01_H

#include "types.h"
#include "pso/object/trap/TOTrap.h"

struct TOTrapSeabed01 : public TOTrap {
    TOTrapSeabed01(TObject *parent, void *set_data);
    virtual ~TOTrapSeabed01();
    virtual void vfunc_6(s16 *, s32);
    virtual void render();
    virtual f32 receive_physical_attack(void *, f32);
    virtual int deliver_attack_hits(f32 damage_scale);
    virtual void vfunc_81();
    virtual void vfunc_82();
    virtual void vfunc_84();
    virtual void play_sounds();
    void draw_object_tree(NJS_OBJECT *object);
    void render_effect_layers();
    void sub_802C9D38();
    void sub_802C9C18(s32);
    void check_hold_player();
    void clamp_params_and_init();
    void draw();
    static void *create(void *set_data);
    static void free_static_resources();
    static void load_resources();
    static void trigger_by_id(NJS_OBJECT *node);
    s32 pad_344;
    s32 strike_timer; // name inferred: 30 frames per set param 1; vfunc_82 strikes when it runs out
    s32 projected; // name inferred: set param 2 != 0; draws with the particle TEV and the projection texture
    DirectAttackPayload payload; // name inferred: sent to every player in reach by vfunc_67
    s32 sound_handle; // name inferred: play_sound_effect's result, stopped by vfunc_6
};

LAYOUT_ASSERT(TOTrapSeabed01_size, sizeof(TOTrapSeabed01) == 0x35C);
#endif
