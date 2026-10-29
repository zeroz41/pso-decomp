#include "pso/player/PlayerAttackParams.h"
#include "pso/system/vector.h"
#include "pso/system/byteswap.h"
#include "pso/protocol/protocol_types.h"
#include "pso/misc/TLobby_801E43E4.h"
#include "types.h"
#include "pso/TObject.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/TObjMotion.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/player/TObjChara.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();
extern "C" void apply_switch_attack__9TObjCharaFv();
#include "pso/item/TItem.h"
extern "C" void apply_anti_technique__9TObjCharaFl();
#include "pso/enemy/TObjEneLappy.h"
#include "pso/player/DamageBookkeeping.h"
#include "dolphin/mtx.h"
#include <stddef.h>
#include "pso/effect/TEffClitical.h"

#include "pso/boss/TObjBoss2Tunnel.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TOCtrlDubchik.h"
#include "pso/map/FloorArea.h"

struct VBase_800172CC { u8 pad[0x18]; };

struct Player_800172CC : VBase_800172CC {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3(); virtual void m4();
    virtual void m5(); virtual void m6(); virtual void m7(); virtual void m8(); virtual void m9();
    virtual void m10(); virtual void m11(); virtual void m12(); virtual void m13(); virtual void m14();
    virtual void m15(); virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23(); virtual void m24();
    virtual void m25(); virtual void m26(); virtual void m27(); virtual void m28(); virtual void m29();
    virtual void m30(); virtual void m31(); virtual void m32(); virtual void m33(); virtual void m34();
    virtual void m35(); virtual void m36(); virtual void m37(); virtual void m38(); virtual void m39();
    virtual void m40(); virtual void m41(); virtual void m42(); virtual void m43(); virtual void m44();
    virtual void m45(); virtual void m46(); virtual void m47(); virtual void m48();
    u8 pad1c[0x254 - 0x1C];
    u8 f254[0xC];
    u8 f260[0xC];
};

struct Vec_800186E8 { f32 x, y, z; };

struct Motion_8001882C { s16 f0; s16 f2; s16 f4; s16 f6; s16 f8; s16 fa; s16 fc; u8 padE[0x18 - 0xE]; s32 f18; };

struct Player_8001882C {
    u8 pad0[0x2B0];
    Motion_8001882C *motion;
    u8 pad2B4[0x2B8 - 0x2B4];
    s16 f2b8;
    s16 f2ba;
    s16 f2bc;
    s16 f2be;
    s16 f2c0;
    s16 f2c2;
    s16 f2c4;
    s16 f2c6;
    s16 f2c8;
    s16 f2ca;
    s16 f2cc;
    s16 f2ce;
    s16 f2d0;
    s16 f2d2;
    u8 pad2D4[0x2E8 - 0x2D4];
    s16 f2e8;
    s16 f2ea;
    s16 f2ec;
    s16 f2ee;
    s16 f2f0;
    s16 f2f2;
    s16 f2f4;
    s16 f2f6;
    s16 f2f8;
    s16 f2fa;
    u8 pad2FC[0x32C - 0x2FC];
    s16 f32c;
    s16 f32e;
};

struct ObjFlags;
class TObjPlayer;
struct Info_8001311C { s32 type; f32 power; };

struct Vec_8001311C { f32 x, y, z; };

struct Coll_8001311C { u8 pad0[0x18]; u32 flags; Vec_8001311C pos; };

struct Stats_8001311C { s16 f0; s16 mst; };

struct VBase_8001311C { char pad[0x18]; };

struct Actor_8001311C : VBase_8001311C {
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
    virtual void m46(Coll_8001311C *);
    virtual void m47();
    virtual void m48();
    virtual void m49(Info_8001311C);
    virtual void m50(Info_8001311C);
    virtual void m51();
    virtual void m52();
    virtual void m53();
    virtual void m54(f32);
    virtual void m55(s32);
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
    virtual void m72(s32);
    virtual void m73();
    u16 f1c;
    u8 pad1E[0x30 - 0x1E];
    u32 flags30;
    u8 pad34[0x2B0 - 0x34];
    Stats_8001311C *stats;
    u8 pad2B4[0x2D4 - 0x2B4];
    u16 id;
    u8 pad2D6[0x2DC - 0x2D6];
    u32 f2dc;
    u8 pad2E0[0x2F2 - 0x2E0];
    s16 resist1;
    s16 resist3;
    s16 resist2;
    s16 resist5;
    s16 resist4;
    Vec_8001311C pos;
    u8 pad308[0x828 - 0x308];
    u8 f828[4];
};

typedef struct Vec_800114D8 { f32 x, y, z; } Vec_800114D8;

struct Vec_80011824 { f32 x, y, z; };

struct Rec_80011824 { s32 kind; f32 power; };

struct Stats_80011824 { u8 pad0[0xE]; s16 f0E; };

struct Coll_80011824 { u8 pad0[0x18]; u32 flags; Vec_80011824 pos; };

struct Base_80011824 { u8 pad0[0x18]; };

struct Actor_80011824 : Base_80011824 {
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
    virtual void m12(s32);
    virtual void m13(s32);
    virtual s32 m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20(void *, f32);
    virtual void m21(void *, Rec_80011824, void *, s32, s32);
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
    virtual void m46(s32);
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
    virtual void m72(s32);
    virtual void m73();
    u16 id;
    u8 pad1E[0x30 - 0x1E];
    u32 flags30;
    u8 pad34[0x2B0 - 0x34];
    Stats_80011824 *stats;
    u8 pad2B4[0x2D4 - 0x2B4];
    u16 f2D4;
    u8 pad2D6[0x2DC - 0x2D6];
    u32 f2DC;
    u8 pad2E0[0x2F2 - 0x2E0];
    s16 f2F2;
    s16 f2F4;
    s16 f2F6;
    s16 f2F8;
    u8 pad2FA[0x2FC - 0x2FA];
    Vec_80011824 pos;
};

struct VBase_80019038 { u8 pad[0x18]; };

struct Obj_80019038 : VBase_80019038 {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6();
};

struct Elem_80019038 { u8 pad[0xC]; };

struct Layout_80019038 {
    u8 pad0[0x110];
    u8 pairs[3][2];
    s16 f116;
    s16 f118;
    u8 pad11a[0x254 - 0x11A];
    Elem_80019038 elems[5];
};

extern "C" {
void spawn_slow_effect__10TObjPlayerFii(s32 arg0, s32 arg1);
void apply_slow_status__9TObjCharaFv(void *arg0);
void play_shock_feedback__10TObjPlayerFii(s32 arg0, s32 arg1);
s32 update_shock_clock__9TObjCharaFv(u8 *arg0);
u8 obj_isState2_324__9TObjCharaFv(u8* p);
s32 vfunc_43__9TObjCharaFv(Player_800172CC *self);
s32 VecCopy__FP3VecPC3Vec(s32, s32);
void subtract_vector(void *a, void *b);
f32 calc_xz_distance_sq(s32 arg0, u32 arg1, void *arg2);
s32 get_main_phase();
s32 check_heavy_damage_flag__9TObjCharaFf(void *arg0, f32 farg0);
void activate_switch_attacks__10TObjPlayerFii(s32 arg0, s32 arg1);
void attach_mine_trap__10TObjPlayerFiUi(s32 arg0, u32 arg1);
f32 random_ratio__9TObjCharaFv(s32 arg0);
s32 add_actor_hp(u8 *arg0, s16 arg1);
s32 TObjectV8047c128_subtract_hp(u8 *arg0, s16 arg1);
void trigger_switch_attack__10TObjPlayerFPvi(void *arg0, s32 arg1);
void try_apply_damage__9TObjCharaFUll(void *arg0, u32 arg1, s32 arg2);
u8 is_locally_controlled__10TObjPlayerFPv(u8 *arg0);
u8 obj_isState3_324__9TObjCharaFv(u8* p);
s32 get_type__10TObjPlayerFPv(void* p);
void create_hit_effect__10TObjPlayerFPv(void *);
f32 receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll(Actor_8001311C *self, Actor_8001311C *att, Info_8001311C *arg, Coll_8001311C *coll, s32 tech, s32 arg5);
u8 obj_is_hit_receivable(u8 *arg0);
int get_player_data__10TObjPlayerFi(int a0);
extern s32 registered_player_count;
extern s32 lbl_805D5870;
u16 find_nearest_hittable_enemy__10TObjPlayerFiPvf(s32 arg0, Vec_800114D8 *arg1, f32 farg0);
s32 try_spend_actor_meseta(u8 *arg0, s32 arg1);
s32 add_actor_tp(u8 *arg0, s32 arg1);
s32 damage_hp__10TObjPlayerFii(s32 arg0, s32 arg1);
void show_meseta_label(s32 arg0, u32 arg1, s32 arg2, s32 arg3);
void show_miss_popup__9TObjCharaFPCf(TObjPlayer *self, const float *pos);
s16 get_actor_tp(u8* p);
int obj_getPtr2B0_20(u8* p);
s16 obj_getS16_2BA(u8* p);
s16 get_actor_hp(u8* p);
u8 obj_testFlag_2E4__9TObjCharaFUl(u8* p, u32 mask);
int get_item_field_6__10TObjPlayerFPv(void* p);
void send_6x2F_change_player_hp(u16, u16, s16);
void dispatch_weapon_special_effect(void *, void *, void *, s32);
f32 receive_weapon_special_attack__9TObjCharaFPvPv(Actor_80011824 *self, Actor_80011824 *att, Coll_80011824 *coll);
void TObjPlayer__sub_8001951C(void* p);
void subtractive_rng_seed(void *, u16);
void __ct__14SubtractiveRngFv(void *);
void __ct__10TObjMotionFP7TObject(void *, void *);
void __construct_array(void *, void *, void *, u32, u32);
extern void *__vt__9TObjChara[];
Obj_80019038 *__ct__9TObjCharaFP7TObject(Obj_80019038 *self, void *parent);
}
void reset_status_effect_row(u8 *arg0);
s32 calc_freeze_chance(TObjPlayer *arg0, TObjPlayer *arg1, TObjPlayer *arg2, f32 farg0);
s32 calc_shock_chance(TObjPlayer *arg0, TObjPlayer *arg1, TObjPlayer *arg2);
void empty_post_damage_hook(void *defender, void *attacker);
void record_local_damage_if_enabled(void *arg0, void *arg1, s32 arg2);
void draw_hp_label(void *arg0, u32 arg1, s32 arg2, s16 arg3);
void obj_copyVec2_0(u8* d, u8* s);
f32 calc_technique_boost(s32, u16);
extern s32 game_difficulty_selection;
void display_exp_gain(s32 arg0, u32 arg1, s32 arg2, s32 arg3);
void show_tp_font(s32 arg0, u32 arg1, s32 arg2, s32 arg3);
s16 obj_getS16_118(u8* p);
typedef void (*SceneFn_8000FD54)(void);

typedef struct SceneEntry_8000FD54 {
    SceneFn_8000FD54 init;
    SceneFn_8000FD54 update;
    SceneFn_8000FD54 exit;
} SceneEntry_8000FD54;

typedef struct SceneState_8000FD54 {
    s32 cur;
    s32 next;
    s32 unk8;
    s32 unkC;
    s32 result;
    s32 prev;
} SceneState_8000FD54;

struct Stack_80010A84 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct Stack_80010B44 {
    s32 sp8;
    s32 spC;
    s32 sp10;
};

struct Pkt_80010C54 {
    u8 cmd;
    u8 size;
    u16 client;
    u16 target;
    u8 which;
    u8 amount;
};

struct Pkt_80010DE8 { u8 f0; u8 f1; u16 f2; u16 f4; u8 f6; u8 f7; };

struct Obj_80010DE8 { u8 pad[0x1c]; u16 f1c; };

struct RecoveredGlobal_80010E44_lbl_8050EA40
{
  s32 value;
  u8 remaining[0x2C];
};

typedef struct RecoveredGlobal_80010E44_lbl_8050EA40 RecoveredGlobal_80010E44_lbl_8050EA40;

typedef char RecoveredGlobal_80010E44_lbl_8050EA40_size[((sizeof(RecoveredGlobal_80010E44_lbl_8050EA40)) == 0x30) ? (1) : (-1)];

struct Obj_80010F54 { u8 pad[0x2D4]; u16 id; u16 id2; };

struct ActorMesetaView
{
  u8 padding[0x20];
  s32 meseta;
};

struct O_80011274 { u8 pad[0x2be]; s16 v; };

struct O_800112D4 { u8 pad[0x32e]; s16 v; };

struct O_80011378 { u8 pad[0x2bc]; s16 v; };

struct O_80011704 { u8 pad[0x1c]; u16 f1c; };

typedef struct Vec_800115C4 { f32 x, y, z; } Vec_800115C4;

typedef struct Player_800115C4 {
    u8 pad0[0x1C];
    u16 id;
    u8 pad1E[0x30 - 0x1E];
    s32 flags;
    u8 pad34[0x2FC - 0x34];
    Vec_800115C4 pos;
} Player_800115C4;

typedef struct Vec_8001401C { f32 x, y, z; } Vec_8001401C;

struct Obj_80014C1C { u8 pad0[0x30]; u32 f30; u8 pad34[0x254 - 0x34]; u8 f254[0x330 - 0x254]; u32 f330; };

struct O_80015D74 { u8 pad[0x110]; s16 arr[3]; };

struct O_80015DC4 { u8 pad[0x110]; s16 arr[3]; };

struct Base_800163F8 { char pad[0x18]; };

struct VObj_800163F8 : Base_800163F8 {
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
    virtual s32 m25();
};

struct Stack_80018780
{
  s32 sp8;
  u8 trailing_storage[0x8];
};

struct Stack_8001806C {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct RecoveredGlobal_8001806C_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };

typedef char RecoveredGlobal_8001806C_lbl_8058D490_size[sizeof(RecoveredGlobal_8001806C_lbl_8058D490) == 0x30 ? 1 : -1];

struct Vec_80018660 { f32 x, y, z; };

struct Obj_80018660 { u8 pad[0x38]; Vec_80018660 pos; u8 pad44[0x1c]; s32 angle; u8 pad64[0x238]; Vec_80018660 dest; };

struct Vec_80018570 { f32 x, y, z; };

struct Obj_80018570 { u8 pad[0x38]; Vec_80018570 pos; u8 pad44[0x1c]; s32 angle; u8 pad64[0x238]; Vec_80018570 dest; };

struct Vec_800180E8 { f32 x, y, z; };

struct Obj_800180E8 { u8 pad[0x308]; f32 vx; f32 vy; f32 vz; };

typedef struct Obj_80017804 {
    u8 pad0[0x38];
    Vec_800180E8 pos;
    u8 pad44[0x290 - 0x44];
    Vec_800180E8 home;
    Vec_800180E8 dest;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec_800180E8 cur;
    f32 vx;
    f32 vy;
    f32 vz;
} Obj_80017804;

typedef struct Obj_80017ABC {
    u8 pad0[0x38];
    Vec_800180E8 pos;
    u8 pad44[0x290 - 0x44];
    Vec_800180E8 home;
    Vec_800180E8 dest;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec_800180E8 cur;
} Obj_80017ABC;

typedef struct Vec_80018428 { f32 x, y, z; } Vec_80018428;

struct Vec_800182A0 { f32 x, y, z; };

struct Sub_800182A0 { u8 pad[0xC]; f32 fC; };

struct Obj_800182A0 {
    u8 pad0[0x3C];
    f32 f3C;
    u8 pad40[0xA4 - 0x40];
    Sub_800182A0 *fA4;
    u8 padA8[0x29C - 0xA8];
    Vec_800182A0 f29C;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec_800182A0 pos;
};

struct Obj_800182A0;

struct Vec_800182A0;

struct Vec_80017E6C
{
  f32 x;
  f32 y;
  f32 z;
};

struct Plane_80017E6C
{
  u8 pad0[0xC];
  f32 fC;
  f32 f10;
  f32 f14;
};

struct Hit_80017E6C
{
  s32 f0;
  Plane_80017E6C *plane;
};

struct Obj_80017E6C
{
  u8 pad0[0x38];
  Vec_80017E6C pos;
  Vec_80017E6C prev;
  u8 pad50[0x2FC - 0x50];
  Vec_80017E6C cur;
  Vec_80017E6C vel;
};

struct Vec_80017BA8 { f32 x, y, z; };

struct Vec_80016454 { f32 x, y, z; };

struct Body_80016454 {
    Vec_80016454 local;
    f32 radius;
    u8 pad10[0x8];
    u32 flags;
    u8 pad1c[0x10];
};

struct Base_80016454 { u8 pad[0x18]; };

struct Actor_80016454 : Base_80016454 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual s32 m24(Actor_80016454 *, s32, f32);
    u8 pad1c[0x38 - 0x1c];
    Vec_80016454 pos;
    u8 pad44[0x60 - 0x44];
    s32 yaw;
    u8 pad64[0xa4 - 0x64];
    Body_80016454 *bodies;
    s32 bodyCount;
};

struct RecoveredGlobal_8001806C_lbl_8058D490;

struct Vec_8001745C { f32 x, y, z; };

struct Part_8001745C {
    Vec_8001745C pos;
    f32 radius;
    u8 pad10[0x8];
    u32 flags;
    u8 pad1C[0x10];
};

struct Target_8001745C {
    u8 pad0[0x30];
    u32 flags30;
    u8 pad34[0x4];
    Vec_8001745C pos;
    u8 pad44[0x1C];
    s32 rotY;
    u8 pad64[0x40];
    Part_8001745C *parts;
    s32 nparts;
};

struct Player_8001745C {
    u8 pad0[0x38];
    Vec_8001745C pos;
    u8 pad44[0x1C];
    s32 rotY;
    u8 pad64[0x2A8 - 0x64];
    Target_8001745C *target;
    u8 pad2AC[0x318 - 0x2AC];
    u32 f318;
};

typedef s32 (*VecCopyFn_80016454)(void *, void *);

struct Obj_80018660;

typedef struct Hit_80017E6C Hit_80017E6C;

typedef struct Obj_80017E6C Obj_80017E6C;

typedef struct Plane_80017E6C Plane_80017E6C;

typedef struct Vec_80017E6C Vec_80017E6C;

struct Vec_80018428;

typedef struct Stack_80018780 Stack_80018780;

