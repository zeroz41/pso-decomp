// ---- pso/unk/text_8020A2AC
#include "types.h"
#include "pso/unk/text_80209584.h"
#include "pso/unk/text_8020A2AC.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

extern "C" {
s32 run_step__9TItemDropFl(int, void *);
s32 __cvt_fp2unsigned(f32);
s32 rand();
extern s32 item_drop_rng;
extern s32 lbl_805D60A4;
extern s32 item_drop_server_seed;
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
#include "types.h"
#include "pso/unk/TLobby_8020A350.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"

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
#include "types.h"
#include "pso/unk/TLobby.h"

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
#include "types.h"
#include "pso/unk/TLobby_8020A568.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"

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
#include "types.h"
#include "pso/unk/text_8020A6B0.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/unk/text_8020A768.h"

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
#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

int rebuild_entry__6TLobbyFv(void);
int init_sub_state__6TLobbyFv(void);

void TLobby::init_sub_objects() { init_sub_state__6TLobbyFv(); rebuild_entry__6TLobbyFv(); }

}

// ---- pso/unk/text_8020A768
#include "types.h"
#include "pso/unk/TLobby_80131794.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/unk/text_800F8A18.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/text_8020A768.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_80207644.h"
struct Ent_8020A768 { s16 a; s16 b; u8 pad[0x48 - 4]; };

struct Name_8020A768 { char s[0x20]; };

struct Ent_8020A834 { s16 a; s16 b; u8 pad[0x44 - 4]; };

struct Name_8020A834 { char s[0x20]; };

extern "C" {
s32 read_disc_file(const char *, void *);
// The callers pass the signed file size as the count.
s32 init_floor_enemy_count__6TLobbyFlPUcUl(s32, u8 *, s32);
s32 load_object_set_entries__6TLobbyFlPUcUl(s32, u8 *, s32);
void reserve_enemy_set_actor_ids(struct SpawnRecord_8020A9C4 *, s32, s32);
extern char lbl_8044BBA8[];
extern u8 *TLobby__map_set_file_buffer;
extern s32 TLobby__map_set_file_buffer_size;
}
extern u8 lbl_8044BBB0[];
s32 load_enemy_set_file(s32 idx, s32 arg1) {
    Name_8020A768 name;
    s32 size;
    Ent_8020A768 *p;
    s32 n;
    s32 i;
    s32 floor;
    replace_file_extension__6TLobbyFPvPvPv((char *)&name, (char *)arg1, (char *)lbl_8044BBA8);
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
    replace_file_extension__6TLobbyFPvPvPv(name.s, (char *)arg1, (char *)lbl_8044BBB0);
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

extern s32 map_set_data_handle_a;
extern s32 map_set_data_handle_b;
extern s32 map_set_object_id_counter;
extern s32 TLobby__next_enemy_set_actor_id;
extern s32 map_object_id_counter;
extern s32 map_set_enemy_id_counter;
extern s16 TLobby__data_805D6134;
extern s32 TLobby__data_805D6148;
extern s32 TLobby__data_805D614C;
extern s32 lbl_805DC620;
extern s32 lbl_805DC624;

void load_map_set_data(s32 idx, s32 arg1) {
    map_set_data_handle_a = 0;
    map_set_data_handle_b = 0;
    map_set_object_id_counter = 0;
    TLobby__next_enemy_set_actor_id = 0;
    map_object_id_counter = 0;
    map_set_enemy_id_counter = 0;
    copy_name((s32)&lbl_805DC620);
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
    copy_name((s32)&lbl_805DC624);
}

struct SpawnRecord_8020A9C4 {
    s16 type;
    u16 flags;
    s16 index;
    s16 children;
    u16 reserved;
    s16 actor_id;
    u8 pad[0x48 - 0xC];
};

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

}

// ---- pso/unk/TLobby_8020AB30
#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

int clear_record_flags_a__6TLobbyFv(void*);

