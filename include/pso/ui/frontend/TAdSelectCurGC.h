#ifndef PSO_UI_FRONTEND_TADSELECTCURGC_H
#define PSO_UI_FRONTEND_TADSELECTCURGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TAdSelectCurGC : public TObject {
public:
    virtual ~TAdSelectCurGC();
    virtual void run_task();
public:
    virtual void render();
};

#endif
