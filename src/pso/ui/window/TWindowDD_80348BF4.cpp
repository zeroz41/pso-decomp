#include "types.h"
#include "pso/ui/window/TWindowDD_80348BF4.h"
#include "pso/ui/window/TWindowDD.h"


extern s32 local_client_id;
extern u32 TWindowDD__word_select_lists;

void handle_6x74_word_select(u8 *window_dd) {
    ((TWindowDD *)window_dd)->handle_word_select();
    if ((u32) TWindowDD__word_select_lists != 0U) {
        if ((s32) *(u16 *)((s8 *)window_dd + 2) != (s32) local_client_id) {
            ((TWindowDD *)(window_dd + 4))->update_selected_id();
        }
        TWindowDD::build_player_word_lists();
        TWindowDD::open(window_dd + 4, *(u16 *)((s8 *)window_dd + 2));
    }
}
