#include "pso/system/memory.h"
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
#include "pso/unk/TLobby.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/system/scene/TScene.h"
#include "pso/map/FloorArea.h"

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/byteswap.h"
#include <string.h>
#include "pso/unk/TLobby_800F8AA8.h"


extern char floor_map_name_acity00[];
extern char floor_map_name_acity00_00[];
extern char floor_map_name_aforest01[];
extern char floor_map_name_aforest02[];
extern char floor_map_name_acave01[];
extern char floor_map_name_acave01_00[];
extern char floor_map_name_acave01_01[];
extern char floor_map_name_acave01_02[];
extern char floor_map_name_acave01_03[];
extern char floor_map_name_acave01_04[];
extern char floor_map_name_acave01_05[];
extern char floor_map_name_acave02[];
extern char floor_map_name_acave02_00[];
extern char floor_map_name_acave02_01[];
extern char floor_map_name_acave02_02[];
extern char floor_map_name_acave02_03[];
extern char floor_map_name_acave02_04[];
extern char floor_map_name_acave03[];
extern char floor_map_name_acave03_00[];
extern char floor_map_name_acave03_01[];
extern char floor_map_name_acave03_02[];
extern char floor_map_name_acave03_03[];
extern char floor_map_name_acave03_04[];
extern char floor_map_name_acave03_05[];
extern char floor_map_name_amachine01[];
extern char floor_map_name_amachine01_00[];
extern char floor_map_name_amachine01_01[];
extern char floor_map_name_amachine01_02[];
extern char floor_map_name_amachine01_03[];
extern char floor_map_name_amachine01_04[];
extern char floor_map_name_amachine01_05[];
extern char floor_map_name_amachine02[];
extern char floor_map_name_amachine02_00[];
extern char floor_map_name_amachine02_01[];
extern char floor_map_name_amachine02_02[];
extern char floor_map_name_amachine02_03[];
extern char floor_map_name_amachine02_04[];
extern char floor_map_name_amachine02_05[];
extern char floor_map_name_aancient01[];
extern char floor_map_name_aancient01_00[];
extern char floor_map_name_aancient01_01[];
extern char floor_map_name_aancient01_02[];
extern char floor_map_name_aancient01_03[];
extern char floor_map_name_aancient01_04[];
extern char floor_map_name_aancient02[];
extern char floor_map_name_aancient02_00[];
extern char floor_map_name_aancient02_01[];
extern char floor_map_name_aancient02_02[];
extern char floor_map_name_aancient02_03[];
extern char floor_map_name_aancient02_04[];
extern char floor_map_name_aancient03[];
extern char floor_map_name_aancient03_00[];
extern char floor_map_name_aancient03_01[];
extern char floor_map_name_aancient03_02[];
extern char floor_map_name_aancient03_03[];
extern char floor_map_name_aancient03_04[];
extern char floor_map_name_aboss01[];
extern char floor_map_name_aboss02[];
extern char floor_map_name_aboss03[];
extern char floor_map_name_boss08[];
extern char floor_map_name_boss07[];
extern char floor_map_name_boss06[];
extern char floor_map_name_boss05[];
extern char floor_map_name_seabed02_02[];
extern char floor_map_name_seabed02_01[];
extern char floor_map_name_seabed02_00[];
extern char floor_map_name_seabed02[];
extern char floor_map_name_seabed01_02[];
extern char floor_map_name_seabed01_01[];
extern char floor_map_name_seabed01_00[];
extern char floor_map_name_seabed01[];
extern char floor_map_name_jungle07_04[];
extern char floor_map_name_jungle07_03[];
extern char floor_map_name_jungle07_02[];
extern char floor_map_name_jungle07_01[];
extern char floor_map_name_jungle07_00[];
extern char floor_map_name_jungle07[];
extern char floor_map_name_jungle06_00[];
extern char floor_map_name_jungle06[];
extern char floor_map_name_jungle05_00[];
extern char floor_map_name_jungle05[];
extern char floor_map_name_jungle04_02[];
extern char floor_map_name_jungle04_01[];
extern char floor_map_name_jungle04_00[];
extern char floor_map_name_jungle04[];
extern char floor_map_name_jungle03_00[];
extern char floor_map_name_jungle03[];
extern char floor_map_name_jungle02_00[];
extern char floor_map_name_jungle02[];
extern char floor_map_name_jungle01_00[];
extern char floor_map_name_jungle01[];
extern char floor_map_name_ruins02_02[];
extern char floor_map_name_ruins02_01[];
extern char floor_map_name_ruins02_00[];
extern char floor_map_name_ruins02[];
extern char floor_map_name_ruins01_02[];
extern char floor_map_name_ruins01_01[];
extern char floor_map_name_ruins01_00[];
extern char floor_map_name_ruins01[];
extern char floor_map_name_space02_02[];
extern char floor_map_name_space02_01[];
extern char floor_map_name_space02_00[];
extern char floor_map_name_space02[];
extern char floor_map_name_space01_02[];
extern char floor_map_name_space01_01[];
extern char floor_map_name_space01_00[];
extern char floor_map_name_space01[];
extern char floor_map_name_labo00_00[];
extern char floor_map_name_labo00[];
extern char floor_map_name_vs02_02[];
extern char floor_map_name_vs02_01[];
extern char floor_map_name_vs02_00[];
extern char floor_map_name_vs02[];
extern char floor_map_name_vs01_02[];
extern char floor_map_name_vs01_01[];
extern char floor_map_name_vs01_00[];
extern char floor_map_name_vs01[];
extern char floor_map_name_soccer12[];
extern char floor_map_name_soccer11[];
extern char floor_map_name_lobby_green_be00[];
extern char floor_map_name_lobby_yellow_be00[];
extern char floor_map_name_lobby_red_be00[];
extern char floor_map_name_lobby_10[];
extern char floor_map_name_lobby_09[];
extern char floor_map_name_lobby_08[];
extern char floor_map_name_lobby_07[];
extern char floor_map_name_lobby_06[];
extern char floor_map_name_lobby_05[];
extern char floor_map_name_lobby_04[];
extern char floor_map_name_lobby_03[];
extern char floor_map_name_lobby_02[];
extern char floor_map_name_lobby_01[];
extern char floor_map_name_darkfalz00[];
extern char floor_map_name_boss03[];
extern char floor_map_name_boss02[];
extern char floor_map_name_boss01[];
extern char floor_map_name_ancient03_04[];
extern char floor_map_name_ancient03_03[];
extern char floor_map_name_ancient03_02[];
extern char floor_map_name_ancient03_01[];
extern char floor_map_name_ancient03_00[];
extern char floor_map_name_ancient03[];
extern char floor_map_name_ancient02_04[];
extern char floor_map_name_ancient02_03[];
extern char floor_map_name_ancient02_02[];
extern char floor_map_name_ancient02_01[];
extern char floor_map_name_ancient02_00[];
extern char floor_map_name_ancient02[];
extern char floor_map_name_ancient01_04[];
extern char floor_map_name_ancient01_03[];
extern char floor_map_name_ancient01_02[];
extern char floor_map_name_ancient01_01[];
extern char floor_map_name_ancient01_00[];
extern char floor_map_name_ancient01[];
extern char floor_map_name_machine02_05[];
extern char floor_map_name_machine02_04[];
extern char floor_map_name_machine02_03[];
extern char floor_map_name_machine02_02[];
extern char floor_map_name_machine02_01[];
extern char floor_map_name_machine02_00[];
extern char floor_map_name_machine02[];
extern char floor_map_name_machine01_05[];
extern char floor_map_name_machine01_04[];
extern char floor_map_name_machine01_03[];
extern char floor_map_name_machine01_02[];
extern char floor_map_name_machine01_01[];
extern char floor_map_name_machine01_00[];
extern char floor_map_name_machine01[];
extern char floor_map_name_cave03_05[];
extern char floor_map_name_cave03_04[];
extern char floor_map_name_cave03_03[];
extern char floor_map_name_cave03_02[];
extern char floor_map_name_cave03_01[];
extern char floor_map_name_cave03_00[];
extern char floor_map_name_cave03[];
extern char floor_map_name_cave02_04[];
extern char floor_map_name_cave02_03[];
extern char floor_map_name_cave02_02[];
extern char floor_map_name_cave02_01[];
extern char floor_map_name_cave02_00[];
extern char floor_map_name_cave02[];
extern char floor_map_name_cave01_05[];
extern char floor_map_name_cave01_04[];
extern char floor_map_name_cave01_03[];
extern char floor_map_name_cave01_02[];
extern char floor_map_name_cave01_01[];
extern char floor_map_name_cave01_00[];
extern char floor_map_name_cave01[];
extern char floor_map_name_forest02[];
extern char floor_map_name_forest01[];
extern char floor_map_name_city00_00[];
extern char floor_map_name_city00[];
extern "C" {
__declspec(section ".data") const char *lbl_804C8C60[2] = { floor_map_name_city00, floor_map_name_city00_00 };
__declspec(section ".data") const char *lbl_804C8C68[2] = { floor_map_name_forest01, floor_map_name_forest01 };
__declspec(section ".data") const char *lbl_804C8C70[2] = { floor_map_name_forest02, floor_map_name_forest02 };
const char *lbl_804C8C78[12] = { floor_map_name_cave01, floor_map_name_cave01_00, floor_map_name_cave01, floor_map_name_cave01_01, floor_map_name_cave01, floor_map_name_cave01_02, floor_map_name_cave01, floor_map_name_cave01_03, floor_map_name_cave01, floor_map_name_cave01_04, floor_map_name_cave01, floor_map_name_cave01_05 };
const char *lbl_804C8CA8[10] = { floor_map_name_cave02, floor_map_name_cave02_00, floor_map_name_cave02, floor_map_name_cave02_01, floor_map_name_cave02, floor_map_name_cave02_02, floor_map_name_cave02, floor_map_name_cave02_03, floor_map_name_cave02, floor_map_name_cave02_04 };
const char *lbl_804C8CD0[12] = { floor_map_name_cave03, floor_map_name_cave03_00, floor_map_name_cave03, floor_map_name_cave03_01, floor_map_name_cave03, floor_map_name_cave03_02, floor_map_name_cave03, floor_map_name_cave03_03, floor_map_name_cave03, floor_map_name_cave03_04, floor_map_name_cave03, floor_map_name_cave03_05 };
const char *lbl_804C8D00[12] = { floor_map_name_machine01, floor_map_name_machine01_00, floor_map_name_machine01, floor_map_name_machine01_01, floor_map_name_machine01, floor_map_name_machine01_02, floor_map_name_machine01, floor_map_name_machine01_03, floor_map_name_machine01, floor_map_name_machine01_04, floor_map_name_machine01, floor_map_name_machine01_05 };
const char *lbl_804C8D30[12] = { floor_map_name_machine02, floor_map_name_machine02_00, floor_map_name_machine02, floor_map_name_machine02_01, floor_map_name_machine02, floor_map_name_machine02_02, floor_map_name_machine02, floor_map_name_machine02_03, floor_map_name_machine02, floor_map_name_machine02_04, floor_map_name_machine02, floor_map_name_machine02_05 };
const char *lbl_804C8D60[10] = { floor_map_name_ancient01, floor_map_name_ancient01_00, floor_map_name_ancient01, floor_map_name_ancient01_01, floor_map_name_ancient01, floor_map_name_ancient01_02, floor_map_name_ancient01, floor_map_name_ancient01_03, floor_map_name_ancient01, floor_map_name_ancient01_04 };
const char *lbl_804C8D88[10] = { floor_map_name_ancient02, floor_map_name_ancient02_00, floor_map_name_ancient02, floor_map_name_ancient02_01, floor_map_name_ancient02, floor_map_name_ancient02_02, floor_map_name_ancient02, floor_map_name_ancient02_03, floor_map_name_ancient02, floor_map_name_ancient02_04 };
const char *lbl_804C8DB0[10] = { floor_map_name_ancient03, floor_map_name_ancient03_00, floor_map_name_ancient03, floor_map_name_ancient03_01, floor_map_name_ancient03, floor_map_name_ancient03_02, floor_map_name_ancient03, floor_map_name_ancient03_03, floor_map_name_ancient03, floor_map_name_ancient03_04 };
__declspec(section ".data") const char *lbl_804C8DD8[2] = { floor_map_name_boss01, floor_map_name_boss01 };
__declspec(section ".data") const char *lbl_804C8DE0[2] = { floor_map_name_boss02, floor_map_name_boss02 };
__declspec(section ".data") const char *lbl_804C8DE8[2] = { floor_map_name_boss03, floor_map_name_boss03 };
__declspec(section ".data") const char *lbl_804C8DF0[2] = { floor_map_name_darkfalz00, floor_map_name_darkfalz00 };
const char *lbl_804C8DF8[30] = { floor_map_name_lobby_01, floor_map_name_lobby_01, floor_map_name_lobby_02, floor_map_name_lobby_02, floor_map_name_lobby_03, floor_map_name_lobby_03, floor_map_name_lobby_04, floor_map_name_lobby_04, floor_map_name_lobby_05, floor_map_name_lobby_05, floor_map_name_lobby_06, floor_map_name_lobby_06, floor_map_name_lobby_07, floor_map_name_lobby_07, floor_map_name_lobby_08, floor_map_name_lobby_08, floor_map_name_lobby_09, floor_map_name_lobby_09, floor_map_name_lobby_10, floor_map_name_lobby_10, floor_map_name_lobby_red_be00, floor_map_name_lobby_red_be00, floor_map_name_lobby_yellow_be00, floor_map_name_lobby_yellow_be00, floor_map_name_lobby_green_be00, floor_map_name_lobby_green_be00, floor_map_name_soccer11, floor_map_name_soccer11, floor_map_name_soccer12, floor_map_name_soccer12 };
const char *lbl_804C8E70[6] = { floor_map_name_vs01, floor_map_name_vs01_00, floor_map_name_vs01, floor_map_name_vs01_01, floor_map_name_vs01, floor_map_name_vs01_02 };
const char *lbl_804C8E88[6] = { floor_map_name_vs02, floor_map_name_vs02_00, floor_map_name_vs02, floor_map_name_vs02_01, floor_map_name_vs02, floor_map_name_vs02_02 };
__declspec(section ".data") const char *lbl_804C8EA0[2] = { floor_map_name_labo00, floor_map_name_labo00_00 };
const char *lbl_804C8EA8[6] = { floor_map_name_space01, floor_map_name_space01_00, floor_map_name_space01, floor_map_name_space01_01, floor_map_name_space01, floor_map_name_space01_02 };
const char *lbl_804C8EC0[6] = { floor_map_name_space02, floor_map_name_space02_00, floor_map_name_space02, floor_map_name_space02_01, floor_map_name_space02, floor_map_name_space02_02 };
const char *lbl_804C8ED8[6] = { floor_map_name_ruins01, floor_map_name_ruins01_00, floor_map_name_ruins01, floor_map_name_ruins01_01, floor_map_name_ruins01, floor_map_name_ruins01_02 };
const char *lbl_804C8EF0[6] = { floor_map_name_ruins02, floor_map_name_ruins02_00, floor_map_name_ruins02, floor_map_name_ruins02_01, floor_map_name_ruins02, floor_map_name_ruins02_02 };
__declspec(section ".data") const char *lbl_804C8F08[2] = { floor_map_name_jungle01, floor_map_name_jungle01_00 };
__declspec(section ".data") const char *lbl_804C8F10[2] = { floor_map_name_jungle02, floor_map_name_jungle02_00 };
__declspec(section ".data") const char *lbl_804C8F18[2] = { floor_map_name_jungle03, floor_map_name_jungle03_00 };
const char *lbl_804C8F20[6] = { floor_map_name_jungle04, floor_map_name_jungle04_00, floor_map_name_jungle04, floor_map_name_jungle04_01, floor_map_name_jungle04, floor_map_name_jungle04_02 };
__declspec(section ".data") const char *lbl_804C8F38[2] = { floor_map_name_jungle05, floor_map_name_jungle05_00 };
__declspec(section ".data") const char *lbl_804C8F40[2] = { floor_map_name_jungle06, floor_map_name_jungle06_00 };
const char *lbl_804C8F48[10] = { floor_map_name_jungle07, floor_map_name_jungle07_00, floor_map_name_jungle07, floor_map_name_jungle07_01, floor_map_name_jungle07, floor_map_name_jungle07_02, floor_map_name_jungle07, floor_map_name_jungle07_03, floor_map_name_jungle07, floor_map_name_jungle07_04 };
const char *lbl_804C8F70[6] = { floor_map_name_seabed01, floor_map_name_seabed01_00, floor_map_name_seabed01, floor_map_name_seabed01_01, floor_map_name_seabed01, floor_map_name_seabed01_02 };
const char *lbl_804C8F88[6] = { floor_map_name_seabed02, floor_map_name_seabed02_00, floor_map_name_seabed02, floor_map_name_seabed02_01, floor_map_name_seabed02, floor_map_name_seabed02_02 };
__declspec(section ".data") const char *lbl_804C8FA0[2] = { floor_map_name_boss05, floor_map_name_boss05 };
__declspec(section ".data") const char *lbl_804C8FA8[2] = { floor_map_name_boss06, floor_map_name_boss06 };
__declspec(section ".data") const char *lbl_804C8FB0[2] = { floor_map_name_boss07, floor_map_name_boss07 };
__declspec(section ".data") const char *lbl_804C8FB8[2] = { floor_map_name_boss08, floor_map_name_boss08 };
/* {name list, entry count} per floor (inferred) */
struct FloorSceneEntry {
    const char **names;
    s32 count;
};
FloorSceneEntry lbl_804C8FC0[36] = { { lbl_804C8C60, 1 }, { lbl_804C8C68, 1 }, { lbl_804C8C70, 1 }, { lbl_804C8C78, 6 }, { lbl_804C8CA8, 5 }, { lbl_804C8CD0, 6 }, { lbl_804C8D00, 6 }, { lbl_804C8D30, 6 }, { lbl_804C8D60, 5 }, { lbl_804C8D88, 5 }, { lbl_804C8DB0, 5 }, { lbl_804C8DD8, 1 }, { lbl_804C8DE0, 1 }, { lbl_804C8DE8, 1 }, { lbl_804C8DF0, 1 }, { lbl_804C8DF8, 15 }, { lbl_804C8E70, 3 }, { lbl_804C8E88, 3 }, { lbl_804C8EA0, 1 }, { lbl_804C8ED8, 3 }, { lbl_804C8EF0, 3 }, { lbl_804C8EA8, 3 }, { lbl_804C8EC0, 3 }, { lbl_804C8F08, 1 }, { lbl_804C8F10, 1 }, { lbl_804C8F18, 1 }, { lbl_804C8F20, 3 }, { lbl_804C8F38, 1 }, { lbl_804C8F70, 3 }, { lbl_804C8F88, 3 }, { lbl_804C8FA0, 1 }, { lbl_804C8FA8, 1 }, { lbl_804C8FB0, 1 }, { lbl_804C8FB8, 1 }, { lbl_804C8F40, 1 }, { lbl_804C8F48, 5 } };
__declspec(section ".data") const char *lbl_804C90E0[2] = { floor_map_name_acity00, floor_map_name_acity00_00 };
__declspec(section ".data") const char *lbl_804C90E8[2] = { floor_map_name_aforest01, floor_map_name_aforest01 };
__declspec(section ".data") const char *lbl_804C90F0[2] = { floor_map_name_aforest02, floor_map_name_aforest02 };
const char *lbl_804C90F8[12] = { floor_map_name_acave01, floor_map_name_acave01_00, floor_map_name_acave01, floor_map_name_acave01_01, floor_map_name_acave01, floor_map_name_acave01_02, floor_map_name_acave01, floor_map_name_acave01_03, floor_map_name_acave01, floor_map_name_acave01_04, floor_map_name_acave01, floor_map_name_acave01_05 };
const char *lbl_804C9128[10] = { floor_map_name_acave02, floor_map_name_acave02_00, floor_map_name_acave02, floor_map_name_acave02_01, floor_map_name_acave02, floor_map_name_acave02_02, floor_map_name_acave02, floor_map_name_acave02_03, floor_map_name_acave02, floor_map_name_acave02_04 };
const char *lbl_804C9150[12] = { floor_map_name_acave03, floor_map_name_acave03_00, floor_map_name_acave03, floor_map_name_acave03_01, floor_map_name_acave03, floor_map_name_acave03_02, floor_map_name_acave03, floor_map_name_acave03_03, floor_map_name_acave03, floor_map_name_acave03_04, floor_map_name_acave03, floor_map_name_acave03_05 };
const char *lbl_804C9180[12] = { floor_map_name_amachine01, floor_map_name_amachine01_00, floor_map_name_amachine01, floor_map_name_amachine01_01, floor_map_name_amachine01, floor_map_name_amachine01_02, floor_map_name_amachine01, floor_map_name_amachine01_03, floor_map_name_amachine01, floor_map_name_amachine01_04, floor_map_name_amachine01, floor_map_name_amachine01_05 };
const char *lbl_804C91B0[12] = { floor_map_name_amachine02, floor_map_name_amachine02_00, floor_map_name_amachine02, floor_map_name_amachine02_01, floor_map_name_amachine02, floor_map_name_amachine02_02, floor_map_name_amachine02, floor_map_name_amachine02_03, floor_map_name_amachine02, floor_map_name_amachine02_04, floor_map_name_amachine02, floor_map_name_amachine02_05 };
const char *lbl_804C91E0[10] = { floor_map_name_aancient01, floor_map_name_aancient01_00, floor_map_name_aancient01, floor_map_name_aancient01_01, floor_map_name_aancient01, floor_map_name_aancient01_02, floor_map_name_aancient01, floor_map_name_aancient01_03, floor_map_name_aancient01, floor_map_name_aancient01_04 };
const char *lbl_804C9208[10] = { floor_map_name_aancient02, floor_map_name_aancient02_00, floor_map_name_aancient02, floor_map_name_aancient02_01, floor_map_name_aancient02, floor_map_name_aancient02_02, floor_map_name_aancient02, floor_map_name_aancient02_03, floor_map_name_aancient02, floor_map_name_aancient02_04 };
const char *lbl_804C9230[10] = { floor_map_name_aancient03, floor_map_name_aancient03_00, floor_map_name_aancient03, floor_map_name_aancient03_01, floor_map_name_aancient03, floor_map_name_aancient03_02, floor_map_name_aancient03, floor_map_name_aancient03_03, floor_map_name_aancient03, floor_map_name_aancient03_04 };
__declspec(section ".data") const char *lbl_804C9258[2] = { floor_map_name_aboss01, floor_map_name_aboss01 };
__declspec(section ".data") const char *lbl_804C9260[2] = { floor_map_name_aboss02, floor_map_name_aboss02 };
__declspec(section ".data") const char *lbl_804C9268[2] = { floor_map_name_aboss03, floor_map_name_aboss03 };
}
FloorSceneEntry floor_scene_table[36] = { { lbl_804C90E0, 1 }, { lbl_804C90E8, 1 }, { lbl_804C90F0, 1 }, { lbl_804C90F8, 6 }, { lbl_804C9128, 5 }, { lbl_804C9150, 6 }, { lbl_804C9180, 6 }, { lbl_804C91B0, 6 }, { lbl_804C91E0, 5 }, { lbl_804C9208, 5 }, { lbl_804C9230, 5 }, { lbl_804C9258, 1 }, { lbl_804C9260, 1 }, { lbl_804C9268, 1 }, { lbl_804C8DF0, 1 }, { lbl_804C8DF8, 15 }, { lbl_804C8E70, 3 }, { lbl_804C8E88, 3 }, { lbl_804C8EA0, 1 }, { lbl_804C8ED8, 3 }, { lbl_804C8EF0, 3 }, { lbl_804C8EA8, 3 }, { lbl_804C8EC0, 3 }, { lbl_804C8F08, 1 }, { lbl_804C8F10, 1 }, { lbl_804C8F18, 1 }, { lbl_804C8F20, 3 }, { lbl_804C8F38, 1 }, { lbl_804C8F70, 3 }, { lbl_804C8F88, 3 }, { lbl_804C8FA0, 1 }, { lbl_804C8FA8, 1 }, { lbl_804C8FB0, 1 }, { lbl_804C8FB8, 1 }, { lbl_804C8F40, 1 }, { lbl_804C8F48, 5 } };
const char *forest_rel_filename_table[6] = { "SetDataTableOff.rel", "SetDataTableOffUlti.rel", "SetDataTableOn.rel", "SetDataTableOnUlti.rel", "SetDataTable_TGS2001.rel", 0 };
saddr get_floor_scene_table(s32 area);

