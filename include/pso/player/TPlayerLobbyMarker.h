#ifndef PSO_PLAYER_TPLAYERLOBBYMARKER_H
#define PSO_PLAYER_TPLAYERLOBBYMARKER_H
#include "pso/system/task/TObject.h"
struct TObjPlayer;
class TPlayerLobbyMarker : public TObject {
public:
    TPlayerLobbyMarker(TObject*, s16, s8);
    virtual ~TPlayerLobbyMarker() {}
    virtual void run_task();
    virtual void render();
    u8 get_material_index();
    u8 material_index;
    u8 flags;
    u16 player_id;
    s32 rotation;
public:
    void set_material_index(u8 v);
};
typedef char LobbyMarker_size[sizeof(TPlayerLobbyMarker) == 0x24 ? 1 : -1];
#endif
