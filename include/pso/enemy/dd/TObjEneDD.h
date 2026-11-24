#ifndef PSO_ENEMY_DD_TOBJENEDD_H
#define PSO_ENEMY_DD_TOBJENEDD_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

struct CsnHit;
struct DragonAttackParams;
class AreaAttackHistory;
class TObjEneDD_ST;

struct TObjEneDD : public TObjEnemy {
    TObjEneDD(TObject *parent);
    virtual ~TObjEneDD();
    void set_part_local_pos(void *, s32);
    static void set_part_position(void *actor, void *v, int i);
    void transition_enemy_state(s32);
    void sub_800BBA0C();
    void invoke_initialization_hook(void *set_data);
    void reset_state_fields();
    void init_common_from(TObjBase *source);
    void clear_attack_receipts();
    virtual void apply_enemy_state(s32 *);
    virtual s32 update_status_effects();
    virtual s32 update_immobilizing_statuses();
    virtual void update_action_state();
    virtual s32 has_action_state_changed();
    virtual void dispatch_action(u32 state, s32 reason) = 0;
    virtual void update_body_colliders();
    virtual void check_collisions();
    virtual s32 vfunc_90();
    virtual void set_invulnerable();
    virtual void clear_invulnerable();
    virtual void enable_body_collision();
    virtual void disable_body_collision();
    virtual void set_intangible();
    virtual void clear_intangible();
    virtual void set_colliders_contact_high();
    virtual void set_colliders_contact_low();
    virtual s32 is_confused();
    virtual void render_minimap_dot();
    virtual CsnHit *move_xz_on_ground(const Vec *);
    virtual CsnHit *update_ground_contact();
    virtual CsnHit *snap_to_ground_at(u8 *dest);
    // The table ends at slot 103 (the word after it is padding): dispatch_action's state handlers
    // start at slot 104 and each subclass declares its own (TObjEneDD_ST f32, TBoss2Mine s32, FlyNest init).
    int get_flag_b4();
    f32 calc_elapsed_scaled();
    static void init_lights();
    static s32 clamp_frame_index(s32 frame);
    static s32 check_v2_mode();
    int get_target_state_a();
    int get_target_state_b();
    static int query_teammate_state();
    int update_lobby_state();
    static s32 is_phase_e();
    static s32 is_main_phase_15();
    static void clear_global_flag_400();
    void draw_ground_shadow(const Vec *scale, s32 forceDraw);
    static void draw_oriented_shadow(const Vec *position, const Vec *normal, saddr angle, const Vec *scale);
    void update_primary_light();
    void update_secondary_light();
    void reload_stats_keep_hp_tp(player_stats *base_stats, AttackParams *attack_stats, ActorParamBlock *resistance_stats);
    void reset_hp(player_stats *base_stats, AttackParams *attack_stats, ActorParamBlock *resistance_stats);
    void initialize_enemy_state(s32 parameter);
    s32 get_random_scaled();
    f32 rand_range(f32 low, f32 high);
    void set_state_8();
    void set_state_flag_4();
    void set_state_flag_2();
    void set_state_flag_1();
    static void send_damage_message(TObjChara *attacker, TObjChara *target);
    static void inflict_poison(TObjChara *attacker, TObjChara *target);
    void emit_effect_at_position(const DragonAttackParams *params);
    static void emit_effect(TObjBase *owner, const Vec *pos, const DragonAttackParams *params);
    static void emit_enemy_effect(TObjBase *owner, const Vec *pos, const DragonAttackParams *params, AreaAttackHistory *attack_history);
    // Fires the shared DD hitbox (obj_ene_dd_instance) at pos for owner with the given attack.
    static void setup(TObjBase *owner, Vec *pos, DragonAttackParams *params);
    static void setup_instance(TObjBase *owner, Vec *pos, DragonAttackParams *params, AreaAttackHistory *attack_history);
    s32 is_valid_target();
    void transform_part_positions();
    void init_model(CollisionBody *bodies, s32 count);
    void clear_field_388();
    int has_move_failures(s32 limit);
    CsnHit *enemy_probe_wall_ahead(f32 dx, f32 dz, f32 dist);
    void calc_shot_position(Vec *, f32, f32, f32);
    CsnHit *try_move_actor_xz_on_ground(const Vec *);
    void move_to_wall_clamped_destination(f32 dx, f32 dz, f32 dist);
    CsnHit *move_with_wall_slide_commit(f32 dx, f32 dz, f32 dist);
    void move_with_wall_stop(f32 dx, f32 dz, f32 dist);
    void move_clamped_on_ground(f32 dx, f32 dz, f32 dist);
    void move_with_wall_slide_on_ground(f32 dx, f32 dz, f32 dist);
    void move_to_shot_position(f32 dx, f32 dz, f32 dist);
    // Fills enemy_target_candidate_table for actor; returns how many it found.
    static s32 collect_target_candidates(TObjEneDD *actor, f32 range);
    static void create_instance();
    static int get_enemy_count();
    int get_target_info();
    void set_field_378(s32 v);
    void init_position_vectors();
    static void release_resource();

