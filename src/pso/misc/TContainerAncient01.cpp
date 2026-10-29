#include "types.h"
#include "pso/map/FloorArea.h"
static const f32 TContainerAncient01__data_805DBD10[1] = {1.0f};
static const f32 TContainerAncient01__data_805DBD14[1] = {0.0f};
#include "types.h"
#include "pso/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TContainerAncient01R.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/system/vector.h"

#include "pso/misc/TContainerAncient01.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/object/TObjFish.h"

struct Base_8018AC68_8018A584 { char pad[0x18]; };
struct VObj_8018AC68_8018A584 : Base_8018AC68_8018A584 {
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
    virtual void m18();
    virtual void m19();
    virtual void m20(s32, f32);
};
struct VBase8018AD04_8018A584 { char pad[0x18]; };
struct VObj8018AD04_8018A584 : VBase8018AD04_8018A584 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_8018A9D8_TContainerAncient01__data_804B6DC0 { s32 value; u8 remaining[0x28]; };

struct Obj_8018AB44 { u8 pad0[0x38]; u8 pos[0x328]; s32 f360; };

struct Atk_8018A584 { s32 type; f32 power; s32 kind; f32 base; };

struct VBase_8018A584 { u8 pad[0x18]; };

struct Player_8018A584 : VBase_8018A584 {
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
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21(void *, Atk_8018A584 *, s32, s32, s32);
    u8 pad1c[0x38 - 0x1C];
    f32 pos[3];
};

struct Obj_8018A584 { u8 pad[0x38]; f32 pos[3]; };

struct Obj_8018A688 {
    u8 pad[0x2B4];
    f32 x2b4;
    u8 pad2b8[0x340 - 0x2B8];
    f32 x340;
    f32 x344;
    u8 x348[0xC];
    u8 x354[0x370 - 0x354];
    u32 x370;
};
struct Player_8018A914 { u8 pad[0x38]; f32 pos[3]; };
struct Obj_8018A914 {
    u8 pad[0x38];
    f32 pos[3];
    u8 pad44[0xB8 - 0x44];
    s16 xb8;
    u8 padba[0x2B4 - 0xBA];
    f32 x2b4;
    u8 pad2b8[0x326 - 0x2B8];
    s16 state;
    u8 pad328[0x33C - 0x328];
    f32 x33c;
};
struct RecoveredGlobal_8018B5D0_TContainerAncient01__data_804B6DC0 {
    s32 value;
    u8 remaining[0x28];
};

struct Obj_8018B510 { u8 pad0[0x38]; u8 pos[0x7C]; s16 fB4[3]; u8 pad1[0x1FA]; f32 f2B4; u8 pad2[0x6E]; s16 state; u8 pad3[0x10]; f32 f338; };

struct Obj_8018B700 { u8 pad0[0x38]; u8 pos[0x324]; s32 f35C; };

struct Atk_8018B180 { s32 type; f32 power; s32 kind; f32 base; };

struct VBase_8018B180 { u8 pad[0x18]; };

struct Player_8018B180 : VBase_8018B180 {
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
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21(void *, Atk_8018B180 *, s32, s32, s32);
    u8 pad1c[0x38 - 0x1C];
    f32 pos[3];
};

struct Obj_8018B180 { u8 pad[0x38]; f32 pos[3]; };

struct Obj_8018B180;
struct Obj_8018B284 {
    u8 pad0[0x38];
    u8 pos[0x2B4 - 0x38];
    f32 f2B4;
    u8 pad2B8[0x33C - 0x2B8];
    f32 f33C;
    f32 f340;
    u8 f344[0xC];
    u8 f350[0x36C - 0x350];
    u32 f36C;
};

struct Vec_8018B030 { f32 x, y, z; };
struct Coll_8018B030 { f32 x; f32 y; };
struct Res_8018B030 { u8 pad[0x430]; s32 x430; };

struct VBase_8018B030 { u8 pad[0x18]; };
struct Obj_8018B030 : VBase_8018B030 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(void *);
    u8 pad1c[0x24 - 0x1C];
    s32 x24;
    u8 pad28[0x30 - 0x28];
    u32 flags;
    s32 x34;
    Vec_8018B030 pos;
    u8 pad44[0x74 - 0x44];
    Vec_8018B030 pos74;
    u8 pad80[0xB8 - 0x80];
    s16 anim;
    u8 padba[0xD8 - 0xBA];
    void *animTbl;
    s32 xdc;
    u8 pade0[0x2FC - 0xE0];
    Vec_8018B030 pos2fc;
    u8 pad308[0x326 - 0x308];
    s16 state;
};

