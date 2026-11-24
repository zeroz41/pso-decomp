#include "types.h"
#include <string.h>
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/boss/volopt/TBoss3VoloptHiraisin.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/system/MatrixStack.h"
#include "pso/enemy/stelth/TObjEneMe3Stelth.h"
#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/render/GinjaTextureMatrices.h"

#pragma readonly_strings on

CollisionBody TObjNpcEnemy::collision_body_parts = {{0.0f, 7.5f, 0.0f}, 7.0f, 0.0f, 0, 0x30203, {0.0f, 0.0f, 0.0f}, 0.0f};
const char *TObjNpcEnemy::name = "TObjNpcEnemy";

void TObjNpcEnemyEntry::reset() {
    id = 0;
    kind = 4;
    y_offset = 0.0f;
    model = 0;
    texlist = 0;
    radius = 0.0f;
    animation.motions = NULL;
    animation.actions = NULL;
    animation.default_action = 0;
    animation.mode2_action = 0;
    animation.debug_action_limit = 0;
}

void TObjNpcEnemy::register_animated_ginja(s16 id, NJS_OBJECT *model, NJS_TEXLIST *texlist,
                                              const NpcAnimationBinding *animation, f32 radius, f32 y_offset) {
    TObjNpcEnemyEntry *entry = insert_slot_by_id(id);
    if (entry != NULL) {
        entry->id = id;
        entry->kind = 3;
        entry->y_offset = y_offset;
        entry->model = model;
        entry->texlist = texlist;
        entry->radius = radius;
        entry->animation = *animation;
    }
}

#pragma push
#pragma scheduling off
NpcAnimationBinding &NpcAnimationBinding::operator=(const NpcAnimationBinding &other) {
    motions = other.motions;
    actions = other.actions;
    default_action = other.default_action;
    mode2_action = other.mode2_action;
    debug_action_limit = other.debug_action_limit;
    return *this;
}
#pragma pop

void TObjNpcEnemy::register_ginja(s16 id, NJS_OBJECT *model, NJS_TEXLIST *texlist, f32 radius, f32 y_offset) {
    TObjNpcEnemyEntry *entry = insert_slot_by_id(id);
    if (entry != NULL) {
        entry->id = id;
        entry->kind = 2;
        entry->y_offset = y_offset;
        entry->model = model;
        entry->texlist = texlist;
        entry->radius = radius;
        entry->animation.motions = 0;
        entry->animation.actions = 0;
        entry->animation.default_action = 0;
        entry->animation.mode2_action = 0;
        entry->animation.debug_action_limit = 0;
    }
}

void TObjNpcEnemy::register_animated_chunk(s16 id, NJS_OBJECT *model, NJS_TEXLIST *texlist,
                                               const NpcAnimationBinding *animation, f32 radius, f32 y_offset) {
    TObjNpcEnemyEntry *entry = insert_slot_by_id(id);
    if (entry != NULL) {
        entry->id = id;
        entry->kind = 1;
        entry->y_offset = y_offset;
        entry->model = model;
        entry->texlist = texlist;
        entry->radius = radius;
        entry->animation = *animation;
    }
}

void TObjNpcEnemy::register_chunk(s16 id, NJS_OBJECT *model, NJS_TEXLIST *texlist, f32 radius, f32 y_offset) {
    TObjNpcEnemyEntry *entry = insert_slot_by_id(id);
    if (entry != NULL) {
        entry->id = id;
        entry->kind = 0;
        entry->y_offset = y_offset;
        entry->model = model;
        entry->texlist = texlist;
        entry->radius = radius;
        entry->animation.motions = 0;
        entry->animation.actions = 0;
        entry->animation.default_action = 0;
        entry->animation.mode2_action = 0;
        entry->animation.debug_action_limit = 0;
    }
}

TObjNpcEnemyEntry *TObjNpcEnemy::get_entry_by_index(s16 index) {
    TObjNpcEnemyEntry *entry;
    if (index < 0) {
        return NULL;
    }
    if (index >= 0x10) {
        return NULL;
    }
    entry = &entry_table[index];
    if (entry->id == 0) {
        return NULL;
    }
    return entry;
}

TObjNpcEnemyEntry *TObjNpcEnemy::insert_slot_by_id(s16 id) {
    s32 i;
    TObjNpcEnemyEntry *e;
    for (i = 0; i < 0x10; i++) {
        e = &entry_table[i];
        if (e->id == 0) {
            return e;
        }
        if (e->id >= id) {
            if (e->id == id) {
                return NULL;
            }
            break;
        }
    }
    if (i >= 0x10) {
        return NULL;
    }
    if (entry_table[15].id != 0) {
        return NULL;
    }
    if (i < 0xF) {
        memmove(e + 1, e, (0xF - i) * sizeof(TObjNpcEnemyEntry));
    }
    e->reset();
    return e;
}

