#ifndef PSO_OBJECT_CITY_CITYDOORS_H
#define PSO_OBJECT_CITY_CITYDOORS_H

#include "types.h"

// --- C functions defined in CityDoors.cpp ---
extern "C" {
s32 TLobby__sub_80182E60(void);
void *TObjCityDoor_Guild__create(void *set);
void *TObjCityDoor_Guild__ct(void *o, void *parent, void *set);
u8 *TObjCityDoor_Lobby__create(s32 arg0);
void *TObjCityDoor_Med__create(void *set);
void *TObjCityDoor_Med__ct(void *o, void *parent, void *set);
void *TObjCityDoor_Shop__create(void *arg0);
u8 *TObjCityDoor_Shop__ct(u8 *city_door_shop, s32 arg1, s32 arg2);
void *TObjCityDoor_Warp__create(void *set);
void *TObjCityDoor_Warp__ct(void *o, void *parent, void *set);
void *TObjPlayer__sub_80182D24(void *arg0, s16 arg1);
u8 *__dt__18TObjCityDoor_LobbyFPvs(u8 *arg0, s16 arg1);
void *dt__16TObjCityDoor_MedFPvs(void *arg0, s16 arg1);
void *dt__17TObjCityDoor_ShopFPvs(void *arg0, s16 arg1);
void *dt__17TObjCityDoor_WarpFPvs(void *arg0, s16 arg1);
void *dt__18TObjCityDoor_GuildFPvs(void *arg0, s16 arg1);
int check_phase_e(void *p);
}
// --- end of C functions

#endif
