#ifndef PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801C50A8_H
#define PSO_UI_FRONTEND_TADSINGLEPLYCHRSELECTGC_801C50A8_H

#include "types.h"

extern "C" {
void set_active_fourth_place_count(int value);
u16 get_active_fourth_place_count(void);
void set_active_third_place_count(int value);
u16 get_active_third_place_count(void);
void set_active_second_place_count(int value);
u16 get_active_second_place_count(void);
void set_active_first_place_count(int value);
u16 get_active_first_place_count(void);
void clear_duel_result_window(void);
void clear_battle_proximity_sound(void);
}

#endif
