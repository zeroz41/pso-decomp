#include "pso/system/memory.h"
#include "pso/map/FloorPopulation.h"
#include "pso/unk/TLobby_80207644.h"
#include "pso/map/MapSetArchive.h"
#include "pso/network/FloorEventCommand.h"
#include "pso/system/ResourceFile.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_80207DA8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/map/FloorLifecycleTables.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/system/THeap.h"
#include "pso/network/TLobby.h"
#include "pso/map/AreaEventSet.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/unk/FloorMapNames.h"
#include "pso/system/task/TObject.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/ui/keyboard/SystemBootInit.h"
#include "pso/system/byteswap.h"
#include <string.h>
#include "pso/unk/TLobby_800F8AA8.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/network/client_id.h"


extern "C" {
__declspec(section ".data") const char *floor_map_set_city00[2] = { floor_map_name_city00, floor_map_name_city00_00 };
__declspec(section ".data") const char *floor_map_set_forest01[2] = { floor_map_name_forest01, floor_map_name_forest01 };
__declspec(section ".data") const char *floor_map_set_forest02[2] = { floor_map_name_forest02, floor_map_name_forest02 };
const char *floor_map_set_cave01[12] = { floor_map_name_cave01, floor_map_name_cave01_00, floor_map_name_cave01, floor_map_name_cave01_01, floor_map_name_cave01, floor_map_name_cave01_02, floor_map_name_cave01, floor_map_name_cave01_03, floor_map_name_cave01, floor_map_name_cave01_04, floor_map_name_cave01, floor_map_name_cave01_05 };
const char *floor_map_set_cave02[10] = { floor_map_name_cave02, floor_map_name_cave02_00, floor_map_name_cave02, floor_map_name_cave02_01, floor_map_name_cave02, floor_map_name_cave02_02, floor_map_name_cave02, floor_map_name_cave02_03, floor_map_name_cave02, floor_map_name_cave02_04 };
const char *floor_map_set_cave03[12] = { floor_map_name_cave03, floor_map_name_cave03_00, floor_map_name_cave03, floor_map_name_cave03_01, floor_map_name_cave03, floor_map_name_cave03_02, floor_map_name_cave03, floor_map_name_cave03_03, floor_map_name_cave03, floor_map_name_cave03_04, floor_map_name_cave03, floor_map_name_cave03_05 };
const char *floor_map_set_machine01[12] = { floor_map_name_machine01, floor_map_name_machine01_00, floor_map_name_machine01, floor_map_name_machine01_01, floor_map_name_machine01, floor_map_name_machine01_02, floor_map_name_machine01, floor_map_name_machine01_03, floor_map_name_machine01, floor_map_name_machine01_04, floor_map_name_machine01, floor_map_name_machine01_05 };
const char *floor_map_set_machine02[12] = { floor_map_name_machine02, floor_map_name_machine02_00, floor_map_name_machine02, floor_map_name_machine02_01, floor_map_name_machine02, floor_map_name_machine02_02, floor_map_name_machine02, floor_map_name_machine02_03, floor_map_name_machine02, floor_map_name_machine02_04, floor_map_name_machine02, floor_map_name_machine02_05 };
const char *floor_map_set_ancient01[10] = { floor_map_name_ancient01, floor_map_name_ancient01_00, floor_map_name_ancient01, floor_map_name_ancient01_01, floor_map_name_ancient01, floor_map_name_ancient01_02, floor_map_name_ancient01, floor_map_name_ancient01_03, floor_map_name_ancient01, floor_map_name_ancient01_04 };
const char *floor_map_set_ancient02[10] = { floor_map_name_ancient02, floor_map_name_ancient02_00, floor_map_name_ancient02, floor_map_name_ancient02_01, floor_map_name_ancient02, floor_map_name_ancient02_02, floor_map_name_ancient02, floor_map_name_ancient02_03, floor_map_name_ancient02, floor_map_name_ancient02_04 };
const char *floor_map_set_ancient03[10] = { floor_map_name_ancient03, floor_map_name_ancient03_00, floor_map_name_ancient03, floor_map_name_ancient03_01, floor_map_name_ancient03, floor_map_name_ancient03_02, floor_map_name_ancient03, floor_map_name_ancient03_03, floor_map_name_ancient03, floor_map_name_ancient03_04 };
__declspec(section ".data") const char *floor_map_set_boss01[2] = { floor_map_name_boss01, floor_map_name_boss01 };
__declspec(section ".data") const char *floor_map_set_boss02[2] = { floor_map_name_boss02, floor_map_name_boss02 };
__declspec(section ".data") const char *floor_map_set_boss03[2] = { floor_map_name_boss03, floor_map_name_boss03 };
__declspec(section ".data") const char *floor_map_set_darkfalz00[2] = { floor_map_name_darkfalz00, floor_map_name_darkfalz00 };
const char *floor_map_set_lobby_01[30] = { floor_map_name_lobby_01, floor_map_name_lobby_01, floor_map_name_lobby_02, floor_map_name_lobby_02, floor_map_name_lobby_03, floor_map_name_lobby_03, floor_map_name_lobby_04, floor_map_name_lobby_04, floor_map_name_lobby_05, floor_map_name_lobby_05, floor_map_name_lobby_06, floor_map_name_lobby_06, floor_map_name_lobby_07, floor_map_name_lobby_07, floor_map_name_lobby_08, floor_map_name_lobby_08, floor_map_name_lobby_09, floor_map_name_lobby_09, floor_map_name_lobby_10, floor_map_name_lobby_10, floor_map_name_lobby_red_be00, floor_map_name_lobby_red_be00, floor_map_name_lobby_yellow_be00, floor_map_name_lobby_yellow_be00, floor_map_name_lobby_green_be00, floor_map_name_lobby_green_be00, floor_map_name_soccer11, floor_map_name_soccer11, floor_map_name_soccer12, floor_map_name_soccer12 };
const char *floor_map_set_vs01[6] = { floor_map_name_vs01, floor_map_name_vs01_00, floor_map_name_vs01, floor_map_name_vs01_01, floor_map_name_vs01, floor_map_name_vs01_02 };
const char *floor_map_set_vs02[6] = { floor_map_name_vs02, floor_map_name_vs02_00, floor_map_name_vs02, floor_map_name_vs02_01, floor_map_name_vs02, floor_map_name_vs02_02 };
__declspec(section ".data") const char *floor_map_set_labo00[2] = { floor_map_name_labo00, floor_map_name_labo00_00 };
const char *floor_map_set_space01[6] = { floor_map_name_space01, floor_map_name_space01_00, floor_map_name_space01, floor_map_name_space01_01, floor_map_name_space01, floor_map_name_space01_02 };
const char *floor_map_set_space02[6] = { floor_map_name_space02, floor_map_name_space02_00, floor_map_name_space02, floor_map_name_space02_01, floor_map_name_space02, floor_map_name_space02_02 };
const char *floor_map_set_ruins01[6] = { floor_map_name_ruins01, floor_map_name_ruins01_00, floor_map_name_ruins01, floor_map_name_ruins01_01, floor_map_name_ruins01, floor_map_name_ruins01_02 };
const char *floor_map_set_ruins02[6] = { floor_map_name_ruins02, floor_map_name_ruins02_00, floor_map_name_ruins02, floor_map_name_ruins02_01, floor_map_name_ruins02, floor_map_name_ruins02_02 };
__declspec(section ".data") const char *floor_map_set_jungle01[2] = { floor_map_name_jungle01, floor_map_name_jungle01_00 };
__declspec(section ".data") const char *floor_map_set_jungle02[2] = { floor_map_name_jungle02, floor_map_name_jungle02_00 };
__declspec(section ".data") const char *floor_map_set_jungle03[2] = { floor_map_name_jungle03, floor_map_name_jungle03_00 };
const char *floor_map_set_jungle04[6] = { floor_map_name_jungle04, floor_map_name_jungle04_00, floor_map_name_jungle04, floor_map_name_jungle04_01, floor_map_name_jungle04, floor_map_name_jungle04_02 };
__declspec(section ".data") const char *floor_map_set_jungle05[2] = { floor_map_name_jungle05, floor_map_name_jungle05_00 };
__declspec(section ".data") const char *floor_map_set_jungle06[2] = { floor_map_name_jungle06, floor_map_name_jungle06_00 };
const char *floor_map_set_jungle07[10] = { floor_map_name_jungle07, floor_map_name_jungle07_00, floor_map_name_jungle07, floor_map_name_jungle07_01, floor_map_name_jungle07, floor_map_name_jungle07_02, floor_map_name_jungle07, floor_map_name_jungle07_03, floor_map_name_jungle07, floor_map_name_jungle07_04 };
const char *floor_map_set_seabed01[6] = { floor_map_name_seabed01, floor_map_name_seabed01_00, floor_map_name_seabed01, floor_map_name_seabed01_01, floor_map_name_seabed01, floor_map_name_seabed01_02 };
const char *floor_map_set_seabed02[6] = { floor_map_name_seabed02, floor_map_name_seabed02_00, floor_map_name_seabed02, floor_map_name_seabed02_01, floor_map_name_seabed02, floor_map_name_seabed02_02 };
__declspec(section ".data") const char *floor_map_set_boss05[2] = { floor_map_name_boss05, floor_map_name_boss05 };
__declspec(section ".data") const char *floor_map_set_boss06[2] = { floor_map_name_boss06, floor_map_name_boss06 };
__declspec(section ".data") const char *floor_map_set_boss07[2] = { floor_map_name_boss07, floor_map_name_boss07 };
__declspec(section ".data") const char *floor_map_set_boss08[2] = { floor_map_name_boss08, floor_map_name_boss08 };
/* {name list, entry count} per floor (inferred) */
FloorSceneEntry offline_floor_scene_table[36] = { { floor_map_set_city00, 1 }, { floor_map_set_forest01, 1 }, { floor_map_set_forest02, 1 }, { floor_map_set_cave01, 6 }, { floor_map_set_cave02, 5 }, { floor_map_set_cave03, 6 }, { floor_map_set_machine01, 6 }, { floor_map_set_machine02, 6 }, { floor_map_set_ancient01, 5 }, { floor_map_set_ancient02, 5 }, { floor_map_set_ancient03, 5 }, { floor_map_set_boss01, 1 }, { floor_map_set_boss02, 1 }, { floor_map_set_boss03, 1 }, { floor_map_set_darkfalz00, 1 }, { floor_map_set_lobby_01, 15 }, { floor_map_set_vs01, 3 }, { floor_map_set_vs02, 3 }, { floor_map_set_labo00, 1 }, { floor_map_set_ruins01, 3 }, { floor_map_set_ruins02, 3 }, { floor_map_set_space01, 3 }, { floor_map_set_space02, 3 }, { floor_map_set_jungle01, 1 }, { floor_map_set_jungle02, 1 }, { floor_map_set_jungle03, 1 }, { floor_map_set_jungle04, 3 }, { floor_map_set_jungle05, 1 }, { floor_map_set_seabed01, 3 }, { floor_map_set_seabed02, 3 }, { floor_map_set_boss05, 1 }, { floor_map_set_boss06, 1 }, { floor_map_set_boss07, 1 }, { floor_map_set_boss08, 1 }, { floor_map_set_jungle06, 1 }, { floor_map_set_jungle07, 5 } };
__declspec(section ".data") const char *floor_map_set_acity00[2] = { floor_map_name_acity00, floor_map_name_acity00_00 };
__declspec(section ".data") const char *floor_map_set_aforest01[2] = { floor_map_name_aforest01, floor_map_name_aforest01 };
__declspec(section ".data") const char *floor_map_set_aforest02[2] = { floor_map_name_aforest02, floor_map_name_aforest02 };
const char *floor_map_set_acave01[12] = { floor_map_name_acave01, floor_map_name_acave01_00, floor_map_name_acave01, floor_map_name_acave01_01, floor_map_name_acave01, floor_map_name_acave01_02, floor_map_name_acave01, floor_map_name_acave01_03, floor_map_name_acave01, floor_map_name_acave01_04, floor_map_name_acave01, floor_map_name_acave01_05 };
const char *floor_map_set_acave02[10] = { floor_map_name_acave02, floor_map_name_acave02_00, floor_map_name_acave02, floor_map_name_acave02_01, floor_map_name_acave02, floor_map_name_acave02_02, floor_map_name_acave02, floor_map_name_acave02_03, floor_map_name_acave02, floor_map_name_acave02_04 };
const char *floor_map_set_acave03[12] = { floor_map_name_acave03, floor_map_name_acave03_00, floor_map_name_acave03, floor_map_name_acave03_01, floor_map_name_acave03, floor_map_name_acave03_02, floor_map_name_acave03, floor_map_name_acave03_03, floor_map_name_acave03, floor_map_name_acave03_04, floor_map_name_acave03, floor_map_name_acave03_05 };
const char *floor_map_set_amachine01[12] = { floor_map_name_amachine01, floor_map_name_amachine01_00, floor_map_name_amachine01, floor_map_name_amachine01_01, floor_map_name_amachine01, floor_map_name_amachine01_02, floor_map_name_amachine01, floor_map_name_amachine01_03, floor_map_name_amachine01, floor_map_name_amachine01_04, floor_map_name_amachine01, floor_map_name_amachine01_05 };
const char *floor_map_set_amachine02[12] = { floor_map_name_amachine02, floor_map_name_amachine02_00, floor_map_name_amachine02, floor_map_name_amachine02_01, floor_map_name_amachine02, floor_map_name_amachine02_02, floor_map_name_amachine02, floor_map_name_amachine02_03, floor_map_name_amachine02, floor_map_name_amachine02_04, floor_map_name_amachine02, floor_map_name_amachine02_05 };
const char *floor_map_set_aancient01[10] = { floor_map_name_aancient01, floor_map_name_aancient01_00, floor_map_name_aancient01, floor_map_name_aancient01_01, floor_map_name_aancient01, floor_map_name_aancient01_02, floor_map_name_aancient01, floor_map_name_aancient01_03, floor_map_name_aancient01, floor_map_name_aancient01_04 };
const char *floor_map_set_aancient02[10] = { floor_map_name_aancient02, floor_map_name_aancient02_00, floor_map_name_aancient02, floor_map_name_aancient02_01, floor_map_name_aancient02, floor_map_name_aancient02_02, floor_map_name_aancient02, floor_map_name_aancient02_03, floor_map_name_aancient02, floor_map_name_aancient02_04 };
const char *floor_map_set_aancient03[10] = { floor_map_name_aancient03, floor_map_name_aancient03_00, floor_map_name_aancient03, floor_map_name_aancient03_01, floor_map_name_aancient03, floor_map_name_aancient03_02, floor_map_name_aancient03, floor_map_name_aancient03_03, floor_map_name_aancient03, floor_map_name_aancient03_04 };
__declspec(section ".data") const char *floor_map_set_aboss01[2] = { floor_map_name_aboss01, floor_map_name_aboss01 };
__declspec(section ".data") const char *floor_map_set_aboss02[2] = { floor_map_name_aboss02, floor_map_name_aboss02 };
__declspec(section ".data") const char *floor_map_set_aboss03[2] = { floor_map_name_aboss03, floor_map_name_aboss03 };
}
FloorSceneEntry floor_scene_table[36] = { { floor_map_set_acity00, 1 }, { floor_map_set_aforest01, 1 }, { floor_map_set_aforest02, 1 }, { floor_map_set_acave01, 6 }, { floor_map_set_acave02, 5 }, { floor_map_set_acave03, 6 }, { floor_map_set_amachine01, 6 }, { floor_map_set_amachine02, 6 }, { floor_map_set_aancient01, 5 }, { floor_map_set_aancient02, 5 }, { floor_map_set_aancient03, 5 }, { floor_map_set_aboss01, 1 }, { floor_map_set_aboss02, 1 }, { floor_map_set_aboss03, 1 }, { floor_map_set_darkfalz00, 1 }, { floor_map_set_lobby_01, 15 }, { floor_map_set_vs01, 3 }, { floor_map_set_vs02, 3 }, { floor_map_set_labo00, 1 }, { floor_map_set_ruins01, 3 }, { floor_map_set_ruins02, 3 }, { floor_map_set_space01, 3 }, { floor_map_set_space02, 3 }, { floor_map_set_jungle01, 1 }, { floor_map_set_jungle02, 1 }, { floor_map_set_jungle03, 1 }, { floor_map_set_jungle04, 3 }, { floor_map_set_jungle05, 1 }, { floor_map_set_seabed01, 3 }, { floor_map_set_seabed02, 3 }, { floor_map_set_boss05, 1 }, { floor_map_set_boss06, 1 }, { floor_map_set_boss07, 1 }, { floor_map_set_boss08, 1 }, { floor_map_set_jungle06, 1 }, { floor_map_set_jungle07, 5 } };
const char *forest_rel_filename_table[6] = { "SetDataTableOff.rel", "SetDataTableOffUlti.rel", "SetDataTableOn.rel", "SetDataTableOnUlti.rel", "SetDataTable_TGS2001.rel", 0 };



    extern int story_select_pending_state;
