#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/saver/SaverLifecycle.h"
#include "pso/effect/enemy/TEneParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/player/PlayerAttackParams.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "types.h"
#include "pso/system/AreaSound.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/saver/TObjEneSaver.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();

#include "pso/system/vector.h"

#include "pso/render/TUnk_80490470.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"

#include "pso/unk/TLobby.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"

struct Obj_800A6B14;


typedef struct Ent_800A715C { s32 a; void *b; } Ent_800A715C;

typedef struct Sub_800A715C { u8 pad[8]; void *f8; NJS_TEXLIST *texlist; } Sub_800A715C;

typedef struct Res_800A715C { u8 pad[0x42C]; Sub_800A715C *sub; Ent_800A715C *ents; } Res_800A715C;

struct Obj_800A73F8 { u8 pad0[0x18]; void *vt; u8 pad1c[0x3C0 - 0x1C]; void *items[3]; };

struct E_800A7734 { u8 pad[8]; s32 x8; s32 xc; };

struct G_800A7734 { u8 pad[0x42c]; E_800A7734 *tbl; };

struct O_800A7734 { u8 pad[0x24]; s32 x24; u8 pad2[0xc]; s32 x34; };

extern "C" {
s32 update_movement_status__12TObjEneSaverFv(u8 *arg0);
s32 update_action_hold_status__12TObjEneSaverFv(u8 *arg0);
extern void *bm_ene_df1_saver_model_names[2];
extern void *bm_ene_df1_saver_motion_names[12];
}
RecoveredGlobal_lbl_80500978 lbl_80500978;
extern "C" {
void *saver_boss_stat_handle;
void **player_object_ptr_array;
void *saver_object_stat_handle;
f32 *lbl_805D504C;
uaddr saver_bml_resource;
saddr lbl_805D5054;
s32 lbl_805D5058;
s32 lbl_805D505C;
saddr lbl_805D5060;
saddr lbl_805D5064;
void *lbl_805D5068;
saddr lbl_805D506C;
void initialize_saver_resources(void);
void *__dt__13TUnk_80490470Fv(void *, s16);
void *__dt__9TObjEnemyFv(TObjEnemy *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
extern void *TObjEneSaver__vtable[83];
Obj_800A73F8 *__dt__12TObjEneSaverFv(Obj_800A73F8 *arg0, s16 arg1);
void* get_center__12TObjEneSaverFv(void* p);
void __ct__9TObjEnemyFP7TObject(void *, void *, void *);
void init_collision_body_parts(void *, void *, s32);
u8 *TObjEneSaver__ct(TObjEneSaver *self, void *arg1, void *arg2);
}
int initialize_enemy_photon_effect(void *p);

struct C_800A4294 { s32 x0; };

struct B_800A4294 { u8 pad[0xc]; C_800A4294 *c; };

struct A_800A4294 { u8 pad[0x8]; B_800A4294 *b; };

struct G_800A4294 { A_800A4294 *p; s32 n; u8 pad[0x8]; };

struct Base1 { u8 pad[0x14]; };

struct VObj1 : Base1 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
    virtual void m5();
};

extern A_800A4294 lbl_804CC8C8;
extern G_800A4294 player_effect_task_list;
extern int TObjPlayer__effect_count;
extern "C" {
void TObjPlayer__sub_800A4294(void);
s32 TObjPlayer__sub_800A7774(void *, void *);
}
void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 farg0);
void move_with_wall_slide(u8 *arg0);
extern "C" {
s32 TObjPlayer__sub_800A04F0(void *);
struct VDisp_800a42c4_800A4288 { char pad[0x18]; virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4(void *, void *); };

void TObjPlayer__sub_800A42C0(void);
void run_death_reaction__12TObjEneSaverFv(void *arg0);
s32 post_translate_matrix(void *);
void check_enemy_body_collisions(void *arg0);
s32 submit_cursor_candidate(void *, int);
s32 matrix_mult_vec_array(int, int, void *, int);
s32 minimap_render_dot(void *, int, int, int);

struct Obj_800A48C4;
struct Obj_800A4C4C;
struct Obj_800A5A68;
struct Obj_800A677C;
extern "C" {
void vfunc_6__8TObjBaseFPsl();
void has_no_target__9TObjCharaFv();
void recalc_stats__9TObjCharaFv();
void deliver_attack_hits__9TObjCharaFf();
void vfunc_66__9TObjCharaFv();
void get_anim_node_position__9TObjCharaFlP3Vec();
void vfunc_43__9TObjCharaFv();
void update_actor_ground_y_at__9TObjCharaFP3Vec();
void interact__14TObjCollidableFl();
void run_hit_reaction__12TObjEneSaverFv(Obj_800A48C4 *o);
void run_attack_action__12TObjEneSaverFv(Obj_800A5A68 *self);
void run_move_action__12TObjEneSaverFv(void *arg0);
void run_idle_action__12TObjEneSaverFv(u8 *arg0);
void render__12TObjEneSaverFv(u8 *arg0);
void run_task__12TObjEneSaverFv(u8 *arg0);
void vfunc_74__9TObjEnemyFl();
void add_actor_exp__9TObjCharaFl();
void apply_action_hold_status__9TObjCharaFf();
void apply_anti_technique__9TObjCharaFl();
void apply_attack_stat_status__9TObjCharaFPv();
void apply_confusion_status__9TObjCharaFv();
void apply_hit_message_flags__9TObjEnemyFPv();
void apply_knockback_from_attacker__9TObjCharaFPUcf();
void apply_movement_ailment__9TObjCharaFl();
void apply_object_set_data__8TObjBaseFPv();
void apply_paralysis__9TObjCharaFv();
void apply_poison_status__9TObjCharaFv();
void apply_set_data__9TObjEnemyFPv();
void apply_shock_status__9TObjCharaFv();
void apply_slow_status__9TObjCharaFv();
void apply_switch_attack__9TObjCharaFv();
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
void apply_enemy_state__9TObjEnemyFPl();
void classify_actor_view_detail__8TObjBaseFfff();
void clear_all_status_effects__9TObjCharaFv();
void clear_harmful_statuses__9TObjCharaFv();
void clear_lobby_object_state__9TObjEnemyFv();
void consume_timer_field__9TObjCharaFl();
void cure_paralysis__9TObjCharaFv();
void cure_poison_ailment__9TObjCharaFv();
void enemy_spawn_jellen_effect__9TObjCharaFv();
void enemy_spawn_zalure_effect__9TObjCharaFv();
void run_miss_reaction__12TObjEneSaverFv(void *arg0);
s32 test_flag_256__12TObjEneSaverFv(Obj_800A4C4C *self);
void find_nearest_target__10TObjPlayerFPv(Obj_800A677C *self);
void vfunc_78__9TObjCharaFl();
void gain_photon_blast_chain_charge__9TObjCharaFv();
void spend_photon_blast_charge__9TObjCharaFf();
void gain_photon_blast_charge__9TObjCharaFf();
void get_actor_level_index__9TObjCharaFv();
void get_name__9TObjEnemyFv();
void get_pos__9TObjCharaFl();
void is_actor_cadence_frame__9TObjCharaFl();
s32 is_target_in_attack_range__12TObjEneSaverFv(u8 *arg0);
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
void receive_physical_attack__9TObjCharaFPvf();
void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();
void render_shadows__9TObjEnemyFv(u8 *arg0);
void reset_motion_fields__9TObjCharaFv();
void reset_pose__9TObjCharaFv();
void roll_physical_accuracy__9TObjCharaFPvlf();
void select_melee_contact_body__9TObjCharaFPvf();
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
void try_start_action__9TObjCharaFll();
s32 update_slow_status__9TObjCharaFv(u8 *arg0);
void update_actor_ground_y__9TObjCharaFv();
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
void update_flag30_timer__9TObjCharaFv();
void update_object_view_visibility__8TObjBaseFff();
void update_poison_status__9TObjCharaFv();
void update_shock_clock__9TObjCharaFv();
__declspec(section ".data") void *bm_ene_df1_saver_model_names[2] = {
    (void *)"df1_s_kil_body.nj", (void *)0x0,
};
void *bm_ene_df1_saver_motion_names[12] = {
    (void *)"aseri_df1_s_kil_body.njm", (void *)"atack_df1_s_kil_body.njm", (void *)"damage_df1_s_kil_body.njm", (void *)"deadb_df1_s_kil_body.njm",
    (void *)"dead_df1_s_kil_body.njm", (void *)"defdam_df1_s_kil_body.njm", (void *)"defence_df1_s_kil_body.njm", (void *)"jump_df1_s_kil_body.njm",
    (void *)"nail_df1_s_kil_body.njm", (void *)"wait_df1_s_kil_body.njm", (void *)"walk_df1_s_kil_body.njm", (void *)0x0,
};
void *bm_ene_df1_saver_resource_descriptor[4] = {
    (void *)"bm_ene_df1_saver.bml", (void *)&bm_ene_df1_saver_model_names, (void *)&bm_ene_df1_saver_motion_names, (void *)0x1000b,
};
TObjMotionAction saver_action_table[11] = {
    {1, 0, 9, 1.0f, 1},
    {1, 0, 10, 1.0f, 1},
    {2, 0, 1, 1.0f, 4},
    {2, 0, 8, 1.0f, 4},
    {2, 0, 7, 0.7f, 4},
    {1, 0, 6, 0.8f, 0x20},
    {2, 7, 5, 1.0f, 8},
    {2, 0, 0, 0.8f, 0x20},
    {2, 0, 2, 1.0f, 8},
    {3, 0, 4, 1.0f, 0x10},
    {3, 0, 3, 1.0f, 0x10},
};

const char *TObjEneSaver__class_name = "TObjEneSaver";
const NpcAnimationBinding saver_init_binding_desc = { NULL, reinterpret_cast<TObjMotionAction *>(saver_action_table), 0, 1, 11 };
const Vec lbl_8043A8A4 = {0.0f, 0.0f, 0.0f};
const Vec lbl_8043A8B0 = {0.0f, 0.0f, 0.0f};
const Vec lbl_8043A8BC = {0.0f, 0.0f, 0.0f};
void *lbl_80490B28[7] = {
    (void *)0x437a0000, (void *)0x3fa00000, (void *)0x400, (void *)0x0,
    (void *)0x64, (void *)0x0, (void *)0x0,
};
void *saver_collision_body_part_table[11] = {
    (void *)0x0, (void *)0x41480000, (void *)0x0, (void *)0x40c00000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *TObjEneSaver__vtable[83] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__12TObjEneSaverFv, (void *)&run_task__12TObjEneSaverFv,
    (void *)&render__12TObjEneSaverFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__12TObjEneSaverFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&update_actor_ground_y_at__9TObjCharaFP3Vec, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&find_nearest_target__10TObjPlayerFPv, (void *)&has_no_target__9TObjCharaFv, (void *)&is_target_in_attack_range__12TObjEneSaverFv, (void *)&test_flag_256__12TObjEneSaverFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__12TObjEneSaverFv, (void *)&update_slow_status__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__12TObjEneSaverFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&run_idle_action__12TObjEneSaverFv, (void *)&run_move_action__12TObjEneSaverFv,
    (void *)&run_attack_action__12TObjEneSaverFv, (void *)&run_miss_reaction__12TObjEneSaverFv, (void *)&run_hit_reaction__12TObjEneSaverFv, (void *)&run_death_reaction__12TObjEneSaverFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&deliver_attack_hits__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&gain_photon_blast_charge__9TObjCharaFf,
    (void *)&spend_photon_blast_charge__9TObjCharaFf, (void *)&gain_photon_blast_chain_charge__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&apply_enemy_state__9TObjEnemyFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv,
};
}

void TObjPlayer::reset_effect_count() { TObjPlayer__effect_count = 0; }

void TObjPlayer__sub_800A4294(void) {
    player_effect_task_list.p = &lbl_804CC8C8;
    player_effect_task_list.n = 0x10;
    (*(s32 *)&TObjPlayer__effect_count) = player_effect_task_list.p->b->c->x0;
}

void TObjPlayer__sub_800A42C0(void) {  }

void TObjEneSaver::apply_lookup_entry_effect() {
    struct { s32 a, b, c; s32 d, e, f, g, h; } sp8;
    s32 entry;
    u8 *temp_r3_2;

    entry = (saddr)((SampledMotionPoints *)((void *)lbl_805D5064))->lookup((f32)this->frame);
    if (entry != 0) {
        push_matrix();
        set_matrix_identity(0);
        post_translate_matrix((void *) (((u8 *)this) + 0x38));
        rotate_matrix_y(0, this->rotation_y);
        matrix_mult_vec_array(0, entry, &sp8, 2);
        pop_matrix();
        temp_r3_2 = (unsigned char *) (*(void **)((s8 *)((u8 *)this) + 0x3C0));
        if (temp_r3_2 != NULL) {
            ((struct VDisp_800a42c4_800A4288 *) temp_r3_2)->m4(&sp8, &sp8.d);
        }
    }
}

void TObjEneSaver::sub_800A435C() {
    switch (this->m_380) {
    case 0x0:
        if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x3A0) != 0U) {
            ((TEneParticleCtrl *)(*(void **)((s8 *)((u8 *)this) + 0x3A0)))->free_particle_ctrl();
        }
        break;
    default:
        calc_move_state();
    case 0x107:
    case 0x10E:
        if (!(this->m_374 & 4)) {
            if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x3A0) != 0U) {
                ((TEneParticleCtrl *)(*(void **)((s8 *)((u8 *)this) + 0x3A0)))->free_particle_ctrl();
            }
        } else if ((s32) this->m_384 != (s32) this->m_380) {
            if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x3A0) != 0U) {
                ((TEneParticleCtrl *)(*(void **)((s8 *)((u8 *)this) + 0x3A0)))->set_param(this->m_380);
            }
            this->m_384 = (s32) this->m_380;
        }
        break;
    }
    if ((u32) *(u32 *)((s8 *)((u8 *)this) + 0x3A0) != 0U) {
        TObjPlayer__sub_800A7774(*(void **)((s8 *)((u8 *)this) + 0x3A0), ((u8 *)this) + 0x390);
    }
}

