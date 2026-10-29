#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/misc/TOExplosiveMachine.h"
#include "pso/misc/TOExplosiveMachine01.h"
#include "pso/misc/TOExplosiveMachine02.h"
#include "pso/misc/TOExplosiveMachine03.h"
#include "pso/TMainTask.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjChip.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/NinjaTypes.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D96A8.h"

extern "C" {
void *load_resource_from_descriptor(void *, s32, BmlResourceDescriptor *, s32, s32, s32);
void TLobby__sub_8001FE7C(void *, s32);
f32 horizontal_distance_squared(const Vec *, const Vec *);
s32 post_translate_matrix(const Vec *);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();

void *get_bml_model(void *, s32);
s32 TObjFish__sub_8001EDB0(void *, s32);

__declspec(section ".rodata") const char lbl_80441268[] = "fs_obj_bapipe.gj";
__declspec(section ".rodata") const char lbl_8044127C[] = "fs_obj_bapipe_a.gj";
__declspec(section ".rodata") const char lbl_80441290[] = "fs_obj_bapipe_b.gj";
__declspec(section ".rodata") const char lbl_804412A4[] = "fs_obj_baswitch.gj";
__declspec(section ".rodata") const char lbl_804412B8[] = "fs_obj_baswitch_a.gj";
__declspec(section ".rodata") const char lbl_804412D0[] = "fs_obj_baswitch_b.gj";
__declspec(section ".rodata") const char lbl_804412E8[] = "fs_obj_batank.gj";
__declspec(section ".rodata") const char lbl_804412FC[] = "fs_obj_batank_a.gj";
__declspec(section ".rodata") const char lbl_80441310[] = "fs_obj_batank_b.gj";
__declspec(section ".rodata") const char lbl_80441324[] = "bm_o_explosive_machine.bml";
__declspec(section ".rodata") const char lbl_80441340[] = "TOExplosiveMachine";
__declspec(section ".rodata") const char lbl_80441354[] = "TOExplosiveMachine01";
__declspec(section ".rodata") const char lbl_8044136C[] = "TOExplosiveMachine02";
__declspec(section ".rodata") const char lbl_80441384[] = "TOExplosiveMachine03";

const char *bm_o_explosive_machine_model_names[] = {
    lbl_80441268, lbl_8044127C, lbl_80441290,
    lbl_804412A4, lbl_804412B8, lbl_804412D0,
    lbl_804412E8, lbl_804412FC, lbl_80441310, NULL
};
__declspec(section ".sdata") const char *bm_o_explosive_machine_motion_names[] = {NULL};
BmlResourceDescriptor explosive_machine_resource_desc = {
    lbl_80441324, bm_o_explosive_machine_model_names,
    bm_o_explosive_machine_motion_names, 9, 0
};
const char *TOExplosiveMachine__class_name = lbl_80441340;
const char *TOExplosiveMachine01__class_name = lbl_80441354;
const char *TOExplosiveMachine02__class_name = lbl_8044136C;
const char *TOExplosiveMachine03__class_name = lbl_80441384;
void *explosive_machine_model_archive;

}

#pragma push
#pragma defer_codegen on

TOExplosiveMachine::TOExplosiveMachine() : TObjBase(tl_05) {
    m_name = TOExplosiveMachine__class_name;
    view_distance = 500.0f;
    view_radius = 0.0f;
    trigger_radius = 30.0f + scale.x;
    for (s32 i = 0; i < 2; i++) {
        debris_models[i] = NULL;
        debris_textures[i] = 0;
    }
}

TOExplosiveMachine::~TOExplosiveMachine() {
    for (s32 i = 0; i < 2; i++) {
        debris_models[i] = NULL;
        debris_textures[i] = 0;
    }
}

void TOExplosiveMachine::load_shared_resource() {
    void *resource = ::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &explosive_machine_resource_desc, 0, 0, 0);
    }
    explosive_machine_model_archive = resource;
}

void TOExplosiveMachine::destroy_static_lobby() {
    if (explosive_machine_model_archive != NULL) {
        TLobby__sub_8001FE7C(explosive_machine_model_archive, 1);
        explosive_machine_model_archive = NULL;
    }
}

