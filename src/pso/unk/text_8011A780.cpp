#include "types.h"
#include "pso/protocol/subcmd_6x.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_801036CC.h"
#include "pso/misc/TKeyBoardControl_8000F764.h"
#include "pso/misc/TLobby_80105A2C.h"
#include "pso/unk/text_8011A780.h"

#include <stddef.h>
#include "pso/misc/TLobby.h"
#include "pso/item/TItemData.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"
#include "pso/misc/TLobby_80207644.h"

// G_PickUpItem_6x59::G_PickUpItem_6x59() on a command built here.
extern "C" void *__ct__17G_PickUpItem_6x59Fv(void *cmd);
// FloorItem::FloorItem() on a record built here.
extern "C" void *__ct__9FloorItemFv(void *item);
struct Stack_8011AED8 {
    s8 sp8;
    u8 pad_9[0x3];
    f32 spC;
    f32 sp10;
    s16 sp14;
    u8 pad_16[0x2];
    s32 sp18;
    u8 trailing_storage[0x10];
};

struct Msg_8011A9D8 { u8 pad[2]; u16 u2; u32 u4; s16 s8; };

struct Cmd_8011A9D8 { u8 pad[2]; u16 a; u16 b; s16 c; u32 d; };

struct Item_8011AA68 { u8 data[12]; u32 id; u32 meseta; };

struct Source_8011AA68 { u16 group; u16 claim; };

struct Delivery_8011AA68 {
    u32 header; u8 client; u8 kind; s16 source; f32 x; f32 z; s16 room; u16 reserved; u8 item[24];
};

struct Item_8011AB64 { u8 data[12]; u32 id; u32 meseta; };

struct Source_8011AB64 { u32 a; u16 claim; u16 b; u32 c; };

struct Delivery_8011AB64 {
    u32 header; u8 client; u8 kind; s16 source; f32 x; f32 z; s16 room; u16 reserved; u8 item[24];
};

struct Row12_8011ADF4 { u32 a; u16 claim; u16 b; u32 c; };

struct Row4_8011ADF4 { u16 group; u16 claim; };

struct Pkt_8011ADF4 {
    u8 cmd; u8 size; u16 flag;
    u8 client; u8 kind; s16 source; f32 x; f32 z; s16 room; u16 reserved;
    u8 item[20];
};

struct Req_8011AD1C {
    u8 cmd; u8 size; u16 pad2; s8 client; u8 area; s16 source;
    f32 x; f32 z; s16 room; s16 x12; s8 slot;
};

extern s32 item_sync_counter_table;
extern s32 item_id_counter_table;
extern "C" {
s32 bswap_6xa2_fields__6TLobbyFv();
s32 handle_box_drop_directive(void *);
void set_boss_buf_entry__6TLobbyFii(s32 v, u16 idx);
void handle_6x5A_pick_up_item_request(Msg_8011A9D8 *msg);
int is_quest_active(void);
void init__9TItemDataFv(void *);
extern Source_8011AA68 *quest_object_entries;
void apply_by_index__9TObjEnemyFs(s16, void *);
void drop_item_from_slot__10TObjPlayerFlll(s8 arg0, s32 arg1, s32 arg2);
extern Source_8011AB64 *TLobby__data_805D6144;
s32 spawn_dropped_item_from_msg(void *, int);
void handle_6x5F_drop_item(Pkt_8011ADF4 *pkt);
s32 bswap_packet__6TLobbyFv();
}

u32 build_item_id(u16 arg0) {
    u32 id;
    if (get_main_phase() == 0xF) {
        if (is_quest_active() != 0) {
            id = arg0 | 0x06030000;
        } else {
            id = arg0 | 0x06010000;
        }
    } else if (build_item_id_mode == 1) {
        id = arg0 | 0x06020000;
    } else {
        id = arg0 | 0x06010000;
    }
    return id;
}

