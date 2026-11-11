#include "pso/network/NetworkInfoLoader.h"
#include "pso/network/NetworkInfoRequests.h"

// The original realigns the stack to 32 bytes (clrlwi/subfic/stwux) without
// using it; no clean source found that does that (see NOTES of lane cJ).
s32 request_network_info_load(s32 channel, void *buffer) {
    switch (get_network_config_mode()) {
    case 0:
        return -1;
    case 1:
        break;
    default:
        return -5;
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

#pragma push
#pragma scheduling off
s32 take_network_info_request_result(s32 *arg0, s32 *arg1) {
    s32 r;
    s32 t;
    if (get_network_config_mode() == 0) {
        return -1;
    }
    if (network_info_load_state.request_kind == 2) {
        *arg0 = network_info_load_state.card_result;
        *arg1 = network_info_load_state.card_detail;
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
        *arg0 = 0;
        *arg1 = 0;
        r = -4;
    }
    return r;
}
#pragma pop
