#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/boss/TBoss3VoloptCore.h"
#include "pso/boss/TBoss3VoloptP01.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/TTecZondeEff.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/enemy/TObjEneMe1GiGue.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TBreakUpMdl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/misc/TTecFoie.h"
#include "pso/misc/TTecGiBarta.h"
#include "pso/misc/TTecGiZonde.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjGyaranzoMissile.h"
#include "pso/object/TObjLight_80133568.h"
#include "pso/object/TObjVoloptShutter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/vector.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"

extern "C" {
u16 get_entity_id(void *obj);
void obj_setFlags30(void *obj, u32 flags);
s32 play_sound_effect(s32 id, void *pos, s32 a2, s32 a3);
f32 normalize_vector(Vec *v);
void vec3_add_to(Vec *a, const Vec *b);
void matrix_mult_vec(s32 matrix, const Vec *in, Vec *out);
s32 rotate_matrix_y(s32 matrix, s32 angle);
s32 push_matrix();
s32 post_translate_matrix(const void *pos);
s32 advance_animation_playback(void *obj);
void *find_entity_by_id(u16 id);
void init_collision_body_parts(void *obj, void *parts, s32 count);
void free_collision_body_parts(void *obj);
s32 submit_cursor_candidate(void *obj, s32 a1);
s32 minimap_render_dot(void *pos, s32 color, s32 a2, s32 a3);
f32 fabs_float(f32 x);
void *__construct_array(void *array, void *ctor, void *dtor, u32 size, u32 count);
extern Mtx34 identity_matrix;
extern Mtx34 *anim_model_matrix_array;
extern s32 registered_player_count;

// TBoss3Volopt.cpp defines these; its header does not declare them yet.
}
void reset_status_effect_row(u8 *row);

#pragma readonly_strings on
static const char *TBoss3VoloptP01_class_name = "TBoss3VoloptP01";
static const Vec volopt_p01_node_origin = { 0.0f, 0.0f, 0.0f };
static const DirectAttackPayload volopt_p01_zonde_attack = { 3, 0.0f };

static void *volopt_p01_boss_stat_handle_a;
static void *volopt_p01_shared_handler_b;
static void *volopt_p01_object_handle;
static TBoss3VoloptP01Params *volopt_p01_shared_handler_handle;
static BmlResource *TBoss3VoloptP01__resource_bundle;
static TBoss3VoloptBreakupPieces *TBoss3VoloptP01__breakup_model;
static TBoss3VoloptChunkList *volopt_p01_chunk_list;
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
static TBoss3VoloptBreakupParams volopt_p01_breakup_params = { 0x14, { 0.06f, 1.5f, 0.9f, 0.12f, 0.55f, 0.5f } };
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
    texlist = TBoss3VoloptP01__resource_bundle->models[index].m_c;
}

s32 TBoss3VoloptP01::sub_800443DC(s32 index) {
    return volopt_p01_shared_handler_handle->values[index];
}

void TargetCursorRecord::init_cursor_record() {
    id = 0xFFFF;
    flag = 0;
    value = 0.0f;
}

TargetCursorRecord *fn_8004438C(TargetCursorRecord *record) {
    record->init_cursor_record();
    return record;
}

int TObjPlayer::construct_target_cursor_records() {
    TargetCursorList *list = (TargetCursorList *)this;

    __construct_array(list->records, (void *)fn_8004438C, NULL, sizeof(TargetCursorRecord), 11);
    fn_80044330(list);
    return (int)list;
}

void fn_80044330(TargetCursorList *list) {
    list->count = 0;
}

TBoss3VoloptP01::TBoss3VoloptP01(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    ((TObjPlayer *)&targets)->construct_target_cursor_records();
    m_name = TBoss3VoloptP01_class_name;
    apply_set_data(set_data);
    init_params();
    shutter = new TObjVoloptShutter(0);
}

