#ifndef PSO_UI_FRONTEND_TADLOADQUESTLINEGC_H
#define PSO_UI_FRONTEND_TADLOADQUESTLINEGC_H

#include "pso/system/task/TObject.h"
#include <stddef.h>

class TAdLoadQuestLineGC : public TObject {
public:
    TAdLoadQuestLineGC(TObject *arg1, void *arg2);
    virtual ~TAdLoadQuestLineGC();
    virtual void run_task();
    virtual void render();
    s32 m_state;
    s32 m_frameCount;
public:
    void render_by_state();
};

LAYOUT_ASSERT(TAdLoadQuestLineGCFrameOffset, offsetof(TAdLoadQuestLineGC, m_frameCount) == 0x20);
LAYOUT_ASSERT(TAdLoadQuestLineGCSize, sizeof(TAdLoadQuestLineGC) == 0x24);
LAYOUT_ASSERT(TAdLoadQuestLineGCStateOffset, offsetof(TAdLoadQuestLineGC, m_state) == 0x1C);

extern "C" {
s32 get_or_create_line__14TAdLoadQuestGCFii(saddr arg0, saddr arg1);
}

#endif
