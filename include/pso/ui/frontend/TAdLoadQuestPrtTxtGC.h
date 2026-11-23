#ifndef PSO_UI_FRONTEND_TADLOADQUESTPRTTXTGC_H
#define PSO_UI_FRONTEND_TADLOADQUESTPRTTXTGC_H

#include "types.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

class TParticleCtrl;

struct TAdLoadQuestPrtTxtGC : public TObject {
    TAdLoadQuestPrtTxtGC(TObject *parent, s32 slot);
    virtual ~TAdLoadQuestPrtTxtGC();
    s32 particle_count;
    TParticleCtrl *particles[32];
    Vec particle_pos[32];
    // Index into quest_load_prt_txt_by_slot; also selects the particle layout.
    s32 slot;
    s32 timer;
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TAdLoadQuestPrtTxtGC_size, sizeof(TAdLoadQuestPrtTxtGC) == 0x228);
LAYOUT_ASSERT(TAdLoadQuestPrtTxtGCSlotOffset, offsetof(TAdLoadQuestPrtTxtGC, slot) == 0x220);
LAYOUT_ASSERT(TAdLoadQuestPrtTxtGCTimerOffset, offsetof(TAdLoadQuestPrtTxtGC, timer) == 0x224);

extern "C" TAdLoadQuestPrtTxtGC *quest_load_prt_txt_by_slot[3];

#endif
