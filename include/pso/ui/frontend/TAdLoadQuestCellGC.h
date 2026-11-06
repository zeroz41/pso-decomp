#ifndef PSO_UI_FRONTEND_TADLOADQUESTCELLGC_H
#define PSO_UI_FRONTEND_TADLOADQUESTCELLGC_H

#include "pso/system/task/TObject.h"
#include <stddef.h>

class TAdLoadQuestCellGC : public TObject {
public:
    TAdLoadQuestCellGC(TObject *arg1, void *arg2);
    virtual ~TAdLoadQuestCellGC();
    virtual void run_task();
    virtual void render();
    s32 m_state;
    s32 m_frameCount;
public:
    void render_state();
};

typedef char TAdLoadQuestCellGCFrameOffset[(offsetof(TAdLoadQuestCellGC, m_frameCount) == 0x20) ? 1 : -1];
typedef char TAdLoadQuestCellGCSize[sizeof(TAdLoadQuestCellGC) == 0x24 ? 1 : -1];
typedef char TAdLoadQuestCellGCStateOffset[offsetof(TAdLoadQuestCellGC, m_state) == 0x1C ? 1 : -1];

extern "C" {
s32 get_or_create_cell__14TAdLoadQuestGCFii(s32 arg0, s32 arg1);
}

#endif
