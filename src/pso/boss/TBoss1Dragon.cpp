#include "pso/system/ChunkMaterialState.h"
#include "pso/boss/TBoss1Dragon.h"
#include "pso/boss/TObjBoss1Rock.h"
#include "pso/system/vector.h"
#include "pso/enemy/TObjEneEpsilon.h"
#include "pso/enemy/TObjEneDD_ST.h"
#include "pso/player/TObjChara.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/object/TObjMotion.h"
#include "pso/boss/TUnk_80481B34.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/object/obj_band.h"
#include "pso/boss/TObjBoss1Crater.h"
#include "pso/misc/TMainCursor.h"
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss1DragonEffTail.h"
#include "pso/boss/TBoss3Volopt.h"
#include "pso/boss/TBoss4DarkFalz.h"
#include "pso/boss/TBoss4Type2.h"
#include "pso/boss/TBoss8Dragon.h"

#include "pso/boss/TObjBoss2Tunnel.h"

#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TCameraCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TNowLoading.h"
#include "pso/misc/TWindowCtrl.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TUnk_804928CC.h"
extern "C" void apply_paralysis__12TBoss1DragonFv();
extern "C" void apply_confusion_status__12TBoss1DragonFv();
extern "C" void apply_movement_ailment__12TBoss1DragonFl();
extern "C" void apply_shock_status__12TBoss1DragonFv();

struct DragonVisibilityBase { u8 opaque[0x18]; };
struct DragonVisibilityDispatch : DragonVisibilityBase {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32,f32);
};

extern "C" {

void TObjLight__sub_801337F8(s32);
s32 scale_matrix(s32, f32, f32, f32);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void draw_model_motion(void *, void *, f32);
extern s32 current_scene_light;
extern s32 model_render_flags;
extern const f32 lbl_805D7F18;
extern const f32 TBoss1Dragon__data_805D7F1C;
extern const f32 lbl_805D7F20;
extern const f32 TBoss1Dragon__data_805D7F24;
extern const f32 TBoss1Dragon__data_805D7F28;

}

struct DragonVirtualBase { char pad[0x18]; };
struct DragonVirtualInterface : DragonVirtualBase {
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
    virtual void m84(); virtual void m85(s16, s32);
};

struct VBase_18_5c4a6f { char pad[0x18]; };

struct VObj_18_5c4a6f : VBase_18_5c4a6f {
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
    virtual s32 m46(s32);
};

struct ByteBlock_C { u8 bytes[0xc]; };

struct Obj_80021260;
#include "types.h"
#include "pso/system/PadRumble.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct ByteBlock_8 { u8 bytes[0x8]; };

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

struct VBase_18_310373 { char pad[0x18]; };

struct VObj_18_310373 : VBase_18_310373 {
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
    virtual s32 m12(void *, void *, s32);
};

struct VBase_18_ffc433 { char pad[0x18]; };

struct VObj_18_ffc433 : VBase_18_ffc433 {
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
    virtual s32 m15(void *, s32);
};

#include <dolphin/mtx.h>
#include <stddef.h>

struct VBase_18_8002985C { char pad[0x18]; };
struct VObj_18_8002985C : VBase_18_8002985C {
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
    virtual s32 m30();
    virtual void m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual void m36();
    virtual void m37();
    virtual void m38();
    virtual s32 m39();
    virtual s32 m40();
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
    virtual s32 m86();
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
    virtual s32 m103();
};

struct RecoveredGlobal_8002116C_lbl_80434F20 { s32 value; u8 remaining[0x88]; };

struct RecoveredGlobal_8002116C_lbl_804FE188 { s32 value; u8 remaining[0x8]; };

struct RecoveredGlobal_8002116C_lbl_804FE194 { s32 value; u8 remaining[0x38]; };

struct RecoveredGlobal_80027AAC_lbl_80434EB4 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_8002826C_lbl_80480D00 {
    s32 value;
    u8 remaining[0x44];
};

struct RecoveredGlobal_8002826C_lbl_80480D48 {
    s32 value;
    u8 remaining[0x23C];
};

