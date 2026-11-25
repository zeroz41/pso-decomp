#ifndef PSO_UI_FRONTEND_TADFLOORLOADGC_H
#define PSO_UI_FRONTEND_TADFLOORLOADGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TAdFloorLoadGC : public TObject {
public:
    TAdFloorLoadGC(TObject *parent, s32 mode);
    virtual ~TAdFloorLoadGC();
    virtual void run_task();
    virtual void render();
public:
};

#endif