void TObjEneSaver::calc_move_state() {
    s16 temp_r0;
    s16 temp_r6;

    temp_r0 = *(s16 *)((s8 *)this + 0x38A);
    temp_r6 = *(s16 *)((s8 *)this + 0x388);
    if (temp_r0 == temp_r6) {
        this->m_380 = 0x101;
        return;
    }
    if ((0.5f * (f32) temp_r0) < (f32) temp_r6) {
        this->m_380 = 0x102;
        return;
    }
    if (temp_r6 > 0) {
        this->m_380 = 0x103;
        return;
    }
    this->m_380 = 0;
}

void TObjEneSaver::update_collapse_and_destroy() {
    s32 prev_r3;
    u8 *self = (u8 *)this;
    advance_animation();
    switch (((TObjEneSaver *)self)->phase) {
    case 0:
        ((TObjEneSaver *)self)->phase = 1;
        fn_800D911C((Vec *)(self + 0x38));
        TObjPlayer__sub_800A04F0((u8 *)&this->m_3a4);
        apply_actor_gravity((TObjEnemy *)(self), (s32 *)(0), 0.0f);
        prev_r3 = ((TObjEnemy *)(self))->remap_sound_for_area(0x4003B207);
        play_sound_effect(prev_r3, (u8 *)&this->position, 0, 0);
        return;
    case 1:
        step_angle_clamped(self, 0);
        move_with_wall_slide(self);
        *(f32 *)((s8 *)self + 0x308) *= 0.5f;
        ((TObjEneSaver *)self)->m_310*= 0.5f;
        if (((VObj1 *)(self + 0x3A4))->m4() == 1) {
            TObjPlayer::apply_effect_variant_a((saddr)(self + 0x38), 0);
            ((TObjEneSaver *)self)->phase = 2;
        }
        return;
    case 2:
        ((TObject *)self)->queue_destruction();
        break;
    }
}

void TObjEneSaver::run_death_reaction() {
    void *temp_r4;
    s16 temp_s16;

    if ((s16) this->mode != 0xA) {
        temp_s16 = 0xA;
        this->mode = temp_s16;
        this->phase = 0;
        if (random_ratio() < 0.5f) {
            this->requested_action = 9;
        } else {
            this->requested_action = 0xA;
        }
        temp_r4 = this->bodies;
        *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFFE);
        ((TObjPlayer *)this)->refresh_lobby_state();
        send_entity_set_flags();
    }
}

void TObjEneSaver::update_entry_motion() {
    u8 *temp_r3;

    advance_animation();
    step_angle_clamped(this, 0);
    switch (this->phase) {
    case 0:
        this->phase = 1;
        apply_actor_gravity((TObjEnemy *)(this), (s32 *)(0), 0.0f);
        break;
    case 1:
        this->m_310 = (f32) 0.0f;
        *(f32 *)((s8 *)((u8 *)this) + 0x308) = (f32) 0.0f;
        apply_actor_gravity((TObjEnemy *)(this), (s32 *)(0), 0.0f);
        if ((u32) this->action_flags != 8U) {
            this->phase = 2;
        }
        break;
    case 2:
        if (!(this->actorFlags & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)(this), (s32 *)(0), 0.0f);
        }
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFF9FF);
        temp_r3 = (unsigned char *) (this->bodies);
        *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFBFFFFFF);
        this->referenceHp = (s16) this->hp;
        break;
    }
    this->check_object_collisions();
    check_enemy_body_collisions((this));
    minimap_render_dot((void *) (((u8 *)this) + 0x38), -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
}
}


typedef struct Sub_800A48C4 {
    u8 pad0[0x18];
    s32 flags;
} Sub_800A48C4;

typedef struct Obj_800A48C4 {
    u8 pad0[0x30];
    s32 flags30;
    u8 pad34[0x60 - 0x34];
    s32 f60;
    u8 pad64[0xA4 - 0x64];
    Sub_800A48C4 *fA4;
    u8 padA8[0xB8 - 0xA8];
    s16 fB8;
    u8 padBA[0x2D4 - 0xBA];
    u16 target;
    u8 pad2D6[0x2FC - 0x2D6];
    Vec pos;
    u8 pad308[0x326 - 0x308];
    s16 state;
    s16 f328;
} Obj_800A48C4;

extern "C" {
f32 atan2_float(f32 y, f32 x);
s32 angle_difference_abs(s32, s32);
void *get_player_by_client_id(s32 i);
s32 subtract_vector(void *, void *);
void update_knockback_state__12TObjEneSaverFv(u8 *arg0);

void TObjEneSaver::update_knockback_state() {

    advance_animation();
    step_angle_clamped(this, 0);
    switch (this->phase) {
    case 0:
        this->phase = 1;
        apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), 0.0f);
        break;
    case 1:
        move_with_wall_slide(((u8 *)this));
        *(f32 *)((s8 *)((u8 *)this) + 0x308) *= 0.5f;
        this->m_310 *= 0.5f;
        if ((u32) this->action_flags != 8U) {
            this->requested_action = 7;
            this->phase = 2;
        }
        break;
    case 2:
        if (!(this->actorFlags & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), 0.0f);
        }
        if ((u32) this->action_flags != 0x20U) {
            if ((s32) *(s16 *)((s8 *)((u8 *)this) + 0x388) <= 0) {
                this->m_374 = (s32) (this->m_374 | 8);
            }
            this->actorFlags = (s32) (this->actorFlags & 0xFFFFF9FF);
            this->referenceHp = (s16) this->hp;
        }
        break;
    }
    this->check_object_collisions();
    check_enemy_body_collisions(this);
    minimap_render_dot(((u8 *)this) + 0x38, -0x5DB4, 1, 0);
    submit_cursor_candidate(this, -1);
    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
}
void TObjEneSaver::run_hit_reaction() {
    Obj_800A48C4 *o = (Obj_800A48C4 *)this;
    Vec v;
    u8 *e;
    s32 d;
    if (this->mode >= 10 || this->mode < 8) {
        e = (u8 *)get_player_by_client_id(o->target);
        if (e != NULL) {
            VecCopy((Vec *)&v, (const Vec *)(e + 0x2FC));
            subtract_vector(&v, &o->pos);
            d = angle_difference_abs(this->rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z)));
        } else {
            d = 0;
        }
        if (d < 0x2AAA) {
            this->mode = 8;
            this->requested_action = 6;
        } else {
            this->mode = 9;
            this->requested_action = 8;
        }
        this->phase = 0;
    }
    o->fA4->flags |= 1;
    o->flags30 &= ~0x06240000;
}

}


