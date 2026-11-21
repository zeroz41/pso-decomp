#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/EnemyBmlResource.h"
#include "pso/system/BmlResource.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/animation/MotionContext.h"

struct NJS_OBJECT;

#include "pso/math/FloatRounding.h"

#include "pso/enemy/TObjEnemy.h"

#include "pso/enemy/berura/TObjEneRe7Berura_803E4CE0.h"

#include "pso/system/vector.h"
#include "pso/math/MatrixTransforms.h"

#include "pso/network/protocol/protocol_types.h"

#include "pso/unk/TLobby_801E43E4.h"

#include "pso/system/NinjaTypes.h"

#include "types.h"

#include "pso/camera/CameraPlayback.h"

#include "pso/render/NinjaUtil.h"

#include "pso/system/PadRumble.h"

#include "pso/enemy/dd/TObjEneDD.h"

#include "pso/enemy/dd/TObjEneDD_ST.h"

#include "pso/player/TObjPlayer.h"

#include "pso/object/base/TObjChara.h"

#include "pso/ui/hud/TRaderMapCore.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/boss/derolle/TBoss2DeRolLe.h"

#include "pso/boss/derolle/TUnk_80036250.h"

#include "pso/unk/text_803D8F74.h"

#include "pso/math/AngleLookup.h"

#include "pso/unk/text_80087278.h"

#include "pso/unk/text_803E2D70.h"

#include "pso/unk/text_803D96A8.h"

#include "pso/effect/particle/TParticleCtrl_800874F4.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"
#include "pso/enemy/dd/TObjEneDD_800B9B84.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"

extern "C" void has_flag_0x800__9TObjCharaFv();

extern "C" void test_flag30_512__9TObjCharaFv();

extern "C" void test_flag_1000__9TObjCharaFv();

extern "C" void test_flag_256__9TObjCharaFv();

#include "pso/effect/TBreakUpMdl.h"

#include "pso/unk/TUnk_80482090.h"

#include "pso/boss/derolle/TBoss2Tentacle.h"

#include "pso/object/TObjEZRopeBase.h"

#include "pso/system/task/TObject.h"
#include "pso/boss/derolle/TBoss2PhotonPad.h"
#include "pso/boss/derolle/TBoss2LaserLight.h"
#include "pso/system/SoundEffect.h"
#include "pso/boss/TUnk_80482C58.h"

#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/boss/derolle/TBoss2Fin.h"

#include "pso/boss/derolle/TBoss2Joint.h"

#include "pso/boss/derolle/TBoss2Mine.h"
#include "pso/camera/TCameraCtrl_801A6E60.h"

#include "pso/boss/derolle/TUnk_80482D04.h"

#include "pso/boss/derolle/TUnk_80482EC0.h"
#include "pso/enemy/AttackTargetHistory.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/task/TMainTask.h"
#include "pso/player/TObjPlayer_801542CC.h"

#include "pso/boss/volopt/TBoss3Volopt.h"

#include "pso/boss/darkfalz/TBoss4DarkFalz.h"

#include "pso/boss/darkfalz/TBoss4Type2.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"

#include "pso/boss/derolle/TObjBoss2CeilJunk.h"

#include "pso/boss/derolle/TObjBoss2Tunnel.h"

#include "pso/enemy/berura/TObjEneRe7Berura.h"

#include "pso/camera/TCameraCtrl.h"

#include "pso/unk/TLobby.h"

#include "pso/ui/hud/TNowLoading.h"

#include "pso/ui/window/TWindowCtrl.h"

#include "pso/object/ambient/TObjFish.h"

#include "pso/math/AngleUnits.h"

#include "pso/system/BmlResourceDescriptor.h"

#include <stddef.h>

// inferred: the five-word effect descriptor emit_effect and setup_instance read (an id word,
// three floats, a trailing word); sub_8002FE60 patches the first float per spawn
struct DeRolLeEffectParams {
    s32 pad_00;
    f32 pad_04;
    f32 pad_08;
    f32 pad_0C;
    s32 pad_10;
};

const s32 derolle_attack_sequence_id_table[21] = {
    0x18, 0x1A, 0x1C, 0x1D, 0x1E, 0x1F, 0x22, 0x45, 0x4A, 0x5F, 0x60,
    0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, -1,
};

const Vec TBoss2DeRolLe__position_point_table[4] = {
    {-175.0f, 7.0f, 25.0f},
    {0.0f, 7.0f, 500.0f},
    {175.0f, 7.0f, 25.0f},
    {0.0f, 7.0f, -250.0f},
};

const DeRolLeEffectParams derolle_effect_params = {0, 0.0f, 8.0f, 5.0f, 1};

// inferred: the five mine positions load_resources grounds into TBoss2DeRolLe__mine_ground_targets
const Vec derolle_mine_offsets[5] = {
    {0.0f, 0.0f, 0.0f},
    {45.0f, 0.0f, 30.0f},
    {45.0f, 0.0f, -30.0f},
    {-45.0f, 0.0f, 30.0f},
    {-45.0f, 0.0f, -30.0f},
};

// inferred: the effect sub_8002FE60 spawns where the laser hits
const DeRolLeEffectParams derolle_laser_hit_effect_params = {0, 120.0f, 16.0f, 20.0f, 1};

s32 de_rol_le_base_param_ids[1] = {0xF};

s32 de_rol_le_resistance_param_ids[1] = {0xF};

// inferred: the ids load_resources passes to TLobby::dispatch_shared_handler_a, the
// counterpart of TBoss2DeRolLe__shared_handler_id_table (dispatch_shared_handler_b)
s32 de_rol_le_shared_handler_a_ids[1] = {0xF};

// What TObjEnemy::movementParameters points at.
struct TBoss2DeRolLeMovement {
    EnemyMoveParams move;
    s32 unk_0C[4];
};

// The four points matrix_mult_vec_array places along a breakup piece (TObjPlayer__sub_8002F61C).
Vec derolle_part_transform_template[4] = {
    {0.0f, 0.0f, 0.0f},
    {0.0f, 0.0f, 1.0f},
    {0.0f, 0.0f, 4.0f},
    {0.0f, 0.0f, 13.0f},
};

s32 derolle_action_mode_sequence_table[44] = {
    0x1, 0x3, 0x18, 0x6, 0x11, 0x9, 0xC, 0x12, 0x14, 0x16, 0x3,
    0x6, 0x11, 0x9, 0xD, 0x19, 0x8, 0x10, 0x4, 0x13, 0x15, 0x17,
    0x9, 0xF, 0x21, 0x22, 0x1A, 0x1B, 0x1B, 0x1B, 0x1B, 0x1C, 0x23,
    0x24, 0x25, 0x21, 0x22, 0x1A, 0x1B, 0x1B, 0x1B, 0x1B, 0x1D, 0x2C,
};

s32 derolle_action_sequence_table[50] = {
    0x1, 0x28, 0x29, 0x2A, 0x2B, 0x22, 0xD, 0x25, 0x21, 0x28,
    0x27, 0x29, 0x2A, 0x2B, 0x27, 0x22, 0xF, 0x21, 0x28, 0x27,
    0x28, 0x27, 0x28, 0x22, 0x1A, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B,
    0x1C, 0xD, 0x25, 0x21, 0x28, 0x29, 0x2A, 0x2B, 0x28, 0x22,
    0x1A, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1B, 0x1D, 0x2C,
};

s32 TBoss2DeRolLe__shared_handler_id_table[3] = {0xF, 0x10, 0x11};

TBoss2DeRolLeMovement boss2_derolle_movement = {{225.0f, 0.0f, 0x600}, {0, 0, 0, 0}};

CollisionBody boss2_derolle_collision_bodies[3] = {
    {{0.0f, 0.0f, 0.0f}, 25.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
    {{0.0f, 0.0f, 0.0f}, 10.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f},
};

const char *bm_boss2_de_rol_le_model_names[8] = {
    "boss2_b_derorure_fin_b.nj",
    "boss2_b_derorure_fin_a.nj",
    "boss2_b_derorure_body.nj",
    "boss2_b_derorure_sting.nj",
    "boss2_b_derorure_tentacle.nj",
    "boss2_b_helm_break.nj",
    "boss2_b_shell_break.nj",
    NULL,
};

const char *bm_boss2_de_rol_le_motion_names[19] = {
    "beam02_boss2_b_body.njm",
    "beamwait_boss2_b_body.njm",
    "beam_a_boss2_b_body.njm",
    "beam_b_boss2_b_body.njm",
    "beam_c_boss2_b_body.njm",
    "bite_lloop_boss2_b_body.njm",
    "bite_rloop_boss2_b_body.njm",
    "die_boss2_b_body.njm",
    "enter_boss2_b_body.njm",
    "fd02_boss2_b_body.njm",
    "fjump_boss2_b_body.njm",
    "forward_boss2_b_body.njm",
    "lrjump_boss2_b_body.njm",
    "l_bite_boss2_b_body.njm",
    "rljump_boss2_b_body.njm",
    "r_bite_boss2_b_body.njm",
    "scatter_boss2_b_body.njm",
    "tloop_boss2_b_tentacle.njm",
    NULL,
};

BmlResourceDescriptor boss2_derolle_bml_descriptor = {
    "bm_boss2_de_rol_le.bml", bm_boss2_de_rol_le_model_names, bm_boss2_de_rol_le_motion_names, 7, 18,
};

TObjMotionAction boss2_derolle_action_table[17] = {
    {3, 0, 8, 0.8f, ACTION_NO_BLEND_IN | ACTION_NO_BLEND_OUT},
    {1, 0, 11, 0.6f, 0x0},
    {1, 0, 9, 1.0f, 0x0},
    {3, 0, 0, 0.4f, 0x0},
    {2, 1, 10, 0.3f, 0x0},
    {2, 1, 14, 0.5f, 0x0},
    {2, 1, 12, 0.5f, 0x0},
    {2, 9, 15, 0.28f, 0x0},
    {2, 10, 13, 0.28f, 0x0},
    {1, 0, 6, 2.0f, 0x0},
    {1, 0, 5, 2.0f, 0x0},
    {3, 0, 16, 0.6f, 0x0},
    {2, 15, 2, 0.4f, 0x0},
    {3, 0, 3, 0.3f, 0x0},
    {2, 1, 4, 0.4f, 0x0},
    {1, 0, 1, 0.5f, 0x0},
    {3, 0, 7, 0.7f, 0x0},
};

s32 boss2_derolle_particle_node_indices[3] = {0, 5, 9};

f32 boss2_derolle_particle_limits[3] = {32.0f, 30.0f, 30.0f};

const char *boss2_de_rol_le_class_name = "TBoss2DeRolLe";

#include <stddef.h>

struct Motion_8002EFE8 { s32 f0; s32 anim; s32 f8; s32 fC; };

struct Model_8002EFE8 { s32 f0; u32 frames; };

struct Anim_8002EFE8 { s32 f0; Model_8002EFE8 *model; };

struct Self_8002EFE8 {
    u8 pad0[0x24];
    s32 x24;
    u8 pad28[0x34 - 0x28];
    saddr x34;
    u8 pos[0xC];
    u8 pad44[0x5C - 0x44];
    s32 rotX;
    s32 rotY;
    s32 rotZ;
    u8 pad68[0xC0 - 0x68];
    f32 frame;
    u8 padC4[0xD8 - 0xC4];
    Motion_8002EFE8 *motions;
    Anim_8002EFE8 *anims;
    u8 padE0[0x354 - 0xE0];
    f32 motionIdx;
    f32 fixedFrame;
    f32 speed;
    u8 pad360[0x5E0 - 0x360];
    saddr joints[10];
};

extern "C" {

void *__ct__9TBoss2FinFv(void *, TObject *, Vec *, Vec *);

void *__ct__14TBoss2TentacleFP7TObjectll(void *, TObject *, GC_Mtx *, s32);

void fill_value_array(AreaAttackHistory *history);


void update_local_colliders_from_world(TObjEneDD *self, Vec *offsets);
extern f32 lbl_804FF5E8[];

void TObjPlayer__sub_8002E7C8(void);


f32 vec3_add_to(void *, void *);

void scale_matrix(int, f32, f32, f32);

void push_matrix(void);

void VecCopy__FP3VecPC3Vec(void *, void *);

void fn_8002F5AC(u8 *arg0);


s32 TObjLight__sub_801337F8(s32);


s32 rotate_matrix_z(int, int);

s32 rotate_matrix_x(int, int);

s32 scale_current_matrix(void *);

s32 post_translate_matrix(void *);

void draw_model_motion(void *arg0, void *arg1, f32 farg0);

void TObjPlayer__sub_8002F61C(NJS_OBJECT *);


extern saddr current_scene_light;

extern s32 saved_model_render_flags;

extern s32 model_render_flags;

void TObjPlayer__sub_8002EB88(void);

}

struct VBase_18_3a6650 { char pad[0x18]; };

struct VObj_18_3a6650 : VBase_18_3a6650 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
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
    virtual s32 m104();
};

struct Vec4_8002F258 { f32 x, y, z, w; };

struct Light_8002F258 { u8 pad0[0x24]; Vec4_8002F258 col; };

struct Ctx_8002F258 { u8 pad0[0x2C]; void *tex; };

struct Me_8002F258 : VObj_18_3a6650 {
    u8 pad1C[0x24 - 0x1C];
    s32 f24;
    u8 pad28[0x38 - 0x28];
    Vec pos;
    u8 pad44[0x5C - 0x44];
    s32 rx;
    s32 ry;
    s32 rz;
    u8 pad68[0x3C0 - 0x68];
    s32 flags;
    u8 pad3c4[0x3D8 - 0x3C4];
    u8 nodes[0x3F8 - 0x3D8];
    Vec pts[20];
    u8 pad4e8[0x540 - 0x4E8];
    Vec mids[10];
    u8 pad5b8[0x5E0 - 0x5B8];
    saddr joints[10];
    u8 pad608[0x6A4 - 0x608];
    f32 height;
};

extern "C" {


s32 TObjLight__sub_801336DC(s32);

s32 TObjLight__sub_8013379C(s32, void *);

void translate_matrix(uaddr arg0, f32 x, f32 y, f32 z);

extern u8 derolle_segment_texture_slots[];

extern Light_8002F258 TObjLight__scene_light_state;

extern s32 lbl_805D5564;

extern s32 saved_chunk_polygon_flags_and_mask;

extern s32 saved_chunk_polygon_flags_or_mask;

extern s32 chunk_polygon_flags_or_mask;

extern s32 chunk_polygon_flags_and_mask;

}

void get_current_matrix(void *m);

saddr TBoss2DeRolLe__base_params[1];
saddr TBoss2DeRolLe__resistance_params[1];
u8 *TBoss2DeRolLe__data_805D4BA0;
BmlResource *boss2_derolle_resource;
s32 TBoss2DeRolLe__current_attack_id;
s32 TBoss2DeRolLe__sequence_match_index;
s32 lbl_805D4BB0;
u8 *lbl_805D4BB4;
u8 *lbl_805D4BB8;
saddr lbl_805D4BBC;
saddr lbl_805D4BC0;
TBoss2DeRolLe *TBoss2DeRolLe__instance;
Ctx_8002F258 *derolle_texture_list_handle;
void *lbl_805D4BCC;

namespace joint_transform_view {

extern "C" {



s32 matrix_mult_vec_array(int, void *, void *, int);

s32 subtract_vector(void *, void *);

s32 push_matrix();

extern s32 TBoss2DeRolLe__current_attack_id;

extern s32 TBoss2DeRolLe__sequence_match_index;

extern s32 lbl_805D4BB0;

extern s32 lbl_805D4BB4;

extern saddr lbl_805D4BB8;

extern saddr lbl_805D4BBC;

extern saddr lbl_805D4BC0;

void TObjPlayer__sub_8002F61C(NJS_OBJECT *);

}

}

void *create_particle_controller_with_angles(void *arg0, void *arg1, s32 arg2, s32 arg3, u16 arg4);
namespace behavior_view {

struct Self_800310F8 {
    u8 pad0[0xB8];
    s16 fB8;
    u8 padBA[0x390 - 0xBA];
    u8 *f390;
    u8 pad394[0x3C0 - 0x394];
    s32 flags;
    u8 pad3C4[0x620 - 0x3C4];
    void *parts[4];
    u8 pad630[0x654 - 0x630];
    s32 dir;
    u8 pad658[0x6E0 - 0x658];
    s32 phase;
    s32 timer;
    s32 idx;
    s32 limit;
    s32 life;
};

struct DR_800327C8 {
    u8 pad0[0x38];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0xB8 - 0x44];
    s16 fB8;
    u8 padBA[0x3C0 - 0xBA];
    u32 flags;
    u8 pad3C4[0x654 - 0x3C4];
    s32 mode;
    s32 sub;
    u8 pad65C[0x67C - 0x65C];
    f32 ampX;
    u8 pad680[0x69C - 0x680];
    f32 ampZ;
    u8 pad6A0[0x6E0 - 0x6A0];
    s32 done;
    s32 kind;
    u8 pad6E8[0x6FC - 0x6E8];
    f32 baseX;
    f32 baseZ;
    f32 scaleX;
    f32 scaleZ;
};

struct VBase_18_8002F7C4 { char pad[0x18]; };

struct VObj_18_8002F7C4 : VBase_18_8002F7C4 {
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
    virtual void m72(s32);
};

struct Sub_8002F7C4 { u8 pad0[8]; u32 f8; };

struct Rol_8002F7C4 : VObj_18_8002F7C4 {
    u8 pad1C[0x30 - 0x1C];
    u32 flags30;
    u8 pad34[0x38 - 0x34];
    Vec pos;
    u8 pad44[0x5C - 0x44];
    s32 f5C;
    u8 pad60[0xB8 - 0x60];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3C0 - 0xC4];
    u32 f3C0;
    u8 pad3C4[0x3CC - 0x3C4];
    Sub_8002F7C4 *f3CC;
    u8 pad3D0[0x540 - 0x3D0];
    Vec pts[10];
    u8 pad5B8[0x5E0 - 0x5B8];
    s32 slots[10];
    u8 pad608[0x620 - 0x608];
    saddr tent[4];
    u8 pad630[0x654 - 0x630];
    s32 f654;
    u8 pad658[0x6A4 - 0x658];
    f32 f6A4;
    u8 pad6A8[4];
    s32 f6AC;
    u8 pad6B0[0x6E0 - 0x6B0];
    s32 f6E0;
    s32 f6E4;
    u8 pad6E8[0x6F4 - 0x6E8];
    s32 f6F4;
    u8 pad6F8[0x758 - 0x6F8];
    s32 f758;
};

struct Rol_80032E38 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x64 - 0x44];
    s32 f64;
    u8 pad68[0xB8 - 0x68];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3A0 - 0xC4];
    f32 f3A0;
    u8 pad3A4[0x3A8 - 0x3A4];
    f32 f3A8;
    f32 f3AC;
    u8 pad3B0[0x3C0 - 0x3B0];
    u32 f3C0;
    u8 pad3C4[0x654 - 0x3C4];
    s32 f654;
    u8 pad658[0x6A4 - 0x658];
    f32 f6A4;
    u8 pad6A8[0x6E0 - 0x6A8];
    s32 f6E0;
    s32 f6E4;
    s32 f6E8;
    u8 pad6EC[0x6FC - 0x6EC];
    f32 f6FC;
    u8 pad700[0x724 - 0x700];
    Vec f724;
};