void TOExplosiveMachine::render() {
    if (update_object_view_visibility(view_distance, view_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position);
        rotate_matrix_y(0, rotation_y);
        TObjFish::set_global_param(texlist);
        draw_ginja_object(model);
        pop_matrix();
    }
}

void TOExplosiveMachine::run_task() {
    for (s32 client = 0; client < TLobby::get_game_mode(); client++) {
        TObjPlayer *player = get_player_by_client_id(client);
        if (player != NULL && !player->obj_testFlags30(0x800) &&
            horizontal_distance_squared(&player->position, &position) <= trigger_radius * trigger_radius) {
            const TObjChipParams first = {
                {0.5f, 0.03f, 0.2f}, {position.x, position.y, position.z}, {3, 5, 3},
                {0x800, 0x100, 0x800}, {7, 50}, {-100, 1},
                (s32)debris_models[0], debris_textures[0], 22
            };
            const TObjChipParams second = {
                {0.5f, 0.03f, 0.2f}, {position.x, position.y, position.z}, {3, 5, 3},
                {0x800, 0x100, 0x800}, {7, 50}, {-100, 1},
                (s32)debris_models[1], debris_textures[1], 22
            };
            spawn_particle_effect(&position, 0x45);
            spawn_particle_effect(&position, 0x46);
            void *chip = TObject::operator new(0x234);
            if (chip != NULL) {
                __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)chip, (u8 *)tl_05, (u8 *)&first);
            }
            chip = TObject::operator new(0x234);
            if (chip != NULL) {
                __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)chip, (u8 *)tl_05, (u8 *)&second);
            }
            queue_destruction();
            break;
        }
    }
}

TOExplosiveMachine01::TOExplosiveMachine01(void *set_data) {
    m_name = TOExplosiveMachine01__class_name;
    apply_object_set_data(set_data);
    model = get_bml_model(explosive_machine_model_archive, 0);
    texlist = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 0);
    view_radius = ((ExplosiveMachineModel *)((NJS_OBJECT *)model)->model)->radius;
    debris_models[0] = get_bml_model(explosive_machine_model_archive, 1);
    debris_textures[0] = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 1);
    debris_models[1] = get_bml_model(explosive_machine_model_archive, 2);
    debris_textures[1] = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 2);
}

TOExplosiveMachine01::~TOExplosiveMachine01() {}

extern "C" void *TOExplosiveMachine01__create(void *set_data) {
    return new TOExplosiveMachine01(set_data);
}

TOExplosiveMachine02::TOExplosiveMachine02(void *set_data) {
    m_name = TOExplosiveMachine02__class_name;
    apply_object_set_data(set_data);
    model = get_bml_model(explosive_machine_model_archive, 3);
    texlist = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 3);
    view_radius = ((ExplosiveMachineModel *)((NJS_OBJECT *)model)->model)->radius;
    debris_models[0] = get_bml_model(explosive_machine_model_archive, 4);
    debris_textures[0] = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 4);
    debris_models[1] = get_bml_model(explosive_machine_model_archive, 5);
    debris_textures[1] = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 5);
}

TOExplosiveMachine02::~TOExplosiveMachine02() {}

extern "C" void *TOExplosiveMachine02__create(void *set_data) {
    return new TOExplosiveMachine02(set_data);
}

TOExplosiveMachine03::TOExplosiveMachine03(void *set_data) {
    m_name = TOExplosiveMachine03__class_name;
    apply_object_set_data(set_data);
    model = get_bml_model(explosive_machine_model_archive, 6);
    texlist = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 6);
    view_radius = ((ExplosiveMachineModel *)((NJS_OBJECT *)model)->model)->radius;
    debris_models[0] = get_bml_model(explosive_machine_model_archive, 7);
    debris_textures[0] = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 7);
    debris_models[1] = get_bml_model(explosive_machine_model_archive, 8);
    debris_textures[1] = TObjFish__sub_8001EDB0(explosive_machine_model_archive, 8);
}

TOExplosiveMachine03::~TOExplosiveMachine03() {}

extern "C" void *TOExplosiveMachine03__create(void *set_data) {
    return new TOExplosiveMachine03(set_data);
}
#pragma pop
