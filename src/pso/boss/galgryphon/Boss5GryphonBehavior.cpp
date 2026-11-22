#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/boss/galgryphon/Boss5GryphonBehavior.h"
#include "pso/boss/goldragon/TBoss8Dragon_80065C90.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/DragonAttackParams.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/system/vector.h"
#include "pso/enemy/EnemyStateEvent.h"
#include "pso/render/MaterialColorFade.h"
#include "types.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjChara.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/boss/galgryphon/TBoss5Gryphon.h"
#include "pso/boss/galgryphon/TBoss5GryphonSnarl.h"
#include "pso/boss/galgryphon/TBoss5GryphonDemo.h"
#include "pso/system/PadRumble.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/MatrixOps.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/render/render_util.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/hud/TRaderMapCore.h"
extern "C" void has_flag_0x800__9TObjCharaFv();
extern "C" void test_flag30_512__9TObjCharaFv();
extern "C" void test_flag_1000__9TObjCharaFv();
extern "C" void test_flag_256__9TObjCharaFv();


#include <stddef.h>
#include "pso/boss/galgryphon/TObjBoss5Ctrl.h"

#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/render/RenderFadeState.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/boss/galgryphon/Boss5GryphonActionScripts.h"
#include "pso/boss/goldragon/TBoss8Dragon_8005D700.h"
#include "pso/boss/galgryphon/TBoss5GryphonShockWave.h"
#include "pso/unk/text_80355A1C.h"
#include "pso/unk/TLobby.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/unk/TLobby_803255F8.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/byteswap.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/map/CsnGroundQuery.h"
#include "pso/unk/text_80086B64.h"
#include "pso/unk/text_80087278.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/camera/TCameraCtrl_8006A03C.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/galgryphon/TBoss5GryphonLightningEff.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/boss/galgryphon/TBoss5GryphonColli.h"


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


typedef struct Res_80063088 {
    u8 pad0[0xC];
    s32 fC;
    s32 f10;
} Res_80063088;

struct Obj_80063088 {
    u8 prefix[0x1C];
    u8 pad1C[0x60 - 0x1C];
    s32 angle;
    u8 pad64[0xB8 - 0x64];
    s16 fB8;
    u8 padBA[0x38C - 0xBA];
    u16 f38C;
    u8 pad38E[0x394 - 0x38E];
    f32 f394;
    f32 f398;
    f32 f39C;
    u8 pad3A0[0x444 - 0x3A0];
    Vec fxPos;
    u8 pad450[0x490 - 0x450];
    s32 f490;
    u8 pad494[0x4C4 - 0x494];
    u8 f4C4[0x5F0 - 0x4C4];
    Res_80063088 *res;
    u8 pad5F4[0x6DC - 0x5F4];
    s32 state;
    s32 f6E0;
    u8 pad6E4[0x724 - 0x6E4];
    void *fx;
};

struct Fx_8005E594 { u8 pad[0x14]; s32 f14; };

struct Hit2_8005E594 { u8 pad[4]; f32 y; };

struct Hit_8005E594 { u8 pad[4]; Hit2_8005E594 *p; };

struct Obj_8005E594 {
    u8 pad0[0x3E4];
    Vec cp[8];
    u8 pad444[0x5F0 - 0x444];
    Fx_8005E594 *fx;
    u8 pad5f4[0x734 - 0x5F4];
    void *parts[16];
};


struct Cfg_80064F50 { u8 pad[0x18]; s32 i18; s32 i1C; s32 i20; s32 i24; };


struct Hit2_80060020 { u8 pad[4]; f32 y; };

struct Hit_80060020 { u8 pad[4]; Hit2_80060020 *p; };

struct Cfg_80060020 { s16 h0; s16 h2; s32 f4; };

struct Fx_80060020 { u8 pad[4]; s32 f4; };

struct Dragon_80060020 {
    u8 prefix[0x1C];
    u8 pad1c[0x38 - 0x1C];
    Vec pos;
    u8 pad44[0x5C - 0x44];
    s32 f5C;
    s32 f60;
    s32 f64;
    u8 pad68[0xB8 - 0x68];
    s16 fB8;
    u8 padba[0x4BC - 0xBA];
    Cfg_80060020 *f4BC;
    u32 f4C0;
    u8 pad4c4[0x5F0 - 0x4C4];
    Fx_80060020 *f5F0;
    u8 f5F4[0x6DC - 0x5F4];
    s32 f6DC;
    s32 f6E0;
    u8 pad6e4[0x6E8 - 0x6E4];
    s32 f6E8;
    u8 pad6ec[0x6F4 - 0x6EC];
    f32 f6F4;
};

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off


extern "C" {
s32 get_flag_bit6__13TBoss5GryphonFv();
extern const f32 lbl_805D8DAC;
void run_task__13TBoss5GryphonFv(u8 *arg0);
s32 TBoss8Dragon__sub_800670E0(int, void *);
TParticleCtrl *spawn_continuous_particle_effect_with_flags(void *parent, s32 idx, s32 flags);
u8 *__ct__22TBoss5GryphonShockWaveFP7TObjectlPUcPUcls(u8 *arg0, u8 *arg1_parent, s32 arg2, u8 *arg3, u8 *arg4, s32 arg5, s16 arg6);
extern const f32 lbl_805D8D80;
extern const f32 lbl_805D8E5C;
extern const f32 lbl_805D8E9C;
extern const f32 lbl_805D8EA0;
extern const f32 lbl_805D8D90;
extern const f32 lbl_805D8D94;
f64 atan2_float(f32, f32);
s32 restore_player_cameras(void);
s32 activate_camera_mode(s32 arg0);
void set_scripted_camera_pose(void *, void *, void *);
void play_cue_stream_file(saddr name);
extern const f32 lbl_805D8DD4;
extern const f32 lbl_805D8E80;
extern const f32 lbl_805D8E84;
extern const f32 lbl_805D8E88;
extern const f32 lbl_805D8E10;
extern const f32 lbl_805D8EAC;
void update_body_colliders__13TBoss5GryphonFv(TBoss5Gryphon *self);
f32 calc_random_ratio__10TObjPlayerFv(void *);
s32 subtractive_rng_seed(void *, s32);
s32 fn_80351DA8(void *, void *, void *, int, int);
void copy_position__26TBoss5GryphonLightningWingFPv(void *, void *);
extern const f32 lbl_805D8D88;
extern const f32 lbl_805D8DBC;
extern const f32 lbl_805D8DC0;
extern const f32 lbl_805D8DC4;
extern const f32 lbl_805D8DC8;
extern const f32 lbl_805D8DCC;
extern const f32 lbl_805D8DD0;
extern const f32 lbl_805D8DD8;
extern const f32 lbl_805D8DDC;
extern const f32 lbl_805D8DE0;
extern const f32 lbl_805D8DE4;
extern const f32 lbl_805D8D98;
extern const f32 lbl_805D8DA0;
extern const f32 lbl_805D8DA4;
extern const f32 lbl_805D8DA8;
extern const f32 lbl_805D8DB0;
extern const f32 lbl_805D8DB4;
void choose_next_action__13TBoss5GryphonFPvPv(u8 *arg0, u32 *entry);
void apply_lightning_hit(s32 arg0, s32 arg1, f32 farg0);
void apply_snarl_hit(s32 arg0, s32 arg1, f32 inner, f32 scale);


struct Obj_8005E058 { u8 pad0[0x3C0]; Vec src[10]; u8 pad438[0xB0]; Vec dst[10]; };

struct Obj_8005E0C0 { u8 pad[0x34]; saddr f34; u8 pad38[0x24]; s32 f5c; s32 f60; s32 f64; u8 pad68[0x90]; saddr ff8; u8 pad_fc[0x3C0 - 0xFC]; u8 f3c0[0x100]; s32 f4c0; };


struct Obj_8005E4D4 { u8 pad[0x734]; void *parts[16]; };

struct Obj_8005E52C { u8 pad[0x734]; void *parts[16]; };


struct P_8005F740 { u8 pad[0x30]; };

struct O_8005FCE4 { u8 pad[0x4c0]; u32 flags; };

struct Shot_8005FBC4 { f32 v[3]; };

struct Obj_8005FBC4 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
    u8 pad64[0x474 - 0x64];
    Vec vel;
    s32 f480;
    u8 pad484[0x4c0 - 0x484];
    s32 flags;
    u8 pad4c4[0x4e4 - 0x4c4];
    s32 f4e4;
};

struct Tgt_80062550 {
    u8 pad0[4];
    s32 f4;
    s32 f8;
    f32 fc;
    f32 f10;
};

struct Obj_80062550 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0xb8 - 0x44];
    s16 fb8;
    u8 padba[0x490 - 0xba];
    s32 f490;
    u8 pad494[0x4bc - 0x494];
    Tgt_80062550 *f4bc;
};

struct Obj_80060F4C {
    u8 pad0[0x60];
    s32 f60;
    u8 pad64[0xB8 - 0x64];
    s16 fb8;
    u8 padba[0x4C0 - 0xBA];
    u32 flags;
};

struct ByteBlock_10 { u8 bytes[0x10]; };


struct P_80064AB0 { u16 a; u16 id; u32 kind; f32 x; f32 z; };



struct Obj_80065658 {
    u8 pad0[0x18];
    void *vt;
    u8 pad1c[0x3c0 - 0x1c];
    Vec f3c0[15];
    f32 f474[3];
    u8 pad480[0x484 - 0x480];
    f32 f484[3];
    u8 pad490[0x494 - 0x490];
    Boss5GryphonMotionEntry motions[2];
    u8 pad4bc[0x4c4 - 0x4bc];
    u8 f4c4[0x4e8 - 0x4c4];
    Vec f4e8[10];
    u8 pad560[0x578 - 0x560];
    AreaAttackHistory *attack_history;
    TBoss5GryphonDemo *demo;
    u8 f580[0x6f4 - 0x580];
    f32 f6f4[11];
    u8 pad720[0x734 - 0x720];
    void *objs[16];
};

struct Obj_80063570 {
    u8 pad0[0xb8];
    s16 fb8;
    u8 padba[0x490 - 0xba];
    s32 f490;
    u8 pad494[0x4c0 - 0x494];
    s32 flags;
};


struct Obj_8005D880 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x60 - 0x44];
    s32 f60;
};


struct Seg_80063CDC { f32 x, y, z, w; };

f32 newton_sqrtf(f32);

s32 get_player_pos_in_arc__13TBoss5GryphonFPviiPvPv(Obj_8005D880 *arg0, s32 arg1, s32 arg2, Vec *org, Vec *out);
void render_shadows__13TBoss5GryphonFv(void* p);
void TBoss8Dragon__sub_8005E17C(NJS_OBJECT *);
void TBoss8Dragon__sub_8005F684(TBoss5Gryphon *self, void *params);
void trigger_effect__12TBoss8DragonFPvi(void *arg0, s32 arg1);
void apply_shockwave_hit(s32 arg0, s32 arg1);
void apply_remote_action__13TBoss5GryphonFPvPv(u8 *ene_dd, u8 *boss8_dragon);
void run_miss_reaction__13TBoss5GryphonFv(void);
void run_hit_reaction__13TBoss5GryphonFv(void);
void run_death_reaction__13TBoss5GryphonFv(void);
void refresh_target__13TBoss5GryphonFv(void);
Obj_80065658 * __dt__13TBoss5GryphonFv(Obj_80065658 *o, s16 flag);
void TBoss8Dragon__sub_800660A4(void *);
s32 __ct__17TBoss5GryphonDemoFP7TObjectlf(void *, s32, void *, f32);
s32 init_motion_record(s32);
void TBoss8Dragon__sub_80067074(saddr arg0, saddr prm);
void start_camera_shake(s32 id, f32 v);
void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);
void *__dt__15RenderFadeStateFv(void *arg0, s16 arg1);
u8 *get_enemy_entity(u16 arg0);
s32 TObjLight__sub_801337F8(void *);
s32 draw__10TObjMotionFv(void *);
u8 * find_entity_by_id();
void free_collision_body_parts(void *);
s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);
void __dt__7TObjectFv(void *, int);
void TBoss5GryphonLightningEff__sub_80325064(void *p);
void * __ct__25TBoss5GryphonLightningEffFv(void *, void *, void *, s32, f32, f32, f32);
s32 spawn_lightning_wing__12TBoss8DragonFiiiiii(saddr self, saddr pos, saddr mid, saddr arg3, saddr arg4, saddr arg5);
void __destroy_arr(void *, void *, int, int);
f32 vec3_dot(void *, void *);
void subtract_vector(void *, void *);
s32 post_translate_matrix(void *);
void set_material_alpha_compare_reference(s32 reference);
void set_chunk_material_override_pair(s32 arg0, s32 arg1);
}

