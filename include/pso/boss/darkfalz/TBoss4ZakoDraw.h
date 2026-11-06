#ifndef PSO_BOSS_DARKFALZ_TBOSS4ZAKODRAW_H
#define PSO_BOSS_DARKFALZ_TBOSS4ZAKODRAW_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TBoss4ZakoDraw : public TObject {
public:
    virtual ~TBoss4ZakoDraw();
    virtual void run_task();
    virtual void render();
public:
    static void render();
};

#endif