void TLobby::reset_story_select() { TAdStorySelectGC::set_state((saddr)((void*)0)); story_select_pending_state = -1; }

s32 TLobby::is_scene_ready() {
    s32 status;

    if (get_current_floor_area() != AREA_LOBBY) {
        return 0;
    }
    status = TScene::get_status();
    if ((status >= 0xD) && (status < 0xF)) {
        return 1;
    }
    return 0;
}
void TLobby__sub_80207E24(void* p, s32 size) { ((TLobby *)p)->copy_table_entries(size); }
void TLobby__sub_80207E44(void) {  }
void TLobby__sub_80207E48(void) { randomize_adventure_maps(); }
s32 lookup_floor_map_selection(s32 floor, FloorMapSelection *selection) {
    return get_floor_map_selection(floor, selection);
}
saddr get_floor_scene_table(s32 area) {
    if (area > 0x23) {
        return 0;
    }
    if (TLobby::is_online_ready() != 0) {
        return (saddr)floor_scene_table[area].names;
    }
    return (saddr)offline_floor_scene_table[area].names;
}


void TLobby::reset_story_select(void* p) { TLobby::reset_story_select(); }
void TLobby__sub_80207F10(void) { TLobby::reset_story_select(); }
typedef FloorLifecycleEntry E_80207F80;
typedef FloorLifecycleCallback Fn_80208020;
typedef FloorLifecycleEntry E_80208020;
extern "C" {
s32 bswap_16__FPUs(u16 *, s32);
s32 bswap_32__FPUl(s32 *, s32);
}

