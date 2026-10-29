#include "pso/enemy/DelDepthData.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/animation/ActorAnimationState.h"
#include "types.h"
#include "pso/map/CsnQuery.h"
#include "pso/TObjControl.h"
#include "pso/render/reflection.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneDelDepthBomb.h"
#include "pso/enemy/TObjEneDelDepth.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneLappy.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TTecBarta.h"
#include "pso/misc/TTecMegid.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_803E2D70.h"

extern "C" {
f64 atan2_float(f32, f32);

s32 angle_difference_abs(s32, s32);
s32 approach_angle_limited(s32, s32, s32);
s32 project_actor_to_ground(void *, void *, void *);
f32 vec3_add_to(void *, void *);
f32 vector_length(void *);
s32 normalize_vector(void *);
extern const f64 TObjEneDelDepth__data_80475DD0;
extern const f32 TObjEneDelDepth__data_805DF280;
extern const f32 lbl_805DF288;
extern const f32 lbl_805DF28C;
extern const f32 lbl_805DF290;
void submit_cursor_candidate(void *, s32);
void minimap_render_dot(void *, s32, s32, s32);
f32 cos_table_lookup(s32);
f32 sin_table_lookup(s32);
f32 fabs_float(f32);
s32 play_sound_effect(int, void *, int, int);
u16 find_nearest_visible_player(void *, int, f32);

TObjChara *get_battle_param__10TObjPlayerFi(s32);
s32 obj_is_hit_receivable(void *);
s32 get_entity_id(void *);
s32 is_player_entity_id(s32);

extern CollisionBody TObjEneDelDepth_collision_body_parts[];
extern s32 actor_frame_tick;
extern const f32 TObjEneDelDepth__data_805DF268;
extern const f32 TObjEneDelDepth__data_805DF270;
extern const f32 TObjEneDelDepth__data_805DF298;
extern const f32 lbl_805DF2A4;
extern const f32 lbl_805DF2A8;
extern const f32 lbl_805DF2AC;
u8 *get_bml_motion(s32, s32);

extern const f32 lbl_805DF29C;
extern const f32 lbl_805DF294;

s32 TObjFish__sub_8001EDB0(u8 *, int);

s32 get_mode__11TCameraCtrlFPv(void *);
void draw_blob_shadow(s32 arg0);
s32 refresh_lobby_state__10TObjPlayerFv();
s32 free_collision_body_parts(void *);
s32 init_collision_body_parts(void *, void *, int);
void create__11TTecRaBartaFPvPvPvPv(void *source, void *origin, void *pos, void *level);
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
void restore_render_scissor(s32 arg0);
extern "C" {
s32 matrix_mult_vec(int, void *, void *);
void rotate_matrix_zyx(void *m, s32 x, s32 y, s32 z);
void scale_matrix_vec3(u8 *arg0, u8 *arg1);
s32 rotate_matrix_y(int, s32);
s32 rotate_matrix_z(int, int);
void translate_matrix(u32 arg0, f32 x, f32 y, f32 z);
s32 rotate_matrix_x(int, void *);
s32 push_matrix_from(void *);
s32 push_matrix();
s32 pop_matrix();
s32 scale_current_matrix(void *, f32, f32, f32);
s32 post_translate_matrix(void *);
void draw_chunk_object(void *child);

extern const f32 TObjEneDelDepth__data_805DF26C;
extern const float TObjEneDelDepth__data_805DF278;

extern const Vec lbl_80475D6C;
extern const Vec lbl_80475D78;
extern Vec lbl_80475DA4[];
extern Vec lbl_80475DB0;
extern TObjMotionAction lbl_804E8194[];

extern s32 identity_matrix[];
extern const char *TObjEneDelDepth__name;
extern const char *TObjEneDelDepthBomb__name;
extern s32 game_difficulty_selection;
extern s32 anim_model_matrix_array;
extern const f32 lbl_805DF264;
extern const f32 lbl_805DF274;
extern const f32 lbl_805DF27C;
extern const f32 lbl_805DF284;
extern const f32 lbl_805DF2A0;
extern const f32 lbl_805DF2B0;
extern const f32 lbl_805DF2B4;
extern const f32 lbl_805DF2B8;
extern const f32 lbl_805DF2BC;
extern const f32 lbl_805DF2C0;
extern const f32 lbl_805DF2C4;
extern const f32 lbl_805DF2C8;
extern const f32 lbl_805DF2CC;
extern const f32 lbl_805DF2D0;
extern s32 lbl_805DF2D4;
extern const f32 lbl_805DF2D8;
extern const f32 lbl_805DF2DC;

extern "C" {
s32 is_split_screen(void);
s32 dispatch_shared_handler_a__6TLobbyFl(s32);
BmlResource *load_resource_from_descriptor(BmlResource *, s32, const BmlResourceDescriptor *, s32, s32, s32);

void TLobby__sub_8001FE7C(void*, int);

extern "C" const char lbl_80475BD8[];
extern "C" const char lbl_80475BE8[];
extern "C" const char lbl_80475BF8[];
extern "C" const char lbl_80475C08[];
extern "C" const char lbl_80475C20[];
extern "C" const char lbl_80475C38[];
extern "C" const char lbl_80475C50[];
extern "C" const char lbl_80475C64[];
extern "C" const char lbl_80475C78[];
extern "C" const char lbl_80475C90[];
extern "C" const char lbl_80475CA8[];
extern "C" const char lbl_80475CC0[];
extern "C" const char lbl_80475CD8[];
extern "C" const char lbl_80475CF0[];
extern "C" const char lbl_80475D04[];
extern "C" const char lbl_80475D18[];
extern "C" const char lbl_80475D30[];
extern "C" const char lbl_80475D40[];
extern const char *lbl_804E80C0[4];
extern const char *TObjEneDelDepth_motion_file_list[13];
extern const char *lbl_804E8114[4];
extern const char *TObjEneDelDepth_motion_names[13];
const char *lbl_804E80C0[4] = {
    lbl_80475BD8, lbl_80475BE8, lbl_80475BF8, NULL,
};
const char *TObjEneDelDepth_motion_file_list[13] = {
    lbl_80475C08, lbl_80475C20, lbl_80475C38, lbl_80475C50,
    lbl_80475C64, lbl_80475C78, lbl_80475C90, lbl_80475CA8,
    lbl_80475CC0, lbl_80475CD8, lbl_80475CF0, lbl_80475D04,
    NULL,
};
BmlResourceDescriptor lbl_804E8104 = {
    lbl_80475D18, lbl_804E80C0, TObjEneDelDepth_motion_file_list, 3, 12
};
const char *lbl_804E8114[4] = {
    lbl_80475D30, lbl_80475BE8, lbl_80475BF8, NULL,
};
const char *TObjEneDelDepth_motion_names[13] = {
    lbl_80475C08, lbl_80475C20, lbl_80475C38, lbl_80475C50,
    lbl_80475C64, lbl_80475C78, lbl_80475C90, lbl_80475CA8,
    lbl_80475CC0, lbl_80475CD8, lbl_80475CF0, lbl_80475D04,
    NULL,
};
BmlResourceDescriptor lbl_804E8158 = {
    lbl_80475D40, lbl_804E8114, TObjEneDelDepth_motion_names, 3, 12
};
CollisionBody TObjEneDelDepth_collision_body_parts[] = {
    {{0.0f, 15.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f}
};
TObjMotionAction lbl_804E8194[] = {
    {1, 0, 11, 0.5f, 0},
    {2, 0, 5, 0.8f, 0},
    {3, 0, 6, 0.8f, 0},
    {3, 0, 11, 0.5f, 0},
    {3, 0, 9, 0.8f, 0},
    {3, 0, 10, 0.7f, 0}
};
TObjMotionAction lbl_804E81F4[] = {{1, 0, 0xB, 0.5f, 0}};

}

TObjEneDelDepth::ActionPair deldepth_actions[] = {
    { &TObjEneDelDepth::init_params, &TObjEneDelDepth::try_relocate_on_timer },
    { &TObjEneDelDepth::init_draw_params, &TObjEneDelDepth::fn_80314EC4 },
    { &TObjEneDelDepth::init_draw_mode_and_motion, &TObjEneDelDepth::update_scale_pulse },
    { &TObjEneDelDepth::start_move_toward_player, &TObjEneDelDepth::update_movement },
    { &TObjEneDelDepth::enter_state8, &TObjEneDelDepth::update_state },
    { &TObjEneDelDepth::enter_appear_state, &TObjEneDelDepth::try_enter_appear },
    { &TObjEneDelDepth::fn_80314500, &TObjEneDelDepth::fn_803142DC },
    { &TObjEneDelDepth::init_depth, &TObjEneDelDepth::fn_803141A8 },
    { &TObjEneDelDepth::setup_depth_draw, &TObjEneDelDepth::move_toward_target },
    { &TObjEneDelDepth::enter_attack_cast, &TObjEneDelDepth::update_attack_cast },
    { &TObjEneDelDepth::init_draw_state, &TObjEneDelDepth::update_bomb_drop },
    { &TObjEneDelDepth::init_state, &TObjEneDelDepth::update_state_flag },
    { &TObjEneDelDepth::start_attack_motion, &TObjEneDelDepth::update_ai_state },
    { &TObjEneDelDepth::init_move, &TObjEneDelDepth::update_death_fade },
    { &TObjEneDelDepth::enter_fall_to_ground, &TObjEneDelDepth::update_fall_to_ground },
};

}

extern "C" {

extern s32 tl_04;

}

extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;
extern const f32 lbl_805DF2E0;

extern "C" {
extern const f32 lbl_805DF250;
extern const f32 lbl_805DF254;
extern const f32 TObjEneDelDepth__data_805DF258;
extern const f32 lbl_805DF25C;
extern const f32 TObjEneDelDepth__data_805DF260;
extern const f32 lbl_805DF264;
}
void TObjEneDelDepth::setup_draw_material(f32 farg0, f32 farg1, f32 farg2, f32 farg3) {
    NJS_ARGB color;
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= 0x8820;
    set_chunk_material_override_pair(0xFF00, 0x800);
    set_chunk_blend(0x2100);
    color.r = farg1;
    color.g = farg2;
    color.a = lbl_805DF2E0 + farg0;
    color.b = farg3;
    set_constant_material(&color);
}

void TObjEneDelDepth::setup_draw_material_default(f32 farg0) {
    TObjEneDelDepth::setup_draw_material(farg0, TObjEneDelDepth__data_805DF258, TObjEneDelDepth__data_805DF258, TObjEneDelDepth__data_805DF258);
}

void TObjEneDelDepth::reset_globals() {
    model_render_flags &= 0xFFFF77DF;
    set_chunk_material_override_pair(0xFF00, 0);
    set_chunk_blend(0x2500);
    set_chunk_blend(0x2500);
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
}

TObjEneDelDepth *TObjEneDelDepth::create(void *setData) {
    return new TObjEneDelDepth(new TObjControl((TObject *)tl_04), setData);
}

void TObjEneDelDepth::load_assets() {

    if (is_split_screen() != 0) {
        BmlResource *p = (BmlResource *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, &lbl_804E8158, 0, 0, 0);
        }
        TObjEneDelDepth__shared_resource = p;
    } else {
        BmlResource *p = (BmlResource *)::operator new(0x440);
        if (p != NULL) {
            p = load_resource_from_descriptor(p, 1, &lbl_804E8104, 0, 0, 0);
        }
        TObjEneDelDepth__shared_resource = p;
    }

    {
        DelDepthAnimationBinding info = deldepth_anim_binding;
        info.motions = TObjEneDelDepth__shared_resource->motions;
        TLobby::spawn_npc_enemy((s16)0x47, TObjEneDelDepth__shared_resource->models[0].model, TObjEneDelDepth__shared_resource->models[0].m_c, (s32)&info, TObjEneDelDepth_collision_body_parts[0].radius, (f32)TObjEneDelDepth__data_805DF258);
    }
    {
        DelDepthAnimationBinding info = deldepth_anim_binding_b;
        info.motions = TObjEneDelDepth__shared_resource->motions;
        TLobby::spawn_npc_enemy((s16)0x48, TObjEneDelDepth__shared_resource->models[1].model, TObjEneDelDepth__shared_resource->models[1].m_c, (s32)&info, TObjEneDelDepth_collision_body_parts[0].radius, (f32)TObjEneDelDepth__data_805DF258);
    }
    TObjEneDelDepth__tune_params = (DelDepthParameters *)dispatch_shared_handler_a__6TLobbyFl(0x30);
}

void TObjEneDelDepth::free_shared_data() {
    if ((u32) TObjEneDelDepth__shared_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TObjEneDelDepth__shared_resource, 1);
        TObjEneDelDepth__shared_resource = NULL;
    }
}

