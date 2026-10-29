#include "types.h"
#include <stdlib.h>
#include "pso/TMainTask.h"
#include "pso/math/AngleLookup.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/math/MatrixVector.h"
#include "pso/misc/TOKurage.h"
#include "pso/object/TObjFish.h"
#include "pso/object/TObjFish_8001ED90.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80141D1C.h"
#include "pso/player/TObjPlayer_803DF7A8.h"
#include "pso/player/TObjPlayer_803E4954.h"
#include "pso/render/model_render_state.h"
#include "pso/system/BmlResourceLoad.h"
#include "pso/system/ChunkMaterialColor.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/system/MatrixOps.h"
#include "pso/system/MatrixStack.h"
#include "pso/system/vector.h"
#include "pso/unk/text_800FD8A0.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/unk/text_803D96A8.h"

// normalize_vector (text_803D96A8, 133 callers) has no header yet: the files
// that use it declare it with conflicting return types.
extern "C" f32 normalize_vector(Vec *v);

const char *bm_fs_obj_kurage_model_names[] = {"fs_obj_kurage.nj", NULL};
const char *bm_fs_obj_kurage_motion_names[] = {"fs_obj_kurage.njm", "fs_obj_kurage.njs", NULL};
BmlResourceDescriptor bm_fs_obj_kurage_resource_descriptor = {
    "bm_fs_obj_kurage.bml", bm_fs_obj_kurage_model_names, bm_fs_obj_kurage_motion_names, 1, 2,
};
const char *TOKurage__class_name = "TOKurage";
BmlResource *TOKurage__bml_resource;

// Tilts the body toward this frame's movement (x by the z step, z by the
// x step), at most 0x40 a frame.
void TOKurage::update_tilt() {
    s32 old_rotation[3];
    copy_xyz(old_rotation, &rotation_x);
    rotation_x = (s32)(6000.0f * (position.z - prev_position.z));
    rotation_z = (s32)(-6000.0f * (position.x - prev_position.x));
    rotation_x = approach_angle_limited(old_rotation[0], rotation_x, 0x40);
    rotation_z = approach_angle_limited(old_rotation[2], rotation_z, 0x40);
}

void TOKurage::check_player_distance() {
    if ((xyz_distance(&home, &position) > scale.y) && (state != 4)) {
        state = 3;
    }
}

void TOKurage::update_state() {
    if (is_any_player_within_radius_xz(scale.x * scale.x) == 1) {
        state = 4;
    }
}

void TOKurage::debug_print_ranges() {
    if (is_current_room(this) == 1) {
        debug_printf_at(0x13001C, "VANISH_RENGE");
        debug_printf_at(0x13001D, "MOVE_RENGE");
        debug_printf_at(0x13001E, "REBIRTH_RENGE");
    }
}

void TOKurage::init() {
    VecCopy(&bob_base, &position);
    VecCopy(&home, &position);
    velocity.x = 0.0f;
    velocity.y = 0.0f;
    velocity.z = 0.0f;
    lift = 0.0f;
    state = 0;
    rising = 0;
    timer = 0x1E;
    bob_phase = 0;
    color.a = 1.0f;
    color.r = 1.0f;
    color.g = 1.0f;
    color.b = 1.0f;
}

