#include "types.h"
#include "pso/ui/window/TWindowDD_80348BF4.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

s32 handle_word_select__9TWindowDDFv();
}
extern s32 local_client_id;
extern u32 TWindowDD__word_select_lists;

void handle_6x74_word_select(u8 *arg0) {
    handle_word_select__9TWindowDDFv();
    if ((u32) TWindowDD__word_select_lists != 0U) {
        if ((s32) *(u16 *)((s8 *)arg0 + 2) != (s32) local_client_id) {
            ((TWindowDD *)(arg0 + 4))->update_selected_id();
        }
        TWindowDD::build_player_word_lists();
        TWindowDD::open((s32)(arg0 + 4), (s32)((int) (*(u16 *)((s8 *)arg0 + 2))));
    }
}
