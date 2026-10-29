#include "types.h"
#include "pso/object/TObjTreeLobby.h"
#include "pso/object/TQuestDamageTask.h"
#include "pso/TMainTask.h"
#include "pso/TParticleCtrl.h"
#include "pso/misc/TLobby.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/BmlResource.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/boss/TBoss5GryphonLightningWing.h"

#pragma readonly_strings on

extern "C" {
void TLobby__sub_8001FE7C(BmlResource *resource, s32 del);
BmlResource *load_resource_from_descriptor(void *resource, s32 kind, BmlResourceDescriptor *descriptor, s32, s32, s32);
}

__declspec(section ".sdata") const char *bm_obj_lobby_tree_motion_names[1] = { NULL };
__declspec(section ".data") const char *bm_obj_lobby_tree_model_names[2] = { "lobby_yukieda_hachi.gj", NULL };
BmlResourceDescriptor bm_obj_lobby_tree_resource_descriptor = { "bm_obj_lobby_tree.bml", bm_obj_lobby_tree_model_names, bm_obj_lobby_tree_motion_names, 1, 0 };
const char *obj_tree_lobby_class_name = "TObjTreeLobby";
BmlResource *TObjTreeLobby::model_resource;
u32 TObjTreeLobby::lobby_texlist;

TQuestDamageTask::TQuestDamageTask(u16 client_id, TObject *parent, f32 damage) : TObject(parent) {
    this->damage = damage;
    this->client_id = client_id;
}

TQuestDamageTask::~TQuestDamageTask() {}

void TQuestDamageTask::run_task() {
    TObjPlayer *player = get_player_by_client_id(client_id);
    if (player != NULL) {
        DirectAttackPayload attack;
        attack.kind = 21;
        attack.power = damage;
        player->receive_direct_attack(player, attack, NULL, -1, -1);
        queue_destruction();
    }
}

TObjTreeLobby::TObjTreeLobby(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = obj_tree_lobby_class_name;
    apply_object_set_data(set_data);
    if (is_lobby_event_active() != 0) {
        fade_state = 0;
    } else {
        fade_state = 3;
    }
    fade_scale = 1.0f;
    model = (void *)model_resource->models->model;
    texlist = lobby_texlist;
}

TObjTreeLobby::~TObjTreeLobby() {}

void TObjTreeLobby::load_resources() {
    void *resource = ::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 5, &bm_obj_lobby_tree_resource_descriptor, 0, 0, 0);
    }
    model_resource = (BmlResource *)resource;
    lobby_texlist = TLobby::get_lobby_texlist();
}

void TObjTreeLobby::destroy_static_instance() {
    if (model_resource != NULL) {
        TLobby__sub_8001FE7C(model_resource, 1);
        model_resource = NULL;
    }
}

void *TObjTreeLobby::create(void *set_data) {
    return new TObjTreeLobby(tl_05, set_data);
}

void TObjTreeLobby::run_task() {
    switch (fade_state) {
    case 0:
        if (TLobby::is_connected() != 0) {
            fade_state = 2;
        }
        break;
    case 2:
        fade_scale += 0.1f;
        if (fade_scale >= 1.0f) {
            fade_scale = 1.0f;
            fade_state = 3;
        }
        break;
    case 1:
        fade_scale -= 0.1f;
        if (fade_scale <= 0.0f) {
            fade_scale = 0.0f;
            fade_state = 0;
        }
        break;
    case 3:
    default:
        if (TLobby::is_lobby_obj_active() != 0) {
            fade_state = 1;
        }
        break;
    }
}

void TObjTreeLobby::render() {
    if (fade_state != 0) {
        TParticleCtrl::begin_effect_render();
        TObjFish::set_global_param(texlist);
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_y(NULL, rotation_y);
        if (fade_state != 3) {
            scale_matrix(NULL, fade_scale, 1.0f, fade_scale);
        }
        draw_ginja_object(model);
        pop_matrix();
        TParticleCtrl::end_effect_render();
    }
}
