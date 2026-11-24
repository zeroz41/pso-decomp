#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/boss/volopt/TBoss3VoloptCore.h"
#include "pso/boss/volopt/TBoss3VoloptP01.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/technique/TTecFoie.h"
#include "pso/technique/TTecGiBarta.h"
#include "pso/technique/TTecGiZonde.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/enemy/gyaranzo/TObjGyaranzoMissile.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/boss/volopt/TObjVoloptShutter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/system/vector.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/unk/text_803D853C.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/object/base/TObjBase.h"

extern "C" {
s32 post_translate_matrix(const void *pos);
void *find_entity_by_id(u16 id);
void init_collision_body_parts(void *obj, void *parts, s32 count);
void free_collision_body_parts(void *obj);
s32 minimap_render_dot(void *pos, s32 color, s32 a2, s32 a3);
void *__construct_array(void *array, void *ctor, void *dtor, u32 size, u32 count);
extern Mtx34 identity_matrix;
extern s32 registered_player_count;

// TBoss3Volopt.cpp defines these; its header does not declare them yet.
}

#pragma readonly_strings on
static const char *TBoss3VoloptP01_class_name = "TBoss3VoloptP01";
static const Vec volopt_p01_node_origin = { 0.0f, 0.0f, 0.0f };
static const DirectAttackPayload volopt_p01_zonde_attack = { 3, 0.0f };

static void *volopt_p01_boss_stat_handle_a;
static void *volopt_p01_shared_handler_b;
static void *volopt_p01_object_handle;
static TBoss3VoloptP01Params *volopt_p01_shared_handler_handle;
static BmlResource *TBoss3VoloptP01__resource_bundle;
static TBreakUpMdlData *TBoss3VoloptP01__breakup_model;
static NJS_OBJECT *volopt_p01_chunk_list;
static u8 *volopt_p01_breakup_color_ptr;

static TObjMotionAction volopt_p01_action_table[6] = {
    { 1, 0, 0xF, 0.7f, 0x0 },
    { 1, 0, 0xF, 1.0f, 0x1 },
    { 2, 0, 0x0, 0.5f, 0x4 },
    { 2, 0, 0x3, 1.4f, 0x8 },
    { 1, 0, 0xF, 1.0f, 0x10 },
    { 2, 2, 0xC, 1.0f, 0x0 },
};
static TBoss3VoloptP01Movement volopt_p01_movement = { 150.0f, 0.5555555f, 0x400, 0x1E0000, 0, 1, 0 };
static TBoss3VoloptP01CollisionPart volopt_p01_collision_parts = { 0, 18.0f, 0, 8.0f, 0, 0, 0x8003, 0, 0, 0, 0 };
static BreakUpParamRow volopt_p01_breakup_params = { 0x14, 0.06f, 1.5f, 0.9f, 0.12f, 0.55f, 0.5f };
void TObjVoloptShutter::open() {
    state = 2;
    substate = 0;
}

void TObjVoloptShutter::close() {
    state = 1;
    substate = 0;
}

void TBoss3VoloptP01::load_model(s32 index) {
    model = (void *)TBoss3VoloptP01__resource_bundle->models[index].model;
    texlist = TBoss3VoloptP01__resource_bundle->models[index].texlist;
}

s32 TBoss3VoloptP01::get_shared_value(s32 index) {
    return volopt_p01_shared_handler_handle->values[index];
}

void TargetCursorRecord::init_cursor_record() {
    id = 0xFFFF;
    flag = 0;
    value = 0.0f;
}

TargetCursorRecord::TargetCursorRecord() {
    init_cursor_record();
}

TargetCursorList::TargetCursorList() {
    clear_target_cursor_list(this);
}

void clear_target_cursor_list(TargetCursorList *list) {
    list->count = 0;
}

TBoss3VoloptP01::TBoss3VoloptP01(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    m_name = TBoss3VoloptP01_class_name;
    apply_set_data(set_data);
    init_params();
    shutter = new TObjVoloptShutter(0);
}

