#ifndef PSO_OBJECT_LOBBY_TOBJCITYDOOR_LOBBY_H
#define PSO_OBJECT_LOBBY_TOBJCITYDOOR_LOBBY_H

#include "types.h"
#include "pso/map/CsnGeometry.h"
#include "pso/object/base/TObjMotion.h"

struct TObjCityDoor_Lobby : public TObjBase {
    TObjCityDoor_Lobby(TObject *parent, void *set);
    virtual ~TObjCityDoor_Lobby();
    virtual void dispatch_lobby_action();
    void build_door_collision_triangles();
    void process_lobby_action_14();
    virtual void render();
    virtual void run_task();

    CsnGroup collision_group;
    CsnModel collision_model;
    CsnFace collision_faces[8];
    Vec collision_vertices[10];

    s32 collision_registered;  // collision_group is in the map's collision controller
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjCityDoorLobbyGroupOffset, offsetof(TObjCityDoor_Lobby, collision_group) == 0x90);
LAYOUT_ASSERT(TObjCityDoorLobbyModelOffset, offsetof(TObjCityDoor_Lobby, collision_model) == 0xA8);
LAYOUT_ASSERT(TObjCityDoorLobbyFacesOffset, offsetof(TObjCityDoor_Lobby, collision_faces) == 0xB8);
LAYOUT_ASSERT(TObjCityDoorLobbyVerticesOffset, offsetof(TObjCityDoor_Lobby, collision_vertices) == 0x1D8);

LAYOUT_ASSERT(TObjCityDoor_Lobby_size, sizeof(TObjCityDoor_Lobby) == 0x254);
#endif
