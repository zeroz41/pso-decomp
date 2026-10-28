#ifndef PSO_MAP_FLOORAREA_H
#define PSO_MAP_FLOORAREA_H

#include "types.h"

enum floor_area {
    AREA_PIONEER2_EP1         = 0x00,
    AREA_FOREST1              = 0x01,
    AREA_FOREST2              = 0x02,
    AREA_CAVE1                = 0x03,
    AREA_CAVE2                = 0x04,
    AREA_CAVE3                = 0x05,
    AREA_MINE1                = 0x06,
    AREA_MINE2                = 0x07,
    AREA_RUINS1               = 0x08,
    AREA_RUINS2               = 0x09,
    AREA_RUINS3               = 0x0A,
    AREA_DRAGON               = 0x0B,
    AREA_DE_ROL_LE            = 0x0C,
    AREA_VOL_OPT              = 0x0D,
    AREA_DARK_FALZ            = 0x0E,
    AREA_LOBBY                = 0x0F,
    AREA_BATTLE1              = 0x10, // Spaceship
    AREA_BATTLE2              = 0x11, // Palace
    AREA_PIONEER2_EP2         = 0x12, // Lab
    AREA_VR_TEMPLE_ALPHA      = 0x13,
    AREA_VR_TEMPLE_BETA       = 0x14,
    AREA_VR_SPACESHIP_ALPHA   = 0x15,
    AREA_VR_SPACESHIP_BETA    = 0x16,
    AREA_CENTRAL_CONTROL_AREA = 0x17,
    AREA_JUNGLE_NORTH         = 0x18,
    AREA_JUNGLE_EAST          = 0x19,
    AREA_MOUNTAIN             = 0x1A,
    AREA_SEASIDE              = 0x1B,
    AREA_SEABED_UPPER         = 0x1C,
    AREA_SEABED_LOWER         = 0x1D,
    AREA_GAL_GRYPHON          = 0x1E,
    AREA_OLGA_FLOW            = 0x1F,
    AREA_BARBA_RAY            = 0x20,
    AREA_GOL_DRAGON           = 0x21,
    AREA_SEASIDE_NIGHT        = 0x22,
    AREA_TOWER                = 0x23,
};

s32 is_warp_excluded_area(s32 area);
s32 is_boss_area();
void set_current_floor_area(s32 floor);
floor_area get_current_floor_area();
s32 is_current_area_item_enabled();
s32 is_central_control_area();

#endif
