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

typedef char TAdLoadQuestLineGCFrameOffset[(offsetof(TAdLoadQuestLineGC, m_frameCount) == 0x20) ? 1 : -1];
typedef char TAdLoadQuestLineGCSize[sizeof(TAdLoadQuestLineGC) == 0x24 ? 1 : -1];
typedef char TAdLoadQuestLineGCStateOffset[offsetof(TAdLoadQuestLineGC, m_state) == 0x1C ? 1 : -1];

extern "C" {
s32 get_or_create_line__14TAdLoadQuestGCFii(s32 arg0, s32 arg1);
}

#endif
