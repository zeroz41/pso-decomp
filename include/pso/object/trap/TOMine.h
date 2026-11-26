#ifndef PSO_OBJECT_TRAP_TOMINE_H
#define PSO_OBJECT_TRAP_TOMINE_H

#include <stddef.h>
#include "types.h"
#include "pso/object/base/TObjChara.h"
#include "pso/system/NinjaTypes.h"

struct NJS_TEXLIST;
struct NJS_OBJECT;

struct TOMine : public TObjChara {
    TOMine(TObject *parent);
    virtual ~TOMine();
    virtual f32 receive_weapon_special_attack(void *, void *);
    void detonate();
    void update_float_height();
    void sync_position();
    // Calls sync_position (name inferred).
    void apply_float_position();
    void trigger_group();
    void follow_target();
    void update_trigger();
    void play_trigger_effects();
    void update_state();
    s32 is_target_in_list(void *);
    virtual void vfunc_79();
    virtual void play_trigger_sound();
    virtual void play_effect_sound();
    virtual void spawn_blast_particle();
    virtual void spawn_disp_objects();
    virtual void vfunc_84();
    virtual void vfunc_85();
    virtual void set_armed();
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual void apply_saved_state(s16 *, s32);
    virtual f32 receive_physical_attack(void *, f32);
    virtual s32 select_melee_contact_body(void *, f32);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual const char *get_name();
    virtual void apply_object_set_data(void *);
    virtual void apply_knockback_from_attacker(u8 *, f32);
    virtual s32 try_start_action(void *, s32, f32);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    Vec float_position; // copied from position on spawn; y bobs in update_float_height
    u32 float_flags;  // bit 2: it has reached its float height
    s32 behavior;  // 0 stays put, 1 triggered with its group, 2 follows its target (from scale.z)
    s32 group_id;  // scale.z: mines of one group are triggered together (behavior 1)
    f32 detect_radius;              // inferred: detection radius (find_target_in_range squares it)
    f32 trigger_radius;                // trigger radius (squared against horizontal_distance_squared)
    DirectAttackPayload attack; // passed by value to receive_direct_attack
    u16 target_id;
    u8 pad_35E[0x2];
    NJS_ARGB color;           // the constant material colour render draws it with
    u32 facing;
    NJS_OBJECT *light_model;
    NJS_TEXLIST *light_textures;
    // Offers this mine to player `client`'s lock-on cursor.
    void submit_cursor_target(s32 client);
    int find_target_player();
    virtual void run_task();
    void free_sub_objects();
    void free_parts();
    virtual void render();
    static void free_instance();
    static void load_static_resource();
};

LAYOUT_ASSERT(TOMine_size, sizeof(TOMine) == 0x37C);
LAYOUT_ASSERT(TOMineLightModelOffset, offsetof(TOMine, light_model) == 0x374);
LAYOUT_ASSERT(TOMineLightTexturesOffset, offsetof(TOMine, light_textures) == 0x378);

struct BmlResource;
// bm_o_mine.bml, loaded by TOMine::load_static_resource; the mine models of every TOMine class.
extern BmlResource *mine_model_archive;
// The one collision sphere TOMineTrap and the four TOMineIcon constructors install.
extern CollisionBody mine_collision_body_parts[1];
struct game_command_header;

void handle_6x80_trigger_trap(game_command_header *command);
void set_mine_trap_damage(f32 farg0);

#endif
