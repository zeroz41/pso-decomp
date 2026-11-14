#include "types.h"
#include "pso/system/memory.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_8007C550.h"
#include "pso/unk/text_80209584.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/byteswap.h"
#include "pso/unk/text_802097B0.h"
#include "pso/item/drop/TItemDrop_80105D0C.h"
#include "pso/unk/TLobby_8020A350.h"
#include "pso/unk/TLobby_8020A568.h"
#include "pso/system/EventShuffleTable.h"
#include "pso/unk/TLobby_80209BD8.h"
#include "string.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/unk/TLobby_8020A188.h"
#include "pso/quest/TQuestVmDownLoadServer.h"

// ---- pso/unk/TLobby_80209524

extern "C" {

void mem_free(void *p);

void *TLobby::free_boss4rock(s16 arg1) {
    if (this != NULL) {
        mem_free((void *)(*(s32 *)&this->m_flags));
        ::operator delete(*(void * *)&this->m_name);
        *(s32 *)&this->m_prev = 0;
        *(s32 *)&this->m_next = 0;
        if (arg1 > 0) {
            ::operator delete(this);
        }
    }
    return this;
}

}

// ---- pso/unk/text_80209584

struct Hdr_802095EC { s32 type; s32 size; s32 id; s32 x; };

struct Hdr_8020967C { s32 type; s32 size; s32 id; s32 x; };

extern "C" {
void *mem_alloc(u32 size);
u8 *TLobby__sub_80209584(u8 *arg0, s32 arg1) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0xE8);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = __ct__14SubtractiveRngFv((void *) temp_r3);
    }
    *(s32 *)((s8 *)arg0 + 0) = var_r0;
    *(s32 *)((s8 *)arg0 + 4) = (s32)mem_alloc((arg1 * 4));
    *(s32 *)((s8 *)arg0 + 8) = 0;
    *(s32 *)((s8 *)arg0 + 0xC) = arg1;
    *(s32 *)((s8 *)arg0 + 0x10) = arg1;
    return arg0;
}
Hdr_802095EC *find_type5_header__6TLobbyFPvi(Hdr_802095EC *arg, s32 id) {
    Hdr_802095EC *p;
    if ((p = arg) != NULL) {
        for (;;) {
            Hdr_802095EC h = *p;
            ((TLobby *)(&h))->bswap_quad_word();
            if (h.type == 5) {
                if (h.id == id) {
                    return p + 1;
                }
            }
            if (h.type == 0) {
                break;
            }
            p = (Hdr_802095EC *)((u8 *)p + h.size);
        }
    }
    return NULL;
}
Hdr_8020967C *find_chunk_by_id__6TLobbyFPvi(Hdr_8020967C *arg, s32 id) {
    Hdr_8020967C *p;
    if ((p = arg) != NULL) {
        for (;;) {
            Hdr_8020967C h = *p;
            ((TLobby *)(&h))->bswap_quad_word();
            if (h.type == 4) {
                if (h.id == id) {
                    return p + 1;
                }
            }
            if (h.type == 0) {
                break;
            }
            p = (Hdr_8020967C *)((u8 *)p + h.size);
        }
    }
    return NULL;
}

}

// ---- pso/unk/TLobby_8020970C

extern u8 *lbl_805D60C4;
extern s32 lbl_805D60C8;

void TLobby::append_swapped_u32(s32 *arg0) {
    s32 sp8;

    if (lbl_805D60C4 != NULL) {
        sp8 = *arg0;
        bswap_32((u32 *)&sp8);
        ((TLobby *)(lbl_805D60C4 + lbl_805D60C8))->move_data(&sp8, 4);
        lbl_805D60C8 += 4;
    }
}

void TLobby::append_entity_entry() {
    s32 arg0 = (s32)this;
    if (lbl_805D60C4 != NULL) {
        ((TLobby *)(lbl_805D60C4 + lbl_805D60C8))->move_data((s32 *)arg0, 1);
        lbl_805D60C8 += 1;
    }
}

// ---- pso/unk/text_802097B0
struct Ent_802098AC { f32 a, b, c; u32 d, e, f, g; };

