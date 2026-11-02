#include "types.h"
#include "pso/enemy/TObjEneDD_800BB804.h"
#include "pso/boss/TBoss8Dragon_8005D700.h"
#include "pso/misc/TLanguage_801E4874.h"
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
extern void *lbl_805D4DD8;
extern void *boss5_common_texture_list;
void load_boss5_common_assets(void) {
    switch (TBoss8Dragon__sub_8005D700()) {
    case 0:
        lbl_805D4DD8 = (void *)load_enemy_bml_resource((u8 *)&bm_obj_boss5_common_resource_descriptor);
        boss5_common_texture_list = load_gvm_texture_file((s32)"obj_boss5_common.gvm");
        break;
    }
}
