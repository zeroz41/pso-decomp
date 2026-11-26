#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/task/TObject.h"
#include "pso/object/TObjWaitEntryHairMoveSim.h"
#include "pso/object/T_OWEHMS_Exp.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/object/TObjEZBoneRotPlayer.h"
#include "pso/object/TObjEZBoneRotBase.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/charcreate/CharacterAppearance.h"
#include "pso/object/TObjTailsTailsMove.h"
#include "pso/ui/charcreate/TCharaMaking.h"

#include "types.h"

struct H_800FE32C { u8 pad[0x878]; u8 state; u8 pad879[0x88E - 0x879]; s8 flags; };

struct Obj_800FE698 {
    u8 pad0[0x88D];
    s8 lvl;
    s8 flags;
    u8 pad1[0xB];
    s16 v9A;
    s16 v9C;
};

struct EntX_800FE5A0 { s8 a; s8 b; s8 c; s8 d; void *p4; void *p8; saddr pc; };

struct Pl_800FE5A0 {
    u8 pad0[0x88D];
    s8 lvl;
    s8 flags;
    u8 pad1[0xB];
    s16 v9A;
    s16 v9C;
    u8 pad2[0x8AC - 0x89E];
    s32 vAC;
    s32 vB0;
    s32 vB4;
};

struct Self_800FE5A0 {
    u8 pad[0x1C];
    Pl_800FE5A0 *pl;
};

