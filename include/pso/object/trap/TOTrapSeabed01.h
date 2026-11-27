#ifndef PSO_OBJECT_TRAP_TOTRAPSEABED01_H
#define PSO_OBJECT_TRAP_TOTRAPSEABED01_H

#include "types.h"
#include "pso/object/trap/TOTrap.h"

struct TOTrapSeabed01 : public TOTrap {
    TOTrapSeabed01(TObject *parent, void *set_data);
    virtual ~TOTrapSeabed01();
    virtual void apply_saved_state(s16 *, s32);
    virtual void render();
    virtual f32 receive_physical_attack(TObjChara *, f32);
    virtual int deliver_attack_hits(f32 damage_scale);
    virtual void update_springing();
    virtual void update_holding();
    virtual void update_effects();
    virtual void play_sounds();
    void draw_object_tree(NJS_OBJECT *object);
    void render_effect_layers();
    void release_trapped_player();
    void play_floor_sound(s32);
    void check_hold_player();
    void clamp_params_and_init();
    void draw();
    static void *create(void *set_data);
    static void free_static_resources();
    static void load_resources();
    static void trigger_by_id(NJS_OBJECT *node);
    s32 pad_344;
    s32 strike_timer; // name inferred: 30 frames per set param 1; update_holding strikes when it runs out
    s32 projected; // name inferred: set param 2 != 0; draws with the particle TEV and the projection texture
    DirectAttackPayload payload; // name inferred: sent to every player in reach by vfunc_67
    s32 sound_handle; // name inferred: play_sound_effect's result, stopped by apply_saved_state
};

LAYOUT_ASSERT(TOTrapSeabed01_size, sizeof(TOTrapSeabed01) == 0x35C);

// One fragment chip play_sounds throws when the trap breaks: model index,
// position in the trap's frame and the chip's y angle.
struct SeabedTrapFragmentSpawn {
    s32 model;
    Vec pos;
    s32 angle_y;
};

#endif
