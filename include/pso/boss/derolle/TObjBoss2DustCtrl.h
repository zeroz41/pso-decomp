#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2DUSTCTRL_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2DUSTCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjBoss2DustCtrl : public TObject {
public:
    virtual ~TObjBoss2DustCtrl();
    virtual void run_task();
public:
    static void create();
};

extern "C" {
void *TObjBoss2DustCtrl__ct(void *arg0);
void TObjBoss2DustCtrl__sub_8003AB5C(void);
void TObjBoss2DustCtrl__sub_8003AD50(void);
void boss2_dust_draw_at(s32 *arg0, s32 arg1);
void fn_8003AD54(void);
}

#endif
