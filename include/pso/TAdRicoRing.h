#ifndef PSO_TADRICORING_H
#define PSO_TADRICORING_H
#include "pso/TObject.h"
#include "types.h"

class TAdRicoRing : public TObject {
public:
    virtual ~TAdRicoRing();
    virtual void run_task();
    virtual void render();
public:
    void update_position();
};

#endif
