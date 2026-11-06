#include "pso/boss/dragon/ObjBoss1CommonJResource.h"

const char *bm_obj_boss1_common_j_model_names[] = {
    "dokutu_fe_obj001_drayuka.nj",
    "dokutu_hunkakou1.nj",
    "dokutu_fe_obj001_draiwa01.nj",
    "dokutu_fe_obj001_draiwa02.nj",
    "grid2_jimen.nj",
    NULL,
};
const char *bm_obj_boss1_common_j_motion_names[] = { NULL };
BmlResourceDescriptor bm_obj_boss1_common_j_resource_descriptor = {
    "bm_obj_boss1_common_j.bml", bm_obj_boss1_common_j_model_names, bm_obj_boss1_common_j_motion_names, 5, 0,
};

// Inferred name (the string is the texture archive of bm_obj_boss1_common_j.bml).
extern const char obj_boss1_common_j_texture_filename[] = "obj_boss1_common_j.gvm";
