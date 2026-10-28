#include "types.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TUnk_804806E8.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneMe3ShinowaMirage.h"
#include "pso/enemy/TObjEneSaver.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneMe3Shinowa.h"
extern "C" void has_flag_0x800__13TUnk_804806E8Fv();
extern "C" void test_flag30_512__13TUnk_804806E8Fv();
extern "C" void test_flag_1000__13TUnk_804806E8Fv();
extern "C" void test_flag_256__13TUnk_804806E8Fv();
#include "pso/object/obj_band.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/TUnk_80494938.h"
#include <stddef.h>
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss4Type3.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/TObjEneMe3SinowZoa.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TTecResta.h"
#include "pso/misc/TTecSifta.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"

#define CAT2(a, b) a##b
#define CAT(a, b) CAT2(a, b)
#define PAD_VIRT virtual void CAT(pv, __LINE__)();
#define PADV virtual void CAT(pv, __LINE__)();
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();

struct VBase_18_2add4a { char pad[0x18]; };

struct VObj_18_2add4a : VBase_18_2add4a {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4(s32 *, s32 *);
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
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual s32 m20(void *, f32);
    virtual void m21();
    virtual void m22();
    virtual s32 m23(void *, f32);
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
    virtual void m85();
    virtual s32 m86();
    virtual s32 m87();
    virtual void m88();
    virtual s32 m89();
    virtual s32 m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual u32 m100();
};

struct VBase_18_a1ce10 { char pad[0x18]; };
struct VObj_18_a1ce10 : VBase_18_a1ce10 {
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
    virtual u32 m16(void *);
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
    virtual void m85();
    virtual s32 m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual s32 m91();
    virtual s32 m92();
    virtual void m93();
    virtual s32 m94();
};

struct Vec_800E5F64 { f32 x, y, z; };

struct VBase_18_dc3190 { char pad[0x18]; };

struct VObj_18_dc3190 : VBase_18_dc3190 {
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
    virtual void m85();
    virtual s32 m86();
    virtual s32 m87();
    virtual void m88();
    virtual s32 m89();
    virtual s32 m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
    virtual void m101();
    virtual s32 m102(f32);
};

struct VBase_18_4f5f2e { char pad[0x18]; };

struct VObj_18_4f5f2e : VBase_18_4f5f2e {
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
    virtual void m85();
    virtual void m86();
    virtual s32 m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
    virtual void m101();
    virtual void m102();
    virtual s32 m103();
    virtual void m104();
    virtual s32 m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual void m109();
    virtual s32 m110();
};

struct Info_800E5CE4 { u8 pad[0x8]; f32 f8; u8 pad2[0x14]; s32 f20; };

extern "C" const u32 TObjEneMe3ShinowaMirage__data_805DA5E8[1];
extern "C" const u32 TObjEneMe3ShinowaMirage__data_805DA5EC[1];
extern "C" const u32 lbl_805DA5F0[1];
extern "C" const u32 TObjEneMe3ShinowaMirage__data_805DA5F4[1];
extern "C" const u32 lbl_805DA5F8[1];
extern "C" const u32 lbl_805DA5FC[1];
extern "C" const u32 lbl_805DA600[1];
extern "C" const u32 lbl_805DA604[1];
extern "C" const u32 TObjEneMe3ShinowaMirage__data_805DA608[1];
extern "C" const u32 lbl_805DA60C[1];
extern "C" const u32 lbl_805DA610[1];
extern "C" const u32 lbl_805DA614[1];
extern "C" const u32 lbl_805DA618[1];
extern "C" const u32 lbl_805DA61C[1];
extern "C" const u32 lbl_805DA620[1];
extern "C" const u32 lbl_805DA624[1];
#define TObjEneMe3ShinowaMirage__data_805DA5E8 (*(const f32 *)TObjEneMe3ShinowaMirage__data_805DA5E8)
#define TObjEneMe3ShinowaMirage__data_805DA5EC (*(const f32 *)TObjEneMe3ShinowaMirage__data_805DA5EC)
#define lbl_805DA5F0 (*(const f32 *)lbl_805DA5F0)
#define TObjEneMe3ShinowaMirage__data_805DA5F4 (*(const f32 *)TObjEneMe3ShinowaMirage__data_805DA5F4)
#define lbl_805DA5F8 (*(const f32 *)lbl_805DA5F8)
#define lbl_805DA5FC (*(const f32 *)lbl_805DA5FC)
#define lbl_805DA600 (*(const f32 *)lbl_805DA600)
#define lbl_805DA604 (*(const f32 *)lbl_805DA604)
#define TObjEneMe3ShinowaMirage__data_805DA608 (*(const f32 *)TObjEneMe3ShinowaMirage__data_805DA608)
#define lbl_805DA60C (*(const f32 *)lbl_805DA60C)
#define lbl_805DA610 (*(const f32 *)lbl_805DA610)
#define lbl_805DA614 (*(const f32 *)lbl_805DA614)
#define lbl_805DA618 (*(const f32 *)lbl_805DA618)
#define lbl_805DA61C (*(const f32 *)lbl_805DA61C)
#define lbl_805DA620 (*(const f32 *)lbl_805DA620)
#define lbl_805DA624 (*(const f32 *)lbl_805DA624)

extern "C" {
f64 atan2_float(f32, f32);
u32 csnVecterUnder(void *, int);
s32 spawn_particle_effect(void *, int);
s32 transition_enemy_state__9TObjEneDDFs(void *, s32);
s32 copy_target_state__14TObjEnePanarmsFPv(void *, int);
s32 approach_angle_limited(int, int, int);
s32 advance_animation_playback(void *, s32);
s32 play_sound_effect(void *, void *, int, int);
s32 mult_vec_array__10TObjPlayerFUll(int, int, void *, int);
s32 set_matrix_identity(int);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
extern const f64 TObjEneMe3ShinowaMirage__data_8043CFE0;
extern s32 TObjEneMe3ShinowaMirage__data_805D52AC;
extern const f32 TObjEneMe3ShinowaMirage__data_805DA5B8;
extern const f32 TObjEneMe3ShinowaMirage__data_805DA5DC;
extern const f32 TObjEneMe3ShinowaMirage__data_805DA5E4;
void TObjEneMe3ShinowaMirage__sub_800E5F64(u8 *arg0, s32 arg1);
struct Tgt_800E54E8 { u16 id; u8 pad[6]; };
f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32, f32);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2);
void *create_particle_emitter(void *, s32);
s32 enemy_set_target_id(void *, u16);
s32 transform_relative_position__9TObjEneDDFPv(void *, void *);
}
void calc_wall_clamped_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist);
extern "C" {
s32 collect_target_candidates__9TObjEneDDFlf(void *, f32);
s32 subtract_vector(void *, void *);
extern Tgt_800E54E8 enemy_target_candidate_table[];
s32 sub_800E6FE0__17TObjEneMe3ShinowaFv(u8 *arg0);
extern const f32 lbl_805DA5BC;
extern const f32 TObjEneMe3ShinowaReal__data_805DA5CC;
void TObjEneMe3ShinowaReal__sub_800E5950(u8 *arg0, s32 arg1);
s32 move_to_shot_position__9TObjEneDDFfff(void *, void *, f32, f32, f32);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
extern const f32 lbl_805DA5D4;
void TObjEneMe3ShinowaMirage__sub_800E5CE4(u8 *arg0, s32 arg1);
struct Base_800E7034_800E47DC { char pad[0x18]; };

struct VObj_800E7034_800E47DC : Base_800E7034_800E47DC {
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
    virtual void m84(); virtual void m85(); virtual void m86();
};

struct Base_800E707C_800E47DC { char pad[0x18]; };

struct VObj_800E707C_800E47DC : Base_800E707C_800E47DC {
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
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
};

struct RecoveredGlobal_800E4D7C_TObjEneMe3ShinowaMirage__data_80500FC0 {
    s32 value;
    u8 remaining[0x20];
};

struct RecoveredGlobal_800E4D7C_lbl_80500FF4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_800F4758_lbl_8050110C {
    s32 value;
    u8 remaining[0x10];
};

struct Stack_800E6BB8 {
    s32 sp8;
    f32 spC;
};

struct VBase_14_948132 { char pad[0x14]; };

struct VObj_14_948132 : VBase_14_948132 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5();
};

struct VBase_18_4a41ce
{
  char pad[0x18];
};

struct VObj_18_4a41ce : VBase_18_4a41ce {
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
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual s32 m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
};

struct VBase_14_763762
{
  char pad[0x14];
};

struct VObj_14_763762 : VBase_14_763762 {
    virtual void m0();
    virtual void m1();
    virtual s32 m2();
    virtual void m3();
    virtual s32 m4();
};

struct RecoveredFields_800E50D8_arg0
{
  u8 unknown_0[0xB8];
  s16 field_B8;
  u8 unknown_BA[0x30A];
  s32 field_3C4;
  u8 unknown_3C8[0x3C];
  s32 field_404;
};

struct Info_800E6F0C { u8 pad[0x18]; s32 frame; s32 frame_1C; };

struct VBase_18_800E530C { char pad[0x18]; };
struct VObj_18_800E530C : VBase_18_800E530C {
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
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
};

struct Obj_800E6F0C { u8 pad[0x38]; u8 pos[0x3c0 - 0x38]; s32 kind; };

typedef struct { f32 x, y, z; } Vec_800E4FE8;

struct Base_800E6DD8 { u8 pad[0x18]; };

struct Obj_800E6DD8 : Base_800E6DD8 {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual void p4();
    virtual void p5();
    virtual void p6();
    virtual void p7();
    virtual void p8();
    virtual void p9();
    virtual void p10();
    virtual void p11();
    virtual void p12();
    virtual void p13();
    virtual void p14();
    virtual void p15();
    virtual void p16();
    virtual void p17();
    virtual void p18();
    virtual void p19();
    virtual void p20();
    virtual void p21();
    virtual void p22();
    virtual void p23();
    virtual void p24();
    virtual void p25();
    virtual void p26();
    virtual void p27();
    virtual void p28();
    virtual void p29();
    virtual void p30();
    virtual void p31();
    virtual void p32();
    virtual void p33();
    virtual void p34();
    virtual void p35();
    virtual void p36();
    virtual void p37();
    virtual void p38();
    virtual void p39();
    virtual void p40();
    virtual void p41();
    virtual void p42();
    virtual void p43();
    virtual void p44();
    virtual void p45();
    virtual void p46();
    virtual void p47();
    virtual void p48();
    virtual void p49();
    virtual void p50();
    virtual void p51();
    virtual void p52();
    virtual void p53();
    virtual void p54();
    virtual void p55();
    virtual void p56();
    virtual void p57();
    virtual void p58();
    virtual void p59();
    virtual void p60();
    virtual void p61();
    virtual void p62();
    virtual void p63();
    virtual void p64();
    virtual void p65();
    virtual void p66();
    virtual void p67();
    virtual void p68();
    virtual void p69();
    virtual void p70();
    virtual void p71();
    virtual void p72();
    virtual void p73();
    virtual void p74();
    virtual void p75();
    virtual void p76();
    virtual void p77();
    virtual void p78();
    virtual void p79();
    virtual void p80();
    virtual void p81();
    virtual void p82();
    virtual void p83();
    virtual void p84();
    virtual void p85();
    virtual void p86();
    virtual void p87();
    virtual void p88();
    virtual void p89();
    virtual void p90();
    virtual void p91();
    virtual void p92();
    virtual void p93();
    virtual void p94();
    virtual void p95();
    virtual void p96();
    virtual void p97();
    virtual void p98();
    virtual void p99();
    virtual void p100();
    virtual void p101();
    virtual void p102();
    virtual void p103();
    virtual void p104();
    virtual void p105();
    virtual void p106();
    virtual void p107();
    virtual void p108();
    virtual void p109();
    virtual void p110();
    virtual void v111(s32);
    virtual void v112(s32);
    virtual void v113(s32);
    virtual void v114(s32);
};

struct VBase_18_82072c { char pad[0x18]; };

struct VObj_18_82072c : VBase_18_82072c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
    virtual s32 m9(f32, f32, f32);
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
    virtual void m85();
    virtual void m86();
    virtual void m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual void m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
    virtual void m105();
    virtual s32 m106();
    virtual s32 m107();
    virtual s32 m108();
    virtual void m109();
    virtual void m110();
    virtual void m111();
    virtual void m112();
    virtual void m113();
    virtual void m114();
    virtual void m115();
    virtual s32 m116();
};

struct Vec_800E4DD0 { f32 x, y, z; };

struct VBase_18_e66632 { char pad[0x18]; };

struct VObj_18_e66632 : VBase_18_e66632 {
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
    virtual void m85();
    virtual void m86();
    virtual s32 m87();
    virtual void m88();
    virtual void m89();
    virtual void m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
    virtual void m95();
    virtual void m96();
    virtual void m97();
    virtual void m98();
    virtual void m99();
    virtual s32 m100();
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual s32 m104();
    virtual void m105();
    virtual void m106();
    virtual void m107();
    virtual void m108();
    virtual s32 m109();
};

struct VBase18b_800e70d4_800E47DC { char pad[0x18]; };

struct VObj18b_800e70d4_800E47DC : VBase18b_800e70d4_800E47DC {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4(void *, void *);
};

typedef char RecoveredGlobal_800E4D7C_TObjEneMe3ShinowaMirage__data_80500FC0_size[sizeof(RecoveredGlobal_800E4D7C_TObjEneMe3ShinowaMirage__data_80500FC0) == 0x24 ? 1 : -1];

typedef char RecoveredGlobal_800E4D7C_lbl_80500FF4_size[sizeof(RecoveredGlobal_800E4D7C_lbl_80500FF4) == 0xC ? 1 : -1];

struct RecoveredGlobal_800E4D7C_lbl_80500FF4;

typedef struct RecoveredFields_800E50D8_arg0 RecoveredFields_800E50D8_arg0;

