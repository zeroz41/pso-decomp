#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/effect/item/TItemEffArmor.h"
#include "pso/effect/particle/ParticleFactory.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/item/TItemLoad.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TActorLight.h"
#include "pso/object/ambient/TObjLight_80133568.h"
#include "pso/technique/TechniqueContact.h"
#include "pso/player/PlayerSlots.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80011014.h"
#include "pso/player/TObjPlayer_80117DD8.h"
#include "pso/player/TObjPlayer_8023E480.h"
#include "pso/player/TObjPlayer_803E1A58.h"
#include "pso/player/TPlyDispData.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/model_render_state.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/scene/TScene.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/vector.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"
#include "types.h"
#include "pso/object/base/TObjBase.h"

// The armour's glow: the model's starting colour and its actor light's.
extern const NJS_ARGB armor_glow_color = { 1.0f, 0.5f, 1.0f, 1.0f };
const char *TItemEffArmor::class_name = "TItemEffArmor";

#pragma defer_codegen on

void TObjPlayer::spawn_appearance_effect(u16 client) {
    TObjPlayer *player = get_player_by_client_id(client);
    if (player != NULL) {
        player_stats *stats = (player_stats *)player->get_stats();
        if (stats != NULL) {
            f32 proportions = stats->proportions;
            Vec upper;
            Vec lower;
            f32 scale;
            player->get_anim_node_position(0x28, &upper);
            player->get_anim_node_position(0x1B, &lower);
            scale = 1.2f * (xyz_distance(&upper, &lower) / 20.0f);
            new TItemEffArmor(player, scale, proportions);
            play_sound_effect(0x4000B20A, &player->position, 0, 0);
        }
    }
}

TItemEffArmor::TItemEffArmor(TObjPlayer *owner, f32 scale, f32 rise) : TObject(tl_07) {
    m_name = class_name;
    frame = 0.0f;
    TItemLoad::get_armor_effect_model(&model, &texture_list, &motion);
    this->scale = scale;
    this->rise = rise;
    this->owner = owner;
    angle_y = 0;
    light_level = default_scene_light_config.ambient;
    light_intensity = default_scene_light_config.intensity;
    light_step = (1.0f - light_level) / 14.5f;
    particle = create_particle_emitter(&this->owner->position, 0x1BA);
    copy_argb(&color, (NJS_ARGB *)&armor_glow_color);
    {
        Vec up = { 0.0f, 1.0f, 0.0f };
        new TActorLight(0.2f, (NJS_ARGB *)&armor_glow_color, &up, 0x3A, owner, tl_07);
    }
}

TItemEffArmor::~TItemEffArmor() {
    TParticleCtrl::release(particle);
}

void TItemEffArmor::run_task() {
    angle_y += 0x139D;
    if (owner != NULL) {
        VecCopy(&position, &owner->position);
    }
    position.y += (frame * rise) / 29.0f;
    if (particle != NULL) {
        particle->set_position(&position);
    }
    color.a = 1.0f - (frame / 29.0f);
    if (owner != NULL) {
        publish_actor_light_scalars(owner->get_entity_id(), light_intensity, light_level);
    }
    if (light_level >= 1.0f) {
        light_step = -1.0f * light_step;
    }
    light_level += light_step;
    if (29.0f == frame) {
        queue_destruction();
    }
    frame += 1.0f;
}

void TItemEffArmor::render() {
    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(NULL, angle_y);
    scale_matrix(NULL, scale, 1.0f, scale);
    saved_model_render_flags = model_render_flags;
    model_render_flags |= 0x10;
    copy_argb(&saved_model_draw_color, &model_material_color);
    set_constant_material(&color);
    set_texlist(texture_list);
    draw_ginja_model_with_motion(model, motion, frame);
    copy_argb(&model_material_color, &saved_model_draw_color);
    model_render_flags = saved_model_render_flags;
    pop_matrix();
}

TItemEffArmorPulse::TItemEffArmorPulse(TObject *parent, u16 client_id) : TObject(parent) {
    timer = 0;
    this->client_id = client_id;
}

TItemEffArmorPulse::~TItemEffArmorPulse() {
}

void TItemEffArmorPulse::run_task() {
    if (120.0f <= (f32)timer) {
        TObjPlayer *player = get_player_by_client_id(client_id);
        if (player != NULL) {
            if (is_item_area_enabled(player->get_area()) == 1) {
                if (is_opposite_sex_player_near(player->get_entity_id()) != 0) {
                    spawn_particle_effect(&player->body_center, 0x1BE);
                }
            }
        }
        timer = 0;
    }
    timer++;
}

#pragma defer_codegen off
