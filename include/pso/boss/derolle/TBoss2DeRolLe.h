#ifndef PSO_BOSS_DEROLLE_TBOSS2DEROLLE_H
#define PSO_BOSS_DEROLLE_TBOSS2DEROLLE_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/derolle/TUnk_80036250.h"
#include "pso/system/ControllerInputState.h"
#include <dolphin/mtx.h>

struct TBoss2Joint;
class TBoss2Tentacle;
class TBoss2Fin;
struct TBoss2LaserLight;
class TUnk_80482EC0;
class TUnk_80482D04;
class AreaAttackHistory;

struct TBoss2DeRolLe : public TObjEneDD_ST {
    TBoss2DeRolLe(TObject *parent, void *set_data);
    virtual ~TBoss2DeRolLe();
    virtual void run_task();
    virtual void render();
    virtual void vfunc_28();
    virtual void apply_poison_status();
    virtual void apply_paralysis();
    virtual void apply_slow_status();
    virtual void apply_confusion_status();
    virtual void apply_movement_ailment(s32);
    virtual void apply_shock_status();
    virtual void clear_harmful_statuses();
    virtual void vfunc_61();
    virtual void vfunc_62();
    virtual void vfunc_63();
    virtual void dispatch_action(u32 state, s32 reason);
    virtual void vfunc_88();           // refreshes the colliders from the body's offsets
    virtual void vfunc_93();
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
    void sub_800344A4(s32 joint, s32 arg2);
    void calc_offset_position();
    void activate_laser_light();
    void free_laser();
    void apply_hp_damage_with_sound(s32 damage, u16);
    void set_flags_play_sound();
    static void spawn_offset_particle(Vec *position, f32 height, f32 distance);
    u8 pad_374[0x8];
    f32 unk_37C;                       // 20.0 (TBoss7DeRolLeC's twin field too)
    u8 pad_380[0x40];
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
    TUnk_80482EC0 *unk_630[5];
    TUnk_80482D04 *unk_644[3];
    TBoss2Fin *fin;
    s32 unk_654;
    s32 unk_658;
    s32 unk_65C;
    s32 unk_660;
    TUnk_80036250 unk_664;
    TUnk_80036250 unk_684;
    f32 unk_6A4;
    s32 unk_6A8;
    s32 unk_6AC;
    s32 unk_6B0;
    s32 unk_6B4;
    TBoss2LaserLight *laser_light;
    Vec laser_light_pos;               // the position the laser light follows
    AreaAttackHistory *attack_history;
    TObject *unk_6CC;
    TObject *unk_6D0;
    f32 unk_6D4;
    f32 unk_6D8;
    s32 unk_6DC;
    s32 unk_6E0;
    s32 unk_6E4;
    s32 unk_6E8;
    s32 unk_6EC;
    s32 unk_6F0;
    s32 unk_6F4;
    s32 unk_6F8;
    f32 unk_6FC[16];
    TObject *unk_73C;
    TObject *unk_740[6];
    s32 unk_758;
    static void reset_fields_3d0(void *p);
};

