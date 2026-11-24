#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/enemy/gee/TObjEneMe1Gee_NEEDLE.h"
#include "pso/enemy/gee/TObjEneMe1Gee.h"
#include "pso/enemy/TNeedleShoot.h"
#include "pso/object/base/TObjChara.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/BmlResource.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/SoundEffect.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/map/FloorArea.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/enemy/gigue/TObjEneMe1GiGueMissile.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjBase.h"

Vec *TNeedleShoot::get_shoot_data() { return &prev_pos; }

void TObjEneMe1Gee_NEEDLE::queue_destruction() {
    s32 remaining;
    remaining = linger_frames - 1;
    linger_frames = remaining;
    if (remaining <= 0) {
        TObject::queue_destruction();
    }
}

void TObjEneMe1Gee_NEEDLE::on_wall_hit() {
    if (get_current_floor_area() == AREA_SEASIDE_NIGHT) {
        play_sound_effect(0x4003B20E, &pos, 0, 0);
    } else {
        play_sound_effect(0x3A847, &pos, 0, 0);
    }
    active = 0;
}

void TObjEneMe1Gee_NEEDLE::on_target_hit(TObjCollidable *actor) {
    TObjChara *target = static_cast<TObjChara *>(actor);
    DirectAttackPayload attack;
    attack.kind = 0;
    attack.power = power;
    DirectAttackPayload payload = attack;
    target->receive_direct_attack(owner, payload, contact_body, -1, -1);
    TObject::queue_destruction();
}

TObjEneMe1Gee_NEEDLE::~TObjEneMe1Gee_NEEDLE() {
}

#pragma readonly_strings on

const char *TObjEneMe1Gee_NEEDLE__name = "TObjEneMe1Gee_NEEDLE";
BmlResource *gee_needle_resource;

void TObjEneMe1Gee_NEEDLE::render() {
    if (gee_needle_resource == NULL) {
        TObject::queue_destruction();
        return;
    }
    push_matrix();
    TParticleCtrl::begin_effect_render();
    post_translate_matrix(&pos.x);
    rotate_matrix_y(NULL, rotation_y);
    rotate_matrix_x(NULL, rotation_x);
    TObjFish::set_global_param(get_bml_texlist(gee_needle_resource, 1));
    draw_ginja_object((void *)get_bml_model(gee_needle_resource, 1));
    TParticleCtrl::end_effect_render();
    pop_matrix();
}

void TObjEneMe1Gee_NEEDLE::run_task() {
    owner = find_entity_by_id(owner_id);
    if (owner == 0) {
        TObject::queue_destruction();
        return;
    }
    if (active == 1) {
        update_position();
        update_lifetime();
        check_target_hit(1);
        return;
    }
    update_stopped();
}

TObjEneMe1Gee_NEEDLE::TObjEneMe1Gee_NEEDLE(TObjBase *owner, Vec *from, Vec *to, f32 speed, f32 power)
    : TNeedleShoot(owner, from, to) {
    m_name = TObjEneMe1Gee_NEEDLE__name;
    this->power = power;
    this->speed = speed;
    linger_frames = 150;
    contact_mode = 1;
    if (this->owner != NULL) {
        owner_id = this->owner->get_entity_id();
    }
}

void TObjEneMe1Gee_NEEDLE::free_global() {
}

void TObjEneMe1Gee_NEEDLE::init_global() {
    gee_needle_resource = TObjEneMe1Gee::get_resource_bundle();
}