#pragma push
#pragma fp_contract on
TBoss3VoloptP01::TBoss3VoloptP01(TBoss3Volopt *parent, s32 index, u16 id, s32 angle_param) : TObjEnemyCustom(parent) {
    s32 angle;

    ((TObjPlayer *)&targets)->construct_target_cursor_records();
    m_name = TBoss3VoloptP01_class_name;
    entity_id = id;
    *(s16 *)&set_index = angle_param;
    set_entry = NULL;
    *(s16 *)&room = *(s16 *)&parent->room;
    *((s16 *)&room + 1) = *((s16 *)&parent->room + 1);
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
    set_field_d8((s32)action_table);
    init_collision_body_parts(this, &volopt_p01_collision_parts, 1);
    variant = 0;
    movementParameters = &volopt_p01_movement;
    recalc_combat_stats(volopt_p01_boss_stat_handle_a, volopt_p01_shared_handler_b, volopt_p01_object_handle, 1.0f, 1.0f);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_field_b8(this->requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    set_param(0x2E);
    update_prev_position();
    ((TBoss3Volopt *)this)->reset_photon_effect();
    load_model(17);
    start_rise();
    ((TBoss3VoloptP01Collision *)bodies)->flags &= ~1;
    charge_effect = NULL;
    glow_effect = NULL;
    add_flags_2e4(4);
    obj_setFlags30(this, 0x8000);
    clear_lobby_object_state();
}

TBoss3VoloptP01::~TBoss3VoloptP01() {
    free_collision_body_parts(this);
}

void *TBoss3VoloptP01::create(void *set_data) {
    return new TBoss3VoloptP01(tl_04, set_data);
}

void TBoss3VoloptP01::init_breakup_effect() {
    TBoss3VoloptBreakupPieces *pieces;

    TBoss3VoloptP01__resource_bundle = boss3_volopt_resources;
    pieces = (TBoss3VoloptBreakupPieces *)::operator new(0x10);
    if (pieces != NULL) {
        pieces = (TBoss3VoloptBreakupPieces *)((TBreakUpMdl *)pieces)->init_from_model(TBoss3VoloptP01__resource_bundle->models[17].model);
    }
    TBoss3VoloptP01__breakup_model = pieces;
    volopt_p01_chunk_list = (TBoss3VoloptChunkList *)find_model_node(TBoss3VoloptP01__resource_bundle->models[17].model, 0xD);
    volopt_p01_boss_stat_handle_a = TLobby::register_boss(0x22);
    volopt_p01_shared_handler_b = TLobby::dispatch_shared_handler_b(0x22);
    volopt_p01_object_handle = TLobby::register_object(0x22);
    volopt_p01_shared_handler_handle = (TBoss3VoloptP01Params *)TLobby::dispatch_shared_handler_a(0x22);
    volopt_p01_breakup_color_ptr = volopt_p01_chunk_list->first->color;
}

void TBoss3VoloptP01::destroy() {
    delete TBoss3VoloptP01__breakup_model;
    TBoss3VoloptP01__breakup_model = NULL;
}

void TBoss3VoloptP01::run_task() {
    f32 y;
    s32 angle;

    if (TObjPlayer::check_demo_mode() == 1) {
        sub_80043CA8();
        return;
    }
    if (has_flag_0x800() != 0) {
        vfunc_63();
    } else if (test_flag30_512() != 0 && !(actorFlags & 0x04000000)) {
        vfunc_62();
    }
    if (obj_testFlags30(0x4000) != 0) {
        if (((TObjPlayer *)this)->add_status_effect_timer(4, -1) <= 0) {
            reset_status_effect_row(unk_284);
            obj_clearFlags30(0x4000);
        }
    } else {
        if (mode != (s32)next_action) {
            if ((s32)state != -1) {
                state = -1;
                dispatch_state();
            }
            mode = next_action;
            state = 0;
        }
        dispatch_state();
        VecCopy((Vec *)&m_2fc, &position);
        y = m_300;
        m_300 = y + (18.0f + y_offset);
        ((TBoss3VoloptP01Collision *)bodies)->height = 18.0f + y_offset;
        ((TBoss3VoloptHiraisin *)this)->copy_position();
        angle = pulse_angle;
        pulse_angle = angle + 0x400;
        clear_all_status_effects();
    }
}

void TBoss3VoloptP01::dispatch_state() {
    switch (mode) {
    case 0: sub_80043758(); return;
    case 2: update_attack(); return;
    case 4: update_state(); return;
    case 9: run_state_machine(); return;
    case 5: update_breakup(); break;
    }
}

void TBoss3VoloptP01::sub_80043CA8() {}

void TBoss3VoloptP01::render() {
    u32 flags;

    if (!(actorFlags & 0x02000000) && update_object_view_visibility(400.0f, 40.0f) != 0) {
        TObjFish::set_global_param(texlist);
        select_actor_lighting((s32)this);
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        if (TObjPlayer::check_demo_mode() == 1) {
            post_translate_matrix(&position);
            rotate_matrix_y(0, rotation_y);
            draw_chunk_object(model);
        } else {
            translate_matrix(0, position.x, position.y + y_offset, position.z);
            rotate_matrix_y(0, rotation_y);
            flags = m_388;
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
            TBoss3VoloptCore::link_photon(m_2d4, 0);
            TBoss3VoloptCore::set_grabbed_state(0x12C);
        }
        if (TBoss3Volopt::is_v2_mode() != 0) {
            flags = m_388;
            if (flags & 0x10000) {
                m_388 = flags & ~1;
                next_action = 2;
                mode = 2;
                state = last_state;
            } else if (flags & 0x20000) {
                m_388 = flags & ~1;
                sub_80042F84();
            } else {
                play_sound_effect(0x4003A810, &position, 0xA, 0);
                state = 2;
            }
        } else {
            this->requested_action = 3;
            state = 1;
        case 1:
            advance_animation_playback(this);
            if (this->action_flags != 8) {
                flags = m_388;
                if (flags & 0x10000) {
                    m_388 = flags & ~1;
                    vfunc_60();
                } else if (flags & 0x20000) {
                    m_388 = flags & ~1;
                    sub_80042F84();
                } else {
                    play_sound_effect(0x4003A810, &position, 0xA, 0);
                    state = 2;
                }
            }
        }
        break;
    case 2:
        if (update_sink() == 1) {
            m_388 &= ~1;
            vfunc_58();
        }
        break;
    case -1:
        m_388 &= ~1;
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
        *(s16 *)&timer = 0x5A;
        TObjPlayer::spawn_effect_f8((s32)&m_2fc, *(s16 *)&timer);
        if (is_primary != 0) {
            volopt_breakup_flag = 1;
            TBoss3VoloptCore::link_photon(m_2d4, 0);
            TBoss3VoloptCore::set_grabbed_state(0x12C);
        }
        state = 1;
    case 1:
        advance_animation_playback(this);
        (*(s16 *)&timer)--;
        if (*(s16 *)&timer < 0) {
            TBoss3Volopt::create_breakup_mdl((s32)TBoss3VoloptP01__breakup_model, (s32)&volopt_p01_breakup_params, texlist, (s32)&m_2fc, rotation_y);
            ((TObjPlayer *)&m_2fc)->trigger_dell_biter_events();
            m_388 |= 0x40000;
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
    ((TObjPlayer *)this)->update_collisions();
}

void TBoss3VoloptP01::sub_80043758() {
    switch (state) {
    case 0:
        actorFlags |= 0x40000;
        this->requested_action = 0;
        advance_animation_playback(this);
        y_offset = -40.0f;
        shutter->close();
        is_primary = 0;
        m_388 &= ~0x80000;
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
    sub_8004292C();
    switch (state) {
    case 0:
        this->requested_action = 0;
        advance_animation_playback(this);
        glow_effect = NULL;
        if (!(m_388 & 0x20000)) {
            effect_timer = 0x96;
            m_388 |= 0x20000;
        }
        if (y_offset >= 0.0f) {
            state = 2;
        } else {
            start_rise();
            shutter->open();
            push_nearby_players();
            state = 1;
        }
        m_388 &= ~0x80000;
        break;
    case 1:
        set_flags_30();
        if (update_rise() == 1) {
            state = 2;
        }
        break;
    case 2:
        if (glow_effect == NULL) {
            glow_effect = (TObject *)create_particle_emitter(&m_2fc, 0x21);
            ((TBoss4Type2 *)glow_effect)->set_flags(0x40U);
        }
        state = 3;
    case 3:
        if (glow_effect != NULL) {
            ((TParticleCtrl *)glow_effect)->set_position(&m_2fc);
        }
        effect_timer--;
        if (effect_timer <= 0) {
            if (glow_effect != NULL) {
                glow_effect->queue_destruction();
                glow_effect = NULL;
            }
            state = 4;
            m_388 &= ~0x20000;
        }
        break;
    case 4:
        set_flags_30();
        if (update_sink() == 1) {
            shutter->close();
            vfunc_58();
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
    sub_8004292C();
    switch (state) {
    case 0:
        charge_effect = NULL;
        if (m_388 & 0x10000) {
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
                advance_animation_playback(this);
                this->frame = 8.0f;
                state = 7;
                break;
            }
        } else {
            quarter_hp = hpmax / 4;
            this->requested_action = 5;
            start_rise();
            m_388 |= 0x10000;
            shutter->open();
            *(s16 *)&timer = 0x14;
            resume_state = 1;
            state = 1;
            push_nearby_players();
            cast_count = 0;
        }
        if (is_primary != 0) {
            m_388 |= 0x80000;
        } else {
            m_388 &= ~0x80000;
        }
        advance_animation_playback(this);
        break;
    case 1:
        set_flags_30();
        if (--*(s16 *)&timer <= 0) {
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
        advance_animation_playback(this);
        if (this->requested_action == 2) {
            if (is_primary != 0) {
                resume_state = 4;
                state = 4;
            } else {
                resume_state = 0xC;
                state = 0xC;
                m_388 &= ~0x10000;
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
        play_persistent_sound(0x4002B51E, (s32)this, (u32)&position, 0, 0);
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
        advance_animation_playback(this);
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
        m_388 &= ~0x10000;
        *(s16 *)&timer = 0x78;
        state = 8;
    case 8:
        (*(s16 *)&timer)--;
        if (*(s16 *)&timer <= 0) {
            state = 9;
        }
        break;
    case 9:
        advance_animation_playback(this);
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
            vfunc_58();
            m_388 &= ~0x80000;
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

void TBoss3VoloptP01::sub_80042F84() {
    if (obj_testFlags30(0x04000800) == 0) {
        ((TObjEneMe1GiGue *)this)->update_if_active(9);
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
        if (player == NULL || get_entity_id(player) >= 0x1000) {
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
    if (obj_testFlags30(0x800) == 0) {
        m_388 &= ~1;
        ((TObjEneMe1GiGue *)this)->update_if_active(2);
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

    attack.power = sub_800443DC(0);
    n = 0;
    for (i = 0; i < registered_player_count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player == NULL || get_entity_id(player) >= 0x1000) {
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
            target_pos = (Vec *)&target->m_2fc;
            VecCopy(&dir, target_pos);
            subtract_vector(&dir, &pos);
            len = normalize_vector(&dir);
            bolt = (TTecZondeEff *)TObject::operator new(0x260);
            if (bolt != NULL) {
                bolt->construct((u8 *)tl_07, (u8 *)&pos, (u8 *)&dir, len);
            }
            VecCopy(&pos, target_pos);
            target->receive_direct_attack(this, attack, NULL, -1, -1);
        }
        hiraisin = (TBoss3VoloptHiraisin *)find_entity_by_id(volopt_hiraisin_id);
        if (hiraisin != NULL) {
            Vec to_hiraisin = *&hiraisin->position;
            subtract_vector(&to_hiraisin, &pos);
            len = normalize_vector(&to_hiraisin);
            bolt = (TTecZondeEff *)TObject::operator new(0x260);
            if (bolt != NULL) {
                bolt->construct((u8 *)tl_07, (u8 *)&pos, (u8 *)&to_hiraisin, len);
            }
            if (hiraisin->sub_80040FCC() != 0) {
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
        fn_80044330(&targets);
        n = 0;
        for (i = 0; i < registered_player_count; i++) {
            player = TObjPlayer::get_player_data(i);
            if (player != NULL && get_entity_id(player) < 0x1000 && !(player->actorFlags & 0x02000800)) {
                targets.records[n].id = get_entity_id(player);
                targets.records[n].flag = 1;
                n++;
            }
        }
        targets.count = n;
        if (n > 0) {
            ((TTecGiZonde *)this)->create(&pos, &targets, (void *)0x1D);
        }
        break;
    case 1:
        for (j = 0; j < registered_player_count; j++) {
            player = TObjPlayer::get_player_data(j);
            if (player != NULL && get_entity_id(player) < 0x1000 && !(player->actorFlags & 0x02000800)) {
                TTecFoie::create_ex(this, &pos, &player->m_2fc, (void *)0x1D);
            }
        }
        break;
    case 2:
        for (k = 0; k < registered_player_count; k++) {
            target = TObjPlayer::get_player_data(k);
            if (target != NULL && get_entity_id(target) < 0x1000 && !(target->actorFlags & 0x02000800)) {
                ((TTecGiBarta *)this)->create(&pos, &target->m_2fc, (void *)0x1D);
            }
        }
        break;
    }
}
