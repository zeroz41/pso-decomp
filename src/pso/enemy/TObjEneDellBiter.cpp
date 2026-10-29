#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/player/TObjPlayer_800D8FDC.h"
#include "pso/enemy/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/TUnk_80494968.h"
#include "pso/render/reflection.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/system/BmlResource.h"
#include "pso/system/NinjaTypes.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneDellBiter.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/map/FloorArea.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/object/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"

#include "pso/player/TUnk_804928CC.h"
#include "pso/player/TUnk_80490470.h"
#include "pso/enemy/TObjEneDellBiter_Eff_Rush.h"
#include <stddef.h>
#include "pso/unk/TObjEneDellBiter_Eff_TpAbsorb1.h"

#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"

#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/item/TItemData.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjFish.h"

#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/item/TItem.h"

extern "C" {
f64 atan2_float(f32, f32);
s32 spawn_particle_effect(void *, int);
s32 approach_angle_limited(int, int, int);
s32 play_sound_effect(int, void *, int, int);
void * __nw__7TObjectFUl(int);
extern const f64 TObjEneDellBiter__data_80475328;
extern DelbiterMovementParameters *TObjEneDellBiter__movement_params;
extern const f32 lbl_805DEFCC;
extern const f32 lbl_805DEFD0;
extern const f32 lbl_805DEFD4;
extern const f32 TObjEneDellBiter__data_805DEFD8;
s32 turn_toward_angle_limited__15TObjBoss2TunnelFlllll(int, int, int, int, int);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
extern const f32 lbl_805DF004;
extern const f32 lbl_805DF008;
extern const f32 TObjEneDellBiter__data_805DF00C;
extern const f32 lbl_805DF000;
extern const f32 lbl_805DF010;
s32 fill_value_array(int);
s32 enemy_validate_retained_target(void *);
u32 enemy_probe_wall_ahead__13TBoss5GryphonFfff(void *, f32, f32, f32);
f32 subtract_vector(void *, void *);
extern const f32 TObjEneDellBiter__data_805DEFE8;
extern const f32 TObjEneDellBiter__data_805DEFF4;
extern const f32 lbl_805DEFF8;
extern const f32 lbl_805DEFFC;

s16 get_attack_params_atp_min(void *p);
s32 obj_is_hit_receivable(void *);
u16 get_entity_id(void *);
void obj_setFlags30(void *, s32);
void TLobby__sub_8001FE7C(void*, int);
void attach_particle_model(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, f32 farg0);
s32 get_mode__11TCameraCtrlFPv(void *);
u32 csnLookAt(void *, void *);
s32 *csnVectorUnder(Vec *arg0, u32 *arg1, s32 arg2);
s32 rotate_xz_pair_by_angle(void *, void *, int);
void *create_particle_emitter(void *pos, s32 id);
s32 TObjPlayer__sub_800A04F0(void *);
void enemy_clear_target__12TObjEneDD_STFUs(void *);
void enemy_set_target_id(void *, u16);
s32 update_player_state__9TObjEneDDFv(void *, void *, int);
s32 get_camera_ctrl__9TObjEneDDFv(void *, int);
s32 pack_debug_text_position(s32, s32);
void invoke_initialization_hook__9TObjEneDDFv(void *, void *);
s32 attack_target_history_add(s32, void *);
void fn_800D8830(void *owner, void *pos);
s32 TObjEneGibbles__sub_800D8988(s32);
f32 horizontal_distance_squared(void *, void *);
void *get_player_by_client_id(s32 i);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void TObjPlayer__sub_8023DEE0(s16 *p, s16 a, s16 b, u16 id);
}
void restore_render_scissor(s32 arg0);
extern "C" {

s32 debug_printf_at(s32, const char *, ...);
s32 vec3_add_to(void *, void *);
s32 scale_matrix(int, f32, f32, f32);
s32 rotate_matrix_y(int, int);
s32 rotate_matrix_x(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_chunk_object(void *child);

extern s32 TObjEneDellBiter__shared_handler_param;
extern u32 TObjEneDellBiter__shared_model_resource;
extern s32 TObjEneDellBiter__demo_script_step;
extern s32 TObjEneDellBiter__demo_rotate_x_angle;
extern s32 TObjEneDellBiter__demo_script_cursor;
extern const f32 TObjEneDellBiter__data_805DEFB8;
extern const f32 TObjEneDellBiter__data_805DEFE0;
extern const f32 TObjEneDellBiter__data_805DEFE4;
void free_collision_body_parts(void *);
extern s32 __dt__15RenderFadeStateFv[];
extern s32 __ct__15RenderFadeStateFv[];
extern DelbiterContactAttack lbl_8047528C[];
extern Vec lbl_804752A0[];
extern char lbl_804752AC[];
extern char lbl_804752BC[];
extern char lbl_804752D0[];
extern char lbl_804752E4[];
extern char lbl_804752F8[];
extern char lbl_8047530C[];
extern char lbl_80475318[];
extern s32 __vt__25TObjEneDellBiter_Eff_Rush[];
extern Vec dellbiter_demo_camera_vec;
extern s32 TObjEneDellBiter_Eff_Rush__name;
extern void *TObjEneDellBiter__class_name;
extern s32 actor_frame_tick;
extern s32 game_difficulty_selection;
extern s32 TObjEneDellBiter__scrolling_uv_polygon_list;
extern s32 TObjEneDellBiter__last_uv_scroll_tick;
extern const f32 lbl_805DEFAC;
extern const f32 lbl_805DEFB0;
extern const f32 lbl_805DEFB4;
extern const f32 lbl_805DEFBC;
extern const f32 lbl_805DEFC8;
extern const f32 lbl_805DEFDC;
extern const f32 lbl_805DEFEC;
extern const f32 lbl_805DEFF0;
extern const f32 lbl_805DF014;
extern const f32 lbl_805DF018;
extern const f32 lbl_805DF01C;
extern const f32 lbl_805DF020;
extern const f32 lbl_805DF024;
extern const f32 lbl_805DF028;
extern const f32 lbl_805DF02C;
extern const f32 lbl_805DF030;
extern const f32 lbl_805DF034;
extern const f32 lbl_805DF03C;
extern void *tl_04;

extern "C" {
s32 is_split_screen();
s32 reset_hp__9TObjEneDDFv(void *, int, int, int);
s32 initialize_enemy_state__9TObjEneDDFv(void *, int);
s32 init_model__9TObjEneDDFv(void *, void *, int);
s32 init_collision_body_parts(void *, void *, int);
void *__nw__7TObjectFUl(int);
s32 get_camera_mode__11TCameraCtrlFv();
s32 is_main_phase_15__9TObjEneDDFv();
s32 defer_render__7TObjectFv(void *);
extern Vec lbl_80475294[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
}

extern "C" u8 lbl_80475138[];
extern "C" u8 lbl_80475148[];
extern "C" u8 lbl_80475160[];
extern "C" u8 lbl_80475174[];
extern "C" u8 lbl_8047518C[];
extern "C" u8 lbl_804751A0[];
extern "C" u8 lbl_804751B8[];
extern "C" u8 lbl_804751CC[];
extern "C" u8 lbl_804751E0[];
extern "C" u8 lbl_804751F8[];
extern "C" u8 lbl_8047520C[];
extern "C" u8 lbl_80475220[];
extern "C" u8 lbl_80475238[];
extern "C" u8 lbl_8047524C[];
extern const char *lbl_804E6C3C[2];
extern const char *TObjEneDellBiter__resource_descriptor[11];
extern const char *lbl_804E6C80[2];
extern const char *lbl_804E6C88[11];

extern "C" {
u8 *dispatch_shared_handler_a__6TLobbyFl(s32);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
void *load_enemy_bml_resource(void *);
extern DelbiterAttackDefinition ene_dell_biter_attack_def;
}
DelbiterInitialParameters TObjEneDellBiter__param_table = {
    225.0f, 0.0f, 0x600, {0, 0, 0, 0}
};
CollisionBody lbl_804E6B8C[4] = {
    {{0.0f, 12.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 15.0f, 0.0f, 0, 0x9D03, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 15.0f, 0.0f, 0, 0x9D03, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 12.0f, 0.0f}, 15.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f}
};
__declspec(section ".data") const char *lbl_804E6C3C[2] = {
    (const char *)&lbl_80475138, NULL,
};
const char *TObjEneDellBiter__resource_descriptor[11] = {
    (const char *)&lbl_80475148, (const char *)&lbl_80475160, (const char *)&lbl_80475174, (const char *)&lbl_8047518C,
    (const char *)&lbl_804751A0, (const char *)&lbl_804751B8, (const char *)&lbl_804751CC, (const char *)&lbl_804751E0,
    (const char *)&lbl_804751F8, (const char *)&lbl_8047520C, NULL,
};
BmlResourceDescriptor lbl_804E6C70 = {
    (const char *)lbl_80475220, lbl_804E6C3C, TObjEneDellBiter__resource_descriptor, 1, 10
};
__declspec(section ".data") const char *lbl_804E6C80[2] = {
    (const char *)&lbl_80475238, NULL,
};
const char *lbl_804E6C88[11] = {
    (const char *)&lbl_80475148, (const char *)&lbl_80475160, (const char *)&lbl_80475174, (const char *)&lbl_8047518C,
    (const char *)&lbl_804751A0, (const char *)&lbl_804751B8, (const char *)&lbl_804751CC, (const char *)&lbl_804751E0,
    (const char *)&lbl_804751F8, (const char *)&lbl_8047520C, NULL,
};
BmlResourceDescriptor lbl_804E6CB4 = {
    (const char *)lbl_8047524C, lbl_804E6C80, lbl_804E6C88, 1, 10
};
TObjMotionAction dell_biter_param_table[10] = {
    {1, 0, 8, 0.5f, 0},
    {1, 0, 9, 0.7f, 0},
    {1, 0, 5, 0.8f, 0},
    {3, 0, 6, 0.9f, 0},
    {3, 0, 0, 0.6f, 0},
    {3, 0, 1, 0.6f, 0},
    {3, 0, 2, 1.0f, 0},
    {3, 0, 4, 0.7f, 0},
    {3, 0, 7, 1.0f, 0},
    {3, 0, 3, 0.7f, 0}
};

extern s32 dellbiter_boss_stat_handle;
extern s32 dellbiter_object_stat_handle;
extern const f32 lbl_805DF038;

}

#pragma fp_contract on

void TObjEneDellBiter::load_resources() {
    dellbiter_demo_camera_vec.x = TObjEneDellBiter__data_805DEFF4;
    dellbiter_demo_camera_vec.y = TObjEneDellBiter__data_805DEFF4;
    dellbiter_demo_camera_vec.z = TObjEneDellBiter__data_805DEFF4;
    if (is_split_screen() != 0) {
        TObjEneDellBiter__shared_model_resource = (u32)load_enemy_bml_resource(&lbl_804E6CB4);
    } else {
        TObjEneDellBiter__shared_model_resource = (u32)load_enemy_bml_resource(&lbl_804E6C70);
    }
    dellbiter_boss_stat_handle = register_boss__6TLobbyFl(0xD);
    TObjEneDellBiter__shared_handler_param = dispatch_shared_handler_b__6TLobbyFl(0xD);
    dellbiter_object_stat_handle = register_object__6TLobbyFl(0xD);
    TObjEneDellBiter__movement_params = (DelbiterMovementParameters *)dispatch_shared_handler_a__6TLobbyFl(0xD);
    TObjEneDellBiter__demo_script_step = 0;
    TObjEneDellBiter__demo_rotate_x_angle = 0;
    TObjEneDellBiter__demo_script_cursor = 0;
    TObjEneDellBiter::set_min_clamped_entry_value(4, TObjEneDellBiter__movement_params->animation_speed_4);
    TObjEneDellBiter::set_min_clamped_entry_value(5, TObjEneDellBiter__movement_params->animation_speed_5);
    {
        BmlResource *resource = (BmlResource *)TObjEneDellBiter__shared_model_resource;
        NJS_OBJECT *object = (NJS_OBJECT *)resource->models->model;
        TObjEneDellBiter__scrolling_uv_polygon_list = (s32)((NJS_CNK_MODEL *)object->child->model)->polygon_list;
        TObjEneDellBiter__last_uv_scroll_tick = 0;
        DelbiterAttackDefinition attack = ene_dell_biter_attack_def;
        attack.motion = resource->motions;
        TLobby::spawn_npc_enemy((s16)0x46, resource->models->model, resource->models->m_c,
            (s32)&attack, lbl_804E6B8C[0].radius, TObjEneDellBiter__data_805DEFF4);
    }
}

void *TObjEneDellBiter::create(void *set_data) {
    return new TObjEneDellBiter((TObject *)tl_04, set_data);
}

void TObjEneDellBiter::destroy_static_instance() {
    if ((u32) TObjEneDellBiter__shared_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjEneDellBiter__shared_model_resource, 1);
        TObjEneDellBiter__shared_model_resource = 0U;
    }
}

void TObjEneDellBiter::set_min_clamped_entry_value(s32 index, f32 speed) {
    if (speed < lbl_805DF03C) {
        speed = lbl_805DF03C;
    }
    dell_biter_param_table[index].speed = speed;
}

TObjEneDellBiter::TObjEneDellBiter(TObject *parent, void *set_data) : TObjEneDD_ST(parent) {
    m_name = (const char *)TObjEneDellBiter__class_name;
    invoke_initialization_hook__9TObjEneDDFv(this, set_data);
    init_target_offsets();
    init_params();
}

void TObjEneDellBiter::init_params() {
    s32 i;
    init_position_vectors();
    model = (void *)((BmlResource *)TObjEneDellBiter__shared_model_resource)->models->model;
    texlist = ((BmlResource *)TObjEneDellBiter__shared_model_resource)->models->m_c;
    init_model__9TObjEneDDFv(this, lbl_804E6B8C, 1);
    bodies->flags |= 0x400000;
    set_field_d8((s32)&dell_biter_param_table);
    set_field_dc((s32)((BmlResource *)TObjEneDellBiter__shared_model_resource)->motions);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_field_b8(this->requested_action);
    reset_hp__9TObjEneDDFv(this, dellbiter_boss_stat_handle, TObjEneDellBiter__shared_handler_param, dellbiter_object_stat_handle);
    set_state_8();
    movementParameters = &TObjEneDellBiter__param_table;
    initialize_enemy_state__9TObjEneDDFv(this, 0x48);
    field_37c = lbl_805DF038;
    enemy_init_acquire_period(30);
    enemy_init_validate_period(30);
    flags = 0;
    flags_3c4 = 0;
    VecCopy(&reflection_position, &position);
    flags |= 1;
    fade.reset_obstruction_fade();
    for (i = 0; i < 4; i++) {
        camera_fades[i].activate_and_dispatch();
    }
    for (i = 0; i < 3; i++) {
        VecCopy(&part_positions[i], &position);
    }
    part_rotation_x = 0;
    field_488 = 0;
    field_48c = 0;
    effect_timer = 0;
    attack_bodies[0] = new TUnk_804928CC(this, this, &lbl_804E6B8C[1], 1);
    attack_bodies[1] = new TUnk_804928CC(this, this, &lbl_804E6B8C[2], 1);
    rush_body = new TObjCollidable(NULL);
    init_collision_body_parts(rush_body, &lbl_804E6B8C[3], 1);
    attack_history = new AreaAttackHistory(8);
    saver = TUnk_80494968::create(0xFF5050FF, 0x80000080);
    state_timer = 0;
    field_4d0 = 0;
    field_4d4 = 0;
    field_4d8 = 0;
    field_4dc = TObjEneDellBiter__data_805DEFF4;
    field_4e0 = TObjEneDellBiter__data_805DEFF4;
    mode = 1;
    dispatch_action(mode, 4);
    effect = NULL;
    status_effects[0] = NULL;
    status_effects[1] = NULL;
}

TObjEneDellBiter::~TObjEneDellBiter() {
    if (effect != NULL) {
        effect->queue_destruction();
        effect = NULL;
    }
    if (status_effects[0] != NULL) {
        status_effects[0]->queue_destruction();
        status_effects[0] = NULL;
    }
    if (status_effects[1] != NULL) {
        status_effects[1]->queue_destruction();
        status_effects[1] = NULL;
    }
    if (saver != NULL) {
        saver->queue_destruction();
        saver = NULL;
    }
    if (attack_history != NULL) {
        delete attack_history;
        attack_history = NULL;
    }
    if (attack_bodies[1] != NULL) {
        delete attack_bodies[1];
        attack_bodies[1] = NULL;
    }
    if (attack_bodies[0] != NULL) {
        delete attack_bodies[0];
        attack_bodies[0] = NULL;
    }
    if (rush_body != NULL) {
        free_collision_body_parts(rush_body);
        delete rush_body;
        rush_body = NULL;
    }
    free_collision_body_parts(this);
}

void TObjEneDellBiter::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        this->fn_80303538();
        return;
    }
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
        if ((s32) TObjEneDellBiter__last_uv_scroll_tick != (s32) actor_frame_tick) {
            TObjEneDellBiter__last_uv_scroll_tick = actor_frame_tick;
            TObjPlayer__sub_8023DEE0((s16 *)TObjEneDellBiter__scrolling_uv_polygon_list, 0xC, 0, 0);
        }
    }
    this->update_particle_emitters();
    if (flags_3c4 & 0x4000) {
        TObjEneRecon::set_active();
    }
    this->set_effect_pos_above_self();
    submit_default_cursor_candidate();
    this->vfunc_100();
}

