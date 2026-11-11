#include "pso/math/FloatRounding.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/render/RenderFadeState.h"
#include "types.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/system/PadRumble.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/map/CsnQuery.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/hud/TMainCursor.h"

#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/goldragon/TBoss8DragonEffTail.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/vector.h"
#include "pso/enemy/dd/TObjEneDD_800BB804.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/MaterialAlphaCompare.h"

struct VBase_18 { char pad[0x18]; };

struct VObj_18 : VBase_18 {
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

struct FadeE_802FCF00 { u8 b[0x1C]; };

struct Fade_802FCF00 { u8 pad[0x6DC]; FadeE_802FCF00 e[4]; };

struct VBase_18_dc1f7f { char pad[0x18]; };

struct VObj_18_dc1f7f : VBase_18_dc1f7f {
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
    virtual s32 m89();
    virtual s32 m90();
    virtual void m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
};

struct Vec_802F7808 { f32 x, y, z; };

struct Vec_802F951C { f32 x, y, z; };

struct Rot_802F9D08 { s32 x, y, z; };

struct Obj_802FC674 {
    u8 pad0[0x38];
    f32 pos[3];
    u8 pad44[0x32C - 0x44];
    s16 f32C;
};

struct Induction_802F46F4_var_r31 { u8 bytes[0x1C]; };

struct Induction_802F46F4_var_r31_owner { u8 padding[0x6DC]; Induction_802F46F4_var_r31 elements[4]; };

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
};

struct S_802FB220 { u32 a; f32 b; f32 c; u32 d; u32 e; };

struct F3_802FB220 { f32 f[3]; };

struct G_802FB220 { F3_802FB220 *value; u8 rest[8]; };

extern "C" {
s32 VecCopy__FP3VecPC3Vec(void *, void *);
s32 queue_destruction__7TObjectFv(void *);
void project_sound_origin_from_camera(s32 arg0, u8 *arg1, f32 farg0);
s32 query_teammate_state__9TObjEneDDFv();
s32 is_main_phase_15__9TObjEneDDFv(void *);
s32 update__15RenderFadeStateFv(void *);
s32 add_radar_scaled_marker(void *, int, int, int, f32);
void release_grabbed_player__12TBoss8DragonFPv(TBoss8Dragon *arg0);
s32 is_health_low__12TBoss8DragonFPv(TBoss8Dragon *arg0);
extern s32 local_client_id;
extern s32 TBoss8Dragon__data_805D69B8;
extern const f32 lbl_805DEEE4;
void run_task__12TBoss8DragonFv(u8 *arg0);
void TBoss8Dragon__sub_802F48DC(TBoss8Dragon *dragon, Vec *target);
struct Dragon_802F8578;
void spawn_effect__12TBoss8DragonFii(s32 arg0, s32 arg1);
s32 update_linked_position__12TBoss8DragonFv(void *);
extern u8 *TBoss8Dragon__data_80541DDC[];
int TBoss8Dragon__sub_802FB984(void);
void send_action_packet__12TBoss8DragonFPvi(u8 *arg0, s32 arg1);
extern s32 lbl_805D69B4;
s32 TBoss8Dragon__sub_802FBFA4(u8 *arg0);
void play_cue_stream_file(s32 name);
void TBoss8Dragon__sub_802FB09C(s32 arg0);
s32 copy_pos_to_field688__12TBoss8DragonFPv(void* p);
s32 restore_target_pos__12TBoss8DragonFPv(void* p);
void spawn_effect_if_in_band__12TBoss8DragonFi(s32 arg0);
extern s32 lbl_80474B40[];
s32 fn_802F2E7C(int, void *, int);
s32 mask_flags__12TBoss8DragonFiii(s32 arg1, s32 arg2, s32 arg3);
void TBoss8Dragon__sub_802FB484(void);
void update_pos_from_data__12TBoss8DragonFv(void);
void TBoss8Dragon__sub_802FB70C(s32 arg0);
void TBoss8Dragon__sub_802FBA1C(TBoss8Dragon *arg0);
void spawn_trap__12TBoss8DragonFii(s32 arg0, s32 arg1);
void TBoss8Dragon__sub_802FC850(TBoss8Dragon *dragon);
f32 random_ratio__9TObjCharaFv();
f64 atan2_float(f32, f32);
void fill_value_array(s32);
f32 normalize_vector_xz__FP3Vec(void *);
void TBoss8Dragon__sub_802FB300(void);
extern const f64 TBoss8Dragon__data_80474B28;
void TBoss8Dragon__sub_802F7808(u8 *arg0, u32 arg1, s32 arg2);
s32 fn_8002AE08(int);
s32 approach_angle_limited(int, int, int);
u8 TBoss8Dragon__sub_802FABB4(void *arg0);
void TBoss8Dragon__sub_802FBBC8(u8 *arg0, s32 *arg1);
extern u16 TBoss8Dragon__data_805D69BC;
f32 sample_acceleration_curve(void *, f32);
void init_acceleration_curve(void *, f32, f32, f32, f32);
s32 angle_diff_s16(s32, s32);
void apply_ground_movement__12TBoss8DragonFPvPv(u8 *arg0, f32 *arg1);
void sync_target_pos__12TBoss8DragonFPv(void* p);
void TBoss8Dragon__sub_802FC500(u8 *arg0);
u16 get_entity_id(u8 *);
void *spawn_particle_effect_with_rotation(void *, void *, s32, s32);
s32 enemy_validate_retained_target(void *);
void * __nw__7TObjectFUl(int);
void TBoss8Dragon__sub_802FC9D8(u8 *arg0);
s32 __ct__21TBoss8DragonEffBreathFP7TObjectPvPvls(void *, void *, void *, void *, s32, u16);
extern const f32 lbl_805DEEAC;
f32 newton_sqrtf(f32);
s32 is_valid_target__9TObjEneDDFv(void);
f32 horizontal_distance_squared(void *, void *);
extern const f32 lbl_805DEED8;
s32 TBoss8Dragon__sub_802FC674(Obj_802FC674 *self, f32 *out);
s32 TBoss8Dragon__sub_802F46F4(s32 arg0);
extern S_802FB220 lbl_80474ACC;
extern S_802FB220 lbl_80474AE0;
void TBoss8Dragon__sub_802FB1B0(TBoss8Dragon *dragon, int x, f32 c);
void TBoss8Dragon__sub_802FB220(void *o, int x, u32 a);
struct VBase_18_574b0f { char pad[0x18]; };

struct VObj_18_574b0f : VBase_18_574b0f {
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
    virtual s32 m89();
    virtual s32 m90();
    virtual void m91();
    virtual void m92();
    virtual s32 m93();
};

struct RecoveredGlobal_802F45A0_lbl_80474580 { s32 value; u8 remaining[0x88]; };

typedef char RecoveredGlobal_802F45A0_lbl_80474580_size[sizeof(RecoveredGlobal_802F45A0_lbl_80474580) == 0x8C ? 1 : -1];

struct RecoveredGlobal_802F45A0_lbl_80541DE8 { Vec value; };

typedef char RecoveredGlobal_802F45A0_lbl_80541DE8_size[sizeof(RecoveredGlobal_802F45A0_lbl_80541DE8) == 0xC ? 1 : -1];

// Third argument of TBoss8Dragon::clone_node_tree, stored in every cloned node.
struct Boss8DragonNodeState {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};

struct RecoveredGlobal_802F45A0_lbl_80541DF4 {
    Vec value;
    Vec unkC;
    Vec unk18;
};

// Dragon BML resource loaded by TBoss8Dragon__sub_802FDA78; only its model set is read here.
struct Boss8DragonModelSet {
    u8 pad_0[0x8];
    void *node_tree;
};

struct Boss8DragonBmlRes {
    u8 pad_0[0x42C];
    Boss8DragonModelSet *models;
};

typedef char RecoveredGlobal_802F45A0_lbl_80541DF4_size[sizeof(RecoveredGlobal_802F45A0_lbl_80541DF4) == 0x24 ? 1 : -1];

struct Stack_802F4760 {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

struct RecoveredGlobal_802F4760_lbl_80541E30 {
    s32 value;
    u8 remaining[0x8];
};

struct RecoveredGlobal_802F4760_lbl_80541E3C {
    s32 value;
    u8 remaining[0x8];
};

struct Vec_802F481C { f32 x, y, z; };

struct Obj_802F44D8 {
    u8 pad0[0x34];
    s32 f34;
    u8 v38[0x5C - 0x38];
    s32 f5C;
    s32 f60;
    s32 f64;
    u8 v68[0xF8 - 0x68];
    s32 fF8;
    u8 padFC[0x3C0 - 0xFC];
    s32 f3C0;
    u8 pad3C4[0x3EC - 0x3C4];
    u8 f3EC[0x434 - 0x3EC];
    u8 f434[4];
};

struct Vec_802F4990 { f32 x, y, z; };

typedef char RecoveredGlobal_802F4760_lbl_80541E30_size[sizeof(RecoveredGlobal_802F4760_lbl_80541E30) == 0xC ? 1 : -1];

typedef char RecoveredGlobal_802F4760_lbl_80541E3C_size[sizeof(RecoveredGlobal_802F4760_lbl_80541E3C) == 0xC ? 1 : -1];

s32 TBoss8Dragon__data_80541DC8[5];
u8 *TBoss8Dragon__data_80541DDC[3];
RecoveredGlobal_802F45A0_lbl_80541DE8 lbl_80541DE8;
RecoveredGlobal_802F45A0_lbl_80541DF4 lbl_80541DF4;
Boss8DragonNodeState lbl_80541E18;
RecoveredGlobal_802F4760_lbl_80541E30 boss8_dragon_reference_pos_vec;
RecoveredGlobal_802F4760_lbl_80541E3C dragon_forward_reference_vec;

struct VBase_14_f8ef8c { char pad[0x14]; };

struct VObj_14_f8ef8c : VBase_14_f8ef8c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual s32 m5();
    u8 pad1C[4];
};

struct Self_802F51DC { u8 pad[0x6DC]; VObj_14_f8ef8c arr[4]; };

struct Vec_802F51DC { f32 x, y, z; };

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

struct VBase_14_df5984 { char pad[0x14]; };

struct VObj_14_df5984 : VBase_14_df5984 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual s32 m4();
    u8 pad1C[4];
};

struct Self_802F5434 { u8 pad[0x6DC]; VObj_14_df5984 arr[4]; };

struct VBase_18_2fe63c { char pad[0x18]; };

struct VObj_18_2fe63c : VBase_18_2fe63c {
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
    virtual s32 m89();
    virtual void m90();
    virtual void m91();
    virtual s32 m92();
    virtual void m93();
    virtual s32 m94();
};

struct VBase_18_667c9b { char pad[0x18]; };

struct VObj_18_667c9b : VBase_18_667c9b {
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
    virtual s32 m89();
    virtual s32 m90();
    virtual s32 m91();
    virtual s32 m92();
    virtual void m93();
    virtual s32 m94();
};

struct FadeBase_802F9A4C { char pad[0x14]; };

struct Fade_802F9A4C : FadeBase_802F9A4C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    u8 pad2[4];
};

struct Obj_802F9A4C { u8 pad[0x6DC]; Fade_802F9A4C fades[4]; };

struct VBase_802F9B8C { char pad[0x18]; };

struct VObj_802F9B8C : VBase_802F9B8C {
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
};

struct Stack_802FB0DC {
    s32 sp8;
    f32 spC;
};

struct V3_802FAC08 { f32 x, y, z; };

struct Obj_802FAC08 { u8 pad0[0x38]; f32 x; u8 pad1[4]; f32 z; };

struct S_802FB290 { u32 a; f32 b; f32 c; u32 d; u32 e; };

struct F3_802FB290 { f32 f[3]; };

struct G_802FB290 { F3_802FB290 *value; u8 rest[8]; };

typedef struct Vec_802FB304 { f32 x, y, z; } Vec_802FB304;

typedef struct Eff_802FB304 { s32 a; s32 b; f32 f; s32 c; s32 d; } Eff_802FB304;

struct RecoveredGlobal_802FB70C_TBoss8Dragon__data_804744C8 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_802FB70C_TBoss8Dragon__data_80541DC8 {
    s32 value;
    u8 remaining[0x10];
};

struct Stack_802FB778 {
    s32 sp8;
    u8 pad_C[0x4];
    f32 sp10;
    u8 trailing_storage[0x8];
};

struct RecoveredGlobal_802FB778_lbl_804744B4 {
    s32 value;
    u8 remaining[0x10];
};

struct RecoveredGlobal_802FB778_TBoss8Dragon__data_80541DDC {
    u8 * value;
    u8 remaining[0x8];
};

typedef char RecoveredGlobal_802FB70C_TBoss8Dragon__data_804744C8_size[sizeof(RecoveredGlobal_802FB70C_TBoss8Dragon__data_804744C8) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_802FB70C_TBoss8Dragon__data_80541DC8_size[sizeof(RecoveredGlobal_802FB70C_TBoss8Dragon__data_80541DC8) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_802FB778_lbl_804744B4_size[sizeof(RecoveredGlobal_802FB778_lbl_804744B4) == 0x14 ? 1 : -1];

typedef char RecoveredGlobal_802FB778_TBoss8Dragon__data_80541DDC_size[sizeof(RecoveredGlobal_802FB778_TBoss8Dragon__data_80541DDC) == 0xC ? 1 : -1];

struct Eff_802FB828 { u32 w[5]; };

struct RecoveredGlobal_802FBA1C_lbl_80474638 { s32 value; u8 remaining[0x1C]; };

typedef char RecoveredGlobal_802FBA1C_lbl_80474638_size[sizeof(RecoveredGlobal_802FBA1C_lbl_80474638) == 0x20 ? 1 : -1];

struct RecoveredGlobal_802FBA84_lbl_8047460C
{
  s32 value;
  u8 remaining[0x28];
};

struct RecoveredGlobal_802FBA84_lbl_80474658
{
  s32 value;
  u8 remaining[0x70];
};

struct RecoveredGlobal_802FBA84_lbl_804746CC
{
  s32 value;
  u8 remaining[0x6C];
};

typedef struct RecoveredGlobal_802FBA84_lbl_8047460C RecoveredGlobal_802FBA84_lbl_8047460C;

typedef struct RecoveredGlobal_802FBA84_lbl_80474658 RecoveredGlobal_802FBA84_lbl_80474658;

typedef struct RecoveredGlobal_802FBA84_lbl_804746CC RecoveredGlobal_802FBA84_lbl_804746CC;

typedef char RecoveredGlobal_802FBA84_lbl_8047460C_size[((sizeof(RecoveredGlobal_802FBA84_lbl_8047460C)) == 0x2C) ? (1) : (-1)];

typedef char RecoveredGlobal_802FBA84_lbl_80474658_size[((sizeof(RecoveredGlobal_802FBA84_lbl_80474658)) == 0x74) ? (1) : (-1)];

typedef char RecoveredGlobal_802FBA84_lbl_804746CC_size[((sizeof(RecoveredGlobal_802FBA84_lbl_804746CC)) == 0x70) ? (1) : (-1)];

struct VBase_18_be4a70
{
  char pad[0x18];
};

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

typedef struct VBase_18_be4a70 VBase_18_be4a70;

typedef struct VObj_18_be4a70 VObj_18_be4a70;

struct RecoveredGlobal_802FBF0C_TBoss8Dragon__data_80541DC8 {
    s32 value;
    u8 remaining[0x10];
};

typedef char RecoveredGlobal_802FBF0C_TBoss8Dragon__data_80541DC8_size[sizeof(RecoveredGlobal_802FBF0C_TBoss8Dragon__data_80541DC8) == 0x14 ? 1 : -1];

struct RecoveredGlobal_802FC500_TBoss8Dragon__data_804744A8 { s32 value; u8 remaining[0x8]; };

typedef char RecoveredGlobal_802FC500_TBoss8Dragon__data_804744A8_size[sizeof(RecoveredGlobal_802FC500_TBoss8Dragon__data_804744A8) == 0xC ? 1 : -1];

struct Obj_802FC580 {
    u8 pad0[0x698];
    s32 count;
    u8 pad69C[4];
    f32 vals[12];
};

struct V_802FC910 { f32 x, y, z; };

struct Boss_802FC910 { u8 pad[0x394]; V_802FC910 pos; };

struct D_A { char pad[0x18]; };

struct D_V : D_A {
    virtual void pv164();
    virtual void pv165();
    virtual void pv166();
    virtual void pv167();
    virtual void pv168();
    virtual void pv169();
    virtual void pv170();
    virtual void pv171();
    virtual void pv172();
    virtual void pv173();
    virtual void pv174();
    virtual void pv175();
    virtual void pv176();
    virtual void pv177();
    virtual void pv178();
    virtual void pv179();
    virtual void pv180();
    virtual void pv181();
    virtual void pv182();
    virtual void pv183();
    virtual void pv184();
    virtual void pv185();
    virtual void pv186();
    virtual void pv187();
    virtual void pv188();
    virtual void pv189();
    virtual void pv190();
    virtual void pv191();
    virtual void pv192();
    virtual void pv193();
    virtual void pv194();
    virtual void pv195();
    virtual void pv196();
    virtual void pv197();
    virtual void pv198();
    virtual void pv199();
    virtual void pv200();
    virtual void pv201();
    virtual void pv202();
    virtual void pv203();
    virtual void pv204();
    virtual void pv205();
    virtual void pv206();
    virtual void pv207();
    virtual void pv208();
    virtual void pv209();
    virtual void pv210();
    virtual void pv211();
    virtual void pv212();
    virtual void pv213();
    virtual void pv214();
    virtual void pv215();
    virtual void pv216();
    virtual void pv217();
    virtual void pv218();
    virtual void pv219();
    virtual void pv220();
    virtual void pv221();
    virtual void pv222();
    virtual void pv223();
    virtual void pv224();
    virtual void pv225();
    virtual void pv226();
    virtual void pv227();
    virtual void pv228();
    virtual void pv229();
    virtual void pv230();
    virtual void pv231();
    virtual void pv232();
    virtual void pv233();
    virtual void pv234();
    virtual void pv235();
    virtual void pv236();
    virtual void pv237();
    virtual void pv238();
    virtual void pv239();
    virtual void pv240();
    virtual void pv241();
    virtual void pv242();
    virtual void pv243();
    virtual void pv244();
    virtual void pv245();
    virtual void pv246();
    virtual void pv247();
    virtual void pv248();
    virtual void m85(s16, s32);
};

struct DelBase_802FD354 { char pad[0x18]; };

struct Del_802FD354 : DelBase_802FD354 {
    virtual ~Del_802FD354();
};

struct Pkt_802FBBFC { u8 hdr[2]; u16 a; s16 b; s16 c; s32 d; f32 e; f32 f; s8 g; };

struct VB_802FBBFC { u8 pad[0x18]; };

struct V_802FBBFC : VB_802FBBFC {
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
    virtual void m85(s32, int);
};

struct Pkt_802FBCBC { u8 hdr[2]; u16 a; s16 b; s16 c; s32 d; f32 e; f32 f; s8 g; };

typedef struct Vec_802FC380 { f32 x, y, z; } Vec_802FC380;

struct Vec_802FCA58 { f32 x, y, z; };

struct Part_802FCA58 { u8 pad0[4]; f32 f4; u8 pad8[0x20]; f32 f28; };

struct Cfg_802FCA58 { u8 pad[0x18]; s32 i18; s32 i1C; s32 i20; };

struct Vec_802FDC1C { f32 x, y, z; };

struct Cam_802FDC1C { s32 f0; f32 *p4; f32 *p8; };

int get_player_data__10TObjPlayerFi(int a0);
s32 get_current_floor();
s32 register_object__6TLobbyFl(int);
s32 register_boss__6TLobbyFl(int);
void free_bin_model_request(void*, int);
void TBoss1Dragon__sub_80027A80(u8 *arg0, u8 *arg1);
s32 set_frames__15ProtectionTimerFl(void *, int);
s32 spawn_particle_effect_with_flags(void *, void *, int);
void TObjEneEpsilon__sub_800B9384(u8 *arg0, s32 arg1, f32 farg0);
s32 update_linked_position__12TObjEneDD_STFf(f32);
void enemy_clear_target__12TObjEneDD_STFUs(void *);
void enemy_set_target_id(void *, u16);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
s32 reload_stats_keep_hp_tp__9TObjEneDDFv(void *, void *, int, void *);
s32 reset_hp__9TObjEneDDFPUcPUcPUc(void *, int, int, int);
void get_camera_ctrl__9TObjEneDDFv(s32, s32);
void update_camera_sequence__9TObjEneDDFv(void);
f32 rand_range__9TObjEneDDFff(void *, f32, f32);
f32 calc_elapsed_scaled__9TObjEneDDFv(void *);
int emit_effect_at_position__9TObjEneDDFPv(void*);
int emit_enemy_effect__9TObjEneDDFllPUcl(void*);
int setup_instance__9TObjEneDDFllPUcl(void*);
s32 is_alive__8TObjBaseFv(void);
s32 update_local_colliders_from_world(void *, void *);
s32 __dt__17AreaAttackHistoryFv(s32 arg0, s16 arg1);
void *__dt__15RenderFadeStateFv(void *arg0, s16 arg1);
u8 *get_enemy_entity(u16 arg0);
void free_collision_body_parts(void *);
s32 check_flag_100__10TObjPlayerFPv();
s32 start_freeze__10TObjPlayerFv(int);
s32 play_persistent_sound(s32 id, s32 a1, u32 src, s32 a3, s32 flags);
s32 play_sound_effect(s32, s32, s32, s32);
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, s32);
s32 is_closest_part__12TBoss8DragonFv();
void set_mode_params__12TBoss8DragonFSc(void *, unsigned char);
s32 TBoss8Dragon__sub_802F4760(void *owner, Vec *point, f32 farg0);
void update_movement__12TBoss8DragonFPv(u8 *arg0);
u8 check_attack_ready__12TBoss8DragonFPv(void *arg0);
int get_state_flags__12TBoss8DragonFPv(void* p);
int emit_effect__12TBoss8DragonFPv(void* p);
void draw_beam_segments__12TBoss8DragonFPvfff(u8 *arg0, f32 a, f32 b, f32 c);
void TBoss8Dragon__sub_802FB778(s32 arg0);
void TBoss8Dragon__sub_802FB828(u8 *arg0, s32 arg1);
void apply_6xA8_action__12TBoss8DragonFPvPv(u8 *arg0, u8 *arg1);
void TBoss8Dragon__sub_802FBE3C(TBoss8Dragon *dragon);
void TBoss8Dragon__sub_802FBEA4(TBoss8Dragon *dragon);
s32 select_target_in_front__12TBoss8DragonFPv(u8 *arg0);
s32 TBoss8Dragon__sub_802FC580(Obj_802FC580 *obj, f32 *out);
u8 TBoss8Dragon__sub_802FC88C(void *arg0);
s32 TBoss8Dragon__sub_802FCCBC(TBoss8Dragon *arg0);
void vfunc_61__12TBoss8DragonFv(void);
void vfunc_62__12TBoss8DragonFv(void);
void vfunc_63__12TBoss8DragonFv(void);
void vfunc_28__12TBoss8DragonFv(void);
u8 *TBoss8Dragon__ct(u8 *, void *, void *);
void TBoss8Dragon__sub_802FD9D0(void);
s32 eval_bezier_curve__12TBoss8DragonFPviiPvf(void *, int, int, void *, f32);
void __destroy_arr(void *, void *, u32, u32);
s32 mult_vec_array__10TObjPlayerFUll(int, void *, int, int);
f32 vec3_dot(void *, void *);
s32 rotate_matrix_z(s32, s32);
void subtract_vector(void *, void *);
s32 rotate_matrix_x(s32, s32);
s32 push_matrix();
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
s32 scale_matrix(int, f32, f32, f32);

extern u8 TBoss8Dragon__body_effect_parameters[];
extern s32 TBoss8Dragon__data_80541DC8[];
extern Boss8DragonBmlRes *TBoss8Dragon__data_805D6988;
extern s32 lbl_805D69A4;
extern const f32 lbl_805DEEE8;
extern s32 TBoss8Dragon__data_805D698C;
extern s32 TBoss8Dragon__data_805D6994;
extern s32 TBoss8Dragon__data_805D6998;
extern s32 TBoss8Dragon__data_805D699C;
extern s32 TBoss8Dragon__data_805D69A0;
extern s32 TBoss8Dragon__data_805D69A8;
extern u8 *TBoss8Dragon__data_805D69AC;
extern const f32 TBoss8Dragon__data_805DEEA4;
extern s32 TLobby__designated_client_id;
extern RecoveredGlobal_802FB778_lbl_804744B4 lbl_804744B4;
extern s32 boss8_dragon_init_state_params[];
extern RecoveredGlobal_802F45A0_lbl_80474580 dragon_camera_script_frame_table;
extern const RecoveredGlobal_802FBA84_lbl_8047460C dragon_next_action_table;
extern RecoveredGlobal_802FBA1C_lbl_80474638 boss8_dragon_state_transition_table;
extern const RecoveredGlobal_802FBA84_lbl_80474658 boss8_dragon_action_pick_table;
extern const RecoveredGlobal_802FBA84_lbl_804746CC boss8_dragon_action_pick_table_b;
extern Eff_802FB828 boss8_dragon_breath_eff_params;
extern S_802FB290 TBoss8Dragon__breath_params;
extern u8 controller_input_state[];
extern RecoveredGlobal_802F45A0_lbl_80541DE8 lbl_80541DE8;
extern RecoveredGlobal_802F45A0_lbl_80541DF4 lbl_80541DF4;
extern RecoveredGlobal_802F4760_lbl_80541E30 boss8_dragon_reference_pos_vec;
extern RecoveredGlobal_802F4760_lbl_80541E3C dragon_forward_reference_vec;
extern s32 lbl_805D6990;
extern f32 boss8_dragon_visibility_distance;
extern const f32 lbl_805DEEA0;
extern const f32 lbl_805DEEA8;
extern f32 lbl_805DEEB0;
extern const f32 lbl_805DEEB4;
extern const f32 lbl_805DEEB8;
extern const f32 lbl_805DEEBC;
extern const f32 lbl_805DEEC0;
extern const f32 lbl_805DEEC4;
extern const f32 lbl_805DEEC8;
extern s32 lbl_805D28BC;
struct Vec_802FB4DC { f32 x, y, z; };
extern const f32 lbl_805DEED0;
extern const f32 lbl_805DEED4;
extern const f32 lbl_805DEEDC;
extern const f32 lbl_805DEEE0;
extern void *tl_04;

extern "C" {
f32 calc_direct_attack_damage__12TBoss8DragonFPvPvPviii(void *a, void *b, struct Pair_802F3D18 *p, s32 x, s32 y, s32 z);
}
extern "C" {
void draw_motion_model__12TBoss8DragonFv();
}
extern "C" {
int TBoss8Dragon__sub_802F4360(void *p);
}
extern "C" {
void TBoss8Dragon__sub_802F4380(TBoss8Dragon *self);
}
extern "C" {
}
extern "C" {
}
extern "C" {
}
extern "C" {
struct Obj_802F7B70;
}
extern "C" {
void sub_802FA4E4__12TBoss8DragonFll();
}
extern "C" {
void vfunc_44__12TBoss8DragonFv();
}
extern "C" {
void vfunc_45__12TBoss8DragonFv();
}
extern "C" {
void vfunc_46__12TBoss8DragonFv();
}
extern "C" {
void vfunc_47__12TBoss8DragonFv();
}
extern "C" {
void vfunc_48__12TBoss8DragonFl();
}
extern "C" {
void vfunc_49__12TBoss8DragonFv();
}
extern "C" {
void vfunc_50__12TBoss8DragonFv();
}
extern "C" {
void vfunc_6__8TObjBaseFPsl();
}
extern "C" {
void vfunc_103__9TObjEneDDFPUc();
}
extern "C" {
void vfunc_79__9TObjEneDDFPl();
}
extern "C" {
void vfunc_84__9TObjEneDDFv();
}
extern "C" {
void vfunc_85__9TObjEneDDFv();
}
extern "C" {
void vfunc_86__9TObjEneDDFv();
}
extern "C" {
void vfunc_89__9TObjEneDDFv();
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
int vfunc_104__12TObjEneDD_STFf(void *p);
}
extern "C" {
void vfunc_83__12TObjEneDD_STFv();
}
extern "C" {
void vfunc_29__9TObjCharaFv();
}
extern "C" {
extern u8 apply_anti_technique__9TObjCharaFl[];
}
extern "C" {
void recalc_stats__9TObjCharaFv();
}
extern "C" {
extern u8 enemy_spawn_zalure_effect__9TObjCharaFv[];
}
extern "C" {
extern u8 enemy_spawn_jellen_effect__9TObjCharaFv[];
}
extern "C" {
extern u8 get_actor_level_index__9TObjCharaFv[];
}
extern "C" {
void consume_timer_field__9TObjCharaFl();
}
extern "C" {
extern u8 add_actor_exp__9TObjCharaFl[];
}
extern "C" {
extern u8 is_actor_cadence_frame__9TObjCharaFl[];
}
extern "C" {
extern u8 receive_weapon_special_attack__9TObjCharaFPvPv[];
}
extern "C" {
extern u8 apply_knockback_from_attacker__9TObjCharaFPUcf[];
}
extern "C" {
extern u8 receive_physical_attack__9TObjCharaFPvf[];
}
extern "C" {
void vfunc_67__9TObjCharaFf();
}
extern "C" {
void vfunc_66__9TObjCharaFv();
}
extern "C" {
void get_anim_node_position__9TObjCharaFlP3Vec();
}
extern "C" {
void vfunc_60__9TObjCharaFv();
}
extern "C" {
void vfunc_59__9TObjCharaFv();
}
extern "C" {
void vfunc_58__9TObjCharaFv();
}
extern "C" {
extern u8 apply_action_hold_status__9TObjCharaFf[];
}
extern "C" {
extern u8 clear_all_status_effects__9TObjCharaFv[];
}
extern "C" {
extern u8 cure_paralysis__9TObjCharaFv[];
}
extern "C" {
extern u8 cure_poison_ailment__9TObjCharaFv[];
}
extern "C" {
extern u8 apply_defense_stat_status__9TObjCharaFPv[];
}
extern "C" {
extern u8 apply_attack_stat_status__9TObjCharaFPv[];
}
extern "C" {
extern u8 calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf[];
}
extern "C" {
extern u8 roll_physical_accuracy__9TObjCharaFPvlf[];
}
extern "C" {
extern u8 select_melee_contact_body__9TObjCharaFPvf[];
}
extern "C" {
extern u8 update_defense_stat_status__9TObjCharaFv[];
}
extern "C" {
extern u8 update_attack_stat_status__9TObjCharaFv[];
}
extern "C" {
void update_shock_clock__9TObjCharaFv();
}
extern "C" {
extern u8 update_movement_status__9TObjCharaFv[];
}
extern "C" {
extern u8 update_action_hold_status__9TObjCharaFv[];
}
extern "C" {
extern u8 update_poison_status__9TObjCharaFv[];
}
extern "C" {
void vfunc_43__9TObjCharaFv();
}
extern "C" {
extern u8 is_target_in_attack_range__9TObjCharaFv[];
}
extern "C" {
void vfunc_18__9TObjCharaFPUc();
}
extern "C" {
extern u8 update_actor_ground_y__9TObjCharaFv[];
}
extern "C" {
extern u8 get_center__9TObjCharaFv[];
}
extern "C" {
extern u8 reset_motion_fields__9TObjCharaFv[];
}
extern "C" {
void interact__14TObjCollidableFl();
}
extern "C" {
void vfunc_74__9TObjEnemyFl();
}
extern "C" {
void apply_hit_message_flags__9TObjEnemyFPv();
}
extern "C" {
extern u8 apply_set_data__9TObjEnemyFPv[];
}
extern "C" {
void apply_switch_attack__9TObjCharaFv();
}
extern "C" {
void vfunc_78__9TObjCharaFl();
}
extern "C" {
void vfunc_77__9TObjCharaFv();
}
extern "C" {
void vfunc_76__9TObjCharaFf();
}
extern "C" {
void vfunc_75__9TObjCharaFf();
}
extern "C" {
void clear_lobby_object_state__9TObjEnemyFv();
}
extern "C" {
extern u8 apply_object_set_data__8TObjBaseFPv[];
}
extern "C" {
extern u8 classify_actor_view_detail__8TObjBaseFfff[];
}
extern "C" {
extern u8 update_object_view_visibility__8TObjBaseFff[];
}
extern "C" {
void get_name__9TObjEnemyFv();
}
extern "C" {
void get_pos__9TObjCharaFl();
}
extern "C" {
extern u8 lbl_8047473C[];
}
extern "C" {
extern u8 lbl_80474754[];
}
extern "C" {
extern u8 lbl_8047476C[];
}
extern "C" {
extern u8 lbl_80474784[];
}
extern "C" {
extern u8 lbl_804747A0[];
}
extern "C" {
extern u8 lbl_804747C0[];
}
extern "C" {
extern u8 lbl_804747DC[];
}
extern "C" {
extern u8 lbl_804747F8[];
}
extern "C" {
extern u8 lbl_80474818[];
}
extern "C" {
extern u8 lbl_80474834[];
}
extern "C" {
extern u8 lbl_80474850[];
}
extern "C" {
extern u8 lbl_8047486C[];
}
extern "C" {
extern u8 lbl_8047488C[];
}
extern "C" {
extern u8 lbl_804748A8[];
}
extern "C" {
extern u8 lbl_804748C4[];
}
extern "C" {
extern u8 lbl_804748E0[];
}
extern "C" {
extern u8 lbl_804748FC[];
}
extern "C" {
extern u8 lbl_80474918[];
}
extern "C" {
extern u8 lbl_80474938[];
}
extern "C" {
extern u8 lbl_80474958[];
}
extern "C" {
extern u8 lbl_80474974[];
}
extern "C" {
extern u8 lbl_80474990[];
}
extern "C" {
extern u8 lbl_804749AC[];
}
extern "C" {
extern u8 lbl_804749C8[];
}
extern "C" {
extern u8 lbl_804749E8[];
}
extern "C" {
extern u8 lbl_80474A04[];
}
extern "C" {
extern u8 lbl_80474A24[];
}
extern "C" {
extern u8 lbl_80474A44[];
}
extern "C" {
extern u8 lbl_80474A64[];
}
extern "C" {
extern u8 lbl_80474A80[];
}
extern "C" {
void reset_pose__9TObjCharaFv();
}
extern "C" {
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
}
extern "C" {
void try_start_action__9TObjCharaFll();
}
extern "C" {
void render_shadows__12TBoss8DragonFv();
}
extern "C" {
s32 vfunc_37__9TObjCharaFv(u8 *arg0);
}
extern "C" {
void update_flag30_timer__9TObjCharaFv();
}
extern void *lbl_804E4D8C[4];
extern void *lbl_804E4D9C[27];
void update_colliders__12TBoss8DragonFPv(TBoss8Dragon *arg0);
u8 *__dt__12TBoss8DragonFv(u8 *arg0, s16 arg1);
s32 TBoss8Dragon__camera_offset_index_table[5] = {
    0x12, 0x14, 0x15, 0x16, 0x17,
};
s32 lbl_804E4C1C[3] = {
    0x11, 0x12, 0x13,
};
void *TBoss8Dragon__data_804E4C28[5] = {
    (void *)0x0, (void *)0x1, (void *)0x2, (void *)0x3,
    (void *)0x4,
};
void *lbl_804E4C3C[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x500050,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804E4C58[77] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41200000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41200000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41700000, (void *)0x0, (void *)0x0, (void *)0x8003,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41700000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41200000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41200000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0,
};
void *lbl_804E4D8C[4] = {
    (void *)&lbl_8047473C, (void *)&lbl_80474754, (void *)&lbl_8047476C, (void *)0x0,
};
void *lbl_804E4D9C[27] = {
    (void *)&lbl_80474784, (void *)&lbl_804747A0, (void *)&lbl_804747C0, (void *)&lbl_804747DC,
    (void *)&lbl_804747F8, (void *)&lbl_80474818, (void *)&lbl_80474834, (void *)&lbl_80474850,
    (void *)&lbl_8047486C, (void *)&lbl_8047488C, (void *)&lbl_804748A8, (void *)&lbl_804748C4,
    (void *)&lbl_804748E0, (void *)&lbl_804748FC, (void *)&lbl_80474918, (void *)&lbl_80474938,
    (void *)&lbl_80474958, (void *)&lbl_80474974, (void *)&lbl_80474990, (void *)&lbl_804749AC,
    (void *)&lbl_804749C8, (void *)&lbl_804749E8, (void *)&lbl_80474A04, (void *)&lbl_80474A24,
    (void *)&lbl_80474A44, (void *)&lbl_80474A64, (void *)0x0,
};
void *lbl_804E4E08[4] = {
    (void *)&lbl_80474A80, (void *)&lbl_804E4D8C, (void *)&lbl_804E4D9C, (void *)0x3001a,
};
void *lbl_804E4E18[112] = {
    (void *)0x10000, (void *)0xb, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0xd, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0xa, (void *)0x3f333333, (void *)0x0,
    (void *)0x30000, (void *)0x12, (void *)0x3f666666, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x4, (void *)0x3ecccccd, (void *)0x0,
    (void *)0x30000, (void *)0x5, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0xc, (void *)0x3f000000, (void *)0x0,
    (void *)0x20009, (void *)0x8, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x2, (void *)0x3e99999a, (void *)0x0,
    (void *)0x30000, (void *)0x9, (void *)0x3e99999a, (void *)0x0,
    (void *)0x30000, (void *)0x11, (void *)0x3f19999a, (void *)0x0,
    (void *)0x30000, (void *)0x10, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0xf, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0xe, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x7, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x13, (void *)0x3f800000, (void *)0x0,
    (void *)0x2000e, (void *)0x6, (void *)0x3f800000, (void *)0x0,
    (void *)0x20010, (void *)0x14, (void *)0x3f8ccccd, (void *)0x0,
    (void *)0x30000, (void *)0x0, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x19, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x18, (void *)0x3f000000, (void *)0x0,
    (void *)0x20017, (void *)0x17, (void *)0x3f800000, (void *)0x0,
    (void *)0x10000, (void *)0x15, (void *)0x3f800000, (void *)0x0,
    (void *)0x20010, (void *)0x16, (void *)0x3f000000, (void *)0x80000000,
    (void *)0x30000, (void *)0x17, (void *)0x3f800000, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3f000000, (void *)0x80000000,
    (void *)0x20008, (void *)0x11, (void *)0x3f19999a, (void *)0x0,
};
void *lbl_804E4FD8[3] = {
    (void *)0x0, (void *)0x419e6666, (void *)0xc0a00000,
};
void *lbl_804E4FE4[3] = {
    (void *)0x0, (void *)0x41cb70a4, (void *)0x4235ae14,
};
void *lbl_804E4FF0[9] = {
    (void *)0x0, (void *)0x41b80000, (void *)0xc0400000, (void *)0x0,
    (void *)0x42000000, (void *)0x0, (void *)0x0, (void *)0x41c80000,
    (void *)0xc0a00000,
};
void *lbl_804E5014[33] = {
    (void *)0x0, (void *)0x41300000, (void *)0x42200000, (void *)0x0,
    (void *)0x40a00000, (void *)0x420c0000, (void *)0x0, (void *)0x42480000,
    (void *)0x42700000, (void *)0x0, (void *)0x41a00000, (void *)0xc2f00000,
    (void *)0x0, (void *)0x42f00000, (void *)0xc2f00000, (void *)0x0,
    (void *)0x41c80000, (void *)0xc1f00000, (void *)0x0, (void *)0x42480000,
    (void *)0xc2a00000, (void *)0x0, (void *)0x42f00000, (void *)0x42480000,
    (void *)0x0, (void *)0x43960000, (void *)0xc1f00000, (void *)0x0,
    (void *)0x42200000, (void *)0x0, (void *)0x43960000, (void *)0x42f00000,
    (void *)0x42480000,
};
extern void *boss8_dragon_bezier_points[16];
extern void *boss8_dragon_bezier_points_3[12];
extern void *TBoss8Dragon__dive_height_curve[12];
extern void *__vt__12TBoss8Dragon[107];
#define TBoss8Dragon__data_804E4C28 ((s32 *)TBoss8Dragon__data_804E4C28)

struct Self_802F87EC { u8 pad[0x6DC]; VObj_14_f8ef8c arr[4]; };

struct Dragon_802F951C : VObj_18_444bc5 {
    u8 pad1C[0x60 - 0x1C];
    s32 angle;
    u8 pad64[0xB8 - 0x64];
    s16 field_B8;
    u8 padBA[0x394 - 0xBA];
    u8 f394[0x3A0 - 0x394];
    Vec_802F951C dir;
    f32 f3AC;
    u8 pad3B0[0x3C0 - 0x3B0];
    s32 field_3C0;
    u8 pad3C4[0x5E0 - 0x3C4];
    Vec_802F951C v5E0;
    u8 curve0[0x610 - 0x5EC];
    u8 curve1[0x654 - 0x610];
    s32 sign;
    u8 pad658[0x84C - 0x658];
    s32 field_84C;
    u8 pad850[0x85C - 0x850];
    s32 base;
    u8 pad860[0x864 - 0x860];
    f32 field_864;
};

}