typedef struct VBase_14_763762 VBase_14_763762;

typedef struct VBase_18_4a41ce VBase_18_4a41ce;

typedef struct VObj_14_763762 VObj_14_763762;

typedef struct VObj_18_4a41ce VObj_18_4a41ce;

struct Info_800E6F0C;

typedef char RecoveredGlobal_800F4758_lbl_8050110C_size[sizeof(RecoveredGlobal_800F4758_lbl_8050110C) == 0x14 ? 1 : -1];

struct E71ACBase_800e71ac_800E71A8 { char pad[0x14]; };

struct E71ACObj_800e71ac_800E71A8 : E71ACBase_800e71ac_800E71A8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
};

struct E71FCBase_800e71fc_800E71A8 { char pad[0x14]; };

struct E71FCObj_800e71fc_800E71A8 : E71FCBase_800e71fc_800E71A8 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
};

struct VBase_18_c44252 { char pad[0x18]; };

struct VObj_18_c44252 : VBase_18_c44252 {
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
    virtual s32 m18(void *, f32);
    virtual void m19();
    virtual s32 m20(void *, f32);
    virtual void m21();
    virtual void m22();
    virtual s32 m23(void *, f32);
};

struct Stack_800E7324 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct RecoveredGlobal_800E7324_lbl_8043CF94 {
    s32 value;
    u8 remaining[0x8];
};

struct Vec_800E75AC { f32 x; f32 y; f32 z; };

struct Node_800E75AC { u8 pad[0x2c]; void *child; };

struct Sub_800E750C { f32 f0; u8 pad4[4]; f32 f8; f32 fC; f32 f10; s32 f14; s32 f18; };

struct Obj_800E750C { u8 pad0[0x60]; s32 f60; u8 pad1[0xA4 - 0x64]; Sub_800E750C *fA4; };

struct Obj_800E750C;

struct E_800E728C { u8 pad[0x60]; s32 f60; u8 pad64[0x390 - 0x64]; s32 f390; u8 pad394[0x3AC - 0x394]; f32 f3ac; u8 pad3b0[0x3C4 - 0x3B0]; s32 f3c4; };

typedef char RecoveredGlobal_800E7324_lbl_8043CF94_size[sizeof(RecoveredGlobal_800E7324_lbl_8043CF94) == 0xC ? 1 : -1];

struct VBase_800E7884 { u8 pad[0x14]; };

struct VObj_800E7884 : VBase_800E7884 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    u8 pad18[4];
};

struct Tbl_800E7884 { u8 pad[0xC]; s32 t[3][2]; };

struct Mirage_800E7884 {
    u8 pad0[0x34];
    s32 f34;
    u8 pad38[0x3C - 0x38];
    f32 f3C;
    u8 pad40[0xB0 - 0x40];
    s32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s16 fB8;
    u8 padBA[0x2CC - 0xBA];
    s16 f2CC;
    u8 pad2CE[0x350 - 0x2CE];
    void *f350;
    u8 pad354[0x37C - 0x354];
    f32 f37C;
    u8 pad380[0x3C0 - 0x380];
    s32 f3C0;
    s32 f3C4;
    f32 f3C8;
    f32 f3CC;
    s32 f3D0;
    s32 f3D4;
    s32 f3D8;
    s16 f3DC;
    void *f3E0;
    void *f3E4;
    VObj_800E7884 sub;
    s32 f404;
    s32 f408;
    s32 f40C;
    f32 f410;
    f32 f414;
    f32 f418;
    f32 f41C;
    f32 f420;
    s32 f424;
    s32 f428;
};

struct Game_800E7884 { u8 pad[0x42C]; u8 *mdl; s32 f430; };

