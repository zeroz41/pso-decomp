#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/render_util.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TMotorcycle.h"
#include "pso/object/base/ActorCollision.h"
#include "pso/unk/text_803DA798.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/render/DebugFont.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"

extern const char *fe_obj_baiku_model_names[3];
extern BmlResourceDescriptor motorcycle_resource_descriptor;
extern const char *fe_obj_baiku_motion_names[1];


BmlResource *motorcycle_bml_resource;
NJS_TEXLIST *motorcycle_texture_list;
extern const s32 motorcycle_model_ids[];
extern CollisionBody motorcycle_collision_parts[1];
extern const char *motorcycle_class_name;

__declspec(section ".data") const char *fe_obj_baiku_model_names[3] = { "fe_obj_baiku.gj", "fe_obj_baiku_jimen.gj", NULL };
BmlResourceDescriptor motorcycle_resource_descriptor = { "fe_obj_baiku.bml", fe_obj_baiku_model_names, fe_obj_baiku_motion_names, 2, 0 };
CollisionBody motorcycle_collision_parts[1] = {
    {{0.0f, 5.0f, 0.0f}, 24.0f, 7.0f, 1, 0x30003},
};
// model index picked by placement parity (TMotorcycle__ct; debug_draw_label prints it)
const s32 motorcycle_model_ids[2] = { 1, 0 };
__declspec(section ".sdata") const char *fe_obj_baiku_motion_names[1] = { NULL };
const char *motorcycle_class_name = "TMotorcycle";



// The override of TObjBase::update_object_view_visibility (vtable slot +0x28): visible inside `radius` of the camera.
s32 TMotorcycle::update_object_view_visibility(f32 depth, f32 radius) {
    if (xz_distance_squared(&camera_ctrl_instance->pos, &position) < (radius * radius)) {
        return 1;
    }
    return TObjBase::update_object_view_visibility(depth, radius);
}

void TMotorcycle::debug_draw_label() {
    TObjMesBase::debug_draw_label();
    model_index = (s32)fabs_float(scale.x);
    model_index = model_index % 2;
    model_index = motorcycle_model_ids[model_index];
    set_debug_text_color(0xFF00FF);
    debug_printf_at(0x13001C, "<- MODEL SELECT");
    set_debug_text_color(0xF0F0F0FF);
}

void TMotorcycle::render() {
    if ((TMainTask::get_render_pass() != 1) && (update_object_view_visibility(400.0f, 50.0f) != 0)) {
        set_draw_list_mask(3);
        if (motorcycle_texture_list != NULL) {
            set_texture_list(motorcycle_texture_list);
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_yxz(0, (this->rotation_x), (this->rotation_y), (this->rotation_z));
            draw_ginja_object(reinterpret_cast<NJS_OBJECT *>(get_bml_model(motorcycle_bml_resource, model_index)));
            pop_matrix();
        }
        restore_draw_list_mask();
    }
}

void TMotorcycle::update_idle() {  }


void *create_stage_motorcycle(void *placement) {
    return new TMotorcycle(static_cast<TObject *>(tl_05), static_cast<ObjectSetData *>(placement));
}

void TMotorcycle::free_statics() {
    if (motorcycle_texture_list != NULL) {
        release_texture_list(motorcycle_texture_list);
        safe_free(motorcycle_texture_list);
        motorcycle_texture_list = NULL;
    }
    if (motorcycle_bml_resource != NULL) {
        delete motorcycle_bml_resource;
        motorcycle_bml_resource = NULL;
    }
}

void TMotorcycle::load_resources() {
    BmlResource *storage = new BmlResource(5, &motorcycle_resource_descriptor, 0, 0, NULL);
    motorcycle_bml_resource = storage;
    motorcycle_texture_list = LoadPvmFileTls("obj_motorcycle.GVM");
    TObjNpcEnemy::register_ginja(0x3C, reinterpret_cast<NJS_OBJECT *>(get_bml_model(motorcycle_bml_resource, 0)),
                           motorcycle_texture_list, 16.0f, 0.0f);
    TObjNpcEnemy::register_ginja(0x3D, reinterpret_cast<NJS_OBJECT *>(get_bml_model(motorcycle_bml_resource, 1)),
                           motorcycle_texture_list, 16.0f, 0.0f);
}

TMotorcycle::~TMotorcycle() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}
TMotorcycle::TMotorcycle(TObject *parent, ObjectSetData *placement) : TObjMesBase(parent, placement) {
    m_name = motorcycle_class_name;
    model_index = (s32)fabs_float(scale.x);
    model_index = model_index % 2;
    model_index = motorcycle_model_ids[model_index];
    init_collision_body_parts(this, motorcycle_collision_parts, 1);
    actorFlags |= 0x40000000;
    register_object_by_id();
}
