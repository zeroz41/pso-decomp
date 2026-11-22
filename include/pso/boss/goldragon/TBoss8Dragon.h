#ifndef PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_H
#define PSO_BOSS_GOLDRAGON_TBOSS8DRAGON_H

#include "types.h"
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/task/TObject.h"
#include "pso/render/RenderFadeState.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/boss/derolle/AccelerationCurve.h"

class AreaAttackHistory;
struct TBoss8DragonEffTail;
class TParticleCtrl;
struct ControllerInputContext;

// The gold dragon (Episode 2's Gol Dragon) boss.
class TBoss8Dragon : public TObjEneDD_ST
{
public:
    TBoss8Dragon(TObject *parent, void *set_data);
    virtual ~TBoss8Dragon();
    virtual void run_task();
    virtual void render();
    virtual void render_shadows();
    // Slot 23: kinds 0xB and 0xC do it no damage; the rest go to TObjChara's.
    virtual f32 receive_direct_attack(void *attacker, DirectAttackPayload payload, void *arg2, s32 arg3, s32 flags);
    virtual void refresh_target();
    // Slots 44-50: the status ailments TObjChara applies; the dragon ignores them.
    virtual void apply_poison_status();
    virtual void apply_paralysis();
    virtual void apply_slow_status();
    virtual void apply_confusion_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_shock_status();
    virtual void clear_harmful_statuses();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    // Slot 87: runs the current action's handler (one per action, handlers[] in the body).
    virtual void dispatch_action(u32 action, s32 event);
    // Slot 88: moves the seven collider bodies to the model's node positions.
    virtual void update_body_colliders();
    // Slots 105 and 106, the two the dragon adds to TObjEneDD_ST's table.
    virtual int run_demo_task();
    virtual void draw_motion_model();

    void get_render_position(u8 *);
    s32 hasActiveRenderFade();
    s32 sub_802F46F4();