TObjEneDelDepth::TObjEneDelDepth(TObject *parent, void *setData) : TObjEnemy(parent) {
    m_name = TObjEneDelDepth__name;
    add_flags_2e4(8);
    apply_set_data(setData);
    update_target_depth();
    init();
    project_actor_to_ground(this, &position, NULL);
    set_action_state(0);
}

void TObjEneDelDepth::init() {
    u8 *arg0 = (u8 *)this;
    DelDepthMotion *var_r0;
    this->texlist = TObjFish__sub_8001EDB0((u8 *)(TObjEneDelDepth__shared_resource = TObjEneDelDepth::get_data()), 0);
    this->model = (void *)get_bml_model(TObjEneDelDepth__shared_resource, 0);
    VecCopy(&this->prev_position, (const Vec *)(VecCopy(&this->home_position, (const Vec *)(VecCopy(&this->center, &this->position)))));
    this->collisionBody = (CollisionBody *)init_collision_body_parts(arg0, TObjEneDelDepth_collision_body_parts, 1);
    ((TObjMotion *)arg0)->set_field_d8((s32)lbl_804E8194);
    ((TObjMotion *)arg0)->set_field_dc((int) (TObjEneDelDepth__shared_resource->motions));
    ((TObjMotion *)arg0)->set_animation(0);
    ((TObjMotion *)arg0)->set_field_b8(0);
    VecCopy((Vec *)((u8 *)&this->m_2fc), &this->position);
    this->m_310 = (f32) TObjEneDelDepth__data_805DF258;
    this->y_speed = (f32) TObjEneDelDepth__data_805DF258;
    x_speed = (f32) TObjEneDelDepth__data_805DF258;
    this->target = 0;
    ((TObjEnemy *)arg0)->bind_enemy_combat_stats((u8 *)(TLobby::register_boss(0x30)), (u8 *)(TLobby::dispatch_shared_handler_b(0x30)), (u8 *)(TLobby::register_object(0x30)));
    this->referenceHp = (s16) this->hp;
    ((TBoss3Volopt *)arg0)->reset_photon_effect();
    this->movementParameters = 0;
    ((TObjEnemy *)arg0)->set_param(0x47);
    var_r0 = new DelDepthMotion(this);
    this->motionController = var_r0;
    this->targetPlayer = 0xFFFF;
    this->groundFlags = 0;
    VecCopy(&this->groundPoint, &this->position);
    this->clear_lobby_object_state();
}