void TObjEneDellBiter::vfunc_28() {  }

void TObjEneDellBiter::vfunc_63() {
    if (mode != 11) {
        transition_enemy_state(11);
    }
}

void TObjEneDellBiter::vfunc_62() {
    if ((s16) mode != 0xA) {
        sub_803055C8();
        if (flags & 0x14) {
            this->clear_attack_receipts();
            return;
        }
        transition_enemy_state(10);
    }
}

void TObjEneDellBiter::vfunc_61() {  }

void TObjEneDellBiter::set_effect_pos_above_self() {
    VecCopy((Vec *)&m_2fc, &position);
    m_300 += lbl_805DF028;
    VecCopy(&center, (Vec *)&m_2fc);
}

void TObjEneDellBiter::vfunc_88() {  }

void TObjEneDellBiter::update_particle_emitters() {
    Vec emission_position;
    s32 active_flags = flags;
    if (active_flags & 0x10) {
        if (effect_timer <= 0) {
            flags = active_flags & ~0x10;
        } else {
            VecCopy(&emission_position, &position);
            emission_position.y += TObjEneDellBiter__data_805DEFE0;
            if (game_difficulty_selection == 3) {
                TParticleCtrl *emitter = status_effects[0];
                if (emitter == NULL) {
                    status_effects[0] = (TParticleCtrl *)create_particle_emitter(&emission_position, 0x216);
                } else {
                    emitter->set_position(&emission_position);
                }
            } else {
                TParticleCtrl *emitter = status_effects[0];
                if (emitter == NULL) {
                    status_effects[0] = (TParticleCtrl *)create_particle_emitter(&emission_position, 0x215);
                } else {
                    emitter->set_position(&emission_position);
                }
                emitter = status_effects[1];
                if (emitter == NULL) {
                    status_effects[1] = (TParticleCtrl *)create_particle_emitter(&emission_position, 0x219);
                } else {
                    emitter->set_position(&emission_position);
                }
            }
        }
        effect_timer--;
        return;
    }
    TParticleCtrl *emitter = status_effects[0];
    if (emitter != NULL) {
        emitter->queue_destruction();
        status_effects[0] = NULL;
    }
    emitter = status_effects[1];
    if (emitter != NULL) {
        emitter->queue_destruction();
        status_effects[1] = NULL;
    }
}

