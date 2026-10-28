#include "types.h"
#include "pso/item/TItemData.h"
#include "pso/protocol/protocol_types.h"
#include "pso/misc/TLobby.h"
#include "pso/item/TItem.h"

struct Base_80103748 { char pad[0x18]; };
struct VObj_80103748 : Base_80103748 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
};

struct Player_801036CC { u8 pad[0x10]; void *owner; };

struct Ent_801037A0 { u8 pad0[0xE]; u16 key; u8 padx[0xC]; s32 val; u8 pad2[4]; };

struct Msg_801037A0 { u32 hdr; s32 v; s32 who; };

struct Save_80103890 {
    u16 slots[0x10];
    s32 boss[0xC];
    s32 counts[0xF];
    Ent_801037A0 items[1];
};

struct Ent_80103DD8 { s8 n; u8 pad1[0xD]; u16 key; u8 padx[0xC]; s32 val; u8 pad2[4]; };

struct Save_801039BC {
    u16 slots[0x10];
    s32 boss[0xC];
    s32 counts[0xF];
    Ent_801037A0 items[1];
};

extern s32 floor_item_counts_by_floor;
extern s32 floor_item_free_id_stack;
extern s32 floor_item_free_id_count;
extern "C" {
int get_player_data__10TObjPlayerFi(int a0);
s32 test_elt_flag__13TUnk_80493450Fll(void *p, s32 a, s32 mask);
void queue_destruction__7TObjectFv(void *);
extern void *tl_05;
void TLobby__sub_801036CC(void);
void TLobby__sub_801041BC(void *, void *);
void bswap_sync_item_state_header(void *);
void set_boss_buf_entry__6TLobbyFii(s32, u16);
void TLobby__sub_80104258(void *, void *);
s32 test_flags_any(void *, s32);
void TLobby__sub_801041D8(void);
extern u16 *floor_item_next_sort_keys;
extern s32 lbl_805D5440;
void debug_print__6TLobbyFle(const char *, ...);
void *memcpy(void *, const void *, u32);
extern char lbl_8043E048[];
Ent_801037A0 *find_item_condition_entry__6TLobbyFii(s32 n, s32 val);
void spawn_dropped_item_from_msg(void *, s32);
s32 get_sync_counter__6TLobbyFi(u16);
s32 bswap_player_packet__6TLobbyFv();

void TLobby__sub_801036CC(void) {
    s32 i;
    Player_801036CC *p;
    for (i = 0; i != TLobby::get_lobby_flag(); i++) {
        p = (Player_801036CC *)get_player_data__10TObjPlayerFi(i);
        if (p != NULL && test_elt_flag__13TUnk_80493450Fll(p, 0, 0x20000) != 0 && p->owner == tl_05) {
            queue_destruction__7TObjectFv(p);
        }
    }
    TLobby::reset_floor_items();
}
}
extern s32 local_client_id;
extern s32 TLobby__designated_client_id;
extern Ent_801037A0 **floor_item_row_table;
void evict_lowest_key_floor_item(s32 n);
void handle_6x63_destroy_floor_item(void *arg0) {
    struct VObj_80103748 *o;

    bswap_player_packet__6TLobbyFv();
    TLobby::remove_item_condition((s32)(*(s32 *)((s8 *)arg0 + 8)), (s32)(*(s32 *)((s8 *)arg0 + 4)));
    o = (struct VObj_80103748 *)find_item_by_id(*(s32 *)((s8 *)arg0 + 4));
    if (o != NULL) {
        o->m27();
    }
}

void evict_lowest_key_floor_item(s32 n) {
    Msg_801037A0 m;
    s32 best;
    u16 bestKey;
    s32 i;
    s32 v;
    if (local_client_id == TLobby__designated_client_id) {
        bestKey = 0xFFFF;
        best = 0;
        for (i = 0; i != (*(s32 * *)&floor_item_counts_by_floor)[n]; i++) {
            if (floor_item_row_table[n][i].key < bestKey) {
                best = i;
                bestKey = floor_item_row_table[n][i].key;
            }
        }
        v = floor_item_row_table[n][best].val;
        TLobby__sub_801041BC(&m, &floor_item_row_table[n][best]);
        m.v = v;
        m.who = n;
        ((TLobby *)(&m))->update_and_send();
    }
}

