#include "types.h"
#include "pso/misc/TLobby_801F3A24.h"
#include "pso/misc/TLobby_80207644.h"
#include "pso/misc/TLobby_80207DA8.h"
#include "pso/misc/TLobby_8020A188.h"
#include "pso/system/TGStream.h"
#include "pso/object/TObjMotion.h"
#include "pso/unk/text_801F43A8.h"
#include "pso/unk/text_8020A2AC.h"
#include "pso/unk/text_8020AB50.h"
#include "pso/unk/text_8020AD40.h"
#include "pso/system/byteswap.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TQuestListOnline.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct QuestObjRow_801F3AD8 {
    u8 pad0[2];
    s16 flags;
    u8 pad1[0x40];
};

struct Ent_801F3A80 {
    u16 a;
    s16 b;
    u8 rest[0x44];
};

extern "C" {
void convert_quest_object_rows(struct QuestObjRow_801F3AD8 *rows, u32 byte_size);
extern s16 quest_floor_designations[];
extern s32 TLobby__data_805D5EE0;
s32 read_disc_file(s32, s32);
s32 alloc__22TQuestVmDownLoadServerFUl();
s32 update_lobby_scene__6TSceneFv();

void refresh_quest_list__6TLobbyFi(s32 arg0) {
    s32 temp_r3;

    if (update_lobby_scene__6TSceneFv() >= 0) {
        temp_r3 = alloc__22TQuestVmDownLoadServerFUl();
        if (temp_r3 != 0) {
            read_disc_file(arg0, temp_r3);
            rebuild_all__6TLobbyFi(temp_r3);
            TAdSinglePlyChrSelectGC::safe_free(temp_r3);
        }
    }
}

void TLobby::bswap_enemy_set_rows(u32 arg1) {
    Ent_801F3A80* p = (Ent_801F3A80*)this;
    u32 n = arg1 / sizeof(Ent_801F3A80);
    u32 i;
    for (i = 0; i < n; i++, p++) {
        bswap_enemy_set_row(p);
        p->b = 0;
    }
}

void convert_quest_object_rows(struct QuestObjRow_801F3AD8 *rows, u32 byte_size) {
    struct QuestObjRow_801F3AD8 *p = rows;
    u32 count = byte_size / 68;
    u32 i;
    for (i = 0; i < count; ++i, p++) {
        swap_object_row_endian(p);
        p->flags = 0;
    }
}
void TLobby::init_floor_encounter_sections() {
    s32 i;
    s32 ok;
    for (i = 0; i < 0x12; i++) {
        ok = 0;
        switch (quest_floor_designations[i]) {
        case 0:
            if (TLobby::handle_msg_type2(i) != 0) {
                ok = 1;
            }
            if (ok == 1) {
                load_quest_encounter_section(i);
            }
            break;
        case 1:
        case 2:
        case 3:
            break;
        }
        if (ok == 0) {
            init_buffers__6TLobbyFii(i, TLobby__data_805D5EE0);
        }
    }
}
void TLobby::handle_msg_type1_for_idle_slots() {
    s32 i;
    for (i = 0; i < 0x12; i++) {
        switch (quest_floor_designations[i]) {
        case 0:
            TLobby::handle_msg_type1(i);
            break;
        case 1:
        case 2:
        case 3:
            break;
        }
    }
}

}

struct RecoveredGlobal_801F3DEC_TLobby__data_805127D0 {
    s32 value;
    u8 remaining[0x24];
};

struct Sel_801F3E1C { s32 area; s32 terrain; s32 entities; };

struct RecoveredGlobal_801F3DEC_TLobby__data_805127D0;
extern "C" {
s32 memset(void *, int, int);
extern u8 lbl_80449D08[];
extern u8 lbl_80449D1C[];
extern u8 lbl_80449D30[];
int init_sub_state__6TLobbyFv(void);
int rebuild_entry__6TLobbyFv(void);

    extern short TLobby__data_805D6134;
void rebuild_all__6TLobbyFi(int a0) { TLobby__data_805D5EE0 = a0; TLobby::handle_msg_type1_for_idle_slots(); init_sub_state__6TLobbyFv(); TLobby__sub_8020A2AC(); TLobby::init_floor_encounter_sections(); TLobby::free_boss4rock(); rebuild_entry__6TLobbyFv(); TLobby::init_id_tables(); TLobby__data_805D6134 = 1; TLobby__data_805D5EE0 = 0; }
}
typedef char RecoveredGlobal_801F3DEC_TLobby__data_805127D0_size[sizeof(RecoveredGlobal_801F3DEC_TLobby__data_805127D0) == 0x28 ? 1 : -1];