void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
void set_collider_contact_low(u8 *arg0);
void set_collider_contact_high(u8 *arg0);
void build_6xA8_gol_dragon_boss_actions(void *p);
typedef char Induction_802F46F4_var_r31_size_check[sizeof(Induction_802F46F4_var_r31) == 0x1C ? 1 : -1];
typedef char Induction_802F46F4_var_r31_offset_check[offsetof(Induction_802F46F4_var_r31_owner, elements) == 0x6DC ? 1 : -1];
extern "C" {
struct Info_802F4DD4 { u8 pad[8]; s32 a; s32 b; };
struct Vec_802F4DD4 { f32 x, y, z; };
struct Drg_802F4DD4 {
    u8 pad0[0x38];
    Vec_802F4DD4 pos;
    u8 pad44[0xB8 - 0x44];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x41C - 0xC4];
    u8 dir41C[0x458 - 0x41C];
    f32 f458;
    u8 pad45C[4];
    f32 f460;
    u8 pad464[0x470 - 0x464];
    f32 f470;
    u8 pad474[4];
    f32 f478;
    u8 pad47C[0x680 - 0x47C];
    s32 f680;
    u8 pad684[0x760 - 0x684];
    Info_802F4DD4 *info;
    u8 pad764[0x84C - 0x764];
    s32 phase;
    s32 f850;
    s32 step;
    s32 f858;
    u8 pad85C[0x894 - 0x85C];
    void *demo;
};
u8 *__ct__16TBoss8DragonDemoFv(u8 *arg0, s32 arg1, s32 arg2, f32 farg0);
}
void create_boss8_piller_ctrl(s32 arg0, s32 arg1, f32 farg0);
extern s32 lbl_80474B18[];
extern s32 tl_01;
extern "C" {
struct Obj_802FAC08;
struct VBase_18_599a64 { char pad[0x18]; };
struct VObj_18_599a64 : VBase_18_599a64 {
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
};
struct VBase_18_81e212 { char pad[0x18]; };
struct VObj_18_81e212 : VBase_18_81e212 {
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
    virtual s32 m72(s32);
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
};
struct Vec_802F6838 { f32 x, y, z; };
struct Rot_802F6838 { s32 x, y, z; };
s32 restore_player_cameras(void);
void activate_camera_mode(s32, f32);
void set_scripted_camera_pose(void *, void *, void *);
void rotate_xz_pair_by_angle(f32 *arg0, f32 *arg1, s32 arg2);
void refresh_and_send_entity_flags__9TObjEnemyFv(void);
void vec3_add_to(void *, void *);
extern u8 lbl_804744F0[];
extern u8 lbl_804744FC[];
extern u8 lbl_80474B30[];
struct VBase_18_2719b2x { char pad[0x18]; };
struct VObj_18_2719b2x : VBase_18_2719b2x {
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
    virtual s32 m90();
    virtual s32 m91();
    virtual void m92();
    virtual void m93();
    virtual s32 m94();
};
struct Obj_802FC580;
struct Vec_802F7B70 { f32 x, y, z; };
struct VBase_802F7B70 { u8 pad[0x18]; };
struct VObj_802F7B70 : VBase_802F7B70 {
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
    virtual void m92(); virtual void m93(); virtual void m94();
};
struct Obj_802F7B70 : VObj_802F7B70 {
    u8 pad1C[0x38 - 0x1C];
    Vec_802F7B70 pos;
    u8 pad44[0x5C - 0x44];
    s32 rotX;
    s32 rotY;
    s32 rotZ;
    u8 pad68[0xB8 - 0x68];
    s16 fb8;
    u8 padBA[0x394 - 0xBA];
    Vec_802F7B70 f394;
    f32 f3a0;
    f32 f3a4;
    f32 f3a8;
    f32 f3ac;
    u8 pad3B0[0x3C0 - 0x3B0];
    u32 f3c0;
    u8 pad3C4[0x414 - 0x3C4];
    f32 f414;
    u8 pad418[0x650 - 0x418];
    s32 f650;
    u8 pad654[0x680 - 0x654];
    s32 f680;
    u8 pad684[0x84C - 0x684];
    s32 state;
    s32 timer;
    u8 pad854[0x85C - 0x854];
    s32 angle;
    s32 spin;
    f32 f864;
    f32 f868;
    f32 f86c;
    u8 pad870[0x890 - 0x870];
    s32 spawned;
};
void sync_target_pos__12TBoss8DragonFPv(void *p);
void TBoss8Dragon__sub_802FC060(void *, s32);
extern void *TBoss8Dragon__dive_height_curve[];
struct Pair_802F8578 { f32 a; f32 b; };
struct Ids_802F8578 { u8 pad[0x8]; s32 id8; s32 idC; };
struct Vec_802F8578 { f32 x, y, z; };
struct Dragon_802F8578 : VObj_18_444bc5 {
    u8 pad1C[0x38 - 0x1C];
    Vec_802F8578 pos;
    u8 pad44[0xB8 - 0x44];
    s16 field_B8;
    u8 padBA[0x326 - 0xBA];
    s16 field_326;
    u8 pad328[0x3C0 - 0x328];
    s32 field_3C0;
    u8 pad3C4[0x680 - 0x3C4];
    s32 field_680;
    u8 pad684[0x754 - 0x684];
    s32 field_754;
    u8 pad758[0x760 - 0x758];
    Ids_802F8578 *field_760;
    u8 pad764[0x84C - 0x764];
    s32 field_84C;
    s32 field_850;
    u8 pad854[0x864 - 0x854];
    f32 field_864;
};
struct VBase_18_444bc5x { char pad[0x18]; };
struct VObj_18_444bc5x : VBase_18_444bc5x {
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
struct Vec_802F8F88 { f32 x, y, z; };
void rotate_vec_xz(void *, void *, s32);
u32 spawn_continuous_particle_effect_with_flags(void *, void *, int);
s32 get_random_scaled__9TObjEneDDFv(void *);
s32 TBoss8DragonEffBullet__ct(void *, void *, void *, void *, s32, u16);
extern f32 lbl_805D69C0;
void subtractive_rng_seed(void *, s32);
f32 calc_random_ratio__10TObjPlayerFv(void *);
// Slot 87: per-action event dispatch through a table of handler members.
}
struct VBase_18_802FD47C { char pad[0x18]; };
struct VObj_18_802FD47C : VBase_18_802FD47C {
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
struct Vec_802FD47C { f32 x, y, z; };
struct E1C_802FD47C { u8 b[0x1C]; };
struct D_802FD47C {
    u8 pad0[0x38];
    Vec_802FD47C pos;
    u8 pad44[0x3EC - 0x44];
    Vec_802FD47C v3EC[3];
    Vec_802FD47C v410;
    Vec_802FD47C v41C;
    Vec_802FD47C v428;
    Vec_802FD47C v434[0x22];
    u8 pad5CC[0x6A0 - 0x5CC];
    f32 a6A0[12];
    u8 pad6D0[0x6DC - 0x6D0];
    E1C_802FD47C e6DC[4];
};
extern "C" {
s32 __ct__14SubtractiveRngFv(void *arg0);
void __ct__12TObjEneDD_STFP7TObject(void *, void *, void *);
void initialize_enemy_state__9TObjEneDDFl(void *, int);
void init_model__9TObjEneDDFP13CollisionBodyl(void *, void *, int);
void invoke_initialization_hook__9TObjEneDDFPv(void *, void *);
u8 *__ct__17AreaAttackHistoryFl(u8 *arg0, s32 arg1);
void __ct__7TObjectFP7TObject(void *, void *);
u8 *TBoss8DragonColli__ct(u8 *arg0, s32 arg1);
void *TBoss8Dragon__sub_802F3C24(void *arg0, void *arg1);
void *TBoss8DragonEffTail__ct(void *, void *, void *);
void __construct_array(void *, void *, void *, int, int);
void __ct__15RenderFadeStateFv(void *);
extern s32 boss8_dragon_class_name;
}

extern "C" {
void get_camera_offsets__12TBoss8DragonFPvPv(Vec_802FDC1C *arg0, Vec_802FDC1C *arg1);
}
void handle_6xA8_gol_dragon_boss_actions(void *boss8_dragon);

// --- folded from the fragments ---
struct Node_802FDDD4 {
    u8 pad0[4];
    s32 v;
    u8 pad1[0x24];
    Node_802FDDD4 *c0;
    Node_802FDDD4 *c1;
    u8 pad2[4];
};
extern "C" {
void copy_model_node(u8 *, u8 *);
Node_802FDDD4 *clone_node_tree__12TBoss8DragonFPvPvi(Node_802FDDD4 *src, Node_802FDDD4 *dst, s32 v);
extern const f32 lbl_805D9E80;
f32 lbl_805D6980 = 5.0f * lbl_805D9E80;
f32 lbl_805D6984 = 7.0f * lbl_805D9E80;
Boss8DragonBmlRes *TBoss8Dragon__data_805D6988;
s32 TBoss8Dragon__data_805D698C;
s32 lbl_805D6990;
s32 TBoss8Dragon__data_805D6994;
s32 TBoss8Dragon__data_805D6998;
s32 TBoss8Dragon__data_805D699C;
s32 TBoss8Dragon__data_805D69A0;
s32 lbl_805D69A4;
s32 TBoss8Dragon__data_805D69A8;
u8 *TBoss8Dragon__data_805D69AC;
f32 boss8_dragon_visibility_distance;
s32 lbl_805D69B4;
s32 TBoss8Dragon__data_805D69B8;
u16 TBoss8Dragon__data_805D69BC;
}
// (from _802FDDD4)
struct RecoveredGlobal_802F3CA0_lbl_80474508 {
    s32 value;
    u8 remaining[0x24];
};
struct RecoveredGlobal_802F3CA0_lbl_80474530 {
    s32 value;
    u8 remaining[0x24];
};
struct RecoveredGlobal_802F3CA0_lbl_80474558 {
    s32 value;
    u8 remaining[0x24];
};
struct VBase_18_26a62c { char pad[0x18]; };
struct VObj_18_26a62c : VBase_18_26a62c {
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
typedef struct A_802F3D6C { u8 pad0[4]; s32 idx; u8 pad8[8]; } A_802F3D6C;
typedef struct Anim_802F3D6C { u8 pad0[4]; u32 nframes; } Anim_802F3D6C;
typedef struct B_802F3D6C { u8 pad0[4]; Anim_802F3D6C *anim; } B_802F3D6C;
struct Pair_802F3D18 { s32 a; s32 b; };
extern "C" {
extern RecoveredGlobal_802F3CA0_lbl_80474508 boss8_dragon_mode_params;
extern RecoveredGlobal_802F3CA0_lbl_80474530 dragon_mode_params_a;
extern RecoveredGlobal_802F3CA0_lbl_80474558 dragon_mode_params_b;
void TObjLight__sub_801337F8(s32);
void draw_model_motion(void *arg0, void *arg1, f32 farg0);
extern s32 current_scene_light;
extern s32 model_render_flags;
f32 receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(void *, void *, Pair_802F3D18 *, s32, s32, s32);
typedef char RecoveredGlobal_802F3CA0_lbl_80474508_size[sizeof(RecoveredGlobal_802F3CA0_lbl_80474508) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_802F3CA0_lbl_80474530_size[sizeof(RecoveredGlobal_802F3CA0_lbl_80474530) == 0x28 ? 1 : -1];
typedef char RecoveredGlobal_802F3CA0_lbl_80474558_size[sizeof(RecoveredGlobal_802F3CA0_lbl_80474558) == 0x28 ? 1 : -1];
}
// (from _802F3CA0)
extern "C" {
s32 render_nodes__7TObjectFv(s32, s32);
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
}
// (from _802F3EE4)
struct RecoveredGlobal_802F4098_main_task { s32 value; u8 remaining[0x30]; };
typedef char RecoveredGlobal_802F4098_main_task_size[sizeof(RecoveredGlobal_802F4098_main_task) == 0x34 ? 1 : -1];
typedef struct Obj_802F3F20 {
    u8 pad0[0x326];
    s16 x326;
    u8 pad328[0x434 - 0x328];
    Vec pts[8];
} Obj_802F3F20;
struct VBase_14_681f8e { char pad[0x14]; };
struct VObj_14_681f8e : VBase_14_681f8e {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual s32 m6();
};
struct Fade_802F4114 { u8 pad[0x1C]; };
struct Obj_802F4114 { u8 pad[0x6DC]; Fade_802F4114 fades[4]; };
extern "C" {
s32 get_mode__11TCameraCtrlFPv(void *);
u8 *find_entity_by_id(void);
extern s32 boss8_dragon_point_index_table[];
extern u8 *camera_ctrl_instance;
s32 isFading__15RenderFadeStateCFv(int);
s32 has_enough_enemies__12TBoss8DragonFv();
extern s32 current_scene_light;
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
}
// (from _802F3F20)
extern "C" {
s32 draw__10TObjMotionFv(void *, int);
}
// (from _802F42A0)
extern "C" {
int check_demo_mode__10TObjPlayerFv(void*);
}
// (from _802F4324)
struct RecoveredGlobal_802F4380_main_task { s32 value; u8 remaining[0x30]; };
typedef char RecoveredGlobal_802F4380_main_task_size[sizeof(RecoveredGlobal_802F4380_main_task) == 0x34 ? 1 : -1];
struct VBase_802F4380 { char pad[0x18]; };
struct VObj_802F4380 : VBase_802F4380 {
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
    virtual void m101();
    virtual void m102();
    virtual void m103();
    virtual void draw_motion_model();
};
extern "C" {
s32 defer_render__7TObjectFv(void *);
BOOL is_split_screen(void); // TObjPlayer_80011014.h, whose other prototypes clash here
s32 TBoss8Dragon__sub_802F3F20(u8 *arg0); // defined further down
}
void set_tev_swap_channels(u8 r, u8 g, u8 b, u8 a);
void init_tev_swap();
// (from _802F4380)
extern "C" {
struct VOff_802F4480_arg0 { char pad_0[0x410]; char f_410[1]; char pad_411[0xB]; char f_41C[1]; };
}
// (from _802F4480)
void build_6xA8_gol_dragon_boss_actions(void* p) { *(u8*)((char*)p + 0x0) = 168; *(u8*)((char*)p + 0x1) = 6; }

void TBoss8Dragon::bswap_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }

void TBoss8Dragon::send_swapped_packet() { bswap_packet(); send_subcommand((u8 *)this); }

void TBoss8Dragon::vfunc_50() {  }

void TBoss8Dragon::vfunc_49() {  }

void TBoss8Dragon::vfunc_48(s32) {  }

void TBoss8Dragon::vfunc_47() {  }

void TBoss8Dragon::vfunc_46() {  }

void TBoss8Dragon::vfunc_45() {  }

void TBoss8Dragon::vfunc_44() {  }

extern "C" {
Node_802FDDD4 *clone_node_tree__12TBoss8DragonFPvPvi(Node_802FDDD4 *src, Node_802FDDD4 *dst, s32 v) {
    Node_802FDDD4 *cur = dst;
    dst = dst + 1;
    copy_model_node((u8 *)cur, (u8 *)src);
    cur->v = v;
    if (src->c0 != NULL) {
        cur->c0 = dst;
        dst = clone_node_tree__12TBoss8DragonFPvPvi(src->c0, dst, v);
    }
    if (src->c1 != NULL) {
        cur->c1 = dst;
        dst = clone_node_tree__12TBoss8DragonFPvPvi(src->c1, dst, v);
    }
    return dst;
}
}

#define F(t, o) (*(t *)((u8 *)this + (o)))
extern "C" {
void get_camera_offsets__12TBoss8DragonFPvPv(Vec_802FDC1C *arg0, Vec_802FDC1C *arg1) {
    s32 mode;
    s32 idx;

    if (TBoss8Dragon__data_805D69AC == NULL) {
        mode = 1;
    } else if (TBoss8Dragon::find_target_enemy() != 0) {
        mode = 0;
    } else if (*(s16 *)((s8 *)TBoss8Dragon__data_805D69AC + 0x326) == 0x17) {
        mode = 1;
    } else {
        switch (*(s32 *)((s8 *)TBoss8Dragon__data_805D69AC + 0x3E4)) {
        case 0:
        default:
            idx = 0;
            break;
        case 1:
            idx = 1;
            break;
        case 2:
            idx = 2;
            break;
        }
        VecCopy__FP3VecPC3Vec(arg0, (Vec_802FDC1C *) lbl_804E4FF0 + idx);
        VecCopy__FP3VecPC3Vec(arg1, (Vec_802FDC1C *) lbl_804E5014 + idx);
        if (*(u32 *)((s8 *)TBoss8Dragon__data_805D69AC + 0x64C) == 1) {
            arg1->y += TBoss8Dragon__data_805DEEA4;
            arg1->z += TBoss8Dragon__data_805DEEA4;
        }
        return;
    }
    arg0->x = 0.0f;
    arg1->x = 0.0f;
    switch (mode) {
    case 1:
    default:
        if (TCameraCtrl::get_camera_id() == 2) {
            VecCopy__FP3VecPC3Vec(arg0, lbl_804E4FD8);
            VecCopy__FP3VecPC3Vec(arg1, lbl_804E4FE4);
            break;
        }
        arg0->y = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p4[0];
        arg0->z = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p4[1];
        arg1->y = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p4[2];
        arg1->z = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p4[3];
        break;
    case 0:
        arg0->y = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p4[4];
        arg0->z = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p4[5];
        arg1->y = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p8[0];
        arg1->z = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p8[1];
        break;
    }
}

void TBoss8Dragon__sub_802FDA78(void) {
    s32 i;
    s32 j;

    TBoss8Dragon__data_805D6988 = (Boss8DragonBmlRes *)load_enemy_bml_resource((u8 *)lbl_804E4E08);
    lbl_805D69A4 = ((TObjBoss2Tunnel *)TBoss8Dragon__data_805D6988->models->node_tree)->count_tree_nodes();
    TBoss8Dragon__data_805D69A8 = (s32)TQuestVmDownLoadServer::alloc(lbl_805D69A4 * 0x50);
    lbl_80541E18.unk0 = 0;
    lbl_80541E18.unk4 = 0;
    lbl_80541E18.unk8 = 0.0f;
    lbl_80541E18.unkC = 0.0f;
    lbl_80541E18.unk10 = 0.0f;
    lbl_80541E18.unk14 = 0.0f;
    TBoss8Dragon::clone_node_tree(TBoss8Dragon__data_805D6988->models->node_tree, (void *)TBoss8Dragon__data_805D69A8,
                                  (int)&lbl_80541E18);
    TBoss8Dragon__data_805D698C = 0;
    lbl_805D6990 = 60;
    lbl_80541DE8.value.x = 0.0f;
    lbl_80541DE8.value.y = 0.0f;
    lbl_80541DE8.value.z = 0.0f;
    lbl_80541DF4.value.x = 0.0f;
    lbl_80541DF4.value.y = 0.0f;
    lbl_80541DF4.value.z = 5.0f;
    lbl_80541DF4.unkC.x = 0.0f;
    lbl_80541DF4.unkC.y = sin_table_lookup(-0x1555);
    lbl_80541DF4.unkC.z = cos_table_lookup(-0x1555);
    vec3_add_to(&lbl_80541DF4.unkC, &lbl_80541DF4.value);
    lbl_80541DF4.unk18.x = 0.0f;
    lbl_80541DF4.unk18.y = lbl_805DEEE8;
    lbl_80541DF4.unk18.z = 1.0f;
    TBoss8Dragon__data_805D6994 = 0;
    TBoss8Dragon__data_805D6998 = 0;
    TBoss8Dragon__data_805D699C = 0;
    TBoss8Dragon__data_805D69A0 = 0;
    TBoss8Dragon__data_805D69AC = 0;
    for (i = 0; i < 5; i++) {
        TBoss8Dragon__data_80541DC8[i] = (s32)TLobby::dispatch_shared_handler_b(TBoss8Dragon__camera_offset_index_table[i]);
    }
    for (j = 0; j < 3; j++) {
        TBoss8Dragon__data_80541DDC[j] = (u8 *)TLobby::dispatch_shared_handler_a(lbl_804E4C1C[j]);
    }
    lbl_805D69B4 = 0;
    TBoss8Dragon__data_805D69B8 = 0;
    TBoss8Dragon__data_805D69BC = 0xFFFF;
    TWindowCtrl::init_all_slots();
    fn_802FE48C();
}

void *TBoss8Dragon::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x8A4);
    if (o != NULL) {
        o = TBoss8Dragon__ct((u8 *)o, tl_04, arg0);
    }
    return o;
}

void TBoss8Dragon::free_static() {
    if ((u32) (*(u32 *)&TBoss8Dragon__data_805D69A8) != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((u32)((void*)(*(u32 *)&TBoss8Dragon__data_805D69A8)));
        (*(u32 *)&TBoss8Dragon__data_805D69A8) = 0U;
    }
    if ((u32) TBoss8Dragon__data_805D6988 != 0U) {
        free_bin_model_request((void*)TBoss8Dragon__data_805D6988, 1);
        TBoss8Dragon__data_805D6988 = 0U;
    }
}

void TBoss8Dragon__sub_802FD9D0(void) { (*(int *)&TBoss8Dragon__data_805D69B8) = 0; }

#define TBoss8Dragon__data_805D6988 ((u8 *)TBoss8Dragon__data_805D6988)
#define lbl_804E4C3C ((u8 *)lbl_804E4C3C)
#define lbl_804E4C58 ((u8 *)lbl_804E4C58)
#define lbl_804E4E18 ((u8 *)lbl_804E4E18)
u8 *TBoss8Dragon__ct(u8 *arg0, void *arg1, void *arg2) {
    u32 sp8[4];
    s32 i;
    s32 j;
    void *p;
    u8 *q;
    u8 *cfg;
    D_802FD47C *d = (D_802FD47C *) arg0;

    __ct__12TObjEneDD_STFP7TObject(arg0, arg1, arg2);
    *(u8 * *)&((TBoss8Dragon *)arg0)->m_18 = (u8 *)__vt__12TBoss8Dragon;
    __ct__7TObjectFP7TObject(arg0 + 0x3C4, 0);
    TObjBoss2Tunnel::reset_coords_pass((s32)(arg0 + 0x5EC));
    TObjBoss2Tunnel::reset_coords_pass((s32)(arg0 + 0x610));
    __construct_array(arg0 + 0x6DC, (void *) __ct__15RenderFadeStateFv, (void *) __dt__15RenderFadeStateFv, 0x1C, 4);
    __ct__14SubtractiveRngFv(arg0 + 0x764);
    ((TBoss8Dragon *)arg0)->m_0 = boss8_dragon_class_name;
    if (TBoss8Dragon__data_805D69AC == NULL) {
        TBoss8Dragon__data_805D69AC = arg0;
    }
    invoke_initialization_hook__9TObjEneDDFPv(arg0, arg2);
    ((TBoss8Dragon *)arg0)->m_3c0 = 0;
    if (((TObjEnemy *)arg0)->exchange_object_state((s32)sp8, (s16)1) != 0 && (sp8[0] & 0x12008) == 0x12008) {
        ((TBoss8Dragon *)arg0)->m_3c0 |= 8;
    }
    ((TObjEneDD *)arg0)->init_position_vectors();
    ((TBoss8Dragon *)arg0)->m_34 = *(s32 *)((s8 *)(*(u8 **)((s8 *)TBoss8Dragon__data_805D6988 + 0x42C)) + 8);
    ((TBoss8Dragon *)arg0)->m_24 = *(s32 *)((s8 *)(*(u8 **)((s8 *)TBoss8Dragon__data_805D6988 + 0x42C)) + 0xC);
    ((TBoss8Dragon *)arg0)->m_68 = 2.0f;
    *(f32 *)((s8 *)arg0 + 0x6C) = 2.0f;
    ((TBoss8Dragon *)arg0)->m_70 = 2.0f;
    init_model__9TObjEneDDFP13CollisionBodyl(arg0, lbl_804E4C58, 7);
    ((TBoss8Dragon *)arg0)->m_b0 = 0;
    ((TObjMotion *)arg0)->set_field_d8((s32)lbl_804E4E18);
    ((TObjMotion *)arg0)->set_field_dc(*(s32 *)((s8 *)TBoss8Dragon__data_805D6988 + 0x430));
    ((TBoss8Dragon *)arg0)->m_b8 = 0;
    ((TObjMotion *)arg0)->set_animation(((TBoss8Dragon *)arg0)->m_b8);
    ((TObjMotion *)arg0)->set_field_b8(((TBoss8Dragon *)arg0)->m_b8);
    reset_hp__9TObjEneDDFPUcPUcPUc(arg0, register_boss__6TLobbyFl(0x12), TBoss8Dragon__data_80541DC8[TBoss8Dragon__data_804E4C28[0]], register_object__6TLobbyFl(0x12));
    ((TObjEneDD *)arg0)->check_state_flag_1();
    *(u8 **)((s8 *)arg0 + 0x350) = lbl_804E4C3C;
    initialize_enemy_state__9TObjEneDDFl(arg0, 0x4C);
    ((TBoss8Dragon *)arg0)->m_37c = 20.0f;
    ((TObjEneDD_ST *)arg0)->enemy_init_acquire_period(0xA);
    ((TObjEneDD_ST *)arg0)->enemy_init_validate_period(0xA);
    ((TBoss8Dragon *)arg0)->m_3e4 = 0;
    ((TBoss8Dragon *)arg0)->m_3c0 |= 1;
    for (i = 0; i < 3; i++) {
        VecCopy__FP3VecPC3Vec(&d->v3EC[i], &d->pos);
    }
    VecCopy__FP3VecPC3Vec(&d->v410, &d->pos);
    VecCopy__FP3VecPC3Vec(&d->v41C, &d->pos);
    VecCopy__FP3VecPC3Vec(&d->v428, &d->pos);
    for (i = 0; i < 0x22; i++) {
        VecCopy__FP3VecPC3Vec(&d->v434[i], &d->pos);
    }
    ((TBoss8Dragon *)arg0)->m_5cc = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x5D0) = 0.0f;
    ((TBoss8Dragon *)arg0)->m_5d4 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x5D8) = 0.0f;
    ((TBoss8Dragon *)arg0)->m_5dc = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x5E0) = 0.0f;
    ((TBoss8Dragon *)arg0)->m_5e4 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x5E8) = 0.0f;
    ((TObjBoss2Tunnel *)(arg0 + 0x5EC))->reset_coords();
    ((TObjBoss2Tunnel *)(arg0 + 0x610))->reset_coords();
    VecCopy__FP3VecPC3Vec(arg0 + 0x634, arg0 + 0x38);
    VecCopy__FP3VecPC3Vec(arg0 + 0x640, arg0 + 0x38);
    ((TBoss8Dragon *)arg0)->m_64c = 0;
    ((TBoss8Dragon *)arg0)->m_650 = 0;
    ((TBoss8Dragon *)arg0)->m_654 = 1;
    ((TBoss8Dragon *)arg0)->m_65c = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x660) = 0.0f;
    ((TBoss8Dragon *)arg0)->m_670 = 0.0f;
    ((TBoss8Dragon *)arg0)->m_674 = 0;
    ((TBoss8Dragon *)arg0)->m_678 = 0;
    cfg = TBoss8Dragon__data_80541DDC[2];
    ((TBoss8Dragon *)arg0)->m_67a = *(f32 *)((s8 *)cfg + 8) * ((TBoss8Dragon *)arg0)->m_2b8 / 100.0f;
    q = *(u8 **)((s8 *)arg0 + 0x2B0);
    *(f32 *)((s8 *)q + 0x10) = TBoss8Dragon__data_805DEEA4;
    TBoss8Dragon__sub_802FC850((TBoss8Dragon *)arg0);
    p = __nw__7TObjectFUl(0xCC);
    if (p != NULL) {
        p = TBoss8DragonEffTail__ct(p, arg0, arg0 + 0x4E8);
    }
    *(void **)((s8 *)arg0 + 0x67C) = p;
    p = ::operator new(0x10);
    if (p != NULL) {
        p = __ct__17AreaAttackHistoryFl((u8 *)p, 4);
    }
    *(void **)((s8 *)arg0 + 0x680) = p;
    p = __nw__7TObjectFUl(0x28);
    if (p != NULL) {
        p = TBoss8DragonColli__ct((u8 *)p, (s32)(arg0 + 0x3C4));
    }
    *(void **)((s8 *)arg0 + 0x684) = p;
    *(f32 *)((s8 *)arg0 + 0x688) = 0.0f;
    ((TBoss8Dragon *)arg0)->m_68c = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x690) = 0.0f;
    ((TBoss8Dragon *)arg0)->m_694 = 0.0f;
    ((TBoss8Dragon *)arg0)->m_698 = 0;
    ((TBoss8Dragon *)arg0)->m_69c = 0;
    for (i = 0; i < 0xC; i++) {
        d->a6A0[i] = 0.0f;
    }
    ((TBoss8Dragon *)arg0)->m_6d0 = 0;
    for (j = 0; j < 4; j++) {
        ((RenderFadeState *)(&d->e6DC[j]))->activate_and_dispatch();
    }
    ((TBoss8Dragon *)arg0)->m_74c = 0;
    ((TBoss8Dragon *)arg0)->m_750 = 0xFFFF;
    ((TBoss8Dragon *)arg0)->m_754 = 0;
    ((TBoss8Dragon *)arg0)->m_758 = 0;
    set_mode_params__12TBoss8DragonFSc(arg0, 2);
    ((TBoss8Dragon *)arg0)->m_84c = 0;
    ((TBoss8Dragon *)arg0)->m_850 = 0;
    ((TBoss8Dragon *)arg0)->m_854 = 0;
    ((TBoss8Dragon *)arg0)->m_858 = 0;
    ((TBoss8Dragon *)arg0)->m_85c = 0;
    ((TBoss8Dragon *)arg0)->m_860 = 0;
    *(f32 *)((s8 *)arg0 + 0x864) = 0.0f;
    ((TBoss8Dragon *)arg0)->m_868 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x86C) = 0.0f;
    ((TBoss8Dragon *)arg0)->m_870 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x874) = 0.0f;
    ((TBoss8Dragon *)arg0)->m_878 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x87C) = 0.0f;
    ((TBoss8Dragon *)arg0)->m_880 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x884) = 0.0f;
    ((TBoss8Dragon *)arg0)->m_888 = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x88C) = 0.0f;
    ((TBoss8Dragon *)arg0)->m_890 = 0;
    ((TBoss8Dragon *)arg0)->m_894 = 0;
    ((TBoss8Dragon *)arg0)->m_898 = 0;
    ((TBoss8Dragon *)arg0)->m_89c = 0;
    *(u8 **)((s8 *)arg0 + 0x6D8) = controller_input_state + 0xC0;
    ((TBoss8Dragon *)arg0)->m_6d4 = 0;
    ((TBoss8Dragon *)arg0)->m_326 = 0;
    if (is_main_phase_15__9TObjEneDDFv(controller_input_state) != 0) {
        if (((TObjEneDD *)arg0)->update_lobby_state() != 0) {
            ((TBoss8Dragon *)arg0)->m_3e0 = 0;
        } else {
            ((TBoss8Dragon *)arg0)->m_3e0 = 1;
        }
    } else {
        ((TBoss8Dragon *)arg0)->m_3e0 = 0;
    }
    TBoss8Dragon::init_default(arg0);
    if (TBoss8Dragon__data_805D69AC == arg0) {
        ((TBoss8Dragon *)arg0)->m_326 = 0x1E;
        TBoss8Dragon__sub_802F3C24(arg0, arg2);
    }
    if (!(((TBoss8Dragon *)arg0)->m_3c0 & 8)) {
        ((VObj_18_802FD47C *) arg0)->m85(((TBoss8Dragon *)arg0)->m_326, 4);
    }
    ((TBoss8Dragon *)arg0)->m_8a0 = 0;
    return arg0;
}