s32 TLobby::is_stat_over_limit(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x12) && ((s32) *(s32 *)((s8 *)floor_item_counts_by_floor + (arg0 * 4)) < 0x32)) {
        return 0;
    }
    return 1;
}

void TLobby::apply_sync_item_state() {
    s32 i;
    u16 b;
    s32 k;
    s32 j;
    s32 count;
    Ent_801037A0 *p;
    s32 n;
    TLobby::reset_floor_items();
    bswap_sync_item_state_header(this);
    for (i = 0; i < 0x10; i++) {
        floor_item_next_sort_keys[i] = ((Save_80103890 *)this)->slots[i];
    }
    for (b = 0; b != 0xC; b++) {
        set_boss_buf_entry__6TLobbyFii(((Save_80103890 *)this)->boss[b], b);
    }
    for (i = 0; i < 0xF; i++) {
        (*(s32 **)&floor_item_counts_by_floor)[i] = ((Save_80103890 *)this)->counts[i];
    }
    k = 0;
    for (j = 0; j != 0xF; j++) {
        count = (*(s32 **)&floor_item_counts_by_floor)[j];
        p = floor_item_row_table[j];
        for (n = 0; n != count; n++, p++) {
            TLobby__sub_80104258(p, &((Save_80103890 *)this)->items[k++]);
            ((TLobby *)p)->bswap_item();
            ((TItemData *)((u8 *)p + 0x10))->decode_from_network();
        }
    }
    if (test_flags_any(&lbl_805D5440, 1) != 0) {
        TLobby::respawn_missing_floor_items(0);
    }
    TLobby__sub_801041D8();
}

#pragma push
#pragma opt_propagation off
s32 TLobby::write_sync_item_state() {
    s32 i;
    u16 b;
    Save_801039BC *dst = (Save_801039BC *)this;
    s32 k;
    Ent_801037A0 *d;
    s32 j;
    s32 count;
    Ent_801037A0 *p;
    s32 n;
    for (i = 0; i < 0x10; i++) {
        dst->slots[i] = floor_item_next_sort_keys[i];
    }
    for (b = 0; b != 0xC; b++) {
        dst->boss[b] = get_sync_counter__6TLobbyFi(b);
    }
    for (i = 0; i < 0xF; i++) {
        dst->counts[i] = (*(s32 **)&floor_item_counts_by_floor)[i];
    }
    d = dst->items;
    k = 0;
    for (j = 0; j != 0xF; j++) {
        count = (*(s32 **)&floor_item_counts_by_floor)[j];
        p = floor_item_row_table[j];
        for (n = 0; n != count; n++, p++, k++) {
            TLobby__sub_80104258(d, p);
            ((TItemData *)((u8 *)d + 0x10))->encode_for_network();
            ((TLobby *)d)->bswap_item();
            d++;
        }
    }
    i = k * 0x24 + 0x8C;
    bswap_sync_item_state_header(dst);
    return i;
}
#pragma pop

u16 pop_free_entity_id() {
    s32 temp_r0;
    if ((s32) floor_item_free_id_count != 0) {
        temp_r0 = floor_item_free_id_count - 1;
        floor_item_free_id_count = temp_r0;
        return *(u16 *)((s8 *)(floor_item_free_id_stack + (temp_r0 * 2)) + 0);
    }
    return 0xFFFFU;
}