void set_quest_floor_designation_ex(s16 mode, s32 floor, s32 area, s32 layout, s32 entities) {
    if (floor > 17 || area > 35) {
        return;
    }
    switch (mode) {
    case 0:
        set_floor_map_selection(floor, area, layout, 0);
        ((s16 *) &quest_floor_designations)[floor] = mode;
        break;
    case 2:
        set_floor_map_selection(floor, area, layout, entities);
        ((s16 *) &quest_floor_designations)[floor] = mode;
        break;
    case 1:
    case 3:
        ((s16 *) &quest_floor_designations)[floor] = mode;
        break;
    default:
        return;
    }
}

void set_quest_floor_designation(s16 mode, s32 floor, s32 terrain, s32 unused) {
    if (floor > 17) {
        return;
    }
    switch (mode) {
    case 0:
        set_floor_map_selection(floor, floor, terrain, 0);
        ((s16 *)&quest_floor_designations)[floor] = mode;
        break;
    case 2:
        set_floor_map_selection(floor, floor, terrain, 0);
        ((s16 *)&quest_floor_designations)[floor] = mode;
        break;
    case 1:
    case 3:
        ((s16 *)&quest_floor_designations)[floor] = mode;
        break;
    }
}

void clear_quest_floor_designations(void) {
    memset(&quest_floor_designations, 0, 0x24);
}

void populate_quest_floor_sets(void) {
    s32 i;
    Sel_801F3E1C sel;
    TLobby::init_handle(0x8000);
    for (i = 0; i < 18; i++) {
        switch (((s16 *)&quest_floor_designations)[i]) {
        case 0:
            TLobby::handle_msg_type1(i);
            TLobby::handle_msg_type2(i);
            load_quest_encounter_section(i);
            break;
        case 1:
        case 2:
            if (get_floor_map_selection(i, (u8 *)&sel) == 1 && sel.area >= 0) {
                open_gsl_archive((char *)lbl_80449D08);
                load_area_object_set(i, sel.area, sel.terrain, sel.entities);
                close_gsl_archive();
                open_gsl_archive((char *)lbl_80449D1C);
                load_area_enemy_set(i, sel.area, sel.terrain, sel.entities);
                close_gsl_archive();
                open_gsl_archive((char *)lbl_80449D30);
                load_area_event_set(i, sel.area, sel.terrain, sel.entities);
                close_gsl_archive();
            }
            break;
        case 3:
            break;
        }
    }
    init_sub_state__6TLobbyFv();
    rebuild_entry__6TLobbyFv();
    TLobby::free_data_60F0();
}

bool load_quest_encounter_section(s32 arg0) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    u8 *var_r31;
    var_r31 = (u8 *)((*(u8 * *)&TLobby__data_805D5EE0));
    if (var_r31 != NULL) {
loop_1:
        sp14 = *(s32 *)((s8 *)var_r31 + 0);
        sp10 = *(s32 *)((s8 *)var_r31 + 4);
        spC = *(s32 *)((s8 *)var_r31 + 8);
        sp8 = *(s32 *)((s8 *)var_r31 + 0xC);
        bswap_32((u32 *)&sp14);
        bswap_32((u32 *)&sp10);
        bswap_32((u32 *)&spC);
        bswap_32((u32 *)&sp8);
        if ((sp14 == 3) && (spC == arg0)) {
            return TLobby::add_player(spC, (s32)(var_r31 + 0x10), sp8) != 0;
        }
        if (sp14 != 0) {
            var_r31 += sp10;
            goto loop_1;
        }
        goto block_6;
    }
block_6:
    return 0;
}
extern "C" {

s32 reserve_enemy_set_actor_ids(void *, u32, s32);

s32 TLobby::handle_msg_type2(s32 arg0) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 sp8;
    u8 *lobby;
    u8 *var_r31;

    if ((var_r31 = (u8 *)TLobby__data_805D5EE0) != NULL) {
loop_1:
        sp14 = *(s32 *)((s8 *)var_r31 + 0);
        sp10 = *(s32 *)((s8 *)var_r31 + 4);
        spC = *(s32 *)((s8 *)var_r31 + 8);
        sp8 = *(s32 *)((s8 *)var_r31 + 0xC);
        bswap_32((u32 *)&sp14);
        bswap_32((u32 *)&sp10);
        bswap_32((u32 *)&spC);
        bswap_32((u32 *)&sp8);
        if ((sp14 == 2) && (spC == arg0)) {
            lobby = var_r31 + 0x10;
            ((TLobby *)lobby)->bswap_enemy_set_rows(sp8);
            reserve_enemy_set_actor_ids(lobby, (u32) sp8 / 72U, get_floor_area(spC));
            TLobby::init_floor_enemy_count(spC, lobby, sp8);
            return 1;
        }
        if (sp14 != 0) {
            var_r31 += sp10;
            goto loop_1;
        }
        goto block_6;
    }
block_6:
    return 0;
}

