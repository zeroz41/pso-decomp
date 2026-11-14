#pragma fp_contract on
#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/dd/TObjEneDD_800BA754.h"
#include "pso/system/vector.h"
#include "pso/system/MatrixOps.h"
#include "pso/render/render_util.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/math/AngleLookup.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
const char *TObjEneDD__name = "TObjEneDD";
const char *TObjEneDD_ST__name = "TObjEneDD_ST";
extern "C" {
void enemy_clear_target__12TObjEneDD_STFUs(void *);
u16 enemy_find_nearest_player_in_range(u8 *self, f32 range);
s32 is_valid_target__9TObjEneDDFv(s32);
u16 get_entity_id(void *);
u32 csnLookAt(void *, void *);
s32 push_matrix(void);
void post_translate_matrix(void *);
int rotate_matrix_y(void *, void *);
}
#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
extern "C" {
u32 get_player_by_client_id(u16);
}
#include "types.h"
#include "pso/enemy/dd/TObjEneDD_800BABA4.h"
#include "pso/enemy/dd/TObjEneDD_800BB804.h"
#include "pso/enemy/epsilon/TObjEneEpsilon_800B92AC.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/unk/TLobby.h"
struct O_800B98C0;
extern "C" {
void select_nearest_target__12TObjEneDD_STFf(s32 arg0);
s32 transform_relative_position__9TObjEneDDFPv(void *, int);
s32 calc_shot_position__13TBoss5GryphonFPUcfff(void *, s32, f32, f32, f32);
f64 atan2_float(f32, f32);
u16 set_squared_value__9TObjEneDDFf(void *, f32);
}
struct O_800B98C0 { u8 pad[0x38c]; u16 f38c; u8 pad2[2]; s32 f390; };
struct Obj_800B9958 { u8 pad[0x38c]; u16 id; u8 pad2[2]; s32 ptr; };
struct Obj_800B98D8 { u8 pad[0x38c]; u16 target_id; u8 pad2[2]; void *target; };
extern "C" {
s32 find_active_entity_by_id(u16);
void enemy_set_target_id(Obj_800B9958 *self, u16 id);
}
#include "types.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/dd/TObjEneDD.h"
extern const float TObjEneDD__data_805D9E8C;
#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
extern "C" {
f32 normalize_vector_xz__FP3Vec(void *, f32, f32);
extern const f32 TObjEneDD__data_805D9E8C;
}
#include "pso/enemy/dd/TObjEneDD_ST.h"
extern "C" void enemy_clear_target__12TObjEneDD_STFUs(void *);
#include "types.h"
#include "pso/enemy/dd/TObjEneDD_800B9AF8.h"
#include "pso/enemy/dd/TObjEneDD.h"
extern "C" {
int TObjLight__sub_801337F8(void*);
int TObjLight__sub_801337FC(void*);
extern int lbl_805D555C;
extern int current_scene_light;
}
#include "types.h"
#include "pso/enemy/dd/TObjEneDD_800B9B84.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/vector.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
extern "C" {
extern s32 camera_ctrl_instance;
int is_local_client_floor_leader(void*);
int TObjPlayer__sub_801BA42C(void*);
int freeze_all_players__10TObjPlayerFv(void*);
int is_any_teammate_in_state__10TObjPlayerFv(void*);
extern s32 enable_v2_features;
extern s32 game_difficulty_selection;
}
#include "types.h"
#include "pso/render/render_util.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/render/BlobShadow.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
struct Stack_800B9D94 {
    s32 sp8;
    u8 pad_C[0x4];
    s32 sp10;
};
struct Obj_800B9E84 {
    u8 pad[0x2b8]; s16 a; s16 b;
    u8 pad2[0x32c - 0x2bc]; s16 c; s16 d;
};
extern "C" {
s32 minimap_render_dot(void *, int, int, int);
s32 scale_current_matrix(void *);
extern const f32 TObjEneDD__data_805D9E8C;
int bind_enemy_combat_stats__9TObjEnemyFPUcPUcPUc(void*);
int transform_to_view__11TCameraCtrlFii(void*);
int apply_split_screen_view_matrix__11TCameraCtrlFv(void*);
int restore_scene_lighting(void*);
int select_actor_lighting(void*);
extern int model_render_flags;
}
#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
extern "C" {
f32 random_ratio__9TObjCharaFv();
}
#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
extern "C" {
f32 random_ratio__9TObjCharaFv();
}
#include "types.h"
#include "pso/enemy/dd/TObjEneDD_800BA754.h"
#include "pso/enemy/dd/TObjEneDD.h"
struct Part_800BA030 { u8 pad[0x2c]; };
struct Obj_800BA030 { u8 pad[0xa4]; Part_800BA030 *parts; s32 count; };
struct Part_800BA084 { u8 pad[0x2c]; };
struct Obj_800BA084 { u8 pad[0xa4]; Part_800BA084 *parts; s32 count; };
extern "C" {
f32 random_ratio__9TObjCharaFv();
}
#include "types.h"
#include "pso/enemy/dd/TObjEneDD_800BA138.h"
#include "pso/player/TUnk_804928CC.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include <stddef.h>
struct VBase_18_0c879f { char pad[0x18]; };
struct VObj_18_0c879f : VBase_18_0c879f {
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
    virtual s32 m21(s32, s32 *, s32, s32, s32);
};
struct Stack_800BA318 {
    s32 sp8;
    f32 spC;
};
struct E_800BA1C8 { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };
struct O_800BA1C8 { u8 pad[0xa4]; E_800BA1C8 *entries; s32 count; };
struct E_800BA190 { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };
struct O_800BA190 { u8 pad[0xa4]; E_800BA190 *entries; s32 count; };
struct Part_800BA200 { u8 pad[0x18]; u32 flags; u8 pad2[0x2c - 0x1c]; };
struct Obj_800BA200 { u8 pad[0x30]; u32 flags; u8 pad2[0xa4 - 0x34]; Part_800BA200 *parts; s32 count; };
struct Part_800BA244 { u8 pad[0x18]; u32 flags; u8 pad2[0x2c - 0x1c]; };
struct Obj_800BA244 { u8 pad[0x30]; u32 flags; u8 pad2[0xa4 - 0x34]; Part_800BA244 *parts; s32 count; };
extern "C" {
struct EneDDBase2_800BA138 { char pad[0x18]; };
struct EneDDObj2_800BA138 : EneDDBase2_800BA138 {
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
    virtual void m15(void *, void *);
    virtual void m16(void *, void *);
};
struct EneDDBase_800BA138 { char pad[0x18]; };
struct EneDDObj_800BA138 : EneDDBase_800BA138 {
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
    virtual void m12(void *, void *, void *);
    virtual void m13(void *, void *, void *);
};
int is_target_unobstructed__9TObjEneDDFl(void* a0 = 0, void* a1 = 0, void* a2 = 0);
int add_flags_2e4__9TObjCharaFUl(void*, int);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
s32 get_position__12TBoss1DragonFv(void *, s32);
u8 * obj_ene_dd_instance;
}
#include "types.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
struct E_800BA8A8 { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };
struct O_800BA8A8 { u8 pad[0xa4]; E_800BA8A8 *entries; s32 count; };
extern "C" {
int TObjEneDD__sub_800BA804(u16 arg0);
s32 all_parents_unqueued_for_destruction__7TObjectFv();
}
void set_collider_contact_low(u8 *arg0);
void set_collider_contact_high(u8 *arg0);
void update_collider_contact_by_height(u8 *arg0, f32 farg0);
#include "types.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
struct Part_800BA934 { u8 pad[0x1c]; u8 f1c[0x10]; };
struct Obj_800BA934 { u8 pad[0x38]; u8 f38[0x28]; void *f60; u8 pad2[0x40]; Part_800BA934 *parts; s32 count; };
struct Part_800BAAE4 { Vec a; u8 pad[0x10]; Vec b; u8 pad2[4]; };
struct Obj_800BAAE4 { u8 pad[0x38]; Vec pos; u8 pad2[0x1c]; s32 angle; u8 pad3[0x40]; Part_800BAAE4 *parts; };
struct Vec_800BA9BC { f32 x, y, z; };
struct Part_800BA9BC { Vec_800BA9BC a; u8 pad[0x10]; Vec_800BA9BC b; u8 pad2[4]; };
struct Obj_800BA9BC { u8 pad[0x38]; Vec_800BA9BC pos; u8 pad2[0x1c]; s32 angle; u8 pad3[0x40]; Part_800BA9BC *parts; };
struct V3_800BAA2C { f32 x; f32 y; f32 z; };
struct Col_800BAA2C { u8 pad0[0x1C]; V3_800BAA2C pos; u8 pad28[4]; };
struct Obj_800BAA2C { u8 pad0[0x38]; f32 x; f32 y; f32 z; u8 pad44[0x60 - 0x44]; s32 rot; u8 pad64[0xA4 - 0x64]; Col_800BAA2C *cols; s32 count; };
extern "C" {
int matrix_mult_vec(void *, void *, void *);
void set_part_position__9TObjEneDDFPvPvi(Obj_800BA9BC *self, Vec_800BA9BC *v, s32 i);
void update_local_colliders_from_world(Obj_800BAA2C *arg0, V3_800BAA2C *arg1);
}
#include "pso/system/vector.h"
#include "types.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
struct VBase_18_3f4583 { char pad[0x18]; };
struct VObj_18_3f4583 : VBase_18_3f4583 {
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
    virtual void * m101();
};
struct Vec_800BAF1C { f32 x, y, z; };
struct Node_800BAF1C { u8 pad0[4]; Vec_800BAF1C *pos; };
struct Ene_800BAF1C {
    u8 pad0[0x38];
    Vec_800BAF1C pos;
    u8 pad44[0x37C - 0x44];
    f32 reach;
    s32 count;
};
struct Vec_800BB000 { f32 x, y, z; };
struct Node_800BB000 { u8 pad0[4]; u8 *wall; };
struct Ene_800BB000 {
    u8 pad0[0x38];
    Vec_800BB000 pos;
    u8 pad44[0x37C - 0x44];
    f32 reach;
    s32 count;
};
extern "C" {
f32 newton_sqrtf(f32);
}
void calc_wall_clamped_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist);
extern const f32 TObjEneDD__data_805D9E8C;
void calc_wall_slide_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist);
#include <dolphin/mtx.h>
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "types.h"
struct Stack_800BB218
{
  f32 sp8;
  f32 spC;
  f32 sp10;
};
#include <stddef.h>
extern "C" {
f32 fabs_float(f32);
s32 csnVector(void *, void *, int);
u8 *csnVectorUnder(f32 *, void *, s32);
s32 VecCopy__FP3VecPC3Vec(void *, void *, s32);
typedef struct Stack_800BB218 Stack_800BB218;
}
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BB650.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/TLobby.h"
struct RecoveredGlobal_800BB45C_lbl_80500B98 {
    s32 value;
    u8 remaining[0x1C];
};
struct Ent_800BB484 { s16 id; f32 dist; };
extern "C" {
extern RecoveredGlobal_800BB45C_lbl_80500B98 enemy_target_candidate_table;
typedef struct Ent_800BB388 {
    u8 pad0[0x30];
    s32 flags30;
    u8 pad34[0x38 - 0x34];
    u8 pos[0x2FC - 0x38];
    u8 f2FC[0xC];
}
Ent_800BB388;
u16 enemy_nearest_visible_enemy_sq(Ent_800BB388 *self, f32 range);
extern const f32 TObjEneDD__data_805D9E8C;
s32 collect_enemy_target_candidates(s32 arg0, Ent_800BB484 *out, f32 farg0);
typedef char RecoveredGlobal_800BB45C_lbl_80500B98_size[sizeof(RecoveredGlobal_800BB45C_lbl_80500B98) == 0x20 ? 1 : -1];
}
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_800BB650.h"
#include "pso/enemy/fly/TObjEneBm3Fly.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/TLobby.h"
struct Part_800BB780 { u8 pad[0x18]; u32 flags; u8 pad2[0x10]; };
struct Obj_800BB780 { u8 pad[0x30]; u32 flags; u8 pad1[0x70]; Part_800BB780 *parts; s32 count; u8 pad2[0x230]; s32 f2dc; u8 pad3[0x4c]; s16 f32c; u8 pad4[0x10]; s16 f33e; };
extern "C" {
int submit_cursor_candidate(void*, int);
}
#include "types.h"
#include "pso/enemy/dd/TObjEneDD_800BB804.h"
#include "pso/unk/text_800BC4C8.h"
#include "pso/system/vector.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/enemy/dd/TObjEneDD.h"
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
    virtual s32 m84();
    virtual s32 m85(s16, s32);
};
struct VBase_18_62ee2d { char pad[0x18]; };
struct VObj_18_62ee2d : VBase_18_62ee2d {
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
    virtual s32 m31();
    virtual void m32();
    virtual void m33();
    virtual void m34();
    virtual void m35();
    virtual s32 m36();
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
    virtual s32 m60();
    virtual s32 m61();
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
    virtual s32 m82();
};
struct Base_800BBA18 { char pad[0x18]; };
struct V_800BBA18 : Base_800BBA18 {
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
    virtual void m84(); virtual void m85(s16 state, s32 mode);
    u8 pad_[0x326 - 0x1c];
    s16 state;
};
struct Obj_800BB88C {
    u8 pad0[0x28]; s16 f28; s16 f2a; u8 pad2c[0xc];
    f32 f38; f32 f3c; f32 f40; u8 pad44[0x18];
    s32 f5c; s32 f60; s32 f64; u8 pad68[0x354 - 0x68];
    f32 f354[5]; s32 f368; s32 f36c;
};
extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern const f32 TObjEneDD__data_805D9E8C;
s32 subtractive_rng_seed(void *, int);
s32 vfunc_79__9TObjEnemyFPl();
int fn_800FD8A0(void*);
extern s32 area_random_seed;
struct Base_800BBDD4 { char pad[0x18]; };
struct VObj_800BBDD4 : Base_800BBDD4 {
    virtual void m0(int);
};
void *__nw__7TObjectFUl(int);
extern int lbl_805D5870;
}

