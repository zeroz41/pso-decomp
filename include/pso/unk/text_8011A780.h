#ifndef PSO_UNK_TEXT_8011A780_H
#define PSO_UNK_TEXT_8011A780_H

#include "types.h"

extern "C" {
u32 advance_item_id_counter(u16 client);
}
// The floor item records ("ItemCondition"): one per item lying on a floor.
void add_item_condition(s16 floor, f32 x, f32 z, s16 room, u8 *item);
void remove_item_condition_at(s16 floor, s32 item_id);
u32 build_item_id(u16 arg0);
void handle_6x5C_destroy_floor_item(void *arg0);
void handle_6x60_standard_drop_item_request(void *arg0);
void handle_6x62(void);
void handle_6xA2_specializable_item_drop_request(void *arg0);
void process_enemy_drop_request(s8 area, s16 source, int client, s16 room, int slot, f32 x, f32 z);

#endif
