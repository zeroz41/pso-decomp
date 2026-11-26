#ifndef PSO_SYSTEM_GAMEMODEQUERIES_H
#define PSO_SYSTEM_GAMEMODEQUERIES_H

#include "types.h"

// Nonzero while a quest runs outside challenge mode (play mode 2).
s32 is_game_quest_active();
s32 is_challenge_quest_active(void);
s32 get_game_play_mode(void);
s32 is_online_ready();
s32 is_camera_ctrl_active();

#endif
