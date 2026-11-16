#ifndef PSO_BOSS_DARKFALZ_TOBJDFYUTAI_H
#define PSO_BOSS_DARKFALZ_TOBJDFYUTAI_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjDFYutai : public TObject {
public:
    TObjDFYutai(s32, s32, s16);
    virtual ~TObjDFYutai();
    virtual void run_task();
    virtual void render();
};

extern "C" {
void *__ct__11TObjDFYutaiFlls(void *arg0, s32 arg1, s32 arg2, s16 arg3);
}

#endif
