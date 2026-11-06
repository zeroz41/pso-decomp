#ifndef PSO_UI_FRONTEND_TADSELECTGAMEMODEGC_H
#define PSO_UI_FRONTEND_TADSELECTGAMEMODEGC_H
#include "pso/system/task/TObject.h"
#include "types.h"

class TAdSelectGameModeGC : public TObject {
public:
    virtual ~TAdSelectGameModeGC();
    virtual void run_task();
public:
    static int get_mode_data();
    static void enable_camera();
    void free_sub_ctrls();
    virtual void render();
    static int call_enable_camera(void* p);
};

#endif
