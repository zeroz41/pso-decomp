#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/olgaflow/OlgaFlowActions.h"
#include "pso/boss/olgaflow/TBoss6Type1.h"
#include "pso/boss/Boss6ScrollStrips.h"
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/boss/olgaflow/TBoss6PlotFalz.h"
#include "pso/boss/olgaflow/TBoss6PlotFalzState.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_803D96A8.h"
void set_constant_material(const NJS_ARGB *color);
#include "pso/boss/darkfalz/TBoss4Fade.h"
#include "types.h"
#include "pso/map/FloorArea.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/PadRumble.h"
#include "pso/system/vector.h"


#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/system/BmlResourceDescriptor.h"

extern const char *boss06_plotfalz_dat_model_names[15];
extern const char *boss06_plotfalz_dat_motion_names[63];
extern BmlResourceDescriptor boss6_plot_falz_resource_descriptor;
#include <stddef.h>
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/olgaflow/TBoss6EmptyWarp.h"
#include "pso/boss/olgaflow/TBoss6Mine.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type3.h"
#include "pso/boss/olgaflow/TBoss6GravBall.h"
#include "pso/boss/olgaflow/TBoss6Rock.h"
#include "pso/boss/olgaflow/TBoss6Tube.h"
#include "pso/boss/olgaflow/TBoss6Type2.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/olgaflow/TBoss6Thanks_8035D1F4.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/olgaflow/TBoss6EmptyWarp_802B0E2C.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/unk/text_80357058.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D853C.h"
#include "pso/player/PlayerSlots.h"

#pragma readonly_strings on
const char *boss06_plotfalz_dat_model_names[15] = {
    "bossgc_laser.nj",
    "bossgc_pf_mag.nj",
    "bossgc_pf01_kirai.nj",
    "bossgc_pf01_leg.nj",
    "bossgc_pf02_body.nj",
    "bossgc_pf02l_body.nj",
    "bssgc_pf01_body.nj",
    "flow_body.nj",
    "flow_dark_body.nj",
    "flow_sord.nj",
    "flowen_aa_t_ok_head.nj",
    "flowen_az_t_body.nj",
    "op_flow_mark.nj",
    "wxmS02_k_m_sp_rbuki.nj",
    NULL,
};
const char *boss06_plotfalz_dat_motion_names[63] = {
    "appear_bossgc_pf01_kirai.njm",
    "bouend_bossgc_pf02_body.njm",
    "bousou_bossgc_pf02_body.njm",
    "dead_bossgc_pf_mag.njm",
    "dead_bossgc_pf01_leg.njm",
    "dead_bssgc_pf01_body.njm",
    "dpb_bossgc_pf02_body.njm",
    "end_bossgc_pf02_body.njm",
    "flow_dark_body.njm",
    "flowend1_flow_body.njm",
    "flowend1_flow_sord.njm",
    "flowend2_flow_body.njm",
    "fukatu_bossgc_pf_mag.njm",
    "grdwait_bossgc_pf01_leg.njm",
    "grdwait_bssgc_pf01_body.njm",
    "hoe_bssgc_pf01_body.njm",
    "jump_bossgc_pf02_body.njm",
    "jyut_a_bssgc_pf01_body.njm",
    "jyut_b_bssgc_pf01_body.njm",
    "jyut_c_bssgc_pf01_body.njm",
    "jyut_d_bssgc_pf01_body.njm",
    "jyut_e_bssgc_pf01_body.njm",
    "kakusan_bssgc_pf01_body.njm",
    "kakuside_bssgc_pf01_body.njm",
    "kamae_bossgc_pf02_body.njm",
    "kaming_bossgc_pf02_body.njm",
    "kiri1_bossgc_pf02_body.njm",
    "kiri2_bossgc_pf02_body.njm",
    "kiri3_bossgc_pf02_body.njm",
    "land_bossgc_pf01_leg.njm",
    "land_bssgc_pf01_body.njm",
    "op_bossgc_pf01_leg.njm",
    "op_bossgc_pf02_body.njm",
    "op_bssgc_pf01_body.njm",
    "op_op_flow_mark.njm",
    "op3_bossgc_pf01_leg.njm",
    "op3_bssgc_pf01_body.njm",
    "roll_bossgc_pf01_leg.njm",
    "roll_bssgc_pf01_body.njm",
    "sarch_bossgc_pf02_body.njm",
    "sidetoup_bossgc_pf01_leg.njm",
    "sidetoup_bssgc_pf01_body.njm",
    "skwait2_bossgc_pf01_leg.njm",
    "skysd_bssgc_pf01_body.njm",
    "skywait_bossgc_pf01_leg.njm",
    "skywait_bssgc_pf01_body.njm",
    "sodatk_bssgc_pf01_body.njm",
    "takeoff_bossgc_pf01_leg.njm",
    "takeoff_bssgc_pf01_body.njm",
    "tame_bossgc_pf_mag.njm",
    "tinmoku_bossgc_pf_mag.njm",
    "tlatk_bossgc_pf01_leg.njm",
    "tlatk_bssgc_pf01_body.njm",
    "uptoside_bssgc_pf01_body.njm",
    "wait_bossgc_pf_mag.njm",
    "wait_bossgc_pf02_body.njm",
    "waitside_bssgc_pf01_body.njm",
    "waitvsk_bossgc_pf02_body.njm",
    "walk_bossgc_pf02_body.njm",
    "walkgd_bossgc_pf02_body.njm",
    "walkvsk_bossgc_pf02_body.njm",
    "wxmS02_k_m_sp_rbuki.njm",
    NULL,
};
BmlResourceDescriptor boss6_plot_falz_resource_descriptor = { "boss06_plotfalz_dat.bml", boss06_plotfalz_dat_model_names, boss06_plotfalz_dat_motion_names, 14, 62 };
const char *TBoss6PlotFalz__name = "TBoss6PlotFalz";
f32 TBoss6PlotFalz__fade_amount = -1.0f;
const Vec lbl_8047059C = { -10000.0f, 0.0f, 0.0f };
const Vec lbl_804705A8 = { -10000.0f, 10.0f, 0.0f };
const Vec lbl_804705B4 = { 0.0f, 0.0f, 0.0f };
const Vec lbl_804705C0 = { 0.0f, 0.0f, 0.0f };
const Vec lbl_804705CC = { -10000.0f, 0.0f, 0.0f };

