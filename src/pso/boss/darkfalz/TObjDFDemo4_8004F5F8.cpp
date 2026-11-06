#include "types.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/effect/particle/TParticleCtrl.h"
struct S_8004F5F8 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x90 - 0x1c];
    u8 f90[0x14];
    void *ptr[2];
    u8 padac[0x100 - 0xac];
    void *f100;
};

extern "C" {
void fn_8004AA04(void *);
void __dl__7TObjectFPv(void *);
extern u8 lbl_80485764[];
S_8004F5F8 *__dt__11TObjDFDemo4Fv(S_8004F5F8 *o, s16 flag);
S_8004F5F8 *__dt__11TObjDFDemo4Fv(S_8004F5F8 *o, s16 flag) {
    s32 i;
    if (o != 0) {
        o->vt = lbl_80485764;
        fn_8004AA04(o->f90);
        if (o->f100 != 0) {
            TObjFish::init_state_1(o->f100);
            o->f100 = 0;
        }
        for (i = 0; i < 2; i++) {
            if (o->ptr[i] != 0) {
                TParticleCtrl::release(o->ptr[i]);
                o->ptr[i] = 0;
            }
        }
        restore_player_cameras();
        __dt__8TObjBaseFv(o, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(o);
        }
    }
    return o;
}

}