void TOKurage::run_task() {
    f32 y;
    VecCopy(&prev_position, &position);
    if (TObjPlayer::check_demo_mode() == 1) {
        debug_print_ranges();
        return;
    }
    if (motion != 0) {
        update_anim_phase();
    }
    y = 3.2f * sin_table_lookup(bob_phase) + bob_base.y;
    if (rising == 0) {
        lift = 5.0f * (y - position.y);
        if (lift < 0.1f) {
            lift = 0.1f;
        } else if (lift > 4.0f) {
            lift = 4.0f;
        }
        bob_speed = 2.0f * (0.01f * lift) + 0.3f;
        velocity.y = 0.1f * (0.027f * lift) + velocity.y;
        velocity.y = velocity.y - 0.027f;
    } else {
        lift = -7.0f * (y - position.y);
        if (lift < 0.1f) {
            lift = 0.1f;
        } else if (lift > 4.0f) {
            lift = 4.0f;
        }
        bob_speed = 2.0f * (0.1f * lift) + 0.32f;
        velocity.y = velocity.y - 0.5f * (0.027f * lift);
        velocity.y = velocity.y - 0.027f;
        bob_pos = bob_pos + bob_speed;
        if (bob_pos > 5.0f) {
            bob_pos = 0.0f;
            rising = 0;
        }
    }
    switch (state) {
    case 0:
        velocity.x *= 0.8f;
        velocity.z *= 0.8f;
        break;
    case 1:
        if (rising == 0) {
            Vec dir;
            Vec out;
            dir.x = 2.0f * (0.0015f * (2.0f * (3.0517578125e-05f * (f32)rand()) - 1.0f));
            dir.y = 0.0f;
            dir.z = 2.0f * (0.0015f * (3.0517578125e-05f * (f32)rand())) + 0.05f;
            push_matrix_from(&identity_matrix);
            rotate_matrix_y(NULL, rotation_y);
            rotate_vector_by_matrix(NULL, &dir, &out);
            pop_matrices(1);
            velocity.x += out.x;
            velocity.z += out.z;
            velocity.x *= 0.72f;
            velocity.z *= 0.72f;
        } else {
            velocity.x *= 0.85f;
            velocity.z *= 0.85f;
        }
        break;
    case 2:
        if (turn_dir == 0) {
            rotation_y = (f32)rotation_y + (200.0f * (3.0517578125e-05f * (f32)rand()) + 200.0f);
        } else {
            rotation_y = (f32)rotation_y - (200.0f * (3.0517578125e-05f * (f32)rand()) + 200.0f);
        }
        if (rising == 0) {
            Vec dir;
            Vec out;
            dir.x = 2.0f * (0.025f * (2.0f * (3.0517578125e-05f * (f32)rand()) - 1.0f));
            dir.y = 0.0f;
            dir.z = 2.0f * (0.025f * (3.0517578125e-05f * (f32)rand())) + 0.05f;
            push_matrix_from(&identity_matrix);
            rotate_matrix_y(NULL, rotation_y);
            rotate_vector_by_matrix(NULL, &dir, &out);
            pop_matrices(1);
            velocity.x += out.x;
            velocity.z += out.z;
            velocity.x *= 0.85f;
            velocity.z *= 0.85f;
        } else {
            velocity.x *= 0.75f;
            velocity.z *= 0.75f;
        }
        break;
    case 3: {
        Vec d;
        VecCopy(&d, &home);
        subtract_vector(&d, &position);
        normalize_vector(&d);
        d.x /= 5.0f;
        d.y /= 5.0f;
        d.z /= 5.0f;
        VecCopy(&velocity, &d);
        if (xyz_distance(&home, &position) < scale.y / 5.0f) {
            state = 1;
        }
        break;
    }
    case 4: {
        Vec d;
        VecCopy(&d, &position);
        subtract_vector(&d, &home);
        normalize_vector(&d);
        d.x /= 5.0f;
        d.y /= 5.0f;
        d.z /= 5.0f;
        VecCopy(&velocity, &d);
        break;
    }
    }
    vec3_add_to(&position, &velocity);
    if (position.y > 12.0f + y) {
        position.y = 12.0f + y;
    } else if (position.y < y - 6.0f) {
        position.y = y - 6.0f;
    }
    if (timer != 0) {
        timer--;
    } else {
        switch (state) {
        case 0:
            state = 1;
            timer = 2.0f * (20.0f * (3.0517578125e-05f * (f32)rand())) + 20.0f;
            break;
        case 1:
            if (3.0517578125e-05f * (f32)rand() < 0.5f) {
                state = 2;
                timer = 50.0f * (3.0517578125e-05f * (f32)rand()) + 50.0f;
                if (3.0517578125e-05f * (f32)rand() < 0.5f) {
                    turn_dir = 0;
                } else {
                    turn_dir = 1;
                }
            } else {
                state = 0;
                timer = 30.0f * (3.0517578125e-05f * (f32)rand()) + 30.0f;
            }
            break;
        case 2:
            if (3.0517578125e-05f * (f32)rand() < 0.4f) {
                state = 2;
                timer = 50.0f * (3.0517578125e-05f * (f32)rand()) + 50.0f;
                if (3.0517578125e-05f * (f32)rand() < 0.5f) {
                    turn_dir = 0;
                } else {
                    turn_dir = 1;
                }
            } else {
                state = 1;
                timer = 2.0f * (30.0f * (3.0517578125e-05f * (f32)rand())) + 30.0f;
            }
            break;
        case 3:
            if (turn_dir == 0) {
                rotation_y = (f32)rotation_y + (200.0f * (3.0517578125e-05f * (f32)rand()) + 200.0f);
            } else {
                rotation_y = (f32)rotation_y - (200.0f * (3.0517578125e-05f * (f32)rand()) + 200.0f);
            }
            if (rising == 0) {
                push_matrix_from(&identity_matrix);
                rotate_matrix_y(NULL, rotation_y);
                pop_matrices(1);
            }
            if (xyz_distance(&home, &position) < scale.y / 5.0f) {
                state = 1;
            }
            break;
        case 4: {
            Vec d;
            VecCopy(&d, &position);
            subtract_vector(&d, &home);
            normalize_vector(&d);
            d.x /= 5.0f;
            d.y /= 5.0f;
            d.z /= 5.0f;
            VecCopy(&velocity, &d);
            break;
        }
        }
    }
    check_player_distance();
    update_state();
    update_tilt();
    bob_phase += (s32)(40.0f * (3.0517578125e-05f * (f32)rand()) + 160.0f);
}

