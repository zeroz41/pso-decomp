#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/item/TItemEffLandHit.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/system/vector.h"
#include "pso/weapon/TItemAttacker.h"
#include "types.h"

#pragma readonly_strings on

#pragma push
#pragma opt_propagation off
void spawn_hit_particle_trio(Vec *pos) {
    HitPositionWords *src = (HitPositionWords *)pos;
    HitPosition v;
    s32 z;
    s32 y;
    s32 x;
    x = src->x;
    y = src->y;
    z = src->z;
    v.w.x = x;
    v.w.y = y;
    v.w.z = z;
    spawn_particle_effect(&v.f, 0x1D0);
    spawn_particle_effect(&v.f, 0x1D1);
    v.f.y = v.f.y - 15.0f;
    spawn_particle_effect(&v.f, 0x1D2);
}
#pragma pop

void spawn_wall_hit_particles(s32 layer, Vec *pos) {
    spawn_hit_particle_trio(pos);
}

void spawn_weapon_impact_effect(s32 layer, TItemWeapon *weapon, Vec *start, Vec *end) {
    spawn_hit_particle_trio(end);
}

void TItemEffLandHit::trigger_impact() {
    TItem *item;
    item = find_item_by_id(item_id);
    if (item != NULL) {
        ((TObjPlayer *)item)->call_callback_1ec((saddr)&start, (saddr)&end);
    }
    finished = 1;
}

void TItemEffLandHit::on_timer_expired(TObject *object) {
    if (object != NULL) {
        static_cast<TItemEffLandHit *>(object)->trigger_impact();
    }
}

void spawn_land_hit_effect(TObject *parent, TItem *item, Vec *start, Vec *end, s32 frames) {
    if (parent != NULL && start != NULL && end != NULL && item != NULL) {
        TItemAttacker::spawn_item_timer(new TItemEffLandHit(parent, item, start, end),
                                        TItemEffLandHit::on_timer_expired, frames);
    }
}

const char *TItemEffLandHit::class_name = "TItemEffLandHit";

void TItemEffLandHit::run_task() {
    if (finished) {
        queue_destruction();
    }
}

TItemEffLandHit::~TItemEffLandHit() {}

TItemEffLandHit::TItemEffLandHit(TObject *parent, TItem *item, Vec *start, Vec *end) : TObject(parent) {
    m_name = class_name;
    VecCopy(&this->end, end);
    VecCopy(&this->start, start);
    item_id = item->get_item_id();
    finished = 0;
    disallow_rendering();
}
