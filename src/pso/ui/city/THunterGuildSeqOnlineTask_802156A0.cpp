#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/item/TItemData.h"

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

struct Item_8021587C { u8 pad[3]; u8 f3; };
struct Obj_8021599C { u8 pad[4]; u8 slot; };
struct Obj_80215720 { u8 pad[7]; s8 a; u8 p8; s8 b; u8 pa; s8 c; };

struct Ctr_80215720 { u8 buf[0x68]; };

// Grind/percentage steps picked by the JudgeItem appraisal rolls (name inferred from its users).
static const s8 item_appraisal_adjust_table[] = {-10, -5, -3, -2, -1, 0, 1, 2, 3, 5, 10, 0};

ItemAppraisalRules *item_appraisal_rules;
s32 item_appraisal_favored_weapon;
s32 item_appraisal_score;
extern "C" {
struct SectionIdFavoredGrindTable { s32 value; u8 remaining[0x24]; };
extern SectionIdFavoredGrindTable section_id_favored_grind_table;
extern s32 lbl_805D6238;
u8 lookup_key_value__6TLobbyFc(s8 x);
void shuffle_shop_pool_n_times(void *, s32);
void push_shop_pool_entry(void *, u8);
void adjust_appraisal_special(Obj_8021599C *obj);
void adjust_appraisal_percentages(Obj_80215720 *arg0);

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

void adjust_appraisal_percentages(Obj_80215720 *arg0) {
    Ctr_80215720 ctr;
    const AppraisalRollEntry *e;
    s32 count;
    s32 n;
    s32 r;
    ((TLobby *)(&ctr))->reset_counter_64();
    count = item_appraisal_rules->percentage_rolls->count;
    e = &item_appraisal_rules->percentage_rolls->entries[count * lbl_805D6238];
    while (count-- > 0) {
        if (item_appraisal_favored_weapon != 0) {
            n = e->favored_weight;
        } else {
            n = e->weight;
        }
        while (n-- != 0) {
            push_shop_pool_entry(&ctr, e->adjustment);
        }
        e++;
    }
    shuffle_shop_pool_n_times(&ctr, 4);
    r = ((TLobby *)(&ctr))->pop_byte();
    if (r != -1) {
        u8 v = item_appraisal_adjust_table[r];
        arg0->a += v;
        arg0->b += v;
        arg0->c += v;
    } else {
        arg0->a = 0;
        arg0->b = 0;
        arg0->c = 0;
    }
    if (arg0->a > 100) {
        arg0->a = 100;
    }
    if (arg0->b > 100) {
        arg0->b = 100;
    }
    if (arg0->c > 100) {
        arg0->c = 100;
    }
    item_appraisal_score += ((s8 (*)(s8))lookup_key_value__6TLobbyFc)(r);
}

void TLobby::roll_item_grind_bonus() {
    u8 buf[0x68];
    const AppraisalRollEntry *e;
    s32 n;
    s32 c;
    s32 r;
    if (TItemData::is_rare_item(this) == 0) {
        ((TLobby *)buf)->reset_counter_64();
        const AppraisalRollTable *t = item_appraisal_rules->grind_rolls;
        n = t->count;
        e = &t->entries[n * lbl_805D6238];
        while (n-- > 0) {
            if (item_appraisal_favored_weapon != 0) {
                c = e->favored_weight;
            } else {
                c = e->weight;
            }
            while (c-- != 0) {
                push_shop_pool_entry(buf, e->adjustment);
            }
            e++;
        }
        shuffle_shop_pool_n_times(buf, 4);
        r = ((TLobby *)buf)->pop_byte();
        if (r != -1) {
            s32 v = ((Item_8021587C *)this)->f3 + item_appraisal_adjust_table[r];
            if (v < 0) {
                v = 0;
            }
            ((Item_8021587C *)this)->f3 = v;
        }
        u8 m = ((TItemData *)this)->get_entry_field16();
        if (((Item_8021587C *)this)->f3 > m) {
            ((Item_8021587C *)this)->f3 = m;
        }
        item_appraisal_score += (s8)TLobby::lookup_table_value(r);
    }
}

void adjust_appraisal_special(Obj_8021599C *obj) {
    u8 buf[0x68];
    AppraisalRollEntry *e;
    s32 n;
    s32 c;
    s32 r;
    ((TLobby *)buf)->reset_counter_64();
    AppraisalRollTable *t = item_appraisal_rules->special_rolls;
    n = t->count;
    e = &t->entries[n * lbl_805D6238];
    while (n-- > 0) {
        if (item_appraisal_favored_weapon != 0) {
            c = e->favored_weight;
        } else {
            c = e->weight;
        }
        while (c-- != 0) {
            push_shop_pool_entry(buf, e->adjustment);
        }
        e++;
    }
    shuffle_shop_pool_n_times(buf, 4);
    r = ((TLobby *)buf)->pop_byte();
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
    u8 *arg0 = (u8 *)this;
    return *(u8 *)((s8 *)arg0 + 1) == *(s32 *)((s8 *)&section_id_favored_grind_table.value + (lbl_805D6238 * 4));
}
s32 is_slot_match__6TLobbyFv();


void update_item_appraisal(saddr arg0) {
    if ((uaddr) item_appraisal_rules != 0U) {
        item_appraisal_score = 0;
        item_appraisal_favored_weapon = is_slot_match__6TLobbyFv();
        adjust_appraisal_special((Obj_8021599C *)arg0);
        ((TLobby *)arg0)->roll_item_grind_bonus();
        adjust_appraisal_percentages((Obj_80215720 *)arg0);
    }
}

void TLobby::free_window() {
    if ((uaddr) item_appraisal_rules != 0U) {
        TLobby::free_nodes_with_id((uaddr)((void*)item_appraisal_rules));
        item_appraisal_rules = 0U;
    }
}
}
void load_judge_item(void) { item_appraisal_rules = static_cast<ItemAppraisalRules *>(create_named_object("JudgeItem.rel")); }
