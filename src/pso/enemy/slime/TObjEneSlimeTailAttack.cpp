#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResourceDescriptor.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"

struct NJS_OBJECT;
#include "pso/enemy/slime/TObjEneSlime.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/enemy/slime/SlimeAnimationState.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/object/base/TObjChara.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobby.h"
#include "pso/enemy/slime/TObjEneSlimeOne.h"
#include "pso/enemy/slime/TObjEneSlimeTailAttack.h"
#include "pso/enemy/slime/TObjEneSlimeWaterBomb.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"


#include "pso/system/vector.h"

#include <stddef.h>
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/enemy/lappy/TObjEneLappy.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/object/TObjControl.h"
#include "pso/player/TObjPlayer_80011014.h"

#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/map/CsnQuery.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/TObjBase.h"

extern "C" {
extern void *slime_model_index_by_type[2];
extern TObjMotionAction slime_motion_action_table[7];

struct SlimeSavedState {
    s32 flags;
    u16 unknown4;
    s16 unknown6;
    u8 unknown8[4];
};



// This TU's .rodata objects in address order (names stay placeholders).
extern const char slime_tail_model_name_bm4_ps_ma_body_nj[] = "bm4_ps_ma_body.nj";
extern const char slime_tail_model_name_bm4_ps_ma_tail_nj[] = "bm4_ps_ma_tail.nj";
extern const char slime_tail_model_name_bm4_ps_mar_body_nj[] = "bm4_ps_mar_body.nj";
extern const char slime_tail_model_name_bm4_ps_mar_tail_nj[] = "bm4_ps_mar_tail.nj";
extern const char slime_tail_model_name_bm4_ps_mb_body_nj[] = "bm4_ps_mb_body.nj";
extern const char slime_tail_model_name_bm4_ps_mbr_body_nj[] = "bm4_ps_mbr_body.nj";
extern const char slime_tail_motion_name_apear_bm4_ps_mb_body_njm[] = "apear_bm4_ps_mb_body.njm";
extern const char slime_tail_motion_name_apper_bm4_ps_ma_body_njm[] = "apper_bm4_ps_ma_body.njm";
extern const char slime_tail_motion_name_atack_bm4_ps_ma_body_njm[] = "atack_bm4_ps_ma_body.njm";
extern const char slime_tail_motion_name_damage_bm4_ps_ma_body_njm[] = "damage_bm4_ps_ma_body.njm";
extern const char slime_tail_motion_name_kie_bm4_ps_ma_body_njm[] = "kie_bm4_ps_ma_body.njm";
extern const char slime_tail_motion_name_kie_bm4_ps_mb_body_njm[] = "kie_bm4_ps_mb_body.njm";
extern const char slime_tail_motion_name_move_bm4_ps_mb_body_njm[] = "move_bm4_ps_mb_body.njm";
extern const char slime_tail_motion_name_move_bm4_ps_mb_body_njs[] = "move_bm4_ps_mb_body.njs";
extern const char slime_tail_motion_name_nodam_bm4_ps_ma_body_njm[] = "nodam_bm4_ps_ma_body.njm";
extern const char slime_tail_motion_name_tlatk_bm4_ps_ma_tail_njm[] = "tlatk_bm4_ps_ma_tail.njm";
extern const char slime_tail_motion_name_wait_bm4_ps_ma_body_njm[] = "wait_bm4_ps_ma_body.njm";
extern const char slime_tail_motion_name_wait_bm4_ps_mb_body_njm[] = "wait_bm4_ps_mb_body.njm";
extern const char slime_tail_motion_name_wait_bm4_ps_mb_body_njs[] = "wait_bm4_ps_mb_body.njs";
extern const char slime_tail_motion_name_wait2_bm4_ps_ma_body_njm[] = "wait2_bm4_ps_ma_body.njm";
extern const char bm4_ps_ma_body_bml_filename[] = "bm4_ps_ma_body.bml";
extern const char TObjEneSlime__class_name_string[] = "TObjEneSlime";
extern const char slime_type_label_blue[] = "BLUE";
// Debug label strings; slime_debug_label_table points at them.
extern const char slime_type_label_red[] = "RED";
extern const SlimeChildSlot slime_empty_child_slot = {0, NULL};
extern const char TObjEneSlimeOne__class_name_string[] = "TObjEneSlimeOne";
// draw_scale while a slime rises out of (state_value = 0, a flat puddle) or sinks back into the
// ground (state_value = 1, full size); the grow and shrink states blend between them.
extern const Vec slime_puddle_scale = {2.5f, 0.0f, 2.5f};
extern const Vec slime_full_scale = {1.0f, 1.0f, 1.0f};
extern const char TObjEneSlimeWaterBomb__class_name_string[] = "TObjEneSlimeWaterBomb";
}
SlimeTailNodeCapture slime_tail_node_capture;
extern "C" {
BmlResource *slime_bml_resource;
int slime_tail_node_index;  // capture_slime_tail_node's count of the nodes drawn

const char *slime_model_name_ptr_table[7] = {
    slime_tail_model_name_bm4_ps_ma_body_nj,
    slime_tail_model_name_bm4_ps_ma_tail_nj,
    slime_tail_model_name_bm4_ps_mar_body_nj,
    slime_tail_model_name_bm4_ps_mar_tail_nj,
    slime_tail_model_name_bm4_ps_mb_body_nj,
    slime_tail_model_name_bm4_ps_mbr_body_nj,
    NULL,
};
const char *bm4_ps_ma_body_motion_names[15] = {
    slime_tail_motion_name_apear_bm4_ps_mb_body_njm,
    slime_tail_motion_name_apper_bm4_ps_ma_body_njm,
    slime_tail_motion_name_atack_bm4_ps_ma_body_njm,
    slime_tail_motion_name_damage_bm4_ps_ma_body_njm,
    slime_tail_motion_name_kie_bm4_ps_ma_body_njm,
    slime_tail_motion_name_kie_bm4_ps_mb_body_njm,
    slime_tail_motion_name_move_bm4_ps_mb_body_njm,
    slime_tail_motion_name_move_bm4_ps_mb_body_njs,
    slime_tail_motion_name_nodam_bm4_ps_ma_body_njm,
    slime_tail_motion_name_tlatk_bm4_ps_ma_tail_njm,
    slime_tail_motion_name_wait_bm4_ps_ma_body_njm,
    slime_tail_motion_name_wait_bm4_ps_mb_body_njm,
    slime_tail_motion_name_wait_bm4_ps_mb_body_njs,
    slime_tail_motion_name_wait2_bm4_ps_ma_body_njm,
    NULL,
};
BmlResourceDescriptor slime_pair_resource_descriptor = {
    bm4_ps_ma_body_bml_filename, slime_model_name_ptr_table, bm4_ps_ma_body_motion_names, 6, 14,
};
__declspec(section ".data") void *slime_debug_label_table[2] = {
    (void *)&slime_type_label_blue, (void *)slime_type_label_red,
};
__declspec(section ".data") void *slime_model_index_by_type[2] = {
    (void *)0x4, (void *)0x5,
};
CollisionBody slime_one_collision_body[1] = {
    { { 0.0f, 15.0f, 0.0f }, 7.5f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
TObjMotionAction slime_motion_action_table[7] = {
    { MOTION_MODE_LOOP, 0, 10, 0.5f, 0 },
    { MOTION_MODE_CHAIN, 2, 10, 0.5f, 0 },
    { MOTION_MODE_LOOP, 0, 13, 0.5f, 0 },
    { MOTION_MODE_CHAIN, 0, 2, 0.8f, 0 },
    { MOTION_MODE_ONCE, 0, 8, 0.8f, 0 },
    { MOTION_MODE_ONCE, 0, 3, 0.8f, 0 },
    { MOTION_MODE_ONCE, 0, 9, 0.8f, 0 },
};
/* State table of TObjEneSlimeOne: {enter, update} per state, indexed by state; built by the TU's __sinit. */
typedef void (TObjEneSlimeOne::*SlimeOneStateFn)();
struct SlimeOneState { SlimeOneStateFn enter; SlimeOneStateFn update; };
static SlimeOneState slime_one_state_table[15] = {
    { &TObjEneSlimeOne::init_state, &TObjEneSlimeOne::update_wait_search },
    { &TObjEneSlimeOne::reset_display, &TObjEneSlimeOne::update_grow },
    { &TObjEneSlimeOne::init_slime_display, &TObjEneSlimeOne::update_shrink },
    { &TObjEneSlimeOne::enter_slide, &TObjEneSlimeOne::update_slide },
    { &TObjEneSlimeOne::enter_slime_state, &TObjEneSlimeOne::update_slime_timer },
    { &TObjEneSlimeOne::enter_appear_state, &TObjEneSlimeOne::update_dive_timer },
    { &TObjEneSlimeOne::enter_scan, &TObjEneSlimeOne::update_scan },
    { &TObjEneSlimeOne::init_slime_state, &TObjEneSlimeOne::update_aim_at_enemy },
    { &TObjEneSlimeOne::enter_approach, &TObjEneSlimeOne::update_approach },
    { &TObjEneSlimeOne::begin_appear, &TObjEneSlimeOne::update_water_bomb_timer },
    { &TObjEneSlimeOne::start_tail_attack, &TObjEneSlimeOne::tick_timer },
    { &TObjEneSlimeOne::reset_display_state, &TObjEneSlimeOne::update_tick },
    { &TObjEneSlimeOne::init_split_effect, &TObjEneSlimeOne::update_damage },
    { &TObjEneSlimeOne::enter_death, &TObjEneSlimeOne::update_effect_fade_lifetime },
    { &TObjEneSlimeOne::enter_launched, &TObjEneSlimeOne::update_launched },
};
__declspec(section ".data") void *slime_one_model_by_variant[2] = {
    (void *)0x0, (void *)0x2,
};
__declspec(section ".data") void *slime_tail_attack_id_pair[2] = {
    (void *)0x4, (void *)0x5,
};
__declspec(section ".data") void *TObjEneSlime__attack_target_param_table[2] = {
    (void *)0x30, (void *)0x34,
};
__declspec(section ".data") s32 slime_tail_model_by_target[2] = {
    1, 3,
};
__declspec(section ".data") s32 slime_tail_attack_param_ids[2] = {
    0x30, 0x34,
};
Vec slime_tail_attack_zero_vec = {0.0f, 0.0f, 0.0f};
Vec slime_tail_attack_transform = {0.0f, 0.0f, 0.0f};
#define slime_tail_attack_id_pair ((s32 *)slime_tail_attack_id_pair)
#define TObjEneSlime__attack_target_param_table ((s32 *)TObjEneSlime__attack_target_param_table)


extern const char TObjEneSlimeTailAttack__class_name_string[];
// .sdata: the class-name pointers the constructors store in TObject's name field.
const char *TObjEneSlime__name = TObjEneSlime__class_name_string;
const char *TObjEneSlimeOne_class_name = TObjEneSlimeOne__class_name_string;
const char *TObjEneSlimeWaterBomb__name = TObjEneSlimeWaterBomb__class_name_string;
const char *TObjEneSlimeTailAttack__name = TObjEneSlimeTailAttack__class_name_string;

}
// ---- folded from src/pso/unk/text_800EB778.cpp ----


extern "C" {
s32 has_no_active_slot(TObjEneSlime *self);
s32 spawn_slime_in_slot(TObjEneSlime *origin, s32 index, Vec *position, Vec *velocity);

}

// ---- folded from src/pso/enemy/TObjEneSlime.cpp ----

#include "pso/render/render_util.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/enemy/slime/TObjEneSlimeOne_800EC394.h"




#include "pso/render/model_render_state.h"

// ---- folded from src/pso/enemy/TObjEneSlime_800EBBC8.cpp ----


#include "pso/boss/darkfalz/TObjDFHorming.h"


// ---- folded from src/pso/enemy/TObjEneSlime_800EBD38.cpp ----

// ---- folded from src/pso/player/TObjPlayer_800EBE2C.cpp ----

#include "pso/render/MaterialColorFade.h"
#include "pso/player/TObjPlayer_800EBE2C.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/BlobShadow.h"
#include "pso/player/PlayerSlots.h"






void TObjPlayer::push_material_color_override(f32 alpha, f32 r, f32 g, f32 b) {
    NJS_ARGB color;
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    model_render_flags |= 0x20;
    set_chunk_material_override_pair(0xFF00, 0x800);
    color.r = r;
    color.g = g;
    color.a = -1.0f + alpha;
    color.b = b;
    set_constant_material(&color);
}

void push_material_fade(f32 alpha) {
    TObjPlayer::push_material_color_override(alpha, 0.0f, 0.0f, 0.0f);
}

void TObjPlayer::init_render_globals() { chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask; chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask; model_render_flags = saved_model_render_flags; }

s32 TObjEneSlime::create(saddr set_data) {
    return (saddr)new TObjEneSlime(new TObjControl(tl_04), (u8 *)set_data);
}

void TObjEneSlime::spawn_pair() {
    BmlResource *resource = new BmlResource(1, &slime_pair_resource_descriptor, NULL, NULL, NULL);
    slime_bml_resource = resource;
    BmlModelEntry *models = resource->models;
    TObjNpcEnemy::register_chunk(0x28, models[4].model, models[4].texlist, 10.0f, 0.0f);
    models = slime_bml_resource->models;
    TObjNpcEnemy::register_chunk(0x29, models[5].model, models[5].texlist, 10.0f, 0.0f);
}

void TObjEneSlime::free_instance() {
    if (slime_bml_resource != NULL) {
        delete slime_bml_resource;
        slime_bml_resource = NULL;
    }
}

TObjEneSlime::TObjEneSlime(TObject *parent, u8 *set_data) : TObjEnemy(parent) {
    m_name = TObjEneSlime__name;
    apply_set_data(set_data);
    clear_lobby_object_state();
    register_by_id();
    copy_set_entry(&spawn_template, set_data);
    child_limit = *(s16 *)(set_data + 2);
    if (child_limit < 1) {
        if (TObjPlayer::check_demo_mode() != 0) {
            child_limit = 3;
        }
    } else if (child_limit > 4) {
        child_limit = 4;
    }
    actorFlags |= 0x02000000;
    init_slots();
}

TObjEneSlime::~TObjEneSlime() {
    this->release_split_slimes();
}

void TObjEneSlime::run_death_reaction() { this->release_split_slimes(); }

void TObjEneSlime::run_task() {
    s32 enemy_state;

    if ((TObjPlayer::check_demo_mode() == 0) && (has_no_active_slot(this) != 0)) {
        enemy_state = 0x800;
        send_6x0A_enemy_state(&enemy_state);
        exchange_object_state(&enemy_state, (s16)0);
        this->apply_enemy_state(&enemy_state);
        send_entity_set_flags();
        queue_destruction();
    }
}

void TObjEneSlime::render() {
    s32 type_offset;
    s32 model_index;
    s32 deferred;
    deferred = this->defer_render();
    if (TObjPlayer::check_demo_mode() != 0) {
        type_offset = (this->state36C * 4) & 4;
        debug_printf_at(0x130020, "TYPE [0/1] : %s", (int) (*(s32 *)((s8 *)((u8 *)slime_debug_label_table + type_offset) + 0)));
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        model_index = *(s32 *)((s8 *)((u8 *)slime_model_index_by_type + type_offset) + 0);
        post_translate_matrix(&position.x);
        TObjFish::set_global_param(get_bml_texlist(slime_bml_resource, model_index));
        if (deferred != 0) {
            model_render_flags |= 0x400000;
            set_chunk_render_flags(1);
            draw_chunk_object((void *)get_bml_model(slime_bml_resource, model_index));
            clear_chunk_render_flags();
            model_render_flags &= 0xFFBFFFFF;
        } else {
            set_chunk_render_flags(2);
            set_cull_back();
            draw_chunk_object((void *)get_bml_model(slime_bml_resource, model_index));
            set_cull_front();
            draw_chunk_object((void *)get_bml_model(slime_bml_resource, model_index));
            set_cull_none();
            clear_chunk_render_flags();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}

void copy_child_slot(SlimeChildSlot *dst, SlimeChildSlot *src) { *dst = *src; }

void TObjEneSlime::init_slots() {
    s32 i;
    for (i = 0; i < 4; i++) {
        copy_child_slot(&child_slots[i], (SlimeChildSlot *)&slime_empty_child_slot);
    }
    spawn_slime_in_slot(this, 0, NULL, NULL);
}

void TObjEneSlime::release_split_slimes() {
    s32 i;
    for (i = 0; i < 4; i++) {
        SlimeChildSlot *s = &child_slots[i];
        if (s->state == 1) {
            if (s->slime != 0) {
                s->slime->clear_parent_slime();
                s->slime = 0;
            }
            s->state = 2;
        }
    }
}

s32 has_no_active_slot(TObjEneSlime *self) {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (self->child_slots[i].state == 1) {
            return 0;
        }
    }
    return 1;
}

s32 spawn_slime_in_slot(TObjEneSlime *origin, s32 index, Vec *position, Vec *velocity) {
    SlimeSpawnTemplate t;
    SlimeChildSlot *slot;
    s32 n;
    if (index < 0 || index >= origin->child_limit || origin->child_slots[index].state != 0) {
        return 0;
    }
    t = origin->spawn_template;
    n = index + 1;
    t.entry.set_index = origin->spawn_template.entry.set_index + n;
    t.entry.child_count = 0;
    t.entry.entity_id = origin->spawn_template.entry.entity_id + n;
    if (position == NULL) {
        VecCopy(&t.entry.position, &origin->position);
    } else {
        VecCopy(&t.entry.position, position);
    }
    slot = &origin->child_slots[index];
    if (velocity == 0) {
        slot->slime = (TObjEneSlimeOne *)TObjEneSlimeOne::create((saddr)origin, (saddr)&t);
    } else {
        slot->slime = (TObjEneSlimeOne *)TObjEneSlimeOne::create((saddr)origin, (saddr)&t, (saddr)velocity);
    }
    if (slot->slime == NULL) {
        return 0;
    }
    slot->state = 1;
    return 1;
}

void TObjEneSlime::release_child_slot(s32 id) {
    s32 i = id - entity_id - 1;
    if (i < 0 || i >= 4 || child_slots[i].state != 1) {
        return;
    }
    child_slots[i].slime = 0;
    child_slots[i].state = 2;
}


s32 TObjEneSlime::try_spawn_child(void *position) {
    s32 i;
    Vec pos;
    Vec dir;
    s32 ang;
    s32 n;
    n = child_limit;
    for (i = 0; i < n && child_slots[i].state != 0; i++) {
    }
    if (i == n) {
        return 0;
    }
    VecCopy((Vec *)&pos, (const Vec *)position);
    pos.y += 10.0f;
    ang = (s16) (65535.0f * random_ratio());
    dir.x = sin_table_lookup(ang);
    dir.y = 0.0f;
    dir.z = cos_table_lookup(ang);
    if (vector_length(&dir) <= 0.01f) {
        dir.x = 1.0f;
        dir.y = 0.0f;
        dir.z = 0.0f;
    } else {
        normalize_vector(&dir);
    }
    play_sound_effect(0x4003A619, &pos, 0, 0);
    return spawn_slime_in_slot(this, i, &pos, &dir);
}

#pragma push
saddr TObjEneSlimeOne::create(saddr owner, saddr set_data) {
    return (saddr)new TObjEneSlimeOne(new TObjControl(tl_04), (TObjEneSlime *)owner, (void *)set_data);
}
#pragma pop

#pragma push

saddr TObjEneSlimeOne::create(saddr owner, saddr set_data, saddr velocity) {
    return (saddr)new TObjEneSlimeOne(new TObjControl(tl_04), (TObjEneSlime *)owner, (void *)set_data, (const Vec *)velocity);
}
#pragma pop

#pragma push

#pragma opt_common_subs off
TObjEneSlimeOne::TObjEneSlimeOne(TObject *parent, TObjEneSlime *owner, void *set_data)
    : TObjEnemy(parent) {
    SlimeSavedState state;
    m_name = TObjEneSlimeOne_class_name;
    add_flags_2e4(2);
    apply_set_data(set_data);
    if (exchange_object_state(&state, 1) != 0) {
        state.flags = 0;
        state.unknown6 = 0;
        exchange_object_state(&state, 0);
    }
    parent_slime = owner;
    initialize_slime_instance_state();
    project_actor_to_ground(this, &position, 0);
    set_state(0);
}
#pragma pop

#pragma push

#pragma opt_common_subs off
TObjEneSlimeOne::TObjEneSlimeOne(TObject *parent, TObjEneSlime *owner, void *set_data, const Vec *velocity)
    : TObjEnemy(parent) {
    SlimeSavedState state;
    m_name = TObjEneSlimeOne_class_name;
    add_flags_2e4(2);
    apply_set_data(set_data);
    if (exchange_object_state(&state, 1) != 0) {
        state.flags = 0;
        state.unknown6 = 0;
        exchange_object_state(&state, 0);
    }
    parent_slime = owner;
    VecCopy(&launch_velocity, velocity);
    initialize_slime_instance_state();
    set_state(14);
}
#pragma pop

void TObjEneSlimeOne::initialize_slime_instance_state() {
    TObjEneSlimeOne *actor = this;
    actor->model_archive = TObjEneSlimeOne::get_instance();
    if (actor->random_ratio() < 0.002f || (actor->state36C & 1)) {
        actor->variant = 1;
    } else {
        actor->variant = 0;
    }

    s32 *variant = &actor->variant;
    s32 id = ((s32 *)slime_one_model_by_variant)[*variant];
    actor->texlist = get_bml_texlist(actor->model_archive, id);
    actor->model = get_bml_model(actor->model_archive, id);
    VecCopy(&actor->prev_position, VecCopy(&actor->home_position, VecCopy(&actor->center, &actor->position)));
    actor->collision_body_parts = init_collision_body_parts(actor, slime_one_collision_body, 1);
    actor->set_action_table(slime_motion_action_table);
    actor->set_motion_list(actor->model_archive->motions);
    actor->set_animation(0);
    actor->set_requested_action(0);
    VecCopy(&actor->body_center, &actor->position);
    actor->velocity.z = 0.0f;
    actor->velocity.y = 0.0f;
    actor->velocity.x = 0.0f;
    actor->target = NULL;
    if (*variant == 0) {
        actor->bind_enemy_combat_stats(TLobby::register_boss(0x30), TLobby::dispatch_shared_handler_b(0x30),
                                      TLobby::register_object(0x30));
    } else {
        actor->bind_enemy_combat_stats(TLobby::register_boss(0x34), TLobby::dispatch_shared_handler_b(0x34),
                                      TLobby::register_object(0x34));
    }
    actor->referenceHp = actor->hp;
    actor->register_by_id();
    actor->movementParameters = NULL;
    if (*variant == 0) {
        actor->set_param(0x13);
    } else {
        actor->set_param(0x14);
    }
    actor->animation = new SlimeAnimationState(actor);
    actor->particle = NULL;
    actor->target_client_id = 0xFFFF;
    actor->copy_position();
}

TObjEneSlimeOne::~TObjEneSlimeOne() {
    free_collision_body_parts(this);
    this->collision_body_parts = NULL;
    if (this->particle != NULL) {
        TParticleCtrl::release(this->particle);
        this->particle = NULL;
    }
    delete animation;
    animation = NULL;
}

void TObjEneSlimeOne::run_task() {
    if (TObjPlayer::check_demo_mode() == 0) {
        if ((s32)this->state != 13 && (this->parent_slime == 0 || parent_slime->all_parents_unqueued_for_destruction() == 0)) {
            set_state(13);
        }
        set_target_flag_bit0();
        {
            SlimeOneState *tbl = slime_one_state_table;
            SlimeOneStateFn a = tbl[this->state].update;
            if (a != 0) {}
            (this->*a)();
        }
        update_prev_position();
        update_collisions();
        if ((s32)this->targetable != 0) {
            submit_cursor_candidate(this, -1);
        }
        animation->advance();
        play_persistent_sound(0x4003B21C, this, &position, 0, 0);
        update_trail_position();
        clear_child_flag();
        if ((s32)this->state != 13) {
            minimap_render_dot(&body_center, -0x5DB4, 1, 0);
        }
    }
}
void TObjEneSlimeOne::render() {
    TObjEneSlimeOne *ene_slime_one = this;
    s32 deferred;
    if ((TObjPlayer::check_demo_mode() == 0) && !(ene_slime_one->alpha <= 0.0f) && (((TObjEneSlimeOne *)(ene_slime_one))->update_object_view_visibility(500.0f, 20.0f) != 0)) {
        deferred = ene_slime_one->defer_render();
        if (ene_slime_one->alpha < 1.0f) {
            push_material_fade(ene_slime_one->alpha);
        }
        TObjPlayer::toggle_particle_effect();
        push_matrix();
        {
            Vec v = ene_slime_one->position;
            v.y += ene_slime_one->draw_offset_y;
            post_translate_matrix(&v.x);
        }
        rotate_matrix_y(0, ene_slime_one->rotation_y);
        scale_matrix_vec3(0, (u8 *)&ene_slime_one->draw_scale);
        ene_slime_one->animation->draw(deferred);
        pop_matrix();
        TParticleCtrl::end_effect_render();
        if (ene_slime_one->alpha < 1.0f) {
            TObjPlayer::init_render_globals();
        }
        ene_slime_one->render_trail();
    }
}

void TObjEneSlimeOne::set_state(s32 new_state) {
    this->state = new_state;
    SlimeOneStateFn a = slime_one_state_table[this->state].enter;
    if (a != 0) {}
    (this->*a)();
}

void TObjEneSlimeOne::set_random_timer(s32 minimum, s32 range) {
    state_timer = minimum + (s32)((f32)range * random_ratio());
}
s32 TObjEneSlimeOne::project_to_ground() {
    Vec sp = position;
    sp.y += 5.0f;
    if (project_actor_to_ground(this, &sp, 0) != 0) {
        position.y += 0.5f * (sp.y - position.y);
        return 1;
    }
    return 0;
}

void TObjEneSlimeOne::set_display_mode(s32 mode) {
    collision_body_parts->flags &= 0xF5FFF297;
    switch (mode) {
    case 0:
        collision_body_parts->flags |= 0x0A000000 | 0x528;
        targetable = 0;
        return;
    case 1:
        collision_body_parts->flags |= 0x0A000000 | 0x28;
        targetable = 0;
        return;
    case 2:
        targetable = 1;
        return;
    }
}

void TObjEneSlimeOne::set_target_flag_bit0() {
    collision_body_parts->flags |= 1;
}

void TObjEneSlimeOne::clear_child_flag() {
    if ((s32) this->targetable == 0) {
        collision_body_parts->flags &= ~1;
    }
}

f32 TObjEneSlimeOne::receive_direct_attack(void *attacker, DirectAttackPayload payload,
                                         void *source, s32, s32) {
    if (payload.kind == 2 && parent_slime != 0 &&
        parent_slime->all_parents_unqueued_for_destruction()) {
        parent_slime->try_spawn_child(&position);
    }
    TObjChara::receive_direct_attack(attacker, payload, source, -1, -1);
    return 0.0f;
}

void TObjEneSlimeOne::run_death_reaction() { if ((s32) this->state != 13) { set_state(13); } }

void TObjEneSlimeOne::run_hit_reaction() {
    if ((s32) this->state != 0xC) {
        TObjPlayer *player;
        if (((s32) this->attacker_id < (s32) registered_player_count) && ((player = get_player_by_client_id(attacker_id)) != NULL) && (player->get_attack_stage() == 2) && (parent_slime != NULL) && (parent_slime->all_parents_unqueued_for_destruction() != 0)) {
            parent_slime->try_spawn_child((u8 *)&this->position);
        }
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFDFF);
        set_state(0xC);
    }
}

void TObjEneSlimeOne::run_miss_reaction() {
    if ((s32) this->state != 0xB) {
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFEFF);
        set_state(0xB);
    }
}

void TObjEneSlimeOne::set_random_timer_15() { set_random_timer(15, 15); }

void TObjEneSlimeOne::init_state() { project_to_ground(); this->draw_offset_y = -2.5f; this->draw_scale.z = 0.0f; this->draw_scale.y = 0.0f; this->draw_scale.x = 0.0f; this->alpha = 0.0f; this->search_count = 0; animation->set_state(7); set_display_mode(0); this->actorFlags = (this->actorFlags | 0x40000); this->set_random_timer_15(); }

void TObjEneSlimeOne::update_wait_search() {
    if (--this->state_timer <= 0) {
        if (find_nearest_visible_player(this, NULL, 200.0f) == 0xFFFF) {
            if (++this->search_count >= 5) {
                position.x = home_position.x;
                position.z = home_position.z;
                this->search_count = 5;
            }
            this->set_random_timer_15();
            return;
        }
        this->set_state(1);
    }
}

void TObjEneSlimeOne::reset_display() { set_display_mode(0); this->actorFlags = (this->actorFlags & 0xfffbffff); this->state_value = 0.0f; this->draw_offset_y = -2.5f; }
void TObjEneSlimeOne::update_grow() {
    f32 progress;
    f32 wobble;
    f32 wobble_scale;
    this->draw_offset_y = (f32) (-2.5f * (1.0f - this->state_value));
    this->draw_scale.x = (f32) ((this->state_value * (slime_full_scale.x - slime_puddle_scale.x)) + slime_puddle_scale.x);
    this->draw_scale.y = (f32) ((this->state_value * (slime_full_scale.y - slime_puddle_scale.y)) + slime_puddle_scale.y);
    this->draw_scale.z = (f32) ((this->state_value * (slime_full_scale.z - slime_puddle_scale.z)) + slime_puddle_scale.z);
    wobble_scale = 1.0f;
    progress = this->state_value;
    if (progress > 0.8f) {
        wobble_scale = (1.0f - progress) / 0.19999999f;
    }
    wobble = wobble_scale * (0.1f * sin_table_lookup(this->state_timer << 0xC));
    this->draw_scale.x = (f32) (this->draw_scale.x * (1.0f + wobble));
    this->draw_scale.z = (f32) (this->draw_scale.z * (1.0f - wobble));
    this->state_timer = (this->state_timer + 1);
    progress = this->state_value;
    if (progress >= 0.5f) {
        this->alpha = (f32) 1.0f;
    } else {
        this->alpha = (f32) (2.0f * progress);
    }
    if ((this->state_value += 0.033333335f) > 1.0f) {
        if (find_nearest_visible_player(this, 0, 200.0f) != 0xFFFF) {
            this->set_state(3);
        } else {
            this->set_state(2);
        }
    }
}

void TObjEneSlimeOne::init_slime_display() { this->state_value = 1.0f; this->draw_offset_y = 0.0f; set_display_mode(0); animation->set_state(7); }
void TObjEneSlimeOne::update_shrink() {
    f32 progress;
    f32 wobble;
    f32 wobble_scale;
    this->draw_offset_y = (f32) (-2.5f * (1.0f - this->state_value));
    this->draw_scale.x = (f32) ((this->state_value * (slime_full_scale.x - slime_puddle_scale.x)) + slime_puddle_scale.x);
    this->draw_scale.y = (f32) ((this->state_value * (slime_full_scale.y - slime_puddle_scale.y)) + slime_puddle_scale.y);
    this->draw_scale.z = (f32) ((this->state_value * (slime_full_scale.z - slime_puddle_scale.z)) + slime_puddle_scale.z);
    wobble_scale = 1.0f;
    progress = this->state_value;
    if (progress > 0.8f) {
        wobble_scale = (1.0f - progress) / 0.19999999f;
    }
    wobble = wobble_scale * (0.15f * sin_table_lookup(this->state_timer << 0xA));
    this->draw_scale.x = (f32) (this->draw_scale.x * (1.0f + wobble));
    this->draw_scale.z = (f32) (this->draw_scale.z * (1.0f - wobble));
    this->state_timer = (this->state_timer + 1);
    progress = this->state_value;
    if (progress >= 0.5f) {
        this->alpha = (f32) 1.0f;
    } else {
        this->alpha = (f32) (2.0f * progress);
    }
    if ((this->state_value += -0.011111111f) < 0.0f) {
        this->set_state(0);
    }
}
void TObjEneSlimeOne::enter_slide() {
    s32 angle;
    this->move_speed = (f32) 0.0f;
    if (find_nearest_visible_player(static_cast<TObjChara *>(this), &movement_direction, 200.0f) == 0xFFFF) {
        this->set_state(2);
        return;
    }
    angle = (s32) (1048575.0f * this->random_ratio());
    this->movement_direction.x = (f32) ((15.0f * sin_table_lookup(angle)) + this->movement_direction.x);
    this->movement_direction.z = (f32) ((15.0f * cos_table_lookup(angle)) + this->movement_direction.z);
    if (vector_length(&movement_direction) <= 0.01f) {
        this->set_state(2);
        return;
    }
    normalize_vector(&this->movement_direction);
    this->state_value = ((20.0f * this->random_ratio()) + 50.0f);
    this->alpha = (f32) 1.0f;
    this->animation->set_state(8);
    set_display_mode(1);
}
void TObjEneSlimeOne::update_slide() {
    Vec to_player;
    f32 s;
    f32 c;
    f32 accel;  // inferred: the per-frame speed-up added to move_speed
    s32 i;
    s32 ang;
    rotation_y += 0x100;
    if (state_value > 0.0f) {
        motion_phase += 0xC00;
        accel = 0.25f * (0.5f * (0.5f + sin_table_lookup(motion_phase)));
        if ((move_speed += accel) > 2.5f) {
            move_speed = 2.5f;
        }
    } else {
        if ((move_speed -= 0.25f) < 0.0f) {
            move_speed = 0.0f;
        }
    }
    state_value -= move_speed;
    VecCopy(&prev_position, &position);
    for (i = 1; i < 15; i++) {
        position.x += move_speed * movement_direction.x;
        position.y += move_speed * movement_direction.y;
        position.z += move_speed * movement_direction.z;
        if (project_to_ground() != 0 && csnLookAt(&prev_position, &position) == 0) {
            break;
        }
        ang = i << 12;
        if (i & 1) {
            ang *= -1;
        }
        s = sin_table_lookup(ang);
        c = cos_table_lookup(ang);
        movement_direction.x = c * movement_direction.x - s * movement_direction.z;
        movement_direction.z = s * movement_direction.x + c * movement_direction.z;
        VecCopy(&position, &prev_position);
    }
    if (state_value <= 0.0f && 0.0f == move_speed) {
        if (find_nearest_visible_player(this, &to_player, 50.0f) != 0xFFFF && vector_length(&to_player) > 15.0f) {
            set_state(4);
        } else {
            set_state(3);
        }
    }
}

void TObjEneSlimeOne::enter_slime_state() {
    effect_timer = 8;
    animation->set_state(9);
    play_sound_effect(0x4003AD1D, &position, 0, 0);
    set_display_mode(1);
}

void TObjEneSlimeOne::update_slime_timer() {
    if (--effect_timer == 0) {
        spawn_particle_effect(&body_center, 0xCD);
    }
    if (animation->is_finished() == 1) {
        if (this->is_timer_active() != 0) {
            this->set_state(7);
            return;
        }
        this->set_state(6);
    }
}

void TObjEneSlimeOne::enter_appear_state() {
    effect_timer = 0x14;
    play_sound_effect(0x4003AD1D, &position, 0, 0);
    animation->set_state(0xA);
    set_display_mode(1);
}

void TObjEneSlimeOne::update_dive_timer() {
    if (--effect_timer == 0) {
        spawn_particle_effect(&body_center, 0xCD);
    }
    if (animation->is_finished() == 1) {
        this->set_state(3);
    }
}

void TObjEneSlimeOne::enter_scan() {
  unsigned int new_var;
  this->target_client_id = 0xFFFF;
  this->motion_phase = (s32) ((((s32) (4.0f * this->random_ratio())) + 4) << 0x10);
  this->state_timer = 0x7FFFFFFF;
  this->turn_speed = 0x400;
  new_var = 1;
  if (this->random_ratio() > 0.5f)
  {
    this->turn_speed = (s32) ((this->turn_speed) * (-new_var));
  }
  animation->set_state(new_var);
  set_display_mode(2);
}
void TObjEneSlimeOne::update_scan() {
    Vec to_player;
    Vec direction;
    f32 f;
    u16 r;
    s32 n;

    f = sin_table_lookup(this->motion_phase);
    if (f < 0.0f) {
        f = 0.0f;
    }
    this->rotation_y = f * (f32)this->turn_speed + (f32)this->rotation_y;
    if (this->target_client_id == 0xFFFF) {
        r = find_nearest_visible_player(this, &to_player, 162.5f);
        if (r != 0xFFFF &&
            angle_difference_abs(this->rotation_y, (s32)(10430.38043493439 * atan2_float(to_player.x, to_player.z))) < 0x1C71) {
            this->motion_phase = 0;
            this->target_client_id = r;
        }
    }
    this->motion_phase -= 0x600;
    if (this->motion_phase <= 0) {
        n = (f32)(get_bml_motion(model_archive, 10))->frameCount / 0.5f;
        this->motion_phase = 0;
        if (this->target_client_id != 0xFFFF) {
            direction.x = 1.0f;
            direction.y = 0.0f;
            direction.z = 0.0f;
            TObjPlayer::calc_distance_to_client(this, this->target_client_id, &direction);
            this->rotation_y = approach_angle_limited(this->rotation_y, (s32)(10430.38043493439 * atan2_float(direction.x, direction.z)), 0x280);
        }
        if (this->state_timer > n) {
            animation->set_state(0);
            this->state_timer = n;
        } else if (--this->state_timer <= 0) {
            if (this->target_client_id == 0xFFFF) {
                this->set_state(5);
            } else {
                this->set_state(8);
            }
        }
    }
}

void TObjEneSlimeOne::init_slime_state() {
    set_random_timer(0x1E, 0x1E);
    this->turn_speed = 0x888;
    if (random_ratio() > 0.5f) {
        this->turn_speed = this->turn_speed * 0xFFFFFFFF;
    }
    animation->set_state(1);
    set_display_mode(2);
}

void TObjEneSlimeOne::update_aim_at_enemy() {
    Vec sp;
    s32 r = 0;
    s32 t;
    this->rotation_y = this->rotation_y + this->turn_speed;
    if (((TObjEneSlimeOne *)this)->find_nearest_enemy_with_flag(&sp, 500.0f) != 0xFFFF) {
        t = (s32) (10430.38043493439 * atan2_float(sp.x, sp.z));
        if (angle_difference_abs(this->rotation_y, t) < 0x444) {
            this->rotation_y = t;
            r = 1;
        }
    }
    this->state_timer = this->state_timer - 1;
    if (r != 0 || this->state_timer < 0) {
        ((TObjEneSlimeOne *)this)->set_state(9);
    }
}

void TObjEneSlimeOne::enter_approach() { set_random_timer(30, 30); animation->set_state(0); set_display_mode(2); }

void TObjEneSlimeOne::update_approach() {
    Vec v;
    s32 t;
    v.x = 1.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    if (target_client_id != 0xFFFF) {
        TObjPlayer::calc_distance_to_client(this, static_cast<u16>(target_client_id), &v);
    }
    t = (s32) (10430.38043493439 * atan2_float(v.x, v.z));
    rotation_y = approach_angle_limited(rotation_y, t, 0x200);
    if (angle_difference_abs(rotation_y, t) < 0x200) {
        state_timer = 0;
    }
    VecCopy(&prev_position, &position);
    if (vector_length(&v) <= 0.01f) {
        v.x = 1.0f;
        v.y = 0.0f;
        v.z = 0.0f;
    } else {
        normalize_vector(&v);
    }
    v.x *= 0.2f;
    v.y *= 0.2f;
    v.z *= 0.2f;
    vec3_add_to(&position, &v);
    if (project_actor_to_ground(this, &position, 0) == 0 || csnLookAt(&prev_position, &position) != 0) {
        VecCopy(&position, &prev_position);
    }
    if (--state_timer <= 0) {
        if (vector_length(&v) > 50.0f || random_ratio() < 0.45f) {
            set_state(9);
        } else {
            set_state(10);
        }
    }
}

void TObjEneSlimeOne::begin_appear() { this->state_timer = 90; effect_timer = 19; animation->set_state(3); set_display_mode(2); }

void TObjEneSlimeOne::update_water_bomb_timer() {
    s32 timer;

    effect_timer = (s32) (effect_timer - 1);
    timer = effect_timer;
    if (timer > 0) {
        spawn_particle_effect(&body_center, 0xFF);
    } else if (timer == 0) {
        play_sound_effect(0x4003A017, &position, 0, 0);
        spawn_particle_effect(&body_center, 0xE2);
        TObjEneSlimeWaterBomb::create(this, this);
    }
    if (--this->state_timer <= 0) {
        if (this->is_timer_active() != 0) {
            this->set_state(7);
            return;
        }
        this->set_state(5);
    }
}
void TObjEneSlimeOne::start_tail_attack() {
    TObjEneSlimeOne *self = this;
    f32 r;
    s32 ang;
    s32 n;
    f32 len;
    TObjPlayer *target = get_player_by_client_id(target_client_id);
    if (target == NULL || (target->actorFlags & 0x02000800)) {
        self->set_state(5);
        return;
    }
    VecCopy(&self->attack_position, &target->position);
    r = 5.0f * self->random_ratio() + 2.5f;
    ang = 65536.0f * self->random_ratio();
    self->attack_position.x = r * sin_table_lookup(ang) + self->attack_position.x;
    self->attack_position.z = r * cos_table_lookup(ang) + self->attack_position.z;
    Vec dir = self->attack_position;
    subtract_vector(&dir, &self->position);
    len = vector_length(&dir);
    if (0.0f == len) {
        self->set_state(5);
        return;
    }
    n = len / 10.0f;
    if (vector_length(&dir) <= 0.01f) {
        dir.x = 1.0f;
        dir.z = dir.y = 0.0f;
    } else {
        normalize_vector(&dir);
    }
    dir.x *= 10.0f;
    dir.y *= 10.0f;
    dir.z *= 10.0f;
    Vec pos = self->position;
    pos.y += 5.0f;
    while (n > 0) {
        Vec tmp = pos;
        if (project_actor_to_ground(self, &tmp, 0) == 0 || csnLookAt(&self->position, &pos) != 0) {
            self->set_state(9);
            return;
        }
        n--;
        vec3_add_to(&pos, &dir);
    }
    this->state_timer = 0x5A;
    animation->set_state(0);
    play_sound_effect(0x4003A318, &self->attack_position, 0, 0);
    TObjEneSlimeTailAttack::create((saddr)self, &self->attack_position, this->rotation_y, this);
    set_display_mode(2);
}

void TObjEneSlimeOne::tick_timer() {
    if (--this->state_timer <= 0) {
        this->set_state(5);
    }
}

void TObjEneSlimeOne::reset_display_state() { this->draw_scale.z = 1.0f; this->draw_scale.y = 1.0f; this->draw_scale.x = 1.0f; effect_timer = 0; animation->set_state(4); set_display_mode(2); }

void TObjEneSlimeOne::update_tick() {
    s32 timer;

    timer = effect_timer + 1;
    effect_timer = timer;
    if (!(timer & 3)) {
        spawn_particle_effect(&body_center, 0xE0);
    }
    if (this->motion_flags & 0x10) {
        if (this->is_timer_active() != 0) {
            this->set_state(7);
            return;
        }
        this->set_state(6);
    }
}

void TObjEneSlimeOne::init_split_effect() {
    this->draw_scale.z = 1.0f;
    this->draw_scale.y = 1.0f;
    this->draw_scale.x = 1.0f;
    spawn_particle_effect(&body_center, 0xCE);
    play_sound_effect(0x4003A61A, &position, 0, 0);
    animation->set_state(5);
    set_display_mode(0);
}

void TObjEneSlimeOne::update_damage() {
    if (this->motion_flags & 0x10) {
        this->set_state(5);
    }
}

void TObjEneSlimeOne::enter_death() {
    if (parent_slime != NULL && parent_slime->all_parents_unqueued_for_destruction() != 0) {
        parent_slime->release_child_slot(entity_id);
    }
    this->draw_scale.z = 1.0f;
    this->draw_scale.y = 1.0f;
    this->draw_scale.x = 1.0f;
    this->state_timer = 5;
    refresh_lobby_state();
    play_sound_effect(0x4003A81B, &position, 0, 0);
    spawn_particle_effect(&body_center, 0xFE);
    animation->set_state(5);
    set_display_mode(0);
}

void TObjEneSlimeOne::update_effect_fade_lifetime() {
    if ((this->alpha += -0.2f) < 0.0f) {
        this->alpha = 0.0f;
    }
    if (--this->state_timer <= 0) {
        this->queue_destruction();
    }
}
extern "C" {


void TObjEneSlimeOne::enter_launched() {
    this->particle = (TParticleCtrl *)create_particle_emitter(&position, 0xE1);
    this->draw_offset_y = -2.5f;
    this->draw_scale.z = 0.0f;
    this->draw_scale.y = 0.0f;
    this->draw_scale.x = 0.0f;
    this->alpha = 0.0f;
    animation->set_state(7);
    set_display_mode(0);
}
void TObjEneSlimeOne::update_launched() {
    s32 landed = 0;
    s32 tries = 4;
    s32 angle;
    f32 s;
    f32 c;

    this->launch_velocity.y += -0.075f;
    do {
        Vec next;
        Vec probe;
        VecCopy(&next, &this->position);
        vec3_add_to(&next, &this->launch_velocity);
        VecCopy(&probe, &next);
        probe.y += 5.0f + fabs_float(this->launch_velocity.y);
        if (project_actor_to_ground(this, &probe, 0) != 0) {
            VecCopy(&this->position, &next);
            if (!(this->position.y > probe.y)) {
                this->position.y = probe.y;
                landed = 1;
            }
            break;
        }
        s = sin_table_lookup(0x4000);
        c = cos_table_lookup(0x4000);
        this->launch_velocity.x = c * this->launch_velocity.x + s * this->launch_velocity.z;
        this->launch_velocity.z = -s * this->launch_velocity.x + c * this->launch_velocity.z;
    } while (--tries > 0);
    if (tries == 0) {
        Vec probe;
        this->launch_velocity.x = this->launch_velocity.z = 0.0f;
        VecCopy(&probe, &this->position);
        probe.y += 5.0f + fabs_float(this->launch_velocity.y);
        if (project_actor_to_ground(this, &probe, 0) != 0) {
            if (!(this->position.y > probe.y)) {
                this->position.y = probe.y;
                landed = 1;
            }
        } else {
            landed = 1;
        }
    }
    if (this->particle != NULL) {
        ((TParticleCtrl *)this->particle)->set_position(&this->position);
    }
    if (landed != 0) {
        if (this->particle != NULL) {
            TParticleCtrl::release(this->particle);
            this->particle = NULL;
        }
        for (angle = 0; angle < 0xFFFF; angle += 0x1000) {
            Vec p = *&this->position;
            p.x = 12.5f * sin_table_lookup(angle) + p.x;
            p.y += -2.5f;
            p.z = 12.5f * cos_table_lookup(angle) + p.z;
            spawn_particle_effect(&p, 0xE2);
        }
        project_to_ground();
        this->set_state(1);
    }
}

void TObjEneSlimeOne::copy_position() {
    VecCopy(&trail_position, &position);
}

void TObjEneSlimeOne::update_trail_position() {
    Vec delta;
    VecCopy(&delta, &position);
    subtract_vector(&delta, &trail_position);
    delta.x *= 0.025f;
    delta.y *= 0.025f;
    delta.z *= 0.025f;
    vec3_add_to(&trail_position, &delta);
}

void TObjEneSlimeOne::render_trail() {
    TObjEneSlimeOne *self = this;
    Vec c;
    Vec b;
    f32 s;
    s32 ang;
    s32 t;
    s32 w1;
    s32 w0;
    s = 0.5f * self->alpha;
    Vec a = self->position;
    subtract_vector(&a, &self->trail_position);
    a.x *= 0.5f;
    a.y *= 0.5f;
    a.z *= 0.5f;
    VecCopy((Vec *)&c, (const Vec *)&self->trail_position);
    vec3_add_to(&c, &a);
    c.y += -1.125f;
    ang = 10430.38043493439 * atan2_float(a.x, a.z);
    b.x = 1.25f;
    b.y = 0.21428572f;
    b.z = 1.25f * vector_length(&a) / 11.0f;
    if (b.x > b.z) {
        b.x = b.z;
    }
    if (s < 0.05f || b.x < 0.05f) {
        return;
    }
    TObjPlayer::push_material_color_override(s, -1.0f, 0.0f, 1.0f);
    push_matrix();
    post_translate_matrix(&c.x);
    rotate_matrix_y(0, ang);
    scale_matrix_vec3((u8 *)(0), (u8 *)&b);
    t = slime_tail_attack_id_pair[self->variant];
    TObjFish::set_global_param(get_bml_texlist(self->model_archive, t));
    draw_chunk_object(get_bml_model(self->model_archive, t));
    pop_matrix();
    TObjPlayer::init_render_globals();
}
#pragma push
#pragma opt_common_subs off
TObjEneSlimeWaterBomb::TObjEneSlimeWaterBomb(TObjEneSlimeOne *parent, TObjEneSlimeOne *owner)
    : TObjEnemy(parent) {
    f32 s;
    f32 c;
    m_name = TObjEneSlimeWaterBomb__name;
    this->owner = owner;
    this->rotation_y = ((TObjEneSlimeOne *)m_up)->rotation_y;
    VecCopy(&position, &((TObjEneSlimeOne *)m_up)->position);
    s = sin_table_lookup(this->rotation_y);
    c = cos_table_lookup(this->rotation_y);
    position.x += 15.0f * s;
    position.y += 20.0f;
    position.z += 15.0f * c;
    movement.x = 0.6f * s;
    movement.y = 0.0f;
    movement.z = 0.6f * c;
    lifetime = 0.0f;
    particle = (TParticleCtrl *)create_particle_emitter(&position, 0xCF);
    attack_power = *(f32 *)TLobby::dispatch_shared_handler_a(TObjEneSlime__attack_target_param_table[this->owner->get_attack_target()]);
    if (attack_power < 0.0f) {
        attack_power = 0.0f;
    }
    elapsed_frames = 0;
}
#pragma pop

#pragma push

TObjEneSlimeWaterBomb::~TObjEneSlimeWaterBomb() {
    if (particle != NULL) {
        TParticleCtrl::release(particle);
        particle = NULL;
    }
}
#pragma pop

#pragma push

TObjEneSlimeWaterBomb *TObjEneSlimeWaterBomb::create(TObjEneSlimeOne *parent, TObjEneSlimeOne *owner) {
    return new TObjEneSlimeWaterBomb(parent, owner);
}
#pragma pop

#pragma push

void TObjEneSlimeWaterBomb::run_task() {
    s32 die = 0;
    movement.y += -0.05f;
    vec3_add_to(&position, &movement);
    if (++elapsed_frames > 0x14F) {
        die = 1;
    }
    {
        Vec probe = position;
        probe.y += 5.0f;
        if (project_actor_to_ground(this, &probe, &ground_normal) != 0) {
            ground_height = probe.y;
            if (position.y <= ground_height) {
                position.y = ground_height;
                movement.y *= -0.975f;
                spawn_particle_effect(&position, 0xE2);
            }
        } else {
            die = 1;
        }
    }
    if (particle != NULL) {
        particle->set_position(&position);
    }
    if (owner->is_in_water_bomb_states() != 0 || check_hits() != 0) {
        die = 1;
    }
    {
        if ((lifetime += 0.6f) >= 200.0f || die != 0) {
            spawn_particle_effect(&position, 0xE2);
            queue_destruction();
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TObjEneSlimeWaterBomb::render() {
    Vec shadow_scale;
    s32 angle_x;
    s32 angle_z;
    f32 height;
    f32 width;
    push_matrix();
    translate_matrix(0, position.x, 0.1f + ground_height, position.z);
    direction_to_rotation_xz((u8 *)&ground_normal, &angle_x, &angle_z);
    rotate_matrix_z(0, angle_z);
    rotate_matrix_x(0, angle_x + 0x4000);
    height = position.y - ground_height;
    if (height > 40.0f) {
        height = 40.0f;
    } else if (height < 0.0f) {
        height = 0.0f;
    }
    width = 0.65f * (1.0f - height / 40.0f) + 0.1f;
    shadow_scale.x = shadow_scale.y = width;
    shadow_scale.z = 1.0f;
    scale_current_matrix(&shadow_scale.x);
    draw_blob_shadow(0);
    pop_matrix();
}
#pragma pop

#pragma push

s32 TObjEneSlimeWaterBomb::check_hits() {
    s32 hit;
    TObjChara *player;
    TObjChara *enemy;
    DirectAttackPayload attack = {0, 0.0f};
    u16 player_id;
    s32 enemy_id;
    hit = 0;
    attack.power = attack_power;
    VecCopy(&body_center, &position);
    player_id = find_nearest_visible_player(this, 0, 25.0f);
    if (player_id != 0xFFFF) {
        player = get_player_by_client_id(player_id);
        if (player != NULL && !(horizontal_distance_squared(&body_center, &player->body_center) > 25.0f)) {
            f32 damage = player->receive_direct_attack(owner, attack, 0, -1, -1);
            if (0.0f != damage) {
                player->apply_knockback_from_attacker((u8 *)this, damage);
            }
            hit = 1;
        }
    }
    enemy_id = find_nearest_enemy_masked(25.0f);
    if (enemy_id != 0xFFFF) {
        enemy = (TObjChara *)get_enemy_entity(enemy_id);
        if (enemy != NULL && !(horizontal_distance_squared(&body_center, &enemy->body_center) > 25.0f)) {
            f32 damage = enemy->receive_direct_attack(owner, attack, 0, -1, -1);
            if (0.0f != damage) {
                enemy->apply_knockback_from_attacker((u8 *)this, damage);
            }
            hit = 1;
        }
    }
    return hit;
}
#pragma pop

extern "C" const char TObjEneSlimeTailAttack__class_name_string[] = "TObjEneSlimeTailAttack";
#pragma push
TObjEneSlimeTailAttack::TObjEneSlimeTailAttack(TObject *parent, const Vec *position, s32 angle, TObjEneSlimeOne *owner)
    : TObjEnemy(parent) {
    m_name = TObjEneSlimeTailAttack__name;
    this->owner = owner;
    BmlResource *resource = TObjEneSlimeOne::get_instance();
    u32 id = slime_tail_model_by_target[this->owner->get_attack_target()];
    texlist = get_bml_texlist(resource, id);
    model = (void *)get_bml_model(resource, id);
    action_table = slime_motion_action_table;
    set_action_table(slime_motion_action_table);
    motion_list = resource->motions;
    set_motion_list(resource->motions);
    requested_action = 6;
    set_animation(requested_action);
    set_requested_action(requested_action);
    this->rotation_y = angle;
    VecCopy(&this->position, position);
    active = 1;
    last_hit_player = 0xFFFF;
    stretch_scale.x = stretch_scale.y = stretch_scale.z = 1.0f;
    fade = 1.0f;
}
#pragma pop

#pragma push

TObjEneSlimeTailAttack::~TObjEneSlimeTailAttack() {}
#pragma pop

#pragma push

TObjEneSlimeTailAttack *TObjEneSlimeTailAttack::create(saddr, const Vec *position, s32 angle, TObjEneSlimeOne *owner) {
    return new TObjEneSlimeTailAttack(new TObjControl(tl_04), position, angle, owner);
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneSlimeTailAttack::run_task() {
    if (active != 0) {
        apply_tail_hits();
        advance_animation();
        if (this->motion_flags & 0x10) {
            queue_destruction();
            return;
        }
        if (owner->is_in_water_bomb_states() != 0) {
            active = 0;
        }
    } else {
        this->frame += 0.1f * (7.0f - this->frame);
        fade += -0.033333335f;
        position.y += -0.016666668f;
        stretch_scale.x += 0.06666667f;
        stretch_scale.y += -0.031666666f;
        stretch_scale.z += 0.06666667f;
        if (stretch_scale.y <= 0.05f) {
            queue_destruction();
        }
    }
}
#pragma pop

#pragma push

s32 TObjEneSlimeTailAttack::apply_tail_hits() {
    TObjEneSlimeTailAttack *self = this;
    DirectAttackPayload hit;
    s32 result;
    TObjChara *e;
    TObjChara *e2;
    u16 id;
    s32 id2;
    f32 t = self->frame;
    if (t < 17.0f || t > 30.0f) {
        return 0;
    }
    hit.kind = 0;
    result = 0;
    hit.power = *(s16 *)TLobby::register_boss(slime_tail_attack_param_ids[self->owner->get_attack_target()]);
    id = find_nearest_visible_player(self, 0, 25.0f);
    if (id != 0xFFFF && id != self->last_hit_player) {
        e = get_player_by_client_id(id);
        if (e != NULL) {
            TObjPlayer *pl = (TObjPlayer *)e;
            f32 lo = pl->position.y - 5.0f;
            f32 hi = 5.0f + (pl->position.y + pl->base_stats.proportions);
            if (!(self->body_center.y < lo) && !(self->body_center.y > hi) &&
                !(horizontal_distance_squared(&self->body_center, &pl->position) > 56.25f)) {
                f32 damage = e->receive_direct_attack(self->owner, hit, 0, -1, -1);
                if (0.0f != damage) {
                    e->apply_knockback_from_attacker((u8 *)self, damage);
                }
                self->last_hit_player = id;
                result = 1;
            }
        }
    }
    id2 = self->find_nearest_enemy_with_flag(25.0f);
    if (id2 != 0xFFFF) {
        TObjEneSlimeOne *owner = self->owner;
        if (owner == NULL || id2 != (u16)owner->get_entity_id()) {
            e2 = (TObjChara *)get_enemy_entity(id2);
            if (e2 != NULL && !(horizontal_distance_squared(&self->body_center, &e2->body_center) > 56.25f)) {
                f32 damage = e2->receive_direct_attack(self->owner, hit, 0, -1, -1);
                if (0.0f != damage) {
                    e2->apply_knockback_from_attacker((u8 *)self, damage);
                }
                result = 1;
            }
        }
    }
    return result;
}
#pragma pop

#pragma push
#pragma dont_inline off
void TObjEneSlimeTailAttack::render() {
  f32 frame;
  f32 segment_frames;
  draw_body();
  if (active != 0)
  {
    frame = this->frame;
    segment_frames = 7.0f;
    if (frame < segment_frames)
    {
      draw_stretched_segment(&owner->position, &position, (f32) (frame / segment_frames));
    }
    else
      if ((frame >= 41.0f) && (frame < 48.0f))
    {
      draw_stretched_segment(&position, &owner->position, (f32) ((frame - 41.0f) / segment_frames));
    }
  }
  frame = this->frame;
  if ((frame >= 12.0f) && (frame < 35.0f))
  {
    draw_blob_shadows();
  }
}
#pragma pop

#pragma push
#pragma dont_inline off
void TObjEneSlimeTailAttack::draw_body() {
    u8 *self = (u8 *)this;
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, (int) (this->rotation_y));
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
    if (active != 0) {
        reset_slime_tail_node_index();
        set_chunk_model_node_callback(capture_slime_tail_node);
        ((TObjMotion *)self)->draw();
        set_chunk_model_node_callback(NULL);
        get_slime_tail_pose(&pose);
        VecCopy(&body_center, &pose.attachment);
    } else {
        push_material_fade((f32) fade);
        scale_matrix_vec3(0, (u8 *)&stretch_scale);
        reset_slime_tail_node_index();
        set_chunk_model_node_callback(capture_slime_tail_node);
        ((TObjMotion *)self)->draw();
        set_chunk_model_node_callback(NULL);
        get_slime_tail_pose(&pose);
        VecCopy(&body_center, &pose.attachment);
        TObjPlayer::init_render_globals();
    }
    pop_matrix();
}
#pragma pop

void TObjEneSlimeTailAttack::draw_stretched_segment(Vec *from, Vec *to, f32 t) {
    f32 len;
    f32 k;
    f32 saved;
    Vec d;
    VecCopy(&d, to);
    subtract_vector(&d, from);
    len = vector_length(&d);
    push_matrix();
    k = 0.5f * (1.0f + t);
    {
        Vec p = *from;
        p.x += k * d.x;
        p.y += k * d.y + -0.5f;
        p.z += k * d.z;
        post_translate_matrix(&p.x);
    }
    rotate_matrix_y(0, (s32)(10430.38043493439 * atan2_float(d.x, d.z)));
    {
        f32 r = 1.0f - t;
        scale_matrix(0, 1.0f, 0.5f, r * len / 10.0f);
    }
    TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
    push_material_fade(0.10000001f * t + 0.05f);
    saved = this->frame;
    this->frame = 7.0f;
    this->draw();
    this->frame = saved;
    TObjPlayer::init_render_globals();
    pop_matrix();
}
void TObjEneSlimeTailAttack::draw_blob_shadows() {
    s32 i;
    f32 k;
    s32 angle_x;
    s32 angle_z;
    k = 10.0f;
    for (i = 0; i < 4; i++) {
        Vec v = pose.shadows[i];
        Vec normal;
        v.y += k;
        if (project_actor_to_ground(this, &v, &normal) != 0) {
            push_matrix();
            translate_matrix(0, v.x, 0.1f + v.y, v.z);
            direction_to_rotation_xz((u8 *)&normal, &angle_x, &angle_z);
            rotate_matrix_z(0, angle_z);
            rotate_matrix_x(0, angle_x + 0x4000);
            scale_matrix(0, 0.75f, 0.75f, 0.75f);
            draw_blob_shadow(0);
            pop_matrix();
        }
    }
}
void reset_slime_tail_node_index(void) { slime_tail_node_index = 0; }
void capture_slime_tail_node(NJS_OBJECT *) {
    if (slime_tail_node_index == 7) {
        TCameraCtrl::transform_to_view(&slime_tail_attack_zero_vec, &slime_tail_node_capture.pose.attachment);
    }
    if (slime_tail_node_index >= 4 && slime_tail_node_index < 8) {
        TCameraCtrl::transform_to_view(&slime_tail_attack_transform, &slime_tail_node_capture.pose.shadows[slime_tail_node_index - 4]);
    }
    slime_tail_node_index += 1;
}
SlimeTailPose *copy_slime_tail_pose(SlimeTailPose *dst, SlimeTailPose *src) {
    *dst = *src;
    return dst;
}

void get_slime_tail_pose(SlimeTailPose *dst) {
    copy_slime_tail_pose(dst, &slime_tail_node_capture.pose);
}
}

#undef slime_tail_attack_id_pair
#undef TObjEneSlime__attack_target_param_table
