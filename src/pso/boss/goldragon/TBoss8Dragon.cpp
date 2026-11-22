#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/boss/DragonAttackParams.h"
#include "pso/unk/text_80087278.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/BmlResource.h"
#include "pso/system/EnemyBmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/math/FloatRounding.h"
#include "pso/boss/goldragon/TBoss8DragonEffBullet.h"
#include "pso/enemy/TObjEnemy.h"
#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/unk/TLobby_801E2F94.h"
#include "pso/render/RenderFadeState.h"
#include "types.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/system/PadRumble.h"
#include "pso/system/ControllerInputState.h"
#include "pso/enemy/epsilon/TObjEneEpsilon.h"
#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjChara.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/boss/goldragon/TBoss8DragonColli.h"
#include "pso/boss/goldragon/TBoss8DragonEffBreath.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/AngleUnits.h"
#include "pso/system/BmlResourceDescriptor.h"
#include <stdlib.h>
#include "pso/unk/text_803E2D70.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/map/CsnQuery.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/ui/hud/TMainCursor.h"

#include <stddef.h>
#include "pso/system/task/TObject.h"
#include "pso/boss/volopt/TBoss3Volopt.h"
#include "pso/boss/darkfalz/TBoss4DarkFalz.h"
#include "pso/boss/darkfalz/TBoss4Type2.h"
#include "pso/boss/goldragon/TBoss8DragonEffTail.h"
#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/enemy/panarms/TObjEnePanarms.h"
#include "pso/enemy/berura/TObjEneRe7Berura.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/vector.h"
#include "pso/quest/TQuestVmDownLoadServer.h"
#include "pso/network/protocol/protocol_types.h"
#include "pso/unk/TLobby_801E43E4.h"
#include "pso/system/byteswap.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/MaterialAlphaCompare.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/enemy/shinowa/TObjEneMe3ShinowaReal_8002ADD8.h"
#include "pso/unk/text_800870BC.h"
#include "pso/object/TObjControl.h"
#include "pso/boss/goldragon/TBoss8Dragon_802F3AB4.h"
#include "pso/boss/goldragon/TBoss8DragonDemo.h"
#include "pso/boss/dragon/TBoss1Dragon.h"
#include "pso/render/render_util.h"
#include "pso/unk/TLobby_802268F4.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"
#include "pso/boss/derolle/TObjBoss2Tunnel_8007E418.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/object/ambient/TObjLight.h"

struct Rot_802F9D08 { s32 x, y, z; };

struct F3_802FB220 { f32 f[3]; };

struct G_802FB220 { F3_802FB220 *value; u8 rest[8]; };