void *lbl_80487848[4] = {
    (void *)"boss_rock.gj", (void *)"fe_obj001_iwaware_01.gj", (void *)"fe_obj001_iwaware_02.gj", (void *)0x0,
};
void *lbl_80487858[2] = {
    (void *)"boss_rock.njm", (void *)0x0,
};
// Resource descriptor passed to load_enemy_bml_resource for boss5_gryphon_bml_resource.
void *boss5_gryphon_bml_desc[4] = {
    (void *)"bm_modelparticle_gryphon.bml", (void *)&lbl_80487848, (void *)&lbl_80487858, (void *)0x30001,
};
// Ids resolved into boss5_gryphon_attack_params / boss5_gryphon_behavior_params by the resource loader.
s32 boss5_gryphon_attack_param_ids[5] = { 0x1E, 0x1F, 0x20, 0x21, 0x22 };
s32 boss5_gryphon_behavior_param_ids[3] = { 0x1E, 0x1F, 0x20 };
void *lbl_80487890[3] = {
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_8048789C[3] = {
    (void *)0x0, (void *)0x1, (void *)0x2,
};
void *lbl_804878A8[3] = {
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804878B4[7] = {
    (void *)0x43610000, (void *)0x0, (void *)0x600, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0,
};
void *lbl_804878D0[110] = {
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41200000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41200000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41200000, (void *)0x0, (void *)0x0, (void *)0x8003,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41200000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41200000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x41700000, (void *)0x0, (void *)0x0,
    (void *)0x8003, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x41700000, (void *)0x0, (void *)0x0, (void *)0x8003,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x41700000,
    (void *)0x0, (void *)0x0, (void *)0x8003, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0, (void *)0x41700000, (void *)0x0,
    (void *)0x0, (void *)0x8003, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x0,
};
extern const Vec lbl_80437938 = { 0.0f, 0.0f, 0.0f };
extern const DragonAttackParams boss5_gryphon_params_b = { 0, 0.0f, 30.0f, 7.0f, 1 };
extern const s32 lbl_80437958[9] = { 0x220, 0x221, 0x222, 0x202, 0x200, 0x207, 0x223, 0x224, 0x225 };
extern const s32 boss5_gryphon_bone_capture_node_indices[16] = {
    4, 11, 27, 43, 46, 47, 48, 66, 69, 70, 71, 95, 128, 144, 159, 999,
};
void *lbl_80487A88[5] = {
    (void *)"boss5_s_body.nj", (void *)"boss5_ss_body.nj", (void *)"lo_boss5_s_body.nj", (void *)"lo_boss5_ss_body.nj",
    (void *)0x0,
};
void *lbl_80487A9C[28] = {
    (void *)"fly_boss5_s_body.njm", (void *)"hoe_boss5_s_body.njm", (void *)"kakuin_boss5_s_body.njm", (void *)"kakuland_boss5_s_body.njm",
    (void *)"kakuout_boss5_s_body.njm", (void *)"kaku_boss5_s_body.njm", (void *)"land_boss5_s_body.njm", (void *)"op_boss5_s_body.njm",
    (void *)"shot_boss5_s_body.njm", (void *)"stand_boss5_s_body.njm", (void *)"takeoff_boss5_s_body.njm", (void *)"walk_boss5_s_body.njm",
    (void *)"huseout_boss5_s_body.njm", (void *)"houko_boss5_s_body.njm", (void *)"huse_boss5_s_body.njm", (void *)"husein_boss5_s_body.njm",
    (void *)"dead_boss5_s_body.njm", (void *)"kiri_boss5_s_body.njm", (void *)"kiriland_boss5_s_body.njm", (void *)"kirin_boss5_s_body.njm",
    (void *)"kiriout_boss5_s_body.njm", (void *)"run_boss5_s_body.njm", (void *)"runin_boss5_s_body.njm", (void *)"runout_boss5_s_body.njm",
    (void *)"tuno_boss5_s_body.njm", (void *)"tunoin_boss5_s_body.njm", (void *)"tunout_boss5_s_body.njm", (void *)0x0,
};
// Resource descriptor passed to load_enemy_bml_resource for boss5_gryphon_body_bml_resource.
void *boss5_gryphon_body_bml_desc[4] = {
    (void *)"bm_boss5_gryphon.bml", (void *)&lbl_80487A88, (void *)&lbl_80487A9C, (void *)0x4001b,
};
extern const char boss5_gryphon_type_name[] = "TBoss5Gryphon";
extern const s32 gryphon_part_attack_index_table[4] = { 1, 2, 12, 13 };
extern const DragonAttackParams gryphon_part_attack_params = { 0, 10.0f, 15.0f, 8.0f, 1 };
extern const DragonAttackParams gryphon_collider_desc = { 0, 0.0f, 80.0f, 0.0f, 1 };
extern const f32 gryphon_effect_scale_table[5] = { 20.0f, 30.0f, 50.0f, 30.0f, 20.0f };
extern const DragonAttackParams gryphon_effect_param_block = { 0, 0.0f, 0.0f, 7.0f, 1 };
extern const DragonAttackParams boss8_dragon_attack_params = { 0, 0.0f, 0.0f, 7.0f, 1 };
extern const DragonAttackParams lbl_80437D40 = { 0, 10.0f, 35.0f, 10.0f, 1 };
extern const DragonAttackParams lbl_80437D54 = { 0, 10.0f, 5.0f, 10.0f, 1 };
extern const DragonAttackParams lbl_80437D68 = { 0, 10.0f, 15.0f, 10.0f, 1 };
extern const DragonAttackParams lbl_80437D7C = { 0, 10.0f, 15.0f, 10.0f, 1 };
extern const DragonAttackParams lbl_80437D90 = { 0, 10.0f, 10.0f, 10.0f, 1 };
extern const DragonAttackParams lbl_80437DA4 = { 3, 10.0f, 10.0f, 20.0f, 1 };
extern const Vec lbl_80437DB8 = { 0.0f, 2.0f, 0.0f };
extern const Vec lbl_80437DC4 = { 23.0f, 180.0f, 991.0f };
extern const s32 lbl_80437DD0[3] = { -2928, 36734, 0 };
extern const Vec boss5_gryphon_waypoint_vecs[2] = { { 27.0f, 0.0f, 175.0f }, { 153.0f, 437.0f, 1347.0f } };
extern const f32 boss5_gryphon_scale_x_table[4] = { 0.3f, 0.75f, 0.75f, 0.0f };
extern const f32 boss5_gryphon_scale_y_table[4] = { 0.0f, 0.75f, 0.75f, 0.0f };
extern const f32 gryphon_velocity_scale_z_table[4] = { 0.0f, 0.75f, 0.75f, 0.0f };
extern const f32 gryphon_action_probability_table_a[9] = { 0.0f, 0.0f, 0.0f, 0.0f, 0.2f, 0.3f, 0.4f, 0.5f, 0.6f };
const f32 gryphon_action_probability_table_b[9] = { 0.0f, 0.0f, 0.1f, 0.2f, 0.2f, 0.3f, 0.4f, 0.4f, 0.5f };
const s32 gryphon_bone_copy_index_table[10] = { 0, 1, 2, 12, 13, 11, 3, 5, 7, 9 };
const s32 boss5_gryphon_point_index_table[5] = { 1, 2, 12, 13, 0 };
saddr boss5_gryphon_attack_params[5];
void *boss5_gryphon_behavior_params[3];
Vec boss5_gryphon_bone_capture_origin;
u8 boss5_gryphon_camera_pos_vec[0xC];
u8 boss5_gryphon_direction_vec[0x10];
extern const f32 lbl_805D9E80;
// Set up by this file's static initializer (the last function in the object).
f32 lbl_805D4D90 = lbl_805D8D90 * lbl_805D9E80;
f32 lbl_805D4D94 = 2.0f * lbl_805D9E80;
saddr boss5_gryphon_base_params[1];
saddr boss5_gryphon_resistance_params[1];
u8 *boss5_gryphon_body_bml_resource;
BmlResource *boss5_gryphon_bml_resource;
GinjaTextureList *boss5_gryphon_texture_list;
s32 boss5_gryphon_render_node_index;
s32 boss5_gryphon_bone_capture_index;
saddr boss5_gryphon_bone_capture_output;
s32 boss5_gryphon_render_flags;
Obj_80065658 *boss5_gryphon_instance;
f32 lbl_805D4DC0;
extern "C" {
extern u8 *camera_ctrl_instance;
extern saddr current_scene_light;
extern s32 saved_model_render_flags;
extern const float lbl_805D8D84;
extern const f32 lbl_805D8D8C;
extern const f32 lbl_805D8D9C;
extern const float lbl_805D8DEC;
extern const f32 lbl_805D8DF4;
extern const f32 lbl_805D8DF8;
extern const f32 lbl_805D8E00;
extern const f32 lbl_805D8E04;
extern const f32 lbl_805D8E08;
extern const f32 lbl_805D8E0C;
extern const f32 lbl_805D8E14;
extern const float lbl_805D8E20;
extern const f32 lbl_805D8E34;
extern const f32 lbl_805D8E60;
extern const f32 lbl_805D8E64;
extern const f32 lbl_805D8E68;
extern const f32 lbl_805D8E6C;
extern const f32 lbl_805D8E70;
extern const f32 lbl_805D8E74;
extern const f32 lbl_805D8E78;
extern const f32 lbl_805D8E7C;
extern const f32 lbl_805D8E8C;
extern const f32 lbl_805D8E90;
extern const f32 lbl_805D8E94;
extern const f32 lbl_805D8E98;
extern const f32 lbl_805D8EA4;
extern const f32 lbl_805D8EA8;
extern const f32 lbl_805D8EB0;
extern const f32 lbl_805D8EB4;
extern const f32 lbl_805D8EB8;
extern const f32 lbl_805D8EBC;
extern const f32 lbl_805D8EC0;
extern const float lbl_805D8EC4;
extern const f32 lbl_805D8EC8;
extern s32 model_render_flags;
extern saddr tl_01;

#pragma push
#pragma fp_contract on

extern "C" {
void render_demo__13TBoss5GryphonFv();
}
extern "C" {
void run_demo_task__13TBoss5GryphonFv();
}
extern "C" {
s32 is_split_screen();
void render__13TBoss5GryphonFv(TBoss5Gryphon *self);
}
extern "C" {
void matrix_mult_vec(s32 mtx, void *in, void *out);
}
extern "C" {
f32 fabs_float(f32);
}
extern "C" {
void apply_poison_status__13TBoss5GryphonFv();
}
extern "C" {
void apply_paralysis__13TBoss5GryphonFv();
}
extern "C" {
void apply_slow_status__13TBoss5GryphonFv();
}
extern "C" {
void apply_confusion_status__13TBoss5GryphonFv();
}
extern "C" {
void apply_movement_ailment__13TBoss5GryphonFl();
}
extern "C" {
void apply_shock_status__13TBoss5GryphonFv();
}
extern "C" {
void clear_harmful_statuses__13TBoss5GryphonFv();
}
extern "C" {
void vfunc_6__8TObjBaseFPsl();
}
extern "C" {
void snap_to_ground_at__9TObjEneDDFPUc();
}
extern "C" {
void apply_enemy_state__9TObjEneDDFPl();
}
extern "C" {
void update_immobilizing_statuses__9TObjEneDDFv();
}
extern "C" {
void update_action_state__9TObjEneDDFv();
}
extern "C" {
void has_action_state_changed__9TObjEneDDFv();
}
extern "C" {
void check_collisions__9TObjEneDDFv();
}
extern "C" {
void vfunc_90__9TObjEneDDFv();
}
extern "C" {
void set_invulnerable__9TObjEneDDFv();
}
extern "C" {
void clear_invulnerable__9TObjEneDDFv();
}
extern "C" {
void enable_body_collision__9TObjEneDDFv();
}
extern "C" {
void disable_body_collision__9TObjEneDDFv();
}
extern "C" {
void set_intangible__9TObjEneDDFv();
}
extern "C" {
void clear_intangible__9TObjEneDDFv();
}
extern "C" {
void set_colliders_contact_high__9TObjEneDDFv();
}
extern "C" {
void set_colliders_contact_low__9TObjEneDDFv();
}
extern "C" {
void is_confused__9TObjEneDDFv();
}
extern "C" {
void render_minimap_dot__9TObjEneDDFv();
}
extern "C" {
void move_xz_on_ground__9TObjEneDDFPUc();
}
extern "C" {
void update_ground_contact__9TObjEneDDFv();
}
extern "C" {
int acquire_target__12TObjEneDD_STFf(void *p);
}
extern "C" {
void update_status_effects__12TObjEneDD_STFv();
}
extern "C" {
void has_no_target__9TObjCharaFv();
}
extern "C" {
void recalc_stats__9TObjCharaFv();
}
extern "C" {
void consume_timer_field__9TObjCharaFl();
}
extern "C" {
void deliver_attack_hits__9TObjCharaFf();
}
extern "C" {
void vfunc_66__9TObjCharaFv();
}
extern "C" {
void get_anim_node_position__9TObjCharaFlP3Vec();
}
extern "C" {
void run_attack_action__9TObjCharaFv();
}
extern "C" {
void run_move_action__9TObjCharaFv();
}
extern "C" {
void run_idle_action__9TObjCharaFv();
}
extern "C" {
void update_shock_clock__9TObjCharaFv();
}
extern "C" {
void vfunc_43__9TObjCharaFv();
}
extern "C" {
void update_actor_ground_y_at__9TObjCharaFP3Vec();
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
void add_actor_exp__9TObjCharaFl();
}
extern "C" {
void apply_action_hold_status__9TObjCharaFf();
}
extern "C" {
void apply_anti_technique__9TObjCharaFl();
}
extern "C" {
void apply_attack_stat_status__9TObjCharaFPv();
void apply_defense_stat_status__9TObjCharaFPv();
}
extern "C" {
void apply_knockback_from_attacker__9TObjCharaFPUcf();
}
extern "C" {
void apply_object_set_data__8TObjBaseFPv();
}
extern "C" {
void apply_set_data__9TObjEnemyFPv();
}
extern "C" {
void apply_switch_attack__9TObjCharaFv();
}
extern "C" {
void calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf();
}
extern "C" {
void classify_actor_view_detail__8TObjBaseFfff();
}
extern "C" {
void clear_all_status_effects__9TObjCharaFv();
}
extern "C" {
void cure_paralysis__9TObjCharaFv();
}
extern "C" {
void cure_poison_ailment__9TObjCharaFv();
}
extern "C" {
void enemy_spawn_jellen_effect__9TObjCharaFv();
}
extern "C" {
void enemy_spawn_zalure_effect__9TObjCharaFv();
}
extern "C" {
void vfunc_78__9TObjCharaFl();
}
extern "C" {
void gain_photon_blast_chain_charge__9TObjCharaFv();
}
extern "C" {
void spend_photon_blast_charge__9TObjCharaFf();
}
extern "C" {
void gain_photon_blast_charge__9TObjCharaFf();
}
extern "C" {
void clear_lobby_object_state__9TObjEnemyFv();
}
extern "C" {
void get_center__9TObjCharaFv();
}
extern "C" {
void get_actor_level_index__9TObjCharaFv();
}
extern "C" {
void get_name__9TObjEnemyFv();
}
extern "C" {
void get_pos__9TObjCharaFl();
}
extern "C" {
void is_actor_cadence_frame__9TObjCharaFl();
}
extern "C" {
void is_target_in_attack_range__9TObjCharaFv();
}
extern "C" {
void receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll();
}
extern "C" {
void receive_physical_attack__9TObjCharaFPvf();
}
extern "C" {
void receive_weapon_special_attack__9TObjCharaFPvPv();
}
extern "C" {
void reset_motion_fields__9TObjCharaFv();
}
extern "C" {
void reset_pose__9TObjCharaFv();
}
extern "C" {
void roll_physical_accuracy__9TObjCharaFPvlf();
}
extern "C" {
void select_melee_contact_body__9TObjCharaFPvf();
}
extern "C" {
void trigger_switch_attack__9TObjCharaFv(s32 arg0);
}
extern "C" {
void try_start_action__9TObjCharaFll();
}
extern "C" {
void update_action_hold_status__9TObjCharaFv();
}
extern "C" {
s32 update_slow_status__9TObjCharaFv(u8 *arg0);
}
extern "C" {
void update_actor_ground_y__9TObjCharaFv();
}
extern "C" {
s32 update_attack_stat_status__9TObjCharaFv(u8 *arg0);
}
extern "C" {
s32 update_defense_stat_status__9TObjCharaFv(u8 *arg0);
}
extern "C" {
void update_flag30_timer__9TObjCharaFv();
}
extern "C" {
void update_movement_status__9TObjCharaFv();
}
extern "C" {
void update_object_view_visibility__8TObjBaseFff();
}
extern "C" {
void update_poison_status__9TObjCharaFv();
}
void *lbl_80487B1C[108] = {
    (void *)0x10000, (void *)0x9, (void *)0x3f4ccccd, (void *)0x0,
    (void *)0x10000, (void *)0xb, (void *)0x3f000000, (void *)0x0,
    (void *)0x30000, (void *)0x1, (void *)0x3edc28f6, (void *)0x0,
    (void *)0x30000, (void *)0xa, (void *)0x3f000000, (void *)0x0,
    (void *)0x10000, (void *)0x0, (void *)0x3f451eb8, (void *)0x0,
    (void *)0x30000, (void *)0x6, (void *)0x3ef5c28f, (void *)0x0,
    (void *)0x20007, (void *)0x2, (void *)0x3f333333, (void *)0x6,
    (void *)0x10000, (void *)0x5, (void *)0x3f666666, (void *)0x7,
    (void *)0x30000, (void *)0x4, (void *)0x3f11eb85, (void *)0x0,
    (void *)0x30000, (void *)0x3, (void *)0x3f333333, (void *)0x0,
    (void *)0x2000b, (void *)0x16, (void *)0x3f800000, (void *)0xa,
    (void *)0x10000, (void *)0x15, (void *)0x3f800000, (void *)0xb,
    (void *)0x30000, (void *)0x17, (void *)0x3f800000, (void *)0x0,
    (void *)0x2000e, (void *)0xf, (void *)0x3ecccccd, (void *)0xd,
    (void *)0x10000, (void *)0xe, (void *)0x3eb33333, (void *)0xe,
    (void *)0x30000, (void *)0xc, (void *)0x3ecccccd, (void *)0x0,
    (void *)0x20011, (void *)0x19, (void *)0x3f400000, (void *)0x10,
    (void *)0x10000, (void *)0x18, (void *)0x3eb33333, (void *)0x11,
    (void *)0x30000, (void *)0x1a, (void *)0x3f19999a, (void *)0x0,
    (void *)0x20014, (void *)0x13, (void *)0x3f000000, (void *)0x13,
    (void *)0x10000, (void *)0x11, (void *)0x3f800000, (void *)0x14,
    (void *)0x30000, (void *)0x14, (void *)0x3f000000, (void *)0x15,
    (void *)0x30000, (void *)0x12, (void *)0x3ecccccd, (void *)0x16,
    (void *)0x30000, (void *)0xd, (void *)0x3eb33333, (void *)0x0,
    (void *)0x30000, (void *)0x8, (void *)0x3f266666, (void *)0x0,
    (void *)0x30000, (void *)0x7, (void *)0x3f800000, (void *)0x80000000,
    (void *)0x30000, (void *)0x10, (void *)0x3f000000, (void *)0x0,
};
void *boss8_dragon_follow_camera_offsets[3] = {
    (void *)0x0, (void *)0x419e6666, (void *)0xc0a00000,
};
void *lbl_80487CD8[3] = {
    (void *)0x0, (void *)0x41cb70a4, (void *)0x4235ae14,
};
extern void *lbl_8048802C[16];
extern void *boss5_gryphon_descend_bezier_points[16];
extern void *lbl_804880AC[3];
extern void *lbl_804880B8[3];
extern void *gryphon_particle_enable_pos[3];
extern void *gryphon_particle_position_vec[3];
extern void *__vt__13TBoss5Gryphon[107];
#define gryphon_particle_enable_pos ((u8 *)gryphon_particle_enable_pos)
#define gryphon_particle_position_vec ((s32 *)gryphon_particle_position_vec)
#define __vt__13TBoss5Gryphon ((u8 *)__vt__13TBoss5Gryphon)

struct Cnt_8005D708 { u32 f0; u32 count; };

struct Mot_8005D708 { u32 f0; Cnt_8005D708 *p; };

struct Anm_8005D708 { u32 f0; s32 idx; u32 f8; u32 fc; };

struct Obj_8005D708 {
    u8 pad0[0x24];
    s32 f24;
    u8 pad28[0xC];
    saddr f34;
    u8 pad38[0x28];
    s32 f60;
    u8 pad64[0xD8 - 0x64];
    Anm_8005D708 *anims;
    Mot_8005D708 *mots;
    u8 pade0[0x354 - 0xE0];
    f32 f354;
    f32 f358;
};

// Read by TBoss5GryphonLightningHorn, TBoss5GryphonLightningWing, TBoss5GryphonTornado and spawn_gryphon_tornado.
extern const f32 lbl_805D8D48;
const f32 lbl_805D8D48 = 6.0f;

extern "C" {
void TBoss5Gryphon::render_demo() {
#define o ((Obj_8005D708 *)this)
    Cnt_8005D708 *c;
    f32 f;
    s32 idx;
    if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
        TObjFish::set_global_param(o->f24);
        push_matrix();
        post_translate_matrix((u8 *)this + 0x38);
        rotate_matrix_y(0, o->f60);
        push_matrix();
        scale_matrix(0, 8.0f, 2.0f, 8.0f);
        pop_matrix();
        scale_matrix(0, 2.0f, 2.0f, 2.0f);
        model_render_flags &= ~0x400;
        idx = (s32)o->f354;
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 0x1B) {
            idx = 0x1A;
        }
        c = o->mots[o->anims[idx].idx].p;
        f = o->f358;
        if (f < 0.0f) {
            f = 0.0f;
        } else {
            u32 n = c->count;
            if (f > (n - 1)) {
                f = (f32)n;
            }
        }
        draw_model_motion((void *)o->f34, c, f);
        TObjLight__sub_801337F8((void *)current_scene_light);
        pop_matrix();
    }
#undef o
}

}


void TBoss5Gryphon::run_demo_task() { get_target_info(); }

s32 get_player_pos_in_arc__13TBoss5GryphonFPviiPvPv(Obj_8005D880 *arg0, s32 arg1, s32 arg2, Vec *org, Vec *out) {
    Obj_8005D880 *p;
    f32 dx;
    f32 dz;
    f32 px;
    f32 pz;
    s32 ang;

    p = ((Obj_8005D880 * (*)(s32))get_player_by_client_id)(arg2);
    if (p == 0) {
        return 0;
    }
    pz = p->pos.z;
    px = p->pos.x;
    dz = pz - arg0->pos.z;
    dx = px - arg0->pos.x;
    if (dx * dx + dz * dz < 10000.0f) {
        return 0;
    }
    ang = angle_diff_s16((s32)(10430.38043493439 * atan2_float(px - org->x, pz - org->z)), arg0->f60);
    if (arg1 != 0) {
        if ((f32)(s32)(u16)ang > 45056.0f) {
            return 0;
        }
    } else {
        if ((f32)(s32)(u16)ang < 20480.0f) {
            return 0;
        }
    }
    VecCopy(out, &p->pos);
    return 1;
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss8Dragon__sub_8005D9BC(u8 *arg0, s32 arg1, s32 arg2) {
    Vec pos;
    Vec mid;
    Vec out;
    Vec tmp;
    f32 r;
    s32 ang;
    u8 *p;

    r = calc_random_ratio__10TObjPlayerFv(arg0 + 0x5F4);
    r = 100.0f * r + 100.0f;
    ang = (s32)(45056.0f * calc_random_ratio__10TObjPlayerFv(arg0 + 0x5F4) + (f32)*(s32 *)((s8 *)arg0 + 0x60));
    if (arg1 != 0) {
        if (*(u32 *)((s8 *)arg0 + 0x6DC) == 0) return;
        copy_position__26TBoss5GryphonLightningWingFPv((void *)(*(uaddr *)((s8 *)arg0 + 0x6DC)), &pos);
    } else {
        if (*(u32 *)((s8 *)arg0 + 0x6E0) == 0) return;
        copy_position__26TBoss5GryphonLightningWingFPv((void *)(*(uaddr *)((s8 *)arg0 + 0x6E0)), &pos);
    }
    if (((s32 (*)(void *, s32, s32, void *, void *))get_player_pos_in_arc__13TBoss5GryphonFPviiPvPv)(arg0, arg1, arg2, &pos, &out) == 0) {
        if (arg1 != 0) {
            ang += 20480.0f;
        }
        out.x = r * sin_table_lookup(ang) + *(f32 *)((s8 *)arg0 + 0x38);
        out.y = *(f32 *)((s8 *)arg0 + 0x3C);
        out.z = r * cos_table_lookup(ang) + *(f32 *)((s8 *)arg0 + 0x40);
        VecCopy(&tmp, &out);
        p = (u8 *)csnVecterUnder(&tmp, 0x16EF);
        if (p == NULL || *(f32 *)((s8 *)(*(u8 **)((s8 *)p + 4)) + 4) > 6.0f) {
            out.x = 100.0f * sin_table_lookup(ang) + *(f32 *)((s8 *)arg0 + 0x38);
            out.y = *(f32 *)((s8 *)arg0 + 0x3C);
            out.z = 100.0f * cos_table_lookup(ang) + *(f32 *)((s8 *)arg0 + 0x40);
        }
    }
    mid.x = 0.5f * (pos.x + out.x);
    mid.y = 250.0f + pos.y;
    mid.z = 0.5f * (pos.z + out.z);
    spawn_lightning_wing__12TBoss8DragonFiiiiii((saddr)arg0, (saddr)&pos, (saddr)&mid, (saddr)&out, 0x14, 0x11);
}
#pragma pop

void TBoss5Gryphon::render_nodes_with_flag() {
    saddr self = (saddr)this;
    s32 temp_r4;

    temp_r4 = model_render_flags;
    saved_model_render_flags = temp_r4;
    model_render_flags = temp_r4 | 0x400;
    ((TObject *)(self + 0x4C4))->render_nodes();
    model_render_flags = saved_model_render_flags;
}

s32 TBoss5Gryphon::fn_8005DC0C() {
    Vec cam;
    Vec dir;
    f32 len;
    u8 *pl;
    s32 i;
    if (camera_ctrl_instance == 0) {
        return 0;
    }
    if (mode == 4) {
        return 0;
    }
    if (get_flag_bit6() != 0) {
        return 0;
    }
    if (flight_mode != 0) {
        return 0;
    }
    TCameraCtrl::get_camera_target_id(-1);
    pl = find_entity_by_id();
    if (pl == 0) {
        return 0;
    }
    VecCopy(&cam, (Vec *)(camera_ctrl_instance + 0x178));
    cam.y = 0.0f;
    VecCopy(&dir, (Vec *)(pl + 0x38));
    subtract_vector(&dir, &cam);
    dir.y = 0.0f;
    len = normalize_vector_xz(&dir);
    VecCopy((Vec *)boss5_gryphon_camera_pos_vec, &cam);
    VecCopy((Vec *)boss5_gryphon_direction_vec, &dir);
    lbl_805D4DC0 = len;
    for (i = 0; i < 4; i++) {
        if (fn_8005E1E8(&pad_3C0[boss5_gryphon_point_index_table[i]], lbl_805D8D80) != 0) {
            return 1;
        }
    }
    return 0;
}

void TBoss5Gryphon::render_with_fade(s32 arg1) {
    RenderFadeState *fade;
    TObjFish::set_global_param(this->texlist);
    TObjEneDD::clear_global_flag_400();
    saved_model_render_flags = model_render_flags;
    set_material_alpha_compare_reference(0);
    if (fn_8005DC0C() != 0) {
        this->renderFadeStates[arg1].fadeOut();
    } else {
        this->renderFadeStates[arg1].restore();
    }
    fade = &this->renderFadeStates[arg1];
    if (fade->isFading() != 0) {
        fade->set_flags_and_apply_damage_color();
    }
    push_matrix();
    post_translate_matrix((void *) (((u8 *)this) + 0x38));
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, this->rotation_x);
    rotate_matrix_z(0, this->rotation_z);
    scale_matrix(0, 2.0f, 2.0f, 2.0f);
    TObjPlayer::toggle_particle_effect();
    draw();
    TParticleCtrl::end_effect_render();
    TObjLight__sub_801337F8((void *)current_scene_light);
    pop_matrix();
    set_chunk_material_override_pair(0xFF00, 0);
    set_material_alpha_compare_reference(0xBF);
    model_render_flags = saved_model_render_flags;
}

void TBoss5Gryphon::render_model() {
    s32 temp_r31;
    u8 *temp_r4;

    push_matrix();
    post_translate_matrix((void *) (((u8 *)this) + 0x38));
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, this->rotation_x);
    rotate_matrix_z(0, this->rotation_z);
    scale_matrix(0, 2.0f, 2.0f, 2.0f);
    temp_r31 = *(s32 *)&this->model;
    temp_r4 = (unsigned char *) (*(void **)((s8 *)boss5_gryphon_body_bml_resource + 0x42C));
    *(s32 *)&this->model = (s32) *(s32 *)((s8 *)temp_r4 + 0x18);
    ((s32 (*)(void *, int))draw__10TObjMotionFv)(this, (saddr)temp_r4);
    *(s32 *)&this->model = temp_r31;
    pop_matrix();
}

void TBoss5Gryphon::render_shadows() { if (TObjPlayer::check_demo_mode() == 0) { render_model(); } }

void TBoss5Gryphon::render() {
    s32 view = 0;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->render_demo();
        return;
    }
    if (is_split_screen() != 0) {
        view = TCameraCtrl::get_camera_mode();
    }
    if (this->defer_render() != 0) {
        fn_8005E040();
        this->draw_body();
        this->copy_bone_positions();
        if (this->renderFadeStates[view].isFading() == 0) {
            this->render_with_fade(view);
        }
        this->render_nodes_with_flag();
    } else if (this->renderFadeStates[view].isFading() != 0) {
        this->render_with_fade(view);
    }
}

void TBoss5Gryphon::fn_8005E040() {
    if (flight_mode == 0) {
        position.y = lbl_805D8D84;
    }
}

void TBoss5Gryphon::copy_bone_positions() {
    s32 i;
    Vec *d = ((Obj_8005E058 *)this)->dst;
    for (i = 0; i < 10; i++) {
        VecCopy(d, &((Obj_8005E058 *)this)->src[gryphon_bone_copy_index_table[i]]);
        d++;
    }
}

void TBoss5Gryphon::draw_body() {
    boss5_gryphon_render_node_index = 0;
    boss5_gryphon_bone_capture_index = 0;
    boss5_gryphon_bone_capture_output = (saddr)((Obj_8005E0C0 *)this)->f3c0;
    boss5_gryphon_render_flags = ((Obj_8005E0C0 *)this)->f4c0;
    set_chunk_model_node_callback(TBoss8Dragon__sub_8005E17C);
    push_matrix();
    set_motion_packed_rotation();
    ((void (*)(void *))post_translate_matrix)((u8 *)this + 0x38);
    ((void (*)(int, int))rotate_matrix_y)(0, ((Obj_8005E0C0 *)this)->f60);
    ((void (*)(int, int))rotate_matrix_x)(0, ((Obj_8005E0C0 *)this)->f5c);
    ((void (*)(int, int))rotate_matrix_z)(0, ((Obj_8005E0C0 *)this)->f64);
    ((void (*)(int, f32, f32, f32))scale_matrix)(0, 2.0f, 2.0f, 2.0f);
    draw_motion((NJS_OBJECT *)((Obj_8005E0C0 *)this)->f34, (NJS_MOTION *)((Obj_8005E0C0 *)this)->ff8, this->get_motion_frame());
    clear_motion_packed_rotation();
    pop_matrix();
    set_chunk_model_node_callback(0);
}

void TBoss8Dragon__sub_8005E17C(NJS_OBJECT *) {
    saddr pos;
    if ((s32) boss5_gryphon_render_node_index == boss5_gryphon_bone_capture_node_indices[boss5_gryphon_bone_capture_index]) {
        pos = boss5_gryphon_bone_capture_output;
        boss5_gryphon_bone_capture_output = pos + 0xC;
        forward_transform_to_view((const Vec *)&boss5_gryphon_bone_capture_origin, (Vec *)pos);
        boss5_gryphon_bone_capture_index += 1;
    }
    boss5_gryphon_render_node_index += 1;
}

#pragma push
#pragma fp_contract on
s32 TBoss5Gryphon::fn_8005E1E8(Vec *point, f32 radius) {
    Vec dir;
    f32 dist;
    f32 cos_limit;
    VecCopy(&dir, point);
    dir.y = 0.0f;
    subtract_vector(&dir, (Vec *)boss5_gryphon_camera_pos_vec);
    dist = normalize_vector_xz(&dir);
    if (dist + radius < lbl_805D4DC0) {
        cos_limit = dist * (lbl_805D8D88 / newton_sqrtf(dist * dist + radius * radius));
        if (vec3_dot(&dir, boss5_gryphon_direction_vec) >= cos_limit) {
            return 1;
        }
    }
    return 0;
}
#pragma pop

