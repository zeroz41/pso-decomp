#ifndef PSO_ITEM_TITEMMENUCTRL_H
#define PSO_ITEM_TITEMMENUCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"
#include "pso/system/data/FlagWord.h"
#include <stddef.h>

class TItemMenuCtrl : public TObject {
public:
    TItemMenuCtrl(TObject *parent);
    virtual ~TItemMenuCtrl();
public:
    static s32 query_flag(s32 flag_bit);
    static void open_menu(u32 menu);
    void set_menu_flags(u32 mask);

    FlagWord menu_flags;
    static TItemMenuCtrl *instance;
};

LAYOUT_ASSERT(TItemMenuCtrlSize, sizeof(TItemMenuCtrl) == 0x20);
LAYOUT_ASSERT(TItemMenuCtrlFlagsOffset, offsetof(TItemMenuCtrl, menu_flags) == 0x1C);


struct Vec;
struct StarLightParameters;
class TEffStarLight2D;

void advance_angle_wrap(s32 *angle, s32 blade_speed);
TEffStarLight2D *spawn_star_light_2d(const Vec *position, const StarLightParameters *parameters, TObject *parent);
s32 decrement_timer(u32 *packed, s32 step);

#endif
