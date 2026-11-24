#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/npc/TUnk_804A9F50.h"
#include "pso/npc/TObjNpcKenkyuW.h"
#include "pso/system/vector.h"
#include "pso/player/TObjPlayer.h"

#include "pso/unk/TLobby.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/npc/TObjNpcLappy.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/system/BmlResourceDescriptor.h"
#include "pso/math/MatrixVector.h"
#include "pso/object/base/CollisionActorLookup.h"
#include "pso/object/base/TObjBase.h"

#pragma readonly_strings on

__declspec(section ".data") const char *bm_npc_kenkyu_w_model_names[2] = {"kenkyu_w_hone_body.nj", NULL};
const char *bm_npc_kenkyu_w_motion_names[] = {NULL};
BmlResourceDescriptor bm_npc_kenkyu_w_resource_descriptor = {
    "bm_npc_kenkyu_w.bml", bm_npc_kenkyu_w_model_names, bm_npc_kenkyu_w_motion_names, 1, 0,
};
const char *TObjNpcKenkyuW::class_name = "TObjNpcKenkyuW";
BmlResource *TObjNpcKenkyuW::model_resource;

void TObjNpcKenkyuW::destroy_instance() {
    if (model_resource != NULL) {
        delete model_resource;
        model_resource = NULL;
    }
}

void TObjNpcKenkyuW::load_resource_instance() {
    model_resource = new BmlResource(1, &bm_npc_kenkyu_w_resource_descriptor, 0, 0, NULL);
}

TObjNpcKenkyuW::~TObjNpcKenkyuW() {}

TObjNpcKenkyuW::TObjNpcKenkyuW(TObject *parent, void *set_data) : TUnk_804A9F50(parent) {
    m_name = class_name;
    apply_set_data(set_data);
    init_position_vectors();
    model = get_bml_model(model_resource, 0);
    texlist = get_bml_texlist(model_resource, 0);
    setup_common();
}