void TBoss5Gryphon::free_parts() {
    if (particles[2] != NULL) {
        particles[2]->queue_destruction();
        particles[2] = NULL;
    }
    if (particles[1] != NULL) {
        particles[1]->queue_destruction();
        particles[1] = NULL;
    }
    if (particles[0] != NULL) {
        particles[0]->queue_destruction();
        particles[0] = NULL;
    }
}

void TBoss5Gryphon::update_particle_positions() {
    if (particles[0] != NULL) {
        particles[0]->set_position(gryphon_particle_position_vec);
        particles[0]->enable();
    }
    if (particles[1] != NULL) {
        particles[1]->set_position(gryphon_particle_position_vec);
        particles[1]->enable();
    }
    if (particles[2] != NULL) {
        particles[2]->set_position(gryphon_particle_position_vec);
        particles[2]->enable();
    }
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::fn_8005E39C() {
    Vec pos;
    ParticleAngles rot;
    pos.x = lbl_805D8D8C * sin_table_lookup(rotation_y) + pad_3C0[11].x;
    pos.y = pad_3C0[11].y;
    pos.z = lbl_805D8D8C * cos_table_lookup(rotation_y) + pad_3C0[11].z;
    rot.x = 0;
    rot.y = rotation_y;
    rot.x = 0x4000;
    if (particles[0] == NULL) {
        particles[0] = spawn_continuous_particle_effect_with_flags(&pos, effect_ids[6], 0x2040);
        particles[0]->set_direction(&rot);
    } else {
        particles[0]->set_position(&pos);
        particles[0]->set_direction(&rot);
    }
    if (particles[1] == NULL) {
        particles[1] = spawn_continuous_particle_effect_with_flags(&pos, effect_ids[7], 0x40);
    } else {
        particles[1]->set_position(&pos);
    }
    if (particles[2] == NULL) {
        particles[2] = spawn_continuous_particle_effect_with_flags(&pos, effect_ids[8], 0x40);
        particles[2]->set_direction(&rot);
    } else {
        particles[2]->set_position(&pos);
        particles[2]->set_direction(&rot);
    }
}
#pragma pop

void TBoss5Gryphon::destroy_parts() {
    s32 i;
    for (i = 15; i >= 0; i--) {
        if (((Obj_8005E4D4 *)this)->parts[i] != 0) {
            ((TObject *)(((Obj_8005E4D4 *)this)->parts[i]))->queue_destruction();
            ((Obj_8005E4D4 *)this)->parts[i] = 0;
        }
    }
}

void TBoss5Gryphon::enable_particles() {
    s32 i;
    for (i = 0; i < 16; i++) {
        if (((Obj_8005E52C *)this)->parts[i] != 0) {
            ((TParticleCtrl *)((Obj_8005E52C *)this)->parts[i])->set_position(gryphon_particle_enable_pos);
            ((TParticleCtrl *)(((Obj_8005E52C *)this)->parts[i]))->enable();
        }
    }
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::update_ground_effects() {
    Obj_8005E594 *self = (Obj_8005E594 *)this;
    Vec pts[16];
    Vec *p;
    Vec *q;
    s32 i;
    p = pts;
    VecCopy(p++, &self->cp[0]);
    VecCopy(p++, &self->cp[1]);
    VecCopy(p++, &self->cp[2]);
    VecCopy(p, &self->cp[3]);
    p[1].x = (2.0f * self->cp[0].x + self->cp[1].x) / lbl_805D8D90;
    p[1].y = (2.0f * self->cp[0].y + self->cp[1].y) / lbl_805D8D90;
    p[1].z = (2.0f * self->cp[0].z + self->cp[1].z) / lbl_805D8D90;
    p[2].x = (2.0f * self->cp[1].x + self->cp[0].x) / lbl_805D8D90;
    p[2].y = (2.0f * self->cp[1].y + self->cp[0].y) / lbl_805D8D90;
    p[2].z = (2.0f * self->cp[1].z + self->cp[0].z) / lbl_805D8D90;
    p[3].x = 0.5f * (self->cp[1].x + self->cp[2].x);
    p[3].y = 0.5f * (self->cp[1].y + self->cp[2].y);
    p[3].z = 0.5f * (self->cp[1].z + self->cp[2].z);
    p[4].x = 0.5f * (self->cp[2].x + self->cp[3].x);
    p[4].y = 0.5f * (self->cp[2].y + self->cp[3].y);
    p[4].z = 0.5f * (self->cp[2].z + self->cp[3].z);
    p += 5;
    VecCopy(p++, &self->cp[4]);
    VecCopy(p++, &self->cp[5]);
    VecCopy(p++, &self->cp[6]);
    VecCopy(p, &self->cp[7]);
    p[1].x = (2.0f * self->cp[4].x + self->cp[5].x) / lbl_805D8D90;
    p[1].y = (2.0f * self->cp[4].y + self->cp[5].y) / lbl_805D8D90;
    p[1].z = (2.0f * self->cp[4].z + self->cp[5].z) / lbl_805D8D90;
    p[2].x = (2.0f * self->cp[5].x + self->cp[4].x) / lbl_805D8D90;
    p[2].y = (2.0f * self->cp[5].y + self->cp[4].y) / lbl_805D8D90;
    p[2].z = (2.0f * self->cp[5].z + self->cp[4].z) / lbl_805D8D90;
    p[3].x = 0.5f * (self->cp[5].x + self->cp[6].x);
    p[3].y = 0.5f * (self->cp[5].y + self->cp[6].y);
    p[3].z = 0.5f * (self->cp[5].z + self->cp[6].z);
    p[4].x = 0.5f * (self->cp[6].x + self->cp[7].x);
    p[4].y = 0.5f * (self->cp[6].y + self->cp[7].y);
    p[4].z = 0.5f * (self->cp[6].z + self->cp[7].z);
    q = pts;
    for (i = 0; i < 16; i++, q++) {
        Hit_8005E594 *hit = (Hit_8005E594 *)csnVecterUnder(q, 0x16EF);
        if (hit == NULL) {
            q->y = lbl_805D8D94;
        } else {
            f32 y = hit->p->y;
            if (y > 6.0f) {
                q->y = 6.0f;
            } else {
                q->y = y;
            }
        }
        if (self->parts[i] == NULL) {
            self->parts[i] = spawn_continuous_particle_effect_with_flags(q, self->fx->f14, 0x40);
        } else {
            ((TParticleCtrl *)self->parts[i])->set_position(q);
        }
    }
}
#pragma pop

s32 TBoss5Gryphon::get_random_sign(Boss5GryphonActionStep *step, s32 i) {
    s32 v;

    v = step->ints[i].min;
    if (v > 0) {
        return 1;
    }
    if (v < 0) {
        return -1;
    }
    if ((lbl_805D8D98 * (f32) rand()) >= 0.5f) {
        return 1;
    }
    return -1;
}

s32 TBoss5Gryphon::calc_product(Boss5GryphonActionStep *step, s32 sign_index, s32 range_index) {
    s32 value;

    value = random_in_table_range(step, range_index);
    return value * get_random_sign(step, sign_index);
}

#pragma push
#pragma fp_contract on
s32 TBoss5Gryphon::rand_scaled_offset(s32 base, s32 spread) {
    return (s32) (((f32) spread * (lbl_805D8D98 * (f32) rand())) + (f32) base);
}
#pragma pop

s32 TBoss5Gryphon::fn_8005E9D8(Boss5GryphonActionStep *step, s32 i) {
    return step->ints[i].min;
}

s32 TBoss5Gryphon::random_in_table_range(Boss5GryphonActionStep *step, s32 i) {
    return (s32) random_in_range((f32) step->ints[i].min, (f32) step->ints[i].range);
}

#pragma push
#pragma fp_contract on
f32 TBoss5Gryphon::random_in_range(f32 min, f32 range) {
    return (range * (lbl_805D8D98 * (f32) rand())) + min;
}
#pragma pop

#pragma push
#pragma scheduling off
f32 TBoss5Gryphon::fn_8005EAD0(Boss5GryphonActionStep *step, s32 i) {
    return random_in_range(step->floats[i].min, step->floats[i].range);
}
#pragma pop

void TBoss5Gryphon::set_random_param(u8 *arg1) {
    *(s32 *)((s8 *)arg1 + 4) = (s32) (lbl_805D8D9C * (lbl_805D8D98 * (f32) rand()));
}

void TBoss5Gryphon::calc_attack_params(void *arg1, Boss5GryphonActionStep *step) {
    f32 temp_f1;
    temp_f1 = fn_8005EAD0(step, 1);
    *(f32 *)((s8 *)arg1 + 0xC) = (f32) (temp_f1 * temp_f1);
    *(f32 *)((s8 *)arg1 + 8) = fn_8005EAD0(step, 0);
    *(s32 *)((s8 *)arg1 + 4) = calc_product(step, 0, 1);
}

void TBoss5Gryphon::fn_8005EBDC(u8 *arg1, Boss5GryphonActionStep *step) {
    f32 temp_f31;
    s32 temp_r31;
    s32 temp_r3;
    temp_r3 = random_in_table_range(step, 0);
    switch (temp_r3) {
    case 0:
        temp_r31 = (s32) (10430.38043493439 * atan2_float(position.x, position.z));
        temp_f31 = fn_8005EAD0(step, 1);
        *(f32 *)((s8 *)arg1 + 4) = (f32) (temp_f31 * ((f32 (*)(int))sin_table_lookup)(temp_r31));
        *(f32 *)((s8 *)arg1 + 8) = (f32) (temp_f31 * ((f32 (*)(int))cos_table_lookup)(temp_r31));
        break;
    case 1:
        *(f32 *)((s8 *)arg1 + 4) = fn_8005EAD0(step, 1);
        *(f32 *)((s8 *)arg1 + 8) = fn_8005EAD0(step, 2);
        break;
    }
    *(f32 *)((s8 *)arg1 + 0xC) = fn_8005EAD0(step, 0);
    *(s32 *)((s8 *)arg1 + 0x10) = random_in_table_range(step, 1);
}

void TBoss5Gryphon::calc_params(void *arg1, Boss5GryphonActionStep *step) {
    *(s32 *)((s8 *)arg1 + 4) = random_in_table_range(step, 1);
    *(f32 *)((s8 *)arg1 + 0xC) = fn_8005EAD0(step, 0);
    *(f32 *)((s8 *)arg1 + 0x10) = fn_8005EAD0(step, 1);
    *(s32 *)((s8 *)arg1 + 8) = get_random_sign(step, 0);
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::calc_product_and_ratio(void *arg1, Boss5GryphonActionStep *step) {
    *(s32 *)((s8 *)arg1 + 4) = calc_product(step, 0, 1);
    *(f32 *)((s8 *)arg1 + 8) = fn_8005EAD0(step, 0);
}
#pragma pop

typedef void (TBoss5Gryphon::*StateAction)(int);
#pragma push
#pragma inline on
static inline StateAction *dispatch_state_actions() {
static StateAction actions[35] = {
    (StateAction)&TBoss5Gryphon::state_action_noop,
    (StateAction)&TBoss5Gryphon::update_idle_state,
    (StateAction)&TBoss5Gryphon::update_ground_pursuit,
    (StateAction)&TBoss5Gryphon::wait_for_players,
    (StateAction)&TBoss5Gryphon::update_demo_state,
    (StateAction)&TBoss5Gryphon::update_death_state,
    (StateAction)&TBoss5Gryphon::update_ground_takeoff,
    (StateAction)&TBoss5Gryphon::update_shockwave_attack,
    (StateAction)&TBoss5Gryphon::fn_80062660,
    (StateAction)&TBoss5Gryphon::circle_arena,
    (StateAction)&TBoss5Gryphon::move_to_motion_destination,
    (StateAction)&TBoss5Gryphon::update_landing_attack,
    (StateAction)&TBoss5Gryphon::fn_80062114,
    (StateAction)&TBoss5Gryphon::update_low_flight_straight,
    (StateAction)&TBoss5Gryphon::update_low_flight_circle,
    (StateAction)&TBoss5Gryphon::update_bezier_descent,
    (StateAction)&TBoss5Gryphon::update_dive_motion,
    (StateAction)&TBoss5Gryphon::fn_800615FC,
    (StateAction)&TBoss5Gryphon::handle_descend_state,
    (StateAction)&TBoss5Gryphon::handle_takeoff_state,
    (StateAction)&TBoss5Gryphon::fn_800610D0,
    (StateAction)&TBoss5Gryphon::state_move,
    (StateAction)&TBoss5Gryphon::fn_80060D9C,
    (StateAction)&TBoss5Gryphon::fn_80060CA4,
    (StateAction)&TBoss5Gryphon::fn_80060BF8,
    (StateAction)&TBoss5Gryphon::fn_80060B18,
    (StateAction)&TBoss5Gryphon::fn_80060A58,
    (StateAction)&TBoss5Gryphon::update_ground_lightning_attack,
    (StateAction)&TBoss5Gryphon::fn_80060788,
    (StateAction)&TBoss5Gryphon::update_offscreen_climb,
    (StateAction)&TBoss5Gryphon::fn_80060020,
    (StateAction)&TBoss5Gryphon::update_roar_state,
    (StateAction)&TBoss5Gryphon::fn_8005FE18,
    (StateAction)&TBoss5Gryphon::fn_8005FD34,
    (StateAction)&TBoss5Gryphon::handle_message,
};
    return actions;
}
#pragma pop

void *lbl_8048802C[16] = {
    (void *)0x0, (void *)0x42860000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x42d60000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x43130000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x42820000, (void *)0x0, (void *)0x0,
};
#undef gryphon_particle_enable_pos
#undef gryphon_particle_position_vec
#undef __vt__13TBoss5Gryphon
void *boss5_gryphon_descend_bezier_points[16] = {
    (void *)0x0, (void *)0x42860000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x431d0000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x43998000, (void *)0x0, (void *)0x0,
    (void *)0x0, (void *)0x42820000, (void *)0x0, (void *)0x0,
};
void *lbl_804880AC[3] = {
    (void *)0xc1c80000, (void *)0x0, (void *)0x428a0000,
};
void *lbl_804880B8[3] = {
    (void *)0x41980000, (void *)0x0, (void *)0x428a0000,
};
void TBoss5Gryphon::copy_angle_state(void *arg0, void *dst, void *src) {
    *(s16 *)((s8 *)dst + 0) = (s16) *(s32 *)((s8 *)src + 0);
    *(s16 *)((s8 *)dst + 2) = ((TBoss5Gryphon *)arg0)->rand_scaled_offset(((Boss5GryphonActionStep *)src)->base, ((Boss5GryphonActionStep *)src)->spread);
}

s32 TBoss5Gryphon::run_action_script_step(s16 *out, u32 *entry) {
    TBoss5Gryphon *self = this;
    typedef void (TBoss5Gryphon::*Action)(void *, void *);
    static Action actions[35] = {
        0, 0, 0, 0, 0, 0, 0, 0,
        (Action)&TBoss5Gryphon::calc_product_and_ratio,
        (Action)&TBoss5Gryphon::calc_params,
        (Action)&TBoss5Gryphon::fn_8005EBDC,
        0, 0, 0,
        (Action)&TBoss5Gryphon::calc_attack_params,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        (Action)&TBoss5Gryphon::set_random_param,
        0, 0,
        (Action)&TBoss5Gryphon::set_random_param,
        0, 0, 0, 0,
    };
    Action *action;
    u32 index = *entry;

    TBoss5Gryphon::copy_angle_state(self, out, entry);
    action = actions + index;
    if (*action != NULL) {
        (self->**action)(out, entry);
    }
    if (index == 0x22) {
        return 1;
    }
    return 0;
}

void dispatch_action__13TBoss5GryphonFUll(TBoss5Gryphon *, s32, s32);

void *gryphon_particle_enable_pos[3] = {
    (void *)0x0, (void *)0xc61c4000, (void *)0x0,
};
void *gryphon_particle_position_vec[3] = {
    (void *)0x0, (void *)0xc61c4000, (void *)0x0,
};
void *__vt__13TBoss5Gryphon[107] = {
    (void *)0x0, (void *)0x0, (void *)&__dt__13TBoss5GryphonFv, (void *)&run_task__13TBoss5GryphonFv,
    (void *)&render__13TBoss5GryphonFv, (void *)&render_shadows__13TBoss5GryphonFv, (void *)&vfunc_6__8TObjBaseFPsl, (void *)&apply_object_set_data__8TObjBaseFPv,
    (void *)&reset_motion_fields__9TObjCharaFv, (void *)&get_center__9TObjCharaFv, (void *)&update_object_view_visibility__8TObjBaseFff, (void *)&classify_actor_view_detail__8TObjBaseFfff,
    (void *)&get_name__9TObjEnemyFv, (void *)&interact__14TObjCollidableFl, (void *)&add_actor_exp__9TObjCharaFl, (void *)&consume_timer_field__9TObjCharaFl,
    (void *)&get_actor_level_index__9TObjCharaFv, (void *)&update_actor_ground_y__9TObjCharaFv, (void *)&update_actor_ground_y_at__9TObjCharaFP3Vec, (void *)&is_actor_cadence_frame__9TObjCharaFl,
    (void *)&select_melee_contact_body__9TObjCharaFPvf, (void *)&calc_distance_accuracy_penalty__9TObjCharaFPvPvPvf, (void *)&receive_physical_attack__9TObjCharaFPvf, (void *)&receive_direct_attack__9TObjCharaFPv19DirectAttackPayloadPvll,
    (void *)&receive_weapon_special_attack__9TObjCharaFPvPv, (void *)&apply_knockback_from_attacker__9TObjCharaFPUcf, (void *)&try_start_action__9TObjCharaFll, (void *)&roll_physical_accuracy__9TObjCharaFPvlf,
    (void *)&refresh_target__13TBoss5GryphonFv, (void *)&has_no_target__9TObjCharaFv, (void *)&is_target_in_attack_range__9TObjCharaFv, (void *)&test_flag_256__9TObjCharaFv,
    (void *)&test_flag30_512__9TObjCharaFv, (void *)&has_flag_0x800__9TObjCharaFv, (void *)&test_flag_1000__9TObjCharaFv, (void *)&update_poison_status__9TObjCharaFv,
    (void *)&update_action_hold_status__9TObjCharaFv, (void *)&update_slow_status__9TObjCharaFv, (void *)&update_flag30_timer__9TObjCharaFv, (void *)&update_movement_status__9TObjCharaFv,
    (void *)&update_shock_clock__9TObjCharaFv, (void *)&update_attack_stat_status__9TObjCharaFv, (void *)&update_defense_stat_status__9TObjCharaFv, (void *)&vfunc_43__9TObjCharaFv,
    (void *)&apply_poison_status__13TBoss5GryphonFv, (void *)&apply_paralysis__13TBoss5GryphonFv, (void *)&apply_slow_status__13TBoss5GryphonFv, (void *)&apply_confusion_status__13TBoss5GryphonFv,
    (void *)&apply_movement_ailment__13TBoss5GryphonFl, (void *)&apply_shock_status__13TBoss5GryphonFv, (void *)&clear_harmful_statuses__13TBoss5GryphonFv, (void *)&apply_attack_stat_status__9TObjCharaFPv,
    (void *)&apply_defense_stat_status__9TObjCharaFPv, (void *)&cure_poison_ailment__9TObjCharaFv, (void *)&cure_paralysis__9TObjCharaFv, (void *)&clear_all_status_effects__9TObjCharaFv,
    (void *)&apply_action_hold_status__9TObjCharaFf, (void *)&apply_anti_technique__9TObjCharaFl, (void *)&run_idle_action__9TObjCharaFv, (void *)&run_move_action__9TObjCharaFv,
    (void *)&run_attack_action__9TObjCharaFv, (void *)&run_miss_reaction__13TBoss5GryphonFv, (void *)&run_hit_reaction__13TBoss5GryphonFv, (void *)&run_death_reaction__13TBoss5GryphonFv,
    (void *)&reset_pose__9TObjCharaFv, (void *)&get_anim_node_position__9TObjCharaFlP3Vec, (void *)&vfunc_66__9TObjCharaFv, (void *)&deliver_attack_hits__9TObjCharaFf,
    (void *)&get_pos__9TObjCharaFl, (void *)&apply_switch_attack__9TObjCharaFv, (void *)&enemy_spawn_jellen_effect__9TObjCharaFv, (void *)&trigger_switch_attack__9TObjCharaFv,
    (void *)&enemy_spawn_zalure_effect__9TObjCharaFv, (void *)&recalc_stats__9TObjCharaFv, (void *)&vfunc_74__9TObjEnemyFl, (void *)&gain_photon_blast_charge__9TObjCharaFf,
    (void *)&spend_photon_blast_charge__9TObjCharaFf, (void *)&gain_photon_blast_chain_charge__9TObjCharaFv, (void *)&vfunc_78__9TObjCharaFl, (void *)&apply_enemy_state__9TObjEneDDFPl,
    (void *)&apply_hit_message_flags__9TObjEnemyFPv, (void *)&apply_set_data__9TObjEnemyFPv, (void *)&clear_lobby_object_state__9TObjEnemyFv, (void *)&update_status_effects__12TObjEneDD_STFv,
    (void *)&update_immobilizing_statuses__9TObjEneDDFv, (void *)&update_action_state__9TObjEneDDFv, (void *)&has_action_state_changed__9TObjEneDDFv, (void *)&dispatch_action__13TBoss5GryphonFUll,
    (void *)&update_body_colliders__13TBoss5GryphonFv, (void *)&check_collisions__9TObjEneDDFv, (void *)&vfunc_90__9TObjEneDDFv, (void *)&set_invulnerable__9TObjEneDDFv,
    (void *)&clear_invulnerable__9TObjEneDDFv, (void *)&enable_body_collision__9TObjEneDDFv, (void *)&disable_body_collision__9TObjEneDDFv, (void *)&set_intangible__9TObjEneDDFv,
    (void *)&clear_intangible__9TObjEneDDFv, (void *)&set_colliders_contact_high__9TObjEneDDFv, (void *)&set_colliders_contact_low__9TObjEneDDFv, (void *)&is_confused__9TObjEneDDFv,
    (void *)&render_minimap_dot__9TObjEneDDFv, (void *)&move_xz_on_ground__9TObjEneDDFPUc, (void *)&update_ground_contact__9TObjEneDDFv, (void *)&snap_to_ground_at__9TObjEneDDFPUc,
    (void *)&acquire_target__12TObjEneDD_STFf, (void *)&run_demo_task__13TBoss5GryphonFv, (void *)&render_demo__13TBoss5GryphonFv,
};
#define gryphon_particle_enable_pos ((u8 *)gryphon_particle_enable_pos)
#define gryphon_particle_position_vec ((s32 *)gryphon_particle_position_vec)
#define __vt__13TBoss5Gryphon ((u8 *)__vt__13TBoss5Gryphon)

#define F(t, o) (*(t *)(arg0 + (o)))
#define TBL(o) (*(s32 *)((s8 *)(F(u8 *, 0x778)) + (o)))
#define LEVEL (*(s32 *)((s8 *)boss5_gryphon_behavior_params[2] + 0x28))
void choose_next_action__13TBoss5GryphonFPvPv(u8 *arg0, u32 *entry) {
    f32 r;
    if (*entry != 0x21) {
        ((TBoss5Gryphon *)arg0)->update_target_from_state();
        return;
    }
    r = lbl_805D8D98 * (f32)rand();
    switch (((TBoss5Gryphon *)arg0)->fn_8005E9D8((Boss5GryphonActionStep *)entry, 0)) {
    case 0:
        if (r < lbl_805D8DA0) {
            F(s32, 0x774) = TBL(8);
        } else if (r < lbl_805D8DA4) {
            F(s32, 0x774) = TBL(0xC);
        } else {
            F(s32, 0x774) = TBL(0x10);
        }
        break;
    case 1:
        if ((F(s32, 0x4C0) & 0x200) && LEVEL >= 5) {
            F(s32, 0x774) = TBL(0x24);
            F(s32, 0x4C0) &= ~0x200;
            break;
        }
        F(s32, 0x4C0) |= 0x200;
        if (r < gryphon_action_probability_table_a[LEVEL]) {
            F(s32, 0x774) = TBL(0x24);
            break;
        }
        r = (f32)F(s16, 0x32C) / (f32)F(s16, 0x2B8);
        if (lbl_805D8D98 * (f32)rand() < gryphon_action_probability_table_b[LEVEL]) {
            if (lbl_805D8D98 * (f32)rand() < r) {
                F(s32, 0x774) = TBL(0x1C);
            } else {
                F(s32, 0x774) = TBL(0x20);
            }
        } else {
            if (lbl_805D8D98 * (f32)rand() < r) {
                F(s32, 0x774) = TBL(0x14);
            } else {
                F(s32, 0x774) = TBL(0x18);
            }
        }
        break;
    case 2:
        if (r < gryphon_action_probability_table_a[LEVEL]) {
            F(s32, 0x774) = TBL(0x24);
        } else {
            F(s32, 0x774) = TBL(0x28);
        }
        break;
    case 3:
        if (r < lbl_805D8DA8) {
            F(s32, 0x774) = TBL(0x2C);
        } else if (r < lbl_805D8DAC) {
            F(s32, 0x774) = TBL(0x30);
        } else if (r < lbl_805D8DA0) {
            F(s32, 0x774) = TBL(0x34);
        } else if (r < lbl_805D8DB0) {
            F(s32, 0x774) = TBL(0x38);
        } else {
            F(s32, 0x774) = TBL(0x3C);
        }
        break;
    case 4:
        if (r < lbl_805D8DB4) {
            if (LEVEL >= 2) {
                F(s32, 0x774) = TBL(0x4C);
            } else {
                F(s32, 0x774) = TBL(0x40);
            }
        } else if (r < lbl_805D8DA0) {
            if (LEVEL >= 4) {
                F(s32, 0x774) = TBL(0x50);
            } else {
                F(s32, 0x774) = TBL(0x44);
            }
        } else {
            if (LEVEL >= 6) {
                F(s32, 0x774) = TBL(0x54);
            } else {
                F(s32, 0x774) = TBL(0x48);
            }
        }
        break;
    case 5:
        F(s32, 0x774) = TBL(0x58);
        break;
    case 6:
        F(s32, 0x774) = TBL(0x10);
        break;
    }
}

void TBoss5Gryphon::update_target_from_state() {
    s32 temp_r0;

    temp_r0 = this->flight_mode;
    switch (temp_r0) {
    default:
    case 0:
        this->m_774 = *(u8 **)((s8 *)(*(void **)((s8 *)this + 0x778)) + 0x40);
        return;
    case 1:
        this->m_774 = *(u8 **)((s8 *)(*(void **)((s8 *)this + 0x778)) + 8);
        return;
    case 3:
        this->m_774 = *(u8 **)((s8 *)(*(void **)((s8 *)this + 0x778)) + 0x60);
        return;
    case 2:
        this->m_774 = *(u8 **)((s8 *)(*(void **)((s8 *)this + 0x778)) + 0x5C);
        return;
    }
}

void TBoss5Gryphon::play_animation_index(s32 arg1) {
    struct { u8 pad[0x30]; } sp8;
    saddr temp_r5;
    ((TBoss8Dragon *)(&sp8))->init_color();
    temp_r5 = *(s32 *)((s8 *)((u8 *)this) + 0x778);
    this->m_774 = *(u8 **)((s8 *)temp_r5 + (arg1 * 4));
    ((s32 (*)(void *, void *, int))trigger_effect__12TBoss8DragonFPvi)(this, &sp8, temp_r5);
    TBoss8Dragon__sub_8005F684(this, &sp8);
    this->copy_spawn_params(&sp8);
}

void TBoss5Gryphon::set_animation_by_state() {
    m_4c0 |= 8;
    switch (flight_mode) {
    default:
    case 0:
        play_animation_index(0x19);
        return;
    case 1:
        play_animation_index(0x1A);
        return;
    case 3:
        play_animation_index(0x1B);
        return;
    case 2:
        play_animation_index(0x1C);
        return;
    }
}

void TBoss5Gryphon::init_state_zero() {
    play_animation_index(0);
}

void TBoss8Dragon__sub_8005F684(TBoss5Gryphon *self, void *params) {
    s32 i;
    u8 *out;

    if (self->m_774 == NULL) {
        self->update_target_from_state();
    }
    out = (u8 *)params + 0x14;
    for (i = 0; i < 1;) {
        u32 *entry = (u32 *)self->m_774;
        if (*entry == 0x21) {
            choose_next_action__13TBoss5GryphonFPvPv((u8 *)self, entry);
            continue;
        }
        if (self->run_action_script_step((s16 *)out, entry) != 0) {
            break;
        }
        i++;
        out += 0x14;
        self->m_774 += 0x48;
    }
}

void trigger_effect__12TBoss8DragonFPvi(void *arg0, s32 arg1) {
    init_motion_record(arg1 + 0x14);
}

void TBoss5Gryphon::flush_pending_effect() {
    P_8005F740 p;
    if ((this->m_4c0 & 2) && this->motion >= &this->motions[1]) {
        ((TBoss8Dragon *)(&p))->init_color();
        ((void (*)(void *, void *))trigger_effect__12TBoss8DragonFPvi)(this, &p);
        TBoss8Dragon__sub_8005F684(this, &p);
        this->m_4c0 &= ~2;
        copy_spawn_params(&p);
    }
}

void TBoss5Gryphon::refresh_target_periodically() {
    TBoss5Gryphon::update_linked_ground_position();
    if (!(this->targetRefreshCounter & 0x1F)) {
        if (enemy_validate_retained_target(this) != 0) {
            enemy_copy_target_destination();
        } else {
            this->set_target_destination(&lbl_80437938);
        }
        fn_80064AB0();
    }
    this->targetRefreshCounter = (this->targetRefreshCounter + 1);
}

void TBoss5Gryphon::scale_size(f32 scale, f32 farg1, f32 farg2) {
    this->pad_474.x = this->pad_474.x * scale;
    this->pad_474.y = this->pad_474.y * farg1;
    this->pad_474.z = this->pad_474.z * scale;
    this->m_480 = (s32)((f32)this->m_480 * farg2);
}

void TBoss5Gryphon::fire_at_angle(s32 ang) {
    turn_toward_angle_limited(ang, (s32)(10430.38043493439 * atan2_float(-position.x, -position.z)));
}

void TBoss5Gryphon::update_heading(s32 ang) {
    this->update_velocity();
    turn_toward_angle_limited(ang, (s32)(10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z)));
}

void TBoss5Gryphon::turn_toward_angle_limited(s32 ang, s32 target) {
    s32 t;
    s32 v;

    t = angle_diff_s16(rotation_y, target);
    t = angle_diff_s16((s32)((f32)t * lbl_805D8DA0), m_480);
    v = (t < -ang) ? -ang : ((t < ang) ? t : ang);
    m_480 = m_480 - v;
}

void TBoss5Gryphon::update_facing(f32 speed) {
    update_velocity();
    move_along_angle(speed, (s32)(10430.38043493439 * atan2_float(destination_direction.x, destination_direction.z)));
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::move_along_angle(f32 speed, s32 ang) {
    pad_474.x = (speed * sin_table_lookup(ang)) + pad_474.x;
    pad_474.z = (speed * cos_table_lookup(ang)) + pad_474.z;
}
#pragma pop

s32 TBoss5Gryphon::fn_8005FAE0() {
    return play_speed <= 0.0f;
}

void TBoss5Gryphon::advance_motion_entry() {
    s16 *ptr;
    ptr = (s16 *) (*(saddr *)((s8 *)this + 0x4BC) + 0x14);
    *(s32 *)((s8 *)this + 0x4BC) = (saddr) ptr;
    ptr = (s16 *) *(saddr *)((s8 *)this + 0x4BC);
    if ((s16) this->mode != *ptr) {
        transition_enemy_state(*ptr);
    }
}

void TBoss5Gryphon::advance_motion_timer() {
    int temp_r4;
    void *temp_r5;
    void *temp_r4b;

    if ((s16) this->mode != 4) {
        temp_r5 = *(void **)((s8 *)this + 0x4BC);
        temp_r4 = (s16) *(s16 *)((s8 *)temp_r5 + 2);
        if (temp_r4 > 0) {
            *(s16 *)((s8 *)temp_r5 + 2) = (temp_r4 - 1);
            temp_r4b = *(void **)((s8 *)this + 0x4BC);
            if (*(s16 *)((s8 *)temp_r4b + 2) == 0) {
                advance_motion_entry();
            }
        }
    }
}

void TBoss5Gryphon::fn_8005FB90() {
    position.x = position.x + pad_484.x;
    position.z = position.z + pad_484.z;
    pad_484.x = 0.0f;
    pad_484.y = 0.0f;
    pad_484.z = 0.0f;
}

#pragma push
#pragma pool_data off
void TBoss5Gryphon::apply_velocity() {
    Shot_8005FBC4 shot;
    Vec v;
    f32 len;
    if (((Obj_8005FBC4 *)this)->flags & 0x10) {
        ((Obj_8005FBC4 *)this)->pos.y += ((Obj_8005FBC4 *)this)->vel.y;
        ((Obj_8005FBC4 *)this)->f60 += ((Obj_8005FBC4 *)this)->f480;
        v.x = ((Obj_8005FBC4 *)this)->vel.x;
        v.y = 0.0f;
        v.z = ((Obj_8005FBC4 *)this)->vel.z;
        len = normalize_vector_xz((Vec *)(&v));
        this->calc_shot_position((u8 *)&shot, (f32)v.x, (f32)v.z, (f32)len);
        this->try_move_actor_xz_on_ground((u8 *)&shot);
    } else {
        ((Obj_8005FBC4 *)this)->pos.x += ((Obj_8005FBC4 *)this)->vel.x;
        ((Obj_8005FBC4 *)this)->pos.y += ((Obj_8005FBC4 *)this)->vel.y;
        ((Obj_8005FBC4 *)this)->pos.z += ((Obj_8005FBC4 *)this)->vel.z;
        ((Obj_8005FBC4 *)this)->f60 += ((Obj_8005FBC4 *)this)->f480;
    }
    if (!(((Obj_8005FBC4 *)this)->flags & 0x20)) {
        this->scale_size(boss5_gryphon_scale_x_table[((Obj_8005FBC4 *)this)->f4e4], boss5_gryphon_scale_y_table[((Obj_8005FBC4 *)this)->f4e4], gryphon_velocity_scale_z_table[((Obj_8005FBC4 *)this)->f4e4]);
    }
}
#pragma pop

void TBoss5Gryphon::handle_message(s32 msg) {
    O_8005FCE4 *self = (O_8005FCE4 *)this;
    switch (msg) {
    case 4:
        self->flags |= 0x80;
        ((TObject *)self)->queue_destruction();
        break;
    case 5:
        break;
    case 6: case 7: case 8: case 9: case 10: case 11:
        return;
    }
}

void TBoss5Gryphon::fn_8005FD34(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        switch (self->flight_mode) {
        case 0:
            self->requested_action = 0;
            break;
        case 1:
            self->requested_action = 4;
            break;
        case 2:
            self->requested_action = 7;
            break;
        }
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->flight_mode) {
        case 0:
            break;
        case 1:
            self->fn_80063EF4();
            break;
        case 2:
            move_along_angle(lbl_805D8D90, self->rotation_y);
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::fn_8005FE18(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x17;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        self->m_4c0 &= ~4;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        if (((TObjMotion *)self)->is_passing_frame(lbl_805D8D80) != 0) {
            self->play_se(0x4003A817);
        }
        if (self->fn_8005FAE0() != 0) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

#pragma push
#pragma fp_contract on
#define PLAY_SE(o, id) ((TBoss5Gryphon *)o)->play_se((id))
extern const f32 lbl_805D8DB8;

void TBoss5Gryphon::update_roar_state(s32 event) {
    TBoss5Gryphon *self = this;
    Vec pos;
    Vec *bones;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 2;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        if (((TObjMotion *)self)->is_passing_frame(lbl_805D8DB8) != 0) {
            bones = (Vec *)((u8 *)self + 0x3C0);
            pos.x = 0.5f * (bones[1].x + bones[2].x);
            pos.y = 0.5f * (bones[1].y + bones[2].y);
            pos.z = 0.5f * (bones[1].z + bones[2].z);
            new TBoss5GryphonSnarl((TObject *)&self->m_4c4, &pos);
            TCameraCtrl::set_shake_preset(1);
            self->play_se(0x40032306);
        }
        if (self->fn_8005FAE0() != 0) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

#pragma pop

extern const f32 lbl_805D8DE8;
extern const f32 lbl_805D8DF0;

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::fn_80060020(u32 arg1) {
    Dragon_80060020 *self = (Dragon_80060020 *)this;
    Vec w;
    Vec v;
    Vec p;
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        self->fB8 = 0x14;
        ((TBoss5Gryphon *)self)->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_offscreen_mode();
        ((TBoss5Gryphon *)self)->set_offscreen_height();
        self->f4C0 |= 4;
        PLAY_SE(self, 0x4003A818);
        subtractive_rng_seed(self->f5F4, self->f4BC->f4);
        self->f5C = 0x4000;
        self->f6E8 = 0;
        self->f6E0 = (f32)self->f4BC->h2 - TWindowSubStatusDisp::round_away_from_zero(lbl_805D8DBC);
        self->f6F4 = lbl_805D8DC4 / ((f32)self->f4BC->h2 - TWindowSubStatusDisp::round_away_from_zero(lbl_805D8DC0));
        self->f6DC = 0;
        break;
    case ENEMY_STATE_UPDATE:
        ((TObjMotion *)self)->advance_animation();
        switch (self->f6DC) {
        case 0: {
            u8 *pl;
            s32 a2;
            s32 ang;
            s32 found;
            f32 r;
            f32 xx = self->pos.x * self->pos.x;
            f32 zz = self->pos.z * self->pos.z;
            if (xx + zz > lbl_805D8DC8) {
                ((TBoss5Gryphon *)self)->fire_at_angle(0x100);
            } else {
                ((TBoss5Gryphon *)self)->update_heading(0x100);
            }
            ((TBoss5Gryphon *)self)->update_facing(lbl_805D8D90);
            self->pos.y -= self->f6F4;
            self->f64 += 0x3311;
            if (self->f6E8 >= self->f6E0) {
                self->fB8 = 0x16;
                fn_800660B8((u8 *)self);
                self->f6DC = 1;
            }
            found = 0;
            ang = 65536.0f * calc_random_ratio__10TObjPlayerFv(self->f5F4);
            r = calc_random_ratio__10TObjPlayerFv(self->f5F4);
            if (calc_random_ratio__10TObjPlayerFv(self->f5F4) > 0.5f) {
                pl = ((u8 *(*)(u16))get_player_by_client_id)((s32)(lbl_805D8DCC * calc_random_ratio__10TObjPlayerFv(self->f5F4)));
                if (((TObjBase *)pl)->is_alive() != 0) {
                    Hit_80060020 *hit;
                    r *= lbl_805D8DD0;
                    do {
                        v.x = r * sin_table_lookup(ang) + ((Vec *)(pl + 0x38))->x;
                        v.y = lbl_805D8DD0 + ((Vec *)(pl + 0x38))->y;
                        v.z = r * cos_table_lookup(ang) + ((Vec *)(pl + 0x38))->z;
                        hit = (Hit_80060020 *)csnVecterUnder(&v, 0x16EF);
                        ang += 0x2000;
                    } while (hit == NULL || hit->p->y > 6.0f);
                    found = 1;
                }
            }
            if (found == 0) {
                Hit_80060020 *hit;
                r *= lbl_805D8DD4;
                do {
                    v.x = r * sin_table_lookup(ang);
                    v.y = 0.0f;
                    v.z = r * cos_table_lookup(ang);
                    hit = (Hit_80060020 *)csnVecterUnder(&v, 0x16EF);
                    r -= lbl_805D8DCC;
                } while (hit == NULL || hit->p->y > 6.0f);
            }
            {
                a2 = 10430.38043493439 * atan2_float(v.x - self->pos.x, v.z - self->pos.z);
                w.x = lbl_805D8DD0 * sin_table_lookup(a2) + self->pos.x;
                w.y = lbl_805D8DD0 + self->pos.y;
                w.z = lbl_805D8DD0 * cos_table_lookup(a2) + self->pos.z;
            }
            if (self->f6E8 % 5 == 0) {
                fn_80351DA8(self, &w, &v, 0x28, 0x11);
            }
            if (self->f6E8 == 0x14) {
                PLAY_SE(self, 0x40033C12);
            }
            self->f6E8++;
            break;
        }
        case 1: {
            f32 s;
            ((TBoss5Gryphon *)self)->move_along_angle(lbl_805D8D88, self->f60);
            self->pos.y -= self->f6F4;
            s = ((TObjEneDD_ST *)self)->get_motion_frame();
            self->f5C = 65536.0f - lbl_805D8DD8 * (lbl_805D8D88 - s / lbl_805D8DDC);
            self->f64 = lbl_805D8DE0 * (lbl_805D8DDC - s) * (lbl_805D8DDC - s);
            if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8DDC) != 0) {
                self->f5C = 0;
                self->f64 = 0;
                self->f6DC = 2;
            }
            break;
        }
        case 2:
            ((TBoss5Gryphon *)self)->move_along_angle(lbl_805D8D88, self->f60);
            self->pos.y -= self->f6F4;
            if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8DE4) != 0) {
                ((TBoss5Gryphon *)self)->enter_ground_mode();
                ((TBoss5Gryphon *)self)->set_ground_height();
                PLAY_SE(self, 0x40032D0D);
                p.x = self->pos.x;
                p.y = 0.0f;
                p.z = self->pos.z;
                spawn_particle_effect_with_flags(&p, self->f5F0->f4, 0x40);
                TCameraCtrl::set_shake_preset(1);
                ((TBoss5Gryphon *)self)->fn_800646F0();
                self->f6DC = 3;
            }
            break;
        case 3:
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        self->f5C = 0;
        self->f64 = 0;
        self->f4C0 &= ~4;
        break;
    case 8:
        switch (self->f6DC) {
        case 0:
        case 1:
            ((TBoss5Gryphon *)self)->refresh_target_periodically();
            break;
        case 2:
        case 3:
            break;
        }
        break;
    case 11:
        break;
    }
}
#pragma pop

void TBoss5Gryphon::update_offscreen_climb(s32 event) {
    TBoss5Gryphon *self = this;
    f32 speed;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x13;
        self->clear_intangible();
        set_flag_4e4();
        self->set_flight_height();
        self->m_4c0 |= 4;
        self->m_6e0 = 0;
        self->m_6dc = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->m_6dc) {
        case 0: {
            f32 t;
            speed = lbl_805D8DE8;
            t = self->get_motion_frame();
            self->position.y = lbl_805D8DEC + lbl_805D8DF0 * (t * t) / lbl_805D8DF4;
            if (((TObjMotion *)self)->is_passing_frame(lbl_805D8DF8) != 0) {
                self->m_6e0 = 0;
                self->m_6dc = 1;
            }
            break;
        }
        case 1:
            self->position.y += lbl_805D8D8C;
            speed = lbl_805D8DE8;
            self->m_6e0++;
            if (self->m_6e0 >= 0x28) {
                ((TBoss5Gryphon *)self)->enter_offscreen_mode();
                ((TBoss5Gryphon *)self)->set_offscreen_height();
                self->rotation_x = 0x4000;
                self->advance_motion_entry();
            }
            break;
        }
        move_along_angle(speed, self->rotation_y);
        break;
    case ENEMY_STATE_LEAVE:
        self->m_4c0 &= ~4;
        ((TBoss5Gryphon *)self)->enter_offscreen_mode();
        ((TBoss5Gryphon *)self)->set_offscreen_height();
        self->rotation_x = 0x4000;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::fn_80060788(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x12;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        if (((TObjMotion *)self)->is_passing_frame(6.0f) != 0) {
            self->play_se(0x40032D10);
        }
        if (self->fn_8005FAE0() != 0) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::update_ground_lightning_attack(s32 event) {
    TBoss5Gryphon *self = this;
    Vec left;
    Vec right;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x11;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        self->demo->draw_linked_model(&self->position, self->rotation_y);
        self->m_6e4 = 0;
        push_matrix();
        set_matrix_identity(NULL);
        post_translate_matrix(&self->position);
        rotate_matrix_y(0, self->rotation_y);
        matrix_mult_vec(0, lbl_804880AC, &left);
        matrix_mult_vec(0, lbl_804880B8, &right);
        pop_matrix();
        self->m_6dc = TBoss8Dragon::spawn_ground_lightning((saddr)self, (saddr)&left, self->rotation_y);
        self->m_6e0 = TBoss8Dragon::spawn_ground_lightning((saddr)self, (saddr)&right, self->rotation_y);
        subtractive_rng_seed(self->rng, self->motion->m_4);
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        self->fn_800641A8();
        if (*(s32 *)((u8 *)boss5_gryphon_behavior_params[2] + 0x28) >= 2) {
            self->spawn_lightning_effect();
            apply_lightning_hit((saddr)self, (saddr)&self->position, lbl_805D8DF0);
        }
        if (*(s32 *)((u8 *)boss5_gryphon_behavior_params[2] + 0x28) >= 4 && self->m_6e4 % 20 == 0) {
            TBoss8Dragon__sub_8005D9BC((u8 *)self, (self->m_6e4 / 20) & 1 ? 0 : 1, lbl_805D8DCC * calc_random_ratio__10TObjPlayerFv(self->rng));
        }
        self->spawn_ancient_trap(0x40032D11);
        self->m_6e4++;
        break;
    case ENEMY_STATE_LEAVE:
        if ((TBoss8Dragon *)self->m_6e0 != NULL) {
            ((TBoss8Dragon *)self->m_6e0)->queue_destruction();
            self->m_6e0 = 0;
        }
        if ((TBoss8Dragon *)self->m_6dc != NULL) {
            ((TBoss8Dragon *)self->m_6dc)->queue_destruction();
            self->m_6dc = 0;
        }
        self->demo->get_state();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

extern const f32 lbl_805D8DFC;

void TBoss5Gryphon::fn_80060A58(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x10;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        if (((TObjMotion *)self)->is_passing_frame(lbl_805D8DFC) != 0) {
            self->play_se(0x4003320F);
        }
        if (self->action_flags == 0x11) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::fn_80060B18(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0xF;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        self->demo->draw_linked_model(&self->position, self->rotation_y);
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        self->fn_800641A8();
        if (((TObjMotion *)self)->is_passing_frame(lbl_805D8DF8) != 0) {
            self->demo->get_state();
        }
        if (self->fn_8005FAE0() != 0) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->demo->get_state();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::fn_80060BF8(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0xE;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        self->demo->draw_linked_model(&self->position, self->rotation_y);
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        self->fn_800641A8();
        break;
    case ENEMY_STATE_LEAVE:
        self->demo->get_state();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::fn_80060CA4(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0xD;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        self->fn_800641A8();
        if (((TObjMotion *)self)->is_passing_frame(lbl_805D8DDC) != 0) {
            self->demo->draw_linked_model(&self->position, self->rotation_y);
        }
        if (((TObjMotion *)self)->is_passing_frame(lbl_805D8D88) != 0) {
            self->play_se(0x40032D0E);
        }
        if (self->action_flags == 0xE) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->demo->get_state();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::fn_80060D9C(s32 event) {
    TBoss5Gryphon *self = this;
    Vec at;
    f32 v;
    f32 speed;
    f32 scale;
    f32 depth;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0xC;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        self->m_4c0 |= 0x30;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        v = self->get_motion_frame();
        speed = 0.0f;
        if (v < lbl_805D8E00) {
            depth = lbl_805D8E04;
            scale = lbl_805D8DA4;
        } else {
            depth = lbl_805D8E04;
            scale = lbl_805D8E08;
        }
        if (((TObjMotion *)self)->is_passing_frame(lbl_805D8D90) != 0) {
            speed += lbl_805D8E0C;
        }
        self->scale_size(scale, depth, depth);
        move_along_angle(speed, self->rotation_y);
        if (((TObjMotion *)self)->is_passing_frame(lbl_805D8E00) != 0) {
            at.x = self->position.x;
            at.y = 0.0f;
            at.z = self->position.z;
            spawn_particle_effect_with_flags(&at, self->effect_ids[1], 0x40);
            self->fn_800646F0();
            self->play_se(0x40032D0D);
        }
        if (self->fn_8005FAE0() != 0) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->m_4c0 &= ~0x30;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::state_move(s32 arg1) {
    f32 speed;
    f32 scale;
    f32 depth;
    f32 v;
    s32 ang;
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        ((Obj_80060F4C *)this)->fb8 = 0xB;
        this->clear_intangible();
        this->enter_ground_mode();
        this->set_ground_height();
        ((Obj_80060F4C *)this)->flags |= 0x30;
        return;
    case 8:
        this->refresh_target_periodically();
        return;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        fn_80064DB8();
        this->update_velocity();
        fn_8006426C();
        fn_80064828();
        v = this->get_motion_frame();
        if (v < lbl_805D8E10 || v >= lbl_805D8DE4) {
            depth = lbl_805D8E04;
            ang = 0;
            speed = 0.0f;
            scale = lbl_805D8DA4;
        } else {
            depth = lbl_805D8E04;
            ang = 0xD0;
            speed = lbl_805D8D88;
            scale = lbl_805D8E08;
        }
        if (is_passing_frame(0.5f) != 0) {
            ang += 0x500;
            speed += lbl_805D8E14;
        }
        this->scale_size(scale, depth, depth);
        move_along_angle(speed, ((Obj_80060F4C *)this)->f60);
        this->update_heading(ang);
        return;
    case ENEMY_STATE_LEAVE:
        ((Obj_80060F4C *)this)->flags &= ~0x30;
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

void TBoss5Gryphon::fn_800610D0(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0xA;
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        if (self->action_flags == 0xB) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

extern const f32 lbl_805D8E38;
extern const f32 lbl_805D8E18;
extern const f32 lbl_805D8E1C;
extern const f32 lbl_805D8E24;
extern const f32 lbl_805D8E28;
extern const f32 lbl_805D8E2C;
extern const f32 lbl_805D8E30;

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::handle_takeoff_state(s32 event) {
    TBoss5Gryphon *self = this;
    f32 speed;
    f32 f;
    f32 d;
    s32 t;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x14;
        self->clear_intangible();
        set_flag_4e4();
        self->set_flight_height();
        self->m_4c0 |= 4;
        self->update_particle_positions();
        self->m_6dc = 0;
        self->m_6e0 = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->m_6dc) {
        case 0:
            t = self->m_6e0;
            speed = lbl_805D8E18;
            if ((f32)t < *(const f32 *)&lbl_805D8E1C) {
                f = (f32)t;
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E1C));
                d = -lbl_805D8E24 * d + lbl_805D8E24;
                self->position.y = lbl_805D8E20 + d;
            } else {
                f = (f32)(0x27 - t);
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E1C));
                d = lbl_805D8E24 * d + lbl_805D8E24;
                self->position.y = lbl_805D8E20 + d;
            }
            self->rotation_x = (s32)(-(lbl_805D8E2C * f) / lbl_805D8E1C);
            self->m_6e0++;
            if (self->m_6e0 == 0xB) {
                self->requested_action = 0x15;
            } else if (self->m_6e0 > 0x27) {
                self->position.y = lbl_805D8E30;
                self->rotation_x = 0;
                self->m_6dc = 1;
            }
            if (((TObjMotion *)self)->is_passing_frame(lbl_805D8DDC) != 0) {
                self->spawn_ground_splash();
            }
            break;
        case 1: {
            f32 phase_speed;
            f32 base;
            speed = lbl_805D8E34;
            phase_speed = self->get_motion_frame();
            base = lbl_805D8E0C;
            phase_speed -= base;
            d = self->frame_count - base;
            self->position.y = lbl_805D8E30 - lbl_805D8DD0 *
                sin_table_lookup((s32)(lbl_805D8E28 * phase_speed / d));
            if (self->fn_8005FAE0() != 0) {
                self->advance_motion_entry();
            }
            break;
        }
        }
        move_along_angle(speed, self->rotation_y);
        break;
    case ENEMY_STATE_LEAVE:
        self->m_4c0 &= ~0x104;
        self->free_parts();
        self->position.y = lbl_805D8DEC;
        self->rotation_x = 0;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}
#pragma pop

void TBoss5Gryphon::handle_descend_state(s32 arg1) {
    TBoss5Gryphon *self = this;
    Vec out;
    Vec at;

    switch (arg1) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x16;
        ((TBoss5Gryphon *)self)->clear_intangible();
        set_flag_4e4();
        self->set_flight_height();
        *(u32 *)((s8 *)self + 0x4C0) |= 4;
        self->update_particle_positions();
        *(s32 *)((s8 *)self + 0x6DC) = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (*(s32 *)((s8 *)self + 0x6DC)) {
        case 0:
            move_along_angle(lbl_805D8E38, self->rotation_y);
            TBoss8Dragon::eval_bezier_curve(boss5_gryphon_descend_bezier_points, 4, 0, &out, ((TObjEneDD_ST *)self)->get_motion_frame() / lbl_805D8DE4);
            *(f32 *)((s8 *)self + 0x3C) = out.y;
            if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8DE4) != 0) {
                ((TBoss5Gryphon *)self)->enter_ground_mode();
                ((TBoss5Gryphon *)self)->set_ground_height();
                self->play_se(0x40032D0D);
                at.x = *(f32 *)((s8 *)self + 0x38);
                at.y = 0.0f;
                at.z = *(f32 *)((s8 *)self + 0x40);
                spawn_particle_effect_with_flags(&at, *(s32 *)((s8 *)(*(u8 **)((s8 *)self + 0x5F0)) + 4), 0x40);
                TCameraCtrl::set_shake_preset(1);
                self->fn_800646F0();
                *(s32 *)((s8 *)self + 0x6DC) = 1;
            }
            break;
        case 1:
            if (self->fn_8005FAE0() != 0) {
                self->advance_motion_entry();
            }
            break;
        }
        if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8DCC) != 0) {
            self->spawn_ground_splash();
        }
        break;
    case ENEMY_STATE_LEAVE:
        *(u32 *)((s8 *)self + 0x4C0) &= ~0x104;
        self->free_parts();
        break;
    case 10: case 11:
    default:
        break;
    }
}

extern const f32 lbl_805D8E3C;
extern const f32 lbl_805D8E40;
extern const f32 lbl_805D8E44;

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::fn_800615FC(s32 event) {
    TBoss5Gryphon *self = this;
    f32 speed;
    f32 f;
    f32 d;
    s32 t;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0x13;
        self->clear_intangible();
        set_flag_4e4();
        self->set_flight_height();
        self->m_4c0 |= 0x104;
        self->m_6dc = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->m_6dc) {
        case 0:
            speed = lbl_805D8E34;
            self->position.y = 20.0f * sin_table_lookup((s32)(lbl_805D8E28 * self->get_motion_frame() / lbl_805D8E14)) + lbl_805D8DEC;
            if (((TObjMotion *)self)->is_passing_frame(lbl_805D8E14) != 0) {
                self->m_6dc = 1;
                self->m_6e0 = 0;
            }
            break;
        case 1:
            t = self->m_6e0;
            speed = lbl_805D8E3C;
            if ((f32)t < *(const f32 *)&lbl_805D8E10) {
                f = (f32)t;
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E10));
                d = lbl_805D8E40 * d + lbl_805D8E40;
                self->position.y = lbl_805D8E20 + d;
            } else {
                f = (f32)(0x14 - t);
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E10));
                d = -lbl_805D8E40 * d + lbl_805D8E40;
                self->position.y = lbl_805D8E20 + d;
            }
            self->rotation_x = (s32)(lbl_805D8E44 * f / lbl_805D8E10);
            self->m_6e0++;
            if (self->m_6e0 > 0x14) {
                ((TBoss5Gryphon *)self)->enter_low_flight_mode();
                ((TBoss5Gryphon *)self)->set_low_flight_height();
                self->rotation_x = 0;
                self->m_6dc = 2;
            }
            break;
        case 2:
            speed = lbl_805D8E3C;
            if (self->action_flags == 0x14) {
                self->advance_motion_entry();
            }
            break;
        }
        move_along_angle(speed, self->rotation_y);
        if (((TObjMotion *)self)->is_passing_frame(lbl_805D8DF8) != 0) {
            self->spawn_ground_splash();
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->m_4c0 &= ~4;
        ((TBoss5Gryphon *)self)->enter_low_flight_mode();
        ((TBoss5Gryphon *)self)->set_low_flight_height();
        self->rotation_x = 0;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}