s32 init_object_set_data(ObjectSetData *set) {
    s32 r;
    memset(set, 0, sizeof(*set));
    set->set_index = -1;
    r = get_current_floor();
    set->floor = r;
    set->entity_id = 0xFFFF;
    return r;
}
extern "C" {

void run_floor_cleanup_callbacks__6TLobbyFi(s32 floor) {
    E_80207F80 *p = (E_80207F80 *)floor_lifecycle_callback_tables[floor];
    s32 n;
    s32 i;
    if (p != 0) {
        n = 0;
        while (p->cleanup != 0) {
            p++;
            n++;
        }
        for (i = 0; i < n; i++) {
            (p--)[-1].cleanup();
        }
    }
}
}

void TLobby::update_current_floor() { get_current_floor_area(); ((void (*)(void))run_floor_cleanup_callbacks__6TLobbyFi)(); }
s32 run_floor_initialize_callbacks(s32 floor) {
    E_80208020 *p = floor_lifecycle_callback_tables[floor];
    Fn_80208020 f;
    if (p == 0) {
        return 1;
    }
    while ((f = p->initialize) != 0) {
        if (is_area_transfer_pending() != 0) {
            return 0;
        }
        f();
        p++;
    }
    return 1;
}

s32 TLobby::update_key_machine() { get_current_floor_area(); return ((int (*)(void))run_floor_initialize_callbacks)(); }
void bswap_enemy_set_row(void *row_ptr) {
    EnemySetRecord *row = (EnemySetRecord *)row_ptr;
    bswap_16((u16 *)&row->type);
    bswap_enemy_set_row_fields(&row->placement);
}

