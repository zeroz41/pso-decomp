#ifndef PSO_UI_FRONTEND_TADMULTIPLAYERNOGC_H
#define PSO_UI_FRONTEND_TADMULTIPLAYERNOGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TAdMultiPlayerNoGC : public TObject {
public:
    virtual ~TAdMultiPlayerNoGC();
    virtual void run_task();
    virtual void render();
public:
    void render_status();
    static void run_task();
};

#endif