struct Color_802ABF44 { f32 a, b, c, d; };

extern "C" {
s16 get_entity_id(void *);
extern s32 plot_falz_phase;
void set_chunk_material_override_pair(int, int, s32, s32);
}


struct Player_802AAE78 { u8 pad[0x32C]; s16 f32c; };


extern "C" {
extern u16 boss6_plot_falz_player_order_table[];
s32 send_6x2F_change_player_hp(int, s32, s16);

struct TBoss6PlotFalz_802AACF4 { u8 pad[0x3D0]; s32 f3D0; s32 f3D4; s32 f3D8; };
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void update_random_shake__14TBoss6PlotFalzFPv(TBoss6PlotFalz_802AACF4 *o) {
    if (o->f3D0 != 0) {
        s32 n = o->f3D4 - 1;
        o->f3D4 = n;
        if (n < 0) {
            TCameraCtrl::set_shake_preset(o->f3D8);
            o->f3D4 = (s32)(60.0f * (3.0517578125e-05f * (f32)rand()) + 60.0f);
        }
    }
}
#pragma pop

s32 TBoss6PlotFalz::damage_player_hp(s32 client, u32 damage) {
    u32 v;
    TObjPlayer *p;
    s32 hp;
    u16 id;
    id = client;
    v = damage;
    if (id == 0xFFFF || (p = get_player_by_client_id(id)) == NULL || TBoss6PlotFalz::is_active(p) == 0) {
        return 0;
    }
    hp = p->get_actor_hp();
    if ((u32)hp < v) {
        v = hp;
    }
    if (p->obj_isState2_324() != 0) {
        return v;
    }
    hp -= v;
    send_6x2F_change_player_hp(0xFFFF, client, hp);
    p->gain_photon_blast_charge(TObjPlayer::calc_photon_blast_charge(p, v));
    return v;
}

u16 TBoss6PlotFalz__sub_802AAE48(s32 i) {
    if (i < 0 || i >= 4) return 0xFFFF;
    return boss6_plot_falz_player_order_table[i];
}

s32 TBoss6PlotFalz::sort_active_players() {
    s32 vals[4];
    s32 i;
    s32 j;
    s32 n;
    Player_802AAE78 *p;
    s32 t;
    s32 k;
    u16 s;
    for (i = 0; i < 4; i++) {
        boss6_plot_falz_player_order_table[i] = 0xFFFF;
        vals[i] = -1;
    }
    n = 0;
    for (i = 0; i < registered_player_count; i++) {
        p = (Player_802AAE78 *)TObjPlayer::get_player_data(i);
        if (p != NULL && TBoss6PlotFalz::is_active((TObjPlayer *)p) != 0 && p->f32c != 0) {
            boss6_plot_falz_player_order_table[n] = get_entity_id(p);
            vals[n] = p->f32c;
            n++;
        }
    }
    for (i = 2; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
            k = j + 1;
            if (vals[j] < vals[k]) {
                t = vals[j];
                vals[j] = vals[k];
                vals[k] = t;
                s = boss6_plot_falz_player_order_table[j];
                boss6_plot_falz_player_order_table[j] = boss6_plot_falz_player_order_table[k];
                boss6_plot_falz_player_order_table[k] = s;
            }
        }
    }
    return n;
}

u16 TBoss6PlotFalz::pick_random_active_player() {
    u16 ids[4];
    s32 n;
    s32 i;
    Player_802AAE78 *p;

    n = 0;
    for (i = 0; i < registered_player_count; i++) {
        p = (Player_802AAE78 *)TObjPlayer::get_player_data(i);
        if (p != NULL && TBoss6PlotFalz::is_active((TObjPlayer *)p) != 0) {
            ids[n] = get_entity_id(p);
            n++;
        }
    }
    if (n == 0) {
        return 0xFFFF;
    }
    return ids[(s32)(((f32)n - 0.1f) * (3.0517578125e-05f * (f32)rand()))];
}

s32 TBoss6PlotFalz::is_active(TObjPlayer *player) {
    if ((is_state_1f(player) != 0) && !(player->actorFlags & 0x02000800)) {
        return 1;
    }
    return 0;
}

}
#undef get_player_data__10TObjPlayerFi

#define update_random_shake__14TBoss6PlotFalzFPv ((s32 (*)(void *))update_random_shake__14TBoss6PlotFalzFPv)

