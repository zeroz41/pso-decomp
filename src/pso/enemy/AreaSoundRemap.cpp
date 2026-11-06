#include "pso/enemy/AreaSoundRemap.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/map/FloorArea.h"
#include "pso/misc/TLobby.h"

struct AreaSoundRemapEntry {
    s32 base;
    s32 start;
};

AreaSoundRemapEntry area_sound_remap_table_a[] = {
    { -1, 0 },
    { 0, 0 },
    { 0, 0 },
    { 11, 34 },
    { 11, 34 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { 21, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { 32, 11 },
    { 32, 11 },
    { 32, 11 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { 35, 9 },
    { 43, 17 },
    { 43, 17 },
    { -1, 0 },
    { -1, 0 },
    { 49, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { 57, 8 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
};

AreaSoundRemapEntry area_sound_remap_table_b[] = {
    { -1, 0 },
    { 9, 0 },
    { 9, 0 },
    { 40, 34 },
    { 40, 34 },
    { 0, 11 },
    { 0, 11 },
    { 17, 24 },
    { 17, 24 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { 20, 0 },
    { 31, 14 },
    { 31, 14 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { 27, 41 },
    { 27, 41 },
    { 27, 41 },
    { 0, 0 },
    { 9, 9 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { 41, 0 },
    { 49, 18 },
    { 49, 18 },
    { 49, 18 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { 56, 30 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { 50, 59 },
    { 50, 59 },
    { 50, 59 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { 0, 0 },
    { 0, 0 },
    { 7, 18 },
    { 11, 24 },
    { 0, 7 },
    { 0, 7 },
    { 0, 7 },
    { 15, 33 },
    { 15, 33 },
    { 23, 43 },
    { -1, 0 },
    { -1, 0 },
    { 25, 0 },
    { 25, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { 36, 17 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
    { -1, 0 },
};

s32 TBoss3Volopt::remap_area_sound_id(s32 arg0) {
    s32 masked;
    s32 result;
    s32 area;
    area = get_current_floor_area();
    if (TLobby::get_instance() != 0) {
        if (area != AREA_VR_TEMPLE_ALPHA && area != AREA_VR_TEMPLE_BETA && area != AREA_VR_SPACESHIP_ALPHA && area != AREA_VR_SPACESHIP_BETA && area != AREA_SEASIDE_NIGHT && area != AREA_TOWER) {
            return arg0;
        }
    } else if (area != AREA_BATTLE1 && area != AREA_BATTLE2) {
        return arg0;
    }
    masked = arg0 & 0x8FFFFF00;
    if (TLobby::get_instance() != 0) {
        if (area == AREA_VR_TEMPLE_ALPHA || area == AREA_VR_TEMPLE_BETA) {
            result = 0x3AB42;
        } else if (area == AREA_VR_SPACESHIP_ALPHA || area == AREA_VR_SPACESHIP_BETA) {
            result = 0x4003AB3D;
        } else if (area == AREA_SEASIDE_NIGHT) {
            result = 0x4003B22A;
        } else if (area == AREA_TOWER) {
            result = 0x4003A359;
        }
    } else {
        result = 0x30043;
        result |= masked;
    }
    return result;
}

s32 remap_area_sound_id(s32 arg0, s32 arg1) {
    s32 area;
    s32 base;
    s32 start;
    area = get_current_floor_area();
    if (TLobby::get_instance() != 0) {
        if (area != AREA_VR_TEMPLE_ALPHA && area != AREA_VR_TEMPLE_BETA && area != AREA_VR_SPACESHIP_ALPHA && area != AREA_VR_SPACESHIP_BETA && area != AREA_SEASIDE_NIGHT && area != AREA_TOWER) {
            return arg0;
        }
    } else {
        if (area != AREA_BATTLE1 && area != AREA_BATTLE2) {
            return arg0;
        }
    }
    if ((u32) arg0 == 0x4003B241U) {
        return 0x4003B23E;
    }
    if (((u32) (arg0 & 0xBFFF00FF) >> 16 << 16) != 0x30000) {
        return arg0;
    }
    if (TLobby::get_instance() != 0) {
        base = area_sound_remap_table_b[arg1].base;
    } else {
        base = area_sound_remap_table_a[arg1].base;
    }
    if (base < 0) {
        return arg0;
    }
    if (TLobby::get_instance() != 0) {
        start = area_sound_remap_table_b[arg1].start;
    } else {
        start = area_sound_remap_table_a[arg1].start;
    }
    {
        s32 r = base + (arg0 - start);
        return r | (arg0 & 0x8FFFFF00);
    }
}
