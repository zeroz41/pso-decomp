#include "pso/TPlyItem.h"
#include "pso/item/TItemList.h"
#include "pso/player/TPlyItem.h"
#include "pso/item/TItem.h"

#include "types.h"

struct VBase_801D5004 { char pad[0x18]; };

struct VObj_801D5004 : VBase_801D5004 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual s32 v34();
};

struct Item_801D5004 {
    u8 pad0[0xC];
    Item_801D5004 *next;
    u8 pad10[0x4];
    Item_801D5004 *child;
};

struct VBase_801D50E0 { char pad[0x18]; };

struct VObj_801D50E0 : VBase_801D50E0 {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual s32 v34();
};

struct Item_801D50E0 {
    u8 pad0[0xC];
    Item_801D50E0 *next;
    u8 pad10[0x4];
    Item_801D50E0 *child;
};

struct Item_801D51A0 {
    u8 pad0[0xC];
    Item_801D51A0 *next;
    u8 pad10[0x4];
    Item_801D51A0 *child;
};

extern "C" {
void *get_owner_if_alive__10TObjPlayerFv(void *);
s32 is_item_valid__9TItemListFl(void *);
extern u8 *item_reduce_target_player;
extern u8 item_reduce_owner_match_field_ec;
extern u8 reduce_owner_match_id;
extern s32 *TObjPlayer__owner_field_write_cursor;
extern s32 inventory_walk_visit_count;
}

TPlyItem::~TPlyItem() {
    TItemList__sub_801D5B10((char*)this + 0x20, -1);
}

#include "pso/misc/TLobby.h"
#include "pso/player/TObjPlayer.h"
#include "pso/TItemList.h"
#include "pso/misc/TOSwitchItem.h"

extern "C" {

void __ct__7TObjectFP7TObject(void *);

extern s32 __vt__8TPlyItem[];
extern void *TPlyItem_name_ref;

void *TPlyItem__ct(void *ply_item) {
    __ct__7TObjectFP7TObject(ply_item);
    *(s32 **)((s8 *)ply_item + 0x18) = __vt__8TPlyItem;
    ((TItemList *)((char *)ply_item + 32))->init_items();
    *(void * *)&((TPlyItem *)ply_item)->m_name = TPlyItem_name_ref;
    *(u16 *)((s8 *)ply_item + 0x1C) = 0;
    *(u16 *)((s8 *)ply_item + 0x1E) = 0;
    return ply_item;
}
void TLobby::reduce_owner_matched_items() {
    Item_801D5004 *self = (Item_801D5004 *)this;
    VObj_801D5004 *owner;
    Item_801D5004 *it;
    u8 *lobby;
    for (it = self->child; it != NULL; it = it->next) {
        if (is_item_valid__9TItemListFl(it) != 0) {
            owner = (VObj_801D5004 *)get_owner_if_alive__10TObjPlayerFv(it);
            if (owner != NULL && item_reduce_owner_match_field_ec == ((TItem *)owner)->get_item_type() &&
                reduce_owner_match_id == ((TItem *)owner)->get_item_group()) {
                if (item_reduce_owner_match_field_ec == 3) {
                    lobby = item_reduce_target_player;
                    ((TLobby *)(*(s32 *)(lobby + 0xD00)))->reduce_item_amount((s32)lobby, (s32)it, (s32)(owner->v34()));
                } else {
                    ((TLobby *)(*(s32 *)(item_reduce_target_player + 0xD00)))->reduce_item_amount((s32)item_reduce_target_player, (s32)it, 1);
                }
            }
        }
        ((TLobby *)it)->reduce_child_item_amounts();
    }
}
void TLobby::reduce_child_item_amounts() {
    Item_801D50E0 *self = (Item_801D50E0 *)this;
    VObj_801D50E0 *owner;
    Item_801D50E0 *it;
    u8 *lobby;
    for (it = self->child; it != NULL; it = it->next) {
        if (is_item_valid__9TItemListFl(it) != 0) {
            owner = (VObj_801D50E0 *)get_owner_if_alive__10TObjPlayerFv(it);
            if (owner != NULL && item_reduce_owner_match_field_ec == ((TItem *)owner)->get_item_type()) {
                if (item_reduce_owner_match_field_ec == 3) {
                    lobby = item_reduce_target_player;
                    ((TLobby *)(*(s32 *)(lobby + 0xD00)))->reduce_item_amount((s32)lobby, (s32)it, (s32)(owner->v34()));
                } else {
                    ((TLobby *)(*(s32 *)(item_reduce_target_player + 0xD00)))->reduce_item_amount((s32)item_reduce_target_player, (s32)it, 1);
                }
            }
        }
        ((TLobby *)it)->reduce_child_item_amounts();
    }
}
void TObjPlayer::collect_owner_fields_recursive() {
    Item_801D51A0 *self = (Item_801D51A0 *)this;
    Item_801D51A0 *it;
    void *owner;
    for (it = self->child; it != NULL; it = it->next) {
        if (is_item_valid__9TItemListFl(it) != 0 && (owner = get_owner_if_alive__10TObjPlayerFv(it)) != NULL) {
            *TObjPlayer__owner_field_write_cursor++ = ((TItem *)owner)->get_item_id();
            inventory_walk_visit_count++;
        }
        ((TObjPlayer *)it)->collect_owner_fields_recursive();
    }
}

}
