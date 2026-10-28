#include "types.h"
#include "pso/misc/TObjEneMe1Gee_NEEDLE.h"
#include "pso/misc/TNeedleShoot_802A4754.h"
#include "pso/misc/TNeedleShoot_802A4A44.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TNeedleShoot.h"
#include "pso/map/FloorArea.h"


struct VBase_18_174c10 { char pad[0x18]; };

struct VObj_18_174c10 : VBase_18_174c10 {
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
    virtual s32 m21(s32, void *, s32, s32, s32);
};

struct Pair_802A4AEC { s32 a; f32 b; };

extern "C" {
s32 play_sound_effect(int, void *, int, int);

void*TNeedleShoot::get_shoot_data() { return (char*)this + 0x28; }


extern "C" {

int TObjEneMe1Gee_NEEDLE::queue_destruction() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    temp_r0 = this->m_c0 - 1;
    this->m_c0 = temp_r0;
    if (temp_r0 <= 0) {
        queue_destruction__7TObjectFv(arg0);
    }
}

int TObjEneMe1Gee_NEEDLE::vfunc_6() {
    if (get_current_floor_area() == AREA_SEASIDE_NIGHT) {
        play_sound_effect(0x4003B20E, (u8 *)&this->m_6c, 0, 0);
    } else {
        play_sound_effect(0x3A847, (u8 *)&this->m_6c, 0, 0);
    }
    this->m_b8 = 0;
}

}


void TObjEneMe1Gee_NEEDLE::vfunc_9(void *arg1_arg) {
    u8 *arg0 = (u8 *)this;
    VObj_18_174c10 *arg1 = (VObj_18_174c10 *)arg1_arg;
    Pair_802A4AEC t;
    t.a = 0;
    t.b = *(f32 *)(arg0 + 0xBC);
    Pair_802A4AEC u = t;
    arg1->m21(*(s32 *)(arg0 + 0x1C), &u, *(s32 *)(arg0 + 0x38), -1, -1);
    queue_destruction__7TObjectFv((arg0));
}

}
TObjEneMe1Gee_NEEDLE::~TObjEneMe1Gee_NEEDLE() {

}
