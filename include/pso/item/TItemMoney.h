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
    static TItem *create(TItemData *data);

    s32 amount;
};

typedef char TItemMoneyAmountOffset[(offsetof(TItemMoney, amount) == 0xF8) ? 1 : -1];
typedef char TItemMoneySize[(sizeof(TItemMoney) == 0xFC) ? 1 : -1];

// The most meseta one stack holds.
#define ITEM_MONEY_MAX 999999

#endif
