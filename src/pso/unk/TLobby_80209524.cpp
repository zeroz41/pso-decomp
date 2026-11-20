#include "pso/map/FloorPopulation.h"
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/unk/TLobby_80209524.h"
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
#include "pso/unk/text_8020A2AC.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/unk/text_8020A6B0.h"
#include "pso/unk/text_8020A768.h"
#include "pso/unk/TLobby_80131794.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/unk/text_800F8A18.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/unk/text_8020AB50.h"
#include "pso/unk/TLobby_8020B03C.h"
#include "pso/unk/text_8020AD40.h"
#include "pso/unk/text_800F8A0C.h"
#include "pso/system/TGStream.h"
#include "pso/unk/TLobby_8020B334.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

// ---- pso/unk/TLobby_80209524

extern "C" {


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

struct Ent_802098AC;
struct SpawnRecord_8020A9C4;
struct SetEntry_80209D34;

s32 item_drop_rng;
s32 lbl_805D60A4;
u8 *lbl_805D60A8;
u8 *lbl_805D60AC;
u8 *TLobby__item_data_table_buffer;
SpawnRecord_8020A9C4 *lbl_805D60B4;
Ent_802098AC *lbl_805D60B8;
SetEntry_80209D34 *lbl_805D60BC;
s32 lbl_805D60C0;
u8 *lbl_805D60C4;
s32 lbl_805D60C8;
s32 lbl_805D60CC;

// ---- pso/unk/text_80209584

struct Hdr_802095EC { s32 type; s32 size; s32 id; s32 x; };

struct Hdr_8020967C { s32 type; s32 size; s32 id; s32 x; };

extern "C" {
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
extern "C" {
void TLobby__sub_802099FC(Out_802099FC *arg0, s32 arg1);
Rec_802099FC *bsearch_record__6TLobbyFPvii(void *arg0, s32 n, s32 key);

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


// ---- pso/unk/text_80209C58
struct Hdr_80209C58 { s32 type; s32 size; s32 id; s32 x; };

extern "C" {
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

struct SpawnRecord_8020A9C4 {
    s16 type;
    u16 flags;
    s16 index;
    s16 children;
    u16 reserved;
    s16 actor_id;
    u8 pad[0x48 - 0xC];
};

extern "C" {
void reserve_enemy_set_actor_ids(SpawnRecord_8020A9C4 *slots, s32 count, s32 floor);
s32 init_floor_enemy_count__6TLobbyFlPUcUl(s32 floor, u8 *slots, s32 size);
u8 *alloc_heap_slot__6TLobbyFll(s32 floor, s32 size);
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
        lbl_805D60B4 = (SpawnRecord_8020A9C4 *)TQuestVmDownLoadServer::alloc(0x9000);
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

// ---- pso/unk/text_8020A2AC
s32 run_step__9TItemDropFl(int, void *);
s32 __cvt_fp2unsigned(f32);
s32 rand();
s32 item_drop_server_seed;
s32 lbl_805D60D4;
s32 map_set_data_handle_a;
s32 map_set_data_handle_b;
s32 map_set_object_id_counter;
s32 TLobby__next_enemy_set_actor_id;
s32 map_object_id_counter;
s32 map_set_enemy_id_counter;
u8 *TLobby__map_set_file_buffer;
s32 TLobby__map_set_file_buffer_size;
void TLobby__sub_8020A2AC(void) {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r0;
    s32 var_r0_2;
    if (TRaderMapCore::is_not_split_screen() == 1) {
        item_drop_server_seed = __cvt_fp2unsigned((f32) (4294967300.0f * (3.0517578e-05f * (f32) rand())));
    }
    temp_r3 = (int)::operator new(0xE8);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = run_step__9TItemDropFl((int)temp_r3, (void *)item_drop_server_seed);
    }
    item_drop_rng = var_r0;
    temp_r3_2 = (int)::operator new(0x14);
    var_r0_2 = temp_r3_2;
    if (var_r0_2 != 0) {
        var_r0_2 = (s32)TLobby__sub_80209584((u8 *)temp_r3_2, 0x20);
    }
    lbl_805D60A4 = var_r0_2;
}

}

// ---- pso/unk/TLobby_8020A350

void TLobby::bswap_quad_word() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); }

void TLobby__sub_8020A394(void* p) { bswap_16((u16 *)p); bswap_16((u16 *)((char*)p + 0x2)); bswap_32((u32 *)((char*)p + 0x4)); }

void TLobby__sub_8020A3D0(void *arg0, void *arg1) {
    *(s16 *)((s8 *)arg0 + 0) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
}

void TLobby::bswap_vec3() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }

void TLobby::swap_header_endian() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); bswap_32((u32 *)((char*)this + 0x10)); bswap_32((u32 *)((char*)this + 0x14)); bswap_16((u16 *)((char*)this + 0x18)); bswap_16((u16 *)((char*)this + 0x1a)); }

void TLobby__sub_8020A48C(void* p) { bswap_32((u32 *)p); bswap_32((u32 *)((char*)p + 0x4)); bswap_32((u32 *)((char*)p + 0x8)); bswap_32((u32 *)((char*)p + 0xc)); bswap_32((u32 *)((char*)p + 0x10)); bswap_16((u16 *)((char*)p + 0x14)); bswap_16((u16 *)((char*)p + 0x16)); bswap_16((u16 *)((char*)p + 0x18)); bswap_16((u16 *)((char*)p + 0x1a)); bswap_16((u16 *)((char*)p + 0x1c)); bswap_16((u16 *)((char*)p + 0x1e)); }

// ---- pso/unk/text_8020A508

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_14 { u8 bytes[0x14]; };

void TLobby::copy_record_entry(s32 arg1) {
    s32 arg0 = (s32)this;
    *(ByteBlock_14 *)(arg0) = *(const ByteBlock_14 *)(arg1);
    *(s16 *)((s8 *)arg0 + 0x14) = (s16) *(s16 *)((s8 *)arg1 + 0x14);
    *(s16 *)((s8 *)arg0 + 0x16) = (s16) *(s16 *)((s8 *)arg1 + 0x16);
    *(s16 *)((s8 *)arg0 + 0x18) = (s16) *(s16 *)((s8 *)arg1 + 0x18);
    *(s16 *)((s8 *)arg0 + 0x1A) = (s16) *(s16 *)((s8 *)arg1 + 0x1A);
    *(s16 *)((s8 *)arg0 + 0x1C) = (s16) *(s16 *)((s8 *)arg1 + 0x1C);
    *(s16 *)((s8 *)arg0 + 0x1E) = (s16) *(s16 *)((s8 *)arg1 + 0x1E);
}

// ---- pso/unk/TLobby_8020A568

void TLobby__sub_8020A568(void* p) { bswap_32((u32 *)p); bswap_32((u32 *)((char*)p + 0x4)); bswap_32((u32 *)((char*)p + 0x8)); bswap_32((u32 *)((char*)p + 0xc)); }

void TLobby::bswap() { bswap_32((u32 *)this); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_16((u16 *)((char*)this + 0x8)); bswap_16((u16 *)((char*)this + 0xa)); bswap_16((u16 *)((char*)this + 0xc)); bswap_16((u16 *)((char*)this + 0xe)); bswap_16((u16 *)((char*)this + 0x12)); bswap_32((u32 *)((char*)this + 0x14)); }

void TLobby__sub_8020A618(void *arg0, void *arg1) {
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)arg0 + 4) = (s16) *(s16 *)((s8 *)arg1 + 4);
    *(s16 *)((s8 *)arg0 + 6) = (s16) *(s16 *)((s8 *)arg1 + 6);
    *(s16 *)((s8 *)arg0 + 8) = (s16) *(s16 *)((s8 *)arg1 + 8);
    *(s16 *)((s8 *)arg0 + 0xA) = (s16) *(s16 *)((s8 *)arg1 + 0xA);
    *(s16 *)((s8 *)arg0 + 0xC) = (s16) *(s16 *)((s8 *)arg1 + 0xC);
    *(s16 *)((s8 *)arg0 + 0xE) = (s16) *(s16 *)((s8 *)arg1 + 0xE);
    *(u8 *)((s8 *)arg0 + 0x10) = (u8) *(u8 *)((s8 *)arg1 + 0x10);
    *(u8 *)((s8 *)arg0 + 0x11) = (u8) *(u8 *)((s8 *)arg1 + 0x11);
    *(s16 *)((s8 *)arg0 + 0x12) = (s16) *(s16 *)((s8 *)arg1 + 0x12);
    *(s32 *)((s8 *)arg0 + 0x14) = (s32) *(s32 *)((s8 *)arg1 + 0x14);
}

