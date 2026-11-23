#ifndef PSO_EFFECT_TDUELEFFECTCTRL_H
#define PSO_EFFECT_TDUELEFFECTCTRL_H

#include "pso/system/task/TObject.h"
#include <stddef.h>

class TDuelEffectCtrl : public TObject {
public:
    static const char *class_name;
    TDuelEffectCtrl(TObject* parent, u8 state);
    virtual ~TDuelEffectCtrl();
    void update_duel_end_effect();
    void update_duel_start_countdown();
    virtual void run_task();
    virtual void render();
    u8 m_state;
    u8 m_padding[3];
    s32 m_frameCount;
    TObject* m_effect;
};

LAYOUT_ASSERT(DuelFrameOffset, offsetof(TDuelEffectCtrl, m_frameCount) == 0x20);
LAYOUT_ASSERT(DuelEffectOffset, offsetof(TDuelEffectCtrl, m_effect) == 0x24);
LAYOUT_ASSERT(DuelControllerSize, sizeof(TDuelEffectCtrl) == 0x28);
#endif