struct RecoveredFields_8002826C_arg0 {
    u8 unknown_0[0x67C];
    s32 field_67C;
    u8 unknown_680[0xE0];
    s32 field_760;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct ByteBlock_10 { u8 bytes[0x10]; };

struct RecoveredGlobal_800646F0_lbl_80437944 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_800646F0_lbl_804FF5B4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8006435C_lbl_80437D2C {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_8006435C_lbl_804FF5A0 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80064CFC_lbl_80487848 {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_80064CFC_lbl_804FF5A0 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80065EA0_lbl_80487CCC {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80065EA0_lbl_80487CD8 {
    s32 value;
    u8 remaining[0x350];
};

struct RecoveredGlobal_80065DB4_lbl_804FF5B4 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_80065F08_lbl_80437938 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_8002885C_TBoss1Dragon__data_804FE168 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80027634_TBoss1Dragon__data_804FE17C {
    u8 * value;
    u8 remaining[0x8];
};

struct Stack_80027E78 {
    s32 sp8;
    u8 pad_C[0x4];
    f32 sp10;
    u8 trailing_storage[0x8];
};

struct RecoveredGlobal_80027E78_lbl_80434E8C {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80027E78_TBoss1Dragon__data_804FE17C {
    u8 * value;
    u8 remaining[0x8];
};

struct ByteBlock_14
{
  u8 bytes[0x14];
};

struct RecoveredGlobal_80027650_lbl_80435338
{
  s32 value;
  u8 remaining[0x10];
};

struct RecoveredGlobal_80027650_TBoss1Dragon__data_804FE17C
{
  u8 *value;
  u8 remaining[0x8];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct RecoveredGlobal_80027710_lbl_80435324 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_80027710_TBoss1Dragon__data_804FE17C {
    f32 * value;
    u8 remaining[0x8];
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct RecoveredGlobal_800277D8_lbl_80435310 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_800277D8_TBoss1Dragon__data_804FE17C {
    u8 * value;
    u8 remaining[0x8];
};

struct VBase_18_444bc5 { char pad[0x18]; };

struct VObj_18_444bc5 : VBase_18_444bc5 {
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
    virtual s32 m94();
};

struct pkt_80028530 {
    u8 hdr[2];
    u16 target_id;
    s16 state;
    s16 cursor;
    s32 extra;
    f32 x;
    f32 z;
};

struct dragon_80028530 {
    u8 pad0[0x1C];
    u16 target_id;
    u8 pad1[0x326 - 0x1E];
    s16 mode;
    u8 pad2[0x38C - 0x328];
    u16 extra;
    u8 pad3[0x67C - 0x38E];
    s32 sequence_cursor;
    u8 pad4[0x690 - 0x680];
    f32 outgoing_x;
    f32 outgoing_z;
};

struct Stack_800212D8 {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};
struct Vec_800292C0 { f32 x, y, z; };

struct Vec_80029238 { f32 x, y, z; };

struct Obj_80027320 {
    u8 pad0[0x6E4];
    u8 *f6e4;
    u8 pad1[0x760 - 0x6E8];
    s32 f760;
    u16 f764;
    u8 pad2[2];
    s32 f768;
};
struct VBase_18_5c1903 { char pad[0x18]; };
struct VObj_18_5c1903 : VBase_18_5c1903 {
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
    virtual s32 m21(s32, s32 *, void *, s32, s32);
    u8 pad1c[0xA4 - 0x1C];
    struct Ent_8002AACC *ents;
    s32 count;
};

struct Ent_8002AACC { u8 pad0[0x18]; u32 flags; u8 pad1c[0x2C - 0x1C]; };
struct V2_8002AACC { s32 a, b; };
struct Src_8002AACC { u8 pad[0xAC]; s32 fAC; };

struct Obj_80027010 { u8 pad0[0x38]; f32 f38; u8 pad3C[4]; f32 f40; };

struct Vec_80027010 { f32 x, y, z; };

typedef struct Dragon_80028EA8 {
    u8 pad0[0x6A0];
    s32 count;
    u8 pad6A4[4];
    f32 slots[12];
} Dragon_80028EA8;

typedef struct Vec_80028EA8 {
    f32 x, y, z;
} Vec_80028EA8;

struct Vec_80028CA8 { f32 x, y, z; };

struct VBase_80029C78 { char pad[0x18]; };

struct VObj_80029C78 : VBase_80029C78 {
    virtual ~VObj_80029C78();
};

struct Obj_80029C78 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x3C4 - 0x1C];
    u8 f3C4[0x5F4 - 0x3C4];
    u8 f5F4[0x618 - 0x5F4];
    u8 f618[0x684 - 0x618];
    VObj_80029C78 *f684;
    void *f688;
    VObj_80029C78 *f68C;
    u8 pad690[0x6D8 - 0x690];
    void *f6D8;
    u8 pad6DC[0x6E8 - 0x6DC];
    u8 f6E8[0x774 - 0x6E8];
    VObj_80029C78 *f774;
};

struct Vec_800278A8 { f32 x, y, z; };

struct Params_800278A8 { s32 a; s32 b; f32 scale; s32 c; s32 d; };

struct Vec_80029408 { f32 x, y, z; };

struct Coll_80029408 { Vec_80029408 local; f32 radius; u32 type, attribute, flags; Vec_80029408 world; f32 defense; };
struct VBase_14_8d1630 { char pad[0x14]; };
struct VObj_14_8d1630 : VBase_14_8d1630 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
    u32 x18;
};
struct Owner_80020A54 { u8 pad[0x6E8]; VObj_14_8d1630 e[4]; };

struct Input_80022740 { u8 pad0[8]; s32 flags; u8 padC[0x24 - 0xC]; f32 f24; };
struct Input_80022C38 { u8 pad0[8]; s32 flags; u8 padC[0x24 - 0xC]; f32 f24; };
struct VBase_14_c1c33b { char pad[0x14]; };
struct Part_80022DF4 : VBase_14_c1c33b {
    virtual void p0();
    virtual void p1();
    virtual void p2();
    virtual void p3();
    virtual s32 p4();
    u8 pad18[0x1C - 0x18];
};
struct Dragon_80022DF4 {
    u8 pad0[0x6E8];
    Part_80022DF4 parts[4];
};
struct VBase_18_5b68e0 { char pad[0x18]; };
struct VObj_18_5b68e0 : VBase_18_5b68e0 {
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
    virtual s32 m89(s32);
    virtual s32 m90();
    virtual void m91();
    virtual void m92();
    virtual s32 m93();
};
struct VBase_8002624C { u8 pad[0x18]; };
struct Tail_8002624C : VBase_8002624C {
    virtual void m0();
    virtual void m1();
};
struct Dragon_8002624C : VBase_8002624C {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48(); virtual void m49();
    virtual void m50(); virtual void m51(); virtual void m52(); virtual void m53(); virtual void m54();
    virtual void m55(); virtual void m56(); virtual void m57(); virtual void m58(); virtual void m59();
    virtual void m60(); virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68(); virtual void m69();
    virtual void m70(); virtual void m71(); virtual void m72(); virtual void m73(); virtual void m74();
    virtual void m75(); virtual void m76(); virtual void m77(); virtual void m78(); virtual void m79();
    virtual void m80(); virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84();
    virtual void m85(); virtual void m86(); virtual void m87(); virtual void m88(); virtual void m89();
    virtual void m90(); virtual void m91(); virtual void m92(); virtual void m93(); virtual void m94();
    u8 pad1c[0xB8 - 0x1C];
    s16 fB8;
    u8 padBA[0x3C0 - 0xBA];
    u32 f3C0;
    u8 pad3C4[0x684 - 0x3C4];
    Tail_8002624C *tail;
    u8 pad688[0x864 - 0x688];
    s32 f864;
};

struct Obj_800288EC {
    u8 pad0[0x60];
    s32 f60;
    u8 pad1[0x660 - 0x64];
    s32 f660;
    f32 f664, f668, f66C, f670, f674, f678;
};

struct Vec_80021490 { f32 x, y, z; };

struct Rot_80021490 { s32 x, y, z; };

struct Tbl_80021490 { u8 pad0[8]; s32 e8; u8 padC[0x14 - 0xC]; s32 e14; u8 pad18[4]; s32 e1C; };

struct Dragon_80021490 {
    u8 pad0[0x38];
    Vec_80021490 pos;
    u8 pad44[0x5C - 0x44];
    s32 rot[3];
    u8 pad68[0xB8 - 0x68];
    s16 action;
    u8 padBA[0xC0 - 0xBA];
    f32 frame;
    u8 padC4[0x40C - 0xC4];
    Vec_80021490 fxpos;
    Vec_80021490 fxdir;
    u8 pad424[0x5D8 - 0x424];
    f32 altitude;
    f32 offset;
    f32 base;
    u8 pad5E4[0x778 - 0x5E4];
    Tbl_80021490 *tbl;
    u8 pad77C[0x864 - 0x77C];
    s32 phase;
    s32 ticks;
    s32 stage;
    s32 demo_active;
    u8 pad874[0x8AC - 0x874];
    u32 mouth;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
struct RecoveredGlobal_8006435C_lbl_804FF5A0;
struct Cam_80022EE0 { u8 mode; u8 sub; s16 c; f32 d; f32 e; };

struct Eff_80022EE0 { u32 w[5]; };

struct Vec_80022EE0 { f32 x, y, z; };

struct Vec_80028F9C { f32 x, y, z; };

struct Player_80028F9C { u8 pad0[0x38]; Vec_80028F9C pos; u8 pad44[0x32C - 0x44]; s16 hp; };

struct Glob_800267B8 { u8 *value; u8 remaining[0x8]; };

struct Vec_80020B54 { f32 x, y, z; };

struct Color_80020B54 { f32 a, r, g, b; };

struct Channel_80020B54 {
    u8 pad0[0x14];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8();
    u32 f18;
};

struct Body_80020B54 {
    u8 pad0[0x6E8];
    Channel_80020B54 ch[4];
};

struct Dragon_80020B54 {
    u8 pad0[0x18];
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8(f32, f32);
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
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void m104();
};

struct VBase_80029DE4 { char pad[0x18]; };
struct VObj_80029DE4 : VBase_80029DE4 {
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
    virtual void m85(s16, s32);
};

struct Vec_80029DE4 { f32 x, y, z; };
struct E1C_80029DE4 { u8 b[0x1C]; };
struct Obj_80029DE4 {
    u8 p0[0x38];
    Vec_80029DE4 pos;
    u8 p1[0x3E8 - 0x44];
    Vec_80029DE4 v3[3];
    u8 p2[0x430 - 0x40C];
    Vec_80029DE4 v22[0x22];
    u8 p3[0x6A8 - 0x5C8];
    f32 f[12];
    u8 p4[0x6E8 - 0x6D8];
    E1C_80029DE4 e[4];
};
extern f32 lbl_805D4AF8;
extern f32 boss1_dragon_gravity;
extern s32 tl_05;
extern const f32 TBoss1Dragon__data_805D7F48;
extern const f32 lbl_805D8038;
extern const f32 lbl_805D8044;
extern const f32 lbl_805D8048;
extern const f32 lbl_805D804C;
extern const f32 lbl_805D8050;
extern const f32 lbl_805D8054;
extern const f32 lbl_805D8058;
extern const f32 lbl_805D805C;
extern const f32 lbl_805D8060;
extern "C" {
f32 sample_acceleration_curve(void *, f32);
s32 init_acceleration_curve(void *, f32, f32, f32, f32);
s32 get_random_scaled__9TObjEneDDFv(void *);
void *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
void init_air_turn__12TBoss1DragonFv(void *, s32);
void rotate_vec_xz(void *, void *, s32);
u8 *TBoss1DragonEffBullet__ct(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void prepare_flight_destination__12TBoss1DragonFPv(u8 *arg0);

extern const f32 lbl_805D800C;
s32 get_current_floor();
u32 get_player_by_client_id(s32);
extern s32 TLobby__designated_client_id;
s32 clearState__12TBoss1DragonFv(void *);
s32 advance_animation_playback();
s32 isV2Mode__12TBoss1DragonFv(void);
u8 *__nw__7TObjectFUl(s32);
u8 *__ct__16TBoss1DragonDemoFv(u8 *arg0, s32 arg1, s32 arg2, f32 farg0);
s32 request_state_change__12TBoss1DragonFPvs(void *vself, s16 state32);
s32 play_sound_effect(s32, s32, s32, s32);
void *spawn_particle_effect_with_flags(void *pos, s32 id, s32 flags);
s32 play_cue_stream_file(void *, int);
u32 spawn_particle_effect_with_rotation(void *, void *, void *, int);
s32 queue_destruction__7TObjectFv(void *);
extern s32 tl_01;
extern const u8 boss1_dragon_death_cue_filename[];
extern const f32 lbl_805D7F4C;
extern const f32 TBoss1Dragon__data_805D7F50;
extern const f32 lbl_805D7F54;
extern const f32 lbl_805D7F58;
extern const f32 lbl_805D7F5C;
extern const f32 lbl_805D7F60;
extern const f32 TBoss1Dragon__data_805D7F64;
extern const f32 TBoss1Dragon__data_805D7F68;
extern const f32 lbl_805D7F6C;
extern const f32 lbl_805D7F70;
extern const f32 lbl_805D7F74;
extern const f32 lbl_805D7F78;
extern const f32 lbl_805D7F7C;
extern const f32 lbl_805D7F80;
extern const f32 TBoss1Dragon__data_805D7F84;
extern const f32 lbl_805D7F88;
s32 VecCopy__FP3VecPC3Vec(s32, s32);
void TBoss1Dragon__sub_800275BC(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3);
s32 beginHeightTransition__12TBoss1DragonFv(void *);
s32 restore_player_cameras(void);
s32 activate_camera_mode(s32);
s32 set_scripted_camera_pose(void *, void *, void *);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2);
s32 reset_hp__9TObjEneDDFv(void *, int, int, int);
s32 vec3_add_to(void *, void *);
extern u8 TBoss1Dragon__head_fall_effect_params[];
extern u8 lbl_80434EC8[];
extern u8 lbl_80434ED4[];
extern RecoveredGlobal_8006435C_lbl_804FF5A0 TBoss1Dragon__part_hp_stats;
extern const f32 TBoss1Dragon__data_805D7F38;
extern const f32 TBoss1Dragon__data_805D7F3C;
extern const f32 lbl_805D7FB4;
extern const f32 lbl_805D7FB8;
extern const f32 lbl_805D7FBC;
extern const f32 lbl_805D7FC0;
void update_death_state__12TBoss1DragonFv(u8 *arg0, u32 arg1);
f32 newton_sqrtf(f32);
s32 is_valid_target__9TObjEneDDFv(void *);
f32 horizontal_distance_squared(void *, void *);
extern const f32 TBoss1Dragon__data_805D7FC4;
extern const f32 lbl_805D80B8;
s32 next_sequence_action__12TBoss1DragonFv(void *);
s32 restoreTargetPosition__12TBoss1DragonFv();
void send_state_sync__12TBoss1DragonFPv(struct dragon_80028530 *s);
void TBoss1Dragon__sub_80028BE0(u8 *arg0);
s32 is_destination_ahead__12TBoss1DragonFPv(u8 *s);
void calc_target_vector__12TBoss1DragonFPv(u8 *arg0);
void TObjEneEpsilon__sub_800B9384(u8 *arg0, s32 arg1, f32 farg0);
s32 enemy_validate_retained_target();
s32 update_velocity__9TObjEneDDFv(void *);
f32 sin_table_lookup(s32);
f32 cos_table_lookup(s32);

extern RecoveredGlobal_80027634_TBoss1Dragon__data_804FE17C TBoss1Dragon__data_804FE17C;
extern const f32 TBoss1Dragon__data_805D7F98;
extern const f32 TBoss1Dragon__data_805D7F9C;
extern const f32 lbl_805D7FA0;
extern const f32 TBoss1Dragon__data_805D7FA4;
extern const f32 TBoss1Dragon__data_805D7FAC;
extern const f32 TBoss1Dragon__data_805D7FF8;
extern const f32 lbl_805D8078;
extern const f32 lbl_805D807C;
extern const f32 lbl_805D8080;
extern const f32 lbl_805D8084;
s32 is_split_screen();
s32 check_parts_visible__12TBoss1DragonFiPv(s32 arg0, Obj_80021260 *arg1);
s32 is_sphere_visible__12TBoss1DragonFf(f32 farg0);
s32 get_camera_mode__11TCameraCtrlFv();
s32 TBoss1Dragon__sub_8002B108(s32, s32);
f32 clamp_velocity__15TObjBoss2TunnelFv(void *, f32, f32);
s32 isFading__15RenderFadeStateCFv(void *);
void update_obstruction_fade(void *);
u8 *find_entity_by_id(s32);
s32 defer_render__7TObjectFv(void *);
s32 rotate_matrix_z(s32, s32);
void subtract_vector(void *, void *);
s32 translate_matrix(s32, f32, f32, f32);
s32 rotate_matrix_x(s32, s32);
void set_material_alpha_compare_reference(s32);
void set_chunk_material_override_pair(s32, s32);
void render__12TBoss1DragonFv(u8 *arg0);
}
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
void dragon_capture_node_points(void);
extern Color_80020B54 dragon_boss1_render_color;
extern u8 lbl_804FE1D0[0xC];
extern u8 lbl_804FE1DC[0xC];
extern u32 TBoss1Dragon__data_805D4B08;
extern s32 TBoss1Dragon__data_805D4B0C;
extern s32 TBoss1Dragon__data_805D4B14;
extern s32 TBoss1Dragon__data_805D4B18;
extern s32 TBoss1Dragon__data_805D4B1C;
extern s32 TBoss1Dragon__data_805D4B20;
extern const f32 boss1_dragon_visibility_distance;
extern u8 *camera_ctrl_instance;
extern s32 saved_model_render_flags;
extern const f32 lbl_805D7F2C;
extern const f32 lbl_805D7F30;
extern const f32 lbl_805D7F34;
struct G_80025C68 { u8 *value; u8 remaining[0x8]; };
struct Vec_80024314 { f32 x, y, z; };
struct Vec_80025710 { f32 x; f32 y; f32 z; };
extern "C" {
f32 vec3_dot(void *, void *);
extern const f32 TBoss1Dragon__data_805D7F40;
void play_se_at_pos__12TBoss1DragonFii(s32 arg0, s32 arg1);
extern const f32 TBoss1Dragon__data_805D8040;
void TBoss1Dragon__sub_80028B28(u8 *arg0);
s32 set_type__10TObjPlayerFl(void *, s32);
extern const f32 lbl_805D8090;
f32 calc_burrow_speed__12TBoss1DragonFPv(void *arg0);
extern const f32 lbl_805D80B0;
void TBoss1Dragon__sub_80027A80(u8 *arg0, u8 *arg1);
s32 enemy_set_target_id(void *, u16);
u8 *TBoss1Dragon__ct(u8 *, void *, void *);
extern s32 tl_04;
extern s32 tl_02;
extern const f32 lbl_805D80A8;
s32 isHpPhasePending__12TBoss1DragonFv(void *);
void project_sound_origin_from_camera(s32 arg0, u8 *arg1, f32 farg0);
s32 query_teammate_state__9TObjEneDDFv();
s32 is_main_phase_15__9TObjEneDDFv();
s32 add_radar_scaled_marker(void *, int, int, int, f32);
extern s32 TBoss1Dragon__data_805D4B38;
extern s32 local_client_id;
extern const f32 lbl_805D80C0;
void run_task__12TBoss1DragonFv(u8 *arg0);
void get_camera_ctrl__9TObjEneDDFv(s32, s32);
void update_camera_sequence__9TObjEneDDFv(void);
s32 mult_vec_array__10TObjPlayerFUll(int, void *, int, int);
extern const RecoveredGlobal_8002116C_lbl_80434F20 boss1_dragon_capture_node_table;
extern RecoveredGlobal_8002116C_lbl_804FE188 lbl_804FE188;
extern RecoveredGlobal_8002116C_lbl_804FE194 lbl_804FE194;
extern s32 lbl_805D4B10;
s32 TBoss1Dragon__sub_80027590(void* object, void* action);
extern const RecoveredGlobal_80027AAC_lbl_80434EB4 boss1_dragon_ground_impact_params;
s32 reload_stats_keep_hp_tp__9TObjEneDDFv(void *, int, int, int);
extern s32 TBoss1Dragon__data_805D4B00;
extern s32 TBoss1Dragon__data_805D4B04;
extern s32 TBoss1Dragon__data_805D4B2C;
void calc_follow_camera_offsets__12TBoss1DragonFv(TBoss1Dragon *self, Vec *eye, Vec *target);
f32 TBoss1Dragon__sub_80027634(void);
extern RecoveredGlobal_80027E78_lbl_80434E8C boss1_dragon_attack_sphere_params;
void apply_landing_attack__12TBoss1DragonFi(s32 arg0);
extern const f32 lbl_805D80BC;
struct Obj_80027320;
extern u8 controller_input_state[];
s32 request_state_change__12TBoss1DragonFPvs(void *, s16);
void TBoss1Dragon__sub_80026C98(TBoss1Dragon *arg0, u32 arg1);
void TBoss1Dragon__sub_80022158(TBoss1Dragon *arg0, u32 arg1);
void TBoss1Dragon__sub_800224A4(TBoss1Dragon *arg0, u32 arg1);
void TBoss1Dragon__sub_80022740(TBoss1Dragon *arg0, u32 arg1);
void TBoss1Dragon__sub_800228E8(TBoss1Dragon *arg0, u32 arg1);
void TBoss1Dragon__sub_80022C38(TBoss1Dragon *arg0, u32 arg1);
void TBoss1Dragon__sub_80023A2C(TBoss1Dragon *arg0, u32 arg1);
void update_dive_state__12TBoss1DragonFv(u8 *arg0, u32 arg1);
s32 TBoss1Dragon__sub_80025168(void *, void *);
void TBoss1Dragon__sub_80026B98(TBoss1Dragon *arg0, u32 arg1);
void dispatch_action__12TBoss1DragonFiUii(s32 arg0, u32 arg1, s32 arg2);
void send_6x2F_change_player_hp(s32 arg0, s32 arg1, s32 arg2);
s32 TBoss1Dragon__sub_80027514(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3);
void TBoss1Dragon__sub_800277D8(u8 *arg0);
extern const f32 TBoss1Dragon__gravity_accel;
extern const f32 TBoss1Dragon__data_805D8008;
extern const f32 lbl_805D8020;
extern const f32 lbl_805D8024;
void bind_motion_context(s32 arg0, f32 farg0);
void compose_motion_node_matrix(void *arg0);
s32 matrix_mult_vec(int, void *, void *);
s32 push_matrix_from(void *);
extern u8 identity_matrix[];
extern const f32 lbl_805D808C;
f32 TBoss1Dragon__sub_80027010(Obj_80027010 *arg0, f32 farg0, f32 farg1, f32 farg2);
f32 calc_boss4_scale__10TObjPlayerFi(void);
f32 get_random_float__21TObjEneMe3ShinowaRealFv(f32);
f32 rand_range__9TObjEneDDFff(void *, f32, f32);
extern const f32 lbl_805D7FE0;
s32 choose_burrow_ring_destination__12TBoss1DragonFPvPv(Dragon_80028EA8 *arg0, Vec_80028EA8 *arg1);
int get_player_data__10TObjPlayerFi(int a0);
u16 get_entity_id(void *);
void enemy_clear_target__12TObjEneDD_STFUs(void *);
s32 is_alive__9TObjEneDDFv(void *);
s32 select_forward_target__12TBoss1DragonFPv(u8 *self);
s32 __dt__7TObjectFv(void *, int);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 delete_buffer__12TBoss8DragonFis(s32 arg0, s16 arg1);
s32 free_collision_body_parts(void *);
void __dl__7TObjectFPv(void *);
s32 __destroy_arr(void *, void *, int, int);
void *__dt__13TUnk_804949A8Fv(void *arg0, s16 arg1);
Obj_80029C78 *destroy__12TBoss1DragonFPvs(Obj_80029C78 *o, s16 flag);
void render_shadows__12TBoss1DragonFv(u8 *arg0);

u8 *TBoss1DragonColli__ct(u8 *arg0, s32 arg1);
void *TBoss1DragonEffTail__ct(void *, void *, void *);
u8 *TObjBoss1MokoHill_SoloM__ct(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
s32 __ct__14SubtractiveRngFv(void *arg0);
void init_object__12TObjEneDD_STFv(void *, void *);
void initialize_enemy_state__9TObjEneDDFv(void *, s32);
void init_model__9TObjEneDDFv(void *, void *, s32);
void invoke_initialization_hook__9TObjEneDDFv(void *, void *);
u8 *TBoss8Dragon__sub_800BC5EC(u8 *arg0, s32 arg1);
void __ct__7TObjectFP7TObject(void *, void *);
void __construct_array(void *, void *, void *, int, int);
extern u8 init_and_activate__10TObjPlayerFv[];
extern u8 boss1_dragon_normal_action_table[];
extern u8 boss1_dragon_normal_particle_table[];
extern s32 lbl_805D2650;

extern "C" void vfunc_6__8TObjBaseFPsl();
extern "C" void vfunc_103__9TObjEneDDFPUc();
extern "C" void vfunc_79__9TObjEneDDFv();
extern "C" void TObjEneDD__vt82();
extern "C" void vfunc_85__9TObjEneDDFv();
extern "C" void vfunc_86__9TObjEneDDFv();
extern "C" void vfunc_89__9TObjEneDDFv();
extern "C" void vfunc_90__9TObjEneDDFv();
extern "C" void vfunc_91__9TObjEneDDFv();
extern "C" void vfunc_92__9TObjEneDDFv();
extern "C" void vfunc_93__9TObjEneDDFv();
extern "C" void vfunc_94__9TObjEneDDFv();
extern "C" void vfunc_95__9TObjEneDDFv();
extern "C" void vfunc_96__9TObjEneDDFv();
extern "C" void vfunc_97__9TObjEneDDFv();
extern "C" void vfunc_98__9TObjEneDDFv();
extern "C" void vfunc_99__9TObjEneDDFv();
extern "C" void vfunc_100__9TObjEneDDFv();
extern "C" void vfunc_101__9TObjEneDDFPUc();
extern "C" void vfunc_102__9TObjEneDDFv();
extern "C" int TObjEneEpsilon__vt101(void *p);
extern "C" void vfunc_83__12TObjEneDD_STFv();
extern "C" void vfunc_29__9TObjCharaFv();
extern "C" void recalc_stats__9TObjCharaFv();
extern "C" void consume_timer_field__9TObjCharaFl();
extern "C" void vfunc_67__9TObjCharaFf();
extern "C" void vfunc_66__9TObjCharaFv();
extern "C" void get_anim_node_position__9TObjCharaFlP3Vec();
extern "C" void vfunc_60__9TObjCharaFv();
extern "C" void vfunc_59__9TObjCharaFv();
extern "C" void vfunc_58__9TObjCharaFv();
extern "C" void update_shock_clock__9TObjCharaFv();
extern "C" void vfunc_43__9TObjCharaFv();
extern "C" void vfunc_18__9TObjCharaFPUc();
extern "C" void interact__14TObjCollidableFl();
extern "C" void vfunc_74__9TObjEnemyFl();
extern "C" void apply_hit_message_flags__9TObjEnemyFPv();
extern "C" void add_actor_exp__9TObjCharaFl();
extern "C" void apply_action_hold_status__9TObjCharaFf();
extern "C" void apply_anti_technique__9TObjCharaFl();
extern "C" void apply_attack_stat_status__9TObjCharaFPv();
extern "C" void apply_knockback_from_attacker__9TObjCharaFPUc();
extern "C" void apply_object_set_data__8TObjBaseFPv();
extern "C" void apply_set_data__9TObjEnemyFPv();
extern "C" void apply_switch_attack__9TObjCharaFv();
extern "C" void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
extern "C" void classify_actor_view_detail__8TObjBaseFfff();
extern "C" void clear_all_status_effects__9TObjCharaFv();
extern "C" void cure_paralysis__9TObjCharaFv();
extern "C" void cure_poison_ailment__9TObjCharaFv();
extern "C" void enemy_spawn_jellen_effect__9TObjCharaFv();
extern "C" void enemy_spawn_zalure_effect__9TObjCharaFv();
extern "C" void vfunc_78__9TObjCharaFl();
extern "C" void vfunc_77__9TObjCharaFv();
extern "C" void vfunc_76__9TObjCharaFv();
extern "C" void vfunc_75__9TObjCharaFf();
extern "C" void clear_lobby_object_state__9TObjEnemyFv();
extern "C" void get_center__9TObjCharaFv();
extern "C" void get_actor_level_index__9TObjCharaFv();
extern "C" void get_name__9TObjEnemyFv();
extern "C" void get_pos__9TObjCharaFl();
extern "C" void is_actor_cadence_frame__9TObjCharaFl();
extern "C" void is_target_in_attack_range__9TObjCharaFv();
extern "C" u8 lbl_80434FAC[];
extern "C" u8 lbl_80434FC4[];
extern "C" u8 lbl_80434FDC[];
extern "C" u8 lbl_80434FFC[];
extern "C" u8 lbl_80435018[];
extern "C" u8 lbl_80435034[];
extern "C" u8 lbl_80435050[];
extern "C" u8 lbl_8043506C[];
extern "C" u8 lbl_80435088[];
extern "C" u8 lbl_804350A8[];
extern "C" u8 lbl_804350C4[];
extern "C" u8 lbl_804350E0[];
extern "C" u8 lbl_80435100[];
extern "C" u8 lbl_8043511C[];
extern "C" u8 lbl_80435138[];
extern "C" u8 lbl_80435154[];
extern "C" u8 lbl_80435170[];
extern "C" u8 lbl_80435190[];
extern "C" u8 lbl_804351AC[];
extern "C" u8 lbl_804351C8[];
extern "C" u8 lbl_804351E4[];
extern "C" u8 lbl_80435200[];
extern "C" u8 lbl_80435220[];
extern "C" u8 lbl_80435240[];
extern "C" u8 lbl_8043525C[];
extern "C" u8 lbl_8043527C[];
extern "C" u8 lbl_80435298[];
extern "C" u8 lbl_804352B8[];
extern "C" u8 lbl_804352D8[];
extern "C" void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
extern "C" void receive_physical_attack__9TObjCharaFPvf();
extern "C" void receive_weapon_special_attack__9TObjCharaFPvPv();
extern "C" void apply_defense_stat_status__9TObjCharaFPv();
extern "C" void render_low_detail__12TBoss1DragonFv();
extern "C" void reset_motion_fields__9TObjCharaFv();
extern "C" void reset_pose__9TObjCharaFv();
extern "C" void roll_physical_accuracy__9TObjCharaFPvlf();
extern "C" void select_melee_contact_body__9TObjCharaFPvf();
extern "C" void trigger_switch_attack__9TObjCharaFv(s32 arg0);
extern "C" void try_start_action__9TObjCharaFll();
extern "C" void update_action_hold_status__9TObjCharaFv();
extern "C" s32 vfunc_37__9TObjCharaFv(u8 *arg0);
extern "C" void update_actor_ground_y__9TObjCharaFv();
extern "C" s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
extern "C" void update_flag30_timer__9TObjCharaFv();
extern "C" void update_movement_status__9TObjCharaFv();
extern "C" void update_object_view_visibility__8TObjBaseFff();
extern "C" void update_poison_status__9TObjCharaFv();
extern void *lbl_80480F88[3];
extern void *lbl_80480F94[31];
int vfunc_105__12TBoss1DragonFv(void* p);
void vfunc_61__12TBoss1DragonFv(void);
void vfunc_62__12TBoss1DragonFv(void);
void vfunc_63__12TBoss1DragonFv(void);
void vfunc_28__12TBoss1DragonFv(void);
void apply_poison_status__12TBoss1DragonFv(void);
void apply_slow_status__12TBoss1DragonFv(void);
void clear_harmful_statuses__12TBoss1DragonFv(void);
void vfunc_88__12TBoss1DragonFv(u8 *arg0);
void *TBoss1Dragon__data_80480CE0[8] = {
    (void *)0x2, (void *)0x3, (void *)0x4, (void *)0x5,
    (void *)0x6, (void *)0x7, (void *)0x8, (void *)0x20,
};
void *boss1_dragon_sequence_remap_table[8] = {
    (void *)0x0, (void *)0x0, (void *)0x2, (void *)0x3,
    (void *)0x3, (void *)0x3, (void *)0x0, (void *)0x0,
};
void *lbl_80480D20[10] = {
    (void *)0x2, (void *)0x3, (void *)0x2, (void *)0x3,
    (void *)0x4, (void *)0x5, (void *)0x6, (void *)0x22,
    (void *)0x8, (void *)0x20,
};
void *lbl_80480D48[10] = {
    (void *)0x0, (void *)0x0, (void *)0x2, (void *)0x0,
    (void *)0x2, (void *)0x3, (void *)0x3, (void *)0x3,
    (void *)0x0, (void *)0x0,
};
void *boss1_dragon_action_sequence_table[14] = {
    (void *)0x5, (void *)0x6,
    (void *)0xf, (void *)0x10, (void *)0x12, (void *)0x11,
    (void *)0x12, (void *)0x11, (void *)0x12, (void *)0x13,
    (void *)0x8, (void *)0x2, (void *)0x3, (void *)0x21,
};
void *boss1_dragon_action_sequence_table_b[12] = {
    (void *)0x5, (void *)0x6, (void *)0xf, (void *)0x10,
    (void *)0x12, (void *)0x11, (void *)0x12, (void *)0x23,
    (void *)0x13, (void *)0x8, (void *)0x2, (void *)0x3,
};
void *lbl_80480DD8[9] = {
    (void *)0x21, (void *)0x12, (void *)0x14, (void *)0x15,
    (void *)0x16, (void *)0x17, (void *)0x11, (void *)0x12,
    (void *)0x13,
};
s32 boss1_dragon_base_stat_indices[5] = { 0, 0, 0, 0, 0 };
s32 boss1_dragon_attack_stat_indices[5] = { 0, 1, 2, 3, 4 };
s32 boss1_dragon_resistance_stat_indices[5] = { 0, 0, 0, 0, 0 };
void *boss1_dragon_init_params[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
struct DragonCollisionBodyPartInit {
    f32 local_center[3];
    f32 radius;
    f32 field_10;
    s32 field_14;
    u32 flags;
    f32 world_center[3];
    f32 field_28;
};
typedef char DragonCollisionBodyPartInit_size[(sizeof(DragonCollisionBodyPartInit) == 0x2C) ? 1 : -1];
DragonCollisionBodyPartInit boss1_dragon_collision_body_parts[7] = {
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
    { { 0.0f, 0.0f, 0.0f }, 10.0f, 0.0f, 0, 0x8003, { 0.0f, 0.0f, 0.0f }, 0.0f },
};
void *lbl_80480F88[3] = {
    (void *)&lbl_80434FAC, (void *)&lbl_80434FC4, (void *)0x0,
};
void *lbl_80480F94[31] = {
    (void *)&lbl_80434FDC, (void *)&lbl_80434FFC, (void *)&lbl_80435018, (void *)&lbl_80435034,
    (void *)&lbl_80435050, (void *)&lbl_8043506C, (void *)&lbl_80435088, (void *)&lbl_804350A8,
    (void *)&lbl_804350C4, (void *)&lbl_804350E0, (void *)&lbl_80435100, (void *)&lbl_8043511C,
    (void *)&lbl_80435138, (void *)&lbl_80435154, (void *)&lbl_80435170, (void *)&lbl_80435190,
    (void *)&lbl_804351AC, (void *)&lbl_804351C8, (void *)&lbl_804351E4, (void *)&lbl_80435200,
    (void *)&lbl_80435220, (void *)&lbl_80435240, (void *)&lbl_8043525C, (void *)&lbl_8043527C,
    (void *)&lbl_80435298, (void *)&lbl_804352B8, (void *)0x0, (void *)&lbl_804352D8,
    (void *)&lbl_80480F88, (void *)&lbl_80480F94, (void *)0x2001a,
};
void *lbl_80481010[108] = {
    (void *)0x10000, (void *)0x11, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x15, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x10, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x5, (void *)0x3f666666, (void *)0x0,
    (void *)0x30000, (void *)0x8, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x9, (void *)0x3ecccccd, (void *)0x0,
    (void *)0x30000, (void *)0xa, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x12, (void *)0x3f000000, (void *)0x0,
    (void *)0x20009, (void *)0xe, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x4, (void *)0x3e99999a, (void *)0x0,
    (void *)0x30000, (void *)0xf, (void *)0x3e99999a, (void *)0x0,
    (void *)0x30000, (void *)0x2, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x19, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x18, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0xd, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x7, (void *)0x3f800000, (void *)0x0,
    (void *)0x2000e, (void *)0xc, (void *)0x3f800000, (void *)0x0,
    (void *)0x20010, (void *)0x6, (void *)0x3f8ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x17, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x16, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x14, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0xb, (void *)0x3f800000, (void *)0x0,
    (void *)0x20010, (void *)0x13, (void *)0x3f000000, (void *)0x80000000,
    (void *)0x30000, (void *)0x0, (void *)0x3f000000, (void *)0x80000000,
    (void *)0x20008, (void *)0x2, (void *)0x3f19999a, (void *)0x0,
};
static void *boss1_dragon_follow_camera_offsets[3] = {
    (void *)0x0, (void *)0x419e6666, (void *)0xc0a00000,
};
static void *lbl_804811CC[3] = {
    (void *)0x0, (void *)0x41cb70a4, (void *)0x4235ae14,
};
static void *boss1_dragon_follow_camera_phase_positions[9] = {
    (void *)0x0, (void *)0x41b80000, (void *)0xc0400000, (void *)0x0,
    (void *)0x42000000, (void *)0x0, (void *)0x0, (void *)0x41c80000,
    (void *)0xc0a00000,
};
static void *boss1_dragon_follow_camera_phase_targets[9] = {
    (void *)0x0, (void *)0x41300000, (void *)0x42200000, (void *)0x0,
    (void *)0x40a00000, (void *)0x420c0000, (void *)0x0, (void *)0x42480000,
    (void *)0x42700000,
};
static void *boss1_dragon_held_camera_positions[12] = {
    (void *)0x0, (void *)0x41a00000, (void *)0xc2f00000, (void *)0x0,
    (void *)0x42f00000, (void *)0xc2f00000, (void *)0x0, (void *)0x41c80000,
    (void *)0xc1f00000, (void *)0x0, (void *)0x42480000, (void *)0xc2a00000,
};
static void *boss1_dragon_held_camera_targets[12] = {
    (void *)0x0, (void *)0x42f00000, (void *)0x42480000, (void *)0x0,
    (void *)0x43960000, (void *)0xc1f00000, (void *)0x0, (void *)0x42200000,
    (void *)0x0, (void *)0x43960000, (void *)0x42f00000, (void *)0x42480000,
};
void *lbl_80481280[107] = {
    (void *)0x0, (void *)0x0, (void *)&destroy__12TBoss1DragonFPvs, (void *)&run_task__12TBoss1DragonFv,
    (void *)&render__12TBoss1DragonFv, (void *)&render_shadows__12TBoss1DragonFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUc, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__12TBoss1DragonFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__12TBoss1DragonFv, (void *)&apply_paralysis__12TBoss1DragonFv, (void *)&apply_slow_status__12TBoss1DragonFv, (void *)&apply_confusion_status__12TBoss1DragonFv,
    (void *)&apply_movement_ailment__12TBoss1DragonFl, (void *)&apply_shock_status__12TBoss1DragonFv, (void *)&clear_harmful_statuses__12TBoss1DragonFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__12TBoss1DragonFv, (void *)&vfunc_62__12TBoss1DragonFv, (void *)&vfunc_63__12TBoss1DragonFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFv, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEneDDFv,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&TObjEneDD__vt82, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&dispatch_action__12TBoss1DragonFiUii,
    (void *)&vfunc_88__12TBoss1DragonFv, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&TObjEneEpsilon__vt101, (void *)&vfunc_105__12TBoss1DragonFv, (void *)&render_low_detail__12TBoss1DragonFv,
};

s32 fill_value_array(s32);
s32 emit_enemy_effect__9TObjEneDDFllPUcl(void *, void *, void *, s32);
s32 update_local_colliders_from_world(void *, void *);
void TBoss1Dragon__sub_800274A4(s32 arg0);
extern const f32 TBoss1Dragon__data_805D7F90;
s32 fn_8002AE08(int);
s32 approach_angle_limited(int, int, int);
extern const f32 lbl_805D7FA8;
extern const f32 lbl_805D7FB0;
f64 atan2_float(f32, f32);
s32 saveCurrentDestination__12TBoss1DragonFv(void *);
s32 restorePosition__12TBoss1DragonFv(void *);
void TBoss1Dragon__sub_80028AFC(u8 *);
extern const f32 TBoss1Dragon__data_805D7F94;
extern const f32 lbl_805D7FEC;
extern const f32 TBoss1Dragon__data_805D7FF0;
extern const f32 lbl_805D7FF4;
extern const f32 lbl_805D7FFC;
extern s32 lbl_80435388[];
s32 update_damage_threshold__12TBoss1DragonFv();
s32 disable_dragon_blocking_bodies(int);
s32 enable_dragon_blocking_bodies(int, void *, int);
extern const f32 TBoss1Dragon__data_805D8000;
extern const f32 lbl_805D8014;
extern const f32 TBoss1Dragon__data_805D8018;
extern const f32 lbl_805D801C;
extern const f32 lbl_805D4AF0;
extern const f32 lbl_805D8064;
extern const f32 lbl_805D8068;
extern const f32 lbl_805D806C;
extern const f32 lbl_805D8070;
s32 __ct__21TBoss1DragonEffBreathFP7TObjectPvPv(void *, void *, void *, void *);
extern const f32 lbl_805D8074;
void clear_work__12TBoss1DragonFi(s32 arg0);
void TBoss1Dragon__sub_80028AFC(u8 *arg0);
void spawn_trap__12TBoss1DragonFii(s32 arg0, s32 arg1);
s32 filter_input_flags__12TBoss1DragonFiii(s32 arg1, s32 arg2, s32 arg3);
u8 check_attack_ready__12TBoss1DragonFPv(void *arg0);
void sweep_head_fall_spheres_late__12TBoss1DragonFv(void);
void update_from_data__12TBoss1DragonFv(void);
void sweep_body_attack_spheres__12TBoss1DragonFv(u8 *arg0, f32 a, f32 b, f32 c);
s32 check_flag_100__10TObjPlayerFPv();
u8 *get_enemy_entity(u16 arg0);
s32 angle_diff_s16(s32, s32);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
void *init_base__13TUnk_80481B34Fv(void *arg0);
void TLobby__sub_8001FE7C(void*, int);
void construct_collision_body(void *);
s32 update_linked_position__12TObjEneDD_STFf(f32);
}
void get_dragon_follow_camera_offsets(u8 *arg0, u8 *arg1);
extern const f32 lbl_805D8094;
extern const RecoveredGlobal_80027650_lbl_80435338 dragon_fireball_impact_damage_params;
extern RecoveredGlobal_80027710_lbl_80435324 dragon_fireball_attack_params;
s32 is_dragon_trail_damaging(u8 *arg0);
extern RecoveredGlobal_800277D8_lbl_80435310 dragon_breath_attack_params;
extern const f32 lbl_805D7FD0;
void set_collider_contact_low(u8 *arg0);
void set_collider_contact_high(u8 *arg0);
void handle_6x12_dragon_boss_actions(TObjPlayer *arg0);
void handle_6x11_dragon_boss_actions(void *arg0);
void handle_6x10_dragon_boss_actions(void *arg0);
extern u32 TBoss1Dragon__data_805D4B28;
extern const f32 lbl_805D7F44;
extern f32 lbl_805D8088;
extern const f32 TBoss1Dragon__data_805D8010;
extern const f32 lbl_805D8098;
extern const f32 lbl_805D809C;
extern const f32 lbl_805D80A0;
extern s32 enable_v2_features;
extern s32 lbl_805D4B34;
extern u16 TBoss1Dragon__data_805D4B3C;
extern s32 lbl_80481B34[];

bool TBoss1Dragon::isV2Mode() {
    return TObjEneDD::check_v2_mode() != 0;
}

void TBoss1Dragon::render_low_detail() {
    TBoss1Dragon *self = this;
    DragonMotion *m;
    s32 i;
    f32 frame;

    if (((DragonVisibilityDispatch*)self)->m8(lbl_805D7F18, TBoss1Dragon__data_805D7F1C) == 0) {
        return;
    }
    TObjFish::set_global_param(self->texlist);
    push_matrix();
    post_translate_matrix(&self->position.x);
    rotate_matrix_y(0, self->rotation_y);
    push_matrix();
    scale_matrix(0, lbl_805D7F20, TBoss1Dragon__data_805D7F24, lbl_805D7F20);
    pop_matrix();
    scale_matrix(0, TBoss1Dragon__data_805D7F24, TBoss1Dragon__data_805D7F24, TBoss1Dragon__data_805D7F24);
    model_render_flags &= ~0x400;
    i = (s32)self->parameters[0];
    if (i < 0) {
        i = 0;
    } else if (i >= 0x1B) {
        i = 0x1A;
    }
    m = (*(DragonMotionEntry * *)&self->motion_list)[(*(DragonAnimationEntry * *)&self->action_table)[i].motionIndex].motion;
    frame = self->parameters[1];
    if (frame < TBoss1Dragon__data_805D7F28) {
        frame = TBoss1Dragon__data_805D7F28;
    } else {
        if (frame > (m->frameCount - 1)) {
            frame = (f32)m->frameCount;
        }
    }
    draw_model_motion(self->model, m, frame);
    TObjLight__sub_801337F8(current_scene_light);
    pop_matrix();
}

extern const u8 boss1_dragon_death_cue_filename[] = "dradeath.adx";
static const f64 boss1_dragon_angle_units_per_radian = 10430.38043493439;

int TBoss1Dragon::vfunc_105() { return this->get_target_info(); }

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define SELF ((Dragon_80020B54 *) ((u8 *)this))
void TBoss1Dragon::render() {
    s32 view;
    s32 saved;
    s32 i;
    Channel_80020B54 *ch;
    s32 visible;
    s16 state;
    u8 *ent;
    s32 hit;
    f32 dist;
    view = 0;
    if (TObjPlayer::check_demo_mode() != 0) {
        SELF->m104();
        return;
    }
    if (is_split_screen() != 0) {
        view = get_camera_mode__11TCameraCtrlFv();
    }
    TBoss1Dragon__data_805D4B0C = 0;
    TBoss1Dragon__data_805D4B14 = (s32) (((u8 *)this) + 0x3E8);
    TBoss1Dragon__data_805D4B18 = 0;
    TBoss1Dragon__data_805D4B1C = (s32) (((u8 *)this) + 0x430);
    TBoss1Dragon__data_805D4B20 = *(s32 *)&((TBoss1Dragon *)((u8 *)this))->flags;
    SELF->m8(lbl_805D7F30, lbl_805D7F30);
    ch = &((Body_80020B54 *) ((u8 *)this))->ch[view];
    if (ch->m8() != 0) {
        if (is_split_screen() != 0 && ((TBoss1Dragon *)((u8 *)this))->heightOffset - ((TBoss1Dragon *)((u8 *)this))->defaultHeightOffset >= lbl_805D7F2C &&
            ((TBoss1Dragon *)((u8 *)this))->mode != 0x16) {
            push_matrix();
            post_translate_matrix(((u8 *)this) + 0x38);
            translate_matrix(0, TBoss1Dragon__data_805D7F28, TBoss1Dragon__data_805D7F24, TBoss1Dragon__data_805D7F28);
            rotate_matrix_y(0, ((TBoss1Dragon *)((u8 *)this))->rotation_y);
            scale_matrix(0, TBoss1Dragon__data_805D7F24, lbl_805D7F34, TBoss1Dragon__data_805D7F24);
            rotate_matrix_x(0, *(s32 *)((s8 *)((u8 *)this) + 0x5C));
            rotate_matrix_z(0, ((TBoss1Dragon *)((u8 *)this))->rotation_z);
            Color_80020B54 color = dragon_boss1_render_color;
            saved = *(s32 *)((s8 *)((u8 *)this) + 0x34);
            *(s32 *)((s8 *)((u8 *)this) + 0x34) = *(s32 *)((s8 *)(*(u8 **)((s8 *)TBoss1Dragon__data_805D4B08 + 0x42C)) + 0x18);
            saved_model_render_flags = model_render_flags;
            model_render_flags = saved_model_render_flags | 0x10;
            set_constant_material((const NJS_ARGB *)((&color)));
            ((TObjMotion *)((u8 *)this))->draw();
            model_render_flags = saved_model_render_flags;
            *(s32 *)((s8 *)((u8 *)this) + 0x34) = saved;
            pop_matrix();
        }
        TObjFish::set_global_param(((TBoss1Dragon *)((u8 *)this))->texlist);
        TObjEneDD::clear_global_flag_400();
        saved_model_render_flags = model_render_flags;
        set_material_alpha_compare_reference(0);
        state = ((TBoss1Dragon *)((u8 *)this))->mode;
        visible = 1;
        if (state == 0x16) {
            ch->m6();
            visible = 0;
        } else {
            hit = 0;
            if (camera_ctrl_instance != NULL && state != 0x1D && state != 0x16 && state != 0x15 &&
                ((TBoss1Dragon *)((u8 *)this))->phase == 0) {
                ent = find_entity_by_id(TCameraCtrl::get_camera_target_id(-1));
                if (ent != NULL) {
                    Vec_80020B54 origin;
                    Vec_80020B54 delta;
                    f32 *points[4];
                    Vec_80020B54 probe;
                    VecCopy__FP3VecPC3Vec((s32) &origin, (s32)(camera_ctrl_instance + 0x178));
                    origin.y = TBoss1Dragon__data_805D7F28;
                    VecCopy__FP3VecPC3Vec((s32) &delta, (s32)(ent + 0x38));
                    subtract_vector(&delta, &origin);
                    delta.y = TBoss1Dragon__data_805D7F28;
                    dist = ((f32 (*)(void *)) clamp_velocity__15TObjBoss2TunnelFv)(&delta);
                    VecCopy__FP3VecPC3Vec((s32) lbl_804FE1D0, (s32) &origin);
                    VecCopy__FP3VecPC3Vec((s32) lbl_804FE1DC, (s32) &delta);
                    *(f32 *) &boss1_dragon_visibility_distance = dist;
                    points[0] = (f32 *) (((u8 *)this) + 0x454);
                    points[1] = (f32 *) (((u8 *)this) + 0x460);
                    points[2] = (f32 *) (((u8 *)this) + 0x46C);
                    points[3] = (f32 *) (((u8 *)this) + 0x478);
                    for (i = 0; i < 4; i++) {
                        if (((s32 (*)(void *, void *, f32)) is_sphere_visible__12TBoss1DragonFf)(((u8 *)this), points[i], TBoss1Dragon__data_805D7F38) != 0) {
                            hit = 1;
                            break;
                        }
                    }
                    if (((TBoss1Dragon *)((u8 *)this))->mode == 9) {
                        if (hit == 0) {
                            probe.x = *(f32 *)((s8 *)((u8 *)this) + 0x38) - TBoss1Dragon__data_805D7F3C * sin_table_lookup(((TBoss1Dragon *)((u8 *)this))->rotation_y);
                            probe.y = TBoss1Dragon__data_805D7F28;
                            probe.z = *(f32 *)((s8 *)((u8 *)this) + 0x40) - TBoss1Dragon__data_805D7F3C * cos_table_lookup(((TBoss1Dragon *)((u8 *)this))->rotation_y);
                            hit = ((s32 (*)(void *, void *, f32)) is_sphere_visible__12TBoss1DragonFf)(((u8 *)this), &probe, TBoss1Dragon__data_805D7F1C);
                        }
                        if (hit == 0) {
                            hit = ((s32 (*)(void *, s32)) check_parts_visible__12TBoss1DragonFiPv)(((u8 *)this), TBoss1Dragon__sub_8002B108(*(s32 *)((s8 *)((u8 *)this) + 0x68C), 1));
                        }
                        if (hit == 0) {
                            hit = ((s32 (*)(void *, s32)) check_parts_visible__12TBoss1DragonFiPv)(((u8 *)this), TBoss1Dragon__sub_8002B108(*(s32 *)((s8 *)((u8 *)this) + 0x68C), 2));
                        }
                    }
                }
            }
            if (hit != 0) {
                ((RenderFadeState *)ch)->fadeOut();
            } else {
                ((RenderFadeState *)ch)->restore();
            }
            update_obstruction_fade(ch);
            if (isFading__15RenderFadeStateCFv(ch) != 0) {
                ch->m6();
                visible = 0;
            }
        }
        if (visible == 0) {
            if (defer_render__7TObjectFv(((u8 *)this)) != 0) {
                visible = 0;
            } else {
                visible = 1;
            }
        }
        if (visible != 0) {
            push_matrix();
            post_translate_matrix(((u8 *)this) + 0x38);
            translate_matrix(0, TBoss1Dragon__data_805D7F28, ((TBoss1Dragon *)((u8 *)this))->heightOffset, TBoss1Dragon__data_805D7F28);
            rotate_matrix_y(0, ((TBoss1Dragon *)((u8 *)this))->rotation_y);
            rotate_matrix_x(0, *(s32 *)((s8 *)((u8 *)this) + 0x5C));
            rotate_matrix_z(0, ((TBoss1Dragon *)((u8 *)this))->rotation_z);
            scale_matrix(0, TBoss1Dragon__data_805D7F24, TBoss1Dragon__data_805D7F24, TBoss1Dragon__data_805D7F24);
            TObjEneRe7Berura::set_global_state((s32)((s32 *) dragon_capture_node_points));
            TObjPlayer::toggle_particle_effect();
            ((TObjMotion *)((u8 *)this))->draw();
            TParticleCtrl::end_effect_render();
            TObjEneRe7Berura::set_global_state((s32)NULL);
            TObjLight__sub_801337F8(current_scene_light);
            pop_matrix();
        }
        set_chunk_material_override_pair(0xFF00, 0);
        set_material_alpha_compare_reference(0xBF);
        model_render_flags = saved_model_render_flags;
    } else {
        ((TBoss1Dragon *)((u8 *)this))->draw();
        SELF->m8(lbl_805D7F30, lbl_805D7F30);
    }
    VecCopy__FP3VecPC3Vec((s32) (((u8 *)this) + 0x40C), (s32) (((u8 *)this) + 0x3E8));
    VecCopy__FP3VecPC3Vec((s32) (((u8 *)this) + 0x418), (s32) (((u8 *)this) + 0x3F4));
    subtract_vector(((u8 *)this) + 0x418, ((u8 *)this) + 0x40C);
    VecCopy__FP3VecPC3Vec((s32) (((u8 *)this) + 0x424), (s32) (((u8 *)this) + 0x400));
    saved_model_render_flags = model_render_flags;
    model_render_flags = saved_model_render_flags | 0x400;
    ((TObject *)(((u8 *)this) + 0x3C4))->render_nodes();
    model_render_flags = saved_model_render_flags;
}
#pragma pop

void TBoss1Dragon::draw() {
    s32 temp_r31;

    temp_r31 = *(s32 *)&this->model;
    *(s32 *)&this->model = (s32) TBoss1Dragon__data_805D4B28;
    TObjEneRe7Berura::set_global_state((s32)(((s32 *)dragon_capture_node_points)));
    push_matrix();
    post_translate_matrix(((u8 *)this) + 0x38);
    translate_matrix(0, TBoss1Dragon__data_805D7F28, this->heightOffset, TBoss1Dragon__data_805D7F28);
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, *(s32 *)&this->rotation_x);
    rotate_matrix_z(0, this->rotation_z);
    scale_matrix(0, TBoss1Dragon__data_805D7F24, TBoss1Dragon__data_805D7F24, TBoss1Dragon__data_805D7F24);
    ((TObjMotion *)((u8 *)this))->draw();
    pop_matrix();
    TObjEneRe7Berura::set_global_state((s32)NULL);
    *(s32 *)&this->model = temp_r31;
}

void dragon_capture_node_points(void) {
    s32 temp_r0;
    s32 temp_r4;
    if ((s32) TBoss1Dragon__data_805D4B0C == (s32) lbl_805D4B10) {
        push_matrix();
        update_camera_sequence__9TObjEneDDFv();
        mult_vec_array__10TObjPlayerFUll(0, (void *)&lbl_804FE194.value, TBoss1Dragon__data_805D4B14, 3);
        pop_matrix();
    }
    if ((s32) TBoss1Dragon__data_805D4B0C == (s32) *(s32 *)((s8 *)&boss1_dragon_capture_node_table.value + (TBoss1Dragon__data_805D4B18 * 4))) {
        temp_r4 = TBoss1Dragon__data_805D4B1C;
        TBoss1Dragon__data_805D4B1C = temp_r4 + 0xC;
        get_camera_ctrl__9TObjEneDDFv((s32) &lbl_804FE188.value, temp_r4);
        temp_r0 = TBoss1Dragon__data_805D4B18 + 1;
        TBoss1Dragon__data_805D4B18 = temp_r0;
        if ((temp_r0 == 7) && !(TBoss1Dragon__data_805D4B20 & 0x80)) {
            TBoss1Dragon__data_805D4B18 = 0xC;
            TBoss1Dragon__data_805D4B1C += 0x3C;
        }
        if (((s32) TBoss1Dragon__data_805D4B18 == 0x12) && !(TBoss1Dragon__data_805D4B20 & 0x200)) {
            TBoss1Dragon__data_805D4B18 = 0x20;
            TBoss1Dragon__data_805D4B1C += 0xA8;
        }
    }
    TBoss1Dragon__data_805D4B0C += 1;
}

void TBoss1Dragon::action(s32 arg1) {
    switch (arg1) {
    case 4:
        this->m_b8 = 0;
        this->stateStep = 0;
        this->position.y = (f32) TBoss1Dragon__data_805D7F28;
        this->heightOffset = (f32) (lbl_805D7F44 + this->defaultHeightOffset);
        this->height = (f32) (this->defaultHeightOffset + (this->heightOffset + this->position.y));
        return;
    case 3:
        if ((s32) this->stateStep > 0x96) {
            transition_enemy_state((s16)(8));
        }
    case 5:
    case 1:
        return;
    case 0:
        if ((get_player_by_client_id(0) != 0U) || (get_player_by_client_id(1) != 0U) || (get_player_by_client_id(2) != 0U) || (get_player_by_client_id(3) != 0U)) {
            this->stateStep = (this->stateStep + 1);
        }
        break;
    }
}

#define ANIM(s) ((s32 (*)(void *)) advance_animation_playback)(s)
void TBoss1Dragon::update_appearance_state(u32 reason) {
    Dragon_80021490 *self = (Dragon_80021490 *)this;
    s32 *demo = &self->demo_active;
    u8 *p;
    switch (reason) {
    case 4:
        self->action = 0;
        clearState__12TBoss1DragonFv(self);
        ANIM(self);
        self->pos.x = TBoss1Dragon__data_805D7F28;
        self->pos.y = TBoss1Dragon__data_805D7F28;
        self->pos.z = TBoss1Dragon__data_805D7F28;
        self->rot[0] = 0;
        self->rot[1] = 0;
        self->rot[2] = 0;
        self->altitude = TBoss1Dragon__data_805D7F28;
        self->offset = self->base;
        self->mouth = 0;
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            self->phase = 1;
            break;
        case 1:
            self->phase = 2;
            break;
        }
        self->stage = 0;
        self->ticks = 0;
        *demo = 1;
        p = __nw__7TObjectFUl(0x28);
        if (p != NULL) {
            __ct__16TBoss1DragonDemoFv(p, tl_01, (s32) demo, TBoss1Dragon__data_805D7F48);
        }
        self->action = 25;
        TWindowCtrl::init_all_slots();
        ((TObjEneDD *)self)->get_target_state_b();
        ((TMainCursor *)self)->update_pair();
        break;
    case 2:
    case 9:
        if (self->phase == 4) {
            request_state_change__12TBoss1DragonFPvs(self, 0);
        }
        break;
    case 0:
        switch (self->phase) {
        case 0:
            break;
        case 1:
            ANIM(self);
            if (((TObjEneDD *)self)->get_flag_b4() != 0) {
                self->phase = 4;
                TWindowCtrl::init_all_slots2();
                self->action = 0;
            }
            switch (self->stage) {
            case 0:
                if (objInBand((GameObj *)self, (f32)TBoss1Dragon__data_805D7F24) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                    self->stage++;
                }
                break;
            case 1:
                if (objInBand((GameObj *)self, (f32)lbl_805D7F4C) != 0) {
                    play_sound_effect(0x4003AD0E, 0, 0, 0);
                }
                if (objInBand((GameObj *)self, (f32)TBoss1Dragon__data_805D7F50) != 0) {
                    spawn_particle_effect_with_flags(&self->pos, self->tbl->e8, 0x40);
                    self->stage++;
                }
                break;
            case 2:
                if (objInBand((GameObj *)self, (f32)lbl_805D7F54) != 0) {
                    play_sound_effect(0x4003AD06, 0, 0, 0);
                    self->stage++;
                    self->ticks = 0;
                }
                break;
            case 3:
                if (self->frame <= lbl_805D7F58) {
                    self->ticks++;
                    if (self->ticks % 4 == 0) {
                        spawn_particle_effect_with_flags(&self->fxpos, self->tbl->e1C, 0x40);
                    }
                } else {
                    self->stage++;
                }
                break;
            case 4:
                if (objInBand((GameObj *)self, (f32)lbl_805D7F5C) != 0) {
                    ((s32 (*)(void *)) play_cue_stream_file)((void*)boss1_dragon_death_cue_filename);
                    self->stage++;
                    self->ticks = 0;
                }
                break;
            case 5:
                if (self->frame < lbl_805D7F60) {
                    Rot_80021490 rot;
                    direction_to_rotation_xz((u8 *)&self->fxdir, &rot.x, &rot.z);
                    if (self->mouth == 0) {
                        self->mouth = spawn_particle_effect_with_rotation(&self->fxpos, &rot, (void *) self->tbl->e14, 0x40);
                    } else {
                        ((TNowLoading *)((void *) self->mouth))->copy_pos(&self->fxpos);
                        ((TBoss4Type2 *)((void *) self->mouth))->copy_vec3(&rot);
                    }
                } else {
                    if (self->mouth != 0) {
                        queue_destruction__7TObjectFv((void *) self->mouth);
                        self->mouth = 0;
                    }
                    self->stage++;
                }
                break;
            }
            break;
        case 2:
            ANIM(self);
            if (((TObjEneDD *)self)->get_flag_b4() != 0) {
                self->phase = 4;
                TWindowCtrl::init_all_slots2();
                self->action = 0;
            }
            switch (self->stage) {
            case 0:
                if (objInBand((GameObj *)self, (f32)TBoss1Dragon__data_805D7F64) != 0 ||
                    objInBand((GameObj *)self, (f32)TBoss1Dragon__data_805D7F68) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                }
                if (objInBand((GameObj *)self, (f32)lbl_805D7F6C) != 0) {
                    play_sound_effect(0x4003AD0E, 0, 0, 0);
                }
                if (objInBand((GameObj *)self, (f32)lbl_805D7F70) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                    spawn_particle_effect_with_flags(&self->pos, self->tbl->e8, 0x40);
                    self->stage++;
                }
                break;
            case 1:
                if (objInBand((GameObj *)self, (f32)lbl_805D7F74) != 0) {
                    play_sound_effect(0x4003AD06, 0, 0, 0);
                    self->stage++;
                    self->ticks = 0;
                }
                break;
            case 2:
                if (self->frame <= lbl_805D7F78) {
                    self->ticks++;
                    if (self->ticks % 4 == 0) {
                        spawn_particle_effect_with_flags(&self->fxpos, self->tbl->e1C, 0x40);
                    }
                } else {
                    self->stage++;
                }
                break;
            case 3:
                if (objInBand((GameObj *)self, (f32)lbl_805D7F7C) != 0) {
                    ((s32 (*)(void *)) play_cue_stream_file)((void*)boss1_dragon_death_cue_filename);
                    self->stage++;
                    self->ticks = 0;
                }
                break;
            case 4:
                if (self->frame < lbl_805D7F80) {
                    Rot_80021490 rot;
                    direction_to_rotation_xz((u8 *)&self->fxdir, &rot.x, &rot.z);
                    if (self->mouth == 0) {
                        self->mouth = spawn_particle_effect_with_rotation(&self->fxpos, &rot, (void *) self->tbl->e14, 0x40);
                    } else {
                        ((TNowLoading *)((void *) self->mouth))->copy_pos(&self->fxpos);
                        ((TBoss4Type2 *)((void *) self->mouth))->copy_vec3(&rot);
                    }
                } else {
                    if (self->mouth != 0) {
                        queue_destruction__7TObjectFv((void *) self->mouth);
                        self->mouth = 0;
                    }
                    self->stage++;
                }
                break;
            }
            break;
        case 3:
            ANIM(self);
            if (((TObjEneDD *)self)->get_flag_b4() != 0) {
                self->phase = 4;
                TWindowCtrl::init_all_slots2();
                self->action = 0;
            }
            switch (self->stage) {
            case 0:
                if (objInBand((GameObj *)self, (f32)TBoss1Dragon__data_805D7F24) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                    self->stage++;
                }
                break;
            case 1:
                if (objInBand((GameObj *)self, (f32)TBoss1Dragon__data_805D7F84) != 0) {
                    play_sound_effect(0x4003AD0E, 0, 0, 0);
                }
                if (objInBand((GameObj *)self, (f32)lbl_805D7F88) != 0) {
                    spawn_particle_effect_with_flags(&self->pos, self->tbl->e8, 0x40);
                    spawn_particle_effect_with_flags(&self->pos, 0x203, 0x40);
                    self->stage++;
                }
                break;
            case 2:
                if (objInBand((GameObj *)self, (f32)lbl_805D7F54) != 0) {
                    play_sound_effect(0x4003AD06, 0, 0, 0);
                    self->stage++;
                    self->ticks = 0;
                }
                break;
            case 3:
                if (self->frame > lbl_805D7F58) {
                    self->stage++;
                }
                break;
            case 4:
                if (objInBand((GameObj *)self, (f32)lbl_805D7F5C) != 0) {
                    ((s32 (*)(void *)) play_cue_stream_file)((void*)boss1_dragon_death_cue_filename);
                    self->stage++;
                    self->ticks = 0;
                }
                break;
            case 5:
                if (self->frame < lbl_805D7F60) {
                    Rot_80021490 rot;
                    direction_to_rotation_xz((u8 *)&self->fxdir, &rot.x, &rot.z);
                    if (self->mouth == 0) {
                        self->mouth = spawn_particle_effect_with_rotation(&self->fxpos, &rot, (void *) self->tbl->e14, 0x40);
                    } else {
                        ((TNowLoading *)((void *) self->mouth))->copy_pos(&self->fxpos);
                        ((TBoss4Type2 *)((void *) self->mouth))->copy_vec3(&rot);
                    }
                } else {
                    if (self->mouth != 0) {
                        queue_destruction__7TObjectFv((void *) self->mouth);
                        self->mouth = 0;
                    }
                    self->stage++;
                }
                break;
            }
            break;
        case 4:
            ANIM(self);
            break;
        }
        break;
    case 5:
        if (self->mouth != 0) {
            queue_destruction__7TObjectFv((void *) self->mouth);
            self->mouth = 0;
        }
        ((TMainCursor *)self)->update_cursor_pair();
        *demo = 0;
        TWindowCtrl::init_all_slots2();
        ((TObjEneDD *)self)->get_target_state_a();
        break;
    }
}

void TBoss1Dragon::update_wander_state(s32 arg1) {
    switch (arg1) {
    case 4:
        this->m_b8 = 0xB;
        this->stateStep = 0;
        return;
    case 0:
        this->stateStep = (this->stateStep + 1);
        if ((s32) this->stateStep > 0x5A) {
            this->stateStep = 0;
            this->m_b8 = (this->m_b8 + 1);
            if ((s16) this->m_b8 >= 0x1B) {
                this->m_b8 = 0;
            }
        }
        advance_animation_playback();
    case 3:
    case 5:
    case 1:
        return;
    }
}

void TBoss1Dragon::handleFallState(u32 reason) {
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;
    switch (reason) {
    case 4:
        this->m_b8 = 0x11;
        this->vfunc_96();
        this->clearState();
        TBoss1Dragon__sub_80028B28((u8 *)this);
        this->flags = (s32) (this->flags | 0xE80);
        this->stateStep = 0;
        this->fallVelocity = (f32) TBoss1Dragon__data_805D7F28;
        this->impactAge = 0;
        return;
    case 2:
    case 11:
        this->controlTimer = 0;
        if (get_flag_b4() != 0) {
            request_state_change__12TBoss1DragonFPvs(this, 0x17);
        }
    default:
        return;
    case 9:
        if (get_flag_b4() != 0) {
            switch (this->mode) {
            default:
            case 8:
                next_sequence_action__12TBoss1DragonFv(this);
                return;
            case 10:
                request_state_change__12TBoss1DragonFPvs(this, 9);
                return;
            case 11:
                request_state_change__12TBoss1DragonFPvs(this, 0xD);
                return;
            case 12:
                request_state_change__12TBoss1DragonFPvs(this, 0x15);
                return;
            }
        }
        break;
    case 7:
        this->restorePosition();
        return;
    case 6:
        this->saveCurrentDestination();
        return;
    case 0:
        switch (this->stateStep) {
        case 1:
            break;
        case 0:
            advance_animation_playback();
            this->rootHeight = sample_root_height();
            if (this->m_c0 >= lbl_805D8020) {
                this->stateStep = 1;
            }
            if (objInBand((GameObj *)(this), TBoss1Dragon__data_805D7F24) != 0) {
                play_se_at_pos__12TBoss1DragonFii((s32)this, 0x4003A804);
            }
            if (objInBand((GameObj *)(this), lbl_805D8024) != 0) {
                update_switch_attack();
            }
            break;
        case 2:
            advance_animation_playback();
            break;
        }
        switch (this->stateStep) {
        case 0:
            if (this->m_c0 > TBoss1Dragon__data_805D8008) {
                this->fallVelocity = (f32) (this->fallVelocity + TBoss1Dragon__gravity_accel);
                this->height = (f32) (this->height + this->fallVelocity);
            }
            this->heightOffset = (f32) (this->defaultHeightOffset + ((this->height - this->rootHeight) - this->position.y));
            return;
        case 1:
            this->fallVelocity = (f32) (this->fallVelocity + TBoss1Dragon__gravity_accel);
            this->height = (f32) (this->height + this->fallVelocity);
            temp_f3 = this->position.y;
            temp_f1 = this->rootHeight;
            temp_f2 = this->height;
            if (temp_f2 < (temp_f3 + temp_f1)) {
                this->stateStep = 2;
                this->height = (f32) this->position.y;
                this->heightOffset = (f32) this->defaultHeightOffset;
                play_se_at_pos__12TBoss1DragonFii((s32)this, 0x4003AD0E);
                return;
            }
            this->heightOffset = (f32) (this->defaultHeightOffset + ((temp_f2 - temp_f1) - temp_f3));
            return;
        case 2:
            this->impactAge = (this->impactAge + 1);
            if ((s32) this->impactAge == 4) {
                spawn_particle_effect_with_flags(((void *) &this->position.x), (s32)this->effectResource->data, 0x40);
                TCameraCtrl::set_shake_preset(1);
                apply_landing_attack__12TBoss1DragonFi((s32)this);
                return;
            }
            break;
        }
        break;
    case 5:
        this->beginHeightTransition();
        break;
    }
}

extern "C" {

void TBoss1Dragon::render_shadows() {
    s32 temp_r31;
    s32 var_r31;
    u8 *temp_r3;
    u8 *temp_r4;

    var_r31 = 0;
    if (TObjPlayer::check_demo_mode() == 0) {
        if (is_split_screen() != 0) {
            var_r31 = get_camera_mode__11TCameraCtrlFv();
        }
        if ((((Owner_80020A54 *)((u8 *)this))->e[var_r31].m8() != 0) && ((((TBoss1Dragon *)((u8 *)this))->heightOffset - ((TBoss1Dragon *)((u8 *)this))->defaultHeightOffset) >= lbl_805D7F2C) && ((s16) ((TBoss1Dragon *)((u8 *)this))->mode != 0x16)) {
            push_matrix();
            post_translate_matrix((void *) (((u8 *)this) + 0x38));
            rotate_matrix_y(0, (int) (((TBoss1Dragon *)((u8 *)this))->rotation_y));
            scale_matrix(0, TBoss1Dragon__data_805D7F24, TBoss1Dragon__data_805D7F24, TBoss1Dragon__data_805D7F24);
            rotate_matrix_x(0, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x5C)));
            rotate_matrix_z(0, (int) (((TBoss1Dragon *)((u8 *)this))->rotation_z));
            temp_r31 = *(s32 *)((s8 *)((u8 *)this) + 0x34);
            temp_r4 = (u8 *)(*(u8 **)((s8 *)TBoss1Dragon__data_805D4B08 + 0x42C));
            *(s32 *)((s8 *)((u8 *)this) + 0x34) = (s32) *(s32 *)((s8 *)temp_r4 + 0x18);
            ((TObjMotion *)((u8 *)this))->draw();
            *(s32 *)((s8 *)((u8 *)this) + 0x34) = temp_r31;
            pop_matrix();
        }
    }
}

struct Rec_80021260 { u8 pad0[0xC]; f32 f0C; u8 pad10[0xC]; u8 b1C[0x10]; };
struct Obj_80021260 { u8 pad0[0xA4]; Rec_80021260 *recs; s32 count; };
s32 check_parts_visible__12TBoss1DragonFiPv(s32 arg0, Obj_80021260 *arg1) {
    s32 off;
    s32 n;
    s32 i;
    i = 0;
    off = 0;
    n = arg1->count;
    for (; i < n; i++, off += sizeof(Rec_80021260)) {
        Rec_80021260 *r = (Rec_80021260 *)((u8 *)arg1->recs + off);
        if (((s32 (*)(void *, void *, f32))is_sphere_visible__12TBoss1DragonFf)((void *)arg0, r->b1C, r->f0C) != 0) {
            return 1;
        }
    }
    return 0;
}

#pragma push
#pragma fp_contract on
s32 is_sphere_visible__12TBoss1DragonFf(f32 farg0) {
    Stack_800212D8 stack;
    f32 temp_f1;
    ((s32 (*)(void *))VecCopy__FP3VecPC3Vec)(&stack.sp8);
    stack.spC = TBoss1Dragon__data_805D7F28;
    subtract_vector(&stack.sp8, (void *) lbl_804FE1D0);
    temp_f1 = ((f32 (*)(void *))clamp_velocity__15TObjBoss2TunnelFv)(&stack.sp8);
    if ((temp_f1 + farg0) < boss1_dragon_visibility_distance) {
        if (vec3_dot(&stack.sp8, (void *) lbl_804FE1DC) >= (temp_f1 * (TBoss1Dragon__data_805D7F40 / newton_sqrtf((f32) ((temp_f1 * temp_f1) + (farg0 * farg0)))))) {
            return 1;
        }
    }
    return 0;
}
#pragma pop

struct Vec_80021DE4 { f32 x, y, z; };
struct Ext_80021DE4 { u8 pad0[0x3A0]; Vec_80021DE4 dir; };
extern const f32 lbl_805D7F8C;
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define self ((TBoss1Dragon *)arg0)
#define ext ((Ext_80021DE4 *)arg0)
void TBoss1Dragon::handle_fall_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        self->m_b8 = 0x11;
        this->vfunc_96();
        self->setPhase2();
        TBoss1Dragon__sub_80028AFC(arg0);
        self->flags = self->flags | 0xC00;
        self->flags = self->flags & 0xFFFFFC7F;
        this->vfunc_91();
        this->vfunc_94();
        self->fallVelocity = TBoss1Dragon__data_805D7F28;
        ext->dir.x = -self->position.x;
        ext->dir.y = TBoss1Dragon__data_805D7F28;
        ext->dir.z = -self->position.z;
        ((void (*)(void *))clamp_velocity__15TObjBoss2TunnelFv)(arg0 + 0x3A0);
        this->rotation_y = (s32) (boss1_dragon_angle_units_per_radian * atan2_float(ext->dir.x, ext->dir.z));
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->set_field_3c();
        return;
    case 2:
    case 11:
        if (self->rootHeight >= lbl_805D7F8C) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x13);
        }
    default:
        return;
    case 7:
        self->restorePosition();
        return;
    case 6:
        self->saveCurrentDestination();
        return;
    case 0:
        self->fallVelocity += TBoss1Dragon__data_805D7F90;
        if (self->fallVelocity > TBoss1Dragon__data_805D7F38) {
            self->fallVelocity = TBoss1Dragon__data_805D7F38;
        }
        self->rootHeight = self->rootHeight + self->fallVelocity;
        self->position.x = ext->dir.x * self->fallVelocity + self->position.x;
        self->position.z = ext->dir.z * self->fallVelocity + self->position.z;
        TBoss1Dragon__sub_800277D8(arg0);
        return;
    case 5:
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->spawn_child_object();
        break;
    }
}
#undef self
#undef ext
#pragma pop

