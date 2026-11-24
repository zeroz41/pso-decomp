#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/render_util.h"

#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/player/TObjPlayer_80011014.h"

/* Ninja chunk strips, model and object used to override the material of the next drawn model. */
struct AltChunkStrips {
    s16 header;
    s16 size;
    s32 diffuse;
    s16 end[2];
};

struct AltChunkModel {
    s32 *vlist;
    s16 *plist;
    f32 center[3];
    f32 radius;
};

struct AltChunkObject {
    u32 eval_flags;
    AltChunkModel *model;
    f32 position[3];
    s32 angle[3];
    f32 scale[3];
    AltChunkObject *child;
    AltChunkObject *sibling;
    u8 pad34[4];
};

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/object/ambient/TObjLight_80133568.h"

extern "C" {
void set_chunk_material_override_pair(s32 first, s32 second);
extern s32 model_render_flags;

void TObjPlayer::update_lights() { current_scene_light->init_directional_light(); current_scene_light->sub_801337F8(); }

void TObjPlayer::begin_alt_model_draw() {  }

void TObjPlayer::clear_alt_model_flag() {
    model_render_flags &= 0xFFFFF7FF;
    set_chunk_material_override_pair(0xFF00, 0);
}
void TObjPlayer::set_alt_model_flag() { model_render_flags |= 0x800; set_chunk_material_override_pair((saddr)(-513), (saddr)(0)); }
AltChunkObject alt_model_object;
AltChunkModel alt_model;
AltChunkStrips alt_model_strips;

AltChunkObject *TObjPlayer__sub_800F08AC(AltChunkObject *next, s32 diffuse) {
    alt_model_strips.diffuse = diffuse;
    alt_model_object.sibling = next;
    return &alt_model_object;
}
void TObjEneDD_ST::draw_with_alt_model(s32 diffuse) {
    saddr temp_r31;
    temp_r31 = (saddr)this->model;
    TObjPlayer::set_alt_model_flag();
    TObjPlayer::begin_alt_model_draw();
    this->model = (void *)TObjPlayer__sub_800F08AC((AltChunkObject *)temp_r31, diffuse);
    draw();
    TObjPlayer::update_lights();
    TObjPlayer::clear_alt_model_flag();
    this->model = (void *)temp_r31;
}
void TObjPlayer::init_alt_model() {
    s16 *strips = (s16 *)&alt_model_strips;
    AltChunkObject *object = &alt_model_object;
    strips[0] = 0x2514;
    strips[1] = 2;
    strips[2] = 0;
    strips[3] = 0xAFF;
    strips[4] = 0xFF;
    strips[5] = 0xFF;
    alt_model.vlist = NULL;
    alt_model.plist = strips;
    alt_model.center[0] = 0.0f;
    alt_model.center[1] = 0.0f;
    alt_model.center[2] = 0.0f;
    alt_model.radius = 0.0f;
    object->eval_flags = 0x57;
    object->model = &alt_model;
    object->position[0] = 0.0f;
    object->position[1] = 0.0f;
    object->position[2] = 0.0f;
    object->angle[0] = 0;
    object->angle[1] = 0;
    object->angle[2] = 0;
    object->scale[0] = 0.0f;
    object->scale[1] = 0.0f;
    object->scale[2] = 0.0f;
    object->child = NULL;
    object->sibling = NULL;
}

s32 is_split_screen__10TObjPlayerFv(void) {
    return is_split_screen() ? 1 : 0;
}

}