struct D_800320B4 {
    u8 pad0[0x38];
    f32 x;
    f32 y;
    f32 z;
    u8 pad44[0xB0 - 0x44];
    u32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 frame;
    u8 padC4[0x3C0 - 0xC4];
    u32 flags;
    u8 pad3C4[0x518 - 0x3C4];
    u8 snd[0x540 - 0x518];
    Vec recs[10];
    u8 pad5B8[0x654 - 0x5B8];
    s32 mode;
    s32 next_mode;
    u8 pad65C[0x684 - 0x65C];
    u8 mover[0x694 - 0x684];
    f32 f694;
    u8 pad698[0x69C - 0x698];
    f32 f69C;
    u8 pad6A0[0x6A4 - 0x6A0];
    f32 f6A4;
    u8 pad6A8[0x6E0 - 0x6A8];
    s32 phase;
    s32 f6E4;
    s32 step;
    s32 tick;
    u8 pad6F0[0x6FC - 0x6F0];
    f32 dir;
    f32 f700;
    f32 f704;
    f32 vy;
    f32 vx;
    f32 ay;
};

struct Sub_800313F8 { u8 pad0[8]; u32 f8; };

struct DR_800313F8 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0x64 - 0x44];
    s32 f64;
    u8 pad68[0xB0 - 0x68];
    u32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3C0 - 0xC4];
    u32 f3C0;
    u8 pad3C4[0x3CC - 0x3C4];
    Sub_800313F8 *f3CC;
    u8 pad3D0[0x44C - 0x3D0];
    Vec v44C;
    Vec v458;
    u8 pad464[0x4E8 - 0x464];
    Vec v4E8;
    u8 pad4F4[0x518 - 0x4F4];
    u8 snd[0x620 - 0x518];
    saddr tentacles[4];
    u8 pad630[0x654 - 0x630];
    s32 f654;
    u8 pad658[0x6A4 - 0x658];
    f32 f6A4;
    u8 pad6A8[0x6E0 - 0x6A8];
    s32 f6E0;
    s32 f6E4;
    s32 f6E8;
    s32 f6EC;
    u8 pad6F0[0x6FC - 0x6F0];
    f32 f6FC;
    f32 f700;
    f32 f704;
    f32 f708;
    f32 f70C;
    f32 f710;
    f32 f714;
    f32 f718;
    u8 pad71C[0x73C - 0x71C];
    void *f73C;
};

struct D_8002FE60 {
    u8 pad0[0xB8];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 frame;
    u8 padC4[0x390 - 0xC4];
    u8 *target;
    u8 pad394[0x3C0 - 0x394];
    u32 flags;
    u8 pad3C4[0x4E8 - 0x3C4];
    Vec pos;
    Vec dir;
    u8 pad500[0x518 - 0x500];
    u8 snd[0x654 - 0x518];
    s32 mode;
    u8 pad658[0x6C8 - 0x658];
    s32 f6C8;
    void *laser1;
    void *laser2;
    u8 pad6D4[0x6DC - 0x6D4];
    s32 count;
    s32 phase;
    s32 timer;
    s32 f6E8;
    u8 pad6EC[0x6F4 - 0x6EC];
    s32 f6F4;
    u8 pad6F8[0x6FC - 0x6F8];
    f32 speed;
    f32 f700;
    u8 pad704[0x724 - 0x704];
    Vec vel;
    Vec hit;
    void *ptcl;
    u8 pad740[0x758 - 0x740];
    s32 f758;
};

extern "C" {









s32 VecCopy__FP3VecPC3Vec(int, void *);







s32 VecCopy__FP3VecPC3Vec(int, void *);


int play_sound(void* p, int a1);



void TBoss2DeRolLe__sub_800313F8(DR_800313F8 *o, u32 arg1, s32 arg2);

s32 VecCopy__FP3VecPC3Vec(int, void *);



void fill_value_array(saddr);

int spawn_trap__13TBoss2DeRolLeFPvii(void* p, int a1, int a2);

int play_sound(void* p, int a1);





u8 *csnVector(void *, void *, int);


s32 vec3_add_to(int, void *);

void subtract_vector(void *, void *);

extern u8 *TBoss2DeRolLe__data_805D4BA0;

void TBoss2DeRolLe__sub_8002FE60(void *arg0, u32 arg1);






s32 VecCopy__FP3VecPC3Vec(int, void *);

void set_move_direction__13TBoss2DeRolLeFPv(void *, s32);


s32 TBoss2Tentacle__sub_80039CA0(void *);


extern u8 *TBoss2DeRolLe__data_805D4BA0;

void TBoss2DeRolLe__sub_800310F8(void *arg0, void *arg1, int arg2);


void TBoss2DeRolLe__sub_800327C8(void *arg0, void *arg1, int arg2, int arg3);

void assign_slots_from_list(void *, saddr);


s32 VecCopy__FP3VecPC3Vec(int, void *);



s32 restore_player_cameras();

s32 activate_camera_mode(int);

void set_scripted_camera_pose(void *, void *, void *);


int play_sound_effect(void*, int, int, int);

void play_cue_stream_file(saddr name);

void handle_death_state__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);

s32 VecCopy__FP3VecPC3Vec(int, void *);

s32 activate_camera_mode(int);

void get_node_world_pos__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1);

s32 vec3_add_to(int, void *);



int play_sound_effect(void*, int, int, int);


CameraPlayback *get_scripted_camera_playback(void);

s32 restore_player_cameras();

void TBoss2DeRolLe__sub_80032E38(void *arg0, void *arg1);


s32 VecCopy__FP3VecPC3Vec(int, void *);


int play_sound(void* p, int a1);


f32 calc_node_height__13TBoss2DeRolLeFPv(void *);

s32 advance_scalar_motion_profile(void *);


void TBoss2DeRolLe__sub_800320B4(void *arg0, void *arg1, int arg2, int arg3);



s32 VecCopy__FP3VecPC3Vec(int, void *);







void TBoss2DeRolLe__sub_80030A38(u8 *arg0, u32 arg1);

void TBoss2DeRolLe__sub_80030DFC(void *, void *, int);

void TBoss2DeRolLe__sub_80031AD4(void *, void *);

void handle_debug_pad_input__13TBoss2DeRolLeFPvPv(void *, void *);

void dispatch_action__13TBoss2DeRolLeFiUii(saddr arg0, u32 arg1, saddr arg2);


int spawn_trap__13TBoss2DeRolLeFPvii(void* p, int a1, int a2);

int play_sound(void* p, int a1);






void reset_fields_3d0__13TBoss2DeRolLeFPv(void* p);

void set_params__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);

void init_from_param__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);

void handle_6x14_de_rol_le_boss_actions_with_target(void *arg0);

void handle_6x13_de_rol_le_boss_actions(void *arg0);

void clear_play_flags__13TBoss2DeRolLeFv(void *arg0);



void update_check__13TBoss2DeRolLeFPv(void *arg0);

void swap_endian__13TBoss2DeRolLeFPv(void *);

void swap_6x13_fields__13TBoss2DeRolLeFPv(void *);



s32 enemy_set_target_id(void * a0 = 0, u16 a1 = 0);

void project_sound_origin_from_camera(saddr arg0, u8 *arg1, f32 farg0);




u8 *get_enemy_entity(u16 arg0);

s32 play_persistent_sound(s32 id, saddr a1, uaddr src, s32 a3, s32 flags);

int play_sound_effect(void*, int, int, int);

s32 vec3_add_to(int, void *);

extern Vec TBoss2DeRolLe__mine_ground_targets[];





extern int fold_flush_0;

struct Rol_80031AD4 {
    u8 pad0[0x38];
    Vec pos;
    u8 pad44[0xB0 - 0x44];
    s32 fB0;
    u8 padB4[0xB8 - 0xB4];
    s16 fB8;
    u8 padBA[0xC0 - 0xBA];
    f32 fC0;
    u8 padC4[0x3C0 - 0xC4];
    u32 f3C0;
    u8 pad3C4[0x518 - 0x3C4];
    u8 f518[0x654 - 0x518];
    s32 f654;
    u8 pad658[0x684 - 0x658];
    u8 f684[0x69C - 0x684];
    f32 f69C;
    u8 pad6A0[0x6A4 - 0x6A0];
    f32 f6A4;
    u8 pad6A8[0x6E0 - 0x6A8];
    s32 f6E0;
    s32 f6E4;
    s32 f6E8;
    s32 f6EC;
    u8 pad6F0[0x6FC - 0x6F0];
    f32 f6FC;
    f32 f700;
    f32 f704;
    f32 f708;
};

extern "C" {

s32 VecCopy__FP3VecPC3Vec(int, void *);

f32 calc_node_height__13TBoss2DeRolLeFPv(void *);

s32 advance_scalar_motion_profile(void *);




int play_sound(void* p, int a1);

}

struct Pad_80032B28 { u8 pad[8]; u32 buttons; };

extern int fold_flush_1;

extern int fold_flush_2;

s32 advance_scalar_motion_profile(void *);



s32 advance_scalar_motion_profile(void *);





s32 advance_scalar_motion_profile(void *);







s32 advance_scalar_motion_profile(void *);



}

}

void compose_motion_node_matrix(void *arg0);
void compose_motion_node_matrix(void *arg0);
namespace joint_state_view {

struct VBase18 { char pad[0x18]; };

struct VObj18 : VBase18 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(void *, f32);
};

struct RecoveredFields_80034C2C_arg0 {
    u8 unknown_0[0x3AC];
    f32 field_3AC;
};

struct Obj_80034B60 { u8 pad0[0x34]; saddr f34; u8 pad1[0xC0 - 0x38]; f32 fC0; u8 pad2[0xF8 - 0xC4]; saddr fF8; };




extern "C" {

f32 TBoss2DeRolLe__sub_80034CEC(void);

f32 TBoss2DeRolLe__sub_80034CF8(void);

extern u8 *TBoss2DeRolLe__instance;

void forward_switch_phase_stats__13TBoss2DeRolLeFi(saddr arg0);

void switch_phase_stats__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1);

s32 VecCopy__FP3VecPC3Vec(s32, s32);

void update_colliders_from_offsets__13TBoss2DeRolLeFi(s32 arg0);

int play_sound(void *, int);



void run_hit_reaction__13TBoss2DeRolLeFv(TBoss2DeRolLe *arg0);

s32 VecCopy__FP3VecPC3Vec(s32, s32);

s32 VecCopy__FP3VecPC3Vec(s32, s32);

f32 subtract_vector(void *, void *);

s32 matrix_mult_vec(int, void *, void *);

s32 set_matrix_identity(int);

s32 push_matrix();

void get_node_world_pos__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1);

s32 matrix_mult_vec(int, void *, void *);

s32 scale_matrix(int, f32, f32, f32);

extern u8 identity_matrix[];

f32 calc_node_height__13TBoss2DeRolLeFPv(Obj_80034B60 *self);


extern s32 TBoss2DeRolLe__attack_params_table[];

extern saddr TBoss2DeRolLe__base_params[1];

extern saddr TBoss2DeRolLe__resistance_params[1];

void send_6x13__13TBoss2DeRolLeFPv(void *p);

void TBoss2DeRolLe__sub_80036358(void *p);

void update_and_send__13TBoss2DeRolLeFPv(void *p);

void TBoss2DeRolLe__sub_800363A0(void *p);

void run_miss_reaction__13TBoss2DeRolLeFv(void);

s32 TBoss2Joint_get_shell_max_hp(void);

void backup_pos__13TBoss2DeRolLeFi(s32 arg0);

void emit_effect_and_step__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1);

void set_move_direction__13TBoss2DeRolLeFPv(void *arg0);

s32 VecCopy__FP3VecPC3Vec(s32, s32);


extern u8 *TBoss2DeRolLe__data_805D4BA0;

LAYOUT_ASSERT(RecoveredFields_80034C2C_arg0_3AC_offset, offsetof(RecoveredFields_80034C2C_arg0, field_3AC) == 0x3AC);

}

}

namespace lifecycle_view {

typedef struct Slot_80035D24 {
    s32 kind;
    s32 f04;
    f32 f08[3];
    s32 f14;
    s32 f18;
    s32 f1C;
    f32 f20[3];
    struct Slot_80035D24 *next;
    s32 f30;
    s32 f34;
} Slot_80035D24;

typedef struct Node_80035D24 {
    u8 pad0[4];
    struct { u8 pad[4]; s32 v; } *h;
    u8 pad8[0x2C - 8];
    struct Node_80035D24 *sub;
    struct Node_80035D24 *next;
} Node_80035D24;

extern "C" {

void VecCopy__FP3VecPC3Vec(void *, void *);


void TBoss2DeRolLe__sub_800360A8(void *arg0);




void backup_pos__13TBoss2DeRolLeFi(s32 arg0);





void run_task__13TBoss2DeRolLeFPv(u8 *arg0);

s32 __dt__7TObjectFv(void *, int);


void *__dt__12TObjEneDD_STFv(void *arg0, s16 arg1);

s32 __dt__17AreaAttackHistoryFv(s32 arg0, s16 arg1);


s32 free_collision_body_parts(void *);

s32 __dl__7TObjectFPv(void *);

extern s32 TBoss2DeRolLe__instance;

u8 *__dt__13TBoss2DeRolLeFv(u8 *arg0, s16 arg1);

void VecCopy__FP3VecPC3Vec(void *, void *);


s32 TObjLight__sub_801337F8(s32);

s32 scale_matrix(int, f32, f32, f32);

f32 vector_length(void *);

void translate_matrix_vec3(u8 *arg0, u8 *arg1);

s32 subtract_vector(void *, void *);

s32 rotate_matrix_x(int, int);


s32 push_matrix();


extern saddr current_scene_light;





void TObjPlayer__sub_8002E7C8(void);







extern saddr TBoss2DeRolLe__base_params[1];

extern saddr TBoss2DeRolLe__resistance_params[1];

extern s32 TBoss2DeRolLe__data_805D4BA0[1];


extern s32 TBoss2DeRolLe__current_attack_id;

extern s32 TBoss2DeRolLe__sequence_match_index;

extern s32 lbl_805D4BB0;

extern s32 lbl_805D4BB4;

extern saddr lbl_805D4BB8;

extern saddr lbl_805D4BBC;

extern saddr lbl_805D4BC0;

extern s32 TBoss2DeRolLe__instance;

extern u8 *derolle_texture_list_handle;

extern s32 lbl_805D4BCC;

void load_resources__13TBoss2DeRolLeFv(void);

s32 advance_scalar_motion_profile(void *arg0);

void run_death_reaction__13TBoss2DeRolLeFv(void);

void refresh_target__13TBoss2DeRolLeFv(void);

void apply_poison_status__13TBoss2DeRolLeFv(void);

void apply_paralysis__13TBoss2DeRolLeFv(void);

void apply_slow_status__13TBoss2DeRolLeFv(void);

void apply_confusion_status__13TBoss2DeRolLeFv(void);

void apply_movement_ailment__13TBoss2DeRolLeFl(void);

void apply_shock_status__13TBoss2DeRolLeFv(void);

void clear_harmful_statuses__13TBoss2DeRolLeFv(void);

void TBoss2DeRolLe__sub_80036358(void* p);

void TBoss2DeRolLe__sub_800363A0(void* p);

void *create__13TBoss2DeRolLeFPv(void *arg0);

void reset_parts__13TBoss2DeRolLeFv(void);

void send_6x13__13TBoss2DeRolLeFPv(void* p);

void swap_6x13_fields__13TBoss2DeRolLeFPv(void* p);

void swap_endian__13TBoss2DeRolLeFPv(void* p);

void update_and_send__13TBoss2DeRolLeFPv(void* p);

void *TBoss2DeRolLe__ct(void *, void *, void *);





void TObjPlayer__sub_8002EB88(void);

void __dl__FPv(void);


int bswap_16__FPUs(void*);

int bswap_32__FPUl(void*);


}

}

Vec TBoss2DeRolLe__mine_ground_targets[5];

u32 *boss2_derolle_primary_color_targets[3];

u32 derolle_segment_joint_node_offsets[10];

u32 *boss2_derolle_segment_color_targets[10];

u32 TBoss2DeRolLe__attack_params_table[3];

namespace lifecycle_view {

extern "C" {

extern void *tl_04;






u32 lbl_804FE30C[4];

u32 lbl_804FE31C[3];

Slot_80035D24 derolle_segment_texture_slots[11];

extern s32 TBoss2DeRolLe__instance;

void TBoss2DeRolLe__sub_800363A0(void* p) { *(u8*)((char*)p + 0x0) = 20; *(u8*)((char*)p + 0x1) = 3; }

void update_and_send__13TBoss2DeRolLeFPv(void* p) { swap_endian__13TBoss2DeRolLeFPv(p); send_subcommand(p); }

void TBoss2DeRolLe__sub_80036358(void* p) { *(u8*)((char*)p + 0x0) = 19; *(u8*)((char*)p + 0x1) = 2; }

void send_6x13__13TBoss2DeRolLeFPv(void* p) { swap_6x13_fields__13TBoss2DeRolLeFPv(p); send_subcommand(p); }

void swap_6x13_fields__13TBoss2DeRolLeFPv(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16__FPUs((char*)p + 0x4); bswap_16__FPUs((char*)p + 0x6); }

void swap_endian__13TBoss2DeRolLeFPv(void* p) { ((G_ClientIDHeader *)p)->bswap(); bswap_16__FPUs((char*)p + 0x4); bswap_16__FPUs((char*)p + 0x6); bswap_32__FPUl((char*)p + 0x8); }

void TBoss2DeRolLe::clear_harmful_statuses() {  }

void TBoss2DeRolLe::apply_shock_status() {  }

void TBoss2DeRolLe::apply_movement_ailment(s32) {  }

void TBoss2DeRolLe::apply_confusion_status() {  }

void TBoss2DeRolLe::apply_slow_status() {  }

void TBoss2DeRolLe::apply_paralysis() {  }

void TBoss2DeRolLe::apply_poison_status() {  }

TBoss2DeRolLe *TBoss2DeRolLe::get_instance() {
    return (TBoss2DeRolLe *)TBoss2DeRolLe__instance;
}

}

}

TUnk_80036250::TUnk_80036250() {
    init_float_block();
}

TUnk_80036250::~TUnk_80036250() {}

void TUnk_80036250::init_float_block() {
    state = 0;
    accel = 0.0f;
    decel = 0.0f;
    max_speed = 0.0f;
    speed = 0.0f;
    distance = 0.0f;
    travelled = 0.0f;
    brake_point = 0.0f;
}

void TUnk_80036250::init_params(f32 max_speed, f32 distance, f32 accel) {
    state = 0;
    this->accel = accel;
    decel = accel;
    this->max_speed = max_speed;
    speed = 0.0f;
    this->distance = distance;
    travelled = 0.0f;
    TBoss2DeRolLe__sub_800360A8(this);
}

void TUnk_80036250::set_move_params(f32 max_speed, f32 distance, f32 accel, f32 decel) {
    state = 0;
    this->accel = accel;
    this->decel = decel;
    this->max_speed = max_speed;
    speed = 0.0f;
    this->distance = distance;
    travelled = 0.0f;
    TBoss2DeRolLe__sub_800360A8(this);
}

