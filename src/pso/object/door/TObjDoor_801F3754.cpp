#include "types.h"
#include "pso/object/door/TObjDoor_801F3754.h"
#include "pso/object/door/TObjDoor.h"

extern s32 TObjDoor__data_805D5BC8;

void TObjDoor__sub_801F3754(void) {
    TObjDoor__data_805D5BC8 = 1;
}

    extern int switch_doors_force_closed;
void TObjDoor__sub_801F3760(void) { switch_doors_force_closed = 1; }

    extern int city_main_warp_destination_id;
void TObjDoor::set_main_warp_id(int a0) { city_main_warp_destination_id = a0; }