    s32 previous_mode;         // mode when the last state handler finished; vfunc_86 tests for a change
    s32 next_mode;             // mode a finished action hands back to (transition_enemy_state(next_mode))
    f32 wall_reach;            // extra distance the wall probe looks ahead of a move (5.0)
    s32 wall_probe_failures;   // moves the wall probe blocked in a row
    s32 ground_probe_failures; // moves that found no ground in a row
    s32 active_flags;          // bit 0 set by TObjEneDD_ST::set_active
};

// One entry collect_enemy_target_candidates fills: a player's entity id and
// its horizontal squared distance from the actor.
struct TargetCandidate {
    u16 id;
    f32 dist;
};

// Where a move of dist along (dx, dz) from self ends, stopped wall_reach
// short of a wall the probe hits.
void calc_wall_clamped_destination(TObjEneDD *self, Vec *dest, f32 dx, f32 dz, f32 dist);
void calc_wall_slide_destination(TObjEneDD *self, Vec *out, f32 dx, f32 dz, f32 dist);

extern "C" {
extern TargetCandidate enemy_target_candidate_table[4];
// Copies world points into the actor's collision body centers and stores
// them, moved into the actor's frame, in the bodies' offsets.
void update_local_colliders_from_world(TObjEneDD *self, Vec *world_points);
// The living players within range (squared, all when range <= 0) of self,
// nearest first; returns how many it wrote to out.
s32 collect_enemy_target_candidates(TObjEneDD *self, TargetCandidate *out, f32 range);
void forward_split_screen_view_matrix();
void forward_transform_to_view(const Vec *in, Vec *out);
s32 is_target_unobstructed_from(TObjEneDD *self, TObjChara *target);
u16 enemy_nearest_visible_enemy(void *self, f32 range);
u16 enemy_find_nearest_player_in_range(TObjChara *self, f32 range);
s32 is_player_entity_id(u16 id);
// 1 for an enemy's entity id (0x1000-0x3FFF).
int is_enemy_entity_id(u16 id);
s32 pack_debug_text_position(s32 x, s32 y);
void project_sound_origin_from_camera(const Vec *source, Vec *out, f32 distance);
void TObjEneDD__sub_800BA378(TObjChara *attacker, TObjChara *target);
void TObjEneDD__sub_800BA438(TObjChara *attacker, TObjChara *target);
void TObjEneDD__sub_800BA5A4(TObjBase *owner, DragonAttackParams *params);
int is_target_android(void *p);
int is_target_ranger(void *p);
void TBoss8Dragon__sub_800BB650(TargetCandidate *dst, TargetCandidate *src);
void TBoss8Dragon__sub_800BB7D4(void *self, int id);
CsnHit *TObjEneEpsilon__sub_800B92AC(TObjEneDD_ST *self, s32 max_step, f32 distance);
CsnHit *TObjEneEpsilon__sub_800B92F8(TObjEneDD_ST *self, s32 max_step, f32 distance);
CsnHit *TObjEneEpsilon__sub_800B9384(TObjEneDD_ST *self, s32 iscale, f32 scale);
void TBoss8Dragon__sub_800BB7D8(void *self, s32 id, f32 scale);
void TBoss8Dragon__sub_800BB7DC(void *self);
}
CsnHit *enemy_turn_and_move_on_ground(TObjEneDD_ST *self, s32 max_step, f32 currentSpeed);

void set_collider_contact_high(CollisionBody *body);
void set_collider_contact_low(CollisionBody *body);
void update_collider_contact_by_height(CollisionBody *body, f32 height);
u16 enemy_nearest_visible_player_sq(TObjChara *self, f32 range);
s32 tick_period_counter(s32 self, s32 *counter, s32 limit);

// The far (310) and near (155) depths the enemies' render() hands classify_actor_view_detail.
extern const f32 view_detail_far_depth;
extern const f32 view_detail_near_depth;

#endif
