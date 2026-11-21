#include "pso/network/NetworkInfoLoader.h"
#include "pso/network/NetworkInfoRequests.h"

// The original has a 32-byte-aligned frame with no live stack locals. MWCC's
// parameter alignment reproduces that frame without changing the register ABI.
#ifdef __MWERKS__
#define NETWORK_INFO_FRAME_ALIGN ATTRIBUTE_ALIGN(32)
#else
#define NETWORK_INFO_FRAME_ALIGN
#endif

#pragma push
#pragma scheduling off
#pragma peephole off
s32 request_network_info_load(s32 channel NETWORK_INFO_FRAME_ALIGN, void *buffer) {
    switch (get_network_config_mode()) {
    case 0:
        return -1;
    case 1:
        break;
    case 2:
    case 3:
    default:
        return -5;
    }

    NetworkInfoLoadState *state = &network_info_load_state;
    if (state->request_kind != 0) {
        return -4;
    }
    set_network_config_card_channel(channel);
    state->request_kind = 2;
    network_info_load_state.phase = 3;
    network_info_load_state.caller_buffer = buffer;
    network_info_load_state.result = 200;
    return 0;
}
#pragma pop
#undef NETWORK_INFO_FRAME_ALIGN

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