void TObjEneDellBiter::init_target_offsets() {
    const f32 *minimum;
    field_4a8 = lbl_805DF030 + parameters[0];
    field_4ac = lbl_805DF030 + parameters[1];
    field_4b0 = TObjEneDellBiter__data_805DEFE8 + parameters[2];
    if (field_4b0 < *(minimum = &TObjEneDellBiter__data_805DEFE0)) {
        field_4b0 = *minimum;
    }
    field_4b4 = lbl_805DF030 + parameters[3];
    field_4b8 = lbl_805DF034 + parameters[4];
    if ((s32)variant >= 1) {
        field_4bc = 1;
        return;
    }
    field_4bc = 0;
}

void TObjEneDellBiter::update_contact_attacks() {
    f32 frame = this->frame;
    if (frame >= lbl_805DEFF0 && frame <= lbl_805DF02C) {
        attack_bodies[0]->rotation_y = rotation_y;
        VecCopy(&attack_bodies[0]->position, &part_positions[1]);
        attack_bodies[0]->refresh_collision_body_centers();
        attack_bodies[1]->rotation_y = rotation_y;
        VecCopy(&attack_bodies[1]->position, &part_positions[1]);
        attack_bodies[1]->refresh_collision_body_centers();
        DelbiterContactAttack attack = lbl_8047528C[0];
        attack.power = get_attack_params_atp_min((void *)TObjEneDellBiter__shared_handler_param);
        if (vfunc_99() != 0) {
            attack.flags |= 2;
        }
        attack_bodies[0]->call_vt16_with_default(&attack, attack_history);
        attack_bodies[1]->call_vt16_with_default(&attack, attack_history);
    }
}