void observe_item_id(s32 item_id) {
    int id = item_id;
    if (get_current_area() != 0xf) {
        s32 lo = 0x10000;
        if (lo < id && id < 0x2010000) {
            s32 idx = id >> 21;
            if (((s32 *)item_sync_counter_table)[(u16)idx] <= id) {
                set_boss_buf_entry__6TLobbyFii(id + 1, idx);
            }
        }
    }
}

void handle_6x5C_destroy_floor_item(void *arg0) {
    bswap_packet__6TLobbyFv();
    remove_item_condition(*(s32 *)((s8 *)arg0 + 8), *(s32 *)((s8 *)arg0 + 4));
}

void handle_6x5A_pick_up_item_request(Msg_8011A9D8 *msg) {
    ((G_PickUpItemRequest_6x5A *)msg)->bswap();
    if (find_item_condition(msg->s8, msg->u4) != 0) {
        Cmd_8011A9D8 cmd;
        __ct__17G_PickUpItem_6x59Fv(&cmd);
        cmd.a = msg->u2;
        cmd.b = msg->u2;
        cmd.c = msg->s8;
        cmd.d = msg->u4;
        ((G_PickUpItem_6x59 *)&cmd)->send();
    }
}

void remove_item_condition_at(s16 floor, s32 item_id) {
    remove_item_condition(floor, item_id);
}

void TLobby::drop_item_from_source(s16 source, int client, s16 room, int slot, f32 x, f32 z) {
    Delivery_8011AA68 delivery;
    Item_8011AA68 item;
    u32 id;
    if (source != -1) {
        Source_8011AA68 row = quest_object_entries[source];
        if (row.claim != 0xFFFF) {
            id = build_item_id(row.claim);
            row.claim = 0xFFFF;
            TLobby::apply_table_entry(source, &row);
            init__9TItemDataFv(&item);
            TObjPlayer::drop_item(slot, (s32)&item);
            item.id = id;
            if (((TItemData *)(&item))->isValidGroundDrop() != 0) {
                ((TItemData *)&item)->encode_for_network();
                ((TLobby *)(&delivery))->init_header_packet();
                delivery.client = client;
                delivery.kind = 2;
                delivery.source = source;
                delivery.x = x;
                delivery.z = z;
                delivery.room = room;
                ((TItemData *)(delivery.item))->copy_from((TItemData *)(&item));
                ((TLobby *)(&delivery))->send_item_packet();
            }
        }
    }
}

void process_enemy_drop_request(s8 area, s16 source, int client, s16 room, int slot, f32 x, f32 z) {
    u32 id;
    if (source != -1) {
        Delivery_8011AB64 delivery;
        Item_8011AB64 item;
        Source_8011AB64 row = TLobby__data_805D6144[source];
        if (row.claim != 0xFFFF) {
            id = build_item_id(row.claim);
            row.claim = 0xFFFF;
            apply_by_index__9TObjEnemyFs(source, &row);
            init__9TItemDataFv(&item);
            drop_item_from_slot__10TObjPlayerFlll(area, slot, (s32)&item);
            item.id = id;
            if (((TItemData *)(&item))->isValidGroundDrop() != 0) {
                ((TItemData *)&item)->encode_for_network();
                ((TLobby *)(&delivery))->init_header_packet();
                delivery.client = client;
                delivery.kind = 1;
                delivery.source = source;
                delivery.x = x;
                delivery.z = z;
                ((TItemData *)(delivery.item))->copy_from((TItemData *)(&item));
                delivery.room = room;
                ((TLobby *)(&delivery))->send_item_packet();
            }
        }
    }
}

