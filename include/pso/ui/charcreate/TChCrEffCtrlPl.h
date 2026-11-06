#ifndef PSO_UI_CHARCREATE_TCHCREFFCTRLPL_H
#define PSO_UI_CHARCREATE_TCHCREFFCTRLPL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TChCrEffCtrlPl : public TObject {
public:
    TChCrEffCtrlPl(TObject *_w1);
    virtual ~TChCrEffCtrlPl();
    virtual void run_task();
    virtual void render();
public:
    static s32 get_clamped_player_index();
    void *create();
};

extern "C" {
int TChCrEffCtrlPl__sub_80298F6C(void *p);
}

#endif
