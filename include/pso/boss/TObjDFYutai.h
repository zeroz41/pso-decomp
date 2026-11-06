#ifndef PSO_BOSS_TOBJDFYUTAI_H
#define PSO_BOSS_TOBJDFYUTAI_H

#include "pso/TObject.h"
#include "types.h"

class TObjDFYutai : public TObject {
public:
    virtual ~TObjDFYutai();
    virtual void run_task();
    virtual void render();
};

extern "C" {
void *__ct__11TObjDFYutaiFv(void *arg0, s32 arg1, s32 arg2, s16 arg3);
}

#endif