s32 get_main_phase();
f32 calc_boss4_scale__10TObjPlayerFi(s32);
s32 is_split_screen();
void queue_destruction__7TObjectFv(void *arg0);
}
void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0);
extern "C" {
s32 enemy_validate_retained_target(void *, int);
s32 update_linked_position__12TObjEneDD_STFf(f32);
int select_and_apply_target__12TObjEneDD_STFf(void*);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 is_main_phase_15__9TObjEneDDFv();
s32 update_player_state__9TObjEneDDFv(void *, void *, int);
s32 reset_hp__9TObjEneDDFv(void *, int, int, int);
void get_camera_ctrl__9TObjEneDDFv(s32, s32);
s32 initialize_enemy_state__9TObjEneDDFv(void *, int);
void TObjEneDD__sub_800BA438(s32 arg0, u8 *arg1);
void init_model__9TObjEneDDFv(void *, void *, s32);
s32 TObjEneMe3SinowZoa__sub_800D758C(void *);
void *__dt__13TUnk_80494938Fv(void *arg0, s16 arg1);
s32 TBoss3Volopt__sub_800D8D88(void *, f32);
void update_mirage__17TObjEneMe3ShinowaFv(void* p);
void vfunc_116__17TObjEneMe3ShinowaFl(void);
void vfunc_114__17TObjEneMe3ShinowaFl(void);
void TObjEneMe3ShinowaMirage__sub_800E4FE8(u8 *arg0, s32 arg1);
void TObjEneMe3ShinowaMirage__sub_800E50D8(u8 *arg0, s32 arg1);
void TObjEneMe3ShinowaMirage__sub_800E5220(void *arg0, s32 arg1);
void TObjEneMe3ShinowaMirage__sub_800E54E8(void *, s32);
void TObjEneMe3ShinowaMirage__sub_800E66FC(u8 *, s32);
void TObjEneMe3ShinowaMirage__sub_800E69F0(u8 *arg0, s32 arg1);
void action__17TObjEneMe3ShinowaFl(u8 *arg0, s32 arg1);
void dispatch_action__23TObjEneMe3ShinowaMirageFPvUii(Obj_800E6DD8 *arg0, u32 arg1, s32 arg2);
void TObjEneMe3ShinowaMirage__sub_800E6F0C(Obj_800E6F0C *self);
int select_and_apply_target__23TObjEneMe3ShinowaMirageFPv(void* p);
void vfunc_89__17TObjEneMe3ShinowaFv(void *arg0);
void vfunc_111__17TObjEneMe3ShinowaFv(void);
void TObjEneMe3Shinowa__sub_800E7268(u8 *arg0);
s32 check_in_range__23TObjEneMe3ShinowaMirageFPv(void *arg0);
u8 check_body_collision_at__17TObjEneMe3ShinowaFlf(Obj_800E750C *arg0, s32 arg1, f32 farg0);
void fn_800E762C(void);
void vfunc_88__17TObjEneMe3ShinowaFv(u8 *arg0);
void vfunc_61__17TObjEneMe3ShinowaFv(void);
void vfunc_28__17TObjEneMe3ShinowaFv(void);
void * __dt__17TObjEneMe3ShinowaFv(void *arg0, s16 arg1);
void * TObjEneMe3Shinowa__ct(void *arg0);
s32 check_enemy_body_collisions(void *);
void free_collision_body_parts(void *);
s32 get_room__13TUnk_804B9870Fv(int);
s32 defer_render__7TObjectFv(void *);
void __dl__7TObjectFPv(void *);
s32 create__10TTecDebandFlll(void *, void *, s32);
void bind_motion_context(s32, f32);
void compose_motion_node_matrix(void *arg0);
s32 matrix_mult_vec(int, void *, void *);
s32 translate_matrix(int, f32, f32, f32);
s32 push_matrix_from(void *);

extern RecoveredGlobal_800E4D7C_TObjEneMe3ShinowaMirage__data_80500FC0 TObjEneMe3ShinowaMirage__data_80500FC0;
extern Info_800E6F0C *TObjEneMe3ShinowaMirage__mirage_info_table[];
extern u8 *TObjEneMe3ShinowaMirage__data_805D5298;
extern s32 TObjEneMe3ShinowaMirage__data_805D52A0;
extern s32 TObjEneMe3ShinowaMirage__data_805D52A4;
extern s32 TObjEneMe3ShinowaMirage__data_805D52A8;
extern s32 __vt__17TObjEneMe3Shinowa[];
extern u8 shinowa_mirage_breakup_params[];
extern RecoveredGlobal_800E7324_lbl_8043CF94 lbl_8043CF94;
extern RecoveredGlobal_800F4758_lbl_8050110C lbl_80500FEC;
extern RecoveredGlobal_800E4D7C_lbl_80500FF4 lbl_80500FF4;
extern s32 *lbl_80501000[];
extern u8 identity_matrix[];
extern void *lbl_805D2AC8;
extern s32 TObjEneMe3ShinowaMirage__render_node_index;
extern s32 saved_model_render_flags;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern const f32 lbl_805DA5D8;
extern const f32 lbl_805DA5E0;
extern s32 lbl_805DA634;
extern const f32 lbl_805DA638;
extern const f32 lbl_805DA63C;
extern const f32 lbl_805DA640;
extern const f32 lbl_805DA644;
extern const f32 lbl_805DA648;
extern const f32 lbl_805DA64C;
extern const f32 lbl_805DA650;
extern s32 model_render_flags;

#define PAD_VIRT virtual void CAT(pv, __LINE__)();
#define PADV virtual void CAT(pv, __LINE__)();
#define PADV4 virtual void CAT(pa, __LINE__)(); virtual void CAT(pb, __LINE__)(); virtual void CAT(pc, __LINE__)(); virtual void CAT(pd, __LINE__)();
extern "C" {
void vfunc_6__13TUnk_804B9870FPsl();
}
extern "C" {
void vfunc_103__9TObjEneDDFPUc();
}
extern "C" {
void vfunc_79__9TObjEneDDFv();
}
extern "C" {
void TObjEneDD__vt82();
}
extern "C" {
void vfunc_85__9TObjEneDDFv();
}
extern "C" {
void vfunc_86__9TObjEneDDFv();
}
extern "C" {
void vfunc_90__9TObjEneDDFv();
}
extern "C" {
void vfunc_91__9TObjEneDDFv();
}
extern "C" {
void vfunc_92__9TObjEneDDFv();
}
extern "C" {
void vfunc_93__9TObjEneDDFv();
}
extern "C" {
void vfunc_94__9TObjEneDDFv();
}
extern "C" {
void vfunc_95__9TObjEneDDFv();
}
extern "C" {
void vfunc_96__9TObjEneDDFv();
}
extern "C" {
void vfunc_97__9TObjEneDDFv();
}
extern "C" {
void vfunc_98__9TObjEneDDFv();
}
extern "C" {
void vfunc_99__9TObjEneDDFv();
}
extern "C" {
void vfunc_100__9TObjEneDDFv();
}
extern "C" {
void vfunc_101__9TObjEneDDFPUc();
}
extern "C" {
void vfunc_102__9TObjEneDDFv();
}
extern "C" {
void vfunc_83__12TObjEneDD_STFv();
}
extern "C" {
void TObjEneMe3ShinowaMirage__sub_800E47DC();
}
extern "C" {
void vfunc_105__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void can_hit_same_target__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void vfunc_107__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void update_player_state_default__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void update_effect__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void dispatch_if_active__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void apply_effect_pair__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void TObjEneMe3ShinowaMirage__vt113(u8 *arg0, s32 arg1);
}
extern "C" {
void vfunc_62__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void vfunc_63__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void vfunc_29__13TUnk_804806E8Fv();
}
extern "C" {
void recalc_stats__13TUnk_804806E8Fv();
}
extern "C" {
void consume_timer_field__13TUnk_804806E8Fl();
}
extern "C" {
void vfunc_67__13TUnk_804806E8Ff();
}
extern "C" {
void vfunc_66__13TUnk_804806E8Fv();
}
extern "C" {
void get_anim_node_position__13TUnk_804806E8FlP3Vec();
}
extern "C" {
void vfunc_60__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_59__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_58__13TUnk_804806E8Fv();
}
extern "C" {
void apply_slow_status__13TUnk_804806E8Fv();
}
extern "C" {
void update_shock_clock__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_43__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_18__13TUnk_804806E8FPUc();
}
extern "C" {
void interact__13TUnk_804AF8A0Fl();
}
extern "C" {
void vfunc_74__9TObjEnemyFl();
}
extern "C" {
void apply_hit_message_flags__9TObjEnemyFPv();
}
extern "C" {
void *__dt__23TObjEneMe3ShinowaMirageFv(void *arg0, s16 arg1);
}
extern "C" {
void add_actor_exp__13TUnk_804806E8Fl();
}
extern "C" {
void apply_action_hold_status__13TUnk_804806E8Ff();
}
extern "C" {
void apply_anti_technique__13TUnk_804806E8Fl();
}
extern "C" {
void apply_attack_stat_status__13TUnk_804806E8FPv();
}
extern "C" {
void apply_confusion_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_knockback_from_attacker__13TUnk_804806E8FPUc();
}
extern "C" {
void apply_movement_ailment__13TUnk_804806E8Fl();
}
extern "C" {
void apply_object_set_data__13TUnk_804B9870FPv();
}
extern "C" {
void apply_paralysis__13TUnk_804806E8Fv();
}
extern "C" {
void apply_poison_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_set_data__9TObjEnemyFPv();
}
extern "C" {
void apply_shock_status__13TUnk_804806E8Fv();
}
extern "C" {
void apply_switch_attack__13TUnk_804806E8Fv();
}
extern "C" {
void calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf();
}
extern "C" {
void classify_actor_view_detail__13TUnk_804B9870Ffff();
}
extern "C" {
void clear_all_status_effects__13TUnk_804806E8Fv();
}
extern "C" {
void clear_harmful_statuses__13TUnk_804806E8Fv();
}
extern "C" {
void cure_paralysis__13TUnk_804806E8Fv();
}
extern "C" {
void cure_poison_ailment__13TUnk_804806E8Fv();
}
extern "C" {
void enemy_spawn_jellen_effect__13TUnk_804806E8Fv();
}
extern "C" {
void enemy_spawn_zalure_effect__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_78__13TUnk_804806E8Fl();
}
extern "C" {
void vfunc_77__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_76__13TUnk_804806E8Fv();
}
extern "C" {
void vfunc_75__13TUnk_804806E8Ff();
}
extern "C" {
void clear_lobby_object_state__9TObjEnemyFv();
}
extern "C" {
void get_center__13TUnk_804806E8Fv();
}
extern "C" {
void get_actor_level_index__13TUnk_804806E8Fv();
}
extern "C" {
void get_name__9TObjEnemyFv();
}
extern "C" {
void get_pos__13TUnk_804806E8Fl();
}
extern "C" {
void is_actor_cadence_frame__13TUnk_804806E8Fl();
}
extern "C" {
void is_target_in_attack_range__13TUnk_804806E8Fv();
}
extern "C" {
extern u8 lbl_8043CE3C[];
}
extern "C" {
extern u8 lbl_8043CE4C[];
}
extern "C" {
extern u8 lbl_8043CE60[];
}
extern "C" {
extern u8 lbl_8043CE78[];
}
extern "C" {
extern u8 lbl_8043CE90[];
}
extern "C" {
extern u8 lbl_8043CEA4[];
}
extern "C" {
extern u8 lbl_8043CEBC[];
}
extern "C" {
extern u8 lbl_8043CED0[];
}
extern "C" {
extern u8 lbl_8043CEE8[];
}
extern "C" {
extern u8 lbl_8043CF00[];
}
extern "C" {
extern u8 lbl_8043CF14[];
}
extern "C" {
extern u8 lbl_8043CF28[];
}
extern "C" {
void receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll();
}
extern "C" {
void receive_physical_attack__13TUnk_804806E8FPvf();
}
extern "C" {
void receive_weapon_special_attack__13TUnk_804806E8FPvPv();
void apply_defense_stat_status__13TUnk_804806E8FPv();
}
extern "C" {
void render__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void render_shadows__9TObjEnemyFv(u8 *arg0);
}
extern "C" {
void reset_motion_fields__13TUnk_804806E8Fv();
}
extern "C" {
void reset_pose__13TUnk_804806E8Fv();
}
extern "C" {
void roll_physical_accuracy__13TUnk_804806E8FPvlf();
}
extern "C" {
void run_task__23TObjEneMe3ShinowaMirageFv();
}
extern "C" {
void select_melee_contact_body__13TUnk_804806E8FPvf();
}
extern "C" {
void trigger_switch_attack__13TUnk_804806E8Fv(s32 arg0);
}
extern "C" {
void try_start_action__13TUnk_804806E8Fll();
}
extern "C" {
void update_action_hold_status__13TUnk_804806E8Fv();
}
extern "C" {
s32 vfunc_37__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
void update_actor_ground_y__13TUnk_804806E8Fv();
}
extern "C" {
s32 update_attack_stat_status__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
s32 update_defense_stat_status__13TUnk_804806E8Fv(u8 *arg0);
}
extern "C" {
void update_flag30_timer__13TUnk_804806E8Fv();
}
extern "C" {
void update_movement_status__13TUnk_804806E8Fv();
}
extern "C" {
void update_object_view_visibility__13TUnk_804B9870Fff();
}
extern "C" {
void update_poison_status__13TUnk_804806E8Fv();
}
extern void *bm_ene_me3_shinowa_model_names[2];
extern void *bm_ene_me3_shinowa_motion_names[11];
void *TObjEneMe3ShinowaMirage__init_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *shinowa_mirage_model_init_data[11] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41000000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
__declspec(section ".data") void *bm_ene_me3_shinowa_model_names[2] = {
    (void *)&lbl_8043CE3C, (void *)0x0,
};
void *bm_ene_me3_shinowa_motion_names[11] = {
    (void *)&lbl_8043CE4C, (void *)&lbl_8043CE60, (void *)&lbl_8043CE78, (void *)&lbl_8043CE90,
    (void *)&lbl_8043CEA4, (void *)&lbl_8043CEBC, (void *)&lbl_8043CED0, (void *)&lbl_8043CEE8,
    (void *)&lbl_8043CF00, (void *)&lbl_8043CF14, (void *)0x0,
};
void *shinowa_mirage_resource_descriptor[4] = {
    (void *)&lbl_8043CF28, (void *)&bm_ene_me3_shinowa_model_names, (void *)&bm_ene_me3_shinowa_motion_names, (void *)0x1000a,
};
void *shinowa_mirage_motion_param_table[44] = {
    (void *)0x10000, (void *)0x7, (void *)0x3f000000, (void *)0x80000000,
    (void *)0x30000, (void *)0x0, (void *)0x3fc00000, (void *)0x80000000,
    (void *)0x30000, (void *)0x1, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x2, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x4, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x5, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x6, (void *)0x3f333333, (void *)0x0,
    (void *)0x10000, (void *)0x8, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x9, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x6, (void *)0x3f333333, (void *)0x80000000,
};
void *__vt__23TObjEneMe3ShinowaMirage[119] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__23TObjEneMe3ShinowaMirageFv, (void *)&run_task__23TObjEneMe3ShinowaMirageFv,
    (void *)&render__23TObjEneMe3ShinowaMirageFv, (void *)&render_shadows__9TObjEnemyFv, (void *)&vfunc_6__13TUnk_804B9870FPsl, (void *)&apply_object_set_data__13TUnk_804B9870FPv,
    (void *)&reset_motion_fields__13TUnk_804806E8Fv, (void *)&get_center__13TUnk_804806E8Fv, (void *)&update_object_view_visibility__13TUnk_804B9870Fff, (void *)&classify_actor_view_detail__13TUnk_804B9870Ffff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__13TUnk_804AF8A0Fl, (void *)&add_actor_exp__13TUnk_804806E8Fl, (void *)&consume_timer_field__13TUnk_804806E8Fl,
    (void *)&get_actor_level_index__13TUnk_804806E8Fv, (void *)&update_actor_ground_y__13TUnk_804806E8Fv, (void *)&vfunc_18__13TUnk_804806E8FPUc, (void *)&is_actor_cadence_frame__13TUnk_804806E8Fl,
    (void *)&select_melee_contact_body__13TUnk_804806E8FPvf, (void *)&calc_distance_accuracy_penalty__13TUnk_804806E8FPvPvPvf, (void *)&receive_physical_attack__13TUnk_804806E8FPvf, (void *)&receive_direct_attack__13TUnk_804806E8FPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__13TUnk_804806E8FPvPv, (void *)&apply_knockback_from_attacker__13TUnk_804806E8FPUc, (void *)&try_start_action__13TUnk_804806E8Fll, (void *)&roll_physical_accuracy__13TUnk_804806E8FPvlf,
    (void *)&vfunc_28__17TObjEneMe3ShinowaFv, (void *)&vfunc_29__13TUnk_804806E8Fv, (void *)&is_target_in_attack_range__13TUnk_804806E8Fv, (void *)&test_flag_256__13TUnk_804806E8Fv,
    (void *)&test_flag30_512__13TUnk_804806E8Fv, (void *)&has_flag_0x800__13TUnk_804806E8Fv, (void *)&test_flag_1000__13TUnk_804806E8Fv, (void *)&update_poison_status__13TUnk_804806E8Fv,
    (void *)&update_action_hold_status__13TUnk_804806E8Fv, (void *)&vfunc_37__13TUnk_804806E8Fv, (void *)&update_flag30_timer__13TUnk_804806E8Fv, (void *)&update_movement_status__13TUnk_804806E8Fv,
    (void *)&update_shock_clock__13TUnk_804806E8Fv, (void *)&update_attack_stat_status__13TUnk_804806E8Fv, (void *)&update_defense_stat_status__13TUnk_804806E8Fv, (void *)&vfunc_43__13TUnk_804806E8Fv,
    (void *)&apply_poison_status__13TUnk_804806E8Fv, (void *)&apply_paralysis__13TUnk_804806E8Fv, (void *)&apply_slow_status__13TUnk_804806E8Fv, (void *)&apply_confusion_status__13TUnk_804806E8Fv,
    (void *)&apply_movement_ailment__13TUnk_804806E8Fl, (void *)&apply_shock_status__13TUnk_804806E8Fv, (void *)&clear_harmful_statuses__13TUnk_804806E8Fv, (void *)&apply_attack_stat_status__13TUnk_804806E8FPv,
    (void *)&apply_defense_stat_status__13TUnk_804806E8FPv, (void *)&cure_poison_ailment__13TUnk_804806E8Fv, (void *)&cure_paralysis__13TUnk_804806E8Fv, (void *)&clear_all_status_effects__13TUnk_804806E8Fv,
    (void *)&apply_action_hold_status__13TUnk_804806E8Ff, (void *)&apply_anti_technique__13TUnk_804806E8Fl, (void *)&vfunc_58__13TUnk_804806E8Fv, (void *)&vfunc_59__13TUnk_804806E8Fv,
    (void *)&vfunc_60__13TUnk_804806E8Fv, (void *)&vfunc_61__17TObjEneMe3ShinowaFv, (void *)&vfunc_62__23TObjEneMe3ShinowaMirageFv, (void *)&vfunc_63__23TObjEneMe3ShinowaMirageFv,
    (void *)&reset_pose__13TUnk_804806E8Fv, (void *)&get_anim_node_position__13TUnk_804806E8FlP3Vec, (void *)&vfunc_66__13TUnk_804806E8Fv, (void *)&vfunc_67__13TUnk_804806E8Ff,
    (void *)&get_pos__13TUnk_804806E8Fl, (void *)&apply_switch_attack__13TUnk_804806E8Fv, (void *)&enemy_spawn_jellen_effect__13TUnk_804806E8Fv, (void *)&trigger_switch_attack__13TUnk_804806E8Fv,
    (void *)&enemy_spawn_zalure_effect__13TUnk_804806E8Fv, (void *)&recalc_stats__13TUnk_804806E8Fv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__13TUnk_804806E8Ff,
    (void *)&vfunc_76__13TUnk_804806E8Fv, (void *)&vfunc_77__13TUnk_804806E8Fv, (void *)&vfunc_78__13TUnk_804806E8Fl, (void *)&vfunc_79__9TObjEneDDFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&TObjEneDD__vt82, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&dispatch_action__23TObjEneMe3ShinowaMirageFPvUii,
    (void *)&vfunc_88__17TObjEneMe3ShinowaFv, (void *)&vfunc_89__17TObjEneMe3ShinowaFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&select_and_apply_target__23TObjEneMe3ShinowaMirageFPv, (void *)&vfunc_105__23TObjEneMe3ShinowaMirageFv, (void *)&can_hit_same_target__23TObjEneMe3ShinowaMirageFv, (void *)&vfunc_107__23TObjEneMe3ShinowaMirageFv,
    (void *)&update_player_state_default__23TObjEneMe3ShinowaMirageFv, (void *)&update_effect__23TObjEneMe3ShinowaMirageFv, (void *)&dispatch_if_active__23TObjEneMe3ShinowaMirageFv, (void *)&vfunc_111__17TObjEneMe3ShinowaFv,
    (void *)&apply_effect_pair__23TObjEneMe3ShinowaMirageFv, (void *)&action__17TObjEneMe3ShinowaFl, (void *)&vfunc_114__17TObjEneMe3ShinowaFl, (void *)&TObjEneMe3ShinowaMirage__vt113,
    (void *)&vfunc_116__17TObjEneMe3ShinowaFl, (void *)&update_mirage__17TObjEneMe3ShinowaFv, (void *)&TObjEneMe3ShinowaMirage__sub_800E47DC,
};
#define shinowa_mirage_model_init_data ((u8 *)shinowa_mirage_model_init_data)

void TObjEneMe3Shinowa::update_mirage() { if (get_target_info() != 0) { ((int (*)(void*))fn_800E762C)(this); sub_800E6F64(); } }

void TObjEneMe3ShinowaMirage::draw_model() {
    s32 var_r31;
    s32 var_r30;
    s32 i;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->vfunc_118();
        return;
    }
    sub_800E6FE0__17TObjEneMe3ShinowaFv(((u8 *)this));
    if (*(s32 *)((s8 *)((u8 *)this) + 0x3C4) & 2) {
        var_r31 = 0;
    } else if (is_main_phase_15__9TObjEneDDFv() != 0) {
        var_r31 = ((VObj_18_82072c *)(this))->m9(lbl_805D9E88, lbl_805D9E84, TObjEneMe3ShinowaReal__data_805DA5CC);
    } else if (((VObj_18_82072c *)(this))->m8(lbl_805DA5D8, TObjEneMe3ShinowaReal__data_805DA5CC) != 0) {
        var_r31 = 1;
    } else {
        var_r31 = 0;
    }
    if (var_r31 != 0) {
        this->update_player_state_default();
        TObjFish::set_global_param(this->texlist);
        this->update_secondary_light();
        saved_model_render_flags = model_render_flags;
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        for (i = 0; i < 3; i++) {
            if (lbl_80501000[i] != NULL) {
                *lbl_80501000[i] = *(s32 *)((s8 *)((u8 *)this) + 0x3D0);
            }
        }
        var_r30 = 1;
        if ((this->update_effect() != 0) && (defer_render__7TObjectFv((void *)this) != 0)) {
            var_r30 = 0;
        }
        if (var_r30 != 0) {
            push_matrix();
            post_translate_matrix((void *) ((u8 *)this + 0x38));
            translate_matrix(0, TObjEneMe3ShinowaMirage__data_805DA5B8, (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x3CC)), TObjEneMe3ShinowaMirage__data_805DA5B8);
            rotate_matrix_y(0, this->rotation_y);
            TObjEneMe3ShinowaMirage__render_node_index = 0;
            TObjEneRe7Berura::set_global_state((s32)((void *) (TObjEneMe3ShinowaMirage::advance_camera_ctrl_step)));
            if (var_r31 == 1) {
                ((TObjMotion *)((u8 *)this))->draw();
            } else {
                this->render_world_model();
            }
            TObjEneRe7Berura::set_global_state(NULL);
            pop_matrix();
        }
        this->dispatch_if_active();
        model_render_flags = saved_model_render_flags;
        this->update_primary_light();
        VecCopy((Vec *)((u8 *)this + 0x2FC), (const Vec *)(&lbl_80500FF4));
    } else if ((get_main_phase() == 0xF) || (is_split_screen() == 0)) {
        VecCopy((Vec *)((u8 *)this + 0x2FC), (const Vec *)((u8 *)this + 0x38));
    }
    TParticleCtrl::end_effect_render();
}