void TLobby__sub_80207E44(void);

void randomize_adventure_maps(void);

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
    return (saddr)lbl_804C8FC0[area].names;
}


void TLobby::reset_story_select(void* p) { TLobby::reset_story_select(); }
void TLobby__sub_80207F10(void) { TLobby::reset_story_select(); }
void bswap_enemy_set_row(void *arg0);
void bswap_enemy_set_row_fields(void *arg0);
void swap_object_row_endian(void *arg0);
void bswap_object_row_fields(void *arg0);
typedef FloorLifecycleEntry E_80207F80;
typedef FloorLifecycleCallback Fn_80208020;
typedef FloorLifecycleEntry E_80208020;
extern "C" {
void run_floor_cleanup_callbacks__6TLobbyFi(s32 arg0);
s32 bswap_16__FPUs(u16 *, s32);
s32 bswap_32__FPUl(s32 *, s32);

s32 TLobby__sub_80207F30(ObjectSetData *set) {
    s32 r;
    memset(set, 0, sizeof(*set));
    set->object_type = -1;
    r = get_current_floor();
    set->floor = r;
    set->entity_id = 0xFFFF;
    return r;
}

void run_floor_cleanup_callbacks__6TLobbyFi(s32 arg0) {
    E_80207F80 *p = (E_80207F80 *)floor_lifecycle_callback_tables[arg0];
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

void TLobby::update_current_floor() { get_current_floor_area(); ((void (*)(void))run_floor_cleanup_callbacks__6TLobbyFi)(); }
}
s32 run_floor_initialize_callbacks(s32 floor);
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
void bswap_enemy_set_row(void *arg0) {
    bswap_16((u16 *)arg0);
    bswap_enemy_set_row_fields((void *)((void *)((char *)arg0 + 4)));
}

void bswap_enemy_set_row_fields(void *arg0) {
    bswap_16((u16 *)((void *)((char *)arg0 + 2)));
    bswap_16((u16 *)((void *)((char *)arg0 + 4)));
    bswap_16((u16 *)((void *)((char *)arg0 + 12)));
    bswap_16((u16 *)((void *)((char *)arg0 + 8)));
    bswap_16((u16 *)((void *)((char *)arg0 + 10)));
    bswap_32((u32 *)((void *)((char *)arg0 + 16)));
    bswap_32((u32 *)((void *)((char *)arg0 + 20)));
    bswap_32((u32 *)((void *)((char *)arg0 + 24)));
    bswap_32((u32 *)((void *)((char *)arg0 + 28)));
    bswap_32((u32 *)((void *)((char *)arg0 + 32)));
    bswap_32((u32 *)((void *)((char *)arg0 + 36)));
    bswap_32((u32 *)((void *)((char *)arg0 + 40)));
    bswap_32((u32 *)((void *)((char *)arg0 + 44)));
    bswap_32((u32 *)((void *)((char *)arg0 + 48)));
    bswap_32((u32 *)((void *)((char *)arg0 + 52)));
    bswap_32((u32 *)((void *)((char *)arg0 + 56)));
    bswap_16((u16 *)((void *)((char *)arg0 + 60)));
    bswap_16((u16 *)((void *)((char *)arg0 + 62)));
}

void swap_object_row_endian(void *arg0) {
    bswap_16((u16 *)arg0);
    bswap_object_row_fields((void *)((void *)((char *)arg0 + 4)));
}

void bswap_object_row_fields(void *arg0) {
    bswap_16((u16 *)((void *)((char *)arg0 + 2)));
    bswap_16((u16 *)((void *)((char *)arg0 + 6)));
    bswap_16((u16 *)((void *)((char *)arg0 + 8)));
    bswap_32((u32 *)((void *)((char *)arg0 + 12)));
    bswap_32((u32 *)((void *)((char *)arg0 + 16)));
    bswap_32((u32 *)((void *)((char *)arg0 + 20)));
    bswap_32((u32 *)((void *)((char *)arg0 + 24)));
    bswap_32((u32 *)((void *)((char *)arg0 + 28)));
    bswap_32((u32 *)((void *)((char *)arg0 + 32)));
    bswap_32((u32 *)((void *)((char *)arg0 + 36)));
    bswap_32((u32 *)((void *)((char *)arg0 + 40)));
    bswap_32((u32 *)((void *)((char *)arg0 + 44)));
    bswap_32((u32 *)((void *)((char *)arg0 + 48)));
    bswap_32((u32 *)((void *)((char *)arg0 + 52)));
    bswap_32((u32 *)((void *)((char *)arg0 + 56)));
}

MapSetArea *map_set_areas;

extern "C" {


extern s32 game_difficulty_selection;

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
    MapSetModule *temp_r3;
    MapSetArea *areas;
    s32 drop_item_mode;

    forest_rel_set_data_table = 0;
    forest_rel_module = NULL;
    if (forest_rel_work_buffer != NULL) {
        drop_item_mode = TLobby::get_drop_item_mode();
        if (get_resource_file_size(forest_rel_filename_table[drop_item_mode]) <= 0x24B8) {
            temp_r3 = (MapSetModule *)load_relocatable_file(forest_rel_filename_table[drop_item_mode], forest_rel_work_buffer);
            forest_rel_module = temp_r3;
            if (temp_r3 != NULL) {
                areas = temp_r3->areas;
                forest_rel_set_data_table = areas;
                map_set_areas = areas;
            }
        }
    }
}

void TLobby__sub_802083C0(void);

void TLobby__sub_802083C0(void) {
    if (forest_rel_work_buffer != NULL) {
        safe_free(forest_rel_work_buffer);
        forest_rel_work_buffer = NULL;
        forest_rel_module = 0;
        forest_rel_set_data_table = 0;
        map_set_areas = 0;
    }
}
}


