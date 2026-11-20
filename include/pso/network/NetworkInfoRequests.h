#ifndef PSO_NETWORK_NETWORKINFOREQUESTS_H
#define PSO_NETWORK_NETWORKINFOREQUESTS_H

#include "types.h"

s32 request_network_info_load(s32 channel, void *buffer);
s32 take_network_info_request_result(s32 *card_result, s32 *card_detail);

#endif
