#include "types.h"
#include "pso/system/NinjaUtil.h"
#include "pso/boss/TBoss3VoloptHiraisin.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/misc/TBreakUpMdl.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjLight_80133568.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/vector.h"
#include "pso/TParticleCtrl.h"
#include "pso/unk/text_803E2D70.h"

extern "C" {
void advance_animation_playback(TObjMotion *obj);
s32 play_sound_effect(s32 id, Vec *pos, s32 a2, s32 flags);
s32 TObjFish__sub_8001EDB0(BmlResource *resource, s32 index);
void obj_setFlags30(TObject *obj, u32 mask);
void submit_cursor_candidate(TObject *obj, s32 a1);
s32 minimap_render_dot(Vec *pos, s32 color, s16 a2, s32 a3);
void init_collision_body_parts(TObject *obj, void *parts, s32 count);
void free_collision_body_parts(TObject *obj);
void push_matrix(void);
s32 pop_matrix(void);
void post_translate_matrix(const f32 *pos);
void rotate_matrix_y(void *mtx, s32 angle);
void scale_matrix(void *mtx, f32 x, f32 y, f32 z);

TUnk_8048FA00 *init_from_model__11TBreakUpMdlFl(TUnk_8048FA00 *obj, s32 model);
void trigger_dell_biter_events__10TObjPlayerFv(Vec *pos);
void update_collisions__10TObjPlayerFv(TObjEnemy *obj);

extern u32 model_render_flags;
extern u32 saved_model_render_flags;
extern TObject *tl_04;
}

struct BreakupParams {
    s32 pad_0;
    f32 pad_4;
    f32 pad_8;
    f32 pad_c;
    f32 pad_10;
    f32 pad_14;
    f32 pad_18;
};

struct MotionAction {
    s32 pad_0;
    s32 pad_4;
    f32 pad_8;
    s32 pad_c;
};

struct EnemyMovementParams {
    f32 pad_0;
    f32 pad_4;
    s32 pad_8;
    s32 pad_c;
    s32 pad_10;
    s32 pad_14;
    s32 pad_18;
};

struct CollisionBodyPart {
    Vec offset;
    f32 radius;
    u8 pad_10[0x8];
    s32 flags;
    u8 pad_1c[0x10];
};

struct CollisionState {
    u8 pad_0[0x18];
    u32 flags;
};

// A model node: evaluation flags, then the node's rotation at 0x14.
struct ModelNode {
    u32 flags;
    u8 pad_4[0x14];
    s32 rotation_y;
};

#pragma readonly_strings on

static const char *TBoss3VoloptHiraisin_name = "TBoss3VoloptHiraisin";

static BreakupParams volopt_hiraisin_breakup_params = { 0x14, 0.06f, 1.5f, 0.9f, 0.12f, 0.55f, 0.5f };
static MotionAction volopt_hiraisin_motions[5] = {
    { 0x10000, 6, 0.7f, 0 },
    { 0x10000, 6, 0.7f, 1 },
    { 0x20000, 6, 0.7f, 4 },
    { 0x20000, 8, 0.7f, 8 },
    { 0x30004, 7, 0.5f, 0x10 },
};
static EnemyMovementParams volopt_hiraisin_movement = { 150.0f, 0.5555555f, 0x400, 0x1E0000, 0, 1, 0 };
static CollisionBodyPart volopt_hiraisin_body_parts[1] = {
    { { 0.0f, -5.0f, 0.0f }, 6.0f, { 0 }, 0x8005 },
};


static void *volopt_hiraisin_stats;
static void *volopt_hiraisin_stats_b;
static void *volopt_hiraisin_object_params;
static void *volopt_hiraisin_stat_table;
static BmlResource *volopt_hiraisin_resources;
static ModelNode *volopt_hiraisin_spin_node;
static TUnk_8048FA00 *volopt_hiraisin_breakup_model;

void TBoss3VoloptHiraisin::clear_flag_08000000() {
    clear_player_status_flag(0, 0x08000000);
}

void TBoss3VoloptHiraisin::set_flag_08000000() {
    set_indexed_flags(0, 0x08000000);
}

s32 TBoss3VoloptHiraisin::sub_80040FCC() {
    return (m_a4->flags >> 1) & 1;
}

