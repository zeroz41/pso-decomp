#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/map/FloorArea.h"

struct RecoveredGlobal_80207798_lbl_80513920 {
    s32 value;
    u8 remaining[0xD4];
};

extern "C" {
RecoveredGlobal_80207798_lbl_80513920 floor_map_registry;
}


struct RecoveredGlobal_802077CC_lbl_80513920 {
    s32 value;
    u8 remaining[0xD4];
};

struct RecoveredGlobal_802078A4_lbl_80513920
{
  s32 value;
  u8 remaining[0xD4];
};

struct Map_80207C60 { s32 map; s32 layout; s32 entities; };

struct Ids_80207C60 { s32 w[18]; };

struct Tbl_8020765C { s32 w[2][18]; };

struct Ent_8020780C { s32 pad; s32 a; s32 b; };

typedef struct FloorEntry_80207770 { s32 a; s32 b; s32 c; } FloorEntry_80207770;

// File names of the floor maps: the first three are the sky model extensions
// TSceneSora::load_sky_resources passes to TLobby::replace_file_extension, the rest
// are the per-floor map name lists (pointed to by the tables in TLobby_80207DA8.cpp).
extern const char sky_model_ext_s_njm[] = "s.njm";
extern const char sky_model_ext_sm_gj[] = "sm.gj";
extern const char sky_model_ext_s_gj[] = "s.gj";
extern const char floor_map_name_city00[] = "map_city00";
extern const char floor_map_name_city00_00[] = "map_city00_00";
extern const char floor_map_name_forest01[] = "map_forest01";
extern const char floor_map_name_forest02[] = "map_forest02";
extern const char floor_map_name_cave01[] = "map_cave01";
extern const char floor_map_name_cave01_00[] = "map_cave01_00";
extern const char floor_map_name_cave01_01[] = "map_cave01_01";
extern const char floor_map_name_cave01_02[] = "map_cave01_02";
extern const char floor_map_name_cave01_03[] = "map_cave01_03";
extern const char floor_map_name_cave01_04[] = "map_cave01_04";
extern const char floor_map_name_cave01_05[] = "map_cave01_05";
extern const char floor_map_name_cave02[] = "map_cave02";
extern const char floor_map_name_cave02_00[] = "map_cave02_00";
extern const char floor_map_name_cave02_01[] = "map_cave02_01";
extern const char floor_map_name_cave02_02[] = "map_cave02_02";
extern const char floor_map_name_cave02_03[] = "map_cave02_03";
extern const char floor_map_name_cave02_04[] = "map_cave02_04";
extern const char floor_map_name_cave03[] = "map_cave03";
extern const char floor_map_name_cave03_00[] = "map_cave03_00";
extern const char floor_map_name_cave03_01[] = "map_cave03_01";
extern const char floor_map_name_cave03_02[] = "map_cave03_02";
extern const char floor_map_name_cave03_03[] = "map_cave03_03";
extern const char floor_map_name_cave03_04[] = "map_cave03_04";
extern const char floor_map_name_cave03_05[] = "map_cave03_05";
extern const char floor_map_name_machine01[] = "map_machine01";
extern const char floor_map_name_machine01_00[] = "map_machine01_00";
extern const char floor_map_name_machine01_01[] = "map_machine01_01";
extern const char floor_map_name_machine01_02[] = "map_machine01_02";
extern const char floor_map_name_machine01_03[] = "map_machine01_03";
extern const char floor_map_name_machine01_04[] = "map_machine01_04";
extern const char floor_map_name_machine01_05[] = "map_machine01_05";
extern const char floor_map_name_machine02[] = "map_machine02";
extern const char floor_map_name_machine02_00[] = "map_machine02_00";
extern const char floor_map_name_machine02_01[] = "map_machine02_01";
extern const char floor_map_name_machine02_02[] = "map_machine02_02";
extern const char floor_map_name_machine02_03[] = "map_machine02_03";
extern const char floor_map_name_machine02_04[] = "map_machine02_04";
extern const char floor_map_name_machine02_05[] = "map_machine02_05";
extern const char floor_map_name_ancient01[] = "map_ancient01";
extern const char floor_map_name_ancient01_00[] = "map_ancient01_00";
extern const char floor_map_name_ancient01_01[] = "map_ancient01_01";
extern const char floor_map_name_ancient01_02[] = "map_ancient01_02";
extern const char floor_map_name_ancient01_03[] = "map_ancient01_03";
extern const char floor_map_name_ancient01_04[] = "map_ancient01_04";
extern const char floor_map_name_ancient02[] = "map_ancient02";
extern const char floor_map_name_ancient02_00[] = "map_ancient02_00";
extern const char floor_map_name_ancient02_01[] = "map_ancient02_01";
extern const char floor_map_name_ancient02_02[] = "map_ancient02_02";
extern const char floor_map_name_ancient02_03[] = "map_ancient02_03";
extern const char floor_map_name_ancient02_04[] = "map_ancient02_04";
extern const char floor_map_name_ancient03[] = "map_ancient03";
extern const char floor_map_name_ancient03_00[] = "map_ancient03_00";
extern const char floor_map_name_ancient03_01[] = "map_ancient03_01";
extern const char floor_map_name_ancient03_02[] = "map_ancient03_02";
extern const char floor_map_name_ancient03_03[] = "map_ancient03_03";
extern const char floor_map_name_ancient03_04[] = "map_ancient03_04";
extern const char floor_map_name_boss01[] = "map_boss01";
extern const char floor_map_name_boss02[] = "map_boss02";
extern const char floor_map_name_boss03[] = "map_boss03";
extern const char floor_map_name_darkfalz00[] = "map_darkfalz00";
extern const char floor_map_name_lobby_01[] = "map_lobby_01";
extern const char floor_map_name_lobby_02[] = "map_lobby_02";
extern const char floor_map_name_lobby_03[] = "map_lobby_03";
extern const char floor_map_name_lobby_04[] = "map_lobby_04";
extern const char floor_map_name_lobby_05[] = "map_lobby_05";
extern const char floor_map_name_lobby_06[] = "map_lobby_06";
extern const char floor_map_name_lobby_07[] = "map_lobby_07";
extern const char floor_map_name_lobby_08[] = "map_lobby_08";
extern const char floor_map_name_lobby_09[] = "map_lobby_09";
extern const char floor_map_name_lobby_10[] = "map_lobby_10";
extern const char floor_map_name_lobby_red_be00[] = "map_lobby_red_be00";
extern const char floor_map_name_lobby_yellow_be00[] = "map_lobby_yellow_be00";
extern const char floor_map_name_lobby_green_be00[] = "map_lobby_green_be00";
extern const char floor_map_name_soccer11[] = "map_soccer11";
extern const char floor_map_name_soccer12[] = "map_soccer12";
extern const char floor_map_name_vs01[] = "map_vs01";
extern const char floor_map_name_vs01_00[] = "map_vs01_00";
extern const char floor_map_name_vs01_01[] = "map_vs01_01";
extern const char floor_map_name_vs01_02[] = "map_vs01_02";
extern const char floor_map_name_vs02[] = "map_vs02";
extern const char floor_map_name_vs02_00[] = "map_vs02_00";
extern const char floor_map_name_vs02_01[] = "map_vs02_01";
extern const char floor_map_name_vs02_02[] = "map_vs02_02";
extern const char floor_map_name_labo00[] = "map_labo00";
extern const char floor_map_name_labo00_00[] = "map_labo00_00";
extern const char floor_map_name_space01[] = "map_space01";
extern const char floor_map_name_space01_00[] = "map_space01_00";
extern const char floor_map_name_space01_01[] = "map_space01_01";
extern const char floor_map_name_space01_02[] = "map_space01_02";
extern const char floor_map_name_space02[] = "map_space02";
extern const char floor_map_name_space02_00[] = "map_space02_00";
extern const char floor_map_name_space02_01[] = "map_space02_01";
extern const char floor_map_name_space02_02[] = "map_space02_02";
extern const char floor_map_name_ruins01[] = "map_ruins01";
extern const char floor_map_name_ruins01_00[] = "map_ruins01_00";
extern const char floor_map_name_ruins01_01[] = "map_ruins01_01";
extern const char floor_map_name_ruins01_02[] = "map_ruins01_02";
extern const char floor_map_name_ruins02[] = "map_ruins02";
extern const char floor_map_name_ruins02_00[] = "map_ruins02_00";
extern const char floor_map_name_ruins02_01[] = "map_ruins02_01";
extern const char floor_map_name_ruins02_02[] = "map_ruins02_02";
extern const char floor_map_name_jungle01[] = "map_jungle01";
extern const char floor_map_name_jungle01_00[] = "map_jungle01_00";
extern const char floor_map_name_jungle02[] = "map_jungle02";
extern const char floor_map_name_jungle02_00[] = "map_jungle02_00";
extern const char floor_map_name_jungle03[] = "map_jungle03";
extern const char floor_map_name_jungle03_00[] = "map_jungle03_00";
extern const char floor_map_name_jungle04[] = "map_jungle04";
extern const char floor_map_name_jungle04_00[] = "map_jungle04_00";
extern const char floor_map_name_jungle04_01[] = "map_jungle04_01";
extern const char floor_map_name_jungle04_02[] = "map_jungle04_02";
extern const char floor_map_name_jungle05[] = "map_jungle05";
extern const char floor_map_name_jungle05_00[] = "map_jungle05_00";
extern const char floor_map_name_jungle06[] = "map_jungle06";
extern const char floor_map_name_jungle06_00[] = "map_jungle06_00";
extern const char floor_map_name_jungle07[] = "map_jungle07";
extern const char floor_map_name_jungle07_00[] = "map_jungle07_00";
extern const char floor_map_name_jungle07_01[] = "map_jungle07_01";
extern const char floor_map_name_jungle07_02[] = "map_jungle07_02";
extern const char floor_map_name_jungle07_03[] = "map_jungle07_03";
extern const char floor_map_name_jungle07_04[] = "map_jungle07_04";
extern const char floor_map_name_seabed01[] = "map_seabed01";
extern const char floor_map_name_seabed01_00[] = "map_seabed01_00";
extern const char floor_map_name_seabed01_01[] = "map_seabed01_01";
extern const char floor_map_name_seabed01_02[] = "map_seabed01_02";
extern const char floor_map_name_seabed02[] = "map_seabed02";
extern const char floor_map_name_seabed02_00[] = "map_seabed02_00";
extern const char floor_map_name_seabed02_01[] = "map_seabed02_01";
extern const char floor_map_name_seabed02_02[] = "map_seabed02_02";
extern const char floor_map_name_boss05[] = "map_boss05";
extern const char floor_map_name_boss06[] = "map_boss06";
extern const char floor_map_name_boss07[] = "map_boss07";
extern const char floor_map_name_boss08[] = "map_boss08";
extern const char floor_map_name_acity00[] = "map_acity00";
extern const char floor_map_name_acity00_00[] = "map_acity00_00";
extern const char floor_map_name_aforest01[] = "map_aforest01";
extern const char floor_map_name_aforest02[] = "map_aforest02";
extern const char floor_map_name_acave01[] = "map_acave01";
extern const char floor_map_name_acave01_00[] = "map_acave01_00";
extern const char floor_map_name_acave01_01[] = "map_acave01_01";
extern const char floor_map_name_acave01_02[] = "map_acave01_02";
extern const char floor_map_name_acave01_03[] = "map_acave01_03";
extern const char floor_map_name_acave01_04[] = "map_acave01_04";
extern const char floor_map_name_acave01_05[] = "map_acave01_05";
extern const char floor_map_name_acave02[] = "map_acave02";
extern const char floor_map_name_acave02_00[] = "map_acave02_00";
extern const char floor_map_name_acave02_01[] = "map_acave02_01";
extern const char floor_map_name_acave02_02[] = "map_acave02_02";
extern const char floor_map_name_acave02_03[] = "map_acave02_03";
extern const char floor_map_name_acave02_04[] = "map_acave02_04";
extern const char floor_map_name_acave03[] = "map_acave03";
extern const char floor_map_name_acave03_00[] = "map_acave03_00";
extern const char floor_map_name_acave03_01[] = "map_acave03_01";
extern const char floor_map_name_acave03_02[] = "map_acave03_02";
extern const char floor_map_name_acave03_03[] = "map_acave03_03";
extern const char floor_map_name_acave03_04[] = "map_acave03_04";
extern const char floor_map_name_acave03_05[] = "map_acave03_05";
extern const char floor_map_name_amachine01[] = "map_amachine01";
extern const char floor_map_name_amachine01_00[] = "map_amachine01_00";
extern const char floor_map_name_amachine01_01[] = "map_amachine01_01";
extern const char floor_map_name_amachine01_02[] = "map_amachine01_02";
extern const char floor_map_name_amachine01_03[] = "map_amachine01_03";
extern const char floor_map_name_amachine01_04[] = "map_amachine01_04";
extern const char floor_map_name_amachine01_05[] = "map_amachine01_05";
extern const char floor_map_name_amachine02[] = "map_amachine02";
extern const char floor_map_name_amachine02_00[] = "map_amachine02_00";
extern const char floor_map_name_amachine02_01[] = "map_amachine02_01";
extern const char floor_map_name_amachine02_02[] = "map_amachine02_02";
extern const char floor_map_name_amachine02_03[] = "map_amachine02_03";
extern const char floor_map_name_amachine02_04[] = "map_amachine02_04";
extern const char floor_map_name_amachine02_05[] = "map_amachine02_05";
extern const char floor_map_name_aancient01[] = "map_aancient01";
extern const char floor_map_name_aancient01_00[] = "map_aancient01_00";
extern const char floor_map_name_aancient01_01[] = "map_aancient01_01";
extern const char floor_map_name_aancient01_02[] = "map_aancient01_02";
extern const char floor_map_name_aancient01_03[] = "map_aancient01_03";
extern const char floor_map_name_aancient01_04[] = "map_aancient01_04";
extern const char floor_map_name_aancient02[] = "map_aancient02";
extern const char floor_map_name_aancient02_00[] = "map_aancient02_00";
extern const char floor_map_name_aancient02_01[] = "map_aancient02_01";
extern const char floor_map_name_aancient02_02[] = "map_aancient02_02";
extern const char floor_map_name_aancient02_03[] = "map_aancient02_03";
extern const char floor_map_name_aancient02_04[] = "map_aancient02_04";
extern const char floor_map_name_aancient03[] = "map_aancient03";
extern const char floor_map_name_aancient03_00[] = "map_aancient03_00";
extern const char floor_map_name_aancient03_01[] = "map_aancient03_01";
extern const char floor_map_name_aancient03_02[] = "map_aancient03_02";
extern const char floor_map_name_aancient03_03[] = "map_aancient03_03";
extern const char floor_map_name_aancient03_04[] = "map_aancient03_04";
extern const char floor_map_name_aboss01[] = "map_aboss01";
extern const char floor_map_name_aboss02[] = "map_aboss02";
extern const char floor_map_name_aboss03[] = "map_aboss03";

