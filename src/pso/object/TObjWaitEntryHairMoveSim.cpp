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
HairEffectEntry hair_effect_selection_table[41] = {
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

const char *wait_entry_hair_move_sim_name = "TObjWaitEntryHairMoveSim";
const char *owehms_exp_name = "T_OWEHMS_Exp";

TObjWaitEntryHairMoveSim::~TObjWaitEntryHairMoveSim() {}

TObject *create_hair_move_sim(TObjPlayer *player) {
    if (character_display_index((uaddr)player->name) == 0xE) {
        TObjTailsTailsMove::create(player);
        return 0;
    }
    if (TObjWaitEntryHairMoveSim::is_move_done(player) != 0) {
        T_OWEHMS_Exp::create(player);
        return 0;
    }
    if (TObjWaitEntryHairMoveSim::is_level_in_table(player) != 0) {
        return new TObjWaitEntryHairMoveSim(player);
    }
    return 0;
}

s32 TObjWaitEntryHairMoveSim::is_level_in_table(TObjPlayer *player) {
    HairEffectEntry *e;
    if (player->v2_flags & 0xA) {
        return 0;
    }
    for (e = hair_effect_selection_table; e->class_id >= 0 && e->class_id <= player->char_class; e++) {
        if (player->char_class == e->class_id &&
            (player->hair == e->head_model_hair || player->hair == e->hair_model_hair ||
             player->head == e->attachment_model_head)) {
            return 1;
        }
    }
    return 0;
}

void TObjWaitEntryHairMoveSim::create_hair_effects() {
    HairEffectEntry *e;
    NJS_OBJECT *model;
    for (e = hair_effect_selection_table; e->class_id >= 0 && e->class_id <= player->char_class; e++) {
        if (player->char_class == e->class_id) {
            if (player->hair == e->head_model_hair) {
                model = (NJS_OBJECT *)player->head_model;
            } else if (player->hair == e->hair_model_hair) {
                model = (NJS_OBJECT *)player->hair_model;
            } else if (player->head == e->attachment_model_head) {
                model = (NJS_OBJECT *)player->attachment_model;
            } else {
                continue;
            }
            sub_800FE3BC(model);
            if (e->bone_rotation != NULL) {
                TObjEZBoneRotPlayer::create(player, model, e->bone_rotation);
            } else if (e->rope_spec != NULL) {
                player->create_hairmove(e->rope_spec, e->collider_spec);
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
        create_hair_effects();
        queue_destruction();
    }
}

T_OWEHMS_Exp* T_OWEHMS_Exp::create(TObjPlayer* p) {
    if (TObjWaitEntryHairMoveSim::is_move_done(p) == 0) {
        return NULL;
    }
    return new T_OWEHMS_Exp(p);
}

T_OWEHMS_Exp::T_OWEHMS_Exp(TObjPlayer *p) : TObject(p) {
    m_name = owehms_exp_name;
    player = p;
    descriptor_index = TObjWaitEntryHairMoveSim::get_move_done_result(player);
}

T_OWEHMS_Exp::~T_OWEHMS_Exp() {}

void T_OWEHMS_Exp::run_task() {
    if (player->model_load_flags == 0) {
        start_bone_rotation();
        queue_destruction();
    }
}

void TObjWaitEntryHairMoveSim::sub_800FE3BC(NJS_OBJECT *model) {  }

void T_OWEHMS_Exp::start_bone_rotation() {
    NJS_OBJECT *model = (NJS_OBJECT *)player->hair_model;
    TObjWaitEntryHairMoveSim::sub_800FE3BC(model);
    TObjEZBoneRotPlayer::create(player, model, &hair_bone_rotation_descriptor[descriptor_index]);
}

s32 TObjWaitEntryHairMoveSim::get_move_done_result(TObjPlayer *player) {
    if (!(player->v2_flags & 0xA)) {
        return -1;
    }
    switch (player->extra_model) {
    case 6:
        return 0;
    }
    return -1;
}

int TObjWaitEntryHairMoveSim::is_move_done(TObjPlayer *player) {
    return get_move_done_result(player) != -1 ? 1 : 0;
}