#pragma push
#pragma fp_contract on
TBoss3VoloptP01::TBoss3VoloptP01(TBoss3Volopt *parent, s32 index, u16 id, s32 group) : TObjEnemyCustom(parent) {
    s32 angle;

    m_name = TBoss3VoloptP01_class_name;
    entity_id = id;
    set_index = group;
    set_entry = NULL;
    room = parent->room;
    set_group = parent->set_group;
    init_params();
    angle = (s32)(182.04445f * (f32)(index * 60));
    position.x = 76.0f * cos_table_lookup(angle) + boss3_volopt_spawn_pos.x;
    position.z = 76.0f * sin_table_lookup(angle) + boss3_volopt_spawn_pos.z;
    position.y = 0.0f;
    rotation_y = -0x4000 - angle;
    shutter = new TObjVoloptShutter(index);
}
#pragma pop

void TBoss3VoloptP01::init_params() {
    motion_list = TBoss3VoloptP01__resource_bundle->motions;
    action_table = volopt_p01_action_table;
    set_action_table(action_table);
    init_collision_body_parts(this, &volopt_p01_collision_parts, 1);
    variant = 0;
    movementParameters = &volopt_p01_movement;
    recalc_combat_stats((player_stats *)volopt_p01_boss_stat_handle_a, (AttackParams *)volopt_p01_shared_handler_b, (ActorParamBlock *)volopt_p01_object_handle, 1.0f, 1.0f);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_requested_action(this->requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    set_param(0x2E);
    update_prev_position();
    register_by_id();
    load_model(17);
    start_rise();
    ((TBoss3VoloptP01Collision *)bodies)->flags &= ~1;
    charge_effect = NULL;
    glow_effect = NULL;
    add_flags_2e4(4);
    set_actor_flags(0x8000);
    clear_lobby_object_state();
}

TBoss3VoloptP01::~TBoss3VoloptP01() {
    free_collision_body_parts(this);
}

void *TBoss3VoloptP01::create(void *set_data) {
    return new TBoss3VoloptP01(tl_04, set_data);
}

void TBoss3VoloptP01::init_breakup_effect() {
    TBoss3VoloptP01__resource_bundle = boss3_volopt_resources;
    TBoss3VoloptP01__breakup_model = new TBreakUpMdlData(TBoss3VoloptP01__resource_bundle->models[17].model);
    volopt_p01_chunk_list = find_model_node(TBoss3VoloptP01__resource_bundle->models[17].model, 0xD);
    volopt_p01_boss_stat_handle_a = TLobby::register_boss(0x22);
    volopt_p01_shared_handler_b = TLobby::dispatch_shared_handler_b(0x22);
    volopt_p01_object_handle = TLobby::register_object(0x22);
    volopt_p01_shared_handler_handle = (TBoss3VoloptP01Params *)TLobby::dispatch_shared_handler_a(0x22);
    volopt_p01_breakup_color_ptr = reinterpret_cast<u8 *>(static_cast<NJS_CNK_MODEL *>(volopt_p01_chunk_list->model)->polygon_list);
}

void TBoss3VoloptP01::destroy() {
    delete TBoss3VoloptP01__breakup_model;
    TBoss3VoloptP01__breakup_model = NULL;
}

void TBoss3VoloptP01::run_task() {
    f32 y;
    s32 angle;

    if (TObjPlayer::check_demo_mode() == 1) {
        run_demo_task();
        return;
    }
    if (has_flag_0x800() != 0) {
        run_death_reaction();
    } else if (test_flag30_512() != 0 && !(actorFlags & 0x04000000)) {
        run_hit_reaction();
    }
    if (test_actor_flags(0x4000) != 0) {
        if (this->add_status_effect_timer(4, -1) <= 0) {
            status_effects[4].clear();
            clear_actor_flags(0x4000);
        }
    } else {
        if (mode != next_action) {
            if ((s32)state != -1) {
                state = -1;
                dispatch_state();
            }
            mode = next_action;
            state = 0;
        }
        dispatch_state();
        VecCopy(&body_center, &position);
        y = body_center.y;
        body_center.y = y + (18.0f + y_offset);
        ((TBoss3VoloptP01Collision *)bodies)->height = 18.0f + y_offset;
        copy_position();
        angle = pulse_angle;
        pulse_angle = angle + 0x400;
        clear_all_status_effects();
    }
}

void TBoss3VoloptP01::dispatch_state() {
    switch (mode) {
    case 0: update_idle(); return;
    case 2: update_attack(); return;
    case 4: update_state(); return;
    case 9: run_state_machine(); return;
    case 5: update_breakup(); break;
    }
}

void TBoss3VoloptP01::run_demo_task() {}

void TBoss3VoloptP01::render() {
    u32 flags;

    if (!(actorFlags & 0x02000000) && update_object_view_visibility(400.0f, 40.0f) != 0) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        select_actor_lighting(this);
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        if (TObjPlayer::check_demo_mode() == 1) {
            post_translate_matrix(&position);
            rotate_matrix_y(0, rotation_y);
            draw_chunk_object(model);
        } else {
            translate_matrix(0, position.x, position.y + y_offset, position.z);
            rotate_matrix_y(0, rotation_y);
            flags = behavior_flags;
            if (flags & 0x40000) {
                draw_chunk_model(((TBoss3VoloptP01Model *)model)->pieces->root);
            } else {
                if (flags & 0x80000) {
                    volopt_p01_breakup_color_ptr[7] = 255.0f * fabs_float(sin_table_lookup(pulse_angle));
                    volopt_p01_breakup_color_ptr[4] = 0;
                    volopt_p01_breakup_color_ptr[5] = 0;
                } else {
                    volopt_p01_breakup_color_ptr[7] = 0;
                    volopt_p01_breakup_color_ptr[4] = 0xCC;
                    volopt_p01_breakup_color_ptr[5] = 0xFF;
                }
                draw();
            }
        }
        pop_matrix();
        restore_scene_lighting();
        TParticleCtrl::end_effect_render();
    }
}

