#include "types.h"
#include "pso/ui/window/TWindowDD.h"

#pragma pool_data off

extern "C" void push_recent_id(s16 id) {
    s32 i;
    if (id != ws_recent_state.ids[0]) {
        for (i = 15; i > 0; i--) {
            ws_recent_state.ids[i] = ws_recent_state.ids[i - 1];
        }
        ws_recent_state.ids[0] = id;
    }
}
void clear_window_dd_nodes(void) {
    if (ws_recent_state.data_base == NULL || ws_recent_state.data_table == NULL) {
        return;
    }
    ws_recent_state.data_base->count = ws_recent_state.entry_count;
    ws_recent_state.data_table->count = ws_recent_state.entry_count;
    ws_recent_state.data_base = NULL;
    ws_recent_state.data_table = NULL;
    ws_recent_state.data_base_values = 0;
    ws_recent_state.data_table_values = 0;
}

// Indexed [category][column] by get_word_select_type_state.
static const s32 word_select_type_state_table[6][2] = {
    { 2, 5 }, { 3, 7 }, { 4, 12 }, { 6, 2 }, { 1, 3 }, { 1, 1 },
};
static const s32 category0_ids[] = { 11 };
static const s32 category2_ids[] = { 12 };
static const s32 category3_ids[] = { 13 };
static const s32 category4_ids[] = { 2, 15, 24, 47 };

void init_ws_data_tables() {
    TWindowDDValueList *a = TWindowDD::ws_data_base;
    TWindowDDValueList *b;
    s32 i;
    s32 x;
    s32 y;
    if (a == NULL || (b = TWindowDD::ws_data_table) == NULL) {
        return;
    }
    for (i = 0; i < 16; i++) {
        ws_recent_state.ids[i] = -1;
    }
    ws_recent_state.data_base = a;
    ws_recent_state.data_table = b;
    ws_recent_state.data_base_values = a->values;
    ws_recent_state.data_table_values = b->values;
    if (ws_recent_state.data_base_values == 0 || ws_recent_state.data_table_values == 0) {
        return;
    }
    x = a->count;
    y = b->count;
    if (x < 1 || y < 1 || x != y) {
        return;
    }
    ws_recent_state.entry_count = x;
}

s32 get_word_select_type_state(s32 state, s32 item) {
    return word_select_type_state_table[lookup_item_category(item)][state];
}
s32 lookup_item_category(s32 item) {
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
            if (item == list[j]) {
                r = e->category;
                break;
            }
        }
        if (r != 5) {
            break;
        }
    }
    if (r == 2 && TWindowDD::window_mode == 0) {
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