struct Stack_80018E6C {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct Stack_80018EE4 {
    f32 sp8;
    f32 spC;
    f32 sp10;
};

struct Vec_80018F64 { f32 x, y, z; };

struct Obj_80018F64 {
    u8 pad0[0x104]; Vec_80018F64 v104;
    u8 pad110[0x248 - 0x110]; f32 f248; f32 f24c; f32 f250;
    u8 pad254[0x290 - 0x254]; Vec_80018F64 v290; Vec_80018F64 v29c;
    u8 pad2a8[4]; s32 f2ac; u8 pad2b0[4]; f32 f2b4;
    u8 pad2b8[0x2d4 - 0x2b8]; u16 f2d4; u8 pad2d6[6]; s32 f2dc;
    u8 pad2e0[0x2fc - 0x2e0]; Vec_80018F64 v2fc; Vec_80018F64 v308;
    u8 pad314[0x320 - 0x314]; s32 f320; u8 pad324[4]; s16 f328; s16 f32a;
};

struct Rec800192C4 { s32 a; f32 b; s32 c; };

struct Obj800192C4 { u8 pad[0x254]; Rec800192C4 recs[1]; };

struct Word12 { int w; u8 _[8]; };

struct ObjArr254 { u8 _pad[0x254]; Word12 arr[1]; };

struct ObjArrFC  { u8 _pad[0xfc];  u16 arr[1];     };

struct ObjArr254_p53 { u8 _pad[0x25c]; Word12 arr[1]; };

struct R_800193FC { s32 a; f32 b; s32 c; };

struct O_800193FC { u8 pad[0x254]; R_800193FC recs[1]; };

struct R_8001940C { s32 a; f32 b; s32 c; };

struct O_8001940C { u8 pad[0x254]; R_8001940C recs[1]; };

struct R_8001941C { s32 a; f32 b; s32 c; };

struct O_8001941C { u8 pad[0x254]; R_8001941C recs[1]; };

struct R_800194AC { s32 a; f32 b; s32 c; };

struct O_800194AC { u8 pad[0x254]; R_800194AC recs[1]; };

struct ObjFlags {
    u8  _pad00[0x1c];
    u16 field_1c;
    u8  _pad1e[0x30 - 0x1e];
    u32 flags_30;
    u8  _pad34[0x96 - 0x34];
    u16 field_96;
};

struct O_80019664 { u8 f0; u8 f1; u8 pad[2]; u16 f4; u8 f6; u8 f7; };

struct O_80019828 { s32 arr[16]; };

struct Obj_80014B5C { u8 pad0[0x30]; u32 f30; u8 pad34[0x254 - 0x34]; u8 f254[0x330 - 0x254]; u32 f330; };

struct StatStatusReceipt_80014E74 { s32 kind; f32 power; };

typedef struct Elem_800162E0 {
    u8 pad0[0x18];
    s32 flags;
    u8 pad1C[0x2C - 0x1C];
} Elem_800162E0;

typedef struct Obj_800162E0 {
    u8 pad0[0x30];
    s32 flags30;
    u8 pad34[0xA4 - 0x34];
    Elem_800162E0 *elems;
    u8 padA8[0x2CC - 0xA8];
    s16 val2CC;
    u8 pad2CE[0x2DC - 0x2CE];
    s32 flags2DC;
} Obj_800162E0;

struct Motion_80018990 { s16 f0; s16 f2; s16 f4; s16 f6; s16 f8; s16 fa; s16 fc; u8 padE[0x18 - 0xE]; s32 f18; };

struct Bonus_80018990 { s16 f0; s16 f2; s16 f4; s16 f6; s16 f8; s16 fa; u8 padC[0x1C - 0xC]; s32 f1c; };

struct Player_80018990 {
    u8 pad0[0x2B0];
    Motion_80018990 *motion;
    u8 pad2B4[0x2B8 - 0x2B4];
    s16 f2b8;
    s16 f2ba;
    s16 f2bc;
    s16 f2be;
    s16 f2c0;
    s16 f2c2;
    s16 f2c4;
    s16 f2c6;
    s16 f2c8;
    s16 f2ca;
    s16 f2cc;
    s16 f2ce;
    s16 f2d0;
    s16 f2d2;
    u8 pad2D4[0x2F2 - 0x2D4];
    s16 f2f2;
    s16 f2f4;
    s16 f2f6;
    s16 f2f8;
    s16 f2fa;
    u8 pad2FC[0x318 - 0x2FC];
    void *f318;
    Bonus_80018990 *bonus;
    u8 pad320[0x32C - 0x320];
    s16 f32c;
    s16 f32e;
};

void shutdown_and_reset_system(void);
void init_game_systems(void);
extern "C" {
bool vfunc_29__9TObjCharaFv(u8 *arg0);
void TObjPlayer__sub_8000FF4C(void* p, s16 v);
void spawn_poison_effect__10TObjPlayerFii(s32 arg0, s32 arg1);
void TObjPlayer__sub_8001053C(u8 *arg0);
void add_id_to_slots__10TObjPlayerFiUs(s32 arg0, u16 arg1);
int vfunc_74__9TObjCharaFl(void);
void recalc_stats__9TObjCharaFv(void);
void enemy_spawn_zalure_effect__9TObjCharaFv(s32 arg0);
void enemy_spawn_jellen_effect__9TObjCharaFv(s32 arg0);
void handle_6x9A_update_entity_stat(Pkt_80010C54 *pkt);
void sub_80010DE8__9TObjCharaFUsUcUc(Obj_80010DE8 *self, u16 a, u8 b, u8 c);
void vfunc_78__9TObjCharaFl(void);
void vfunc_77__9TObjCharaFv(void);
void vfunc_76__9TObjCharaFv(void);
void vfunc_75__9TObjCharaFf(void);
u16 fn_80010F4C(void* p);
void record_attack_source(Obj_80010F54 *self, s32 id);
void vfunc_28__9TObjCharaFv(void);
s32 get_actor_level_index__9TObjCharaFv(void* p);
s32 consume_timer_field__9TObjCharaFl(u8 *arg0, s32 arg1);
s32 add_actor_exp__9TObjCharaFl(u8 *arg0, s32 arg1);
s32 add_actor_tp_bonus(O_80011274 *self, s32 x);
s32 add_actor_hp_bonus(O_80011378 *self, s32 x);
u16 find_nearest_visible_player(u8 *arg0, Vec_800115C4 *arg1, f32 farg0);
s32 is_actor_cadence_frame__9TObjCharaFl(O_80011704 *self, s32 x);
void apply_actor_gravity(TObjEnemy *arg0, s32 *arg1, f32 farg0);
void apply_knockback_from_attacker__9TObjCharaFPUcf(u8 *arg0, u8 *arg1);
int vfunc_67__9TObjCharaFf(void);
int vfunc_66__9TObjCharaFv(void);
void get_anim_node_position__9TObjCharaFlP3Vec(void);
void reset_pose__9TObjCharaFv(void* p);
void vfunc_63__9TObjCharaFv(void);
void vfunc_62__9TObjCharaFv(void);
void vfunc_61__9TObjCharaFv(void);
void vfunc_60__9TObjCharaFv(void);
void vfunc_59__9TObjCharaFv(void);
void vfunc_58__9TObjCharaFv(void);
void apply_action_hold_status__9TObjCharaFf(s32 arg0, f32 farg0);
void cure_poison_ailment__9TObjCharaFv(Obj_80014C1C *self);
s32 try_start_action__9TObjCharaFll(void *arg0, s32 arg1, s32 arg2);
s32 select_melee_contact_body__9TObjCharaFPvf(Actor_80016454 *target, Actor_80016454 *source, f32 factor);
s32 update_flag30_timer__9TObjCharaFv(u8 *arg0);
s32 vfunc_37__9TObjCharaFv(u8 *arg0);
s32 is_target_in_attack_range__9TObjCharaFv(Player_8001745C *p);
f32 step_toward_destination__10TObjPlayerFPvPvf(Obj_80017804 *arg0, Vec_800180E8 *arg1, f32 farg0);
f32 enemy_pursue_point(u8 *arg0, s32 arg1, Vec_800180E8 arg2, f32 farg0, f32 farg1);
f32 enemy_backstep_from_point(Obj_80017ABC *arg0, Vec_800180E8 arg1, f32 farg0);
void enemy_set_heading_velocity(TObjEnemy *arg0, s32 arg1, f32 farg0);
void calc_velocity_toward_destination(Obj_800180E8 *self, Vec_800180E8 *pos, Vec_800180E8 *dest, f32 speed);
s32 TObjPlayer__sub_800181DC(u8 *arg0, Vec_800180E8 arg1);
s32 select_enemy_destination(Obj_800182A0 *self, Vec_800182A0 *arg1, int flags);
s32 check_path_obstructed(u8 *arg0, Vec_80018428 *arg1);
s32 copy_position_if_valid__10TObjPlayerFii(s32 arg0, s32 arg1);
void enemy_turn_half_toward_dest(Obj_80018570 *self);
void enemy_turn_toward_dest(Obj_80018660 *self, s32 turn);
u8 * vfunc_18__9TObjCharaFPUc(u8 *arg0, u8 *arg1);
u8 * update_actor_ground_y__9TObjCharaFv(u8 *arg0);
void* get_center__9TObjCharaFv(void* p);
void reset_motion_fields__9TObjCharaFv(Obj_80018F64 *self);
void * __dt__9TObjCharaFv(void *arg0, s16 arg1);
void get_pos__9TObjCharaFl(s32 arg0, s32 arg1);
f32 TObjPlayer__sub_800192C4(Obj800192C4 *self, s32 i);
int obj_getArrWord_254(ObjArr254* p, int i);
void obj_setArrS16_FC(ObjArrFC* p, int i, s16 v);
u16 obj_getArrU16_FC(ObjArrFC* p, int i);
s16 get_actor_attack_params_atp_min__9TObjCharaFv(void* p);
s16 get_attack_params_atp_min(void* p);
void TObjPlayer__sub_800193FC(O_800193FC *self, s32 i, s32 v);
void TObjPlayer__sub_8001940C(O_8001940C *self, s32 i, s32 v);
void TObjPlayer__sub_8001941C(O_8001941C *self, s32 i, f32 v);
int TObjPlayer__sub_8001943C(ObjArr254_p53* p, int i);
s16 get_ata__10TObjPlayerFv(void* p);
s16 TObjPlayer__sub_800194E8(void* p);
s16 get_stats_atp_max__9TObjCharaFv(void* p);
s16 get_attack_params_atp_max(void* p);
void interact__14TObjCollidableFl(void* p, s16 v);
u32 obj_testFlags30__14TObjCollidableFUl(ObjFlags* p, u32 mask);
u16 get_entity_id(ObjFlags* p);
void obj_setFlags30(ObjFlags* p, u32 mask);
bool is_split_screen(void);
f32 calc_random_ratio__10TObjPlayerFv(void);
s32 get_current_floor(void);
f32 fabs_float(f32 x);
f32 atan2_float(f32 y, f32 x);
f32 newton_sqrtf(f32 x);
u32 csnLookAt(void *, void *);
u8 * csnVectorUnder(f32 *, void *, s32, void *, f32);
u32 csnVecterUnder(void *, int);
u32 csnVector(void *, void *, s32);
u32 subtractive_rng_next();
void create__10TObjPlayerFUiii(u32, s32, s32);
s32 spawn_particle_effect_with_flags(s32, s32, s32);
s32 set_owner_id__13TParticleCtrlFUs(s32, s32);
s32 draw_blob_shadow(void *);
s32 create_font_small_task(u32, s32, s32, s32, s32 *, s16, s32);
s32 create_font_small_task_default_color(u32, s32, s32, s32, s32 *, s16);
s32 create_damage_font__19TObjEneEpsilonGuardFllll(u32, s32, s32, s16);
f32 horizontal_distance_squared(void *, void *);
s32 angle_difference_abs(s32, s32);
s32 lerp_angle_half__10TObjPlayerFUsUs(s32, s32);
s32 approach_angle_limited(s32, s32, s32);
void __dt__10TObjMotionFv(void *, int);
void * find_entity_by_id(s32 id);
s32 project_actor_to_ground(s32, s32, s32);
s32 record_damage_stats__10TOMineTrapFUiUis(void *, void *, void *);
s32 get_player_by_client_id(s32);
int get_slot_value__10TObjPlayerFPvi(void*, int);
int bswap_16__FPUs(void*);
s32 play_sound_effect(s32, s32, s32, s32);
void __dl__7TObjectFPv(void *);
u32 __nw__7TObjectFUl(s32);
s32 construct_actor_light_task(f32, void *, void *, void *, s32, void *, s32);
s32 rand();
f64 atan2(f64 y, f64 x);
s32 vec3_add_to(void *, void *);
void matrix_mult_vec(s32, void *, void *);
s32 scale_matrix(int, f32, f32, f32);
void set_matrix_identity(s32);
f32 vec_squared_length(void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, void *);
s32 rotate_matrix_z(int, int);
s32 translate_matrix(int, f32, f32, f32);
s32 rotate_matrix_x(int, int);
s32 normalize_vector(void *);
s32 push_matrix_from(void *);
s32 push_matrix();
s32 pop_matrix();
void post_translate_matrix(void *);

extern s32 TObjPlayer__data_80434060[];
extern const f64 TObjPlayer__data_804340B8;
extern int TObjPlayer__data_8050D460[];
extern s32 player_attack_stat_status_light_colors[];
extern s32 player_defense_stat_status_light_colors[];
extern s16 lbl_8043406C[];
extern Vec_800115C4 lbl_80434074;
extern const f64 lbl_80434098;
extern const f64 lbl_804340A0;
extern u8 lbl_804340A8[];
extern s32 lbl_804340B0[];
extern SceneEntry_8000FD54 main_phase_table[];
extern SceneState_8000FD54 main_phase_state;
extern Vec_800182A0 scratch_vec;
extern RecoveredGlobal_80010E44_lbl_8050EA40 lobby_rule_settings;
extern RecoveredGlobal_8001806C_lbl_8058D490 identity_matrix;
extern s32 camera_split_screen_selector;
extern s32 actor_frame_tick;
extern s32 lobby_player_count;
extern s32 current_floor_index;
extern s32 tl_07;

extern "C" {
void obj_setField96_1(ObjFlags* p);
}

void main(void) {
    SceneFn_8000FD54 fn;
    SceneFn_8000FD54 update;

    init_game_systems();
    while (main_phase_state.cur != 0) {
        main_phase_state.result = 0;
        fn = main_phase_table[main_phase_state.cur].init;
        if (fn != NULL) {
            fn();
        }
        update = main_phase_table[main_phase_state.cur].update;
        while (main_phase_state.result == 0 && update != NULL) {
            update();
            actor_frame_tick++;
        }
        fn = main_phase_table[main_phase_state.cur].exit;
        if (fn != NULL) {
            fn();
        }
        switch (main_phase_state.result) {
        case 1:
        case 2:
        case 3:
            main_phase_state.prev = main_phase_state.cur;
            main_phase_state.cur = main_phase_state.next;
            break;
        }
    }
    shutdown_and_reset_system();
}

s32 TObjChara::check_heavy_damage_flag(f32 farg0) {
    if (((0.25f) * (f32) this->hpmax) < farg0) {
        this->actorFlags = (s32) (this->actorFlags | 0x400);
        return 1;
    }
    return 0;
}

int TObjChara::test_flag_1000() { return ((int (*)(void*, int))obj_testFlags30__14TObjCollidableFUl)(this, 4096); }

int TObjChara::has_flag_0x800() { return ((int (*)(void*, int))obj_testFlags30__14TObjCollidableFUl)(this, 2048); }

int TObjChara::test_flag30_512() { return ((int (*)(void*, int))obj_testFlags30__14TObjCollidableFUl)(this, 512); }

int TObjChara::test_flag_256() { return ((int (*)(void*, int))obj_testFlags30__14TObjCollidableFUl)(this, 256); }

bool TObjChara::vfunc_29() {
    return this->target == 0;
}

void TObjPlayer__sub_8000FF4C(void* p, s16 v) { *(s16*)((char*)p + 0x2d4) = v; }

u16 TObjPlayer::get_field_2d4() { return this->m_2d4; }

s32 TObjPlayer::is_local_player() {
    s32 arg0 = (s32)this;
    if (((u16 (*)(void*))get_entity_id)((void*)arg0) < 0x1000U) {
        return ((s32 (*)(s32))is_locally_controlled__10TObjPlayerFPv)(arg0);
    }
    return 0;
}

void activate_switch_attacks__10TObjPlayerFii(s32 arg0, s32 arg1) {
    if (((int (*)(void*, int))obj_testFlags30__14TObjCollidableFUl)((void*)arg0, 0x02000000) == 0) {
        spawn_particle_effect_with_flags(arg1, 0xB9, 0x40);
        spawn_particle_effect_with_flags(arg1, 0xBA, 0x40);
        ((s32 (*)(s32, s32))trigger_switch_attack__10TObjPlayerFPvi)(arg0, arg1);
    }
}

void TObjChara::spawn_freeze_shell_effect(u32 arg1, s32 arg2) {
    u32 temp_r4;
    if (((s32)((int (*)(void*, int))obj_testFlags30__14TObjCollidableFUl)(this, 0x02000000)) == 0) {
        if (arg1 != 0U) {
            create__10TObjPlayerFUiii((u32) this, (s32) arg1, 0x96);
        } else {
            temp_r4 = *(u32 *)&this->bodies;
            if (temp_r4 != 0U) {
                create__10TObjPlayerFUiii((u32) this, (s32) temp_r4, 0x96);
            }
        }
        if (arg2 != 0) {
            play_sound_effect(0xB20F, (s32)((u32) (((u8 *)this) + 0x38)), 0, 0);
        }
    }
}

void play_shock_feedback__10TObjPlayerFii(s32 arg0, s32 arg1) {
    s32 particle_effect_with_flags;
    if (((s32)((int (*)(void*, int))obj_testFlags30__14TObjCollidableFUl)((void*)arg0, 0x02000000)) == 0) {
        particle_effect_with_flags = spawn_particle_effect_with_flags(arg0 + 0x2FC, 0x21, 0x50);
        if (particle_effect_with_flags != 0) {
            set_owner_id__13TParticleCtrlFUs(particle_effect_with_flags, ((s32 (*)(void*))get_entity_id)((void*)arg0));
        }
        if (arg1 != 0) {
            play_sound_effect(0xB210, arg0 + 0x38, 0, 0);
        }
    }
}
}
void spawn_confusion_feedback_effect(s32 arg0, s32 arg1);
void spawn_paralysis_feedback_effect(s32 arg0, s32 arg1);
s32 is_entity_locally_controlled(s32 id);
void move_with_wall_slide(u8 *arg0);
void obj_clearArrS16_FC(ObjArrFC* p, int i);
f64 fabs_double(f64 x);
void *create_timed_particle_emitter_with_flags(void *pos, s32 id, s32 a, s32 b, s32 c);
void *create_oneshot_particle_emitter(void *pos, void *dir, s32 id, s32 flags);
void direction_to_rotation_xz(u8 *arg0, s32 *arg1, s32 *arg2);
void spawn_confusion_feedback_effect(s32 arg0, s32 arg1) {
    s32 particle_effect_with_flags;
    if (((s32)((int (*)(void*, int))obj_testFlags30__14TObjCollidableFUl)((void*)arg0, 0x02000000)) == 0) {
        particle_effect_with_flags = spawn_particle_effect_with_flags(arg0 + 0x2FC, 0x24, 0x50);
        if (particle_effect_with_flags != 0) {
            set_owner_id__13TParticleCtrlFUs(particle_effect_with_flags, ((s32 (*)(void*))get_entity_id)((void*)arg0));
        }
        if (arg1 != 0) {
            play_sound_effect(0xB20E, arg0 + 0x38, 0, 0);
        }
    }
}

void spawn_slow_effect__10TObjPlayerFii(s32 arg0, s32 arg1) {
    s32 particle_effect_with_flags;
    if (((s32)((int (*)(void*, int))obj_testFlags30__14TObjCollidableFUl)((void*)arg0, 0x02000000)) == 0) {
        particle_effect_with_flags = spawn_particle_effect_with_flags(arg0 + 0x2FC, 0x27, 0x50);
        if (particle_effect_with_flags != 0) {
            set_owner_id__13TParticleCtrlFUs(particle_effect_with_flags, ((s32 (*)(void*))get_entity_id)((void*)arg0));
        }
        if (arg1 != 0) {
            play_sound_effect(0xB20D, arg0 + 0x38, 0, 0);
        }
    }
}

void spawn_paralysis_feedback_effect(s32 arg0, s32 arg1) {
    s32 particle_effect_with_flags;
    if (((s32)((int (*)(void*, int))obj_testFlags30__14TObjCollidableFUl)((void*)arg0, 0x02000000)) == 0) {
        particle_effect_with_flags = spawn_particle_effect_with_flags(arg0 + 0x2FC, 0x26, 0x50);
        if (particle_effect_with_flags != 0) {
            set_owner_id__13TParticleCtrlFUs(particle_effect_with_flags, ((s32 (*)(void*))get_entity_id)((void*)arg0));
        }
        if (arg1 != 0) {
            play_sound_effect(0xB20C, arg0 + 0x38, 0, 0);
        }
    }
}

void spawn_poison_effect__10TObjPlayerFii(s32 arg0, s32 arg1) {
    s32 particle_effect_with_flags;
    if (((s32)((int (*)(void*, int))obj_testFlags30__14TObjCollidableFUl)((void*)arg0, 0x02000000)) == 0) {
        particle_effect_with_flags = spawn_particle_effect_with_flags(arg0 + 0x2FC, 0x25, 0x50);
        if (particle_effect_with_flags != 0) {
            set_owner_id__13TParticleCtrlFUs(particle_effect_with_flags, ((s32 (*)(void*))get_entity_id)((void*)arg0));
        }
        if (arg1 != 0) {
            play_sound_effect(0xCD0B, arg0 + 0x38, 0, 0);
        }
    }
}

s32 calc_freeze_chance(TObjPlayer *actor, TObjPlayer *arg1, TObjPlayer *arg2, f32 farg0) {
    f32 var_f31;

    var_f31 = farg0;
    if ((((u16 (*)(TObjPlayer *))get_entity_id)(arg1) >= 0x1000U) && (((u16 (*)(TObjPlayer *))get_entity_id)(arg1) < 0x4000U) && (((u16 (*)(TObjPlayer *))get_entity_id)(arg2) < 0x1000U)) {
        var_f31 = 0.75f - ((f32) ((TObjPlayer *)actor)->get_class_id() / 100.0f);
        if (var_f31 < 0.0f) {
            var_f31 = 0.0f;
        }
    } else if (((s32) game_difficulty_selection == 3) && ((0.2f) < var_f31)) {
        var_f31 = (0.2f);
    } else if ((0.4f) < var_f31) {
        var_f31 = (0.4f);
    }
    return random_ratio__9TObjCharaFv((s32) actor) < var_f31;
}

s32 calc_shock_chance(TObjPlayer *actor, TObjPlayer *arg1, TObjPlayer *arg2) {
    f32 var_f31;

    if ((((u16 (*)(TObjPlayer *))get_entity_id)(arg1) >= 0x1000U) && (((u16 (*)(TObjPlayer *))get_entity_id)(arg2) < 0x1000U)) {
        var_f31 = 0.75f - ((f32) ((TObjPlayer *)actor)->get_item_index() / 100.0f);
        if (var_f31 < 0.0f) {
            var_f31 = 0.0f;
        }
    } else if ((s32) game_difficulty_selection == 3) {
        var_f31 = (0.025f);
    } else {
        var_f31 = (0.06666667f);
    }
    return random_ratio__9TObjCharaFv((s32) actor) < var_f31;
}
extern "C" {

void TObjPlayer__sub_8001053C(u8 *arg0) {
    *(f32 *)((s8 *)arg0 + 0x310) = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0x30C) = (f32) (0.0f);
    *(f32 *)((s8 *)arg0 + 0x308) = (f32) (0.0f);
}

void TObjPlayer::apply_velocity() {
    this->position.x = (f32) (this->position.x + *(f32 *)&this->unk_308);
    this->position.y = (f32) (this->position.y + this->y_speed);
    this->position.z = (f32) (this->position.z + *(f32 *)&this->m_310);
}

s16 TObjPlayer::clamp_tp() {
    s16 temp_r0;
    s16 temp_r4;

    temp_r4 = *(s16 *)&this->tp;
    if (temp_r4 < 0) {
        *(s16 *)&this->tp = 0;
    } else {
        temp_r0 = *(s16 *)&this->tpmax;
        if (temp_r0 < temp_r4) {
            *(s16 *)&this->tp = temp_r0;
        }
    }
    return *(s16 *)&this->tp;
}

s16 TObjChara::clamp_hp() {
    s16 temp_r0;
    s16 temp_r4;

    temp_r4 = (this->hp);
    if (temp_r4 < 0) {
        (this->hp) = 0;
    } else {
        temp_r0 = (this->hpmax);
        if (temp_r0 < temp_r4) {
            (this->hp) = temp_r0;
        }
    }
    return (this->hp);
}

void TObjChara::apply_anti_technique(s32 arg1) {
    if (arg1 >= 0) {
        switch (((int (*)(void *, int))obj_getArrWord_254)(this, 0)) {
        case 0xF:
            this->actorFlags &= ~3;
            ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x254);
        }
    }
    if (arg1 >= 1) {
        switch (((int (*)(void *, int))obj_getArrWord_254)(this, 1)) {
        case 3:
            sub_800192B4((int)((f32)this->get_s16_2c4() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 1)));
            this->actorFlags &= ~0x3C;
            ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x260);
        }
    }
    if (arg1 >= 2) {
        switch (((int (*)(void *, int))obj_getArrWord_254)(this, 0)) {
        case 0x10:
            sub_800192B4((int)((f32)this->get_s16_2c4() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 0)));
            this->actorFlags &= ~3;
            ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x254);
        }
    }
    if (arg1 >= 3) {
        switch (((int (*)(void *, int))obj_getArrWord_254)(this, 1)) {
        case 0x12:
            this->actorFlags &= ~0x3C;
            ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x260);
        }
    }
    if (arg1 >= 4) {
        switch (((int (*)(void *, int))obj_getArrWord_254)(this, 1)) {
        case 0x11:
            this->actorFlags &= ~0x3C;
            ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x260);
        }
    }
    if (arg1 >= 5) {
        switch (((int (*)(void *, int))obj_getArrWord_254)(this, 2)) {
        case 0xB:
            this->add_to_field_2c8((int)((f32)this->get_field_2c0() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 2)));
            this->add_to_field_2ca((int)((f32)this->get_field_2c2() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 2)));
            ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x26C);
        }
        switch (((int (*)(void *, int))obj_getArrWord_254)(this, 3)) {
        case 0xC:
            this->add_to_field_2ce((int)((f32)this->get_atp() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 3)));
            ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x278);
        }
    }
    if (arg1 >= 6) {
        switch (((int (*)(void *, int))obj_getArrWord_254)(this, 1)) {
        case 2:
            sub_800192B4((int)((f32)this->get_s16_2c4() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 1)));
            this->actorFlags &= ~0x3C;
            ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x260);
        }
    }
    *(u32 *)(((u8 *)this) + 0x330) = this->actorFlags & 0x3F;
    obj_clearFlags30((u32)0x4000);
    ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x284);
}

void add_id_to_slots__10TObjPlayerFiUs(s32 arg0, u16 arg1) {
    s32 var_r30;

    var_r30 = 0;
loop_1:
    if (arg1 != ((u16 (*)(s32, s32))obj_getArrU16_FC)(arg0, var_r30)) {
        if (((u16 (*)(s32, s32))obj_getArrU16_FC)(arg0, var_r30) == 0xFFFF) {
            ((s32 (*)(s32, s32, u16))obj_setArrS16_FC)(arg0, var_r30, arg1);
            return;
        }
        var_r30 += 1;
        if (var_r30 >= 4) {

        } else {
            goto loop_1;
        }
    }
}

void TObjPlayer::clear_s16_arrays(void* p) { { int i; for (i = 0; i < 4; i++) { ((int (*)(void*, void*))obj_clearArrS16_FC)(p, (void*)i); } } }

s32 TObjChara::vfunc_74(s32) { return 0; }

void TObjChara::recalc_stats() {}

void TObjChara::enemy_spawn_zalure_effect() {
    Stack_80010A84 stack;
    s32 oneshot_particle_emitter;
    s32 arg0 = (s32)this;
    stack.spC = 0;
    stack.sp8 = 0;
    stack.sp10 = -0x8000;
    oneshot_particle_emitter = (s32)create_oneshot_particle_emitter((void *)(arg0 + 0x2FC), &stack.sp8, 0x1FE, 0x50);
    if (oneshot_particle_emitter != 0) {
        set_owner_id__13TParticleCtrlFUs(oneshot_particle_emitter, (s32)((void *) (((s32 (*)(s32))get_entity_id)(arg0))));
    }
}

void TObjChara::trigger_switch_attack() {
    s32 particle_effect_with_flags;

    particle_effect_with_flags = spawn_particle_effect_with_flags((s32)this + 0x2FC, 0x1FE, 0x50);
    if (particle_effect_with_flags != 0) {
        set_owner_id__13TParticleCtrlFUs(particle_effect_with_flags, ((s32 (*)(TObjChara *))get_entity_id)(this));
    }
}

void TObjChara::enemy_spawn_jellen_effect() {
    Stack_80010B44 stack;
    s32 oneshot_particle_emitter;
    s32 arg0 = (s32)this;
    stack.spC = 0;
    stack.sp8 = 0;
    stack.sp10 = -0x8000;
    oneshot_particle_emitter = (s32)create_oneshot_particle_emitter((void *)(arg0 + 0x2FC), &stack.sp8, 0x1FD, 0x50);
    if (oneshot_particle_emitter != 0) {
        set_owner_id__13TParticleCtrlFUs(oneshot_particle_emitter, (s32)((void *) (((s32 (*)(s32))get_entity_id)(arg0))));
    }
}

void TObjChara::apply_switch_attack() {
    s32 particle_effect_with_flags;
    s32 arg0 = (s32)this;

    particle_effect_with_flags = spawn_particle_effect_with_flags(arg0 + 0x2FC, 0x1FD, 0x50);
    if (particle_effect_with_flags != 0) {
        set_owner_id__13TParticleCtrlFUs(particle_effect_with_flags, ((s32 (*)(s32))get_entity_id)(arg0));
    }
}
}

s32 is_entity_locally_controlled(s32 id) {
    void *p;
    if ((u16)id == 0xFFFF || (u16)id >= 0x1000) {
        return 0;
    }
    p = find_entity_by_id(id);
    if (p == 0) {
        return 0;
    }
    return ((s32 (*)(void *))is_locally_controlled__10TObjPlayerFPv)(p);
}

void handle_6x9A_update_entity_stat(Pkt_80010C54 *pkt) {
    s16 v;
    s32 player;
    s32 amount;
    if (pkt == NULL) {
        return;
    }
    ((TObjPlayer *)pkt)->bswap_head16();
    if (pkt->client >= 0x1000U) {
        return;
    }
    player = get_player_by_client_id(pkt->client);
    if (player == 0) {
        return;
    }
    amount = pkt->amount;
    switch (pkt->which) {
    case 0: {
        v = amount;
        ((s32 (*)(s32, s16))TObjectV8047c128_subtract_hp)(player, v);
        if (((s32 (*)(u16))is_entity_locally_controlled)(pkt->target) != 0) {
            ((s32 (*)(s32, s32, s32, s16))draw_hp_label)(player, player + 0x2FC, 0xA, v);
        } else {
            ((s32 (*)(s32, s32, s32, s16))draw_hp_label)(player, player + 0x2FC, 0xA, -amount);
        }
        break;
    }
    case 1: {
        v = amount;
        ((TObjChara *)player)->subtract_actor_tp((s32)v);
        if (((s32 (*)(u16))is_entity_locally_controlled)(pkt->target) != 0) {
            ((s32 (*)(s32, s32, s32, s16))show_tp_font)(player, player + 0x2FC, 0xA, v);
        } else {
            ((s32 (*)(s32, s32, s32, s16))show_tp_font)(player, player + 0x2FC, 0xA, -amount);
        }
        break;
    }
    case 2:
        ((s32 (*)(s32, s32))try_spend_actor_meseta)(player, amount);
        ((s32 (*)(s32, s32, s32, s16))show_meseta_label)(player, player + 0x2FC, 0xA, -amount);
        break;
    case 3: {
        v = amount;
        ((s32 (*)(s32, s16))add_actor_hp)(player, v);
        ((s32 (*)(s32, s32, s32, s16))draw_hp_label)(player, player + 0x2FC, 0xA, v);
        ((TObjPlayer *)player)->spawn_recovery_effect();
        break;
    }
    case 4: {
        v = amount;
        ((s32 (*)(s32, s16))add_actor_tp)(player, v);
        ((s32 (*)(s32, s32, s32, s16))show_tp_font)(player, player + 0x2FC, 0xA, v);
        ((TObjPlayer *)player)->spawn_recovery_effect();
        break;
    }
    }
}

void TObjChara::sub_80010DE8(u16 a, u8 b, u8 c) {
    Pkt_80010DE8 pkt;
    ((TObjPlayer *)(&pkt))->init_packet_9a();
    pkt.f2 = ((Obj_80010DE8 *)this)->f1c;
    pkt.f4 = a;
    pkt.f6 = b;
    pkt.f7 = c;
    ((TObjPlayer *)(&pkt))->send_head();
}

void empty_post_damage_hook(void *defender, void *attacker) {  }