void TObjEneMe3ShinowaMirage::advance_camera_ctrl_step() {
    if ((s32) TObjEneMe3ShinowaMirage__render_node_index == 1) {
        get_camera_ctrl__9TObjEneDDFv((s32) &TObjEneMe3ShinowaMirage__data_80500FC0.value, (s32) &lbl_80500FF4.value);
    }
    TObjEneMe3ShinowaMirage__render_node_index += 1;
}

void TObjEneMe3Shinowa::vfunc_116(s32) {  }

void TObjEneMe3Shinowa::vfunc_115() {  }

void TObjEneMe3Shinowa::vfunc_114(s32) {  }

#pragma push
#pragma fp_contract on
void TObjEneMe3ShinowaMirage::state_break_apart(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    Vec_800E4DD0 sp14;
    Vec_800E4DD0 sp8;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 4;
        ((TBoss8Dragon *)arg0)->refresh_and_send_entity_flags();
        this->vfunc_94();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFC);
        *(s32 *)((s8 *)arg0 + 0x404) = 0;
        break;
    case 3:
    case 5:
        break;
    case 0:
        switch (*(s32 *)((s8 *)arg0 + 0x404)) {
        case 0:
            ((void (*)())advance_animation_playback)();
            if ((objInBand((GameObj *)(arg0), (f32)lbl_805DA5E0) != 0) || (objInBand((GameObj *)(arg0), (f32)((f32)TObjEneMe3ShinowaMirage__data_805DA5E4)) != 0)) {
                play_sound_effect((void *) copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD12), arg0 + 0x38, 0, 0);
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x404) = 1;
                *(s32 *)((s8 *)arg0 + 0x408) = 0;
                sp14.x = TObjEneMe3ShinowaMirage__data_805DA5B8;
                sp14.y = TObjEneMe3ShinowaMirage__data_805DA5E8;
                sp14.z = TObjEneMe3ShinowaMirage__data_805DA5EC;
                ((TObjBoss2Tunnel *)(&sp14))->init_zako(arg0 + 0x38, *(s32 *)((s8 *)arg0 + 0x60));
                TObjPlayer::spawn_effect_f8((s32)&sp14, 0x14);
            }
            break;
        case 1:
            (*(s32 *)((s8 *)arg0 + 0x408))++;
            if (*(s32 *)((s8 *)arg0 + 0x408) >= 0x14) {
                *(s32 *)((s8 *)arg0 + 0x404) = 2;
                *(s32 *)((s8 *)arg0 + 0x3C4) |= 2;
                TBoss3Volopt::create_breakup_mdl((s32)TObjEneMe3ShinowaMirage__data_805D52A0, (s32)shinowa_mirage_breakup_params, (s32)(*(s32 *)((s8 *)arg0 + 0x24)), (s32)(arg0 + 0x38), (s32)(*(s32 *)((s8 *)arg0 + 0x60)));
                VecCopy((Vec *)&sp8, (const Vec *)(arg0 + 0x38));
                sp8.x += TObjEneMe3ShinowaMirage__data_805DA5EC * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x60));
                sp8.z += TObjEneMe3ShinowaMirage__data_805DA5EC * cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x60));
                ((TObjPlayer *)(&sp8))->trigger_dell_biter_events();
                play_sound_effect((void *) copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD16), arg0 + 0x38, 0, 0);
            }
            this->vfunc_102();
            break;
        case 2:
            queue_destruction__7TObjectFv(arg0);
            break;
        }
        break;
    }
}
#pragma pop

void TObjEneMe3ShinowaMirage__sub_800E4FE8(u8 *ene_dd_st, s32 arg1) {
    Vec_800E4FE8 v;
    f32 c;
    switch (arg1) {
    case 4:
        ((TObjEneDD_ST *)ene_dd_st)->m_b8 = 3;
        advance_animation_playback(ene_dd_st, arg1);
        ((TObjEneDD_ST *)ene_dd_st)->set_active();
        break;
    case 3:
        if (((TObjEneDD *)ene_dd_st)->get_flag_b4() != 0) {
            transition_enemy_state__9TObjEneDDFs(ene_dd_st, *(s32 *)((s8 *)ene_dd_st + 0x378));
        }
        break;
    case 0:
        advance_animation_playback(ene_dd_st, arg1);
        VecCopy((Vec *)&v, (const Vec *)(ene_dd_st + 0x308));
        c = ((TObjBoss2Tunnel *)(&v))->clamp_velocity();
        ((TObjEneDD *)ene_dd_st)->move_clamped_on_ground(v.x, v.z, c);
        *(f32 *)((s8 *)ene_dd_st + 0x308) *= lbl_805DA5F0;
        ((TObjEneDD_ST *)ene_dd_st)->m_310 *= lbl_805DA5F0;
        ((TObjEneDD *)ene_dd_st)->vfunc_89();
        break;
    case 5:
        ((TObjEneDD *)ene_dd_st)->clear_attack_receipts();
        ((TObjEneDD *)ene_dd_st)->clear_field_388();
        break;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E50D8(u8 *ene_dd, s32 arg1) {
  s32 temp_r3;
  switch (arg1)
  {
    return;
    case 4:
      ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_B8 = 7;
      ((TObjEneDD *)ene_dd)->set_field_378(4);
      (((TObjEneDD *)(ene_dd))->vfunc_95());
      ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_3C4 = (s32) (((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_3C4 & 0xFFFFFFFC);
      temp_r3 = ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_3C4;
      if (temp_r3 & 0x80000)
    {
      ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_3C4 = (s32) (temp_r3 & 0xFFF7FFFF);
      ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_404 = 2;
      return;
    }
      (((VObj_14_763762 *)(((u8 *) ene_dd) + 1000))->m2());
      ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_404 = 1;
      return;
    case 3:
      if (((s32) ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_404) == 2)
    {
      transition_enemy_state__9TObjEneDDFs(ene_dd, 0);
    }
    case 5:
      return;
    case 0:
      advance_animation_playback(ene_dd, arg1);
      switch (((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_404)
    {
      case 0:
        if (((TObjEneDD *)ene_dd)->get_flag_b4() != 0)
      {
        ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_404 = 1;
      }
        break;
      case 1:
        if ((((VObj_14_763762 *)(((u8 *) ene_dd) + 1000))->m4()) != 0)
      {
        ((RecoveredFields_800E50D8_arg0 *) ene_dd)->field_404 = 2;
      }
        break;
    }
      (((TObjEneDD *)(ene_dd))->vfunc_102());
      break;
  }
}

void TObjEneMe3ShinowaMirage__sub_800E5220(void *ene_dd, s32 arg1) {
    s32 temp_r4;

    switch (arg1) {
    case 4:
        ((TObjEneDD *)ene_dd)->m_b8 = 8;
        ((TObjEneDD *)ene_dd)->set_field_378(0xB);
        *(s32 *)((s8 *)ene_dd + 0x3C4) = (s32) (*(s32 *)((s8 *)ene_dd + 0x3C4) & 0xFFFFFFFC);
        ((TObjEneDD *)ene_dd)->vfunc_95();
        *(s32 *)((s8 *)ene_dd + 0x3D8) = 0;
        *(s32 *)((s8 *)ene_dd + 0x404) = 0;
        return;
    case 3:
        if (update_linked_position__12TObjEneDD_STFf(TObjEneMe3ShinowaMirage__data_805DA5F4) != 0) {
            transition_enemy_state__9TObjEneDDFs(ene_dd, 4);
        } else if ((s32) *(s32 *)((s8 *)ene_dd + 0x404) >= 0x5A) {
            transition_enemy_state__9TObjEneDDFs(ene_dd, 9);
        }
        return;
    case 0:
        temp_r4 = *(s32 *)((s8 *)ene_dd + 0x404);
        *(s32 *)((s8 *)ene_dd + 0x404) = (temp_r4 + 1);
        advance_animation_playback(ene_dd, temp_r4);
        ((TObjEneDD *)ene_dd)->vfunc_102();
        break;
    case 5:
        break;
    }
}

void TObjEneMe3ShinowaMirage::state_cast_support(s32 arg1) {
#define arg0 ((u8 *)this)
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 7;
        ((TObjEneDD *)arg0)->set_field_378(0xA);
        ((VObj_18_800E530C *)arg0)->m94();
        *(s32 *)((s8 *)arg0 + 0x3C4) &= ~3;
        *(s32 *)((s8 *)arg0 + 0x404) = 0;
        *(s32 *)((s8 *)arg0 + 0x408) = 0;
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x408) > TObjEneMe3ShinowaMirage__mirage_info_table[*(s32 *)((s8 *)arg0 + 0x3C0)]->frame_1C) {
            transition_enemy_state__9TObjEneDDFs(arg0, 4);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(arg0, arg1);
        switch (*(s32 *)((s8 *)arg0 + 0x404)) {
        case 0:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                TObjEneMe3ShinowaMirage__sub_800E6F0C((Obj_800E6F0C *)arg0);
                if (TObjEneDD::check_v2_mode() != 0) {
                    *(s32 *)((s8 *)arg0 + 0x404) = 2;
                } else {
                    *(s32 *)((s8 *)arg0 + 0x404) = 1;
                }
                *(s32 *)((s8 *)arg0 + 0x408) = 0;
            }
            break;
        case 1:
            (*(s32 *)((s8 *)arg0 + 0x408))++;
            break;
        case 2:
            (*(s32 *)((s8 *)arg0 + 0x408))++;
            if (*(s32 *)((s8 *)arg0 + 0x408) == 5) {
                TTecSifta::create((void *)arg0, arg0 + 0x38, (void *)(TObjEneDD::clamp_frame_index(TObjEneMe3ShinowaMirage__mirage_info_table[*(s32 *)((s8 *)arg0 + 0x3C0)]->frame)));
            } else if (*(s32 *)((s8 *)arg0 + 0x408) == 0xA) {
                create__10TTecDebandFlll(arg0, arg0 + 0x38, TObjEneDD::clamp_frame_index(TObjEneMe3ShinowaMirage__mirage_info_table[*(s32 *)((s8 *)arg0 + 0x3C0)]->frame));
                *(s32 *)((s8 *)arg0 + 0x404) = 1;
                *(s32 *)((s8 *)arg0 + 0x408) = 0;
            }
            break;
        }
        ((VObj_18_800E530C *)arg0)->m100();
        break;
    }
}
#undef arg0

#define arg0 ((u8 *)arg0_)
#define F(t, o) (*(t *)(arg0 + (o)))
#define VO ((VObj_18_a1ce10 *)(arg0))

#pragma push
#pragma opt_common_subs off
void TObjEneMe3ShinowaMirage__sub_800E54E8(void *arg0_, s32 arg1) {
    Vec_800E4FE8 savePos;
    Vec_800E4FE8 save2FC;
    Vec_800E4FE8 dest;
    s32 rot[3];
    f32 v;
    u8 *home = arg0 + 0x418;

    switch (arg1) {
    case 4: {
        F(s32, 0x3C4) &= ~3;
        VO->m94();
        VO->m92();
        F(s32, 0x404) = 0;
        F(s32, 0x408) = 0;
        F(f32, 0x410) = TObjEneMe3ShinowaMirage__data_805DA5DC;
        F(f32, 0x37C) = lbl_805DA5F8;
        F(s32, 0x40C) = ((F(s32, 0x3D4) - (s32)get_random_float__21TObjEneMe3ShinowaRealFv(lbl_805DA5FC, TObjEneMe3ShinowaMirage__data_805DA5DC)) * 0x3333) / 40;
        VecCopy((Vec *)home, (const Vec *)(arg0 + 0x38));
        F(void *, 0x424) = 0;
        F(void *, 0x428) = 0;
        ((TObjEneDD_ST *)arg0)->set_active();
        break;
    }
    case 3: {
        if (F(s32, 0x404) >= 40) {
            TObjEneMe3Shinowa__sub_800E7268(arg0);
            s32 r = collect_target_candidates__9TObjEneDDFlf(arg0, lbl_805DA600);
            if (r > 0) {
                enemy_set_target_id(arg0, enemy_target_candidate_table[r - 1].id);
                transition_enemy_state__9TObjEneDDFs(arg0, 4);
            } else {
                transition_enemy_state__9TObjEneDDFs(arg0, 11);
            }
        }
        break;
    }
    case 0:
        advance_animation_playback(arg0, arg1);
        F(s32, 0x404)++;
        if (transform_relative_position__9TObjEneDDFPv(arg0, F(void *, 0x390)) != 0) {
            if ((s16)get_room__13TUnk_804B9870Fv((s32)arg0) == (s16)get_room__13TUnk_804B9870Fv(F(s32, 0x390))) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            }
        }
        ((TObjEneDD *)arg0)->update_velocity();
        rotate_xz_pair_by_angle((f32 *)(arg0 + 0x3A0), (f32 *)(arg0 + 0x3A8), (s32)(F(s32, 0x40C)));
        v = F(f32, 0x3AC);
        if (v > lbl_805DA604) {
            v -= TObjEneMe3ShinowaMirage__data_805DA608;
            if (v < lbl_805DA604) {
                v = lbl_805DA604;
            }
        } else if (v < lbl_805DA604) {
            v += TObjEneMe3ShinowaMirage__data_805DA608;
            if (v > lbl_805DA604) {
                v = lbl_805DA604;
            }
        }
        VecCopy((Vec *)&savePos, (const Vec *)(arg0 + 0x38));
        VecCopy((Vec *)&save2FC, (const Vec *)(arg0 + 0x2FC));
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0x394));
        VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x38));
        F(f32, 0x300) += TObjEneMe3ShinowaMirage__data_805DA5EC;
        v *= F(f32, 0x410);
        calc_wall_clamped_destination(arg0, &dest, -F(f32, 0x3A0), -F(f32, 0x3A8), v);
        if (VO->m16(&dest) == 0) {
            F(f32, 0x410) *= lbl_805DA5F0;
            VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&savePos);
            VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)&save2FC);
        } else {
            F(f32, 0x410) = TObjEneMe3ShinowaMirage__data_805DA5DC;
            VecCopy((Vec *)(arg0 + 0x38), (const Vec *)&savePos);
            VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)&save2FC);
            subtract_vector(&dest, arg0 + 0x38);
            f32 len = ((TObjBoss2Tunnel *)(&dest))->clamp_velocity();
            ((TObjEneDD *)arg0)->move_clamped_on_ground(dest.x, dest.z, len);
        }
        F(s32, 0x60) = (s32)(TObjEneMe3ShinowaMirage__data_8043CFE0 * atan2_float(F(f32, 0x3A0), F(f32, 0x3A8)));
        if (F(s32, 0x40C) != 0) {
            rot[0] = 0;
            if (F(s32, 0x40C) > 0) {
                rot[1] = F(s32, 0x60);
            } else {
                rot[1] = F(s32, 0x60) - 0x8000;
            }
            rot[2] = -0x4000;
            if (F(void *, 0x424) == 0) {
                F(void *, 0x424) = create_particle_emitter(arg0 + 0x38, 0x115);
                if (F(void *, 0x424) != 0) {
                    ((TParticleCtrl *)(F(void *, 0x424)))->enable();
                    ((TBoss4Type2 *)(F(void *, 0x424)))->set_flags(2);
                }
            } else {
                ((TBoss4Type2 *)(F(void *, 0x424)))->copy_vec3(rot);
                ((TNowLoading *)(F(void *, 0x424)))->copy_pos(arg0 + 0x38);
            }
            if (F(void *, 0x428) == 0) {
                F(void *, 0x428) = create_particle_emitter(arg0 + 0x38, 0x116);
                if (F(void *, 0x428) != 0) {
                    ((TParticleCtrl *)(F(void *, 0x428)))->enable();
                    ((TBoss4Type2 *)(F(void *, 0x428)))->set_flags(2);
                }
            } else {
                ((TBoss4Type2 *)(F(void *, 0x428)))->copy_vec3(rot);
                ((TNowLoading *)(F(void *, 0x428)))->copy_pos(arg0 + 0x38);
            }
        }
        VO->m86();
        break;
    case 5:
        VO->m91();
        F(f32, 0x37C) = TObjEneMe3ShinowaMirage__data_805DA5E8;
        if (F(void *, 0x424) != 0) {
            queue_destruction__7TObjectFv(F(void *, 0x424));
            F(void *, 0x424) = 0;
        }
        if (F(void *, 0x428) != 0) {
            queue_destruction__7TObjectFv(F(void *, 0x428));
            F(void *, 0x428) = 0;
        }
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}

