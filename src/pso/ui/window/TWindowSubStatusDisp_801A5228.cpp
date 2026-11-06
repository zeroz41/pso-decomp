#include "types.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

struct RecoveredGlobal_801A5228_lbl_80446970 {
    s32 value;
    u8 remaining[0xC];
};

extern RecoveredGlobal_801A5228_lbl_80446970 card_window_scale_table;

extern "C" {

s32 get_character_save_record(u32 arg0);

extern s32 local_client_id;

typedef char RecoveredGlobal_801A5228_lbl_80446970_size[sizeof(RecoveredGlobal_801A5228_lbl_80446970) == 0x10 ? 1 : -1];
f32 TWindowSubStatusDisp::get_card_window_scale(s32 _w0) {
    return *(f32 *)((s8 *)((u8 *)&card_window_scale_table.value + (TWindowSubStatusDisp::get_card_window_flags(_w0) * 4)) + 0);
}

s32 TWindowSubStatusDisp::get_card_window_flags(s32 arg0) {
    s32 var_r3;
    void *character_save_record;

    var_r3 = arg0;
    if (var_r3 >= 4) {
        var_r3 = local_client_id;
    }
    character_save_record = (void *)get_character_save_record(var_r3);
    if (character_save_record == NULL) {
        return 1;
    }
    return ((u32) *(u32 *)((s8 *)character_save_record + 0x10) >> 8U) & 3;
}

}