void bswap_enemy_set_row_fields(void *placement_ptr) {
    EnemyPlacement *placement = (EnemyPlacement *)placement_ptr;
    bswap_16((u16 *)&placement->child_count);
    bswap_16((u16 *)&placement->unknown04[0]);
    bswap_16((u16 *)&placement->unknown0c[0]);
    bswap_16((u16 *)&placement->room);
    bswap_16((u16 *)&placement->wave);
    bswap_32((u32 *)&placement->position.x);
    bswap_32((u32 *)&placement->position.y);
    bswap_32((u32 *)&placement->position.z);
    bswap_32((u32 *)&placement->rotation[0]);
    bswap_32((u32 *)&placement->rotation[1]);
    bswap_32((u32 *)&placement->rotation[2]);
    bswap_32((u32 *)&placement->parameters[0]);
    bswap_32((u32 *)&placement->parameters[1]);
    bswap_32((u32 *)&placement->parameters[2]);
    bswap_32((u32 *)&placement->parameters[3]);
    bswap_32((u32 *)&placement->parameters[4]);
    bswap_16((u16 *)&placement->variant);
    bswap_16((u16 *)&placement->unknown3e);
}

void swap_object_row_endian(void *row_ptr) {
    FloorObjectSetRow *row = (FloorObjectSetRow *)row_ptr;
    bswap_16((u16 *)&row->type);
    bswap_object_row_fields(&row->placement);
}

