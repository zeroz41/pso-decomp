#ifndef PSO_SYSTEM_SCENE_OFFLINEGAMESCENE_H
#define PSO_SYSTEM_SCENE_OFFLINEGAMESCENE_H

#include "types.h"
#include "pso/map/FloorResourceCallbacks.h"

void init_offline_game_scene(void);
void dispatch_offline_main_frame(void);
void run_offline_game_frame(void);
void run_offline_transfer_frame(void);
void run_offline_area_transfer(void);
void run_single_view_frame(void);
void run_split_screen_frame(void);

// In split-screen play (game play modes 1 and 2) deletes the four players and creates them
// again from the character select.
void recreate_split_screen_players(void);

// The number of views the screen is split into (1 = full screen).
void set_view_count(int count);
void reset_view_count(void);
// Splits the screen into count views, one camera per player.
void set_split_screen_views(int count);

// Load and release hooks of the offline game scene (see OfflineGameScene.cpp).
extern FloorResourceCallbacks offline_game_scene_callbacks[48];

// Views on screen: 1, or 2 to 4 in a split-screen game (TCameraCtrl::get_view_count).
extern int camera_split_screen_selector;

extern "C" {
void TLobby__sub_801A2DF4(void);
void TLobby__sub_801A2DF8(void);
void TLobby__sub_801A2DFC(void);
}

#endif