extern "C" {
extern s32 local_client_id;
extern s32 TBoss8Dragon__data_805D69B8;
extern u8 *TBoss8Dragon__data_80541DDC[];
int TBoss8Dragon__sub_802FB984(void);
extern s32 lbl_805D69B4;
s32 fn_802F2E7C(int, void *, int);
f32 atan2_float(f32 y, f32 x);
void TBoss8Dragon__sub_802FB300(void);
}
extern u16 TBoss8Dragon__data_805D69BC;
f32 sample_acceleration_curve(AccelerationCurve *c, f32 t);
void init_acceleration_curve(AccelerationCurve *c, f32 a, f32 d, f32 length, f32 speed);
extern "C" {
void TBoss8Dragon__sub_802FC500(u8 *boss8_dragon);
u16 get_entity_id(u8 *);
f32 newton_sqrtf(f32);
void TBoss8Dragon__sub_802FB1B0(TBoss8Dragon *dragon, int x, f32 c);
void TBoss8Dragon__sub_802FB220(void *o, int x, u32 a);

// Third argument of TBoss8Dragon::clone_node_tree, stored in every cloned node.
struct Boss8DragonNodeState {
    s32 unk0;
    s32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
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

struct Stack_802F4760 {
    s32 sp8;
    f32 spC;
    u8 trailing_storage[0x4];
};

struct Obj_802F44D8 {
    u8 pad0[0x34];
    saddr f34;
    u8 v38[0x5C - 0x38];
    s32 f5C;
    s32 f60;
    s32 f64;
    u8 v68[0xF8 - 0x68];
    saddr fF8;
    u8 padFC[0x3C0 - 0xFC];
    s32 f3C0;
    u8 pad3C4[0x3EC - 0x3C4];
    u8 f3EC[0x434 - 0x3EC];
    u8 f434[4];
};

saddr TBoss8Dragon__data_80541DC8[5];
u8 *TBoss8Dragon__data_80541DDC[3];
}
RecoveredGlobal_lbl_80541DE8 lbl_80541DE8;
RecoveredGlobal_lbl_80541DF4 lbl_80541DF4;
extern "C" {
Boss8DragonNodeState lbl_80541E18;
}
Boss8DragonReferencePosVec boss8_dragon_reference_pos_vec;
DragonForwardReferenceVec dragon_forward_reference_vec;
extern "C" {



struct Obj_802FAC08 { u8 pad0[0x38]; f32 x; u8 pad1[4]; f32 z; };

struct F3_802FB290 { f32 f[3]; };

struct G_802FB290 { F3_802FB290 *value; u8 rest[8]; };

struct Boss_802FC910 { u8 pad[0x394]; Vec pos; };

struct Pkt_802FBBFC { u8 hdr[2]; u16 a; s16 b; s16 c; s32 d; f32 e; f32 f; s8 g; };

struct Pkt_802FBCBC { u8 hdr[2]; u16 a; s16 b; s16 c; s32 d; f32 e; f32 f; s8 g; };

struct Cfg_802FCA58 { u8 pad[0x18]; s32 i18; s32 i1C; s32 i20; };

struct Cam_802FDC1C { s32 f0; f32 *p4; f32 *p8; };

s32 get_current_floor();
int setup_instance__9TObjEneDDFllPUcl(void*);
void free_collision_body_parts(void *);
s32 check_flag_100__10TObjPlayerFPv();
s32 play_sound_effect(s32, s32, s32, s32);
s32 is_closest_part();
void set_mode_params__12TBoss8DragonFSc(void *, unsigned char);
s32 TBoss8Dragon__sub_802F4760(void *owner, Vec *point, f32 farg0);
void TBoss8Dragon__sub_802FB828(u8 *ene_dd, s32 arg1);
s32 TBoss8Dragon__sub_802FCCBC(TBoss8Dragon *boss8_dragon);
void TBoss8Dragon__sub_802FD9D0(void);
s32 eval_bezier_curve__12TBoss8DragonFPviiPvf(void *, int, int, void *, f32);
s32 matrix_mult_vec_array(int, void *, int, int);
f32 vec3_dot(void *, void *);
s32 rotate_matrix_z(s32, s32);
void subtract_vector(void *, void *);
s32 rotate_matrix_x(s32, s32);
s32 scale_current_matrix(void *);
s32 post_translate_matrix(void *);
s32 scale_matrix(int, f32, f32, f32);
}

extern saddr TBoss8Dragon__data_80541DC8[];
extern Boss8DragonBmlRes *TBoss8Dragon__data_805D6988;
extern s32 lbl_805D69A4;
extern s32 TBoss8Dragon__data_805D698C;
extern s32 TBoss8Dragon__data_805D6994;
extern s32 TBoss8Dragon__data_805D6998;
extern saddr TBoss8Dragon__data_805D699C;
extern s32 TBoss8Dragon__data_805D69A0;
extern saddr TBoss8Dragon__data_805D69A8;
extern u8 *TBoss8Dragon__data_805D69AC;
extern s32 TLobby__designated_client_id;
extern s32 lbl_805D6990;
extern f32 boss8_dragon_visibility_distance;
extern void *lbl_805D28BC;


// The tables below mirror TBoss1Dragon's (same values where the Gol Dragon kept them).
extern const Vec TBoss8Dragon__data_804744A8 = {0.0f, 0.0f, 0.0f};
extern const DragonAttackParams lbl_804744B4 = {0, 0.0f, 30.0f, 7.0f, 1};
extern const DragonAttackParams TBoss8Dragon__body_effect_parameters = {0, 0.0f, 35.0f, 50.0f, 1};
extern const DragonAttackParams boss8_dragon_init_state_params = {0, 10.0f, 25.0f, 7.5f, 1};
extern const Vec lbl_804744F0 = {-35.0f, 0.0f, 10.0f};
extern const Vec lbl_804744FC = {-60.0f, 0.0f, -20.0f};
extern const s32 boss8_dragon_mode_params[10] = {0x41, 0x4c, 0x223, -1, 0xf0, 0x220, -1, 0x221, 0x222, 0xc5};
extern const s32 dragon_mode_params_a[10] = {0x200, 0x211, 0x212, 0x212, 0x94, 0x21d, -1, 0x21c, 0x21b, 0x219};
extern const s32 dragon_mode_params_b[10] = {0x41, 0x4c, 0x208, 0x203, 0xf0, 0x207, 0x200, 0x201, 0x202, 0x205};
extern const s32 dragon_camera_script_frame_table[35] = {0, 8, 0xa, 0x28, 0x29, 0x32, 0x33, 0x36, 0x37, 0x38, 0x39, 0x3a, 0x43, 0x46, 0x47, 0x48, 0x4a, 0x4c, 0x4f, 0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x58, 0x59, 0x5a, 0x5b, 0x5c, 0x5d, 0x5e, 0x64, 0x66, 0x3e7};
extern const s32 dragon_next_action_table[11] = {3, 0x27, 0x28, 0x29, 0x2a, 3, 5, 6, 0x23, 8, 0x21};
extern const s32 boss8_dragon_state_transition_table[8] = {0, 0, 2, 3, 3, 3, 0, 0};
extern const s32 boss8_dragon_action_pick_table[29] = {5, 6, 0xf, 0x2b, 0x13, 8, 0x27, 0x28, 3, 5, 6, 0x23, 8, 3, 2, 0x29, 0x2a, 0x27, 0x28, 3, 5, 6, 0x23, 8, 0x27, 0x28, 3, 2, 0x22};
extern const s32 boss8_dragon_action_pick_table_b[28] = {0x13, 8, 0x27, 0x28, 3, 0x27, 0x28, 3, 2, 3, 0x27, 0x28, 5, 6, 0x23, 8, 3, 5, 6, 0x23, 8, 2, 3, 5, 6, 0xf, 0x16, 0x21};
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
const char *lbl_804E4D8C[4] = {
    "boss1_s_nb_dragon.nj",
    "lo_boss1_s_nb_dragon.nj",
    "boss1_s_sd_dragon.nj",
    NULL,
};
const char *lbl_804E4D9C[27] = {
    "dead_boss1_s_nb_dragon.njm",
    "bossopgc_boss1_s_nb_dragon.njm",
    "down_boss1_s_nb_dragon.njm",
    "frin_boss1_s_nb_dragon.njm",
    "frloop_boss1_s_nb_dragon.njm",
    "frout_boss1_s_nb_dragon.njm",
    "land_boss1_s_nb_dragon.njm",
    "lift_boss1_s_nb_dragon.njm",
    "nkdown_boss1_s_nb_dragon.njm",
    "nkup_boss1_s_nb_dragon.njm",
    "nobi_boss1_s_nb_dragon.njm",
    "stand_boss1_s_nb_dragon.njm",
    "tatk_boss1_s_nb_dragon.njm",
    "walk_boss1_s_nb_dragon.njm",
    "wngclose_boss1_s_nb_dragon.njm",
    "wngopn_boss1_s_nb_dragon.njm",
    "daml_boss1_s_nb_dragon.njm",
    "dams_boss1_s_nb_dragon.njm",
    "fire_boss1_s_nb_dragon.njm",
    "fly_boss1_s_nb_dragon.njm",
    "flyshot_boss1_s_nb_dragon.njm",
    "kiri_boss1_s_nb_dragon.njm",
    "tobidasi_boss1_s_nb_dragon.njm",
    "tukomi_boss1_s_nb_dragon.njm",
    "wgwalk_boss1_s_nb_dragon.njm",
    "wing_boss1_s_nb_dragon.njm",
    NULL,
};
BmlResourceDescriptor lbl_804E4E08 = {"bm_boss8_dragon.bml", lbl_804E4D8C, lbl_804E4D9C, 3, 26};
const char *boss8_dragon_class_name = "TBoss8Dragon";
// Same records as TBoss1Dragon's foot-step / fireball attack parameters.
extern const DragonAttackParams boss8_dragon_breath_eff_params = {0, 10.0f, 15.0f, 8.0f, 1};
extern const DragonAttackParams TBoss8Dragon__breath_params = {1, 2.0f, 10.0f, 10.0f, 1};
extern const DragonAttackParams lbl_80474ACC = {1, 10.0f, 30.0f, 10.0f, 1};
extern const DragonAttackParams lbl_80474AE0 = {0, 10.0f, 0.0f, 10.0f, 1};
extern const s32 boss8_dragon_point_index_table[4] = {3, 4, 5, 6};
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
#define TBoss8Dragon__data_804E4C28 ((s32 *)TBoss8Dragon__data_804E4C28)


void direction_to_rotation_xz(u8 *dir, s32 *rot_a, s32 *rot_b);
void build_6xA8_gol_dragon_boss_actions(void *p);
extern "C" {
struct Info_802F4DD4 { u8 pad[8]; s32 a; s32 b; };
struct Drg_802F4DD4 {
    u8 pad0[0x38];
    Vec pos;
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
    AreaAttackHistory *attack_history;
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
struct Obj_802FAC08;
struct Rot_802F6838 { s32 x, y, z; };
s32 restore_player_cameras(void);
void activate_camera_mode(s32, f32);
void set_scripted_camera_pose(void *, void *, void *);
void vec3_add_to(void *, void *);
struct Pair_802F8578 { f32 a; f32 b; };
extern f32 lbl_805D69C0;
void subtractive_rng_seed(void *, s32);
f32 calc_random_ratio__10TObjPlayerFv(void *);
// Slot 87: per-action event dispatch through a table of handler members.
}
void create_boss8_piller_ctrl(saddr arg0, s32 arg1, f32 boss8_piller_ctrl);
extern "C" {
s32 __ct__14SubtractiveRngFv(void *arg0);
void *TBoss8Dragon__sub_802F3C24(void *object, void *set_data);
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
Node_802FDDD4 *clone_node_tree__12TBoss8DragonFPvPvi(Node_802FDDD4 *src, Node_802FDDD4 *dst, s32 v);
extern const f32 lbl_805D9E80;
f32 lbl_805D6980 = 5.0f * lbl_805D9E80;
f32 lbl_805D6984 = 7.0f * lbl_805D9E80;
}
Boss8DragonBmlRes *TBoss8Dragon__data_805D6988;
s32 TBoss8Dragon__data_805D698C;
s32 lbl_805D6990;
s32 TBoss8Dragon__data_805D6994;
s32 TBoss8Dragon__data_805D6998;
saddr TBoss8Dragon__data_805D699C;
s32 TBoss8Dragon__data_805D69A0;
s32 lbl_805D69A4;
saddr TBoss8Dragon__data_805D69A8;
u8 *TBoss8Dragon__data_805D69AC;
f32 boss8_dragon_visibility_distance;
extern "C" {
s32 lbl_805D69B4;
s32 TBoss8Dragon__data_805D69B8;
}
u16 TBoss8Dragon__data_805D69BC;
// (from _802FDDD4)
typedef struct A_802F3D6C { u8 pad0[4]; s32 idx; u8 pad8[8]; } A_802F3D6C;
typedef struct Anim_802F3D6C { u8 pad0[4]; u32 nframes; } Anim_802F3D6C;
typedef struct B_802F3D6C { u8 pad0[4]; Anim_802F3D6C *anim; } B_802F3D6C;
extern "C" {
extern s32 model_render_flags;
// (from _802F3CA0)
extern s32 saved_model_render_flags;
}
// (from _802F3EE4)
typedef struct Obj_802F3F20 {
    u8 pad0[0x326];
    s16 x326;
    u8 pad328[0x434 - 0x328];
    Vec pts[8];
} Obj_802F3F20;
extern "C" {
u8 *find_entity_by_id(void);
extern u8 *camera_ctrl_instance;
// (from _802F3F20)
s32 draw__10TObjMotionFv(void *, int);
// (from _802F42A0)
}
// (from _802F4324)
extern "C" {
BOOL is_split_screen(void); // TObjPlayer_80011014.h, whose other prototypes clash here
s32 TBoss8Dragon__sub_802F3F20(u8 *owner); // defined further down
}
void set_tev_swap_channels(u8 r, u8 g, u8 b, u8 a);
void init_tev_swap();
// (from _802F4380)
struct VOff_802F4480_arg0 { char pad_0[0x410]; char f_410[1]; char pad_411[0xB]; char f_41C[1]; };
// (from _802F4480)
void build_6xA8_gol_dragon_boss_actions(void* p) { *(u8*)((char*)p + 0x0) = 168; *(u8*)((char*)p + 0x1) = 6; }

void TBoss8Dragon::bswap_packet() { ((G_ClientIDHeader *)this)->bswap(); bswap_16((u16 *)((char*)this + 0x4)); bswap_16((u16 *)((char*)this + 0x6)); bswap_32((u32 *)((char*)this + 0x8)); }

void TBoss8Dragon::send_swapped_packet() { bswap_packet(); send_subcommand((u8 *)this); }

void TBoss8Dragon::clear_harmful_statuses() {  }

void TBoss8Dragon::apply_shock_status() {  }

void TBoss8Dragon::apply_movement_ailment(s32) {  }

void TBoss8Dragon::apply_confusion_status() {  }

void TBoss8Dragon::apply_slow_status() {  }

void TBoss8Dragon::apply_paralysis() {  }

void TBoss8Dragon::apply_poison_status() {  }

extern "C" {
Node_802FDDD4 *clone_node_tree__12TBoss8DragonFPvPvi(Node_802FDDD4 *src, Node_802FDDD4 *dst, s32 v) {
    Node_802FDDD4 *cur = dst;
    dst = dst + 1;
    copy_model_node((u8 *)cur, (u8 *)src);
    cur->v = v;
    if (src->c0 != NULL) {
        cur->c0 = dst;
        dst = (Node_802FDDD4 *)TBoss8Dragon::clone_node_tree(src->c0, dst, v);
    }
    if (src->c1 != NULL) {
        cur->c1 = dst;
        dst = (Node_802FDDD4 *)TBoss8Dragon::clone_node_tree(src->c1, dst, v);
    }
    return dst;
}
#define F(t, o) (*(t *)((u8 *)this + (o)))
void TBoss8Dragon::get_camera_offsets(Vec *eye, Vec *target) {
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
        VecCopy(eye, (Vec *) lbl_804E4FF0 + idx);
        VecCopy(target, (Vec *) lbl_804E5014 + idx);
        if (*(u32 *)((s8 *)TBoss8Dragon__data_805D69AC + 0x64C) == 1) {
            target->y += 10.0f;
            target->z += 10.0f;
        }
        return;
    }
    eye->x = 0.0f;
    target->x = 0.0f;
    switch (mode) {
    case 1:
    default:
        if (TCameraCtrl::get_camera_id() == 2) {
            VecCopy(eye, (Vec *)lbl_804E4FD8);
            VecCopy(target, (Vec *)lbl_804E4FE4);
            break;
        }
        eye->y = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p4[0];
        eye->z = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p4[1];
        target->y = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p4[2];
        target->z = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p4[3];
        break;
    case 0:
        eye->y = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p4[4];
        eye->z = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p4[5];
        target->y = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p8[0];
        target->z = (*(Cam_802FDC1C *)&TBoss8Dragon__data_80541DDC).p8[1];
        break;
    }
}

void TBoss8Dragon__sub_802FDA78(void) {
    s32 i;
    s32 j;

    TBoss8Dragon__data_805D6988 = (Boss8DragonBmlRes *)load_enemy_bml_resource(&lbl_804E4E08);
    lbl_805D69A4 = count_tree_nodes((NJS_OBJECT *)TBoss8Dragon__data_805D6988->models->node_tree);
    TBoss8Dragon__data_805D69A8 = (saddr)TQuestVmDownLoadServer::alloc(lbl_805D69A4 * 0x50);
    lbl_80541E18.unk0 = 0;
    lbl_80541E18.unk4 = 0;
    lbl_80541E18.unk8 = 0.0f;
    lbl_80541E18.unkC = 0.0f;
    lbl_80541E18.unk10 = 0.0f;
    lbl_80541E18.unk14 = 0.0f;
    TBoss8Dragon::clone_node_tree(TBoss8Dragon__data_805D6988->models->node_tree, (void *)TBoss8Dragon__data_805D69A8,
                                  (saddr)&lbl_80541E18);
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
    lbl_80541DF4.unk18.y = -1.0f;
    lbl_80541DF4.unk18.z = 1.0f;
    TBoss8Dragon__data_805D6994 = 0;
    TBoss8Dragon__data_805D6998 = 0;
    TBoss8Dragon__data_805D699C = 0;
    TBoss8Dragon__data_805D69A0 = 0;
    TBoss8Dragon__data_805D69AC = 0;
    for (i = 0; i < 5; i++) {
        TBoss8Dragon__data_80541DC8[i] = (saddr)TLobby::dispatch_shared_handler_b(TBoss8Dragon__camera_offset_index_table[i]);
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

void *TBoss8Dragon::create(void *set_data) {
    return new TBoss8Dragon(tl_04, set_data);
}

void TBoss8Dragon::free_static() {
    if ((u32) (*(u32 *)&TBoss8Dragon__data_805D69A8) != 0U) {
        TAdSinglePlyChrSelectGC::safe_free((uaddr)((void*)(*(uaddr *)&TBoss8Dragon__data_805D69A8)));
        (*(u32 *)&TBoss8Dragon__data_805D69A8) = 0U;
    }
    if ((uaddr) TBoss8Dragon__data_805D6988 != 0U) {
        delete (BmlResource *)TBoss8Dragon__data_805D6988;
        TBoss8Dragon__data_805D6988 = 0U;
    }
}

void TBoss8Dragon__sub_802FD9D0(void) { (*(int *)&TBoss8Dragon__data_805D69B8) = 0; }

#define TBoss8Dragon__data_805D6988 ((u8 *)TBoss8Dragon__data_805D6988)
#define lbl_804E4C3C ((u8 *)lbl_804E4C3C)
#define lbl_804E4C58 ((u8 *)lbl_804E4C58)
#define lbl_804E4E18 ((u8 *)lbl_804E4E18)
TBoss8Dragon::TBoss8Dragon(TObject *parent, void *set_data) : TObjEneDD_ST(parent), sub_tasks(NULL) {
    u32 sp8[4];
    s32 i;
    s32 j;
    u8 *q;
    u8 *cfg;

    __ct__14SubtractiveRngFv(&m_764);
    this->m_name = boss8_dragon_class_name;
    if (TBoss8Dragon__data_805D69AC == NULL) {
        TBoss8Dragon__data_805D69AC = (u8 *)this;
    }
    invoke_initialization_hook(set_data);
    this->flags = 0;
    if (this->exchange_object_state(sp8, 1) != 0 && (sp8[0] & 0x12008) == 0x12008) {
        this->flags |= 8;
    }
    this->init_position_vectors();
    this->model = *(void **)((s8 *)(*(u8 **)((s8 *)TBoss8Dragon__data_805D6988 + 0x42C)) + 8);
    this->texlist = *(s32 *)((s8 *)(*(u8 **)((s8 *)TBoss8Dragon__data_805D6988 + 0x42C)) + 0xC);
    this->scale.x = 2.0f;
    this->scale.y = 2.0f;
    this->scale.z = 2.0f;
    init_model((CollisionBody *)lbl_804E4C58, (s32)7);
    this->motion_flags = 0;
    this->set_field_d8((saddr)lbl_804E4E18);
    this->set_field_dc(*(s32 *)((s8 *)TBoss8Dragon__data_805D6988 + 0x430));
    this->requested_action = 0;
    this->set_animation(this->requested_action);
    this->set_field_b8(this->requested_action);
    reset_hp((u8 *)(TLobby::register_boss(0x12)), (u8 *)(TBoss8Dragon__data_80541DC8[TBoss8Dragon__data_804E4C28[0]]), (u8 *)(TLobby::register_object(0x12)));
    this->set_state_flag_1();
    *(u8 **)((s8 *)this + 0x350) = lbl_804E4C3C;
    initialize_enemy_state(0x4C);
    this->wall_reach = 20.0f;
    this->enemy_init_acquire_period(0xA);
    this->enemy_init_validate_period(0xA);
    this->m_3e4 = 0;
    this->flags |= 1;
    for (i = 0; i < 3; i++) {
        VecCopy(&this->pad_3EC[i], &this->position);
    }
    VecCopy(&this->m_410, &this->position);
    VecCopy(&this->m_41c, &this->position);
    VecCopy(&this->m_428, &this->position);
    for (i = 0; i < 0x22; i++) {
        VecCopy(&this->node_positions[i], &this->position);
    }
    this->m_5cc = 0.0f;
    this->m_5d0 = 0.0f;
    this->m_5d4 = 0.0f;
    this->m_5d8 = 0.0f;
    this->m_5dc = 0.0f;
    this->m_5e0.x = 0.0f;
    this->m_5e0.y = 0.0f;
    this->m_5e0.z = 0.0f;
    curve0.reset_coords();
    curve1.reset_coords();
    VecCopy((Vec *)((u8 *)this + 0x634), &this->position);
    VecCopy((Vec *)((u8 *)this + 0x640), &this->position);
    this->m_64c = 0;
    this->m_650 = 0;
    this->m_654 = 1;
    this->m_65c = 0.0f;
    this->m_660 = 0.0f;
    this->m_670 = 0.0f;
    this->sequenceCursor = 0;
    this->hpThreshold = 0;
    cfg = TBoss8Dragon__data_80541DDC[2];
    this->finalHpThreshold = *(f32 *)((s8 *)cfg + 8) * this->hpmax / 100.0f;
    q = *(u8 **)((s8 *)this + 0x2B0);
    *(f32 *)((s8 *)q + 0x10) = 10.0f;
    sub_802FC850();
    this->tail = new TBoss8DragonEffTail(this, &this->node_positions[15]);
    this->attack_history = new AreaAttackHistory(4);
    this->collider = new TBoss8DragonColli(&this->sub_tasks);
    this->m_688 = 0.0f;
    this->m_68c = 0.0f;
    this->m_690 = 0.0f;
    this->m_694 = 0.0f;
    this->sector_count = 0;
    this->m_69c = 0;
    for (i = 0; i < 0xC; i++) {
        this->sector_radii[i] = 0.0f;
    }
    this->m_6d0 = 0;
    for (j = 0; j < 4; j++) {
        this->renderFadeStates[j].activate_and_dispatch();
    }
    this->m_74c = 0;
    this->m_750 = 0xFFFF;
    this->m_754 = 0;
    this->m_758 = 0;
    this->set_mode_params(2);
    this->stateStep = 0;
    this->impactAge = 0;
    this->m_854 = 0;
    this->m_858 = 0;
    this->m_85c = 0;
    this->m_860 = 0;
    this->m_864 = 0.0f;
    this->m_868 = 0.0f;
    this->m_86c = 0.0f;
    this->m_870 = 0.0f;
    this->m_874 = 0.0f;
    this->m_878 = 0.0f;
    this->m_87c = 0.0f;
    this->m_880 = 0.0f;
    this->m_884 = 0.0f;
    this->m_888 = 0.0f;
    this->m_88c = 0.0f;
    this->m_890 = 0;
    this->m_894 = 0;
    this->m_898 = 0;
    this->m_89c = 0;
    this->controller_input = &controller_input_state.controllers[2];
    this->m_6d4 = 0;
    this->mode = 0;
    if (TObjEneDD::is_main_phase_15() != 0) {
        if (this->update_lobby_state() != 0) {
            this->m_3e0 = 0;
        } else {
            this->m_3e0 = 1;
        }
    } else {
        this->m_3e0 = 0;
    }
    init_default(this);
    if (TBoss8Dragon__data_805D69AC == (u8 *)this) {
        this->mode = 0x1E;
        TBoss8Dragon__sub_802F3C24((u8 *)this, set_data);
    }
    if (!(this->flags & 8)) {
        this->dispatch_action(this->mode, 4);
    }
    this->m_8a0 = 0;
}

#undef TBoss8Dragon__data_805D6988
#undef lbl_804E4C3C
#undef lbl_804E4C58
#undef lbl_804E4E18
}
TBoss8Dragon::~TBoss8Dragon() {
    if (collider != NULL) {
        delete collider;
        collider = NULL;
    }
    if (attack_history != NULL) {
        delete attack_history;
        attack_history = NULL;
    }
    if (tail != NULL) {
        delete tail;
        tail = NULL;
    }
    free_collision_body_parts(this);
    if (TBoss8Dragon__data_805D69AC == (u8 *)this) {
        TBoss8Dragon__data_805D69AC = NULL;
    }
}

void TBoss8Dragon::run_task() {
    u8 *self = (u8 *)this;
    s32 temp_r0_2;
    s32 temp_r30;
    s32 temp_r30_2;
    s32 i;
    if (TObjPlayer::check_demo_mode() != 0) {
        this->run_demo_task();
        return;
    }
    if (*(s32 *)&this->flags & 8) {
        this->send_entity_set_flags();
        ((TObject *)self)->queue_destruction();
        return;
    }
    if (this->m_74c != 0) {
        this->freeze_player_at_self();
        this->m_754 = this->m_754 + 1;
    } else if ((TObjEneDD::is_main_phase_15() != 0) && ((s32) *(s32 *)&this->m_6d4 == 0)) {
        temp_r30 = *(s32 *)&this->m_3e0;
        if (this->update_lobby_state() != 0) {
            *(s32 *)&this->m_3e0 = 0;
            if ((s32) *(s32 *)&this->m_3e0 != temp_r30) {
                this->m_8a0 = 1;
            }
        } else {
            *(s32 *)&this->m_3e0 = 1;
        }
    }
    temp_r30_2 = TObjEneDD::query_teammate_state();
    this->update_attack_stat_status();
    this->update_defense_stat_status();
    if (temp_r30_2 == 0) {
        if (this->mode == 0x15 || this->mode == 0x16 || this->mode == 0x17) {
            *(s32 *)&this->actorFlags = (s32) (*(s32 *)&this->actorFlags | 0x800);
        } else {
            *(s32 *)&this->actorFlags = (s32) (*(s32 *)&this->actorFlags & 0xFFFFF7FF);
        }
        if (this->m_74c != 0) {
            if ((s32) this->m_750 == (s32) local_client_id) {
                if ((this->test_flag30_512() != 0) && (this->is_health_low() != 0)) {
                    if ((s16) this->hp < this->finalHpThreshold) {
                        this->hp = this->finalHpThreshold;
                    }
                    this->clear_attack_receipts();
                }
                if ((s32) TBoss8Dragon__data_805D69B8 == 0) {
                    this->release_grabbed_player();
                } else {
                    this->check_death();
                }
                this->dispatch_action(this->mode, 8);
                this->dispatch_action(this->mode, 0);
            } else {
                if ((this->test_flag30_512() != 0) && (this->is_health_low() != 0)) {
                    if ((s16) this->hp < this->finalHpThreshold) {
                        this->hp = this->finalHpThreshold;
                    }
                    this->clear_attack_receipts();
                }
                if ((s32) TBoss8Dragon__data_805D69B8 == 0) {
                    this->release_grabbed_player();
                }
                this->dispatch_action(this->mode, 0);
            }
        } else {
            temp_r0_2 = this->m_3e0;
            if (temp_r0_2 != 1) {
                if (temp_r0_2 == 2) {
                    this->dispatch_action(this->mode, 2);
                } else {
                    if ((this->test_flag30_512() != 0) && (this->is_health_low() != 0)) {
                        if ((s16) this->hp < this->finalHpThreshold) {
                            this->hp = this->finalHpThreshold;
                        }
                        this->clear_attack_receipts();
                    }
                    this->select_next_action();
                }
                this->dispatch_action(this->mode, 8);
                this->dispatch_action(this->mode, 0);
            } else {
                if ((this->test_flag30_512() != 0) && (this->is_health_low() != 0)) {
                    if ((s16) this->hp < this->finalHpThreshold) {
                        this->hp = this->finalHpThreshold;
                    }
                    this->clear_attack_receipts();
                }
                this->dispatch_action(this->mode, 0);
            }
        }
    }
    this->sub_800BBA0C();
    this->update_body_colliders();
    this->store_position();
    this->submit_default_cursor_candidate();
    add_radar_scaled_marker(&this->position, -0x5DB4, 1, 1, 2.0f);
    VecCopy((Vec *)(&this->m_640), &this->body_center);
    if (temp_r30_2 == 0) {
        ((TObject *)(self + 0x3C4))->run_tasks();
    }
    project_sound_origin_from_camera((saddr)(self + 0x38), (u8 *)(self + 0x634), 0.4f);
    if (!(*(s32 *)&this->flags & 0x100)) {
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].update();
        }
    }
}

void TBoss8Dragon::select_next_action() {
    u8 *self = (u8 *)this;
    s32 temp_r4;
    temp_r4 = this->flags;
    if (temp_r4 & 0x40) {
        if (!(temp_r4 & 0x20) && (this->hp <= 0)) {
            this->send_action_packet(0x16);
            return;
        }
        goto block_14;
    }
    if (is_health_low() != 0) {
        if (!(this->flags & 0x10)) {
            if (check_damage_reaction() == 0) {
                if (((s32 (*)(void *))TBoss8Dragon__sub_802FB984)(self) != 0) {
                    return;
                }
                goto block_14;
            }
        } else {
            goto block_14;
        }
    } else {
        if (!(this->flags & 0x20) && (this->hp <= 0)) {
            if ((s32) this->m_3e4 == 1) {
                this->send_action_packet(0xC);
                return;
            }
            this->send_action_packet(0x15);
            return;
        }
block_14:
        if ((s32) lbl_805D69B4 != 0) {
            this->dispatch_action(this->mode, 2);
            return;
        }
        if (this->m_74c != 0) {
            this->dispatch_action(this->mode, 0xB);
            return;
        }
        this->dispatch_action(this->mode, 9);
    }
}

void TBoss8Dragon::check_death() {
    if (is_health_low() != 0) {
        if (check_damage_reaction() != 0) {
            return;
        }
        goto block_8;
    }
    if (!(this->flags & 0x20) && (this->hp <= 0)) {
        if ((s32) this->m_3e4 == 1) {
            send_action_packet(0xC);
            return;
        }
        send_action_packet(0x15);
        return;
    }
block_8:
    this->dispatch_action(this->mode, 0xB);
}

void TBoss8Dragon::refresh_target() {  }

void TBoss8Dragon::run_death_reaction() {  }

void TBoss8Dragon::run_hit_reaction() {  }

void TBoss8Dragon::run_miss_reaction() {  }

void TBoss8Dragon::set_state_22() { if (this->mode != 22) { send_action_packet(22); } }

s32 TBoss8Dragon__sub_802FCCBC(TBoss8Dragon *boss8_dragon) {
    if (boss8_dragon->mode != 0x1E) {
        return 1;
    }
    return 0;
}

void TBoss8Dragon::store_position() {
    u8 *self = (u8 *)this;
    VecCopy((Vec *)(self + 0x2FC), (Vec *)(self + 0x434));
    VecCopy((Vec *)(self + 0x74), (Vec *)(self + 0x2FC));
}

void TBoss8Dragon::update_body_colliders() {
    Vec pts[7];
    Vec *p;
    s32 i;

    p = pts;
    VecCopy(p++, (Vec *)((u8 *)this + 0x434));
    VecCopy(p++, (Vec *)((u8 *)this + 0x470));
    VecCopy(p++, (Vec *)((u8 *)this + 0x458));
    VecCopy(p++, (Vec *)((u8 *)this + 0x440));
    VecCopy(p++, (Vec *)((u8 *)this + 0x5B4));
    VecCopy(p++, (Vec *)((u8 *)this + 0x4C4));
    VecCopy(p, (Vec *)((u8 *)this + 0x500));
    update_local_colliders_from_world(this, pts);
    for (i = 0; i < 7; i++) {
        if (bodies[i].offset.y >= 30.0f) {
            set_collider_contact_high((u8 *)&bodies[i]);
        } else {
            set_collider_contact_low((u8 *)&bodies[i]);
        }
    }
    if (this->mode != 9) {
        set_collider_contact_high((u8 *)&bodies[3]);
        set_collider_contact_high((u8 *)&bodies[4]);
    }
    bodies[0].unk_28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i20;
    bodies[1].unk_28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i1C;
    bodies[2].unk_28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i1C;
    bodies[3].unk_28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i20;
    bodies[4].unk_28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i20;
    bodies[5].unk_28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i18;
    bodies[6].unk_28 = ((Cfg_802FCA58 *) TBoss8Dragon__data_80541DDC[0])->i20;
}

s32 TBoss8Dragon::update_linked_position() {
    return TObjEneDD_ST::update_linked_position(1000.0f);
}

void TBoss8Dragon::sub_802FC9D8() {
    f32 temp_f1;
    f32 temp_f2;
    temp_f2 = this->destination.x;
    this->m_5cc = (f32) (temp_f2 - this->m_410.x);
    this->m_5d0 = 0.0f;
    temp_f1 = this->destination.z;
    this->m_5d4 = (f32) (temp_f1 - this->m_410.z);
    this->m_5d8 = normalize_vector_xz((Vec *)&this->m_5cc);
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::calc_orbit_xz(f32 *arg1, f32 *arg2) {
    *arg1 = (185.0f * sin_table_lookup(this->rotation_y)) + this->position.x;
    *arg2 = (185.0f * cos_table_lookup(this->rotation_y)) + this->position.z;
}

#pragma pop
s32 TBoss8Dragon::is_near_target() {
    Boss_802FC910 *o = (Boss_802FC910 *)this;
    struct { f32 b[2]; Vec c; } s;
    Vec a;
    calc_orbit_xz(s.b, (f32 *)&s.c);
    VecCopy(&a, &o->pos);
    subtract_vector(&a, s.b);
    return normalize_vector_xz((Vec *)&a) <= 35.0f;
}

void TBoss8Dragon::init_default(void *boss8_dragon) {
    ((TBoss8Dragon *)boss8_dragon)->set_damage_phase_value(0);
}

void TBoss8Dragon::set_damage_phase_value(s32 arg1) {
    if (arg1 == 0) {
        this->sequenceCursor = 0;
        return;
    }
    this->sequenceCursor = 0x32;
}

s32 TBoss8Dragon::is_health_low() {
    TBoss8Dragon * boss8_dragon = this;
    return boss8_dragon->sequenceCursor < 0x32;
}

s32 TBoss8Dragon::sub_802FC88C() {
    return (u8) (this->sequenceCursor >= 0x32);
}

void TBoss8Dragon::sub_802FC850() {
    s16 step = this->hpmax / 10;
    s16 value = this->hpmax - step;
    step += step;
    while (this->hp <= value) {
        value -= step;
    }
    this->hpThreshold = value;
}

s32 TBoss8Dragon::sub_802FC674(f32 *out) {
    TObjPlayer *list[12];
    TObjPlayer *p;
    s32 bestHp;
    s32 n;
    s32 i;
    s32 best;
    Vec *apos;
    TObjPlayer *a;
    TObjPlayer *b;
    s32 found;
    s32 i2;
    s32 j;
    s32 k;
    f32 lim;
    lim = 6400.0f;
    n = 0;
    for (i = 0; i < 12; i++) {
        p = get_player_by_client_id(i);
        if (((TObjEneDD *)p)->is_valid_target() != 0 &&
            horizontal_distance_squared(&p->position, &this->position) >= lim) {
            list[n] = p;
            n++;
        }
    }
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        VecCopy((Vec *)out, &list[0]->position);
    } else {
        lim = 100.0f;
        best = 0;
        found = 0;
        for (i2 = 0; i2 < n; i2++) {
            a = list[i2];
            apos = &a->position;
            for (j = i2 + 1; j < n; j++) {
                b = list[j];
                if (newton_sqrtf(horizontal_distance_squared(&b->position, apos)) < lim) {
                    s32 sum;
                    found = 1;
                    sum = a->hp + b->hp;
                    if (sum > best) {
                        best = sum;
                        out[0] = 0.5f * (apos->x + b->position.x);
                        out[1] = 0.5f * (apos->y + b->position.y);
                        out[2] = 0.5f * (apos->z + b->position.z);
                    }
                }
            }
        }
        if (found == 0) {
            bestHp = 0;
            for (k = 0; k < n; k++) {
                p = list[k];
                if (bestHp < p->hp) {
                    bestHp = p->hp;
                    VecCopy((Vec *)out, &p->position);
                }
            }
        }
    }
    return 1;
}

s32 TBoss8Dragon::sub_802FC580(f32 *out) {
    s32 ang;
    s32 i;
    s32 n;
    f32 r;
    i = (s32)floor_to_float(12.0f * this->random_ratio());
    n = this->sector_count;
    if (n < 12) {
        this->sector_count = n + 1;
        while (0.0f != this->sector_radii[i]) {
            i++;
            if (i >= 12) {
                i = 0;
            }
        }
        r = this->rand_range(100.0f, 220.0f);
        this->sector_radii[i] = r;
    } else {
        r = this->sector_radii[i];
    }
    ang = i * 0x1555;
    out[0] = r * sin_table_lookup(ang);
    out[1] = 0.0f;
    out[2] = r * cos_table_lookup(ang);
    return 1;
}

void TBoss8Dragon__sub_802FC500(u8 *boss8_dragon) {
    if (((TBoss8Dragon *)boss8_dragon)->is_health_low() != 0) {
        VecCopy((Vec *)(boss8_dragon + 0x394), (Vec *)(boss8_dragon + 0x38));
        *(f32 *)((s8 *)boss8_dragon + 0x398) = 0.0f;
        normalize_vector_xz((Vec *)(boss8_dragon + 0x394));
        ((TBoss8Dragon *)boss8_dragon)->destination.x *= -100.0f;
        ((TBoss8Dragon *)boss8_dragon)->destination.z *= -100.0f;
        return;
    }
    VecCopy((Vec *)(boss8_dragon + 0x394), &TBoss8Dragon__data_804744A8);
}

s32 TBoss8Dragon::select_target_in_front() {
    Vec d;
    Vec ref;
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
    ref.x = sin_table_lookup(this->rotation_y);
    ref.y = 0.0f;
    ref.z = cos_table_lookup(this->rotation_y);
    for (i = 0; i < count; i++) {
        player = (u8 *)TObjPlayer::get_player_data(i);
        if (((TObjMotion *)player)->is_alive() != 0) {
            VecCopy(&d, (Vec *)(player + 0x38));
            subtract_vector(&d, &this->position);
            normalize_vector_xz((Vec *)&d);
            if (vec3_dot(&d, &ref) > lim) {
                ids[n++] = get_entity_id(player);
            }
        }
    }
    if (n <= 0) {
        this->enemy_clear_target();
        return 0;
    }
    if (n == 1) {
        enemy_set_target_id(this, ids[0]);
        return 1;
    }
    enemy_set_target_id(this, ids[(s32)floor_to_float((f32)n * this->random_ratio())]);
    return 1;
}

void TBoss8Dragon::play_effect_sound(s32 sound_id) {
    play_sound_effect(sound_id, (saddr)this + 0x634, 0, 0);
}

void TBoss8Dragon::spawn_trap(s32 id) {
    play_persistent_sound(id, (saddr)this, (uaddr)&this->m_634, 0, 0);
}

void TBoss8Dragon::try_spawn_trap() {
    if ((this->flags & 0x40) && (is_closest_part() != 0)) {
        this->spawn_trap(0x4003D013);
    }
}

void TBoss8Dragon::play_sound_if_in_band() {
    u8 *self = (u8 *)this;
    if ((this->is_passing_frame(4.0f) != 0) || (this->is_passing_frame(24.5f) != 0)) {
        ((TBoss8Dragon *)((saddr) self))->play_effect_sound(0x4003A801);
    }
}

void TBoss8Dragon::spawn_effect_if_in_band() {
    if (this->is_passing_frame(5.0f) != 0) {
        this->play_effect_sound(0x4003A804);
    }
}

void TBoss8Dragon::reset_timer() { this->m_3e4 = 0; }

void TBoss8Dragon::set_state() { this->m_3e4 = 1; }

void TBoss8Dragon::set_action_state() { this->m_3e4 = 2; }

void TBoss8Dragon::set_active_flag() { this->flags = (this->flags | 0x1); this->position.y = 0.0f; }

void TBoss8Dragon::activate_attack() { this->flags = (this->flags | 0x1); this->position.y = 180.0f; }

void TBoss8Dragon::reset_action() { this->flags = (this->flags & 0xfffffffe); this->position.y = -400.0f; }

void TBoss8Dragon::check_hit_result(s32 arg1, s32 arg2) {
    if (angle_diff_s16(arg1, arg2) >= 0) {
        this->m_654 = 1;
        return;
    }
    this->m_654 = -1;
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::sub_802FC060(s32 arg1) {
    f32 height;
    f32 turn;
    f32 half;
    f32 frames = 35.0f;
    f32 k = 25.0f;

    this->m_650 = (s16) this->m_650;
    height = (f32) this->m_650;
    turn = (f32) angle_diff_s16(this->rotation_y, arg1);
    half = 0.5f * height;
    this->m_660 = -(2.0f * (turn - half * frames)) / 1500.0f;
    this->m_65c = -(this->m_660 * k + height) / frames;
    this->m_670 = 0.0f;
    this->m_664 = height;
    this->m_668 = -(this->m_660 * k);
    half = 0.5f * this->m_65c;
    this->m_66c = frames * (half * frames + height);
    this->m_658 = this->rotation_y;
}

s32 TBoss8Dragon::sub_802FBFA4() {
    f32 t;
    this->m_670 += 1.0f;
    t = this->m_670;
    if (t <= 35.0f) {
        this->rotation_y = this->m_658 + (s32) (t * ((0.5f * this->m_65c * t) + this->m_664));
        return 0;
    }
    if (t <= 60.0f) {
        t = t - 35.0f;
        this->rotation_y = this->m_658 + (s32) ((t * ((0.5f * this->m_660 * t) + this->m_668)) + this->m_66c);
        return 0;
    }
    return 1;
}

#pragma pop
void TBoss8Dragon::reload_boss_stats() {
    this->reload_stats_keep_hp_tp((u8 *)(TLobby::register_boss(0x12)), (u8 *)(TBoss8Dragon__data_80541DC8[TBoss8Dragon__data_804E4C28[0]]), (u8 *)(TLobby::register_object(0x12)));
}

void TBoss8Dragon::reset_tail_hp() {
    this->reset_hp((u8 *)0, (u8 *)(*(saddr *)((s8 *)&TBoss8Dragon__data_80541DC8 + 4)), (u8 *)0);
}

void TBoss8Dragon::sub_802FBEA4() {
    this->reload_stats_keep_hp_tp((u8 *)(TLobby::register_boss(0x12)), (u8 *)TBoss8Dragon__data_80541DC8[TBoss8Dragon__data_804E4C28[2]], (u8 *)(TLobby::register_object(0x12)));
}

void TBoss8Dragon::sub_802FBE3C() {
    this->reload_stats_keep_hp_tp((u8 *)(TLobby::register_boss(0x12)), (u8 *)TBoss8Dragon__data_80541DC8[TBoss8Dragon__data_804E4C28[3]], (u8 *)(TLobby::register_object(0x12)));
}

void handle_6xA8_gol_dragon_boss_actions(void *boss8_dragon) {
    void *x;
    ((TBoss8Dragon *)boss8_dragon)->bswap_packet();
    x = get_enemy_entity(*(u16 *)((s8 *)boss8_dragon + 0x2));
    if (x != NULL) {
        ((TBoss8Dragon *)x)->apply_6xA8_action((u8 *)boss8_dragon);
    }
}

void TBoss8Dragon::apply_6xA8_action(u8 *packet) {
    s16 action;
    enemy_set_target_id(this, (u16)*(s32 *)(packet + 8));
    this->sequenceCursor = *(s16 *)(packet + 6);
    this->m_690 = *(f32 *)(packet + 0xC);
    this->m_694 = *(f32 *)(packet + 0x10);
    this->dispatch_action(*(s16 *)(packet + 4), 7);
    set_mode_params__12TBoss8DragonFSc(this, packet[0x14]);
    action = *(s16 *)(packet + 4);
    if ((s16)this->mode != action) {
        this->transition_enemy_state(action);
    }
}

void TBoss8Dragon::send_6xA8_action() {
    Pkt_802FBCBC p;
    f32 t;
    build_6xA8_gol_dragon_boss_actions(&p);
    p.a = this->entity_id;
    p.b = this->mode;
    p.c = this->sequenceCursor;
    p.d = this->target_id;
    p.e = this->m_688;
    p.f = this->m_68c;
    t = 0.000030517578f * (f32)rand();
    p.g = (s8)(3.0f * t);
    ((TBoss8Dragon *)(&p))->send_swapped_packet();
}

void TBoss8Dragon::send_action_packet(int action) {
    u8 * boss8_dragon = (u8 *)this;
    Pkt_802FBBFC p;
    f32 t;
    ((TBoss8Dragon *)boss8_dragon)->dispatch_action(action, 6);
    build_6xA8_gol_dragon_boss_actions(&p);
    p.a = ((TBoss8Dragon *)boss8_dragon)->entity_id;
    p.b = action;
    p.c = ((TBoss8Dragon *)boss8_dragon)->sequenceCursor;
    p.d = ((TBoss8Dragon *)boss8_dragon)->target_id;
    p.e = *(f32 *)((s8 *)boss8_dragon + 0x688);
    p.f = ((TBoss8Dragon *)boss8_dragon)->m_68c;
    t = 0.000030517578f * (f32)rand();
    p.g = (s8)(3.0f * t);
    ((TBoss8Dragon *)(&p))->send_swapped_packet();
}

void TBoss8Dragon::sync_target_pos() {
    this->destination.x = this->m_690;
    this->destination.z = this->m_694;
}

void TBoss8Dragon::sub_802FBBC8(s32 *arg1) {
    *arg1 = (s32) this->m_690;
}

void TBoss8Dragon::restore_target_pos() {
    this->position.x = this->m_690;
    this->position.z = this->m_694;
}

void TBoss8Dragon::save_position() { this->m_688 = this->destination.x; this->m_68c = this->destination.z; }

void TBoss8Dragon::set_speed(s32 arg1) {
    this->m_688 = (f32) arg1;
    this->m_68c = 0.0f;
}

void TBoss8Dragon::copy_pos_to_field688() {
    this->m_688 = this->position.x;
    this->m_68c = this->position.z;
}

#pragma push
#pragma pool_data off
void TBoss8Dragon::pick_next_action() {
  s32 var_r7;
  const s32 *var_r8;
  s32 temp_r4;
  s32 temp_r5;
  s32 var_r9;
  if ((this->flags) & 0x40)
  {
    var_r7 = this->sequenceCursor;
    var_r8 = boss8_dragon_action_pick_table_b;
  }
  else
  {
    temp_r5 = this->sequenceCursor;
    if (temp_r5 < 0x32)
    {
      var_r7 = temp_r5;
      var_r8 = dragon_next_action_table;
    }
    else
    {
      var_r7 = temp_r5 - 0x32;
      var_r8 = boss8_dragon_action_pick_table;
    }
  }
  do
  {
    temp_r4 = *((s32 *) (((s8 *) var_r8) + (var_r7 * 4)));
    var_r9 = 0;
    var_r7 += 1;
    this->sequenceCursor = (s32) ((this->sequenceCursor) + 1);
    switch (temp_r4)
    {
      case 33:
        this->sequenceCursor = 0;
        var_r9 = 1;
        var_r7 = 0;
        break;
      case 34:
        this->sequenceCursor = 0x32;
        var_r9 = 1;
        var_r7 = 0;
        break;
    }
  }
  while (var_r9 != 0);
  this->send_action_packet((int) temp_r4);
}
#pragma pop

void TBoss8Dragon::sub_802FBA1C() {
    if (this->m_74c != 0) {
        this->pick_next_action();
        return;
    }
    if (this->check_damage_reaction() == 0) {
        this->sequenceCursor = boss8_dragon_state_transition_table[this->sequenceCursor];
        this->pick_next_action();
    }
}

s32 TBoss8Dragon::check_damage_reaction() {
    if (*(s32 *)&this->flags & 0x40) {
        return 0;
    }
    if ((s16) this->hp <= this->finalHpThreshold) {
        this->hp = this->finalHpThreshold;
        set_damage_phase_value(1);
        if ((s32) *(s32 *)&this->m_3e4 == 0) {
            send_action_packet(0xD);
            return 1;
        }
        send_action_packet(0xB);
        return 1;
    }
    return 0;
}

int TBoss8Dragon__sub_802FB984(void) { return 0; }

#pragma push
#pragma fp_contract on
f32 TBoss8Dragon::calc_step_value() {
    TBoss8Dragon *o = this;
    return 4.0f * (f32)*(s32 *)&o->m_6d0 + 4.0f;
}

#pragma pop
void TBoss8Dragon::spawn_effect() {
    saddr self = (saddr)this;
    start_pad_rumble_at((Vec *)(self + 0x38), 0xE0, self);
}

void TBoss8Dragon__sub_802FB828(u8 *ene_dd, s32 arg1) {
    DragonAttackParams eff = boss8_dragon_breath_eff_params;
    u8 *a;
    u8 *b;
    fill_value_array(((TBoss8Dragon *)ene_dd)->attack_history);
    if (arg1 == 0) {
        a = ene_dd + 0x470;
        b = ene_dd + 0x47C;
    } else {
        a = ene_dd + 0x458;
        b = ene_dd + 0x464;
    }
    ((TObjEneDD *)ene_dd)->reset_hp((u8 *)0, (u8 *)(TBoss8Dragon__data_80541DC8[0]), (u8 *)0);
    ((TBoss8Dragon *)ene_dd)->emit_effect(a, &eff, ((TBoss8Dragon *)ene_dd)->attack_history);
    ((TBoss8Dragon *)ene_dd)->emit_effect(b, &eff, ((TBoss8Dragon *)ene_dd)->attack_history);
    ((TObjEneDD *)ene_dd)->reset_hp((u8 *)0, (u8 *)(TBoss8Dragon__data_80541DC8[0]), (u8 *)0);
    spawn_particle_effect_with_flags((const Vec *)b, (saddr)(*(void **)(*(u8 **)(ene_dd + 0x760) + 0x10)), (s32)(0x40));
}

int TBoss8Dragon::check_condition_default(void* p) { return ((int (*)(void*, int))TBoss8Dragon__sub_802FB828)(p, 0); }

int TBoss8Dragon::set_state_1(void* p) { return ((int (*)(void*, int))TBoss8Dragon__sub_802FB828)(p, 1); }

void TBoss8Dragon::sub_802FB778() {
    DragonAttackParams stack;
    TBoss1Dragon__sub_80027A80(&stack, &lbl_804744B4);
    stack.field_8 = *(f32 *)((s8 *)(TBoss8Dragon__data_80541DDC[0]) + 0xC);
    sub_802FBEA4();
    this->get_state_flags(&stack);
    this->reload_boss_stats();
}

void TBoss8Dragon::sub_802FB70C() {
    this->reset_hp((u8 *)0, (u8 *)(*(saddr *)((s8 *)&TBoss8Dragon__data_80541DC8 + 0x10)), (u8 *)0);
    this->get_state_flags((void *)&TBoss8Dragon__body_effect_parameters);
    this->reset_hp((u8 *)0, (u8 *)(*(saddr *)((s8 *)&TBoss8Dragon__data_80541DC8 + 0)), (u8 *)0);
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::draw_beam_segments(f32 a, f32 b, f32 c) {
    DragonAttackParams fx = TBoss8Dragon__body_effect_parameters;
    Vec v2;
    Vec v1;
    f32 sn;
    f32 cs;
    f32 d;
    u8 *ene_dd = (u8 *)this;

    *(f32 *)((s8 *)&fx + 8) = a - 2.0f;
    fill_value_array(((TBoss8Dragon *)ene_dd)->attack_history);
    sn = sin_table_lookup(((TObjEneDD *)ene_dd)->rotation_y);
    cs = cos_table_lookup(((TObjEneDD *)ene_dd)->rotation_y);
    VecCopy(&v1, (Vec *)(ene_dd + 0x38));
    v1.x += -4.0f * cs;
    v1.y = 0.0f;
    v1.z -= -4.0f * sn;
    d = 0.5f * (b + c);
    VecCopy(&v2, &v1);
    v2.x = sn * d + v2.x;
    v2.z = cs * d + v2.z;
    spawn_particle_effect_with_flags(&v2, *(s32 *)((s8 *)(*(u8 **)((s8 *)ene_dd + 0x760)) + 0x10), 0x40);
    ((TObjEneDD *)ene_dd)->reset_hp((u8 *)0, (u8 *)(TBoss8Dragon__data_80541DC8[4]), (u8 *)0);
    c = c - a;
    d = b - a;
    a *= 2.0f;
    b = 0.5f * (0.5f * a);
    while (d > c) {
        VecCopy(&v2, &v1);
        v2.x = sn * d + v2.x;
        v2.z = cs * d + v2.z;
        ((TBoss8Dragon *)ene_dd)->emit_effect(&v2, &fx, ((TBoss8Dragon *)ene_dd)->attack_history);
        d -= a;
        push_matrix();
        post_translate_matrix(&v2);
        scale_matrix(0, b, 2.0f, b);
        draw_chunk_object((void *)lbl_805D28BC);
        pop_matrix();
    }
    ((TObjEneDD *)ene_dd)->reset_hp((u8 *)0, (u8 *)(TBoss8Dragon__data_80541DC8[0]), (u8 *)0);
}

#pragma pop
void TBoss8Dragon::update_pos_from_data() {
    draw_beam_segments(10.0f, -60.0f, -140.0f);
}

void TBoss8Dragon::sub_802FB484() {
    this->draw_beam_segments(10.0f, 90.0f, 60.0f);
}

void TBoss8Dragon::init_state(saddr dragon) {
    ((TBoss8Dragon *)dragon)->sub_802FBE3C();
    ((TBoss8Dragon *)dragon)->get_state_flags((void *)&boss8_dragon_init_state_params);
    ((TBoss8Dragon *)dragon)->reload_boss_stats();
}

void TBoss8Dragon::emit_body_effects() {
    Vec *pts[10];
    DragonAttackParams e;
    Vec v;
    s32 i;
    reset_hp((u8 *)0, (u8 *)(TBoss8Dragon__data_80541DC8[4]), (u8 *)0);
    fill_value_array(this->attack_history);
    TBoss1Dragon__sub_80027A80(&e, &TBoss8Dragon__body_effect_parameters);
    VecCopy(&v, (Vec *)(((u8 *)this) + 0x4C4));
    e.field_8 = 15.0f;
    emit_effect(&v, &e, this->attack_history);
    e.field_8 = 12.0f;
    pts[0] = (Vec *)((u8 *)this + 0x488);
    pts[1] = (Vec *)((u8 *)this + 0x4A0);
    for (i = 0; i < 2; i++) {
        emit_effect(pts[i], &e, this->attack_history);
    }
    e.field_8 = 11.0f;
    pts[0] = (Vec *)((u8 *)this + 0x4DC);
    pts[1] = (Vec *)((u8 *)this + 0x4E8);
    pts[2] = (Vec *)((u8 *)this + 0x4F4);
    pts[3] = (Vec *)((u8 *)this + 0x500);
    for (i = 0; i < 4; i++) {
        emit_effect(pts[i], &e, this->attack_history);
    }
    reset_hp((u8 *)0, (u8 *)(TBoss8Dragon__data_80541DC8[0]), (u8 *)0);
}

void TBoss8Dragon__sub_802FB300(void) {  }

void TBoss8Dragon::setup_breath_instance(Vec *pos, u32 kind, AreaAttackHistory *history) {
    DragonAttackParams s = TBoss8Dragon__breath_params;
    s.field_4 = (*(G_802FB290 *)&TBoss8Dragon__data_80541DDC).value->f[0];
    s.field_0 = kind;
    setup_instance((saddr)pos, &s, history);
}

void TBoss8Dragon__sub_802FB220(void *o, int x, u32 a) {
    DragonAttackParams s = lbl_80474ACC;
    s.field_4 = (*(G_802FB220 *)&TBoss8Dragon__data_80541DDC).value->f[1];
    s.field_0 = a;
    ((TBoss8Dragon *)o)->setup_instance(x, &s, 0);
}

void TBoss8Dragon__sub_802FB1B0(TBoss8Dragon *dragon, int x, f32 c) {
    DragonAttackParams s = lbl_80474AE0;
    s.field_8 = c;
    s.field_4 = (*(G_802FB220 *)&TBoss8Dragon__data_80541DDC).value->f[2];
    dragon->setup_instance(x, &s, dragon->attack_history);
}

void TBoss8Dragon::emit_effect(void *pos, void *params, AreaAttackHistory *history) {
    TObjEneDD::emit_enemy_effect(this, pos, (u8 *)params, history);
}

void TBoss8Dragon::get_state_flags(void *params) { emit_effect_at_position(params); }

int TBoss8Dragon::setup_instance(int _w1, void * _w2, AreaAttackHistory *history) { return setup_instance__9TObjEneDDFllPUcl(this); }

void TBoss8Dragon::spawn_ground_effect() {
    Vec pos;
    f32 temp_f1;
    CsnHit *hit;
    VecCopy(&pos, &this->position);
    hit = csnVecterUnder(&pos, 0x16EF);
    if (hit != NULL) {
        temp_f1 = hit->contact->point.y;
        if (!(temp_f1 > 30.0f)) {
            pos.y = temp_f1;
            spawn_particle_effect_with_flags(&pos, this->particle_ids[1], 0x40);
        }
    }
}

void TBoss8Dragon::sub_802FB09C() {
    if (this->is_passing_frame(14.0f) != 0) {
        this->spawn_ground_effect();
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
    u8 *p;
    if (TBoss8Dragon__data_805D69B8 != 0) {
        this->m_74c = 1;
    } else {
        this->m_74c = 0;
        this->m_750 = 0xFFFFU;
        return;
    }
    this->m_754 = 0x96;
    this->controller_input = &controller_input_state.controllers[0];
    if (TObjEneDD::is_main_phase_15() != 0) {
        if (TBoss8Dragon__data_805D69BC == 0xFFFFU) {
            var_r31 = TBoss8Dragon::find_player_on_floor(this);
        } else {
            var_r31 = TBoss8Dragon__data_805D69BC;
        }
    } else {
        var_r31 = (u16)local_client_id;
    }
    TObjPlayer *player = ((TObjPlayer * (*)(s32))get_player_by_client_id)(var_r31);
    if (player != NULL) {
        player->start_freeze();
    }
    this->m_750 = var_r31;
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::freeze_player_at_self() {
    u8 *player;
    player = ((u8 * (*)(s32))get_player_by_client_id)(this->m_750);
    if (player != NULL) {
        if (((TObjPlayer *)player)->get_floor() == get_current_floor()) {
            ((TObjPlayer *)player)->start_freeze();
            ((ProtectionTimer *)(player + 0x644))->set_frames(0x14);
            ((TObjPlayer *)player)->actorFlags = (s32) (((TObjPlayer *)player)->actorFlags & 0xFFEFFFDF);
            VecCopy((Vec *)(player + 0x38), &this->position);
            *(f32 *)((s8 *)player + 0x3C) = (f32) (*(f32 *)((s8 *)player + 0x3C) - 200.0f);
            ((TObjPlayer *)player)->rotation_y = (s32) this->rotation_y;
            return;
        }
    }
    ((s32 (*)(void))TBoss8Dragon__sub_802FD9D0)();
}

#pragma pop
void TBoss8Dragon::release_grabbed_player() {
    TBoss8Dragon * boss8_dragon = this;
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
        if (((s32) temp_r4 == (s32) local_client_id) && ((s16) boss8_dragon->mode == 0x15)) {
            send_6x2F_change_player_hp((0xFFFFU), (temp_r4), 0);
        }
    }
    boss8_dragon->m_74c = 0;
    if ((s16) boss8_dragon->mode != 0x15) {
        var_r31 = 0;
        if (((TBoss8Dragon *)boss8_dragon)->is_health_low() != 0) {
            boss8_dragon->sequenceCursor = 0;
            switch (boss8_dragon->mode) {
            case 24:
            case 25:
                var_r31 = 1;
                boss8_dragon->sequenceCursor = 0;
                break;
            case 3:
                boss8_dragon->sequenceCursor = 2;
                break;
            case 4:
                boss8_dragon->sequenceCursor = 3;
                break;
            case 5:
                boss8_dragon->sequenceCursor = 4;
                break;
            case 26:
            case 27:
                var_r31 = 1;
                boss8_dragon->sequenceCursor = 6;
                break;
            case 7:
                boss8_dragon->sequenceCursor = 6;
                break;
            case 8:
                boss8_dragon->sequenceCursor = 7;
                break;
            case 9:
                boss8_dragon->sequenceCursor = 0;
                break;
            }
        } else {
            boss8_dragon->sequenceCursor = 0;
            switch (boss8_dragon->mode) {
            case 24:
            case 25:
                var_r31 = 1;
                boss8_dragon->sequenceCursor = 0;
                break;
            case 3:
            case 4:
                boss8_dragon->sequenceCursor = 0;
                break;
            case 5:
                boss8_dragon->sequenceCursor = 1;
                break;
            case 26:
            case 27:
                var_r31 = 1;
                boss8_dragon->sequenceCursor = 0xA;
                break;
            case 7:
                boss8_dragon->sequenceCursor = 0xA;
                break;
            case 8:
            case 19:
                boss8_dragon->sequenceCursor = 0xB;
                break;
            case 15:
                boss8_dragon->sequenceCursor = 2;
                break;
            case 37:
            case 38:
                var_r31 = 1;
                boss8_dragon->sequenceCursor = 9;
                break;
            case 9:
                boss8_dragon->sequenceCursor = 0;
                break;
            }
            boss8_dragon->sequenceCursor = (boss8_dragon->sequenceCursor + 0x32);
        }
        if (var_r31 != 0) {
            boss8_dragon->pick_next_action();
        }
    }
}

#pragma push
#pragma fp_contract on
f32 TBoss8Dragon::clamp_step_in_radius(f32 a, f32 b, f32 s) {
    Obj_802FAC08 *o = (Obj_802FAC08 *)this;
    Vec v;
    v.x = a * s + o->x;
    v.y = 0.0f;
    v.z = b * s + o->z;
    if (vec3_dot(&v, &v) > 28900.0f) {
        s = 0.0f;
    }
    return s;
}

#pragma pop
s32 TBoss8Dragon::sub_802FABB4() {
    u8 var_r31;

    var_r31 = 0;
    if (((s32) this->m_754 >= 0x96) && (this->mask_flags(this->controller_input->unknown_08, 0x400) != 0)) {
        var_r31 = 1;
    }
    return (u8) var_r31;
}

s32 TBoss8Dragon::check_attack_ready() {
    u8 var_r31;

    var_r31 = 0;
    if ((this->mask_flags(this->controller_input->unknown_08, 0x400) != 0) && (sub_802FC88C() != 0)) {
        var_r31 = 1;
    }
    return var_r31;
}

void TBoss8Dragon::calc_velocity_from_angle() {
    this->position.x = (f32) (330.0f * sin_table_lookup(this->m_758));
    this->position.z = (f32) (330.0f * cos_table_lookup(this->m_758));
}

s32 TBoss8Dragon::mask_flags(s32 input_flags, s32 mask) {
    if ((get_player_by_client_id(local_client_id) == 0U) || (check_flag_100__10TObjPlayerFPv() != 0)) {
        input_flags &= 0xFFFCF9F9;
    }
    return input_flags & mask;
}

void TBoss8Dragon::dispatch_action(u32 action, s32 event) {
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
void TBoss8Dragon::sub_802FA478(s32 event) {
    switch (event) {
    case 4:
        this->select_freeze_target();
        return;
    case 2:
    case 11:
        send_action_packet(0x18);
        return;
    case 9:
        if (this->m_74c != 0) {
            send_action_packet(0x18);
            return;
        }
        this->pick_next_action();
    default:
        return;
    }
}

void TBoss8Dragon::sub_802FA374(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 0;
        this->stateStep = 0;
        if (this->flags & 0x40) {
            this->try_spawn_trap();
        } else {
            this->play_effect_sound(0x4003AD00);
        }
        break;
    case 2:
    case 11:
        if (this->mask_flags(this->controller_input->unknown_08, 4) != 0) {
            send_action_packet(3);
        } else if (this->mask_flags(this->controller_input->unknown_08, 0x400) != 0) {
            send_action_packet(5);
        } else if (this->controller_input->stick_magnitude > 0.1f) {
            send_action_packet(0x19);
        }
        break;
    case 0:
        this->stateStep++;
        this->advance_animation();
        break;
    }
}

void TBoss8Dragon::sub_802FA16C(s32 event) {
    f32 temp_f1;
    s32 temp_r4_2;
    s32 var_r30;
    switch (event) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags & ~0x36);
        this->stateStep = 0;
        temp_f1 = *(f32 *)((s8 *)TBoss8Dragon__data_80541DDC[0] + 0x10);
        this->m_864 = (f32) (5.0f + TObjBoss2Tunnel::calc_scaled_value((s32) (320.0f * temp_f1), temp_f1));
        return;
    case 2:
    case 11:
        send_action_packet(0x18);
        return;
    case 9:
        temp_r4_2 = this->stateStep;
        var_r30 = 0;
        if ((temp_r4_2 >= 0x96) && (this->current_target != NULL)) {
            if (this->destination_distance < this->m_864) {
                var_r30 = 1;
            } else if (this->is_near_target() != 0) {
                var_r30 = 1;
            } else if ((s32) this->stateStep >= 0x258) {
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
        this->update_linked_position();
        this->stateStep = (this->stateStep + 1);
        if ((s32) (this->stateStep % 20) == 0x13) {
            if (enemy_validate_retained_target(this) != 0) {
                this->enemy_copy_target_destination();
            } else {
                this->set_target_destination(&TBoss8Dragon__data_804744A8);
            }
            this->save_position();
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        sync_target_pos();
        return;
    case 6:
        this->acquire_counter = (s32) this->acquire_period;
        if (this->update_linked_position() != 0) {
            this->enemy_copy_target_destination();
        } else {
            this->set_target_destination(&TBoss8Dragon__data_804744A8);
        }
        this->save_position();
        return;
    case 0:
        this->update_movement();
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::state_breath_attack(s32 event) {
    Rot_802F9D08 rot;
    switch (event) {
    case 4:
        this->requested_action = 4;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags &= ~0x36;
        this->stateStep = 0;
        this->impactAge = 2;
        this->m_854 = 0;
        this->m_894 = 0;
        this->m_898 = 0;
        this->m_89c = 0;
        return;
    case 2:
    case 11:
        if (this->stateStep == 3) {
            send_action_packet(0x18);
        }
        return;
    case 9:
        if (this->stateStep == 3) {
            this->pick_next_action();
        }
        return;
    case 7:
        sync_target_pos();
        return;
    case 6:
        if (enemy_validate_retained_target(this) != 0) {
            this->enemy_copy_target_destination();
        } else {
            this->destination.x = 115.0f * sin_table_lookup(this->rotation_y) + this->m_410.x;
            this->destination.y = this->position.y;
            this->destination.z = 115.0f * cos_table_lookup(this->rotation_y) + this->m_410.z;
        }
        this->save_position();
        return;
    case 0:
        this->advance_animation();
        this->try_spawn_trap();
        switch (this->stateStep) {
        case 0:
            this->update_velocity();
            sub_802FC9D8();
            this->rotation_y = approach_angle_limited(this->rotation_y, (RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z)), 0xA0);
            this->rotation_y = (s16)this->rotation_y;
            if (this->get_flag_b4() != 0) {
                this->requested_action = 5;
                this->stateStep = 1;
            }
            break;
        case 1:
            this->m_854++;
            if (this->m_854 >= 0x78) {
                this->requested_action = 6;
                if (this->m_894 != 0) {
                    this->m_894->queue_destruction();
                    this->m_894 = 0;
                }
                if (this->m_898 != 0) {
                    this->m_898->queue_destruction();
                    this->m_898 = 0;
                }
                if (this->m_89c != 0) {
                    this->m_89c->queue_destruction();
                    this->m_89c = 0;
                }
                this->stateStep = 2;
                this->impactAge = 0;
            } else if (!(this->motion_flags & 4)) {
                this->spawn_trap(0x4003AD0D);
                direction_to_rotation_xz((u8 *)&m_41c, &rot.x, &rot.z);
                this->impactAge++;
                if (this->impactAge >= 2) {
                    new TBoss8DragonEffBreath(&sub_tasks, &m_410, &m_41c, m_75c, get_entity_id(((u8 *)this)));
                    this->impactAge = 0;
                }
                if (this->m_894 == 0) {
                    this->m_894 = (TParticleCtrl *)spawn_particle_effect_with_rotation(&m_410, &rot, this->particle_ids[5], 0x40);
                    if (this->m_894 != 0) {
                        this->m_894->enable();
                    }
                } else {
                    this->m_894->set_position((u8 *)&m_428);
                    this->m_894->set_direction(&rot);
                }
                if (this->m_898 == 0) {
                    if (this->particle_ids[6] != -1) {
                        this->m_898 = (TParticleCtrl *)spawn_particle_effect_with_rotation(&m_410, &rot, this->particle_ids[6], 0x40);
                    }
                    if (this->m_898 != 0) {
                        this->m_898->enable();
                    }
                } else {
                    this->m_898->set_position((u8 *)&m_428);
                    this->m_898->set_direction(&rot);
                }
                if (this->m_89c == 0) {
                    this->m_89c = (TParticleCtrl *)spawn_particle_effect_with_rotation(&m_410, &rot, this->particle_ids[7], 0x40);
                    if (this->m_89c != 0) {
                        this->m_89c->enable();
                    }
                } else {
                    this->m_89c->set_position((u8 *)&m_428);
                    this->m_89c->set_direction(&rot);
                }
            }
            break;
        case 2:
            this->impactAge++;
            if (this->impactAge < 0x1E) {
                this->spawn_trap(0x4003AD0D);
            }
            if (this->get_flag_b4() != 0) {
                this->stateStep = 3;
            }
            break;
        }
        break;
    case 5:
        if (this->m_894 != 0) {
            this->m_894->queue_destruction();
            this->m_894 = 0;
        }
        if (this->m_898 != 0) {
            this->m_898->queue_destruction();
            this->m_898 = 0;
        }
        if (this->m_89c != 0) {
            this->m_89c->queue_destruction();
            this->m_89c = 0;
        }
        break;
    }
}

#pragma pop
#undef F
void TBoss8Dragon::handle_tail_attack_state(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 7;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags &= ~0x34;
        this->flags |= 2;
        this->stateStep = 0;
        this->tail->enable();
        break;
    case 2:
    case 11:
        if (this->get_flag_b4() != 0) {
            send_action_packet(0x18);
        }
        break;
    case 9:
        if (this->get_flag_b4() != 0) {
            this->pick_next_action();
        }
        break;
    case 0:
        this->advance_animation();
        (this->stateStep)++;
        if (this->is_passing_frame(0.0f) != 0 || this->is_passing_frame(12.0f) != 0) {
            this->play_effect_sound(0x4003AD09);
        }
        if (this->stateStep > 1) {
            if (this->is_passing_frame(10.0f) != 0) {
                this->tail->disable();
            } else if (this->is_passing_frame(23.0f) != 0) {
                this->tail->enable();
            }
            this->tail->run_task();
        }
        break;
    }
}

void TBoss8Dragon::sub_802F9A4C(s32 event) {
    s32 i;
    switch (event) {
    case 4:
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].set_speed(0.08f);
        }
        this->flags |= 0x100;
        sub_802F9850(event);
        break;
    case 2:
    case 11:
        this->m_754 = 0;
        if (this->sub_802F46F4() == 0) {
            this->pick_next_action();
        }
        break;
    case 9:
        if (this->sub_802F46F4() == 0) {
            this->pick_next_action();
        }
        break;
    case 0:
        switch (this->stateStep) {
        case 0:
            break;
        case 1:
            for (i = 0; i < 4; i++) {
                this->renderFadeStates[i].decay_value_toward_floor();
            }
            break;
        }
        sub_802F9850(event);
        break;
    case 5:
        this->flags &= ~0x100;
        sub_802F9850(event);
        break;
    default:
        sub_802F9850(event);
        break;
    }
}

void TBoss8Dragon::sub_802F9850(s32 event) {
    struct { f32 x, y, z; } sp8;

    switch (event) {
    case 4:
        this->requested_action = 0xF;
        this->advance_animation();
        this->clear_intangible();
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
            send_action_packet(0x1A);
        }
        return;
    case 9:
        if ((s32) *(s32 *)((s8 *)((u8 *)this) + 0x850) >= 0x28) {
            this->pick_next_action();
            return;
        }
        break;
    case 7:
        restore_target_pos();
        return;
    case 6:
        copy_pos_to_field688();
        return;
    case 0:
        this->advance_animation();
        if (this->is_passing_frame(14.0f) != 0) {
            this->play_effect_sound(0x4003A804);
        }
        if (this->is_passing_frame(42.0f) != 0) {
            this->play_effect_sound(0x4003A803);
        }
        if (this->is_passing_frame(46.0f) != 0) {
            this->spawn_ground_effect();
        }
        switch (*(s32 *)((s8 *)((u8 *)this) + 0x84C)) {
        case 0:
            if (this->is_passing_frame(35.0f) != 0) {
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

#pragma push
#pragma fp_contract on
void TBoss8Dragon::state_turn_and_charge(s32 event) {
    s32 diff;
    switch (event) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags &= ~0x36;
        this->update_velocity();
        init_acceleration_curve(&this->curve0, (f32)(0.1f), (f32)(-0.1f), (f32)this->destination_distance, (f32)(2.0f + *(f32 *)(TBoss8Dragon__data_80541DDC[0] + 0x14)));
        diff = angle_diff_s16(this->rotation_y, (s32)(RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z)));
        if (diff >= 0) {
            this->m_654 = 1;
        } else {
            diff = -diff;
            this->m_654 = -1;
        }
        init_acceleration_curve(&this->curve1, (f32)(16.0f), (f32)(-16.0f), (f32)((f32)diff), (f32)(s32)(256.0f * (2.0f + *(f32 *)(TBoss8Dragon__data_80541DDC[0] + 0x14))));
        this->m_85c = this->rotation_y;
        this->stateStep = 0;
        this->m_864 = 0.0f;
        break;
    case 2:
        send_action_packet(26);
        break;
    case 11:
        if (this->stateStep == 2) {
            send_action_packet(15);
        }
        break;
    case 9:
        if (this->stateStep == 2) {
            this->pick_next_action();
        }
        break;
    case 7:
        this->sync_target_pos();
        break;
    case 6:
        ((void (*)(u8 *, void *))TBoss8Dragon__sub_802FC500)(((u8 *)this), &this->destination);
        this->save_position();
        break;
    case 0:
        this->advance_animation();
        this->spawn_effect_if_in_band();
        sub_802FB09C();
        switch (this->stateStep) {
        case 0:
            this->m_864 += 1.0f;
            this->rotation_y = (s32)((f32)this->m_654 * sample_acceleration_curve(&this->curve1, this->m_864) + (f32)this->m_85c);
            if (this->curve1.check_param_threshold(this->m_864) != 0) {
                this->m_864 = 0.0f;
                this->stateStep = 1;
            }
            break;
        case 1: {
            f32 prev = sample_acceleration_curve(&this->curve0, this->m_864);
            f32 dlt;
            Vec v;
            this->m_864 += 1.0f;
            dlt = sample_acceleration_curve(&this->curve0, this->m_864) - prev;
            v.x = this->destination_direction.x * dlt;
            v.y = 0.0f;
            v.z = this->destination_direction.z * dlt;
            apply_ground_movement(&v);
            if (this->curve0.check_param_threshold(this->m_864) != 0) {
                this->stateStep = 2;
            }
            break;
        }
        }
        break;
    case 5:
        VecCopy(&this->m_5e0, &this->destination_direction);
        break;
    }
}

#define F(t, o) (*(t *)((u8 *)this + (o)))
void TBoss8Dragon::sub_802F8F88(s32 event) {
    f32 *d = &m_878;

    switch (event) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags &= ~0x36;
        this->stateStep = 0;
        this->impactAge = 0;
        this->m_854 = 0;
        this->m_894 = 0;
        break;
    case 2:
    case 11:
        if (this->stateStep == 3) {
            send_action_packet(0x1A);
        }
        break;
    case 9:
        if (this->stateStep == 4) {
            this->pick_next_action();
        }
        break;
    case 0:
        this->advance_animation();
        switch (this->stateStep) {
        case 0:
            if (this->sub_802FC674(d) != 0) {
                this->m_85c = (s32)(RADIANS_TO_ANGLE * atan2_float(d[0] - this->position.x, d[2] - this->position.z));
            } else {
                this->m_85c = get_random_scaled();
                d[0] = 125.0f * sin_table_lookup(this->m_85c);
                d[1] = 0.0f;
                d[2] = 125.0f * cos_table_lookup(this->m_85c);
            }
            this->m_85c = (s16)this->m_85c;
            this->stateStep = 1;
            if (this->m_74c != 0) {
                this->m_85c = (s16)this->rotation_y;
                VecCopy((Vec *)d, &position);
                d[0] += 125.0f * sin_table_lookup(this->m_85c);
                d[1] = 0.0f;
                d[2] += 125.0f * cos_table_lookup(this->m_85c);
                this->stateStep = 2;
                F(s32, 0x650) = 0;
                this->rotation_y = this->m_85c;
                this->requested_action = 0x12;
                this->flags |= 0x30;
            }
            this->check_hit_result(this->rotation_y, this->m_85c);
            sub_802FC060(this->m_85c);
        case 1:
            this->spawn_effect_if_in_band();
            sub_802FB09C();
            if (sub_802FBFA4() != 0) {
                F(s32, 0x650) = 0;
                this->rotation_y = this->m_85c;
                this->stateStep = 2;
                this->requested_action = 0x12;
                this->flags |= 0x30;
            }
            break;
        case 2:
            if (this->is_passing_frame(2.0f) != 0) {
                this->play_effect_sound(0x4003A804);
            }
            if (this->is_passing_frame(45.0f) != 0) {
                this->play_effect_sound(0x4003AD0A);
            }
            if (this->is_passing_frame(14.0f) != 0 || this->is_passing_frame(53.0f) != 0) {
                this->spawn_ground_effect();
            }
            if (this->m_894 == 0) {
                if (this->frame >= 20.0f) {
                    this->m_894 = spawn_continuous_particle_effect_with_flags((void *)&m_410, this->particle_ids[8], (s32)(0x40));
                }
            } else if (this->frame <= 40.0f) {
                this->m_894->set_position((u8 *)&m_410);
            } else {
                this->m_894->queue_destruction();
                this->m_894 = 0;
            }
            if (this->is_passing_frame(47.0f) != 0) {
                Vec v;
                Vec dir;
                Vec rot;
                f32 len;
                VecCopy(&dir, (Vec *)d);
                subtract_vector(&dir, (u8 *)&position);
                len = normalize_vector_xz((Vec *)&dir);
                dir.y = 0.0f;
                VecCopy(&v, (Vec *)d);
                v.y = TBoss8Dragon__data_804744A8.y;
                new TBoss8DragonEffBullet(&sub_tasks, &m_410, &v, m_75c, get_entity_id(((u8 *)this)));
                rotate_vec_xz(&dir, &rot, 0x1000);
                VecCopy(&v, &position);
                v.x += rot.x * len;
                v.y = TBoss8Dragon__data_804744A8.y;
                v.z += rot.z * len;
                new TBoss8DragonEffBullet(&sub_tasks, &m_410, &v, m_75c, get_entity_id(((u8 *)this)));
                rotate_vec_xz(&dir, &rot, -0x1000);
                VecCopy(&v, &position);
                v.x += rot.x * len;
                v.y = TBoss8Dragon__data_804744A8.y;
                v.z += rot.z * len;
                new TBoss8DragonEffBullet(&sub_tasks, &m_410, &v, m_75c, get_entity_id(((u8 *)this)));
                spawn_particle_effect_with_flags((const Vec *)&m_410, this->particle_ids[9], 0x40);
                this->stateStep = 3;
                this->m_854 = 0;
                this->flags &= ~0x30;
            }
            break;
        case 3:
            this->m_854++;
            if (this->m_854 > 10) {
                this->impactAge++;
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
        if (this->m_894 != 0) {
            this->m_894->queue_destruction();
            this->m_894 = 0;
        }
        break;
    }
}

#undef F
#define F(t, o) (*(t *)(arg0 + (o)))
void TBoss8Dragon::sub_802F89F8(s32 event) {
    s32 found;
    Vec pos;
    TObjPlayer *player;
    f32 step;

    switch (event) {
    case 4:
        this->requested_action = 0x19;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags |= 0x30;
        this->flags &= ~0x6;
        this->stateStep = 0;
        this->impactAge = 0;
        this->m_854 = 0;
        this->m_85c = 0;
        this->m_864 = 13.0f;
        break;
    case 2:
    case 11:
        send_action_packet(0x1A);
        break;
    case 9:
        if (this->stateStep == 6) {
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
        copy_pos_to_field688();
        break;
    case 0:
        switch (this->stateStep) {
        case 0:
            this->advance_animation();
            if (this->is_passing_frame(39.0f) != 0) {
                this->stateStep = 1;
                this->play_effect_sound(0x4003B210);
            }
            break;
        case 1:
            this->advance_animation();
            if (this->frame > 22.0f) {
                this->rotation_x = (s32)(-16384.0f * ((this->frame - 22.0f) / (this->frame_count - 22.0f)));
            }
            if (this->get_flag_b4() != 0) {
                this->requested_action = 0x18;
                this->stateStep = 2;
            }
            break;
        case 2:
            this->advance_animation();
            this->rotation_x = 0;
            if (this->frame > 22.0f) {
                this->m_85c = 0x1000;
                this->stateStep = 3;
                this->m_64c = 1;
            }
            break;
        case 3:
            this->m_85c += 0x40;
            if (this->m_85c > 0x2000) {
                this->m_85c = 0x2000;
            }
            this->impactAge++;
            if (this->impactAge >= 4) {
                this->impactAge = 0;
                this->m_854++;
                if (this->m_854 >= 40) {
                    this->stateStep = 4;
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
                new TBoss8DragonEffBullet(&sub_tasks, &m_410, &pos, this->m_75c, get_entity_id((u8 *)this));
            }
            this->rotation_x -= this->m_85c;
            break;
        case 4:
            this->m_85c -= 0x50;
            if (this->m_85c < 0x1300) {
                this->m_85c = 0x1300;
                this->rotation_x -= this->m_85c;
                if ((this->rotation_x & 0xFFFF) <= 0x1300 || (this->rotation_x & 0xFFFF) >= 0xED00) {
                    this->rotation_x = 0;
                    this->m_860 = (s32)(RADIANS_TO_ANGLE * atan2_float(-this->position.x, -this->position.z));
                    this->stateStep = 5;
                }
            } else {
                this->rotation_x -= this->m_85c;
            }
            break;
        case 5:
            this->advance_animation();
            step = (f32)angle_diff_s16(this->rotation_y, this->m_860);
            step *= 0.3f;
            if ((step < 512.0f && step >= -512.0f) || this->get_flag_b4() != 0) {
                this->rotation_y = this->m_860;
                this->stateStep = 6;
            } else {
                this->rotation_y += (s32)step;
            }
            break;
        case 6:
            this->advance_animation();
            break;
        }
        if (this->stateStep == 1 || this->stateStep == 2) {
            this->m_864 += lbl_805D69C0;
            if (this->m_864 < 0.0f) {
                this->m_864 = 0.0f;
            }
            this->position.y += this->m_864;
            if (this->position.y <= 180.0f) {
                this->position.y = 180.0f;
            }
        }
        if (this->stateStep == 3 || this->stateStep == 4 || this->stateStep == 5) {
            this->position.y -= 1.0f;
            if (this->position.y < 180.0f) {
                this->position.y = 180.0f;
            }
        }
        break;
    case 5:
        this->rotation_x = 0;
        this->sub_8002AE64();
        this->m_64c = 0;
        break;
    }
}

void TBoss8Dragon::sub_802F87EC(s32 event) {
    Vec v;
    s32 ang;
    f32 c;
    s32 i;
    u8 *hit;
    switch (event) {
    case 4:
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].set_speed(0.008f);
        }
        this->flags = (s32) (this->flags | 0x100);
        sub_802F8578(event);
        this->play_effect_sound(0x4003A814);
        return;
    case 7:
        sub_802F48DC(&this->position);
        return;
    case 6:
        this->acquire_counter = (s32) this->acquire_period;
        if (this->update_linked_position() != 0) {
            this->enemy_copy_target_destination();
        } else {
            this->set_target_destination(&TBoss8Dragon__data_804744A8);
        }
        c = sin_table_lookup((s32)(ang = (s32) (65536.0f * (0.000030517578f * (f32) rand()))));
        v.x = *(f32 *)((s8 *)TBoss8Dragon__data_80541DDC[2] + 0xC) * c + this->destination.x;
        v.y = 30.0f;
        v.z = *(f32 *)((s8 *)TBoss8Dragon__data_80541DDC[2] + 0xC) * cos_table_lookup(ang) + this->destination.z;
        hit = (u8 *)csnVecterUnder(&v, 0x16EF);
        if ((hit != NULL) && (*(f32 *)((s8 *)(*(u8 **)((s8 *)hit + 4)) + 4) <= 30.0f)) {
            this->destination.x = v.x;
            this->destination.z = v.z;
        }
        this->save_position();
        return;
    case 0:
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].advance_toward_max();
        }
        sub_802F8578(event);
        return;
    case 5:
        this->flags = (s32) (this->flags & 0xFFFFFEFF);
        sub_802F8578(event);
        return;
    case 11:
    default:
        sub_802F8578(event);
        return;
    }
}

#pragma pop
void TBoss8Dragon::sub_802F8578(s32 event) {
    Pair_802F8578 out;

    switch (event) {
    case 4:
        this->requested_action = 0x11;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags |= 0x36;
        this->stateStep = 0;
        this->m_864 = 0.0f;
        this->impactAge = 0;
        break;
    case 2:
    case 11:
        this->m_754 = 0;
        if (this->get_flag_b4() != 0) {
            send_action_packet(0x18);
        }
        break;
    case 9:
        if (this->get_flag_b4() != 0) {
            switch (this->mode) {
            default:
            case 8:
                this->pick_next_action();
                break;
            case 10:
                send_action_packet(9);
                break;
            case 11:
                send_action_packet(0xD);
                break;
            case 12:
                send_action_packet(0x15);
                break;
            }
        }
        break;
    case 7:
        restore_target_pos();
        break;
    case 6:
        copy_pos_to_field688();
        break;
    case 0:
        this->advance_animation();
        switch (this->stateStep) {
        case 0:
            eval_bezier_curve__12TBoss8DragonFPviiPvf(boss8_dragon_bezier_points_3, 3, 0, &out,
                this->get_motion_frame() / 50.0f);
            this->position.y = out.b;
            if (this->is_passing_frame(2.0f) != 0) {
                this->play_effect_sound(0x4003A804);
            }
            if (this->is_passing_frame(11.0f) != 0) {
                this->spawn_ground_effect();
            }
            if (this->is_passing_frame(50.0f) != 0) {
                fill_value_array(this->attack_history);
                create_boss8_piller_ctrl((saddr)&position, (s32)(((s32 (*)(u8 *))get_entity_id)((u8 *)this)), 100.0f);
                spawn_particle_effect_with_flags(&position, this->particle_ids[2], 0x40);
                if (this->particle_ids[3] != -1) {
                    spawn_particle_effect_with_flags(&position, this->particle_ids[3], 0x40);
                }
                this->play_effect_sound(0x4003AD0E);
                TCameraCtrl::set_shake_preset(1);
                sub_802FB778();
                this->reset_timer();
                this->set_active_flag();
                this->stateStep = 1;
            }
            break;
        case 1:
            break;
        }
        break;
    case 5:
        this->set_active_flag();
        break;
    }
}

void TBoss8Dragon::sub_802F8270(s32 event) {
    f32 var_f31;
    f32 temp_f30;
    f32 temp_f29;
    f32 temp_f1;
    s32 temp_r5;
    switch (event) {
    case 4:
        this->requested_action = 8;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags | 0x16);
        temp_r5 = this->flags & 0xFFFFFFDF;
        this->flags = temp_r5;
        this->stateStep = 0;
        this->impactAge = 0;
        this->play_effect_sound(0x4003AD06);
        return;
    case 11:
        if (((s32) this->stateStep >= 0x96) && (this->mask_flags(this->controller_input->unknown_08, 2) != 0)) {
            this->stateStep = 0x1C2;
        }
        if (((s32) this->impactAge == 2) && (this->get_flag_b4() != 0)) {
            send_action_packet(0x18);
        }
        return;
    case 2:
        if (((s32) this->impactAge == 2) && (this->get_flag_b4() != 0)) {
            send_action_packet(0x18);
            return;
        }
        break;
    case 9:
        if (((s32) this->impactAge == 2) && (this->get_flag_b4() != 0)) {
            sub_802FBA1C();
            return;
        }
        break;
    case 7:
        restore_target_pos();
        return;
    case 6:
        copy_pos_to_field688();
        return;
    case 0:
        this->advance_animation();
        switch (this->impactAge) {
        case 0:
            if (this->is_passing_frame(7.0f) != 0) {
                sub_802FB70C();
            } else if (this->is_passing_frame(14.0f) != 0) {
                update_pos_from_data();
            } else if (this->is_passing_frame(18.0f) != 0) {
                sub_802FB484();
            }
            if ((s16) this->requested_action != 8) {
                fn_802F2E7C((int) (*(s32 *)((s8 *)this + 0x684)), ((u8 *)this) + 0x38, (int) (this->rotation_y));
                this->impactAge = 1;
                return;
            }
            break;
        case 1:
            this->spawn_trap(0x4003AD12);
            this->stateStep = (s32) (this->stateStep + 1);
            if ((s32) this->stateStep >= 0x1C2) {
                this->requested_action = 0xA;
                this->impactAge = 2;
                ((TBoss8Dragon *)(*(saddr *)((s8 *)this + 0x684)))->update_colli_parts();
                return;
            }
            break;
        case 2:
            var_f31 = 0.9f;
            temp_f30 = sin_table_lookup((int) (this->rotation_y));
            temp_f29 = cos_table_lookup((int) (this->rotation_y));
            if ((s32) this->m_74c != 0) {
                var_f31 = this->clamp_step_in_radius(temp_f30, temp_f29, 0.9f);
            }
            temp_f1 = this->frame;
            if ((temp_f1 >= 13.0f) && (temp_f1 <= 20.0f)) {
                this->move_to_shot_position(temp_f30, temp_f29, var_f31);
                return;
            }
            break;
        }
        break;
    case 5:
        sub_802FC850();
        ((TBoss8Dragon *)(*(saddr *)((s8 *)this + 0x684)))->update_colli_parts();
        break;
    }
}

void TBoss8Dragon::sub_802F8150(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 2;
        this->set_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF9);
        this->set_invulnerable();
        break;
    case 2:
    case 11:
        if (this->get_flag_b4() != 0) {
            send_action_packet(0x18);
        }
        break;
    case 9:
        if (this->get_flag_b4() != 0) {
            this->pick_next_action();
        }
        break;
    case 7:
        restore_target_pos();
        break;
    case 6:
        copy_pos_to_field688();
        break;
    case 0:
        this->advance_animation();
        if (this->is_passing_frame(20.0f) != 0) {
            play_cue_stream_file((saddr)"draroar.adx");
        }
        break;
    case 5:
        this->clear_invulnerable();
        break;
    }
}