s32 push_free_entity_id(u16 id) {
  if ((floor_item_free_id_count < 0x20) && (id != (((((((((-1) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF) & 0xFFFF)))
  {
    *((u16 *) (((s8 *) (floor_item_free_id_stack + (floor_item_free_id_count * 2))) + 0)) = id;
    floor_item_free_id_count += 1;
    return 1;
  }
  return 0;
}

s32 TLobby::is_entry_valid(s32 arg0) {
    if (((s32) *(s32 *)((s8 *)floor_item_counts_by_floor + (arg0 * 4)) < 0xC0) && (arg0 < 0x12)) {
        return 1;
    }
    return 0;
}

void TLobby::respawn_missing_floor_items(s32 n) {
    s32 i;
    if (n < 0x12) {
        if (floor_item_row_table[n] != 0) {
            for (i = 0; i != (*(s32 **)&floor_item_counts_by_floor)[n]; i++) {
                Ent_801037A0 *e = &floor_item_row_table[n][i];
                if (find_item_by_id(e->val) == 0) {
                    spawn_dropped_item_from_msg(e, 1);
                }
            }
        }
    }
}

s32 TLobby::remove_item_condition(s32 n, s32 val) {
    Ent_801037A0 *list;
    s32 count;
    s32 lo;
    s32 mid;
    s32 hi;
    if (n >= 0x12) {
        return 0;
    }
    list = floor_item_row_table[n];
    if (list != NULL) {
        count = (*(s32 **)&floor_item_counts_by_floor)[n];
        if (count == 0) {
            return 0;
        }
        hi = count - 1;
        lo = 0;
        while (lo < hi) {
            mid = (lo + hi) / 2;
            if (list[mid].val < val) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        if (val == list[lo].val) {
            memcpy(&list[lo], &list[lo + 1], (count - (lo + 1)) * 0x24);
            (*(s32 **)&floor_item_counts_by_floor)[n]--;
            ((FloorItem *)(&list[(*(s32 **)&floor_item_counts_by_floor)[n]]))->clear();
            return 1;
        }
        return 0;
    }
    debug_print__6TLobbyFle(lbl_8043E048);
    return 0;
}
Ent_801037A0 *find_item_condition_entry__6TLobbyFii(s32 n, s32 val) {
    Ent_801037A0 *list;
    s32 count;
    s32 lo;
    s32 mid;
    s32 hi;
    Ent_801037A0 *p;
    if (n >= 0x12) {
        return NULL;
    }
    list = floor_item_row_table[n];
    if (list != NULL) {
        count = (*(s32 **)&floor_item_counts_by_floor)[n];
        if (count == 0) {
            return NULL;
        }
        hi = count - 1;
        lo = 0;
        while (lo < hi) {
            mid = (lo + hi) >> 1;
            if (list[mid].val < val) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        p = &list[lo];
        if (val == p->val) {
            return p;
        }
        return NULL;
    }
    debug_print__6TLobbyFle(lbl_8043E048);
    return NULL;
}
s32 TLobby::insert_sorted_entry() {
    s32 *counts;
    s32 idx;
    Ent_80103DD8 *list;
    s32 lo;
    s32 mid;
    s32 n;
    s32 val;
    s32 hi;
    Ent_80103DD8 *p;
    if (this != NULL) {
        if (TLobby::is_stat_over_limit(((Ent_80103DD8 *)this)->n) != 0) {
            evict_lowest_key_floor_item(((Ent_80103DD8 *)this)->n);
        }
        if (((Ent_80103DD8 *)this)->n < 0x12 && TLobby::is_entry_valid(((Ent_80103DD8 *)this)->n) != 0) {
            idx = ((Ent_80103DD8 *)this)->n;
            list = (*(Ent_80103DD8 ** *)&floor_item_row_table)[idx];
            if (list != NULL) {
                counts = *(s32 **)&floor_item_counts_by_floor;
                val = ((Ent_80103DD8 *)this)->val;
                n = counts[idx];
                hi = n - 1;
                if (hi > -1 && val < list[hi].val) {
                    lo = 0;
                    while (lo < hi) {
                        mid = (lo + hi) / 2;
                        if (list[mid].val < val) {
                            lo = mid + 1;
                        } else {
                            hi = mid;
                        }
                    }
                    p = &list[lo];
                    if (val == p->val) {
                        return 0;
                    }
                    memcpy(p + 1, p, (n - lo) * sizeof(Ent_80103DD8));
                } else {
                    lo = n;
                }
                ((Ent_80103DD8 *)this)->key = floor_item_next_sort_keys[((Ent_80103DD8 *)this)->n];
                if (floor_item_next_sort_keys[((Ent_80103DD8 *)this)->n] != 0xFFFF) {
                    floor_item_next_sort_keys[((Ent_80103DD8 *)this)->n]++;
                }
                TLobby__sub_80104258(&list[lo], this);
                counts[idx]++;
                return 1;
            }
        }
    }
    return 0;
}