int TLobby::rebuild_entry() { return clear_record_flags_a__6TLobbyFv(this); }

}

// ---- pso/unk/text_8020AB50
#include "types.h"
#include "pso/unk/TLobby_80131794.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/unk/text_8020AB50.h"
#include "pso/unk/TLobby.h"

extern char lbl_8044BBB8[];
extern char lbl_8044BBC8[];
extern char lbl_8044BBD4[];
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
        TLobby::debug_print(lbl_8044BBB8);
        return 0;
    }
    t3 = t2[arg2].entries;
    if (t3 == NULL || t2[arg2].count - 1 < arg3) {
        TLobby::debug_print(lbl_8044BBB8);
        return 0;
    }
    name = t3[arg3].enemy_set_name;
    if (arg1 == 0 || arg1 == 0x12) {
        switch (get_game_play_mode()) {
        case 0:
            replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)name, (char *)lbl_8044BBA8);
            break;
        case 1:
            replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)name, (char *)lbl_8044BBC8);
            break;
        case 2:
            replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)name, (char *)lbl_8044BBD4);
            break;
        }
    } else {
        replace_file_extension__6TLobbyFPvPvPv((char *)buf, (char *)name, (char *)lbl_8044BBA8);
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
#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {

int clear_record_flags_b__6TLobbyFv(void*);

int TLobby::init_sub_state() { return clear_record_flags_b__6TLobbyFv(this); }

}

// ---- pso/unk/text_8020AD40
#include "types.h"
#include "pso/unk/TLobby_80131794.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/unk/TLobby_8020B03C.h"
#include "pso/unk/TLobby_8030A6A8.h"
#include "pso/unk/text_8020AD40.h"
#include "pso/unk/TLobby.h"

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
void advance_enemy_id_counter(s32 arg0);
s32 load_area_enemy_set(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void advance_object_id_counter(s32 arg0);
extern u8 lbl_8044BBB0[];
extern char lbl_8044BBB8[];
extern u8 lbl_8044BBDC[];
extern u8 lbl_8044BBE8[];

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
        TLobby::debug_print(lbl_8044BBB8);
        return 0;
    }
    items = subs[arg2].entries;
    if (items == NULL || subs[arg2].count - 1 < arg3) {
        TLobby::debug_print(lbl_8044BBB8);
        return 0;
    }
    id = items[arg3].object_set_name;
    if (lobby == 0 || lobby == 0x12) {
        switch (get_game_play_mode()) {
        case 0:
            replace_file_extension__6TLobbyFPvPvPv((char *)name, (char *)id, (char *)lbl_8044BBB0);
            break;
        case 1:
            replace_file_extension__6TLobbyFPvPvPv((char *)name, (char *)id, (char *)lbl_8044BBDC);
            break;
        case 2:
            replace_file_extension__6TLobbyFPvPvPv((char *)name, (char *)id, (char *)lbl_8044BBE8);
            break;
        }
    } else {
        replace_file_extension__6TLobbyFPvPvPv((char *)name, (char *)id, (char *)lbl_8044BBB0);
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
#include "types.h"
#include "pso/unk/text_800F8A0C.h"
#include "pso/unk/TLobby_8020B03C.h"
#include "pso/system/TGStream.h"
#include "pso/unk/text_800F8A18.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

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

s32 strncmp(s32, s32 *, s32);
}

void clear_map_set_data(void) {
    map_set_object_id_counter = 0;
    TLobby__next_enemy_set_actor_id = 0;
    map_object_id_counter = 0;
    map_set_enemy_id_counter = 0;
    TLobby__map_set_file_buffer_size = 0;
    s32 temp_r3 = (s32)get_player_name_copy_buffer();
    if (strncmp(temp_r3, &lbl_805DC620, 0x10) == 0) {
        copy_name((s32)&lbl_805DC624);
    }
}

