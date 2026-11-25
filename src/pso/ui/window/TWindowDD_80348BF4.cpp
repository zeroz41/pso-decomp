#include "types.h"
#include "pso/ui/window/TWindowDD_80348BF4.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/WordSelectMessage.h"


extern s32 local_client_id;
extern u32 TWindowDD__word_select_lists;

void handle_6x74_word_select(u8 *window_dd) {
    G_WordSelect_6x74 *cmd = (G_WordSelect_6x74 *)window_dd;
    cmd->bswap_message();
    if ((u32) TWindowDD__word_select_lists != 0U) {
        if ((s32) cmd->client_id != (s32) local_client_id) {
            cmd->message.remember_selected_id();
        }
        TWindowDD::build_player_word_lists();
        TWindowDD::open(&cmd->message, cmd->client_id);
    }
}
