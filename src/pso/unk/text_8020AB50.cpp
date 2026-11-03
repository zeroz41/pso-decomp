#include "types.h"
#include "pso/misc/TLobby_80131794.h"
#include "pso/misc/TLobby_80207DA8.h"
#include "pso/misc/TLobby_8030A6A8.h"
#include "pso/unk/text_8020AB50.h"
#include "pso/misc/TLobby.h"

struct E3_8020AB50 { s32 a; s32 name; s32 c; };

struct E2_8020AB50 { E3_8020AB50 *recs; s32 count; };

struct E1_8020AB50 { E2_8020AB50 *recs; s32 count; };

extern "C" {
s32 read_disc_file(void *, void *);
s32 reserve_enemy_set_actor_ids(void *, u32, s32);
s32 init_floor_enemy_count__6TLobbyFlPUcUl(s32, void *, s32);
}
extern char lbl_8044BBA8[];
extern char lbl_8044BBB8[];
extern char lbl_8044BBC8[];
extern char lbl_8044BBD4[];
extern E1_8020AB50 *TLobby__data_805D6068;
extern u8 *TLobby__map_set_file_buffer;
extern s32 TLobby__map_set_file_buffer_size;
s32 load_area_enemy_set(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    char buf[0x28];
    s32 name;
    s32 size;
    u8 *p;
    u32 count;
    s32 i;
    E2_8020AB50 *t2;
    E3_8020AB50 *t3;
    t2 = TLobby__data_805D6068[arg1].recs;
    if (t2 == NULL || TLobby__data_805D6068[arg1].count - 1 < arg2) {
        TLobby::debug_print(lbl_8044BBB8);
        return 0;
    }
    t3 = t2[arg2].recs;
    if (t3 == NULL || t2[arg2].count - 1 < arg3) {
        TLobby::debug_print(lbl_8044BBB8);
        return 0;
    }
    name = t3[arg3].name;
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
    for (i = 0; i < (s32)count; i++, p += 0x48) {
        bswap_enemy_set_row(p);
        *(s16 *)(p + 2) = 0;
    }
    reserve_enemy_set_actor_ids(TLobby__map_set_file_buffer, count, arg1);
    init_floor_enemy_count__6TLobbyFlPUcUl(arg0, TLobby__map_set_file_buffer, size);
    return 1;
}
