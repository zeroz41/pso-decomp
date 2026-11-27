#include "pso/system/memory.h"
#include "pso/object/base/TObjCollidable.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/TObjTank.h"
#include "pso/render/psoLoadTexture.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixStack.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/vector.h"
#include "pso/object/base/TObjMotion.h"

#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/math/MatrixReflect.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/object/base/ActorCollision.h"

__declspec(section ".data") const char *fs_obj_tank_model_names[2] = { "fs_obj_tank.gj", NULL };
const char *fs_obj_tank_motion_names[1] = { NULL };
BmlResourceDescriptor fs_obj_tank_resource_descriptor = {
    "fs_obj_tank.bml", fs_obj_tank_model_names, fs_obj_tank_motion_names, 1, 0
};
const char *tank_class_name = "TObjTank";

CollisionBody tobjtank_collision_body_parts = {{0.0f, 0.0f, 0.0f}, 20.0f, 10.0f, 0, 0x10003, {0.0f, 0.0f, 0.0f}, 0.0f};

BmlResource *tank_bml_resource;
NJS_TEXLIST *tank_texture_list;

void TObjTank::render() {
    NJS_TEXLIST *textures;
    if ((this->update_object_view_visibility(400.0f, 20.0f) != 0) && (textures = tank_texture_list)) {
        set_texture_list(textures);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, this->rotation_y);
        draw_ginja_object(get_bml_model(tank_bml_resource, 0));
        pop_matrix();
    }
}

void TObjTank::run_task() {  }
TObjTank::~TObjTank() {
    this->unregister_object_by_id();
    free_collision_body_parts(this);
}


TObjTank::TObjTank(TObject *parent, ObjectSetData *placement) : TObjCollidable(parent) {
    m_name = tank_class_name;
    VecCopy(&position, &placement->position);
    copy_xyz(&rotation_x, placement->rotation);
    VecCopy(&scale, &placement->scale);
    init_collision_body_parts(this, &tobjtank_collision_body_parts, 1);
    actorFlags |= 0x40000000;
    register_object_by_id();
}

void *TObjTank::create(void *set_data) {
    return new TObjTank(tl_05, static_cast<ObjectSetData *>(set_data));
}

void TObjTank::free_globals() {
    if (tank_texture_list != NULL) {
        release_texture_list(tank_texture_list);
        safe_free(tank_texture_list);
        tank_texture_list = NULL;
    }
    if (tank_bml_resource != NULL) {
        delete tank_bml_resource;
        tank_bml_resource = NULL;
    }
}
void TObjTank::load_globals() {
    BmlResource *storage = new BmlResource(5, &fs_obj_tank_resource_descriptor, 0, 0, NULL);
    tank_bml_resource = storage;
    tank_texture_list = LoadPvmFileTls("fs_obj_tank.GVM");
}

