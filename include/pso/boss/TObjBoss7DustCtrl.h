#ifndef PSO_BOSS_TOBJBOSS7DUSTCTRL_H
#define PSO_BOSS_TOBJBOSS7DUSTCTRL_H

#include "pso/TObject.h"
#include "types.h"

class TObjBoss7DustCtrl : public TObject {
public:
    virtual ~TObjBoss7DustCtrl();
    virtual void run_task();
public:
    static void create();
};

extern "C" {
void *TObjBoss7DustCtrl__ct(void *boss7_dust_ctrl);
s32 TObjBoss7DustCtrl__sub_802F125C(void);
void TObjBoss7DustCtrl__sub_802F1450(void);
void boss7_dust_draw_at(s32 *arg0, s32 arg1);
void fn_802F1454(void);
}

#endif