void TBoss8Dragon::state_roar(s32 event) {
    s32 temp_r4;
    switch (event) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF9);
        play_cue_stream_file((saddr)"draroar.adx");
        this->set_invulnerable();
        this->stateStep = 0;
        break;
    case 9:
        if ((s32) this->stateStep >= 0x3C) {
            this->pick_next_action();
        }
        break;
    case 7:
        restore_target_pos();
        break;
    case 6:
        copy_pos_to_field688();
        break;
    case 0:
        this->advance_animation();
        temp_r4 = this->stateStep;
        this->stateStep = (temp_r4 + 1);
        this->spawn_effect_if_in_band();
        sub_802FB09C();
        break;
    case 5:
        this->clear_invulnerable();
        break;
    case 11:
        break;
    }
}

void TBoss8Dragon::sub_802F7B70(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags &= ~0x36;
        this->stateStep = 0;
        this->impactAge = 0;
        this->m_890 = 0;
        this->m_860 = 0;
        this->m_85c = (s32)(RADIANS_TO_ANGLE * atan2_float(this->destination_direction.x, this->destination_direction.z));
        this->destination_distance += 5.0f;
        sub_802FC060(this->m_85c);
        if (this->destination_distance < 50.0f) {
            this->m_864 = this->m_868 = this->destination_distance / 60.0f;
            this->m_86c = 0.0f;
        } else {
            f32 t;
            this->m_868 = 1.6666666f;
            t = 2.0f * (50.0f - (this->destination_distance - 50.0f)) / 30.0f;
            this->m_86c = t / 30.0f;
            this->m_864 = 1.6666666f - t;
        }
        break;
    case 2:
        if (this->stateStep == 6) {
            send_action_packet(0x1C);
        }
        break;
    case 11:
        if (this->stateStep == 6) {
            send_action_packet(0x25);
        }
        break;
    case 9:
        if (this->stateStep == 6) {
            this->pick_next_action();
        }
        break;
    case 7:
        sync_target_pos();
        this->update_velocity();
        break;
    case 6:
        if (sub_802FC580(&destination.x) == 0) {
            this->destination.x = 0.0f;
            this->destination.y = 0.0f;
            this->destination.z = 0.0f;
        }
        this->update_velocity();
        this->save_position();
        break;
    case 0:
        this->advance_animation();
        switch (this->stateStep) {
        case 0:
            this->stateStep = 1;
        case 1:
            this->spawn_effect_if_in_band();
            sub_802FB09C();
            if (sub_802FBFA4() != 0) {
                this->m_650 = 0;
                this->rotation_y = this->m_85c;
                this->stateStep = 2;
                this->requested_action = 0x16;
            }
            break;
        case 2:
            if (this->is_passing_frame(14.0f) != 0) {
                this->flags |= 0x30;
                this->impactAge = 0;
                this->stateStep = 3;
            }
            break;
        case 3: {
            Vec v;
            this->m_864 += this->m_86c;
            this->move_with_wall_stop(this->destination_direction.x, this->destination_direction.z, this->m_864);
            eval_bezier_curve__12TBoss8DragonFPviiPvf(TBoss8Dragon__dive_height_curve, 3, 0, &v, (f32)this->impactAge / 60.0f);
            this->position.y = v.y;
            this->impactAge++;
            if (this->is_passing_frame(39.0f) != 0) {
                this->stateStep = 4;
                this->play_effect_sound(0x4003B210);
            }
            break;
        }
        case 4:
        case 5: {
            Vec v;
            this->move_with_wall_stop(this->destination_direction.x, this->destination_direction.z, this->m_868);
            this->rotation_x = approach_angle_limited(this->rotation_x, 0x4000, 0x400);
            if (this->m_860 < 0x2811) {
                this->m_860 += 0x117;
            }
            this->rotation_z += this->m_860;
            eval_bezier_curve__12TBoss8DragonFPviiPvf(TBoss8Dragon__dive_height_curve, 3, 0, &v, (f32)this->impactAge / 60.0f);
            this->position.y = v.y;
            this->impactAge++;
            if (this->m_410.y <= TBoss8Dragon__data_804744A8.y - 50.0f && this->stateStep == 4) {
                this->stateStep = 5;
                this->play_effect_sound(0x4003AD0F);
            }
            if (this->position.y <= 0.0f && this->m_890 == 0) {
                TBoss8Dragon::init_state((saddr)this);
                fill_value_array(this->attack_history);
                create_boss8_piller_ctrl((saddr)&position, (s32)(((s32 (*)(u8 *))get_entity_id)((u8 *)this)), 100.0f);
                this->m_890 = 1;
                this->set_invulnerable();
                this->disable_body_collision();
                this->set_action_state();
            }
            if (this->impactAge >= 60) {
                this->stateStep = 6;
                this->flags &= ~1;
            }
            break;
        }
        case 6:
            break;
        }
        break;
    case 5:
        this->rotation_x = 0;
        this->rotation_z = 0;
        break;
    case 1:
    case 3:
    case 8:
    case 10:
        break;
    }
}