void TBoss3VoloptP01::update_state() {
    u32 flags;

    switch (state) {
    case 0:
        actorFlags &= ~0x00200200;
        referenceHp = hp;
        if (is_primary != 0) {
            volopt_breakup_flag = 1;
            TBoss3VoloptCore::link_photon(attacker_id, 0);
            TBoss3VoloptCore::set_grabbed_state(0x12C);
        }
        if (TBoss3Volopt::is_v2_mode() != 0) {
            flags = behavior_flags;
            if (flags & 0x10000) {
                behavior_flags = flags & ~1;
                next_action = 2;
                mode = 2;
                state = last_state;
            } else if (flags & 0x20000) {
                behavior_flags = flags & ~1;
                enter_state_machine();
            } else {
                play_sound_effect(0x4003A810, &position, 0xA, 0);
                state = 2;
            }
        } else {
            this->requested_action = 3;
            state = 1;
        case 1:
            advance_animation();
            if (this->action_flags != 8) {
                flags = behavior_flags;
                if (flags & 0x10000) {
                    behavior_flags = flags & ~1;
                    run_attack_action();
                } else if (flags & 0x20000) {
                    behavior_flags = flags & ~1;
                    enter_state_machine();
                } else {
                    play_sound_effect(0x4003A810, &position, 0xA, 0);
                    state = 2;
                }
            }
        }
        break;
    case 2:
        if (update_sink() == 1) {
            behavior_flags &= ~1;
            run_idle_action();
        }
        break;
    case -1:
        behavior_flags &= ~1;
        break;
    }
    submit_cursor_candidate(this, -1);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}

void TBoss3VoloptP01::update_breakup() {
    switch (state) {
    case 0:
        set_flags_30();
        actorFlags |= 0x44040000;
        actorFlags &= ~0x20000000;
        ((TBoss3VoloptP01Collision *)bodies)->flags |= 0x1000;
        this->requested_action = 4;
        state = 1;
        timer = 0x5A;
        spawn_effect_f8(&body_center, timer);
        if (is_primary != 0) {
            volopt_breakup_flag = 1;
            TBoss3VoloptCore::link_photon(attacker_id, 0);
            TBoss3VoloptCore::set_grabbed_state(0x12C);
        }
        state = 1;
    case 1:
        advance_animation();
        timer--;
        if (timer < 0) {
            TBoss3Volopt::create_breakup_mdl(TBoss3VoloptP01__breakup_model, &volopt_p01_breakup_params,
                               texlist, &body_center, rotation_y);
            trigger_dell_biter_events(&body_center);
            behavior_flags |= 0x40000;
            play_sound_effect(0x4003AD07, &position, 0, 0);
            state = 2;
            actorFlags &= ~0x800;
        }
        break;
    case -1:
        return;
    case 2:
        break;
    }
    update_collisions();
}

