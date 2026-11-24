#include "pso/math/MatrixTransforms.h"
#include "pso/player/PlayerSlots.h"
#include "pso/system/SoundEffect.h"
#include "pso/enemy/EnemyMovement.h"
#include "pso/object/TActorLight.h"
#include "pso/player/TPlyDispData.h"
#include "pso/enemy/EnemyTargeting.h"
#include "pso/effect/particle/ParticleFactory.h"

#include "pso/map/CsnQuery.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/system/MainPhaseState.h"
#include "pso/system/MainPhaseTable.h"
#include "pso/unk/text_8007C0CC.h"
#include "pso/render/BlobShadow.h"

#include "pso/unk/text_803D8F74.h"

#include "pso/player/PlayerAttackParams.h"

#include "pso/system/vector.h"

#include "pso/system/byteswap.h"
#include "pso/math/InverseTrig.h"
#include <stdlib.h>

#include "pso/network/protocol/protocol_types.h"

#include "pso/unk/TLobby_801E43E4.h"

#include "types.h"
#include "pso/object/base/HitEligibility.h"
#include "pso/map/CsnGroundCandidates.h"

#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/system/task/TObject.h"

#include "pso/player/TObjPlayer.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/enemy/TObjEnemy.h"

#include "pso/object/base/TObjChara.h"

#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"


#include "pso/item/TItem.h"


#include "pso/enemy/lappy/TObjEneLappy.h"

#include "pso/player/DamageBookkeeping.h"

#include "dolphin/mtx.h"

#include <stddef.h>

#include "pso/effect/TEffClitical.h"

#include "pso/boss/derolle/TObjBoss2Tunnel.h"

#include "pso/unk/TLobby.h"
#include "pso/system/SubtractiveRng.h"

#include "pso/enemy/dubchik/TOCtrlDubchik.h"

#include "pso/map/FloorArea.h"

#include "pso/ui/TLogo.h"

#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"

#include "pso/ui/frontend/TAdMultiChgGameModeGC_8023F4E4.h"

#include "pso/unk/text_8023F3F8.h"

#include "pso/ui/keyboard/TKeyBoardControl.h"

#include "pso/ui/keyboard/TKeyBoardControl_802A1180.h"

#include "pso/unk/text_802A1154.h"

#include "pso/unk/text_80290BEC.h"

#include "pso/ui/frontend/TAdEndText.h"

#include "pso/ui/frontend/TAdEndText_80307A34.h"

#include "pso/system/scene/TEnding.h"

#include "pso/unk/text_8008C4F4.h"

#include "pso/system/scene/OfflineGameScene.h"

#include "pso/unk/TLobby_801A3C48.h"

#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"


#include "pso/ui/frontend/TAdTrialModemChkGC.h"

#include "pso/item/TItemReverseTech.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjBase.h"


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

struct ObjFlags;
class TObjPlayer;
struct Info_8001311C { s32 type; f32 power; };
struct Coll_8001311C { u8 pad0[0x18]; u32 flags; Vec pos; };
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
    Vec pos;
    u8 pad308[0x828 - 0x308];
    u8 f828[4];
};

struct Rec_80011824 { s32 kind; f32 power; };
struct Stats_80011824 { u8 pad0[0xE]; s16 f0E; };
struct Coll_80011824 { u8 pad0[0x18]; u32 flags; Vec pos; };
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
    Vec pos;
};


struct Layout_80019038 {
    u8 pad0[0x110];
    u8 pairs[3][2];
    s16 f116;
    s16 f118;
    u8 pad11a[0x254 - 0x11A];
};
extern "C" {
s32 VecCopy__FP3VecPC3Vec(s32, s32);
void activate_switch_attacks__10TObjPlayerFii(saddr arg0, saddr pos);
void attach_mine_trap__10TObjPlayerFiUi(saddr object, u32 arg1);
s32 TObjectV8047c128_subtract_hp(u8 *arg0, s16 arg1);
s32 get_type__10TObjPlayerFPv(void* p);
void create_hit_effect__10TObjPlayerFPv(void *);
int get_player_data__10TObjPlayerFi(int a0);
extern s32 registered_player_count;
extern s32 registered_enemy_count;
s32 damage_hp__10TObjPlayerFii(saddr arg0, saddr arg1);
void show_meseta_label(saddr player, u32 arg1, s32 arg2, s32 arg3);
s16 get_actor_tp(u8* p);
int obj_getPtr2B0_20(u8* p);
s16 obj_getS16_2BA(u8* p);
void send_6x2F_change_player_hp(u16, u16, s16);
void dispatch_weapon_special_effect(void *, void *, void *, s32);
void __construct_array(void *, void *, void *, u32, u32);
}

s32 calc_freeze_chance(TObjPlayer *arg0, TObjPlayer *arg1, TObjPlayer *arg2, f32 farg0);
s32 calc_shock_chance(TObjPlayer *arg0, TObjPlayer *arg1, TObjPlayer *arg2);
void empty_post_damage_hook(void *defender, void *attacker);
void record_local_damage_if_enabled(void *mine_trap, void *att, saddr damage);
void draw_hp_label(void *player, u32 pos, s32 delay, s16 arg3);
void obj_copyVec2_0(u8* d, u8* s);
f32 calc_technique_boost(s32, u16);
extern s32 game_difficulty_selection;
void display_exp_gain(saddr player, u32 pos, s32 delay, s32 arg3);
void show_tp_font(saddr player, u32 pos, s32 delay, s32 arg3);
s16 obj_getS16_118(u8* p);
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

struct O_80011704 { u8 pad[0x1c]; u16 f1c; };

typedef struct Player_800115C4 {
    u8 pad0[0x1C];
    u16 id;
    u8 pad1E[0x30 - 0x1E];
    s32 flags;
    u8 pad34[0x2FC - 0x34];
    Vec pos;
} Player_800115C4;

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

struct RecoveredGlobal_8001806C_lbl_8058D490 { s32 value; u8 remaining[0x2C]; };
LAYOUT_ASSERT(RecoveredGlobal_8001806C_lbl_8058D490_size, sizeof(RecoveredGlobal_8001806C_lbl_8058D490) == 0x30);
struct Obj_80018660 { u8 pad[0x38]; Vec pos; u8 pad44[0x1c]; s32 angle; u8 pad64[0x238]; Vec dest; };
struct Obj_800180E8 { u8 pad[0x308]; f32 vx; f32 vy; f32 vz; };

typedef struct Obj_80017804 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x290 - 0x44];
    Vec home;
    Vec dest;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec cur;
    f32 vx;
    f32 vy;
    f32 vz;
} Obj_80017804;

typedef struct Obj_80017ABC {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x290 - 0x44];
    Vec home;
    Vec dest;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec cur;
} Obj_80017ABC;

struct Sub_800182A0 { u8 pad[0xC]; f32 fC; };

struct Obj_800182A0 {
    u8 pad0[0x3C];
    f32 f3C;
    u8 pad40[0xA4 - 0x40];
    Sub_800182A0 *fA4;
    u8 padA8[0x29C - 0xA8];
    Vec f29C;
    u8 pad2A8[0x2FC - 0x2A8];
    Vec pos;
};

struct Obj_800182A0;

struct Body_80016454 {
    Vec local;
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
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 yaw;
    u8 pad64[0xa4 - 0x64];
    Body_80016454 *bodies;
    s32 bodyCount;
};

struct RecoveredGlobal_8001806C_lbl_8058D490;

struct Part_8001745C {
    Vec pos;
    f32 radius;
    u8 pad10[0x8];
    u32 flags;
    u8 pad1C[0x10];
};

struct Target_8001745C {
    u8 pad0[0x30];
    u32 flags30;
    u8 pad34[0x4];
    Vec pos;
    u8 pad44[0x1C];
    s32 rotY;
    u8 pad64[0x40];
    Part_8001745C *parts;
    s32 nparts;
};

struct Player_8001745C {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x1C];
    s32 rotY;
    u8 pad64[0x2A8 - 0x64];
    Target_8001745C *target;
    u8 pad2AC[0x318 - 0x2AC];
    u32 f318;
};

typedef s32 (*VecCopyFn_80016454)(void *, void *);
struct Obj_80018660;

struct Obj_80018F64 {
    u8 pad0[0x104]; Vec v104;
    u8 pad110[0x248 - 0x110]; f32 f248; f32 f24c; f32 f250;
    u8 pad254[0x290 - 0x254]; Vec v290; Vec v29c;
    u8 pad2a8[4]; s32 f2ac; u8 pad2b0[4]; f32 f2b4;
    u8 pad2b8[0x2d4 - 0x2b8]; u16 f2d4; u8 pad2d6[6]; s32 f2dc;
    u8 pad2e0[0x2fc - 0x2e0]; Vec v2fc; Vec v308;
    u8 pad314[0x320 - 0x314]; s32 f320; u8 pad324[4]; s16 f328; s16 f32a;
};

struct ObjArrFC  { u8 _pad[0xfc];  u16 arr[1];     };

struct ObjFlags {
    u8  _pad00[0x1c];
    u16 field_1c;
    u8  _pad1e[0x30 - 0x1e];
    u32 flags_30;
};

struct O_80019664 { u8 f0; u8 f1; u8 pad[2]; u16 f4; u8 f6; u8 f7; };
struct Obj_80014B5C { u8 pad0[0x30]; u32 f30; u8 pad34[0x254 - 0x34]; u8 f254[0x330 - 0x254]; u32 f330; };