#undef TBoss8Dragon__data_805D6988
#undef lbl_804E4C3C
#undef lbl_804E4C58
#undef lbl_804E4E18
}
u8 *__dt__12TBoss8DragonFv(u8 *arg0, s16 arg1) {
    if (arg0 != NULL) {
        ((TBoss8Dragon *)arg0)->m_18 = (s32 *)__vt__12TBoss8Dragon;
        if (*(Del_802FD354 **)((s8 *)arg0 + 0x684) != NULL) {
            delete *(Del_802FD354 **)((s8 *)arg0 + 0x684);
            *(Del_802FD354 **)((s8 *)arg0 + 0x684) = NULL;
        }
        if (*(void **)((s8 *)arg0 + 0x680) != NULL) {
            __dt__17AreaAttackHistoryFv((s32)(*(void **)((s8 *)arg0 + 0x680)), 1);
            *(void **)((s8 *)arg0 + 0x680) = NULL;
        }
        if (*(Del_802FD354 **)((s8 *)arg0 + 0x67C) != NULL) {
            delete *(Del_802FD354 **)((s8 *)arg0 + 0x67C);
            *(Del_802FD354 **)((s8 *)arg0 + 0x67C) = NULL;
        }
        free_collision_body_parts(arg0);
        if (TBoss8Dragon__data_805D69AC == arg0) {
            TBoss8Dragon__data_805D69AC = NULL;
        }
        __destroy_arr(arg0 + 0x6DC, (void *)__dt__15RenderFadeStateFv, 0x1C, 4);
        TObjBoss2Tunnel::maybe_delete((s32)(arg0 + 0x610), (s16)(-1));
        TObjBoss2Tunnel::maybe_delete((s32)(arg0 + 0x5EC), (s16)(-1));
        __dt__7TObjectFv(arg0 + 0x3C4, -1);
        __dt__12TObjEneDD_STFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TBoss8Dragon::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0_2;
    s32 temp_r30;
    s32 temp_r30_2;
    s32 i;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((VObj_18 *)(arg0))->m103();
        return;
    }
    if (*(s32 *)&this->m_3c0 & 8) {
        ((TObjEnemy *)arg0)->send_entity_set_flags();
        queue_destruction__7TObjectFv(arg0);
        return;
    }
    if ((s32) *(s32 *)&this->m_74c != 0) {
        ((TBoss8Dragon *)arg0)->freeze_player_at_self();
        *(s32 *)&this->m_754 = (s32) (*(s32 *)&this->m_754 + 1);
    } else if ((((s32 (*)(void)) is_main_phase_15__9TObjEneDDFv)() != 0) && ((s32) *(s32 *)&this->m_6d4 == 0)) {
        temp_r30 = *(s32 *)&this->m_3e0;
        if (((TObjEneDD *)arg0)->update_lobby_state() != 0) {
            *(s32 *)&this->m_3e0 = 0;
            if ((s32) *(s32 *)&this->m_3e0 != temp_r30) {
                *(s32 *)&this->m_8a0 = 1;
            }
        } else {
            *(s32 *)&this->m_3e0 = 1;
        }
    }
    temp_r30_2 = query_teammate_state__9TObjEneDDFv();
    ((VObj_18 *)(arg0))->m39();
    ((VObj_18 *)(arg0))->m40();
    if (temp_r30_2 == 0) {
        if (this->m_326 == 0x15 || this->m_326 == 0x16 || this->m_326 == 0x17) {
            *(s32 *)&this->unk_30 = (s32) (*(s32 *)&this->unk_30 | 0x800);
        } else {
            *(s32 *)&this->unk_30 = (s32) (*(s32 *)&this->unk_30 & 0xFFFFF7FF);
        }
        if ((s32) *(s32 *)&this->m_74c != 0) {
            if ((s32) this->m_750 == (s32) local_client_id) {
                if ((((VObj_18 *)(arg0))->m30() != 0) && (is_health_low__12TBoss8DragonFPv((TBoss8Dragon *)arg0) != 0)) {
                    if ((s16) this->m_32c < (s16) *(s16 *)&this->m_67a) {
                        this->m_32c = *(s16 *)&this->m_67a;
                    }
                    ((TObjEneDD *)arg0)->clear_attack_receipts();
                }
                if ((s32) TBoss8Dragon__data_805D69B8 == 0) {
                    release_grabbed_player__12TBoss8DragonFPv((TBoss8Dragon *)arg0);
                } else {
                    ((TBoss8Dragon *)arg0)->check_death();
                }
                ((VObj_18 *)(arg0))->m85(this->m_326, 8);
                ((VObj_18 *)(arg0))->m85(this->m_326, 0);
            } else {
                if ((((VObj_18 *)(arg0))->m30() != 0) && (is_health_low__12TBoss8DragonFPv((TBoss8Dragon *)arg0) != 0)) {
                    if ((s16) this->m_32c < (s16) *(s16 *)&this->m_67a) {
                        this->m_32c = *(s16 *)&this->m_67a;
                    }
                    ((TObjEneDD *)arg0)->clear_attack_receipts();
                }
                if ((s32) TBoss8Dragon__data_805D69B8 == 0) {
                    release_grabbed_player__12TBoss8DragonFPv((TBoss8Dragon *)arg0);
                }
                ((VObj_18 *)(arg0))->m85(this->m_326, 0);
            }
        } else {
            temp_r0_2 = *(s32 *)&this->m_3e0;
            if (temp_r0_2 != 1) {
                if (temp_r0_2 == 2) {
                    ((VObj_18 *)(arg0))->m85(this->m_326, 2);
                } else {
                    if ((((VObj_18 *)(arg0))->m30() != 0) && (is_health_low__12TBoss8DragonFPv((TBoss8Dragon *)arg0) != 0)) {
                        if ((s16) this->m_32c < (s16) *(s16 *)&this->m_67a) {
                            this->m_32c = *(s16 *)&this->m_67a;
                        }
                        ((TObjEneDD *)arg0)->clear_attack_receipts();
                    }
                    ((TBoss8Dragon *)arg0)->select_next_action();
                }
                ((VObj_18 *)(arg0))->m85(this->m_326, 8);
                ((VObj_18 *)(arg0))->m85(this->m_326, 0);
            } else {
                if ((((VObj_18 *)(arg0))->m30() != 0) && (is_health_low__12TBoss8DragonFPv((TBoss8Dragon *)arg0) != 0)) {
                    if ((s16) this->m_32c < (s16) *(s16 *)&this->m_67a) {
                        this->m_32c = *(s16 *)&this->m_67a;
                    }
                    ((TObjEneDD *)arg0)->clear_attack_receipts();
                }
                ((VObj_18 *)(arg0))->m85(this->m_326, 0);
            }
        }
    }
    ((TObjEneDD *)arg0)->sub_800BBA0C();
    ((VObj_18 *)(arg0))->m86();
    ((TBoss8Dragon *)arg0)->store_position();
    ((TObjEnemy *)arg0)->submit_default_cursor_candidate();
    add_radar_scaled_marker((u8 *)&this->m_38, -0x5DB4, 1, 1, 2.0f);
    VecCopy__FP3VecPC3Vec((u8 *)&this->m_640, arg0 + 0x2FC);
    if (temp_r30_2 == 0) {
        ((TObject *)(arg0 + 0x3C4))->run_tasks();
    }
    project_sound_origin_from_camera((s32)(arg0 + 0x38), (u8 *)(arg0 + 0x634), lbl_805DEEE4);
    if (!(*(s32 *)&this->m_3c0 & 0x100)) {
        for (i = 0; i < 4; i++) {
            update__15RenderFadeStateFv((void *) &((Fade_802FCF00 *) arg0)->e[i]);
        }
    }
}

void TBoss8Dragon::select_next_action() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r4;
    temp_r4 = this->m_3c0;
    if (temp_r4 & 0x40) {
        if (!(temp_r4 & 0x20) && (this->m_32c <= 0)) {
            send_action_packet__12TBoss8DragonFPvi(arg0, 0x16);
            return;
        }
        goto block_14;
    }
    if (((s32 (*)(void))is_health_low__12TBoss8DragonFPv)() != 0) {
        if (!(this->m_3c0 & 0x10)) {
            if (check_damage_reaction() == 0) {
                if (((s32 (*)(void *))TBoss8Dragon__sub_802FB984)(arg0) != 0) {
                    return;
                }
                goto block_14;
            }
        } else {
            goto block_14;
        }
    } else {
        if (!(this->m_3c0 & 0x20) && (this->m_32c <= 0)) {
            if ((s32) this->m_3e4 == 1) {
                send_action_packet__12TBoss8DragonFPvi(arg0, 0xC);
                return;
            }
            send_action_packet__12TBoss8DragonFPvi(arg0, 0x15);
            return;
        }
block_14:
        if ((s32) lbl_805D69B4 != 0) {
            ((VObj_18 *)(arg0))->m85(this->m_326, 2);
            return;
        }
        if ((s32) this->m_74c != 0) {
            ((VObj_18 *)(arg0))->m85(this->m_326, 0xB);
            return;
        }
        ((VObj_18 *)(arg0))->m85(this->m_326, 9);
    }
}

void TBoss8Dragon::check_death() {
    if (((s32 (*)(void))is_health_low__12TBoss8DragonFPv)() != 0) {
        if (check_damage_reaction() != 0) {
            return;
        }
        goto block_8;
    }
    if (!(this->m_3c0 & 0x20) && (this->m_32c <= 0)) {
        if ((s32) this->m_3e4 == 1) {
            ((s32 (*)(void *, s32))send_action_packet__12TBoss8DragonFPvi)(this, 0xC);
            return;
        }
        ((s32 (*)(void *, s32))send_action_packet__12TBoss8DragonFPvi)(this, 0x15);
        return;
    }
block_8:
    ((D_V *) this)->m85(this->m_326, 0xB);
}

void TBoss8Dragon::vfunc_28() {  }

void TBoss8Dragon::vfunc_63() {  }

void TBoss8Dragon::vfunc_62() {  }

void TBoss8Dragon::vfunc_61() {  }

void TBoss8Dragon::set_state_22() { if (this->m_326 != 22) { ((int (*)(void*, void*))send_action_packet__12TBoss8DragonFPvi)(this, (void*)22); } }

s32 TBoss8Dragon__sub_802FCCBC(TBoss8Dragon *boss8_dragon) {
    if (boss8_dragon->m_326 != 0x1E) {
        return 1;
    }
    return 0;
}

void TBoss8Dragon::store_position() {
    s32 arg0 = (s32)this;
    ((s32 (*)(s32, s32))VecCopy__FP3VecPC3Vec)(arg0 + 0x2FC, arg0 + 0x434);
    ((s32 (*)(s32, s32))VecCopy__FP3VecPC3Vec)(arg0 + 0x74, arg0 + 0x2FC);
}

void update_colliders__12TBoss8DragonFPv(TBoss8Dragon *boss8_dragon) {
    Vec_802FCA58 pts[7];
    Vec_802FCA58 *p;
    s32 i;

    p = pts;
    VecCopy__FP3VecPC3Vec(p++, (u8 *)boss8_dragon + 0x434);
    VecCopy__FP3VecPC3Vec(p++, (u8 *)boss8_dragon + 0x470);
    VecCopy__FP3VecPC3Vec(p++, (u8 *)boss8_dragon + 0x458);
    VecCopy__FP3VecPC3Vec(p++, (u8 *)boss8_dragon + 0x440);
    VecCopy__FP3VecPC3Vec(p++, (u8 *)boss8_dragon + 0x5B4);
    VecCopy__FP3VecPC3Vec(p++, (u8 *)boss8_dragon + 0x4C4);
    VecCopy__FP3VecPC3Vec(p, (u8 *)boss8_dragon + 0x500);
    update_local_colliders_from_world(boss8_dragon, pts);
    for (i = 0; i < 7; i++) {
        if ((*(Part_802FCA58 * *)&boss8_dragon->m_a4)[i].f4 >= 30.0f) {
            set_collider_contact_high((u8 *)(&(*(Part_802FCA58 * *)&boss8_dragon->m_a4)[i]));
        } else {
            set_collider_contact_low((u8 *)(&(*(Part_802FCA58 * *)&boss8_dragon->m_a4)[i]));
        }
    }
    if (boss8_dragon->m_326 != 9) {
        set_collider_contact_high((u8 *)(&(*(Part_802FCA58 * *)&boss8_dragon->m_a4)[3]));
        set_collider_contact_high((u8 *)(&(*(Part_802FCA58 * *)&boss8_dragon->m_a4)[4]));
    }
    (*(Part_802FCA58 * *)&boss8_dragon->m_a4)[0].f28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i20;
    (*(Part_802FCA58 * *)&boss8_dragon->m_a4)[1].f28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i1C;
    (*(Part_802FCA58 * *)&boss8_dragon->m_a4)[2].f28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i1C;
    (*(Part_802FCA58 * *)&boss8_dragon->m_a4)[3].f28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i20;
    (*(Part_802FCA58 * *)&boss8_dragon->m_a4)[4].f28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i20;
    (*(Part_802FCA58 * *)&boss8_dragon->m_a4)[5].f28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i18;
    (*(Part_802FCA58 * *)&boss8_dragon->m_a4)[6].f28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i20;
}

s32 update_linked_position__12TBoss8DragonFv(void * _w0) {
    update_linked_position__12TObjEneDD_STFf(lbl_805DEEE0);
}

void TBoss8Dragon__sub_802FC9D8(u8 *arg0) {
    f32 temp_f1;
    f32 temp_f2;
    temp_f2 = *(f32 *)((s8 *)arg0 + 0x394);
    *(f32 *)((s8 *)arg0 + 0x5CC) = (f32) (temp_f2 - *(f32 *)((s8 *)arg0 + 0x410));
    *(f32 *)((s8 *)arg0 + 0x5D0) = 0.0f;
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x39C);
    *(f32 *)((s8 *)arg0 + 0x5D4) = (f32) (temp_f1 - *(f32 *)((s8 *)arg0 + 0x418));
    *(f32 *)((s8 *)arg0 + 0x5D8) = ((f32 (*)(void *, f32, f32))normalize_vector_xz__FP3Vec)(arg0 + 0x5CC, temp_f1, temp_f2);
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::calc_orbit_xz(f32 *arg1, f32 *arg2) {
    *arg1 = (lbl_805DEEDC * sin_table_lookup(this->m_60)) + *(f32 *)&this->m_38;
    *arg2 = (lbl_805DEEDC * cos_table_lookup(this->m_60)) + this->m_40;
}

#pragma pop
s32 TBoss8Dragon::is_near_target() {
    Boss_802FC910 *o = (Boss_802FC910 *)this;
    struct { f32 b[2]; V_802FC910 c; } s;
    V_802FC910 a;
    calc_orbit_xz(s.b, (f32 *)&s.c);
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&a, &o->pos);
    subtract_vector(&a, s.b);
    return ((f32 (*)(void *))normalize_vector_xz__FP3Vec)(&a) <= 35.0f;
}

void TBoss8Dragon::init_default(void *boss8_dragon) {
    ((TBoss8Dragon *)boss8_dragon)->set_damage_phase_value(0);
}

void TBoss8Dragon::set_damage_phase_value(s32 arg1) {
    if (arg1 == 0) {
        this->m_674 = 0;
        return;
    }
    this->m_674 = 0x32;
}

s32 is_health_low__12TBoss8DragonFPv(TBoss8Dragon *boss8_dragon) {
    return *(s32 *)&boss8_dragon->m_674 < 0x32;
}

u8 TBoss8Dragon__sub_802FC88C(void *arg0) {
    return (u8) (*(s32 *)((s8 *)arg0 + 0x674) >= 0x32);
}

void TBoss8Dragon__sub_802FC850(TBoss8Dragon *dragon) {
    s16 step = dragon->m_2b8 / 10;
    s16 value = dragon->m_2b8 - step;
    step += step;
    while (dragon->m_32c <= value) {
        value -= step;
    }
    dragon->m_678 = value;
}

s32 TBoss8Dragon__sub_802FC674(Obj_802FC674 *self, f32 *out) {
    Obj_802FC674 *list[12];
    Obj_802FC674 *p;
    s32 bestHp;
    s32 n;
    s32 i;
    s32 best;
    f32 *apos;
    Obj_802FC674 *a;
    Obj_802FC674 *b;
    s32 found;
    s32 i2;
    s32 j;
    s32 k;
    f32 lim;
    lim = lbl_805DEED8;
    n = 0;
    for (i = 0; i < 12; i++) {
        p = (Obj_802FC674 *)get_player_by_client_id(i);
        if (is_valid_target__9TObjEneDDFv() != 0 &&
            horizontal_distance_squared(p->pos, self->pos) >= lim) {
            list[n] = p;
            n++;
        }
    }
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        VecCopy__FP3VecPC3Vec(out, list[0]->pos);
    } else {
        lim = 100.0f;
        best = 0;
        found = 0;
        for (i2 = 0; i2 < n; i2++) {
            a = list[i2];
            apos = a->pos;
            for (j = i2 + 1; j < n; j++) {
                b = list[j];
                if (newton_sqrtf(horizontal_distance_squared(b->pos, apos)) < lim) {
                    s32 sum;
                    found = 1;
                    sum = a->f32C + b->f32C;
                    if (sum > best) {
                        best = sum;
                        out[0] = 0.5f * (apos[0] + b->pos[0]);
                        out[1] = 0.5f * (apos[1] + b->pos[1]);
                        out[2] = 0.5f * (apos[2] + b->pos[2]);
                    }
                }
            }
        }
        if (found == 0) {
            bestHp = 0;
            for (k = 0; k < n; k++) {
                p = list[k];
                if (bestHp < p->f32C) {
                    bestHp = p->f32C;
                    VecCopy__FP3VecPC3Vec(out, p->pos);
                }
            }
        }
    }
    return 1;
}

s32 TBoss8Dragon__sub_802FC580(Obj_802FC580 *obj, f32 *out) {
    s32 ang;
    s32 i;
    s32 n;
    f32 r;
    i = (s32)floor_to_float(12.0f * random_ratio__9TObjCharaFv());
    n = obj->count;
    if (n < 12) {
        obj->count = n + 1;
        while (0.0f != obj->vals[i]) {
            i++;
            if (i >= 12) {
                i = 0;
            }
        }
        r = rand_range__9TObjEneDDFff(obj, 100.0f, 220.0f);
        obj->vals[i] = r;
    } else {
        r = obj->vals[i];
    }
    ang = i * 0x1555;
    out[0] = r * sin_table_lookup(ang);
    out[1] = 0.0f;
    out[2] = r * cos_table_lookup(ang);
    return 1;
}

void TBoss8Dragon__sub_802FC500(u8 *boss8_dragon) {
    extern u8 TBoss8Dragon__data_804744A8[];
    if (is_health_low__12TBoss8DragonFPv((TBoss8Dragon *)boss8_dragon) != 0) {
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(boss8_dragon + 0x394, boss8_dragon + 0x38);
        *(f32 *)((s8 *)boss8_dragon + 0x398) = 0.0f;
        normalize_vector_xz__FP3Vec(boss8_dragon + 0x394);
        ((TBoss8Dragon *)boss8_dragon)->m_394 = (f32) (((TBoss8Dragon *)boss8_dragon)->m_394 * lbl_805DEED4);
        ((TBoss8Dragon *)boss8_dragon)->m_39c = (f32) (((TBoss8Dragon *)boss8_dragon)->m_39c * lbl_805DEED4);
        return;
    }
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(boss8_dragon + 0x394, &(*(RecoveredGlobal_802FC500_TBoss8Dragon__data_804744A8 *)&TBoss8Dragon__data_804744A8).value);
}

s32 select_target_in_front__12TBoss8DragonFPv(u8 *ene_dd_st) {
    Vec_802FC380 d;
    Vec_802FC380 ref;
    u16 ids[4];
    f32 lim;
    s32 n;
    s32 count;
    u8 *player;
    s32 i;

    n = 0;
    count = TLobby::get_game_mode();
    if (count > 4) {
        count = 4;
    }
    lim = cos_table_lookup(0x3000);
    ref.x = sin_table_lookup(*(s32 *)(ene_dd_st + 0x60));
    ref.y = 0.0f;
    ref.z = cos_table_lookup(*(s32 *)(ene_dd_st + 0x60));
    for (i = 0; i < count; i++) {
        player = (u8 *)get_player_data__10TObjPlayerFi(i);
        if (is_alive__8TObjBaseFv() != 0) {
            ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&d, player + 0x38);
            subtract_vector(&d, ene_dd_st + 0x38);
            normalize_vector_xz__FP3Vec(&d);
            if (vec3_dot(&d, &ref) > lim) {
                ids[n++] = get_entity_id(player);
            }
        }
    }
    if (n <= 0) {
        enemy_clear_target__12TObjEneDD_STFUs(ene_dd_st);
        return 0;
    }
    if (n == 1) {
        enemy_set_target_id(ene_dd_st, ids[0]);
        return 1;
    }
    enemy_set_target_id(ene_dd_st, ids[(s32)floor_to_float((f32)n * ((f32 (*)(void *))random_ratio__9TObjCharaFv)(ene_dd_st))]);
    return 1;
}

void spawn_effect__12TBoss8DragonFii(s32 arg0, s32 arg1) {
    play_sound_effect(arg1, arg0 + 0x634, 0, 0);
}

void spawn_trap__12TBoss8DragonFii(s32 arg0, s32 arg1) {
    play_persistent_sound(arg1, arg0, arg0 + 0x634, 0, 0);
}

void TBoss8Dragon::try_spawn_trap() {
    if ((this->m_3c0 & 0x40) && (is_closest_part__12TBoss8DragonFv() != 0)) {
        spawn_trap__12TBoss8DragonFii((s32)this, 0x4003D013);
    }
}

void TBoss8Dragon::play_sound_if_in_band() {
    u8 *arg0 = (u8 *)this;
    if ((((TObjMotion *)arg0)->is_passing_frame(4.0f) != 0) || (((TObjMotion *)arg0)->is_passing_frame(lbl_805DEED0) != 0)) {
        ((s32 (*)(void *, int))spawn_effect__12TBoss8DragonFii)((void *)((s32) arg0), 0x4003A801);
    }
}

void spawn_effect_if_in_band__12TBoss8DragonFi(s32 arg0) {
    if (((TObjMotion *)arg0)->is_passing_frame(5.0f) != 0) {
        ((s32 (*)(void *, int))spawn_effect__12TBoss8DragonFii)((void *)arg0, 0x4003A804);
    }
}

void TBoss8Dragon::reset_timer() { this->m_3e4 = 0; }

void TBoss8Dragon::set_state() { this->m_3e4 = 1; }

void TBoss8Dragon::set_action_state() { this->m_3e4 = 2; }

void TBoss8Dragon::set_active_flag() { *(int *)&this->m_3c0 = (*(int *)&this->m_3c0 | 0x1); this->m_3c = 0.0f; }

void TBoss8Dragon::activate_attack() { *(int *)&this->m_3c0 = (*(int *)&this->m_3c0 | 0x1); this->m_3c = 180.0f; }

void TBoss8Dragon::reset_action() { *(int *)&this->m_3c0 = (*(int *)&this->m_3c0 & 0xfffffffe); this->m_3c = -400.0f; }

void TBoss8Dragon::check_hit_result(s32 arg1, s32 arg2) {
    if (angle_diff_s16(arg1, arg2) >= 0) {
        this->m_654 = 1;
        return;
    }
    this->m_654 = -1;
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon__sub_802FC060(void *arg0, s32 arg1) {
    extern const f32 lbl_805DEECC;
    f32 height;
    f32 turn;
    f32 half;
    f32 frames = 35.0f;
    f32 k = 25.0f;

    *(s32 *)((s8 *)arg0 + 0x650) = (s16) *(s32 *)((s8 *)arg0 + 0x650);
    height = (f32) *(s32 *)((s8 *)arg0 + 0x650);
    turn = (f32) angle_diff_s16(*(s32 *)((s8 *)arg0 + 0x60), arg1);
    half = 0.5f * height;
    *(f32 *)((s8 *)arg0 + 0x660) = -(2.0f * (turn - half * frames)) / lbl_805DEECC;
    *(f32 *)((s8 *)arg0 + 0x65C) = -(*(f32 *)((s8 *)arg0 + 0x660) * k + height) / frames;
    *(f32 *)((s8 *)arg0 + 0x670) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x664) = height;
    *(f32 *)((s8 *)arg0 + 0x668) = -(*(f32 *)((s8 *)arg0 + 0x660) * k);
    half = 0.5f * *(f32 *)((s8 *)arg0 + 0x65C);
    *(f32 *)((s8 *)arg0 + 0x66C) = frames * (half * frames + height);
    *(s32 *)((s8 *)arg0 + 0x658) = *(s32 *)((s8 *)arg0 + 0x60);
}

s32 TBoss8Dragon__sub_802FBFA4(u8 *arg0) {
    f32 t;
    *(f32 *)((s8 *)arg0 + 0x670) += 1.0f;
    t = *(f32 *)((s8 *)arg0 + 0x670);
    if (t <= 35.0f) {
        *(s32 *)((s8 *)arg0 + 0x60) = *(s32 *)((s8 *)arg0 + 0x658) + (s32) (t * ((0.5f * *(f32 *)((s8 *)arg0 + 0x65C) * t) + *(f32 *)((s8 *)arg0 + 0x664)));
        return 0;
    }
    if (t <= 60.0f) {
        t = t - 35.0f;
        *(s32 *)((s8 *)arg0 + 0x60) = *(s32 *)((s8 *)arg0 + 0x658) + (s32) ((t * ((0.5f * *(f32 *)((s8 *)arg0 + 0x660) * t) + *(f32 *)((s8 *)arg0 + 0x668))) + *(f32 *)((s8 *)arg0 + 0x66C));
        return 0;
    }
    return 1;
}

#pragma pop
void TBoss8Dragon::reload_boss_stats() {
    reload_stats_keep_hp_tp__9TObjEneDDFv(this, TLobby::register_boss(0x12), ((s32 *)&TBoss8Dragon__data_80541DC8)[TBoss8Dragon__data_804E4C28[0]], TLobby::register_object(0x12));
}

void TBoss8Dragon::reset_tail_hp() {
    s32 arg0 = (s32)this;
    reset_hp__9TObjEneDDFPUcPUcPUc((void *)arg0, 0, (int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_802FBF0C_TBoss8Dragon__data_80541DC8 *)&TBoss8Dragon__data_80541DC8).value) + 4)), 0);
}

