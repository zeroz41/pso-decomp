#ifndef PSO_ITEM_TITEMIDCOUNTERS_H
#define PSO_ITEM_TITEMIDCOUNTERS_H

#include "types.h"

struct TItemData;
struct G_DestroyFloorItem_6x5C;
struct G_DropItem_DC_6x5F;
struct G_StandardDropItemRequest_PC_V3_BB_6x60;
struct G_SpecializableItemDropRequest_6xA2;

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
void add_item_condition(s16 floor, f32 x, f32 z, s16 room, TItemData *item);
void remove_item_condition_at(s16 floor, s32 item_id);
u32 build_item_id(u16 drop_id_base);
extern s32 build_item_id_mode;
extern s32 lbl_805D54E0;
// Advances the owning client's item id counter past an item id seen from the network.
void observe_item_id(s32 item_id);
void handle_6x5C_destroy_floor_item(G_DestroyFloorItem_6x5C *destroy);
void handle_6x5F_drop_item(G_DropItem_DC_6x5F *pkt);
void handle_6x60_standard_drop_item_request(G_StandardDropItemRequest_PC_V3_BB_6x60 *req);
void handle_6x62(void);
void handle_6xA2_specializable_item_drop_request(G_SpecializableItemDropRequest_6xA2 *request);
void process_enemy_drop_request(s32 area, s16 source, int client, s16 room, int slot, f32 x, f32 z);
void drop_item_from_source(s16 source, int client, s16 room, int slot, f32 x, f32 z);

#endif