extern "C" {
void __ct__9TObjCharaFP7TObject(void *, void *, void *);
s32 TObjFish__sub_8001EDB0(int, int);
void init_collision_body_parts(void *, void *, int);
extern s32 TContainerAncient01R__name;

void queue_destruction__7TObjectFv(void *);
u32 get_bml_motion(int, int);
s32 get_bml_model(int, int);
s32 submit_cursor_candidate(void *, int, f32);
s32 run_task__7TObjectFv(void *);
extern s32 TContainerAncient01R__bml_resource;

void run_task__20TContainerAncient01RFv(u8 *arg0);
f32 xyz_distance_squared(void *, void *, void *);

s32 is_within_range__19TContainerAncient01Fii(s32 arg0, s32 arg1);
void advance_animation_playback(void *);
unsigned int __cvt_fp2unsigned(f32);

f32 receive_physical_attack__20TContainerAncient01RFPvf(u8 *arg0);

extern s32 TContainerAncient01__open_effect_table[];
s32 obj_testFlags30__14TObjCollidableFUl(void *, s32);
s32 get_current_floor();
f32 horizontal_distance_squared(void *, void *);

void TContainerAncient01__sub_8018A584(Obj_8018A584 *self, f32 range);

void *get_player_by_client_id(s32 i);
s32 play_sound_effect(int, void *, int, int);

extern s32 registered_player_count;

s32 TContainerAncient01__sub_8018BE90(void);

void *spawn_particle_effect(void *pos, s32 id);
extern s32 TContainerAncient01__effect_id_table[];
void TContainerAncient01__sub_8018B180(Obj_8018B180 *self, f32 range);

int calc_distance_accuracy_penalty__20TContainerAncient01RFPvPvPvf(void);
f32 receive_direct_attack__20TContainerAncient01RFPv19DirectAttackPayloadPvll(void *arg0, s32 arg1, s32 *arg2);
void render__20TContainerAncient01RFv(u8 *arg0);
void vfunc_6__20TContainerAncient01RFPsl(void *arg0, s16 *arg1, s32 arg2);
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
void draw_ginja_object(void *child);
s32 draw_ginja_model_with_motion(s32, s32, f32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();

void *TContainerAncient01R__create(void *arg0);
void TContainerAncient01R__sub_8018AF74(void);
void *dt__20TContainerAncient01RFPvs(void *arg0, s16 arg1);
void *TContainerAncient01R__ct(Obj_8018B030 *, void *, void *);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

extern "C" void receive_weapon_special_attack__20TContainerAncient01RFPvPv();
extern "C" void apply_knockback_from_attacker__20TContainerAncient01RFPUcf();
extern "C" void try_start_action__20TContainerAncient01RFll();
extern "C" void roll_physical_accuracy__20TContainerAncient01RFPvlf();
extern "C" void vfunc_29__9TObjCharaFv();
extern "C" void vfunc_74__9TObjCharaFl();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void vfunc_28__9TObjCharaFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void vfunc_67__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void vfunc_63__9TObjCharaFv();
extern "C" void vfunc_62__9TObjCharaFv();
extern "C" void vfunc_61__9TObjCharaFv();
extern "C" void vfunc_60__9TObjCharaFv();
extern "C" void vfunc_59__9TObjCharaFv();
extern "C" void vfunc_58__9TObjCharaFv();
extern "C" void apply_slow_status__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void interact__14TObjCollidableFl();
extern "C" void get_name__8TObjBaseFv();
extern "C" void add_actor_exp__9TObjCharaFl();
extern "C" void apply_action_hold_status__9TObjCharaFf();
extern "C" void apply_anti_technique__9TObjCharaFl();
extern "C" void apply_attack_stat_status__9TObjCharaFPv();
extern "C" void apply_confusion_status__9TObjCharaFv();
extern "C" void apply_movement_ailment__9TObjCharaFl();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void apply_paralysis__9TObjCharaFv();
extern "C" void apply_poison_status__9TObjCharaFv();
extern "C" void apply_shock_status__9TObjCharaFv();
extern "C" void apply_switch_attack__9TObjCharaFv();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void clear_harmful_statuses__9TObjCharaFv();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
extern "C" void vfunc_78__9TObjCharaFl();
extern "C" void vfunc_77__9TObjCharaFv();
extern "C" void vfunc_76__9TObjCharaFv();
extern "C" void vfunc_75__9TObjCharaFf();
extern "C" void get_center__9TObjCharaFv();
extern "C" void get_actor_level_index__9TObjCharaFv();
extern "C" void get_pos__9TObjCharaFl();
extern "C" void is_actor_cadence_frame__9TObjCharaFl();
extern "C" void is_target_in_attack_range__9TObjCharaFv();
extern "C" u8 lbl_80444F98[];
extern "C" u8 lbl_80444FAC[];
extern "C" u8 lbl_80444FC4[];
extern "C" u8 lbl_80444FDC[];
extern "C" u8 lbl_80444FF4[];
extern "C" u8 lbl_8044500C[];
extern "C" u8 lbl_80445020[];
extern "C" u8 lbl_80445034[];
extern "C" u8 lbl_80445048[];
extern "C" u8 lbl_8044505C[];
extern "C" void render_shadows__7TObjectFv();
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void update_action_hold_status__9TObjCharaFv();
extern "C" s32 vfunc_37__9TObjCharaFv(u8 *arg0);
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_movement_status__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
extern void *fe_obj_h_s_konte_model_names[3];
extern void *fe_obj_h_s_konte_motion_names[3];
extern void *bm_obj_geenest_model_names[3];
extern void *bm_obj_geenest_motion_names[3];
void *fe_obj_h_s_konte_model_names[3] = {
    (void *)&lbl_80444F98, (void *)&lbl_80444FAC, (void *)0x0,
};
void *fe_obj_h_s_konte_motion_names[3] = {
    (void *)&lbl_80444FC4, (void *)&lbl_80444FDC, (void *)0x0,
};
void *TContainerAncient01__resource_descriptor[4] = {
    (void *)&lbl_80444FF4, (void *)&fe_obj_h_s_konte_model_names, (void *)&fe_obj_h_s_konte_motion_names, (void *)0x20002,
};
void *bm_obj_geenest_model_names[3] = {
    (void *)&lbl_8044500C, (void *)&lbl_80445020, (void *)0x0,
};
void *bm_obj_geenest_motion_names[3] = {
    (void *)&lbl_80445034, (void *)&lbl_80445048, (void *)0x0,
};
void *TContainerAncient01__resource_descriptor_2[4] = {
    (void *)&lbl_8044505C, (void *)&bm_obj_geenest_model_names, (void *)&bm_obj_geenest_motion_names, (void *)0x20002,
};
void *TContainerAncient01__collision_body_parts[11] = {
    (void *)0x0, (void *)0x41000000, (void *)0x0, (void *)0x41200000,
    (void *)0x41200000, (void *)0x0, (void *)0x38003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
TObjMotionAction TContainerAncient01__anim_table[3] = {
    {1, 0, 0, 1.0f, 1},
    {1, 0, 0, 6.0f, 1},
    {2, 0, 1, 1.0f, 4},
};
void *__vt__20TContainerAncient01R[79] = {
    (void *)0x0, (void *)0x0, (void *)&dt__20TContainerAncient01RFPvs, (void *)&run_task__20TContainerAncient01RFv,
    (void *)&render__20TContainerAncient01RFv, (void *)&render_shadows__7TObjectFv, (void *)&vfunc_6__20TContainerAncient01RFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__8TObjBaseFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&is_within_range__19TContainerAncient01Fii, (void *)&calc_distance_accuracy_penalty__20TContainerAncient01RFPvPvPvf, (void *)&receive_physical_attack__20TContainerAncient01RFPvf, (void *)&receive_direct_attack__20TContainerAncient01RFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__20TContainerAncient01RFPvPv, (void *)&apply_knockback_from_attacker__20TContainerAncient01RFPUcf, (void *)&try_start_action__20TContainerAncient01RFll, (void *)&roll_physical_accuracy__20TContainerAncient01RFPvlf,
    (void *)&vfunc_28__9TObjCharaFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__9TObjCharaFv, (void *)&apply_paralysis__9TObjCharaFv, (void *)&apply_slow_status__9TObjCharaFv, (void *)&apply_confusion_status__9TObjCharaFv,
    (void *)&apply_movement_ailment__9TObjCharaFl, (void *)&apply_shock_status__9TObjCharaFv, (void *)&clear_harmful_statuses__9TObjCharaFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__9TObjCharaFv, (void *)&vfunc_62__9TObjCharaFv, (void *)&vfunc_63__9TObjCharaFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjCharaFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl,
};
#define TContainerAncient01__collision_body_parts (*(RecoveredGlobal_8018A9D8_TContainerAncient01__data_804B6DC0 *)TContainerAncient01__collision_body_parts)
#define __vt__20TContainerAncient01R ((s32 *)__vt__20TContainerAncient01R)

void TContainerAncient01__sub_8018A584(Obj_8018A584 *self, f32 range) {
    u16 i;
    Player_8018A584 *pl;
    for (i = 0; i < 4; i++) {
        pl = (Player_8018A584 *)get_player_by_client_id(i);
        if (pl != NULL) {
            if (((TObjPlayer *)pl)->get_field_3e4() == get_current_floor() && obj_testFlags30__14TObjCollidableFUl(pl, 1) == 0 &&
                horizontal_distance_squared(self->pos, pl->pos) < range) {
                Atk_8018A584 atk;
                atk.type = 0xF;
                atk.base = 1e+02f;
                atk.kind = 0xF;
                *(s32 *)&atk.power = *(s32 *)&atk.base;
                pl->m21(self, &atk, 0, -1, -1);
            }
        }
    }
}

void TContainerAncient01R::reset_hp() { this->mode = 0; this->requested_action = this->mode; this->m_2b4 = (-1.0f); }

s32 TContainerAncient01R::sub_8018A688() {
    Obj_8018A688 *self = (Obj_8018A688 *)this;
    u32 period;
    f32 t;
    u32 rem;

    advance_animation_playback(self);
    if (1e+01f == this->m_2b4) {
        switch (get_current_floor_area()) {
        case AREA_CENTRAL_CONTROL_AREA:
        case AREA_JUNGLE_NORTH:
        case AREA_JUNGLE_EAST:
        case AREA_MOUNTAIN:
        case AREA_SEASIDE:
            play_sound_effect(0x4BC1C, (u8 *)self + 0x38, 0, 0);
            break;
        case AREA_SEASIDE_NIGHT:
            play_sound_effect(0x4004BC1C, (u8 *)self + 0x38, 0, 0);
            break;
        case AREA_TOWER:
            play_sound_effect(0x4004BC1C, (u8 *)self + 0x38, 0, 0);
            break;
        default:
            play_sound_effect(0x4004BC16, (u8 *)self + 0x38, 0, 0);
            break;
        }
    }
    if (1e+01f == this->m_2b4 || 12.0f == this->m_2b4 || 14.0f == this->m_2b4) {
        TContainerAncient01::trigger_spawn(self, self->x354, (void *)0x7D);
    }
    if (4e+01f == this->m_2b4) {
        TContainerAncient01::trigger_spawn(self, self->x348, (void *)0x7E);
    }
    period = __cvt_fp2unsigned(3e+01f / this->m_370);
    t = this->m_2b4;
    rem = (u32)t % period;
    if (14.0f < t && t < 6e+01f && rem == 0) {
        TContainerAncient01::trigger_spawn(self, self->x354, (void *)0x7E);
    }
    if (6e+01f < this->m_2b4 && rem == 0) {
        TContainerAncient01::trigger_spawn(self, self->x348, (void *)0x7E);
    }
    TContainerAncient01__sub_8018A584((Obj_8018A584 *)self, this->m_344);
    if (self->x340 <= this->m_2b4) {
        ((TContainerAncient01R *)self)->reset_hp();
    }
}

void TContainerAncient01R::update_spawning() {
    u8 *arg0 = (u8 *)this;
  advance_animation_playback(arg0);
  if ((__cvt_fp2unsigned(this->m_2b4) % 15) == 0)
  {
    TContainerAncient01::trigger_spawn(arg0, (u8 *)&this->unk_348, (void *) 0x7D);
  }
  if (6e+01f <= (this->m_2b4))
  {
    this->mode = 2;
    this->requested_action = this->mode;
    this->m_2b4 = (f32) (-1.0f);
  }
}

void TContainerAncient01R::check_open_trigger() {
    Obj_8018A914 *self = (Obj_8018A914 *)this;
    s32 hit;
    u16 i;
    Player_8018A914 *pl;
    f32 range;

    advance_animation_playback(self);
    hit = 0;
    if (this->m_33c <= this->m_2b4) {
        hit = 1;
    } else {
        range = 6.4e+03f;
        for (i = 0; i < registered_player_count; i++) {
            pl = (Player_8018A914 *)get_player_by_client_id(i);
            if (pl != NULL && horizontal_distance_squared(self->pos, pl->pos) < range) {
                hit = 1;
            }
        }
    }
    if (hit != 0) {
        this->mode = 1;
        this->requested_action = this->mode;
        this->m_2b4 = (-1.0f);
    }
}

#pragma push
#pragma fp_contract on
void TContainerAncient01::init_positions() {
    u8 *arg0 = (u8 *)this;
    this->m_33c = (f32) (3e+02f + (this->scale.x - TContainerAncient01__data_805DBD10[0]));
    *(f32 *)&this->unk_340 = (f32) (2.1e+02f + (this->scale.y - TContainerAncient01__data_805DBD10[0]));
    this->m_344 = (f32) (4e+02f + (this->scale.z - TContainerAncient01__data_805DBD10[0]));
    *(s32 *)((s8 *)arg0 + 0x370) = (s32) (*(s32 *)&this->set_params[2] + 4);
    VecCopy((Vec *)&this->unk_348, (const Vec *)&this->position);
    this->m_34c = (f32) (this->m_34c + *(f32 *)((s8 *)&TContainerAncient01__collision_body_parts.value + 4));
    VecCopy((Vec *)&this->m_354, (const Vec *)&this->unk_348);
    *(f32 *)&this->unk_358 = (f32) ((1.25f * *(f32 *)((s8 *)&TContainerAncient01__collision_body_parts.value + 4)) + *(f32 *)&this->unk_358);
    *(s32 *)&this->m_360 = 0;
    *(f32 *)&this->unk_364 = (f32) TContainerAncient01__data_805DBD10[0];
    this->m_368 = (f32) TContainerAncient01__data_805DBD10[0];
    *(f32 *)&this->unk_36C = (f32) TContainerAncient01__data_805DBD10[0];
    this->hp = (s16) this->rotation_z;
    if ((s16) this->hp < 1) {
        this->hp = 1;
    }
    this->m_338 = 0;
}
#pragma pop

void TContainerAncient01R::vfunc_6(s16 *arg1, s32 arg2) {
    this->m_338 = (s16) *arg1;
    if (arg2 != 0) {
        if ((this->hp - this->m_338) <= 0) {
            this->reset_hp();
            this->open_container();
            this->m_360 = 1;
        }
    } else if ((this->hp - this->m_338) <= 0) {
        this->m_360 = 1;
    }
}

void TContainerAncient01R::open_container() {
    Obj_8018AB44 *arg0 = (Obj_8018AB44 *)this;
    if (arg0->f360 == 0) {
        arg0->f360 = 1;
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
        TContainerAncient01::trigger_spawn((void *)arg0, (void *)arg0->pos, (void *)TContainerAncient01__open_effect_table[0]);
        TContainerAncient01::trigger_spawn((void *)arg0, (void *)arg0->pos, (void *)TContainerAncient01__open_effect_table[1]);
        if (TContainerAncient01::is_global_state_in_table() == 0) {
            ((TObjChara *)arg0)->request_box_item_drop(arg0->pos, 1);
        }
        ((TObjCollidable *)arg0)->set_flag8();
    }
}

f32 TContainerAncient01R::receive_physical_attack(void *, f32) {
    u8 *arg0 = (u8 *)this;
    s16 sp8;
    if ((u16) this->entity_id >= 0x1000U) {
        this->m_338 = (this->m_338 + 1);
        if (((u32) this->set_entry != 0U) && (((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 1) != 0)) {
            sp8 = this->m_338;
            ((TObjCollidable *)arg0)->access_object_saved_state(&sp8, 0);
            ((TObjCollidable *)arg0)->send_object_state_update(&sp8);
        }
    }
    return TContainerAncient01__data_805DBD14[0];
}

f32 TContainerAncient01R::receive_direct_attack(void *arg1, DirectAttackPayload payload, void *, s32, s32) {
    s32 temp_r4;
    struct VObj_8018AC68_8018A584 *o = (struct VObj_8018AC68_8018A584 *)this;

    temp_r4 = payload.kind;
    if ((temp_r4 == 0) || ((temp_r4 - 1) <= 3U) || (temp_r4 == 0x13)) {
        o->m20(0, TContainerAncient01__data_805DBD10[0]);
    }
    return TContainerAncient01__data_805DBD14[0];
}

int TContainerAncient01R::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }

s32 is_within_range__19TContainerAncient01Fii(s32 arg0, s32 arg1) {
    return xyz_distance_squared((void *)(arg1 + 0x38), (void *)(arg0 + 0x38), (void *)arg0) < 4e+02f;
}

void TContainerAncient01R::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj8018AD04_8018A584 *) arg0)->m8(3e+02f, 2e+01f) != 0) {
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) this->m_360 != 0) {
            scale_current_matrix((u8 *)&this->unk_364);
        }
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_ginja_object(this->model);
        } else {
            draw_ginja_model_with_motion(*(s32 *)&this->model, *(s32 *)&this->current_motion, this->frame);
        }
        pop_matrix();
    }
}
void TContainerAncient01R::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    f32 temp_f1_2;
    if (TObjPlayer::check_demo_mode() == 0) {
        if ((s32) this->m_360 == 0) {
            switch (this->mode) {
            case 0:
                ((TContainerAncient01R *)arg0)->check_open_trigger();
                break;
            case 1:
                ((TContainerAncient01R *)arg0)->update_spawning();
                break;
            case 2:
                ((TContainerAncient01R *)arg0)->sub_8018A688();
                break;
            default:
                this->mode = 0;
                this->requested_action = (s16) this->mode;
                this->m_2b4 = (f32) (-1.0f);
                ((TContainerAncient01R *)arg0)->check_open_trigger();
                break;
            }
            temp_f1 = this->m_2b4;
            this->m_2b4 = (f32) (temp_f1 + TContainerAncient01__data_805DBD10[0]);
            submit_cursor_candidate(arg0, -1, temp_f1);
        } else {
            temp_f1_2 = this->m_368;
            if (temp_f1_2 <= 0.2f) {
                *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C) - 0.025f);
                if (*(f32 *)((s8 *)arg0 + 0x3C) <= ((-1e+01f) * this->m_368)) {
                    queue_destruction__7TObjectFv(arg0);
                }
            } else {
                this->m_368 = (f32) (temp_f1_2 - 0.025f);
            }
        }
    }
    if ((u32) this->current_motion == get_bml_motion(TContainerAncient01R__bml_resource, 0)) {
        *(s32 *)&this->model = get_bml_model(TContainerAncient01R__bml_resource, 0);
    }
    if ((u32) this->current_motion == get_bml_motion(TContainerAncient01R__bml_resource, 1)) {
        *(s32 *)&this->model = get_bml_model(TContainerAncient01R__bml_resource, 1);
    }
    run_task__7TObjectFv(arg0);
}

