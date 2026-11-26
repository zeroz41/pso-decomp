#include "pso/player/TargetCursorList.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/technique/TTecZondeEff.h"
#include "types.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/technique/TechniqueParams.h"
#include "pso/technique/TTecGiZonde.h"
#include "pso/technique/TTecLuker.h"
#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/technique/TTecShot.h"
#include "pso/audio/SoundRequests.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/task/TMainTask.h"
#include "pso/technique/TTecZondeHitEffect.h"
#include "pso/system/SoundEffect.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

const char *TTecGiZonde_name_ref = "TTecGiZonde";

void TTecGiZonde::init_parameters() {
    TechniqueParams *scaled = calc_technique_parameters(7, level, 0xFFFF);
    params.copy(scaled);
    if (level >= 15 && TTecCtrl::is_technique_ready() == 0) {
        params.power = (f32)(tech_high_level_linear_power_table[7].base + tech_high_level_linear_power_table[7].per_level * level);
        return;
    }
    params.power = params.power + (f32)(params.power_per_level * level);
    if (TTecCtrl::is_technique_ready()) {
        params.power = params.power * technique_scale_table[7].power;
    }

}


void TTecGiZonde::apply_to_target(TObjChara *target) {
    DirectAttackPayload hit;
    hit.kind = 3;
    hit.power = this->params.power;
    target->receive_direct_attack(this->source, hit, 0, 7, -1);
}

s32 TTecGiZonde::find_chain_targets() {
    Vec d;
    Vec d2;
    f32 scale = 0.5f;
    f32 len;
    f32 len2;
    TObjChara *e;
    s32 i;
    TObjChara *a;
    TObjChara *b;
    void *p;
    e = (TObjChara *) find_entity_by_id(targetList.records[0].id);
    if (TTecLuker::is_parents_unqueued(e) == 0) {
        return 0;
    }
    d.x = e->bodies[targetList.records[0].flag].center.x - position.x;
    d.y = e->bodies[targetList.records[0].flag].center.y - position.y;
    d.z = e->bodies[targetList.records[0].flag].center.z - position.z;
    len = vector_length(&d);
    if (0.0f != len) {
        normalize_vector(&d);
    }
    switch (band) {
    case 0:
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, len, 0.5f);
        new TTecZondeHitEffect(&e->bodies[targetList.records[0].flag].center, &position, tl_07, 0x19F);
        break;
    case 1:
        scale *= 1.2f;
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, len, scale);
        new TTecZondeHitEffect(&e->bodies[targetList.records[0].flag].center, &position, tl_07, 0x19F);
        break;
    case 2:
        scale *= 1.4f;
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, len, scale);
        new TTecZondeHitEffect(&e->bodies[targetList.records[0].flag].center, &position, tl_07, 0x19F);
        break;
    case 3:
        scale *= 1.2f;
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, len, scale);
        new TTecZondeHitEffect(&e->bodies[targetList.records[0].flag].center, &position, tl_07, 0x19F);
        new TTecZondeHitEffect(&e->bodies[targetList.records[0].flag].center, &position, tl_07, 0x188);
        break;
    case 4:
        scale *= 1.4f;
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, len, scale);
        new TTecZondeHitEffect(&e->bodies[targetList.records[0].flag].center, &position, tl_07, 0x19F);
        new TTecZondeHitEffect(&e->bodies[targetList.records[0].flag].center, &position, tl_07, 0x188);
        break;
    case 5:
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, len, 5.0f);
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, len, 0.5f);
        new TTecZondeEff(tl_07, &position, &d, 0x14000000, 20, len, 0.5f);
        new TTecZondeHitEffect(&e->bodies[targetList.records[0].flag].center, &position, tl_07, 0x19F);
        new TTecZondeHitEffect(&e->bodies[targetList.records[0].flag].center, &position, tl_07, 0x188);
        break;
    }
    if (targetList.count == 1) {
        return 1;
    }
    for (i = 0; i < targetList.count - 1; i++) {
        a = (TObjChara *) find_entity_by_id(targetList.records[i].id);
        b = (TObjChara *) find_entity_by_id(targetList.records[i + 1].id);
        if (TTecLuker::is_parents_unqueued(a) != 0 && TTecLuker::is_parents_unqueued(b) != 0) {
        if ((a->actorFlags & 0x20000000) && (b->actorFlags & 0x20000000) &&
            TObjPlayer::is_valid_and_active((uaddr) a) != 0 && TObjPlayer::is_valid_and_active((uaddr) b) != 0 &&
            a->is_actor_dead() != 0 && b->is_actor_dead() != 0) {
            return 0;
        }
        d2.x = b->bodies[targetList.records[i].flag].center.x - a->bodies[targetList.records[i + 1].flag].center.x;
        d2.y = b->bodies[targetList.records[i].flag].center.y - a->bodies[targetList.records[i + 1].flag].center.y;
        d2.z = b->bodies[targetList.records[i].flag].center.z - a->bodies[targetList.records[i + 1].flag].center.z;
        len2 = vector_length(&d2);
        if (0.0f != len2) {
            normalize_vector(&d2);
        }
        scale = 0.5f;
        switch (band) {
        case 0:
            new TTecZondeEff(tl_07, &a->bodies[targetList.records[i].flag].center, &d2, 0x14000000, 20, len2, 0.5f);
            break;
        case 1:
            scale *= 1.2f;
            new TTecZondeEff(tl_07, &a->bodies[targetList.records[i].flag].center, &d2, 0x14000000, 20, len2, scale);
            break;
        case 2:
            scale *= 1.4f;
            new TTecZondeEff(tl_07, &a->bodies[targetList.records[i].flag].center, &d2, 0x14000000, 20, len2, scale);
            break;
        case 3:
            scale *= 1.2f;
            new TTecZondeEff(tl_07, &a->bodies[targetList.records[i].flag].center, &d2, 0x14000000, 20, len2, scale);
            break;
        case 4:
            scale *= 1.4f;
            new TTecZondeEff(tl_07, &a->bodies[targetList.records[i].flag].center, &d2, 0x14000000, 20, len2, scale);
            break;
        case 5:
            new TTecZondeEff(tl_07, &a->bodies[targetList.records[i].flag].center, &d2, 0x14000000, 20, len2, 5.0f);
            new TTecZondeEff(tl_07, &a->bodies[targetList.records[i].flag].center, &d2, 0x14000000, 20, len2, 0.5f);
            new TTecZondeEff(tl_07, &a->bodies[targetList.records[i].flag].center, &d2, 0x14000000, 20, len2, 0.5f);
            break;
        }
        } else {
            return 0;
        }
    }
    return 1;
}

