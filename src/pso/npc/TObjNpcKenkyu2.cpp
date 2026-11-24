#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/TObjControl.h"
#include "pso/npc/TObjNpcKenkyu2.h"
#include "pso/npc/TObjNpcHosa2.h"
#include "pso/npc/TObjNpcMale.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#pragma readonly_strings on

void *TObjNpcKenkyu2::create(void *set_data) {
    TObjControl *control = new TObjControl(tl_04);
    return new TObjNpcKenkyu2(control, set_data);
}

extern const char *bm_npc_kenkyu2_motion_names[1];

void TObjNpcKenkyu2::free_static_model() {
    if (shared_model_resource != NULL) {
        delete shared_model_resource;
        shared_model_resource = NULL;
    }
}

void TObjNpcKenkyu2::load_shared_resource() {
    shared_model_resource = new BmlResource(1, &resource_descriptor, 0, 0, NULL);
}

TObjNpcKenkyu2::~TObjNpcKenkyu2() {}

TObjNpcKenkyu2::TObjNpcKenkyu2(TObject *parent, void *set_data) : TObjNpcMale(parent) {
    this->m_name = name;
    this->apply_set_data(set_data);
    init_position_vectors();
    model = get_bml_model(shared_model_resource, 0);
    texlist = get_bml_texlist(shared_model_resource, 0);
    this->setup_common();
}

__declspec(section ".data") const char *bm_npc_kenkyu2_model_names[2] = { "kenkyu2_body.nj", NULL };
BmlResourceDescriptor TObjNpcKenkyu2::resource_descriptor = { "bm_npc_kenkyu2.bml", bm_npc_kenkyu2_model_names, bm_npc_kenkyu2_motion_names, 1, 0 };
__declspec(section ".sdata") const char *bm_npc_kenkyu2_motion_names[1] = { NULL };

const char *TObjNpcKenkyu2::name = "TObjNpcKenkyu2";
BmlResource *TObjNpcKenkyu2::shared_model_resource;
