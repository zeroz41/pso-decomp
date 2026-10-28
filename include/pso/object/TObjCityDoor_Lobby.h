#ifndef PSO_OBJECT_TOBJCITYDOOR_LOBBY_H
#define PSO_OBJECT_TOBJCITYDOOR_LOBBY_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjCityDoor_Lobby : public TObjBase {
    virtual ~TObjCityDoor_Lobby();
    virtual void dispatch_lobby_action();
    s32 build_door_collision_triangles();
    void process_lobby_action_14();
    virtual void render();
    virtual void run_task();

    u8 unk_90[0x1C0];

    s32 m_250;
};

typedef char TObjCityDoor_Lobby_size[sizeof(TObjCityDoor_Lobby) == 0x254 ? 1 : -1];
#endif