void TBoss1Dragon::state_circle_flight(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;

    switch (arg1) {
    case 4:
        this->m_b8 = 0x11;
        this->vfunc_96();
        ((TBoss1Dragon *)arg0)->setPhase2();
        TBoss1Dragon__sub_80028AFC(arg0);
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & 0xFFFFFC7F);
        this->vfunc_91();
        this->vfunc_94();
        ((TBoss1Dragon *)arg0)->updateFacingPosition();
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->set_field_3c();
        return;
    case 2:
    case 11:
        if (((s32) this->stateStep >= 0x1C2) || (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), 0x400) != 0)) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x25);
        }
        return;
    case 7:
        this->facingAngle = (s32) this->savedX;
        if (this->savedZ > TBoss1Dragon__data_805D7F28) {
            *(s32 *)((s8 *)arg0 + 0x874) = 0x180;
            return;
        }
        *(s32 *)((s8 *)arg0 + 0x874) = -0x180;
        return;
    case 6:
        this->destinationX = (f32) (TBoss1Dragon__data_805D7F94 * calc_boss4_scale__10TObjPlayerFi());
        this->destinationZ = calc_elapsed_scaled__9TObjEneDDFv(arg0);
        return;
    case 0:
        this->facingAngle = (s32) (this->facingAngle + *(s32 *)((s8 *)arg0 + 0x874));
        if ((s32) *(s32 *)((s8 *)arg0 + 0x874) >= 0) {
            this->rotation_y = (this->facingAngle + 0x9800);
        } else {
            this->rotation_y = (this->facingAngle + 0xFFFF6800);
        }
        ((TBoss1Dragon *)arg0)->updateFacingPosition();
        temp_r4 = this->stateStep;
        this->stateStep = (temp_r4 + 1);
        ((void (*)(u8 *, s32))TBoss1Dragon__sub_800277D8)(arg0, temp_r4);
        return;
    case 5:
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->spawn_child_object();
        break;
    default:
        break;
    }
}

struct Vec_80022158 { f32 x, y, z; };
struct Ext_80022158 { u8 pad0[0x38]; Vec_80022158 pos; u8 pad44[0x890 - 0x44]; Vec_80022158 home; };
struct Input_80022158 { u8 pad0[8]; s32 flags; u8 padC[0x1C - 0xC]; s32 angle; u8 pad20[4]; f32 f24; };

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define self ((TBoss1Dragon *)arg0)
#define ext ((Ext_80022158 *)arg0)
void TBoss1Dragon__sub_80022158(TBoss1Dragon *arg0, u32 arg1) {
    f32 dx;
    f32 dz;
    Vec_80022158 *home;
    Input_80022158 *in;
    extern const u8 TBoss1Dragon__data_80434E80[0xC];

    home = &ext->home;
    switch (arg1) {
    case 4:
        self->m_b8 = 0x11;
        ((TBoss1Dragon *)(arg0))->vfunc_96();
        self->setPhase2();
        TBoss1Dragon__sub_80028AFC((u8 *)arg0);
        self->flags = self->flags | 0xC00;
        self->flags = self->flags & 0xFFFFFC7F;
        ((TBoss1Dragon *)(arg0))->vfunc_91();
        ((TBoss1Dragon *)(arg0))->vfunc_94();
        VecCopy__FP3VecPC3Vec((s32)home, (s32)&ext->pos);
        self->stateStep = 0x64;
        self->impactAge = 0;
        home->y = ((const Vec_80022158 *)TBoss1Dragon__data_80434E80)->y;
        self->fallVelocity = TBoss1Dragon__data_805D7F28;
        self->rootHeight = TBoss1Dragon__data_805D7F28;
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->set_field_1c();
        return;
    case 2:
    case 11:
        if (self->impactAge == 1) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x1B);
            return;
        }
        if ((*(Input_80022158 **)((s8 *)self + 0x6E4))->flags & 2) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x13);
        }
    default:
        return;
    case 8:
        self->stateStep = self->stateStep + 1;
        if (self->stateStep >= 0x1E) {
            self->stateStep = 0;
            in = *(Input_80022158 **)((s8 *)self + 0x6E4);
            if (in->f24 <= TBoss1Dragon__data_805D7F90) {
                self->impactAge = 1;
                return;
            }
            arg0->rotation_y = in->angle;
            self->setDestinationX(arg0->rotation_y);
            send_state_sync__12TBoss1DragonFPv((struct dragon_80028530 *)arg0);
            return;
        }
        break;
    case 7:
        self->copySavedX((int *)((u8 *)arg0 + 0x60));
        return;
    case 6:
        self->setDestinationX(arg0->rotation_y);
        return;
    case 0:
        dx = sin_table_lookup(arg0->rotation_y);
        dz = cos_table_lookup(arg0->rotation_y);
        ext->pos.x = dx * TBoss1Dragon__data_805D7F98 + ext->pos.x;
        ext->pos.z = dz * TBoss1Dragon__data_805D7F98 + ext->pos.z;
        horizontal_distance_squared(&ext->pos, home);
        dx = ((f32 (*)(void))newton_sqrtf)();
        VecCopy__FP3VecPC3Vec((s32)home, (s32)&ext->pos);
        self->fallVelocity = self->fallVelocity + dx;
        return;
    case 5:
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->spawn_child_object();
        break;
    }
}
#undef self
#undef ext
#pragma pop

void TBoss1Dragon::handle_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    u8 *temp_r3;

    switch (arg1) {
    case 4:
        this->vfunc_96();
        ((TBoss1Dragon *)arg0)->setPhase2();
        TBoss1Dragon__sub_80028AFC(arg0);
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & 0xFFFFFC7F);
        this->vfunc_91();
        this->vfunc_94();
        this->stateStep = 0;
        return;
    case 2:
    case 11:
        temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x6E4));
        if (*(f32 *)((s8 *)temp_r3 + 0x24) > TBoss1Dragon__data_805D7F90) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x1C);
            return;
        }
        if (*(s32 *)((s8 *)temp_r3 + 8) & 2) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x13);
            return;
        }
        break;
    case 7:
        restorePosition__12TBoss1DragonFv(arg0);
        return;
    case 6:
        saveCurrentDestination__12TBoss1DragonFv(arg0);
        return;
    case 0:
        this->stateStep = (this->stateStep + 1);
        if ((s32) this->stateStep > 0xA) {
            clear_work__12TBoss1DragonFi((s32)arg0);
            this->stateStep = 0;
        }
        break;
    }
}

void TBoss1Dragon__sub_800224A4(TBoss1Dragon *arg0, u32 arg1) {
    f32 temp_f31;
    f32 temp_f30;
    f32 var_f3;
    s32 temp_r4;
    u8 *temp_r4_2;
    s32 *saved = (s32 *)((u8 *)arg0 + 0x874);

    switch (arg1) {
    case 4:
        arg0->m_b8 = 0x10;
        ((TBoss1Dragon *)(arg0))->vfunc_96();
        arg0->setActive();
        TBoss1Dragon__sub_80028B28((u8 *)arg0);
        arg0->flags = (s32) (arg0->flags & ~0xE80);
        arg0->stateStep = 0x64;
        arg0->impactAge = 0;
        return;
    case 11:
        if (((s32) arg0->controlTimer > 0x1C2) || (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), 2) != 0)) {
            request_state_change__12TBoss1DragonFPvs(arg0, 8);
            return;
        }
        if ((s32) arg0->impactAge == 1) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x19);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), 4) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 7);
            return;
        }
        if (arg0->check_can_attack() != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0xF);
        }
    default:
        return;
    case 2:
        if ((s32) arg0->impactAge == 1) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x19);
            return;
        }
        temp_r4 = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8);
        if (temp_r4 & 4) {
            request_state_change__12TBoss1DragonFPvs(arg0, 7);
            return;
        }
        if (temp_r4 & 2) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0xF);
            return;
        }
        if (temp_r4 & 0x400) {
            request_state_change__12TBoss1DragonFPvs(arg0, 8);
            return;
        }
        break;
    case 8:
        arg0->stateStep = (arg0->stateStep + 1);
        if ((s32) arg0->stateStep >= 0x1E) {
            arg0->stateStep = 0;
            temp_r4_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x6E4));
            if (*(f32 *)((s8 *)temp_r4_2 + 0x24) <= TBoss1Dragon__data_805D7F90) {
                arg0->impactAge = 1;
                return;
            }
            *saved = *(s32 *)((s8 *)temp_r4_2 + 0x1C);
            arg0->setDestinationX(*saved);
            send_state_sync__12TBoss1DragonFPv((struct dragon_80028530 *)arg0);
            return;
        }
        break;
    case 7:
        arg0->copySavedX((int*)saved);
        return;
    case 6:
        arg0->setDestinationX(*saved);
        return;
    case 0:
        advance_animation_playback();
        arg0->play_nearby_se();
        TBoss1Dragon__sub_800274A4((s32)arg0);
        arg0->rotation_y = approach_angle_limited(arg0->rotation_y, *saved, 0x200);
        temp_f31 = sin_table_lookup(arg0->rotation_y);
        temp_f30 = cos_table_lookup(arg0->rotation_y);
        var_f3 = TBoss1Dragon__data_805D7F24;
        if ((s32) *(s32 *)((s8 *)arg0 + 0x760) != 0) {
            var_f3 = TBoss1Dragon__sub_80027010((Obj_80027010 *) (arg0), temp_f31, temp_f30, var_f3);
        }
        ((TObjEneDD *)arg0)->move_with_wall_stop(temp_f31, temp_f30, var_f3);
        break;
    }
}

#define self ((TBoss1Dragon *)arg0)
void TBoss1Dragon__sub_80022740(TBoss1Dragon *arg0, u32 arg1) {

    Input_80022740 *in;
    s32 flags;

    switch (arg1) {
    case 4:
        self->m_b8 = 0x10;
        ((VObj_18_444bc5 *)(self))->m94();
        self->setActive();
        TBoss1Dragon__sub_80028B28((u8 *)arg0);
        self->flags = self->flags & ~0xE80;
        return;
    case 11:
        if (self->controlTimer > 0x1C2 || filter_input_flags__12TBoss1DragonFiii((s32)arg0, (*(Input_80022740 **)((s8 *)self + 0x6E4))->flags, 2) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 8);
            return;
        }
        in = *(Input_80022740 **)((s8 *)self + 0x6E4);
        if (in->f24 > TBoss1Dragon__data_805D7F90) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x1A);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, in->flags, 4) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 7);
            return;
        }
        if (arg0->check_can_attack() != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0xF);
        }
    default:
        return;
    case 2:
        in = *(Input_80022740 **)((s8 *)self + 0x6E4);
        if (in->f24 > TBoss1Dragon__data_805D7F90) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x1A);
            return;
        }
        flags = in->flags;
        if (flags & 4) {
            request_state_change__12TBoss1DragonFPvs(arg0, 7);
            return;
        }
        if (flags & 2) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0xF);
            return;
        }
        if (flags & 0x400) {
            request_state_change__12TBoss1DragonFPvs(arg0, 8);
            return;
        }
        break;
    case 7:
        self->restorePosition();
        return;
    case 6:
        self->saveCurrentDestination();
        return;
    case 0:
        advance_animation_playback();
        arg0->play_nearby_se();
        TBoss1Dragon__sub_800274A4((s32)arg0);
        break;
    }
}
#undef self

#define filter_input_flags__12TBoss1DragonFiii ((s32 (*)(s32, s32, s32))filter_input_flags__12TBoss1DragonFiii)
#define check_attack_ready__12TBoss1DragonFPv ((u8 (*)(void *))check_attack_ready__12TBoss1DragonFPv)
#define TBoss1Dragon__sub_80027010 ((f32 (*)(void *, f32, f32, f32))TBoss1Dragon__sub_80027010)
#define send_state_sync__12TBoss1DragonFPv ((void (*)(void *))send_state_sync__12TBoss1DragonFPv)
#define TBoss1Dragon__sub_80028BE0 ((void (*)(u8 *))TBoss1Dragon__sub_80028BE0)
void TBoss1Dragon__sub_800228E8(TBoss1Dragon *arg0, u32 arg1) {
    f32 temp_f31;
    f32 temp_f30;
    f32 var_f29;
    f32 temp_f1;
    s32 temp_r4;
    u8 *temp_r4_2;
    s32 *saved = (s32 *)((u8 *)arg0 + 0x874);

    switch (arg1) {
    case 4:
        arg0->m_b8 = 1;
        ((TBoss1Dragon *)(arg0))->vfunc_96();
        clearState__12TBoss1DragonFv(arg0);
        beginHeightTransition__12TBoss1DragonFv(arg0);
        arg0->flags = (s32) (arg0->flags & ~0xE80);
        arg0->stateStep = 0;
        arg0->impactAge = 0;
        return;
    case 2:
        if ((s32) arg0->impactAge == 1) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x17);
            return;
        }
        temp_r4 = *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8);
        if (temp_r4 & 4) {
            request_state_change__12TBoss1DragonFPvs(arg0, 3);
            return;
        }
        if (temp_r4 & 2) {
            request_state_change__12TBoss1DragonFPvs(arg0, 4);
            return;
        }
        if (temp_r4 & 0x400) {
            request_state_change__12TBoss1DragonFPvs(arg0, 5);
        }
    default:
        return;
    case 11:
        if ((s32) arg0->impactAge == 1) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x17);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), 4) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 3);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), 2) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 4);
            return;
        }
        if (((s32 (*)(void *))check_attack_ready__12TBoss1DragonFPv)(arg0) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 5);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), fn_8002AE08(TBoss1Dragon__data_805D4B3C)) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 9);
            return;
        }
        break;
    case 8:
        arg0->stateStep = (arg0->stateStep + 1);
        if ((s32) arg0->stateStep >= 0x1E) {
            arg0->stateStep = 0;
            temp_r4_2 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x6E4));
            if (*(f32 *)((s8 *)temp_r4_2 + 0x24) <= TBoss1Dragon__data_805D7F90) {
                arg0->impactAge = 1;
                return;
            }
            *saved = *(s32 *)((s8 *)temp_r4_2 + 0x1C);
            arg0->setDestinationX(*saved);
            send_state_sync__12TBoss1DragonFPv(arg0);
            return;
        }
        break;
    case 7:
        arg0->copySavedX((int*)saved);
        return;
    case 6:
        arg0->setDestinationX(arg0->rotation_y);
        return;
    case 0:
        advance_animation_playback();
        if ((s16) arg0->m_b8 == 1) {
            TBoss1Dragon__sub_80028BE0((u8 *)arg0);
        }
        if (objInBand((GameObj *)(arg0), TBoss1Dragon__data_805D7F9C) != 0) {
            arg0->initDefault();
        } else if (objInBand((GameObj *)(arg0), lbl_805D7FA0) != 0) {
            arg0->setState1();
        }
        arg0->m_c8 = (f32) lbl_805D7FA8;
        var_f29 = TBoss1Dragon__data_805D7FA4;
        temp_f1 = arg0->m_c0;
        if ((!(temp_f1 > TBoss1Dragon__data_805D7F98) || !(temp_f1 < TBoss1Dragon__data_805D7F64)) && (!(temp_f1 > lbl_805D7FA0) || !(temp_f1 < TBoss1Dragon__data_805D7FAC))) {
            arg0->rotation_y = approach_angle_limited(arg0->rotation_y, *saved, 0x200);
            temp_f31 = sin_table_lookup(arg0->rotation_y);
            temp_f30 = cos_table_lookup(arg0->rotation_y);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x760) != 0) {
                var_f29 = TBoss1Dragon__sub_80027010(arg0, temp_f31, temp_f30, TBoss1Dragon__data_805D7FA4);
            }
            ((TObjEneDD *)arg0)->move_to_shot_position(temp_f31, temp_f30, var_f29);
        }
        break;
    }
}
#undef filter_input_flags__12TBoss1DragonFiii
#undef check_attack_ready__12TBoss1DragonFPv
#undef TBoss1Dragon__sub_80027010
#undef send_state_sync__12TBoss1DragonFPv
#undef TBoss1Dragon__sub_80028BE0

#define self ((TBoss1Dragon *)arg0)
void TBoss1Dragon__sub_80022C38(TBoss1Dragon *arg0, u32 arg1) {

    Input_80022C38 *in;
    s32 flags;

    switch (arg1) {
    case 4:
        self->m_b8 = 0;
        ((VObj_18_444bc5 *)(self))->m94();
        self->clearState();
        self->beginHeightTransition();
        self->flags = self->flags & ~0xE80;
        return;
    case 11:
        in = *(Input_80022C38 **)((s8 *)self + 0x6E4);
        if (in->f24 > TBoss1Dragon__data_805D7F90) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x18);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, in->flags, 4) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 3);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, (*(Input_80022C38 **)((s8 *)self + 0x6E4))->flags, 2) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 4);
            return;
        }
        if (((s32 (*)(void *))check_attack_ready__12TBoss1DragonFPv)(arg0) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 5);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, (*(Input_80022C38 **)((s8 *)self + 0x6E4))->flags, fn_8002AE08(TBoss1Dragon__data_805D4B3C)) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 9);
        }
    default:
        return;
    case 2:
        in = *(Input_80022C38 **)((s8 *)self + 0x6E4);
        if (in->f24 > TBoss1Dragon__data_805D7F90) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x18);
            return;
        }
        flags = in->flags;
        if (flags & 4) {
            request_state_change__12TBoss1DragonFPvs(arg0, 3);
            return;
        }
        if (flags & 2) {
            request_state_change__12TBoss1DragonFPvs(arg0, 4);
            return;
        }
        if (flags & 0x400) {
            request_state_change__12TBoss1DragonFPvs(arg0, 5);
            return;
        }
        break;
    case 7:
        self->restorePosition();
        return;
    case 6:
        self->saveCurrentDestination();
        return;
    case 0:
        advance_animation_playback();
        break;
    }
}
#undef self

