#include "types.h"
#include "pso/npc/TObjNpcConnoisseur.h"
#include "pso/npc/TObjNpcExpertBase.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/ui/font/TFontSmallTask.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResourceLoader.h"

const char *bm_n_kanteib_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_kanteib_i_body_model_names[2] = { "n_kanteib_i_body_1.nj", NULL };
BmlResourceDescriptor bm_n_kanteib_i_body_resource_descriptor = { "bm_n_kanteib_i_body.bml", bm_n_kanteib_i_body_model_names, bm_n_kanteib_i_body_motion_names, 1, 0 };
const char *bm_n_kanteib2_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_kanteib2_i_body_model_names[2] = { "n_kanteib2_i_body.nj", NULL };
BmlResourceDescriptor bm_n_kanteib2_i_body_resource_descriptor = { "bm_n_kanteib2_i_body.bml", bm_n_kanteib2_i_body_model_names, bm_n_kanteib2_i_body_motion_names, 1, 0 };
const char *bm_n_kanteif_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_kanteif_i_body_model_names[2] = { "n_kanteif_i_body.nj", NULL };
BmlResourceDescriptor bm_n_kanteif_i_body_resource_descriptor = { "bm_n_kanteif_i_body.bml", bm_n_kanteif_i_body_model_names, bm_n_kanteif_i_body_motion_names, 1, 0 };
const char *bm_n_kanteif2_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_kanteif2_i_body_model_names[2] = { "n_kanteif2_i_body.nj", NULL };
BmlResourceDescriptor bm_n_kanteif2_i_body_resource_descriptor = { "bm_n_kanteif2_i_body.bml", bm_n_kanteif2_i_body_model_names, bm_n_kanteif2_i_body_motion_names, 1, 0 };
const char *bm_n_kanteifs_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_kanteifs_i_body_model_names[2] = { "n_kanteifs_i_body.nj", NULL };
BmlResourceDescriptor bm_n_kanteifs_i_body_resource_descriptor = { "bm_n_kanteifs_i_body.bml", bm_n_kanteifs_i_body_model_names, bm_n_kanteifs_i_body_motion_names, 1, 0 };
const char *bm_n_kanteifs2_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_kanteifs2_i_body_model_names[2] = { "n_kanteifs2_i_body.nj", NULL };
BmlResourceDescriptor bm_n_kanteifs2_i_body_resource_descriptor = { "bm_n_kanteifs2_i_body.bml", bm_n_kanteifs2_i_body_model_names, bm_n_kanteifs2_i_body_motion_names, 1, 0 };
const char *bm_n_kanteio_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_kanteio_i_body_model_names[2] = { "n_kanteio_i_body.nj", NULL };
BmlResourceDescriptor bm_n_kanteio_i_body_resource_descriptor = { "bm_n_kanteio_i_body.bml", bm_n_kanteio_i_body_model_names, bm_n_kanteio_i_body_motion_names, 1, 0 };
const char *bm_n_kanteio2_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_kanteio2_i_body_model_names[2] = { "n_kanteio2_i_body.nj", NULL };
BmlResourceDescriptor bm_n_kanteio2_i_body_resource_descriptor = { "bm_n_kanteio2_i_body.bml", bm_n_kanteio2_i_body_model_names, bm_n_kanteio2_i_body_motion_names, 1, 0 };
const char *bm_n_kanteit_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_kanteit_i_body_model_names[2] = { "n_kanteit_i_body.nj", NULL };
BmlResourceDescriptor bm_n_kanteit_i_body_resource_descriptor = { "bm_n_kanteit_i_body.bml", bm_n_kanteit_i_body_model_names, bm_n_kanteit_i_body_motion_names, 1, 0 };
const char *bm_n_kanteit2_i_body_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_n_kanteit2_i_body_model_names[2] = { "n_kanteit2_i_body.nj", NULL };
BmlResourceDescriptor bm_n_kanteit2_i_body_resource_descriptor = { "bm_n_kanteit2_i_body.bml", bm_n_kanteit2_i_body_model_names, bm_n_kanteit2_i_body_motion_names, 1, 0 };
BmlResourceDescriptor *tekker_descriptor_selector_table[10] = {
    &bm_n_kanteifs_i_body_resource_descriptor, &bm_n_kanteif_i_body_resource_descriptor,
    &bm_n_kanteifs2_i_body_resource_descriptor, &bm_n_kanteib_i_body_resource_descriptor,
    &bm_n_kanteif2_i_body_resource_descriptor, &bm_n_kanteit_i_body_resource_descriptor,
    &bm_n_kanteio_i_body_resource_descriptor, &bm_n_kanteit2_i_body_resource_descriptor,
    &bm_n_kanteio2_i_body_resource_descriptor, &bm_n_kanteib2_i_body_resource_descriptor,
};
const char *TObjNpcConnoisseur__name = "TObjNpcConnoisseur";