void TBoss8Dragon__sub_802FBEA4(TBoss8Dragon *dragon) {
    reload_stats_keep_hp_tp__9TObjEneDDFv(dragon, TLobby::register_boss(0x12), TBoss8Dragon__data_80541DC8[TBoss8Dragon__data_804E4C28[2]], TLobby::register_object(0x12));
}

void TBoss8Dragon__sub_802FBE3C(TBoss8Dragon *dragon) {
    reload_stats_keep_hp_tp__9TObjEneDDFv(dragon, TLobby::register_boss(0x12), TBoss8Dragon__data_80541DC8[TBoss8Dragon__data_804E4C28[3]], TLobby::register_object(0x12));
}

void handle_6xA8_gol_dragon_boss_actions(void *boss8_dragon) {
    void *x;
    ((TBoss8Dragon *)boss8_dragon)->bswap_packet();
    x = get_enemy_entity(*(u16 *)((s8 *)boss8_dragon + 0x2));
    if (x != NULL) {
        ((void (*)(void *, void *))apply_6xA8_action__12TBoss8DragonFPvPv)(x, boss8_dragon);
    }
}

extern "C" {
void apply_6xA8_action__12TBoss8DragonFPvPv(u8 *boss8_dragon, u8 *arg1) {
  s8 *new_var2;
  s16 temp_r4;
  u16 new_var;
  new_var = (u16) (*((s32 *) (((s8 *) arg1) + 8)));
  enemy_set_target_id(boss8_dragon, new_var);
  ((TBoss8Dragon *)boss8_dragon)->m_674 = (s32) (*((s16 *) (((s8 *) arg1) + 6)));
  new_var2 = (s8 *) boss8_dragon;
  *((f32 *)(new_var2 + 0x690)) = (f32) (*((f32 *) (((s8 *) arg1) + 0xC)));
  *((f32 *)(new_var2 + 0x694)) = (f32) (*((f32 *) (((s8 *) arg1) + 0x10)));
  (((VObj_18_be4a70 *)(boss8_dragon))->m85((*((s16 *) (((s8 *) arg1) + 4))), 7));
  set_mode_params__12TBoss8DragonFSc(boss8_dragon, (s8) (*((u8 *) (((s8 *) arg1) + 0x14))));
  temp_r4 = *((s16 *) (((s8 *) arg1) + 4));
  if (((s16) (((TBoss8Dragon *)boss8_dragon)->m_326)) != temp_r4)
  {
    ((TObjEneDD *)boss8_dragon)->transition_enemy_state(temp_r4);
  }
}

void TBoss8Dragon::send_6xA8_action() {
    Pkt_802FBCBC p;
    f32 t;
    build_6xA8_gol_dragon_boss_actions(&p);
    p.a = *(u16 *)&this->unk_1C;
    p.b = this->m_326;
    p.c = this->m_674;
    p.d = this->m_38c;
    p.e = *(f32 *)&this->unk_688;
    p.f = this->m_68c;
    t = 0.000030517578f * (f32)rand();
    p.g = (s8)(3.0f * t);
    ((TBoss8Dragon *)(&p))->send_swapped_packet();
}

void send_action_packet__12TBoss8DragonFPvi(u8 *boss8_dragon, s32 arg1) {
    Pkt_802FBBFC p;
    f32 t;
    ((V_802FBBFC *)boss8_dragon)->m85(arg1, 6);
    build_6xA8_gol_dragon_boss_actions(&p);
    p.a = *(u16 *)((s8 *)boss8_dragon + 0x1C);
    p.b = arg1;
    p.c = ((TBoss8Dragon *)boss8_dragon)->m_674;
    p.d = ((TBoss8Dragon *)boss8_dragon)->m_38c;
    p.e = *(f32 *)((s8 *)boss8_dragon + 0x688);
    p.f = ((TBoss8Dragon *)boss8_dragon)->m_68c;
    t = 0.000030517578f * (f32)rand();
    p.g = (s8)(3.0f * t);
    ((TBoss8Dragon *)(&p))->send_swapped_packet();
}

void sync_target_pos__12TBoss8DragonFPv(void* p) { *(f32*)((char*)p + 0x394) = *(f32*)((char*)p + 0x690); *(f32*)((char*)p + 0x39c) = *(f32*)((char*)p + 0x694); }

void TBoss8Dragon__sub_802FBBC8(u8 *arg0, s32 *arg1) {
    *arg1 = (s32) *(f32 *)((s8 *)arg0 + 0x690);
}

s32 restore_target_pos__12TBoss8DragonFPv(void* p) { *(f32*)((char*)p + 0x38) = *(f32*)((char*)p + 0x690); *(f32*)((char*)p + 0x40) = *(f32*)((char*)p + 0x694); }

void TBoss8Dragon::save_position() { *(f32 *)&this->unk_688 = this->m_394; this->m_68c = this->m_39c; }

void TBoss8Dragon::set_speed(s32 arg1) {
    *(f32 *)&this->unk_688 = (f32) arg1;
    this->m_68c = 0.0f;
}

s32 copy_pos_to_field688__12TBoss8DragonFPv(void* p) { *(f32*)((char*)p + 0x688) = *(f32*)((char*)p + 0x38); *(f32*)((char*)p + 0x68c) = *(f32*)((char*)p + 0x40); }

void TBoss8Dragon::pick_next_action() {
    u8 *arg0 = (u8 *)this;
  s32 var_r7;
  s32 *var_r8;
  s32 temp_r4;
  s32 temp_r5;
  s32 var_r9;
  if ((this->m_3c0) & 0x40)
  {
    var_r7 = this->m_674;
    var_r8 = (s32 *)&boss8_dragon_action_pick_table_b.value;
  }
  else
  {
    temp_r5 = this->m_674;
    if (temp_r5 < 0x32)
    {
      var_r7 = temp_r5;
      var_r8 = (s32 *)&dragon_next_action_table.value;
    }
    else
    {
      var_r7 = temp_r5 - 0x32;
      var_r8 = (s32 *)&boss8_dragon_action_pick_table.value;
    }
  }
  do
  {
    temp_r4 = *((s32 *) (((s8 *) var_r8) + (var_r7 * 4)));
    var_r9 = 0;
    var_r7 += 1;
    this->m_674 = (s32) ((this->m_674) + 1);
    switch (temp_r4)
    {
      case 33:
        this->m_674 = 0;
        var_r9 = 1;
        var_r7 = 0;
        break;
      case 34:
        this->m_674 = 0x32;
        var_r9 = 1;
        var_r7 = 0;
        break;
    }
  }
  while (var_r9 != 0);
  ((s32 (*)(void *, s32))send_action_packet__12TBoss8DragonFPvi)((void *) arg0, (int) temp_r4);
}

void TBoss8Dragon__sub_802FBA1C(TBoss8Dragon *boss8_dragon) {
    if ((s32) boss8_dragon->m_74c != 0) {
        boss8_dragon->pick_next_action();
        return;
    }
    if (boss8_dragon->check_damage_reaction() == 0) {
        boss8_dragon->m_674 = (s32) *(s32 *)((s8 *)&boss8_dragon_state_transition_table.value + (boss8_dragon->m_674 * 4));
        boss8_dragon->pick_next_action();
    }
}

s32 TBoss8Dragon::check_damage_reaction() {
    if (*(s32 *)&this->m_3c0 & 0x40) {
        return 0;
    }
    if ((s16) this->m_32c <= (s16) *(s16 *)&this->m_67a) {
        this->m_32c = *(s16 *)&this->m_67a;
        set_damage_phase_value(1);
        if ((s32) *(s32 *)&this->m_3e4 == 0) {
            ((s32 (*)(void *, s32))send_action_packet__12TBoss8DragonFPvi)(this, 0xD);
            return 1;
        }
        ((s32 (*)(void *, s32))send_action_packet__12TBoss8DragonFPvi)(this, 0xB);
        return 1;
    }
    return 0;
}

int TBoss8Dragon__sub_802FB984(void) { return 0; }

}
#pragma push
#pragma fp_contract on
extern "C" {
f32 TBoss8Dragon::calc_step_value() {
    TBoss8Dragon *o = this;
    return 4.0f * (f32)*(s32 *)&o->m_6d0 + 4.0f;
}

}
#pragma pop
extern "C" {
void TBoss8Dragon::spawn_effect() {
    s32 arg0 = (s32)this;
    start_pad_rumble_at((Vec *)(arg0 + 0x38), 0xE0, arg0);
}

void TBoss8Dragon__sub_802FB828(u8 *arg0, s32 arg1) {
    Eff_802FB828 eff = boss8_dragon_breath_eff_params;
    u8 *a;
    u8 *b;
    ((s32 (*)(s32))fill_value_array)(*(s32 *)(arg0 + 0x680));
    if (arg1 == 0) {
        a = arg0 + 0x470;
        b = arg0 + 0x47C;
    } else {
        a = arg0 + 0x458;
        b = arg0 + 0x464;
    }
    ((s32 (*)(void *, s32, s32, s32))reset_hp__9TObjEneDDFPUcPUcPUc)(arg0, 0, TBoss8Dragon__data_80541DC8[0], 0);
    ((s32 (*)(void *, void *, void *, s32))emit_effect__12TBoss8DragonFPv)(arg0, a, &eff, *(s32 *)(arg0 + 0x680));
    ((s32 (*)(void *, void *, void *, s32))emit_effect__12TBoss8DragonFPv)(arg0, b, &eff, *(s32 *)(arg0 + 0x680));
    ((s32 (*)(void *, s32, s32, s32))reset_hp__9TObjEneDDFPUcPUcPUc)(arg0, 0, TBoss8Dragon__data_80541DC8[0], 0);
    ((s32 (*)(void *, void *, s32))spawn_particle_effect_with_flags)(b, *(void **)(*(u8 **)(arg0 + 0x760) + 0x10), 0x40);
}

int TBoss8Dragon::check_condition_default(void* p) { return ((int (*)(void*, int))TBoss8Dragon__sub_802FB828)(p, 0); }

int TBoss8Dragon::set_state_1(void* p) { return ((int (*)(void*, int))TBoss8Dragon__sub_802FB828)(p, 1); }

void TBoss8Dragon__sub_802FB778(s32 arg0) {
    typedef char sp8_offset[(offsetof(Stack_802FB778, sp8) == 0x0) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_802FB778, sp10) == 0x8) ? 1 : -1];
    Stack_802FB778 stack;
    TBoss1Dragon__sub_80027A80((u8 *)&stack.sp8, (u8 *)&lbl_804744B4.value);
    stack.sp10 = *(f32 *)((s8 *)((*(RecoveredGlobal_802FB778_TBoss8Dragon__data_80541DDC *)&TBoss8Dragon__data_80541DDC).value) + 0xC);
    TBoss8Dragon__sub_802FBEA4((TBoss8Dragon *)arg0);
    ((s32 (*)(void *, void *))get_state_flags__12TBoss8DragonFPv)((void *)arg0, &stack.sp8);
    ((TBoss8Dragon *)arg0)->reload_boss_stats();
}

void TBoss8Dragon__sub_802FB70C(s32 arg0) {
    reset_hp__9TObjEneDDFPUcPUcPUc((void *)arg0, 0, (int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_802FB70C_TBoss8Dragon__data_80541DC8 *)&TBoss8Dragon__data_80541DC8).value) + 0x10)), 0);
    ((s32 (*)(void *, void *))get_state_flags__12TBoss8DragonFPv)((void *)arg0, (void *) (&(*(RecoveredGlobal_802FB70C_TBoss8Dragon__data_804744C8 *)&TBoss8Dragon__body_effect_parameters).value));
    reset_hp__9TObjEneDDFPUcPUcPUc((void *)arg0, 0, (int) (*(s32 *)((s8 *)(&(*(RecoveredGlobal_802FB70C_TBoss8Dragon__data_80541DC8 *)&TBoss8Dragon__data_80541DC8).value) + 0)), 0);
}

}
#pragma push
#pragma fp_contract on
extern "C" {
void draw_beam_segments__12TBoss8DragonFPvfff(u8 *ene_dd, f32 a, f32 b, f32 c) {
    RecoveredGlobal_802FB70C_TBoss8Dragon__data_804744C8 fx = *(RecoveredGlobal_802FB70C_TBoss8Dragon__data_804744C8 *)TBoss8Dragon__body_effect_parameters;
    Vec_802FB4DC v2;
    Vec_802FB4DC v1;
    f32 sn;
    f32 cs;
    f32 d;

    *(f32 *)((s8 *)&fx + 8) = a - 2.0f;
    fill_value_array(*(s32 *)((s8 *)ene_dd + 0x680));
    sn = sin_table_lookup(((TObjEneDD *)ene_dd)->rotation_y);
    cs = cos_table_lookup(((TObjEneDD *)ene_dd)->rotation_y);
    VecCopy__FP3VecPC3Vec(&v1, ene_dd + 0x38);
    v1.x += lbl_805DEEC8 * cs;
    v1.y = 0.0f;
    v1.z -= lbl_805DEEC8 * sn;
    d = 0.5f * (b + c);
    VecCopy__FP3VecPC3Vec(&v2, &v1);
    v2.x = sn * d + v2.x;
    v2.z = cs * d + v2.z;
    ((void (*)(void *, s32, int))spawn_particle_effect_with_flags)(&v2, *(s32 *)((s8 *)(*(u8 **)((s8 *)ene_dd + 0x760)) + 0x10), 0x40);
    reset_hp__9TObjEneDDFPUcPUcPUc(ene_dd, 0, TBoss8Dragon__data_80541DC8[4], 0);
    c = c - a;
    d = b - a;
    a *= 2.0f;
    b = 0.5f * (0.5f * a);
    while (d > c) {
        VecCopy__FP3VecPC3Vec(&v2, &v1);
        v2.x = sn * d + v2.x;
        v2.z = cs * d + v2.z;
        ((void (*)(void *, void *, void *, s32))emit_effect__12TBoss8DragonFPv)(ene_dd, &v2, &fx, *(s32 *)((s8 *)ene_dd + 0x680));
        d -= a;
        push_matrix();
        post_translate_matrix(&v2);
        scale_matrix(0, b, 2.0f, b);
        draw_chunk_object((void *)lbl_805D28BC);
        pop_matrix();
    }
    reset_hp__9TObjEneDDFPUcPUcPUc(ene_dd, 0, TBoss8Dragon__data_80541DC8[0], 0);
}

}
#pragma pop
extern "C" {
void update_pos_from_data__12TBoss8DragonFv(void) {
    ((s32 (*)(f32, f32, f32))draw_beam_segments__12TBoss8DragonFPvfff)(TBoss8Dragon__data_805DEEA4, lbl_805DEEC0, lbl_805DEEC4);
}

void TBoss8Dragon__sub_802FB484(void) {
    ((s32 (*)(f32, f32, f32))draw_beam_segments__12TBoss8DragonFPvfff)(TBoss8Dragon__data_805DEEA4, lbl_805DEEBC, 60.0f);
}

void TBoss8Dragon::init_state(s32 arg0) {
    TBoss8Dragon__sub_802FBE3C((TBoss8Dragon *)arg0);
    ((s32 (*)(s32, s32 *))get_state_flags__12TBoss8DragonFPv)(arg0, boss8_dragon_init_state_params);
    ((TBoss8Dragon *)arg0)->reload_boss_stats();
}

void TBoss8Dragon::emit_body_effects() {
    Vec_802FB304 *pts[10];
    Eff_802FB304 e;
    Vec_802FB304 v;
    s32 i;
    ((void (*)(void *, s32, s32, s32))reset_hp__9TObjEneDDFPUcPUcPUc)(this, 0, TBoss8Dragon__data_80541DC8[4], 0);
    fill_value_array(this->m_680);
    TBoss1Dragon__sub_80027A80((u8 *)&e, (u8 *)TBoss8Dragon__body_effect_parameters);
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v, ((u8 *)this) + 0x4C4);
    e.f = 15.0f;
    ((void (*)(void *, void *, void *, s32))emit_effect__12TBoss8DragonFPv)(this, &v, &e, this->m_680);
    e.f = 12.0f;
    pts[0] = (Vec_802FB304 *)((u8 *)this + 0x488);
    pts[1] = (Vec_802FB304 *)((u8 *)this + 0x4A0);
    for (i = 0; i < 2; i++) {
        ((void (*)(void *, void *, void *, s32))emit_effect__12TBoss8DragonFPv)(this, pts[i], &e, this->m_680);
    }
    e.f = 11.0f;
    pts[0] = (Vec_802FB304 *)((u8 *)this + 0x4DC);
    pts[1] = (Vec_802FB304 *)((u8 *)this + 0x4E8);
    pts[2] = (Vec_802FB304 *)((u8 *)this + 0x4F4);
    pts[3] = (Vec_802FB304 *)((u8 *)this + 0x500);
    for (i = 0; i < 4; i++) {
        ((void (*)(void *, void *, void *, s32))emit_effect__12TBoss8DragonFPv)(this, pts[i], &e, this->m_680);
    }
    ((void (*)(void *, s32, s32, s32))reset_hp__9TObjEneDDFPUcPUcPUc)(this, 0, TBoss8Dragon__data_80541DC8[0], 0);
}

void TBoss8Dragon__sub_802FB300(void) {  }

void TBoss8Dragon::setup_breath_instance(void *o, int x, u32 a, int w) {
    S_802FB290 s = TBoss8Dragon__breath_params;
    s.b = (*(G_802FB290 *)&TBoss8Dragon__data_80541DDC).value->f[0];
    s.a = a;
    ((TBoss8Dragon *)o)->setup_instance(x, &s, w);
}

void TBoss8Dragon__sub_802FB220(void *o, int x, u32 a) {
    S_802FB220 s = lbl_80474ACC;
    s.b = (*(G_802FB220 *)&TBoss8Dragon__data_80541DDC).value->f[1];
    s.a = a;
    ((TBoss8Dragon *)o)->setup_instance(x, &s, 0);
}

void TBoss8Dragon__sub_802FB1B0(TBoss8Dragon *dragon, int x, f32 c) {
    S_802FB220 s = lbl_80474AE0;
    s.c = c;
    s.b = (*(G_802FB220 *)&TBoss8Dragon__data_80541DDC).value->f[2];
    dragon->setup_instance(x, &s, dragon->m_680);
}

int emit_effect__12TBoss8DragonFPv(void* p) { return emit_enemy_effect__9TObjEneDDFllPUcl(p); }

int get_state_flags__12TBoss8DragonFPv(void* p) { return emit_effect_at_position__9TObjEneDDFPv(p); }

int TBoss8Dragon::setup_instance(int _w1, void * _w2, int _w3) { return setup_instance__9TObjEneDDFllPUcl(this); }

void TBoss8Dragon::spawn_ground_effect() {
    Stack_802FB0DC stack;
    f32 temp_f1;
    u8 *temp_r3;
    VecCopy__FP3VecPC3Vec(&stack.sp8, (u8 *)&this->m_38);
    temp_r3 = (u8 *)csnVecterUnder((s32)&stack.sp8, 0x16EF);
    if (temp_r3 != NULL) {
        temp_f1 = *(f32 *)((s8 *)(*(void **)((s8 *)temp_r3 + 4)) + 4);
        if (!(temp_f1 > 30.0f)) {
            stack.spC = temp_f1;
            spawn_particle_effect_with_flags(&stack.sp8, (void *) (*(s32 *)((s8 *)this->m_760 + 4)), 0x40);
        }
    }
}

void TBoss8Dragon__sub_802FB09C(s32 arg0) {
    if (((TObjMotion *)arg0)->is_passing_frame(14.0f) != 0) {
        ((TBoss8Dragon *)arg0)->spawn_ground_effect();
    }
}

u16 TBoss8Dragon::find_player_on_floor(void *arg0) {
    u8 *p;
    u16 idx;
    u16 i;
    p = ((u8 * (*)(s32))get_player_by_client_id)(TLobby__designated_client_id);
    if (p != NULL) {
        if (((TObjPlayer *)p)->get_floor() == get_current_floor()) {
            return TLobby__designated_client_id;
        }
    }
    for (i = 0; i < 4; i++) {
        idx = (TLobby__designated_client_id + i + 1) % 4;
        p = ((u8 * (*)(s32))get_player_by_client_id)(idx);
        if (p != NULL) {
            if (((TObjPlayer *)p)->get_floor() == get_current_floor()) {
                break;
            }
        }
    }
    return idx;
}

void TBoss8Dragon::select_freeze_target() {
    u16 var_r31;
    if (TBoss8Dragon__data_805D69B8 != 0) {
        this->m_74c = 1;
    } else {
        this->m_74c = 0;
        this->m_750 = 0xFFFFU;
        return;
    }
    this->m_754 = 0x96;
    *(u8 * *)&this->m_6d8 = controller_input_state + 0x20;
    if (is_main_phase_15__9TObjEneDDFv(controller_input_state) != 0) {
        if (TBoss8Dragon__data_805D69BC == 0xFFFFU) {
            var_r31 = TBoss8Dragon::find_player_on_floor(this);
        } else {
            var_r31 = TBoss8Dragon__data_805D69BC;
        }
    } else {
        var_r31 = (u16)local_client_id;
    }
    if (((u8 * (*)(s32))get_player_by_client_id)(var_r31) != NULL) {
        ((s32 (*)(void))start_freeze__10TObjPlayerFv)();
    }
    this->m_750 = var_r31;
}

}
#pragma push
#pragma fp_contract on
extern "C" {
void TBoss8Dragon::freeze_player_at_self() {
    u8 *player;
    player = ((u8 * (*)(s32))get_player_by_client_id)(this->m_750);
    if (player != NULL) {
        if (((TObjPlayer *)player)->get_floor() == get_current_floor()) {
            start_freeze__10TObjPlayerFv((int)player);
            set_frames__15ProtectionTimerFl(player + 0x644, 0x14);
            ((TObjPlayer *)player)->actorFlags = (s32) (((TObjPlayer *)player)->actorFlags & 0xFFEFFFDF);
            VecCopy__FP3VecPC3Vec(player + 0x38, (u8 *)&this->m_38);
            *(f32 *)((s8 *)player + 0x3C) = (f32) (*(f32 *)((s8 *)player + 0x3C) - lbl_805DEEB8);
            ((TObjPlayer *)player)->rotation_y = (s32) this->m_60;
            return;
        }
    }
    ((s32 (*)(void))TBoss8Dragon__sub_802FD9D0)();
}

}
#pragma pop
extern "C" {
void release_grabbed_player__12TBoss8DragonFPv(TBoss8Dragon *boss8_dragon) {
    s32 var_r31;
    u16 temp_r4;
    u8 *player;
    player = (u8 *)(((u8 * (*)(s32))get_player_by_client_id)((s32) boss8_dragon->m_750));
    if (player != NULL) {
        ((TObjPlayer *)player)->end_camera_pan();
        ((TObjPlayer *)player)->actorFlags = (s32) (((TObjPlayer *)player)->actorFlags & 0xFDFFFFFF);
        ((TObjPlayer *)(player + 0x644))->reset_lobby_model();
        *(f32 *)((s8 *)player + 0x3C) = 0.0f;
        temp_r4 = boss8_dragon->m_750;
        if (((s32) temp_r4 == (s32) local_client_id) && ((s16) boss8_dragon->m_326 == 0x15)) {
            send_6x2F_change_player_hp((0xFFFFU), (temp_r4), 0);
        }
    }
    boss8_dragon->m_74c = 0;
    if ((s16) boss8_dragon->m_326 != 0x15) {
        var_r31 = 0;
        if (is_health_low__12TBoss8DragonFPv(boss8_dragon) != 0) {
            boss8_dragon->m_674 = 0;
            switch (boss8_dragon->m_326) {
            case 24:
            case 25:
                var_r31 = 1;
                boss8_dragon->m_674 = 0;
                break;
            case 3:
                boss8_dragon->m_674 = 2;
                break;
            case 4:
                boss8_dragon->m_674 = 3;
                break;
            case 5:
                boss8_dragon->m_674 = 4;
                break;
            case 26:
            case 27:
                var_r31 = 1;
                boss8_dragon->m_674 = 6;
                break;
            case 7:
                boss8_dragon->m_674 = 6;
                break;
            case 8:
                boss8_dragon->m_674 = 7;
                break;
            case 9:
                boss8_dragon->m_674 = 0;
                break;
            }
        } else {
            boss8_dragon->m_674 = 0;
            switch (boss8_dragon->m_326) {
            case 24:
            case 25:
                var_r31 = 1;
                boss8_dragon->m_674 = 0;
                break;
            case 3:
            case 4:
                boss8_dragon->m_674 = 0;
                break;
            case 5:
                boss8_dragon->m_674 = 1;
                break;
            case 26:
            case 27:
                var_r31 = 1;
                boss8_dragon->m_674 = 0xA;
                break;
            case 7:
                boss8_dragon->m_674 = 0xA;
                break;
            case 8:
            case 19:
                boss8_dragon->m_674 = 0xB;
                break;
            case 15:
                boss8_dragon->m_674 = 2;
                break;
            case 37:
            case 38:
                var_r31 = 1;
                boss8_dragon->m_674 = 9;
                break;
            case 9:
                boss8_dragon->m_674 = 0;
                break;
            }
            boss8_dragon->m_674 = (boss8_dragon->m_674 + 0x32);
        }
        if (var_r31 != 0) {
            boss8_dragon->pick_next_action();
        }
    }
}

}
#pragma push
#pragma fp_contract on
extern "C" {
f32 TBoss8Dragon::clamp_step_in_radius(f32 a, f32 b, f32 s) {
    Obj_802FAC08 *o = (Obj_802FAC08 *)this;
    V3_802FAC08 v;
    v.x = a * s + o->x;
    v.y = 0.0f;
    v.z = b * s + o->z;
    if (vec3_dot(&v, &v) > lbl_805DEEB4) {
        s = 0.0f;
    }
    return s;
}

}
#pragma pop
extern "C" {
u8 TBoss8Dragon__sub_802FABB4(void *arg0) {
    u8 var_r31;

    var_r31 = 0;
    if (((s32) *(s32 *)((s8 *)arg0 + 0x754) >= 0x96) && (mask_flags__12TBoss8DragonFiii((s32)arg0, (s32)(*(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x6D8)) + 8)), 0x400) != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

u8 check_attack_ready__12TBoss8DragonFPv(void *arg0) {
    u8 var_r31;

    var_r31 = 0;
    if ((mask_flags__12TBoss8DragonFiii((s32)arg0, (s32)(*(s32 *)((s8 *)(*(void **)((s8 *)arg0 + 0x6D8)) + 8)), 0x400) != 0) && (((s32 (*)(void *))TBoss8Dragon__sub_802FC88C)(arg0) != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

void TBoss8Dragon::calc_velocity_from_angle() {
    *(f32 *)&this->m_38 = (f32) (lbl_805DEEB0 * sin_table_lookup(*(s32 *)&this->m_758));
    this->m_40 = (f32) (lbl_805DEEB0 * cos_table_lookup(this->m_758));
}

s32 mask_flags__12TBoss8DragonFiii(s32 arg1, s32 arg2, s32 arg3) {
    s32 var_r31;

    var_r31 = arg3;
    if ((get_player_by_client_id(local_client_id) == 0U) || (check_flag_100__10TObjPlayerFPv() != 0)) {
        arg2 &= 0xFFFCF9F9;
    }
    return arg2 & var_r31;
}

void TBoss8Dragon::sub_802FA4E4(s32 action, s32 event) {
    static void (TBoss8Dragon::*handlers[44])(s32) = {
        &TBoss8Dragon::sub_802FA478,
        &TBoss8Dragon::sub_802FA374,
        &TBoss8Dragon::sub_802FA16C,
        &TBoss8Dragon::state_breath_attack,
        &TBoss8Dragon::handle_tail_attack_state,
        &TBoss8Dragon::sub_802F9850,
        &TBoss8Dragon::state_turn_and_charge,
        &TBoss8Dragon::sub_802F8F88,
        &TBoss8Dragon::sub_802F8578,
        &TBoss8Dragon::sub_802F8270,
        &TBoss8Dragon::sub_802F8578,
        &TBoss8Dragon::sub_802F8578,
        &TBoss8Dragon::sub_802F8578,
        &TBoss8Dragon::sub_802F8150,
        &TBoss8Dragon::state_roar,
        &TBoss8Dragon::sub_802F7B70,
        &TBoss8Dragon::sub_802F7B4C,
        &TBoss8Dragon::action_17,
        &TBoss8Dragon::sub_802F75C8,
        &TBoss8Dragon::handle_leap_state,
        0,
        &TBoss8Dragon::sub_802F6838,
        &TBoss8Dragon::sub_802F6708,
        &TBoss8Dragon::sub_802F6618,
        &TBoss8Dragon::sub_802F645C,
        &TBoss8Dragon::sub_802F610C,
        &TBoss8Dragon::sub_802F5F64,
        &TBoss8Dragon::sub_802F5CC8,
        &TBoss8Dragon::sub_802F5BA0,
        &TBoss8Dragon::handle_walk_state,
        &TBoss8Dragon::sub_802F4DD4,
        &TBoss8Dragon::action,
        &TBoss8Dragon::update_wander_state,
        0,
        0,
        &TBoss8Dragon::sub_802F89F8,
        &TBoss8Dragon::handle_spiral_state,
        &TBoss8Dragon::sub_802F57E4,
        &TBoss8Dragon::sub_802F5644,
        &TBoss8Dragon::sub_802F5434,
        &TBoss8Dragon::sub_802F51DC,
        &TBoss8Dragon::sub_802F9A4C,
        &TBoss8Dragon::sub_802F87EC,
        &TBoss8Dragon::sub_802F4B90,
    };
    if (handlers[action]) {
        (this->*handlers[action])(event);
    }
}

f32 lbl_805D69C0 = 5.0f * lbl_805D9E80;

void *boss8_dragon_bezier_points[16] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x438c0000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x433e0000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x43340000, (void *)0x0, (void *)0x0,
};
void *boss8_dragon_bezier_points_3[12] = {
    (void *)0x0, (void *)0x43340000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x43fa0000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
};
void *TBoss8Dragon__dive_height_curve[12] = {
    (void *)0x0, (void *)0x43340000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x44610000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0xc3c80000, (void *)0x0, (void *)0x0,
};
void *__vt__12TBoss8Dragon[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__12TBoss8DragonFv, (void *)&run_task__12TBoss8DragonFv,
    (void *)&TBoss8Dragon__sub_802F4380, (void *)&render_shadows__12TBoss8DragonFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&vfunc_18__9TObjCharaFPUc, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&calc_direct_attack_damage__12TBoss8DragonFPvPvPviii,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&vfunc_28__12TBoss8DragonFv, (void *)&vfunc_29__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&vfunc_37__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&vfunc_44__12TBoss8DragonFv, (void *)&vfunc_45__12TBoss8DragonFv, (void *)&vfunc_46__12TBoss8DragonFv, (void *)&vfunc_47__12TBoss8DragonFv,
    (void *)&vfunc_48__12TBoss8DragonFl, (void *)&vfunc_49__12TBoss8DragonFv, (void *)&vfunc_50__12TBoss8DragonFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&vfunc_58__9TObjCharaFv, (void *)&vfunc_59__9TObjCharaFv,
    (void *)&vfunc_60__9TObjCharaFv, (void *)&vfunc_61__12TBoss8DragonFv, (void *)&vfunc_62__12TBoss8DragonFv, (void *)&vfunc_63__12TBoss8DragonFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&vfunc_67__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&vfunc_75__9TObjCharaFf,
    (void *)&vfunc_76__9TObjCharaFf, (void *)&vfunc_77__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&vfunc_79__9TObjEneDDFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&vfunc_83__12TObjEneDD_STFv,
    (void *)&vfunc_84__9TObjEneDDFv, (void *)&vfunc_85__9TObjEneDDFv, (void *)&vfunc_86__9TObjEneDDFv, (void *)&sub_802FA4E4__12TBoss8DragonFll,
    (void *)&update_colliders__12TBoss8DragonFPv, (void *)&vfunc_89__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&vfunc_91__9TObjEneDDFv,
    (void *)&vfunc_92__9TObjEneDDFv, (void *)&vfunc_93__9TObjEneDDFv, (void *)&vfunc_94__9TObjEneDDFv, (void *)&vfunc_95__9TObjEneDDFv,
    (void *)&vfunc_96__9TObjEneDDFv, (void *)&vfunc_97__9TObjEneDDFv, (void *)&vfunc_98__9TObjEneDDFv, (void *)&vfunc_99__9TObjEneDDFv,
    (void *)&vfunc_100__9TObjEneDDFv, (void *)&vfunc_101__9TObjEneDDFPUc, (void *)&vfunc_102__9TObjEneDDFv, (void *)&vfunc_103__9TObjEneDDFPUc,
    (void *)&vfunc_104__12TObjEneDD_STFf, (void *)&TBoss8Dragon__sub_802F4360, (void *)&draw_motion_model__12TBoss8DragonFv,
};
void TBoss8Dragon::sub_802FA478(s32 arg1) {
    switch (arg1) {
    case 4:
        this->select_freeze_target();
        return;
    case 2:
    case 11:
        ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0x18);
        return;
    case 9:
        if ((s32) this->m_74c != 0) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0x18);
            return;
        }
        this->pick_next_action();
    default:
        return;
    }
}

void TBoss8Dragon::sub_802FA374(s32 arg1) {
    switch (arg1) {
    case 4:
        this->m_b8 = 0;
        this->m_84c = 0;
        if (this->m_3c0 & 0x40) {
            this->try_spawn_trap();
        } else {
            ((s32 (*)(void *, s32))spawn_effect__12TBoss8DragonFii)(((u8 *)this), 0x4003AD00);
        }
        break;
    case 2:
    case 11:
        if (((s32 (*)(void *, s32, s32))mask_flags__12TBoss8DragonFiii)(((u8 *)this), *(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8), 4) != 0) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 3);
        } else if (((s32 (*)(void *, s32, s32))mask_flags__12TBoss8DragonFiii)(((u8 *)this), *(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8), 0x400) != 0) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 5);
        } else if (*(f32 *)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 0x24) > 0.1f) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0x19);
        }
        break;
    case 0:
        this->m_84c++;
        ((TObjMotion *)this)->advance_animation();
        break;
    }
}