void TBoss1Dragon::update_fade_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 i;

    switch (arg1) {
    case 4:
        this->m_b8 = 0x13;
        this->vfunc_95();
        clearState__12TBoss1DragonFv(arg0);
        beginHeightTransition__12TBoss1DragonFv(arg0);
        this->flags |= 0xE80;
        for (i = 0; i < 4; i++) {
            ((TBoss8Dragon *)(&((Dragon_80022DF4 *) arg0)->parts[i]))->set_speed(lbl_805D7FB0);
        }
        break;
    case 0:
        advance_animation_playback();
        for (i = 0; i < 4; i++) {
            if (((Dragon_80022DF4 *) arg0)->parts[i].p4() != 0) {
                queue_destruction__7TObjectFv(arg0);
            }
        }
        break;
    case 1:
        return;
    case 2:
        return;
    case 3:
        return;
    case 5:
        return;
    case 6:
        return;
    case 7:
        return;
    case 8:
        return;
    case 9:
        return;
    case 10:
        return;
    case 11:
        return;
    }
}

#define TBoss1Dragon__sub_800277D8 ((void (*)(u8 *))TBoss1Dragon__sub_800277D8)
#define clear_work__12TBoss1DragonFi ((void (*)(s32))clear_work__12TBoss1DragonFi)
#define calc_burrow_speed__12TBoss1DragonFPv ((f32 (*)(void *))calc_burrow_speed__12TBoss1DragonFPv)
#define spawn_trap__12TBoss1DragonFii ((void (*)(s32, s32))spawn_trap__12TBoss1DragonFii)

#define F(T, o) (*(T *)(arg0 + (o)))
#define RES(o) (*(s32 *)((u8 *)&TBoss1Dragon__part_hp_stats + (o)))
void update_death_state__12TBoss1DragonFv(u8 *arg0, u32 arg1) {
    Eff_80022EE0 eff1;
    Eff_80022EE0 eff2;
    Cam_80022EE0 cam;
    Vec_80022EE0 rot;
    Vec_80022EE0 v;
    void *u;
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 0x13;
        ((TBoss1Dragon *)(arg0))->vfunc_95();
        clearState__12TBoss1DragonFv(arg0);
        beginHeightTransition__12TBoss1DragonFv(arg0);
        F(s32, 0x3C0) |= 0xE80;
        F(s32, 0x864) = 0;
        F(s32, 0x868) = 0;
        F(f32, 0x87C) = TBoss1Dragon__data_805D7F28;
        F(u32, 0x8AC) = 0;
        ((s32 (*)(void *))play_cue_stream_file)((void*)boss1_dragon_death_cue_filename);
        TWindowCtrl::init_all_slots();
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            cam.sub = 0;
            cam.mode = 2;
            cam.c = 0;
            cam.d = TBoss1Dragon__data_805D7F28;
            cam.e = TBoss1Dragon__data_805D7F48;
            activate_camera_mode(5);
            ((TCameraCtrl *)(&cam))->cache_target_and_forward(0x31C7);
            set_scripted_camera_pose(arg0 + 0x38, arg0 + 0x38, arg0 + 0x5C);
            break;
        case 1:
            cam.sub = 1;
            cam.mode = 2;
            cam.c = 0;
            cam.d = TBoss1Dragon__data_805D7F28;
            cam.e = TBoss1Dragon__data_805D7F48;
            activate_camera_mode(5);
            ((TCameraCtrl *)(&cam))->cache_target_and_forward(0x3333);
            set_scripted_camera_pose(arg0 + 0x38, arg0 + 0x38, arg0 + 0x5C);
            break;
        }
        break;
    case 2:
    case 11:
        if (F(s32, 0x868) >= 0x32) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x16);
        }
        break;
    case 9:
        if (F(s32, 0x868) >= 0x32) {
            request_state_change__12TBoss1DragonFPvs(u, 0x16);
        }
        break;
    case 0:
        advance_animation_playback();
        switch (F(s32, 0x864)) {
        case 0:
            if (objInBand((GameObj *)arg0, (f32)TBoss1Dragon__data_805D7F84) != 0 || objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805D7FB4)) != 0) {
                play_sound_effect(0x4003AD07, 0, 0, 0);
                start_pad_rumble_all(0xA0, 0xF);
            }
            if (F(f32, 0xC0) >= TBoss1Dragon__data_805D7F3C && F(f32, 0xC0) < TBoss1Dragon__data_805D7F68) {
                direction_to_rotation_xz(arg0 + 0x418, (s32 *)&rot.x, (s32 *)&rot.z);
                if (F(u32, 0x8AC) == 0) {
                    F(u32, 0x8AC) = spawn_particle_effect_with_rotation(arg0 + 0x40C, &rot, (void *)*(s32 *)((s8 *)(F(u8 *, 0x778)) + 0x14), 0x40);
                }
                if (F(u32, 0x8AC) != 0) {
                    ((TNowLoading *)(F(void *, 0x8AC)))->copy_pos(arg0 + 0x424);
                    ((TBoss4Type2 *)(F(void *, 0x8AC)))->copy_vec3(&rot);
                }
            } else if (F(u32, 0x8AC) != 0) {
                queue_destruction__7TObjectFv(F(void *, 0x8AC));
                F(u32, 0x8AC) = 0;
            }
            if (objInBand((GameObj *)arg0, (f32)lbl_805D7FB8) != 0) {
                eff1 = *(Eff_80022EE0 *)TBoss1Dragon__head_fall_effect_params;
                *(f32 *)&eff1.w[2] = TBoss1Dragon__data_805D7F38;
                ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v, lbl_80434EC8);
                rotate_xz_pair_by_angle(&v.x, &v.z, F(s32, 0x60));
                vec3_add_to(&v, arg0 + 0x38);
                reset_hp__9TObjEneDDFv(arg0, 0, RES(0x10), 0);
                switch (isV2Mode__12TBoss1DragonFv()) {
                case 0:
                    TObjEneDD::emit_effect((void*)arg0, (int)&v, (int)&eff1);
                    break;
                case 1:
                    ((void (*)(u8 *, void *, u8 *, s32))TBoss1Dragon__sub_800275BC)(arg0, &v, (u8 *)&eff1, 0);
                    break;
                }
                reset_hp__9TObjEneDDFv(arg0, 0, RES(0), 0);
                spawn_particle_effect_with_flags(&v, *(s32 *)((s8 *)(F(u8 *, 0x778)) + 8), 0x40);
            }
            if (objInBand((GameObj *)arg0, (f32)lbl_805D7FBC) != 0) {
                eff2 = *(Eff_80022EE0 *)TBoss1Dragon__head_fall_effect_params;
                *(f32 *)&eff2.w[2] = TBoss1Dragon__data_805D7F3C;
                ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v, lbl_80434ED4);
                rotate_xz_pair_by_angle(&v.x, &v.z, F(s32, 0x60));
                vec3_add_to(&v, arg0 + 0x38);
                reset_hp__9TObjEneDDFv(arg0, 0, RES(0x10), 0);
                switch (isV2Mode__12TBoss1DragonFv()) {
                case 0:
                    TObjEneDD::emit_effect((void*)arg0, (int)&v, (int)&eff2);
                    break;
                case 1:
                    ((void (*)(u8 *, void *, u8 *, s32))TBoss1Dragon__sub_800275BC)(arg0, &v, (u8 *)&eff2, 0);
                    break;
                }
                reset_hp__9TObjEneDDFv(arg0, 0, RES(0), 0);
                spawn_particle_effect_with_flags(&v, *(s32 *)((s8 *)(F(u8 *, 0x778)) + 8), 0x40);
            }
            if (objInBand((GameObj *)arg0, (f32)lbl_805D7FC0) != 0) {
                ((TBoss1Dragon *)arg0)->sweep_death_body_attack();
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                F(s32, 0x864) = 1;
                F(s32, 0x868) = 0;
            }
            break;
        case 1:
            F(s32, 0x868) += 1;
            if (F(s32, 0x868) >= 0x32) {
                TWindowCtrl::init_all_slots2();
                restore_player_cameras();
            }
            break;
        }
        break;
    case 5:
        ((TBoss8Dragon *)arg0)->refresh_and_send_entity_flags();
        TBoss4DarkFalz::dispatch_by_main_phase(0x17);
        F(s32, 0x30) = 0x12008;
        ((TBoss1Dragon *)(arg0))->vfunc_74(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        if (F(u32, 0x8AC) != 0) {
            queue_destruction__7TObjectFv(F(void *, 0x8AC));
            F(u32, 0x8AC) = 0;
        }
        if (F(s32, 0x760) != 0) {
            ((TBoss1Dragon *)arg0)->release_held_player();
        }
        break;
    }
}

struct Vec_80023450 { f32 x, y, z; };
extern const f32 lbl_805D7FC8;
extern const f32 lbl_805D7FCC;
extern const f32 lbl_805D7FD4;
extern const f32 lbl_805D7FD8;
extern const f32 lbl_805D7FDC;
extern const f32 lbl_805D7FE4;
extern const f32 lbl_805D7FE8;
#pragma push
#pragma fp_contract on
#define TGT_80023450 ((const Vec_80023450 *)TBoss1Dragon__data_80434E80)
#define CLAMP_80023450 ((f32 (*)(void *))clamp_velocity__15TObjBoss2TunnelFv)
#define UPDVEL_80023450 ((s32 (*)(void *, f32))update_velocity__9TObjEneDDFv)
#define PLAY_80023450 ((s32 (*)(void *))advance_animation_playback)

void TBoss1Dragon::update_emergence_state(u32 arg1) {
    extern const u8 TBoss1Dragon__data_80434E80[0xC];
    Vec_80023450 *v = (Vec_80023450 *)(((u8 *)this) + 0x890);
    f32 len;

    switch (arg1) {
    case 4:
        this->m_b8 = 0x18;
        PLAY_80023450(this);
        this->vfunc_96();
        this->setPhase2();
        TBoss1Dragon__sub_80028AFC(((u8 *)this));
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & 0xFFFFFC7F);
        this->stateStep = 0;
        this->impactAge = 0;
        return;
    case 2:
    case 11:
        if (this->stateStep == 6) {
            request_state_change__12TBoss1DragonFPvs(this, 0x19);
        }
        return;
    case 9:
        if (this->stateStep == 6) {
            request_state_change__12TBoss1DragonFPvs(this, 8);
        }
        return;
    case 6:
        if (choose_burrow_ring_destination__12TBoss1DragonFPvPv((Dragon_80028EA8 *)this, (Vec_80028EA8 *)(((u8 *)this) + 0x394)) == 0) {
            this->targetX = TBoss1Dragon__data_805D7F28;
            this->targetY = *(f32 *)((s8 *)((u8 *)this) + 0x3C);
            this->targetZ = TBoss1Dragon__data_805D7F28;
            UPDVEL_80023450(this, TBoss1Dragon__data_805D7F28);
        }
        this->saveTargetDestination();
        return;
    case 0:
        switch (this->stateStep) {
        case 0:
            (this->impactAge)++;
            if ((f32) this->impactAge >= TBoss1Dragon__data_805D7FC4) {
                this->stateStep = 1;
                restorePosition__12TBoss1DragonFv(this);
                this->flags |= 0x100;
                v->x = TGT_80023450->x - *(f32 *)((s8 *)((u8 *)this) + 0x38);
                v->y = TBoss1Dragon__data_805D7F28;
                v->z = TGT_80023450->z - *(f32 *)((s8 *)((u8 *)this) + 0x40);
                len = CLAMP_80023450(v);
                if (len <= TBoss1Dragon__data_805D7FC4) {
                    this->fallVelocity = TBoss1Dragon__data_805D7F28;
                    *(s32 *)((s8 *)((u8 *)this) + 0x5C) = 0;
                } else {
                    f32 k = lbl_805D7FC8;
                    k += newton_sqrtf(lbl_805D7FCC);
                    this->fallVelocity = len / k;
                    *(s32 *)((s8 *)((u8 *)this) + 0x5C) = (s32) (boss1_dragon_angle_units_per_radian * atan2_float(this->fallVelocity, lbl_805D7FD0));
                }
                this->rotation_y = (s32) (boss1_dragon_angle_units_per_radian * atan2_float(v->x, v->z));
                this->rootHeight = lbl_805D7FD0;
                v->x *= this->fallVelocity;
                v->z *= this->fallVelocity;
                *(f32 *)((s8 *)((u8 *)this) + 0x38) = v->x * lbl_805D7FD4 + *(f32 *)((s8 *)((u8 *)this) + 0x38);
                *(f32 *)((s8 *)((u8 *)this) + 0x40) = v->z * lbl_805D7FD4 + *(f32 *)((s8 *)((u8 *)this) + 0x40);
                this->height = lbl_805D7FD8;
                this->heightOffset = this->defaultHeightOffset + (this->height - *(f32 *)((s8 *)((u8 *)this) + 0x3C));
            }
            break;
        case 1:
            if (this->height > TGT_80023450->y) {
                this->stateStep = 2;
                this->vfunc_92();
                this->vfunc_93();
                this->setActive();
                this->spawn_impact_crater((s32)(((u8 *)this) + 0x38));
                this->apply_ground_impact_attack();
                play_se_at_pos__12TBoss1DragonFii((s32) this, 0x4003AD0F);
            }
            break;
        case 2:
            if (this->height > lbl_805D7FDC) {
                this->stateStep = 3;
            }
            break;
        case 3:
            if (this->rootHeight < TBoss1Dragon__data_805D7F28 && this->height < lbl_805D7FE0) {
                this->stateStep = 4;
                *(f32 *)((s8 *)((u8 *)this) + 0x884) = (this->rootHeight * this->rootHeight) / lbl_805D7F58;
            }
            break;
        case 4:
            if (this->rootHeight > TBoss1Dragon__data_805D7F28) {
                this->stateStep = 5;
                this->rootHeight = TBoss1Dragon__data_805D7F28;
                this->impactAge = 0;
            }
            break;
        }
        switch (this->stateStep) {
        case 1:
            vec3_add_to(((u8 *)this) + 0x38, v);
            this->height += this->rootHeight;
            this->heightOffset = this->defaultHeightOffset + (this->height - *(f32 *)((s8 *)((u8 *)this) + 0x3C));
            break;
        case 2:
            vec3_add_to(((u8 *)this) + 0x38, v);
            this->rootHeight += lbl_805D7FE4;
            this->height += this->rootHeight;
            this->heightOffset = this->defaultHeightOffset + (this->height - *(f32 *)((s8 *)((u8 *)this) + 0x3C));
            break;
        case 3:
            PLAY_80023450(this);
            this->rootHeight += lbl_805D7FE4;
            this->height += this->rootHeight;
            if (this->m_c0 >= lbl_805D7FD0) {
                v->x *= lbl_805D7FE8;
                v->z *= lbl_805D7FE8;
            }
            vec3_add_to(((u8 *)this) + 0x38, v);
            *(s32 *)((s8 *)((u8 *)this) + 0x5C) = approach_angle_limited(*(s32 *)((s8 *)((u8 *)this) + 0x5C), 0, 0x80);
            this->heightOffset = this->height - *(f32 *)((s8 *)((u8 *)this) + 0x3C);
            break;
        case 4:
            PLAY_80023450(this);
            if (this->m_b8 == 0x10) {
                this->play_nearby_se();
            }
            this->rootHeight += *(f32 *)((s8 *)((u8 *)this) + 0x884);
            this->height += this->rootHeight;
            this->heightOffset = this->defaultHeightOffset + (this->height - *(f32 *)((s8 *)((u8 *)this) + 0x3C));
            v->x *= lbl_805D7FE8;
            v->z *= lbl_805D7FE8;
            vec3_add_to(((u8 *)this) + 0x38, v);
            break;
        case 5:
            PLAY_80023450(this);
            this->play_nearby_se();
            (this->impactAge)++;
            if (this->impactAge >= 50) {
                this->stateStep = 6;
            }
            break;
        }
        break;
    case 5:
        *(s32 *)((s8 *)((u8 *)this) + 0x5C) = 0;
        break;
    }
}

#pragma pop

#pragma push
#pragma fp_contract on
void TBoss1Dragon__sub_80023A2C(TBoss1Dragon *arg0, u32 arg1) {
    f32 temp_f1;
    s32 temp_r30;
    s32 temp_r30_2;

    switch (arg1) {
    case 4:
        ((TBoss1Dragon *)(arg0))->vfunc_96();
        arg0->setPhase2();
        TBoss1Dragon__sub_80028AFC((u8 *)arg0);
        arg0->flags = (s32) (arg0->flags | 0xC00);
        arg0->flags = (s32) (arg0->flags & 0xFFFFFC7F);
        ((TBoss1Dragon *)(arg0))->vfunc_91();
        ((TBoss1Dragon *)(arg0))->vfunc_94();
        fill_value_array((int) (*(s32 *)((s8 *)arg0 + 0x688)));
        arg0->stateStep = 0;
        arg0->impactAge = 0;
        arg0->rootHeight = calc_burrow_speed__12TBoss1DragonFPv(arg0);
        arg0->fallVelocity = (f32) (lbl_805D7FEC * arg0->rootHeight);
        *(f32 *)((s8 *)arg0 + 0x884) = (f32) TBoss1Dragon__data_805D7FF0;
        *(s32 *)((s8 *)arg0 + 0x874) = 0;
        return;
    case 2:
    case 11:
        request_state_change__12TBoss1DragonFPvs(arg0, 0x1B);
        return;
    case 9:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x8B8) != 0) {
            next_sequence_action__12TBoss1DragonFv(arg0);
            *(s32 *)((s8 *)arg0 + 0x8B8) = 0;
            return;
        }
        if ((s32) arg0->stateStep == 2) {
            next_sequence_action__12TBoss1DragonFv(arg0);
        }
    default:
        return;
    case 6:
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) (TBoss1Dragon__data_805D7FF0 * sin_table_lookup(temp_r30 = (s32) (TBoss1Dragon__data_805D7F94 * calc_boss4_scale__10TObjPlayerFi())));
        *(f32 *)((s8 *)arg0 + 0x40) = (f32) (TBoss1Dragon__data_805D7FF0 * cos_table_lookup(temp_r30));
        saveCurrentDestination__12TBoss1DragonFv(arg0);
        return;
    case 0:
        switch (arg0->stateStep) {
        case 2:
            break;
        case 0:
            arg0->impactAge = (arg0->impactAge + 1);
            if ((f32) arg0->impactAge >= TBoss1Dragon__data_805D7F84) {
                arg0->impactAge = 0;
                arg0->stateStep = 1;
                ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->set_field_3c();
                restorePosition__12TBoss1DragonFv(arg0);
                *(s32 *)((s8 *)arg0 + 0x874) = (s32) (boss1_dragon_angle_units_per_radian * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x38)), (f32) (*(f32 *)((s8 *)arg0 + 0x40))));
                return;
            }
            break;
        case 1:
            temp_r30_2 = (s32) (boss1_dragon_angle_units_per_radian * (arg0->fallVelocity / *(f32 *)((s8 *)arg0 + 0x884)));
            *(s32 *)((s8 *)arg0 + 0x874) += temp_r30_2;
            *(f32 *)((s8 *)arg0 + 0x38) = *(f32 *)((s8 *)arg0 + 0x884) * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x874));
            *(f32 *)((s8 *)arg0 + 0x40) = *(f32 *)((s8 *)arg0 + 0x884) * cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x874));
            *(f32 *)((s8 *)arg0 + 0x884) -= lbl_805D7FF4 * (f32) temp_r30_2;
            if (*(f32 *)((s8 *)arg0 + 0x884) < TBoss1Dragon__data_805D7FF8) {
                arg0->stateStep = 2;
            }
            TBoss1Dragon__sub_800277D8((u8 *)arg0);
            arg0->impactAge = (arg0->impactAge + 1);
            if ((s32) arg0->impactAge > 0xA) {
                clear_work__12TBoss1DragonFi((s32)arg0);
                arg0->impactAge = 0;
            }
            spawn_trap__12TBoss1DragonFii((s32)arg0, 0x40038F11);
            return;
        }
        break;
    case 5:
        ((TBoss1Dragon *)(arg0))->vfunc_92();
        ((TBoss1Dragon *)(arg0))->vfunc_93();
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->spawn_child_object();
        break;
    }
}
#pragma pop
#undef TBoss1Dragon__sub_800277D8
#undef clear_work__12TBoss1DragonFi
#undef calc_burrow_speed__12TBoss1DragonFPv
#undef spawn_trap__12TBoss1DragonFii

#define VecCopy__FP3VecPC3Vec ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)
#define TBoss1Dragon__sub_800277D8 ((void (*)(u8 *))TBoss1Dragon__sub_800277D8)
#define clear_work__12TBoss1DragonFi ((void (*)(s32))clear_work__12TBoss1DragonFi)
#define calc_burrow_speed__12TBoss1DragonFPv ((f32 (*)(void *))calc_burrow_speed__12TBoss1DragonFPv)
#define spawn_trap__12TBoss1DragonFii ((void (*)(s32, s32))spawn_trap__12TBoss1DragonFii)
#define sin_table_lookup ((f32 (*)(int))sin_table_lookup)
#define cos_table_lookup ((f32 (*)(int))cos_table_lookup)

#pragma push
#pragma fp_contract on
void TBoss1Dragon::update_burrow_outward_run(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    u8 sp8[0xC];
    switch (arg1) {
    case 4:
        this->vfunc_96();
        ((TBoss1Dragon *)arg0)->setPhase2();
        TBoss1Dragon__sub_80028AFC(arg0);
        this->flags |= 0xC00;
        this->flags &= ~0x380;
        this->vfunc_91();
        this->vfunc_94();
        this->stateStep = 0;
        this->impactAge = 0;
        this->rootHeight = calc_burrow_speed__12TBoss1DragonFPv(arg0);
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->set_field_1c();
        if (isV2Mode__12TBoss1DragonFv() == 1 && *(s32 *)((s8 *)arg0 + 0x6DC) == 2) {
            *(s32 *)((s8 *)arg0 + 0x6DC) += 1;
            this->rootHeight = calc_burrow_speed__12TBoss1DragonFPv(arg0);
            *(s32 *)((s8 *)arg0 + 0x6DC) -= 1;
        }
        break;
    case 2:
    case 11:
        request_state_change__12TBoss1DragonFPvs(arg0, 0x1B);
        break;
    case 9:
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(sp8, (u8 *)&this->position);
        if (((f32 (*)(void *))clamp_velocity__15TObjBoss2TunnelFv)(sp8) > TBoss1Dragon__data_805D7FF0) {
            next_sequence_action__12TBoss1DragonFv(arg0);
        }
        break;
    case 7:
        restoreTargetPosition__12TBoss1DragonFv();
        break;
    case 6:
        if (select_forward_target__12TBoss1DragonFPv(arg0) != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            update_velocity__9TObjEneDDFv(arg0);
        } else {
            *(f32 *)((s8 *)arg0 + 0x3A0) = sin_table_lookup(this->rotation_y);
            *(f32 *)((s8 *)arg0 + 0x3A8) = cos_table_lookup(this->rotation_y);
        }
        this->targetX = TBoss1Dragon__data_805D7FF0 * *(f32 *)((s8 *)arg0 + 0x3A0);
        this->targetY = TBoss1Dragon__data_805D7F28;
        this->targetZ = TBoss1Dragon__data_805D7FF0 * *(f32 *)((s8 *)arg0 + 0x3A8);
        ((TBoss1Dragon *)arg0)->saveTargetDestination();
        break;
    case 0:
        update_velocity__9TObjEneDDFv(arg0);
        this->rotation_y = approach_angle_limited(this->rotation_y, (s32) (boss1_dragon_angle_units_per_radian * atan2_float(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8))), 0x600);
        this->position.x += this->rootHeight * sin_table_lookup(this->rotation_y);
        this->position.z += this->rootHeight * cos_table_lookup(this->rotation_y);
        TBoss1Dragon__sub_800277D8(arg0);
        this->impactAge += 1;
        if (this->impactAge > 10) {
            clear_work__12TBoss1DragonFi((s32)arg0);
            this->impactAge = 0;
        }
        spawn_trap__12TBoss1DragonFii((s32)arg0, 0x40038F11);
        break;
    case 5:
        this->vfunc_92();
        this->vfunc_93();
        ((TBoss8Dragon *)(*(s32 *)((s8 *)arg0 + 0x6D8)))->spawn_child_object();
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss1Dragon::update_burrow_inward_run(u32 arg1, s32 arg2) {
    s32 temp_r30;
    struct { f32 x, y, z; } v;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f2;

    switch (arg1) {
    case 4:
        this->vfunc_96();
        this->setPhase2();
        TBoss1Dragon__sub_80028AFC(((u8 *)this));
        this->flags = (s32) (this->flags | 0xC00);
        this->flags = (s32) (this->flags & 0xFFFFFC7F);
        this->vfunc_91();
        this->vfunc_94();
        if (arg2 == 0x10) {
            *(s32 *)((s8 *)((u8 *)this) + 0x6DC) = 0;
        } else {
            *(s32 *)((s8 *)((u8 *)this) + 0x6DC) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x6DC) + 1);
        }
        fill_value_array((int) (*(s32 *)((s8 *)((u8 *)this) + 0x688)));
        this->stateStep = 0;
        this->impactAge = 0;
        this->fallVelocity = (f32) TBoss1Dragon__data_805D7F28;
        this->rootHeight = calc_burrow_speed__12TBoss1DragonFPv((void *)this);
        return;
    case 2:
    case 11:
        request_state_change__12TBoss1DragonFPvs((void *)this, 0x1B);
        return;
    case 9:
        if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x8B8) != 0) {
            next_sequence_action__12TBoss1DragonFv((void *)this);
            *(s32 *)((s8 *)((u8 *)this) + 0x8B8) = 0;
            return;
        }
        if ((s32) this->stateStep == 1) {
            VecCopy__FP3VecPC3Vec(&v, (void *) ((u8 *)this + 0x38));
            v.y = TBoss1Dragon__data_805D7F28;
            if (((f32 (*)(void *))clamp_velocity__15TObjBoss2TunnelFv)(&v) < lbl_805D7FFC) {
                next_sequence_action__12TBoss1DragonFv((void *)this);
            }
        }
    default:
        return;
    case 6:
        *(f32 *)((s8 *)((u8 *)this) + 0x38) = (f32) (TBoss1Dragon__data_805D7FF0 * sin_table_lookup(temp_r30 = (s32) (TBoss1Dragon__data_805D7F94 * calc_boss4_scale__10TObjPlayerFi())));
        *(f32 *)((s8 *)((u8 *)this) + 0x40) = (f32) (TBoss1Dragon__data_805D7FF0 * cos_table_lookup(temp_r30));
        saveCurrentDestination__12TBoss1DragonFv((void *)this);
        return;
    case 0:
        switch (this->stateStep) {
        case 0:
            this->impactAge = (this->impactAge + 1);
            if ((f32) this->impactAge >= TBoss1Dragon__data_805D7F84) {
                this->impactAge = 0;
                this->stateStep = 1;
                ((TBoss8Dragon *)(*(s32 *)((s8 *)((u8 *)this) + 0x6D8)))->set_field_1c();
                restorePosition__12TBoss1DragonFv((void *)this);
                this->rotation_y = (s32) ((s32) (boss1_dragon_angle_units_per_radian * atan2_float((f32) (*(f32 *)((s8 *)((u8 *)this) + 0x38)), (f32) (*(f32 *)((s8 *)((u8 *)this) + 0x40)))) + 0x8000);
                *(f32 *)((s8 *)((u8 *)this) + 0x3A0) = sin_table_lookup(this->rotation_y);
                *(f32 *)((s8 *)((u8 *)this) + 0x3A8) = cos_table_lookup(this->rotation_y);
            }
            break;
        case 1:
            this->fallVelocity = (f32) (this->fallVelocity + TBoss1Dragon__data_805D7F90);
            if (this->fallVelocity > this->rootHeight) {
                this->fallVelocity = this->rootHeight;
            }
            *(f32 *)((s8 *)((u8 *)this) + 0x38) = (f32) ((*(f32 *)((s8 *)((u8 *)this) + 0x3A0) * this->fallVelocity) + *(f32 *)((s8 *)((u8 *)this) + 0x38));
            *(f32 *)((s8 *)((u8 *)this) + 0x40) = (f32) ((*(f32 *)((s8 *)((u8 *)this) + 0x3A8) * this->fallVelocity) + *(f32 *)((s8 *)((u8 *)this) + 0x40));
            TBoss1Dragon__sub_800277D8(((u8 *)this));
            this->impactAge = (this->impactAge + 1);
            if ((s32) this->impactAge > 0xA) {
                clear_work__12TBoss1DragonFi((s32)this);
                this->impactAge = 0;
            }
            break;
        }
        spawn_trap__12TBoss1DragonFii((s32)this, 0x40038F11);
        return;
    case 5:
        this->vfunc_92();
        this->vfunc_93();
        break;
    }
}
#pragma pop
#undef VecCopy__FP3VecPC3Vec
#undef TBoss1Dragon__sub_800277D8
#undef clear_work__12TBoss1DragonFi
#undef calc_burrow_speed__12TBoss1DragonFPv
#undef spawn_trap__12TBoss1DragonFii
#undef sin_table_lookup
#undef cos_table_lookup

