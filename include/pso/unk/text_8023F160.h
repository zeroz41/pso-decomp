#ifndef PSO_UNK_TEXT_8023F160_H
#define PSO_UNK_TEXT_8023F160_H

#include "types.h"

// Defined in TAdMultiChgGameModeGC_8023E7A8.cpp. The unload/load pair runs the lobby
// scene hook table (unload halves in reverse, then the load halves): the options and
// time-set screens call it after a language change.
extern "C" {
void unload_lobby_scene_resources(void);
void load_lobby_scene_resources(void);
void init_game_mode_select_scene(void);
}

#endif
