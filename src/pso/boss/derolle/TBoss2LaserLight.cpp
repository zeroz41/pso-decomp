#include "types.h"
#include "pso/boss/derolle/TBoss2LaserLight.h"
#include "pso/boss/TUnk_80482C58.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/object/ambient/PointLight.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject_80019A50.h"

#pragma readonly_strings on

const char *TBoss2LaserLight__name = "TBoss2LaserLight";

#pragma defer_codegen on

TBoss2LaserLight::TBoss2LaserLight(TObject *parent, Vec *position) : TObject(parent) {
    m_name = TBoss2LaserLight__name;
    m_position = position;
    m_state = OFF;
    m_request = REQUEST_NONE;
    m_color[0] = 1.0f;
    m_color[1] = 1.0f;
    m_color[2] = 0.2f;
    m_color[3] = 2.0f;
    m_range[0] = 0.0f;
    m_range[1] = 0.0f;
    m_light = TObjLight::alloc_light_slot();
    if (m_light == NULL) {
        queue_destruction();
        return;
    }
    m_light->disable();
    m_light->set_color(m_color);
    m_light->set_range(m_range);
}

TBoss2LaserLight::~TBoss2LaserLight() {
    if (m_light != NULL) {
        m_light->unregister_and_free();
        m_light = NULL;
    }
}

void TBoss2LaserLight::turn_on() { m_request = REQUEST_ON; }
void TBoss2LaserLight::turn_off() { m_request = REQUEST_OFF; }

void TBoss2LaserLight::run_task() {
    f32 range;
    switch (m_state) {
    case OFF:
    case FADE_OUT:
        if (m_request == REQUEST_ON) {
            m_request = REQUEST_NONE;
            m_state = FADE_IN;
            m_light->enable();
        }
        break;
    case FADE_IN:
    case ON:
        if (m_request == REQUEST_OFF) {
            m_request = REQUEST_NONE;
            m_state = FADE_OUT;
        }
        break;
    }
    switch (m_state) {
    case OFF:
        break;
    case FADE_IN:
        range = m_range[0];
        range += 3.0f;
        if (range >= 60.0f) {
            range = 60.0f;
            m_state = ON;
        }
        m_range[0] = range;
        m_range[1] = 40.0f + range;
        m_light->set_range(m_range);
        m_light->set_position(m_position);
        break;
    case ON:
        m_light->set_position(m_position);
        break;
    case FADE_OUT:
        range = m_range[0];
        range -= 3.0f;
        if (range <= 0.0f) {
            range = 0.0f;
            m_state = OFF;
            m_light->disable();
        }
        m_range[0] = range;
        m_range[1] = 40.0f + range;
        m_light->set_range(m_range);
        m_light->set_position(m_position);
        break;
    }
}

void TBoss2LaserLight::render() {}

TUnk_80482C58::TUnk_80482C58(TObject *parent, s32 limit, s32 effect_id) : TObject(parent) {
    s32 i;
    for (i = 0; i < NUM_POINTS; i++) {
        m_points[i].x = 0.0f;
        m_points[i].y = 0.0f;
        m_points[i].z = 0.0f;
    }
    m_head = 0;
    m_cur = 0;
    m_limit = limit;
    m_effect_id = effect_id;
    m_particle = NULL;
    m_state = 0;
}

TUnk_80482C58::~TUnk_80482C58() {
    if (m_particle != NULL) {
        // Called out of line: the inline copy this file emits belongs at its end, after the constructors.
        queue_destruction__7TObjectFv(m_particle);
        m_particle = NULL;
    }
}

// Its 5.0f opens this file's .sdata2 pool, so it is this translation unit's first function.
void TUnk_80482C58::push_ring_point(const Vec *pos) {
    VecCopy(&m_points[m_head], pos);
    m_points[m_head].y += 5.0f;
    m_head++;
    if (m_head >= NUM_POINTS) {
        m_head = 0;
    }
}
