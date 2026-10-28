#ifndef PSO_ITEM_TUNK_8049FE00_H
#define PSO_ITEM_TUNK_8049FE00_H
#include "types.h"
#include "pso/item/TItemObject.h"

class TUnk_8049FE00 : public TItemObject {
public:
    TUnk_8049FE00(TObject *parent, u8 *item);
    virtual ~TUnk_8049FE00();
    virtual void apply_use_effect();
    static TUnk_8049FE00 *create(u8 *item);
    // The TP the three kinds give (by item index).
    int get_max_tp();
    int calc_large_tp();
    int calc_small_tp();
};

#endif
