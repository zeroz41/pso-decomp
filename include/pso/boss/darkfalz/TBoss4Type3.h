#ifndef PSO_BOSS_DARKFALZ_TBOSS4TYPE3_H
#define PSO_BOSS_DARKFALZ_TBOSS4TYPE3_H

#include "types.h"

struct BmlResource;
struct TBoss4FormSetData;
#include "pso/unk/ModelNodeTables.h"
#include <stddef.h>
#include "pso/enemy/TObjEnemy.h"

class ModelNodePositionCapture;

struct TObjDFHorming;
class TObjDFYutai;

struct SampledMotionPoints;
class TParticleCtrl;
class TAttackTraceStrip;
struct CollisionBody;
struct TBoss4DarkFalz;

// Dark Falz's third form. Field names are inferred from their uses in TBoss4Type3.cpp.
struct TBoss4Type3 : public TObjEnemy {
    TBoss4Type3(TObject *parent, TBoss4FormSetData *set_data);
    virtual ~TBoss4Type3();
    virtual void render();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    void reset_action_to_3(void *);
    void init_effect(void *);
    void draw_faded_models();
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
    s32 state;                  // row of boss4_type3_states
    ModelNodeTables node_tables;
    TBoss4DarkFalz *owner;      // relays the packed actions (send_code_25_4)
    BmlResource *archive;
    CollisionBody *collision;
    s32 state_timer;
    f32 move_ratio;             // 0 at prev_node, 1 at node
    s32 node;                   // 0-15 a ring position, 16 the centre, 17 above it
    s32 prev_node;
    s32 heading;                // in sixteenths of a turn
    s32 prev_heading;
    f32 fade;                   // 1 shown, 0 hidden
    s32 fade_timer;
    u16 capture_target;         // client id it reaches for, 0xFFFF for none
    u16 captured_player;        // client id it holds, 0xFFFF for none
    s32 move_count;
    s32 radar_frame;
    u32 radar_color;
    f32 captured_fade;          // draw_player_model_by_id's fade for the held player
    s32 radius_shown;
    s32 radius_hidden;
    s32 prev_hp;
    s32 rumble_timer;
    f32 texture_scroll;
    s32 capture_hp;             // at or below this hp it captures a player
    s32 drained_hp;             // hp the held player was last drained at
    f32 hit_flash;
    f32 hp_ratio;
    s32 anim;                   // row of TBoss4Type3__anim_state_table
    f32 anim_frame;
    f32 anim_speed;
    s32 anim_looped;
    s32 anim_mode;
    TParticleCtrl *effect_parts[13];
    ModelNodePositionCapture *render_lists[3];
    Vec node_positions[3][6];   // render_lists' captured node positions
    SampledMotionPoints *trail_samples[2];
    TAttackTraceStrip *trails[2];
    s32 camera_mode;            // 1 for the close follow camera

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
    void send_random_action(s32 lo, s32 hi);
    void turn_toward_player(s32 id);
    s32 get_random_scaled();
    s32 choose_attack_heading_sector();
    void interp_position_between_nodes();
    void apply_packed_state(u32 packed);
    void spawn_random_effect();
    void send_attack_code(s32 action, u16 target);
    void send_packed_action(s32 action, s32 next_node, s32 next_heading);
    void send_action(s32 action);
    void release_state_effects();
    void destroy_parts();
    void create_particle_emitters();
    void set_action_from_table(s32 action);
    void copy_pair(void* q);
    void set_anim_state(s32 index);
    void draw();
    static TBoss4Type3 *create(TBoss4FormSetData *set_data);
    s32 get_action_state();
    void get_defeat_params(u16 *a, u16 *b, u16 *out);
    static TObjDFYutai *create_yutai(TObject *parent, s32 kind, u16 player_id);
    static f32 compute_wave_offset(f32 wave);
    static u16 pick_random_target_player();
    static TObjDFHorming *create_horming(TObject *parent, const Vec *position, u16 target_id);
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
LAYOUT_ASSERT(Type3StateSize, sizeof(TBoss4Type3State)==0x2C);
LAYOUT_ASSERT(Type3StateEnter, offsetof(TBoss4Type3State,enter)==0x8);
LAYOUT_ASSERT(Type3StateAdvance, offsetof(TBoss4Type3State,advance)==0x14);
LAYOUT_ASSERT(Type3StateUpdate, offsetof(TBoss4Type3State,update)==0x20);
LAYOUT_ASSERT(Type3Offset_374, (offsetof(TBoss4Type3,state) == 0x374));
LAYOUT_ASSERT(Type3Offset_38c, (offsetof(TBoss4Type3,owner) == 0x38c));
LAYOUT_ASSERT(Type3Offset_398, (offsetof(TBoss4Type3,state_timer) == 0x398));
LAYOUT_ASSERT(Type3Offset_3b8, (offsetof(TBoss4Type3,capture_target) == 0x3b8));
LAYOUT_ASSERT(Type3Offset_3c0, (offsetof(TBoss4Type3,radar_frame) == 0x3c0));
LAYOUT_ASSERT(Type3Offset_3f0, (offsetof(TBoss4Type3,anim) == 0x3f0));
LAYOUT_ASSERT(Type3Offset_400, (offsetof(TBoss4Type3,anim_mode) == 0x400));
LAYOUT_ASSERT(Type3Offset_404, (offsetof(TBoss4Type3,effect_parts) == 0x404));
LAYOUT_ASSERT(Type3Offset_444, (offsetof(TBoss4Type3,node_positions) == 0x444));
LAYOUT_ASSERT(Type3Offset_51c, (offsetof(TBoss4Type3,trail_samples) == 0x51c));
LAYOUT_ASSERT(Type3Size, (sizeof(TBoss4Type3)==0x530));

#endif
