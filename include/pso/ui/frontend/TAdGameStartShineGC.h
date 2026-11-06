#ifndef PSO_UI_FRONTEND_TADGAMESTARTSHINEGC_H
#define PSO_UI_FRONTEND_TADGAMESTARTSHINEGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TAdGameStartShineGC : public TObject {
public:
    virtual ~TAdGameStartShineGC();
    void render_status_box();
    virtual void run_task();
    virtual void render();
};

#endif
