#include "types.h"
#include "pso/object/lobby/LobbyPigeonTheme.h"
#include "pso/unk/TLobby.h"

s32 filter_lobby_pigeon_theme(void) {
    s32 filtered_event_theme;

    filtered_event_theme = TLobby::get_filtered_event_theme();
    switch (filtered_event_theme) {
    case 3:
    case 9:
        filtered_event_theme = 3;
        break;
    }
    return filtered_event_theme;
}
