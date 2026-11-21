#include "pso/boss/barbaray/TObjBoss7RaftSplash.h"
#include "pso/unk/text_802F0E24.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/system/vector.h"

#include "types.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/barbaray/TObjBoss7RaftSplash_802F18E8.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/system/task/TObject.h"
#include <stdlib.h>

#pragma readonly_strings on

struct Stack_802F15D4 {
    s32 sp8;
    f32 spC;
};

extern "C" {
u16 TCameraCtrl__sub_8006A5DC();
const char *lbl_805D3FE8 = "TObjBoss7RaftSplash";


void TObjBoss7RaftSplash::run_task() {
    Vec splash_position;
    if (TCameraCtrl__sub_8006A5DC() != 5) {
        elapsed += *step;
        f32 timer = elapsed;
        f32 period = interval;
        if (timer >= period) {
            elapsed = timer - period;
            VecCopy(&splash_position, &position);
            splash_position.y += *step - boss7_tunnel_max_scroll_speed;
            TObjFish::create_splash_particle((s32)&splash_position, 0x200, (s32)&splash_offset);
        }
    }
}

TObjBoss7RaftSplash::~TObjBoss7RaftSplash() {}
TObjBoss7RaftSplash::TObjBoss7RaftSplash(TObject *parent, const Vec *position, const Vec *offset, f32 *speed)
    : TObject(parent) {
    m_name = lbl_805D3FE8;
    interval = boss7_tunnel_max_scroll_speed * (3.0f + rand_signed_unit());
    elapsed = interval * (3.0517578e-05f * (f32)rand());
    VecCopy(&this->position, position);
    VecCopy(&splash_offset, offset);
    step = speed;
}

void TObjFish::spawn_default_particle(s32 position, s32 particle_index) {
    spawn_particle(position, particle_index, -5.0f);
}

// The TObjFish particle helpers below share this TU's .sdata2 pool: -5.0f (0x805DEC90) is used by
// spawn_default_particle and TObjFish__sub_802F18E8, and the .text runs on without a pool of its own.
s32 fn_802F190C(void *, s32);
s32 fn_802F1960(void *, f32);

}

void TObjFish::create_splash_particle(s32 arg0, s32 arg1, s32 arg2) {
    void *var_r31;

    var_r31 = TObject::operator new(0x78);
    if (var_r31 != NULL) {
        var_r31 = initialize_flagged_particle(var_r31, reinterpret_cast<const void *>(arg0), TParticleCtrl::get_particle_by_index(arg1), 1, 0, 0, 1, (u16)0x40);
    }
    if (var_r31 != NULL) {
        ((TObject *)var_r31)->run_task();
        fn_802F190C(var_r31, arg2);
    }
}

void TObjFish::spawn_particle(s32 arg0, s32 arg1, f32 farg0) {
    void *var_r31;

    var_r31 = TObject::operator new(0x78);
    if (var_r31 != NULL) {
        var_r31 = initialize_flagged_particle(var_r31, reinterpret_cast<const void *>(arg0), TParticleCtrl::get_particle_by_index(arg1), 1, 0, 0, 1, (u16)0x40);
    }
    if (var_r31 != NULL) {
        ((TObject *)var_r31)->run_task();
        fn_802F1960(var_r31, farg0);
    }
}

extern "C" void TObjFish__sub_802F18E8(void *particle) {
    fn_802F1960(particle, -5.0f);
}