s32 tick_period_counter(s32 arg0, s32 *arg1, s32 arg2) {
    s32 temp_r3;
    temp_r3 = *arg1;
    if (temp_r3 >= arg2) {
        *arg1 = 0;
        return 1;
    }
    *arg1 = temp_r3 + 1;
    return 0;
}

extern "C" {

int TObjEneDD::get_enemy_count() {  return lbl_805D5870; }

void TObjEneDD::create_instance() {
    void *o;
    o = __nw__7TObjectFUl(0xB0);
    if (o != NULL) {
        o = __ct__13TUnk_804928CCFP7TObjectP8TObjBase((u8 *)o, 0, 0);
    }
    obj_ene_dd_instance = (u8 *)o;
}

void TObjEneDD::release_resource() {
    if (obj_ene_dd_instance != NULL) {
        if (obj_ene_dd_instance != NULL) {
            ((VObj_800BBDD4 *)obj_ene_dd_instance)->m0(1);
        }
        obj_ene_dd_instance = NULL;
    }
}

TObjEneDD::TObjEneDD(TObject *parent) : TObjEnemy(parent) {
    m_name = TObjEneDD__name;
    *(u32 *)((s8 *)this + 0x374) = 0;
    *(u32 *)((s8 *)this + 0x378) = 0;
    *(f32 *)((s8 *)this + 0x37C) = 5.0f;
    *(u32 *)((s8 *)this + 0x380) = 0;
    *(u32 *)((s8 *)this + 0x384) = 0;
    *(u32 *)((s8 *)this + 0x388) = 0;
}

TObjEneDD::~TObjEneDD() {}

void TObjEneDD::init_position_vectors() {
    u8 *arg0 = (u8 *)this;
    VecCopy(&this->prev_position, (const Vec *)&this->position);
    VecCopy(&this->home_position, (const Vec *)&this->position);
    VecCopy(&this->center, (const Vec *)&this->position);
    ((TBoss3Volopt *)arg0)->reset_photon_effect();
    VecCopy((Vec *)&this->m_2fc, (const Vec *)&this->position);
    *(f32 *)((s8 *)arg0 + 0x308) = (f32) TObjEneDD__data_805D9E8C;
    *(f32 *)((s8 *)arg0 + 0x30C) = (f32) TObjEneDD__data_805D9E8C;
    this->m_310 = (f32) TObjEneDD__data_805D9E8C;
    this->ground_normal.x = (f32) TObjEneDD__data_805D9E8C;
    ground_normal.y = (f32) TObjEneDD__data_805D9E8C;
    this->ground_normal.z = (f32) TObjEneDD__data_805D9E8C;
    this->target = 0;
    this->clear_lobby_object_state();
}

s32 TObjEneDD::vfunc_83() {
    u8 *arg0 = (u8 *)this;
    if (this->has_flag_0x800() != 0) {
        this->vfunc_63();
        return 1;
    }
    this->update_attack_stat_status();
    this->update_defense_stat_status();
    this->update_flag30_timer();
    if (((VObj_18_62ee2d *)(arg0))->m82() != 0) {
        return 4;
    }
    if (this->test_flag30_512() != 0) {
        this->vfunc_62();
        return 2;
    }
    return 0;
}

s32 TObjEneDD::vfunc_84() {
    s32 r = update_action_hold_status();
    r |= update_shock_clock();
    r |= update_movement_status();
    return r;
}

void TObjEneDD::vfunc_85() {
    if (((VObj_18 *)(this))->m84() == 0) {
        ((VObj_18 *)(this))->m85(this->mode, 3);
    }
    ((VObj_18 *)(this))->m85(this->mode, 0);
    sub_800BBA0C();
}

u8 TObjEneDD::vfunc_86() {
    return (u8) (*(s32 *)((s8 *)this + 0x374) != this->mode);
}

void TObjEneDD::transition_enemy_state(s32 state) {
    dispatch_action(mode, 5);
    dispatch_action(state, 4);
    mode = state;
}

void TObjEneDD::sub_800BBA0C() {
    *(s32 *)((s8 *)((u8 *)this) + 0x374) = (s32) this->mode;
}

void TObjEneDD::set_field_378(s32 v) { *(s32*)((char*)this + 0x378) = v; }

s32 load_enemy_bml_resource(u8 *arg0) {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, arg0, 0, 0, 0));
    }
    return var_r0;
}

