#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleFactory.h"

#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/particle/TParticleCtrl_800867E4.h"

#include "pso/animation/MotionContext.h"
#include "pso/unk/text_803D853C.h"

struct NJS_OBJECT;

#include "pso/math/FloatRounding.h"

#include "pso/enemy/TObjEnemy.h"

#include "pso/system/NinjaTypes.h"

#include "types.h"
#include <string.h>

#include "pso/camera/CameraPlayback.h"

#include "pso/render/NinjaUtil.h"

#include "pso/ui/hud/TRaderMapCore.h"

#include "pso/object/base/TObjMotion.h"

#include "pso/boss/barbaray/TBoss7PhotonBullet.h"

#include "pso/boss/barbaray/TBoss7Tentacle.h"

#include "pso/effect/particle/TParticleCtrl.h"

#include "pso/boss/volopt/TBoss3Volopt.h"

#include "pso/boss/darkfalz/TBoss4DarkFalz.h"

#include "pso/boss/darkfalz/TBoss4Type2.h"

#include "pso/boss/barbaray/TBoss7Joint.h"

#include "pso/boss/barbaray/TBoss7LaserPtcl.h"
#include "pso/map/CsnQuery.h"
#include "pso/boss/TUnk_804F1C88.h"
#include "pso/network/protocol/subcmd_6x.h"
#include "pso/boss/barbaray/TBoss7TentacleNeedle.h"

#include "pso/boss/barbaray/TBoss7LaserLight.h"

#include "pso/object/TUnk_804E4788.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"

#include "pso/boss/derolle/TObjBoss2Tunnel.h"

#include "pso/enemy/dd/TObjEneDD.h"

#include "pso/enemy/dd/TObjEneDD_ST.h"

#include "pso/camera/TCameraCtrl.h"

#include "pso/unk/TLobby.h"

#include "pso/ui/hud/TNowLoading.h"

#include "pso/ui/window/TWindowCtrl.h"

#include "pso/object/ambient/TObjFish.h"

#include "pso/player/TObjPlayer.h"

#include "pso/boss/barbaray/TBoss7DeRolLeC.h"

#include "pso/enemy/TObjEnemyCustom.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"

// Load and release hooks run by run_load_callback_table / call_funcs_reverse.
struct Boss7LoadCallback {
    void (*load)(void);
    void (*release)(void);
};

// What TObjEnemy::movementParameters points at.
struct TBoss7DeRolLeCMovement {
    EnemyMoveParams move;
    s32 unk_0C[4];
};

// The BML resource descriptor, followed by the action table that
// TBoss7DeRolLeC's constructor hands to set_field_d8.
extern Boss7LoadCallback lbl_804E3C5C[6];
extern TBoss7DeRolLeCMovement lbl_804E3C8C;
extern BmlResourceDescriptor bm_boss7_de_rol_le_c_resource_descriptor;
extern TObjMotionAction de_rol_le_c_action_table[17];

#include "pso/boss/barbaray/TBoss7Crawfish.h"

#include "pso/boss/barbaray/TBoss7Crawfish_8030908C.h"


#include "pso/system/task/TObject.h"

#include "pso/system/vector.h"

#include "pso/boss/barbaray/TBoss7PhotonPad.h"

#include <stddef.h>

#include "pso/player/TObjPlayer_801AF2F0.h"

#include "pso/math/AngleLookup.h"

#include "pso/unk/text_80087278.h"

#include "pso/unk/text_803D96A8.h"

#include "pso/effect/particle/TParticleCtrl_800874F4.h"

#include "pso/object/base/TObjChara.h"

#include "pso/player/TObjPlayer_803E4954.h"

#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/SoundEffect.h"
#include "pso/object/trap/TOTrapAncient01_80226534.h"

#include "pso/system/task/TObject_80019A50.h"

#include "pso/boss/goldragon/TBoss8Dragon_800BC53C.h"

#include "pso/enemy/dd/TObjEneDD_800B9A34.h"

#include "pso/enemy/AttackTargetHistory.h"

#include "pso/unk/TUnk_804F1C58.h"

#include "pso/system/BmlResource.h"

#include "pso/object/ambient/TObjFish_8001ED90.h"

#include "pso/system/task/TMainTask.h"

// Action step of a De Rol Le C attack pattern: action id and its duration in
// seconds (the timer compares against b * 30).
struct Ent_802E88F8 { s32 a; s32 b; };

// Attack/effect parameter record passed to TObjEneDD::emit_effect /
// setup_instance (type name inferred; same shape as TBoss1Dragon's).
struct Boss7AttackParams {
    s32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_C;
    s32 field_10;
};

extern const s32 lbl_80472CB0[21] = {0x18, 0x1a, 0x1c, 0x1d, 0x1e, 0x1f, 0x22, 0x45, 0x4a, 0x5f, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, -1};

extern const Vec lbl_80472D04[10] = {
    {-175.0f, 7.0f, 25.0f},
    {0.0f, 7.0f, 500.0f},
    {175.0f, 7.0f, 25.0f},
    {0.0f, 7.0f, -250.0f},
    {0.0f, 7.0f, 25.0f},
    {-205.0f, -100.0f, 25.0f},
    {0.0f, -100.0f, 530.0f},
    {205.0f, -100.0f, 25.0f},
    {0.0f, -100.0f, -280.0f},
    {0.0f, -100.0f, 25.0f}
};

extern const Boss7AttackParams lbl_80472D7C = {0, 0.0f, 8.0f, 5.0f, 1};

extern const Boss7AttackParams boss7_laser_particle_params = {0, 120.0f, 16.0f, 20.0f, 1};

extern const Ent_802E88F8 lbl_80472DA4[68] = {
    {1, 0}, {3, 0}, {8, 0}, {15, 0}, {3, 0}, {40, 0}, {60, 0}, {50, 0},
    {68, 0}, {57, 0}, {61, 0}, {41, 0}, {17, 0}, {63, 10}, {21, 0}, {17, 0},
    {63, 7}, {21, 0}, {40, 0}, {59, 0}, {54, 0}, {68, 0}, {55, 0}, {41, 0},
    {16, 0}, {18, 0}, {63, 10}, {22, 0}, {18, 0}, {63, 7}, {22, 0}, {58, 0},
    {10, 0}, {40, 0}, {47, 0}, {61, 0}, {41, 0}, {61, 0}, {23, 0}, {24, 0},
    {24, 0}, {25, 0}, {13, 0}, {40, 0}, {60, 0}, {50, 0}, {68, 0}, {55, 0},
    {59, 0}, {58, 0}, {41, 0}, {16, 0}, {18, 0}, {63, 10}, {22, 0}, {10, 0},
    {15, 0}, {17, 0}, {63, 10}, {21, 0}, {59, 0}, {5, 0}, {23, 0}, {24, 0},
    {24, 0}, {25, 0}, {13, 0}, {69, 0},
};

extern const Ent_802E88F8 lbl_80472FC4[87] = {
    {1, 0}, {3, 0}, {6, 0}, {16, 0}, {40, 0}, {58, 1}, {56, 0}, {68, 0},
    {57, 0}, {59, 2}, {41, 0}, {15, 0}, {17, 0}, {63, 3}, {21, 0}, {17, 0},
    {63, 3}, {21, 0}, {59, 3}, {17, 0}, {63, 1}, {21, 0}, {40, 0}, {59, 3},
    {54, 0}, {59, 1}, {68, 0}, {55, 0}, {58, 1}, {41, 0}, {16, 0}, {18, 0},
    {63, 3}, {22, 0}, {18, 0}, {63, 3}, {22, 0}, {58, 3}, {18, 0}, {63, 1},
    {22, 0}, {10, 0}, {40, 0}, {47, 0}, {61, 2}, {41, 0}, {61, 3}, {23, 0},
    {24, 0}, {24, 0}, {25, 0}, {13, 0}, {40, 0}, {60, 1}, {50, 0}, {68, 0},
    {55, 0}, {60, 2}, {61, 2}, {41, 0}, {16, 0}, {18, 0}, {63, 2}, {22, 0},
    {58, 4}, {18, 0}, {63, 2}, {22, 0}, {10, 0}, {15, 0}, {17, 0}, {63, 2},
    {21, 0}, {59, 4}, {17, 0}, {63, 2}, {21, 0}, {59, 3}, {5, 0}, {61, 3},
    {23, 0}, {24, 0}, {24, 0}, {25, 0}, {61, 3}, {13, 0}, {69, 0},
};

extern const Ent_802E88F8 lbl_8047327C[88] = {
    {1, 0}, {3, 0}, {8, 0}, {15, 0}, {40, 0}, {59, 3}, {54, 0}, {59, 5},
    {68, 0}, {55, 0}, {58, 3}, {41, 0}, {16, 0}, {18, 0}, {63, 3}, {22, 0},
    {58, 4}, {18, 0}, {63, 3}, {22, 0}, {59, 3}, {40, 0}, {58, 5}, {54, 0},
    {59, 1}, {68, 0}, {57, 0}, {59, 5}, {41, 0}, {15, 0}, {17, 0}, {63, 3},
    {21, 0}, {59, 4}, {17, 0}, {63, 3}, {21, 0}, {58, 5}, {17, 0}, {63, 3},
    {21, 0}, {59, 3}, {4, 0}, {40, 0}, {43, 0}, {61, 2}, {41, 0}, {60, 7},
    {23, 0}, {24, 0}, {24, 0}, {25, 0}, {13, 0}, {40, 0}, {60, 1}, {50, 0},
    {68, 0}, {55, 0}, {60, 2}, {61, 2}, {41, 0}, {16, 0}, {18, 0}, {63, 2},
    {22, 0}, {58, 4}, {18, 0}, {63, 2}, {22, 0}, {10, 0}, {15, 0}, {17, 0},
    {63, 2}, {21, 0}, {59, 4}, {17, 0}, {63, 2}, {21, 0}, {59, 2}, {5, 0},
    {61, 5}, {23, 0}, {24, 0}, {24, 0}, {25, 0}, {61, 4}, {13, 0}, {69, 0},
};

extern const Ent_802E88F8 lbl_8047353C[97] = {
    {1, 0}, {3, 0}, {6, 0}, {16, 0}, {40, 0}, {58, 3}, {56, 0}, {58, 5},
    {68, 0}, {59, 5}, {57, 0}, {59, 3}, {41, 0}, {59, 4}, {17, 0}, {63, 2},
    {21, 0}, {59, 5}, {17, 0}, {63, 2}, {21, 0}, {58, 3}, {17, 0}, {63, 0},
    {21, 0}, {40, 0}, {59, 2}, {54, 0}, {59, 8}, {68, 0}, {55, 0}, {58, 8},
    {41, 0}, {16, 0}, {18, 0}, {63, 2}, {22, 0}, {58, 4}, {18, 0}, {63, 2},
    {22, 0}, {58, 5}, {18, 0}, {63, 0}, {22, 0}, {40, 0}, {43, 0}, {61, 4},
    {41, 0}, {61, 9}, {23, 0}, {24, 0}, {24, 0}, {24, 0}, {25, 0}, {13, 0},
    {40, 0}, {60, 1}, {50, 0}, {60, 8}, {68, 0}, {55, 0}, {41, 0}, {16, 0},
    {18, 0}, {63, 2}, {22, 0}, {58, 4}, {18, 0}, {63, 2}, {22, 0}, {58, 4},
    {10, 0}, {15, 0}, {17, 0}, {63, 2}, {21, 0}, {59, 4}, {17, 0}, {63, 2},
    {21, 0}, {59, 2}, {5, 0}, {61, 4}, {62, 0}, {61, 8}, {62, 0}, {61, 9},
    {62, 0}, {23, 0}, {24, 0}, {24, 0}, {24, 0}, {25, 0}, {61, 4}, {13, 0},
    {69, 0},
};

extern const s32 lbl_80473844[10][9] = {
    1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1,
    0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
    0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 2, 0, 1, 1, 1, 1, 1, 0, 2, 0, 2,
    0, 1, 1, 2, 1, 0, 1, 1, 1, 0, 1, 2, 1, 2, 1,
    1, 2, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2,
};

extern const s32 lbl_804739AC[10] = {0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x19, 0x19, 0x19, 0x19};

extern const s32 lbl_804739D4[10] = {0x19, 0x1c, 0x1c, 0x1c, 0x1c, 0x19, 0x1c, 0x1c, 0x1c, 0x1c};

extern const Vec lbl_804739FC[9] = {
    {72.0f, 12.0f, 60.0f},
    {65.0f, 12.0f, 45.0f},
    {72.0f, 12.0f, 30.0f},
    {65.0f, 12.0f, 15.0f},
    {72.0f, 12.0f, 0.0f},
    {65.0f, 12.0f, -15.0f},
    {72.0f, 12.0f, -30.0f},
    {65.0f, 12.0f, -45.0f},
    {72.0f, 12.0f, -60.0f},
};

extern const Vec lbl_80473A68[9] = {
    {-72.0f, 12.0f, 60.0f},
    {-65.0f, 12.0f, 45.0f},
    {-72.0f, 12.0f, 30.0f},
    {-65.0f, 12.0f, 15.0f},
    {-72.0f, 12.0f, 0.0f},
    {-65.0f, 12.0f, -15.0f},
    {-72.0f, 12.0f, -30.0f},
    {-65.0f, 12.0f, -45.0f},
    {-72.0f, 12.0f, -60.0f},
};

extern const Vec lbl_80473AD4[9] = {
    {50.0f, 12.0f, 75.0f},
    {37.5f, 12.0f, 65.0f},
    {25.0f, 12.0f, 75.0f},
    {12.5f, 12.0f, 65.0f},
    {0.0f, 12.0f, 75.0f},
    {-12.5f, 12.0f, 65.0f},
    {-25.0f, 12.0f, 75.0f},
    {-37.5f, 12.0f, 65.0f},
    {-50.0f, 12.0f, 75.0f},
};

extern const Vec lbl_80473B40[9] = {
    {50.0f, 12.0f, -95.0f},
    {37.5f, 12.0f, -85.0f},
    {25.0f, 12.0f, -95.0f},
    {12.5f, 12.0f, -85.0f},
    {0.0f, 12.0f, -95.0f},
    {-12.5f, 12.0f, -85.0f},
    {-25.0f, 12.0f, -95.0f},
    {-37.5f, 12.0f, -85.0f},
    {-50.0f, 12.0f, -95.0f},
};

extern const s32 lbl_80473BAC[9] = {0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000};

extern const s32 lbl_80473BD0[9] = {0x4000, 0x4000, 0x4000, 0x4000, 0x4000, 0x4000, 0x4000, 0x4000, 0x4000};

extern const s32 lbl_80473BF4[9] = {0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000};

extern const s32 lbl_80473C18[9] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

extern const CollisionBody lbl_80473C3C = {{0.0f, 0.0f, 0.0f}, 25.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f};

extern const char boss7_de_rol_le_c_model_name_boss2_b_derorure_body_nj[] = "boss2_b_derorure_body.nj";

extern const char boss7_de_rol_le_c_model_name_boss2_b_derorure_tentacle_nj[] = "boss2_b_derorure_tentacle.nj";

extern const char boss7_de_rol_le_c_model_name_boss2_b_helm_break_nj[] = "boss2_b_helm_break.nj";

extern const char boss7_de_rol_le_c_model_name_boss2_b_shell_break_nj[] = "boss2_b_shell_break.nj";

extern const char lbl_80473CD4[] = "ikada_h_hahen.gj";

extern const char boss7_de_rol_le_c_model_name_hige_at01_tentacle_nj[] = "hige_at01_tentacle.nj";

extern const char boss7_de_rol_le_c_motion_name_beam02_boss2_b_body_njm[] = "beam02_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_beamwait_boss2_b_body_njm[] = "beamwait_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_beam_a_boss2_b_body_njm[] = "beam_a_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_beam_b_boss2_b_body_njm[] = "beam_b_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_beam_c_boss2_b_body_njm[] = "beam_c_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_bite_lloop_boss2_b_body_njm[] = "bite_lloop_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_bite_rloop_boss2_b_body_njm[] = "bite_rloop_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_ed_boss2_b_derorure_body_njm[] = "ed_boss2_b_derorure_body.njm";

extern const char boss7_de_rol_le_c_motion_name_op_boss2_b_derorure_body_njm[] = "op_boss2_b_derorure_body.njm";

