#ifndef PSO_UI_TADSELECTTXTSUBGC_H
#define PSO_UI_TADSELECTTXTSUBGC_H

#include "pso/TObject.h"
#include "types.h"

class TAdSelectTxtSubGC : public TObject {
public:
    virtual ~TAdSelectTxtSubGC();
    void render_status();
    virtual void run_task();
    virtual void render();
};

extern "C" {
void *TObjNpcHosa__create(void *arg0);
int TObjNpcHosa__sub_802A39B0(void);
}

#endif
