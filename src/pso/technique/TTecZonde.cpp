#include "pso/player/TargetCursorList.h"
#include "pso/technique/TTecZondeEff.h"
#include "pso/math/MatrixVector.h"
#include "types.h"
#include "pso/enemy/beast/TObjEneBeastBase.h"
#include <stdlib.h>
#include "pso/technique/TechniqueParams.h"
#include "pso/player/TObjPlayer.h"
#include "pso/technique/TTecAnti.h"
#include "pso/technique/TTecZonde.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/technique/TTecCtrl.h"
#include "pso/audio/SoundRequests.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

const char *TTecZonde_class_name = "TTecZonde"; // TTecZonde__name

void TTecZonde::init_parameters() {
    TechniqueParams *scaled = calc_technique_parameters(6, level, 0xFFFF);
    params.copy(scaled);
    if (level >= 15 && is_technique_ready() == 0) {
        params.power = (f32)(tech_high_level_linear_power_table[6].base + tech_high_level_linear_power_table[6].per_level * level);
        return;
    }
    params.power = params.power + (f32)(params.power_per_level * level);
    if (is_technique_ready()) {
        params.power = params.power * technique_scale_table[6].power;
    }

}

void TTecZonde::create(TObjBase *source, Vec *origin, TargetCursorList *targets, s32 level) {
    new TTecZonde(source, origin, targets, level);
}
void TTecZonde::apply_to_target(TObjChara *target) {
    DirectAttackPayload hit;
    hit.kind = 3;
    hit.power = this->params.power;
    if (static_cast<TObjEneBeastBase *>(target)->test_elt_flag(0, 0x80) == 0) {
        target->receive_direct_attack(source, hit, 0, 6, -1);
    }
}

#include "pso/technique/TTecLuker.h"
#include "pso/system/MatrixStack.h"
#include "pso/technique/TTecZondeHitEffect.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/task/TMainTask.h"


TTecZonde::~TTecZonde() {
}

void TTecZonde::render() {  }

#pragma push
#pragma fp_contract on

void TTecZonde::run_task() {
    ZondeBolt segs[14];
    ZondeBolt *s;
    Vec *pb;
    s32 i;
    s32 j;
    s32 k;
    s32 l;
    TObjChara *t;
    f32 scale;

    source = find_entity_by_id(sourceId);
    if (source == NULL) {
        queue_destruction();
        return;
    }
    if (targets.count == 0) {
        queue_destruction();
        return;
    }
    t = static_cast<TObjChara *>(find_entity_by_id(targets.records[0].id));
    if (TObject::is_parents_unqueued(t) != 0) {
        for (i = 0; i < 14; i++) {
            s = &segs[i];
            s->start.y = 100.0f + t->position.y;
            if (band == 5 && i == 0) {
                s->start.y = 500.0f + t->position.y;
            }
            s->start.x = 13.0f * ((f32)i * (3.0517578e-05f * (f32)rand())) + t->position.x;
            s->start.z = 13.0f * ((f32)i * (3.0517578e-05f * (f32)rand())) + t->position.z;
            s->dir.x = t->position.x - s->start.x;
            s->dir.y = t->position.y - s->start.y;
            pb = &s->dir;
            s->dir.z = t->position.z - s->start.z;
            s->len = vector_length(pb);
            if (0.0f != s->len) {
                normalize_vector(pb);
            }
        }
        scale = 0.5f;
        switch (band) {
        case 0:
            new TTecZondeEff(tl_07, &segs[0].start, &segs[0].dir, 0x14000000, 0x14, segs[0].len, 0.5f);
            break;
        case 1:
            scale *= 1.2f;
            new TTecZondeEff(tl_07, &segs[0].start, &segs[0].dir, 0x14000000, 0x14, segs[0].len, scale);
            break;
        case 2:
            scale *= 1.4f;
            new TTecZondeEff(tl_07, &segs[0].start, &segs[0].dir, 0x14000000, 0x14, segs[0].len, scale);
            break;
        case 3:
            for (j = 0; j < 3; j++) {
                new TTecZondeEff(tl_07, &segs[j].start, &segs[j].dir, 0x14000000, 0x14, segs[j].len, 0.5f);
            }
            break;
        case 4:
            scale *= 1.4f;
            for (k = 0; k < 3; k++) {
                new TTecZondeEff(tl_07, &segs[k].start, &segs[k].dir, 0x14000000, 0x14, segs[k].len, scale);
            }
            break;
        case 5:
            for (l = 0; l < 14; l++) {
                if (l == 0) {
                    new TTecZondeEff(tl_07, &segs[l].start, &segs[l].dir, 0x14000000, 0x14, segs[l].len, 5.0f);
                } else {
                    new TTecZondeEff(tl_07, &segs[l].start, &segs[l].dir, 0x14000000, 0x14, segs[l].len, 0.5f);
                }
            }
            break;
        }
        if (band != 5) {
            new TTecZondeHitEffect(&segs[0].start, &t->position, tl_07, 0x19F);
        }
        {
            s32 h;
            switch (band) {
            case 0:
                h = play_sound_effect(0x4002A408, &t->position, 0, 0);
                if (h >= 0) {
                    set_sound_pitch_request(h, 0x100, 0);
                }
                break;
            case 1:
                play_sound_effect(0x4002A408, &t->position, 0, 0);
                break;
            case 2:
            case 3:
                h = play_sound_effect(0x4002A408, &t->position, 0, 0);
                if (h >= 0) {
                    set_sound_pitch_request(h, -0x180, 0);
                }
                break;
            case 4:
                h = play_sound_effect(0x4002A408, &t->position, 0, 0);
                if (h >= 0) {
                    set_sound_pitch_request(h, -0x250, 0);
                }
                break;
            case 5:
                h = play_sound_effect(0x4002A408, &t->position, 0, 0);
                if (h >= 0) {
                    set_sound_pitch_request(h, -0x100, 0);
                }
                break;
            }
        }
    }
    if (t != NULL && TObject::is_parents_unqueued(t) != 0 && TObjCollidable::is_valid_and_active(t) != 0) {
        apply_to_target(t);
    }
    queue_destruction();
}

#pragma pop
TTecZonde::TTecZonde(TObjBase *source, Vec *origin, TargetCursorList *target_list, s32 level) : TTecShot(source, origin, 0, level) {
    m_name = TTecZonde_class_name;
    init_parameters();
    copy_technique_target_list(&targets, target_list);
    if (this->source != NULL) {
        sourceId = this->source->get_entity_id();
    }
}