struct Out_802098AC { u8 pad[0x14]; f32 a, b, c; u32 d, e, f; };

struct Hdr_802099FC { s32 table; s32 b; s32 count; s32 d; };

struct Rec_802099FC { f32 f[5]; s16 h[6]; };

struct Out_802099FC {
    u8 pad0[6];
    s16 f6;
    u8 pad8[0x2C - 8];
    f32 f[5];
    s16 f40;
    s16 f42;
};

struct Hdr_80209AEC { s32 a; s32 table; s32 c; s32 count; };

struct Ent_80209AEC { u8 b0; u8 b1; u8 weight; u8 pad; };

struct Rec_802099FC;
struct Tmp_8020994C { u8 pad[0x18]; s16 v; u8 pad2[2]; };

struct Hdr_802097B0 { s32 table; s32 data; s32 count; };

struct Ent_802097B0 { s16 id; s16 count; s32 offset; };

void init_event_shuffle_table(EventShuffleTable *table, s32 count);

s32 next_event_shuffle_entry(EventShuffleTable *s);
extern s32 lbl_805D60A4;
Ent_802098AC *lbl_805D60B8;
extern "C" {
extern u8 *TLobby__item_data_table_buffer;
void TLobby__sub_802099FC(Out_802099FC *arg0, s32 arg1);
extern s32 item_drop_rng;
Rec_802099FC *bsearch_record__6TLobbyFPvii(void *arg0, s32 n, s32 key);
extern u8 *lbl_805D60AC;

void TLobby__sub_802097B0(s16 id) {
    Ent_802097B0 e;
    Hdr_802097B0 hdr = *(Hdr_802097B0 *)lbl_805D60AC;
    u8 *table;
    s32 lo;
    s32 hi;
    s32 mid;

    ((TLobby *)(&hdr))->bswap_vec3();
    table = lbl_805D60AC + hdr.table;
    lo = 0;
    hi = hdr.count - 1;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        TLobby__sub_8020A3D0(&e, table + mid * 8);
        TLobby__sub_8020A394(&e);
        if (e.id < id) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    TLobby__sub_8020A3D0(&e, table + lo * 8);
    TLobby__sub_8020A394(&e);
    if (e.id == id) {
        lbl_805D60B8 = (Ent_802098AC *)((u32)lbl_805D60AC + hdr.data + e.offset);
        init_event_shuffle_table((EventShuffleTable *)lbl_805D60A4, e.count);
    }
}

void TLobby::pick_random_entry() {
    Out_802098AC *out = (Out_802098AC *)this;
    s32 i = next_event_shuffle_entry((EventShuffleTable *)lbl_805D60A4);
    Ent_802098AC e = lbl_805D60B8[i];
    ((TLobby *)(&e))->swap_header_endian();
    out->a = e.a;
    out->b = e.b;
    out->c = e.c;
    out->d = e.d;
    out->e = e.e;
    out->f = e.f;
}

Rec_802099FC *bsearch_record__6TLobbyFPvii(void *arg0, s32 n, s32 key) {
    u8 *arr = (u8 *)arg0;
    u8 *e;
    Tmp_8020994C t;
    s32 lo;
    s32 hi;
    s32 mid;
    hi = n - 1;
    lo = 0;
    while (lo < hi) {
        mid = (lo + hi) / 2;
        ((TLobby *)(&t))->copy_record_entry((s32)(arr + mid * 32));
        TLobby__sub_8020A48C(&t);
        if (t.v < key) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    e = arr + lo * 32;
    ((TLobby *)(&t))->copy_record_entry((s32)e);
    TLobby__sub_8020A48C(&t);
    if (t.v == key) {
        return (Rec_802099FC *)e;
    }
    return NULL;
}

void TLobby__sub_802099FC(Out_802099FC *arg0, s32 key) {
    Hdr_802099FC hdr = *(Hdr_802099FC *)TLobby__item_data_table_buffer;
    Rec_802099FC *p;
    TLobby__sub_8020A568(&hdr);
    p = bsearch_record__6TLobbyFPvii((void *)(TLobby__item_data_table_buffer + hdr.table), hdr.count, key);
    if (p != NULL) {
        Rec_802099FC r = *p;
        TLobby__sub_8020A48C(&r);
        arg0->f[0] = r.f[0];
        arg0->f[1] = r.f[1];
        arg0->f[2] = r.f[2];
        arg0->f[3] = r.f[3];
        arg0->f[4] = r.f[4];
        arg0->f40 = r.h[1];
        arg0->f42 = r.h[0];
        arg0->f6 = TLobby::clamp_min_drop(r.h[4], r.h[5] + 1);
    }
}
}
void TLobby::pick_weighted_entry(s32 *arg0, s32 *arg1) {
    Hdr_80209AEC hdr = *(Hdr_80209AEC *)TLobby__item_data_table_buffer;
    Ent_80209AEC *tbl;
    u32 total;
    u32 r;
    s32 i;
    s32 n;
    TLobby__sub_8020A568(&hdr);
    tbl = (Ent_80209AEC *)(TLobby__item_data_table_buffer + hdr.table);
    n = hdr.count;
    total = 0;
    for (i = 0; i < n; i++) {
        total += tbl[i].weight;
    }
    r = item_drop_rng_below(item_drop_rng, total);
    for (i = 0; i < n; i++) {
        if (tbl[i].weight != 0) {
            if (r < tbl[i].weight) {
                *arg0 = tbl[i].b1;
                *arg1 = tbl[i].b0;
                return;
            }
            r -= tbl[i].weight;
        }
    }
    *arg1 = -1;
    *arg0 = -1;
}

// ---- pso/unk/TLobby_80209BD8

extern "C" {

extern const s32 lobby_random_slot_id_table[42] = {
    68, 67, 65, 66, 64, 96, 97, 98, 99, 100, 101, 128, 129, 130,
    131, 132, 133, 160, 161, 162, 163, 164, 165, 166, 167, 168, 212, 213,
    214, 215, 216, 217, 218, 219, 220, 221, 222, 223, 224, 224, 225, 0,
};

s32 pick_random_slot__6TLobbyFPv(s16 *arg0) {
    s32 key;
    s32 sp8;

    TLobby::pick_weighted_entry(&key, &sp8);
    if ((key != -1) && (sp8 != -1)) {
        *arg0 = (s16) lobby_random_slot_id_table[sp8];
        TLobby__sub_802099FC((Out_802099FC *)arg0, key);
        ((TLobby *)arg0)->pick_random_entry();
        return 0;
    }
    return 1;
}

}

// ---- pso/unk/text_80209C58
struct Hdr_80209C58 { s32 type; s32 size; s32 id; s32 x; };

extern "C" {
extern s32 lbl_805D60CC;
Hdr_80209C58 *find_header_by_id__6TLobbyFPvi(Hdr_80209C58 *arg, s32 id) {
    Hdr_80209C58 *p;
    if ((p = arg) != NULL) {
        for (;;) {
            Hdr_80209C58 h = *p;
            ((TLobby *)(&h))->bswap_quad_word();
            if (h.type == 3) {
                if (h.id == id) {
                    lbl_805D60CC = h.x;
                    return p + 1;
                }
            }
            if (h.type == 0) {
                break;
            }
            p = (Hdr_80209C58 *)((u8 *)p + h.size);
        }
    }
    lbl_805D60CC = -1;
    return NULL;
}

}

// ---- pso/unk/TLobby_80209CF8

extern "C" {
}

// A random value in [0, max) from the item drop RNG, raised to at least min.
u32 TLobby::clamp_min_drop(u32 min, u32 max) {
    u32 value;

    value = item_drop_rng_below(item_drop_rng, max);
    if (value < min) {
        value = min;
    }
    return value;
}

struct SetHeader_80209D34 {
    s32 data_offset;
    s32 record_offset;
    s32 record_count;
    s32 unk_c;
};

struct SetRecord_80209D34 {
    s32 base_id;
    s16 x;
    s16 z;
    s16 type;
    s16 first_index;
    s16 drop_min;
    s16 drop_max;
    u8 spawn_min;
    u8 spawn_max;
    s16 group_count;
    s32 data;
};

struct SetEntry_80209D34 {
    s32 id;
    s16 x;
    s16 z;
    s16 type;
    s16 index;
    s32 drops;
    s32 data;
};

struct SpawnSlot_80209D34 {
    u8 pad0[0xC];
    s16 type;
    s16 index;
    u8 pad10[0x48 - 0x10];
};

extern "C" {
void reserve_enemy_set_actor_ids(SpawnSlot_80209D34 *slots, s32 count, s32 floor);
extern u8 *lbl_805D60A8;
extern SpawnSlot_80209D34 *lbl_805D60B4;
extern SetEntry_80209D34 *lbl_805D60BC;
extern s32 lbl_805D60C0;
void TLobby__sub_80209D34(s32 floor);
u8 *alloc_heap_slot__6TLobbyFll(s32 floor, s32 size);
s32 init_floor_enemy_count__6TLobbyFlPUcUl(s32 floor, u8 *slots, u32 size);
}

#pragma push
#pragma cplusplus off
#pragma dont_inline off
void TLobby__sub_80209D34(s32 floor_id) {
  void append_swapped_u32__6TLobbyFPl(void *value);
  struct SetHeader_80209D34 hdr;
  u32 val;
  u8 ent[4];
  u32 out_hdr[4];
  struct SetRecord_80209D34 rec;
  s32 off;
  u8 *p;
  s32 rem;
  s32 slots;
  s16 index;
  s16 id;
  s32 i;
  s32 groups;
  s32 spawns;
  s32 area;
  s32 aligned;
  s32 total;
  s32 size;
  void *dst;
  hdr = *((struct SetHeader_80209D34 *) lbl_805D60A8);
  swap_endian_header__6TLobbyFv((u8 *) &hdr);
  p = ((u8 *) lbl_805D60A8) + hdr.record_offset;
  rem = lbl_805D60CC - ((hdr.record_count * 0x18) + 0x10);
  memset(lbl_805D60B4, 0, 0x9000);
  memset(lbl_805D60BC, 0, 0x1400);
  lbl_805D60C0 = 0;
  memset(lbl_805D60C4, 0, 0x1000);
  lbl_805D60C8 = (off = 0);
  slots = 0;
  for (i = 0; i < hdr.record_count; i++, p += 0x18)
  {
    TLobby__sub_8020A618(&rec, p);
    bswap__6TLobbyFv(&rec);
    groups = clamp_min_drop__6TLobbyFUlUl(1, (rec.group_count) + 1);
    id = rec.base_id;
    index = rec.first_index;
    while ((groups--) > 0)
    {
      spawns = clamp_min_drop__6TLobbyFUlUl(rec.spawn_min, (rec.spawn_max) + 1);
      TLobby__sub_802097B0(rec.type);
      while ((spawns--) > 0)
      {
        if (pick_random_slot__6TLobbyFPv((s16 *) (((u8 *) lbl_805D60B4) + off)) == 0)
        {
          *((s16 *) ((((u8 *) lbl_805D60B4) + off) + 0xe)) = index;
          *((s16 *) ((((u8 *) lbl_805D60B4) + off) + 0xc)) = rec.type;
          slots++;
          off += 0x48;
        }
      }

      if (groups > 0)
      {
        *((s32 *) (((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14))) = id;
        *((s16 *) ((((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14)) + 4)) = rec.x;
        *((s16 *) ((((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14)) + 6)) = rec.z;
        *((s16 *) ((((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14)) + 8)) = rec.type;
        *((s16 *) ((((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14)) + 0xa)) = index;
        *((s32 *) ((((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14)) + 0xc)) = clamp_min_drop__6TLobbyFUlUl(rec.drop_min, (rec.drop_max) + 1);
        *((s32 *) ((((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14)) + 0x10)) = rem + lbl_805D60C8;
        id = (s16) (((rec.base_id) + 0x2710) + index);
        ent[0] = 0xc;
        append_entity_entry__6TLobbyFv(ent);
        val = (u16) id;
        append_swapped_u32__6TLobbyFPl(&val);
        ent[0] = 1;
        append_entity_entry__6TLobbyFv(ent);
        lbl_805D60C0++;
        index++;
      }
    }

    TLobby__sub_8020A618(&rec, p);
    bswap__6TLobbyFv(&rec);
    *((s32 *) (((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14))) = id;
    *((s16 *) ((((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14)) + 4)) = rec.x;
    *((s16 *) ((((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14)) + 6)) = rec.z;
    *((s16 *) ((((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14)) + 8)) = rec.type;
    *((s16 *) ((((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14)) + 0xa)) = index;
    *((s32 *) ((((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14)) + 0xc)) = clamp_min_drop__6TLobbyFUlUl(rec.drop_min, (rec.drop_max) + 1);
    *((s32 *) ((((u8 *) lbl_805D60BC) + (lbl_805D60C0 * 0x14)) + 0x10)) = rec.data;
    lbl_805D60C0++;
  }

  if (slots > 0)
  {
    area = get_floor_area(floor_id);
    reserve_enemy_set_actor_ids(lbl_805D60B4, slots, area);
    init_floor_enemy_count__6TLobbyFlPUcUl(floor_id, (u8 *) lbl_805D60B4, slots * 0x48);
  }
  if (lbl_805D60C0 > 0)
  {
    total = lbl_805D60C0 * 0x14;
    size = lbl_805D60C8 + 3;
    aligned = size;
    aligned &= ~3;
    total += rem;
    size = total;
    size += aligned;
    size += 0x10;
    dst = alloc_heap_slot__6TLobbyFll(floor_id, size);
    if (dst != 0)
    {
      out_hdr[0] = (lbl_805D60C0 * 0x14) + 0x10;
      out_hdr[1] = 0x10;
      out_hdr[2] = lbl_805D60C0;
      move_data__6TLobbyFPCvUl(dst, out_hdr, 0x10);
      if (lbl_805D60C0 > 0)
      {
        dst = ((u8 *) dst) + 0x10;
        move_data__6TLobbyFPCvUl(dst, lbl_805D60BC, lbl_805D60C0 * 0x14);
      }
      if (rem > 0)
      {
        dst = ((u8 *) dst) + (lbl_805D60C0 * 0x14);
        move_data__6TLobbyFPCvUl(dst, ((u8 *) lbl_805D60A8) + hdr.data_offset, rem);
      }
      if (aligned > 0)
      {
        dst = ((u8 *) dst) + rem;
        move_data__6TLobbyFPCvUl(dst, lbl_805D60C4, aligned);
      }
    }
  }
}
#pragma pop

extern "C" {

void init_buffers__6TLobbyFii(s32 id, s32 arg1) {
    Hdr_802095EC *items;

    lbl_805D60A8 = (u8 *)find_header_by_id__6TLobbyFPvi((Hdr_80209C58 *)arg1, id);
    lbl_805D60AC = (u8 *)find_chunk_by_id__6TLobbyFPvi((Hdr_8020967C *)arg1, id);
    items = find_type5_header__6TLobbyFPvi((Hdr_802095EC *)arg1, id);
    TLobby__item_data_table_buffer = (u8 *)items;
    if (lbl_805D60A8 != NULL && lbl_805D60AC != NULL && items != NULL) {
        lbl_805D60B4 = (SpawnSlot_80209D34 *)TQuestVmDownLoadServer::alloc(0x9000);
        lbl_805D60BC = (SetEntry_80209D34 *)TQuestVmDownLoadServer::alloc(0x1400);
        lbl_805D60C0 = 0;
        lbl_805D60C4 = (u8 *)TQuestVmDownLoadServer::alloc(0x1000);
        lbl_805D60C8 = 0;
        TLobby__sub_80209D34(id);
        TAdSinglePlyChrSelectGC::safe_free((u32)lbl_805D60C4);
        TAdSinglePlyChrSelectGC::safe_free((u32)lbl_805D60BC);
        lbl_805D60BC = NULL;
        TAdSinglePlyChrSelectGC::safe_free((u32)lbl_805D60B4);
        lbl_805D60B4 = NULL;
    }
}

void TLobby::free_boss4rock() { ((TLobby *)lbl_805D60A4)->free_boss4rock(1); lbl_805D60A4 = 0; ::operator delete((void *)item_drop_rng); item_drop_rng = 0; }

}
