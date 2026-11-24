#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/technique/TTecGrants.h"
#include "pso/unk/TUnk_804CC888.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/task/TObject_80019A50.h"

#include "pso/technique/TTecCircle.h"
#include "pso/system/task/TObject.h"

#include <stddef.h>
#include "pso/technique/TTecLuker.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/player/TargetCursorList.h"
#include "pso/object/base/TObjBase.h"

extern "C" {
extern s32 tec_grants_class_name;

void TTecGrants::render() {  }

void TTecGrants::apply_to_target(TObjChara *target) {
    DirectAttackPayload hit;
    hit.kind = 0x4;
    hit.power = this->params.power;
    target->receive_direct_attack((void *)this->source, hit, this->contact, 0x9, -1);
}

void TTecGrants::create(void *source, void *origin, void *targets, s32 level) {
    new TTecGrants((saddr)source, (saddr)origin, (saddr)targets, level);
}

void TTecGrants::run_task() {
    uaddr entity;
    source = (uaddr)find_entity_by_id(sourceId);
    if (source == 0) {
        queue_destruction();
        return;
    }
    if (targets.count == 0) {
        queue_destruction();
        return;
    }
    entity = (uaddr)find_entity_by_id(targets.records[0].id);
    if ((TTecLuker::is_parents_unqueued(entity) != 0) && (TObjPlayer::is_valid_and_active(entity) != 0) && (m_148 == 0)) {
        new TUnk_804CC888((u8 *)entity, level, tl_07);
    }
    m_148 = m_148 + 1;
    if (m_148 > 0x1E) {
        if ((entity != 0) && (TTecLuker::is_parents_unqueued(entity) != 0) && (TObjPlayer::is_valid_and_active(entity) != 0)) {
            apply_to_target((TObjChara *)entity);
        }
        queue_destruction();
    }
}

}
TTecGrants::~TTecGrants() {

}

TTecGrants::TTecGrants(saddr arg1, saddr origin, saddr target_list, saddr level) : TTecCircle(arg1, origin, level) {
    m_name = (const char *)tec_grants_class_name;
    init_parameters();
    copy_technique_target_list(&targets, (TargetCursorList *)target_list);
    m_148 = 0;
    if (source != 0U) {
        sourceId = ((TObjBase *)(saddr)source)->get_entity_id();
    }
}

