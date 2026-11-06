#pragma readonly_strings on
#define TOBJECT_OUT_OF_LINE_HELPERS

// Built with -inline deferred (GAME_EXCEPTIONS in configure.py), which emits functions
// in reverse source order: bodies here run from the highest address down.

#include "types.h"
#include "pso/TObject.h"
#include "pso/effect/TParticleCtrl.h"
#include "pso/misc/TNowLoading.h"
#include "pso/object/TObjLight.h"
#include "pso/system/vector.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"
#include "pso/ui/TAdSinglePlyChrSelectGC_801334D4.h"
#include "pso/unk/text_80087278.h"

#include "pso/object/TUnk_804E4788.h"
#include "pso/boss/TBoss7LaserLight.h"

const char *TBoss7LaserLight_name = "TBoss7LaserLight";

TBoss7LaserLight::TBoss7LaserLight(TObject *parent, Vec *position) : TObject(parent) {
    m_name = TBoss7LaserLight_name;
    m_position = position;
    m_state = OFF;
    m_request = REQUEST_NONE;
    m_color[0] = 1.0f;
    m_color[1] = 1.0f;
    m_color[2] = 0.2f;
    m_color[3] = 2.0f;
    m_range[0] = 0.0f;
    m_range[1] = 0.0f;
    m_light = (TObjLight *)TObjLight::alloc_light_slot();
    if (m_light == NULL) {
        queue_destruction();
        return;
    }
    ((TAdSinglePlyChrSelectGC *)m_light)->noop_laser();
    ((TAdSinglePlyChrSelectGC *)m_light)->set_position(m_color);
    ((TAdSinglePlyChrSelectGC *)m_light)->forward_to_field_0x14(m_range);
}

TBoss7LaserLight::~TBoss7LaserLight() {
    if (m_light != NULL) {
        m_light->unregister_and_free();
        m_light = NULL;
    }
}

void TBoss7LaserLight::turn_on() { m_request = REQUEST_ON; }

void TBoss7LaserLight::turn_off() { m_request = REQUEST_OFF; }

void TBoss7LaserLight::run_task() {
    f32 range;

    switch (m_state) {
    case OFF:
    case FADE_OUT:
        if (m_request == REQUEST_ON) {
            m_request = REQUEST_NONE;
            m_state = FADE_IN;
            TAdSinglePlyChrSelectGC__sub_80133508(m_light);
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
        ((TAdSinglePlyChrSelectGC *)m_light)->forward_to_field_0x14(m_range);
        ((TAdSinglePlyChrSelectGC *)m_light)->set_vec3(m_position);
        break;
    case ON:
        ((TAdSinglePlyChrSelectGC *)m_light)->set_vec3(m_position);
        break;
    case FADE_OUT:
        range = m_range[0];
        range -= 3.0f;
        if (range <= 0.0f) {
            range = 0.0f;
            m_state = OFF;
            ((TAdSinglePlyChrSelectGC *)m_light)->noop_laser();
        }
        m_range[0] = range;
        m_range[1] = 40.0f + range;
        ((TAdSinglePlyChrSelectGC *)m_light)->forward_to_field_0x14(m_range);
        ((TAdSinglePlyChrSelectGC *)m_light)->set_vec3(m_position);
        break;
    }
}

void TBoss7LaserLight::render() {}

TUnk_804E4788::TUnk_804E4788(TObject *parent, s32 limit, s32 effect_id) : TObject(parent) {
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

TUnk_804E4788::~TUnk_804E4788() {
    if (m_particle != NULL) {
        m_particle->queue_destruction();
        m_particle = NULL;
    }
}

void TUnk_804E4788::push_ring_point(const Vec *pos) {
    VecCopy(&m_points[m_head], pos);
    m_points[m_head].y += 5.0f;
    m_head++;
    if (m_head >= NUM_POINTS) {
        m_head = 0;
    }
}

void TUnk_804E4788::run_task() {
    if (m_particle == NULL) {
        m_particle = (TParticleCtrl *)spawn_continuous_particle_effect_with_flags(m_points, m_effect_id, 0x40);
        if (m_particle != NULL) {
            m_particle->enable();
        }
    } else {
        switch (m_state) {
        case 0:
            if (m_head >= m_limit) {
                m_state = 1;
                m_cur = 0;
            }
            m_particle->enable();
            break;
        case 1:
            ((TParticleCtrl *)m_particle)->set_position(&m_points[m_cur]);
            m_cur++;
            if (m_cur >= NUM_POINTS) {
                m_cur = 0;
            }
            if (m_cur == m_head) {
                m_state = 2;
            }
            break;
        case 2:
            m_particle->enable();
            break;
        }
    }
}