LAYOUT_ASSERT(TBoss2DeRolLe_size, sizeof(TBoss2DeRolLe) == 0x75C);
extern "C" {
void TBoss2DeRolLe__sub_8002F73C(TBoss2DeRolLe *self, u32 reason);
void TBoss2DeRolLe__sub_8002FCE4(TBoss2DeRolLe *self, u32 reason);
void TBoss2DeRolLe__sub_8002FD9C(TBoss2DeRolLe *self, u32 reason, s32 arg2);
void TBoss2DeRolLe__sub_8002FE60(TBoss2DeRolLe *self, u32 reason);
void TBoss2DeRolLe__sub_80030720(TBoss2DeRolLe *self, u32 reason, s32 state);
void TBoss2DeRolLe__sub_80030898(TBoss2DeRolLe *self, u32 reason, s32 arg2);
void TBoss2DeRolLe__sub_80030A38(TBoss2DeRolLe *self, u32 reason);
void TBoss2DeRolLe__sub_80030DFC(TBoss2DeRolLe *self, u32 reason, s32 arg2);
void TBoss2DeRolLe__sub_800310F8(TBoss2DeRolLe *self, u32 reason, s32 arg2);
void TBoss2DeRolLe__sub_800313F8(TBoss2DeRolLe *self, u32 reason, s32 arg2);
void TBoss2DeRolLe__sub_80031AD4(TBoss2DeRolLe *self, u32 reason);
void TBoss2DeRolLe__sub_800320B4(TBoss2DeRolLe *self, u32 reason, s32 arg2, s32 arg3);
void TBoss2DeRolLe__sub_800327C8(TBoss2DeRolLe *self, u32 reason, s32 arg2, s32 arg3);
void TBoss2DeRolLe__sub_80032E38(TBoss2DeRolLe *self, u32 reason);
void TBoss2DeRolLe__sub_800333F4(TBoss2DeRolLe *self, u32 reason);
void TBoss2DeRolLe__sub_80034034(TBoss2DeRolLe *self);
void TBoss2DeRolLe__sub_800338BC(void);
void TBoss2DeRolLe__sub_80033A80(s32 arg0, saddr arg1);
f32 TBoss2DeRolLe__sub_80034CEC(void);
f32 TBoss2DeRolLe__sub_80034CF8(void);
void TBoss2DeRolLe__sub_8003508C(void *arg0);
void TBoss2DeRolLe__sub_800360A8(void *arg0);
void TBoss2DeRolLe__sub_80036358(void *p);
void TBoss2DeRolLe__sub_800363A0(void *p);
s32 TBoss2Joint_get_shell_max_hp(void);
void TObjPlayer__sub_8002F61C(NJS_OBJECT *);
void advance_action_sequence__13TBoss2DeRolLeFPv(TBoss2DeRolLe *self);
void advance_phase_wrap__13TBoss2DeRolLeFv(u8 *arg0);
s32 advance_scalar_motion_profile(void *arg0);
void vfunc_62__13TBoss2DeRolLeFv(TBoss2DeRolLe *arg0);
void backup_pos__13TBoss2DeRolLeFi(s32 arg0);
void emit_effect_and_step__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);
void fn_8002F5AC(u8 *arg0);
void forward_switch_phase_stats__13TBoss2DeRolLeFi(saddr arg0);
void get_node_world_pos__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1);
void handle_6x13_de_rol_le_boss_actions(void *arg0);
void handle_6x14_de_rol_le_boss_actions_with_target(void *arg0);
void handle_death_state__13TBoss2DeRolLeFPvPv(TBoss2DeRolLe *self, u32 reason);
void handle_debug_pad_input__13TBoss2DeRolLeFPvPv(TBoss2DeRolLe *self, u32 reason);
void init_from_param__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);
void init_head_params__13TBoss2DeRolLeFPv(u8 *arg0);
s32 is_ready__13TBoss2DeRolLeFPv(TBoss2DeRolLe *arg0);
void pick_random_target__13TBoss2DeRolLeFi(saddr actor);
s32 play_sound(s32 id, Vec *position);
void reload_stats_for_phase__13TBoss2DeRolLeFPvi(void *self, s32 kind);
void render__13TBoss2DeRolLeFv(u8 *arg0);
void render_body__13TBoss2DeRolLeFv(u8 *arg0);
void send_6x13__13TBoss2DeRolLeFPv(void *p);
void set_move_direction__13TBoss2DeRolLeFPv(void *arg0);
void set_move_target_point__13TBoss2DeRolLeFPvi(u8 *arg0, s32 arg1);
void set_params__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);
void set_position_index__13TBoss2DeRolLeFPvi(u8 *arg0, s32 arg1);
void spawn_ceil_junk__13TBoss2DeRolLeFii(s32 arg1, saddr arg2);
int spawn_trap__13TBoss2DeRolLeFPvii(void *p, int a1, int a2);
void state_ceiling_attack__13TBoss2DeRolLeFPvUi(TBoss2DeRolLe *self, u32 reason);
void swap_6x13_fields__13TBoss2DeRolLeFPv(void *p);
void swap_endian__13TBoss2DeRolLeFPv(void *p);
void switch_phase_stats__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1);
void update_and_send__13TBoss2DeRolLeFPv(void *p);
void update_angle__13TBoss2DeRolLeFPv(void *arg0);
void update_projectile_spawns__13TBoss2DeRolLeFPv(u8 *arg0);
void update_particle_ctrls__13TBoss2DeRolLeFPv(TBoss2DeRolLe *self);
void update_pulsing_colors__13TBoss2DeRolLeFPv(u8 *arg0);
}

// lbl_804FE30C: layout known from its uses only.
struct RecoveredGlobal_lbl_804FE30C { s32 value; u8 remaining[0xC]; };
extern RecoveredGlobal_lbl_804FE30C lbl_804FE30C;
// lbl_804FE31C: layout known from its uses only.
struct RecoveredGlobal_lbl_804FE31C { s32 value; u8 remaining[0x8]; };
extern RecoveredGlobal_lbl_804FE31C lbl_804FE31C;

#endif