void TBoss8Dragon::sub_802F7B4C(s32 event) { sub_802F7808(event, 16); }

void TBoss8Dragon::action_17(s32 event) { sub_802F7808(event, 17); }

#pragma push
#pragma fp_contract on
void TBoss8Dragon::sub_802F7808(u32 event, s32 action) {
    s32 a;
    switch (event) {
    case 4:
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags |= 0x30;
        this->flags &= ~7;
        this->set_invulnerable();
        this->disable_body_collision();
        if (action == 0x10) {
            this->m_6d0 = 0;
        } else {
            this->m_6d0++;
        }
        fill_value_array(this->attack_history);
        this->stateStep = 0;
        this->impactAge = 0;
        this->m_864 = 0.0f;
        this->m_868 = this->calc_step_value();
        break;
    case 2:
    case 11:
        this->send_action_packet(0x1C);
        break;
    case 9:
        if (this->m_8a0 != 0) {
            this->pick_next_action();
            this->m_8a0 = 0;
        } else if (this->stateStep == 1) {
            Vec v;
            VecCopy(&v, &this->position);
            v.y = 0.0f;
            if (normalize_vector_xz((Vec *)&v) < 50.0f) {
                this->pick_next_action();
            }
        }
        break;
    case 6:
        a = (s32)(65536.0f * this->random_ratio());
        this->position.x = 350.0f * sin_table_lookup(a);
        this->position.z = 350.0f * cos_table_lookup(a);
        this->copy_pos_to_field688();
        break;
    case 0:
        switch (this->stateStep) {
        case 0:
            this->impactAge++;
            if ((f32)this->impactAge >= 60.0f) {
                this->impactAge = 0;
                this->stateStep = 1;
                this->restore_target_pos();
                this->rotation_y = (s32)(RADIANS_TO_ANGLE * atan2_float(this->position.x, this->position.z)) + 0x8000;
                this->destination_direction.x = sin_table_lookup(this->rotation_y);
                this->destination_direction.z = cos_table_lookup(this->rotation_y);
            }
            break;
        case 1:
            this->m_864 += 0.1f;
            if (this->m_864 > this->m_868) {
                this->m_864 = this->m_868;
            }
            this->position.x = this->destination_direction.x * this->m_864 + this->position.x;
            this->position.z = this->destination_direction.z * this->m_864 + this->position.z;
            ((void (*)(u8 *))TBoss8Dragon__sub_802FB300)((u8 *)this);
            this->impactAge++;
            if (this->impactAge > 10) {
                this->spawn_effect();
                this->impactAge = 0;
            }
            break;
        }
        this->spawn_trap(0x4003AD11);
        break;
    case 5:
        this->clear_invulnerable();
        this->enable_body_collision();
        break;
    }
}