#pragma push
#pragma opt_pointer_analysis on
void record_local_damage_if_enabled(void *mine_trap, void *arg1, s32 arg2) {
  if ((((((TLobby *)(&lobby_rule_settings.value))->get_rule_field_0() == 1) && (((int (*)(void *))is_locally_controlled__10TObjPlayerFPv)(mine_trap) != 0)) && (arg2 > 0)) && (arg1 != NULL))
  {
    record_damage_stats__10TOMineTrapFUiUis((void *) mine_trap, (void *) arg1, (void *) arg2);
  }
}
#pragma pop
extern "C" {

void TObjChara::vfunc_78(s32) {  }

void TObjChara::vfunc_77() {  }

void TObjChara::vfunc_76() {  }

void TObjChara::vfunc_75(f32) {  }

void assign_slots_from_list(void *arg0, s32 arg1) {
    s32 var_r31;

    if (arg1 != 0) {
        if (((s32 (*)(void))is_split_screen)() != 0) {
            var_r31 = 0;
            do {
                ((s32 (*)(void *, s32))add_id_to_slots__10TObjPlayerFiUs)(arg0, ((s32 (*)(s32, s32))obj_getArrU16_FC)(arg1, var_r31));
                var_r31 += 1;
            } while (var_r31 != 4);
            return;
        }
        if (*(u16 *)((s8 *)arg0 + 0x2D6) == 0xFFFF) {
            *(u16 *)((s8 *)arg0 + 0x2D6) = fn_80010F4C((void*)arg1);
        }
    }
}

u16 fn_80010F4C(void* p) { return *(u16*)((char*)p + 0x2d6); }

void record_attack_source(Obj_80010F54 *self, s32 id) {
    if ((u16)id != 0xFFFF) {
        self->id = id;
        if (self->id < 0x1000 && is_entity_locally_controlled(self->id) != 0) {
            if (((s32 (*)(void))is_split_screen)() == 0) {
                self->id2 = self->id;
            } else {
                ((s32 (*)(void *, s32))add_id_to_slots__10TObjPlayerFiUs)(self, id);
            }
        }
    }
}

void attach_mine_trap__10TObjPlayerFiUi(s32 arg0, u32 arg1) {
    if (arg1 != 0U) {
        ((int (*)(void*, void*))record_attack_source)((void*)arg0, (void*)(((s32 (*)(u32))get_entity_id)(arg1)));
    }
}

void TObjChara::vfunc_28() {  }

f32 TObjChara::random_ratio() {
    if (get_main_phase() == 0xE) {
        return (3.0517578e-05f) * (f32) rand();
    }
    return ((f32 (*)(s32))calc_random_ratio__10TObjPlayerFv)((s32)this + 0x160);
}

extern const f32 lbl_805D7D3C = 65536.0f;

void TObjEnemy::render_with_position_override(u8 *arg1, s32 arg2) {
    u8 *arg0 = (u8 *)this;
    s32 spC;
    s32 sp8;

    push_matrix();
    direction_to_rotation_xz((u8 *)&this->m_248, &spC, &sp8);
    translate_matrix(0, (f32) (*(f32 *)&(*(void * *)((u8 *)this + 0x38))), (f32) ((0.3f) + *(f32 *)((s8 *)arg0 + 0x3C)), (f32) ((*(f32 *)((u8 *)this + 0x40))));
    rotate_matrix_z(0, sp8);
    rotate_matrix_x(0, spC);
    ((s32 (*)(int, int))rotate_matrix_y)(0, (int) ((this->rotation_y)));
    rotate_matrix_x(0, -0x4000);
    if (arg1 != NULL) {
        scale_matrix(0, (f32) (*(f32 *)((s8 *)arg1 + 0)), (f32) (*(f32 *)((s8 *)arg1 + 8)), (f32) ((1.0f)));
    }
    draw_blob_shadow((void *)arg2);
    pop_matrix();
}

s32 try_spend_actor_meseta(u8 *arg0, s32 arg1) {
    s32 temp_r0;
    u8 *temp_r5;
    temp_r5 = *(u8 **)((s8 *)arg0 + 0x2B0);
    temp_r0 = *(s32 *)((s8 *)temp_r5 + 0x20);
    if (temp_r0 < arg1) {
        return 0;
    }
    *(s32 *)((s8 *)temp_r5 + 0x20) = (s32) (temp_r0 - arg1);
    return 1;
}

s32 TObjPlayer::add_meseta(s32 amount) {
  TObjPlayer* self = this;
  s32 limit = 999999;
  int maximum;
  ((ActorMesetaView *) self->m_2b0)->meseta += amount;
  maximum = limit;
  if (maximum < ((ActorMesetaView *) self->m_2b0)->meseta)
  {
    ((ActorMesetaView *) self->m_2b0)->meseta = maximum;
    return 0;
  }
  return 1;
}

s32 TObjChara::get_actor_level_index() { return *(s32*)((char*)this->m_2b0 + 0x18); }

s32 TObjPlayer::add_capped_counter_999(s32 arg1) {
    this->m_11a = (s16) (this->m_11a + arg1);
    if ((s16) this->m_11a > 0x3E7) {
        this->m_11a = 0x3E7;
        return 0;
    }
    return 1;
}

s32 TObjChara::consume_timer_field(s32 arg1) {
    u8 *temp_r4;
    u8 *temp_r5;
    temp_r5 = this->m_2b0;
    *(s32 *)((s8 *)temp_r5 + 0x1C) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x1C) - arg1);
    temp_r4 = this->m_2b0;
    if ((s32) *(s32 *)((s8 *)temp_r4 + 0x1C) < 0) {
        *(s32 *)((s8 *)temp_r4 + 0x1C) = 0;
        return 0;
    }
    return 1;
}

s32 TObjChara::add_actor_exp(s32 arg1) {
  u8 *temp_r3;
  int new_var;
  u8 *temp_r6;
  temp_r6 = this->m_2b0;
  *((s32 *) (((s8 *) temp_r6) + 0x1C)) = (s32) ((*((s32 *) (((s8 *) temp_r6) + 0x1C))) + arg1);
  temp_r3 = this->m_2b0;
  new_var = 0x05F5E0FF;
  if (new_var < ((s32) (*((s32 *) (((s8 *) temp_r3) + 0x1C)))))
  {
    *((s32 *) (((s8 *) temp_r3) + 0x1C)) = new_var;
    return 0;
  }
  return 1;
}

int TObjPlayer::get_tp_materials_clamped() {
    u8 *arg0 = (u8 *)this;
  int new_var;
  s16 temp_r0;
  new_var = 0xFFFFu;
  temp_r0 = (unsigned long) (*((s16 *) (((s8 *) arg0) + (((((0x2BE & new_var) & new_var) & new_var) & new_var) & new_var))));
  if (temp_r0 < 0)
  {
    return 0U;
  }
  if (temp_r0 <= 0xFA)
  {
    return (u8) temp_r0;
  }
  return 0xFAU;
}

s32 add_actor_tp_bonus(O_80011274 *self, s32 x) {
    self->v += x;
    if (self->v < 0) {
        self->v = 0;
        return 0;
    }
    return 1;
}

s32 add_actor_tp(u8 *arg0, s32 arg1) {
    s16 temp_r4;
    *(s16 *)((s8 *)arg0 + 0x32E) = (s16) (*(s16 *)((s8 *)arg0 + 0x32E) + arg1);
    if (*(s16 *)((s8 *)arg0 + 0x32E) > *(s16 *)((s8 *)arg0 + 0x2BA)) {
        *(s16 *)((s8 *)arg0 + 0x32E) = *(s16 *)((s8 *)arg0 + 0x2BA);
        return 0;
    }
    return 1;
}

s32 TObjChara::subtract_actor_tp(s32 x) {
    ((O_800112D4 *)this)->v -= x;
    if (((O_800112D4 *)this)->v < 0) {
        ((O_800112D4 *)this)->v = 0;
        return 0;
    }
    return 1;
}

s32 check_can_act__10TObjPlayerFii(s32 arg0, s32 arg1) {
    if (((s32 (*)(void))obj_isState2_324__9TObjCharaFv)() != 0) {
        return 0;
    }
    return ((TObjChara *)arg0)->subtract_actor_tp(arg1);
}

int TObjPlayer::get_hp_material_points() {
  s16 temp_r0;
  int new_var;
  new_var = this->hp_bonus;
  temp_r0 = new_var;
  if (temp_r0 < 0)
  {
    return 0U;
  }
  if (temp_r0 <= 0xFA)
  {
    return (u8) temp_r0;
  }
  return 0xFAU;
}

s32 add_actor_hp_bonus(O_80011378 *self, s32 x) {
    self->v += x;
    if (self->v < 0) {
        self->v = 0;
        return 0;
    }
    return 1;
}

s32 TObjPlayer::clamp_hp_value(s16 *arg1) {
    s16 temp_r0;
    s16 temp_r5;
    temp_r5 = *arg1;
    if (temp_r5 < 0) {
        *arg1 = 0;
        return 0;
    }
    temp_r0 = this->hpmax;
    if (temp_r5 > temp_r0) {
        *arg1 = temp_r0;
        return 0;
    }
    return 1;
}

void TObjPlayer::set_hp_clamped(s16 arg1) {
    u8 *arg0 = (u8 *)this;
    this->hp = arg1;
    clamp_hp_value((s16 *)(arg0 + 0x32C));
}

#pragma push
#pragma scheduling off
s32 add_actor_hp(u8 *arg0, s16 arg1) {
    s16 temp_r4;
    s16 temp_r0;
    if (arg1 < 0) {
        return 0;
    }
    *(s16 *)((s8 *)arg0 + 0x32C) = (s16) (*(s16 *)((s8 *)arg0 + 0x32C) + arg1);
    if (*(s16 *)((s8 *)arg0 + 0x32C) > *(s16 *)((s8 *)arg0 + 0x2B8)) {
        *(s16 *)((s8 *)arg0 + 0x32C) = *(s16 *)((s8 *)arg0 + 0x2B8);
        return 0;
    }
    return 1;
}
#pragma pop

s32 TObjectV8047c128_subtract_hp(u8 *arg0, s16 arg1) {
  if (arg1 < 0)
  {
    return 0;
  }
  *((s16 *) (((s8 *) arg0) + 0x32C)) = (s16) ((*((s16 *) (((s8 *) arg0) + 0x32C))) - arg1);
  if ((*((s16 *) (((s8 *) arg0) + 0x32C))) < 0)
  {
    *((s16 *) (((s8 *) arg0) + 0x32C)) = 0;
    return 0;
  }
  return 1;
}

s32 damage_hp__10TObjPlayerFii(s32 arg0, s32 arg1) {
    if (((s32 (*)(void))obj_isState2_324__9TObjCharaFv)() != 0) {
        return 0;
    }
    return ((int (*)(void*, void*))TObjectV8047c128_subtract_hp)((void*)arg0, (void*)arg1);
}

u16 find_nearest_hittable_enemy__10TObjPlayerFiPvf(s32 arg0, Vec_800114D8 *arg1, f32 farg0) {
    Vec_800114D8 pos;
    f32 best;
    f32 dist;
    u16 result;
    s32 i;
    ObjFlags *p;
    best = farg0 * farg0;
    result = 0xFFFF;
    for (i = registered_player_count; i < registered_player_count + lbl_805D5870; i++) {
        p = ((ObjFlags * (*)(s32))get_player_data__10TObjPlayerFi)(i);
        if (p == NULL) {
            break;
        }
        if (((s32 (*)(ObjFlags *))obj_is_hit_receivable)(p) != 0) {
            u16 id = get_entity_id(p);
            if (id >= 0x1000 && id < 0x4000 && !(p->flags_30 & 0x02000800)) {
                dist = ((f32 (*)(s32, ObjFlags *, void *))calc_xz_distance_sq)(arg0, p, &pos);
                if (dist < best) {
                    best = dist;
                    result = p->field_1c;
                    if (arg1 != NULL) {
                        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg1, &pos);
                    }
                }
            }
        }
    }
    return result;
}

u16 find_nearest_visible_player(u8 *arg0, Vec_800115C4 *arg1, f32 farg0) {
    f32 best = farg0 * farg0;
    u16 result = 0xFFFF;
    Vec_800115C4 diff = lbl_80434074;
    f32 dist;
    Player_800115C4 *player;
    s32 i;
    for (i = 0; i < registered_player_count; i++) {
        player = ((Player_800115C4 * (*)(s32))get_player_data__10TObjPlayerFi)(i);
        if (player != NULL && player->id < 0x1000 && !(player->flags & 0x02000800)) {
            if (((TObjPlayer *)player)->get_field_3e4() == get_current_floor()) {
                ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&diff, &player->pos);
                ((s32 (*)(void *, void *))subtract_vector)(&diff, arg0 + 0x2FC);
                dist = (diff.x * diff.x) + (diff.z * diff.z);
                if (dist < best && ((s32 (*)(void *, void *))check_path_obstructed)(arg0, &player->pos) == 0) {
                    best = dist;
                    result = player->id;
                    if (arg1 != NULL) {
                        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg1, &diff);
                    }
                }
            }
        }
    }
    return result;
}

s32 TObjChara::is_actor_cadence_frame(s32 x) {
    s32 g = actor_frame_tick % x;
    if ((((O_80011704 *)this)->f1c % x) == g) {
        return 1;
    }
    return 0;
}

void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 farg0) {
    Vec position;
    f32 temp_f1;
    s32 temp_r31;
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&position.x, (u8 *)enemy + 0x38);
    temp_r31 = ((s32 (*)(void *, void *, void *))project_actor_to_ground)(enemy, &position.x, (u8 *)enemy + 0x248);
    if (arg1 != NULL) {
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg1, &position.x);
    }
    if (temp_r31 != 0) {
        *(f32 *)((s8 *)enemy + 0x30C) += (-0.10888889f);
        *(f32 *)((s8 *)enemy + 0x3C) = (f32) (*(f32 *)((s8 *)enemy + 0x3C) + *(f32 *)((s8 *)enemy + 0x30C));
        temp_f1 = position.y + farg0;
        position.y = temp_f1;
        if (*(f32 *)((s8 *)enemy + 0x3C) <= temp_f1) {
            *(f32 *)((s8 *)enemy + 0x3C) = temp_f1;
            *(f32 *)((s8 *)enemy + 0x30C) = (f32) (0.0f);
            enemy->actorFlags = (s32) (enemy->actorFlags | 0x800000);
            return;
        }
        enemy->actorFlags = (s32) (enemy->actorFlags & 0xFF7FFFFF);
        return;
    }
    enemy->actorFlags = (s32) (enemy->actorFlags & 0xFF7FFFFF);
}

#pragma push
#pragma fp_contract on
#define TEST30(o, m) ((s32 (*)(Actor_8001311C *, u32))obj_testFlags30__14TObjCollidableFUl)(o, m)
#define SET30(o, m) ((void (*)(Actor_8001311C *, u32))obj_setFlags30)(o, m)
#define FIELD1C(o) ((u16 (*)(Actor_8001311C *))get_entity_id)(o)
#define STATE2(o) ((s32 (*)(Actor_8001311C *))obj_isState2_324__9TObjCharaFv)(o)
#define STATE3(o) ((s32 (*)(Actor_8001311C *))obj_isState3_324__9TObjCharaFv)(o)
#define LOCAL(o) ((s32 (*)(Actor_8001311C *))is_locally_controlled__10TObjPlayerFPv)(o)
#define VECCOPY(d, s) ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(d, s)
#define HIT(o, p) ((void (*)(Actor_8001311C *, Vec_8001311C *, s32))try_apply_damage__9TObjCharaFUll)(o, p, 0)
#define DAMAGE(o, p, d) ((void (*)(Actor_8001311C *, Vec_8001311C *, s32))try_apply_damage__9TObjCharaFUll)(o, p, d)
#define SWITCH_ATTACK(o, p) ((void (*)(Actor_8001311C *, Vec_8001311C *))trigger_switch_attack__10TObjPlayerFPvi)(o, p)
#define SUB_HP(o, d) ((s32 (*)(Actor_8001311C *, s32))TObjectV8047c128_subtract_hp)(o, d)

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
struct TObjPlayer;
struct Obj_80010DE8;
struct O_800112D4;
#define VECCOPY_W24(d, s) ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((d), (s))
#define FIELD1C_W24(p) ((u16 (*)(void *))get_entity_id)(p)
#define TESTF30_W24(p, m) ((s32 (*)(void *, u32))obj_testFlags30__14TObjCollidableFUl)((p), (m))
#define SETF30_W24(p, m) ((void (*)(void *, u32))obj_setFlags30)((p), (m))
#define ISSTATE2_W24(p) ((s32 (*)(void *))obj_isState2_324__9TObjCharaFv)(p)
#define ISLOCAL_W24(p) ((s32 (*)(void *))is_locally_controlled__10TObjPlayerFPv)(p)
#define MISS_W24(s, v) ((void (*)(void *, void *))show_miss_popup__9TObjCharaFPCf)((s), (v))
#define APPLYDMG_W24(s, v, d) ((void (*)(void *, void *, s32))try_apply_damage__9TObjCharaFUll)((s), (v), (d))
#define DISPATCH_W24(a, s, v) dispatch_weapon_special_effect((a), (s), (v), 1)
#define SUB10DE8_W24(p, id, k, v) ((void (*)(void *, u16, s32, s32))sub_80010DE8__9TObjCharaFUsUcUc)((p), (id), (k), (v))
#define SUBHP_W24(p, v) ((s32 (*)(void *, s32))TObjectV8047c128_subtract_hp)((p), (v))
#define ADDHP_W24(p, v) ((s32 (*)(void *, s32))add_actor_hp)((p), (v))
#define SUBTP_W24(p, v) ((TObjChara *)p)->subtract_actor_tp((s32)((v)))
#define ADDTP_W24(p, v) ((s32 (*)(void *, s32))add_actor_tp)((p), (v))
#define HPLABEL_W24(p, v, k, n) ((void (*)(void *, void *, s32, s32))draw_hp_label)((p), (v), (k), (n))
#define TPFONT_W24(p, v, k, n) ((void (*)(void *, void *, s32, s32))show_tp_font)((p), (v), (k), (n))
#define BOSS4_W24(p) ((f32 (*)(void *))random_ratio__9TObjCharaFv)(p)
#define CLEARCOLL_W24() if (coll != NULL) { coll->flags &= ~0x04000000; }
typedef unsigned int RangedU;
typedef struct { float x,y,z; } RangedVec;
typedef struct {
    unsigned char before_flags[0x30]; RangedU flags;
    unsigned char before_position[4]; RangedVec position;
    unsigned char before_evp[0x2cc-0x44]; short evp;
    unsigned char before_hit_flags[0x2dc-0x2ce]; RangedU hit_flags;
} RangedActor;
typedef struct { unsigned char prefix[0x18]; RangedU flags; RangedVec center; float defense; } RangedBody;
struct Obj_80014108;

extern "C" {
void run_task__7TObjectFv(void);
void render__7TObjectFv(void);
void render_shadows__7TObjectFv(void);
void vfunc_6__8TObjBaseFPsl(void);
void apply_object_set_data__8TObjBaseFPv(void);
void update_object_view_visibility__8TObjBaseFff(void);
void classify_actor_view_detail__8TObjBaseFfff(void);
void get_name__8TObjBaseFv(void);
int calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf(RangedActor* target,RangedActor* attacker,RangedBody* body,const RangedVec* origin,float multiplier);
f32 receive_physical_attack__9TObjCharaFPvf(Obj_80014108 *self, Obj_80014108 *att, f32 scale);
s32 roll_physical_accuracy__9TObjCharaFPvlf(Obj_800162E0 *arg0, void *arg1, s32 arg2, f32 farg0);
s32 update_poison_status__9TObjCharaFv(u8 *arg0);
s32 update_action_hold_status__9TObjCharaFv(u8 *arg0);
s32 update_movement_status__9TObjCharaFv(u8 *arg0);
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
void apply_defense_stat_status__9TObjCharaFPv(void *arg0, void *arg1);
void trigger_switch_attack__9TObjCharaFv(void *arg0);
void apply_poison_status__9TObjCharaFv(void *arg0);
void apply_paralysis__9TObjCharaFv(u8 *arg0);
void apply_confusion_status__9TObjCharaFv(void *arg0);
void apply_movement_ailment__9TObjCharaFl(u8 *arg0, s32 arg1);
void apply_shock_status__9TObjCharaFv(u8 *arg0);
void clear_harmful_statuses__9TObjCharaFv(u8 *arg0);
void apply_attack_stat_status__9TObjCharaFPv(TObjPlayer *arg0, StatStatusReceipt_80014E74 *arg1);
void cure_paralysis__9TObjCharaFv(Obj_80014B5C *self);
void clear_all_status_effects__9TObjCharaFv(u8 *arg0);

void *__vt__9TObjChara[] = {
    0,
    0,
    (void *)__dt__9TObjCharaFv,
    (void *)run_task__7TObjectFv,
    (void *)render__7TObjectFv,
    (void *)render_shadows__7TObjectFv,
    (void *)vfunc_6__8TObjBaseFPsl,
    (void *)apply_object_set_data__8TObjBaseFPv,
    (void *)reset_motion_fields__9TObjCharaFv,
    (void *)get_center__9TObjCharaFv,
    (void *)update_object_view_visibility__8TObjBaseFff,
    (void *)classify_actor_view_detail__8TObjBaseFfff,
    (void *)get_name__8TObjBaseFv,
    (void *)interact__14TObjCollidableFl,
    (void *)add_actor_exp__9TObjCharaFl,
    (void *)consume_timer_field__9TObjCharaFl,
    (void *)get_actor_level_index__9TObjCharaFv,
    (void *)update_actor_ground_y__9TObjCharaFv,
    (void *)vfunc_18__9TObjCharaFPUc,
    (void *)is_actor_cadence_frame__9TObjCharaFl,
    (void *)select_melee_contact_body__9TObjCharaFPvf,
    (void *)calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf,
    (void *)receive_physical_attack__9TObjCharaFPvf,
    (void *)receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)receive_weapon_special_attack__9TObjCharaFPvPv,
    (void *)apply_knockback_from_attacker__9TObjCharaFPUcf,
    (void *)try_start_action__9TObjCharaFll,
    (void *)roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)vfunc_28__9TObjCharaFv,
    (void *)vfunc_29__9TObjCharaFv,
    (void *)is_target_in_attack_range__9TObjCharaFv,
    (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv,
    (void *)&has_flag_0x800__9TObjCharaFv,
    (void *)&test_flag_1000__9TObjCharaFv,
    (void *)update_poison_status__9TObjCharaFv,
    (void *)update_action_hold_status__9TObjCharaFv,
    (void *)vfunc_37__9TObjCharaFv,
    (void *)update_flag30_timer__9TObjCharaFv,
    (void *)update_movement_status__9TObjCharaFv,
    (void *)update_shock_clock__9TObjCharaFv,
    (void *)update_attack_stat_status__9TObjCharaFv,
    (void *)update_defense_stat_status__9TObjCharaFv,
    (void *)vfunc_43__9TObjCharaFv,
    (void *)apply_poison_status__9TObjCharaFv,
    (void *)apply_paralysis__9TObjCharaFv,
    (void *)apply_slow_status__9TObjCharaFv,
    (void *)apply_confusion_status__9TObjCharaFv,
    (void *)apply_movement_ailment__9TObjCharaFl,
    (void *)apply_shock_status__9TObjCharaFv,
    (void *)clear_harmful_statuses__9TObjCharaFv,
    (void *)apply_attack_stat_status__9TObjCharaFPv,
    (void *)apply_defense_stat_status__9TObjCharaFPv,
    (void *)cure_poison_ailment__9TObjCharaFv,
    (void *)cure_paralysis__9TObjCharaFv,
    (void *)clear_all_status_effects__9TObjCharaFv,
    (void *)apply_action_hold_status__9TObjCharaFf,
    (void *)apply_anti_technique__9TObjCharaFl,
    (void *)vfunc_58__9TObjCharaFv,
    (void *)vfunc_59__9TObjCharaFv,
    (void *)vfunc_60__9TObjCharaFv,
    (void *)vfunc_61__9TObjCharaFv,
    (void *)vfunc_62__9TObjCharaFv,
    (void *)vfunc_63__9TObjCharaFv,
    (void *)reset_pose__9TObjCharaFv,
    (void *)get_anim_node_position__9TObjCharaFlP3Vec,
    (void *)vfunc_66__9TObjCharaFv,
    (void *)vfunc_67__9TObjCharaFf,
    (void *)get_pos__9TObjCharaFl,
    (void *)apply_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_jellen_effect__9TObjCharaFv,
    (void *)trigger_switch_attack__9TObjCharaFv,
    (void *)enemy_spawn_zalure_effect__9TObjCharaFv,
    (void *)recalc_stats__9TObjCharaFv,
    (void *)vfunc_74__9TObjCharaFl,
    (void *)vfunc_75__9TObjCharaFf,
    (void *)vfunc_76__9TObjCharaFv,
    (void *)vfunc_77__9TObjCharaFv,
    (void *)vfunc_78__9TObjCharaFl,
};
}

