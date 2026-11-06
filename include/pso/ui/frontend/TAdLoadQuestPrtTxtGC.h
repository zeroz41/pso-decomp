#ifndef PSO_UI_FRONTEND_TADLOADQUESTPRTTXTGC_H
#define PSO_UI_FRONTEND_TADLOADQUESTPRTTXTGC_H

#include "types.h"
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
    s32 m_224;
    virtual void render();
    static void *create_particle(void *arg0, s32 arg1, s32 arg2);
    virtual void run_task();
};

typedef char TAdLoadQuestPrtTxtGC_size[sizeof(TAdLoadQuestPrtTxtGC) == 0x228 ? 1 : -1];
#endif
