#ifndef PSO_SYSTEM_SCENE_ONLINELOBBYSCENE_H
#define PSO_SYSTEM_SCENE_ONLINELOBBYSCENE_H

#include "types.h"

void run_online_lobby_scene(void);
void cleanup_online_lobby_scene(void);
void send_and_handle();
void blocking_vsync();
void start_udp_test_game();
void update_camera_state();

// Set when the player leaves the lobby floor; the lobby scene reloads the floor while it is 1.
extern s16 lobby_floor_reload_pending;

#endif