extern const char boss7_de_rol_le_c_motion_name_fd02_boss2_b_body_njm[] = "fd02_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_fjump_boss2_b_body_njm[] = "fjump_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_forward_boss2_b_body_njm[] = "forward_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_lrjump_boss2_b_body_njm[] = "lrjump_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_l_bite_boss2_b_body_njm[] = "l_bite_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_rljump_boss2_b_body_njm[] = "rljump_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_r_bite_boss2_b_body_njm[] = "r_bite_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_scatter_boss2_b_body_njm[] = "scatter_boss2_b_body.njm";

extern const char boss7_de_rol_le_c_motion_name_tloop_boss2_b_tentacle_njm[] = "tloop_boss2_b_tentacle.njm";

extern const char boss7_de_rol_le_c_motion_name_hige_down_hige_down_tentacle_njm[] = "hige_down_hige_down_tentacle.njm";

extern const char boss7_de_rol_le_c_motion_name_hige_up_hige_up_tentacle_njm[] = "hige_up_hige_up_tentacle.njm";

extern const char boss7_de_rol_le_c_motion_name_hige_wait_hige_wait_tentacle_njm[] = "hige_wait_hige_wait_tentacle.njm";

extern const char bm_boss7_de_rol_le_c_bml_filename[] = "bm_boss7_de_rol_le_c.bml";

extern const char TBoss7DeRolLeC__class_name_string[] = "TBoss7DeRolLeC";

const char *TBoss7DeRolLeC__class_name = TBoss7DeRolLeC__class_name_string;

extern const Vec lbl_80473F6C = {10000.0f, 10000.0f, 10000.0f};

extern const Vec lbl_80473F78 = {0.0f, 0.0f, -600.0f};

extern const Vec lbl_80473F84 = {0.0f, 0.0f, -275.0f};

extern const Vec lbl_80473F90 = {0.0f, 0.0f, -520.0f};


extern const Boss7Angles lbl_80473F9C = {0, 0, 0};

extern s32 game_difficulty_selection;

Vec lbl_804E3BF0 = {2.5f, 2.5f, 2.5f};

Vec lbl_804E3BFC[4] = {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 4.0f}, {0.0f, 0.0f, 13.0f}};

// Action sequences per difficulty, then the crawfish spawn positions and
// y angles per spawn pattern variant.
const Ent_802E88F8 *lbl_804E3C2C[4] = {lbl_80472DA4, lbl_80472FC4, lbl_8047327C, lbl_8047353C};

const Vec *lbl_804E3C3C[4] = {lbl_804739FC, lbl_80473A68, lbl_80473AD4, lbl_80473B40};

const s32 *lbl_804E3C4C[4] = {lbl_80473BAC, lbl_80473BD0, lbl_80473BF4, lbl_80473C18};
extern "C" {

void TObjPlayer__sub_802E7470(void);

void TObjPlayer__sub_802E7084(void);

void TObjPlayer__sub_802E7088(void);

void TObjPlayer__sub_802E746C(void);

}

Boss7LoadCallback lbl_804E3C5C[6] = {
    {TBoss7Tentacle::load_static_resource, TBoss7Tentacle::destroy_instance},
    {TObjPlayer__sub_802E7470, TObjPlayer__sub_802E7084},
    {TObjPlayer__sub_802E7088, TObjPlayer__sub_802E746C},
    {TBoss7Crawfish::load_static_resource, TBoss7Crawfish::destroy_instance},
    {TBoss7TentacleNeedle::load_static_resource, TBoss7TentacleNeedle::destroy_instance},
    {TUnk_804F1C88::load_static_resource, TUnk_804F1C88::destroy_instance},
};

TBoss7DeRolLeCMovement lbl_804E3C8C = {{225.0f, 0.0f, 0x600}, {0, 0, 0, 0}};

const char *bm_boss7_de_rol_le_c_model_names[7] = {
    boss7_de_rol_le_c_model_name_boss2_b_derorure_body_nj,
    boss7_de_rol_le_c_model_name_boss2_b_derorure_tentacle_nj,
    boss7_de_rol_le_c_model_name_boss2_b_helm_break_nj,
    boss7_de_rol_le_c_model_name_boss2_b_shell_break_nj,
    lbl_80473CD4,
    boss7_de_rol_le_c_model_name_hige_at01_tentacle_nj,
    NULL,
};

const char *bm_boss7_de_rol_le_c_motion_names[22] = {
    boss7_de_rol_le_c_motion_name_beam02_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_beamwait_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_beam_a_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_beam_b_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_beam_c_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_bite_lloop_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_bite_rloop_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_ed_boss2_b_derorure_body_njm,
    boss7_de_rol_le_c_motion_name_op_boss2_b_derorure_body_njm,
    boss7_de_rol_le_c_motion_name_fd02_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_fjump_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_forward_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_lrjump_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_l_bite_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_rljump_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_r_bite_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_scatter_boss2_b_body_njm,
    boss7_de_rol_le_c_motion_name_tloop_boss2_b_tentacle_njm,
    boss7_de_rol_le_c_motion_name_hige_down_hige_down_tentacle_njm,
    boss7_de_rol_le_c_motion_name_hige_up_hige_up_tentacle_njm,
    boss7_de_rol_le_c_motion_name_hige_wait_hige_wait_tentacle_njm,
    NULL,
};

BmlResourceDescriptor bm_boss7_de_rol_le_c_resource_descriptor = {
    bm_boss7_de_rol_le_c_bml_filename, bm_boss7_de_rol_le_c_model_names, bm_boss7_de_rol_le_c_motion_names, 6, 21,
};

TObjMotionAction de_rol_le_c_action_table[17] = {
    {3, 0, 8, 0.7f, ACTION_NO_BLEND_IN | ACTION_NO_BLEND_OUT},
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

s32 particle_pos_index_table[3] = {0, 5, 9};

f32 lbl_804E3E48[3] = {32.0f, 30.0f, 30.0f};

extern "C" {
f32 atan2_float(f32 y, f32 x);

f32 newton_sqrtf(f32);

f32 subtract_vector(void *, void *);



}

extern "C" {
s32 VecCopy__FP3VecPC3Vec(int, void *);


}



extern "C" {





u16 get_entity_id(void *);




// The set entry a crawfish spawned by De Rol Le C is built from (layout from
// the stores below; position and rotation as TObjMotion reads them).
struct Boss7CrawfishSetData {
    s16 set_index;
    s16 unk_02;
    s16 unk_04;
    u16 entity_id;
    s16 room;
    s16 unk_0A;
    s16 unk_0C;
    s16 unk_0E;
    Vec position;
    Boss7Angles rotation;
    f32 unk_28;
    f32 unk_2C;
    f32 unk_30;
    f32 unk_34;
    f32 unk_38;
    s16 unk_3C;
    s16 unk_3E;
};

// Spawns a crawfish in child slot `slot` unless one with that entity id is
// already alive.
struct CrawfishSlotOffset { s16 value; };
#pragma push
#pragma inline_depth(4)
static inline void add_crawfish_slot_base(CrawfishSlotOffset &offset) {
    offset.value += 11;
    offset.value = (s16)offset.value;
}
}

#pragma pop

struct Stack_802E8274 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    f32 sp1C;
    f32 sp20;
    f32 sp24;
    f32 sp28;
};

struct RecoveredGlobal_802E80F4_lbl_8050BEC0 {
    s32 value;
    u8 remaining[0x1C];
};

struct RecoveredGlobal_802E80F4_lbl_8058D4C0 {
    s32 value;
    u8 remaining[0xC];
};
extern "C" {
s32 transform_point_by_current_matrix(void *, void *);

s32 push_matrix();

void TObjPlayer__sub_802E8274(NJS_OBJECT *);



extern RecoveredGlobal_802E80F4_lbl_8050BEC0 saved_model_draw_color;

extern RecoveredGlobal_802E80F4_lbl_8058D4C0 model_material_color;

extern s32 saved_model_render_flags;

extern s32 saved_chunk_polygon_flags_and_mask;

extern s32 saved_chunk_polygon_flags_or_mask;

extern s32 chunk_polygon_flags_or_mask;

extern s32 chunk_polygon_flags_and_mask;

extern s32 model_render_flags;



LAYOUT_ASSERT(RecoveredGlobal_802E80F4_lbl_8050BEC0_size, sizeof(RecoveredGlobal_802E80F4_lbl_8050BEC0) == 0x20);

LAYOUT_ASSERT(RecoveredGlobal_802E80F4_lbl_8058D4C0_size, sizeof(RecoveredGlobal_802E80F4_lbl_8058D4C0) == 0x10);
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off





}
void get_current_matrix(void *m);
struct ByteBlock_14 { u8 bytes[0x14]; };








struct Body_802E8B50 { u8 pad[8]; s32 flags; };

struct Fish_802E8B50 {
    u8 pad0[0x30];
    s32 f30;
    u8 pad34[0x38 - 0x34];
    Vec pos;
    u8 pad44[0x5C - 0x44];
    s32 f5C;
    u8 pad60[0x5F8 - 0x60];
    void *kids[10];
    u8 pad620[0x624 - 0x620];
    Body_802E8B50 *body;
    s32 flags;
    u8 pad62C[0x6C0 - 0x62C];
    s32 dir;
    u8 pad6C4[0x6DC - 0x6C4];
    void *tent[4];
    f32 f6EC_pad;
    f32 f6F0;
    u8 pad6F4[0x6FC - 0x6F4];
    s32 f6FC;
    u8 pad700[0x728 - 0x700];
    s32 phase;
    s32 timer;
    u8 pad730[0x73C - 0x730];
    s32 f73C;
    u8 pad740[0x7A4 - 0x740];
    void *nodes;
    u8 pad7A8[0x7B0 - 0x7A8];
    s32 f7B0;
    u8 f7B4[4];
};


struct Fish_802E9DBC {
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
    u8 padC4[0x440 - 0xC4];
    Vec p440;
    Vec p44C;
    u8 pad458[0x4DC - 0x458];
    Vec p4DC;
    u8 pad4E8[0x50C - 0x4E8];
    u8 eff[0x624 - 0x50C];
    u8 *f624;
    u32 flags;
    u8 pad62C[0x6C0 - 0x62C];
    s32 mode;
    u8 pad6C4[0x6DC - 0x6C4];
    saddr tent[4];
    u8 pad6EC[0x6F0 - 0x6EC];
    f32 f6F0;
    u8 pad6F4[0x728 - 0x6F4];
    s32 state;
    s32 timer;
    s32 tick;
    s32 count;
    u8 pad738[0x744 - 0x738];
    f32 f744;
    f32 f748;
    f32 f74C;
    f32 f750;
    f32 f754;
    f32 f758;
    f32 f75C;
    f32 f760;
    u8 pad764[0x784 - 0x764];
    void *ptcl;
};

extern "C" {
void fill_value_array(saddr address);











s32 restore_player_cameras();

s32 activate_camera_mode(s32 arg0);

CameraPlayback *get_scripted_camera_playback();















f32 fabs_float(f32);

s32 advance_scalar_motion_profile(void *);



}

void *create_particle_controller_with_angles(void *arg0, void *arg1, s32 arg2, s32 arg3, u16 arg4);
extern "C" {



void assign_slots_from_list(void *arg0, saddr arg1);





void TObjBoss2Tunnel__sub_802F22C4(void);

void TObjBoss2Tunnel__sub_802F22DC(void);

void TObjFish__sub_802E9DBC(u8 *arg0, u32 arg1, s32 arg2);







s32 enemy_set_target_id(void * a0 = 0, u16 a1 = 0);

void project_sound_origin_from_camera(saddr arg0, u8 *arg1, f32 farg0);


u8 *get_enemy_entity(u16 arg0);




void TObjFish__sub_802EC468(saddr arg0, f32 farg0, f32 farg1);

void TBoss7DeRolLeC__sub_802EC994(void* p);

void fn_802EC9A4(void *arg0, void *arg1);

void fn_802EC9F0(TObjEneDD *arg0, void *arg1);




s32 TObjFish__sub_802F18E8(void *);

extern f32 lbl_804FF5E8[];



}

void calc_laser_ray_hit_point(u8 *arg0, u8 *arg1);

void handle_6xAA_barba_ray_boss_actions(void *arg0);

void handle_6xA9_barba_ray_boss_actions(void *arg0);



void compose_motion_node_matrix(void *arg0);

s32 TBoss7Joint_get_shell_max_hp(void);


extern "C" {


s32 update_local_colliders_from_world(void *, void *);
s32 add_radar_scaled_marker(void *, int, int, int, f32);
#pragma pop

s32 rotate_matrix_by_node_angles(void *, int);


s32 scale_current_matrix(void *);

s32 post_translate_matrix(void *);


extern const char *TBoss7DeRolLeC__class_name;

extern const CollisionBody lbl_80473C3C;

extern const Vec lbl_80473F6C;





void run_load_callback_table(void *, int);

}

Light_802EE574 boss7_derolle_light_pool[11];

u8 *lbl_805D6918; // resource bundle loaded by TObjPlayer__sub_802EE574
s32 boss7_derolle_c_motion_id;
s32 lbl_805D6920;
s32 lbl_805D6924;
saddr lbl_805D6928;
saddr lbl_805D692C;
saddr lbl_805D6930;
saddr lbl_805D6934;
TBoss7DeRolLeC *boss7_joint_state; // the destructor clears it when it holds this object
u8 *lbl_805D693C;
s32 *lbl_805D6940;
saddr lbl_805D6944;

void TBoss7DeRolLeC::clear_harmful_statuses() {  }

void TBoss7DeRolLeC::apply_shock_status() {  }

void TBoss7DeRolLeC::apply_movement_ailment(s32) {  }

void TBoss7DeRolLeC::apply_confusion_status() {  }

void TBoss7DeRolLeC::apply_slow_status() {  }

void TBoss7DeRolLeC::apply_paralysis() {  }

void TBoss7DeRolLeC::apply_poison_status() {  }

TBoss7DeRolLeC *TBoss7Joint::get_state() { return boss7_joint_state; }

void TObjPlayer__sub_802EE574(void) {
    s32 i;
    u8 *p;
    p = (u8 *)new BmlResource(1, &bm_boss7_de_rol_le_c_resource_descriptor, 0, 0, NULL);
    lbl_805D6918 = p;
    boss7_derolle_c_motion_id = 0;
    lbl_805D6920 = 0;
    lbl_805D6924 = 0;
    lbl_805D6928 = 0;
    lbl_805D692C = 0;
    lbl_805D6930 = 0;
    lbl_805D6934 = 0;
    boss7_joint_state = NULL;
    run_load_callback_table(lbl_804E3C5C, 0x30);
    lbl_805D693C = (u8 *)find_model_node(*(s32 *)((s8 *)(*(u8 **)((s8 *)lbl_805D6918 + 0x42C)) + 8), 0x4D);
    lbl_805D6940 = *(s32 **)((s8 *)lbl_805D693C + 0x2C);
    for (i = 0; i < 11; i++) {
        Light_802EE574 *l = &boss7_derolle_light_pool[i];
        l->type = 0xF;
        l->f4 = 0;
        l->f8 = 0.0f;
        l->fC = 0.0f;
        l->f10 = 0.0f;
        l->f14 = 0;
        l->f18 = 0;
        l->f1C = 0;
        l->f20 = 0.0f;
        l->f24 = 0.0f;
        l->f28 = 0.0f;
        l->next = 0;
        l->f30 = 0;
    }
    for (i = 0; i < 10; i++) {
        boss7_derolle_light_pool[i].next = &boss7_derolle_light_pool[i + 1];
    }
    {
        Light_802EE574 *t = &boss7_derolle_light_pool[10];
        t->type = 0x1F;
        t->next = 0;
    }
    TWindowCtrl::init_all_slots();
}

void *TBoss7DeRolLeC::create(void *arg0) {
    return new TBoss7DeRolLeC(tl_04, arg0);
}

void TBoss7DeRolLeC::run_exit_callbacks() {
    TLobby::call_funcs_reverse((void*)lbl_804E3C5C, (unsigned int)0x30U);
    if ((void *) lbl_805D6918 != NULL) {
        delete (BmlResource *)lbl_805D6918;
        lbl_805D6918 = NULL;
    }
}

