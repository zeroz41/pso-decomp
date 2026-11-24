#include "pso/enemy/EnemyStateRecord.h"
#include "pso/system/memory.h"
#include <string.h>
#include "pso/system/ResourceFile.h"
#include "types.h"
#include "pso/unk/TLobby_801F3A24.h"
#include "pso/map/FloorPopulation.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/system/TGStream.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/text_801F43A8.h"
#include "pso/unk/text_8020A2AC.h"
#include "pso/unk/text_8020AB50.h"
#include "pso/unk/text_8020AD40.h"
#include "pso/system/byteswap.h"
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/TSetManager.h"
#include "pso/unk/TLobby_80209524.h"

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
u8 *TLobby__data_805D5EE0;

void TLobby::refresh_quest_list(const char *path) {
    u8 *quest;
    s32 size;

    size = get_resource_file_size(path);
    if (size >= 0) {
        quest = (u8 *)TQuestVmDownLoadServer::alloc(size);
        if (quest != NULL) {
            read_disc_file(path, quest);
            TLobby::rebuild_all(quest);
            safe_free(quest);
        }
    }
}

void TLobby::bswap_enemy_set_rows(u32 size) {
    Ent_801F3A80* p = (Ent_801F3A80*)this;
    u32 n = size / sizeof(Ent_801F3A80);
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
            TLobby::init_buffers(i, TLobby__data_805D5EE0);
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


void TLobby::rebuild_all(u8 *quest) {
    TLobby__data_805D5EE0 = quest;
    TLobby::handle_msg_type1_for_idle_slots();
    TLobby::init_sub_state();
    TLobby__sub_8020A2AC();
    TLobby::init_floor_encounter_sections();
    TLobby::free_boss4rock();
    TLobby::rebuild_entry();
    TLobby::init_id_tables();
    floor_set_flags = 1;
    TLobby__data_805D5EE0 = NULL;
}

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
    FloorMapSelection sel;
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
            if (get_floor_map_selection(i, &sel) == 1 && sel.area >= 0) {
                open_gsl_archive("gsl_set_object.gsl");
                load_area_object_set(i, sel.area, sel.terrain, sel.entities);
                close_gsl_archive();
                open_gsl_archive("gsl_set_enemy.gsl");
                load_area_enemy_set(i, sel.area, sel.terrain, sel.entities);
                close_gsl_archive();
                open_gsl_archive("gsl_set_event.gsl");
                load_area_event_set(i, sel.area, sel.terrain, sel.entities);
                close_gsl_archive();
            }
            break;
        case 3:
            break;
        }
    }
    TLobby::init_sub_state();
    TLobby::rebuild_entry();
    TLobby::free_data_60F0();
}

bool load_quest_encounter_section(s32 arg0) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 size;
    u8 *var_r31;
    if ((var_r31 = TLobby__data_805D5EE0) != NULL) {
loop_1:
        sp14 = *(s32 *)((s8 *)var_r31 + 0);
        sp10 = *(s32 *)((s8 *)var_r31 + 4);
        spC = *(s32 *)((s8 *)var_r31 + 8);
        size = *(s32 *)((s8 *)var_r31 + 0xC);
        bswap_32((u32 *)&sp14);
        bswap_32((u32 *)&sp10);
        bswap_32((u32 *)&spC);
        bswap_32((u32 *)&size);
        if ((sp14 == 3) && (spC == arg0)) {
            return TLobby::add_player(spC, (saddr)(var_r31 + 0x10), size) != 0;
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
    s32 size;
    u8 *lobby;
    u8 *var_r31;

    if ((var_r31 = TLobby__data_805D5EE0) != NULL) {
loop_1:
        sp14 = *(s32 *)((s8 *)var_r31 + 0);
        sp10 = *(s32 *)((s8 *)var_r31 + 4);
        spC = *(s32 *)((s8 *)var_r31 + 8);
        size = *(s32 *)((s8 *)var_r31 + 0xC);
        bswap_32((u32 *)&sp14);
        bswap_32((u32 *)&sp10);
        bswap_32((u32 *)&spC);
        bswap_32((u32 *)&size);
        if ((sp14 == 2) && (spC == arg0)) {
            lobby = var_r31 + 0x10;
            ((TLobby *)lobby)->bswap_enemy_set_rows(size);
            reserve_enemy_set_actor_ids(lobby, (u32) size / 72U, get_floor_area(spC));
            TLobby::init_floor_enemy_count(spC, lobby, size);
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


s32 TLobby::handle_msg_type1(s32 arg0) {
    s32 sp14;
    s32 sp10;
    s32 spC;
    s32 byte_size;
    u8 *rows;
    u8 *var_r31;

    if ((var_r31 = TLobby__data_805D5EE0) != NULL) {
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

void TLobby::setup_quest_list() {
    map_set_object_id_counter = 0;
    next_enemy_set_actor_id = 0;
    map_object_id_counter = 0;
    map_set_enemy_id_counter = 0;
    switch ((s32) evt2_random_enemies_mode) {
    case 1:
        TLobby::open_session(fn_801F43A8());
        break;
    case 2:
        TLobby::update_and_reset(TQuestListOnline::get_quest_list_flag());
        break;
    case 3:
        TLobby::update_and_reset(TQuestListVM::get_quest_dat());
        break;
    case 4:
        TLobby::rebuild_all(TQuestListOnline::get_quest_list_flag());
        break;
    case 5:
        TLobby::refresh_quest_list(fn_801F43A8());
        break;
    }
    advance_object_id_counter((u16) map_object_id_counter);
    advance_enemy_id_counter((u16) map_set_enemy_id_counter);
    object_condition_count = map_set_object_id_counter;
    enemy_condition_count = next_enemy_set_actor_id;
    TLobby__sub_8020B308();
    TLobby::sum_floor_enemy_counts();
}

}

void TLobby::update_and_reset(u8 *quest) {
    TLobby__data_805D5EE0 = quest;
    populate_quest_floor_sets();
    TLobby::init_id_tables();
    floor_set_flags = 1;
    TLobby__data_805D5EE0 = NULL;
}

#include "pso/player/TObjPlayer.h"


void TLobby::open_session(const char *path) {
    u8 *quest;
    s32 size;

    size = get_resource_file_size(path);
    if (size >= 0) {
        quest = (TLobby__data_805D5EE0 = (u8 *)TQuestVmDownLoadServer::alloc(size));
        if (quest != NULL) {
            read_disc_file(path, quest);
            populate_quest_floor_sets();
            TLobby::init_id_tables();
            floor_set_flags = 1;
            safe_free(TLobby__data_805D5EE0);
            TLobby__data_805D5EE0 = NULL;
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
        TLobby__data_805D6144[i].drop_id = v;
    }
}

s16 quest_floor_designations[0x14];
