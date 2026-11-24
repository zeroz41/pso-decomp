#include "pso/system/BmlResource.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/npc/TObjNpcSoutokufu.h"
#include "pso/npc/TObjNpcMale.h"

#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"

#pragma readonly_strings on

void *TObjNpcSoutokufu::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcSoutokufu(control, set_data);
}

const char *bm_npc_soutokufu_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_npc_soutokufu_model_names[2] = { "soutokufu_body.nj", NULL };
BmlResourceDescriptor bm_npc_soutokufu_resource_descriptor = { "bm_npc_soutokufu.bml", bm_npc_soutokufu_model_names, bm_npc_soutokufu_motion_names, 1, 0 };
const char *TObjNpcSoutokufu::name = "TObjNpcSoutokufu";
BmlResource *TObjNpcSoutokufu::shared_model_resource;

void TObjNpcSoutokufu::close_dialog_window() {
    if (shared_model_resource != NULL) {
        delete shared_model_resource;
        shared_model_resource = NULL;
    }
}

void TObjNpcSoutokufu::load_shared_resource() {
    shared_model_resource = new BmlResource(1, &bm_npc_soutokufu_resource_descriptor, 0, 0, NULL);
}

TObjNpcSoutokufu::~TObjNpcSoutokufu() {}

TObjNpcSoutokufu::TObjNpcSoutokufu(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    model = get_bml_model(shared_model_resource, 0);
    texlist = get_bml_texlist(shared_model_resource, 0);
    this->setup_common();
}
