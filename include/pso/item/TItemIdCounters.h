#ifndef PSO_ITEM_TITEMIDCOUNTERS_H
#define PSO_ITEM_TITEMIDCOUNTERS_H

#include "types.h"

// Built with the item system: allocates the per-client item id counters and
// their sync copies (12 each) and resets them; freeing it frees both.
struct TItemIdCounters {
    TItemIdCounters();
    ~TItemIdCounters();
};

extern s32 *item_id_counter_table;
extern s32 *item_sync_counter_table;

u32 advance_item_id_counter(u16 client);
// The floor item records ("ItemCondition"): one per item lying on a floor.
void add_item_condition(s16 floor, f32 x, f32 z, s16 room, u8 *item);
void remove_item_condition_at(s16 floor, s32 item_id);
u32 build_item_id(u16 drop_id_base);
extern s32 build_item_id_mode;
extern s32 lbl_805D54E0;
// Advances the owning client's item id counter past an item id seen from the network.
void observe_item_id(s32 item_id);
void handle_6x5C_destroy_floor_item(void *lobby);
void handle_6x60_standard_drop_item_request(void *command);
void handle_6x62(void);
void handle_6xA2_specializable_item_drop_request(void *lobby);
void process_enemy_drop_request(s32 area, s16 source, int client, s16 room, int slot, f32 x, f32 z);

#endif