    u32 m_3c0;
    TObject sub_tasks;  // the dragon's collider task hangs under it; run_task runs its tasks
    u32 m_3e0;
    u32 m_3e4;
    s32 m_3e8;
    Vec pad_3EC[3];
    Vec m_410;
    Vec m_41c;
    Vec m_428;
    Vec node_positions[0x22];  // the model's node positions; update_body_colliders reads seven
    f32 m_5cc;
    f32 m_5d0;
    f32 m_5d4;
    f32 m_5d8;
    f32 m_5dc;
    Vec m_5e0;
    AccelerationCurve curve0;  // fed to init_acceleration_curve / sample_acceleration_curve
    AccelerationCurve curve1;
    void* m_634;
    u8 _pad638[0x8];
    void* m_640;
    u8 _pad644[0x8];
    u32 m_64c;
    u32 m_650;
    s32 m_654;
    s32 m_658;
    f32 m_65c;
    f32 m_660;
    f32 m_664;
    f32 m_668;
    f32 m_66c;
    f32 m_670;
    u32 m_674;
    u16 m_678;
    u16 m_67a;
    TBoss8DragonEffTail *tail;  // the TBoss8DragonEffTail the constructor creates
    AreaAttackHistory *attack_history;
    TObject *collider;  // the TBoss8DragonColli the constructor hangs under sub_tasks
    f32 m_688;
    f32 m_68c;
    f32 m_690;
    f32 m_694;
    u32 m_698;
    u32 m_69c;
    f32 pad_6A0[12];
    u32 m_6d0;
    u32 m_6d4;
    ControllerInputContext *m_6d8;
    RenderFadeState renderFadeStates[4];
    u32 m_74c;
    u16 m_750;
    u8 _pad752[0x2];
    u32 m_754;
    u32 m_758;
    s32 m_75c;
    const s32 *m_760;
    void* m_764;
    u8 unk_768[0xC];
    saddr m_774;
    u8 unk_778[0xD4];
    s32 m_84c;
    s32 m_850;
    s32 m_854;
    u32 m_858;
    s32 m_85c;
    s32 m_860;
    f32 m_864;
    f32 m_868;
    f32 m_86c;
    f32 m_870;
    f32 m_874;
    f32 m_878;
    f32 m_87c;
    f32 m_880;
    f32 m_884;
    f32 m_888;
    f32 m_88c;
    s32 m_890;
    TParticleCtrl *m_894;
    TParticleCtrl *m_898;
    TParticleCtrl *m_89c;
    s32 m_8a0;
    static void sync_target_pos(void *p);
    static s32 restore_target_pos(void *p);
    static s32 copy_pos_to_field688(void *p);
    void spawn_switch_attack();
    void spawn_attack_effect();
    void run_default_state();
    void update_state_3();
    void set_state_2();
    void attack_default();
    void query_default();
    void copy_action_state(u8 *arg1);
    static s32 spawn_ground_lightning(s32 arg0, saddr arg1, s32 rotation_y);
    static void set_default_on_state0();
    static void update_camera_script(NJS_OBJECT *);
    void calc_velocity_from_angle();
    f32 clamp_step_in_radius(f32 a, f32 b, f32 s);
    void freeze_player_at_self();
    static u16 find_player_on_floor(void *arg0);
    void spawn_ground_effect();
    int setup_instance(int _w1, void * _w2, AreaAttackHistory *history);
    void setup_breath_instance(Vec *pos, u32 kind, AreaAttackHistory *history);
    void emit_effect(void *pos, void *params, AreaAttackHistory *history);
    static void init_state(saddr dragon);
    static int set_state_1(void* p);
    static int check_condition_default(void* p);
    void spawn_effect();
    void play_effect_sound(s32 sound_id);
    f32 calc_step_value();
    s32 check_damage_reaction();
    void pick_next_action();
    void set_speed(s32 arg1);
    void save_position();
    void send_6xA8_action();
    void send_action_packet(int action);
    void apply_ground_movement(Vec *step);
    void draw_beam_segments(f32 a, f32 b, f32 c);
    void copy_pos_to_field688();
    void restore_target_pos();
    void sync_target_pos();
    void release_grabbed_player();
    s32 is_health_low();
    void reset_tail_hp();
    void reload_boss_stats();
    void check_hit_result(s32 arg1, s32 arg2);
    void reset_action();
    void activate_attack();
    void set_active_flag();
    void set_action_state();
    void set_state();
    void reset_timer();
    void play_sound_if_in_band();
    void try_spawn_trap();
    void set_damage_phase_value(s32 arg1);
    static void init_default(void *boss8_dragon);
    s32 is_near_target();
    void calc_orbit_xz(f32 *arg1, f32 *arg2);
    void store_position();
    void set_state_22();
    void check_death();
    void select_next_action();
    static void free_static();
    static void *clone_node_tree(void *src, void *dst, int state);
    static void *create(void *set_data);
    void update_colli_parts();
    void set_field_3c();
    void set_field_1c();
    void spawn_child_object();
    static void free_resources();
    static int get_instance_count();
    void init_color();
    void send_spawn_params_packet();
    void byteswap_action_packet();
    void byteswap_record();
    void send_boss_actions();
    void bswap_boss_actions();
    s32 is_within_xz_distance(u8 *arg1, f32 off);
    f32 calc_sq_offset(f32 farg0);
    void noop();
    static u16 get_global_part_count(s32 arg0);
    void place_parts_in_ring(s32 arg1, s32 arg2);
    static s32 find_target_enemy();
    static s32 is_any_part_alive();
    static void update_all_parts();
    static bool has_enough_enemies();
    s32 spawn_attack_object(saddr arg1, s32 arg2, s32 hp, s32 arg4);
    u16 get_part_count_plus(s32 arg1);
    void set_mode_params(s8 arg1);
    void update_pos_from_data();
    void render_nodes_flagged();
    void copy_vectors();
    void send_swapped_packet();
    void bswap_packet();
    void queue_destruction();
    static void trigger_switches_in_range(void *arg0, void *arg1, void *arg2);
    static s32 calc_binomial_coefficient(s32 n, s32 k);
    void render_body_model();
    void select_freeze_target();
    void emit_body_effects();
    void get_follow_camera_offsets(u8 *arg1);
    s32 is_closest_part();
    s32 push_apart_from_parts();
    s32 is_near_other_part();
    void draw_with_fade(saddr pos, s32 view);
    void draw();