#pragma pop
#undef arg0
#undef F
#undef VO

void TObjEneMe3ShinowaReal__sub_800E5950(u8 *arg0, s32 arg1) {
    s32 temp_r5;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 2;
        ((TObjEneDD *)arg0)->set_field_378(7);
        ((TObjEneDD *)(arg0))->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C4) &= 0xFFFFFFFC;
        *(s32 *)((s8 *)arg0 + 0x3D8) = 0;
        *(s32 *)((s8 *)arg0 + 0x404) = 3;
        if (((VObj_18_dc3190 *)(arg0))->m102(TObjEneMe3ShinowaMirage__data_805DA5F4) != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            ((TObjEneDD *)arg0)->update_velocity();
            *(s32 *)((s8 *)arg0 + 0x40C) = (s32) (TObjEneMe3ShinowaMirage__data_8043CFE0 * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8))));
            if (((s32 (*)(void *, s32, f32))check_body_collision_at__17TObjEneMe3ShinowaFlf)(arg0, (int) (*(s32 *)((s8 *)arg0 + 0x40C) + 0x8000), lbl_805DA604) == 0) {
                *(f32 *)((s8 *)arg0 + 0x3A0) = (f32) (*(f32 *)((s8 *)arg0 + 0x3A0) * lbl_805DA5BC);
                *(f32 *)((s8 *)arg0 + 0x3A8) = (f32) (*(f32 *)((s8 *)arg0 + 0x3A8) * lbl_805DA5BC);
                *(s32 *)((s8 *)arg0 + 0x404) = 0;
                *(f32 *)((s8 *)arg0 + 0x410) = (f32) lbl_805DA60C;
            }
        }
        ((TObjEneDD_ST *)arg0)->set_active();
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x404) == 3) {
            if (((s32 (*)(void))sub_800E6FE0__17TObjEneMe3ShinowaFv)() != 0) {
                transition_enemy_state__9TObjEneDDFs(arg0, 0xA);
            } else if ((*(s32 *)((s8 *)arg0 + 0x3C4) & 0x20000) || (((TObjEneMe3Shinowa *)arg0)->sub_800E701C() == 0)) {
                *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFCFFFF);
                if ((TObjEneDD::check_v2_mode() != 0) && (((TObjEneMe3Shinowa *)arg0)->sub_800E701C() == 0)) {
                    transition_enemy_state__9TObjEneDDFs(arg0, 0x10);
                } else {
                    transition_enemy_state__9TObjEneDDFs(arg0, 4);
                }
            } else {
                *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) | 0x20000);
                transition_enemy_state__9TObjEneDDFs(arg0, 0xE);
            }
        }
        break;
    case 0:
        ((s32 (*)(void))advance_animation_playback)();
        switch (*(s32 *)((s8 *)arg0 + 0x404)) {
        case 0:
            *(s32 *)((s8 *)arg0 + 0x60) = approach_angle_limited((int) (*(s32 *)((s8 *)arg0 + 0x60)), (int) (*(s32 *)((s8 *)arg0 + 0x40C)), 0x31C7);
            if ((*(f32 *)((s8 *)arg0 + 0xC0) + *(f32 *)((s8 *)arg0 + 0xC8)) >= TObjEneMe3ShinowaReal__data_805DA5CC) {
                *(s32 *)((s8 *)arg0 + 0x404) = 1;
                ((TObjEneDD *)(arg0))->vfunc_91();
                play_sound_effect((void *) copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD11), arg0 + 0x38, 0, 0);
            }
            ((TObjEneDD *)(arg0))->vfunc_102();
            ((TObjEneDD *)(arg0))->vfunc_89();
            return;
        case 1:
            if ((*(f32 *)((s8 *)arg0 + 0xC0) + *(f32 *)((s8 *)arg0 + 0xC8)) >= lbl_805DA610) {
                *(s32 *)((s8 *)arg0 + 0x404) = 2;
                ((TObjEneDD *)(arg0))->vfunc_92();
                play_sound_effect((void *) copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD12), arg0 + 0x38, 0, 0);
                spawn_particle_effect(arg0 + 0x38, 0xF3);
            }
            ((TObjEneDD *)arg0)->move_clamped_on_ground((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8)), (f32) (*(f32 *)((s8 *)arg0 + 0x410)));
            ((TObjEneDD *)(arg0))->vfunc_88();
            return;
        case 2:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)arg0 + 0x404) = 3;
            }
            ((TObjEneDD *)(arg0))->vfunc_102();
            ((TObjEneDD *)(arg0))->vfunc_89();
            return;
        }
        break;
    case 5:
        ((TObjEneDD *)(arg0))->vfunc_92();
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E5CE4(u8 *ene_epsilon, s32 arg1) {
    s32 var_r4;
    Info_800E5CE4 *info;
    switch (arg1) {
    case 4:
        ((TObjEneEpsilon *)ene_epsilon)->m_b8 = 6;
        ((TObjEneDD *)ene_epsilon)->set_field_378(6);
        ((TObjEneEpsilon *)(ene_epsilon))->vfunc_96();
        *(s32 *)((s8 *)ene_epsilon + 0x3C4) = (s32) (*(s32 *)((s8 *)ene_epsilon + 0x3C4) & 0xFFFFFFFC);
        *(s32 *)((s8 *)ene_epsilon + 0x3C4) = (s32) (*(s32 *)((s8 *)ene_epsilon + 0x3C4) | 0x10000);
        *(s32 *)((s8 *)ene_epsilon + 0x404) = 0;
        *(s32 *)((s8 *)ene_epsilon + 0x408) = 0;
        ((TBoss4Type3 *)(*(void **)((s8 *)ene_epsilon + 0x3E0)))->reset_timer();
        ((TBoss4Type3 *)(*(void **)((s8 *)ene_epsilon + 0x3E4)))->reset_timer();
        break;
    case 3:
        if (((TObjEneDD *)ene_epsilon)->get_flag_b4() != 0) {
            ((VObj_18_4f5f2e *)(ene_epsilon))->m105();
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(ene_epsilon, arg1);
        switch (*(s32 *)((s8 *)ene_epsilon + 0x404)) {
        case 0:
            ((VObj_18_4f5f2e *)(ene_epsilon))->m103();
            if (((TObjEneEpsilon *)ene_epsilon)->m_c0 < TObjEneMe3ShinowaMirage__data_805DA5EC) {
                if (((TObjEneEpsilon *)ene_epsilon)->update_death_check() != 0) {
                    ((TObjEneDD_ST *)ene_epsilon)->enemy_copy_target_destination();
                    ((TObjEneDD *)ene_epsilon)->update_velocity();
                    var_r4 = (s32) (TObjEneMe3ShinowaMirage__data_8043CFE0 * atan2_float(((TObjEneEpsilon *)ene_epsilon)->m_3a0, *(f32 *)((s8 *)ene_epsilon + 0x3A8)));
                } else {
                    var_r4 = ((TObjEneEpsilon *)ene_epsilon)->rotation_y;
                }
                ((TObjEneEpsilon *)ene_epsilon)->rotation_y = approach_angle_limited(((TObjEneEpsilon *)ene_epsilon)->rotation_y, var_r4, 0x300);
                ((TObjEneEpsilon *)ene_epsilon)->m_3a0 = sin_table_lookup(((TObjEneEpsilon *)ene_epsilon)->rotation_y);
                *(f32 *)((s8 *)ene_epsilon + 0x3A8) = cos_table_lookup(((TObjEneEpsilon *)ene_epsilon)->rotation_y);
            }
            ((VObj_18_4f5f2e *)(ene_epsilon))->m110();
            if (((TObjEneEpsilon *)ene_epsilon)->m_c0 >= TObjEneMe3ShinowaMirage__data_805DA5B8 && ((TObjEneEpsilon *)ene_epsilon)->m_c0 <= lbl_805DA5D4) {
                info = ((Info_800E5CE4 * *)&TObjEneMe3ShinowaMirage__mirage_info_table)[*(s32 *)((s8 *)ene_epsilon + 0x3C0)];
                move_to_shot_position__9TObjEneDDFfff(ene_epsilon, info, ((TObjEneEpsilon *)ene_epsilon)->m_3a0, *(f32 *)((s8 *)ene_epsilon + 0x3A8), info->f8);
            } else {
                ((TObjEneEpsilon *)(ene_epsilon))->vfunc_102();
            }
            if (((TObjEneEpsilon *)ene_epsilon)->m_c0 >= 25.0f) {
                ((TObjEneEpsilon *)ene_epsilon)->m_c0 = 25.0f;
                *(s32 *)((s8 *)ene_epsilon + 0x404) = 1;
            }
            break;
        case 1:
            (*(s32 *)((s8 *)ene_epsilon + 0x408))++;
            if (*(s32 *)((s8 *)ene_epsilon + 0x408) <= ((Info_800E5CE4 * *)&TObjEneMe3ShinowaMirage__mirage_info_table)[*(s32 *)((s8 *)ene_epsilon + 0x3C0)]->f20) {
                ((TObjEneEpsilon *)ene_epsilon)->m_c0 = TObjEneMe3ShinowaMirage__data_805DA5E4;
            }
            ((TObjEneEpsilon *)(ene_epsilon))->vfunc_102();
            break;
        }
        ((TObjEneEpsilon *)(ene_epsilon))->vfunc_89();
        break;
    }
}

#pragma push
#pragma fp_contract on
#undef TObjEneMe3ShinowaMirage__data_805DA5E8
#undef TObjEneMe3ShinowaMirage__data_805DA5EC
#undef lbl_805DA5F0
#undef TObjEneMe3ShinowaMirage__data_805DA5F4
#undef lbl_805DA5F8
#undef lbl_805DA5FC
#undef lbl_805DA600
#undef lbl_805DA604
#undef TObjEneMe3ShinowaMirage__data_805DA608
#undef lbl_805DA60C
#undef lbl_805DA610
#undef lbl_805DA614
#undef lbl_805DA618
#undef lbl_805DA61C
#undef lbl_805DA620
#undef lbl_805DA624
__declspec(section ".sdata2") extern const u32 TObjEneMe3ShinowaMirage__data_805DA5E8[1] = { 0x41200000 };
__declspec(section ".sdata2") extern const u32 TObjEneMe3ShinowaMirage__data_805DA5EC[1] = { 0x41a00000 };
__declspec(section ".sdata2") extern const u32 lbl_805DA5F0[1] = { 0x3f4ccccd };
__declspec(section ".sdata2") extern const u32 TObjEneMe3ShinowaMirage__data_805DA5F4[1] = { 0x43480000 };
__declspec(section ".sdata2") extern const u32 lbl_805DA5F8[1] = { 0x41f00000 };
__declspec(section ".sdata2") extern const u32 lbl_805DA5FC[1] = { 0x40200000 };
__declspec(section ".sdata2") extern const u32 lbl_805DA600[1] = { 0x471c4000 };
__declspec(section ".sdata2") extern const u32 lbl_805DA604[1] = { 0x42a00000 };
__declspec(section ".sdata2") extern const u32 TObjEneMe3ShinowaMirage__data_805DA608[1] = { 0x40400000 };
__declspec(section ".sdata2") extern const u32 lbl_805DA60C[1] = { 0x40e38e39 };
__declspec(section ".sdata2") extern const u32 lbl_805DA610[1] = { 0x41c00000 };
__declspec(section ".sdata2") extern const u32 lbl_805DA614[1] = { 0x41600000 };
__declspec(section ".sdata2") extern const u32 lbl_805DA618[1] = { 0x414db6dc };
__declspec(section ".sdata2") extern const u32 lbl_805DA61C[1] = { 0x41b80000 };
__declspec(section ".sdata2") extern const u32 lbl_805DA620[1] = { 0x3f59999a };
__declspec(section ".sdata2") extern const u32 lbl_805DA624[1] = { 0x43960000 };
#define TObjEneMe3ShinowaMirage__data_805DA5E8 (*(const f32 *)TObjEneMe3ShinowaMirage__data_805DA5E8)
#define TObjEneMe3ShinowaMirage__data_805DA5EC (*(const f32 *)TObjEneMe3ShinowaMirage__data_805DA5EC)
#define lbl_805DA5F0 (*(const f32 *)lbl_805DA5F0)
#define TObjEneMe3ShinowaMirage__data_805DA5F4 (*(const f32 *)TObjEneMe3ShinowaMirage__data_805DA5F4)
#define lbl_805DA5F8 (*(const f32 *)lbl_805DA5F8)
#define lbl_805DA5FC (*(const f32 *)lbl_805DA5FC)
#define lbl_805DA600 (*(const f32 *)lbl_805DA600)
#define lbl_805DA604 (*(const f32 *)lbl_805DA604)
#define TObjEneMe3ShinowaMirage__data_805DA608 (*(const f32 *)TObjEneMe3ShinowaMirage__data_805DA608)
#define lbl_805DA60C (*(const f32 *)lbl_805DA60C)
#define lbl_805DA610 (*(const f32 *)lbl_805DA610)
#define lbl_805DA614 (*(const f32 *)lbl_805DA614)
#define lbl_805DA618 (*(const f32 *)lbl_805DA618)
#define lbl_805DA61C (*(const f32 *)lbl_805DA61C)
#define lbl_805DA620 (*(const f32 *)lbl_805DA620)
#define lbl_805DA624 (*(const f32 *)lbl_805DA624)

void TObjEneMe3ShinowaMirage__sub_800E5F64(u8 *arg0, s32 arg1) {
    Vec_800E5F64 sp20;
    Vec_800E5F64 sp14;
    Vec_800E5F64 v;
    f32 d;
    s32 var_r4;
    s32 entry;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 5;
        ((TObjEneDD *)arg0)->set_field_378(4);
        ((TObjEneDD *)(arg0))->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C4) &= ~3;
        *(s32 *)((s8 *)arg0 + 0x3C4) |= 0x10000;
        *(s32 *)((s8 *)arg0 + 0x404) = 0;
        *(f32 *)((s8 *)arg0 + 0x410) = TObjEneMe3ShinowaMirage__data_805DA5B8;
        ((TBoss4Type3 *)(*(u8 **)((s8 *)arg0 + 0x3E0)))->reset_timer();
        ((TObjEneDD_ST *)arg0)->set_active();
        break;
    case 3:
        if (*(s32 *)((s8 *)arg0 + 0x404) == 5 || ((int)((TObjEneDD *)arg0)->get_flag_b4()) != 0) {
            if (((TObjEneDD *)(arg0))->vfunc_102() == 0U) {
                transition_enemy_state__9TObjEneDDFs(arg0, 9);
            } else {
                transition_enemy_state__9TObjEneDDFs(arg0, 4);
            }
        }
        break;
    case 0:
        switch (*(s32 *)((s8 *)arg0 + 0x404)) {
        case 0:
            advance_animation_playback(arg0, arg1);
            if (*(s32 *)((s8 *)arg0 + 0xB0) & 8) {
                *(s32 *)((s8 *)arg0 + 0x404) = 1;
            }
            ((TObjEneDD *)(arg0))->vfunc_102();
            ((TObjEneDD *)(arg0))->vfunc_89();
            break;
        case 1:
            advance_animation_playback(arg0, arg1);
            if (((TObjEneEpsilon *)arg0)->update_death_check() != 0) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                ((TObjEneDD *)arg0)->update_velocity();
                var_r4 = (s32)(TObjEneMe3ShinowaMirage__data_8043CFE0 * atan2_float(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8)));
            } else {
                var_r4 = *(s32 *)((s8 *)arg0 + 0x60);
            }
            *(s32 *)((s8 *)arg0 + 0x60) = approach_angle_limited(*(s32 *)((s8 *)arg0 + 0x60), var_r4, 0x1000);
            if (objInBand((GameObj *)arg0, (f32)TObjEneMe3ShinowaMirage__data_805DA5E8) != 0) {
                *(s32 *)((s8 *)arg0 + 0x404) = 2;
            }
            ((TObjEneDD *)(arg0))->vfunc_102();
            ((TObjEneDD *)(arg0))->vfunc_89();
            break;
        case 2:
            advance_animation_playback(arg0, arg1);
            if (((TObjEneEpsilon *)arg0)->update_death_check() != 0) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
                ((TObjEneDD *)arg0)->update_velocity();
            }
            if (*(f32 *)((s8 *)arg0 + 0xC0) + *(f32 *)((s8 *)arg0 + 0xC8) >= lbl_805DA614) {
                if (((s32 (*)(void *, s32, f32))check_body_collision_at__17TObjEneMe3ShinowaFlf)(arg0, *(s32 *)((s8 *)arg0 + 0x60), *(f32 *)((s8 *)arg0 + 0x3AC) - TObjEneMe3ShinowaMirage__data_805DA5EC) != 0) {
                    *(s32 *)((s8 *)arg0 + 0x404) = 5;
                } else {
                    d = *(f32 *)((s8 *)arg0 + 0x3AC) - TObjEneMe3ShinowaMirage__data_805DA5EC;
                    VecCopy((Vec *)&v, (const Vec *)(arg0 + 0x38));
                    v.x += *(f32 *)((s8 *)arg0 + 0x3A0) * d;
                    v.y += TObjEneMe3ShinowaMirage__data_805DA5EC;
                    v.z += *(f32 *)((s8 *)arg0 + 0x3A8) * d;
                    if (csnVecterUnder(&v, 0x15) != 0U) {
                        *(s32 *)((s8 *)arg0 + 0x404) = 3;
                        *(f32 *)((s8 *)arg0 + 0x414) = (*(f32 *)((s8 *)arg0 + 0x3AC) - TObjEneMe3ShinowaMirage__data_805DA5EC) / lbl_805DA618;
                        ((TObjEneDD *)(arg0))->vfunc_91();
                        play_sound_effect((void *)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD11), arg0 + 0x38, 0, 0);
                    } else {
                        *(s32 *)((s8 *)arg0 + 0x404) = 5;
                    }
                }
            }
            ((TObjEneDD *)(arg0))->vfunc_102();
            ((TObjEneDD *)(arg0))->vfunc_89();
            break;
        case 3:
            advance_animation_playback(arg0, arg1);
            if (*(f32 *)((s8 *)arg0 + 0xC0) + *(f32 *)((s8 *)arg0 + 0xC8) >= lbl_805DA61C) {
                *(s32 *)((s8 *)arg0 + 0x404) = 4;
                ((TObjEneDD *)(arg0))->vfunc_92();
                play_sound_effect((void *)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD12), arg0 + 0x38, 0, 0);
                spawn_particle_effect(arg0 + 0x38, 0xF3);
            }
            ((TObjEneDD *)arg0)->move_with_wall_slide_commit(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8), *(f32 *)((s8 *)arg0 + 0x414));
            ((TObjEneDD *)(arg0))->vfunc_88();
            break;
        case 4:
            advance_animation_playback(arg0, arg1);
            if (objInBand((GameObj *)arg0, (f32)TObjEneMe3ShinowaMirage__data_805DA5E4) != 0) {
                if (((TObjEneDD_ST *)arg0)->enemy_check_target_valid() != 0) {
                    if (((VObj_18_2add4a *)*(u8 **)((s8 *)arg0 + 0x390))->m18(arg0, TObjEneMe3ShinowaMirage__data_805DA5DC) != 0) {
                        ((VObj_18_2add4a *)*(u8 **)((s8 *)arg0 + 0x390))->m20(arg0, TObjEneMe3ShinowaMirage__data_805DA5DC);
                        ((VObj_18_2add4a *)*(u8 **)((s8 *)arg0 + 0x390))->m23(arg0, TObjEneMe3ShinowaMirage__data_805DA608);
                    }
                }
                play_sound_effect((void *)copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD13), arg0 + 0x38, 0, 0);
            }
            *(f32 *)((s8 *)arg0 + 0x414) *= lbl_805DA620;
            ((TObjEneDD *)arg0)->move_with_wall_slide_on_ground(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8), *(f32 *)((s8 *)arg0 + 0x414));
            ((TObjEneDD *)(arg0))->vfunc_89();
            break;
        }
        if (*(s32 *)((s8 *)arg0 + 0x404) != 0) {
            entry = TObjPlayer::lookup_entry_by_value((void *)TObjEneMe3ShinowaMirage__data_805D52AC, *(f32 *)((s8 *)arg0 + 0xC0));
            if (entry != 0) {
                push_matrix();
                set_matrix_identity(0);
                post_translate_matrix(arg0 + 0x38);
                rotate_matrix_y(0, *(s32 *)((s8 *)arg0 + 0x60));
                mult_vec_array__10TObjPlayerFUll(0, entry, &sp14, 2);
                pop_matrix();
                ((VObj_18_2add4a *)*(u8 **)((s8 *)arg0 + 0x3E0))->m4((s32 *)&sp14, (s32 *)&sp20);
            }
        }
        break;
    case 5:
        *(f32 *)((s8 *)arg0 + 0x3C8) = *(f32 *)((s8 *)arg0 + 0x3C);
        *(f32 *)((s8 *)arg0 + 0x3CC) = TObjEneMe3ShinowaMirage__data_805DA5B8;
        ((TObjEneDD *)(arg0))->vfunc_92();
        ((TObjEneDD *)arg0)->clear_field_388();
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneMe3ShinowaMirage::state_chase_target(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        this->m_b8 = 9;
        ((TObjEneDD *)arg0)->set_field_378(4);
        this->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFC);
        *(f32 *)((s8 *)arg0 + 0x3AC) = (f32) lbl_805DA624;
        if (*(s32 *)((s8 *)arg0 + 0x3C4) & 0x10) {
            *(f32 *)((s8 *)arg0 + 0x410) = (f32) *(f32 *)((s8 *)TObjEneMe3ShinowaMirage__mirage_info_table[*(s32 *)((s8 *)arg0 + 0x3C0)] + 4);
        } else {
            *(f32 *)((s8 *)arg0 + 0x410) = (f32) *(f32 *)((s8 *)TObjEneMe3ShinowaMirage__mirage_info_table[*(s32 *)((s8 *)arg0 + 0x3C0)] + 0);
        }
        *(f32 *)((s8 *)arg0 + 0x414) = (f32) TObjEneMe3ShinowaMirage__data_805DA5B8;
        return;
    case 3:
        if ((u32) this->m_390 == 0U) {
            this->vfunc_111();
            transition_enemy_state__9TObjEneDDFs(arg0, 0xB);
        } else if (((s32 (*)(f32))check_in_range__23TObjEneMe3ShinowaMirageFPv)((f32) (*(f32 *)((s8 *)arg0 + 0x414))) != 0) {
            transition_enemy_state__9TObjEneDDFs(arg0, 6);
        } else if (((VObj_18_e66632 *)(arg0))->m104() != 0) {
            transition_enemy_state__9TObjEneDDFs(arg0, 5);
        }
        break;
    case 5:
        break;
    case 0:
        ((void (*)())advance_animation_playback)();
        if (((s32 (*)(void *, f32))update_linked_position__12TObjEneDD_STFf)(arg0, TObjEneMe3ShinowaMirage__data_805DA5F4) != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            ((TObjEneDD *)arg0)->update_velocity();
            *(f32 *)((s8 *)arg0 + 0x414) = (f32) ((*(f32 *)((s8 *)arg0 + 0x3A0) * sin_table_lookup(this->rotation_y)) + (*(f32 *)((s8 *)arg0 + 0x3A8) * cos_table_lookup(this->rotation_y)));
            if (*(f32 *)((s8 *)arg0 + 0x414) < cos_table_lookup(0x1000)) {
                ((TObjEneEpsilon *)arg0)->update_angle(0x500);
                this->vfunc_102();
            } else {
                enemy_turn_and_move_on_ground((arg0), 0x500, (f32) (*(f32 *)((s8 *)arg0 + 0x410)));
            }
            this->vfunc_89();
        }
        break;
    }
}
#pragma pop