namespace lifecycle_view {

extern "C" {

void TBoss2DeRolLe__sub_800360A8(void *arg0) {
  s8 *new_var;
  s8 *new_var2;
  f32 temp_f0;
  f32 temp_f1;
  f32 temp_f31;
  f32 temp_f3;
  f32 temp_f4;
  f32 temp_f5;
  new_var = ((s8 *) arg0) + 0xC;
  temp_f4 = *((f32 *) (((s8 *) arg0) + 0x10));
  temp_f31 = -(*((f32 *) (((s8 *) arg0) + 8)));
  temp_f5 = temp_f4 * temp_f4;
  temp_f3 = (1.0f / (*((f32 *) (((s8 *) arg0) + 4)))) - (1.0f / temp_f31);
  new_var2 = ((s8 *) arg0) + 0x1C;
  temp_f1 = (*((f32 *) (((s8 *) arg0) + 0x14))) + (temp_f5 / (-2.0f * temp_f31));
  if ((((1.0f / (*((f32 *) (((s8 *) arg0) + 4)))) - (1.0f / temp_f31)) * (0.5f * temp_f5)) > temp_f1)
  {
    *((f32 *) new_var) = newton_sqrtf((2.0f * temp_f1) / temp_f3);
    temp_f3 = (1.0f / (*((f32 *) (((s8 *) arg0) + 4)))) - (1.0f / temp_f31);
  }
  temp_f0 = *((f32 *) new_var);
  *((f32 *) new_var2) = (f32) ((*((f32 *) (((s8 *) arg0) + 0x14))) + ((0.5f * (temp_f0 * temp_f0)) / temp_f31));
}

s32 advance_scalar_motion_profile(void *arg0) {
    f32 temp_f1;
    f32 temp_f1_2;
    switch (*(s32 *)((s8 *)arg0 + 0)) {
    case 0:
        *(f32 *)((s8 *)arg0 + 0x10) = (f32) (*(f32 *)((s8 *)arg0 + 0x10) + *(f32 *)((s8 *)arg0 + 4));
        if (*(f32 *)((s8 *)arg0 + 0x10) > *(f32 *)((s8 *)arg0 + 0xC)) {
            *(f32 *)((s8 *)arg0 + 0x10) = *(f32 *)((s8 *)arg0 + 0xC);
            *(s32 *)((s8 *)arg0 + 0) = 1;
        }
        break;
    case 1:
        if (*(f32 *)((s8 *)arg0 + 0x18) > *(f32 *)((s8 *)arg0 + 0x1C)) {
            *(f32 *)((s8 *)arg0 + 0x10) = (f32) (*(f32 *)((s8 *)arg0 + 0x10) - *(f32 *)((s8 *)arg0 + 8));
            *(s32 *)((s8 *)arg0 + 0) = 2;
        }
        break;
    case 2:
        *(f32 *)((s8 *)arg0 + 0x10) = (f32) (*(f32 *)((s8 *)arg0 + 0x10) - *(f32 *)((s8 *)arg0 + 8));
        if (*(f32 *)((s8 *)arg0 + 0x10) < 0.0f) {
            *(f32 *)((s8 *)arg0 + 0x10) = 0.0f;
            *(s32 *)((s8 *)arg0 + 0) = 3;
        }
        break;
    }
    *(f32 *)((s8 *)arg0 + 0x18) = (f32) (*(f32 *)((s8 *)arg0 + 0x18) + *(f32 *)((s8 *)arg0 + 0x10));
    if (*(f32 *)((s8 *)arg0 + 0x18) > *(f32 *)((s8 *)arg0 + 0x14)) {
        *(f32 *)((s8 *)arg0 + 0x18) = *(f32 *)((s8 *)arg0 + 0x14);
    }
    return *(s32 *)((s8 *)arg0 + 0);
}

void load_resources__13TBoss2DeRolLeFv(void) {
    s32 k;
    s32 m2;
    s32 m3;
    u8 *res;
    s32 i;
    Node_80035D24 *n;
    Node_80035D24 *m;
    Slot_80035D24 *p;
    if (TObjEneDD::check_v2_mode() != 0) {
        res = (u8 *)load_enemy_bml_resource_named(&boss2_derolle_bml_descriptor, "bm_boss2_de_rol_le_a.bml");
    } else {
        res = (u8 *)load_enemy_bml_resource(&boss2_derolle_bml_descriptor);
    }
    boss2_derolle_resource = (BmlResource *)res;
    TBoss2DeRolLe__current_attack_id = 0;
    TBoss2DeRolLe__sequence_match_index = 0;
    lbl_805D4BB0 = 0;
    ((f32 *)lbl_804FE30C)[0] = 0.0f;
    ((f32 *)lbl_804FE30C)[1] = 0.0f;
    ((f32 *)lbl_804FE30C)[2] = 0.0f;
    ((f32 *)lbl_804FE30C)[3] = 0.0f;
    ((f32 *)lbl_804FE31C)[0] = 0.0f;
    ((f32 *)lbl_804FE31C)[1] = 0.0f;
    ((f32 *)lbl_804FE31C)[2] = 0.0f;
    lbl_805D4BB4 = 0;
    lbl_805D4BB8 = 0;
    lbl_805D4BBC = 0;
    lbl_805D4BC0 = 0;
    for (i = 0; i < 1; i++) {
        TBoss2DeRolLe__base_params[i] = (saddr)TLobby::register_boss(de_rol_le_base_param_ids[i]);
    }
    for (i = 0; i < 3; i++) {
        ((s32 *)TBoss2DeRolLe__attack_params_table)[i] = (saddr)TLobby::dispatch_shared_handler_b(TBoss2DeRolLe__shared_handler_id_table[i]);
    }
    for (i = 0; i < 1; i++) {
        TBoss2DeRolLe__resistance_params[i] = (saddr)TLobby::register_object(de_rol_le_resistance_param_ids[i]);
    }
    for (i = 0; i < 1; i++) {
        TBoss2DeRolLe__data_805D4BA0[i] = (saddr)TLobby::dispatch_shared_handler_a(de_rol_le_shared_handler_a_ids[i]);
    }
    TBoss2DeRolLe__instance = 0;
    TBoss2Tentacle::load_shared_model();
    TBoss2Mine::load_resources();
    for (k = 0; k < 5; k++) {
        TObjBoss2Tunnel::adjust_to_ground((saddr)&derolle_mine_offsets[k], (u8 *)TBoss2DeRolLe__mine_ground_targets + k * 0xC);
    }
    TBoss2Fin::init_effect_table();
    res = (u8 *)boss2_derolle_resource;
    n = *(Node_80035D24 **)(*(u8 **)(*(u8 **)(res + 0x42C) + 0x28) + 0x2C);
    for (i = 0; i < 10; i++) {
        ((s32 *)derolle_segment_joint_node_offsets)[i] = n->h->v + 8;
        boss2_derolle_segment_color_targets[i] = (u32 *)(n->sub->h->v + 8);
        n = n->next;
    }
    boss2_derolle_primary_color_targets[0] = (u32 *)(n->h->v + 8);
    m = n->next;
    boss2_derolle_primary_color_targets[1] = (u32 *)(m->h->v + 8);
    boss2_derolle_primary_color_targets[2] = (u32 *)(m->next->h->v + 8);
    derolle_texture_list_handle = (u8 *)find_model_node(*(s32 *)(*(u8 **)(res + 0x42C) + 0x28), 0x4D);
    lbl_805D4BCC = *(s32 *)(derolle_texture_list_handle + 0x2C);
    for (m2 = 0; m2 < 11; m2++) {
        p = &derolle_segment_texture_slots[m2];
        p->kind = 0xF;
        p->f04 = 0;
        p->f08[0] = 0.0f;
        p->f08[1] = 0.0f;
        p->f08[2] = 0.0f;
        p->f14 = 0;
        p->f18 = 0;
        p->f1C = 0;
        p->f20[0] = 0.0f;
        p->f20[1] = 0.0f;
        p->f20[2] = 0.0f;
        p->next = 0;
        p->f30 = 0;
    }
    for (m3 = 0; m3 < 10; m3++) {
        derolle_segment_texture_slots[m3].next = &derolle_segment_texture_slots[m3 + 1];
    }
    p = &derolle_segment_texture_slots[10];
    p->kind = 0x1F;
    p->next = 0;
    TObjPlayer::create_breakup_model();
    TObjPlayer__sub_8002E7C8();
    TWindowCtrl::init_all_slots();
}

void *TBoss2DeRolLe::create(void *set_data) {
    return new TBoss2DeRolLe(tl_04, set_data);
}

void reset_parts__13TBoss2DeRolLeFv(void) {
    TObjPlayer::clear_target_ref();
    TObjPlayer__sub_8002EB88();
    TBoss2Fin::release_effect_table();
    TBoss2Mine::free_resources();
    TBoss2Tentacle::release_shared_model();
    if (boss2_derolle_resource != NULL) {
        delete boss2_derolle_resource;
        boss2_derolle_resource = NULL;
    }
}

}

}

#pragma push
#pragma opt_common_subs off
#pragma opt_loop_invariants off
#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

TBoss2DeRolLe::TBoss2DeRolLe(TObject *parent, void *set_data) : TObjEneDD_ST(parent), part_group(NULL) {
    u16 id;
    s32 set;
    s32 i;
    s32 j;
    s32 k;
    s32 m;

    m_name = boss2_de_rol_le_class_name;
    if (TBoss2DeRolLe__instance == NULL) {
        TBoss2DeRolLe__instance = this;
    }
    invoke_initialization_hook(set_data);
    state_flags = 0;
    {
        // exchange_object_state copies the object's whole 12-byte lobby record
        u32 flags[3];
        if (exchange_object_state(flags, 1) != 0 && (flags[0] & 0x12008) == 0x12008) {
            state_flags |= 0x8000;
        }
    }
    init_position_vectors();
    model = boss2_derolle_resource->models[2].model;
    texlist = (saddr)boss2_derolle_resource->models[2].m_c;
    init_model(boss2_derolle_collision_bodies, 3);
    motion_flags = 0;
    set_field_d8((saddr)boss2_derolle_action_table);
    set_field_dc((saddr)boss2_derolle_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    reset_hp((u8 *)TBoss2DeRolLe__base_params[0], (u8 *)TBoss2DeRolLe__attack_params_table[0], (u8 *)TBoss2DeRolLe__resistance_params[0]);
    set_state_flag_2();
    movementParameters = &boss2_derolle_movement;
    initialize_enemy_state(0x2D);
    wall_reach = 20.0f;
    enemy_init_acquire_period(30);
    enemy_init_validate_period(30);
    unk_3C4 = 0;
    unk_3D0 = 0;
    unk_3D4 = 0;
    for (i = 0; i < 20; i++) {
        unk_3F8[i].x = 0.0f;
        unk_3F8[i].y = 0.0f;
        unk_3F8[i].z = 0.0f;
    }
    for (i = 0; i < 4; i++) {
        unk_4E8[i].x = 0.0f;
        unk_4E8[i].y = 0.0f;
        unk_4E8[i].z = 0.0f;
    }
    tentacle_matrices = (GC_Mtx *)mem_alloc(4 * sizeof(GC_Mtx));
    for (i = 0; i < 4; i++) {
        set_matrix_identity((u8 *)tentacle_matrices[i]);
        void *p = TObject::operator new(0x158);
        if (p != NULL) {
            p = __ct__14TBoss2TentacleFP7TObjectll(p, &part_group, &tentacle_matrices[i], i);
        }
        tentacles[i] = (TBoss2Tentacle *)p;
    }
    Vec v = {10000.0f, 10000.0f, 10000.0f};
    id = entity_id + 1;
    set = set_index + 1;
    for (j = 0; j < 10; j++) {
        VecCopy(&joint_positions[j], &v);
        unk_5B8[j] = -1;
        joints[j] = new TBoss2Joint(this, id++, set++, &joint_positions[j], derolle_segment_joint_node_offsets[j], (s32)boss2_derolle_segment_color_targets[j]);
    }
    for (i = 0; i < 5; i++) {
        mines[i] = new TUnk_80482EC0(&part_group, id++, set++);
    }
    for (i = 0; i < 3; i++) {
        target_mines[i] = new TUnk_80482D04(&part_group, id++, set++);
    }
    {
        void *p = TObject::operator new(0x88);
        if (p != NULL) {
            p = __ct__9TBoss2FinFv(p, &part_group, &unk_3F8[1], &unk_3F8[10]);
        }
        fin = (TBoss2Fin *)p;
    }
    position_index = 0;
    unk_658 = 0;
    unk_65C = 0;
    unk_660 = 0;
    unk_664.init_float_block();
    unk_684.init_float_block();
    unk_6A4 = 0.0f;
    unk_6A8 = unk_6AC = *(s32 *)(TBoss2DeRolLe__data_805D4BA0 + 0x18);
    unk_6B0 = *(s32 *)(TBoss2DeRolLe__data_805D4BA0 + 0x20);
    hpmax = hp = 20000;
    photon_pad_level = 0;
    laser_light = new TBoss2LaserLight(&part_group, &laser_light_pos);
    laser_light_pos.x = 0.0f;
    laser_light_pos.y = 0.0f;
    laser_light_pos.z = 0.0f;
    attack_history = new AreaAttackHistory(4);
    fill_value_array(attack_history);
    unk_6CC = NULL;
    unk_6D0 = NULL;
    pulse_phase = 1.0f;
    pulse_speed = 0.1f;
    for (k = 0; k < 3; k++) {
        VecCopy(&unk_518[k], &position);
    }
    unk_53C = 0;
    unk_608[0] = 1.0f;
    unk_608[1] = 1.0f;
    unk_608[2] = 1.0f;
    unk_608[3] = 1.0f;
    unk_618 = (GC_Mtx *)mem_alloc(12 * sizeof(GC_Mtx));
    for (i = 0; i < 12; i++) {
        set_matrix_identity((u8 *)unk_618[i]);
    }
    for (m = 0; m < 6; m++) {
        splash_ctrls[m] = NULL;
    }
    splash_joint = 0;
    unk_6DC = 0;
    unk_6E0 = 0;
    unk_6E4 = 0;
    unk_6E8 = 0;
    unk_6EC = 0;
    unk_6F0 = 0;
    unk_6F4 = 0;
    unk_6F8 = 0;
    unk_6FC[0] = 0.0f;
    unk_6FC[1] = 0.0f;
    unk_6FC[2] = 0.0f;
    unk_6FC[3] = 0.0f;
    unk_6FC[4] = 0.0f;
    unk_6FC[5] = 0.0f;
    unk_6FC[6] = 0.0f;
    unk_6FC[7] = 0.0f;
    unk_6FC[8] = 0.0f;
    unk_6FC[9] = 0.0f;
    unk_6FC[10] = 0.0f;
    unk_6FC[11] = 0.0f;
    unk_6FC[12] = 0.0f;
    unk_6FC[13] = 0.0f;
    unk_6FC[14] = 0.0f;
    unk_6FC[15] = 0.0f;
    unk_73C = NULL;
    debug_pad_active = 0;
    debug_pad = &controller_input_state.controllers[1];
    if (TObjEneDD::is_main_phase_15() != 0) {
        if (update_lobby_state() != 0) {
            unk_3F4 = 0;
        } else {
            unk_3F4 = 1;
        }
    } else {
        unk_3F4 = 0;
    }
    reset_fields_3d0(this);
    if (!(state_flags & 0x8000)) {
        mode = 1;
        dispatch_action(mode, 4);
    }
}

#pragma pop

TBoss2DeRolLe::~TBoss2DeRolLe() {
    s32 i;
    if (unk_73C != NULL) {
        unk_73C->queue_destruction();
        unk_73C = NULL;
    }
    for (i = 0; i < 6; i++) {
        if (splash_ctrls[i] != NULL) {
            splash_ctrls[i]->queue_destruction();
            splash_ctrls[i] = NULL;
        }
    }
    mem_free(unk_618);
    unk_618 = NULL;
    if (unk_6CC != NULL) {
        unk_6CC->queue_destruction();
        unk_6CC = NULL;
    }
    if (unk_6D0 != NULL) {
        unk_6D0->queue_destruction();
        unk_6D0 = NULL;
    }
    if (attack_history != NULL) {
        delete attack_history;
        attack_history = NULL;
    }
    if (laser_light != NULL) {
        laser_light->queue_destruction();
        laser_light = NULL;
    }
    if (fin != NULL) {
        fin->queue_destruction();
        fin = NULL;
    }
    for (i = 2; i >= 0; i--) {
        target_mines[i]->queue_destruction();
        target_mines[i] = NULL;
    }
    for (i = 4; i >= 0; i--) {
        mines[i]->queue_destruction();
        mines[i] = NULL;
    }
    for (i = 9; i >= 0; i--) {
        joints[i]->queue_destruction();
        joints[i] = NULL;
    }
    for (i = 3; i >= 0; i--) {
        tentacles[i]->queue_destruction();
        tentacles[i] = NULL;
    }
    mem_free(tentacle_matrices);
    free_collision_body_parts(this);
    if (TBoss2DeRolLe__instance == this) {
        TBoss2DeRolLe__instance = NULL;
    }
}

namespace lifecycle_view {

extern "C" {

void TBoss2DeRolLe::run_task() {
  s32 teammate_state;
  s32 flags;
  if (get_target_info() != 0)
  {
    vfunc_105();
    return;
  }
  flags = state_flags;
  if (flags & 0x8000)
  {
    send_entity_set_flags();
    queue_destruction();
    return;
  }
  if (flags & 0x80)
  {
    state_flags = flags & ~0x80;
    state_flags |= 0x40;
    new TUnk_80482090(this, (u32)unk_618);
  }
  if ((TObjEneDD::is_main_phase_15() != 0) && (debug_pad_active == 0))
  {
    if (update_lobby_state() != 0)
    {
      unk_3F4 = 0;
    }
    else
    {
      unk_3F4 = 1;
    }
  }
  if ((debug_pad_active != 0) && (debug_pad->unknown_08 & 0x10000))
  {
    switch (unk_3F4)
    {
      case 1:
        unk_3F4 = 0;
        advance_action_sequence();
        break;
      case 0:
        unk_3F4 = 2;
        break;
      case 2:
        unk_3F4 = 1;
        break;
    }
  }
  teammate_state = TObjEneDD::query_teammate_state();
  update_attack_stat_status();
  update_defense_stat_status();
  if (teammate_state == 0)
  {
    if (mode == 0x1F || mode == 0x20 || mode == 0x1E)
    {
      actorFlags |= 0x800;
    }
    else
    {
      actorFlags &= ~0x800;
    }
    if (unk_3F4 != 1)
    {
      if (unk_3F4 == 2)
      {
        if (is_ready() != 0)
        {
          sub_80034034();
        }
        else
        {
          dispatch_action(mode, 2);
        }
      }
      else
      {
        sub_8003508C();
      }
      if (test_flag30_512() != 0)
      {
        run_hit_reaction();
      }
      dispatch_action(mode, 8);
      dispatch_action(mode, 0);
    }
    else
    {
      if (test_flag30_512() != 0)
      {
        run_hit_reaction();
      }
      dispatch_action(mode, 0);
    }
    advance_phase_wrap();
    update_projectile_spawns();
  }
  sub_800BBA0C();
  update_body_colliders();
  backup_pos__13TBoss2DeRolLeFi((saddr)this);
  submit_default_cursor_candidate();
  add_radar_scaled_marker(&position, -0x5DB4, 1, 1, 2.0f);
  update_particle_ctrls();
  if (teammate_state == 0)
  {
    part_group.run_tasks();
  }
}

}

}

void TBoss2DeRolLe::sub_8003508C() {
    if (is_ready() != 0) {
        sub_80034034();
        return;
    }
    dispatch_action(mode, 9);
}

namespace lifecycle_view {

extern "C" {

void TBoss2DeRolLe::refresh_target() {  }

void TBoss2DeRolLe::run_death_reaction() {  }

}

}

namespace joint_state_view {

extern "C" {

void TBoss2DeRolLe::run_hit_reaction() {
    s32 damage;
    damage = hpmax - hp;
    if (state_flags & 8) {
        unk_6AC = unk_6AC - damage;
        spawn_offset_particle(&bodies->center, 2.0f, 8.0f);
        play_sound(0x4003A80F, &unk_518[0]);
    } else {
        unk_6B0 = unk_6B0 - damage;
        if (unk_6B0 < 0) {
            unk_6B0 = 0;
            set_flags_play_sound();
        }
    }
    hp = hpmax;
    clear_attack_receipts();
}

void TBoss2DeRolLe::run_miss_reaction() {  }

void backup_pos__13TBoss2DeRolLeFi(s32 arg0) {
    VecCopy__FP3VecPC3Vec(arg0 + 0x2FC, arg0 + 0x38);
    VecCopy__FP3VecPC3Vec(arg0 + 0x74, arg0 + 0x2FC);
}

#pragma push
#pragma fp_contract on

void TBoss2DeRolLe::update_body_colliders() {
    Vec offsets[3];
    VecCopy(&offsets[0], &unk_3F8[6]);
    VecCopy(&offsets[1], &unk_4E8[2]);
    VecCopy(&offsets[2], &unk_4E8[3]);
    update_local_colliders_from_world(this, offsets);
}

#pragma pop

}

}

void TBoss2DeRolLe::set_state_and_send(s32 state) {
    DeRolLeActionTargetPacket target_packet;
    DeRolLeActionPacket packet;
    dispatch_action(state, 6);
    if (state == 0x19 || (state - 0x14) <= 1U || state == 0x1B) {
        TBoss2DeRolLe__sub_800363A0(&target_packet);
        target_packet.header.client_id = entity_id;
        target_packet.state = state;
        target_packet.sequence_index = unk_3D4;
        target_packet.target_id = target_id;
        update_and_send__13TBoss2DeRolLeFPv(&target_packet);
        return;
    }
    TBoss2DeRolLe__sub_80036358(&packet);
    packet.header.client_id = entity_id;
    packet.state = state;
    packet.sequence_index = unk_3D4;
    send_6x13__13TBoss2DeRolLeFPv(&packet);
}

namespace joint_state_view {


}

void TBoss2DeRolLe::reload_stats_for_phase(s32 kind) {
    s32 a;
    s32 i;
    s32 b;
    switch (kind) {
    case 0:
    default:
        a = 0;
        i = 0;
        b = 0;
        break;
    case 1:
        a = 0;
        i = 1;
        b = 0;
        break;
    case 2:
        a = 0;
        i = 2;
        b = 0;
        break;
    }
    reload_stats_keep_hp_tp((u8 *)TBoss2DeRolLe__base_params[a], (u8 *)TBoss2DeRolLe__attack_params_table[i], (u8 *)TBoss2DeRolLe__resistance_params[b]);
}

namespace joint_state_view {

extern "C" {

void forward_switch_phase_stats__13TBoss2DeRolLeFi(saddr arg0) {
    if ((void *) TBoss2DeRolLe__instance != NULL) {
        switch_phase_stats__13TBoss2DeRolLeFPvPv((u8 *)TBoss2DeRolLe__instance, (u8 *)arg0);
    }
}

void switch_phase_stats__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1) {
    u8 *temp_r5;
    temp_r5 = *(u8 **)((s8 *)arg1 + 0xA4);
    if (temp_r5 != NULL) {
        *(s32 *)((s8 *)temp_r5 + 0x18) = (s32) (*(s32 *)((s8 *)temp_r5 + 0x18) | 0x04000000);
        ((TBoss2DeRolLe *)arg0)->reload_stats_for_phase(1);
        ((VObj18 *)arg1)->m20(arg0, 1.0f);
        ((TBoss2DeRolLe *)arg0)->reload_stats_for_phase(((TBoss2DeRolLe *)arg0)->unk_3C4);
    }
}

void emit_effect_and_step__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1) {
    ((TBoss2DeRolLe *)arg0)->reload_stats_for_phase(2);
    TObjEneDD::emit_effect((void*)arg0, (saddr)arg1, (saddr)&derolle_effect_params);
    ((TBoss2DeRolLe *)arg0)->reload_stats_for_phase(((TBoss2DeRolLe *)arg0)->unk_3C4);
}

f32 TBoss2DeRolLe__sub_80034CF8(void) {
    return *(f32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 4);
}

f32 TBoss2DeRolLe__sub_80034CEC(void) {
    return *(f32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 8);
}

s32 TBoss2Joint_get_shell_max_hp(void) {
    return *(s32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 0x1C);
}

}

}

