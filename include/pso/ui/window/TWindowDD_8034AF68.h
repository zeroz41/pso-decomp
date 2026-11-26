#ifndef PSO_UI_WINDOW_TWINDOWDD_8034AF68_H
#define PSO_UI_WINDOW_TWINDOWDD_8034AF68_H

#include "types.h"

struct TWindowDDValueList;

// Recent word-select ids (push_recent_id) and the two ws data tables init_ws_data_tables checked.
struct WsRecentState {
    s16 ids[16];
    TWindowDDValueList *a;
    TWindowDDValueList *b;
    s16 *a0;
    s16 *b0;
    s32 n;
};

extern WsRecentState ws_recent_state;

// Entry counts of TWindowDD::lookup_item_category's id lists (.sdata2, after the lists).
extern const s32 category0_id_count;
extern const s32 category2_id_count;
extern const s32 category3_id_count;
extern const s32 category4_id_count;

s32 get_word_select_type_state(s32 state, s32 item);

extern "C" {
void push_recent_id(s16 id);
}

#endif