void TBoss8Dragon::sub_802FA16C(s32 arg1) {
    extern u8 TBoss8Dragon__data_804744A8[];
    f32 temp_f1;
    s32 temp_r4_2;
    s32 var_r30;
    switch (arg1) {
    case 4:
        this->m_b8 = 1;
        ((TObjEneDD_ST *)this)->vfunc_96();
        this->reset_timer();
        this->set_active_flag();
        *(s32 *)&this->m_3c0 = (s32) (*(s32 *)&this->m_3c0 & ~0x36);
        *(s32 *)&this->m_84c = 0;
        temp_f1 = *(f32 *)((s8 *)TBoss8Dragon__data_80541DDC[0] + 0x10);
        *(f32 *)((s8 *)this + 0x864) = (f32) (5.0f + TObjBoss2Tunnel::calc_scaled_value((s32) (320.0f * temp_f1), temp_f1));
        return;
    case 2:
    case 11:
        ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(this, 0x18);
        return;
    case 9:
        temp_r4_2 = *(s32 *)&this->m_84c;
        var_r30 = 0;
        if ((temp_r4_2 >= 0x96) && ((u32) this->m_390 != 0U)) {
            if (*(f32 *)((s8 *)this + 0x3AC) < *(f32 *)((s8 *)this + 0x864)) {
                var_r30 = 1;
            } else if (this->is_near_target() != 0) {
                var_r30 = 1;
            } else if ((s32) *(s32 *)&this->m_84c >= 0x258) {
                var_r30 = 1;
            }
        } else if (temp_r4_2 >= 0x12C) {
            var_r30 = 1;
        }
        if (var_r30 != 0) {
            this->pick_next_action();
        }
        return;
    case 8:
        this->try_spawn_trap();
        ((s32 (*)(void *))update_linked_position__12TBoss8DragonFv)(this);
        *(s32 *)&this->m_84c = (s32) (*(s32 *)&this->m_84c + 1);
        if ((s32) (*(s32 *)&this->m_84c % 20) == 0x13) {
            if (enemy_validate_retained_target(this) != 0) {
                ((TObjEneDD_ST *)this)->enemy_copy_target_destination();
            } else {
                ((TObjEneDD *)this)->set_target_destination((const Vec *)TBoss8Dragon__data_804744A8);
            }
            this->save_position();
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        ((s32 (*)(void))sync_target_pos__12TBoss8DragonFPv)();
        return;
    case 6:
        this->m_3b0 = (s32) *(s32 *)((s8 *)this + 0x3B4);
        if (((s32 (*)(void *))update_linked_position__12TBoss8DragonFv)(this) != 0) {
            ((TObjEneDD_ST *)this)->enemy_copy_target_destination();
        } else {
            ((TObjEneDD *)this)->set_target_destination((const Vec *)TBoss8Dragon__data_804744A8);
        }
        this->save_position();
        return;
    case 0:
        ((s32 (*)(void))update_movement__12TBoss8DragonFPv)();
        break;
    }
}

}
#pragma push
#pragma fp_contract on
extern "C" {
void TBoss8Dragon::state_breath_attack(s32 arg1) {
    Rot_802F9D08 rot;
    void *mem;
    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 4;
        ((VObj_18_444bc5 *)(((u8 *)this)))->m94();
        this->reset_timer();
        this->set_active_flag();
        F(s32, 0x3C0) &= ~0x36;
        F(s32, 0x84C) = 0;
        F(s32, 0x850) = 2;
        F(s32, 0x854) = 0;
        F(void *, 0x894) = 0;
        F(void *, 0x898) = 0;
        F(void *, 0x89C) = 0;
        return;
    case 2:
    case 11:
        if (F(s32, 0x84C) == 3) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x18);
        }
        return;
    case 9:
        if (F(s32, 0x84C) == 3) {
            this->pick_next_action();
        }
        return;
    case 7:
        sync_target_pos__12TBoss8DragonFPv(((u8 *)this));
        return;
    case 6:
        if (enemy_validate_retained_target(((u8 *)this)) != 0) {
            ((TObjEneDD_ST *)this)->enemy_copy_target_destination();
        } else {
            F(f32, 0x394) = lbl_805DEEAC * sin_table_lookup(F(s32, 0x60)) + F(f32, 0x410);
            F(f32, 0x398) = F(f32, 0x3C);
            F(f32, 0x39C) = lbl_805DEEAC * cos_table_lookup(F(s32, 0x60)) + F(f32, 0x418);
        }
        this->save_position();
        return;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        this->try_spawn_trap();
        switch (F(s32, 0x84C)) {
        case 0:
            ((TObjEneDD *)this)->update_velocity();
            TBoss8Dragon__sub_802FC9D8(((u8 *)this));
            F(s32, 0x60) = approach_angle_limited(F(s32, 0x60), (s32)(TBoss8Dragon__data_80474B28 * atan2_float(F(f32, 0x3A0), F(f32, 0x3A8))), 0xA0);
            F(s32, 0x60) = (s16)F(s32, 0x60);
            if (((TObjEneDD *)this)->get_flag_b4() != 0) {
                F(s16, 0xB8) = 5;
                F(s32, 0x84C) = 1;
            }
            break;
        case 1:
            F(s32, 0x854)++;
            if (F(s32, 0x854) >= 0x78) {
                F(s16, 0xB8) = 6;
                if (F(void *, 0x894) != 0) {
                    queue_destruction__7TObjectFv(F(void *, 0x894));
                    F(void *, 0x894) = 0;
                }
                if (F(void *, 0x898) != 0) {
                    queue_destruction__7TObjectFv(F(void *, 0x898));
                    F(void *, 0x898) = 0;
                }
                if (F(void *, 0x89C) != 0) {
                    queue_destruction__7TObjectFv(F(void *, 0x89C));
                    F(void *, 0x89C) = 0;
                }
                F(s32, 0x84C) = 2;
                F(s32, 0x850) = 0;
            } else if (!(F(s32, 0xB0) & 4)) {
                ((void (*)(void *, s32))spawn_trap__12TBoss8DragonFii)(((u8 *)this), 0x4003AD0D);
                direction_to_rotation_xz((u8 *)&m_41c, &rot.x, &rot.z);
                F(s32, 0x850)++;
                if (F(s32, 0x850) >= 2) {
                    mem = __nw__7TObjectFUl(0x40);
                    if (mem != 0) {
                        __ct__21TBoss8DragonEffBreathFP7TObjectPvPvls(mem, (u8 *)&m_3c4, (u8 *)&m_410, (u8 *)&m_41c, F(s32, 0x75C), get_entity_id(((u8 *)this)));
                    }
                    F(s32, 0x850) = 0;
                }
                if (F(void *, 0x894) == 0) {
                    F(void *, 0x894) = spawn_particle_effect_with_rotation((u8 *)&m_410, &rot, *(s32 *)((s8 *)(F(u8 *, 0x760)) + 0x14), 0x40);
                    if (F(void *, 0x894) != 0) {
                        ((TParticleCtrl *)(F(void *, 0x894)))->enable();
                    }
                } else {
                    ((TParticleCtrl *)F(void *, 0x894))->set_position((u8 *)&m_428);
                    ((TParticleCtrl *)(F(void *, 0x894)))->set_direction(&rot);
                }
                if (F(void *, 0x898) == 0) {
                    if (*(s32 *)((s8 *)(F(u8 *, 0x760)) + 0x18) != -1) {
                        F(void *, 0x898) = spawn_particle_effect_with_rotation((u8 *)&m_410, &rot, *(s32 *)((s8 *)(F(u8 *, 0x760)) + 0x18), 0x40);
                    }
                    if (F(void *, 0x898) != 0) {
                        ((TParticleCtrl *)(F(void *, 0x898)))->enable();
                    }
                } else {
                    ((TParticleCtrl *)F(void *, 0x898))->set_position((u8 *)&m_428);
                    ((TParticleCtrl *)(F(void *, 0x898)))->set_direction(&rot);
                }
                if (F(void *, 0x89C) == 0) {
                    F(void *, 0x89C) = spawn_particle_effect_with_rotation((u8 *)&m_410, &rot, *(s32 *)((s8 *)(F(u8 *, 0x760)) + 0x1C), 0x40);
                    if (F(void *, 0x89C) != 0) {
                        ((TParticleCtrl *)(F(void *, 0x89C)))->enable();
                    }
                } else {
                    ((TParticleCtrl *)F(void *, 0x89C))->set_position((u8 *)&m_428);
                    ((TParticleCtrl *)(F(void *, 0x89C)))->set_direction(&rot);
                }
            }
            break;
        case 2:
            F(s32, 0x850)++;
            if (F(s32, 0x850) < 0x1E) {
                ((void (*)(void *, s32))spawn_trap__12TBoss8DragonFii)(((u8 *)this), 0x4003AD0D);
            }
            if (((TObjEneDD *)this)->get_flag_b4() != 0) {
                F(s32, 0x84C) = 3;
            }
            break;
        }
        break;
    case 5:
        if (F(void *, 0x894) != 0) {
            queue_destruction__7TObjectFv(F(void *, 0x894));
            F(void *, 0x894) = 0;
        }
        if (F(void *, 0x898) != 0) {
            queue_destruction__7TObjectFv(F(void *, 0x898));
            F(void *, 0x898) = 0;
        }
        if (F(void *, 0x89C) != 0) {
            queue_destruction__7TObjectFv(F(void *, 0x89C));
            F(void *, 0x89C) = 0;
        }
        break;
    }
}

}
#pragma pop
#undef F
extern "C" {
void TBoss8Dragon::handle_tail_attack_state(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 7;
        ((VObj_802F9B8C *)this)->m94();
        this->reset_timer();
        this->set_active_flag();
        *(s32 *)((s8 *)this + 0x3C0) &= ~0x34;
        *(s32 *)((s8 *)this + 0x3C0) |= 2;
        *(s32 *)((s8 *)this + 0x84C) = 0;
        ((TBoss8DragonEffTail *)(*(u8 **)((s8 *)this + 0x67C)))->enable();
        break;
    case 2:
    case 11:
        if (((TObjEneDD *)this)->get_flag_b4() != 0) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0x18);
        }
        break;
    case 9:
        if (((TObjEneDD *)this)->get_flag_b4() != 0) {
            this->pick_next_action();
        }
        break;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        (*(s32 *)((s8 *)this + 0x84C))++;
        if (((TObjMotion *)this)->is_passing_frame(0.0f) != 0 || ((TObjMotion *)this)->is_passing_frame(12.0f) != 0) {
            ((s32 (*)(void *, s32))spawn_effect__12TBoss8DragonFii)(((u8 *)this), 0x4003AD09);
        }
        if (*(s32 *)((s8 *)this + 0x84C) > 1) {
            if (((TObjMotion *)this)->is_passing_frame(TBoss8Dragon__data_805DEEA4) != 0) {
                ((TBoss8DragonEffTail *)(*(u8 **)((s8 *)this + 0x67C)))->disable();
            } else if (((TObjMotion *)this)->is_passing_frame(lbl_805DEEA8) != 0) {
                ((TBoss8DragonEffTail *)(*(u8 **)((s8 *)this + 0x67C)))->enable();
            }
            (*(VObj_802F9B8C **)((s8 *)this + 0x67C))->m1();
        }
        break;
    }
}

void TBoss8Dragon::sub_802F9A4C(s32 arg1) {
    s32 i;
    switch (arg1) {
    case 4:
        for (i = 0; i < 4; i++) {
            ((TBoss8Dragon *)(&((Obj_802F9A4C *)this)->fades[i]))->set_speed(lbl_805DEEA0);
        }
        this->m_3c0 |= 0x100;
        sub_802F9850(arg1);
        break;
    case 2:
    case 11:
        this->m_754 = 0;
        if (((s32 (*)(void *))TBoss8Dragon__sub_802F46F4)(((u8 *)this)) == 0) {
            this->pick_next_action();
        }
        break;
    case 9:
        if (((s32 (*)(void *))TBoss8Dragon__sub_802F46F4)(((u8 *)this)) == 0) {
            this->pick_next_action();
        }
        break;
    case 0:
        switch (this->m_84c) {
        case 0:
            break;
        case 1:
            for (i = 0; i < 4; i++) {
                ((Obj_802F9A4C *)this)->fades[i].m4();
            }
            break;
        }
        sub_802F9850(arg1);
        break;
    case 5:
        this->m_3c0 &= ~0x100;
        sub_802F9850(arg1);
        break;
    default:
        sub_802F9850(arg1);
        break;
    }
}

void TBoss8Dragon::sub_802F9850(s32 arg1) {
    struct { f32 x, y, z; } sp8;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)((u8 *)this) + 0xB8) = 0xF;
        ((TObjMotion *)this)->advance_animation();
        ((VObj_18_444bc5 *)(((u8 *)this)))->m94();
        this->reset_timer();
        this->set_active_flag();
        *(s32 *)((s8 *)((u8 *)this) + 0x3C0) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3C0) & ~0x36);
        *(s32 *)((s8 *)((u8 *)this) + 0x84C) = 0;
        *(s32 *)((s8 *)((u8 *)this) + 0x850) = 0;
        return;
    case 2:
    case 11:
        *(s32 *)((s8 *)((u8 *)this) + 0x754) = 0;
        if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x850) >= 0x28) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)((void *) (((u8 *)this)), 0x1A);
        }
        return;
    case 9:
        if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x850) >= 0x28) {
            this->pick_next_action();
            return;
        }
        break;
    case 7:
        ((s32 (*)(void))restore_target_pos__12TBoss8DragonFPv)();
        return;
    case 6:
        ((s32 (*)(void))copy_pos_to_field688__12TBoss8DragonFPv)();
        return;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        if (((TObjMotion *)this)->is_passing_frame(14.0f) != 0) {
            ((s32 (*)(void *, s32))spawn_effect__12TBoss8DragonFii)((void *) (((u8 *)this)), 0x4003A804);
        }
        if (((TObjMotion *)this)->is_passing_frame(42.0f) != 0) {
            ((s32 (*)(void *, s32))spawn_effect__12TBoss8DragonFii)((void *) (((u8 *)this)), 0x4003A803);
        }
        if (((TObjMotion *)this)->is_passing_frame(46.0f) != 0) {
            this->spawn_ground_effect();
        }
        switch (*(s32 *)((s8 *)((u8 *)this) + 0x84C)) {
        case 0:
            if (((TObjMotion *)this)->is_passing_frame(35.0f) != 0) {
                *(s32 *)((s8 *)((u8 *)this) + 0x3C0) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x3C0) | 0x30);
                this->set_state();
                *(s32 *)((s8 *)((u8 *)this) + 0x84C) = 1;
                *(s32 *)((s8 *)((u8 *)this) + 0x850) = 0;
                return;
            }
            break;
        case 1:
            *(s32 *)((s8 *)((u8 *)this) + 0x850) = (s32) (*(s32 *)((s8 *)((u8 *)this) + 0x850) + 1);
            eval_bezier_curve__12TBoss8DragonFPviiPvf(boss8_dragon_bezier_points, 4, 0, &sp8, (f32) *(s32 *)((s8 *)((u8 *)this) + 0x850) / 40.0f);
            *(f32 *)((s8 *)((u8 *)this) + 0x3C) = sp8.y;
            break;
        }
        break;
    }
}

}
#pragma push
#pragma fp_contract on
extern "C" {
void TBoss8Dragon::state_turn_and_charge(s32 arg1) {
    Dragon_802F951C *d = (Dragon_802F951C *)this;
    s32 diff;
    switch (arg1) {
    case 4:
        d->field_B8 = 0x10;
        d->m94();
        ((TBoss8Dragon *)d)->set_state();
        ((TBoss8Dragon *)d)->activate_attack();
        d->field_3C0 &= ~0x36;
        ((TObjEneDD *)d)->update_velocity();
        init_acceleration_curve(d->curve0, 0.1f, -0.1f, d->f3AC, 2.0f + *(f32 *)(TBoss8Dragon__data_80541DDC[0] + 0x14));
        diff = angle_diff_s16(d->angle, (s32)(TBoss8Dragon__data_80474B28 * atan2_float(d->dir.x, d->dir.z)));
        if (diff >= 0) {
            d->sign = 1;
        } else {
            diff = -diff;
            d->sign = -1;
        }
        init_acceleration_curve(d->curve1, 16.0f, -16.0f, (f32)diff, (f32)(s32)(256.0f * (2.0f + *(f32 *)(TBoss8Dragon__data_80541DDC[0] + 0x14))));
        d->base = d->angle;
        d->field_84C = 0;
        d->field_864 = 0.0f;
        break;
    case 2:
        send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 26);
        break;
    case 11:
        if (d->field_84C == 2) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 15);
        }
        break;
    case 9:
        if (d->field_84C == 2) {
            this->pick_next_action();
        }
        break;
    case 7:
        sync_target_pos__12TBoss8DragonFPv(d);
        break;
    case 6:
        ((void (*)(u8 *, void *))TBoss8Dragon__sub_802FC500)(((u8 *)this), d->f394);
        ((TBoss8Dragon *)d)->save_position();
        break;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        spawn_effect_if_in_band__12TBoss8DragonFi((s32)d);
        TBoss8Dragon__sub_802FB09C((s32)d);
        switch (d->field_84C) {
        case 0:
            d->field_864 += 1.0f;
            d->angle = (s32)((f32)d->sign * sample_acceleration_curve(d->curve1, d->field_864) + (f32)d->base);
            if (((TObjBoss2Tunnel *)(d->curve1))->check_param_threshold(d->field_864) != 0) {
                d->field_864 = 0.0f;
                d->field_84C = 1;
            }
            break;
        case 1: {
            f32 prev = sample_acceleration_curve(d->curve0, d->field_864);
            f32 dlt;
            Vec_802F951C v;
            d->field_864 += 1.0f;
            dlt = sample_acceleration_curve(d->curve0, d->field_864) - prev;
            v.x = d->dir.x * dlt;
            v.y = 0.0f;
            v.z = d->dir.z * dlt;
            apply_ground_movement__12TBoss8DragonFPvPv(((u8 *)this), &v.x);
            if (((TObjBoss2Tunnel *)(d->curve0))->check_param_threshold(d->field_864) != 0) {
                d->field_84C = 2;
            }
            break;
        }
        }
        break;
    case 5:
        VecCopy__FP3VecPC3Vec(&d->v5E0, &d->dir);
        break;
    }
}

#define F(t, o) (*(t *)((u8 *)this + (o)))
#define VO ((VObj_18_444bc5x *)this)
void TBoss8Dragon::sub_802F8F88(s32 arg1) {
    extern u8 TBoss8Dragon__data_804744A8[];
    f32 *d = &m_878;

    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 0x10;
        VO->m94();
        this->set_state();
        this->activate_attack();
        F(s32, 0x3C0) &= ~0x36;
        F(s32, 0x84C) = 0;
        F(s32, 0x850) = 0;
        F(s32, 0x854) = 0;
        F(u32, 0x894) = 0;
        break;
    case 2:
    case 11:
        if (F(s32, 0x84C) == 3) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x1A);
        }
        break;
    case 9:
        if (F(s32, 0x84C) == 4) {
            this->pick_next_action();
        }
        break;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        switch (F(s32, 0x84C)) {
        case 0:
            if (TBoss8Dragon__sub_802FC674((Obj_802FC674 *)(((u8 *)this)), d) != 0) {
                F(s32, 0x85C) = (s32)(TBoss8Dragon__data_80474B28 * atan2_float(d[0] - F(f32, 0x38), d[2] - F(f32, 0x40)));
            } else {
                F(s32, 0x85C) = get_random_scaled__9TObjEneDDFv(((u8 *)this));
                d[0] = 125.0f * sin_table_lookup(F(s32, 0x85C));
                d[1] = 0.0f;
                d[2] = 125.0f * cos_table_lookup(F(s32, 0x85C));
            }
            F(s32, 0x85C) = (s16)F(s32, 0x85C);
            F(s32, 0x84C) = 1;
            if (F(s32, 0x74C) != 0) {
                F(s32, 0x85C) = (s16)F(s32, 0x60);
                VecCopy__FP3VecPC3Vec(d, (u8 *)&m_38);
                d[0] += 125.0f * sin_table_lookup(F(s32, 0x85C));
                d[1] = 0.0f;
                d[2] += 125.0f * cos_table_lookup(F(s32, 0x85C));
                F(s32, 0x84C) = 2;
                F(s32, 0x650) = 0;
                F(s32, 0x60) = F(s32, 0x85C);
                F(s16, 0xB8) = 0x12;
                F(s32, 0x3C0) |= 0x30;
            }
            this->check_hit_result(F(s32, 0x60), F(s32, 0x85C));
            TBoss8Dragon__sub_802FC060(((u8 *)this), F(s32, 0x85C));
        case 1:
            spawn_effect_if_in_band__12TBoss8DragonFi((s32)((u8 *)this));
            TBoss8Dragon__sub_802FB09C((s32)((u8 *)this));
            if (TBoss8Dragon__sub_802FBFA4(((u8 *)this)) != 0) {
                F(s32, 0x650) = 0;
                F(s32, 0x60) = F(s32, 0x85C);
                F(s32, 0x84C) = 2;
                F(s16, 0xB8) = 0x12;
                F(s32, 0x3C0) |= 0x30;
            }
            break;
        case 2:
            if (((TObjMotion *)this)->is_passing_frame(2.0f) != 0) {
                spawn_effect__12TBoss8DragonFii((s32)((u8 *)this), 0x4003A804);
            }
            if (((TObjMotion *)this)->is_passing_frame(45.0f) != 0) {
                spawn_effect__12TBoss8DragonFii((s32)((u8 *)this), 0x4003AD0A);
            }
            if (((TObjMotion *)this)->is_passing_frame(14.0f) != 0 || ((TObjMotion *)this)->is_passing_frame(53.0f) != 0) {
                this->spawn_ground_effect();
            }
            if (F(u32, 0x894) == 0) {
                if (F(f32, 0xC0) >= 20.0f) {
                    F(u32, 0x894) = spawn_continuous_particle_effect_with_flags((u8 *)&m_410, (void *)*(s32 *)((s8 *)(F(u8 *, 0x760)) + 0x20), 0x40);
                }
            } else if (F(f32, 0xC0) <= 40.0f) {
                ((TParticleCtrl *)F(void *, 0x894))->set_position((u8 *)&m_410);
            } else {
                queue_destruction__7TObjectFv(F(void *, 0x894));
                F(u32, 0x894) = 0;
            }
            if (((TObjMotion *)this)->is_passing_frame(47.0f) != 0) {
                Vec_802F8F88 v;
                Vec_802F8F88 dir;
                Vec_802F8F88 rot;
                f32 len;
                VecCopy__FP3VecPC3Vec(&dir, d);
                subtract_vector(&dir, (u8 *)&m_38);
                len = normalize_vector_xz__FP3Vec(&dir);
                dir.y = 0.0f;
                VecCopy__FP3VecPC3Vec(&v, d);
                v.y = *(f32 *)(TBoss8Dragon__data_804744A8 + 4);
                {
                    void *b = __nw__7TObjectFUl(0x58);
                    if (b != 0) {
                        TBoss8DragonEffBullet__ct(b, (u8 *)&m_3c4, (u8 *)&m_410, &v, F(s32, 0x75C), get_entity_id(((u8 *)this)));
                    }
                }
                rotate_vec_xz(&dir, &rot, 0x1000);
                VecCopy__FP3VecPC3Vec(&v, (u8 *)&m_38);
                v.x += rot.x * len;
                v.y = *(f32 *)(TBoss8Dragon__data_804744A8 + 4);
                v.z += rot.z * len;
                {
                    void *b = __nw__7TObjectFUl(0x58);
                    if (b != 0) {
                        TBoss8DragonEffBullet__ct(b, (u8 *)&m_3c4, (u8 *)&m_410, &v, F(s32, 0x75C), get_entity_id(((u8 *)this)));
                    }
                }
                rotate_vec_xz(&dir, &rot, -0x1000);
                VecCopy__FP3VecPC3Vec(&v, (u8 *)&m_38);
                v.x += rot.x * len;
                v.y = *(f32 *)(TBoss8Dragon__data_804744A8 + 4);
                v.z += rot.z * len;
                {
                    void *b = __nw__7TObjectFUl(0x58);
                    if (b != 0) {
                        TBoss8DragonEffBullet__ct(b, (u8 *)&m_3c4, (u8 *)&m_410, &v, F(s32, 0x75C), get_entity_id(((u8 *)this)));
                    }
                }
                spawn_particle_effect_with_flags((u8 *)&m_410, (void *)*(s32 *)((s8 *)(F(u8 *, 0x760)) + 0x24), 0x40);
                F(s32, 0x84C) = 3;
                F(s32, 0x854) = 0;
                F(s32, 0x3C0) &= ~0x30;
            }
            break;
        case 3:
            F(s32, 0x854)++;
            if (F(s32, 0x854) > 10) {
                F(s32, 0x850)++;
                if (F(s32, 0x850) >= 2) {
                    F(s32, 0x84C) = 4;
                } else {
                    F(s32, 0x84C) = 0;
                }
            }
            break;
        }
        break;
    case 5:
        if (F(u32, 0x894) != 0) {
            queue_destruction__7TObjectFv(F(void *, 0x894));
            F(u32, 0x894) = 0;
        }
        break;
    }
}

#undef F
#undef VO
#define F(t, o) (*(t *)(arg0 + (o)))
#define VO ((VObj_18_667c9b *)(arg0))
void TBoss8Dragon::sub_802F89F8(s32 event) {
    void *bullet;
    s32 found;
    Vec pos;
    TObjPlayer *player;
    f32 step;

    switch (event) {
    case 4:
        this->m_b8 = 0x19;
        ((TObjEneDD *)this)->vfunc_96();
        this->set_state();
        this->activate_attack();
        this->m_3c0 |= 0x30;
        this->m_3c0 &= ~0x6;
        this->m_84c = 0;
        this->m_850 = 0;
        this->m_854 = 0;
        this->m_85c = 0;
        this->m_864 = 13.0f;
        break;
    case 2:
    case 11:
        send_action_packet__12TBoss8DragonFPvi((u8 *)this, 0x1A);
        break;
    case 9:
        if (this->m_84c == 6) {
            this->pick_next_action();
        }
        break;
    case 7:
        {
            u32 seed = (u32)(s32)(100.0f * this->m_690);
            s32 low = (s32)(100.0f * this->m_694);
            seed *= 0x10000UL;
            seed |= (u32)low & 0xFFFFUL;
            subtractive_rng_seed(&this->m_764, seed);
        }
        break;
    case 6:
        copy_pos_to_field688__12TBoss8DragonFPv(this);
        break;
    case 0:
        switch (this->m_84c) {
        case 0:
            ((TObjMotion *)this)->advance_animation();
            if (((TObjMotion *)this)->is_passing_frame(39.0f) != 0) {
                this->m_84c = 1;
                spawn_effect__12TBoss8DragonFii((s32)this, 0x4003B210);
            }
            break;
        case 1:
            ((TObjMotion *)this)->advance_animation();
            if (this->m_c0 > 22.0f) {
                this->m_5c = (s32)(-16384.0f * ((this->m_c0 - 22.0f) / (this->m_c4 - 22.0f)));
            }
            if (((TObjEneDD *)this)->get_flag_b4() != 0) {
                this->m_b8 = 0x18;
                this->m_84c = 2;
            }
            break;
        case 2:
            ((TObjMotion *)this)->advance_animation();
            this->m_5c = 0;
            if (this->m_c0 > 22.0f) {
                this->m_85c = 0x1000;
                this->m_84c = 3;
                this->m_64c = 1;
            }
            break;
        case 3:
            this->m_85c += 0x40;
            if (this->m_85c > 0x2000) {
                this->m_85c = 0x2000;
            }
            this->m_850++;
            if (this->m_850 >= 4) {
                this->m_850 = 0;
                this->m_854++;
                if (this->m_854 >= 40) {
                    this->m_84c = 4;
                    this->m_64c = 0;
                }
                found = 0;
                if ((this->m_854 & 1) == 0) {
                    player = get_player_by_client_id((u16)((this->m_854 >> 1) % 4));
                    if (player->is_alive() != 0) {
                        VecCopy(&pos, &player->position);
                        pos.x += 100.0f * (calc_random_ratio__10TObjPlayerFv(&this->m_764) - 0.5f);
                        pos.z += 100.0f * (calc_random_ratio__10TObjPlayerFv(&this->m_764) - 0.5f);
                        found = 1;
                    }
                }
                if (found == 0) {
                    pos.x = 700.0f * (calc_random_ratio__10TObjPlayerFv(&this->m_764) - 0.5f);
                    pos.y = 0.0f;
                    pos.z = 700.0f * (calc_random_ratio__10TObjPlayerFv(&this->m_764) - 0.5f);
                }
                bullet = __nw__7TObjectFUl(0x58);
                if (bullet != 0) {
                    TBoss8DragonEffBullet__ct(bullet, &this->m_3c4, &this->m_410, &pos, this->m_75c, get_entity_id((u8 *)this));
                }
            }
            this->m_5c -= this->m_85c;
            break;
        case 4:
            this->m_85c -= 0x50;
            if (this->m_85c < 0x1300) {
                this->m_85c = 0x1300;
                this->m_5c -= this->m_85c;
                if ((this->m_5c & 0xFFFF) <= 0x1300 || (this->m_5c & 0xFFFF) >= 0xED00) {
                    this->m_5c = 0;
                    this->m_860 = (s32)(TBoss8Dragon__data_80474B28 * atan2_float(-this->m_38, -this->m_40));
                    this->m_84c = 5;
                }
            } else {
                this->m_5c -= this->m_85c;
            }
            break;
        case 5:
            ((TObjMotion *)this)->advance_animation();
            step = (f32)angle_diff_s16(this->m_60, this->m_860);
            step *= 0.3f;
            if ((step < 512.0f && step >= -512.0f) || ((TObjEneDD *)this)->get_flag_b4() != 0) {
                this->m_60 = this->m_860;
                this->m_84c = 6;
            } else {
                this->m_60 += (s32)step;
            }
            break;
        case 6:
            ((TObjMotion *)this)->advance_animation();
            break;
        }
        if (this->m_84c == 1 || this->m_84c == 2) {
            this->m_864 += lbl_805D69C0;
            if (this->m_864 < 0.0f) {
                this->m_864 = 0.0f;
            }
            this->m_3c += this->m_864;
            if (this->m_3c <= 180.0f) {
                this->m_3c = 180.0f;
            }
        }
        if (this->m_84c == 3 || this->m_84c == 4 || this->m_84c == 5) {
            this->m_3c -= 1.0f;
            if (this->m_3c < 180.0f) {
                this->m_3c = 180.0f;
            }
        }
        break;
    case 5:
        this->m_5c = 0;
        ((TObjEnemy *)this)->sub_8002AE64();
        this->m_64c = 0;
        break;
    }
}