extern "C" {

s32 TBoss6PlotFalz::is_state_1f(TObjPlayer *player) {
    if (player == NULL || player->get_area() != AREA_OLGA_FLOW) {
        return 0;
    }
    return 1;
}


void TBoss6PlotFalz::run_phase_action() {
    TBoss6PlotFalzAction action = TBoss6PlotFalz__data_804DE66C[this->m_378].update;
    if (action != 0) {
      (this->*action)();
    }
    update_random_shake__14TBoss6PlotFalzFPv(this);
}

void TBoss6PlotFalz::call_state_action() {
    TBoss6PlotFalzAction action = TBoss6PlotFalz__data_804DE66C[this->m_378].tick;
    if (action != 0) {
      (this->*action)();
    }
}

void TBoss6PlotFalz::set_state_2() { *(s32*)((char*)this + 0x3d4) = 0; *(s32*)((char*)this + 0x3d8) = 2; }
void TBoss6PlotFalz::reset_state() { *(s32*)((char*)this + 0x3d4) = 0; *(s32*)((char*)this + 0x3d8) = 0; }
void TBoss6PlotFalz::activate_warp() { if (tube) tube->activate_warp(); }
void TBoss6PlotFalz::free_child() { if (tube) tube->sub_802B1004(); }
void TBoss6PlotFalz::set_state(s32 arg1) {
    if (arg1 < 0 || arg1 >= 9) {
        return;
    }
    if (this->m_378 != -1) {
        TBoss6PlotFalzAction action = TBoss6PlotFalz__data_804DE66C[this->m_378].leave;
        if (action != 0) {
            (this->*action)();
        }
    }
    this->m_378 = arg1;
    TBoss6PlotFalzAction action = TBoss6PlotFalz__data_804DE66C[this->m_378].enter;
    if (action != 0) {
        (this->*action)();
    }
}

}
#undef update_random_shake__14TBoss6PlotFalzFPv

