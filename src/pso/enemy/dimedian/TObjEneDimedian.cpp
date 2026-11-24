#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/memory.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "types.h"
#include "pso/enemy/lappy/TObjEneLappy_800F5DE0.h"
#include "pso/system/AreaSound.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_800A7764.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/dimedian/TObjEneDimedian.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/object/base/TObjChara.h"
#include "pso/render/TUnk_80490470.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/effect/TAttackTrace.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/model_render_state.h"
#include "pso/unk/text_803D853C.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/mine/TOComputerMachine01_8023DD0C.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/system/task/TMainTask.h"

extern "C" {
extern SampledMotionPoints *dimedian_attack_left_trail;
extern SampledMotionPoints *dimedian_attack_right_trail;

extern saddr dimedian_resource_handles[];
extern s32 dimedian_last_draw_tick[];


s16 TObjPlayer::get_atp() { return this->atp; }
s16 TObjPlayer::get_atp_range() { return this->atp_range; }
void TObjPlayer__sub_800A7774(TObjBase *object, const Vec *position) { VecCopy(&object->position, position); }

void TObjMotion::set_override_speed(f32 farg0) {
    this->override_speed = farg0;
    set_motion_flags(MOTION_OVERRIDE_SPEED);
}

void TObjMotion::set_motion_flags(u32 flags) { motion_flags |= flags; }
void TObjEneDimedian::run_demo_task() {  }

void TObjEneDimedian::play_group_chase_sound() {
    play_sound_effect(remap_sound_for_area(0x4003AD40), &position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::play_death_sound() {
    play_sound_effect(remap_sound_for_area(0x4003AD3D), &position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::play_hurt_sound() {
    play_sound_effect(remap_sound_for_area(0x4003A83E), &position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::play_attack_sound() {
    play_sound_effect(remap_sound_for_area(0x4003A83F), &position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::play_alert_sound() {
    s32 sound;
    if (random_ratio() < 0.5f) {
        sound = remap_sound_for_area(0x4003B23B);
        play_sound_effect(sound, &position, 0, 0);
    } else {
        sound = remap_sound_for_area(0x4003B23C);
        play_sound_effect(sound, &position, 0, 0);
    }
    TObjPlayer::play_effect_if_v2(-0x100);
}

void TObjEneDimedian::spawn_death_effect() {
    s32 area;
    TObjPlayer::apply_effect_variant_a(&position, 0);
    fn_800D911C(&body_center);
    area = get_current_floor_area();
    if ((area == AREA_VR_TEMPLE_ALPHA) || (area == AREA_VR_TEMPLE_BETA)) {
        play_sound_effect(0x3AD3F, &position, 0, 0);
        return;
    }
    play_sound_effect(remap_sound_for_area(0x4003AD25), &position, 0, 0);
}

void TObjEneDimedian::update_attack_trail() {
    Vec b;
    Vec a;
    Vec *e;
    s32 idx;
    TAttackTraceStrip *eff;
    if (!(this->frame < 12.0f)) {
        return;
    }
    switch (this->requested_action) {
    case 3:
        e = dimedian_attack_left_trail->lookup(this->frame);
        idx = 0;
        break;
    case 4:
        e = dimedian_attack_right_trail->lookup(this->frame);
        idx = 1;
        break;
    default:
        e = 0;
        break;
    }
    if (e == 0) {
        return;
    }
    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, this->rotation_y);
    matrix_mult_vec_array(NULL, e, &a, 2);
    pop_matrix();
    eff = attack_trails[idx];
    if (eff != NULL) {
        eff->add_segment(&a, &b);
    }
}

void TObjEneDimedian::beast_retire_corpse() {
    this->appearing = 1;
    if (body_fade.decay_value_toward_floor() == 1) {
        queue_destruction();
    }
}
void TObjEneDimedian::sub_800A7B54() {
    s32 kind = subtype;
    if (kind < 0) {
        subtype = 0;
    } else if (kind > 2) {
        subtype = 2;
    }
    switch (subtype) {
    case 2:
        variant = 0;
        set_param(0x2B);
        return;
    case 1:
        variant = 1;
        set_param(0x2A);
        return;
    default:
        variant = 2;
        set_param(0x29);
        return;
    }
}
void TObjEneDimedian::beast_update_appear() {
    advance_animation();
    switch (this->phase) {
    case 0:
    default:
        if (this->appearing == 1) {
            this->phase = 1;
            play_area_se_with_particle(&position);
            body_fade.start_fade_in();
        } else {
            this->phase = 2;
        }
        break;
    case 1:
        if (body_fade.advance_toward_max() == 1) {
            this->phase = 2;
            this->appearing = 0;
        }
        break;
    case 2:
        this->mode = 1;
        break;
    }
}
void TObjEneDimedian::render() {
    s16 saved;
    s32 vis;
    s32 fading;
    s32 camera;
    s32 d;
    s32 doDraw;
    Vec pos;
    if (actor_frame_tick != dimedian_last_draw_tick[variant]) {
        dimedian_last_draw_tick[variant] = actor_frame_tick;
        TObjPlayer__sub_8023DEE0((s16 *)dimedian_resource_handles[variant], 0xE, 0, 0);
    }
    camera = 0;
    if (is_split_screen() != 0) {
        camera = TCameraCtrl::get_camera_mode();
    }
    vis = classify_actor_view_detail(2e+02f, 4e+02f, 3e+01f);
    if (vis == 0) {
        return;
    }
    fading = 0;
    if (TObjEneDD::check_v2_mode() != 0) {
        camera_fades[camera].update();
        fading = camera_fades[camera].updateFromCamera(&body_center.x);
    }
    select_actor_lighting(this);
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object(model);
    } else {
        switch (mode) {
        case 0:
        case 1:
        case 8: {
            s16 *strip = ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->child->sibling->model)->polygon_list;
            saved = strip[3];
            strip[3] = (u8)strip[3];
            break;
        }
        }
        TObjPlayer::toggle_particle_effect();
        if (appearing == 1) {
            if (body_fade.has_visible_opacity() != 0) {
                saved_model_render_flags = model_render_flags;
                saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
                saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
                body_fade.set_flags_and_apply_damage_color();
                d = 1;
                if (defer_render() != 0) {
                    d = 0;
                }
                if (d != 0) {
                    draw();
                }
                body_fade.clear_flag_and_notify();
                chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
                chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
                model_render_flags = saved_model_render_flags;
            }
        } else {
            doDraw = 1;
            if (fading != 0) {
                camera_fades[camera].set_flags_and_apply_damage_color();
                if (defer_render() != 0) {
                    doDraw = 0;
                }
            }
            if (doDraw != 0) {
                if (vis == 1) {
                    draw();
                } else {
                    draw_motion_model();
                }
            }
            if (fading != 0) {
                camera_fades[camera].clear_flag_and_notify();
            }
        }
        TParticleCtrl::end_effect_render();
        switch (mode) {
        case 0:
        case 1:
        case 8:
            ((NJS_CNK_MODEL *)((NJS_OBJECT *)model)->child->sibling->model)->polygon_list[3] = saved;
            break;
        }
    }
    pop_matrix();
    restore_scene_lighting();
    switch (mode) {
    case 0:
    case 1:
    case 8:
    case 9:
        break;
    default:
        pos.x = 1.5f;
        pos.y = 1.0f;
        pos.z = 2.0f;
        draw_ground_shadow(&pos, 0);
        break;
    }
}

}

extern "C" const u8 dimedian_sl_body_model_filename[20] = "df3_sl_wala_body.nj";
extern "C" const u8 dimedian_ssl_body_model_filename[24] = "df3_ssl_wala_body.nj";
extern "C" const u8 dimedian_s_body_model_filename[20] = "df3_s_wala_body.nj";
extern "C" const u8 dimedian_appear_motion_filename[28] = "appear_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_attack_left_motion_filename[28] = "atackl_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_attack_right_motion_filename[28] = "atackr_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_damage_motion_filename[28] = "damage_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_deadb_motion_filename[28] = "deadb_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_dead_motion_filename[28] = "dead_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_leader_motion_filename[28] = "leader_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_mihari_motion_filename[28] = "mihari_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_run_motion_filename[24] = "run_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_stund_motion_filename[28] = "stund_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_wakeup_motion_filename[28] = "wakeup_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_walk_motion_filename[28] = "walk_bm1_s_wala_body.njm";
extern "C" const u8 dimedian_bml_filename[24] = "bm_ene_df3_dimedian.bml";
extern "C" const char dimedian_class_name[16] = "TObjEneDimedian";




extern "C" {
extern const u8 dimedian_a_bml_filename[26];
}
extern "C" {
extern const char *TObjEneDimedian_name_ref;



extern void *dimedian_model_name_table[4];
extern void *dimedian_motion_name_table[13];
void *dimedian_model_name_table[4] = {
    (void *)&dimedian_sl_body_model_filename, (void *)&dimedian_ssl_body_model_filename, (void *)&dimedian_s_body_model_filename, (void *)0x0,
};
void *dimedian_motion_name_table[13] = {
    (void *)&dimedian_appear_motion_filename, (void *)&dimedian_attack_left_motion_filename, (void *)&dimedian_attack_right_motion_filename, (void *)&dimedian_damage_motion_filename,
    (void *)&dimedian_deadb_motion_filename, (void *)&dimedian_dead_motion_filename, (void *)&dimedian_leader_motion_filename, (void *)&dimedian_mihari_motion_filename,
    (void *)&dimedian_run_motion_filename, (void *)&dimedian_stund_motion_filename, (void *)&dimedian_wakeup_motion_filename, (void *)&dimedian_walk_motion_filename,
    (void *)0x0,
};
void *dimedian_resource_descriptor[4] = {
    (void *)&dimedian_bml_filename, (void *)&dimedian_model_name_table, (void *)&dimedian_motion_name_table, (void *)0x3000c,
};
TObjMotionAction dimedian_action_table[11] = {
    {1, 0, 9, 0.6f, 1},
    {2, 0, 7, 0.6f, 0x20},
    {1, 2, 0xB, 1.0f, 1},
    {2, 0, 1, 1.0f, 4},
    {2, 0, 2, 1.0f, 4},
    {1, 0, 8, 1.0f, 1},
    {2, 0, 3, 1.0f, 8},
    {2, 0, 0xA, 0.8f, 0x20},
    {3, 0, 5, 0.6f, 0x10},
    {3, 0, 4, 0.6f, 0x10},
    {2, 0, 6, 0.6f, 0x20},
};
BeastMovementParams dimedian_movement_params[3] = {
    {225.0f, 0.75f, 0x400, {0, 0x1E0000, 1, 0}},
    {250.0f, 0.9f, 0x400, {0, 0x1E0000, 1, 0}},
    {300.0f, 1.0f, 0x400, {0, 0x1E0000, 1, 0}},
};
CollisionBody dimedian_collision_body_table[3] = {
    {{0.0f, 12.5f, 0.0f}, 7.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 12.5f, 0.0f}, 7.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 15.0f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

void *TObjEneDimedian::create(void *arg2_) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjEneDimedian(control, arg2_);
}

player_stats **dimedian_boss_object_buf;
AttackParams **dimedian_attack_stat_table;
ActorParamBlock **TObjEneDimedian__boss_objects;
f32 **dimedian_buffer_ptr;
extern BmlResource *dimedian_resource_ptr;

void TObjEneDimedian::free_boss_objects() {
    if (dimedian_boss_object_buf != NULL) {
        mem_free(dimedian_boss_object_buf);
        dimedian_boss_object_buf = NULL;
    }
    if (dimedian_attack_stat_table != NULL) {
        mem_free(dimedian_attack_stat_table);
        dimedian_attack_stat_table = NULL;
    }
    if (TObjEneDimedian__boss_objects != NULL) {
        mem_free(TObjEneDimedian__boss_objects);
        TObjEneDimedian__boss_objects = NULL;
    }
    if (dimedian_buffer_ptr != NULL) {
        mem_free(dimedian_buffer_ptr);
        dimedian_buffer_ptr = NULL;
    }
    if (dimedian_attack_right_trail != NULL) {
        delete dimedian_attack_right_trail;
        dimedian_attack_right_trail = NULL;
    }
    if (dimedian_attack_left_trail != NULL) {
        delete dimedian_attack_left_trail;
        dimedian_attack_left_trail = NULL;
    }
    if (dimedian_resource_ptr != NULL) {
        delete dimedian_resource_ptr;
        dimedian_resource_ptr = 0U;
    }
}


void TLobby::load_dimedian_resources() {
    BmlModelEntry *models;
    void *p;
    s32 i;
    if (TObjEneDD::check_v2_mode() != 0) {
        dimedian_resource_ptr = load_enemy_bml_resource_named((BmlResourceDescriptor *)dimedian_resource_descriptor, (const char *)dimedian_a_bml_filename);
    } else {
        p = new BmlResource(1, (BmlResourceDescriptor *)dimedian_resource_descriptor, 0, 0, NULL);
        dimedian_resource_ptr = (BmlResource *)p;
    }
    models = dimedian_resource_ptr->models;
    dimedian_resource_handles[0] = (saddr)((NJS_CNK_MODEL *)models[0].model->child->sibling->sibling->model)->polygon_list;
    dimedian_resource_handles[1] = (saddr)((NJS_CNK_MODEL *)models[1].model->child->sibling->sibling->model)->polygon_list;
    dimedian_resource_handles[2] = (saddr)((NJS_CNK_MODEL *)models[2].model->child->sibling->sibling->model)->polygon_list;
    dimedian_last_draw_tick[0] = 0;
    dimedian_last_draw_tick[1] = 0;
    dimedian_last_draw_tick[2] = 0;
    dimedian_attack_left_trail = new SampledMotionPoints(2, 7.0f, 12.0f, 1.0f);
    dimedian_attack_right_trail = new SampledMotionPoints(2, 7.0f, 12.0f, 1.0f);
    dimedian_attack_left_trail->sample_two_nodes(dimedian_resource_ptr->models->model, (NJS_MOTION *)dimedian_resource_ptr->motions[dimedian_action_table[3].motion].motion, 5, 8);
    dimedian_attack_right_trail->sample_two_nodes(dimedian_resource_ptr->models->model, (NJS_MOTION *)dimedian_resource_ptr->motions[dimedian_action_table[4].motion].motion, 0xA, 0xD);
    dimedian_boss_object_buf = static_cast<player_stats **>(mem_alloc(0xC));
    dimedian_attack_stat_table = static_cast<AttackParams **>(mem_alloc(0xC));
    TObjEneDimedian__boss_objects = static_cast<ActorParamBlock **>(mem_alloc(0xC));
    dimedian_buffer_ptr = (f32 **)mem_alloc(0xC);
    dimedian_boss_object_buf[0] = TLobby::register_boss(0x53);
    dimedian_boss_object_buf[1] = TLobby::register_boss(0x54);
    dimedian_boss_object_buf[2] = TLobby::register_boss(0x55);
    dimedian_attack_stat_table[0] = TLobby::dispatch_shared_handler_b(0x5A);
    dimedian_attack_stat_table[1] = TLobby::dispatch_shared_handler_b(0x5B);
    dimedian_attack_stat_table[2] = TLobby::dispatch_shared_handler_b(0x5C);
    TObjEneDimedian__boss_objects[0] = TLobby::register_object(0x52);
    TObjEneDimedian__boss_objects[1] = TLobby::register_object(0x53);
    TObjEneDimedian__boss_objects[2] = TLobby::register_object(0x54);
    dimedian_buffer_ptr[0] = (f32 *)TLobby::dispatch_shared_handler_a(0x52);
    dimedian_buffer_ptr[1] = (f32 *)TLobby::dispatch_shared_handler_a(0x53);
    dimedian_buffer_ptr[2] = (f32 *)TLobby::dispatch_shared_handler_a(0x54);
    {
        s16 ids[3] = { 0x1B, 0x1C, 0x1D };
        NpcAnimationBinding anim = { dimedian_resource_ptr->motions, dimedian_action_table, 0, 2, 12 };
        for (i = 0; i < 3; i++) {
            TObjNpcEnemy::register_animated_chunk(ids[i], dimedian_resource_ptr->models[i].model, dimedian_resource_ptr->models[i].texlist, &anim,
                dimedian_collision_body_table[i].radius, 0.0f);
        }
    }
}
extern "C" __declspec(section ".rodata") const u8 dimedian_a_bml_filename[26] = "bm_ene_df3_dimedian_a.bml";
}

extern "C" {
saddr dimedian_resource_handles[3];
s32 dimedian_last_draw_tick[3];

const char *TObjEneDimedian_name_ref = dimedian_class_name;

BmlResource *dimedian_resource_ptr;
SampledMotionPoints *dimedian_attack_left_trail;
SampledMotionPoints *dimedian_attack_right_trail;
}

#pragma defer_codegen on
void TObjEneDimedian::load_dimedian_param_entry(s32 i) {
    model = dimedian_resource_ptr->models[i].model;
    texlist = dimedian_resource_ptr->models[i].texlist;
}

TObjEneDimedian::TObjEneDimedian(TObject *parent, void *set_data) : TUnk_80493450(parent) {
    s32 color;
    s32 i;
    m_name = TObjEneDimedian_name_ref;
    apply_set_data(set_data);
    init_position_vectors();
    subtype = variant;
    sub_800A7B54();
    load_dimedian_param_entry(variant);
    action_table = dimedian_action_table;
    set_action_table(action_table);
    motion_list = dimedian_resource_ptr->motions;
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
    init_collision_body_parts(this, &dimedian_collision_body_table[subtype], 1);
    bind_enemy_combat_stats(dimedian_boss_object_buf[subtype], dimedian_attack_stat_table[subtype], TObjEneDimedian__boss_objects[subtype]);
    movementParameters = &dimedian_movement_params[subtype];
    referenceHp = hp;
    update_prev_position();
    copy_position();
    initialize_enemy_photon_effect(this);
    m_2ac = (s32)(182.04445f * (3.6e+02f * random_ratio()));
    resetTimer = 0xF;
    timer = resetTimer;
    phase = 0;
    retreat_timer = 0;
    pad_376 = 0;
    in_group = 0;
    child_count = 0;
    add_flags_2e4(8);
    actorFlags |= 0x40000;
    corpse_sink_limit = -4.0f;
    if (TObjEneDD::check_v2_mode() != 0) {
        switch (subtype) {
        case 0:
        default:
            color = 0xFF20FF20;
            break;
        case 1:
            color = 0xFFFF0040;
            break;
        case 2:
            color = 0xFFFFFF00;
            break;
        }
    } else {
        switch (subtype) {
        default:
            color = 0xFF0000FF;
            break;
        case 1:
            color = 0xFFFF0000;
            break;
        case 2:
            color = 0xFFFFFF00;
            break;
        }
    }
    attack_trails[0] = TAttackTraceStrip::create(0xA0303030, color);
    attack_trails[1] = TAttackTraceStrip::create(0xA0303030, color);
    appearing = 1;
    far_move_speed = dimedian_buffer_ptr[subtype][0];
    far_anim_speed = dimedian_buffer_ptr[subtype][1];
    near_move_speed = dimedian_buffer_ptr[subtype][2];
    near_anim_speed = dimedian_buffer_ptr[subtype][3];
    for (i = 0; i < 4; i++) {
        camera_fades[i].activate_and_dispatch();
    }
    clear_lobby_object_state();
}

TObjEneDimedian::~TObjEneDimedian() {
    s32 i;
    for (i = 0; i < 2; i++) {
        if (attack_trails[i] != NULL) {
            attack_trails[i]->queue_destruction();
            attack_trails[i] = NULL;
        }
    }
    unlink_enemy_group_relations();
    free_collision_body_parts(this);
}
