#include "pso/enemy/TObjEnemy.h"
#include "pso/system/vector.h"
#include "types.h"
#include "pso/enemy/TObjEneBm3FlyNest_CarryFly.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjChara.h"
#include "pso/enemy/TObjEneBm3Fly.h"
#include "pso/enemy/TObjEneDD.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEneBm3FlyNest.h"

extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();

#include "pso/enemy/TObjEneDD_ST.h"
#include <stddef.h>
#include "pso/TObject.h"
#include "pso/TParticleCtrl.h"
#include "pso/boss/TBoss8Dragon.h"
#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/enemy/TObjEnePanarms.h"
#include "pso/enemy/TObjEneRe7Berura.h"
#include "pso/misc/RenderFadeState.h"
#include "pso/misc/TLobby.h"

#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct VBase_800B3EB8 { char pad[0x18]; };
struct VObj_800B3EB8 : VBase_800B3EB8 {
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
    virtual void m85(s16, int);
    virtual void m86();
};

extern const f32 lbl_805D9D6C;

extern "C" {

struct VBase_18_6eb1ad
{
  char pad[0x18];
};

struct VObj_18_6eb1ad : VBase_18_6eb1ad {
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
    virtual s32 m81();
    virtual void m82();
    virtual s32 m83();
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
    virtual s32 m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual void m102();
    virtual s32 m103();
};

struct RecoveredGlobal_800B22C8_lbl_8043B0FC {
    s32 value;
    u8 remaining[0xC];
};

struct RecoveredGlobal_800B22C8_lbl_80491B4C {
    s32 value;
    u8 remaining[0x28];
};

struct RecoveredGlobal_800B2168___vt__13TObjEneBm3Fly {
    s32 value;
    u8 remaining[0x1A8];
};

struct VBase_18_800B23A0 { char pad[0x18]; };

struct VObj_18_800B23A0 : VBase_18_800B23A0 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Vec_800B23A0 { s32 x, y, z; };

struct Ent_800B23A0 { s32 a; u32 count; };

struct Pair_800B23A0 { s32 k; Ent_800B23A0 *e; };

typedef struct VBase_18_6eb1ad VBase_18_6eb1ad;

typedef struct VObj_18_6eb1ad VObj_18_6eb1ad;

typedef char RecoveredGlobal_800B2168___vt__13TObjEneBm3Fly_size[sizeof(RecoveredGlobal_800B2168___vt__13TObjEneBm3Fly) == 0x1AC ? 1 : -1];

typedef char RecoveredGlobal_800B22C8_lbl_8043B0FC_size[sizeof(RecoveredGlobal_800B22C8_lbl_8043B0FC) == 0x10 ? 1 : -1];

typedef char RecoveredGlobal_800B22C8_lbl_80491B4C_size[sizeof(RecoveredGlobal_800B22C8_lbl_80491B4C) == 0x2C ? 1 : -1];

struct RecoveredGlobal_800B2948_lbl_8043B2A4 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_800B2948_lbl_80500B00 {
    s32 value;
    u8 remaining[0x3C];
};

struct NestAttachmentPoint { f32 x,y,z; };

struct Obj_800B2A5C { u8 pad[0x3b0]; s32 count; u8 pad2[4]; u16 ids[6]; };

struct Obj_800B2AF4 { u8 pad[0x3b0]; s32 count; u8 pad2[4]; u16 ids[6]; };

struct VBase_14_aa9368 { char pad[0x14]; };

struct VObj_14_aa9368 : VBase_14_aa9368 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
    virtual s32 m7();
};

struct VBase_18_113a45 { char pad[0x18]; };

struct VObj_18_113a45 : VBase_18_113a45 {
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
    virtual s32 m103();
};

struct Vec_800B264C { f32 x, y, z; };

struct Cam_800B264C { u8 b[0x1C]; };

struct Nest_800B264C {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0x38 - 0x28];
    u8 f38[0x60 - 0x38];
    s32 f60;
    u8 pad64[0x2FC - 0x64];
    Vec_800B264C f2FC;
    u8 pad308[0x326 - 0x308];
    s16 f326;
    u8 pad328[0x3AC - 0x328];
    s32 f3AC;
    u8 pad3B0[0x3C8 - 0x3B0];
    Vec_800B264C f3C8;
    u8 pad3D4[0x3E0 - 0x3D4];
    u8 f3E0[0x440 - 0x3E0];
    Cam_800B264C cams[4];
    f32 f4B0;
};

struct Vec_800B2C24 { f32 x, y, z; };

struct Base_800B2BAC_800B2A14 { char pad[0x18]; };

struct VObj_800B2BAC_800B2A14 : Base_800B2BAC_800B2A14 {
    virtual void m0();
    virtual void m1();  virtual void m2();  virtual void m3();  virtual void m4();
    virtual void m5();  virtual void m6();  virtual void m7();  virtual void m8();
    virtual void m9();  virtual void m10(); virtual void m11(); virtual void m12();
    virtual void m13(); virtual void m14(); virtual void m15(); virtual void m16();
    virtual void m17(); virtual void m18(); virtual void m19(); virtual void m20();
    virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28();
    virtual void m29(); virtual void m30(); virtual void m31(); virtual void m32();
    virtual void m33(); virtual void m34(); virtual void m35(); virtual void m36();
    virtual void m37(); virtual void m38(); virtual void m39(); virtual void m40();
    virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48();
    virtual void m49(); virtual void m50(); virtual void m51(); virtual void m52();
    virtual void m53(); virtual void m54(); virtual void m55(); virtual void m56();
    virtual void m57(); virtual void m58(); virtual void m59(); virtual void m60();
    virtual void m61(); virtual void m62(); virtual void m63(); virtual void m64();
    virtual void m65(); virtual void m66(); virtual void m67(); virtual void m68();
    virtual void m69(); virtual void m70(); virtual void m71(); virtual void m72();
    virtual void m73(); virtual void m74(); virtual void m75(); virtual void m76();
    virtual void m77(); virtual void m78(); virtual void m79(); virtual void m80();
    virtual void m81(); virtual void m82(); virtual void m83(); virtual void m84();
    virtual void m85(); virtual void m86(); virtual void m87(); virtual void m88();
    virtual void m89(); virtual void m90(); virtual void m91(); virtual void m92();
    virtual void m93();
};

typedef char RecoveredGlobal_800B2948_lbl_8043B2A4_size[sizeof(RecoveredGlobal_800B2948_lbl_8043B2A4) == 0x20 ? 1 : -1];

typedef char RecoveredGlobal_800B2948_lbl_80500B00_size[sizeof(RecoveredGlobal_800B2948_lbl_80500B00) == 0x40 ? 1 : -1];

struct Base_800B3428_800B30B0 { char pad[0x18]; };

struct VObj_800B3428_800B30B0 : Base_800B3428_800B30B0 {
virtual void f151();
virtual void f152();
virtual void f153();
virtual void f154();
virtual void f155();
virtual void f156();
virtual void f157();
virtual void f158();
virtual void f159();
virtual void f160();
virtual void f161();
virtual void f162();
virtual void f163();
virtual void f164();
virtual void f165();
virtual void f166();
virtual void f167();
virtual void f168();
virtual void f169();
virtual void f170();
virtual void f171();
virtual void f172();
virtual void f173();
virtual void f174();
virtual void f175();
virtual void f176();
virtual void f177();
virtual void f178();
virtual void f179();
virtual void f180();
virtual void f181();
virtual void f182();
virtual void f183();
virtual void f184();
virtual void f185();
virtual void f186();
virtual void f187();
virtual void f188();
virtual void f189();
virtual void f190();
virtual void f191();
virtual void f192();
virtual void f193();
virtual void f194();
virtual void f195();
virtual void f196();
virtual void f197();
virtual void f198();
virtual void f199();
virtual void f200();
virtual void f201();
virtual void f202();
virtual void f203();
virtual void f204();
virtual void f205();
virtual void f206();
virtual void f207();
virtual void f208();
virtual void f209();
virtual void f210();
virtual void f211();
virtual void f212();
virtual void f213();
virtual void f214();
virtual void f215();
virtual void f216();
virtual void f217();
virtual void f218();
virtual void f219();
virtual void f220();
virtual void f221();
virtual void f222();
virtual void f223();
virtual void f224();
virtual void f225();
virtual void f226();
virtual void f227();
virtual void f228();
virtual void f229();
virtual void f230();
virtual void f231();
virtual void f232();
virtual void f233();
virtual void f234();
virtual void f235();
virtual void f236();
virtual void f237();
virtual void f238();
virtual void f239();
virtual void f240();
virtual void f241();
virtual void f242();
virtual void f243();
virtual void f244();
    virtual void m94();
virtual void f246();
virtual void f247();
virtual void f248();
virtual void f249();
virtual void f250();
    virtual void m100();
};

struct Stack_800B318C {
    f32 sp8;
    u8 pad_C[0x4];
    f32 sp10;
};

struct VBase_18 { char pad[0x18]; };

struct Elem_800B36F8 { f32 x, y, z; };

struct Self_800B36F8 { u8 pad[0x3E0]; Elem_800B36F8 arr[6]; };

struct VObj_18_p5 : VBase_18 {
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
    virtual s32 m81();
    virtual void m82();
    virtual s32 m83();
    virtual void m84();
    virtual void m85();
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
    virtual s32 m98();
    virtual void m99();
    virtual void m100();
    virtual void m101();
    virtual s32 m102();
};

struct Obj_800B3E40 { u8 pad[0x18]; void *vtbl; u8 pad2[0x440 - 0x1c]; u8 arr[4][0x1c]; };

typedef struct Vec_800B39CC {
    f32 x, y, z;
} Vec_800B39CC;

typedef struct Nest_800B39CC {
    u8 pad0[0x2C];
    s16 f2C;
    u8 pad2E[0x38 - 0x2E];
    Vec_800B39CC pos;
    u8 pad44[0x3B0 - 0x44];
    s32 count;
    s32 spawned;
    u16 ids[6];
    u16 nextId;
    u8 pad3C6[0x3D4 - 0x3C6];
    u8 f3D4[0xC];
} Nest_800B39CC;

struct Anim_800B41E8 { s32 motions, actions, initial_action, counts; };

struct Vec_800B41E8 { f32 x, y, z; };

struct Res_800B41E8 { u8 pad[0x42C]; u8 *bodies; s32 motions; };

struct Bodies_800B41E8 { u8 pad0[0xC]; s32 textures; u8 pad1[0x18 - 0x10]; s32 model; };

struct Vec_800B4688 { f32 x, y, z; };

struct Vec_800B4388 { f32 x, y, z; };

