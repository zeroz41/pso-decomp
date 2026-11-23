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
BmlResource *TObjNpcConnoisseur__instance;

void TObjNpcConnoisseur::destroy_instance() {
    if (TObjNpcConnoisseur__instance != NULL) {
        delete TObjNpcConnoisseur__instance;
        TObjNpcConnoisseur__instance = NULL;
    }
}

void TObjNpcConnoisseur::load_section_motion() {
    lbl_805D5748 = leader_selection.get_section_id();
    TObjNpcConnoisseur__instance = new BmlResource(1, (BmlResourceDescriptor *)tekker_descriptor_selector_table[lbl_805D5748], 0, 0, NULL);
}

TObjNpcConnoisseur::~TObjNpcConnoisseur() {}


TObjNpcConnoisseur::TObjNpcConnoisseur(TObject *parent, void *arg2) : TUnk_804A9F50(parent) {
    ((TObjNpcConnoisseur *)this)->m_name = TObjNpcConnoisseur__name;
    ((TObjNpcConnoisseur *)this)->apply_set_data(arg2);
    init_position_vectors();
    model = TObjNpcConnoisseur__instance->models->model;
    texlist = TObjNpcConnoisseur__instance->models->texlist;
    ((TObjNpcBase *)this)->setup_common();
}

void *TObjNpcExpertBase__create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcExpertBase(control, set_data);
}