extern void *tl_05;

void *TContainerAncient01R__create(void *parent) {
    void *o = __nw__7TObjectFUl(0x374);
    if (o != NULL) {
        o = TContainerAncient01R__ct((Obj_8018B030 *)o, tl_05, parent);
    }
    return o;
}

void TContainerAncient01R__sub_8018AF74(void) { TContainerAncient01R__bml_resource = 0; }

void TContainerAncient01R::init_table_entries() {
    TContainerAncient01R__bml_resource = TContainerAncient01__sub_8018BE90();
    TContainerAncient01__open_effect_table[0] = TContainerAncient01::get_table_entry(0);
    TContainerAncient01__open_effect_table[1] = TContainerAncient01::get_table_entry(1);
}

void *dt__20TContainerAncient01RFPvs(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TContainerAncient01R;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__9TObjCharaFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
void *TContainerAncient01R__ct(Obj_8018B030 *self, void *arg1, void *parent) {
    Coll_8018B030 *c;

    __ct__9TObjCharaFP7TObject(self, arg1, parent);
    *(void **)((u8 *)self + 0x18) = (void *)__vt__20TContainerAncient01R;
    *(s32 *)self = TContainerAncient01R__name;
    self->m5(parent);
    self->x34 = get_bml_model(TContainerAncient01R__bml_resource, 0);
    self->x24 = TObjFish__sub_8001EDB0(TContainerAncient01R__bml_resource, 0);
    self->animTbl = (void *)TContainerAncient01__anim_table;
    ((TObjMotion *)self)->set_field_d8((s32)self->animTbl);
    self->xdc = ((Res_8018B030 *)TContainerAncient01R__bml_resource)->x430;
    self->anim = 0;
    ((TObjMotion *)self)->set_animation(self->anim);
    ((TObjMotion *)self)->set_field_b8(self->anim);
    self->flags |= 0x60000000;
    init_collision_body_parts(self, (void *)&TContainerAncient01__collision_body_parts, 1);
    ((TObjPlayer *)self)->register_object_by_id();
    VecCopy((Vec *)&self->pos74, (const Vec *)&self->pos);
    c = (Coll_8018B030 *)&TContainerAncient01__collision_body_parts;
    self->pos74.y = c->y / 2.0f + self->pos74.y;
    VecCopy((Vec *)&self->pos2fc, (const Vec *)&self->pos74);
    self->state = 0;
    ((TContainerAncient01 *)self)->init_positions();
    return self;
}
#pragma pop

void TContainerAncient01::spawn_effect(void* p, void* a1, void* a2) { spawn_particle_effect(a1, (s32)a2); }

void TContainerAncient01__sub_8018B180(Obj_8018B180 *self, f32 range) {
    u16 i;
    Player_8018B180 *pl;
    for (i = 0; i < 4; i++) {
        pl = (Player_8018B180 *)get_player_by_client_id(i);
        if (pl != NULL) {
            if (((TObjPlayer *)pl)->get_field_3e4() == get_current_floor() && obj_testFlags30__14TObjCollidableFUl(pl, 1) == 0 &&
                horizontal_distance_squared(self->pos, pl->pos) < range) {
                Atk_8018B180 atk;
                atk.type = 0xF;
                atk.base = 1e+02f;
                atk.kind = 0xF;
                *(s32 *)&atk.power = *(s32 *)&atk.base;
                pl->m21(self, &atk, 0, -1, -1);
            }
        }
    }
}

void TContainerAncient01::reset_state() { this->mode = 0; this->requested_action = this->mode; this->m_2b4 = (-1.0f); }

void TContainerAncient01::sub_8018B284() {
    Obj_8018B284 *self = (Obj_8018B284 *)this;
    u32 period;
    u32 phase;
    f32 t;
    advance_animation_playback(self);
    if (1e+01f == this->m_2b4) {
        switch (get_current_floor_area()) {
        case AREA_CENTRAL_CONTROL_AREA:
        case AREA_JUNGLE_NORTH:
        case AREA_JUNGLE_EAST:
        case AREA_MOUNTAIN:
        case AREA_SEASIDE:
            play_sound_effect(0x4BC1C, self->pos, 0, 0);
            break;
        case AREA_SEASIDE_NIGHT:
            play_sound_effect(0x4004BC1C, self->pos, 0, 0);
            break;
        case AREA_TOWER:
            play_sound_effect(0x4004BC1C, self->pos, 0, 0);
            break;
        default:
            play_sound_effect(0x4004BC16, self->pos, 0, 0);
            break;
        }
    }
    if (1e+01f == this->m_2b4 || 12.0f == this->m_2b4 || 14.0f == this->m_2b4) {
        TContainerAncient01::spawn_effect(self, self->f350, (void *)0x7D);
    }
    if (4e+01f == this->m_2b4) {
        TContainerAncient01::spawn_effect(self, self->f344, (void *)0x7E);
    }
    period = (u32)(3e+01f / (f32)self->f36C);
    phase = (u32)(t = this->m_2b4) % period;
    if (14.0f < t && t < 6e+01f && phase == 0) {
        TContainerAncient01::spawn_effect(self, self->f350, (void *)0x7E);
    }
    if (6e+01f < this->m_2b4 && phase == 0) {
        TContainerAncient01::spawn_effect(self, self->f344, (void *)0x7E);
    }
    TContainerAncient01__sub_8018B180((Obj_8018B180 *)self, self->f340);
    if (this->m_33c <= this->m_2b4) {
        ((TContainerAncient01 *)self)->reset_state();
    }
}

void TContainerAncient01::sub_8018B48C() {
    u8 *arg0 = (u8 *)this;
  advance_animation_playback(arg0);
  if (((__cvt_fp2unsigned(this->m_2b4) & 0xFFFFFFFF) % 15) == 0)
  {
    TContainerAncient01::spawn_effect(arg0, (u8 *)&this->m_344, (void*)((void *) 0x7D));
  }
  if (6e+01f <= (this->m_2b4))
  {
    this->mode = 2;
    this->requested_action = this->mode;
    this->m_2b4 = (f32) (-1.0f);
  }
}

#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_8018B5D0_TContainerAncient01__data_804B6DC0_size[sizeof(RecoveredGlobal_8018B5D0_TContainerAncient01__data_804B6DC0) == 0x2C ? 1 : -1];

void TContainerAncient01::update_wait_for_player() {
    Obj_8018B510 *arg0 = (Obj_8018B510 *)this;
    s32 flag;
    u16 i;
    u8 *p;
    f32 c;
    advance_animation_playback(arg0);
    flag = 0;
    if (arg0->f338 <= this->m_2b4) {
        flag = 1;
    } else {
        c = 6.4e+03f;
        for (i = 0; i < 4; i++) {
            p = (u8 *)get_player_by_client_id(i);
            if (p != 0 && horizontal_distance_squared(arg0->pos, p + 0x38) < c) {
                flag = 1;
            }
        }
    }
    if (flag != 0) {
        this->mode = 1;
        arg0->fB4[2] = this->mode;
        this->m_2b4 = (-1.0f);
    }
}

void TContainerAncient01::init_state_vectors() {
    *(f32 *)&this->m_338 = (f32) (3e+02f + (this->scale.x - TContainerAncient01__data_805DBD10[0]));
    this->m_33c = (f32) (2.1e+02f + (this->scale.y - TContainerAncient01__data_805DBD10[0]));
    *(f32 *)&this->unk_340 = (f32) (4e+02f + (this->scale.z - TContainerAncient01__data_805DBD10[0]));
    *(s32 *)&this->unk_36C = (s32) (*(s32 *)&this->set_params[2] + 4);
    VecCopy((Vec *)&this->m_344, (const Vec *)&this->position);
    *(f32 *)&this->unk_348 = (f32) (*(f32 *)&this->unk_348 + *(f32 *)((s8 *)&TContainerAncient01__collision_body_parts.value + 4));
    VecCopy((Vec *)&this->unk_350, (const Vec *)&this->m_344);
    this->m_354 = (f32) ((1.25f * *(f32 *)((s8 *)&TContainerAncient01__collision_body_parts.value + 4)) + this->m_354);
    *(s32 *)&this->m_35c = 0;
    *(f32 *)&this->m_360 = (f32) TContainerAncient01__data_805DBD10[0];
    *(f32 *)&this->unk_364 = (f32) TContainerAncient01__data_805DBD10[0];
    this->m_368 = (f32) TContainerAncient01__data_805DBD10[0];
}
#pragma pop

void TContainerAncient01::vfunc_6(s16 *arg1, s32 arg2) {
    if (arg2 != 0) {
        if ((s16) *arg1 == 1) {
            sub_8018B700();
            this->m_35c = 1;
        }
    } else if ((s16) *arg1 == 1) {
        this->m_35c = 1;
    }
}
void TContainerAncient01::sub_8018B700() {
    Obj_8018B700 *arg0 = (Obj_8018B700 *)this;
    if (arg0->f35C == 0) {
        arg0->f35C = 1;
        ((TObjCollidable *)arg0)->clear_player_status_flag(0, 1);
        TContainerAncient01::spawn_effect((void*)arg0, (void*)arg0->pos, (void*)TContainerAncient01__effect_id_table[0]);
        TContainerAncient01::spawn_effect((void*)arg0, (void*)arg0->pos, (void*)TContainerAncient01__effect_id_table[1]);
        if (TContainerAncient01::is_global_state_in_table() == 0) {
            ((TObjChara *)arg0)->request_box_item_drop(arg0->pos, 1);
        }
        ((TObjCollidable *)arg0)->set_flag8();
    }
}

}
#include "types.h"
#include "pso/misc/TContainerAncient01_8018B79C.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjMotion.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

