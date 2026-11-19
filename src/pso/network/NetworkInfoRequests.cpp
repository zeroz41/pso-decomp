#include "pso/network/NetworkInfoLoader.h"
#include "pso/network/NetworkInfoRequests.h"

#pragma push
#pragma scheduling off
#pragma peephole off
#pragma opt_dead_assignments off
// The caller's buffer is declared 32-byte aligned, as the library's buffer pointers in .sbss are; GC/1.3 gives
// the parameter an aligned home, hence the 32-aligned frame.
s32 request_network_info_load(s32 channel, void *buffer __attribute__((aligned(32)))) {
    switch (get_network_config_mode()) {
    case 0:
        return -1;
    case 2:
    case 3:
    default:
        return -5;
    case 1:
        break;
    }
    if (network_info_load_state.request_kind != 0) {
        return -4;
    }
    set_network_config_card_channel(channel);
    network_info_load_state.request_kind = 2;
    network_info_load_state.phase = 3;
    network_info_load_state.caller_buffer = buffer;
    network_info_load_state.result = 200;
    return 0;
}
#pragma pop

#pragma push
#pragma scheduling off
s32 take_network_info_request_result(s32 *card_result, s32 *card_detail) {
    s32 r;
    s32 t;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (network_info_load_state.request_kind == 2) {
        *card_result = network_info_load_state.card_result;
        *card_detail = network_info_load_state.card_detail;
        t = network_info_load_state.result;
        r = t;
        if (t != 200) {
            if (t == 0) {
                get_or_set_network_config_mode(2);
            }
            network_info_load_state.request_kind = 0;
            network_info_load_state.phase = 0;
            network_info_load_state.result = 0;
        }
    } else {
        *card_result = 0;
        *card_detail = 0;
        r = -4;
    }
    return r;
}
#pragma pop