void TBoss3VoloptP01::update_idle() {
    switch (state) {
    case 0:
        actorFlags |= 0x40000;
        this->requested_action = 0;
        advance_animation();
        y_offset = -40.0f;
        shutter->close();
        is_primary = 0;
        behavior_flags &= ~0x80000;
        state = 1;
        break;
    case 1:
        break;
    case -1:
        actorFlags &= ~0x40000;
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss3VoloptP01::run_state_machine() {
    clear_flags_30();
    switch (state) {
    case 0:
        this->requested_action = 0;
        advance_animation();
        glow_effect = NULL;
        if (!(behavior_flags & 0x20000)) {
            effect_timer = 0x96;
            behavior_flags |= 0x20000;
        }
        if (y_offset >= 0.0f) {
            state = 2;
        } else {
            start_rise();
            shutter->open();
            push_nearby_players();
            state = 1;
        }
        behavior_flags &= ~0x80000;
        break;
    case 1:
        set_flags_30();
        if (update_rise() == 1) {
            state = 2;
        }
        break;
    case 2:
        if (glow_effect == NULL) {
            glow_effect = (TObject *)create_particle_emitter(&body_center, 0x21);
            ((TParticleCtrl *)glow_effect)->set_flags(0x40U);
        }
        state = 3;
    case 3:
        if (glow_effect != NULL) {
            ((TParticleCtrl *)glow_effect)->set_position(&body_center);
        }
        effect_timer--;
        if (effect_timer <= 0) {
            if (glow_effect != NULL) {
                glow_effect->queue_destruction();
                glow_effect = NULL;
            }
            state = 4;
            behavior_flags &= ~0x20000;
        }
        break;
    case 4:
        set_flags_30();
        if (update_sink() == 1) {
            shutter->close();
            run_idle_action();
        }
        break;
    case -1:
        if (glow_effect != NULL) {
            glow_effect->queue_destruction();
            glow_effect = NULL;
        }
        break;
    }
    submit_cursor_candidate(this, -1);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
}
#pragma pop

void TBoss3VoloptP01::update_attack() {
    clear_flags_30();
    switch (state) {
    case 0:
        charge_effect = NULL;
        if (behavior_flags & 0x10000) {
            state = resume_state;
            switch (state) {
            case 2:
            case 3:
                this->requested_action = 5;
                break;
            case 5: {
                Vec v;
                get_node_position(5, &v);
                charge_effect = (TObject *)create_particle_emitter(&v, 0x11A);
                this->requested_action = 2;
                break;
            }
            case 6:
                this->requested_action = 2;
                advance_animation();
                this->frame = 8.0f;
                state = 7;
                break;
            }
        } else {
            quarter_hp = hpmax / 4;
            this->requested_action = 5;
            start_rise();
            behavior_flags |= 0x10000;
            shutter->open();
            timer = 0x14;
            resume_state = 1;
            state = 1;
            push_nearby_players();
            cast_count = 0;
        }
        if (is_primary != 0) {
            behavior_flags |= 0x80000;
        } else {
            behavior_flags &= ~0x80000;
        }
        advance_animation();
        break;
    case 1:
        set_flags_30();
        if (--timer <= 0) {
            play_sound_effect(0x4003A306, &position, 0xA, 0);
            state = 2;
        }
        break;
    case 2:
        set_flags_30();
        if (update_rise() == 1) {
            resume_state = 3;
            state = 3;
        }
        break;
    case 3:
        advance_animation();
        if (this->requested_action == 2) {
            if (is_primary != 0) {
                resume_state = 4;
                state = 4;
            } else {
                resume_state = 0xC;
                state = 0xC;
                behavior_flags &= ~0x10000;
                attack_timer = 0xAF;
            }
        }
        break;
    case 4: {
        Vec v;
        attack_timer = 0x19;
        get_node_position(5, &v);
        charge_effect = (TObject *)create_particle_emitter(&v, 0x11A);
        resume_state = 5;
        state = 5;
    }
    case 5:
        play_persistent_sound(0x4002B51E, this, &position, 0, 0);
        if (--attack_timer <= 0) {
            if (charge_effect != NULL) {
                charge_effect->queue_destruction();
                charge_effect = NULL;
            }
            resume_state = 6;
            state = 6;
        }
        break;
    case 6:
        advance_animation();
        if (this->frame >= 8.0f) {
            state = 7;
        }
        break;
    case 7:
        if (is_primary != 0) {
            if (TBoss3Volopt::is_v2_mode() != 0) {
                cast_tech_on_players();
            } else {
                fire_zonde_at_players();
            }
            cast_count++;
        }
        behavior_flags &= ~0x10000;
        timer = 0x78;
        state = 8;
    case 8:
        timer--;
        if (timer <= 0) {
            state = 9;
        }
        break;
    case 9:
        advance_animation();
        if (this->action_flags != 4) {
            if (cast_count >= 2) {
                state = 0xA;
            } else {
                state = 4;
            }
        }
        break;
    case 10:
        set_flags_30();
        play_sound_effect(0x4003A810, &position, 0xA, 0);
        state = 0xB;
    case 11:
        set_flags_30();
        if (update_sink() == 1) {
            shutter->close();
            run_idle_action();
            behavior_flags &= ~0x80000;
        }
        break;
    case 12:
        if (--attack_timer <= 0) {
            state = 0xA;
        }
        break;
    case -1:
        if (charge_effect != NULL) {
            charge_effect->queue_destruction();
            charge_effect = NULL;
        }
        break;
    }
    submit_cursor_candidate(this, -1);
    minimap_render_dot(&position, -0x5DB4, 1, 0);
    if ((s32)state != -1) {
        last_state = state;
    }
}

void TBoss3VoloptP01::start_rise() {
    rise_phase = 0;
    y_offset = -40.0f;
    ((TBoss3VoloptP01Collision *)bodies)->flags |= 1;
}

s32 TBoss3VoloptP01::update_rise() {
    switch (rise_phase) {
    case 0:
        y_offset += 2.9333334f;
        if (y_offset >= 4.0f) {
            rise_phase = 1;
        }
        break;
    case 1: {
        f32 rest = 0.0f;
        y_offset += -0.6666667f;
        if (y_offset <= rest) {
            y_offset = rest;
            return 1;
        }
        break;
    }
    default:
        rise_phase = 0;
        break;
    }
    return 0;
}

#pragma push
#pragma opt_common_subs off
s32 TBoss3VoloptP01::update_sink() {
    y_offset -= 2.9333334f;
    if (y_offset <= -40.0f) {
        y_offset = -40.0f;
        rise_phase = 0;
        ((TBoss3VoloptP01Collision *)bodies)->flags &= ~1;
        return 1;
    }
    return 0;
}
#pragma pop

void TBoss3VoloptP01::enter_state_machine() {
    if (test_actor_flags(0x04000800) == 0) {
        this->update_if_active(9);
    }
}

void TBoss3VoloptP01::get_node_position(s32 node, Vec *out) {
    push_matrix_from(identity_matrix);
    translate_matrix(0, position.x, position.y + y_offset, position.z);
    rotate_matrix_y(0, rotation_y);
    calc_joint_matrices(frame);
    pop_matrix();
    Vec origin = volopt_p01_node_origin;
    push_matrix_from(anim_model_matrix_array[node]);
    matrix_mult_vec(0, &origin, out);
    pop_matrix();
}

BOOL TBoss3VoloptP01::is_mode_0() {
    return mode == 0;
}

void TBoss3VoloptP01::push_nearby_players() {
    f32 radius_sq;
    s32 i;
    TObjPlayer *player;

    radius_sq = 64.0f;
    for (i = 0; i < registered_player_count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player == NULL || player->get_entity_id() >= 0x1000) {
            break;
        }
        {
            Vec v = *&player->position;
            subtract_vector(&v, &position);
            if (v.x * v.x + v.z * v.z <= radius_sq) {
                v.y = 0.0f;
                vec_set_length(&v, 13.0f);
                vec3_add_to(&player->position, &v);
            }
        }
    }
}

void TBoss3VoloptP01::set_primary(s32 primary) {
    if (test_actor_flags(0x800) == 0) {
        behavior_flags &= ~1;
        this->update_if_active(2);
        is_primary = primary;
    }
}

s32 TBoss3VoloptP01::fire_zonde_at_players() {
    TObjPlayer *list[4];
    Vec pos;
    Vec dir;
    s32 n;
    TObjPlayer *player;
    Vec *target_pos;
    TObjPlayer *target;
    s32 i;
    s32 j;
    TBoss3VoloptHiraisin *hiraisin;
    f32 len;
    TTecZondeEff *bolt;
    DirectAttackPayload attack = volopt_p01_zonde_attack;

    attack.power = get_shared_value(0);
    n = 0;
    for (i = 0; i < registered_player_count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player == NULL || player->get_entity_id() >= 0x1000) {
            break;
        }
        if (!(player->actorFlags & 0x02000800)) {
            list[n] = player;
            n++;
        }
    }
    if (n > 0) {
        get_node_position(12, &pos);
        for (j = 0; j < n; j++) {
            target = list[j];
            target_pos = &target->body_center;
            VecCopy(&dir, target_pos);
            subtract_vector(&dir, &pos);
            len = normalize_vector(&dir);
            new TTecZondeEff(tl_07, &pos, &dir, len);
            VecCopy(&pos, target_pos);
            target->receive_direct_attack(this, attack, NULL, -1, -1);
        }
        hiraisin = (TBoss3VoloptHiraisin *)find_entity_by_id(volopt_hiraisin_id);
        if (hiraisin != NULL) {
            Vec to_hiraisin = *&hiraisin->position;
            subtract_vector(&to_hiraisin, &pos);
            len = normalize_vector(&to_hiraisin);
            new TTecZondeEff(tl_07, &pos, &to_hiraisin, len);
            if (hiraisin->is_grounded() != 0) {
                TBoss3VoloptActionPacket packet;
                packet.init();
                packet.id = entity_id;
                packet.action = 2;
                packet.send();
            }
        }
        play_sound_effect(0x4002A509, NULL, 0, 0);
    }
    return n;
}