TBoss7DeRolLeC::TBoss7DeRolLeC(TObject *parent, void *set_data) : TObjEneDD_ST(parent), unk_690(NULL) {
    u32 state[3];

    m_name = TBoss7DeRolLeC__class_name;
    if (boss7_joint_state == NULL) {
        boss7_joint_state = this;
    }
    reset_hp((u8 *)TLobby::register_boss(15), (u8 *)TLobby::dispatch_shared_handler_b(15), (u8 *)TLobby::register_object(15));
    unk_620 = (TBoss7DeRolLeCParams *)TLobby::dispatch_shared_handler_a(15);
    invoke_initialization_hook(set_data);
    unk_628 = 0;
    if (exchange_object_state(state, 1) && (state[0] & 0x12008) == 0x12008) {
        unk_628 |= 0x8000;
    }
    init_position_vectors();
    model = (void *)get_bml_model((BmlResource *)lbl_805D6918, 0);
    texlist = (saddr)get_bml_texlist((BmlResource *)lbl_805D6918, 0);
    save_joint_polygons();
    copy_collision_body(&unk_3C0, &lbl_80473C3C);
    set_collision_body(&unk_3C0);
    transform_part_positions();
    motion_flags = 0;
    set_field_d8((saddr)de_rol_le_c_action_table);
    set_field_dc((saddr)((BmlResource *)lbl_805D6918)->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    set_state_flag_2();
    movementParameters = &lbl_804E3C8C;
    initialize_enemy_state(0x49);
    unk_37C = 20.0f;
    enemy_init_acquire_period(30);
    enemy_init_validate_period(30);
    unk_7A8 = 0;
    crawfish_parent = new TObject(this);
    unk_62C = 0;
    unk_6B0 = 0;
    action_index = 0;
    for (s32 i = 0; i < 20; i++) {
        unk_3EC[i].x = 0.0f;
        unk_3EC[i].y = 0.0f;
        unk_3EC[i].z = 0.0f;
    }
    for (s32 i = 0; i < 4; i++) {
        unk_4DC[i].x = 0.0f;
        unk_4DC[i].y = 0.0f;
        unk_4DC[i].z = 0.0f;
    }
    unk_6D8 = (GC_Mtx *)mem_alloc(4 * sizeof(GC_Mtx));
    for (s32 i = 0; i < 4; i++) {
        set_matrix_identity((u8 *)unk_6D8[i]);
        unk_6DC[i] = new TBoss7Tentacle(&unk_690, (saddr)unk_6D8[i], i);
    }
    Vec v = lbl_80473F6C;
    u16 id = entity_id + 1;
    s32 set = set_index + 1;
    for (s32 i = 0; i < 10; i++) {
        VecCopy(&unk_530[i], &v);
        unk_5F8[i] = new TBoss7Joint(this, id++, set++, &unk_530[i], i);
    }
    unk_6C0 = 0;
    unk_6C4 = 0;
    unk_6C8 = 0;
    unk_6CC = 0;
    unk_6D0 = 0;
    motion_x.init_float_block();
    motion_y.init_float_block();
    motion_z.init_float_block();
    unk_6EC.x = 0.0f;
    unk_6EC.y = 0.0f;
    unk_6EC.z = 0.0f;
    unk_6F8 = unk_6FC = unk_620->unk_18;
    unk_700 = unk_620->unk_20;
    hpmax = hp = 20000;
    unk_704 = 0;
    unk_708 = new TBoss7LaserLight(&unk_690, &unk_70C);
    unk_70C.x = 0.0f;
    unk_70C.y = 0.0f;
    unk_70C.z = 0.0f;
    unk_718 = new AreaAttackHistory(4);
    fill_value_array((saddr)unk_718);
    unk_71C = NULL;
    unk_720 = NULL;
    for (s32 i = 0; i < 3; i++) {
        VecCopy(&unk_50C[i], &position);
    }
    unk_6BC = 0;
    unk_6D4 = (GC_Mtx *)mem_alloc(12 * sizeof(GC_Mtx));
    for (s32 i = 0; i < 12; i++) {
        set_matrix_identity((u8 *)unk_6D4[i]);
    }
    for (s32 i = 0; i < 6; i++) {
        unk_788[i] = NULL;
    }
    unk_7A0 = 0;
    unk_724 = 0;
    unk_728 = 0;
    unk_72C = 0;
    unk_730 = 0;
    unk_734 = 0;
    unk_738 = 0;
    unk_73C = 0;
    unk_740 = 0;
    unk_744 = 0.0f;
    unk_748 = 0.0f;
    unk_74C = 0.0f;
    unk_750 = 0.0f;
    unk_754 = 0.0f;
    unk_758 = 0.0f;
    unk_75C = 0.0f;
    unk_760 = 0.0f;
    unk_764 = 0.0f;
    unk_768 = 0.0f;
    unk_76C.x = 0.0f;
    unk_76C.y = 0.0f;
    unk_76C.z = 0.0f;
    unk_778.x = 0.0f;
    unk_778.y = 0.0f;
    unk_778.z = 0.0f;
    unk_784 = NULL;
    unk_6AC = 0;
    unk_624 = &controller_input_state.controllers[1];
    if (TObjEneDD::is_main_phase_15()) {
        if (update_lobby_state()) {
            unk_6B8 = 0;
        } else {
            unk_6B8 = 1;
        }
    } else {
        unk_6B8 = 0;
    }
    TBoss7DeRolLeC__sub_802EC994(this);
    if (!(unk_628 & 0x8000)) {
        mode = 1;
        dispatch_action(mode, 4);
    }
    unk_7AC = new TUnk_804F1C58(this, model);
    if (unk_7AC != NULL) {
        unk_7AC->set_field_38(TObjPlayer__sub_802E8274);
    }
    unk_7B0 = NULL;
    unk_7B4.x = 0.0f;
    unk_7B4.y = 0.0f;
    unk_7B4.z = 0.0f;
    unk_7C0.x = 0.0f;
    unk_7C0.y = 0.0f;
    unk_7C0.z = 0.0f;
    needle_targets[0] = 0xFFFF;
    needle_targets[1] = 0xFFFF;
    needle_targets[2] = 0xFFFF;
    needle_targets[3] = 0xFFFF;
}

TBoss7DeRolLeC::~TBoss7DeRolLeC() {
    s32 i;
    if (unk_784 != NULL) {
        unk_784->queue_destruction();
        unk_784 = NULL;
    }
    for (i = 0; i < 6; i++) {
        if (unk_788[i] != NULL) {
            unk_788[i]->queue_destruction();
            unk_788[i] = NULL;
        }
    }
    mem_free(unk_6D4);
    unk_6D4 = NULL;
    if (unk_71C != NULL) {
        unk_71C->queue_destruction();
        unk_71C = NULL;
    }
    if (unk_720 != NULL) {
        unk_720->queue_destruction();
        unk_720 = NULL;
    }
    if (unk_718 != NULL) {
        delete unk_718;
        unk_718 = NULL;
    }
    if (unk_708 != NULL) {
        ((TObject *)unk_708)->queue_destruction();
        unk_708 = NULL;
    }
    for (i = 3; i >= 0; i--) {
        ((TObject *)unk_6DC[i])->queue_destruction();
        unk_6DC[i] = NULL;
    }
    mem_free(unk_6D8);
    clear_collision_bodies();
    if (boss7_joint_state == this) {
        boss7_joint_state = NULL;
    }
    destroy_child();
}

void TBoss7DeRolLeC::run_task() {
    s32 temp_r0_2;
    s32 temp_r0_3;
    s32 temp_r30;
    s32 temp_r3;
    TObjPlayer__sub_802ED984();
    temp_r3 = this->unk_628;
    if (temp_r3 & 0x8000) {
        this->send_entity_set_flags();
        queue_destruction();
        return;
    }
    if (temp_r3 & 0x80) {
        this->unk_628 = (s32) (temp_r3 & 0xFFFFFF7F);
        this->unk_628 = (s32) (this->unk_628 | 0x40);
        {
            void *p = (void *)TObject::operator new(0x3C);
            if (p != NULL) {
                ((TObjPlayer *)p)->init_breakup_pieces(this, (saddr)this->unk_6D4);
            }
        }
    }
    if ((TObjEneDD::is_main_phase_15() != 0) && (this->unk_6AC == 0)) {
        if (this->update_lobby_state() != 0) {
            this->unk_6B8 = 0;
        } else {
            this->unk_6B8 = 1;
        }
    }
    if ((this->unk_6AC != 0) && (*(s32 *)((s8 *)(*(u8 **)((s8 *)((u8 *)this) + 0x624)) + 8) & 0x10000)) {
        switch (this->unk_6B8) {
        case 1:
            this->unk_6B8 = 0;
            this->advance_action_sequence();
            break;
        case 0:
            this->unk_6B8 = 2;
            break;
        case 2:
            this->unk_6B8 = 1;
            break;
        }
    }
    temp_r30 = TObjEneDD::query_teammate_state();
    this->update_attack_stat_status();
    this->update_defense_stat_status();
    if (temp_r30 == 0) {
        if ((this->mode == 0x1C) || (this->mode == 0x1D) || (this->mode == 0x1B)) {
            this->actorFlags = (s32) (this->actorFlags | 0x800);
        } else {
            this->actorFlags = (s32) (this->actorFlags & 0xFFFFF7FF);
        }
        temp_r0_3 = this->unk_6B8;
        if (temp_r0_3 != 1) {
            if (temp_r0_3 == 2) {
                if (sub_802ECB10() != 0) {
                    this->sub_802ECAA4();
                } else {
                    dispatch_action(this->mode, 2);
                }
            } else {
                this->update_or_dispatch();
            }
            if (this->test_flag30_512() != 0) {
                this->vfunc_62();
            }
            dispatch_action(this->mode, 8);
            dispatch_action(this->mode, 0);
        } else {
            if (this->test_flag30_512() != 0) {
                this->vfunc_62();
            }
            dispatch_action(this->mode, 0);
        }
        this->update_projectile_spawns();
    }
    this->sub_800BBA0C();
    this->vfunc_88();
    sync_position_vectors();
    this->flee_if_disturbed();
    update_particle_ctrls();
    if (temp_r30 == 0) {
        this->unk_690.run_tasks();
    }
    if (this->unk_7AC != 0) {
        set_motion_packed_rotation();
        push_matrix();
        set_matrix_identity(0);
        post_translate_matrix(((u8 *)this) + 0x38);
        post_translate_matrix(&this->unk_6EC);
        rotate_matrix_by_node_angles(((u8 *)this) + 0x5C, 1);
        scale_current_matrix(&lbl_804E3BF0);
        this->sub_802E8234();
        unk_7AC->apply_with_callback((NJS_MOTION *)current_motion, get_frame());
        pop_matrix();
        clear_motion_packed_rotation();
        calc_joint_positions();
    }
}

void TObjPlayer__sub_802ED984(void) {  }

void TBoss7DeRolLeC::update_or_dispatch() {
    if (sub_802ECB10() != 0) {
        sub_802ECAA4();
        return;
    }
    dispatch_action(this->mode, 9);
}
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
void TBoss7DeRolLeC::vfunc_28() {  }

void TBoss7DeRolLeC::vfunc_63() {  }

void TBoss7DeRolLeC::vfunc_62() {
    s32 damage;
    damage = hpmax - hp;
    if (unk_628 & 8) {
        unk_6FC = unk_6FC - damage;
        TObjFish__sub_802EC468((saddr)&bodies->center, 2.0f, 8.0f);
        play_sound_at(0x3B213, &unk_50C[0]);
    } else {
        unk_700 = unk_700 - damage;
        if (unk_700 < 0) {
            unk_700 = 0;
            set_hooked_effect_target();
        }
    }
    hp = (s16)hpmax;
    set_flag_800();
    clear_attack_receipts();
}

void TBoss7DeRolLeC::vfunc_61() {  }

void TBoss7DeRolLeC::sync_position_vectors() {
    VecCopy((Vec *)&m_2fc, &position);
    VecCopy(&center, (Vec *)&m_2fc);
}
void TBoss7DeRolLeC::vfunc_88() {
    Vec v;
    f32 f;
    s32 set;
    s32 clr;
    s32 i;
    VecCopy(&v, &unk_3EC[6]);
    update_local_colliders_from_world(this, &v);
    f = position.y;
    if (f < -35.0f) {
        set = 0;
        clr = 7;
    } else if (f >= 30.0f) {
        set = 5;
        clr = 2;
    } else {
        set = 3;
        clr = 4;
    }
    f = position.z;
    if (f < -180.0f && 180.0f < f) {
        set = 0;
        clr = 7;
    }
    for (i = 0; i != body_count; i++) {
        bodies[i].flags |= set;
        (this->bodies)[i].flags &= ~clr;
    }
}

void TBoss7DeRolLeC::flee_if_disturbed() {
    if (bodies->flags & 1) {
        submit_default_cursor_candidate();
        add_radar_scaled_marker(&position, -0x5DB4, 1, 1, 2.0f);
    }
}

void TBoss7DeRolLeC::set_state_and_send(s32 arg1) {
    G_BarbaRayBossActions_6xAA pa;
    G_BarbaRayBossActions_6xA9 pb;
    dispatch_action(arg1, 6);
    if (((arg1 - 0x13) <= 1U) || ((arg1 - 0x40) <= 1U) || (arg1 == 0x44) || (arg1 == 0x18)) {
        pa.init();
        pa.header.client_id = this->entity_id;
        pa.what = arg1;
        pa.unknown_a2 = this->action_index;
        pa.target_client_id = this->unk_38C;
        pa.send();
        return;
    }
    pb.init();
    pb.header.client_id = this->entity_id;
    pb.what = arg1;
    pb.unknown_a2 = this->action_index;
    pb.send();
}

void TBoss7DeRolLeC::reload_stats_for_phase(s32 phase) {
    s32 v;
    switch (phase) {
    case 0:
    default:
        v = 0xF;
        break;
    case 1:
        v = 0x10;
        break;
    case 2:
        v = 0x11;
        break;
    }
    reload_stats_keep_hp_tp((u8 *)TLobby::register_boss(0xF), (u8 *)TLobby::dispatch_shared_handler_b(v), (u8 *)TLobby::register_object(0xF));
}

void TBoss7DeRolLeC::emit_hit_effect(const Vec *position) {
    reload_stats_for_phase(2);
    TObjEneDD::emit_effect(this, (saddr)position, (saddr)&lbl_80472D7C);
    reload_stats_for_phase(unk_62C);
}

f32 TBoss7PhotonBullet::get_target_pos_y() {
    return *(f32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0xF)) + 4);
}

s32 TBoss7Joint_get_shell_max_hp(void) {
    return *(s32 *)((s8 *)(TLobby::dispatch_shared_handler_a(0xF)) + 0x1C);
}

void TBoss7DeRolLeC::set_position_index(s32 index) {
    VecCopy(&position, &lbl_80472D04[index]);
    unk_6EC.y = 0.0f;
    rotation_z = 0;
}

void TBoss7DeRolLeC::set_swim_direction(s32) {
    if (unk_6C0 == 0) {
        position.x = -100.0f;
        rotation_z = 0x500;
    } else {
        position.x = 100.0f;
        rotation_z = -0x500;
    }
    position.z = 10.0f;
    unk_6EC.y = 4.0f;
}

f32 TBoss7DeRolLeC::sub_802ED3E4() {
    Vec v;
    v.x = 0.0f;
    v.y = 0.0f;
    v.z = 0.0f;
    push_matrix_from(identity_matrix);
    scale_matrix(NULL, 2.5f, 2.5f, 2.5f);
    bind_motion_context(current_motion, frame);
    compose_motion_node_matrix(model);
    transform_point_by_current_matrix(&v, &v);
    pop_matrix();
    return v.y;
}

void TBoss7DeRolLeC::update_wobble_angle() {
    if (unk_6EC.y > 0.4f) {
        unk_6EC.y -= 0.4f;
    } else if (unk_6EC.y < -0.4f) {
        unk_6EC.y += 0.4f;
    } else {
        unk_6EC.y = 0.0f;
    }
}

