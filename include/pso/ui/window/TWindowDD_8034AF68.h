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

extern "C" {
s32 TWindowDD__sub_8034B008(s32 arg0, s32 arg1);
}

#endif
