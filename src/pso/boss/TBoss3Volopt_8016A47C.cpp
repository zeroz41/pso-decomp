#include "types.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/misc/TOKey.h"
#include "pso/misc/TOKeyMachine01.h"
#include "pso/map/CurrentArea.h"

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
    u32 global_state;
    global_state = get_current_area();
    switch (global_state) {
    case 1:
    case 2:
        play_sound_effect(0x4AD0C, (void *)(arg0 + 0x38), 0, 0);
        break;
    case 3:
    case 4:
    case 5:
        play_sound_effect(0x42D0B, (void *)(arg0 + 0x38), 0, 0);
        break;
    case 6:
    case 7:
        play_sound_effect(0x4004AD05, (void *)(arg0 + 0x38), 0, 0);
        break;
    case 8:
    case 9:
    case 10:
        play_sound_effect(0x4004AD0C, (void *)(arg0 + 0x38), 0, 0);
        break;
    case 16:
    case 17:
        if ((s32) enable_v2_features == 1) {
            play_sound_effect(0x4004AD03, (void *)(arg0 + 0x38), 0, 0);
            break;
        }
    default:
        break;
    case 19:
    case 20:
        play_sound_effect(0x4AD03, (void *)(arg0 + 0x38), 0, 0);
        break;
    case 21:
    case 22:
        play_sound_effect(0x4004AD03, (void *)(arg0 + 0x38), 0, 0);
        break;
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
        play_sound_effect(0x4AD13, (void *)(arg0 + 0x38), 0, 0);
        break;
    case 34:
        play_sound_effect(0x4004AD13, (void *)(arg0 + 0x38), 0, 0);
        break;
    case 35:
        play_sound_effect(0x4004AD13, (void *)(arg0 + 0x38), 0, 0);
        break;
    case 28:
    case 29:
        play_sound_effect(0x4004AD13, (void *)(arg0 + 0x38), 0, 0);
        break;
    }
}

void TBoss3Volopt::call_vt21() {
    struct VObj_8016A604 *o = (struct VObj_8016A604 *)this;
    o->m21();
}
void TOKey::play_activate_sound() {
    u32 global_state;
    global_state = get_current_area();
    switch (global_state) {
    case 1:
    case 2:
        switch (this->m_d0) {
        case 0:
            play_sound_effect(0x4C60A, (u8 *)&this->position, 0, 0);
            return;
        case 1:
            play_sound_effect(0x4AD0B, (u8 *)&this->position, 0, 0);
            return;
        }
        break;
    case 3:
    case 4:
    case 5:
        switch (this->m_d0) {
        case 0:
            play_sound_effect(0x44609, (u8 *)&this->position, 0, 0);
            return;
        case 1:
            play_sound_effect(0x42D0A, (u8 *)&this->position, 0, 0);
            return;
        }
        break;
    case 6:
    case 7:
        switch (this->m_d0) {
        case 0:
            play_sound_effect(0x4004C603, (u8 *)&this->position, 0, 0);
            return;
        case 1:
            play_sound_effect(0x4004AD04, (u8 *)&this->position, 0, 0);
            return;
        }
        break;
    case 8:
    case 9:
    case 10:
        switch (this->m_d0) {
        case 0:
            play_sound_effect(0x4004C60A, (u8 *)&this->position, 0, 0);
            return;
        case 1:
            play_sound_effect(0x4004AD0B, (u8 *)&this->position, 0, 0);
            return;
        }
        break;
    case 16:
    case 17:
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
    case 19:
    case 20:
        play_sound_effect(0x4C601, (u8 *)&this->position, 0, 0);
        return;
    case 21:
    case 22:
        play_sound_effect(0x4004C601, (u8 *)&this->position, 0, 0);
        return;
    case 23:
    case 24:
    case 25:
    case 26:
    case 27:
        play_sound_effect(0x4C611, (u8 *)&this->position, 0, 0);
        return;
    case 34:
        play_sound_effect(0x4004C611, (u8 *)&this->position, 0, 0);
        return;
    case 35:
        play_sound_effect(0x4004C611, (u8 *)&this->position, 0, 0);
        return;
    case 28:
    case 29:
        play_sound_effect(0x4004C611, (u8 *)&this->position, 0, 0);
        break;
    }
}

}