void TLobby::swap_endian_header() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); }

// ---- pso/unk/text_8020A6B0

/* Per-area map set table: area -> terrain variants -> map set entries. */
struct MapSetEntry {
    s32 object_set_name; // file base name read by load_area_object_set
    s32 enemy_set_name;  // file base name read by load_area_enemy_set
    s32 unk_8;
};

struct MapSetVariant {
    MapSetEntry *entries;
    s32 count;
};

struct MapSetArea {
    MapSetVariant *variants;
    s32 count;
};


extern MapSetArea *TLobby__data_805D6068;

void TLobby__sub_8020A6B0(s32 player) {
    s32 area = get_floor_area(player);
    s32 terrain = get_floor_map_terrain(player);
    MapSetVariant *variants;
    MapSetEntry *entries;

    variants = TLobby__data_805D6068[area].variants;
    if (variants == NULL || TLobby__data_805D6068[area].count - 1 < terrain) {
        return;
    }
    entries = variants[terrain].entries;
    if (entries == NULL || variants[terrain].count - 1 < 0) {
        return;
    }
    load_map_set_data(player, entries[0].object_set_name);
}

// ---- pso/unk/TLobby_8020A744

extern "C" {

int rebuild_entry__6TLobbyFv(void);
int init_sub_state__6TLobbyFv(void);

void TLobby::init_sub_objects() { init_sub_state__6TLobbyFv(); rebuild_entry__6TLobbyFv(); }

}

// ---- pso/unk/text_8020A768
struct Ent_8020A768 { s16 a; s16 b; u8 pad[0x48 - 4]; };

struct Name_8020A768 { char s[0x20]; };

struct Ent_8020A834 { s16 a; s16 b; u8 pad[0x44 - 4]; };

struct Name_8020A834 { char s[0x20]; };

extern "C" {
// The callers pass the signed file size as the count.
s32 load_object_set_entries__6TLobbyFlPUcUl(s32, u8 *, s32);
}
s32 load_enemy_set_file(s32 idx, s32 arg1) {
    Name_8020A768 name;
    s32 size;
    Ent_8020A768 *p;
    s32 n;
    s32 i;
    s32 floor;
    replace_file_extension__6TLobbyFPvPvPv((char *)&name, (char *)arg1, "e.dat");
    size = read_disc_file(name.s, TLobby__map_set_file_buffer);
    if (size < 0) {
        return 0;
    }
    if (size > TLobby__map_set_file_buffer_size) {
        return 0;
    }
    p = (Ent_8020A768 *)TLobby__map_set_file_buffer;
    n = size / sizeof(Ent_8020A768);
    for (i = 0; i < n; i++, p++) {
        bswap_enemy_set_row(p);
        p->b = 0;
    }
    floor = get_floor_area(idx);
    reserve_enemy_set_actor_ids((struct SpawnRecord_8020A9C4 *)TLobby__map_set_file_buffer, n, floor);
    init_floor_enemy_count__6TLobbyFlPUcUl(idx, TLobby__map_set_file_buffer, size);
    return 1;
}
s32 load_object_set_file(s32 idx, s32 arg1) {
    Name_8020A834 name;
    s32 size;
    Ent_8020A834 *p;
    s32 n;
    s32 i;
    s32 floor;
    replace_file_extension__6TLobbyFPvPvPv(name.s, (char *)arg1, "o.dat");
    size = read_disc_file(name.s, TLobby__map_set_file_buffer);
    if (size < 0) {
        return 0;
    }
    if (size > TLobby__map_set_file_buffer_size) {
        return 0;
    }
    p = (Ent_8020A834 *)TLobby__map_set_file_buffer;
    n = size / sizeof(Ent_8020A834);
    for (i = 0; i < n; i++, p++) {
        swap_object_row_endian(p);
        p->b = 0;
    }
    floor = get_floor_area(idx);
    ((TLobby *)TLobby__map_set_file_buffer)->assign_object_ids(n, (void *)floor);
    load_object_set_entries__6TLobbyFlPUcUl(idx, TLobby__map_set_file_buffer, size);
    return 1;
}

