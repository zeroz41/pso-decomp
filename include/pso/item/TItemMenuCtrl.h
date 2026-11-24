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
    static s32 query_flag(s32 arg0);
    static void open_menu(u32 arg0);
    void set_menu_flags(u32 mask);

    FlagWord menu_flags;
};

LAYOUT_ASSERT(TItemMenuCtrlSize, sizeof(TItemMenuCtrl) == 0x20);
LAYOUT_ASSERT(TItemMenuCtrlFlagsOffset, offsetof(TItemMenuCtrl, menu_flags) == 0x1C);

extern TItemMenuCtrl *TItemMenuCtrl__instance;

#endif