void TBoss2DeRolLe::set_position_index(s32 index) {
    VecCopy(&position, &TBoss2DeRolLe__position_point_table[index]);
    unk_6A4 = 0.0f;
    rotation_z = 0;
}

namespace joint_state_view {

extern "C" {

#pragma push
#pragma opt_common_subs off

}

}

void TBoss2DeRolLe::set_move_target_point(s32 index) {
    VecCopy(&destination, &TBoss2DeRolLe__position_point_table[index]);
    VecCopy(&destination_direction, &destination);
    subtract_vector(&destination_direction, &position);
    destination_distance = normalize_vector_xz(&destination_direction);
}

namespace joint_state_view {

extern "C" {

#pragma pop

void set_move_direction__13TBoss2DeRolLeFPv(void *arg0) {
    if ((s32) *(s32 *)((s8 *)arg0 + 0x654) == 0) {
        *(f32 *)((s8 *)arg0 + 0x38) = -100.0f;
        *(s32 *)((s8 *)arg0 + 0x64) = 0x500;
    } else {
        *(f32 *)((s8 *)arg0 + 0x38) = 100.0f;
        *(s32 *)((s8 *)arg0 + 0x64) = -0x500;
    }
    *(f32 *)((s8 *)arg0 + 0x40) = 10.0f;
    *(f32 *)((s8 *)arg0 + 0x6A4) = 4.0f;
}

f32 calc_node_height__13TBoss2DeRolLeFPv(Obj_80034B60 *self) {
    Vec v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    push_matrix_from(identity_matrix);
    scale_matrix(0, 2.0f, 2.0f, 2.0f);
    bind_motion_context((NJS_MOTION *)self->fF8, self->fC0);
    compose_motion_node_matrix((void *)self->f34);
    matrix_mult_vec(0, &v, &v);
    pop_matrix();
    return v.y;
}

void get_node_world_pos__13TBoss2DeRolLeFPvPv(u8 *arg0, u8 *arg1) {
    *(f32 *)((s8 *)arg1 + 0) = 0.0f;
    *(f32 *)((s8 *)arg1 + 4) = 0.0f;
    *(f32 *)((s8 *)arg1 + 8) = 0.0f;
    push_matrix();
    set_matrix_identity(0);
    Vec scale = {2.0f, 2.0f, 2.0f};
    scale_current_matrix(&scale);
    bind_motion_context((NJS_MOTION *)(*(saddr *)((s8 *)arg0 + 0xF8)), (f32) (*(f32 *)((s8 *)arg0 + 0xC0)));
    compose_motion_node_matrix((void *)(*(saddr *)((s8 *)arg0 + 0x34)));
    matrix_mult_vec(0, arg1, arg1);
    pop_matrix();
}

}

}

void TBoss2DeRolLe::update_angle() {
    if (unk_6A4 > 0.4f) {
        unk_6A4 -= 0.4f;
        return;
    }
    if (unk_6A4 < -0.4f) {
        unk_6A4 += 0.4f;
        return;
    }
    unk_6A4 = 0.0f;
}

void TBoss2DeRolLe::init_head_params() {
    unk_65C = 0;
    unk_664.init_params(3.0f, fabs_float(-position.x), 0.08f);
    unk_684.init_params(5.0f, fabs_float(500.0f - position.z), 0.08f);
}

#pragma push
#pragma opt_common_subs off

s32 TBoss2DeRolLe::update_phase_is_done() {
    advance_scalar_motion_profile(&unk_684);
    switch (unk_65C) {
    case 0:
        if (unk_684.travelled > 380.0f) {
            unk_65C = 1;
        }
        break;
    case 1:
        if (advance_scalar_motion_profile(&unk_664) == 3) {
            unk_65C = 2;
        }
        break;
    }
    play_speed += 0.1f;
    if (play_speed > 0.9f) {
        play_speed = 0.9f;
    }
    return unk_65C == 2;
}

#pragma pop

void TBoss2DeRolLe::init_movement() {
    unk_660 = 0;
    unk_664.init_params(3.0f, fabs_float(-175.0f - position.x), 0.08f);
    unk_684.set_move_params(7.0f, fabs_float(25.0f - position.z), 0.2f, 0.05f);
}

s32 TBoss2DeRolLe::sub_80034800() {
    advance_scalar_motion_profile(&unk_664);
    switch (unk_660) {
    case 0:
        if (unk_664.travelled > 160.0f) {
            unk_660 = 2;
        }
        break;
    case 2:
        play_speed = 0.3f;
        unk_660 = 3;
        break;
    case 3:
        if (advance_scalar_motion_profile(&unk_684) == 3) {
            unk_660 = 4;
        }
        if (unk_684.travelled > 200.0f) {
            play_speed += 0.1f;
            if (play_speed > 0.9f) {
                play_speed = 0.9f;
            }
        }
        break;
    }
    return unk_660 == 4;
}

void TBoss2DeRolLe::init_move_params() {
    unk_65C = 0;
    unk_664.init_params(3.0f, fabs_float(-position.x), 0.08f);
    unk_684.set_move_params(7.0f, fabs_float(-250.0f - position.z), 0.2f, 0.05f);
}

s32 TBoss2DeRolLe::update_state() {

    advance_scalar_motion_profile(&unk_684);
    switch (unk_65C) {
    case 0:
        play_speed = 0.3f;
        if (unk_684.travelled > 100.0f) {
            unk_65C = 1;
        }
        break;
    case 1:
        if (advance_scalar_motion_profile(&unk_664) == 3) {
            unk_65C = 2;
        }
        break;
    }
    if (unk_684.travelled > 100.0f) {
        play_speed = 0.9f;
    }
    return unk_65C == 2;
}

void TBoss2DeRolLe::init_wave_params() {
    unk_660 = 1;
    unk_664.init_params(3.0f, fabs_float(-175.0f - position.x), 0.08f);
    unk_684.init_params(5.0f, fabs_float(25.0f - position.z), 0.08f);
}

s32 TBoss2DeRolLe::sub_80034574() {
    f32 speed;
    advance_scalar_motion_profile(&unk_664);
    switch (unk_660) {
    case 2:
        break;
    case 1:
        speed = unk_684.speed - 0.1f;
        if (speed < -4.0f) {
            speed = -4.0f;
        }
        unk_684.speed = speed;
        unk_684.travelled = unk_684.travelled + speed;
        if (unk_664.travelled > 30.0f) {
            unk_660 = 3;
        }
        break;
    case 3:
        if (advance_scalar_motion_profile(&unk_684) == 3) {
            unk_660 = 4;
        }
        break;
    }
    play_speed += 0.1f;
    if (play_speed > 0.9f) {
        play_speed = 0.9f;
    }
    return unk_660 == 4;
}

void TBoss2DeRolLe::spawn_photon_pad(s32 joint, s32 level) {
    Vec dir;
    s32 ang;
    ang = 0x3800 - joint * 0x33;
    dir.x = sin_table_lookup(ang);
    dir.y = 0.0f;
    dir.z = cos_table_lookup(ang);
    if (position_index == 2) {
        dir.x *= -1.0f;
    }
    new TBoss2PhotonPad(&part_group, &joint_positions[joint], &dir, level);
    play_sound_effect(0x4003B708, &joint_positions[joint], 0, 1);
    joints[joint]->start_pad_flash();
}

#pragma push
#pragma fp_contract on

void TBoss2DeRolLe::calc_offset_position() {
    VecCopy(&laser_light_pos, &unk_4E8[0]);
    laser_light_pos.x = 30.0f * unk_4E8[1].x + laser_light_pos.x;
    laser_light_pos.y = 30.0f * unk_4E8[1].y + laser_light_pos.y;
    laser_light_pos.z = 30.0f * unk_4E8[1].z + laser_light_pos.z;
}

#pragma pop

void TBoss2DeRolLe::activate_laser_light() {
    if (laser_light != NULL) {
        laser_light->turn_on();
    }
    state_flags |= 0x10;
}

void TBoss2DeRolLe::free_laser() {
    if (laser_light != NULL) {
        laser_light->turn_off();
    }
    state_flags &= ~0x10;
}

namespace behavior_view {


}

void TBoss2DeRolLe::pick_random_target() {
    s32 n;
    TObjPlayer *player;
    s32 j;
    s32 i;

    n = TLobby::get_game_mode();
    if (n == 0) {
        enemy_clear_target();
        return;
    }
    if (n == 1) {
        player = TObjPlayer::get_player_data(0);
        set_target_player(player);
        return;
    }
    j = (s32)floor_to_float((f32)n * random_ratio());
    enemy_clear_target();
    for (i = 0; i < n; i++) {
        player = TObjPlayer::get_player_data(j);
        if (player->is_alive() != 0) {
            set_target_player(player);
            return;
        }
        if (++j >= n) {
            j = 0;
        }
    }
}

void TBoss2DeRolLe::sub_80034258() {
    s32 i;
    set_intangible();
    for (i = 0; i < 10; i++) {
        joints[i]->set_intangible();
    }
}

void TBoss2DeRolLe::sub_800341F0() {
    s32 i;
    clear_intangible();
    for (i = 0; i < 10; i++) {
        joints[i]->clear_intangible();
    }
}

namespace behavior_view {

extern "C" {

void TBoss2DeRolLe::enable_body_collision() {
    TObjEneDD::enable_body_collision();
    if ((state_flags & 8) || TObjEneDD::check_v2_mode() != 0) {
        clear_play_flags();
    }
}

}

}

void TBoss2DeRolLe::apply_hp_damage_with_sound(s32 damage, u16) {
    unk_6AC = unk_6AC - (s32)(0.5f * damage);
    play_sound(0x4003A80F, &position);
}

void TBoss2DeRolLe::set_flags_play_sound() {
    state_flags |= 0x88;
    clear_play_flags();
    play_sound(0x4003AA06, &position);
}

void TBoss2DeRolLe::clear_play_flags() {
    bodies[1].flags &= ~1;
    bodies[2].flags &= ~1;
}

namespace behavior_view {


}

s32 TBoss2DeRolLe::is_ready() {
    int ready;

    ready = 0;
    if (unk_6AC <= 0 && !(state_flags & 4)) {
        ready = 1;
    }
    return (u8)ready;
}

void TBoss2DeRolLe::sub_80034034() {
    s16 st = mode;
    if (st != 0x1f && st != 0x20) {
        if (st == 0x14 || st == 0x15) {
            advance_action_sequence();
        } else if (st == 0x16 || st == 0x17) {
            set_state_and_send(0x1f);
        } else {
            set_state_and_send(0x1e);
        }
    }
}

namespace behavior_view {

extern "C" {

void handle_6x13_de_rol_le_boss_actions(void *arg0) {
    void *x;
    swap_6x13_fields__13TBoss2DeRolLeFPv(arg0);
    x = get_enemy_entity(*(u16 *)((s8 *)arg0 + 0x2));
    if (x != NULL) {
        init_from_param__13TBoss2DeRolLeFPvPv(x, arg0);
    }
}

void handle_6x14_de_rol_le_boss_actions_with_target(void *arg0) {
    void *x;
    swap_endian__13TBoss2DeRolLeFPv(arg0);
    x = get_enemy_entity(*(u16 *)((s8 *)arg0 + 0x2));
    if (x != NULL) {
        set_params__13TBoss2DeRolLeFPvPv(x, arg0);
    }
}

void init_from_param__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1) {
    *(s32 *)((s8 *)arg0 + 0x3D4) = (s32) *(s16 *)((s8 *)arg1 + 6);
    ((TObjEneDD *)arg0)->transition_enemy_state(*(s16 *)((s8 *)arg1 + 4));
}

void set_params__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1) {
    enemy_set_target_id(arg0, (u16) *(s32 *)((s8 *)arg1 + 8));
    *(s32 *)((s8 *)arg0 + 0x3D4) = (s32) *(s16 *)((s8 *)arg1 + 6);
    ((TObjEneDD *)arg0)->transition_enemy_state(*(s16 *)((s8 *)arg1 + 4));
}

void reset_fields_3d0__13TBoss2DeRolLeFPv(void* p) { *(s32*)((char*)p + 0x3d0) = 0; *(s32*)((char*)p + 0x3d4) = 0; }

}

}

void TBoss2DeRolLe::advance_action_sequence() {
    s32 retry;
    s32 mode;
    do {
        retry = 0;
        unk_3D4++;
        if (TObjEneDD::check_v2_mode() != 0) {
            mode = derolle_action_sequence_table[unk_3D4];
        } else {
            mode = derolle_action_mode_sequence_table[unk_3D4];
        }
        switch (mode) {
        case 33:
            if (calc_elapsed_scaled() > 0.0f) {
                mode = 8;
            } else {
                mode = 6;
            }
            break;
        case 34:
            if (unk_658 == 0) {
                mode = 5;
            } else {
                mode = 9;
            }
            break;
        case 35:
            if (calc_elapsed_scaled() > 0.0f) {
                mode = 0xC;
            } else {
                mode = 0xE;
            }
            break;
        case 36:
            if (unk_658 == 0) {
                mode = 3;
            } else {
                mode = 0xB;
            }
            break;
        case 37:
            if (calc_elapsed_scaled() > 0.0f) {
                mode = 0x18;
            } else {
                mode = 0x19;
            }
            break;
        case 39:
            if (unk_658 == 0) {
                mode = 4;
            } else {
                mode = 0xA;
            }
            break;
        case 40:
            if (unk_658 == 0) {
                mode = 0x10;
            } else {
                mode = 0x11;
            }
            break;
        case 41:
            if (unk_658 == 0) {
                mode = 0x12;
            } else {
                mode = 0x13;
            }
            break;
        case 42:
            if (unk_658 == 0) {
                mode = 0x14;
            } else {
                mode = 0x15;
            }
            break;
        case 43:
            if (unk_658 == 0) {
                mode = 0x16;
            } else {
                mode = 0x17;
            }
            break;
        case 44:
            retry = 1;
            unk_3D4 = 5;
            break;
        }
    } while (retry != 0);
    set_state_and_send(mode);
}

namespace behavior_view {

extern "C" {

}

}

#pragma push
#pragma fp_contract on

void TBoss2DeRolLe::update_particle_ctrls() {
    Vec t;
    s32 ang[3];
    s32 ok;
    s32 j;
    s32 i;
    s32 k;
    void *p;
    s32 m;
    s32 n;
    ok = 1;
    for (i = 0; i < 6; i++) {
        if (splash_ctrls[i] == NULL) {
            ang[2] = 0;
            ang[1] = 0;
            ang[0] = 0;
            p = create_particle_controller_with_angles(joint_positions, ang, 0x120, 1, 0x40);
            if (p != NULL) {
                splash_ctrls[i] = (TParticleCtrl *)p;
                splash_ctrls[i]->set_flags(2);
                splash_ctrls[i]->enable();
            } else {
                for (j = 0; j < i; j++) {
                    splash_ctrls[j]->enable();
                }
                ok = 0;
                break;
            }
        }
    }
    if (ok != 0) {
        if (splash_joint == 0) {
            for (k = 0; k < 3; k++) {
                Vec *v = &joint_positions[boss2_derolle_particle_node_indices[k]];
                f32 r = fabs_float(v->y - -10.0f);
                f32 lim = boss2_derolle_particle_limits[k];
                if (r < 0.9f * lim) {
                    VecCopy(&t, v);
                    lim -= r;
                    t.y = -5.0f;
                    t.x += lim;
                    splash_ctrls[k * 2]->set_position(&t);
                    t.x -= 2.0f * lim;
                    splash_ctrls[k * 2 + 1]->set_position(&t);
                } else {
                    splash_ctrls[k * 2]->enable();
                    splash_ctrls[k * 2 + 1]->enable();
                }
            }
        } else {
            VecCopy(&t, &joint_positions[splash_joint]);
            t.y = -5.0f;
            t.x += 20.0f;
            splash_ctrls[0]->set_position(&t);
            t.x -= 40.0f;
            splash_ctrls[1]->set_position(&t);
            for (m = 2; m < 6; m++) {
                splash_ctrls[m]->enable();
            }
            splash_joint = 0;
        }
        for (n = 0; n < 6; n++) {
            sub_80033A80(splash_ctrls[n]);
        }
    }
}

