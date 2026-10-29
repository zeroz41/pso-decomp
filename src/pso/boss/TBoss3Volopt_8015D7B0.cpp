#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/FloorArea.h"

extern "C" {
s32 is_any_player_within_radius_xz__13TObjMapObjectFf(f32);
s32 play_sound_effect(s32, void *, s32, s32);
extern s32 enable_v2_features;
extern const f32 lbl_805DB3D4;
extern const f32 lbl_805DB3D8;
void TUnk_804B0BB8::vfunc_17() {
    u8 *arg0 = (u8 *)this;
    if ((*(s32 *)(arg0 + 0xD0) & 1) && is_any_player_within_radius_xz__13TObjMapObjectFf(lbl_805DB3D4) != 0) {
        return;
    }
    *(s32 *)(arg0 + 0xAC) = 3;
    ((TObjCollidable *)arg0)->clear_player_status_flag(0, 8);
    switch ((u32)get_current_floor_area()) {
    case AREA_PIONEER2_EP1:
        break;
    case AREA_CAVE1:
    case AREA_CAVE2:
    case AREA_CAVE3:
        play_sound_effect(0x42807, (u8 *)&this->position, 0, 0);
        break;
    case AREA_MINE1:
    case AREA_MINE2:
        play_sound_effect(0x4004BC01, (u8 *)&this->position, 0, 0);
        break;
    case AREA_RUINS1:
    case AREA_RUINS2:
    case AREA_RUINS3:
        play_sound_effect(0x4004B708, (u8 *)&this->position, 0, 0);
        break;
    case AREA_BATTLE1:
    case AREA_BATTLE2:
        if (enable_v2_features == 1) {
            play_sound_effect(0x4004AA0B, (u8 *)&this->position, 0, 0);
        }
        break;
    case AREA_SEABED_UPPER:
    case AREA_SEABED_LOWER:
        play_sound_effect(0x4004A80C, (u8 *)&this->position, 0, 0);
        break;
    case AREA_PIONEER2_EP2:
        play_sound_effect(0x42A05, (u8 *)&this->position, 0, 0);
        break;
    }
}
void TUnk_804B0BB8::play_proximity_sound() {
    u8 *arg0 = (u8 *)this;
    if ((*(s32 *)(arg0 + 0xD0) & 1) && is_any_player_within_radius_xz__13TObjMapObjectFf(lbl_805DB3D8) == 1) {
        *(s32 *)(arg0 + 0xAC) = 1;
        ((TObjCollidable *)arg0)->set_indexed_flags(0, 8);
        switch ((u32)get_current_floor_area()) {
        case AREA_CAVE1:
        case AREA_CAVE2:
        case AREA_CAVE3:
            play_sound_effect(0x42807, (u8 *)&this->position, 0, 0);
            break;
        case AREA_MINE1:
        case AREA_MINE2:
            play_sound_effect(0x4004BC01, (u8 *)&this->position, 0, 0);
            break;
        case AREA_RUINS1:
        case AREA_RUINS2:
        case AREA_RUINS3:
            play_sound_effect(0x4004B708, (u8 *)&this->position, 0, 0);
            break;
        case AREA_BATTLE1:
        case AREA_BATTLE2:
            if (enable_v2_features == 1) {
                play_sound_effect(0x4004AA0B, (u8 *)&this->position, 0, 0);
            }
            break;
        case AREA_VR_TEMPLE_ALPHA:
        case AREA_VR_TEMPLE_BETA:
            play_sound_effect(0x4BF0B, (u8 *)&this->position, 0, 0);
            break;
        case AREA_VR_SPACESHIP_ALPHA:
        case AREA_VR_SPACESHIP_BETA:
            play_sound_effect(0x4004AA0B, (u8 *)&this->position, 0, 0);
            break;
        case AREA_PIONEER2_EP2:
            play_sound_effect(0x42A04, (u8 *)&this->position, 0, 0);
            break;
        case AREA_SEABED_UPPER:
        case AREA_SEABED_LOWER:
            play_sound_effect(0x4004A80C, (u8 *)&this->position, 0, 0);
            break;
        case AREA_PIONEER2_EP1:
            break;
        }
    }
}

}
