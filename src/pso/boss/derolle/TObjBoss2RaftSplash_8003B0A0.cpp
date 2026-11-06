#include "types.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/derolle/TObjBoss2RaftSplash.h"

struct Base_8003B0A0 { char pad[0x18]; };
struct VObj_8003B0A0 : Base_8003B0A0 {
    virtual void m0();
    virtual void m1();
};

extern "C" {

void *__nw__7TObjectFUl(s32);

void TObjBoss2RaftSplash::spawn_splash(s32 position, s32 arg1, s32 arg2) {
    void *var_r31;

    var_r31 = __nw__7TObjectFUl(0x78);
    if (var_r31 != NULL) {
        var_r31 = ((TParticleCtrl *)var_r31)->initialize_with_flags((const void *)position, (s32)(TParticleCtrl::get_particle_by_index(arg1)), 1, 0, 0, 1, (u16)0x40);
    }
    if (var_r31 != NULL) {
        ((VObj_8003B0A0 *)var_r31)->m1();
        ((TObjBoss2Tunnel *)var_r31)->detach_children((void *)arg2);
    }
}

}
