#ifndef PSO_ITEM_ITEM_CREATE_H
#define PSO_ITEM_ITEM_CREATE_H

#include "types.h"

void set_boss_buf_entry(int value, u16 index);
s32 get_item_data(u32 item);
void forward_message(saddr buf, uaddr item);
void mark_selected();
int get_drop_flag();
void handle_select_confirm();

s32 is_valid_drop_floor(s32 floor);
s32 is_valid_area_id(s32 index);
struct TObjPlayer;

// Whether the player's class has every class bit perm asks for.
int check_class_equip_permission(TObjPlayer *player, s32 perm);
s32 item_identity_matches(u8 *arg0, u8 *arg1);
s32 compare_item_data_masked(void *item, void *other, s32 mode);

void normalize_drop_area(s32 *p);

saddr find_eligible_combination_recipe(saddr player, u8 *item);

void TItemDisconnectCtrl__sub_80105BE8(void);

struct TItem;
struct TItemData;

// The one equipped item item combines with, or NULL when none or several do.
TItem *find_unique_combination_target(TObjPlayer *player, TItemData *item);

u8 roll_weapon_special_channel15(u8 stars);
extern "C" {
// Whether `player` meets the item's requirements; *requirement gets the
// stat it falls short on.
s32 check_equip_requirements(void *player, TItemData *item, s32 *requirement);
}

// Builds the item object for `data` with its type's create function.
TItem *construct_item(TItemData *data);

#endif
