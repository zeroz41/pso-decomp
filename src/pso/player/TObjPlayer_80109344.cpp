#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/player/TObjPlayer_80109344.h"
#include "pso/player/TObjPlayer.h"
#include "pso/item/TItem.h"
#include "pso/effect/item/TItemEffLandHit.h"

struct W_801093B4 { s32 a; s32 b; s32 c; };

union V_801093B4 { W_801093B4 w; struct { f32 x; f32 y; f32 z; } f; };


#pragma push
#pragma opt_propagation off
void TObjPlayer::spawn_hit_particle_trio() {
    W_801093B4 *arg0 = (W_801093B4 *)this;
    V_801093B4 v;
    s32 c;
    s32 b;
    s32 a;
    a = arg0->a;
    b = arg0->b;
    c = arg0->c;
    v.w.a = a;
    v.w.b = b;
    v.w.c = c;
    spawn_particle_effect((const Vec *)&v, 0x1D0);
    spawn_particle_effect((const Vec *)&v, 0x1D1);
    v.f.y = v.f.y - 15.0f;
    spawn_particle_effect((const Vec *)&v, 0x1D2);
}
#pragma pop

void TObjPlayer::forward_item_effect_callback(s32 layer, saddr pos) {
    ((TObjPlayer *)pos)->spawn_hit_particle_trio();
}
void spawn_weapon_impact_effect(s32 layer, void *weapon, s32 start, saddr end) {
    ((TObjPlayer *)end)->spawn_hit_particle_trio();
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
