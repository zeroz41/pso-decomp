#include "types.h"
#include "pso/ui/window/TWindowDD_8034AF68.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/unk/text_8034AD38.h"

#pragma pool_data off

void push_recent_id(s16 id) {
    s32 i;
    if (id != ws_recent_state.ids[0]) {
        for (i = 15; i > 0; i--) {
            ws_recent_state.ids[i] = ws_recent_state.ids[i - 1];
        }
        ws_recent_state.ids[0] = id;
    }
}
void clear_window_dd_nodes(void) {
    if (ws_recent_state.a == NULL || ws_recent_state.b == NULL) {
        return;
    }
    ws_recent_state.a->count = ws_recent_state.n;
    ws_recent_state.b->count = ws_recent_state.n;
    ws_recent_state.a = NULL;
    ws_recent_state.b = NULL;
    ws_recent_state.a0 = 0;
    ws_recent_state.b0 = 0;
}

// lookup_item_category's id lists: an id found in a list gives that entry's category.
struct ItemCategoryIds { const s32 *ids; s32 count; s32 category; };

// Indexed [category][column] by TWindowDD__sub_8034B008.
static const s32 word_select_type_state_table[6][2] = {
    { 2, 5 }, { 3, 7 }, { 4, 12 }, { 6, 2 }, { 1, 3 }, { 1, 1 },
};
static const s32 category0_ids[] = { 11 };
static const s32 category2_ids[] = { 12 };
static const s32 category3_ids[] = { 13 };
static const s32 category4_ids[] = { 2, 15, 24, 47 };
extern s32 TWindowDD__window_mode;

void TWindowDD::init_ws_data_tables() {
    TWindowDDValueList *a = TWindowDD__ws_data_base;
    TWindowDDValueList *b;
    s32 i;
    s32 x;
    s32 y;
    if (a == NULL || (b = TWindowDD__ws_data_table) == NULL) {
        return;
    }
    for (i = 0; i < 16; i++) {
        ws_recent_state.ids[i] = -1;
    }
    ws_recent_state.a = a;
    ws_recent_state.b = b;
    ws_recent_state.a0 = a->values;
    ws_recent_state.b0 = b->values;
    if (ws_recent_state.a0 == 0 || ws_recent_state.b0 == 0) {
        return;
    }
    x = a->count;
    y = b->count;
    if (x < 1 || y < 1 || x != y) {
        return;
    }
    ws_recent_state.n = x;
}

s32 TWindowDD__sub_8034B008(s32 arg0, s32 arg1) {
    return word_select_type_state_table[TWindowDD::lookup_item_category(arg1)][arg0];
}
s32 TWindowDD::lookup_item_category(s32 arg0) {
    static ItemCategoryIds categories[4] = {
        { category0_ids, category0_id_count, 0 },
        { category2_ids, category2_id_count, 2 },
        { category3_ids, category3_id_count, 3 },
        { category4_ids, category4_id_count, 4 },
    };
    s32 r;
    s32 i;
    s32 j;
    ItemCategoryIds *e;
    const s32 *list;
    r = 5;
    for (i = 0; i < 4; i++) {
        e = &categories[i];
        list = e->ids;
        for (j = 0; j < e->count; j++) {
            if (arg0 == list[j]) {
                r = e->category;
                break;
            }
        }
        if (r != 5) {
            break;
        }
    }
    if (r == 2 && TWindowDD__window_mode == 0) {
        r = 1;
    }
    return r;
}

// Defined after lookup_item_category: its local static table comes first in .data.
WsRecentState ws_recent_state = { 0 };

__declspec(section ".sdata2") extern const s32 category0_id_count = 1;
__declspec(section ".sdata2") extern const s32 category2_id_count = 1;
__declspec(section ".sdata2") extern const s32 category3_id_count = 1;
__declspec(section ".sdata2") extern const s32 category4_id_count = 4;