struct Pkt_8020857C { u8 hdr[2]; u16 a; s16 b; s16 pad; s16 c; s8 d; s8 e; };

struct Pkt_8020851C {
    u8 cmd;
    u8 size;
    u16 a;
    u16 b;
    u16 pad;
    u16 c;
    u8 d;
    u8 e;
};


void set_destroy_event__6TLobbyFi(int a0);

void TLobby::load_item_data() {
    MapSetModule *temp_r3_2;
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
            temp_r3_2 = (MapSetModule *)load_relocatable_file(forest_rel_filename_table[drop_item_mode], forest_rel_work_buffer);
            forest_rel_module = temp_r3_2;
            if (temp_r3_2 != NULL) {
                areas = temp_r3_2->areas;
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
extern s32 local_client_id;
void send_6x67_wave_trigger_event(s32 arg0);
void send_6x05_wave_set_switch(s16 arg0);
void send_6x05_wave_clear_switch(s32 arg0);
void send_6x67_wave_trigger_event(s32 arg0) {
    G_FloorEvent_6x67 pkt;
    s32 t = wave_event_trigger_count;
    wave_event_trigger_count = t + 1;
    ((void (*)(int, int))set_destroy_event__6TLobbyFi)(1, t);
    pkt.init();
    pkt.header.client_id = 0xFFFF;
    pkt.floor = get_current_floor();
    pkt.event_id = arg0;
    pkt.sender_client_id = local_client_id;
    pkt.send();
}

void send_6x05_wave_clear_switch(s32 arg0) {
    Pkt_8020851C pkt;
    ((G_SwitchStateChanged_6x05 *)(&pkt))->init();
    pkt.b = 0;
    pkt.a = 0xFFFF;
    pkt.c = arg0;
    pkt.d = ((s32 (*)(s32))get_current_floor)(0xFFFF);
    pkt.e = 0;
    ((G_SwitchStateChanged_6x05 *)(&pkt))->send();
}

void send_6x05_wave_set_switch(s16 arg0) {
    Pkt_8020857C pkt;
    ((G_SwitchStateChanged_6x05 *)(&pkt))->init();
    pkt.a = 0xFFFF;
    pkt.b = 0;
    pkt.c = arg0;
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
    s32 sp8;
    s32 temp_r4;

    memcpy(&sp8, (void *)(wave_event_stream_base + wave_event_stream_cursor), 4);
    temp_r4 = wave_event_stream_cursor;
    wave_event_stream_cursor = temp_r4 + 4;
    bswap_32__FPUl(&sp8, temp_r4);
    return sp8;
}

u16 read_stream_u16(void) {
    u16 sp8;
    s32 temp_r4;

    memcpy(&sp8, wave_event_stream_base + wave_event_stream_cursor, 2);
    temp_r4 = wave_event_stream_cursor;
    wave_event_stream_cursor = temp_r4 + 2;
    ((s32 (*)(u16 *, s32))bswap_16__FPUs)(&sp8, temp_r4);
    return sp8;
}

unsigned char read_stream_u8(void);

s32 run_wave_event_actions(void);

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