void shutdown_and_reset_system(void);
void init_game_systems(void);
extern "C" {
void clear_velocity(u8 *arg0);
void handle_6x9A_update_entity_stat(Pkt_80010C54 *pkt);
s32 select_destination_away_from(TObjChara *chara, Vec point);
s32 check_path_obstructed(TObjChara *chara, Vec *target);
void enemy_turn_half_toward_dest(TObjChara *chara);
s16 get_actor_attack_params_atp_min__9TObjCharaFv(void* p);
s16 get_attack_params_atp_min(void* p);
s16 get_attack_params_atp_max(void* p);
bool is_split_screen(void);
s32 get_current_floor(void);
f32 fabs_float(f32 x);
f32 atan2_float(f32 y, f32 x);
f32 newton_sqrtf(f32 x);
void create__10TObjPlayerFUiii(uaddr, s32, s32);
s32 create_font_small_task(u32, s32, s32, s32, s32 *, s16, u16);
s32 create_font_small_task_default_color(u32, s32, s32, s32, s32 *, s16);
s32 create_damage_font__19TObjEneEpsilonGuardFllll(u32, s32, s32, s16);
f32 horizontal_distance_squared(void *, void *);
s32 angle_difference_abs(s32, s32);
s32 lerp_angle_half__Fll(s32, s32);
s32 approach_angle_limited(s32, s32, s32);
void * find_entity_by_id(s32 id);
s32 record_damage_stats__10TOMineTrapFUiUis(void *, void *, void *);
int bswap_16__FPUs(void*);
u32 __nw__7TObjectFUl(s32);
s32 vec3_add_to(void *, void *);
void matrix_mult_vec(s32, void *, void *);
s32 scale_matrix(int, f32, f32, f32);
void set_matrix_identity(s32);
f32 vec_squared_length(void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_z(int, int);
s32 rotate_matrix_x(int, int);
void post_translate_matrix(void *);
extern const f64 TObjPlayer__data_804340B8;
extern int TObjPlayer__data_8050D460[];
extern const f64 lbl_80434098;
extern const f64 lbl_804340A0;
extern u8 lbl_804340A8[];
extern const char lbl_804340B0[];
extern Vec scratch_vec;
struct LobbyRuleSettings { s32 value; u8 remaining[0x2C]; };
extern LobbyRuleSettings lobby_rule_settings;
extern RecoveredGlobal_8001806C_lbl_8058D490 identity_matrix;
extern s32 actor_frame_tick;
extern s32 lobby_player_count;
extern s32 current_floor_index;
extern TObject *tl_07;
void obj_setField96_1(TObjCollidable *p);
const f32 player_attack_stat_status_light_colors[4] = {1.0f, 0.9f, 0.5f, 0.2f};
const f32 player_defense_stat_status_light_colors[4] = {1.0f, 0.4f, 0.8f, 1.0f};
const f32 TObjPlayer__data_80434060[3] = {0.0f, 1.0f, 0.0f};

// inferred: update_poison_status adds entry [game_difficulty_selection] to each poison tick's damage
const s16 poison_damage_bonus_by_difficulty[4] = {0, 2, 5, 10};

// inferred: the zero vector find_nearest_visible_player starts its player-distance vector from
const Vec nearest_player_zero_vec = {0.0f, 0.0f, 0.0f};

static const f32 lbl_805D7D3C = 65536.0f;
}
void apply_actor_gravity(TObjEnemy *arg0, s32 *arg1, f32 farg0);
void enemy_set_heading_velocity(f32 speed, TObjEnemy *enemy, s32 heading);
s32 is_entity_locally_controlled(s32 id);
f64 fabs_double(f64 x);
void direction_to_rotation_xz(u8 *dir, s32 *rot_a, s32 *rot_b);
#pragma push
#pragma fp_contract on
#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define TEST30(o, m) ((TObjCollidable *)o)->test_actor_flags(m)
#define FIELD1C(o) ((TObjBase *)(o))->get_entity_id()
#define STATE2(o) (((TObjChara *)(o))->obj_isState2_324())
#define STATE3(o) ((TObjChara *)o)->obj_isState3_324()
#define LOCAL(o) TObjPlayer::is_locally_controlled(o)
#define VECCOPY(d, s) ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(d, s)
#define HIT(o, p) (((TObjChara *)(o))->try_apply_damage(p, 0))
#define DAMAGE(o, p, d) (((TObjChara *)(o))->try_apply_damage(p, d))
#define SWITCH_ATTACK(o, p) ((TObjChara *)(o))->trigger_switch_attack(p)
#define SUB_HP(o, d) ((s32 (*)(Actor_8001311C *, s32))TObjectV8047c128_subtract_hp)(o, d)
struct TObjPlayer;
struct Obj_80010DE8;

#define VECCOPY_W24(d, s) ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((d), (s))
#define FIELD1C_W24(p) ((TObjBase *)(p))->get_entity_id()
#define TESTF30_W24(p, m) ((TObjCollidable *)((p)))->test_actor_flags((m))
#define ISSTATE2_W24(p) (((TObjChara *)(p))->obj_isState2_324())
#define ISLOCAL_W24(p) TObjPlayer::is_locally_controlled(p)
#define MISS_W24(s, v) (((TObjChara *)(s))->show_miss_popup((const float *)(v)))
#define APPLYDMG_W24(s, v, d) (((TObjChara *)(s))->try_apply_damage((const Vec *)(v), (d)))
#define DISPATCH_W24(a, s, v) dispatch_weapon_special_effect((a), (s), (v), 1)
#define SUBHP_W24(p, v) ((s32 (*)(void *, s32))TObjectV8047c128_subtract_hp)((p), (v))
#define ADDHP_W24(p, v) ((s32 (*)(void *, s32))add_actor_hp)((p), (v))
#define SUBTP_W24(p, v) ((TObjChara *)p)->subtract_actor_tp((s32)((v)))
#define ADDTP_W24(p, v) ((s32 (*)(void *, s32))add_actor_tp)((p), (v))
#define HPLABEL_W24(p, v, k, n) ((void (*)(void *, void *, s32, s32))draw_hp_label)((p), (v), (k), (n))
#define TPFONT_W24(p, v, k, n) ((void (*)(void *, void *, s32, s32))show_tp_font)((p), (v), (k), (n))
#define BOSS4_W24(p) (((TObjChara *)(p))->random_ratio())
#define CLEARCOLL_W24() if (coll != NULL) { coll->flags &= ~0x04000000; }
struct Obj_80014108;
#pragma pop
#undef TEST30
#undef FIELD1C
#undef STATE2
#undef STATE3
#undef LOCAL
#undef VECCOPY
#undef HIT
#undef DAMAGE
#undef SWITCH_ATTACK
#undef SUB_HP
#undef VECCOPY_W24
#undef FIELD1C_W24
#undef TESTF30_W24
#undef ISSTATE2_W24
#undef ISLOCAL_W24
#undef MISS_W24
#undef APPLYDMG_W24
#undef DISPATCH_W24
#undef SUBHP_W24
#undef ADDHP_W24
#undef SUBTP_W24
#undef ADDTP_W24
#undef HPLABEL_W24
#undef TPFONT_W24
#undef BOSS4_W24
#undef CLEARCOLL_W24
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

struct Coll_80014108 { u8 pad0[0x18]; u32 flags; Vec pos; f32 def; };
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

#pragma pop

#pragma push
#pragma fp_contract on
extern const double lbl_80434090;

#pragma pop


struct ObjFlags;

void CsnGroundCandidates::clear() {
    s32 i;
    for (i = 0; i < 16; i++) {
        this->groups[i] = NULL;
    }
}

CsnGroundCandidates::CsnGroundCandidates() {
    clear();
}

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
f64 fabs_double(f64 x) { return __fabs(x); }

f32 atan2_float(f32 y, f32 x) {
    return (f32) atan2((f64) y, (f64) x);
}

f32 fabs_float(f32 x) {
    return (f32) fabs_double((f64) x);
}

s32 get_type__10TObjPlayerFPv(void* p) { return *(s32*)((char*)p + 0x0); }

u8 TItem::get_item_group() { return this->item_group; }

TItem *TObjPlayer::get_equipped_weapon(void *player) { return (TItem *)get_slot_value(((TObjPlayer *)player)->equipped_items, 6); }

s32 TObjPlayer::get_player_count() {
    return lobby_player_count;
}

s32 TObjPlayer::get_floor() { return this->current_floor; }

s32 get_current_floor(void) {
    return current_floor_index;
}

f32 calc_random_ratio__10TObjPlayerFv(SubtractiveRng *rng) {
    const u32 sample = static_cast<u32>(subtractive_rng_next(reinterpret_cast<s32 *>(rng)));
    return (f32) (sample >> 16) / *(const volatile f32 *)&lbl_805D7D3C;
}

bool is_split_screen(void) {
    return camera_split_screen_selector != 1;
}

void TObjPlayer::init_packet_9a() {
    O_80019664 *self = (O_80019664 *)this;
    self->f4 = 0xFFFF;
    self->f6 = 0;
    self->f7 = 0;
    self->f0 = 0x9a;
    self->f1 = 2;
}

void TObjPlayer::send_head() { bswap_head16(); send_subcommand(this); }

void G_ClientIDHeader::bswap() { bswap_16(&client_id); }

void TObjPlayer::bswap_head16() { ((G_ClientIDHeader *)this)->bswap(); bswap_16__FPUs((char*)this + 0x4); }

void TObjBase::set_actor_flags(s32 flags) {
    actorFlags |= flags;
}

void TObjBase::clear_actor_flags(u32 mask) {
    ((ObjFlags*)this)->flags_30 &= ~mask;
}

u16 TObjBase::get_entity_id() {
    return entity_id;
}

s32 TObjCollidable::test_actor_flags(u32 mask) {
    ObjFlags*p = (ObjFlags*)this;
    return p->flags_30 & mask;
}

void obj_setField96_1(TObjCollidable *p) {
    p->hit_receive_state = 1;
}

int get_player_data__10TObjPlayerFi(int a0) {  return TObjPlayer__data_8050D460[a0]; }

extern "C" s32 obj_is_hit_receivable(const TObjCollidable *target) {
    return target->hit_receive_state == 1;
}

void TObjCollidable::interact(u16 client) { this->interactor = client; }

StatusEffect::StatusEffect() { clear(); }

void TObjChara::add_flags_2e4(u32 v) { (this->target_attribute_mask) |= v; }

void TObjChara::clear_immunity_flags() { this->immunity_flags = 0; }

s16 get_attack_params_atp_max(void* p) { return *(s16*)((char*)p + 0x2); }

s16 TObjChara::get_stats_atp_max() { return get_attack_params_atp_max(this->attack_params); }

s16 AttackParams::get_ata() { return this->ata; }

s16 TObjChara::get_attack_params_ata() { return this->attack_params->get_ata(); }

s32 TObjChara::add_status_effect_timer(s32 i, s32 v) {
    return this->status_effects[i].timer += v;
}

f32 AttackParams::get_attack_range() { return attack_range; }

f32 TObjChara::get_attack_range() { return this->attack_params->get_attack_range(); }

s32 AttackParams::get_attack_angle() { return attack_angle; }

s32 TObjChara::get_attack_angle() { return this->attack_params->get_attack_angle(); }

s16 TObjPlayer::get_ata() { return this->ata; }
#pragma push
#pragma scheduling off
s32 TObjChara::get_status_effect_timer(s32 i) {
    return this->status_effects[i].timer;
}
#pragma pop
s16 TObjChara::test_immunity_flags(s32 arg1) {
    return (s16) (this->immunity_flags & arg1);
}

void TObjChara::set_status_effect_amount(s32 i, f32 amount) {
    this->status_effects[i].amount = amount;
}

void TObjChara::set_status_effect_type(s32 i, s32 type) {
    this->status_effects[i].type = type;
}

void TObjChara::set_status_effect_timer(s32 i, s32 timer) {
    this->status_effects[i].timer = timer;
}

s16 get_attack_params_atp_min(void* p) { return *(s16*)((char*)p + 0x0); }

s16 TObjChara::get_actor_attack_params_atp_min() { return get_attack_params_atp_min(this->attack_params); }

#pragma push
#pragma scheduling off
#pragma scheduling on
#pragma scheduling off
void obj_copyVec2_0(u8* d, u8* s) {
    *(int*)(d + 0) = *(int*)(s + 0);
    *(f32*)(d + 4) = *(f32*)(s + 4);
}

s32 TObjChara::obj_isState3_324() {
    return this->control_state == 3;
}

s16 TObjPlayer::obj_getS16_116() {
    return this->m_116;
}

s16 obj_getS16_118(u8* p) {
    return *(s16*)(p + 0x118);
}

s32 TObjChara::obj_testFlag_2E4(u32 mask) {
    return (u8)((this->target_attribute_mask & mask) != 0);
}

s16 TObjChara::get_actor_hp() {
    return this->hp;
}

s16 obj_getS16_2BA(u8* p) {
    return *(s16*)(p + 0x2ba);
}

int TObjChara::obj_getPtr2B0_1C() {
    return this->stat_block->exp;
}

int obj_getPtr2B0_20(u8* p) {
    return *(int*)(*(u8**)(p + 0x2b0) + 0x20);
}

s16 get_actor_tp(u8* p) {
    return *(s16*)(p + 0x32e);
}

s32 TObjChara::obj_isState2_324() {
    return this->control_state == 2;
}

#pragma pop
#pragma push
#pragma scheduling off
#pragma scheduling on
void obj_clearArrS16_FC(TObjChara *actor, s32 index) {
    actor->attack_credit_slots[index] = 0xFFFF;
}

#pragma pop
#pragma push
#pragma scheduling off
u16 obj_getArrU16_FC(TObjChara *actor, s32 index) {
    return actor->attack_credit_slots[index];
}

void obj_setArrS16_FC(TObjChara *actor, s32 index, u16 value) {
    actor->attack_credit_slots[index] = static_cast<u16>(value);
}

s32 TObjChara::get_status_effect_type(s32 i) {
    return this->status_effects[i].type;
}

#pragma pop
void StatusEffect::clear() {
    this->type = 0;
    this->amount = 0.0f;
    this->timer = 0;
}

s16 TObjChara::get_base_evp() { return (this->base_evp); }

f32 TObjChara::get_status_effect_amount(s32 i) {
    return this->status_effects[i].amount;
}

void TObjChara::adjust_evp(int amount) { this->evp = (this->evp + amount); }

s16 TObjChara::get_base_atp() { return this->base_atp; }

void TObjChara::adjust_atp(int amount) { this->atp = (this->atp + amount); }

s16 TObjChara::get_base_atp_range() { return this->base_atp_range; }

void TObjChara::adjust_atp_range(int amount) { this->atp_range = (this->atp_range + amount); }

s16 TObjChara::get_base_dfp() { return this->base_dfp; }

void TObjChara::adjust_dfp(int amount) { this->dfp = (this->dfp + amount); }

s16 TObjPlayer::get_item_index() { return this->m_2f4; }

s16 TObjPlayer::get_class_id() { return *(s16*)((char*)this + 0x2f6); }

#pragma push
#pragma scheduling off
s32 TObjPlayer::is_locally_controlled(void *chara) {
    return (u8) (((TObjChara *)chara)->control_state == 1);
}

Vec *VecCopy(Vec* dst, const Vec* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
    return dst;
}

#pragma pop
void TObjChara::get_pos(saddr out) {
    VecCopy((Vec *)out, &this->body_center);
}

#pragma push
#pragma opt_common_subs off
TObjChara::TObjChara(TObject *parent) : TObjMotion(parent) {
    Layout_80019038 *l;
    s32 i;
    s32 j;
    this->ground_cache = &this->ground_candidates;
    this->mode = 0;
    reset_motion_fields();
    *(s32 *)((s8 *)this + 0x2B0) = 0;
    *(s32 *)((s8 *)this + 0x2A8) = 0;
    this->controller_input = NULL;
    this->attack_params = NULL;
    *(s32 *)((s8 *)this + 0x31C) = 0;
    this->tp_bonus = 0;
    this->hp_bonus = 0;
    this->tp = 0;
    this->hp = 0;
    this->tpmax = 0;
    this->hpmax = 0;
    this->m_11a = 0;
    this->atp = 0;
    this->base_atp = 0;
    this->atp_range = 0;
    this->base_atp_range = 0;
    this->evp = 0;
    this->base_evp = 0;
    this->dfp = 0;
    this->base_dfp = 0;
    this->lck = 0;
    this->ata = 0;
    *(s32 *)((s8 *)this + 0x2E0) = 0;
    *(s16 *)((s8 *)this + 0x2F0) = 0;
    this->m_2ee = 0;
    *(s16 *)((s8 *)this + 0x2EC) = 0;
    this->m_2ea = 0;
    *(s16 *)((s8 *)this + 0x2E8) = 0;
    *(s16 *)((s8 *)this + 0x2FA) = 0;
    this->m_2f8 = 0;
    *(s16 *)((s8 *)this + 0x2F6) = 0;
    this->m_2f4 = 0;
    this->m_2f2 = 0;
    subtractive_rng_seed(&this->rng, this->entity_id);
    this->target_attribute_mask = 0;
    this->add_flags_2e4(0);
    this->control_state = 0;
    this->m_2d8 = 0xFFFF;
    l = (Layout_80019038 *)this;
    for (i = 0; i < 3; i++) {
        l->pairs[i][0] = 0;
        l->pairs[i][1] = 0;
    }
    for (j = 0; j < 5; j++) {
        this->status_effects[j].clear();
    }
    l->f116 = 0;
    l->f118 = 0;
    local_attacker_id = 0xFFFF;
    TObjPlayer::clear_s16_arrays(this);
    *(s32 *)((s8 *)this + 0x330) = 0;
    obj_setField96_1(this);
    clear_immunity_flags();
}

#pragma pop
TObjChara::~TObjChara() {}

void TObjChara::reset_motion_fields() {
    Obj_80018F64 *self = (Obj_80018F64 *)this;
    self->v104.x = self->v104.y = self->v104.z = (0.0f);
    self->v290.x = self->v290.y = self->v290.z = (0.0f);
    self->v29c.x = self->v29c.y = self->v29c.z = (0.0f);
    this->ground_normal.x = this->ground_normal.z = (0.0f);
    ground_normal.y = (1.0f);
    this->m_2ac = 0;
    this->frame_timer = (0.0f);
    this->attacker_id = 0xFFFF;
    this->hit_flags = 0;
    this->phase = self->f32a = 0;
    self->f320 = 0;
    self->v2fc.x = self->v2fc.y = self->v2fc.z = self->v308.x = self->v308.y = self->v308.z = (0.0f);
}

void *TObjChara::get_center() { return (char*)this + 0x2fc; }

CsnHit *TObjChara::update_actor_ground_y() {
    Vec stack;
    f32 temp_f1;
    CsnHit *hit;
    player_stats *stats;
    stack.x = position.x;
    stats = this->stat_block;
    temp_f1 = position.y;
    stack.y = temp_f1 + stats->proportions;
    stack.z = position.z;
    hit = csnVectorUnder(&stack, ground_candidates.groups, 0x15);
    if (hit == NULL) {
        return NULL;
    }
    position.y = hit->contact->point.y;
    return hit;
}

CsnHit *TObjChara::update_actor_ground_y_at(Vec *pos) {
    Vec stack;
    f32 y;
    CsnHit *hit;
    player_stats *stat_block;
    stack.x = pos->x;
    stat_block = this->stat_block;
    y = pos->y;
    stack.y = y + stat_block->proportions;
    stack.z = pos->z;
    hit = csnVectorUnder(&stack, ground_candidates.groups, 0x15);
    if (hit == NULL) {
        return NULL;
    }
    position.y = hit->contact->point.y;
    return hit;
}

#pragma push
#pragma fp_contract on
void TObjChara::calc_attach_pos() {
    u8 *arg0 = (u8 *)this;
    if ((void *) this->stat_block != NULL) {
        this->body_center.x = (f32) this->position.x;
        this->body_center.y = (f32) (((0.5f) * this->stat_block->proportions) + this->position.y);
        this->body_center.z = (f32) this->position.z;
        return;
    }
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg0 + 0x2FC, (u8 *)&this->position);
}

s32 TObjChara::recalc_combat_stats(player_stats *base_stats, AttackParams *attack_stats, ActorParamBlock *resistance_stats, f32 xscale, f32 yscale) {
    if (base_stats != NULL) {
        this->stat_block = base_stats;
        this->hpmax = (s16)(xscale * (f32)(this->stat_block->stats.hp + this->stat_block->level) + (f32)this->hp_bonus);
        this->hp = this->hpmax;
        if (this->obj_testFlag_2E4(4) != 0) {
            this->tpmax = 0;
            this->tp = 0;
        } else {
            this->tpmax = (s16)(yscale * (f32)(this->stat_block->stats.mst + this->stat_block->level) + (f32)this->tp_bonus);
            this->tp = this->tpmax;
        }
    } else if (this->stat_block != NULL) {
        this->hpmax = (s16)(xscale * (f32)(this->stat_block->stats.hp + this->stat_block->level) + (f32)this->hp_bonus);
        if (this->obj_testFlag_2E4(4) != 0) {
            this->tpmax = 0;
            this->tp = 0;
        } else {
            this->tpmax = (s16)(yscale * (f32)(this->stat_block->stats.mst + this->stat_block->level) + (f32)this->tp_bonus);
        }
    } else {
        return 0;
    }
    if (attack_stats != NULL) {
        this->attack_params = attack_stats;
    } else if (this->attack_params == NULL) {
        return 0;
    }
    if (resistance_stats != NULL) {
        this->param_block = resistance_stats;
    } else if (this->param_block == NULL) {
        return 0;
    }
    this->base_atp = this->atp = this->stat_block->stats.atp;
    this->base_atp_range = this->atp_range = this->get_stats_atp_max() - this->get_actor_attack_params_atp_min();
    this->base_evp = this->evp = this->stat_block->stats.evp + this->param_block->values[0];
    this->base_dfp = this->dfp = this->stat_block->stats.dfp + this->param_block->value_1c;
    this->ata = (s16)((0.1f) * (f32)(this->stat_block->stats.ata + get_attack_params_ata()));
    this->lck = this->stat_block->stats.lck;
    this->m_2f2 = this->param_block->values[1];
    this->m_2f4 = this->param_block->values[3];
    this->m_2f6 = this->param_block->values[2];
    this->m_2fa = this->param_block->values[4];
    this->m_2f8 = this->param_block->values[5];
    this->adjust_atp((f32)this->get_base_atp() * this->get_status_effect_amount(2));
    this->adjust_atp_range((f32)this->get_base_atp_range() * this->get_status_effect_amount(2));
    this->adjust_dfp((f32)this->get_base_dfp() * this->get_status_effect_amount(3));
    return 1;
}