struct Stack_802AB684 {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

struct Player_802AB3E0 { u8 pad[0x38]; Vec pos; };

extern "C" {
s32 vector_length(void *);
s32 subtract_vector(void *, const void *);
void TBoss6PlotFalz__sub_802AB684(saddr arg0);
f64 atan2_float(f32, f32);
extern u8 *camera_ctrl_instance;
s32 TBoss6PlotFalz__sub_802AB6CC(void *pos, f32 r);

s32 is_local_client_floor_leader();

void TBoss6PlotFalz::set_visible_flag() {
    if (is_local_client_floor_leader() != 0) {
        *(s32 *)((s8 *)this + 0x374) = 0;
        return;
    }
    *(s32 *)((s8 *)this + 0x374) = 1;
}

void TBoss6PlotFalz::spawn_player_hit_effects() {
    Vec v;
    Player_802AB3E0 *p;
    s32 i;
    f32 k;
    if (TBoss6Thanks__sub_8035D270() != 0) {
        play_sound_effect(0x40033231, 0, 0, 0);
        k = 12.5f;
        for (i = 0; i < registered_player_count; i++) {
            p = (Player_802AB3E0 *)TObjPlayer::get_player_data(i);
            if (TBoss6PlotFalz::is_state_1f((TObjPlayer *)p) != 0) {
                VecCopy((Vec *)(&v), (const Vec *)(&p->pos));
                v.y += k;
                spawn_particle_effect(&v, 0x29);
            }
        }
    }
}

}
struct V3_802AB490 { s32 x, y, z; };
struct Msg_802AB490 { s32 a, b, c; };
extern "C" {
s32 is_split_screen();
extern s32 local_client_id;

void TBoss6PlotFalz::award_exp_and_destroy() {
    u8 *self = (u8 *)this;
    TBoss6PlotFalz::spawn_player_hit_effects();
    if (is_split_screen() != 0) {
        ((TObjEnemy *)self)->distribute_experience();
    } else {
        TObjPlayer *pl = get_player_by_client_id(local_client_id);
        if (pl != NULL) {
            V3_802AB490 saved = *(V3_802AB490 *)(self + 0x2FC);
            VecCopy(&this->body_center, &pl->body_center);
            ((TObjEnemy *)self)->distribute_experience();
            VecCopy(&this->body_center, (const Vec *)&saved);
        }
    }
    Msg_802AB490 m;
    m.a = 0x800;
    ((TObjEnemy *)self)->send_6x0A_enemy_state(&m);
    ((TObjEnemy *)self)->exchange_object_state(&m, 0);
    this->apply_enemy_state((s32 *)&m);
    ((TObjEnemy *)self)->send_entity_set_flags();
    ((TObject *)self)->queue_destruction();
}

void TBoss6PlotFalz::apply_fade_alpha(s32 color, f32 farg0) {
    f32 var_f1;
    TBoss4Fade *temp_r3;
    var_f1 = farg0;
    temp_r3 = fade;
    if ((temp_r3 != NULL) && !(var_f1 <= 0.0f)) {
        if (var_f1 > 1.0f) {
            var_f1 = 1.0f;
        }
        fn_803594B4(temp_r3, color, var_f1);
    }
}
#pragma push
#pragma fp_contract on
s32 TBoss6PlotFalz::rand_vary_count(s32 arg0, f32 farg0) {
    s32 v = (s32)((f32)arg0 * (farg0 * sin_table_lookup((s32)(65535.0f * (3.0517578125e-05f * (f32)rand())))) + (f32)arg0);
    if (v < 1) {
        v = 1;
    }
    return v;
}
#pragma pop
void TBoss6PlotFalz__sub_802AB684(saddr arg0) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_802AB684, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_802AB684, spC) == 0x4);
    Stack_802AB684 stack;
    VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0));
    subtract_vector(&stack.sp8, &lbl_8047059C);
    stack.spC = 0.0f;
    vector_length(&stack.sp8);
}
extern "C" {
__declspec(section ".sdata2") const f32 lbl_805DE0A4[1] = { 1e-05f };
}
#define lbl_805DE0A4 (lbl_805DE0A4[0])
#define VLEN(v) (((f32 (*)(void *))vector_length)(v))
s32 TBoss6PlotFalz__sub_802AB6CC(void *pos, f32 r) {
    Vec c;
    Vec pl;
    Vec p = *(Vec *)pos;
    Vec d1;
    Vec d2;
    Vec d3;
    Vec a;
    Vec b;
    Vec dir;
    TObjPlayer *player;
    f32 l2;
    f32 l3;
    s32 ang1;
    s32 ang2;
    s32 ang3;
    s32 s1;
    s32 s2;
    p.y = 0.0f;
    player = get_player_by_client_id(TCameraCtrl::get_nth_view_player_id(TCameraCtrl::get_camera_no()));
    if (player == NULL) {
        return 0;
    }
    VecCopy(&pl, &player->position);
    VecCopy((Vec *)&c, (const Vec *)(camera_ctrl_instance + 0x178));
    VecCopy((Vec *)&d1, (const Vec *)&p);
    subtract_vector(&d1, &pl);
    d1.y = 0.0f;
    if (VLEN(&d1) < r) {
        return 1;
    }
    VecCopy((Vec *)&d2, (const Vec *)&p);
    subtract_vector(&d2, &c);
    d2.y = 0.0f;
    l2 = VLEN(&d2);
    if (l2 < r) {
        return 1;
    }
    if (l2 > 250.0f) {
        return 0;
    }
    VecCopy((Vec *)&d3, (const Vec *)&pl);
    subtract_vector(&d3, &c);
    d3.y = 0.0f;
    l3 = VLEN(&d3);
    if (l3 <= lbl_805DE0A4 || l3 > 250.0f) {
        return 0;
    }
    if (l3 < l2 - r) {
        return 0;
    }
    if (vec3_dot(&d2, &d3) <= 0.0f) {
        return 0;
    }
    dir.x = -d2.z;
    dir.y = 0.0f;
    dir.z = d2.x;
    normalize_vector(&dir);
    dir.x *= r;
    dir.z *= r;
    VecCopy((Vec *)&a, (const Vec *)&p);
    vec3_add_to(&a, &dir);
    VecCopy((Vec *)&b, (const Vec *)&p);
    subtract_vector(&b, &dir);
    ang1 = (s32)(10430.38043493439 * atan2_float(a.x - c.x, a.z - c.z));
    ang2 = (s32)(10430.38043493439 * atan2_float(b.x - c.x, b.z - c.z));
    ang3 = (s32)(10430.38043493439 * atan2_float(pl.x - c.x, pl.z - c.z));
    s1 = angle_diff_s16(ang1, ang3);
    s2 = angle_diff_s16(ang3, ang2);
    if ((s1 >= 0 && s2 >= 0) || (s1 <= 0 && s2 <= 0)) {
        if (l3 < l2 + r) {
            return 0;
        }
        return 1;
    }
    return 0;
}

#undef VLEN

f32 TBoss6PlotFalz::cosine_ease(f32 t) {
    if (t < 0.0f) {
        return 0.0f;
    }
    if (t > 1.0f) {
        return 1.0f;
    }
    return 0.5f * (1.0f - cos_table_lookup((s32)(32768.0f * t)));
}
s32 TBoss6PlotFalz__sub_802ABADC(void);
f32 TBoss6PlotFalz::get_value() {
    if ((TBoss6PlotFalz__sub_802ABADC() == 0) || (TBoss6PlotFalz__type1_instance == NULL)) {
        return 0.0f;
    }
    return TBoss6PlotFalz__type1_instance->position.y;
}
s32 TBoss6PlotFalz::is_boss_active() {
    if ((TBoss6PlotFalz__type2_instance == NULL) || (TBoss6PlotFalz__type2_instance->get_state() == 0x23)) {
        return 0;
    }
    return 1;
}
s32 TBoss6PlotFalz__sub_802ABADC(void) {
    if ((TBoss6PlotFalz__type1_instance == NULL) || (TBoss6PlotFalz__type1_instance->get_gravity_attack_state() == 0x28)) {
        return 0;
    }
    return 1;
}


void TBoss6PlotFalz::destroy_static_instance() {
    if (TBoss6PlotFalz__type2_instance != NULL) {
        TBoss6PlotFalz__type2_instance->queue_destruction();
        TBoss6PlotFalz__type2_instance = NULL;
    }
}

void TBoss6PlotFalz::queue_instance_destruction() {
    if (TBoss6PlotFalz__type1_instance != NULL) {
        TBoss6PlotFalz__type1_instance->queue_destruction();
        TBoss6PlotFalz__type1_instance = NULL;
    }
}

}