void bswap_object_row_fields(void *placement_ptr) {
    ObjectSetData *placement = (ObjectSetData *)placement_ptr;
    bswap_16((u16 *)&placement->floor);
    bswap_16((u16 *)&placement->wave);
    bswap_16((u16 *)&placement->room);
    bswap_32((u32 *)&placement->position.x);
    bswap_32((u32 *)&placement->position.y);
    bswap_32((u32 *)&placement->position.z);
    bswap_32((u32 *)&placement->rotation[0]);
    bswap_32((u32 *)&placement->rotation[1]);
    bswap_32((u32 *)&placement->rotation[2]);
    bswap_32((u32 *)&placement->scale.x);
    bswap_32((u32 *)&placement->scale.y);
    bswap_32((u32 *)&placement->scale.z);
    bswap_32((u32 *)&placement->set_params[0]);
    bswap_32((u32 *)&placement->set_params[1]);
    bswap_32((u32 *)&placement->set_params[2]);
}

MapSetArea *map_set_areas;

s32 TLobby::get_drop_item_mode() {
    s32 main_phase;

    main_phase = get_main_phase();
    switch (main_phase) {
    case 15:
        if ((TLobby::get_instance() == 0) && ((s32) game_difficulty_selection == 3)) {
            return 3;
        }
        return 2;
    case 14:
        if (is_split_screen() == 1) {
            if ((TLobby::get_instance() == 0) && ((s32) game_difficulty_selection == 3)) {
                return 3;
            }
            return 2;
        }
        if ((TLobby::get_instance() == 0) && ((s32) game_difficulty_selection == 3)) {
            return 1;
        }
        return 0;
    default:
        return 3;
    }
}