struct Base14 { char pad[0x14]; };

struct VObj14 : Base14 {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
};

struct Obj_800A4C4C {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0x60 - 0x34];
    s32 f60;
    u8 pad64[0x2FC - 0x64];
    Vec pos;
    u8 pad308[0x374 - 0x308];
    u32 f374;
    u8 pad378[0x388 - 0x378];
    s16 f388;
    u8 pad38A[0x38C - 0x38A];
    struct Obj_800A4C4C *f38C;
};

struct Sub_800A5A68 { u8 pad0[0x18]; u32 flags; };

struct Obj_800A5A68 {
    u8 pad0[0x30];
    u32 f30;
    u8 pad34[0xA4 - 0x34];
    Sub_800A5A68 *sub;
    u8 padA8[0xB8 - 0xA8];
    s16 fB8;
    u8 padBA[0x2A8 - 0xBA];
    struct Obj_800A5A68 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec pos;
    u8 pad308[0x326 - 0x308];
    s16 f326;
    s16 f328;
    u8 pad32A[0x37C - 0x32A];
    s16 mode;
};

struct VBase18_800A4D9C { char pad[0x18]; };

struct VObj18_800A4D9C : VBase18_800A4D9C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4(void *, void *);
};

struct VBase_18_217cff { char pad[0x18]; };

struct VObj_18_217cff : VBase_18_217cff {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual s32 m18(u32, f32);
    virtual void m19();
    virtual s32 m20(u32, f32);
    virtual void m21();
    virtual void m22();
    virtual s32 m23(u32);
};

extern "C" {
s32 TObjPlayer__sub_800A0554(void *);
f32 calc_distance_to_client__10TObjPlayerFlUsUl(void *, u16, void *);
extern s32 registered_player_count;

f32 calc_xz_distance_sq(saddr arg0, uaddr arg1, void *arg2);

s32 enemy_move_toward(void *, s32, Vec *, int, f32 *, f32);
s32 select_enemy_destination(void *, Vec *, int);
s32 copy_position_if_valid__10TObjPlayerFii(s32 arg0, s32 arg1);
#define turn_toward_target__12TObjEneSaverFv ((s32 (*)(void*))(turn_toward_target__12TObjEneSaverFv))
f32 horizontal_distance_squared(int, void *);

}
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
extern "C" {
s32 calc_velocity_toward_destination(void *, Vec, Vec, f32);
s32 get_current_floor();
f32 newton_sqrtf(f32);
u8 *get_enemy_entity(u16);

void TObjPlayer__sub_800A54B4(u8 *arg0);
s32 check_path_obstructed(void *, void *);
u16 get_entity_id(void *);
extern s32 lbl_805D5870;
void TObjPlayer__sub_800A5960(void *arg0);

s16 TObjPlayer__sub_800A776C(void *p);

#pragma push
#pragma fp_contract on
void TObjPlayer__sub_800A49B4(TObjEneSaver *self) {
    self->advance_animation();
    step_angle_clamped(self, 0);
    if (!(self->actorFlags & 0x800000)) {
        apply_actor_gravity(self, (s32 *)0, 0.0f);
    }
    switch (self->phase) {
    case 0:
        self->phase = 1;
        apply_actor_gravity(self, (s32 *)0, 0.0f);
        if (self->m_38c != NULL) {
            s32 bonus;
            s32 atp;
            atp = self->m_38c->get_actor_attack_params_atp_min();
            bonus = self->m_38c->get_field_2c8();
            self->m_388 -= 0.2f * (bonus + atp + TObjPlayer__sub_800A776C(self->m_38c) - self->m_2ce);
            if (self->m_388 <= 0) {
                self->m_388 = 0;
                self->m_374 |= 8;
            }
        }
        self->actorFlags |= 0x04000000;
        play_sound_effect(((TObjEnemy *)(self))->remap_sound_for_area(0x4003AD05), &self->position, 0, 0);
        break;
    case 1:
        if (((TObjMotion *)self)->is_passing_frame(5.0f) != 0) {
            self->m_380 = 0x107;
        }
        if (((TObjMotion *)self)->is_passing_frame(28.0f) != 0) {
            self->actorFlags &= 0xFBFFFEFF;
            self->m_374 &= ~0x20;
            if (self->test_flag_256() != 0) {
                self->phase = 0;
                self->frame = 0.0f;
            } else {
                self->phase = 2;
            }
            self->calc_move_state();
        }
        break;
    case 2:
    default:
        self->actorFlags &= 0xFBFFFEFF;
        self->m_374 &= ~0x20;
        break;
    }
    ((TObjPlayer *)self)->check_object_collisions();
    check_enemy_body_collisions(self);
    minimap_render_dot(&self->position, -0x5DB4, 1, 0);
    self->actorFlags &= ~0x200000;
}
#pragma pop

void TObjEneSaver::run_miss_reaction() {
    void *temp_r5;

    if ((s16) this->mode != 7) {
        this->mode = 7;
        this->phase = 0;
        this->requested_action = 5;
    }
    temp_r5 = this->bodies;
    *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 1);
    this->actorFlags = (s32) (this->actorFlags & 0xF99BFFFF);
}


int TObjEneSaver::test_flag_256() {
    Obj_800A4C4C *self = (Obj_800A4C4C *)this;
    Vec v;
    Obj_800A4C4C *p;
    s32 i;
    if (self->f374 & 0x20) {
        return 1;
    }
    if ((self->f374 & 4) && self->f388 > 0) {
        for (i = 0; i < registered_player_count; i++) {
            p = (Obj_800A4C4C *)TObjPlayer::get_player_data(i);
            if (p == NULL || (p->f30 & 0x800)) {
                continue;
            }
            if (!(calc_distance_to_client__10TObjPlayerFlUsUl(self, i, &v) < 900.0f)) {
                continue;
            }
            if (angle_difference_abs(this->rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z))) >= 0x2AAA) {
                continue;
            }
            if (((TObjPlayer *)p)->test_action_mask(0xE0) == 0) {
                continue;
            }
            VecCopy((Vec *)&v, (const Vec *)&self->pos);
            subtract_vector(&v, &p->pos);
            if (angle_difference_abs(p->f60, (s32)(10430.38043493439 * atan2_float(v.x, v.z))) < 0x2AAA) {
                self->f38C = p;
                self->f374 |= 0x20;
                return 1;
            }
        }
    }
    return 0;
}

#define F(T, o) (*(T *)(self + (o)))
void TObjEneSaver::sub_800A4D9C() {
    u8 m50[0xC];
    u8 m44[0xC];
    Vec d;
    u8 *p;
    s32 floor;
    s32 e;
    u16 id;
    u8 *self = (u8 *)this;
    id = F(u16, 0x338);
    if (id < 0x1000) {
        p = (u8 *)get_player_by_client_id(id);
        if (p != NULL && ((TObjPlayer *)p)->get_floor() == get_current_floor()) {
            F(u8 *, 0x2A8) = p;
        } else {
            F(u8 *, 0x2A8) = NULL;
        }
    } else if (id < 0x4000) {
        F(u8 *, 0x2A8) = get_enemy_entity(id);
    } else {
        F(u16, 0x338) = 0xFFFF;
        F(u8 *, 0x2A8) = NULL;
    }
    F(u32, 0x30) |= 0x06000000;
    {
        u32 *anim = F(u32 *, 0xA4);
        anim[6] &= ~1;
        ((TObjMotion *)self)->advance_animation();
    }
    step_angle_clamped(self, 0);
    switch (F(s16, 0x328)) {
    case 0:
        if (!(F(u32, 0x30) & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
        }
        if (((TObjMotion *)self)->is_passing_frame((f32)11.0f) != 0) {
            u8 *t = F(u8 *, 0x2A8);
            if (t == NULL) {
                goto fail;
            }
            {
                Vec dest = *(Vec *)(t + 0x2FC);
                if (select_enemy_destination(self, &dest, 1) == 0) {
                    goto fail;
                }
            }
            F(s16, 0x328) = 1;
            {
                Vec pos = F(Vec, 0x2FC);
                copy_position_if_valid__10TObjPlayerFii((saddr)self, (saddr)&pos);
            }
            VecCopy((Vec *)&d, (const Vec *)(self + 0x29C));
            subtract_vector(&d, (u8 *)&this->body_center);
            {
                f32 dist = newton_sqrtf(d.x * d.x + d.z * d.z);
                dist -= 15.0f;
                calc_velocity_toward_destination(self, F(Vec, 0x290), F(Vec, 0x29C), 0.058333334f * dist);
            }
            play_sound_effect(((TObjEnemy *)(self))->remap_sound_for_area(0x4003AD03), (u8 *)&this->position, 0, 0);
            goto done;
        fail:
            F(s16, 0x328) = 2;
        done:
            spawn_particle_effect(&this->position, 0xF3);
        }
        break;
    case 1:
        move_with_wall_slide(self);
        if (11.0f <= F(f32, 0xC0) && F(f32, 0xC0) <= 27.0f) {
            if ((e = (saddr)((SampledMotionPoints *)(lbl_805D5068))->lookup(F(f32, 0xC0))) != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix((u8 *)&this->position);
                rotate_matrix_y(0, F(s32, 0x60));
                matrix_mult_vec_array(0, e, m44, 2);
                pop_matrix();
                if (F(VObj18_800A4D9C *, 0x3C4) != NULL) {
                    F(VObj18_800A4D9C *, 0x3C4)->m4(m44, m50);
                }
            }
        }
        if (((TObjMotion *)self)->is_passing_frame((f32)23.0f) != 0) {
            ((TObjPlayer *)self)->check_object_collisions();
            check_enemy_body_collisions(self);
            F(s16, 0x328) = 2;
            TObjPlayer__sub_800A5960(self);
            spawn_particle_effect(&this->position, 0xF3);
            play_sound_effect(((TObjEnemy *)(self))->remap_sound_for_area(0x4003AD04), (u8 *)&this->position, 0, 0);
            F(u32, 0x374) &= ~0x10;
        }
        break;
    case 2:
        if (!(F(u32, 0x30) & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)self, (s32 *)(0), 0.0f);
        }
        if (F(u32, 0xB4) != 4) {
            enemy_set_heading_velocity(0.0f, (TObjEnemy *)(self), F(s32, 0x60));
            F(u32, 0x30) &= 0xF9DFFFFF;
            F(u32 *, 0xA4)[6] |= 1;
        }
        break;
    }
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
}
#undef F

