#pragma readonly_strings on

#include "types.h"
#include "pso/item/TItemMoney.h"
#include "pso/item/TItemData.h"
#include "pso/system/task/TMainTask.h"

const char *TItemMoney__name = "TItemMoney";

void TItemMoney::write_item_data(TItemData *data) { data->data2.data_u32 = amount; }

TItemMoney::~TItemMoney() {}

// Built without copy propagation: the clamp keeps its limit in a register.
#pragma push
#pragma opt_propagation off
TItemMoney::TItemMoney(TObject *parent, TItemData *data) : TItem(parent, (u8 *)data) {
    s32 max = ITEM_MONEY_MAX;
    m_name = TItemMoney__name;
    amount = data->data2.data_u32;
    if (max < amount) {
        amount = max;
    }
}
#pragma pop

TItem *TItemMoney::create(u8 *item) {
    if (item != NULL) {
        return new TItemMoney(tl_05, reinterpret_cast<TItemData *>(item));
    }
    return NULL;
}
