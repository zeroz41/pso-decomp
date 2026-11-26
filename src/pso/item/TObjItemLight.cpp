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


#pragma readonly_strings on

struct Light_80191F90 { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x18]; f32 rot[3]; u8 pad68[0x28]; f32 f90; void *f94; };

extern "C" {
s32 is_item_light_interaction_blocked();
void run_task__13TObjItemLightFv(Light_80191F90 *arg0);


void run_task__13TObjItemLightFv(Light_80191F90 *arg0) {
    s32 i;
    TObjPlayer *p;
    if (arg0->f94 != 0) {
        ((TParticleCtrl *)arg0->f94)->set_position(arg0->pos);
        ((TParticleCtrl *)(arg0->f94))->set_direction(arg0->rot);
    }
    if (is_item_light_interaction_blocked() != 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != 0 && p->get_floor() == get_current_floor()
            && p->is_locally_controlled() != 0
            && xz_distance_squared(&p->position, (const Vec *)arg0->pos) < arg0->f90 * arg0->f90) {
            ((TObjBase *)arg0)->set_event_source_flag(8);
            ((TObject *)arg0)->queue_destruction();
            return;
        }
    }
}

}
TObjItemLight::~TObjItemLight() {
    if (*(void **)((s8 *)this + 0x94) != NULL) { TParticleCtrl::release(*(void **)((s8 *)this + 0x94)); this->m_94 = 0; }
}


const char *TObjItemLight::class_name = "TObjItemLight";

#define item_light this
TObjItemLight::TObjItemLight(TObject *parent, saddr set_data) : TObjBase(parent) {
    ((TObjItemLight *)item_light)->m_name = TObjItemLight::class_name;
    item_light->apply_object_set_data((void *)set_data);
    item_light->m_94 = 0;
    *(f32 *)((s8 *)item_light + 0x90) = (f32) item_light->scale.x;
    if (*(f32 *)((s8 *)item_light + 0x90) < 0.0f) {
        *(f32 *)((s8 *)item_light + 0x90) = 30.0f;
    }
    item_light->m_94 = (saddr)spawn_particle_effect_with_rotation(&item_light->position, &item_light->rotation_x, 0x1CA, 0x40);
}
#undef item_light

