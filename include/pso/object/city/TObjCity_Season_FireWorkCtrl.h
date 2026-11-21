#ifndef PSO_OBJECT_CITY_TOBJCITY_SEASON_FIREWORKCTRL_H
#define PSO_OBJECT_CITY_TOBJCITY_SEASON_FIREWORKCTRL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjCity_Season_FireWorkCtrl : public TObjBase {
    TObjCity_Season_FireWorkCtrl(TObject *parent, void *set_data);
    virtual ~TObjCity_Season_FireWorkCtrl();
    virtual void vfunc_13(s32);
    void sub_8018355C();
    virtual void run_task();

    s32 unk_90;
};

LAYOUT_ASSERT(TObjCity_Season_FireWorkCtrl_size, sizeof(TObjCity_Season_FireWorkCtrl) == 0x94);
#endif