struct VBase_800A5154 { char pad[0x18]; };
struct VTgt_800A5154 : VBase_800A5154 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17();
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual f32 m20(void *, f32);
    virtual void m21(); virtual void m22();
    virtual void m23(void *);
};
struct VCb_800A5154 : VBase_800A5154 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(void *, void *);
};
struct Anim_800A5154 { u8 pad[0x18]; u32 flags; };

struct Pl_800A5154 {
    u8 pad0[0x30];
    u32 flags;
    u8 pad34[0x38 - 0x34];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 angle;
    u8 pad64[0xA4 - 0x64];
    Anim_800A5154 *anim;
    u8 padA8[0xB4 - 0xA8];
    u32 fB4;
    u8 padB8[0xC0 - 0xB8];
    f32 fC0;
    u8 padC4[0x2A8 - 0xC4];
    VTgt_800A5154 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    u8 snd[0x328 - 0x2FC];
    s16 phase;
    u8 pad32A[0x338 - 0x32A];
    u16 target_id;
    u8 pad33A[0x374 - 0x33A];
    u32 f374;
    u8 pad378[0x37E - 0x378];
    s16 count;
    s32 f380;
    u8 pad384[0x388 - 0x384];
    s16 f388;
    s16 f38A;
    u8 pad38C[0x3C8 - 0x38C];
    VCb_800A5154 *cb;
};

#define o ((Pl_800A5154 *)arg0)
void TObjPlayer__sub_800A5154(void *arg0) {
    Vec w;
    Vec v;
    u16 id;

    id = o->target_id;
    if (id < 0x1000) {
        u8 *p = (u8 *)get_player_by_client_id(id);
        if (p != NULL && ((TObjPlayer *)p)->get_floor() == get_current_floor()) {
            o->target = (VTgt_800A5154 *)p;
        } else {
            o->target = NULL;
        }
    } else if (id < 0x4000) {
        o->target = (VTgt_800A5154 *)get_enemy_entity(id);
    } else {
        o->target_id = 0xFFFF;
        o->target = NULL;
    }
    o->anim->flags |= 1;
    o->flags &= 0xF9FBFFFF;
    ((TObjMotion *)o)->advance_animation();
    step_angle_clamped(o, 0);
    switch (o->phase) {
    case 0:
        o->phase = 1;
        apply_actor_gravity((TObjEnemy *)((u8 *)o), (s32 *)(0), 0.0f);
        play_sound_effect(((TObjEnemy *)(o))->remap_sound_for_area(0x4003AD02), &o->pos, 0, 0);
        break;
    case 1:
        if (!(o->flags & 0x800000)) {
            apply_actor_gravity((TObjEnemy *)((u8 *)o), (s32 *)(0), 0.0f);
        }
        if (((TObjMotion *)o)->is_passing_frame((f32)7.0f) != 0) {
            if (o->target != NULL && o->target->m18(o, 1.0f) != 0) {
                f32 d = o->target->m20(o, 1.0f);
                o->target->m23(o);
                o->f388 = o->f388 + d;
                o->f380 = 0x10E;
                if (o->f38A < o->f388) {
                    o->f388 = o->f38A;
                }
                play_sound_effect(((TObjEnemy *)(o))->remap_sound_for_area(0x4003B241), o->snd, 0, 0);
            }
        }
        if (0.0f <= o->fC0 && o->fC0 <= 7.0f) {
            s32 entry = (saddr)((SampledMotionPoints *)((void *)lbl_805D506C))->lookup(o->fC0);
            if (entry != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(&o->pos);
                rotate_matrix_y(0, o->angle);
                matrix_mult_vec_array(0, entry, &v, 2);
                pop_matrix();
                if (o->cb != NULL) {
                    o->cb->m4(&v, &w);
                }
            }
        }
        if (o->fB4 != 4) {
            o->phase = 2;
            o->count++;
        }
        break;
    case 2:
        ((TObjEneSaver *)o)->calc_move_state();
        if (o->count >= 2) {
            o->count = 0;
            o->f374 &= ~8;
        }
        o->flags &= ~0x200000;
        break;
    }
    ((TObjPlayer *)o)->check_object_collisions();
    check_enemy_body_collisions(o);
    minimap_render_dot(&o->pos, -0x5DB4, 1, 0);
    submit_cursor_candidate(o, -1);
}
#undef o

#define F(t, o) (*(t *)(arg0 + (o)))

void TObjPlayer__sub_800A54B4(u8 *arg0) {
    *(s32 *)((s8 *)(F(u8 *, 0xA4)) + 0x18) |= 1;
    F(s32, 0x30) &= 0xF9FBFFFF;
    if (F(u16, 0x338) < 0x1000) {
        u8 *p = (u8 *)get_player_by_client_id(F(u16, 0x338));
        if (p != NULL && ((TObjPlayer *)p)->get_floor() == get_current_floor()) {
            F(u8 *, 0x2A8) = p;
        } else {
            F(u8 *, 0x2A8) = NULL;
        }
    } else if (F(u16, 0x338) < 0x4000) {
        F(u8 *, 0x2A8) = get_enemy_entity(F(u16, 0x338));
    } else {
        F(u16, 0x338) = 0xFFFF;
        F(u8 *, 0x2A8) = NULL;
    }
    switch (F(s16, 0x328)) {
    case 0:
        if (F(u8 *, 0x2A8) == NULL) {
            F(s16, 0x328) = 0;
            F(s32, 0x30) &= ~0x200000;
            F(s16, 0x33A) = 0;
        } else {
            Vec d;
            s32 a;
            VecCopy((Vec *)&d, (const Vec *)(F(u8 *, 0x2A8) + 0x2FC));
            subtract_vector(&d, arg0 + 0x2FC);
            a = ((TObjEnemy *)arg0)->turn_toward_direction(*(s32 *)((s8 *)(F(u8 *, 0x350)) + 8), (Vec *)&d);
            if (!(F(s32, 0x30) & 0x800000)) {
                apply_actor_gravity((TObjEnemy *)arg0, (s32 *)(0), 0.0f);
            }
            if (a < 0x10) {
                F(s16, 0x328) = 1;
                F(s16, 0xB8) = 2;
                ((TObjMotion *)arg0)->sub_800A7798(lbl_805D504C[0]);
                if (check_path_obstructed(arg0, F(u8 *, 0x2A8) + 0x2FC) == 1) {
                    F(f32, 0x308) = F(f32, 0x30C) = F(f32, 0x310) = 0.0f;
                } else {
                    calc_velocity_toward_destination(arg0, *(Vec *)(arg0 + 0x2FC), *(Vec *)(F(u8 *, 0x2A8) + 0x2FC), *(f32 *)((s8 *)(F(u8 *, 0x350)) + 4));
                }
            }
        }
        break;
    case 1:
        F(s16, 0xB8) = 2;
        if (((TObjMotion *)arg0)->is_passing_frame((f32)12.0f) != 0) {
            F(s16, 0x328) = 2;
            play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003A801), arg0 + 0x38, 0, 0);
        }
        break;
    case 2:
        F(s16, 0xB8) = 2;
        if (((TObjMotion *)arg0)->is_passing_frame((f32)16.0f) != 0) {
            TObjPlayer__sub_800A5960(arg0);
        }
        if (15.0f <= F(f32, 0xC0) && F(f32, 0xC0) <= 20.0f) {
            ((TObjEneSaver *)arg0)->apply_lookup_entry_effect();
        }
        if (((TObjMotion *)arg0)->is_passing_frame((f32)21.0f) != 0) {
            F(s16, 0x328) = 3;
        }
        break;
    case 3:
        F(s16, 0xB8) = 2;
        move_with_wall_slide(arg0);
        if (((TObjMotion *)arg0)->is_passing_frame((f32)32.0f) != 0) {
            F(s16, 0x328) = 4;
            play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003A801), arg0 + 0x38, 0, 0);
        }
        break;
    case 4:
        F(s16, 0xB8) = 2;
        if (((TObjMotion *)arg0)->is_passing_frame((f32)37.0f) != 0) {
            TObjPlayer__sub_800A5960(arg0);
        }
        if (32.0f <= F(f32, 0xC0) && F(f32, 0xC0) <= 40.0f) {
            ((TObjEneSaver *)arg0)->apply_lookup_entry_effect();
        }
        if (((TObjMotion *)arg0)->is_passing_frame((f32)42.0f) != 0) {
            F(s16, 0x328) = 5;
        }
        break;
    case 5:
        F(s16, 0xB8) = 2;
        move_with_wall_slide(arg0);
        if (((TObjMotion *)arg0)->is_passing_frame((f32)52.0f) != 0) {
            F(s16, 0x328) = 6;
            play_sound_effect(((TObjEnemy *)(arg0))->remap_sound_for_area(0x4003A801), arg0 + 0x38, 0, 0);
        }
        break;
    case 6:
        F(s16, 0xB8) = 2;
        if (((TObjMotion *)arg0)->is_passing_frame((f32)54.0f) != 0) {
            TObjPlayer__sub_800A5960(arg0);
        }
        if (52.0f <= F(f32, 0xC0) && F(f32, 0xC0) <= 60.0f) {
            ((TObjEneSaver *)arg0)->apply_lookup_entry_effect();
        }
        if (F(u32, 0xB4) != 4) {
            F(s16, 0x328) = 7;
            F(s16, 0x33A) = lbl_805D504C[1];
        }
        break;
    case 7:
        if (--F(s16, 0x33A) < 0) {
            F(s16, 0x328) = 0;
            F(s32, 0x30) &= ~0x200000;
            F(s16, 0x33A) = 0;
        }
        break;
    }
    ((TObjMotion *)arg0)->advance_animation();
    step_angle_clamped(arg0, 0);
    ((TObjPlayer *)arg0)->check_object_collisions();
    check_enemy_body_collisions(arg0);
    minimap_render_dot(arg0 + 0x38, -0x5DB4, 1, 0);
    submit_cursor_candidate(arg0, -1);
}
#undef F