// What spawn_type1 / spawn_type2 hand create: the owner, then a copy of the 0x40-byte set entry
// at 0x388 renumbered for the body (the constructor's apply_set_data reads it), then m_37c.
struct Boss6BodySpawnParams {
    TBoss6PlotFalz *owner;
    s16 set_index;
    u8 pad_06[0x4];
    s16 entity_id;
    s16 flags;
    u8 pad_0E[0x36];
    u8 variant;
};

extern "C" {
f32 xyz_distance(const void *, const void *);

void TBoss6PlotFalz::release_object() { if (tube != NULL) { tube->queue_destruction(); tube = NULL; } }

s32 TBoss6PlotFalz::get_target_pos_a(Vec *position) {
    if (TBoss6PlotFalz__type2_instance == NULL) {
        VecCopy(position, &lbl_804705CC);
        return 0;
    }
    VecCopy(position, &TBoss6PlotFalz__type2_instance->position);
    return 1;
}

s32 TBoss6PlotFalz::get_target_pos_b(Vec *position) {
    if (TBoss6PlotFalz__type1_instance == NULL) {
        VecCopy(position, &lbl_804705C0);
        return 0;
    }
    VecCopy(position, &TBoss6PlotFalz__type1_instance->position);
    return 1;
}

void TBoss6PlotFalz::spawn_type2() {
    u8 *self = (u8 *)this;
    Boss6BodySpawnParams params;
    if (TBoss6PlotFalz__type2_instance == NULL) {
        params.owner = this;
        params.variant = m_37c;
        copy_set_entry(&params.set_index, self + 0x388);
        params.flags = 1;
        params.set_index = set_index + 0x1FF;
        params.entity_id = entity_id + 0x1FF;
        TBoss6PlotFalz__type2_instance = TBoss6Type2::create((saddr)&params);
    }
}

void TBoss6PlotFalz::spawn_type1() {
    u8 *self = (u8 *)this;
    Boss6BodySpawnParams params;
    if (TBoss6PlotFalz__type1_instance == NULL) {
        params.owner = this;
        params.variant = m_37c;
        copy_set_entry(&params.set_index, self + 0x388);
        params.set_index = set_index + 0x200;
        params.entity_id = entity_id + 0x200;
        TBoss6PlotFalz__type1_instance = TBoss6Type1::create((saddr)&params);
    }
}

void TBoss6PlotFalz::ensure_field384() {
    if (tube == NULL) {
        tube = TBoss6Tube::create(this);
    }
}

f32 TBoss6Mine::next_random_float(s32 *arg0) {
    *arg0 = TBoss6Type1__sub_802ABDEC(*arg0);
    return (f32) (*arg0 & 0x7FFF) / 32767.0f;
}

s32 TBoss6Type1__sub_802ABDEC(s32 seed) {
    seed = seed * 0x41C64E6D + 12345;
    seed = seed / 65536;
    seed = seed % 32768;
    return seed & 0x7FFF;
}

void TObjFish::reset_fish_globals() { chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask; chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask; model_render_flags = saved_model_render_flags; }
void TBoss6PlotFalz::apply_radial_effect_to_players(void *pos, s16 amount, s16 kind, f32 range) {
    s32 n;
    s32 i;
    saddr p;
    f32 d;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = (saddr)TObjPlayer::get_player_data(i);
        if (TBoss6PlotFalz::is_state_1f((TObjPlayer *)p) != 0 && TObjPlayer::is_locally_controlled((void *)p) != 0) {
            d = xyz_distance((void *)(p + 0x38), pos);
            if (!(d >= range)) {
                start_pad_rumble_client((s16)((f32)amount * (1.0f - d / range)), kind, (s16)((s32 (*)(s32))get_entity_id)(p));
            }
        }
    }
}
extern "C" {
__declspec(section ".sdata2") const s32 lbl_805DE0B8[1] = { 0x8829 };
}
#define lbl_805DE0B8 (lbl_805DE0B8[0])
void TBoss6PlotFalz::set_fade_material_color(f32 f) {
    Color_802ABF44 c;
    s32 old = model_render_flags;
    model_render_flags = old & ~0x10;
    saved_model_render_flags = old;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= lbl_805DE0B8;
    set_chunk_material_override_pair(0xFF00, 0x800, chunk_polygon_flags_or_mask, chunk_polygon_flags_and_mask);
    c.a = -1.0f + f;
    c.b = c.c = c.d = 0.0f;
    set_constant_material((const NJS_ARGB *)&c);
}

}

#define set_chunk_material_override_pair ((s32 (*)(int, int, int, s32, s32, int))set_chunk_material_override_pair)
#define set_constant_material ((s32 (*)(void *, f32, f32, f32, f32))set_constant_material)

struct Stack_802AC040 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
};


void TBoss6PlotFalz__sub_802AC008(f32 farg0, f32 hp_ratio);
void set_chunk_blend(u32 x);
extern s32 game_difficulty_selection;

void TBoss6PlotFalz::update_camera_target() {
    if (TBoss6PlotFalz__fade_amount > 0.0f) {
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
    }
    TBoss6PlotFalz__fade_amount = (-1.0f);
}
#pragma push
#pragma fp_contract on
void TBoss6PlotFalz__sub_802AC008(f32 farg0, f32 hp_ratio) {
    f32 temp_f3;
    temp_f3 = 0.25f * hp_ratio;
    TBoss6PlotFalz::apply_fade_material_color(farg0, ((-0.75f) * hp_ratio) + 1.0f, temp_f3, temp_f3);
}
#pragma pop

