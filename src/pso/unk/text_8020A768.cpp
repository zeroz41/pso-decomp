#include "types.h"
#include "pso/misc/TLobby_80131794.h"
#include "pso/misc/TLobby_80207DA8.h"
#include "pso/unk/text_800F8A18.h"
#include "pso/unk/text_801A2514.h"
#include "pso/unk/text_8020A768.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TLobby_80207644.h"
struct Ent_8020A768 { s16 a; s16 b; u8 pad[0x48 - 4]; };

struct Name_8020A768 { char s[0x20]; };

struct Ent_8020A834 { s16 a; s16 b; u8 pad[0x44 - 4]; };

struct Name_8020A834 { char s[0x20]; };

extern "C" {
s32 read_disc_file(Name_8020A768 *, void *);
void reserve_enemy_set_actor_ids(struct SpawnRecord_8020A9C4 *, s32, s32);
void init_floor_enemy_count__6TLobbyFlPUcUl(s32, Ent_8020A768 *, s32);
extern u8 lbl_8044BBA8[];
extern Ent_8020A768 *TLobby__map_set_file_buffer;
extern s32 TLobby__map_set_file_buffer_size;
void load_object_set_entries__6TLobbyFlPUcUl(s32, Ent_8020A834 *, s32);
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
    size = read_disc_file(&name, TLobby__map_set_file_buffer);
    if (size < 0) {
        return 0;
    }
    if (size > TLobby__map_set_file_buffer_size) {
        return 0;
    }
    p = TLobby__map_set_file_buffer;
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
    replace_file_extension__6TLobbyFPvPvPv((char *)((Name_8020A768 *)(&name)), (char *)(arg1), (char *)((const void *)(lbl_8044BBB0)));
    size = read_disc_file((Name_8020A768 *)(&name), (void *)((*(Ent_8020A834 * *)&TLobby__map_set_file_buffer)));
    if (size < 0) {
        return 0;
    }
    if (size > TLobby__map_set_file_buffer_size) {
        return 0;
    }
    p = (*(Ent_8020A834 * *)&TLobby__map_set_file_buffer);
    n = size / sizeof(Ent_8020A834);
    for (i = 0; i < n; i++, p++) {
        swap_object_row_endian(p);
        p->b = 0;
    }
    floor = get_floor_area(idx);
    ((TLobby *)(*(Ent_8020A834 * *)&TLobby__map_set_file_buffer))->assign_object_ids(n, (void *)floor);
    load_object_set_entries__6TLobbyFlPUcUl(idx, (*(Ent_8020A834 * *)&TLobby__map_set_file_buffer), size);
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
void reserve_enemy_set_actor_ids(SpawnRecord_8020A9C4 *arg0, s32 arg1, s32 arg2);
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
