#ifndef PSO_UI_FRONTEND_TADLOADQUESTCELLGC_H
#define PSO_UI_FRONTEND_TADLOADQUESTCELLGC_H

#include "pso/system/task/TObject.h"
#include <stddef.h>

class TAdLoadQuestCellGC : public TObject {
public:
    TAdLoadQuestCellGC(TObject *parent, s32 state);
    virtual ~TAdLoadQuestCellGC();
    virtual void run_task();
    virtual void render();
    s32 m_state;
    s32 m_frameCount;
public:
    void render_state();
};

LAYOUT_ASSERT(TAdLoadQuestCellGCFrameOffset, offsetof(TAdLoadQuestCellGC, m_frameCount) == 0x20);
LAYOUT_ASSERT(TAdLoadQuestCellGCSize, sizeof(TAdLoadQuestCellGC) == 0x24);
LAYOUT_ASSERT(TAdLoadQuestCellGCStateOffset, offsetof(TAdLoadQuestCellGC, m_state) == 0x1C);

extern "C" TAdLoadQuestCellGC *ad_load_quest_cell_table[3];

#endif
