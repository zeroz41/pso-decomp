#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/item/TObjItemLight.h"
#include "pso/item/TObjItemLight.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer.h"

#pragma readonly_strings on

struct Light_80191F90 { u8 pad0[0x38]; f32 pos[3]; u8 pad44[0x18]; f32 rot[3]; u8 pad68[0x28]; f32 f90; void *f94; };

struct Ply_80191F90 { u8 pad0[0x38]; f32 pos[3]; };

extern "C" {
s32 get_current_floor();
s32 is_item_light_interaction_blocked();
f32 xz_distance_squared(void *, void *);
Ply_80191F90 *get_player_by_client_id(s32);
void run_task__13TObjItemLightFv(Light_80191F90 *arg0);
u8 *TObjItemLight__ct(TObjItemLight *arg0, s32 arg1, s32 arg2);
void *__dt__13TObjItemLightFv(void *arg0, s16 arg1);
void *spawn_particle_effect_with_rotation(void *pos, void *dir, s32 id, int e);
s32 __ct__8TObjBaseFP7TObject();
void __dl__7TObjectFPv(void *);

extern s32 __vt__13TObjItemLight[];

void run_task__13TObjItemLightFv(Light_80191F90 *arg0) {
    s32 i;
    Ply_80191F90 *p;
    if (arg0->f94 != 0) {
        ((TParticleCtrl *)arg0->f94)->set_position(arg0->pos);
        ((TParticleCtrl *)(arg0->f94))->set_direction(arg0->rot);
    }
    if (is_item_light_interaction_blocked() != 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        p = get_player_by_client_id(i);
        if (p != 0 && ((TObjPlayer *)p)->get_floor() == get_current_floor()
            && TObjPlayer::is_locally_controlled(p) != 0
            && xz_distance_squared(p->pos, arg0->pos) < arg0->f90 * arg0->f90) {
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
extern "C" {

const char *TObjItemLight__class_name = "TObjItemLight";

u8 *TObjItemLight__ct(TObjItemLight *item_light, s32 arg1, s32 arg2) {
    __ct__8TObjBaseFP7TObject();
    *(s32 **)((s8 *)item_light + 0x18) = __vt__13TObjItemLight;
    *(const char **)((s8 *)item_light + 0) = TObjItemLight__class_name;
    item_light->apply_object_set_data((void *)arg2);
    item_light->m_94 = 0;
    *(f32 *)((s8 *)item_light + 0x90) = (f32) item_light->scale.x;
    if (*(f32 *)((s8 *)item_light + 0x90) < 0.0f) {
        *(f32 *)((s8 *)item_light + 0x90) = 30.0f;
    }
    item_light->m_94 = (s32)spawn_particle_effect_with_rotation((u8 *)item_light + 0x38, (u8 *)item_light + 0x5C, 0x1CA, 0x40);
    return (u8 *)item_light;
}

}