s32 TObjEneDellBiter::check_rush_collisions() {
    s32 hit;
    TObjChara *target;
    s32 i;
    DirectAttackPayload attack;
    hit = 0;
    VecCopy(&rush_body->position, &position);
    TObjPlayer::init_all_slots();
    rush_body->check_object_collisions();
    if (rush_body->bodies->flags & 0x180000) {
        hit = 1;
        for (i = 0; i < 0x10; i++) {
            target = (TObjChara *)TObjPlayer::get_battle_param(i);
            if (target == NULL) {
                break;
            }
            if (obj_is_hit_receivable(target) != 0 && attack_target_history_add((s32)attack_history, target) != 0) {
                if (flags & 0x10) {
                    if (game_difficulty_selection == 3) {
                        attack.kind = 5;
                        attack.power = TObjEneDellBiter__movement_params->powered_attack_power;
                    } else {
                        attack.kind = 3;
                        attack.power = TObjEneDellBiter__movement_params->powered_attack_power;
                    }
                } else {
                    attack.kind = 0;
                    attack.power = TObjEneDellBiter__movement_params->attack_power;
                }
                target->receive_direct_attack(this, attack, NULL, -1, -1);
                if (target->obj_testFlags30(0x04000000) == 0) {
                    obj_setFlags30(target, 0x600);
                }
                new TObjEneDellBiter_Eff_Rush(this, this, target, lbl_805DF028);
            }
        }
    }
    return hit;
}

void TObjEneDellBiter::update_attack_effect() {
    if (fn_803059BC(&position) != 0) {
        TObjEneGibbles__sub_800D8988((s32)&position);
        return;
    }
    play_sound_effect(((TObjEnemy *)(this))->remap_sound_for_area((s32)((void *)0x40039E11)), &position, 0, 0);
}

void TObjEneDellBiter::spawn_front_particle() {
    Vec front;
    front.x = lbl_805DF024;
    front.y = TObjEneDellBiter__data_805DEFF4;
    front.z = lbl_805DF004;
    rotate_xz_pair_by_angle(&front.x, &front.z, rotation_y);
    vec3_add_to(&front, &position);
    if (fn_803059BC(&front) == 0) {
        spawn_particle_effect(&front, 0xF3);
    }
}

s32 TObjEneDellBiter::fn_803059BC(const Vec *origin) {
    Vec pos;
    CsnGroundHit *hit;
    void *e;
    VecCopy(&pos, origin);
    pos.y += 15.0f;
    hit = (CsnGroundHit *)csnVectorUnder(&pos, (u32 *)&m_120, 0x4007);
    if (hit != NULL) {
        flags_3c4 = hit->surface->flags;
        if (flags_3c4 & 0x4000) {
            VecCopy(&reflection_position, &hit->surface->point);
        } else {
            VecCopy(&reflection_position, &position);
        }
        if (hit->flags & 4) {
            e = (void *)spawn_particle_effect(&hit->surface->point_38, 0x49);
            if (e != NULL) {
                attach_particle_model((u8 *)e, (s32)(TParticleCtrl::get_particle_model(2)), (s32)(TParticleCtrl::get_instance()), 0, 1, (f32)TObjEneDellBiter__data_805DEFD8);
                ((TParticleCtrl *)e)->set_scale(lbl_805DF020, lbl_805DF020);
            }
            e = (void *)spawn_particle_effect(&hit->surface->point_38, 0xA4);
            if (e != NULL) {
                ((TParticleCtrl *)e)->set_scale(lbl_805DF020, lbl_805DF020);
            }
            return 1;
        }
        if (hit->flags & 2) {
            e = (void *)spawn_particle_effect(&hit->surface->point_54, 0x49);
            if (e != NULL) {
                attach_particle_model((u8 *)e, (s32)(TParticleCtrl::get_particle_model(2)), (s32)(TParticleCtrl::get_instance()), 0, 1, (f32)TObjEneDellBiter__data_805DEFD8);
                ((TParticleCtrl *)e)->set_scale(lbl_805DF020, lbl_805DF020);
            }
            e = (void *)spawn_particle_effect(&hit->surface->point_54, 0xA4);
            if (e != NULL) {
                ((TParticleCtrl *)e)->set_scale(lbl_805DF020, lbl_805DF020);
            }
            return 1;
        }
    }
    return 0;
}

void TObjEneDellBiter::fn_8030591C() {
    if (is_passing_frame(TObjEneDellBiter__data_805DEFF4) != 0 || is_passing_frame(lbl_805DF01C) != 0) {
        if (fn_803059BC(&position) != 0) {
            fn_800D8830(this, &position);
            return;
        }
        play_persistent_sound(((TObjEnemy *)(this))->remap_sound_for_area((s32)((void *)0x40039E13)), (s32)this, (u32)&position, 0, 0);
        spawn_particle_effect(&position, 0xF0);
    }
}

void TObjEneDellBiter::fn_803058DC() {
    if (is_passing_frame(lbl_805DF008) != 0) {
        spawn_front_particle();
    }
}

s32 TObjEneDellBiter::validate_or_update_target() {
    if (!(flags & 8)) {
        return update_linked_position(TObjEneDellBiter__data_805DF00C);
    }
    s32 valid = enemy_validate_retained_target(this);
    if (valid == 0) {
        flags &= ~8;
    }
    return valid;
}

s32 TObjEneDellBiter::select_farthest_visible_player() {
    s32 count;
    TObjChara *player;
    u16 id;
    s32 i;
    f32 distance;
    f32 best;
    best = TObjEneDellBiter__data_805DEFF4;
    id = 0xFFFF;
    count = TLobby::get_game_mode();
    for (i = 0; i < count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player->is_alive() != 0) {
            distance = horizontal_distance_squared(&m_2fc, &player->position);
            if (distance < lbl_805DF018 && distance > best &&
                csnLookAt(&m_2fc, &player->m_2fc) == 0) {
                id = get_entity_id(player);
                best = distance;
            }
        }
    }
    if (id != 0xFFFF) {
        enemy_set_target_id(this, id);
        return 1;
    }
    enemy_clear_target__12TObjEneDD_STFUs(this);
    return 0;
}

void TObjEneDellBiter::fn_80305688() {
    s32 count;
    TObjChara *player;
    s32 i;
    count = TLobby::get_game_mode();
    for (i = 0; i < count; i++) {
        player = TObjPlayer::get_player_data(i);
        if (player->is_alive() != 0) {
            f32 distance = horizontal_distance_squared(&m_2fc, &player->position);
            if (csnLookAt(&m_2fc, &player->m_2fc) == 0 &&
                distance <= field_4b0 * field_4b0 && random_ratio() <= field_4ac) {
                DirectAttackPayload attack;
                attack.kind = 18;
                attack.power = TObjEneDellBiter__data_805DEFD8;
                player->receive_direct_attack(this, attack, NULL, -1, -1);
            }
        }
    }
}

void TObjEneDellBiter::fn_80305684() {}

s32 TObjEneDellBiter::vfunc_104(f32 distance) {
    if (vfunc_99() != 0) {
        return select_and_apply_target(distance);
    }
    return select_nearest_target(distance);
}

void TObjEneDellBiter::sub_803055C8() {
    u16 id = m_2d4;
    if (id < 0x1000U) {
        void *player = get_player_by_client_id(id);
        if (player != NULL) {
            set_target_player(player);
        }
        flags |= 8;
    }
}

s32 TObjEneDellBiter::check_low_hp_transition() {
    if (!(flags & 0x10) && hp <= hpmax / 2 &&
        random_ratio() <= field_4b8) {
        transition_enemy_state(12);
        return 1;
    }
    return 0;
}

s32 TObjEneDellBiter::fn_803054FC() {
    if (random_ratio() <= field_4b4) {
        transition_enemy_state(9);
        return 1;
    }
    return 0;
}

