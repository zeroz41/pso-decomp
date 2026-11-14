#include "types.h"
#include "pso/unk/text_803F3BF8.h"
#include "pso/network/NetworkInfoLoader.h"
#include <dolphin/os/OSAlloc.h>

// First function of the ntInf library: it publishes the library's version
// string ("ntInf Ver 1.17.00 Build:Jul  9 2002").
extern "C" {
extern const char *lbl_805D79AC;
extern const char *const lbl_805E10F8;
extern s32 lobby_net_config_mode;
extern s32 lbl_805D7984;
extern s32 lobby_net_config_load_state;
extern u8 *lobby_net_config_buffer;
extern u8 *lobby_net_config_card_base;

// The original realigns the stack to 32 bytes (clrlwi/subfic/stwux) without
// using it; no clean source found that does that (see NOTES of lane cJ).
s32 TLobby__sub_803F3BF8(s32 backup_mode, void *buffer, s32 mode) {
    lbl_805D79AC = lbl_805E10F8;
    if (get_network_config_mode() != 0) {
        return -1;
    }
    lobby_net_config_mode = mode;
    lbl_805D7984 = mode;
    if (backup_mode != 0) {
        return -2;
    }
    get_or_set_network_config_mode(1);
    get_or_set_network_config_backup_mode(backup_mode);
    lobby_net_config_load_state = 0;
    if (buffer == NULL) {
        lobby_net_config_buffer = (u8 *)OSAllocFromHeap(__OSCurrHeap, get_network_config_buffer_size(backup_mode));
        if (lobby_net_config_buffer == NULL) {
            return -4;
        }
        lobby_net_config_load_state = 1;
    } else {
        lobby_net_config_buffer = (u8 *)buffer;
    }
    if (backup_mode == 1) {
        lobby_net_config_card_base = lobby_net_config_buffer + 0x19D4;
    }
    set_network_config_card_channel(2);
    return 0;
}

}
