#include "pso/boss/dragon/ObjBoss1CommonResource.h"

const char *bm_obj_boss1_common_model_names[] = {
    "dokutu_hunkakou1.nj",
    "dokutu_fe_obj001_draiwa01.nj",
    "dokutu_fe_obj001_draiwa02.nj",
    "grid2_jimen.nj",
    "dokutu_fe_obj001_drayuka.nj",
    "dokutu_fe_obj001_drayuka.gj",
    NULL,
};
const char *bm_obj_boss1_common_motion_names[] = { NULL };
BmlResourceDescriptor dragon_ground_resource_descriptor = {
    "bm_obj_boss1_common.bml", bm_obj_boss1_common_model_names, bm_obj_boss1_common_motion_names, 6, 0,
};

extern const char dragon_common_texture_filename[] = "obj_boss1_common.gvm";
extern const char dragon_common_alternate_bml_filename[] = "bm_obj_boss1_common_a.bml";
extern const char dragon_common_alternate_texture_filename[] = "obj_boss1_common_a.gvm";