s32 is_split_screen();
f32 atan2_float(f32 y, f32 x);
void queue_destruction__7TObjectFv(void *);
s32 dispatch_shared_handler_a__6TLobbyFl(int);
s32 register_object__6TLobbyFl(int);
s32 dispatch_shared_handler_b__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
void TLobby__sub_8001FE7C(void*, int);
s32 get_camera_mode__11TCameraCtrlFv();
s32 get_flag_b4__9TObjEneDDFv(void *);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2);
void *spawn_particle_effect(void *pos, s32 id);
void render_with_state_debug__17TObjEneBm3FlyNestFv(u8 *arg0);
void render__17TObjEneBm3FlyNestFv(u8 *arg0);
void handle_attachment_sample__17TObjEneBm3FlyNestFi(s32 arg0);
int copy_target_state__17TObjEneBm3FlyNestFPv(void* p, s32 sound_id);
void* TObjEneBm3FlyNest__sub_800B2A54(void* p);
void handle_state__17TObjEneBm3FlyNestFPvi(void *arg0, s32 arg1);
void state_dying__17TObjEneBm3FlyNestFPvi(u8 *arg0, s32 arg1);
void handle_motion_event__17TObjEneBm3FlyNestFPvi(u8 *arg0, s32 arg1);
void state_spawn__17TObjEneBm3FlyNestFPvi(void *arg0, s32 arg1);
void update_state__17TObjEneBm3FlyNestFPvi(void *arg0, s32 arg1);
void TObjEneBm3FlyNest__sub_800B318C(u8 *arg0, s32 arg1);
void handle_event__17TObjEneBm3FlyNestFPvi(void *arg0, s32 arg1);
void state_wait__17TObjEneBm3FlyNestFPvi(void *arg0, s32 arg1);
void handle_appear__17TObjEneBm3FlyNestFPvi(u8 *arg0, s32 arg1);
void init_params__17TObjEneBm3FlyNestFv(void *arg0);
s32 TObjEneBm3FlyNest__sub_800B3AC8(u8 *arg0);
void vfunc_88__17TObjEneBm3FlyNestFv(void* p);
void vfunc_61__17TObjEneBm3FlyNestFv(void);
void vfunc_62__17TObjEneBm3FlyNestFv(void *arg0);
void vfunc_63__17TObjEneBm3FlyNestFv(void *arg0);
void vfunc_28__17TObjEneBm3FlyNestFv(void);
void dispatch_state__17TObjEneBm3FlyNestFiUii(s32 arg0, u32 arg1, s32 arg2);
void run_task__17TObjEneBm3FlyNestFv(u8 *arg0);
Obj_800B3E40 * TObjEneBm3FlyNest__sub_800B3E40(Obj_800B3E40 *self, s16 flag);
void * TObjEneBm3FlyNest__ct(void *, void *, void *);
int TObjEneBm3FlyNest__sub_800B4158(void);
void * __dt__26TObjEneBm3FlyNest_CarryFlyFv(void *arg0, s16 arg1);
u8 * __ct__26TObjEneBm3FlyNest_CarryFlyFP7TObjectlllll(u8 *self, void *parent, s32 a, s32 b, s32 unused, s32 c, s32 d);
s32 is_main_phase_15__9TObjEneDDFv();
void update_player_state__9TObjEneDDFv(void *, Vec_800B23A0 *, s32);
void get_camera_ctrl__9TObjEneDDFv(s32, s32);
s32 get_random_scaled__9TObjEneDDFv(void *);
f32 rand_range__9TObjEneDDFff(void *, f32, f32);
s32 clear_attack_receipts__9TObjEneDDFv();
s32 noop__12TBoss8DragonFv(void *);
s32 TBoss8Dragon__sub_800BB7D4(void *, s32);
s32 pack_debug_text_position(s32, s32);
u32 load_enemy_bml_resource_named(void *, void *);
s32 load_enemy_bml_resource(u8 *arg0);
s32 transition_enemy_state__9TObjEneDDFl(void *, s32);
void *__dt__9TObjEneDDFv(void *arg0, s16 arg1);
s32 update__15RenderFadeStateFv(void *);
void *__dt__15RenderFadeStateFv(void *arg0, s16 arg1);
s32 set_field_e4__10TObjPlayerFll(void *, int, f32);
void spawn_dead_spot_scale15(s32 point, s32 delay);
s32 is_passing_frame__10TObjMotionFf(void *, f32);
s32 advance_animation_playback(void *);
void *find_entity_by_id(u16 id);
void free_collision_body_parts(void *);
s32 send_entity_set_flags__9TObjEnemyFv();
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
s32 play_sound_effect(void *, void *, int, int);
s32 defer_render__7TObjectFv(void *);
void __dl__7TObjectFPv(void *);
void * __nw__7TObjectFUl(int);
void __dt__7TObjectFv(void *, int);
void __destroy_arr(void *, void *, u32, u32);
f32 sin_table_lookup(int);
f32 cos_table_lookup(int);
void debug_printf_at(s32, const char *, ...);
s32 vec3_add_to(void *, void *);
void rotate_matrix_y(s32, s32);
s32 subtract_vector(void *, void *);
void translate_matrix(s32, f32, f32, f32);
s32 push_matrix();
s32 pop_matrix();
s32 post_translate_matrix(void *);
void set_global_param__8TObjFishFl(s32);
void draw_chunk_object(void *child);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);

