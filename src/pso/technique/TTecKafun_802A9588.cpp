#include "types.h"
#include "pso/technique/TTecKafun.h"
struct Pair_802A9588 {
    s32 id;
    f32 val;
};

struct VBase_802A9588 { char pad[0x18]; };

struct Target_802A9588 : VBase_802A9588 {
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
    virtual void m21(s32, Pair_802A9588, s32, s32, s32);
};

struct TTecKafun_802A9588 {
    u8 pad0[0x1C];
    s32 f1c;
    u8 pad20[0xEC - 0x20];
    f32 fec;
    u8 padf0[0xF8 - 0xF0];
    s32 ff8;
};


void TTecKafun::vfunc_6(void *target) {
    Pair_802A9588 p;
    p.val = ((TTecKafun_802A9588 *)this)->fec;
    switch (((TTecKafun_802A9588 *)this)->ff8) {
    case 15:
    case 16:
    case 17:
    case 18:
        p.id = 0;
        ((Target_802A9588 *)target)->m21(((TTecKafun_802A9588 *)this)->f1c, p, 0, -1, -1);
        p.id = ((TTecKafun_802A9588 *)this)->ff8;
        ((Target_802A9588 *)target)->m21(((TTecKafun_802A9588 *)this)->f1c, p, 0, -1, -1);
        break;
    default:
        p.id = ((TTecKafun_802A9588 *)this)->ff8;
        ((Target_802A9588 *)target)->m21(((TTecKafun_802A9588 *)this)->f1c, p, 0, -1, -1);
        break;
    }
}