struct Base_8018B820_8018B79C { char pad[0x18]; };
struct VObj_8018B820_8018B79C : Base_8018B820_8018B79C {
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
    virtual void m18();
    virtual void m19();
    virtual void m20(s32, f32);
};
struct VBase8018B8BC_8018B79C { char pad[0x18]; };
struct VObj8018B8BC_8018B79C : VBase8018B8BC_8018B79C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

extern "C" {
u32 get_bml_motion(int, int);
s32 get_bml_model(int, int);
s32 submit_cursor_candidate(void *, int, f32);
s32 run_task__7TObjectFv(void *);
extern s32 TContainerAncient01__bml_resource;

f32 xyz_distance_squared(void *, void *, void *);

s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
s32 draw_ginja_model_with_motion(s32, s32, f32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 reset_state__19TContainerAncient01Fv();

f32 TContainerAncient01::receive_physical_attack(void *, f32) {
    s16 sp8;

    if ((u16) this->entity_id >= 0x1000U) {
        reset_state__19TContainerAncient01Fv();
        if (((u32) this->set_entry != 0U) && (access_object_saved_state(&sp8, 1) != 0)) {
            sp8 = 1;
            access_object_saved_state(&sp8, 0);
            send_object_state_update(&sp8);
        }
    }
    return TContainerAncient01__data_805DBD14[0];
}

f32 TContainerAncient01::receive_direct_attack(void *arg1, DirectAttackPayload payload, void *, s32, s32) {
    s32 temp_r4;
    struct VObj_8018B820_8018B79C *o = (struct VObj_8018B820_8018B79C *)this;

    temp_r4 = payload.kind;
    if ((temp_r4 == 0) || ((temp_r4 - 1) <= 3U) || (temp_r4 == 0x13)) {
        o->m20(0, TContainerAncient01__data_805DBD10[0]);
    }
    return TContainerAncient01__data_805DBD14[0];
}

int TContainerAncient01::calc_distance_accuracy_penalty(void *, void *, void *, float) { return 1; }

s32 TContainerAncient01__vt18(s32 arg0, s32 arg1) {
    return xyz_distance_squared((void *)(arg1 + 0x38), (void *)(arg0 + 0x38), (void *)arg0) < 4e+02f;
}

void TContainerAncient01::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj8018B8BC_8018B79C *) arg0)->m8(3e+02f, 2e+01f) != 0) {
        TObjFish::set_global_param(this->texlist);
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        if ((s32) this->m_35c != 0) {
            scale_current_matrix((u8 *)&this->m_360);
        }
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_ginja_object(this->model);
        } else {
            draw_ginja_model_with_motion(*(s32 *)&this->model, *(s32 *)&this->current_motion, this->frame);
        }
        pop_matrix();
    }
}
void TContainerAncient01::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    f32 temp_f1_2;
    if (TObjPlayer::check_demo_mode() == 0) {
        if ((s32) this->m_35c == 0) {
            switch (this->mode) {
            case 0:
                ((TContainerAncient01 *)arg0)->update_wait_for_player();
                break;
            case 1:
                ((TContainerAncient01 *)arg0)->sub_8018B48C();
                break;
            case 2:
                ((TContainerAncient01 *)arg0)->sub_8018B284();
                break;
            default:
                this->mode = 0;
                this->requested_action = (s16) this->mode;
                this->m_2b4 = (f32) (-1.0f);
                ((TContainerAncient01 *)arg0)->update_wait_for_player();
                break;
            }
            temp_f1 = this->m_2b4;
            this->m_2b4 = (f32) (temp_f1 + TContainerAncient01__data_805DBD10[0]);
            submit_cursor_candidate(arg0, -1, temp_f1);
        } else {
            temp_f1_2 = *(f32 *)&this->unk_364;
            if (temp_f1_2 <= 0.2f) {
                *(f32 *)((s8 *)arg0 + 0x3C) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C) - 0.025f);
                if (*(f32 *)((s8 *)arg0 + 0x3C) <= ((-1e+01f) * *(f32 *)&this->unk_364)) {
                    queue_destruction__7TObjectFv(arg0);
                }
            } else {
                *(f32 *)&this->unk_364 = (f32) (temp_f1_2 - 0.025f);
            }
        }
    }
    if ((u32) this->current_motion == get_bml_motion(TContainerAncient01__bml_resource, 0)) {
        *(s32 *)&this->model = get_bml_model(TContainerAncient01__bml_resource, 0);
    }
    if ((u32) this->current_motion == get_bml_motion(TContainerAncient01__bml_resource, 1)) {
        *(s32 *)&this->model = get_bml_model(TContainerAncient01__bml_resource, 1);
    }
    run_task__7TObjectFv(arg0);
}

}
#include "types.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/enemy/TObjEneMe3Stelth.h"

