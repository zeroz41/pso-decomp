#ifndef PSO_BOSS_DEROLLE_TOBJBOSS2DUSTCTRL_H
#define PSO_BOSS_DEROLLE_TOBJBOSS2DUSTCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include <dolphin/mtx.h>

class TObjBoss2DustCtrl : public TObject {
public:
    TObjBoss2DustCtrl(TObject *parent);
    virtual ~TObjBoss2DustCtrl();
    virtual void run_task();
public:
    static void create();
};

extern "C" {
s32 TObjBoss2DustCtrl__sub_8003AB5C(void);
void TObjBoss2DustCtrl__sub_8003AD50(void);
}
void boss2_dust_draw_at(const Vec *position, s32 slot);
extern "C" {
void fn_8003AD54(void);
}

#endif
