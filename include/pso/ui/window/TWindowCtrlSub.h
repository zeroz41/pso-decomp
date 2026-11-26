#ifndef PSO_UI_WINDOW_TWINDOWCTRLSUB_H
#define PSO_UI_WINDOW_TWINDOWCTRLSUB_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TWindowCtrlSub : public TObject {
public:
    static const char *class_name;
    TWindowCtrlSub(TObject *parent);
    virtual ~TWindowCtrlSub();
    virtual void run_task();
};

#endif
