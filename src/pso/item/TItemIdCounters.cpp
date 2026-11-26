#include "pso/enemy/EnemyStateRecord.h"
#include "types.h"
#include "pso/network/protocol/ItemDropPacket.h"
#include "pso/item/TItem.h"
#include "pso/unk/text_801036CC.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/unk/TLobby_80105A2C.h"
#include <stddef.h>
#include "pso/network/TLobby.h"
#include "pso/item/TItemData.h"
#include "pso/object/base/ObjectSetData.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/system/memory.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/item/TItemIdCounters.h"
#include "pso/unk/TLobby_801F3A24.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/protocol/SubcommandHandlers.h"
#include "pso/item/item_create.h"
#include "pso/unk/text_801057A8.h"




s32 lbl_805D54E0;
s32 build_item_id_mode;
// The per-client item id tables (12 s32 each, allocated by TItemIdCounters).
s32 *item_sync_counter_table;
s32 *item_id_counter_table;
void handle_box_drop_directive(G_SpecializableItemDropRequest_6xA2 *request);
void handle_6x5F_drop_item(G_DropItem_DC_6x5F *pkt);

u32 build_item_id(u16 drop_id_base) {
    u32 id;
    if (get_main_phase() == 0xF) {
        if (is_quest_active() != 0) {
            id = drop_id_base | 0x06030000;
        } else {
            id = drop_id_base | 0x06010000;
        }
    } else if (build_item_id_mode == 1) {
        id = drop_id_base | 0x06020000;
    } else {
        id = drop_id_base | 0x06010000;
    }
    return id;
}

void observe_item_id(s32 item_id) {
    int id = item_id;
    if (get_current_floor_area() != AREA_LOBBY) {
        s32 lo = 0x10000;
        if (lo < id && id < 0x2010000) {
            u16 idx = id >> 21;
            if (item_sync_counter_table[idx] <= id) {
                set_boss_buf_entry(id + 1, idx);
            }
        }
    }
}

void handle_box_drop_directive(G_SpecializableItemDropRequest_6xA2 *request) {
    const G_StandardDropItemRequest_PC_V3_BB_6x60 &extended =
        request->__base_G_StandardDropItemRequest_PC_V3_BB_6x60;
    const G_StandardDropItemRequest_DC_6x60 &drop = extended.__base_G_StandardDropItemRequest_DC_6x60;
    ObjectSetData set;
    TItemData item;
    u32 id;
    s32 source = drop.entity_index;
    if (source != -1) {
        QuestObjectEntry row = quest_object_entries[static_cast<s16>(source)];
        if (row.drop_id_base != 0xFFFF) {
            id = build_item_id(row.drop_id_base);
            row.drop_id_base = 0xFFFF;
            TLobby::apply_table_entry(source, &row);
            set.scale.z = request->scale_z;
            set.set_params[0] = request->set_params[0];
            set.set_params[1] = request->set_params[1];
            set.set_params[2] = request->set_params[2];
            item.unpack_from_item(&set);
            if (0.0f == set.scale.z) {
                const u8 data0 = item.data1.data_u8[0];
                const u8 data1 = item.data1.data_u8[1];
                item.init();
                item.data1.data_u8[0] = data0;
                item.data1.data_u8[1] = data1;
                TObjPlayer::drop_meseta_from_slot(extended.effective_area, (saddr)&item);
            }
            item.id = id;
            if (item.isValidGroundDrop() != 0) {
                item.encode_for_network();
                G_DropItem_PC_V3_BB_6x5F delivery;
                FloorItem &floor_item = delivery.__base_G_DropItem_DC_6x5F.item;
                floor_item.floor = drop.floor;
                floor_item.source_type = 2;
                floor_item.entity_index = source;
                floor_item.pos.x = drop.pos.x;
                floor_item.pos.z = drop.pos.z;
                floor_item.room_id = drop.room;
                floor_item.item.copy_from(&item);
                delivery.send();
            }
        }
    }
}

void handle_6x5C_destroy_floor_item(void *lobby) {
    ((TLobby *)lobby)->bswap_packet();
    remove_item_condition(*(s32 *)((s8 *)lobby + 8), *(s32 *)((s8 *)lobby + 4));
}

void handle_6x5A_pick_up_item_request(G_PickUpItemRequest_6x5A *command) {
    command->bswap();
    if (find_item_condition(command->floor, command->item_id) != 0) {
        G_PickUpItem_6x59 cmd;
        cmd.header.client_id = command->header.client_id;
        cmd.client_id2 = command->header.client_id;
        cmd.floor = command->floor;
        cmd.item_id = command->item_id;
        cmd.send();
    }
}

