#ifndef PSO_PLAYER_PLAYERREF_H
#define PSO_PLAYER_PLAYERREF_H
#include "types.h"

struct TObjPlayer;

// A player looked up by client id, embedded at +0x1C in TForceOperate and the lock-on cursor tasks. The
// ctor sets both ids to 0xFFFF and clears the player; the owners' ctors then store the client id with
// set_client_id. resolve looks the player with that client id up, keeps it in `player` and returns
// whether it exists.
class PlayerRef {
public:
    PlayerRef();
    ~PlayerRef();
    void set_client_id(u16 id);
    u16 get_client_id();
    TObjPlayer *get_player();
    BOOL resolve();

    u16 client_id;
    u16 reserved;
    TObjPlayer *player;
};
LAYOUT_ASSERT(PlayerRef_size, sizeof(PlayerRef) == 0x8);

#endif
