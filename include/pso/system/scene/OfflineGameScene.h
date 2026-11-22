#ifndef PSO_SYSTEM_SCENE_OFFLINEGAMESCENE_H
#define PSO_SYSTEM_SCENE_OFFLINEGAMESCENE_H

#include "types.h"

void init_offline_game_scene(void);
void dispatch_offline_main_frame(void);

// Views on screen: 1, or 2 to 4 in a split-screen game (TCameraCtrl::get_view_count).
extern int camera_split_screen_selector;

extern "C" {
void TLobby__sub_801A2DF4(void);
void TLobby__sub_801A2DF8(void);
void TLobby__sub_801A2DFC(void);
void TLobby__sub_801A2E00(void);
void TLobby__sub_801A3B90(int a0);
void TLobby__sub_801A3B98(void);
}

#endif
