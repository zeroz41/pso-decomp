#include "pso/system/BmlResource.h"
#include "pso/object/TObjControl.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/npc/TObjNpcHosa2.h"
#include "pso/npc/TObjNpcMale.h"

#include "pso/system/BmlResourceDescriptor.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on

void *TObjNpcHosa2::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHosa2(control, set_data);
}

extern const char *bm_npc_hosa2_motion_names[1];
__declspec(section ".data") const char *bm_npc_hosa2_model_names[2] = { "hosa_hone2_body.nj", NULL };
BmlResourceDescriptor npc_hosa2_resource_descriptor = { "bm_npc_hosa2.bml", bm_npc_hosa2_model_names, bm_npc_hosa2_motion_names, 1, 0 };

const char *bm_npc_hosa2_motion_names[1] = { NULL };
const char *TObjNpcHosa2::name = "TObjNpcHosa2";
BmlResource *TObjNpcHosa2::shared_model_resource;

void TObjNpcHosa2::close_dialog_window() {
    if (shared_model_resource != NULL) {
        delete shared_model_resource;
        shared_model_resource = NULL;
    }
}

void TObjNpcHosa2::load_shared_resource() {
    shared_model_resource = new BmlResource(1, &npc_hosa2_resource_descriptor, 0, 0, NULL);
}

TObjNpcHosa2::~TObjNpcHosa2() {}

TObjNpcHosa2::TObjNpcHosa2(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    model = get_bml_model(shared_model_resource, 0);
    texlist = get_bml_texlist(shared_model_resource, 0);
    this->setup_common();
}

