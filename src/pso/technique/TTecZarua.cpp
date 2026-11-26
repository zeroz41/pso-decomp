#include "pso/player/TargetCursorList.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecZarua.h"
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

const char *TTecZarua::name = "TTecZarua";

void TTecZarua::create_instance(TObjBase *caster, Vec *pos, TargetCursorList *targets, s32 level) {
    new TTecZarua(caster, pos, targets, level);
}


void TTecZarua::calc_range() {
    TechniqueParams *params = calc_technique_parameters(0xC, this->level, 0xFFFF);
    this->params.copy(params);
    this->params.power = (f32)(this->params.power_per_level * this->level);
}

void TTecZarua::apply_to_target(TObjChara *target) {
    DirectAttackPayload hit;
    hit.kind = 0xc;
    hit.power = this->params.power;
    target->receive_direct_attack(this->source, hit, this->contact, 0xc, -1);
}

void TTecZarua::create_instance(TObjBase *source, Vec *pos, Vec *target, s32 level) {
    new TTecZarua(source, pos, target, level);
}
void TTecZarua::render() {  }

void TTecZarua::run_task() {
    s32 i;
    uaddr id;
    source = find_entity_by_id(sourceId);
    if (source == NULL) {
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

TTecZarua::~TTecZarua() {

}

TTecZarua::TTecZarua(TObjBase *source, Vec *pos, TargetCursorList *list, s32 level) : TTecCircle(source, pos, level) {
    s32 r;
    m_name = TTecZarua::name;
    has_targets = 1;
    copy_technique_target_list(&targets, list);
    calc_range();
    VecCopy(&position, pos);
    if (collidable != NULL) {
        collidable->bodies->radius = params.range;
    }
    switch (band) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002A817, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002A817, &position, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002A817, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    }
    if (this->source != NULL) {
        sourceId = this->source->get_entity_id();
    }
}

TTecZarua::TTecZarua(TObjBase *source, Vec *pos, Vec *target, s32 level) : TTecCircle(source, pos, target, level) {
    s32 r;
    m_name = TTecZarua::name;
    has_targets = 0;
    calc_range();
    VecCopy(&position, &this->target);
    if (collidable != NULL) {
        collidable->bodies->radius = params.range;
    }
    switch (band) {
    case 0:
    case 1:
        r = play_sound_effect(0x4002A817, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, 0x100, 0);
        }
        break;
    case 2:
    case 3:
        play_sound_effect(0x4002A817, &position, 0, 0);
        break;
    case 4:
    case 5:
        r = play_sound_effect(0x4002A817, &position, 0, 0);
        if (r >= 0) {
            set_sound_pitch_request(r, -0x100, 0);
        }
        break;
    }
    if (this->source != NULL) {
        sourceId = this->source->get_entity_id();
    }
}
