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

struct EntityTag_80209D34 {
    u8 kind;
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
}

void TLobby__sub_80209D34(s32 floor) {
    SetHeader_80209D34 header = *(SetHeader_80209D34 *)lbl_805D60A8;
    SetRecord_80209D34 rec;
    EntityTag_80209D34 tag;
    s32 off;
    u8 *src;
    s32 extra;
    s32 slots;
    s16 index;
    s16 id;
    s32 r;
    s32 groups;
    u8 *dst;
    s32 spawns;
    s32 pad;
    s32 area;
    s32 key;
    s32 hdr[4];

    ((TLobby *)&header)->swap_endian_header();
    src = lbl_805D60A8 + header.record_offset;
    extra = lbl_805D60CC - (header.record_count * sizeof(SetRecord_80209D34) + sizeof(SetHeader_80209D34));
    memset(lbl_805D60B4, 0, 0x9000);
    memset(lbl_805D60BC, 0, 0x1400);
    lbl_805D60C0 = 0;
    memset(lbl_805D60C4, 0, 0x1000);
    lbl_805D60C8 = off = 0;
    slots = 0;
    for (r = 0; r < header.record_count; r++) {
        TLobby__sub_8020A618(&rec, src);
        ((TLobby *)&rec)->bswap();
        groups = TLobby::clamp_min_drop(1, rec.group_count + 1);
        index = rec.first_index;
        id = rec.base_id;
        while (groups-- > 0) {
            spawns = TLobby::clamp_min_drop(rec.spawn_min, rec.spawn_max + 1);
            TLobby__sub_802097B0(rec.type);
            while (spawns-- > 0) {
                if (pick_random_slot__6TLobbyFPv((s16 *)((u8 *)lbl_805D60B4 + off)) == 0) {
                    ((SpawnSlot_80209D34 *)((u8 *)lbl_805D60B4 + off))->index = index;
                    ((SpawnSlot_80209D34 *)((u8 *)lbl_805D60B4 + off))->type = rec.type;
                    slots++;
                    off += sizeof(SpawnSlot_80209D34);
                }
            }
            if (groups > 0) {
                lbl_805D60BC[lbl_805D60C0].id = id;
                lbl_805D60BC[lbl_805D60C0].x = rec.x;
                lbl_805D60BC[lbl_805D60C0].z = rec.z;
                lbl_805D60BC[lbl_805D60C0].type = rec.type;
                lbl_805D60BC[lbl_805D60C0].index = index;
                lbl_805D60BC[lbl_805D60C0].drops = TLobby::clamp_min_drop(rec.drop_min, rec.drop_max + 1);
                lbl_805D60BC[lbl_805D60C0].data = extra + lbl_805D60C8;
                id = rec.base_id + 10000 + index;
                tag.kind = 12;
                ((TLobby *)&tag)->append_entity_entry();
                key = (u16)id;
                TLobby::append_swapped_u32(&key);
                tag.kind = 1;
                ((TLobby *)&tag)->append_entity_entry();
                index++;
                lbl_805D60C0++;
            }
        }
        TLobby__sub_8020A618(&rec, src);
        ((TLobby *)&rec)->bswap();
        lbl_805D60BC[lbl_805D60C0].id = id;
        lbl_805D60BC[lbl_805D60C0].x = rec.x;
        lbl_805D60BC[lbl_805D60C0].z = rec.z;
        lbl_805D60BC[lbl_805D60C0].type = rec.type;
        lbl_805D60BC[lbl_805D60C0].index = index;
        lbl_805D60BC[lbl_805D60C0].drops = TLobby::clamp_min_drop(rec.drop_min, rec.drop_max + 1);
        src += sizeof(SetRecord_80209D34);
        lbl_805D60BC[lbl_805D60C0].data = rec.data;
        lbl_805D60C0++;
    }
    if (slots > 0) {
        area = get_floor_area(floor);
        reserve_enemy_set_actor_ids(lbl_805D60B4, slots, area);
        TLobby::init_floor_enemy_count(floor, (u8 *)lbl_805D60B4, slots * sizeof(SpawnSlot_80209D34));
    }
    if (lbl_805D60C0 > 0) {
        pad = (lbl_805D60C8 + 3) & ~3;
        dst = TLobby::alloc_heap_slot(floor, 16 + lbl_805D60C0 * 20 + extra + pad);
        if (dst != NULL) {
            hdr[1] = 16;
            hdr[2] = lbl_805D60C0;
            hdr[0] = lbl_805D60C0 * sizeof(SetEntry_80209D34) + 16;
            ((TLobby *)dst)->move_data(hdr, 16);
            if (lbl_805D60C0 > 0) {
                dst += 16;
                ((TLobby *)dst)->move_data(lbl_805D60BC, lbl_805D60C0 * sizeof(SetEntry_80209D34));
            }
            if (extra > 0) {
                dst += lbl_805D60C0 * sizeof(SetEntry_80209D34);
                ((TLobby *)dst)->move_data(lbl_805D60A8 + header.data_offset, extra);
            }
            if (pad > 0) {
                ((TLobby *)(dst + extra))->move_data(lbl_805D60C4, pad);
            }
        }
    }
}
