#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/dragon/TObjBoss1Floor.h"
#include "pso/boss/dragon/TObjBoss1Crater.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_8002C190.h"
#include "pso/unk/text_8002E174.h"
#include "pso/render/render_util.h"
#include "pso/render/model_render_state.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/unk/text_803D96A8.h"


#include "pso/unk/TLobby.h"
#include "pso/system/task/TMainTask.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/enemy/dd/TObjEneDD.h"
#include "pso/ui/hud/TNowLoading.h"
#include "pso/system/scene/TScene.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/player/TObjPlayer_801AF2F0.h"
#include "pso/system/task/TObject.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/boss/dragon/TObjBoss1MokoHill_Solo.h"
#include "pso/boss/dragon/TObjBoss1MokoHill_SoloM.h"
#include "pso/boss/dragon/ObjBoss1CommonResource.h"
#include "pso/system/BmlResource.h"
#include "pso/system/MatrixStack.h"
#include "pso/boss/goldragon/TBoss8Dragon_8002CC48.h"
#include "pso/system/scene/TScene_800838C4.h"
#include "pso/player/PlayerSlots.h"

extern "C" {
const char *TObjBoss1Floor__name = "TObjBoss1Floor";
void TObjBoss1Floor__sub_8002CB40(void);
void TObjBoss1Floor__sub_8002CB78(void);
}

void TLobby::update_boss1_objects() { TObjBoss1MokoHill_SoloM::free_resources(); TObjBoss1Rock__sub_8002E3CC(); TObjBoss1Crater__sub_8002C7B4(); TObjBoss1Floor__sub_8002CB40(); TLobby::free_char_select(); }
void TLobby::forward_floor_2CB44() { TObjBoss1Floor::create_instance(); }
void TLobby::init_bosses() { load_dragon_ground_assets(); TObjBoss1Floor__sub_8002CB78(); TObjBoss1Crater__sub_8002C7B8(); TObjBoss1Rock__sub_8002E3D0(); TObjBoss1MokoHill_SoloM::load_resources(); }


void TObjBoss1Floor::render() {
    u32 temp_r3;
    NJS_OBJECT *floor;

    if ((TObjPlayer::is_any_teammate_in_state() == 0) && ((TObjEneDD::check_v2_mode() != 0) || (TMainTask::get_render_pass() != 1))) {
        temp_r3 = model_render_flags;
        saved_model_render_flags = temp_r3;
        model_render_flags = temp_r3 | 0x400;
        TParticleCtrl::end_effect_render();
        push_matrix();
        model_render_flags = 1;
        set_draw_list_mask(3);
        TObjPlayer::draw_if_all_ready();
        TObjFish::set_global_param(dragon_common_texture_list);
        floor = dragon_ground_resource->models[5].model;
        render_projected_shadow_receiver((u8 *)floor->pos, (saddr)floor->ang);
        draw_ginja_model(floor->model);
        TScene::apply_single_screen_state();
        restore_draw_list_mask();
        pop_matrix();
        model_render_flags = saved_model_render_flags;
    }
}

void TObjBoss1Floor::run_task() {
    s32 i;
    TObjPlayer *player;
    if (TObjEneDD::check_v2_mode() != 0) {
        for (i = 0; i < 4; i++) {
            player = get_player_by_client_id(i);
            if (player != NULL) {
                Vec pos = player->position;
                pos.y -= 4.0f;
                if (this->player_emitters[i] == NULL) {
                    this->player_emitters[i] = create_particle_emitter(&pos, 0x144);
                } else {
                    this->player_emitters[i]->set_position(&pos);
                }
            } else if (this->player_emitters[i] != NULL) {
                this->player_emitters[i]->queue_destruction();
                this->player_emitters[i] = NULL;
            }
        }
    }
}

TObjBoss1Floor::~TObjBoss1Floor() {
    s32 i;
    for (i = 0; i * 0x10 != 0; i++) {
        if (this->player_emitters[i] != NULL) {
            this->player_emitters[i]->queue_destruction();
            this->player_emitters[i] = NULL;
        }
    }
}
TObjBoss1Floor::TObjBoss1Floor(TObject *parent) : TObject(parent) {
    s32 i;
    m_name = TObjBoss1Floor__name;
    this->position.x = 0.0f;
    this->position.y = 0.0f;
    this->position.z = 0.0f;
    for (i = 0; i < 4; i++) {
        this->player_emitters[i] = NULL;
    }
}

extern "C" void TObjBoss1Floor__sub_8002CB40(void) {  }


void TObjBoss1Floor::create_instance() {
    void* obj = new TObjBoss1Floor((TObject *)tl_02);
}

extern "C" void TObjBoss1Floor__sub_8002CB78(void) {  }


void TObjBoss1MokoHill_Solo::render() {
    TObjFish::set_global_param(dragon_common_texture_list);
    update_dragon_trail_uvs(&position);
    push_matrix();
    translate_matrix(0, position.x, height, position.z);
    if (v2_mode != 0) {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x800;
        set_chunk_material_override_pair(0xFF00, 0x100);
        draw_chunk_object(dragon_ground_resource->models[3].model);
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
    } else {
        draw_chunk_object(dragon_ground_resource->models[3].model);
    }
    pop_matrix();
}