extern "C" {
s32 get_move_done_result__24TObjWaitEntryHairMoveSimFPv(H_800FE32C *h);

s32 is_level_in_table__24TObjWaitEntryHairMoveSimFPv(Obj_800FE698 *o);

extern EZBoneRotKey hair_bone_rotation_bone_list_00[4];
extern EZBoneRotKey hair_bone_rotation_bone_list_01[5];
extern EZBoneRotKey hair_bone_rotation_bone_list_02[4];
extern EZBoneRotKey hair_bone_rotation_bone_list_03[9];
extern EZBoneRotKey hair_bone_rotation_bone_list_04[6];
extern EZBoneRotKey hair_bone_rotation_bone_list_05[2];
extern EZBoneRotKey hair_bone_rotation_bone_list_06[4];
extern EZBoneRotKey hair_bone_rotation_bone_list_07[2];
extern EZBoneRotKey hair_bone_rotation_bone_list_08[4];
extern EZBoneRotKey hair_bone_rotation_bone_list_09[5];
extern EZBoneRotKey hair_bone_rotation_bone_list_10[7];
extern EZBoneRotKey hair_bone_rotation_bone_list_11[5];
extern EZBoneRotKey hair_bone_rotation_bone_list_12[4];
extern EZBoneRotKey hair_bone_rotation_bone_list_13[6];
extern EZBoneRotKey hair_bone_rotation_bone_list_14[3];
extern EZBoneRotKey hair_bone_rotation_bone_list_15[3];
extern EZBoneRotKey hair_bone_rotation_bone_list_16[5];
extern EZBoneRotKey hair_bone_rotation_bone_list_17[4];
extern EZBoneRotKey hair_bone_rotation_bone_list_18[3];
extern EZBoneRotKey hair_bone_rotation_bone_list_19[5];
extern EZBoneRotKey hair_bone_rotation_bone_list_20[8];
extern EZBoneRotKey hair_bone_rotation_bone_list_21[9];
extern EZBoneRotKey hair_bone_rotation_bone_list_22[3];
extern EZBoneRotKey hair_bone_rotation_bone_list_23[3];
extern EZBoneRotKey hair_bone_rotation_bone_list_24[5];
extern EZBoneRotKey hair_bone_rotation_bone_list_25[5];
extern EZBoneRotKey hair_bone_rotation_bone_list_26[2];
extern EZBoneRotKey hair_bone_rotation_bone_list_27[2];
extern EZBoneRotKey hair_bone_rotation_bone_list_28[3];
extern EZBoneRotKey hair_bone_rotation_bone_list_29[5];
extern EZBoneRotKey hair_bone_rotation_bone_list_30[4];
extern EZBoneRotKey hair_bone_rotation_bone_list_31[2];
extern EZBoneRotKey hair_bone_rotation_bone_list_32[4];
extern EZBoneRotKey hair_bone_rotation_bone_list_33[6];
extern EZBoneRotKey hair_bone_rotation_bone_list_34[4];
extern EZBoneRotKey hair_bone_rotation_bone_list_35[3];
extern EZBoneRotKey hair_bone_rotation_bone_list_36[2];
extern EZBoneRotKey hair_bone_rotation_bone_list_37[4];
extern EZBoneRotKey hair_bone_rotation_bone_list_38[5];
extern EZBoneRotKey hair_bone_rotation_bone_list_39[4];
extern EZBoneRotDesc hair_bone_rotation_desc_00;
extern EZBoneRotDesc hair_bone_rotation_desc_01;
extern EZBoneRotDesc hair_bone_rotation_desc_02;
extern EZBoneRotDesc hair_bone_rotation_desc_03;
extern EZBoneRotDesc hair_bone_rotation_desc_04;
extern EZBoneRotDesc hair_bone_rotation_desc_05;
extern EZBoneRotDesc hair_bone_rotation_desc_06;
extern EZBoneRotDesc hair_bone_rotation_desc_07;
extern EZBoneRotDesc hair_bone_rotation_desc_08;
extern EZBoneRotDesc hair_bone_rotation_desc_09;
extern EZBoneRotDesc hair_bone_rotation_desc_10;
extern EZBoneRotDesc hair_bone_rotation_desc_11;
extern EZBoneRotDesc hair_bone_rotation_desc_12;
extern EZBoneRotDesc hair_bone_rotation_desc_13;
extern EZBoneRotDesc hair_bone_rotation_desc_14;
extern EZBoneRotDesc hair_bone_rotation_desc_15;
extern EZBoneRotDesc hair_bone_rotation_desc_16;
extern EZBoneRotDesc hair_bone_rotation_desc_17;
extern EZBoneRotDesc hair_bone_rotation_desc_18;
extern EZBoneRotDesc hair_bone_rotation_desc_19;
extern EZBoneRotDesc hair_bone_rotation_desc_20;
extern EZBoneRotDesc hair_bone_rotation_desc_21;
extern EZBoneRotDesc hair_bone_rotation_desc_22;
extern EZBoneRotDesc hair_bone_rotation_desc_23;
extern EZBoneRotDesc hair_bone_rotation_desc_24;
extern EZBoneRotDesc hair_bone_rotation_desc_25;
extern EZBoneRotDesc hair_bone_rotation_desc_26;
extern EZBoneRotDesc hair_bone_rotation_desc_27;
extern EZBoneRotDesc hair_bone_rotation_desc_28;
extern EZBoneRotDesc hair_bone_rotation_desc_29;
extern EZBoneRotDesc hair_bone_rotation_desc_30;
extern EZBoneRotDesc hair_bone_rotation_desc_31;
extern EZBoneRotDesc hair_bone_rotation_desc_32;
extern EZBoneRotDesc hair_bone_rotation_desc_33;
extern EZBoneRotDesc hair_bone_rotation_desc_34;
extern EZBoneRotDesc hair_bone_rotation_desc_35;
extern EZBoneRotDesc hair_bone_rotation_desc_36;
extern EZBoneRotDesc hair_bone_rotation_desc_37;
extern EZBoneRotDesc hair_bone_rotation_desc_38;
extern EZBoneRotDesc hair_bone_rotation_desc_39;
extern EZBoneRotKey hair_bone_rotation_bone_list_of_descriptor[5];
EZBoneRotKey hair_bone_rotation_bone_list_00[4] = {
    {3, {0.0f, 1.0f, 0.0f}},
    {4, {0.0f, 1.0f, 0.0f}},
    {5, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_01[5] = {
    {1, {1.0f, 0.0f, 0.0f}},
    {2, {1.0f, 0.0f, 0.0f}},
    {3, {1.0f, 0.0f, 0.0f}},
    {4, {1.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_02[4] = {
    {6, {0.0f, 1.0f, 0.0f}},
    {7, {0.0f, 1.0f, 0.0f}},
    {8, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_03[9] = {
    {1, {0.13f, 0.0f, 1.04f}},
    {2, {0.120000005f, 0.0f, 0.96000004f}},
    {3, {0.11000001f, 0.0f, 0.88000005f}},
    {4, {0.1f, 0.0f, 0.8f}},
    {5, {-0.13f, 0.0f, 1.04f}},
    {6, {-0.120000005f, 0.0f, 0.96000004f}},
    {7, {-0.11000001f, 0.0f, 0.88000005f}},
    {8, {-0.1f, 0.0f, 0.8f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_04[6] = {
    {6, {0.0f, 1.0f, 0.0f}},
    {7, {0.0f, 1.0f, 0.0f}},
    {8, {0.0f, 1.0f, 0.0f}},
    {11, {0.0f, 1.0f, 0.0f}},
    {12, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_05[2] = {
    {1, {1.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_06[4] = {
    {1, {1.0f, 0.0f, 0.0f}},
    {2, {1.0f, 0.0f, 0.0f}},
    {3, {1.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_07[2] = {
    {1, {1.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_08[4] = {
    {5, {0.0f, 1.0f, 0.0f}},
    {6, {0.0f, 1.0f, 0.0f}},
    {7, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_09[5] = {
    {1, {1.0f, 0.25f, 0.0f}},
    {2, {1.0f, 0.25f, 0.0f}},
    {3, {1.0f, -0.25f, 0.0f}},
    {4, {1.0f, -0.25f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_10[7] = {
    {3, {0.0f, 1.0f, 0.0f}},
    {4, {0.0f, 1.0f, 0.0f}},
    {5, {0.0f, 1.0f, 0.0f}},
    {8, {0.0f, 1.0f, 0.0f}},
    {9, {0.0f, 1.0f, 0.0f}},
    {10, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_11[5] = {
    {1, {1.0f, 0.0f, 1.0f}},
    {2, {1.0f, 0.0f, 1.0f}},
    {3, {1.0f, 0.0f, 1.0f}},
    {4, {1.0f, 0.0f, 1.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_12[4] = {
    {3, {0.0f, 1.0f, 0.0f}},
    {4, {0.0f, 1.0f, 0.0f}},
    {5, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_13[6] = {
    {3, {0.0f, 1.0f, 0.0f}},
    {4, {0.0f, 1.0f, 0.0f}},
    {5, {0.0f, 1.0f, 0.0f}},
    {8, {0.0f, 1.0f, 0.0f}},
    {9, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_14[3] = {
    {3, {0.0f, 1.0f, 0.25f}},
    {4, {0.0f, 1.0f, 0.25f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_15[3] = {
    {1, {1.0f, 0.45f, -0.45f}},
    {2, {1.0f, -0.45f, 0.45f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_16[5] = {
    {1, {0.1f, 0.0f, 0.71f}},
    {2, {0.1f, 0.0f, 0.71f}},
    {3, {0.1f, 0.0f, 0.71f}},
    {4, {0.1f, 0.0f, 0.71f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_17[4] = {
    {3, {0.0f, 1.0f, 0.0f}},
    {4, {0.0f, 1.0f, 0.0f}},
    {5, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_18[3] = {
    {6, {0.0f, 0.0f, 1.0f}},
    {7, {0.0f, 0.0f, 1.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_19[5] = {
    {6, {0.0f, 1.0f, 0.0f}},
    {7, {0.0f, 1.0f, 0.0f}},
    {10, {0.0f, 1.0f, 0.0f}},
    {11, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_20[8] = {
    {6, {0.0f, 1.0f, 0.0f}},
    {7, {0.0f, 1.0f, 0.0f}},
    {8, {0.0f, 1.0f, 0.0f}},
    {11, {0.0f, 1.0f, 0.0f}},
    {12, {0.0f, 1.0f, 0.0f}},
    {15, {0.0f, 1.0f, 0.0f}},
    {16, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_21[9] = {
    {1, {1.0f, 0.0f, 0.2f}},
    {2, {1.0f, 0.0f, 0.2f}},
    {3, {1.0f, 0.0f, 0.2f}},
    {4, {1.0f, 0.0f, 0.2f}},
    {5, {-1.0f, 0.0f, -0.2f}},
    {6, {-1.0f, 0.0f, -0.2f}},
    {7, {-1.0f, 0.0f, -0.2f}},
    {8, {-1.0f, 0.0f, -0.2f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_22[3] = {
    {1, {1.0f, 0.45f, -0.45f}},
    {2, {1.0f, -0.45f, 0.45f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_23[3] = {
    {2, {0.0f, 1.0f, 0.0f}},
    {3, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_24[5] = {
    {6, {0.0f, 0.5f, 0.0f}},
    {7, {0.0f, 0.5f, 0.0f}},
    {10, {0.0f, 1.0f, 0.0f}},
    {11, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_25[5] = {
    {6, {1.0f, 0.5f, 0.0f}},
    {7, {1.2f, 0.7f, 0.0f}},
    {10, {-1.0f, 0.5f, 0.0f}},
    {11, {-1.2f, 0.7f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_26[2] = {
    {1, {1.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_27[2] = {
    {1, {1.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_28[3] = {
    {6, {0.0f, 0.0f, 1.0f}},
    {7, {0.0f, 0.0f, 1.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_29[5] = {
    {1, {-1.0f, 0.25f, 0.0f}},
    {2, {-1.0f, 0.25f, 0.0f}},
    {3, {1.0f, -0.25f, 0.0f}},
    {4, {1.0f, -0.25f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_30[4] = {
    {3, {0.0f, 1.0f, 0.0f}},
    {4, {0.0f, 1.0f, 0.0f}},
    {5, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_31[2] = {
    {1, {1.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_32[4] = {
    {6, {0.0f, 1.0f, 0.0f}},
    {7, {0.0f, 1.0f, 0.0f}},
    {8, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_33[6] = {
    {1, {1.0f, 0.0f, 0.0f}},
    {2, {1.0f, 0.0f, 0.0f}},
    {3, {1.0f, 0.0f, 0.0f}},
    {4, {1.0f, 0.0f, 0.0f}},
    {5, {1.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_34[4] = {
    {6, {0.0f, 1.0f, 0.0f}},
    {7, {0.0f, 1.0f, 0.0f}},
    {8, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_35[3] = {
    {1, {1.0f, 0.0f, 0.0f}},
    {2, {-1.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_36[2] = {
    {1, {1.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_37[4] = {
    {6, {0.0f, 1.0f, 0.0f}},
    {7, {0.0f, 1.0f, 0.0f}},
    {8, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_38[5] = {
    {1, {1.0f, 0.0f, 0.0f}},
    {2, {1.0f, 0.0f, 0.0f}},
    {3, {1.0f, 0.0f, 0.0f}},
    {4, {1.0f, 0.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotKey hair_bone_rotation_bone_list_39[4] = {
    {6, {0.0f, 1.0f, 0.0f}},
    {7, {0.0f, 1.0f, 0.0f}},
    {8, {0.0f, 1.0f, 0.0f}},
    {-1, {0.0f, 0.0f, 0.0f}},
};
EZBoneRotDesc hair_bone_rotation_desc_00 = {
    2560, 4096, 4096, 1.1f,
    hair_bone_rotation_bone_list_00,
};
EZBoneRotDesc hair_bone_rotation_desc_01 = {
    768, 4096, 4096, 1.1f,
    hair_bone_rotation_bone_list_01,
};
EZBoneRotDesc hair_bone_rotation_desc_02 = {
    1536, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_02,
};
EZBoneRotDesc hair_bone_rotation_desc_03 = {
    1536, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_03,
};
EZBoneRotDesc hair_bone_rotation_desc_04 = {
    1536, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_04,
};
EZBoneRotDesc hair_bone_rotation_desc_05 = {
    1536, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_05,
};
EZBoneRotDesc hair_bone_rotation_desc_06 = {
    1536, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_06,
};
EZBoneRotDesc hair_bone_rotation_desc_07 = {
    1536, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_07,
};
EZBoneRotDesc hair_bone_rotation_desc_08 = {
    1024, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_08,
};
EZBoneRotDesc hair_bone_rotation_desc_09 = {
    6144, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_09,
};
EZBoneRotDesc hair_bone_rotation_desc_10 = {
    1024, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_10,
};
EZBoneRotDesc hair_bone_rotation_desc_11 = {
    640, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_11,
};
EZBoneRotDesc hair_bone_rotation_desc_12 = {
    1024, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_12,
};
EZBoneRotDesc hair_bone_rotation_desc_13 = {
    1024, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_13,
};
EZBoneRotDesc hair_bone_rotation_desc_14 = {
    2048, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_14,
};
EZBoneRotDesc hair_bone_rotation_desc_15 = {
    6144, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_15,
};
EZBoneRotDesc hair_bone_rotation_desc_16 = {
    5120, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_16,
};
EZBoneRotDesc hair_bone_rotation_desc_17 = {
    512, 4096, 4096, 1.1f,
    hair_bone_rotation_bone_list_17,
};
EZBoneRotDesc hair_bone_rotation_desc_18 = {
    3072, 5120, 6144, 0.95f,
    hair_bone_rotation_bone_list_18,
};
EZBoneRotDesc hair_bone_rotation_desc_19 = {
    2560, 6144, 14336, 0.95f,
    hair_bone_rotation_bone_list_19,
};
EZBoneRotDesc hair_bone_rotation_desc_20 = {
    1024, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_20,
};
EZBoneRotDesc hair_bone_rotation_desc_21 = {
    1024, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_21,
};
EZBoneRotDesc hair_bone_rotation_desc_22 = {
    6144, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_22,
};
EZBoneRotDesc hair_bone_rotation_desc_23 = {
    1536, 2560, 8192, 1.1f,
    hair_bone_rotation_bone_list_23,
};
EZBoneRotDesc hair_bone_rotation_desc_24 = {
    3072, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_24,
};
EZBoneRotDesc hair_bone_rotation_desc_25 = {
    1024, 6144, 8192, 1.1f,
    hair_bone_rotation_bone_list_25,
};
EZBoneRotDesc hair_bone_rotation_desc_26 = {
    1536, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_26,
};
EZBoneRotDesc hair_bone_rotation_desc_27 = {
    2048, 5120, 8192, 1.1f,
    hair_bone_rotation_bone_list_27,
};
EZBoneRotDesc hair_bone_rotation_desc_28 = {
    832, 5120, 8192, 1.1f,
    hair_bone_rotation_bone_list_28,
};
EZBoneRotDesc hair_bone_rotation_desc_29 = {
    6144, 4096, 8192, 1.1f,
    hair_bone_rotation_bone_list_29,
};
EZBoneRotDesc hair_bone_rotation_desc_30 = {
    512, 4096, 4096, 1.1f,
    hair_bone_rotation_bone_list_30,
};
EZBoneRotDesc hair_bone_rotation_desc_31 = {
    3072, 4096, 4096, 1.1f,
    hair_bone_rotation_bone_list_31,
};
EZBoneRotDesc hair_bone_rotation_desc_32 = {
    1536, 4096, 8192, 1.2f,
    hair_bone_rotation_bone_list_32,
};
EZBoneRotDesc hair_bone_rotation_desc_33 = {
    512, 4096, 4096, 1.1f,
    hair_bone_rotation_bone_list_33,
};
EZBoneRotDesc hair_bone_rotation_desc_34 = {
    768, 4096, 4096, 1.1f,
    hair_bone_rotation_bone_list_34,
};
EZBoneRotDesc hair_bone_rotation_desc_35 = {
    3072, 4096, 4096, 1.1f,
    hair_bone_rotation_bone_list_35,
};
EZBoneRotDesc hair_bone_rotation_desc_36 = {
    1536, 4096, 4096, 1.1f,
    hair_bone_rotation_bone_list_36,
};
EZBoneRotDesc hair_bone_rotation_desc_37 = {
    768, 4096, 4096, 1.1f,
    hair_bone_rotation_bone_list_37,
};
EZBoneRotDesc hair_bone_rotation_desc_38 = {
    1024, 4096, 4096, 1.1f,
    hair_bone_rotation_bone_list_38,
};
EZBoneRotDesc hair_bone_rotation_desc_39 = {
    1536, 4096, 8192, 1.2f,
    hair_bone_rotation_bone_list_39,
};
EntX_800FE5A0 hair_effect_selection_table[41] = {
    {0, -1, 7, -1, &hair_bone_rotation_desc_00, 0, 0},
    {0, -1, 9, -1, &hair_bone_rotation_desc_01, 0, 0},
    {1, -1, 3, -1, &hair_bone_rotation_desc_02, 0, 0},
    {1, -1, 4, -1, &hair_bone_rotation_desc_03, 0, 0},
    {1, -1, 6, -1, &hair_bone_rotation_desc_04, 0, 0},
    {5, -1, -1, 1, &hair_bone_rotation_desc_05, 0, 0},
    {5, -1, -1, 2, &hair_bone_rotation_desc_06, 0, 0},
    {5, -1, -1, 3, &hair_bone_rotation_desc_07, 0, 0},
    {6, -1, 0, -1, &hair_bone_rotation_desc_08, 0, 0},
    {6, 2, -1, -1, &hair_bone_rotation_desc_09, 0, 0},
    {6, 3, -1, -1, &hair_bone_rotation_desc_10, 0, 0},
    {6, -1, 3, -1, &hair_bone_rotation_desc_11, 0, 0},
    {6, -1, 5, -1, &hair_bone_rotation_desc_12, 0, 0},
    {6, -1, 6, -1, &hair_bone_rotation_desc_13, 0, 0},
    {6, 9, -1, -1, &hair_bone_rotation_desc_14, 0, 0},
    {7, 1, -1, -1, &hair_bone_rotation_desc_15, 0, 0},
    {7, -1, 5, -1, &hair_bone_rotation_desc_16, 0, 0},
    {7, -1, 7, -1, &hair_bone_rotation_desc_17, 0, 0},
    {7, 9, -1, -1, &hair_bone_rotation_desc_18, 0, 0},
    {8, 0, -1, -1, &hair_bone_rotation_desc_19, 0, 0},
    {8, -1, 0, -1, &hair_bone_rotation_desc_20, 0, 0},
    {8, -1, 3, -1, &hair_bone_rotation_desc_21, 0, 0},
    {8, 5, -1, -1, &hair_bone_rotation_desc_22, 0, 0},
    {8, 6, -1, -1, &hair_bone_rotation_desc_23, 0, 0},
    {8, -1, 6, -1, &hair_bone_rotation_desc_24, 0, 0},
    {8, 9, -1, -1, &hair_bone_rotation_desc_25, 0, 0},
    {9, -1, -1, 0, &hair_bone_rotation_desc_26, 0, 0},
    {9, -1, -1, 2, &hair_bone_rotation_desc_27, 0, 0},
    {10, 2, -1, -1, &hair_bone_rotation_desc_28, 0, 0},
    {10, 3, -1, -1, &hair_bone_rotation_desc_29, 0, 0},
    {10, -1, 5, -1, &hair_bone_rotation_desc_30, 0, 0},
    {10, -1, 7, -1, &hair_bone_rotation_desc_31, 0, 0},
    {10, 8, -1, -1, &hair_bone_rotation_desc_32, 0, 0},
    {10, -1, 9, -1, &hair_bone_rotation_desc_33, 0, 0},
    {11, -1, 1, -1, &hair_bone_rotation_desc_34, 0, 0},
    {11, -1, 3, -1, &hair_bone_rotation_desc_35, 0, 0},
    {11, -1, 4, -1, &hair_bone_rotation_desc_36, 0, 0},
    {11, -1, 6, -1, &hair_bone_rotation_desc_37, 0, 0},
    {11, -1, 7, -1, &hair_bone_rotation_desc_38, 0, 0},
    {11, 9, -1, -1, &hair_bone_rotation_desc_39, 0, 0},
    {-1, -1, -1, -1, 0, 0, 0},
};
EZBoneRotKey hair_bone_rotation_bone_list_of_descriptor[5] = {
    {1, {0.5f, 0.0f, 1.0f}},
    {2, {0.5f, 0.0f, 1.0f}},
    {3, {0.5f, 0.0f, 1.0f}},
    {4, {0.5f, 0.0f, 1.0f}},
    {-1, {0.0f, 0.0f, 0.25f}},
};
EZBoneRotDesc hair_bone_rotation_descriptor[1] = {
    {
    1024, 3072, 4096, 1.1f,
    hair_bone_rotation_bone_list_of_descriptor,
    },
};

}

const char *wait_entry_hair_move_sim_name = "TObjWaitEntryHairMoveSim";
const char *T_OWEHMS_Exp__name = "T_OWEHMS_Exp";

TObjWaitEntryHairMoveSim::~TObjWaitEntryHairMoveSim() {}

TObject *create_hair_move_sim(TObjPlayer *player) {
    if (character_display_index(reinterpret_cast<uaddr>((const u8 *)player + 0x85C)) == 0xE) {
        TObjTailsTailsMove::create(player);
        return 0;
    }
    if (((s32 (*)(void *))is_move_done__24TObjWaitEntryHairMoveSimFv)((void *)player) != 0) {
        T_OWEHMS_Exp::create(player);
        return 0;
    }
    if (is_level_in_table__24TObjWaitEntryHairMoveSimFPv((Obj_800FE698 *)player) != 0) {
        return new TObjWaitEntryHairMoveSim(player);
    }
    return 0;
}

s32 is_level_in_table__24TObjWaitEntryHairMoveSimFPv(Obj_800FE698 *o) {
    EntX_800FE5A0 *e;
    if (o->flags & 0xA) {
        return 0;
    }
    for (e = hair_effect_selection_table; e->a >= 0 && e->a <= o->lvl; e++) {
        if (o->lvl == e->a && (o->v9C == e->b || o->v9C == e->c || o->v9A == e->d)) {
            return 1;
        }
    }
    return 0;
}

void create_hair_effects__24TObjWaitEntryHairMoveSimFPv(TObjWaitEntryHairMoveSim *wait_entry_hair_move_sim) {
    Self_800FE5A0 *self = (Self_800FE5A0 *)wait_entry_hair_move_sim;
    EntX_800FE5A0 *e;
    saddr v;
    for (e = hair_effect_selection_table; e->a >= 0 && e->a <= self->pl->lvl; e++) {
        if (self->pl->lvl == e->a) {
            if (self->pl->v9C == e->b) {
                v = self->pl->vB0;
            } else if (self->pl->v9C == e->c) {
                v = self->pl->vAC;
            } else if (self->pl->v9A == e->d) {
                v = self->pl->vB4;
            } else {
                continue;
            }
            TObjWaitEntryHairMoveSim__sub_800FE3BC(v);
            if (e->p4 != NULL) {
                TObjEZBoneRotPlayer::create(self->pl, (void *)v, e->p4);
            } else if (e->p8 != NULL) {
                ((TObjPlayer *)(self->pl))->create_hairmove(e->p8, (void *)e->pc);
            }
        }
    }
}

TObjWaitEntryHairMoveSim::TObjWaitEntryHairMoveSim(TObjPlayer *player) : TObject(player) {
    m_name = wait_entry_hair_move_sim_name;
    this->player = player;
}

void TObjWaitEntryHairMoveSim::run_task() {
    if (player->model_load_flags == 0) {
        create_hair_effects__24TObjWaitEntryHairMoveSimFPv(this);
        queue_destruction();
    }
}

T_OWEHMS_Exp* T_OWEHMS_Exp::create(TObjPlayer* p) {
    if (((int (*)(TObjPlayer*))is_move_done__24TObjWaitEntryHairMoveSimFv)(p) == 0) {
        return NULL;
    }
    return new T_OWEHMS_Exp(p);
}

T_OWEHMS_Exp::T_OWEHMS_Exp(TObjPlayer *p) : TObject(p) {
    m_name = T_OWEHMS_Exp__name;
    player = p;
    descriptor_index = get_move_done_result__24TObjWaitEntryHairMoveSimFPv((H_800FE32C*)player);
}

T_OWEHMS_Exp::~T_OWEHMS_Exp() {}

void T_OWEHMS_Exp::run_task() {
    if (player->model_load_flags == 0) {
        start_bone_rotation();
        queue_destruction();
    }
}

void TObjWaitEntryHairMoveSim__sub_800FE3BC(int bone) {  }

void T_OWEHMS_Exp::start_bone_rotation() {
    saddr bone = (saddr)player->hair_model;
    TObjWaitEntryHairMoveSim__sub_800FE3BC(bone);
    TObjEZBoneRotPlayer::create(player, (void *)bone, &hair_bone_rotation_descriptor[descriptor_index]);
}

s32 get_move_done_result__24TObjWaitEntryHairMoveSimFPv(H_800FE32C *h) {
    if (!(h->flags & 0xA)) {
        return -1;
    }
    switch (h->state) {
    case 6:
        return 0;
    }
    return -1;
}

int is_move_done__24TObjWaitEntryHairMoveSimFv(void) {
    return (~((int (*)(void))get_move_done_result__24TObjWaitEntryHairMoveSimFPv)()) != 0 ? 1 : 0;
}
