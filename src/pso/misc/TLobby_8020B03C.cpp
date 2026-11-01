#include "types.h"
#include "pso/unk/text_800F8A0C.h"
#include "pso/misc/TLobby_8020B03C.h"
#include "pso/system/TGStream.h"
#include "pso/unk/text_800F8A18.h"
#include "pso/misc/TLobby.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

extern "C" {

u32 alloc__22TQuestVmDownLoadServerFUl();

extern u32 TLobby__map_set_file_buffer;
extern s32 TLobby__map_set_file_buffer_size;

void TLobby::free_data_60F0() {
    if ((u32) TLobby__map_set_file_buffer != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)TLobby__map_set_file_buffer));
        TLobby__map_set_file_buffer = 0U;
        TLobby__map_set_file_buffer_size = 0;
    }
}

s32 TLobby::init_handle(s32 arg0) {
    u32 temp_r3;

    temp_r3 = alloc__22TQuestVmDownLoadServerFUl();
    TLobby__map_set_file_buffer = temp_r3;
    if (temp_r3 != 0U) {
        TLobby__map_set_file_buffer_size = arg0;
        return 1;
    }
    TLobby__map_set_file_buffer = 0U;
    return 0;
}

s32 strncmp(s32, s32 *, s32);
}
extern s32 map_set_object_id_counter;
extern s32 TLobby__next_enemy_set_actor_id;
extern s32 map_object_id_counter;
extern s32 map_set_enemy_id_counter;
extern s32 lbl_805DC620;
extern s32 lbl_805DC624;

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

struct Entry_8020B260 { s16 a; s16 flags; s16 room; s16 group; };

struct Floor_8020B260 { s32 count; u8 pad[0xC]; struct Entry_8020B260 *entries; u8 pad2[4]; };

struct Ent_8020B1E4 { u8 pad[2]; s16 f2; s16 f4; s16 f6; };

struct Grp_8020B1E4 { u8 pad[4]; s32 count; u8 pad2[0xC]; Ent_8020B1E4 *ents; };

extern RecoveredGlobal_8020B118_lbl_8044BBF0 lbl_8044BBF0;
extern RecoveredGlobal_8020B118_lbl_8044BC04 lbl_8044BC04;
extern s32 map_set_data_handle_a;
extern s32 map_set_data_handle_b;
extern s16 TLobby__data_805D6134;
extern s32 TLobby__data_80513CC8[];
extern s32 TLobby__data_80513C80[];
extern struct Floor_8020B260 TLobby__floor_enemy_group_table[];
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
    Grp_8020B1E4 *g = &((Grp_8020B1E4 *)&TLobby__floor_enemy_group_table)[arg0];
    Ent_8020B1E4 *e;
    s32 n = 0;
    s32 i;
    if (g->count > 0) {
        e = g->ents;
        if (e != 0) {
            for (i = 0; i < g->count; i++, e++) {
                if (e->f4 == arg1 && e->f6 == arg2) {
                    n++;
                    e->f2 |= arg3;
                }
            }
        }
    }
    return n;
}

s32 TLobby::set_room_group_flags(s32 floor, s16 room, s16 group, s32 bits) {
    struct Floor_8020B260 *t = &TLobby__floor_enemy_group_table[floor];
    s32 n = 0;
    struct Entry_8020B260 *e;
    s32 i;
    if (t->count > 0) {
        e = t->entries;
        if (e != NULL) {
            for (i = 0; i < t->count; i++, e++) {
                if (e->room == room && e->group == group) {
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
