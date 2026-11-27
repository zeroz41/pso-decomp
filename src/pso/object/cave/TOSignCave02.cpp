#include "types.h"
#include "pso/object/cave/CaveSignRender.h"
#include <stdlib.h>
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/object/cave/TOSignCave02.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/math/MatrixReflect.h"

const char *bm_fs_obj_dokanban02_model_names[] = {"fs_obj_dokanban02.gj", NULL};
const char *bm_fs_obj_dokanban02_motion_names[] = {NULL};
BmlResourceDescriptor bm_fs_obj_dokanban02_resource_descriptor = {
    "bm_fs_obj_dokanban02.bml", bm_fs_obj_dokanban02_model_names, bm_fs_obj_dokanban02_motion_names, 1, 0,
};
const char *sign_cave02_class_name = "TOSignCave02";
BmlResource *sign_cave02_bml_resource;

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

void *TOSignCave02::create(ObjectSetData *set_data) {
    return new TOSignCave02(tl_05, set_data);
}

void TOSignCave02::release_static_resource() {
    if (sign_cave02_bml_resource != NULL) {
        delete sign_cave02_bml_resource;
        sign_cave02_bml_resource = NULL;
    }
}

void TOSignCave02::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &bm_fs_obj_dokanban02_resource_descriptor, 0, 0, NULL);
    sign_cave02_bml_resource = resource;
}

TOSignCave02::~TOSignCave02() {}

TOSignCave02::TOSignCave02(TObject *parent, ObjectSetData *set_data) : TObjMapObject(parent) {
    m_name = sign_cave02_class_name;
    apply_object_set_data(set_data);
    model = sign_cave02_bml_resource->models[0].model;
    texlist = sign_cave02_bml_resource->models[0].texlist;
    view_range = 500.0f;
    model_radius = 300.0f;
}
