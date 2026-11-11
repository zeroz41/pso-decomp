#ifndef PSO_BOSS_DARKFALZ_TBOSS4TYPE3_H
#define PSO_BOSS_DARKFALZ_TBOSS4TYPE3_H

#include "types.h"
#include "pso/unk/ModelNodeTables.h"
#include <stddef.h>
#include "pso/enemy/TObjEnemy.h"

struct TBoss4Type3CollisionState {
    u8 unknown00[0x18]; u32 flags;
    u8 unknown1c[0xC]; f32 radius;
};

struct TBoss4Type3 : public TObjEnemy {
    virtual ~TBoss4Type3();
    virtual void vfunc_62();
    virtual void vfunc_63();
    void reset_action_to_3(void *);
    void init_effect(void *);
    void sub_8005A438();
    void update_scale_sound();
    void update_radar_markers();
    void handle_damage_taken();
    void update_target_effect_timer();
    void request_follow_camera_default_offsets();
    virtual void clear_harmful_statuses();
    virtual void apply_shock_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_confusion_status();
    virtual void apply_slow_status();
    virtual void apply_paralysis();
    virtual void apply_poison_status();
    s32 m_374;
    ModelNodeTables node_tables;
    u32 m_38c;
    s32 m_390;
    TBoss4Type3CollisionState *m_394;
    s32 m_398;
    f32 m_39c;
    s32 m_3a0;
    u32 m_3a4;
    u32 m_3a8;
    u32 m_3ac;
    f32 m_3b0;
    u32 m_3b4;
    u16 m_3b8;
    u16 m_3ba;
    u32 m_3bc;
    u8 _pad3C0[0x4];
    u32 m_3c4;
    f32 m_3c8;
    s32 m_3cc;
    s32 m_3d0;
    s32 m_3d4;
    u32 m_3d8;
    f32 m_3dc;
    u32 m_3e0;
    u32 m_3e4;
    f32 m_3e8;
    f32 m_3ec;
    s32 m_3f0;
    f32 m_3f4;
    u8 _pad3F8[4];
    u32 m_3fc;
    u8 _pad400[4];
    void *effect_parts[13];
    void *render_lists[3];
    u8 _pad444[0xC];
    void* m_450;
    u8 _pad454[0x8];
    void* m_45c;
    u8 _pad460[0x14];
    void* m_474;
    u8 _pad478[0xA4];
    u32 m_51c;
    u32 m_520;
    u32 m_524;
    u32 m_528;
    u32 m_52c;

    void update_libera();
    void advance_libera();
    void enter_libera();
    void update_bura();
    void advance_bura();
    void enter_bura();
    void update_capture();
    void advance_capture();
    void enter_capture();
    void update_dark_magic();
    void advance_dark_magic();
    void enter_dark_magic();
    void update_light_magic();
    void advance_light_magic();
    void enter_light_magic();
    void update_homing();
    void advance_homing();
    void enter_homing();
    void update_go_down();
    void advance_go_down();
    void enter_go_down();
    void update_go_up();
    void advance_go_up();
    void enter_go_up();
    void update_cut();
    void advance_cut();
    void enter_cut();
    void update_dead();
    void advance_dead();
    void enter_dead();
    void advance_wait_next();
    void update_appear();
    void advance_appear();
    void enter_appear();

    void draw_model_set(const s32 *models, f32 weight);

    void run_task();

    void calc_grid_index();
    void turn_toward_player(s32 arg1);
    static s32 get_random_scaled(void * _w0);
    s32 choose_attack_heading_sector();
    void interp_position_between_nodes();
    void spawn_random_effect();
    void send_packed_action(s32 arg1, s32 arg2, s32 arg3);
    void destroy_parts();
    void create_particle_emitters();
    void set_action_from_table(s32 arg1);
    void copy_pair(void* q);
    void set_anim_state(s32 arg1);
    void draw();
    static s32 create(s32 arg0);
    static void *create_yutai(void *arg0, void *arg1, void *arg2);
    static f32 compute_wave_offset(f32 farg0);
    static u16 pick_random_target_player();
    static void *create_horming(void *arg0, void *arg1, void *arg2);
    void copy_positions_to_parts();
    void update_phase_timer();
    void advance_afterimage();
};