#pragma pop

extern const f32 lbl_805D8E4C;
extern const f32 lbl_805D8E48;
extern const f32 lbl_805D8E50;
#pragma push
#pragma fp_contract on
void TBoss5Gryphon::update_dive_motion(s32 arg1) {
    u8 *self = (u8 *)this;
    f32 speed;
    f32 f;
    f32 d;
    s32 t;

    switch (arg1) {
    case 10:
    case 11:
        break;
    case ENEMY_STATE_ENTER:
        this->requested_action = 7;
        ((TBoss5Gryphon *)self)->clear_intangible();
        set_flag_4e4();
        ((TBoss5Gryphon *)self)->set_flight_height();
        *(s32 *)((s8 *)self + 0x4C0) |= 4;
        ((TBoss5Gryphon *)self)->enable_particles();
        *(s32 *)((s8 *)self + 0x6DC) = 0;
        *(s32 *)((s8 *)self + 0x6E0) = 0;
        break;
    case ENEMY_STATE_UPDATE:
        ((TObjMotion *)self)->advance_animation();
        switch (*(s32 *)((s8 *)self + 0x6DC)) {
        case 0:
            t = *(s32 *)((s8 *)self + 0x6E0);
            speed = lbl_805D8E18;
            if ((f32)t < *(const f32 *)&lbl_805D8E1C) {
                f = (f32)t;
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E1C));
                d = -lbl_805D8E48 * d + lbl_805D8E48;
                *(f32 *)((s8 *)self + 0x3C) = lbl_805D8E20 + d;
            } else {
                f = (f32)(0x27 - t);
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E1C));
                d = lbl_805D8E48 * d + lbl_805D8E48;
                *(f32 *)((s8 *)self + 0x3C) = lbl_805D8E20 + d;
            }
            this->rotation_x = (s32)(-(lbl_805D8E2C * f) / lbl_805D8E1C);
            (*(s32 *)((s8 *)self + 0x6E0))++;
            if (*(s32 *)((s8 *)self + 0x6E0) == 0x11) {
                this->requested_action = 8;
            } else if (*(s32 *)((s8 *)self + 0x6E0) > 0x27) {
                *(f32 *)((s8 *)self + 0x3C) = lbl_805D8E4C;
                this->rotation_x = 0;
                *(s32 *)((s8 *)self + 0x6DC) = 1;
            }
            break;
        case 1:
            speed = lbl_805D8E34;
            f = this->frame_count - lbl_805D8E10;
            d = ((TObjEneDD_ST *)self)->get_motion_frame() - lbl_805D8E10;
            *(f32 *)((s8 *)self + 0x3C) = lbl_805D8E4C - lbl_805D8E50 * sin_table_lookup((s32)(lbl_805D8E28 * d / f));
            if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8DE4) != 0) {
                ((TBoss5Gryphon *)self)->spawn_ground_splash();
            }
            if (fn_8005FAE0() != 0) {
                ((TBoss5Gryphon *)self)->advance_motion_entry();
            }
            break;
        }
        move_along_angle(speed, this->rotation_y);
        break;
    case ENEMY_STATE_LEAVE:
        *(s32 *)((s8 *)self + 0x4C0) &= ~4;
        ((TBoss5Gryphon *)self)->destroy_parts();
        this->rotation_x = 0;
        break;
    }
}

