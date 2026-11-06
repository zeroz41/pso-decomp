#ifndef PSO_UI_FRONTEND_TADMCSELECTMCGC_H
#define PSO_UI_FRONTEND_TADMCSELECTMCGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TAdMcSelectMcGC : public TObject {
public:
    virtual ~TAdMcSelectMcGC();
public:
    void draw_status_window();
    virtual void render();
    virtual void run_task();
};

#endif
