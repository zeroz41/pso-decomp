#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/enemy/EnemyPlacement.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/system/AreaSound.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/map/CsnQuery.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/morfos/TObjEneMorfos.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/enemy/recon/TObjEneRecon.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/FloatRounding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/render/reflection.h"
#include "pso/math/AngleLookup.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/enemy/TUnk_804EF130.h"
#include "pso/system/task/TObject.h"
#include "pso/render/TUnk_80490470.h"
#include "pso/render/TUnk_80494938.h"
#include <stddef.h>
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/sinowzoa/TObjEneMe3SinowZoa.h"
#include "pso/enemy/morfos/TObjEneMorfosArm.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/enemy/berura/TObjEneRe7BeruraPunch.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/object/mine/TOComputerMachine01_8023DD0C.h"
#include "pso/network/IPv6.h"
#include "pso/player/PlayerSlots.h"
#include "pso/animation/ActorAnimationState.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803E2F28.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/object/base/TObjBase.h"
// .rodata holds the table strings, the class name, the 803350AC binding template, then the Vecs in
// reverse .text order and the doubles in .text order: deferred codegen, functions written last to first.
#pragma defer_codegen on









// inferred: the boss, object and handler-a ids 803350AC registers; one each
static const s32 morfos_boss_ids[1] = { 0x40 };
static const s32 morfos_object_ids[1] = { 0x40 };
static const s32 morfos_handler_a_ids[1] = { 0x40 };

extern "C" {
// check_value_in_range called on int arguments: the u16 prototype adds a clrlwi per argument at both calls.
s32 check_value_in_range__13TObjEneMorfosFPvUsUsUs(void *, int, int, int);
}












extern BmlResource *TObjEneMorfos__instance;
extern s32 TObjEneMorfos__phase;
extern Vec *TObjEneMorfos__camera_path_cursor;
extern float morfos_projectile_speed;
extern float morfos_param_table_speed_copy;