extern const s32 adventure_map_variation_count_table[36][2] = {
    { 1, 1 },
    { 1, 3 },
    { 1, 3 },
    { 3, 1 },
    { 3, 1 },
    { 3, 1 },
    { 3, 2 },
    { 3, 2 },
    { 3, 2 },
    { 3, 2 },
    { 3, 2 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
    { 10, 1 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
    { 2, 1 },
    { 2, 1 },
    { 2, 1 },
    { 2, 1 },
    { 1, 3 },
    { 1, 3 },
    { 1, 3 },
    { 2, 2 },
    { 1, 3 },
    { 2, 1 },
    { 2, 1 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
};
extern const s32 online_floor_map_variation_dimension_table[36][2] = {
    { 1, 1 },
    { 1, 5 },
    { 1, 5 },
    { 3, 2 },
    { 3, 2 },
    { 3, 2 },
    { 3, 2 },
    { 3, 2 },
    { 3, 2 },
    { 3, 2 },
    { 3, 2 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
    { 10, 1 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
    { 2, 1 },
    { 2, 1 },
    { 2, 1 },
    { 2, 1 },
    { 1, 3 },
    { 1, 3 },
    { 1, 3 },
    { 2, 2 },
    { 1, 3 },
    { 2, 2 },
    { 2, 2 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
    { 1, 1 },
};
extern const Ids_80207C60 floor_map_registry_id_table = { { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17 } };
extern const Ids_80207C60 boss_warp_area_id_table = { { 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35 } };
extern const Tbl_8020765C boss_warp_destination_table = { {
    { 0, 11, 11, 12, 12, 12, 13, 13, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 14, 14, 15, 15, 12, 12, 12, 12, 12, 13, 13, 0, 0, 0, 0, 0, 0 },
} };
extern const Tbl_8020765C boss_warp_destination_table_b = { {
    { 0, 11, 11, 12, 12, 12, 13, 13, 14, 14, 14, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 14, 14, 15, 15, 12, 12, 12, 12, 12, 13, 13, 0, 0, 0, 0, 0, 0 },
} };

extern RecoveredGlobal_80207798_lbl_80513920 floor_map_registry;
s32 set_floor_map_selection(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern "C" {
s32 get_floor_map_selection(s32 arg0, u8 *arg1);
s32 get_main_phase(void);
s32 rand(void);
extern int selected_episode;
void randomize_adventure_maps(void);
s32 memset(void *, int, int);
void TLobby__sub_80207BB0(void);
s32 get_current_floor();
s32 get_game_play_mode();
s32 get_boss_warp_destination(void);
s32 get_floor_map_terrain(s32 arg0);
struct Buf12_80207718_80207644 { s32 a, b, c; };

    extern int story_select_current;
void TLobby::backup_story_select() { selected_episode = story_select_current; }

void TLobby::sync_story_select() { story_select_current = selected_episode; }

s32 get_boss_warp_destination(void) {
    Tbl_8020765C a = boss_warp_destination_table;
    Tbl_8020765C b = boss_warp_destination_table_b;
    if (get_game_play_mode() == 1) {
        return b.w[0][get_current_floor_area()];
    }
    s32 i = TLobby::get_instance();
    s32 p = get_current_floor();
    return a.w[i][p];
}

}

s32 get_floor_area(s32 floor) {
    struct Buf12_80207718_80207644 buf;

    if (get_floor_map_selection(floor, (u8 *)&buf) == 1) {
        return buf.a;
    }
    return -1;
}
void init_floor_map_registry(void);
extern s32 story_select_pending_state;

void set_floor_map_variant(s32 arg0, s32 arg1) {
    if (arg0 <= 0x11) {
        s32 *p = (s32 *)&floor_map_registry;
        p[arg0 * 3 + 1] = arg1;
    }
}

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_80207798_lbl_80513920_size[sizeof(RecoveredGlobal_80207798_lbl_80513920) == 0xD8 ? 1 : -1];

s32 get_floor_map_terrain(s32 arg0) {
    if (arg0 > 0x11) {
        return 0;
    }
    s32 *p = (s32 *)&floor_map_registry;
    return p[arg0 * 3 + 1];
}

s32 set_floor_map_selection(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r0;
    u8 *temp_r4;
    if (arg0 > 0x11) {
        return 0;
    }
    temp_r0 = arg0 * 0xC;
    *(s32 *)((s8 *)((u8 *)&floor_map_registry.value + temp_r0) + 0) = arg1;
    temp_r4 = (u8 *)&floor_map_registry.value + temp_r0;
    *(s32 *)((s8 *)temp_r4 + 4) = arg2;
    *(s32 *)((s8 *)temp_r4 + 8) = arg3;
    return 1;
}
#pragma pop

#pragma push
#pragma opt_common_subs off
typedef char RecoveredGlobal_802077CC_lbl_80513920_size[sizeof(RecoveredGlobal_802077CC_lbl_80513920) == 0xD8 ? 1 : -1];

s32 get_floor_map_selection(s32 arg0, u8 *arg1) {
    s32 temp_r6;
    u8 *temp_r5;
    if (arg0 > 0x11) {
        return 0;
    }
    temp_r6 = arg0 * 0xC;
    temp_r5 = (u8 *)(&(*(RecoveredGlobal_802077CC_lbl_80513920 *)&floor_map_registry).value) + temp_r6;
    *(s32 *)((s8 *)arg1 + 0) = (s32) *(s32 *)((s8 *)((u8 *)(&(*(RecoveredGlobal_802077CC_lbl_80513920 *)&floor_map_registry).value) + temp_r6) + 0);
    *(s32 *)((s8 *)arg1 + 4) = (s32) *(s32 *)((s8 *)temp_r5 + 4);
    *(s32 *)((s8 *)arg1 + 8) = (s32) *(s32 *)((s8 *)temp_r5 + 8);
    return 1;
}
#pragma pop

typedef struct RecoveredGlobal_802078A4_lbl_80513920 RecoveredGlobal_802078A4_lbl_80513920;
typedef char RecoveredGlobal_802078A4_lbl_80513920_size[((sizeof(RecoveredGlobal_802078A4_lbl_80513920)) == 0xD8) ? (1) : (-1)];

void TLobby::copy_table_entries(u32 size) {
    s32 *src = (s32 *)this;
    s32 n = size >> 3;
    s32 i;
    if (n <= 0x12) {
        switch ((*(s32 *)&selected_episode)) {
        case 1:
            for (i = 0; i < n; i++, src += 2) {
                ((Ent_8020780C *)&floor_map_registry)[i].a = src[0];
                ((Ent_8020780C *)&floor_map_registry)[i].b = src[1];
            }
            break;
        case 0:
        default:
            for (i = 0; i < n; i++, src += 2) {
                ((Ent_8020780C *)&floor_map_registry)[i].a = src[0];
                ((Ent_8020780C *)&floor_map_registry)[i].b = src[1];
            }
            break;
        }
    }
}

void randomize_adventure_maps(void) {
  s32 *var_r31;
  s32 main_phase;
  s32 var_r29;
  var_r31 = (s32 *) (&(*(RecoveredGlobal_802078A4_lbl_80513920 *)&floor_map_registry).value);
  TAdStorySelectGC::set_state((s32)((void*)((*(s32 *)&selected_episode))));
  main_phase = get_main_phase();
  if (TRaderMapCore::is_not_split_screen() == 1)
  {
    main_phase = 0xF;
  }
  var_r29 = 0;
  do
  {
    if (((s32) (*((s32 *) (((s8 *) var_r31) + 0)))) >= 0)
    {
      switch (main_phase)
      {
        case 14:
          *((s32 *) (((s8 *) var_r31) + 4)) = (s32) (((f32) (*((s32 *) (((s8 *)adventure_map_variation_count_table) + ((*((s32 *) (((s8 *) var_r31) + 0))) * 8))))) * (0.000030517578f * ((f32) rand())));
          *((s32 *) (((s8 *) var_r31) + 8)) = (s32) (((f32) (*((s32 *) (((s8 *) (((u8 *)adventure_map_variation_count_table) + ((*((s32 *) (((s8 *) var_r31) + 0))) * 8))) + 4)))) * (0.000030517578f * ((f32) rand())));
          break;
        case 15:
          *((s32 *) (((s8 *) var_r31) + 4)) = (s32) (((f32) (*((s32 *) (((s8 *)online_floor_map_variation_dimension_table) + ((*((s32 *) (((s8 *) var_r31) + 0))) * 8))))) * (0.000030517578f * ((f32) rand())));
          *((s32 *) (((s8 *) var_r31) + 8)) = (s32) (((f32) (*((s32 *) (((s8 *) (((u8 *)online_floor_map_variation_dimension_table) + ((*((s32 *) (((s8 *) var_r31) + 0))) * 8))) + 4)))) * (0.000030517578f * ((f32) rand())));
          break;
        default:
          *((s32 *) (((s8 *) var_r31) + 4)) = (s32) (((f32) (*((s32 *) (((s8 *)adventure_map_variation_count_table) + ((*((s32 *) (((s8 *) var_r31) + 0))) * 8))))) * (0.000030517578f * ((f32) rand())));
          *((s32 *) (((s8 *) var_r31) + 8)) = (s32) (((f32) (*((s32 *) (((s8 *) (((u8 *)adventure_map_variation_count_table) + ((*((s32 *) (((s8 *) var_r31) + 0))) * 8))) + 4)))) * (0.000030517578f * ((f32) rand())));
          break;
      }
    }
    var_r29 += 1;
    var_r31 = (s32 *) (((u8 *) var_r31) + 0xC);
  }
  while (var_r29 < 0x12);
}

#pragma push
#pragma opt_common_subs off
void TLobby__sub_80207BB0(void) {
    struct Ids_80207C60 ids = boss_warp_area_id_table;
    s32 i;
    memset((void *) ((struct Map_80207C60 *)&floor_map_registry), 0, 0xD8);
    for (i = 0; i < 18; i++) {
        ((struct Map_80207C60 *)&floor_map_registry)[i].map = -1;
    }
    for (i = 0; i < 18; i++) {
        ((struct Map_80207C60 *)&floor_map_registry)[i].map = ids.w[i];
    }
}
#pragma pop

void init_floor_map_registry(void) {
    struct Ids_80207C60 ids = floor_map_registry_id_table;
    s32 i;
    memset((void *) ((struct Map_80207C60 *)&floor_map_registry), 0, 0xD8);
    for (i = 0; i < 18; i++) {
        ((struct Map_80207C60 *)&floor_map_registry)[i].map = -1;
    }
    for (i = 0; i < 18; i++) {
        ((struct Map_80207C60 *)&floor_map_registry)[i].map = ids.w[i];
    }
}

void TLobby::reset_story_select_state() {
    if ((s32) story_select_pending_state != -1) {
        TAdStorySelectGC::set_state((s32)((void*)story_select_pending_state));
        story_select_pending_state = -1;
    }
}