s32 TObjEneDellBiter::fn_803054A8() {
    if (random_ratio() <= field_4a8) {
        transition_enemy_state(8);
        return 1;
    }
    return 0;
}

void TObjEneDellBiter::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        update_state(reason);
        return;
    case 1:
        fn_80305268(reason);
        return;
    case 2:
        fn_80305034(reason);
        return;
    case 3:
        fn_80304D10(reason);
        return;
    case 4:
        fn_80304B88(reason);
        return;
    case 5:
        fn_8030492C(reason);
        return;
    case 6:
        fn_803044AC(reason);
        return;
    case 7:
        fn_803042B0(reason);
        return;
    case 8:
        fn_803040D0(reason);
        return;
    case 9:
        fn_80303BC0(reason);
        return;
    case 12:
        fn_80303F04(reason);
        return;
    case 10:
        fn_80303AA0(reason);
        return;
    case 11:
        state_death(reason);
    default:
        return;
    }
}

void TObjEneDellBiter::update_state(s32 reason) {
    switch (reason) {
    case 4:
        set_field_378(0);
        state_timer = 0;
        return;
    case 3:
        transition_enemy_state(1);
        return;
    case 0:
        state_timer = (s32) (state_timer + 1);
    case 5:
        return;
    }
}

void TObjEneDellBiter::fn_80305268(s32 reason) {
    switch (reason) {
    case 4:
        this->set_field_378(1);
        flags = (s32) (flags | 1);
        this->vfunc_95();
        VecCopy(&position, &home_position);
        return;
    case 3:
        if (update_linked_position(TObjEneDellBiter__data_805DF00C) != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
            rotation_y = (s32) (TObjEneDellBiter__data_80475328 * atan2_float((f32) (target_direction.x), (f32) (target_direction.z)));
            if ((s32) field_4bc == 1) {
                transition_enemy_state(3);
                return;
            }
            transition_enemy_state(2);
        } else {
        case 5:
        case 0:
            return;
        }
        break;
    }
}

void TObjEneDellBiter::fn_80305034(s32 reason) {

    switch (reason) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(5);
        flags = (s32) (flags & 0xFFFFFFFE);
        flags = (s32) (flags | 2);
        this->vfunc_95();
        fade.reset_obstruction_fade();
        state_timer = 0;
        field_4d0 = 0;
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &position);
        VecCopy((Vec *)(&m_2fc), &position);
        field_488 = 0;
        field_48c = 0;
        play_sound_effect(((TObjEnemy *)(this))->remap_sound_for_area((s32)((void *)0x40039E12)), &position, 0, 0);
        return;
    case 3:
        if ((s32) field_4d0 == 2) {
            transition_enemy_state(5);
        }
        return;
    case 0:
        advance_animation();
        update_linked_position(TObjEneDellBiter__data_805DF00C);
        state_timer = (s32) (state_timer + 1);
        switch (field_4d0) {
        case 0:
            if ((s32) state_timer > 0x14) {
                field_4d0 = 1;
                this->requested_action = 3;
                play_sound_effect(((TObjEnemy *)(this))->remap_sound_for_area((s32)((void *)0x40039B14)), &position, 0, 0);
            }
            fn_8030591C();
            this->move_with_wall_slide_on_ground((f32) (target_direction.x), (f32) (target_direction.z), lbl_805DF014);
            fn_80305684();
            break;
        case 1:
            fn_803058DC();
            if (this->get_flag_b4() != 0) {
                field_4d0 = 2;
            }
            break;
        }
        if (fade.advance_toward_max() != 0) {
            flags = (s32) (flags & 0xFFFFFFFD);
            this->vfunc_96();
            this->vfunc_89();
            return;
        }
        break;
    case 5:
        this->vfunc_96();
        break;
    }
}

void TObjEneDellBiter::fn_80304D10(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 2;
        this->set_field_378(5);
        flags &= ~1;
        flags |= 6;
        bodies->flags |= 0x700;
        vfunc_96();
        fade.reset_obstruction_fade();
        field_4dc = TObjEneDellBiter__movement_params->rush_speed;
        field_4d0 = 0;
        play_sound_effect(((TObjEnemy *)(this))->remap_sound_for_area((s32)((void *)0x40039E12)), &position, 0, 0);
        VecCopy(&position, &home_position);
        VecCopy(&prev_position, &position);
        VecCopy((Vec *)(&m_2fc), &position);
        position.x -= lbl_805DF010 * sin_table_lookup(rotation_y);
        position.z -= lbl_805DF010 * cos_table_lookup(rotation_y);
        state_timer = (s32)(lbl_805DF010 / TObjEneDellBiter__movement_params->rush_speed);
        field_488 = 0;
        field_48c = 0;
        this->set_active();
        break;
    case 3:
        if (field_4d0 == 2) {
            transition_enemy_state(5);
        }
        break;
    case 0:
        advance_animation();
        switch (field_4d0) {
        case 0:
            fn_8030591C();
            position.x = field_4dc * sin_table_lookup(rotation_y) + position.x;
            position.z = field_4dc * cos_table_lookup(rotation_y) + position.z;
            check_rush_collisions();
            state_timer--;
            if (state_timer <= 0) {
                field_4d0 = 1;
                state_timer = 0;
                flags &= ~4;
                this->set_field_378(5);
                play_sound_effect(((TObjEnemy *)(this))->remap_sound_for_area((s32)((void *)0x40039B14)), &position, 0, 0);
            }
            vfunc_102();
            break;
        case 1:
            state_timer++;
            if (state_timer >= 10) {
                this->requested_action = 3;
                fn_803058DC();
                if (this->get_flag_b4() != 0) {
                    field_4d0 = 2;
                }
                field_4dc *= lbl_805DF000;
            }
            check_rush_collisions();
            this->move_clamped_on_ground(target_direction.x, target_direction.z, field_4dc);
            break;
        }
        if (fade.advance_toward_max() != 0) {
            flags &= ~2;
            vfunc_89();
        }
        break;
    case 5:
        flags &= ~4;
        bodies->flags &= ~0x700;
        this->clear_field_388();
        break;
    }
}

void TObjEneDellBiter::fn_80304B88(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 0;
        this->set_field_378(4);
        flags = (s32) (flags & 0xFFFFFFF8);
        this->vfunc_95();
        state_timer = 0;
        field_4d0 = 0;
        break;
    case 3:
        if (state_timer == 2) {
            transition_enemy_state(5);
        } else if (state_timer == 3) {
            transition_enemy_state(1);
        }
        break;
    case 0:
        advance_animation();
        switch (state_timer) {
        case 0:
            if (update_linked_position(TObjEneDellBiter__data_805DF00C) != 0) {
                state_timer = 2;
            } else {
                field_4d0 = field_4d0 + 1;
                if (field_4d0 >= 0x3C) {
                    state_timer = 1;
                    fade.reset_color();
                    flags = (s32) (flags | 2);
                }
            }
            break;
        case 1:
            if (fade.decay_value_toward_floor() != 0) {
                state_timer = 3;
            }
            break;
        }
        this->vfunc_102();
        this->vfunc_89();
        break;
    case 5:
        break;
    }
}