#pragma push
#pragma opt_common_subs off
void TObjEneDelDepth::update_target_depth() {
    this->bombSpeed = (f32) (lbl_805DF2DC + this->parameters[0]);
    if (this->bombSpeed < TObjEneDelDepth__data_805DF258) {
        this->bombSpeed = (f32) TObjEneDelDepth__data_805DF258;
    }
}
#pragma pop

TObjEneDelDepth::~TObjEneDelDepth() {
    free_collision_body_parts(this);
    collisionBody = NULL;
    delete motionController;
    motionController = 0;
}

void TObjEneDelDepth::run_task() {
    TObjEneDelDepth *o = this;
    TObjEneDelDepth::Action fn;
    if (TObjPlayer::check_demo_mode() != 0) {
        update_target_depth();
        return;
    }
    this->sub_803152C0();
    fn = deldepth_actions[action].update;
    (void)(fn != NULL);
    (this->*fn)();
    ((TObjEnemy *)o)->update_prev_position();
    ((TObjPlayer *)o)->update_collisions();
    if (this->targetable != 0) {
        submit_cursor_candidate(o, -1);
    }
    motionController->update_animation_frame();
    this->sub_803152A0();
    if (this->action != 0xD) {
        minimap_render_dot(&o->m_2fc, -0x5DB4, 1, 0);
    }
    update_ground_check();
}

void TObjEneDelDepth::render() {
    TObjEneDelDepth *o = this;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->fn_80315518();
        return;
    }
    if (o->opacity <= TObjEneDelDepth__data_805DF258) {
        return;
    }
    if (o->update_object_view_visibility(lbl_805DF294, lbl_805DF2D8) == 0) {
        return;
    }
    if (draw_if_visible() != 0) {
        return;
    }
    if (o->opacity < TObjEneDelDepth__data_805DF260) {
        setup_draw_material_default(o->opacity);
    }
    TObjPlayer::toggle_particle_effect();
    push_matrix();
    Vec v = o->position;
    v.y += o->drawOffsetY;
    post_translate_matrix(&v);
    rotate_matrix_y(0, o->rotation_y);
    scale_matrix_vec3(0, (u8 *)&o->drawScale);
    o->motionController->draw_model_part();
    pop_matrix();
    TParticleCtrl::end_effect_render();
    if (o->opacity < TObjEneDelDepth__data_805DF260) {
        TObjEneDelDepth::reset_globals();
    }
    if (!(o->groundFlags & 0x4000)) {
        Vec s = lbl_80475DA4[0];
        ((TObjEnemy *)o)->render_with_position_override((u8 *)&s, 0);
    }
}

s32 TObjEneDelDepth::draw_if_visible() {
    TObjEneDelDepth *o = this;
    if (get_mode__11TCameraCtrlFPv(((u8 *)&main_task)) & 0x20) {
        if (push_reflection_matrix((Vec *)(&o->groundPoint)) != 0) {
            push_matrix();
            Vec v = o->position;
            v.y += o->drawOffsetY;
            post_translate_matrix(&v);
            rotate_matrix_y(0, o->rotation_y);
            scale_matrix_vec3(0, (u8 *)&o->drawScale);
            o->motionController->draw_model_part();
            pop_matrix();
            restore_render_scissor(1);
        }
        return 1;
    }
    return 0;
}

void TObjEneDelDepth::fn_80315518() {  }

void TObjEneDelDepth::set_action_state(s32 i) {
    TObjEneDelDepth::Action fn;
    action = i;
    fn = deldepth_actions[action].enter;
    (void)(fn != NULL);
    (this->*fn)();
}

void TObjEneDelDepth::set_depth_offset(s32 minimum, s32 range) {
    timer = minimum + (s32)((f32)range * random_ratio());
}

#pragma push
#pragma fp_contract on
s32 TObjEneDelDepth::adjust_height_to_ground() {
    TObjEneDelDepth *arg0 = this;
    Vec v = arg0->position;
    v.x = TObjEneDelDepth__data_805DF270 * cos_table_lookup(arg0->rotation_y) + v.x;
    v.y = v.y + TObjEneDelDepth__data_805DF268;
    v.x = TObjEneDelDepth__data_805DF270 * sin_table_lookup(arg0->rotation_y) + v.x;
    if (project_actor_to_ground(arg0, &v, NULL) != 0) {
        arg0->position.y += TObjEneDelDepth__data_805DF298 * (v.y - arg0->position.y);
        return 1;
    }
    return 0;
}
#pragma pop

void TObjEneDelDepth::set_draw_mode(s32 mode) {
    collisionBody->flags &= 0xF5FFF297;
    switch (mode) {
    case 0:
        collisionBody->flags |= 0x0A000000 | 0x528;
        targetable = 0;
        return;
    case 1:
        collisionBody->flags |= 0x0A000000 | 0x28;
        targetable = 0;
        return;
    case 2:
        targetable = 1;
        return;
    case 3:
        collisionBody->flags |= lbl_805DF2D4;
        targetable = 1;
        return;
    }
}

void TObjEneDelDepth::sub_803152C0() {
    CollisionBody *temp_r3;
    temp_r3 = this->collisionBody;
    temp_r3->flags = (s32) (temp_r3->flags | 1);
}

void TObjEneDelDepth::sub_803152A0() {
    CollisionBody *temp_r3;
    if ((s32) this->targetable == 0) {
        temp_r3 = this->collisionBody;
        temp_r3->flags = (s32) (temp_r3->flags & 0xFFFFFFFE);
    }
}

