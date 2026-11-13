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

#pragma readonly_strings on

extern "C" {
const char *TObjEneMe1GiGueBarrier__name = "TObjEneMe1GiGueBarrier";
BmlResource *TObjEneMe1GiGueBarrier__barrier_resource_object;
TObjMotionAction TObjEneMe1GiGueBarrier__animation_definitions[3] = {
    { MOTION_MODE_ONCE, 0, 6, 1.0f, 0x1 },
    { MOTION_MODE_LOOP, 0, 7, 1.0f, 0x0 },
    { MOTION_MODE_ONCE, 0, 8, 1.0f, 0x1 },
};
}

extern "C" {
void TObjEneMe1GiGueBarrier__sub_80325CC0(void);

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
        TObjFish::set_global_param(texlist);
        TParticleCtrl::end_effect_render();
        draw();
        pop_matrix();
    }
}

void TObjEneMe1GiGueBarrier::run_task() {
    TObjEneMe1GiGue *owner = m_fc;
    if (owner == NULL) {
        queue_destruction();
        return;
    }
    VecCopy(&position, owner->update_and_get_pos());
    rotation_y = m_fc->sub_802CAC48();
    advance_animation();
    m_108 = m_108 - 1;
    switch (m_104) {
    case 0:
        if (motion_flags & 0x10) {
            m_104 = 1;
            requested_action = 1;
            if (get_current_floor_area() == AREA_TOWER) {
                play_sound_effect(0x4003A316, (u8 *)&position, 0, 0);
            } else {
                play_sound_effect(0x3A346, (u8 *)&position, 0, 0);
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
        if (m_108 <= 0 || m_fc->is_active_state() != 0) {
            m_104 = 2;
            requested_action = 2;
        }
        break;
    }
}

}
TObjEneMe1GiGueBarrier::~TObjEneMe1GiGueBarrier() {
    if (m_fc != NULL) {
        m_fc->clear_flag388_bit80000();
    }
}

TObjEneMe1GiGueBarrier::TObjEneMe1GiGueBarrier(TObject *parent, void *owner) : TObjMotion(parent) {
    BmlModelEntry *models;
    m_name = TObjEneMe1GiGueBarrier__name;
    m_fc = (TObjEneMe1GiGue *)owner;
    m_100 = get_entity_id(m_fc);
    VecCopy(&position, m_fc->update_and_get_pos());
    rotation_y = m_fc->sub_802CAC48();
    m_108 = m_fc->get_field_44c();
    m_fc->sub_802CABF4();
    m_104 = 0;
    model = (void *)TObjEneMe1GiGueBarrier__barrier_resource_object->models[2].model;
    models = TObjEneMe1GiGueBarrier__barrier_resource_object->models;
    texlist = models[2].m_c;
    set_field_d8((s32)TObjEneMe1GiGueBarrier__animation_definitions);
    set_field_dc((s32)TObjEneMe1GiGueBarrier__barrier_resource_object->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
}

void TObjEneMe1GiGueBarrier__sub_80325CC0(void) {  }

void *TObjEneMe1GiGueBarrier::create(void *arg0, void *arg1) {
    return new TObjEneMe1GiGueBarrier((TObject *)arg0, arg1);
}

void TObjEneMe1GiGueBarrier::init_global() {
    TObjEneMe1GiGueBarrier__barrier_resource_object = TObjEneMe1GiGue::sub_802CAC80();
}