void TObjEneDD::copy_resource_desc(u8 *arg1) {
    *(s32 *)&this->m_name = (s32) *(s32 *)((s8 *)arg1 + 0);
    *(s32 *)&this->m_flags = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(s32 *)&this->m_prev = (s32) *(s32 *)((s8 *)arg1 + 8);
    *(s16 *)&this->m_next = (s16) *(s16 *)((s8 *)arg1 + 0xC);
    *(s16 *)((s8 *)((u8 *)this) + 0xE) = (s16) *(s16 *)((s8 *)arg1 + 0xE);
}

s32 load_enemy_bml_resource_named(s32 arg0, s32 arg1) {
    s32 sp8;
    ((TObjEneDD *)(&sp8))->copy_resource_desc((u8 *)arg0);
    sp8 = arg1;
    return load_enemy_bml_resource((u8 *)&sp8);
}

void TObjEneDD::vfunc_79(s32 *state) {
    s16 temp_r31;

    temp_r31 = this->mode;
    TObjEnemy::vfunc_79(state);
    this->mode = temp_r31;
}

void TObjEneDD::invoke_initialization_hook(void *set_data) {
    apply_set_data(set_data);
}

void TObjEneDD::reset_state_fields() {
    s32 i;
    ((Obj_800BB88C *)this)->f38 = TObjEneDD__data_805D9E8C;
    ((Obj_800BB88C *)this)->f3c = TObjEneDD__data_805D9E8C;
    ((Obj_800BB88C *)this)->f40 = TObjEneDD__data_805D9E8C;
    ((Obj_800BB88C *)this)->f5c = 0;
    ((Obj_800BB88C *)this)->f60 = 0;
    ((Obj_800BB88C *)this)->f64 = 0;
    for (i = 0; i < 5; i++) {
        ((Obj_800BB88C *)this)->f354[i] = TObjEneDD__data_805D9E8C;
    }
    ((Obj_800BB88C *)this)->f368 = 0;
    ((Obj_800BB88C *)this)->f36c = 0;
    ((Obj_800BB88C *)this)->f28 = -1;
    ((Obj_800BB88C *)this)->f2a = -1;
}

s32 pack_debug_text_position(s32 arg0, s32 arg1) {
    return ((arg0 + 0x13) << 0x10) | (arg1 + 0x1A);
}

int TObjEneDD::get_target_info() { return fn_800FD8A0(this); }

void TObjEneDD::init_common_from(u8 *arg1) {
    reset_state_fields();
    *(s16 *)&this->room = (s16) *(s16 *)((s8 *)arg1 + 0x28);
    *(s16 *)((s8 *)((u8 *)this) + 0x2A) = (s16) *(s16 *)((s8 *)arg1 + 0x2A);
    subtractive_rng_seed((void *) (((u8 *)this) + 0x160), (int) (this->entity_id + area_random_seed));
}

}

int TObjEnemy::submit_default_cursor_candidate() { return submit_cursor_candidate(this, -1); }

void TBoss8Dragon__sub_800BB7DC(void) {  }

void TBoss8Dragon__sub_800BB7D8(void) {  }

void TBoss8Dragon__sub_800BB7D4(void) {  }

void TBoss8Dragon::noop() {  }

void TObjEneDD::clear_attack_receipts() {
    s32 i;
    ((Obj_800BB780 *)this)->f33e = ((Obj_800BB780 *)this)->f32c;
    ((Obj_800BB780 *)this)->flags &= ~0x200;
    ((Obj_800BB780 *)this)->f2dc = 0;
    for (i = 0; i < ((Obj_800BB780 *)this)->count; i++) {
        ((Obj_800BB780 *)this)->parts[i].flags &= ~0x04000000;
    }
}

int TObjEneBm3Fly::was_hit_by_ranged() { return (this->m_2dc >> 1) & 0x1; }

void TObjEnemy::refresh_and_send_entity_flags() { ((TObjPlayer *)this)->refresh_lobby_state(); ((TObjEnemy *)this)->send_entity_set_flags(); }

u16 enemy_nearest_visible_player_sq(u8 *arg0, f32 farg0) {
    f32 d;
    f32 best;
    s32 n;
    u8 *p;
    u16 result;
    s32 i;
    best = farg0;
    result = 0xFFFF;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        p = (u8 *)TObjPlayer::get_player_data(i);
        if (((TObjBase *)p)->is_alive() != 0) {
            d = horizontal_distance_squared((const Vec *)(arg0 + 0x2FC), (const Vec *)(p + 0x38));
            if (d < best && csnLookAt(arg0 + 0x2FC, p + 0x2FC) == 0) {
                result = get_entity_id(p);
                best = d;
            }
        }
    }
    return result;
}

