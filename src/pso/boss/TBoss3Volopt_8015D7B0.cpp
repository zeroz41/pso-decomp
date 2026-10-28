#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/unk/TUnk_804B0BB8.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/player/TObjPlayer.h"
#include "pso/map/CurrentArea.h"

extern "C" {
s32 is_any_player_within_radius_xz(f32);
s32 play_sound_effect(s32, void *, s32, s32);
extern s32 enable_v2_features;
extern const f32 lbl_805DB3D4;
extern const f32 lbl_805DB3D8;
void TUnk_804B0BB8::vfunc_17() {
    u8 *arg0 = (u8 *)this;
    if ((*(s32 *)(arg0 + 0xD0) & 1) && is_any_player_within_radius_xz(lbl_805DB3D4) != 0) {
        return;
    }
    *(s32 *)(arg0 + 0xAC) = 3;
    ((TObjCollidable *)arg0)->clear_player_status_flag(0, 8);
    switch ((u32)get_current_area()) {
    case 0:
        break;
    case 3:
    case 4:
    case 5:
        play_sound_effect(0x42807, (u8 *)&this->position, 0, 0);
        break;
    case 6:
    case 7:
        play_sound_effect(0x4004BC01, (u8 *)&this->position, 0, 0);
        break;
    case 8:
    case 9:
    case 10:
        play_sound_effect(0x4004B708, (u8 *)&this->position, 0, 0);
        break;
    case 16:
    case 17:
        if (enable_v2_features == 1) {
            play_sound_effect(0x4004AA0B, (u8 *)&this->position, 0, 0);
        }
        break;
    case 28:
    case 29:
        play_sound_effect(0x4004A80C, (u8 *)&this->position, 0, 0);
        break;
    case 18:
        play_sound_effect(0x42A05, (u8 *)&this->position, 0, 0);
        break;
    }
}
void TUnk_804B0BB8::play_proximity_sound() {
    u8 *arg0 = (u8 *)this;
    if ((*(s32 *)(arg0 + 0xD0) & 1) && is_any_player_within_radius_xz(lbl_805DB3D8) == 1) {
        *(s32 *)(arg0 + 0xAC) = 1;
        ((TObjCollidable *)arg0)->set_indexed_flags(0, 8);
        switch ((u32)get_current_area()) {
        case 3:
        case 4:
        case 5:
            play_sound_effect(0x42807, (u8 *)&this->position, 0, 0);
            break;
        case 6:
        case 7:
            play_sound_effect(0x4004BC01, (u8 *)&this->position, 0, 0);
            break;
        case 8:
        case 9:
        case 10:
            play_sound_effect(0x4004B708, (u8 *)&this->position, 0, 0);
            break;
        case 16:
        case 17:
            if (enable_v2_features == 1) {
                play_sound_effect(0x4004AA0B, (u8 *)&this->position, 0, 0);
            }
            break;
        case 19:
        case 20:
            play_sound_effect(0x4BF0B, (u8 *)&this->position, 0, 0);
            break;
        case 21:
        case 22:
            play_sound_effect(0x4004AA0B, (u8 *)&this->position, 0, 0);
            break;
        case 18:
            play_sound_effect(0x42A04, (u8 *)&this->position, 0, 0);
            break;
        case 28:
        case 29:
            play_sound_effect(0x4004A80C, (u8 *)&this->position, 0, 0);
            break;
        case 0:
            break;
        }
    }
}

}