void vfunc_6__8TObjBaseFPsl();
void vfunc_103__9TObjEneDDFPUc();
void vfunc_79__9TObjEneDDFPl();
void vfunc_83__9TObjEneDDFv();
void vfunc_84__9TObjEneDDFv();
void vfunc_85__9TObjEneDDFv();
void vfunc_86__9TObjEneDDFv();
void vfunc_89__9TObjEneDDFv();
void vfunc_90__9TObjEneDDFv();
void vfunc_91__9TObjEneDDFv();
void vfunc_92__9TObjEneDDFv();
void vfunc_93__9TObjEneDDFv();
void vfunc_94__9TObjEneDDFv();
void vfunc_95__9TObjEneDDFv();
void vfunc_96__9TObjEneDDFv();
void vfunc_97__9TObjEneDDFv();
void vfunc_98__9TObjEneDDFv();
void vfunc_99__9TObjEneDDFv();
void vfunc_100__9TObjEneDDFv();
void vfunc_101__9TObjEneDDFPUc();
void vfunc_102__9TObjEneDDFv();
void vfunc_29__9TObjCharaFv();
void recalc_stats__9TObjCharaFv();
void consume_timer_field__9TObjCharaFl();
void vfunc_67__9TObjCharaFf();
void vfunc_66__9TObjCharaFv();
void get_anim_node_position__9TObjCharaFlP3Vec();
void vfunc_60__9TObjCharaFv();
void vfunc_59__9TObjCharaFv();
void vfunc_58__9TObjCharaFv();
void apply_slow_status__9TObjCharaFv();
void update_shock_clock__9TObjCharaFv();
void vfunc_43__9TObjCharaFv();
void vfunc_18__9TObjCharaFPUc();
void interact__14TObjCollidableFl();
void vfunc_74__9TObjEnemyFl();
void apply_hit_message_flags__9TObjEnemyFPv();
void add_actor_exp__9TObjCharaFl();
void apply_action_hold_status__9TObjCharaFf();
void apply_anti_technique__9TObjCharaFl();
void apply_attack_stat_status__9TObjCharaFPv();
void apply_confusion_status__9TObjCharaFv();
void apply_knockback_from_attacker__9TObjCharaFPUcf();
void apply_movement_ailment__9TObjCharaFl();
void apply_object_set_data__8TObjBaseFPv();
void apply_paralysis__9TObjCharaFv();
void apply_poison_status__9TObjCharaFv();
void apply_set_data__9TObjEnemyFPv();
void apply_shock_status__9TObjCharaFv();
void apply_switch_attack__9TObjCharaFv();
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
void classify_actor_view_detail__8TObjBaseFfff();
void clear_all_status_effects__9TObjCharaFv();
void clear_harmful_statuses__9TObjCharaFv();
void cure_paralysis__9TObjCharaFv();
void cure_poison_ailment__9TObjCharaFv();
void enemy_spawn_jellen_effect__9TObjCharaFv();
void enemy_spawn_zalure_effect__9TObjCharaFv();
void vfunc_78__9TObjCharaFl();
void vfunc_77__9TObjCharaFv();
void vfunc_76__9TObjCharaFv();
void vfunc_75__9TObjCharaFf();
void clear_lobby_object_state__9TObjEnemyFv();
void get_center__9TObjCharaFv();
void get_actor_level_index__9TObjCharaFv();
void get_name__9TObjEnemyFv();
void get_pos__9TObjCharaFl();
void is_actor_cadence_frame__9TObjCharaFl();
void is_target_in_attack_range__9TObjCharaFv();
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
void receive_physical_attack__9TObjCharaFPvf();
void receive_weapon_special_attack__9TObjCharaFPvPv();
void apply_defense_stat_status__9TObjCharaFPv();
void render_shadows__17TObjEneBm3FlyNestFv();
void reset_motion_fields__9TObjCharaFv();
void reset_pose__9TObjCharaFv();
void roll_physical_accuracy__9TObjCharaFPvlf();
void select_melee_contact_body__9TObjCharaFPvf();
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
void try_start_action__9TObjCharaFll();
void update_action_hold_status__9TObjCharaFv();
s32 vfunc_37__9TObjCharaFv(u8 *arg0);
void update_actor_ground_y__9TObjCharaFv();
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
void update_flag30_timer__9TObjCharaFv();
void update_movement_status__9TObjCharaFv();
void update_object_view_visibility__8TObjBaseFff();
void update_poison_status__9TObjCharaFv();
extern char lbl_8043B120[];
extern char lbl_8043B130[];
extern char lbl_8043B140[];
extern char lbl_8043B158[];
extern char lbl_8043B170[];
extern char lbl_8043B184[];
extern char lbl_8043B19C[];
extern char lbl_8043B1B0[];
extern char lbl_8043B1C4[];
extern char lbl_8043B1DC[];
extern char lbl_8043B1F4[];
extern char lbl_8043B20C[];
extern char lbl_8043B220[];
extern char lbl_8043B238[];
extern char lbl_8043B24C[];
extern char lbl_8043B264[];
extern char lbl_8043B27C[];
extern char lbl_8043B290[];
struct Params_80491DA0 { f32 f00; u32 w[6]; };
struct Coll_80491DBC { u32 w0[3]; f32 radius; u32 w1[2]; u32 flags; u32 w2[4]; };
struct Res_80491E34 { void *bml; void *models; void *motions; u16 nmodels; u16 nmotions; };
struct Hit_80491E44 { u16 kind; u16 pad; u32 part; f32 scale; u32 zero; };
Params_80491DA0 bm3_fly_nest_params = { 225.0f, { 0x0, 0x600, 0x0, 0x0, 0x0, 0x0 } };
Coll_80491DBC bm3_flynest_collider_params = { { 0x0, 0x0, 0x0 }, 10.0f, { 0x0, 0x0 }, 0x8003, { 0x0, 0x0, 0x0, 0x0 } };
void *bm_ene_bm3_fly_model_names[3] = { lbl_8043B120, lbl_8043B130, 0 };
void *bm_ene_bm3_fly_motion_names[16] = { lbl_8043B140, lbl_8043B158, lbl_8043B170, lbl_8043B184, lbl_8043B19C, lbl_8043B1B0, lbl_8043B1C4, lbl_8043B1DC, lbl_8043B1F4, lbl_8043B20C, lbl_8043B220, lbl_8043B238, lbl_8043B24C, lbl_8043B264, lbl_8043B27C, 0 };
Res_80491E34 bm3_fly_nest_resource_desc = { lbl_8043B290, bm_ene_bm3_fly_model_names, bm_ene_bm3_fly_motion_names, 0x2, 0xf };
Hit_80491E44 bm3_flynest_hit_action_table[10] = { { 0x1, 0x0, 0xe, 0.30000001192092896f, 0x0 }, { 0x3, 0x0, 0x9, 0.699999988079071f, 0x0 }, { 0x3, 0x0, 0x2, 1.0f, 0x0 }, { 0x3, 0x0, 0x5, 0.5f, 0x0 }, { 0x1, 0x0, 0x8, 0.30000001192092896f, 0x0 }, { 0x3, 0x0, 0x7, 0.699999988079071f, 0x0 }, { 0x3, 0x0, 0x6, 1.0f, 0x0 }, { 0x3, 0x0, 0x4, 0.30000001192092896f, 0x0 }, { 0x1, 0x0, 0xd, 0.30000001192092896f, 0x0 }, { 0x3, 0x0, 0xb, 0.20000000298023224f, 0x0 } };
void *lbl_80491EE4[106] = {
    0, 0, (void *)TObjEneBm3FlyNest__sub_800B3E40, (void *)run_task__17TObjEneBm3FlyNestFv,
    (void *)render__17TObjEneBm3FlyNestFv, (void *)render_shadows__17TObjEneBm3FlyNestFv, (void *)vfunc_6__8TObjBaseFPsl, (void *)apply_object_set_data__8TObjBaseFPv,
    (void *)reset_motion_fields__9TObjCharaFv, (void *)get_center__9TObjCharaFv, (void *)update_object_view_visibility__8TObjBaseFff, (void *)classify_actor_view_detail__8TObjBaseFfff,
    (void *)get_name__9TObjEnemyFv, (void *)interact__14TObjCollidableFl, (void *)add_actor_exp__9TObjCharaFl, (void *)consume_timer_field__9TObjCharaFl,
    (void *)get_actor_level_index__9TObjCharaFv, (void *)update_actor_ground_y__9TObjCharaFv, (void *)vfunc_18__9TObjCharaFPUc, (void *)is_actor_cadence_frame__9TObjCharaFl,
    (void *)select_melee_contact_body__9TObjCharaFPvf, (void *)calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)receive_physical_attack__9TObjCharaFPvf, (void *)receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__9TObjCharaFPvPv, (void *)apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)try_start_action__9TObjCharaFll, (void *)roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)vfunc_28__17TObjEneBm3FlyNestFv, (void *)vfunc_29__9TObjCharaFv, (void *)is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)update_poison_status__9TObjCharaFv,
    (void *)update_action_hold_status__9TObjCharaFv, (void *)vfunc_37__9TObjCharaFv, (void *)update_flag30_timer__9TObjCharaFv, (void *)update_movement_status__9TObjCharaFv,
    (void *)update_shock_clock__9TObjCharaFv, (void *)update_attack_stat_status__9TObjCharaFv, (void *)update_defense_stat_status__9TObjCharaFv, (void *)vfunc_43__9TObjCharaFv,
    (void *)apply_poison_status__9TObjCharaFv, (void *)apply_paralysis__9TObjCharaFv, (void *)apply_slow_status__9TObjCharaFv, (void *)apply_confusion_status__9TObjCharaFv,
    (void *)apply_movement_ailment__9TObjCharaFl, (void *)apply_shock_status__9TObjCharaFv, (void *)clear_harmful_statuses__9TObjCharaFv, (void *)apply_attack_stat_status__9TObjCharaFPv,
    (void *)apply_defense_stat_status__9TObjCharaFPv, (void *)cure_poison_ailment__9TObjCharaFv, (void *)cure_paralysis__9TObjCharaFv, (void *)clear_all_status_effects__9TObjCharaFv,
    (void *)apply_action_hold_status__9TObjCharaFf, (void *)apply_anti_technique__9TObjCharaFl, (void *)vfunc_58__9TObjCharaFv, (void *)vfunc_59__9TObjCharaFv,
    (void *)vfunc_60__9TObjCharaFv, (void *)vfunc_61__17TObjEneBm3FlyNestFv, (void *)vfunc_62__17TObjEneBm3FlyNestFv, (void *)vfunc_63__17TObjEneBm3FlyNestFv,
    (void *)reset_pose__9TObjCharaFv, (void *)get_anim_node_position__9TObjCharaFlP3Vec, (void *)vfunc_66__9TObjCharaFv, (void *)vfunc_67__9TObjCharaFf,
    (void *)get_pos__9TObjCharaFl, (void *)apply_switch_attack__9TObjCharaFv, (void *)enemy_spawn_jellen_effect__9TObjCharaFv, (void *)trigger_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_zalure_effect__9TObjCharaFv, (void *)recalc_stats__9TObjCharaFv, (void *)vfunc_74__9TObjEnemyFl, (void *)vfunc_75__9TObjCharaFf,
    (void *)vfunc_76__9TObjCharaFv, (void *)vfunc_77__9TObjCharaFv, (void *)vfunc_78__9TObjCharaFl, (void *)vfunc_79__9TObjEneDDFPl,
    (void *)apply_hit_message_flags__9TObjEnemyFPv, (void *)apply_set_data__9TObjEnemyFPv, (void *)clear_lobby_object_state__9TObjEnemyFv, (void *)vfunc_83__9TObjEneDDFv,
    (void *)vfunc_84__9TObjEneDDFv, (void *)vfunc_85__9TObjEneDDFv, (void *)vfunc_86__9TObjEneDDFv, (void *)dispatch_state__17TObjEneBm3FlyNestFiUii,
    (void *)vfunc_88__17TObjEneBm3FlyNestFv, (void *)vfunc_89__9TObjEneDDFv, (void *)vfunc_90__9TObjEneDDFv, (void *)vfunc_91__9TObjEneDDFv,
    (void *)vfunc_92__9TObjEneDDFv, (void *)vfunc_93__9TObjEneDDFv, (void *)vfunc_94__9TObjEneDDFv, (void *)vfunc_95__9TObjEneDDFv,
    (void *)vfunc_96__9TObjEneDDFv, (void *)vfunc_97__9TObjEneDDFv, (void *)vfunc_98__9TObjEneDDFv, (void *)vfunc_99__9TObjEneDDFv,
    (void *)vfunc_100__9TObjEneDDFv, (void *)vfunc_101__9TObjEneDDFPUc, (void *)vfunc_102__9TObjEneDDFv, (void *)vfunc_103__9TObjEneDDFPUc,
    (void *)TObjEneBm3FlyNest::init, (void *)render_with_state_debug__17TObjEneBm3FlyNestFv,
};
extern RecoveredGlobal_800B2948_lbl_8043B2A4 bm3_fly_nest_attachment_sample_table;
extern Anim_800B41E8 bm3_flynest_anim_binding;
extern Vec_800B39CC lbl_8043B304[];
extern Vec_800B264C lbl_8043B310;
extern const Vec_800B23A0 lbl_8043B31C;
extern char lbl_8043B328[];
extern char lbl_8043B338[];
extern char lbl_8043B348[];
extern char lbl_8043B358[];
extern char lbl_8043B368[];
extern const f64 lbl_8043B398[];
extern s32 __vt__26TObjEneBm3FlyNest_CarryFly[];
typedef struct Ctl_800B47C4 {
    f32 *pv;
    s32 *pc;
    s32 d;
    s32 e;
    s32 f;
} Ctl_800B47C4;
f32 TObjEneBm3FlyNest__attachment_sample_origin[3];
f32 fly_nest_vertex_table[6];
__declspec(section ".data") s32 lbl_80500B24[2];
Ctl_800B47C4 lbl_80500B2C;
#define TObjEneBm3FlyNest__attachment_sample_origin (*(RecoveredGlobal_800B2948_lbl_80500B00 *)TObjEneBm3FlyNest__attachment_sample_origin)
extern s32 debug_chunk_object;
extern s32 TObjEneBm3FlyNest_CarryFly__name;
extern s32 lbl_805D50F8;
extern s32 lbl_805D50FC;
extern s32 lbl_805D5100;
extern s32 lbl_805D5104;
extern u32 lbl_805D5108;
extern s32 lbl_805D510C;
extern NestAttachmentPoint *TObjEneBm3FlyNest_attachment_point_ptr;
extern s32 lbl_805D5114;
extern s32 bm3_fly_nest_attachment_index;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern const f32 lbl_805D9D08;
extern const f32 lbl_805D9D0C;
extern const f32 lbl_805D9D10;
extern const f32 lbl_805D9D14;
extern const f32 lbl_805D9D18;
extern const f32 lbl_805D9D1C;
extern const f32 lbl_805D9D20;
extern const f32 lbl_805D9D24;
extern const f32 lbl_805D9D28;
extern const f32 lbl_805D9D2C;
extern const f32 lbl_805D9D30;
extern const f32 lbl_805D9D34;
extern const f32 lbl_805D9D38;
extern const f32 lbl_805D9D3C;
extern const f32 lbl_805D9D40;
extern const f32 lbl_805D9D44;
extern const f32 lbl_805D9D48;
extern const f32 lbl_805D9D4C;
extern const f32 lbl_805D9D50;
extern const f32 lbl_805D9D54;
extern const f32 lbl_805D9D58;
extern const f32 lbl_805D9D5C;
extern const f32 lbl_805D9D60;
extern const f32 lbl_805D9D64;
extern const f32 lbl_805D9D68;
extern const f32 lbl_805D9E84;
extern const f32 lbl_805D9E88;
extern s32 model_render_flags;
extern void *tl_04;