// inferred: first word of the loaded SetDataTable*.rel module (update_drop_item/load_item_data)
MapSetArea *forest_rel_set_data_table;
// inferred: the SetDataTable*.rel module load_relocatable_file returns
MapSetModule *forest_rel_module;
void *forest_rel_work_buffer;

void TLobby::update_drop_item() {
    MapSetModule *module;
    MapSetArea *areas;
    s32 drop_item_mode;

    forest_rel_set_data_table = 0;
    forest_rel_module = NULL;
    if (forest_rel_work_buffer != NULL) {
        drop_item_mode = TLobby::get_drop_item_mode();
        if (get_resource_file_size(forest_rel_filename_table[drop_item_mode]) <= 0x24B8) {
            module = (MapSetModule *)load_relocatable_file(forest_rel_filename_table[drop_item_mode], forest_rel_work_buffer);
            forest_rel_module = module;
            if (module != NULL) {
                areas = module->areas;
                forest_rel_set_data_table = areas;
                map_set_areas = areas;
            }
        }
    }
}


void free_forest_rel_work_buffer(void) {
    if (forest_rel_work_buffer != NULL) {
        safe_free(forest_rel_work_buffer);
        forest_rel_work_buffer = NULL;
        forest_rel_module = 0;
        forest_rel_set_data_table = 0;
        map_set_areas = 0;
    }
}





