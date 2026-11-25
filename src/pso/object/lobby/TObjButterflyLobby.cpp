#include "pso/system/BmlAccessors.h"
#include "pso/system/BmlResourceLoader.h"
#include "pso/system/BmlResource.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/object/ambient/TObjFish_8001ED90.h"
#include "types.h"
#include "pso/object/lobby/TObjButterflyLobby.h"
#include "pso/object/lobby/TObjButterflyLobby_80350958.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"

#include "pso/network/TLobby.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/unk/TLobbyEventTheme.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/unk/text_803516F8.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/math/AngleLookup.h"
#include <stdlib.h>
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/map/CsnQuery.h"
#include "pso/math/MatrixVector.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"

const char *bm_butterfly_lobby_model_names[3] = {"lobby_chou00_bule.gj", "lobby_chou01_red.gj", NULL};
const char *bm_butterfly_lobby_motion_names[2] = {"lobby_chou00_bule.njm", NULL};
BmlResourceDescriptor bm_butterfly_lobby_resource_descriptor = {
    "bm_butterfly_lobby.bml", bm_butterfly_lobby_model_names, bm_butterfly_lobby_motion_names, 2, 1,
};
/* inferred: TObject name the constructor stores */
const char *butterfly_lobby_name = "TObjButterflyLobby";

BmlResource *lobby_butterfly_bml_resource;

void TObjButterflyLobby::draw_butterfly() {
    f32 temp_f1;

    push_matrix();
    post_translate_matrix(&position.x);
    rotate_matrix_y(0, rotation_y);
    rotate_matrix_x(0, -0x2000);
    if ((s32) appear_state != 3) {
        temp_f1 = appear_scale;
        scale_matrix(0, temp_f1, temp_f1, temp_f1);
    }
    draw_ginja_model_with_motion(lobby_model, get_bml_motion(lobby_butterfly_bml_resource, 0), animation_frame);
    pop_matrix();
}

void TObjButterflyLobby::init_params() {
    VecCopy(&this->hover_origin, &this->position);
    this->velocity.x = 0.0f;
    this->velocity.y = 0.0f;
    this->velocity.z = 0.0f;
    animation_frame = (0.5f * (3.0517578125e-05f * (f32) rand()));
    this->lift = 0.0f;
    this->flight_state = 0;
    this->rising = 0;
    this->state_timer = 0x1E;
    this->bob_phase = 0;
}

void TObjButterflyLobby::render() {
    if ((this->update_object_view_visibility(400.0f, 20.0f) != 0) && ((s32) this->appear_state != 0)) {
        TObjFish::set_global_param(reinterpret_cast<NJS_TEXLIST *>(this->model_textures));
        draw_butterfly();
    }
}
void TObjButterflyLobby::update_fade() {
    switch (appear_state) {
    case 0:
        if (TLobbyEventTheme::ended() != 0) {
            appear_state = 2;
        }
        break;
    case 2:
        appear_scale += 0.1f;
        if (appear_scale >= 1.0f) {
            appear_scale = 1.0f;
            appear_state = 3;
        }
        break;
    case 1:
        appear_scale -= 0.1f;
        if (appear_scale <= 0.0f) {
            appear_scale = 0.0f;
            appear_state = 0;
        }
        break;
    case 3:
    default:
        if (TLobbyEventTheme::started() != 0) {
            appear_state = 1;
        }
        break;
    }
}
#pragma push
#pragma fp_contract on

