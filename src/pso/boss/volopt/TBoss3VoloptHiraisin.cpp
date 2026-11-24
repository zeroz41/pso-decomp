#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/render/NinjaUtil.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/effect/TBreakUpMdl.h"
#include "pso/unk/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResource.h"
#include "pso/system/vector.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/system/MatrixOps.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/boss/volopt/TBoss3Volopt_800D8ACC.h"
#include "pso/object/base/TObjBase.h"


extern "C" {
s32 minimap_render_dot(Vec *pos, s32 color, s16 a2, s32 a3);
void init_collision_body_parts(TObject *obj, void *parts, s32 count);
void free_collision_body_parts(TObject *obj);

extern u32 model_render_flags;
extern u32 saved_model_render_flags;
extern TObject *tl_04;
}

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
#pragma readonly_strings on

static const char *TBoss3VoloptHiraisin_name = "TBoss3VoloptHiraisin";

static BreakUpParamRow volopt_hiraisin_breakup_params = { 0x14, 0.06f, 1.5f, 0.9f, 0.12f, 0.55f, 0.5f };
static TObjMotionAction volopt_hiraisin_motions[5] = {
    {1, 0, 6, 0.7f, 0},
    {1, 0, 6, 0.7f, 1},
    {2, 0, 6, 0.7f, 4},
    {2, 0, 8, 0.7f, 8},
    {3, 4, 7, 0.5f, 0x10},
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
static NJS_OBJECT *volopt_hiraisin_spin_node;
static TBreakUpMdlData *volopt_hiraisin_breakup_model;

void TBoss3VoloptHiraisin::clear_flag_08000000() {
    clear_player_status_flag(0, 0x08000000);
}

void TBoss3VoloptHiraisin::set_flag_08000000() {
    set_indexed_flags(0, 0x08000000);
}

s32 TBoss3VoloptHiraisin::is_grounded() {
    return (bodies->flags >> 1) & 1;
}

void TBoss3VoloptHiraisin::update_descend() {
    switch (state) {
    case -1:
        break;
    case 0:
        behavior_flags |= 1;
        this->requested_action = 0;
        advance_animation();
        position.y = 80.0f;
        actorFlags |= 0x40000;
        ((CollisionState *)bodies)->flags |= 4;
        ((CollisionState *)bodies)->flags &= ~2;
        play_sound_effect(0x4003A306, &position, 0, 0);
        state = 1;
    case 1:
        position.y -= 0.5f;
        if (position.y <= 50.0f) {
            position.y = 50.0f;
            behavior_flags &= ~1;
            actorFlags &= ~0x40000;
            run_move_action();
        }
        break;
    }
    refresh_collision_body_centers();
}

void TBoss3VoloptHiraisin::start_attack() {
    s16 max_hp;
    u32 flags;
    TBoss3Volopt::create_breakup_mdl(volopt_hiraisin_breakup_model, &volopt_hiraisin_breakup_params,
                       get_bml_texlist((BmlResource *)volopt_hiraisin_resources, 0x10), &body_center, rotation_y);
    trigger_dell_biter_events(&body_center);
    play_sound_effect(0x4001C112, &position, 0, 0);
    behavior_flags &= ~1;
    max_hp = hpmax;
    referenceHp = max_hp;
    hp = max_hp;
    flags = actorFlags;
    actorFlags = flags & ~0xA00;
    start_appear();
}

void TBoss3VoloptHiraisin::update_hover() {
    switch (state) {
    case 0:
        this->requested_action = 0;
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
        this->requested_action = 4;
        velocity.y = -2.27f;
        state = 1;
        hover_angle = 0;
        break;
    case 1:
        advance_animation();
        position.y = position.y + velocity.y;
        if (position.y <= 4.6f) {
            position.y = 4.6f;
            state = 2;
            ((CollisionState *)bodies)->flags &= ~4;
            ((CollisionState *)bodies)->flags |= 2;
            play_sound_effect(0x4003A808, &position, 0, 0);
        }
        break;
    case 2:
        advance_animation();
        if (this->frame >= this->frame_count - 1.5f) {
            state = 3;
        }
        break;
    case -1:
        return;
    case 3:
        break;
    }
    update_collisions();
}

void TBoss3VoloptHiraisin::update_hit() {
    switch (state) {
    case -1:
        break;
    case 0:
        actorFlags &= ~0x200000;
        this->requested_action = 3;
        state = 1;
    case 1:
        advance_animation();
        if (this->action_flags != 8) {
            referenceHp = hp;
            actorFlags &= ~0x200;
            behavior_flags &= ~1;
            run_move_action();
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
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        saved_model_render_flags = model_render_flags;
        model_render_flags |= 0x01000000;
        select_actor_lighting(this);
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        model_render_flags &= ~0x400;
        post_translate_matrix(&position.x);
        if (this->action_flags == 8) {
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
        if (position.y < 50.0f) {
            push_matrix();
            scale = 1.0f - 0.02202643f * (position.y - 4.6f);
            translate_matrix(0, position.x, 4.5f, position.z);
            scale_matrix(NULL, scale, scale, scale);
            TObjFish::set_global_param(get_bml_texlist((BmlResource *)volopt_hiraisin_resources, 0));
            draw_chunk_object((void *)get_bml_model((BmlResource *)volopt_hiraisin_resources, 0));
            pop_matrix();
        }
    }
}
#pragma pop

void TBoss3VoloptHiraisin::dispatch_state() {
    switch (mode) {
    case 0:
    case 1:
        update_hover();
        break;
    case 4:
        update_hit();
        break;
    case 5:
        update_drop();
        break;
    case 7:
        update_descend();
        break;
    }
}

void TBoss3VoloptHiraisin::run_task() {
    if (TObjPlayer::check_demo_mode() != 1) {
        if (mode != 5) {
            if (has_flag_0x800() != 0) {
                run_death_reaction();
            } else if (test_flag30_512() != 0) {
                run_hit_reaction();
            }
        }
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
        if (mode != 5) {
            body_center.y -= 30.0f;
        }
        copy_position();
        submit_cursor_candidate(this, -1);
        minimap_render_dot(&position, -0x5DB4, 1, 0);
        volopt_hiraisin_spin_node->ang[1] += 0x4000;
        clear_all_status_effects();
    }
}

void TBoss3VoloptHiraisin::destroy() {
    delete volopt_hiraisin_breakup_model;
    volopt_hiraisin_breakup_model = NULL;
}

void TBoss3VoloptHiraisin::init_models() {
    TBreakUpMdlData *breakup;
    volopt_hiraisin_resources = boss3_volopt_resources;
    volopt_hiraisin_spin_node = find_model_node(get_bml_model((BmlResource *)boss3_volopt_resources, 0x10), 0xB);
    volopt_hiraisin_spin_node->evalflags &= ~NJD_EVAL_UNIT_ANG;
    breakup = new TBreakUpMdlData(get_bml_model((BmlResource *)volopt_hiraisin_resources, 0x10));
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
    VecCopy(&body_center, &position);
    body_center.y -= 30.0f;
    copy_position();
    motion_list = volopt_hiraisin_resources->motions;
    action_table = volopt_hiraisin_motions;
    set_action_table(action_table);
    init_collision_body_parts(this, volopt_hiraisin_body_parts, 1);
    variant = 0;
    movementParameters = &volopt_hiraisin_movement;
    recalc_combat_stats((player_stats *)volopt_hiraisin_stats, (AttackParams *)volopt_hiraisin_stats_b, (ActorParamBlock *)volopt_hiraisin_object_params, 1.0f, 1.0f);
    this->requested_action = 0;
    set_animation(this->requested_action);
    set_requested_action(this->requested_action);
    hp = hpmax;
    tp = tpmax;
    referenceHp = hp;
    set_param(0x2E);
    register_by_id();
    load_params_from_table(0x10);
    start_appear();
    add_flags_2e4(4);
    set_actor_flags(0x8000);
    clear_lobby_object_state();
}

TBoss3VoloptHiraisin::TBoss3VoloptHiraisin(TObjBase *parent, u16 id, s32 index) : TObjEnemyCustom(parent) {
    m_name = TBoss3VoloptHiraisin_name;
    entity_id = id;
    set_index = index;
    set_entry = NULL;
    room = parent->room;
    set_group = parent->set_group;
    position.y = 80.0f;
    position.x = boss3_volopt_spawn_pos.x;
    position.z = boss3_volopt_spawn_pos.z;
    init_params();
}

TBoss3VoloptHiraisin::TBoss3VoloptHiraisin(TObject *parent, void *set_data) : TObjEnemyCustom(parent) {
    m_name = TBoss3VoloptHiraisin_name;
    apply_set_data(set_data);
    init_params();
}

void TObjChara::copy_position() {
    VecCopy(&center, &body_center);
}

void TBoss3VoloptHiraisin::load_params_from_table(s32 index) {
    model = (void *)volopt_hiraisin_resources->models[index].model;
    texlist = volopt_hiraisin_resources->models[index].texlist;
}