void TBoss3VoloptP01::cast_tech_on_players() {
    Vec pos;
    s32 n;
    s32 i;
    TObjPlayer *player;
    s32 j;
    TObjPlayer *target;
    s32 k;

    get_node_position(12, &pos);
    switch (volopt_p01_tech) {
    case 0:
        clear_target_cursor_list(&targets);
        n = 0;
        for (i = 0; i < registered_player_count; i++) {
            player = TObjPlayer::get_player_data(i);
            if (player != NULL && player->get_entity_id() < 0x1000 && !(player->actorFlags & 0x02000800)) {
                targets.records[n].id = player->get_entity_id();
                targets.records[n].flag = 1;
                n++;
            }
        }
        targets.count = n;
        if (n > 0) {
            TTecGiZonde::create(this, &pos, &targets, 0x1D);
        }
        break;
    case 1:
        for (j = 0; j < registered_player_count; j++) {
            player = TObjPlayer::get_player_data(j);
            if (player != NULL && player->get_entity_id() < 0x1000 && !(player->actorFlags & 0x02000800)) {
                TTecFoie::create_ex(this, &pos, &player->body_center, 0x1D);
            }
        }
        break;
    case 2:
        for (k = 0; k < registered_player_count; k++) {
            target = TObjPlayer::get_player_data(k);
            if (target != NULL && target->get_entity_id() < 0x1000 && !(target->actorFlags & 0x02000800)) {
                TTecGiBarta::create(this, &pos, &target->body_center, 0x1D);
            }
        }
        break;
    }
}
