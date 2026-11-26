#include "pso/system/BmlAccessors.h"
#include "types.h"
#include "pso/object/ambient/TButterfly.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/BmlResource.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "pso/render/ModelDrawContext.h"
#include <stdlib.h>
#include "pso/object/ambient/TObjFish.h"
#include "pso/system/task/TMainTask.h"
#include "pso/math/MatrixVector.h"

__declspec(section ".data") const char *bm_o_abe_butterfly_model_names[2] = { "abecyou_fe_obj001_cyou.gj", NULL };
__declspec(section ".data") const char *bm_o_abe_butterfly_motion_names[2] = { "abecyou2_fe_obj001_cyou.njm", NULL };
BmlResourceDescriptor bm_o_abe_butterfly_resource_descriptor = {
    "bm_o_abe_butterfly.bml", bm_o_abe_butterfly_model_names, bm_o_abe_butterfly_motion_names, 1, 1
};
const char *butterfly_name = "TButterfly";

extern "C" {

BmlResource *butterfly_bml_resource;

void TButterfly::draw_model() {
    push_matrix();
    post_translate_matrix(&this->position.x);
    rotate_matrix_y(0, this->rotation_y);
    rotate_matrix_x(0, -0x2000);
    draw_ginja_model_with_motion(get_bml_model((BmlResource *)butterfly_bml_resource, 0), get_bml_motion(butterfly_bml_resource, 0), this->motion_frame);
    pop_matrix();
}

void TButterfly::init_motion() {
    VecCopy(&this->home_position, &this->position);
    this->velocity.x = 0.0f;
    this->velocity.y = 0.0f;
    this->velocity.z = 0.0f;
    this->motion_frame = (f32) ((0.5f) * ((3.0517578e-05f) * (f32) rand()));
    this->lift = 0.0f;
    this->state = 0;
    this->flag = 0;
    this->timer = 0x1E;
    this->angle = 0;
}

void TButterfly::render() {
    if (this->update_object_view_visibility((4e+02f), (2e+01f)) != 0) {
        TObjFish::set_global_param(get_bml_texlist((BmlResource *)butterfly_bml_resource, 0));
        draw_model();
    }
}


#pragma push
#pragma fp_contract on
void TButterfly::run_task() {
    f32 target;
    f32 lift;
    target = 3.2f * sin_table_lookup(this->angle) + this->home_position.y;
    if (this->flag == 0) {
        this->lift = 5.0f * (target - this->position.y);
        lift = this->lift;
        if (lift < 0.1f) {
            this->lift = 0.1f;
        } else if (lift > 4.0f) {
            this->lift = 4.0f;
        }
        this->phase_speed = 2.0f * (0.01f * this->lift) + 0.3f;
        this->velocity.y = 0.1f * (0.027f * this->lift) + this->velocity.y;
        this->velocity.y = this->velocity.y - 0.027f;
        this->motion_frame = this->motion_frame + this->phase_speed;
        if (this->motion_frame > 5.0f) {
            this->motion_frame = 0.0f;
        }
    } else {
        this->lift = -7.0f * (target - this->position.y);
        lift = this->lift;
        if (lift < 0.1f) {
            this->lift = 0.1f;
        } else if (lift > 4.0f) {
            this->lift = 4.0f;
        }
        this->phase_speed = 2.0f * (0.1f * this->lift) + 0.32f;
        this->velocity.y = this->velocity.y - 0.5f * (0.027f * this->lift);
        this->velocity.y = this->velocity.y - 0.027f;
        this->motion_frame = this->motion_frame + this->phase_speed;
        if (this->motion_frame > 5.0f) {
            this->motion_frame = 0.0f;
            this->flag = 0;
        }
    }
    switch (this->state) {
    case 0:
        this->velocity.x *= (0.8f);
        this->velocity.z *= (0.8f);
        break;
    case 1:
        if (this->flag == 0) {
            Vec dir;
            Vec out;
            dir.x = 2.0f * (0.0015f * (2.0f * (3.0517578125e-05f * (f32)rand()) - 1.0f));
            dir.y = 0.0f;
            dir.z = 2.0f * (0.0015f * (3.0517578125e-05f * (f32)rand())) + 0.05f;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(NULL, this->rotation_y);
            rotate_vector_by_matrix(NULL, &dir, &out);
            pop_matrices(1);
            this->velocity.x = this->velocity.x + out.x;
            this->velocity.z = this->velocity.z + out.z;
            this->velocity.x *= (0.72f);
            this->velocity.z *= (0.72f);
        } else {
            this->velocity.x *= (0.85f);
            this->velocity.z *= (0.85f);
        }
        break;
    case 2:
        if (this->turn_dir == 0) {
            this->rotation_y = (f32)this->rotation_y + (200.0f * (3.0517578125e-05f * (f32)rand()) + 200.0f);
        } else {
            this->rotation_y = (f32)this->rotation_y - (200.0f * (3.0517578125e-05f * (f32)rand()) + 200.0f);
        }
        if (this->flag == 0) {
            Vec dir;
            Vec out;
            dir.x = 2.0f * (0.025f * (2.0f * (3.0517578125e-05f * (f32)rand()) - 1.0f));
            dir.y = 0.0f;
            dir.z = 2.0f * (0.025f * (3.0517578125e-05f * (f32)rand())) + 0.05f;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(NULL, this->rotation_y);
            rotate_vector_by_matrix(NULL, &dir, &out);
            pop_matrices(1);
            this->velocity.x = this->velocity.x + out.x;
            this->velocity.z = this->velocity.z + out.z;
            this->velocity.x *= (0.85f);
            this->velocity.z *= (0.85f);
        } else {
            this->velocity.x *= (0.75f);
            this->velocity.z *= (0.75f);
        }
        break;
    }
    vec3_add_to(&this->position, &this->velocity);
    if (this->position.y > 12.0f + target) {
        this->position.y = 12.0f + target;
    } else if (this->position.y < target - 6.0f) {
        this->position.y = target - 6.0f;
    }
    if (this->timer != 0) {
        this->timer--;
    } else {
        switch (this->state) {
        case 0:
            this->state = 1;
            this->timer = 2.0f * (20.0f * (3.0517578125e-05f * (f32)rand())) + 20.0f;
            break;
        case 1:
            if (3.0517578125e-05f * (f32)rand() < 0.5f) {
                this->state = 2;
                this->timer = 50.0f * (3.0517578125e-05f * (f32)rand()) + 50.0f;
                if (3.0517578125e-05f * (f32)rand() < 0.5f) {
                    this->turn_dir = 0;
                } else {
                    this->turn_dir = 1;
                }
            } else {
                this->state = 0;
                this->timer = 30.0f * (3.0517578125e-05f * (f32)rand()) + 30.0f;
            }
            break;
        case 2:
            if (3.0517578125e-05f * (f32)rand() < 0.4f) {
                this->state = 2;
                this->timer = 50.0f * (3.0517578125e-05f * (f32)rand()) + 50.0f;
                if (3.0517578125e-05f * (f32)rand() < 0.5f) {
                    this->turn_dir = 0;
                } else {
                    this->turn_dir = 1;
                }
            } else {
                this->state = 1;
                this->timer = 2.0f * (30.0f * (3.0517578125e-05f * (f32)rand())) + 30.0f;
            }
            break;
        }
    }
    this->angle = this->angle + (s32)(40.0f * (3.0517578125e-05f * (f32)rand()) + 160.0f);
}
#pragma pop

}
TButterfly::~TButterfly() {

}
TButterfly::TButterfly(TObject *parent, void *arg2) : TObjBase(parent) {
    this->m_name = butterfly_name;
    VecCopy(&this->position, (const Vec *)((char *)arg2 + 12));
    copy_xyz((char *)this + 92, ((char *)arg2 + 24));
    VecCopy(&this->scale, (const Vec *)((char *)arg2 + 36));
    this->init_motion();
}


void *TButterfly::create(void *set_data) {
    void *o = (void *)new TButterfly(tl_05, set_data);
    return o;
}


void TButterfly::destroy_instance() {
    if (butterfly_bml_resource != NULL) {
        delete butterfly_bml_resource;
        butterfly_bml_resource = NULL;
    }
}


void TButterfly::load_resources() {
    BmlResource *loaded = (BmlResource *)new BmlResource(1, &bm_o_abe_butterfly_resource_descriptor, 0, 0, NULL);
    butterfly_bml_resource = loaded;
}
