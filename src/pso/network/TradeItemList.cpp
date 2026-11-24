#include "types.h"
#include "pso/network/TradeItemEntry.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/network/client_id.h"
#include "pso/item/TItem.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TPlyItem.h"
#include "pso/player/TPlyDispData.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
s32 item_identity_matches(u8 *arg0, u8 *arg1);
s32 TObjPlayer__sub_801C1AC8();
}

s32 check_trade_offer_inventory(TradeSide *side, s32 *failed_id) {
    TradeItemEntry *p;
    s32 i;
    s32 id;
    s32 empty = 1;
    side->lists[1].clear_stale_entries();
    for (p = side->lists[0].entries, i = 0; i < 0x1F; i++, p++) {
        id = p->id;
        if ((u32)(id + 0x10000) != 0xFFFF && p->count > 0) {
            s32 r;
            empty = 0;
            r = side->lists[1].add_trade_item(id, p->count);
            if (r != 0) {
                *failed_id = id;
                return r;
            }
        }
    }
    return empty ? 4 : 0;
}

void TradeSide::transfer_trade_item_amount(u32 id, s32 count) {
    TradeItemEntry *offered;
    TradeItemEntry *owned;
    offered = lists[0].find_trade_entry(id);
    if (offered != NULL) {
        offered->count -= count;
        if (offered->count <= 0) {
            lists[0].remove_trade_entry(id);
        }
        owned = lists[1].find_trade_entry(id);
        if (owned != NULL) {
            owned->count += count;
        }
    }
}

void TradeSide::move_trade_item_amount(u32 id, s32 count) {
    TradeItemEntry *owned;
    TradeItemEntry *offered;
    owned = lists[1].find_trade_entry(id);
    if (owned != NULL) {
        owned->count -= count;
        offered = lists[0].find_trade_entry(id);
        if (offered != NULL) {
            offered->count += count;
            return;
        }
        if (id == 0xFFFFFF01) {
            offered = lists[0].get_meseta_entry();
        } else {
            offered = lists[0].find_free_trade_slot();
        }
        offered->id = id;
        offered->count = count;
    }
}

void TradeSide::set_inventory_meseta(s32 meseta) {
    lists[1].get_meseta_entry()->count = meseta;
}

void snapshot_player_trade_inventory(TradeSide *side, s32 client) {
    s32 ids[0x1E];
    s32 count;
    TradeItemEntry *meseta;
    TObjPlayer *player;
    s32 i;
    TItem *item;
    player_stats *stats;
    TradeItemEntry *e;
    side->clear();
    player = get_player_by_client_id(client);
    if (player != NULL) {
        count = player->inventory_objects->run_and_get_result(ids);
        e = side->lists[1].entries;
        i = 0;
        while (i < count) {
            item = find_item_by_id(ids[i]);
            if (item != NULL) {
                e->id = ids[i];
                e->count = item->get_amount();
                if (e->count <= 0) {
                    e->count = 1;
                }
                e++;
            }
            i += 1;
        }
        meseta = side->lists[1].get_meseta_entry();
        stats = player->get_stats();
        meseta->id = 0xFFFFFF01;
        if (stats != NULL) {
            meseta->count = stats->meseta;
            return;
        }
        meseta->count = 0;
    }
}

void TradeSide::clear() {
    lists[0].clear();
    lists[1].clear();
}

void TradeItemList::clear_stale_entries() {
    TradeItemEntry *e;
    s32 i;

    e = entries;
    i = 0;
    do {
        if ((e->id + 0x10000) != 0xFFFFU && (find_item_by_id(e->id) == NULL || e->count <= 0)) {
            e->id = 0xFFFFFFFF;
            e->count = 0;
        }
        i += 1;
        e++;
    } while (i < 0x1E);
}

s32 TradeItemList::add_trade_item(u32 id, s32 count) {
    TItemData data;
    TItemData other;
    TItem *item;
    TradeItemEntry *e;
    TItem *found;
    s32 i;
    if (id == 0xFFFFFF01) {
        TradeItemEntry *meseta = get_meseta_entry();
        meseta->count += count;
        return meseta->count > 999999;
    }
    item = find_item_by_id(id);
    if (item == NULL) {
        return 0;
    }
    if (TObjPlayer__sub_801C1AC8() != 0) {
        item->copy_to_item_data(&data);
        e = entries;
        for (i = 0; i < 30; i++, e++) {
            if (e->id != 0xFFFFFFFF && e->id != 0xFFFFFF01) {
                found = find_item_by_id(e->id);
                if (found != NULL) {
                    found->copy_to_item_data(&other);
                    if (item_identity_matches((u8 *)&other, (u8 *)&data) != 0) {
                        e->count += count;
                        if (e->count > found->get_max_stack_size()) {
                            return 2;
                        }
                    }
                }
            }
        }
    }
    e = find_free_trade_slot();
    if (e == NULL) {
        return 3;
    }
    e->id = id;
    e->count = count;
    return 0;
}

s32 TradeItemList::get_item_count(u32 id) {
    TradeItemEntry *e = find_trade_entry(id);
    if (e != NULL) {
        return e->count;
    }
    return 0;
}

void TradeItemList::remove_trade_entry(u32 id) {
    TradeItemEntry *p;
    s32 i;
    if ((id + 0x10000) == 0xFF01) {
        TradeItemEntry *meseta = get_meseta_entry();
        meseta->count = 0;
        return;
    }
    p = entries;
    for (i = 0; i < 0x1F; i++, p++) {
        if (id == p->id) {
            break;
        }
    }
    i++;
    p++;
    while (i < 0x1F) {
        if ((p->id + 0x10000) == 0xFF01) {
            break;
        }
        p[-1].copy_from(p);
        p->id = 0xFFFFFFFF;
        i++;
        p->count = 0;
        p++;
    }
}

TradeItemEntry *TradeItemList::get_meseta_entry() {
    return &entries[30];
}

TradeItemEntry *TradeItemList::find_free_trade_slot() {
    TradeItemEntry *p = entries;
    s32 i;
    for (i = 0; i < 30; i++, p++) {
        if (p->id == 0xFFFFFFFF) return p;
    }
    return NULL;
}

TradeItemEntry *TradeItemList::find_trade_entry(u32 id) {
    TradeItemEntry *p = entries;
    s32 i;
    for (i = 0; i < 31; i++, p++) {
        if (id == p->id) return p;
    }
    return NULL;
}

void TradeItemList::clear() {
    TradeItemEntry *p = entries;
    s32 i;
    for (i = 0; i < 31; i++, p++) {
        p->id = 0xFFFFFFFF;
        p->count = 0;
    }
}

void G_ModifyTradeProposal_6xA6::prepare() {
    header.client_id = local_client_id;
    bswap();
}