void TObjEneDellBiter::fn_8030492C(s32 reason) {
    f32 temp_f31_2;
    s32 temp_r30;
    DelbiterMovementParameters *temp_r30_2;
    switch (reason) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(5);
        this->vfunc_96();
        flags = (s32) (flags & 0xFFFFFFF8);
        state_timer = 0;
        return;
    case 3:
        if ((u32) current_target == 0U) {
            transition_enemy_state(4);
        } else if ((target_distance >= TObjEneDellBiter__movement_params->rush_start_distance) && ((s32) field_48c < 2)) {
            transition_enemy_state(6);
        } else if ((s32) state_timer == 1) {
            transition_enemy_state(7);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation();
        if (validate_or_update_target() != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
        }
        rotation_y = approach_angle_limited((int) (rotation_y), temp_r30 = (s32) (TObjEneDellBiter__data_80475328 * atan2_float((f32) (target_direction.x), (f32) (target_direction.z))), 0x300);
        part_rotation_x = turn_toward_angle_limited__15TObjBoss2TunnelFlllll((int) (rotation_y), (int) (part_rotation_x), temp_r30, 0x200, 0x2000);
        temp_r30_2 = TObjEneDellBiter__movement_params;
        if (target_distance <= (f32) temp_r30_2->attack_distance) {
            temp_f31_2 = (target_direction.x * sin_table_lookup((int) (rotation_y))) + (target_direction.z * cos_table_lookup((int) (rotation_y)));
            if (temp_f31_2 >= cos_table_lookup(0x1800)) {
                state_timer = 1;
            }
        } else {
            this->move_clamped_on_ground(sin_table_lookup((int) (rotation_y)), cos_table_lookup((int) (rotation_y)), temp_r30_2->walk_speed);
        }
        this->vfunc_89();
        fn_80305684();
        if ((is_passing_frame(lbl_805DF004) != 0) || (is_passing_frame(lbl_805DF008) != 0)) {
            this->update_attack_effect();
        }
        break;
    }
}

void TObjEneDellBiter::fn_803044AC(s32 reason) {
    s32 hit;
    f32 t;
    switch (reason) {
    case 4:
        this->requested_action = 7;
        this->set_field_378(5);
        flags &= ~3;
        flags |= 4;
        state_timer = 0;
        field_4d0 = 0;
        field_4dc = TObjEneDellBiter__movement_params->rush_speed;
        field_4e0 = TObjEneDellBiter__data_805DEFF4;
        fill_value_array((s32)attack_history);
        this->set_active();
        break;
    case 3:
        if (state_timer == 3) {
            field_488 = 0;
            field_48c++;
            flags &= ~8;
            if (this->fn_803054A8() == 0 && this->fn_803054FC() == 0) {
                transition_enemy_state(5);
            }
        }
        break;
    case 0:
        advance_animation();
        switch (state_timer) {
        case 0:
            if (is_passing_frame((f32)lbl_805DEFF8) != 0 || is_passing_frame((f32)((f32)lbl_805DEFFC)) != 0) {
                play_sound_effect(((TObjEnemy *)(this))->remap_sound_for_area((s32)((void *)0x40039E12)), &position, 0, 0);
                this->spawn_front_particle();
            }
            if (this->get_flag_b4() != 0) {
                this->requested_action = 2;
                state_timer = 1;
                bodies->flags |= 0x700;
            }
            if (enemy_validate_retained_target(this) != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
            }
            rotation_y = approach_angle_limited(rotation_y, (s32)(TObjEneDellBiter__data_80475328 * atan2_float(target_direction.x, target_direction.z)), 0x280);
            part_rotation_x = turn_toward_angle_limited__15TObjBoss2TunnelFlllll(rotation_y, part_rotation_x, rotation_y, 0x200, 0x2000);
            this->vfunc_89();
            break;
        case 1:
            fn_8030591C();
            if (validate_or_update_target() != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
            }
            hit = 0;
            if (enemy_probe_wall_ahead__13TBoss5GryphonFfff(this, target_direction.x, target_direction.z, TObjEneDellBiter__data_805DEFE8 * TObjEneDellBiter__movement_params->rush_speed) != 0) {
                hit = 1;
            }
            this->move_clamped_on_ground(target_direction.x, target_direction.z, TObjEneDellBiter__movement_params->rush_speed);
            field_4e0 += TObjEneDellBiter__movement_params->rush_speed;
            if (this->has_move_failures(1) != 0) {
                hit = 1;
            }
            update_enemy_collision_flags();
            if (bodies->flags & 0x200000) {
                hit = 1;
            }
            if (check_rush_collisions() != 0) {
                hit = 1;
            }
            if (enemy_validate_retained_target(this) != 0) {
                Vec v;
                VecCopy(&v, &current_target->position);
                subtract_vector(&v, &position);
                if (normalize_vector_xz(&v) >= TObjEneDellBiter__data_805DEFE8) {
                    if (v.x * sin_table_lookup(rotation_y) + v.z * cos_table_lookup(rotation_y) < TObjEneDellBiter__data_805DEFF4) {
                        hit = 1;
                    }
                }
            }
            if (hit != 0 || field_4e0 >= TObjEneDellBiter__movement_params->rush_distance) {
                state_timer = 2;
                field_4d0 = 0;
                this->set_field_378(5);
                play_sound_effect(((TObjEnemy *)(this))->remap_sound_for_area((s32)((void *)0x40039B14)), &position, 0, 0);
            }
            break;
        case 2:
            field_4d0++;
            if (field_4d0 >= 10) {
                this->requested_action = 3;
                fn_803058DC();
                if (this->get_flag_b4() != 0) {
                    flags &= ~4;
                    state_timer = 3;
                }
                field_4dc *= lbl_805DF000;
            }
            check_rush_collisions();
            this->move_clamped_on_ground(target_direction.x, target_direction.z, field_4dc);
            break;
        }
        break;
    case 5:
        flags &= ~4;
        bodies->flags &= ~0x700;
        this->clear_field_388();
        break;
    }
}

#pragma fp_contract off

void TObjEneDellBiter::fn_803042B0(s32 reason) {
    s32 temp_r3;

    switch (reason) {
    case 4:
        this->requested_action = 4;
        this->set_field_378(5);
        flags = (s32) (flags & 0xFFFFFFFC);
        flags = (s32) (flags | 4);
        fill_value_array((int) ((s32)attack_history));
        saver->clear_segments();
        state_timer = 0;
        field_4d0 = 0;
        field_48c = 0;
        return;
    case 3:
        if ((s32) field_4d0 == 2) {
            field_488 = (s32) (field_488 + 1);
            if ((s32) field_488 >= 2) {
                field_488 = 0;
                flags = (s32) (flags & 0xFFFFFFF7);
            }
            if (this->fn_803054FC() == 0) {
                transition_enemy_state(5);
            }
        }
        break;
    case 0:
        advance_animation();
        temp_r3 = rotation_y;
        part_rotation_x = turn_toward_angle_limited__15TObjBoss2TunnelFlllll(temp_r3, (int) (part_rotation_x), temp_r3, 0x200, 0x2000);
        switch (field_4d0) {
        case 0:
            if (is_passing_frame(TObjEneDellBiter__data_805DEFE4) != 0) {
                this->spawn_front_particle();
            }
            update_contact_attacks();
            if (is_passing_frame(lbl_805DEFF0) != 0) {
                play_sound_effect((int) (((TObjEnemy *)(this))->remap_sound_for_area((s32)((void *) (0x40039E16)))), &position, 0, 0);
            }
            if (this->get_flag_b4() != 0) {
                this->requested_action = 0;
                field_4d0 = 1;
                state_timer = 0;
            }
            break;
        case 1:
            state_timer = (s32) (state_timer + 1);
            if ((s32) state_timer >= (s32) TObjEneDellBiter__movement_params->state_duration) {
                field_4d0 = 2;
            }
            break;
        }
        this->vfunc_102();
        this->vfunc_89();
        break;
    case 5:
        break;
    }
}

