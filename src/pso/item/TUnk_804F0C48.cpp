#include "types.h"
#include "pso/TMainTask.h"
#include "pso/item/TItem.h"
#include "pso/unk/TUnk_804F0C48.h"
#include "pso/player/TObjPlayer.h"

#include "pso/item/TItemData.h"

// What the item can turn into: item codes with their weights out of 256.
struct ItemChoice { u8 code[3]; u8 weight; };

struct ItemChoiceList { s32 count; ItemChoice *choices; };

extern "C" {
ItemChoiceList *get_item_pmt_entry__10TObjPlayerFUc(u8);
s32 rand(void);
extern const f32 lbl_805DFE28;
extern const f32 lbl_805DFE2C;
}

void TUnk_804F0C48::apply_use_effect() {
    ItemChoiceList *list;
    list = get_item_pmt_entry__10TObjPlayerFUc(this->get_item_index());
    if (list != NULL) {
        s32 r = (s32)(lbl_805DFE28 * (lbl_805DFE2C * (f32)rand()));
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

TUnk_804F0C48::~TUnk_804F0C48() {}

TUnk_804F0C48::TUnk_804F0C48(TObject *parent, u8 *item) : TItemObject(parent, item) {
    clear_item_flags(ITEM_FLAG_CONSUMABLE);
}

TUnk_804F0C48 *TUnk_804F0C48::create(u8 *item) {
    if (item != NULL) {
        return new TUnk_804F0C48(tl_05, item);
    }
    return NULL;
}
