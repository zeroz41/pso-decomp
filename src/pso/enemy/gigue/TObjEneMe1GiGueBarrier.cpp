#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/enemy/gigue/TObjEneMe1GiGueBarrier.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/enemy/gigue/TObjEneMe1GiGue.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/BmlResource.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

const char *TObjEneMe1GiGueBarrier__name = "TObjEneMe1GiGueBarrier";
BmlResource *TObjEneMe1GiGueBarrier__barrier_resource_object;
TObjMotionAction TObjEneMe1GiGueBarrier__animation_definitions[3] = {
    { MOTION_MODE_ONCE, 0, 6, 1.0f, 0x1 },
    { MOTION_MODE_LOOP, 0, 7, 1.0f, 0x0 },
    { MOTION_MODE_ONCE, 0, 8, 1.0f, 0x1 },
};

void TObjEneMe1GiGueBarrier::render() {
    if (TObjEneMe1GiGueBarrier__barrier_resource_object == NULL) {
        queue_destruction();
        return;
    }
    if (get_current_floor_area() == AREA_TOWER) {
        if (classify_actor_view_detail(600.0f, 600.0f, 20.0f) == 0) {
            return;
        }
    } else if (classify_actor_view_detail(150.0f, 400.0f, 20.0f) == 0) {
        return;
    }
    if (defer_render() == 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(texlist));
        TParticleCtrl::end_effect_render();
        draw();
        pop_matrix();
    }
}

void TObjEneMe1GiGueBarrier::run_task() {
    TObjEneMe1GiGue *gigue = owner;
    if (gigue == NULL) {
        queue_destruction();
        return;
    }
    VecCopy(&position, gigue->update_and_get_pos());
    rotation_y = owner->get_rotation_y();
    advance_animation();
    timer = timer - 1;
    switch (phase) {
    case 0:
        if (motion_flags & 0x10) {
            phase = 1;
            requested_action = 1;
            if (get_current_floor_area() == AREA_TOWER) {
                play_sound_effect(0x4003A316, reinterpret_cast<const Vec *>((u8 *)&position), 0, 0);
            } else {
                play_sound_effect(0x3A346, reinterpret_cast<const Vec *>((u8 *)&position), 0, 0);
            }
        }
        break;
    case 2:
        if (motion_flags & 0x10) {
            queue_destruction();
        }
        break;
    default:
    case 1:
        if (timer <= 0 || owner->is_active_state() != 0) {
            phase = 2;
            requested_action = 2;
        }
        break;
    }
}

TObjEneMe1GiGueBarrier::~TObjEneMe1GiGueBarrier() {
    if (owner != NULL) {
        owner->clear_barrier_active();
    }
}

TObjEneMe1GiGueBarrier::TObjEneMe1GiGueBarrier(TObject *parent, void *owner_obj) : TObjMotion(parent) {
    BmlModelEntry *models;
    m_name = TObjEneMe1GiGueBarrier__name;
    owner = (TObjEneMe1GiGue *)owner_obj;
    owner_id = owner->get_entity_id();
    VecCopy(&position, owner->update_and_get_pos());
    rotation_y = owner->get_rotation_y();
    timer = owner->get_barrier_duration();
    owner->set_barrier_active();
    phase = 0;
    model = (void *)TObjEneMe1GiGueBarrier__barrier_resource_object->models[2].model;
    models = TObjEneMe1GiGueBarrier__barrier_resource_object->models;
    texlist = models[2].texlist;
    set_action_table(TObjEneMe1GiGueBarrier__animation_definitions);
    set_motion_list(TObjEneMe1GiGueBarrier__barrier_resource_object->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_requested_action(requested_action);
}

void TObjEneMe1GiGueBarrier::free_global() {}

void *TObjEneMe1GiGueBarrier::create(void *parent, void *owner) {
    return new TObjEneMe1GiGueBarrier((TObject *)parent, owner);
}

void TObjEneMe1GiGueBarrier::init_global() {
    TObjEneMe1GiGueBarrier__barrier_resource_object = TObjEneMe1GiGue::get_resource();
}