extern s16 TLobby__data_805D6134;
extern s32 TLobby__data_805D6148;
extern s32 TLobby__data_805D614C;

void load_map_set_data(s32 idx, s32 arg1) {
    map_set_data_handle_a = 0;
    map_set_data_handle_b = 0;
    map_set_object_id_counter = 0;
    TLobby__next_enemy_set_actor_id = 0;
    map_object_id_counter = 0;
    map_set_enemy_id_counter = 0;
    copy_name((s32)"SET");
    TLobby__data_805D6134 = 0;
    if (TLobby::init_handle(0x8000) != 0) {
        load_object_set_file(idx, arg1);
        load_enemy_set_file(idx, arg1);
        advance_object_id_counter((u16) map_object_id_counter);
        TLobby__data_805D6148 = map_set_object_id_counter;
        advance_enemy_id_counter((u16) map_set_enemy_id_counter);
        TLobby__data_805D614C = TLobby__next_enemy_set_actor_id;
        TLobby::free_data_60F0();
        TLobby__data_805D6134 |= 1;
    }
    copy_name((s32)"..");
}

struct Rec_8020AA94 {
    u8 pad0[4];
    s16 f4;
    u8 pad6[2];
    s16 f8;
    u8 padA[0x44 - 0xA];
};

extern "C" {
s32 get_enemy_factory_child_count(s32, SpawnRecord_8020A9C4 *);
s32 find_floor_object_factory__6TLobbyFlPs(void *, Rec_8020AA94 *);
void reserve_enemy_set_actor_ids(SpawnRecord_8020A9C4 *arg0, s32 arg1, s32 arg2) {
    SpawnRecord_8020A9C4 *r;
    s32 i;
    s32 n;
    for (i = 0; i < arg1; i++) {
        r = &arg0[i];
        r->actor_id = map_set_enemy_id_counter++ + 0x1000;
        r->index = TLobby__next_enemy_set_actor_id++;
        if (r->children > 0) {
            TLobby__next_enemy_set_actor_id += r->children;
            map_set_enemy_id_counter += r->children;
        } else {
            n = get_enemy_factory_child_count(arg2, r);
            if (n > 0) {
                TLobby__next_enemy_set_actor_id += n;
                map_set_enemy_id_counter += n;
                r->children = n;
            }
        }
    }
}
void TLobby::assign_object_ids(s32 arg1, void *lobby) {
    s32 i;
    s32 r;
    for (i = 0; i < arg1; i++) {
        ((Rec_8020AA94 *)this)[i].f8 = map_object_id_counter++ + 0x4000;
        ((Rec_8020AA94 *)this)[i].f4 = map_set_object_id_counter++;
        r = find_floor_object_factory__6TLobbyFlPs(lobby, &((Rec_8020AA94 *)this)[i]);
        if (r >= 0) {
            map_set_object_id_counter += r;
            map_object_id_counter += r;
        }
    }
}

// ---- pso/unk/TLobby_8020AB30
int clear_record_flags_a__6TLobbyFv(void*);

int TLobby::rebuild_entry() { return clear_record_flags_a__6TLobbyFv(this); }

}

// ---- pso/unk/text_8020AB50

