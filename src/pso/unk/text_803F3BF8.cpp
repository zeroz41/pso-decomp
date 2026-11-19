#include "types.h"
#include "pso/unk/text_803F3BF8.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_803F3CF4.h"
#include "pso/network/NetworkInfoLoader.h"
#include <dolphin/os/OSAlloc.h>

// First function of the ntInf library: it publishes the library's version
// string ("ntInf Ver 1.17.00 Build:Jul  9 2002").
extern "C" {
extern const char *lbl_805D79AC;
char lbl_804FCE38[] = "\nntInf Ver 1.17.00 Build:Jul  9 2002 09:41:44\n";
extern const char *const lbl_805E10F8 = lbl_804FCE38;
extern s32 lobby_net_config_mode;
extern s32 lbl_805D7984;
extern s32 lobby_net_config_load_state;
extern u8 *lobby_net_config_buffer;
extern u8 *lobby_net_config_card_base;

#pragma push
#pragma scheduling off
#pragma opt_dead_assignments off
s32 TLobby__sub_803F3BF8(s32 backup_mode, void *buffer, s32 mode) {
    char pad __attribute__((aligned(32)));
    void *unused = &pad;
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
#pragma pop

}

#pragma push
#pragma peephole off
s32 update_network_info_request(void) {
    if (get_network_config_mode() == 0) {
        return -1;
    }
    switch (network_info_load_state.request_kind) {
    case 2:
        update_network_info_load();
        break;
    case 1:
        update_network_info_exists();
        break;
    case 3:
    case 4:
        break;
    }
    return 0;
}
#pragma pop


extern "C" {

s32 TLobby__sub_803F3D60(void) {
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (lobby_net_config_load_state == 1 && lobby_net_config_buffer != NULL) {
        OSFreeToHeap(__OSCurrHeap, lobby_net_config_buffer);
        lobby_net_config_buffer = NULL;
    }
    get_or_set_network_config_mode(0);
    get_or_set_network_config_backup_mode(0);
    set_network_config_card_channel(2);
    return 0;
}

}
