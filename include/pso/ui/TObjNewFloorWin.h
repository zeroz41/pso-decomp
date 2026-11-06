#ifndef PSO_UI_TOBJNEWFLOORWIN_H
#define PSO_UI_TOBJNEWFLOORWIN_H

#include "pso/TObject.h"
#include "types.h"

class TObjNewFloorWin : public TObject {
public:
    TObjNewFloorWin(TObject *arg1, void *arg2);
    virtual ~TObjNewFloorWin();
    virtual void run_task();
public:
    void open_window();
};

extern "C" {
void fn_800740DC(void);
}

#endif
