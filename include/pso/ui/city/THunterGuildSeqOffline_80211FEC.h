#ifndef PSO_UI_CITY_THUNTERGUILDSEQOFFLINE_80211FEC_H
#define PSO_UI_CITY_THUNTERGUILDSEQOFFLINE_80211FEC_H

#include "types.h"

// Nonzero while a THunterGuildSeqOnline (client or server side) or a THunterGuildSeqOffline runs for the client.
s32 get_online_client_instance(s32 client_id);
s32 get_online_server_instance(s32 client_id);
s32 get_offline_instance(s32 client_id);
s32 is_near_designated_player(void);

#endif
