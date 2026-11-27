#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/item/TObjItemLight.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/player/PlayerSlots.h"
#include "pso/render/NinjaUtil.h"
#include "pso/object/TObjRoomId.h"


#pragma readonly_strings on


void TObjItemLight::run_task() {
    s32 i;
    TObjPlayer *p;
    if (m_particle != 0) {
        m_particle->set_position(&position);
        m_particle->set_direction(&rotation);
    }
    if (is_item_light_interaction_blocked() != 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != 0 && p->get_floor() == get_current_floor()
            && p->is_locally_controlled() != 0
            && xz_distance_squared(&p->position, &position) < m_radius * m_radius) {
            set_event_source_flag(8);
            queue_destruction();
            return;
        }
    }
}

TObjItemLight::~TObjItemLight() {
    if (m_particle != 0) { TParticleCtrl::release(m_particle); m_particle = 0; }
}


const char *TObjItemLight::class_name = "TObjItemLight";

TObjItemLight::TObjItemLight(TObject *parent, void *set_data) : TObjBase(parent) {
    m_name = TObjItemLight::class_name;
    apply_object_set_data(set_data);
    m_particle = 0;
    m_radius = (f32) scale.x;
    if (m_radius < 0.0f) {
        m_radius = 30.0f;
    }
    m_particle = spawn_particle_effect_with_rotation(&position, &rotation, 0x1CA, 0x40);
}