#pragma pop

void TBoss2DeRolLe::sub_80033A80(TParticleCtrl *ctrl) {
    TObjBoss2Tunnel::sub_8003B1D8(ctrl);
}

void TBoss2DeRolLe::spawn_ceil_junk(Vec *pos) {
    TObjBoss2CeilJunk::create_particle(pos, 0x121);
}

#pragma push
#pragma fp_contract on

void TBoss2DeRolLe::spawn_offset_particle(Vec *position, f32 height, f32 distance) {
    Vec pos;
    VecCopy(&pos, position);
    pos.x = -((lbl_804FF5E8[3] * distance) - pos.x);
    pos.y -= (lbl_804FF5E8[4] * distance) - height;
    pos.z = -((lbl_804FF5E8[5] * distance) - pos.z);
    spawn_particle_effect_with_flags(&pos, 0x127, 0x40);
}

#pragma pop

void TBoss2DeRolLe::update_projectile_spawns() {
    Vec *mid;

    project_sound_origin_from_camera((saddr)&position, (u8 *)&unk_518[0], 0.3f);
    project_sound_origin_from_camera((saddr)&unk_3F8[18], (u8 *)&unk_518[1], 0.3f);
    mid = &unk_518[2];
    VecCopy(mid, &unk_518[1]);
    vec3_add_to(mid, &unk_518[1]);
    mid->x *= 0.5f;
    mid->y *= 0.5f;
    mid->z *= 0.5f;
    if ((state_flags & 0x100) && ((is_passing_frame(3.0f) != 0) || (is_passing_frame(20.0f) != 0))) {
        unk_53C = 0;
    }
    if (unk_53C <= 0x10) {
        play_persistent_sound(0x4003AD00, (saddr)this, (uaddr)&unk_518[2], 0, 0);
        unk_53C = unk_53C + 1;
    }
}

void TBoss2DeRolLe::sub_800338BC() {  }

namespace behavior_view {

extern "C" {

int play_sound(void* p, int a1) { return play_sound_effect(p, a1, 0, 0); }

int spawn_trap__13TBoss2DeRolLeFPvii(void* p, int a1, int a2) { return play_persistent_sound((saddr)p, (a1), (a2), 0, 0); }

}

}


#pragma push
#pragma opt_common_subs off

void TBoss2DeRolLe::advance_phase_wrap() {
    f32 phase;
    pulse_phase = pulse_phase + pulse_speed;
    phase = pulse_phase;
    if (phase >= 2.0f) {
        pulse_phase = phase - 2.0f;
    }
}

#pragma pop

#pragma push
#pragma fp_contract on

#define SWAP_COLOR_HALVES(x) ((((x) & 0xFF00) << 16) | ((x) >> 16) | (((x) & 0xFF) << 16))

// SWAP_COLOR_HALVES swaps the two halfwords of a packed colour (0xAARRGGBB -> 0xGGBBAARR)
// The runtime's float to unsigned conversion, called directly here.
extern "C" u32 __cvt_fp2unsigned(f32);

void TBoss2DeRolLe::update_pulsing_colors() {
    s32 i;
    f32 t;
    u8 v;
    u32 c;
    f32 ph;
    t = pulse_phase;
    if (t > 1.0f) {
        t = 2.0f - t;
    }
    v = __cvt_fp2unsigned(255.0f * (0.9f * t + 0.1f));
    c = 0xFF000000;
    c |= v << 16;
    c |= v >> 2;
    *boss2_derolle_primary_color_targets[2] = *boss2_derolle_primary_color_targets[0] = SWAP_COLOR_HALVES(c);
    c = 0xFF000000;
    c |= v << 16;
    c |= v << 8;
    *boss2_derolle_primary_color_targets[1] = SWAP_COLOR_HALVES(c);
    ph = pulse_phase;
    for (i = 0; i < 10; i++) {
        ph += 0.2f;
        if (ph > 2.0f) {
            ph -= 2.0f;
        }
        t = ph;
        if (ph > 1.0f) {
            t = 2.0f - ph;
        }
        v = __cvt_fp2unsigned(255.0f * (0.9f * t + 0.1f));
        c = 0xFF000000;
        c |= v << 16;
        c |= v << 8;
        *boss2_derolle_segment_color_targets[i] = SWAP_COLOR_HALVES(c);
    }
}

#pragma pop

#undef SWAP_COLOR_HALVES

namespace behavior_view {

extern "C" {

void TBoss2DeRolLe::dispatch_action(u32 state, s32 reason) {
    switch (state) {
    case 0:
        sub_800333F4(reason);
        return;
    case 1:
        TBoss2DeRolLe__sub_80032E38(this, reason);
        return;
    case 2:
        handle_debug_pad_input__13TBoss2DeRolLeFPvPv(this, reason);
        return;
    case 3:
        TBoss2DeRolLe__sub_800327C8(this, reason, 0, 1);
        return;
    case 4:
        TBoss2DeRolLe__sub_800320B4(this, reason, 0, 2);
        return;
    case 5:
        TBoss2DeRolLe__sub_800327C8(this, reason, 0, 3);
        return;
    case 6:
        TBoss2DeRolLe__sub_800327C8(this, reason, 1, 2);
        return;
    case 8:
        TBoss2DeRolLe__sub_800327C8(this, reason, 1, 0);
        return;
    case 9:
        TBoss2DeRolLe__sub_800327C8(this, reason, 2, 3);
        return;
    case 10:
        TBoss2DeRolLe__sub_800320B4(this, reason, 2, 0);
        return;
    case 11:
        TBoss2DeRolLe__sub_800327C8(this, reason, 2, 1);
        return;
    case 12:
        TBoss2DeRolLe__sub_800327C8(this, reason, 3, 0);
        return;
    case 13:
        TBoss2DeRolLe__sub_80031AD4(this, reason);
        return;
    case 14:
        TBoss2DeRolLe__sub_800327C8(this, reason, 3, 2);
        return;
    case 18:
        TBoss2DeRolLe__sub_800313F8(this, reason, 0);
        return;
    case 19:
        TBoss2DeRolLe__sub_800313F8(this, reason, 2);
        return;
    case 20:
        TBoss2DeRolLe__sub_800310F8(this, reason, 0);
        return;
    case 21:
        TBoss2DeRolLe__sub_800310F8(this, reason, 2);
        return;
    case 22:
        TBoss2DeRolLe__sub_80030DFC(this, reason, 0);
        return;
    case 23:
        TBoss2DeRolLe__sub_80030DFC(this, reason, 2);
        return;
    case 16:
        state_photon_pads(reason, 0);
        return;
    case 17:
        state_photon_pads(reason, 2);
        return;
    case 15:
        TBoss2DeRolLe__sub_80030A38(this, reason);
        return;
    case 24:
        state_launch_mines(reason, 0x18);
        return;
    case 25:
        state_launch_mines(reason, 0x19);
        return;
    case 26:
        state_ceiling_attack(reason);
        return;
    case 27:
        TBoss2DeRolLe__sub_8002FE60(this, reason);
        return;
    case 28:
        sub_8002FD9C(reason, 0);
        return;
    case 29:
        sub_8002FD9C(reason, 1);
        return;
    case 30:
        sub_8002FCE4(reason);
        return;
    case 31:
        handle_death_state__13TBoss2DeRolLeFPvPv(this, reason);
        return;
    case 32:
        sub_8002F73C(reason);
    default:
        return;
    }
}

}

}

void TBoss2DeRolLe::sub_800333F4(u32 reason) {
    switch (reason) {
    case 4: requested_action = 1; return;
    case 2: set_state_and_send(1); return;
    case 0: advance_animation(); return;
    case 1: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

namespace behavior_view {

extern "C" {

#pragma push
#pragma fp_contract on

#define o ((Rol_80032E38 *)arg0)

void TBoss2DeRolLe__sub_80032E38(void *arg0, void *arg1) {
    Vec *p = &o->f724;
    CameraPlayback cam;
    CameraPlayback cam2;
    Vec v1;
    Vec v2;
    Vec v3;
    f32 t;
    switch ((uaddr)arg1) {
    case 4:
        o->fB8 = 0;
        ((TBoss2DeRolLe *)o)->sub_80034258();
        o->f3C0 &= ~4;
        o->f3C0 &= ~0x100;
        o->pos.x = 70.0f;
        o->f6A4 = 0.0f;
        o->f64 = 0;
        o->f6E0 = 1;
        o->f6E4 = 0;
        o->f6E8 = 0;
        o->f6FC = 0.0f;
        p->x = 0.0f;
        p->y = 0.0f;
        p->z = 0.0f;
        if (TObjEneDD::check_v2_mode() != 0) {
            cam.index = 1;
            cam.bank = 1;
            cam.flags = 0;
            cam.frame = 0.0f;
            cam.frame_step = 0.8f;
            ((s32 (*)(int, f32))activate_camera_mode)(5, 0.0f);
            cam.cache_target_and_forward(0x1C71);
        } else {
            cam2.index = 0;
            cam2.bank = 1;
            cam2.flags = 0;
            cam2.frame = 0.0f;
            cam2.frame_step = 0.8f;
            ((s32 (*)(int, f32))activate_camera_mode)(5, 0.0f);
            cam2.cache_target_and_forward(0x1C71);
        }
        TWindowCtrl::init_all_slots();
        ((TObjEneDD *)o)->get_target_state_b();
        break;
    case 2:
        if (o->f6E0 == 5) {
            o->f654 = 0;
            ((TBoss2DeRolLe *)o)->set_state_and_send(2);
        }
        break;
    case 9:
        if (o->f6E0 == 5) {
            o->f654 = 0;
            ((TBoss2DeRolLe *)o)->advance_action_sequence();
        }
        break;
    case 0:
        if (o->f6E0 == 2) {
            o->fB8 = 1;
            ((void (*)(void *, void *))vec3_add_to)(&o->pos, p);
            ((TBoss2DeRolLe *)o)->set_move_target_point(0);
            o->f6E0 = 3;
        }
        ((TObjMotion *)o)->advance_animation();
        switch (o->f6E0) {
        case 0:
            o->f6E8++;
            if (o->f6E8 >= 0x37) {
                o->f6E8 = 0;
                o->f6E0 = 1;
                o->pos.x = 0.0f;
                o->pos.y = 7.0f;
                o->pos.z = -190.0f;
                o->f6A4 = 0.0f;
                o->f64 = 0;
            }
            break;
        case 1:
            get_node_world_pos__13TBoss2DeRolLeFPvPv((u8 *)o, (u8 *)p);
            o->f6E4++;
            t = o->fC0;
            if (t >= 34.0f && t <= 42.0f) {
                if ((f32)o->f6E4 >= 3.0f) {
                    o->f6E4 = 0;
                    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v1, &o->pos);
                    ((void (*)(void *, void *))vec3_add_to)(&v1, p);
                    v1.x += 30.0f * ((TObjEneDD *)o)->calc_elapsed_scaled();
                    v1.y = -5.0f;
                    v1.z += 70.0f;
                    ((TBoss2DeRolLe *)o)->spawn_ceil_junk(&v1);
                }
            } else if (t >= 64.0f && t <= 72.0f) {
                if ((f32)o->f6E4 >= 2.0f) {
                    o->f6E4 = 0;
                    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v2, &o->pos);
                    ((void (*)(void *, void *))vec3_add_to)(&v2, p);
                    v2.x += 40.0f * ((TObjEneDD *)o)->calc_elapsed_scaled();
                    v2.y = -5.0f;
                    v2.z += 40.0f;
                    ((TBoss2DeRolLe *)o)->spawn_ceil_junk(&v2);
                }
            } else if (t >= 110.0f && t <= 120.0f && (f32)o->f6E4 >= 2.0f) {
                o->f6E4 = 0;
                ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v3, &o->pos);
                ((void (*)(void *, void *))vec3_add_to)(&v3, p);
                v3.x += 30.0f * ((TObjEneDD *)o)->calc_elapsed_scaled();
                v3.y = -5.0f;
                v3.z += 70.0f;
                ((TBoss2DeRolLe *)o)->spawn_ceil_junk(&v3);
            }
            if (((TObjMotion *)o)->is_passing_frame(35.0f) != 0 || ((TObjMotion *)o)->is_passing_frame(112.0f) != 0) {
                play_sound_effect((void *)0x4003AD11, 0, 0, 0);
            } else if (((TObjMotion *)o)->is_passing_frame(65.0f) != 0) {
                play_sound_effect((void *)0x4003AD12, 0, 0, 0);
            }
            if (o->fC0 >= 34.0f) {
                o->pos.x -= 1.0f;
            } else if (o->fC0 >= 18.0f) {
                o->pos.x -= 5.0f;
            }
            if (((TObjEneDD *)o)->get_flag_b4() != 0) {
                o->f6E0 = 2;
                o->f3C0 |= 0x100;
            }
            break;
        case 2:
            break;
        case 3:
            o->pos.x = 3.0f * o->f3A0 + o->pos.x;
            o->pos.z = 3.0f * o->f3A8 + o->pos.z;
            o->f6FC += 3.0f;
            if (o->f6FC >= o->f3AC) {
                o->f6E0 = 4;
            }
            break;
        case 4:
            if (get_scripted_camera_playback()->flags & 1) {
                restore_player_cameras();
                o->f6E0 = 5;
            }
            break;
        }
        break;
    case 5:
        restore_player_cameras();
        TWindowCtrl::init_all_slots2();
        ((TObjEneDD *)o)->get_target_state_a();
        break;
    }
}

#pragma pop

#undef o
#define arg0 ((u8 *)arg0_)

void handle_debug_pad_input__13TBoss2DeRolLeFPvPv(void *arg0_, void *arg1_) {
    u32 arg1 = (uaddr)arg1_;
    u32 b;

    switch (arg1) {
    case 4:
        ((TBoss2DeRolLe *)arg0)->requested_action = 1;
        ((TBoss2DeRolLe *)arg0)->sub_800341F0();
        *(s32 *)((s8 *)arg0 + 0x3C0) &= ~4;
        *(s32 *)((s8 *)arg0 + 0x3C0) |= 0x100;
        *(f32 *)((s8 *)arg0 + 0x6A4) = 0.0f;
        ((TBoss2DeRolLe *)arg0)->rotation_z = 0;
        *(s32 *)((s8 *)arg0 + 0x6E4) = 1;
        *(s32 *)((s8 *)arg0 + 0x6E8) = 0;
        *(s32 *)((s8 *)arg0 + 0x6E0) = 0;
        break;
    case 2:
        switch (*(s32 *)((s8 *)arg0 + 0x654)) {
        case 0:
            b = (*(Pad_80032B28 **)((s8 *)arg0 + 0x3CC))->buttons;
            if (b & 0x10) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(3);
            } else if (b & 0x40) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(4);
            } else if (b & 0x20) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(5);
            } else if (b & 0x400) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0x12);
            } else if (b & 4) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0x10);
            } else if (b & 2) {
                *(f32 *)((s8 *)arg0 + 0x40) = -210.0f;
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(1);
            }
            break;
        case 1:
            b = (*(Pad_80032B28 **)((s8 *)arg0 + 0x3CC))->buttons;
            if (b & 0x40) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(6);
            } else if (b & 0x20) {
            } else if (b & 0x80) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(8);
            } else if (b & 0x400) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0x18);
            } else if (b & 4) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0x19);
            } else if (b & 2) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0x1E);
            }
            break;
        case 2:
            b = (*(Pad_80032B28 **)((s8 *)arg0 + 0x3CC))->buttons;
            if (b & 0x20) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(9);
            } else if (b & 0x80) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0xA);
            } else if (b & 0x10) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0xB);
            } else if (b & 0x400) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0x13);
            } else if (b & 4) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0x11);
            } else if (b & 2) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0x1E);
            }
            break;
        case 3:
            b = (*(Pad_80032B28 **)((s8 *)arg0 + 0x3CC))->buttons;
            if (b & 0x80) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0xC);
            } else if (b & 0x10) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0xD);
            } else if (b & 0x40) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0xE);
            } else if (b & 0x400) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0xF);
            } else if (b & 4) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0x1A);
            } else if (b & 0x200) {
                if (TObjBoss2Tunnel::is_active() != 0) {
                    TObjBoss2Tunnel::set_global_flag_800();
                } else {
                    TObjBoss2Tunnel::set_global_flag_400();
                }
            } else if (b & 2) {
                ((TBoss2DeRolLe *)arg0)->set_state_and_send(0x1F);
            }
            break;
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        if (!(((TBoss2DeRolLe *)arg0)->motion_flags & 4)) {
            ((TBoss2DeRolLe *)arg0)->play_speed -= 0.03f;
            if (((TBoss2DeRolLe *)arg0)->play_speed < 0.6f) {
                ((TBoss2DeRolLe *)arg0)->play_speed = 0.6f;
            }
        }
        break;
    case 1: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

#pragma push
#pragma fp_contract on

#undef arg0
#define o ((DR_800327C8 *)arg0)

