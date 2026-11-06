#ifndef PSO_UI_TADGAMESTARTBACKGC_H
#define PSO_UI_TADGAMESTARTBACKGC_H

#include "pso/TObject.h"
#include "types.h"

class TAdGameStartBackGC : public TObject {
public:
    virtual ~TAdGameStartBackGC();
    virtual void run_task();
    virtual void render();
public:
    void render_background_status();
};

extern "C" {
u8 *__ct__18TAdGameStartBackGCFv(u8 *arg0, u8 *arg1);
}

#endif