void TBoss8Dragon::sub_802F87EC(s32 arg1) {
    extern u8 TBoss8Dragon__data_804744A8[];
    struct { f32 x, y, z; } v;
    s32 ang;
    f32 c;
    s32 i;
    u8 *hit;
    switch (arg1) {
    case 4:
        for (i = 0; i < 4; i++) {
            ((TBoss8Dragon *)(&((Self_802F87EC *)this)->arr[i]))->set_speed(0.008f);
        }
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) | 0x100);
        sub_802F8578(arg1);
        spawn_effect__12TBoss8DragonFii((s32)((u8 *)this), 0x4003A814);
        return;
    case 7:
        TBoss8Dragon__sub_802F48DC(this, (Vec *)((u8 *)this + 0x38));
        return;
    case 6:
        *(s32 *)((s8 *)this + 0x3B0) = (s32) *(s32 *)((s8 *)this + 0x3B4);
        if (update_linked_position__12TBoss8DragonFv(((u8 *)this)) != 0) {
            ((TObjEneDD_ST *)this)->enemy_copy_target_destination();
        } else {
            ((TObjEneDD *)this)->set_target_destination((const Vec *)TBoss8Dragon__data_804744A8);
        }
        c = sin_table_lookup((s32)(ang = (s32) (65536.0f * (0.000030517578f * (f32) rand()))));
        v.x = *(f32 *)((s8 *)TBoss8Dragon__data_80541DDC[2] + 0xC) * c + *(f32 *)((s8 *)this + 0x394);
        v.y = 30.0f;
        v.z = *(f32 *)((s8 *)TBoss8Dragon__data_80541DDC[2] + 0xC) * cos_table_lookup(ang) + *(f32 *)((s8 *)this + 0x39C);
        hit = (u8 *)csnVecterUnder((s32)&v, 0x16EF);
        if ((hit != NULL) && (*(f32 *)((s8 *)(*(u8 **)((s8 *)hit + 4)) + 4) <= 30.0f)) {
            *(f32 *)((s8 *)this + 0x394) = v.x;
            *(f32 *)((s8 *)this + 0x39C) = v.z;
        }
        this->save_position();
        return;
    case 0:
        for (i = 0; i < 4; i++) {
            ((Self_802F87EC *)this)->arr[i].m5();
        }
        sub_802F8578(arg1);
        return;
    case 5:
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) & 0xFFFFFEFF);
        sub_802F8578(arg1);
        return;
    case 11:
    default:
        sub_802F8578(arg1);
        return;
    }
}

}
#pragma pop
extern "C" {
void TBoss8Dragon::sub_802F8578(s32 arg1) {
    Pair_802F8578 out;

    switch (arg1) {
    case 4:
        ((Dragon_802F8578 *)this)->field_B8 = 0x11;
        ((Dragon_802F8578 *)this)->m94();
        ((TBoss8Dragon *)((Dragon_802F8578 *)this))->set_state();
        ((TBoss8Dragon *)((Dragon_802F8578 *)this))->activate_attack();
        ((Dragon_802F8578 *)this)->field_3C0 |= 0x36;
        ((Dragon_802F8578 *)this)->field_84C = 0;
        ((Dragon_802F8578 *)this)->field_864 = 0.0f;
        ((Dragon_802F8578 *)this)->field_850 = 0;
        break;
    case 2:
    case 11:
        ((Dragon_802F8578 *)this)->field_754 = 0;
        if (((TObjEneDD *)((Dragon_802F8578 *)this))->get_flag_b4() != 0) {
            send_action_packet__12TBoss8DragonFPvi((u8 *)((Dragon_802F8578 *)this), 0x18);
        }
        break;
    case 9:
        if (((TObjEneDD *)((Dragon_802F8578 *)this))->get_flag_b4() != 0) {
            switch (((Dragon_802F8578 *)this)->field_326) {
            default:
            case 8:
                ((TBoss8Dragon *)((Dragon_802F8578 *)this))->pick_next_action();
                break;
            case 10:
                send_action_packet__12TBoss8DragonFPvi((u8 *)((Dragon_802F8578 *)this), 9);
                break;
            case 11:
                send_action_packet__12TBoss8DragonFPvi((u8 *)((Dragon_802F8578 *)this), 0xD);
                break;
            case 12:
                send_action_packet__12TBoss8DragonFPvi((u8 *)((Dragon_802F8578 *)this), 0x15);
                break;
            }
        }
        break;
    case 7:
        restore_target_pos__12TBoss8DragonFPv(((Dragon_802F8578 *)this));
        break;
    case 6:
        copy_pos_to_field688__12TBoss8DragonFPv(((Dragon_802F8578 *)this));
        break;
    case 0:
        ((TObjMotion *)((Dragon_802F8578 *)this))->advance_animation();
        switch (((Dragon_802F8578 *)this)->field_84C) {
        case 0:
            eval_bezier_curve__12TBoss8DragonFPviiPvf(boss8_dragon_bezier_points_3, 3, 0, &out,
                ((TObjEneDD_ST *)((Dragon_802F8578 *)this))->get_motion_frame() / 50.0f);
            ((Dragon_802F8578 *)this)->pos.y = out.b;
            if (((TObjMotion *)((Dragon_802F8578 *)this))->is_passing_frame(2.0f) != 0) {
                spawn_effect__12TBoss8DragonFii((s32)((Dragon_802F8578 *)this), 0x4003A804);
            }
            if (((TObjMotion *)((Dragon_802F8578 *)this))->is_passing_frame(11.0f) != 0) {
                ((TBoss8Dragon *)((Dragon_802F8578 *)this))->spawn_ground_effect();
            }
            if (((TObjMotion *)((Dragon_802F8578 *)this))->is_passing_frame(50.0f) != 0) {
                fill_value_array(((Dragon_802F8578 *)this)->field_680);
                create_boss8_piller_ctrl((s32)&m_38, (s32)(((s32 (*)(u8 *))get_entity_id)((u8 *)((Dragon_802F8578 *)this))), 100.0f);
                spawn_particle_effect_with_flags(&m_38, (void *)((Dragon_802F8578 *)this)->field_760->id8, 0x40);
                if (((Dragon_802F8578 *)this)->field_760->idC != -1) {
                    spawn_particle_effect_with_flags(&m_38, (void *)((Dragon_802F8578 *)this)->field_760->idC, 0x40);
                }
                spawn_effect__12TBoss8DragonFii((s32)((Dragon_802F8578 *)this), 0x4003AD0E);
                TCameraCtrl::set_shake_preset(1);
                TBoss8Dragon__sub_802FB778((s32)((Dragon_802F8578 *)this));
                ((TBoss8Dragon *)((Dragon_802F8578 *)this))->reset_timer();
                ((TBoss8Dragon *)((Dragon_802F8578 *)this))->set_active_flag();
                ((Dragon_802F8578 *)this)->field_84C = 1;
            }
            break;
        case 1:
            break;
        }
        break;
    case 5:
        ((TBoss8Dragon *)((Dragon_802F8578 *)this))->set_active_flag();
        break;
    }
}

void TBoss8Dragon::sub_802F8270(s32 arg1) {
    f32 var_f31;
    f32 temp_f30;
    f32 temp_f29;
    f32 temp_f1;
    s32 temp_r5;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 8;
        ((VObj_18_444bc5 *)(((u8 *)this)))->m94();
        this->reset_timer();
        this->set_active_flag();
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) | 0x16);
        temp_r5 = *(s32 *)((s8 *)this + 0x3C0) & 0xFFFFFFDF;
        *(s32 *)((s8 *)this + 0x3C0) = temp_r5;
        *(s32 *)((s8 *)this + 0x84C) = 0;
        *(s32 *)((s8 *)this + 0x850) = 0;
        ((void (*)(void *, int, int))spawn_effect__12TBoss8DragonFii)(((u8 *)this), 0x4003AD06, temp_r5);
        return;
    case 11:
        if (((s32) *(s32 *)((s8 *)this + 0x84C) >= 0x96) && (mask_flags__12TBoss8DragonFiii((s32)((u8 *)this), *(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8), 2) != 0)) {
            *(s32 *)((s8 *)this + 0x84C) = 0x1C2;
        }
        if (((s32) *(s32 *)((s8 *)this + 0x850) == 2) && (((TObjEneDD *)this)->get_flag_b4() != 0)) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x18);
        }
        return;
    case 2:
        if (((s32) *(s32 *)((s8 *)this + 0x850) == 2) && (((TObjEneDD *)this)->get_flag_b4() != 0)) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x18);
            return;
        }
        break;
    case 9:
        if (((s32) *(s32 *)((s8 *)this + 0x850) == 2) && (((TObjEneDD *)this)->get_flag_b4() != 0)) {
            TBoss8Dragon__sub_802FBA1C(this);
            return;
        }
        break;
    case 7:
        restore_target_pos__12TBoss8DragonFPv(((u8 *)this));
        return;
    case 6:
        copy_pos_to_field688__12TBoss8DragonFPv(((u8 *)this));
        return;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        switch (*(s32 *)((s8 *)this + 0x850)) {
        case 0:
            if (((TObjMotion *)this)->is_passing_frame(7.0f) != 0) {
                TBoss8Dragon__sub_802FB70C((s32)((u8 *)this));
            } else if (((TObjMotion *)this)->is_passing_frame(14.0f) != 0) {
                ((void (*)(void *))update_pos_from_data__12TBoss8DragonFv)(((u8 *)this));
            } else if (((TObjMotion *)this)->is_passing_frame(18.0f) != 0) {
                ((void (*)(void *))TBoss8Dragon__sub_802FB484)(((u8 *)this));
            }
            if ((s16) *(s16 *)((s8 *)this + 0xB8) != 8) {
                fn_802F2E7C((int) (*(s32 *)((s8 *)this + 0x684)), ((u8 *)this) + 0x38, (int) (*(s32 *)((s8 *)this + 0x60)));
                *(s32 *)((s8 *)this + 0x850) = 1;
                return;
            }
            break;
        case 1:
            spawn_trap__12TBoss8DragonFii((s32)((u8 *)this), 0x4003AD12);
            *(s32 *)((s8 *)this + 0x84C) = (s32) (*(s32 *)((s8 *)this + 0x84C) + 1);
            if ((s32) *(s32 *)((s8 *)this + 0x84C) >= 0x1C2) {
                *(s16 *)((s8 *)this + 0xB8) = 0xA;
                *(s32 *)((s8 *)this + 0x850) = 2;
                ((TBoss8Dragon *)(*(s32 *)((s8 *)this + 0x684)))->update_colli_parts();
                return;
            }
            break;
        case 2:
            var_f31 = 0.9f;
            temp_f30 = sin_table_lookup((int) (*(s32 *)((s8 *)this + 0x60)));
            temp_f29 = cos_table_lookup((int) (*(s32 *)((s8 *)this + 0x60)));
            if ((s32) *(s32 *)((s8 *)this + 0x74C) != 0) {
                var_f31 = this->clamp_step_in_radius(temp_f30, temp_f29, 0.9f);
            }
            temp_f1 = *(f32 *)((s8 *)this + 0xC0);
            if ((temp_f1 >= 13.0f) && (temp_f1 <= 20.0f)) {
                ((TObjEneDD *)this)->move_to_shot_position(temp_f30, temp_f29, var_f31);
                return;
            }
            break;
        }
        break;
    case 5:
        TBoss8Dragon__sub_802FC850(this);
        ((TBoss8Dragon *)(*(s32 *)((s8 *)this + 0x684)))->update_colli_parts();
        break;
    }
}

void TBoss8Dragon::sub_802F8150(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 2;
        ((VObj_18_574b0f *)(((u8 *)this)))->m93();
        this->reset_timer();
        this->set_active_flag();
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) | 0x30);
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) & 0xFFFFFFF9);
        ((VObj_18_574b0f *)(((u8 *)this)))->m89();
        break;
    case 2:
    case 11:
        if (((TObjEneDD *)this)->get_flag_b4() != 0) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x18);
        }
        break;
    case 9:
        if (((TObjEneDD *)this)->get_flag_b4() != 0) {
            this->pick_next_action();
        }
        break;
    case 7:
        restore_target_pos__12TBoss8DragonFPv(((u8 *)this));
        break;
    case 6:
        copy_pos_to_field688__12TBoss8DragonFPv(((u8 *)this));
        break;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        if (((TObjMotion *)this)->is_passing_frame(20.0f) != 0) {
            play_cue_stream_file((s32)lbl_80474B40);
        }
        break;
    case 5:
        ((VObj_18_574b0f *)(((u8 *)this)))->m90();
        break;
    }
}

void TBoss8Dragon::state_roar(s32 arg1) {
    s32 temp_r4;
    switch (arg1) {
    case 4:
        this->m_b8 = 0x10;
        ((VObj_18_dc1f7f *)this)->m94();
        this->set_state();
        this->activate_attack();
        this->m_3c0 = (s32) (this->m_3c0 | 0x30);
        this->m_3c0 = (s32) (this->m_3c0 & 0xFFFFFFF9);
        play_cue_stream_file((s32)lbl_80474B40);
        ((VObj_18_dc1f7f *)this)->m89();
        this->m_84c = 0;
        break;
    case 9:
        if ((s32) this->m_84c >= 0x3C) {
            this->pick_next_action();
        }
        break;
    case 7:
        restore_target_pos__12TBoss8DragonFPv(this);
        break;
    case 6:
        copy_pos_to_field688__12TBoss8DragonFPv(this);
        break;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        temp_r4 = this->m_84c;
        this->m_84c = (temp_r4 + 1);
        ((void (*)(void *, int))spawn_effect_if_in_band__12TBoss8DragonFi)(this, temp_r4);
        TBoss8Dragon__sub_802FB09C((s32)this);
        break;
    case 5:
        ((VObj_18_dc1f7f *)this)->m90();
        break;
    case 11:
        break;
    }
}

void TBoss8Dragon::sub_802F7B70(s32 arg1) {
    extern const f64 TBoss8Dragon__data_80474B28;
    extern const u8 TBoss8Dragon__data_804744A8[];
    switch (arg1) {
    case 4:
        ((Obj_802F7B70 *)this)->fb8 = 0x10;
        ((Obj_802F7B70 *)this)->m94();
        ((TBoss8Dragon *)((Obj_802F7B70 *)this))->set_state();
        ((TBoss8Dragon *)((Obj_802F7B70 *)this))->activate_attack();
        ((Obj_802F7B70 *)this)->f3c0 &= ~0x36;
        ((Obj_802F7B70 *)this)->state = 0;
        ((Obj_802F7B70 *)this)->timer = 0;
        ((Obj_802F7B70 *)this)->spawned = 0;
        ((Obj_802F7B70 *)this)->spin = 0;
        ((Obj_802F7B70 *)this)->angle = (s32)(TBoss8Dragon__data_80474B28 * atan2_float(((Obj_802F7B70 *)this)->f3a0, ((Obj_802F7B70 *)this)->f3a8));
        ((Obj_802F7B70 *)this)->f3ac += 5.0f;
        TBoss8Dragon__sub_802FC060(((Obj_802F7B70 *)this), ((Obj_802F7B70 *)this)->angle);
        if (((Obj_802F7B70 *)this)->f3ac < 50.0f) {
            ((Obj_802F7B70 *)this)->f864 = ((Obj_802F7B70 *)this)->f868 = ((Obj_802F7B70 *)this)->f3ac / 60.0f;
            ((Obj_802F7B70 *)this)->f86c = 0.0f;
        } else {
            f32 t;
            ((Obj_802F7B70 *)this)->f868 = 1.6666666f;
            t = 2.0f * (50.0f - (((Obj_802F7B70 *)this)->f3ac - 50.0f)) / 30.0f;
            ((Obj_802F7B70 *)this)->f86c = t / 30.0f;
            ((Obj_802F7B70 *)this)->f864 = 1.6666666f - t;
        }
        break;
    case 2:
        if (((Obj_802F7B70 *)this)->state == 6) {
            send_action_packet__12TBoss8DragonFPvi((u8 *)((Obj_802F7B70 *)this), 0x1C);
        }
        break;
    case 11:
        if (((Obj_802F7B70 *)this)->state == 6) {
            send_action_packet__12TBoss8DragonFPvi((u8 *)((Obj_802F7B70 *)this), 0x25);
        }
        break;
    case 9:
        if (((Obj_802F7B70 *)this)->state == 6) {
            ((TBoss8Dragon *)((Obj_802F7B70 *)this))->pick_next_action();
        }
        break;
    case 7:
        sync_target_pos__12TBoss8DragonFPv(((Obj_802F7B70 *)this));
        ((TObjEneDD *)((Obj_802F7B70 *)this))->update_velocity();
        break;
    case 6:
        if (TBoss8Dragon__sub_802FC580((Obj_802FC580 *)((Obj_802F7B70 *)this), &m_394) == 0) {
            ((Obj_802F7B70 *)this)->f394.x = 0.0f;
            ((Obj_802F7B70 *)this)->f394.y = 0.0f;
            ((Obj_802F7B70 *)this)->f394.z = 0.0f;
        }
        ((TObjEneDD *)((Obj_802F7B70 *)this))->update_velocity();
        ((TBoss8Dragon *)((Obj_802F7B70 *)this))->save_position();
        break;
    case 0:
        ((TObjMotion *)((Obj_802F7B70 *)this))->advance_animation();
        switch (((Obj_802F7B70 *)this)->state) {
        case 0:
            ((Obj_802F7B70 *)this)->state = 1;
        case 1:
            spawn_effect_if_in_band__12TBoss8DragonFi((s32)((Obj_802F7B70 *)this));
            TBoss8Dragon__sub_802FB09C((s32)((Obj_802F7B70 *)this));
            if (TBoss8Dragon__sub_802FBFA4((u8 *)((Obj_802F7B70 *)this)) != 0) {
                ((Obj_802F7B70 *)this)->f650 = 0;
                ((Obj_802F7B70 *)this)->rotY = ((Obj_802F7B70 *)this)->angle;
                ((Obj_802F7B70 *)this)->state = 2;
                ((Obj_802F7B70 *)this)->fb8 = 0x16;
            }
            break;
        case 2:
            if (((TObjMotion *)((Obj_802F7B70 *)this))->is_passing_frame(14.0f) != 0) {
                ((Obj_802F7B70 *)this)->f3c0 |= 0x30;
                ((Obj_802F7B70 *)this)->timer = 0;
                ((Obj_802F7B70 *)this)->state = 3;
            }
            break;
        case 3: {
            Vec_802F7B70 v;
            ((Obj_802F7B70 *)this)->f864 += ((Obj_802F7B70 *)this)->f86c;
            ((TObjEneDD *)((Obj_802F7B70 *)this))->move_with_wall_stop(((Obj_802F7B70 *)this)->f3a0, ((Obj_802F7B70 *)this)->f3a8, ((Obj_802F7B70 *)this)->f864);
            eval_bezier_curve__12TBoss8DragonFPviiPvf(TBoss8Dragon__dive_height_curve, 3, 0, &v, (f32)((Obj_802F7B70 *)this)->timer / 60.0f);
            ((Obj_802F7B70 *)this)->pos.y = v.y;
            ((Obj_802F7B70 *)this)->timer++;
            if (((TObjMotion *)((Obj_802F7B70 *)this))->is_passing_frame(39.0f) != 0) {
                ((Obj_802F7B70 *)this)->state = 4;
                spawn_effect__12TBoss8DragonFii((s32)((Obj_802F7B70 *)this), 0x4003B210);
            }
            break;
        }
        case 4:
        case 5: {
            Vec_802F7B70 v;
            ((TObjEneDD *)((Obj_802F7B70 *)this))->move_with_wall_stop(((Obj_802F7B70 *)this)->f3a0, ((Obj_802F7B70 *)this)->f3a8, ((Obj_802F7B70 *)this)->f868);
            ((Obj_802F7B70 *)this)->rotX = approach_angle_limited(((Obj_802F7B70 *)this)->rotX, 0x4000, 0x400);
            if (((Obj_802F7B70 *)this)->spin < 0x2811) {
                ((Obj_802F7B70 *)this)->spin += 0x117;
            }
            ((Obj_802F7B70 *)this)->rotZ += ((Obj_802F7B70 *)this)->spin;
            eval_bezier_curve__12TBoss8DragonFPviiPvf(TBoss8Dragon__dive_height_curve, 3, 0, &v, (f32)((Obj_802F7B70 *)this)->timer / 60.0f);
            ((Obj_802F7B70 *)this)->pos.y = v.y;
            ((Obj_802F7B70 *)this)->timer++;
            if (((Obj_802F7B70 *)this)->f414 <= ((const f32 *)TBoss8Dragon__data_804744A8)[1] - 50.0f && ((Obj_802F7B70 *)this)->state == 4) {
                ((Obj_802F7B70 *)this)->state = 5;
                spawn_effect__12TBoss8DragonFii((s32)((Obj_802F7B70 *)this), 0x4003AD0F);
            }
            if (((Obj_802F7B70 *)this)->pos.y <= 0.0f && ((Obj_802F7B70 *)this)->spawned == 0) {
                TBoss8Dragon::init_state((s32)((Obj_802F7B70 *)this));
                fill_value_array(((Obj_802F7B70 *)this)->f680);
                create_boss8_piller_ctrl((s32)&m_38, (s32)(((s32 (*)(u8 *))get_entity_id)((u8 *)((Obj_802F7B70 *)this))), 100.0f);
                ((Obj_802F7B70 *)this)->spawned = 1;
                ((Obj_802F7B70 *)this)->m89();
                ((Obj_802F7B70 *)this)->m92();
                ((TBoss8Dragon *)((Obj_802F7B70 *)this))->set_action_state();
            }
            if (((Obj_802F7B70 *)this)->timer >= 60) {
                ((Obj_802F7B70 *)this)->state = 6;
                ((Obj_802F7B70 *)this)->f3c0 &= ~1;
            }
            break;
        }
        case 6:
            break;
        }
        break;
    case 5:
        ((Obj_802F7B70 *)this)->rotX = 0;
        ((Obj_802F7B70 *)this)->rotZ = 0;
        break;
    case 1:
    case 3:
    case 8:
    case 10:
        break;
    }
}

void TBoss8Dragon::sub_802F7B4C(s32 a1) { TBoss8Dragon__sub_802F7808((u8 *)this, (u32)a1, 16); }

void TBoss8Dragon::action_17(s32 a1) { TBoss8Dragon__sub_802F7808((u8 *)this, (u32)a1, 17); }

}
#pragma push
#pragma fp_contract on
extern "C" {
void TBoss8Dragon__sub_802F7808(u8 *arg0, u32 arg1, s32 arg2) {
    s32 a;
    switch (arg1) {
    case 4:
        VO->m94();
        ((TBoss8Dragon *)arg0)->set_action_state();
        ((TBoss8Dragon *)arg0)->reset_action();
        F(s32, 0x3C0) |= 0x30;
        F(s32, 0x3C0) &= ~7;
        VO->m89();
        VO->m92();
        if (arg2 == 0x10) {
            F(s32, 0x6D0) = 0;
        } else {
            F(s32, 0x6D0)++;
        }
        fill_value_array(F(s32, 0x680));
        F(s32, 0x84C) = 0;
        F(s32, 0x850) = 0;
        F(f32, 0x864) = 0.0f;
        F(f32, 0x868) = ((TBoss8Dragon *)arg0)->calc_step_value();
        break;
    case 2:
    case 11:
        send_action_packet__12TBoss8DragonFPvi(arg0, 0x1C);
        break;
    case 9:
        if (F(s32, 0x8A0) != 0) {
            ((TBoss8Dragon *)arg0)->pick_next_action();
            F(s32, 0x8A0) = 0;
        } else if (F(s32, 0x84C) == 1) {
            Vec_802F7808 v;
            VecCopy__FP3VecPC3Vec(&v, arg0 + 0x38);
            v.y = 0.0f;
            if (normalize_vector_xz__FP3Vec(&v) < 50.0f) {
                ((TBoss8Dragon *)arg0)->pick_next_action();
            }
        }
        break;
    case 6:
        a = (s32)(65536.0f * random_ratio__9TObjCharaFv());
        F(f32, 0x38) = 350.0f * sin_table_lookup(a);
        F(f32, 0x40) = 350.0f * cos_table_lookup(a);
        copy_pos_to_field688__12TBoss8DragonFPv(arg0);
        break;
    case 0:
        switch (F(s32, 0x84C)) {
        case 0:
            F(s32, 0x850)++;
            if ((f32)F(s32, 0x850) >= 60.0f) {
                F(s32, 0x850) = 0;
                F(s32, 0x84C) = 1;
                restore_target_pos__12TBoss8DragonFPv(arg0);
                F(s32, 0x60) = (s32)(TBoss8Dragon__data_80474B28 * atan2_float(F(f32, 0x38), F(f32, 0x40))) + 0x8000;
                F(f32, 0x3A0) = sin_table_lookup(F(s32, 0x60));
                F(f32, 0x3A8) = cos_table_lookup(F(s32, 0x60));
            }
            break;
        case 1:
            F(f32, 0x864) += 0.1f;
            if (F(f32, 0x864) > F(f32, 0x868)) {
                F(f32, 0x864) = F(f32, 0x868);
            }
            F(f32, 0x38) = F(f32, 0x3A0) * F(f32, 0x864) + F(f32, 0x38);
            F(f32, 0x40) = F(f32, 0x3A8) * F(f32, 0x864) + F(f32, 0x40);
            ((void (*)(u8 *))TBoss8Dragon__sub_802FB300)(arg0);
            F(s32, 0x850)++;
            if (F(s32, 0x850) > 10) {
                ((TBoss8Dragon *)arg0)->spawn_effect();
                F(s32, 0x850) = 0;
            }
            break;
        }
        spawn_trap__12TBoss8DragonFii((s32)arg0, 0x4003AD11);
        break;
    case 5:
        VO->m90();
        VO->m91();
        break;
    }
}

#undef F
#undef VO
#define F(t, o) (*(t *)((u8 *)this + (o)))
#define VO ((VObj_18_667c9b *)this)
void TBoss8Dragon::sub_802F75C8(s32 arg1) {
    struct { f32 x, y, z; } sp8;
    switch (arg1) {
    case 4:
        ((VObj_18_667c9b *)(((u8 *)this)))->m94();
        this->set_action_state();
        this->reset_action();
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) | 0x30);
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) & 0xFFFFFFF8);
        ((VObj_18_667c9b *)(((u8 *)this)))->m89();
        ((VObj_18_667c9b *)(((u8 *)this)))->m92();
        *(s32 *)((s8 *)this + 0x84C) = 0;
        *(s32 *)((s8 *)this + 0x850) = 0;
        *(f32 *)((s8 *)this + 0x868) = this->calc_step_value();
        return;
    case 2:
    case 11:
        ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0x1C);
        return;
    case 9:
        VecCopy__FP3VecPC3Vec(&sp8, ((u8 *)this) + 0x38);
        if (normalize_vector_xz__FP3Vec(&sp8) > 350.0f) {
            this->pick_next_action();
        }
        return;
    case 7:
        ((s32 (*)(void))sync_target_pos__12TBoss8DragonFPv)();
        return;
    case 6:
        if (((s32 (*)(void))select_target_in_front__12TBoss8DragonFPv)() != 0) {
            ((TObjEneDD_ST *)this)->enemy_copy_target_destination();
            ((TObjEneDD *)this)->update_velocity();
        } else {
            *(f32 *)((s8 *)this + 0x3A0) = ((f32 (*)(int))sin_table_lookup)((int) (*(s32 *)((s8 *)this + 0x60)));
            *(f32 *)((s8 *)this + 0x3A8) = ((f32 (*)(int))cos_table_lookup)((int) (*(s32 *)((s8 *)this + 0x60)));
        }
        *(f32 *)((s8 *)this + 0x394) = (350.0f * *(f32 *)((s8 *)this + 0x3A0));
        *(f32 *)((s8 *)this + 0x398) = 0.0f;
        *(f32 *)((s8 *)this + 0x39C) = (f32) (350.0f * *(f32 *)((s8 *)this + 0x3A8));
        this->save_position();
        return;
    case 0:
        ((TObjEneDD *)this)->update_velocity();
        *(s32 *)((s8 *)this + 0x60) = approach_angle_limited((int) (*(s32 *)((s8 *)this + 0x60)), ((s32) (TBoss8Dragon__data_80474B28 * atan2_float((f32) (*(f32 *)((s8 *)this + 0x3A0)), (f32) (*(f32 *)((s8 *)this + 0x3A8))))), 0x600);
        *(f32 *)((s8 *)this + 0x38) = (f32) ((*(f32 *)((s8 *)this + 0x868) * ((f32 (*)(int))sin_table_lookup)((int) (*(s32 *)((s8 *)this + 0x60)))) + *(f32 *)((s8 *)this + 0x38));
        *(f32 *)((s8 *)this + 0x40) = (f32) ((*(f32 *)((s8 *)this + 0x868) * ((f32 (*)(int))cos_table_lookup)((int) (*(s32 *)((s8 *)this + 0x60)))) + *(f32 *)((s8 *)this + 0x40));
        ((s32 (*)(void *)) TBoss8Dragon__sub_802FB300)(((u8 *)this));
        *(s32 *)((s8 *)this + 0x850) = (s32) (*(s32 *)((s8 *)this + 0x850) + 1);
        if ((s32) *(s32 *)((s8 *)this + 0x850) > 0xA) {
            this->spawn_effect();
            *(s32 *)((s8 *)this + 0x850) = 0;
        }
        ((s32 (*)(void *, int))spawn_trap__12TBoss8DragonFii)(((u8 *)this), 0x4003AD11);
        return;
    case 5:
        ((VObj_18_667c9b *)(((u8 *)this)))->m90();
        ((VObj_18_667c9b *)(((u8 *)this)))->m91();
        break;
    }
}

void TBoss8Dragon::handle_spiral_state(s32 arg1) {
    s32 a;
    switch (arg1) {
    case 4:
        VO->m94();
        this->set_action_state();
        this->reset_action();
        F(s32, 0x3C0) |= 0x30;
        F(s32, 0x3C0) &= ~7;
        VO->m89();
        VO->m92();
        fill_value_array(F(s32, 0x680));
        F(s32, 0x84C) = 0;
        F(s32, 0x850) = 0;
        F(f32, 0x868) = this->calc_step_value();
        F(f32, 0x864) = 2.5f * F(f32, 0x868);
        F(f32, 0x86C) = 350.0f;
        F(s32, 0x85C) = 0;
        break;
    case 2:
    case 11:
        send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x1C);
        break;
    case 9:
        if (F(s32, 0x8A0) != 0) {
            this->pick_next_action();
            F(s32, 0x8A0) = 0;
        } else if (F(s32, 0x84C) == 2) {
            this->pick_next_action();
        }
        break;
    case 6:
        a = (s32)(65536.0f * random_ratio__9TObjCharaFv());
        F(f32, 0x38) = 350.0f * sin_table_lookup(a);
        F(f32, 0x40) = 350.0f * cos_table_lookup(a);
        copy_pos_to_field688__12TBoss8DragonFPv(((u8 *)this));
        break;
    case 0:
        switch (F(s32, 0x84C)) {
        case 0:
            F(s32, 0x850)++;
            if ((f32)F(s32, 0x850) >= 60.0f) {
                F(s32, 0x850) = 0;
                F(s32, 0x84C) = 1;
                restore_target_pos__12TBoss8DragonFPv(((u8 *)this));
                F(s32, 0x85C) = (s32)(TBoss8Dragon__data_80474B28 * atan2_float(F(f32, 0x38), F(f32, 0x40)));
                return;
            }
            break;
        case 1:
            a = (s32)(TBoss8Dragon__data_80474B28 * (F(f32, 0x864) / F(f32, 0x86C)));
            F(s32, 0x85C) += a;
            F(f32, 0x38) = F(f32, 0x86C) * sin_table_lookup(F(s32, 0x85C));
            F(f32, 0x40) = F(f32, 0x86C) * cos_table_lookup(F(s32, 0x85C));
            F(f32, 0x86C) -= 0.0010681152f * (f32)a;
            if (F(f32, 0x86C) < 5.0f) {
                F(s32, 0x84C) = 2;
            }
            ((void (*)(u8 *))TBoss8Dragon__sub_802FB300)(((u8 *)this));
            F(s32, 0x850)++;
            if (F(s32, 0x850) > 10) {
                this->spawn_effect();
                F(s32, 0x850) = 0;
            }
            spawn_trap__12TBoss8DragonFii((s32)((u8 *)this), 0x4003AD11);
            return;
        case 2:
            break;
        }
        break;
    case 5:
        VO->m90();
        VO->m91();
        break;
    }
}

