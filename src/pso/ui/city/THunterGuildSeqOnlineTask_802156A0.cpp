#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/text_800F9B84.h"
#include "pso/item/TItemData.h"

struct RecoveredGlobal_80215ABC_lbl_804CA0B8 {
    s32 value;
    u8 remaining[0x24];
};
typedef char RecoveredGlobal_80215ABC_lbl_804CA0B8_size[sizeof(RecoveredGlobal_80215ABC_lbl_804CA0B8) == 0x28 ? 1 : -1];

struct Pair_802156E0 { s8 key; u8 val; };

struct G_802156E0 { u8 pad[0xc]; Pair_802156E0 *tbl; };

struct Pair_802156A0 { s8 key; u8 val; };

struct G_802156A0 { u8 pad[0x10]; Pair_802156A0 *tbl; };

struct Ent_8021587C { u8 id; u8 n1; u8 n2; };

struct Tbl_8021587C { Ent_8021587C *base; s32 count; };

struct G_8021587C { u8 pad[4]; Tbl_8021587C *t; };

struct Item_8021587C { u8 pad[3]; u8 f3; };

struct Ent_8021599C { u8 id; u8 n1; u8 n2; };

struct Tbl_8021599C { Ent_8021599C *base; s32 count; };

struct G_8021599C { Tbl_8021599C *t; };

struct Obj_8021599C { u8 pad[4]; u8 slot; };

struct G_802156E0;
struct Ent_80215720 { u8 id; u8 n1; u8 n2; };

struct Tbl_80215720 { Ent_80215720 *base; s32 count; };

struct G_80215720 { u8 pad[8]; Tbl_80215720 *t; };

struct Obj_80215720 { u8 pad[7]; s8 a; u8 p8; s8 b; u8 pa; s8 c; };

struct Ctr_80215720 { u8 buf[0x68]; };

// Grind/percentage steps picked by the JudgeItem appraisal rolls (name inferred from its users).
static const s8 item_appraisal_adjust_table[] = {-10, -5, -3, -2, -1, 0, 1, 2, 3, 5, 10, 0};

extern "C" {
extern RecoveredGlobal_80215ABC_lbl_804CA0B8 section_id_favored_grind_table;
extern s32 lbl_805D6238;
extern G_802156E0 *item_appraisal_rules;
u8 lookup_key_value__6TLobbyFc(s8 x);
u8 get_entry_field16__9TItemDataFv(Item_8021587C *);
void shuffle_shop_pool_n_times(void *, s32);
void push_shop_pool_entry(void *, u8);
extern s32 item_appraisal_favored_weapon;
extern s32 item_appraisal_score;
void adjust_appraisal_special(Obj_8021599C *obj);
void adjust_appraisal_percentages(Obj_80215720 *arg0);

u8 TLobby::lookup_table_value(s8 x) {
    Pair_802156A0 *p = (*(G_802156A0 * *)&item_appraisal_rules)->tbl;
    while (p->key != -1) {
        if (p->key == x) {
            return p->val;
        }
        p++;
    }
    return 0;
}

u8 lookup_key_value__6TLobbyFc(s8 x) {
    Pair_802156E0 *p = item_appraisal_rules->tbl;
    while (p->key != -1) {
        if (p->key == x) {
            return p->val;
        }
        p++;
    }
    return 0;
}

struct G_802156E0;

void adjust_appraisal_percentages(Obj_80215720 *arg0) {
    Ctr_80215720 ctr;
    Ent_80215720 *e;
    s32 count;
    s32 n;
    s32 r;
    ((TLobby *)(&ctr))->reset_counter_64();
    count = ((G_80215720 *)item_appraisal_rules)->t->count;
    e = &((G_80215720 *)item_appraisal_rules)->t->base[count * lbl_805D6238];
    while (count-- > 0) {
        if (item_appraisal_favored_weapon != 0) {
            n = e->n2;
        } else {
            n = e->n1;
        }
        while (n-- != 0) {
            push_shop_pool_entry(&ctr, e->id);
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
    Ent_8021587C *e;
    s32 n;
    s32 c;
    s32 r;
    if (TItemData::is_rare_item(((Item_8021587C *)this)) == 0) {
        ((TLobby *)buf)->reset_counter_64();
        Tbl_8021587C *t = (*(G_8021587C **)&item_appraisal_rules)->t;
        n = t->count;
        e = &t->base[n * lbl_805D6238];
        while (n-- > 0) {
            if (item_appraisal_favored_weapon != 0) {
                c = e->n2;
            } else {
                c = e->n1;
            }
            while (c-- != 0) {
                push_shop_pool_entry(buf, e->id);
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
        u8 m = get_entry_field16__9TItemDataFv(((Item_8021587C *)this));
        if (((Item_8021587C *)this)->f3 > m) {
            ((Item_8021587C *)this)->f3 = m;
        }
        item_appraisal_score += (s8)TLobby::lookup_table_value(r);
    }
}

void adjust_appraisal_special(Obj_8021599C *obj) {
    u8 buf[0x68];
    Ent_8021599C *e;
    s32 n;
    s32 c;
    s32 r;
    ((TLobby *)buf)->reset_counter_64();
    Tbl_8021599C *t = (*(G_8021599C **)&item_appraisal_rules)->t;
    n = t->count;
    e = &t->base[n * lbl_805D6238];
    while (n-- > 0) {
        if (item_appraisal_favored_weapon != 0) {
            c = e->n2;
        } else {
            c = e->n1;
        }
        while (c-- != 0) {
            push_shop_pool_entry(buf, e->id);
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
}

extern "C" {
s32 is_slot_match__6TLobbyFv();

extern s32 item_appraisal_favored_weapon;
extern s32 item_appraisal_score;

void update_all__6TLobbyFi(s32 arg0) {
    if ((u32) item_appraisal_rules != 0U) {
        item_appraisal_score = 0;
        item_appraisal_favored_weapon = is_slot_match__6TLobbyFv();
        adjust_appraisal_special((Obj_8021599C *)arg0);
        ((TLobby *)arg0)->roll_item_grind_bonus();
        adjust_appraisal_percentages((Obj_80215720 *)arg0);
    }
}

void TLobby::free_window() {
    if ((u32) item_appraisal_rules != 0U) {
        TLobby::free_nodes_with_id((u32)((void*)item_appraisal_rules));
        item_appraisal_rules = 0U;
    }
}
}
void load_judge_item(void) { (*(int *)&item_appraisal_rules) = create_named_object((s32)"JudgeItem.rel"); }