extern "C" {

u16 enemy_find_nearest_player_in_range(u8 *self, f32 range) {
    return enemy_nearest_visible_player_sq(self, range * range);
}

void TBoss8Dragon__sub_800BB650(void* p, void* q) { *(u16*)((char*)p + 0x0) = *(u16*)((char*)q + 0x0); *(f32*)((char*)p + 0x4) = *(f32*)((char*)q + 0x4); }

s32 collect_enemy_target_candidates(s32 arg0, Ent_800BB484 *out, f32 farg0) {
    s32 n;
    s32 cnt;
    Ent_800BB484 tmp;
    u8 *p;
    s32 mi;
    s32 j;
    f32 mx;
    f32 d;
    s32 k;
    n = 0;
    cnt = TLobby::get_game_mode();
    if (farg0 > TObjEneDD__data_805D9E8C) {
        for (s32 i = 0; i < cnt; i++) {
            p = ((u8 *)TObjPlayer::get_player_data(i));
            if (((TObjBase *)p)->is_alive() != 0) {
                d = horizontal_distance_squared((const Vec *)(arg0 + 0x38), (const Vec *)(p + 0x38));
                if (d < farg0) {
                    out[n].id = get_entity_id(p);
                    out[n].dist = d;
                    n++;
                }
            }
        }
    } else {
        for (s32 i = 0; i < cnt; i++) {
            p = ((u8 *)TObjPlayer::get_player_data(i));
            if (((TObjBase *)p)->is_alive() != 0) {
                d = horizontal_distance_squared((const Vec *)(arg0 + 0x38), (const Vec *)(p + 0x38));
                out[n].id = get_entity_id(p);
                out[n].dist = d;
                n++;
            }
        }
    }
    if (n > 1) {
        for (k = n - 1; k >= 1; k--) {
            mx = out[0].dist;
            mi = 0;
            for (j = 1; j <= k; j++) {
                f32 v = out[j].dist;
                if (v > mx) {
                    mx = v;
                    mi = j;
                }
            }
            if (mi != k) {
                TBoss8Dragon__sub_800BB650(&tmp, &out[mi]);
                TBoss8Dragon__sub_800BB650(&out[mi], &out[k]);
                TBoss8Dragon__sub_800BB650(&out[k], &tmp);
            }
        }
    }
    return n;
}

void TObjEneDD::collect_target_candidates(s32 arg0, f32 farg0) {
    collect_enemy_target_candidates(arg0, (Ent_800BB484 *)(&enemy_target_candidate_table.value), farg0);
}

u16 enemy_nearest_visible_enemy_sq(Ent_800BB388 *self, f32 range) {
    s32 count;
    s32 base;
    Ent_800BB388 *p;
    u16 best;
    s32 i;
    f32 d;

    best = 0xFFFF;
    base = TLobby::get_game_mode();
    count = TObjEneDD::get_enemy_count();
    for (i = 0; i < count; i++) {
        p = (Ent_800BB388 *)TObjPlayer::get_player_data(base + i);
        if (p != self && !(p->flags30 & 0x01000000) && ((TObjBase *)p)->is_alive() != 0) {
            d = horizontal_distance_squared((const Vec *)self->f2FC, (const Vec *)p->pos);
            if (d < range && csnLookAt(self->f2FC, p->f2FC) == 0) {
                best = get_entity_id(p);
                range = d;
            }
        }
    }
    return best;
}

void TObjEneDD::set_squared_value(f32 farg0) {
    ((s32 (*)(f32))enemy_nearest_visible_enemy_sq)(farg0 * farg0);
}

u8 *TObjEneDD::vfunc_103(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    Vec position;
    u8 *temp_r3;
    position.x = *(f32 *)((s8 *)arg1 + 0);
    position.y = *(f32 *)((s8 *)arg1 + 4) + *(f32 *)(this->m_2b0 + 0x10);
    position.z = *(f32 *)((s8 *)arg1 + 8);
    if (csnVectorUnder(&position.x, (u8 *)&this->m_120, 0xE0) != NULL) {
        return NULL;
    }
    temp_r3 = (u8 *)(csnVectorUnder(&position.x, (u8 *)&this->m_120, 0x15));
    if (temp_r3 == NULL) {
        return NULL;
    }
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 4)) + 4);
    return temp_r3;
}

s32 TBoss5Gryphon::enemy_probe_wall_ahead(f32 farg0, f32 farg1, f32 farg2) {
  f32 temp_f31;
  Stack_800BB218 stack;
  f32 temp_f30;
  temp_f30 = farg0 * farg2;
  temp_f31 = farg1 * farg2;
  if ((fabs_float(temp_f30) < 0.01f) && (fabs_float(temp_f31) < 0.01f))
  {
    return farg0 * 0;
  }
  stack.sp8 = (*((f32 *) (((s8 *) ((u8 *)this)) + 0x38))) + temp_f30;
  stack.spC = this->m_300;
  stack.sp10 = (*((f32 *) (((s8 *) ((u8 *)this)) + 0x40))) + temp_f31;
  return csnVector((void *) (((u8 *)this) + 0x2FC), &stack.sp8, 0x88E0);
}

void TBoss5Gryphon::calc_shot_position(u8 *arg1, f32 farg0, f32 farg1, f32 farg2) {
    u8 *arg0 = (u8 *)this;
    s32 temp_r5;

    f32 reach = farg2 + this->m_37c;
    if (((TBoss5Gryphon *)arg0)->enemy_probe_wall_ahead(farg0, farg1, reach) == 0U) {
        *(f32 *)((s8 *)arg1 + 0) = (f32) ((farg0 * farg2) + *(f32 *)((s8 *)arg0 + 0x38));
        *(f32 *)((s8 *)arg1 + 4) = (f32) *(f32 *)((s8 *)arg0 + 0x3C);
        *(f32 *)((s8 *)arg1 + 8) = (f32) ((farg1 * farg2) + *(f32 *)((s8 *)arg0 + 0x40));
        *(s32 *)((s8 *)arg0 + 0x380) = 0;
        return;
    }
    temp_r5 = *(s32 *)((s8 *)arg0 + 0x380);
    *(s32 *)((s8 *)arg0 + 0x380) = (temp_r5 + 1);
    VecCopy__FP3VecPC3Vec(arg1, (u8 *)&this->position, temp_r5);
}

}

#pragma push
#pragma fp_contract on
#define e ((Ene_800BB000 *)arg0)
#define out ((Vec_800BB000 *)arg1)
void calc_wall_slide_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist) {
    Node_800BB000 *n;
    Vec_800BB000 v;
    n = (Node_800BB000 *)((TBoss5Gryphon *)e)->enemy_probe_wall_ahead(dx, dz, dist + e->reach);
    if (n == NULL) {
        out->x = dx * dist + e->pos.x;
        out->y = e->pos.y;
        out->z = dz * dist + e->pos.z;
        e->count = 0;
        return;
    }
    e->count++;
    v.x = *(f32 *)(n->wall + 0x14);
    v.z = -*(f32 *)(n->wall + 0xC);
    normalize_vector_xz((Vec *)(&v));
    if (dx * v.x + dz * v.z >= TObjEneDD__data_805D9E8C) {
        dx = v.x;
        dz = v.z;
    } else {
        dx = -v.x;
        dz = -v.z;
    }
    if ((Node_800BB000 *)((TBoss5Gryphon *)e)->enemy_probe_wall_ahead(dx, dz, dist + e->reach) == NULL) {
        out->x = dx * dist + e->pos.x;
        out->y = e->pos.y;
        out->z = dz * dist + e->pos.z;
        return;
    }
    VecCopy((Vec *)out, (const Vec *)&e->pos);
}
#undef e
#undef out
#pragma pop

#pragma push
#pragma fp_contract on
void calc_wall_clamped_destination(void *arg0, void *arg1, f32 dx, f32 dz, f32 dist) {
    Ene_800BAF1C *e = (Ene_800BAF1C *)arg0;
    Vec_800BAF1C *out = (Vec_800BAF1C *)arg1;
    Node_800BAF1C *n = (Node_800BAF1C *)((TBoss5Gryphon *)e)->enemy_probe_wall_ahead(dx, dz, dist + ((TBoss5Gryphon *)e)->m_37c);
    if (n == NULL) {
        e->count = 0;
    } else {
        Vec_800BAF1C *p;
        f32 ddx;
        f32 px;
        f32 ddz;
        e->count++;
        p = n->pos;
        px = p->x;
        ddz = p->z - e->pos.z;
        ddx = px - e->pos.x;
        dist = ((f32 (*)(f32, f32, f32))newton_sqrtf)(ddx * ddx + ddz * ddz, px, ddz) - ((TBoss5Gryphon *)e)->m_37c;
    }
    out->x = dx * dist + e->pos.x;
    out->y = e->pos.y;
    out->z = dz * dist + e->pos.z;
}
#pragma pop

u8 *TBoss5Gryphon::try_move_actor_xz_on_ground(u8 *arg1) {
    f32 temp_f31;
    u8 *temp_r3;
    temp_f31 = *(f32 *)((s8 *)((u8 *)this) + 0x3C);
    temp_r3 = (unsigned char *) (((VObj_18_3f4583 *)(this))->m101());
    if (temp_r3 != NULL) {
        this->prev_position.x = (f32) *(f32 *)((s8 *)((u8 *)this) + 0x38);
        this->prev_position.y = temp_f31;
        this->prev_position.z = (f32) *(f32 *)((s8 *)((u8 *)this) + 0x40);
        *(f32 *)((s8 *)((u8 *)this) + 0x38) = (f32) *(f32 *)((s8 *)arg1 + 0);
        *(f32 *)((s8 *)((u8 *)this) + 0x40) = (f32) *(f32 *)((s8 *)arg1 + 8);
        VecCopy((Vec *)(((u8 *)this) + 0x248), (const Vec *)(*(s32 *)((s8 *)temp_r3 + 4) + 0xC));
        this->m_384 = 0;
    } else {
        this->m_384 = (this->m_384 + 1);
    }
    return temp_r3;
}

