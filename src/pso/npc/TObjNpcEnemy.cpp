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
#include "pso/enemy/slime/TObjEneSlime.h"
#include "pso/enemy/stelth/TObjEneMe3Stelth.h"
#include "pso/object/TMotorcycle.h"
#include "pso/unk/TLobby.h"

#pragma readonly_strings on

CollisionBody TObjNpcEnemy__collision_body_parts = {{0.0f, 7.5f, 0.0f}, 7.0f, 0.0f, 0, 0x30203, {0.0f, 0.0f, 0.0f}, 0.0f};
const char *TObjNpcEnemy_class_name = "TObjNpcEnemy";

extern "C" {
s32 TObjNpcBase__ct(void *);
s32 init_collision_body_parts(void *, void *, int);
struct NpcDefaultBattleStats { s32 value; u8 remaining[0x20]; };
extern NpcDefaultBattleStats npc_default_battle_stats;
struct NpcMovementParameters { s32 value; u8 remaining[0x44]; };
extern NpcMovementParameters npc_movement_parameters;
extern s32 __vt__12TObjNpcEnemy[];
u8 *TObjNpcEnemy__ct(u8 *arg0, s32 arg1, saddr arg2);
s32 draw_debug_info__11TObjNpcBaseFv();
void debug_printf_at(s32, const char *, ...);
void * TObjNpcEnemy__create(void *arg0);
void *__ct__11TObjControlFP7TObject(void *, void *);
s32 rotate_matrix_y(int, int);
s32 translate_matrix(int, int, f32, f32, f32);
s32 init_motion__10TObjMotionFP16TObjMotionActionP14BmlMotionEntrys(void *, s32, s32, s16);

}

// Called on TObjNpcEnemy__entry_table slots rather than on objects; the symbol's
// owner is kept as the tree has it until evidence names the slot type.
void TObjNpcEnemy::reset_anim_fields() {
    TObjNpcEnemyEntry *entry = (TObjNpcEnemyEntry *)this;
    entry->id = 0;
    entry->kind = 4;
    entry->y_offset = 0.0f;
    entry->model = 0;
    entry->texlist = 0;
    entry->radius = 0.0f;
    entry->motion.motion_entry = 0;
    entry->motion.motion_action = 0;
    entry->motion.action = 0;
    entry->motion.action_mode2 = 0;
    entry->motion.action_count = 0;
}

void TObjEneMe3Stelth::spawn_attack(s16 id, s32 model, s32 texlist, s32 motion, f32 radius, f32 y_offset) {
    TObjNpcEnemyEntry *entry = TObjNpcEnemy::insert_slot_by_id(id);
    if (entry != NULL) {
        entry->id = id;
        entry->kind = 3;
        entry->y_offset = y_offset;
        entry->model = model;
        entry->texlist = texlist;
        entry->radius = radius;
        copy_position_data(&entry->motion, (void *)motion);
    }
}

void copy_position_data(void *dst, void *src) {
    TObjNpcEnemyEntryMotion *to = (TObjNpcEnemyEntryMotion *)dst;
    TObjNpcEnemyEntryMotion *from = (TObjNpcEnemyEntryMotion *)src;
    to->motion_entry = from->motion_entry;
    to->motion_action = from->motion_action;
    to->action = from->action;
    to->action_mode2 = from->action_mode2;
    to->action_count = from->action_count;
}

void TMotorcycle::add_entry(s16 id, s32 model, s32 texlist, f32 radius, f32 y_offset) {
    TObjNpcEnemyEntry *entry = TObjNpcEnemy::insert_slot_by_id(id);
    if (entry != NULL) {
        entry->id = id;
        entry->kind = 2;
        entry->y_offset = y_offset;
        entry->model = model;
        entry->texlist = texlist;
        entry->radius = radius;
        entry->motion.motion_entry = 0;
        entry->motion.motion_action = 0;
        entry->motion.action = 0;
        entry->motion.action_mode2 = 0;
        entry->motion.action_count = 0;
    }
}

