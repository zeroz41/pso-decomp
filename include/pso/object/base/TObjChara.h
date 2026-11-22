#ifndef PSO_OBJECT_BASE_TOBJCHARA_H
#define PSO_OBJECT_BASE_TOBJCHARA_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct Vec;
struct ActorParamBlock;
struct ControllerInputContext;

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
    s32 obj_isState3_324();
    s32 obj_isState2_324();
    // control_state 7: the owner holds a fixed pose its mag aligns to.
    s32 is_in_fixed_pose();
    void calc_attach_pos();
    // move_destination = position, then move_origin and prev_position follow it.
    void init_position_vectors();
    void add_flags_2e4(u32);
    s16 get_stats_atp_max();
    s16 sub_800194C4();
    f32 get_attack_range();
    s32 get_attack_angle();
    s16 test_immunity_flags(s32);
    s16 get_actor_attack_params_atp_min();
    s32 obj_testFlag_2E4(u32);
    int obj_getPtr2B0_1C();
    // The character's stat block (ATP, MST, EVP, HP, DFP, ATA, LCK first).
    u8 *get_stats();
    s16 get_base_evp();
    void adjust_evp(int);
    s16 get_base_atp();
    void adjust_atp(int);
    s16 get_base_atp_range();
    void adjust_atp_range(int);
    s16 get_base_dfp();
    void adjust_dfp(int);
    s32 recalc_combat_stats(void *, void *, void *, f32, f32);
    s32 set_motion_params(void *);
    void show_miss_popup(const float *);
    void try_apply_damage(const Vec *pos, s32 damage);
    s32 subtract_actor_tp(s32);
    void sub_80010DE8(u16, u8, u8);
    s16 clamp_hp();
    void spawn_freeze_shell_effect(u32, s32);
    s32 check_heavy_damage_flag(f32);
    virtual s32 add_actor_exp(s32);
    virtual s32 consume_timer_field(s32);
    virtual s32 get_actor_level_index();
    virtual u8 *update_actor_ground_y();
    virtual u8 *update_actor_ground_y_at(Vec *pos);
    virtual s32 is_actor_cadence_frame(s32);
    virtual s32 select_melee_contact_body(void *, f32);
    virtual int calc_distance_accuracy_penalty(void *, void *, void *, float);
    virtual f32 receive_physical_attack(void *, f32);
    virtual f32 receive_direct_attack(void *, DirectAttackPayload, void *, s32, s32);
    virtual f32 receive_weapon_special_attack(void *, void *);
    virtual void apply_knockback_from_attacker(u8 *, f32);
    virtual s32 try_start_action(s32 attacker, s32 collider);
    virtual s32 roll_physical_accuracy(void *, s32, f32);
    virtual void refresh_target();
    virtual int has_no_target();
    virtual s32 is_target_in_attack_range();
    virtual int test_flag_256();
    virtual int test_flag30_512();
    virtual int has_flag_0x800();
    virtual int test_flag_1000();
    virtual s32 update_poison_status();
    virtual s32 update_action_hold_status();
    virtual s32 update_slow_status();
    virtual s32 update_flag30_timer();
    virtual s32 update_movement_status();
    virtual s32 update_shock_clock();
    virtual s32 update_attack_stat_status();
    virtual s32 update_defense_stat_status();
    virtual s32 vfunc_43();
    virtual void apply_poison_status();
    virtual void apply_paralysis();
    virtual void apply_slow_status();
    virtual void apply_confusion_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_shock_status();
    virtual void clear_harmful_statuses();
    virtual void apply_attack_stat_status(void *);
    virtual void apply_defense_stat_status(void *);
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
    virtual int vfunc_66();
    virtual int deliver_attack_hits(f32 damage_scale);
    virtual void get_pos(saddr out);
    virtual void apply_switch_attack();
    virtual void enemy_spawn_jellen_effect();
    virtual void trigger_switch_attack();
    void trigger_switch_attack(const Vec *pos);
    virtual void enemy_spawn_zalure_effect();
    // Recomputes the combat stats and clamps HP and TP to their maxima.
    virtual void recalc_stats();
    virtual s32 vfunc_74(s32);
    virtual void gain_photon_blast_charge(f32);
    // Spends photon blast charge; TObjPlayer forwards it to subtract_photon_blast_charge (param name inferred).
    virtual void spend_photon_blast_charge(f32 charge);
    virtual void gain_photon_blast_chain_charge();
    virtual void vfunc_78(saddr);
    void request_box_item_drop(const Vec *position, s32 random_item);
    virtual void *get_center();
    virtual void reset_motion_fields();
    int m_fc;
    u8 unk_100[0x3];
    u8 m_103;
    void* m_104;
    s32 m_108;
    u8 unk_10C[0xA];
    s16 m_116;
    u8 unk_118[0x2];
    s16 m_11a;
    s16 m_11c;
    u8 unk_11E[0x1];
    u8 m_11f;
    void* m_120;
    u8 unk_124[0x4];
    void * m_128;
    u8 unk_12C[0xF];
    u8 m_13b;
    u8 unk_13C[0x14];
    f32 m_150;
    u8 unk_154[0x3];
    u8 m_157;
    u8 unk_158[0x18];
    s32 m_170;
    u8 unk_174[0x10];
    s32 m_184;
    u8 unk_188[0x7];
    u8 m_18f;
    u8 unk_190[0x8];
    s16 m_198;
    u8 unk_19A[0x11];
    u8 m_1ab;
    u8 unk_1AC[0xC];
    u32 m_1b8;
    u8 unk_1BC[0x4];
    s32 m_1c0;
    TObject *unk_1C4;
    int m_1c8;
    u8 unk_1CC[0x2];
    s16 m_1ce;
    u8 unk_1D0[0x2];
    u8 m_1d2;
    u8 unk_1D3[0x11];
    float m_1e4;
    u8 unk_1E8[0x4];
    s32 * m_1ec;
    u8 unk_1F0[0x4];
    s32 * m_1f4;
    u8 unk_1F8[0x4];
    s32 m_1fc;
    u8 unk_200[0x4];
    s32 m_204;
    u8 unk_208[0x4];
    s32 m_20c;
    u8 unk_210[0x4];
    s32 m_214;
    u8 unk_218[0x4];
    s32 m_21c;
    u8 unk_220[0x4];
    f32 m_224;
    u8 unk_228[0x4];
    void* m_22c;
    u8 unk_230[0x18];
    Vec ground_normal;
    u8 unk_254[0x20];
    void* m_274;
    u8 unk_278[0x8];
    void* m_280;
    u8 unk_284[0x8];
    u32 m_28c;
    Vec move_origin;  // where the current move started (calc_velocity_toward_destination's from)
    Vec move_destination;  // where the current move goes
    u8 *target;
    u32 m_2ac;
    u8 * m_2b0;
    f32 m_2b4;
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
    u16 m_2d6;
    u16 m_2d8;
    u8 unk_2DA[0x2];
    // Bit 1: hit by a ranged attack (calc_distance_accuracy_penalty); bit 2: a
    // Recon whose Recobox died. Cleared with the attack receipts.
    u32 hit_flags;
    void* m_2e0;
    uaddr m_2e4;
    u8 unk_2E8[0x2];
    s16 m_2ea;
    u8 unk_2EC[0x2];
    s16 m_2ee;
    u8 unk_2F0[0x2];
    s16 m_2f2;
    s16 m_2f4;
    s16 m_2f6;
    s16 m_2f8;
    s16 m_2fa;
    Vec body_center;  // position raised to mid-body; effects spawn and distances are measured here
    Vec velocity;
    // The pad driving it in place of its AI; TObjControl::run_task reads the
    // attack button and the stick (inferred).
    ControllerInputContext *controller_input;
    uaddr m_318;  // the actor's AttackParams
    ActorParamBlock *param_block;  // get_actor_param_block
    u8 unk_320[0x2];
    s16 m_322;
    s16 control_state;  // who drives it: 6 a script, 7 a fixed pose
    s16 mode;
    s16 phase;
    u8 unk_32A[0x2];
    s16 hp;
    u16 tp;
    u8 unk_330[0x4];
};

extern "C" void *__dt__9TObjCharaFv(void *, s16);

LAYOUT_ASSERT(TObjCharaGroundNormalOffset, offsetof(TObjChara, ground_normal) == 0x248);

#endif
