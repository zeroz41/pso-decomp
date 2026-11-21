#ifndef PSO_BOSS_BARBARAY_TOBJBOSS7DUSTCTRL_H
#define PSO_BOSS_BARBARAY_TOBJBOSS7DUSTCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

class TObjBoss7DustCtrl : public TObject {
public:
    TObjBoss7DustCtrl(TObject *parent);
    virtual ~TObjBoss7DustCtrl();
    virtual void run_task();
public:
    static void create();
};

extern "C" {
s32 TObjBoss7DustCtrl__sub_802F125C(void);
void TObjBoss7DustCtrl__sub_802F1450(void);
}
void boss7_dust_draw_at(const Vec *position, s32 slot);
extern "C" {
void fn_802F1454(void);
}

#endif
