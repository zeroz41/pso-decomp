#ifndef PSO_ITEM_ITEMCREATEFUNCTION_H
#define PSO_ITEM_ITEMCREATEFUNCTION_H

#include "types.h"

struct TItem;

typedef TItem *(*ItemCreateFunction)(u8 *item);

extern "C" {
ItemCreateFunction get_weapon_factory_for_item(u8 *item);
ItemCreateFunction TLobby__sub_8010440C(u8 *item);
TItem *create_weapon_for_item(u8 *item);
TItem *TLobby__sub_801054E0(u8 *item);
}

#endif
