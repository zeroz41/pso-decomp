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
#include "pso/network/TLobby.h"
#include "pso/quest/TQuestListOnline.h"
#include "pso/quest/TQuestListVM.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/map/TSetManager.h"
#include "pso/unk/TLobby_80209524.h"



void convert_quest_object_rows(struct ConvertQuestObjectRowsQuestObjRow *rows, u32 byte_size);
extern "C" {
extern s16 quest_floor_designations[];
u8 *quest_dat_buffer;
}

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
    BswapEnemySetRowsEntry* p = (BswapEnemySetRowsEntry*)this;
    u32 n = size / sizeof(BswapEnemySetRowsEntry);
    u32 i;
    for (i = 0; i < n; i++, p++) {
        bswap_enemy_set_row(p);
        p->b = 0;
    }
}

void convert_quest_object_rows(struct ConvertQuestObjectRowsQuestObjRow *rows, u32 byte_size) {
    struct ConvertQuestObjectRowsQuestObjRow *p = rows;
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
            TLobby::init_buffers(i, quest_dat_buffer);
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


void TLobby::rebuild_all(u8 *quest) {
    quest_dat_buffer = quest;
    TLobby::handle_msg_type1_for_idle_slots();
    TLobby::init_sub_state();
    init_item_drop_rng();
    TLobby::init_floor_encounter_sections();
    TLobby::free_boss4rock();
    TLobby::rebuild_entry();
    TLobby::init_id_tables();
    floor_set_flags = 1;
    quest_dat_buffer = NULL;
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

bool load_quest_encounter_section(s32 floor) {
    s32 type;
    s32 next_offset;
    s32 record_floor;
    s32 size;
    QuestDatRecord *record;
    if ((record = (QuestDatRecord *)quest_dat_buffer) != NULL) {
        do {
            type = record->type;
            next_offset = record->next_offset;
            record_floor = record->floor;
            size = record->size;
            bswap_32((u32 *)&type);
            bswap_32((u32 *)&next_offset);
            bswap_32((u32 *)&record_floor);
            bswap_32((u32 *)&size);
            if ((type == 3) && (record_floor == floor)) {
                return TLobby::add_player(record_floor, (saddr)(record + 1), size) != 0;
            }
            if (type == 0) {
                break;
            }
            record = (QuestDatRecord *)((u8 *)record + next_offset);
        } while (1);
    }
    return 0;
}
extern "C" {

s32 reserve_enemy_set_actor_ids(void *, u32, s32);

s32 TLobby::handle_msg_type2(s32 floor) {
    s32 type;
    s32 next_offset;
    s32 record_floor;
    s32 size;
    u8 *lobby;
    QuestDatRecord *record;

    if ((record = (QuestDatRecord *)quest_dat_buffer) != NULL) {
        do {
            type = record->type;
            next_offset = record->next_offset;
            record_floor = record->floor;
            size = record->size;
            bswap_32((u32 *)&type);
            bswap_32((u32 *)&next_offset);
            bswap_32((u32 *)&record_floor);
            bswap_32((u32 *)&size);
            if ((type == 2) && (record_floor == floor)) {
                lobby = (u8 *)(record + 1);
                ((TLobby *)lobby)->bswap_enemy_set_rows(size);
                reserve_enemy_set_actor_ids(lobby, (u32) size / 72U, get_floor_area(record_floor));
                TLobby::init_floor_enemy_count(record_floor, lobby, size);
                return 1;
            }
            if (type == 0) {
                break;
            }
            record = (QuestDatRecord *)((u8 *)record + next_offset);
        } while (1);
    }
    return 0;
}


s32 TLobby::handle_msg_type1(s32 floor) {
    s32 type;
    s32 next_offset;
    s32 record_floor;
    s32 byte_size;
    u8 *rows;
    QuestDatRecord *record;

    if ((record = (QuestDatRecord *)quest_dat_buffer) != NULL) {
        do {
            type = record->type;
            next_offset = record->next_offset;
            record_floor = record->floor;
            byte_size = record->size;
            bswap_32((u32 *)&type);
            bswap_32((u32 *)&next_offset);
            bswap_32((u32 *)&record_floor);
            bswap_32((u32 *)&byte_size);
            if ((type == 1) && (record_floor == floor)) {
                rows = (u8 *)(record + 1);
                convert_quest_object_rows((struct ConvertQuestObjectRowsQuestObjRow *)rows, byte_size);
                assign_object_ids((FloorObjectSetRow *)rows, (s32)((u32) byte_size / 68U), get_floor_area(record_floor));
                TLobby::load_object_set_entries(record_floor, rows, byte_size);
                return 1;
            }
            if (type == 0) {
                break;
            }
            record = (QuestDatRecord *)((u8 *)record + next_offset);
        } while (1);
    }
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
        TLobby::open_session(get_offline_quest_filename_buffer_b());
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
        TLobby::refresh_quest_list(get_offline_quest_filename_buffer_b());
        break;
    }
    advance_object_id_counter((u16) map_object_id_counter);
    advance_enemy_id_counter((u16) map_set_enemy_id_counter);
    object_condition_count = map_set_object_id_counter;
    enemy_condition_count = next_enemy_set_actor_id;
    get_total_object_set_count();
    TLobby::sum_floor_enemy_counts();
}

}

void TLobby::update_and_reset(u8 *quest) {
    quest_dat_buffer = quest;
    populate_quest_floor_sets();
    TLobby::init_id_tables();
    floor_set_flags = 1;
    quest_dat_buffer = NULL;
}

#include "pso/player/TObjPlayer.h"


void TLobby::open_session(const char *path) {
    u8 *quest;
    s32 size;

    size = get_resource_file_size(path);
    if (size >= 0) {
        quest = (quest_dat_buffer = (u8 *)TQuestVmDownLoadServer::alloc(size));
        if (quest != NULL) {
            read_disc_file(path, quest);
            populate_quest_floor_sets();
            TLobby::init_id_tables();
            floor_set_flags = 1;
            safe_free(quest_dat_buffer);
            quest_dat_buffer = NULL;
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
        enemy_state_records[i].drop_id = v;
    }
}

s16 quest_floor_designations[0x14];
