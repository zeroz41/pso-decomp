#ifndef PSO_BOSS_DARKFALZ_TBOSS4FADE_H
#define PSO_BOSS_DARKFALZ_TBOSS4FADE_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss4Fade : public TObject {
public:
    virtual ~TBoss4Fade();
    virtual void run_task();
    virtual void render();
};

extern "C" {
void *__ct__10TBoss4FadeFv(void *boss4_fade);
}

#endif
