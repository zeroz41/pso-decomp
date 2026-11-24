#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcKenkyu.h"
#include "pso/npc/TObjNpcSoutokufu.h"
#include "pso/npc/TObjNpcMale.h"

#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

#pragma readonly_strings on

void *TObjNpcKenkyu::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcKenkyu(control, set_data);
}

const char *bm_npc_kenkyu_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_npc_kenkyu_model_names[2] = { "kenkyu_body.nj", NULL };
BmlResourceDescriptor bm_npc_kenkyu_resource_descriptor = { "bm_npc_kenkyu.bml", bm_npc_kenkyu_model_names, bm_npc_kenkyu_motion_names, 1, 0 };
const char *TObjNpcKenkyu::name = "TObjNpcKenkyu";
BmlResource *TObjNpcKenkyu::static_model;
void TObjNpcKenkyu::free_static_model() {
    if (static_model != NULL) {
        delete static_model;
        static_model = NULL;
    }
}

void TObjNpcKenkyu::load_shared_resource() {
    static_model = new BmlResource(1, &bm_npc_kenkyu_resource_descriptor, 0, 0, NULL);
}

TObjNpcKenkyu::~TObjNpcKenkyu() {}

TObjNpcKenkyu::TObjNpcKenkyu(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    model = get_bml_model(static_model, 0);
    texlist = get_bml_texlist(static_model, 0);
    this->setup_common();
}