struct Obj_800A4C4C;
typedef struct Self_800A5960 Self_800A5960;
void TObjPlayer__sub_800A5960(void *arg0) {
    s32 n;
    s32 limit;
    s32 i;
    u8 *p;
    uaddr self = (uaddr)arg0;
    if (((TObjCollidable *)self)->obj_testFlags30(0x10) != 0) {
        limit = 0x4000;
        n = registered_player_count + lbl_805D5870;
    } else {
        n = registered_player_count;
        limit = 0x1000;
    }
    for (i = 0; i < n; i++) {
        p = (u8 *)TObjPlayer::get_player_data(i);
        if (TObjPlayer::is_valid_and_active((uaddr)p) != 0 && p != (u8 *)self &&
            get_entity_id(p) < limit && !(*(s32 *)(p + 0x30) & 0x02000800) &&
            ((VObj_18_217cff *)p)->m18(self, 1.0f) != 0) {
            ((VObj_18_217cff *)p)->m20(self, 1.0f);
            ((VObj_18_217cff *)p)->m23(self);
        }
    }
}
}

void TObjEneSaver::run_attack_action() {
    Obj_800A5A68 *self = (Obj_800A5A68 *)this;
    Vec v;
    switch (self->mode) {
    case 0:
    default: {
        VecCopy((Vec *)&v, (const Vec *)&self->target->pos);
        subtract_vector(&v, &self->pos);
        f32 a = atan2_float(v.x, v.z);
        this->mode = 4;
        if ((s32)(10430.38043493439 * a) < 0x10) {
            this->phase = 1;
            this->requested_action = 2;
            ((TObjMotion *)self)->sub_800A7798(*lbl_805D504C);
        } else {
            this->phase = 0;
            this->requested_action = 1;
        }
        break;
    }
    case 2:
        this->mode = 5;
        this->phase = 0;
        this->requested_action = 3;
        break;
    case 1:
        this->mode = 6;
        this->phase = 0;
        this->requested_action = 4;
        break;
    }
    ((TObjEnemy *)self)->bind_enemy_combat_stats((u8 *)(0), (u8 *)player_object_ptr_array[self->mode], (u8 *)(0));
    self->sub->flags |= 1;
    this->actorFlags &= 0xF9FBFFFF;
    this->actorFlags |= 0x200000;
}

s32 TObjEneSaver::is_target_in_attack_range() {
    u8 *self = (u8 *)this;
    Vec v;
    f32 var_f29;
    f32 r;
    f32 dist;
    s32 ang;
    s32 flags;
    u8 *tgt;
    u8 *p;
    if (this->mode >= 3) {
        tgt = this->target;
        if (tgt != NULL && this->m_318 != 0U && !(*(s32 *)((s8 *)tgt + 0x30) & 0x02000800)) {
            dist = calc_xz_distance_sq((saddr)self, (uaddr)tgt, (void *)&v);
            ang = angle_difference_abs(this->rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z)));
            p = *(u8 **)(this->target + 0xA4);
            if (p != NULL) {
                var_f29 = *(f32 *)((s8 *)p + 0xC);
            } else {
                var_f29 = 10.0f;
            }
            flags = this->m_374;
            if (flags & 8) {
                *(s16 *)((s8 *)self + 0x37C) = 2;
                if (dist <= (var_f29 + ((AttackParams *)(player_object_ptr_array[*(s16 *)((s8 *)self + 0x37C)]))->get_attack_range()) * (var_f29 + ((AttackParams *)(player_object_ptr_array[*(s16 *)((s8 *)self + 0x37C)]))->get_attack_range()) && ang <= ((AttackParams *)(player_object_ptr_array[*(s16 *)((s8 *)self + 0x37C)]))->get_attack_angle()) {
                    return 1;
                }
            } else if (flags & 0x10) {
                *(s16 *)((s8 *)self + 0x37C) = 1;
                r = 150.0f + var_f29;
                if (dist <= r * r && ang <= 0xAAA) {
                    return 1;
                }
            } else {
                *(s16 *)((s8 *)self + 0x37C) = 0;
                if (dist <= (var_f29 + ((AttackParams *)(player_object_ptr_array[*(s16 *)((s8 *)self + 0x37C)]))->get_attack_range()) * (var_f29 + ((AttackParams *)(player_object_ptr_array[*(s16 *)((s8 *)self + 0x37C)]))->get_attack_range()) && ang <= ((AttackParams *)(player_object_ptr_array[*(s16 *)((s8 *)self + 0x37C)]))->get_attack_angle()) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void TObjEneSaver::update_move_toward_target() {
    f32 temp_f0;
    f32 temp_f1;
    u8 *temp_r8;
    *(s32 *)((s8 *)this->bodies + 0x18) |= 1;
    this->actorFlags &= 0xF9DBFFFF;
    temp_r8 = this->target;
    if (temp_r8 != NULL) {
        switch (this->phase) {
        case 0: {
            Vec v = *(Vec *)(temp_r8 + 0x2FC);
            if (select_enemy_destination(this, &v, 1) != 0) {
                sub_800A7798(lbl_805D504C[3]);
                this->phase = 1;
                {
                Vec v2 = *(Vec *)(((u8 *)this) + 0x2FC);
                copy_position_if_valid__10TObjPlayerFii((saddr)this, (saddr)&v2);
                }
                apply_actor_gravity((TObjEnemy *)(this), (s32 *)(0), 0.0f);
            }
            break;
        }
        case 1: {
            Vec v3 = *(Vec *)(temp_r8 + 0x2FC);
            enemy_move_toward(this, *(s32 *)((s8 *)this->movementParameters + 8), &v3, 0, lbl_805D504C, lbl_805D504C[2]);
            temp_f1 = horizontal_distance_squared((saddr) (((u8 *)this) + 0x29C), (void *) (((u8 *)this) + 0x38));
            if (temp_f1 < 22500.0f) {
                this->m_374 &= ~0x10;
            } else {
                this->m_374 |= 0x10;
            }
            temp_f0 = *(f32 *)((s8 *)this->movementParameters + 4) + *(f32 *)((s8 *)this->bodies + 0xC);
            if (temp_f1 < (temp_f0 * temp_f0)) {
                this->phase = 2;
            }
            break;
        }
        case 2:
            this->m_374 &= ~0x10;
            this->phase = 0;
            break;
        }
        advance_animation();
        turn_toward_target();
        this->check_object_collisions();
        check_enemy_body_collisions((this));
        minimap_render_dot((void *) (((u8 *)this) + 0x38), -0x5DB4, 1, 0);
        submit_cursor_candidate(this, -1);
    }
}

void TObjEneSaver::sub_800A5FA8() {
    u8 *temp_r4;
    u8 *self = (u8 *)this;
    ((TObjEneSaver *)self)->actorFlags = (s32) (((TObjEneSaver *)self)->actorFlags & 0xFFDFFFFF);
    ((TObjEneSaver *)self)->actorFlags = (s32) (((TObjEneSaver *)self)->actorFlags | 0x06040000);
    temp_r4 = (unsigned char *) (((TObjEneSaver *)self)->bodies);
    *(s32 *)((s8 *)temp_r4 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r4 + 0x18) & 0xFFFFFFFE);
    ((TObjMotion *)self)->advance_animation();
    switch (((TObjEneSaver *)self)->phase) {
    case 0:
        ((TObjEneSaver *)self)->phase = 1;
        play_area_se_with_particle((Vec *)(self + 0x38));
        TObjPlayer__sub_800A0554((u8 *)&this->m_3a4);
        apply_actor_gravity((TObjEnemy *)(self), (s32 *)(0), 0.0f);
        play_area_variant_sound((Vec *)(self + 0x38));
        break;
    case 1:
        if (((VObj14 *) (self + 0x3A4))->m5() == 1) {
            ((TObjEneSaver *)self)->phase = 2;
        }
        break;
    case 2:
        *(s32 *)((s8 *)self + 0x374) = (s32) (*(s32 *)((s8 *)self + 0x374) & 0xFFFF0000);
        *(s32 *)((s8 *)self + 0x374) = (s32) (*(s32 *)((s8 *)self + 0x374) | 4);
        break;
    }
    minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
}

void TObjEneSaver::advance_motion_state() {

    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
    this->actorFlags = (s32) (this->actorFlags | 0x06040000);
    *(s32 *)((s8 *)this->bodies + 0x18) = (s32) (*(s32 *)((s8 *)this->bodies + 0x18) & 0xFFFFFFFE);
    switch (this->phase) {
    case 0:
        this->phase = 1;
        apply_actor_gravity((TObjEnemy *)this, (s32 *)(0), 0.0f);
        return;
    case 1:
        if (horizontal_distance_squared((saddr)(this->target + 0x2FC), (void *) (((u8 *)this) + 0x2FC)) < 40000.0f) {
            this->phase = 2;
        }
        return;
    case 2:
        this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
        this->m_374 = (s32) (this->m_374 | 2);
        break;
    }
}

#undef turn_toward_target__12TObjEneSaverFv

struct VBase800A64E8_800a64e8_800A4288 { char pad[0x14]; };
struct VObj800A64E8_800a64e8_800A4288 : VBase800A64E8_800a64e8_800A4288 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8();
};

