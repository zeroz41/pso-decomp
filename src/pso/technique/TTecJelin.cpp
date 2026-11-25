#include "pso/player/TargetCursorList.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecJelin.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/system/vector.h"
#include "pso/technique/TTecCircle.h"

#include <stddef.h>

#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/unk/TLobby_80226070.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

const char *tec_jelin_class_name_ptr = "TTecJelin";

void TTecJelin::create(void *caster, Vec *pos, TargetCursorList *targets, s32 level) {
    new TTecJelin((saddr)caster, pos, targets, level);
}


void TTecJelin::init_tech_params() {
    u8 *arg0 = (u8 *)this;
    TechniqueParams *res;
    res = calc_technique_parameters(0xB, this->level, 0xFFFF);
    ((TechniqueParams *)(arg0 + 0x88))->copy((TechniqueParams *)res);
    this->params.power = (f32)(this->params.power_per_level * this->level);
}

void TTecJelin::apply_to_target(TObjChara *target) {
    DirectAttackPayload hit;
    hit.kind = 0xb;
    hit.power = this->params.power;
    target->receive_direct_attack((void *)this->source, hit, this->contact, 0xb, -1);
}

void TTecJelin::create(void *source, Vec *pos, Vec *target, s32 level) {
    new TTecJelin((saddr)source, pos, target, level);
}
void TTecJelin::render() {  }

void TTecJelin::run_task() {
    s32 i;
    uaddr id;
    source = (uaddr)find_entity_by_id(sourceId);
    if (source == 0) {
        queue_destruction();
        return;
    }
    if (has_targets != 0) {
        for (i = 0; i < targets.count; i++) {
            id = (uaddr)find_entity_by_id(targets.records[i].id);
            if (TTecLuker::is_parents_unqueued(id) != 0) {
                apply_to_target((TObjChara *)id);
            }
        }
    } else {
        apply_technique_to_area_targets();
    }
    queue_destruction();
}

TTecJelin::~TTecJelin() {

}

TTecJelin::TTecJelin(saddr source, Vec *pos, TargetCursorList *list, s32 level) : TTecCircle(source, (saddr)pos, level) {
    s32 r;
    m_name = tec_jelin_class_name_ptr;
    has_targets = 1;
    copy_technique_target_list(&targets, list);
    init_tech_params();
    VecCopy(&position, pos);
    if (collidable != NULL) {
        collidable->bodies->radius = params.range;
    }
    switch (band) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002A315, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002A315, &position, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002A315, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    }
    if (this->source != 0) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}

TTecJelin::TTecJelin(saddr source, Vec *pos, Vec *target, s32 level) : TTecCircle(source, pos, target, level) {
    s32 r;
    m_name = tec_jelin_class_name_ptr;
    has_targets = 0;
    init_tech_params();
    VecCopy(&position, &this->target);
    if (collidable != NULL) {
        collidable->bodies->radius = params.range;
    }
    switch (band) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002A315, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002A315, &position, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002A315, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    }
    if (this->source != 0) {
        sourceId = ((TObjBase *)this->source)->get_entity_id();
    }
}