void TTecGiZonde::create(TObjBase *caster, Vec *pos, TargetCursorList *targets, s32 level) {
    new TTecGiZonde(caster, pos, targets, level);
}

TTecGiZonde::~TTecGiZonde() {}

void TTecGiZonde::deliver_chain_hits() {
    s32 i;
    TObjCollidable *actor;
    for (i = 0; i < targetList.count; i++) {
        actor = find_entity_by_id(targetList.records[i].id);
        if (TTecLuker::is_parents_unqueued(actor) != 0 && TObjPlayer::is_valid_and_active((uaddr)actor) != 0) {
            apply_to_target((TObjChara *)actor);
        }
    }
}

void TTecGiZonde::run_task() {
    this->source = find_entity_by_id(this->sourceId);
    if (this->source == NULL) {
        queue_destruction();
        return;
    }
    if ((s32) this->targetList.count == 0) {
        queue_destruction();
        return;
    }
    if (find_chain_targets() == 1) {
        deliver_chain_hits();
    }
    queue_destruction();
}
// The chain starts at `pos` with no facing (angle 0).
TTecGiZonde::TTecGiZonde(TObjBase *source, Vec *pos, TargetCursorList *targets, s32 level) : TTecShot(source, pos, 0, level) {
    s32 h;
    m_name = TTecGiZonde_name_ref;
    init_parameters();
    copy_technique_target_list(&this->targetList, targets);
    switch (band) {
    case 0:
        if ((h = play_sound_effect(0x4002A509, &position, 0, 0)) >= 0) {
            set_sound_pitch_request(h, 0x100, 0);
        }
        break;
    case 1:
        play_sound_effect(0x4002A509, &position, 0, 0);
        break;
    case 2:
    case 3:
        if ((h = play_sound_effect(0x4002A509, &position, 0, 0)) >= 0) {
            set_sound_pitch_request(h, -0x180, 0);
        }
        break;
    case 4:
        if ((h = play_sound_effect(0x4002A509, &position, 0, 0)) >= 0) {
            set_sound_pitch_request(h, -0x250, 0);
        }
        break;
    case 5:
        if ((h = play_sound_effect(0x4002A509, &position, 0, 0)) >= 0) {
            set_sound_pitch_request(h, -0x100, 0);
        }
        break;
    }
    if (this->source != NULL) {
        sourceId = this->source->get_entity_id();
    }
}