    // Per-action event handlers, run by dispatch_action (vtable slot 87).
    void sub_802F4B90(s32 event);
    void action(s32 event);
    void sub_802F4DD4(s32 event);
    void update_wander_state(s32 event);
    void sub_802F51DC(s32 event);
    void sub_802F5434(s32 event);
    void sub_802F5644(s32 event);
    void sub_802F57E4(s32 event);
    void handle_walk_state(s32 event);
    void sub_802F5BA0(s32 event);
    void sub_802F5CC8(s32 event);
    void sub_802F5F64(s32 event);
    void sub_802F610C(s32 event);
    void sub_802F645C(s32 event);
    void sub_802F6618(s32 event);
    void sub_802F6708(s32 event);
    void sub_802F6838(s32 event);
    void handle_leap_state(s32 event);
    void handle_spiral_state(s32 event);
    void sub_802F75C8(s32 event);
    void action_17(s32 event);
    void sub_802F7B4C(s32 event);
    void sub_802F7808(u32 event, s32 action);
    void sub_802F7B70(s32 event);
    void state_roar(s32 event);
    void sub_802F8150(s32 event);
    void sub_802F8270(s32 event);
    void sub_802F8578(s32 event);
    void sub_802F87EC(s32 event);
    void sub_802F89F8(s32 event);
    void sub_802F8F88(s32 event);
    void state_turn_and_charge(s32 event);
    void sub_802F9850(s32 event);
    void sub_802F9A4C(s32 event);
    void handle_tail_attack_state(s32 event);
    void state_breath_attack(s32 event);
    void sub_802FA16C(s32 event);
    void sub_802FA374(s32 event);
    void sub_802FA478(s32 event);
};

#include <stddef.h>
LAYOUT_ASSERT(TBoss8DragonFadeStride, sizeof(RenderFadeState) == 0x1C);
LAYOUT_ASSERT(TBoss8DragonFadeOffset, offsetof(TBoss8Dragon, renderFadeStates) == 0x6DC);
LAYOUT_ASSERT(TBoss8DragonSize, sizeof(TBoss8Dragon) == 0x8A4);
LAYOUT_ASSERT(TBoss8DragonSubTasksOffset, offsetof(TBoss8Dragon, sub_tasks) == 0x3C4);
LAYOUT_ASSERT(TBoss8DragonAfterFadeOffset, offsetof(TBoss8Dragon, m_74c) == 0x74C);

// boss8_dragon_reference_pos_vec: layout known from its uses only.
struct Boss8DragonReferencePosVec { s32 value; u8 remaining[0x8]; };
extern Boss8DragonReferencePosVec boss8_dragon_reference_pos_vec;
// dragon_forward_reference_vec: layout known from its uses only.
struct DragonForwardReferenceVec { s32 value; u8 remaining[0x8]; };
extern DragonForwardReferenceVec dragon_forward_reference_vec;
// lbl_80541DE8: layout known from its uses only.
struct RecoveredGlobal_lbl_80541DE8 { Vec value; };
extern RecoveredGlobal_lbl_80541DE8 lbl_80541DE8;
// lbl_80541DF4: layout known from its uses only.
struct RecoveredGlobal_lbl_80541DF4 { Vec value; Vec unkC; Vec unk18; };
extern RecoveredGlobal_lbl_80541DF4 lbl_80541DF4;

#endif
