#include "pso/system/BmlAccessors.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/object/TObjBigTuitate.h"
#include "pso/object/TObjTuitate.h"
#include "pso/render/render_util.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/render/TextureState.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"

#include "pso/render/RenderFadeState.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/object/base/ObjectSetData.h"
#include "pso/map/TObjMapCsn.h"
#include "pso/render/DebugFont.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#include "pso/math/MatrixReflect.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/hud/SplitScreenQuery.h"


BmlResource *TObjTuitate::bml_resource;
BmlResource *TObjBigTuitate::bml_resource;

__declspec(section ".data") const char *fe_obj_tutate_model_names[2] = { "fe_obj_tutate.gj", NULL };
const char *fe_obj_tutate_motion_names[1] = { NULL };
BmlResourceDescriptor fe_obj_tutate_resource_descriptor = {
    "fe_obj_tutate.bml", fe_obj_tutate_model_names, fe_obj_tutate_motion_names, 1, 0
};
__declspec(section ".data") const char *fe_obj_bigtutate_model_names[2] = { "fe_obj_bigtutate.gj", NULL };
const char *fe_obj_bigtutate_motion_names[1] = { NULL };
BmlResourceDescriptor fe_obj_bigtutate_resource_descriptor = {
    "fe_obj_bigtutate.bml", fe_obj_bigtutate_model_names, fe_obj_bigtutate_motion_names, 1, 0
};
CollisionBody TObjTuitate::collision_parts[1] = {
    {{0.0f, 0.0f, 0.0f}, 6.0f, 16.0f, 1, 0x10003},
};
CollisionBody TObjBigTuitate::collision_parts[1] = {
    {{0.0f, 0.0f, 0.0f}, 6.0f, 16.0f, 1, 0x10003},
};
const char *TObjTuitate::class_name = "TObjTuitate";
const char *TObjBigTuitate::class_name = "TObjBigTuitate";

void TObjTuitate::load_resources() {
    BmlResource *storage = new BmlResource(1, &fe_obj_tutate_resource_descriptor, 0, 0, NULL);
    bml_resource = storage;
}

void TObjTuitate::free_resources() {
    if (bml_resource != NULL) {
        delete bml_resource;
        bml_resource = NULL;
    }
}

void *TObjTuitate::create(ObjectSetData *set_data) {
    return new TObjTuitate(tl_05, set_data);
}

TObjTuitate::TObjTuitate(TObject *parent, ObjectSetData *set_data) : TObjCollidable(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, collision_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    ObjectSetData csn_data = *set_data;
    csn_data.scale.x = 32.0f;
    csn_data.scale.y = 20.0f;
    csn_data.scale.z = 12.0f;
    map_csn = TObjMapCsn::create(&csn_data);
    fade.activate_and_dispatch();
}

TObjTuitate::~TObjTuitate() {
    if (map_csn != NULL) {
        map_csn->queue_destruction();
        map_csn = NULL;
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjTuitate::run_task() { fade.update(); }

void TObjTuitate::render() {
    Vec v;
    s32 fading;
    if (update_object_view_visibility(400.0f, 20.0f) == 0) {
        return;
    }
    matrix_mult_vec(NULL, &position, &v);
    if (v.z > (-38.0f)) {
        fade.fadeOut();
    } else {
        fade.restore();
    }
    set_cull_back();
    if (is_not_split_screen() == 1) {
        fading = 0;
    } else {
        fading = fade.isFading();
    }
    if (fading != 0) {
        fade.set_flags_and_apply_damage_color();
    }
    set_texture_list(get_bml_texlist(bml_resource, 0));
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation.y);
    draw_ginja_object(get_bml_model(bml_resource, 0));
    pop_matrix();
    if (fading != 0) {
        fade.clear_flag_and_notify();
    }
    set_cull_none();
}

void TObjBigTuitate::load_resources() {
    BmlResource *storage = new BmlResource(1, &fe_obj_bigtutate_resource_descriptor, 0, 0, NULL);
    bml_resource = storage;
}

void TObjBigTuitate::free_instance() {
    if (bml_resource != NULL) {
        delete bml_resource;
        bml_resource = NULL;
    }
}

void *TObjBigTuitate::create(ObjectSetData *set_data) {
    return new TObjBigTuitate(tl_05, set_data);
}

TObjBigTuitate::TObjBigTuitate(TObject *parent, ObjectSetData *set_data) : TObjCollidable(parent) {
    m_name = class_name;
    apply_object_set_data(set_data);
    init_collision_body_parts(this, collision_parts, 1);
    refresh_collision_body_centers();
    register_object_by_id();
    ObjectSetData csn_data = *set_data;
    csn_data.scale.x = 32.0f;
    csn_data.scale.y = 40.0f;
    csn_data.scale.z = 12.0f;
    map_csn = TObjMapCsn::create(&csn_data);
    fade.activate_and_dispatch();
}

TObjBigTuitate::~TObjBigTuitate() {
    if (map_csn != NULL) {
        map_csn->queue_destruction();
        map_csn = NULL;
    }
    unregister_object_by_id();
    free_collision_body_parts(this);
}

void TObjBigTuitate::run_task() { fade.update(); }

void TObjBigTuitate::render() {
    Vec v;
    s32 fading;
    if (update_object_view_visibility(400.0f, 20.0f) == 0) {
        return;
    }
    matrix_mult_vec(NULL, &position, &v);
    if (-v.z < 38.0f) {
        fade.fadeOut();
    } else {
        fade.restore();
    }
    set_cull_back();
    if (is_not_split_screen() == 1) {
        fading = 0;
    } else {
        fading = fade.isFading();
    }
    if (fading != 0) {
        fade.set_flags_and_apply_damage_color();
    }
    set_texture_list(get_bml_texlist(bml_resource, 0));
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation.y);
    draw_ginja_object(get_bml_model(bml_resource, 0));
    pop_matrix();
    if (fading != 0) {
        fade.clear_flag_and_notify();
    }
    set_cull_none();
}