void remove_item_condition_at(s16 floor, s32 item_id) {
    remove_item_condition(floor, item_id);
}

void TLobby::drop_item_from_source(s16 source, int client, s16 room, int slot, f32 x, f32 z) {
    TItemData item;
    u32 id;
    if (source != -1) {
        QuestObjectEntry row = quest_object_entries[source];
        if (row.drop_id_base != 0xFFFF) {
            id = build_item_id(row.drop_id_base);
            row.drop_id_base = 0xFFFF;
            TLobby::apply_table_entry(source, &row);
            item.init();
            TObjPlayer::drop_item(slot, (saddr)&item);
            item.id = id;
            if (item.isValidGroundDrop() != 0) {
                item.encode_for_network();
                G_DropItem_PC_V3_BB_6x5F delivery;
                FloorItem &floor_item = delivery.__base_G_DropItem_DC_6x5F.item;
                floor_item.floor = client;
                floor_item.source_type = 2;
                floor_item.entity_index = source;
                floor_item.pos.x = x;
                floor_item.pos.z = z;
                floor_item.room_id = room;
                floor_item.item.copy_from(&item);
                delivery.send();
            }
        }
    }
}

void process_enemy_drop_request(s32 area, s16 source, int client, s16 room, int slot, f32 x, f32 z) {
    u32 id;
    if (source != -1) {
        TItemData item;
        EnemyStateRecord row = enemy_state_records[source];
        if (row.drop_id != 0xFFFF) {
            id = build_item_id(row.drop_id);
            row.drop_id = 0xFFFF;
            TObjEnemy::apply_by_index(source, &row);
            item.init();
            TObjPlayer::drop_item_from_slot(area, slot, reinterpret_cast<saddr>(&item));
            item.id = id;
            if (item.isValidGroundDrop() != 0) {
                item.encode_for_network();
                G_DropItem_PC_V3_BB_6x5F delivery;
                FloorItem &floor_item = delivery.__base_G_DropItem_DC_6x5F.item;
                floor_item.floor = client;
                floor_item.source_type = 1;
                floor_item.entity_index = source;
                floor_item.pos.x = x;
                floor_item.pos.z = z;
                floor_item.item.copy_from(&item);
                floor_item.room_id = room;
                delivery.send();
            }
        }
    }
}

#pragma push
#pragma fp_contract on
void handle_6xA2_specializable_item_drop_request(void *command) {
    G_SpecializableItemDropRequest_6xA2 *request = static_cast<G_SpecializableItemDropRequest_6xA2 *>(command);
    const G_StandardDropItemRequest_PC_V3_BB_6x60 &extended =
        request->__base_G_StandardDropItemRequest_PC_V3_BB_6x60;
    const G_StandardDropItemRequest_DC_6x60 &drop = extended.__base_G_StandardDropItemRequest_DC_6x60;
    s8 area;
    request->bswap();
    area = static_cast<s8>(drop.rt_index);
    if (area == 0x30) {
        if (drop.ignore_def != 0) {
            TLobby::drop_item_from_source(drop.entity_index, drop.floor, drop.room, extended.effective_area,
                                         drop.pos.x, drop.pos.z);
            return;
        }
        handle_box_drop_directive(request);
        return;
    }
    process_enemy_drop_request(area, drop.entity_index, drop.floor, drop.room, extended.effective_area,
                               drop.pos.x, drop.pos.z);
}
#pragma pop

void handle_6x60_standard_drop_item_request(void *command) {
    G_StandardDropItemRequest_PC_V3_BB_6x60 *req = static_cast<G_StandardDropItemRequest_PC_V3_BB_6x60 *>(command);
    const G_StandardDropItemRequest_DC_6x60 &drop = req->__base_G_StandardDropItemRequest_DC_6x60;
    s32 client;
    s32 slot;
    s8 area;
    req->__base_G_StandardDropItemRequest_DC_6x60.bswap();
    if ((u32)(drop.header.size * 4) == 0x14) {
        client = drop.floor;
        slot = get_floor_area(client);
    } else {
        client = drop.floor;
        slot = req->effective_area;
    }
    area = (s8)drop.rt_index;
    if (area == 0x30) {
        if (drop.ignore_def != 0) {
            TLobby::drop_item_from_source(drop.entity_index, client, drop.room, slot, drop.pos.x, drop.pos.z);
            return;
        }
        TLobby::drop_item_from_source(drop.entity_index, client, drop.room, slot, drop.pos.x, drop.pos.z);
        return;
    }
    process_enemy_drop_request(area, drop.entity_index, client, drop.room, slot, drop.pos.x, drop.pos.z);
}