s32 load_area_enemy_set(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char buf[0x28];
    s32 name;
    s32 size;
    u8 *p;
    s32 count;
    s32 i;
    MapSetVariant *t2;
    MapSetEntry *t3;
    t2 = TLobby__data_805D6068[arg1].variants;
    if (t2 == NULL || TLobby__data_805D6068[arg1].count - 1 < arg2) {
        TLobby::debug_print("NOT FOUND SET");
        return 0;
    }
    t3 = t2[arg2].entries;
    if (t3 == NULL || t2[arg2].count - 1 < arg3) {
        TLobby::debug_print("NOT FOUND SET");
        return 0;
    }
    name = t3[arg3].enemy_set_name;
    if (arg1 == 0 || arg1 == 0x12) {
        switch (get_game_play_mode()) {
        case 0:
            replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)name, "e.dat");
            break;
        case 1:
            replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)name, "e_c1.dat");
            break;
        case 2:
            replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)name, "e_d.dat");
            break;
        }
    } else {
        replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)name, "e.dat");
    }
    size = read_disc_file(buf, TLobby__map_set_file_buffer);
    if (size < 0) {
        return 0;
    }
    if (size > TLobby__map_set_file_buffer_size) {
        return 0;
    }
    p = TLobby__map_set_file_buffer;
    count = (u32)size / 0x48;
    for (i = 0; i < count; i++, p += 0x48) {
        bswap_enemy_set_row(p);
        *(s16 *)(p + 2) = 0;
    }
    reserve_enemy_set_actor_ids((SpawnRecord_8020A9C4 *)TLobby__map_set_file_buffer, count, arg1);
    init_floor_enemy_count__6TLobbyFlPUcUl(arg0, TLobby__map_set_file_buffer, size);
    return 1;
}

// ---- pso/unk/TLobby_8020AD20

extern "C" {

int clear_record_flags_b__6TLobbyFv(void*);

int TLobby::init_sub_state() { return clear_record_flags_b__6TLobbyFv(this); }

}

// ---- pso/unk/text_8020AD40