#pragma pop

void TBoss5Gryphon::update_bezier_descent(s32 event) {
    TBoss5Gryphon *self = this;
    Vec out;
    Vec at;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 9;
        self->clear_intangible();
        set_flag_4e4();
        self->set_flight_height();
        self->m_4c0 |= 4;
        self->enable_particles();
        self->m_6dc = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->m_6dc) {
        case 0:
            move_along_angle(lbl_805D8E38, self->rotation_y);
            TBoss8Dragon::eval_bezier_curve(lbl_8048802C, 4, 0, &out, self->get_motion_frame() / 20.0f);
            self->position.y = out.y;
            if (((TObjMotion *)self)->is_passing_frame(20.0f) != 0) {
                ((TBoss5Gryphon *)self)->enter_ground_mode();
                ((TBoss5Gryphon *)self)->set_ground_height();
                self->play_se(0x40032D0D);
                at.x = self->position.x;
                at.y = 0.0f;
                at.z = self->position.z;
                spawn_particle_effect_with_flags(&at, self->effect_ids[1], 0x40);
                TCameraCtrl::set_shake_preset(1);
                self->fn_800646F0();
                self->m_6dc = 1;
            }
            break;
        case 1:
            if (self->fn_8005FAE0() != 0) {
                self->advance_motion_entry();
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->m_4c0 &= ~4;
        self->destroy_parts();
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

extern const f32 lbl_805D8E54;

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::update_low_flight_circle(s32 event) {
    s32 ofs;
    s32 a;
    s32 d;
    s32 v;
    f32 speed;

    switch (event) {
    case ENEMY_STATE_ENTER:
        if (this->m_4c0 & 0x100) {
            this->requested_action = 0x14;
        } else {
            this->requested_action = 7;
        }
        this->clear_intangible();
        this->enter_low_flight_mode();
        this->set_low_flight_height();
        break;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        ofs = 0x4000;
        if (this->position.x * this->position.x + this->position.z * this->position.z > this->motion->m_c) {
            ofs = 0x5000;
        }
        speed = this->motion->m_8;
        a = (s32)(10430.38043493439 * atan2_float(this->position.x, this->position.z));
        if (this->motion->m_4 > 0) {
            a += ofs;
            d = angle_diff_s16(this->rotation_y, a);
            if (d > 0) {
                this->m_480 += this->motion->m_4;
            }
        } else {
            a -= ofs;
            d = angle_diff_s16(this->rotation_y, a);
            if (d < 0) {
                this->m_480 += this->motion->m_4;
            }
        }
        if (fabs_float((f32)d) > lbl_805D8E44) {
            speed *= lbl_805D8DB0;
        }
        move_along_angle(speed, this->rotation_y);
        if ((f32)this->motion->timer > 6.0f) {
            v = (s32)(lbl_805D8E54 * (f32)this->m_480);
            v = (v < -0x600) ? -0x600 : ((v < 0x600) ? v : 0x600);
            d = angle_diff_s16(this->rotation_z, v);
            this->rotation_z = (s32)(lbl_805D8DB4 * (f32)d + (f32)this->rotation_z);
        } else {
            this->rotation_z -= this->rotation_z / this->motion->timer;
        }
        if (this->m_4c0 & 0x100) {
            fn_8006435C();
            fn_8005E39C();
        } else {
            fn_8006442C();
            this->update_ground_effects();
            spawn_ancient_trap(0x40032802);
        }
        break;
    case ENEMY_STATE_LEAVE:
        this->rotation_z = 0;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}
#pragma pop

extern const f32 lbl_805D8E58;

void TBoss5Gryphon::update_low_flight_straight(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        if (self->m_4c0 & 0x100) {
            self->requested_action = 0x14;
        } else {
            self->requested_action = 7;
        }
        self->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_low_flight_mode();
        ((TBoss5Gryphon *)self)->set_low_flight_height();
        self->m_6e0 = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        move_along_angle(lbl_805D8E58, self->rotation_y);
        if (self->m_4c0 & 0x100) {
            self->fn_8006435C();
            self->fn_8005E39C();
        } else {
            self->fn_8006442C();
            self->update_ground_effects();
            self->spawn_ancient_trap(0x40032802);
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}


#pragma push
#pragma fp_contract on
void TBoss5Gryphon::fn_80062114(s32 event) {
    TBoss5Gryphon *self = this;
    f32 speed;
    f32 f;
    f32 d;
    s32 t;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 6;
        self->clear_intangible();
        set_flag_4e4();
        self->set_flight_height();
        self->m_4c0 |= 4;
        self->m_6dc = 0;
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        switch (self->m_6dc) {
        case 0:
            speed = lbl_805D8E34;
            self->position.y = lbl_805D8E50 * sin_table_lookup((s32)(lbl_805D8E28 * self->get_motion_frame() / lbl_805D8E5C)) + lbl_805D8DEC;
            if (((TObjMotion *)self)->is_passing_frame(lbl_805D8E5C) != 0) {
                self->m_6dc = 1;
                self->m_6e0 = 0;
            }
            break;
        case 1:
            t = self->m_6e0;
            speed = lbl_805D8E3C;
            if ((f32)t < *(const f32 *)&lbl_805D8E00) {
                f = (f32)t;
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E00));
                d = lbl_805D8E48 * d + lbl_805D8E48;
                self->position.y = lbl_805D8E20 + d;
            } else {
                f = (f32)(0x1E - t);
                d = cos_table_lookup((s32)(lbl_805D8E28 * f / lbl_805D8E00));
                d = -lbl_805D8E48 * d + lbl_805D8E48;
                self->position.y = lbl_805D8E20 + d;
            }
            self->rotation_x = (s32)(lbl_805D8E44 * f / lbl_805D8E00);
            self->m_6e0++;
            if (self->m_6e0 > 0x1E) {
                ((TBoss5Gryphon *)self)->enter_low_flight_mode();
                ((TBoss5Gryphon *)self)->set_low_flight_height();
                self->rotation_x = 0;
                self->m_6dc = 2;
            }
            break;
        case 2:
            speed = lbl_805D8E3C;
            if (self->action_flags == 7) {
                self->advance_motion_entry();
            }
            break;
        }
        move_along_angle(speed, self->rotation_y);
        if (((TObjMotion *)self)->is_passing_frame(lbl_805D8E10) != 0) {
            self->spawn_ground_splash();
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->m_4c0 &= ~4;
        ((TBoss5Gryphon *)self)->enter_low_flight_mode();
        ((TBoss5Gryphon *)self)->set_low_flight_height();
        self->rotation_x = 0;
        break;
    case 10:
    case 11:
    default:
        break;
    }
}
#pragma pop

struct Motion_800623E4 {
    s32 state_timer;
    f32 x;
    f32 z;
    f32 speed;
    s32 turn_rate;
};

inline s32 initial_angle_800623E4(TBoss5Gryphon *self) {
    Motion_800623E4 *motion = (Motion_800623E4 *)self->motion;
    f32 initial_dx = motion->x;
    f32 initial_dz = motion->z - self->position.z;
    initial_dx -= self->position.x;
    return (s32)(10430.38043493439 * atan2_float(initial_dx, initial_dz));
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::move_to_motion_destination(s32 event) {
    TBoss5Gryphon *self = this;
    f32 dx;
    f32 dz;

    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 4;
        self->clear_intangible();
        set_flag_4e4();
        self->set_flight_height();
        self->m_6ec = initial_angle_800623E4(self);
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        self->fn_80063EF4();
        dx = ((Motion_800623E4 *)self->motion)->x - self->position.x;
        dz = ((Motion_800623E4 *)self->motion)->z - self->position.z;
        turn_toward_angle_limited(((Motion_800623E4 *)self->motion)->turn_rate, self->m_6ec);
        move_along_angle(((Motion_800623E4 *)self->motion)->speed, (s32)(10430.38043493439 * atan2_float(dx, dz)));
        if (dx * dx + dz * dz < lbl_805D8E10) {
            self->advance_motion_entry();
        }
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}
#pragma pop

void TBoss5Gryphon::circle_arena(s32 arg1) {
    s32 ofs;
    s32 ang;
    s32 a;
    Tgt_80062550 *t;
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        ((Obj_80062550 *)this)->fb8 = 4;
        this->clear_intangible();
        set_flag_4e4();
        this->set_flight_height();
        ((Obj_80062550 *)this)->f490 = 0;
        return;
    case 8:
        this->refresh_target_periodically();
        return;
    case ENEMY_STATE_UPDATE:
        advance_animation();
        fn_80063EF4();
        ofs = 0x4000;
        if (((Obj_80062550 *)this)->pos.x * ((Obj_80062550 *)this)->pos.x + ((Obj_80062550 *)this)->pos.z * ((Obj_80062550 *)this)->pos.z > ((Obj_80062550 *)this)->f4bc->f10 * ((Obj_80062550 *)this)->f4bc->f10) {
            ofs = 0x5000;
        }
        a = (s32)(10430.38043493439 * atan2_float(((Obj_80062550 *)this)->pos.x, ((Obj_80062550 *)this)->pos.z));
        t = ((Obj_80062550 *)this)->f4bc;
        ang = a - ofs;
        if (t->f8 > 0) {
            ang = a + ofs;
        }
        move_along_angle(t->fc, ang);
        this->update_heading(((Obj_80062550 *)this)->f4bc->f4);
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case ENEMY_STATE_LEAVE: return;
    case 6: return;
    case 7: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

void TBoss5Gryphon::fn_80062660(s32 event) {
    TBoss5Gryphon *self = this;
    switch (event) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 4;
        self->clear_intangible();
        set_flag_4e4();
        self->set_flight_height();
        break;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        self->fn_80063EF4();
        move_along_angle(self->motion->m_8, self->rotation_y);
        self->m_480 += self->motion->m_4;
        break;
    case ENEMY_STATE_LEAVE:
        break;
    case 10:
    case 11:
    default:
        break;
    }
}

void TBoss5Gryphon::wait_for_players(s32 arg1) {
    void *ene_dd = this;
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        ((TObjEneDD *)ene_dd)->requested_action = 0;
        *(s32 *)((s8 *)ene_dd + 0x6DC) = 0;
        return;
    case 3:
        if ((s32) *(s32 *)((s8 *)ene_dd + 0x6DC) > 0x96) {
            ((TObjEneDD *)ene_dd)->transition_enemy_state(0xB);
        }
    case ENEMY_STATE_LEAVE:
    case 1:
        return;
    case ENEMY_STATE_UPDATE:
        if ((get_player_by_client_id(0) != 0U) || (get_player_by_client_id(1) != 0U) || (get_player_by_client_id(2) != 0U) || (get_player_by_client_id(3) != 0U)) {
            *(s32 *)((s8 *)ene_dd + 0x6DC) = (s32) (*(s32 *)((s8 *)ene_dd + 0x6DC) + 1);
        }
        break;
    }
}

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma fp_contract on

#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
#pragma pop

#pragma push
#pragma fp_contract on
#pragma pop

#pragma push
#pragma fp_contract on
#pragma pop

#pragma push
#pragma fp_contract on
#pragma pop

#pragma push
#pragma fp_contract on
#define F(t, o) (*(t *)(arg0 + (o)))
#pragma pop

#pragma push
#pragma fp_contract on
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma push
#pragma fp_contract on
#pragma pop

#pragma push
#pragma pool_data off
void TBoss5Gryphon::update_demo_state(u32 arg1) {
    s32 *p = (s32 *)((u8 *)this + 0x6E8);
    u8 sp8[0xC];
    void *obj;
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0;
        set_flag_4e4();
        this->set_flight_height();
        advance_animation();
        *(f32 *)((s8 *)this + 0x38) = 0.0f;
        *(f32 *)((s8 *)this + 0x3C) = 0.0f;
        *(f32 *)((s8 *)this + 0x40) = 0.0f;
        this->rotation_x = 0;
        this->rotation_y = 0;
        this->rotation_z = 0;
        switch (TBoss8Dragon__sub_8005D700()) {
        case 0:
            *(s32 *)((s8 *)this + 0x6DC) = 0;
            break;
        }
        *(s32 *)((s8 *)this + 0x4C0) |= 0x80;
        *(s32 *)((s8 *)this + 0x6E4) = 0;
        *(s32 *)((s8 *)this + 0x6E0) = 0;
        *p = 1;
        obj = TObject::operator new(0x28);
        if (obj != NULL) {
            __ct__17TBoss5GryphonDemoFP7TObjectlf(obj, tl_01, p, lbl_805D8D88);
        }
        this->requested_action = 0x19;
        TWindowCtrl::init_all_slots();
        this->get_target_state_b();
        return;
    case 2:
    case 9:
        if ((s32) *(s32 *)((s8 *)this + 0x6DC) == 1) {
            init_state_zero();
        }
        break;
    case ENEMY_STATE_UPDATE:
        switch (*(s32 *)((s8 *)this + 0x6DC)) {
        case 0:
            advance_animation();
            if (this->get_flag_b4() != 0) {
                *(s32 *)((s8 *)this + 0x6DC) = 1;
                TWindowCtrl::init_all_slots2();
                this->requested_action = 4;
            }
            switch (*(s32 *)((s8 *)this + 0x6E4)) {
            case 0:
                if (is_passing_frame((f32)lbl_805D8E60) != 0) {
                    VecCopy((Vec *)sp8, boss5_gryphon_waypoint_vecs);
                    spawn_particle_effect_with_flags((const Vec *)sp8, *(saddr *)((s8 *)(*(u8 **)((s8 *)this + 0x5F0)) + 4), 0x40);
                    start_pad_rumble_all(0x1C, 0x3C);
                } else if (is_passing_frame((f32)lbl_805D8E64) != 0) {
                    VecCopy((Vec *)sp8, &boss5_gryphon_waypoint_vecs[1]);
                    spawn_particle_effect_with_flags((const Vec *)sp8, *(saddr *)((s8 *)(*(u8 **)((s8 *)this + 0x5F0)) + 4), 0x40);
                    start_pad_rumble_all(0xC0, 0xF);
                } else if ((is_passing_frame((f32)lbl_805D8E68) != 0) || (is_passing_frame((f32)lbl_805D8E6C) != 0)) {
                    VecCopy((Vec *)sp8, &boss5_gryphon_waypoint_vecs[1]);
                    spawn_particle_effect_with_flags((const Vec *)sp8, *(saddr *)((s8 *)(*(u8 **)((s8 *)this + 0x5F0)) + 0), 0x40);
                }
                if (is_passing_frame((f32)lbl_805D8E70) != 0) {
                    play_sound_effect(0x40032A00, (void *) (0), 0, 0);
                    start_pad_rumble_all(0xA0, 0x3C);
                }
                if ((is_passing_frame(100.0f) != 0) || (is_passing_frame((f32)lbl_805D8E74) != 0)) {
                    play_sound_effect(0x40033409, (void *) (0), 0, 0);
                }
                if (is_passing_frame((f32)lbl_805D8E64) != 0) {
                    play_sound_effect(0x40032D0D, (void *) (0), 0, 0);
                }
                if (is_passing_frame((f32)lbl_805D8E78) != 0) {
                    play_sound_effect(0x40033409, (void *) (0), 0, 0);
                    start_pad_rumble_all(0x80, 7);
                }
                if (is_passing_frame((f32)lbl_805D8E7C) != 0) {
                    TObjBoss5Ctrl::play_pillar_sound();
                }
                break;
            }
            break;
        case 1:
            VecCopy(&this->position, &lbl_80437DC4);
            copy_xyz((u8 *)this + 0x5C, (void *)lbl_80437DD0);
            advance_animation();
            return;
        }
        break;
    case ENEMY_STATE_LEAVE:
        VecCopy(&this->position, &lbl_80437DC4);
        copy_xyz((u8 *)this + 0x5C, (void *)lbl_80437DD0);
        *(f32 *)((s8 *)this + 0x484) = 0.0f;
        *(f32 *)((s8 *)this + 0x488) = 0.0f;
        *(f32 *)((s8 *)this + 0x48C) = 0.0f;
        *p = 0;
        *(s32 *)((s8 *)this + 0x4C0) = (s32) (*(s32 *)((s8 *)this + 0x4C0) & 0xFFFFFF7F);
        TWindowCtrl::init_all_slots2();
        this->get_target_state_a();
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
#pragma pool_data off
void TBoss5Gryphon::update_death_state(u32 arg1) {
    u8 *arg0 = (u8 *)this;
    CameraPlayback cam;
    Vec v;
    Vec tmp;
    const Vec *p;
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        F(s16, 0xB8) = 0x1A;
        ((TBoss5Gryphon *)arg0)->set_intangible();
        set_flag_4e4();
        ((TBoss5Gryphon *)arg0)->set_flight_height();
        F(s32, 0x4C0) |= 0xC4;
        F(s32, 0x6DC) = 0;
        F(s32, 0x6E0) = 0;
        F(f32, 0x6F4) = 0.0f;
        p = get_arena_center();
        F(s32, 0x60) = (s32)(10430.38043493439 * atan2_float(p->x - F(f32, 0x38), p->z - F(f32, 0x40)));
        F(f32, 0x38) = p->x - lbl_805D8E80 * sin_table_lookup(F(s32, 0x60));
        F(f32, 0x3C) = lbl_805D8DD4;
        F(f32, 0x40) = p->z - lbl_805D8E80 * cos_table_lookup(F(s32, 0x60));
        play_cue_stream_file((saddr)"dradeath.adx");
        TWindowCtrl::init_all_slots();
        switch (TBoss8Dragon__sub_8005D700()) {
        case 0:
            cam.index = 0;
            cam.bank = 2;
            cam.flags = 0;
            cam.frame = 0.0f;
            cam.frame_step = 0.5f;
            activate_camera_mode(5);
            cam.cache_target_and_forward(0x31C7);
            set_scripted_camera_pose(arg0 + 0x38, arg0 + 0x38, (u8 *)&this->rotation_x);
            break;
        }
        return;
    case ENEMY_STATE_UPDATE:
        ((TObjMotion *)arg0)->advance_animation();
        switch (TBoss8Dragon__sub_8005D700()) {
        case 0:
        if (((TObjMotion *)arg0)->is_passing_frame((f32)lbl_805D8E84) != 0) {
            v.x = F(f32, 0x38);
            v.y = lbl_805D8E88;
            v.z = F(f32, 0x40);
            spawn_particle_effect_with_flags(&v, 0x201, 0x40);
            spawn_particle_effect_with_flags(&v, 0x20D, 0x40);
            spawn_particle_effect_with_flags(&v, 0x20D, 0x40);
            spawn_particle_effect_with_flags(&v, 0x20D, 0x40);
            play_sound_effect(0x4003230C, 0, 0, 0);
        }
        }
        switch (F(s32, 0x6DC)) {
        case 0:
            if (((TObjEneDD *)arg0)->get_flag_b4() != 0) {
                F(s32, 0x6DC) = 1;
                F(s32, 0x6E0) = 0;
            }
            break;
        case 1:
            F(s32, 0x6E0)++;
            if (F(s32, 0x6E0) >= 50) {
                ((TBoss5Gryphon *)arg0)->advance_motion_entry();
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        F(s32, 0x4C0) &= ~0x84;
        VecCopy(&tmp, (Vec *)(arg0 + 0x38));
        VecCopy((Vec *)(arg0 + 0x38), &lbl_80437DB8);
        ((TObjEnemy *)arg0)->update_prev_position();
        ((TObjEnemy *)arg0)->refresh_and_send_entity_flags();
        set_story_flag_or_send_quest_flag(0x52);
        VecCopy((Vec *)(arg0 + 0x38), &tmp);
        ((TObjEnemy *)arg0)->update_prev_position();
        F(s32, 0x30) = 0x12008;
        ((TObjChara *)(arg0))->vfunc_74(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}
#pragma pop

void TBoss5Gryphon::update_landing_attack(u32 arg1) {
    u8 *self = (u8 *)this;
    Vec at;
    f32 d;
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 5;
        ((TBoss5Gryphon *)self)->clear_intangible();
        set_flag_4e4();
        ((TBoss5Gryphon *)self)->set_flight_height();
        *(u32 *)((s8 *)self + 0x4C0) |= 4;
        *(s32 *)((s8 *)self + 0x6DC) = 0;
        break;
    case ENEMY_STATE_UPDATE:
        ((TObjMotion *)self)->advance_animation();
        switch (*(s32 *)((s8 *)self + 0x6DC)) {
        case 0:
            move_along_angle(lbl_805D8E04, this->rotation_y);
            if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8D88) != 0) {
                *(s32 *)((s8 *)self + 0x6DC) = 1;
            }
            break;
        case 1:
            d = ((TObjEneDD_ST *)self)->get_motion_frame() - lbl_805D8D88;
            *(f32 *)((s8 *)self + 0x3C) = (*(const f32 *)&lbl_805D8DEC) + lbl_805D8E8C * -(d * d) / lbl_805D8E90;
            move_along_angle(lbl_805D8E04, this->rotation_y);
            if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8E94) != 0) {
                ((TBoss5Gryphon *)self)->enter_ground_mode();
                ((TBoss5Gryphon *)self)->set_ground_height();
                ((TBoss5Gryphon *)self)->play_se(0x40032D0D);
                at.x = *(f32 *)((s8 *)self + 0x38);
                at.y = 0.0f;
                at.z = *(f32 *)((s8 *)self + 0x40);
                spawn_particle_effect_with_flags(&at, (s32)(*(s32 *)((s8 *)(*(u8 **)((s8 *)self + 0x5F0)) + 4)), 0x40);
                TCameraCtrl::set_shake_preset(1);
                ((TBoss5Gryphon *)self)->fn_800646F0();
                *(s32 *)((s8 *)self + 0x6DC) = 2;
            }
            break;
        case 2:
            if (fn_8005FAE0() != 0) {
                ((TBoss5Gryphon *)self)->advance_motion_entry();
            }
            break;
        }
        if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8E98) != 0) {
            ((TBoss5Gryphon *)self)->spawn_ground_splash();
        }
        break;
    case ENEMY_STATE_LEAVE:
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        *(u32 *)((s8 *)self + 0x4C0) &= ~4;
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

void TBoss5Gryphon::update_shockwave_attack(u32 arg1) {
    Obj_80063088 *self = (Obj_80063088 *)this;
    Vec pos;
    Vec vel;
    f32 speed;
    void *p;
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 0x18;
        ((TBoss5Gryphon *)self)->clear_intangible();
        set_flag_4e4();
        ((TBoss5Gryphon *)self)->set_flight_height();
        self->state = 0;
        self->f6E0 = 0;
        self->fx = NULL;
        this->targetRefreshCounter = 0;
        break;
    case 8:
        ((TBoss5Gryphon *)self)->refresh_target_periodically();
        break;
    case ENEMY_STATE_UPDATE:
        ((TObjMotion *)self)->advance_animation();
        switch (self->state) {
        case 0:
            self->state = 1;
        case 1:
            if (((TObjMotion *)self)->is_passing_frame(8.0f) != 0) {
                ((TBoss5Gryphon *)self)->play_se(0x40033203);
            }
            if (((TObjMotion *)self)->is_passing_frame(20.0f) != 0) {
                ((TBoss5Gryphon *)self)->play_se(0x40033204);
            }
            if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8D80) != 0) {
                ((TBoss5Gryphon *)self)->spawn_ground_splash();
            }
            speed = ((TObjEneDD_ST *)self)->get_motion_frame();
            if (self->fx == NULL) {
                if (speed >= 8.0f && speed <= lbl_805D8E5C) {
                    self->fx = spawn_continuous_particle_effect_with_flags(&self->fxPos, self->res->fC, 0x40);
                }
            } else if (speed <= lbl_805D8E5C) {
                ((TParticleCtrl *)self->fx)->set_position(&self->fxPos);
            } else {
                ((TObject *)self->fx)->queue_destruction();
                self->fx = NULL;
            }
            if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8E9C) != 0) {
                pos.x = self->f394;
                pos.y = lbl_80437938.y;
                pos.z = self->f39C;
                vel.x = lbl_805D8EA0 * sin_table_lookup(this->rotation_y);
                vel.y = 0.5f * -(self->fxPos.y - lbl_80437938.y);
                vel.z = lbl_805D8EA0 * cos_table_lookup(this->rotation_y);
                p = TObject::operator new(0x70);
                if (p != NULL) {
                    ((void (*)(void *, void *, void *, void *, void *, void *, u16))__ct__22TBoss5GryphonShockWaveFP7TObjectlPUcPUcls)(
                        p, self->f4C4, self, &self->fxPos, &pos, &vel, self->f38C);
                }
                spawn_particle_effect_with_flags(&self->fxPos, self->res->f10, 0x40);
                self->state = 2;
            }
            break;
        case 2:
            if (fn_8005FAE0() != 0) {
                ((TBoss5Gryphon *)self)->advance_motion_entry();
            }
            break;
        }
        break;
    case ENEMY_STATE_LEAVE:
        if (self->fx != NULL) {
            ((TObject *)self->fx)->queue_destruction();
            self->fx = NULL;
        }
        break;
    case 1:
    case 2:
    case 3:
    case 6:
    case 7:
    case 9:
    case 10:
    case 11:
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::update_ground_takeoff(u32 arg1) {
    u8 *self = (u8 *)this;
    f32 d;
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 3;
        ((TBoss5Gryphon *)self)->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        *(s32 *)((s8 *)self + 0x6E0) = 0;
        break;
    case ENEMY_STATE_UPDATE:
        ((TObjMotion *)self)->advance_animation();
        switch (*(s32 *)((s8 *)self + 0x6E0)) {
        case 0:
            if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8DF4) != 0) {
                move_along_angle(lbl_805D8DF8, this->rotation_y);
                *(u32 *)((s8 *)self + 0x4C0) |= 4;
                ((TBoss5Gryphon *)self)->run_default_state();
                set_flag_4e4();
                start_camera_shake(0x14, lbl_805D8EA4);
                ((TBoss5Gryphon *)self)->play_se(0x40033409);
                *(s32 *)((s8 *)self + 0x6E0) = 1;
            }
            break;
        case 1:
            d = ((TObjEneDD_ST *)self)->get_motion_frame() - lbl_805D8DF4;
            d = lbl_805D8DD0 * (d * d);
            *(f32 *)((s8 *)self + 0x3C) = d * lbl_805D8E34 + (*(const f32 *)&lbl_805D8D84);
            move_along_angle(lbl_805D8D88, this->rotation_y);
            if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8EA8) != 0) {
                *(s32 *)((s8 *)self + 0x6E0) = 2;
            }
            break;
        case 2:
            d = lbl_805D8EAC - ((TObjEneDD_ST *)self)->get_motion_frame();
            *(f32 *)((s8 *)self + 0x3C) = (*(const f32 *)&lbl_805D8DEC) + (*(const f32 *)&lbl_805D8D84) * -(d * d) / lbl_805D8E14;
            move_along_angle(lbl_805D8D88, this->rotation_y);
            if (((TObjMotion *)self)->is_passing_frame((f32)lbl_805D8EAC) != 0) {
                *(f32 *)((s8 *)self + 0x3C) = (*(const f32 *)&lbl_805D8DEC);
                *(s32 *)((s8 *)self + 0x6E0) = 3;
            }
            break;
        case 3:
            move_along_angle(lbl_805D8D88, this->rotation_y);
            if (fn_8005FAE0() != 0) {
                ((TBoss5Gryphon *)self)->advance_motion_entry();
            }
            break;
        }
        if (((TObjMotion *)self)->is_passing_frame(20.0f) != 0 || ((TObjMotion *)self)->is_passing_frame((f32)((f32)lbl_805D8EB0)) != 0) {
            ((TBoss5Gryphon *)self)->spawn_ground_splash();
        }
        break;
    case ENEMY_STATE_LEAVE:
        set_flag_4e4();
        ((TBoss5Gryphon *)self)->set_flight_height();
        *(u32 *)((s8 *)self + 0x4C0) &= ~4;
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}
#pragma pop

