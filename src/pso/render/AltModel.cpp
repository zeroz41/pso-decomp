#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/AltModel.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/model_render_state.h"
#include "pso/render/render_util.h"

#include "pso/enemy/dd/TObjEneDD_ST.h"
#include "pso/object/base/TObjCharaHelpers.h"

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/object/ambient/TObjLight.h"
#include "pso/object/ambient/TObjLight_SceneLights.h"

void update_lights() { current_scene_light->init_directional_light(); current_scene_light->debug_scene_light_hook(); }

void begin_alt_model_draw() {  }

void clear_alt_model_flag() {
    model_render_flags &= 0xFFFFF7FF;
    set_chunk_material_override_pair(0xFF00, 0);
}
void set_alt_model_flag() {
    model_render_flags |= 0x800;
    set_chunk_material_override_pair(-513, 0);
}
NJS_OBJECT alt_model_object;
NJS_CNK_MODEL alt_model;
AltChunkStrips alt_model_strips;

NJS_OBJECT *prepend_alt_model(NJS_OBJECT *next, s32 diffuse) {
    alt_model_strips.diffuse = diffuse;
    alt_model_object.sibling = next;
    return &alt_model_object;
}
void TObjEneDD_ST::draw_with_alt_model(s32 diffuse) {
    NJS_OBJECT *saved_model = model;
    set_alt_model_flag();
    begin_alt_model_draw();
    model = prepend_alt_model(saved_model, diffuse);
    draw();
    update_lights();
    clear_alt_model_flag();
    model = saved_model;
}
void init_alt_model() {
    s16 *strips = (s16 *)&alt_model_strips;
    NJS_OBJECT *object = &alt_model_object;
    strips[0] = 0x2514;
    strips[1] = 2;
    strips[2] = 0;
    strips[3] = 0xAFF;
    strips[4] = 0xFF;
    strips[5] = 0xFF;
    alt_model.vertex_list = NULL;
    alt_model.polygon_list = strips;
    alt_model.center[0] = 0.0f;
    alt_model.center[1] = 0.0f;
    alt_model.center[2] = 0.0f;
    alt_model.r = 0.0f;
    object->evalflags = 0x57;
    object->model = &alt_model;
    object->pos[0] = 0.0f;
    object->pos[1] = 0.0f;
    object->pos[2] = 0.0f;
    object->ang[0] = 0;
    object->ang[1] = 0;
    object->ang[2] = 0;
    object->scl[0] = 0.0f;
    object->scl[1] = 0.0f;
    object->scl[2] = 0.0f;
    object->child = NULL;
    object->sibling = NULL;
}

s32 split_screen_active() {
    return is_split_screen() ? 1 : 0;
}