struct Stack_8020AF0C {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct Stack_8020AFA4 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct Rec_8020AD40 { u8 pad0[2]; s16 f2; u8 pad4[0x40]; };

extern "C" {
s32 is_area_transfer_pending();
}

s32 load_area_object_set(s32 arg0, s32 lobby, s32 arg2, s32 arg3) {
    char name[0x20];
    MapSetVariant *subs;
    MapSetEntry *items;
    s32 id;
    s32 len;
    Rec_8020AD40 *r;
    s32 n;
    s32 i;
    subs = TLobby__data_805D6068[lobby].variants;
    if (subs == NULL || TLobby__data_805D6068[lobby].count - 1 < arg2) {
        TLobby::debug_print("NOT FOUND SET");
        return 0;
    }
    items = subs[arg2].entries;
    if (items == NULL || subs[arg2].count - 1 < arg3) {
        TLobby::debug_print("NOT FOUND SET");
        return 0;
    }
    id = items[arg3].object_set_name;
    if (lobby == 0 || lobby == 0x12) {
        switch (get_game_play_mode()) {
        case 0:
            replace_file_extension__6TLobbyFPvPvPv((char *)name, (char *)id, "o.dat");
            break;
        case 1:
            replace_file_extension__6TLobbyFPvPvPv((char *)name, (char *)id, "o_c1.dat");
            break;
        case 2:
            replace_file_extension__6TLobbyFPvPvPv((char *)name, (char *)id, "o_d.dat");
            break;
        }
    } else {
        replace_file_extension__6TLobbyFPvPvPv((char *)name, (char *)id, "o.dat");
    }
    len = read_disc_file(name, TLobby__map_set_file_buffer);
    if (len < 0) {
        return 0;
    }
    if (len > TLobby__map_set_file_buffer_size) {
        return 0;
    }
    r = (Rec_8020AD40 *)TLobby__map_set_file_buffer;
    n = len / sizeof(Rec_8020AD40);
    for (i = 0; i < n; i++, r++) {
        swap_object_row_endian(r);
        r->f2 = 0;
    }
    ((TLobby *)TLobby__map_set_file_buffer)->assign_object_ids((s32)n, (void *)lobby);
    load_object_set_entries__6TLobbyFlPUcUl(arg0, TLobby__map_set_file_buffer, len);
    return 1;
}

s32 TLobby::load_all_floor_enemy_sets() {
    Stack_8020AF0C stack;
    s32 var_r31;
    var_r31 = 0;
loop_1:
    if ((get_floor_map_selection(var_r31, (u8 *)&stack.sp8) == 1) && (stack.sp8 >= 0)) {
        if (is_area_transfer_pending() != 0) {
            return 0;
        }
        load_area_enemy_set(var_r31, stack.sp8, stack.spC, stack.sp10);
        goto block_6;
    }
block_6:
    var_r31 += 1;
    if (var_r31 >= 0x12) {
        advance_enemy_id_counter(((u16) map_set_enemy_id_counter));
        TLobby__data_805D614C = TLobby__next_enemy_set_actor_id;
        TLobby::sum_floor_enemy_counts();
        return 1;
    }
    goto loop_1;
}
s32 TLobby::load_all_floor_object_sets() {
    Stack_8020AFA4 stack;
    s32 var_r31;
    var_r31 = 0;
loop_1:
    if ((get_floor_map_selection(var_r31, (u8 *)&stack.sp8) == 1) && (stack.sp8 >= 0)) {
        if (is_area_transfer_pending() != 0) {
            return 0;
        }
        load_area_object_set(var_r31, stack.sp8, stack.spC, stack.sp10);
        goto block_6;
    }
block_6:
    var_r31 += 1;
    if (var_r31 >= 0x12) {
        advance_object_id_counter(((u16) map_object_id_counter));
        TLobby__data_805D6148 = map_set_object_id_counter;
        TLobby__sub_8020B308();
        return 1;
    }
    goto loop_1;
}

// ---- pso/unk/TLobby_8020B03C

extern "C" {

u32 alloc__22TQuestVmDownLoadServerFUl();

void TLobby::free_data_60F0() {
    if (TLobby__map_set_file_buffer != NULL) {
        TAdSinglePlyChrSelectGC::safe_free((u32)TLobby__map_set_file_buffer);
        TLobby__map_set_file_buffer = NULL;
        TLobby__map_set_file_buffer_size = 0;
    }
}

s32 TLobby::init_handle(s32 arg0) {
    u32 temp_r3;

    temp_r3 = alloc__22TQuestVmDownLoadServerFUl();
    TLobby__map_set_file_buffer = (u8 *)temp_r3;
    if (temp_r3 != 0U) {
        TLobby__map_set_file_buffer_size = arg0;
        return 1;
    }
    TLobby__map_set_file_buffer = NULL;
    return 0;
}

}

void clear_map_set_data(void) {
    map_set_object_id_counter = 0;
    TLobby__next_enemy_set_actor_id = 0;
    map_object_id_counter = 0;
    map_set_enemy_id_counter = 0;
    TLobby__map_set_file_buffer_size = 0;
    const char *name = (const char *)get_player_name_copy_buffer();
    if (strncmp(name, "SET", 0x10) == 0) {
        copy_name((s32)"..");
    }
}


void TLobby::load_set_gsl_files() {
    map_set_data_handle_a = 0;
    map_set_data_handle_b = 0;
    map_set_object_id_counter = 0;
    TLobby__next_enemy_set_actor_id = 0;
    map_object_id_counter = 0;
    map_set_enemy_id_counter = 0;
    TLobby__map_set_file_buffer_size = 0;
    TLobby__data_805D6134 = 0;
    if (TLobby::init_handle(0x8000) != 0) {
        open_gsl_archive("gsl_set_object.gsl");
        if (TLobby::load_all_floor_object_sets() == 0) {
            close_gsl_archive();
            TLobby::free_data_60F0();
            TLobby__data_805D6134 |= 1;
            return;
        }
        close_gsl_archive();
        open_gsl_archive("gsl_set_enemy.gsl");
        if (TLobby::load_all_floor_enemy_sets() == 0) {
            close_gsl_archive();
            TLobby::free_data_60F0();
            TLobby__data_805D6134 |= 1;
            return;
        }
        close_gsl_archive();
        TLobby::free_data_60F0();
        TLobby__data_805D6134 |= 1;
    }
}

s32 TLobby::set_flags_on_matching_entries(s32 arg0, s16 arg1, s16 arg2, s32 arg3) {
    LobbyFloorRows *g = &TLobby__floor_enemy_group_table[arg0];
    FloorSavedSetRow *e;
    s32 n = 0;
    s32 i;
    if (g->enemy_count > 0) {
        e = g->enemy_rows;
        if (e != 0) {
            for (i = 0; i < g->enemy_count; i++, e++) {
                if (e->room == arg1 && e->wave == arg2) {
                    n++;
                    e->flags |= arg3;
                }
            }
        }
    }
    return n;
}

s32 TLobby::set_room_group_flags(s32 floor, s16 room, s16 group, s32 bits) {
    LobbyFloorRows *t = &TLobby__floor_enemy_group_table[floor];
    s32 n = 0;
    FloorSavedSetRow *e;
    s32 i;
    if (t->object_count > 0) {
        e = t->object_rows;
        if (e != NULL) {
            for (i = 0; i < t->object_count; i++, e++) {
                if (e->room == room && e->wave == group) {
                    e->flags |= bits;
                    n++;
                }
            }
        }
    }
    return n;
}

s32 TLobby::sum_floor_enemy_counts() {
    s32 sum = 0;
    s32 i;
    for (i = 0; i < 18; i++) sum += TLobby__data_80513CC8[i];
    return sum;
}
s32 TLobby__sub_8020B308(void) {
    s32 sum = 0;
    s32 i;
    for (i = 0; i < 18; i++) sum += TLobby__data_80513C80[i];
    return sum;
}

// ---- pso/unk/TLobby_8020B334

extern "C" {

int get_matching_object__6TLobbyFv(void*);
int get_object_count__6TLobbyFv(void*);

int TLobby::resolve_matching_object() { return get_matching_object__6TLobbyFv(this); }
int get_object_count__6TLobbyFPv(void* p) { return get_object_count__6TLobbyFv(p); }

// ---- pso/unk/text_8020B374
s32 TLobby::init_floor_enemy_count(s32 arg0, u8 *arg1, u32 arg2) {
    if (init_quest_floor_enemies(arg0, (EnemySetRecord *)arg1, arg2) == 1) {
        TLobby__data_80513CC8[arg0] = arg2 / 72U;
        return 1;
    }
    TLobby__data_80513CC8[arg0] = -1;
    return 0;
}

s32 TLobby::load_object_set_entries(s32 arg0, u8 *arg1, u32 arg2) {
    if (load_floor_enemy_group_entries__6TLobbyFiPvUi(arg0, (FloorObjectSetRow *)arg1, arg2) == 1) {
        TLobby__data_80513C80[arg0] = arg2 / 68U;
        return 1;
    }
    TLobby__data_80513C80[arg0] = -1;
    return 0;
}

int TLobby::get_object_type(int a0) {  return TLobby__data_80513CC8[a0]; }

int TLobby::get_obj_table_entry(int a0) {  return TLobby__data_80513C80[a0]; }

}

// ---- pso/unk/text_8020B47C

// Entity set-flag block of the 6x6E game-state sync: four big-endian words, the first and third the offsets
// of the per-floor object and enemy flag arrays from the block's start.
struct SyncSetFlagBlock_8020B47C {
    u32 object_flags_offset;
    u32 unk_4;
    u32 enemy_flags_offset;
    u32 unk_c;
};

extern "C" {
// Copies the received object and enemy set flags of every floor into the floor tables.
void TLobby__sub_8020B47C(SyncSetFlagBlock_8020B47C *block) {
    s32 j;
    FloorSavedSetRow *row;
    s32 i;
    s16 *src;
    s32 count;

    ((TLobby *)block)->bswap_4_words();
    src = (s16 *)((u8 *)block + block->object_flags_offset);
    for (i = 0; i < 18; i++) {
        if (TLobby__floor_enemy_group_table[i].object_count > 0) {
            count = TLobby__floor_enemy_group_table[i].object_count;
            row = TLobby__floor_enemy_group_table[i].object_rows;
            for (j = 0; j < count; j++) {
                s16 flags = *src;
                bswap_16((u16 *)&flags);
                row->flags = flags;
                src++;
                row++;
            }
        }
    }
    src = (s16 *)((u8 *)block + block->enemy_flags_offset);
    for (j = 0; j < 18; j++) {
        if (TLobby__floor_enemy_group_table[j].enemy_count > 0) {
            row = TLobby__floor_enemy_group_table[j].enemy_rows;
            count = TLobby__floor_enemy_group_table[j].enemy_count;
            for (i = 0; i < count; i++) {
                s16 flags = *src;
                bswap_16((u16 *)&flags);
                row->flags = flags;
                src++;
                row++;
            }
        }
    }
}
}

// ---- pso/unk/TLobby_8020B588

void TLobby::bswap_4_words() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); }
