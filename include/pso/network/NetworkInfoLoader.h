#ifndef PSO_NETWORK_NETWORK_INFO_LOADER_H
#define PSO_NETWORK_NETWORK_INFO_LOADER_H

#include "types.h"
#include <stddef.h>

struct NetworkInfoLoadState {
    void *caller_buffer;
    s32 request_kind;
    s32 phase;
    s32 field_0C;
    s32 file_handle;
    s32 result;
    s32 card_channel;
    s32 card_result;
    s32 card_detail;
};
LAYOUT_ASSERT(NetworkInfoLoadStateExtent, sizeof(NetworkInfoLoadState) == 0x24);
LAYOUT_ASSERT(NetworkInfoPhaseOffset, offsetof(NetworkInfoLoadState, phase) == 8);
LAYOUT_ASSERT(NetworkInfoHandleOffset, offsetof(NetworkInfoLoadState, file_handle) == 0x10);
LAYOUT_ASSERT(NetworkInfoDetailOffset, offsetof(NetworkInfoLoadState, card_detail) == 0x20);

extern NetworkInfoLoadState network_info_load_state;

s32 take_network_info_request_result(s32 *card_result, s32 *card_detail);
void update_network_info_load(void);
s32 request_network_info_exists(s32 channel);
s32 take_network_info_exists_result(s32 *card_result, s32 *card_detail);
void update_network_info_exists(void);
void init_network_config_defaults(void);
s32 get_network_config_mode(void);
s32 get_or_set_network_config_mode(s32 mode);
s32 get_network_config_backup_mode(void);
s32 get_or_set_network_config_backup_mode(s32 mode);
s32 get_network_config_card_channel(void);
void set_network_config_card_channel(s32 channel);
s32 get_network_config_buffer_size(s32 backup_mode);
s32 get_network_info_file_size(void);
s32 get_network_info_card_key(int channel, u8 *key);
u32 calc_crc32(saddr buf, s32 len);
extern "C" {
u32 fn_803F4D10(u32 crc, u8 *buf, s32 len);
}

s32 get_network_config_backup_mode(void);
s32 get_network_config_buffer_size(s32 mode);
s32 get_network_config_card_channel(void);
s32 get_network_config_mode(void);
s32 get_network_info_card_key(int chan, u8 *out);
s32 get_network_info_file_size(void);
s32 get_or_set_network_config_backup_mode(s32 mode);
s32 get_or_set_network_config_mode(s32 mode);
void init_network_config_defaults(void);
s32 request_network_info_exists(s32 channel);
void set_network_config_card_channel(s32 channel);
s32 take_network_info_exists_result(s32 *arg0, s32 *arg1);
void update_network_info_exists(void);
void update_network_info_load(void);

#endif
