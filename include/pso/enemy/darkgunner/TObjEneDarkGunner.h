#ifndef PSO_ENEMY_DARKGUNNER_TOBJENEDARKGUNNER_H
#define PSO_ENEMY_DARKGUNNER_TOBJENEDARKGUNNER_H
#include "types.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/render/TUnk_80490470.h"

struct BmlResource;

class TObject;
class TParticleCtrl;
class TeneFakeTecThunderEff;

// The record TLobby::dispatch_shared_handler_a(30) returns (TObjEneDarkGunner__behavior_params).
struct TObjEneDarkGunnerBehaviorParams {
    f32 float_params[6]; // get_float_parameter: 0 move speed, 1 move distance, 2 damage limit, 3 dark_gunner_shot_speed
    s32 int_params[4];   // get_int_parameter: 0 attack timer, 1 hide timer, 2 bodies->unk_28 while behavior_flags bit 22, 3 TUnk_804909C4 t.b
};

struct TObjEneDarkGunner : public TObjEnemyCustom {
    TObjEneDarkGunner(TObject *parent, void *set_data);
    virtual ~TObjEneDarkGunner();
    static void *create(void *set_data);
    void update_wait();     // mode 0: wait motion (upside down on the ceiling with behavior_flags bit 16)
    void update_move();     // mode 1: drop, spin and glide (drop/move motions)
    void update_attack();   // mode 2: attack/await/pullback, fires the thunder shots
    void update_state_machine(); // mode 3: wait motion until timer runs out, then start_move
    void update_damage();   // mode 4: damage/duckdame motions
    void update_dying();    // mode 5: die motion, then the death fade
    virtual void run_task();
    virtual void render();
    void set_fields_24_34_from_global(void*);
    void update_hover();    // hover_height bob; shadow_pos and child_offsets from it
    void update_state();    // run_task's mode switch
    int is_death_gunner();  // behavior_flags bit 26, set by become_death_gunner
    void return_home_or_wait(); // mode 8 when over 10 units from home_position, else mode 0
    void start_move();      // mode 1 unless the gunner is down (actorFlags 0x800)
    void start_hide();      // mode 6 unless down or already hiding (behavior_flags bit 23)
    void update_hide_sequence(); // mode 6: duck motion for hide_timer frames, then start_move
    virtual s32 update_movement_status();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    virtual void run_move_action();
    virtual void run_idle_action();
    virtual s32 update_action_hold_status();
    virtual void refresh_target();
    void step_along_ground();
    void update_return_home(); // mode 8: walks back to home_position, then return_home_or_wait
    int is_on_ground();     // actorFlags 0x800000
    void spawn_hamon_effects(s32 type, s32 variant, f32 scale);
    void render_shadow();
    static void cleanup_effects();
    static f32 get_float_parameter(s32 index); // f32 entries of the gunner's behavior params
    static s32 get_int_parameter(s32 index); // its s32 entries, from +0x18
    void load_params();     // dark_gunner_shot_speed from float param 3
    void run_demo_task();
    void clear_state7_flag(); // empty here; the hook TObjEneDubchik::clear_state7_flag fills
    void become_death_gunner(); // the gun center's selected gunner: behavior_flags bit 26, param 0x23
    void become_dark_gunner();  // every other gunner: clears bit 26, param 0x22
    f32 render_y_offset;
    f32 hover_height;  // integrated from hover_speed, clamped to 0..9
    f32 hover_speed;
    s16 spin_count;    // 0x555 turns before the move state
    s16 attack_timer;
    s16 hide_timer;
    s16 pad_39e;
    f32 move_speed;     // fed to enemy_set_heading_velocity, decays each frame
    f32 move_distance;  // sum of move_speed; the move ends past a parameter
    s32 move_heading;
    s32 turn_delay;
    s32 attack_count;
    Vec shadow_pos;  // above position by 5 + hover_height; render_shadow draws here
    Vec child_offsets[4];
    TeneFakeTecThunderEff *children[4];  // the beams update_attack spawns at child_offsets
    TParticleCtrl *trail_emitter;  // particle 0xD9/0xD4 at shadow_pos while behavior_flags & 0x200000
    TParticleCtrl *glow_emitter;   // particle 0xDB at body_center while behavior_flags & 0x800000
    TUnk_80490470 render_control;
    s32 material_phase;
    // bm_ene_darkgunner.bml, loaded with the Dark Gunner's resources.
    static BmlResource *bml_resource;
    u16 center_id;  // entity id of the TObjEneDarkGunCenter that links it
    u8 pad_42a[2];
};
extern "C" const char *TObjEneDarkGunner__class_name;

LAYOUT_ASSERT(DarkGunnerSize, sizeof(TObjEneDarkGunner)==0x42C);
// The shot speed per frame (float param 3, set by load_params); the shot (TUnk_804909C4) moves by it.
extern f32 dark_gunner_shot_speed;

#endif