#pragma pop
s32 TObjChara::set_motion_params(player_stats *base_stats) {
    if (base_stats != NULL) {
        this->stat_block = base_stats;
        this->hpmax = this->stat_block->stats.hp + this->stat_block->level + this->hp_bonus;
        this->tpmax = this->stat_block->stats.mst + this->stat_block->level + this->tp_bonus;
        this->hp = this->hpmax;
        this->tp = this->tpmax;
    } else if (this->stat_block != NULL) {
        this->hpmax = this->stat_block->stats.hp + this->stat_block->level + this->hp_bonus;
        this->tpmax = this->stat_block->stats.mst + this->stat_block->level + this->tp_bonus;
    } else {
        return 0;
    }
    this->base_atp = this->atp = this->stat_block->stats.atp;
    this->base_atp_range = this->atp_range = 0;
    this->base_evp = this->evp = this->stat_block->stats.evp;
    this->base_dfp = this->dfp = this->stat_block->stats.dfp;
    this->ata = (s16)((0.1f) * (f32)this->stat_block->stats.ata);
    this->lck = this->stat_block->stats.lck;
    this->m_2ee = 0;
    this->pad_2F0 = 0;
    this->pad_2EC = 0;
    this->m_2ea = 0;
    this->pad_2E8 = 0;
    this->m_2f8 = 0;
    this->m_2fa = 0;
    this->m_2f6 = 0;
    this->m_2f4 = 0;
    this->m_2f2 = 0;
    return 1;
}

#define VCOPY(d, s) ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((d), (s))
f32 TObjPlayer::calc_distance_to_client(const TObjBase *actor, u16 client, Vec *delta) {
    Vec direction;
    f32 distance = 1.0e8f;
    if (client < 0x1000U) {
        TObjPlayer *player = get_player_by_client_id(client);
        if (player != NULL && !(player->actorFlags & 0x800)) {
            if (player->get_floor() == get_current_floor()) {
                distance = calc_xz_distance_sq(actor, player, &direction);
                if (delta != NULL) {
                    VecCopy(delta, &direction);
                }
            }
        }
    }
    return distance;
}

f32 calc_xz_distance_sq(const TObjBase *actor, const TObjBase *target, Vec *offset) {
    Vec diff;
    f32 distance;
    if (target != NULL) {
        VecCopy(&diff, &target->position);
        subtract_vector(&diff, &actor->position);
        diff.y = 0.01f;
        distance = (diff.x * diff.x) + (diff.z * diff.z);
        if (offset != NULL) {
            VecCopy(offset, &diff);
        }
    } else {
        distance = 1.0e8f;
    }
    return distance;
}

s32 TObjEnemy::enemy_turn_toward_dest(s32 turn) {
    Vec d;
    s32 a;
    VecCopy__FP3VecPC3Vec((saddr)&d, (saddr)&((Obj_80018660 *)this)->dest);
    subtract_vector(&d, &((Obj_80018660 *)this)->pos);
    a = (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(d.x, d.z));
    ((Obj_80018660 *)this)->angle = approach_angle_limited(((Obj_80018660 *)this)->angle, a, turn);
    return angle_difference_abs(((Obj_80018660 *)this)->angle, a);
}

s32 TObjEnemy::turn_toward_direction(s32 max_step, Vec *direction) {
    s32 target_angle;

    target_angle = (s32) (TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(direction->x, direction->z));
    this->rotation_y = approach_angle_limited(this->rotation_y, target_angle, max_step);
    return angle_difference_abs(this->rotation_y, target_angle);
}

void enemy_turn_half_toward_dest(TObjChara *chara) {
    Vec d;
    s32 a;
    VecCopy__FP3VecPC3Vec((saddr)&d, (saddr)&chara->move_destination);
    subtract_vector(&d, &chara->position);
    a = (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(d.x, d.z));
    chara->rotation_y = lerp_angle_half__Fll(chara->rotation_y, a);
    angle_difference_abs(chara->rotation_y, a);
}

s32 copy_position_if_valid(TObjChara *chara, Vec pos) {
    if (project_actor_to_ground(chara, &pos, 0) != 0) {
        VecCopy(&chara->move_origin, &chara->position);
        return 1;
    }
    return 0;
}

