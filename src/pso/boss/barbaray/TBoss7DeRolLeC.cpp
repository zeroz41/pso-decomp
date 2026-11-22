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
#include "pso/system/MatrixStack.h"
#include "pso/boss/barbaray/TBoss7TentacleNeedle.h"

#include "pso/boss/barbaray/TBoss7LaserLight.h"

#include "pso/object/TUnk_804E4788.h"

#include "pso/boss/goldragon/TBoss8Dragon.h"

#include "pso/boss/derolle/TObjBoss2Tunnel.h"
#include "pso/boss/barbaray/TObjBoss7Tunnel.h"

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
extern Boss7LoadCallback boss7_derolle_c_load_callbacks[6];
extern TBoss7DeRolLeCMovement boss7_derolle_c_movement;
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
#include "pso/player/TObjPlayer_802E6CA8.h"
#include "pso/camera/TCameraCtrl_800687BC.h"
#include "pso/camera/CameraHelpers.h"
#include "pso/object/TObjControl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/render/model_render_state.h"
#include "pso/map/area/AreaScene.h"

// Step of a De Rol Le C action sequence: the action id and its parameter, a
// duration in seconds (the timer compares against param * 30) or the
// boss7_derolle_c_crawfish_patterns row of a crawfish spawn.
struct Boss7ActionStep {
    s32 action;
    s32 param;
};

// Attack/effect parameter record passed to TObjEneDD::emit_effect /
// setup_instance (type name inferred; same shape as TBoss1Dragon's).
struct Boss7AttackParams {
    s32 field_0;
    f32 field_4;
    f32 field_8;
    f32 field_C;
    s32 field_10;
};

extern const s32 boss7_derolle_c_body_point_node_ids[21] = {0x18, 0x1a, 0x1c, 0x1d, 0x1e, 0x1f, 0x22, 0x45, 0x4a, 0x5f, 0x60, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x68, 0x69, -1};