void TObjEneMe3ShinowaMirage__sub_800E66FC(u8 *arg0, s32 arg1) {
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f31;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        ((TObjEneDD *)arg0)->set_field_378(0xB);
        ((TObjEneDD *)(arg0))->vfunc_96();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFD);
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) | 1);
        *(s32 *)((s8 *)arg0 + 0x404) = 0;
        *(f32 *)((s8 *)arg0 + 0x410) = (f32) TObjEneMe3ShinowaMirage__data_805DA5B8;
        if (((TObjEneDD_ST *)arg0)->enemy_has_live_target() != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            ((TObjEneDD *)arg0)->update_velocity();
            *(s32 *)((s8 *)arg0 + 0x40C) = (s32) (TObjEneMe3ShinowaMirage__data_8043CFE0 * ((f32 (*)(f64, f64))atan2_float)((f64) *(f32 *)((s8 *)arg0 + 0x3A0), (f64) *(f32 *)((s8 *)arg0 + 0x3A8)));
            return;
        }
        *(s32 *)((s8 *)arg0 + 0x40C) = (s32) *(s32 *)((s8 *)arg0 + 0x60);
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x404) == 3) {
            transition_enemy_state__9TObjEneDDFs(arg0, 0xB);
        }
        return;
    case 0:
        switch (*(s32 *)((s8 *)arg0 + 0x404)) {
        case 0:
            temp_f31 = ((TObjEneMe3Shinowa *)arg0)->get_node_world_y();
            ((s32 (*)(void *))advance_animation_playback)(arg0);
            *(f32 *)((s8 *)arg0 + 0x414) = ((TObjEneMe3Shinowa *)arg0)->get_node_world_y();
            *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C8) + (temp_f31 - *(f32 *)((s8 *)arg0 + 0x414)));
            *(s32 *)((s8 *)arg0 + 0x60) = (s32) (*(s32 *)((s8 *)arg0 + 0x60) + 0x8000);
            *(s32 *)((s8 *)arg0 + 0x404) = 1;
            *(f32 *)((s8 *)arg0 + 0x3CC) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C8) - *(f32 *)((s8 *)arg0 + 0x3C));
            break;
        case 1:
            ((s32 (*)(void *))advance_animation_playback)(arg0);
            if (*(f32 *)((s8 *)arg0 + 0xC0) > 29.0f) {
                *(f32 *)((s8 *)arg0 + 0xC0) = 29.0f;
            }
            *(s32 *)((s8 *)arg0 + 0x60) = ((s32 (*)(s32, s32, s32))approach_angle_limited)(*(s32 *)((s8 *)arg0 + 0x60), *(s32 *)((s8 *)arg0 + 0x40C), 0x800);
            *(f32 *)((s8 *)arg0 + 0x410) = (f32) (*(f32 *)((s8 *)arg0 + 0x410) - 0.3f);
            if (*(f32 *)((s8 *)arg0 + 0x410) < -5.0f) {
                *(f32 *)((s8 *)arg0 + 0x410) = -5.0f;
            }
            *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C8) + *(f32 *)((s8 *)arg0 + 0x410));
            temp_f1 = ((TObjEneMe3Shinowa *)arg0)->get_node_world_y();
            *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C8) - (temp_f1 - *(f32 *)((s8 *)arg0 + 0x414)));
            *(f32 *)((s8 *)arg0 + 0x414) = temp_f1;
            if (*(f32 *)((s8 *)arg0 + 0x3C8) < *(f32 *)((s8 *)arg0 + 0x3C)) {
                *(f32 *)((s8 *)arg0 + 0x3C8) = *(f32 *)((s8 *)arg0 + 0x3C);
                *(s32 *)((s8 *)arg0 + 0x404) = 2;
                ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD12), (u32)(arg0 + 0x38), 0, 0);
                ((s32 (*)(s32, s32))spawn_particle_effect)((s32)(arg0 + 0x38), 0xF3);
            }
            break;
        case 2:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                *(s16 *)((s8 *)arg0 + 0xB8) = 8;
                *(s32 *)((s8 *)arg0 + 0x404) = 3;
                *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
                *(f32 *)((s8 *)arg0 + 0x3CC) = (f32) TObjEneMe3ShinowaMirage__data_805DA5B8;
            }
            ((s32 (*)(void *))advance_animation_playback)(arg0);
            break;
        }
        ((TObjEneDD *)(arg0))->vfunc_102();
        ((TObjEneMe3ShinowaMirage *)arg0)->update_by_distance();
        ((TObjEneDD *)(arg0))->vfunc_89();
        *(f32 *)((s8 *)arg0 + 0x3CC) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C8) - *(f32 *)((s8 *)arg0 + 0x3C));
        return;
    case 5:
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFE);
        *(f32 *)((s8 *)arg0 + 0x3CC) = (f32) TObjEneMe3ShinowaMirage__data_805DA5B8;
        break;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E69F0(u8 *ene_me3_shinowa_mirage, s32 arg1) {
    s32 temp_r3;
    s32 ene_dd_st;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)ene_me3_shinowa_mirage + 0xB8) = 0;
        ((TObjEneDD *)ene_me3_shinowa_mirage)->set_field_378(3);
        ((TObjEneDD *)(ene_me3_shinowa_mirage))->vfunc_95();
        *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) = (s32) (*(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) & 0xFFFFFFFC);
        *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x404) = 0;
        *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x404) > 0x1E) {
            transition_enemy_state__9TObjEneDDFs(ene_me3_shinowa_mirage, 3);
        }
        return;
    case 0:
        ((void (*)())advance_animation_playback)();
        temp_r3 = *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x404);
        if (temp_r3 == 0) {
            if (((s32 (*)(void *, f32))update_linked_position__12TObjEneDD_STFf)(ene_me3_shinowa_mirage, TObjEneMe3ShinowaMirage__data_805DA5F4) != 0) {
                *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x404) = 1;
                if (!(*(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) & 0x1000)) {
                    *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) = 0x1C00FFFF;
                }
                *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) = (s32) (*(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) & lbl_805DA634);
                *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408) = 0;
            }
        } else {
            *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x404) = (temp_r3 + 1);
            *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408) = (s32) (*(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408) + 0x10);
            if ((s32) *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408) > 0xFF) {
                *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408) = 0xFF;
            }
            ene_dd_st = *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x408);
            *(u32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) = (ene_dd_st << 24) | (*(u32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) & 0x00FFFFFF);
            if (enemy_validate_retained_target(ene_me3_shinowa_mirage, ene_dd_st) == 0) {
                *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x404) = 0;
                if (!(*(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) & 0x1000)) {
                    *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) = 0;
                }
            }
        }
        ((TObjEneDD *)(ene_me3_shinowa_mirage))->vfunc_102();
        ((TObjEneMe3ShinowaMirage *)ene_me3_shinowa_mirage)->update_by_distance();
        ((TObjEneDD *)(ene_me3_shinowa_mirage))->vfunc_89();
        *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x3CC) = (f32) (*(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C8) - *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C));
        return;
    case 5:
        if (!(*(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3C4) & 0x1000)) {
            *(s32 *)((s8 *)ene_me3_shinowa_mirage + 0x3D0) = 0x1C00FFFF;
        }
        *(f32 *)((s8 *)ene_me3_shinowa_mirage + 0x3CC) = (f32) TObjEneMe3ShinowaMirage__data_805DA5B8;
        break;
    }
}