#undef F
void TBoss8Dragon::sub_802F75C8(s32 event) {
    struct { f32 x, y, z; } sp8;
    switch (event) {
    case 4:
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF8);
        this->set_invulnerable();
        this->disable_body_collision();
        this->stateStep = 0;
        this->impactAge = 0;
        this->m_868 = this->calc_step_value();
        return;
    case 2:
    case 11:
        send_action_packet(0x1C);
        return;
    case 9:
        VecCopy((Vec *)(&sp8), &this->position);
        if (normalize_vector_xz((Vec *)&sp8) > 350.0f) {
            this->pick_next_action();
        }
        return;
    case 7:
        sync_target_pos();
        return;
    case 6:
        if (this->select_target_in_front() != 0) {
            this->enemy_copy_target_destination();
            this->update_velocity();
        } else {
            this->destination_direction.x = sin_table_lookup((int) (this->rotation_y));
            this->destination_direction.z = cos_table_lookup((int) (this->rotation_y));
        }
        this->destination.x = (350.0f * this->destination_direction.x);
        this->destination.y = 0.0f;
        this->destination.z = (f32) (350.0f * this->destination_direction.z);
        this->save_position();
        return;
    case 0:
        this->update_velocity();
        this->rotation_y = approach_angle_limited((this->rotation_y), ((s32) (RADIANS_TO_ANGLE * atan2_float((f32) (this->destination_direction.x), (f32) (this->destination_direction.z)))), 0x600);
        this->position.x = (f32) ((this->m_868 * sin_table_lookup((int) (this->rotation_y))) + this->position.x);
        this->position.z = (f32) ((this->m_868 * cos_table_lookup((int) (this->rotation_y))) + this->position.z);
        ((s32 (*)(void *)) TBoss8Dragon__sub_802FB300)(this);
        this->impactAge = (s32) (this->impactAge + 1);
        if ((s32) this->impactAge > 0xA) {
            this->spawn_effect();
            this->impactAge = 0;
        }
        this->spawn_trap(0x4003AD11);
        return;
    case 5:
        this->clear_invulnerable();
        this->enable_body_collision();
        break;
    }
}

