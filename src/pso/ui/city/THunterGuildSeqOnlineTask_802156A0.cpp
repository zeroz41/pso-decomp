#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TLobby.h"
#include "pso/item/shop/ShopPool.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/item/TItemData.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/city/TShopItemListWindow.h"

struct AppraisalScoreEntry {
    s8 roll;
    u8 score;
};

struct AppraisalRollEntry {
    u8 adjustment;
    u8 weight;
    u8 favored_weight;
};

struct AppraisalRollTable {
    AppraisalRollEntry *entries;
    s32 count;
};

struct ItemAppraisalRules {
    AppraisalRollTable *special_rolls;
    AppraisalRollTable *grind_rolls;
    AppraisalRollTable *percentage_rolls;
    AppraisalScoreEntry *special_and_percentage_scores;
    AppraisalScoreEntry *grind_scores;
};

struct AppraisalItemView { u8 pad[3]; u8 f3; };
struct AppraisalSlotView { u8 pad[4]; u8 slot; };
struct AppraisalPercentages { u8 pad[7]; s8 a; u8 p8; s8 b; u8 pa; s8 c; };


// Grind/percentage steps picked by the JudgeItem appraisal rolls (name inferred from its users).
static const s8 item_appraisal_adjust_table[] = {-10, -5, -3, -2, -1, 0, 1, 2, 3, 5, 10, 0};

ItemAppraisalRules *item_appraisal_rules;
s32 item_appraisal_favored_weapon;
s32 item_appraisal_score;
extern "C" {

u8 TLobby::lookup_table_value(s8 x) {
    const AppraisalScoreEntry *p = item_appraisal_rules->grind_scores;
    while (p->roll != -1) {
        if (p->roll == x) {
            return p->score;
        }
        p++;
    }
    return 0;
}

u8 lookup_key_value__6TLobbyFc(s8 x) {
    const AppraisalScoreEntry *p = item_appraisal_rules->special_and_percentage_scores;
    while (p->roll != -1) {
        if (p->roll == x) {
            return p->score;
        }
        p++;
    }
    return 0;
}

void adjust_appraisal_percentages(AppraisalPercentages *appraisal) {
    ShopPool ctr;
    const AppraisalRollEntry *e;
    s32 count;
    s32 n;
    s32 r;
    ctr.clear();
    count = item_appraisal_rules->percentage_rolls->count;
    e = &item_appraisal_rules->percentage_rolls->entries[count * shop_section_id];
    while (count-- > 0) {
        if (item_appraisal_favored_weapon != 0) {
            n = e->favored_weight;
        } else {
            n = e->weight;
        }
        while (n-- != 0) {
            ctr.push(e->adjustment);
        }
        e++;
    }
    ctr.shuffle_n_times(4);
    r = ctr.pop();
    if (r != -1) {
        u8 v = item_appraisal_adjust_table[r];
        appraisal->a += v;
        appraisal->b += v;
        appraisal->c += v;
    } else {
        appraisal->a = 0;
        appraisal->b = 0;
        appraisal->c = 0;
    }
    if (appraisal->a > 100) {
        appraisal->a = 100;
    }
    if (appraisal->b > 100) {
        appraisal->b = 100;
    }
    if (appraisal->c > 100) {
        appraisal->c = 100;
    }
    item_appraisal_score += ((s8 (*)(s8))lookup_key_value__6TLobbyFc)(r);
}

void TLobby::roll_item_grind_bonus() {
    ShopPool pool;
    const AppraisalRollEntry *e;
    s32 n;
    s32 c;
    s32 r;
    if (TItemData::is_rare_item(this) == 0) {
        pool.clear();
        const AppraisalRollTable *t = item_appraisal_rules->grind_rolls;
        n = t->count;
        e = &t->entries[n * shop_section_id];
        while (n-- > 0) {
            if (item_appraisal_favored_weapon != 0) {
                c = e->favored_weight;
            } else {
                c = e->weight;
            }
            while (c-- != 0) {
                pool.push(e->adjustment);
            }
            e++;
        }
        pool.shuffle_n_times(4);
        r = pool.pop();
        if (r != -1) {
            s32 v = ((AppraisalItemView *)this)->f3 + item_appraisal_adjust_table[r];
            if (v < 0) {
                v = 0;
            }
            ((AppraisalItemView *)this)->f3 = v;
        }
        u8 m = ((TItemData *)this)->get_max_grind();
        if (((AppraisalItemView *)this)->f3 > m) {
            ((AppraisalItemView *)this)->f3 = m;
        }
        item_appraisal_score += (s8)TLobby::lookup_table_value(r);
    }
}

void adjust_appraisal_special(AppraisalSlotView *obj) {
    ShopPool pool;
    AppraisalRollEntry *e;
    s32 n;
    s32 c;
    s32 r;
    pool.clear();
    AppraisalRollTable *t = item_appraisal_rules->special_rolls;
    n = t->count;
    e = &t->entries[n * shop_section_id];
    while (n-- > 0) {
        if (item_appraisal_favored_weapon != 0) {
            c = e->favored_weight;
        } else {
            c = e->weight;
        }
        while (c-- != 0) {
            pool.push(e->adjustment);
        }
        e++;
    }
    pool.shuffle_n_times(4);
    r = pool.pop();
    if (r != -1) {
        switch (item_appraisal_adjust_table[r]) {
        case -1:
            obj->slot = TObjPlayer::find_adjacent_matching_slot(obj->slot);
            break;
        case 1:
            obj->slot = TObjPlayer::get_next_matching_special_index(obj->slot);
            break;
        }
    }
    item_appraisal_score += (s8)lookup_key_value__6TLobbyFc(r);
}

bool TLobby::is_slot_match() {
    return *(u8 *)((s8 *)this + 1) == section_id_favored_grind_table[shop_section_id];
}
s32 is_slot_match__6TLobbyFv();
}


void update_item_appraisal(saddr appraisal) {
    if ((uaddr) item_appraisal_rules != 0U) {
        item_appraisal_score = 0;
        item_appraisal_favored_weapon = is_slot_match__6TLobbyFv();
        adjust_appraisal_special((AppraisalSlotView *)appraisal);
        ((TLobby *)appraisal)->roll_item_grind_bonus();
        adjust_appraisal_percentages((AppraisalPercentages *)appraisal);
    }
}

void TLobby::free_window() {
    if ((uaddr) item_appraisal_rules != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)item_appraisal_rules));
        item_appraisal_rules = 0U;
    }
}
void load_judge_item(void) { item_appraisal_rules = static_cast<ItemAppraisalRules *>(create_named_object("JudgeItem.rel")); }