f32 TObjChara::receive_weapon_special_attack(void *attacker, void *collision) {
    Rec_80011824 rec;
    Vec_80011824 pos;
    s16 kind;
    s16 power;
    s32 blocked;
    s32 immune;
    f32 dmg;
    f32 mul;
    f32 cap;
    f32 amt;
    f32 chance;
    Coll_80011824 *coll = (Coll_80011824 *)collision;
    Actor_80011824 *att = (Actor_80011824 *)attacker;
    Actor_80011824 *self = (Actor_80011824 *)this;
    if (coll != NULL) {
        VECCOPY_W24(&pos, &coll->pos);
    } else {
        VECCOPY_W24(&pos, &self->pos);
    }
    if (att == NULL) {
        return (0.0f);
    }
    if (FIELD1C_W24(att) == 0xFFFF) {
        return (0.0f);
    }
    kind = ((TObjPlayer *)att)->obj_getS16_116();
    power = ((s16 (*)(void *))obj_getS16_118)(att);
    blocked = 0;
    if (TESTF30_W24(self, 0x04000000) != 0) {
        blocked = 1;
    }
    if (coll != NULL && (coll->flags & 0x02000000)) {
        blocked = 1;
    }
    if (blocked != 0) {
        switch (kind) {
        case 0:
            break;
        case 1:
        case 2:
        case 5:
        case 6:
        case 7:
        case 9:
        case 10:
            APPLYDMG_W24(self, &pos, 0);
            break;
        case 3:
        case 4:
        case 8:
        case 11:
        case 12:
        case 13:
            MISS_W24(self, &pos);
            break;
        }
        CLEARCOLL_W24()
        return (0.0f);
    }
    ((void (*)(void *, void *))attach_mine_trap__10TObjPlayerFiUi)(self, att);
    if (ISSTATE2_W24(self) != 0) {
        immune = 1;
    } else if (ISSTATE2_W24(att) != 0) {
        if (ISLOCAL_W24(self) != 0 && get_type__10TObjPlayerFPv((void*)((u8 *)att + 0x828)) != 0) {
            immune = 0;
        } else {
            immune = 1;
        }
    } else {
        immune = 0;
    }
    if (game_difficulty_selection == 3 && self->f2D4 < 0x1000 && ((s32 (*)(void *, s32))obj_testFlag_2E4__9TObjCharaFUl)(att, 4) != 0 &&
        kind != 11 && kind != 9 && kind != 10) {
        power += 30;
    }
    dmg = (0.0f);
    rec.kind = 0;
    rec.power = dmg;
    if (self->f2D4 < 0x1000) {
        void *item = ((void *(*)(void *))get_item_field_6__10TObjPlayerFPv)(att);
        if (item == NULL) {
            mul = (1.0f);
        } else {
            switch (((TItem *)item)->get_item_group()) {
            case 2:
            case 3:
            case 4:
                mul = (0.5f);
                break;
            case 5:
            case 8:
            case 9:
                mul = (0.33f);
                break;
            default:
                mul = (1.0f);
                break;
            }
        }
    } else {
        mul = (1.0f);
    }
    switch (kind) {
    case 1:
        dmg = (0.01f) * (f32)(power * ((s16 (*)(void *))get_actor_hp)(self));
        cap = (3e+01f) * (game_difficulty_selection + 1);
        if (cap < dmg) {
            dmg = cap;
        }
        dmg *= mul;
        if (dmg < (1.0f)) {
            dmg = (1.0f);
        }
        if (TObjPlayer::get_player_count() != 0) {
            if (ISLOCAL_W24(self) != 0 && ISSTATE2_W24(att) != 0) {
                SUB10DE8_W24(att, self->f2D4, 3, (s32)dmg);
                SUB10DE8_W24(self, self->f2D4, 0, (s32)dmg);
                self->m20(att, (0.6f));
            } else if (ISSTATE2_W24(self) == 0 || FIELD1C_W24(att) >= 0x1000) {
                if (ISLOCAL_W24(att) != 0) {
                    SUB10DE8_W24(att, self->f2D4, 3, (s32)dmg);
                    HPLABEL_W24(self, &pos, 10, (s32)dmg);
                    SUBHP_W24(self, (s32)dmg);
                } else if (ISSTATE2_W24(att) == 0) {
                    ADDHP_W24(att, (s32)dmg);
                    DISPATCH_W24(att, self, &pos);
                    SUBHP_W24(self, (s32)dmg);
                }
                self->m20(att, (0.6f));
            }
        } else {
            if (ISLOCAL_W24(att) != 0) {
                SUB10DE8_W24(att, self->f2D4, 3, (s32)dmg);
                HPLABEL_W24(self, &pos, 10, (s32)dmg);
                SUBHP_W24(self, (s32)dmg);
            } else if (ISSTATE2_W24(att) == 0) {
                ADDHP_W24(att, (s32)dmg);
                DISPATCH_W24(att, self, &pos);
                SUBHP_W24(self, (s32)dmg);
            }
            self->m20(att, (0.6f));
        }
        if (((TObjChara *)self)->clamp_hp() <= 0) {
            SETF30_W24(self, 0xA00);
            empty_post_damage_hook(self, att);
        } else {
            SETF30_W24(self, 0x200);
        }
        if (TESTF30_W24(self, 0x02000000) == 0) {
            create_hit_effect__10TObjPlayerFPv(&pos);
        }
        break;
    case 2:
        if (((s32 (*)(void *, s32))obj_testFlag_2E4__9TObjCharaFUl)(att, 4) != 0) {
            dmg = (0.0f);
            CLEARCOLL_W24()
        } else {
            dmg = (0.01f) * (f32)(power * ((s16 (*)(void *))obj_getS16_2BA)(att));
            cap = (25.0f) * (game_difficulty_selection + 1);
            if (cap < dmg) {
                dmg = cap;
            }
            dmg *= mul;
            if (dmg < (1.0f)) {
                dmg = (1.0f);
            }
            if (TObjPlayer::get_player_count() != 0) {
                if (ISLOCAL_W24(self) != 0 && ISSTATE2_W24(att) != 0) {
                    SUB10DE8_W24(att, self->f2D4, 4, (s32)dmg);
                    SUB10DE8_W24(self, self->f2D4, 1, (s32)dmg);
                    self->m20(att, (0.6f));
                } else if (ISSTATE2_W24(self) == 0 || FIELD1C_W24(att) >= 0x1000) {
                    if (ISLOCAL_W24(att) != 0) {
                        SUB10DE8_W24(att, self->f2D4, 4, (s32)dmg);
                        TPFONT_W24(self, &pos, 10, (s32)dmg);
                        SUBTP_W24(self, (s32)dmg);
                    } else if (ISSTATE2_W24(att) == 0) {
                        ADDTP_W24(att, (s32)dmg);
                        DISPATCH_W24(att, self, &pos);
                        SUBTP_W24(self, (s32)dmg);
                    }
                    self->m20(att, (0.6f));
                }
            } else {
                if (ISLOCAL_W24(att) != 0) {
                    SUB10DE8_W24(att, self->f2D4, 4, (s32)dmg);
                    TPFONT_W24(self, &pos, 10, (s32)dmg);
                    SUBTP_W24(self, (s32)dmg);
                } else if (ISSTATE2_W24(att) == 0) {
                    ADDTP_W24(att, (s32)dmg);
                    DISPATCH_W24(att, self, &pos);
                    SUBTP_W24(self, (s32)dmg);
                }
                self->m20(att, (0.6f));
            }
        }
        SETF30_W24(self, 0x200);
        if (TESTF30_W24(self, 0x02000000) == 0) {
            create_hit_effect__10TObjPlayerFPv(&pos);
        }
        break;
    case 3:
        if (is_boss_area() != 0) {
            CLEARCOLL_W24()
        } else if (self->id < 0x1000) {
            dmg = (0.0f);
            MISS_W24(self, &pos);
            CLEARCOLL_W24()
        } else {
            dmg = (0.01f) * (f32)(power * ((TObjChara *)self)->obj_getPtr2B0_1C());
            cap = (2e+01f) * (game_difficulty_selection + 1);
            if (cap < dmg) {
                dmg = cap;
            }
            dmg *= mul;
            if (dmg < (1.0f)) {
                dmg = (1.0f);
            }
            if (immune == 0) {
                if (ISLOCAL_W24(self) != 0) {
                    self->m13((s32)dmg);
                }
                att->m12((s32)dmg);
            }
            SETF30_W24(self, 0x200);
            DISPATCH_W24(att, self, &pos);
            if (TESTF30_W24(self, 0x02000000) == 0) {
                create_hit_effect__10TObjPlayerFPv(&pos);
                ((void (*)(void *, void *, s32, s32))display_exp_gain)(self, &pos, 10, (s32)dmg);
            }
        }
        self->m20(att, (0.6f));
        break;
    case 4: {
        f32 cost = (2e+02f);
        if (TESTF30_W24(self, 0x02000000) == 0) {
            DISPATCH_W24(att, self, &pos);
        }
        if (cost <= (f32)((s32 (*)(void *))obj_getPtr2B0_20)(att)) {
            if (TObjPlayer::get_player_count() != 0) {
                if (ISLOCAL_W24(self) != 0 && ISSTATE2_W24(att) != 0) {
                    SUB10DE8_W24(att, self->f2D4, 2, (s32)cost);
                    self->m20(att, (3.0f));
                } else if (ISSTATE2_W24(self) == 0 || FIELD1C_W24(att) >= 0x1000) {
                    ((s32 (*)(void *, s32))try_spend_actor_meseta)(att, (s32)cost);
                    ((void (*)(void *, void *, s32, s32))show_meseta_label)(att, &att->pos, 0, (s32)-cost);
                    self->m20(att, (3.0f));
                }
            } else {
                if (immune == 0) {
                    ((s32 (*)(void *, s32))try_spend_actor_meseta)(att, (s32)cost);
                    ((void (*)(void *, void *, s32, s32))show_meseta_label)(att, &att->pos, 0, (s32)-cost);
                }
                self->m20(att, (3.0f));
            }
        } else {
            self->flags30 |= 0x100;
            MISS_W24(self, &pos);
            CLEARCOLL_W24()
        }
        dmg = (0.0f);
        break;
    }
    case 5:
        if (TESTF30_W24(self, 0x02000000) == 0) {
            DISPATCH_W24(att, self, &pos);
        }
        amt = (0.2f) * (f32)((s16 (*)(void *))get_actor_tp)(att);
        if ((1e+01f) <= (f32)((s16 (*)(void *))get_actor_tp)(att)) {
            if (TObjPlayer::get_player_count() != 0) {
                if (ISLOCAL_W24(self) != 0 && ISSTATE2_W24(att) != 0) {
                    SUB10DE8_W24(att, self->f2D4, 1, (s32)amt);
                    self->m20(att, (3.0f));
                } else if (ISSTATE2_W24(self) == 0 || FIELD1C_W24(att) >= 0x1000) {
                    SUBTP_W24(att, (s32)amt);
                    self->m20(att, (3.0f));
                }
            } else {
                SUBTP_W24(att, (s32)amt);
                self->m20(att, (3.0f));
            }
        } else {
            self->flags30 |= 0x100;
            MISS_W24(self, &pos);
            CLEARCOLL_W24()
        }
        dmg = (0.0f);
        break;
    case 6:
        if (TESTF30_W24(self, 0x02000000) == 0) {
            DISPATCH_W24(att, self, &pos);
        }
        amt = (0.25f) * (f32)((s16 (*)(void *))get_actor_hp)(att);
        if ((1.0f) < (f32)((s16 (*)(void *))get_actor_hp)(att)) {
            if (TObjPlayer::get_player_count() != 0) {
                if (ISLOCAL_W24(self) != 0 && ISSTATE2_W24(att) != 0) {
                    SUB10DE8_W24(att, self->f2D4, 0, (s32)amt);
                    self->m20(att, (3.0f));
                } else if (ISSTATE2_W24(self) == 0 || FIELD1C_W24(att) >= 0x1000) {
                    SUBHP_W24(att, (s32)amt);
                    self->m20(att, (3.0f));
                }
            } else {
                ((s32 (*)(void *, s32))damage_hp__10TObjPlayerFii)(att, (s32)amt);
                if (ISLOCAL_W24(att) != 0) {
                    u16 id = FIELD1C_W24(att);
                    send_6x2F_change_player_hp(id, id, ((s16 (*)(void *))get_actor_hp)(att));
                }
                self->m20(att, (3.0f));
            }
        } else {
            self->flags30 |= 0x100;
            MISS_W24(self, &pos);
            CLEARCOLL_W24()
        }
        dmg = (0.0f);
        break;
    case 7:
        chance = mul * ((0.01f) * (f32)(power - self->stats->f0E));
        if (chance < (0.0f)) {
            chance = (0.0f);
        }
        if (((s32 (*)(void *, void *, void *, f32))calc_freeze_chance)(self, att, self, chance) != 0) {
            if (TESTF30_W24(self, 0x02000000) == 0) {
                create_hit_effect__10TObjPlayerFPv(&pos);
                DISPATCH_W24(att, self, &pos);
            }
            if (immune == 0) {
                self->m46(0);
                self->m20(att, (0.6f));
            }
        } else {
            MISS_W24(self, &pos);
            CLEARCOLL_W24()
        }
        dmg = (0.0f);
        break;
    case 8:
        if (BOSS4_W24(self) < mul * ((0.01f) * (f32)(power - self->stats->f0E))) {
            if (TESTF30_W24(self, 0x02000000) == 0) {
                create_hit_effect__10TObjPlayerFPv(&pos);
                DISPATCH_W24(att, self, &pos);
            }
            if (immune == 0) {
                if (self->id >= 0x1000) {
                    self->m43();
                }
                self->m20(att, (0.6f));
            }
        } else {
            MISS_W24(self, &pos);
            CLEARCOLL_W24()
        }
        dmg = (0.0f);
        break;
    case 9:
        rec.kind = 1;
        rec.power = (5.0f) *
                    ((2e+01f) * ((1.0f) + (f32)power) +
                     (f32)att->m14() / ((5.0f) - (f32)power));
        dmg = rec.power * ((0.002f) * (f32)(100 - self->f2F2));
        if (immune == 0) {
            SUBHP_W24(self, (s32)dmg);
            if (((TObjChara *)self)->clamp_hp() <= 0) {
                SETF30_W24(self, 0x800);
                empty_post_damage_hook(self, att);
            }
        }
        SETF30_W24(self, 0x200);
        check_heavy_damage_flag__9TObjCharaFf(self, dmg);
        self->f2DC |= 4;
        if (TESTF30_W24(self, 0x02000000) == 0) {
            create_hit_effect__10TObjPlayerFPv(&pos);
            ((void (*)(void *, void *))trigger_switch_attack__10TObjPlayerFPvi)(self, &pos);
            APPLYDMG_W24(self, &pos, (s32)dmg);
            DISPATCH_W24(att, self, &pos);
        }
        break;
    case 10:
        rec.kind = 3;
        rec.power = (5.0f) *
                    ((2e+01f) * ((1.0f) + (f32)power) +
                     (f32)att->m14() / ((5.0f) - (f32)power));
        dmg = rec.power * ((0.002f) * (f32)(100 - self->f2F4));
        if (immune == 0) {
            SUBHP_W24(self, (s32)dmg);
            if (((TObjChara *)self)->clamp_hp() <= 0) {
                SETF30_W24(self, 0x800);
                empty_post_damage_hook(self, att);
            }
        }
        SETF30_W24(self, 0x200);
        check_heavy_damage_flag__9TObjCharaFf(self, dmg);
        self->f2DC |= 4;
        if ((ISLOCAL_W24(self) != 0 || ((TObjPlayer *)att)->is_local_player() != 0) &&
            ((s32 (*)(void *, void *, void *, f32))calc_shock_chance)(self, att, self, dmg) != 0) {
            self->m47();
        }
        if (TESTF30_W24(self, 0x02000000) == 0) {
            DISPATCH_W24(att, self, &pos);
            ((void (*)(void *, void *))activate_switch_attacks__10TObjPlayerFii)(self, &pos);
            APPLYDMG_W24(self, &pos, (s32)dmg);
        }
        break;
    case 11:
        mul *= (0.01f) * (f32)(power - self->f2F8);
        if (self->id < 0x1000) {
            mul -= (0.5f);
        }
        if (BOSS4_W24(self) < mul && is_boss_area() == 0) {
            if (TESTF30_W24(self, 0x02000000) == 0) {
                DISPATCH_W24(att, self, &pos);
            }
            if (immune == 0) {
                ((s16 (*)(void *))get_actor_hp)(self);
                ((TObjPlayer *)self)->set_hp_clamped(0);
                SETF30_W24(self, 0xA00);
                empty_post_damage_hook(self, att);
            }
        } else {
            MISS_W24(self, &pos);
            CLEARCOLL_W24()
        }
        dmg = (0.0f);
        break;
    case 12:
        if (BOSS4_W24(self) < mul * ((0.01f) * (f32)(power - self->stats->f0E))) {
            rec.kind = 18;
            rec.power = (0.0f);
            self->m21(att, rec, coll, -1, -1);
            if (TESTF30_W24(self, 0x02000000) == 0) {
                DISPATCH_W24(att, self, &pos);
            }
        }
        self->m20(att, (0.6f));
        dmg = (0.0f);
        break;
    case 13:
        if (is_boss_area() != 0) {
            dmg = (0.0f);
            MISS_W24(self, &pos);
            CLEARCOLL_W24()
        } else if (self->id < 0x1000) {
            dmg = (0.0f);
            MISS_W24(self, &pos);
            CLEARCOLL_W24()
        } else if (BOSS4_W24(self) < (0.5f)) {
            dmg = mul * (((1.0f) - (0.01f) * (f32)power) *
                         (f32)((s16 (*)(void *))get_actor_hp)(self));
            if (dmg < (1.0f)) {
                dmg = (1.0f);
            }
            if (immune == 0) {
                SUBHP_W24(self, (s32)dmg);
                if (((TObjChara *)self)->clamp_hp() <= 0) {
                    SETF30_W24(self, 0x800);
                    empty_post_damage_hook(self, att);
                }
            }
            SETF30_W24(self, 0x200);
            if (TESTF30_W24(self, 0x02000000) == 0) {
                DISPATCH_W24(att, self, &pos);
            }
        } else {
            dmg = (0.0f);
            MISS_W24(self, &pos);
            CLEARCOLL_W24()
        }
        break;
    default:
        dmg = (0.0f);
        break;
    }
    if (immune == 0) {
        self->m72(0);
    }
    if (ISLOCAL_W24(self) != 0) {
        TObjPlayer::calc_photon_blast_charge(self, (s32)((2e+01f) * dmg));
        self->m73();
    }
    record_local_damage_if_enabled(self, att, (s32)dmg);
    return dmg;
}
#undef VECCOPY_W24
#undef FIELD1C_W24
#undef TESTF30_W24
#undef SETF30_W24
#undef ISSTATE2_W24
#undef ISLOCAL_W24
#undef MISS_W24
#undef APPLYDMG_W24
#undef DISPATCH_W24
#undef SUB10DE8_W24
#undef SUBHP_W24
#undef ADDHP_W24
#undef SUBTP_W24
#undef ADDTP_W24
#undef HPLABEL_W24
#undef TPFONT_W24
#undef BOSS4_W24
#undef CLEARCOLL_W24
#pragma pop

f32 TObjChara::receive_direct_attack(void *att, DirectAttackPayload payload, void *coll, s32 tech, s32 arg5) {
    Info_8001311C info;
    Vec_8001311C pos;
    s32 immune;
    u16 aid;
    f32 mst;
    f32 dmg;
    f32 f;
    f32 heal;
    ((void (*)(Info_8001311C *, Info_8001311C *))obj_copyVec2_0)(&info, (Info_8001311C *)&payload);
    if (info.power < 0.0f) {
        info.power = 0.0f;
    }
    if (((Coll_8001311C *)coll) != NULL) {
        VECCOPY(&pos, &((Coll_8001311C *)coll)->pos);
    } else {
        VECCOPY(&pos, &((Actor_8001311C *)this)->pos);
    }
    if (((Actor_8001311C *)att) == NULL || FIELD1C(((Actor_8001311C *)att)) == 0xFFFF || (info.type != 8 && TEST30(((Actor_8001311C *)this), 0x800) != 0)) {
        return (0.0f);
    }
    if (info.type != 6 && info.type != 7 && info.type != 8 && info.type != 9 && info.type != 10 && info.type != 20 &&
        (TEST30(((Actor_8001311C *)this), 0x04000000) != 0 || (((Coll_8001311C *)coll) != NULL && (((Coll_8001311C *)coll)->flags & 0x02000080)))) {
        if (STATE2(((Actor_8001311C *)this)) == 0) {
            HIT(((Actor_8001311C *)this), &pos);
        }
        return (0.0f);
    }
    ((void (*)(Actor_8001311C *, Actor_8001311C *))attach_mine_trap__10TObjPlayerFiUi)(((Actor_8001311C *)this), ((Actor_8001311C *)att));
    if (STATE2(((Actor_8001311C *)this)) != 0) {
        if ((u32)(info.type - 6) <= 3 || info.type == 10) {
            immune = 0;
        } else {
            immune = 1;
        }
    } else if (((Actor_8001311C *)this)->id < 0x1000 && get_main_phase() == 15) {
        if (STATE2(((Actor_8001311C *)att)) != 0) {
            if (LOCAL(((Actor_8001311C *)this)) != 0 || STATE3(((Actor_8001311C *)this)) != 0) {
                if ((u32)(info.type - 6) <= 4 || get_type__10TObjPlayerFPv(((Actor_8001311C *)att)->f828) != 0) {
                    immune = 0;
                } else {
                    immune = 1;
                }
            } else {
                immune = 1;
            }
        } else {
            immune = 0;
        }
    } else {
        immune = 0;
    }
    if (((Actor_8001311C *)this)->id < 0x4000) {
        mst = ((Actor_8001311C *)att)->stats->mst;
        if (mst < 0.0f) {
            mst = 0.0f;
        }
    } else {
        mst = (0.0f);
    }
    aid = FIELD1C(((Actor_8001311C *)att));
    if (aid < 12) {
        dmg = info.power + mst;
        if (tech != -1) {
            dmg *= (1.0f) + calc_technique_boost(tech, aid);
        }
    } else {
        dmg = (0.5f) * mst + info.power;
    }
    switch (info.type) {
    case 0:
        if (TEST30(((Actor_8001311C *)this), 0x10000000) == 0 || STATE2(((Actor_8001311C *)this)) == 0) {
            dmg *= (0.2f);
            if (immune == 0) {
                SUB_HP(((Actor_8001311C *)this), (s32)dmg);
                if (((TObjChara *)((Actor_8001311C *)this))->clamp_hp() <= 0) {
                    SET30(((Actor_8001311C *)this), 0x800);
                }
            }
            SET30(((Actor_8001311C *)this), 0x200);
            check_heavy_damage_flag__9TObjCharaFf(((Actor_8001311C *)this), dmg);
            ((Actor_8001311C *)this)->f2dc |= 4;
            if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
                create_hit_effect__10TObjPlayerFPv(&pos);
                SWITCH_ATTACK(((Actor_8001311C *)this), &pos);
                DAMAGE(((Actor_8001311C *)this), &pos, (s32)dmg);
            }
        }
        break;
    case 1:
        if (TEST30(((Actor_8001311C *)this), 0x10000000) == 0 || STATE2(((Actor_8001311C *)this)) == 0) {
            dmg *= (0.002f) * (f32)(100 - ((Actor_8001311C *)this)->resist1);
            if (immune == 0) {
                SUB_HP(((Actor_8001311C *)this), (s32)dmg);
                if (((TObjChara *)((Actor_8001311C *)this))->clamp_hp() <= 0) {
                    SET30(((Actor_8001311C *)this), 0x800);
                }
            }
            SET30(((Actor_8001311C *)this), 0x200);
            check_heavy_damage_flag__9TObjCharaFf(((Actor_8001311C *)this), dmg);
            ((Actor_8001311C *)this)->f2dc |= 4;
            if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
                create_hit_effect__10TObjPlayerFPv(&pos);
                SWITCH_ATTACK(((Actor_8001311C *)this), &pos);
                DAMAGE(((Actor_8001311C *)this), &pos, (s32)dmg);
            }
        }
        break;
    case 2:
        if (TEST30(((Actor_8001311C *)this), 0x10000000) == 0 || STATE2(((Actor_8001311C *)this)) == 0) {
            dmg *= (0.002f) * (f32)(100 - ((Actor_8001311C *)this)->resist2);
            if (immune == 0) {
                SUB_HP(((Actor_8001311C *)this), (s32)dmg);
                if (((TObjChara *)((Actor_8001311C *)this))->clamp_hp() <= 0) {
                    SET30(((Actor_8001311C *)this), 0x800);
                }
            }
            SET30(((Actor_8001311C *)this), 0x200);
            ((Actor_8001311C *)this)->f2dc |= 4;
            if (LOCAL(((Actor_8001311C *)this)) != 0 || ((TObjPlayer *)((Actor_8001311C *)att))->is_local_player() != 0) {
                f = info.power - (2.5e+02f);
                if (f < 0.0f) {
                    f = 0.0f;
                }
                if (((s32 (*)(Actor_8001311C *, Actor_8001311C *, Actor_8001311C *, f32))calc_freeze_chance)(((Actor_8001311C *)this), ((Actor_8001311C *)att), ((Actor_8001311C *)this), (0.025f) * ((0.025f) * f + (5.0f))) != 0) {
                    this->apply_movement_ailment((s32)((Coll_8001311C *)coll));
                }
            }
            if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
                create_hit_effect__10TObjPlayerFPv(&pos);
                SWITCH_ATTACK(((Actor_8001311C *)this), &pos);
                DAMAGE(((Actor_8001311C *)this), &pos, (s32)dmg);
            }
        }
        break;
    case 3:
        if (TEST30(((Actor_8001311C *)this), 0x10000000) == 0 || STATE2(((Actor_8001311C *)this)) == 0) {
            dmg *= (0.002f) * (f32)(100 - ((Actor_8001311C *)this)->resist3);
            if (immune == 0) {
                SUB_HP(((Actor_8001311C *)this), (s32)dmg);
                if (((TObjChara *)((Actor_8001311C *)this))->clamp_hp() <= 0) {
                    SET30(((Actor_8001311C *)this), 0x800);
                }
            }
            SET30(((Actor_8001311C *)this), 0x200);
            check_heavy_damage_flag__9TObjCharaFf(((Actor_8001311C *)this), dmg);
            ((Actor_8001311C *)this)->f2dc |= 4;
            if ((LOCAL(((Actor_8001311C *)this)) != 0 || ((TObjPlayer *)((Actor_8001311C *)att))->is_local_player() != 0) &&
                ((s32 (*)(Actor_8001311C *, Actor_8001311C *, Actor_8001311C *, f32))calc_shock_chance)(((Actor_8001311C *)this), ((Actor_8001311C *)att), ((Actor_8001311C *)this), info.power) != 0) {
                this->apply_shock_status();
            }
            ((void (*)(Actor_8001311C *, Vec_8001311C *))activate_switch_attacks__10TObjPlayerFii)(((Actor_8001311C *)this), &pos);
            if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
                DAMAGE(((Actor_8001311C *)this), &pos, (s32)dmg);
            }
        }
        break;
    case 4:
        if (TEST30(((Actor_8001311C *)this), 0x10000000) == 0 || STATE2(((Actor_8001311C *)this)) == 0) {
            dmg *= (0.002f) * (f32)(100 - ((Actor_8001311C *)this)->resist4);
            if (immune == 0) {
                SUB_HP(((Actor_8001311C *)this), (s32)dmg);
                if (((TObjChara *)((Actor_8001311C *)this))->clamp_hp() <= 0) {
                    SET30(((Actor_8001311C *)this), 0x800);
                }
            }
            SET30(((Actor_8001311C *)this), 0x200);
            check_heavy_damage_flag__9TObjCharaFf(((Actor_8001311C *)this), dmg);
            ((Actor_8001311C *)this)->f2dc |= 4;
            if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
                create_hit_effect__10TObjPlayerFPv(&pos);
                SWITCH_ATTACK(((Actor_8001311C *)this), &pos);
                DAMAGE(((Actor_8001311C *)this), &pos, (s32)dmg);
            }
        }
        break;
    case 5:
        if (TEST30(((Actor_8001311C *)this), 0x10000000) == 0 || STATE2(((Actor_8001311C *)this)) == 0) {
            if (is_boss_area() == 0 || (game_difficulty_selection == 3 && ((Actor_8001311C *)this)->id >= 0x1000)) {
                if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
                    create_hit_effect__10TObjPlayerFPv(&pos);
                }
                ((Actor_8001311C *)this)->f2dc |= 4;
                dmg = (0.01f) * (info.power - (f32)((Actor_8001311C *)this)->resist5);
                if (immune == 0 && ((f32 (*)(Actor_8001311C *))random_ratio__9TObjCharaFv)(((Actor_8001311C *)this)) < dmg) {
                    ((TObjPlayer *)((Actor_8001311C *)this))->set_hp_clamped(0);
                    SET30(((Actor_8001311C *)this), 0xA00);
                }
            } else {
                dmg = (0.0f);
            }
        }
        break;
    case 6:
        heal = (0.5f) * mst + info.power;
        if (immune == 0) {
            ((s32 (*)(Actor_8001311C *, s32))add_actor_hp)(((Actor_8001311C *)this), (s32)heal);
            ((TObjChara *)((Actor_8001311C *)this))->clamp_hp();
        }
        ((void (*)(Actor_8001311C *, Vec_8001311C *, s32, s32))draw_hp_label)(((Actor_8001311C *)this), &pos, 0, (s32)heal);
        dmg = (0.0f);
        break;
    case 7:
        dmg = (0.0f);
        if (STATE3(((Actor_8001311C *)this)) != 0) {
            this->clear_harmful_statuses();
        } else {
            this->apply_anti_technique(arg5);
        }
        break;
    case 9:
        dmg = (0.0f);
        if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
            this->apply_switch_attack();
        }
        ((Actor_8001311C *)this)->m49(info);
        if (((Actor_8001311C *)this)->f1c <= 0x1000 && ((Actor_8001311C *)this)->f1c > 0x4000) {
            this->vfunc_74(info.type);
        }
        break;
    case 10:
        dmg = (0.0f);
        if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
            this->trigger_switch_attack();
        }
        ((Actor_8001311C *)this)->m50(info);
        if (((Actor_8001311C *)this)->f1c <= 0x1000 && ((Actor_8001311C *)this)->f1c > 0x4000) {
            this->vfunc_74(info.type);
        }
        break;
    case 11:
        dmg = (0.0f);
        if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
            this->enemy_spawn_jellen_effect();
        }
        ((Actor_8001311C *)this)->m49(info);
        if (((Actor_8001311C *)this)->f1c <= 0x1000 && ((Actor_8001311C *)this)->f1c > 0x4000) {
            this->vfunc_74(info.type);
        }
        break;
    case 12:
        dmg = (0.0f);
        if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
            this->enemy_spawn_zalure_effect();
        }
        ((Actor_8001311C *)this)->m50(info);
        if (((Actor_8001311C *)this)->f1c <= 0x1000 && ((Actor_8001311C *)this)->f1c > 0x4000) {
            this->vfunc_74(info.type);
        }
        break;
    case 15:
        dmg = (0.0f);
        if (immune == 0) {
            this->apply_poison_status();
        }
        break;
    case 16:
        dmg = (0.0f);
        if (immune == 0) {
            this->apply_paralysis();
        }
        break;
    case 17:
        dmg = (0.0f);
        if (immune == 0) {
            this->apply_slow_status();
        }
        break;
    case 18:
        dmg = (0.0f);
        if (immune == 0) {
            this->apply_confusion_status();
        }
        break;
    case 19:
        if (TEST30(((Actor_8001311C *)this), 0x10000000) == 0 || STATE2(((Actor_8001311C *)this)) == 0) {
            dmg *= (0.002f) * (f32)(100 - ((Actor_8001311C *)this)->resist2);
            if (immune == 0) {
                SUB_HP(((Actor_8001311C *)this), (s32)dmg);
                if (((TObjChara *)((Actor_8001311C *)this))->clamp_hp() <= 0) {
                    ((Actor_8001311C *)this)->flags30 |= 0x800;
                }
            }
            ((Actor_8001311C *)this)->flags30 |= 0x200;
            check_heavy_damage_flag__9TObjCharaFf(((Actor_8001311C *)this), dmg);
            ((Actor_8001311C *)this)->f2dc |= 4;
            if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
                create_hit_effect__10TObjPlayerFPv(&pos);
                SWITCH_ATTACK(((Actor_8001311C *)this), &pos);
                DAMAGE(((Actor_8001311C *)this), &pos, (s32)dmg);
            }
        }
        break;
    case 20:
        dmg = (0.0f);
        this->apply_action_hold_status(info.power);
        break;
    case 8:
        dmg = (0.0f);
        this->reset_pose();
        break;
    case 21:
        if (TEST30(((Actor_8001311C *)this), 0x10000000) == 0 || STATE2(((Actor_8001311C *)this)) == 0) {
            dmg = info.power;
            if (immune == 0) {
                SUB_HP(((Actor_8001311C *)this), (s32)dmg);
                if (((TObjChara *)((Actor_8001311C *)this))->clamp_hp() <= 0) {
                    SET30(((Actor_8001311C *)this), 0x800);
                }
            }
            SET30(((Actor_8001311C *)this), 0x200);
            check_heavy_damage_flag__9TObjCharaFf(((Actor_8001311C *)this), dmg);
            ((Actor_8001311C *)this)->f2dc |= 4;
            if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
                create_hit_effect__10TObjPlayerFPv(&pos);
                SWITCH_ATTACK(((Actor_8001311C *)this), &pos);
                DAMAGE(((Actor_8001311C *)this), &pos, (s32)dmg);
            }
        }
        break;
    default:
        dmg = (0.0f);
        break;
    }
    if (immune == 0) {
        this->vfunc_74(0);
    }
    if (LOCAL(((Actor_8001311C *)this)) != 0) {
        TObjPlayer::calc_photon_blast_charge(((Actor_8001311C *)this), (s32)((2e+01f) * dmg));
        ((Actor_8001311C *)this)->m73();
    }
    record_local_damage_if_enabled(((Actor_8001311C *)this), ((Actor_8001311C *)att), (s32)dmg);
    empty_post_damage_hook(((Actor_8001311C *)this), ((Actor_8001311C *)att));
    return dmg;
}
#undef TEST30
#undef SET30
#undef FIELD1C
#undef STATE2
#undef STATE3
#undef LOCAL
#undef VECCOPY
#undef HIT
#undef DAMAGE
#undef SWITCH_ATTACK
#undef SUB_HP
#pragma pop