extern const Vec boss7_derolle_c_position_points[10] = {
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

extern const Boss7AttackParams boss7_derolle_c_hit_effect_params = {0, 0.0f, 8.0f, 5.0f, 1};

extern const Boss7AttackParams boss7_laser_particle_params = {0, 120.0f, 16.0f, 20.0f, 1};

extern const Boss7ActionStep boss7_derolle_c_actions_normal[68] = {
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

extern const Boss7ActionStep boss7_derolle_c_actions_hard[87] = {
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

extern const Boss7ActionStep boss7_derolle_c_actions_very_hard[88] = {
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

extern const Boss7ActionStep boss7_derolle_c_actions_ultimate[97] = {
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

extern const s32 boss7_derolle_c_crawfish_patterns[10][9] = {
    1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1,
    0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1,
    0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 0, 2, 0, 1, 1, 1, 1, 1, 0, 2, 0, 2,
    0, 1, 1, 2, 1, 0, 1, 1, 1, 0, 1, 2, 1, 2, 1,
    1, 2, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2,
};

extern const s32 boss7_derolle_c_joint_node_ids[10] = {0x62, 0x63, 0x64, 0x65, 0x66, 0x67, 0x19, 0x19, 0x19, 0x19};

extern const s32 boss7_derolle_c_shell_node_ids[10] = {0x19, 0x1c, 0x1c, 0x1c, 0x1c, 0x19, 0x1c, 0x1c, 0x1c, 0x1c};

extern const Vec boss7_derolle_c_crawfish_positions_pos_x[9] = {
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

extern const Vec boss7_derolle_c_crawfish_positions_neg_x[9] = {
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

extern const Vec boss7_derolle_c_crawfish_positions_pos_z[9] = {
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

extern const Vec boss7_derolle_c_crawfish_positions_neg_z[9] = {
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

extern const s32 boss7_derolle_c_crawfish_angles_pos_x[9] = {0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000, 0xc000};

extern const s32 boss7_derolle_c_crawfish_angles_neg_x[9] = {0x4000, 0x4000, 0x4000, 0x4000, 0x4000, 0x4000, 0x4000, 0x4000, 0x4000};

extern const s32 boss7_derolle_c_crawfish_angles_pos_z[9] = {0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000, 0x8000};

extern const s32 boss7_derolle_c_crawfish_angles_neg_z[9] = {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0};

extern const CollisionBody boss7_derolle_c_collision_body = {{0.0f, 0.0f, 0.0f}, 25.0f, 0.0f, 0, 0x8003, {0.0f, 0.0f, 0.0f}, 0.0f};

extern const char boss7_de_rol_le_c_model_name_boss2_b_derorure_body_nj[] = "boss2_b_derorure_body.nj";

extern const char boss7_de_rol_le_c_model_name_boss2_b_derorure_tentacle_nj[] = "boss2_b_derorure_tentacle.nj";

extern const char boss7_de_rol_le_c_model_name_boss2_b_helm_break_nj[] = "boss2_b_helm_break.nj";

extern const char boss7_de_rol_le_c_model_name_boss2_b_shell_break_nj[] = "boss2_b_shell_break.nj";

extern const char boss7_de_rol_le_c_model_name_ikada_h_hahen_gj[] = "ikada_h_hahen.gj";

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

extern const Vec boss7_derolle_c_joint_start_position = {10000.0f, 10000.0f, 10000.0f};

extern const Vec lbl_80473F78 = {0.0f, 0.0f, -600.0f};

extern const Vec lbl_80473F84 = {0.0f, 0.0f, -275.0f};

extern const Vec boss7_derolle_c_death_effect_point = {0.0f, 0.0f, -520.0f};


extern const Boss7Angles boss7_derolle_c_zero_angles = {0, 0, 0};

extern s32 game_difficulty_selection;

Vec boss7_derolle_c_model_scale = {2.5f, 2.5f, 2.5f};

Vec boss7_derolle_c_part_transform_template[4] = {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 1.0f}, {0.0f, 0.0f, 4.0f}, {0.0f, 0.0f, 13.0f}};

// Action sequences per difficulty, then the crawfish spawn positions and
// y angles per spawn pattern variant.
const Boss7ActionStep *boss7_derolle_c_difficulty_actions[4] = {boss7_derolle_c_actions_normal, boss7_derolle_c_actions_hard, boss7_derolle_c_actions_very_hard, boss7_derolle_c_actions_ultimate};

const Vec *boss7_derolle_c_crawfish_position_sets[4] = {boss7_derolle_c_crawfish_positions_pos_x, boss7_derolle_c_crawfish_positions_neg_x, boss7_derolle_c_crawfish_positions_pos_z, boss7_derolle_c_crawfish_positions_neg_z};

const s32 *boss7_derolle_c_crawfish_angle_sets[4] = {boss7_derolle_c_crawfish_angles_pos_x, boss7_derolle_c_crawfish_angles_neg_x, boss7_derolle_c_crawfish_angles_pos_z, boss7_derolle_c_crawfish_angles_neg_z};

Boss7LoadCallback boss7_derolle_c_load_callbacks[6] = {
    {TBoss7Tentacle::load_static_resource, TBoss7Tentacle::destroy_instance},
    {TObjPlayer__sub_802E7470, TObjPlayer__sub_802E7084},
    {TObjPlayer__sub_802E7088, TObjPlayer__sub_802E746C},
    {TBoss7Crawfish::load_static_resource, TBoss7Crawfish::destroy_instance},
    {TBoss7TentacleNeedle::load_static_resource, TBoss7TentacleNeedle::destroy_instance},
    {TUnk_804F1C88::load_static_resource, TUnk_804F1C88::destroy_instance},
};

TBoss7DeRolLeCMovement boss7_derolle_c_movement = {{225.0f, 0.0f, 0x600}, {0, 0, 0, 0}};

const char *bm_boss7_de_rol_le_c_model_names[7] = {
    boss7_de_rol_le_c_model_name_boss2_b_derorure_body_nj,
    boss7_de_rol_le_c_model_name_boss2_b_derorure_tentacle_nj,
    boss7_de_rol_le_c_model_name_boss2_b_helm_break_nj,
    boss7_de_rol_le_c_model_name_boss2_b_shell_break_nj,
    boss7_de_rol_le_c_model_name_ikada_h_hahen_gj,
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

f32 boss7_derolle_c_particle_limits[3] = {32.0f, 30.0f, 30.0f};





extern "C" {




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


#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
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




void *create_particle_controller_with_angles(void *arg0, void *arg1, s32 arg2, s32 arg3, u16 arg4);
extern "C" {
extern f32 lbl_804FF5E8[];
}

void calc_laser_ray_hit_point(u8 *laser, u8 *arg1);





void compose_motion_node_matrix(void *arg0);

s32 TBoss7Joint_get_shell_max_hp(void);


#pragma pop

NJS_OBJECT boss7_derolle_light_pool[11];

BmlResource *boss7_derolle_c_bml_resource; // loaded by load_resources
// State of the draw callback record_node_transforms, reset by reset_node_transforms before
// each draw: the node it is at, the points and matrices it records, and a copy of state_flags.
s32 boss7_derolle_c_node_index;
s32 boss7_derolle_c_body_point_index;
s32 boss7_derolle_c_draw_state_flags;
Vec *boss7_derolle_c_body_point_cursor;
Vec *boss7_derolle_c_part_points;
GC_Mtx *boss7_derolle_c_tentacle_matrix_cursor;
GC_Mtx *boss7_derolle_c_node_matrix_cursor;
TBoss7DeRolLeC *boss7_joint_state; // the destructor clears it when it holds this object
// Model node 0x4D; render swaps its children for the hidden boss7_derolle_light_pool
// nodes while state flag 0x40 is set.
NJS_OBJECT *boss7_derolle_c_hideable_node;
NJS_OBJECT *boss7_derolle_c_hideable_node_child;
Vec *boss7_derolle_c_emitter_points;

void TBoss7DeRolLeC::clear_harmful_statuses() {  }

void TBoss7DeRolLeC::apply_shock_status() {  }

void TBoss7DeRolLeC::apply_movement_ailment(s32) {  }

void TBoss7DeRolLeC::apply_confusion_status() {  }

void TBoss7DeRolLeC::apply_slow_status() {  }

void TBoss7DeRolLeC::apply_paralysis() {  }

void TBoss7DeRolLeC::apply_poison_status() {  }

TBoss7DeRolLeC *TBoss7Joint::get_state() { return boss7_joint_state; }

void TBoss7DeRolLeC::load_resources() {
    s32 i;
    boss7_derolle_c_bml_resource = new BmlResource(1, &bm_boss7_de_rol_le_c_resource_descriptor, 0, 0, NULL);
    boss7_derolle_c_node_index = 0;
    boss7_derolle_c_body_point_index = 0;
    boss7_derolle_c_draw_state_flags = 0;
    boss7_derolle_c_body_point_cursor = NULL;
    boss7_derolle_c_part_points = NULL;
    boss7_derolle_c_tentacle_matrix_cursor = NULL;
    boss7_derolle_c_node_matrix_cursor = NULL;
    boss7_joint_state = NULL;
    run_load_callback_table(boss7_derolle_c_load_callbacks, 0x30);
    boss7_derolle_c_hideable_node = (NJS_OBJECT *)find_model_node((uaddr)boss7_derolle_c_bml_resource->models[0].model, 0x4D);
    boss7_derolle_c_hideable_node_child = boss7_derolle_c_hideable_node->child;
    for (i = 0; i < 11; i++) {
        NJS_OBJECT *node = &boss7_derolle_light_pool[i];
        node->evalflags = 0xF;
        node->model = NULL;
        node->pos[0] = 0.0f;
        node->pos[1] = 0.0f;
        node->pos[2] = 0.0f;
        node->ang[0] = 0;
        node->ang[1] = 0;
        node->ang[2] = 0;
        node->scl[0] = 0.0f;
        node->scl[1] = 0.0f;
        node->scl[2] = 0.0f;
        node->child = NULL;
        node->sibling = NULL;
    }
    for (i = 0; i < 10; i++) {
        boss7_derolle_light_pool[i].child = &boss7_derolle_light_pool[i + 1];
    }
    {
        NJS_OBJECT *last = &boss7_derolle_light_pool[10];
        last->evalflags = 0x1F;
        last->child = NULL;
    }
    TWindowCtrl::init_all_slots();
}

void *TBoss7DeRolLeC::create(void *set_data) {
    return new TBoss7DeRolLeC(tl_04, set_data);
}

void TBoss7DeRolLeC::run_exit_callbacks() {
    TLobby::call_funcs_reverse((void*)boss7_derolle_c_load_callbacks, (unsigned int)0x30U);
    if (boss7_derolle_c_bml_resource != NULL) {
        delete boss7_derolle_c_bml_resource;
        boss7_derolle_c_bml_resource = NULL;
    }
}

TBoss7DeRolLeC::TBoss7DeRolLeC(TObject *parent, void *set_data) : TObjEneDD_ST(parent), part_group(NULL) {
    u32 state[3];

    m_name = TBoss7DeRolLeC__class_name;
    if (boss7_joint_state == NULL) {
        boss7_joint_state = this;
    }
    reset_hp((u8 *)TLobby::register_boss(15), (u8 *)TLobby::dispatch_shared_handler_b(15), (u8 *)TLobby::register_object(15));
    unk_620 = (TBoss7DeRolLeCParams *)TLobby::dispatch_shared_handler_a(15);
    invoke_initialization_hook(set_data);
    state_flags = 0;
    if (exchange_object_state(state, 1) && (state[0] & 0x12008) == 0x12008) {
        state_flags |= 0x8000;
    }
    init_position_vectors();
    model = (void *)get_bml_model(boss7_derolle_c_bml_resource, 0);
    texlist = (saddr)get_bml_texlist(boss7_derolle_c_bml_resource, 0);
    save_joint_polygons();
    copy_collision_body(&unk_3C0, &boss7_derolle_c_collision_body);
    set_collision_body(&unk_3C0);
    transform_part_positions();
    motion_flags = 0;
    set_field_d8((saddr)de_rol_le_c_action_table);
    set_field_dc((saddr)boss7_derolle_c_bml_resource->motions);
    requested_action = 0;
    set_animation(requested_action);
    set_field_b8(requested_action);
    set_state_flag_2();
    movementParameters = &boss7_derolle_c_movement;
    initialize_enemy_state(0x49);
    wall_reach = 20.0f;
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
    tentacle_matrices = (GC_Mtx *)mem_alloc(4 * sizeof(GC_Mtx));
    for (s32 i = 0; i < 4; i++) {
        set_matrix_identity((u8 *)tentacle_matrices[i]);
        tentacles[i] = new TBoss7Tentacle(&part_group, (saddr)tentacle_matrices[i], i);
    }
    Vec v = boss7_derolle_c_joint_start_position;
    u16 id = entity_id + 1;
    s32 set = set_index + 1;
    for (s32 i = 0; i < 10; i++) {
        VecCopy(&joint_positions[i], &v);
        joints[i] = new TBoss7Joint(this, id++, set++, &joint_positions[i], i);
    }
    position_slot = 0;
    next_position_slot = 0;
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
    laser_light = new TBoss7LaserLight(&part_group, &laser_light_pos);
    laser_light_pos.x = 0.0f;
    laser_light_pos.y = 0.0f;
    laser_light_pos.z = 0.0f;
    attack_history = new AreaAttackHistory(4);
    fill_value_array(attack_history);
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
    debug_pad = &controller_input_state.controllers[1];
    if (TObjEneDD::is_main_phase_15()) {
        if (update_lobby_state()) {
            unk_6B8 = 0;
        } else {
            unk_6B8 = 1;
        }
    } else {
        unk_6B8 = 0;
    }
    reset_action_sequence();
    if (!(state_flags & 0x8000)) {
        mode = 1;
        dispatch_action(mode, 4);
    }
    unk_7AC = new TUnk_804F1C58(this, model);
    if (unk_7AC != NULL) {
        unk_7AC->set_field_38(record_node_transforms);
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
    if (attack_history != NULL) {
        delete attack_history;
        attack_history = NULL;
    }
    if (laser_light != NULL) {
        ((TObject *)laser_light)->queue_destruction();
        laser_light = NULL;
    }
    for (i = 3; i >= 0; i--) {
        ((TObject *)tentacles[i])->queue_destruction();
        tentacles[i] = NULL;
    }
    mem_free(tentacle_matrices);
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
    temp_r3 = this->state_flags;
    if (temp_r3 & 0x8000) {
        this->send_entity_set_flags();
        queue_destruction();
        return;
    }
    if (temp_r3 & 0x80) {
        this->state_flags = (s32) (temp_r3 & 0xFFFFFF7F);
        this->state_flags = (s32) (this->state_flags | 0x40);
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
    if ((this->unk_6AC != 0) && (debug_pad->unknown_08 & 0x10000)) {
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
                if (is_ready() != 0) {
                    this->sub_802ECAA4();
                } else {
                    dispatch_action(this->mode, 2);
                }
            } else {
                this->update_or_dispatch();
            }
            if (this->test_flag30_512() != 0) {
                this->run_hit_reaction();
            }
            dispatch_action(this->mode, 8);
            dispatch_action(this->mode, 0);
        } else {
            if (this->test_flag30_512() != 0) {
                this->run_hit_reaction();
            }
            dispatch_action(this->mode, 0);
        }
        this->update_projectile_spawns();
    }
    this->sub_800BBA0C();
    this->update_body_colliders();
    sync_position_vectors();
    this->flee_if_disturbed();
    update_particle_ctrls();
    if (temp_r30 == 0) {
        this->part_group.run_tasks();
    }
    if (this->unk_7AC != 0) {
        set_motion_packed_rotation();
        push_matrix();
        set_matrix_identity(0);
        post_translate_matrix(&position.x);
        post_translate_matrix(&unk_6EC.x);
        rotate_matrix_by_node_angles(&rotation_x, 1);
        scale_current_matrix(&boss7_derolle_c_model_scale.x);
        this->reset_node_transforms();
        unk_7AC->apply_with_callback((NJS_MOTION *)current_motion, get_frame());
        pop_matrix();
        clear_motion_packed_rotation();
        calc_joint_positions();
    }
}

void TObjPlayer__sub_802ED984(void) {  }

void TBoss7DeRolLeC::update_or_dispatch() {
    if (is_ready() != 0) {
        sub_802ECAA4();
        return;
    }
    dispatch_action(this->mode, 9);
}
#pragma push
#pragma inline_depth(1)
#pragma auto_inline off
void TBoss7DeRolLeC::refresh_target() {  }

void TBoss7DeRolLeC::run_death_reaction() {  }

void TBoss7DeRolLeC::run_hit_reaction() {
    s32 damage;
    damage = hpmax - hp;
    if (state_flags & 8) {
        unk_6FC = unk_6FC - damage;
        spawn_offset_particle(&bodies->center, 2.0f, 8.0f);
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

void TBoss7DeRolLeC::run_miss_reaction() {  }

void TBoss7DeRolLeC::sync_position_vectors() {
    VecCopy(&body_center, &position);
    VecCopy(&center, &body_center);
}
void TBoss7DeRolLeC::update_body_colliders() {
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
        pa.target_client_id = this->target_id;
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
    TObjEneDD::emit_effect(this, (saddr)position, (saddr)&boss7_derolle_c_hit_effect_params);
    reload_stats_for_phase(unk_62C);
}

f32 TBoss7PhotonBullet::get_target_pos_y() {
    return ((TBoss7DeRolLeCParams *)TLobby::dispatch_shared_handler_a(0xF))->target_pos_y;
}

s32 TBoss7Joint_get_shell_max_hp(void) {
    return ((TBoss7DeRolLeCParams *)TLobby::dispatch_shared_handler_a(0xF))->shell_max_hp;
}

void TBoss7DeRolLeC::set_position_index(s32 index) {
    VecCopy(&position, &boss7_derolle_c_position_points[index]);
    unk_6EC.y = 0.0f;
    rotation_z = 0;
}

void TBoss7DeRolLeC::set_swim_direction(s32) {
    if (position_slot == 0) {
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
    transform_point_by_current_matrix(&v.x, &v);
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
    motion_z.advance();
    motion_x.advance();
    motion_y.advance();
    if (motion_x.state == 3 && motion_y.state == 3 && motion_z.state == 3) {
        return 1;
    }
    return 0;
}
#pragma push
#pragma opt_common_subs off
u32 TBoss7DeRolLeC::update_anim_state() {
    u8 done;
    motion_z.advance();
    if (motion_y.advance() == 3) {
        unk_6CC = 1;
    }
    switch (unk_6C8) {
    case 0:
        if (motion_z.travelled > 380.0f) {
            unk_6C8 = 1;
        }
        break;
    case 1:
        if (motion_x.advance() == 3) {
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
    motion_x.advance();
    if (motion_y.advance() == 3) {
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
        if (motion_z.advance() == 3) {
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
    motion_z.advance();
    if (motion_y.advance() == 3) {
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
        if (motion_x.advance() == 3) {
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
    motion_x.advance();
    if (motion_y.advance() == 3) {
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
        if (motion_z.advance() == 3) {
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
void TBoss7DeRolLeC::spawn_photon_pad(s32 joint, s32 shot_level) {
    s32 angle;
    Vec dir;
    angle = 0x3800 - joint * 51;
    dir.x = sin_table_lookup(angle);
    dir.y = 0.0f;
    dir.z = cos_table_lookup(angle);
    if (position_slot == 2) {
        dir.x *= -1.0f;
    }
    new TBoss7PhotonPad(&part_group, &joint_positions[joint], &dir, shot_level);
    play_sound_effect(0x39D11, &joint_positions[joint], 0, 1);
}

#pragma push
#pragma fp_contract on

void TBoss7DeRolLeC::calc_offset_position() {
    VecCopy(&laser_light_pos, &unk_4DC[0]);
    laser_light_pos.x += 30.0f * unk_4DC[1].x;
    laser_light_pos.y += 30.0f * unk_4DC[1].y;
    laser_light_pos.z += 30.0f * unk_4DC[1].z;
}
#pragma pop
void TBoss7DeRolLeC::turn_on_laser_light() {
    if (laser_light != NULL) {
        laser_light->turn_on();
    }
    state_flags |= 0x10;
}

void TBoss7DeRolLeC::turn_off_laser_light() {
    if (laser_light != NULL) {
        laser_light->turn_off();
    }
    state_flags &= ~0x10;
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
    set_intangible();
    for (i = 0; i < 10; i++) {
        joints[i]->set_intangible();
    }
}

void TBoss7DeRolLeC::sub_802ECBDC() {
    s32 i;
    clear_intangible();
    for (i = 0; i < 10; i++) {
        joints[i]->clear_intangible();
    }
}

void TBoss7DeRolLeC::apply_damage_and_set_effect(s32 damage, u16) {
    unk_6FC = unk_6FC - (s32)(0.5f * (f32)damage);
    play_sound_at(0x3B213, &position);
}

void TBoss7DeRolLeC::set_hooked_effect_target() {
    state_flags |= 0x88;
    play_sound_at(0x3A312, &position);
}

s32 TBoss7DeRolLeC::is_ready() {
    s32 var_r4;

    var_r4 = 0;
    if ((this->unk_6FC <= 0) && !(this->state_flags & 4)) {
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

void handle_6xA9_barba_ray_boss_actions(void *data) {
    G_BarbaRayBossActions_6xA9 *cmd = (G_BarbaRayBossActions_6xA9 *)data;
    TBoss7DeRolLeC *boss;
    cmd->bswap();
    boss = (TBoss7DeRolLeC *)get_enemy_entity(cmd->header.client_id);
    if (boss != NULL) {
        boss->init_from_param(cmd);
    }
}

void handle_6xAA_barba_ray_boss_actions(void *data) {
    G_BarbaRayBossActions_6xAA *cmd = (G_BarbaRayBossActions_6xAA *)data;
    TBoss7DeRolLeC *boss;
    cmd->bswap();
    boss = (TBoss7DeRolLeC *)get_enemy_entity(cmd->header.client_id);
    if (boss != NULL) {
        boss->set_params(cmd);
    }
}

void TBoss7DeRolLeC::init_from_param(G_BarbaRayBossActions_6xA9 *cmd) {
    action_index = cmd->unknown_a2;
    transition_enemy_state(cmd->what);
}

void TBoss7DeRolLeC::set_params(G_BarbaRayBossActions_6xAA *cmd) {
    enemy_set_target_id(this, cmd->target_client_id);
    action_index = cmd->unknown_a2;
    transition_enemy_state(cmd->what);
}

void TBoss7DeRolLeC::reset_action_sequence() {
    unk_6B0 = 0;
    action_index = 0;
}

void TBoss7DeRolLeC::advance_action_sequence() {
    s32 var_r30;
    s32 var_r4;
    do {
        var_r30 = 0;
        this->action_index = (this->action_index + 1);
        var_r4 = boss7_derolle_c_difficulty_actions[game_difficulty_selection][this->action_index].action;
        switch (var_r4) {
        case 0x1E:
            if (calc_elapsed_scaled() > 0.0f) {
                var_r4 = 8;
            } else {
                var_r4 = 6;
            }
            break;
        case 0x1F:
            if (this->next_position_slot == 0) {
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
            if (this->next_position_slot == 0) {
                var_r4 = 3;
            } else {
                var_r4 = 0xB;
            }
            break;
        case 0x23:
            if (this->next_position_slot == 0) {
                var_r4 = 4;
            } else {
                var_r4 = 0xA;
            }
            break;
        case 0x24:
            if (this->next_position_slot == 0) {
                var_r4 = 0xF;
            } else {
                var_r4 = 0x10;
            }
            break;
        case 0x25:
            if (this->next_position_slot == 0) {
                var_r4 = 0x11;
            } else {
                var_r4 = 0x12;
            }
            break;
        case 0x26:
            if (this->next_position_slot == 0) {
                var_r4 = 0x13;
            } else {
                var_r4 = 0x14;
            }
            break;
        case 0x27:
            if (this->next_position_slot == 0) {
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
            r = create_particle_controller_with_angles(joint_positions, p, 0x200, 1, 0x40);
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
                Vec *src = &joint_positions[particle_pos_index_table[k]];
                r = fabs_float(src->y - -10.0f);
                w = boss7_derolle_c_particle_limits[k];
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
            VecCopy(&v, &joint_positions[unk_7A0]);
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
    TObjBoss7Tunnel::sub_802F18E8(ctrl);
}

void TBoss7DeRolLeC::spawn_particle_201(Vec *pos) {
    TObjBoss7Tunnel::create_particle(pos, 0x201);
}
#pragma push
#pragma fp_contract on
void TBoss7DeRolLeC::spawn_offset_particle(const Vec *pos, f32 lift, f32 back) {
    Vec v;
    VecCopy(&v, pos);
    v.x -= lbl_804FF5E8[3] * back;
    v.y -= lbl_804FF5E8[4] * back - lift;
    v.z -= lbl_804FF5E8[5] * back;
    spawn_particle_effect_with_flags(&v, 0x127, 0x40);
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
    if ((state_flags & 0x100) && ((is_passing_frame(3.0f) != 0) || (is_passing_frame(20.0f) != 0))) {
        unk_6BC = 0;
    }
    if (unk_6BC <= 0x10) {
        if (state_flags & 0x400) {
            play_persistent_sound_at(0x39704, &unk_50C[2]);
        } else {
            play_persistent_sound_at(0x3A303, &unk_50C[2]);
        }
        unk_6BC = unk_6BC + 1;
    }
    if (state_flags & 0x200) {
        play_persistent_sound_at(0x39F08, &unk_50C[0]);
    }
}

void TBoss7DeRolLeC::sub_802EC32C() {}

void TBoss7DeRolLeC::play_sound_at(s32 id, Vec *pos) { play_sound_effect(id, pos, 0, 0); }

void TBoss7DeRolLeC::play_persistent_sound_at(s32 id, Vec *pos) {
    play_persistent_sound(id, (saddr)this, (uaddr)pos, 0, 0);
}

void TBoss7DeRolLeC::dispatch_action(u32 state, s32 reason) {
    s32 slot;
    switch (state) {
    case 0x0:
        handle_opening_state(reason);
        return;
    case 0x1:
        handle_intro_camera_state(reason);
        return;
    case 0x2:
        handle_debug_pad_input(reason);
        return;
    case 0x3:
        handle_position_travel_state(reason, 0, 1);
        return;
    case 0x4:
        handle_side_jump_state(reason, 0, 2);
        return;
    case 0x5:
        handle_position_travel_state(reason, 0, 3);
        return;
    case 0x6:
        handle_position_travel_state(reason, 1, 2);
        return;
    case 0x8:
        handle_position_travel_state(reason, 1, 0);
        return;
    case 0x9:
        handle_position_travel_state(reason, 2, 3);
        return;
    case 0xA:
        handle_side_jump_state(reason, 2, 0);
        return;
    case 0xB:
        handle_position_travel_state(reason, 2, 1);
        return;
    case 0xC:
        handle_position_travel_state(reason, 3, 0);
        return;
    case 0xD:
        handle_forward_jump_state(reason);
        return;
    case 0xE:
        handle_position_travel_state(reason, 3, 2);
        return;
    case 0x11:
        handle_bite_state(reason, 0);
        return;
    case 0x12:
        handle_bite_state(reason, 2);
        return;
    case 0x13:
        handle_tentacle_attack_state(reason, 0);
        return;
    case 0x14:
        handle_tentacle_attack_state(reason, 2);
        return;
    case 0x15:
        handle_roll_dive_state(reason, 0);
        return;
    case 0x16:
        handle_roll_dive_state(reason, 2);
        return;
    case 0xF:
        handle_photon_pad_spawn_state(reason, 0);
        return;
    case 0x10:
        handle_photon_pad_spawn_state(reason, 2);
        return;
    case 0x17:
        handle_ceiling_attack_state(reason);
        return;
    case 0x18:
        handle_laser_attack_state(reason);
        return;
    case 0x19:
        sub_802E8EEC(reason, 0);
        return;
    case 0x1A:
        sub_802E8EEC(reason, 1);
        return;
    case 0x1B:
        handle_deep_sink_state(reason);
        return;
    case 0x1C:
        handle_death_state(reason);
        return;
    case 0x1D:
        handle_despawn_state(reason);
        return;
    case 0x28:
    case 0x29:
        slot = position_slot;
        if (slot < 5) {
            handle_position_travel_state(reason, slot, slot + 5);
            return;
        }
        handle_position_travel_state(reason, slot, slot - 5);
        return;
    case 0x2A:
        handle_position_travel_state(reason, 6, 7);
        return;
    case 0x2B:
        handle_position_travel_state(reason, 7, 8);
        return;
    case 0x2C:
        handle_position_travel_state(reason, 8, 5);
        return;
    case 0x2D:
        handle_position_travel_state(reason, 5, 6);
        return;
    case 0x2E:
        handle_position_travel_state(reason, 6, 5);
        return;
    case 0x2F:
        handle_position_travel_state(reason, 5, 8);
        return;
    case 0x30:
        handle_position_travel_state(reason, 8, 7);
        return;
    case 0x31:
        handle_position_travel_state(reason, 7, 6);
        return;
    case 0x32:
        handle_position_travel_state(reason, 6, 9);
        return;
    case 0x33:
        handle_position_travel_state(reason, 9, 8);
        return;
    case 0x34:
        handle_position_travel_state(reason, 8, 9);
        return;
    case 0x35:
        handle_position_travel_state(reason, 9, 6);
        return;
    case 0x36:
        handle_position_travel_state(reason, 5, 9);
        return;
    case 0x37:
        handle_position_travel_state(reason, 9, 7);
        return;
    case 0x38:
        handle_position_travel_state(reason, 7, 9);
        return;
    case 0x39:
        handle_position_travel_state(reason, 9, 5);
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
        handle_crawfish_drain_state(reason);
        return;
    case 0x3F:
        handle_wait_state(reason);
        return;
    case 0x40:
        handle_tentacle_volley_state(reason, 0);
        return;
    case 0x41:
        handle_tentacle_volley_state(reason, 2);
        return;
    case 0x42:
        handle_retract_tentacles_state(reason);
        return;
    case 0x43:
        handle_extend_tentacles_state(reason);
        return;
    case 0x44:
        handle_tentacle_needle_barrage_state(reason);
    default:
        return;
    }
}

void TBoss7DeRolLeC::handle_opening_state(u32 event) {
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

void TBoss7DeRolLeC::handle_intro_camera_state(u32 event) {
    switch (event) {
    case 4:
        set_field_b8(0);
        sub_802ECC44();
        state_flags &= ~4;
        state_flags &= ~0x100;
        unk_6EC.y = 0.0f;
        unk_728 = 0;
        unk_72C = 0;
        TWindowCtrl::init_all_slots();
        get_target_state_b();
        break;
    case 2:
        if (unk_728 == 1) {
            position_slot = 0;
            set_state_and_send(2);
        }
        break;
    case 9:
        if (unk_728 == 1) {
            position_slot = 0;
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
void TBoss7DeRolLeC::handle_debug_pad_input(u32 event) {
    u32 b;
    switch (event) {
    case 4:
        set_field_b8(1);
        sub_802ECBDC();
        state_flags &= ~4;
        state_flags |= 0x100;
        unk_6EC.y = 0.0f;
        rotation_z = 0;
        unk_72C = 1;
        unk_730 = 0;
        unk_728 = 0;
        break;
    case 2:
        switch (position_slot) {
        case 0:
            b = debug_pad->unknown_08;
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
            b = debug_pad->unknown_08;
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
            b = debug_pad->unknown_08;
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
            b = debug_pad->unknown_08;
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
// Moves the body from point position_slot of boss7_derolle_c_position_points to point next_position_slot (states 3, 5,
// 6, 8, 9, 0xB, 0xC, 0xE, 0x28, 0x29 of dispatch_action): one TUnk_80036250 profile
// per axis, unk_74C/unk_758/unk_750 the x/y/z direction signs, unk_744/unk_754/unk_748
// the start position.
void TBoss7DeRolLeC::handle_position_travel_state(u32 event, s32 mode, s32 next_mode) {
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
        state_flags &= ~4;
        state_flags |= 0x100;
        position_slot = mode;
        next_position_slot = next_mode;
        set_position_index(position_slot);
        unk_728 = 0;
        unk_744 = position.x;
        unk_754 = position.y;
        unk_748 = position.z;
        d = boss7_derolle_c_position_points[next_position_slot].x - boss7_derolle_c_position_points[position_slot].x;
        if (0.0f < d) {
            unk_74C = 1.0f;
        } else if (d < 0.0f) {
            unk_74C = -1.0f;
        } else {
            unk_74C = 0.0f;
        }
        d = boss7_derolle_c_position_points[next_position_slot].y - boss7_derolle_c_position_points[position_slot].y;
        if (0.0f < d) {
            unk_758 = 1.0f;
        } else if (d < 0.0f) {
            unk_758 = -1.0f;
        } else {
            unk_758 = 0.0f;
        }
        d = boss7_derolle_c_position_points[next_position_slot].z - boss7_derolle_c_position_points[position_slot].z;
        if (0.0f < d) {
            unk_750 = 1.0f;
        } else if (d < 0.0f) {
            unk_750 = -1.0f;
        } else {
            unk_750 = 0.0f;
        }
        if (next_position_slot < 5) {
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
        motion_x.init_params(speed, fabs_float(boss7_derolle_c_position_points[next_position_slot].x - position.x), accel);
        motion_y.init_params(speed, fabs_float(boss7_derolle_c_position_points[next_position_slot].y - position.y), accel);
        if (unk_750 > 0.0f) {
            motion_z.init_params(z_speed, fabs_float(boss7_derolle_c_position_points[next_position_slot].z - position.z), z_accel);
        } else {
            motion_z.set_move_params(z_speed, fabs_float(boss7_derolle_c_position_points[next_position_slot].z - position.z), z_accel, 0.05f);
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
                extend_all_tentacles();
                play_sound_at(0x39902, unk_50C);
                state_flags &= ~0x400;
            } else {
                retract_all_tentacles();
                play_sound_at(0x39E01, unk_50C);
                state_flags |= 0x400;
            }
        } else {
            switch (position_slot) {
            case 1:
            case 6:
                unk_72C = 2;
                break;
            case 3:
            case 8:
                unk_72C = 0;
                break;
            default:
                switch (next_position_slot) {
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
            if (state_flags & 0x800) {
                state_flags &= ~0x800;
                switch (next_position_slot) {
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
        position_slot = next_position_slot;
        break;
    }
}
void TBoss7DeRolLeC::handle_side_jump_state(u32 event, s32 position_index, s32 next_index) {
    switch (event) {
    case 4:
        sub_802ECBDC();
        state_flags |= 4;
        state_flags &= ~0x100;
        position_slot = position_index;
        next_position_slot = next_index;
        set_position_index(position_slot);
        if (position_slot == 0) {
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
            if (state_flags & 0x800) {
                state_flags &= ~0x800;
                switch (next_position_slot) {
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
                            if (v.y * joint_positions[i].y < 0.0f) {
                                break;
                            }
                            VecCopy(&v, &joint_positions[i]);
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
                motion_z.advance();
                position.z = unk_750 - motion_z.travelled;
                break;
            case 5:
                position.x = position.x + unk_754;
                update_wobble_angle();
                motion_z.advance();
                position.z = unk_750 - motion_z.travelled;
                break;
            case 6:
                update_wobble_angle();
                if (motion_z.advance() == 3) {
                    unk_728 = 2;
                }
                position.z = unk_750 - motion_z.travelled;
                if (requested_action == 1) {
                    state_flags |= 0x100;
                }
                break;
            }
            break;
        }
        break;
    case 5:
        position_slot = next_position_slot;
        state_flags &= ~4;
        break;
    }
}
#pragma push
#pragma fp_contract on
#pragma push
#pragma opt_common_subs off
#undef self
void TBoss7DeRolLeC::handle_forward_jump_state(u32 event) {
    switch (event) {
    case 4:
        set_field_b8(1);
        sub_802ECBDC();
        state_flags |= 4;
        state_flags &= ~0x100;
        position_slot = 3;
        set_position_index(position_slot);
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
                } else if (motion_z.advance() == 3) {
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
        position_slot = 1;
        state_flags &= ~4;
        break;
    }
}
void TBoss7DeRolLeC::handle_bite_state(u32 event, s32 position_index) {
    TParticleCtrl *p_;
    switch (event) {
    case 4:
        set_field_b8(1);
        sub_802ECBDC();
        state_flags |= 4;
        state_flags &= ~0x100;
        position_slot = position_index;
        set_position_index(position_slot);
        unk_744 = 0.0f;
        unk_750 = 0.0f;
        unk_74C = 0.0f;
        unk_748 = 0.0f;
        unk_754 = -0.2f;
        unk_758 = 0.0f;
        unk_75C = position.z;
        unk_760 = 0.0f;
        unk_72C = 0;
        unk_728 = 0;
        unk_730 = 0;
        unk_784 = NULL;
        unk_734 = 0;
        break;
    case 2: {
        u32 f = debug_pad->unknown_08;
        if (f & 0x400) {
            if (position_slot == 0) {
                set_state_and_send(0x13);
            } else {
                set_state_and_send(0x14);
            }
        } else if (f & 4) {
            if (position_slot == 0) {
                set_state_and_send(0x15);
            } else {
                set_state_and_send(0x16);
            }
        }
        break;
    }
    case 9:
        if (requested_action == 10 || requested_action == 9) {
            advance_action_sequence();
        }
        break;
    case 0:
        advance_animation();
        switch (unk_728) {
        case 0:
            unk_72C++;
            if (unk_72C > 10) {
                unk_72C = 0;
                unk_728 = 1;
                if (position_slot == 0) {
                    set_field_b8(7);
                    unk_744 = -1.0f;
                } else {
                    set_field_b8(8);
                    unk_744 = 1.0f;
                }
            }
            break;
        case 1:
            if (!(motion_flags & 4)) {
                unk_728 = 2;
            }
            break;
        case 2:
            if (frame >= 6.0f) {
                unk_728 = 3;
                unk_750 = 0.0f;
                unk_748 = position.x;
                unk_74C = (100.0f * unk_744 - unk_748) / 7.0f;
                unk_754 = -(unk_758 / 7.0f);
                unk_75C = position.z;
                unk_758 = 0.0f;
            }
            break;
        case 3:
            if (frame >= 13.0f) {
                unk_728 = 4;
                unk_750 = 0.0f;
                unk_748 = 100.0f * unk_744;
                unk_74C = (135.0f * unk_744 - unk_748) / 7.0f;
                unk_75C = position.z;
                unk_754 = (2.0f * (10.0f - position.z)) / 144.0f;
                unk_758 = 0.0f;
            }
            break;
        case 4:
            if (frame >= 20.0f) {
                unk_728 = 5;
                unk_750 = 0.0f;
                unk_748 = 135.0f * unk_744;
                unk_74C = (100.0f * unk_744 - unk_748) / 5.0f;
                unk_760 = (1280.0f * -unk_744) / 5.0f;
            }
            break;
        case 5:
            if (frame >= 25.0f) {
                s32 i;
                unk_728 = 6;
                TCameraCtrl::set_shake_preset(1);
                if (position_slot == 0) {
                    TObjBoss7Tunnel::start_sway_negative_x();
                } else {
                    TObjBoss7Tunnel::start_sway_positive_x();
                }
                play_sound_at(0x3A107, &unk_50C[0]);
                new TUnk_804F1C88(this, &unk_4DC[0]);
                state_flags |= 0x200;
                for (i = 0; i < 4; i++) {
                    tentacles[i]->sub_802F0B58();
                }
            }
            break;
        case 6:
            break;
        }
        unk_730++;
        if (unk_728 != 0 && unk_728 != 1) {
            if (frame >= 15.0f && frame <= 17.0f && unk_730 >= 2) {
                Vec v;
                f32 s;
                unk_730 = 0;
                VecCopy(&v, &unk_4DC[0]);
                s = 50.0f * random_ratio();
                v.x = v.x - unk_744 * s;
                v.y = -5.0f;
                v.z += 40.0f;
                spawn_particle_201(&v);
            }
            if (is_passing_frame(15.0f) != 0) {
                play_sound_at(0x39905, &unk_50C[0]);
            }
            p_ = unk_784;
            if (p_ == NULL) {
                unk_784 = create_particle_emitter(&position, 0x161);
                if (unk_784 != NULL) {
                    unk_784->enable();
                }
            } else if (frame >= 24.0f && frame <= 30.0f) {
                s32 r;
                unk_734++;
                r = unk_734 % 4;
                if (r == 0) {
                    unk_784->set_position(&unk_3EC[7]);
                } else if (r == 2) {
                    unk_784->set_position(&unk_3EC[8]);
                } else {
                    unk_784->enable();
                }
            } else {
                p_->enable();
            }
        }
        switch (unk_728) {
        case 0:
        case 1:
        case 2:
            unk_758 = unk_758 + unk_754;
            if (unk_758 < -7.0f) {
                unk_758 = -7.0f;
            }
            position.z = position.z + unk_758;
            break;
        case 3: {
            f32 t = frame - 6.0f;
            position.x = unk_74C * t + unk_748;
            { f32 h_ = 0.5f * unk_754; position.z = t * (h_ * t + -7.0f) + unk_75C; }
            if (is_passing_frame(8.5f) != 0) {
                play_sound_at(0x39906, &unk_50C[0]);
            }
            break;
        }
        case 4: {
            f32 t = frame - 13.0f;
            position.x = unk_74C * t + unk_748;
            { f32 h_ = 0.5f * unk_754; position.z = t * (h_ * t) + unk_75C; }
            unk_6EC.y = 28.0f * t;
            if (unk_6EC.y > 4.0f) {
                unk_6EC.y = 4.0f;
            }
            break;
        }
        case 5: {
            f32 t = frame - 20.0f;
            f32 t2;
            f32 d;
            position.x = unk_74C * t + unk_748;
            t2 = frame - 13.0f;
            { f32 h_ = 0.5f * unk_754; d = t2 * (h_ * t2); }
            position.z = unk_75C + d;
            rotation_z = unk_760 * t;
            break;
        }
        case 6:
            break;
        }
        break;
    case 5:
        state_flags &= ~4;
        if (unk_784 != NULL) {
            unk_784->queue_destruction();
            unk_784 = NULL;
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
        state_flags &= ~4;
        state_flags &= ~0x100;
        position_slot = position_index;
        set_swim_direction(position_slot);
        if (position_slot == 0) {
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
            if (position_slot == 0) {
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
                    VecCopy(&v, &current_target->position);
                } else {
                    f32 r = 120.0f * random_ratio();
                    ang = get_random_scaled();
                    v.x = r * sin_table_lookup(ang);
                    v.y = -1.85f;
                    v.z = r * cos_table_lookup(ang);
                    TObjBoss2Tunnel::adjust_to_ground(&v, &v);
                }
                tentacles[unk_730]->start_attack_at_position((u8 *)&v, unk_738);
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
                if (tentacles[i]->is_attack_finished() == 0) {
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
            tentacles[j]->sub_802F0AF0();
        }
        break;
    }
}
#pragma push
#pragma fp_contract on
#pragma push
#pragma opt_common_subs off
void TBoss7DeRolLeC::handle_roll_dive_state(u32 event, s32 position_index) {
    switch (event) {
    case 4:
        for (s32 i = 0; i < 4; i++) {
            tentacles[i]->sub_802F0AF0();
        }
        sub_802ECBDC();
        state_flags |= 4;
        state_flags &= 0xFFFFFEFF;
        position_slot = position_index;
        set_swim_direction(position_slot);
        if (position_slot == 0) {
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
        TObjBoss7Tunnel::clear_flags_0x3000();
        state_flags &= 0xFFFFFDFF;
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
                set_position_index(position_slot);
                unk_6EC.y = -137.0f;
                set_field_b8(1);
                unk_750 = 0.0f;
                state_flags &= ~4;
                state_flags |= 0x100;
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
        state_flags &= ~4;
        break;
    case 1: case 3: case 6: case 7: case 8:
        break;
    }
}
#pragma pop
#pragma pop
#pragma pop
void TBoss7DeRolLeC::handle_photon_pad_spawn_state(u32 event, s32 position_index) {
    s32 joint;
    switch (event) {
    case 4:
        set_field_b8(3);
        sub_802ECBDC();
        state_flags &= ~4;
        state_flags &= ~0x100;
        position_slot = position_index;
        set_position_index(position_slot);
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
                spawn_photon_pad(unk_728, unk_704);
                unk_72C = 1;
                return;
            }
            break;
        case 1:
            joint = unk_728;
            if (joint_positions[joint].y < joint_positions[joint + 1].y) {
                unk_728 = joint + 1;
                if ((f32)unk_728 >= 4.0f) {
                    unk_72C = 2;
                }
                spawn_photon_pad(unk_728, unk_704);
            }
            break;
        }
        break;
    }
}
#pragma push
#pragma fp_contract on
void TBoss7DeRolLeC::handle_ceiling_attack_state(u32 event) {
    Vec v;
    f32 f;

    switch (event) {
    case 4:
        state_flags &= ~4;
        state_flags |= 0x100;
        sub_802ECBDC();
        set_field_b8(0xC);
        position_slot = 3;
        set_position_index(position_slot);
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
void TBoss7DeRolLeC::handle_laser_attack_state(u32 event) {
    Vec from;
    CsnHit *hit;
    Vec *aim = &unk_76C;
    Vec *beam_end;
    switch (event) {
    case 4:
        state_flags &= ~4;
        state_flags |= 0x100;
        sub_802ECBDC();
        set_field_b8(0xF);
        position_slot = 3;
        set_position_index(position_slot);
        fill_value_array(attack_history);
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
                fill_value_array(attack_history);
                set_field_b8(0xD);
                if (enemy_check_target_valid() != 0) {
                    VecCopy(aim, &current_target->position);
                } else {
                    aim->x = 0.0f;
                    aim->y = 0.0f;
                    aim->z = 0.0f;
                }
                if (unk_7A8 != NULL) {
                    unk_7A8->queue_destruction();
                }
                unk_7A8 = new TBoss7LaserPtcl(this, (TBoss7LaserPtclVector *)&unk_4DC[0], (TBoss7LaserPtclVector *)aim);
                calc_offset_position();
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
            calc_offset_position();
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
                TObjEneDD::setup_instance((saddr)this, (saddr)beam_end, (u8 *)&params, (saddr)attack_history);
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
        state_flags &= ~4;
        state_flags |= 0x100;
        set_field_b8(0xE);
        sub_802ECBDC();
        position_slot = 3;
        set_position_index(position_slot);
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

void TBoss7DeRolLeC::handle_deep_sink_state(u32 event) {
    switch (event) {
    case 4:
        state_flags |= 4;
        state_flags &= ~0x100;
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
        state_flags &= ~0x300;
        state_flags |= 4;
        sub_802ECC44();
        set_field_b8(0x10);
        position_slot = 3;
        set_position_index(position_slot);
        rotation_x = 0;
        unk_6EC.y = 0.0f;
        unk_728 = 0;
        unk_72C = 0;
        unk_73C = 0;
        unk_6FC = 0;
        for (i = 0; i < 4; i++) {
            tentacles[i]->speed_up_sway();
        }
        if (crawfish_parent != NULL) {
            crawfish_parent->queue_destruction_for_each_node();
        }
        TObjBoss7Tunnel::clear_flags_0x3000();
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
        if (debug_pad->unknown_08 & 0x400) {
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
            Vec v = boss7_derolle_c_death_effect_point;
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
            assign_slots_from_list(this, (saddr)joints[i]);
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

void TBoss7DeRolLeC::handle_despawn_state(u32 event) {
    switch (event) {
    case 4:
        set_field_b8(0x10);
        sub_802ECC44();
        state_flags |= 4;
        state_flags &= ~0x100;
        TObjBoss7Tunnel::set_flag_0x200();
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

void TBoss7DeRolLeC::handle_crawfish_drain_state(u32 event) {
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

void TBoss7DeRolLeC::handle_wait_state(u32 event) {
    switch (event) {
    case 4:
        unk_728 = boss7_derolle_c_difficulty_actions[game_difficulty_selection][action_index].param * 30;
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
void TBoss7DeRolLeC::handle_tentacle_volley_state(u32 event, s32 position_index) {
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
        state_flags &= ~4;
        state_flags &= ~0x100;
        position_slot = position_index;
        set_swim_direction(position_slot);
        if (position_slot == 0) {
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
            if (position_slot == 0) {
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
            if (unk_72C > boss7_derolle_c_difficulty_actions[game_difficulty_selection][action_index].param * 0x1E) {
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
                        VecCopy(&v, &current_target->position);
                    } else {
                        scale = 120.0f * random_ratio();
                        r = get_random_scaled();
                        v.x = scale * sin_table_lookup(r);
                        v.y = -1.85f;
                        v.z = scale * cos_table_lookup(r);
                        TObjBoss2Tunnel::adjust_to_ground(&v, &v);
                    }
                    for (j = 0; j != 4; j++) {
                        tentacles[j]->start_attack_at_position((u8 *)&v, unk_738);
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
                if (tentacles[i]->is_attack_finished() == 0) {
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
            tentacles[k]->sub_802F0AF0();
        }
        return;
    case 1:
    case 3:
    case 7:
    case 8:
        return;
    }
}
void TBoss7DeRolLeC::handle_retract_tentacles_state(u32 event) {
    switch (event) {
    case 0:
        advance_animation();
        retract_all_tentacles();
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

void TBoss7DeRolLeC::handle_extend_tentacles_state(u32 event) {
    switch (event) {
    case 0:
        advance_animation();
        extend_all_tentacles();
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

void TBoss7DeRolLeC::handle_tentacle_needle_barrage_state(u32 event) {
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

void TBoss7DeRolLeC::record_node_transforms(NJS_OBJECT *) {
    Vec emitter_point;
    Vec aim_point;
    Vec body_point;
    if ((s32) boss7_derolle_c_node_index == 0x5F) {
        emitter_point.x = 0.0f;
        emitter_point.y = 0.0f;
        emitter_point.z = 0.0f;
        transform_point_by_current_matrix(&emitter_point.x, boss7_derolle_c_emitter_points);
    }
    if ((s32) boss7_derolle_c_node_index == 0x71) {
        aim_point.x = 0.0f;
        aim_point.y = 0.0f;
        aim_point.z = 0.0f;
        transform_point_by_current_matrix(&aim_point.x, boss7_derolle_c_emitter_points + 1);
    }
    if ((s32) boss7_derolle_c_node_index == boss7_derolle_c_body_point_node_ids[boss7_derolle_c_body_point_index]) {
        body_point.x = 0.0f;
        body_point.y = 0.0f;
        body_point.z = 0.0f;
        transform_point_by_current_matrix(&body_point.x, boss7_derolle_c_body_point_cursor);
        boss7_derolle_c_body_point_index += 1;
        boss7_derolle_c_body_point_cursor++;
    }
    if ((s32) boss7_derolle_c_node_index == 0x33) {
        push_matrix();
        matrix_mult_vec_array(NULL, (const Vec *)boss7_derolle_c_part_transform_template, boss7_derolle_c_part_points, 4);
        pop_matrix();
        subtract_vector(boss7_derolle_c_part_points + 1, boss7_derolle_c_part_points);
    }
    if ((boss7_derolle_c_draw_state_flags & 0x80) && ((s32) boss7_derolle_c_node_index >= 0x4D) && ((s32) boss7_derolle_c_node_index <= 0x58)) {
        push_matrix();
        get_current_matrix(boss7_derolle_c_node_matrix_cursor);
        pop_matrix();
        boss7_derolle_c_node_matrix_cursor++;
    }
    if (((s32) boss7_derolle_c_node_index >= 0x1D) && ((s32) boss7_derolle_c_node_index <= 0x20)) {
        push_matrix();
        get_current_matrix(boss7_derolle_c_tentacle_matrix_cursor);
        pop_matrix();
        boss7_derolle_c_tentacle_matrix_cursor++;
    }
    boss7_derolle_c_node_index += 1;
}

void TBoss7DeRolLeC::reset_node_transforms() {
    boss7_derolle_c_node_index = 0;
    boss7_derolle_c_draw_state_flags = this->state_flags;
    boss7_derolle_c_body_point_index = 0;
    boss7_derolle_c_body_point_cursor = unk_3EC;
    boss7_derolle_c_tentacle_matrix_cursor = tentacle_matrices;
    boss7_derolle_c_node_matrix_cursor = unk_6D4;
    boss7_derolle_c_part_points = unk_4DC;
    boss7_derolle_c_emitter_points = &unk_7B4;
}

void TBoss7DeRolLeC::render() {
    TBoss7Joint **joint;
    s32 i;
    if (!((s32)main_task.get_task_flags() & 0x20) || !(position.y < -35.0f)) {
        joint = joints;
        i = 0;
        do {
            if ((*joint)->is_part_active() != 0U) {
                hide_joint_polygons(i);
            }
            i += 1;
            joint++;
        } while (i != 10);
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        copy_argb(&saved_model_draw_color, &model_material_color);
        TObjEneDD::clear_global_flag_400();
        TParticleCtrl::begin_effect_render();
        push_matrix();
        if (this->unk_7AC != 0) {
            if (this->state_flags & 0x40) {
                boss7_derolle_c_hideable_node->child = &boss7_derolle_light_pool[0];
            } else {
                boss7_derolle_c_hideable_node->child = boss7_derolle_c_hideable_node_child;
            }
            TObjPlayer::draw_effect();
            ((TObjPlayer *)(this->unk_7AC))->draw_node_tree_if_visible();
        }
        pop_matrix();
        TParticleCtrl::end_effect_render();
        copy_argb(&model_material_color, &saved_model_draw_color);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
        restore_joint_polygons();
        this->part_group.render_nodes();
    }
}

void TObjPlayer::draw_effect() { TObjFish::set_global_param((saddr)get_bml_texlist(boss7_derolle_c_bml_resource, 0)); }

GinjaTextureList *TBoss7DeRolLeC::get_archive_textures() { return (GinjaTextureList *)get_bml_texlist(boss7_derolle_c_bml_resource, 0); }

NJS_OBJECT *TBoss7DeRolLeC::get_archive_model(s32 index) { return (NJS_OBJECT *)get_bml_model(boss7_derolle_c_bml_resource, index); }

AnimationMotion *get_boss7_motion(s32 kind) { return get_bml_motion(boss7_derolle_c_bml_resource, kind); }
void TBoss7DeRolLeC::restore_joint_polygons() {
    uaddr model;
    s32 i;
    NJS_OBJECT *node;
    model = (uaddr)get_archive_model(0);
    for (i = 0; i != 10; i++) {
        node = (NJS_OBJECT *)find_model_node(model, boss7_derolle_c_joint_node_ids[i]);
        ((NJS_CNK_MODEL *)node->model)->polygon_list = joint_polygons[i];
        node = (NJS_OBJECT *)find_model_node(model, boss7_derolle_c_shell_node_ids[i]);
        ((NJS_CNK_MODEL *)node->model)->polygon_list = shell_polygons[i];
    }
}

void TBoss7DeRolLeC::hide_joint_polygons(s32 joint) {
    NJS_OBJECT *node;
    if (joint >= 0 && joint < 10) {
        node = (NJS_OBJECT *)find_model_node((uaddr)get_archive_model(0), boss7_derolle_c_joint_node_ids[joint]);
        if (node != NULL) {
            ((NJS_CNK_MODEL *)node->model)->polygon_list = NULL;
        }
        node = (NJS_OBJECT *)find_model_node((uaddr)get_archive_model(0), boss7_derolle_c_shell_node_ids[joint]);
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
        joint_polygons[i] = ((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(model, boss7_derolle_c_joint_node_ids[i]))->model)->polygon_list;
        shell_polygons[i] = ((NJS_CNK_MODEL *)((NJS_OBJECT *)find_model_node(model, boss7_derolle_c_shell_node_ids[i]))->model)->polygon_list;
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
            if (id == get_entity_id((TObjBase *)child)) {
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
        used[get_entity_id((TObjBase *)child) - base] = 1;
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
    s32 kind = boss7_derolle_c_crawfish_patterns[boss7_derolle_c_difficulty_actions[game_difficulty_selection][action_index].param][index];
    if (kind != 0) {
        const Vec *positions = boss7_derolle_c_crawfish_position_sets[variant];
        const s32 *angles = boss7_derolle_c_crawfish_angle_sets[variant];
        s32 flag;
        if (kind == 1) {
            flag = 1;
        } else {
            flag = 0;
        }
        Boss7Angles angle = boss7_derolle_c_zero_angles;
        angle.y = angles[index];
        spawn_crawfish_child(find_free_crawfish_slot(), &positions[index], &angle, flag);
    }
}

void TBoss7DeRolLeC::retract_all_tentacles() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (tentacles[i] != NULL) {
            tentacles[i]->enable_retract();
        }
    }
}

void TBoss7DeRolLeC::extend_all_tentacles() {
    s32 i;
    for (i = 0; i < 4; i++) {
        if (tentacles[i] != NULL) {
            tentacles[i]->enable_extend();
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
    out = joint_positions;
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