s32 TBoss7DeRolLeC::is_all_parts_done() {
    advance_scalar_motion_profile(&motion_z);
    advance_scalar_motion_profile(&motion_x);
    advance_scalar_motion_profile(&motion_y);
    if (motion_x.state == 3 && motion_y.state == 3 && motion_z.state == 3) {
        return 1;
    }
    return 0;
}
#pragma push
#pragma opt_common_subs off
u32 TBoss7DeRolLeC::update_anim_state() {
    u8 done;
    advance_scalar_motion_profile(&motion_z);
    if (advance_scalar_motion_profile(&motion_y) == 3) {
        unk_6CC = 1;
    }
    switch (unk_6C8) {
    case 0:
        if (motion_z.travelled > 380.0f) {
            unk_6C8 = 1;
        }
        break;
    case 1:
        if (advance_scalar_motion_profile(&motion_x) == 3) {
            unk_6C8 = 2;
        }
        break;
    }
    play_speed += 0.1f;
    if (play_speed > 0.9f) {
        play_speed = 0.9f;
    }
    done = 0;
    if (unk_6C8 == 2 && unk_6CC == 1) {
        done = 1;
    }
    return done;
}
#pragma pop
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
u32 TBoss7DeRolLeC::update_phase_settling() {
    u8 done;
    advance_scalar_motion_profile(&motion_x);
    if (advance_scalar_motion_profile(&motion_y) == 3) {
        unk_6CC = 1;
    }
    switch (unk_6D0) {
    case 0:
        if (motion_x.travelled > 160.0f) {
            unk_6D0 = 2;
        }
        break;
    case 2:
        play_speed = 0.3f;
        unk_6D0 = 3;
        break;
    case 3:
        if (advance_scalar_motion_profile(&motion_z) == 3) {
            unk_6D0 = 4;
        }
        if (motion_z.travelled > 200.0f) {
            play_speed += 0.1f;
            if (play_speed > 0.9f) {
                play_speed = 0.9f;
            }
        }
        break;
    }
    done = 0;
    if (unk_6D0 == 4 && unk_6CC == 1) {
        done = 1;
    }
    return done;
}
#pragma pop
#pragma push
#pragma fp_contract on
u32 TBoss7DeRolLeC::update_tail_anim_state() {
    u8 done;
    advance_scalar_motion_profile(&motion_z);
    if (advance_scalar_motion_profile(&motion_y) == 3) {
        unk_6CC = 1;
    }
    switch (unk_6C8) {
    case 0:
        play_speed = 0.3f;
        if (motion_z.travelled > 100.0f) {
            unk_6C8 = 1;
        }
        break;
    case 1:
        if (advance_scalar_motion_profile(&motion_x) == 3) {
            unk_6C8 = 2;
        }
        break;
    }
    if (motion_z.travelled > 100.0f) {
        play_speed = 0.9f;
    }
    done = 0;
    if (unk_6C8 == 2 && unk_6CC == 1) {
        done = 1;
    }
    return done;
}
#pragma pop
#pragma push
#pragma opt_common_subs off
u32 TBoss7DeRolLeC::update_phase_rising() {
    f32 speed;
    u8 done;
    advance_scalar_motion_profile(&motion_x);
    if (advance_scalar_motion_profile(&motion_y) == 3) {
        unk_6CC = 1;
    }
    switch (unk_6D0) {
    case 2:
        break;
    case 1:
        speed = motion_z.speed - 0.1f;
        if (speed < -4.0f) {
            speed = -4.0f;
        }
        motion_z.speed = speed;
        motion_z.travelled = motion_z.travelled + speed;
        if (motion_x.travelled > 30.0f) {
            unk_6D0 = 3;
        }
        break;
    case 3:
        if (advance_scalar_motion_profile(&motion_z) == 3) {
            unk_6D0 = 4;
        }
        break;
    }
    play_speed += 0.1f;
    if (play_speed > 0.9f) {
        play_speed = 0.9f;
    }
    done = 0;
    if (unk_6D0 == 4 && unk_6CC == 1) {
        done = 1;
    }
    return done;
}

#pragma pop
void TBoss7DeRolLeC::sub_802ECE90(s32 joint, s32 shot_level) {
    s32 angle;
    Vec dir;
    angle = 0x3800 - joint * 51;
    dir.x = sin_table_lookup(angle);
    dir.y = 0.0f;
    dir.z = cos_table_lookup(angle);
    if (unk_6C0 == 2) {
        dir.x *= -1.0f;
    }
    new TBoss7PhotonPad(&unk_690, &unk_530[joint], &dir, shot_level);
    play_sound_effect(0x39D11, &unk_530[joint], 0, 1);
}

#pragma push
#pragma fp_contract on

void TBoss7DeRolLeC::sub_802ECE28() {
    VecCopy(&unk_70C, &unk_4DC[0]);
    unk_70C.x += 30.0f * unk_4DC[1].x;
    unk_70C.y += 30.0f * unk_4DC[1].y;
    unk_70C.z += 30.0f * unk_4DC[1].z;
}
#pragma pop
void TBoss7DeRolLeC::turn_on_laser_light() {
    if (unk_708 != NULL) {
        unk_708->turn_on();
    }
    unk_628 |= 0x10;
}

void TBoss7DeRolLeC::turn_off_laser_light() {
    if (unk_708 != NULL) {
        unk_708->turn_off();
    }
    unk_628 &= ~0x10;
}
void TBoss7DeRolLeC::pick_random_target() {
    s32 n;
    u8 *p;
    s32 idx;
    s32 i;
    n = TLobby::get_game_mode();
    if (n == 0) {
        enemy_clear_target();
        return;
    }
    if (n == 1) {
        p = (u8 *)TObjPlayer::get_player_data(0);
        set_target_player(p);
        return;
    }
    idx = (s32)floor_to_float((f32)n * random_ratio());
    enemy_clear_target();
    for (i = 0; i < n; i++) {
        p = (u8 *)TObjPlayer::get_player_data(idx);
        if (((TObjBase *)p)->is_alive() != 0) {
            set_target_player(p);
            return;
        }
        idx++;
        if (idx >= n) {
            idx = 0;
        }
    }
}

void TBoss7DeRolLeC::sub_802ECC44() {
    s32 i;
    vfunc_95();
    for (i = 0; i < 10; i++) {
        unk_5F8[i]->vfunc_95();
    }
}

void TBoss7DeRolLeC::sub_802ECBDC() {
    s32 i;
    vfunc_96();
    for (i = 0; i < 10; i++) {
        unk_5F8[i]->vfunc_96();
    }
}

void TBoss7DeRolLeC::apply_damage_and_set_effect(s32 damage, u16) {
    unk_6FC = unk_6FC - (s32)(0.5f * (f32)damage);
    play_sound_at(0x3B213, &position);
}

void TBoss7DeRolLeC::set_hooked_effect_target() {
    unk_628 |= 0x88;
    play_sound_at(0x3A312, &position);
}

s32 TBoss7DeRolLeC::sub_802ECB10() {
    s32 var_r4;

    var_r4 = 0;
    if ((this->unk_6FC <= 0) && !(this->unk_628 & 4)) {
        var_r4 = 1;
    }
    return (u8)var_r4;
}

void TBoss7DeRolLeC::sub_802ECAA4() {
    if (mode == 0x1C || mode == 0x1D) {
    } else if (mode == 0x13 || mode == 0x14) {
        advance_action_sequence();
    } else if (mode == 0x15 || mode == 0x16) {
        set_state_and_send(0x1C);
    } else {
        set_state_and_send(0x1B);
    }
}

void handle_6xA9_barba_ray_boss_actions(void *boss7_joint) {
    void *x;
    ((G_BarbaRayBossActions_6xA9 *)boss7_joint)->bswap();
    x = get_enemy_entity(*(u16 *)((s8 *)boss7_joint + 0x2));
    if (x != NULL) {
        fn_802EC9F0((TObjEneDD *)x, boss7_joint);
    }
}

void handle_6xAA_barba_ray_boss_actions(void *boss7_joint) {
    void *x;
    ((G_BarbaRayBossActions_6xAA *)boss7_joint)->bswap();
    x = get_enemy_entity(*(u16 *)((s8 *)boss7_joint + 0x2));
    if (x != NULL) {
        fn_802EC9A4(x, boss7_joint);
    }
}

void fn_802EC9F0(TObjEneDD *ene_dd, void *arg1) {
    *(s32 *)((s8 *)ene_dd + 0x6B4) = (s32) *(s16 *)((s8 *)arg1 + 6);
    ene_dd->transition_enemy_state(*(s16 *)((s8 *)arg1 + 4));
}

void fn_802EC9A4(void *ene_dd, void *arg1) {
    enemy_set_target_id(ene_dd, (u16) *(s32 *)((s8 *)arg1 + 8));
    *(s32 *)((s8 *)ene_dd + 0x6B4) = (s32) *(s16 *)((s8 *)arg1 + 6);
    ((TObjEneDD *)ene_dd)->transition_enemy_state(*(s16 *)((s8 *)arg1 + 4));
}

void TBoss7DeRolLeC__sub_802EC994(void* p) { *(s32*)((char*)p + 0x6b0) = 0; *(s32*)((char*)p + 0x6b4) = 0; }

void TBoss7DeRolLeC::advance_action_sequence() {
    s32 var_r30;
    s32 var_r4;
    do {
        var_r30 = 0;
        this->action_index = (this->action_index + 1);
        var_r4 = lbl_804E3C2C[game_difficulty_selection][this->action_index].a;
        switch (var_r4) {
        case 0x1E:
            if (calc_elapsed_scaled() > 0.0f) {
                var_r4 = 8;
            } else {
                var_r4 = 6;
            }
            break;
        case 0x1F:
            if (this->unk_6C4 == 0) {
                var_r4 = 5;
            } else {
                var_r4 = 9;
            }
            break;
        case 0x20:
            if (calc_elapsed_scaled() > 0.0f) {
                var_r4 = 0xC;
            } else {
                var_r4 = 0xE;
            }
            break;
        case 0x21:
            if (this->unk_6C4 == 0) {
                var_r4 = 3;
            } else {
                var_r4 = 0xB;
            }
            break;
        case 0x23:
            if (this->unk_6C4 == 0) {
                var_r4 = 4;
            } else {
                var_r4 = 0xA;
            }
            break;
        case 0x24:
            if (this->unk_6C4 == 0) {
                var_r4 = 0xF;
            } else {
                var_r4 = 0x10;
            }
            break;
        case 0x25:
            if (this->unk_6C4 == 0) {
                var_r4 = 0x11;
            } else {
                var_r4 = 0x12;
            }
            break;
        case 0x26:
            if (this->unk_6C4 == 0) {
                var_r4 = 0x13;
            } else {
                var_r4 = 0x14;
            }
            break;
        case 0x27:
            if (this->unk_6C4 == 0) {
                var_r4 = 0x15;
            } else {
                var_r4 = 0x16;
            }
            break;
        case 0x45:
            var_r30 = 1;
            this->action_index = 1;
            break;
        }
    } while (var_r30 != 0);
    set_state_and_send(var_r4);
}
#pragma push
#pragma fp_contract on
void TBoss7DeRolLeC::update_particle_ctrls() {
    Vec v;
    s32 p[3];
    s32 ok;
    s32 i;
    s32 k;
    f32 w;
    f32 r;
    s32 j;
    s32 m;
    ok = 1;
    for (i = 0; i < 6; i++) {
        if (unk_788[i] == 0) {
            void *r;
            p[2] = 0;
            p[1] = 0;
            p[0] = 0;
            r = create_particle_controller_with_angles(unk_530, p, 0x200, 1, 0x40);
            if (r != 0) {
                unk_788[i] = (TParticleCtrl *)r;
                unk_788[i]->set_flags(2);
                unk_788[i]->enable();
            } else {
                for (ok = 0; ok < i; ok++) {
                    unk_788[ok]->enable();
                }
                ok = 0;
                break;
            }
        }
    }
    if (ok != 0) {
        if (unk_7A0 == 0) {
            for (k = 0; k < 3; k++) {
                Vec *src = &unk_530[particle_pos_index_table[k]];
                r = fabs_float(src->y - -10.0f);
                w = lbl_804E3E48[k];
                if (r < 0.9f * w) {
                    VecCopy(&v, src);
                    w -= r;
                    v.y = -5.0f;
                    v.x += w;
                    unk_788[k * 2]->set_position(&v);
                    v.x -= 2.0f * w;
                    unk_788[k * 2 + 1]->set_position(&v);
                } else {
                    unk_788[k * 2]->enable();
                    unk_788[k * 2 + 1]->enable();
                }
            }
        } else {
            VecCopy(&v, &unk_530[unk_7A0]);
            v.y = -5.0f;
            v.x += 20.0f;
            unk_788[0]->set_position(&v);
            v.x -= 40.0f;
            unk_788[1]->set_position(&v);
            for (j = 2; j < 6; j++) {
                unk_788[j]->enable();
            }
            unk_7A0 = 0;
        }
        for (m = 0; m < 6; m++) {
            sub_802EC52C(unk_788[m]);
        }
    }
}
#pragma pop
void TBoss7DeRolLeC::sub_802EC52C(TParticleCtrl *ctrl) {
    TObjFish__sub_802F18E8(ctrl);
}

void TBoss7DeRolLeC::spawn_particle_201(Vec *pos) {
    TObjFish::spawn_default_particle((saddr)pos, 0x201);
}
#pragma push
#pragma fp_contract on
void TObjFish__sub_802EC468(saddr arg0, f32 farg0, f32 farg1) {
    Vec stack;
    VecCopy(&stack, (const Vec *)arg0);
    stack.x -= lbl_804FF5E8[3] * farg1;
    stack.y -= lbl_804FF5E8[4] * farg1 - farg0;
    stack.z -= lbl_804FF5E8[5] * farg1;
    spawn_particle_effect_with_flags(&stack, 0x127, 0x40);
}
#pragma pop
void TBoss7DeRolLeC::update_projectile_spawns() {
    Vec *mid;

    project_sound_origin_from_camera((saddr)&position, (u8 *)&unk_50C[0], 0.3f);
    project_sound_origin_from_camera((saddr)&unk_3EC[18], (u8 *)&unk_50C[1], 0.3f);
    mid = &unk_50C[2];
    VecCopy(mid, &unk_50C[1]);
    vec3_add_to(mid, &unk_50C[1]);
    mid->x *= 0.5f;
    mid->y *= 0.5f;
    mid->z *= 0.5f;
    if ((unk_628 & 0x100) && ((is_passing_frame(3.0f) != 0) || (is_passing_frame(20.0f) != 0))) {
        unk_6BC = 0;
    }
    if (unk_6BC <= 0x10) {
        if (unk_628 & 0x400) {
            play_persistent_sound_at(0x39704, &unk_50C[2]);
        } else {
            play_persistent_sound_at(0x3A303, &unk_50C[2]);
        }
        unk_6BC = unk_6BC + 1;
    }
    if (unk_628 & 0x200) {
        play_persistent_sound_at(0x39F08, &unk_50C[0]);
    }
}

void TBoss7DeRolLeC::sub_802EC32C() {}

void TBoss7DeRolLeC::play_sound_at(s32 id, Vec *pos) { play_sound_effect(id, pos, 0, 0); }

void TBoss7DeRolLeC::play_persistent_sound_at(s32 id, Vec *pos) {
    play_persistent_sound(id, (saddr)this, (uaddr)pos, 0, 0);
}