struct Tgt_800A6B14 { u8 pad[0x2fc]; Vec pos; };

struct Obj_800A6B14 {
    u8 pad[0x60]; s32 angle;
    u8 pad2[0x2a8 - 0x64]; Tgt_800A6B14 *target;
    u8 pad3[0x2fc - 0x2ac]; Vec pos;
};

struct VBase_800A6C54_a { char pad[0x14]; };

struct VObj_800A6C54_a : VBase_800A6C54_a {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8();
};

struct VBase_800A677C { char pad[0x18]; };

struct VObj_800A677C : VBase_800A677C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16();
    virtual s32 m17(s32);
};

struct Obj_800A677C : VObj_800A677C {
    u16 f1C;
    u8 pad1E[0x30 - 0x1E];
    u32 f30;
    u8 pad34[0x2A8 - 0x34];
    u8 *target;
    u8 pad2AC[0x2FC - 0x2AC];
    Vec pos;
    u8 pad308[0x338 - 0x308];
    u16 f338;
    u8 pad33A[0x350 - 0x33A];
    f32 *range;
    u8 pad354[0x374 - 0x354];
    u32 f374;
    u32 target_class_mask;
};

extern "C" {
s32 rotate_matrix_x(int, void *);
extern f32 lbl_804FF5E8[];
s32 angle_diff_s16(s32, s32);
#define TObjPlayer__sub_800A42C0 ((s32 (*)(void*))(TObjPlayer__sub_800A42C0))
#define sub_800A435C__12TObjEneSaverFv ((s32 (*)(void*))(sub_800A435C__12TObjEneSaverFv))
#define update_entry_motion__12TObjEneSaverFv ((s32 (*)(void*))(update_entry_motion__12TObjEneSaverFv))
#define update_knockback_state__12TObjEneSaverFv ((s32 (*)(void*))(update_knockback_state__12TObjEneSaverFv))
void TObjPlayer__sub_800A49B4(TObjEneSaver *self);
#define update_move_toward_target__12TObjEneSaverFv ((s32 (*)(void*))(update_move_toward_target__12TObjEneSaverFv))
#define advance_motion_state__12TObjEneSaverFv ((s32 (*)(void*))(advance_motion_state__12TObjEneSaverFv))
void TObjPlayer__sub_8023DEE0(s16 *p, s16 a, s16 b, u16 id);
extern s32 actor_frame_tick;

void restore_scene_lighting(void);
void select_actor_lighting(s32 obj);
s32 matrix_mult_vec(int, Vec *, void *);
extern u8 identity_matrix[];
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

#define get_entity_id ((s32 (*)(void*))(get_entity_id))
void * create_ene_saver(void *arg0);
void *__ct__11TObjControlFP7TObject(void *, void *);
s32 lerp_angle_half__Fll(s32, s32);
s32 obj_setFlags30(void *, int);

void TObjEneSaver::run_move_action() {
    s32 temp_r4;
    void *temp_r3;
    void *temp_r3_2;

    switch (this->mode) {
    default:
        temp_r4 = this->m_374;
        if (temp_r4 & 4) {
            this->mode = 3;
            this->phase = 0;
            this->requested_action = 1;
            this->actorFlags = (s32) (this->actorFlags & 0xF9FBFFFF);
        } else if (temp_r4 & 1) {
            this->mode = 1;
            this->phase = 0;
            this->actorFlags = (s32) (this->actorFlags | 0x06040000);
        }
        temp_r3 = this->bodies;
        *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) | 1);
        return;
    case 1:
        if (this->m_374 & 2) {
            this->mode = 2;
            this->phase = 0;
            this->actorFlags = (s32) (this->actorFlags | 0x06040000);
        }
        return;
    case 2:
        if (this->m_374 & 4) {
            this->mode = 3;
            this->phase = 0;
            this->requested_action = 1;
            this->actorFlags = (s32) (this->actorFlags & 0xF9FBFFFF);
            return;
        }
        break;
    case 3:
        if (this->m_374 & 3) {
            this->mode = 1;
            this->phase = 0;
            this->actorFlags = (s32) (this->actorFlags | 0x06040000);
            this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
            this->m_374 = (s32) (this->m_374 | 1);
            temp_r3_2 = this->bodies;
            *(s32 *)((s8 *)temp_r3_2 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3_2 + 0x18) | 1);
            return;
        }
        break;
    }
}


struct VBase62D4 { char pad[0x14]; };
struct VObj62D4 : VBase62D4 {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
};


void TObjEneSaver::sub_800A62D4() {
    s16 temp_r4_2;

    this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
    this->actorFlags = (s32) (this->actorFlags | 0x06040000);
    this->m_374 = (s32) (this->m_374 & 0xFFFFFFF8);
    *(s32 *)((s8 *)this->bodies + 0x18) = (s32) (*(s32 *)((s8 *)this->bodies + 0x18) & 0xFFFFFFFE);
    this->advance_animation();
    switch (this->phase) {
    case 0:
    default:
        temp_r4_2 = *(s16 *)((s8 *)((u8 *)this) + 0x37E);
        *(s16 *)((s8 *)((u8 *)this) + 0x37E) = (temp_r4_2 + 1);
        if (30.0f < (f32) temp_r4_2) {
            this->phase = 1;
            this->scale.z = (f32) 1.0f;
            this->scale.y = (f32) 1.0f;
            this->scale.x = (f32) 1.0f;
            *(s16 *)((s8 *)((u8 *)this) + 0x37E) = 0;
            TObjPlayer__sub_800A04F0((void *) (((u8 *)this) + 0x3A4));
            apply_actor_gravity((TObjEnemy *)(this), (s32 *)(0), 0.0f);
            play_area_variant_sound((Vec *)((u8 *)this + 0x38));
        }
        break;
    case 1:
        this->scale.x = (f32) (this->scale.x - 0.1f);
        if (this->scale.x < 1e-5f) {
            this->scale.x = (f32) 0.0f;
        }
        this->scale.y += 0.1f;
        this->scale.z = (f32) this->scale.x;
        if (((VObj62D4 *) (((u8 *)this) + 0x3A4))->m4() == 1) {
            this->phase = 2;
        }
        break;
    case 2:
        this->set_position_from((void *) (((u8 *)this) + 0x50));
        this->update_prev_position();
        this->scale.z = (f32) 1.0f;
        this->scale.y = (f32) 1.0f;
        this->scale.x = (f32) 1.0f;
        this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
        this->m_374 = (s32) (this->m_374 | 1);
        break;
    }
    minimap_render_dot((void *) (((u8 *)this) + 0x38), -0x5DB4, 1, 0);
}
#define sub_800A62D4__12TObjEneSaverFv ((s32 (*)(void*))(sub_800A62D4__12TObjEneSaverFv))

void TObjEneSaver::init_render_flags() {
    u8 *self = (u8 *)this;
    u8 *temp_r3;

    ((TObjBase *)self)->set_position_from((u8 *)&this->home_position);
    ((TObjCollidable *)self)->refresh_collision_body_centers();
    *(s32 *)&(this->actorFlags) = (s32) (*(s32 *)&(this->actorFlags) & 0xFFDFFFFF);
    *(s32 *)&(this->actorFlags) = (s32) (*(s32 *)&(this->actorFlags) | 0x06040000);
    temp_r3 = (unsigned char *) (this->bodies);
    *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFFE);
}

void TObjEneSaver::run_idle_action() {
    u8 *self = (u8 *)this;
    u8 *temp_r3;

    switch (this->mode) {
    case 0:
        if (((VObj800A64E8_800a64e8_800A4288 *)(self + 0x3A4))->m8() != 0) {
            this->mode = 0xB;
            this->phase = 0;
            this->requested_action = 0;
            ((TObjBase *)self)->obj_clearFlags30(0x200000);
            obj_setFlags30(self, 0x06040000);
            this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
            this->m_374 = (s32) (this->m_374 | 0x40);
            temp_r3 = (unsigned char *) (this->bodies);
            *(s32 *)((s8 *)temp_r3 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r3 + 0x18) & 0xFFFFFFFE);
        }
        return;
    case 11:
        if (!(this->m_374 & 0x40)) {
            this->mode = 0;
            return;
        }
        break;
    default:
        this->mode = 0xB;
        this->phase = 0;
        this->requested_action = 0;
        ((TObjBase *)self)->obj_clearFlags30(0x200000);
        obj_setFlags30(self, 0x06040000);
        this->m_374 = (s32) (this->m_374 & 0xFFFF0000);
        this->m_374 = (s32) (this->m_374 | 0x40);
        break;
    }
}

#define P_800A677C(p) ((Obj_800A677C *)(p))

s32 TObjEneSaver::update_movement_status() {
    u8 *self = (u8 *)this;
    if (TObjChara::update_movement_status() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
        case 2:
        case 0xB:
            if (((VObj14 *)(self + 0x3A4))->m5() == 1) {
                this->m_374 &= ~0x43;
                this->m_374 |= 4;
                this->mode = 3;
                this->phase = 0;
                this->requested_action = 1;
                ((TObjBase *)self)->obj_clearFlags30(0x06240000);
            }
            break;
        }
        return 1;
    }
    return 0;
}

s32 TObjEneSaver::update_action_hold_status() {
    u8 *self = (u8 *)this;
    if (TObjChara::update_action_hold_status() != 0) {
        switch (this->mode) {
        case 0:
        case 1:
        case 2:
        case 0xB:
            if (((VObj14 *)(self + 0x3A4))->m5() == 1) {
                this->m_374 &= ~0x43;
                this->m_374 |= 4;
                this->mode = 3;
                this->phase = 0;
                this->requested_action = 1;
                ((TObjBase *)self)->obj_clearFlags30(0x06240000);
            }
            break;
        }
        return 1;
    }
    return 0;
}