u8 *TObjEneDD::vfunc_101(u8 *arg1) {
    u8 *arg0 = (u8 *)this;
    f32 temp_f31;
    u8 *temp_r3;
    temp_f31 = *(f32 *)((s8 *)arg0 + 0x3C);
    temp_r3 = (unsigned char *) (((VObj_18_3f4583 *)(arg0))->m101());
    if (temp_r3 != NULL) {
        VecCopy((Vec *)(arg0 + 0x248), (const Vec *)(*(s32 *)((s8 *)temp_r3 + 4) + 0xC));
    }
    this->prev_position.x = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    this->prev_position.y = temp_f31;
    this->prev_position.z = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    *(f32 *)((s8 *)arg0 + 0x38) = (f32) *(f32 *)((s8 *)arg1 + 0);
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) *(f32 *)((s8 *)arg1 + 8);
    *(s32 *)((s8 *)arg0 + 0x384) = 0;
    return temp_r3;
}

u8 *TObjEneDD::vfunc_102() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f31;
    u8 *temp_r3;
    temp_f31 = *(f32 *)((s8 *)arg0 + 0x3C);
    temp_r3 = (unsigned char *) (((TObjEneDD *)(arg0))->update_actor_ground_y());
    if (temp_r3 != NULL) {
        VecCopy((Vec *)(arg0 + 0x248), (const Vec *)(*(s32 *)((s8 *)temp_r3 + 4) + 0xC));
    }
    this->prev_position.x = (f32) *(f32 *)((s8 *)arg0 + 0x38);
    this->prev_position.y = temp_f31;
    this->prev_position.z = (f32) *(f32 *)((s8 *)arg0 + 0x40);
    *(s32 *)((s8 *)arg0 + 0x384) = 0;
    return temp_r3;
}

void TObjEneDD::move_to_shot_position(f32 farg0, f32 farg1, f32 farg2) {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    ((TBoss5Gryphon *)arg0)->calc_shot_position((u8 *)&sp8, (f32)farg0, (f32)farg1, (f32)farg2);
    ((TBoss5Gryphon *)arg0)->try_move_actor_xz_on_ground((u8 *)&sp8);
}

void TObjEneDD::move_with_wall_slide_on_ground(f32 dx, f32 dz, f32 dist) {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    calc_wall_slide_destination(arg0, &sp8, dx, dz, dist);
    ((TBoss5Gryphon *)arg0)->try_move_actor_xz_on_ground((u8 *)&sp8);
}

void TObjEneDD::move_clamped_on_ground(f32 farg0, f32 farg1, f32 dist) {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    calc_wall_clamped_destination(arg0, &sp8, farg0, farg1, dist);
    ((TBoss5Gryphon *)arg0)->try_move_actor_xz_on_ground((u8 *)&sp8);
}

void TObjEneDD::move_with_wall_stop(f32 farg0, f32 farg1, f32 farg2) {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    ((TBoss5Gryphon *)arg0)->calc_shot_position((u8 *)&sp8, (f32)farg0, (f32)farg1, (f32)farg2);
    this->vfunc_101((u8 *)&sp8);
}

void TObjEneDD::move_with_wall_slide_commit(f32 dx, f32 dz, f32 dist) {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    calc_wall_slide_destination(arg0, &sp8, dx, dz, dist);
    this->vfunc_101((u8 *)&sp8);
}

void TObjEneDD::move_to_wall_clamped_destination(f32 farg0, f32 farg1, f32 dist) {
    u8 *arg0 = (u8 *)this;
    s32 sp8;
    calc_wall_clamped_destination(arg0, &sp8, farg0, farg1, dist);
    this->vfunc_101((u8 *)&sp8);
}

int TObjEneDD::has_move_failures(s32 arg1) {
    u8 *arg0 = (u8 *)this;
    u8 var_r5;
    var_r5 = 0;
    if (((s32) *(s32 *)((s8 *)arg0 + 0x380) >= arg1) || ((s32) *(s32 *)((s8 *)arg0 + 0x384) >= arg1)) {
        var_r5 = 1;
    }
    return var_r5;
}

extern "C" {

void TObjEneDD_ST::set_active() { *(s32*)((char*)this + 0x388) = 1; }

void TObjEneDD::clear_field_388() { *(s32*)((char*)this + 0x388) = 0; }

void TObjEneDD::init_model(CollisionBody *bodies, s32 count) {
    init_collision_body_parts(this, bodies, count);
    transform_part_positions();
}

void TObjEneDD::set_part_local_pos(void *v, s32 i) {
    Vec *p;
    VecCopy((Vec *)&((Obj_800BAAE4 *)this)->parts[i].b, (const Vec *)((Vec *)v));
    p = &((Obj_800BAAE4 *)this)->parts[i].a;
    VecCopy((Vec *)p, (const Vec *)((Vec *)v));
    subtract_vector(p, &((Obj_800BAAE4 *)this)->pos);
    rotate_xz_pair_by_angle(&p->x, &p->z, -((Obj_800BAAE4 *)this)->angle);
}

void update_local_colliders_from_world(Obj_800BAA2C *arg0, V3_800BAA2C *arg1) {
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    rotate_matrix_y((void *)(0), (void *)(-arg0->rot));
    translate_matrix(0, -arg0->x, -arg0->y, -arg0->z);
    for (i = 0; i < arg0->count; i++) {
        VecCopy((Vec *)((Vec *)(&arg0->cols[i].pos)), (const Vec *)((const Vec *)(arg1)));
        matrix_mult_vec(0, arg1, &arg0->cols[i]);
        arg1++;
    }
    pop_matrix();
}

void set_part_position__9TObjEneDDFPvPvi(Obj_800BA9BC *self, Vec_800BA9BC *v, s32 i) {
    Vec_800BA9BC *p;
    VecCopy((Vec *)((Vec *)(&self->parts[i].a)), (const Vec *)((const Vec *)(v)));
    p = &self->parts[i].b;
    VecCopy((Vec *)((Vec *)(p)), (const Vec *)((const Vec *)(v)));
    rotate_xz_pair_by_angle(&p->x, &p->z, self->angle);
    vec3_add_to((Vec *)p, (const Vec *)&self->pos);
}

void TObjEneDD::transform_part_positions() {
    Obj_800BA934 *self = (Obj_800BA934 *)this;
    s32 i;
    push_matrix();
    set_matrix_identity(0);
    post_translate_matrix(self->f38);
    rotate_matrix_y(0, self->f60);
    set_motion_packed_rotation();
    for (i = 0; i < self->count; i++) {
        matrix_mult_vec(0, &self->parts[i], self->parts[i].f1c);
    }
    clear_motion_packed_rotation();
    pop_matrix();
}

}

void TObjEneDD::vfunc_88() {  }

void TObjEneDD::vfunc_89() {
    this->vfunc_88();
    ((TObjPlayer *)this)->check_object_collisions();
    check_enemy_body_collisions(this);
}

s32 TObjEneDD::vfunc_90() {
    O_800BA8A8 *self = (O_800BA8A8 *)this;
    s32 i;
    for (i = 0; i < self->count; i++) {
        if (self->entries[i].flags & 0x380000) {
            return 1;
        }
    }
    return 0;
}

void set_collider_contact_high(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) | 4);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) & 0xFFFFFFFD);
}

void set_collider_contact_low(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) & 0xFFFFFFFB);
    *(s32 *)((s8 *)arg0 + 0x18) = (s32) (*(s32 *)((s8 *)arg0 + 0x18) | 2);
}

void update_collider_contact_by_height(u8 *arg0, f32 farg0) {
    if (*(f32 *)((s8 *)arg0 + 4) >= farg0) {
        set_collider_contact_high(arg0);
        return;
    }
    set_collider_contact_low(arg0);
}

