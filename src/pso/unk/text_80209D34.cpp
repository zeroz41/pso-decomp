#include "types.h"
#include "string.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_8020A568.h"
#include "pso/unk/text_802097B0.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/unk/TLobby_80209BD8.h"


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
extern u8 *lbl_805D60C4;
extern s32 lbl_805D60C8;
extern s32 lbl_805D60CC;
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
