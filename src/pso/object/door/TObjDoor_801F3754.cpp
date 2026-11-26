#include "types.h"
#include "pso/object/door/TObjDoor_801F3754.h"
#include "pso/object/door/TObjDoor.h"
#include "pso/object/door/TODoorBase.h"
#include "pso/object/warp/TObjCityMainWarp.h"

void enable_door_masterkey(void) {
    door_masterkey_on = 1;
}

void force_switch_doors_closed(void) { switch_doors_force_closed = 1; }

void TObjDoor::set_main_warp_id(int main_warp_id) { city_main_warp_destination_id = main_warp_id; }
