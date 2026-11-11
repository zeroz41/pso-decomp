#ifndef PSO_NETWORK_NETWORKINFOREQUESTS_H
#define PSO_NETWORK_NETWORKINFOREQUESTS_H

#include "types.h"

extern "C" s32 request_network_info_load(s32 channel, void *buffer);
s32 take_network_info_request_result(s32 *arg0, s32 *arg1);

#endif
