#include "types.h"
#include "pso/misc/TODummyKeyCave01.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/FloorArea.h"
typedef struct Pair_80165940 { u32 a; u32 b; } Pair_80165940;

typedef struct Key_80165940 {
    u8 pad0[0x34];
    void *f34;
    u8 pad38[0x84 - 0x38];
    u32 f84;
    u32 f88;
    u32 f8C;
    u32 f90;
    u32 f94;
    u16 f98;
    u16 f9A;
    u8 pad9C[0xBC - 0x9C];
    s32 fBC;
    s32 fC0;
    s32 fC4;
    s32 fC8;
    u8 padCC[4];
    s32 fD0;
} Key_80165940;

extern "C" {
u8 is_current_floor_switch_set(u16);
void *get_bml_model(void *, s32);
extern void *TOKeyAncient03__model_archive;
extern Pair_80165940 *TOKeyAncient03__texture_variants;
extern void *TOKeyCave01__resource_bundle;
extern Pair_80165940 *TOKeyCave01__texture_lists;
extern void *key_machine_model_archive;
extern Pair_80165940 *TOKeyMachine01__texture_lists;
void TODummyKeyCave01::sub_80165940() {
    Key_80165940 *self = (Key_80165940 *)this;
    self->fD0 = 0;
    self->f98 = self->f84;
    if (self->f98 < 0x100) {
        self->f9A = is_current_floor_switch_set(self->f98);
    } else {
        self->f98 = 0xFFFF;
        self->f9A = 1;
    }
    self->fBC = self->f88 & 0xFFFF;
    self->fC8 = self->f88 >> 16;
    self->fC0 = self->f8C & 0xFFFF;
    if (self->fC0 > 6) {
        self->fC0 = 0;
    }
    self->fC4 = self->f8C >> 16;
    if (self->fC4 > 1) {
        self->fC4 = 0;
    }
    switch (get_current_floor_area()) {
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        self->f34 = get_bml_model(TOKeyCave01__resource_bundle, 0);
        self->f90 = TOKeyCave01__texture_lists->a;
        self->f94 = TOKeyCave01__texture_lists->b;
        break;
    case AREA_FOREST1:
    case AREA_FOREST2:
    case AREA_MINE1:
    case AREA_MINE2:
        self->f34 = get_bml_model(key_machine_model_archive, 0);
        self->f90 = TOKeyMachine01__texture_lists->a;
        self->f94 = TOKeyMachine01__texture_lists->b;
        break;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        self->f34 = get_bml_model(TOKeyAncient03__model_archive, 0);
        self->f90 = TOKeyAncient03__texture_variants->a;
        self->f94 = TOKeyAncient03__texture_variants->b;
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        if (self->fBC == 0) {
            self->f34 = get_bml_model(TOKeyCave01__resource_bundle, 0);
            self->f90 = TOKeyCave01__texture_lists->a;
            self->f94 = TOKeyCave01__texture_lists->b;
        } else {
            self->f34 = get_bml_model(key_machine_model_archive, 0);
            self->f90 = TOKeyMachine01__texture_lists->a;
            self->f94 = TOKeyMachine01__texture_lists->b;
        }
        break;
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
    case AREA_SEASIDE_NIGHT:
    case AREA_TOWER:
        self->f34 = get_bml_model(TOKeyCave01__resource_bundle, 0);
        self->f90 = TOKeyCave01__texture_lists->a;
        self->f94 = TOKeyCave01__texture_lists->b;
        self->fD0 = 1;
        break;
    default:
        self->f34 = 0;
        self->f90 = 0;
        self->f94 = 0;
        break;
    }
}

}