s32 check_path_obstructed(TObjChara *chara, Vec *target) {
    Vec d;
    s32 a;
    ((s32 (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&d, target);
    subtract_vector(&d, &chara->body_center);
    if ((9e+04f) < (d.x * d.x) + (d.z * d.z)) {
        a = (s32) (TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(d.x, d.z));
        d.y = d.x = (0.0f);
        d.z = (3e+02f);
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, a);
        rotate_vector_by_matrix(0, &d, &d);
        pop_matrix();
        vec3_add_to(&d, &chara->body_center);
    } else {
        ((s32 (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&d, target);
    }
    if (csnLookAt(&chara->body_center, &d) != 0) {
        return 1;
    }
    return 0;
}

s32 select_enemy_destination(TObjChara *chara, Vec dest, s32 flags) {
    Vec d;
    s32 a;
    if (project_actor_to_ground(chara, &dest, 0) != 0) {
        VecCopy(&d, &dest);
        if (!(flags & 1)) {
            d.y = chara->body_center.y;
        } else {
            d.y += chara->body_center.y - chara->position.y;
        }
        if (chara->bodies != NULL) {
            subtract_vector(&d, &chara->body_center);
            a = (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(d.x, d.z));
            scratch_vec.x = scratch_vec.y = (0.0f);
            scratch_vec.z = chara->bodies->radius;
            push_matrix_from(&identity_matrix);
            rotate_matrix_y(0, a);
            rotate_vector_by_matrix(0, &scratch_vec, &scratch_vec);
            pop_matrix();
            vec3_add_to(&d, &scratch_vec);
            vec3_add_to(&d, &chara->body_center);
        }
        if (!(flags & 2) && check_path_obstructed(chara, &d) != 0) {
            return 0;
        }
        if (!(flags & 4) && csnVector(&chara->body_center, &d, -1) != 0) {
            return 0;
        }
        VecCopy(&chara->move_destination, &dest);
    return 1;
    }
    return 0;
}

s32 select_destination_away_from(TObjChara *chara, Vec point) {
    Vec d;
    VecCopy(&d, &point);
    subtract_vector(&d, &chara->body_center);
    push_matrix_from(&identity_matrix);
    rotate_matrix_y(0, 0x8000);
    rotate_vector_by_matrix(0, &d, &d);
    pop_matrix();
    if ((1e-05f) < vec_squared_length(&d)) {
        normalize_vector(&d);
        vec3_add_to(&d, &chara->body_center);
        return select_enemy_destination(chara, d, 1);
    }
    return 0;
}

void calc_velocity_toward_destination(TObjChara *chara, Vec from, Vec to, f32 speed) {
    Vec d;
    s32 a;
    VecCopy(&d, &to);
    subtract_vector(&d, &from);
    if (d.x * d.x + d.z * d.z < (1e-05f)) {
        chara->velocity.z = (0.0f);
        chara->velocity.x = (0.0f);
    } else {
        a = (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(d.x, d.z));
        d.z = speed;
        d.x = d.y = (0.0f);
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, a);
        rotate_vector_by_matrix(0, &d, &d);
        pop_matrix();
        chara->velocity.x = d.x;
        chara->velocity.z = d.z;
    }
}

void enemy_set_heading_velocity(f32 farg0, TObjEnemy *enemy, s32 heading) {
    Vec stack;
    stack.z = farg0;
    stack.y = (0.0f);
    stack.x = (0.0f);
    push_matrix_from(&identity_matrix.value);
    rotate_matrix_y(0, heading);
    rotate_vector_by_matrix(0, &stack.x, &stack.x);
    pop_matrix();
    *(f32 *)((s8 *)enemy + 0x308) = stack.x;
    enemy->velocity.z = stack.z;
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void move_with_wall_slide(TObjChara *actor) {
    Vec next;
    Vec direction;
    Vec tangent;
    CsnHit *hit;
    CsnContact *contact;
    f32 speed;
    f32 tangent_x;
    f32 velocity_x_squared;
    f32 velocity_z_squared;

    VecCopy(&actor->prev_position, &actor->position);
    VecCopy(&next, &actor->body_center);
    vec3_add_to(&next, &actor->velocity);
    VecCopy(&direction, &actor->velocity);
    normalize_vector_xz(&direction);
    next.x = 5.0f * direction.x + next.x;
    next.z = 5.0f * direction.z + next.z;
    hit = csnVector(&actor->body_center, &next, 0x8FE0);
    if (hit != NULL) {
        contact = hit->contact;
        tangent.x = contact->normal.z;
        tangent.z = -contact->normal.x;
        normalize_vector_xz(&tangent);
        velocity_x_squared = actor->velocity.x * actor->velocity.x;
        velocity_z_squared = actor->velocity.z * actor->velocity.z;
        speed = newton_sqrtf(velocity_x_squared + velocity_z_squared);
        if ((actor->velocity.x * (tangent_x = tangent.x) + actor->velocity.z * tangent.z) >= 0.0f) {
            actor->velocity.x = tangent_x * speed;
            actor->velocity.z = tangent.z * speed;
        } else {
            actor->velocity.x = -tangent_x * speed;
            actor->velocity.z = -tangent.z * speed;
        }
        VecCopy(&next, &actor->body_center);
        vec3_add_to(&next, &actor->velocity);
        VecCopy(&direction, &actor->velocity);
        normalize_vector_xz(&direction);
        next.x = 5.0f * direction.x + next.x;
        next.z = 5.0f * direction.z + next.z;
        if (csnVector(&actor->body_center, &next, 0x8FE0) != NULL) {
            return;
        }
    }
    VecCopy(&next, &actor->body_center);
    vec3_add_to(&next, &actor->velocity);
    next.y += 10.0f;
    if (csnVecterUnder(&next, 0xE0) == NULL && project_actor_to_ground(actor, &next, NULL) != 0) {
        VecCopy(&actor->position, &next);
    }
}

#pragma pop
extern "C" {
f32 update_enemy_wander_move(TObjEnemy *enemy, Vec dest, s32 flags, f32 speed) {
    if (enemy->is_actor_cadence_frame(0x1E) != 0) {
        if (select_enemy_destination(enemy, dest, flags) != 0) {
            copy_position_if_valid(enemy, enemy->body_center);
        }
    }
    calc_velocity_toward_destination(enemy, enemy->move_origin, enemy->move_destination, speed);
    move_with_wall_slide(enemy);
    return horizontal_distance_squared(&dest, &enemy->position);
}

f32 TObjEnemy::enemy_wander_home(f32 farg0, f32 range_x, f32 range_z, s32 turn) {
    Vec v;
    f32 var_f31;
    s32 ang;
    u8 *arg0 = (u8 *)this;
    var_f31 = horizontal_distance_squared((u8 *)&this->body_center, (u8 *)&this->move_destination);
    if ((var_f31 < (farg0 * farg0)) || (((TObjEnemy *)(arg0))->is_actor_cadence_frame(0x96) != 0)) {
        v.x = v.y = (0.0f);
        v.z = (1.0f);
        ang = (s32) ((182.04445f) * ((3.6e+02f) * ((TObjChara *)arg0)->random_ratio()));
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, ang);
        rotate_vector_by_matrix(0, &v, &v);
        pop_matrix();
        v.x *= range_x;
        v.z *= range_z;
        vec3_add_to(&v, (u8 *)&this->home_position);
        select_enemy_destination(this, v, 1);
        *(f32 *)((s8 *)arg0 + 0x308) = ((TObjEnemy *)arg0)->velocity.z = (0.0f);
        ((TObjEnemy *)arg0)->m_2ac = 0;
    } else {
        ((TObjEnemy *)arg0)->enemy_turn_toward_dest(turn);
        enemy_set_heading_velocity(farg0, (TObjEnemy *)arg0, ((TObjEnemy *)arg0)->rotation_y);
        move_with_wall_slide(this);
        var_f31 = horizontal_distance_squared((u8 *)&this->move_destination, (u8 *)&this->body_center);
        ((TObjEnemy *)arg0)->m_2ac = ((TObjEnemy *)arg0)->m_2ac + 1;
    }
    return var_f31;
}

f32 enemy_backstep_from_point(TObjEnemy *enemy, Vec point, f32 speed) {
    if (select_destination_away_from(enemy, point) != 0) {
        copy_position_if_valid(enemy, enemy->body_center);
        calc_velocity_toward_destination(enemy, enemy->move_origin, enemy->move_destination, speed);
        move_with_wall_slide(enemy);
        return horizontal_distance_squared(&point, &enemy->position);
    }
    return (0.0f);
}

f32 enemy_pursue_point(TObjEnemy *enemy, s32 turn_speed, Vec point, f32 speed, f32 step) {
    f32 d0;
    f32 d1;
    f32 d2;
    s32 a;
    Vec d;
    d0 = horizontal_distance_squared(&enemy->body_center, &enemy->move_origin);
    d1 = horizontal_distance_squared(&enemy->move_origin, &enemy->move_destination);
    d2 = horizontal_distance_squared(&enemy->body_center, &enemy->move_destination);
    if (step * step <= d0 || d1 < (1e-05f) || d2 < (1e-05f) || enemy->is_actor_cadence_frame(0x96) != 0) {
        VecCopy(&d, &point);
        subtract_vector(&d, &enemy->body_center);
        a = (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(d.x, d.z));
        d.z = step;
        d.x = d.y = (0.0f);
        push_matrix_from(&identity_matrix);
        rotate_matrix_y(0, a);
        rotate_vector_by_matrix(0, &d, &d);
        pop_matrix();
        vec3_add_to(&d, &enemy->body_center);
        if (select_enemy_destination(enemy, d, 1) != 0) {
            copy_position_if_valid(enemy, enemy->body_center);
        }
    }
    enemy->enemy_turn_toward_dest(turn_speed);
    enemy_set_heading_velocity(speed, enemy, enemy->rotation_y);
    move_with_wall_slide(enemy);
    return horizontal_distance_squared(&point, &enemy->body_center);
}

f32 step_toward_destination(TObjChara *chara, Vec dest, f32 speed) {
    VecCopy(&chara->move_destination, &dest);
    VecCopy(&chara->move_origin, &chara->body_center);
    calc_velocity_toward_destination(chara, chara->move_origin, chara->move_destination, speed);
    chara->position.x += chara->velocity.x;
    chara->position.z += chara->velocity.z;
    return horizontal_distance_squared(&dest, &chara->position);
}

f32 enemy_move_toward(TObjEnemy *enemy, s32 turn_speed, Vec dest, s32 flags, f32 speed) {
    if (horizontal_distance_squared(&enemy->move_destination, &enemy->position) < (1e-05f) || enemy->is_actor_cadence_frame(0x1E) != 0) {
        if (select_enemy_destination(enemy, dest, flags) != 0) {
            copy_position_if_valid(enemy, enemy->body_center);
        }
    }
    enemy->enemy_turn_toward_dest(turn_speed);
    enemy_set_heading_velocity(speed, enemy, enemy->rotation_y);
    move_with_wall_slide(enemy);
    return horizontal_distance_squared(&dest, &enemy->position);
}

s32 TObjChara::is_target_in_attack_range() {
    Vec v;
    Vec base;
    Vec out;
    Target_8001745C *t;
    s32 i;
    s32 ang;
    f32 range;
    f32 dist;
    f32 prod;
    Player_8001745C *p = (Player_8001745C *)this;
    if (p->target != NULL && p->f318 != 0 &&
        ((TObject *)(p->target))->all_parents_unqueued_for_destruction() != 0 &&
        ((u8 * (*)(u16))find_entity_by_id)(((TObjBase *)(p->target))->get_entity_id()) != NULL) {
        t = p->target;
        if (!(t->flags30 & 0x800)) {
            if (t->parts != NULL) {
                VCOPY(&base, &t->pos);
                for (i = 0; i < p->target->nparts; i++) {
                    if (!(p->target->parts[i].flags & 0x02000000)) {
                        VCOPY(&v, &p->target->parts[i]);
                        push_matrix_from(&identity_matrix);
                        rotate_matrix_y(0, p->target->rotY);
                        rotate_vector_by_matrix(0, &v, &v);
                        pop_matrix();
                        vec3_add_to(&v, &base);
                        subtract_vector(&v, &p->pos);
                        dist = v.x * v.x + v.z * v.z;
                        range = (p->target->parts[i].radius + ((TObjChara *)p)->get_attack_range()) * (p->target->parts[i].radius + ((TObjChara *)p)->get_attack_range());
                        ang = ((s32)angle_difference_abs(this->rotation_y, (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(v.x, v.z))));
                        if (dist < range && ang < ((TObjChara *)p)->get_attack_angle()) {
                            return 1;
                        }
                    }
                }
            } else {
                dist = calc_xz_distance_sq(this, reinterpret_cast<const TObjBase *>(t), &out);
                ang = ((s32)angle_difference_abs(this->rotation_y, (s32)(TObjPlayer__data_804340B8 * ((f64 (*)(f32, f32))atan2_float)(out.x, out.z))));
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

s32 TObjChara::vfunc_43() {
    if (this->test_actor_flags(0x40) != 0) {
        this->clear_harmful_statuses();
        return 1;
    }
    if (this->obj_isState2_324() != 0) {
        if (this->test_actor_flags(3) == 0) {
            switch (this->get_status_effect_type(0)) {
            case 0x10:
                adjust_evp((s32)(this->get_base_evp() * -this->get_status_effect_amount(0)));
                break;
            }
            this->status_effects[0].clear();
        }
        if (this->test_actor_flags(0x3C) == 0) {
            switch (this->get_status_effect_type(1)) {
            case 2:
            case 3:
                adjust_evp((s32)(this->get_base_evp() * -this->get_status_effect_amount(1)));
                break;
            }
            this->status_effects[1].clear();
        }
    }
    return 0;
}
#undef VCOPY
s32 TObjChara::update_poison_status() {
    s32 dmg;

    if (this->test_actor_flags(1) != 0) {
        if ((this->add_status_effect_timer(0, 1) % 45) == 0) {
            this->spawn_poison_effect(1);
            this->set_status_effect_timer(0, 0);
            dmg = (s32) ((0.006666667f) * (f32) get_actor_hp());
            if ((s16) dmg < 1) {
                dmg = 1;
            }
            ((s32 (*)(u8 *, s32, const s16 *))TObjectV8047c128_subtract_hp)(((u8 *)this), dmg + poison_damage_bonus_by_difficulty[game_difficulty_selection], poison_damage_bonus_by_difficulty);
            if (this->clamp_hp() <= 0) {
                if (this->test_actor_flags(0x800) == 0) {
                    ((TObjPlayer *)((u8 *)this))->set_hp_clamped(1);
                }
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

s32 TObjChara::update_action_hold_status() {
    f32 temp_f31;
    s32 temp_r31;

    if ((this->test_actor_flags(0x4000) != 0) && ((u16) this->entity_id >= 0x1000U)) {
        if (this->add_status_effect_timer(4, -1) <= 0) {
            this->status_effects[4].clear();
            this->clear_actor_flags((u32)(0x4000));
        }
        return 1;
    }
    if (((TObjCollidable *)((((u8 *)this))))->test_actor_flags(2) != 0) {
        temp_r31 = this->add_status_effect_timer(0, -1);
        if ((u16) this->entity_id < 0x1000U) {
            if (temp_r31 <= 0) {
                this->spawn_paralysis_feedback_effect(1);
                this->set_status_effect_timer(0, 0x2D);
            }
            return 1;
        }
        if (temp_r31 > 0) {
            ((TObjBase *)((u8 *)this))->clear_actor_flags((u32)(3));
            set_actor_flags(2);
            if ((temp_r31 % 45) == 0) {
                this->spawn_paralysis_feedback_effect(1);
            }
            return 1;
        }
        ((TObjBase *)((u8 *)this))->clear_actor_flags((u32)(3));
        *(s32 *)((s8 *)((u8 *)this) + 0x330) = (s32) (this->actorFlags & 0x3F);
        temp_f31 = -this->get_status_effect_amount(0);
        {
            f32 v = ((TObjChara *)((u8 *)this))->get_base_evp();
            v *= temp_f31;
            ((TObjChara *)((u8 *)this))->adjust_evp((s32) v);
        }
        this->status_effects[0].clear();
    }
    return 0;
}

s32 TObjChara::update_slow_status() {
    s32 temp_ret;

    if ((((TObjCollidable *)(((u8 *)this)))->test_actor_flags(8) != 0) && ((u16) ((TObjChara *)((u8 *)this))->entity_id < 0x1000U)) {
        temp_ret = this->add_status_effect_timer(1, -1);
        if (temp_ret > 0) {
            if ((temp_ret % 45) == 0) {
                this->spawn_slow_effect(1);
            }
            return 1;
        }
        ((TObjBase *)((u8 *)this))->clear_actor_flags((u32)0x3C);
        *(s32 *)((s8 *)((u8 *)this) + 0x330) = (s32) (((TObjChara *)((u8 *)this))->actorFlags & 0x3F);
        this->status_effects[1].clear();
        goto block_7;
    }
block_7:
    return 0;
}

s32 TObjChara::update_flag30_timer() {
    s32 temp_ret;

    if (this->test_actor_flags(0x10) != 0) {
        temp_ret = this->add_status_effect_timer(1, -1);
        if (temp_ret > 0) {
            this->clear_actor_flags((u32)0x3C);
            set_actor_flags(0x10);
            if ((temp_ret % 45) == 0) {
                this->spawn_confusion_feedback_effect(1);
            }
            return 1;
        }
        this->clear_actor_flags((u32)0x3C);
        *(s32 *)((s8 *)((u8 *)this) + 0x330) = (s32) (this->actorFlags & 0x3F);
        this->status_effects[1].clear();
        goto block_6;
    }
block_6:
    return 0;
}

s32 TObjChara::update_movement_status() {
    f32 temp_f31;
    f32 fv;
    s32 temp_ret;

    if (this->test_actor_flags(0x20) != 0) {
        temp_ret = this->add_status_effect_timer(1, -1);
        if (temp_ret > 0) {
            this->clear_actor_flags((u32)0x3C);
            set_actor_flags(0x20);
            if ((temp_ret % 45) == 0) {
                ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0xB20F, ((u8 *)this) + 0x38, 0, 0);
            }
            return 1;
        }
        this->clear_actor_flags((u32)0x3C);
        *(s32 *)((s8 *)((u8 *)this) + 0x330) = (s32) (this->actorFlags & 0x3F);
        temp_f31 = -this->get_status_effect_amount(1);
        fv = (f32) this->get_base_evp();
        this->adjust_evp((s32) (fv * temp_f31));
        this->status_effects[1].clear();
        goto block_6;
    }
block_6:
    return 0;
}

s32 TObjChara::update_shock_clock() {
    f32 temp_f31;
    f32 fv;
    s32 temp_ret;
    if (this->test_actor_flags(4) != 0) {
        temp_ret = this->add_status_effect_timer(1, -1);
        if (temp_ret > 0) {
            this->clear_actor_flags((u32)0x3C);
            set_actor_flags(4);
            if ((temp_ret % 45) == 0) {
                this->play_shock_feedback(1);
            }
            return 1;
        }
        this->clear_actor_flags((u32)0x3C);
        *(s32 *)((s8 *)((u8 *)this) + 0x330) = (s32) (this->actorFlags & 0x3F);
        if ((u16) this->entity_id >= 0x1000U) {
            temp_f31 = -this->get_status_effect_amount(1);
            fv = (f32) this->get_base_evp();
            this->adjust_evp((s32) (fv * temp_f31));
        }
        this->status_effects[1].clear();
        goto block_8;
    }
block_8:
    return 0;
}

s32 TObjChara::update_attack_stat_status() {
    s32 temp_ret;

    if (this->get_status_effect_timer(2) > 0) {
        temp_ret = this->add_status_effect_timer(2, -1);
        if (temp_ret > 0) {
            if (((temp_ret % 45) == 0) && (((TObjCollidable *)(((u8 *)this)))->test_actor_flags(0x02000000) == 0)) {
                switch (this->get_status_effect_type(2)) {
                case 10:
                    break;
                case 9:
                    ((TObjChara *)((u8 *)this))->apply_switch_attack();
                    if ((((TObjCollidable *)(((u8 *)this)))->test_actor_flags(0x10000000) == 0) || (TObjPlayer::is_locally_controlled(((u8 *)this)) != 0)) {
                        ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x4002462A, ((u8 *)this) + 0x38, 0, 0);
                    }
                    break;
                case 11:
                    ((TObjChara *)((u8 *)this))->enemy_spawn_jellen_effect();
                    if ((((TObjCollidable *)(((u8 *)this)))->test_actor_flags(0x10000000) == 0) || (TObjPlayer::is_locally_controlled(((u8 *)this)) != 0)) {
                        ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x4002442B, ((u8 *)this) + 0x38, 0, 0);
                    }
                    break;
                }
                new TActorLight(0.1f, (NJS_ARGB *)player_attack_stat_status_light_colors, (Vec *)TObjPlayer__data_80434060, 0x2D, this, tl_07);
            }
            return 1;
        }
        ((TObjChara *)((u8 *)this))->adjust_atp((s32) ((f32) ((TObjChara *)((u8 *)this))->get_base_atp() * -this->get_status_effect_amount(2)));
        ((TObjChara *)((u8 *)this))->adjust_atp_range((s32) ((f32) ((TObjChara *)((u8 *)this))->get_base_atp_range() * -this->get_status_effect_amount(2)));
        this->status_effects[2].clear();
    } else if (this->obj_isState2_324() != 0) {
        ((TObjChara *)((u8 *)this))->adjust_atp((s32) ((f32) ((TObjChara *)((u8 *)this))->get_base_atp() * -this->get_status_effect_amount(2)));
        ((TObjChara *)((u8 *)this))->adjust_atp_range((s32) ((f32) ((TObjChara *)((u8 *)this))->get_base_atp_range() * -this->get_status_effect_amount(2)));
        this->status_effects[2].clear();
    }
    return 0;
}

s32 TObjChara::update_defense_stat_status() {
    s32 temp_ret;

    if (this->get_status_effect_timer(3) > 0) {
        temp_ret = this->add_status_effect_timer(3, -1);
        if (temp_ret > 0) {
            if (((temp_ret % 45) == 0) && (((TObjCollidable *)(((u8 *)this)))->test_actor_flags(0x02000000) == 0)) {
                switch (this->get_status_effect_type(3)) {
                case 11:
                    break;
                case 10:
                    this->trigger_switch_attack();
                    if ((((TObjCollidable *)(((u8 *)this)))->test_actor_flags(0x10000000) == 0) || (TObjPlayer::is_locally_controlled(((u8 *)this)) != 0)) {
                        ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x40022C2C, ((u8 *)this) + 0x38, 0, 0);
                    }
                    break;
                case 12:
                    this->enemy_spawn_zalure_effect();
                    if ((((TObjCollidable *)(((u8 *)this)))->test_actor_flags(0x10000000) == 0) || (TObjPlayer::is_locally_controlled(((u8 *)this)) != 0)) {
                        ((s32 (*)(s32, void *, s32, s32))play_sound_effect)(0x4002362D, ((u8 *)this) + 0x38, 0, 0);
                    }
                    break;
                }
                new TActorLight(0.1f, (NJS_ARGB *)player_defense_stat_status_light_colors, (Vec *)TObjPlayer__data_80434060, 0x2D, this, tl_07);
            }
            return 1;
        }
        this->adjust_dfp((s32) ((f32) this->get_base_dfp() * -this->get_status_effect_amount(3)));
        this->status_effects[3].clear();
    } else if (this->obj_isState2_324() != 0) {
        this->adjust_dfp((s32) ((f32) this->get_base_dfp() * -this->get_status_effect_amount(3)));
        this->status_effects[3].clear();
    }
    return 0;
}

s32 TObjChara::select_melee_contact_body(void *source, f32 factor) {
    s32 selected = -1;
    Vec point;
    s32 i;
    s32 diff;
    f32 dist2;
    f32 r2;
    f32 dist;
    f32 r;
    if (((Actor_80016454 *)source) != NULL) {
    if (((Actor_80016454 *)this)->bodies != NULL) {
        push_matrix();
        set_matrix_identity(0);
        ((void (*)(s32, f32, f32, f32))translate_matrix)(0, -((Actor_80016454 *)source)->pos.x, -((Actor_80016454 *)source)->pos.y, -((Actor_80016454 *)source)->pos.z);
        post_translate_matrix(&((Actor_80016454 *)this)->pos);
        rotate_matrix_y(0, ((Actor_80016454 *)this)->yaw);
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

s32 TObjChara::try_start_action(s32 attacker, s32 collider) {
    if (((VObj_800163F8 *)this)->m25() != 0) {
        return 1;
    }
    ((TObjPlayer *)this)->show_miss_for_collider(collider);
    return 0;
}
#pragma push
#pragma fp_contract on
s32 TObjChara::roll_physical_accuracy(void *attacker, s32 collider, f32 accuracy) {
    f32 v;

    if (attacker == NULL) {
        return 0;
    }
    if (this->test_actor_flags(0x04000800) == 0) {
        v = (0.01f) * ((accuracy * (f32) ((TObjPlayer *)attacker)->get_ata()) - ((0.2f) * (f32) evp));
        if ((0.0f) < v && this->random_ratio() <= v) {
            bodies[collider].flags |= 0x04000000;
            hit_flags |= 1;
            return 1;
        }
        actorFlags |= 0x100;
    }
    return 0;
}
}

#pragma pop
void TObjPlayer::show_miss_for_collider(s32 collider) {
    this->show_miss_popup((const float*)((*(uaddr *)&this->bodies) + collider*0x2C + 0x1C));
}

void TObjChara::show_miss_popup(const float *pos) {
    if (this->test_actor_flags(0x02000000) == 0 && TObjPlayer::is_locally_controlled((void *)(this)) == 0 && pos != NULL) {
        if (TObjPlayer::get_player_count() == 0 || this->entity_id >= 0x1000) {
            TOCtrlDubchik::create_font((saddr)pos, 0xFFFF0000, 0x14, lbl_804340B0);
        }
    }
}

void TObjChara::try_apply_damage(const Vec *pos, s32 damage) {
    if ((this->test_actor_flags(0x02000000) == 0) && (TObjPlayer::is_locally_controlled((void *)(this)) == 0) && (pos != NULL) && ((s16) damage >= 0) && ((TObjPlayer::get_player_count() == 0) || ((u16) this->entity_id >= 0x1000U))) {
        create_damage_font__19TObjEneEpsilonGuardFllll((uaddr)pos, -1, 0x14, (s16) damage);
    }
}

void draw_hp_label(void *player, u32 pos, s32 delay, s16 arg3) {
    if ((((TObjCollidable *)player)->test_actor_flags(0x02000000) == 0) && (TObjPlayer::is_locally_controlled((void *)(player)) == 0) && (pos != 0U)) {
        create_font_small_task_default_color(pos, 0xFF00FF00, 0x14, delay, (s32 *)"HP", (s16)arg3);
    }
}

void show_tp_font(saddr player, u32 pos, s32 delay, s32 arg3) {
    if ((((TObjCollidable *)player)->test_actor_flags(0x02000000) == 0) && (TObjPlayer::is_locally_controlled((void *)(player)) == 0) && (pos != 0U)) {
        create_font_small_task_default_color(pos, 0xFF00B2FF, 0x14, delay, (s32 *)"TP", arg3);
    }
}

void show_meseta_label(saddr player, u32 arg1, s32 arg2, s32 arg3) {
    s32 size;
    if (((TObjCollidable *)player)->test_actor_flags(0x02000000) == 0 && arg1 != 0) {
        size = 0x14;
        if (TObjPlayer::is_locally_controlled((void *)(player)) != 0) {
            size <<= 1;
        }
        create_font_small_task(arg1, -0x100, size, arg2, (s32 *)lbl_804340A8, arg3, ((TObjBase *)(player))->get_entity_id());
    }
}

void display_exp_gain(saddr player, u32 pos, s32 delay, s32 arg3) {
    if ((((TObjCollidable *)player)->test_actor_flags(0x02000000) == 0) && (TObjPlayer::is_locally_controlled((void *)(player)) == 0) && (pos != 0U)) {
        create_font_small_task(pos, 0xFFFF00FF, 0x14, delay, (s32 *)"EXP", arg3, ((TObjBase *)(player))->get_entity_id());
    }
}

#pragma push
#pragma fp_contract on
int TObjChara::calc_distance_accuracy_penalty(void *attacker, void *body_arg, void *origin, float multiplier) {
    CollisionBody *body = (CollisionBody *)body_arg;
    Vec delta;
    if (attacker && body && !(this->actorFlags & 0x04000000)) {
        float chance = 0.01f * (multiplier * (float)((TObjPlayer *)attacker)->get_ata() - 0.2f * (float)this->evp);
        VecCopy(&delta, &body->center);
        if (!((TObjChara *)attacker)->obj_testFlag_2E4(0x20)) {
            if (origin) {
                subtract_vector(&delta, static_cast<const Vec *>(origin));
            } else {
                subtract_vector(&delta, &((TObjChara *)attacker)->position);
            }
            const float squared = delta.x * delta.x + delta.z * delta.z;
            const float dist = newton_sqrtf(squared);
            float pen = (float)(dist * lbl_80434090);
            pen *= 0.33333334f;
            chance -= pen;
        }
        if (0.0f < chance && this->random_ratio() <= chance) {
            body->flags |= 0x04000000;
            attach_mine_trap__10TObjPlayerFiUi((saddr)this, (uaddr)attacker);
            this->hit_flags |= 2;
            return 1;
        }
        this->actorFlags |= 0x100;
        VecCopy(&delta, &body->center);
        this->show_miss_popup((const float *)&delta);
    }
    return 0;
}

#pragma pop
s16 *TObjPlayer::get_attribute_entry(s32 i) {
    O_80015DC4 *self = (O_80015DC4 *)this;
    if (i < 3) {
        return &self->arr[i];
    }
    return 0;
}

void TObjPlayer::copy_entry_bytes(void* q) { *(u8*)((char*)this + 0x0) = *(u8*)((char*)q + 0x0); *(u8*)((char*)this + 0x1) = *(u8*)((char*)q + 0x1); }

void TObjPlayer::set_attribute_entry(s32 i, void *q) {
    O_80015D74 *self = (O_80015D74 *)this;
    if (i < 3) {
        ((TObjPlayer *)(&self->arr[i]))->copy_entry_bytes(q);
    }
}

void TObjChara::trigger_switch_attack(const Vec *pos) {
    if (this->test_actor_flags(0x02000000) == 0) {
        switch (this->target_attribute_mask) {
        case 1:
            spawn_particle_effect_with_flags((const Vec *)pos, 0xF1, 0x40);
            return;
        case 2:
            spawn_particle_effect_with_flags((const Vec *)pos, 0xF2, 0x40);
            return;
        case 4:
            spawn_particle_effect_with_flags((const Vec *)pos, 0xE3, 0x40);
            return;
        case 8:
            spawn_particle_effect_with_flags((const Vec *)pos, 0x10D, 0x40);
            break;
        }
    }
}

void TObjPlayer::spawn_recovery_effect() {
    if (this->test_actor_flags(0x02000000) == 0) {
        create_timed_particle_emitter_with_flags(&body_center, 0x10A, 0, 0xA, 0x40);
    }
}

void TObjChara::apply_poison_status() {
    f32 temp_f31;

    if ((this->obj_testFlag_2E4(4) == 0) && ((u16) this->entity_id < 0x1000U) && (this->test_immunity_flags(1) == 0)) {
        this->spawn_poison_effect(0);
        if (this->get_status_effect_type(0) == 0x10) {
            f32 temp_d4;
            temp_f31 = -this->get_status_effect_amount(0);
            temp_d4 = (f32) this->get_base_evp();
            adjust_evp((s32) (temp_d4 * temp_f31));
        }
        this->set_status_effect_type(0, 0xF);
        this->set_status_effect_amount(0, (0.0f));
        this->set_status_effect_timer(0, 0x2D);
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFFC);
        this->actorFlags = (s32) (this->actorFlags | 1);
    }
}

void TObjChara::apply_paralysis() {
    if ((this->obj_testFlag_2E4(4U) == 0) && (this->test_actor_flags(0x01000000U) == 0) && (this->test_immunity_flags(2) == 0)) {
        this->spawn_paralysis_feedback_effect(0);
        if (this->get_status_effect_type(0) == 0x10) {
            adjust_evp((s32) ((f32) this->get_base_evp() * -this->get_status_effect_amount(0)));
        }
        this->set_status_effect_type(0, 0x10);
        if ((u16) this->entity_id >= 0x1000U) {
            this->set_status_effect_amount(0, (f32) ((-0.15f)));
            adjust_evp((s32) ((-0.15f) * (f32) this->get_base_evp()));
            this->set_status_effect_timer(0, 0xD2);
        } else {
            this->set_status_effect_amount(0, (f32) ((0.0f)));
            this->set_status_effect_timer(0, 0);
        }
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFFC);
        this->actorFlags = (s32) (this->actorFlags | 2);
    }
}

void TObjChara::apply_slow_status() {
    f32 temp_f31;
    if (((u16) this->entity_id <= 0x1000U) && (this->test_immunity_flags(8) == 0)) {
        this->spawn_slow_effect(0);
        switch (this->get_status_effect_type(1)) {
        case 2:
        case 3:
            adjust_evp((s32) ((f32) this->get_base_evp() * -this->get_status_effect_amount(1)));
            break;
        }
        this->set_status_effect_type(1, 0x11);
        this->set_status_effect_amount(1, (0.0f));
        this->set_status_effect_timer(1, 0xD2);
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC3);
        this->actorFlags = (s32) (this->actorFlags | 8);
    }
}

void TObjChara::apply_confusion_status() {
    f32 temp_f31;

    if ((this->obj_testFlag_2E4(0x10) == 0) && (this->test_immunity_flags(0x10) == 0)) {
        this->spawn_confusion_feedback_effect(0);
        switch (this->get_status_effect_type(1)) {
        case 2:
        case 3:
            adjust_evp((s32) ((f32) this->get_base_evp() * -this->get_status_effect_amount(1)));
            break;
        }
        this->set_status_effect_type(1, 0x12);
        this->set_status_effect_amount(1, (0.0f));
        this->set_status_effect_timer(1, 0x12C);
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC3);
        this->actorFlags = (s32) (this->actorFlags | 0x10);
    }
}

void TObjChara::apply_movement_ailment(s32 arg1) {

    if ((this->test_actor_flags(0x8000U) == 0) && (this->test_actor_flags(0x01000000U) == 0) && (this->test_immunity_flags(0x20) == 0) && ((this->test_actor_flags(0x20U) == 0) || (this->get_status_effect_timer(1) <= 0))) {
        spawn_freeze_shell_effect(arg1, 1);
        switch (this->get_status_effect_type(1)) {
        case 2:
        case 3:
            adjust_evp((s32)((f32)this->get_base_evp() * -this->get_status_effect_amount(1)));
            break;
        }
        this->set_status_effect_type(1, 2);
        this->set_status_effect_amount(1, (f32) ((-0.3f)));
        this->set_status_effect_timer(1, 0x96);
        this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC3);
        this->actorFlags = (s32) (this->actorFlags | 0x20);
        adjust_evp((s32) ((-0.3f) * (f32) this->get_base_evp()));
    }
}

void TObjChara::apply_shock_status() {
    s32 ok;
    f32 k;
    f32 v;

    ok = 0;
    if (this->get_entity_id() >= 0x1000 && this->get_entity_id() < 0x4000 &&
        this->obj_testFlag_2E4(4) != 0 && this->test_actor_flags(0x01000000) == 0 &&
        this->test_immunity_flags(4) == 0) {
        ok = 1;
    }
    if (this->get_entity_id() < 0x1000 && this->test_immunity_flags(4) == 0) {
        ok = 1;
    }
    if (ok != 0) {
        if (this->test_actor_flags(0x02000000) == 0) {
            this->play_shock_feedback(1);
        }
        switch (this->get_status_effect_type(1)) {
        case 2:
        case 3:
            k = -this->get_status_effect_amount(1);
            v = (f32)this->get_base_evp();
            v *= k;
            adjust_evp((s32)v);
            break;
        }
        this->set_status_effect_type(1, 3);
        if (this->get_entity_id() < 0x1000) {
            this->set_status_effect_amount(1, (0.0f));
        } else {
            this->set_status_effect_amount(1, (-0.15f));
        }
        this->set_status_effect_timer(1, 0x12C);
        this->actorFlags &= ~0x3C;
        this->actorFlags |= 4;
        if (this->entity_id >= 0x1000) {
            adjust_evp((s32)((-0.15f) * (f32)this->get_base_evp()));
        }
    }
}

void TObjChara::clear_harmful_statuses() {
    switch (this->get_status_effect_type(0)) {
    case 0x10:
        adjust_evp((s32)((f32)this->get_base_evp() * -this->get_status_effect_amount(0)));
        break;
    }
    switch (this->get_status_effect_type(1)) {
    case 2:
    case 3:
        adjust_evp((s32)((f32)this->get_base_evp() * -this->get_status_effect_amount(1)));
        break;
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC0);
    *(s32 *)&this->unk_330 = (s32) (*(s32 *)&this->actorFlags & 0x3F);
    this->status_effects[0].clear();
    this->status_effects[1].clear();
    switch (this->get_status_effect_type(2)) {
    case 0xB:
        this->adjust_atp((s32)((f32)this->get_base_atp() * -this->get_status_effect_amount(2)));
        this->adjust_atp_range((s32)((f32)this->get_base_atp_range() * -this->get_status_effect_amount(2)));
        this->status_effects[2].clear();
        break;
    }
    switch (this->get_status_effect_type(3)) {
    case 0xC:
        this->adjust_dfp((s32)((f32)this->get_base_dfp() * -this->get_status_effect_amount(3)));
        this->status_effects[3].clear();
        break;
    }
}

#pragma push
#pragma fp_contract on
void TObjChara::apply_attack_stat_status(void *arg1_arg) {
    StatStatusReceipt *arg1 = (StatStatusReceipt *)arg1_arg;
    f32 var_f31;
    f32 temp_f30;
    f32 status_effect_amount;

    if ((s32) arg1->kind != 0xB) {
        var_f31 = (0.01f) * ((1.3f) * arg1->power + (1e+01f));
    } else {
        var_f31 = (-0.01f) * ((1.3f) * arg1->power + (1e+01f));
    }
    status_effect_amount = this->get_status_effect_amount(2);
    temp_f30 = ((f32 (*)(f32))fabs_float)(var_f31);
    if (!(((f32 (*)(f32))fabs_float)(status_effect_amount) > temp_f30)) {
        temp_f30 = -this->get_status_effect_amount(2);
        {
            f32 v = this->get_base_atp();
            v *= temp_f30;
            this->adjust_atp((s32) v);
        }
        temp_f30 = -this->get_status_effect_amount(2);
        {
            f32 v = this->get_base_atp_range();
            v *= temp_f30;
            this->adjust_atp_range((s32) v);
        }
        this->set_status_effect_type(2, arg1->kind);
        this->set_status_effect_amount(2, var_f31);
        this->adjust_atp((s32) (var_f31 * (f32) this->get_base_atp()));
        this->adjust_atp_range((s32) (var_f31 * (f32) this->get_base_atp_range()));
        this->set_status_effect_timer(2, (s32) ((3e+01f) * ((1e+01f) * arg1->power + (4e+01f))));
        if (((TObjCollidable *)(((TObjPlayer *)this)))->test_actor_flags(0x02000000) == 0) {
            new TActorLight(0.1f, (NJS_ARGB *)player_attack_stat_status_light_colors, (Vec *)TObjPlayer__data_80434060, 0x2D, this, tl_07);
        }
    }
}

void TObjChara::apply_defense_stat_status(void *receipt_arg) {
    StatStatusReceipt *receipt = (StatStatusReceipt *)receipt_arg;
    f32 temp_f31;
    f32 var_f30;
    f32 status_effect_amount;

    if (receipt->kind != 0xC) {
        var_f30 = (0.01f) * ((1.3f) * receipt->power + (1e+01f));
    } else {
        var_f30 = (-0.01f) * ((1.3f) * receipt->power + (1e+01f));
    }
    status_effect_amount = this->get_status_effect_amount(3);
    temp_f31 = ((f32 (*)(f32))fabs_float)(var_f30);
    if (!(((f32 (*)(f32))fabs_float)(status_effect_amount) > temp_f31)) {
        temp_f31 = -this->get_status_effect_amount(3);
        {
            f32 v = this->get_base_dfp();
            v *= temp_f31;
            this->adjust_dfp((s32) v);
        }
        this->set_status_effect_type(3, receipt->kind);
        this->set_status_effect_amount(3, var_f30);
        this->adjust_dfp((s32) (var_f30 * (f32) this->get_base_dfp()));
        this->set_status_effect_timer(3, (s32) ((3e+01f) * ((1e+01f) * receipt->power + (4e+01f))));
        if (this->test_actor_flags(0x02000000) == 0) {
            new TActorLight(0.1f, (NJS_ARGB *)player_defense_stat_status_light_colors, (Vec *)TObjPlayer__data_80434060, 0x2D, this, tl_07);
        }
    }
}

#pragma pop
void TObjChara::cure_poison_ailment() {
    switch (this->get_status_effect_type(0)) {
    case 0xf:
        ((Obj_80014C1C *)this)->f30 &= ~3;
        ((Obj_80014C1C *)this)->f330 = ((Obj_80014C1C *)this)->f30 & 0x3f;
        this->status_effects[0].clear();
        break;
    }
}

void TObjChara::cure_paralysis() {
    switch (this->get_status_effect_type(0)) {
    case 0x10:
        adjust_evp((s32) ((f32) this->get_base_evp() * -this->get_status_effect_amount(0)));
        ((Obj_80014B5C *)this)->f30 &= ~3;
        ((Obj_80014B5C *)this)->f330 = ((Obj_80014B5C *)this)->f30 & 0x3f;
        this->status_effects[0].clear();
        break;
    }
}

void TObjChara::clear_all_status_effects() {
    switch (this->get_status_effect_type(0)) {
    case 0x10:
        this->adjust_evp((s32) ((f32) this->get_base_evp() * -this->get_status_effect_amount(0)));
        break;
    }
    switch (this->get_status_effect_type(1)) {
    case 2:
    case 3:
        this->adjust_evp((s32) ((f32) this->get_base_evp() * -this->get_status_effect_amount(1)));
        break;
    }
    this->actorFlags = (s32) (this->actorFlags & 0xFFFFFFC0);
    *(s32 *)((s8 *)((u8 *)this) + 0x330) = (s32) (this->actorFlags & 0x3F);
    this->status_effects[0].clear();
    this->status_effects[1].clear();
    this->adjust_atp((s32) ((f32) this->get_base_atp() * -this->get_status_effect_amount(2)));
    this->adjust_atp_range((s32) ((f32) this->get_base_atp_range() * -this->get_status_effect_amount(2)));
    this->status_effects[2].clear();
    this->adjust_dfp((s32) ((f32) this->get_base_dfp() * -this->get_status_effect_amount(3)));
    this->status_effects[3].clear();
    clear_actor_flags((u32)0x4000U);
    this->status_effects[4].clear();
}

void TObjChara::apply_action_hold_status(f32 power) {
    saddr arg0 = (saddr)this;
    ((TObjChara *)arg0)->set_status_effect_type(4, 0x14);
    ((TObjChara *)arg0)->set_status_effect_timer(4, (s32) power);
    set_actor_flags(0x4000U);
}

void TObjChara::run_idle_action() {  }

void TObjChara::run_move_action() {  }

void TObjChara::run_attack_action() {  }

void TObjChara::run_miss_reaction() {  }

void TObjChara::run_hit_reaction() {  }

void TObjChara::run_death_reaction() {  }

void TObjChara::reset_pose() { clear_actor_flags((uaddr)((void*)2048)); *(short *)&this->hp = *(short *)&this->hpmax; this->tp = this->tpmax; }

void TObjChara::get_anim_node_position(s32, Vec *) {  }

int TObjChara::vfunc_66() { return 0; }

int TObjChara::deliver_attack_hits(f32) { return 0; }

#pragma push
#pragma fp_contract on
#pragma opt_loop_invariants off
#define attach_mine_trap__10TObjPlayerFiUi(a, b) ((void (*)(void *, void *))attach_mine_trap__10TObjPlayerFiUi)(a, b)
#define TObjectV8047c128_subtract_hp(a, b) ((void (*)(void *, s32))TObjectV8047c128_subtract_hp)(a, b)
#define VecCopy__FP3VecPC3Vec(a, b) ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(a, b)
#define get_actor_attack_params_atp_min__9TObjCharaFv(a) (((TObjChara *)(a))->get_actor_attack_params_atp_min())
#define get_type__10TObjPlayerFPv(a) ((s32 (*)(void *))get_type__10TObjPlayerFPv)(a)
#define play_sound_effect(a, b, c, d) ((void (*)(s32, void *, s32, s32))play_sound_effect)(a, b, c, d)
#define RESIST_80014108(k) \
    dmg += ((Obj_80014108 *)att)->atkElem[k] * (0.01f * (f32)(100 - ((Obj_80014108 *)this)->resist[k]));
#define COLL_80014108() (&((Obj_80014108 *)this)->colls[i])
f32 TObjChara::receive_physical_attack(void *att, f32 scale) {
    Vec hit;
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

    if (((Obj_80014108 *)att) == NULL || ((TObjBase *)att)->get_entity_id() == 0xFFFF || this->test_actor_flags(0x800) != 0) {
        return 0.0f;
    }
    if (this->test_actor_flags(0x04000000) != 0 && this->test_actor_flags(0x02000000) == 0) {
        this->try_apply_damage((const Vec *)((u8 *)this + 0x2FC), 0);
        return 0.0f;
    }
    attach_mine_trap__10TObjPlayerFiUi(((Obj_80014108 *)this), ((Obj_80014108 *)att));
    if (((TObjChara *)this)->obj_isState2_324() != 0) {
        immune = 1;
    } else if (((TObjChara *)att)->obj_isState2_324() != 0) {
        if (TObjPlayer::is_locally_controlled(((Obj_80014108 *)this)) != 0 && get_type__10TObjPlayerFPv((u8 *)((Obj_80014108 *)att) + 0x828) != 0) {
            immune = 0;
        } else {
            immune = 1;
        }
    } else {
        immune = 0;
    }
    scl0 = this->random_ratio();
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
                this->try_apply_damage((const Vec *)&hit, (s32)d);
            } else {
                d *= scale;
                if (this->test_actor_flags(0x02000000) == 0) {
                    boss = this->random_ratio();
                    if (((TObjBase *)att)->get_entity_id() < 0x1000) {
                        crit = boss; crit *= (5e+02f);
                    } else {
                        crit = boss; crit *= (2e+02f);
                    }
                    lck = ((Obj_80014108 *)att)->lck;
                    if (100.0f < lck) {
                        lck = 100.0f;
                    }
                    if (crit <= lck) {
                        TEffClitical::create(&hit);
                        play_sound_effect(0x4001A31F, &hit, 0, 0);
                        d *= (1.5f);
                    } else {
                        create_hit_effect__10TObjPlayerFPv(&hit);
                    }
                    ((TObjChara *)this)->trigger_switch_attack((const Vec *)&hit);
                    this->try_apply_damage((const Vec *)&hit, (s32)d);
                }
                total += d;
            }
        }
    }
    if (total <= 0.0f) {
        ((Obj_80014108 *)this)->flags30 |= 0x100;
        return 0.0f;
    }
    set_actor_flags(0x200);
    this->check_heavy_damage_flag(total);
    if (immune == 0) {
        TObjectV8047c128_subtract_hp(((Obj_80014108 *)this), (s32)total);
        if (((Obj_80014108 *)this)->hp <= 0) {
            ((Obj_80014108 *)this)->flags30 |= 0x800;
        }
    }
    if (immune == 0) {
        ((TObjChara *)((Obj_80014108 *)this))->sync_enemy_state(0);
    }
    if (TObjPlayer::is_locally_controlled(((Obj_80014108 *)this)) != 0) {
        TObjPlayer::calc_photon_blast_charge(((Obj_80014108 *)this), (s32)(20.0f * total));
        ((VObj_18_d805cd *)((Obj_80014108 *)this))->m73();
    }
    record_local_damage_if_enabled(((Obj_80014108 *)this), ((Obj_80014108 *)att), (s32)total);
    empty_post_damage_hook(((Obj_80014108 *)this), ((Obj_80014108 *)att));
    return total;
}

#pragma pop
#undef attach_mine_trap__10TObjPlayerFiUi
#undef TObjectV8047c128_subtract_hp
#undef VecCopy__FP3VecPC3Vec
#undef get_actor_attack_params_atp_min__9TObjCharaFv
#undef get_type__10TObjPlayerFPv
#undef play_sound_effect
#undef RESIST_80014108
#undef COLL_80014108
void TObjChara::apply_knockback_from_attacker(u8 *arg1, f32) {
    Vec diff;
    f32 scale;
    if (this->obj_isState2_324() != 1 && this->test_actor_flags(0x04000000) == 0) {
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&diff, arg1 + 0x38);
    ((s32 (*)(void *, void *))subtract_vector)(&diff, ((u8 *)this) + 0x38);
    if ((diff.x * diff.x) + (diff.z * diff.z) < (1e-05f)) {
        *(f32 *)((s8 *)((u8 *)this) + 0x308) = (0.0f);
        this->velocity.z = (0.0f);
        return;
    }
    scale = 10.0f + (10.0f - this->stat_block->mbr_0x14);
    if (scale < 0.0f) {
        scale = 0.0f;
    }
    normalize_vector_safe(&diff);
    *(f32 *)((s8 *)((u8 *)this) + 0x308) = -scale * diff.x;
    this->velocity.z = -scale * diff.z;
    }
}