void TObjEneMe3Shinowa::sub_800E6BB8(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    Stack_800E6BB8 stack;
    f32 temp_f1;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        ((TObjEneDD *)arg0)->set_field_378(0);
        this->vfunc_95();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFC);
        TObjEneMe3SinowZoa__sub_800D758C(arg0 + 0x3E8);
        VecCopy((Vec *)(&stack.sp8), (const Vec *)(arg0 + 0x38));
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x3C8);
        stack.spC = temp_f1 - TObjEneMe3ShinowaMirage__data_805DA5EC;
        TBoss3Volopt__sub_800D8D88(&stack.sp8, temp_f1);
        return;
    case 3:
        if (((VObj_14_948132 *)(arg0 + (1000)))->m5() != 0) {
            transition_enemy_state__9TObjEneDDFs(arg0, 2);
        }
    case 5:
    case 0:
        return;
    }
}

void TObjEneMe3Shinowa::action(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)arg0 + 0xB8) = 1;
        ((TObjEneDD *)arg0)->set_field_378(1);
        this->vfunc_95();
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) | 2);
        *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFFE);
        if (TObjEneDD::check_v2_mode() != 0) {
            *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFCFFFF);
        }
        *(s32 *)((s8 *)arg0 + 0x404) = 0;
        VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg0 + 0x50));
        VecCopy((Vec *)(arg0 + 0x44), (const Vec *)(arg0 + 0x50));
        VecCopy((Vec *)(arg0 + 0x2FC), (const Vec *)(arg0 + 0x50));
        *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
        if (!(*(s32 *)((s8 *)arg0 + 0x3C4) & 0x1000)) {
            *(s32 *)((s8 *)arg0 + 0x3D0) = 0;
        }
        *(s32 *)((s8 *)arg0 + 0x3D8) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x404) > 5) {
            transition_enemy_state__9TObjEneDDFs(arg0, 1);
        }
    case 5:
        return;
    case 0:
        *(s32 *)((s8 *)arg0 + 0x404) = (s32) (*(s32 *)((s8 *)arg0 + 0x404) + 1);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x404) == 1) {
            *(f32 *)((s8 *)arg0 + 0x3C8) = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
            this->vfunc_102();
            *(f32 *)((s8 *)arg0 + 0x3CC) = (f32) (*(f32 *)((s8 *)arg0 + 0x3C8) - *(f32 *)((s8 *)arg0 + 0x3C));
        }
        break;
    }
}

void dispatch_action__23TObjEneMe3ShinowaMirageFPvUii(Obj_800E6DD8 *arg0_, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 0:
        arg0_->v111(arg2);
        return;
    case 1:
        ((TObjEneMe3Shinowa *)arg0_)->sub_800E6BB8(arg2);
        return;
    case 2:
        TObjEneMe3ShinowaMirage__sub_800E69F0((u8 *)arg0_, (s32)arg2);
        return;
    case 3:
        TObjEneMe3ShinowaMirage__sub_800E66FC((u8 *)arg0_, arg2);
        return;
    case 4:
        ((TObjEneMe3ShinowaMirage *)arg0_)->state_chase_target(arg2);
        return;
    case 5:
        TObjEneMe3ShinowaMirage__sub_800E5F64((u8 *)arg0_, (s32)arg2);
        return;
    case 6:
        TObjEneMe3ShinowaMirage__sub_800E5CE4((u8 *)arg0_, (s32)arg2);
        return;
    case 7:
        TObjEneMe3ShinowaReal__sub_800E5950((u8 *)arg0_, (s32)arg2);
        return;
    case 8:
        TObjEneMe3ShinowaMirage__sub_800E54E8(arg0_, arg2);
        return;
    case 11:
        TObjEneMe3ShinowaMirage__sub_800E5220(arg0_, arg2);
        return;
    case 9:
        TObjEneMe3ShinowaMirage__sub_800E50D8((u8 *) arg0_, arg2);
        return;
    case 10:
        ((TObjEneMe3ShinowaMirage *)arg0_)->state_cast_support(arg2);
        return;
    case 12:
        TObjEneMe3ShinowaMirage__sub_800E4FE8((u8 *)arg0_, (s32)arg2);
        return;
    case 13:
        ((TObjEneMe3ShinowaMirage *)arg0_)->state_break_apart(arg2);
        return;
    case 14:
        arg0_->v112(arg2);
        return;
    case 15:
        arg0_->v113(arg2);
        return;
    case 16:
        arg0_->v114(arg2);
    default:
        return;
    }
}

void TObjEneMe3ShinowaMirage__sub_800E6F0C(Obj_800E6F0C *self) {
    s32 f = TObjEneDD::clamp_frame_index(TObjEneMe3ShinowaMirage__mirage_info_table[self->kind]->frame);
    TTecResta::create((void *)self, self->pos, (void *)f);
}

void TObjEneMe3Shinowa::sub_800E6F64() {
    u8 *arg0 = (u8 *)this;
    if (sub_800E6FE0__17TObjEneMe3ShinowaFv(arg0) != 0) {
        *(s32 **)((s8 *)arg0 + 0x24) = &lbl_80500FEC.value;
        initialize_enemy_state__9TObjEneDDFv(arg0, 0x1b);
        *(s32 *)((s8 *)arg0 + 0x3c0) = 1;
        return;
    }
    *(s32 **)((s8 *)arg0 + 0x24) = (s32 *) *(s32 **)((s8 *)(*(u8 **)((s8 *)TObjEneMe3ShinowaMirage__data_805D5298 + 0x42C)) + 0xC);
    initialize_enemy_state__9TObjEneDDFv(arg0, 0x1a);
    *(s32 *)((s8 *)arg0 + 0x3c0) = 0;
}

s32 TObjEneMe3Shinowa::sub_800E6FE0() {
    u8 *arg0 = (u8 *)this;
    return *(f32 *)((s8 *)arg0 + 0x358) >= TObjEneMe3ShinowaMirage__data_805DA5DC;
}

int select_and_apply_target__23TObjEneMe3ShinowaMirageFPv(void* p) { return select_and_apply_target__12TObjEneDD_STFf(p); }

s32 TObjEneMe3Shinowa::sub_800E701C() {
    u8 *arg0 = (u8 *)this;
    return *(f32 *)((s8 *)arg0 + 0x354) < TObjEneMe3ShinowaMirage__data_805DA5DC;
}

void TObjEneMe3Shinowa::vfunc_89() {
    struct VObj_800E7034_800E47DC *o = (struct VObj_800E7034_800E47DC *)this;
    o->m86();
    ((TObjPlayer *)this)->check_object_collisions();
    check_enemy_body_collisions(this);
}

void TObjEneMe3ShinowaMirage::update_by_distance() {
    VObj_800E707C_800E47DC *o = (VObj_800E707C_800E47DC *)this;
    f32 lim = lbl_805DA5F8;
    if ((*(f32 *)((s8 *)this + 0x3C8) - *(f32 *)((s8 *)this + 0x3C)) > lim) {
        o->m95();
        return;
    }
    o->m96();
}

