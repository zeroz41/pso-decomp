#ifndef PSO_UI_FRONTEND_TADPLAYERLOADGC_803F18B8_H
#define PSO_UI_FRONTEND_TADPLAYERLOADGC_803F18B8_H

#include "types.h"

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

#endif