void TBoss3VoloptHiraisin::sub_80040FDC() {
    switch (state) {
    case -1:
        break;
    case 0:
        m_388 |= 1;
        m_b8 = 0;
        advance_animation_playback(this);
        position[1] = 80.0f;
        actorFlags |= 0x40000;
        ((CollisionState *)m_a4)->flags |= 4;
        ((CollisionState *)m_a4)->flags &= ~2;
        play_sound_effect(0x4003A306, (Vec *)position, 0, 0);
        state = 1;
    case 1:
        position[1] -= 0.5f;
        if (position[1] <= 50.0f) {
            position[1] = 50.0f;
            m_388 &= ~1;
            actorFlags &= ~0x40000;
            vfunc_59();
        }
        break;
    }
    refresh_collision_body_centers();
}

void TBoss3VoloptHiraisin::start_attack() {
    s16 max_hp;
    u32 flags;
    TBoss3Volopt::create_breakup_mdl((s32)volopt_hiraisin_breakup_model, (s32)&volopt_hiraisin_breakup_params,
                                     TObjFish__sub_8001EDB0(volopt_hiraisin_resources, 0x10), (s32)&m_2fc, rotation_y);
    trigger_dell_biter_events__10TObjPlayerFv((Vec *)&m_2fc);
    play_sound_effect(0x4001C112, (Vec *)position, 0, 0);
    m_388 &= ~1;
    max_hp = hpmax;
    referenceHp = max_hp;
    hp = max_hp;
    flags = actorFlags;
    actorFlags = flags & ~0xA00;
    sub_800C7860();
}

void TBoss3VoloptHiraisin::sub_8004118C() {
    switch (state) {
    case 0:
        m_b8 = 0;
        state = 1;
        break;
    case 1:
        break;
    case -1:
        break;
    }
    refresh_collision_body_centers();
    hover_angle += 0x800;
}

void TBoss3VoloptHiraisin::update_drop() {
    switch (state) {
    case 0:
        m_b8 = 4;
        y_speed = -2.27f;
        state = 1;
        hover_angle = 0;
        break;
    case 1:
        advance_animation_playback(this);
        position[1] = position[1] + y_speed;
        if (position[1] <= 4.6f) {
            position[1] = 4.6f;
            state = 2;
            ((CollisionState *)m_a4)->flags &= ~4;
            ((CollisionState *)m_a4)->flags |= 2;
            play_sound_effect(0x4003A808, (Vec *)position, 0, 0);
        }
        break;
    case 2:
        advance_animation_playback(this);
        if (m_c0 >= anim_end_frame - 1.5f) {
            state = 3;
        }
        break;
    case -1:
        return;
    case 3:
        break;
    }
    update_collisions__10TObjPlayerFv(this);
}

void TBoss3VoloptHiraisin::sub_80041314() {
    switch (state) {
    case -1:
        break;
    case 0:
        actorFlags &= ~0x200000;
        m_b8 = 3;
        state = 1;
    case 1:
        advance_animation_playback(this);
        if (m_b4 != 8) {
            referenceHp = hp;
            actorFlags &= ~0x200;
            m_388 &= ~1;
            vfunc_59();
        }
        break;
    }
    refresh_collision_body_centers();
}

#pragma push
#pragma fp_contract on
void TBoss3VoloptHiraisin::render() {
    f32 scale;
    if (!(actorFlags & 0x02000000) && update_object_view_visibility(400.0f, 40.0f) != 0) {
        TObjFish::set_global_param(texture_id);
        saved_model_render_flags = model_render_flags;
        model_render_flags |= 0x01000000;
        select_actor_lighting((s32)this);
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        model_render_flags &= ~0x400;
        post_translate_matrix(position);
        if (m_b4 == 8) {
            translate_matrix(0, 0.0f, 20.0f, 0.0f);
        }
        translate_matrix(0, 0.0f, sin_table_lookup(hover_angle), 0.0f);
        rotate_matrix_y(NULL, rotation_y);
        if (TObjPlayer::check_demo_mode() == 1) {
            draw_chunk_object(model);
        } else {
            draw();
        }
        pop_matrix();
        restore_scene_lighting();
        TParticleCtrl::end_effect_render();
        model_render_flags = saved_model_render_flags;
        if (position[1] < 50.0f) {
            push_matrix();
            scale = 1.0f - 0.02202643f * (position[1] - 4.6f);
            translate_matrix(0, position[0], 4.5f, position[2]);
            scale_matrix(NULL, scale, scale, scale);
            TObjFish::set_global_param(TObjFish__sub_8001EDB0(volopt_hiraisin_resources, 0));
            draw_chunk_object((void *)get_bml_model(volopt_hiraisin_resources, 0));
            pop_matrix();
        }
    }
}
#pragma pop

void TBoss3VoloptHiraisin::dispatch_state() {
    switch (mode) {
    case 0:
    case 1:
        sub_8004118C();
        break;
    case 4:
        sub_80041314();
        break;
    case 5:
        update_drop();
        break;
    case 7:
        sub_80040FDC();
        break;
    }
}

