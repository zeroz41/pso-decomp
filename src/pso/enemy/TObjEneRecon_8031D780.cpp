#include "types.h"
#include "pso/enemy/TObjEneRecon_8031D780.h"
#include "pso/misc/TOTrapAncient01_80226534.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneRecon.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneRecobox.h"

struct Base_8031D780 { char pad[0x18]; };
struct VObj_8031D780 : Base_8031D780 {
    virtual void m0();  virtual void m1();  virtual void m2();  virtual void m3();
    virtual void m4();  virtual void m5();  virtual void m6();  virtual void m7();
    virtual void m8();  virtual void m9();  virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
    virtual void m28(); virtual void m29(); virtual void m30(); virtual void m31();
    virtual void m32(); virtual void m33(); virtual void m34(); virtual void m35();
    virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43();
    virtual void m44(); virtual void m45(); virtual void m46(); virtual void m47();
    virtual void m48(); virtual void m49(); virtual void m50(); virtual void m51();
    virtual void m52(); virtual void m53(); virtual void m54(); virtual void m55();
    virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63();
    virtual void m64(); virtual void m65(); virtual void m66(); virtual void m67();
    virtual void m68(); virtual void m69(); virtual void m70(); virtual void m71();
    virtual void m72(); virtual void m73(); virtual void m74(); virtual void m75();
    virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83();
    virtual void m84(); virtual void m85(); virtual void m86(); virtual void m87();
    virtual void m88(); virtual void m89(); virtual void m90(); virtual void m91();
    virtual void m92(); virtual void m93(); virtual void m94(); virtual void m95();
    virtual void m96(); virtual s32 m97();
};

extern "C" {

s32 select_nearest_target__12TObjEneDD_STFf(void *, f32);

s32 TObjEneRecon::vfunc_104(f32 farg0) {
    if (((VObj_8031D780 *)this)->m97() != 0) {
        ((TObjEneDD_ST *)this)->select_and_apply_target(farg0);
        return;
    }
    select_nearest_target__12TObjEneDD_STFf(this, farg0);
}

void TObjEneRecon::spawn_trap_a() {
    s32 arg0 = (s32)this;
    play_persistent_sound((TObjEneRecobox::remap_area_sound_id(0x4003AD07)), (arg0), (arg0 + 0x38), 0, 0);
}

void TObjEneRecon::spawn_trap_b() {
    s32 arg0 = (s32)this;
    play_persistent_sound((TObjEneRecobox::remap_area_sound_id(0x4003B206)), (arg0), (arg0 + 0x38), 0, 0);
}

u16 TObjEneRecon__sub_8031D878(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x474) != 0) {
        return *(u16 *)((s8 *)arg0 + 0x38C);
    }
    return 0xFFFFU;
}

}
