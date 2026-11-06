#ifndef PSO_UI_FRONTEND_TADRICORING_H
#define PSO_UI_FRONTEND_TADRICORING_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TAdRicoRing : public TObject {
public:
    virtual ~TAdRicoRing();
    virtual void run_task();
    virtual void render();
public:
    void update_position();
};

extern "C" {
u8 *__ct__11TAdRicoRingFv(u8 *arg0, void *parent);
}

#endif