struct Param_8018BB64 { s32 a; s32 b; s32 c; s32 d; };

struct Res_8018BB64 { u8 pad[0x430]; s32 x430; };

extern "C" {

void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern Param_8018BB64 container_ancient_anim_binding[];

extern s32 TContainerAncient01__effect_id_table[];

u8 *TContainerAncient01__ct(u8 *arg0, s32 arg1, s32 arg2);
void TLobby__sub_8001FE7C(void*, int);
void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TContainerAncient01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x370);
    if (o != NULL) {
        o = TContainerAncient01__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

void TContainerAncient01::release_static_resource() {
    if ((u32) TContainerAncient01__bml_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TContainerAncient01__bml_resource, 1);
        TContainerAncient01__bml_resource = 0U;
    }
}
void TContainerAncient01::load_resources() {
    void *p;
    TContainerAncient01__bml_resource = 0;
    if (TContainerAncient01::is_global_state_in_table() != 0) {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, TContainerAncient01__resource_descriptor_2, 0, 0, 0);
        }
        TContainerAncient01__effect_id_table[0] = 0x230;
        TContainerAncient01__bml_resource = (u32)p;
        TContainerAncient01__effect_id_table[1] = 0x231;
    } else {
        p = ::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 5, TContainerAncient01__resource_descriptor, 0, 0, 0);
        }
        TContainerAncient01__effect_id_table[0] = 0x45;
        TContainerAncient01__bml_resource = (u32)p;
        TContainerAncient01__effect_id_table[1] = 0x46;
    }
    Param_8018BB64 prm = container_ancient_anim_binding[0];
    prm.a = ((Res_8018BB64 *)TContainerAncient01__bml_resource)->x430;
    TObjEneMe3Stelth::spawn_attack((s16)0x3B, (s32)(get_bml_model(TContainerAncient01__bml_resource, 0)), (s32)(TObjFish__sub_8001EDB0(TContainerAncient01__bml_resource, 0)), (s32)&prm, (f32)1e+01f, (f32)TContainerAncient01__data_805DBD14[0]);
}

}
#include "pso/misc/RenderFadeState.h"
#include "pso/system/vector.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/item/TObjContainerJungEnemy.h"
#include "pso/item/TObjContainerIdo.h"
#include "pso/item/TUnk_804B97C0.h"
#include "pso/misc/TContainerAncient01.h"
#include "pso/misc/TContainerAncient01R.h"