void TObjEneBm3FlyNest::render_with_state_debug() {
    u8 *arg0 = (u8 *)this;
    f32 var_f31;
    Ent_800B23A0 *var_r30;
    if (((TObjEneDD *)arg0)->get_target_info() != 0) {
        switch (this->m_3a8) {
        default:
        case 2:
            debug_printf_at(pack_debug_text_position(0, 0), lbl_8043B328);
            break;
        case 9:
            debug_printf_at(pack_debug_text_position(0, 0), lbl_8043B338);
            break;
        case 5:
            debug_printf_at(pack_debug_text_position(0, 0), lbl_8043B348);
            break;
        }
        debug_printf_at(pack_debug_text_position(0, 1), lbl_8043B358, this->m_3ac);
        debug_printf_at(pack_debug_text_position(0, 2), lbl_8043B368, this->m_3b0);
    }
    switch (this->m_3a8) {
    default:
    case 2:
        var_f31 = 0.0f;
        var_r30 = (*(Pair_800B23A0 * *)&this->motion_list)[*(s32 *)((s8 *)(*(u8 * *)&this->action_table) + 4)].e;
        break;
    case 9:
        var_r30 = (*(Pair_800B23A0 * *)&this->motion_list)[*(s32 *)((s8 *)(*(u8 * *)&this->action_table) + 0x74)].e;
        var_f31 = var_r30->count - 1;
        break;
    case 5:
        var_r30 = (*(Pair_800B23A0 * *)&this->motion_list)[*(s32 *)((s8 *)(*(u8 * *)&this->action_table) + 0x34)].e;
        var_f31 = var_r30->count - 1;
        break;
    }
    if (((VObj_18_800B23A0 *)arg0)->m8(500.0f, 120.0f) != 0) {
        Vec_800B23A0 v = lbl_8043B31C;
        update_player_state__9TObjEneDDFv(arg0, &v, 1);
        set_global_param__8TObjFishFl(this->texlist);
        ((void (*)(void))push_matrix)();
        ((void (*)(void *))post_translate_matrix)(arg0 + 0x38);
        translate_matrix(0, 0.0f, -5.0f, 0.0f);
        rotate_matrix_y(0, this->rotation_y);
        TObjEneDD::clear_global_flag_400();
        TObjPlayer::toggle_particle_effect();
        TObjPlayer::set_global_flag();
        draw_model_motion(this->model, var_r30, var_f31);
        TObjPlayer::clear_global_state();
        TParticleCtrl::end_effect_render();
        ((void (*)(void))pop_matrix)();
    }
    ((void (*)(void))push_matrix)();
    ((void (*)(void *))post_translate_matrix)(arg0 + 0x38);
    rotate_matrix_y(0, this->rotation_y);
    translate_matrix(0, *(f32 *)((s8 *)arg0 + 0x35C), *(f32 *)((s8 *)arg0 + 0x360), *(f32 *)((s8 *)arg0 + 0x364));
    draw_chunk_object((void *)debug_chunk_object);
    ((void (*)(void))pop_matrix)();
}

__declspec(section ".rodata") extern const char lbl_8043B380[] = "bm_ene_bm3_fly_a.bml";
__declspec(section ".rodata") extern const f64 lbl_8043B398[1] = { 10430.38043493439 };

void TObjEneBm3FlyNest::render() {
    Cam_800B264C *cm;
    s32 cam;
    s32 res;
    s32 draw;
    Nest_800B264C *self = (Nest_800B264C *)this;
    f32 t;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_with_state_debug();
        return;
    }
    cam = 0;
    if (is_split_screen() != 0) {
        cam = get_camera_mode__11TCameraCtrlFv();
    }
    self->f3AC = 0;
    if (self->f326 != 9) {
        if (is_main_phase_15__9TObjEneDDFv() != 0) {
            res = ((VObj_18_113a45 *)(this))->m9(lbl_805D9D08 + lbl_805D9E88, lbl_805D9D0C + lbl_805D9E84, 120.0f);
        } else if (((VObj_18_113a45 *)(this))->m8(500.0f, 120.0f) != 0) {
            res = 1;
        } else {
            res = 0;
        }
        if (res != 0) {
            draw = 1;
            self->f3AC = 1;
            saved_model_render_flags = model_render_flags;
            saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
            saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
            cm = &self->cams[cam];
            update__15RenderFadeStateFv(cm);
            if (((RenderFadeState *)cm)->updateFromCamera((const f32*)(&self->f2FC)) != 0) {
                ((VObj_14_aa9368 *)(cm))->m6();
                if (defer_render__7TObjectFv(this) != 0) {
                    draw = 0;
                }
            }
            if (self->f326 != 9) {
                Vec_800B264C v = lbl_8043B310;
                if (self->f326 == 0) {
                    t = lbl_805D9D10 / (self->f4B0 - lbl_805D9D14);
                    if (t < lbl_805D9D18 && t > 0.0f) {
                        v.x = v.z = lbl_805D9D1C * t;
                    }
                }
                ((s32 (*)(void *, void *, int))update_player_state__9TObjEneDDFv)(this, &v, 1);
            }
            if (draw != 0) {
                this->update_secondary_light();
                ((s32 (*)(int))set_global_param__8TObjFishFl)(self->f24);
                push_matrix();
                lbl_805D510C = 0;
                TObjEneBm3FlyNest_attachment_point_ptr = (NestAttachmentPoint *)&self->f3C8;
                post_translate_matrix(self->f38);
                ((s32 (*)(int, f32, f32, f32))translate_matrix)(0, 0.0f, self->f4B0, 0.0f);
                if (self->f326 == 0) {
                    bm3_fly_nest_attachment_index = 0;
                    lbl_805D5114 = (s32)self->f3E0;
                    TObjEneRe7Berura::set_global_state((s32)((void *)handle_attachment_sample__17TObjEneBm3FlyNestFi));
                } else {
                    TObjEneRe7Berura::set_global_state((s32)((void *)TObjEneBm3FlyNest::capture_attachment));
                }
                ((s32 (*)(int, int))rotate_matrix_y)(0, self->f60);
                TObjEneDD::clear_global_flag_400();
                TObjPlayer::toggle_particle_effect();
                if (res == 1) {
                    this->draw();
                } else {
                    this->draw_motion_model();
                }
                TParticleCtrl::end_effect_render();
                TObjEneRe7Berura::set_global_state((s32)NULL);
                pop_matrix();
            }
            this->update_primary_light();
            if (((RenderFadeState *)cm)->updateFromCamera((const f32*)(&self->f2FC)) != 0) {
                ((VObj_14_aa9368 *)(cm))->m7();
            }
            model_render_flags = saved_model_render_flags;
            chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
            chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        }
    }
    VecCopy((Vec *)&self->f2FC, (const Vec *)&self->f3C8);
}

void handle_attachment_sample__17TObjEneBm3FlyNestFi(s32 arg0) {
    s32 pos;
    if ((s32) lbl_805D510C == (s32) *(s32 *)((s8 *)&bm3_fly_nest_attachment_sample_table.value + (bm3_fly_nest_attachment_index * 4))) {
        pos = lbl_805D5114;
        bm3_fly_nest_attachment_index += 1;
        lbl_805D5114 = pos + 0xC;
        get_camera_ctrl__9TObjEneDDFv((s32) &TObjEneBm3FlyNest__attachment_sample_origin.value, pos);
    }
    TObjEneBm3FlyNest::capture_attachment((void *)arg0);
}

void TObjEneBm3FlyNest::capture_attachment(void * _w0) {
    switch (lbl_805D510C) {
    case 36: case 45:
        get_camera_ctrl__9TObjEneDDFv((s32)&TObjEneBm3FlyNest__attachment_sample_origin, (s32)(TObjEneBm3FlyNest_attachment_point_ptr++));
        break;
    }
    ++lbl_805D510C;
}

int TObjEneBm3FlyNest::init(void* p) { return ((int (*)(void*))init_params__17TObjEneBm3FlyNestFv)(p); }

int copy_target_state__17TObjEneBm3FlyNestFPv(void* p, s32 sound_id) { return ((TObjEnemy *)(p))->remap_sound_for_area((s32)(sound_id)); }

void* TObjEneBm3FlyNest__sub_800B2A54(void* p) { return (char*)p + 0x3d4; }

void TObjEneBm3FlyNest::remove_child(u8 *child) {
    Obj_800B2A5C *self = (Obj_800B2A5C *)this;
    s32 i;
    for (i = 0; i < 6; i++) {
        if (find_entity_by_id(self->ids[i]) == child) {
            self->count--;
            self->ids[i] = self->ids[self->count];
            self->ids[self->count] = 0xFFFF;
            return;
        }
    }
}

s32 TObjEneBm3FlyNest::has_free_attack_slot(u16 id) {
    Obj_800B2AF4 *self = (Obj_800B2AF4 *)this;
    s32 n = 0;
    s32 i;
    for (i = 0; i < self->count; i++) {
        u8 *p = (u8 *)find_entity_by_id(self->ids[i]);
        if (p != 0 && id == ((TObjEneBm3Fly *)p)->get_active_id()) {
            n++;
        }
    }
    if (TObjEneDD::check_v2_mode()) {
        return n < 4;
    }
    return n < 2;
}

void handle_state__17TObjEneBm3FlyNestFPvi(void *arg0, s32 arg1) {
    switch (arg1) {
    case 4:
        ((struct VObj_800B2BAC_800B2A14 *) arg0)->m93();
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x3B0) == 0) {
            send_entity_set_flags__9TObjEnemyFv();
            ((s32 (*)(void *))queue_destruction__7TObjectFv)(arg0);
        }
    case 5:
    case 0:
        return;
    }
}

