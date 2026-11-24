#include "types.h"
#include <string.h>
#include "pso/unk/TLobby.h"

char lobby_name[0x18] = { 0 };

void receive_lobby_name(char *name) {
    clear_lobby_name();
    strncpy(lobby_name, name, 0x10);
    lobby_name[0x10] = 0;
}