#undef VO
#define VO ((VObj_18_2719b2x *)this)
#define G(o) (*(const f32 *)(TBoss8Dragon__data_804744A8 + (o)))
void TBoss8Dragon::handle_leap_state(s32 arg1) {
    extern const u8 TBoss8Dragon__data_804744A8[];
    f32 *d = &m_878;
    f32 v;

    switch (arg1) {
    case 4:
        F(s16, 0xB8) = 0x18;
        ((TObjMotion *)this)->advance_animation();
        VO->m94();
        this->set_action_state();
        this->reset_action();
        F(s32, 0x3C0) |= 0x30;
        F(s32, 0x3C0) &= ~7;
        F(s32, 0x84C) = 0;
        F(s32, 0x850) = 0;
        break;
    case 2:
    case 11:
        if (F(s32, 0x84C) == 6) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x1A);
        }
        break;
    case 9:
        if (F(s32, 0x84C) == 6) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 8);
        }
        break;
    case 6:
        if (TBoss8Dragon__sub_802FC580((Obj_802FC580 *)this, &m_394) == 0) {
            F(f32, 0x394) = 0.0f;
            F(f32, 0x398) = F(f32, 0x3C);
            F(f32, 0x39C) = 0.0f;
            ((TObjEneDD *)this)->update_velocity();
        }
        this->save_position();
        break;
    case 0:
        switch (F(s32, 0x84C)) {
        case 0:
            F(s32, 0x850)++;
            if ((f32)F(s32, 0x850) >= 100.0f) {
                F(s32, 0x84C) = 1;
                F(s32, 0x3C0) |= 1;
                d[0] = G(0) - F(f32, 0x38);
                d[1] = 0.0f;
                d[2] = G(8) - F(f32, 0x40);
                v = normalize_vector_xz__FP3Vec(d);
                if (v > 110.0f) {
                    v = 110.0f;
                }
                if (v <= 100.0f) {
                    F(f32, 0x864) = 0.0f;
                    F(s32, 0x5C) = 0;
                } else {
                    f32 k = 37.333336f;
                    k += newton_sqrtf(298.6667f);
                    F(f32, 0x864) = v / k;
                    F(s32, 0x5C) = (s32)(TBoss8Dragon__data_80474B28 * atan2_float(F(f32, 0x864), 15.0f));
                }
                F(s32, 0x60) = (s32)(TBoss8Dragon__data_80474B28 * atan2_float(d[0], d[2]));
                F(f32, 0x868) = 15.0f;
                d[0] *= F(f32, 0x864);
                d[2] *= F(f32, 0x864);
                f32 step = -11.333333f;
                F(f32, 0x38) = d[0] * step + F(f32, 0x38);
                F(f32, 0x40) = d[2] * step + F(f32, 0x40);
                F(f32, 0x3C) = -170.0f;
            }
            break;
        case 1:
            if (F(f32, 0x3C) > G(4)) {
                F(s32, 0x84C) = 2;
                VO->m90();
                VO->m91();
                this->set_state();
                TBoss8Dragon::init_state((s32)((u8 *)this));
                fill_value_array(F(s32, 0x680));
                create_boss8_piller_ctrl((s32)((u8 *)&m_38), (s32)(((s32 (*)(void *))get_entity_id)(((u8 *)this))), 100.0f);
                spawn_effect__12TBoss8DragonFii((s32)((u8 *)this), 0x4003AD0F);
            }
            break;
        case 2:
            if (F(f32, 0x3C) > 110.0f) {
                F(s32, 0x84C) = 3;
            }
            break;
        case 3:
            if (F(f32, 0x868) < 0.0f && F(f32, 0x3C) < 220.0f) {
                F(s32, 0x84C) = 4;
                F(f32, 0x86C) = F(f32, 0x868) * F(f32, 0x868) / 80.0f;
            }
            break;
        case 4:
            if (F(f32, 0x868) > 0.0f) {
                F(s32, 0x84C) = 5;
                F(f32, 0x868) = 0.0f;
                F(s32, 0x850) = 0;
            }
            break;
        }
        switch (F(s32, 0x84C)) {
        case 1:
            vec3_add_to((u8 *)&m_38, d);
            F(f32, 0x3C) += F(f32, 0x868);
            break;
        case 2:
            vec3_add_to((u8 *)&m_38, d);
            F(f32, 0x868) += -0.4017857f;
            F(f32, 0x3C) += F(f32, 0x868);
            break;
        case 3:
            ((TObjMotion *)this)->advance_animation();
            F(f32, 0x868) += -0.4017857f;
            if (F(f32, 0xC0) >= 15.0f) {
                d[0] *= 0.98f;
                d[2] *= 0.98f;
            }
            vec3_add_to((u8 *)&m_38, d);
            F(f32, 0x3C) += F(f32, 0x868);
            F(s32, 0x5C) = approach_angle_limited(F(s32, 0x5C), 0, 0x80);
            break;
        case 4:
            ((TObjMotion *)this)->advance_animation();
            if (F(s16, 0xB8) == 0x10) {
                spawn_effect_if_in_band__12TBoss8DragonFi((s32)((u8 *)this));
            }
            F(f32, 0x868) += F(f32, 0x86C);
            F(f32, 0x3C) += F(f32, 0x868);
            d[0] *= 0.98f;
            d[2] *= 0.98f;
            vec3_add_to((u8 *)&m_38, d);
            break;
        case 5:
            ((TObjMotion *)this)->advance_animation();
            spawn_effect_if_in_band__12TBoss8DragonFi((s32)((u8 *)this));
            F(s32, 0x850)++;
            if (F(s32, 0x850) >= 50) {
                F(s32, 0x84C) = 6;
            }
            break;
        }
        break;
    case 5:
        F(s32, 0x5C) = 0;
        break;
    }
}

}
#pragma pop
#undef F
#undef VO
#undef G
extern "C" {
void TBoss8Dragon::sub_802F6838(s32 arg1) {
    CameraPlayback cam;
    Rot_802F6838 r;
    Vec_802F6838 v;

    switch (arg1) {
    case 4: {
        *(s16 *)((s8 *)this + 0xB8) = 0x13;
        ((VObj_18_81e212 *)(((u8 *)this)))->m93();
        this->reset_timer();
        this->set_active_flag();
        *(s32 *)((s8 *)this + 0x3C0) |= 0x36;
        *(s32 *)((s8 *)this + 0x84C) = 0;
        *(s32 *)((s8 *)this + 0x850) = 0;
        *(f32 *)((s8 *)this + 0x864) = 0.0f;
        *(void **)((s8 *)this + 0x894) = 0;
        play_cue_stream_file((s32)lbl_80474B30);
        TWindowCtrl::init_all_slots();
        cam.bank = 2;
        cam.index = 0;
        cam.flags = 0;
        cam.frame = 0.0f;
        cam.frame_step = 0.5f;
        activate_camera_mode(5, 0.0f);
        cam.cache_target_and_forward(0x31C7);
        set_scripted_camera_pose((u8 *)&m_38, (u8 *)&m_38, (u8 *)&m_5c);
        break;
    }
    case 2:
    case 11:
        if (*(s32 *)((s8 *)this + 0x850) >= 50) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x17);
        }
        break;
    case 9:
        if (*(s32 *)((s8 *)this + 0x850) >= 50) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x17);
        }
        break;
    case 8:
        TBoss8Dragon::update_all_parts();
        break;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        switch (*(s32 *)((s8 *)this + 0x84C)) {
        case 0:
            if (((TObjMotion *)this)->is_passing_frame(60.0f) != 0 || ((TObjMotion *)this)->is_passing_frame(98.0f) != 0) {
                play_sound_effect(0x4003AD07, 0, 0, 0);
                start_pad_rumble_all(0xA0, 0xF);
            }
            if (*(f32 *)((s8 *)this + 0xC0) >= 25.0f && *(f32 *)((s8 *)this + 0xC0) < 40.0f) {
                direction_to_rotation_xz((u8 *)&m_41c, &r.x, &r.z);
                if (*(void **)((s8 *)this + 0x894) == 0) {
                    *(void **)((s8 *)this + 0x894) = spawn_particle_effect_with_rotation((u8 *)&m_410, &r, *(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x760)) + 0x1C), 0x40);
                }
                if (*(void **)((s8 *)this + 0x894) != 0) {
                    ((TParticleCtrl *)*(void **)((s8 *)this + 0x894))->set_position((u8 *)&m_428);
                    ((TParticleCtrl *)(*(void **)((s8 *)this + 0x894)))->set_direction(&r);
                }
            } else if (*(void **)((s8 *)this + 0x894) != 0) {
                queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x894));
                *(void **)((s8 *)this + 0x894) = 0;
            }
            if (((TObjMotion *)this)->is_passing_frame(57.0f) != 0) {
                Eff_802FB304 e = *(Eff_802FB304 *)TBoss8Dragon__body_effect_parameters;
                e.f = 12.0f;
                VecCopy__FP3VecPC3Vec(&v, lbl_804744F0);
                rotate_xz_pair_by_angle(&v.x, &v.z, *(s32 *)((s8 *)this + 0x60));
                vec3_add_to(&v, (u8 *)&m_38);
                reset_hp__9TObjEneDDFPUcPUcPUc(((u8 *)this), 0, TBoss8Dragon__data_80541DC8[4], 0);
                ((void (*)(void *, void *, void *, s32))emit_effect__12TBoss8DragonFPv)(((u8 *)this), &v, &e, 0);
                reset_hp__9TObjEneDDFPUcPUcPUc(((u8 *)this), 0, TBoss8Dragon__data_80541DC8[0], 0);
                spawn_particle_effect_with_flags(&v, (void *)*(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x760)) + 8), 0x40);
                if (*(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x760)) + 0xC) != -1) {
                    spawn_particle_effect_with_flags((u8 *)&m_38, (void *)*(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x760)) + 0xC), 0x40);
                }
            }
            if (((TObjMotion *)this)->is_passing_frame(88.0f) != 0) {
                Eff_802FB304 e = *(Eff_802FB304 *)TBoss8Dragon__body_effect_parameters;
                e.f = 25.0f;
                VecCopy__FP3VecPC3Vec(&v, lbl_804744FC);
                rotate_xz_pair_by_angle(&v.x, &v.z, *(s32 *)((s8 *)this + 0x60));
                vec3_add_to(&v, (u8 *)&m_38);
                reset_hp__9TObjEneDDFPUcPUcPUc(((u8 *)this), 0, TBoss8Dragon__data_80541DC8[4], 0);
                ((void (*)(void *, void *, void *, s32))emit_effect__12TBoss8DragonFPv)(((u8 *)this), &v, &e, 0);
                reset_hp__9TObjEneDDFPUcPUcPUc(((u8 *)this), 0, TBoss8Dragon__data_80541DC8[0], 0);
                spawn_particle_effect_with_flags(&v, (void *)*(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x760)) + 8), 0x40);
                if (*(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x760)) + 0xC) != -1) {
                    spawn_particle_effect_with_flags((u8 *)&m_38, (void *)*(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x760)) + 0xC), 0x40);
                }
            }
            if (((TObjMotion *)this)->is_passing_frame(97.0f) != 0) {
                this->emit_body_effects();
            }
            if (((TObjEneDD *)this)->get_flag_b4() != 0) {
                *(s32 *)((s8 *)this + 0x84C) = 1;
                *(s32 *)((s8 *)this + 0x850) = 0;
            }
            break;
        case 1:
            (*(s32 *)((s8 *)this + 0x850))++;
            if (*(s32 *)((s8 *)this + 0x850) >= 50) {
                TWindowCtrl::init_all_slots2();
                restore_player_cameras();
            }
            break;
        }
        break;
    case 5:
        refresh_and_send_entity_flags__9TObjEnemyFv();
        TBoss4DarkFalz::dispatch_by_main_phase(0x4F);
        *(s32 *)((s8 *)this + 0x30) = 0x12008;
        ((VObj_18_81e212 *)(((u8 *)this)))->m72(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        if (*(void **)((s8 *)this + 0x894) != 0) {
            queue_destruction__7TObjectFv(*(void **)((s8 *)this + 0x894));
            *(void **)((s8 *)this + 0x894) = 0;
        }
        if (*(s32 *)((s8 *)this + 0x74C) != 0) {
            release_grabbed_player__12TBoss8DragonFPv(this);
        }
        break;
    }
}

}
#pragma push
#pragma fp_contract on
extern "C" {
void TBoss8Dragon::sub_802F6708(s32 arg1) {
    f32 temp_f1;
    f32 temp_f4;

    switch (arg1) {
    case 4:
        ((VObj_18_599a64 *)(((u8 *)this)))->m93();
        this->reset_timer();
        this->set_active_flag();
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) | 0xB6);
        *(s32 *)((s8 *)this + 0x84C) = 0;
        break;
    case 2:
    case 11:
        if ((s32) *(s32 *)((s8 *)this + 0x84C) >= 6) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x17);
        }
        break;
    case 9:
        if ((s32) *(s32 *)((s8 *)this + 0x84C) >= 6) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x17);
        }
        break;
    case 0:
        temp_f4 = (f32) *(s32 *)((s8 *)this + 0x84C) / 6.0f;
        temp_f1 = 2.0f * (1.0f - temp_f4);
        *(f32 *)((s8 *)this + 0x68) = temp_f1;
        *(f32 *)((s8 *)this + 0x6C) = (f32) (2.0f * ((3.0f * temp_f4) + 1.0f));
        *(f32 *)((s8 *)this + 0x70) = temp_f1;
        *(s32 *)((s8 *)this + 0x84C) = (s32) (*(s32 *)((s8 *)this + 0x84C) + 1);
        break;
    case 5:
        if ((s32) *(s32 *)((s8 *)this + 0x74C) != 0) {
            ((void (*)(void))release_grabbed_player__12TBoss8DragonFPv)();
        }
        queue_destruction__7TObjectFv(((u8 *)this));
        break;
    }
}

}
#pragma pop
extern "C" {
void TBoss8Dragon::sub_802F6618(s32 event) {
    s32 i;
    switch (event) {
    case 4:
        this->m_b8 = 0x13;
        ((VObj_18_599a64 *)this)->m93();
        this->reset_timer();
        this->set_active_flag();
        this->m_3c0 |= 0x136;
        for (i = 0; i < 4; i++) {
            ((TBoss8Dragon *)&this->renderFadeStates[i])->set_speed(0.005f);
        }
        break;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        for (i = 0; i < 4; i++) {
            if (((VObj_14_df5984 *)&this->renderFadeStates[i])->m4() != 0) {
                queue_destruction__7TObjectFv(this);
                return;
            }
        }
        break;
    case 2:
    case 11:
        break;
    }
}

void TBoss8Dragon::sub_802F645C(s32 arg1) {
    u8 *temp_r4;
    u8 *temp_r4_2;
    u8 *temp_r4_3;
    switch (arg1) {
    case 4:
        this->m_b8 = 0;
        ((VObj_18_444bc5 *)(((u8 *)this)))->m94();
        this->reset_timer();
        this->set_active_flag();
        this->m_3c0 = (s32) (this->m_3c0 & ~0x36);
        return;
    case 11:
        temp_r4 = (u8 *)(*(u8 **)((s8 *)this + 0x6D8));
        if (*(f32 *)((s8 *)temp_r4 + 0x24) > 0.1f) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0x19);
            return;
        }
        if (((s32 (*)(void *, void *, int))mask_flags__12TBoss8DragonFiii)(((u8 *)this), (void *) (*(u8 **)((s8 *)temp_r4 + 8)), 4) != 0) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 3);
            return;
        }
        if (((s32 (*)(void *, void *, int))mask_flags__12TBoss8DragonFiii)(((u8 *)this), (void *) (*(void **)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8)), 2) != 0) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 4);
            return;
        }
        if (((s32 (*)(void *))TBoss8Dragon__sub_802FABB4)(((u8 *)this)) != 0) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 5);
            return;
        }
        if (((s32 (*)(void *, void *, int))mask_flags__12TBoss8DragonFiii)(((u8 *)this), (void *) (*(void **)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8)), (int) (fn_8002AE08(TBoss8Dragon__data_805D69BC))) != 0) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 9);
        }
        return;
    case 2:
        temp_r4_2 = (u8 *)(*(u8 **)((s8 *)this + 0x6D8));
        if (*(f32 *)((s8 *)temp_r4_2 + 0x24) > 0.1f) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0x19);
            return;
        }
        temp_r4_3 = (u8 *)(*(u8 **)((s8 *)temp_r4_2 + 8));
        if ((s32) temp_r4_3 & 4) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 3);
            return;
        }
        if ((s32) temp_r4_3 & 2) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 4);
            return;
        }
        if ((s32) temp_r4_3 & 0x400) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 5);
            return;
        }
        break;
    case 7:
        ((s32 (*)(void))restore_target_pos__12TBoss8DragonFPv)();
        return;
    case 6:
        ((s32 (*)(void))copy_pos_to_field688__12TBoss8DragonFPv)();
        return;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        break;
    }
}

void TBoss8Dragon::sub_802F610C(s32 arg1) {
    s32 *p = (s32 *)((u8 *)this + 0x85C);
    u8 *q;
    f32 s;
    f32 c;
    f32 scale;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 1;
        ((VObj_18_444bc5 *)(((u8 *)this)))->m94();
        this->reset_timer();
        this->set_active_flag();
        *(s32 *)((s8 *)this + 0x3C0) &= ~0x36;
        *(s32 *)((s8 *)this + 0x84C) = 0;
        *(s32 *)((s8 *)this + 0x850) = 0;
        return;
    case 2:
        if (*(s32 *)((s8 *)this + 0x850) == 1) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x18);
            return;
        }
        q = *(u8 **)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8);
        if ((s32)q & 4) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 3);
            return;
        }
        if ((s32)q & 2) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 4);
            return;
        }
        if ((s32)q & 0x400) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 5);
            return;
        }
        break;
    case 11:
        if (*(s32 *)((s8 *)this + 0x850) == 1) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x18);
            return;
        }
        if (((s32 (*)(void *, void *, int))mask_flags__12TBoss8DragonFiii)(((u8 *)this), *(void **)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8), 4) != 0) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 3);
            return;
        }
        if (((s32 (*)(void *, void *, int))mask_flags__12TBoss8DragonFiii)(((u8 *)this), *(void **)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8), 2) != 0) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 4);
            return;
        }
        if (((s32 (*)(void *))TBoss8Dragon__sub_802FABB4)(((u8 *)this)) != 0) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 5);
            return;
        }
        if (((s32 (*)(void *, void *, int))mask_flags__12TBoss8DragonFiii)(((u8 *)this), *(void **)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8), fn_8002AE08(TBoss8Dragon__data_805D69BC)) != 0) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 9);
            return;
        }
        break;
    case 8:
        (*(s32 *)((s8 *)this + 0x84C))++;
        if (*(s32 *)((s8 *)this + 0x84C) >= 0x1E) {
            *(s32 *)((s8 *)this + 0x84C) = 0;
            q = *(u8 **)((s8 *)this + 0x6D8);
            if (*(f32 *)((s8 *)q + 0x24) <= 0.1f) {
                *(s32 *)((s8 *)this + 0x850) = 1;
                return;
            }
            *p = *(s32 *)((s8 *)q + 0x1C);
            this->set_speed(*p);
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        TBoss8Dragon__sub_802FBBC8(((u8 *)this), p);
        return;
    case 6:
        this->set_speed(*(s32 *)((s8 *)this + 0x60));
        return;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        if (*(s16 *)((s8 *)this + 0xB8) == 1) {
            this->play_sound_if_in_band();
        }
        if (((TObjMotion *)this)->is_passing_frame(24.0f) != 0) {
            TBoss8Dragon::check_condition_default(((u8 *)this));
        } else if (((TObjMotion *)this)->is_passing_frame(3.0f) != 0) {
            TBoss8Dragon::set_state_1(((u8 *)this));
        }
        *(f32 *)((s8 *)this + 0xC8) = 0.48000002f;
        scale = 0.8f;
        if (*(f32 *)((s8 *)this + 0xC0) > 4.0f && *(f32 *)((s8 *)this + 0xC0) < 9.0f) {
            return;
        }
        if (*(f32 *)((s8 *)this + 0xC0) > 24.0f && *(f32 *)((s8 *)this + 0xC0) < 30.0f) {
            return;
        }
        *(s32 *)((s8 *)this + 0x60) = approach_angle_limited(*(s32 *)((s8 *)this + 0x60), *p, 0x200);
        s = sin_table_lookup(*(s32 *)((s8 *)this + 0x60));
        c = cos_table_lookup(*(s32 *)((s8 *)this + 0x60));
        if (*(s32 *)((s8 *)this + 0x74C) != 0) {
            scale = this->clamp_step_in_radius(s, c, 0.8f);
        }
        ((TObjEneDD *)this)->move_to_shot_position(s, c, scale);
        break;
    }
}

void TBoss8Dragon::sub_802F5F64(s32 arg1) {
    u8 *temp_r3;
    u8 *temp_r4;
    u8 *temp_r4_2;
    switch (arg1) {
    case 4:
        this->m_b8 = 0x10;
        ((VObj_18_444bc5 *)(((u8 *)this)))->m94();
        this->set_state();
        this->activate_attack();
        this->m_3c0 = (s32) (this->m_3c0 & ~0x36);
        return;
    case 11:
        if (((s32) this->m_754 > 0x1C2) || (((s32 (*)(void *, void *, int))mask_flags__12TBoss8DragonFiii)(((u8 *)this), (void *) (*(void **)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8)), 2) != 0)) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 8);
            return;
        }
        temp_r3 = (u8 *)(*(u8 **)((s8 *)this + 0x6D8));
        if (*(f32 *)((s8 *)temp_r3 + 0x24) > 0.1f) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0x1B);
            return;
        }
        if (((s32 (*)(void *, void *, int))mask_flags__12TBoss8DragonFiii)(((u8 *)this), (void *) (*(u8 **)((s8 *)temp_r3 + 8)), 4) != 0) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 7);
            return;
        }
        if (((s32 (*)(void *))check_attack_ready__12TBoss8DragonFPv)(((u8 *)this)) != 0) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0xF);
        }
        return;
    case 2:
        temp_r4 = (u8 *)(*(u8 **)((s8 *)this + 0x6D8));
        if (*(f32 *)((s8 *)temp_r4 + 0x24) > 0.1f) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0x1B);
            return;
        }
        temp_r4_2 = (u8 *)(*(u8 **)((s8 *)temp_r4 + 8));
        if ((s32) temp_r4_2 & 4) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 7);
            return;
        }
        if ((s32) temp_r4_2 & 2) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0xF);
            return;
        }
        if ((s32) temp_r4_2 & 0x400) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 8);
            return;
        }
        break;
    case 7:
        ((s32 (*)(void))restore_target_pos__12TBoss8DragonFPv)();
        return;
    case 6:
        ((s32 (*)(void))copy_pos_to_field688__12TBoss8DragonFPv)();
        return;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        ((s32 (*)(void *))spawn_effect_if_in_band__12TBoss8DragonFi)(((u8 *)this));
        ((s32 (*)(void *))TBoss8Dragon__sub_802FB09C)(((u8 *)this));
        break;
    }
}

void TBoss8Dragon::sub_802F5CC8(s32 arg1) {
    s32 *p = (s32 *)((u8 *)this + 0x85C);
    u8 *q;
    f32 s;
    f32 c;
    f32 scale;

    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 0x10;
        ((VObj_18_444bc5 *)(((u8 *)this)))->m94();
        this->set_state();
        this->activate_attack();
        *(s32 *)((s8 *)this + 0x3C0) &= ~0x36;
        *(s32 *)((s8 *)this + 0x84C) = 0x64;
        *(s32 *)((s8 *)this + 0x850) = 0;
        return;
    case 11:
        if (*(s32 *)((s8 *)this + 0x754) > 0x1C2 || ((s32 (*)(void *, void *, int))mask_flags__12TBoss8DragonFiii)(((u8 *)this), *(void **)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8), 2) != 0) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 8);
            return;
        }
        if (*(s32 *)((s8 *)this + 0x850) == 1) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x1A);
            return;
        }
        if (((s32 (*)(void *, void *, int))mask_flags__12TBoss8DragonFiii)(((u8 *)this), *(void **)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8), 4) != 0) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 7);
            return;
        }
        if (((s32 (*)(void *))check_attack_ready__12TBoss8DragonFPv)(((u8 *)this)) != 0) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0xF);
        }
        return;
    case 2:
        if (*(s32 *)((s8 *)this + 0x850) == 1) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x1A);
            return;
        }
        q = *(u8 **)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8);
        if ((s32)q & 4) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 7);
            return;
        }
        if ((s32)q & 2) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0xF);
            return;
        }
        if ((s32)q & 0x400) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 8);
            return;
        }
        break;
    case 8:
        (*(s32 *)((s8 *)this + 0x84C))++;
        if (*(s32 *)((s8 *)this + 0x84C) >= 0x1E) {
            *(s32 *)((s8 *)this + 0x84C) = 0;
            q = *(u8 **)((s8 *)this + 0x6D8);
            if (*(f32 *)((s8 *)q + 0x24) <= 0.1f) {
                *(s32 *)((s8 *)this + 0x850) = 1;
                return;
            }
            *p = *(s32 *)((s8 *)q + 0x1C);
            this->set_speed(*p);
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        TBoss8Dragon__sub_802FBBC8(((u8 *)this), p);
        return;
    case 6:
        this->set_speed(*p);
        return;
    case 0:
        ((TObjMotion *)this)->advance_animation();
        ((s32 (*)(void *))spawn_effect_if_in_band__12TBoss8DragonFi)(((u8 *)this));
        ((s32 (*)(void *))TBoss8Dragon__sub_802FB09C)(((u8 *)this));
        *(s32 *)((s8 *)this + 0x60) = approach_angle_limited(*(s32 *)((s8 *)this + 0x60), *p, 0x200);
        s = sin_table_lookup(*(s32 *)((s8 *)this + 0x60));
        c = cos_table_lookup(*(s32 *)((s8 *)this + 0x60));
        scale = 2.0f;
        if (*(s32 *)((s8 *)this + 0x74C) != 0) {
            scale = this->clamp_step_in_radius(s, c, scale);
        }
        ((TObjEneDD *)this)->move_with_wall_stop(s, c, scale);
        break;
    }
}

