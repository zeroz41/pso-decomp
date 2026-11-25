#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/item/TItem.h"
#include "pso/item/TItemToolRandomItem.h"
#include "pso/player/TObjPlayer.h"

#include "pso/item/TItemData.h"
#include "pso/item/item_pmt.h"
#include <stdlib.h>




void TItemToolRandomItem::apply_use_effect() {
    ItemChoiceList *list;
    list = (ItemChoiceList *)TObjPlayer::get_item_pmt_entry(this->get_item_index());
    if (list != NULL) {
        s32 r = (s32)(100.0f * (3.0517578e-05f * (f32)rand()));
        ItemChoice *choice = list->choices;
        s32 i;
        for (i = list->count; i != 0; i++) {
            if ((u8)r < choice->weight) {
                TItemData data;
                data.data1.data_u8[0] = choice->code[0];
                data.data1.data_u8[1] = choice->code[1];
                data.data1.data_u8[2] = choice->code[2];
                replace_item_with_new_code(&data, (TItem *)this);
                return;
            }
            r -= choice->weight;
            choice++;
        }
    }
    consume_item_by_id(this->get_item_id());
}

TItemToolRandomItem::~TItemToolRandomItem() {}

TItemToolRandomItem::TItemToolRandomItem(TObject *parent, u8 *item) : TItemObject(parent, item) {
    clear_item_flags(ITEM_FLAG_CONSUMABLE);
}

TItem *TItemToolRandomItem::create(u8 *item) {
    if (item != NULL) {
        return new TItemToolRandomItem(tl_05, item);
    }
    return NULL;
}
