#include "types.h"
#include "pso/network/NetworkInfoLoader.h"
#include "pso/ui/TAdPlayerLoadGC_803F3CF4.h"

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
s32 OSFreeToHeap(int, void *);
extern s32 __OSCurrHeap;
extern s32 lbl_805D79B0;
extern u32 lobby_net_config_buffer;

s32 TLobby__sub_803F3D60(void) {
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (((s32) lbl_805D79B0 == 1) && ((u32) lobby_net_config_buffer != 0U)) {
        OSFreeToHeap((int)__OSCurrHeap, (void *)lobby_net_config_buffer);
        lobby_net_config_buffer = 0U;
    }
    get_or_set_network_config_mode(0);
    get_or_set_network_config_backup_mode(0);
    set_network_config_card_channel(2);
    return 0;
}

}
