#include "types.h"
#include "pso/misc/MaterialColorFade.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_803D853C.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/misc/TUnk_804AFBF8.h"
#include "pso/misc/TOKurage.h"
#include "pso/misc/TOBarrierEnergy01.h"
#include "pso/misc/TOKey.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/TAdSinglePlyChrSelectGC.h"

struct RecoveredGlobal_8016E800_lbl_804B2E6C { s32 value; u8 remaining[0xC]; };
typedef char RecoveredGlobal_8016E800_lbl_804B2E6C_size[sizeof(RecoveredGlobal_8016E800_lbl_804B2E6C) == 0x10 ? 1 : -1];

extern "C" {
void push_matrix(void);
void post_translate_matrix(void *);
void TObjEneSlimeOne__sub_803E4B54(void *child, void *arg1, void *arg2, f32 farg0);
extern u8 chunk_material_color_half_alpha_f32[];
extern s32 saved_model_render_flags;
extern s32 model_render_flags;
s32 rand(void);
f32 sin_table_lookup(s32);
s32 vec3_add_to(void *, void *);
s32 rotate_vector_by_matrix(int, void *, void *);
s32 rotate_matrix_y(int, int);
s32 subtract_vector(void *, void *);
s32 normalize_vector(void *);
f32 xyz_distance(void *, void *);
extern u8 identity_matrix[];
}

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8016E800_lbl_804B2E6C bm_fs_obj_kurage_resource_descriptor;
extern u32 TOKurage__static_model_resource;
u8 *get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
extern s32 TOKurage__name;
s32 is_current_room(void *);
void debug_printf_at(s32 id, const char *fmt, ...);
extern const char lbl_80441EA0[];
extern const char lbl_80441EB0[];
extern const char lbl_80441EBC[];
void TLobby__sub_8001FE7C(void*, int);
}

void TOKurage::check_player_distance() {
    if ((xyz_distance((u8 *)&this->home, (u8 *)&this->position) > this->scale.y) && ((u8) this->state != 4)) {
        this->state = 3U;
    }
}

void TOKurage::update_state() {
    f32 temp_f0;

    temp_f0 = this->scale.x;
    if (is_any_player_within_radius_xz(temp_f0 * temp_f0) == 1) {
        this->state = 4;
    }
}

void TOKurage::debug_print_ranges() {
    if (is_current_room(this) == 1) {
        debug_printf_at(0x13001C, lbl_80441EA0);
        debug_printf_at(0x13001D, lbl_80441EB0);
        debug_printf_at(0x13001E, lbl_80441EBC);
    }
}

void TOKurage::init() {
    VecCopy(&this->bob_base, &this->position);
    VecCopy(&this->home, &this->position);
    this->velocity.x = (f32) (0.0f);
    this->velocity.y = (f32) (0.0f);
    this->velocity.z = (f32) (0.0f);
    this->lift = (f32) (0.0f);
    this->state = 0;
    this->rising = 0;
    this->timer = 0x1E;
    this->bob_phase = 0;
    this->color[0] = (f32) (1.0f);
    this->color[1] = (f32) (1.0f);
    this->color[2] = (f32) (1.0f);
    this->color[3] = (f32) (1.0f);
}

