#ifndef PSO_ITEM_DROP_TITEMDROPSUB_H
#define PSO_ITEM_DROP_TITEMDROPSUB_H

#include "pso/system/task/TObject.h"
#include "types.h"

// The quest's box drop area: quest opcode ba_set_box_drop_area creates the
// single instance and sets it; boxes of drop areas 0x10 and 0x11 drop from it.
class TItemDropSub : public TObject {
public:
    s32 box_drop_area;
    TItemDropSub(TObject *parent);
    virtual ~TItemDropSub();
public:
    static void create_instance(s32 area);
    static s32 get_box_drop_area();

    static TItemDropSub *instance;
};

#endif
