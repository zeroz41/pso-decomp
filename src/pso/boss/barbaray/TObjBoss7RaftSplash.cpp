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

struct RecoveredGlobal_802F16CC___vt__19TObjBoss7RaftSplash { s32 value; u8 remaining[0x14]; };

extern "C" {
u16 TCameraCtrl__sub_8006A5DC();
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_802F16CC___vt__19TObjBoss7RaftSplash __vt__19TObjBoss7RaftSplash;
const char *lbl_805D3FE8 = "TObjBoss7RaftSplash";


void TObjBoss7RaftSplash::run_task() {
    u8 *arg0 = (u8 *)this;
    Stack_802F15D4 stack;
    f32 temp_f0;
    f32 temp_f1;
    if (TCameraCtrl__sub_8006A5DC() != 5) {
        *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (*(f32 *)((s8 *)arg0 + 0x1C) + **(f32 **)((s8 *)arg0 + 0x24));
        temp_f0 = *(f32 *)((s8 *)arg0 + 0x1C);
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x20);
        if (temp_f0 >= temp_f1) {
            *(f32 *)((s8 *)arg0 + 0x1C) = (f32) (temp_f0 - temp_f1);
            VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x28));
            stack.spC += **(f32 **)((s8 *)arg0 + 0x24) - boss7_tunnel_max_scroll_speed;
            TObjFish::create_splash_particle((saddr) &stack.sp8, 0x200, (saddr)(arg0 + 0x34));
        }
    }
}

TObjBoss7RaftSplash::~TObjBoss7RaftSplash() {}
u8 *TObjBoss7RaftSplash__ct(u8 *object, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4) {
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__19TObjBoss7RaftSplash.value;
    ((TObjBoss7RaftSplash *)object)->m_name = lbl_805D3FE8;
    *(f32 *)((s8 *)object + 0x20) = (f32) (boss7_tunnel_max_scroll_speed * (3.0f + rand_signed_unit()));
    *(f32 *)((s8 *)object + 0x1C) = (f32) (*(f32 *)((s8 *)object + 0x20) * (3.0517578e-05f * (f32) rand()));
    VecCopy((Vec *)(object + 0x28), (const Vec *)arg2);
    VecCopy((Vec *)(object + 0x34), (const Vec *)arg3);
    *(s32 *)((s8 *)object + 0x24) = arg4;
    return object;
}

void TObjFish::spawn_default_particle(s32 position, s32 particle_index) {
    spawn_particle(position, particle_index, -5.0f);
}

// The TObjFish particle helpers below share this TU's .sdata2 pool: -5.0f (0x805DEC90) is used by
// spawn_default_particle and TObjFish__sub_802F18E8, and the .text runs on without a pool of its own.
s32 fn_802F190C(void *, s32);
s32 fn_802F1960(void *, f32);

}

void TObjFish::create_splash_particle(saddr arg0, s32 arg1, saddr arg2) {
    void *var_r31;

    var_r31 = TObject::operator new(0x78);
    if (var_r31 != NULL) {
        var_r31 = ((TParticleCtrl *)var_r31)->initialize_with_flags((const void *)arg0, (s32)(TParticleCtrl::get_particle_by_index(arg1)), 1, 0, 0, 1, (u16)0x40);
    }
    if (var_r31 != NULL) {
        ((TObject *)var_r31)->run_task();
        fn_802F190C(var_r31, arg2);
    }
}

void TObjFish::spawn_particle(saddr arg0, s32 arg1, f32 farg0) {
    void *var_r31;

    var_r31 = TObject::operator new(0x78);
    if (var_r31 != NULL) {
        var_r31 = ((TParticleCtrl *)var_r31)->initialize_with_flags((const void *)arg0, (s32)(TParticleCtrl::get_particle_by_index(arg1)), 1, 0, 0, 1, (u16)0x40);
    }
    if (var_r31 != NULL) {
        ((TObject *)var_r31)->run_task();
        fn_802F1960(var_r31, farg0);
    }
}

extern "C" void TObjFish__sub_802F18E8(void *particle) {
    fn_802F1960(particle, -5.0f);
}