void TBoss7DeRolLeC::dispatch_action(u32 state, s32 reason) {
    s32 temp_r6;
    switch (state) {
    case 0x0:
        sub_802EBE50(reason);
        return;
    case 0x1:
        sub_802EBBC8(reason);
        return;
    case 0x2:
        sub_802EB90C(reason);
        return;
    case 0x3:
        sub_802EB270(reason, 0, 1);
        return;
    case 0x4:
        sub_802EAAC8(reason, 0, 2);
        return;
    case 0x5:
        sub_802EB270(reason, 0, 3);
        return;
    case 0x6:
        sub_802EB270(reason, 1, 2);
        return;
    case 0x8:
        sub_802EB270(reason, 1, 0);
        return;
    case 0x9:
        sub_802EB270(reason, 2, 3);
        return;
    case 0xA:
        sub_802EAAC8(reason, 2, 0);
        return;
    case 0xB:
        sub_802EB270(reason, 2, 1);
        return;
    case 0xC:
        sub_802EB270(reason, 3, 0);
        return;
    case 0xD:
        sub_802EA4D8(reason);
        return;
    case 0xE:
        sub_802EB270(reason, 3, 2);
        return;
    case 0x11:
        TObjFish__sub_802E9DBC((u8 *)this, reason, 0);
        return;
    case 0x12:
        TObjFish__sub_802E9DBC((u8 *)this, reason, 2);
        return;
    case 0x13:
        handle_tentacle_attack_state(reason, 0);
        return;
    case 0x14:
        handle_tentacle_attack_state(reason, 2);
        return;
    case 0x15:
        sub_802E979C(reason, 0);
        return;
    case 0x16:
        sub_802E979C(reason, 2);
        return;
    case 0xF:
        sub_802E95F8(reason, 0);
        return;
    case 0x10:
        sub_802E95F8(reason, 2);
        return;
    case 0x17:
        sub_802E9458(reason);
        return;
    case 0x18:
        sub_802E8FCC(reason);
        return;
    case 0x19:
        sub_802E8EEC(reason, 0);
        return;
    case 0x1A:
        sub_802E8EEC(reason, 1);
        return;
    case 0x1B:
        sub_802E8E34(reason);
        return;
    case 0x1C:
        handle_death_state(reason);
        return;
    case 0x1D:
        sub_802E8AD4(reason);
        return;
    case 0x28:
    case 0x29:
        temp_r6 = *(s32 *)((s8 *)this + 0x6C0);
        if (temp_r6 < 5) {
            sub_802EB270(reason, temp_r6, temp_r6 + 5);
            return;
        }
        sub_802EB270(reason, temp_r6, temp_r6 - 5);
        return;
    case 0x2A:
        sub_802EB270(reason, 6, 7);
        return;
    case 0x2B:
        sub_802EB270(reason, 7, 8);
        return;
    case 0x2C:
        sub_802EB270(reason, 8, 5);
        return;
    case 0x2D:
        sub_802EB270(reason, 5, 6);
        return;
    case 0x2E:
        sub_802EB270(reason, 6, 5);
        return;
    case 0x2F:
        sub_802EB270(reason, 5, 8);
        return;
    case 0x30:
        sub_802EB270(reason, 8, 7);
        return;
    case 0x31:
        sub_802EB270(reason, 7, 6);
        return;
    case 0x32:
        sub_802EB270(reason, 6, 9);
        return;
    case 0x33:
        sub_802EB270(reason, 9, 8);
        return;
    case 0x34:
        sub_802EB270(reason, 8, 9);
        return;
    case 0x35:
        sub_802EB270(reason, 9, 6);
        return;
    case 0x36:
        sub_802EB270(reason, 5, 9);
        return;
    case 0x37:
        sub_802EB270(reason, 9, 7);
        return;
    case 0x38:
        sub_802EB270(reason, 7, 9);
        return;
    case 0x39:
        sub_802EB270(reason, 9, 5);
        return;
    case 0x3A:
        handle_crawfish_spawn_state(reason, 0);
        return;
    case 0x3B:
        handle_crawfish_spawn_state(reason, 1);
        return;
    case 0x3C:
        handle_crawfish_spawn_state(reason, 2);
        return;
    case 0x3D:
        handle_crawfish_spawn_state(reason, 3);
        return;
    case 0x3E:
        sub_802E8990(reason);
        return;
    case 0x3F:
        sub_802E88F8(reason);
        return;
    case 0x40:
        sub_802E85E0(reason, 0);
        return;
    case 0x41:
        sub_802E85E0(reason, 2);
        return;
    case 0x42:
        sub_802E8584(reason);
        return;
    case 0x43:
        sub_802E8528(reason);
        return;
    case 0x44:
        sub_802E83E8(reason);
    default:
        return;
    }
}