#pragma push
#pragma fp_contract on
void state_dying__17TObjEneBm3FlyNestFPvi(u8 *actor, s32 arg1) {
    Vec_800B2C24 v;
    Vec_800B2C24 p;
    f32 r;
    s32 a;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)actor + 0xB8) = 7;
        ((TObjEneDD *)(actor))->vfunc_96();
        *(f32 *)((s8 *)actor + 0x4B0) = 0.0f;
        ((TObjPlayer *)actor)->refresh_lobby_state();
        *(s32 *)((s8 *)actor + 0x4C8) = 4;
        *(s32 *)((s8 *)actor + 0x4CC) = 0x14;
        *(s32 *)((s8 *)actor + 0x4D0) = 0;
        *(f32 *)((s8 *)actor + 0x4D8) = 0.0f;
        break;
    case 3:
        if (*(f32 *)((s8 *)actor + 0x4D8) >= lbl_805D9D20) {
            ((s32 (*)(void *, int))transition_enemy_state__9TObjEneDDFl)(actor, 9);
        }
        break;
    case 5:
        break;
    case 0:
        switch (*(s32 *)((s8 *)actor + 0x4D0)) {
        case 0:
            ((s32 (*)(void))advance_animation_playback)();
            if (get_flag_b4__9TObjEneDDFv(actor) != 0) {
                *(s32 *)((s8 *)actor + 0x4D0) = 1;
                v.x = lbl_805D9D24;
                v.y = 0.0f;
                v.z = lbl_805D9D28;
                rotate_xz_pair_by_angle((f32 *)&v, &v.z, *(s32 *)((s8 *)actor + 0x60));
                vec3_add_to(&v, actor + 0x38);
                spawn_dead_spot_scale15((s32)&v, 0x32);
                set_field_e4__10TObjPlayerFll(&v, 0x46, lbl_805D9D10);
            }
            if (*(f32 *)((s8 *)actor + 0xC0) < lbl_805D9D08) {
                *(s32 *)((s8 *)actor + 0x4C8) += 1;
                if (*(s32 *)((s8 *)actor + 0x4C8) >= 4) {
                    r = rand_range__9TObjEneDDFff(actor, lbl_805D9D1C, lbl_805D9D10);
                    a = get_random_scaled__9TObjEneDDFv(actor);
                    VecCopy((Vec *)&p, (const Vec *)(actor + 0x2FC));
                    p.x = r * sin_table_lookup(a) + p.x;
                    p.y += lbl_805D9D1C;
                    p.z = r * cos_table_lookup(a) + p.z;
                    spawn_particle_effect(&p, 0xF1);
                    *(s32 *)((s8 *)actor + 0x4C8) = 0;
                }
                *(s32 *)((s8 *)actor + 0x4CC) += 1;
                if (*(s32 *)((s8 *)actor + 0x4CC) >= 0x14) {
                    ((s32 (*)(int, void *, int, int))play_sound_effect)(((TObjEnemy *)(actor))->remap_sound_for_area((s32)(0x4003AD2B)), actor + 0x38, 0, 0);
                    *(s32 *)((s8 *)actor + 0x4CC) = 0;
                }
            }
            ((TObjEneDD *)(actor))->vfunc_102();
            break;
        case 1:
            *(f32 *)((s8 *)actor + 0x4D8) += lbl_805D9D2C;
            *(f32 *)((s8 *)actor + 0x3C) -= lbl_805D9D2C;
            break;
        }
        break;
    }
}
#pragma pop

void handle_motion_event__17TObjEneBm3FlyNestFPvi(u8 *arg0, s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneDD *)arg0)->vfunc_96();
        noop__12TBoss8DragonFv(arg0);
        TBoss8Dragon__sub_800BB7D4(arg0, 0xF1);
        ((s32 (*)(void *, void *, s32, s32))play_sound_effect)((void *)(s32)((TObjEnemy *)(arg0))->remap_sound_for_area((s32)(0x4003A829)), arg0 + 0x38, 0, 0);
        if ((s32) *(s32 *)((s8 *)arg0 + 0x3A8) != 0) {
            *(s16 *)((s8 *)arg0 + 0xB8) = 6;
            *(f32 *)((s8 *)arg0 + 0x4B0) = (f32) 0.0f;
            return;
        }
        *(s16 *)((s8 *)arg0 + 0xB8) = 2;
        *(f32 *)((s8 *)arg0 + 0x4B0) = (f32) -5.0f;
        return;
    case 3:
        if (((s32 (*)(void))get_flag_b4__9TObjEneDDFv)() != 0) {
            if ((s32) *(s32 *)((s8 *)arg0 + 0x3A8) != 0) {
                transition_enemy_state__9TObjEneDDFl(arg0, 5);
                return;
            }
            if ((s16) *(s16 *)((s8 *)arg0 + 0x32C) <= (s32) ((s16) *(s16 *)((s8 *)arg0 + 0x2B8) / 2)) {
                transition_enemy_state__9TObjEneDDFl(arg0, 4);
                return;
            }
            transition_enemy_state__9TObjEneDDFl(arg0, *(s32 *)((s8 *)arg0 + 0x378));
            return;
        }
        break;
    case 0:
        ((s32 (*)(void))advance_animation_playback)();
        ((TObjEneDD *)arg0)->vfunc_102();
        return;
    case 5:
        clear_attack_receipts__9TObjEneDDFv();
        break;
    }
}

