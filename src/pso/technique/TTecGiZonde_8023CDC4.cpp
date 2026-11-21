#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/ParticleFactory.h"
#include "types.h"
#include "pso/unk/TUnk_804CCD78.h"
#include "pso/technique/TTecGiZonde_8023CDC4.h"
#include "pso/system/vector.h"

#include "pso/technique/TTecGiZonde.h"
#include "pso/system/task/TObject.h"

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern s32 __vt__13TUnk_804CCD78[];

void TUnk_804CCD78::run_task() {
    this->m_38 = (this->m_38 + 1);
    if ((s32) this->m_38 >= 0x46) {
        queue_destruction();
    }
}

}
TUnk_804CCD78::~TUnk_804CCD78() {

}

u8 *construct_helper_effect__11TTecGiZondeFPvPvPvPvi(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, s32 arg4) {
    __ct__7TObjectFP7TObject(arg0, arg3);
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__13TUnk_804CCD78;
    VecCopy((Vec *)(arg0 + 0x1C), (const Vec *)arg1);
    VecCopy((Vec *)(arg0 + 0x28), (const Vec *)arg2);
    *(s32 *)((s8 *)arg0 + 0x3C) = arg4;
    ((TUnk_804CCD78 *)arg0)->m_38 = 0;
    spawn_particle_effect_with_flags((const Vec *)(arg0 + 0x1C), *(s32 *)((s8 *)arg0 + 0x3C), 0x40);
    return arg0;
}

