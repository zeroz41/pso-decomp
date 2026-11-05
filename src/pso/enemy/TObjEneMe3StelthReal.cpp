#include "types.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneMe3Stelth.h"
#include "pso/enemy/TObjEneMe3StelthReal.h"

struct VBase_18_be4a70 { char pad[0x18]; };

struct VObj_18_be4a70 : VBase_18_be4a70 {
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
    virtual void m74();
    virtual void m75();
    virtual void m76();
    virtual void m77();
    virtual void m78();
    virtual void m79();
    virtual void m80();
    virtual void m81();
    virtual void m82();
    virtual void m83();
    virtual void m84();
    virtual s32 m85(s16, s32);
};

extern "C" {
s32 invoke_initialization_hook__9TObjEneDDFPv(void *, void *);
void *TObjEneMe3Stelth__ct(void *arg0);
extern s32 __vt__20TObjEneMe3StelthReal[];
extern s32 lbl_805D2AFC;
u8 *TObjEneMe3StelthReal__ct(TObjEneMe3StelthReal *arg0, s32 arg1, s32 arg2);
typedef struct EneStelth_800F0CE8 EneStelth_800F0CE8;

void *__dt__20TObjEneMe3StelthRealFv(void *arg0, s16 arg1);
int vfunc_62__16TObjEneMe3StelthFv(void*);
int vfunc_63__16TObjEneMe3StelthFv(void*);
void __dl__7TObjectFPv(void *);
void *__dt__16TObjEneMe3StelthFv(void *arg0, s16 arg1);
void *__nw__7TObjectFUl(int);

void TObjEneMe3StelthReal::vfunc_111() {  }

extern const f32 lbl_805DA81C;

void TObjEneMe3StelthReal::vfunc_107() {
    EneStelth_800F0CE8 *self = (EneStelth_800F0CE8 *)this;
    *(s32 *)((s8 *)this + 0x3EC) = *(s32 *)((s8 *)this + 0x3EC) + 1;
    if ((*(s32 *)((s8 *)this + 0x3EC) >= 2) || (random_ratio() < lbl_805DA81C)) {
        ((TObjEneDD *)self)->transition_enemy_state(9);
        return;
    }
    ((TObjEneDD *)self)->transition_enemy_state(6);
}

void TObjEneMe3StelthReal::vfunc_62() { vfunc_62__16TObjEneMe3StelthFv(this); }
void TObjEneMe3StelthReal::vfunc_63() { vfunc_63__16TObjEneMe3StelthFv(this); }

void *__dt__20TObjEneMe3StelthRealFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__20TObjEneMe3StelthReal;
        __dt__16TObjEneMe3StelthFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *tl_04;

u8 *TObjEneMe3StelthReal__ct(TObjEneMe3StelthReal *ene_me3_stelth_real, s32 arg1, s32 arg2) {
    TObjEneMe3Stelth__ct(ene_me3_stelth_real);
    *(s32 **)((s8 *)ene_me3_stelth_real + 0x18) = __vt__20TObjEneMe3StelthReal;
    *(s32 *)((s8 *)ene_me3_stelth_real + 0) = (s32) lbl_805D2AFC;
    invoke_initialization_hook__9TObjEneDDFPv((void *)ene_me3_stelth_real, (void *)arg2);
    ((TObjEneMe3Stelth *)ene_me3_stelth_real)->setup_move_bounds();
    ene_me3_stelth_real->init_common();
    ene_me3_stelth_real->mode = 0;
    ((VObj_18_be4a70 *)(ene_me3_stelth_real))->m85(ene_me3_stelth_real->mode, 4);
    return (u8 *)ene_me3_stelth_real;
}

void *TObjEneMe3StelthReal::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x44C);
    if (o != NULL) {
        o = TObjEneMe3StelthReal__ct((TObjEneMe3StelthReal *)((u8 *)o), (s32)tl_04, (s32)arg0);
    }
    return o;
}

}