void state_spawn__17TObjEneBm3FlyNestFPvi(void *ene_bm3_fly_nest, s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->requested_action = 5;
        ((TObjEneDD *)ene_bm3_fly_nest)->vfunc_96();
        ((TObjEneDD *)ene_bm3_fly_nest)->set_field_378(5);
        *(f32 *)((s8 *)ene_bm3_fly_nest + 0x4B0) = (f32) 0.0f;
        return;
    case 3:
        if (((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->motion_flags & 0x10) {
            transition_enemy_state__9TObjEneDDFl(ene_bm3_fly_nest, 5);
        }
        break;
    case 5:
    case 1:
        break;
    case 0:
        if (((s32 (*)(f32))is_passing_frame__10TObjMotionFf)(lbl_805D9D30) != 0) {
            ((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->spawn_child();
            ((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->m_4d4 = (s32) (((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->m_4d4 - 1);
        }
        advance_animation_playback(ene_bm3_fly_nest);
        ((TObjEneDD *)ene_bm3_fly_nest)->vfunc_102();
        break;
    }
}

void update_state__17TObjEneBm3FlyNestFPvi(void *ene_bm3_fly_nest, s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->requested_action = 4;
        ((TObjEneDD *)ene_bm3_fly_nest)->vfunc_96();
        ((TObjEneDD *)ene_bm3_fly_nest)->set_field_378(5);
        *(f32 *)((s8 *)ene_bm3_fly_nest + 0x4B0) = (f32) 0.0f;
        if ((s32) *(s32 *)((s8 *)ene_bm3_fly_nest + 0x3A8) == 0) {
            *(s32 *)((s8 *)ene_bm3_fly_nest + 0x3A8) = 1;
            *(s32 *)((s8 *)ene_bm3_fly_nest + 0x4C0) = 2;
            *(s32 *)((s8 *)ene_bm3_fly_nest + 0x4C4) = 0x78;
        }
        break;
    case 5:
        break;
    case 3:
        if (((s32 (*)(void))TObjEneBm3FlyNest__sub_800B3AC8)() != 0) {
            transition_enemy_state__9TObjEneDDFl(ene_bm3_fly_nest, 6);
            return;
        }
        break;
    case 0:
        advance_animation_playback(ene_bm3_fly_nest);
        ((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->update_replenish();
        ((TObjEneDD *)ene_bm3_fly_nest)->vfunc_102();
        break;
    }
}

#pragma push
#pragma opt_common_subs off
#pragma fp_contract on
void TObjEneBm3FlyNest__sub_800B318C(u8 *ene_dd, s32 arg1) {
    typedef char sp8_offset[(offsetof(Stack_800B318C, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800B318C, sp10) == 0x8) ? 1 : -1];
    Stack_800B318C stack;
    s32 temp_r31;
    switch (arg1) {
    case 4:
        ((TObjEneDD *)(ene_dd))->vfunc_91();
        ((TObjEneDD *)ene_dd)->requested_action = 3;
        ((TObjEneDD *)(ene_dd))->vfunc_96();
        ((TObjEneDD *)ene_dd)->set_field_378(5);
        *(f32 *)((s8 *)ene_dd + 0x4B0) = (f32) -5.0f;
        break;
    case 3:
        if (((TObjEneDD *)ene_dd)->motion_flags & 0x10) {
            transition_enemy_state__9TObjEneDDFl(ene_dd, 5);
            break;
        }
        break;
    case 0:
        ((s32)advance_animation_playback(ene_dd));
        if ((is_passing_frame__10TObjMotionFf(ene_dd, lbl_805D9D10) != 0) || (is_passing_frame__10TObjMotionFf(ene_dd, lbl_805D9D34) != 0)) {
            play_sound_effect((void *) (((TObjEnemy *)(ene_dd))->remap_sound_for_area((s32)(0x4003B72A))), ene_dd + 0x38, 0, 0);
        }
        if (is_passing_frame__10TObjMotionFf(ene_dd, lbl_805D9D38) != 0) {
            spawn_particle_effect((ene_dd + 0x38), 0xF0);
        } else if (is_passing_frame__10TObjMotionFf(ene_dd, lbl_805D9D3C) != 0) {
            temp_r31 = ((TObjEneDD *)ene_dd)->rotation_y - 0x4000;
            VecCopy((Vec *)(&stack.sp8), (const Vec *)(ene_dd + 0x38));
            stack.sp8 += lbl_805D9D40 * sin_table_lookup(temp_r31);
            stack.sp10 += lbl_805D9D40 * cos_table_lookup(temp_r31);
            spawn_particle_effect((&stack.sp8), 0xF0);
        }
        *(f32 *)((s8 *)ene_dd + 0x4B0) = (f32) (*(f32 *)((s8 *)ene_dd + 0x4B0) + lbl_805D9D2C);
        if (*(f32 *)((s8 *)ene_dd + 0x4B0) > 0.0f) {
            *(f32 *)((s8 *)ene_dd + 0x4B0) = (f32) 0.0f;
        }
        ((TObjEneDD *)(ene_dd))->vfunc_102();
        break;
    case 5:
        ((TObjEneDD *)(ene_dd))->vfunc_92();
        break;
    }
}
#pragma pop

void handle_event__17TObjEneBm3FlyNestFPvi(void *ene_bm3_fly_nest, s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->requested_action = 1;
        ((TObjEneDD *)ene_bm3_fly_nest)->vfunc_96();
        ((TObjEneDD *)ene_bm3_fly_nest)->set_field_378(2);
        *(f32 *)((s8 *)ene_bm3_fly_nest + 0x4B0) = (f32) -5.0f;
        return;
    case 3:
        if (((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->motion_flags & 0x10) {
            transition_enemy_state__9TObjEneDDFl(ene_bm3_fly_nest, 2);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(ene_bm3_fly_nest);
        if (is_passing_frame__10TObjMotionFf(ene_bm3_fly_nest, lbl_805D9D30) != 0) {
            ((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->spawn_child();
            ((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->m_4d4 = (s32) (((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->m_4d4 - 1);
        }
        ((TObjEneDD *)ene_bm3_fly_nest)->vfunc_102();
        break;
    }
}

void state_wait__17TObjEneBm3FlyNestFPvi(void *ene_bm3_fly_nest, s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->requested_action = 0;
        ((struct VObj_800B3428_800B30B0 *)ene_bm3_fly_nest)->m94();
        ((TObjEneDD *)ene_bm3_fly_nest)->set_field_378(2);
        *(f32 *)((s8 *)ene_bm3_fly_nest + 0x4B0) = (f32) -5.0f;
        *(s32 *)((s8 *)ene_bm3_fly_nest + 0x4C0) = 1;
        *(s32 *)((s8 *)ene_bm3_fly_nest + 0x4C4) = 0x96;
        return;
    case 3:
        if (((s32 (*)(void))TObjEneBm3FlyNest__sub_800B3AC8)() != 0) {
            transition_enemy_state__9TObjEneDDFl(ene_bm3_fly_nest, 3);
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(ene_bm3_fly_nest);
        ((TObjEneBm3FlyNest *)ene_bm3_fly_nest)->update_replenish();
        ((struct VObj_800B3428_800B30B0 *)ene_bm3_fly_nest)->m100();
        break;
    }
}

void TObjEneBm3FlyNest::state_initial_emit(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    switch (arg1) {
    case 4:
        this->requested_action = 0;
        this->vfunc_95();
        ((TObjEneDD *)arg0)->set_field_378(2);
        *(f32 *)&this->m_4cc = -5.0f;
        *(s32 *)((s8 *)arg0 + 0x4C8) = 0;
        *(s32 *)((s8 *)arg0 + 0x4CC) = 0;
        *(s32 *)((s8 *)arg0 + 0x4D0) = 0;
        break;
    case 3:
        advance_animation_playback(arg0);
        if (*(s32 *)((s8 *)arg0 + 0x4D0) == 3) {
            switch (*(s32 *)&this->m_3a8) {
            case 2:
                transition_enemy_state__9TObjEneDDFl(arg0, *(s32 *)&this->m_3a8);
                break;
            case 5:
                transition_enemy_state__9TObjEneDDFl(arg0, *(s32 *)&this->m_3a8);
                break;
            case 9:
                this->requested_action = 7;
                advance_animation_playback(arg0);
                this->frame = lbl_805D9D14;
                advance_animation_playback(arg0);
                this->frame = *(f32 *)&this->frame_count - lbl_805D9D18;
                *(s32 *)&this->actorFlags |= 0x800;
                *(s32 *)((s8 *)arg0 + 0x3A8) = 1;
                transition_enemy_state__9TObjEneDDFl(arg0, *(s32 *)&this->m_3a8);
                break;
            }
        }
        break;
    case 5:
        break;
    case 0:
        advance_animation_playback(arg0);
        *(s32 *)((s8 *)arg0 + 0x4C8) += 1;
        switch (*(s32 *)((s8 *)arg0 + 0x4D0)) {
        case 0:
            if (*(s32 *)((s8 *)arg0 + 0x4C8) > 0x3C) {
                *(s32 *)((s8 *)arg0 + 0x4D0) = 2;
                this->requested_action = 1;
            }
            break;
        case 1:
            if (is_passing_frame__10TObjMotionFf(arg0, lbl_805D9D30) != 0) {
                *(s32 *)((s8 *)arg0 + 0x4D0) = 2;
            }
            break;
        case 2:
            if (get_flag_b4__9TObjEneDDFv(arg0) != 0) {
                this->requested_action = 0;
            }
            if ((*(s32 *)((s8 *)arg0 + 0x4C8) % 10) == 0) {
                if (*(s32 *)((s8 *)arg0 + 0x4CC) < *(s32 *)&this->m_3ac) {
                    ((TObjEneBm3FlyNest *)arg0)->spawn_child();
                    *(s32 *)((s8 *)arg0 + 0x4CC) += 1;
                } else {
                    *(s32 *)((s8 *)arg0 + 0x4D0) = 3;
                }
            }
            break;
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
void handle_appear__17TObjEneBm3FlyNestFPvi(u8 *ene_dd, s32 arg1) {
    s32 *cnt = (s32 *)(ene_dd + 0x4CC);
    s32 i;
    void *o;

    switch (arg1) {
    case 4:
        ((TObjEneDD *)ene_dd)->requested_action = 8;
        ((TObjEneDD *)(ene_dd))->vfunc_95();
        ((TObjEneDD *)ene_dd)->set_field_378(2);
        *(f32 *)((s8 *)ene_dd + 0x4B0) = lbl_805D9D44;
        *(s32 *)((s8 *)ene_dd + 0x4C8) = 0;
        *(s32 *)((s8 *)ene_dd + 0x4D0) = 0;
        *(s32 *)((s8 *)ene_dd + 0x4D4) = 0;
        break;
    case 3:
        if (*(s32 *)((s8 *)ene_dd + 0x4D0) == 2 && get_flag_b4__9TObjEneDDFv(ene_dd) != 0) {
            transition_enemy_state__9TObjEneDDFl(ene_dd, 1);
        }
        break;
    case 0:
        advance_animation_playback(ene_dd);
        switch (*(s32 *)((s8 *)ene_dd + 0x4D0)) {
        case 0:
            *(s32 *)((s8 *)ene_dd + 0x4C8) += 1;
            if (*(s32 *)((s8 *)ene_dd + 0x4C8) == 1) {
                *cnt = 0;
                for (i = 0; i < 6; i++) {
                    o = __nw__7TObjectFUl(0x68);
                    if (o != 0) {
                        ((s32 (*)(void *, void *, void *, void *, void *, void *, s32))__ct__26TObjEneBm3FlyNest_CarryFlyFP7TObjectlllll)(o, ene_dd, &((Self_800B36F8 *)ene_dd)->arr[i], ene_dd + 0x3D4, ene_dd + 0x38, cnt, i + 1);
                    }
                }
            }
            *(f32 *)((s8 *)ene_dd + 0x4B0) = *(f32 *)((s8 *)ene_dd + 0x4B0) - ((lbl_805D9D4C * (lbl_805D9D18 + sin_table_lookup(*(s32 *)((s8 *)ene_dd + 0x4D4)))) + lbl_805D9D48);
            *(s32 *)((s8 *)ene_dd + 0x4D4) += 0x700;
            if (*(f32 *)((s8 *)ene_dd + 0x4B0) < lbl_805D9D50 && ((TObjEneDD *)ene_dd)->requested_action != 9) {
                ((TObjEneDD *)ene_dd)->requested_action = 9;
            }
            if (*(f32 *)((s8 *)ene_dd + 0x4B0) < -5.0f) {
                *(f32 *)((s8 *)ene_dd + 0x4B0) = -5.0f;
                *(s32 *)((s8 *)ene_dd + 0x4D0) = 1;
                *(s32 *)((s8 *)ene_dd + 0x4C8) = 0;
                spawn_particle_effect(ene_dd + 0x38, 0xF0);
                play_sound_effect((void *) ((TObjEnemy *)(ene_dd))->remap_sound_for_area((s32)(0x4003B72A)), ene_dd + 0x38, 0, 0);
            }
            break;
        case 1:
            *(s32 *)((s8 *)ene_dd + 0x4C8) += 1;
            if (*(s32 *)((s8 *)ene_dd + 0x4C8) > 3) {
                *(s32 *)((s8 *)ene_dd + 0x4C8) = 0;
                *cnt += 1;
                if (*cnt >= 6) {
                    *(s32 *)((s8 *)ene_dd + 0x4D0) = 2;
                }
            }
            break;
        }
        ((TObjEneDD *)(ene_dd))->vfunc_102();
        break;
    case 5:
        *cnt = 6;
        break;
    }
}
#pragma pop

void TObjEneBm3FlyNest::init_params() {
    s32 temp_r0;
    s32 temp_r0_2;

    this->m_3a8 = 2;
    this->m_3ac = (s32) *(f32 *)((s8 *)this + 0x358);
    temp_r0 = this->m_3ac;
    if (temp_r0 < 0) {
        this->m_3ac = 0;
    } else if (temp_r0 > 6) {
        this->m_3ac = 6;
    }
    this->m_3b0 = (s32) *(f32 *)((s8 *)this + 0x35C);
    temp_r0_2 = this->m_3b0;
    if (temp_r0_2 < 0) {
        this->m_3b0 = 0;
        return;
    }
    if (temp_r0_2 > 0x1E) {
        this->m_3b0 = 0x1E;
    }
}

void TObjEneBm3FlyNest::spawn_child() {
    Nest_800B39CC *s = (Nest_800B39CC *)this;
    Vec_800B39CC velocity = lbl_8043B304[0];
    Vec_800B39CC position;
    s32 n;
    if (s->count <= 6) {
        n = (s->f2C + 1) + s->spawned;
        VecCopy((Vec *)(&position), (const Vec *)(((Vec_800B39CC * (*)(void *))TObjEneBm3FlyNest__sub_800B2A54)(s)));
        if (((TObjEneBm3Fly *)s)->create((void *)s->nextId, (void *)n, &position, &velocity) != 0) {
            s->ids[s->count++] = s->nextId;
            s->nextId++;
            s->spawned++;
            spawn_particle_effect(s->f3D4, 0xC8);
            ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(((TObjEnemy *)(s))->remap_sound_for_area((s32)(0x4003AB27)), &s->pos, 0, 0);
            TObjPlayer::play_effect_if_v2(-0x400);
        }
    }
}

s32 TObjEneBm3FlyNest__sub_800B3AC8(u8 *arg0) {
    return *(s32 *)((s8 *)arg0 + 0x4B8) > 0;
}

void TObjEneBm3FlyNest::update_replenish() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 var_r5;
    switch (this->m_4d0) {
    case 0:
        if (((s32) *(s32 *)((s8 *)arg0 + 0x3B0) <= (s32) ((s32) this->m_3ac / 2)) || ((s32) *(s32 *)((s8 *)arg0 + 0x3A8) != 0)) {
            this->m_4d0 = 1;
            *(s32 *)((s8 *)arg0 + 0x4BC) = 0;
        }
        return;
    case 1:
        if ((s32) *(s32 *)((s8 *)arg0 + 0x4C0) > 0) {
            *(s32 *)((s8 *)arg0 + 0x4BC) = (s32) (*(s32 *)((s8 *)arg0 + 0x4BC) + 1);
            if ((s32) *(s32 *)((s8 *)arg0 + 0x4BC) > (s32) *(s32 *)((s8 *)arg0 + 0x4C4)) {
                *(s32 *)((s8 *)arg0 + 0x4BC) = 0;
                var_r5 = *(s32 *)((s8 *)arg0 + 0x4C0);
                temp_r0_2 = 6 - *(s32 *)((s8 *)arg0 + 0x3B0);
                if (temp_r0_2 < var_r5) {
                    var_r5 = temp_r0_2;
                }
                temp_r0_3 = this->m_3b0 - *(s32 *)((s8 *)arg0 + 0x3B4);
                if (temp_r0_3 < var_r5) {
                    var_r5 = temp_r0_3;
                }
                this->m_4d4 = var_r5;
                return;
            }
        }
        break;
    }
}

void TObjEneBm3FlyNest::vfunc_88() { set_part_local_pos((void *)((char*)this + 0x2fc), (s32)((void*)0)); }

void TObjEneBm3FlyNest::copy_pos() { VecCopy((Vec *)((char*)this + 0x74), (const Vec *)((char*)this + 0x2fc)); }

void TObjEneBm3FlyNest::vfunc_61() {  }

void TObjEneBm3FlyNest::vfunc_62() {
    s16 temp_r0;

    if (((s16) this->mode == 3) && (TObjEneDD::check_v2_mode() != 0)) {
        ((s32 (*)(void *))clear_attack_receipts__9TObjEneDDFv)(this);
        return;
    }
    temp_r0 = this->mode;
    if (temp_r0 == 4) {
        ((s32 (*)(void *))clear_attack_receipts__9TObjEneDDFv)(this);
        return;
    }
    if (temp_r0 != 7) {
        transition_enemy_state__9TObjEneDDFl(this, 7);
    }
}

void TObjEneBm3FlyNest::vfunc_63() {
    s16 temp_r0;

    temp_r0 = this->mode;
    if ((temp_r0 != 9) && (temp_r0 != 8) && (temp_r0 != 4)) {
        if ((s32) *(s32 *)((s8 *)this + 0x3A8) == 0) {
            transition_enemy_state__9TObjEneDDFl(this, 4);
            return;
        }
        transition_enemy_state__9TObjEneDDFl(this, 8);
    }
}

void TObjEneBm3FlyNest::vfunc_28() {  }

void dispatch_state__17TObjEneBm3FlyNestFiUii(s32 arg0, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 1:
        ((TObjEneBm3FlyNest *)arg0)->state_initial_emit(arg2);
        return;
    case 0:
        ((s32 (*)(void *, void *))handle_appear__17TObjEneBm3FlyNestFPvi)((void *)arg0, (void *)arg2);
        return;
    case 2:
        ((s32 (*)(void *, void *))state_wait__17TObjEneBm3FlyNestFPvi)((void *)arg0, (void *)arg2);
        return;
    case 3:
        ((s32 (*)(void *, void *))handle_event__17TObjEneBm3FlyNestFPvi)((void *)arg0, (void *)arg2);
        return;
    case 4:
        ((s32 (*)(void *, void *))TObjEneBm3FlyNest__sub_800B318C)((void *)arg0, (void *)arg2);
        return;
    case 5:
        ((s32 (*)(void *, void *))update_state__17TObjEneBm3FlyNestFPvi)((void *)arg0, (void *)arg2);
        return;
    case 6:
        ((s32 (*)(void *, void *))state_spawn__17TObjEneBm3FlyNestFPvi)((void *)arg0, (void *)arg2);
        return;
    case 7:
        ((s32 (*)(void *, void *))handle_motion_event__17TObjEneBm3FlyNestFPvi)((void *)arg0, (void *)arg2);
        return;
    case 8:
        ((s32 (*)(void *, void *))state_dying__17TObjEneBm3FlyNestFPvi)((void *)arg0, (void *)arg2);
        return;
    case 9:
        ((s32 (*)(void *, void *))handle_state__17TObjEneBm3FlyNestFPvi)((void *)arg0, (void *)arg2);
    default:
        return;
    }
}

#pragma push
#pragma fp_contract on
void TObjEneBm3FlyNest::run_task() {
    if (TObjPlayer::check_demo_mode() != 0) {
        ((VObj_18_p5 *)(this))->m102();
        return;
    }
    if (this->vfunc_83() != 4) {
        this->vfunc_85();
    } else if (this->mode == 0) {
        transition_enemy_state__9TObjEneDDFl(this, 1);
    }
    this->vfunc_88();
    this->copy_pos();
    ((TObjEnemy *)((u8 *)this))->submit_default_cursor_candidate();
    this->vfunc_100();
}
#pragma pop

Obj_800B3E40 *TObjEneBm3FlyNest__sub_800B3E40(Obj_800B3E40 *self, s16 flag) {
    if (self != 0) {
        self->vtbl = lbl_80491EE4;
        free_collision_body_parts(self);
        __destroy_arr(self->arr, (void *)__dt__15RenderFadeStateFv, 0x1c, 4);
        __dt__9TObjEneDDFv(self, 0);
        if (flag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

extern s32 bm3_fly_nest_class_name;

struct Vec_800B3EB8 { f32 x, y, z; };
struct Sub_800B3EB8 { u8 pad[0x1c]; };

struct Nest_800B3EB8 {
    s32 id;
    u8 pad4[0x18 - 0x4];
    void *vt;
    u16 f1C;
    u8 pad1E[0x24 - 0x1E];
    s32 f24;
    u8 pad28[0x34 - 0x28];
    s32 f34;
    Vec_800B3EB8 pos;
    u8 pad44[0xB8 - 0x44];
    s16 fB8;
    u8 padBA[0x300 - 0xBA];
    f32 f300;
    u8 pad304[0x326 - 0x304];
    s16 f326;
    u8 pad328[0x350 - 0x328];
    void *f350;
    u8 pad354[0x37C - 0x354];
    f32 f37C;
    u8 pad380[0x394 - 0x380];
    s32 f394;
    s32 f398[4];
    s32 f3A8;
    s32 f3AC;
    s32 f3B0;
    s32 f3B4;
    u16 f3B8[6];
    u16 f3C4;
    u8 pad3C6[2];
    Vec_800B3EB8 f3C8[2];
    Vec_800B3EB8 f3E0[8];
    Sub_800B3EB8 f440[4];
    f32 f4B0;
    s32 f4B4[9];
    f32 f4D8;
};

void *__ct__9TObjEneDDFP7TObject(void *, void *, void *);
void __construct_array(void *, void *, void *, int, int);
void __ct__15RenderFadeStateFv(void *);
void invoke_initialization_hook__9TObjEneDDFv(void *, void *);
void init_model__9TObjEneDDFv(void *, void *, int);
s32 reset_hp__9TObjEneDDFv(void *, int, int, int);
s32 initialize_enemy_state__9TObjEneDDFv(void *, int);

#define self ((Nest_800B3EB8 *)arg0)
#pragma push
#pragma opt_loop_invariants off
void *TObjEneBm3FlyNest__ct(void *arg0, void *arg1, void *arg2) {
    s32 i;

    __ct__9TObjEneDDFP7TObject(self, arg1, arg2);
    self->vt = lbl_80491EE4;
    __construct_array(self->f440, __ct__15RenderFadeStateFv, __dt__15RenderFadeStateFv, 0x1C, 4);
    self->id = bm3_fly_nest_class_name;
    invoke_initialization_hook__9TObjEneDDFv(self, arg2);
    ((TObjEneDD *)self)->init_position_vectors();
    self->f34 = *(s32 *)(*(u8 **)((int)lbl_805D5108 + 0x42C) + 0x18);
    self->f24 = *(s32 *)(*(u8 **)((int)lbl_805D5108 + 0x42C) + 0xC);
    init_model__9TObjEneDDFv(self, &bm3_flynest_collider_params, 1);
    self->f300 = lbl_805D9D20 + self->pos.y;
    ((TObjEneDD *)self)->vfunc_88();
    ((TObjMotion *)self)->set_field_d8((s32)bm3_flynest_hit_action_table);
    ((TObjMotion *)self)->set_field_dc(*(s32 *)((int)lbl_805D5108 + 0x430));
    self->fB8 = 0;
    ((TObjMotion *)self)->set_animation(self->fB8);
    ((TObjMotion *)self)->set_field_b8(self->fB8);
    reset_hp__9TObjEneDDFv(self, lbl_805D50F8, lbl_805D50FC, lbl_805D5100);
    ((TObjEneDD *)self)->check_state_flag_1();
    self->f350 = &bm3_fly_nest_params;
    initialize_enemy_state__9TObjEneDDFv(self, 4);
    self->f37C = lbl_805D9D10;
    init_params__17TObjEneBm3FlyNestFv(self);
    if (self->f394 > *(s16 *)((u8 *)arg2 + 2)) {
        self->f394 = *(s16 *)((u8 *)arg2 + 2);
    }
    for (i = 0; i < 4; i++) {
        self->f398[i] = 0;
    }
    self->f3A8 = 0;
    self->f3AC = 0;
    self->f3B0 = 0;
    self->f3B4 = 0;
    self->f3C4 = self->f1C + 1;
    for (i = 0; i < 6; i++) {
        self->f3B8[i] = 0xFFFF;
    }
    for (i = 0; i < 2; i++) {
        VecCopy((Vec *)&self->f3C8[i], (const Vec *)&self->pos);
    }
    self->f3C8[1].y += lbl_805D9D08;
    for (i = 0; i < 8; i++) {
        VecCopy((Vec *)&self->f3E0[i], (const Vec *)&self->pos);
    }
    for (i = 0; i < 4; i++) {
        ((RenderFadeState *)(&self->f440[i]))->activate_and_dispatch();
    }
    self->f4B0 = 0.0f;
    self->f4B4[0] = 0;
    self->f4B4[1] = 0;
    self->f4B4[2] = 0;
    self->f4B4[3] = 0;
    self->f4B4[4] = 0;
    self->f4B4[5] = 0;
    self->f4B4[6] = 0;
    self->f4B4[7] = 0;
    self->f4B4[8] = 0;
    self->f4D8 = 0.0f;
    self->f326 = 0;
    ((VObj_800B3EB8 *)self)->m85(self->f326, 4);
    return self;
}
#pragma pop
#undef self

int TObjEneBm3FlyNest__sub_800B4158(void) {  return (*(int *)&lbl_805D5108); }

void TObjEneBm3FlyNest::free_fly() {
    TObjEneBm3Fly::release_shared_data();
    if ((u32) lbl_805D5108 != 0U) {
        TLobby__sub_8001FE7C((void*)lbl_805D5108, 1);
        lbl_805D5108 = 0U;
    }
}

void *TObjEneBm3FlyNest::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x4DC);
    if (o != NULL) {
        o = TObjEneBm3FlyNest__ct(o, tl_04, arg0);
    }
    return o;
}

void TObjEneBm3FlyNest::load_resources() {
    Bodies_800B41E8 *bodies;
    (*(Vec_800B41E8 *)&TObjEneBm3FlyNest__attachment_sample_origin).x = 0.0f;
    (*(Vec_800B41E8 *)&TObjEneBm3FlyNest__attachment_sample_origin).y = 0.0f;
    (*(Vec_800B41E8 *)&TObjEneBm3FlyNest__attachment_sample_origin).z = 0.0f;
    lbl_805D510C = 0;
    (*(s32 *)&TObjEneBm3FlyNest_attachment_point_ptr) = 0;
    lbl_805D5114 = 0;
    bm3_fly_nest_attachment_index = 0;
    if (TObjEneDD::check_v2_mode() != 0) {
        lbl_805D5108 = load_enemy_bml_resource_named(&bm3_fly_nest_resource_desc, (void *)lbl_8043B380);
    } else {
        lbl_805D5108 = load_enemy_bml_resource((u8 *)&bm3_fly_nest_resource_desc);
    }
    lbl_805D50F8 = register_boss__6TLobbyFl(1);
    lbl_805D50FC = dispatch_shared_handler_b__6TLobbyFl(1);
    lbl_805D5100 = register_object__6TLobbyFl(1);
    lbl_805D5104 = dispatch_shared_handler_a__6TLobbyFl(1);
    TObjEneBm3Fly::load_resources();
    TObjEneBm3FlyNest::init_vertex_table();
    {
        Anim_800B41E8 anim = bm3_flynest_anim_binding;
        anim.motions = ((Res_800B41E8 *)lbl_805D5108)->motions;
        bodies = (Bodies_800B41E8 *)((Res_800B41E8 *)lbl_805D5108)->bodies;
        TLobby::spawn_npc_enemy((s16)8, bodies->model, bodies->textures, (s32)&anim, (f32)bm3_flynest_collider_params.radius, (f32)0.0f);
    }
}

void TObjEneBm3FlyNest::render_parts() {
    u8 *arg0 = (u8 *)this;
    ((s32 (*)(s32, void *))set_global_param__8TObjFishFl)(*(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 * *)&lbl_805D5108) + 0x42C)) + 0xC), (*(u8 * *)&lbl_805D5108));
    push_matrix();
    if (*(s32 *)&this->set_index == 0) {
        post_translate_matrix(*(void * *)&this->actorFlags);
    } else {
        post_translate_matrix(this->model);
    }
    post_translate_matrix((u8 *)&this->entity_id);
    ((s32 (*)(s32, s32))rotate_matrix_y)(0, *(s32 *)((s8 *)arg0 + 0x40));
    TObjPlayer::set_global_flag();
    draw_model_motion((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)(*(u8 * *)&lbl_805D5108) + 0x42C)) + 8)), (void *)(*(s32 *)&this->prev_position.y), this->prev_position.z);
    TObjPlayer::clear_global_state();
    pop_matrix();
}

#pragma push
#pragma fp_contract on
#pragma fp_contract on
void update_monest_carrier(u8 *self) {
    f32 lim;
    f32 v;
    f32 spd;

    lim = (f32) (*(u32 *)((s8 *)(((TObjEneBm3FlyNest_CarryFly *)self)->m_48) + 4) - 1);
    *(f32 *)((s8 *)self + 0x4C) += lbl_805D9D54;
    if (*(f32 *)((s8 *)self + 0x4C) > lim) {
        *(f32 *)((s8 *)self + 0x4C) -= lim;
    }
    switch (*(s32 *)((s8 *)self + 0x2C)) {
    case 0:
        if (*((TObjEneBm3FlyNest_CarryFly *)self)->m_38 == ((TObjEneBm3FlyNest_CarryFly *)self)->m_28) {
            Vec_800B4388 tmp;
            *(s32 *)((s8 *)self + 0x2C) = 1;
            VecCopy((Vec *)&tmp, (const Vec *)(self + 0x1C));
            ((s32 (*)(void *, s32))vec3_add_to)(&tmp, ((TObjEneBm3FlyNest_CarryFly *)self)->m_30);
            VecCopy((Vec *)(self + 0x50), (const Vec *)&tmp);
            ((s32 (*)(void *, s32))subtract_vector)(self + 0x50, *(s32 *)((s8 *)self + 0x34));
            *(f32 *)((s8 *)self + 0x54) -= lbl_805D9D1C;
            VecCopy((Vec *)(self + 0x1C), (const Vec *)(self + 0x50));
            *(f32 *)((s8 *)self + 0x5C) = normalize_vector_xz((Vec *)(self + 0x50));
            if (*(f32 *)((s8 *)self + 0x5C) <= lbl_805D9D58) {
                ((s32 (*)(void *))queue_destruction__7TObjectFv)(self);
                break;
            }
            ((TObjEneBm3FlyNest_CarryFly *)self)->m_60 = lbl_805D9D5C / (*(f32 *)((s8 *)self + 0x5C) * *(f32 *)((s8 *)self + 0x5C));
            *(f32 *)((s8 *)self + 0x64) = lbl_805D9D60;
        }
        play_persistent_sound((s32)(((s32 (*)(s32, s32))copy_target_state__17TObjEneBm3FlyNestFPv)(*(s32 *)((s8 *)self + 0x10), 0x4003A828)), (s32)self, (u32)(((TObjEneBm3FlyNest_CarryFly *)self)->m_30), 0, 0);
        TObjPlayer::play_effect_if_v2(-0x400);
        break;
    case 1:
        ((TObjEneBm3FlyNest_CarryFly *)self)->m_20 += lbl_805D9D18;
        if (((TObjEneBm3FlyNest_CarryFly *)self)->m_20 > 0.0f) {
            *(s32 *)((s8 *)self + 0x2C) = 2;
            *(f32 *)((s8 *)self + 0x54) = lbl_805D9D64 * *(f32 *)((s8 *)self + 0x5C);
        }
        play_persistent_sound((s32)(((s32 (*)(s32, s32))copy_target_state__17TObjEneBm3FlyNestFPv)(*(s32 *)((s8 *)self + 0x10), 0x4003A828)), (s32)self, (u32)(((TObjEneBm3FlyNest_CarryFly *)self)->m_30), 0, 0);
        TObjPlayer::play_effect_if_v2(-0x400);
        break;
    case 2:
        spd = *(f32 *)((s8 *)self + 0x5C);
        v = *(f32 *)((s8 *)self + 0x54);
        v = v - lbl_805D9D68 * spd;
        if (v < lbl_805D9D64 * -spd) {
            spawn_particle_effect((void *)(*(s32 *)((s8 *)self + 0x34)), 0xC8);
            ((s32 (*)(s32, s32, s32, s32))play_sound_effect)(((s32 (*)(s32, s32))copy_target_state__17TObjEneBm3FlyNestFPv)(*(s32 *)((s8 *)self + 0x10), 0x4003AB27), *(s32 *)((s8 *)self + 0x34), 0, 0);
            TObjPlayer::play_effect_if_v2(-0x400);
            ((s32 (*)(void *))queue_destruction__7TObjectFv)(self);
            break;
        }
        ((TObjEneBm3FlyNest_CarryFly *)self)->m_20 = ((TObjEneBm3FlyNest_CarryFly *)self)->m_60 * (v * v) + *(f32 *)((s8 *)self + 0x64);
        *(f32 *)((s8 *)self + 0x54) = v;
        v = lbl_805D9D64 * *(f32 *)((s8 *)self + 0x5C) + v;
        *(f32 *)((s8 *)self + 0x1C) = ((TObjEneBm3FlyNest_CarryFly *)self)->m_50 * v;
        *(f32 *)((s8 *)self + 0x24) = ((TObjEneBm3FlyNest_CarryFly *)self)->m_58 * v;
        play_persistent_sound((s32)(((s32 (*)(s32, s32))copy_target_state__17TObjEneBm3FlyNestFPv)(*(s32 *)((s8 *)self + 0x10), 0x4003A828)), (s32)self, (u32)(*(s32 *)((s8 *)self + 0x34)), 0, 0);
        TObjPlayer::play_effect_if_v2(-0x400);
        break;
    }
}
#pragma pop

void *__dt__26TObjEneBm3FlyNest_CarryFlyFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__26TObjEneBm3FlyNest_CarryFly;
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

}
TObjEneBm3FlyNest_CarryFly::TObjEneBm3FlyNest_CarryFly(TObject *parent, s32 a, s32 b, s32 unused, s32 c, s32 d) : TObject(parent) {
    Vec_800B4688 v;
    *(s32 *)((s8 *)this + 0) = TObjEneBm3FlyNest_CarryFly__name;
    this->m_30 = a;
    *(s32 *)((s8 *)this + 0x34) = b;
    *(s32 *)((s8 *)this + 0x38) = c;
    this->m_28 = d;
    VecCopy((Vec *)&v, (const Vec *)(*(void **)((s8 *)this + 0x30)));
    subtract_vector(&v, *(void **)((s8 *)this + 0x34));
    ((TObjBoss2Tunnel *)(&v))->update_scale();
    this->m_40 = (s32) (lbl_8043B398[0] * atan2_float(v.x, v.z));
    *(f32 *)((s8 *)this + 0x1C) = lbl_805D9D6C * v.x;
    this->m_20 = lbl_805D9D6C;
    *(f32 *)((s8 *)this + 0x24) = lbl_805D9D6C * v.z;
    *(s32 *)((s8 *)this + 0x48) = *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&lbl_805D5108) + 0x430)) + 0x54);
    *(f32 *)((s8 *)this + 0x4C) = (f32) (this->m_28 * 2);
    *(f32 *)((s8 *)this + 0x3C) = lbl_805D9D18;
    *(s32 *)((s8 *)this + 0x44) = 0;
    this->m_50 = 0.0f;
    *(f32 *)((s8 *)this + 0x54) = 0.0f;
    this->m_58 = 0.0f;
    *(f32 *)((s8 *)this + 0x5C) = 0.0f;
    *(f32 *)((s8 *)this + 0x64) = 0.0f;
    this->m_60 = 0.0f;
    *(s32 *)((s8 *)this + 0x2C) = 0;
}

void TObjEneBm3FlyNest::init_vertex_table() {
    f32 *v = fly_nest_vertex_table;
    v[3] = v[2] = v[1] = v[0] = 0.0f;
    v[5] = v[4] = lbl_805D9D6C;
    lbl_80500B24[0] = -1;
    lbl_80500B24[1] = -1;
    lbl_80500B2C.pv = fly_nest_vertex_table;
    lbl_80500B2C.pc = lbl_80500B24;
    lbl_80500B2C.d = 0;
    lbl_80500B2C.e = 2;
}

