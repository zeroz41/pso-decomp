#include "pso/TParticleCtrl.h"
#include "pso/TBoss6EffHyoui.h"
#include "pso/boss/TBoss4Type2_800874F4.h"
#include "pso/boss/TBoss6EffHyoui.h"
#include "pso/object/TObject_80019A50.h"

#include "types.h"

extern "C" {
void *get_player_by_client_id(s32 i);
void __ct__7TObjectFP7TObject(void *, void *);
s32 is_active__14TBoss6PlotFalzFv();
extern s32 lbl_8047AC70[];
extern s32 __vt__14TBoss6EffHyoui[];
extern s32 lbl_805D44D8;
extern f32 lbl_805D6FF8;
extern s8 lbl_805D6FFC;
extern const f32 lbl_805E0380;
}

#include "pso/boss/TBoss4Type2.h"
#include "pso/misc/TNowLoading.h"
#include "pso/player/TObjPlayer.h"

extern "C" {
void *__nw__7TObjectFUl(int);

extern void *tl_02;

void TBoss6EffHyoui::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 player;
    if ((u32) this->m_1c != 0U) {
        player = (s32)get_player_by_client_id((*(u16 *)((s8 *)arg0 + 0x20)));
        if ((player != 0) && (is_active__14TBoss6PlotFalzFv() != 0)) {
            ((TParticleCtrl *)this->m_1c)->set_position((void *)(player + 0x38));
        }
    }
    *(s32 *)((s8 *)arg0 + 0x28) = (s32) (*(s32 *)((s8 *)arg0 + 0x28) + 1);
    if ((s32) *(s32 *)((s8 *)arg0 + 0x28) > (s32) *(s32 *)((s8 *)arg0 + 0x24)) {
        queue_destruction__7TObjectFv((arg0));
    }
}

TBoss6EffHyoui::~TBoss6EffHyoui() {
    if (m_1c != nullptr) TParticleCtrl::release(m_1c);
}
void *TBoss6EffHyoui__ct(void *object, void *arg1, void *arg2, void *arg3, void *arg4) {
    u8 *self = (u8 *)object;
    u8 *p;
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)self + 0x18) = __vt__14TBoss6EffHyoui;
    *(s32 *)((s8 *)self + 0) = lbl_805D44D8;
    *(u16 *)((s8 *)self + 0x20) = (u16)(u32)arg2;
    *(void **)((s8 *)self + 0x24) = arg4;
    *(void **)((s8 *)self + 0x1C) = NULL;
    p = (u8 *)get_player_by_client_id(*(u16 *)((s8 *)self + 0x20));
    if (p != NULL && is_active__14TBoss6PlotFalzFv() != 0) {
        if (lbl_805D6FFC == 0) {
            lbl_805D6FFC = 1;
            lbl_805D6FF8 = lbl_805E0380;
        }
        if ((*(void **)((s8 *)self + 0x1C) = create_particle_emitter(p + 0x38, lbl_8047AC70[(s32)arg3])) != NULL) {
            ((TParticleCtrl *)(*(void **)((s8 *)self + 0x1C)))->set_flags(0x40);
            ((TParticleCtrl *)(*(void **)((s8 *)self + 0x1C)))->set_scale(lbl_805D6FF8, lbl_805D6FF8);
        }
    }
    *(s32 *)((s8 *)self + 0x28) = 0;
    return object;
}

void *TBoss6EffHyoui::create(void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x2C);
    if (o != NULL) {
        o = TBoss6EffHyoui__ct(o, tl_02, this, arg1, arg2);
    }
    return o;
}

}