void TBoss8Dragon::handle_spiral_state(s32 event) {
    s32 a;
    switch (event) {
    case 4:
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags |= 0x30;
        this->flags &= ~7;
        this->set_invulnerable();
        this->disable_body_collision();
        fill_value_array(attack_history);
        this->stateStep = 0;
        this->impactAge = 0;
        this->m_868 = this->calc_step_value();
        this->m_864 = 2.5f * this->m_868;
        this->m_86c = 350.0f;
        this->m_85c = 0;
        break;
    case 2:
    case 11:
        send_action_packet(0x1C);
        break;
    case 9:
        if (this->m_8a0 != 0) {
            this->pick_next_action();
            this->m_8a0 = 0;
        } else if (this->stateStep == 2) {
            this->pick_next_action();
        }
        break;
    case 6:
        a = (s32)(65536.0f * random_ratio());
        this->position.x = 350.0f * sin_table_lookup(a);
        this->position.z = 350.0f * cos_table_lookup(a);
        copy_pos_to_field688();
        break;
    case 0:
        switch (this->stateStep) {
        case 0:
            this->impactAge++;
            if ((f32)this->impactAge >= 60.0f) {
                this->impactAge = 0;
                this->stateStep = 1;
                restore_target_pos();
                this->m_85c = (s32)(RADIANS_TO_ANGLE * atan2_float(this->position.x, this->position.z));
                return;
            }
            break;
        case 1:
            a = (s32)(RADIANS_TO_ANGLE * (this->m_864 / this->m_86c));
            this->m_85c += a;
            this->position.x = this->m_86c * sin_table_lookup(this->m_85c);
            this->position.z = this->m_86c * cos_table_lookup(this->m_85c);
            this->m_86c -= 0.0010681152f * (f32)a;
            if (this->m_86c < 5.0f) {
                this->stateStep = 2;
            }
            ((void (*)(u8 *))TBoss8Dragon__sub_802FB300)(((u8 *)this));
            this->impactAge++;
            if (this->impactAge > 10) {
                this->spawn_effect();
                this->impactAge = 0;
            }
            this->spawn_trap(0x4003AD11);
            return;
        case 2:
            break;
        }
        break;
    case 5:
        this->clear_invulnerable();
        this->enable_body_collision();
        break;
    }
}

void TBoss8Dragon::handle_leap_state(s32 event) {
    f32 *d = &m_878;
    f32 v;

    switch (event) {
    case 4:
        this->requested_action = 0x18;
        this->advance_animation();
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags |= 0x30;
        this->flags &= ~7;
        this->stateStep = 0;
        this->impactAge = 0;
        break;
    case 2:
    case 11:
        if (this->stateStep == 6) {
            send_action_packet(0x1A);
        }
        break;
    case 9:
        if (this->stateStep == 6) {
            send_action_packet(8);
        }
        break;
    case 6:
        if (sub_802FC580(&destination.x) == 0) {
            this->destination.x = 0.0f;
            this->destination.y = this->position.y;
            this->destination.z = 0.0f;
            this->update_velocity();
        }
        this->save_position();
        break;
    case 0:
        switch (this->stateStep) {
        case 0:
            this->impactAge++;
            if ((f32)this->impactAge >= 100.0f) {
                this->stateStep = 1;
                this->flags |= 1;
                d[0] = TBoss8Dragon__data_804744A8.x - this->position.x;
                d[1] = 0.0f;
                d[2] = TBoss8Dragon__data_804744A8.z - this->position.z;
                v = normalize_vector_xz((Vec *)d);
                if (v > 110.0f) {
                    v = 110.0f;
                }
                if (v <= 100.0f) {
                    this->m_864 = 0.0f;
                    this->rotation_x = 0;
                } else {
                    f32 k = 37.333336f;
                    k += newton_sqrtf(298.6667f);
                    this->m_864 = v / k;
                    this->rotation_x = (s32)(RADIANS_TO_ANGLE * atan2_float(this->m_864, 15.0f));
                }
                this->rotation_y = (s32)(RADIANS_TO_ANGLE * atan2_float(d[0], d[2]));
                this->m_868 = 15.0f;
                d[0] *= this->m_864;
                d[2] *= this->m_864;
                f32 step = -11.333333f;
                this->position.x = d[0] * step + this->position.x;
                this->position.z = d[2] * step + this->position.z;
                this->position.y = -170.0f;
            }
            break;
        case 1:
            if (this->position.y > TBoss8Dragon__data_804744A8.y) {
                this->stateStep = 2;
                this->clear_invulnerable();
                this->enable_body_collision();
                this->set_state();
                TBoss8Dragon::init_state((saddr)((u8 *)this));
                fill_value_array(attack_history);
                create_boss8_piller_ctrl((saddr)((u8 *)&position), (s32)(((s32 (*)(void *))get_entity_id)(this)), 100.0f);
                this->play_effect_sound(0x4003AD0F);
            }
            break;
        case 2:
            if (this->position.y > 110.0f) {
                this->stateStep = 3;
            }
            break;
        case 3:
            if (this->m_868 < 0.0f && this->position.y < 220.0f) {
                this->stateStep = 4;
                this->m_86c = this->m_868 * this->m_868 / 80.0f;
            }
            break;
        case 4:
            if (this->m_868 > 0.0f) {
                this->stateStep = 5;
                this->m_868 = 0.0f;
                this->impactAge = 0;
            }
            break;
        }
        switch (this->stateStep) {
        case 1:
            vec3_add_to((u8 *)&position, d);
            this->position.y += this->m_868;
            break;
        case 2:
            vec3_add_to((u8 *)&position, d);
            this->m_868 += -0.4017857f;
            this->position.y += this->m_868;
            break;
        case 3:
            this->advance_animation();
            this->m_868 += -0.4017857f;
            if (this->frame >= 15.0f) {
                d[0] *= 0.98f;
                d[2] *= 0.98f;
            }
            vec3_add_to((u8 *)&position, d);
            this->position.y += this->m_868;
            this->rotation_x = approach_angle_limited(this->rotation_x, 0, 0x80);
            break;
        case 4:
            this->advance_animation();
            if (this->requested_action == 0x10) {
                this->spawn_effect_if_in_band();
            }
            this->m_868 += this->m_86c;
            this->position.y += this->m_868;
            d[0] *= 0.98f;
            d[2] *= 0.98f;
            vec3_add_to((u8 *)&position, d);
            break;
        case 5:
            this->advance_animation();
            this->spawn_effect_if_in_band();
            this->impactAge++;
            if (this->impactAge >= 50) {
                this->stateStep = 6;
            }
            break;
        }
        break;
    case 5:
        this->rotation_x = 0;
        break;
    }
}

#pragma pop
#pragma push
#pragma pool_data off
void TBoss8Dragon::sub_802F6838(s32 event) {
    CameraPlayback cam;
    Rot_802F6838 r;
    Vec v;

    switch (event) {
    case 4: {
        this->requested_action = 0x13;
        this->set_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags |= 0x36;
        this->stateStep = 0;
        this->impactAge = 0;
        this->m_864 = 0.0f;
        this->m_894 = 0;
        play_cue_stream_file((saddr)"goldeath.adx");
        TWindowCtrl::init_all_slots();
        cam.bank = 2;
        cam.index = 0;
        cam.flags = 0;
        cam.frame = 0.0f;
        cam.frame_step = 0.5f;
        activate_camera_mode(5, 0.0f);
        cam.cache_target_and_forward(0x31C7);
        set_scripted_camera_pose((u8 *)&position, (u8 *)&position, (u8 *)&rotation_x);
        break;
    }
    case 2:
    case 11:
        if (this->impactAge >= 50) {
            send_action_packet(0x17);
        }
        break;
    case 9:
        if (this->impactAge >= 50) {
            send_action_packet(0x17);
        }
        break;
    case 8:
        TBoss8Dragon::update_all_parts();
        break;
    case 0:
        this->advance_animation();
        switch (this->stateStep) {
        case 0:
            if (this->is_passing_frame(60.0f) != 0 || this->is_passing_frame(98.0f) != 0) {
                play_sound_effect(0x4003AD07, 0, 0, 0);
                start_pad_rumble_all(0xA0, 0xF);
            }
            if (this->frame >= 25.0f && this->frame < 40.0f) {
                direction_to_rotation_xz((u8 *)&m_41c, &r.x, &r.z);
                if (this->m_894 == 0) {
                    this->m_894 = (TParticleCtrl *)spawn_particle_effect_with_rotation(&m_410, &r, this->particle_ids[7], 0x40);
                }
                if (this->m_894 != 0) {
                    this->m_894->set_position((u8 *)&m_428);
                    this->m_894->set_direction(&r);
                }
            } else if (this->m_894 != 0) {
                this->m_894->queue_destruction();
                this->m_894 = 0;
            }
            if (this->is_passing_frame(57.0f) != 0) {
                DragonAttackParams e = TBoss8Dragon__body_effect_parameters;
                e.field_8 = 12.0f;
                VecCopy(&v, &lbl_804744F0);
                rotate_xz_pair_by_angle(&v.x, &v.z, this->rotation_y);
                vec3_add_to(&v, (u8 *)&position);
                reset_hp((u8 *)0, (u8 *)(TBoss8Dragon__data_80541DC8[4]), (u8 *)0);
                emit_effect(&v, &e, 0);
                reset_hp((u8 *)0, (u8 *)(TBoss8Dragon__data_80541DC8[0]), (u8 *)0);
                spawn_particle_effect_with_flags(&v, this->particle_ids[2], (s32)(0x40));
                if (this->particle_ids[3] != -1) {
                    spawn_particle_effect_with_flags(&position, this->particle_ids[3], 0x40);
                }
            }
            if (this->is_passing_frame(88.0f) != 0) {
                DragonAttackParams e = TBoss8Dragon__body_effect_parameters;
                e.field_8 = 25.0f;
                VecCopy(&v, &lbl_804744FC);
                rotate_xz_pair_by_angle(&v.x, &v.z, this->rotation_y);
                vec3_add_to(&v, (u8 *)&position);
                reset_hp((u8 *)0, (u8 *)(TBoss8Dragon__data_80541DC8[4]), (u8 *)0);
                emit_effect(&v, &e, 0);
                reset_hp((u8 *)0, (u8 *)(TBoss8Dragon__data_80541DC8[0]), (u8 *)0);
                spawn_particle_effect_with_flags(&v, this->particle_ids[2], (s32)(0x40));
                if (this->particle_ids[3] != -1) {
                    spawn_particle_effect_with_flags(&position, this->particle_ids[3], 0x40);
                }
            }
            if (this->is_passing_frame(97.0f) != 0) {
                this->emit_body_effects();
            }
            if (this->get_flag_b4() != 0) {
                this->stateStep = 1;
                this->impactAge = 0;
            }
            break;
        case 1:
            (this->impactAge)++;
            if (this->impactAge >= 50) {
                TWindowCtrl::init_all_slots2();
                restore_player_cameras();
            }
            break;
        }
        break;
    case 5:
        refresh_and_send_entity_flags();
        set_story_flag_or_send_quest_flag(0x4F);
        this->actorFlags = 0x12008;
        this->vfunc_74(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        if (this->m_894 != 0) {
            this->m_894->queue_destruction();
            this->m_894 = 0;
        }
        if (this->m_74c != 0) {
            release_grabbed_player();
        }
        break;
    }
}
#pragma pop

#pragma push
#pragma fp_contract on
void TBoss8Dragon::sub_802F6708(s32 event) {
    f32 temp_f1;
    f32 temp_f4;

    switch (event) {
    case 4:
        this->set_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags | 0xB6);
        this->stateStep = 0;
        break;
    case 2:
    case 11:
        if ((s32) this->stateStep >= 6) {
            send_action_packet(0x17);
        }
        break;
    case 9:
        if ((s32) this->stateStep >= 6) {
            send_action_packet(0x17);
        }
        break;
    case 0:
        temp_f4 = (f32) this->stateStep / 6.0f;
        temp_f1 = 2.0f * (1.0f - temp_f4);
        this->scale.x = temp_f1;
        this->scale.y = (f32) (2.0f * ((3.0f * temp_f4) + 1.0f));
        this->scale.z = temp_f1;
        this->stateStep = (s32) (this->stateStep + 1);
        break;
    case 5:
        if ((s32) this->m_74c != 0) {
            release_grabbed_player();
        }
        TObject::queue_destruction();
        break;
    }
}

