#ifndef PSO_OBJECT_CITY_CITYDOORS_H
#define PSO_OBJECT_CITY_CITYDOORS_H

#include "types.h"

// --- C functions defined in CityDoors.cpp ---
extern "C" {
s32 TLobby__sub_80182E60(void);
void *TObjCityDoor_Guild__create(void *set);
void *TObjCityDoor_Lobby__create(void *set);
void *TObjCityDoor_Med__create(void *set);
void *TObjCityDoor_Shop__create(void *set);
void *TObjCityDoor_Warp__create(void *set);
int check_phase_e(void *p);
}
// --- end of C functions

#endif
