#include "types.h"
#include "pso/object/cave/CaveSignRender.h"
#include <stdlib.h>
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/cave/TOSignCave02.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_803D8F74.h"

const char *bm_fs_obj_dokanban02_model_names[] = {"fs_obj_dokanban02.gj", NULL};
const char *bm_fs_obj_dokanban02_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_dokanban02_resource_descriptor = {
    "bm_fs_obj_dokanban02.bml", bm_fs_obj_dokanban02_model_names, bm_fs_obj_dokanban02_motion_names, 1, 0,
};
const char *TOSignCave02__class_name = "TOSignCave02";
BmlResource *TOSignCave02__bml_resource;

#ifdef __MWERKS__
#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
#endif
void TOSignCave02::render() {
    render_cave_sign(this);
}
#ifdef __MWERKS__
#pragma pop
#endif

void *TOSignCave02::create(void *set_data) {
    return new TOSignCave02(tl_05, set_data);
}

void TOSignCave02::release_static_resource() {
    if (TOSignCave02__bml_resource != NULL) {
        free_bin_model_request(TOSignCave02__bml_resource, 1);
        TOSignCave02__bml_resource = NULL;
    }
}

void TOSignCave02::load_shared_resource() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_dokanban02_resource_descriptor, 0, 0, 0);
    }
    TOSignCave02__bml_resource = resource;
}

TOSignCave02::~TOSignCave02() {}

TOSignCave02::TOSignCave02(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = TOSignCave02__class_name;
    apply_object_set_data(set_data);
    model = (void *)TOSignCave02__bml_resource->models[0].model;
    texlist = TOSignCave02__bml_resource->models[0].m_c;
    view_range = 500.0f;
    model_radius = 300.0f;
}
