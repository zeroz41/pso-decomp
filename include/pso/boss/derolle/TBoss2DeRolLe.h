#ifndef PSO_BOSS_DEROLLE_TBOSS2DEROLLE_H
#define PSO_BOSS_DEROLLE_TBOSS2DEROLLE_H

#include "types.h"

struct NJS_OBJECT;
struct BmlResource;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/derolle/TUnk_80036250.h"
#include "pso/system/ControllerInputState.h"
#include <dolphin/mtx.h>
#include "pso/network/protocol/protocol_types.h"

struct TBoss2Joint;
class TBoss2Tentacle;
class TBoss2Fin;
class TObjChara;
class TParticleCtrl;
struct TBoss2LaserLight;
class TUnk_80482EC0;
class TUnk_80482D04;
class AreaAttackHistory;

// The boss's models and motions, loaded from bm_boss2_de_rol_le(_a).bml by load_resources.
extern BmlResource *boss2_derolle_resource;

// The 6x13 subcommand: the boss's new action state (handle_6x13_de_rol_le_boss_actions).
struct DeRolLeActionPacket {
    G_ClientIDHeader header;
    s16 state;
    s16 sequence_index;
};

// The 6x14 subcommand: 6x13 plus the target (handle_6x14_de_rol_le_boss_actions_with_target).
struct DeRolLeActionTargetPacket {
    G_ClientIDHeader header;
    s16 state;
    s16 sequence_index;
    s32 target_id;
};

struct TBoss2DeRolLe : public TObjEneDD_ST {
    TBoss2DeRolLe(TObject *parent, void *set_data);
    virtual ~TBoss2DeRolLe();
    virtual void run_task();
    virtual void render();
    virtual void refresh_target();
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
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void update_body_colliders();           // refreshes the colliders from the body's offsets
    virtual void enable_body_collision();
    virtual int vfunc_105();
    virtual void render_body();
    static TBoss2DeRolLe *get_instance();
    static void *create(void *set_data);
    static void load_resources();
    static void reset_parts();
    void advance_phase_wrap();
    void clear_play_flags();
    s32 update_phase_is_done();
    void init_movement();
    s32 sub_80034800();
    void init_move_params();
    s32 update_state();
    void init_wave_params();
    s32 sub_80034574();
    void spawn_photon_pad(s32 joint, s32 level);
    void calc_offset_position();
    void activate_laser_light();
    void free_laser();
    void apply_hp_damage_with_sound(s32 damage, u16);
    void set_flags_play_sound();
    static void spawn_offset_particle(Vec *position, f32 height, f32 distance);
    void set_state_and_send(s32 state);
    s32 is_ready();
    void sub_80034034();
    void advance_action_sequence();
    void sub_8003508C();
    void set_position_index(s32 index);
    void pick_random_target();
    void sub_80034258();
    void sub_800341F0();
    void sub_800333F4(u32 reason);
    void sub_8002FD9C(u32 reason, s32 arg2);
    void sub_8002FCE4(u32 reason);
    void sub_8002F73C(u32 reason);
    void reload_stats_for_phase(s32 kind);
    void set_move_target_point(s32 index);
    void update_angle();
    void init_head_params();
    void state_photon_pads(u32 reason, s32 position);
    void state_launch_mines(u32 reason, s32 state);
    void state_ceiling_attack(u32 reason);
    void spawn_ceil_junk(Vec *pos);
    void update_particle_ctrls();
    void sub_80033A80(TParticleCtrl *ctrl);
    void update_projectile_spawns();
    void sub_800338BC();
    void update_pulsing_colors();
    void sub_80030DFC(u32 reason, s32 side);
    void set_move_direction(s32 side);
    void sub_800310F8(u32 reason, s32 side);
    void sub_80030A38(u32 reason);
    void handle_debug_pad_input(u32 reason);
    void sub_800327C8(u32 reason, s32 from, s32 to);
    s32 state_flags;                   // 0x8 shell broken, 0x40/0x80 breakup pieces, 0x8000 already beaten
    s32 unk_3C4;
    s32 debug_pad_active;              // handle_debug_pad_input drives the boss from debug_pad when set
    ControllerInputContext *debug_pad; // controller_input_state.controllers[1]
    s32 unk_3D0;
    s32 unk_3D4;
    TObject part_group;                // parent of the tentacles, mines, fin and laser light
    s32 unk_3F4;
    Vec unk_3F8[20];
    Vec unk_4E8[4];
    Vec unk_518[3];
    s32 unk_53C;
    Vec joint_positions[10];           // one per TBoss2Joint in joints
    s32 unk_5B8[10];
    TBoss2Joint *joints[10];
    f32 unk_608[4];
    GC_Mtx *unk_618;                   // 12 matrices, mem_alloc'd by the constructor
    GC_Mtx *tentacle_matrices;         // one per tentacle root
    TBoss2Tentacle *tentacles[4];
    TUnk_80482EC0 *mines[5];
    TUnk_80482D04 *target_mines[3];  // launched at the target (init_launch)
    TBoss2Fin *fin;
    s32 position_index;
    s32 next_position_index;           // where the running move ends; it becomes position_index
    s32 unk_65C;
    s32 unk_660;
    TUnk_80036250 motion_x;            // drives position.x (TBoss7DeRolLeC's motion_x)
    TUnk_80036250 motion_z;            // drives position.z
    f32 height_offset;                 // body height the render matrix is translated by (render)
    s32 unk_6A8;
    s32 unk_6AC;
    s32 unk_6B0;
    s32 photon_pad_level;              // 0-2, cycled by state_photon_pads; TBoss2PhotonPad's level
    TBoss2LaserLight *laser_light;
    Vec laser_light_pos;               // the position the laser light follows
    AreaAttackHistory *attack_history;
    TObject *unk_6CC;
    TObject *unk_6D0;
    f32 pulse_phase;                   // 0..2, advanced by pulse_speed (advance_phase_wrap)
    f32 pulse_speed;
    s32 unk_6DC;
    s32 state_step;                    // the running state's step (every state handler switches on it)
    s32 unk_6E4;
    s32 unk_6E8;
    s32 unk_6EC;
    s32 unk_6F0;
    s32 unk_6F4;
    s32 unk_6F8;
    f32 state_floats[16];              // per-state scratch: each state handler gives them its own meaning
    TParticleCtrl *unk_73C;
    TParticleCtrl *splash_ctrls[6];    // splash emitters kept on the joints (update_particle_ctrls)
    s32 splash_joint;                  // when set, the joint the first splash pair moves to for one update
    static void reset_fields_3d0(void *p);
};