#define FRND() (3.0517578125e-05f * (f32)rand())
void TObjButterflyLobby::run_task() {
    f32 base;
    update_fade();
    base = 3.2f * sin_table_lookup(this->bob_phase) + this->hover_origin.y;
    if (this->rising == 0) {
        this->lift = 5.0f * (base - this->position.y);
        if (this->lift < -4.0f) {
            this->lift = -4.0f;
        } else if (this->lift > 4.0f) {
            this->lift = 4.0f;
        }
        this->animation_speed = 2.0f * (0.01f * this->lift) + 0.3f;
        this->velocity.y += 0.1f * (0.027f * this->lift);
        this->animation_frame += this->animation_speed;
        if (this->animation_frame > 5.0f) {
            this->animation_frame = 0.0f;
        }
    } else {
        this->lift = -7.0f * (base - this->position.y);
        if (this->lift < 0.1f) {
            this->lift = 0.1f;
        } else if (this->lift > 4.0f) {
            this->lift = 4.0f;
        }
        this->animation_speed = 2.0f * (0.1f * this->lift) + 0.32f;
        this->velocity.y -= 0.5f * (0.027f * this->lift);
        this->velocity.y -= 0.027f;
        this->animation_frame += this->animation_speed;
        if (this->animation_frame > 5.0f) {
            this->animation_frame = 0.0f;
            this->rising = 0;
        }
    }
    switch (this->flight_state) {
    case 0:
        this->velocity.x *= 0.8f;
        this->velocity.z *= 0.8f;
        break;
    case 1:
        if (this->rising == 0) {
            Vec in;
            Vec out;
            in.x = 2.0f * (0.0015f * (2.0f * FRND() - 1.0f));
            in.y = 0.0f;
            in.z = 2.0f * (0.0015f * FRND()) + 0.05f;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, this->rotation_y);
            rotate_vector_by_matrix(0, &in, &out);
            pop_matrices(1);
            this->velocity.x += out.x;
            this->velocity.z += out.z;
            this->velocity.x *= 0.72f;
            this->velocity.z *= 0.72f;
        } else {
            this->velocity.x *= 0.85f;
            this->velocity.z *= 0.85f;
        }
        break;
    case 2:
        if (this->turn_dir == 0) {
            this->rotation_y += 200.0f * FRND() + 200.0f;
        } else {
            this->rotation_y -= 200.0f * FRND() + 200.0f;
        }
        if (this->rising == 0) {
            Vec in;
            Vec out;
            in.x = 2.0f * (0.025f * (2.0f * FRND() - 1.0f));
            in.y = 0.0f;
            in.z = 2.0f * (0.025f * FRND()) + 0.05f;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, this->rotation_y);
            rotate_vector_by_matrix(0, &in, &out);
            pop_matrices(1);
            this->velocity.x += out.x;
            this->velocity.z += out.z;
            this->velocity.x *= 0.85f;
            this->velocity.z *= 0.85f;
        } else {
            this->velocity.x *= 0.75f;
            this->velocity.z *= 0.75f;
        }
        break;
    }
    {
    Vec p;
    VecCopy(&p, &this->position);
    p.y += this->velocity.y;
    if (csnVector(&this->position, &p, -1) == 0) {
        VecCopy(&this->position, &p);
    } else {
        this->hover_origin.y = this->position.y;
        if (this->velocity.y < 0.0f) {
            this->hover_origin.y += 10.0f;
        } else {
            this->hover_origin.y -= 10.0f;
        }
    }
    p.x += this->velocity.x;
    if (csnVector(&this->position, &p, -1) == 0) {
        VecCopy(&this->position, &p);
    }
    p.z += this->velocity.z;
    if (csnVector(&this->position, &p, -1) == 0) {
        VecCopy(&this->position, &p);
    }
    }
    if (this->position.y > 12.0f + base) {
        this->position.y = 12.0f + base;
    } else if (this->position.y < base - 6.0f) {
        this->position.y = base - 6.0f;
    }
    if (this->state_timer != 0) {
        this->state_timer--;
    } else {
        switch (this->flight_state) {
        case 0:
            this->flight_state = 1;
            this->state_timer = 2.0f * (20.0f * FRND()) + 20.0f;
            break;
        case 1:
            if (FRND() < 0.5f) {
                this->flight_state = 2;
                this->state_timer = 50.0f * FRND() + 50.0f;
                if (FRND() < 0.5f) {
                    this->turn_dir = 0;
                } else {
                    this->turn_dir = 1;
                }
            } else {
                this->flight_state = 0;
                this->state_timer = 30.0f * FRND() + 30.0f;
            }
            break;
        case 2:
            if (FRND() < 0.4f) {
                this->flight_state = 2;
                this->state_timer = 50.0f * FRND() + 50.0f;
                if (FRND() < 0.5f) {
                    this->turn_dir = 0;
                } else {
                    this->turn_dir = 1;
                }
            } else {
                this->flight_state = 1;
                this->state_timer = 2.0f * (30.0f * FRND()) + 30.0f;
            }
            break;
        }
    }
    this->bob_phase += (s32)(40.0f * FRND() + 160.0f);
}
#pragma pop

TObjButterflyLobby::~TObjButterflyLobby() {

}
TObjButterflyLobby::TObjButterflyLobby(TObject *parent, ObjectSetData *set_data) : TObjBase(parent) {
    m_name = butterfly_lobby_name;
    VecCopy(&position, &set_data->position);
    copy_xyz(&rotation_x, set_data->rotation);
    VecCopy(&scale, &set_data->scale);
    if (is_lobby_event_active() != 0) {
        appear_state = 0;
    } else {
        appear_state = 3;
    }
    appear_scale = 1.0f;
    if (set_data->set_params[0] < 1) {
        lobby_model = (NJS_OBJECT *)get_bml_model(lobby_butterfly_bml_resource, 0);
        model_textures = get_bml_texlist(lobby_butterfly_bml_resource, 0);
    } else {
        lobby_model = (NJS_OBJECT *)get_bml_model(lobby_butterfly_bml_resource, 1);
        model_textures = get_bml_texlist(lobby_butterfly_bml_resource, 1);
    }
    init_params();
}


void *TObjButterflyLobby::create(void *set_data) {
    return new TObjButterflyLobby(tl_05, (ObjectSetData *)set_data);
}

void TObjButterflyLobby::destroy_instance() {
    if (lobby_butterfly_bml_resource != NULL) {
        delete lobby_butterfly_bml_resource;
        lobby_butterfly_bml_resource = NULL;
    }
}

void load_lobby_butterfly_bml_resource(void) {
    lobby_butterfly_bml_resource = new BmlResource(1, &bm_butterfly_lobby_resource_descriptor, 0, 0, NULL);
}