#pragma pop
void TBoss8Dragon::sub_802F6618(s32 event) {
    s32 i;
    switch (event) {
    case 4:
        this->requested_action = 0x13;
        this->set_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags |= 0x136;
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].set_speed(0.005f);
        }
        break;
    case 0:
        this->advance_animation();
        for (i = 0; i < 4; i++) {
            if (this->renderFadeStates[i].decay_value_toward_floor() != 0) {
                TObject::queue_destruction();
                return;
            }
        }
        break;
    case 2:
    case 11:
        break;
    }
}

void TBoss8Dragon::sub_802F645C(s32 event) {
    u8 *temp_r4;
    u8 *temp_r4_2;
    u8 *temp_r4_3;
    switch (event) {
    case 4:
        this->requested_action = 0;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags & ~0x36);
        return;
    case 11:
        temp_r4 = (u8 *)this->controller_input;
        if (*(f32 *)((s8 *)temp_r4 + 0x24) > 0.1f) {
            send_action_packet(0x19);
            return;
        }
        if (this->mask_flags(*(s32 *)(temp_r4 + 8), 4) != 0) {
            send_action_packet(3);
            return;
        }
        if (this->mask_flags(this->controller_input->unknown_08, 2) != 0) {
            send_action_packet(4);
            return;
        }
        if (sub_802FABB4() != 0) {
            send_action_packet(5);
            return;
        }
        if (this->mask_flags(this->controller_input->unknown_08, fn_8002AE08(TBoss8Dragon__data_805D69BC)) != 0) {
            send_action_packet(9);
        }
        return;
    case 2:
        temp_r4_2 = (u8 *)this->controller_input;
        if (*(f32 *)((s8 *)temp_r4_2 + 0x24) > 0.1f) {
            send_action_packet(0x19);
            return;
        }
        temp_r4_3 = (u8 *)(*(u8 **)((s8 *)temp_r4_2 + 8));
        if ((saddr) temp_r4_3 & 4) {
            send_action_packet(3);
            return;
        }
        if ((saddr) temp_r4_3 & 2) {
            send_action_packet(4);
            return;
        }
        if ((saddr) temp_r4_3 & 0x400) {
            send_action_packet(5);
            return;
        }
        break;
    case 7:
        restore_target_pos();
        return;
    case 6:
        copy_pos_to_field688();
        return;
    case 0:
        this->advance_animation();
        break;
    }
}

void TBoss8Dragon::sub_802F610C(s32 event) {
    s32 *p = (s32 *)((u8 *)this + 0x85C);
    u8 *q;
    f32 s;
    f32 c;
    f32 scale;
    switch (event) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags &= ~0x36;
        this->stateStep = 0;
        this->impactAge = 0;
        return;
    case 2:
        if (this->impactAge == 1) {
            send_action_packet(0x18);
            return;
        }
        q = *(u8 **)((s8 *)((u8 *)this->controller_input) + 8);
        if ((saddr)q & 4) {
            send_action_packet(3);
            return;
        }
        if ((saddr)q & 2) {
            send_action_packet(4);
            return;
        }
        if ((saddr)q & 0x400) {
            send_action_packet(5);
            return;
        }
        break;
    case 11:
        if (this->impactAge == 1) {
            send_action_packet(0x18);
            return;
        }
        if (this->mask_flags(this->controller_input->unknown_08, 4) != 0) {
            send_action_packet(3);
            return;
        }
        if (this->mask_flags(this->controller_input->unknown_08, 2) != 0) {
            send_action_packet(4);
            return;
        }
        if (sub_802FABB4() != 0) {
            send_action_packet(5);
            return;
        }
        if (this->mask_flags(this->controller_input->unknown_08, fn_8002AE08(TBoss8Dragon__data_805D69BC)) != 0) {
            send_action_packet(9);
            return;
        }
        break;
    case 8:
        (this->stateStep)++;
        if (this->stateStep >= 0x1E) {
            this->stateStep = 0;
            q = (u8 *)this->controller_input;
            if (*(f32 *)((s8 *)q + 0x24) <= 0.1f) {
                this->impactAge = 1;
                return;
            }
            *p = *(s32 *)((s8 *)q + 0x1C);
            this->set_speed(*p);
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        sub_802FBBC8(p);
        return;
    case 6:
        this->set_speed(this->rotation_y);
        return;
    case 0:
        this->advance_animation();
        if (this->requested_action == 1) {
            this->play_sound_if_in_band();
        }
        if (this->is_passing_frame(24.0f) != 0) {
            TBoss8Dragon::check_condition_default(this);
        } else if (this->is_passing_frame(3.0f) != 0) {
            TBoss8Dragon::set_state_1(this);
        }
        this->play_speed = 0.48000002f;
        scale = 0.8f;
        if (this->frame > 4.0f && this->frame < 9.0f) {
            return;
        }
        if (this->frame > 24.0f && this->frame < 30.0f) {
            return;
        }
        this->rotation_y = approach_angle_limited(this->rotation_y, *p, 0x200);
        s = sin_table_lookup(this->rotation_y);
        c = cos_table_lookup(this->rotation_y);
        if (this->m_74c != 0) {
            scale = this->clamp_step_in_radius(s, c, 0.8f);
        }
        this->move_to_shot_position(s, c, scale);
        break;
    }
}

void TBoss8Dragon::sub_802F5F64(s32 event) {
    u8 *temp_r3;
    u8 *temp_r4;
    u8 *temp_r4_2;
    switch (event) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags = (s32) (this->flags & ~0x36);
        return;
    case 11:
        if ((this->m_754 > 0x1C2) || (this->mask_flags(this->controller_input->unknown_08, 2) != 0)) {
            send_action_packet(8);
            return;
        }
        temp_r3 = (u8 *)this->controller_input;
        if (*(f32 *)((s8 *)temp_r3 + 0x24) > 0.1f) {
            send_action_packet(0x1B);
            return;
        }
        if (this->mask_flags(*(s32 *)(temp_r3 + 8), 4) != 0) {
            send_action_packet(7);
            return;
        }
        if (this->check_attack_ready() != 0) {
            send_action_packet(0xF);
        }
        return;
    case 2:
        temp_r4 = (u8 *)this->controller_input;
        if (*(f32 *)((s8 *)temp_r4 + 0x24) > 0.1f) {
            send_action_packet(0x1B);
            return;
        }
        temp_r4_2 = (u8 *)(*(u8 **)((s8 *)temp_r4 + 8));
        if ((saddr) temp_r4_2 & 4) {
            send_action_packet(7);
            return;
        }
        if ((saddr) temp_r4_2 & 2) {
            send_action_packet(0xF);
            return;
        }
        if ((saddr) temp_r4_2 & 0x400) {
            send_action_packet(8);
            return;
        }
        break;
    case 7:
        restore_target_pos();
        return;
    case 6:
        copy_pos_to_field688();
        return;
    case 0:
        this->advance_animation();
        this->spawn_effect_if_in_band();
        sub_802FB09C();
        break;
    }
}

void TBoss8Dragon::sub_802F5CC8(s32 event) {
    s32 *p = (s32 *)((u8 *)this + 0x85C);
    u8 *q;
    f32 s;
    f32 c;
    f32 scale;

    switch (event) {
    case 4:
        this->requested_action = 0x10;
        this->clear_intangible();
        this->set_state();
        this->activate_attack();
        this->flags &= ~0x36;
        this->stateStep = 0x64;
        this->impactAge = 0;
        return;
    case 11:
        if (this->m_754 > 0x1C2 || this->mask_flags(this->controller_input->unknown_08, 2) != 0) {
            send_action_packet(8);
            return;
        }
        if (this->impactAge == 1) {
            send_action_packet(0x1A);
            return;
        }
        if (this->mask_flags(this->controller_input->unknown_08, 4) != 0) {
            send_action_packet(7);
            return;
        }
        if (this->check_attack_ready() != 0) {
            send_action_packet(0xF);
        }
        return;
    case 2:
        if (this->impactAge == 1) {
            send_action_packet(0x1A);
            return;
        }
        q = *(u8 **)((s8 *)((u8 *)this->controller_input) + 8);
        if ((saddr)q & 4) {
            send_action_packet(7);
            return;
        }
        if ((saddr)q & 2) {
            send_action_packet(0xF);
            return;
        }
        if ((saddr)q & 0x400) {
            send_action_packet(8);
            return;
        }
        break;
    case 8:
        (this->stateStep)++;
        if (this->stateStep >= 0x1E) {
            this->stateStep = 0;
            q = (u8 *)this->controller_input;
            if (*(f32 *)((s8 *)q + 0x24) <= 0.1f) {
                this->impactAge = 1;
                return;
            }
            *p = *(s32 *)((s8 *)q + 0x1C);
            this->set_speed(*p);
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        sub_802FBBC8(p);
        return;
    case 6:
        this->set_speed(*p);
        return;
    case 0:
        this->advance_animation();
        this->spawn_effect_if_in_band();
        sub_802FB09C();
        this->rotation_y = approach_angle_limited(this->rotation_y, *p, 0x200);
        s = sin_table_lookup(this->rotation_y);
        c = cos_table_lookup(this->rotation_y);
        scale = 2.0f;
        if (this->m_74c != 0) {
            scale = this->clamp_step_in_radius(s, c, scale);
        }
        this->move_with_wall_stop(s, c, scale);
        break;
    }
}

void TBoss8Dragon::sub_802F5BA0(s32 event) {
    u8 *temp_r3;
    switch (event) {
    case 4:
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF8);
        this->set_invulnerable();
        this->disable_body_collision();
        this->stateStep = 0;
        break;
    case 2:
    case 11:
        temp_r3 = (u8 *)this->controller_input;
        if (*(f32 *)((s8 *)temp_r3 + 0x24) > 0.1f) {
            send_action_packet(0x1D);
            break;
        }
        if (*(s32 *)((s8 *)temp_r3 + 8) & 2) {
            send_action_packet(0x13);
            break;
        }
    default:
        break;
    case 7:
        restore_target_pos();
        break;
    case 6:
        copy_pos_to_field688();
        break;
    case 0:
        this->stateStep = (this->stateStep + 1);
        if ((s32) this->stateStep > 0xA) {
            this->spawn_effect();
            this->stateStep = 0;
        }
        break;
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss8Dragon::handle_walk_state(s32 event) {
    f32 temp_f1;
    f32 temp_f31;
    f32 temp_f31_2;
    u8 *temp_r30;
    u8 *temp_r4;

    temp_r30 = ((u8 *)this + 0x878);
    switch (event) {
    case 4:
        this->requested_action = 0x11;
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF8);
        this->set_invulnerable();
        this->disable_body_collision();
        VecCopy((Vec *)temp_r30, &this->position);
        this->stateStep = 0x64;
        this->impactAge = 0;
        *(f32 *)((s8 *)temp_r30 + 4) = TBoss8Dragon__data_804744A8.y;
        this->m_864 = 0.0f;
        this->m_868 = 0.0f;
        return;
    case 2:
    case 11:
        if ((s32) this->impactAge == 1) {
            send_action_packet(0x1C);
            return;
        }
        if (this->controller_input->unknown_08 & 2) {
            send_action_packet(0x13);
        }
        return;
    case 8:
        this->stateStep = (this->stateStep + 1);
        if ((s32) this->stateStep >= 0x1E) {
            this->stateStep = 0;
            temp_r4 = (u8 *)this->controller_input;
            if (*(f32 *)((s8 *)temp_r4 + 0x24) <= 0.1f) {
                this->impactAge = 1;
                return;
            }
            this->rotation_y = (s32) *(s32 *)((s8 *)temp_r4 + 0x1C);
            this->set_speed(this->rotation_y);
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        sub_802FBBC8(&this->rotation_y);
        return;
    case 6:
        this->set_speed(this->rotation_y);
        return;
    case 0:
        temp_f31 = sin_table_lookup(this->rotation_y);
        temp_f1 = cos_table_lookup(this->rotation_y);
        f32 speed = 4.0f;
        this->position.x = (f32) ((temp_f31 * speed) + this->position.x);
        this->position.z = (f32) ((temp_f1 * speed) + this->position.z);
        temp_f31_2 = newton_sqrtf(horizontal_distance_squared(&this->position, (Vec *)temp_r30));
        VecCopy((Vec *)temp_r30, &this->position);
        this->m_864 = (f32) (this->m_864 + temp_f31_2);
        break;
    }
}

#pragma pop
void TBoss8Dragon::sub_802F57E4(s32 event) {
    s32 temp_r4;
    switch (event) {
    case 4:
        this->requested_action = 0x11;
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF8);
        this->set_invulnerable();
        this->disable_body_collision();
        this->calc_velocity_from_angle();
        return;
    case 2:
    case 11:
        if (((s32) this->stateStep >= 0x1C2) || (this->mask_flags(this->controller_input->unknown_08, 0x400) != 0)) {
            send_action_packet(0x26);
        }
        return;
    case 7:
        this->m_758 = (s32) this->m_690;
        if (this->m_694 > 0.0f) {
            this->m_85c = 0x180;
            return;
        }
        this->m_85c = -0x180;
        return;
    case 6:
        this->m_688 = (f32) (65536.0f * random_ratio());
        this->m_68c = calc_elapsed_scaled();
        return;
    case 0:
        this->m_758 = (s32) (this->m_758 + this->m_85c);
        if ((s32) this->m_85c >= 0) {
            this->rotation_y = (s32) (this->m_758 + 0x9800);
        } else {
            this->rotation_y = (s32) (this->m_758 + 0xFFFF6800);
        }
        this->calc_velocity_from_angle();
        temp_r4 = this->stateStep;
        this->stateStep = (temp_r4 + 1);
        ((s32 (*)(void *, int))TBoss8Dragon__sub_802FB300)(this, temp_r4);
        break;
    }
}

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off
void TBoss8Dragon::sub_802F5644(s32 event) {
    f32 temp_f1;
    f32 temp_f2;
    switch (event) {
    case 4:
        this->requested_action = 0x11;
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags = (s32) (this->flags | 0x30);
        this->flags = (s32) (this->flags & 0xFFFFFFF8);
        this->set_invulnerable();
        this->disable_body_collision();
        this->m_864 = 0.0f;
        this->destination_direction.x = (f32) -this->position.x;
        this->destination_direction.y = 0.0f;
        this->destination_direction.z = (f32) -this->position.z;
        normalize_vector_xz((Vec *)((u8 *)this + 0x3A0));
        this->rotation_y = (s32) (RADIANS_TO_ANGLE * atan2_float((f32) (this->destination_direction.x), this->destination_direction.z));
        return;
    case 2:
    case 11:
        if (this->m_868 >= 680.0f) {
            send_action_packet(0x13);
        }
        return;
    case 7:
        restore_target_pos();
        return;
    case 6:
        copy_pos_to_field688();
        return;
    case 0:
        this->m_864 += 0.1f;
        if (this->m_864 > 12.0f) {
            this->m_864 = 12.0f;
        }
        this->m_868 = (f32) (this->m_868 + this->m_864);
        this->position.x = (f32) ((this->destination_direction.x * this->m_864) + this->position.x);
        temp_f2 = this->destination_direction.z;
        temp_f1 = this->m_864;
        this->position.z = (f32) ((temp_f2 * temp_f1) + this->position.z);
        ((s32 (*)(void *, f32, f32)) TBoss8Dragon__sub_802FB300)(this, temp_f1, temp_f2);
        break;
    }
}

#pragma pop
void TBoss8Dragon::sub_802F5434(s32 event) {
    f32 temp_f1;
    s32 i;
    s32 j;
    switch (event) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags & ~0x36);
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].set_speed(0.02f);
        }
        this->flags = (this->flags | 0x100);
        this->stateStep = 0;
        temp_f1 = *(f32 *)((s8 *)TBoss8Dragon__data_80541DDC[0] + 0x10);
        this->m_864 = (f32) (5.0f + TObjBoss2Tunnel::calc_scaled_value((s32) (320.0f * temp_f1), temp_f1));
        return;
    case 2:
    case 11:
        send_action_packet(0x18);
        return;
    case 9:
        if (this->sub_802F46F4() == 0) {
            this->pick_next_action();
        }
        return;
    case 8:
        this->update_linked_position();
        this->stateStep = (this->stateStep + 1);
        if ((s32) (this->stateStep % 20) == 0x13) {
            if (enemy_validate_retained_target(this) != 0) {
                this->enemy_copy_target_destination();
            } else {
                this->set_target_destination(&TBoss8Dragon__data_804744A8);
            }
            this->save_position();
            this->send_6xA8_action();
            return;
        }
        break;
    case 7:
        sync_target_pos();
        return;
    case 6:
        this->acquire_counter = (s32) this->acquire_period;
        if (this->update_linked_position() != 0) {
            this->enemy_copy_target_destination();
        } else {
            this->set_target_destination(&TBoss8Dragon__data_804744A8);
        }
        this->save_position();
        return;
    case 0:
        this->update_movement();
        for (j = 0; j < 4; j++) {
            this->renderFadeStates[j].decay_value_toward_floor();
        }
        return;
    case 5:
        this->flags = (s32) (this->flags & 0xFFFFFEFF);
        break;
    }
}

#pragma push
#pragma fp_contract on
void TBoss8Dragon::sub_802F51DC(s32 event) {
    Vec v;
    f32 temp_f1;
    f32 var_f2;
    s32 i;
    s32 j;
    switch (event) {
    case 4:
        this->requested_action = 1;
        this->clear_intangible();
        this->reset_timer();
        this->set_active_flag();
        this->flags = (s32) (this->flags & ~0x36);
        sub_802F48DC(&this->destination);
        for (i = 0; i < 4; i++) {
            this->renderFadeStates[i].set_speed(0.02f);
        }
        this->flags = (s32) (this->flags | 0x100);
        temp_f1 = *(f32 *)((s8 *)TBoss8Dragon__data_80541DDC[0] + 0x10);
        this->m_864 = (f32) (5.0f + TObjBoss2Tunnel::calc_scaled_value((s32) (320.0f * temp_f1), temp_f1));
        this->play_effect_sound(0x4003A315);
        return;
    case 2:
    case 11:
        send_action_packet(0x18);
        return;
    case 9:
        if (this->hasActiveRenderFade() == 0) {
            this->pick_next_action();
        }
        return;
    case 7:
        sync_target_pos();
        return;
    case 6:
        this->acquire_counter = (s32) this->acquire_period;
        if (this->update_linked_position() != 0) {
            this->enemy_copy_target_destination();
        } else {
            this->set_target_destination(&TBoss8Dragon__data_804744A8);
        }
        v.x = this->destination.x - this->position.x;
        v.z = this->destination.z - this->position.z;
        if ((s32) ((u16) ((s32) (RADIANS_TO_ANGLE * atan2_float(v.x, v.z)) - this->rotation_y) + 0x2000) > 0x4000) {
            v.x = sin_table_lookup(this->rotation_y);
            v.z = cos_table_lookup(this->rotation_y);
            var_f2 = 120.0f;
        } else {
            var_f2 = normalize_vector_xz((Vec *)&v);
            var_f2 *= 0.5f;
        }
        this->destination.x = (f32) ((v.x * var_f2) + this->position.x);
        this->destination.z = (f32) ((v.z * var_f2) + this->position.z);
        this->save_position();
        return;
    case 0:
        this->update_movement();
        for (j = 0; j < 4; j++) {
            this->renderFadeStates[j].advance_toward_max();
        }
        return;
    case 5:
        this->flags = (s32) (this->flags & 0xFFFFFEFF);
        break;
    }
}

