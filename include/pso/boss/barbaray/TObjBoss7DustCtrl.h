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
    // Twins of TObjBoss2DustCtrl's sub_8003AB5C (next strip slot), sub_8003AD50 (empty) and
    // sub_8003AD54 (builds the strip tables).
    static s32 sub_802F125C();
    static void sub_802F1450();
    static void sub_802F1454();
};

void boss7_dust_draw_at(const Vec *position, s32 slot);

#endif
