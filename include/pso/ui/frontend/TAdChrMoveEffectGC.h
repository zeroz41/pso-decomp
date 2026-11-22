#ifndef PSO_UI_FRONTEND_TADCHRMOVEEFFECTGC_H
#define PSO_UI_FRONTEND_TADCHRMOVEEFFECTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdChrMoveEffectGC : public TObject {
    TAdChrMoveEffectGC(TObject *parent);
    virtual ~TAdChrMoveEffectGC();
    void sub_80348E34();
    u32 m_1c;
    u32 m_20;
    virtual void render();
    void reset_effect_entries();
    void clear_entries();
    void setup_move_effect_params(s32 arg1, s32 arg2);
    virtual void run_task();
    u8 unk_24[0x380];
};

LAYOUT_ASSERT(TAdChrMoveEffectGC_size, sizeof(TAdChrMoveEffectGC) == 0x3A4);

extern TAdChrMoveEffectGC *lbl_805D6E78;

extern "C" {
void *__dt__18TAdChrMoveEffectGCFv(void *arg0, s16 arg1);
}

#endif