extern "C" {
__declspec(section ".sdata2") const s32 lbl_805DE0C8[1] = { 0x8810 };
}
#define lbl_805DE0C8 (lbl_805DE0C8[0])
#pragma push
#pragma opt_common_subs off
#pragma opt_dead_assignments off
#pragma fp_contract on
void TBoss6PlotFalz::apply_fade_material_color(f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_802AC040, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_802AC040, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_802AC040, sp10) == 0x8);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_802AC040, sp14) == 0xC);
    Stack_802AC040 stack;
    f32 temp_f1;
    f32 temp_f2;
    f32 var_f1;
    s32 temp_r5;
    s32 temp_r8;
    var_f1 = farg0;
    if (((-1.0f) != TBoss6PlotFalz__fade_amount) || (var_f1 < 0.0f) || (var_f1 > 1.0f) || (farg1 < 0.0f) || (farg1 > 1.0f) || (farg2 < 0.0f) || (farg2 > 1.0f) || (farg3 < 0.0f) || (farg3 > 1.0f)) {
        var_f1 = 0.0f;
    }
    TBoss6PlotFalz__fade_amount = var_f1;
    if (0.0f != var_f1) {
        temp_r8 = model_render_flags;
        temp_r5 = temp_r8 & 0xFFFFFFDF;
        model_render_flags = temp_r5;
        saved_model_render_flags = temp_r8;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags = temp_r5 | lbl_805DE0C8;
        set_chunk_material_override_pair(0, 0x800, (int)temp_r5, chunk_polygon_flags_or_mask, chunk_polygon_flags_and_mask, (int)temp_r8);
        set_chunk_blend(0x2500);
        stack.sp8 = 1.0f;
        temp_f2 = -((TBoss6PlotFalz__fade_amount * (1.0f - farg1)) - 1.0f);
        temp_f1 = -((TBoss6PlotFalz__fade_amount * (1.0f - farg2)) - 1.0f);
        stack.spC = temp_f2;
        stack.sp10 = temp_f1;
        stack.sp14 = -((TBoss6PlotFalz__fade_amount * (1.0f - farg3)) - 1.0f);
        set_constant_material(&stack.sp8, temp_f1, temp_f2, 1.0f, TBoss6PlotFalz__fade_amount);
    }
}
#pragma pop

s32 is_normal_difficulty(void) {
    if (game_difficulty_selection == 0) {
        return 1;
    }
    return 0;
}

#undef set_chunk_material_override_pair
#undef set_constant_material

int TBoss6PlotFalz::get_phase() {  return plot_falz_phase; }

union MemberActionStorage_8004B084 { s32 words[3]; void (TBoss4DarkFalz::*action)(); };

union MemberActionStorage_8004B0F8 { s32 words[3]; void (TBoss4DarkFalz::*action)(); };

struct Sub_802AC3E8 { u8 pad[0x18]; s32 flags; };

struct Obj_802AC3E8 { u8 pad[0x38]; Vec pos; u8 pad2[0xA4 - 0x44]; Sub_802AC3E8 *sub; };

void *destroy_buffer_pair(void *arg0, s16 arg1);
extern "C" {
void scroll_strip_uvs(u32, s16, s16);
s32 get_main_phase();

void TBoss6PlotFalz::update_active_flag() {
    plot_falz_phase = 0;
    if ((get_main_phase() == 0xF) || (is_split_screen() != 0)) {
        plot_falz_phase = 1;
    }
}

void Boss6ScrollStrips::scroll_strips_uv(s32 dx, s32 dy) {
    s32 j;
    s32 i;
    i = 0;
    j = 0;
    u += dx;
    v += dy;
    for (; i < count; i++, j += 4) {
        u32 e = *(u32 *)((u8 *)items + j);
        if (e != 0) {
            scroll_strip_uvs(e, u, v);
        }
    }
}

void Boss6ScrollStrips::free_buffer_pairs() {
    s32 i;
    for (i = 0; i < count; i++) {
        if (items[i] != 0) {
            destroy_buffer_pair(items[i], 1);
            items[i] = 0;
        }
    }
    mem_free(items);
    items = 0;
}
LAYOUT_ASSERT(MemberActionStorage_8004B084_size, sizeof(MemberActionStorage_8004B084) == 12);
LAYOUT_ASSERT(MemberActionStorage_8004B0F8_size, sizeof(MemberActionStorage_8004B0F8) == 12);

void Boss6ScrollStrips::build_tables(const Boss6StripDesc *descs, s32 n) {
    saddr h;
    s32 i;
    const Boss6StripDesc *r;
    s32 t;
    saddr p;
    s32 j;
    h = (saddr)TBoss6PlotFalz::get_scene_archive();
    if (h == 0 || descs == NULL || n < 1) {
        return;
    }
    count = n;
    items = NULL;
    items = (StripBufferPair **)mem_alloc(count * 4);
    u = 0;
    v = 0;
    for (j = 0; j < count; j++) {
        items[j] = 0;
    }
    for (i = 0; i < count; i++) {
        r = &descs[i];
        t = (saddr)find_model_node((uaddr)get_bml_model((BmlResource *)h, r->model), r->node);
        p = (saddr)::operator new(0x14);
        if (p != 0) {
            p = (saddr)((TLobby *)p)->alloc_tables(t, r->texture_filter);
        }
        items[i] = (StripBufferPair *)p;
    }
}

void TBoss6PlotFalz::warp_nearby_players() {
    Vec v;
    s32 i;
    Obj_802AC3E8 *p;
    for (i = registered_player_count + registered_enemy_count; i < lbl_805D5868; i++) {
        p = (Obj_802AC3E8 *)TObjPlayer::get_player_data(i);
        if (p != NULL && p->sub != NULL && (p->sub->flags & 0x20000)
            && !(xyz_distance(&lbl_804705B4, &p->pos) > 150.0f)
            && !(xyz_distance(&lbl_8047059C, &p->pos) <= 300.0f)) {
            VecCopy((Vec *)&v, (const Vec *)&p->pos);
            subtract_vector(&v, &lbl_804705B4);
            vec3_add_to(&v, &lbl_8047059C);
            v.y = 7.5f;
            VecCopy((Vec *)&p->pos, (const Vec *)&v);
            ((TObjCollidable *)p)->refresh_collision_body_centers();
        }
    }
}

void TBoss6PlotFalz::refresh_players_equipment() {
    s32 i;
    void *p;
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != 0) {
            if (((TObjPlayer *)p)->get_area() == 0x1f) {
                ((TObjPlayer *)p)->refresh_equipment_slot();
            }
        }
    }
}
}
void reset_cameras_to_actor(void *, s32);

