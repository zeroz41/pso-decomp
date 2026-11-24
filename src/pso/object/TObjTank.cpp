#include "pso/system/memory.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/TObjTank.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

__declspec(section ".data") const char *fs_obj_tank_model_names[2] = { "fs_obj_tank.gj", NULL };
const char *fs_obj_tank_motion_names[1] = { NULL };
BmlResourceDescriptor fs_obj_tank_resource_descriptor = {
    "fs_obj_tank.bml", fs_obj_tank_model_names, fs_obj_tank_motion_names, 1, 0
};
const char *TObjTank__class_name = "TObjTank";

CollisionBody tobjtank_collision_body_parts = {{0.0f, 0.0f, 0.0f}, 20.0f, 10.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};

extern "C" {
BmlResource *tank_bml_resource;
NJS_TEXLIST *TObjTank__texture_list;
s32 init_collision_body_parts(void *, void *, int);
s32 free_collision_body_parts(void *);

void TObjTank::render() {
    NJS_TEXLIST *textures;
    if ((this->update_object_view_visibility(400.0f, 20.0f) != 0) && (textures = TObjTank__texture_list)) {
        TObjFish::set_global_param(textures);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_object(reinterpret_cast<NJS_OBJECT *>(get_bml_model((BmlResource *)tank_bml_resource, 0)));
        pop_matrix();
    }
}

void TObjTank::run_task() {  }

}
TObjTank::~TObjTank() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}


#define arg0 ((u8 *)this)
TObjTank::TObjTank(TObject *parent, saddr arg2) : TObjCollidable(parent) {
    *(saddr *)((s8 *)arg0 + 0) = (saddr) TObjTank__class_name;
    VecCopy((Vec *)(arg0 + 0x38), (const Vec *)(arg2 + 0xC));
    copy_xyz(arg0 + 0x5C, (void *)(arg2 + 0x18));
    VecCopy((Vec *)(arg0 + 0x68), (const Vec *)(arg2 + 0x24));
    init_collision_body_parts(arg0, &tobjtank_collision_body_parts, 1);
    ((TObjTank *)arg0)->actorFlags = (s32) (((TObjTank *)arg0)->actorFlags | 0x40000000);
    ((TObjPlayer *)arg0)->register_object_by_id();
}
#undef arg0

void *TObjTank::create(void *set_data) {
    return new TObjTank(tl_05, (saddr)set_data);
}

void TObjTank::free_globals() {
    if (TObjTank__texture_list != NULL) {
        release_texture_list(TObjTank__texture_list);
        safe_free(TObjTank__texture_list);
        TObjTank__texture_list = NULL;
    }
    if (tank_bml_resource != NULL) {
        delete (BmlResource *)tank_bml_resource;
        tank_bml_resource = NULL;
    }
}
void TObjTank::load_globals() {
    BmlResource *storage = new BmlResource(5, (BmlResourceDescriptor *)&fs_obj_tank_resource_descriptor, 0, 0, NULL);
    tank_bml_resource = storage;
    TObjTank__texture_list = load_gvm_texture_file("fs_obj_tank.GVM");
}

