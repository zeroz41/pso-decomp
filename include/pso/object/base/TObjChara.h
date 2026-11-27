#ifndef PSO_OBJECT_BASE_TOBJCHARA_H
#define PSO_OBJECT_BASE_TOBJCHARA_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/CsnGroundCandidates.h"
#include "pso/system/SubtractiveRng.h"
#include "pso/item/WeaponAttribute.h"
#include "pso/object/base/StatStatusReceipt.h"

struct Vec;
struct player_stats;
struct ActorParamBlock;
struct AttackParams;
struct ControllerInputContext;
struct CsnGroup;
struct CsnHit;

// One row of a character's status effects: 0 poison/paralysis, 1 slow,
// confusion, freeze or shock, 2 the attack stat (Shifta/Jellen), 3 the
// defense stat (Deband/Zalure), 4 an action hold.
struct StatusEffect {
    StatusEffect();
    StatusEffect &operator=(StatusEffect &src);
    void clear();
    void bswap();
    s32 type;
    f32 amount;
    s32 timer;  // frames left
};


struct DirectAttackPayload {
    s32 kind;
    f32 power;
};

class TObjChara : public TObjMotion {
public:
    TObjChara(TObject *parent);
    f32 random_ratio();
    virtual ~TObjChara();
    f32 get_frame();
    s16 get_actor_hp();
    s16 get_hpmax();
    s16 get_actor_tp();
    s16 get_tpmax();
    // The meseta in its stat block.
    s32 get_actor_meseta();
    // Takes `amount` meseta from its stat block; 0 when it holds less.
    s32 try_spend_actor_meseta(s32 amount);
    s32 obj_isState3_324();
    s32 obj_isState2_324();
    // control_state 1: this machine drives it.
    s32 is_locally_controlled();
    // control_state 7: the owner holds a fixed pose its mag aligns to.
    s32 is_in_fixed_pose();
    void calc_attach_pos();
    // move_destination = position, then move_origin and prev_position follow it.
    void init_position_vectors();
    void copy_position();
    void add_flags_2e4(u32);
    // Alive and nothing blocks the line from `from` to its body centre (csnLookAt).
    s32 is_target_unobstructed(const Vec *from);
    s16 get_stats_atp_max();
    s16 get_attack_params_ata();
    f32 get_attack_range();
    s32 get_attack_angle();
    s16 test_immunity_flags(s32);
    void add_immunity_flags(s32 mask);
    void remove_immunity_flags(s32 mask);
    f32 get_status_effect_amount(s32 i);
    s32 get_status_effect_type(s32 i);
    void set_status_effect_timer(s32 i, s32 timer);
    void set_status_effect_type(s32 i, s32 type);
    void set_status_effect_amount(s32 i, f32 amount);
    s32 get_status_effect_timer(s32 i);
    s32 add_status_effect_timer(s32 i, s32 frames);
    s16 get_actor_attack_params_atp_min();
    s32 obj_testFlag_2E4(u32);
    int obj_getPtr2B0_1C();
    // The character's stat block (ATP, MST, EVP, HP, DFP, ATA, LCK first).
    player_stats *get_stats();
    s16 get_base_evp();
    void adjust_evp(int);
    s16 get_base_atp();
    void adjust_atp(int);
    s16 get_base_atp_range();
    void adjust_atp_range(int);
    s16 get_base_dfp();
    void adjust_dfp(int);
    s32 recalc_combat_stats(player_stats *base_stats, AttackParams *attack_stats, ActorParamBlock *resistance_stats, f32 xscale, f32 yscale);
    s32 set_motion_params(player_stats *base_stats);
    void show_miss_popup(const float *);
    void try_apply_damage(const Vec *pos, s32 damage);
    s32 subtract_actor_tp(s32);
    // Spends dmg of its TP (subtract_actor_tp) unless it is in state 2; 0 when it cannot act.
    s32 check_can_act(s32 dmg);
    // Tells the other clients (6x9A) that `target` changed this one's HP,
    // TP or meseta (`which` 0-4) by `amount`.
    void send_update_entity_stat(u16 target, s32 which, s32 amount);
    // Sets attacker_id; a local player's id also becomes local_attacker_id
    // (single screen) or goes to TObjPlayer::add_id_to_slots (split screen).
    void record_attack_source(u16 id);
    // Puts `id` in the first free attack-credit slot unless a slot holds it.
    void add_id_to_slots(u16 id);
    // Takes over `source`'s credit: its slots (split screen) or its local attacker.
    void assign_slots_from_list(TObjChara *source);
    // Subtracts `amount` HP unless it is in state 2.
    s32 damage_hp(s32 amount);
    // Hit sparks at `pos` and its switch attack, unless actor flag 0x02000000 is set.
    void activate_switch_attacks(const Vec *pos);
    void clear_velocity();
    // Records a non-null attacker's entity id as the attack source.
    void attach_mine_trap(TObjBase *attacker);
    u16 get_local_attacker_id();
    void clear_immunity_flags();
    // Status-effect particles at body_center; play_sound adds the cue.
    void spawn_poison_effect(s32 play_sound);
    void spawn_paralysis_feedback_effect(s32 play_sound);
    void spawn_slow_effect(s32 play_sound);
    void spawn_confusion_feedback_effect(s32 play_sound);
    void play_shock_feedback(s32 play_sound);
    s16 clamp_hp();
    void spawn_freeze_shell_effect(CollisionBody *body, s32 play_sound);
    s32 check_heavy_damage_flag(f32);
    virtual s32 add_actor_exp(s32);
    virtual s32 consume_timer_field(s32);
    virtual s32 get_actor_level_index();
    virtual CsnHit *update_actor_ground_y();
    virtual CsnHit *update_actor_ground_y_at(Vec *pos);
    virtual s32 is_actor_cadence_frame(s32);
    virtual s32 select_melee_contact_body(TObjChara *, f32);
    virtual int calc_distance_accuracy_penalty(TObjChara *, CollisionBody *, const Vec *, float);
    virtual f32 receive_physical_attack(TObjChara *, f32);
    virtual f32 receive_direct_attack(TObjBase *, DirectAttackPayload, CollisionBody *, s32, s32);
    virtual f32 receive_weapon_special_attack(TObjChara *, CollisionBody *);
    virtual void apply_knockback_from_attacker(TObjBase *, f32);
    virtual s32 try_start_action(TObjChara *attacker, s32 collider, f32 accuracy);
    virtual s32 roll_physical_accuracy(TObjChara *, s32, f32);
    virtual void refresh_target();
    virtual int has_no_target();
    virtual s32 is_target_in_attack_range();
    virtual int test_flag_256();
    virtual int test_flag30_512();
    virtual int is_actor_dead(); // actor flag 0x800, set just before run_death_reaction
    virtual int test_flag_1000();
    virtual s32 update_poison_status();
    virtual s32 update_action_hold_status();
    virtual s32 update_slow_status();
    virtual s32 update_flag30_timer();
    virtual s32 update_movement_status();
    virtual s32 update_shock_clock();
    virtual s32 update_attack_stat_status();
    virtual s32 update_defense_stat_status();
    virtual s32 update_evp_status();
    virtual void apply_poison_status();
    virtual void apply_paralysis();
    virtual void apply_slow_status();
    virtual void apply_confusion_status();
    virtual void apply_movement_ailment(CollisionBody *body);
    virtual void apply_shock_status();
    virtual void clear_harmful_statuses();
    virtual void apply_attack_stat_status(StatStatusReceipt *receipt);
    virtual void apply_defense_stat_status(StatStatusReceipt *receipt);
    virtual void cure_poison_ailment();
    virtual void cure_paralysis();
    virtual void clear_all_status_effects();
    virtual void apply_action_hold_status(f32);
    virtual void apply_anti_technique(s32);
    virtual void run_idle_action();
    virtual void run_move_action();
    virtual void run_attack_action();
    virtual void run_miss_reaction();
    virtual void run_hit_reaction();
    virtual void run_death_reaction();
    virtual void reset_pose();
    virtual void get_anim_node_position(s32 node, Vec *out);
    virtual u32 vfunc_66(s32 attach_slot);
    virtual int deliver_attack_hits(f32 damage_scale);
    virtual void get_pos(saddr out);
    virtual void apply_switch_attack();
    virtual void enemy_spawn_jellen_effect();
    virtual void trigger_switch_attack();
    void trigger_switch_attack(const Vec *pos);
    virtual void enemy_spawn_zalure_effect();
    // Recomputes the combat stats and clamps HP and TP to their maxima.
    virtual void recalc_stats();
    // Sends an enemy's HP lost and Jellen/Zalure stat drop (status 9-12) to the
    // other clients in a 6x0A packet; a player sends nothing (0).
    virtual s32 sync_enemy_state(s32 status);
    virtual void gain_photon_blast_charge(f32);
    // Spends photon blast charge; TObjPlayer forwards it to subtract_photon_blast_charge (param name inferred).
    virtual void spend_photon_blast_charge(f32 charge);
    virtual void gain_photon_blast_chain_charge(f32 amount);
    virtual void send_status_effect_add(StatStatusReceipt effect);
    void request_box_item_drop(const Vec *position, s32 random_item);
    virtual void *get_center();
    virtual void reset_motion_fields();
    u16 get_attack_credit_slot(s32 index);
    void set_attack_credit_slot(s32 index, u16 id);
    void clear_attack_credit_slot(s32 index);
    void set_model_param(s16 v);
    void set_model_id(s16 v);
    // The union and its byte view are kept: dropping these two anonymous types
    // renumbers the compiler's local statics in every includer.
    union {
        u16 attack_credit_slots[4];
        struct {
            u8 pad_FC[0x8];
        } credit_slot_bytes;
    };
    u8 pad_104[0xC];
    WeaponAttribute attack_attributes[3];  // the equipped weapon's special attributes
    s16 special_kind;  // the special attack it hits with (set_model_id); Epsilon is immune to one kind
    s16 special_power;  // that attack's strength (set_model_param)
    s16 kill_count;  // TObjPlayer::get_kill_count, capped at 999
    s16 immunity_flags;  // test_immunity_flags
    u8 pad_11E[0x2];
    CsnGroundCandidates ground_candidates;  // ground_cache points here
    SubtractiveRng rng;
    Vec ground_normal;
    StatusEffect status_effects[5];
    Vec move_origin;  // where the current move started (calc_velocity_toward_destination's from)
    Vec move_destination;  // where the current move goes
    TObjChara *target;
    s32 move_timer;  // frames spent on the current move; reset when a new destination is picked
    player_stats *stat_block;  // the stat block get_stats returns
    f32 frame_timer;  // frames counted up or down by the current behaviour
    s16 hpmax;
    s16 tpmax;
    s16 hp_bonus;  // what items add to the HP maximum (add_actor_hp_bonus)
    s16 tp_bonus;  // and to the TP maximum
    // Combat stats filled by recalc_combat_stats: base_* are the stat block's
    // values plus the item bonuses, the others the current values after the
    // Shifta/Deband boosts and status effects.
    s16 base_atp;  // stat block ATP
    s16 base_atp_range;  // the attack params' ATP max - min
    s16 base_evp;  // stat block EVP plus the item bonus
    s16 base_dfp;  // the stat block's DFP plus the item bonus
    s16 atp;  // base_atp with Shifta
    s16 atp_range;  // base_atp_range with Shifta
    s16 evp;
    s16 dfp;  // base_dfp with Deband; the guard formulas subtract it from the attacker's ATP
    s16 ata;  // stat block ATA plus the attack params' bonus
    s16 lck;  // stat block LCK
    u16 attacker_id;  // entity id of whoever last hit it; 6x89 sets a player's killer
    u16 local_attacker_id;  // the last local player that hit it (record_attack_source, single screen); distribute_experience awards it
    u16 owner_entity_id;  // entity id of the object that set it (TOMineTrap: the setting player); 0xFFFF none
    u8 pad_2DA[0x2];
    // Bit 1: hit by a ranged attack (calc_distance_accuracy_penalty); bit 2: a
    // Recon whose Recobox died. Cleared with the attack receipts.
    u32 hit_flags;
    u8 pad_2E0[0x4];
    u32 target_attribute_mask;  // 1 native, 2 A.Beast, 4 machine (androids), 8 dark: what a weapon's attribute bonus targets
    s16 element_attack[5];  // added to a physical hit, each scaled by the target's element_resist
    s16 element_resist[5];  // percent of the attacker's element_attack taken away
    Vec body_center;  // position raised to mid-body; effects spawn and distances are measured here
    Vec velocity;
    // The pad driving it in place of its AI; TObjControl::run_task reads the
    // attack button and the stick (inferred).
    ControllerInputContext *controller_input;
    AttackParams *attack_params;
    ActorParamBlock *param_block;  // get_actor_param_block
    s32 mode_mask;  // 1 << mode, kept by set_action_state
    s16 control_state;  // who drives it: 6 a script, 7 a fixed pose
    s16 mode;
    s16 phase;
    s16 prev_mode;  // the mode before the last set_action_state
    s16 hp;
    s16 tp;
    u32 low_game_flags;  // the enemy's status effect bits (actorFlags & 0x3F) the 6x9C packet last sent
};