#pragma push
#pragma fp_contract on
void place_players_in_warp_circle(void) {
    s32 step;
    s32 ang = 0;
    s32 i;
    if (registered_player_count <= 2) {
        step = 0x2000;
    } else {
        step = 0x2000 / (registered_player_count - 1);
    }
    for (i = 0; i < registered_player_count; i++) {
        void *p = TObjPlayer::get_player_data(i);
        if (p != NULL && ((TObjPlayer *)p)->get_area() == 0x1F) {
            Vec pos = lbl_804705A8;
            pos.x += 350.0f * sin_table_lookup(ang);
            pos.z += 350.0f * cos_table_lookup(ang);
            ((TObjMotion *)p)->set_position_from(&pos);
            ((TObjBase *)p)->save_previous_position();
            *(s32 *)((u8 *)((TObjBase *)p)->get_rotation() + 4) = ang + 0x8000;
            ((TObjPlayer *)p)->refresh_equipment_slot();
            if (TObjPlayer::is_locally_controlled((void *)p) != 0) {
                reset_cameras_to_actor(p, 0);
            }
            ang += step;
        }
    }
}
#pragma pop
void place_players_in_warp_circle(void);
extern "C" {

void TBoss6EmptyWarp::init_warp() { place_players_in_warp_circle(); TBoss6PlotFalz::warp_nearby_players(); }

void release_all_players_control_lock(void);
void TBoss6PlotFalz::end_cutscene_camera() {
    s32 i;
    void *p;
    TWindowCtrl::init_all_slots2();
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != 0) {
            ((TObjPlayer *)p)->end_camera_pan();
        }
    }
    release_all_players_control_lock();
}

void TBoss6PlotFalz::freeze_all_players() {
    s32 i;
    void *p;
    TWindowCtrl::init_all_slots();
    for (i = 0; i < registered_player_count; i++) {
        TObjPlayer *player = TObjPlayer::get_player_data(i);
        if (player != 0) {
            player->start_freeze();
        }
    }
}
void TBoss6PlotFalz::move_player_to(TObjPlayer *player, Vec *pos) {
    if (player == NULL || pos == NULL) {
        return;
    }
    player->set_position_from(pos);
    player->save_previous_position();
    player->set_indexed_flags(0, 0x900000);
    player->actorFlags &= ~0x20;
}
}


typedef struct Loc_802AC9EC {
    s32 a;
    s16 b;
    s16 c;
    s32 d;
    s32 e;
} Loc_802AC9EC;



extern "C" {
void fn_802E52AC(void);
}
void clear_boss6_player_snapshots(void);
BmlResource *boss6_scene_archive;
extern "C" {
extern saddr TBoss6PlotFalz__instance;

void TBoss6PlotFalz::render() {  }

void TBoss6PlotFalz::run_task() {
    u8 *self = (u8 *)this;
    if (TObjEneDD::query_teammate_state() == 0) {
        ((TBoss6PlotFalz *)self)->set_visible_flag();
        if ((s32) *(s32 *)((s8 *)self + 0x374) == 0) {
            ((TBoss6PlotFalz *)self)->call_state_action();
        }
        ((TBoss6PlotFalz *)self)->run_phase_action();
    }
}

void TBoss6PlotFalz::run_death_reaction() {  }

void handle_6xA3_olga_flow_boss_actions(game_command_header *command) {
    OlgaFlowPlotActionMsg *message = reinterpret_cast<OlgaFlowPlotActionMsg *>(command);
    TBoss6PlotFalz *boss;
    s8 phase;
    s8 mode;
    message->swap_entity_id();
    boss = (TBoss6PlotFalz *)get_enemy_entity(message->header.client_id);
    if (boss != NULL && boss == reinterpret_cast<TBoss6PlotFalz *>(TBoss6PlotFalz__instance)) {
        phase = message->phase;
        if (phase >= 0 && phase < 9 && phase != boss->get_scene_state()) {
            boss->set_state(phase);
        }
        mode = message->mode;
        if (mode >= 0) {
            boss->m_37c = mode;
        }
    }
}

}