#pragma push
#pragma fp_contract on
void handle_6xA2_specializable_item_drop_request(void *arg0) {
    s8 temp_b;
    bswap_6xa2_fields__6TLobbyFv();
    temp_b = *(u8 *)((s8 *)arg0 + 5);
    if (temp_b == 0x30) {
        if (*(s16 *)((s8 *)arg0 + 0x12) != 0) {
            TLobby::drop_item_from_source((s16)(*(s16 *)((s8 *)arg0 + 6)), (int)(*(s8 *)((s8 *)arg0 + 4)), (s16)(*(s16 *)((s8 *)arg0 + 0x10)), (int)(*(s8 *)((s8 *)arg0 + 0x14)), *(f32 *)((s8 *)arg0 + 8), *(f32 *)((s8 *)arg0 + 0xC));
            return;
        }
        handle_box_drop_directive(arg0);
        return;
    }
    process_enemy_drop_request(temp_b, (s16)(*(s16 *)((s8 *)arg0 + 6)), (int)(*(s8 *)((s8 *)arg0 + 4)), (s16)(*(s16 *)((s8 *)arg0 + 0x10)), (int)(*(s8 *)((s8 *)arg0 + 0x14)), *(f32 *)((s8 *)arg0 + 8), *(f32 *)((s8 *)arg0 + 0xC));
}
#pragma pop

void handle_6x60_standard_drop_item_request(void *arg0) {
    Req_8011AD1C *req = (Req_8011AD1C *)arg0;
    s32 client;
    s32 slot;
    s8 area;
    bswap_6x60_drop_request_fields(arg0);
    if ((u32)(req->size * 4) == 0x14) {
        client = req->client;
        slot = get_floor_area(client);
    } else {
        client = req->client;
        slot = req->slot;
    }
    area = (s8)req->area;
    if (area == 0x30) {
        if (req->x12 != 0) {
            TLobby::drop_item_from_source(req->source, client, req->room, slot, req->x, req->z);
            return;
        }
        TLobby::drop_item_from_source(req->source, client, req->room, slot, req->x, req->z);
        return;
    }
    process_enemy_drop_request(area, req->source, client, req->room, slot, req->x, req->z);
}

void handle_6x5F_drop_item(Pkt_8011ADF4 *pkt) {
    ((TLobby *)pkt)->bswap_item_packet();
    if ((u32)pkt->size * 4 == 0x28) {
        ((TItemData *)pkt->item)->convert_from_version(0);
    } else {
        ((TItemData *)pkt->item)->convert_from_version(2);
    }
    ((TItemData *)pkt->item)->decode_from_network();
    s32 kind = pkt->kind;
    if (kind == 1) {
        Row12_8011ADF4 row = (*(Row12_8011ADF4 * *)&TLobby__data_805D6144)[pkt->source];
        row.claim = 0xFFFF;
        apply_by_index__9TObjEnemyFs(pkt->source, &row);
    } else {
        Row4_8011ADF4 row = (*(Row4_8011ADF4 * *)&quest_object_entries)[pkt->source];
        row.claim = 0xFFFF;
        TLobby::apply_table_entry(pkt->source, (Source_8011AA68 *)(&row));
    }
    spawn_dropped_item_from_msg(&pkt->client, 0);
}

void add_item_condition(s16 floor, f32 x, f32 z, s16 room, u8 *item) {
    typedef char sp8_offset[(offsetof(Stack_8011AED8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8011AED8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8011AED8, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_8011AED8, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_8011AED8, sp18) == 0x10) ? 1 : -1];
    Stack_8011AED8 stack;
    __ct__9FloorItemFv(&stack.sp8);
    stack.sp8 = floor;
    stack.spC = x;
    stack.sp10 = z;
    stack.sp14 = room;
    ((TItemData *)(&stack.sp18))->copy_from((TItemData *)(item));
    observe_item_id(*(s32 *)((s8 *)item + 0xC));
    insert_item_condition((FloorItem *)&stack.sp8);
}

void handle_6x62(void) {  }

u32 advance_item_id_counter(u16 client) {
    if (get_current_area() == 0xF)
        return ((u32*)item_id_counter_table)[client]++;
    return ((u32*)item_sync_counter_table)[client]++;
}
void TLobby::reset_item_id_counters() {
    s32 i;
    if ((s32 *)item_sync_counter_table == 0 || (s32 *)item_id_counter_table == 0) {
        return;
    }
    for (i = 0; i < 12; i++) {
        ((s32 *)item_sync_counter_table)[i] = (i << 21) + 0x10000;
        ((s32 *)item_id_counter_table)[i] = (i << 21) + 0x10010000;
    }
}