void TBoss2DeRolLe__sub_800327C8(void *arg0, void *arg1, int arg2, int arg3) {
    s32 r;
    switch ((uaddr)arg1) {
    case 4:
        o->fB8 = 1;
        ((TBoss2DeRolLe *)o)->sub_800341F0();
        o->flags &= ~4;
        o->flags |= 0x100;
        o->mode = arg2;
        o->sub = arg3;
        ((TBoss2DeRolLe *)o)->set_position_index(o->mode);
        o->done = 0;
        o->baseX = o->x;
        o->baseZ = o->z;
        switch (o->mode) {
        case 0:
            o->scaleX = 1.0f;
            switch (o->sub) {
            case 2:
                break;
            case 1:
                o->kind = 1;
                break;
            case 3:
                o->kind = 3;
                break;
            }
            break;
        case 1:
            o->kind = 2;
            switch (o->sub) {
            case 1:
                break;
            case 2:
                o->scaleX = 1.0f;
                break;
            case 0:
                o->scaleX = -1.0f;
                break;
            }
            break;
        case 2:
            o->scaleX = -1.0f;
            switch (o->sub) {
            case 2:
                break;
            case 1:
                o->kind = 1;
                break;
            case 3:
                o->kind = 3;
                break;
            }
            break;
        case 3:
            o->kind = 0;
            switch (o->sub) {
            case 1:
                break;
            case 2:
                o->scaleX = 1.0f;
                break;
            case 0:
                o->scaleX = -1.0f;
                break;
            }
            break;
        }
        switch (o->kind) {
        case 0:
            ((TBoss2DeRolLe *)arg0)->init_wave_params();
            o->scaleZ = 1.0f;
            break;
        case 1:
            ((TBoss2DeRolLe *)o)->init_head_params();
            o->scaleZ = 1.0f;
            break;
        case 2:
            ((TBoss2DeRolLe *)arg0)->init_movement();
            o->scaleZ = -1.0f;
            break;
        case 3:
            ((TBoss2DeRolLe *)arg0)->init_move_params();
            o->scaleZ = -1.0f;
            break;
        }
        break;
    case 2:
        if (o->done == 1) {
            ((TBoss2DeRolLe *)o)->set_state_and_send(2);
        }
        break;
    case 9:
        if (o->done == 1) {
            ((TBoss2DeRolLe *)o)->advance_action_sequence();
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        ((TBoss2DeRolLe *)o)->sub_800338BC();
        r = 0;
        switch (o->kind) {
        case 0:
            r = ((TBoss2DeRolLe *)arg0)->sub_80034574();
            break;
        case 1:
            r = ((TBoss2DeRolLe *)arg0)->update_phase_is_done();
            o->z = o->baseZ + o->ampZ;
            break;
        case 2:
            r = ((TBoss2DeRolLe *)arg0)->sub_80034800();
            o->z = o->baseZ - o->ampZ;
            break;
        case 3:
            r = ((TBoss2DeRolLe *)arg0)->update_state();
            o->z = o->baseZ - o->ampZ;
            break;
        }
        if (r != 0) {
            o->done = 1;
        }
        o->x = o->ampX * o->scaleX + o->baseX;
        o->z = o->ampZ * o->scaleZ + o->baseZ;
        break;
    case 5:
        o->mode = o->sub;
        break;
    }
}

#define self ((D_800320B4 *) arg0)

void TBoss2DeRolLe__sub_800320B4(void *arg0, void *arg1, int arg2, int arg3) {
    switch ((uaddr) arg1) {
    case 4:
        ((TBoss2DeRolLe *)self)->sub_800341F0();
        self->flags |= 4;
        self->flags &= ~0x100;
        self->mode = arg2;
        self->next_mode = arg3;
        ((TBoss2DeRolLe *)self)->set_position_index(self->mode);
        if (self->mode == 0) {
            self->fB8 = 5;
            self->dir = -1.0f;
        } else {
            self->fB8 = 6;
            self->dir = 1.0f;
        }
        self->phase = 0;
        self->f6E4 = 0;
        self->step = 0;
        self->f700 = 0.0f;
        self->f704 = 0.0f;
        self->vx = 0.0f;
        self->ay = 0.0f;
        self->vy = 0.0f;
        self->tick = 0;
        break;
    case 2:
        if (self->phase == 2) {
            ((TBoss2DeRolLe *)self)->set_state_and_send(2);
        }
        break;
    case 9:
        if (self->phase == 2) {
            ((TBoss2DeRolLe *)self)->advance_action_sequence();
        }
        break;
    case 0:
        switch (self->phase) {
        case 0:
            ((TObjMotion *)self)->advance_animation();
            if (!(self->fB0 & 4)) {
                self->phase = 1;
            }
            break;
        case 1:
            ((TObjMotion *)self)->advance_animation();
            switch (self->step) {
            case 0:
                if (self->frame >= 10.0f) {
                    self->step = 1;
                    self->vx = 3.25f * self->dir;
                }
                break;
            case 1:
                if (self->frame >= 20.0f) {
                    self->step = 2;
                    self->vx = -5.625f * self->dir;
                    self->ay = (270.0f - self->z + 72.666664f * -self->vy) / 1034.6666f;
                }
                break;
            case 2:
                if (self->frame >= 28.0f) {
                    self->step = 3;
                    self->f700 = (calc_node_height__13TBoss2DeRolLeFPv(self) - self->f700) / 2.5f;
                    self->f704 = (2.0f * self->f700) / 56.666664f;
                    self->vx = -6.5294123f * self->dir;
                    self->tick = 0;
                }
                break;
            case 3:
                if (self->frame >= 45.0f) {
                    self->step = 4;
                    self->vx = -15.0f * self->dir;
                    ((TUnk_80036250 *)self->mover)->set_move_params(7.0f, fabs_float(25.0f - self->z), 0.2f, 0.05f);
                    self->f694 = -(0.5f * self->vy);
                    self->vy = self->z;
                }
                break;
            case 4:
                if (self->frame >= 46.0f) {
                    self->step = 5;
                    self->vx = self->dir * ((-175.0f - self->x * self->dir) / 36.0f);
                }
                break;
            case 5:
                if (self->frame >= 64.0f) {
                    self->step = 6;
                }
                break;
            }
            if (self->fB8 != 1) {
                if (((TObjMotion *)self)->is_passing_frame(10.0f) != 0 || ((TObjMotion *)self)->is_passing_frame(41.0f) != 0) {
                    ((int (*)(int, void *))play_sound)(0x4003AD11, self->snd);
                } else if (((TObjMotion *)self)->is_passing_frame(25.0f) != 0) {
                    ((int (*)(int, void *))play_sound)(0x4003AD12, self->snd);
                }
            }
            self->tick++;
            if (self->step != 6) {
                f32 frame = self->frame;
                if (frame >= 24.0f && frame <= 32.0f) {
                    if (self->tick >= 3) {
                        Vec v;
                        s32 i;
                        self->tick = 0;
                        ((void (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&v, &self->x);
                        for (i = 0; i < 10; i++) {
                            if (v.y * self->recs[i].y < 0.0f) {
                                break;
                            }
                            ((void (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&v, &self->recs[i]);
                        }
                        v.x = v.x - self->dir * (20.0f * ((TObjChara *)self)->random_ratio() + 40.0f);
                        v.y = -5.0f;
                        v.z = v.z + (20.0f * ((TObjEneDD *)self)->calc_elapsed_scaled() + 70.0f);
                        ((TBoss2DeRolLe *)self)->spawn_ceil_junk(&v);
                    }
                } else if (frame >= 41.0f && frame <= 46.0f && self->tick >= 3) {
                    Vec v;
                    self->tick = 0;
                    ((void (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&v, &self->x);
                    v.x = v.x + self->dir * (20.0f * ((TObjChara *)self)->random_ratio() + 20.0f);
                    v.y = -5.0f;
                    v.z = v.z + (60.0f * ((TObjEneDD *)self)->calc_elapsed_scaled() + 10.0f);
                    ((TBoss2DeRolLe *)self)->spawn_ceil_junk(&v);
                }
            }
            switch (self->step) {
            case 0:
                self->vy = self->vy - 0.2f;
                self->z = self->z + self->vy;
                break;
            case 1:
                self->x = self->x + self->vx;
                self->z = self->z + self->vy;
                break;
            case 2:
                self->x = self->x + self->vx;
                self->vy = self->vy + self->ay;
                self->z = self->z + self->vy;
                self->f700 = calc_node_height__13TBoss2DeRolLeFPv(self);
                break;
            case 3:
                self->x = self->x + self->vx;
                self->frame = self->frame - 0.19999999f;
                self->f6A4 = self->f6A4 + self->f700;
                self->f700 = self->f700 - self->f704;
                self->z = self->z + self->vy;
                break;
            case 4:
                self->x = self->x + self->vx;
                ((TBoss2DeRolLe *)self)->update_angle();
                advance_scalar_motion_profile(self->mover);
                self->z = self->vy - self->f69C;
                break;
            case 5:
                self->x = self->x + self->vx;
                ((TBoss2DeRolLe *)self)->update_angle();
                advance_scalar_motion_profile(self->mover);
                self->z = self->vy - self->f69C;
                break;
            case 6:
                ((TBoss2DeRolLe *)self)->update_angle();
                if (advance_scalar_motion_profile(self->mover) == 3) {
                    self->phase = 2;
                }
                self->z = self->vy - self->f69C;
                if (self->fB8 == 1) {
                    self->flags |= 0x100;
                }
                break;
            }
            break;
        }
        break;
    case 5:
        self->mode = self->next_mode;
        self->flags &= ~4;
        break;
    }
}

#undef o
#undef self
#define o ((Rol_80031AD4 *)arg0)

extern "C" {

void TBoss2DeRolLe__sub_80031AD4(void *arg0, void *arg1) {
    Vec va;
    Vec vb;

    switch ((uaddr)arg1) {
    case 4:
        o->fB8 = 1;
        ((TBoss2DeRolLe *)o)->sub_800341F0();
        o->f3C0 |= 4;
        o->f3C0 &= ~0x100;
        o->f654 = 3;
        ((TBoss2DeRolLe *)o)->set_position_index(o->f654);
        o->f6E0 = 0;
        o->f6E8 = 0;
        o->f6E4 = 0;
        o->f6FC = 0.0f;
        o->f700 = 0.0f;
        o->f704 = 0.0f;
        o->f708 = 0.0f;
        o->f6EC = 0;
        break;
    case 2:
        if (o->f6E0 == 3) {
            ((TBoss2DeRolLe *)o)->set_state_and_send(2);
        }
        break;
    case 9:
        if (o->f6E0 == 3) {
            ((TBoss2DeRolLe *)o)->advance_action_sequence();
        }
        break;
    case 0:
        ((TObjMotion *)o)->advance_animation();
        switch (o->f6E0) {
        case 0:
            o->f6E8++;
            if (o->f6E8 > 0x14) {
                o->fB8 = 4;
                o->f6E0 = 1;
            }
            o->f704 -= 0.2f;
            if (o->f704 < -7.0f) {
                o->f704 = -7.0f;
            }
            o->pos.z += o->f704;
            break;
        case 1:
            if (!(o->fB0 & 4)) {
                o->f6E0 = 2;
            }
            break;
        case 2:
            switch (o->f6E4) {
            case 0:
                if (o->fC0 >= 10.5f) {
                    o->f6E4 = 1;
                    o->f708 = (300.0f - o->pos.z + 49.102562f * -o->f704) / 732.1581f;
                    o->f6EC = 0;
                }
                break;
            case 1:
                if (o->fC0 >= 16.0f) {
                    o->f6E4 = 2;
                    o->f6FC = 4.0f * (40.0f - o->pos.y) / 30.76923f;
                    o->f700 = 2.0f * o->f6FC / 30.76923f;
                    o->f6EC = 0;
                }
                break;
            case 2:
                if (o->fC0 >= 22.0f) {
                    o->f6E4 = 3;
                    o->f704 *= 0.5f;
                    o->f708 = 0.0f;
                }
                break;
            case 3:
                if (o->fC0 >= 29.0f) {
                    o->f6E4 = 4;
                }
                break;
            }
            if (o->fB8 != 1) {
                if (((TObjMotion *)o)->is_passing_frame(4.0f) != 0 || ((TObjMotion *)o)->is_passing_frame(22.0f) != 0) {
                    play_sound((void *)0x4003AD11, (saddr)o->f518);
                } else if (((TObjMotion *)o)->is_passing_frame(14.0f) != 0) {
                    play_sound((void *)0x4003AD12, (saddr)o->f518);
                }
            }
            switch (o->f6E4) {
            case 1:
                o->f6EC++;
                if (o->fC0 >= 13.5f && o->f6EC >= 2) {
                    o->f6EC = 0;
                    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&va, &o->pos);
                    va.x += 50.0f * ((TObjEneDD *)o)->calc_elapsed_scaled();
                    va.y = -5.0f;
                    va.z += 180.0f;
                    ((TBoss2DeRolLe *)o)->spawn_ceil_junk(&va);
                }
                break;
            case 2:
            case 3:
                o->f6EC++;
                if (o->f6EC >= 2 && o->fC0 >= 21.0f && o->fC0 <= 26.0f) {
                    o->f6EC = 0;
                    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&vb, &o->pos);
                    vb.x += 50.0f * ((TObjEneDD *)o)->calc_elapsed_scaled();
                    vb.y = -5.0f;
                    vb.z += -20.0f;
                    ((TBoss2DeRolLe *)o)->spawn_ceil_junk(&vb);
                }
                break;
            }
            switch (o->f6E4) {
            case 0:
                o->f704 -= 0.2f;
                if (o->f704 < -7.0f) {
                    o->f704 = -7.0f;
                }
                o->pos.z += o->f704;
                break;
            case 1:
                o->f704 += o->f708;
                o->pos.z += o->f704;
                o->f6FC = calc_node_height__13TBoss2DeRolLeFPv(o);
                break;
            case 2:
                o->pos.z += o->f704;
                o->f6A4 += o->f6FC;
                o->f6FC -= o->f700;
                o->fC0 -= 0.105000004f;
                break;
            case 3:
            case 4:
                if (o->f708 <= 0.0f) {
                    o->f704 -= 0.2f;
                    if (o->f704 <= 0.0f) {
                        o->f708 = 1.0f;
                        ((TUnk_80036250 *)o->f684)->set_move_params(7.0f, fabs_float(500.0f - o->pos.z), 0.2f, 0.05f);
                        o->f704 = o->pos.z;
                    } else {
                        o->pos.z += o->f704;
                    }
                } else if (advance_scalar_motion_profile(o->f684) == 3) {
                    o->f6E0 = 3;
                } else {
                    o->pos.z = o->f704 - o->f69C;
                }
                ((TBoss2DeRolLe *)o)->update_angle();
                break;
            }
            break;
        }
        break;
    case 5:
        o->f654 = 1;
        o->f3C0 &= ~4;
        break;
    }
}

#undef o

void TBoss2DeRolLe__sub_800313F8(DR_800313F8 *o, u32 arg1, s32 arg2) {
    switch (arg1) {
    case 4:
        o->fB8 = 1;
        ((TBoss2DeRolLe *)o)->sub_800341F0();
        o->f3C0 |= 4;
        o->f3C0 &= ~0x100;
        o->f654 = arg2;
        ((TBoss2DeRolLe *)o)->set_position_index(o->f654);
        o->f6FC = 0.0f;
        o->f708 = 0.0f;
        o->f704 = 0.0f;
        o->f700 = 0.0f;
        o->f70C = -0.2f;
        o->f710 = 0.0f;
        o->f714 = o->pos.z;
        o->f718 = 0.0f;
        o->f6E4 = 0;
        o->f6E0 = 0;
        o->f6E8 = 0;
        o->f73C = 0;
        o->f6EC = 0;
        break;
    case 2: {
        u32 fl = o->f3CC->f8;
        if (fl & 0x400) {
            if (o->f654 == 0) {
                ((TBoss2DeRolLe *)o)->set_state_and_send(0x14);
            } else {
                ((TBoss2DeRolLe *)o)->set_state_and_send(0x15);
            }
        } else if (fl & 4) {
            if (o->f654 == 0) {
                ((TBoss2DeRolLe *)o)->set_state_and_send(0x16);
            } else {
                ((TBoss2DeRolLe *)o)->set_state_and_send(0x17);
            }
        }
        break;
    }
    case 9:
        if (o->fB8 == 0xA || o->fB8 == 9) {
            ((TBoss2DeRolLe *)o)->advance_action_sequence();
        }
        break;
    case 0:
        ((TObjMotion *)o)->advance_animation();
        switch (o->f6E0) {
        case 0:
            o->f6E4++;
            if (o->f6E4 > 0xA) {
                o->f6E4 = 0;
                o->f6E0 = 1;
                if (o->f654 == 0) {
                    o->fB8 = 7;
                    o->f6FC = -1.0f;
                } else {
                    o->fB8 = 8;
                    o->f6FC = 1.0f;
                }
            }
            break;
        case 1:
            if (!(o->fB0 & 4)) {
                o->f6E0 = 2;
            }
            break;
        case 2:
            if (o->fC0 >= 6.0f) {
                o->f6E0 = 3;
                o->f708 = 0.0f;
                o->f700 = o->pos.x;
                o->f704 = (100.0f * o->f6FC - o->f700) / 7.0f;
                o->f70C = -(o->f710 / 7.0f);
                o->f714 = o->pos.z;
                o->f710 = 0.0f;
            }
            break;
        case 3:
            if (o->fC0 >= 13.0f) {
                o->f6E0 = 4;
                o->f708 = 0.0f;
                o->f700 = 100.0f * o->f6FC;
                o->f704 = (135.0f * o->f6FC - o->f700) / 7.0f;
                o->f714 = o->pos.z;
                o->f70C = (2.0f * (10.0f - o->pos.z)) / 144.0f;
                o->f710 = 0.0f;
            }
            break;
        case 4:
            if (o->fC0 >= 20.0f) {
                o->f6E0 = 5;
                o->f708 = 0.0f;
                o->f700 = 135.0f * o->f6FC;
                o->f704 = (100.0f * o->f6FC - o->f700) / 5.0f;
                o->f718 = (1280.0f * -o->f6FC) / 5.0f;
            }
            break;
        case 5:
            if (o->fC0 >= 25.0f) {
                s32 i;
                o->f6E0 = 6;
                TCameraCtrl::set_shake_preset(1);
                if (o->f654 == 0) {
                    TObjBoss2Tunnel::sub_8003C610();
                } else {
                    TObjBoss2Tunnel::sub_8003C5F8();
                }
                ((int (*)(s32, void *))play_sound)(0x4003A507, o->snd);
                for (i = 0; i < 4; i++) {
                    ((TBoss2Tentacle *)(o->tentacles[i]))->raise();
                }
            }
            break;
        case 6:
            break;
        }
        o->f6E8++;
        if (o->f6E0 != 0 && o->f6E0 != 1) {
            if (o->fC0 >= 15.0f && o->fC0 <= 17.0f && o->f6E8 >= 2) {
                Vec v;
                f32 s;
                o->f6E8 = 0;
                VecCopy__FP3VecPC3Vec((saddr)&v, &o->v4E8);
                s = 50.0f * ((TObjChara *)o)->random_ratio();
                v.x = v.x - o->f6FC * s;
                v.y = -5.0f;
                v.z += 40.0f;
                ((TBoss2DeRolLe *)o)->spawn_ceil_junk(&v);
            }
            if (((TObjMotion *)o)->is_passing_frame(15.0f) != 0) {
                ((int (*)(s32, void *))play_sound)(0x4003AD11, o->snd);
            }
            if (o->f73C == 0) {
                o->f73C = create_particle_emitter(&o->pos, 0x161);
                if (o->f73C != 0) {
                    ((TParticleCtrl *)(o->f73C))->enable();
                }
            } else if (o->fC0 >= 24.0f && o->fC0 <= 30.0f) {
                o->f6EC++;
                if (o->f6EC % 4 == 0) {
                    ((TParticleCtrl *)o->f73C)->set_position(&o->v44C);
                } else if (o->f6EC % 4 == 2) {
                    ((TParticleCtrl *)o->f73C)->set_position(&o->v458);
                } else {
                    ((TParticleCtrl *)(o->f73C))->enable();
                }
            } else {
                ((TParticleCtrl *)(o->f73C))->enable();
            }
        }
        switch (o->f6E0) {
        case 0:
        case 1:
        case 2:
            o->f710 += o->f70C;
            if (o->f710 < -7.0f) {
                o->f710 = -7.0f;
            }
            o->pos.z += o->f710;
            break;
        case 3: {
            f32 t = o->fC0 - 6.0f;
            o->pos.x = o->f704 * t + o->f700;
            f32 h = 0.5f * o->f70C;
            o->pos.z = t * (h * t + -7.0f) + o->f714;
            if (((TObjMotion *)o)->is_passing_frame(8.5f) != 0) {
                ((int (*)(s32, void *))play_sound)(0x4003AD12, o->snd);
            }
            break;
        }
        case 4: {
            f32 t = o->fC0 - 13.0f;
            o->pos.x = o->f704 * t + o->f700;
            f32 h = 0.5f * o->f70C;
            o->pos.z = t * (h * t) + o->f714;
            o->f6A4 = 28.0f * t;
            if (o->f6A4 > 4.0f) {
                o->f6A4 = 4.0f;
            }
            break;
        }
        case 5: {
            f32 t = o->fC0 - 20.0f;
            f32 u;
            o->pos.x = o->f704 * t + o->f700;
            u = o->fC0 - 13.0f;
            {
                f32 h = 0.5f * o->f70C;
                f32 w = u * (h * u);
                o->pos.z = o->f714 + w;
            }
            o->f64 = o->f718 * t;
            break;
        }
        case 6:
            break;
        }
        break;
    case 5:
        o->f3C0 &= ~4;
        if (o->f73C != 0) {
            ((TObject *)o->f73C)->queue_destruction();
            o->f73C = 0;
        }
        break;
    }
}

}

#pragma pop

#define self ((Self_800310F8 *)arg0)

void TBoss2DeRolLe__sub_800310F8(void *arg0, void *arg1, int arg2) {
    Vec v;
    s32 a;
    s32 ok;
    s32 i;
    switch ((uaddr)arg1) {
    case 4:
        ((TBoss2DeRolLe *)self)->sub_800341F0();
        self->flags &= ~4;
        self->flags &= ~0x100;
        self->dir = arg2;
        set_move_direction__13TBoss2DeRolLeFPv(self, self->dir);
        if (self->dir == 0) {
            self->fB8 = 9;
        } else {
            self->fB8 = 10;
        }
        self->phase = 0;
        self->timer = 0;
        self->idx = 0;
        if (TObjEneDD::check_v2_mode() != 0) {
            self->limit = *(s32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 0x24);
            self->life = *(s32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 0x28);
        } else {
            self->limit = 0xB4;
            self->life = 0x78;
        }
        break;
    case 2:
        if (self->phase == 3) {
            if (self->dir == 0) {
                ((TBoss2DeRolLe *)self)->set_state_and_send(0x16);
            } else {
                ((TBoss2DeRolLe *)self)->set_state_and_send(0x17);
            }
        }
        break;
    case 9:
        if (self->phase == 3) {
            ((TBoss2DeRolLe *)self)->advance_action_sequence();
        }
        break;
    case 0:
        ((TObjMotion *)self)->advance_animation();
        switch (self->phase) {
        case 0:
            self->timer++;
            if (self->timer > 0x28) {
                self->phase = 1;
                self->timer = 0;
                self->idx = 0;
            }
            break;
        case 1:
            self->timer++;
            if (self->timer >= self->limit) {
                self->timer = 0;
                if (((TObjEneDD_ST *)self)->enemy_has_live_target() != 0) {
                    VecCopy__FP3VecPC3Vec((saddr)&v, self->f390 + 0x38);
                } else {
                    f32 r = 120.0f * ((TObjChara *)self)->random_ratio();
                    a = ((TObjEneDD *)self)->get_random_scaled();
                    v.x = r * sin_table_lookup(a);
                    v.y = -1.85f;
                    v.z = r * cos_table_lookup(a);
                    TObjBoss2Tunnel::adjust_to_ground((saddr)&v, &v);
                }
                {
                    Self_800310F8 *o = (Self_800310F8 *)arg0;
                    ((TBoss2Tentacle *)(o->parts[o->idx]))->start_attack_at_target((u8 *)&v, o->life);
                }
                self->idx++;
                if (self->idx >= 4) {
                    self->timer = 0;
                    self->phase = 2;
                }
            }
            break;
        case 2:
            ok = 1;
            self->timer++;
            for (i = 0; i < 4; i++) {
                if (TBoss2Tentacle__sub_80039CA0(self->parts[i]) == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok != 0 || self->timer > 0x258) {
                self->phase = 3;
            }
            break;
        }
        break;
    case 6:
        ((TBoss2DeRolLe *)(saddr)self)->pick_random_target();
        break;
    case 5:
        {
            s32 j;
            for (j = 0; j < 4; j++) {
                ((TBoss2Tentacle *)self->parts[j])->drop_back();
            }
        }
        break;
    }
}

#pragma push
#pragma fp_contract on

#undef self
#define F(t, o) (*(t *)(arg0 + (o)))
#define arg0 ((u8 *)arg0_)

void TBoss2DeRolLe__sub_80030DFC(void *arg0_, void *arg1_, int arg2) {
    switch ((uaddr)arg1_) {
    case 4:
        ((TBoss2DeRolLe *)arg0)->sub_800341F0();
        F(s32, 0x3C0) |= 4;
        F(s32, 0x3C0) &= ~0x100;
        F(s32, 0x654) = arg2;
        set_move_direction__13TBoss2DeRolLeFPv(arg0, F(s32, 0x654));
        if (F(s32, 0x654) == 0) {
            F(f32, 0x700) = -1.0f;
            F(s16, 0xB8) = 9;
        } else {
            F(f32, 0x700) = 1.0f;
            F(s16, 0xB8) = 10;
        }
        F(s32, 0x6E0) = 0;
        F(s32, 0x6E4) = 0;
        F(f32, 0x6FC) = 0.0f;
        F(f32, 0x708) = -1.0f;
        F(f32, 0x704) = 0.0f;
        F(s32, 0x6F4) = 0x500;
        TObjBoss2Tunnel::clear_global_flag_3000();
        break;
    case 2:
        if (F(s32, 0x6E0) == 2) {
            ((TBoss2DeRolLe *)arg0)->set_state_and_send(2);
        }
        break;
    case 9:
        if (F(s32, 0x6E0) == 2) {
            ((TBoss2DeRolLe *)arg0)->advance_action_sequence();
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        switch (F(s32, 0x6E0)) {
        case 0:
            F(f32, 0x704) += 0.2f;
            F(f32, 0x40) -= F(f32, 0x704);
            F(f32, 0x6FC) += 0.08f;
            F(f32, 0x38) += F(f32, 0x6FC) * F(f32, 0x700);
            F(f32, 0x708) += 0.1f;
            F(f32, 0x6A4) -= F(f32, 0x708);
            F(s32, 0x6F4) += 256.0f;
            if ((f32)F(s32, 0x6F4) >= 16384.0f) {
                F(s32, 0x6F4) = 0x4000;
            }
            F(s32, 0x64) = (s32)((f32)F(s32, 0x6F4) * -F(f32, 0x700));
            if (F(s32, 0x6E4) == 0 && F(s32, 0x6F4) >= 0x2200) {
                F(s32, 0x6E4) = 1;
                play_sound((void *)0x4003AD12, (saddr)(arg0 + 0x518));
            }
            if (F(f32, 0x6A4) < -137.0f) {
                F(s32, 0x6E0) = 1;
                ((TBoss2DeRolLe *)arg0)->set_position_index(F(s32, 0x654));
                F(f32, 0x6A4) = -137.0f;
                F(s16, 0xB8) = 1;
                F(f32, 0x708) = 0.0f;
                F(s32, 0x3C0) &= ~4;
                F(s32, 0x3C0) |= 0x100;
            }
            break;
        case 1:
            F(f32, 0x6A4) += 2.0f;
            if (F(f32, 0x6A4) >= 0.0f) {
                F(f32, 0x6A4) = 0.0f;
                F(s32, 0x6E0) = 2;
            }
            break;
        }
        break;
    case 5:
        F(s32, 0x3C0) &= ~4;
        break;
    case 1:
    case 3:
    case 6:
    case 7:
    case 8:
        break;
    }
}

#undef F
#undef arg0

void TBoss2DeRolLe__sub_80030A38(u8 *arg0, u32 arg1) {
    Vec v;

    switch (arg1) {
    case 4:
        ((TBoss2DeRolLe *)arg0)->requested_action = 1;
        ((TBoss2DeRolLe *)arg0)->sub_800341F0();
        *(s32 *)((s8 *)arg0 + 0x3C0) = *(s32 *)((s8 *)arg0 + 0x3C0) | 4;
        *(s32 *)((s8 *)arg0 + 0x3C0) = *(s32 *)((s8 *)arg0 + 0x3C0) & ~0x100;
        ((TBoss2DeRolLe *)arg0)->set_position_index(3);
        *(s32 *)((s8 *)arg0 + 0x6E0) = 0;
        *(s32 *)((s8 *)arg0 + 0x6E4) = 0;
        *(s32 *)((s8 *)arg0 + 0x6E8) = 0x1E;
        *(f32 *)((s8 *)arg0 + 0x6FC) = 0.0f;
        *(f32 *)((s8 *)arg0 + 0x700) = 3.0f;
        return;
    case 2:
        if (*(s32 *)((s8 *)arg0 + 0x6E0) == 6) {
            ((TBoss2DeRolLe *)arg0)->set_state_and_send(2);
        }
        return;
    case 9:
        if (*(s32 *)((s8 *)arg0 + 0x6E0) == 6) {
            ((TBoss2DeRolLe *)arg0)->advance_action_sequence();
            return;
        }
        break;
    case 0:
        ((TObjMotion *)arg0)->advance_animation();
        switch (*(s32 *)((s8 *)arg0 + 0x6E0)) {
        case 0:
            *(f32 *)((s8 *)arg0 + 0x6FC) += 0.2f;
            *(f32 *)((s8 *)arg0 + 0x40) -= *(f32 *)((s8 *)arg0 + 0x6FC);
            *(f32 *)((s8 *)arg0 + 0x700) += -0.2f;
            *(f32 *)((s8 *)arg0 + 0x6A4) += *(f32 *)((s8 *)arg0 + 0x700);
            if (*(f32 *)((s8 *)arg0 + 0x6A4) < -137.0f) {
                *(s32 *)((s8 *)arg0 + 0x6E0) = 1;
                *(s32 *)((s8 *)arg0 + 0x6E4) = 0;
            }
            break;
        case 1:
            *(s32 *)((s8 *)arg0 + 0x6E4) += 1;
            if (*(s32 *)((s8 *)arg0 + 0x6E4) >= 0x2D) {
                *(s32 *)((s8 *)arg0 + 0x6E0) = 2;
                ((TBoss2DeRolLe *)arg0)->requested_action = 2;
                *(f32 *)((s8 *)arg0 + 0x40) = -1200.0f;
                ((TBoss2DeRolLe *)arg0)->rotation_z = 0x8000;
                *(f32 *)((s8 *)arg0 + 0x6A4) = 93.0f;
            }
            break;
        case 2:
            *(s32 *)((s8 *)arg0 + 0x6E8) += 1;
            if (*(s32 *)((s8 *)arg0 + 0x6E8) >= 0x1E) {
                *(s32 *)((s8 *)arg0 + 0x6E8) = 0;
            }
            ((int (*)(int, void *, void *))spawn_trap__13TBoss2DeRolLeFPvii)(0x40039E02, arg0, arg0 + 0x518);
            *(f32 *)((s8 *)arg0 + 0x40) += 6.0f;
            if (*(f32 *)((s8 *)arg0 + 0x40) >= 360.0f) {
                *(s32 *)((s8 *)arg0 + 0x6E0) = 3;
                *(f32 *)((s8 *)arg0 + 0x700) = 0.0f;
            }
            if (((TObjChara *)arg0)->random_ratio() <= *(f32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 0x10)) {
                VecCopy__FP3VecPC3Vec((saddr)&v, arg0 + 0x38);
                v.x = *(f32 *)((s8 *)TBoss2DeRolLe__data_805D4BA0 + 0xC) * ((TObjEneDD *)arg0)->calc_elapsed_scaled() + v.x;
                v.z -= 100.0f * ((TObjChara *)arg0)->random_ratio();
                v.y += 10.0f + *(f32 *)((s8 *)arg0 + 0x6A4);
                TObjBoss2CeilJunk::create(&v);
            }
            break;
        case 3:
            ((TBoss2DeRolLe *)arg0)->play_speed -= 0.02f;
            if (((TBoss2DeRolLe *)arg0)->play_speed < 0.0f) {
                ((TBoss2DeRolLe *)arg0)->play_speed = 0.0f;
            }
            if (*(f32 *)((s8 *)arg0 + 0x6A4) > 0.0f) {
                *(f32 *)((s8 *)arg0 + 0x700) += -0.1f;
                *(f32 *)((s8 *)arg0 + 0x40) += 4.8f;
            } else {
                *(f32 *)((s8 *)arg0 + 0x40) += 1.2f;
            }
            *(f32 *)((s8 *)arg0 + 0x6A4) += *(f32 *)((s8 *)arg0 + 0x700);
            if (*(f32 *)((s8 *)arg0 + 0x6A4) < -137.0f) {
                *(s32 *)((s8 *)arg0 + 0x6E0) = 4;
                *(s32 *)((s8 *)arg0 + 0x6E4) = 0;
                ((int (*)(int, void *))play_sound)(0x4003AD12, arg0 + 0x518);
            }
            break;
        case 4:
            *(s32 *)((s8 *)arg0 + 0x6E4) += 1;
            if (*(s32 *)((s8 *)arg0 + 0x6E4) >= 0x2D) {
                *(s32 *)((s8 *)arg0 + 0x6E0) = 5;
                ((TBoss2DeRolLe *)arg0)->requested_action = 1;
                *(s32 *)((s8 *)arg0 + 0x654) = 1;
                ((TBoss2DeRolLe *)arg0)->set_position_index(*(s32 *)((s8 *)arg0 + 0x654));
                ((TBoss2DeRolLe *)arg0)->rotation_z = 0;
                *(f32 *)((s8 *)arg0 + 0x6A4) = -137.0f;
                TObjBoss2Tunnel::set_global_flag_400();
            }
            break;
        case 5:
            *(f32 *)((s8 *)arg0 + 0x6A4) += 0.9f;
            if (*(f32 *)((s8 *)arg0 + 0x6A4) >= 0.0f) {
                *(f32 *)((s8 *)arg0 + 0x6A4) = 0.0f;
                *(s32 *)((s8 *)arg0 + 0x6E0) = 6;
            }
            break;
        }
        break;
    default:
        break;
    }
}

#pragma pop

}

}

void TBoss2DeRolLe::state_photon_pads(u32 reason, s32 position) {
    s32 i;

    switch (reason) {
    case 4:
        requested_action = 3;
        sub_800341F0();
        state_flags = state_flags & ~4;
        state_flags = state_flags & ~0x100;
        position_index = position;
        set_position_index(position_index);
        unk_6E0 = 0;
        unk_6E4 = 0;
        unk_6FC[0] = -1000.0f;
        photon_pad_level = photon_pad_level + 1;
        if (photon_pad_level >= 3) {
            photon_pad_level = 0;
        }
        return;
    case 2:
        if (get_flag_b4() != 0) {
            set_state_and_send(2);
            return;
        }
        break;
    case 9:
        if (get_flag_b4() != 0) {
            advance_action_sequence();
            return;
        }
        break;
    case 0:
        advance_animation();
        switch (unk_6E4) {
        case 0:
            if (!(motion_flags & 4)) {
                spawn_photon_pad(unk_6E0, photon_pad_level);
                unk_6E4 = 1;
                return;
            }
            break;
        case 1:
            i = unk_6E0;
            if (joint_positions[i].y < joint_positions[i + 1].y) {
                unk_6E0 = i + 1;
                if ((f32)unk_6E0 >= 4.0f) {
                    unk_6E4 = 2;
                }
                spawn_photon_pad(unk_6E0, photon_pad_level);
            }
            break;
        }
        break;
    default:
        break;
    }
}

void TBoss2DeRolLe::state_launch_mines(u32 reason, s32 state) {
    Vec *pos;
    s32 i;
    s32 j;
    switch (reason) {
    case 4:
        state_flags &= ~4;
        state_flags |= 0x100;
        requested_action = 0xB;
        position_index = 1;
        set_position_index(position_index);
        break;
    case 2:
        if (get_flag_b4() != 0) {
            set_state_and_send(2);
        }
        break;
    case 9:
        if (get_flag_b4() != 0) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        if (is_passing_frame(18.0f) != 0) {
            pos = &unk_3F8[18];
            if (state == 0x18) {
                for (i = 0; i < 5; i++) {
                    mines[i]->set_launch_position_velocity(pos, &TBoss2DeRolLe__mine_ground_targets[i]);
                }
            } else if (enemy_has_live_target() != 0) {
                for (j = 0; j < 3; j++) {
                    target_mines[j]->init_launch(pos, target, j);
                }
            }
            play_sound(0x4003A303, &unk_518[1]);
        }
        break;
    case 6:
        if (state == 0x19) {
            pick_random_target();
        }
        break;
    }
}

#pragma push
#pragma fp_contract on

void TBoss2DeRolLe::state_ceiling_attack(u32 reason) {
    Vec v;
    f32 frame_now;

    switch (reason) {
    case 4:
        state_flags = state_flags & ~4;
        state_flags = state_flags | 0x100;
        sub_800341F0();
        requested_action = 0xC;
        position_index = 3;
        set_position_index(position_index);
        unk_6E0 = 0;
        unk_6DC = 0;
        return;
    case 2:
        if (requested_action == 0xF) {
            set_state_and_send(0x1B);
        }
        return;
    case 9:
        if (requested_action == 0xF) {
            advance_action_sequence();
            return;
        }
        break;
    case 0:
        advance_animation();
        unk_6E0 = unk_6E0 + 1;
        frame_now = frame;
        if (frame_now >= 10.0f && frame_now <= 14.0f && (f32)unk_6E0 >= 3.0f) {
            unk_6E0 = 0;
            VecCopy(&v, &position);
            v.x = 30.0f * calc_elapsed_scaled() + v.x;
            v.y = -5.0f;
            v.z += 80.0f;
            spawn_ceil_junk(&v);
        }
        if (is_passing_frame(10.0f) != 0) {
            play_sound(0x4003AD12, &unk_518[0]);
        }
        break;
    default:
        break;
    }
}

namespace behavior_view {

extern "C" {

#define VADD(d, s) ((void (*)(void *, void *)) vec3_add_to)((d), (s))
#define VCOPY(d, s) ((void (*)(void *, void *)) VecCopy__FP3VecPC3Vec)((d), (s))

void TBoss2DeRolLe__sub_8002FE60(void *arg0, u32 arg1) {
    Vec *vel;
    Vec *hit;
    D_8002FE60 *self = (D_8002FE60 *) arg0;
    vel = &self->vel;
    switch (arg1) {
    case 4:
        self->flags &= ~4;
        self->flags |= 0x100;
        ((TBoss2DeRolLe *)self)->sub_800341F0();
        self->fB8 = 0xF;
        self->mode = 3;
        ((TBoss2DeRolLe *)self)->set_position_index(self->mode);
        fill_value_array(self->f6C8);
        self->phase = 0;
        self->timer = 0;
        self->f6E8 = 0;
        self->f6F4 = 0;
        self->speed = 0.0f;
        self->f700 = 0.0f;
        vel->x = 0.0f;
        vel->y = 0.0f;
        vel->z = 0.0f;
        self->ptcl = NULL;
        break;
    case 2:
        if (self->phase == 4) {
            if (self->count >= 4) {
                ((TBoss2DeRolLe *)self)->set_state_and_send(0x1C);
            } else {
                ((TBoss2DeRolLe *)self)->set_state_and_send(0x1B);
            }
        }
        break;
    case 9:
        if (self->phase == 4) {
            ((TBoss2DeRolLe *)self)->advance_action_sequence();
        }
        break;
    case 0:
        ((TObjMotion *)self)->advance_animation();
        self->f758 = 6;
        switch (self->phase) {
        case 0:
            self->timer++;
            if (self->timer >= 0x14) {
                self->timer = 0;
                self->phase = 1;
                fill_value_array(self->f6C8);
                self->fB8 = 0xD;
                if (((TObjEneDD_ST *)self)->enemy_check_target_valid() != 0) {
                    VCOPY(vel, self->target + 0x38);
                } else {
                    vel->x = 0.0f;
                    vel->y = 0.0f;
                    vel->z = 0.0f;
                }
                ((TBoss2DeRolLe *)self)->calc_offset_position();
                ((TBoss2DeRolLe *)self)->activate_laser_light();
                ((int (*)(int, void *))play_sound)(0x4003A809, self->snd);
            }
            break;
        case 1:
            if (self->count != 0 && TObjEneDD::check_v2_mode() != 0) {
                self->frame = 13.0f;
            }
            if (self->frame <= 12.0f) {
                if (self->ptcl == NULL) {
                    self->ptcl = spawn_continuous_particle_effect_with_flags(&self->pos, 0x122, 0x40);
                    if (self->ptcl != NULL) {
                        ((TParticleCtrl *)(self->ptcl))->enable();
                    }
                } else {
                    Vec a;
                    VCOPY(&a, &self->pos);
                    a.x += 2.0f * (5.0f * self->dir.x);
                    a.y += 5.0f * self->dir.y;
                    a.z += 5.0f * self->dir.z;
                    ((TParticleCtrl *)self->ptcl)->set_position(&a);
                }
            } else if (self->ptcl != NULL) {
                ((TObject *)self->ptcl)->queue_destruction();
                self->ptcl = NULL;
            }
            ((TBoss2DeRolLe *)self)->calc_offset_position();
            if (self->frame >= 13.0f) {
                self->frame = 13.0f;
                self->phase = 2;
                subtract_vector(vel, &self->pos);
                normalize_vector_xz((Vec *)vel);
                vel->y = 0.0f;
                self->f6F4 = RADIANS_TO_ANGLE * atan2_float(vel->x, vel->z);
                self->speed = 80.0f;
                spawn_particle_effect_with_flags(&self->pos, 0x126, 0x40);
            }
            break;
        case 2: {
            f32 k;
            f32 dist;
            f32 s;
            u8 *col;
            self->frame = 13.0f;
            self->speed += 30.0f;
            if (self->ptcl == NULL) {
                self->ptcl = spawn_continuous_particle_effect_with_flags(&self->pos, 0x177, 0x40);
                if (self->ptcl != NULL) {
                    ((TParticleCtrl *)(self->ptcl))->enable();
                }
            } else {
                Vec b;
                VCOPY(&b, &self->pos);
                b.x += 2.0f * (5.0f * self->dir.x);
                b.y += 5.0f * self->dir.y;
                b.z += 5.0f * self->dir.z;
                ((TParticleCtrl *)self->ptcl)->set_position(&b);
            }
            {
                Vec e;
                Vec c;
                Vec p;
                Vec d;
                f32 h;
                f32 dy;
                f32 t;
                hit = &self->hit;
                h = self->pos.y;
                dy = -10.0f - h;
                e.x = vel->x * self->speed;
                e.y = dy;
                e.z = vel->z * self->speed;
                t = (10.0f - h) / dy;
                c.x = e.x * t;
                c.y = dy * t;
                c.z = e.z * t;
                VADD(&c, &self->pos);
                VCOPY(hit, &e);
                VADD(hit, &self->pos);
                self->f700 += 5.0f;
                if (self->f700 >= 20.0f) {
                    self->f700 -= 20.0f;
                }
                s = self->f700;
                VCOPY(&p, &self->pos);
                VCOPY(&d, hit);
                subtract_vector(&d, &p);
                dist = normalize_vector_safe(&d);
                p.x += d.x * s;
                p.y += d.y * s;
                p.z += d.z * s;
                k = 20.0f;
                d.x *= k;
                d.y *= k;
                d.z *= k;
                for (; dist > s; s += k) {
                    spawn_particle_effect_with_flags(&p, 0x176, 0x40);
                    VADD(&p, &d);
                }
                col = csnVector(&c, hit, 0x16EF);
                if (col != NULL) {
                    VCOPY(hit, *(void **) (col + 4));
                    if (self->laser1 == NULL) {
                        self->laser1 = new TUnk_80482C58((TObject *)self, 6, 0x124);
                    } else {
                        ((TUnk_80482C58 *)self->laser1)->push_ring_point(hit);
                    }
                    if (self->laser2 == NULL) {
                        self->laser2 = new TUnk_80482C58((TObject *)self, 0xF, 0x125);
                    } else {
                        ((TUnk_80482C58 *)self->laser2)->push_ring_point(hit);
                    }
                }
                {
                    DeRolLeEffectParams r = derolle_laser_hit_effect_params;
                    r.pad_04 = *(f32 *) TBoss2DeRolLe__data_805D4BA0;
                    TObjEneDD::setup_instance((saddr)self, (saddr)hit, (u8 *)&r, self->f6C8);
                }
            }
            ((int (*)(int, void *, void *))spawn_trap__13TBoss2DeRolLeFPvii)(0x4003B00A, self, hit);
            if (self->speed >= 500.0f) {
                self->speed = 500.0f;
                self->phase = 3;
                if (self->ptcl != NULL) {
                    ((TObject *)self->ptcl)->queue_destruction();
                    self->ptcl = NULL;
                }
            }
            break;
        }
        case 3:
            if (TObjEneDD::check_v2_mode() != 0) {
                self->phase = 4;
            }
            if (((TObjEneDD *)self)->get_flag_b4() != 0) {
                self->phase = 4;
            }
            break;
        }
        break;
    case 6:
        ((TBoss2DeRolLe *)(saddr) self)->pick_random_target();
        break;
    case 5:
        self->count++;
        ((TBoss2DeRolLe *)self)->free_laser();
        if (self->ptcl != NULL) {
            ((TObject *)self->ptcl)->queue_destruction();
            self->ptcl = NULL;
        }
        if (self->laser1 != NULL) {
            ((TObject *)self->laser1)->queue_destruction();
            self->laser1 = NULL;
        }
        if (self->laser2 != NULL) {
            ((TObject *)self->laser2)->queue_destruction();
            self->laser2 = NULL;
        }
        break;
    }
}

#pragma pop

#undef VADD
#undef VCOPY

}

}

void TBoss2DeRolLe::sub_8002FD9C(u32 reason, s32 arg2) {
    switch (reason) {
    case 4:
        state_flags &= ~4;
        state_flags |= 0x100;
        requested_action = 0xE;
        sub_800341F0();
        position_index = 3;
        set_position_index(position_index);
        if (arg2 != 0) {
            TObjBoss2Tunnel::set_global_flag_800();
        }
        break;
    case 2:
        if (requested_action == 1) {
            set_state_and_send(2);
        }
        break;
    case 9:
        if (requested_action == 1) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        break;
    }
}

void TBoss2DeRolLe::sub_8002FCE4(u32 reason) {
    switch (reason) {
    case 4:
        state_flags = state_flags | 4;
        state_flags = state_flags & 0xFFFFFEFF;
        sub_80034258();
        rotation_x = 0;
        unk_6A4 = 0.0f;
        return;
    case 9:
        if (requested_action == 1) {
            advance_action_sequence();
        }
        break;
    case 8:
        if (unk_6A4 < -200.0f) {
            set_state_and_send(0x1F);
            return;
        }
        break;
    case 0:
        unk_6A4 = unk_6A4 - 2.0f;
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
    }
}

namespace behavior_view {

extern "C" {

#pragma push
#pragma fp_contract on
#pragma opt_common_subs off

#define o ((Rol_8002F7C4 *)arg0)

void handle_death_state__13TBoss2DeRolLeFPvPv(void *arg0, void *arg1) {
    CameraPlayback cam;
    Vec v;
    Vec w;
    Vec save;
    s32 i;
    f32 t;
    switch ((uaddr)arg1) {
    case 4:
        o->f3C0 &= ~0x100;
        o->f3C0 |= 4;
        ((TBoss2DeRolLe *)o)->sub_80034258();
        o->fB8 = 0x10;
        o->f654 = 3;
        ((TBoss2DeRolLe *)o)->set_position_index(o->f654);
        o->f5C = 0;
        o->f6A4 = 0.0f;
        o->f6E0 = 0;
        o->f6E4 = 0;
        o->f6F4 = 0;
        o->f6AC = 0;
        for (i = 0; i < 4; i++) {
            ((TBoss2Tentacle *)o->tent[i])->speed_up_sway();
        }
        TWindowCtrl::init_all_slots();
        cam.index = 0;
        cam.bank = 2;
        cam.flags = 0;
        cam.frame = 0.0f;
        cam.frame_step = 0.7f;
        ((s32 (*)(int, f32))activate_camera_mode)(5, 0.0f);
        cam.cache_target_and_forward(0x2AAA);
        set_scripted_camera_pose(&o->pos, &o->pos, &o->f5C);
        break;
    case 2:
        if (o->f3CC->f8 & 0x400) {
            o->flags30 &= ~0x800;
            ((TBoss2DeRolLe *)o)->sub_800341F0();
            ((TBoss2DeRolLe *)o)->set_state_and_send(2);
        }
        break;
    case 9:
        if (o->f6E0 == 3) {
            ((TBoss2DeRolLe *)o)->set_state_and_send(0x20);
        }
        break;
    case 0:
        ((TObjMotion *)o)->advance_animation();
        switch (o->f6E0) {
        case 0:
            if (((TObjMotion *)o)->is_passing_frame(27.0f) != 0) {
                play_cue_stream_file((saddr)"deldeath.adx");
            } else if (((TObjMotion *)o)->is_passing_frame(20.0f) != 0) {
                play_sound_effect((void *)0x4003AD11, 0, 0, 0);
            } else if (((TObjMotion *)o)->is_passing_frame(99.0f) != 0) {
                play_sound_effect((void *)0x4003AD12, 0, 0, 0);
                start_pad_rumble_all(0xC0, 0xF);
            }
            o->f6E4++;
            t = o->fC0;
            if (t >= 20.0f && t <= 28.0f) {
                if ((f32)o->f6E4 >= 2.0f) {
                    o->f6E4 = 0;
                    ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v, &o->pos);
                    for (i = 0; i < 10; i++) {
                        u8 *q = (u8 *)o + i * 12;
                        if (v.y * *(f32 *)(q + 0x544) < 0.0f) {
                            break;
                        }
                        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&v, q + 0x540);
                    }
                    v.x += 40.0f * ((TObjEneDD *)o)->calc_elapsed_scaled();
                    v.y = -5.0f;
                    v.z += 80.0f * ((TObjChara *)o)->random_ratio();
                    ((TBoss2DeRolLe *)o)->spawn_ceil_junk(&v);
                }
            } else if (t >= 99.0f && t <= 140.0f && (f32)o->f6E4 >= 2.0f) {
                o->f6E4 = 0;
                ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&w, &o->pos);
                w.x += 40.0f * ((TObjEneDD *)o)->calc_elapsed_scaled() + 20.0f;
                w.y = -5.0f;
                w.z += 40.0f * ((TObjEneDD *)o)->calc_elapsed_scaled() + 20.0f;
                ((TBoss2DeRolLe *)o)->spawn_ceil_junk(&w);
            }
            if (o->fC0 >= 20.0f) {
                o->f758 = 5;
            }
            if (o->fC0 > 100.0f) {
                o->f6E0 = 2;
            }
            break;
        case 1:
            o->f6F4 += 0x400;
            o->f6A4 = 0.5f * (6.0f * (cos_table_lookup(o->f6F4) - 1.0f));
            break;
        case 2:
            o->f6A4 -= 1.0f;
            if (o->f6A4 < -100.0f) {
                o->f6E0 = 3;
                TWindowCtrl::init_all_slots2();
                restore_player_cameras();
            }
            break;
        }
        break;
    case 1:
        break;
    case 3:
        break;
    case 5:
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&save, &o->pos);
        o->pos.x = -55.8f;
        o->pos.y = 2.0f;
        o->pos.z = 60.29f;
        ((TObjEnemy *)o)->update_prev_position();
        for (i = 0; i != 10; i++) {
            assign_slots_from_list(o, o->slots[i]);
        }
        ((TObjEnemy *)o)->refresh_and_send_entity_flags();
        set_story_flag_or_send_quest_flag((u16)((void *)0x20));
        ((void (*)(void *, void *))VecCopy__FP3VecPC3Vec)(&o->pos, &save);
        ((TObjEnemy *)o)->update_prev_position();
        o->flags30 = 0x12008;
        o->m72(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    }
}

#pragma pop

#undef o

}

}

void TBoss2DeRolLe::sub_8002F73C(u32 reason) {
    switch (reason) {
    case 4:
        requested_action = 0x10;
        sub_80034258();
        state_flags = state_flags | 4;
        state_flags = state_flags & 0xFFFFFEFF;
        TObjBoss2Tunnel::set_global_flag_200();
        if (TObjBoss2Tunnel::is_active() != 0) {
            TObjBoss2Tunnel::set_global_flag_800();
        }
        break;
    case 0:
        queue_destruction();
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
    }
}

namespace behavior_view {


}


namespace joint_transform_view {

extern "C" {

void TObjPlayer__sub_8002F61C(NJS_OBJECT *) {
    if ((s32) TBoss2DeRolLe__current_attack_id == derolle_attack_sequence_id_table[TBoss2DeRolLe__sequence_match_index]) {
        forward_transform_to_view((const Vec *)&lbl_804FE31C.value, (Vec *)lbl_805D4BB4);
        TBoss2DeRolLe__sequence_match_index += 1;
        lbl_805D4BB4 += 0xC;
    }
    if ((s32) TBoss2DeRolLe__current_attack_id == 0x33) {
        push_matrix();
        forward_split_screen_view_matrix();
        matrix_mult_vec_array(0, derolle_part_transform_template, (void *)lbl_805D4BB8, 4);
        pop_matrix();
        subtract_vector((void *)(lbl_805D4BB8 + 0xC), (void *)lbl_805D4BB8);
    }
    if ((lbl_805D4BB0 & 0x80) && ((s32) TBoss2DeRolLe__current_attack_id >= 0x4D) && ((s32) TBoss2DeRolLe__current_attack_id <= 0x58)) {
        push_matrix();
        forward_split_screen_view_matrix();
        get_current_matrix((void *)lbl_805D4BC0);
        pop_matrix();
        lbl_805D4BC0 += 0x30;
    }
    if (((s32) TBoss2DeRolLe__current_attack_id >= 0x1D) && ((s32) TBoss2DeRolLe__current_attack_id <= 0x20)) {
        push_matrix();
        forward_split_screen_view_matrix();
        get_current_matrix((void *)lbl_805D4BBC);
        pop_matrix();
        lbl_805D4BBC += 0x30;
    }
    TBoss2DeRolLe__current_attack_id += 1;
}

}

}

void fn_8002F5AC(u8 *arg0) {
    TBoss2DeRolLe__current_attack_id = 0;
    copy_argb((NJS_ARGB *)&lbl_804FE30C.value, (NJS_ARGB *)(arg0 + 0x608));
    lbl_805D4BB0 = *(s32 *)((s8 *)arg0 + 0x3C0);
    TBoss2DeRolLe__sequence_match_index = 0;
    lbl_805D4BB4 = arg0 + 0x3F8;
    lbl_805D4BBC = *(s32 *)((s8 *)arg0 + 0x61C);
    lbl_805D4BC0 = *(s32 *)((s8 *)arg0 + 0x618);
    lbl_805D4BB8 = arg0 + 0x4E8;
}

extern "C" {

void copy_argb(NJS_ARGB *dst, NJS_ARGB *src) {
    dst->a = src->a;
    dst->r = src->r;
    dst->g = src->g;
    dst->b = src->b;
}

void TBoss2DeRolLe::render() {
    Me_8002F258 *e = (Me_8002F258 *)this;
    Vec4_8002F258 *col;
    s32 i;
    Vec *out;

    if (this->get_target_info() != 0) {
        e->m104();
        return;
    }
    e->m8(1000.0f, 1000.0f);
    saved_model_render_flags = model_render_flags;
    saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
    saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
    TObjEneDD::clear_global_flag_400();
    TParticleCtrl::begin_effect_render();
    push_matrix();
    post_translate_matrix(&e->pos);
    translate_matrix(0, 0.0f, e->height, 0.0f);
    rotate_matrix_y(0, e->ry);
    rotate_matrix_x(0, e->rx);
    rotate_matrix_z(0, e->rz);
    {
        Vec sc = {2.0f, 2.0f, 2.0f};
        scale_current_matrix(&sc);
    }
    update_pulsing_colors();
    for (i = 0; i < 10; i++) {
        ((TBoss2Joint *)e->joints[i])->apply_flash_color();
    }
    if (e->flags & 0x40) {
        derolle_texture_list_handle->tex = derolle_segment_texture_slots;
    } else {
        derolle_texture_list_handle->tex = lbl_805D4BCC;
    }
    fn_8002F5AC(((u8 *)this));
    TObjFish::set_global_param(e->f24);
    set_chunk_model_node_callback(TObjPlayer__sub_8002F61C);
    {
    Vec4_8002F258 saved;
    col = &TObjLight__scene_light_state.col;
    copy_argb((NJS_ARGB *)&saved, (NJS_ARGB *)col);
    if (TObjBoss2Tunnel::is_active() != 0) {
        TObjLight__scene_light_state.col.y = 0.3f;
        TObjLight__scene_light_state.col.z = 0.4f;
        TObjLight__scene_light_state.col.w = 0.5f;
        TObjLight__sub_8013379C(current_scene_light, &TObjLight__scene_light_state);
        TObjLight__sub_801336DC(lbl_805D5564);
    }
    this->draw();
    copy_argb((NJS_ARGB *)col, (NJS_ARGB *)&saved);
    }
    set_chunk_model_node_callback(NULL);
    TObjLight__sub_801337F8(current_scene_light);
    pop_matrix();
    chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
    chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
    model_render_flags = saved_model_render_flags;
    TParticleCtrl::end_effect_render();
    {
    Vec v;
    out = e->mids;
    VecCopy__FP3VecPC3Vec(&v, &e->pts[0]);
    vec3_add_to(&v, &e->pts[9]);
    v.x *= 0.5f;
    v.y *= 0.5f;
    v.z *= 0.5f;
    VecCopy__FP3VecPC3Vec(out, &v);
    VecCopy__FP3VecPC3Vec(&v, &e->pts[9]);
    vec3_add_to(&v, &e->pts[11]);
    v.x *= 0.5f;
    v.y *= 0.5f;
    v.z *= 0.5f;
    VecCopy__FP3VecPC3Vec(out + 1, &v);
    out += 2;
    for (i = 0; i < 8; i++) {
        VecCopy__FP3VecPC3Vec(&v, &e->pts[i + 11]);
        vec3_add_to(&v, &e->pts[i + 12]);
        v.x *= 0.5f;
        v.y *= 0.5f;
        v.z *= 0.5f;
        VecCopy__FP3VecPC3Vec(out, &v);
        out++;
    }
    }
    ((TObject *)(e->nodes))->render_nodes();
}

int TBoss2DeRolLe::vfunc_105() { return this->get_target_info(); }

#pragma push
#pragma opt_common_subs off

void TBoss2DeRolLe::render_body() {
    Self_8002EFE8 *self = (Self_8002EFE8 *)this;
    s32 i;
    Model_8002EFE8 *model;
    s32 idx;
    f32 frame;
    f32 max;
    this->update_object_view_visibility(1000.0f, 1000.0f);
    saved_model_render_flags = model_render_flags;
    TObjEneDD::clear_global_flag_400();
    push_matrix();
    post_translate_matrix(self->pos);
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, this->rotation_x);
    rotate_matrix_z(0, this->rotation_z);
    Vec scale = {2.0f, 2.0f, 2.0f};
    TObjEneDD::check_v2_mode();
    scale_current_matrix(&scale);
    for (i = 0; i < 10; i++) {
        ((TBoss2Joint *)self->joints[i])->apply_flash_color();
    }
    idx = self->motionIdx;
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 0x11) {
        idx = 0x10;
    }
    model = self->anims[self->motions[idx].anim].model;
    if (test_previous_buttons_packed(&controller_input_state.controllers[2], 4) != 0) {
        max = model->frames - 1;
        this->frame = this->frame + self->speed;
        while (this->frame < 0.0f) {
            this->frame = this->frame + max;
        }
        while (this->frame > max) {
            this->frame = this->frame - max;
        }
        frame = this->frame;
    } else {
        frame = self->fixedFrame;
        if (frame < 0.0f) {
            frame = 0.0f;
        } else if (frame > (model->frames - 1)) {
            frame = model->frames;
        }
    }
    fn_8002F5AC((u8 *)self);
    set_chunk_model_node_callback(TObjPlayer__sub_8002F61C);
    TObjFish::set_global_param(this->texlist);
    draw_model_motion((void *)self->x34, (void *)model, (f32)frame);
    set_chunk_model_node_callback(NULL);
    TObjLight__sub_801337F8(current_scene_light);
    pop_matrix();
}

}

#pragma pop
