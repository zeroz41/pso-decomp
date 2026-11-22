#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/unk/SampledMotionPoints.h"
#include "pso/npc/NpcModelRegistry.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/enemy/TUnk_80493450.h"
#include "pso/enemy/balclaw/TObjEneBalClaw.h"
#include "pso/enemy/balclaw/TObjEneBalClawClaw.h"
#include "pso/enemy/beast/TObjEneBeast.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/unk/text_803D853C.h"

#include "pso/effect/TUnk_80494968.h"
#include "types.h"

#include "pso/player/TObjPlayer.h"


#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/ambient/TObjFish.h"


#include "pso/render/RenderFadeState.h"
#include "pso/system/task/TObject.h"

#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"


#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/unk/TLobby.h"
#include "pso/system/BmlResourceDescriptor.h"

#include <stddef.h>
#include "pso/unk/text_803E2F28.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/effect/TUnk_80494968.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/SoundEffect.h"
#include "pso/render/model_render_state.h"
#include "pso/player/TObjPlayer_801542CC.h"

extern "C" {
extern SampledMotionPoints *beast_claw_trail_instance;
extern SampledMotionPoints *boss4_type3_instance;
}
void TObjEneBeast::run_demo_task() {  }
void TObjEneBeast::play_group_chase_sound() {
    play_sound_effect(0x4003E431, &position, 0, 0);
}
void TObjEneBeast::play_death_sound() {
    play_sound_effect(0x4003AB2D, &position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
}
void TObjEneBeast::play_hurt_sound() {
    play_sound_effect(0x4003A32E, &position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}
void TObjEneBeast::play_attack_sound() {
    play_sound_effect(0x4003A62F, &position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x100);
}
void TObjEneBeast::play_alert_sound() {
    play_sound_effect(0x4003A82C, &position, 0, 0);
    TObjPlayer::play_effect_if_v2(-0x200);
}

void TObjEneBeast::spawn_death_effect() {
    Vec stack;
    stack.x = 0.0f;
    stack.y = 1e+01f;
    stack.z = 0.5f * *(f32 *)(this->m_2b0 + 0x10);
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(0, this->rotation_y);
    rotate_vector_by_matrix(0, &stack, &stack);
    pop_matrix();
    vec3_add_to(&stack, &this->position);
    ((TObjPlayer *)(&stack.x))->spawn_effect_at_ground(0x23);
    TObjPlayer::spawn_dead_spot_type2((saddr)&stack.x, 0xF);
}

void TObjEneBeast::update_attack_trail() {
    Vec dir;
    Vec pos;
    Vec *entry;
    s32 idx;
    TUnk_80494968 *eff;
    if (this->frame < 12.0f) {
        switch (this->requested_action) {
        case 3:
            entry = beast_claw_trail_instance->lookup(this->frame);
            idx = 0;
            break;
        case 4:
            entry = boss4_type3_instance->lookup(this->frame);
            idx = 1;
            break;
        default:
            entry = 0;
            break;
        }
        if (entry != 0) {
            push_matrix();
            set_matrix_identity(0);
            post_translate_matrix(&position.x);
            rotate_matrix_y(0, this->rotation_y);
            matrix_mult_vec_array(NULL, entry, &pos, 2);
            pop_matrix();
            eff = attack_trails[idx];
            if (eff != NULL) {
                eff->add_segment(&pos, &dir);
            }
        }
    }
}

void TObjEneBeast::select_subtype() {
    s32 kind = subtype;
    if (kind < 0) {
        subtype = 0;
    } else if (kind > 2) {
        subtype = 2;
    }
    switch (subtype) {
    case 2:
        variant = 1;
        set_param(0xB);
        return;
    case 1:
        variant = 2;
        set_param(0xA);
        return;
    default:
        variant = 0;
        set_param(9);
        return;
    }
}
void TObjEneBeast::beast_update_appear() {
    switch (phase) {
    case 0:
    default:
        if (m_390 != 1) {
            phase = 2;
        } else {
            phase = 1;
            requested_action = 0xB;
            set_indexed_flags(0, 0x0A000000);
            obj_setFlags30(this, 0x04000000);
            play_sound_effect(0x4003AB32, &position, 0, 0);
        }
        break;
    case 1:
        if (action_flags != 0x20U) {
            phase = 2;
            m_390 = 0;
            requested_action = 0;
            clear_player_status_flag(0, 0x0A000000);
            obj_clearFlags30(0x04000000);
        }
        break;
    case 2:
        mode = 1;
        break;
    }
    advance_animation();
}
void TObjEneBeast::render() {
    s32 drawMode;
    saddr fade;
    s32 cam;
    s32 doDraw;

    cam = 0;
    if (is_split_screen() != 0) {
        cam = TCameraCtrl::get_camera_mode();
    }
    drawMode = classify_actor_view_detail(2e+02f, 4e+02f, 3e+01f);
    if (drawMode == 0) {
        return;
    }
    fade = 0;
    if (TObjEneDD::check_v2_mode() != 0) {
        camera_fades[cam].update();
        fade = camera_fades[cam].updateFromCamera(&body_center.x);
    }
    saved_model_render_flags = model_render_flags;
    select_actor_lighting(this);
    TObjFish::set_global_param(texlist);
    push_matrix();
    translate_matrix(0, 0.0f, unk_380, 0.0f);
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    if (TObjPlayer::check_demo_mode() == 1) {
        draw_chunk_object(model);
    } else {
        TObjPlayer::toggle_particle_effect();
        doDraw = 1;
        if (fade != 0) {
            camera_fades[cam].set_flags_and_apply_damage_color();
            if (defer_render() != 0) {
                doDraw = 0;
            }
        }
        if (doDraw != 0) {
            if (drawMode == 1) {
                draw();
            } else {
                draw_motion_model();
            }
        }
        TParticleCtrl::end_effect_render();
        if (fade != 0) {
            camera_fades[cam].clear_flag_and_notify();
        }
    }
    pop_matrix();
    restore_scene_lighting();
    if (mode >= 10 || mode < 8) {
        Vec v;
        v.x = 1.5f;
        v.y = 1.0f;
        v.z = 2.0f;
        draw_ground_shadow(&v, 0);
    }
}

#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/enemy/saver/TObjEneSaver.h"


#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/task/TMainTask.h"


const char *beast_model_name_table[4] = {
    "re8_b_beast_wola_body.nj", "re8_b_rdbeast_wola_body.nj", "re8_b_srdbeast_wola_body.nj", NULL,
};
const char *beast_motion_name_table[13] = {
    "appear_bm1_s_wala_body.njm", "atackl_bm1_s_wala_body.njm", "atackr_bm1_s_wala_body.njm", "damage_bm1_s_wala_body.njm",
    "deadb_bm1_s_wala_body.njm", "dead_bm1_s_wala_body.njm", "leader_bm1_s_wala_body.njm", "mihari_bm1_s_wala_body.njm",
    "run_bm1_s_wala_body.njm", "stund_bm1_s_wala_body.njm", "wakeup_bm1_s_wala_body.njm", "walk_bm1_s_wala_body.njm",
    NULL,
};
BmlResourceDescriptor beast_resource_descriptor = {
    "bm_ene_re8_b_beast.bml", beast_model_name_table, beast_motion_name_table, 3, 12,
};
// inferred: stored to the object's name field by the constructor
const char *beast_class_name = "TObjEneBeast";
extern const char beast_a_bml_filename[25];
TObjMotionAction beast_action_table[12] = {
    {1, 0, 9, 0.6f, 1},
    {2, 0, 7, 0.6f, 0x20},
    {1, 2, 0xB, 0.5f, 1},
    {2, 0, 1, 0.65f, 4},
    {2, 0, 2, 0.85f, 4},
    {1, 0, 8, 1.0f, 1},
    {2, 0, 3, 1.5f, 8},
    {2, 0, 0xA, 0.8f, 0x20},
    {3, 0, 5, 0.6f, 0x10},
    {3, 0, 4, 0.6f, 0x10},
    {2, 0, 6, 0.6f, 0x20},
    {2, 0, 0, 0.5f, 0x20},
};
BeastMovementParams beast_movement_params[3] = {
    {225.0f, 0.4f, 0x400, {0, 0x1E0000, 1, 0}},
    {250.0f, 0.55f, 0x400, {0, 0x1E0000, 1, 0}},
    {300.0f, 0.7f, 0x400, {0, 0x1E0000, 1, 0}},
};
CollisionBody beast_collision_body_table[3] = {
    {{0.0f, 12.5f, 0.0f}, 7.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 12.5f, 0.0f}, 7.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 15.0f, 0.0f}, 8.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

void *TObjEneBeast::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjEneBeast(control, set_data);
}

u8 **ene_beast_boss_id_buffer;
u8 **TObjEneBeast__boss4_rock_handler_ids;
u8 **boss4_rock_pool;
f32 **boss4_rock_shared_handler_ids;
BmlResource *ene_beast_bml_resource;
SampledMotionPoints *beast_claw_trail_instance;
SampledMotionPoints *boss4_type3_instance;

void free_boss4_rock_pool(void) {
    if (ene_beast_boss_id_buffer != NULL) {
        mem_free(ene_beast_boss_id_buffer);
        ene_beast_boss_id_buffer = NULL;
    }
    if (TObjEneBeast__boss4_rock_handler_ids != NULL) {
        mem_free(TObjEneBeast__boss4_rock_handler_ids);
        TObjEneBeast__boss4_rock_handler_ids = NULL;
    }
    if (boss4_rock_pool != NULL) {
        mem_free(boss4_rock_pool);
        boss4_rock_pool = NULL;
    }
    if (boss4_rock_shared_handler_ids != NULL) {
        mem_free(boss4_rock_shared_handler_ids);
        boss4_rock_shared_handler_ids = NULL;
    }
    if (boss4_type3_instance != NULL) {
        delete boss4_type3_instance;
        boss4_type3_instance = NULL;
    }
    if (beast_claw_trail_instance != NULL) {
        delete beast_claw_trail_instance;
        beast_claw_trail_instance = NULL;
    }
    if (ene_beast_bml_resource != NULL) {
        delete ene_beast_bml_resource;
        ene_beast_bml_resource = NULL;
    }
}

#pragma push
#pragma opt_propagation off
void TObjEneBeast::load_resources() {
    BmlResource *p;
    s32 i;

    if (TObjEneDD::check_v2_mode() != 0) {
        ene_beast_bml_resource = load_enemy_bml_resource_named(&beast_resource_descriptor, (const char *)beast_a_bml_filename);
        beast_collision_body_table[0].radius = 1e+01f;
        beast_collision_body_table[1].radius = 1e+01f;
        beast_collision_body_table[2].radius = 9.0f;
    } else {
        p = new BmlResource(1, &beast_resource_descriptor, 0, 0, NULL);
        ene_beast_bml_resource = p;
        beast_collision_body_table[0].radius = 7.0f;
        beast_collision_body_table[1].radius = 7.0f;
        beast_collision_body_table[2].radius = 8.0f;
    }
    beast_claw_trail_instance = new SampledMotionPoints(2, 7.0f, 12.0f, 1.0f);
    boss4_type3_instance = new SampledMotionPoints(2, 7.0f, 12.0f, 1.0f);
    beast_claw_trail_instance->sample_two_nodes(ene_beast_bml_resource->models->model, (NJS_MOTION *)ene_beast_bml_resource->motions[beast_action_table[3].motion].motion, 5, 8);
    boss4_type3_instance->sample_two_nodes(ene_beast_bml_resource->models->model, (NJS_MOTION *)ene_beast_bml_resource->motions[beast_action_table[4].motion].motion, 10, 13);
    ene_beast_boss_id_buffer = (u8 **)mem_alloc(0xC);
    TObjEneBeast__boss4_rock_handler_ids = (u8 **)mem_alloc(0xC);
    boss4_rock_pool = (u8 **)mem_alloc(0xC);
    boss4_rock_shared_handler_ids = (f32 **)mem_alloc(0xC);
    ene_beast_boss_id_buffer[0] = (u8 *)TLobby::register_boss(0x4B);
    ene_beast_boss_id_buffer[1] = (u8 *)TLobby::register_boss(0x4C);
    ene_beast_boss_id_buffer[2] = (u8 *)TLobby::register_boss(0x4D);
    TObjEneBeast__boss4_rock_handler_ids[0] = (u8 *)TLobby::dispatch_shared_handler_b(0x4E);
    TObjEneBeast__boss4_rock_handler_ids[1] = (u8 *)TLobby::dispatch_shared_handler_b(0x4F);
    TObjEneBeast__boss4_rock_handler_ids[2] = (u8 *)TLobby::dispatch_shared_handler_b(0x50);
    boss4_rock_pool[0] = (u8 *)TLobby::register_object(0x4A);
    boss4_rock_pool[1] = (u8 *)TLobby::register_object(0x4B);
    boss4_rock_pool[2] = (u8 *)TLobby::register_object(0x4C);
    boss4_rock_shared_handler_ids[0] = (f32 *)TLobby::dispatch_shared_handler_a(0x4A);
    boss4_rock_shared_handler_ids[1] = (f32 *)TLobby::dispatch_shared_handler_a(0x4B);
    boss4_rock_shared_handler_ids[2] = (f32 *)TLobby::dispatch_shared_handler_a(0x4C);
    {
        s16 ids[3] = {2, 3, 4};
        NpcAnimationBinding q = { NULL, beast_action_table, 0, 2, 12 };
        q.motions = ene_beast_bml_resource->motions;
        for (i = 0; i < 3; i++) {
            NpcModelRegistry::register_animated_chunk(ids[i], ene_beast_bml_resource->models[i].model,
                                            ene_beast_bml_resource->models[i].m_c, &q,
                                            beast_collision_body_table[i].radius, 0.0f);
        }
    }
}

#pragma pop
extern "C" {
// Archive loaded instead of beast_resource_descriptor's when TObjEneDD::check_v2_mode() is set. Defined after
// load_resources (it follows that function's initialisers and is not pooled there); the declaration above it would
// otherwise send it to .data.
}
__declspec(section ".rodata") const char beast_a_bml_filename[25] = "bm_ene_re8_b_beast_a.bml"; // inferred: from the string

#pragma defer_codegen on
TObjEneBeast::TObjEneBeast(TObject *parent, void *set_data) : TUnk_80493450(parent) {
    s32 i;

    m_name = beast_class_name;
    apply_set_data(set_data);
    ((TObjPlayer *)this)->init_position_vectors();
    subtype = variant;
    select_subtype();
    select_model_record(variant);
    action_table = beast_action_table;
    set_field_d8((saddr)action_table);
    motion_list = ene_beast_bml_resource->motions;
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    init_collision_body_parts(this, &beast_collision_body_table[subtype], 1);
    bind_enemy_combat_stats(ene_beast_boss_id_buffer[subtype], TObjEneBeast__boss4_rock_handler_ids[subtype], boss4_rock_pool[subtype]);
    movementParameters = &beast_movement_params[subtype];
    referenceHp = hp;
    update_prev_position();
    ((TBoss3VoloptHiraisin *)this)->copy_position();
    ((TObjPlayer *)this)->register_object_by_id();
    m_2ac = (s32)(182.04445f * (3.6e+02f * random_ratio()));
    resetTimer = 0xF;
    timer = resetTimer;
    phase = 0;
    m_374 = 0;
    m_376 = 0;
    m_378 = 0;
    m_37c = 0;
    add_flags_2e4(1);
    obj_setFlags30(this, 0x40000);
    unk_380 = 0.0f;
    attack_trails[0] = TUnk_80494968::create(0xA0303030, 0xFF303030);
    attack_trails[1] = TUnk_80494968::create(0xA0303030, 0xFF303030);
    m_398 = boss4_rock_shared_handler_ids[subtype][0];
    m_3a0 = boss4_rock_shared_handler_ids[subtype][1];
    unk_39C = boss4_rock_shared_handler_ids[subtype][2];
    unk_3A4 = boss4_rock_shared_handler_ids[subtype][3];
    m_390 = 1;
    for (i = 0; i < 4; i++) {
        camera_fades[i].activate_and_dispatch();
    }
    clear_lobby_object_state();
}

TObjEneBeast::~TObjEneBeast() {
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
