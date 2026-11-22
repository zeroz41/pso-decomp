#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcConnoisseur.h"
#include "pso/npc/TObjNpcExpertBase.h"
#include "pso/npc/TUnk_804A9F50.h"

#include "pso/ui/font/TFontSmallTask.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

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


s32 lbl_805D5748;
uaddr TObjNpcConnoisseur__instance;
extern u8 TLobby__data_805011D8[];

void TObjNpcConnoisseur::destroy_instance() {
    if ((u32) TObjNpcConnoisseur__instance != 0U) {
        delete (BmlResource *)TObjNpcConnoisseur__instance;
        TObjNpcConnoisseur__instance = 0U;
    }
}

void TObjNpcConnoisseur::load_section_motion() {
    void *o;
    lbl_805D5748 = ((TFontSmallTask *)TLobby__data_805011D8)->get_task_id();
    o = new BmlResource(1, (BmlResourceDescriptor *)tekker_descriptor_selector_table[lbl_805D5748], 0, 0, NULL);
    TObjNpcConnoisseur__instance = (uaddr)o;
}

TObjNpcConnoisseur::~TObjNpcConnoisseur() {}


TObjNpcConnoisseur::TObjNpcConnoisseur(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    ((TObjNpcConnoisseur *)this)->m_name = TObjNpcConnoisseur__name;
    ((TObjNpcConnoisseur *)this)->apply_set_data(arg2);
    ((TObjPlayer *)this)->init_position_vectors();
    *(s32 *)((s8 *)this + 0x34) = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcConnoisseur__instance) + 0x42C)) + 8);
    ((TObjNpcConnoisseur *)this)->texlist = (s32) *(s32 *)((s8 *)(*(u8 **)((s8 *)(*(u8 * *)&TObjNpcConnoisseur__instance) + 0x42C)) + 0xC);
    ((TObjNpcBase *)this)->setup_common();
}

void *TObjNpcExpertBase__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcExpertBase(control, set_data);
}