void TBoss8Dragon::sub_802F5BA0(s32 arg1) {
    u8 *temp_r3;
    switch (arg1) {
    case 4:
        ((VObj_18_2fe63c *)this)->m94();
        this->set_action_state();
        this->reset_action();
        this->m_3c0 = (s32) (this->m_3c0 | 0x30);
        this->m_3c0 = (s32) (this->m_3c0 & 0xFFFFFFF8);
        ((VObj_18_2fe63c *)this)->m89();
        ((VObj_18_2fe63c *)this)->m92();
        this->m_84c = 0;
        break;
    case 2:
    case 11:
        temp_r3 = (u8 *)(*(u8 **)((s8 *)this + 0x6D8));
        if (*(f32 *)((s8 *)temp_r3 + 0x24) > 0.1f) {
            send_action_packet__12TBoss8DragonFPvi((u8 *)this, 0x1D);
            break;
        }
        if (*(s32 *)((s8 *)temp_r3 + 8) & 2) {
            send_action_packet__12TBoss8DragonFPvi((u8 *)this, 0x13);
            break;
        }
    default:
        break;
    case 7:
        ((s32)restore_target_pos__12TBoss8DragonFPv(this));
        break;
    case 6:
        ((s32)copy_pos_to_field688__12TBoss8DragonFPv(this));
        break;
    case 0:
        this->m_84c = (this->m_84c + 1);
        if ((s32) this->m_84c > 0xA) {
            this->spawn_effect();
            this->m_84c = 0;
        }
        break;
    }
}

}
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
extern "C" {
void TBoss8Dragon::handle_walk_state(s32 arg1) {
    extern const u8 TBoss8Dragon__data_804744A8[];
    f32 temp_f1;
    f32 temp_f31;
    f32 temp_f31_2;
    u8 *temp_r30;
    u8 *temp_r4;

    temp_r30 = ((u8 *)this + 0x878);
    switch (arg1) {
    case 4:
        this->m_b8 = 0x11;
        ((VObj_18_2fe63c *)(((u8 *)this)))->m94();
        this->set_action_state();
        this->reset_action();
        this->m_3c0 = (s32) (this->m_3c0 | 0x30);
        this->m_3c0 = (s32) (this->m_3c0 & 0xFFFFFFF8);
        ((VObj_18_2fe63c *)(((u8 *)this)))->m89();
        ((VObj_18_2fe63c *)(((u8 *)this)))->m92();
        VecCopy__FP3VecPC3Vec(temp_r30, ((u8 *)this) + 0x38);
        this->m_84c = 0x64;
        this->m_850 = 0;
        *(f32 *)((s8 *)temp_r30 + 4) = *(const f32 *)((s8 *)TBoss8Dragon__data_804744A8 + 4);
        *(f32 *)((s8 *)this + 0x864) = 0.0f;
        this->m_868 = 0.0f;
        return;
    case 2:
    case 11:
        if ((s32) this->m_850 == 1) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x1C);
            return;
        }
        if (*(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8) & 2) {
            send_action_packet__12TBoss8DragonFPvi(((u8 *)this), 0x13);
        }
        return;
    case 8:
        this->m_84c = (s32) (this->m_84c + 1);
        if ((s32) this->m_84c >= 0x1E) {
            this->m_84c = 0;
            temp_r4 = (u8 *)(*(u8 **)((s8 *)this + 0x6D8));
            if (*(f32 *)((s8 *)temp_r4 + 0x24) <= 0.1f) {
                this->m_850 = 1;
                return;
            }
            this->m_60 = (s32) *(s32 *)((s8 *)temp_r4 + 0x1C);
            this->set_speed(this->m_60);
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        TBoss8Dragon__sub_802FBBC8(((u8 *)this), (s32 *)((u8 *)this + 0x60));
        return;
    case 6:
        this->set_speed(this->m_60);
        return;
    case 0:
        temp_f31 = sin_table_lookup((int) (this->m_60));
        temp_f1 = cos_table_lookup((int) (this->m_60));
        f32 speed = 4.0f;
        *(f32 *)((s8 *)this + 0x38) = (f32) ((temp_f31 * speed) + *(f32 *)((s8 *)this + 0x38));
        this->m_40 = (f32) ((temp_f1 * speed) + this->m_40);
        temp_f31_2 = newton_sqrtf(horizontal_distance_squared((u8 *)this + 0x38, temp_r30));
        VecCopy__FP3VecPC3Vec(temp_r30, ((u8 *)this) + 0x38);
        *(f32 *)((s8 *)this + 0x864) = (f32) (*(f32 *)((s8 *)this + 0x864) + temp_f31_2);
        break;
    }
}

}
#pragma pop
extern "C" {
void TBoss8Dragon::sub_802F57E4(s32 arg1) {
    s32 temp_r4;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 0x11;
        ((VObj_18_2fe63c *)(((u8 *)this)))->m94();
        this->set_action_state();
        this->reset_action();
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) | 0x30);
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) & 0xFFFFFFF8);
        ((VObj_18_2fe63c *)(((u8 *)this)))->m89();
        ((VObj_18_2fe63c *)(((u8 *)this)))->m92();
        this->calc_velocity_from_angle();
        return;
    case 2:
    case 11:
        if (((s32) *(s32 *)((s8 *)this + 0x84C) >= 0x1C2) || (((s32 (*)(void *, void *, int))mask_flags__12TBoss8DragonFiii)(((u8 *)this), (void *) (*(s32 *)((s8 *)(*(u8 **)((s8 *)this + 0x6D8)) + 8)), 0x400) != 0)) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0x26);
        }
        return;
    case 7:
        *(s32 *)((s8 *)this + 0x758) = (s32) *(f32 *)((s8 *)this + 0x690);
        if (*(f32 *)((s8 *)this + 0x694) > 0.0f) {
            *(s32 *)((s8 *)this + 0x85C) = 0x180;
            return;
        }
        *(s32 *)((s8 *)this + 0x85C) = -0x180;
        return;
    case 6:
        *(f32 *)((s8 *)this + 0x688) = (f32) (65536.0f * random_ratio__9TObjCharaFv());
        *(f32 *)((s8 *)this + 0x68C) = calc_elapsed_scaled__9TObjEneDDFv(((u8 *)this));
        return;
    case 0:
        *(s32 *)((s8 *)this + 0x758) = (s32) (*(s32 *)((s8 *)this + 0x758) + *(s32 *)((s8 *)this + 0x85C));
        if ((s32) *(s32 *)((s8 *)this + 0x85C) >= 0) {
            *(s32 *)((s8 *)this + 0x60) = (s32) (*(s32 *)((s8 *)this + 0x758) + 0x9800);
        } else {
            *(s32 *)((s8 *)this + 0x60) = (s32) (*(s32 *)((s8 *)this + 0x758) + 0xFFFF6800);
        }
        this->calc_velocity_from_angle();
        temp_r4 = *(s32 *)((s8 *)this + 0x84C);
        *(s32 *)((s8 *)this + 0x84C) = (temp_r4 + 1);
        ((s32 (*)(void *, int))TBoss8Dragon__sub_802FB300)(((u8 *)this), temp_r4);
        break;
    }
}

}
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
extern "C" {
void TBoss8Dragon::sub_802F5644(s32 arg1) {
    f32 temp_f1;
    f32 temp_f2;
    switch (arg1) {
    case 4:
        this->m_b8 = 0x11;
        ((VObj_18_2fe63c *)(((u8 *)this)))->m94();
        this->set_action_state();
        this->reset_action();
        this->m_3c0 = (s32) (this->m_3c0 | 0x30);
        this->m_3c0 = (s32) (this->m_3c0 & 0xFFFFFFF8);
        ((VObj_18_2fe63c *)(((u8 *)this)))->m89();
        ((VObj_18_2fe63c *)(((u8 *)this)))->m92();
        *(f32 *)((s8 *)this + 0x864) = 0.0f;
        *(f32 *)((s8 *)this + 0x3A0) = (f32) -*(f32 *)((s8 *)this + 0x38);
        this->m_3a4 = 0.0f;
        this->m_3a8 = (f32) -this->m_40;
        normalize_vector_xz__FP3Vec((u8 *)this + 0x3A0);
        this->m_60 = (s32) (TBoss8Dragon__data_80474B28 * atan2_float((f32) (*(f32 *)((s8 *)this + 0x3A0)), (f32) (this->m_3a8)));
        return;
    case 2:
    case 11:
        if (this->m_868 >= 680.0f) {
            ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0x13);
        }
        return;
    case 7:
        ((s32 (*)(void))restore_target_pos__12TBoss8DragonFPv)();
        return;
    case 6:
        ((s32 (*)(void))copy_pos_to_field688__12TBoss8DragonFPv)();
        return;
    case 0:
        *(f32 *)((s8 *)this + 0x864) += 0.1f;
        if (*(f32 *)((s8 *)this + 0x864) > 12.0f) {
            *(f32 *)((s8 *)this + 0x864) = 12.0f;
        }
        this->m_868 = (f32) (this->m_868 + *(f32 *)((s8 *)this + 0x864));
        *(f32 *)((s8 *)this + 0x38) = (f32) ((*(f32 *)((s8 *)this + 0x3A0) * *(f32 *)((s8 *)this + 0x864)) + *(f32 *)((s8 *)this + 0x38));
        temp_f2 = this->m_3a8;
        temp_f1 = *(f32 *)((s8 *)this + 0x864);
        this->m_40 = (f32) ((temp_f2 * temp_f1) + this->m_40);
        ((s32 (*)(void *, f32, f32)) TBoss8Dragon__sub_802FB300)(((u8 *)this), temp_f1, temp_f2);
        break;
    }
}

}
#pragma pop
extern "C" {
void TBoss8Dragon::sub_802F5434(s32 arg1) {
    extern u8 TBoss8Dragon__data_804744A8[];
    f32 temp_f1;
    s32 i;
    s32 j;
    switch (arg1) {
    case 4:
        this->m_b8 = 1;
        ((TObjEneEpsilon *)this)->vfunc_96();
        this->reset_timer();
        this->set_active_flag();
        *(s32 *)&this->m_3c0 = (s32) (*(s32 *)&this->m_3c0 & ~0x36);
        for (i = 0; i < 4; i++) {
            ((TBoss8Dragon *)(&((Self_802F5434 *)this)->arr[i]))->set_speed(0.02f);
        }
        *(s32 *)&this->m_3c0 = (*(s32 *)&this->m_3c0 | 0x100);
        *(s32 *)&this->m_84c = 0;
        temp_f1 = *(f32 *)((s8 *)TBoss8Dragon__data_80541DDC[0] + 0x10);
        *(f32 *)((s8 *)this + 0x864) = (f32) (5.0f + TObjBoss2Tunnel::calc_scaled_value((s32) (320.0f * temp_f1), temp_f1));
        return;
    case 2:
    case 11:
        ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(this, 0x18);
        return;
    case 9:
        if (TBoss8Dragon__sub_802F46F4((s32)this) == 0) {
            this->pick_next_action();
        }
        return;
    case 8:
        ((s32 (*)(void))update_linked_position__12TBoss8DragonFv)();
        *(s32 *)&this->m_84c = (s32) (*(s32 *)&this->m_84c + 1);
        if ((s32) (*(s32 *)&this->m_84c % 20) == 0x13) {
            if (enemy_validate_retained_target(this) != 0) {
                ((TObjEneDD_ST *)this)->enemy_copy_target_destination();
            } else {
                ((TObjEneDD *)this)->set_target_destination((const Vec *)TBoss8Dragon__data_804744A8);
            }
            this->save_position();
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        ((s32 (*)(void))sync_target_pos__12TBoss8DragonFPv)();
        return;
    case 6:
        this->m_3b0 = (s32) *(s32 *)((s8 *)this + 0x3B4);
        if (((s32 (*)(void))update_linked_position__12TBoss8DragonFv)() != 0) {
            ((TObjEneDD_ST *)this)->enemy_copy_target_destination();
        } else {
            ((TObjEneDD *)this)->set_target_destination((const Vec *)TBoss8Dragon__data_804744A8);
        }
        this->save_position();
        return;
    case 0:
        ((s32 (*)(void))update_movement__12TBoss8DragonFPv)();
        for (j = 0; j < 4; j++) {
            ((Self_802F5434 *)this)->arr[j].m4();
        }
        return;
    case 5:
        *(s32 *)&this->m_3c0 = (s32) (*(s32 *)&this->m_3c0 & 0xFFFFFEFF);
        break;
    }
}

}
#pragma push
#pragma fp_contract on
extern "C" {
void TBoss8Dragon::sub_802F51DC(s32 arg1) {
    extern u8 TBoss8Dragon__data_804744A8[];
    Vec_802F51DC v;
    f32 temp_f1;
    f32 var_f2;
    s32 i;
    s32 j;
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 1;
        ((VObj_18_444bc5 *)(((u8 *)this)))->m94();
        this->reset_timer();
        this->set_active_flag();
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) & ~0x36);
        TBoss8Dragon__sub_802F48DC(this, (Vec *)((u8 *)this + 0x394));
        for (i = 0; i < 4; i++) {
            ((TBoss8Dragon *)(&((Self_802F51DC *)this)->arr[i]))->set_speed(0.02f);
        }
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) | 0x100);
        temp_f1 = *(f32 *)((s8 *)TBoss8Dragon__data_80541DDC[0] + 0x10);
        *(f32 *)((s8 *)this + 0x864) = (f32) (5.0f + TObjBoss2Tunnel::calc_scaled_value((s32) (320.0f * temp_f1), temp_f1));
        ((s32 (*)(void *, int))spawn_effect__12TBoss8DragonFii)(((u8 *)this), 0x4003A315);
        return;
    case 2:
    case 11:
        ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0x18);
        return;
    case 9:
        if (this->hasActiveRenderFade() == 0) {
            this->pick_next_action();
        }
        return;
    case 7:
        ((s32 (*)(void))sync_target_pos__12TBoss8DragonFPv)();
        return;
    case 6:
        *(s32 *)((s8 *)this + 0x3B0) = (s32) *(s32 *)((s8 *)this + 0x3B4);
        if (((s32 (*)(void))update_linked_position__12TBoss8DragonFv)() != 0) {
            ((TObjEneDD_ST *)this)->enemy_copy_target_destination();
        } else {
            ((TObjEneDD *)this)->set_target_destination((const Vec *)TBoss8Dragon__data_804744A8);
        }
        v.x = *(f32 *)((s8 *)this + 0x394) - *(f32 *)((s8 *)this + 0x38);
        v.z = *(f32 *)((s8 *)this + 0x39C) - *(f32 *)((s8 *)this + 0x40);
        if ((s32) ((u16) ((s32) (TBoss8Dragon__data_80474B28 * atan2_float(v.x, v.z)) - *(s32 *)((s8 *)this + 0x60)) + 0x2000) > 0x4000) {
            v.x = ((f32 (*)(int))sin_table_lookup)(*(s32 *)((s8 *)this + 0x60));
            v.z = ((f32 (*)(int))cos_table_lookup)(*(s32 *)((s8 *)this + 0x60));
            var_f2 = 120.0f;
        } else {
            var_f2 = normalize_vector_xz__FP3Vec(&v);
            var_f2 *= 0.5f;
        }
        *(f32 *)((s8 *)this + 0x394) = (f32) ((v.x * var_f2) + *(f32 *)((s8 *)this + 0x38));
        *(f32 *)((s8 *)this + 0x39C) = (f32) ((v.z * var_f2) + *(f32 *)((s8 *)this + 0x40));
        this->save_position();
        return;
    case 0:
        ((s32 (*)(void))update_movement__12TBoss8DragonFPv)();
        for (j = 0; j < 4; j++) {
            ((Self_802F51DC *)this)->arr[j].m5();
        }
        return;
    case 5:
        *(s32 *)((s8 *)this + 0x3C0) = (s32) (*(s32 *)((s8 *)this + 0x3C0) & 0xFFFFFEFF);
        break;
    }
}

}
#pragma pop
extern "C" {
void TBoss8Dragon::update_wander_state(s32 arg1) {
    switch (arg1) {
    case 4:
        *(s16 *)((s8 *)this + 0xB8) = 0xB;
        *(s32 *)((s8 *)this + 0x84C) = 0;
        return;
    case 0:
        *(s32 *)((s8 *)this + 0x84C) = (s32) (*(s32 *)((s8 *)this + 0x84C) + 1);
        if ((s32) *(s32 *)((s8 *)this + 0x84C) > 0x5A) {
            *(s32 *)((s8 *)this + 0x84C) = 0;
            *(s16 *)((s8 *)this + 0xB8) = (s16) (*(s16 *)((s8 *)this + 0xB8) + 1);
            if ((s16) *(s16 *)((s8 *)this + 0xB8) >= 0x1C) {
                *(s16 *)((s8 *)this + 0xB8) = 0;
            }
        }
        ((TObjMotion *)this)->advance_animation();
    case 3:
    case 5:
    case 1:
        return;
    }
}

}
#pragma push
#pragma opt_common_subs off
#define o ((Drg_802F4DD4 *)this)
extern "C" {
void TBoss8Dragon::sub_802F4DD4(s32 arg1) {
    s32 *flag = &o->f858;

    switch (arg1) {
    case 4: {
        void *p;
        o->fB8 = 0;
        ((TBoss8Dragon *)o)->reset_timer();
        ((TObjMotion *)o)->advance_animation();
        o->demo = 0;
        o->phase = 0;
        o->step = 0;
        o->f850 = 0;
        *flag = 1;
        p = __nw__7TObjectFUl(0x28);
        if (p != 0) {
            __ct__16TBoss8DragonDemoFv((u8 *)p, (s32)tl_01, (s32)flag, 0.5f);
        }
        o->fB8 = 0x1A;
        TWindowCtrl::init_all_slots();
        ((TObjEneDD *)o)->get_target_state_b();
        ((TMainCursor *)o)->update_pair();
        break;
    }
    case 2:
    case 9:
        if (o->phase == 1) {
            send_action_packet__12TBoss8DragonFPvi((u8 *)o, 0);
        }
        break;
    case 0:
        switch (o->phase) {
        case 0: {
            s32 step;
            ((TObjMotion *)o)->advance_animation();
            if (((TObjEneDD *)o)->get_flag_b4() != 0) {
                o->phase = 1;
                TWindowCtrl::init_all_slots2();
                o->fB8 = 0;
            }
            switch (step = o->step) {
            case 0:
                if (((TObjMotion *)o)->is_passing_frame(2.0f) != 0) {
                    play_sound_effect(0x4003A804, 0, 0, 0);
                    o->step++;
                }
                break;
            case 1:
                if (((TObjMotion *)o)->is_passing_frame(60.0f) != 0) {
                    play_sound_effect(0x4003AD0E, 0, 0, 0);
                }
                if (((TObjMotion *)o)->is_passing_frame(63.0f) != 0) {
                    Vec_802F4DD4 v;
                    v.x = 0.5f * (o->f458 + o->f470);
                    v.y = 0.0f;
                    v.z = 0.5f * (o->f460 + o->f478);
                    fill_value_array(o->f680);
                    create_boss8_piller_ctrl((s32)&v, (s32)(((s32 (*)(void *))get_entity_id)(o)), 100.0f);
                    spawn_particle_effect_with_flags(&o->pos, (void *)o->info->a, 0x40);
                    if (o->info->b != -1) {
                        spawn_particle_effect_with_flags(&o->pos, (void *)o->info->b, 0x40);
                    }
                    o->step++;
                }
                break;
            case 2:
                if (((TObjMotion *)o)->is_passing_frame(75.0f) != 0) {
                    play_sound_effect(0x4003AD06, 0, 0, 0);
                    o->step++;
                    o->f850 = 0;
                }
                break;
            case 3:
                if (o->fC0 > 80.0f) {
                    o->step = step + 1;
                }
                break;
            case 4:
                if (((TObjMotion *)o)->is_passing_frame(105.0f) != 0) {
                    play_cue_stream_file((s32)lbl_80474B18);
                    o->step++;
                    o->f850 = 0;
                }
                break;
            case 5:
                if (o->fC0 < 150.0f) {
                    s32 rot[3];
                    direction_to_rotation_xz(o->dir41C, &rot[0], &rot[2]);
                } else {
                    o->step = step + 1;
                }
                break;
            }
            break;
        }
        case 1:
            ((TObjMotion *)o)->advance_animation();
            break;
        }
        break;
    case 5:
        if (o->demo != 0) {
            queue_destruction__7TObjectFv(o->demo);
            o->demo = 0;
        }
        ((TMainCursor *)o)->update_cursor_pair();
        *flag = 0;
        TWindowCtrl::init_all_slots2();
        ((TObjEneDD *)o)->get_target_state_a();
        break;
    }
}

}
#pragma pop
#undef o
extern "C" {
void TBoss8Dragon::action(s32 arg1) {
    switch (arg1) {
    case 4:
        ((TObjEneDD *)this)->requested_action = 0;
        *(s32 *)((s8 *)this + 0x84C) = 0;
        *(f32 *)((s8 *)this + 0x3C) = 0.0f;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)this + 0x84C) > 0x96) {
            ((TObjEneDD *)this)->transition_enemy_state(8);
        }
        break;
    case 0:
        if ((get_player_by_client_id(0) != 0U) || (get_player_by_client_id(1) != 0U) || (get_player_by_client_id(2) != 0U) || (get_player_by_client_id(3) != 0U)) {
            *(s32 *)((s8 *)this + 0x84C) = (s32) (*(s32 *)((s8 *)this + 0x84C) + 1);
        }
        break;
    case 5:
    case 1:
        break;
    }
}

void TBoss8Dragon::sub_802F4B90(s32 arg1) {
    s32 *p = (s32 *)((u8 *)this + 0x85C);

    switch (arg1) {
    case 4:
        ((VObj_18_667c9b *)(((u8 *)this)))->m94();
        this->set_action_state();
        this->reset_action();
        *(s32 *)((u8 *)this + 0x3C0) |= 0x30;
        *(s32 *)((u8 *)this + 0x3C0) &= ~7;
        ((VObj_18_667c9b *)(((u8 *)this)))->m89();
        ((VObj_18_667c9b *)(((u8 *)this)))->m92();
        break;
    case 2:
    case 11:
        ((s32 (*)(void *, int))send_action_packet__12TBoss8DragonFPvi)(((u8 *)this), 0x1C);
        break;
    case 9:
        if (TBoss8Dragon::is_any_part_alive() != 0) {
            this->pick_next_action();
        }
        break;
    case 7:
        ((void (*)(void *, void *))TBoss8Dragon__sub_802FBBC8)(((u8 *)this), p);
        break;
    case 6: {
        u32 v = 4294967296.0f * (0.000030517578f * (f32)rand());
        this->set_speed((s32)v);
        break;
    }
    case 5:
        ((TBoss8Dragon *)(*(s32 *)(TBoss8Dragon__data_80541DDC[0] + 0x28)))->place_parts_in_ring(*(s32 *)(TBoss8Dragon__data_80541DDC[0] + 0x24), *p);
        ((VObj_18_667c9b *)(((u8 *)this)))->m90();
        ((VObj_18_667c9b *)(((u8 *)this)))->m91();
        break;
    }
}

void update_movement__12TBoss8DragonFPv(u8 *arg0) {
    Vec_802F4990 old;
    Vec_802F4990 d;
    f32 scale;
    s32 iscale;
    f32 v;
    scale = 0.8f + *(f32 *)((s8 *)TBoss8Dragon__data_80541DDC[0] + 0x10);
    iscale = (s32) (320.0f * scale);
    if (*(s32 *)((s8 *)arg0 + 0xB0) & 4) {
        *(f32 *)((s8 *)arg0 + 0xC8) = 0.125f * scale;
    } else {
        *(f32 *)((s8 *)arg0 + 0xC8) = 0.6f * scale;
    }
    ((TObjMotion *)arg0)->advance_animation();
    ((TBoss8Dragon *)arg0)->play_sound_if_in_band();
    ((TObjEneDD *)arg0)->update_velocity();
    ((s32 (*)(void *))TBoss8Dragon__sub_802FC9D8)(arg0);
    if (((TObjMotion *)arg0)->is_passing_frame(24.0f) != 0) {
        TBoss8Dragon::check_condition_default(arg0);
    } else if (((TObjMotion *)arg0)->is_passing_frame(3.0f) != 0) {
        TBoss8Dragon::set_state_1(arg0);
    }
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&old, arg0 + 0x38);
    v = *(f32 *)((s8 *)arg0 + 0xC0);
    if (v < 4.0f) {
        ((TObjEneDD *)arg0)->move_to_shot_position(((f32 (*)(int))sin_table_lookup)(*(s32 *)((s8 *)arg0 + 0x60)), ((f32 (*)(int))cos_table_lookup)(*(s32 *)((s8 *)arg0 + 0x60)), scale);
    } else if (!(v < 9.0f)) {
        if (v < 19.0f) {
            TObjEneEpsilon__sub_800B9384((arg0), iscale, scale);
        } else if (v < 24.0f) {
            ((TObjEneDD *)arg0)->move_to_shot_position(((f32 (*)(int))sin_table_lookup)(*(s32 *)((s8 *)arg0 + 0x60)), ((f32 (*)(int))cos_table_lookup)(*(s32 *)((s8 *)arg0 + 0x60)), scale);
        } else if (!(v < 30.0f)) {
            TObjEneEpsilon__sub_800B9384((arg0), iscale, scale);
        }
    }
    d.x = *(f32 *)((s8 *)arg0 + 0x38) - old.x;
    d.y = *(f32 *)((s8 *)arg0 + 0x3C) - old.y;
    d.z = *(f32 *)((s8 *)arg0 + 0x40) - old.z;
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x38, &old);
    apply_ground_movement__12TBoss8DragonFPvPv(arg0, (f32 *) &d);
}

void TBoss8Dragon__sub_802F48DC(TBoss8Dragon *dragon, Vec *target) {
    Vec saved;
    u8 shot[0xC];
    Vec delta;
    f32 dist;
    VecCopy(&saved, (Vec *)&dragon->m_38);
    delta.x = target->x - ((Vec *)&dragon->m_38)->x;
    delta.y = 0.0f;
    delta.z = target->z - ((Vec *)&dragon->m_38)->z;
    dist = normalize_vector_xz__FP3Vec(&delta);
    ((TBoss5Gryphon *)dragon)->calc_shot_position(shot, delta.x, delta.z, dist);
    ((TBoss5Gryphon *)dragon)->try_move_actor_xz_on_ground(shot);
    ((Vec *)&dragon->m_38)->y = saved.y;
    if (dragon->is_near_other_part() != 0) {
        VecCopy((Vec *)&dragon->m_38, &saved);
    }
}

void apply_ground_movement__12TBoss8DragonFPvPv(u8 *arg0, f32 *arg1) {
    Vec_802F481C c;
    Vec_802F481C b;
    Vec_802F481C a;
    f32 t;
    *(f32 *)((s8 *)arg0 + 0x3C) = *(f32 *)((s8 *)arg0 + 0x3C) + arg1[1];
    arg1[1] = 0.0f;
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&a, arg0 + 0x38);
    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&c, arg1);
    t = normalize_vector_xz__FP3Vec(&c);
    ((TBoss5Gryphon *)arg0)->calc_shot_position((u8 *)&b, (f32)c.x, (f32)c.z, (f32)t);
    ((TBoss5Gryphon *)arg0)->try_move_actor_xz_on_ground((u8 *)&b);
    *(f32 *)((s8 *)arg0 + 0x3C) = a.y;
    if ((((TBoss8Dragon *)arg0)->push_apart_from_parts() != 0) && (((TBoss8Dragon *)arg0)->is_near_other_part() != 0)) {
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x38, &a);
    }
}

}
#pragma push
#pragma fp_contract on
extern "C" {
s32 TBoss8Dragon__sub_802F4760(void *owner, Vec *point, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_802F4760, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_802F4760, spC) == 0x4) ? 1 : -1];
    Stack_802F4760 stack;
    f32 temp_f1;
    VecCopy((Vec *)&stack.sp8, point);
    stack.spC = 0.0f;
    ((s32 (*)(void *, void *))subtract_vector)(&stack.sp8, &boss8_dragon_reference_pos_vec.value);
    temp_f1 = normalize_vector_xz__FP3Vec(&stack.sp8);
    if ((temp_f1 + farg0) < boss8_dragon_visibility_distance) {
        if (vec3_dot(&stack.sp8, &dragon_forward_reference_vec.value) >= (temp_f1 * (1.0f / newton_sqrtf((f32) ((temp_f1 * temp_f1) + (farg0 * farg0)))))) {
            return 1;
        }
    }
    return 0;
}

}
#pragma pop
extern "C" {
s32 TBoss8Dragon__sub_802F46F4(s32 arg0) {
    s32 var_r30;
    var_r30 = 0;
    loop_1:
    if (((VObj_14_8d1630 *)((unsigned char *) ((s32)&((Induction_802F46F4_var_r31_owner *)arg0)->elements[var_r30])))->m8() != 0) {
        return 1;
    }
    var_r30 += 1;
    if (var_r30 >= 4) {
        return 0;
    }
    goto loop_1;
}

}
s32 TBoss8Dragon::hasActiveRenderFade() {
    for (s32 i = 0; i < 4; ++i) {
        if (renderFadeStates[i].isFading() != 0) {
            return 1;
        }
    }
    return 0;
}

extern "C" {
void TBoss8Dragon::update_camera_script() {
    s32 temp_r0;
    s32 pos;
    if ((s32) TBoss8Dragon__data_805D698C == (s32) lbl_805D6990) {
        push_matrix();
        update_camera_sequence__9TObjEneDDFv();
        mult_vec_array__10TObjPlayerFUll(0, (void *)&lbl_80541DF4.value, TBoss8Dragon__data_805D6994, 3);
        pop_matrix();
    }
    if ((s32) TBoss8Dragon__data_805D698C == (s32) *(s32 *)((s8 *)&dragon_camera_script_frame_table.value + (TBoss8Dragon__data_805D6998 * 4))) {
        pos = TBoss8Dragon__data_805D699C;
        TBoss8Dragon__data_805D699C = pos + 0xC;
        get_camera_ctrl__9TObjEneDDFv((s32) &lbl_80541DE8.value, pos);
        temp_r0 = TBoss8Dragon__data_805D6998 + 1;
        TBoss8Dragon__data_805D6998 = temp_r0;
        if ((temp_r0 == 7) && !(TBoss8Dragon__data_805D69A0 & 4)) {
            TBoss8Dragon__data_805D6998 = 0xC;
            TBoss8Dragon__data_805D699C += 0x3C;
        }
        if (((s32) TBoss8Dragon__data_805D6998 == 0x12) && !(TBoss8Dragon__data_805D69A0 & 2)) {
            TBoss8Dragon__data_805D6998 = 0x20;
            TBoss8Dragon__data_805D699C += 0xA8;
        }
    }
    TBoss8Dragon__data_805D698C += 1;
}

void TBoss8Dragon::render_body_model() {
    s32 saved = ((Obj_802F44D8 *)this)->f34;
    ((Obj_802F44D8 *)this)->f34 = TBoss8Dragon__data_805D69A8;
    TBoss8Dragon__data_805D698C = 0;
    TBoss8Dragon__data_805D6994 = (s32)((Obj_802F44D8 *)this)->f3EC;
    TBoss8Dragon__data_805D6998 = 0;
    TBoss8Dragon__data_805D699C = (s32)((Obj_802F44D8 *)this)->f434;
    TBoss8Dragon__data_805D69A0 = ((Obj_802F44D8 *)this)->f3C0;
    set_chunk_model_node_callback((s32)(TBoss8Dragon::update_camera_script));
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(((Obj_802F44D8 *)this)->v38);
    rotate_matrix_y(0, ((Obj_802F44D8 *)this)->f60);
    rotate_matrix_x(0, ((Obj_802F44D8 *)this)->f5C);
    rotate_matrix_z(0, ((Obj_802F44D8 *)this)->f64);
    scale_current_matrix(((Obj_802F44D8 *)this)->v68);
    draw_motion((NJS_OBJECT *)((Obj_802F44D8 *)this)->f34, (NJS_MOTION *)((Obj_802F44D8 *)this)->fF8, ((TObjEneDD_ST *)this)->get_motion_frame());
    clear_motion_packed_rotation();
    pop_matrix();
    set_chunk_model_node_callback((s32)NULL);
    ((Obj_802F44D8 *)this)->f34 = saved;
}

void TBoss8Dragon::copy_vectors() {
    struct VOff_802F4480_arg0 *self = (struct VOff_802F4480_arg0 *)this;
    VecCopy((Vec *)self->f_410, (const Vec *)((char *)this + 1004));
    VecCopy((Vec *)self->f_41C, (const Vec *)((char *)this + 1016));
    subtract_vector(self->f_41C, self->f_410);
    VecCopy((Vec *)((char *)this + 1064), (const Vec *)((char *)this + 1028));
}

extern "C" {
void TBoss8Dragon__sub_802F4380(TBoss8Dragon *self) {
    s32 view = 0;
    u8 pos[0xC];
    if (TObjPlayer::check_demo_mode() != 0) {
        ((VObj_802F4380 *)self)->draw_motion_model();
        return;
    }
    if (is_split_screen() != 0) {
        view = TCameraCtrl::get_camera_mode();
    }
    self->sub_802F4098(pos);
    if (defer_render__7TObjectFv((void *)self) != 0) {
        if (!(get_mode__11TCameraCtrlFPv(&(*(RecoveredGlobal_802F4380_main_task *)&main_task).value) & 0x10)) {
            self->render_body_model();
            self->copy_vectors();
        }
        if (self->renderFadeStates[view].isFading() == 0) {
            self->draw_with_fade((s32)pos, view);
        }
        self->render_nodes_flagged();
    } else if (self->renderFadeStates[view].isFading() != 0) {
        self->draw_with_fade((s32)pos, view);
    }
}
}

extern "C" {
int TBoss8Dragon__sub_802F4360(void* p) { return ((TObjEneDD *)p)->get_target_info(); }
}

void TBoss8Dragon::render_shadows() { if (check_demo_mode__10TObjPlayerFv(this) == 0) { draw(); } }

void TBoss8Dragon::draw() {
    s32 temp_r31;
    u8 *temp_r4;

    push_matrix();
    post_translate_matrix((void *) (((u8 *)this) + 0x38));
    rotate_matrix_y(0, this->m_60);
    rotate_matrix_x(0, this->m_5c);
    rotate_matrix_z(0, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x64)));
    scale_current_matrix((void *) (((u8 *)this) + 0x68));
    temp_r31 = this->m_34;
    temp_r4 = (unsigned char *) (*(void **)((s8 *)TBoss8Dragon__data_805D6988 + 0x42C));
    this->m_34 = (s32) *(s32 *)((s8 *)temp_r4 + 0x28);
    draw__10TObjMotionFv(this, (int)temp_r4);
    this->m_34 = temp_r31;
    pop_matrix();
}

void TBoss8Dragon::draw_with_fade(s32 arg1, s32 arg2) {
    u8 *temp_r31;
    if (!(this->m_3c <= -400.0f)) {
        TObjFish::set_global_param(this->m_24);
        TObjEneDD::clear_global_flag_400();
        saved_model_render_flags = model_render_flags;
        set_material_alpha_compare_reference(0);
        if (TBoss8Dragon__sub_802F3F20(((u8 *)this)) != 0) {
            ((RenderFadeState *)(&((Obj_802F4114 *)((u8 *)this))->fades[arg2]))->fadeOut();
        } else {
            ((RenderFadeState *)(&((Obj_802F4114 *)((u8 *)this))->fades[arg2]))->restore();
        }
        temp_r31 = (u8 *)&((Obj_802F4114 *)((u8 *)this))->fades[arg2];
        if (isFading__15RenderFadeStateCFv((int)temp_r31) != 0) {
            ((VObj_14_681f8e *)(temp_r31))->m6();
        }
        push_matrix();
        post_translate_matrix((void *)arg1);
        rotate_matrix_y(0, this->m_60);
        rotate_matrix_x(0, this->m_5c);
        rotate_matrix_z(0, (int) (*(s32 *)((s8 *)((u8 *)this) + 0x64)));
        scale_current_matrix((void *) (((u8 *)this) + 0x68));
        TObjPlayer::toggle_particle_effect();
        if (this->m_3c0 & 0x80) {
            set_tev_swap_channels(3, 3, 3, 3);
        }
        if (has_enough_enemies__12TBoss8DragonFv() != 0) {
            this->m_34 = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TBoss8Dragon__data_805D6988 + 0x42C)) + 0x18);
        } else {
            this->m_34 = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)TBoss8Dragon__data_805D6988 + 0x42C)) + 8);
        }
        ((TObjMotion *)((u8 *)this))->draw();
        init_tev_swap();
        TParticleCtrl::end_effect_render();
        TObjLight__sub_801337F8(current_scene_light);
        pop_matrix();
        set_chunk_material_override_pair(0xFF00, 0);
        set_material_alpha_compare_reference(0xBF);
        model_render_flags = saved_model_render_flags;
    }
}

void TBoss8Dragon::sub_802F4098(u8 *arg1) {
    VecCopy((Vec *)arg1, (const Vec *)(((u8 *)this) + 0x38));
    if ((get_mode__11TCameraCtrlFPv(&(*(RecoveredGlobal_802F4098_main_task *)&main_task).value) & 0x10) && (TBoss8Dragon__sub_802FCCBC(this) == 0) && !(this->m_c0 > 63.0f)) {
        *(f32 *)((s8 *)arg1 + 8) += -460.0f;
    }
}

extern "C" {
s32 TBoss8Dragon__sub_802F3F20(u8 *arg0) {
    Vec sp14;
    Vec sp8;
    f32 temp_f31;
    u8 *entity;
    s32 i;
    if (camera_ctrl_instance == 0) {
        return 0;
    }
    if (((Obj_802F3F20 *)arg0)->x326 == 30) {
        return 0;
    }
    if (((Obj_802F3F20 *)arg0)->x326 == 21) {
        return 0;
    }
    if (((Obj_802F3F20 *)arg0)->x326 == 22) {
        return 0;
    }
    if (((Obj_802F3F20 *)arg0)->x326 == 23) {
        return 1;
    }
    if (*(s32 *)(arg0 + 0x3E4) != 0) {
        return 0;
    }
    TCameraCtrl::get_camera_target_id(-1);
    entity = find_entity_by_id();
    if (entity == 0) {
        return 0;
    }
    VecCopy((Vec *)&sp14, (const Vec *)(camera_ctrl_instance + 0x178));
    sp14.y = 0.0f;
    VecCopy((Vec *)&sp8, (const Vec *)(entity + 0x38));
    subtract_vector(&sp8, &sp14);
    sp8.y = 0.0f;
    temp_f31 = normalize_vector_xz((Vec *)(&sp8));
    VecCopy((Vec *)&boss8_dragon_reference_pos_vec, (const Vec *)&sp14);
    VecCopy((Vec *)&dragon_forward_reference_vec, (const Vec *)&sp8);
    boss8_dragon_visibility_distance = temp_f31;
    for (i = 0; i < 4; i++) {
        if (TBoss8Dragon__sub_802F4760(arg0, &((Obj_802F3F20 *)arg0)->pts[boss8_dragon_point_index_table[i]], 12.0f) != 0) {
            return 1;
        }
    }
    return 0;
}
}

void TBoss8Dragon::render_nodes_flagged() {
    s32 arg0 = (s32)this;
    s32 temp_r4;

    temp_r4 = model_render_flags;
    saved_model_render_flags = temp_r4;
    model_render_flags = temp_r4 | 0x400;
    render_nodes__7TObjectFv(arg0 + 0x3C4, temp_r4);
    model_render_flags = saved_model_render_flags;
}

void TBoss8Dragon::draw_motion_model() {
    u8 *arg0 = (u8 *)this;
    f32 f;
    s32 idx;
    Anim_802F3D6C *anim;
    if (((VObj_18_26a62c *)(arg0))->m8(400.0f, 20.0f) != 0) {
        TObjFish::set_global_param(*(s32 *)(arg0 + 0x24));
        push_matrix();
        post_translate_matrix((u8 *)&this->m_38);
        rotate_matrix_y(0, *(s32 *)(arg0 + 0x60));
        push_matrix();
        scale_matrix(0, 8.0f, 2.0f, 8.0f);
        pop_matrix();
        scale_matrix(0, 2.0f, 2.0f, 2.0f);
        model_render_flags &= ~0x400;
        idx = *(f32 *)(arg0 + 0x354);
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 0x1C) {
            idx = 0x1B;
        }
        anim = (*(B_802F3D6C **)(arg0 + 0xDC))[(*(A_802F3D6C **)(arg0 + 0xD8))[idx].idx].anim;
        f = *(f32 *)(arg0 + 0x358);
        if (f < 0.0f) {
            f = 0.0f;
        } else if (f > (f32)(anim->nframes - 1)) {
            f = anim->nframes;
        }
        set_motion_packed_rotation();
        draw_model_motion((void *)(*(s32 *)(arg0 + 0x34)), anim, f);
        clear_motion_packed_rotation();
        TObjLight__sub_801337F8(current_scene_light);
        pop_matrix();
    }
}

extern "C" {
f32 calc_direct_attack_damage__12TBoss8DragonFPvPvPviii(void *a, void *b, Pair_802F3D18 *p, s32 x, s32 y, s32 z) {
    switch (p->a) {
    case 0xB:
    case 0xC:
        return 0.0f;
    }
    Pair_802F3D18 t = *p;
    return receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(a, b, &t, x, y, z);
}
}

void TBoss8Dragon::set_mode_params(s8 arg1) {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x3E8) = (s32) arg1;
    switch (*(s32 *)((s8 *)arg0 + 0x3E8)) {
    case 0:
        this->m_75c = 1;
        this->m_760 = &boss8_dragon_mode_params.value;
        return;
    case 1:
        this->m_75c = 2;
        this->m_760 = &dragon_mode_params_a.value;
        return;
    case 2:
        this->m_75c = 3;
        this->m_760 = &dragon_mode_params_b.value;
        return;
    }
}


}
extern "C" {

}