void find_nearest_target__10TObjPlayerFPv(Obj_800A677C *self) {
    if (self->f374 & 0x40) {
        self->f338 = 0xFFFF;
        self->target = NULL;
        return;
    }
    if (self->m17(0x1E) == 0) {
        return;
    }
    if (((TObjCollidable *)self)->obj_testFlags30(0x10) != 0) {
        s32 best_id;
        s32 i;
        u8 *p;
        s32 id;
        f32 best;
        f32 d;
        u16 tid;
        i = 0;
        best_id = 0xFFFF;
        Vec v = lbl_8043A8B0;
        best = *self->range * *self->range;
        for (; i < registered_player_count + lbl_805D5870; i++) {
            p = (u8 *)TObjPlayer::get_player_data(i);
            if (p != NULL && p != (u8 *)self) {
                id = get_entity_id(p);
                if ((u16)id < 0x4000 && (u16)id != self->f1C && !(P_800A677C(p)->f30 & 0x02000800)) {
                    VecCopy((Vec *)&v, (const Vec *)((Vec *)(p + 0x2FC)));
                    subtract_vector(&v, &self->pos);
                    d = v.x * v.x + v.z * v.z;
                    if (d < best && check_path_obstructed(self, p + 0x2FC) != 1) {
                        best_id = id;
                        best = d;
                    }
                }
            }
        }
        self->f338 = best_id;
        tid = self->f338;
        if (tid < 0x1000U) {
            u8 *q = (u8 *)get_player_by_client_id(tid);
            if (q != NULL) {
                if (((TObjPlayer *)q)->get_floor() == get_current_floor()) {
                    self->target = q;
                    return;
                }
            }
            self->target = NULL;
            return;
        }
        if (tid < 0x4000U) {
            self->target = get_enemy_entity(tid);
        }
        return;
    }
    {
        s32 best_id2;
        s32 best_id;
        u8 *p;
        u8 *best_p2;
        u8 *best_p;
        s32 i;
        f32 best2;
        f32 best;
        f32 d;
        Vec v = lbl_8043A8BC;
        best_id = 0xFFFF;
        best_p2 = NULL;
        best_id2 = best_id;
        best_p = NULL;
        i = 0;
        best = *self->range * *self->range;
        best2 = best;
        for (; i < registered_player_count; i++) {
            p = (u8 *)TObjPlayer::get_player_data(i);
            if (p == NULL) continue;
            if ((u16)get_entity_id(p) >= 0x1000) continue;
            if (((TObjPlayer *)p)->get_floor() != get_current_floor()) continue;
            if (P_800A677C(p)->f30 & 0x02000800) continue;
            VecCopy((Vec *)&v, (const Vec *)((Vec *)(p + 0x2FC)));
            subtract_vector(&v, &self->pos);
            d = v.x * v.x + v.z * v.z;
            if ((((TObjPlayer *)p)->class_flags & self->target_class_mask) && d < best &&
                check_path_obstructed(self, p + 0x2FC) != 1) {
                best_id = get_entity_id(p);
                best = d;
                best_p = p;
            }
            if (d < best2 && check_path_obstructed(self, p + 0x2FC) != 1) {
                best_id2 = get_entity_id(p);
                best2 = d;
                best_p2 = p;
            }
        }
        if (best2 < 900.0f && best_p2 != NULL) {
            self->f338 = best_id2;
            self->target = best_p2;
            return;
        }
        if (best_p != NULL) {
            self->f338 = best_id;
            self->target = best_p;
            return;
        }
        if (best_p2 != NULL) {
            self->f338 = best_id2;
            self->target = best_p2;
            return;
        }
        self->f338 = 0xFFFF;
        self->target = NULL;
    }
}

void TObjEneSaver::turn_toward_target() {
    Vec d;
    VecCopy((Vec *)&d, (const Vec *)&((Obj_800A6B14 *)this)->target->pos);
    subtract_vector(&d, &((Obj_800A6B14 *)this)->pos);
    step_angle_clamped(this, angle_diff_s16(((Obj_800A6B14 *)this)->angle, (s32)(10430.38043493439 * atan2_float(d.x, d.z))));
}

void step_angle_clamped(void *self, s32 arg1) {
    s32 target_rot;

    target_rot = arg1;
    if (target_rot < -0x238E) {
        target_rot = -0x238E;
    } else if (target_rot > 0x238E) {
        target_rot = 0x238E;
    }
    *(s32 *)((s8 *)self + 0x39C) = lerp_angle_half__Fll(*(s32 *)((s8 *)self + 0x39C), target_rot);
}

extern void *tl_04;

void TObjPlayer::step_cutscene_frame(NJS_OBJECT *) {
    if ((s32) lbl_805D505C == 0x15) {
        rotate_matrix_x(0, (void *)lbl_805D5060);
    }
    if ((s32) lbl_805D505C == 0x1A) {
        *(f32 *)((s8 *)&lbl_80500978.value + 0) = (f32) 0.0f;
        *(f32 *)((s8 *)&lbl_80500978.value + 4) = (f32) 0.0f;
        *(f32 *)((s8 *)&lbl_80500978.value + 8) = (f32) 0.0f;
        TObjBoss2Tunnel::transform_vec_by_camera((saddr)&lbl_804FF5E8, (saddr)((void *)&lbl_80500978.value), (saddr)((void *)&lbl_80500978.value));
    }
    lbl_805D505C += 1;
}

void TObjEneSaver::render() {
    s32 v;
    u8 *self = (u8 *)this;
    v = this->classify_actor_view_detail(300.0f, 600.0f, 30.0f);
    if (v != 0) {
        select_actor_lighting((saddr)self);
        TObjFish::set_global_param(((TObjEneSaver *)self)->texlist);
        push_matrix_from(NULL);
        translate_matrix_vec3(0, (u8 *)&this->position);
        rotate_matrix_y(0, ((TObjEneSaver *)self)->rotation_y);
        lbl_805D505C = 0;
        lbl_805D5060 = *(s32 *)((s8 *)self + 0x39C);
        set_chunk_model_node_callback(TObjPlayer::step_cutscene_frame);
        TObjPlayer::toggle_particle_effect();
        switch (((TObjEneSaver *)self)->mode) {
        case 11:
            if (((TObjEneSaver *)self)->phase == 1) {
                scale_matrix_vec3(0, (u8 *)&this->scale);
            }
        case 1:
        case 2:
            if (((VObj_800A6C54_a *)(self + 0x3A4))->m8() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                ((VObj_800A6C54_a *)(self + 0x3A4))->m6();
                v = 1;
                model_render_flags |= 1;
                if (((TObject *)self)->defer_render() != 0) {
                    v = 0;
                }
                if (v != 0) {
                    ((TObjMotion *)self)->draw();
                }
                model_render_flags &= ~1;
                ((VObj_800A6C54_a *)(self + 0x3A4))->m7();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
            break;
        case 0:
            break;
        default:
            if (v == 1) {
                ((TObjMotion *)self)->draw();
            } else {
                ((TObjEnemy *)self)->draw_motion_model();
            }
            break;
        }
        TParticleCtrl::end_effect_render();
        set_chunk_model_node_callback(NULL);
        VecCopy((Vec *)((Vec *)(self + 0x390)), (const Vec *)((Vec *)&lbl_80500978));
        pop_matrix();
        restore_scene_lighting();
        if (!(*(s32 *)((s8 *)self + 0x374) & 1)) {
            ((TObjEnemy *)self)->draw_ground_shadow(0, 0);
        }
    } else {
        push_matrix_from(identity_matrix);
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, ((TObjEneSaver *)self)->rotation_y);
        set_motion_packed_rotation();
        ((TObjEnemy *)self)->calc_joint_matrices(((TObjEneSaver *)self)->frame);
        clear_motion_packed_rotation();
        pop_matrix();
        push_matrix_from(anim_model_matrix_array[26]);
        {
            Vec t = lbl_8043A8A4;
            matrix_mult_vec(0, &t, (u8 *)&this->_pad390);
        }
        pop_matrix();
    }
}

void TObjEneSaver::run_task() {
    s16 temp_r0;
    u8 *temp_r4;
    if ((s32) lbl_805D5058 != (s32) actor_frame_tick) {
        lbl_805D5058 = actor_frame_tick;
        TObjPlayer__sub_8023DEE0((s16 *)lbl_805D5054, 0xE, 0, 0);
    }
    if (TObjPlayer::check_demo_mode() == 1) {
        TObjPlayer__sub_800A42C0(this);
        return;
    }
    temp_r0 = this->mode;
    {
        switch (temp_r0) {
        case 0:
            this->init_render_flags();
            break;
        case 1:
            advance_motion_state();
            break;
        case 2:
            sub_800A5FA8();
            break;
        case 3:
            update_move_toward_target();
            break;
        case 4:
            TObjPlayer__sub_800A54B4((((u8 *)this)));
            break;
        case 5:
            TObjPlayer__sub_800A5154((this));
            break;
        case 6:
            sub_800A4D9C();
            break;
        case 7:
            TObjPlayer__sub_800A49B4(this);
            break;
        case 8:
            update_knockback_state();
            break;
        case 9:
            update_entry_motion();
            break;
        case 10:
            update_collapse_and_destroy();
            break;
        case 11:
            sub_800A62D4();
            break;
        }
    }
    temp_r4 = this->target;
    if ((temp_r4 != NULL) && (*(s32 *)((s8 *)temp_r4 + 0x30) & 0x02000800)) {
        *(s16 *)((s8 *)((u8 *)this) + 0x37E) = 0;
        this->actorFlags = (s32) (this->actorFlags & 0xFFDFFFFF);
        *(s32 *)((s8 *)((u8 *)this) + 0x374) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x374) & 0xFFFF0000);
        *(s32 *)((s8 *)((u8 *)this) + 0x374) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x374) | 0x40);
        this->target = NULL;
    }
    this->update_prev_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    sub_800A435C();
    this->m_2b4 += 1.0f;
}