extern "C" void *__dt__9TObjCharaFv(void *, s16);

LAYOUT_ASSERT(TObjCharaHpMaxOffset, offsetof(TObjChara, hpmax) == 0x2B8);
LAYOUT_ASSERT(TObjCharaTpMaxOffset, offsetof(TObjChara, tpmax) == 0x2BA);
LAYOUT_ASSERT(TObjCharaHpBonusOffset, offsetof(TObjChara, hp_bonus) == 0x2BC);
LAYOUT_ASSERT(TObjCharaTpBonusOffset, offsetof(TObjChara, tp_bonus) == 0x2BE);
LAYOUT_ASSERT(TObjCharaHpOffset, offsetof(TObjChara, hp) == 0x32C);
LAYOUT_ASSERT(TObjCharaBodyCenterOffset, offsetof(TObjChara, body_center) == 0x2FC);
LAYOUT_ASSERT(TObjCharaTpOffset, offsetof(TObjChara, tp) == 0x32E);
LAYOUT_ASSERT(TObjCharaBaseStatsOffset, offsetof(TObjChara, stat_block) == 0x2B0);
LAYOUT_ASSERT(TObjCharaAttackParamsOffset, offsetof(TObjChara, attack_params) == 0x318);
LAYOUT_ASSERT(TObjCharaResistanceParamsOffset, offsetof(TObjChara, param_block) == 0x31C);
LAYOUT_ASSERT(TObjCharaSize, sizeof(TObjChara) == 0x334);
LAYOUT_ASSERT(TObjCharaGroundNormalOffset, offsetof(TObjChara, ground_normal) == 0x248);

LAYOUT_ASSERT(TObjCharaAttackCreditSlotsOffset, offsetof(TObjChara, attack_credit_slots) == 0xFC);

// Advances position through the wall and ground probes.
void move_with_wall_slide(TObjChara *actor);

s32 add_actor_hp(TObjChara *actor, s16 amount);
s32 subtract_actor_hp(TObjChara *actor, s16 amount);
s32 add_actor_tp(TObjChara *actor, s16 amount);
s32 add_actor_hp_bonus(TObjChara *actor, s32 amount);
s32 add_actor_tp_bonus(TObjChara *actor, s32 amount);

void obj_copyVec2_0(u8 *d, u8 *s);
s16 obj_getS16_118(u8 *p);

#endif