#define F(T, o) (*(T *)(arg0 + (o)))
#pragma push
#pragma fp_contract on
void update_dive_state__12TBoss1DragonFv(u8 *arg0, u32 arg1) {
    extern u8 TBoss1Dragon__data_80434E80[0xC];
    Vec_80024314 pos;
    Vec_80024314 vel;
    void *u;
    s32 r;
    s32 a;
    f32 k;
    f32 t;
    f32 q;
    f32 c;
    f32 sn;
    f32 cs;
    f32 s;
    u8 *mem;

    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 0x10;
        ((TBoss1Dragon *)(arg0))->vfunc_96();
        ((TBoss1Dragon *)arg0)->setActive();
        TBoss1Dragon__sub_80028B28(arg0);
        F(s32, 0x3C0) &= ~0xE80;
        F(s32, 0x864) = 0;
        F(f32, 0x888) = TBoss1Dragon__data_805D7F28;
        F(s32, 0x8A8) = 0;
        F(s32, 0x878) = 0;
        F(s32, 0x874) = boss1_dragon_angle_units_per_radian * atan2_float(F(f32, 0x3A0), F(f32, 0x3A8));
        F(f32, 0x3AC) = F(f32, 0x3AC) + TBoss1Dragon__data_805D7FF8;
        init_air_turn__12TBoss1DragonFv(arg0, F(s32, 0x874));
        k = -(13.0f / lbl_805D4AF8);
        t = newton_sqrtf((2.0f + (F(f32, 0x5DC) - 169.0f / (2.0f * lbl_805D4AF8))) / -boss1_dragon_gravity);
        if (F(f32, 0x3AC) < 50.0f) {
            t = F(f32, 0x3AC) / (k + t);
            F(f32, 0x884) = t;
            F(f32, 0x880) = t;
            F(f32, 0x88C) = TBoss1Dragon__data_805D7F28;
        } else {
            q = 50.0f / t;
            F(f32, 0x884) = q;
            c = (2.0f * (q * k - (F(f32, 0x3AC) - 50.0f))) / k;
            F(f32, 0x88C) = c / k;
            F(f32, 0x880) = q - c;
        }
        F(f32, 0x888) = TBoss1Dragon__data_805D8000;
        break;
    case 2:
        if (F(s32, 0x864) == 4) {
            request_state_change__12TBoss1DragonFPvs(u, 0x1B);
        }
        break;
    case 11:
        if (F(s32, 0x864) == 4) {
            request_state_change__12TBoss1DragonFPvs(u, 0x24);
        }
        break;
    case 9:
        if (F(s32, 0x864) == 4) {
            next_sequence_action__12TBoss1DragonFv(u);
        }
        break;
    case 7:
        restoreTargetPosition__12TBoss1DragonFv();
        if (enable_v2_features != 0) {
            update_velocity__9TObjEneDDFv(arg0);
        }
        break;
    case 6:
        if (choose_burrow_ring_destination__12TBoss1DragonFPvPv((Dragon_80028EA8 *)u, (Vec_80028EA8 *)(arg0 + 0x394)) == 0) {
            F(f32, 0x394) = TBoss1Dragon__data_805D7F28;
            F(f32, 0x398) = TBoss1Dragon__data_805D7F28;
            F(f32, 0x39C) = TBoss1Dragon__data_805D7F28;
        }
        update_velocity__9TObjEneDDFv(arg0);
        ((TBoss1Dragon *)arg0)->saveTargetDestination();
        break;
    case 0:
        advance_animation_playback();
        switch (F(s32, 0x864)) {
        case 0:
            ((TBoss1Dragon *)arg0)->play_nearby_se();
            TBoss1Dragon__sub_800274A4((s32)arg0);
            if (((TBoss1Dragon *)arg0)->advance_air_turn() != 0) {
                F(s32, 0x658) = 0;
                F(s32, 0x60) = F(s32, 0x874);
                F(s32, 0x864) = 1;
                F(s16, 0xB8) = 0x16;
            }
            break;
        case 1:
            if (F(f32, 0xC0) >= TBoss1Dragon__data_805D8008) {
                F(s32, 0x864) = 2;
                F(s32, 0x3C0) |= 0xC00;
                play_se_at_pos__12TBoss1DragonFii((s32)arg0, 0x4003B210);
            }
            break;
        case 2:
            if (F(f32, 0x888) > TBoss1Dragon__data_805D7F28) {
                F(f32, 0x888) = F(f32, 0x888) + lbl_805D4AF8;
                F(f32, 0x880) = F(f32, 0x880) + F(f32, 0x88C);
                ((TObjEneDD *)arg0)->move_with_wall_stop(F(f32, 0x3A0), F(f32, 0x3A8), F(f32, 0x880));
            } else {
                F(f32, 0x888) = F(f32, 0x888) + boss1_dragon_gravity;
                ((TObjEneDD *)arg0)->move_with_wall_stop(F(f32, 0x3A0), F(f32, 0x3A8), F(f32, 0x884));
            }
            F(f32, 0x5DC) = F(f32, 0x5DC) + F(f32, 0x888);
            F(f32, 0x5D8) = F(f32, 0x3C) + F(f32, 0x5DC);
            if (F(f32, 0x888) < TBoss1Dragon__data_805D7F28) {
                a = -(s32)(boss1_dragon_angle_units_per_radian * atan2_float(F(f32, 0x888), F(f32, 0x880)));
                if (a > F(s32, 0x5C)) {
                    F(s32, 0x5C) = a;
                }
                if (F(s32, 0x878) < 0x2800) {
                    F(s32, 0x878) += 0x120;
                }
                F(s32, 0x64) += F(s32, 0x878);
            } else {
                F(s32, 0x5C) = approach_angle_limited(F(s32, 0x5C), 0x4000, 0x200);
            }
            if (F(f32, 0x410) <= *(f32 *)(TBoss1Dragon__data_80434E80 + 4) - lbl_805D7FFC) {
                F(s32, 0x864) = 3;
                play_se_at_pos__12TBoss1DragonFii((s32)arg0, 0x4003AD0F);
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                F(s16, 0xB8) = 0x17;
            }
            break;
        case 3:
            if (F(f32, 0x5DC) - F(f32, 0x5E0) <= lbl_805D800C) {
                F(s32, 0x864) = 4;
                F(s32, 0x3C0) &= ~0x100;
            }
            if (F(f32, 0x5DC) - F(f32, 0x5E0) <= TBoss1Dragon__data_805D7F28 && F(s32, 0x8A8) == 0) {
                ((TBoss1Dragon *)arg0)->spawn_impact_crater((s32)(arg0 + 0x38));
                ((TBoss1Dragon *)arg0)->apply_ground_impact_attack();
                F(s32, 0x8A8) = 1;
                ((TBoss1Dragon *)(arg0))->vfunc_91();
                ((TBoss1Dragon *)(arg0))->vfunc_94();
                ((TBoss1Dragon *)arg0)->setPhase2();
            }
            r = get_random_scaled__9TObjEneDDFv(arg0);
            sn = sin_table_lookup(r);
            cs = cos_table_lookup(r);
            pos.x = TBoss1Dragon__data_805D7F1C * sn + F(f32, 0x394);
            pos.y = F(f32, 0x398);
            pos.z = TBoss1Dragon__data_805D7F1C * cs + F(f32, 0x39C);
            s = rand_range__9TObjEneDDFff(arg0, TBoss1Dragon__data_805D7F24, TBoss1Dragon__data_805D7F48);
            vel.x = sn * s;
            vel.y = rand_range__9TObjEneDDFff(arg0, TBoss1Dragon__data_805D8010, TBoss1Dragon__data_805D7F98);
            vel.z = cs * s;
            mem = (u8 *)new TObjBoss1Rock((TObject *)(void *)tl_05, (void *)(void *)&pos, (void *)(void *)&vel);
            F(f32, 0x5DC) = F(f32, 0x5DC) + F(f32, 0x888);
            ((TObjEneDD *)arg0)->move_with_wall_stop(F(f32, 0x3A0), F(f32, 0x3A8), F(f32, 0x884));
            F(f32, 0x5D8) = F(f32, 0x3C) + F(f32, 0x5DC);
            if (F(s32, 0x878) < 0x2800) {
                F(s32, 0x878) += 0x80;
            }
            F(s32, 0x64) += F(s32, 0x878);
            break;
        case 4:
            break;
        }
        break;
    case 5:
        F(s32, 0x5C) = 0;
        F(s32, 0x64) = 0;
        break;
    }
}
#pragma pop
#undef F

#define TBoss1Dragon__sub_800274A4 ((s32 (*)(void *))TBoss1Dragon__sub_800274A4)
#define saveCurrentDestination__12TBoss1DragonFv ((void (*)(void *))saveCurrentDestination__12TBoss1DragonFv)
#define restorePosition__12TBoss1DragonFv ((void (*)(void *))restorePosition__12TBoss1DragonFv)
#define TBoss1Dragon__sub_80028B28 ((s32 (*)(void *))TBoss1Dragon__sub_80028B28)
void TBoss1Dragon::update_roar_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    s32 temp_r4_2;

    switch (arg1) {
    case 4:
        this->m_b8 = 0x10;
        this->vfunc_96();
        ((TBoss1Dragon *)arg0)->setActive();
        TBoss1Dragon__sub_80028B28(arg0);
        this->flags = (s32) (this->flags | 0xC00);
        temp_r4 = this->flags;
        this->flags = (s32) (temp_r4 & ~0x280);
        play_cue_stream_file(lbl_80435388, temp_r4);
        this->vfunc_91();
        this->stateStep = 0;
        return;
    case 9:
        if ((s32) this->stateStep >= 0x3C) {
            next_sequence_action__12TBoss1DragonFv(arg0);
            return;
        }
        break;
    case 11:
        break;
    case 7:
        restorePosition__12TBoss1DragonFv(arg0);
        return;
    case 6:
        saveCurrentDestination__12TBoss1DragonFv(arg0);
        return;
    case 0:
        advance_animation_playback();
        this->stateStep = this->stateStep + 1;
        play_nearby_se();
        TBoss1Dragon__sub_800274A4(arg0);
        return;
    case 5:
        this->vfunc_92();
        break;
    }
}
#undef TBoss1Dragon__sub_800274A4
#undef saveCurrentDestination__12TBoss1DragonFv
#undef restorePosition__12TBoss1DragonFv
#undef TBoss1Dragon__sub_80028B28

#define saveCurrentDestination__12TBoss1DragonFv ((void (*)(void *))saveCurrentDestination__12TBoss1DragonFv)
#define restorePosition__12TBoss1DragonFv ((void (*)(void *))restorePosition__12TBoss1DragonFv)
#define play_cue_stream_file ((s32 (*)(void *))play_cue_stream_file)
void TBoss1Dragon::update_stretch_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;

    switch (arg1) {
    case 4:
        this->m_b8 = 2;
        this->vfunc_95();
        clearState__12TBoss1DragonFv(arg0);
        beginHeightTransition__12TBoss1DragonFv(arg0);
        this->flags = (s32) (this->flags | 0xC00);
        temp_r4 = this->flags;
        this->flags = (s32) (temp_r4 & ~0x280);
        ((VObj_18_5b68e0 *)(arg0))->m89(temp_r4);
        return;
    case 2:
    case 11:
        if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x17);
            return;
        }
        break;
    case 9:
        if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
            next_sequence_action__12TBoss1DragonFv(arg0);
            return;
        }
        break;
    case 7:
        restorePosition__12TBoss1DragonFv(arg0);
        return;
    case 6:
        saveCurrentDestination__12TBoss1DragonFv(arg0);
        return;
    case 0:
        advance_animation_playback();
        if (objInBand((GameObj *)(arg0), TBoss1Dragon__data_805D7F1C) != 0) {
            play_cue_stream_file(lbl_80435388);
            return;
        }
        break;
    case 5:
        this->vfunc_92();
        break;
    }
}
#undef saveCurrentDestination__12TBoss1DragonFv
#undef restorePosition__12TBoss1DragonFv
#undef play_cue_stream_file

#define filter_input_flags__12TBoss1DragonFiii ((s32 (*)(s32, s32, s32))filter_input_flags__12TBoss1DragonFiii)
#define TBoss1Dragon__sub_80027010 ((f32 (*)(void *, f32, f32, f32))TBoss1Dragon__sub_80027010)
#define saveCurrentDestination__12TBoss1DragonFv ((s32 (*)(void))saveCurrentDestination__12TBoss1DragonFv)
#define restorePosition__12TBoss1DragonFv ((s32 (*)(void))restorePosition__12TBoss1DragonFv)
#define spawn_trap__12TBoss1DragonFii ((void (*)(s32, s32))spawn_trap__12TBoss1DragonFii)
#define play_se_at_pos__12TBoss1DragonFii ((void (*)(s32, s32))play_se_at_pos__12TBoss1DragonFii)
#define sin_table_lookup ((f32 (*)(int))sin_table_lookup)
#define cos_table_lookup ((f32 (*)(int))cos_table_lookup)
void TBoss1Dragon::update_head_down_attack_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    f32 var_f31;
    f32 temp_f30;
    f32 temp_f29;
    f32 temp_f1;

    switch (arg1) {
    case 4:
        this->m_b8 = 8;
        this->vfunc_96();
        clearState__12TBoss1DragonFv(arg0);
        beginHeightTransition__12TBoss1DragonFv(arg0);
        this->flags = (s32) (this->flags | 0x680);
        this->flags = (this->flags & 0xFFFFF7FF);
        this->stateStep = 0;
        this->impactAge = 0;
        play_se_at_pos__12TBoss1DragonFii((s32)arg0, 0x4003AD06);
        return;
    case 11:
        if (((s32) this->stateStep >= 0x96) && (filter_input_flags__12TBoss1DragonFiii((s32)arg0, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8), 2) != 0)) {
            this->stateStep = 0x1C2;
        }
        if (((s32) this->impactAge == 2) && (((TObjEneDD *)arg0)->get_flag_b4() != 0)) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x17);
        }
    default:
        return;
    case 2:
        if (((s32) this->impactAge == 2) && (((TObjEneDD *)arg0)->get_flag_b4() != 0)) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x17);
            return;
        }
        break;
    case 9:
        if (((s32) this->impactAge == 2) && (((TObjEneDD *)arg0)->get_flag_b4() != 0)) {
            ((TBoss1Dragon *)arg0)->remap_sequence_after_recovery();
            return;
        }
        break;
    case 7:
        restorePosition__12TBoss1DragonFv();
        return;
    case 6:
        saveCurrentDestination__12TBoss1DragonFv();
        return;
    case 0:
        advance_animation_playback();
        switch (this->impactAge) {
        case 0:
            if (objInBand((GameObj *)(arg0), lbl_805D8014) != 0) {
                apply_head_fall_attack();
            } else if (objInBand((GameObj *)(arg0), TBoss1Dragon__data_805D8018) != 0) {
                ((void (*)(void *))update_from_data__12TBoss1DragonFv)(arg0);
            } else if (objInBand((GameObj *)(arg0), TBoss1Dragon__data_805D8008) != 0) {
                ((void (*)(void *))sweep_head_fall_spheres_late__12TBoss1DragonFv)(arg0);
            }
            if ((s16) this->m_b8 != 8) {
                enable_dragon_blocking_bodies((int) (*(s32 *)((s8 *)arg0 + 0x68C)), (u8 *)&this->position, this->rotation_y);
                this->impactAge = 1;
                return;
            }
            break;
        case 1:
            spawn_trap__12TBoss1DragonFii((s32)arg0, 0x4003AD12);
            this->stateStep = (this->stateStep + 1);
            if ((s32) this->stateStep >= 0x1C2) {
                this->m_b8 = 0xA;
                this->impactAge = 2;
                disable_dragon_blocking_bodies((int) (*(s32 *)((s8 *)arg0 + 0x68C)));
                return;
            }
            break;
        case 2:
            var_f31 = lbl_805D801C;
            temp_f30 = sin_table_lookup(this->rotation_y);
            temp_f29 = cos_table_lookup(this->rotation_y);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x760) != 0) {
                var_f31 = TBoss1Dragon__sub_80027010(arg0, temp_f30, temp_f29, lbl_805D801C);
            }
            temp_f1 = this->m_c0;
            if ((temp_f1 >= TBoss1Dragon__data_805D8000) && (temp_f1 <= TBoss1Dragon__data_805D7F1C)) {
                ((TObjEneDD *)arg0)->move_to_shot_position(temp_f30, temp_f29, var_f31);
                return;
            }
            break;
        }
        break;
    case 5:
        update_damage_threshold__12TBoss1DragonFv();
        disable_dragon_blocking_bodies((int) (*(s32 *)((s8 *)arg0 + 0x68C)));
        break;
    }
}
#undef filter_input_flags__12TBoss1DragonFiii
#undef TBoss1Dragon__sub_80027010
#undef saveCurrentDestination__12TBoss1DragonFv
#undef restorePosition__12TBoss1DragonFv
#undef spawn_trap__12TBoss1DragonFii
#undef play_se_at_pos__12TBoss1DragonFii
#undef sin_table_lookup
#undef cos_table_lookup

#define VecCopy__FP3VecPC3Vec ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)
#define advance_animation_playback ((s32 (*)(void *))advance_animation_playback)
#pragma push
#pragma fp_contract on
void TBoss1Dragon::update_air_fire_state(u32 arg1) {
    extern u8 TBoss1Dragon__data_80434E80[0xC];
    Vec_80025710 *tgt;
    f32 dist;
    Vec_80025710 dest;
    Vec_80025710 d;
    Vec_80025710 out;
    u8 *obj;
    u8 *arg0 = (u8 *)this;

    tgt = (Vec_80025710 *)(arg0 + 0x890);
    switch (arg1) {
    case 4:
        this->m_b8 = 0x10;
        ((TBoss1Dragon *)(arg0))->vfunc_96();
        ((TBoss1Dragon *)arg0)->setActive();
        TBoss1Dragon__sub_80028B28(arg0);
        this->flags &= ~0xE80;
        this->stateStep = 0;
        this->impactAge = 0;
        *(s32 *)((s8 *)arg0 + 0x86C) = 0;
        *(u32 *)((s8 *)arg0 + 0x8AC) = 0;
        break;
    case 2:
    case 11:
        if (this->stateStep == 3) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x19);
        }
        break;
    case 9:
        if (this->stateStep == 4) {
            next_sequence_action__12TBoss1DragonFv(arg0);
        }
        break;
    case 0:
        advance_animation_playback(arg0);
        switch (this->stateStep) {
        case 0:
            if (((TBoss1Dragon *)arg0)->select_air_fire_target(tgt) != 0) {
                *(s32 *)((s8 *)arg0 + 0x874) = (s32)(boss1_dragon_angle_units_per_radian * atan2_float(tgt->x - *(f32 *)((s8 *)arg0 + 0x38), tgt->z - *(f32 *)((s8 *)arg0 + 0x40)));
            } else {
                *(s32 *)((s8 *)arg0 + 0x874) = get_random_scaled__9TObjEneDDFv(arg0);
                tgt->x = lbl_805D8044 * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x874));
                tgt->y = TBoss1Dragon__data_805D7F28;
                tgt->z = lbl_805D8044 * cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x874));
            }
            *(s32 *)((s8 *)arg0 + 0x874) = (s16)*(s32 *)((s8 *)arg0 + 0x874);
            this->stateStep = 1;
            if (*(s32 *)((s8 *)arg0 + 0x760) != 0) {
                *(s32 *)((s8 *)arg0 + 0x874) = (s16)this->rotation_y;
                VecCopy__FP3VecPC3Vec(tgt, (u8 *)&this->position);
                tgt->x = lbl_805D8044 * sin_table_lookup(*(s32 *)((s8 *)arg0 + 0x874)) + tgt->x;
                tgt->y = TBoss1Dragon__data_805D7F28;
                tgt->z = lbl_805D8044 * cos_table_lookup(*(s32 *)((s8 *)arg0 + 0x874)) + tgt->z;
                this->stateStep = 2;
                *(s32 *)((s8 *)arg0 + 0x658) = 0;
                this->rotation_y = *(s32 *)((s8 *)arg0 + 0x874);
                this->m_b8 = 0x12;
                this->flags |= 0xC00;
            }
            ((TBoss1Dragon *)arg0)->set_result_flag(this->rotation_y, *(s32 *)((s8 *)arg0 + 0x874));
            init_air_turn__12TBoss1DragonFv(arg0, *(s32 *)((s8 *)arg0 + 0x874));
        case 1:
            ((TBoss1Dragon *)arg0)->play_nearby_se();
            TBoss1Dragon__sub_800274A4((s32)arg0);
            if (((TBoss1Dragon *)arg0)->advance_air_turn() != 0) {
                *(s32 *)((s8 *)arg0 + 0x658) = 0;
                this->rotation_y = *(s32 *)((s8 *)arg0 + 0x874);
                this->stateStep = 2;
                this->m_b8 = 0x12;
                this->flags |= 0xC00;
            }
            break;
        case 2:
            if (objInBand((GameObj *)arg0, (f32)TBoss1Dragon__data_805D7F24) != 0) {
                play_se_at_pos__12TBoss1DragonFii((s32)arg0, 0x4003A804);
            }
            if (objInBand((GameObj *)arg0, (f32)lbl_805D8048) != 0) {
                play_se_at_pos__12TBoss1DragonFii((s32)arg0, 0x4003AD0A);
            }
            if (objInBand((GameObj *)arg0, (f32)TBoss1Dragon__data_805D8018) != 0 || objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805D804C)) != 0) {
                ((TBoss1Dragon *)arg0)->update_switch_attack();
            }
            if (*(void **)((s8 *)arg0 + 0x8AC) == NULL) {
                if (this->m_c0 >= TBoss1Dragon__data_805D7F1C) {
                    *(u32 *)((s8 *)arg0 + 0x8AC) = (u32)spawn_continuous_particle_effect_with_flags(arg0 + 0x40C, *(s32 *)((s8 *)this->effectResource + 0x18), 0x40);
                }
            } else if (this->m_c0 <= TBoss1Dragon__data_805D7F68) {
                ((TNowLoading *)(*(void **)((s8 *)arg0 + 0x8AC)))->copy_pos(arg0 + 0x40C);
            } else {
                queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8AC));
                *(u32 *)((s8 *)arg0 + 0x8AC) = 0;
            }
            if (objInBand((GameObj *)arg0, (f32)lbl_805D8050) != 0) {
                VecCopy__FP3VecPC3Vec(&d, tgt);
                subtract_vector(&d, (u8 *)&this->position);
                dist = ((f32 (*)(void *))clamp_velocity__15TObjBoss2TunnelFv)(&d);
                d.y = TBoss1Dragon__data_805D7F28;
                VecCopy__FP3VecPC3Vec(&dest, tgt);
                dest.y = *(f32 *)((s8 *)TBoss1Dragon__data_80434E80 + 4);
                obj = __nw__7TObjectFUl(0x4C);
                if (obj != NULL) {
                    TBoss1DragonEffBullet__ct((u8 *)obj, (s32)(arg0 + 0x3C4), (s32)(arg0 + 0x40C), (s32)&dest);
                }
                rotate_vec_xz(&d, &out, 0x1000);
                VecCopy__FP3VecPC3Vec(&dest, (u8 *)&this->position);
                dest.x = out.x * dist + dest.x;
                dest.y = *(f32 *)((s8 *)TBoss1Dragon__data_80434E80 + 4);
                dest.z = out.z * dist + dest.z;
                obj = __nw__7TObjectFUl(0x4C);
                if (obj != NULL) {
                    TBoss1DragonEffBullet__ct((u8 *)obj, (s32)(arg0 + 0x3C4), (s32)(arg0 + 0x40C), (s32)&dest);
                }
                rotate_vec_xz(&d, &out, -0x1000);
                VecCopy__FP3VecPC3Vec(&dest, (u8 *)&this->position);
                dest.x = out.x * dist + dest.x;
                dest.y = *(f32 *)((s8 *)TBoss1Dragon__data_80434E80 + 4);
                dest.z = out.z * dist + dest.z;
                obj = __nw__7TObjectFUl(0x4C);
                if (obj != NULL) {
                    TBoss1DragonEffBullet__ct((u8 *)obj, (s32)(arg0 + 0x3C4), (s32)(arg0 + 0x40C), (s32)&dest);
                }
                spawn_particle_effect_with_flags(arg0 + 0x40C, *(s32 *)((s8 *)this->effectResource + 0x1C), 0x40);
                this->stateStep = 3;
                *(s32 *)((s8 *)arg0 + 0x86C) = 0;
                this->flags &= ~0xC00;
            }
            break;
        case 3:
            (*(s32 *)((s8 *)arg0 + 0x86C))++;
            if (*(s32 *)((s8 *)arg0 + 0x86C) > 0xA) {
                (this->impactAge)++;
                if (this->impactAge >= 2) {
                    this->stateStep = 4;
                } else {
                    this->stateStep = 0;
                }
            }
            break;
        }
        break;
    case 5:
        if (*(void **)((s8 *)arg0 + 0x8AC) != NULL) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8AC));
            *(u32 *)((s8 *)arg0 + 0x8AC) = 0;
        }
        break;
    }
}
#pragma pop
#undef VecCopy__FP3VecPC3Vec

#define prepare_flight_destination__12TBoss1DragonFPv ((s32 (*)(void *, void *))prepare_flight_destination__12TBoss1DragonFPv)
#pragma push
#pragma fp_contract on
void TBoss1Dragon::update_flight_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    f32 *base;
    s32 var;
    s32 old;
    f32 t;

    base = (f32 *)(arg0 + 0x890);
    switch (arg1) {
    case 4:
        this->m_b8 = 0x10;
        this->vfunc_96();
        ((TBoss1Dragon *)arg0)->setActive();
        TBoss1Dragon__sub_80028B28(arg0);
        old = this->flags;
        this->flags = old & ~0xE80;
        ((s32 (*)(void *, s32))update_velocity__9TObjEneDDFv)(arg0, old);
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            init_acceleration_curve(arg0 + 0x5F4, TBoss1Dragon__data_805D7F90, lbl_805D8054, *(f32 *)((s8 *)arg0 + 0x3AC), TBoss1Dragon__data_805D7F24);
            break;
        case 1:
            init_acceleration_curve(arg0 + 0x5F4, TBoss1Dragon__data_805D7F90, lbl_805D8054, *(f32 *)((s8 *)arg0 + 0x3AC), *(f32 *)((s8 *)(*(G_80025C68 *)&TBoss1Dragon__data_804FE17C).value + 0x14));
            break;
        }
        VecCopy__FP3VecPC3Vec((s32)base, (s32)(arg0 + 0x38));
        var = angle_diff_s16(this->rotation_y, (s32)(boss1_dragon_angle_units_per_radian * atan2_float(*(f32 *)((s8 *)arg0 + 0x3A0), *(f32 *)((s8 *)arg0 + 0x3A8))));
        if (var >= 0) {
            *(s32 *)((s8 *)arg0 + 0x65C) = 1;
        } else {
            var = -var;
            *(s32 *)((s8 *)arg0 + 0x65C) = -1;
        }
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            init_acceleration_curve(arg0 + 0x618, lbl_805D8058, lbl_805D805C, (f32)var, lbl_805D8038);
            break;
        case 1:
            init_acceleration_curve(arg0 + 0x618, lbl_805D8058, lbl_805D805C, (f32)var, (f32)(s32)(lbl_805D8060 * *(f32 *)((s8 *)(*(G_80025C68 *)&TBoss1Dragon__data_804FE17C).value + 0x14)));
            break;
        }
        *(s32 *)((s8 *)arg0 + 0x874) = this->rotation_y;
        this->stateStep = 0;
        this->fallVelocity = TBoss1Dragon__data_805D7F28;
        break;
    case 2:
        request_state_change__12TBoss1DragonFPvs(arg0, 0x19);
        break;
    case 11:
        if (this->stateStep == 2) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0xF);
        }
        break;
    case 9:
        if (this->stateStep == 2) {
            next_sequence_action__12TBoss1DragonFv(arg0);
        }
        break;
    case 7:
        restoreTargetPosition__12TBoss1DragonFv();
        break;
    case 6:
        prepare_flight_destination__12TBoss1DragonFPv(arg0, (u8 *)&this->targetX);
        ((TBoss1Dragon *)arg0)->saveTargetDestination();
        break;
    case 0:
        advance_animation_playback(arg0);
        play_nearby_se();
        TBoss1Dragon__sub_800274A4((s32)arg0);
        switch (this->stateStep) {
        case 0:
            this->fallVelocity += TBoss1Dragon__data_805D7F40;
            t = sample_acceleration_curve(arg0 + 0x618, this->fallVelocity);
            this->rotation_y = (s32)((f32)*(s32 *)((s8 *)arg0 + 0x65C) * t + (f32)*(s32 *)((s8 *)arg0 + 0x874));
            if (((TObjBoss2Tunnel *)(arg0 + 0x618))->check_param_threshold(this->fallVelocity) != 0) {
                this->fallVelocity = TBoss1Dragon__data_805D7F28;
                this->stateStep = 1;
            }
            break;
        case 1:
            this->fallVelocity += TBoss1Dragon__data_805D7F40;
            t = sample_acceleration_curve(arg0 + 0x5F4, this->fallVelocity);
            this->position.x = *(f32 *)((s8 *)arg0 + 0x3A0) * t + base[0];
            this->position.z = *(f32 *)((s8 *)arg0 + 0x3A8) * t + base[2];
            if (((TObjBoss2Tunnel *)(arg0 + 0x5F4))->check_param_threshold(this->fallVelocity) != 0) {
                this->stateStep = 2;
            }
            break;
        }
        break;
    case 5:
        VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x5E8), (s32)(arg0 + 0x3A0));
        break;
    }
}
#pragma pop
#undef prepare_flight_destination__12TBoss1DragonFPv
#undef advance_animation_playback

void TBoss1Dragon::update_lift_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    TBoss1Dragon *self = (TBoss1Dragon *)arg0;

    switch (arg1) {
    case 4:
        self->m_b8 = 0xF;
        advance_animation_playback();
        this->vfunc_96();
        self->clearState();
        self->beginHeightTransition();
        self->flags = self->flags & ~0xE80;
        self->stateStep = 0;
        self->fallVelocity = TBoss1Dragon__data_805D7F28;
        self->impactAge = 0;
        self->height = self->position.y;
        return;
    case 2:
    case 11:
        self->controlTimer = 0;
        if (self->fallVelocity < TBoss1Dragon__data_805D7F28) {
            request_state_change__12TBoss1DragonFPvs(self, 0x19);
        }
    default:
        return;
    case 9:
        if (self->fallVelocity < TBoss1Dragon__data_805D7F28) {
            next_sequence_action__12TBoss1DragonFv(self);
            return;
        }
        break;
    case 7:
        self->restorePosition();
        return;
    case 6:
        self->saveCurrentDestination();
        return;
    case 0:
        self->stateStep = self->stateStep + 1;
        switch (self->impactAge) {
        case 0:
            if ((self->m_c0 + ((TBoss1Dragon *)self)->m_c8) >= TBoss1Dragon__data_805D7F68) {
                f32 t;
                self->rootHeight = ((TBoss1Dragon *)self)->sample_root_height();
                t = lbl_805D8064 * lbl_805D4AF0;
                self->fallVelocity = newton_sqrtf(t * (TBoss1Dragon__data_805D8040 - self->rootHeight));
                self->impactAge = 1;
                self->flags = self->flags | 0xC00;
                self->setActive();
            }
            break;
        }
        ((s32 (*)(void *))advance_animation_playback)(self);
        if (objInBand((GameObj *)self, (f32)TBoss1Dragon__data_805D8018) != 0) {
            play_se_at_pos__12TBoss1DragonFii((s32)self, 0x4003A804);
        }
        if (objInBand((GameObj *)self, (f32)lbl_805D8068) != 0) {
            play_se_at_pos__12TBoss1DragonFii((s32)self, 0x4003A803);
        }
        if (objInBand((GameObj *)self, (f32)lbl_805D806C) != 0) {
            spawn_particle_effect_with_flags(&self->position.x, self->effectResource->unknown00[1], 0x40);
        }
        switch (self->impactAge) {
        case 1:
            self->heightOffset = self->defaultHeightOffset + (self->rootHeight - ((TBoss1Dragon *)self)->sample_root_height());
            self->height = self->position.y + self->rootHeight;
            self->rootHeight = self->rootHeight + self->fallVelocity;
            self->fallVelocity = self->fallVelocity + lbl_805D4AF0;
            break;
        case 0:
            break;
        }
        break;
    }
}

#define next_sequence_action__12TBoss1DragonFv ((s32 (*)(void *))next_sequence_action__12TBoss1DragonFv)
#define request_state_change__12TBoss1DragonFPvs ((s32 (*)(void *, s16))request_state_change__12TBoss1DragonFPvs)
#define beginHeightTransition__12TBoss1DragonFv ((void (*)(void *))beginHeightTransition__12TBoss1DragonFv)
#define clearState__12TBoss1DragonFv ((void (*)(void *))clearState__12TBoss1DragonFv)
#define advance_animation_playback ((s32 (*)(void))advance_animation_playback)
void TBoss1Dragon::update_tail_attack_state(u32 arg1) {
    Dragon_8002624C *self = (Dragon_8002624C *)this;
    switch (arg1) {
    case 4:
        self->fB8 = 7;
        self->m94();
        clearState__12TBoss1DragonFv(self);
        beginHeightTransition__12TBoss1DragonFv(self);
        self->f3C0 &= ~0xC80;
        self->f3C0 |= 0x200;
        self->f864 = 0;
        ((TBoss1DragonEffTail *)(self->tail))->enable();
        break;
    case 2:
    case 11:
        if (((TObjEneDD *)self)->get_flag_b4() != 0) {
            request_state_change__12TBoss1DragonFPvs(self, 0x17);
        }
        break;
    case 9:
        if (((TObjEneDD *)self)->get_flag_b4() != 0) {
            next_sequence_action__12TBoss1DragonFv(self);
        }
        break;
    case 0:
        advance_animation_playback();
        self->f864++;
        if (objInBand((GameObj *)self, (f32)TBoss1Dragon__data_805D7F28) != 0 ||
            objInBand((GameObj *)self, (f32)TBoss1Dragon__data_805D7F38) != 0) {
            play_se_at_pos__12TBoss1DragonFii((s32)self, 0x4003AD09);
        }
        if (self->f864 > 1) {
            if (objInBand((GameObj *)self, (f32)TBoss1Dragon__data_805D8010) != 0) {
                ((TBoss1DragonEffTail *)(self->tail))->disable();
            } else if (objInBand((GameObj *)self, (f32)lbl_805D8070) != 0) {
                ((TBoss1DragonEffTail *)(self->tail))->enable();
            }
            self->tail->m1();
        }
        break;
    }
}
#undef next_sequence_action__12TBoss1DragonFv
#undef request_state_change__12TBoss1DragonFPvs
#undef beginHeightTransition__12TBoss1DragonFv
#undef clearState__12TBoss1DragonFv
#undef advance_animation_playback

