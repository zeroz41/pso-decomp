#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/player/TObjPlayer_8002E784.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk_8003A81C.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/TLobby.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/GinjaTexture.h"

const char *bm_obj_boss2_common_model_names[] = {
    "fe_boss02iwa1.gj",
    "fe_boss02iwa2.gj",
    "fe_boss02iwa3.gj",
    "fe_crobj2.gj",
    "fe_crobj1.gj",
    "fe_crobj3.gj",
    "fe_obj001_complex3.gj",
    "fe_obj002_complex4.gj",
    "fe_obj003_obj1_1.gj",
    "fe_obj004_obj1.gj",
    "fe_obj006_grid2.gj",
    "fe_obj007_cube18_3.gj",
    "fe_obj008_cube18_3.gj",
    "fe_obj010_start.gj",
    "fe_obj001_muzu.gj",
    "fe_obj002_mizu.gj",
    "fe_obj003_mizu.gj",
    "fe_obj004_mizu.gj",
    "fe_obj006_mizu.gj",
    "fe_obj007_mizu.gj",
    "fe_obj008_mizu.gj",
    "fe_obj006_mizu1.gj",
    NULL,
};

__declspec(section ".sdata") const char *bm_obj_boss2_common_motion_names[1] = { NULL };

BmlResourceDescriptor bm_obj_boss2_common_resource_descriptor = {
    "bm_obj_boss2_common.bml",
    bm_obj_boss2_common_model_names,
    bm_obj_boss2_common_motion_names,
    22,
    0,
};

void *boss2_dermt_slot_table[7];
f32 boss2_ceil_junk_water_level;
s32 lbl_805D4BE4;
BmlResource *boss2_common_resource;
NJS_TEXLIST *boss2_common_texture_list;
__declspec(section ".sdata2") const f32 boss2_tunnel_max_scroll_speed = 9.259259f;
TObjBoss2CeilJunk *TObjBoss2CeilJunk::create(const Vec *position) {
    return new TObjBoss2CeilJunk(tl_05, position);
}


void __sinit_TObjBoss2CeilJunk_8003A81C_cpp(void) { boss2_ceil_junk_water_level = boss2_water_level; }
void free_boss2_common_resource(void) {
    s32 i;
    for (i = 0; i < 7; i++) {
        boss2_dermt_slot_table[i] = 0;
    }
    release_texture_list(boss2_common_texture_list);
    delete boss2_common_resource;
    boss2_common_resource = 0;
}

void load_boss2_common_resource(void) {
    BmlResource *resource = new BmlResource(5, &bm_obj_boss2_common_resource_descriptor, 0, 0, NULL);
    boss2_common_resource = resource;
    boss2_common_texture_list = resource->models[6].texlist;
    if (TObjEneDD::check_v2_mode() != 0) {
        TLobby::load_texture_pvm_file("obj_boss2_common_a.gvm", boss2_common_texture_list);
    } else {
        TLobby::load_texture_pvm_file("obj_boss2_common.gvm", boss2_common_texture_list);
    }
}

__declspec(section ".ctors") static void *const __sinit_TObjBoss2CeilJunk_8003A81C_cpp_ref = (void *)__sinit_TObjBoss2CeilJunk_8003A81C_cpp;
