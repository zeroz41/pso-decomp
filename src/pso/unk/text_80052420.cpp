#include "types.h"
#include "pso/unk/text_80052420.h"
#include "pso/player/TObjPlayer.h"
struct VBase_80052420 { u8 pad[0x18]; };

struct VObj_80052420 : VBase_80052420 {
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
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27();
    virtual void m28();
    virtual void m29();
    virtual void m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual void m39();
    virtual void m40();
    virtual void m41();
    virtual void m42();
    virtual void m43();
    virtual void m44();
    virtual void m45();
    virtual void m46();
    virtual void m47();
    virtual void m48();
    virtual void m49();
    virtual void m50();
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54();
    virtual void m55();
    virtual void m56();
    virtual void m57();
    virtual void m58();
    virtual void m59();
    virtual void m60();
    virtual void m61();
    virtual void m62();
    virtual void m63();
    virtual void m64();
    virtual void m65();
    virtual void m66();
    virtual void m67();
    virtual void m68();
    virtual void m69();
    virtual void m70();
    virtual void m71();
    virtual void m72();
    virtual void m73();
};

extern "C" {
s32 obj_isState2_324__9TObjCharaFv(VObj_80052420 *);
s16 get_actor_hp(VObj_80052420 *);
s32 TBoss4Type3__sub_8005254C(s32);
void send_6x2F_change_player_hp(s32, s32, s16);
VObj_80052420 *get_player_by_client_id(u16);
}
u32 drain_player_hp(s32 id, u32 arg1) {
    u32 n;
    VObj_80052420 *p;
    s32 v;
    n = arg1;
    if ((u16)id == 0xFFFF || (p = get_player_by_client_id(id)) == NULL ||
        TBoss4Type3__sub_8005254C(id) == 0) {
        return 0;
    }
    v = get_actor_hp(p);
    if (v < n) {
        n = v;
    }
    if (obj_isState2_324__9TObjCharaFv(p) != 0) {
        return n;
    }
    v -= n;
    send_6x2F_change_player_hp(0xFFFF, id, v);
    TObjPlayer::calc_photon_blast_charge(p, n);
    p->m73();
    return n;
}
