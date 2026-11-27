#ifndef PSO_ITEM_ITEM_CREATE_H
#define PSO_ITEM_ITEM_CREATE_H

#include "types.h"

struct TItemData;
struct FlagWord;

// Bit 0 is set on entering Pioneer 2; apply_sync_item_state then respawns floor 0's missing items.
extern FlagWord pioneer2_item_respawn_flags;

void set_boss_buf_entry(int value, u16 index);
int get_sync_counter(u16 index);
s32 get_item_data(const TItemData *item);
void forward_message(char *buf, TItemData *item);
void mark_selected();
int get_drop_flag();
void handle_select_confirm();

s32 is_valid_drop_floor(s32 floor);
s32 is_valid_area_id(s32 index);
struct TObjPlayer;
struct TObjEnemy;
struct TItem;
struct TItemData;
struct ItemCombination;

// Whether the player's class has every class bit perm asks for.
int check_class_equip_permission(TObjPlayer *player, s32 perm);
s32 item_identity_matches(u8 *item, u8 *other);
s32 compare_item_data_masked(void *item, void *other, s32 mode);

void normalize_drop_area(s32 *p);

// Sends the 6x60 standard drop request for a killed enemy.
void send_6x60_standard_drop_item_request(TObjEnemy *enemy);

ItemCombination *find_eligible_combination_recipe(TObjPlayer *player, TItemData *item);

void item_class_slot7_load(void);

// The one equipped item item combines with, or NULL when none or several do.
TItem *find_unique_combination_target(TObjPlayer *player, TItemData *item);

u8 roll_weapon_special_channel15(u8 stars);
// Whether `player` meets the item's requirements; *requirement gets the
// stat it falls short on.
s32 check_equip_requirements(void *player, TItemData *item, s32 *requirement);

// Builds the item object for `data` with its type's create function.
TItem *construct_item(TItemData *data);
void forward_to_player(int id, TItemData *item);
void handle_player_event(s32 client, s32 slot);

struct FloorItem;
// Creates the item a 6x5D/6x5F drop describes and puts it on the floor.
TItem *spawn_dropped_item_from_msg(FloorItem *drop, s32 quiet);
s32 calc_price_of(TItemData *data);
u8 find_adjacent_matching_slot(u8 slot);
u8 get_next_matching_special_index(u8 slot);
void cleanup_game_objects();
void free_item_globals();
void init_game_resources();

#endif
