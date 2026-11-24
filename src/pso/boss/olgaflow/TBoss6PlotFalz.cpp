#include "pso/render/StripBufferPair.h"
#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "pso/system/memory.h"
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
#include "pso/boss/olgaflow/TBoss6Type2_8036DC80.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/system/task/TObject.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/boss/darkfalz/TBoss4Fade.h"
#include "types.h"
#include "pso/map/FloorArea.h"
#include "pso/render/NinjaUtil.h"
#include "pso/system/PadRumble.h"
#include "pso/system/vector.h"


#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/base/TObjBase.h"

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
#include "pso/render/StripBufferPair.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/olgaflow/TBoss6Thanks_8035D1F4.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/darkfalz/TObjDFHorming.h"
#include "pso/unk/text_80357058.h"
#include "pso/system/TLoadCtrl_80227390.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D853C.h"
#include "pso/player/PlayerSlots.h"
#include "pso/math/MatrixVector.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/network/client_id.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/object/ending/TObjOnlineEnding.h"

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
// warp_nearby_players carries players within 150 of warp_origin to the same offset from the
// arena center; place_players_in_warp_circle rings them around warp_circle_center; the default
// targets are what get_target_pos_b/_a return while Type1/Type2 is gone.
const Vec boss6_plot_falz_arena_center = { -10000.0f, 0.0f, 0.0f };
const Vec boss6_plot_falz_warp_circle_center = { -10000.0f, 10.0f, 0.0f };
const Vec boss6_plot_falz_warp_origin = { 0.0f, 0.0f, 0.0f };
const Vec boss6_plot_falz_type1_default_target = { 0.0f, 0.0f, 0.0f };
const Vec boss6_plot_falz_type2_default_target = { -10000.0f, 0.0f, 0.0f };

