#ifndef PSO_ENEMY_TOBJENEPANBARA_H
#define PSO_ENEMY_TOBJENEPANBARA_H
#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/RenderFadeState.h"

class ModelNodePositionCapture;
class TObjEnePanarms;

// One Pan Arms half (0x470 bytes, TObjEnePanarms::create_bara).

class TObjEnePanBARA : public TObjEnemy {
public:
    TObjEnePanBARA(TObject *parent, void *setData, s32 index);
    virtual ~TObjEnePanBARA();
    void set_state(s32 next);
    // Links the half to the body and to the other half (the body's constructor).
    void set_links(TObjEnePanarms *body, TObjEnePanBARA *partner);
    // Death: run_death_reaction enters state 7 (sink), whose update enters state 8 when it ends.
    s32 is_dying();
    int get_state_flag();
    int sub_800DFB74();
    s32 sub_800DFB9C();
    s32 is_dead();
    void do_action_2();
    void sub_800E1D38();
    void sub_800E1D94();
    void sub_800E1E14();
    s32 sub_800E2FB4();
    s32 sub_800E1774();
    s32 is_below_half_hp();
    s32 sub_800E2E68();
    s32 sub_800E2E54();
    s32 check_can_attack();
    s32 is_phase_12();
    virtual void run_task();
    virtual void render();
    // The half's place beside the body (pos) and its facing (rotation, may be NULL).
    void calc_part_position(Vec *pos, s32 *rotation);
    void calc_default_part_position();
    // Moves by delta; when the ground or a wall stops it, retries with delta turned
    // 22.5, -45, 67.5, ... degrees. Nonzero when the half moved.
    s32 try_move_with_detour(Vec *delta);
    virtual void run_death_reaction();
    virtual void run_hit_reaction();
    virtual void run_miss_reaction();
    void set_random_action_timer(int minimum, int range);
    void update_action_timer();
    void init_attack_state();
    void init_open_state();
    void update_move_timer();
    void start_phase3_timer12();
    void start_phase2_timer150();
    void update_attack();
    void init_attack_state2();
    void init_action();
    void update_chase_target();
    void init_state_2();
    void apply_effect_if_flagged();
    void update_hit_state();
    void restore_from_linked_object();
    void init_state_16();
    void update_move_to_target();
    void init_state_1();
    void start_action();
    void handle_split_flag();
    void init_split();
    void snap_to_parent_position();
    void reset_state();
    void spawn_periodic_particle();
    void update_offset_from_parent();
    void reset_split();
    void init_state();
    void update_linked_effect();
    void draw();
    int find_nearest_enemy_with_flag_alt_target(Vec *direction, f32 range);
    void attack_target_player(s32 arg1);
    // The state table's entries that have no name yet.
    void sub_800E10D0();
    void sub_800E0D1C();
    void sub_800E0B9C();
    void sub_800E0A44();
    void sub_800E0950();
    void sub_800E0930();
    void sub_800E092C();
    void sub_800E055C();
    void sub_800E0344();
    void sub_800E0214();
    void sub_800E0048();
    void sub_800DFE08();
    s32 prev_state; // the state before the last set_state
    s32 state; // index into the TU's {enter, update} state table (set_state)
    CollisionBody *collision_body_parts; // init_collision_body_parts / free_collision_body_parts
    s32 half_index; // create_bara's index: picks the half's model, motions and tables
    s32 m_384;
    s32 m_388;
    Vec m_38c;
    s32 m_398;
    TObjEnePanarms *body;
    TObjEnePanBARA *partner; // the other half
    u8 unk_3A4[0x4];
    f32 m_3a8;
    u8 unk_3AC[0x4];
    f32 m_3b0;
    s32 action_timer;
    s32 target_id; // entity id of the attack target (find_entity_by_id)
    s32 split_hp; // hp the half starts with when the body splits
    s32 unk_3C0;
    s32 m_3c4;
    Vec pad_3c8;
    s32 m_3d4;
    f32 pad_3d8;
    ModelNodePositionCapture *m_3dc;
    Vec draw_callback_position;
    RenderFadeState fades[4]; // one per camera (render)
    s32 m_45c;
    f32 pad_460;
    f32 m_464;
    f32 pad_468;
    f32 m_46c;
};

#endif
