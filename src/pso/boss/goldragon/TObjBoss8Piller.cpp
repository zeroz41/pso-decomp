#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/BmlResource.h"
#include "types.h"
#include "pso/system/MatrixStack.h"
#include "pso/boss/goldragon/TObjBoss8Piller.h"
#include "pso/boss/goldragon/TBoss8Dragon.h"
#include "pso/render/TextureState.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"
#include "pso/object/base/TObjCharaHelpers.h"
#include "pso/system/vector.h"
#include <stdlib.h>
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/object/TObjControl.h"
#include "pso/render/ChunkModelDraw.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/NinjaTypes.h"

const char *bm_obj_boss8_piller_model_names[5] = {
    "fe_obj_gol_hasira5m.nj", "fe_obj_gol_hasira1m.nj", "fe_obj_gol_hasira5m_m.nj", "fe_obj_gol_hasira1m_m.nj", NULL,
};
const char *bm_obj_boss8_piller_motion_names[3] = { "fe_obj_gol_hasira5m.njm", "fe_obj_gol_hasira1m.njm", NULL };
BmlResourceDescriptor bm_obj_boss8_piller_resource_descriptor = {
    "bm_obj_boss8_piller.bml", bm_obj_boss8_piller_model_names, bm_obj_boss8_piller_motion_names, 4, 2,
};
const char *TObjBoss8Piller::class_name = "TObjBoss8Piller";


BmlResource *TObjBoss8Piller::shared_resource;


extern "C" {
void TObjBoss8Piller::render() {
    NJS_OBJECT *model;

    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        if (is_split_screen() != 0) {
            model = TObjBoss8Piller::shared_resource->models[2].model;
        } else {
            model = TObjBoss8Piller::shared_resource->models[0].model;
        }
        set_texture_list(reinterpret_cast<NJS_TEXLIST *>(TObjBoss8Piller::shared_resource->models[0].texlist));
        push_matrix();
        post_translate_matrix(&this->position.x);
        scale_matrix(0, 1.0f, 1.0f, 1.0f);
        draw_model_motion(model, this->motion, this->frame);
        pop_matrix();
        set_default_alpha_blend();
    }
}
void TObjBoss8Piller::run_task() {
    TBoss8Dragon *dragon;
    u32 last_frame;
    this->frame += 1.0f;
    dragon = (TBoss8Dragon *)get_enemy_entity(this->dragon_id);
    if (dragon != NULL) {
        dragon->apply_pillar_attack(&this->position, 25.0f);
    }
    last_frame = this->motion->nbFrame - 1;
    if (this->frame >= (f32)last_frame) {
        this->frame = (f32)last_frame;
        this->queue_destruction();
    }
}
}


TObjBoss8Piller::~TObjBoss8Piller() {}

TObjBoss8Piller::TObjBoss8Piller(TObject *parent, Vec *pos, f32, u16 dragon_id) : TObject(parent) {
    m_name = TObjBoss8Piller::class_name;
    VecCopy(&this->position, pos);
    this->position.y = 0.0f;
    this->frame = 0.0f;
    this->dragon_id = dragon_id;
    this->frame = 3.0f * (3.0517578e-05f * (f32)rand());
    this->motion = TObjBoss8Piller::shared_resource->motions[0].motion;
}

extern "C" {

void TObjBoss8Piller::free_held_object() {
    if (TObjBoss8Piller::shared_resource != NULL) {
        delete TObjBoss8Piller::shared_resource;
        TObjBoss8Piller::shared_resource = NULL;
    }
}
void TObjBoss8Piller::load_resource_descriptor() {
    TObjBoss8Piller::shared_resource = new BmlResource(5, &bm_obj_boss8_piller_resource_descriptor, 0, 0, NULL);
}

}