void TLobby::spawn_npc_enemy(s16 id, s32 model, NJS_TEXLIST *texlist, void *motion, f32 radius, f32 y_offset) {
    TObjNpcEnemyEntry *entry = TObjNpcEnemy::insert_slot_by_id(id);
    if (entry != NULL) {
        entry->id = id;
        entry->kind = 1;
        entry->y_offset = y_offset;
        entry->model = model;
        entry->texlist = (saddr)texlist;
        entry->radius = radius;
        copy_position_data(&entry->motion, motion);
    }
}

void TObjEneSlime::spawn_child(s16 id, s32 model, s32 texlist, f32 radius, f32 y_offset) {
    TObjNpcEnemyEntry *entry = TObjNpcEnemy::insert_slot_by_id(id);
    if (entry != NULL) {
        entry->id = id;
        entry->kind = 0;
        entry->y_offset = y_offset;
        entry->model = model;
        entry->texlist = texlist;
        entry->radius = radius;
        entry->motion.motion_entry = 0;
        entry->motion.motion_action = 0;
        entry->motion.action = 0;
        entry->motion.action_mode2 = 0;
        entry->motion.action_count = 0;
    }
}

TObjNpcEnemyEntry *TObjNpcEnemy::get_entry_by_index(s16 arg0) {
    TObjNpcEnemyEntry *entry;
    if (arg0 < 0) {
        return NULL;
    }
    if (arg0 >= 0x10) {
        return NULL;
    }
    entry = &TObjNpcEnemy__entry_table[arg0];
    if (entry->id == 0) {
        return NULL;
    }
    return entry;
}

TObjNpcEnemyEntry *TObjNpcEnemy::insert_slot_by_id(s16 arg0) {
    s32 i;
    TObjNpcEnemyEntry *e;
    for (i = 0; i < 0x10; i++) {
        e = &TObjNpcEnemy__entry_table[i];
        if (e->id == 0) {
            return e;
        }
        if (e->id >= arg0) {
            if (e->id == arg0) {
                return NULL;
            }
            break;
        }
    }
    if (i >= 0x10) {
        return NULL;
    }
    if (TObjNpcEnemy__entry_table[15].id != 0) {
        return NULL;
    }
    if (i < 0xF) {
        memmove(e + 1, e, (0xF - i) * sizeof(TObjNpcEnemyEntry));
    }
    ((TObjNpcEnemy *)e)->reset_anim_fields();
    return e;
}

void TObjNpcEnemy::reset_all_anim_fields() {
    s32 i;
    for (i = 0; i < 0x10; i++) {
        ((TObjNpcEnemy *)&TObjNpcEnemy__entry_table[i])->reset_anim_fields();
    }
}

s32 TObjNpcEnemy::sub_802D7444() {
    return (this->entry->id != 0x3F) ? 1 : 0;
}

void TObjNpcEnemy::request_action(s32) {
    TObjNpcEnemyEntry *entry = this->entry;
    if ((s16) this->mode != 2) {
        this->requested_action = entry->motion.action;
        return;
    }
    this->requested_action = entry->motion.action_mode2;
}


void TObjNpcEnemy::set_npc_data(void *data) {
    TObjNpcEnemyEntry *entry;

    this->entry = (TObjNpcEnemyEntry *)data;
    entry = this->entry;
    if (entry == NULL) {
        this->model = 0;
        this->texlist = 0;
        this->requested_action = 0;
        *(f32 *)((s8 *)this->bodies + 0xC) = 0.0f;
        return;
    }
    *(s32 *)&this->model = entry->model;
    this->texlist = this->entry->texlist;
    this->requested_action = entry->motion.action;
    switch (this->entry->kind) {
    case 0:
    case 2:
    case 4:
        break;
    case 1:
    case 3:
        init_motion__10TObjMotionFP16TObjMotionActionP14BmlMotionEntrys(this, entry->motion.motion_action, entry->motion.motion_entry, this->requested_action);
        break;
    }
    *(f32 *)((s8 *)this->bodies + 0xC) = this->entry->radius;
}