#pragma push
#pragma fp_contract on
#define TEST30(o, m) ((TObjCollidable *)o)->test_actor_flags(m)
#define FIELD1C(o) ((TObjBase *)(o))->get_entity_id()
#define STATE2(o) (((TObjChara *)(o))->obj_isState2_324())
#define STATE3(o) ((TObjChara *)o)->obj_isState3_324()
#define LOCAL(o) TObjPlayer::is_locally_controlled(o)
#define VECCOPY(d, s) ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(d, s)
#define HIT(o, p) (((TObjChara *)(o))->try_apply_damage(p, 0))
#define DAMAGE(o, p, d) (((TObjChara *)(o))->try_apply_damage(p, d))
#define SWITCH_ATTACK(o, p) ((TObjChara *)(o))->trigger_switch_attack(p)
#define SUB_HP(o, d) ((s32 (*)(Actor_8001311C *, s32))TObjectV8047c128_subtract_hp)(o, d)
f32 TObjChara::receive_direct_attack(void *att, DirectAttackPayload payload, void *coll, s32 tech, s32 arg5) {
    Info_8001311C info;
    Vec pos;
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
                    set_actor_flags(0x800);
                }
            }
            set_actor_flags(0x200);
            this->check_heavy_damage_flag(dmg);
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
                    set_actor_flags(0x800);
                }
            }
            set_actor_flags(0x200);
            this->check_heavy_damage_flag(dmg);
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
                    set_actor_flags(0x800);
                }
            }
            set_actor_flags(0x200);
            ((Actor_8001311C *)this)->f2dc |= 4;
            if (LOCAL(((Actor_8001311C *)this)) != 0 || ((TObjPlayer *)((Actor_8001311C *)att))->is_local_player() != 0) {
                f = info.power - (2.5e+02f);
                if (f < 0.0f) {
                    f = 0.0f;
                }
                if (((s32 (*)(Actor_8001311C *, Actor_8001311C *, Actor_8001311C *, f32))calc_freeze_chance)(((Actor_8001311C *)this), ((Actor_8001311C *)att), ((Actor_8001311C *)this), (0.025f) * ((0.025f) * f + (5.0f))) != 0) {
                    this->apply_movement_ailment((saddr)((Coll_8001311C *)coll));
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
                    set_actor_flags(0x800);
                }
            }
            set_actor_flags(0x200);
            this->check_heavy_damage_flag(dmg);
            ((Actor_8001311C *)this)->f2dc |= 4;
            if ((LOCAL(((Actor_8001311C *)this)) != 0 || ((TObjPlayer *)((Actor_8001311C *)att))->is_local_player() != 0) &&
                ((s32 (*)(Actor_8001311C *, Actor_8001311C *, Actor_8001311C *, f32))calc_shock_chance)(((Actor_8001311C *)this), ((Actor_8001311C *)att), ((Actor_8001311C *)this), info.power) != 0) {
                this->apply_shock_status();
            }
            ((void (*)(Actor_8001311C *, Vec *))activate_switch_attacks__10TObjPlayerFii)(((Actor_8001311C *)this), &pos);
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
                    set_actor_flags(0x800);
                }
            }
            set_actor_flags(0x200);
            this->check_heavy_damage_flag(dmg);
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
                if (immune == 0 && this->random_ratio() < dmg) {
                    ((TObjPlayer *)((Actor_8001311C *)this))->set_hp_clamped(0);
                    set_actor_flags(0xA00);
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
        ((void (*)(Actor_8001311C *, Vec *, s32, s32))draw_hp_label)(((Actor_8001311C *)this), &pos, 0, (s32)heal);
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
            this->sync_enemy_state(info.type);
        }
        break;
    case 10:
        dmg = (0.0f);
        if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
            this->trigger_switch_attack();
        }
        ((Actor_8001311C *)this)->m50(info);
        if (((Actor_8001311C *)this)->f1c <= 0x1000 && ((Actor_8001311C *)this)->f1c > 0x4000) {
            this->sync_enemy_state(info.type);
        }
        break;
    case 11:
        dmg = (0.0f);
        if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
            this->enemy_spawn_jellen_effect();
        }
        ((Actor_8001311C *)this)->m49(info);
        if (((Actor_8001311C *)this)->f1c <= 0x1000 && ((Actor_8001311C *)this)->f1c > 0x4000) {
            this->sync_enemy_state(info.type);
        }
        break;
    case 12:
        dmg = (0.0f);
        if (TEST30(((Actor_8001311C *)this), 0x02000000) == 0) {
            this->enemy_spawn_zalure_effect();
        }
        ((Actor_8001311C *)this)->m50(info);
        if (((Actor_8001311C *)this)->f1c <= 0x1000 && ((Actor_8001311C *)this)->f1c > 0x4000) {
            this->sync_enemy_state(info.type);
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
            this->check_heavy_damage_flag(dmg);
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
                    set_actor_flags(0x800);
                }
            }
            set_actor_flags(0x200);
            this->check_heavy_damage_flag(dmg);
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
        this->sync_enemy_state(0);
    }
    if (LOCAL(((Actor_8001311C *)this)) != 0) {
        TObjPlayer::calc_photon_blast_charge(((Actor_8001311C *)this), (s32)((2e+01f) * dmg));
        ((Actor_8001311C *)this)->m73();
    }
    record_local_damage_if_enabled(((Actor_8001311C *)this), ((Actor_8001311C *)att), (s32)dmg);
    empty_post_damage_hook(((Actor_8001311C *)this), ((Actor_8001311C *)att));
    return dmg;
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
#define VECCOPY_W24(d, s) ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)((d), (s))
#define FIELD1C_W24(p) ((TObjBase *)(p))->get_entity_id()
#define TESTF30_W24(p, m) ((TObjCollidable *)((p)))->test_actor_flags((m))
#define ISSTATE2_W24(p) (((TObjChara *)(p))->obj_isState2_324())
#define ISLOCAL_W24(p) TObjPlayer::is_locally_controlled(p)
#define MISS_W24(s, v) (((TObjChara *)(s))->show_miss_popup((const float *)(v)))
#define APPLYDMG_W24(s, v, d) (((TObjChara *)(s))->try_apply_damage((const Vec *)(v), (d)))
#define DISPATCH_W24(a, s, v) dispatch_weapon_special_effect((a), (s), (v), 1)
#define SUBHP_W24(p, v) ((s32 (*)(void *, s32))TObjectV8047c128_subtract_hp)((p), (v))
#define ADDHP_W24(p, v) ((s32 (*)(void *, s32))add_actor_hp)((p), (v))
#define SUBTP_W24(p, v) ((TObjChara *)p)->subtract_actor_tp((s32)((v)))
#define ADDTP_W24(p, v) ((s32 (*)(void *, s32))add_actor_tp)((p), (v))
#define HPLABEL_W24(p, v, k, n) ((void (*)(void *, void *, s32, s32))draw_hp_label)((p), (v), (k), (n))
#define TPFONT_W24(p, v, k, n) ((void (*)(void *, void *, s32, s32))show_tp_font)((p), (v), (k), (n))
#define BOSS4_W24(p) (((TObjChara *)(p))->random_ratio())
#define CLEARCOLL_W24() if (coll != NULL) { coll->flags &= ~0x04000000; }
f32 TObjChara::receive_weapon_special_attack(void *attacker, void *collision) {
    Rec_80011824 rec;
    Vec pos;
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
    if (game_difficulty_selection == 3 && self->f2D4 < 0x1000 && ((TObjChara *)att)->obj_testFlag_2E4(4) != 0 &&
        kind != 11 && kind != 9 && kind != 10) {
        power += 30;
    }
    dmg = (0.0f);
    rec.kind = 0;
    rec.power = dmg;
    if (self->f2D4 < 0x1000) {
        TItem *item = TObjPlayer::get_equipped_weapon(att);
        if (item == NULL) {
            mul = (1.0f);
        } else {
            switch (item->get_item_group()) {
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
        dmg = (0.01f) * (f32)(power * ((TObjChara *)self)->get_actor_hp());
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
                ((TObjChara *)att)->send_update_entity_stat(self->f2D4, 3, (s32)dmg);
                ((TObjChara *)self)->send_update_entity_stat(self->f2D4, 0, (s32)dmg);
                self->m20(att, (0.6f));
            } else if (ISSTATE2_W24(self) == 0 || FIELD1C_W24(att) >= 0x1000) {
                if (ISLOCAL_W24(att) != 0) {
                    ((TObjChara *)att)->send_update_entity_stat(self->f2D4, 3, (s32)dmg);
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
                ((TObjChara *)att)->send_update_entity_stat(self->f2D4, 3, (s32)dmg);
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
            set_actor_flags(0xA00);
            empty_post_damage_hook(self, att);
        } else {
            set_actor_flags(0x200);
        }
        if (TESTF30_W24(self, 0x02000000) == 0) {
            create_hit_effect__10TObjPlayerFPv(&pos);
        }
        break;
    case 2:
        if (((TObjChara *)att)->obj_testFlag_2E4(4) != 0) {
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
                    ((TObjChara *)att)->send_update_entity_stat(self->f2D4, 4, (s32)dmg);
                    ((TObjChara *)self)->send_update_entity_stat(self->f2D4, 1, (s32)dmg);
                    self->m20(att, (0.6f));
                } else if (ISSTATE2_W24(self) == 0 || FIELD1C_W24(att) >= 0x1000) {
                    if (ISLOCAL_W24(att) != 0) {
                        ((TObjChara *)att)->send_update_entity_stat(self->f2D4, 4, (s32)dmg);
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
                    ((TObjChara *)att)->send_update_entity_stat(self->f2D4, 4, (s32)dmg);
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
        set_actor_flags(0x200);
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
            set_actor_flags(0x200);
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
                    ((TObjChara *)att)->send_update_entity_stat(self->f2D4, 2, (s32)cost);
                    self->m20(att, (3.0f));
                } else if (ISSTATE2_W24(self) == 0 || FIELD1C_W24(att) >= 0x1000) {
                    try_spend_actor_meseta(reinterpret_cast<TObjChara *>(att), (s32)cost);
                    ((void (*)(void *, void *, s32, s32))show_meseta_label)(att, &att->pos, 0, (s32)-cost);
                    self->m20(att, (3.0f));
                }
            } else {
                if (immune == 0) {
                    try_spend_actor_meseta(reinterpret_cast<TObjChara *>(att), (s32)cost);
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
                    ((TObjChara *)att)->send_update_entity_stat(self->f2D4, 1, (s32)amt);
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
        amt = (0.25f) * (f32)((TObjChara *)att)->get_actor_hp();
        if ((1.0f) < (f32)((TObjChara *)att)->get_actor_hp()) {
            if (TObjPlayer::get_player_count() != 0) {
                if (ISLOCAL_W24(self) != 0 && ISSTATE2_W24(att) != 0) {
                    ((TObjChara *)att)->send_update_entity_stat(self->f2D4, 0, (s32)amt);
                    self->m20(att, (3.0f));
                } else if (ISSTATE2_W24(self) == 0 || FIELD1C_W24(att) >= 0x1000) {
                    SUBHP_W24(att, (s32)amt);
                    self->m20(att, (3.0f));
                }
            } else {
                ((s32 (*)(void *, s32))damage_hp__10TObjPlayerFii)(att, (s32)amt);
                if (ISLOCAL_W24(att) != 0) {
                    u16 id = FIELD1C_W24(att);
                    send_6x2F_change_player_hp(id, id, ((TObjChara *)att)->get_actor_hp());
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
                set_actor_flags(0x800);
                empty_post_damage_hook(self, att);
            }
        }
        set_actor_flags(0x200);
        ((TObjChara *)self)->check_heavy_damage_flag(dmg);
        self->f2DC |= 4;
        if (TESTF30_W24(self, 0x02000000) == 0) {
            create_hit_effect__10TObjPlayerFPv(&pos);
            ((TObjChara *)self)->trigger_switch_attack((const Vec *)&pos);
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
                set_actor_flags(0x800);
                empty_post_damage_hook(self, att);
            }
        }
        set_actor_flags(0x200);
        ((TObjChara *)self)->check_heavy_damage_flag(dmg);
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
                ((TObjChara *)self)->get_actor_hp();
                ((TObjPlayer *)self)->set_hp_clamped(0);
                set_actor_flags(0xA00);
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
                         (f32)((TObjChara *)self)->get_actor_hp());
            if (dmg < (1.0f)) {
                dmg = (1.0f);
            }
            if (immune == 0) {
                SUBHP_W24(self, (s32)dmg);
                if (((TObjChara *)self)->clamp_hp() <= 0) {
                    set_actor_flags(0x800);
                    empty_post_damage_hook(self, att);
                }
            }
            set_actor_flags(0x200);
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

#pragma pop
#pragma pop
#undef TEST30
#undef FIELD1C
#undef STATE2
#undef STATE3
#undef LOCAL
#undef VECCOPY
#undef HIT
#undef DAMAGE
#undef SWITCH_ATTACK
#undef SUB_HP
#undef VECCOPY_W24
#undef FIELD1C_W24
#undef TESTF30_W24
#undef ISSTATE2_W24
#undef ISLOCAL_W24
#undef MISS_W24
#undef APPLYDMG_W24
#undef DISPATCH_W24
#undef SUBHP_W24
#undef ADDHP_W24
#undef SUBTP_W24
#undef ADDTP_W24
#undef HPLABEL_W24
#undef TPFONT_W24
#undef BOSS4_W24
#undef CLEARCOLL_W24
void apply_actor_gravity(TObjEnemy *enemy, s32 *arg1, f32 hover_height) {
    Vec position;
    f32 y;
    s32 temp_r31;
    ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&position.x, (u8 *)enemy + 0x38);
    temp_r31 = project_actor_to_ground(enemy, &position, &enemy->ground_normal);
    if (arg1 != NULL) {
        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(arg1, &position.x);
    }
    if (temp_r31 != 0) {
        ((TObjEnemy *)enemy)->velocity.y += (-0.10888889f);
        *(f32 *)((s8 *)enemy + 0x3C) = (f32) (*(f32 *)((s8 *)enemy + 0x3C) + ((TObjEnemy *)enemy)->velocity.y);
        y = position.y + hover_height;
        position.y = y;
        if (*(f32 *)((s8 *)enemy + 0x3C) <= y) {
            *(f32 *)((s8 *)enemy + 0x3C) = y;
            ((TObjEnemy *)enemy)->velocity.y = 0.0f;
            enemy->actorFlags = (s32) (enemy->actorFlags | 0x800000);
            return;
        }
        enemy->actorFlags = (s32) (enemy->actorFlags & 0xFF7FFFFF);
        return;
    }
    enemy->actorFlags = (s32) (enemy->actorFlags & 0xFF7FFFFF);
}

s32 TObjChara::is_actor_cadence_frame(s32 x) {
    s32 g = actor_frame_tick % x;
    if ((((O_80011704 *)this)->f1c % x) == g) {
        return 1;
    }
    return 0;
}
extern "C" {
u16 find_nearest_visible_player(TObjChara *searcher, Vec *direction, f32 range) {
    f32 best = range * range;
    u16 result = 0xFFFF;
    Vec diff = nearest_player_zero_vec;
    f32 dist;
    Player_800115C4 *player;
    s32 i;
    for (i = 0; i < registered_player_count; i++) {
        player = ((Player_800115C4 * (*)(s32))get_player_data__10TObjPlayerFi)(i);
        if (player != NULL && player->id < 0x1000 && !(player->flags & 0x02000800)) {
            if (((TObjPlayer *)player)->get_floor() == get_current_floor()) {
                ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&diff, &player->pos);
                ((s32 (*)(void *, void *))subtract_vector)(&diff, &searcher->body_center);
                dist = (diff.x * diff.x) + (diff.z * diff.z);
                if (dist < best && ((s32 (*)(void *, void *))check_path_obstructed)(searcher, &player->pos) == 0) {
                    best = dist;
                    result = player->id;
                    if (direction != NULL) {
                        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(direction, &diff);
                    }
                }
            }
        }
    }
    return result;
}

}
u16 find_nearest_hittable_enemy(TObjBase *searcher, Vec *direction, f32 range) {
    Vec pos;
    f32 best;
    f32 dist;
    u16 result;
    s32 i;
    ObjFlags *p;
    best = range * range;
    result = 0xFFFF;
    for (i = registered_player_count; i < registered_player_count + registered_enemy_count; i++) {
        p = ((ObjFlags * (*)(s32))get_player_data__10TObjPlayerFi)(i);
        if (p == NULL) {
            break;
        }
        if (obj_is_hit_receivable(reinterpret_cast<TObjCollidable *>(p)) != 0) {
            u16 id = reinterpret_cast<TObjBase *>(p)->get_entity_id();
            if (id >= 0x1000 && id < 0x4000 && !(p->flags_30 & 0x02000800)) {
                dist = ((f32 (*)(TObjBase *, ObjFlags *, void *))calc_xz_distance_sq)(searcher, p, &pos);
                if (dist < best) {
                    best = dist;
                    result = p->field_1c;
                    if (direction != NULL) {
                        ((s32 (*)(void *, void *))VecCopy__FP3VecPC3Vec)(direction, &pos);
                    }
                }
            }
        }
    }
    return result;
}
extern "C" {

s32 damage_hp__10TObjPlayerFii(saddr arg0, saddr arg1) {
    if (((TObjChara *)arg0)->obj_isState2_324() != 0) {
        return 0;
    }
    return ((int (*)(void*, void*))TObjectV8047c128_subtract_hp)((void*)arg0, (void*)arg1);
}

s32 TObjectV8047c128_subtract_hp(u8 *owner, s16 arg1) {
  if (arg1 < 0)
  {
    return 0;
  }
  *((s16 *) (((s8 *) owner) + 0x32C)) = (s16) ((*((s16 *) (((s8 *) owner) + 0x32C))) - arg1);
  if ((*((s16 *) (((s8 *) owner) + 0x32C))) < 0)
  {
    *((s16 *) (((s8 *) owner) + 0x32C)) = 0;
    return 0;
  }
  return 1;
}
#pragma push
#pragma scheduling off
s32 add_actor_hp(TObjChara *actor, s16 amount) {
    if (amount < 0) {
        return 0;
    }
    actor->hp = static_cast<s16>(actor->hp + amount);
    if (actor->hp > actor->hpmax) {
        actor->hp = actor->hpmax;
        return 0;
    }
    return 1;
}
#pragma pop
void TObjPlayer::set_hp_clamped(s16 arg1) {
    u8 *arg0 = (u8 *)this;
    this->hp = arg1;
    clamp_hp_value((s16 *)(arg0 + 0x32C));
}

s32 TObjPlayer::clamp_hp_value(s16 *arg1) {
    s16 hpmax;
    s16 temp_r5;
    temp_r5 = *arg1;
    if (temp_r5 < 0) {
        *arg1 = 0;
        return 0;
    }
    hpmax = this->hpmax;
    if (temp_r5 > hpmax) {
        *arg1 = hpmax;
        return 0;
    }
    return 1;
}

s32 add_actor_hp_bonus(TObjChara *actor, s32 amount) {
    actor->hp_bonus = static_cast<s16>(static_cast<u32>(actor->hp_bonus) + static_cast<u32>(amount));
    if (actor->hp_bonus < 0) {
        actor->hp_bonus = 0;
        return 0;
    }
    return 1;
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

s32 TObjChara::check_can_act(s32 dmg) {
    if (obj_isState2_324() != 0) {
        return 0;
    }
    return subtract_actor_tp(dmg);
}

s32 TObjChara::subtract_actor_tp(s32 amount) {
    tp = static_cast<s16>(static_cast<u32>(tp) - static_cast<u32>(amount));
    if (tp < 0) {
        tp = 0;
        return 0;
    }
    return 1;
}

s32 add_actor_tp(TObjChara *actor, s32 amount) {
    actor->tp = static_cast<s16>(static_cast<u32>(actor->tp) + static_cast<u32>(amount));
    if (actor->tp > actor->tpmax) {
        actor->tp = actor->tpmax;
        return 0;
    }
    return 1;
}

s32 add_actor_tp_bonus(TObjChara *actor, s32 amount) {
    actor->tp_bonus = static_cast<s16>(static_cast<u32>(actor->tp_bonus) + static_cast<u32>(amount));
    if (actor->tp_bonus < 0) {
        actor->tp_bonus = 0;
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

s32 TObjChara::add_actor_exp(s32 arg1) {
  player_stats *stat_block;
  int new_var;
  player_stats *temp_r6;
  temp_r6 = this->stat_block;
  temp_r6->exp = temp_r6->exp + arg1;
  stat_block = this->stat_block;
  new_var = 99999999;
  if (new_var < (s32)stat_block->exp)
  {
    stat_block->exp = new_var;
    return 0;
  }
  return 1;
}

s32 TObjChara::consume_timer_field(s32 amount) {
    this->stat_block->exp -= amount;
    if (this->stat_block->exp < 0) {
        this->stat_block->exp = 0;
        return 0;
    }
    return 1;
}

s32 TObjPlayer::add_capped_counter_999(s32 arg1) {
    this->m_11a = (s16) (this->m_11a + arg1);
    if ((s16) this->m_11a > 0x3E7) {
        this->m_11a = 0x3E7;
        return 0;
    }
    return 1;
}

s32 TObjChara::get_actor_level_index() { return this->stat_block->level; }

s32 TObjPlayer::add_meseta(s32 amount) {
  TObjPlayer* self = this;
  s32 limit = 999999;
  int maximum;
  self->stat_block->meseta += amount;
  maximum = limit;
  if (maximum < (s32)self->stat_block->meseta)
  {
    self->stat_block->meseta = maximum;
    return 0;
  }
  return 1;
}

s32 try_spend_actor_meseta(TObjChara *actor, s32 amount) {
    player_stats *stats = actor->stat_block;
    s32 held = stats->meseta;
    if (held < amount) {
        return 0;
    }
    stats->meseta = held - amount;
    return 1;
}

void TObjEnemy::draw_ground_shadow(const Vec *scale, s32 forceDraw) {
    s32 rotationX;
    s32 rotationZ;

    (void)&lbl_805D7D3C;
    push_matrix();
    direction_to_rotation_xz((u8 *)&ground_normal, &rotationX, &rotationZ);
    translate_matrix(0, position.x, 0.3f + position.y, position.z);
    rotate_matrix_z(0, rotationZ);
    rotate_matrix_x(0, rotationX);
    rotate_matrix_y(0, rotation_y);
    rotate_matrix_x(0, -0x4000);
    if (scale != NULL) {
        scale_matrix(0, scale->x, scale->z, 1.0f);
    }
    draw_blob_shadow(forceDraw);
    pop_matrix();
}

f32 TObjChara::random_ratio() {
    if (get_main_phase() == 0xE) {
        return (3.0517578e-05f) * (f32) rand();
    }
    return calc_random_ratio__10TObjPlayerFv(&rng);
}

void TObjChara::refresh_target() {  }

void attach_mine_trap__10TObjPlayerFiUi(saddr object, u32 arg1) {
    if (arg1 != 0U) {
        ((TObjChara *)object)->record_attack_source(((TObjBase *)(arg1))->get_entity_id());
    }
}

void TObjChara::record_attack_source(u16 id) {
    if (id != 0xFFFF) {
        attacker_id = id;
        if (attacker_id < 0x1000 && is_entity_locally_controlled(attacker_id) != 0) {
            if (((s32 (*)(void))is_split_screen)() == 0) {
                local_attacker_id = attacker_id;
            } else {
                add_id_to_slots__10TObjPlayerFiUs(this, id);
            }
        }
    }
}

u16 TObjChara::get_local_attacker_id() { return this->local_attacker_id; }

void assign_slots_from_list(void *arg0, saddr arg1) {
    s32 i;

    if (arg1 != 0) {
        if (((s32 (*)(void))is_split_screen)() != 0) {
            i = 0;
            do {
                add_id_to_slots__10TObjPlayerFiUs(static_cast<TObjChara *>(arg0), obj_getArrU16_FC(reinterpret_cast<TObjChara *>(arg1), i));
                i += 1;
            } while (i != 4);
            return;
        }
        if (*(u16 *)((s8 *)arg0 + 0x2D6) == 0xFFFF) {
            *(u16 *)((s8 *)arg0 + 0x2D6) = ((TObjChara *)arg1)->get_local_attacker_id();
        }
    }
}
}

void TObjChara::gain_photon_blast_charge(f32) {  }

void TObjChara::spend_photon_blast_charge(f32) {  }

void TObjChara::gain_photon_blast_chain_charge(f32) {  }

void TObjChara::vfunc_78(saddr) {  }

#pragma push
#pragma opt_pointer_analysis on
void record_local_damage_if_enabled(void *mine_trap, void *att, saddr damage) {
  if ((((((TLobby *)(&lobby_rule_settings.value))->get_rule_field_0() == 1) && (TObjPlayer::is_locally_controlled(mine_trap) != 0)) && (damage > 0)) && (att != NULL))
  {
    record_damage_stats__10TOMineTrapFUiUis((void *) mine_trap, (void *) att, (void *) damage);
  }
}

#pragma pop
void empty_post_damage_hook(void *defender, void *attacker) {  }

void TObjChara::send_update_entity_stat(u16 target, s32 which, s32 amount) {
    Pkt_80010DE8 pkt;
    ((TObjPlayer *)(&pkt))->init_packet_9a();
    pkt.f2 = ((Obj_80010DE8 *)this)->f1c;
    pkt.f4 = target;
    pkt.f6 = which;
    pkt.f7 = amount;
    ((TObjPlayer *)(&pkt))->send_head();
}

void handle_6x9A_update_entity_stat(Pkt_80010C54 *pkt) {
    s16 v;
    saddr player;
    s32 amount;
    if (pkt == NULL) {
        return;
    }
    ((TObjPlayer *)pkt)->bswap_head16();
    if (pkt->client >= 0x1000U) {
        return;
    }
    player = reinterpret_cast<saddr>(get_player_by_client_id(pkt->client));
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
        try_spend_actor_meseta(reinterpret_cast<TObjChara *>(player), amount);
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

s32 is_entity_locally_controlled(s32 id) {
    void *p;
    if ((u16)id == 0xFFFF || (u16)id >= 0x1000) {
        return 0;
    }
    p = find_entity_by_id(id);
    if (p == 0) {
        return 0;
    }
    return TObjPlayer::is_locally_controlled(p);
}

void TObjChara::apply_switch_attack() {
    TParticleCtrl *particle_effect_with_flags;

    particle_effect_with_flags = spawn_particle_effect_with_flags(&this->body_center, 0x1FD, 0x50);
    if (particle_effect_with_flags != 0) {
        particle_effect_with_flags->set_owner_id(((TObjBase *)this)->get_entity_id());
    }
}

void TObjChara::enemy_spawn_jellen_effect() {
    Stack_80010B44 stack;
    saddr oneshot_particle_emitter;
    stack.spC = 0;
    stack.sp8 = 0;
    stack.sp10 = -0x8000;
    oneshot_particle_emitter = (saddr)create_oneshot_particle_emitter(&this->body_center, &stack.sp8, 0x1FD, 0x50);
    if (oneshot_particle_emitter != 0) {
        ((TParticleCtrl *)oneshot_particle_emitter)->set_owner_id(((TObjBase *)this)->get_entity_id());
    }
}

void TObjChara::trigger_switch_attack() {
    TParticleCtrl *particle_effect_with_flags;

    particle_effect_with_flags = spawn_particle_effect_with_flags(&this->body_center, 0x1FE, 0x50);
    if (particle_effect_with_flags != 0) {
        particle_effect_with_flags->set_owner_id(((TObjBase *)this)->get_entity_id());
    }
}

void TObjChara::enemy_spawn_zalure_effect() {
    Stack_80010A84 stack;
    saddr oneshot_particle_emitter;
    stack.spC = 0;
    stack.sp8 = 0;
    stack.sp10 = -0x8000;
    oneshot_particle_emitter = (saddr)create_oneshot_particle_emitter(&this->body_center, &stack.sp8, 0x1FE, 0x50);
    if (oneshot_particle_emitter != 0) {
        ((TParticleCtrl *)oneshot_particle_emitter)->set_owner_id(((TObjBase *)this)->get_entity_id());
    }
}

void TObjChara::recalc_stats() {}

s32 TObjChara::sync_enemy_state(s32) { return 0; }

void TObjPlayer::clear_s16_arrays(void *p) {
    for (s32 i = 0; i < 4; i++) {
        obj_clearArrS16_FC(static_cast<TObjChara *>(p), i);
    }
}

void add_id_to_slots__10TObjPlayerFiUs(TObjChara *actor, u16 id) {
    s32 var_r30;

    var_r30 = 0;
loop_1:
    if (static_cast<u16>(id) != static_cast<u16>(obj_getArrU16_FC(actor, var_r30))) {
        if (static_cast<u16>(obj_getArrU16_FC(actor, var_r30)) == 0xFFFF) {
            obj_setArrS16_FC(actor, var_r30, id);
            return;
        }
        var_r30 += 1;
        if (var_r30 >= 4) {

        } else {
            goto loop_1;
        }
    }
}

void TObjChara::apply_anti_technique(s32 arg1) {
    if (arg1 >= 0) {
        switch (this->get_status_effect_type(0)) {
        case 0xF:
            this->actorFlags &= ~3;
            this->status_effects[0].clear();
        }
    }
    if (arg1 >= 1) {
        switch (this->get_status_effect_type(1)) {
        case 3:
            adjust_evp((int)((f32)this->get_base_evp() * -this->get_status_effect_amount(1)));
            this->actorFlags &= ~0x3C;
            this->status_effects[1].clear();
        }
    }
    if (arg1 >= 2) {
        switch (this->get_status_effect_type(0)) {
        case 0x10:
            adjust_evp((int)((f32)this->get_base_evp() * -this->get_status_effect_amount(0)));
            this->actorFlags &= ~3;
            this->status_effects[0].clear();
        }
    }
    if (arg1 >= 3) {
        switch (this->get_status_effect_type(1)) {
        case 0x12:
            this->actorFlags &= ~0x3C;
            this->status_effects[1].clear();
        }
    }
    if (arg1 >= 4) {
        switch (this->get_status_effect_type(1)) {
        case 0x11:
            this->actorFlags &= ~0x3C;
            this->status_effects[1].clear();
        }
    }
    if (arg1 >= 5) {
        switch (this->get_status_effect_type(2)) {
        case 0xB:
            this->adjust_atp((int)((f32)this->get_base_atp() * -this->get_status_effect_amount(2)));
            this->adjust_atp_range((int)((f32)this->get_base_atp_range() * -this->get_status_effect_amount(2)));
            this->status_effects[2].clear();
        }
        switch (this->get_status_effect_type(3)) {
        case 0xC:
            this->adjust_dfp((int)((f32)this->get_base_dfp() * -this->get_status_effect_amount(3)));
            this->status_effects[3].clear();
        }
    }
    if (arg1 >= 6) {
        switch (this->get_status_effect_type(1)) {
        case 2:
            adjust_evp((int)((f32)this->get_base_evp() * -this->get_status_effect_amount(1)));
            this->actorFlags &= ~0x3C;
            this->status_effects[1].clear();
        }
    }
    *(u32 *)(((u8 *)this) + 0x330) = this->actorFlags & 0x3F;
    clear_actor_flags((u32)0x4000);
    this->status_effects[4].clear();
}

s16 TObjChara::clamp_hp() {
    s16 temp_r0;
    s16 hp;

    hp = (this->hp);
    if (hp < 0) {
        (this->hp) = 0;
    } else {
        temp_r0 = (this->hpmax);
        if (temp_r0 < hp) {
            (this->hp) = temp_r0;
        }
    }
    return (this->hp);
}

s16 TObjPlayer::clamp_tp() {
    s16 temp_r0;
    s16 temp_r4;

    temp_r4 = this->tp;
    if (temp_r4 < 0) {
        this->tp = 0;
    } else {
        temp_r0 = this->tpmax;
        if (temp_r0 < temp_r4) {
            this->tp = temp_r0;
        }
    }
    return this->tp;
}

void TObjPlayer::apply_velocity() {
    this->position.x = (f32) (this->position.x + this->velocity.x);
    this->position.y = (f32) (this->position.y + this->velocity.y);
    this->position.z = (f32) (this->position.z + this->velocity.z);
}

void clear_velocity(u8 *arg0) {
    *(f32 *)((s8 *)arg0 + 0x310) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x30C) = 0.0f;
    *(f32 *)((s8 *)arg0 + 0x308) = 0.0f;
}

s32 calc_shock_chance(TObjPlayer *actor, TObjPlayer *arg1, TObjPlayer *arg2) {
    f32 var_f31;

    if ((arg1->get_entity_id() >= 0x1000U) && (arg2->get_entity_id() < 0x1000U)) {
        var_f31 = 0.75f - ((f32) ((TObjPlayer *)actor)->get_item_index() / 100.0f);
        if (var_f31 < 0.0f) {
            var_f31 = 0.0f;
        }
    } else if ((s32) game_difficulty_selection == 3) {
        var_f31 = (0.025f);
    } else {
        var_f31 = (0.06666667f);
    }
    return ((TObjChara *)actor)->random_ratio() < var_f31;
}

s32 calc_freeze_chance(TObjPlayer *actor, TObjPlayer *arg1, TObjPlayer *arg2, f32 farg0) {
    f32 var_f31;

    var_f31 = farg0;
    if ((arg1->get_entity_id() >= 0x1000U) && (arg1->get_entity_id() < 0x4000U) && (arg2->get_entity_id() < 0x1000U)) {
        var_f31 = 0.75f - ((f32) ((TObjPlayer *)actor)->get_class_id() / 100.0f);
        if (var_f31 < 0.0f) {
            var_f31 = 0.0f;
        }
    } else if (((s32) game_difficulty_selection == 3) && ((0.2f) < var_f31)) {
        var_f31 = (0.2f);
    } else if ((0.4f) < var_f31) {
        var_f31 = (0.4f);
    }
    return ((TObjChara *)actor)->random_ratio() < var_f31;
}

void TObjChara::spawn_poison_effect(s32 play_sound) {
    TParticleCtrl *effect;
    if (this->test_actor_flags(0x02000000) == 0) {
        effect = spawn_particle_effect_with_flags(&this->body_center, 0x25, 0x50);
        if (effect != 0) {
            effect->set_owner_id(((TObjBase *)this)->get_entity_id());
        }
        if (play_sound != 0) {
            play_sound_effect(0xCD0B, &this->position, 0, 0);
        }
    }
}

void TObjChara::spawn_paralysis_feedback_effect(s32 play_sound) {
    TParticleCtrl *effect;
    if (this->test_actor_flags(0x02000000) == 0) {
        effect = spawn_particle_effect_with_flags(&this->body_center, 0x26, 0x50);
        if (effect != 0) {
            effect->set_owner_id(((TObjBase *)this)->get_entity_id());
        }
        if (play_sound != 0) {
            play_sound_effect(0xB20C, &this->position, 0, 0);
        }
    }
}

void TObjChara::spawn_slow_effect(s32 play_sound) {
    TParticleCtrl *effect;
    if (this->test_actor_flags(0x02000000) == 0) {
        effect = spawn_particle_effect_with_flags(&this->body_center, 0x27, 0x50);
        if (effect != 0) {
            effect->set_owner_id(((TObjBase *)this)->get_entity_id());
        }
        if (play_sound != 0) {
            play_sound_effect(0xB20D, &this->position, 0, 0);
        }
    }
}

void TObjChara::spawn_confusion_feedback_effect(s32 play_sound) {
    TParticleCtrl *effect;
    if (this->test_actor_flags(0x02000000) == 0) {
        effect = spawn_particle_effect_with_flags(&this->body_center, 0x24, 0x50);
        if (effect != 0) {
            effect->set_owner_id(((TObjBase *)this)->get_entity_id());
        }
        if (play_sound != 0) {
            play_sound_effect(0xB20E, &this->position, 0, 0);
        }
    }
}
extern "C" {
void TObjChara::play_shock_feedback(s32 play_sound) {
    TParticleCtrl *effect;
    if (this->test_actor_flags(0x02000000) == 0) {
        effect = spawn_particle_effect_with_flags(&this->body_center, 0x21, 0x50);
        if (effect != 0) {
            effect->set_owner_id(((TObjBase *)this)->get_entity_id());
        }
        if (play_sound != 0) {
            play_sound_effect(0xB210, &this->position, 0, 0);
        }
    }
}

void TObjChara::spawn_freeze_shell_effect(u32 arg1, s32 arg2) {
    u32 temp_r4;
    if (((s32)this->test_actor_flags(0x02000000)) == 0) {
        if (arg1 != 0U) {
            create__10TObjPlayerFUiii((uaddr) this, (s32) arg1, 0x96);
        } else {
            temp_r4 = *(u32 *)&this->bodies;
            if (temp_r4 != 0U) {
                create__10TObjPlayerFUiii((uaddr) this, (s32) temp_r4, 0x96);
            }
        }
        if (arg2 != 0) {
            play_sound_effect(0xB20F, &position, 0, 0);
        }
    }
}

void activate_switch_attacks__10TObjPlayerFii(saddr arg0, saddr pos) {
    if (((TObjCollidable *)arg0)->test_actor_flags(0x02000000) == 0) {
        spawn_particle_effect_with_flags((const Vec *)pos, 0xB9, 0x40);
        spawn_particle_effect_with_flags((const Vec *)pos, 0xBA, 0x40);
        ((TObjChara *)arg0)->trigger_switch_attack((const Vec *)pos);
    }
}

s32 TObjPlayer::is_local_player() {
    if (this->get_entity_id() < 0x1000U) {
        return TObjPlayer::is_locally_controlled(this);
    }
    return 0;
}

s32 TObjPlayer::get_attacker_id() { return (u16)(this->attacker_id); }

void TObjPlayer::set_attacker_id(u16 id) { this->attacker_id = id; }

int TObjChara::has_no_target() {
    if (this->target == NULL) {
        return TRUE;
    }
    return FALSE;
}

int TObjChara::test_flag_256() { return this->test_actor_flags(256); }

int TObjChara::test_flag30_512() { return this->test_actor_flags(512); }

int TObjChara::has_flag_0x800() { return this->test_actor_flags(2048); }

int TObjChara::test_flag_1000() { return this->test_actor_flags(4096); }

s32 TObjChara::check_heavy_damage_flag(f32 dmg) {
    if (((0.25f) * (f32) this->hpmax) < dmg) {
        this->actorFlags = (s32) (this->actorFlags | 0x400);
        return 1;
    }
    return 0;
}

}