struct RecoveredGlobal_8020B118_lbl_8044BBF0 { char value[0x13]; };
typedef char RecoveredGlobal_8020B118_lbl_8044BBF0_size[sizeof(RecoveredGlobal_8020B118_lbl_8044BBF0) == 0x13 ? 1 : -1];

struct RecoveredGlobal_8020B118_lbl_8044BC04 { char value[0x12]; };
typedef char RecoveredGlobal_8020B118_lbl_8044BC04_size[sizeof(RecoveredGlobal_8020B118_lbl_8044BC04) == 0x12 ? 1 : -1];

// Saved set-flag row of a floor's object or enemy list.
struct SetFlagRow_8020B47C {
    u16 id;
    s16 flags;
    s16 room;
    s16 wave;
};

// One floor of TLobby__floor_enemy_group_table (owned by text_8020E08C).
struct FloorSetFlags_8020B47C {
    s32 object_count;
    s32 enemy_count;
    u32 object_placement;
    u32 enemy_placement;
    SetFlagRow_8020B47C *object_rows;
    SetFlagRow_8020B47C *enemy_rows;
};

extern RecoveredGlobal_8020B118_lbl_8044BBF0 lbl_8044BBF0;
extern RecoveredGlobal_8020B118_lbl_8044BC04 lbl_8044BC04;
extern "C" {
// Per-floor enemy and object row counts (written by init_floor_enemy_count and load_object_set_entries).
extern s32 TLobby__data_80513CC8[];
extern s32 TLobby__data_80513C80[];
extern FloorSetFlags_8020B47C TLobby__floor_enemy_group_table[18];
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
        open_gsl_archive((char *)&lbl_8044BBF0.value);
        if (TLobby::load_all_floor_object_sets() == 0) {
            close_gsl_archive();
            TLobby::free_data_60F0();
            TLobby__data_805D6134 |= 1;
            return;
        }
        close_gsl_archive();
        open_gsl_archive((char *)&lbl_8044BC04.value);
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
    FloorSetFlags_8020B47C *g = &TLobby__floor_enemy_group_table[arg0];
    SetFlagRow_8020B47C *e;
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
    FloorSetFlags_8020B47C *t = &TLobby__floor_enemy_group_table[floor];
    s32 n = 0;
    SetFlagRow_8020B47C *e;
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
#include "types.h"
#include "pso/unk/TLobby_8020B334.h"
#include "pso/unk/TLobby.h"

extern "C" {

int get_matching_object__6TLobbyFv(void*);
int get_object_count__6TLobbyFv(void*);

int TLobby::resolve_matching_object() { return get_matching_object__6TLobbyFv(this); }
int get_object_count__6TLobbyFPv(void* p) { return get_object_count__6TLobbyFv(p); }

}

// ---- pso/unk/text_8020B374
#include "types.h"
#include "pso/unk/TLobby.h"

extern "C" {
s32 load_floor_enemy_group_entries__6TLobbyFiPvUi(s32, void *, u32);
s32 init_quest_floor_enemies(s32, void *, u32);
s32 TLobby::init_floor_enemy_count(s32 arg0, u8 *arg1, u32 arg2) {
    if (init_quest_floor_enemies(arg0, arg1, arg2) == 1) {
        TLobby__data_80513CC8[arg0] = arg2 / 72U;
        return 1;
    }
    TLobby__data_80513CC8[arg0] = -1;
    return 0;
}

s32 TLobby::load_object_set_entries(s32 arg0, u8 *arg1, u32 arg2) {
    if (load_floor_enemy_group_entries__6TLobbyFiPvUi(arg0, arg1, arg2) == 1) {
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
#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/system/byteswap.h"

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
    SetFlagRow_8020B47C *row;
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
#include "types.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"

void TLobby::bswap_4_words() { bswap_32((u32 *)this); bswap_32((u32 *)((char*)this + 0x4)); bswap_32((u32 *)((char*)this + 0x8)); bswap_32((u32 *)((char*)this + 0xc)); }