void TObjNpcEnemy::reset_all_anim_fields() {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        entry_table[i].reset();
    }
}

s32 TObjNpcEnemy::is_not_jungle_grass() {
    return (this->entry->id != 0x3F) ? 1 : 0;
}

void TObjNpcEnemy::request_action(s32) {
    TObjNpcEnemyEntry *entry = this->entry;
    if ((s16) this->mode != 2) {
        this->requested_action = entry->animation.default_action;
        return;
    }
    this->requested_action = entry->animation.mode2_action;
}


void TObjNpcEnemy::set_npc_data(TObjNpcEnemyEntry *data) {
    TObjNpcEnemyEntry *entry;

    this->entry = data;
    entry = this->entry;
    if (entry == NULL) {
        this->model = 0;
        this->texlist = 0;
        this->requested_action = 0;
        this->bodies->radius = 0.0f;
        return;
    }
    this->model = entry->model;
    this->texlist = this->entry->texlist;
    this->requested_action = entry->animation.default_action;
    switch (this->entry->kind) {
    case 0:
    case 2:
    case 4:
        break;
    case 1:
    case 3:
        init_motion(entry->animation.actions, entry->animation.motions, requested_action);
        break;
    }
    this->bodies->radius = this->entry->radius;
}

void TObjNpcEnemy::draw_debug_info() {
    TObjNpcEnemyEntry *p;
    TObjNpcBase::draw_debug_info();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130018, "<- ENEMY NUMBER");
    debug_printf_at(0x13001A, "<- MOTION TEST");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    p = TObjNpcEnemy::get_entry_by_index((s16) this->rotation_x);
    if (p != this->entry) {
        set_npc_data(p);
    }
    p = this->entry;
    if (p == NULL) {
        TObjNpcEnemy::set_global_count(0xFF0000FF);
        debug_printf_at(0x240018, "ERROR");
        TObjNpcEnemy::set_global_count(0xF0F0F0FF);
        return;
    }
    switch (p->kind) {
    case 0:
    case 2:
    case 4:
        break;
    case 1:
    case 3:
        if (p->animation.debug_action_limit <= this->rotation_z || this->rotation_z < 0) {
            TObjNpcEnemy::set_global_count(0xFF0000FF);
            debug_printf_at(0x24001A, "ERROR");
            TObjNpcEnemy::set_global_count(0xF0F0F0FF);
            this->requested_action = 0;
        } else {
            this->requested_action = this->rotation_z;
        }
        advance_animation();
        break;
    }
}

void TObjNpcEnemy::update_state() {
    TObjNpcEnemyEntry *entry = this->entry;

    switch (entry->kind) {
    case 0:
        set_motion_packed_rotation();
        draw_chunk_object(this->model);
        set_default_alpha_blend();
        clear_motion_packed_rotation();
        return;
    case 1:
        draw();
        return;
    case 2:
        set_motion_packed_rotation();
        draw_ginja_object(this->model);
        set_default_alpha_blend();
        clear_motion_packed_rotation();
        return;
    case 3:
        draw_ginja_motion_model();
    case 4:
        return;
    }
}

void TObjNpcEnemy::render() {
    TObjNpcEnemyEntry *entry;

    if ((this->entry != NULL) && (this->update_object_view_visibility(this->view_distance, this->view_radius) != 0) && ((s32) this->visible == 1)) {
        select_actor_lighting(this);
        if (is_not_jungle_grass() != 0) {
            model_render_flags |= 1;
        }
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->texlist));
        push_matrix_from(0);
        translate_matrix_vec3(0, ((u8 *)&this->position));
        entry = this->entry;
        translate_matrix(0, 0.0f, entry->y_offset, 0.0f);
        rotate_matrix_y(0, this->rotation_y);
        update_state();
        pop_matrix();
        if (is_not_jungle_grass() != 0) {
            model_render_flags &= ~1;
        }
        restore_scene_lighting();
        draw_ground_shadow(0, 0);
    }
}

TObjNpcEnemy::~TObjNpcEnemy() {}


TObjNpcEnemy::TObjNpcEnemy(TObject *parent, void *set_data) : TObjNpcBase(parent) {
    m_name = name;
    apply_set_data(set_data);
    init_position_vectors();
    apply_set_params(0, 1);
    movementParameters = &npc_movement_parameters;
    set_motion_params(&npc_default_battle_stats);
    init_collision_body_parts(this, &collision_body_parts, 1);
    register_object_by_id();
    update_prev_position();
    copy_position();
    set_npc_data(get_entry_by_index((s16)rotation_x));
}

void *TObjNpcEnemy::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcEnemy(control, set_data);
}


TObjNpcEnemyEntry TObjNpcEnemy::entry_table[16];
