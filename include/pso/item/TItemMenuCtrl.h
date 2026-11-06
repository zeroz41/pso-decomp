#ifndef PSO_ITEM_TITEMMENUCTRL_H
#define PSO_ITEM_TITEMMENUCTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TItemMenuCtrl : public TObject {
public:
    virtual ~TItemMenuCtrl();
public:
    static s32 query_flag(s32 arg0);
    static void open_menu(u32 arg0);
    int set_menu_flags();
};

#endif
