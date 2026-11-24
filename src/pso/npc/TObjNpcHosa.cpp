#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcHosa.h"
#include "pso/npc/TObjNpcKenkyuW.h"
#include "pso/npc/TObjNpcMale.h"

#include "pso/system/BmlResourceDescriptor.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

void *TObjNpcHosa::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcHosa(control, set_data);
}

extern const char *bm_npc_hosa_motion_names[1];
__declspec(section ".data") const char *bm_npc_hosa_model_names[2] = { "hosa_hone_body.nj", NULL };
BmlResourceDescriptor npc_hosa_resource_descriptor = { "bm_npc_hosa.bml", bm_npc_hosa_model_names, bm_npc_hosa_motion_names, 1, 0 };

const char *bm_npc_hosa_motion_names[1] = { NULL };
const char *TObjNpcHosa::name = "TObjNpcHosa";
BmlResource *TObjNpcHosa::static_model_resource;

void TObjNpcHosa::destroy_static_instance() {
    if (static_model_resource != NULL) {
        delete static_model_resource;
        static_model_resource = NULL;
    }
}

void TObjNpcHosa::load_static_resource() {
    static_model_resource = new BmlResource(1, &npc_hosa_resource_descriptor, 0, 0, NULL);
}

TObjNpcHosa::~TObjNpcHosa() {}

TObjNpcHosa::TObjNpcHosa(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    model = get_bml_model(static_model_resource, 0);
    texlist = get_bml_texlist(static_model_resource, 0);
    this->setup_common();
}

