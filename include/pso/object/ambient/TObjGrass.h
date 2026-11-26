#ifndef PSO_OBJECT_AMBIENT_TOBJGRASS_H
#define PSO_OBJECT_AMBIENT_TOBJGRASS_H

#include <stddef.h>
#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/TObjEnemy.h"
#include "pso/render/TObjEnemyColorFade.h"
#include "pso/effect/TAttackTrace.h"

struct NJS_OBJECT;

struct TObjGrass : public TObjEnemy {
    TObjGrass(TObject *parent, void *set_data);
    virtual ~TObjGrass();
    virtual void refresh_target();
    virtual s32 is_target_in_attack_range();
    virtual s32 update_action_hold_status();
    virtual s32 update_movement_status();
    virtual void run_idle_action();
    virtual void run_move_action();
    virtual void run_attack_action();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    void update_move_forward();
    void update_swing_attack();
    void update_charge_attack();
    void update_hit_reaction();
    void update_demo();  // empty; run_task calls it in demo mode
    Vec camera_vec;
    Vec render_vec;
    Vec origin_vec;
    f32 charge_distance;     // how far the charge attack runs (target distance + 30, at least 100)
    s16 move_mode;           // 1 wander near home, 2 chase (parameters[1] > 0), 0 target lost
    s16 attack_kind;         // row of grass_attack_params bound as attack stats; picks run_attack_action's mode
    s32 particle_timer;      // update_dying spawns a particle every 4 frames
    s32 lost_target_frames;  // frames moved without a target; the move ends past 150
    s32 view_detail;
    s32 fading_in;
    TObjEnemyColorFade fade;
    TAttackTraceStrip *savers[2];  // attack traces; same type and role as TObjEneDubchik::saver (inferred name)
    void update_dying();
    static void update_camera_vec_by_stage(NJS_OBJECT *);
    void update();
    void update_web_attack();
    void update_chase_target();
    void update_ai();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
    static void destroy_all();
    static void load_resources();
    void init_from_table_entry(s32 i);
    void clear_hit_targets();
    TObjChara *hit_targets[12];  // players this charge has already hit
};

LAYOUT_ASSERT(TObjGrassFadeOffset, offsetof(TObjGrass, fade) == 0x3B0);
LAYOUT_ASSERT(TObjGrass_size, sizeof(TObjGrass) == 0x404);
#endif
