#include "types.h"
#include "pso/object/cave/CaveSignRender.h"
#include <stdlib.h>
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/cave/TOSignCave01.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/math/MatrixReflect.h"

const char *bm_fs_obj_dokanban01_model_names[] = {"fs_obj_dokanban01.gj", NULL};
const char *bm_fs_obj_dokanban01_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_dokanban01_resource_descriptor = {
    "bm_fs_obj_dokanban01.bml", bm_fs_obj_dokanban01_model_names, bm_fs_obj_dokanban01_motion_names, 1, 0,
};
const char *sign_cave01_class_name = "TOSignCave01";
BmlResource *sign_cave01_bml_resource;

#ifdef __MWERKS__
#pragma push
#pragma dont_inline off
#pragma inline_depth(1)
#endif
void TOSignCave01::render() {
    render_cave_sign(this);
}
#ifdef __MWERKS__
#pragma pop
#endif

void *TOSignCave01::create(void *set_data) {
    return new TOSignCave01(tl_05, set_data);
}

void TOSignCave01::release_static_resource() {
    if (sign_cave01_bml_resource != NULL) {
        delete sign_cave01_bml_resource;
        sign_cave01_bml_resource = NULL;
    }
}

void TOSignCave01::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &bm_fs_obj_dokanban01_resource_descriptor, 0, 0, NULL);
    sign_cave01_bml_resource = resource;
}

TOSignCave01::~TOSignCave01() {}

TOSignCave01::TOSignCave01(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = sign_cave01_class_name;
    apply_object_set_data(set_data);
    model = sign_cave01_bml_resource->models[0].model;
    texlist = sign_cave01_bml_resource->models[0].texlist;
    view_range = 500.0f;
    model_radius = 100.0f;
}
