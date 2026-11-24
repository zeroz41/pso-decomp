#ifndef PSO_ENEMY_DELDEPTH_TOBJENEDELDEPTH_H
#define PSO_ENEMY_DELDEPTH_TOBJENEDELDEPTH_H

#include "types.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/enemy/TObjEnemy.h"

struct BmlResource;
struct NJS_TEXLIST;
struct NJS_OBJECT;

struct DelDepthMotion {
    DelDepthMotion(TObjMotion *actor);
    ~DelDepthMotion();
    s32 get_type();
    void draw_model_part();
    void update_animation_frame();
    s32 is_state_complete();
    void set_motion(s32 motion);

    TObjMotion *actor;
    s32 motion;
    NJS_OBJECT *model;
    NJS_TEXLIST *texture;
    AnimationMotion *animation;
    NJS_OBJECT *secondModel;
    NJS_TEXLIST *secondTexture;
    AnimationMotion *secondAnimation;
    f32 speed;
    f32 endFrame;
    f32 frame;
};

LAYOUT_ASSERT(DelDepthMotionSize, sizeof(DelDepthMotion) == 0x2C);
LAYOUT_ASSERT(DelDepthMotionTextureOffset, offsetof(DelDepthMotion, texture) == 0xC);
LAYOUT_ASSERT(DelDepthMotionSecondTextureOffset, offsetof(DelDepthMotion, secondTexture) == 0x18);

struct TObjEneDelDepth : public TObjEnemy {
    TObjEneDelDepth(TObject *, void *);
    static TObjEneDelDepth *create(void *setData);
    virtual ~TObjEneDelDepth();
    typedef void (TObjEneDelDepth::*Action)();
    struct ActionPair { Action enter; Action update; };
    void update_fall_to_ground();
    void enter_fall_to_ground();
    void update_death_fade();
    void enter_attack_cast();
    void update_spin_search(); // action 7: spins until an enemy flagged ahead (500 units) is in line
    void update_look_around(); // action 6: sweeps rotation_y looking for a player within 162.5 units
    void enter_look_around(); // action 6 enter: random sweep angle and turn direction
    void update_surface(); // action 1: grows from flat_scale to full_scale, then attacks or idles
    s32 adjust_height_to_ground();
    void render_in_demo(); // render() in demo mode; empty
    void set_action_state(s32);
    void set_draw_mode(s32);
    void set_depth_offset(s32, s32);
    void set_body_flag(); // collisionBody flag 1, set before each update
    void clear_body_flag_if_untargetable(); // clears it again after the update unless targetable
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    s32 action;
    s32 actionPhase;
    DelDepthMotion *motionController;
    CollisionBody *collisionBody;
    s32 timer;
    s32 attackTimer;
    f32 progress; // surfacing progress 0..1 while appearing or sinking; distance left while moving
    f32 bombSpeed;
    s32 angle;
    f32 opacity;
    f32 drawOffsetY;
    Vec drawScale;
    f32 movementSpeed;
    Vec direction;
    s32 turnSpeed;
    s32 relocationAttempts;
    s32 targetPlayer;
    u8 pad_3c8[0xC];
    Vec fallVelocity;
    u32 groundFlags;
    Vec groundPoint;
    s32 targetable;
    u8 pad_3f4[0x40];
    f32 get_bomb_speed();
    void update_ground_check();
    void init_move();
    void update_ai_state();
    void update_state_flag();
    void init_state();
    void update_attack_cast();
    void update_bomb_drop();
    void init_draw_state();
    void setup_depth_draw();
    void init_depth();
    void try_enter_appear();
    void update_state();
    void enter_state8();
    void update_movement();
    void init_draw_mode_and_motion();
    void init_draw_params();
    void try_relocate_on_timer();
    void init_params();
    void set_default_depth_offset();
    s32 draw_if_visible();
    virtual void render();
    virtual void run_task();
    void update_target_depth();
    void init();
    static void free_shared_data();
    static void load_assets();
    static void reset_globals();
    static void setup_draw_material_default(f32 opacity);
    static void setup_draw_material(f32 opacity, f32 farg1, f32 farg2, f32 farg3);
    static BmlResource *get_data();
    int get_flag_bit4();
    int find_nearest_enemy_with_flag(Vec *direction, f32 range);
    void start_attack_motion();
    void enter_appear_state();
    void update_scale_pulse();
    void move_toward_target();
    void start_move_toward_player();
};

LAYOUT_ASSERT(TObjEneDelDepth_size, sizeof(TObjEneDelDepth) == 0x434);
#endif
