#include "pso/system/BmlResource.h"
#include "pso/system/BmlAccessors.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/object/trap/TOExplosiveMachine.h"
#include "pso/object/trap/TOExplosiveMachine01.h"
#include "pso/object/trap/TOExplosiveMachine02.h"
#include "pso/object/trap/TOExplosiveMachine03.h"
#include "pso/system/task/TMainTask.h"
#include "pso/network/TLobby.h"
#include "pso/object/TObjChip.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/PlayerCommands.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/MatrixStack.h"
#include "pso/math/MatrixReflect.h"
#include "pso/render/render_util.h"
#include "pso/player/PlayerSlots.h"

extern "C" {



#pragma push
#pragma readonly_strings on
const char *bm_o_explosive_machine_model_names[] = {
    "fs_obj_bapipe.gj", "fs_obj_bapipe_a.gj", "fs_obj_bapipe_b.gj",
    "fs_obj_baswitch.gj", "fs_obj_baswitch_a.gj", "fs_obj_baswitch_b.gj",
    "fs_obj_batank.gj", "fs_obj_batank_a.gj", "fs_obj_batank_b.gj", NULL
};
__declspec(section ".sdata") const char *bm_o_explosive_machine_motion_names[] = {NULL};
BmlResourceDescriptor explosive_machine_resource_desc = {
    "bm_o_explosive_machine.bml", bm_o_explosive_machine_model_names,
    bm_o_explosive_machine_motion_names, 9, 0
};
#pragma pop
__declspec(section ".rodata") const char explosive_machine_class_name_string[] = "TOExplosiveMachine";
__declspec(section ".rodata") const char explosive_machine01_class_name_string[] = "TOExplosiveMachine01";
__declspec(section ".rodata") const char explosive_machine02_class_name_string[] = "TOExplosiveMachine02";
__declspec(section ".rodata") const char explosive_machine03_class_name_string[] = "TOExplosiveMachine03";
const char *explosive_machine_class_name = explosive_machine_class_name_string;
const char *explosive_machine01_class_name = explosive_machine01_class_name_string;
const char *explosive_machine02_class_name = explosive_machine02_class_name_string;
const char *explosive_machine03_class_name = explosive_machine03_class_name_string;
BmlResource *explosive_machine_model_archive;

}

#pragma push
#pragma defer_codegen on

TOExplosiveMachine::TOExplosiveMachine() : TObjBase(tl_05) {
    m_name = explosive_machine_class_name;
    view_distance = 500.0f;
    view_radius = 0.0f;
    trigger_radius = 30.0f + scale.x;
    for (s32 i = 0; i < 2; i++) {
        debris_models[i] = NULL;
        debris_textures[i] = NULL;
    }
}

TOExplosiveMachine::~TOExplosiveMachine() {
    for (s32 i = 0; i < 2; i++) {
        debris_models[i] = NULL;
        debris_textures[i] = NULL;
    }
}

void TOExplosiveMachine::load_shared_resource() {
    BmlResource *resource = new BmlResource(1, &explosive_machine_resource_desc, 0, 0, NULL);
    explosive_machine_model_archive = resource;
}

void TOExplosiveMachine::destroy_static_lobby() {
    if (explosive_machine_model_archive != NULL) {
        delete explosive_machine_model_archive;
        explosive_machine_model_archive = NULL;
    }
}

void TOExplosiveMachine::render() {
    if (update_object_view_visibility(view_distance, view_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(0, rotation.y);
        set_texture_list(texlist);
        draw_ginja_object(model);
        pop_matrix();
    }
}

void TOExplosiveMachine::run_task() {
    for (s32 client = 0; client < TLobby::get_game_mode(); client++) {
        TObjPlayer *player = get_player_by_client_id(client);
        if (player != NULL && !player->test_actor_flags(0x800) &&
            horizontal_distance_squared(&player->position, &position) <= trigger_radius * trigger_radius) {
            const TObjChipParams first = {
                0.5f, 0.03f, 0.2f, {position.x, position.y, position.z}, {3, 5, 3},
                {0x800, 0x100, 0x800}, 7, 50, -100, 1,
                debris_models[0], debris_textures[0], 22
            };
            const TObjChipParams second = {
                0.5f, 0.03f, 0.2f, {position.x, position.y, position.z}, {3, 5, 3},
                {0x800, 0x100, 0x800}, 7, 50, -100, 1,
                debris_models[1], debris_textures[1], 22
            };
            spawn_particle_effect(&position, 0x45);
            spawn_particle_effect(&position, 0x46);
            new TObjChip(tl_05, &first);
            new TObjChip(tl_05, &second);
            queue_destruction();
            break;
        }
    }
}

TOExplosiveMachine01::TOExplosiveMachine01(ObjectSetData *set_data) {
    m_name = explosive_machine01_class_name;
    apply_object_set_data(set_data);
    model = get_bml_model(explosive_machine_model_archive, 0);
    texlist = get_bml_texlist(explosive_machine_model_archive, 0);
    view_radius = model->chunk_model->r;
    debris_models[0] = get_bml_model(explosive_machine_model_archive, 1);
    debris_textures[0] = get_bml_texlist(explosive_machine_model_archive, 1);
    debris_models[1] = get_bml_model(explosive_machine_model_archive, 2);
    debris_textures[1] = get_bml_texlist(explosive_machine_model_archive, 2);
}

TOExplosiveMachine01::~TOExplosiveMachine01() {}

void *TOExplosiveMachine01::create(ObjectSetData *set_data) {
    return new TOExplosiveMachine01(set_data);
}

TOExplosiveMachine02::TOExplosiveMachine02(ObjectSetData *set_data) {
    m_name = explosive_machine02_class_name;
    apply_object_set_data(set_data);
    model = get_bml_model(explosive_machine_model_archive, 3);
    texlist = get_bml_texlist(explosive_machine_model_archive, 3);
    view_radius = model->chunk_model->r;
    debris_models[0] = get_bml_model(explosive_machine_model_archive, 4);
    debris_textures[0] = get_bml_texlist(explosive_machine_model_archive, 4);
    debris_models[1] = get_bml_model(explosive_machine_model_archive, 5);
    debris_textures[1] = get_bml_texlist(explosive_machine_model_archive, 5);
}

TOExplosiveMachine02::~TOExplosiveMachine02() {}

void *TOExplosiveMachine02::create(ObjectSetData *set_data) {
    return new TOExplosiveMachine02(set_data);
}

TOExplosiveMachine03::TOExplosiveMachine03(ObjectSetData *set_data) {
    m_name = explosive_machine03_class_name;
    apply_object_set_data(set_data);
    model = get_bml_model(explosive_machine_model_archive, 6);
    texlist = get_bml_texlist(explosive_machine_model_archive, 6);
    view_radius = model->chunk_model->r;
    debris_models[0] = get_bml_model(explosive_machine_model_archive, 7);
    debris_textures[0] = get_bml_texlist(explosive_machine_model_archive, 7);
    debris_models[1] = get_bml_model(explosive_machine_model_archive, 8);
    debris_textures[1] = get_bml_texlist(explosive_machine_model_archive, 8);
}

TOExplosiveMachine03::~TOExplosiveMachine03() {}

void *TOExplosiveMachine03::create(ObjectSetData *set_data) {
    return new TOExplosiveMachine03(set_data);
}
#pragma pop