s32 TLobby__sub_8020B308(s32);

s32 TLobby::handle_msg_type1(s32 arg0) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 byte_size;
    u8 *rows;
    u8 *var_r31;

    if ((var_r31 = (u8 *)TLobby__data_805D5EE0) != NULL) {
loop_1:
        sp14 = *(s32 *)((s8 *)var_r31 + 0);
        sp10 = *(s32 *)((s8 *)var_r31 + 4);
        spC = *(s32 *)((s8 *)var_r31 + 8);
        byte_size = *(s32 *)((s8 *)var_r31 + 0xC);
        bswap_32((u32 *)&sp14);
        bswap_32((u32 *)&sp10);
        bswap_32((u32 *)&spC);
        bswap_32((u32 *)&byte_size);
        if ((sp14 == 1) && (spC == arg0)) {
            rows = var_r31 + 0x10;
            convert_quest_object_rows((struct QuestObjRow_801F3AD8 *)rows, byte_size);
            ((TLobby *)rows)->assign_object_ids((s32)((u32) byte_size / 68U), (void *)(get_floor_area(spC)));
            TLobby::load_object_set_entries(spC, rows, byte_size);
            return 1;
        }
        if (sp14 != 0) {
            var_r31 += sp10;
            goto loop_1;
        }
        goto block_6;
    }
block_6:
    return 0;
}

extern s32 evt2_random_enemies_mode;
extern s32 map_set_object_id_counter;
extern s32 TLobby__next_enemy_set_actor_id;
extern s32 map_object_id_counter;
extern s32 map_set_enemy_id_counter;
extern s32 TLobby__data_805D6148;
extern s32 TLobby__data_805D614C;

void TLobby::setup_quest_list() {
    map_set_object_id_counter = 0;
    TLobby__next_enemy_set_actor_id = 0;
    map_object_id_counter = 0;
    map_set_enemy_id_counter = 0;
    switch ((s32) evt2_random_enemies_mode) {
    case 1:
        fn_801F43A8();
        ((void (*)())open_session__6TLobbyFi)();
        break;
    case 2:
        TQuestListOnline::get_quest_list_flag();
        ((void (*)())update_and_reset__6TLobbyFi)();
        break;
    case 3:
        TQuestListVM::get_quest_dat();
        ((void (*)())update_and_reset__6TLobbyFi)();
        break;
    case 4:
        TQuestListOnline::get_quest_list_flag();
        ((void (*)())rebuild_all__6TLobbyFi)();
        break;
    case 5:
        fn_801F43A8();
        ((void (*)())refresh_quest_list__6TLobbyFi)();
        break;
    }
    advance_object_id_counter((u16) map_object_id_counter);
    advance_enemy_id_counter((u16) map_set_enemy_id_counter);
    TLobby__data_805D6148 = map_set_object_id_counter;
    TLobby__data_805D614C = TLobby__next_enemy_set_actor_id;
    TLobby__sub_8020B308(map_set_object_id_counter);
    TLobby::sum_floor_enemy_counts();
}

void update_and_reset__6TLobbyFi(int a0) { TLobby__data_805D5EE0 = a0; populate_quest_floor_sets(); TLobby::init_id_tables(); TLobby__data_805D6134 = 1; TLobby__data_805D5EE0 = 0; }
}

#include "pso/player/TObjPlayer.h"

struct A_801F4340 { s16 a; s16 b; };

struct B_801F4340 { s32 a; s16 b; u8 rest[6]; };

extern B_801F4340* TLobby__data_805D6144;

extern s16 TLobby__data_805D6134;

void open_session__6TLobbyFi(s32 arg0) {
    s32 t;

    if (update_lobby_scene__6TSceneFv() >= 0) {
        t = (TLobby__data_805D5EE0 = alloc__22TQuestVmDownLoadServerFUl());
        if (t != 0) {
            read_disc_file(arg0, t);
            populate_quest_floor_sets();
            TLobby::init_id_tables();
            TLobby__data_805D6134 = 1;
            TAdSinglePlyChrSelectGC::safe_free(TLobby__data_805D5EE0);
            TLobby__data_805D5EE0 = 0;
        }
    }
}
void TLobby::init_id_tables() {
    s32 i;
    s32 n = 0;
    for (i = 0; i < 0xBA0; i++) {
        s16 v = n + 0x100;
        n++;
        quest_object_entries[i].drop_id_base = v;
    }
    for (i = 0; i < 0xB50; i++) {
        s16 v = n + 0x100;
        n++;
        TLobby__data_805D6144[i].b = v;
    }
}
