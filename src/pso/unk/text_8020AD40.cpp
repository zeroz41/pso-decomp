#include "types.h"
#include "pso/misc/TLobby_80131794.h"
#include "pso/misc/TLobby_80207DA8.h"
#include "pso/misc/TLobby_8020B03C.h"
#include "pso/misc/TLobby_8030A6A8.h"
#include "pso/unk/text_8020AD40.h"
#include "pso/misc/TLobby.h"

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

struct Item_8020AD40 { s32 id; u8 pad[8]; };

struct Sub_8020AD40 { Item_8020AD40 *items; s32 count; };

struct Grp_8020AD40 { Sub_8020AD40 *subs; s32 count; };

struct Rec_8020AD40 { u8 pad0[2]; s16 f2; u8 pad4[0x40]; };

extern "C" {
s32 is_area_transfer_pending();
s32 get_floor_map_selection(int, void *);
s32 read_disc_file(void *, Rec_8020AD40 *);
void load_object_set_entries__6TLobbyFlPUcUl(s32, Rec_8020AD40 *, s32);
}
void advance_enemy_id_counter(s32 arg0);
s32 load_area_enemy_set(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 TLobby__next_enemy_set_actor_id;
extern s32 map_set_enemy_id_counter;
extern s32 TLobby__data_805D614C;
void advance_object_id_counter(s32 arg0);
extern s32 map_set_object_id_counter;
extern s32 map_object_id_counter;
extern s32 TLobby__data_805D6148;
extern u8 lbl_8044BBB0[];
extern char lbl_8044BBB8[];
extern u8 lbl_8044BBDC[];
extern u8 lbl_8044BBE8[];
extern Grp_8020AD40 *TLobby__data_805D6068;
extern Rec_8020AD40 *TLobby__map_set_file_buffer;
extern s32 TLobby__map_set_file_buffer_size;

s32 load_area_object_set(s32 arg0, s32 lobby, s32 arg2, s32 arg3) {
    char name[0x20];
    Sub_8020AD40 *subs;
    Item_8020AD40 *items;
    s32 id;
    s32 len;
    Rec_8020AD40 *r;
    s32 n;
    s32 i;
    subs = TLobby__data_805D6068[lobby].subs;
    if (subs == NULL || TLobby__data_805D6068[lobby].count - 1 < arg2) {
        TLobby::debug_print(lbl_8044BBB8);
        return 0;
    }
    items = subs[arg2].items;
    if (items == NULL || subs[arg2].count - 1 < arg3) {
        TLobby::debug_print(lbl_8044BBB8);
        return 0;
    }
    id = items[arg3].id;
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
    r = TLobby__map_set_file_buffer;
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
    if ((get_floor_map_selection(var_r31, &stack.sp8) == 1) && (stack.sp8 >= 0)) {
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
    if ((get_floor_map_selection(var_r31, &stack.sp8) == 1) && (stack.sp8 >= 0)) {
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