#include "types.h"

struct RecoveredGlobal_8018BD00_TContainerAncient01__data_804B6DC0 {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_8018BD00_lbl_804B6DEC {
    s32 value;
    u8 remaining[0x2C];
};

struct RecoveredGlobal_8018BD00___vt__19TContainerAncient01 {
    s32 value;
    u8 remaining[0x13C];
};

struct B_8018BE30 { u8 pad[0x18]; };

struct V_8018BE30 : B_8018BE30 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(s32 a, f32 b);
};

struct B_8018BE98 { u8 pad[0x18]; };

struct V_8018BE98 : B_8018BE98 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(s32 a, f32 b);
};

extern "C" {

s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);

extern s32 __vt__19TContainerAncient01[];
extern s32 TContainerAncient01__name;
extern s32 TContainerAncient01__bml_resource;

u8 *TContainerAncient01__ct(u8 *arg0, s32 arg1, s32 arg2);

s32 TContainerAncient01__sub_8018BE90(void);
void *__dt__19TContainerAncient01Fv(void *arg0, s16 arg1);
s32 free_collision_body_parts(void *);
s32 __dl__7TObjectFPv(void *);

void *__dt__19TContainerAncient01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__19TContainerAncient01;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__9TObjCharaFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_8018BD00_TContainerAncient01__data_804B6DC0_size[sizeof(RecoveredGlobal_8018BD00_TContainerAncient01__data_804B6DC0) == 0x2C ? 1 : -1];
typedef char RecoveredGlobal_8018BD00_lbl_804B6DEC_size[sizeof(RecoveredGlobal_8018BD00_lbl_804B6DEC) == 0x30 ? 1 : -1];
typedef char RecoveredGlobal_8018BD00___vt__19TContainerAncient01_size[sizeof(RecoveredGlobal_8018BD00___vt__19TContainerAncient01) == 0x140 ? 1 : -1];
u8 *TContainerAncient01__ct(u8 *arg0, s32 arg1, s32 arg2) {
    __ct__9TObjCharaFP7TObject(arg0, (void *)arg1, (void *)arg2);
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8018BD00___vt__19TContainerAncient01 *)&__vt__19TContainerAncient01).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TContainerAncient01__name;
    ((TContainerAncient01 *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model((int) ((*(u8 * *)&TContainerAncient01__bml_resource)), 0);
    ((TContainerAncient01 *)arg0)->texlist = TObjFish__sub_8001EDB0((int) ((*(u8 * *)&TContainerAncient01__bml_resource)), 0);
    ((TContainerAncient01 *)arg0)->action_table = TContainerAncient01__anim_table;
    ((TObjMotion *)arg0)->set_field_d8((s32)((void *) (((TContainerAncient01 *)arg0)->action_table)));
    *(s32 *)((s8 *)arg0 + 0xDC) = (s32) *(s32 *)((s8 *)(*(u8 * *)&TContainerAncient01__bml_resource) + 0x430);
    ((TContainerAncient01 *)arg0)->requested_action = 0;
    ((TObjMotion *)arg0)->set_animation((((TContainerAncient01 *)arg0)->requested_action));
    ((TObjMotion *)arg0)->set_field_b8((int) (((TContainerAncient01 *)arg0)->requested_action));
    ((TContainerAncient01 *)arg0)->actorFlags = (s32) (((TContainerAncient01 *)arg0)->actorFlags | 0x60000000);
    init_collision_body_parts(arg0, (void *)&TContainerAncient01__collision_body_parts.value, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    VecCopy((Vec *)(arg0 + 0x74), (const Vec *)(arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x78) = (f32) ((*(f32 *)((s8 *)&TContainerAncient01__collision_body_parts.value + 4) / 2.0f) + *(f32 *)((s8 *)arg0 + 0x78));
    VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x74));
    ((TContainerAncient01 *)arg0)->mode = 0;
    ((TContainerAncient01 *)arg0)->init_state_vectors();
    return arg0;
}
#pragma pop

f32 TContainerAncient01R::receive_weapon_special_attack(void *, void *) {
    V_8018BE30 *self = (V_8018BE30 *)this;
    self->m20(0, TContainerAncient01__data_805DBD10[0]);
    return TContainerAncient01__data_805DBD14[0];
}

void TContainerAncient01R::apply_knockback_from_attacker(u8 *, f32) {  }
s32 TContainerAncient01R::try_start_action(s32, s32) { return 1; }
s32 TContainerAncient01R::roll_physical_accuracy(void *, s32, f32) { return 1; }

int TContainerAncient01::get_table_entry(int a0) {  return TContainerAncient01__effect_id_table[a0]; }

s32 TContainerAncient01__sub_8018BE90(void) {
    return TContainerAncient01__bml_resource;
}

f32 TContainerAncient01::receive_weapon_special_attack(void *, void *) {
    V_8018BE98 *self = (V_8018BE98 *)this;
    self->m20(0, TContainerAncient01__data_805DBD10[0]);
    return TContainerAncient01__data_805DBD14[0];
}

void TContainerAncient01::apply_knockback_from_attacker(u8 *, f32) {  }
s32 TContainerAncient01::try_start_action(s32, s32) { return 1; }
s32 TContainerAncient01::roll_physical_accuracy(void *, s32, f32) { return 1; }
}