void *lbl_804EE0C0[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
CollisionBody morfos_collision_bodies[1] = {
    { { 0.0f, 0.0f, 0.0f }, 8.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
const char *bm_ene_morfos_model_names[4] = {
    "kabe_arm.nj", "kabe_body.nj", "kabe_wall.nj", NULL,
};
const char *bm_ene_morfos_motion_names[7] = {
    "attack_kabe_arm.njm", "attack_kabe_body.njm", "beam_kabe_body.njm", "damage_kabe_body.njm",
    "dead_kabe_body.njm", "wait_kabe_body.njm", NULL,
};
BmlResourceDescriptor morfos_resource_descriptor = {
    "bm_ene_morfos.bml", bm_ene_morfos_model_names, bm_ene_morfos_motion_names, 3, 6,
};
const char *bm_ene_morfos_low_model_names[4] = {
    "lo_kabe_arm.nj", "lo_kabe_body.nj", "kabe_wall.nj", NULL,
};
const char *bm_ene_morfos_low_motion_names[7] = {
    "attack_kabe_arm.njm", "attack_kabe_body.njm", "beam_kabe_body.njm", "damage_kabe_body.njm",
    "dead_kabe_body.njm", "wait_kabe_body.njm", NULL,
};
BmlResourceDescriptor bm_ene_morfos_low_resource_descriptor = {
    "bm_ene_morfos_low.bml", bm_ene_morfos_low_model_names, bm_ene_morfos_low_motion_names, 3, 6,
};
TObjMotionAction morfos_motion_param_table[5] = {
    { 1, 0, 5, 0.5f, 0 },
    { 3, 0, 1, 0.7f, 0 },
    { 3, 0, 2, 0.7f, 0 },
    { 3, 0, 3, 0.7f, 0 },
    { 3, 0, 4, 0.7f, 0 },
};
const char *morfos_class_name = "TObjEneMorfos";

f32 lbl_805434D0[3];
AttackParams *morfos_attack_params[3];

void TObjEneMorfos::load_static_data() {
    BmlResource *mgr;
    s32 i;

    if (is_split_screen() != 0) {
        mgr = load_enemy_bml_resource(&bm_ene_morfos_low_resource_descriptor);
    } else {
        mgr = load_enemy_bml_resource(&morfos_resource_descriptor);
    }
    TObjEneMorfos__instance = mgr;
    lbl_805434D0[0] = 0.0f;
    lbl_805434D0[1] = 0.0f;
    lbl_805434D0[2] = 0.0f;
    TObjEneMorfos__phase = 0;
    TObjEneMorfos__camera_path_cursor = NULL;
    morfos_body_scroll_polygons = ((NJS_CNK_MODEL *)mgr->models[1].model->child->model)->polygon_list;
    morfos_wall_scroll_polygons = ((NJS_CNK_MODEL *)mgr->models[2].model->model)->polygon_list;
    morfos_body_scroll_tick = 0;
    morfos_wall_scroll_tick = 0;
    for (i = 0; i < 1; i++) {
        morfos_base_params[i] = TLobby::register_boss(morfos_boss_ids[i]);
    }
    for (i = 0; i < 2; i++) {
        morfos_attack_params[i] = TLobby::dispatch_shared_handler_b(morfos_attack_param_ids[i]);
    }
    for (i = 0; i < 1; i++) {
        morfos_resistance_params[i] = TLobby::register_object(morfos_object_ids[i]);
    }
    for (i = 0; i < 1; i++) {
        (&TObjEneMorfos__param_table)[i] = (MorfosParams *)TLobby::dispatch_shared_handler_a(morfos_handler_a_ids[i]);
    }
    TObjEneMorfosArm::init_global();
    {
        NpcAnimationBinding desc = { TObjEneMorfos__instance->motions, morfos_motion_param_table, 0, 0, 6 };
        TObjNpcEnemy::register_animated_chunk(0x4D, TObjEneMorfos__instance->models[1].model,
                                TObjEneMorfos__instance->models[1].texlist, &desc,
                                8.0f, 0.0f);
    }
}

void *TObjEneMorfos::create(void *set_data) {
    return new TObjEneMorfos((TObject *)tl_04, static_cast<EnemyPlacement *>(set_data));
}

void TObjEneMorfos::unload_static_data() {
    TObjEneMorfosArm::free_global();
    if (TObjEneMorfos__instance != NULL) {
        delete TObjEneMorfos__instance;
        TObjEneMorfos__instance = NULL;
    }
}
TObjEneMorfos::TObjEneMorfos(TObject *parent, EnemyPlacement *set_data) : TObjEneDD_ST(parent) {
    m_name = morfos_class_name;
    invoke_initialization_hook(set_data);
    init_target_offsets();
    init_instance();
    burst_emitter = NULL;
}
void TObjEneMorfos::init_instance() {
    s32 i;

    init_position_vectors();
    model = TObjEneMorfos__instance->models[1].model;
    this->texlist = TObjEneMorfos__instance->models[1].texlist;
    init_model(morfos_collision_bodies, 1);
    set_action_table(morfos_motion_param_table);
    set_motion_list(TObjEneMorfos__instance->motions);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_requested_action(this->requested_action);
    reset_hp(morfos_base_params[morfos_base_params_index[0]], morfos_attack_params[morfos_attack_params_index[0]], morfos_resistance_params[morfos_resistance_params_index[0]]);
    load_params();
    set_state_8();
    this->movementParameters = lbl_804EE0C0;
    initialize_enemy_state(0x42);
    this->wall_reach = 10.0f;
    enemy_init_acquire_period(0x3C);
    enemy_init_validate_period(0x3C);
    morfos_flags = 0;
    ground_attributes = 0;
    VecCopy(&reflection_point, &position);
    texture_scroll = 0;
    body_fade.reset_color();
    wall_fade.reset_color();
    for (i = 0; i < 4; i++) {
        part_fades[i].activate_and_dispatch();
    }
    node_points[0].x = 0.0f;
    node_points[0].y = 0.0f;
    node_points[0].z = 0.0f;
    node_points[1].x = 0.0f;
    node_points[1].y = 0.0f;
    node_points[1].z = 0.0f;
    step = 0;
    this->counter = 0;
    this->target_angle = 0;
    burst_start_angle = 0;
    this->accum = 0.0f;
    unk_4C8 = 0.0f;
    this->walk_dir.x = 0.0f;
    walk_dir.y = 0.0f;
    this->walk_dir.z = 0.0f;
    this->set_intangible();
    this->mode = 0;
    dispatch_action(this->mode, 4);
}

TObjEneMorfos::~TObjEneMorfos() {
    if (burst_emitter != NULL) {
        burst_emitter->queue_destruction();
        burst_emitter = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneMorfos::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    if (this->update_status_effects() != 4) {
        this->update_action_state();
        if ((s32) morfos_body_scroll_tick != (s32) actor_frame_tick) {
            morfos_body_scroll_tick = actor_frame_tick;
            TObjPlayer__sub_8023DEE0(morfos_body_scroll_polygons, (s16)((s16) texture_scroll), (s16)(0), (u16)(2U));
        }
        if ((s32) morfos_wall_scroll_tick != (s32) actor_frame_tick) {
            morfos_wall_scroll_tick = actor_frame_tick;
            TObjPlayer__sub_8023DEE0(morfos_wall_scroll_polygons, (s16)(0), (s16) ((f32) texture_scroll / 2.0f), (u16)(0U));
        }
    }
    this->set_hover_target_position();
    this->submit_default_cursor_candidate();
    this->render_minimap_dot();
    this->update_ground_probe();
}

void TObjEneMorfos::refresh_target() {  }

void TObjEneMorfos::run_death_reaction() { if (this->mode != 11) { transition_enemy_state((saddr)((void*)11)); } }

f32 TObjEneMorfos::receive_physical_attack(void *attacker, f32 scale) {
    Vec v;
    f32 ret = 0.0f;
    s32 d;
    if (attacker != NULL) {
        VecCopy(&v, &((TObjChara *)attacker)->body_center);
        subtract_vector(&v, &body_center);
        d = angle_difference_abs(rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z)));
    } else {
        d = 0;
    }
    if (morfos_flags & 0x10) {
        if (d < 0x4000) {
            spawn_particle_effect(node_points, 0x214);
            spawn_particle_effect(node_points, 0x21A);
        } else {
            morfos_flags &= ~0x10;
            morfos_flags |= 0x20;
            ret = TObjChara::receive_physical_attack(attacker, scale);
        }
    } else {
        ret = TObjChara::receive_physical_attack(attacker, scale);
    }
    return ret;
}

void TObjEneMorfos::run_hit_reaction() {
    Vec v;
    TObjPlayer *pl;
    s32 d;
    if (this->mode == 0xA) {
        return;
    }
    pl = get_player_by_client_id(this->attacker_id);
    if (pl != 0) {
        VecCopy(&v, &pl->body_center);
        subtract_vector(&v, &body_center);
        d = angle_difference_abs(this->rotation_y, (s32)(10430.38043493439 * atan2_float(v.x, v.z)));
    } else {
        d = 0;
    }
    if (d < 0x4000) {
        clear_attack_receipts();
        if (check_low_hp_trigger() == 0) {
            try_enter_low_hp_state();
        }
    } else if (morfos_flags & 4) {
        clear_attack_receipts();
    } else {
        transition_enemy_state((saddr)((void *)0xA));
    }
}

void TObjEneMorfos::run_miss_reaction() {  }

s32 TObjEneMorfos::check_low_hp_trigger() {
    if (!(morfos_flags & 0x10) && ((s16) this->hp <= (s32) ((s16) this->hpmax / 2)) && (this->random_ratio() <= wall_chance)) {
        morfos_flags = (s32) (morfos_flags | 0x10);
        return 1;
    }
    return 0;
}

s32 TObjEneMorfos::try_enter_low_hp_state() {
    if (((s16) this->hp <= (s32) ((s16) this->hpmax / 2)) && (this->random_ratio() <= burst_chance)) {
        this->transition_enemy_state((saddr)((void*)(9)));
        return 1;
    }
    return 0;
}

s32 TObjEneMorfos::approach_value(s32 goal, s32 max_step) {
    s32 temp_r3;
    s32 var_r31;

    var_r31 = 0;
    temp_r3 = angle_diff_s16(this->rotation_y, goal);
    if (temp_r3 > max_step) {
        this->rotation_y = (s32) (this->rotation_y + max_step);
    } else if (temp_r3 < (s32) -max_step) {
        this->rotation_y = (s32) (this->rotation_y - max_step);
    } else {
        this->rotation_y = goal;
        var_r31 = 1;
    }
    return var_r31;
}

void TObjEneMorfos::set_hover_target_position() {
    this->body_center.x = position.x;
    this->body_center.y = (f32) (20.0f + position.y);
    this->body_center.z = (f32) position.z;
    VecCopy(&center, &body_center);
}
void TObjEneMorfos::update_body_colliders() {
    this->bodies->offset.y = (f32) (this->body_center.y - position.y);
}

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void TObjEneMorfos::init_target_offsets() {
    if ((s32) this->variant <= 0) {
        can_walk = 1;
    } else {
        can_walk = 0;
    }
    walk_speed = (f32) (0.28f + parameters[0]);
    if (walk_speed < 0.1f) {
        walk_speed = 0.1f;
    }
    walk_duration = (f32) (20.0f + parameters[1]);
    if (walk_duration < 5.0f) {
        walk_duration = 5.0f;
    }
    wall_chance = (f32) (0.1f + parameters[2]);
    burst_chance = (f32) (0.1f + parameters[3]);
}
#pragma pop

void TObjEneMorfos::load_params() {
    morfos_projectile_speed = TObjEneMorfos__param_table->projectile_speed;
    morfos_param_table_speed_copy = TObjEneMorfos__param_table->projectile_speed_b;
}

#pragma push
#pragma fp_contract on
s32 TObjEneMorfos::select_target_in_view() {
    Vec v;
    s32 n;
    TObjPlayer *p;
    u16 id;
    s32 i;
    f32 dz;
    f32 dx;
    f32 cosLim;
    f32 d;
    f32 best;
    best = 0.0f;
    id = 0xFFFF;
    cosLim = cos_table_lookup(0xAAA);
    dx = sin_table_lookup(rotation_y);
    dz = cos_table_lookup(rotation_y);
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = TObjPlayer::get_player_data(i);
        if (p->is_alive() == 0) {
            continue;
        }
        VecCopy(&v, &p->position);
        subtract_vector(&v, &body_center);
        v.y = 0.0f;
        d = normalize_vector_xz((Vec *)(&v));
        if (d < 400.0f && d > best && dx * v.x + dz * v.z > cosLim &&
            csnLookAt(&body_center, &p->body_center) == 0) {
            id = p->get_entity_id();
            best = d;
        }
    }
    if (id != 0xFFFF) {
        enemy_set_target_id(this, id);
        return 1;
    }
    return 0;
}
#pragma pop


void TObjEneMorfos::play_sound_in_band() {
    if ((this->is_passing_frame(4.0f) != 0) || (this->is_passing_frame(20.0f) != 0)) {
        play_sound_effect(0x4003A823, &position, 0, 0);
    }
}

s32 TObjEneMorfos::check_confused() {
    return is_confused() ? 1 : 0;
}

void TObjEneMorfos::dispatch_action(u32 state, s32 ev) {
    switch (state) {
    case 0: this->handle_event_transition(ev); break;
    case 1: state_fade_in(ev); break;
    case 3: this->state_appear(ev); break;
    case 2: state_hidden(ev); break;
    case 7: state_fade_out(ev); break;
    case 4: state_walk(ev); break;
    case 5: state_attack(ev); break;
    case 6: state_beam(ev); break;
    case 9: this->state_rotating_projectile_burst(ev); break;
    case 8: this->state_patrol(ev); break;
    case 10: state_damage(ev); break;
    case 11: this->state_death(ev); break;
    }
}

void TObjEneMorfos::handle_event_transition(s32 ev) {
    switch (ev) {
    case 0:
        return;
    case 3:
        transition_enemy_state((s32)1);
        break;
    }
}

void TObjEneMorfos::state_fade_in(s32 ev) {
    s32 temp_r31;
    switch (ev) {
    case 4:
        this->requested_action = 0;
        this->set_intangible();
        morfos_flags = (s32) (morfos_flags & ~5);
        morfos_flags = (s32) (morfos_flags | 2);
        this->set_field_378(3);
        body_fade.start_fade_in();
        wall_fade.start_fade_in();
        play_area_se_with_particle(&position);
        return;
    case 3:
        temp_r31 = wall_fade.advance_toward_max();
        if ((body_fade.advance_toward_max() != 0) && (temp_r31 != 0)) {
            this->transition_enemy_state((s32)3);
        }
        return;
    case 0:
        this->advance_animation();
        this->update_ground_contact();
        this->update_body_colliders();
        return;
    case 5:
        morfos_flags = (s32) (morfos_flags & 0xFFFFFFFD);
        break;
    }
}

void TObjEneMorfos::state_appear(s32 ev) {

    switch (ev) {
    case 4:
        this->requested_action = 0;
        this->set_intangible();
        morfos_flags = (s32) (morfos_flags & 0xFFFFFFF8);
        set_field_378(4);
        texture_scroll = 0;
        step = 0;
        this->accum = 0.0f;
        return;
    case 3:
        if (((s32) step == 2) && (check_confused() == 0)) {
            transition_enemy_state((s32)4);
        }
        break;
    case 0:
        switch (step) {
        case 0:
            if (update_linked_position(400.0f) != 0) {
                step = 1;
                enemy_copy_target_destination();
                update_velocity();
            }
            break;
        case 1:
            this->accum += 0.5f;
            texture_scroll = (s32) floor_to_float(this->accum);
            if ((s32) texture_scroll >= 0xC) {
                texture_scroll = 0xC;
                step = 2;
            }
            TObjPlayer::play_effect_if_v2(-0x100);
            break;
        }
        this->update_ground_contact();
        this->check_collisions();
        return;
    case 5:
        texture_scroll = 0xC;
        this->clear_intangible();
        break;
    }
}

void TObjEneMorfos::state_hidden(s32 ev) {
    switch (ev) {
    case 4:
        this->requested_action = 0;
        this->set_intangible();
        morfos_flags = (s32) (morfos_flags & 0xFFFFFFF9);
        morfos_flags = (s32) (morfos_flags | 1);
        this->set_field_378(2);
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &position);
        VecCopy(&body_center, &position);
        body_fade.reset_color();
        wall_fade.reset_color();
        return;
    case 3:
        if (this->update_linked_position(400.0f) != 0) {
            this->transition_enemy_state((s32)1);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneMorfos::state_fade_out(s32 ev) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r31;

    switch (ev) {
    case 4:
        this->requested_action = 0;
        this->set_intangible();
        morfos_flags = (s32) (morfos_flags & 0xFFFFFFF8);
        this->set_field_378(7);
        step = 0;
        counter = 0;
        return;
    case 3:
        if (check_confused() == 0) {
            temp_r0 = step;
            if (temp_r0 == 2) {
                this->transition_enemy_state((s32)4);
            } else if (temp_r0 == 3) {
                this->transition_enemy_state((s32)2);
            }
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        temp_r0_2 = step;
        switch (temp_r0_2) {
        case 0:
            if (this->update_linked_position(400.0f) != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
                step = 2;
            } else {
                counter = (s32) (counter + 1);
                if ((s32) counter > 0x3C) {
                    counter = 0;
                    step = 1;
                    body_fade.reset_color();
                    wall_fade.reset_color();
                    morfos_flags = (s32) (morfos_flags | 2);
                }
            }
            break;
        case 1:
            temp_r31 = wall_fade.decay_value_toward_floor();
            if ((body_fade.decay_value_toward_floor() != 0) && (temp_r31 != 0)) {
                step = 3;
            }
            break;
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    }
}

void TObjEneMorfos::state_walk(s32 ev) {
    switch (ev) {
    case 4:
        this->requested_action = 0;
        this->clear_intangible();
        morfos_flags = (s32) (morfos_flags & 0xFFFFFFF8);
        this->set_field_378(4);
        step = 0;
        target_angle = 0;
        counter = 0;
        accum = 0.0f;
        walk_dir.x = 0.0f;
        walk_dir.y = 0.0f;
        walk_dir.z = 0.0f;
        return;
    case 3:
        if (check_confused() == 0) {
            if (current_target == NULL) {
                this->transition_enemy_state((s32)7);
            } else if (destination_distance <= 30.0f) {
                if (this->random_ratio() < 0.3f) {
                    this->transition_enemy_state((s32)6);
                } else {
                    this->transition_enemy_state((s32)5);
                }
            } else if ((s32) counter == 3) {
                this->transition_enemy_state((s32)6);
            }
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        this->play_sound_in_band();
        if (this->update_linked_position(400.0f) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
        }
        switch (counter) {
        case 0:
            if (this->enemy_has_live_target() != 0) {
                target_angle = (s32) (u16) (s32) (10430.38043493439 * ((f64 (*)(f32, f32)) atan2_float)((f32) (destination_direction.x), (f32) (destination_direction.z)));
            } else {
                target_angle = (s32) this->rotation_y;
            }
            counter = 1;
        case 1:
            if (this->approach_value(target_angle, TObjEneMorfos__param_table->turn_step) != 0) {
                counter = 2;
                walk_dir.x = sin_table_lookup((int) (this->rotation_y));
                walk_dir.z = cos_table_lookup((int) (this->rotation_y));
            }
            this->update_ground_contact();
            break;
        case 2:
            if (TObjEneDD::check_v2_mode() != 0) {
                if (this->select_target_in_view() != 0) {
                    this->enemy_copy_target_destination();
                    this->update_velocity();
                    counter = 3;
                } else if (this->enemy_has_live_target() != 0) {
                    target_angle = (s32) (u16) (s32) (10430.38043493439 * ((f64 (*)(f32, f32)) atan2_float)((f32) (destination_direction.x), (f32) (destination_direction.z)));
                } else {
                    target_angle = (s32) this->rotation_y;
                }
                this->approach_value(target_angle, TObjEneMorfos__param_table->turn_step);
            } else {
                accum = (f32) (accum + walk_speed);
                if (accum >= walk_duration) {
                    accum = 0.0f;
                    step = (s32) (step + 1);
                    if (((s32) step >= 2) && (this->select_target_in_view() != 0)) {
                        step = 0;
                        this->enemy_copy_target_destination();
                        this->update_velocity();
                        counter = 3;
                    } else {
                        counter = 0;
                    }
                }
                if ((s32) can_walk == 1) {
                    this->move_clamped_on_ground((f32) (walk_dir.x), (f32) (walk_dir.z), (f32) (walk_speed));
                }
            }
            break;
        }
        this->check_collisions();
        break;
    }
}
void TObjEneMorfos::state_beam(s32 ev) {
    switch (ev) {
    case 4:
        this->clear_intangible();
        morfos_flags = (s32) (morfos_flags & 0xFFFFFFF8);
        this->set_field_378(6);
        if (this->enemy_has_live_target() != 0) {
            this->target_angle = (s32) (u16) ((s32) (10430.38043493439 * atan2_float(this->destination_direction.x, destination_direction.z)) + 0x8000);
            step = 0;
            this->counter = 0;
            this->requested_action = 0;
            play_sound_effect(0x4003A528, &position, 0, 0);
            return;
        }
        step = 6;
        return;
    case 3:
        if (((s32) step == 6) && (check_confused() == 0)) {
            this->transition_enemy_state((s32)4);
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        switch (step) {
        case 0:
            if (this->approach_value(this->target_angle, TObjEneMorfos__param_table->attack_turn_step) != 0) {
                step = 1;
                this->requested_action = 2;
                spawn_particle_effect(node_points, 0x212);
            }
            break;
        case 1:
            if (this->is_passing_frame(1.0f) != 0) {
                step = 2;
            }
            break;
        case 2:
            if (this->is_passing_frame(6.0f) != 0) {
                play_sound_effect(0x4003AD24, &position, 0, 0);
                new TUnk_804EF130(node_points, (u16)(this->target_angle + 0x8000), this);
                step = 3;
            }
            break;
        case 3:
            if (this->get_flag_b4() != 0) {
                this->requested_action = 0;
                this->counter = (this->counter + 1);
                if (this->enemy_has_live_target() != 0) {
                    if ((s32) this->counter >= 2) {
                        this->target_angle = (s32) (10430.38043493439 * atan2_float(this->destination_direction.x, destination_direction.z));
                        step = 5;
                    } else {
                        this->requested_action = 0;
                        step = 4;
                        step_timer = 0;
                    }
                } else if (this->select_target_in_view() != 0) {
                    this->enemy_copy_target_destination();
                    this->update_velocity();
                    if ((s32) this->counter >= 2) {
                        this->target_angle = (s32) (10430.38043493439 * atan2_float(this->destination_direction.x, destination_direction.z));
                        step = 5;
                        play_sound_effect(0x4003A528, &position, 0, 0);
                    } else {
                        this->requested_action = 0;
                        step = 4;
                        step_timer = 0;
                    }
                } else {
                    this->target_angle = (s32) (u16) (this->target_angle + 0x8000);
                    step = 5;
                }
            }
            break;
        case 4:
            step_timer = (s32) (step_timer + 1);
            if ((s32) step_timer >= TObjEneMorfos__param_table->retreat_wait) {
                if (this->enemy_has_live_target() != 0) {
                    this->enemy_copy_target_destination();
                    this->update_velocity();
                    this->target_angle = (s32) (u16) ((s32) (10430.38043493439 * atan2_float(this->destination_direction.x, destination_direction.z)) + 0x8000);
                    step = 0;
                    play_sound_effect(0x4003A528, &position, 0, 0);
                } else {
                    step = 6;
                }
            }
            break;
        case 5:
            if (this->approach_value(this->target_angle, TObjEneMorfos__param_table->attack_turn_step) != 0) {
                step = 6;
            }
            break;
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    }
}

#pragma push
#pragma opt_common_subs off
void TObjEneMorfos::state_rotating_projectile_burst(s32 ev) {
    s32 old;
    s32 n;
    s32 i;
    TObjPlayer *pl;
    switch (ev) {
    case 4:
        clear_intangible();
        morfos_flags &= ~3;
        morfos_flags |= 4;
        set_field_378(4);
        target_angle = 0;
        burst_start_angle = 0;
        step = 0;
        step_timer = 0;
        requested_action = 0;
        burst_emitter = create_particle_emitter(node_points, 0x10A);
        break;
    case 3:
        if (step == 5 && check_confused() == 0) {
            transition_enemy_state((s32)4);
        }
        break;
    case 0:
        advance_animation();
        switch (step) {
        case 0:
            if (burst_emitter != NULL) {
                burst_emitter->set_position(node_points);
            }
            burst_start_angle = rotation_y;
            rotation_y = rotation_y + TObjEneMorfos__param_table->charge_spin_step;
            step_timer = step_timer + 1;
            if (step_timer >= TObjEneMorfos__param_table->charge_frames) {
                step = 1;
                counter = 0;
                if (burst_emitter != NULL) {
                    burst_emitter->queue_destruction();
                    burst_emitter = NULL;
                }
            }
            break;
        case 1: {
            old = rotation_y;
            rotation_y += TObjEneMorfos__param_table->attack_turn_step;
            n = TLobby::get_game_mode();
            for (i = 0; i < n; i++) {
                pl = TObjPlayer::get_player_data(i);
                if (pl->is_alive() != 0) {
                    if (get_room() == pl->get_room()) {
                        enemy_copy_target_destination();
                        update_velocity();
                        target_angle = (u16)((s32)(10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z)) + 0x8000);
                        if (check_value_in_range__13TObjEneMorfosFPvUsUsUs(this, old, rotation_y, target_angle) != 0) {
                            rotation_y = target_angle;
                            step = 2;
                            requested_action = 2;
                            break;
                        }
                    }
                }
            }
            if (step == 1 && check_value_in_range__13TObjEneMorfosFPvUsUsUs(this, old, rotation_y, burst_start_angle) != 0) {
                step = 2;
                requested_action = 2;
            }
            break;
        }
        case 2:
            spawn_particle_effect(node_points, 0x212);
            if (is_passing_frame(1.0f) != 0) {
                step = 3;
            }
            break;
        case 3:
            if (is_passing_frame(6.0f) != 0) {
                play_sound_effect(0x4003AD24, &position, 0, 0);
                new TUnk_804EF130(node_points, (u16)(rotation_y + 0x8000), this);
                step = 4;
            }
            break;
        case 4:
            if (get_flag_b4() != 0) {
                requested_action = 0;
                counter = counter + 1;
                if (game_difficulty_selection == 3 || game_difficulty_selection == 2) {
                    if (counter >= 5) {
                        step = 5;
                        break;
                    }
                } else if (counter >= 4) {
                    step = 5;
                    break;
                }
                burst_start_angle = rotation_y;
                rotation_y = rotation_y + TObjEneMorfos__param_table->attack_turn_step;
                step = 1;
            }
            break;
        }
        update_ground_contact();
        check_collisions();
        break;
    case 5:
        if (burst_emitter != NULL) {
            burst_emitter->queue_destruction();
            burst_emitter = NULL;
        }
        break;
    }
}
#pragma pop


void TObjEneMorfos::state_attack(s32 ev) {
    switch (ev) {
    case 4:
        this->requested_action = 0;
        this->clear_intangible();
        morfos_flags = (s32) (morfos_flags & 0xFFFFFFF8);
        this->set_field_378(5);
        step = 0;
        this->counter = 0;
        break;
    case 3:
        switch (step) {
        case 0:
            if ((check_confused() == 0) && ((void *) this->current_target == NULL)) {
                this->transition_enemy_state((s32)7);
            }
            break;
        case 3:
            this->transition_enemy_state((s32)4);
            break;
        }
        break;
    case 5:
        break;
    case 0:
        this->advance_animation();
        switch (step) {
        case 0:
            if (enemy_validate_retained_target(this) != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
                if (this->approach_value((s32) (10430.38043493439 * atan2_float(this->destination_direction.x, destination_direction.z)), TObjEneMorfos__param_table->attack_turn_step) != 0) {
                    step = 1;
                    this->requested_action = 1;
                    play_sound_effect(0x4003A725, &position, 0, 0);
                    TObjEneMorfosArm::create(this, this);
                } else if (destination_distance >= 30.0f) {
                    step = 3;
                }
                this->play_sound_in_band();
            }
            break;
        case 1:
            if ((this->is_passing_frame(8.0f) != 0) && (this->enemy_check_target_valid() != 0)) {
                if (this->current_target->select_melee_contact_body(this, 1.0f) != 0) {
                    this->current_target->receive_physical_attack(this, 1.0f);
                    this->current_target->apply_knockback_from_attacker((u8 *)this, 5.0f);
                }
            }
            if (this->get_flag_b4() != 0) {
                step = 2;
                this->counter = 0;
                this->requested_action = 0;
            }
            break;
        case 2:
            this->counter = (this->counter + 1);
            if ((s32) this->counter >= 0x32) {
                step = 3;
                this->requested_action = 0;
            }
            break;
        }
        this->update_ground_contact();
        this->check_collisions();
        break;
    }
}

void TObjEneMorfos::state_patrol(s32 ev) {
    switch (ev) {
    case 4:
        this->requested_action = 0;
        this->clear_intangible();
        morfos_flags = (s32) (morfos_flags & 0xFFFFFFF8);
        set_field_378(8);
        step = 0;
        this->target_angle = (this->rotation_y + 0x3800);
        break;
    case 3:
        if ((s32) this->rotation_y >= (s32) this->target_angle) {
            transition_enemy_state((s32)6);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        if (is_motion_blending() == 0) {
            this->play_speed = 1.6f;
        }
        this->rotation_y += 0x280;
        update_ground_contact();
        this->check_collisions();
        break;
    }

}

void TObjEneMorfos::state_damage(s32 ev) {
    s32 temp_r3;
    switch (ev) {
    case 4:
        this->requested_action = 3;
        this->clear_intangible();
        morfos_flags = (s32) (morfos_flags & 0xFFFFFFF8);
        this->advance_animation();
        this->set_active();
        return;
    case 3:
        if (this->get_flag_b4() != 0) {
            temp_r3 = morfos_flags;
            if (temp_r3 & 0x20) {
                morfos_flags = (s32) (temp_r3 & 0xFFFFFFDF);
                if (this->try_enter_low_hp_state() == 0) {
                    this->transition_enemy_state((s32)((s32)((int) (this->next_mode))));
                }
            } else {
                if (this->check_low_hp_trigger() != 0) {
                    this->transition_enemy_state((s32)((s32)((int) (this->next_mode))));
                } else if (this->try_enter_low_hp_state() == 0) {
                    this->transition_enemy_state((s32)((s32)((int) (this->next_mode))));
                }
            }
        }
        break;
    case 0:
        this->advance_animation();
        return;
    case 5:
        this->clear_attack_receipts();
        this->clear_field_388();
        break;
    }
}

void TObjEneMorfos::state_death(s32 ev) {
    s32 counter;
    s32 temp_r30;

    switch (ev) {
    case 4:
        this->requested_action = 4;
        this->clear_intangible();
        morfos_flags = (s32) (morfos_flags & 0xFFFFFFF8);
        this->advance_animation();
        this->refresh_and_send_entity_flags();
        this->accum = (f32) texture_scroll;
        this->counter = 0;
        step = 0;
        wall_fade.init_death_params();
        play_sound_effect(0x4003A626, &position, 0, 0);
        return;
    case 3:
        if ((s32) this->counter == 2) {
            queue_destruction();
        }
    case 5:
        return;
    case 0:
        counter = this->counter;
        switch (counter) {
        case 0:
            this->advance_animation();
            temp_r30 = wall_fade.decay_value_toward_floor();
            if ((this->get_flag_b4() != 0) && (temp_r30 != 0)) {
                fn_800D911C(&position);
                play_sound_effect(0x4003A830, &position, 0, 0);
                body_fade.start_fade_out();
                morfos_flags = (s32) (morfos_flags | 2);
                this->counter = 1;
                return;
            }
            break;
        case 1:
            if (body_fade.decay_value_toward_floor() != 0) {
                this->counter = 2;
                morfos_flags = (s32) (morfos_flags | 1);
                TObjPlayer::apply_effect_variant_b(&position, 0);
                return;
            }
            break;
        default:
            this->counter = 2;
            break;
        }
        break;
    }
}

// inferred name, from its only user (get_camera_ctrl in record_camera_path_point).
static const Vec morfos_camera_path_origin = {0.0f, 0.0f, 0.0f};
void TObjEneMorfos::record_camera_path_point(NJS_OBJECT *) {
    switch (TObjEneMorfos__phase) {
    case 6:
    case 10: {
        Vec pos = morfos_camera_path_origin;
        forward_transform_to_view((const Vec *)&pos, TObjEneMorfos__camera_path_cursor);
        TObjEneMorfos__camera_path_cursor++;
        break;
    }
    }
    TObjEneMorfos__phase += 1;
}

void TObjEneMorfos::render_part(s32 idx, s32 mode) {
    s32 vis;
    RenderFadeState *part;
    part = &part_fades[idx];
    part->update();
    vis = part->updateFromCamera((const f32 *)&body_center);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, this->rotation_y);
    TObjEneMorfos__phase = 0;
    TObjEneMorfos__camera_path_cursor = node_points;
    set_chunk_model_node_callback(TObjEneMorfos::record_camera_path_point);
    if (morfos_flags & 2) {
        if (body_fade.has_visible_opacity() != 0) {
            body_fade.set_flags_and_apply_damage_color();
            if ((s32)main_task.get_task_flags() & 0x200) {
                this->draw();
            }
            body_fade.clear_flag_and_notify();
        }
    } else if (vis != 0) {
        part->set_flags_and_apply_damage_color();
        if ((s32)main_task.get_task_flags() & 0x200) {
            this->draw();
        }
        part->clear_flag_and_notify();
    } else if (!((s32)main_task.get_task_flags() & 0x200)) {
        if (mode == 1) {
            this->draw();
        } else {
            draw_motion_model();
        }
    }
    set_chunk_model_node_callback(NULL);
    pop_matrix();
    update_primary_light();
    TParticleCtrl::end_effect_render();
}

// inferred name: the draw_ground_shadow scale in render.
static const Vec morfos_render_shadow_scale = {2.0f, 1.0f, 2.0f};
void TObjEneMorfos::render() {
    s32 cam;
    s32 vis;
    if (TObjPlayer::check_demo_mode() != 0) {
        render_demo();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    if (morfos_flags & 1) {
        vis = 0;
    } else if (TObjEneDD::is_main_phase_15() != 0) {
        vis = this->classify_actor_view_detail(view_detail_near_depth, view_detail_far_depth, 15.0f);
    } else if (this->update_object_view_visibility(400.0f, 15.0f) != 0) {
        vis = 1;
    } else {
        vis = 0;
    }
    if (vis != 0 && this->render_model_if_visible() == 0) {
        this->defer_render();
        this->render_part(cam, vis);
        if (this->mode != 0xB && !(ground_attributes & 0x4000)) {
            Vec v = morfos_render_shadow_scale;
            this->draw_ground_shadow(&v, 0);
        }
        this->update_secondary_light();
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        model_render_flags &= ~0x810;
        if (morfos_flags & 0x10) {
            this->draw_body();
        }
        model_render_flags = saved_model_render_flags;
    }
}
s32 TObjEneMorfos::render_model_if_visible() {
    if ((s32)main_task.get_task_flags() & 0x20) {
        if (push_reflection_matrix(&reflection_point) != 0) {
            TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, this->rotation_y);
            this->draw();
            pop_matrix();
            if (morfos_flags & 0x10) {
                this->draw_body();
            }
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
void TObjEneMorfos::draw_body() {
    if ((s32)main_task.get_task_flags() & 0x200) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(TObjEneMorfos__instance->models[2].texlist));
        push_matrix();
        post_translate_matrix(&node_points[0].x);
        rotate_matrix_y(0, (int) (rotation_y));
        if (morfos_flags & 2) {
            if (wall_fade.has_visible_opacity() != 0) {
                wall_fade.set_flags_and_apply_damage_color();
                draw_chunk_model(TObjEneMorfos__instance->models[2].model->model);
                wall_fade.clear_flag_and_notify();
            }
        } else {
            draw_chunk_model(TObjEneMorfos__instance->models[2].model->model);
        }
        pop_matrix();
    }
}
#pragma pop


BmlResource *TObjEneMorfos::get_instance() {  return TObjEneMorfos__instance; }
s32 TObjEneMorfos::get_rotation_y() { return rotation_y; }

Vec *TObjEneMorfos::get_arm_point() { return &node_points[1]; }

u8 TObjEneMorfos::check_value_in_range(void *, u16 start, u16 end, u16 value) {
    s32 r;
    s32 d;
    s32 c;
    s32 b;
    s32 a;
    a = start;
    b = end;
    if (a > b) {
        c = value;
        r = 0;
        d = a - c;
        if ((d >= 0 && b - c >= 0) || (d <= 0 && b - c <= 0)) {
            r = 1;
        }
        return r;
    } else {
        s32 r2;
        s32 d2;
        s32 c2;
        c2 = value;
        r2 = 0;
        d2 = a - c2;
        if ((d2 <= 0 && b - c2 >= 0) || (d2 >= 0 && b - c2 <= 0)) {
            r2 = 1;
        }
        return r2;
    }
}

void TObjEneMorfos::update_ground_probe() {
    Vec probe;
    CsnHit *hit;
    if ((actor_frame_tick % 5) == 0) {
        VecCopy(&probe, &position);
        probe.y += 15.0f;
        hit = csnVectorUnder(&probe, ground_candidates.groups, 0x4000);
        if (hit != NULL) {
            ground_attributes = hit->hit_mask;
            VecCopy(&reflection_point, &hit->contact->point);
        } else {
            VecCopy(&reflection_point, &position);
        }
    }
    if (ground_attributes & 0x4000) {
        request_reflection_render();
    }
}

void TObjEneMorfos::run_demo_task() { if (get_target_info() != 0) { this->init_target_offsets(); } }

// inferred name: the draw_ground_shadow scale in render_demo.
static const Vec morfos_vfunc_106_shadow_scale = {2.0f, 1.0f, 2.0f};
void TObjEneMorfos::render_demo() {
    s32 idx;
    f32 frame;
    AnimationMotion *anim;
    get_target_info();
    if (update_object_view_visibility(400.0f, 15.0f) != 0) {
        if (mode != 0xB) {
            Vec v = morfos_vfunc_106_shadow_scale;
            draw_ground_shadow(&v, 0);
        }
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation_y);
        idx = (s32)parameters[0];
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 5) {
            idx = 4;
        }
        anim = motion_list[action_table[idx].motion].motion;
        frame = parameters[1];
        if (frame < 0.0f) {
            frame = 0.0f;
        } else if (frame > (anim->frameCount - 1)) {
            frame = (f32)anim->frameCount;
        }
        set_motion_packed_rotation();
        draw_model_motion(model, anim, frame);
        clear_motion_packed_rotation();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

player_stats *morfos_base_params[1];
ActorParamBlock *morfos_resistance_params[1];
MorfosParams *TObjEneMorfos__param_table;
BmlResource *TObjEneMorfos__instance;
s32 TObjEneMorfos__phase;
Vec *TObjEneMorfos__camera_path_cursor;
s16 *morfos_body_scroll_polygons;
s16 *morfos_wall_scroll_polygons;
s32 morfos_body_scroll_tick;
s32 morfos_wall_scroll_tick;
float morfos_projectile_speed;
float morfos_param_table_speed_copy;