void TObjNpcEnemy::draw_debug_info() {
    u8 *arg0 = (u8 *)this;
    TObjNpcEnemyEntry *p;
    draw_debug_info__11TObjNpcBaseFv();
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x130018, "<- ENEMY NUMBER");
    debug_printf_at(0x13001A, "<- MOTION TEST");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
    p = TObjNpcEnemy::get_entry_by_index((s16) this->rotation_x);
    if (p != this->entry) {
        ((TObjNpcEnemy *)arg0)->set_npc_data(p);
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
        if (p->motion.action_count <= this->rotation_z || this->rotation_z < 0) {
            TObjNpcEnemy::set_global_count(0xFF0000FF);
            debug_printf_at(0x24001A, "ERROR");
            TObjNpcEnemy::set_global_count(0xF0F0F0FF);
            this->requested_action = 0;
        } else {
            this->requested_action = this->rotation_z;
        }
        ((TObjMotion *)arg0)->advance_animation();
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

extern s32 model_render_flags;

void TObjNpcEnemy::render() {
    u8 *arg0 = (u8 *)this;
    TObjNpcEnemyEntry *entry;

    if ((this->entry != NULL) && (this->update_object_view_visibility(this->m_398, this->m_39c) != 0) && ((s32) this->m_390 == 1)) {
        select_actor_lighting((saddr)arg0);
        if (((TObjNpcEnemy *)arg0)->sub_802D7444() != 0) {
            model_render_flags |= 1;
        }
        TObjFish::set_global_param(this->texlist);
        push_matrix_from(0);
        translate_matrix_vec3(0, ((u8 *)&this->position));
        entry = this->entry;
        translate_matrix(0, (saddr)entry, 0.0f, entry->y_offset, 0.0f);
        rotate_matrix_y(0, this->rotation_y);
        update_state();
        pop_matrix();
        if (((TObjNpcEnemy *)arg0)->sub_802D7444() != 0) {
            model_render_flags &= 0xFFFFFFFE;
        }
        restore_scene_lighting();
        ((TObjEnemy *)arg0)->draw_ground_shadow(0, 0);
    }
}

TObjNpcEnemy::~TObjNpcEnemy() {}


extern void *tl_04;

u8 *TObjNpcEnemy__ct(u8 *arg0, s32 arg1, saddr arg2) {
    TObjNpcBase__ct(arg0);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__12TObjNpcEnemy;
    ((TObject *)arg0)->m_name = TObjNpcEnemy_class_name;
    ((TObjNpcEnemy *)(arg0))->apply_set_data((void *)arg2);
    ((TObjPlayer *)arg0)->init_position_vectors();
    ((TObjNpcEnemy *)(arg0))->apply_set_params(0, 1);
    ((TObjNpcEnemy *)arg0)->movementParameters = &npc_movement_parameters.value;
    ((TObjChara *)arg0)->set_motion_params(&npc_default_battle_stats.value);
    init_collision_body_parts(arg0, &TObjNpcEnemy__collision_body_parts, 1);
    ((TObjPlayer *)arg0)->register_object_by_id();
    ((TObjEnemy *)arg0)->update_prev_position();
    ((TBoss3VoloptHiraisin *)arg0)->copy_position();
    ((TObjNpcEnemy *)arg0)->set_npc_data((void *)((int) (((saddr)TObjNpcEnemy::get_entry_by_index((s16)((int) ((s16) ((TObjNpcEnemy *)arg0)->rotation_x)))))));
    return arg0;
}

void * TObjNpcEnemy__create(void *arg0) {
    void *o;
    void *o2;
    o = TObject::operator new(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = TObject::operator new(0x3BC);
    if (o2 != NULL) {
        o2 = TObjNpcEnemy__ct((u8 *)o2, (saddr)o, (saddr)arg0);
    }
    return o2;
}


TObjNpcEnemyEntry TObjNpcEnemy__entry_table[16];