void TObjChara::apply_knockback_from_attacker(u8 *arg1, f32) {
    Vec_8001401C diff;
    f32 scale;
    if (((s32 (*)(void))obj_isState2_324__9TObjCharaFv)() != 1 && ((s32 (*)(void *, int))obj_testFlags30__14TObjCollidableFUl)(this, 0x04000000) == 0) {
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&diff, arg1 + 0x38);
    ((s32 (*)(void *, void *))subtract_vector)(&diff, ((u8 *)this) + 0x38);
    if ((diff.x * diff.x) + (diff.z * diff.z) < (1e-05f)) {
        *(f32 *)((s8 *)((u8 *)this) + 0x308) = (0.0f);
        this->m_310 = (0.0f);
        return;
    }
    scale = 10.0f + (10.0f - *(f32 *)(this->m_2b0 + 0x14));
    if (scale < 0.0f) {
        scale = 0.0f;
    }
    ((TObjBoss2Tunnel *)(&diff))->update_scale();
    *(f32 *)((s8 *)((u8 *)this) + 0x308) = -scale * diff.x;
    this->m_310 = -scale * diff.z;
    }
}

#pragma push
#pragma fp_contract on
struct VBase_18_d805cd { char pad[0x18]; };
struct VObj_18_d805cd : VBase_18_d805cd {
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
    virtual void m72(s32);
    virtual void m73();
};

struct Vec_80014108 { f32 x, y, z; };
struct Coll_80014108 { u8 pad0[0x18]; u32 flags; Vec_80014108 pos; f32 def; };
struct Elem_80014108 { u8 type; s8 value; };
struct Obj_80014108 {
    u8 pad0[0x30];
    u32 flags30;
    u8 pad34[0xA4 - 0x34];
    Coll_80014108 *colls;
    s32 ncolls;
    u8 padAC[0x110 - 0xAC];
    Elem_80014108 elem[3];
    u8 pad116[0x2C8 - 0x116];
    s16 atp;
    s16 atpRange;
    s16 f2CC;
    s16 dfp;
    s16 f2D0;
    s16 lck;
    u8 pad2D4[0x2E4 - 0x2D4];
    s32 elemKind;
    s16 atkElem[5];
    s16 resist[5];
    u8 pad2FC[0x32C - 0x2FC];
    s16 hp;
};

#define check_heavy_damage_flag__9TObjCharaFf(a, b) ((void (*)(void *, f32))check_heavy_damage_flag__9TObjCharaFf)(a, b)
#define attach_mine_trap__10TObjPlayerFiUi(a, b) ((void (*)(void *, void *))attach_mine_trap__10TObjPlayerFiUi)(a, b)
#define random_ratio__9TObjCharaFv(a) ((f32 (*)(void *))random_ratio__9TObjCharaFv)(a)
#define TObjectV8047c128_subtract_hp(a, b) ((void (*)(void *, s32))TObjectV8047c128_subtract_hp)(a, b)
#define trigger_switch_attack__10TObjPlayerFPvi(a, b) ((void (*)(void *, void *))trigger_switch_attack__10TObjPlayerFPvi)(a, b)
#define try_apply_damage__9TObjCharaFUll(a, b, c) ((void (*)(void *, void *, s32))try_apply_damage__9TObjCharaFUll)(a, b, c)
#define VecCopy__FP3VecPC3Vec(a, b) ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(a, b)
#define is_locally_controlled__10TObjPlayerFPv(a) ((s32 (*)(void *))is_locally_controlled__10TObjPlayerFPv)(a)
#define obj_isState2_324__9TObjCharaFv(a) ((s32 (*)(void *))obj_isState2_324__9TObjCharaFv)(a)
#define get_actor_attack_params_atp_min__9TObjCharaFv(a) ((s16 (*)(void *))get_actor_attack_params_atp_min__9TObjCharaFv)(a)
#define obj_testFlags30__14TObjCollidableFUl(a, b) ((s32 (*)(void *, int))obj_testFlags30__14TObjCollidableFUl)(a, b)
#define get_entity_id(a) ((u16 (*)(void *))get_entity_id)(a)
#define obj_setFlags30(a, b) ((void (*)(void *, u32))obj_setFlags30)(a, b)
#define get_type__10TObjPlayerFPv(a) ((s32 (*)(void *))get_type__10TObjPlayerFPv)(a)
#define play_sound_effect(a, b, c, d) ((void (*)(s32, void *, s32, s32))play_sound_effect)(a, b, c, d)
#define RESIST_80014108(k) \
    dmg += ((Obj_80014108 *)att)->atkElem[k] * (0.01f * (f32)(100 - ((Obj_80014108 *)this)->resist[k]));

#pragma opt_loop_invariants off
#define COLL_80014108() (&((Obj_80014108 *)this)->colls[i])

f32 TObjChara::receive_physical_attack(void *att, f32 scale) {
    Vec_80014108 hit;
    s32 immune;
    s32 i;
    s32 j;
    f32 scl0;
    f32 dmg;
    f32 elem;
    f32 total;
    f32 d;
    f32 crit;
    f32 lck;
    f32 boss;

    if (((Obj_80014108 *)att) == NULL || get_entity_id(((Obj_80014108 *)att)) == 0xFFFF || obj_testFlags30__14TObjCollidableFUl(((Obj_80014108 *)this), 0x800) != 0) {
        return 0.0f;
    }
    if (obj_testFlags30__14TObjCollidableFUl(((Obj_80014108 *)this), 0x04000000) != 0 && obj_testFlags30__14TObjCollidableFUl(((Obj_80014108 *)this), 0x02000000) == 0) {
        try_apply_damage__9TObjCharaFUll(((Obj_80014108 *)this), (u8 *)((Obj_80014108 *)this) + 0x2FC, 0);
        return 0.0f;
    }
    attach_mine_trap__10TObjPlayerFiUi(((Obj_80014108 *)this), ((Obj_80014108 *)att));
    if (obj_isState2_324__9TObjCharaFv(((Obj_80014108 *)this)) != 0) {
        immune = 1;
    } else if (obj_isState2_324__9TObjCharaFv(((Obj_80014108 *)att)) != 0) {
        if (is_locally_controlled__10TObjPlayerFPv(((Obj_80014108 *)this)) != 0 && get_type__10TObjPlayerFPv((u8 *)((Obj_80014108 *)att) + 0x828) != 0) {
            immune = 0;
        } else {
            immune = 1;
        }
    } else {
        immune = 0;
    }
    scl0 = random_ratio__9TObjCharaFv(((Obj_80014108 *)this));
    dmg = 0.2f * (((Obj_80014108 *)att)->atpRange * scl0 + ((Obj_80014108 *)att)->atp);
    elem = 0.2f * get_actor_attack_params_atp_min__9TObjCharaFv(((Obj_80014108 *)att));
    for (j = 0; j < 3; j++) {
        switch (((Obj_80014108 *)this)->elemKind) {
        case 1:
            if (((Obj_80014108 *)att)->elem[j].type == 1) {
                elem *= 0.01f * ((Obj_80014108 *)att)->elem[j].value + 1.0f;
            }
            break;
        case 2:
            if (((Obj_80014108 *)att)->elem[j].type == 2) {
                elem *= 0.01f * ((Obj_80014108 *)att)->elem[j].value + 1.0f;
            }
            break;
        case 4:
            if (((Obj_80014108 *)att)->elem[j].type == 3) {
                elem *= 0.01f * ((Obj_80014108 *)att)->elem[j].value + 1.0f;
            }
            break;
        case 8:
            if (((Obj_80014108 *)att)->elem[j].type == 4) {
                elem *= 0.01f * ((Obj_80014108 *)att)->elem[j].value + 1.0f;
            }
            break;
        }
    }
    dmg += elem;
    RESIST_80014108(0)
    RESIST_80014108(1)
    RESIST_80014108(2)
    RESIST_80014108(3)
    RESIST_80014108(4)
    total = 0.0f;
    for (i = 0; i < ((Obj_80014108 *)this)->ncolls; i++) {
        if (COLL_80014108()->flags & 0x04000000) {
            COLL_80014108()->flags &= ~0x04000000;
            VecCopy__FP3VecPC3Vec(&hit, &COLL_80014108()->pos);
            d = dmg - 0.2f * ((Obj_80014108 *)this)->dfp - COLL_80014108()->def;
            if (d < 0.0f) {
                d = 0.0f;
                try_apply_damage__9TObjCharaFUll(((Obj_80014108 *)this), &hit, (s32)d);
            } else {
                d *= scale;
                if (obj_testFlags30__14TObjCollidableFUl(((Obj_80014108 *)this), 0x02000000) == 0) {
                    boss = random_ratio__9TObjCharaFv(((Obj_80014108 *)this));
                    if (get_entity_id(((Obj_80014108 *)att)) < 0x1000) {
                        crit = boss; crit *= (5e+02f);
                    } else {
                        crit = boss; crit *= (2e+02f);
                    }
                    lck = ((Obj_80014108 *)att)->lck;
                    if (100.0f < lck) {
                        lck = 100.0f;
                    }
                    if (crit <= lck) {
                        ((TEffClitical *)(&hit))->create();
                        play_sound_effect(0x4001A31F, &hit, 0, 0);
                        d *= (1.5f);
                    } else {
                        create_hit_effect__10TObjPlayerFPv(&hit);
                    }
                    trigger_switch_attack__10TObjPlayerFPvi(((Obj_80014108 *)this), &hit);
                    try_apply_damage__9TObjCharaFUll(((Obj_80014108 *)this), &hit, (s32)d);
                }
                total += d;
            }
        }
    }
    if (total <= 0.0f) {
        ((Obj_80014108 *)this)->flags30 |= 0x100;
        return 0.0f;
    }
    obj_setFlags30(((Obj_80014108 *)this), 0x200);
    check_heavy_damage_flag__9TObjCharaFf(((Obj_80014108 *)this), total);
    if (immune == 0) {
        TObjectV8047c128_subtract_hp(((Obj_80014108 *)this), (s32)total);
        if (((Obj_80014108 *)this)->hp <= 0) {
            ((Obj_80014108 *)this)->flags30 |= 0x800;
        }
    }
    if (immune == 0) {
        ((TObjChara *)((Obj_80014108 *)this))->vfunc_74(0);
    }
    if (is_locally_controlled__10TObjPlayerFPv(((Obj_80014108 *)this)) != 0) {
        TObjPlayer::calc_photon_blast_charge(((Obj_80014108 *)this), (s32)(20.0f * total));
        ((VObj_18_d805cd *)((Obj_80014108 *)this))->m73();
    }
    record_local_damage_if_enabled(((Obj_80014108 *)this), ((Obj_80014108 *)att), (s32)total);
    empty_post_damage_hook(((Obj_80014108 *)this), ((Obj_80014108 *)att));
    return total;
}

#undef check_heavy_damage_flag__9TObjCharaFf
#undef attach_mine_trap__10TObjPlayerFiUi
#undef random_ratio__9TObjCharaFv
#undef TObjectV8047c128_subtract_hp
#undef trigger_switch_attack__10TObjPlayerFPvi
#undef try_apply_damage__9TObjCharaFUll
#undef VecCopy__FP3VecPC3Vec
#undef is_locally_controlled__10TObjPlayerFPv
#undef obj_isState2_324__9TObjCharaFv
#undef get_actor_attack_params_atp_min__9TObjCharaFv
#undef obj_testFlags30__14TObjCollidableFUl
#undef get_entity_id
#undef obj_setFlags30
#undef get_type__10TObjPlayerFPv
#undef play_sound_effect
#undef RESIST_80014108
#undef COLL_80014108
#pragma pop

int TObjChara::vfunc_67(f32) { return 0; }

int TObjChara::vfunc_66() { return 0; }

void TObjChara::get_anim_node_position(s32, Vec *) {  }

void TObjChara::reset_pose() { obj_clearFlags30((u32)((void*)2048)); *(short *)&this->hp = *(short *)&this->hpmax; *(short *)&this->tp = *(short *)&this->tpmax; }

void TObjChara::vfunc_63() {  }

void TObjChara::vfunc_62() {  }

void TObjChara::vfunc_61() {  }

void TObjChara::vfunc_60() {  }

void TObjChara::vfunc_59() {  }

void TObjChara::vfunc_58() {  }

void TObjChara::apply_action_hold_status(f32 farg0) {
    s32 arg0 = (s32)this;
    ((void (*)(s32, s32, s32))TObjPlayer__sub_8001940C)(arg0, 4, 0x14);
    ((void (*)(s32, s32, s32))TObjPlayer__sub_800193FC)(arg0, 4, (s32) farg0);
    ((void (*)(void *, u32))obj_setFlags30)((void *) arg0, 0x4000U);
}

void TObjChara::clear_all_status_effects() {
    switch (((int (*)(void *, int))obj_getArrWord_254)(this, 0)) {
    case 0x10:
        this->sub_800192B4((s32) ((f32) this->get_s16_2c4() * -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)(this, 0)));
        break;
    }
    switch (((int (*)(void *, int))obj_getArrWord_254)(this, 1)) {
    case 2:
    case 3:
        this->sub_800192B4((s32) ((f32) this->get_s16_2c4() * -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)(this, 1)));
        break;
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC0);
    *(s32 *)((s8 *)((u8 *)this) + 0x330) = (s32) (this->actorFlags & 0x3F);
    ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x254);
    ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x260);
    this->add_to_field_2c8((s32) ((f32) this->get_field_2c0() * -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)(this, 2)));
    this->add_to_field_2ca((s32) ((f32) this->get_field_2c2() * -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)(this, 2)));
    ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x26C);
    this->add_to_field_2ce((s32) ((f32) this->get_atp() * -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)(this, 3)));
    ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x278);
    obj_clearFlags30((u32)0x4000U);
    ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x284);
}

void TObjChara::cure_paralysis() {
    switch (((int (*)(void *, int))obj_getArrWord_254)(this, 0)) {
    case 0x10:
        sub_800192B4((s32) ((f32) this->get_s16_2c4() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 0)));
        ((Obj_80014B5C *)this)->f30 &= ~3;
        ((Obj_80014B5C *)this)->f330 = ((Obj_80014B5C *)this)->f30 & 0x3f;
        ((void (*)(void *))reset_status_effect_row)(((Obj_80014B5C *)this)->f254);
        break;
    }
}

void TObjChara::cure_poison_ailment() {
    switch (((int (*)(void *, int))obj_getArrWord_254)(this, 0)) {
    case 0xf:
        ((Obj_80014C1C *)this)->f30 &= ~3;
        ((Obj_80014C1C *)this)->f330 = ((Obj_80014C1C *)this)->f30 & 0x3f;
        ((void (*)(void *))reset_status_effect_row)(((Obj_80014C1C *)this)->f254);
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjChara::apply_defense_stat_status(void *receipt_arg) {
    StatStatusReceipt_80014E74 *receipt = (StatStatusReceipt_80014E74 *)receipt_arg;
    f32 temp_f31;
    f32 var_f30;
    f32 temp_f29;

    if (receipt->kind != 0xC) {
        var_f30 = (0.01f) * ((1.3f) * receipt->power + (1e+01f));
    } else {
        var_f30 = (-0.01f) * ((1.3f) * receipt->power + (1e+01f));
    }
    temp_f29 = ((f32 (*)(TObjChara *, s32))TObjPlayer__sub_800192C4)(this, 3);
    temp_f31 = ((f32 (*)(f32))fabs_float)(var_f30);
    if (!(((f32 (*)(f32))fabs_float)(temp_f29) > temp_f31)) {
        temp_f31 = -((f32 (*)(TObjChara *, s32))TObjPlayer__sub_800192C4)(this, 3);
        {
            f32 v = this->get_atp();
            v *= temp_f31;
            this->add_to_field_2ce((s32) v);
        }
        ((s32 (*)(TObjChara *, s32, s32))TObjPlayer__sub_8001940C)(this, 3, receipt->kind);
        ((s32 (*)(TObjChara *, s32, f32))TObjPlayer__sub_8001941C)(this, 3, var_f30);
        this->add_to_field_2ce((s32) (var_f30 * (f32) this->get_atp()));
        ((s32 (*)(TObjChara *, s32, s32))TObjPlayer__sub_800193FC)(this, 3, (s32) ((3e+01f) * ((1e+01f) * receipt->power + (4e+01f))));
        if (((s32 (*)(TObjChara *, s32))obj_testFlags30__14TObjCollidableFUl)(this, 0x02000000) == 0) {
            u32 temp_obj = __nw__7TObjectFUl(0x64);
            if (temp_obj != 0U) {
                ((s32 (*)(u32, s32 *, s32 *, s32, s32, f32, s32))construct_actor_light_task)(temp_obj, player_defense_stat_status_light_colors, TObjPlayer__data_80434060, 0x2D, (s32)this, (0.1f), tl_07);
            }
        }
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjChara::apply_attack_stat_status(void *arg1_arg) {
    StatStatusReceipt_80014E74 *arg1 = (StatStatusReceipt_80014E74 *)arg1_arg;
    f32 var_f31;
    f32 temp_f30;
    f32 temp_f29;

    if ((s32) arg1->kind != 0xB) {
        var_f31 = (0.01f) * ((1.3f) * arg1->power + (1e+01f));
    } else {
        var_f31 = (-0.01f) * ((1.3f) * arg1->power + (1e+01f));
    }
    temp_f29 = ((f32 (*)(TObjPlayer*, s32))TObjPlayer__sub_800192C4)(((TObjPlayer *)this), 2);
    temp_f30 = ((f32 (*)(f32))fabs_float)(var_f31);
    if (!(((f32 (*)(f32))fabs_float)(temp_f29) > temp_f30)) {
        temp_f30 = -((f32 (*)(TObjPlayer*, s32))TObjPlayer__sub_800192C4)(((TObjPlayer *)this), 2);
        {
            f32 v = this->get_field_2c0();
            v *= temp_f30;
            this->add_to_field_2c8((s32) v);
        }
        temp_f30 = -((f32 (*)(TObjPlayer*, s32))TObjPlayer__sub_800192C4)(((TObjPlayer *)this), 2);
        {
            f32 v = this->get_field_2c2();
            v *= temp_f30;
            this->add_to_field_2ca((s32) v);
        }
        ((s32 (*)(TObjPlayer*, s32, s32))TObjPlayer__sub_8001940C)(((TObjPlayer *)this), 2, arg1->kind);
        ((s32 (*)(TObjPlayer*, s32, f32))TObjPlayer__sub_8001941C)(((TObjPlayer *)this), 2, var_f31);
        this->add_to_field_2c8((s32) (var_f31 * (f32) this->get_field_2c0()));
        this->add_to_field_2ca((s32) (var_f31 * (f32) this->get_field_2c2()));
        ((s32 (*)(TObjPlayer*, s32, s32))TObjPlayer__sub_800193FC)(((TObjPlayer *)this), 2, (s32) ((3e+01f) * ((1e+01f) * arg1->power + (4e+01f))));
        if (((s32 (*)(TObjPlayer*, s32))obj_testFlags30__14TObjCollidableFUl)(((TObjPlayer *)this), 0x02000000) == 0) {
            u32 temp_obj = __nw__7TObjectFUl(0x64);
            if (temp_obj != 0U) {
                ((s32 (*)(u32, s32 *, s32 *, s32, TObjPlayer*, f32, s32))construct_actor_light_task)(temp_obj, player_attack_stat_status_light_colors, TObjPlayer__data_80434060, 0x2D, ((TObjPlayer *)this), (0.1f), tl_07);
            }
        }
    }
}
#pragma pop

void TObjChara::clear_harmful_statuses() {
    switch (((int (*)(void *, int))obj_getArrWord_254)(this, 0)) {
    case 0x10:
        sub_800192B4((s32)((f32)this->get_s16_2c4() * -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)(this, 0)));
        break;
    }
    switch (((int (*)(void *, int))obj_getArrWord_254)(this, 1)) {
    case 2:
    case 3:
        sub_800192B4((s32)((f32)this->get_s16_2c4() * -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)(this, 1)));
        break;
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC0);
    *(s32 *)&this->unk_330 = (s32) (*(s32 *)&this->actorFlags & 0x3F);
    ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x254);
    ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x260);
    switch (((int (*)(void *, int))obj_getArrWord_254)(this, 2)) {
    case 0xB:
        this->add_to_field_2c8((s32)((f32)this->get_field_2c0() * -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)(this, 2)));
        this->add_to_field_2ca((s32)((f32)this->get_field_2c2() * -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)(this, 2)));
        ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x26C);
        break;
    }
    switch (((int (*)(void *, int))obj_getArrWord_254)(this, 3)) {
    case 0xC:
        this->add_to_field_2ce((s32)((f32)this->get_atp() * -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)(this, 3)));
        ((void (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x278);
        break;
    }
}