#define next_sequence_action__12TBoss1DragonFv ((s32 (*)(void))next_sequence_action__12TBoss1DragonFv)
#define spawn_trap__12TBoss1DragonFii ((void (*)(s32, s32))spawn_trap__12TBoss1DragonFii)
#define calc_target_vector__12TBoss1DragonFPv ((void (*)(u8 *))calc_target_vector__12TBoss1DragonFPv)
#define sin_table_lookup ((f32 (*)(int))sin_table_lookup)
#define cos_table_lookup ((f32 (*)(int))cos_table_lookup)
#pragma push
#pragma fp_contract on
#pragma push
#pragma opt_common_subs off
void TBoss1Dragon::update_breath_attack_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    s32 sp10[2];
    s32 sp8[2];

    switch (arg1) {
    case 4:
        this->m_b8 = 4;
        this->vfunc_96();
        clearState__12TBoss1DragonFv(arg0);
        beginHeightTransition__12TBoss1DragonFv(arg0);
        this->flags = (s32) (this->flags & ~0xE80);
        this->stateStep = 0;
        this->impactAge = 2;
        *(s32 *)((s8 *)arg0 + 0x86C) = 0;
        *(u32 *)((s8 *)arg0 + 0x8AC) = 0U;
        *(u32 *)((s8 *)arg0 + 0x8B0) = 0U;
        *(u32 *)((s8 *)arg0 + 0x8B4) = 0U;
        return;
    case 2:
    case 11:
        if ((s32) this->stateStep == 3) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x17);
        }
    default:
        return;
    case 9:
        if ((s32) this->stateStep == 3) {
            next_sequence_action__12TBoss1DragonFv();
            return;
        }
        break;
    case 7:
        restoreTargetPosition__12TBoss1DragonFv();
        return;
    case 6:
        if (enemy_validate_retained_target() != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
        } else {
            this->targetX = (f32) ((lbl_805D8074 * sin_table_lookup(this->rotation_y)) + *(f32 *)((s8 *)arg0 + 0x40C));
            this->targetY = (f32) this->position.y;
            this->targetZ = (f32) ((lbl_805D8074 * cos_table_lookup(this->rotation_y)) + *(f32 *)((s8 *)arg0 + 0x414));
        }
        ((TBoss1Dragon *)arg0)->saveTargetDestination();
        return;
    case 0:
        advance_animation_playback();
        switch (this->stateStep) {
        case 0:
            update_velocity__9TObjEneDDFv(arg0);
            calc_target_vector__12TBoss1DragonFPv(arg0);
            this->rotation_y = approach_angle_limited(this->rotation_y, ((s32) (boss1_dragon_angle_units_per_radian * atan2_float((f32) (*(f32 *)((s8 *)arg0 + 0x3A0)), (f32) (*(f32 *)((s8 *)arg0 + 0x3A8))))), 0xA0);
            this->rotation_y = (s32) (s16) this->rotation_y;
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                this->m_b8 = 5;
                this->stateStep = 1;
                return;
            }
            break;
        case 1:
            *(s32 *)((s8 *)arg0 + 0x86C) = (s32) (*(s32 *)((s8 *)arg0 + 0x86C) + 1);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x86C) >= 0x78) {
                this->m_b8 = 6;
                if ((u32) *(u32 *)((s8 *)arg0 + 0x8AC) != 0U) {
                    queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8AC));
                    *(u32 *)((s8 *)arg0 + 0x8AC) = 0U;
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x8B0) != 0U) {
                    queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8B0));
                    *(u32 *)((s8 *)arg0 + 0x8B0) = 0U;
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x8B4) != 0U) {
                    queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8B4));
                    *(u32 *)((s8 *)arg0 + 0x8B4) = 0U;
                }
                this->stateStep = 2;
                this->impactAge = 0;
                return;
            }
            if (!(this->animationFlags & 4)) {
                spawn_trap__12TBoss1DragonFii((s32)arg0, 0x4003AD0D);
                direction_to_rotation_xz(arg0 + 0x418, (s32 *)&sp8, (s32 *)sp10);
                this->impactAge = (this->impactAge + 1);
                if ((s32) this->impactAge >= 2) {
                    u8 *o = __nw__7TObjectFUl(0x38);
                    if (o != 0) {
                        __ct__21TBoss1DragonEffBreathFP7TObjectPvPv(o, (u8 *)&this->unknown3C4, arg0 + 0x40C, arg0 + 0x418);
                    }
                    this->impactAge = 0;
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x8AC) == 0U) {
                    *(u32 *)((s8 *)arg0 + 0x8AC) = spawn_particle_effect_with_rotation(arg0 + 0x40C, &sp8, (void *) (*(s32 *)((s8 *)this->effectResource + 0x10)), 0x40);
                    if ((u32) *(u32 *)((s8 *)arg0 + 0x8AC) != 0U) {
                        ((TParticleCtrl *)(*(void **)((s8 *)arg0 + 0x8AC)))->enable();
                    }
                } else {
                    ((TNowLoading *)(*(void **)((s8 *)arg0 + 0x8AC)))->copy_pos(arg0 + 0x424);
                    ((TBoss4Type2 *)(*(void **)((s8 *)arg0 + 0x8AC)))->copy_vec3(&sp8);
                }
                if ((u32) *(u32 *)((s8 *)arg0 + 0x8B4) == 0U) {
                    *(u32 *)((s8 *)arg0 + 0x8B4) = spawn_particle_effect_with_rotation(arg0 + 0x40C, &sp8, (void *) (*(s32 *)((s8 *)this->effectResource + 0x14)), 0x40);
                    if ((u32) *(u32 *)((s8 *)arg0 + 0x8B4) != 0U) {
                        ((TParticleCtrl *)(*(void **)((s8 *)arg0 + 0x8B4)))->enable();
                        return;
                    }
                } else {
                    ((TNowLoading *)(*(void **)((s8 *)arg0 + 0x8B4)))->copy_pos(arg0 + 0x424);
                    ((TBoss4Type2 *)(*(void **)((s8 *)arg0 + 0x8B4)))->copy_vec3(&sp8);
                    return;
                }
            }
            break;
        case 2:
            this->impactAge = (this->impactAge + 1);
            if ((s32) this->impactAge < 0x1E) {
                spawn_trap__12TBoss1DragonFii((s32)arg0, 0x4003AD0D);
            }
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                this->stateStep = 3;
                return;
            }
            break;
        }
        break;
    case 5:
        if ((u32) *(u32 *)((s8 *)arg0 + 0x8AC) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8AC));
            *(u32 *)((s8 *)arg0 + 0x8AC) = 0U;
        }
        if ((u32) *(u32 *)((s8 *)arg0 + 0x8B0) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8B0));
            *(u32 *)((s8 *)arg0 + 0x8B0) = 0U;
        }
        if ((u32) *(u32 *)((s8 *)arg0 + 0x8B4) != 0U) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x8B4));
            *(u32 *)((s8 *)arg0 + 0x8B4) = 0U;
        }
        break;
    }
}
#pragma pop
#pragma pop
#undef next_sequence_action__12TBoss1DragonFv
#undef spawn_trap__12TBoss1DragonFii
#undef calc_target_vector__12TBoss1DragonFPv
#undef sin_table_lookup
#undef cos_table_lookup

#define advance_animation_playback ((s32 (*)(void *))advance_animation_playback)

#define LINKED_800267B8 ((s32 (*)(void))TBoss1Dragon::update_linked_epsilon_position)
#define NEAR_800267B8 ((s32 (*)(void *))is_destination_ahead__12TBoss1DragonFPv)
#define VALID_800267B8 ((s32 (*)(void *))enemy_validate_retained_target)
#define PLAY_800267B8 ((void (*)(void *))advance_animation_playback)
void TBoss1Dragon::update_walking_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    extern u8 TBoss1Dragon__data_80434E80[0xC];
    s32 ticks;
    f32 scale;
    s32 iscale;
    s32 next;
    f32 v;
    switch (arg1) {
    case 4:
        this->m_b8 = 1;
        this->vfunc_96();
        clearState__12TBoss1DragonFv(arg0);
        beginHeightTransition__12TBoss1DragonFv(arg0);
        this->flags &= ~0xE80;
        this->stateStep = 0;
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            this->fallVelocity = TBoss1Dragon__data_805D7FF8 + TObjBoss2Tunnel::calc_scaled_value(0x100, TBoss1Dragon__data_805D7FA4);
            break;
        case 1:
            {
                f32 s1 = *(f32 *)((s8 *)((*(Glob_800267B8 *)&TBoss1Dragon__data_804FE17C).value) + 0x10);
                this->fallVelocity = TBoss1Dragon__data_805D7FF8 + TObjBoss2Tunnel::calc_scaled_value((s32) (lbl_805D8078 * s1), s1);
            }
            break;
        }
        break;
    case 2:
    case 11:
        request_state_change__12TBoss1DragonFPvs(arg0, 0x17);
        break;
    case 9:
        ticks = this->stateStep;
        next = 0;
        if (ticks >= 150 && this->m_390 != 0) {
            if (*(f32 *)((s8 *)arg0 + 0x3AC) < this->fallVelocity) {
                next = 1;
            } else if (NEAR_800267B8(arg0) != 0) {
                next = 1;
            } else if (isV2Mode__12TBoss1DragonFv() >= 1 && this->stateStep >= 600) {
                next = 1;
            }
        } else if (ticks >= 300) {
            next = 1;
        }
        if (next != 0) {
            next_sequence_action__12TBoss1DragonFv(arg0);
        }
        break;
    case 8:
        LINKED_800267B8();
        (this->stateStep)++;
        if (this->stateStep % 20 == 19) {
            if (VALID_800267B8(arg0) != 0) {
                ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
            } else {
                ((TObjEneEpsilon *)arg0)->copy_position(TBoss1Dragon__data_80434E80);
            }
            ((TBoss1Dragon *)arg0)->saveTargetDestination();
            send_state_sync__12TBoss1DragonFPv((struct dragon_80028530 *)(arg0));
        }
        break;
    case 7:
        restoreTargetPosition__12TBoss1DragonFv();
        break;
    case 6:
        *(s32 *)((s8 *)arg0 + 0x3B0) = *(s32 *)((s8 *)arg0 + 0x3B4);
        if (LINKED_800267B8() != 0) {
            ((TObjEneDD_ST *)arg0)->enemy_copy_target_destination();
        } else {
            ((TObjEneEpsilon *)arg0)->copy_position(TBoss1Dragon__data_80434E80);
        }
        ((TBoss1Dragon *)arg0)->saveTargetDestination();
        break;
    case 0:
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            scale = TBoss1Dragon__data_805D7FA4;
            break;
        case 1:
            scale = *(f32 *)((s8 *)((*(Glob_800267B8 *)&TBoss1Dragon__data_804FE17C).value) + 0x10);
            break;
        }
        iscale = (s32) (lbl_805D8078 * scale);
        if (this->animationFlags & 4) {
            this->m_c8 = lbl_805D807C * scale;
        } else {
            this->m_c8 = lbl_805D8080 * scale;
        }
        PLAY_800267B8(arg0);
        TBoss1Dragon__sub_80028BE0(arg0);
        update_velocity__9TObjEneDDFv(arg0);
        calc_target_vector__12TBoss1DragonFPv(arg0);
        if (objInBand((GameObj *)arg0, (f32)TBoss1Dragon__data_805D7F9C) != 0) {
            ((TBoss1Dragon *)arg0)->initDefault();
        } else if (objInBand((GameObj *)arg0, (f32)lbl_805D7FA0) != 0) {
            ((TBoss1Dragon *)arg0)->setState1();
        }
        v = this->m_c0;
        if (v < TBoss1Dragon__data_805D7F98) {
            ((TObjEneDD *)arg0)->move_to_shot_position(sin_table_lookup(this->rotation_y), cos_table_lookup(this->rotation_y), scale);
        } else if (!(v < TBoss1Dragon__data_805D7F64)) {
            if (v < lbl_805D8084) {
                TObjEneEpsilon__sub_800B9384(arg0, iscale, scale);
            } else if (v < lbl_805D7FA0) {
                ((TObjEneDD *)arg0)->move_to_shot_position(sin_table_lookup(this->rotation_y), cos_table_lookup(this->rotation_y), scale);
            } else if (!(v < TBoss1Dragon__data_805D7FAC)) {
                TObjEneEpsilon__sub_800B9384(arg0, iscale, scale);
            }
        }
        break;
    }
}

void TBoss1Dragon__sub_80026B98(TBoss1Dragon *arg0, u32 arg1) {
    s32 temp_r4;

    switch (arg1) {
    case 4:
        arg0->m_b8 = 0;
        arg0->stateStep = 0;
        arg0->height = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
        arg0->heightOffset = (f32) arg0->defaultHeightOffset;
        play_se_at_pos__12TBoss1DragonFii((s32) arg0, 0x4003AD00);
        return;
    case 2:
    case 11:
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, (s32) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8)), 4) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 3);
            return;
        }
        if (filter_input_flags__12TBoss1DragonFiii((s32)arg0, (s32) (*(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 8)), 0x400) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 5);
            return;
        }
        if (*(f32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x6E4)) + 0x24) > TBoss1Dragon__data_805D7F90) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x18);
            return;
        }
        break;
    case 0:
        arg0->stateStep = arg0->stateStep + 1;
        advance_animation_playback(arg0);
        break;
    }
}
#undef advance_animation_playback

void TBoss1Dragon__sub_80026C98(TBoss1Dragon *arg0, u32 arg1) {
    switch (arg1) {
    case 4:
        arg0->init_control_mode();
        return;
    case 2:
    case 11:
        ((s32)request_state_change__12TBoss1DragonFPvs(arg0, 0x17));
        return;
    case 9:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x760) != 0) {
            request_state_change__12TBoss1DragonFPvs(arg0, 0x17);
            return;
        }
        next_sequence_action__12TBoss1DragonFv(arg0);
    default:
        return;
    }
}

void dispatch_action__12TBoss1DragonFiUii(s32 arg0, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 0:
        TBoss1Dragon__sub_80026C98((TBoss1Dragon *)((u8 *)arg0), (u32)arg2);
        return;
    case 1:
        TBoss1Dragon__sub_80026B98((TBoss1Dragon *)((u8 *)arg0), (u32)arg2);
        return;
    case 2:
        ((TBoss1Dragon *)arg0)->update_walking_state(arg2);
        return;
    case 3:
        ((TBoss1Dragon *)arg0)->update_breath_attack_state(arg2);
        return;
    case 4:
        ((TBoss1Dragon *)arg0)->update_tail_attack_state(arg2);
        return;
    case 5:
        ((TBoss1Dragon *)arg0)->update_lift_state(arg2);
        return;
    case 6:
        ((TBoss1Dragon *)arg0)->update_flight_state(arg2);
        return;
    case 7:
        ((TBoss1Dragon *)arg0)->update_air_fire_state((u32)arg2);
        return;
    case 8:
    case 10:
    case 11:
    case 12:
        ((TBoss1Dragon*)arg0)->handleFallState(arg2);
        return;
    case 9:
        ((TBoss1Dragon *)arg0)->update_head_down_attack_state(arg2);
        return;
    case 13:
        ((TBoss1Dragon *)arg0)->update_stretch_state(arg2);
        return;
    case 14:
        ((TBoss1Dragon *)arg0)->update_roar_state(arg2);
        return;
    case 15:
        update_dive_state__12TBoss1DragonFv((u8 *)arg0, (u32)arg2);
        return;
    case 16:
    case 17:
        ((TBoss1Dragon *)arg0)->update_burrow_inward_run(arg2, arg1);
        return;
    case 18:
        ((TBoss1Dragon *)arg0)->update_burrow_outward_run(arg2);
        return;
    case 19:
        ((TBoss1Dragon *)arg0)->update_emergence_state((u32)arg2);
        return;
    case 21:
        update_death_state__12TBoss1DragonFv((u8 *)arg0, (u32)arg2);
        return;
    case 22:
        ((TBoss1Dragon *)arg0)->update_fade_state(arg2);
        return;
    case 23:
        TBoss1Dragon__sub_80022C38((TBoss1Dragon *)((u8 *)arg0), (u32)arg2);
        return;
    case 24:
        TBoss1Dragon__sub_800228E8((TBoss1Dragon *)((u8 *)arg0), (u32)arg2);
        return;
    case 25:
        TBoss1Dragon__sub_80022740((TBoss1Dragon *)((u8 *)arg0), (u32)arg2);
        return;
    case 26:
        TBoss1Dragon__sub_800224A4((TBoss1Dragon *)((u8 *)arg0), (u32)arg2);
        return;
    case 27:
        ((TBoss1Dragon *)arg0)->handle_state(arg2);
        return;
    case 28:
        TBoss1Dragon__sub_80022158((TBoss1Dragon *)((u8 *)arg0), (u32)arg2);
        return;
    case 29:
        ((TBoss1Dragon *)arg0)->update_appearance_state(arg2);
        return;
    case 30:
        ((TBoss1Dragon *)arg0)->action(arg2);
        return;
    case 31:
        ((TBoss1Dragon *)arg0)->update_wander_state(arg2);
        return;
    case 34:
        TBoss1Dragon__sub_80025168((void *)arg0, (void *)arg2);
        return;
    case 35:
        TBoss1Dragon__sub_80023A2C((TBoss1Dragon *)((u8 *)arg0), (u32)arg2);
        return;
    case 36:
        ((TBoss1Dragon *)arg0)->state_circle_flight(arg2);
        return;
    case 37:
        ((TBoss1Dragon *)arg0)->handle_fall_state(arg2);
    default:
        return;
    }
}

s32 filter_input_flags__12TBoss1DragonFiii(s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r31;

    var_r31 = arg3;
    if ((get_player_by_client_id(local_client_id) == 0U) || (check_flag_100__10TObjPlayerFPv() != 0)) {
        arg2 &= 0xFFFCF9F9;
    }
    return arg2 & var_r31;
}

}

void TBoss1Dragon::updateFacingPosition() {
    position.x = lbl_805D8088 * sin_table_lookup(facingAngle);
    position.z = lbl_805D8088 * cos_table_lookup(facingAngle);
}

extern "C" {

s32 TBoss1Dragon::check_can_attack() {
    u8 var_r31;

    var_r31 = 0;
    if ((filter_input_flags__12TBoss1DragonFiii((s32)this, (s32)((s32)(*(s32 *)((s8 *)(*(void **)((s8 *)this + 0x6E4)) + 8))), 0x400) != 0) && (this->isHpPhaseComplete() != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

u8 check_attack_ready__12TBoss1DragonFPv(void *arg0) {
    u8 var_r31;

    var_r31 = 0;
    if (((s32) *(s32 *)((s8 *)arg0 + 0x768) >= 0x96) && (filter_input_flags__12TBoss1DragonFiii((s32)arg0, (s32)((s32)(*(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x6E4)) + 8))), 0x400) != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

#pragma push
#pragma fp_contract on
f32 TBoss1Dragon__sub_80027010(Obj_80027010 *arg0, f32 farg0, f32 farg1, f32 farg2) {
    Vec_80027010 v;
    v.x = farg0 * farg2 + arg0->f38;
    v.y = TBoss1Dragon__data_805D7F28;
    v.z = farg1 * farg2 + arg0->f40;
    if (vec3_dot(&v, &v) > lbl_805D808C) {
        farg2 = TBoss1Dragon__data_805D7F28;
    }
    return farg2;
}
#pragma pop

void TBoss1Dragon::release_held_player() {
    s32 var_r31;
    u16 temp_r4;
    u8 *temp_r3;
    temp_r3 = (u8 *)(((u8 *)get_player_by_client_id((s32) *(u16 *)((s8 *)((u8 *)this) + 0x764))));
    if (temp_r3 != NULL) {
        ((TObjPlayer *)temp_r3)->end_camera_pan();
        ((TObjPlayer *)temp_r3)->actorFlags = (s32) (((TObjPlayer *)temp_r3)->actorFlags & 0xFDFFFFFF);
        ((TObjPlayer *)(temp_r3 + 0x644))->reset_lobby_model();
        *(f32 *)((s8 *)temp_r3 + 0x3C) = (f32) TBoss1Dragon__data_805D7F28;
        temp_r4 = *(u16 *)((s8 *)((u8 *)this) + 0x764);
        if (((s32) temp_r4 == (s32) local_client_id) && ((s16) this->mode == 0x15)) {
            send_6x2F_change_player_hp((0xFFFFU), (temp_r4), 0);
        }
    }
    *(s32 *)((s8 *)((u8 *)this) + 0x760) = 0;
    if ((s16) this->mode != 0x15) {
        var_r31 = 0;
        if (isHpPhasePending__12TBoss1DragonFv(this) != 0) {
            this->hpPhaseValue = 0;
            switch (this->mode) {
            case 23:
            case 24:
                var_r31 = 1;
                this->hpPhaseValue = 0;
                break;
            case 3:
                this->hpPhaseValue = 2;
                break;
            case 4:
                this->hpPhaseValue = 3;
                break;
            case 5:
                this->hpPhaseValue = 4;
                break;
            case 25:
            case 26:
                var_r31 = 1;
                this->hpPhaseValue = 6;
                break;
            case 7:
                this->hpPhaseValue = 6;
                break;
            case 8:
                this->hpPhaseValue = 7;
                break;
            case 9:
                this->hpPhaseValue = 0;
                break;
            }
        } else {
            this->hpPhaseValue = 0;
            switch (this->mode) {
            case 23:
            case 24:
                var_r31 = 1;
                this->hpPhaseValue = 0;
                break;
            case 3:
            case 4:
                this->hpPhaseValue = 0;
                break;
            case 5:
                this->hpPhaseValue = 1;
                break;
            case 25:
            case 26:
                var_r31 = 1;
                this->hpPhaseValue = 0xA;
                break;
            case 7:
                this->hpPhaseValue = 0xA;
                break;
            case 8:
            case 19:
                this->hpPhaseValue = 0xB;
                break;
            case 15:
                this->hpPhaseValue = 2;
                break;
            case 36:
            case 37:
                var_r31 = 1;
                this->hpPhaseValue = 9;
                break;
            case 9:
                this->hpPhaseValue = 0;
                break;
            }
            this->hpPhaseValue = (this->hpPhaseValue + 0x32);
        }
        if (var_r31 != 0) {
            next_sequence_action__12TBoss1DragonFv(this);
        }
    }
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::hold_captured_player() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;
    s32 temp_r3b;
    u8 *temp_r3;
    temp_r3 = ((u8 *)get_player_by_client_id((s32)(*(u16 *)((s8 *)arg0 + 0x764))));
    if (temp_r3 != NULL) {
        temp_r31 = get_current_floor();
        temp_r3b = ((TObjPlayer *)temp_r3)->get_field_3e4();
        if (temp_r3b == temp_r31) {
            ((TObjPlayer *)temp_r3)->start_freeze();
            set_type__10TObjPlayerFl(temp_r3 + 0x644, 0x14);
            ((TObjPlayer *)temp_r3)->actorFlags = (s32) (((TObjPlayer *)temp_r3)->actorFlags & 0xFFEFFFDF);
            VecCopy__FP3VecPC3Vec((s32)(temp_r3 + 0x38), (s32)(arg0 + 0x38));
            *(f32 *)((s8 *)temp_r3 + 0x3C) = (f32) (*(f32 *)((s8 *)temp_r3 + 0x3C) - lbl_805D8090);
            ((TObjPlayer *)temp_r3)->rotation_y = (s32) this->rotation_y;
            return;
        }
    }
    TBoss1Dragon::clearControlOverride();
}
#pragma pop

void TBoss1Dragon::init_control_mode() {
    u16 id;

    if (TBoss1Dragon__data_805D4B38 != 0) {
        ((Obj_80027320 *)this)->f760 = 1;
    } else {
        ((Obj_80027320 *)this)->f760 = 0;
        ((Obj_80027320 *)this)->f764 = 0xFFFF;
        return;
    }
    ((Obj_80027320 *)this)->f768 = 0x96;
    ((Obj_80027320 *)this)->f6e4 = controller_input_state + 0x20;
    if (((s32 (*)(void *))is_main_phase_15__9TObjEneDDFv)(controller_input_state) != 0) {
        if (TBoss1Dragon__data_805D4B3C == 0xFFFF) {
            id = TBoss1Dragon::find_player_on_floor(this);
        } else {
            id = TBoss1Dragon__data_805D4B3C;
        }
    } else {
        id = local_client_id;
    }
    {
        u32 r = get_player_by_client_id(id);
        if (r != 0) {
            ((TObjPlayer *)r)->start_freeze();
        }
    }
    ((Obj_80027320 *)this)->f764 = id;
}

#pragma push
#pragma fp_contract on
u16 TBoss1Dragon::find_player_on_floor(void *arg0) {
    u8 *p;
    u16 idx;
    u16 i;
    p = ((u8 *)get_player_by_client_id(TLobby__designated_client_id));
    if (p != NULL) {
        if (((TObjPlayer *)p)->get_field_3e4() == get_current_floor()) {
            return TLobby__designated_client_id;
        }
    }
    for (i = 0; i < 4; i++) {
        idx = (TLobby__designated_client_id + i + 1) % 4;
        p = ((u8 *)get_player_by_client_id(idx));
        if (p != NULL) {
            if (((TObjPlayer *)p)->get_field_3e4() == get_current_floor()) {
                break;
            }
        }
    }
    return idx;
}
#pragma pop

void TBoss1Dragon::update_switch_attack() {
    spawn_particle_effect_with_flags(&this->position, *(s32 *)((s8 *)this->effectResource + 4), 0x40);
}

s32 TBoss1Dragon__sub_80027514(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    ((TBoss1Dragon *)(*(u8 **)((s8 *)arg0 + 0x774)))->get_position();
    *(f32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x774)) + 0xA4)) + 0xC) = (f32) *(f32 *)((s8 *)arg2 + 8);
    *(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x774)) + 0xA4)) + 0x18) = 0x9D03;
    ((VObj_18_310373 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x774))))->m12(arg2 + 0xC, arg2, arg3);
}

s32 TBoss1Dragon__sub_80027590(void* object, void* action) {
    TBoss1Dragon__sub_800275BC((u8 *)((s32)object), (s32)((s32)((char*)object + 0x38)), (u8 *)((u8*)action), 0);
}

void TBoss1Dragon__sub_800275BC(u8 *arg0, s32 arg1, u8 *arg2, s32 arg3) {
    ((TBoss1Dragon *)(*(u8 **)((s8 *)arg0 + 0x774)))->get_position();
    *(f32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x774)) + 0xA4)) + 0xC) = (f32) *(f32 *)((s8 *)arg2 + 8);
    *(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 **)((s8 *)arg0 + 0x774)) + 0xA4)) + 0x18) = 0x9D03;
    ((VObj_18_ffc433 *)((u8 *)(*(u8 **)((s8 *)arg0 + 0x774))))->m15(arg2 + 0xC, arg3);
}

typedef char RecoveredGlobal_80027634_TBoss1Dragon__data_804FE17C_size[sizeof(RecoveredGlobal_80027634_TBoss1Dragon__data_804FE17C) == 0xC ? 1 : -1];
f32 TBoss1Dragon__sub_80027634(void) {
    return lbl_805D8094 * *(f32 *)((s8 *)TBoss1Dragon__data_804FE17C.value + 4);
}

typedef struct CopyStack_80027650 CopyStack_80027650;
typedef struct ByteBlock_10 ByteBlock_10;
typedef struct ByteBlock_14 ByteBlock_14;
typedef struct RecoveredGlobal_80027650_TBoss1Dragon__data_804FE17C RecoveredGlobal_80027650_TBoss1Dragon__data_804FE17C;
typedef struct RecoveredGlobal_80027650_lbl_80435338 RecoveredGlobal_80027650_lbl_80435338;
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
typedef char RecoveredGlobal_80027650_lbl_80435338_size[((sizeof(RecoveredGlobal_80027650_lbl_80435338)) == 0x14) ? (1) : (-1)];
typedef char RecoveredGlobal_80027650_TBoss1Dragon__data_804FE17C_size[((sizeof(RecoveredGlobal_80027650_TBoss1Dragon__data_804FE17C)) == 0xC) ? (1) : (-1)];
void TBoss1Dragon::apply_fireball_impact_damage(s32 arg1) {
  struct CopyStack_80027650
  {
    u8 bytes[0x14];
  };
  CopyStack_80027650 copy_storage_80027650;
  *((ByteBlock_14 *) (((s32)(copy_storage_80027650.bytes - 0x4)) + 4)) = *((const ByteBlock_14 *) ((((u8 *)&dragon_fireball_impact_damage_params.value) - 4) + 4));
  *((f32 *)(copy_storage_80027650.bytes + 0x4)) = *((f32 *) (((s8 *) (*(RecoveredGlobal_80027650_TBoss1Dragon__data_804FE17C *)&TBoss1Dragon__data_804FE17C).value) + 4));
  *((s32 *) copy_storage_80027650.bytes) = *((s32 *) (((s8 *) ((u8 *)this)) + 0x770));
  switch (isV2Mode__12TBoss1DragonFv())
  {
    case 0:
      TObjEneDD::setup((void*)this, (int)((void *) arg1), (int)((void *) copy_storage_80027650.bytes));
      return;
    case 1:
      TBoss1Dragon__sub_80027514((u8 *)this, (s32)((void *) arg1), (u8 *)((void *) copy_storage_80027650.bytes), 0);
      return;
  }
}

typedef char RecoveredGlobal_80027710_lbl_80435324_size[sizeof(RecoveredGlobal_80027710_lbl_80435324) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80027710_TBoss1Dragon__data_804FE17C_size[sizeof(RecoveredGlobal_80027710_TBoss1Dragon__data_804FE17C) == 0xC ? 1 : -1];
void TBoss1Dragon::deliver_breath_attack(s32 arg1, s32 arg2) {
    struct CopyStack_80027710 { u8 bytes[0x14]; };
    CopyStack_80027710 copy_storage_80027710;
    *(ByteBlock_14 *)(copy_storage_80027710.bytes) = *(const ByteBlock_14 *)((s32) ((u8 *)((void *)((u8 *)&dragon_fireball_attack_params.value + -4))) + 4);
    (*(f32 *)(copy_storage_80027710.bytes + 0x4)) = *(f32 *)((s8 *)((*(RecoveredGlobal_80027710_TBoss1Dragon__data_804FE17C *)&TBoss1Dragon__data_804FE17C).value) + 0);
    (*(s32 *)copy_storage_80027710.bytes) = *(s32 *)((s8 *)((u8 *)this) + 0x770);
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        TObjEneDD::setup_instance((s32) this, arg1, (copy_storage_80027710.bytes), arg2);
        return;
    case 1:
        TBoss1Dragon__sub_80027514((u8 *)this, (s32)arg1, (u8 *)((copy_storage_80027710.bytes)), (s32)arg2);
        return;
    }
}

typedef char RecoveredGlobal_800277D8_lbl_80435310_size[sizeof(RecoveredGlobal_800277D8_lbl_80435310) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_800277D8_TBoss1Dragon__data_804FE17C_size[sizeof(RecoveredGlobal_800277D8_TBoss1Dragon__data_804FE17C) == 0xC ? 1 : -1];
void TBoss1Dragon__sub_800277D8(u8 *arg0) {
    struct CopyStack_800277D8 { u8 bytes[0x14]; };
    CopyStack_800277D8 copy_storage_800277D8;
    u8 *temp_r3;
    temp_r3 = (u8 *)(*(u8 **)((s8 *)arg0 + 0x6D8));
    if ((temp_r3 != NULL) && (is_dragon_trail_damaging(temp_r3) != 0)) {
        *(ByteBlock_14 *)(copy_storage_800277D8.bytes) = *(const ByteBlock_14 *)((s32) ((u8 *)((void *)((u8 *)&dragon_breath_attack_params.value + -4))) + 4);
        (*(f32 *)(copy_storage_800277D8.bytes + 0x4)) = *(f32 *)((s8 *)((*(RecoveredGlobal_800277D8_TBoss1Dragon__data_804FE17C *)&TBoss1Dragon__data_804FE17C).value) + 8);
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            TObjEneDD::setup_instance((s32) arg0, (s32)(arg0 + 0x38), (copy_storage_800277D8.bytes), *(s32 *)((s8 *)arg0 + 0x688));
            return;
        case 1:
            TBoss1Dragon__sub_80027514(arg0, (s32)((s32)(arg0 + 0x38)), (u8 *)((copy_storage_800277D8.bytes)), (s32)(*(s32 *)((s8 *)arg0 + 0x688)));
            break;
        }
    }
}

#pragma push
#pragma opt_common_subs off
void TBoss1Dragon::sweep_death_body_attack() {
    u8 *pts[8];
    Vec_800278A8 pos;
    Params_800278A8 params;
    s32 i;
    s32 off;
    reset_hp__9TObjEneDDFv(this, 0, *(s32 *)((s8 *)&TBoss1Dragon__part_hp_stats + 0x10), 0);
    fill_value_array(*(s32 *)((s8 *)((u8 *)this) + 0x688));
    TBoss1Dragon__sub_80027A80((u8 *)&params, TBoss1Dragon__head_fall_effect_params);
    VecCopy__FP3VecPC3Vec((s32)&pos, (s32)(((u8 *)this) + 0x4C0));
    params.scale = lbl_805D7FD0;
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        emit_enemy_effect__9TObjEneDDFllPUcl(this, &pos, &params, *(s32 *)((s8 *)((u8 *)this) + 0x688));
        break;
    case 1:
        TBoss1Dragon__sub_800275BC(((u8 *)this), (s32)&pos, (u8 *)&params, *(s32 *)((s8 *)((u8 *)this) + 0x688));
        break;
    }
    params.scale = TBoss1Dragon__data_805D7F38;
    pts[0] = ((u8 *)this) + 0x484;
    pts[1] = ((u8 *)this) + 0x49C;
    for (i = 0; i < 2; i++) {
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            emit_enemy_effect__9TObjEneDDFllPUcl(this, pts[i], &params, *(s32 *)((s8 *)((u8 *)this) + 0x688));
            break;
        case 1:
            TBoss1Dragon__sub_800275BC(((u8 *)this), (s32)pts[i], (u8 *)&params, *(s32 *)((s8 *)((u8 *)this) + 0x688));
            break;
        }
    }
    params.scale = lbl_805D8024;
    pts[0] = ((u8 *)this) + 0x4D8;
    pts[1] = ((u8 *)this) + 0x4E4;
    pts[2] = ((u8 *)this) + 0x4F0;
    pts[3] = ((u8 *)this) + 0x4FC;
    for (i = 0; i < 4; i++) {
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            emit_enemy_effect__9TObjEneDDFllPUcl(this, pts[i], &params, *(s32 *)((s8 *)((u8 *)this) + 0x688));
            break;
        case 1:
            TBoss1Dragon__sub_800275BC(((u8 *)this), (s32)pts[i], (u8 *)&params, *(s32 *)((s8 *)((u8 *)this) + 0x688));
            break;
        }
    }
    reset_hp__9TObjEneDDFv(this, 0, *(s32 *)((s8 *)&TBoss1Dragon__part_hp_stats + 0), 0);
}
#pragma pop

