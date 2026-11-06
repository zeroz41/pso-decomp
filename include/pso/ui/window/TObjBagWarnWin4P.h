#ifndef PSO_UI_WINDOW_TOBJBAGWARNWIN4P_H
#define PSO_UI_WINDOW_TOBJBAGWARNWIN4P_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TObjBagWarnWin4P : public TObject {
public:
    virtual ~TObjBagWarnWin4P();
    virtual void run_task();
public:
    static s32 check_can_open(void * _w0);
    void create_window();
};

#endif