void TLobby::load_item_data() {
    MapSetModule *module;
    MapSetArea *areas;
    s32 drop_item_mode;
    void *buffer;

    forest_rel_set_data_table = 0;
    forest_rel_module = NULL;
    buffer = TQuestVmDownLoadServer::alloc(0x24B8);
    forest_rel_work_buffer = buffer;
    if (buffer != NULL) {
        drop_item_mode = TLobby::get_drop_item_mode();
        if (get_resource_file_size(forest_rel_filename_table[drop_item_mode]) <= 0x24B8) {
            module = (MapSetModule *)load_relocatable_file(forest_rel_filename_table[drop_item_mode], forest_rel_work_buffer);
            forest_rel_module = module;
            if (module != NULL) {
                areas = module->areas;
                forest_rel_set_data_table = areas;
                map_set_areas = areas;
            }
        }
    }
}

u8 *wave_event_stream_base;
s32 wave_event_stream_cursor;
s32 wave_event_stop_requested;
s32 wave_event_trigger_count;
s32 wave_event_first_switch_set;
void TLobby::relink_objects(s16 a, s16 b) { link_matching_objects(a, b); wave_event_stop_requested = 1; }
void send_6x67_wave_trigger_event(s32 event_id) {
    G_FloorEvent_6x67 pkt;
    wave_event_trigger_count++;
    set_destroy_event_id(1);
    pkt.init();
    pkt.header.client_id = 0xFFFF;
    pkt.floor = get_current_floor();
    pkt.event_id = event_id;
    pkt.sender_client_id = local_client_id;
    pkt.send();
}

void send_6x05_wave_clear_switch(s32 switch_id) {
    Send6x05WaveClearSwitchPacket pkt;
    ((G_SwitchStateChanged_6x05 *)(&pkt))->init();
    pkt.b = 0;
    pkt.a = 0xFFFF;
    pkt.c = switch_id;
    pkt.d = ((s32 (*)(s32))get_current_floor)(0xFFFF);
    pkt.e = 0;
    ((G_SwitchStateChanged_6x05 *)(&pkt))->send();
}