void handle_6x5F_drop_item(G_DropItem_DC_6x5F *pkt) {
    bswap_item_packet__6TLobbyFv(pkt);
    if ((u32)pkt->header.size * 4 == 0x28) {
        pkt->item.item.convert_from_version(0);
    } else {
        pkt->item.item.convert_from_version(2);
    }
    pkt->item.item.decode_from_network();
    s32 kind = pkt->item.source_type;
    if (kind == 1) {
        EnemyStateRecord row = enemy_state_records[pkt->item.entity_index];
        row.drop_id = 0xFFFF;
        TObjEnemy::apply_by_index(pkt->item.entity_index, &row);
    } else {
        QuestObjectEntry row = quest_object_entries[pkt->item.entity_index];
        row.drop_id_base = 0xFFFF;
        TLobby::apply_table_entry(pkt->item.entity_index, &row);
    }
    spawn_dropped_item_from_msg(&pkt->item, 0);
}

void add_item_condition(s16 floor, f32 x, f32 z, s16 room, u8 *item) {
    FloorItem entry;
    entry.floor = floor;
    entry.pos.x = x;
    entry.pos.z = z;
    entry.room_id = room;
    ((TItemData *)(&entry.item))->copy_from((TItemData *)(item));
    observe_item_id(*(s32 *)((s8 *)item + 0xC));
    insert_item_condition(&entry);
}

void handle_6x62(void) {  }

u32 advance_item_id_counter(u16 client) {
    if (get_current_floor_area() == AREA_LOBBY)
        return reinterpret_cast<u32 *>(item_id_counter_table)[client]++;
    return reinterpret_cast<u32 *>(item_sync_counter_table)[client]++;
}
void TLobby::reset_item_id_counters() {
    s32 i;
    if (item_sync_counter_table == NULL || item_id_counter_table == NULL) {
        return;
    }
    for (i = 0; i < 12; i++) {
        item_sync_counter_table[i] = (i << 21) + 0x10000;
        item_id_counter_table[i] = (i << 21) + 0x10010000;
    }
}


TItemIdCounters::~TItemIdCounters() {
    mem_free(item_sync_counter_table);
    item_sync_counter_table = NULL;
    mem_free(item_id_counter_table);
    item_id_counter_table = NULL;
}

TItemIdCounters::TItemIdCounters() {
    item_id_counter_table = static_cast<s32 *>(mem_alloc(12 * sizeof(s32)));
    item_sync_counter_table = static_cast<s32 *>(mem_alloc(12 * sizeof(s32)));
    TLobby::reset_item_id_counters();
    lbl_805D54E0 = 0;
    build_item_id_mode = 0;
}
void G_DropItem_PC_V3_BB_6x5F::send() {
    bswap_item_packet__6TLobbyFv(this);
    send_subcommand(reinterpret_cast<u8 *>(this));
}
void bswap_item_packet__6TLobbyFv(void *packet) {
    static_cast<G_ClientIDHeader *>(packet)->bswap();
    bswap_item__6TLobbyFv(static_cast<u8 *>(packet) + 4);
}
G_DropItem_PC_V3_BB_6x5F::G_DropItem_PC_V3_BB_6x5F() {
    __base_G_DropItem_DC_6x5F.header.subcommand = 0x5F;
    version[0] = 2;
    version[1] = 0;
    version[2] = 0;
    version[3] = 0;
    __base_G_DropItem_DC_6x5F.header.size = 0xB;
}
G_DropItem_DC_6x5F::G_DropItem_DC_6x5F() {
    header.subcommand = 0x5F;
    header.size = 0xA;
}
void TLobby::bswap_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0x4)); }
s32 TLobby::apply_table_entry(s16 source, void * _w1) {
    if (source > 0xB9F) {
        return 0;
    }
    ((TLobby *)&quest_object_entries[source])->copy_short_fields(_w1);
    return 1;
}
void TLobby::copy_short_fields(void *src) {
    *(s16 *)&this->m_name = (s16) *(s16 *)((s8 *)src + 0);
    *(u16 *)((s8 *)this + 2) = (u16) *(u16 *)((s8 *)src + 2);
}