void TBoss6PlotFalz::send_6xA3_action(s8 phase) {
    struct {
        OlgaFlowPlotActionMsg message;
        u8 stack_padding[4];
    } storage;
    if (phase_state == 0) {
        storage.message.initialize();
        storage.message.header.client_id = entity_id;
        storage.message.phase = phase;
        storage.message.mode = static_cast<s8>(127.0f * (3.0517578125e-05f * static_cast<f32>(rand())));
        storage.message.send();
    }
}

TBoss6PlotFalz::~TBoss6PlotFalz() {
    switch (m_378) {
    case 7:
    case 8:
        send_entity_set_flags();
        break;
    }
    if (((TBoss6PlotFalz *)this)->is_ending_or_split_screen() == 0) {
        TLobby::stop_audio_streams();
        if (m_378 == 7) {
            play_area_music("HALL.adx");
        }
    }
    if (fade != NULL) {
        fade->queue_destruction();
        fade = NULL;
    }
    TBoss6PlotFalz::end_cutscene_camera();
    TBoss6PlotFalz::refresh_players_equipment();
    restore_player_cameras();
    TBoss6PlotFalz::queue_instance_destruction();
    TBoss6PlotFalz::destroy_static_instance();
    TBoss6PlotFalz__instance = 0;
    TBoss6PlotFalz__fade_amount = -1.0f;
}

#pragma push
#pragma opt_common_subs off
TBoss6PlotFalz::TBoss6PlotFalz(TObject *parent, void *set_data) : TObjEnemy(parent) {
    Loc_802AC9EC sp8;
    saddr temp_r30;
    saddr temp_r29;
    saddr temp_r6;

    m_name = TBoss6PlotFalz__name;
    sub_802AAC98();
    TBoss6PlotFalz__instance = (saddr)this;
    apply_set_data(set_data);
    copy_set_entry(((u8 *)this + 0x388), set_data);
    m_38a = 0;
    if (exchange_object_state(&sp8, 1) != 0) {
        sp8.a = 0;
        sp8.c = 0;
        exchange_object_state(&sp8, 0);
    }
    VecCopy((Vec *)((u8 *)this + 0x44), (const Vec *)(VecCopy((Vec *)((u8 *)this + 0x50), (const Vec *)(VecCopy((Vec *)((u8 *)this + 0x74), (const Vec *)((u8 *)this + 0x38))))));
    VecCopy((Vec *)((u8 *)this + 0x2FC), (const Vec *)((u8 *)this + 0x38));
    velocity.z = 0.0f;
    *(f32 *)((s8 *)this + 0x30C) = 0.0f;
    *(f32 *)((s8 *)this + 0x308) = 0.0f;
    *(s32 *)((s8 *)this + 0x2A8) = 0;
    temp_r30 = (saddr)TLobby::register_boss(0x2C);
    temp_r29 = (saddr)TLobby::dispatch_shared_handler_b(0x2C);
    temp_r6 = (saddr)TLobby::register_object(0x2C);
    bind_enemy_combat_stats((u8 *)temp_r30, (u8 *)temp_r29, (u8 *)temp_r6);
    register_entity_by_id((u8 *)this);
    actorFlags = (s32) (actorFlags | 0x02000000);
    set_visible_flag();
    TBoss6PlotFalz::update_active_flag();
    m_3cc = 0;
    m_3d0 = 0;
    m_3d4 = 0;
    m_3d8 = 0;
    fade = create_boss4_fade();
    tube = NULL;
    ensure_field384();
    TBoss6PlotFalz__type1_instance = NULL;
    TBoss6PlotFalz__type2_instance = NULL;
    m_3dc = 0;
    TBoss6PlotFalz__fade_amount = (-1.0f);
    m_37c = 0;
    m_378 = -1;
    set_state(0);
}
#pragma pop

void TBoss6PlotFalz::free_all() { TBoss4DarkFalz::free_global_instance(); TBoss6Tube::free_resources(); TBoss6Rock::free_data(); TItemEffOrgaFlowShot__sub_80357204(); delete boss6_scene_archive; boss6_scene_archive = NULL; }

void TBoss6PlotFalz::load_resources() {
    BmlResource *resource = new BmlResource(5, &boss6_plot_falz_resource_descriptor, 0, 0, NULL);
    boss6_scene_archive = resource;
    if (resource != NULL) {
        clear_boss6_player_snapshots();
        TItemEffOrgaFlowShot__sub_80357210();
        TBoss6Rock::load_resources();
        TBoss6Tube::load_resources();
        fn_802E52AC();
    }
}

s32 TBoss6PlotFalz::create(saddr set_data) {
    return (saddr) new TBoss6PlotFalz(new TObjControl((TObject *)tl_04), (void *)set_data);
}

s32 TBoss6PlotFalz::get_scene_state() { return m_378; }

BmlResource *TBoss6PlotFalz::get_scene_archive() { return boss6_scene_archive; }

u16 boss6_plot_falz_player_order_table[4];
saddr TBoss6PlotFalz__instance;
TBoss6Type1 *TBoss6PlotFalz__type1_instance;
TBoss6Type2 *TBoss6PlotFalz__type2_instance;
s32 plot_falz_phase;
