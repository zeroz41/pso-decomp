#ifndef PSO_ITEM_TITEMMONEY_H
#define PSO_ITEM_TITEMMONEY_H

#include "types.h"
#include <stddef.h>
#include "pso/item/TItem.h"

// Meseta, lying on the floor or held by a player; the amount travels in the
// item data's second word.
struct TItemMoney : public TItem {
    TItemMoney(TObject *parent, TItemData *data);
    virtual ~TItemMoney();
    virtual void write_item_data(TItemData *data);

    // The meseta entry of construct_item's table: NULL without data.
    static TItem *create(u8 *item);

    s32 amount;
};

LAYOUT_ASSERT(TItemMoneyAmountOffset, offsetof(TItemMoney, amount) == 0xF8);
LAYOUT_ASSERT(TItemMoneySize, sizeof(TItemMoney) == 0xFC);

// The most meseta one stack holds.
#define ITEM_MONEY_MAX 999999

#endif