extern "C" {

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss6PlotFalz::update_random_shake() {
    if (shake_active != 0) {
        s32 n = shake_timer - 1;
        shake_timer = n;
        if (n < 0) {
            TCameraCtrl::set_shake_preset(shake_preset);
            shake_timer = (s32)(60.0f * (3.0517578125e-05f * (f32)rand()) + 60.0f);
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

u16 TBoss6PlotFalz::get_sorted_player(s32 i) {
    if (i < 0 || i >= 4) return 0xFFFF;
    return boss6_plot_falz_player_order_table[i];
}

s32 TBoss6PlotFalz::sort_active_players() {
    s32 vals[4];
    s32 i;
    s32 j;
    s32 n;
    TObjPlayer *p;
    s32 t;
    s32 k;
    u16 s;
    for (i = 0; i < 4; i++) {
        boss6_plot_falz_player_order_table[i] = 0xFFFF;
        vals[i] = -1;
    }
    n = 0;
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != NULL && TBoss6PlotFalz::is_active(p) != 0 && p->hp != 0) {
            boss6_plot_falz_player_order_table[n] = p->get_entity_id();
            vals[n] = p->hp;
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
    TObjPlayer *p;

    n = 0;
    for (i = 0; i < registered_player_count; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != NULL && TBoss6PlotFalz::is_active(p) != 0) {
            ids[n] = p->get_entity_id();
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

extern "C" {

s32 TBoss6PlotFalz::is_state_1f(TObjPlayer *player) {
    if (player == NULL || player->get_area() != AREA_OLGA_FLOW) {
        return 0;
    }
    return 1;
}


void TBoss6PlotFalz::run_phase_action() {
    TBoss6PlotFalzAction action = boss6_plot_falz_script_states[this->state_index].update;
    if (action != 0) {
      (this->*action)();
    }
    update_random_shake();
}

void TBoss6PlotFalz::call_state_action() {
    TBoss6PlotFalzAction action = boss6_plot_falz_script_states[this->state_index].tick;
    if (action != 0) {
      (this->*action)();
    }
}

void TBoss6PlotFalz::set_state_2() { shake_timer = 0; shake_preset = 2; }
void TBoss6PlotFalz::reset_state() { shake_timer = 0; shake_preset = 0; }
void TBoss6PlotFalz::activate_warp() { if (tube) tube->activate_warp(); }
void TBoss6PlotFalz::free_child() { if (tube) tube->start_wobble(); }
void TBoss6PlotFalz::set_state(s32 state) {
    if (state < 0 || state >= 9) {
        return;
    }
    if (this->state_index != -1) {
        TBoss6PlotFalzAction action = boss6_plot_falz_script_states[this->state_index].leave;
        if (action != 0) {
            (this->*action)();
        }
    }
    this->state_index = state;
    TBoss6PlotFalzAction action = boss6_plot_falz_script_states[this->state_index].enter;
    if (action != 0) {
        (this->*action)();
    }
}

}

extern "C" {
s32 is_local_client_floor_leader();

void TBoss6PlotFalz::set_visible_flag() {
    if (is_local_client_floor_leader() != 0) {
        not_floor_leader = 0;
        return;
    }
    not_floor_leader = 1;
}

void TBoss6PlotFalz::spawn_player_hit_effects() {
    Vec v;
    TObjPlayer *p;
    s32 i;
    f32 k;
    if (TBoss6Thanks__sub_8035D270() != 0) {
        play_sound_effect(0x40033231, 0, 0, 0);
        k = 12.5f;
        for (i = 0; i < registered_player_count; i++) {
            p = TObjPlayer::get_player_data(i);
            if (TBoss6PlotFalz::is_state_1f(p) != 0) {
                VecCopy(&v, &p->position);
                v.y += k;
                spawn_particle_effect(&v, 0x29);
            }
        }
    }
}

}
// The record exchange_object_state reads and writes.
struct TBoss6PlotFalzStateRecord {
    s32 flags;
    s16 pad_04;
    s16 value;
    s32 pad_08;
};

void TBoss6PlotFalz::award_exp_and_destroy() {
    TBoss6PlotFalz::spawn_player_hit_effects();
    if (is_split_screen() != 0) {
        distribute_experience();
    } else {
        TObjPlayer *pl = get_player_by_client_id(local_client_id);
        if (pl != NULL) {
            Vec saved = body_center;
            VecCopy(&body_center, &pl->body_center);
            distribute_experience();
            VecCopy(&body_center, &saved);
        }
    }
    TBoss6PlotFalzStateRecord record;
    record.flags = 0x800;
    send_6x0A_enemy_state(&record);
    exchange_object_state(&record, 0);
    apply_enemy_state(&record.flags);
    send_entity_set_flags();
    queue_destruction();
}

void TBoss6PlotFalz::apply_fade_alpha(s32 color, f32 alpha) {
    if ((fade != NULL) && !(alpha <= 0.0f)) {
        if (alpha > 1.0f) {
            alpha = 1.0f;
        }
        fade->set_fade(color, alpha);
    }
}
#pragma push
#pragma fp_contract on
s32 TBoss6PlotFalz::rand_vary_count(s32 base, f32 spread) {
    s32 v = (s32)((f32)base * (spread * sin_table_lookup((s32)(65535.0f * (3.0517578125e-05f * (f32)rand())))) + (f32)base);
    if (v < 1) {
        v = 1;
    }
    return v;
}
#pragma pop
f32 TBoss6PlotFalz::arena_center_distance(const Vec *pos) {
    Vec d;
    VecCopy(&d, pos);
    subtract_vector(&d, &boss6_plot_falz_arena_center);
    d.y = 0.0f;
    return vector_length(&d);
}
__declspec(section ".sdata2") const f32 plot_falz_length_epsilon[1] = { 1e-05f };
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
    VecCopy((Vec *)&c, &camera_ctrl_instance->pos);
    VecCopy(&d1, &p);
    subtract_vector(&d1, &pl);
    d1.y = 0.0f;
    if (vector_length(&d1) < r) {
        return 1;
    }
    VecCopy(&d2, &p);
    subtract_vector(&d2, &c);
    d2.y = 0.0f;
    l2 = vector_length(&d2);
    if (l2 < r) {
        return 1;
    }
    if (l2 > 250.0f) {
        return 0;
    }
    VecCopy(&d3, &pl);
    subtract_vector(&d3, &c);
    d3.y = 0.0f;
    l3 = vector_length(&d3);
    if (l3 <= plot_falz_length_epsilon[0] || l3 > 250.0f) {
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
    VecCopy(&a, &p);
    vec3_add_to(&a, &dir);
    VecCopy(&b, &p);
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


f32 TBoss6PlotFalz::cosine_ease(f32 t) {
    if (t < 0.0f) {
        return 0.0f;
    }
    if (t > 1.0f) {
        return 1.0f;
    }
    return 0.5f * (1.0f - cos_table_lookup((s32)(32768.0f * t)));
}
f32 TBoss6PlotFalz::get_value() {
    if ((TBoss6PlotFalz::is_type1_active() == 0) || (TBoss6PlotFalz__type1_instance == NULL)) {
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
s32 TBoss6PlotFalz::is_type1_active() {
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


extern "C" f32 xyz_distance(const void *, const void *);

void TBoss6PlotFalz::release_object() { if (tube != NULL) { tube->queue_destruction(); tube = NULL; } }

s32 TBoss6PlotFalz::get_target_pos_a(Vec *position) {
    if (TBoss6PlotFalz__type2_instance == NULL) {
        VecCopy(position, &boss6_plot_falz_type2_default_target);
        return 0;
    }
    VecCopy(position, &TBoss6PlotFalz__type2_instance->position);
    return 1;
}

s32 TBoss6PlotFalz::get_target_pos_b(Vec *position) {
    if (TBoss6PlotFalz__type1_instance == NULL) {
        VecCopy(position, &boss6_plot_falz_type1_default_target);
        return 0;
    }
    VecCopy(position, &TBoss6PlotFalz__type1_instance->position);
    return 1;
}

void TBoss6PlotFalz::spawn_type2() {
    Boss6BodySpawnParams params;
    if (TBoss6PlotFalz__type2_instance == NULL) {
        params.owner = this;
        params.variant = spawn_variant;
        copy_set_entry(&params.set_entry, &set_entry);
        params.set_entry.room = 1;
        params.set_entry.set_index = set_index + 0x1FF;
        params.set_entry.entity_id = entity_id + 0x1FF;
        TBoss6PlotFalz__type2_instance = TBoss6Type2::create(&params);
    }
}

void TBoss6PlotFalz::spawn_type1() {
    Boss6BodySpawnParams params;
    if (TBoss6PlotFalz__type1_instance == NULL) {
        params.owner = this;
        params.variant = spawn_variant;
        copy_set_entry(&params.set_entry, &set_entry);
        params.set_entry.set_index = set_index + 0x200;
        params.set_entry.entity_id = entity_id + 0x200;
        TBoss6PlotFalz__type1_instance = TBoss6Type1::create(&params);
    }
}

void TBoss6PlotFalz::ensure_field384() {
    if (tube == NULL) {
        tube = TBoss6Tube::create(this);
    }
}

f32 TBoss6Mine::next_random_float(s32 *seed) {
    *seed = next_random_seed(*seed);
    return (f32) (*seed & 0x7FFF) / 32767.0f;
}

s32 next_random_seed(s32 seed) {
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
                start_pad_rumble_client((s16)((f32)amount * (1.0f - d / range)), kind, (s16)((TObjBase *)(p))->get_entity_id());
            }
        }
    }
}
__declspec(section ".sdata2") const s32 plot_falz_fade_render_flags[1] = { 0x8829 };
void TBoss6PlotFalz::set_fade_material_color(f32 f) {
    NJS_ARGB c;
    u32 old = model_render_flags;
    model_render_flags = old & ~0x10;
    saved_model_render_flags = old;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= plot_falz_fade_render_flags[0];
    set_chunk_material_override_pair(0xFF00, 0x800);
    c.a = -1.0f + f;
    c.r = c.g = c.b = 0.0f;
    set_constant_material(&c);
}



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
void TBoss6PlotFalz__sub_802AC008(f32 fade, f32 hp_ratio) {
    f32 tint = 0.25f * hp_ratio;
    TBoss6PlotFalz::apply_fade_material_color(fade, ((-0.75f) * hp_ratio) + 1.0f, tint, tint);
}
#pragma pop

__declspec(section ".sdata2") const s32 plot_falz_tint_render_flags[1] = { 0x8810 };
#pragma push
#pragma fp_contract on
// Tints the material toward (r, g, b) by fade; the render state is saved for reset_fish_globals.
void TBoss6PlotFalz::apply_fade_material_color(f32 fade, f32 r, f32 g, f32 b) {
    NJS_ARGB color;
    if (((-1.0f) != TBoss6PlotFalz__fade_amount) || (fade < 0.0f) || (fade > 1.0f) || (r < 0.0f) || (r > 1.0f) || (g < 0.0f) || (g > 1.0f) || (b < 0.0f) || (b > 1.0f)) {
        fade = 0.0f;
    }
    TBoss6PlotFalz__fade_amount = fade;
    if (0.0f != fade) {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags &= ~0x20;
        model_render_flags |= plot_falz_tint_render_flags[0];
        set_chunk_material_override_pair(0, 0x800);
        set_chunk_blend(0x2500);
        color.a = 1.0f;
        color.r = 1.0f - TBoss6PlotFalz__fade_amount * (1.0f - r);
        color.g = 1.0f - TBoss6PlotFalz__fade_amount * (1.0f - g);
        color.b = 1.0f - TBoss6PlotFalz__fade_amount * (1.0f - b);
        set_constant_material(&color);
    }
}
#pragma pop

s32 is_normal_difficulty(void) {
    if (game_difficulty_selection == 0) {
        return 1;
    }
    return 0;
}

int TBoss6PlotFalz::get_phase() {  return plot_falz_phase; }

extern "C" {

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
        StripBufferPair *e = *(StripBufferPair **)((u8 *)items + j);
        if (e != NULL) {
            e->scroll_uvs(u, v);
        }
    }
}

void Boss6ScrollStrips::free_buffer_pairs() {
    s32 i;
    for (i = 0; i < count; i++) {
        if (items[i] != 0) {
            delete items[i];
            items[i] = 0;
        }
    }
    mem_free(items);
    items = 0;
}

void Boss6ScrollStrips::build_tables(const Boss6StripDesc *descs, s32 n) {
    BmlResource *archive;
    s32 i;
    const Boss6StripDesc *r;
    NJS_OBJECT *t;
    s32 j;
    archive = TBoss6PlotFalz::get_scene_archive();
    if (archive == NULL || descs == NULL || n < 1) {
        return;
    }
    count = n;
    items = NULL;
    items = static_cast<StripBufferPair **>(mem_alloc(count * sizeof(*items)));
    u = 0;
    v = 0;
    for (j = 0; j < count; j++) {
        items[j] = 0;
    }
    for (i = 0; i < count; i++) {
        r = &descs[i];
        t = find_model_node(get_bml_model(archive, r->model), r->node);
        items[i] = new StripBufferPair(t, r->texture_filter);
    }
}

void TBoss6PlotFalz::warp_nearby_players() {
    Vec v;
    s32 i;
    TObjPlayer *p;
    for (i = registered_player_count + registered_enemy_count; i < lbl_805D5868; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p != NULL && p->bodies != NULL && (p->bodies->flags & 0x20000)
            && !(xyz_distance(&boss6_plot_falz_warp_origin, &p->position) > 150.0f)
            && !(xyz_distance(&boss6_plot_falz_arena_center, &p->position) <= 300.0f)) {
            VecCopy(&v, &p->position);
            subtract_vector(&v, &boss6_plot_falz_warp_origin);
            vec3_add_to(&v, &boss6_plot_falz_arena_center);
            v.y = 7.5f;
            VecCopy(&p->position, &v);
            p->refresh_collision_body_centers();
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
        TObjPlayer *p = TObjPlayer::get_player_data(i);
        if (p != NULL && p->get_area() == 0x1F) {
            Vec pos = boss6_plot_falz_warp_circle_center;
            pos.x += 350.0f * sin_table_lookup(ang);
            pos.z += 350.0f * cos_table_lookup(ang);
            p->set_position_from(&pos);
            p->save_previous_position();
            *(s32 *)((u8 *)p->get_rotation() + 4) = ang + 0x8000;
            p->refresh_equipment_slot();
            if (TObjPlayer::is_locally_controlled(p) != 0) {
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





BmlResource *boss6_scene_archive;
extern "C" {

void TBoss6PlotFalz::render() {  }

void TBoss6PlotFalz::run_task() {
    if (TObjEneDD::query_teammate_state() == 0) {
        set_visible_flag();
        if (not_floor_leader == 0) {
            call_state_action();
        }
        run_phase_action();
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
            boss->spawn_variant = mode;
        }
    }
}

}


void TBoss6PlotFalz::send_6xA3_action(s8 phase) {
    struct {
        OlgaFlowPlotActionMsg message;
        u8 stack_padding[4];
    } storage;
    if (not_floor_leader == 0) {
        storage.message.initialize();
        storage.message.header.client_id = entity_id;
        storage.message.phase = phase;
        storage.message.mode = static_cast<s8>(127.0f * (3.0517578125e-05f * static_cast<f32>(rand())));
        storage.message.send();
    }
}

TBoss6PlotFalz::~TBoss6PlotFalz() {
    switch (state_index) {
    case 7:
    case 8:
        send_entity_set_flags();
        break;
    }
    if (((TBoss6PlotFalz *)this)->is_ending_or_split_screen() == 0) {
        TLobby::stop_audio_streams();
        if (state_index == 7) {
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
    TBoss6PlotFalzStateRecord record;
    player_stats *base_params;
    AttackParams *attack_params;
    ActorParamBlock *resistance_params;

    m_name = TBoss6PlotFalz__name;
    reset_child_ids();
    TBoss6PlotFalz__instance = (saddr)this;
    apply_set_data(set_data);
    copy_set_entry(&set_entry, set_data);
    set_entry.kind = 0;
    if (exchange_object_state(&record, 1) != 0) {
        record.flags = 0;
        record.value = 0;
        exchange_object_state(&record, 0);
    }
    VecCopy(&prev_position, VecCopy(&home_position, VecCopy(&center, &position)));
    VecCopy(&body_center, &position);
    velocity.z = 0.0f;
    velocity.y = 0.0f;
    velocity.x = 0.0f;
    target = 0;
    base_params = TLobby::register_boss(0x2C);
    attack_params = TLobby::dispatch_shared_handler_b(0x2C);
    resistance_params = TLobby::register_object(0x2C);
    bind_enemy_combat_stats(base_params, attack_params, resistance_params);
    register_entity_by_id((u8 *)this);
    actorFlags = (s32) (actorFlags | 0x02000000);
    set_visible_flag();
    TBoss6PlotFalz::update_active_flag();
    state_timer = 0;
    shake_active = 0;
    shake_timer = 0;
    shake_preset = 0;
    fade = create_boss4_fade();
    tube = NULL;
    ensure_field384();
    TBoss6PlotFalz__type1_instance = NULL;
    TBoss6PlotFalz__type2_instance = NULL;
    wait_demo = 0;
    TBoss6PlotFalz__fade_amount = (-1.0f);
    spawn_variant = 0;
    state_index = -1;
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

s32 TBoss6PlotFalz::get_scene_state() { return state_index; }

BmlResource *TBoss6PlotFalz::get_scene_archive() { return boss6_scene_archive; }

u16 boss6_plot_falz_player_order_table[4];
saddr TBoss6PlotFalz__instance;
TBoss6Type1 *TBoss6PlotFalz__type1_instance;
TBoss6Type2 *TBoss6PlotFalz__type2_instance;
s32 plot_falz_phase;
