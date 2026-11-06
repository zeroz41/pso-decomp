#ifndef PSO_UI_FRONTEND_TADSUBPLYITEMGC_H
#define PSO_UI_FRONTEND_TADSUBPLYITEMGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TAdSubPlyItemGC : public TObject {
public:
    virtual ~TAdSubPlyItemGC();
    virtual void render();
    virtual void run_task();
public:
    int render_status_line(int a1);
};

#endif
