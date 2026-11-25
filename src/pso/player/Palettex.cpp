#include "types.h"
#include "pso/player/Palettex.h"
#include "pso/player/PalettexState.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/quest/TQuestThread.h"

PalettexState palettex_states[4];

void run_palettex_callback(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        palettex_states[client_index].run_callback();
    }
}

void set_palettex_callback(u16 client_index, s32 label) {
    if (is_local_client(client_index) != 0) {
        palettex_states[client_index].set_callback_label(label);
    }
}

s32 is_palettex_enabled(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        return palettex_states[client_index].is_enabled();
    }
    return 0;
}

void disable_palettex(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        palettex_states[client_index].disable();
    }
}

void enable_palettex(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        palettex_states[client_index].enable();
    }
}

s32 is_palettex_activated(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        return palettex_states[client_index].is_activated();
    }
    return 0;
}

void restore_palettex(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        palettex_states[client_index].restore();
    }
}

void activate_palettex(u16 client_index) {
    if (is_local_client(client_index) != 0) {
        palettex_states[client_index].activate();
    }
}

s32 is_local_client(u16 client_index) {
    TObjPlayer *player = get_player_by_client_id(client_index);
    if (player == NULL) {
        return 0;
    }
    if (player->is_locally_controlled() != 0) {
        return 1;
    }
    return 0;
}

void reset_client_quest_slot_table() {
    s32 i;
    for (i = 0; i < 4; i++) {
        palettex_states[i].reset();
    }
}

void PalettexState::run_callback() { TQuestThread::create_in_root(get_callback_label()); }

