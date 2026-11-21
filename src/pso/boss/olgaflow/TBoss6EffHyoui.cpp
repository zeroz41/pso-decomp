#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/olgaflow/TBoss6EffHyoui.h"
#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/system/task/TObject_80019A50.h"

#include "types.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"

extern "C" {
const char *lbl_805D44D8 = "TBoss6EffHyoui";
f32 lbl_805D6FF8;
s8 lbl_805D6FFC;
}

#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/player/TObjPlayer.h"

extern "C" {

extern void *tl_02;

void TBoss6EffHyoui::run_task() {
    u8 *arg0 = (u8 *)this;
    saddr player;
    if ((uaddr) this->m_1c != 0U) {
        player = (saddr)get_player_by_client_id((*(u16 *)((s8 *)arg0 + 0x20)));
        if ((player != 0) && (((TObjPlayer *)player)->is_active() != 0)) {
            ((TParticleCtrl *)this->m_1c)->set_position((void *)(player + 0x38));
        }
    }
    *(s32 *)((s8 *)arg0 + 0x28) = (s32) (*(s32 *)((s8 *)arg0 + 0x28) + 1);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x28) > (s32) *(s32 *)((s8 *)arg0 + 0x24)) {
        ((TObject *)arg0)->queue_destruction();
    }
}

TBoss6EffHyoui::~TBoss6EffHyoui() {
    if (m_1c != nullptr) TParticleCtrl::release(m_1c);
}
const s32 lbl_8047AC70[2] = {550, 551};

}

TBoss6EffHyoui::TBoss6EffHyoui(TObject *arg1, void *arg2, void *arg3, void *arg4) : TObject(arg1) {
    u8 *self = (u8 *)this;
    u8 *p;
    m_name = lbl_805D44D8;
    *(u16 *)((s8 *)self + 0x20) = (u16)(uaddr)arg2;
    *(void **)((s8 *)self + 0x24) = arg4;
    *(void **)((s8 *)self + 0x1C) = NULL;
    p = (u8 *)get_player_by_client_id(*(u16 *)((s8 *)self + 0x20));
    if (p != NULL && ((TObjPlayer *)p)->is_active() != 0) {
        if (lbl_805D6FFC == 0) {
            lbl_805D6FFC = 1;
            lbl_805D6FF8 = 0.2f;
        }
        if ((*(void **)((s8 *)self + 0x1C) = create_particle_emitter(p + 0x38, lbl_8047AC70[(saddr)arg3])) != NULL) {
            ((TParticleCtrl *)(*(void **)((s8 *)self + 0x1C)))->set_flags(0x40);
            ((TParticleCtrl *)(*(void **)((s8 *)self + 0x1C)))->set_scale(lbl_805D6FF8, lbl_805D6FF8);
        }
    }
    *(s32 *)((s8 *)self + 0x28) = 0;
}

extern "C" {

void *TBoss6EffHyoui::create(void *arg1, void *arg2) {
    return new TBoss6EffHyoui((TObject *)tl_02, this, arg1, arg2);
}

}