void TOKurage::render() {
    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        post_translate_matrix(&position.x);
        rotate_matrix_zyx(NULL, rotation_x, rotation_y, rotation_z);
        TObjFish::set_global_param(texlist);
        switch (state) {
        case 4:
            saved_model_render_flags = model_render_flags;
            model_render_flags |= 0x10;
            if (color.a < 0.0f) {
                state = 3;
            } else {
                color.a -= 0.01f;
            }
            break;
        default:
            if (is_any_player_within_radius_xz(scale.z * scale.z) == 0 &&
                color.a < 0.0f) {
                color.a = 1.0f;
            }
            saved_model_render_flags = model_render_flags;
            model_render_flags |= 0x10;
            break;
        }
        set_constant_material(&color);
        TObjEneSlimeOne__sub_803E4B54(model, motion, motion2, m_b0);
        set_constant_material(&chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
        pop_matrix();
    }
}


void *TOKurage::create(void *set_data) {
    return new TOKurage(tl_05, set_data);
}

void TOKurage::destroy_static_instance() {
    if (TOKurage__bml_resource != NULL) {
        TLobby__sub_8001FE7C(TOKurage__bml_resource, 1);
        TOKurage__bml_resource = NULL;
    }
}

void TOKurage::load_static_resource() {
    BmlResource *resource = (BmlResource *)::operator new(0x440);
    if (resource != NULL) {
        resource = load_resource_from_descriptor(resource, 1, &bm_fs_obj_kurage_resource_descriptor, 0, 0, 0);
    }
    TOKurage__bml_resource = resource;
}

TOKurage::~TOKurage() {}

TOKurage::TOKurage(TObject *parent, void *set_data) : TObjMapObject(parent) {
    m_name = TOKurage__class_name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model(TOKurage__bml_resource, 0);
    texlist = TObjFish__sub_8001EDB0(TOKurage__bml_resource, 0);
    motion = get_bml_motion(TOKurage__bml_resource, 0);
    motion2 = get_bml_motion(TOKurage__bml_resource, 1);
    m_b8 = 0.5f;
    animation_end_frame = (f32)*(u32 *)((s8 *)motion + 4) - 1.0f;
    m_c0 = 500.0f;
    model_radius = 100.0f;
    init();
}