LAYOUT_ASSERT(TBoss2DeRolLe_size, sizeof(TBoss2DeRolLe) == 0x75C);
extern "C" {
void TBoss2DeRolLe__sub_8002FE60(TBoss2DeRolLe *self, u32 reason);
void TBoss2DeRolLe__sub_800313F8(TBoss2DeRolLe *self, u32 reason, s32 arg2);
void TBoss2DeRolLe__sub_80031AD4(TBoss2DeRolLe *self, u32 reason);
void TBoss2DeRolLe__sub_800320B4(TBoss2DeRolLe *self, u32 reason, s32 arg2, s32 arg3);
void TBoss2DeRolLe__sub_80032E38(TBoss2DeRolLe *self, u32 reason);
f32 TBoss2DeRolLe__sub_80034CEC(void);
f32 TBoss2DeRolLe__sub_80034CF8(void);
void TBoss2DeRolLe__sub_800360A8(void *arg0);
void TBoss2DeRolLe__sub_80036358(void *p);
void TBoss2DeRolLe__sub_800363A0(void *p);
s32 TBoss2Joint_get_shell_max_hp(void);
void TObjPlayer__sub_8002F61C(NJS_OBJECT *);
void advance_phase_wrap__13TBoss2DeRolLeFv(u8 *arg0);
s32 advance_scalar_motion_profile(void *arg0);
void run_hit_reaction__13TBoss2DeRolLeFv(TBoss2DeRolLe *arg0);
void backup_pos__13TBoss2DeRolLeFi(s32 arg0);
void emit_effect_and_step__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);
void fn_8002F5AC(u8 *arg0);
void forward_switch_phase_stats__13TBoss2DeRolLeFi(saddr arg0);
void get_node_world_pos__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1);
void handle_6x13_de_rol_le_boss_actions(void *arg0);
void handle_6x14_de_rol_le_boss_actions_with_target(void *arg0);
void handle_death_state__13TBoss2DeRolLeFPvPv(TBoss2DeRolLe *self, u32 reason);
void init_from_param__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);
s32 play_sound(s32 id, Vec *position);
void render__13TBoss2DeRolLeFv(u8 *arg0);
void render_body__13TBoss2DeRolLeFv(u8 *arg0);
void send_6x13__13TBoss2DeRolLeFPv(void *p);
void set_params__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);
int spawn_trap__13TBoss2DeRolLeFPvii(s32 id, void *owner, Vec *pos);
void swap_6x13_fields__13TBoss2DeRolLeFPv(void *p);
void swap_endian__13TBoss2DeRolLeFPv(void *p);
void switch_phase_stats__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1);
void update_and_send__13TBoss2DeRolLeFPv(void *p);
}

// lbl_804FE30C: layout known from its uses only.
struct RecoveredGlobal_lbl_804FE30C { s32 value; u8 remaining[0xC]; };
extern RecoveredGlobal_lbl_804FE30C lbl_804FE30C;
// lbl_804FE31C: layout known from its uses only.
struct RecoveredGlobal_lbl_804FE31C { s32 value; u8 remaining[0x8]; };
extern RecoveredGlobal_lbl_804FE31C lbl_804FE31C;

#endif