struct RecoveredGlobal_801499DC___vt__18TObjNpcConnoisseur {
    s32 value;
    u8 remaining[0x174];
};

extern "C" {
extern s32 __vt__18TObjNpcConnoisseur[];
extern u32 TObjNpcConnoisseur__instance;
extern u8 TLobby__data_805011D8[];
extern s32 lbl_805D5748;
void *__ct__11TObjControlFP7TObject(void *, void *);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TObjNpcConnoisseur::destroy_instance() {
    if ((u32) TObjNpcConnoisseur__instance != 0U) {
        TLobby__sub_8001FE7C((void*)TObjNpcConnoisseur__instance, 1);
        TObjNpcConnoisseur__instance = 0U;
    }
}

void TObjNpcConnoisseur::load_section_motion() {
    void *o;
    lbl_805D5748 = ((TFontSmallTask *)TLobby__data_805011D8)->get_task_id();
    o = ::operator new(0x440);
    if (o != 0) {
        o = load_resource_from_descriptor(o, 1, tekker_descriptor_selector_table[lbl_805D5748], 0, 0, 0);
    }
    TObjNpcConnoisseur__instance = (u32)o;
}

}
TObjNpcConnoisseur::~TObjNpcConnoisseur() {}
extern "C" {

extern void *tl_04;

typedef char RecoveredGlobal_801499DC___vt__18TObjNpcConnoisseur_size[sizeof(RecoveredGlobal_801499DC___vt__18TObjNpcConnoisseur) == 0x178 ? 1 : -1];
u8 *TObjNpcConnoisseur__ct(u8 *player, s32 arg1, s32 arg2) {
    ((TUnk_804A9F50 *)player)->construct_male_npc_base();
    *(s32 **)((s8 *)player + 0x18) = &(*(RecoveredGlobal_801499DC___vt__18TObjNpcConnoisseur *)&__vt__18TObjNpcConnoisseur).value;
    *(const char **)((s8 *)player + 0) = TObjNpcConnoisseur__name;
    ((TObjNpcConnoisseur *)(player))->apply_set_data((void *)arg2);
    ((TObjPlayer *)player)->init_position_vectors();
    *(s32 *)((s8 *)player + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcConnoisseur__instance) + 0x42C)) + 8);
    ((TObjNpcConnoisseur *)player)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcConnoisseur__instance) + 0x42C)) + 0xC);
    ((TObjNpcBase *)player)->setup_common();
    return player;
}

void * TObjNpcExpertBase__create(void *arg0) {
    void *o;
    void *o2;
    o = __nw__7TObjectFUl(0x20);
    if (o != NULL) {
        o = __ct__11TObjControlFP7TObject(o, tl_04);
    }
    o2 = __nw__7TObjectFUl(0x3B8);
    if (o2 != NULL) {
        o2 = TObjNpcExpertBase__ct((u8 *)o2, (s32)o, (s32)arg0);
    }
    return o2;
}

}
