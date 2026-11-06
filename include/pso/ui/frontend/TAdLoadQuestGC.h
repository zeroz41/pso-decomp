#ifndef PSO_UI_FRONTEND_TADLOADQUESTGC_H
#define PSO_UI_FRONTEND_TADLOADQUESTGC_H
#include "pso/system/task/TObject.h"
#include <stddef.h>

class TAdLoadQuestGC : public TObject {
public:
    virtual ~TAdLoadQuestGC();
    virtual void run_task();
    virtual void render();
    TObject *quest_display;
};
typedef char TAdLoadQuestGCDisplayOffset[offsetof(TAdLoadQuestGC, quest_display) == 0x1C ? 1 : -1];

extern "C" {
s32 create_cost_window(s32 arg0);
}

// --- C functions defined in TAdLoadQuestGC.cpp ---
extern "C" {
s32 create_cost_window(s32 arg0);
}
// --- end of C functions

extern "C" {
void *TAdLoadQuestGC__ct(void *ad_load_quest_gc, TObject *parent);
void TAdLoadQuestGC__sub_8030984C(void);
void TAdLoadQuestGC__sub_80309850(void);
int TAdLoadQuestGC__sub_80309854(int a0);
int TAdLoadQuestGC__sub_80309868(int a0);
int TAdLoadQuestGC__sub_8030987C(int a0);
}

#endif
