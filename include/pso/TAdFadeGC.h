#ifndef PSO_TADFADEGC_H
#define PSO_TADFADEGC_H
#include "pso/TObject.h"
#include "types.h"

class TAdFadeGC : public TObject {
public:
    TAdFadeGC(TObject *arg1, void *arg2);
    virtual ~TAdFadeGC();
    virtual void run_task();
    virtual void render();
public:
    void draw_fade();
    void start_fade(void *arg1);

    u8 pad_1c[0x1C]; // every construction site allocates 0x38 bytes
};

#endif
