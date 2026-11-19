#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/network/client_id.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801FBF54.h"

// Card window scale for each of the four card window flag values.
const f32 card_window_scale_table[4] = {34.0f, 51.0f, 68.0f, 0.0f};

f32 TWindowSubStatusDisp::get_card_window_scale(s32 client_id) {
    return card_window_scale_table[get_card_window_flags(client_id)];
}

// Bits 8-9 of the client's character save record word at +0x10 (1 when the slot has no record).
s32 TWindowSubStatusDisp::get_card_window_flags(s32 client_id) {
    if (client_id >= 4) {
        client_id = local_client_id;
    }
    u32 *record = (u32 *)get_character_save_record(client_id);
    if (record == NULL) {
        return 1;
    }
    return (record[4] >> 8) & 3;
}
