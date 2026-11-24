#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/render/render_util.h"

#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TMotorcycle.h"
#include "pso/player/TObjPlayer_801542CC.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803D853C.h"
#include "pso/npc/TObjNpcEnemy.h"
#include "pso/render/NinjaUtil.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/system/task/TObject.h"
#include "pso/camera/TCameraCtrl.h"

extern const char *fe_obj_baiku_model_names[3];
extern BmlResourceDescriptor motorcycle_resource_descriptor;
extern const char *fe_obj_baiku_motion_names[1];


BmlResource *TMotorcycle__bml_resource;
NJS_TEXLIST *TMotorcycle__texture_list;
extern const s32 lbl_80445DF4[];
extern CollisionBody TMotorcycle__collision_parts[1];
extern const char *motorcycle_class_name;

__declspec(section ".data") const char *fe_obj_baiku_model_names[3] = { "fe_obj_baiku.gj", "fe_obj_baiku_jimen.gj", NULL };
BmlResourceDescriptor motorcycle_resource_descriptor = { "fe_obj_baiku.bml", fe_obj_baiku_model_names, fe_obj_baiku_motion_names, 2, 0 };
CollisionBody TMotorcycle__collision_parts[1] = {
    {{0.0f, 5.0f, 0.0f}, 24.0f, 7.0f, 1, 0x30003},
};
// model index picked by placement parity (TMotorcycle__ct; debug_draw_label prints it)
const s32 lbl_80445DF4[2] = { 1, 0 };
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
    m_bc = (s32)fabs_float(scale.x);
    m_bc = m_bc % 2;
    m_bc = lbl_80445DF4[m_bc];
    TObjNpcEnemy::set_global_count(0xFF00FF);
    debug_printf_at(0x13001C, "<- MODEL SELECT");
    TObjNpcEnemy::set_global_count(0xF0F0F0FF);
}

void TMotorcycle::render() {
    if ((TMainTask::get_render_pass() != 1) && (update_object_view_visibility(400.0f, 50.0f) != 0)) {
        set_draw_list_mask(3);
        if (TMotorcycle__texture_list != NULL) {
            TObjFish::set_global_param(TMotorcycle__texture_list);
            push_matrix();
            post_translate_matrix(&position.x);
            rotate_matrix_yxz(0, (this->rotation_x), (this->rotation_y), (this->rotation_z));
            draw_ginja_object(reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)TMotorcycle__bml_resource, m_bc)));
            pop_matrix();
        }
        restore_draw_list_mask();
    }
}

void TMotorcycle::vfunc_14() {  }


extern "C" void *create_stage_motorcycle(void *placement) {
    return new TMotorcycle(static_cast<TObject *>(tl_05), static_cast<ObjectSetData *>(placement));
}

void TMotorcycle::free_statics() {
    if (TMotorcycle__texture_list != NULL) {
        release_texture_list(TMotorcycle__texture_list);
        safe_free(TMotorcycle__texture_list);
        TMotorcycle__texture_list = NULL;
    }
    if (TMotorcycle__bml_resource != NULL) {
        delete (BmlResource *)TMotorcycle__bml_resource;
        TMotorcycle__bml_resource = NULL;
    }
}

void TMotorcycle::load_resources() {
    BmlResource *storage = new BmlResource(5, (BmlResourceDescriptor *)&motorcycle_resource_descriptor, 0, 0, NULL);
    TMotorcycle__bml_resource = storage;
    TMotorcycle__texture_list = load_gvm_texture_file("obj_motorcycle.GVM");
    TObjNpcEnemy::register_ginja(0x3C, reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)TMotorcycle__bml_resource, 0)),
                           TMotorcycle__texture_list, 16.0f, 0.0f);
    TObjNpcEnemy::register_ginja(0x3D, reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)TMotorcycle__bml_resource, 1)),
                           TMotorcycle__texture_list, 16.0f, 0.0f);
}

TMotorcycle::~TMotorcycle() {
    unregister_object_by_id();
    free_collision_body_parts(this);
}
TMotorcycle::TMotorcycle(TObject *parent, ObjectSetData *placement) : TObjMesBase(parent, placement) {
    m_name = motorcycle_class_name;
    m_bc = (s32)fabs_float(scale.x);
    m_bc = m_bc % 2;
    m_bc = lbl_80445DF4[m_bc];
    init_collision_body_parts(this, TMotorcycle__collision_parts, 1);
    actorFlags |= 0x40000000;
    register_object_by_id();
}
