#ifndef PSO_BOSS_DARKFALZ_TBOSS4CHECKEMPTY_H
#define PSO_BOSS_DARKFALZ_TBOSS4CHECKEMPTY_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss4CheckEmpty : public TObject {
public:
    TBoss4CheckEmpty(TObject *parent);
    virtual ~TBoss4CheckEmpty();
    virtual void run_task();
    virtual void render();
public:
    static void render();
    static void *create();

    s32 m_wait_frames; // 0x1C, frames counted before the boss-4 check (inferred name)
};

#endif
