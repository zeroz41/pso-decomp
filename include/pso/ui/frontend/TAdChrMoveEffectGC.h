#ifndef PSO_UI_FRONTEND_TADCHRMOVEEFFECTGC_H
#define PSO_UI_FRONTEND_TADCHRMOVEEFFECTGC_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TAdChrMoveEffectGC : public TObject {
    virtual ~TAdChrMoveEffectGC();
    void sub_80348E34();
    u32 m_1c;
    u32 m_20;
    void copy4(void* q);
    virtual void render();
    void reset_effect_entries();
    void clear_entries();
    void setup_move_effect_params(s32 arg1, s32 arg2);
    virtual void run_task();
    u8 unk_24[0x380];
};

typedef char TAdChrMoveEffectGC_size[sizeof(TAdChrMoveEffectGC) == 0x3A4 ? 1 : -1];

extern "C" {
void *TAdChrMoveEffectGC__ct(void *arg0);
void *__dt__18TAdChrMoveEffectGCFv(void *arg0, s16 arg1);
}

#endif