void TObjEneDelDepth::vfunc_63() { if (this->action != 13) { set_action_state(13); } }

void TObjEneDelDepth::vfunc_62() {
    if ((s32) this->action != 0xC) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFDFF);
        this->set_action_state(0xC);
    }
}

void TObjEneDelDepth::vfunc_61() {
    if ((s32) this->action != 0xB) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFEFF);
        this->set_action_state(0xB);
    }
}

void TObjEneDelDepth::set_default_depth_offset() { set_depth_offset(15, 15); }

void TObjEneDelDepth::init_params() {
    this->adjust_height_to_ground();
    this->drawOffsetY = TObjEneDelDepth__data_805DF278;
    this->drawScale.z = TObjEneDelDepth__data_805DF258;
    this->drawScale.y = TObjEneDelDepth__data_805DF258;
    this->drawScale.x = TObjEneDelDepth__data_805DF258;
    this->opacity = TObjEneDelDepth__data_805DF258;
    this->relocationAttempts = 0;
    this->motionController->set_motion(6);
    this->set_draw_mode(0);
    this->actorFlags = (this->actorFlags | 0x4040000);
    set_default_depth_offset();
}

void TObjEneDelDepth::try_relocate_on_timer() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r0_2;

    temp_r0 = this->timer - 1;
    this->timer = temp_r0;
    if (temp_r0 <= 0) {
        if (find_nearest_visible_player(arg0, 0, TObjEneDelDepth__data_805DF26C) == 0xFFFF) {
            temp_r0_2 = this->relocationAttempts + 1;
            this->relocationAttempts = temp_r0_2;
            if (temp_r0_2 >= 5) {
                this->position.x = (f32) this->home_position.x;
                this->position.z = (f32) this->home_position.z;
                this->relocationAttempts = 5;
            }
            set_default_depth_offset();
            return;
        }
        ((TBoss3Volopt *)((u8 *)&this->position))->play_area_se_with_particle();
        this->set_action_state(1);
    }
}

void TObjEneDelDepth::init_draw_params() {
    this->set_draw_mode(0);
    this->actorFlags = (s32) (this->actorFlags & 0xFBFBFFFF);
    this->m_38c = (f32) TObjEneDelDepth__data_805DF258;
    this->drawOffsetY = (f32) TObjEneDelDepth__data_805DF278;
}

#pragma push
#pragma fp_contract on
void TObjEneDelDepth::fn_80314EC4() {
    TObjEneDelDepth *ene_del_depth = this;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 var_f31;
    var_f31 = TObjEneDelDepth__data_805DF260;
    ene_del_depth->drawOffsetY = (f32) (TObjEneDelDepth__data_805DF278 * (TObjEneDelDepth__data_805DF260 - ene_del_depth->m_38c));
    ene_del_depth->drawScale.x = (f32) ((ene_del_depth->m_38c * (lbl_80475D78.x - lbl_80475D6C.x)) + lbl_80475D6C.x);
    ene_del_depth->drawScale.y = (f32) ((ene_del_depth->m_38c * (lbl_80475D78.y - lbl_80475D6C.y)) + lbl_80475D6C.y);
    ene_del_depth->drawScale.z = (f32) ((ene_del_depth->m_38c * (lbl_80475D78.z - lbl_80475D6C.z)) + lbl_80475D6C.z);
    temp_f1 = ene_del_depth->m_38c;
    if (temp_f1 > lbl_805DF2C0) {
        var_f31 = (TObjEneDelDepth__data_805DF260 - temp_f1) / lbl_805DF2BC;
    }
    temp_f1_2 = var_f31 * (lbl_805DF250 * sin_table_lookup(ene_del_depth->timer << 0xC));
    ene_del_depth->drawScale.x = (f32) (ene_del_depth->drawScale.x * (TObjEneDelDepth__data_805DF260 + temp_f1_2));
    ene_del_depth->drawScale.z = (f32) (ene_del_depth->drawScale.z * (TObjEneDelDepth__data_805DF260 - temp_f1_2));
    ene_del_depth->timer = (s32) (ene_del_depth->timer + 1);
    temp_f1_3 = ene_del_depth->m_38c;
    if (temp_f1_3 >= TObjEneDelDepth__data_805DF298) {
        ene_del_depth->opacity = (f32) TObjEneDelDepth__data_805DF260;
    } else {
        ene_del_depth->opacity = (f32) (lbl_805DF2C8 * temp_f1_3);
    }
    temp_f1_4 = ene_del_depth->m_38c + lbl_805DF2D0;
    ene_del_depth->m_38c = temp_f1_4;
    if (temp_f1_4 > TObjEneDelDepth__data_805DF260) {
        if (find_nearest_visible_player(ene_del_depth, 0, TObjEneDelDepth__data_805DF26C) != 0xFFFF) {
            ene_del_depth->set_action_state(3);
            play_sound_effect(0x4003A822, (u8 *)&ene_del_depth->position, 0, 0);
        } else {
            ene_del_depth->set_action_state(2);
        }
    }
}
#pragma pop

void TObjEneDelDepth::init_draw_mode_and_motion() {
    this->m_38c = TObjEneDelDepth__data_805DF260;
    this->drawOffsetY = TObjEneDelDepth__data_805DF258;
    this->set_draw_mode(0);
    this->motionController->set_motion(0x6);
}

