#ifndef PSO_EFFECT_TDUELEFFECTCTRL_H
#define PSO_EFFECT_TDUELEFFECTCTRL_H

#include "pso/system/task/TObject.h"
#include <stddef.h>

class TDuelEffectCtrl : public TObject {
public:
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

typedef char DuelFrameOffset[(offsetof(TDuelEffectCtrl, m_frameCount) == 0x20) ? 1 : -1];
typedef char DuelEffectOffset[(offsetof(TDuelEffectCtrl, m_effect) == 0x24) ? 1 : -1];
typedef char DuelControllerSize[(sizeof(TDuelEffectCtrl) == 0x28) ? 1 : -1];
#endif
