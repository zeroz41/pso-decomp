#include "pso/ui/city/JudgeItem.h"
#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/network/TLobby.h"
#include "pso/item/shop/ShopPool.h"
#include "pso/system/MallocLoadFilePrc.h"
#include "pso/item/TItemData.h"
#include "pso/ui/city/TShopGetItemWindow.h"
#include "pso/ui/city/TShopItemListWindow.h"

// Grind/percentage steps picked by the JudgeItem appraisal rolls.
static const s8 item_appraisal_adjust_table[] = {-10, -5, -3, -2, -1, 0, 1, 2, 3, 5, 10, 0};

ItemAppraisalRules *item_appraisal_rules;
s32 item_appraisal_favored_weapon;
s32 item_appraisal_score;

u8 lookup_appraisal_grind_score(s8 x) {
    const AppraisalScoreEntry *p = item_appraisal_rules->grind_scores;
    while (p->roll != -1) {
        if (p->roll == x) {
            return p->score;
        }
        p++;
    }
    return 0;
}

u8 lookup_appraisal_score(s8 x) {
    const AppraisalScoreEntry *p = item_appraisal_rules->special_and_percentage_scores;
    while (p->roll != -1) {
        if (p->roll == x) {
            return p->score;
        }
        p++;
    }
    return 0;
}

void adjust_appraisal_percentages(TItemData *appraisal) {
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
        appraisal->data1.data_s8[7] += v;
        appraisal->data1.data_s8[9] += v;
        appraisal->data1.data_s8[11] += v;
    } else {
        appraisal->data1.data_s8[7] = 0;
        appraisal->data1.data_s8[9] = 0;
        appraisal->data1.data_s8[11] = 0;
    }
    if (appraisal->data1.data_s8[7] > 100) {
        appraisal->data1.data_s8[7] = 100;
    }
    if (appraisal->data1.data_s8[9] > 100) {
        appraisal->data1.data_s8[9] = 100;
    }
    if (appraisal->data1.data_s8[11] > 100) {
        appraisal->data1.data_s8[11] = 100;
    }
    item_appraisal_score += (s8)lookup_appraisal_score(r);
}

void adjust_appraisal_grind(TItemData *item) {
    ShopPool pool;
    const AppraisalRollEntry *e;
    s32 n;
    s32 c;
    s32 r;
    if (TItemData::is_rare_item(item) == 0) {
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
            s32 v = item->data1.data_u8[3] + item_appraisal_adjust_table[r];
            if (v < 0) {
                v = 0;
            }
            item->data1.data_u8[3] = v;
        }
        u8 m = item->get_max_grind();
        if (item->data1.data_u8[3] > m) {
            item->data1.data_u8[3] = m;
        }
        item_appraisal_score += (s8)lookup_appraisal_grind_score(r);
    }
}

void adjust_appraisal_special(TItemData *obj) {
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
            obj->data1.data_u8[4] = TObjPlayer::find_adjacent_matching_slot(obj->data1.data_u8[4]);
            break;
        case 1:
            obj->data1.data_u8[4] = TObjPlayer::get_next_matching_special_index(obj->data1.data_u8[4]);
            break;
        }
    }
    item_appraisal_score += (s8)lookup_appraisal_score(r);
}

s32 is_section_favored_weapon(TItemData *item) {
    if (item->data1.data_u8[1] == section_id_favored_grind_table[shop_section_id]) {
        return 1;
    }
    return 0;
}

void update_item_appraisal(TItemData *appraisal) {
    if (item_appraisal_rules != NULL) {
        item_appraisal_score = 0;
        item_appraisal_favored_weapon = is_section_favored_weapon(appraisal);
        adjust_appraisal_special(appraisal);
        adjust_appraisal_grind(appraisal);
        adjust_appraisal_percentages(appraisal);
    }
}

void free_judge_item() {
    if (item_appraisal_rules != NULL) {
        TLobby::free_nodes_with_id((uaddr)((void*)item_appraisal_rules));
        item_appraisal_rules = 0U;
    }
}
void load_judge_item(void) { item_appraisal_rules = static_cast<ItemAppraisalRules *>(create_named_object("JudgeItem.rel")); }
