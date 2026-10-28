#include "types.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/misc/TOKey.h"
#include "pso/map/FloorArea.h"

struct Base_8016A604 { char pad[0x18]; };
struct VObj_8016A604 : Base_8016A604 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
};

extern "C" {
s32 play_sound_effect(int, void *, int, int);
extern s32 enable_v2_features;
void TOKey::vfunc_23() {
    s32 arg0 = (s32)this;
    u32 area;
    area = get_current_floor_area();
    switch (area) {
    case AREA_FOREST1:
    case AREA_FOREST2:
        play_sound_effect(0x4AD0C, (void *)(arg0 + 0x38), 0, 0);
        break;
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_sound_effect(0x42D0B, (void *)(arg0 + 0x38), 0, 0);
        break;
    case AREA_MINE1:
    case AREA_MINE2:
        play_sound_effect(0x4004AD05, (void *)(arg0 + 0x38), 0, 0);
        break;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        play_sound_effect(0x4004AD0C, (void *)(arg0 + 0x38), 0, 0);
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        if ((s32) enable_v2_features == 1) {
            play_sound_effect(0x4004AD03, (void *)(arg0 + 0x38), 0, 0);
            break;
        }
    default:
        break;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x4AD03, (void *)(arg0 + 0x38), 0, 0);
        break;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004AD03, (void *)(arg0 + 0x38), 0, 0);
        break;
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x4AD13, (void *)(arg0 + 0x38), 0, 0);
        break;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4004AD13, (void *)(arg0 + 0x38), 0, 0);
        break;
    case AREA_TOWER:
        play_sound_effect(0x4004AD13, (void *)(arg0 + 0x38), 0, 0);
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4004AD13, (void *)(arg0 + 0x38), 0, 0);
        break;
    }
}

void TBoss3Volopt::call_vt21() {
    struct VObj_8016A604 *o = (struct VObj_8016A604 *)this;
    o->m21();
}
void TOKey::play_activate_sound() {
    u32 area;
    area = get_current_floor_area();
    switch (area) {
    case AREA_FOREST1:
    case AREA_FOREST2:
        switch (this->m_d0) {
        case 0:
            play_sound_effect(0x4C60A, (u8 *)&this->position, 0, 0);
            return;
        case 1:
            play_sound_effect(0x4AD0B, (u8 *)&this->position, 0, 0);
            return;
        }
        break;
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        switch (this->m_d0) {
        case 0:
            play_sound_effect(0x44609, (u8 *)&this->position, 0, 0);
            return;
        case 1:
            play_sound_effect(0x42D0A, (u8 *)&this->position, 0, 0);
            return;
        }
        break;
    case AREA_MINE1:
    case AREA_MINE2:
        switch (this->m_d0) {
        case 0:
            play_sound_effect(0x4004C603, (u8 *)&this->position, 0, 0);
            return;
        case 1:
            play_sound_effect(0x4004AD04, (u8 *)&this->position, 0, 0);
            return;
        }
        break;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        switch (this->m_d0) {
        case 0:
            play_sound_effect(0x4004C60A, (u8 *)&this->position, 0, 0);
            return;
        case 1:
            play_sound_effect(0x4004AD0B, (u8 *)&this->position, 0, 0);
            return;
        }
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        if ((s32) enable_v2_features == 1) {
            switch (this->m_d0) {
            case 0:
                play_sound_effect(0x4004C601, (u8 *)&this->position, 0, 0);
                return;
            case 1:
                play_sound_effect(0x4004AD02, (u8 *)&this->position, 0, 0);
                return;
            }
        }
        break;
    case AREA_VR_TEMPLE_ALPHA:
    case AREA_VR_TEMPLE_BETA:
        play_sound_effect(0x4C601, (u8 *)&this->position, 0, 0);
        return;
    case AREA_VR_SPACESHIP_ALPHA:
    case AREA_VR_SPACESHIP_BETA:
        play_sound_effect(0x4004C601, (u8 *)&this->position, 0, 0);
        return;
    case AREA_CENTRAL_CONTROL_AREA:
    case AREA_JUNGLE_NORTH:
    case AREA_JUNGLE_EAST:
    case AREA_MOUNTAIN:
    case AREA_SEASIDE:
        play_sound_effect(0x4C611, (u8 *)&this->position, 0, 0);
        return;
    case AREA_SEASIDE_NIGHT:
        play_sound_effect(0x4004C611, (u8 *)&this->position, 0, 0);
        return;
    case AREA_TOWER:
        play_sound_effect(0x4004C611, (u8 *)&this->position, 0, 0);
        return;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4004C611, (u8 *)&this->position, 0, 0);
        break;
    }
}

}
