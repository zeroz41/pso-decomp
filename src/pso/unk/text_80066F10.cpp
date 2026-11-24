#include "pso/system/EnemyBmlResource.h"
#include "types.h"
#include "pso/boss/goldragon/TBoss8Dragon_8005D700.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_80066F10.h"
#include "pso/system/BmlResourceDescriptor.h"

const char *bm_obj_boss5_common_model_names[9] = {
    "fe_obj001_hasira_kuzure.gj", "fe_obj001_hasira_sita.gj", "obj001_hasira_null_matome.gj",
    "fe_obj001_hasira_kuzure_gri.gj", "fe_obj001_hasira_sita_gri.gj", "fe_obj001_yuka_ware.gj",
    "fe_obj001_kusa.gj", "obj001_kusa_null_matome.gj", NULL,
};
const char *bm_obj_boss5_common_motion_names[5] = {
    "fe_obj001_hasira_kuzure.njm", "fe_obj001_hasira_sita.njm", "fe_obj001_hasira_kuzure02.njm",
    "fe_obj001_hasira_sita02.njm", NULL,
};
BmlResourceDescriptor bm_obj_boss5_common_resource_descriptor = {
    "bm_obj_boss5_common.bml", bm_obj_boss5_common_model_names, bm_obj_boss5_common_motion_names, 8, 4
};
BmlResource *boss5_common_bml_resource;
NJS_TEXLIST *boss5_common_texture_list;
void load_boss5_common_assets(void) {
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        boss5_common_bml_resource = load_enemy_bml_resource(&bm_obj_boss5_common_resource_descriptor);
        boss5_common_texture_list = load_gvm_texture_file("obj_boss5_common.gvm");
        break;
    }
}
