#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/technique/TTecKafun.h"
#include "pso/system/task/TObject.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/technique/TTecCircle.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/object/base/TObjBase.h"
#include "pso/object/base/TObjChara.h"


#pragma readonly_strings on


const char *tec_kafun_class_name_ptr = "TTecKafun";

void TTecKafun::apply_to_target(TObjChara *target) {
    DirectAttackPayload hit;
    hit.power = this->hit_value;
    switch (this->hit_kind) {
    case 15:
    case 16:
    case 17:
    case 18:
        hit.kind = 0;
        target->receive_direct_attack((void *)this->source, hit, 0, -1, -1);
        hit.kind = this->hit_kind;
        target->receive_direct_attack((void *)this->source, hit, 0, -1, -1);
        break;
    default:
        hit.kind = this->hit_kind;
        target->receive_direct_attack((void *)this->source, hit, 0, -1, -1);
        break;
    }
}

void TTecKafun::create(saddr source, saddr pos, s32 kind, s32 effect, s32 second_effect, f32 value, s32 level, f32 radius) {
    new TTecKafun(source, (Vec *)pos, kind, effect, second_effect, level, value, radius);
}

void TTecKafun::create(saddr source, saddr pos, s32 kind, s32 effect, s32 level, f32 value, f32 radius) {
    new TTecKafun(source, (Vec *)pos, kind, effect, level, value, radius);
}

TTecKafun::~TTecKafun() {

}


void TTecKafun::render() {  }
void TTecKafun::run_task() {
    if (this->collidable == NULL) {
        queue_destruction();
        return;
    }
    this->source = (uaddr)find_entity_by_id(this->sourceId);
    if (this->source == 0U) {
        queue_destruction();
        return;
    }
    spawn_particle_effect(&this->position, this->effect);
    if (this->has_second_effect == 1) {
        spawn_particle_effect(&this->position, this->second_effect);
    }
    apply_technique_to_area_targets();
    queue_destruction();
}

TTecKafun::TTecKafun(saddr source, Vec *pos, s32 kind, s32 effect, s32 second_effect, s32 level, f32 value, f32 radius)
    : TTecCircle(source, pos, pos, level) {
    this->m_name = tec_kafun_class_name_ptr;
    this->hit_value = value;
    this->hit_kind = kind;
    this->has_second_effect = 1;
    this->effect = effect;
    this->second_effect = second_effect;
    if (this->collidable != NULL) {
        this->collidable->bodies->radius = radius;
    }
    play_sound_effect(0x4002A50A, &this->position, 0, 0);
    if (this->source != 0U) {
        this->sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}

TTecKafun::TTecKafun(saddr source, Vec *pos, s32 kind, s32 effect, s32 level, f32 value, f32 radius)
    : TTecCircle(source, pos, pos, level) {
    this->m_name = tec_kafun_class_name_ptr;
    this->hit_value = value;
    this->hit_kind = kind;
    this->has_second_effect = 0;
    this->effect = effect;
    if (this->collidable != NULL) {
        this->collidable->bodies->radius = radius;
    }
    play_sound_effect(0x4002A50A, &this->position, 0, 0);
    if (this->source != 0U) {
        this->sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}