typedef void (TBoss4Type3::*TBoss4Type3Handler)();
struct TBoss4Type3State {
    const char *name;
    s32 animation;
    TBoss4Type3Handler enter;
    TBoss4Type3Handler advance;
    TBoss4Type3Handler update;
};
typedef char Type3StateSize[(sizeof(TBoss4Type3State)==0x2C)?1:-1];
typedef char Type3StateEnter[(offsetof(TBoss4Type3State,enter)==0x8)?1:-1];
typedef char Type3StateAdvance[(offsetof(TBoss4Type3State,advance)==0x14)?1:-1];
typedef char Type3StateUpdate[(offsetof(TBoss4Type3State,update)==0x20)?1:-1];
typedef char Type3TimerOffset[(offsetof(TBoss4Type3,m_398)==0x398)?1:-1];
typedef char Type3FractionOffset[(offsetof(TBoss4Type3,m_39c)==0x39C)?1:-1];

typedef char Type3Offset_374[(offsetof(TBoss4Type3,m_374) == 0x374)?1:-1];
typedef char Type3Offset_378[(offsetof(TBoss4Type3,node_tables) == 0x378)?1:-1];
typedef char Type3Offset_38c[(offsetof(TBoss4Type3,m_38c) == 0x38c)?1:-1];
typedef char Type3Offset_390[(offsetof(TBoss4Type3,m_390) == 0x390)?1:-1];
typedef char Type3Offset_394[(offsetof(TBoss4Type3,m_394) == 0x394)?1:-1];
typedef char Type3Offset_3a0[(offsetof(TBoss4Type3,m_3a0) == 0x3a0)?1:-1];
typedef char Type3Offset_3b0[(offsetof(TBoss4Type3,m_3b0) == 0x3b0)?1:-1];
typedef char Type3Offset_3b8[(offsetof(TBoss4Type3,m_3b8) == 0x3b8)?1:-1];
typedef char Type3Offset_3ba[(offsetof(TBoss4Type3,m_3ba) == 0x3ba)?1:-1];
typedef char Type3Offset_3c8[(offsetof(TBoss4Type3,m_3c8) == 0x3c8)?1:-1];
typedef char Type3Offset_3cc[(offsetof(TBoss4Type3,m_3cc) == 0x3cc)?1:-1];
typedef char Type3Offset_3d0[(offsetof(TBoss4Type3,m_3d0) == 0x3d0)?1:-1];
typedef char Type3Offset_3d4[(offsetof(TBoss4Type3,m_3d4) == 0x3d4)?1:-1];
typedef char Type3Offset_3dc[(offsetof(TBoss4Type3,m_3dc) == 0x3dc)?1:-1];
typedef char Type3Offset_3e8[(offsetof(TBoss4Type3,m_3e8) == 0x3e8)?1:-1];
typedef char Type3Offset_3ec[(offsetof(TBoss4Type3,m_3ec) == 0x3ec)?1:-1];
typedef char Type3Offset_3f0[(offsetof(TBoss4Type3,m_3f0) == 0x3f0)?1:-1];
typedef char Type3Offset_3f4[(offsetof(TBoss4Type3,m_3f4) == 0x3f4)?1:-1];
typedef char Type3Offset_418[(offsetof(TBoss4Type3,effect_parts) + 5 * sizeof(void *) == 0x418)?1:-1];
typedef char Type3Offset_41c[(offsetof(TBoss4Type3,effect_parts) + 6 * sizeof(void *) == 0x41c)?1:-1];
typedef char Type3Size[(sizeof(TBoss4Type3)==0x530)?1:-1];

#endif