void TBoss7DeRolLeC::sub_802EBE50(u32 event) {
    switch (event) {
    case 4:
        set_field_b8(1);
        return;
    case 2:
        set_state_and_send(1);
        return;
    case 0:
        advance_animation();
        return;
    case 1: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

void TBoss7DeRolLeC::sub_802EBBC8(u32 event) {
    switch (event) {
    case 4:
        set_field_b8(0);
        sub_802ECC44();
        unk_628 &= ~4;
        unk_628 &= ~0x100;
        unk_6EC.y = 0.0f;
        unk_728 = 0;
        unk_72C = 0;
        TWindowCtrl::init_all_slots();
        get_target_state_b();
        break;
    case 2:
        if (unk_728 == 1) {
            unk_6C0 = 0;
            set_state_and_send(2);
        }
        break;
    case 9:
        if (unk_728 == 1) {
            unk_6C0 = 0;
            advance_action_sequence();
        }
        break;
    case 0:
        if (unk_72C == 0) {
            if (TObjEneDD::query_teammate_state() == 0) {
                CameraPlayback cam;
                cam.index = 0;
                cam.bank = 1;
                cam.flags = 0;
                cam.frame = 0.0f;
                cam.frame_step = 0.7f;
                activate_camera_mode(5);
                cam.cache_target_and_forward(0x1C71);
                unk_72C = 1;
            }
        } else {
            advance_animation();
            if (is_passing_frame(60.0f) != 0) {
                play_sound_effect(0x39E00, NULL, 0, 0);
            }
            if (is_passing_frame(83.0f) != 0) {
                destroy_child();
                unk_7B0 = spawn_continuous_particle_effect_with_flags(&unk_7B4, 0x20F, 0x40);
            }
            if (is_passing_frame(105.0f) != 0) {
                destroy_child();
            }
            if (is_passing_frame(85.0f) != 0) {
                Vec v = lbl_80473F78;
                spawn_particle_effect_with_flags(&v, 0x20F, 0x40);
            }
            if (is_passing_frame(98.0f) != 0) {
                Vec w = lbl_80473F84;
                spawn_particle_effect_with_flags(&w, 0x20F, 0x40);
                play_sound_effect(0x39906, NULL, 0, 0);
            }
            update_attached_orientation();
            if (get_scripted_camera_playback()->flags & 1) {
                restore_player_cameras();
                advance_action_sequence();
                unk_728 = 1;
            }
        }
        break;
    case 5:
        restore_player_cameras();
        TWindowCtrl::init_all_slots2();
        get_target_state_a();
        break;
    }
}
#pragma push
#pragma opt_common_subs off
void TBoss7DeRolLeC::sub_802EB90C(u32 event) {
    u32 b;
    switch (event) {
    case 4:
        set_field_b8(1);
        sub_802ECBDC();
        unk_628 &= ~4;
        unk_628 |= 0x100;
        unk_6EC.y = 0.0f;
        rotation_z = 0;
        unk_72C = 1;
        unk_730 = 0;
        unk_728 = 0;
        break;
    case 2:
        switch (unk_6C0) {
        case 0:
            b = unk_624->unknown_08;
            if (b & 0x10) {
                set_state_and_send(3);
            } else if (b & 0x40) {
                set_state_and_send(4);
            } else if (b & 0x20) {
                set_state_and_send(5);
            } else if (b & 0x400) {
                set_state_and_send(0x11);
            } else if (b & 4) {
                set_state_and_send(0xF);
            } else if (b & 2) {
                position.z = -210.0f;
                set_state_and_send(1);
            }
            break;
        case 1:
            b = unk_624->unknown_08;
            if (b & 0x40) {
                set_state_and_send(6);
            } else if (!(b & 0x20)) {
                if (b & 0x80) {
                    set_state_and_send(8);
                } else if (b & 2) {
                    set_state_and_send(0x1B);
                }
            }
            break;
        case 2:
            b = unk_624->unknown_08;
            if (b & 0x20) {
                set_state_and_send(9);
            } else if (b & 0x80) {
                set_state_and_send(0xA);
            } else if (b & 0x10) {
                set_state_and_send(0xB);
            } else if (b & 0x400) {
                set_state_and_send(0x12);
            } else if (b & 4) {
                set_state_and_send(0x10);
            } else if (b & 2) {
                set_state_and_send(0x1B);
            }
            break;
        case 3:
            b = unk_624->unknown_08;
            if (b & 0x80) {
                set_state_and_send(0xC);
            } else if (b & 0x10) {
                set_state_and_send(0xD);
            } else if (b & 0x40) {
                set_state_and_send(0xE);
            } else if (b & 4) {
                set_state_and_send(0x17);
            } else if (!(b & 0x200) && (b & 2)) {
                set_state_and_send(0x1C);
            }
            break;
        }
        break;
    case 0:
        advance_animation();
        if (!(motion_flags & 4)) {
            play_speed -= 0.03f;
            if (play_speed < 0.6f) {
                play_speed = 0.6f;
            }
        }
        break;
    case 1:
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
#pragma pop
#pragma push
#pragma fp_contract on
// Moves the body from point unk_6C0 of lbl_80472D04 to point unk_6C4 (states 3, 5,
// 6, 8, 9, 0xB, 0xC, 0xE, 0x28, 0x29 of dispatch_action): one TUnk_80036250 profile
// per axis, unk_74C/unk_758/unk_750 the x/y/z direction signs, unk_744/unk_754/unk_748
// the start position.
void TBoss7DeRolLeC::sub_802EB270(u32 event, s32 mode, s32 next_mode) {
    f32 d;
    f32 z_speed;
    f32 z_accel;
    f32 speed;
    f32 accel;
    s32 done;

    switch (event) {
    case 4:
        this->set_field_b8(1);
        sub_802ECBDC();
        unk_628 &= ~4;
        unk_628 |= 0x100;
        unk_6C0 = mode;
        unk_6C4 = next_mode;
        set_position_index(unk_6C0);
        unk_728 = 0;
        unk_744 = position.x;
        unk_754 = position.y;
        unk_748 = position.z;
        d = lbl_80472D04[unk_6C4].x - lbl_80472D04[unk_6C0].x;
        if (0.0f < d) {
            unk_74C = 1.0f;
        } else if (d < 0.0f) {
            unk_74C = -1.0f;
        } else {
            unk_74C = 0.0f;
        }
        d = lbl_80472D04[unk_6C4].y - lbl_80472D04[unk_6C0].y;
        if (0.0f < d) {
            unk_758 = 1.0f;
        } else if (d < 0.0f) {
            unk_758 = -1.0f;
        } else {
            unk_758 = 0.0f;
        }
        d = lbl_80472D04[unk_6C4].z - lbl_80472D04[unk_6C0].z;
        if (0.0f < d) {
            unk_750 = 1.0f;
        } else if (d < 0.0f) {
            unk_750 = -1.0f;
        } else {
            unk_750 = 0.0f;
        }
        if (unk_6C4 < 5) {
            speed = 3.0f;
            accel = 0.08f;
            if (unk_750 > 0.0f) {
                z_accel = accel;
                z_speed = 5.0f;
            } else {
                z_speed = 7.0f;
                z_accel = 0.2f;
            }
        } else {
            speed = 6.0f;
            accel = 0.16f;
            if (unk_750 > 0.0f) {
                z_accel = accel;
                z_speed = 10.0f;
            } else {
                z_speed = 14.0f;
                z_accel = 0.4f;
            }
        }
        motion_x.init_params(speed, fabs_float(lbl_80472D04[unk_6C4].x - position.x), accel);
        motion_y.init_params(speed, fabs_float(lbl_80472D04[unk_6C4].y - position.y), accel);
        if (unk_750 > 0.0f) {
            motion_z.init_params(z_speed, fabs_float(lbl_80472D04[unk_6C4].z - position.z), z_accel);
        } else {
            motion_z.set_move_params(z_speed, fabs_float(lbl_80472D04[unk_6C4].z - position.z), z_accel, 0.05f);
        }
        if (0.0f != unk_750) {
            unk_6C8 = 0;
        } else {
            unk_6C8 = 1;
        }
        unk_6CC = 0;
        if (unk_750 > 0.0f) {
            if (0.0f != unk_74C) {
                unk_6D0 = 1;
            } else {
                unk_6D0 = 3;
            }
        } else {
            if (0.0f != unk_74C) {
                unk_6D0 = 0;
            } else {
                unk_6D0 = 2;
            }
        }
        if (0.0f != unk_758) {
            unk_72C = 4;
            if (unk_758 > 0.0f) {
                sub_802E7B40();
                play_sound_at(0x39902, unk_50C);
                unk_628 &= ~0x400;
            } else {
                sub_802E7B94();
                play_sound_at(0x39E01, unk_50C);
                unk_628 |= 0x400;
            }
        } else {
            switch (unk_6C0) {
            case 1:
            case 6:
                unk_72C = 2;
                break;
            case 3:
            case 8:
                unk_72C = 0;
                break;
            default:
                switch (unk_6C4) {
                case 1:
                case 6:
                    unk_72C = 1;
                    break;
                case 3:
                case 8:
                    unk_72C = 3;
                    break;
                default:
                    unk_72C = 3;
                    break;
                }
                break;
            }
        }
    case 2:
        if (unk_728 == 1) {
            set_state_and_send(2);
        }
        break;
    case 9:
        if (unk_728 == 1) {
            if (unk_628 & 0x800) {
                unk_628 &= ~0x800;
                switch (unk_6C4) {
                case 0:
                    set_state_and_send(0xF);
                    break;
                case 2:
                    set_state_and_send(0x10);
                    break;
                case 1:
                default:
                    advance_action_sequence();
                    break;
                }
            } else {
                advance_action_sequence();
            }
        }
        break;
    case 0:
        this->advance_animation();
        sub_802EC32C();
        done = 0;
        switch (unk_72C) {
        case 0:
            done = update_phase_rising();
            break;
        case 1:
            done = update_anim_state();
            position.z = unk_748 + motion_z.travelled;
            break;
        case 2:
            done = update_phase_settling();
            position.z = unk_748 - motion_z.travelled;
            break;
        case 3:
            done = update_tail_anim_state();
            position.z = unk_748 - motion_z.travelled;
            break;
        case 4:
            done = 0;
            if (is_all_parts_done()) {
                play_speed += 0.1f;
                if (play_speed > 0.9f) {
                    done = 1;
                }
            } else if (unk_758 < 0.0f) {
                play_speed = 0.3f;
            }
            position.z = unk_748 - motion_z.travelled;
            break;
        }
        if (done) {
            unk_728 = 1;
        }
        position.x = motion_x.travelled * unk_74C + unk_744;
        position.y = motion_y.travelled * unk_758 + unk_754;
        position.z = motion_z.travelled * unk_750 + unk_748;
        break;
    case 5:
        unk_6C0 = unk_6C4;
        break;
    }
}
void TBoss7DeRolLeC::sub_802EAAC8(u32 event, s32 position_index, s32 next_index) {
    switch (event) {
    case 4:
        sub_802ECBDC();
        unk_628 |= 4;
        unk_628 &= ~0x100;
        unk_6C0 = position_index;
        unk_6C4 = next_index;
        set_position_index(unk_6C0);
        if (unk_6C0 == 0) {
            set_field_b8(5);
            unk_744 = -1.0f;
        } else {
            set_field_b8(6);
            unk_744 = 1.0f;
        }
        unk_728 = 0;
        unk_72C = 0;
        unk_730 = 0;
        unk_748 = 0.0f;
        unk_74C = 0.0f;
        unk_754 = 0.0f;
        unk_758 = 0.0f;
        unk_750 = 0.0f;
        unk_734 = 0;
        break;
    case 2:
        if (unk_728 == 2) {
            set_state_and_send(2);
        }
        break;
    case 9:
        if (unk_728 == 2) {
            if (unk_628 & 0x800) {
                unk_628 &= ~0x800;
                switch (unk_6C4) {
                case 0:
                    set_state_and_send(0xF);
                    break;
                case 2:
                    set_state_and_send(0x10);
                    break;
                case 1:
                default:
                    advance_action_sequence();
                    break;
                }
            } else {
                advance_action_sequence();
            }
        }
        break;
    case 0:
        switch (unk_728) {
        case 0:
            advance_animation();
            if (!(motion_flags & 4)) {
                unk_728 = 1;
            }
            break;
        case 1:
            advance_animation();
            switch (unk_730) {
            case 0:
                if (frame >= 10.0f) {
                    unk_730 = 1;
                    unk_754 = 3.25f * unk_744;
                }
                break;
            case 1:
                if (frame >= 20.0f) {
                    unk_730 = 2;
                    unk_754 = -5.625f * unk_744;
                    unk_758 = ((270.0f - position.z) + 72.666664f * -unk_750) / 1034.6666f;
                    unk_7B0 = spawn_continuous_particle_effect_with_flags(&unk_7B4, 0x20F, 0x40);
                }
                break;
            case 2:
                if (frame >= 28.0f) {
                    unk_730 = 3;
                    unk_748 = (sub_802ED3E4() - unk_748) / 2.5f;
                    unk_74C = (2.0f * unk_748) / 56.666664f;
                    unk_754 = -6.5294123f * unk_744;
                    unk_734 = 0;
                }
                break;
            case 3:
                if (frame >= 45.0f) {
                    unk_730 = 4;
                    unk_754 = -15.0f * unk_744;
                    motion_z.set_move_params(7.0f, fabs_float(25.0f - position.z), 0.2f, 0.05f);
                    motion_z.speed = -(0.5f * unk_750);
                    unk_750 = position.z;
                    destroy_child();
                }
                break;
            case 4:
                if (frame >= 46.0f) {
                    unk_730 = 5;
                    unk_754 = unk_744 * ((-175.0f - position.x * unk_744) / 36.0f);
                }
                break;
            case 5:
                if (frame >= 64.0f) {
                    unk_730 = 6;
                }
                break;
            }
            if (requested_action != 1) {
                if (is_passing_frame(10.0f) != 0 || is_passing_frame(41.0f) != 0) {
                    play_sound_at(0x39905, &unk_50C[0]);
                } else if (is_passing_frame(25.0f) != 0) {
                    play_sound_at(0x39906, &unk_50C[0]);
                }
            }
            update_attached_orientation();
            unk_734++;
            if (unk_730 != 6) {
                f32 f = frame;
                if (f >= 24.0f && f <= 32.0f) {
                    if (unk_734 >= 3) {
                        Vec v;
                        s32 i;
                        unk_734 = 0;
                        VecCopy(&v, &position);
                        for (i = 0; i < 10; i++) {
                            if (v.y * unk_530[i].y < 0.0f) {
                                break;
                            }
                            VecCopy(&v, &unk_530[i]);
                        }
                        v.x = v.x - unk_744 * (20.0f * random_ratio() + 40.0f);
                        v.y = -5.0f;
                        v.z = v.z + (20.0f * calc_elapsed_scaled() + 70.0f);
                        spawn_particle_201(&v);
                    }
                } else if (f >= 41.0f && f <= 46.0f && unk_734 >= 3) {
                    Vec v;
                    unk_734 = 0;
                    VecCopy(&v, &position);
                    v.x = v.x + unk_744 * (20.0f * random_ratio() + 20.0f);
                    v.y = -5.0f;
                    v.z = v.z + (60.0f * calc_elapsed_scaled() + 10.0f);
                    spawn_particle_201(&v);
                }
            }
            switch (unk_730) {
            case 0:
                unk_750 -= 0.2f;
                position.z = position.z + unk_750;
                break;
            case 1:
                position.x = position.x + unk_754;
                position.z = position.z + unk_750;
                break;
            case 2:
                position.x = position.x + unk_754;
                unk_750 = unk_750 + unk_758;
                position.z = position.z + unk_750;
                unk_748 = sub_802ED3E4();
                break;
            case 3:
                position.x = position.x + unk_754;
                frame -= 0.19999999f;
                unk_6EC.y = unk_6EC.y + unk_748;
                unk_748 = unk_748 - unk_74C;
                position.z = position.z + unk_750;
                break;
            case 4:
                position.x = position.x + unk_754;
                update_wobble_angle();
                advance_scalar_motion_profile(&motion_z);
                position.z = unk_750 - motion_z.travelled;
                break;
            case 5:
                position.x = position.x + unk_754;
                update_wobble_angle();
                advance_scalar_motion_profile(&motion_z);
                position.z = unk_750 - motion_z.travelled;
                break;
            case 6:
                update_wobble_angle();
                if (advance_scalar_motion_profile(&motion_z) == 3) {
                    unk_728 = 2;
                }
                position.z = unk_750 - motion_z.travelled;
                if (requested_action == 1) {
                    unk_628 |= 0x100;
                }
                break;
            }
            break;
        }
        break;
    case 5:
        unk_6C0 = unk_6C4;
        unk_628 &= ~4;
        break;
    }
}
#pragma push
#pragma fp_contract on
#pragma push
#pragma opt_common_subs off
#undef self
void TBoss7DeRolLeC::sub_802EA4D8(u32 event) {
    switch (event) {
    case 4:
        set_field_b8(1);
        sub_802ECBDC();
        unk_628 |= 4;
        unk_628 &= ~0x100;
        unk_6C0 = 3;
        set_position_index(unk_6C0);
        unk_728 = 0;
        unk_730 = 0;
        unk_72C = 0;
        unk_744 = 0.0f;
        unk_748 = 0.0f;
        unk_74C = 0.0f;
        unk_750 = 0.0f;
        unk_734 = 0;
        break;
    case 2:
        if (unk_728 == 3) {
            set_state_and_send(2);
        }
        break;
    case 9:
        if (unk_728 == 3) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        switch (unk_728) {
        case 0:
            unk_730++;
            if (unk_730 > 0x14) {
                set_field_b8(4);
                unk_728 = 1;
            }
            unk_74C -= 0.2f;
            if (unk_74C < -7.0f) {
                unk_74C = -7.0f;
            }
            position.z += unk_74C;
            break;
        case 1:
            if (!(motion_flags & 4)) {
                unk_728 = 2;
            }
            break;
        case 2:
            switch (unk_72C) {
            case 0:
                if (frame >= 10.5f) {
                    unk_72C = 1;
                    unk_750 = ((300.0f - position.z) + 49.102562f * -unk_74C) / 732.1581f;
                    unk_734 = 0;
                }
                break;
            case 1:
                if (frame >= 16.0f) {
                    unk_72C = 2;
                    unk_744 = (4.0f * (40.0f - position.y)) / 30.76923f;
                    unk_748 = (2.0f * unk_744) / 30.76923f;
                    unk_734 = 0;
                }
                break;
            case 2:
                if (frame >= 22.0f) {
                    unk_72C = 3;
                    unk_74C *= 0.5f;
                    unk_750 = 0.0f;
                }
                break;
            case 3:
                if (frame >= 29.0f) {
                    unk_72C = 4;
                }
                break;
            }
            if (requested_action != 1) {
                if (is_passing_frame(4.0f) != 0 || is_passing_frame(22.0f) != 0) {
                    play_sound_at(0x39905, &unk_50C[0]);
                } else if (is_passing_frame(14.0f) != 0) {
                    play_sound_at(0x39906, &unk_50C[0]);
                }
            }
            switch (unk_72C) {
            case 1:
                unk_734++;
                if (frame >= 13.5f && unk_734 >= 2) {
                    Vec v;
                    unk_734 = 0;
                    VecCopy(&v, &position);
                    v.x = 50.0f * calc_elapsed_scaled() + v.x;
                    v.y = -5.0f;
                    v.z += 180.0f;
                    spawn_particle_201(&v);
                }
                break;
            case 2:
            case 3:
                unk_734++;
                if (unk_734 >= 2) {
                    f32 f = frame;
                    if (f >= 21.0f && f <= 26.0f) {
                        Vec v;
                        unk_734 = 0;
                        VecCopy(&v, &position);
                        v.x = 50.0f * calc_elapsed_scaled() + v.x;
                        v.y = -5.0f;
                        v.z += -20.0f;
                        spawn_particle_201(&v);
                    }
                }
                break;
            }
            switch (unk_72C) {
            case 0:
                unk_74C -= 0.2f;
                if (unk_74C < -7.0f) {
                    unk_74C = -7.0f;
                }
                position.z += unk_74C;
                break;
            case 1:
                unk_74C += unk_750;
                position.z += unk_74C;
                unk_744 = sub_802ED3E4();
                break;
            case 2:
                position.z += unk_74C;
                unk_6EC.y += unk_744;
                unk_744 -= unk_748;
                frame -= 0.105000004f;
                break;
            case 3:
            case 4:
                if (unk_750 <= 0.0f) {
                    unk_74C -= 0.2f;
                    if (unk_74C <= 0.0f) {
                        unk_750 = 1.0f;
                        motion_z.set_move_params(7.0f, fabs_float(500.0f - position.z), 0.2f, 0.05f);
                        unk_74C = position.z;
                    } else {
                        position.z += unk_74C;
                    }
                } else if (advance_scalar_motion_profile(&motion_z) == 3) {
                    unk_728 = 3;
                } else {
                    position.z = unk_74C - motion_z.travelled;
                }
                update_wobble_angle();
                break;
            }
            break;
        }
        break;
    case 5:
        unk_6C0 = 1;
        unk_628 &= ~4;
        break;
    }
}
#define self ((Fish_802E9DBC *) arg0)
void TObjFish__sub_802E9DBC(u8 *arg0, u32 arg1, s32 arg2) {
    void *p_;
    switch (arg1) {
    case 4:
        ((TObjMotion *)self)->set_field_b8(1);
        ((TBoss7DeRolLeC *)self)->sub_802ECBDC();
        self->flags |= 4;
        self->flags &= ~0x100;
        self->mode = arg2;
        ((TBoss7DeRolLeC *)self)->set_position_index(self->mode);
        self->f744 = 0.0f;
        self->f750 = 0.0f;
        self->f74C = 0.0f;
        self->f748 = 0.0f;
        self->f754 = -0.2f;
        self->f758 = 0.0f;
        self->f75C = self->z;
        self->f760 = 0.0f;
        self->timer = 0;
        self->state = 0;
        self->tick = 0;
        self->ptcl = NULL;
        self->count = 0;
        break;
    case 2: {
        u32 f = *(u32 *)(self->f624 + 8);
        if (f & 0x400) {
            if (self->mode == 0) {
                ((TBoss7DeRolLeC *)self)->set_state_and_send(0x13);
            } else {
                ((TBoss7DeRolLeC *)self)->set_state_and_send(0x14);
            }
        } else if (f & 4) {
            if (self->mode == 0) {
                ((TBoss7DeRolLeC *)self)->set_state_and_send(0x15);
            } else {
                ((TBoss7DeRolLeC *)self)->set_state_and_send(0x16);
            }
        }
        break;
    }
    case 9:
        if (self->fB8 == 10 || self->fB8 == 9) {
            ((TBoss7DeRolLeC *)self)->advance_action_sequence();
        }
        break;
    case 0:
        ((TObjMotion *)self)->advance_animation();
        switch (self->state) {
        case 0:
            self->timer++;
            if (self->timer > 10) {
                self->timer = 0;
                self->state = 1;
                if (self->mode == 0) {
                    ((TObjMotion *)self)->set_field_b8(7);
                    self->f744 = -1.0f;
                } else {
                    ((TObjMotion *)self)->set_field_b8(8);
                    self->f744 = 1.0f;
                }
            }
            break;
        case 1:
            if (!(self->fB0 & 4)) {
                self->state = 2;
            }
            break;
        case 2:
            if (self->frame >= 6.0f) {
                self->state = 3;
                self->f750 = 0.0f;
                self->f748 = self->x;
                self->f74C = (100.0f * self->f744 - self->f748) / 7.0f;
                self->f754 = -(self->f758 / 7.0f);
                self->f75C = self->z;
                self->f758 = 0.0f;
            }
            break;
        case 3:
            if (self->frame >= 13.0f) {
                self->state = 4;
                self->f750 = 0.0f;
                self->f748 = 100.0f * self->f744;
                self->f74C = (135.0f * self->f744 - self->f748) / 7.0f;
                self->f75C = self->z;
                self->f754 = (2.0f * (10.0f - self->z)) / 144.0f;
                self->f758 = 0.0f;
            }
            break;
        case 4:
            if (self->frame >= 20.0f) {
                self->state = 5;
                self->f750 = 0.0f;
                self->f748 = 135.0f * self->f744;
                self->f74C = (100.0f * self->f744 - self->f748) / 5.0f;
                self->f760 = (1280.0f * -self->f744) / 5.0f;
            }
            break;
        case 5:
            if (self->frame >= 25.0f) {
                s32 i;
                self->state = 6;
                TCameraCtrl::set_shake_preset(1);
                if (self->mode == 0) {
                    TObjBoss2Tunnel__sub_802F22DC();
                } else {
                    TObjBoss2Tunnel__sub_802F22C4();
                }
                ((TBoss7DeRolLeC *)self)->play_sound_at(0x3A107, (Vec *)(self->eff));
                new TUnk_804F1C88((TBoss7DeRolLeC *)self, &self->p4DC);
                self->flags |= 0x200;
                for (i = 0; i < 4; i++) {
                    ((TBoss7Tentacle *)self->tent[i])->sub_802F0B58();
                }
            }
            break;
        case 6:
            break;
        }
        self->tick++;
        if (self->state != 0 && self->state != 1) {
            if (self->frame >= 15.0f && self->frame <= 17.0f && self->tick >= 2) {
                Vec v;
                f32 s;
                self->tick = 0;
                ((void (*)(void *, void *)) VecCopy__FP3VecPC3Vec)(&v, &self->p4DC);
                s = 50.0f * ((TObjChara *)self)->random_ratio();
                v.x = v.x - self->f744 * s;
                v.y = -5.0f;
                v.z += 40.0f;
                ((TBoss7DeRolLeC *)self)->spawn_particle_201(&v);
            }
            if (((TObjMotion *)self)->is_passing_frame(15.0f) != 0) {
                ((TBoss7DeRolLeC *)self)->play_sound_at(0x39905, (Vec *)(self->eff));
            }
            p_ = self->ptcl;
            if (p_ == NULL) {
                self->ptcl = create_particle_emitter(&self->x, 0x161);
                if (self->ptcl != NULL) {
                    ((TParticleCtrl *)(self->ptcl))->enable();
                }
            } else if (self->frame >= 24.0f && self->frame <= 30.0f) {
                s32 r;
                self->count++;
                r = self->count % 4;
                if (r == 0) {
                    ((TParticleCtrl *)self->ptcl)->set_position(&self->p440);
                } else if (r == 2) {
                    ((TParticleCtrl *)self->ptcl)->set_position(&self->p44C);
                } else {
                    ((TParticleCtrl *)(self->ptcl))->enable();
                }
            } else {
                ((TParticleCtrl *)p_)->enable();
            }
        }
        switch (self->state) {
        case 0:
        case 1:
        case 2:
            self->f758 = self->f758 + self->f754;
            if (self->f758 < -7.0f) {
                self->f758 = -7.0f;
            }
            self->z = self->z + self->f758;
            break;
        case 3: {
            f32 t = self->frame - 6.0f;
            self->x = self->f74C * t + self->f748;
            { f32 h_ = 0.5f * self->f754; self->z = t * (h_ * t + -7.0f) + self->f75C; }
            if (((TObjMotion *)self)->is_passing_frame(8.5f) != 0) {
                ((TBoss7DeRolLeC *)self)->play_sound_at(0x39906, (Vec *)(self->eff));
            }
            break;
        }
        case 4: {
            f32 t = self->frame - 13.0f;
            self->x = self->f74C * t + self->f748;
            { f32 h_ = 0.5f * self->f754; self->z = t * (h_ * t) + self->f75C; }
            self->f6F0 = 28.0f * t;
            if (self->f6F0 > 4.0f) {
                self->f6F0 = 4.0f;
            }
            break;
        }
        case 5: {
            f32 t = self->frame - 20.0f;
            f32 t2;
            f32 d;
            self->x = self->f74C * t + self->f748;
            t2 = self->frame - 13.0f;
            { f32 h_ = 0.5f * self->f754; d = t2 * (h_ * t2); }
            self->z = self->f75C + d;
            ((TBoss7DeRolLeC *)self)->rotation_z = self->f760 * t;
            break;
        }
        case 6:
            break;
        }
        break;
    case 5:
        self->flags &= ~4;
        if (self->ptcl != NULL) {
            ((TObject *)self->ptcl)->queue_destruction();
            self->ptcl = NULL;
        }
        break;
    }
}
#pragma pop
#pragma pop
#undef self
void TBoss7DeRolLeC::handle_tentacle_attack_state(u32 event, s32 position_index) {
    s32 ang;
    Vec v;
    s32 ok;
    s32 i;
    s32 j;
    switch (event) {
    case 4:
        sub_802ECBDC();
        unk_628 &= ~4;
        unk_628 &= ~0x100;
        unk_6C0 = position_index;
        set_swim_direction(unk_6C0);
        if (unk_6C0 == 0) {
            set_field_b8(9);
        } else {
            set_field_b8(0xA);
        }
        unk_728 = 0;
        unk_72C = 0;
        unk_730 = 0;
        unk_734 = 0xB4;
        unk_738 = 0x78;
        break;
    case 2:
        if (unk_728 == 3) {
            if (unk_6C0 == 0) {
                set_state_and_send(0x15);
            } else {
                set_state_and_send(0x16);
            }
        }
        break;
    case 9:
        if (unk_728 == 3) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        switch (unk_728) {
        case 0:
            unk_72C++;
            if (unk_72C > 0x28) {
                unk_728 = 1;
                unk_72C = 0;
                unk_730 = 0;
            }
            break;
        case 1:
            unk_72C++;
            if (unk_72C >= unk_734) {
                unk_72C = 0;
                if (enemy_has_live_target() != 0) {
                    VecCopy(&v, &target->position);
                } else {
                    f32 r = 120.0f * random_ratio();
                    ang = get_random_scaled();
                    v.x = r * sin_table_lookup(ang);
                    v.y = -1.85f;
                    v.z = r * cos_table_lookup(ang);
                    TObjBoss2Tunnel::adjust_to_ground((saddr)&v, (void *)&v);
                }
                unk_6DC[unk_730]->start_attack_at_position((u8 *)&v, unk_738);
                unk_730++;
                if (unk_730 >= 4) {
                    unk_72C = 0;
                    unk_728 = 2;
                }
            }
            break;
        case 2:
            ok = 1;
            unk_72C++;
            for (i = 0; i < 4; i++) {
                if (unk_6DC[i]->sub_802F0904() == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok != 0 || unk_72C > 0x258) {
                unk_728 = 3;
            }
            break;
        }
        break;
    case 6:
        pick_random_target();
        break;
    case 5:
        for (j = 0; j < 4; j++) {
            unk_6DC[j]->sub_802F0AF0();
        }
        break;
    }
}
#pragma push
#pragma fp_contract on
#pragma push
#pragma opt_common_subs off
void TBoss7DeRolLeC::sub_802E979C(u32 event, s32 position_index) {
    switch (event) {
    case 4:
        for (s32 i = 0; i < 4; i++) {
            unk_6DC[i]->sub_802F0AF0();
        }
        sub_802ECBDC();
        unk_628 |= 4;
        unk_628 &= 0xFFFFFEFF;
        unk_6C0 = position_index;
        set_swim_direction(unk_6C0);
        if (unk_6C0 == 0) {
            unk_748 = -1.0f;
            set_field_b8(9);
        } else {
            unk_748 = 1.0f;
            set_field_b8(0xA);
        }
        unk_728 = 0;
        unk_72C = 0;
        unk_744 = 0.0f;
        unk_750 = -1.0f;
        unk_74C = 0.0f;
        unk_73C = 0x500;
        TObjBoss2Tunnel::clear_flags_0x3000();
        unk_628 &= 0xFFFFFDFF;
        break;
    case 2:
        if (unk_728 == 2) {
            set_state_and_send(2);
        }
        break;
    case 9:
        if (unk_728 == 2) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        switch (unk_728) {
        case 0:
            unk_74C += 0.2f;
            position.z -= unk_74C;
            unk_744 += 0.08f;
            position.x += unk_744 * unk_748;
            unk_750 += 0.1f;
            unk_6EC.y -= unk_750;
            unk_73C += 256.0f;
            if (unk_73C >= 16384.0f) {
                unk_73C = 0x4000;
            }
            rotation_z = unk_73C * -unk_748;
            if (unk_72C == 0 && unk_73C >= 0x2200) {
                unk_72C = 1;
                play_sound_at(0x39906, &unk_50C[0]);
            }
            if (unk_6EC.y < -137.0f) {
                unk_728 = 1;
                set_position_index(unk_6C0);
                unk_6EC.y = -137.0f;
                set_field_b8(1);
                unk_750 = 0.0f;
                unk_628 &= ~4;
                unk_628 |= 0x100;
            }
            break;
        case 1:
            unk_6EC.y += 2.0f;
            if (unk_6EC.y >= 0.0f) {
                unk_6EC.y = 0.0f;
                unk_728 = 2;
            }
            break;
        }
        break;
    case 5:
        unk_628 &= ~4;
        break;
    case 1: case 3: case 6: case 7: case 8:
        break;
    }
}
#pragma pop
#pragma pop
#pragma pop
void TBoss7DeRolLeC::sub_802E95F8(u32 event, s32 position_index) {
    s32 joint;
    switch (event) {
    case 4:
        set_field_b8(3);
        sub_802ECBDC();
        unk_628 &= ~4;
        unk_628 &= ~0x100;
        unk_6C0 = position_index;
        set_position_index(unk_6C0);
        unk_728 = 0;
        unk_72C = 0;
        unk_744 = -1000.0f;
        unk_704++;
        if (unk_704 >= 3) {
            unk_704 = 0;
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
        switch (unk_72C) {
        case 0:
            if (!(motion_flags & 4)) {
                sub_802ECE90(unk_728, unk_704);
                unk_72C = 1;
                return;
            }
            break;
        case 1:
            joint = unk_728;
            if (unk_530[joint].y < unk_530[joint + 1].y) {
                unk_728 = joint + 1;
                if ((f32)unk_728 >= 4.0f) {
                    unk_72C = 2;
                }
                sub_802ECE90(unk_728, unk_704);
            }
            break;
        }
        break;
    }
}
#pragma push
#pragma fp_contract on
void TBoss7DeRolLeC::sub_802E9458(u32 event) {
    Vec v;
    f32 f;

    switch (event) {
    case 4:
        unk_628 &= ~4;
        unk_628 |= 0x100;
        sub_802ECBDC();
        set_field_b8(0xC);
        unk_6C0 = 3;
        set_position_index(unk_6C0);
        unk_728 = 0;
        unk_724 = 0;
        return;
    case 2:
        if (requested_action == 0xF) {
            set_state_and_send(0x18);
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
        unk_728++;
        f = frame;
        if ((f >= 10.0f) && (f <= 14.0f) && ((f32)unk_728 >= 3.0f)) {
            unk_728 = 0;
            VecCopy(&v, &position);
            v.x = 30.0f * calc_elapsed_scaled() + v.x;
            v.y = -5.0f;
            v.z += 80.0f;
            spawn_particle_201(&v);
        }
        if (is_passing_frame(10.0f) != 0) {
            play_sound_at(0x39905, &unk_50C[0]);
        }
        break;
    }
}
#pragma pop
void TBoss7DeRolLeC::sub_802E8FCC(u32 event) {
    Vec from;
    CsnHit *hit;
    Vec *aim = &unk_76C;
    Vec *beam_end;
    switch (event) {
    case 4:
        unk_628 &= ~4;
        unk_628 |= 0x100;
        sub_802ECBDC();
        set_field_b8(0xF);
        unk_6C0 = 3;
        set_position_index(unk_6C0);
        fill_value_array((saddr)unk_718);
        unk_728 = 0;
        unk_72C = 0;
        unk_730 = 0;
        unk_73C = 0;
        unk_748 = 0.0f;
        aim->x = 0.0f;
        aim->y = 0.0f;
        aim->z = 0.0f;
        unk_784 = NULL;
        return;
    case 2:
        if (unk_728 == 4) {
            if (unk_724 >= 4) {
                set_state_and_send(0x19);
            } else {
                set_state_and_send(0x18);
            }
        }
        break;
    case 9:
        if (unk_728 == 4) {
            advance_action_sequence();
            return;
        }
        break;
    case 0:
        advance_animation();
        unk_7A0 = 6;
        switch (unk_728) {
        case 0:
            unk_72C++;
            if (unk_72C >= 0x14) {
                unk_72C = 0;
                unk_728 = 1;
                fill_value_array((saddr)unk_718);
                set_field_b8(0xD);
                if (enemy_check_target_valid() != 0) {
                    VecCopy(aim, &target->position);
                } else {
                    aim->x = 0.0f;
                    aim->y = 0.0f;
                    aim->z = 0.0f;
                }
                if (unk_7A8 != NULL) {
                    unk_7A8->queue_destruction();
                }
                unk_7A8 = new TBoss7LaserPtcl(this, (TBoss7LaserPtclVector *)&unk_4DC[0], (TBoss7LaserPtclVector *)aim);
                sub_802ECE28();
                turn_on_laser_light();
                play_sound_at(0x39E0F, &unk_50C[0]);
                return;
            }
            break;
        case 1:
            if (unk_7A8 != NULL) {
                unk_7A8->calc_position((u8 *)&unk_4DC[0], (u8 *)&unk_4DC[1]);
            }
            if (12.0f < frame && unk_7A8 != NULL) {
                unk_7A8->destroy_particles();
            }
            sub_802ECE28();
            if (13.0f <= frame) {
                frame = 13.0f;
                unk_728 = 2;
                if (unk_7A8 != NULL) {
                    unk_7A8->init_laser();
                }
                play_sound_at(0x3A310, &unk_50C[0]);
                return;
            }
            break;
        case 2:
            beam_end = &unk_778;
            frame = 13.0f;
            if (unk_7A8 != NULL) {
                unk_7A8->calc_position((u8 *)&unk_4DC[0], (u8 *)&unk_4DC[1]);
                unk_7A8->calc_world_position(beam_end);
                calc_laser_ray_hit_point((u8 *)unk_7A8, (u8 *)&from);
            }
            hit = csnVector(&from, beam_end, 0x16EF);
            if (hit != NULL) {
                VecCopy(beam_end, &hit->contact->point);
                if (unk_71C == NULL) {
                    unk_71C = new TUnk_804E4788(this, 6, 0x208);
                } else {
                    unk_71C->push_ring_point(beam_end);
                }
                if (unk_720 == NULL) {
                    unk_720 = new TUnk_804E4788(this, 0xF, 0x209);
                } else {
                    unk_720->push_ring_point(beam_end);
                }
            }
            {
                Boss7AttackParams params = boss7_laser_particle_params;
                params.field_4 = unk_620->unk_00;
                TObjEneDD::setup_instance((saddr)this, (saddr)beam_end, (u8 *)&params, (saddr)unk_718);
            }
            if (unk_7A8 != NULL) {
                if (unk_7A8->is_state_2() != 0) {
                    unk_728 = 3;
                    return;
                }
            } else {
                unk_728 = 3;
                return;
            }
            break;
        case 3:
            if (get_flag_b4() != 0) {
                unk_728 = 4;
                return;
            }
            break;
        }
        break;
    case 6:
        pick_random_target();
        return;
    case 5:
        unk_724++;
        turn_off_laser_light();
        if (unk_784 != NULL) {
            unk_784->queue_destruction();
            unk_784 = NULL;
        }
        if (unk_71C != NULL) {
            unk_71C->queue_destruction();
            unk_71C = NULL;
        }
        if (unk_720 != NULL) {
            unk_720->queue_destruction();
            unk_720 = NULL;
        }
        if (unk_7A8 != NULL) {
            unk_7A8->queue_destruction();
            unk_7A8 = NULL;
        }
        break;
    }
}

void TBoss7DeRolLeC::sub_802E8EEC(u32 event, s32) {
    switch (event) {
    case 4:
        unk_628 &= ~4;
        unk_628 |= 0x100;
        set_field_b8(0xE);
        sub_802ECBDC();
        unk_6C0 = 3;
        set_position_index(unk_6C0);
        break;
    case 2:
        if (requested_action == 1) {
            set_state_and_send(2);
            break;
        }
    default:
        break;
    case 9:
        if (requested_action == 1) {
            advance_action_sequence();
            break;
        }
        break;
    case 0:
        advance_animation();
        if (is_passing_frame(8.0f) != 0) {
            play_sound_at(0x39906, &unk_50C[0]);
        }
        break;
    }
}

void TBoss7DeRolLeC::sub_802E8E34(u32 event) {
    switch (event) {
    case 4:
        unk_628 |= 4;
        unk_628 &= ~0x100;
        sub_802ECC44();
        rotation_x = 0;
        unk_6EC.y = 0.0f;
        return;
    case 9:
        if (requested_action == 1) {
            advance_action_sequence();
        }
        return;
    case 8:
        if (unk_6EC.y < -200.0f) {
            set_state_and_send(0x1C);
        }
        return;
    case 0:
        unk_6EC.y -= 2.0f;
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    }
}

void TBoss7DeRolLeC::handle_death_state(u32 event) {
    CameraPlayback cam;
    s32 i;
    switch (event) {
    case 4:
        unk_628 &= ~0x300;
        unk_628 |= 4;
        sub_802ECC44();
        set_field_b8(0x10);
        unk_6C0 = 3;
        set_position_index(unk_6C0);
        rotation_x = 0;
        unk_6EC.y = 0.0f;
        unk_728 = 0;
        unk_72C = 0;
        unk_73C = 0;
        unk_6FC = 0;
        for (i = 0; i < 4; i++) {
            unk_6DC[i]->sub_802F0AD0();
        }
        if (crawfish_parent != NULL) {
            crawfish_parent->queue_destruction_for_each_node();
        }
        TObjBoss2Tunnel::clear_flags_0x3000();
        TWindowCtrl::init_all_slots();
        {
            cam.index = 0;
            cam.bank = 2;
            cam.flags = 0;
            cam.frame = 0.0f;
            cam.frame_step = 0.7f;
            activate_camera_mode(5);
            cam.cache_target_and_forward(0x1C71);
        }
        break;
    case 2:
        if (unk_624->unknown_08 & 0x400) {
            actorFlags &= ~0x800;
            sub_802ECBDC();
            set_state_and_send(2);
        }
        break;
    case 9:
        if (unk_728 == 1) {
            set_state_and_send(0x1D);
        }
        break;
    case 0:
        advance_animation();
        if (get_scripted_camera_playback()->flags & 1) {
            unk_728 = 1;
            TWindowCtrl::init_all_slots2();
            restore_player_cameras();
        }
        if (is_passing_frame(85.0f) != 0) {
            Vec v = lbl_80473F90;
            create_timed_particle_emitter_with_flags(&v, 0x20C, 0, 0xA0, 0x40);
            play_sound_effect(0x39614, NULL, 0, 0);
        }
        if (is_passing_frame(20.0f) != 0) {
            destroy_child();
            unk_7B0 = spawn_continuous_particle_effect_with_flags(&unk_7B4, 0x20F, 0x40);
        }
        if (is_passing_frame(123.0f) != 0) {
            destroy_child();
        }
        update_attached_orientation();
        break;
    case 5: {
        Vec saved;
        VecCopy(&saved, &position);
        position.x = 0.0f;
        position.y = 12.0f;
        position.z = -90.0f;
        update_prev_position();
        for (i = 0; i != 10; i++) {
            assign_slots_from_list(this, (saddr)unk_5F8[i]);
        }
        refresh_and_send_entity_flags();
        set_story_flag_or_send_quest_flag(0x4C);
        VecCopy(&position, &saved);
        update_prev_position();
        actorFlags = 0x12008;
        vfunc_74(0);
        TWindowCtrl::init_all_slots2();
        restore_player_cameras();
        break;
    }
    }
}

void TBoss7DeRolLeC::sub_802E8AD4(u32 event) {
    switch (event) {
    case 4:
        set_field_b8(0x10);
        sub_802ECC44();
        unk_628 |= 4;
        unk_628 &= ~0x100;
        TObjBoss2Tunnel::set_flag_0x200();
        return;
    case 0:
        queue_destruction();
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

void TBoss7DeRolLeC::handle_crawfish_spawn_state(u32 event, s32 variant) {
    s32 index;
    switch (event) {
    case 4:
        unk_72C = 9;
        unk_728 = 0;
        unk_730 = 0;
        set_field_b8(1);
        return;
    case 0:
        advance_animation();
        index = unk_728;
        if (index < unk_72C) {
            if (unk_730 <= 0) {
                unk_728 = index + 1;
                try_spawn_pattern_crawfish(variant, index);
                unk_730 = 5;
            } else {
                unk_730--;
            }
            return;
        }
        advance_action_sequence();
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

void TBoss7DeRolLeC::sub_802E8990(u32 event) {
    switch (event) {
    case 4:
        unk_728 = play_mode;
        play_mode = 1;
        return;
    case 0:
        advance_animation();
        if (crawfish_parent->get_node_count() == 0) {
            advance_action_sequence();
        }
        return;
    case 5:
        play_mode = unk_728;
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

void TBoss7DeRolLeC::sub_802E88F8(u32 event) {
    switch (event) {
    case 4:
        unk_728 = lbl_804E3C2C[game_difficulty_selection][action_index].b * 30;
        return;
    case 0:
        advance_animation();
        if (unk_728-- == 0) {
            advance_action_sequence();
        }
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}
void TBoss7DeRolLeC::sub_802E85E0(u32 event, s32 position_index) {
    Vec v;
    f32 scale;
    s32 r;
    s32 ok;
    s32 j;
    s32 i;
    s32 k;
    switch (event) {
    case 4:
        sub_802ECBDC();
        unk_628 &= ~4;
        unk_628 &= ~0x100;
        unk_6C0 = position_index;
        set_swim_direction(unk_6C0);
        if (unk_6C0 == 0) {
            set_field_b8(9);
        } else {
            set_field_b8(0xA);
        }
        unk_728 = 0;
        unk_72C = 0;
        unk_730 = 0;
        unk_734 = 0xB4;
        unk_738 = 0x78;
        return;
    case 2:
        if (unk_728 == 3) {
            if (unk_6C0 == 0) {
                set_state_and_send(0x15);
            } else {
                set_state_and_send(0x16);
            }
        }
        return;
    case 9:
        if (unk_728 == 3) {
            advance_action_sequence();
        }
        return;
    case 0:
        advance_animation();
        switch (unk_728) {
        case 0:
            unk_72C++;
            if (unk_72C > lbl_804E3C2C[game_difficulty_selection][action_index].b * 0x1E) {
                unk_728 = 1;
                unk_72C = 0;
                unk_730 = 0;
            }
            break;
        case 1:
            unk_72C++;
            if (unk_72C >= unk_734) {
                if (unk_730 == 0) {
                    unk_72C = 0;
                    if (enemy_has_live_target() != 0) {
                        VecCopy(&v, &target->position);
                    } else {
                        scale = 120.0f * random_ratio();
                        r = get_random_scaled();
                        v.x = scale * sin_table_lookup(r);
                        v.y = -1.85f;
                        v.z = scale * cos_table_lookup(r);
                        TObjBoss2Tunnel::adjust_to_ground((saddr)&v, (void *)&v);
                    }
                    for (j = 0; j != 4; j++) {
                        unk_6DC[j]->start_attack_at_position((u8 *)&v, unk_738);
                    }
                    unk_730 = 1;
                    unk_72C = 0;
                } else {
                    unk_728 = 2;
                }
            }
            break;
        case 2:
            ok = 1;
            unk_72C++;
            for (i = 0; i < 4; i++) {
                if (unk_6DC[i]->sub_802F0904() == 0) {
                    ok = 0;
                    break;
                }
            }
            if (ok != 0 || unk_72C > 600) {
                unk_728 = 3;
            }
            break;
        }
        return;
    case 6:
        pick_random_target();
        return;
    case 5:
        for (k = 0; k < 4; k++) {
            unk_6DC[k]->sub_802F0AF0();
        }
        return;
    case 1:
    case 3:
    case 7:
    case 8:
        return;
    }
}
void TBoss7DeRolLeC::sub_802E8584(u32 event) {
    switch (event) {
    case 0:
        advance_animation();
        sub_802E7B94();
        advance_action_sequence();
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 4: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

void TBoss7DeRolLeC::sub_802E8528(u32 event) {
    switch (event) {
    case 0:
        advance_animation();
        sub_802E7B40();
        advance_action_sequence();
        return;
    case 1: return;
    case 2: return;
    case 3: return;
    case 4: return;
    case 5: return;
    case 6: return;
    case 7: return;
    case 8: return;
    case 9: return;
    }
}

void TBoss7DeRolLeC::sub_802E83E8(u32 event) {
    u8 *player;
    void *o;
    u16 id;
    u16 n;
    switch (event) {
    case 4:
        set_field_b8(1);
        set_position_index(9);
        unk_728 = 20;
        unk_72C = 12;
        id = 0;
        n = 0;
        while (n != 4) {
            if (get_player_by_client_id(id = (id + 1) & 3) != NULL) {
                needle_targets[n++] = id;
            }
        }
        break;
    case 9:
        if (unk_72C == 0) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        if (unk_72C > 0) {
            if (unk_728 == 0) {
                unk_728 = 20;
                unk_72C--;
                player = (u8 *)get_player_by_client_id(needle_targets[unk_72C & 3]);
                if (player != NULL) {
                    new TBoss7TentacleNeedle(this, (Vec *)(player + 0x38));
                }
            } else {
                unk_728--;
            }
        }
        break;
    case 6:
        pick_random_target();
        break;
    }
}
#pragma pop

void TObjPlayer__sub_802E8274(NJS_OBJECT *) {
    LAYOUT_ASSERT(sp8_offset, offsetof(Stack_802E8274, sp8) == 0x0);
    LAYOUT_ASSERT(spC_offset, offsetof(Stack_802E8274, spC) == 0x4);
    LAYOUT_ASSERT(sp10_offset, offsetof(Stack_802E8274, sp10) == 0x8);
    LAYOUT_ASSERT(sp14_offset, offsetof(Stack_802E8274, sp14) == 0xC);
    LAYOUT_ASSERT(sp18_offset, offsetof(Stack_802E8274, sp18) == 0x10);
    LAYOUT_ASSERT(sp1C_offset, offsetof(Stack_802E8274, sp1C) == 0x14);
    LAYOUT_ASSERT(sp20_offset, offsetof(Stack_802E8274, sp20) == 0x18);
    LAYOUT_ASSERT(sp24_offset, offsetof(Stack_802E8274, sp24) == 0x1C);
    LAYOUT_ASSERT(sp28_offset, offsetof(Stack_802E8274, sp28) == 0x20);
    Stack_802E8274 stack;
    if ((s32) boss7_derolle_c_motion_id == 0x5F) {
        stack.sp20 = 0.0f;
        stack.sp24 = 0.0f;
        stack.sp28 = 0.0f;
        transform_point_by_current_matrix((void *)&stack.sp20, (void *)lbl_805D6944);
    }
    if ((s32) boss7_derolle_c_motion_id == 0x71) {
        stack.sp14 = 0.0f;
        stack.sp18 = 0.0f;
        stack.sp1C = 0.0f;
        transform_point_by_current_matrix((void *)&stack.sp14, (void *)(lbl_805D6944 + 0xC));
    }
    if ((s32) boss7_derolle_c_motion_id == lbl_80472CB0[lbl_805D6920]) {
        stack.sp8 = 0.0f;
        stack.spC = 0.0f;
        stack.sp10 = 0.0f;
        transform_point_by_current_matrix((void *)&stack.sp8, (void *)lbl_805D6928);
        lbl_805D6920 += 1;
        lbl_805D6928 += 0xC;
    }
    if ((s32) boss7_derolle_c_motion_id == 0x33) {
        push_matrix();
        matrix_mult_vec_array(NULL, (const Vec *)lbl_804E3BFC, (Vec *)lbl_805D692C, 4);
        pop_matrix();
        subtract_vector((void *)(lbl_805D692C + 0xC), (void *)lbl_805D692C);
    }
    if ((lbl_805D6924 & 0x80) && ((s32) boss7_derolle_c_motion_id >= 0x4D) && ((s32) boss7_derolle_c_motion_id <= 0x58)) {
        push_matrix();
        get_current_matrix((void *)lbl_805D6934);
        pop_matrix();
        lbl_805D6934 += 0x30;
    }
    if (((s32) boss7_derolle_c_motion_id >= 0x1D) && ((s32) boss7_derolle_c_motion_id <= 0x20)) {
        push_matrix();
        get_current_matrix((void *)lbl_805D6930);
        pop_matrix();
        lbl_805D6930 += 0x30;
    }
    boss7_derolle_c_motion_id += 1;
}

void TBoss7DeRolLeC::sub_802E8234() {
    boss7_derolle_c_motion_id = 0;
    lbl_805D6924 = this->unk_628;
    lbl_805D6920 = 0;
    lbl_805D6928 = (long) (((u8 *)this) + 0x3EC);
    lbl_805D6930 = (saddr)this->unk_6D8;
    lbl_805D6934 = (saddr)this->unk_6D4;
    lbl_805D692C = (long) (((u8 *)this) + 0x4DC);
    lbl_805D6944 = (long) (((u8 *)this) + 0x7B4);
}

void TBoss7DeRolLeC::render() {
    s32 *var_r30;
    s32 var_r29;
    if (!((s32)main_task.get_task_flags() & 0x20) || !(*(f32 *)((s8 *)((u8 *)this) + 0x3C) < -35.0f)) {
        var_r30 = (s32 *)(((u8 *)this) + 0x5F8);
        var_r29 = 0;
        do {
            if (((TBoss7Joint *)(*var_r30))->is_part_active() != 0U) {
                hide_joint_polygons(var_r29);
            }
            var_r29 += 1;
            var_r30 = (s32 *)((u8 *)var_r30 + (4));
        } while (var_r29 != 0xA);
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        copy_argb((NJS_ARGB *)&saved_model_draw_color.value, (NJS_ARGB *)&model_material_color.value);
        TObjEneDD::clear_global_flag_400();
        TParticleCtrl::begin_effect_render();
        push_matrix();
        if (this->unk_7AC != 0) {
            if (this->unk_628 & 0x40) {
                *(s32 **)((s8 *)lbl_805D693C + 0x2C) = &boss7_derolle_light_pool[0].type;
            } else {
                *(s32 **)((s8 *)lbl_805D693C + 0x2C) = (s32 *) lbl_805D6940;
            }
            TObjPlayer::draw_effect();
            ((TObjPlayer *)(this->unk_7AC))->draw_node_tree_if_visible();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
        copy_argb((NJS_ARGB *)&model_material_color.value, (NJS_ARGB *)&saved_model_draw_color.value);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
        restore_joint_polygons();
        this->unk_690.render_nodes();
    }
}

void TObjPlayer::draw_effect() { TObjFish::set_global_param((s32)get_bml_texlist((BmlResource *)lbl_805D6918, 0)); }

GinjaTextureList *TBoss7DeRolLeC::get_archive_textures() { return (GinjaTextureList *)get_bml_texlist((BmlResource *)lbl_805D6918, 0); }

NJS_OBJECT *TBoss7DeRolLeC::get_archive_model(s32 index) { return (NJS_OBJECT *)get_bml_model((BmlResource *)lbl_805D6918, index); }

AnimationMotion *get_boss7_motion(s32 kind) { return get_bml_motion((BmlResource *)lbl_805D6918, kind); }
void TBoss7DeRolLeC::restore_joint_polygons() {
    uaddr model;
    s32 i;
    NJS_OBJECT *node;
    model = (uaddr)get_archive_model(0);
    for (i = 0; i != 10; i++) {
        node = (NJS_OBJECT *)find_model_node(model, lbl_804739AC[i]);
        ((NJS_CNK_MODEL *)node->model)->polygon_list = joint_polygons[i];
        node = (NJS_OBJECT *)find_model_node(model, lbl_804739D4[i]);
        ((NJS_CNK_MODEL *)node->model)->polygon_list = shell_polygons[i];
    }
}

void TBoss7DeRolLeC::hide_joint_polygons(s32 joint) {
    NJS_OBJECT *node;
    if (joint >= 0 && joint < 10) {
        node = (NJS_OBJECT *)find_model_node((uaddr)get_archive_model(0), lbl_804739AC[joint]);
        if (node != NULL) {
            ((NJS_CNK_MODEL *)node->model)->polygon_list = NULL;
        }
        node = (NJS_OBJECT *)find_model_node((uaddr)get_archive_model(0), lbl_804739D4[joint]);
        if (node != NULL) {
            ((NJS_CNK_MODEL *)node->model)->polygon_list = NULL;
        }
    }
}

void TBoss7DeRolLeC::save_joint_polygons() {
    uaddr model;
    s32 i;
    model = (uaddr)get_archive_model(0);
    for (i = 0; i != 10; i++) {
        joint_polygons[i] = ((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(model, lbl_804739AC[i]))->model)->polygon_list;
        shell_polygons[i] = ((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(model, lbl_804739D4[i]))->model)->polygon_list;
    }
}
#pragma push
#pragma inline_depth(4)
#pragma opt_propagation off
#pragma opt_lifetimes off
void TBoss7DeRolLeC::spawn_crawfish_child(s16 slot, const Vec *position, Boss7Angles *angle, s32 flags) {
    Boss7CrawfishSetData set;
    u16 id;
    TObject *child;
    if (crawfish_parent != NULL && slot > 0) {
        u16 base_id = get_entity_id(this);
        CrawfishSlotOffset offset;
        offset.value = slot;
        add_crawfish_slot_base(offset);
        id = offset.value + base_id;
        for (child = crawfish_parent->m_down; child != NULL; child = child->m_next) {
            if (id == get_entity_id(child)) {
                return;
            }
        }
        set.set_index = set_index + offset.value;
        set.unk_02 = 1;
        set.unk_04 = 0;
        set.entity_id = id;
        set.room = room;
        set.unk_0A = 0;
        set.unk_0C = 0;
        set.unk_0E = 0;
        VecCopy(&set.position, position);
        copy_xyz(&set.rotation, angle);
        if (flags & 1) {
            set.unk_28 = 0.0f;
        } else {
            set.unk_28 = 1.0f;
        }
        set.unk_2C = 0.0f;
        set.unk_30 = 0.0f;
        set.unk_34 = 0.0f;
        set.unk_38 = 0.0f;
        set.unk_3C = 0;
        set.unk_3E = 0;
        new TBoss7Crawfish((TObject *)crawfish_parent, &set);
    }
}
#pragma pop
s16 TBoss7DeRolLeC::find_free_crawfish_slot() {
    u8 used[36];
    u16 base;
    TObject *child;
    s16 i;
    memset(used, 0, sizeof(used));
    base = get_entity_id(this) + 11;
    for (child = crawfish_parent->m_down; child != NULL; child = child->m_next) {
        used[get_entity_id(child) - base] = 1;
    }
    for (i = 35; i >= 0; i--) {
        if (used[i] == 0) {
            return i;
        }
    }
    return -1;
}

// Spawns the crawfish of step `index` of the boss's current spawn pattern when
// the difficulty's table asks for one (2 = the other kind, flag bit 0 clear).
void TBoss7DeRolLeC::try_spawn_pattern_crawfish(s32 variant, s32 index) {
    s32 kind = lbl_80473844[lbl_804E3C2C[game_difficulty_selection][action_index].b][index];
    if (kind != 0) {
        const Vec *positions = lbl_804E3C3C[variant];
        const s32 *angles = lbl_804E3C4C[variant];
        s32 flag;
        if (kind == 1) {
            flag = 1;
        } else {
            flag = 0;
        }
        Boss7Angles angle = lbl_80473F9C;
        angle.y = angles[index];
        spawn_crawfish_child(find_free_crawfish_slot(), &positions[index], &angle, flag);
    }
}

void TBoss7DeRolLeC::sub_802E7B94() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (unk_6DC[i] != NULL) {
            unk_6DC[i]->sub_802F0B70();
        }
    }
}

void TBoss7DeRolLeC::sub_802E7B40() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (unk_6DC[i] != NULL) {
            unk_6DC[i]->sub_802F0B80();
        }
    }
}

void TBoss7DeRolLeC::render_shadows() {
    if (bodies->flags & 1) {
        this->TObjEnemy::render_shadows();
    }
}
void TBoss7DeRolLeC::set_flag_800() { *(u32*)((char*)this + 0x628) |= 0x800; }
void TBoss7DeRolLeC::calc_joint_positions() {
    Vec v;
    Vec *out;
    s32 i;
    out = unk_530;
    VecCopy(&v, &unk_3EC[0]);
    vec3_add_to(&v, &unk_3EC[9]);
    v.x *= 0.5f;
    v.y *= 0.5f;
    v.z *= 0.5f;
    VecCopy(&out[0], &v);
    VecCopy(&v, &unk_3EC[9]);
    vec3_add_to(&v, &unk_3EC[11]);
    v.x *= 0.5f;
    v.y *= 0.5f;
    v.z *= 0.5f;
    VecCopy(&out[1], &v);
    out += 2;
    for (i = 0; i < 8; i++, out++) {
        VecCopy(&v, &unk_3EC[i + 11]);
        vec3_add_to(&v, &unk_3EC[i + 12]);
        v.x *= 0.5f;
        v.y *= 0.5f;
        v.z *= 0.5f;
        VecCopy(out, &v);
    }
}

void TBoss7DeRolLeC::destroy_child() {
    if (unk_7B0 != NULL) {
        unk_7B0->queue_destruction();
        unk_7B0 = NULL;
    }
}

void TBoss7DeRolLeC::update_attached_orientation() {
    if (unk_7B0 != NULL) {
        Vec d = unk_7B4;
        Boss7Angles ang;
        subtract_vector(&d, &unk_7C0);
        ang.x = -(s32)(10430.38043493439 * atan2_float(d.y, newton_sqrtf(d.x * d.x + d.z * d.z))) - 0x4000;
        ang.y = (s32)(10430.38043493439 * atan2_float(d.x, d.z));
        ang.z = 0;
        unk_7B0->set_position(&unk_7B4);
        unk_7B0->set_direction(&ang);
    }
}

f32 get_zero_scale(void) {
    return 0.0f;
}
