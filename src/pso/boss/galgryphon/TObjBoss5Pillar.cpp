#include "pso/unk/text_80066F10.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/boss/galgryphon/TObjBoss5Pillar.h"
#include "pso/boss/galgryphon/TObjBoss5PillarDemo.h"
#include "pso/boss/galgryphon/TObjBoss5PillarSmoke.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/system/BmlResource.h"
#include "pso/animation/ActorAnimationState.h"

#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"
#include "pso/render/ModelDrawContext.h"

#pragma readonly_strings on

extern "C" {
const char *lbl_805D3B40 = "TObjBoss5Pillar";
s32 post_translate_matrix(void *);

}

void TObjBoss5Pillar::render() {
    if (TObjPlayer::is_any_teammate_in_state() == 0) {
        push_matrix();
        TObjFish::set_global_param(boss5_common_texture_list);
        post_translate_matrix(&this->position);
        if (this->state != 3) {
            fn_8028ADDC(this->smoke);
            draw_ginja_model_with_motion(this->models[0], this->motions[0], this->frame);
            TObjBoss5PillarDemo__sub_8028ADB0(this->smoke);
        }
        draw_ginja_model_with_motion(this->models[1], this->motions[1], this->frame);
        pop_matrix();
    }
}

void TObjBoss5Pillar::run_task() {
    u32 last;
    switch (this->state) {
    case 0:
        break;
    case 1:
        if (this->smoke == NULL) {
            this->smoke = create_smoke(this, this->models[0]);
        }
        this->frame += this->frame_step;
        last = this->motions[0]->frameCount - 1;
        if ((f32)last <= this->frame) {
            this->frame = (f32)last;
            this->state = 2;
        }
        break;
    case 2:
        if (this->smoke != NULL) {
            fn_8028AE1C(this->smoke);
        }
        if (this->timer++ > 0x1E) {
            if (this->smoke != NULL) {
                this->smoke->queue_destruction();
                this->smoke = NULL;
            }
            this->state = 3;
        }
        break;
    case 3:
        break;
    }
}

TObjBoss5Pillar::~TObjBoss5Pillar() {
    if (this->smoke != NULL) {
        this->smoke->queue_destruction();
        this->smoke = NULL;
    }
}

TObjBoss5Pillar::TObjBoss5Pillar(TObject *parent, Vec *pos) : TObject(parent) {
    m_name = lbl_805D3B40;
    VecCopy(&this->position, pos);
    this->state = 0;
    this->frame = 0.0f;
    this->frame_step = 1.0f;
    this->timer = 0;
    this->smoke = NULL;
    this->models[0] = boss5_common_bml_resource->models[0].model;
    this->models[1] = boss5_common_bml_resource->models[1].model;
    this->motions[0] = boss5_common_bml_resource->motions[2].motion;
    this->motions[1] = boss5_common_bml_resource->motions[3].motion;
}