void TObjChara::apply_shock_status() {
    s32 ok;
    f32 k;
    f32 v;

    ok = 0;
    if (((u16 (*)(void *))get_entity_id)(this) >= 0x1000 && ((u16 (*)(void *))get_entity_id)(this) < 0x4000 &&
        ((s32 (*)(void *, int))obj_testFlag_2E4__9TObjCharaFUl)(this, 4) != 0 && ((s32 (*)(void *, int))obj_testFlags30__14TObjCollidableFUl)(this, 0x01000000) == 0 &&
        this->test_immunity_flags(4) == 0) {
        ok = 1;
    }
    if (((u16 (*)(void *))get_entity_id)(this) < 0x1000 && this->test_immunity_flags(4) == 0) {
        ok = 1;
    }
    if (ok != 0) {
        if (((s32 (*)(void *, int))obj_testFlags30__14TObjCollidableFUl)(this, 0x02000000) == 0) {
            ((void (*)(void *, int))play_shock_feedback__10TObjPlayerFii)(this, 1);
        }
        switch (((int (*)(void *, int))obj_getArrWord_254)(this, 1)) {
        case 2:
        case 3:
            k = -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)(this, 1);
            v = (f32)this->get_s16_2c4();
            v *= k;
            sub_800192B4((s32)v);
            break;
        }
        ((void (*)(void *, int, int))TObjPlayer__sub_8001940C)(this, 1, 3);
        if (((u16 (*)(void *))get_entity_id)(this) < 0x1000) {
            ((void (*)(void *, int, f32))TObjPlayer__sub_8001941C)(this, 1, (0.0f));
        } else {
            ((void (*)(void *, int, f32))TObjPlayer__sub_8001941C)(this, 1, (-0.15f));
        }
        ((void (*)(void *, int, int))TObjPlayer__sub_800193FC)(this, 1, 0x12C);
        this->actorFlags &= ~0x3C;
        this->actorFlags |= 4;
        if (this->entity_id >= 0x1000) {
            sub_800192B4((s32)((-0.15f) * (f32)this->get_s16_2c4()));
        }
    }
}

void TObjChara::apply_movement_ailment(s32 arg1) {

    if ((((s32 (*)(void *, u32))obj_testFlags30__14TObjCollidableFUl)(this, 0x8000U) == 0) && (((s32 (*)(void *, u32))obj_testFlags30__14TObjCollidableFUl)(this, 0x01000000U) == 0) && (this->test_immunity_flags(0x20) == 0) && ((((s32 (*)(void *, u32))obj_testFlags30__14TObjCollidableFUl)(this, 0x20U) == 0) || (((s32 (*)(void *, int))TObjPlayer__sub_8001943C)(this, 1) <= 0))) {
        spawn_freeze_shell_effect(arg1, 1);
        switch (((int (*)(void *, int))obj_getArrWord_254)(this, 1)) {
        case 2:
        case 3:
            sub_800192B4((s32)((f32)this->get_s16_2c4() * -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)(this, 1)));
            break;
        }
        ((s32 (*)(void *, int, int))TObjPlayer__sub_8001940C)(this, 1, 2);
        ((s32 (*)(void *, int, f32))TObjPlayer__sub_8001941C)(this, 1, (f32) ((-0.3f)));
        ((s32 (*)(void *, int, int))TObjPlayer__sub_800193FC)(this, 1, 0x96);
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC3);
        this->actorFlags = (s32) (this->actorFlags | 0x20);
        sub_800192B4((s32) ((-0.3f) * (f32) this->get_s16_2c4()));
    }
}

void TObjChara::apply_confusion_status() {
    f32 temp_f31;

    if ((((s32 (*)(void *, s32))obj_testFlag_2E4__9TObjCharaFUl)(this, 0x10) == 0) && (this->test_immunity_flags(0x10) == 0)) {
        ((s32 (*)(void *, s32))spawn_confusion_feedback_effect)(this, 0);
        switch (((s32 (*)(void *, s32))obj_getArrWord_254)(this, 1)) {
        case 2:
        case 3:
            sub_800192B4((s32) ((f32) this->get_s16_2c4() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 1)));
            break;
        }
        ((s32 (*)(void *, s32, s32))TObjPlayer__sub_8001940C)(this, 1, 0x12);
        ((s32 (*)(void *, s32, f32))TObjPlayer__sub_8001941C)(this, 1, (0.0f));
        ((s32 (*)(void *, s32, s32))TObjPlayer__sub_800193FC)(this, 1, 0x12C);
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC3);
        this->actorFlags = (s32) (this->actorFlags | 0x10);
    }
}

struct Obj800192C4;
struct ObjArr254;
struct O_800193FC;
struct O_8001940C;
struct O_8001941C;
void TObjChara::apply_slow_status() {
    f32 temp_f31;
    if (((u16) this->entity_id <= 0x1000U) && (this->test_immunity_flags(8) == 0)) {
        ((void (*)(void *, s32))spawn_slow_effect__10TObjPlayerFii)(this, 0);
        switch (((s32 (*)(void *, s32))obj_getArrWord_254)(this, 1)) {
        case 2:
        case 3:
            sub_800192B4((s32) ((f32) this->get_s16_2c4() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 1)));
            break;
        }
        ((void (*)(void *, s32, s32))TObjPlayer__sub_8001940C)(this, 1, 0x11);
        ((void (*)(void *, s32, f32))TObjPlayer__sub_8001941C)(this, 1, (0.0f));
        ((void (*)(void *, s32, s32))TObjPlayer__sub_800193FC)(this, 1, 0xD2);
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC3);
        this->actorFlags = (s32) (this->actorFlags | 8);
    }
}

void TObjChara::apply_paralysis() {
    if ((((s32 (*)(void *, s32))obj_testFlag_2E4__9TObjCharaFUl)(this, 4U) == 0) && (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(this, 0x01000000U) == 0) && (this->test_immunity_flags(2) == 0)) {
        spawn_paralysis_feedback_effect((s32) this, 0);
        if (((int (*)(void *, int))obj_getArrWord_254)(this, 0) == 0x10) {
            sub_800192B4((s32) ((f32) this->get_s16_2c4() * -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)(this, 0)));
        }
        ((s32 (*)(void *, int, int))TObjPlayer__sub_8001940C)(this, 0, 0x10);
        if ((u16) this->entity_id >= 0x1000U) {
            ((s32 (*)(void *, int, f32))TObjPlayer__sub_8001941C)(this, 0, (f32) ((-0.15f)));
            sub_800192B4((s32) ((-0.15f) * (f32) this->get_s16_2c4()));
            ((s32 (*)(void *, int, int))TObjPlayer__sub_800193FC)(this, 0, 0xD2);
        } else {
            ((s32 (*)(void *, int, f32))TObjPlayer__sub_8001941C)(this, 0, (f32) ((0.0f)));
            ((s32 (*)(void *, int, int))TObjPlayer__sub_800193FC)(this, 0, 0);
        }
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFFC);
        this->actorFlags = (s32) (this->actorFlags | 2);
    }
}

void TObjChara::apply_poison_status() {
    f32 temp_f31;

    if ((((s32 (*)(void *, s32))obj_testFlag_2E4__9TObjCharaFUl)(this, 4) == 0) && ((u16) this->entity_id < 0x1000U) && (this->test_immunity_flags(1) == 0)) {
        ((s32 (*)(void *, s32))spawn_poison_effect__10TObjPlayerFii)(this, 0);
        if (((s32 (*)(void *, s32))obj_getArrWord_254)(this, 0) == 0x10) {
            f32 temp_d4;
            temp_f31 = -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 0);
            temp_d4 = (f32) this->get_s16_2c4();
            sub_800192B4((s32) (temp_d4 * temp_f31));
        }
        ((s32 (*)(void *, s32, s32))TObjPlayer__sub_8001940C)(this, 0, 0xF);
        ((s32 (*)(void *, s32, f32))TObjPlayer__sub_8001941C)(this, 0, (0.0f));
        ((s32 (*)(void *, s32, s32))TObjPlayer__sub_800193FC)(this, 0, 0x2D);
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFFC);
        this->actorFlags = (s32) (this->actorFlags | 1);
    }
}

void TObjPlayer::spawn_recovery_effect() {
    u8 *arg0 = (u8 *)this;
    if (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(arg0, 0x02000000) == 0) {
        create_timed_particle_emitter_with_flags(((u8 *)&this->m_2fc), 0x10A, 0, 0xA, 0x40);
    }
}

void trigger_switch_attack__10TObjPlayerFPvi(void *arg0, s32 arg1) {

    if (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(arg0, 0x02000000) == 0) {
        switch (((TObjChara *)arg0)->m_2e4) {
        case 1:
            spawn_particle_effect_with_flags(arg1, 0xF1, 0x40);
            return;
        case 2:
            spawn_particle_effect_with_flags(arg1, 0xF2, 0x40);
            return;
        case 4:
            spawn_particle_effect_with_flags(arg1, 0xE3, 0x40);
            return;
        case 8:
            spawn_particle_effect_with_flags(arg1, 0x10D, 0x40);
            break;
        }
    }
}

void TObjPlayer::set_attribute_entry(s32 i, void *q) {
    O_80015D74 *self = (O_80015D74 *)this;
    if (i < 3) {
        ((TObjPlayer *)(&self->arr[i]))->copy_entry_bytes(q);
    }
}

void TObjPlayer::copy_entry_bytes(void* q) { *(u8*)((char*)this + 0x0) = *(u8*)((char*)q + 0x0); *(u8*)((char*)this + 0x1) = *(u8*)((char*)q + 0x1); }

s16 *TObjPlayer::get_attribute_entry(s32 i) {
    O_80015DC4 *self = (O_80015DC4 *)this;
    if (i < 3) {
        return &self->arr[i];
    }
    return 0;
}

#pragma push
#pragma fp_contract on
extern const double lbl_80434090;
#define get_ata__10TObjPlayerFv(a) ((short (*)(const void *))get_ata__10TObjPlayerFv)(a)
#define obj_testFlag_2E4__9TObjCharaFUl(a, b) ((int (*)(const void *, RangedU))obj_testFlag_2E4__9TObjCharaFUl)(a, b)
#define VecCopy__FP3VecPC3Vec(a, b) ((void (*)(RangedVec *, const RangedVec *))VecCopy__FP3VecPC3Vec)(a, b)
#define subtract_vector(a, b) ((void (*)(RangedVec *, const RangedVec *))subtract_vector)(a, b)
#define random_ratio__9TObjCharaFv(a) ((float (*)(RangedActor *))random_ratio__9TObjCharaFv)(a)
#define attach_mine_trap__10TObjPlayerFiUi(a, b) ((void (*)(RangedActor *, RangedActor *))attach_mine_trap__10TObjPlayerFiUi)(a, b)
#define show_miss_popup__9TObjCharaFPCf(a, b) ((void (*)(RangedActor *, const RangedVec *))show_miss_popup__9TObjCharaFPCf)(a, b)
int TObjChara::calc_distance_accuracy_penalty(void *attacker, void *body_arg, void *origin, float multiplier) {
    RangedBody*body = (RangedBody*)body_arg;
    RangedVec delta;
    if(((RangedActor*)attacker)&&body&&!(((RangedActor*)this)->flags&0x04000000)) {
        float chance=(0.01f)*((multiplier*(float)get_ata__10TObjPlayerFv(((RangedActor*)attacker)))-((0.2f)*(float)((RangedActor*)this)->evp));
        VecCopy__FP3VecPC3Vec(&delta,&body->center);
        if(!obj_testFlag_2E4__9TObjCharaFUl(((RangedActor*)attacker),0x20)) {
            if(((const RangedVec*)origin))subtract_vector(&delta,((const RangedVec*)origin));
            else subtract_vector(&delta,&((RangedActor*)attacker)->position);
            const float squared=delta.x*delta.x+delta.z*delta.z;
            const float dist=newton_sqrtf(squared);
            float pen=(float)(dist*lbl_80434090);
            pen*=(0.33333334f);
            chance-=pen;
        }
        if((0.0f)<chance&&random_ratio__9TObjCharaFv(((RangedActor*)this))<=chance) {
            body->flags|=0x04000000;attach_mine_trap__10TObjPlayerFiUi(((RangedActor*)this),((RangedActor*)attacker));((RangedActor*)this)->hit_flags|=2;return 1;
        }
        ((RangedActor*)this)->flags|=0x100;VecCopy__FP3VecPC3Vec(&delta,&body->center);show_miss_popup__9TObjCharaFPCf(((RangedActor*)this),&delta);
    }
    return 0;
}
}

#undef get_ata__10TObjPlayerFv
#undef obj_testFlag_2E4__9TObjCharaFUl
#undef VecCopy__FP3VecPC3Vec
#undef subtract_vector
#undef random_ratio__9TObjCharaFv
#undef attach_mine_trap__10TObjPlayerFiUi
#undef show_miss_popup__9TObjCharaFPCf
#pragma pop

const char lbl_805D7DA8[] = "EXP";

void display_exp_gain(s32 arg0, u32 arg1, s32 arg2, s32 arg3) {
    if ((((s32 (*)(s32, u32))obj_testFlags30__14TObjCollidableFUl)(arg0, 0x02000000) == 0) && (((s32 (*)(s32))is_locally_controlled__10TObjPlayerFPv)(arg0) == 0) && (arg1 != 0U)) {
        create_font_small_task(arg1, 0xFFFF00FF, 0x14, arg2, (s32 *)lbl_805D7DA8, arg3, ((s32 (*)(s32))get_entity_id)(arg0));
    }
}

void show_meseta_label(s32 arg0, u32 arg1, s32 arg2, s32 arg3) {
    s32 size;
    if (((s32 (*)(s32, u32))obj_testFlags30__14TObjCollidableFUl)(arg0, 0x02000000) == 0 && arg1 != 0) {
        size = 0x14;
        if (((s32 (*)(s32))is_locally_controlled__10TObjPlayerFPv)(arg0) != 0) {
            size <<= 1;
        }
        ((void (*)(u32, s32, s32, s32, void *, s16, s32))create_font_small_task)(arg1, -0x100, size, arg2, lbl_804340A8, arg3, ((s32 (*)(s32))get_entity_id)(arg0));
    }
}

const char lbl_805D7DAC[] = "TP";

void show_tp_font(s32 arg0, u32 arg1, s32 arg2, s32 arg3) {
    if ((((s32 (*)(s32, s32))obj_testFlags30__14TObjCollidableFUl)(arg0, 0x02000000) == 0) && (((s32 (*)(s32))is_locally_controlled__10TObjPlayerFPv)(arg0) == 0) && (arg1 != 0U)) {
        create_font_small_task_default_color(arg1, 0xFF00B2FF, 0x14, arg2, (s32 *)lbl_805D7DAC, arg3);
    }
}

const char lbl_805D7DB0[] = "HP";