void * create_ene_saver(void *arg0) {
    void *o;
    void *o2;
    o = TObject::operator new(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = TObject::operator new(0x3CC);
    if (o2 != NULL) {
        o2 = TObjEneSaver__ct((TObjEneSaver *)((u8 *)o2), (void *)o, (void *)arg0);
    }
    return o2;
}

void TObjPlayer::free_resources() {
    if ((u32) (*(u32 *)&player_object_ptr_array) != 0U) {
        mem_free((void*)(*(uaddr *)&player_object_ptr_array));
        (*(u32 *)&player_object_ptr_array) = 0U;
    }
    if ((u32) (*(u32 *)&lbl_805D5064) != 0U) {
        delete (SampledMotionPoints *)(*(uaddr *)&lbl_805D5064);
        (*(u32 *)&lbl_805D5064) = 0U;
    }
    if ((u32) (*(u32 *)&lbl_805D5068) != 0U) {
        delete (SampledMotionPoints *)(*(uaddr *)&lbl_805D5068);
        (*(u32 *)&lbl_805D5068) = 0U;
    }
    if ((u32) (*(u32 *)&lbl_805D506C) != 0U) {
        delete (SampledMotionPoints *)(*(uaddr *)&lbl_805D506C);
        (*(u32 *)&lbl_805D506C) = 0U;
    }
    if ((u32) saver_bml_resource != 0U) {
        delete (BmlResource *)saver_bml_resource;
        saver_bml_resource = 0U;
    }
}

#define saver_collision_body_part_table ((f32 *)saver_collision_body_part_table)
#define RES ((Res_800A715C *)saver_bml_resource)
void initialize_saver_resources(void) {
    Vec pos;
    Vec dir;
    void *r;
    r = new BmlResource(1, (BmlResourceDescriptor *)bm_ene_df1_saver_resource_descriptor, 0, 0, NULL);
    saver_bml_resource = (uaddr)r;
    lbl_805D5054 = *(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)((u8 *)((Res_800A715C *)r)->sub) + 8)) + 0x2C)) + 0x30)) + 4)) + 4);
    lbl_805D5058 = 0;
    lbl_805D505C = 0;
    lbl_805D5060 = 0;
    ((f32 *)&lbl_80500978)[2] = 0.0f;
    ((f32 *)&lbl_80500978)[1] = 0.0f;
    ((f32 *)&lbl_80500978)[0] = 0.0f;
    r = new SampledMotionPoints(2, 15.0f, 60.0f, 1.0f);
    lbl_805D5064 = (saddr)r;
    r = new SampledMotionPoints(2, 11.0f, 27.0f, 1.0f);
    lbl_805D5068 = r;
    r = new SampledMotionPoints(2, 0.0f, 7.0f, 1.0f);
    lbl_805D506C = (saddr)r;
    ((SampledMotionPoints *)lbl_805D5064)->sample_two_nodes((NJS_OBJECT *)RES->sub->f8, (NJS_MOTION *)(RES->ents[saver_action_table[2].motion].b), 0x20, 0x21);
    ((SampledMotionPoints *)lbl_805D5068)->sample_two_nodes((NJS_OBJECT *)RES->sub->f8, (NJS_MOTION *)(RES->ents[saver_action_table[4].motion].b), 0x20, 0x21);
    pos.x = pos.y = pos.z = 0.0f;
    dir.x = (-10.0f);
    dir.y = dir.z = 0.0f;
    ((SampledMotionPoints *)lbl_805D506C)->sample_node_offsets((NJS_OBJECT *)RES->sub->f8, (NJS_MOTION *)(RES->ents[saver_action_table[3].motion].b), 0x19, (const Vec *)&pos, (const Vec *)&dir);
    player_object_ptr_array = (void **)mem_alloc(0xC);
    saver_boss_stat_handle = TLobby::register_boss(0x52);
    player_object_ptr_array[0] = TLobby::dispatch_shared_handler_b(0x57);
    player_object_ptr_array[2] = TLobby::dispatch_shared_handler_b(0x58);
    player_object_ptr_array[1] = TLobby::dispatch_shared_handler_b(0x59);
    saver_object_stat_handle = TLobby::register_object(0x51);
    lbl_805D504C = (f32 *)TLobby::dispatch_shared_handler_a(0x51);
    NpcAnimationBinding init = saver_init_binding_desc;
    init.motions = reinterpret_cast<BmlMotionEntry *>(RES->ents);
    NpcModelRegistry::register_animated_chunk((s16)0x1A, reinterpret_cast<void *>(RES->sub->f8), reinterpret_cast<void *>(RES->sub->texlist), &init, (f32)saver_collision_body_part_table[3], (f32)0.0f);
}
Obj_800A73F8 *__dt__12TObjEneSaverFv(Obj_800A73F8 *arg0, s16 arg1) {
    s32 i;
    if (arg0 != NULL) {
        i = 0;
        arg0->vt = TObjEneSaver__vtable;
        do {
            if (arg0->items[i] != NULL) {
                ((TObject *)arg0->items[i])->queue_destruction();
                arg0->items[i] = NULL;
            }
            i++;
        } while (i < 3);
        free_collision_body_parts(arg0);
        __dt__13TUnk_80490470Fv((u8 *)arg0 + 0x3A4, -1);
        __dt__9TObjEnemyFv((TObjEnemy *)arg0, 0);
        if (arg1 > 0) {
            TObject::operator delete(arg0);
        }
    }
    return arg0;
}

u8 *TObjEneSaver__ct(TObjEneSaver *self, void *arg1, void *arg2) {
    s16 t;
    void *p;
    __ct__9TObjEnemyFP7TObject(self, arg1, arg2);
    *(u8 **)((s8 *)self + 0x18) = (u8 *)TObjEneSaver__vtable;
    __ct__13TUnk_80490470Fv(((u8 *)self + 0x3A4));
    ((TObjEneSaver *)self)->m_name = TObjEneSaver__class_name;
    self->apply_set_data(arg2);
    ((TObjPlayer *)self)->init_position_vectors();
    *(f32 *)((s8 *)self + 0x70) = 1.0f;
    self->scale.y = 1.0f;
    self->scale.x = 1.0f;
    t = (s16)(100.0f + *(f32 *)((s8 *)self + 0x354));
    *(s16 *)((s8 *)self + 0x388) = t;
    *(s16 *)((s8 *)self + 0x38A) = t;
    if (*(f32 *)((s8 *)self + 0x358) < 0.0f) {
        *(f32 *)((s8 *)self + 0x358) = 0.0f;
    } else if (8.0f < *(f32 *)((s8 *)self + 0x358)) {
        *(f32 *)((s8 *)self + 0x358) = 8.0f;
    }
    *(s32 *)((s8 *)self + 0x378) = 0;
    *(s32 *)((s8 *)self + 0x378) |= 1 << (s32)*(f32 *)((s8 *)self + 0x358);
    self->mode = 0;
    self->phase = 0;
    self->variant = 0;
    ((TObjEnemy *)self)->set_param(0x1E);
    self->subtype = 0;
    self->sub_800A7734(self->variant);
    self->action_table = saver_action_table;
    ((TObjMotion *)self)->set_field_d8((saddr)self->action_table);
    *(s32 *)((s8 *)self + 0xDC) = *(s32 *)((s8 *)(*(u8 * *)&saver_bml_resource) + 0x430);
    self->requested_action = 0;
    ((TObjMotion *)self)->set_animation(self->requested_action);
    ((TObjMotion *)self)->set_field_b8(self->requested_action);
    init_collision_body_parts(self, (u8 *)saver_collision_body_part_table, 1);
    *(s16 *)((s8 *)self + 0x37C) = 0;
    *(s16 *)((s8 *)self + 0x37E) = 0;
    ((TObjEnemy *)self)->bind_enemy_combat_stats((u8 *)saver_boss_stat_handle, (u8 *)(player_object_ptr_array[*(s16 *)((s8 *)self + 0x37C)]), (u8 *)saver_object_stat_handle);
    self->movementParameters = (u8*)lbl_80490B28;
    self->referenceHp = self->hp;
    ((TObjEnemy *)self)->update_prev_position();
    ((TBoss3VoloptHiraisin *)self)->copy_position();
    initialize_enemy_photon_effect(self);
    *(s32 *)((s8 *)self + 0x374) = 1;
    *(s32 *)((s8 *)self + 0x38C) = 0;
    VecCopy((Vec *)((u8 *)self + 0x390), (const Vec *)((u8 *)self + 0x2FC));
    *(s32 *)((s8 *)self + 0x39C) = 0;
    ((TObjChara *)self)->add_flags_2e4(8);
    self->actorFlags |= 0x06040000;
    self->m_380 = 0x101;
    self->m_384 = 0x101;
    p = new TEneParticleCtrl(self, self->m_380);
    *(void **)((s8 *)self + 0x3A0) = p;
    *(s32 *)((s8 *)self + 0x3C0) = (saddr)TUnk_80494968::create(0xA0303030, 0xFFFF0088);
    *(s32 *)((s8 *)self + 0x3C4) = (saddr)TUnk_80494968::create(0xA0303030, 0xFFFF0088);
    *(s32 *)((s8 *)self + 0x3C8) = (saddr)TUnk_80494968::create(0xA0303030, 0xFF303030);
    self->clear_lobby_object_state();
    return (u8 *)self;
}

void *TObjEneSaver::get_center() { return (char*)this + 0x2fc; }
void TObjEneSaver::sub_800A7734(s32 i) {
    ((O_800A7734 *)this)->x34 = (*(G_800A7734 * *)&saver_bml_resource)->tbl[i].x8;
    ((O_800A7734 *)this)->x24 = (*(G_800A7734 * *)&saver_bml_resource)->tbl[i].xc;
}

}
#undef TObjPlayer__sub_800A42C0
#undef sub_800A435C__12TObjEneSaverFv
#undef update_entry_motion__12TObjEneSaverFv
#undef update_knockback_state__12TObjEneSaverFv
#undef update_move_toward_target__12TObjEneSaverFv
#undef advance_motion_state__12TObjEneSaverFv
#undef sub_800A62D4__12TObjEneSaverFv
#undef get_entity_id