#pragma pop
void TBoss8Dragon::update_wander_state(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 0xB;
        this->stateStep = 0;
        return;
    case 0:
        this->stateStep = (s32) (this->stateStep + 1);
        if ((s32) this->stateStep > 0x5A) {
            this->stateStep = 0;
            this->requested_action = (s16) (this->requested_action + 1);
            if ((s16) this->requested_action >= 0x1C) {
                this->requested_action = 0;
            }
        }
        this->advance_animation();
    case 3:
    case 5:
    case 1:
        return;
    }
}

#pragma push
#pragma opt_common_subs off
#define o ((Drg_802F4DD4 *)this)
void TBoss8Dragon::sub_802F4DD4(s32 event) {
    s32 *flag = &o->f858;

    switch (event) {
    case 4: {
        o->fB8 = 0;
        ((TBoss8Dragon *)o)->reset_timer();
        ((TObjMotion *)o)->advance_animation();
        o->demo = 0;
        o->phase = 0;
        o->step = 0;
        o->f850 = 0;
        *flag = 1;
        new TBoss8DragonDemo(tl_01, flag, 0.5f);
        o->fB8 = 0x1A;
        TWindowCtrl::init_all_slots();
        ((TObjEneDD *)o)->get_target_state_b();
        ((TMainCursor *)o)->update_pair();
        break;
    }
    case 2:
    case 9:
        if (o->phase == 1) {
            ((TBoss8Dragon *)o)->send_action_packet(0);
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
                    Vec v;
                    v.x = 0.5f * (o->f458 + o->f470);
                    v.y = 0.0f;
                    v.z = 0.5f * (o->f460 + o->f478);
                    fill_value_array(o->attack_history);
                    create_boss8_piller_ctrl((saddr)&v, (s32)(((s32 (*)(void *))get_entity_id)(o)), 100.0f);
                    spawn_particle_effect_with_flags(&o->pos, o->info->a, 0x40);
                    if (o->info->b != -1) {
                        spawn_particle_effect_with_flags(&o->pos, o->info->b, 0x40);
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
                    play_cue_stream_file((saddr)"dradeath.adx");
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
            ((TObject *)o->demo)->queue_destruction();
            o->demo = 0;
        }
        ((TMainCursor *)o)->update_cursor_pair();
        *flag = 0;
        TWindowCtrl::init_all_slots2();
        ((TObjEneDD *)o)->get_target_state_a();
        break;
    }
}

#pragma pop
#undef o
void TBoss8Dragon::action(s32 event) {
    switch (event) {
    case 4:
        this->requested_action = 0;
        this->stateStep = 0;
        this->position.y = 0.0f;
        return;
    case 3:
        if ((s32) this->stateStep > 0x96) {
            this->transition_enemy_state(8);
        }
        break;
    case 0:
        if ((get_player_by_client_id(0) != 0U) || (get_player_by_client_id(1) != 0U) || (get_player_by_client_id(2) != 0U) || (get_player_by_client_id(3) != 0U)) {
            this->stateStep = (s32) (this->stateStep + 1);
        }
        break;
    case 5:
    case 1:
        break;
    }
}

void TBoss8Dragon::sub_802F4B90(s32 event) {
    s32 *p = (s32 *)((u8 *)this + 0x85C);

    switch (event) {
    case 4:
        this->clear_intangible();
        this->set_action_state();
        this->reset_action();
        this->flags |= 0x30;
        this->flags &= ~7;
        this->set_invulnerable();
        this->disable_body_collision();
        break;
    case 2:
    case 11:
        send_action_packet(0x1C);
        break;
    case 9:
        if (TBoss8Dragon::is_any_part_alive() != 0) {
            this->pick_next_action();
        }
        break;
    case 7:
        sub_802FBBC8(p);
        break;
    case 6: {
        u32 v = 4294967296.0f * (0.000030517578f * (f32)rand());
        this->set_speed((s32)v);
        break;
    }
    case 5:
        ((TBoss8Dragon *)(*(saddr *)(TBoss8Dragon__data_80541DDC[0] + 0x28)))->place_parts_in_ring(*(s32 *)(TBoss8Dragon__data_80541DDC[0] + 0x24), *p);
        this->clear_invulnerable();
        this->enable_body_collision();
        break;
    }
}

void TBoss8Dragon::update_movement() {
    Vec old;
    Vec d;
    f32 scale;
    s32 iscale;
    f32 v;
    scale = 0.8f + *(f32 *)((s8 *)TBoss8Dragon__data_80541DDC[0] + 0x10);
    iscale = (s32) (320.0f * scale);
    if (this->motion_flags & 4) {
        this->play_speed = 0.125f * scale;
    } else {
        this->play_speed = 0.6f * scale;
    }
    this->advance_animation();
    this->play_sound_if_in_band();
    this->update_velocity();
    sub_802FC9D8();
    if (this->is_passing_frame(24.0f) != 0) {
        TBoss8Dragon::check_condition_default(this);
    } else if (this->is_passing_frame(3.0f) != 0) {
        TBoss8Dragon::set_state_1(this);
    }
    VecCopy(&old, &this->position);
    v = this->frame;
    if (v < 4.0f) {
        this->move_to_shot_position(sin_table_lookup(this->rotation_y), cos_table_lookup(this->rotation_y), scale);
    } else if (!(v < 9.0f)) {
        if (v < 19.0f) {
            TObjEneEpsilon__sub_800B9384(this, iscale, scale);
        } else if (v < 24.0f) {
            this->move_to_shot_position(sin_table_lookup(this->rotation_y), cos_table_lookup(this->rotation_y), scale);
        } else if (!(v < 30.0f)) {
            TObjEneEpsilon__sub_800B9384(this, iscale, scale);
        }
    }
    d.x = this->position.x - old.x;
    d.y = this->position.y - old.y;
    d.z = this->position.z - old.z;
    VecCopy(&this->position, &old);
    this->apply_ground_movement(&d);
}

void TBoss8Dragon::sub_802F48DC(Vec *target) {
    Vec saved;
    u8 shot[0xC];
    Vec delta;
    f32 dist;
    VecCopy(&saved, &this->position);
    delta.x = target->x - (&this->position)->x;
    delta.y = 0.0f;
    delta.z = target->z - (&this->position)->z;
    dist = normalize_vector_xz((Vec *)&delta);
    this->calc_shot_position(shot, delta.x, delta.z, dist);
    this->try_move_actor_xz_on_ground(shot);
    (&this->position)->y = saved.y;
    if (this->is_near_other_part() != 0) {
        VecCopy(&this->position, &saved);
    }
}

void TBoss8Dragon::apply_ground_movement(Vec *step) {
    Vec c;
    Vec b;
    Vec a;
    f32 t;
    this->position.y = this->position.y + step->y;
    step->y = 0.0f;
    VecCopy(&a, &this->position);
    VecCopy(&c, step);
    t = normalize_vector_xz((Vec *)&c);
    this->calc_shot_position((u8 *)&b, (f32)c.x, (f32)c.z, (f32)t);
    this->try_move_actor_xz_on_ground((u8 *)&b);
    this->position.y = a.y;
    if ((this->push_apart_from_parts() != 0) && (this->is_near_other_part() != 0)) {
        VecCopy(&this->position, &a);
    }
}

#pragma push
#pragma fp_contract on
s32 TBoss8Dragon__sub_802F4760(void *owner, Vec *point, f32 farg0) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_802F4760, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_802F4760, spC) == 0x4);
    Stack_802F4760 stack;
    f32 temp_f1;
    VecCopy((Vec *)&stack.sp8, point);
    stack.spC = 0.0f;
    ((s32 (*)(void *, void *))subtract_vector)(&stack.sp8, &boss8_dragon_reference_pos_vec.value);
    temp_f1 = normalize_vector_xz((Vec *)&stack.sp8);
    if ((temp_f1 + farg0) < boss8_dragon_visibility_distance) {
        if (vec3_dot(&stack.sp8, &dragon_forward_reference_vec.value) >= (temp_f1 * (1.0f / newton_sqrtf((f32) ((temp_f1 * temp_f1) + (farg0 * farg0)))))) {
            return 1;
        }
    }
    return 0;
}

#pragma pop
s32 TBoss8Dragon::sub_802F46F4() {
    for (s32 i = 0; i < 4; ++i) {
        if (renderFadeStates[i].has_visible_opacity() != 0) {
            return 1;
        }
    }
    return 0;
}

s32 TBoss8Dragon::hasActiveRenderFade() {
    for (s32 i = 0; i < 4; ++i) {
        if (renderFadeStates[i].isFading() != 0) {
            return 1;
        }
    }
    return 0;
}

void TBoss8Dragon::update_camera_script(NJS_OBJECT *) {
    s32 temp_r0;
    saddr pos;
    if ((s32) TBoss8Dragon__data_805D698C == (s32) lbl_805D6990) {
        push_matrix();
        forward_split_screen_view_matrix();
        matrix_mult_vec_array(0, (void *)&lbl_80541DF4.value, TBoss8Dragon__data_805D6994, 3);
        pop_matrix();
    }
    if ((s32) TBoss8Dragon__data_805D698C == dragon_camera_script_frame_table[TBoss8Dragon__data_805D6998]) {
        pos = TBoss8Dragon__data_805D699C;
        TBoss8Dragon__data_805D699C = pos + 0xC;
        forward_transform_to_view((const Vec *)&lbl_80541DE8.value, (Vec *)pos);
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
    TBoss8Dragon__data_805D6994 = (saddr)((Obj_802F44D8 *)this)->f3EC;
    TBoss8Dragon__data_805D6998 = 0;
    TBoss8Dragon__data_805D699C = (saddr)((Obj_802F44D8 *)this)->f434;
    TBoss8Dragon__data_805D69A0 = ((Obj_802F44D8 *)this)->f3C0;
    set_chunk_model_node_callback(TBoss8Dragon::update_camera_script);
    push_matrix();
    set_motion_packed_rotation();
    post_translate_matrix(((Obj_802F44D8 *)this)->v38);
    rotate_matrix_y(0, ((Obj_802F44D8 *)this)->f60);
    rotate_matrix_x(0, ((Obj_802F44D8 *)this)->f5C);
    rotate_matrix_z(0, ((Obj_802F44D8 *)this)->f64);
    scale_current_matrix(((Obj_802F44D8 *)this)->v68);
    draw_motion((NJS_OBJECT *)((Obj_802F44D8 *)this)->f34, (NJS_MOTION *)((Obj_802F44D8 *)this)->fF8, this->get_motion_frame());
    clear_motion_packed_rotation();
    pop_matrix();
    set_chunk_model_node_callback(NULL);
    ((Obj_802F44D8 *)this)->f34 = saved;
}

void TBoss8Dragon::copy_vectors() {
    struct VOff_802F4480_arg0 *self = (struct VOff_802F4480_arg0 *)this;
    VecCopy((Vec *)self->f_410, (const Vec *)((char *)this + 1004));
    VecCopy((Vec *)self->f_41C, (const Vec *)((char *)this + 1016));
    subtract_vector(self->f_41C, self->f_410);
    VecCopy((Vec *)((char *)this + 1064), (const Vec *)((char *)this + 1028));
}

void TBoss8Dragon::render() {
    s32 view = 0;
    u8 pos[0xC];
    if (TObjPlayer::check_demo_mode() != 0) {
        draw_motion_model();
        return;
    }
    if (is_split_screen() != 0) {
        view = TCameraCtrl::get_camera_mode();
    }
    this->get_render_position(pos);
    if (defer_render() != 0) {
        if (!((s32)main_task.get_task_flags() & 0x10)) {
            this->render_body_model();
            this->copy_vectors();
        }
        if (this->renderFadeStates[view].isFading() == 0) {
            this->draw_with_fade((saddr)pos, view);
        }
        this->render_nodes_flagged();
    } else if (this->renderFadeStates[view].isFading() != 0) {
        this->draw_with_fade((saddr)pos, view);
    }
}

int TBoss8Dragon::run_demo_task() { return get_target_info(); }

void TBoss8Dragon::render_shadows() { if (TObjPlayer::check_demo_mode() == 0) { draw(); } }

void TBoss8Dragon::draw() {
    void *temp_r31;
    u8 *temp_r4;

    push_matrix();
    post_translate_matrix((void *) (((u8 *)this) + 0x38));
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, this->rotation_x);
    rotate_matrix_z(0, (int) (this->rotation_z));
    scale_current_matrix((void *) (((u8 *)this) + 0x68));
    temp_r31 = this->model;
    temp_r4 = (unsigned char *) (*(void **)((s8 *)TBoss8Dragon__data_805D6988 + 0x42C));
    this->model = *(void **)((s8 *)temp_r4 + 0x28);
    draw__10TObjMotionFv(this, (saddr)temp_r4);
    this->model = temp_r31;
    pop_matrix();
}

void TBoss8Dragon::draw_with_fade(saddr pos, s32 view) {
    RenderFadeState *fade;
    if (!(this->position.y <= -400.0f)) {
        TObjFish::set_global_param(this->texlist);
        TObjEneDD::clear_global_flag_400();
        saved_model_render_flags = model_render_flags;
        set_material_alpha_compare_reference(0);
        if (TBoss8Dragon__sub_802F3F20(((u8 *)this)) != 0) {
            this->renderFadeStates[view].fadeOut();
        } else {
            this->renderFadeStates[view].restore();
        }
        fade = &this->renderFadeStates[view];
        if (fade->isFading() != 0) {
            fade->set_flags_and_apply_damage_color();
        }
        push_matrix();
        post_translate_matrix((void *)pos);
        rotate_matrix_y(0, this->rotation_y);
        rotate_matrix_x(0, this->rotation_x);
        rotate_matrix_z(0, (int) (this->rotation_z));
        scale_current_matrix((void *) (((u8 *)this) + 0x68));
        TObjPlayer::toggle_particle_effect();
        if (this->flags & 0x80) {
            set_tev_swap_channels(3, 3, 3, 3);
        }
        if (has_enough_enemies() != 0) {
            this->model = *(void **)((s8 *)(*(u8 **)((s8 *)TBoss8Dragon__data_805D6988 + 0x42C)) + 0x18);
        } else {
            this->model = *(void **)((s8 *)(*(u8 **)((s8 *)TBoss8Dragon__data_805D6988 + 0x42C)) + 8);
        }
        ((TObjMotion *)((u8 *)this))->draw();
        init_tev_swap();
        TParticleCtrl::end_effect_render();
        current_scene_light->sub_801337F8();
        pop_matrix();
        set_chunk_material_override_pair(0xFF00, 0);
        set_material_alpha_compare_reference(0xBF);
        model_render_flags = saved_model_render_flags;
    }
}

void TBoss8Dragon::get_render_position(u8 *pos) {
    VecCopy((Vec *)pos, (const Vec *)(&this->position));
    if (((s32)main_task.get_task_flags() & 0x10) && (TBoss8Dragon__sub_802FCCBC(this) == 0) && !(this->frame > 63.0f)) {
        *(f32 *)((s8 *)pos + 8) += -460.0f;
    }
}

extern "C" {
s32 TBoss8Dragon__sub_802F3F20(u8 *owner) {
    Vec sp14;
    Vec sp8;
    f32 temp_f31;
    u8 *entity;
    s32 i;
    if (camera_ctrl_instance == 0) {
        return 0;
    }
    if (((Obj_802F3F20 *)owner)->x326 == 30) {
        return 0;
    }
    if (((Obj_802F3F20 *)owner)->x326 == 21) {
        return 0;
    }
    if (((Obj_802F3F20 *)owner)->x326 == 22) {
        return 0;
    }
    if (((Obj_802F3F20 *)owner)->x326 == 23) {
        return 1;
    }
    if (*(s32 *)(owner + 0x3E4) != 0) {
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
        if (TBoss8Dragon__sub_802F4760(owner, &((Obj_802F3F20 *)owner)->pts[boss8_dragon_point_index_table[i]], 12.0f) != 0) {
            return 1;
        }
    }
    return 0;
}
}

void TBoss8Dragon::render_nodes_flagged() {
    saddr self = (saddr)this;
    s32 temp_r4;

    temp_r4 = model_render_flags;
    saved_model_render_flags = temp_r4;
    model_render_flags = temp_r4 | 0x400;
    ((TObject *)(self + 0x3C4))->render_nodes();
    model_render_flags = saved_model_render_flags;
}

void TBoss8Dragon::draw_motion_model() {
    u8 *self = (u8 *)this;
    f32 f;
    s32 idx;
    Anim_802F3D6C *anim;
    if (this->update_object_view_visibility(400.0f, 20.0f) != 0) {
        TObjFish::set_global_param(*(s32 *)(self + 0x24));
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, *(s32 *)(self + 0x60));
        push_matrix();
        scale_matrix(0, 8.0f, 2.0f, 8.0f);
        pop_matrix();
        scale_matrix(0, 2.0f, 2.0f, 2.0f);
        model_render_flags &= ~0x400;
        idx = *(f32 *)(self + 0x354);
        if (idx < 0) {
            idx = 0;
        } else if (idx >= 0x1C) {
            idx = 0x1B;
        }
        anim = (*(B_802F3D6C **)(self + 0xDC))[(*(A_802F3D6C **)(self + 0xD8))[idx].idx].anim;
        f = *(f32 *)(self + 0x358);
        if (f < 0.0f) {
            f = 0.0f;
        } else if (f > (f32)(anim->nframes - 1)) {
            f = anim->nframes;
        }
        set_motion_packed_rotation();
        draw_model_motion((void *)(*(saddr *)(self + 0x34)), anim, f);
        clear_motion_packed_rotation();
        current_scene_light->sub_801337F8();
        pop_matrix();
    }
}

f32 TBoss8Dragon::receive_direct_attack(void *attacker, DirectAttackPayload payload, void *arg2, s32 arg3, s32 flags) {
    switch (payload.kind) {
    case 0xB:
    case 0xC:
        return 0.0f;
    }
    return TObjChara::receive_direct_attack(attacker, payload, arg2, arg3, flags);
}

#pragma push
#pragma pool_data off
void TBoss8Dragon::set_mode_params(s8 arg1) {
    u8 *self = (u8 *)this;
    *(s32 *)((s8 *)self + 0x3E8) = (s32) arg1;
    switch (*(s32 *)((s8 *)self + 0x3E8)) {
    case 0:
        this->m_75c = 1;
        this->particle_ids = boss8_dragon_mode_params;
        return;
    case 1:
        this->m_75c = 2;
        this->particle_ids = dragon_mode_params_a;
        return;
    case 2:
        this->m_75c = 3;
        this->particle_ids = dragon_mode_params_b;
        return;
    }
}
#pragma pop