void TBoss5Gryphon::update_ground_pursuit(s32 arg1) {
    Obj_80063570 *self = (Obj_80063570 *)this;
    f32 spd;
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        this->requested_action = 1;
        ((TBoss5Gryphon *)self)->clear_intangible();
        ((TBoss5Gryphon *)self)->enter_ground_mode();
        ((TBoss5Gryphon *)self)->set_ground_height();
        self->flags |= 0x10;
        this->targetRefreshCounter = 0;
        return;
    case 8:
        ((TBoss5Gryphon *)self)->refresh_target_periodically();
        return;
    case ENEMY_STATE_UPDATE:
        ((TObjMotion *)self)->advance_animation();
        ((TBoss5Gryphon *)self)->fn_80064E3C();
        ((TObjEneDD_ST *)self)->update_velocity();
        ((TBoss5Gryphon *)self)->fn_800648C8();
        spd = ((TObjEneDD_ST *)self)->get_motion_frame();
        if (spd < lbl_805D8DCC) {
            TObjEneEpsilon__sub_800B9384(this, 0x100, lbl_805D8EB4);
        } else if (!(spd < lbl_805D8E10)) {
            if (spd < lbl_805D8E5C) {
                TObjEneEpsilon__sub_800B9384(this, 0x100, lbl_805D8EB4);
            } else if (!(spd < lbl_805D8DF4)) {
                TObjEneEpsilon__sub_800B9384(this, 0x100, lbl_805D8EB4);
            }
        }
        break;
    case ENEMY_STATE_LEAVE:
        self->flags &= ~0x10;
        break;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

void TBoss5Gryphon::update_idle_state(u32 arg1) {
    TBoss5Gryphon *self = this;
    switch (arg1) {
    case ENEMY_STATE_ENTER:
        self->requested_action = 0;
        self->clear_intangible();
        self->enter_ground_mode();
        self->set_ground_height();
        return;
    case ENEMY_STATE_UPDATE:
        self->advance_animation();
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case ENEMY_STATE_LEAVE: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    case 10: return;
    case 11: return;
    }
}

void TBoss5Gryphon::state_action_noop() {  }

void TBoss5Gryphon::dispatch_action(u32 state, s32 event) {
    TBoss5Gryphon *self = this;
    StateAction *actions = dispatch_state_actions();
    StateAction *action = actions + state;

    if (*action != NULL) {
        (self->**action)(event);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::spawn_switch_attack() {
    TParticleCtrl *particle;

    particle = spawn_particle_effect_with_flags((const Vec *)this, 0x211, 0x40);
    if (particle != 0) {
        attach_particle_model((u8 *)particle, get_bml_model(boss5_gryphon_bml_resource, 2), boss5_gryphon_texture_list, 0, 0, (f32)lbl_805D8D88);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::spawn_attack_effect() {
    TParticleCtrl *particle;

    particle = spawn_particle_effect_with_flags((const Vec *)this, 0x210, 0x40);
    if (particle != 0) {
        attach_particle_model((u8 *)particle, get_bml_model(boss5_gryphon_bml_resource, 1), boss5_gryphon_texture_list, 0, 0, (f32)lbl_805D8D88);
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::spawn_lightning_effect() {
    Seg_80063CDC segs[3];
    s32 a;
    s32 b;
    void *o;

    a = (s32)(65536.0f * (lbl_805D8D98 * (f32)rand()));
    b = (s32)(65536.0f * (lbl_805D8D98 * (f32)rand()));
    segs[0].x = lbl_805D8EB8 * sin_table_lookup(a) + *(f32 *)((s8 *)((u8 *)this) + 0x38);
    segs[0].y = 0.0f;
    segs[0].z = lbl_805D8EB8 * cos_table_lookup(a) + *(f32 *)((s8 *)((u8 *)this) + 0x40);
    segs[0].w = 0.0f;
    segs[2].x = lbl_805D8EB8 * sin_table_lookup(b) + *(f32 *)((s8 *)((u8 *)this) + 0x38);
    segs[2].y = 0.0f;
    segs[2].z = lbl_805D8EB8 * cos_table_lookup(b) + *(f32 *)((s8 *)((u8 *)this) + 0x40);
    segs[2].w = 0.0f;
    a = (s32)(0.5f * (f32)(a + b));
    if (lbl_805D8D98 * (f32)rand() > 0.5f) {
        a += 0x8000;
    }
    segs[1].x = lbl_805D8EB8 * sin_table_lookup(a) + *(f32 *)((s8 *)((u8 *)this) + 0x38);
    segs[1].y = lbl_805D8E10;
    segs[1].z = lbl_805D8EB8 * cos_table_lookup(a) + *(f32 *)((s8 *)((u8 *)this) + 0x40);
    segs[1].w = 0.0f;
    o = TObject::operator new(0x264);
    if (o != NULL) {
        o = __ct__25TBoss5GryphonLightningEffFv(o, this, segs, 3, 0.0f, lbl_805D8D88, 8.0f);
    }
    TBoss5GryphonLightningEff__sub_80325064(o);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::fn_80063EF4() {
    if (is_passing_frame(lbl_805D8EBC) != 0) {
        spawn_ground_splash();
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::spawn_ground_splash() {
    Vec pos;
    f32 temp_f1;
    CsnHit *hit;
    VecCopy(&pos, (Vec *)((void *) (&this->position)));
    hit = csnVecterUnder(&pos, 0x16EF);
    if (hit != NULL) {
        temp_f1 = hit->contact->point.y;
        if (!(temp_f1 > 6.0f)) {
            pos.y = temp_f1;
            spawn_particle_effect_with_flags(&pos, **(saddr **)((u8 *)this + 0x5F0), 0x40);
            play_se(0x40032D01);
        }
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void apply_lightning_hit(s32 arg0, s32 arg1, f32 farg0) {
    DragonAttackParams desc = lbl_80437DA4;
    desc.field_4 = *(f32 *)((s8 *)boss5_gryphon_behavior_params[2] + 0xC);
    desc.field_8 = farg0;
    TObjEneDD::setup_instance(arg0, arg1, (u8 *)&desc, 0);
}


void apply_snarl_hit(s32 arg0, s32 arg1, f32 inner, f32 scale) {
    DragonAttackParams desc = lbl_80437D90;
    desc.field_4 = *(f32 *)boss5_gryphon_behavior_params[2] * scale;
    desc.field_8 = inner;
    TObjEneDD::setup_instance(arg0, arg1, (u8 *)&desc, 0);
}
void apply_tornado_hit(s32 arg0, saddr arg1) {
    DragonAttackParams desc = lbl_80437D7C;
    desc.field_4 = *(f32 *)((s8 *)boss5_gryphon_behavior_params[2] + 8);
    TObjEneDD::setup_instance(arg0, arg1, (u8 *)&desc, 0);
}

void apply_shockwave_hit(s32 arg0, s32 arg1) {
    DragonAttackParams desc = lbl_80437D68;
    desc.field_4 = *(f32 *)((s8 *)boss5_gryphon_behavior_params[2] + 4);
    TBoss8Dragon__sub_80067074(arg1, (saddr)&desc);
    TObjEneDD::setup_instance(arg0, arg1, (u8 *)&desc, 0);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::fn_800641A8() {
    DragonAttackParams desc = lbl_80437D54;
    Vec *pos;
    pos = &pad_3C0[14];
    if (!(pad_3C0[14].y > lbl_805D8E00)) {
        fill_value_array(attack_history);
        reset_hp((u8 *)0, (u8 *)(boss5_gryphon_attack_params[1]), (u8 *)0);
        TObjEneDD::emit_enemy_effect(this, (void *)pos, (u8 *)&desc, attack_history);
        reset_hp((u8 *)0, (u8 *)(boss5_gryphon_attack_params[0]), (u8 *)0);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#pragma push
#pragma fp_contract on
void TBoss5Gryphon::fn_8006426C() {
    Vec mid;
    DragonAttackParams prm = lbl_80437D40;
    f32 bx = pad_3C0[11].x;
    mid.x = 0.5f * (pad_3C0[0].x - bx) + bx;
    f32 by = pad_3C0[11].y;
    mid.y = 0.5f * (pad_3C0[0].y - by) + by;
    f32 bz = pad_3C0[11].z;
    mid.z = 0.5f * (pad_3C0[0].z - bz) + bz;
    fill_value_array(attack_history);
    reset_hp(NULL, (u8 *)boss5_gryphon_attack_params[4], NULL);
    TObjEneDD::emit_enemy_effect(this, &mid, (u8 *)&prm, attack_history);
    reset_hp(NULL, (u8 *)boss5_gryphon_attack_params[0], NULL);
}
#pragma pop

void TBoss5Gryphon::fn_8006435C() {
    DragonAttackParams prm;
    Vec *point;
    TBoss1Dragon__sub_80027A80(&prm, &boss8_dragon_attack_params);
    fill_value_array(attack_history);
    reset_hp(NULL, (u8 *)boss5_gryphon_attack_params[3], NULL);
    point = &pad_3C0[11];
    prm.field_8 = lbl_805D8EAC;
    TBoss8Dragon__sub_800670E0((saddr)point, &prm);
    TObjEneDD::emit_enemy_effect(this, point, (u8 *)&prm, attack_history);
    point = &pad_3C0[0];
    prm.field_8 = lbl_805D8DD0;
    TBoss8Dragon__sub_800670E0((saddr)point, &prm);
    TObjEneDD::emit_enemy_effect(this, point, (u8 *)&prm, attack_history);
    reset_hp(NULL, (u8 *)boss5_gryphon_attack_params[0], NULL);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void TBoss5Gryphon::fn_8006442C() {
    DragonAttackParams fx;
    Vec pts[10];
    Vec *p;
    s32 i;
    TBoss1Dragon__sub_80027A80(&fx, &gryphon_effect_param_block);
    fill_value_array(attack_history);
    p = pts;
    VecCopy(p++, &pad_3C0[3]);
    VecCopy(p, &pad_3C0[7]);
    p[1].x = 0.5f * (pad_3C0[3].x + pad_3C0[4].x);
    p[1].y = 0.5f * (pad_3C0[3].y + pad_3C0[4].y);
    p[1].z = 0.5f * (pad_3C0[3].z + pad_3C0[4].z);
    p[2].x = 0.5f * (pad_3C0[7].x + pad_3C0[8].x);
    p[2].y = 0.5f * (pad_3C0[7].y + pad_3C0[8].y);
    p[2].z = 0.5f * (pad_3C0[7].z + pad_3C0[8].z);
    p[3].x = 0.5f * (pad_3C0[4].x + pad_3C0[5].x);
    p[3].y = 0.5f * (pad_3C0[4].y + pad_3C0[5].y);
    p[3].z = 0.5f * (pad_3C0[4].z + pad_3C0[5].z);
    p[4].x = 0.5f * (pad_3C0[8].x + pad_3C0[9].x);
    p[4].y = 0.5f * (pad_3C0[8].y + pad_3C0[9].y);
    p[4].z = 0.5f * (pad_3C0[8].z + pad_3C0[9].z);
    p[5].x = 0.5f * (pad_3C0[5].x + pad_3C0[6].x);
    p[5].y = 0.5f * (pad_3C0[5].y + pad_3C0[6].y);
    p[5].z = 0.5f * (pad_3C0[5].z + pad_3C0[6].z);
    p[6].x = 0.5f * (pad_3C0[9].x + pad_3C0[10].x);
    p[6].y = 0.5f * (pad_3C0[9].y + pad_3C0[10].y);
    p[6].z = 0.5f * (pad_3C0[9].z + pad_3C0[10].z);
    p += 7;
    VecCopy(p++, &pad_3C0[6]);
    VecCopy(p, &pad_3C0[10]);
    reset_hp(NULL, (u8 *)boss5_gryphon_attack_params[3], NULL);
    p = pts;
    for (i = 0; i < 5; i++) {
        fx.field_8 = gryphon_effect_scale_table[i];
        TBoss8Dragon__sub_800670E0((saddr)p, &fx);
        TObjEneDD::emit_enemy_effect(this, (void *)p++, (u8 *)&fx, attack_history);
        TBoss8Dragon__sub_800670E0((saddr)p, &fx);
        TObjEneDD::emit_enemy_effect(this, (void *)p++, (u8 *)&fx, attack_history);
    }
    reset_hp(NULL, (u8 *)boss5_gryphon_attack_params[0], NULL);
}

void TBoss5Gryphon::update_collider_from_table() {
    s32 arg0 = (saddr)this;
    DragonAttackParams desc = gryphon_collider_desc;
    TBoss8Dragon__sub_800670E0((int)(arg0 + 0x3C0), &desc);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::fn_800646F0() {
    DragonAttackParams stack;
    TBoss1Dragon__sub_80027A80(&stack, &boss5_gryphon_params_b);
    stack.field_8 = *(f32 *)((s8 *)boss5_gryphon_behavior_params[2] + 0x10);
    reload_stats_for_phase(boss5_gryphon_behavior_params[2]);
    TBoss8Dragon__sub_80067074((saddr)&position, (saddr)&stack);
    emit_effect_at_position(&stack);
    reload_stats_for_type();
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::run_default_state() { query_default(); attack_default(); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::update_state_3() { emit_part_attack_effect(3); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::set_state_2() { emit_part_attack_effect(2); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::attack_default() { emit_part_attack_effect(1); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::query_default() { emit_part_attack_effect(0); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::fn_80064828() {
    if (is_passing_frame((f32)lbl_805D8D80) != 0) {
        query_default();
        return;
    }
    if (is_passing_frame(8.0f) != 0) {
        attack_default();
        return;
    }
    if (is_passing_frame((f32)lbl_805D8E00) != 0) {
        set_state_2();
        return;
    }
    if (is_passing_frame((f32)lbl_805D8E0C) != 0) {
        update_state_3();
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::fn_800648C8() {
    if (is_passing_frame((f32)lbl_805D8EC0) != 0) {
        query_default();
        return;
    }
    if (is_passing_frame((f32)lbl_805D8DF8) != 0) {
        attack_default();
        return;
    }
    if (is_passing_frame(20.0f) != 0) {
        set_state_2();
        return;
    }
    if (is_passing_frame(8.0f) != 0) {
        update_state_3();
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::emit_part_attack_effect(int part) {
    DragonAttackParams prm = gryphon_part_attack_params;
    Vec *p;
    fill_value_array(attack_history);
    p = &pad_3C0[gryphon_part_attack_index_table[part]];
    reset_hp((u8 *)0, (u8 *)(boss5_gryphon_attack_params[0]), (u8 *)0);
    TBoss8Dragon__sub_80067074((saddr)p, (saddr)&prm);
    TObjEneDD::emit_enemy_effect(this, (void *)p, (u8 *)&prm, attack_history);
    reset_hp((u8 *)0, (u8 *)(boss5_gryphon_attack_params[0]), (u8 *)0);
    spawn_particle_effect_with_flags(p, effect_ids[2], 0x40);
    ((TBoss8Dragon *)p)->spawn_attack_effect();
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::copy_spawn_params(void* a1) { *(short*)((char*)a1 + 0x2) = this->entity_id; VecCopy((Vec *)((char*)a1 + 0x4), &this->position); *(s32 *)((char*)a1 + 0x10) = this->rotation_y; ((TBoss8Dragon *)a1)->send_spawn_params_packet(); }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::fn_80064AB0() {
    P_80064AB0 p;
    TBoss8Dragon__sub_800660A4(&p);
    p.id = entity_id;
    p.kind = target_id;
    p.x = destination.x;
    p.z = destination.z;
    ((TBoss8Dragon *)(&p))->send_boss_actions();
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void apply_remote_action__13TBoss5GryphonFPvPv(u8 *ene_dd, u8 *boss8_dragon) {
    s16 temp_r4;
    VecCopy((Vec *)(ene_dd + 0x484), (Vec *)(boss8_dragon + 4));
    ((f32 (*)(void *, void *))subtract_vector)(ene_dd + 0x484, ene_dd + 0x38);
    ((TObjEneDD *)ene_dd)->rotation_y = (s32) *(s32 *)((s8 *)boss8_dragon + 0x10);
    ((TBoss8Dragon *)(ene_dd + 0x494))->copy_action_state((u8 *)(boss8_dragon + 0x14));
    *(s16 **)((s8 *)ene_dd + 0x4BC) = (s16 *)(ene_dd + 0x494);
    temp_r4 = **(s16 **)((s8 *)ene_dd + 0x4BC);
    if ((s16) ((TObjEneDD *)ene_dd)->mode != temp_r4) {
        ((TObjEneDD *)ene_dd)->transition_enemy_state(temp_r4);
    }
    *(s32 *)((s8 *)ene_dd + 0x4C0) = (s32) (*(s32 *)((s8 *)ene_dd + 0x4C0) | 2);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss8Dragon::copy_action_state(u8 *arg1) {
    u8 *self = (u8 *)this;
    *(s16 *)((s8 *)self + 0) = (s16) *(s16 *)((s8 *)arg1 + 0);
    *(s16 *)((s8 *)self + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
    *(ByteBlock_10 *)((saddr) (u8 *)&this->m_flags) = *(const ByteBlock_10 *)((saddr) arg1 + 4);
}
}
void handle_6xA0_gal_gryphon_boss_actions(TBoss8Dragon *boss8_dragon);
void handle_6x9F_gal_gryphon_boss_actions(void *boss8_dragon);
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void handle_6xA0_gal_gryphon_boss_actions(TBoss8Dragon *boss8_dragon) {
    void *x;
    boss8_dragon->byteswap_action_packet();
    x = get_enemy_entity(*(u16 *)((s8 *)boss8_dragon + 0x2));
    if (x != NULL) {
        apply_remote_action__13TBoss5GryphonFPvPv((u8 *)x, (u8 *)boss8_dragon);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

void TBoss5Gryphon::set_target_from_action(void *boss8_dragon) {
    enemy_set_target_id(this, (u16) *(s32 *)((s8 *)boss8_dragon + 4));
    this->destination.x = (f32) *(f32 *)((s8 *)boss8_dragon + 8);
    this->destination.z = (f32) *(f32 *)((s8 *)boss8_dragon + 0xC);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void handle_6x9F_gal_gryphon_boss_actions(void *boss8_dragon) {
    void *x;
    ((TBoss8Dragon *)boss8_dragon)->bswap_boss_actions();
    x = get_enemy_entity(*(u16 *)((s8 *)boss8_dragon + 0x2));
    if (x != NULL) {
        ((TBoss5Gryphon *)x)->set_target_from_action(boss8_dragon);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
extern "C" {

void TBoss5Gryphon::reload_stats_for_phase(void *) {
    this->reload_stats_keep_hp_tp((u8 *)(boss5_gryphon_base_params[((s32 *)lbl_80487890)[2]]), (u8 *)(boss5_gryphon_attack_params[((s32 *)lbl_8048789C)[2]]), (u8 *)(boss5_gryphon_resistance_params[((s32 *)lbl_804878A8)[2]]));
}

void TBoss5Gryphon::reload_stats_for_type() {
    saddr arg0 = (saddr)this;
    ((TObjEneDD *)arg0)->reload_stats_keep_hp_tp((u8 *)(boss5_gryphon_base_params[*(s32 *)((s8 *)&lbl_80487848 + 0x48)]), (u8 *)(boss5_gryphon_attack_params[*(s32 *)((s8 *)&lbl_80487848 + 0x54)]), (u8 *)(boss5_gryphon_resistance_params[*(s32 *)((s8 *)&lbl_80487848 + 0x60)]));
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::set_offscreen_height() { this->position.y = lbl_805D8EC4; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::set_low_flight_height() { this->position.y = lbl_805D8E20; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::set_flight_height() { *(float*)((char*)this + 0x3c) = lbl_805D8DEC; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::set_ground_height() { this->position.y = lbl_805D8D84; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::enter_offscreen_mode() { this->flight_mode = 3; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::enter_low_flight_mode() { this->flight_mode = 2; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::set_flag_4e4() { flight_mode = 1; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::enter_ground_mode() { this->flight_mode = 0; }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::fn_80064DB8() {
    if (is_passing_frame(lbl_805D8D80) != 0 || is_passing_frame(8.0f) != 0 || is_passing_frame(lbl_805D8E00) != 0 || is_passing_frame(lbl_805D8E0C) != 0) {
        play_se(0x40032D08);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::fn_80064E3C() {
    if (is_passing_frame(lbl_805D8EC0) != 0 || is_passing_frame(lbl_805D8DF8) != 0 || is_passing_frame(20.0f) != 0 || is_passing_frame(8.0f) != 0) {
        play_se(0x40032D08);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::spawn_ancient_trap(s32 id) {
    play_persistent_sound(id, (saddr)this, (uaddr)&m_560, 0, 0);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::play_se(s32 arg1) {
    s32 arg0 = (saddr)this;
    ((s32 (*)(s32, s32, s32, s32))play_sound_effect)(arg1, arg0 + 0x560, 0, 0);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::update_linked_ground_position() {
    this->update_linked_position(lbl_805D8EC8);
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

#define CFG ((Cfg_80064F50 *)boss5_gryphon_behavior_params[2])
void TBoss5Gryphon::update_body_colliders() {
    if (m_4c0 & 0x80) {
        for (s32 i = 0; i < 10; i++) {
            bodies[i].flags &= ~1;
        }
        return;
    }
    update_local_colliders_from_world(this, body_points);
    {
        f32 lim = lbl_805D8EAC;
        s32 i;
        for (i = 0; i < 10; i++) {
            CollisionBody *p;
            bodies[i].flags |= 1;
            p = &bodies[i];
            if (p->offset.y + p->center.y >= lim) {
                set_collider_contact_high((u8 *)p);
            } else {
                set_collider_contact_low((u8 *)p);
            }
        }
    }
    if (flight_mode == 2) {
        bodies[0].flags |= 0x300;
        bodies[1].flags |= 0x300;
        bodies[2].flags |= 0x300;
        bodies[3].flags |= 0x300;
        bodies[2].flags |= 0x300;
        bodies[6].flags &= ~1;
        bodies[7].flags &= ~1;
        bodies[8].flags &= ~1;
        bodies[9].flags &= ~1;
        bodies[0].radius = lbl_805D8E84;
        set_collider_contact_low((u8 *)&bodies[0]);
        set_collider_contact_low((u8 *)&bodies[1]);
        set_collider_contact_low((u8 *)&bodies[2]);
        set_collider_contact_low((u8 *)&bodies[3]);
        set_collider_contact_low((u8 *)&bodies[2]);
    } else {
        bodies[0].flags &= ~0x300;
        bodies[1].flags &= ~0x300;
        bodies[2].flags &= ~0x300;
        bodies[3].flags &= ~0x300;
        bodies[2].flags &= ~0x300;
        bodies[6].flags |= 1;
        bodies[7].flags |= 1;
        bodies[8].flags |= 1;
        bodies[9].flags |= 1;
        bodies[0].radius = lbl_805D8E10;
    }
    bodies[0].unk_28 = CFG->i20;
    bodies[1].unk_28 = CFG->i1C;
    bodies[2].unk_28 = CFG->i1C;
    bodies[3].unk_28 = CFG->i1C;
    bodies[4].unk_28 = CFG->i1C;
    bodies[5].unk_28 = CFG->i18;
    bodies[6].unk_28 = CFG->i24;
    bodies[7].unk_28 = CFG->i24;
    bodies[8].unk_28 = CFG->i24;
    bodies[9].unk_28 = CFG->i24;
}

void TBoss5Gryphon::shift_position_history() {
    saddr arg0 = (saddr)this;
    VecCopy((Vec *)(arg0 + 0x2FC), (Vec *)(arg0 + 0x3C0));
    VecCopy((Vec *)(arg0 + 0x74), (Vec *)(arg0 + 0x2FC));
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::run_miss_reaction() {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::run_hit_reaction() {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::run_death_reaction() {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::refresh_target() {  }
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
void TBoss5Gryphon::update_state_or_dispatch_tick() {
    if (!(m_4c0 & 0xC) && hp <= 0) {
        set_animation_by_state();
    } else {
        dispatch_action(mode, 9);
    }
}
#pragma pop

#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

struct Obj_8005FBC4;
void TBoss5Gryphon::run_task() {
    s32 temp_r31;
    s32 temp_r31_2;
    s32 var_r30;
    s32 i;
    u8 *self = (u8 *)this;
    if (TObjPlayer::check_demo_mode() != 0) {
        ((TBoss5Gryphon *)(self))->run_demo_task();
        return;
    }
    if (*(s32 *)((s8 *)self + 0x4C0) & 1) {
        ((TObjEnemy *)self)->send_entity_set_flags();
        ((TObject *)self)->queue_destruction();
        return;
    }
    if (TObjEneDD::is_main_phase_15() != 0) {
        temp_r31 = *(s32 *)((s8 *)self + 0x4E0);
        if (((TObjEneDD *)self)->update_lobby_state() != 0) {
            *(s32 *)((s8 *)self + 0x4E0) = 0;
            if ((s32) *(s32 *)((s8 *)self + 0x4E0) != temp_r31) {
                *(s32 *)((s8 *)self + 0x730) = 1;
            }
        } else {
            *(s32 *)((s8 *)self + 0x4E0) = 1;
        }
    }
    temp_r31_2 = TObjEneDD::query_teammate_state();
    ((TBoss5Gryphon *)(self))->update_attack_stat_status();
    ((TBoss5Gryphon *)(self))->update_defense_stat_status();
    if (temp_r31_2 == 0) {
        if (((s32 (*)(void *))get_flag_bit6__13TBoss5GryphonFv)(self) != 0) {
            this->actorFlags = (s32) (this->actorFlags | 0x800);
        } else {
            this->actorFlags = (s32) (this->actorFlags & 0xFFFFF7FF);
        }
        if ((s32) *(s32 *)((s8 *)self + 0x4E0) != 1) {
            if (((TBoss5Gryphon *)(self))->test_flag30_512() != 0) {
                ((TObjEneDD *)self)->clear_attack_receipts();
            }
            ((TBoss5Gryphon *)self)->update_state_or_dispatch_tick();
            ((TBoss5Gryphon *)self)->flush_pending_effect();
            ((TBoss5Gryphon *)self)->dispatch_action(this->mode, 8);
            ((TBoss5Gryphon *)self)->dispatch_action(this->mode, 0);
        } else {
            if (((TBoss5Gryphon *)(self))->test_flag30_512() != 0) {
                ((TObjEneDD *)self)->clear_attack_receipts();
            }
            ((TBoss5Gryphon *)self)->dispatch_action(this->mode, 0);
        }
    }
    ((TObjEneDD *)self)->sub_800BBA0C();
    ((TBoss5Gryphon *)self)->apply_velocity();
    ((TBoss5Gryphon *)self)->fn_8005FB90();
    ((TBoss5Gryphon *)self)->advance_motion_timer();
    ((TBoss5Gryphon *)(self))->update_body_colliders();
    ((TBoss5Gryphon *)self)->shift_position_history();
    ((TObjEnemy *)self)->submit_default_cursor_candidate();
    add_radar_scaled_marker(&this->position, -0x5DB4, 1, 1, 2.0f);
    VecCopy((Vec *)(&this->m_56c), &this->body_center);
    if (temp_r31_2 == 0) {
        ((TObject *)(self + 0x4C4))->run_tasks();
    }
    project_sound_origin_from_camera((saddr)(self + 0x38), (u8 *)(self + 0x560), lbl_805D8DAC);
    for (i = 0; i < 4; i++) {
        renderFadeStates[i].update();
    }
    if ((s32) *(s32 *)((s8 *)self + 0x4E4) != 0) {
        ((TBoss5Gryphon *)self)->update_collider_from_table();
    }
}

Obj_80065658 *__dt__13TBoss5GryphonFv(Obj_80065658 *o, s16 flag) {
    s32 i;
    if (o != 0) {
        o->vt = __vt__13TBoss5Gryphon;
        for (i = 15; i >= 0; i--) {
            if (o->objs[i] != 0) {
                ((TObject *)o->objs[i])->queue_destruction();
                o->objs[i] = 0;
            }
        }
        if (o->demo != 0) {
            delete o->demo;
            o->demo = 0;
        }
        if (o->attack_history != 0) {
            delete o->attack_history;
            o->attack_history = 0;
        }
        free_collision_body_parts(o);
        if (boss5_gryphon_instance == o) {
            boss5_gryphon_instance = 0;
        }
        __destroy_arr(o->f580, (void *)__dt__15RenderFadeStateFv, 0x1c, 4);
        __dt__7TObjectFv(o->f4c4, -1);
        __dt__12TObjEneDD_STFv(o, 0);
        if (flag > 0) {
            TObject::operator delete(o);
        }
    }
    return o;
}

extern "C" {
void __ct__12TObjEneDD_STFP7TObject(void *, void *, void *);
void __ct__7TObjectFP7TObject(void *, void *);
void __construct_array(void *, void *, void *, int, int);
void __ct__15RenderFadeStateFv(void *);
void __ct__14SubtractiveRngFv(void *);
// Ids resolved into boss5_gryphon_base_params / boss5_gryphon_resistance_params by the resource loader.
s32 boss5_gryphon_base_param_ids[1] = { 0x1E };
s32 boss5_gryphon_resistance_param_ids[1] = { 0x1E };
const char *boss5_gryphon_type_name_pointer = boss5_gryphon_type_name;

TBoss5Gryphon *TBoss5Gryphon__ct(TBoss5Gryphon *self, void *parent, void *data) {
    u32 flags[4];
    s32 i;

    __ct__12TObjEneDD_STFP7TObject(self, parent, data);
    ((Obj_80065658 *)self)->vt = __vt__13TBoss5Gryphon;
    __ct__7TObjectFP7TObject(&self->m_4c4, 0);
    __construct_array(self->renderFadeStates, (void *)__ct__15RenderFadeStateFv, (void *)__dt__15RenderFadeStateFv, 0x1C, 4);
    __ct__14SubtractiveRngFv(self->rng);
    self->m_name = boss5_gryphon_type_name_pointer;
    if (boss5_gryphon_instance == NULL) {
        boss5_gryphon_instance = (Obj_80065658 *)self;
    }
    ((TObjEneDD *)self)->invoke_initialization_hook(data);
    self->m_4c0 = 0;
    if (self->exchange_object_state(flags, 1) != 0 && (flags[0] & 0x12008) == 0x12008) {
        self->m_4c0 |= 1;
    }
    self->init_position_vectors();
    if (is_split_screen() != 0) {
        self->model = *(void **)(*(u8 **)(boss5_gryphon_body_bml_resource + 0x42C) + 0x28);
    } else {
        self->model = *(void **)(*(u8 **)(boss5_gryphon_body_bml_resource + 0x42C) + 0x8);
    }
    self->texlist = *(s32 *)(*(u8 **)(boss5_gryphon_body_bml_resource + 0x42C) + 0xC);
    ((TObjEneDD *)self)->init_model((CollisionBody *)lbl_804878D0, (s32)10);
    self->motion_flags = 0;
    self->set_field_d8((saddr)lbl_80487B1C);
    self->set_field_dc(*(s32 *)(boss5_gryphon_body_bml_resource + 0x430));
    self->requested_action = 0;
    self->set_animation(self->requested_action);
    self->set_field_b8(self->requested_action);
    ((TObjEneDD *)self)->reset_hp((u8 *)(boss5_gryphon_base_params[*(s32 *)lbl_80487890]), (u8 *)(boss5_gryphon_attack_params[*(s32 *)lbl_8048789C]), (u8 *)(boss5_gryphon_resistance_params[*(s32 *)lbl_804878A8]));
    self->set_state_flag_2();
    *(void **)((u8 *)self + 0x350) = lbl_804878B4;
    ((TObjEneDD *)self)->initialize_enemy_state(77);
    self->wall_reach = 20.0f;
    ((TObjEneDD_ST *)self)->set_target_destination(&lbl_80437938);
    self->enemy_init_acquire_period(10);
    self->enemy_init_validate_period(10);
    ((Obj_80065658 *)self)->f474[0] = 0.0f;
    ((Obj_80065658 *)self)->f474[1] = 0.0f;
    ((Obj_80065658 *)self)->f474[2] = 0.0f;
    self->m_480 = 0;
    ((Obj_80065658 *)self)->f484[0] = 0.0f;
    ((Obj_80065658 *)self)->f484[1] = 0.0f;
    ((Obj_80065658 *)self)->f484[2] = 0.0f;
    for (i = 0; i < 2; i++) {
        init_motion_record((saddr)&((Obj_80065658 *)self)->motions[i]);
    }
    self->motion = ((Obj_80065658 *)self)->motions;
    self->flight_mode = 0;
    for (i = 0; i < 15; i++) {
        VecCopy(&((Obj_80065658 *)self)->f3c0[i], &self->position);
    }
    for (i = 0; i < 10; i++) {
        VecCopy(&((Obj_80065658 *)self)->f4e8[i], &self->position);
    }
    for (i = 0; i < 16; i++) {
        ((Obj_80065658 *)self)->objs[i] = 0;
    }
    self->m_774 = 0;
    self->m_778 = (uaddr)boss5_gryphon_action_scripts;
    VecCopy((Vec *)(&self->m_560), &self->position);
    VecCopy((Vec *)(&self->m_56c), &self->position);
    *(f32 *)(*(u8 **)((u8 *)self + 0x2B0) + 0x10) = lbl_805D8E10;
    self->attack_history = new AreaAttackHistory(4);
    self->demo = (TBoss5GryphonDemo *)new TBoss5GryphonColli((TObject *)&self->m_4c4);
    for (i = 0; i < 4; i++) {
        self->renderFadeStates[i].activate_and_dispatch();
    }
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        self->effect_ids = lbl_80437958;
        break;
    }
    self->m_6dc = 0;
    self->m_6e0 = 0;
    self->m_6e4 = 0;
    self->m_6e8 = 0;
    self->m_6ec = 0;
    self->m_6f0 = 0;
    ((Obj_80065658 *)self)->f6f4[0] = 0.0f;
    ((Obj_80065658 *)self)->f6f4[1] = 0.0f;
    ((Obj_80065658 *)self)->f6f4[2] = 0.0f;
    ((Obj_80065658 *)self)->f6f4[3] = 0.0f;
    ((Obj_80065658 *)self)->f6f4[4] = 0.0f;
    ((Obj_80065658 *)self)->f6f4[5] = 0.0f;
    ((Obj_80065658 *)self)->f6f4[6] = 0.0f;
    ((Obj_80065658 *)self)->f6f4[7] = 0.0f;
    ((Obj_80065658 *)self)->f6f4[8] = 0.0f;
    ((Obj_80065658 *)self)->f6f4[9] = 0.0f;
    ((Obj_80065658 *)self)->f6f4[10] = 0.0f;
    self->m_720 = 0;
    self->particles[0] = NULL;
    self->particles[1] = NULL;
    self->particles[2] = NULL;
    self->mode = 0;
    if (TObjEneDD::is_main_phase_15() != 0) {
        if (self->update_lobby_state() != 0) {
            self->m_4e0 = 0;
        } else {
            self->m_4e0 = 1;
        }
    } else {
        self->m_4e0 = 0;
    }
    self->mode = 4;
    if (!(self->m_4c0 & 1)) {
        self->dispatch_action(self->mode, 4);
    }
    self->m_730 = 0;
    return self;
}
}
#pragma pop

extern "C" {

void TBoss5Gryphon::cleanup() {
    TLobby::free_char_select_singleton();
    TBoss5GryphonSnarl__sub_80066E84();
    TBoss8Dragon__sub_80355A1C();
    TBoss8Dragon__sub_80066A4C();
    if (boss5_gryphon_texture_list != NULL) {
        release_texture_list(boss5_gryphon_texture_list);
        TAdSinglePlyChrSelectGC::safe_free((uaddr)boss5_gryphon_texture_list);
        boss5_gryphon_texture_list = NULL;
    }
    if (boss5_gryphon_bml_resource != NULL) {
        delete boss5_gryphon_bml_resource;
        boss5_gryphon_bml_resource = NULL;
    }
    if ((uaddr) boss5_gryphon_body_bml_resource != 0U) {
        delete (BmlResource *)boss5_gryphon_body_bml_resource;
        boss5_gryphon_body_bml_resource = 0U;
    }
}

extern void *tl_04;

void *TBoss5Gryphon::create(void *arg0) {
    void *o = TObject::operator new(0x77C);
    if (o != NULL) {
        o = TBoss5Gryphon__ct((TBoss5Gryphon *)o, tl_04, arg0);
    }
    return o;
}

// Inferred: TBoss5Gryphon's resource loader (paired with TBoss5Gryphon::cleanup in the boss resource table).
void load_boss5_gryphon_resources(void) {
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        boss5_gryphon_body_bml_resource = (u8 *)load_enemy_bml_resource((BmlResourceDescriptor *)boss5_gryphon_body_bml_desc);
        boss5_gryphon_bml_resource = load_enemy_bml_resource((BmlResourceDescriptor *)boss5_gryphon_bml_desc);
        boss5_gryphon_texture_list = (GinjaTextureList *)load_gvm_texture_file((saddr)"modelparticle_gryphon.gvm");
        break;
    }
    boss5_gryphon_render_node_index = 0;
    boss5_gryphon_bone_capture_origin.x = 0.0f;
    boss5_gryphon_bone_capture_origin.y = 0.0f;
    boss5_gryphon_bone_capture_origin.z = 0.0f;
    boss5_gryphon_bone_capture_index = 0;
    boss5_gryphon_bone_capture_output = 0;
    boss5_gryphon_render_flags = 0;
    boss5_gryphon_instance = NULL;
    for (s32 i = 0; i < 1; i++) {
        boss5_gryphon_base_params[i] = (saddr)TLobby::register_boss(boss5_gryphon_base_param_ids[i]);
    }
    for (s32 i = 0; i < 5; i++) {
        boss5_gryphon_attack_params[i] = (saddr)TLobby::dispatch_shared_handler_b(boss5_gryphon_attack_param_ids[i]);
    }
    for (s32 i = 0; i < 1; i++) {
        boss5_gryphon_resistance_params[i] = (saddr)TLobby::register_object(boss5_gryphon_resistance_param_ids[i]);
    }
    for (s32 i = 0; i < 3; i++) {
        boss5_gryphon_behavior_params[i] = TLobby::dispatch_shared_handler_a(boss5_gryphon_behavior_param_ids[i]);
    }
    TWindowCtrl::init_all_slots();
    TBoss8Dragon::set_default_on_state0();
    TBoss8Dragon__sub_80355A20();
    TBoss5GryphonSnarl__sub_80066E88();
    load_f512_inazuma();
}

}

void TBoss5Gryphon::fill_follow_camera_params(u8 *arg1, u8 *arg2) {
    *(f32 *)((s8 *)arg1 + 0) = 0.0f;
    *(f32 *)((s8 *)arg2 + 0) = 0.0f;
    switch (this->flight_mode) {
    default:
    case 2:
    case 0:
        *(f32 *)((s8 *)arg1 + 4) = *(f32 *)((s8 *)boss5_gryphon_behavior_params[0] + 0);
        *(f32 *)((s8 *)arg1 + 8) = *(f32 *)((s8 *)boss5_gryphon_behavior_params[0] + 4);
        *(f32 *)((s8 *)arg2 + 4) = *(f32 *)((s8 *)boss5_gryphon_behavior_params[0] + 8);
        *(f32 *)((s8 *)arg2 + 8) = *(f32 *)((s8 *)boss5_gryphon_behavior_params[0] + 0xC);
        return;
    case 1:
        *(f32 *)((s8 *)arg1 + 4) = *(f32 *)((s8 *)boss5_gryphon_behavior_params[0] + 0x10);
        *(f32 *)((s8 *)arg1 + 8) = *(f32 *)((s8 *)boss5_gryphon_behavior_params[0] + 0x14);
        *(f32 *)((s8 *)arg2 + 4) = *(f32 *)((s8 *)boss5_gryphon_behavior_params[1] + 0);
        *(f32 *)((s8 *)arg2 + 8) = *(f32 *)((s8 *)boss5_gryphon_behavior_params[1] + 4);
        return;
    case 3:
        *(f32 *)((s8 *)arg1 + 4) = *(f32 *)((s8 *)boss5_gryphon_behavior_params[1] + 8);
        *(f32 *)((s8 *)arg1 + 8) = *(f32 *)((s8 *)boss5_gryphon_behavior_params[1] + 0xC);
        *(f32 *)((s8 *)arg2 + 4) = *(f32 *)((s8 *)boss5_gryphon_behavior_params[1] + 0x10);
        *(f32 *)((s8 *)arg2 + 8) = *(f32 *)((s8 *)boss5_gryphon_behavior_params[1] + 0x14);
        return;
    }
}

void TBoss8Dragon::get_follow_camera_offsets(u8 *arg1) {
    if (boss5_gryphon_instance == NULL) {
        VecCopy((Vec *)this, (const Vec *)boss8_dragon_follow_camera_offsets);
        VecCopy((Vec *)arg1, (const Vec *)lbl_80487CD8);
        return;
    }
    ((TBoss5Gryphon *)boss5_gryphon_instance)->fill_follow_camera_params((u8 *)this, arg1);
}

struct O_80065FD4 { u16 a; u16 b; u32 c[4]; };

extern "C" {

const Vec *get_arena_center(void) {
    return &lbl_80437938;
}

}

int TBoss8Dragon::get_instance_count() { return (saddr)boss5_gryphon_instance; }

void TBoss5Gryphon::apply_poison_status() {  }
void TBoss5Gryphon::apply_paralysis() {  }
void TBoss5Gryphon::apply_slow_status() {  }
void TBoss5Gryphon::apply_confusion_status() {  }
void TBoss5Gryphon::apply_movement_ailment(s32) {  }
void TBoss5Gryphon::apply_shock_status() {  }
void TBoss5Gryphon::clear_harmful_statuses() {  }
void TBoss8Dragon::init_color() { *(u8 *)((char*)this + 0x0) = 160; *(u8*)((char*)this + 0x1) = 10; }

void TBoss8Dragon::send_spawn_params_packet() { byteswap_action_packet(); send_subcommand((u8 *)this); }

void TBoss8Dragon::byteswap_action_packet() {
    ((G_ClientIDHeader *)this)->bswap();
    ((TBoss8Dragon *)((char *)this + 20))->byteswap_record();
    bswap_32((u32 *)((void *)((char *)this + 4)));
    bswap_32((u32 *)((void *)((char *)this + 8)));
    bswap_32((u32 *)((void *)((char *)this + 12)));
    bswap_32((u32 *)((void *)((char *)this + 16)));
}

void TBoss8Dragon::byteswap_record() {
    O_80065FD4 *p = (O_80065FD4 *)this;
    s32 i;
    bswap_16(&p->a);
    bswap_16(&p->b);
    for (i = 0; i < 4; i++) {
        bswap_32(&p->c[i]);
    }
}

void TBoss8Dragon::send_boss_actions() { bswap_boss_actions(); send_subcommand((u8 *)this); }

void TBoss8Dragon::bswap_boss_actions() {
    saddr arg0 = (saddr)this;
    ((G_ClientIDHeader *)arg0)->bswap();
    bswap_32((u32 *)(arg0 + 4));
    bswap_32((u32 *)(arg0 + 8));
    bswap_32((u32 *)(arg0 + 0xC));
}

extern "C" {

void TBoss8Dragon__sub_800660A4(void* p) { *(u8*)((char*)p + 0x0) = 159; *(u8*)((char*)p + 0x1) = 4; }

void fn_800660B8(u8 *arg0) {
    *(s32 *)((s8 *)arg0 + 0xB0) = (s32) (*(s32 *)((s8 *)arg0 + 0xB0) & 0xFFFFFFFB);
    *(s32 *)((s8 *)arg0 + 0xB0) = (s32) (*(s32 *)((s8 *)arg0 + 0xB0) | 1);
}

void attach_particle_model(void *particle, NJS_OBJECT *model, GinjaTextureList *texlist, AnimationMotion *motion, s32 arg4,
                           f32 farg0) {
    *(NJS_OBJECT **)((s8 *)particle + 0x4C) = model;
    *(GinjaTextureList **)((s8 *)particle + 0x50) = texlist;
    *(AnimationMotion **)((s8 *)particle + 0x54) = motion;
    *(u16 *)((s8 *)particle + 0x2C) = (u16) (*(u16 *)((s8 *)particle + 0x2C) | 0x200);
    *(f32 *)((s8 *)particle + 0x5C) = farg0;
    if (arg4 != 0) {
        *(u16 *)((s8 *)particle + 0x2C) = (u16) (*(u16 *)((s8 *)particle + 0x2C) | 0x400);
    }
}

}

__declspec(section ".sdata2") const f32 lbl_805D8D80 = 12.0f;
extern const f32 lbl_805D8D84;
__declspec(section ".sdata2") const f32 lbl_805D8D84 = 65.0f;
__declspec(section ".sdata2") const f32 lbl_805D8D88 = 1.0f;
__declspec(section ".sdata2") const f32 lbl_805D8D8C = 40.0f;
__declspec(section ".sdata2") const f32 lbl_805D8D90 = 3.0f;
__declspec(section ".sdata2") const f32 lbl_805D8D94 = -1000.0f;
__declspec(section ".sdata2") const f32 lbl_805D8D98 = 3.05175781e-05f;
__declspec(section ".sdata2") const f32 lbl_805D8D9C = 4294967300.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DA0 = 0.600000024f;
__declspec(section ".sdata2") const f32 lbl_805D8DA4 = 0.899999976f;
__declspec(section ".sdata2") const f32 lbl_805D8DA8 = 0.300000012f;
__declspec(section ".sdata2") const f32 lbl_805D8DAC = 0.400000006f;
__declspec(section ".sdata2") const f32 lbl_805D8DB0 = 0.800000012f;
__declspec(section ".sdata2") const f32 lbl_805D8DB4 = 0.200000003f;
__declspec(section ".sdata2") const f32 lbl_805D8DB8 = 22.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DBC = 75.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DC0 = 32.5f;
__declspec(section ".sdata2") const f32 lbl_805D8DC4 = 7935.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DC8 = 102400.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DCC = 4.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DD0 = 50.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DD4 = 360.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DD8 = 49152.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DDC = 7.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DE0 = 933.785706f;
__declspec(section ".sdata2") const f32 lbl_805D8DE4 = 17.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DE8 = 0.280000001f;
extern const f32 lbl_805D8DEC;
__declspec(section ".sdata2") const f32 lbl_805D8DEC = 180.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DF0 = 60.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DF4 = 25.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DF8 = 5.0f;
__declspec(section ".sdata2") const f32 lbl_805D8DFC = 19.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E00 = 15.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E04 = 0.75f;
__declspec(section ".sdata2") const f32 lbl_805D8E08 = 0.860000014f;
__declspec(section ".sdata2") const f32 lbl_805D8E0C = 11.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E10 = 10.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E14 = 9.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E18 = 2.29999995f;
__declspec(section ".sdata2") const f32 lbl_805D8E1C = 19.5f;
extern const f32 lbl_805D8E20;
__declspec(section ".sdata2") const f32 lbl_805D8E20 = 67.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E24 = 81.5f;
__declspec(section ".sdata2") const f32 lbl_805D8E28 = 16384.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E2C = 5120.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E30 = 230.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E34 = 0.25f;
__declspec(section ".sdata2") const f32 lbl_805D8E38 = 1.5f;
__declspec(section ".sdata2") const f32 lbl_805D8E3C = 2.1f;
__declspec(section ".sdata2") const f32 lbl_805D8E40 = 66.5f;
__declspec(section ".sdata2") const f32 lbl_805D8E44 = 6144.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E48 = 116.5f;
__declspec(section ".sdata2") const f32 lbl_805D8E4C = 300.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E50 = 120.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E54 = -4.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E58 = 3.5f;
__declspec(section ".sdata2") const f32 lbl_805D8E5C = 18.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E60 = 68.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E64 = 210.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E68 = 420.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E6C = 463.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E70 = 290.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E74 = 405.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E78 = 455.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E7C = 265.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E80 = 600.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E84 = 110.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E88 = -30.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E8C = 115.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E90 = 484.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E94 = 23.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E98 = 24.0f;
__declspec(section ".sdata2") const f32 lbl_805D8E9C = 20.5f;
__declspec(section ".sdata2") const f32 lbl_805D8EA0 = 150.0f;
__declspec(section ".sdata2") const f32 lbl_805D8EA4 = 0.15f;
__declspec(section ".sdata2") const f32 lbl_805D8EA8 = 27.0f;
__declspec(section ".sdata2") const f32 lbl_805D8EAC = 30.0f;
__declspec(section ".sdata2") const f32 lbl_805D8EB0 = 28.0f;
__declspec(section ".sdata2") const f32 lbl_805D8EB4 = 1.8f;
__declspec(section ".sdata2") const f32 lbl_805D8EB8 = 70.0f;
__declspec(section ".sdata2") const f32 lbl_805D8EBC = 14.0f;
__declspec(section ".sdata2") const f32 lbl_805D8EC0 = 21.0f;
__declspec(section ".sdata2") const f32 lbl_805D8EC4 = 8000.0f;
__declspec(section ".sdata2") const f32 lbl_805D8EC8 = 1000.0f;
}