void draw_hp_label(void *arg0, u32 arg1, s32 arg2, s16 arg3) {
    if ((((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(arg0, 0x02000000) == 0) && (((s32 (*)(void *))is_locally_controlled__10TObjPlayerFPv)(arg0) == 0) && (arg1 != 0U)) {
        create_font_small_task_default_color(arg1, 0xFF00FF00, 0x14, arg2, (s32 *)lbl_805D7DB0, (s16)arg3);
    }
}

void TObjChara::try_apply_damage(u32 arg1, s32 arg2) {
    if ((((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(this, 0x02000000) == 0) && (((s32 (*)(void *))is_locally_controlled__10TObjPlayerFPv)(this) == 0) && (arg1 != 0U) && ((s16) arg2 >= 0) && ((TObjPlayer::get_player_count() == 0) || ((u16) this->entity_id >= 0x1000U))) {
        create_damage_font__19TObjEneEpsilonGuardFllll(arg1, -1, 0x14, (s16) arg2);
    }
}

void TObjChara::show_miss_popup(const float *pos) {
    if (((s32 (*)(void *, u32))obj_testFlags30__14TObjCollidableFUl)(this, 0x02000000) == 0 && ((s32 (*)(void *))is_locally_controlled__10TObjPlayerFPv)(this) == 0 && pos != NULL) {
        if (TObjPlayer::get_player_count() == 0 || this->entity_id >= 0x1000) {
            TOCtrlDubchik::create_font((s32)pos, 0xFFFF0000, 0x14, (s32)lbl_804340B0);
        }
    }
}
void TObjPlayer::show_miss_for_collider(s32 collider) {
    show_miss_popup__9TObjCharaFPCf(this, (const float*)((*(u32 *)&this->bodies) + collider*0x2C + 0x1C));
}

#pragma push
#pragma fp_contract on
extern "C" {
s32 TObjChara::roll_physical_accuracy(void *arg1, s32 arg2, f32 farg0) {
    f32 v;

    if (arg1 == NULL) {
        return 0;
    }
    if (((s32 (*)(void *, u32))obj_testFlags30__14TObjCollidableFUl)(this, 0x04000800) == 0) {
        v = (0.01f) * ((farg0 * (f32) get_ata__10TObjPlayerFv(arg1)) - ((0.2f) * (f32) ((Obj_800162E0 *)this)->val2CC));
        if ((0.0f) < v && ((f32 (*)(void *))random_ratio__9TObjCharaFv)(this) <= v) {
            ((Obj_800162E0 *)this)->elems[arg2].flags |= 0x04000000;
            ((Obj_800162E0 *)this)->flags2DC |= 1;
            return 1;
        }
        ((Obj_800162E0 *)this)->flags30 |= 0x100;
    }
    return 0;
}
#pragma pop

s32 TObjChara::try_start_action(s32 arg1, s32 collider) {
    if (((VObj_800163F8 *)this)->m25() != 0) {
        return 1;
    }
    ((TObjPlayer *)this)->show_miss_for_collider(collider);
    return 0;
}

s32 TObjChara::select_melee_contact_body(void *source, f32 factor) {
    s32 selected = -1;
    Vec_80016454 point;
    s32 i;
    s32 diff;
    f32 dist2;
    f32 r2;
    f32 dist;
    f32 r;
    if (((Actor_80016454 *)source) != NULL) {
    if (((Actor_80016454 *)this)->bodies != NULL) {
        ((void (*)(void))push_matrix)();
        set_matrix_identity(0);
        ((void (*)(s32, f32, f32, f32))translate_matrix)(0, -((Actor_80016454 *)source)->pos.x, -((Actor_80016454 *)source)->pos.y, -((Actor_80016454 *)source)->pos.z);
        post_translate_matrix(&((Actor_80016454 *)this)->pos);
        rotate_matrix_y(0, (void *)((Actor_80016454 *)this)->yaw);
        for (i = 0; i < ((Actor_80016454 *)this)->bodyCount; i++) {
            if (!(((Actor_80016454 *)this)->bodies[i].flags & 0x02000000)) {
                ((VecCopyFn_80016454)VecCopy__FP3VecPC3Vec)(&point, &((Actor_80016454 *)this)->bodies[i]);
                matrix_mult_vec(0, &point, &point);
            }
            dist = point.x * point.x + point.z * point.z;
            r = (((Actor_80016454 *)this)->bodies[i].radius + ((TObjChara *)((Actor_80016454 *)source))->get_attack_range()) * (((Actor_80016454 *)this)->bodies[i].radius + ((TObjChara *)((Actor_80016454 *)source))->get_attack_range());
            diff = angle_difference_abs(((Actor_80016454 *)source)->yaw, (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(point.x, point.z)));
            if (dist < r && diff < ((TObjChara *)((Actor_80016454 *)source))->get_attack_angle()) {
                selected = i;
                break;
            }
        }
        pop_matrix();
        if (selected == -1) {
            return 0;
        }
    } else {
        ((VecCopyFn_80016454)VecCopy__FP3VecPC3Vec)(&point, &((Actor_80016454 *)this)->pos);
        subtract_vector(&point, &((Actor_80016454 *)source)->pos);
        dist2 = point.x * point.x + point.z * point.z;
        r2 = ((TObjChara *)((Actor_80016454 *)source))->get_attack_range() * ((TObjChara *)((Actor_80016454 *)source))->get_attack_range();
        r2 = r2 * r2;
        diff = angle_difference_abs(((Actor_80016454 *)source)->yaw, (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(point.x, point.z)));
        if (r2 < dist2 || ((TObjChara *)((Actor_80016454 *)source))->get_attack_angle() < diff) {
            return 0;
        }
    }
    if (((Actor_80016454 *)this)->m24(((Actor_80016454 *)source), selected, factor) != 0) {
        return 1;
    }
    }
    return 0;
}

s32 TObjChara::update_defense_stat_status() {
    s32 temp_ret;
    void *obj;

    if (((s32 (*)(void *, s32))TObjPlayer__sub_8001943C)(((u8 *)this), 3) > 0) {
        temp_ret = ((TObjPlayer *)this)->add_status_effect_timer(3, -1);
        if (temp_ret > 0) {
            if (((temp_ret % 45) == 0) && (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(((u8 *)this), 0x02000000) == 0)) {
                switch (((s32 (*)(void *, s32))obj_getArrWord_254)(((u8 *)this), 3)) {
                case 11:
                    break;
                case 10:
                    this->trigger_switch_attack();
                    if ((((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(((u8 *)this), 0x10000000) == 0) || (((s32 (*)(void *))is_locally_controlled__10TObjPlayerFPv)(((u8 *)this)) != 0)) {
                        ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x40022C2C, ((u8 *)this) + 0x38, 0, 0);
                    }
                    break;
                case 12:
                    this->enemy_spawn_zalure_effect();
                    if ((((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(((u8 *)this), 0x10000000) == 0) || (((s32 (*)(void *))is_locally_controlled__10TObjPlayerFPv)(((u8 *)this)) != 0)) {
                        ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x4002362D, ((u8 *)this) + 0x38, 0, 0);
                    }
                    break;
                }
                obj = ((void * (*)(u32))__nw__7TObjectFUl)(0x64);
                if (obj != 0) {
                    construct_actor_light_task((0.1f), obj, ((u8 *)&player_defense_stat_status_light_colors), ((u8 *)&TObjPlayer__data_80434060), 0x2D, ((u8 *)this), tl_07);
                }
            }
            return 1;
        }
        this->add_to_field_2ce((s32) ((f32) this->get_atp() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(((u8 *)this), 3)));
        ((s32 (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x278);
    } else if (((s32 (*)(void *))obj_isState2_324__9TObjCharaFv)(((u8 *)this)) != 0) {
        this->add_to_field_2ce((s32) ((f32) this->get_atp() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(((u8 *)this), 3)));
        ((s32 (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x278);
    }
    return 0;
}

s32 TObjChara::update_attack_stat_status() {
    s32 temp_ret;
    void *obj;

    if (((s32 (*)(void *, s32))TObjPlayer__sub_8001943C)(((u8 *)this), 2) > 0) {
        temp_ret = ((TObjPlayer *)((u8 *)this))->add_status_effect_timer(2, -1);
        if (temp_ret > 0) {
            if (((temp_ret % 45) == 0) && (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(((u8 *)this), 0x02000000) == 0)) {
                switch (((s32 (*)(void *, s32))obj_getArrWord_254)(((u8 *)this), 2)) {
                case 10:
                    break;
                case 9:
                    ((TObjChara *)((u8 *)this))->apply_switch_attack();
                    if ((((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(((u8 *)this), 0x10000000) == 0) || (((s32 (*)(void *))is_locally_controlled__10TObjPlayerFPv)(((u8 *)this)) != 0)) {
                        ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x4002462A, ((u8 *)this) + 0x38, 0, 0);
                    }
                    break;
                case 11:
                    ((TObjChara *)((u8 *)this))->enemy_spawn_jellen_effect();
                    if ((((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(((u8 *)this), 0x10000000) == 0) || (((s32 (*)(void *))is_locally_controlled__10TObjPlayerFPv)(((u8 *)this)) != 0)) {
                        ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x4002442B, ((u8 *)this) + 0x38, 0, 0);
                    }
                    break;
                }
                obj = ((void * (*)(u32))__nw__7TObjectFUl)(0x64);
                if (obj != 0) {
                    construct_actor_light_task((0.1f), obj, ((u8 *)&player_attack_stat_status_light_colors), ((u8 *)&TObjPlayer__data_80434060), 0x2D, ((u8 *)this), tl_07);
                }
            }
            return 1;
        }
        ((TObjChara *)((u8 *)this))->add_to_field_2c8((s32) ((f32) ((TObjChara *)((u8 *)this))->get_field_2c0() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(((u8 *)this), 2)));
        ((TObjChara *)((u8 *)this))->add_to_field_2ca((s32) ((f32) ((TObjChara *)((u8 *)this))->get_field_2c2() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(((u8 *)this), 2)));
        ((s32 (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x26C);
    } else if (((s32 (*)(void *))obj_isState2_324__9TObjCharaFv)(((u8 *)this)) != 0) {
        ((TObjChara *)((u8 *)this))->add_to_field_2c8((s32) ((f32) ((TObjChara *)((u8 *)this))->get_field_2c0() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(((u8 *)this), 2)));
        ((TObjChara *)((u8 *)this))->add_to_field_2ca((s32) ((f32) ((TObjChara *)((u8 *)this))->get_field_2c2() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(((u8 *)this), 2)));
        ((s32 (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x26C);
    }
    return 0;
}

struct ObjFlags;
struct O_800194AC;
s32 TObjChara::update_shock_clock() {
    f32 temp_f31;
    f32 fv;
    s32 temp_ret;
    if (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(this, 4) != 0) {
        temp_ret = ((TObjPlayer *)((u8 *)this))->add_status_effect_timer(1, -1);
        if (temp_ret > 0) {
            this->obj_clearFlags30((u32)0x3C);
            ((void (*)(void *, s32))obj_setFlags30)(this, 4);
            if ((temp_ret % 45) == 0) {
                ((void (*)(void *, s32))play_shock_feedback__10TObjPlayerFii)(this, 1);
            }
            return 1;
        }
        this->obj_clearFlags30((u32)0x3C);
        *(s32 *)((s8 *)((u8 *)this) + 0x330) = (s32) (this->actorFlags & 0x3F);
        if ((u16) this->entity_id >= 0x1000U) {
            temp_f31 = -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 1);
            fv = (f32) this->get_s16_2c4();
            this->sub_800192B4((s32) (fv * temp_f31));
        }
        reset_status_effect_row(((u8 *)this) + 0x260);
        goto block_8;
    }
block_8:
    return 0;
}

s32 TObjChara::update_movement_status() {
    f32 temp_f31;
    f32 fv;
    s32 temp_ret;

    if (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(this, 0x20) != 0) {
        temp_ret = ((TObjPlayer *)((u8 *)this))->add_status_effect_timer(1, -1);
        if (temp_ret > 0) {
            this->obj_clearFlags30((u32)0x3C);
            ((s32 (*)(void *, s32))obj_setFlags30)(this, 0x20);
            if ((temp_ret % 45) == 0) {
                ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0xB20F, ((u8 *)this) + 0x38, 0, 0);
            }
            return 1;
        }
        this->obj_clearFlags30((u32)0x3C);
        *(s32 *)((s8 *)((u8 *)this) + 0x330) = (s32) (this->actorFlags & 0x3F);
        temp_f31 = -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 1);
        fv = (f32) this->get_s16_2c4();
        this->sub_800192B4((s32) (fv * temp_f31));
        ((s32 (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x260);
        goto block_6;
    }
block_6:
    return 0;
}

s32 TObjChara::update_flag30_timer() {
    s32 temp_ret;

    if (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(this, 0x10) != 0) {
        temp_ret = ((TObjPlayer *)((u8 *)this))->add_status_effect_timer(1, -1);
        if (temp_ret > 0) {
            this->obj_clearFlags30((u32)0x3C);
            ((s32 (*)(void *, s32))obj_setFlags30)(this, 0x10);
            if ((temp_ret % 45) == 0) {
                ((s32 (*)(void *, s32))spawn_confusion_feedback_effect)(this, 1);
            }
            return 1;
        }
        this->obj_clearFlags30((u32)0x3C);
        *(s32 *)((s8 *)((u8 *)this) + 0x330) = (s32) (this->actorFlags & 0x3F);
        ((s32 (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x260);
        goto block_6;
    }
block_6:
    return 0;
}

s32 TObjChara::vfunc_37() {
    s32 temp_ret;

    if ((((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(((u8 *)this), 8) != 0) && ((u16) ((TObjChara *)((u8 *)this))->entity_id < 0x1000U)) {
        temp_ret = ((TObjPlayer *)((u8 *)this))->add_status_effect_timer(1, -1);
        if (temp_ret > 0) {
            if ((temp_ret % 45) == 0) {
                ((s32 (*)(void *, s32))spawn_slow_effect__10TObjPlayerFii)(((u8 *)this), 1);
            }
            return 1;
        }
        ((TObjBase *)((u8 *)this))->obj_clearFlags30((u32)0x3C);
        *(s32 *)((s8 *)((u8 *)this) + 0x330) = (s32) (((TObjChara *)((u8 *)this))->actorFlags & 0x3F);
        ((s32 (*)(void *))reset_status_effect_row)(((u8 *)this) + 0x260);
        goto block_7;
    }
block_7:
    return 0;
}

s32 TObjChara::update_action_hold_status() {
    f32 temp_f31;
    s32 temp_r31;

    if ((((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(this, 0x4000) != 0) && ((u16) this->entity_id >= 0x1000U)) {
        if (((TObjPlayer *)((u8 *)this))->add_status_effect_timer(4, -1) <= 0) {
            ((s32 (*)(void *))reset_status_effect_row)((void *) (((u8 *)this) + 0x284));
            this->obj_clearFlags30((u32)(0x4000));
        }
        return 1;
    }
    if (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)((void *) (((u8 *)this)), 2) != 0) {
        temp_r31 = ((TObjPlayer *)((u8 *)this))->add_status_effect_timer(0, -1);
        if ((u16) this->entity_id < 0x1000U) {
            if (temp_r31 <= 0) {
                ((s32 (*)(void *, int))spawn_paralysis_feedback_effect)((void *) (((u8 *)this)), 1);
                ((s32 (*)(void *, int, int))TObjPlayer__sub_800193FC)((void *) (((u8 *)this)), 0, 0x2D);
            }
            return 1;
        }
        if (temp_r31 > 0) {
            ((TObjBase *)((u8 *)this))->obj_clearFlags30((u32)(3));
            ((s32 (*)(void *, s32))obj_setFlags30)((void *) (((u8 *)this)), 2);
            if ((temp_r31 % 45) == 0) {
                ((s32 (*)(void *, int))spawn_paralysis_feedback_effect)((void *) (((u8 *)this)), 1);
            }
            return 1;
        }
        ((TObjBase *)((u8 *)this))->obj_clearFlags30((u32)(3));
        *(s32 *)((s8 *)((u8 *)this) + 0x330) = (s32) (this->actorFlags & 0x3F);
        temp_f31 = -((f32 (*)(void *, int))TObjPlayer__sub_800192C4)((void *) (((u8 *)this)), 0);
        {
            f32 v = ((TObjChara *)((u8 *)this))->get_s16_2c4();
            v *= temp_f31;
            ((TObjChara *)((u8 *)this))->sub_800192B4((s32) v);
        }
        ((s32 (*)(void *))reset_status_effect_row)((void *) (((u8 *)this) + 0x254));
    }
    return 0;
}

s32 TObjChara::update_poison_status() {
    s32 dmg;

    if (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(this, 1) != 0) {
        if ((((TObjPlayer *)((u8 *)this))->add_status_effect_timer(0, 1) % 45) == 0) {
            ((s32 (*)(void *, int))spawn_poison_effect__10TObjPlayerFii)(((u8 *)this), 1);
            ((s32 (*)(void *, int, int))TObjPlayer__sub_800193FC)(this, 0, 0);
            dmg = (s32) ((0.006666667f) * (f32) ((s16 (*)(void *))get_actor_hp)(this));
            if ((s16) dmg < 1) {
                dmg = 1;
            }
            ((s32 (*)(u8 *, s32, void *))TObjectV8047c128_subtract_hp)(((u8 *)this), dmg + lbl_8043406C[game_difficulty_selection], lbl_8043406C);
            if (this->clamp_hp() <= 0) {
                if (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(this, 0x800) == 0) {
                    ((TObjPlayer *)((u8 *)this))->set_hp_clamped(1);
                }
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

#define VCOPY(d, s) ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((d), (s))

s32 TObjChara::vfunc_43() {
    if (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(this, 0x40) != 0) {
        this->clear_harmful_statuses();
        return 1;
    }
    if (((s32 (*)(void *))obj_isState2_324__9TObjCharaFv)(this) != 0) {
        if (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(this, 3) == 0) {
            switch (((s32 (*)(void *, s32))obj_getArrWord_254)(this, 0)) {
            case 0x10:
                sub_800192B4((s32)(this->get_s16_2c4() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 0)));
                break;
            }
            reset_status_effect_row(((Player_800172CC *)this)->f254);
        }
        if (((s32 (*)(void *, s32))obj_testFlags30__14TObjCollidableFUl)(this, 0x3C) == 0) {
            switch (((s32 (*)(void *, s32))obj_getArrWord_254)(this, 1)) {
            case 2:
            case 3:
                sub_800192B4((s32)(this->get_s16_2c4() * -((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(this, 1)));
                break;
            }
            reset_status_effect_row(((Player_800172CC *)this)->f260);
        }
    }
    return 0;
}

s32 TObjChara::is_target_in_attack_range() {
    Vec_8001745C v;
    Vec_8001745C base;
    Vec_8001745C out;
    Target_8001745C *t;
    s32 i;
    s32 ang;
    f32 range;
    f32 dist;
    f32 prod;
    Player_8001745C *p = (Player_8001745C *)this;
    if (p->target != NULL && p->f318 != 0 &&
        ((TObject *)(p->target))->all_parents_unqueued_for_destruction() != 0 &&
        ((u8 * (*)(u16))find_entity_by_id)(((u16 (*)(void *))get_entity_id)(p->target)) != NULL) {
        t = p->target;
        if (!(t->flags30 & 0x800)) {
            if (t->parts != NULL) {
                VCOPY(&base, &t->pos);
                for (i = 0; i < p->target->nparts; i++) {
                    if (!(p->target->parts[i].flags & 0x02000000)) {
                        VCOPY(&v, &p->target->parts[i]);
                        push_matrix_from(&identity_matrix);
                        rotate_matrix_y(0, (void *)p->target->rotY);
                        rotate_vector_by_matrix(0, &v, &v);
                        pop_matrix();
                        vec3_add_to(&v, &base);
                        subtract_vector(&v, &p->pos);
                        dist = v.x * v.x + v.z * v.z;
                        range = (p->target->parts[i].radius + ((TObjChara *)p)->get_attack_range()) * (p->target->parts[i].radius + ((TObjChara *)p)->get_attack_range());
                        ang = ((s32)angle_difference_abs(p->rotY, (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(v.x, v.z))));
                        if (dist < range && ang < ((TObjChara *)p)->get_attack_angle()) {
                            return 1;
                        }
                    }
                }
            } else {
                dist = calc_xz_distance_sq((s32)((s32)p), (u32)((u32)t), &out);
                ang = ((s32)angle_difference_abs(p->rotY, (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(out.x, out.z))));
                if (p->target->parts != NULL) {
                    prod = (p->target->parts->radius + ((TObjChara *)p)->get_attack_range()) * (p->target->parts->radius + ((TObjChara *)p)->get_attack_range());
                } else {
                    prod = ((TObjChara *)p)->get_attack_range() * ((TObjChara *)p)->get_attack_range();
                }
                if (dist <= prod && ang <= ((TObjChara *)p)->get_attack_angle()) {
                    return 1;
                }
            }
        } else {
            p->target = NULL;
        }
    }
    return 0;
}

f32 enemy_move_toward(u8 *arg0, s32 arg1, Vec_800180E8 arg2, s32 arg3, f32 farg0) {
    if (horizontal_distance_squared(arg0 + 0x29C, arg0 + 0x38) < (1e-05f) || ((TObjEnemy *)(arg0))->is_actor_cadence_frame(0x1E) != 0) {
        if (((s32 (*)(void *, Vec_800180E8, int)) select_enemy_destination)(arg0, arg2, arg3) != 0) {
            ((s32 (*)(void *, Vec_800180E8)) copy_position_if_valid__10TObjPlayerFii)(arg0, *(Vec_800180E8 *)(arg0 + 0x2FC));
        }
    }
    enemy_turn_toward_dest((Obj_80018660 *)arg0, arg1);
    enemy_set_heading_velocity((TObjEnemy *)arg0, ((TObjEnemy *)arg0)->rotation_y, farg0);
    move_with_wall_slide(arg0);
    return horizontal_distance_squared(&arg2, arg0 + 0x38);
}

f32 step_toward_destination__10TObjPlayerFPvPvf(Obj_80017804 *arg0, Vec_800180E8 *arg1, f32 farg0) {
    VecCopy__FP3VecPC3Vec((s32) &arg0->dest, (s32) arg1);
    VecCopy__FP3VecPC3Vec((s32) &arg0->home, (s32) &arg0->cur);
    ((void (*)(void *, Vec_800180E8, Vec_800180E8, f32)) calc_velocity_toward_destination)(arg0, arg0->home, arg0->dest, farg0);
    arg0->pos.x += arg0->vx;
    arg0->pos.z += arg0->vz;
    return horizontal_distance_squared(arg1, &arg0->pos);
}

f32 enemy_pursue_point(u8 *arg0, s32 arg1, Vec_800180E8 arg2, f32 farg0, f32 farg1) {
    f32 d0;
    f32 d1;
    f32 d2;
    s32 a;
    Vec_800180E8 d;
    d0 = horizontal_distance_squared(arg0 + 0x2FC, arg0 + 0x290);
    d1 = horizontal_distance_squared(arg0 + 0x290, arg0 + 0x29C);
    d2 = horizontal_distance_squared(arg0 + 0x2FC, arg0 + 0x29C);
    if (farg1 * farg1 <= d0 || d1 < (1e-05f) || d2 < (1e-05f) || ((TObjEnemy *)(arg0))->is_actor_cadence_frame(0x96) != 0) {
        VecCopy__FP3VecPC3Vec((s32)&d, (s32)&arg2);
        subtract_vector(&d, arg0 + 0x2FC);
        a = (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(d.x, d.z));
        d.z = farg1;
        d.x = d.y = (0.0f);
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, (void *)a);
        rotate_vector_by_matrix(0, &d, &d);
        pop_matrix();
        vec3_add_to(&d, arg0 + 0x2FC);
        if (((s32 (*)(void *, Vec_800180E8, int)) select_enemy_destination)(arg0, d, 1) != 0) {
            ((s32 (*)(void *, Vec_800180E8)) copy_position_if_valid__10TObjPlayerFii)(arg0, *(Vec_800180E8 *)(arg0 + 0x2FC));
        }
    }
    enemy_turn_toward_dest((Obj_80018660 *)arg0, arg1);
    enemy_set_heading_velocity((TObjEnemy *)arg0, ((TObjEnemy *)arg0)->rotation_y, farg0);
    move_with_wall_slide(arg0);
    return horizontal_distance_squared(&arg2, arg0 + 0x2FC);
}

f32 enemy_backstep_from_point(Obj_80017ABC *arg0, Vec_800180E8 arg1, f32 farg0) {
    if (TObjPlayer__sub_800181DC((u8 *)((u8 *) arg0), (Vec_800180E8)(arg1)) != 0) {
        ((s32 (*)(void *, Vec_800180E8)) copy_position_if_valid__10TObjPlayerFii)(arg0, arg0->cur);
        ((void (*)(void *, Vec_800180E8, Vec_800180E8, f32)) calc_velocity_toward_destination)(arg0, arg0->home, arg0->dest, farg0);
        move_with_wall_slide((u8 *)arg0);
        return horizontal_distance_squared(&arg1, &arg0->pos);
    }
    return (0.0f);
}

f32 TObjEnemy::enemy_wander_home(s32 arg1, f32 farg0, f32 farg1, f32 farg2) {
    Vec_80017BA8 v;
    f32 var_f31;
    s32 ang;
    u8 *arg0 = (u8 *)this;
    var_f31 = horizontal_distance_squared((u8 *)&this->m_2fc, (u8 *)&this->m_29c);
    if ((var_f31 < (farg0 * farg0)) || (((TObjEnemy *)(arg0))->is_actor_cadence_frame(0x96) != 0)) {
        v.x = v.y = (0.0f);
        v.z = (1.0f);
        ang = (s32) ((182.04445f) * ((3.6e+02f) * ((f32 (*)(void *))random_ratio__9TObjCharaFv)(arg0)));
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, (void *) ang);
        rotate_vector_by_matrix(0, &v, &v);
        pop_matrix();
        v.x *= farg1;
        v.z *= farg2;
        vec3_add_to(&v, (u8 *)&this->home_position);
        {
            Vec_80017BA8 c = v;
            select_enemy_destination((Obj_800182A0 *) arg0, (Vec_800182A0 *) &c, 1);
        }
        *(f32 *)((s8 *)arg0 + 0x308) = ((TObjEnemy *)arg0)->m_310 = (0.0f);
        ((TObjEnemy *)arg0)->m_2ac = 0;
    } else {
        enemy_turn_toward_dest((Obj_80018660 *) arg0, arg1);
        enemy_set_heading_velocity((TObjEnemy *)arg0, ((TObjEnemy *)arg0)->rotation_y, farg0);
        move_with_wall_slide(arg0);
        var_f31 = horizontal_distance_squared((u8 *)&this->m_29c, (u8 *)&this->m_2fc);
        ((TObjEnemy *)arg0)->m_2ac = ((TObjEnemy *)arg0)->m_2ac + 1;
    }
    return var_f31;
}

f32 update_enemy_wander_move(Obj_80017ABC *arg0, Vec_800180E8 arg1, s32 arg2, f32 farg0) {
    if (((TObjEneLappy *)(arg0))->is_actor_cadence_frame(0x1E) != 0) {
        if (((s32 (*)(void *, Vec_800180E8, int)) select_enemy_destination)(arg0, arg1, arg2) != 0) {
            ((s32 (*)(void *, Vec_800180E8)) copy_position_if_valid__10TObjPlayerFii)(arg0, arg0->cur);
        }
    }
    ((void (*)(void *, Vec_800180E8, Vec_800180E8, f32)) calc_velocity_toward_destination)(arg0, arg0->home, arg0->dest, farg0);
    move_with_wall_slide((u8 *)arg0);
    return horizontal_distance_squared(&arg1, &arg0->pos);
}
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void move_with_wall_slide(u8 *arg0) {
  Obj_80017E6C *self = (Obj_80017E6C *) arg0;
  Vec_80017E6C next;
  Vec_80017E6C dir;
  Vec_80017E6C nrm;
  Hit_80017E6C *hit;
  Plane_80017E6C *pl;
  f32 len;
  f32 new_var;
  f32 xx;
  f32 zz;
  VecCopy__FP3VecPC3Vec((s32)&self->prev, (s32)&self->pos);
  VecCopy__FP3VecPC3Vec((s32)&next, (s32)&self->cur);
  vec3_add_to(&next, &self->vel);
  VecCopy__FP3VecPC3Vec((s32)&dir, (s32)&self->vel);
  normalize_vector_xz((Vec *)(&dir));
  next.x = ((5.0f) * dir.x) + next.x;
  next.z = ((5.0f) * dir.z) + next.z;
  hit = (Hit_80017E6C *) csnVector(&self->cur, &next, 0x8FE0);
  if (hit != 0)
  {
    pl = hit->plane;
    nrm.x = pl->f14;
    nrm.z = -pl->fC;
    normalize_vector_xz((Vec *)(&nrm));
    xx = self->vel.x * self->vel.x;
    zz = self->vel.z * self->vel.z;
    len = newton_sqrtf(xx + zz);
    if (((self->vel.x * (new_var = nrm.x)) + (self->vel.z * nrm.z)) >= (0.0f))
    {
      self->vel.x = new_var * len;
      self->vel.z = nrm.z * len;
    }
    else
    {
      self->vel.x = (-new_var) * len;
      self->vel.z = (-nrm.z) * len;
    }
    VecCopy__FP3VecPC3Vec((s32)&next, (s32)&self->cur);
    vec3_add_to(&next, &self->vel);
    VecCopy__FP3VecPC3Vec((s32)&dir, (s32)&self->vel);
    normalize_vector_xz((Vec *)(&dir));
    next.x = ((5.0f) * dir.x) + next.x;
    next.z = ((5.0f) * dir.z) + next.z;
    if (csnVector(&self->cur, &next, 0x8FE0) != 0)
    {
      return;
    }
  }
  VecCopy__FP3VecPC3Vec((s32)&next, (s32)&self->cur);
  vec3_add_to(&next, &self->vel);
  next.y += (1e+01f);
  if ((csnVecterUnder(&next, 0xE0) == 0) && (project_actor_to_ground((s32) self, (s32)&next, 0) != 0))
  {
    VecCopy__FP3VecPC3Vec((s32)&self->pos, (s32)&next);
  }
}
#pragma pop

void enemy_set_heading_velocity(TObjEnemy *enemy, s32 arg1, f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_8001806C, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_8001806C, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_8001806C, sp10) == 0x8) ? 1 : -1];
    Stack_8001806C stack;
    stack.sp10 = farg0;
    stack.spC = (0.0f);
    stack.sp8 = (0.0f);
    push_matrix_from(&identity_matrix.value);
    rotate_matrix_y(0, (void *)arg1);
    rotate_vector_by_matrix(0, &stack.sp8, &stack.sp8);
    pop_matrix();
    *(f32 *)((s8 *)enemy + 0x308) = stack.sp8;
    enemy->m_310 = stack.sp10;
}

void calc_velocity_toward_destination(Obj_800180E8 *self, Vec_800180E8 *pos, Vec_800180E8 *dest, f32 speed) {
    Vec_800180E8 d;
    s32 a;
    VecCopy__FP3VecPC3Vec((s32)&d, (s32)dest);
    subtract_vector(&d, pos);
    if (d.x * d.x + d.z * d.z < (1e-05f)) {
        self->vz = (0.0f);
        self->vx = (0.0f);
    } else {
        a = (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(d.x, d.z));
        d.z = speed;
        d.x = d.y = (0.0f);
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, (void *)a);
        rotate_vector_by_matrix(0, &d, &d);
        pop_matrix();
        self->vx = d.x;
        self->vz = d.z;
    }
}

s32 TObjPlayer__sub_800181DC(u8 *arg0, Vec_800180E8 arg1) {
    Vec_800180E8 d;
    VecCopy__FP3VecPC3Vec((s32) &d, (s32) &arg1);
    subtract_vector(&d, arg0 + 0x2FC);
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(0, (void *) 0x8000);
    rotate_vector_by_matrix(0, &d, &d);
    pop_matrix();
    if ((1e-05f) < vec_squared_length(&d)) {
        normalize_vector(&d);
        vec3_add_to(&d, arg0 + 0x2FC);
        return ((s32 (*)(void *, Vec_800180E8, int)) select_enemy_destination)(arg0, d, 1);
    }
    return 0;
}

s32 select_enemy_destination(Obj_800182A0 *self, Vec_800182A0 *arg1, int flags) {
    Vec_800182A0 d;
    s32 a;
    if (project_actor_to_ground((s32)self, (s32)arg1, 0) != 0) {
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&d, arg1);
        if (!(flags & 1)) {
            d.y = self->pos.y;
        } else {
            d.y += self->pos.y - self->f3C;
        }
        if (self->fA4 != NULL) {
            subtract_vector(&d, &self->pos);
            a = (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(d.x, d.z));
            scratch_vec.x = scratch_vec.y = (0.0f);
            scratch_vec.z = self->fA4->fC;
            push_matrix_from(&identity_matrix);
            rotate_matrix_y(0, (void *)a);
            rotate_vector_by_matrix(0, &scratch_vec, &scratch_vec);
            pop_matrix();
            vec3_add_to(&d, &scratch_vec);
            vec3_add_to(&d, &self->pos);
        }
        if (!(flags & 2) && check_path_obstructed((u8 *)self, (Vec_80018428 *)&d) != 0) {
            return 0;
        }
        if (!(flags & 4) && csnVector(&self->pos, &d, -1) != 0) {
            return 0;
        }
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&self->f29C, arg1);
    return 1;
    }
    return 0;
}

s32 check_path_obstructed(u8 *arg0, Vec_80018428 *arg1) {
    Vec_80018428 d;
    s32 a;
    ((s32 (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&d, arg1);
    subtract_vector(&d, arg0 + 0x2FC);
    if ((9e+04f) < (d.x * d.x) + (d.z * d.z)) {
        a = (s32) (TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(d.x, d.z));
        d.y = d.x = (0.0f);
        d.z = (3e+02f);
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, (void *) a);
        rotate_vector_by_matrix(0, &d, &d);
        pop_matrix();
        vec3_add_to(&d, arg0 + 0x2FC);
    } else {
        ((s32 (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&d, arg1);
    }
    if (csnLookAt(arg0 + 0x2FC, &d) != 0) {
        return 1;
    }
    return 0;
}

s32 copy_position_if_valid__10TObjPlayerFii(s32 arg0, s32 arg1) {
    if (project_actor_to_ground(arg0, arg1, 0) != 0) {
        VecCopy__FP3VecPC3Vec(arg0 + 0x290, arg0 + 0x38);
        return 1;
    }
    return 0;
}

void enemy_turn_half_toward_dest(Obj_80018570 *self) {
    Vec_80018570 d;
    s32 a;
    VecCopy__FP3VecPC3Vec((s32)&d, (s32)&self->dest);
    subtract_vector(&d, &self->pos);
    a = (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(d.x, d.z));
    self->angle = lerp_angle_half__10TObjPlayerFUsUs(self->angle, a);
    angle_difference_abs(self->angle, a);
}

s32 TObjEnemy::turn_toward_direction(s32 max_step, Vec *direction) {
    s32 target_angle;

    target_angle = (s32) (TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(direction->x, direction->z));
    this->rotation_y = approach_angle_limited(this->rotation_y, target_angle, max_step);
    return angle_difference_abs(this->rotation_y, target_angle);
}

void enemy_turn_toward_dest(Obj_80018660 *self, s32 turn) {
    Vec_80018660 d;
    s32 a;
    VecCopy__FP3VecPC3Vec((s32)&d, (s32)&self->dest);
    subtract_vector(&d, &self->pos);
    a = (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(d.x, d.z));
    self->angle = approach_angle_limited(self->angle, a, turn);
    angle_difference_abs(self->angle, a);
}

f32 calc_xz_distance_sq(s32 arg0, u32 arg1, void *arg2) {
    Vec_800186E8 diff;
    f32 dist;
    if (arg1 != 0U) {
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&diff, (void *)(arg1 + 0x38));
        ((void (*)(void *, void *))subtract_vector)(&diff, (void *)(arg0 + 0x38));
        diff.y = (0.01f);
        dist = (diff.x * diff.x) + (diff.z * diff.z);
        if (arg2 != NULL) {
            ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg2, &diff);
        }
    } else {
        dist = (1e+08f);
    }
    return dist;
}

f32 TObjPlayer::calc_distance_to_client(s32 arg0, u16 arg1, u32 arg2) {
  Stack_80018780 stack;
  f32 var_f31;
  s32 temp_r31;
  s32 temp_r3;
  var_f31 = (1e+08f);
  if (arg1 < 0x1000U)
  {
    temp_r3 = ((s32 (*)(u32))get_player_by_client_id)((u32) arg1);
    if ((temp_r3 != 0) && (!((((TObjPlayer *)temp_r3)->actorFlags) & 0x800)))
    {
      ;
      if (((TObjPlayer *)temp_r3)->get_field_3e4() == get_current_floor())
      {
        var_f31 = calc_xz_distance_sq(arg0, (u32)((u32) temp_r3), &stack.sp8);
        if (arg2 != 0U)
        {
          VecCopy__FP3VecPC3Vec((s32)((void *) arg2), (s32)&stack.sp8);
        }
      }
    }
  }
  return var_f31;
}

#undef VCOPY

s32 TObjChara::set_motion_params(void *motion_arg) {
    Motion_8001882C *motion = (Motion_8001882C *)motion_arg;
    if (motion != NULL) {
        ((Player_8001882C *)this)->motion = motion;
        ((Player_8001882C *)this)->f2b8 = ((Player_8001882C *)this)->motion->f6 + ((Player_8001882C *)this)->motion->f18 + ((Player_8001882C *)this)->f2bc;
        ((Player_8001882C *)this)->f2ba = ((Player_8001882C *)this)->motion->f2 + ((Player_8001882C *)this)->motion->f18 + ((Player_8001882C *)this)->f2be;
        ((Player_8001882C *)this)->f32c = ((Player_8001882C *)this)->f2b8;
        ((Player_8001882C *)this)->f32e = ((Player_8001882C *)this)->f2ba;
    } else if (((Player_8001882C *)this)->motion != NULL) {
        ((Player_8001882C *)this)->f2b8 = ((Player_8001882C *)this)->motion->f6 + ((Player_8001882C *)this)->motion->f18 + ((Player_8001882C *)this)->f2bc;
        ((Player_8001882C *)this)->f2ba = ((Player_8001882C *)this)->motion->f2 + ((Player_8001882C *)this)->motion->f18 + ((Player_8001882C *)this)->f2be;
    } else {
        return 0;
    }
    ((Player_8001882C *)this)->f2c0 = ((Player_8001882C *)this)->f2c8 = ((Player_8001882C *)this)->motion->f0;
    ((Player_8001882C *)this)->f2c2 = ((Player_8001882C *)this)->f2ca = 0;
    ((Player_8001882C *)this)->f2c4 = ((Player_8001882C *)this)->f2cc = ((Player_8001882C *)this)->motion->f4;
    ((Player_8001882C *)this)->f2c6 = ((Player_8001882C *)this)->f2ce = ((Player_8001882C *)this)->motion->f8;
    ((Player_8001882C *)this)->f2d0 = (0.1f) * (f32)((Player_8001882C *)this)->motion->fa;
    ((Player_8001882C *)this)->f2d2 = ((Player_8001882C *)this)->motion->fc;
    ((Player_8001882C *)this)->f2ee = 0;
    ((Player_8001882C *)this)->f2f0 = 0;
    ((Player_8001882C *)this)->f2ec = 0;
    ((Player_8001882C *)this)->f2ea = 0;
    ((Player_8001882C *)this)->f2e8 = 0;
    ((Player_8001882C *)this)->f2f8 = 0;
    ((Player_8001882C *)this)->f2fa = 0;
    ((Player_8001882C *)this)->f2f6 = 0;
    ((Player_8001882C *)this)->f2f4 = 0;
    ((Player_8001882C *)this)->f2f2 = 0;
    return 1;
}

#pragma push
#pragma fp_contract on
s32 TObjChara::recalc_combat_stats(void *motion_arg, void *arg2, void *bonus_arg, f32 xscale, f32 yscale) {
    Motion_80018990 *motion = (Motion_80018990 *)motion_arg;
    Bonus_80018990 *bonus = (Bonus_80018990 *)bonus_arg;
    if (motion != NULL) {
        ((Player_80018990 *)this)->motion = motion;
        ((Player_80018990 *)this)->f2b8 = xscale * (f32)(((Player_80018990 *)this)->motion->f6 + ((Player_80018990 *)this)->motion->f18) + (f32)((Player_80018990 *)this)->f2bc;
        ((Player_80018990 *)this)->f32c = ((Player_80018990 *)this)->f2b8;
        if (((s32 (*)(void *, s32))obj_testFlag_2E4__9TObjCharaFUl)(this, 4) != 0) {
            ((Player_80018990 *)this)->f2ba = 0;
            ((Player_80018990 *)this)->f32e = 0;
        } else {
            ((Player_80018990 *)this)->f2ba = yscale * (f32)(((Player_80018990 *)this)->motion->f2 + ((Player_80018990 *)this)->motion->f18) + (f32)((Player_80018990 *)this)->f2be;
            ((Player_80018990 *)this)->f32e = ((Player_80018990 *)this)->f2ba;
        }
    } else if (((Player_80018990 *)this)->motion != NULL) {
        ((Player_80018990 *)this)->f2b8 = xscale * (f32)(((Player_80018990 *)this)->motion->f6 + ((Player_80018990 *)this)->motion->f18) + (f32)((Player_80018990 *)this)->f2bc;
        if (((s32 (*)(void *, s32))obj_testFlag_2E4__9TObjCharaFUl)(this, 4) != 0) {
            ((Player_80018990 *)this)->f2ba = 0;
            ((Player_80018990 *)this)->f32e = 0;
        } else {
            ((Player_80018990 *)this)->f2ba = yscale * (f32)(((Player_80018990 *)this)->motion->f2 + ((Player_80018990 *)this)->motion->f18) + (f32)((Player_80018990 *)this)->f2be;
        }
    } else {
        return 0;
    }
    if (arg2 != NULL) {
        ((Player_80018990 *)this)->f318 = arg2;
    } else if (((Player_80018990 *)this)->f318 == NULL) {
        return 0;
    }
    if (bonus != NULL) {
        ((Player_80018990 *)this)->bonus = bonus;
    } else if (((Player_80018990 *)this)->bonus == NULL) {
        return 0;
    }
    ((Player_80018990 *)this)->f2c0 = ((Player_80018990 *)this)->f2c8 = ((Player_80018990 *)this)->motion->f0;
    ((Player_80018990 *)this)->f2c2 = ((Player_80018990 *)this)->f2ca = ((s32 (*)(void *))get_stats_atp_max__9TObjCharaFv)(((Player_80018990 *)this)) - ((s32 (*)(void *))get_actor_attack_params_atp_min__9TObjCharaFv)(((Player_80018990 *)this));
    ((Player_80018990 *)this)->f2c4 = ((Player_80018990 *)this)->f2cc = ((Player_80018990 *)this)->motion->f4 + ((Player_80018990 *)this)->bonus->f0;
    ((Player_80018990 *)this)->f2c6 = ((Player_80018990 *)this)->f2ce = ((Player_80018990 *)this)->motion->f8 + ((Player_80018990 *)this)->bonus->f1c;
    ((Player_80018990 *)this)->f2d0 = (0.1f) * (f32)(((Player_80018990 *)this)->motion->fa + sub_800194C4());
    ((Player_80018990 *)this)->f2d2 = ((Player_80018990 *)this)->motion->fc;
    ((Player_80018990 *)this)->f2f2 = ((Player_80018990 *)this)->bonus->f2;
    ((Player_80018990 *)this)->f2f4 = ((Player_80018990 *)this)->bonus->f6;
    ((Player_80018990 *)this)->f2f6 = ((Player_80018990 *)this)->bonus->f4;
    ((Player_80018990 *)this)->f2fa = ((Player_80018990 *)this)->bonus->f8;
    ((Player_80018990 *)this)->f2f8 = ((Player_80018990 *)this)->bonus->fa;
    ((TObjChara *)((Player_80018990 *)this))->add_to_field_2c8((f32)((TObjChara *)((Player_80018990 *)this))->get_field_2c0() * ((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(((Player_80018990 *)this), 2));
    ((TObjChara *)((Player_80018990 *)this))->add_to_field_2ca((f32)((TObjChara *)((Player_80018990 *)this))->get_field_2c2() * ((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(((Player_80018990 *)this), 2));
    ((TObjChara *)((Player_80018990 *)this))->add_to_field_2ce((f32)((TObjChara *)((Player_80018990 *)this))->get_atp() * ((f32 (*)(void *, s32))TObjPlayer__sub_800192C4)(((Player_80018990 *)this), 3));
    return 1;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TObjChara::calc_attach_pos() {
    u8 *arg0 = (u8 *)this;
    if ((void *) this->m_2b0 != NULL) {
        this->m_2fc = (f32) this->position.x;
        this->m_300 = (f32) (((0.5f) * *(f32 *)(this->m_2b0 + 0x10)) + this->position.y);
        this->m_304 = (f32) this->position.z;
        return;
    }
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x2FC, (u8 *)&this->position);
}
#pragma pop

u8 *TObjChara::vfunc_18(u8 *arg1) {
    Stack_80018E6C stack;
    f32 temp_f1;
    u8 *temp_r3;
    u8 *temp_r6;
    stack.sp8 = *(f32 *)((s8 *)arg1 + 0);
    temp_r6 = this->m_2b0;
    temp_f1 = *(f32 *)((s8 *)arg1 + 4);
    stack.spC = temp_f1 + *(f32 *)((s8 *)temp_r6 + 0x10);
    stack.sp10 = *(f32 *)((s8 *)arg1 + 8);
    temp_r3 = (u8 *)(csnVectorUnder(&stack.sp8, ((u8 *)this) + 0x120, 0x15, temp_r6, temp_f1));
    if (temp_r3 == NULL) {
        return NULL;
    }
    *(f32 *)((s8 *)((u8 *)this) + 0x3C) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 4)) + 4);
    return temp_r3;
}

u8 *TObjChara::update_actor_ground_y() {
    Stack_80018EE4 stack;
    f32 temp_f1;
    u8 *temp_r3;
    u8 *temp_r6;
    stack.sp8 = *(f32 *)((s8 *)((u8 *)this) + 0x38);
    temp_r6 = this->m_2b0;
    temp_f1 = *(f32 *)((s8 *)((u8 *)this) + 0x3C);
    stack.spC = temp_f1 + *(f32 *)((s8 *)temp_r6 + 0x10);
    stack.sp10 = *(f32 *)((s8 *)((u8 *)this) + 0x40);
    temp_r3 = (u8 *)(csnVectorUnder(&stack.sp8, ((u8 *)this) + 0x120, 0x15, temp_r6, temp_f1));
    if (temp_r3 == NULL) {
        return NULL;
    }
    *(f32 *)((s8 *)((u8 *)this) + 0x3C) = (f32) *(f32 *)((s8 *)(*(u8 **)((s8 *)temp_r3 + 4)) + 4);
    return temp_r3;
}

void *TObjChara::get_center() { return (char*)this + 0x2fc; }

void TObjChara::reset_motion_fields() {
    Obj_80018F64 *self = (Obj_80018F64 *)this;
    self->v104.x = self->v104.y = self->v104.z = (0.0f);
    self->v290.x = self->v290.y = self->v290.z = (0.0f);
    self->v29c.x = self->v29c.y = self->v29c.z = (0.0f);
    this->m_248 = this->m_250 = (0.0f);
    self->f24c = (1.0f);
    this->m_2ac = 0;
    this->m_2b4 = (0.0f);
    this->m_2d4 = 0xFFFF;
    this->m_2dc = 0;
    this->phase = self->f32a = 0;
    self->f320 = 0;
    self->v2fc.x = self->v2fc.y = self->v2fc.z = self->v308.x = self->v308.y = self->v308.z = (0.0f);
}

void *__dt__9TObjCharaFv(void *self, s16 deleteFlag) {
    if (self != NULL) {
        *(s32 **)((s8 *)self + 0x18) = (s32 *)__vt__9TObjChara;
        __dt__10TObjMotionFv(self, 0);
        if (deleteFlag > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}

#pragma push
#pragma opt_common_subs off
Obj_80019038 *__ct__9TObjCharaFP7TObject(Obj_80019038 *self, void *parent) {
    u8 *p = (u8 *)self;
    Layout_80019038 *l;
    s32 i;
    s32 j;
    __ct__10TObjMotionFP7TObject(self, parent);
    *(s32 **)((s8 *)self + 0x18) = (s32 *)__vt__9TObjChara;
    ((TObjPlayer *)(p + 0x120))->register_object();
    __ct__14SubtractiveRngFv(p + 0x160);
    __construct_array(p + 0x254, (void *)TObjPlayer::init_192dc_return_self, 0, 0xC, 5);
    *(u8 **)((s8 *)self + 0x90) = p + 0x120;
    ((TObjChara *)self)->mode = 0;
    self->v6();
    *(s32 *)((s8 *)self + 0x2B0) = 0;
    *(s32 *)((s8 *)self + 0x2A8) = 0;
    ((TObjChara *)self)->m_314 = 0;
    ((TObjChara *)self)->m_318 = 0;
    *(s32 *)((s8 *)self + 0x31C) = 0;
    *(s16 *)((s8 *)self + 0x2BE) = 0;
    ((TObjChara *)self)->hp_bonus = 0;
    ((TObjChara *)self)->tp = 0;
    ((TObjChara *)self)->hp = 0;
    ((TObjChara *)self)->tpmax = 0;
    ((TObjChara *)self)->hpmax = 0;
    ((TObjChara *)self)->m_11a = 0;
    ((TObjChara *)self)->m_2c8 = 0;
    ((TObjChara *)self)->m_2c0 = 0;
    *(s16 *)((s8 *)self + 0x2CA) = 0;
    *(s16 *)((s8 *)self + 0x2C2) = 0;
    ((TObjChara *)self)->m_2cc = 0;
    ((TObjChara *)self)->m_2c4 = 0;
    *(s16 *)((s8 *)self + 0x2CE) = 0;
    *(s16 *)((s8 *)self + 0x2C6) = 0;
    *(s16 *)((s8 *)self + 0x2D2) = 0;
    ((TObjChara *)self)->m_2d0 = 0;
    *(s32 *)((s8 *)self + 0x2E0) = 0;
    *(s16 *)((s8 *)self + 0x2F0) = 0;
    ((TObjChara *)self)->m_2ee = 0;
    *(s16 *)((s8 *)self + 0x2EC) = 0;
    ((TObjChara *)self)->m_2ea = 0;
    *(s16 *)((s8 *)self + 0x2E8) = 0;
    *(s16 *)((s8 *)self + 0x2FA) = 0;
    ((TObjChara *)self)->m_2f8 = 0;
    *(s16 *)((s8 *)self + 0x2F6) = 0;
    ((TObjChara *)self)->m_2f4 = 0;
    ((TObjChara *)self)->m_2f2 = 0;
    subtractive_rng_seed(p + 0x160, ((TObjChara *)self)->entity_id);
    ((TObjChara *)self)->m_2e4 = 0;
    ((TObjChara *)self)->add_flags_2e4(0);
    ((TObjChara *)self)->control_state = 0;
    ((TObjChara *)self)->m_2d8 = 0xFFFF;
    l = (Layout_80019038 *)self;
    for (i = 0; i < 3; i++) {
        l->pairs[i][0] = 0;
        l->pairs[i][1] = 0;
    }
    for (j = 0; j < 5; j++) {
        reset_status_effect_row((u8 *)&l->elems[j]);
    }
    l->f116 = 0;
    l->f118 = 0;
    *(u16 *)((s8 *)self + 0x2D6) = 0xFFFF;
    TObjPlayer::clear_s16_arrays(self);
    *(s32 *)((s8 *)self + 0x330) = 0;
    obj_setField96_1((ObjFlags*)((ObjFlags *)self));
    TObjPlayer__sub_8001951C(self);
    return self;
}
#pragma pop

void TObjChara::get_pos(s32 arg1) {
    s32 arg0 = (s32)this;
    ((s32 (*)(s32, s32, s32))VecCopy__FP3VecPC3Vec)(arg1, arg0 + 0x2FC, arg0);
}
#pragma push
#pragma scheduling off
Vec *VecCopy(Vec* dst, const Vec* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    return dst;
}
#pragma pop

#pragma push
#pragma scheduling off

u8 is_locally_controlled__10TObjPlayerFPv(u8 *arg0) {
    return (u8) (((TObjChara *)arg0)->control_state == 1);
}
#pragma pop

s16 TObjPlayer::get_class_id() { return *(s16*)((char*)this + 0x2f6); }

s16 TObjPlayer::get_item_index() { return this->m_2f4; }

void TObjChara::add_to_field_2ce(int a1) { *(short*)((char*)this + 0x2ce) = (*(short*)((char*)this + 0x2ce) + a1); }

s16 TObjChara::get_atp() { return *(s16 *)&this->unk_2C6; }

void TObjChara::add_to_field_2ca(int a1) { *(short*)((char*)this + 0x2ca) = (*(short*)((char*)this + 0x2ca) + a1); }

s16 TObjChara::get_field_2c2() { return *(s16*)((char*)this + 0x2c2); }

void TObjChara::add_to_field_2c8(int a1) { this->m_2c8 = (this->m_2c8 + a1); }

s16 TObjChara::get_field_2c0() { return this->m_2c0; }

void TObjChara::sub_800192B4(int a1) { this->m_2cc = (this->m_2cc + a1); }

f32 TObjPlayer__sub_800192C4(Obj800192C4 *self, s32 i) {
    return self->recs[i].b;
}

s16 TObjChara::get_s16_2c4() { return (this->m_2c4); }

void reset_status_effect_row(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0) = 0;
    *(f32 *)((s8 *)arg0 + 4) = (f32) (0.0f);
    *(s32 *)((s8 *)arg0 + 8) = 0;
}

#pragma push
#pragma scheduling off

int obj_getArrWord_254(ObjArr254* p, int i) {
    return p->arr[i].w;
}
#pragma pop

#pragma push
#pragma scheduling off
void obj_setArrS16_FC(ObjArrFC* p, int i, s16 v) {
    p->arr[i] = v;
}
#pragma pop

#pragma push
#pragma scheduling off
u16 obj_getArrU16_FC(ObjArrFC* p, int i) {
    return p->arr[i];
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
void obj_clearArrS16_FC(ObjArrFC* p, int i) {
    p->arr[i] = 0xFFFF;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off

s32 TObjChara::obj_isState2_324() {
    return this->control_state == 2;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
s16 get_actor_tp(u8* p) {
    return *(s16*)(p + 0x32e);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
int obj_getPtr2B0_20(u8* p) {
    return *(int*)(*(u8**)(p + 0x2b0) + 0x20);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
int TObjChara::obj_getPtr2B0_1C() {
    return *(int*)(this->m_2b0 + 0x1c);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
s16 obj_getS16_2BA(u8* p) {
    return *(s16*)(p + 0x2ba);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
s16 get_actor_hp(u8* p) {
    return *(s16*)(p + 0x32c);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
u8 TObjChara::obj_testFlag_2E4(u32 mask) {
    return (this->m_2e4 & mask) != 0;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
s16 obj_getS16_118(u8* p) {
    return *(s16*)(p + 0x118);
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off

s16 TObjPlayer::obj_getS16_116() {
    return this->m_116;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
u8 TObjChara::obj_isState3_324() {
    return this->control_state == 3;
}
#pragma pop

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
void obj_copyVec2_0(u8* d, u8* s) {
    *(int*)(d + 0) = *(int*)(s + 0);
    *(f32*)(d + 4) = *(f32*)(s + 4);
}
#pragma pop
extern "C" {

s16 TObjChara::get_actor_attack_params_atp_min() { return get_attack_params_atp_min((void*)this->m_318); }

s16 get_attack_params_atp_min(void* p) { return *(s16*)((char*)p + 0x0); }

void TObjPlayer__sub_800193FC(O_800193FC *self, s32 i, s32 v) {
    self->recs[i].c = v;
}

void TObjPlayer__sub_8001940C(O_8001940C *self, s32 i, s32 v) {
    self->recs[i].a = v;
}

void TObjPlayer__sub_8001941C(O_8001941C *self, s32 i, f32 v) {
    self->recs[i].b = v;
}

s16 TObjChara::test_immunity_flags(s32 arg1) {
    return (s16) (this->m_11c & arg1);
}

#pragma push
#pragma scheduling off
int TObjPlayer__sub_8001943C(ObjArr254_p53* p, int i) {
    return p->arr[i].w;
}
#pragma pop

s16 TObjPlayer::get_ata() { return this->m_2d0; }

s32 TObjChara::get_attack_angle() { return ((AttackParams *)(this->m_318))->get_attack_angle(); }

s32 AttackParams::get_attack_angle() { return attack_angle; }

f32 TObjChara::get_attack_range() { return ((AttackParams *)(this->m_318))->get_attack_range(); }

f32 AttackParams::get_attack_range() { return attack_range; }

s32 TObjPlayer::add_status_effect_timer(s32 i, s32 v) {
    O_800194AC *self = (O_800194AC *)this;
    return self->recs[i].c += v;
}

s16 TObjChara::sub_800194C4() { return TObjPlayer__sub_800194E8((void*)this->m_318); }

s16 TObjPlayer__sub_800194E8(void* p) { return *(s16*)((char*)p + 0x4); }

s16 TObjChara::get_stats_atp_max() { return get_attack_params_atp_max((void*)this->m_318); }

s16 get_attack_params_atp_max(void* p) { return *(s16*)((char*)p + 0x2); }

void TObjPlayer__sub_8001951C(void* p) { *(s16*)((char*)p + 0x11c) = 0; }

void TObjChara::add_flags_2e4(u32 v) { (this->m_2e4) |= v; }

void*TObjPlayer::init_192dc_return_self(void* p) { ((int (*)(void*))reset_status_effect_row)(p); return p; }

void TObjCollidable::interact(s32 client) { this->interactor = client; }

u8 obj_is_hit_receivable(u8 *arg0) {
    return (u8) (*(u16 *)((s8 *)arg0 + 0x96) == 1);
}

int get_player_data__10TObjPlayerFi(int a0) {  return TObjPlayer__data_8050D460[a0]; }

void obj_setField96_1(ObjFlags* p) {
    p->field_96 = 1;
}

s32 TObjCollidable::obj_testFlags30(u32 mask) {
    ObjFlags*p = (ObjFlags*)this;
    return p->flags_30 & mask;
}

u16 get_entity_id(ObjFlags* p) {
    return p->field_1c;
}

void TObjBase::obj_clearFlags30(u32 mask) {
    ((ObjFlags*)this)->flags_30 &= ~mask;
}

void obj_setFlags30(ObjFlags* p, u32 mask) {
    p->flags_30 |= mask;
}

void TObjPlayer::bswap_head16() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); }

void G_ClientIDHeader::bswap() { bswap_16(&client_id); }

void TObjPlayer::send_head() { bswap_head16(); send_subcommand(this); }

void TObjPlayer::init_packet_9a() {
    O_80019664 *self = (O_80019664 *)this;
    self->f4 = 0xFFFF;
    self->f6 = 0;
    self->f7 = 0;
    self->f0 = 0x9a;
    self->f1 = 2;
}

bool is_split_screen(void) {
    return camera_split_screen_selector != 1;
}

f32 calc_random_ratio__10TObjPlayerFv(void) {
    return (f32) (subtractive_rng_next() >> 0x10U) / *(const volatile f32 *)&lbl_805D7D3C;
}

s32 get_current_floor(void) {
    return current_floor_index;
}

s32 TObjPlayer::get_field_3e4() { return this->m_3e4; }

s32 TObjPlayer::get_player_count() {
    return lobby_player_count;
}

int get_item_field_6__10TObjPlayerFPv(void* p) { return get_slot_value__10TObjPlayerFPvi((char*)p + 0xd04, 6); }

u8 TItem::get_item_group() { return this->item_group; }

s32 get_type__10TObjPlayerFPv(void* p) { return *(s32*)((char*)p + 0x0); }

f32 fabs_float(f32 x) {
    return (f32) fabs_double((f64) x);
}

f32 atan2_float(f32 y, f32 x) {
    return (f32) atan2((f64) y, (f64) x);
}
}

f64 fabs_double(f64 x) { return __fabs(x); }

#pragma push
#pragma fp_contract on

f32 newton_sqrtf(f32 x) {
    volatile f32 y;
    if (x > (0.0f)) {
        f64 guess = __frsqrte(x);
        guess = lbl_80434098 * guess * (lbl_804340A0 - (f64) x * (guess * guess));
        guess = lbl_80434098 * guess * (lbl_804340A0 - (f64) x * (guess * guess));
        guess = lbl_80434098 * guess * (lbl_804340A0 - (f64) x * (guess * guess));
        y = (f32) ((f64) x * guess);
        return y;
    }
    return x;
}
#pragma pop

s32 TObjPlayer::register_object() {
    s32 arg0 = (s32)this;
    clear_ground_candidates();
    return arg0;
}

void TObjPlayer::clear_ground_candidates() {
    O_80019828 *self = (O_80019828 *)this;
    s32 i;
    for (i = 0; i < 16; i++) {
        self->arr[i] = 0;
    }
}
