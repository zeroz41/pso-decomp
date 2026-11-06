#ifndef PSO_ENEMY_DELDEPTH_TOBJENEDELDEPTH_H
#define PSO_ENEMY_DELDEPTH_TOBJENEDELDEPTH_H

#include "types.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/enemy/TObjEnemy.h"

struct BmlResource;

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
    void *model;
    s32 texture;
    AnimationMotion *animation;
    void *secondModel;
    s32 secondTexture;
    AnimationMotion *secondAnimation;
    f32 speed;
    f32 endFrame;
    f32 frame;
};

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
    void fn_803141A8();
    void fn_803142DC();
    void fn_80314500();
    void fn_80314EC4();
    s32 adjust_height_to_ground();
    void fn_80315518();
    void set_action_state(s32);
    void set_draw_mode(s32);
    void set_depth_offset(s32, s32);
    void sub_803152C0();
    void sub_803152A0();
    virtual void vfunc_63();
    virtual void vfunc_62();
    virtual void vfunc_61();
    s32 action;
    s32 actionPhase;
    DelDepthMotion *motionController;
    CollisionBody *collisionBody;
    s32 timer;
    s32 attackTimer;
    f32 m_38c;
    f32 bombSpeed;
    s32 m_394;
    f32 opacity;
    f32 drawOffsetY;
    Vec drawScale;
    f32 movementSpeed;
    Vec direction;
    s32 m_3bc;
    s32 relocationAttempts;
    s32 targetPlayer;
    u8 unk_3C8[0xC];
    Vec fallVelocity;
    u32 groundFlags;
    Vec groundPoint;
    s32 targetable;
    u8 unknown3F4[0x40];
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
    static void setup_draw_material_default(f32 farg0);
    static void setup_draw_material(f32 farg0, f32 farg1, f32 farg2, f32 farg3);
    static BmlResource *get_data();
    int get_flag_bit4();
    int find_nearest_enemy_with_flag(s32 arg1, f32 farg0);
    void start_attack_motion();
    void enter_appear_state();
    void update_scale_pulse();
    void move_toward_target();
    void start_move_toward_player();
};

typedef char TObjEneDelDepth_size[sizeof(TObjEneDelDepth) == 0x434 ? 1 : -1];
#endif
