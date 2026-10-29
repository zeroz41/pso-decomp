#include "types.h"
#include "pso/enemy/TObjEneRecon_8031F600.h"
#include "pso/enemy/TObjEneDD.h"

struct Base_8031F600 { char pad[0x18]; };
struct VObj_8031F600 : Base_8031F600 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
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
    virtual void m92(); virtual void m93(); virtual void m94(s32);
    virtual void m95(); virtual void m96(); virtual void m97();
    virtual void m98(); virtual void m99(); virtual void m100(); virtual void m101();
    virtual s32 m102(f32);
};

extern "C" {

s32 advance_animation_playback();
s32 TObjEneRecon__sub_8031FACC(void *);

extern const f32 TObjEneRecon__data_805DF438;

void TObjEneRecon__sub_8031F600(void *ene_dd, s32 arg1) {
    s32 temp_r4;

    switch (arg1) {
    case 4:
        temp_r4 = *(s32 *)((s8 *)ene_dd + 0x40C) & 0xFFFFFFFE;
        *(s32 *)((s8 *)ene_dd + 0x40C) = temp_r4;
        ((TObjEneDD *)ene_dd)->requested_action = 0;
        ((VObj_8031F600 *)ene_dd)->m94(temp_r4);
        ((TObjEneDD *)ene_dd)->set_field_378(2);
        return;
    case 3:
        if ((((VObj_8031F600 *)ene_dd)->m102(TObjEneRecon__data_805DF438) != 0) && (TObjEneRecon__sub_8031FACC(ene_dd) != 0)) {
            ((TObjEneDD *)ene_dd)->transition_enemy_state(3);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback();
        break;
    }
}

}