void TObjEneDellBiter::fn_803040D0(s32 reason) {
    Vec effect_position;
    f32 temp_f1;
    u32 temp_r3;
    switch (reason) {
    case 4:
        this->requested_action = 8;
        this->set_field_378(5);
        flags = (s32) (flags & 0xFFFFFFFC);
        flags = (s32) (flags | 4);
        state_timer = 0;
        return;
    case 3:
        if ((s32) state_timer == 1) {
            transition_enemy_state(5);
        }
        return;
    case 0:
        (advance_animation());
        if (this->get_flag_b4() != 0) {
            state_timer = 1;
        } else {
            if ((u32) effect != 0U) {
                if (is_passing_frame(lbl_805DEFEC) != 0) {
                    effect->queue_destruction();
                    effect = NULL;
                } else {
                    temp_f1 = this->frame;
                    if ((temp_f1 >= TObjEneDellBiter__data_805DEFD8) && (temp_f1 <= lbl_805DEFEC)) {
                        VecCopy(&effect_position, &position);
                        effect_position.y += TObjEneDellBiter__data_805DEFE0;
                        effect->set_position(&effect_position);
                    }
                }
            } else if (is_passing_frame(TObjEneDellBiter__data_805DEFD8) != 0) {
                effect = (TParticleCtrl *)create_particle_emitter((&position), 0x211);
            }
            if (is_passing_frame(TObjEneDellBiter__data_805DEFE4) != 0) {
                this->fn_80305688();
                play_sound_effect((int)((void *) (((TObjEnemy *)(this))->remap_sound_for_area((s32)((void *)(0x40039E15))))), &position, 0, 0);
            }
        }
        this->vfunc_102();
        this->vfunc_89();
        return;
    case 5:
        temp_r3 = (u32)effect;
        if (temp_r3 != 0U) {
            ((TObject *)temp_r3)->queue_destruction();
            effect = NULL;
        }
        break;
    }
}

void TObjEneDellBiter::fn_80303F04(s32 reason) {
    Vec sp8;

    switch (reason) {
    case 4:
        this->requested_action = 8;
        this->set_field_378(5);
        flags = (s32) (flags & 0xFFFFFFFC);
        flags = (s32) (flags | 4);
        state_timer = 0;
        return;
    case 3:
        if ((s32) state_timer == 1) {
            transition_enemy_state(5);
        }
    case 5:
        return;
    case 0:
        advance_animation();
        if (is_passing_frame(lbl_805DEFDC) != 0) {
            VecCopy(&sp8, &position);
            sp8.y += TObjEneDellBiter__data_805DEFE0;
            if ((s32) game_difficulty_selection == 3) {
                spawn_particle_effect(&sp8, 0x21D);
                spawn_particle_effect(&sp8, 0x21E);
            } else {
                spawn_particle_effect(&sp8, 0x21B);
                spawn_particle_effect(&sp8, 0x21C);
            }
        }
        if (is_passing_frame(TObjEneDellBiter__data_805DEFE4) != 0) {
            play_sound_effect(((TObjEnemy *)(this))->remap_sound_for_area((s32)((void *)0x40039E15)), &position, 0, 0);
        }
        if (this->get_flag_b4() != 0) {
            state_timer = 1;
            flags = (s32) (flags | 0x10);
            effect_timer = (s32) (TObjEneDellBiter__data_805DEFE8 * (f32) TObjEneDellBiter__movement_params->effect_duration);
        }
        this->vfunc_102();
        this->vfunc_89();
        break;
    }
}

void TObjEneDellBiter::fn_80303BC0(s32 reason) {
    f32 var_f31;
    s32 temp_r5;
    void *p;
    switch (reason) {
    case 4:
        this->requested_action = 1;
        this->set_field_378(5);
        flags = (s32) (flags & 0xFFFFFFFC);
        flags = (s32) (flags | 4);
        state_timer = 0;
        field_4d0 = 0;
        field_4d4 = 0;
        field_4d8 = 0;
        return;
    case 3:
        if ((s32) state_timer == 4) {
            transition_enemy_state(5);
        }
        return;
    case 0:
        advance_animation();
        switch (state_timer) {
        case 0:
            if (select_farthest_visible_player() != 0) {
                this->enemy_copy_target_destination();
                this->update_velocity();
                field_4d8 = (s32) (u16) (s32) (TObjEneDellBiter__data_80475328 * atan2_float((f32) (target_direction.x), (f32) (target_direction.z)));
                state_timer = 1;
            } else {
                state_timer = 4;
            }
            break;
        case 1:
            rotation_y = approach_angle_limited((int) (rotation_y), (int) (field_4d8), 0x300);
            if ((s32) (u16) rotation_y == (s32) field_4d8) {
                state_timer = 2;
                this->requested_action = 5;
            }
            fn_80305684();
            break;
        case 2:
            if (this->get_flag_b4() != 0) {
                if (TObjEneDD::check_v2_mode() != 0) {
                    field_4d0 = (s32) (field_4d0 + 1);
                    if ((s32) field_4d0 < 3) {
                        if (select_farthest_visible_player() != 0) {
                            this->enemy_copy_target_destination();
                            this->update_velocity();
                            field_4d8 = (s32) (u16) (s32) (TObjEneDellBiter__data_80475328 * atan2_float((f32) (target_direction.x), (f32) (target_direction.z)));
                            state_timer = 0;
                            this->requested_action = 1;
                        } else {
                            state_timer = 4;
                        }
                    } else {
                        state_timer = 4;
                    }
                } else {
                    state_timer = 4;
                }
            }
            if (is_passing_frame(lbl_805DEFCC) != 0) {
                temp_r5 = field_4d4;
                var_f31 = (f32) TObjEneDellBiter__movement_params->tp_attack_power;
                if (temp_r5 > 0x96) {
                    var_f31 *= lbl_805DEFD0;
                } else if (temp_r5 > 0x46) {
                    var_f31 *= lbl_805DEFD4;
                }
                new TObjEneDellBiter_Eff_TpAbsorb1(this, this, &part_positions[0], field_4d8, attack_history, var_f31);
                play_sound_effect(((TObjEnemy *)(this))->remap_sound_for_area((s32)((void *)0x40039F17)), &position, 0, 0);
            }
            if (is_passing_frame(TObjEneDellBiter__data_805DEFD8) != 0) {
                spawn_particle_effect(&part_positions[0], 0x21F);
            }
            break;
        }
        this->vfunc_102();
        this->vfunc_89();
        return;
    case 5:
        flags = (s32) (flags & 0xFFFFFFF7);
        break;
    }
}

void TObjEneDellBiter::fn_80303AA0(s32 reason) {
    Vec v;
    f32 len;
    switch (reason) {
    case 4:
        this->requested_action = 6;
        advance_animation();
        this->set_active();
        break;
    case 3:
        if (this->get_flag_b4() != 0 && this->check_low_hp_transition() == 0 &&
            this->fn_803054A8() == 0 && this->fn_803054FC() == 0) {
            transition_enemy_state(next_mode);
        }
        break;
    case 0:
        advance_animation();
        VecCopy(&v, (const Vec *)&x_speed);
        len = normalize_vector_xz(&v);
        this->move_clamped_on_ground(v.x, v.z, len);
        x_speed *= lbl_805DEFC8;
        m_310 *= lbl_805DEFC8;
        this->vfunc_89();
        break;
    case 5:
        this->clear_attack_receipts();
        this->clear_field_388();
        break;
    }
}

