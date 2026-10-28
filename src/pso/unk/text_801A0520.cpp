#include "types.h"
#include "pso/unk/text_801A0520.h"
#include "pso/object/TObjDoorJung.h"
#include "pso/system/BmlResourceDescriptor.h"

extern char lbl_80446678[];
extern char lbl_80446690[];
extern char lbl_804466AC[];
extern char lbl_804466C8[];
extern const char *bm_obj_warp_jung_model_names[3];
extern const char *bm_obj_warp_jung_motion_names[2];
extern BmlResourceDescriptor jungle_warp_beam_resource_descriptor;

struct Node_801A0578 {
    u8 pad0[4];
    s32 f4;
    u8 pad8[0x2C - 8];
    Node_801A0578 *child;
    Node_801A0578 *sibling;
};

extern "C" {
void TLobby__sub_8001FE7C(void *, int);
extern void *TObjWarpJung__beam_bml_resource;
extern s32 warp_jung_beam_motion;
extern s32 warp_jung_model_handle;
extern s32 warp_jung_beam_models[6];
s32 get_bml_motion(void *, s32);
s32 TObjFish__sub_8001EDB0(void *, s32);
Node_801A0578 *get_bml_model(void *, s32);
void *load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
}
extern char lbl_80446718[];
extern char lbl_80446728[];
extern char lbl_80446738[];
extern s32 lbl_805D5CB4;
extern s32 warp_jung_beam_mesh_node;
extern s32 warp_jung_beam_entry_index;
extern s32 lbl_805D5CC0;
extern s32 lbl_805D5CC4;
void free_warp_jung_beam_resources(void) {
    s32 i;
    TLobby__sub_8001FE7C(TObjWarpJung__beam_bml_resource, 1);
    TObjWarpJung__beam_bml_resource = 0;
    warp_jung_beam_motion = 0;
    warp_jung_model_handle = 0;
    for (i = 0; i < 6; i++) {
        warp_jung_beam_models[i] = 0;
    }
}
void load_warp_beam_resources(void) {
    Node_801A0578 *root;
    void *p;
    p = ::operator new(0x440);
    if (p != NULL) {
        p = load_resource_from_descriptor(p, 5, &jungle_warp_beam_resource_descriptor, 0, 0, 0);
    }
    TObjWarpJung__beam_bml_resource = p;
    warp_jung_beam_motion = get_bml_motion(p, 0);
    warp_jung_model_handle = TObjFish__sub_8001EDB0(TObjWarpJung__beam_bml_resource, 0);
    root = get_bml_model(TObjWarpJung__beam_bml_resource, 1)->child;
    warp_jung_beam_models[0] = root->child->f4;
    warp_jung_beam_models[1] = root->child->sibling->f4;
    warp_jung_beam_models[2] = root->child->sibling->sibling->f4;
    warp_jung_beam_models[3] = root->child->sibling->sibling->sibling->f4;
    warp_jung_beam_models[4] = root->child->sibling->sibling->sibling->sibling->f4;
    warp_jung_beam_models[5] = root->sibling->f4;
    warp_jung_beam_mesh_node = root->sibling->sibling->sibling->f4;
    lbl_805D5CB4 = 0;
    warp_jung_beam_entry_index = ((TObjDoorJung *)warp_jung_model_handle)->find_entry_by_name(lbl_80446718);
    lbl_805D5CC0 = ((TObjDoorJung *)warp_jung_model_handle)->find_entry_by_name(lbl_80446728);
    lbl_805D5CC4 = ((TObjDoorJung *)warp_jung_model_handle)->find_entry_by_name(lbl_80446738);
}
extern "C" {

__declspec(section ".data") const char *bm_obj_warp_jung_model_names[3] = { lbl_80446678, lbl_80446690, NULL };
__declspec(section ".data") const char *bm_obj_warp_jung_motion_names[2] = { lbl_804466AC, NULL };
}
BmlResourceDescriptor jungle_warp_beam_resource_descriptor = { lbl_804466C8, bm_obj_warp_jung_model_names, bm_obj_warp_jung_motion_names, 2, 1 };
