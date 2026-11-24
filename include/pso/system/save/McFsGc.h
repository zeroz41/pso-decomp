#ifndef PSO_SYSTEM_SAVE_MCFSGC_H
#define PSO_SYSTEM_SAVE_MCFSGC_H

#include "types.h"

// Per-slot card state: the last CARDProbeEx result and the sizes it reported.
struct CardSlotInfo {
    s32 state;
    s32 mem_size;
    u32 sector_size;
};

typedef void (*CardSlotChangeCallback)(s32 channel, s32 memory_size, u32 sector_size);
LAYOUT_ASSERT(CardSlotInfoSize, (sizeof(CardSlotInfo) == 0xC));

void update_card_find(s32 card_channel);
void update_card_write(s32 file);
void update_card_read(s32 file);
void update_card_open(s32 file);
void update_card_create(s32 file);
void card_check_callback(s32 card_channel, s32 result);
void update_card_mount(s32 card_channel);
s32 update_card_requests(void);
s32 check_card_lib_ready(void);
s32 init_card_lib(void *work_area);
s32 get_or_set_channel_flag(s32 channel, s32 mode);
s32 get_load_state();
void step_set_attributes(s32 card_channel);
void update_card_delete(s32 card_channel);
void update_card_rename(s32 card_channel);
void reset_slot_entry(s32 channel);
s32 close_card_slot(s32 file_handle);
s32 take_card_read_result(s32 channel, s32 *card_detail);
s32 request_card_read(s32 file, void *buffer, s32 length, s32 offset);
s32 take_card_open_result(s32 channel, s32 *card_detail);
s32 begin_card_file_request(s32 chan, const char *name);
void unmount_card(s32 chan);
s32 take_card_mount_result(s32 channel, s32 *card_detail);
s32 take_card_find_result(s32 card_channel, s32 *card_detail);
s32 request_card_find(s32 card_channel, const char *name);

#endif
