#include "pso/system/EnemyBmlResource.h"
#include "types.h"
#include "pso/boss/goldragon/BossAssetVariant.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/boss/galgryphon/Boss5CommonResource.h"
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
    switch (get_boss_asset_variant()) {
    case 0:
        boss5_common_bml_resource = load_enemy_bml_resource(&bm_obj_boss5_common_resource_descriptor);
        boss5_common_texture_list = LoadPvmFileTls("obj_boss5_common.gvm");
        break;
    }
}
