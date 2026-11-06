#ifndef PSO_UI_FRONTEND_TADGAMESTARTSHADOWGC_H
#define PSO_UI_FRONTEND_TADGAMESTARTSHADOWGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TAdGameStartShadowGC : public TObject {
public:
    virtual ~TAdGameStartShadowGC();
    void sub_80320B38();
    virtual void run_task();
    virtual void render();
};

#endif