void TBoss3VoloptHiraisin::run_task() {
    if (TObjPlayer::check_demo_mode() != 1) {
        if (mode != 5) {
            if (has_flag_0x800() != 0) {
                vfunc_63();
            } else if (test_flag30_512() != 0) {
                vfunc_62();
            }
        }
        if (mode != (s32)next_action) {
            if ((s32)state != -1) {
                state = -1;
                dispatch_state();
            }
            mode = next_action;
            state = 0;
        }
        dispatch_state();
        VecCopy((Vec *)&m_2fc, (Vec *)position);
        if (mode != 5) {
            m_300 -= 30.0f;
        }
        copy_position();
        submit_cursor_candidate(this, -1);
        minimap_render_dot((Vec *)position, -0x5DB4, 1, 0);
        volopt_hiraisin_spin_node->rotation_y += 0x4000;
        clear_all_status_effects();
    }
}

void TBoss3VoloptHiraisin::destroy() {
    delete volopt_hiraisin_breakup_model;
    volopt_hiraisin_breakup_model = NULL;
}

void TBoss3VoloptHiraisin::init_models() {
    TUnk_8048FA00 *breakup;
    volopt_hiraisin_resources = boss3_volopt_resources;
    volopt_hiraisin_spin_node = (ModelNode *)find_model_node(get_bml_model(boss3_volopt_resources, 0x10), 0xB);
    volopt_hiraisin_spin_node->flags &= ~2;
    breakup = (TUnk_8048FA00 *)::operator new(0x10);
    if (breakup != NULL) {
        breakup = init_from_model__11TBreakUpMdlFl(breakup, get_bml_model(volopt_hiraisin_resources, 0x10));
    }
    volopt_hiraisin_breakup_model = breakup;
    volopt_hiraisin_stats = TLobby::register_boss(0x24);
    volopt_hiraisin_stats_b = TLobby::dispatch_shared_handler_b(0x24);
    volopt_hiraisin_object_params = TLobby::register_object(0x24);
    volopt_hiraisin_stat_table = TLobby::dispatch_shared_handler_a(0x24);
}

void *TBoss3VoloptHiraisin::create(void *set_data) {
    return new TBoss3VoloptHiraisin(tl_04, set_data);
}

TBoss3VoloptHiraisin::~TBoss3VoloptHiraisin() {
    free_collision_body_parts(this);
}

void TBoss3VoloptHiraisin::init_params() {
    VecCopy((Vec *)&m_2fc, (Vec *)position);
    m_300 -= 30.0f;
    copy_position();
    motion_list = volopt_hiraisin_resources->motions;
    action_table = volopt_hiraisin_motions;
    set_field_d8((s32)action_table);
    init_collision_body_parts(this, volopt_hiraisin_body_parts, 1);
    variant = 0;
    movementParameters = &volopt_hiraisin_movement;
    recalc_combat_stats(volopt_hiraisin_stats, volopt_hiraisin_stats_b, volopt_hiraisin_object_params, 1.0f, 1.0f);
    m_b8 = 0;
    set_animation(m_b8);
    set_field_b8(m_b8);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    set_param(0x2E);
    ((TBoss3Volopt *)this)->reset_photon_effect();
    load_params_from_table(0x10);
    sub_800C7860();
    add_flags_2e4(4);
    obj_setFlags30(this, 0x8000);
    clear_lobby_object_state();
}

TBoss3VoloptHiraisin::TBoss3VoloptHiraisin(TUnk_804B9870 *parent, u16 id, s32 index) : TObjEnemyCustom(parent) {
    m_name = TBoss3VoloptHiraisin_name;
    entity_id = id;
    set_index = index;
    set_entry = NULL;
    room = parent->room;
    set_group = parent->set_group;
    position[1] = 80.0f;
    position[0] = boss3_volopt_spawn_pos.x;
    position[2] = boss3_volopt_spawn_pos.z;
    init_params();
}

TBoss3VoloptHiraisin::TBoss3VoloptHiraisin(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    m_name = TBoss3VoloptHiraisin_name;
    apply_set_data(set_data);
    init_params();
}

void TBoss3VoloptHiraisin::copy_position() {
    VecCopy(&center, (Vec *)&m_2fc);
}

void TBoss3VoloptHiraisin::load_params_from_table(s32 index) {
    model = (void *)volopt_hiraisin_resources->models[index].model;
    texture_id = volopt_hiraisin_resources->models[index].m_c;
}