void TBoss1Dragon__sub_80027A80(u8 *arg0, u8 *arg1) {
    *(ByteBlock_8 *)(arg0) = *(const ByteBlock_8 *)(arg1);
    *(f32 *)((s8 *)arg0 + 8) = (f32) *(f32 *)((s8 *)arg1 + 8);
    *(ByteBlock_8 *)((s32) arg0 + 0xC) = *(const ByteBlock_8 *)((s32) arg1 + 0xC);
}

typedef char RecoveredGlobal_80027AAC_lbl_80434EB4_size[sizeof(RecoveredGlobal_80027AAC_lbl_80434EB4) == 0x14 ? 1 : -1];
void TBoss1Dragon::apply_ground_impact_attack() {
    s32 arg0 = (s32)this;
    reload_impact_stats();
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        ((TObjEneDD *)arg0)->emit_effect_at_position((void *)&boss1_dragon_ground_impact_params.value);
        break;
    case 1:
        TBoss1Dragon__sub_80027590((void*)arg0, (void*)((void *)&boss1_dragon_ground_impact_params.value));
        break;
    }
    reload_difficulty_stats();
}

void sweep_head_fall_spheres_late__12TBoss1DragonFv(void) {
    ((s32 (*)(f32, f32, f32))sweep_body_attack_spheres__12TBoss1DragonFv)(TBoss1Dragon__data_805D8010, lbl_805D8098, TBoss1Dragon__data_805D7F84);
}

void update_from_data__12TBoss1DragonFv(void) {
    ((s32 (*)(f32, f32, f32))sweep_body_attack_spheres__12TBoss1DragonFv)(TBoss1Dragon__data_805D8010, lbl_805D809C, lbl_805D80A0);
}

struct Vec_80027B78 { f32 x, y, z; };
struct Fx_80027B78 { u32 w0; u32 w1; f32 f8; u32 wc; u32 w10; };
void draw_chunk_object(void *child);
extern s32 lbl_805D28BC;
extern const f32 lbl_805D80A4;
#pragma push
#pragma fp_contract on
void sweep_body_attack_spheres__12TBoss1DragonFv(u8 *arg0, f32 a, f32 b, f32 c) {
    Vec_80027B78 pos;
    Vec_80027B78 base;
    Fx_80027B78 fx = *(Fx_80027B78 *)TBoss1Dragon__head_fall_effect_params;
    f32 s0;
    f32 s1;
    f32 d;

    fx.f8 = a - TBoss1Dragon__data_805D7F24;
    fill_value_array(*(s32 *)((s8 *)arg0 + 0x688));
    s0 = sin_table_lookup(((TObjEneDD *)arg0)->rotation_y);
    s1 = cos_table_lookup(((TObjEneDD *)arg0)->rotation_y);
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&base, arg0 + 0x38);
    base.x = lbl_805D80A4 * s1 + base.x;
    base.y = TBoss1Dragon__data_805D7F28;
    base.z = base.z - lbl_805D80A4 * s0;
    d = TBoss1Dragon__data_805D7F48 * (b + c);
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&pos, &base);
    pos.x += s0 * d;
    pos.z += s1 * d;
    spawn_particle_effect_with_flags(&pos, *(s32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0x778)) + 0xC), 0x40);
    reset_hp__9TObjEneDDFv(arg0, 0, *(s32 *)((s8 *)&TBoss1Dragon__part_hp_stats + 0x10), 0);
    c = c - a;
    d = b - a;
    a = a * TBoss1Dragon__data_805D7F24;
    b = TBoss1Dragon__data_805D7F48 * (TBoss1Dragon__data_805D7F48 * a);
    while (d > c) {
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&pos, &base);
        pos.x += s0 * d;
        pos.z += s1 * d;
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            emit_enemy_effect__9TObjEneDDFllPUcl(arg0, &pos, &fx, *(s32 *)((s8 *)arg0 + 0x688));
            break;
        case 1:
            ((void (*)(u8 *, void *, void *, s32))TBoss1Dragon__sub_800275BC)(arg0, &pos, &fx, *(s32 *)((s8 *)arg0 + 0x688));
            break;
        }
        d -= a;
        push_matrix();
        post_translate_matrix(&pos);
        scale_matrix(0, b, TBoss1Dragon__data_805D7F24, b);
        draw_chunk_object((void *)lbl_805D28BC);
        pop_matrix();
    }
    reset_hp__9TObjEneDDFv(arg0, 0, TBoss1Dragon__part_hp_stats.value, 0);
}

#pragma pop

}

int TBoss1Dragon::setState1() {
    return apply_foot_step_attack(1);
}

int TBoss1Dragon::initDefault() {
    return apply_foot_step_attack(0);
}

extern ByteBlock_14 TBoss1Dragon__foot_step_attack_params;
int TBoss1Dragon::apply_foot_step_attack(int arg1) {
    ByteBlock_14 params = TBoss1Dragon__foot_step_attack_params;
    u8 *a;
    u8 *b;

    fill_value_array(*(s32 *)((s8 *)((u8 *)this) + 0x688));
    if (arg1 == 0) {
        a = ((u8 *)this) + 0x46C;
        b = ((u8 *)this) + 0x478;
    } else {
        a = ((u8 *)this) + 0x454;
        b = ((u8 *)this) + 0x460;
    }
    reset_hp__9TObjEneDDFv(this, 0, TBoss1Dragon__part_hp_stats.value, 0);
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        emit_enemy_effect__9TObjEneDDFllPUcl(this, a, params.bytes, *(s32 *)((s8 *)((u8 *)this) + 0x688));
        emit_enemy_effect__9TObjEneDDFllPUcl(this, b, params.bytes, *(s32 *)((s8 *)((u8 *)this) + 0x688));
        break;
    case 1:
        TBoss1Dragon__sub_800275BC(((u8 *)this), (s32) a, params.bytes, *(s32 *)((s8 *)((u8 *)this) + 0x688));
        TBoss1Dragon__sub_800275BC(((u8 *)this), (s32) b, params.bytes, *(s32 *)((s8 *)((u8 *)this) + 0x688));
        break;
    }
    reset_hp__9TObjEneDDFv(this, 0, TBoss1Dragon__part_hp_stats.value, 0);
    spawn_particle_effect_with_flags(b, *(s32 *)((s8 *)this->effectResource + 0xC), 0x40);
}

void TBoss1Dragon::apply_head_fall_attack() {
    reset_hp__9TObjEneDDFv(this, 0, *(s32 *)((s8 *)&TBoss1Dragon__part_hp_stats + 0x10), 0);
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        emit_effect_at_position(TBoss1Dragon__head_fall_effect_params);
        break;
    case 1:
        TBoss1Dragon__sub_80027590(this, TBoss1Dragon__head_fall_effect_params);
        break;
    }
    reset_hp__9TObjEneDDFv(this, 0, *(s32 *)((s8 *)&TBoss1Dragon__part_hp_stats + 0), 0);
}

typedef char RecoveredGlobal_80027E78_lbl_80434E8C_size[sizeof(RecoveredGlobal_80027E78_lbl_80434E8C) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80027E78_TBoss1Dragon__data_804FE17C_size[sizeof(RecoveredGlobal_80027E78_TBoss1Dragon__data_804FE17C) == 0xC ? 1 : -1];
void apply_landing_attack__12TBoss1DragonFi(s32 arg0) {
    typedef char sp8_offset[(offsetof(Stack_80027E78, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80027E78, sp10) == 0x8) ? 1 : -1];
    Stack_80027E78 stack;
    TBoss1Dragon__sub_80027A80((u8 *)&stack.sp8, (u8 *)&boss1_dragon_attack_sphere_params.value);
    stack.sp10 = *(f32 *)((s8 *)((*(RecoveredGlobal_80027E78_TBoss1Dragon__data_804FE17C *)&TBoss1Dragon__data_804FE17C).value) + 0xC);
    ((TBoss1Dragon *)arg0)->reload_stats_for_phase((int) ((*(RecoveredGlobal_80027E78_TBoss1Dragon__data_804FE17C *)&TBoss1Dragon__data_804FE17C).value));
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        ((TObjEneDD *)arg0)->emit_effect_at_position(&stack.sp8);
        break;
    case 1:
        TBoss1Dragon__sub_80027590((void*)arg0, (void*)((void *)&stack.sp8));
        break;
    }
    ((TBoss1Dragon *)arg0)->reload_difficulty_stats();
}

void clear_work__12TBoss1DragonFi(s32 arg0) {
    start_pad_rumble_at((Vec *)(arg0 + 0x38), 0xE0, arg0);
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::spawn_impact_crater(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    Vec position;
    s32 temp_r5;
    VecCopy__FP3VecPC3Vec((s32)&position.x, arg1);
    temp_r5 = *(s32 *)((s8 *)arg0 + 0x6A4);
    if (temp_r5 < 0xC) {
        position.y += lbl_805D80A8 * (f32) temp_r5;
        *(s32 *)((s8 *)arg0 + 0x6A4) = (temp_r5 + 1);
        ((TObjBoss1Crater *)tl_02)->create(&position.x);
    }
    spawn_particle_effect_with_flags((&position.x), (s32)((void *) (**(s32 * *)&this->effectResource)), 0x840);
    TCameraCtrl::set_shake_preset(1);
}
#pragma pop

#pragma push
#pragma fp_contract on
f32 calc_burrow_speed__12TBoss1DragonFPv(void *arg0) {
    return (TBoss1Dragon__data_805D7F98 * (f32) *(s32 *)((s8 *)arg0 + 0x6DC)) + TBoss1Dragon__data_805D7F98;
}
#pragma pop

s32 TBoss1Dragon::check_phase_advance() {
    if ((s16) this->hp <= (s16) this->hpThreshold) {
        if ((s32) this->phase == 1) {
            request_state_change__12TBoss1DragonFPvs(this, 0xA);
            return 1;
        }
        request_state_change__12TBoss1DragonFPvs(this, 9);
        return 1;
    }
    return 0;
}

s32 TBoss1Dragon::update_max_hp_phase() {
    s16 temp_r4;

    if ((s16) this->hp <= (temp_r4 = this->finalHpThreshold)) {
        this->hp = temp_r4;
        this->setHpPhaseValue(1);
        if ((s32) this->phase == 0) {
            request_state_change__12TBoss1DragonFPvs(this, 0xD);
            return 1;
        }
        request_state_change__12TBoss1DragonFPvs(this, 0xB);
        return 1;
    }
    return 0;
}

void TBoss1Dragon::saveCurrentDestination() {
    destinationX = position.x;
    destinationZ = position.z;
}

void TBoss1Dragon::setDestinationX(int x) {
    destinationX = (f32)x;
    destinationZ = TBoss1Dragon__data_805D7F28;
}

void TBoss1Dragon::saveTargetDestination() {
    destinationX = targetX;
    destinationZ = targetZ;
}

void TBoss1Dragon::restorePosition() {
    position.x = savedX;
    position.z = savedZ;
}

void TBoss1Dragon::copySavedX(int* x) {
    *x = (int)savedX;
}

void TBoss1Dragon::restoreTargetPosition() {
    targetX = savedX;
    targetZ = savedZ;
}

typedef char RecoveredGlobal_8002826C_lbl_80480D00_size[sizeof(RecoveredGlobal_8002826C_lbl_80480D00) == 0x48 ? 1 : -1];
typedef char RecoveredGlobal_8002826C_lbl_80480D48_size[sizeof(RecoveredGlobal_8002826C_lbl_80480D48) == 0x240 ? 1 : -1];
typedef char RecoveredFields_8002826C_arg0_67C_offset[offsetof(RecoveredFields_8002826C_arg0, field_67C) == 0x67C ? 1 : -1];
typedef char RecoveredFields_8002826C_arg0_760_offset[offsetof(RecoveredFields_8002826C_arg0, field_760) == 0x760 ? 1 : -1];

void TBoss1Dragon::remap_sequence_after_recovery() {
    if ((s32) ((RecoveredFields_8002826C_arg0 *)((u8 *)this))->field_760 != 0) {
        next_sequence_action__12TBoss1DragonFv(((u8 *)this));
        return;
    }
    if (((TBoss1Dragon *)((u8 *)this))->update_max_hp_phase() == 0) {
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            ((RecoveredFields_8002826C_arg0 *)((u8 *)this))->field_67C = (s32) *(s32 *)((s8 *)((s32 *)boss1_dragon_sequence_remap_table) + (((RecoveredFields_8002826C_arg0 *)((u8 *)this))->field_67C * 4));
            break;
        case 1:
            ((RecoveredFields_8002826C_arg0 *)((u8 *)this))->field_67C = (s32) *(s32 *)((s8 *)((s32 *)lbl_80480D48) + (((RecoveredFields_8002826C_arg0 *)((u8 *)this))->field_67C * 4));
            break;
        }
        next_sequence_action__12TBoss1DragonFv(((u8 *)this));
    }
}

struct Dragon_8002830C {
    u8 pad0[0x67C];
    s32 seqPos;
};

s32 next_sequence_action__12TBoss1DragonFv(void *vself) {
#define self ((Dragon_8002830C *)vself)
    s32 idx;
    s32 *seq;
    s32 code;
    s32 again;

    s32 pos = self->seqPos;
    if (pos < 50) {
        idx = pos;
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            seq = (s32 *)TBoss1Dragon__data_80480CE0;
            break;
        case 1:
            seq = (s32 *)lbl_80480D20;
            break;
        }
    } else {
        idx = pos - 50;
        switch (isV2Mode__12TBoss1DragonFv()) {
        case 0:
            seq = (s32 *)boss1_dragon_action_sequence_table;
            break;
        case 1:
            seq = (s32 *)boss1_dragon_action_sequence_table_b;
            break;
        }
    }
    do {
        code = seq[idx];
        again = 0;
        idx++;
        self->seqPos++;
        switch (code) {
        case 32:
            self->seqPos = 0;
            again = 1;
            idx = 0;
            break;
        case 33:
            self->seqPos = 50;
            again = 1;
            idx = 0;
            break;
        }
    } while (again != 0);
    ((s32 (*)(void *, s32))request_state_change__12TBoss1DragonFPvs)(self, code);
#undef self
}

struct Pkt_800284B4 {
    u16 hdr; u16 owner; s16 state; s16 cursor; s32 target; f32 x; f32 z;
};
struct Dragon_800284B4 {
    u8 pad0[0x1C]; u16 owner; u8 pad1[0x38C - 0x1E]; u16 target; u8 pad2[0x67C - 0x38E];
    s32 cursor; u8 pad3[0x690 - 0x680]; f32 x; f32 z;
};
struct VBase_800284B4 { u8 pad[0x18]; };
struct VObj_800284B4 : VBase_800284B4 {
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
    virtual void m84(); virtual void m85(s16, s32);
};

s32 request_state_change__12TBoss1DragonFPvs(void *vself, s16 state32) {
    struct Dragon_800284B4 *self = (struct Dragon_800284B4 *)vself;
    struct Pkt_800284B4 pkt;

    ((VObj_800284B4 *) self)->m85(state32, 6);
    ((TObjPlayer *)(&pkt))->set_type_dragon();
    pkt.owner = self->owner;
    pkt.state = state32;
    pkt.cursor = self->cursor;
    pkt.target = self->target;
    pkt.x = self->x;
    pkt.z = self->z;
    ((TObjPlayer *)(&pkt))->send_6x12_packet();
}

void send_state_sync__12TBoss1DragonFPv(struct dragon_80028530 *s) {
    struct pkt_80028530 pkt;
    ((TObjPlayer *)(&pkt))->set_type_dragon();
    pkt.target_id = s->target_id;
    pkt.state = s->mode;
    pkt.cursor = (s16) s->sequence_cursor;
    pkt.extra = s->extra;
    pkt.x = s->outgoing_x;
    pkt.z = s->outgoing_z;
    ((TObjPlayer *)(&pkt))->send_6x12_packet();
}

void TBoss1Dragon::receive_state_request(u8 *arg1) {
    s16 temp_r4;
    enemy_set_target_id(this, (u16) *(s32 *)((s8 *)arg1 + 8));
    this->hpPhaseValue = (s32) *(s16 *)((s8 *)arg1 + 6);
    this->savedX = (f32) *(f32 *)((s8 *)arg1 + 0xC);
    this->savedZ = (f32) *(f32 *)((s8 *)arg1 + 0x10);
    ((VObj_18_be4a70 *)(this))->m85(*(s16 *)((s8 *)arg1 + 4), 7);
    temp_r4 = *(s16 *)((s8 *)arg1 + 4);
    if ((s16) this->mode != temp_r4) {
        transition_enemy_state(temp_r4);
    }
}

void handle_6x12_dragon_boss_actions(TObjPlayer *arg0) {
    void *x;
    arg0->bswap_6x12_packet();
    x = get_enemy_entity(*(u16 *)((s8 *)arg0 + 0x2));
    if (x != NULL) {
        ((TBoss1Dragon *)x)->receive_state_request((u8 *)arg0);
    }
}

void TBoss1Dragon::set_params(void *arg1) {
    enemy_set_target_id(this, (u16) *(s32 *)((s8 *)arg1 + 8));
    this->hpPhaseValue = (s32) *(s16 *)((s8 *)arg1 + 6);
    if ((s16) this->mode != (s16) *(s16 *)((s8 *)arg1 + 4)) {
        transition_enemy_state((s16)((s16) *(s16 *)((s8 *)arg1 + 4)));
    }
}

void handle_6x11_dragon_boss_actions(void *arg0) {
    void *x;
    ((TObjPlayer *)arg0)->bswap_dragon_boss_fields();
    x = get_enemy_entity(*(u16 *)((s8 *)arg0 + 0x2));
    if (x != NULL) {
        ((TBoss1Dragon *)x)->set_params(arg0);
    }
}

void TBoss1Dragon::copy_params(void *arg1) {
    enemy_set_target_id(this, (u16) *(s32 *)((s8 *)arg1 + 8));
    this->hpPhaseValue = (s32) *(s16 *)((s8 *)arg1 + 6);
    transition_enemy_state(*(s16 *)((s8 *)arg1 + 4));
}

void handle_6x10_dragon_boss_actions(void *arg0) {
    void *x;
    ((TObjPlayer *)arg0)->bswap_stats();
    x = get_enemy_entity(*(u16 *)((s8 *)arg0 + 0x2));
    if (x != NULL) {
        ((TBoss1Dragon *)x)->copy_params(arg0);
    }
}

typedef char RecoveredGlobal_800646F0_lbl_80437944_size[sizeof(RecoveredGlobal_800646F0_lbl_80437944) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_800646F0_lbl_804FF5B4_size[sizeof(RecoveredGlobal_800646F0_lbl_804FF5B4) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_8006435C_lbl_80437D2C_size[sizeof(RecoveredGlobal_8006435C_lbl_80437D2C) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_8006435C_lbl_804FF5A0_size[sizeof(RecoveredGlobal_8006435C_lbl_804FF5A0) == 0x14 ? 1 : -1];
typedef char RecoveredGlobal_80064CFC_lbl_80487848_size[sizeof(RecoveredGlobal_80064CFC_lbl_80487848) == 0x10 ? 1 : -1];
typedef char RecoveredGlobal_80064CFC_lbl_804FF5A0_size[sizeof(RecoveredGlobal_80064CFC_lbl_804FF5A0) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_8002885C_TBoss1Dragon__data_804FE168_size[sizeof(RecoveredGlobal_8002885C_TBoss1Dragon__data_804FE168) == 0x14 ? 1 : -1];

void TBoss1Dragon::reload_impact_stats() {
    reload_stats_keep_hp_tp__9TObjEneDDFv(this, (&TBoss1Dragon__data_805D4B00)[boss1_dragon_base_stat_indices[3]], ((s32 *)&TBoss1Dragon__part_hp_stats)[boss1_dragon_attack_stat_indices[3]], (&TBoss1Dragon__data_805D4B04)[boss1_dragon_resistance_stat_indices[3]]);
}

void TBoss1Dragon::reload_stats_for_phase(int _w1) {
    reload_stats_keep_hp_tp__9TObjEneDDFv(this, (&TBoss1Dragon__data_805D4B00)[boss1_dragon_base_stat_indices[2]], ((s32 *)&TBoss1Dragon__part_hp_stats)[boss1_dragon_attack_stat_indices[2]], (&TBoss1Dragon__data_805D4B04)[boss1_dragon_resistance_stat_indices[2]]);
}

void TBoss1Dragon::reset_tail_hp() {
    s32 arg0 = (s32)this;
    reset_hp__9TObjEneDDFv((void *)arg0, 0, (int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_8002885C_TBoss1Dragon__data_804FE168 *)&TBoss1Dragon__part_hp_stats).value) + 4)), 0);
}

void TBoss1Dragon::reload_difficulty_stats() {
    s32 arg0 = (s32)this;
    reload_stats_keep_hp_tp__9TObjEneDDFv((void *)arg0, (int) (*(s32 *)((s8 *)&TBoss1Dragon__data_805D4B00 + (*(s32 *)((s8 *)((s32 *)TBoss1Dragon__data_80480CE0) + 0x11c) * 4))), (int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_80064CFC_lbl_804FF5A0 *)&TBoss1Dragon__part_hp_stats).value) + (*(s32 *)((s8 *)((s32 *)TBoss1Dragon__data_80480CE0) + 0x130) * 4))), (int) (*(s32 *)((s8 *)&TBoss1Dragon__data_805D4B04 + (*(s32 *)((s8 *)((s32 *)TBoss1Dragon__data_80480CE0) + 0x144) * 4))));
}

#pragma push
#pragma fp_contract on
s32 TBoss1Dragon::advance_air_turn() {
    Obj_800288EC *self = (Obj_800288EC *)this;
    f32 t;
    self->f678 += 1.0f;
    t = self->f678;
    if (t <= 35.0f) {
        this->rotation_y = self->f660 + (s32)(t * ((0.5f * self->f664) * t + self->f66C));
        return 0;
    }
    if (t <= 60.0f) {
        t -= 35.0f;
        this->rotation_y = self->f660 + (s32)(t * ((0.5f * self->f668) * t + self->f670) + self->f674);
        return 0;
    }
    return 1;
}
#pragma pop

void TBoss1Dragon::set_result_flag(s32 arg1, s32 arg2) {
    if (angle_diff_s16(arg1, arg2) >= 0) {
        *(s32 *)((s8 *)this + 0x65C) = 1;
        return;
    }
    *(s32 *)((s8 *)this + 0x65C) = -1;
}

void TBoss1Dragon::beginHeightTransition() {
    flags |= 0x100;
    height = position.y;
    heightOffset = defaultHeightOffset;
}

void TBoss1Dragon::setPhase2() {
    phase = 2;
}

void TBoss1Dragon::setActive() {
    phase = 1;
}

void TBoss1Dragon::clearState() {
    phase = 0;
}

void TBoss1Dragon__sub_80028B28(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) | 0x100);
    *(f32 *)((s8 *)arg0 + 0x5D8) = (f32) (TBoss1Dragon__data_805D8040 + *(f32 *)((s8 *)arg0 + 0x3C));
    *(f32 *)((s8 *)arg0 + 0x5DC) = (f32) (TBoss1Dragon__data_805D8040 + *(f32 *)((s8 *)arg0 + 0x5E0));
}

void TBoss1Dragon::play_nearby_se() {
    s32 arg0 = (s32)this;
    if (objInBand((GameObj *)arg0, TBoss1Dragon__data_805D7FF8) != 0) {
        play_se_at_pos__12TBoss1DragonFii(arg0, 0x4003A804);
    }
}

void TBoss1Dragon__sub_80028BE0(u8 *arg0) {
    if ((objInBand((GameObj *)arg0, (f32)TBoss1Dragon__data_805D7F98) != 0) || (objInBand((GameObj *)((GameObj *)arg0), (f32)((f32)lbl_805D80B0)) != 0)) {
        play_se_at_pos__12TBoss1DragonFii((s32) arg0, 0x4003A801);
    }
}

void spawn_trap__12TBoss1DragonFii(s32 arg0, s32 arg1) {
    play_persistent_sound(arg1, arg0, arg0 + 0x63C, 0, 0);
}

void play_se_at_pos__12TBoss1DragonFii(s32 arg0, s32 arg1) {
    play_sound_effect(arg1, arg0 + 0x63C, 0, 0);
}

s32 TBoss1Dragon::isHpPhaseComplete() {
    return (u8)(hpPhaseValue >= 50);
}

s32 TBoss1Dragon::isHpPhasePending() {
    return hpPhaseValue < 50;
}

void TBoss1Dragon::setHpPhaseValue(int complete) {
    if (complete == 0) {
        hpPhaseValue = 0;
        return;
    }
    hpPhaseValue = 50;
}

void TBoss1Dragon::resetHpPhase() {
    setHpPhaseValue(0);
}

s32 select_forward_target__12TBoss1DragonFPv(u8 *self) {
    u16 selected[4];
    Vec_80028CA8 delta;
    Vec_80028CA8 fwd;
    f32 cutoff;
    s32 n;
    s32 count;
    u8 *p;
    s32 i;
    n = 0;
    count = TLobby::get_game_mode();
    if (count > 4) {
        count = 4;
    }
    cutoff = cos_table_lookup(0x3000);
    fwd.x = sin_table_lookup(*(s32 *)(self + 0x60));
    fwd.y = TBoss1Dragon__data_805D7F28;
    fwd.z = cos_table_lookup(*(s32 *)(self + 0x60));
    for (i = 0; i < count; i++) {
        p = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (is_alive__9TObjEneDDFv(p) != 0) {
            ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&delta, p + 0x38);
            subtract_vector(&delta, self + 0x38);
            ((void (*)(void *))clamp_velocity__15TObjBoss2TunnelFv)(&delta);
            if (vec3_dot(&delta, &fwd) > cutoff) {
                selected[n++] = get_entity_id(p);
            }
        }
    }
    if (n <= 0) {
        enemy_clear_target__12TObjEneDD_STFUs(self);
        return 0;
    }
    if (n == 1) {
        enemy_set_target_id(self, selected[0]);
        return 1;
    }
    enemy_set_target_id(self, selected[(s32)get_random_float__21TObjEneMe3ShinowaRealFv((f32)n * ((f32 (*)(void *))calc_boss4_scale__10TObjPlayerFi)(self))]);
    return 1;
}

s32 choose_burrow_ring_destination__12TBoss1DragonFPvPv(Dragon_80028EA8 *arg0, Vec_80028EA8 *arg1) {
    s32 idx;
    f32 r;
    idx = (s32)get_random_float__21TObjEneMe3ShinowaRealFv(TBoss1Dragon__data_805D7F38 * calc_boss4_scale__10TObjPlayerFi());
    if (arg0->count < 12) {
        arg0->count++;
        while (TBoss1Dragon__data_805D7F28 != arg0->slots[idx]) {
            idx++;
            if (idx >= 12) {
                idx = 0;
            }
        }
        r = rand_range__9TObjEneDDFff(arg0, TBoss1Dragon__data_805D7FC4, lbl_805D7FE0);
        arg0->slots[idx] = r;
    } else {
        r = arg0->slots[idx];
    }
    arg1->x = r * sin_table_lookup(idx * 0x1555);
    arg1->y = TBoss1Dragon__data_805D7F28;
    arg1->z = r * cos_table_lookup(idx * 0x1555);
    return 1;
}

#define arg1 ((Vec_80028F9C *)out_)
s32 TBoss1Dragon::select_air_fire_target(void *out_) {
    s32 arg0 = (s32)this;
    Player_80028F9C *p;
    Player_80028F9C *list[12];
    s32 top;
    s32 count;
    s32 i;
    s32 best;
    Vec_80028F9C *apos;
    Player_80028F9C *a;
    Player_80028F9C *b;
    s32 found;
    s32 i2;
    s32 j;
    f32 range;
    s32 sum;
    range = lbl_805D80B8;
    count = 0;
    for (i = 0; i < 12; i++) {
        p = (Player_80028F9C *)get_player_by_client_id(i);
        if (is_valid_target__9TObjEneDDFv(p) != 0 && horizontal_distance_squared(&p->pos, (void *)(arg0 + 0x38)) >= range) {
            list[count++] = p;
        }
    }
    if (count <= 0) {
        return 0;
    }
    if (count == 1) {
        ((s32 (*)(Vec_80028F9C *, Vec_80028F9C *))VecCopy__FP3VecPC3Vec)(arg1, &list[0]->pos);
    } else {
        range = TBoss1Dragon__data_805D7FC4;
        best = 0;
        found = 0;
        for (i2 = 0; i2 < count; i2++) {
            a = list[i2];
            apos = &a->pos;
            for (j = i2 + 1; j < count; j++) {
                b = list[j];
                if (newton_sqrtf(horizontal_distance_squared(&b->pos, apos)) < range) {
                    found = 1;
                    sum = a->hp + b->hp;
                    if (sum > best) {
                        best = sum;
                        arg1->x = TBoss1Dragon__data_805D7F48 * (apos->x + b->pos.x);
                        arg1->y = TBoss1Dragon__data_805D7F48 * (apos->y + b->pos.y);
                        arg1->z = TBoss1Dragon__data_805D7F48 * (apos->z + b->pos.z);
                    }
                }
            }
        }
        if (found == 0) {
            s32 k;
            top = 0;
            for (k = 0; k < count; k++) {
                if (top < list[k]->hp) {
                    top = list[k]->hp;
                    ((s32 (*)(Vec_80028F9C *, Vec_80028F9C *))VecCopy__FP3VecPC3Vec)(arg1, &list[k]->pos);
                }
            }
        }
    }
    return 1;
}
#undef arg1

f32 TBoss1Dragon::sample_root_height() {
    struct Vec_80029238 v;
    v.x = TBoss1Dragon__data_805D7F28;
    v.y = TBoss1Dragon__data_805D7F28;
    v.z = TBoss1Dragon__data_805D7F28;
    push_matrix_from(identity_matrix);
    scale_matrix(0, TBoss1Dragon__data_805D7F24, TBoss1Dragon__data_805D7F24, TBoss1Dragon__data_805D7F24);
    bind_motion_context(this->unknownF8, this->m_c0);
    compose_motion_node_matrix(this->model);
    matrix_mult_vec(0, &v, &v);
    pop_matrix();
    return v.y;
}

s32 is_destination_ahead__12TBoss1DragonFPv(u8 *s) {
    Vec_800292C0 pt;
    Vec_800292C0 diff;
    Vec_800292C0 unused;

    ((TBoss1Dragon *)s)->calc_forward_point(&pt.x, &pt.z);
    VecCopy__FP3VecPC3Vec((s32) &diff, (s32)(s + 0x394));
    subtract_vector(&diff, &pt);
    return ((f32 (*)(void *))clamp_velocity__15TObjBoss2TunnelFv)(&diff) <= TBoss1Dragon__data_805D7F50;
}

extern const f32 lbl_805D80B4;

void prepare_flight_destination__12TBoss1DragonFPv(u8 *arg0) {
    extern u8 TBoss1Dragon__data_80434E80[0xC];
    if (((s32 (*)(void))isHpPhasePending__12TBoss1DragonFv)() != 0) {
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x394, arg0 + 0x38);
        *(f32 *)((s8 *)arg0 + 0x398) = (f32) TBoss1Dragon__data_805D7F28;
        ((s32 (*)(void *))clamp_velocity__15TObjBoss2TunnelFv)(arg0 + 0x394);
        *(f32 *)((s8 *)arg0 + 0x394) = (f32) (*(f32 *)((s8 *)arg0 + 0x394) * lbl_805D80B4);
        *(f32 *)((s8 *)arg0 + 0x39C) = (f32) (*(f32 *)((s8 *)arg0 + 0x39C) * lbl_805D80B4);
        return;
    }
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x394, TBoss1Dragon__data_80434E80);
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::calc_forward_point(f32 *arg1, f32 *arg2) {
    *arg1 = (lbl_805D80BC * sin_table_lookup(this->rotation_y)) + this->position.x;
    *arg2 = (lbl_805D80BC * cos_table_lookup(this->rotation_y)) + this->position.z;
}
#pragma pop

void calc_target_vector__12TBoss1DragonFPv(u8 *arg0) {
    f32 temp_f1;
    f32 temp_f2;

    temp_f2 = *(f32 *)((s8 *)arg0 + 0x394);
    *(f32 *)((s8 *)arg0 + 0x5C8) = (f32) (temp_f2 - *(f32 *)((s8 *)arg0 + 0x40C));
    *(f32 *)((s8 *)arg0 + 0x5CC) = (f32) TBoss1Dragon__data_805D7F28;
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x39C);
    *(f32 *)((s8 *)arg0 + 0x5D0) = (f32) (temp_f1 - *(f32 *)((s8 *)arg0 + 0x414));
    *(f32 *)((s8 *)arg0 + 0x5D4) = clamp_velocity__15TObjBoss2TunnelFv(arg0 + 0x5C8, temp_f1, temp_f2);
}

void TBoss1Dragon::update_linked_epsilon_position() {
    update_linked_position__12TObjEneDD_STFf(lbl_805D7F30);
}