#pragma push
#pragma fp_contract on
void TOKurage::run_task() {
    f32 y;
    VecCopy((Vec *)&prev_position, (const Vec *)&position);
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
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, rotation_y);
            rotate_vector_by_matrix(0, &dir, &out);
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
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, rotation_y);
            rotate_vector_by_matrix(0, &dir, &out);
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
        VecCopy((Vec *)&d, (const Vec *)&home);
        subtract_vector(&d, &position);
        normalize_vector(&d);
        d.x /= 5.0f;
        d.y /= 5.0f;
        d.z /= 5.0f;
        VecCopy((Vec *)&velocity, (const Vec *)&d);
        if (xyz_distance(&home, &position) < scale.y / 5.0f) {
            state = 1;
        }
        break;
    }
    case 4: {
        Vec d;
        VecCopy((Vec *)&d, (const Vec *)&position);
        subtract_vector(&d, &home);
        normalize_vector(&d);
        d.x /= 5.0f;
        d.y /= 5.0f;
        d.z /= 5.0f;
        VecCopy((Vec *)&velocity, (const Vec *)&d);
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
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, rotation_y);
                pop_matrices(1);
            }
            if (xyz_distance(&home, &position) < scale.y / 5.0f) {
                state = 1;
            }
            break;
        case 4: {
            Vec d;
            VecCopy((Vec *)&d, (const Vec *)&position);
            subtract_vector(&d, &home);
            normalize_vector(&d);
            d.x /= 5.0f;
            d.y /= 5.0f;
            d.z /= 5.0f;
            VecCopy((Vec *)&velocity, (const Vec *)&d);
            break;
        }
        }
    }
    check_player_distance();
    update_state();
    sub_8016D8F8();
    bob_phase += (s32)(40.0f * (3.0517578125e-05f * (f32)rand()) + 160.0f);
}
#pragma pop

void TOKurage::render() {
    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_zyx(0, rotation_x, rotation_y, rotation_z);
        TObjFish::set_global_param(texlist);
        switch (state) {
        case 4:
            saved_model_render_flags = model_render_flags;
            model_render_flags |= 0x10;
            if (color[0] < (0.0f)) {
                state = 3;
            } else {
                color[0] -= (0.01f);
            }
            break;
        default:
            if (is_any_player_within_radius_xz(scale.z * scale.z) == 0 &&
                color[0] < (0.0f)) {
                color[0] = (1.0f);
            }
            saved_model_render_flags = model_render_flags;
            model_render_flags |= 0x10;
            break;
        }
        set_constant_material((const NJS_ARGB *)&this->color[0]);
        TObjEneSlimeOne__sub_803E4B54(model, (void *)(m_bc), (void *)(motion2), m_b0);
        set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
        pop_matrix();
    }
}

extern void *tl_05;

void *TOKurage::create(void *arg0) {
    return new TOKurage((TObject *)tl_05, arg0);
}

void TOKurage::destroy_static_instance() {
    if ((u32) TOKurage__static_model_resource != 0U) {
        TLobby__sub_8001FE7C((void*)TOKurage__static_model_resource, 1);
        TOKurage__static_model_resource = 0U;
    }
}

void TOKurage::load_static_resource() {
    s32 temp_r3;
    s32 var_r0;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_fs_obj_kurage_resource_descriptor.value, 0, 0, 0));
    }
    (*(s32 *)&TOKurage__static_model_resource) = var_r0;
}

// The destructor is still written out by hand: compiled, its vtable would
// open the unit's .data, which the original fills first with the object's
// resource and collision tables (not owned by this unit yet).
extern "C" {
extern void *__vt__8TOKurage[];
void __dl__7TObjectFPv(void *);

void *__dt__8TOKurageFv(void *self, s16 del) {
    if (self != NULL) {
        *(void **)((u8 *)self + 0x18) = __vt__8TOKurage;

        __dt__13TUnk_804AFBF8Fv(self, 0);
        if (del > 0) {
            __dl__7TObjectFPv(self);
        }
    }
    return self;
}
}

TOKurage::TOKurage(TObject *parent, void *set_data) : TUnk_804AFBF8(parent) {
    m_name = (const char *)TOKurage__name;
    apply_object_set_data(set_data);
    model = (void *)get_bml_model((int) ((*(s32 *)&TOKurage__static_model_resource)), 0);
    texlist = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TOKurage__static_model_resource)), 0);
    motion = (AnimationMotion *)get_bml_motion((*(s32 *)&TOKurage__static_model_resource), 0);
    motion2 = (u32)get_bml_motion((*(s32 *)&TOKurage__static_model_resource), 1);
    m_b8 = (f32) (0.5f);
    animation_end_frame = (f32) ((f32) *(u32 *)((s8 *)motion + 4) - (1.0f));
    m_c0 = (f32) (5e+02f);
    model_radius = (f32) (1e+02f);
    init();
}