void send_6x05_wave_set_switch(s16 switch_id) {
    Send6x05WaveSetSwitchPacket pkt;
    ((G_SwitchStateChanged_6x05 *)(&pkt))->init();
    pkt.a = 0xFFFF;
    pkt.b = 0;
    pkt.c = switch_id;
    pkt.d = ((s8)get_current_floor());
    if (wave_event_first_switch_set != 0) {
        pkt.e = 3;
        wave_event_first_switch_set = 0;
    } else {
        pkt.e = 1;
    }
    ((G_SwitchStateChanged_6x05 *)(&pkt))->send();
}
int link_matching_objects__6TLobbyFPv(void *p) { return ((int (*)(void *))TLobby::link_matching_objects)(p); }
int spawn_objects_at_pos__6TLobbyFPv(void *p) { return ((int (*)(void *))TLobby::spawn_objects_at_pos)(p); }

void request_wave_event_stop(void) { wave_event_stop_requested = 1; }

void TLobby__sub_80208648(void) {  }

// Wave event script opcodes, indexed by the opcode byte: decode reads the opcode's operands from the script
// stream and calls action with them, so each action has the signature its decoder calls it with.
typedef void (*WaveEventActionFunc)();
struct WaveEventAction {
    void (*decode)(u8 opcode);
    WaveEventActionFunc action;
};

WaveEventAction wave_event_action_table[16] = {
    { TLobby::invoke_command, TLobby__sub_80208648 },
    { TLobby::invoke_command, request_wave_event_stop },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { 0, 0 },
    { TLobby::dispatch_opcode_two_u16, (WaveEventActionFunc)spawn_objects_at_pos__6TLobbyFPv },
    { TLobby::dispatch_opcode_two_u16, (WaveEventActionFunc)link_matching_objects__6TLobbyFPv },
    { TLobby::dispatch_stream_command, (WaveEventActionFunc)send_6x05_wave_set_switch },
    { TLobby::dispatch_stream_command, (WaveEventActionFunc)send_6x05_wave_clear_switch },
    { dispatch_wave_event_action, (WaveEventActionFunc)send_6x67_wave_trigger_event },
    { TLobby::dispatch_opcode_two_u16, (WaveEventActionFunc)TLobby::relink_objects },
};

void dispatch_wave_event_action(u8 opcode) {
    void (*action)(s32) = (void (*)(s32))wave_event_action_table[opcode].action;
    action(read_be_u32());
}

void TLobby::dispatch_opcode_two_u16(u8 opcode) {
    void (*action)(u16, u16) = (void (*)(u16, u16))wave_event_action_table[opcode].action;
    u16 a = read_stream_u16();
    action(a, read_stream_u16());
}

void TLobby::dispatch_stream_command(u8 opcode) {
    void (*action)(u16) = (void (*)(u16))wave_event_action_table[opcode].action;
    action(read_stream_u16());
}

void TLobby::invoke_command(u8 opcode) {
    wave_event_action_table[opcode].action();
}


s32 read_be_u32(void) {
    s32 value;
    s32 cursor;

    memcpy(&value, (void *)(wave_event_stream_base + wave_event_stream_cursor), 4);
    cursor = wave_event_stream_cursor;
    wave_event_stream_cursor = cursor + 4;
    bswap_32__FPUl(&value, cursor);
    return value;
}

u16 read_stream_u16(void) {
    u16 value;
    s32 cursor;

    memcpy(&value, wave_event_stream_base + wave_event_stream_cursor, 2);
    cursor = wave_event_stream_cursor;
    wave_event_stream_cursor = cursor + 2;
    ((s32 (*)(u16 *, s32))bswap_16__FPUs)(&value, cursor);
    return value;
}



unsigned char read_stream_u8(void) { return wave_event_stream_base[wave_event_stream_cursor++]; }

s32 run_wave_event_actions(void) {
    wave_event_stop_requested = 0;
    wave_event_trigger_count = 0;
    wave_event_first_switch_set = 1;
    while (wave_event_stop_requested == 0) {
        u8 opcode = read_stream_u8();
        wave_event_action_table[opcode].decode(opcode);
    }
    return wave_event_trigger_count;
}


void TLobby__sub_80208884(void *a0) { wave_event_stream_base = *(u8 **)((char *)a0 + 0x0); wave_event_stream_cursor = *(s32 *)((char *)a0 + 0x4); }
