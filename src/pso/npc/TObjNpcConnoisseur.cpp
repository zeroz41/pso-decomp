#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcConnoisseur.h"
#include "pso/npc/TObjNpcExpertBase.h"
#include "pso/npc/TObjNpcMale.h"

#include "pso/ui/font/TFontSmallTask.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/BmlResource.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

void *TObjNpcConnoisseur::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcConnoisseur(control, set_data);
}

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
const char *TObjNpcConnoisseur::name = "TObjNpcConnoisseur";

s32 TObjNpcConnoisseur::section_id;
BmlResource *TObjNpcConnoisseur::instance;

void TObjNpcConnoisseur::destroy_instance() {
    if (instance != NULL) {
        delete instance;
        instance = NULL;
    }
}

void TObjNpcConnoisseur::load_section_motion() {
    section_id = leader_selection.get_section_id();
    instance = new BmlResource(1, (BmlResourceDescriptor *)tekker_descriptor_selector_table[section_id], 0, 0, NULL);
}

TObjNpcConnoisseur::~TObjNpcConnoisseur() {}

TObjNpcConnoisseur::TObjNpcConnoisseur(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    model = instance->models->model;
    texlist = instance->models->texlist;
    this->setup_common();
}