void TObjEneMe3Shinowa::apply_effect_pair() {
    u8 *arg0 = (u8 *)this;
    s32 sp8[8];
    u32 entry;
    u32 temp_r3_3;

    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix((u8 *)&this->position);
    rotate_matrix_y(0, this->rotation_y);
    entry = TObjPlayer::lookup_entry_by_value((void *)TObjEneMe3ShinowaMirage__data_805D52A4, this->m_c0);
    if (entry != 0U) {
        mult_vec_array__10TObjPlayerFUll(0, entry, &sp8, 2);
        ((VObj18b_800e70d4_800E47DC *) ((unsigned char *) (*(void **)((s8 *)arg0 + 0x3E0))))->m4(&sp8, &sp8[3]);
    }
    temp_r3_3 = TObjPlayer::lookup_entry_by_value((void *)TObjEneMe3ShinowaMirage__data_805D52A8, this->m_c0);
    if (temp_r3_3 != 0U) {
        mult_vec_array__10TObjPlayerFUll(0, temp_r3_3, &sp8, 2);
        ((VObj18b_800e70d4_800E47DC *) ((unsigned char *) (*(void **)((s8 *)arg0 + 0x3E4))))->m4(&sp8, &sp8[3]);
    }
    pop_matrix();
}

#undef PAD_VIRT
#undef PADV
#undef PADV4
void TObjEneMe3Shinowa::vfunc_111() {  }

void TObjEneMe3Shinowa::dispatch_if_active() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 == 1) || (temp_r0 == 9) || (*(s32 *)((s8 *)arg0 + 0x3C4) & 0x80000)) {
        ((E71ACObj_800e71ac_800E71A8*)(arg0 + 0x3E8))->m7();
    }
}

s32 TObjEneMe3Shinowa::update_effect() {
    u8 *arg0 = (u8 *)this;
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 == 1) || (temp_r0 == 9) || (*(s32 *)((s8 *)arg0 + 0x3C4) & 0x80000)) {
        ((E71FCObj_800e71fc_800E71A8*)(arg0 + 0x3E8))->m6();
    }
    return 0;
}

void TObjEneMe3ShinowaReal::sub_800E7250() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) & 0xFFFFFFEF);
    this->m_2cc = (s16) *(s16 *)((s8 *)arg0 + 0x3DC);
}

void TObjEneMe3Shinowa__sub_800E7268(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x3C4) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C4) | 0x10);
    *(s16 *)((s8 *)arg0 + 0x2CC) = (s16) ((s16) *(s16 *)((s8 *)arg0 + 0x3DC) / 2);
}

void TObjEneMe3Shinowa::vfunc_107() {  }

#pragma push
#pragma fp_contract on
u8 TObjEneMe3Shinowa::can_hit_same_target() {
    s16 mine;
    s32 ret;
    s16 theirs;
    ret = 0;
    if (!(((E_800E728C *)this)->f3c4 & 0x10000)) {
        if (((E_800E728C *)this)->f3ac > lbl_805DA638 && ((E_800E728C *)this)->f3ac < lbl_805DA63C) {
            mine = get_room__13TUnk_804B9870Fv((int)((E_800E728C *)this));
            theirs = get_room__13TUnk_804B9870Fv(((E_800E728C *)this)->f390);
            if (theirs == mine && ((s32 (*)(void *, s32, f32))check_body_collision_at__17TObjEneMe3ShinowaFlf)(((E_800E728C *)this), ((E_800E728C *)this)->f60, ((E_800E728C *)this)->f3ac - (*(f32 *)&TObjEneMe3ShinowaMirage__data_805DA5EC)) == 0) {
                ret = 1;
            }
        }
    }
    return (u8)ret;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjEneMe3Shinowa::update_player_state_default() {
    u8 *arg0 = (u8 *)this;
    typedef char sp8_offset[(offsetof(Stack_800E7324, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800E7324, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800E7324, sp10) == 0x8) ? 1 : -1];
    Stack_800E7324 stack;
    if (!(*(s32 *)((s8 *)arg0 + 0x3C4) & 0x80000)) {
        stack.sp8 = *(s32 *)((s8 *)&lbl_8043CF94.value + 0);
        stack.spC = *(s32 *)((s8 *)&lbl_8043CF94.value + 4);
        stack.sp10 = *(s32 *)((s8 *)&lbl_8043CF94.value + 8);
        update_player_state__9TObjEneDDFv(arg0, (void *)&stack.sp8, 0);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma fp_contract on
void TObjEneMe3Shinowa::vfunc_105() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;
    temp_r31 = objInBand((GameObj *)arg0, (f32)lbl_805DA640);
    if ((objInBand((GameObj *)arg0, (f32)lbl_805DA644) != 0) || (temp_r31 != 0)) {
        if (((TObjEneDD_ST *)arg0)->enemy_check_target_valid() != 0) {
            if (((VObj_18_c44252 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x390))))->m18(arg0, TObjEneMe3ShinowaMirage__data_805DA5DC) != 0) {
                ((VObj_18_c44252 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x390))))->m20(arg0, TObjEneMe3ShinowaMirage__data_805DA5DC);
                ((VObj_18_c44252 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x390))))->m23(arg0, TObjEneMe3ShinowaMirage__data_805DA608);
                if ((temp_r31 != 0) && (calc_boss4_scale__10TObjPlayerFi((s32) arg0) <= lbl_805DA648)) {
                    TObjEneDD__sub_800BA438((s32)arg0, (*(u8 **)((s8 *)arg0 + 0x390)));
                }
            }
        }
        ((s32 (*)(s32, u32, s16, s32))play_sound_effect)(copy_target_state__14TObjEnePanarmsFPv(arg0, 0x4003AD13), (u32)(arg0 + 0x38), 0, 0);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
s32 check_in_range__23TObjEneMe3ShinowaMirageFPv(void *arg0) {
    f32 f31;

    if (*(f32 *)((s8 *)arg0 + 0x3AC) > TObjEneMe3ShinowaMirage__data_805DA5E4) {
        return 0;
    }
    f31 = *(f32 *)((s8 *)arg0 + 0x3A8) * ((f32 (*)(s32))cos_table_lookup)(*(s32 *)((s8 *)arg0 + 0x60));
    f31 += *(f32 *)((s8 *)arg0 + 0x3A0) * ((f32 (*)(s32))sin_table_lookup)(*(s32 *)((s8 *)arg0 + 0x60));
    return (s32)((u32)__cntlzw(f31 < ((f32 (*)(s32))cos_table_lookup)(0x1E00)) >> 5);
}
#pragma pop

#pragma push
#pragma fp_contract on
u8 TObjEneMe3Shinowa::check_body_collision_at(s32 arg1, f32 farg0) {
    Obj_800E750C *arg0 = (Obj_800E750C *)this;
    f32 f2 = farg0 * lbl_805DA64C;
    Sub_800E750C *s = *(Sub_800E750C * *)&this->bodies;
    u8 res;
    s32 a = this->rotation_y;
    s32 b = s->f18;
    s->f0 = TObjEneMe3ShinowaMirage__data_805DA5B8;
    s->f8 = f2;
    s->fC = f2;
    s->f10 = lbl_805DA650;
    s->f14 = 1;
    s->f18 = 0x9D01;
    this->rotation_y = arg1;
    ((void (*)(void *, s32, f32, f32))check_enemy_body_collisions)(arg0, arg1, TObjEneMe3ShinowaMirage__data_805DA5B8, f2);
    res = (s->f18 & 0x380000) != 0;
    copy_collision_body((CollisionBody *)s, (const CollisionBody *)shinowa_mirage_model_init_data);
    s->f18 = b;
    this->rotation_y = a;
    return res;
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 TObjEneMe3Shinowa::get_node_world_y() {
    TObjEneMe3Shinowa *self = this;
    Vec_800E75AC v;
    Node_800E75AC *node;
    v.x = TObjEneMe3ShinowaMirage__data_805DA5B8;
    v.y = TObjEneMe3ShinowaMirage__data_805DA5B8;
    v.z = TObjEneMe3ShinowaMirage__data_805DA5B8;
    push_matrix_from(identity_matrix);
    bind_motion_context(self->unknownF8, self->m_c0);
    node = *(Node_800E75AC * *)&self->model;
    compose_motion_node_matrix(node);
    compose_motion_node_matrix(node->child);
    matrix_mult_vec(0, &v, &v);
    pop_matrix();
    return v.y;
}
#pragma pop

void fn_800E762C(void) {  }

void TObjEneMe3Shinowa::vfunc_88() {
    u8 *arg0 = (u8 *)this;
    *(f32 *)((s8 *)this->bodies + 4) = (f32) (*(f32 *)((s8 *)arg0 + 0x3CC) + (this->m_300 - *(f32 *)((s8 *)arg0 + 0x3C)));
}

void TObjEneMe3Shinowa::copy_position_vector() { VecCopy((Vec *)((char*)this + 0x74), (const Vec *)((char*)this + 0x2fc)); }

void TObjEneMe3Shinowa::vfunc_61() {  }

void TObjEneMe3Shinowa::vfunc_62() {
    u8 *arg0 = (u8 *)this;
    if (TObjEneDD::check_v2_mode() != 0) {
        ((TObjEneDD *)arg0)->clear_attack_receipts();
        return;
    }
    if (*(s32 *)((s8 *)arg0 + 0x3C4) & 1) {
        ((TObjEneDD *)arg0)->clear_attack_receipts();
        return;
    }
    if ((s16) this->mode != 0xC) {
        ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(arg0, (void*)(0xC));
    }
}

void TObjEneMe3Shinowa::vfunc_63() { if (this->mode != 13) { ((int (*)(void*, void*))transition_enemy_state__9TObjEneDDFs)(this, (void*)13); } }

void TObjEneMe3Shinowa::vfunc_28() {  }

void TObjEneMe3Shinowa::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        this->update_mirage();
        return;
    }
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
    }
    this->copy_position_vector();
    ((TBoss8Dragon *)((u8 *)this))->set_player_state_default();
    this->vfunc_100();
}

void *__dt__17TObjEneMe3ShinowaFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__17TObjEneMe3Shinowa;
        queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x3E4));
        *(s32 *)((s8 *)arg0 + 0x3E4) = 0;
        queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x3E0));
        *(s32 *)((s8 *)arg0 + 0x3E0) = 0;
        if (*(void **)((s8 *)arg0 + 0x424) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x424)); *(s32 *)((s8 *)arg0 + 0x424) = 0; }
        if (*(void **)((s8 *)arg0 + 0x428) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x428)); *(s32 *)((s8 *)arg0 + 0x428) = 0; }
        free_collision_body_parts(arg0);
        __dt__13TUnk_80494938Fv((s8 *)arg0 + 0x3E8, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

#pragma push
#pragma opt_propagation off
void TObjEneMe3Shinowa::init_enemy() {
    Mirage_800E7884 *self = (Mirage_800E7884 *)this;
    Tbl_800E7884 *tbl = &(*(Tbl_800E7884 *)&TObjEneMe3ShinowaMirage__data_80500FC0);
    ((TObjEneDD *)self)->init_position_vectors();
    ((TObjEneMe3Shinowa *)self)->sub_800E6F64();
    self->f34 = *(s32 *)((*(Game_800E7884 * *)&TObjEneMe3ShinowaMirage__data_805D5298)->mdl + 8);
    init_model__9TObjEneDDFv(self, ((void * *)shinowa_mirage_model_init_data), 1);
    self->fB0 = 0;
    ((TObjMotion *)self)->set_field_d8((s32)shinowa_mirage_motion_param_table);
    ((TObjMotion *)self)->set_field_dc((*(Game_800E7884 * *)&TObjEneMe3ShinowaMirage__data_805D5298)->f430);
    self->fB8 = 0;
    ((TObjMotion *)self)->set_animation(self->fB8);
    ((TObjMotion *)self)->set_field_b8(self->fB8);
    {
        s32 *a = tbl->t[0];
        s32 *b = tbl->t[1];
        s32 *c = tbl->t[2];
        s32 i = self->f3C0;
        reset_hp__9TObjEneDDFv(self, a[i], b[i], c[i]);
    }
    ((TObjEneDD *)self)->check_state_flag_4();
    self->f350 = TObjEneMe3ShinowaMirage__init_params;
    self->f37C = TObjEneMe3ShinowaMirage__data_805DA5E8;
    ((TObjEneDD_ST *)self)->enemy_init_acquire_period(0x1E);
    ((TObjEneDD_ST *)self)->enemy_init_validate_period(0x1E);
    self->f3C4 = 0;
    self->f3C8 = self->f3C;
    self->f3CC = TObjEneMe3ShinowaMirage__data_805DA5B8;
    self->f3D0 = 0;
    self->f3D8 = 0;
    self->f3D4 = 0;
    self->f3DC = self->f2CC;
    self->f3E0 = TObjEneSaver::create((void *)0xFF0000FF, (void *)0xA08000A0);
    self->f3E4 = TObjEneSaver::create((void *)0xFF0000FF, (void *)0xA08000A0);
    self->sub.m3();
    self->f404 = 0;
    self->f408 = 0;
    self->f40C = 0;
    self->f410 = TObjEneMe3ShinowaMirage__data_805DA5B8;
    self->f414 = TObjEneMe3ShinowaMirage__data_805DA5B8;
    self->f418 = TObjEneMe3ShinowaMirage__data_805DA5B8;
    self->f41C = TObjEneMe3ShinowaMirage__data_805DA5B8;
    self->f420 = TObjEneMe3ShinowaMirage__data_805DA5B8;
    self->f424 = 0;
    self->f428 = 0;
}
#pragma pop

void *TObjEneMe3Shinowa__ct(void *ene_me3_shinowa) {
    ((TObjEneDD_ST *)ene_me3_shinowa)->init_object();
    *(s32 **)((s8 *)ene_me3_shinowa + 0x18) = __vt__17TObjEneMe3Shinowa;
    ((TUnk_80494938 *)((char *)ene_me3_shinowa + 1000))->init_common();
    *(void * *)&((TObjEneMe3Shinowa *)ene_me3_shinowa)->m_name = lbl_805D2AC8;
    return ene_me3_shinowa;
}
}
