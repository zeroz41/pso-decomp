#include "types.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk_8003A81C.h"
#include "pso/boss/derolle/TObjBoss2CeilJunk.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/unk/TLobby.h"

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

extern "C" {
extern void *lbl_804FE9C8[];
extern void *lbl_805D4BEC;
extern void *boss2_tunnel_instance;
void release_texture_list(void *);
void TLobby__sub_8001FE7C(void *, int);
void *TObjBoss2CeilJunk__ct(void *, void *, void *);
void *__nw__7TObjectFUl(int);
void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);

extern void *tl_05;

void *TObjBoss2CeilJunk::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB8);
    if (o != NULL) {
        o = TObjBoss2CeilJunk__ct(o, tl_05, arg0);
    }
    return o;
}

    extern float lbl_805D4BE0;
    extern const float lbl_805D8258;
void TObjBoss2CeilJunk__sub_8003A868(void) { lbl_805D4BE0 = lbl_805D8258; }
void TLobby__sub_8003A874(void) {
    s32 i;
    for (i = 0; i < 7; i++) {
        lbl_804FE9C8[i] = 0;
    }
    release_texture_list(lbl_805D4BEC);
    TLobby__sub_8001FE7C(boss2_tunnel_instance, 1);
    boss2_tunnel_instance = 0;
}

void TLobby__sub_8003A8D0(void) {
    void *p = (void *)::operator new(0x440);
    if (p != NULL) {
        p = load_resource_from_descriptor(p, 5, &bm_obj_boss2_common_resource_descriptor, 0, 0, 0);
    }
    boss2_tunnel_instance = p;
    lbl_805D4BEC = *(void **)(*(u8 **)((u8 *)p + 0x42C) + 0x6C);
    if (TObjEneDD::check_v2_mode() != 0) {
        TLobby::load_texture_pvm_file("obj_boss2_common_a.gvm", (s32)lbl_805D4BEC);
    } else {
        TLobby::load_texture_pvm_file("obj_boss2_common.gvm", (s32)lbl_805D4BEC);
    }
}

}

__declspec(section ".ctors") static void *const __sinit_TObjBoss2CeilJunk_8003A81C_cpp_ref = (void *)TObjBoss2CeilJunk__sub_8003A868;