void TBoss1Dragon::vfunc_88() {
    Vec_80029408 pts[7];
    Vec_80029408 *p;
    f32 lim;
    s32 off;
    s32 i;
    Coll_80029408 *c;
    p = pts;
    VecCopy__FP3VecPC3Vec((s32)p++, (s32)(((u8 *)this) + 0x430));
    VecCopy__FP3VecPC3Vec((s32)p++, (s32)(((u8 *)this) + 0x46C));
    VecCopy__FP3VecPC3Vec((s32)p++, (s32)(((u8 *)this) + 0x454));
    VecCopy__FP3VecPC3Vec((s32)p++, (s32)(((u8 *)this) + 0x43C));
    VecCopy__FP3VecPC3Vec((s32)p++, (s32)(((u8 *)this) + 0x5B0));
    VecCopy__FP3VecPC3Vec((s32)p++, (s32)(((u8 *)this) + 0x4C0));
    VecCopy__FP3VecPC3Vec((s32)p, (s32)(((u8 *)this) + 0x4FC));
    update_local_colliders_from_world(this, pts);
    lim = TBoss1Dragon__data_805D7FAC;
    i = 0;
    off = 0;
    do {
        c = (Coll_80029408 *)(*(u8 * *)&this->bodies + off);
        if (c->local.y >= lim) {
            set_collider_contact_high((u8 *)c);
        } else {
            set_collider_contact_low((u8 *)c);
        }
        i++;
        off += 0x2C;
    } while (i < 7);
    if (this->mode != 9) {
        set_collider_contact_high((u8 *)(*(Coll_80029408 * *)&this->bodies + 3));
        set_collider_contact_high((u8 *)(*(Coll_80029408 * *)&this->bodies + 4));
    }
    (*(Coll_80029408 * *)&this->bodies)[0].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C.value + 0x20);
    (*(Coll_80029408 * *)&this->bodies)[1].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C.value + 0x1C);
    (*(Coll_80029408 * *)&this->bodies)[2].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C.value + 0x1C);
    (*(Coll_80029408 * *)&this->bodies)[3].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C.value + 0x20);
    (*(Coll_80029408 * *)&this->bodies)[4].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C.value + 0x20);
    (*(Coll_80029408 * *)&this->bodies)[5].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C.value + 0x18);
    (*(Coll_80029408 * *)&this->bodies)[6].defense = *(s32 *)((s8 *)TBoss1Dragon__data_804FE17C.value + 0x20);
}

void TBoss1Dragon::update_position_history() {
    s32 arg0 = (s32)this;
    VecCopy__FP3VecPC3Vec(arg0 + 0x2FC, arg0 + 0x430);
    VecCopy__FP3VecPC3Vec(arg0 + 0x74, arg0 + 0x2FC);
}

void TBoss1Dragon::vfunc_61() {  }

void TBoss1Dragon::vfunc_62() {  }

void TBoss1Dragon::vfunc_63() {  }

void TBoss1Dragon::vfunc_28() {  }

void TBoss1Dragon::check_death() {
    if (this->isHpPhasePending() != 0) {
        if (update_max_hp_phase() != 0) {
            return;
        }
        goto block_8;
    }
    if (!(this->flags & 0x800) && ((s32) this->hp <= 0)) {
        if ((s32) this->phase == 1) {
            request_state_change__12TBoss1DragonFPvs(this, 0xC);
            return;
        }
        request_state_change__12TBoss1DragonFPvs(this, 0x15);
        return;
    }
block_8:
    ((DragonVirtualInterface *)this)->m85(this->mode, 0xB);
}

void TBoss1Dragon::choose_next_action() {
    if (this->isHpPhasePending() != 0) {
        if (!(this->flags & 0x400)) {
            if (update_max_hp_phase() == 0) {
                if (check_phase_advance() != 0) {
                    return;
                }
                goto block_12;
            }
        } else {
            goto block_12;
        }
    } else {
        if (!(this->flags & 0x800) && (this->hp <= 0)) {
            if ((s32) this->phase == 1) {
                if ((s32) enable_v2_features != 0) {
                    request_state_change__12TBoss1DragonFPvs(this, 0xC);
                    return;
                }
                transition_enemy_state(0xC);
                return;
            }
            request_state_change__12TBoss1DragonFPvs(this, 0x15);
            return;
        }
block_12:
        if ((s32) lbl_805D4B34 != 0) {
            ((DragonVirtualInterface *) this)->m85(this->mode, 2);
            return;
        }
        if ((s32) *(s32 *)((s8 *)this + 0x760) != 0) {
            ((DragonVirtualInterface *) this)->m85(this->mode, 0xB);
            return;
        }
        ((DragonVirtualInterface *) this)->m85(this->mode, 9);
    }
}

void TBoss1Dragon::clearControlOverride() {
    TBoss1Dragon__data_805D4B38 = 0;
}

void TBoss1Dragon::setControlOverride(s16 controlId) {
    if (enable_v2_features != 0) {
        TBoss1Dragon__data_805D4B3C = controlId;
        TBoss1Dragon__data_805D4B38 = 1;
    }
}

void TBoss1Dragon::requestActionRefresh() {
    lbl_805D4B34 = 1;
}

#include "pso/enemy/TObjEnePanarms.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct VObj_18 : VBase_18_8002985C {
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
    virtual s32 m20(s32, f32);
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {
s32 obj_isState2_324__9TObjCharaFv();
void TBoss1Dragon__sub_8002AB6C(u8 *arg0);
void copy_model_node(u8 *arg0, u8 *arg1);

void TBoss1Dragon__sub_800274A4(s32 arg0) {
    if (objInBand((GameObj *)arg0, TBoss1Dragon__data_805D8018) != 0) {
        ((TBoss1Dragon *)arg0)->update_switch_attack();
    }
}

void TBoss1Dragon__sub_80028AFC(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x3C0) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C0) & 0xFFFFFEFF);
    *(f32 *)((s8 *)arg0 + 0x5D8) = (f32) (lbl_805D800C + *(f32 *)((s8 *)arg0 + 0x3C));
    *(f32 *)((s8 *)arg0 + 0x5DC) = (f32) (lbl_805D800C + *(f32 *)((s8 *)arg0 + 0x5E0));
}

#pragma push
#pragma fp_contract on
void TBoss1Dragon::run_task() {
    s16 temp_r0;
    s16 temp_r3;
    s16 temp_r3_2;
    s16 temp_r3_3;
    s16 temp_r3_4;
    s32 temp_r0_2;
    s32 temp_r30;
    s32 temp_r30_2;
    u8 *arg0 = (u8 *)this;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TBoss1Dragon *)(arg0))->vfunc_105();
        return;
    }
    if (((TBoss1Dragon *)arg0)->flags & 0x40) {
        ((TObjEnemy *)arg0)->send_entity_set_flags();
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if ((s32) *(s32 *)((s8 *)arg0 + 0x760) != 0) {
        ((TBoss1Dragon *)arg0)->hold_captured_player();
        ((TBoss1Dragon *)arg0)->controlTimer = (s32) (((TBoss1Dragon *)arg0)->controlTimer + 1);
    } else if ((is_main_phase_15__9TObjEneDDFv() != 0) && ((s32) *(s32 *)((s8 *)arg0 + 0x6E0) == 0)) {
        temp_r30 = *(s32 *)((s8 *)arg0 + 0x3E0);
        if (((TObjEneDD *)arg0)->update_lobby_state() != 0) {
            *(s32 *)((s8 *)arg0 + 0x3E0) = 0;
            if ((s32) *(s32 *)((s8 *)arg0 + 0x3E0) != temp_r30) {
                *(s32 *)((s8 *)arg0 + 0x8B8) = 1;
            }
        } else {
            *(s32 *)((s8 *)arg0 + 0x3E0) = 1;
        }
    }
    temp_r30_2 = query_teammate_state__9TObjEneDDFv();
    ((TBoss1Dragon *)(arg0))->update_attack_stat_status();
    ((TBoss1Dragon *)(arg0))->update_defense_stat_status();
    if (temp_r30_2 == 0) {
        temp_r0 = ((TBoss1Dragon *)arg0)->mode;
        if ((temp_r0 == 0x15) || (temp_r0 == 0x16)) {
            ((TBoss1Dragon *)arg0)->actorFlags = (s32) (((TBoss1Dragon *)arg0)->actorFlags | 0x800);
        } else {
            ((TBoss1Dragon *)arg0)->actorFlags = (s32) (((TBoss1Dragon *)arg0)->actorFlags & 0xFFFFF7FF);
        }
        if ((s32) *(s32 *)((s8 *)arg0 + 0x760) != 0) {
            if ((s32) *(u16 *)((s8 *)arg0 + 0x764) == (s32) local_client_id) {
                if ((((TBoss1Dragon *)(arg0))->test_flag30_512() != 0) && (isHpPhasePending__12TBoss1DragonFv(arg0) != 0)) {
                    ;
                    if ((s16) ((TBoss1Dragon *)arg0)->hp < (s16) ((TBoss1Dragon *)arg0)->finalHpThreshold) {
                        ((TBoss1Dragon *)arg0)->hp = ((TBoss1Dragon *)arg0)->finalHpThreshold;
                    }
                    ((TObjEneDD *)arg0)->clear_attack_receipts();
                }
                if ((s32) TBoss1Dragon__data_805D4B38 == 0) {
                    ((TBoss1Dragon *)arg0)->release_held_player();
                } else {
                    ((TBoss1Dragon *)arg0)->check_death();
                }
                ((VObj_18_8002985C *)(arg0))->m85(((TBoss1Dragon *)arg0)->mode, 8);
                ((VObj_18_8002985C *)(arg0))->m85(((TBoss1Dragon *)arg0)->mode, 0);
            } else {
                if ((((TBoss1Dragon *)(arg0))->test_flag30_512() != 0) && (isHpPhasePending__12TBoss1DragonFv(arg0) != 0)) {
                    ;
                    if ((s16) ((TBoss1Dragon *)arg0)->hp < (s16) ((TBoss1Dragon *)arg0)->finalHpThreshold) {
                        ((TBoss1Dragon *)arg0)->hp = ((TBoss1Dragon *)arg0)->finalHpThreshold;
                    }
                    ((TObjEneDD *)arg0)->clear_attack_receipts();
                }
                if ((s32) TBoss1Dragon__data_805D4B38 == 0) {
                    ((TBoss1Dragon *)arg0)->release_held_player();
                }
                ((VObj_18_8002985C *)(arg0))->m85(((TBoss1Dragon *)arg0)->mode, 0);
            }
        } else {
            temp_r0_2 = *(s32 *)((s8 *)arg0 + 0x3E0);
            if (temp_r0_2 != 1) {
                if (temp_r0_2 == 2) {
                    ((VObj_18_8002985C *)(arg0))->m85(((TBoss1Dragon *)arg0)->mode, 2);
                } else {
                    if ((((TBoss1Dragon *)(arg0))->test_flag30_512() != 0) && (isHpPhasePending__12TBoss1DragonFv(arg0) != 0)) {
                        ;
                        if ((s16) ((TBoss1Dragon *)arg0)->hp < (s16) ((TBoss1Dragon *)arg0)->finalHpThreshold) {
                            ((TBoss1Dragon *)arg0)->hp = ((TBoss1Dragon *)arg0)->finalHpThreshold;
                        }
                        ((TObjEneDD *)arg0)->clear_attack_receipts();
                    }
                    ((TBoss1Dragon *)arg0)->choose_next_action();
                }
                ((VObj_18_8002985C *)(arg0))->m85(((TBoss1Dragon *)arg0)->mode, 8);
                ((VObj_18_8002985C *)(arg0))->m85(((TBoss1Dragon *)arg0)->mode, 0);
            } else {
                if ((((TBoss1Dragon *)(arg0))->test_flag30_512() != 0) && (isHpPhasePending__12TBoss1DragonFv(arg0) != 0)) {
                    ;
                    if ((s16) ((TBoss1Dragon *)arg0)->hp < (s16) ((TBoss1Dragon *)arg0)->finalHpThreshold) {
                        ((TBoss1Dragon *)arg0)->hp = ((TBoss1Dragon *)arg0)->finalHpThreshold;
                    }
                    ((TObjEneDD *)arg0)->clear_attack_receipts();
                }
                ((VObj_18_8002985C *)(arg0))->m85(((TBoss1Dragon *)arg0)->mode, 0);
            }
        }
    }
    ((TObjEneDD *)arg0)->sub_800BBA0C();
    ((TBoss1Dragon *)(arg0))->vfunc_88();
    ((TBoss1Dragon *)arg0)->update_position_history();
    ((TBoss8Dragon *)arg0)->set_player_state_default();
    add_radar_scaled_marker((u8 *)&this->position, -0x5DB4, 1, 1, (f32) ((*(f32 *)&TBoss1Dragon__data_805D7F24)));
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x648), (s32)(arg0 + 0x2FC));
    if (temp_r30_2 == 0) {
        ((TObject *)(arg0 + 0x3C4))->run_tasks();
    }
    project_sound_origin_from_camera((s32)(arg0 + 0x38), (u8 *)(arg0 + 0x63C), lbl_805D80C0);
}
#pragma pop

Obj_80029C78 *destroy__12TBoss1DragonFPvs(Obj_80029C78 *o, s16 flag) {
    if (o != 0) {
        o->vt = lbl_80481280;
        if (o->f774 != 0) {
            delete o->f774;
            o->f774 = 0;
        }
        if (o->f6D8 != 0) {
            queue_destruction__7TObjectFv(o->f6D8);
            o->f6D8 = 0;
        }
        if (o->f68C != 0) {
            delete o->f68C;
            o->f68C = 0;
        }
        if (o->f688 != 0) {
            delete_buffer__12TBoss8DragonFis((s32)o->f688, 1);
            o->f688 = 0;
        }
        if (o->f684 != 0) {
            delete o->f684;
            o->f684 = 0;
        }
        free_collision_body_parts(o);
        if ((Obj_80029C78 *)TBoss1Dragon__data_805D4B2C == o) {
            TBoss1Dragon__data_805D4B2C = 0;
        }
        __destroy_arr(o->f6E8, (void *)__dt__13TUnk_804949A8Fv, 0x1c, 4);
        TObjBoss2Tunnel::maybe_delete((s32)o->f618, (s16)(-1));
        TObjBoss2Tunnel::maybe_delete((s32)o->f5F4, (s16)(-1));
        __dt__7TObjectFv(o->f3C4, -1);
        __dt__12TObjEneDD_STFv(o, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(o);
        }
    }
    return o;
}

#define F_29DE4(o, T, off) (*(T *)(o + (off)))
#define O_29DE4 ((Obj_80029DE4 *)arg0)
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
u8 *TBoss1Dragon__ct(u8 *arg0, void *arg1, void *arg2) {
    u32 sp8[3];
    s32 i;
    s32 j;
    void *p;

    init_object__12TObjEneDD_STFv(arg0, arg1);
    F_29DE4(arg0, s32, 0x18) = (s32)lbl_80481280;
    __ct__7TObjectFP7TObject(arg0 + 0x3C4, 0);
    TObjBoss2Tunnel::reset_coords_pass((s32)(arg0 + 0x5F4));
    TObjBoss2Tunnel::reset_coords_pass((s32)(arg0 + 0x618));
    __construct_array(arg0 + 0x6E8, init_and_activate__10TObjPlayerFv, __dt__13TUnk_804949A8Fv, 0x1C, 4);
    __ct__14SubtractiveRngFv(arg0 + 0x77C);
    F_29DE4(arg0, s32, 0) = lbl_805D2650;
    if ((u32)TBoss1Dragon__data_805D4B2C == 0U) {
        TBoss1Dragon__data_805D4B2C = (s32)arg0;
    }
    invoke_initialization_hook__9TObjEneDDFv(arg0, arg2);
    F_29DE4(arg0, s32, 0x3C0) = 0;
    if (((TObjEnemy *)arg0)->exchange_object_state((s32)sp8, (s16)1) != 0 && (sp8[0] & 0x12008) == 0x12008) {
        F_29DE4(arg0, s32, 0x3C0) |= 0x40;
    }
    ((TObjEneDD *)arg0)->init_position_vectors();
    F_29DE4(arg0, s32, 0x34) = F_29DE4(F_29DE4(TBoss1Dragon__data_805D4B08, u8 *, 0x42C), s32, 8);
    F_29DE4(arg0, s32, 0x24) = F_29DE4(F_29DE4(TBoss1Dragon__data_805D4B08, u8 *, 0x42C), s32, 0xC);
    init_model__9TObjEneDDFv(arg0, (void *)boss1_dragon_collision_body_parts, 7);
    F_29DE4(arg0, s32, 0xB0) = 0;
    ((TObjMotion *)arg0)->set_field_d8((s32)((void *)lbl_80481010));
    ((TObjMotion *)arg0)->set_field_dc(F_29DE4(TBoss1Dragon__data_805D4B08, u32, 0x430));
    F_29DE4(arg0, s16, 0xB8) = 0;
    ((TObjMotion *)arg0)->set_animation(F_29DE4(arg0, s16, 0xB8));
    ((TObjMotion *)arg0)->set_field_b8(F_29DE4(arg0, s16, 0xB8));
    reset_hp__9TObjEneDDFv(arg0, (&TBoss1Dragon__data_805D4B00)[boss1_dragon_base_stat_indices[0]],
                            ((s32 *)&TBoss1Dragon__part_hp_stats)[boss1_dragon_attack_stat_indices[0]],
                            (&TBoss1Dragon__data_805D4B04)[boss1_dragon_resistance_stat_indices[0]]);
    ((TObjEneDD *)arg0)->check_state_flag_1();
    F_29DE4(arg0, s32, 0x350) = (s32)boss1_dragon_init_params;
    initialize_enemy_state__9TObjEneDDFv(arg0, 0x2C);
    F_29DE4(arg0, f32, 0x37C) = TBoss1Dragon__data_805D7F1C;
    ((TObjEneDD_ST *)arg0)->enemy_init_acquire_period(10);
    ((TObjEneDD_ST *)arg0)->enemy_init_validate_period(10);
    F_29DE4(arg0, s32, 0x3E4) = 0;
    F_29DE4(arg0, s32, 0x3C0) |= 0x100;
    for (i = 0; i < 3; i++) {
        VecCopy__FP3VecPC3Vec((s32)&O_29DE4->v3[i], (s32)&O_29DE4->pos);
    }
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x40C), (s32)&O_29DE4->pos);
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x418), (s32)&O_29DE4->pos);
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x424), (s32)&O_29DE4->pos);
    for (i = 0; i < 0x22; i++) {
        VecCopy__FP3VecPC3Vec((s32)&O_29DE4->v22[i], (s32)&O_29DE4->pos);
    }
    F_29DE4(arg0, f32, 0x5C8) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x5CC) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x5D0) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x5D4) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x5D8) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x5E0) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x5DC) = F_29DE4(arg0, f32, 0x5E0);
    F_29DE4(arg0, f32, 0x5E4) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x5E8) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x5EC) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x5F0) = TBoss1Dragon__data_805D7F28;
    ((TObjBoss2Tunnel *)(arg0 + 0x5F4))->reset_coords();
    ((TObjBoss2Tunnel *)(arg0 + 0x618))->reset_coords();
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x63C), (s32)&O_29DE4->pos);
    VecCopy__FP3VecPC3Vec((s32)(arg0 + 0x648), (s32)&O_29DE4->pos);
    F_29DE4(arg0, s32, 0x654) = 0;
    F_29DE4(arg0, s32, 0x658) = 0;
    F_29DE4(arg0, s32, 0x65C) = 1;
    F_29DE4(arg0, f32, 0x664) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x668) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x678) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, s32, 0x67C) = 0;
    F_29DE4(arg0, s16, 0x680) = 0;
    F_29DE4(arg0, s16, 0x682) = F_29DE4(arg0, s16, 0x2B8) * 3 / 10;
    F_29DE4(F_29DE4(arg0, u8 *, 0x2B0), f32, 0x10) = TBoss1Dragon__data_805D8010;
    ((void (*)(void *))update_damage_threshold__12TBoss1DragonFv)(arg0);
    p = __nw__7TObjectFUl(0xCC);
    if (p != 0) {
        p = TBoss1DragonEffTail__ct(p, arg0, arg0 + 0x4E4);
    }
    F_29DE4(arg0, void *, 0x684) = p;
    p = ::operator new(0x10);
    if (p != 0) {
        p = TBoss8Dragon__sub_800BC5EC((u8 *)p, 4);
    }
    F_29DE4(arg0, void *, 0x688) = p;
    p = __nw__7TObjectFUl(0x28);
    if (p != 0) {
        p = TBoss1DragonColli__ct((u8 *)p, (s32)(arg0 + 0x3C4));
    }
    F_29DE4(arg0, void *, 0x68C) = p;
    F_29DE4(arg0, f32, 0x690) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x694) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x698) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x69C) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, s32, 0x6A0) = 0;
    F_29DE4(arg0, s32, 0x6A4) = 0;
    for (i = 0; i < 12; i++) {
        O_29DE4->f[i] = TBoss1Dragon__data_805D7F28;
    }
    p = __nw__7TObjectFUl(0x40);
    if (p != 0) {
        p = TObjBoss1MokoHill_SoloM__ct((u8 *)p, (u8 *)tl_05, (u8 *)(arg0 + 0x38), (s32)(arg0 + 0x60));
    }
    F_29DE4(arg0, void *, 0x6D8) = p;
    F_29DE4(arg0, void *, 0x6DC) = 0;
    for (j = 0; j < 4; j++) {
        ((TObjPlayer *)(&O_29DE4->e[j]))->activate_and_dispatch();
    }
    F_29DE4(arg0, s32, 0x758) = 0;
    F_29DE4(arg0, s32, 0x75C) = 0xA8C;
    F_29DE4(arg0, s32, 0x760) = 0;
    F_29DE4(arg0, u16, 0x764) = 0xFFFF;
    F_29DE4(arg0, s32, 0x768) = 0;
    F_29DE4(arg0, s32, 0x76C) = 0;
    switch (isV2Mode__12TBoss1DragonFv()) {
    case 0:
        F_29DE4(arg0, s32, 0x770) = 1;
        F_29DE4(arg0, u8 *, 0x778) = boss1_dragon_normal_action_table;
        break;
    case 1:
        F_29DE4(arg0, s32, 0x770) = 0x13;
        F_29DE4(arg0, u8 *, 0x778) = boss1_dragon_normal_particle_table;
        break;
    }
    p = __nw__7TObjectFUl(0xB0);
    if (p != 0) {
        p = ((void *(*)(void *, s32, void *))init_base__13TUnk_80481B34Fv)(p, 0, arg0);
    }
    F_29DE4(arg0, void *, 0x774) = p;
    F_29DE4(arg0, s32, 0x864) = 0;
    F_29DE4(arg0, s32, 0x868) = 0;
    F_29DE4(arg0, s32, 0x86C) = 0;
    F_29DE4(arg0, s32, 0x870) = 0;
    F_29DE4(arg0, s32, 0x874) = 0;
    F_29DE4(arg0, s32, 0x878) = 0;
    F_29DE4(arg0, f32, 0x87C) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x880) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x884) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x888) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x88C) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x890) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x894) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x898) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x89C) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x8A0) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, f32, 0x8A4) = TBoss1Dragon__data_805D7F28;
    F_29DE4(arg0, s32, 0x8A8) = 0;
    F_29DE4(arg0, s32, 0x8AC) = 0;
    F_29DE4(arg0, s32, 0x8B0) = 0;
    F_29DE4(arg0, s32, 0x8B4) = 0;
    F_29DE4(arg0, u8 *, 0x6E4) = controller_input_state + 0xC0;
    F_29DE4(arg0, s32, 0x6E0) = 0;
    F_29DE4(arg0, s16, 0x326) = 0;
    if (is_main_phase_15__9TObjEneDDFv() != 0) {
        if (((TObjEneDD *)arg0)->update_lobby_state() != 0) {
            F_29DE4(arg0, s32, 0x3E0) = 0;
        } else {
            F_29DE4(arg0, s32, 0x3E0) = 1;
        }
    } else {
        F_29DE4(arg0, s32, 0x3E0) = 0;
    }
    ((TBoss1Dragon *)arg0)->resetHpPhase();
    F_29DE4(arg0, s16, 0x326) = 0x1D;
    if (!(F_29DE4(arg0, s32, 0x3C0) & 0x40)) {
        ((VObj_80029DE4 *)arg0)->m85(F_29DE4(arg0, s16, 0x326), 4);
    }
    F_29DE4(arg0, s32, 0x8B8) = 0;
    return arg0;
}
#pragma pop
#undef F_29DE4
#undef O_29DE4

void TBoss1Dragon::free_resources() {
    if ((u32) TBoss1Dragon__data_805D4B28 != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)TBoss1Dragon__data_805D4B28));
        TBoss1Dragon__data_805D4B28 = 0U;
    }
    if ((u32) TBoss1Dragon__data_805D4B08 != 0U) {
        TLobby__sub_8001FE7C((void*)TBoss1Dragon__data_805D4B08, 1);
        TBoss1Dragon__data_805D4B08 = 0U;
    }
}

u8 *TBoss1Dragon::create(s32 arg0) {
    u8 *temp_r3;
    u8 *var_r0;
    TBoss4DarkFalz::dispatch_by_main_phase(0x16);
    temp_r3 = (u8 *)(__nw__7TObjectFUl(0x8BC));
    var_r0 = temp_r3;
    if (var_r0 != NULL) {
        var_r0 = (u8 *)(((u8 *(*)(void *, s32, s32))TBoss1Dragon__ct)(temp_r3, tl_04, arg0));
    }
    return var_r0;
}
}

#pragma push
#pragma fp_contract on
void calc_follow_camera_offsets__12TBoss1DragonFv(TBoss1Dragon *self, Vec *eye, Vec *target) {
    s32 phase;
    Vec *limit;

    if (((TBoss1Dragon *)TBoss1Dragon__data_805D4B2C)->mode == 0x16) {
        VecCopy(eye, (Vec *)boss1_dragon_follow_camera_offsets);
        VecCopy(target, (Vec *)lbl_804811CC);
        return;
    }
    switch (self->phase) {
    case 0:
    default:
        phase = 0;
        break;
    case 1:
        phase = 1;
        break;
    case 2:
        phase = 2;
        break;
    }
    VecCopy(eye, (Vec *)boss1_dragon_follow_camera_phase_positions + phase);
    VecCopy(target, (Vec *)boss1_dragon_follow_camera_phase_targets + phase);
    if (*(u32 *)((s8 *)self + 0x654) == 1) {
        target->y += TBoss1Dragon__data_805D8010;
        target->z += TBoss1Dragon__data_805D8010;
    }
    if (*(s32 *)((s8 *)self + 0x760) != 0 && *(u16 *)((s8 *)self + 0x764) == local_client_id) {
        if (self->mode == 0xF) {
            VecCopy(eye, (Vec *)boss1_dragon_held_camera_positions + 3);
            limit = (Vec *)boss1_dragon_held_camera_targets + 3;
            eye->y += TBoss1Dragon__data_805D7F48 * self->height;
            VecCopy(target, limit);
            target->x = TBoss1Dragon__data_805D7F28;
            target->y += self->height;
            if (target->y > limit->x) {
                target->y = limit->x;
            } else if (target->y < TBoss1Dragon__data_805D8010) {
                target->y = TBoss1Dragon__data_805D7F40;
            }
        } else {
            VecCopy(eye, (Vec *)boss1_dragon_held_camera_positions + phase);
            VecCopy(target, (Vec *)boss1_dragon_held_camera_targets + phase);
        }
        eye->y += lbl_805D8090;
        target->y += lbl_805D8090;
    }
}
#pragma pop

typedef char RecoveredGlobal_80065EA0_lbl_80487CCC_size[sizeof(RecoveredGlobal_80065EA0_lbl_80487CCC) == 0xC ? 1 : -1];
typedef char RecoveredGlobal_80065EA0_lbl_80487CD8_size[sizeof(RecoveredGlobal_80065EA0_lbl_80487CD8) == 0x354 ? 1 : -1];
typedef char RecoveredGlobal_80065DB4_lbl_804FF5B4_size[sizeof(RecoveredGlobal_80065DB4_lbl_804FF5B4) == 0xC ? 1 : -1];
void get_dragon_follow_camera_offsets(u8 *arg0, u8 *arg1) {
    if ((void *) (*(u8 * *)&TBoss1Dragon__data_805D4B2C) == NULL) {
        VecCopy__FP3VecPC3Vec((s32)arg0, (s32)(((s32 *)boss1_dragon_follow_camera_offsets)));
        VecCopy__FP3VecPC3Vec((s32)arg1, (s32)(((s32 *)lbl_804811CC)));
        return;
    }
    calc_follow_camera_offsets__12TBoss1DragonFv((TBoss1Dragon *)TBoss1Dragon__data_805D4B2C, (Vec *)arg0, (Vec *)arg1);
}
typedef char RecoveredGlobal_80065F08_lbl_80437938_size[sizeof(RecoveredGlobal_80065F08_lbl_80437938) == 0xC ? 1 : -1];

s32 TBoss1Dragon::get_instance() {
    return TBoss1Dragon__data_805D4B2C;
}

void TUnk_80481B34::apply_hit_if_active(void *arg1, f32 *) {
    ((VObj_18 *)(((u8 *)arg1)))->m20(this->m_ac, TBoss1Dragon__data_805D7F40);
    TBoss1Dragon__sub_8002AB6C(((u8 *)arg1));
}

void TUnk_80481B34::area_attack_receive_direct(void *self_arg, f32 *arg2, void *arg3_arg) {
    VObj_18_5c1903 *self = (VObj_18_5c1903 *)self_arg;
    s32 *arg3 = (s32 *)arg3_arg;
    s32 off;
    s32 i;
    Ent_8002AACC *e;

    off = 0;
    for (i = 0; i < self->count; i++) {
        e = (Ent_8002AACC *)((u8 *)self->ents + off);
        if (e->flags & 0x04000000) {
            V2_8002AACC sp8 = *(V2_8002AACC *)arg3;
            self->m21(((Src_8002AACC *)this)->fAC, (s32 *)&sp8, e, -1, -1);
            TBoss1Dragon__sub_8002AB6C((u8 *)self);
            return;
        }
        off += 0x2C;
    }
}

void TBoss1Dragon__sub_8002AB6C(u8 *arg0) {
    if (obj_isState2_324__9TObjCharaFv() == 0) {
        ((VObj_18_5c4a6f *)(arg0))->m46(0);
    }
}

void *TUnk_80481B34::dt(s16 arg1) {
    if (this != NULL) {
        (*(s32 * *)((u8 *)this + 0x18)) = lbl_80481B34;
        destroy_enemy_object(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(this);
        }
    }
    return this;
}

void *TUnk_80481B34::init_base() {
    construct_collision_body(this);
    *(s32 **)((s8 *)this + 0x18) = lbl_80481B34;
    return this;
}

DragonModelNode* TBoss1Dragon::cloneModelHierarchy(DragonModelNode* source, DragonModelNode* output, void* model) {
    DragonModelNode* current = output;
    ++output;
    copy_model_node((u8*)current, (u8*)source);
    current->model = model;
    if (source->child != 0) {
        current->child = output;
        output = cloneModelHierarchy(source->child, output, model);
    }
    if (source->sibling != 0) {
        current->sibling = output;
        output = cloneModelHierarchy(source->sibling, output, model);
    }
    return output;
}

void copy_model_node(u8 *arg0, u8 *arg1) {
    *(s32 *)((s8 *)arg0 + 0) = (s32) *(s32 *)((s8 *)arg1 + 0);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(ByteBlock_C *)((s32) arg0 + 8) = *(const ByteBlock_C *)((s32) arg1 + 8);
    *(ByteBlock_C *)((s32) arg0 + 0x14) = *(const ByteBlock_C *)((s32) arg1 + 0x14);
    *(ByteBlock_C *)((s32) arg0 + 0x20) = *(const ByteBlock_C *)((s32) arg1 + 0x20);
    *(s32 *)((s8 *)arg0 + 0x2C) = (s32) *(s32 *)((s8 *)arg1 + 0x2C);
    *(s32 *)((s8 *)arg0 + 0x30) = (s32) *(s32 *)((s8 *)arg1 + 0x30);
    *(f32 *)((s8 *)arg0 + 0x34) = (f32) *(f32 *)((s8 *)arg1 + 0x34);
}

s32 TBoss1Dragon::countModelNodes(DragonModelNode* source) {
    s32 count=1;
    DragonModelNode* child=source->child;
    if(child!=0)count=countModelNodes(child)+1;
    DragonModelNode* sibling=source->sibling;
    if(sibling!=0)count+=countModelNodes(sibling);
    return count;
}

void TBoss1Dragon::apply_poison_status() {  }

void TBoss1Dragon::apply_paralysis() {  }

void TBoss1Dragon::apply_slow_status() {  }

void TBoss1Dragon::apply_confusion_status() {  }

void TBoss1Dragon::apply_movement_ailment(s32) {  }

void TBoss1Dragon::apply_shock_status() {  }

void TBoss1Dragon::clear_harmful_statuses() {  }