void TObjEneDellBiter::state_death(s32 reason) {
    switch (reason) {
    case 4:
        this->requested_action = 9;
        flags = (s32) (flags & 0xFFFFFFFC);
        flags = (s32) (flags | 2);
        this->vfunc_94();
        refresh_and_send_entity_flags();
        TObjPlayer__sub_800A04F0(&fade);
        if (get_current_floor_area() == AREA_TOWER) {
            play_sound_effect(0x4003A358, &position, 0, 0);
        } else {
            play_sound_effect((int)(((TObjEnemy *)(this))->remap_sound_for_area((s32)((void *)(0x4003A31A)))), &position, 0, 0);
        }
        state_timer = 0;
        return;
    case 3:
        if ((s32) state_timer == 2) {
            queue_destruction();
        }
        return;
    case 0:
        advance_animation();
        switch (state_timer) {
        case 0:
            if (this->get_flag_b4() != 0) {
                fn_800D911C((Vec *)(&m_2fc));
                play_sound_effect(0x4003A830, &m_2fc, 0, 0);
                state_timer = 1;
                return;
            }
            break;
        case 1:
            if (fade.decay_value_toward_floor() != 0) {
                TObjPlayer::apply_effect_variant_b((s32)(&position), 0);
                state_timer = 2;
                return;
            }
            break;
        default:
            state_timer = 2;
            return;
        }
        break;
    case 5:
        queue_destruction();
        break;
    }
}

void TObjEneDellBiter::step_demo_script() {
    s32 pos;
    switch (TObjEneDellBiter__demo_script_step) {
    case 9:
    case 10:
    case 11:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 21:
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
    case 28:
    case 29:
    case 30:
    case 31:
        break;
    case 8:
        rotate_matrix_x(0, TObjEneDellBiter__demo_rotate_x_angle);
        break;
    case 12:
    case 22:
    case 32:
        pos = TObjEneDellBiter__demo_script_cursor;
        TObjEneDellBiter__demo_script_cursor = pos + 0xC;
        get_camera_ctrl__9TObjEneDDFv(&dellbiter_demo_camera_vec, pos);
        break;
    }
    TObjEneDellBiter__demo_script_step += 1;
}

void TObjEneDellBiter::render() {
    s32 cam;
    s32 vis;
    RenderFadeState *camera_fade;
    s32 draw;
    s32 i;

    if (TObjPlayer::check_demo_mode() != 0) {
        vfunc_106();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = get_camera_mode__11TCameraCtrlFv();
    }
    if (flags & 1) {
        vis = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        if (get_current_floor_area() == AREA_TOWER) {
            vis = classify_actor_view_detail(600.0f, 600.0f, 15.0f);
        } else {
            vis = classify_actor_view_detail(lbl_805D9E88, lbl_805D9E84, 15.0f);
        }
    } else if (update_object_view_visibility(lbl_805DEFBC, 15.0f) != 0) {
        vis = 1;
    } else {
        vis = 0;
    }
    if (vis != 0) {
        if (render_model_if_visible() != 0) {
            return;
        }
        if (!(flags_3c4 & 0x4000)) {
            Vec v = lbl_80475294[0];
            update_player_state__9TObjEneDDFv(this, &v, 0);
        }
        update_secondary_light();
        TObjEneDellBiter__demo_script_step = 0;
        TObjEneDellBiter__demo_rotate_x_angle = part_rotation_x;
        TObjEneDellBiter__demo_script_cursor = (s32)(part_positions);
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        draw = 1;
        camera_fade = &camera_fades[cam];
        camera_fade->update();
        cam = camera_fade->updateFromCamera((const f32*)(&m_2fc));
        if (flags & 2) {
            fade.set_flags_and_apply_damage_color();
            if (defer_render__7TObjectFv(this) != 0) {
                draw = 0;
            }
        } else if (cam != 0) {
            camera_fade->set_flags_and_apply_damage_color();
            if (defer_render__7TObjectFv(this) != 0) {
                draw = 0;
            }
        }
        TObjFish::set_global_param(texlist);
        if (draw != 0) {
            push_matrix();
            post_translate_matrix(&position);
            rotate_matrix_y(0, rotation_y);
            scale_matrix(0, TObjEneDellBiter__data_805DEFB8, TObjEneDellBiter__data_805DEFB8, TObjEneDellBiter__data_805DEFB8);
            set_chunk_model_node_callback((s32)((void *)TObjEneDellBiter::step_demo_script));
            if (vis == 1) {
                this->draw();
            } else {
                draw_motion_model();
            }
            set_chunk_model_node_callback((s32)NULL);
            pop_matrix();
        }
        if (flags & 2) {
            fade.clear_flag_and_notify();
        } else if (cam != 0) {
            camera_fade->clear_flag_and_notify();
        }
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        update_primary_light();
    } else if (is_split_screen() == 0) {
        for (i = 0; i < 3; i++) {
            VecCopy(&part_positions[i], (const Vec *)(&m_2fc));
        }
    }
}

void TObjEneDellBiter::fn_80303538() { if (get_target_info() != 0) { this->init_target_offsets(); } }

void TObjEneDellBiter::vfunc_106() {
    if (this->get_target_info() != 0) {
        debug_printf_at(pack_debug_text_position(0, 2), lbl_804752AC);
        debug_printf_at(pack_debug_text_position(0, 3), lbl_804752BC);
        debug_printf_at(pack_debug_text_position(0, 4), lbl_804752D0);
        debug_printf_at(pack_debug_text_position(0, 5), lbl_804752E4);
        debug_printf_at(pack_debug_text_position(0, 6), lbl_804752F8);
        if ((s32) field_4bc == 1) {
            debug_printf_at(pack_debug_text_position(0, 9), lbl_8047530C);
        } else {
            debug_printf_at(pack_debug_text_position(0, 9), lbl_80475318);
        }
    }
    if (update_object_view_visibility(lbl_805DEFBC, 15.0f) != 0) {
        Vec v = lbl_804752A0[0];
        update_player_state__9TObjEneDDFv(this, &v, 0);
        TObjPlayer::toggle_particle_effect();
        TObjFish::set_global_param((int) (texlist));
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, (int) (rotation_y));
        scale_matrix(0, TObjEneDellBiter__data_805DEFB8, TObjEneDellBiter__data_805DEFB8, TObjEneDellBiter__data_805DEFB8);
        set_motion_packed_rotation();
        draw_chunk_object((void *)(model));
        clear_motion_packed_rotation();
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

s32 TObjEneDellBiter::render_model_if_visible() {
    if (get_mode__11TCameraCtrlFPv(((s32 *)&main_task)) & 0x20) {
        if (push_reflection_matrix(&reflection_position) != 0) {
            TObjFish::set_global_param(texlist);
            push_matrix();
            post_translate_matrix(&position);
            rotate_matrix_y(0, rotation_y);
            scale_matrix(0, TObjEneDellBiter__data_805DEFB8, TObjEneDellBiter__data_805DEFB8, TObjEneDellBiter__data_805DEFB8);
            this->draw();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}