#pragma push
#pragma fp_contract on
void TObjEneDelDepth::update_scale_pulse() {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f1_4;
    f32 var_f31;
    var_f31 = TObjEneDelDepth__data_805DF260;
    this->drawOffsetY = (f32) (TObjEneDelDepth__data_805DF278 * (TObjEneDelDepth__data_805DF260 - this->m_38c));
    this->drawScale.x = (f32) ((this->m_38c * (lbl_80475D78.x - lbl_80475D6C.x)) + lbl_80475D6C.x);
    this->drawScale.y = (f32) ((this->m_38c * (lbl_80475D78.y - lbl_80475D6C.y)) + lbl_80475D6C.y);
    this->drawScale.z = (f32) ((this->m_38c * (lbl_80475D78.z - lbl_80475D6C.z)) + lbl_80475D6C.z);
    temp_f1 = this->m_38c;
    if (temp_f1 > lbl_805DF2C0) {
        var_f31 = (TObjEneDelDepth__data_805DF260 - temp_f1) / lbl_805DF2BC;
    }
    temp_f1_2 = var_f31 * (lbl_805DF2C4 * sin_table_lookup(this->timer << 0xA));
    this->drawScale.x = (f32) (this->drawScale.x * (TObjEneDelDepth__data_805DF260 + temp_f1_2));
    this->drawScale.z = (f32) (this->drawScale.z * (TObjEneDelDepth__data_805DF260 - temp_f1_2));
    this->timer = (this->timer + 1);
    temp_f1_3 = this->m_38c;
    if (temp_f1_3 >= TObjEneDelDepth__data_805DF298) {
        this->opacity = (f32) TObjEneDelDepth__data_805DF260;
    } else {
        this->opacity = (f32) (lbl_805DF2C8 * temp_f1_3);
    }
    temp_f1_4 = this->m_38c + lbl_805DF2CC;
    this->m_38c = temp_f1_4;
    if (temp_f1_4 < TObjEneDelDepth__data_805DF258) {
        this->set_action_state(0);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneDelDepth::start_move_toward_player() {
    f32 temp_f1;
    s32 temp_r31;
    u8 *actor = (u8 *)this;
    this->movementSpeed = TObjEneDelDepth__data_805DF258;
    if (find_nearest_visible_player(actor, (int)((u8 *)&this->direction), TObjEneDelDepth__data_805DF26C) == 0xFFFF) {
        this->set_action_state(2);
        return;
    }
    temp_r31 = (s32) (lbl_805DF2B0 * random_ratio());
    this->direction.x += TObjEneDelDepth__data_805DF270 * sin_table_lookup(temp_r31);
    this->direction.z += TObjEneDelDepth__data_805DF270 * cos_table_lookup(temp_r31);
    if (vector_length((u8 *)&this->direction.x) <= lbl_805DF288) {
        this->set_action_state(2);
        return;
    }
    normalize_vector((u8 *)&this->direction.x);
    temp_f1 = (lbl_805DF2B8 * random_ratio()) + lbl_805DF2B4;
    this->m_38c = temp_f1;
    this->opacity = TObjEneDelDepth__data_805DF260;
    this->motionController->set_motion(7);
    this->set_draw_mode((s32)((void *)3));
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneDelDepth::update_movement() {
    TObjEneDelDepth *arg0 = this;
    Vec p;
    Vec n;
    s32 i;
    TObjChara *pl;
    s32 k;
    s32 ang;
    s32 rot;
    if ((actor_frame_tick % 5) == 0) {
        TObjPlayer::init_all_slots();
        ((TObjPlayer *)arg0)->check_object_collisions();
        for (i = 0; i < 16; i++) {
            pl = get_battle_param__10TObjPlayerFi(i);
            if (pl == 0) {
                break;
            }
            if (obj_is_hit_receivable(pl) != 0 && is_player_entity_id(get_entity_id(pl)) != 0) {
                pl->select_melee_contact_body(arg0, TObjEneDelDepth__data_805DF260);
                pl->receive_physical_attack(arg0, TObjEneDelDepth__data_805DF260);
                pl->apply_knockback_from_attacker((u8 *)arg0, TObjEneDelDepth__data_805DF268);
            }
        }
    }
    if (this->m_38c > TObjEneDelDepth__data_805DF258) {
        this->m_394 += 0xC00;
        f32 t = sin_table_lookup(this->m_394);
        f32 u = TObjEneDelDepth__data_805DF298 * (TObjEneDelDepth__data_805DF298 + t);
        u = TObjEneDelDepth__tune_params->accel * u;
        if ((arg0->movementSpeed += u) > TObjEneDelDepth__tune_params->maxSpeed) {
            arg0->movementSpeed = TObjEneDelDepth__tune_params->maxSpeed;
        }
    } else {
        if ((arg0->movementSpeed -= TObjEneDelDepth__tune_params->accel) < TObjEneDelDepth__data_805DF258) {
            arg0->movementSpeed = TObjEneDelDepth__data_805DF258;
        }
    }
    this->m_38c -= fabs_float(arg0->movementSpeed);
    VecCopy((Vec *)&arg0->prev_position, (const Vec *)&arg0->position);
    for (k = 1; k < 15; k++) {
        f32 s;
        f32 c;
        f32 d;
        arg0->position.x += arg0->movementSpeed * arg0->direction.x;
        arg0->position.z += arg0->movementSpeed * arg0->direction.z;
        VecCopy((Vec *)&p, (const Vec *)&arg0->position);
        VecCopy((Vec *)&n, (const Vec *)&arg0->direction);
        normalize_vector(&n);
        d = lbl_805DF2A4 * TObjEneDelDepth_collision_body_parts[0].radius;
        p.x += d * n.x;
        p.z += d * n.z;
        if (this->adjust_height_to_ground() != 0) {
            CsnHit *hit;
            ang = 0;
            hit = csnVector(&arg0->prev_position, &p, 0x88E0);
            if (hit != 0) {
                Vec w;
                VecCopy((Vec *)&p, (const Vec *)&arg0->position);
                w.x = hit->contact->normal.z;
                w.z = -hit->contact->normal.x;
                normalize_vector_xz((Vec *)(&w));
                if (n.x * w.x + n.z * w.z >= TObjEneDelDepth__data_805DF258) {
                    n.x = w.x;
                    n.z = w.z;
                } else {
                    n.x = -w.x;
                    n.z = -w.z;
                }
                d = lbl_805DF2A8 * TObjEneDelDepth_collision_body_parts[0].radius;
                p.x += d * n.x;
                p.z += d * n.z;
                this->m_394 = (s32)(TObjEneDelDepth__data_80475DD0 * atan2_float(n.x, n.z));
                if (csnVector(&arg0->prev_position, &p, 0x88E0) == 0) {
                    ang = 1;
                }
            } else {
                ang = 1;
            }
            if (ang == 1) {
                CsnHit *u;
                p.y += lbl_805DF2AC;
                u = (CsnHit *)csnVectorUnder(&p, (u32 *)&arg0->m_120, 0x16EF);
                if (u != 0 && (u->contact->flags & 0xE0) == 0) {
                    break;
                }
            }
        }
        rot = k << 12;
        if (k & 1) {
            rot *= -1;
        }
        s = sin_table_lookup(rot);
        c = cos_table_lookup(rot);
        arg0->direction.x = c * arg0->direction.x - s * arg0->direction.z;
        arg0->direction.y = TObjEneDelDepth__data_805DF258;
        arg0->direction.z = s * arg0->direction.x + c * arg0->direction.z;
        normalize_vector(&arg0->direction);
        this->rotation_y = (s32)(TObjEneDelDepth__data_80475DD0 * atan2_float(arg0->direction.x, arg0->direction.z));
        VecCopy((Vec *)&arg0->position, (const Vec *)&arg0->prev_position);
    }
    if (this->m_38c <= TObjEneDelDepth__data_805DF258 && TObjEneDelDepth__data_805DF258 == arg0->movementSpeed) {
        Vec q;
        if (find_nearest_visible_player(arg0, (int)&q, TObjEneDelDepth__data_805DF280) != 0xFFFF && vector_length(&q) > TObjEneDelDepth__data_805DF270) {
            this->set_action_state(4);
        } else {
            this->set_action_state(3);
            play_sound_effect(0x4003A822, &arg0->position, 0, 0);
        }
    }
}
#pragma pop

void TObjEneDelDepth::enter_state8() {
    this->actorFlags = (s32) (this->actorFlags | 0x04000000);
    this->attackTimer = 8;
    this->motionController->set_motion(0xA);
    play_sound_effect(0x4003A820, (u8 *)&this->position, 0, 0);
    this->set_draw_mode(1);
}

void TObjEneDelDepth::update_state() {
    if (this->motionController->is_state_complete() == 1) {
        this->actorFlags = (s32) (this->actorFlags & 0xFBFFFFFF);
        if (get_flag_bit4() != 0) {
            set_action_state(7);
            return;
        }
        set_action_state(6);
    }
}

void TObjEneDelDepth::enter_appear_state() {
    this->actorFlags = (s32) (this->actorFlags | 0x04000000);
    this->attackTimer = 0x14;
    play_sound_effect(0x4003A820, (void *) ((u8 *)&this->position), 0, 0);
    this->motionController->set_motion(0xB);
    this->set_draw_mode(1);
}

void TObjEneDelDepth::try_enter_appear() {
    if (this->motionController->is_state_complete() == 1) {
        this->actorFlags = (s32) (this->actorFlags | 0x04000000);
        this->set_action_state(3);
        play_sound_effect(0x4003A822, (u8 *)&this->position, 0, 0);
    }
}

void TObjEneDelDepth::fn_80314500() {
    targetPlayer = 0xFFFF;
    m_394 = ((s32)(lbl_805DF2A0 * random_ratio()) + 4) << 16;
    timer = 0x7FFFFFFF;
    m_3bc = TObjEneDelDepth__tune_params->turnSpeed;
    if (random_ratio() > TObjEneDelDepth__data_805DF298) {
        m_3bc *= -1;
    }
    motionController->set_motion(0);
    set_draw_mode(2);
}

#pragma push
#pragma fp_contract on
void TObjEneDelDepth::fn_803142DC() {
    u8 *ene_del_depth = (u8 *)this;
    Vec v;
    Vec w;
    f32 f;
    s32 lim;
    u16 id;
    f = sin_table_lookup(this->m_394);
    if (f < TObjEneDelDepth__data_805DF258) {
        f = TObjEneDelDepth__data_805DF258;
    }
    this->rotation_y = (s32)(f * (f32)this->m_3bc + (f32)this->rotation_y);
    if (this->targetPlayer == 0xFFFF) {
        id = find_nearest_visible_player(ene_del_depth, (int)&v, lbl_805DF29C);
        if (id != 0xFFFF && angle_difference_abs(this->rotation_y, (s32)(TObjEneDelDepth__data_80475DD0 * atan2_float(v.x, v.z))) < 0x1C71) {
            this->m_394 = 0;
            this->targetPlayer = id;
        }
    }
    this->m_394 -= 0x600;
    if (this->m_394 <= 0) {
        u32 n = ((AnimationMotion *)get_bml_motion((s32)TObjEneDelDepth__shared_resource, 0xB))->frameCount;
        lim = (s32)((f32)n / TObjEneDelDepth__data_805DF298);
        this->m_394 = 0;
        if (this->targetPlayer != 0xFFFF) {
            w.x = TObjEneDelDepth__data_805DF260;
    w.z = w.y = TObjEneDelDepth__data_805DF258;
            TObjPlayer::calc_distance_to_client((s32)ene_del_depth, (u16)((u16)this->targetPlayer), (u32)&w);
            this->rotation_y = approach_angle_limited(this->rotation_y, (s32)(TObjEneDelDepth__data_80475DD0 * atan2_float(w.x, w.z)), 0x280);
        }
        if (this->timer > lim) {
            this->motionController->set_motion(0);
            this->timer = lim;
        } else if (--this->timer <= 0) {
            if (this->targetPlayer == 0xFFFF) {
                this->set_action_state(5);
            } else {
                this->set_action_state(8);
            }
        }
    }
}
#pragma pop

void TObjEneDelDepth::init_depth() {
    this->set_depth_offset(0x1E, 0x1E);
    this->m_3bc = 0x888;
    if (random_ratio() > TObjEneDelDepth__data_805DF298) {
        this->m_3bc = this->m_3bc * 0xFFFFFFFF;
    }
    this->motionController->set_motion(0);
    this->set_draw_mode(2);
}

void TObjEneDelDepth::fn_803141A8() {
    TObjEneDelDepth *arg0 = this;
    f32 sp[3];
    s32 r = 0;
    s32 t;
    arg0->rotation_y = arg0->rotation_y + arg0->m_3bc;
    if (this->find_nearest_enemy_with_flag((s32)sp, (f32)lbl_805DF294) != 0xFFFF) {
        t = (s32) (((const f64 *)&TObjEneDelDepth__data_80475DD0)[0] * atan2_float(sp[0], sp[2]));
        if (angle_difference_abs(arg0->rotation_y, t) < 0x444) {
            arg0->rotation_y = t;
            r = 1;
        }
    }
    arg0->timer = arg0->timer - 1;
    if (r != 0 || arg0->timer < 0) {
        this->set_action_state(9);
    }
}

void TObjEneDelDepth::setup_depth_draw() { this->set_depth_offset(30, 30); this->motionController->set_motion(0); this->set_draw_mode(2); }

void TObjEneDelDepth::move_toward_target() {
    Vec v;
    s32 ang;
    s32 id;
    u8 *arg0 = (u8 *)this;
    v.x = TObjEneDelDepth__data_805DF260;
    v.z = v.y = TObjEneDelDepth__data_805DF258;
    id = this->targetPlayer;
    if (id != 0xFFFF) {
        TObjPlayer::calc_distance_to_client((s32)arg0, (u16)((u16)id), (u32)&v);
    }
    ang = (s32)(TObjEneDelDepth__data_80475DD0 * atan2_float(v.x, v.z));
    this->rotation_y = approach_angle_limited(this->rotation_y, ang, 0x200);
    if (angle_difference_abs(this->rotation_y, ang) < 0x200) {
        this->timer = 0;
    }
    VecCopy(&this->prev_position, &this->position);
    if (vector_length(&v) <= lbl_805DF288) {
        v.x = TObjEneDelDepth__data_805DF260;
    v.z = v.y = TObjEneDelDepth__data_805DF258;
    } else {
        normalize_vector(&v);
    }
    v.x *= lbl_805DF28C;
    v.y *= lbl_805DF28C;
    v.z *= lbl_805DF28C;
    vec3_add_to((u8 *)&this->position, &v);
    if (project_actor_to_ground(arg0, (u8 *)&this->position, (void *)0) == 0 || csnLookAt((s32)&prev_position, (s32)&position) != 0) {
        VecCopy(&this->position, &this->prev_position);
    }
    if (--this->timer <= 0) {
        if (vector_length(&v) > TObjEneDelDepth__data_805DF280 || random_ratio() < lbl_805DF290) {
            this->set_action_state(9);
        } else {
            this->set_action_state(0xA);
        }
    }
}

void TObjEneDelDepth::init_draw_state() { this->timer = 30; this->attackTimer = 8; this->motionController->set_motion(2); this->set_draw_mode(2); }

void TObjEneDelDepth::update_bomb_drop() {
    u8 *arg0 = (u8 *)this;
    Vec out;
    s32 temp_r0;
    s32 temp_r0_2;
    this->attackTimer = (s32) (this->attackTimer - 1);
    temp_r0 = this->attackTimer;
    if ((temp_r0 <= 0) && (temp_r0 == 0)) {
        set_motion_packed_rotation();
        push_matrix_from(identity_matrix);
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        ((TObjEnemy *)arg0)->calc_joint_matrices(lbl_805DF284);
        pop_matrix();
        push_matrix_from((void *)(anim_model_matrix_array + 0x450));
        {
        Vec v = lbl_80475DB0;
        matrix_mult_vec(0, &v, &out);
        }
        pop_matrix();
        clear_motion_packed_rotation();
        play_sound_effect(0x4003A81D, (u8 *)&this->position, 0, 0);
        TObjEneDelDepthBomb::create(this, this, (Vec *)&out, TObjEneDelDepth__tune_params->techniqueLevel);
    }
    temp_r0_2 = this->timer - 1;
    this->timer = temp_r0_2;
    if (temp_r0_2 <= 0) {
        if (get_flag_bit4() != 0) {
            this->set_action_state(7);
            return;
        }
        this->set_action_state(5);
    }
}

void TObjEneDelDepth::enter_attack_cast() {
    timer = 30;
    attackTimer = 12;
    motionController->set_motion(1);
    set_draw_mode(2);
}

void TObjEneDelDepth::update_attack_cast() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r0_2;

    this->attackTimer = (s32) (this->attackTimer - 1);
    temp_r0 = this->attackTimer;
    if ((temp_r0 <= 0) && (temp_r0 == 0)) {
        if ((s32) game_difficulty_selection == 3) {
            TTecMegid::create_ex((s32)arg0, (s32)((u8 *)&this->position), (s32)((int)this->rotation_y), (s32)((int) (TObjEneDelDepth__tune_params->techniqueLevel)));
        } else {
            ((TTecBarta *)arg0)->create_ex((u8 *)&this->position, (void *)this->rotation_y, (void *)(TObjEneDelDepth__tune_params->techniqueLevel));
        }
    }
    temp_r0_2 = this->timer - 1;
    this->timer = temp_r0_2;
    if (temp_r0_2 <= 0) {
        if (get_flag_bit4() != 0) {
            this->set_action_state(7);
            return;
        }
        this->set_action_state(5);
    }
}

void TObjEneDelDepth::init_state() {
    this->actorFlags = (s32) (this->actorFlags & 0xFBFBFFFF);
    this->drawScale.z = (f32) TObjEneDelDepth__data_805DF260;
    this->drawScale.y = (f32) TObjEneDelDepth__data_805DF260;
    this->drawScale.x = (f32) TObjEneDelDepth__data_805DF260;
    this->attackTimer = 0;
    this->motionController->set_motion(3);
    this->set_draw_mode(2);
}

void TObjEneDelDepth::update_state_flag() {
    if (this->motion_flags & 0x10) {
        if (get_flag_bit4() != 0) {
            set_action_state(7);
            return;
        }
        set_action_state(6);
    }
}

void TObjEneDelDepth::start_attack_motion() {
    this->actorFlags = (s32) (this->actorFlags & 0xFBFBFFFF);
    this->drawScale.z = (f32) TObjEneDelDepth__data_805DF260;
    this->drawScale.y = (f32) TObjEneDelDepth__data_805DF260;
    this->drawScale.x = (f32) TObjEneDelDepth__data_805DF260;
    play_sound_effect(0x4003A321, (void *) ((u8 *)&this->position), 0, 0);
    if (this->motionController->get_type() < 6) {
        this->motionController->set_motion(4);
    } else {
        this->timer = 0x10;
        this->motionController->set_motion(8);
    }
    this->set_draw_mode(0);
}

void TObjEneDelDepth::update_ai_state() {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    s32 temp_r0;

    if (this->motionController->get_type() < 6) {
        if (this->motion_flags & 0x10) {
            this->set_action_state(5);
        }
    } else {
        temp_r0 = this->timer - 1;
        this->timer = temp_r0;
        if (temp_r0 <= 0) {
            if (((((u16 (*)(void *, void *, f32))find_nearest_visible_player)(arg0, &sp8, TObjEneDelDepth__data_805DF280)) != 0xFFFF) && (vector_length(&sp8) > TObjEneDelDepth__data_805DF270)) {
                this->set_action_state(4);
                return;
            }
            this->set_action_state(3);
            play_sound_effect(0x4003A822, (u8 *)&this->position, 0, 0);
        }
    }
}

void TObjEneDelDepth::init_move() {
    this->drawScale.z = (f32) TObjEneDelDepth__data_805DF260;
    this->drawScale.y = (f32) TObjEneDelDepth__data_805DF260;
    this->drawScale.x = (f32) TObjEneDelDepth__data_805DF260;
    refresh_lobby_state__10TObjPlayerFv();
    this->actionPhase = 0;
    if (this->motionController->get_type() < 6) {
        this->timer = 0x22;
        this->motionController->set_motion(5);
    } else {
        this->timer = 0x20;
        this->motionController->set_motion(9);
    }
    this->set_draw_mode(0);
}

#pragma push
#pragma opt_common_subs off
void TObjEneDelDepth::update_death_fade() {
    u8 *enemy = (u8 *)this;
    s32 sp8;
    f32 temp_f1;
    s32 temp_r0_2;
    s32 temp_r0_3;
    switch (this->actionPhase) {
    case 0:
        temp_r0_2 = this->timer - 1;
        this->timer = temp_r0_2;
        if (temp_r0_2 <= 0) {
            this->actionPhase = 1;
            play_sound_effect(0x4003A321, (u8 *)&this->position, 0, 0);
            this->timer = 5;
        }
        break;
    case 1:
        temp_f1 = this->opacity + lbl_805DF27C;
        this->opacity = temp_f1;
        if (temp_f1 < TObjEneDelDepth__data_805DF258) {
            this->opacity = TObjEneDelDepth__data_805DF258;
        }
        temp_r0_3 = this->timer - 1;
        this->timer = temp_r0_3;
        if (temp_r0_3 <= 0) {
            this->actionPhase = 2;
        }
        break;
    case 2:
    default:
        sp8 = 0x800;
        ((TObjEnemy *)enemy)->send_6x0A_enemy_state(&sp8);
        ((TObjEnemy *)enemy)->exchange_object_state((s32)&sp8, (s16)(0));
        vfunc_79(&sp8);
        ((TObjEnemy *)enemy)->send_entity_set_flags();
        TObjPlayer::apply_effect_variant_a((s32)((u8 *)&this->position), 0);
        this->queue_destruction();
        break;
    }
}

#pragma pop
void TObjEneDelDepth::enter_fall_to_ground() {
    drawOffsetY = TObjEneDelDepth__data_805DF278;
    drawScale.z = TObjEneDelDepth__data_805DF258;
    drawScale.y = TObjEneDelDepth__data_805DF258;
    drawScale.x = TObjEneDelDepth__data_805DF258;
    opacity = TObjEneDelDepth__data_805DF258;
    motionController->set_motion(6);
    set_draw_mode(0);
}

#pragma push
#pragma fp_contract on
void TObjEneDelDepth::update_fall_to_ground() {
    TObjEneDelDepth *o = this;
    s32 done;
    s32 tries;
    Vec a;
    Vec b;
    Vec c;
    f32 s;
    f32 co;
    f32 k;

    done = 0;
    k = TObjEneDelDepth__data_805DF268;
    tries = 4;
    o->fallVelocity.y += lbl_805DF274;
    do {
        VecCopy((Vec *)&a, (const Vec *)&o->position);
        vec3_add_to(&a, &o->fallVelocity.x);
        VecCopy((Vec *)&b, (const Vec *)&a);
        b.y += k + fabs_float(o->fallVelocity.y);
        if (project_actor_to_ground(o, &b, 0) != 0) {
            VecCopy((Vec *)&o->position, (const Vec *)&a);
            if (!(o->position.y > b.y)) {
                o->position.y = b.y;
                done = 1;
            }
            break;
        }
        s = sin_table_lookup(0x4000);
        co = cos_table_lookup(0x4000);
        tries--;
        o->fallVelocity.x = co * o->fallVelocity.x + s * o->fallVelocity.z;
        o->fallVelocity.z = -s * o->fallVelocity.x + co * o->fallVelocity.z;
    } while (tries > 0);
    if (tries == 0) {
        o->fallVelocity.x = o->fallVelocity.z = TObjEneDelDepth__data_805DF258;
        VecCopy((Vec *)&c, (const Vec *)&o->position);
        c.y += TObjEneDelDepth__data_805DF268 + fabs_float(o->fallVelocity.y);
        if (project_actor_to_ground(o, &c, 0) != 0) {
            if (!(o->position.y > c.y)) {
                o->position.y = c.y;
                done = 1;
            }
        } else {
            done = 1;
        }
    }
    if (done != 0) {
        this->adjust_height_to_ground();
        this->set_action_state(1);
    }
}
#pragma pop

void TObjEneDelDepth::update_ground_check() {
    Vec point;
    CsnHit *hit;
    if ((actor_frame_tick % 5) == 0) {
        VecCopy(&point, &position);
        point.y += TObjEneDelDepth__data_805DF270;
        hit = (CsnHit *)csnVectorUnder((Vec *)&point, (u32 *)&m_120, 0x4000);
        if (hit != NULL) {
            groundFlags = hit->contact->flags;
            VecCopy(&groundPoint, &hit->contact->point);
        } else {
            VecCopy(&groundPoint, &position);
        }
    }
    if (groundFlags & 0x4000) {
        TObjEneRecon::set_active();
    }
}

TObjEneDelDepthBomb::TObjEneDelDepthBomb(TObjEneDelDepth *parent, TObjChara *attacker, const Vec *origin, s32 level) : TObjChara(parent) {
    m_name = TObjEneDelDepthBomb__name;
    source = attacker;
    rotation_y = ((TObjEneDelDepth *)m_up)->rotation_y;
    VecCopy(&position, origin);
    f32 sine = sin_table_lookup(rotation_y);
    f32 cosine = cos_table_lookup(rotation_y);
    speed = ((TObjEneDelDepth *)m_up)->get_bomb_speed();
    velocity.x = speed * sine;
    velocity.y = TObjEneDelDepth__data_805DF258;
    velocity.z = speed * cosine;
    techniqueLevel = level;
    distance = TObjEneDelDepth__data_805DF258;
    age = 0;
}

TObjEneDelDepthBomb::~TObjEneDelDepthBomb() {}

TObjEneDelDepthBomb *TObjEneDelDepthBomb::create(TObjEneDelDepth *parent, TObjChara *source, const Vec *position, s32 level) {
    return new TObjEneDelDepthBomb(parent, source, position, level);
}

void TObjEneDelDepthBomb::run_task() {
    s32 done = 0;
    f32 travelled;
    velocity.y += lbl_805DF264;
    vec3_add_to(&position, &velocity);
    if (++age > 0x14F) {
        done = 1;
    }
    Vec ground = position;
    ground.y += TObjEneDelDepth__data_805DF268;
    if (project_actor_to_ground(this, &ground, &m_248) != 0) {
        groundHeight = ground.y;
        if (position.y <= groundHeight) {
            done = 1;
        }
    } else {
        done = 1;
    }
    if (fn_80313268() != 0) {
        done = 1;
    }
    travelled = distance + speed;
    distance = travelled;
    if (travelled >= TObjEneDelDepth__data_805DF26C) {
        done = 1;
    }
    if (done != 0) {
        Vec impact;
        VecCopy(&impact, &position);
        impact.y += TObjEneDelDepth__data_805DF268;
        create__11TTecRaBartaFPvPvPvPv(source, &position, &impact, (void *)techniqueLevel);
        this->queue_destruction();
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TObjEneDelDepthBomb::render() {
    Vec shadowScale;
    s32 rotationX;
    s32 rotationZ;
    BmlResource *data = TObjEneDelDepth::get_data();
    if (data == 0) {
        this->queue_destruction();
        return;
    }
    s32 model = get_bml_model(data, 2);
    s32 texture = TObjFish__sub_8001EDB0((u8 *)data, 2);
    push_matrix();
    post_translate_matrix(&position);
    rotate_matrix_zyx(0, rotation_x, rotation_y, rotation_z);
    TObjFish::set_global_param(texture);
    draw_chunk_object((void *)model);
    pop_matrix();
    push_matrix();
    translate_matrix(0, position.x, lbl_805DF250 + groundHeight, position.z);
    direction_to_rotation_xz((u8 *)&m_248, &rotationX, &rotationZ);
    rotate_matrix_z(0, rotationZ);
    rotate_matrix_x(0, (void *)(rotationX + 0x4000));
    f32 height = position.y - groundHeight;
    if (height > lbl_805DF254) {
        height = lbl_805DF254;
    } else if (height < TObjEneDelDepth__data_805DF258) {
        height = TObjEneDelDepth__data_805DF258;
    }
    f32 fade;
    shadowScale.x = shadowScale.y = lbl_805DF25C * (fade = TObjEneDelDepth__data_805DF260 - height / lbl_805DF254) + lbl_805DF250;
    shadowScale.z = TObjEneDelDepth__data_805DF260;
    scale_current_matrix(&shadowScale, fade, TObjEneDelDepth__data_805DF260, lbl_805DF25C);
    draw_blob_shadow(0);
    pop_matrix();
}
#pragma pop

s32 TObjEneDelDepthBomb::fn_80313268() { return 0; }