extern "C" {

s32 is_player_entity_id(u16 arg0) {
    return (u32)(arg0 - 0x1000) >> 0x1FU;
}

int TObjEneDD__sub_800BA804(u16 arg0) {
    u8 var_r3;
    var_r3 = 0;
    if ((arg0 >= 0x1000U) && (arg0 < 0x4000U)) {
        var_r3 = 1;
    }
    return var_r3;
}

u8 TObjEneDD::is_valid_target() {
    int var_r31;

    var_r31 = 0;
    if ((this != NULL) && (all_parents_unqueued_for_destruction__7TObjectFv() != 0) && !(this->actorFlags & 0x06040800)) {
        var_r31 = 1;
    }
    return (u8)var_r31;
}

s32 TObjEneDD::is_target_unobstructed(s32 arg1) {
    s32 arg0 = (s32)this;
    if ((((TObjBase *)arg0)->is_alive() != 0) && (csnLookAt((void *)arg1, (void *)(arg0 + 0x2FC)) == 0U)) {
        return 1;
    }
    return 0;
}

void TObjEneDD::transform_relative_position(void* a1) { is_target_unobstructed__9TObjEneDDFl(a1, (char*)this + 0x2fc, this); }

s32 TObjBase::is_alive() {
    int var_r31;

    var_r31 = 0;
    if ((this != NULL) && (all_parents_unqueued_for_destruction__7TObjectFv() != 0) && !(this->actorFlags & 0x02040800)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

int is_target_ranger(void* p) { return (((TObjPlayer *)p)->class_flags & CLASS_FLAG_RANGER) != 0; }

int is_target_android(void* p) { return (((TObjPlayer *)p)->class_flags & CLASS_FLAG_ANDROID) != 0; }

void TObjEneDD::setup_instance(s32 arg0, s32 arg1, u8 *arg2, s32 arg3) {
    ((TUnk_804928CC *)obj_ene_dd_instance)->sub_800BC3E8((u8 *)arg0);
    get_position__12TBoss1DragonFv(obj_ene_dd_instance, arg1);
    *(f32 *)((s8 *)(*(void **)((s8 *)obj_ene_dd_instance + 0xA4)) + 0xC) = (f32) *(f32 *)((s8 *)arg2 + 8);
    *(s32 *)((s8 *)(*(void **)((s8 *)obj_ene_dd_instance + 0xA4)) + 0x18) = 0x9D03;
    if (*(f32 *)((s8 *)arg2 + 8) > 100.0f) {
        ((EneDDObj_800BA138*)obj_ene_dd_instance)->m13(arg2 + 0xC, (void*)arg2, (void*)arg3);
        return;
    }
    ((EneDDObj_800BA138*)obj_ene_dd_instance)->m12(arg2 + 0xC, (void*)arg2, (void*)arg3);
}

void TObjEneDD::setup(void* p, int a1, int a2) { TObjEneDD::setup_instance((s32)p, (s32)a1, (u8 *)a2, 0); }

void TObjEneDD__sub_800BA5A4(void* p, void* a1) { TObjEneDD::setup_instance((s32)p, (s32)((char*)p + 0x38), (u8 *)a1, (s32)((void*)0)); }

void TObjEneDD::emit_enemy_effect(s32 arg0, s32 arg1, u8 *arg2, s32 arg3) {
    ((TUnk_804928CC *)obj_ene_dd_instance)->sub_800BC3E8((u8 *)arg0);
    get_position__12TBoss1DragonFv(obj_ene_dd_instance, arg1);
    *(f32 *)((s8 *)(*(void **)((s8 *)obj_ene_dd_instance + 0xA4)) + 0xC) = (f32) *(f32 *)((s8 *)arg2 + 8);
    *(s32 *)((s8 *)(*(void **)((s8 *)obj_ene_dd_instance + 0xA4)) + 0x18) = 0x9D03;
    if (*(f32 *)((s8 *)arg2 + 8) > 100.0f) {
        ((EneDDObj2_800BA138*)obj_ene_dd_instance)->m16(arg2 + 0xC, (void*)arg3);
        return;
    }
    ((EneDDObj2_800BA138*)obj_ene_dd_instance)->m15(arg2 + 0xC, (void*)arg3);
}

void TObjEneDD::emit_effect(void* p, int a1, int a2) { TObjEneDD::emit_enemy_effect((s32)p, (s32)a1, (u8 *)a2, 0); }

void TObjEneDD::emit_effect_at_position(void* a1) { TObjEneDD::emit_enemy_effect((s32)this, (s32)((char*)this + 0x38), (u8 *)a1, (s32)((void*)0)); }

void TObjEneDD__sub_800BA438(s32 arg0, u8 *arg1) {
    typedef char sp8_offset[(offsetof(Stack_800BA318, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800BA318, spC) == 0x4) ? 1 : -1];
    Stack_800BA318 stack = {0x12, 1.0f};
    ((VObj_18_0c879f *)(arg1))->m21(arg0, &stack.sp8, 0, -1, -1);
}

void TObjEneDD::inflict_poison(s32 arg0, u8 *arg1) {
    typedef char sp8_offset[(offsetof(Stack_800BA318, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800BA318, spC) == 0x4) ? 1 : -1];
    Stack_800BA318 stack = {0xF, 1.0f};
    ((VObj_18_0c879f *)(arg1))->m21(arg0, &stack.sp8, 0, -1, -1);
}

void TObjEneDD__sub_800BA378(s32 arg0, u8 *arg1) {
    typedef char sp8_offset[(offsetof(Stack_800BA318, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800BA318, spC) == 0x4) ? 1 : -1];
    Stack_800BA318 stack = {0x10, 1.0f};
    ((VObj_18_0c879f *)(arg1))->m21(arg0, &stack.sp8, 0, -1, -1);
}

void TObjEneDD::send_damage_message(s32 arg0, u8 *arg1) {
    typedef char sp8_offset[(offsetof(Stack_800BA318, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800BA318, spC) == 0x4) ? 1 : -1];
    Stack_800BA318 stack = {0x11, 1.0f};
    ((VObj_18_0c879f *)(arg1))->m21(arg0, &stack.sp8, 0, -1, -1);
}

int TObjEneDD::check_state_flag_1() { return add_flags_2e4__9TObjCharaFUl(this, 1); }

int TObjEneDD::check_state_flag_2() { return add_flags_2e4__9TObjCharaFUl(this, 2); }

int TObjEneDD::check_state_flag_4() { return add_flags_2e4__9TObjCharaFUl(this, 4); }

int TObjEneDD::set_state_8() { return add_flags_2e4__9TObjCharaFUl(this, 8); }

void TObjEneDD::vfunc_91() {
    Obj_800BA244 *self = (Obj_800BA244 *)this;
    s32 i;
    this->actorFlags |= 0x04000000;
    for (i = 0; i < self->count; i++) {
        self->parts[i].flags |= 0x02000000;
    }
}

void TObjEneDD::vfunc_92() {
    Obj_800BA200 *self = (Obj_800BA200 *)this;
    s32 i;
    this->actorFlags &= ~0x04000000;
    for (i = 0; i < self->count; i++) {
        self->parts[i].flags &= ~0x02000000;
    }
}

void TObjEneDD::vfunc_93() {
    O_800BA1C8 *self = (O_800BA1C8 *)this;
    s32 i;
    for (i = 0; i < self->count; i++) {
        self->entries[i].flags |= 1;
    }
}

void TObjEneDD::vfunc_94() {
    O_800BA190 *self = (O_800BA190 *)this;
    s32 i;
    for (i = 0; i < self->count; i++) {
        self->entries[i].flags &= ~1;
    }
}

void TObjEneDD::vfunc_95() {
    this->vfunc_91();
    this->vfunc_94();
    this->actorFlags = (s32) (this->actorFlags | 0x04040000);
}

void TObjEneDD::vfunc_96() {
    this->vfunc_92();
    this->vfunc_93();
    this->actorFlags = (s32) (this->actorFlags & 0xFBFBFFFF);
}

void TObjEneDD::vfunc_97() {
    Obj_800BA084 *self = (Obj_800BA084 *)this;
    s32 i;
    for (i = 0; i < self->count; i++) {
        set_collider_contact_high((u8 *)&self->parts[i]);
    }
}

void TObjEneDD::vfunc_98() {
    Obj_800BA030 *self = (Obj_800BA030 *)this;
    s32 i;
    for (i = 0; i < self->count; i++) {
        set_collider_contact_low((u8 *)&self->parts[i]);
    }
}

s32 TObjEneDD::vfunc_99() {
    return (u8)(((this->actorFlags & 0x10) - 0x10) == 0);
}

f32 TObjEneDD::calc_elapsed_scaled() {
    return 2.0f * (random_ratio__9TObjCharaFv() - 0.5f);
}

f32 TObjEneDD::rand_range(f32 farg0, f32 farg1) {
    return ((farg1 - farg0) * random_ratio__9TObjCharaFv()) + farg0;
}

s32 TObjEneDD::get_random_scaled() {
    return (s32) (65535.0f * random_ratio__9TObjCharaFv());
}

void TObjEneDD::initialize_enemy_state(s32 parameter) {
    set_param(parameter);
}

int TObjEneDD::update_camera_sequence() { return apply_split_screen_view_matrix__11TCameraCtrlFv(this); }

int TObjEneDD::get_camera_ctrl() { return transform_to_view__11TCameraCtrlFii(this); }

void TObjEneDD::reset_hp(u8 *base_stats, u8 *attack_stats, u8 *resistance_stats) {
    bind_enemy_combat_stats(base_stats, attack_stats, resistance_stats);
    referenceHp = hp;
}

void TObjEneDD::reload_stats_keep_hp_tp() {
    Obj_800B9E84 *self = (Obj_800B9E84 *)this;
    s16 a = this->hpmax;
    s16 c = this->hp;
    s16 b = this->tpmax;
    s16 d = *(s16 *)&this->tp;
    bind_enemy_combat_stats__9TObjEnemyFPUcPUcPUc(self);
    this->hpmax = a;
    this->hp = c;
    this->tpmax = b;
    *(s16 *)&this->tp = d;
}

int TObjEneDD::update_secondary_light() { return select_actor_lighting(this); }

int TObjEneDD::update_primary_light() { return restore_scene_lighting(this); }

void TObjEneDD::draw_oriented_shadow(s32 arg1, s32 arg2, u32 arg3) {
    s32 arg0 = (s32)this;
    Stack_800B9D94 stack;
    direction_to_rotation_xz((u8 *)arg1, (&stack.sp8), (&stack.sp10));
    push_matrix();
    post_translate_matrix((void *)arg0);
    translate_matrix(0, TObjEneDD__data_805D9E8C, 0.3f, TObjEneDD__data_805D9E8C);
    rotate_matrix_z(0, stack.sp10);
    rotate_matrix_x(0, stack.sp8);
    rotate_matrix_y(0, (void *)arg2);
    if (arg3 != 0U) {
        scale_current_matrix((void *)arg3);
    }
    rotate_matrix_x(0, -0x4000);
    draw_blob_shadow(0);
    pop_matrix();
}

void TObjEneDD::draw_ground_shadow(const Vec *scale, s32 forceDraw) {
    TObjEnemy::draw_ground_shadow(scale, forceDraw);
}

void TObjEneDD::clear_global_flag_400() { model_render_flags = (model_render_flags & 0xfffffbff); }

void TObjEneDD::vfunc_100() {
    if (!(this->actorFlags & 0x40800)) {
        minimap_render_dot((u8 *)&this->position, -0x5DB4, 1, 0);
    }
}

u8 TObjEneDD::is_main_phase_15() {
    return (u8) (get_main_phase() == 0xF);
}

u8 TObjEneDD::is_phase_e() {
    return (u8) (get_main_phase() == 0xE);
}

int TObjEneDD::update_lobby_state() { return is_local_client_floor_leader(this); }

int TObjEneDD::query_teammate_state() { return is_any_teammate_in_state__10TObjPlayerFv(this); }

void project_sound_origin_from_camera(s32 arg0, u8 *arg1, f32 farg0) {
    f32 temp_f1;
    VecCopy((Vec *)(arg1), (const Vec *)(arg0));
    subtract_vector((Vec *)arg1, (const Vec *)(camera_ctrl_instance + 0x178));
    { f32 s = ((TObjBoss2Tunnel *)arg1)->update_scale(); temp_f1 = s * farg0; }
    *(f32 *)((s8 *)arg1 + 0) = (f32) (*(f32 *)((s8 *)arg1 + 0) * temp_f1);
    *(f32 *)((s8 *)arg1 + 4) = (f32) (*(f32 *)((s8 *)arg1 + 4) * temp_f1);
    *(f32 *)((s8 *)arg1 + 8) = (f32) (*(f32 *)((s8 *)arg1 + 8) * temp_f1);
    vec3_add_to((Vec *)arg1, (const Vec *)(camera_ctrl_instance + 0x178));
}

int TObjEneDD::get_target_state_b() { return freeze_all_players__10TObjPlayerFv(this); }

int TObjEneDD::get_target_state_a() { return TObjPlayer__sub_801BA42C(this); }

s32 TObjEneDD::check_v2_mode() {
    if (((s32) enable_v2_features != 0) && ((s32) game_difficulty_selection == 3)) {
        return 1;
    }
    return 0;
}

s32 TObjEneDD::clamp_frame_index(s32 arg0) {
    s32 limit;
    s32 idx;

    idx = arg0;
    limit = 0xE;
    if (TObjEneDD::check_v2_mode() != 0) {
        limit = 0x1D;
    }
    if (idx < 0) {
        idx = 0;
    } else if (idx >= limit) {
        idx = limit - 1;
    }
    return idx;
}

void TObjEneDD__sub_800B9B24(void) {  }

void TObjEneDD::init_lights() { TObjLight__sub_801337F8((void*)current_scene_light); TObjLight__sub_801337FC((void*)lbl_805D555C); }

}

TObjEneDD_ST::TObjEneDD_ST(TObject *parent) : TObjEneDD(parent) {
    m_name = TObjEneDD_ST__name;
    enemy_clear_target__12TObjEneDD_STFUs(this);
    init_float_params();
    enemy_init_acquire_period(30);
    enemy_init_validate_period(30);
}

TObjEneDD_ST::~TObjEneDD_ST() {}

extern "C" {

void TObjEneDD::update_velocity() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f1;
    f32 temp_f2;

    temp_f2 = *(f32 *)((s8 *)arg0 + 0x394);
    *(f32 *)((s8 *)arg0 + 0x3A0) = (f32) (temp_f2 - *(f32 *)((s8 *)arg0 + 0x38));
    *(f32 *)((s8 *)arg0 + 0x3A4) = (f32) TObjEneDD__data_805D9E8C;
    temp_f1 = *(f32 *)((s8 *)arg0 + 0x39C);
    *(f32 *)((s8 *)arg0 + 0x3A8) = (f32) (temp_f1 - *(f32 *)((s8 *)arg0 + 0x40));
    *(f32 *)((s8 *)arg0 + 0x3AC) = normalize_vector_xz__FP3Vec(arg0 + 0x3A0, temp_f1, temp_f2);
}

}

void TObjEneDD_ST::init_float_params() { *(float*)((char*)this + 0x394) = TObjEneDD__data_805D9E8C; *(float*)((char*)this + 0x398) = TObjEneDD__data_805D9E8C; *(float*)((char*)this + 0x39c) = TObjEneDD__data_805D9E8C; *(float*)((char*)this + 0x3a0) = TObjEneDD__data_805D9E8C; *(float*)((char*)this + 0x3a4) = TObjEneDD__data_805D9E8C; *(float*)((char*)this + 0x3a8) = TObjEneDD__data_805D9E8C; *(float*)((char*)this + 0x3ac) = TObjEneDD__data_805D9E8C; }

extern "C" {

void enemy_set_target_id(Obj_800B9958 *self, u16 id) {
    self->id = id;
    if (id != 0xFFFF) {
        self->ptr = find_active_entity_by_id(self->id);
    } else {
        self->id = 0xFFFF;
        self->ptr = 0;
    }
}

void TObjEneDD_ST::set_target_player(void *player) {
    Obj_800B98D8 *self = (Obj_800B98D8 *)this;
    s32 n;
    s32 i;
    self->target_id = 0xFFFF;
    self->target = 0;
    n = TLobby::get_game_mode();
    for (i = 0; i < n; i++) {
        if (player == TObjPlayer::get_player_data(i)) {
            self->target_id = get_entity_id(player);
            self->target = player;
            return;
        }
    }
}

void TObjEneDD_ST::enemy_clear_target(u16 _w1) {
    ((O_800B98C0 *)this)->f390 = 0;
    ((O_800B98C0 *)this)->f38c = 0xFFFF;
}

void TObjEneDD_ST::enemy_init_acquire_period(s32 arg1) {
    *(s32 *)((s8 *)((u8 *)this) + 0x3B0) = (s32) (this->entity_id % arg1);
    *(s32 *)((s8 *)((u8 *)this) + 0x3B4) = arg1;
}

s32 TObjEneDD_ST::vfunc_104(f32 distance) { return select_nearest_target(distance); }

s32 enemy_bind_or_clear_target(void *self, u16 x) {
    if (x != 0xFFFF) {
        enemy_set_target_id((Obj_800B9958 *)(self), x);
        return 1;
    }
    enemy_clear_target__12TObjEneDD_STFUs(self);
    return 0;
}

s32 TObjEneDD_ST::select_and_apply_target(f32 farg0) {
    u16 temp_r3;
    u16 var_r4;

    if (this->vfunc_99() != 0) {
        temp_r3 = set_squared_value__9TObjEneDDFf(this, farg0);
        var_r4 = temp_r3;
        if (temp_r3 == 0xFFFF) {
            var_r4 = enemy_find_nearest_player_in_range((u8 *)this, farg0);
        }
    } else {
        var_r4 = enemy_find_nearest_player_in_range((u8 *)this, farg0);
    }
    return enemy_bind_or_clear_target(this, var_r4);
}

}

s32 TObjEneDD_ST::select_nearest_target(f32 distance) {
    u16 target = enemy_find_nearest_player_in_range((u8 *)this, distance);
    return enemy_bind_or_clear_target(this, target);
}

s32 TObjEneDD_ST::enemy_tick_target_acquisition(s32 *counter, s32 limit, f32 scale) {
    s32 var_r31;
    if (tick_period_counter((s32)this, counter, limit) != 0) {
        var_r31 = this->vfunc_104(scale);
    } else {
        var_r31 = enemy_has_live_target();
        if (var_r31 == 0) {
            enemy_clear_target__12TObjEneDD_STFUs(this);
        }
    }
    return var_r31;
}

s32 TObjEneDD_ST::update_linked_position(f32 scale) {
    return ((TObjEneDD_ST *)this)->enemy_tick_target_acquisition((s32 *)((u8 *)this + 0x3B0), *(s32 *)((s8 *)this + 0x3B4), scale);
}

void TObjEneDD_ST::enemy_copy_target_destination() {
    u32 temp_r4;
    temp_r4 = *(u32 *)((s8 *)((u8 *)this) + 0x390);
    if (temp_r4 != 0U) {
        set_target_destination((const Vec *)(temp_r4 + 0x38));
    }
}

void TObjEneDD::set_target_destination(const Vec *position) { VecCopy((Vec *)((char *)this + 0x394), position); }

void TObjEneDD_ST::enemy_init_validate_period(s32 arg1) {
    *(s32 *)((s8 *)((u8 *)this) + 0x3BC) = arg1;
    *(s32 *)((s8 *)((u8 *)this) + 0x3B8) = (s32) ((this->entity_id + 3) % *(s32 *)((s8 *)((u8 *)this) + 0x3BC));
}

s32 enemy_validate_retained_target(u8 *ene_dd_st) {
    if (tick_period_counter((s32)ene_dd_st, (s32 *)(ene_dd_st + 0x3B8), (*(s32 *)((s8 *)ene_dd_st + 0x3BC))) != 0) {
        if (transform_relative_position__9TObjEneDDFPv(ene_dd_st, (int) (*(s32 *)((s8 *)ene_dd_st + 0x390))) != 0) {
            return 1;
        }
        goto block_5;
    }
    if (((TObjEneDD_ST *)ene_dd_st)->enemy_has_live_target() != 0) {
        return 1;
    }
block_5:
    enemy_clear_target__12TObjEneDD_STFUs(ene_dd_st);
    return 0;
}

s32 TObjEneEpsilon::update_death_check() {
    if ((this->vfunc_99() == 0) && (is_player_entity_id(this->m_38c) == 0)) {
        enemy_clear_target__12TObjEneDD_STFUs(this);
        return 0;
    }
    return enemy_validate_retained_target((u8 *)this);
}

void TObjEneDD::turn_toward_target_direction(s32 arg1) {
    this->rotation_y = (s16) approach_angle_limited(this->rotation_y, (s32) (10430.38043493439 * atan2_float(*(f32 *)((s8 *)this + 0x3A0), *(f32 *)((s8 *)this + 0x3A8))), arg1);
}

void TObjEneEpsilon::fire_attack_c(s32 arg1, s32 arg2, f32 farg0) {
    f32 temp_f30;

    temp_f30 = farg0;
    turn_toward_target_direction(arg2);
    calc_shot_position__13TBoss5GryphonFPUcfff(this, arg1, sin_table_lookup(this->rotation_y), cos_table_lookup(this->rotation_y), temp_f30);
}

void TObjEneEpsilon::fire_attack_b(s32 arg1, s32 arg2, f32 farg0) {
    f32 dz;
    f32 dist;

    dist = farg0;
    turn_toward_target_direction(arg2);
    dz = cos_table_lookup(this->rotation_y);
    calc_wall_slide_destination((void *)this, (void *)arg1, (f32)(sin_table_lookup(this->rotation_y)), (f32)((f32)dz), (f32)((f32)dist));
}

void TObjEneEpsilon::fire_attack_a(s32 out, s32 arg2, f32 farg0) {
    f32 dist;

    dist = farg0;
    turn_toward_target_direction(arg2);
    calc_wall_clamped_destination((void *)this, (void *)out, (f32)(sin_table_lookup(this->rotation_y)), (f32)((f32)cos_table_lookup(this->rotation_y)), (f32)((f32)dist));
}

void TObjEneEpsilon__sub_800B9384(u8 *arg0, s32 arg1, f32 farg0) {
    s32 sp8;
    ((TObjEneEpsilon *)arg0)->fire_attack_c((s32) &sp8, arg1, farg0);
    ((TBoss5Gryphon *)arg0)->try_move_actor_xz_on_ground((u8 *)&sp8);
}

void enemy_turn_and_move_on_ground(u8 *arg0, s32 arg1, f32 farg0) {
    s32 sp8;
    ((TObjEneEpsilon *)arg0)->fire_attack_b((s32) &sp8, arg1, farg0);
    ((TBoss5Gryphon *)arg0)->try_move_actor_xz_on_ground((u8 *)&sp8);
}

extern "C" {

void TObjEneEpsilon__sub_800B92F8(u8 *ene_epsilon, s32 arg1, f32 farg0) {
    s32 sp8;
    ((TObjEneEpsilon *)ene_epsilon)->fire_attack_b((s32) &sp8, arg1, farg0);
    ((TObjEneEpsilon *)(ene_epsilon))->vfunc_101((u8 *)&sp8);
}

void TObjEneEpsilon__sub_800B92AC(u8 *ene_epsilon, s32 arg1, f32 farg0) {
    s32 sp8;
    ((TObjEneEpsilon *)ene_epsilon)->fire_attack_a((s32) &sp8, arg1, farg0);
    ((TObjEneEpsilon *)(ene_epsilon))->vfunc_101((u8 *)&sp8);
}

s32 TObjEneDD_ST::vfunc_83() {
    if ((is_player_entity_id(*(u16 *)((s8 *)this + 0x38C)) != 0) && (get_player_by_client_id(*(u16 *)((s8 *)this + 0x38C)) == 0U)) {
        enemy_clear_target__12TObjEneDD_STFUs(this);
    }
    TObjEneDD::vfunc_83();
}

s32 TObjEneDD_ST::enemy_check_target_valid() {
    u16 id = *(u16 *)((s8 *)this + 0x38C);
    if (id == 0xFFFF) {
        return 0;
    }
    if (find_entity_by_id(id) == 0U) {
        enemy_clear_target__12TObjEneDD_STFUs(this);
        return 0;
    }
    return is_valid_target__9TObjEneDDFv(*(s32 *)((s8 *)this + 0x390));
}

#pragma push
#pragma fp_contract on
s32 TObjEneDD_ST::enemy_has_live_target() {
    u32 id = *(u16 *)((s8 *)this + 0x38C);
    if (id == 0xFFFF) {
        return 0;
    }
    if (find_entity_by_id(id) == 0U) {
        enemy_clear_target__12TObjEneDD_STFUs(this);
        return 0;
    }
    return ((TObjBase *)(*(void **)((s8 *)this + 0x390)))->is_alive();
}
#pragma pop

}
