#include "types.h"
#include "pso/unk/TLobby_801A3B84.h"
#include "pso/unk/TLobby.h"
#include "pso/system/scene/TScene.h"

    extern int quest_active_flag;
void TLobby::clear_counter() { quest_active_flag = 0; }

    extern int camera_split_screen_selector;
void TLobby__sub_801A3B90(int a0) { camera_split_screen_selector = a0; }

void TLobby__sub_801A3B98(void) { camera_split_screen_selector = 1; }

    extern int lobby_online_ready_flag;
void TLobby::clear_quest_state() { lobby_online_ready_flag = 0; }

    extern int scene_resource_index;
void TScene::set_scene(int a0) { scene_resource_index = a0; }
