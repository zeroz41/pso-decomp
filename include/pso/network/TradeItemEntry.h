#ifndef PSO_NETWORK_TRADEITEMENTRY_H
#define PSO_NETWORK_TRADEITEMENTRY_H
#include "types.h"

// One slot of a trade offer: an inventory item id (0xFFFFFF01 for meseta) and how many.
struct TradeItemEntry {
    u32 id;
    s32 count;

    void copy_from(TradeItemEntry *src) {
        id = src->id;
        count = src->count;
    }
};

// Thirty item slots and the meseta slot (entries[30]).
struct TradeItemList {
    TradeItemEntry entries[31];

    void clear_stale_entries();
    s32 add_trade_item(u32 id, s32 count);
    s32 get_item_count(u32 id);
    void remove_trade_entry(u32 id);
    TradeItemEntry *get_meseta_entry();
    TradeItemEntry *find_free_trade_slot();
    TradeItemEntry *find_trade_entry(u32 id);
    void clear();
};

// One trade participant: lists[0] is what they offer, lists[1] their inventory snapshot.
struct TradeSide {
    TradeItemList lists[2];

    void transfer_trade_item_amount(u32 id, s32 count);
    void move_trade_item_amount(u32 id, s32 count);
    void set_inventory_meseta(s32 meseta);
    void clear();
};

s32 check_trade_offer_inventory(TradeSide *side, s32 *failed_id);
void snapshot_player_trade_inventory(TradeSide *side, s32 client);

#endif
