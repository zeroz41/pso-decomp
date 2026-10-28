#include "types.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/misc/TOKey_8015845C.h"
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

struct VBase_18_26a62c { char pad[0x18]; };
struct VObj_18_26a62c : VBase_18_26a62c {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual s32 m8(f32, f32);
};

struct Vec_8016DB24 { f32 x, y, z; };

struct TOKurage_8016DB24 {
    u8 pad0[0x38];
    Vec_8016DB24 pos;
    Vec_8016DB24 prev;
    u8 pad50[0x10];
    s32 angle;
    u8 pad64[8];
    f32 radius;
    u8 pad70[0x4C];
    void *anim;
    u8 padC0[0x10];
    f32 baseY;
    u8 padD4[4];
    Vec_8016DB24 vel;
    Vec_8016DB24 home;
    f32 bobPos;
    f32 bobSpeed;
    f32 lift;
    s16 timer;
    s16 phase;
    u8 state;
    u8 rising;
    u8 turnDir;
};

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

struct RecoveredGlobal_8016E8A8___vt__8TOKurage { s32 value; u8 remaining[0x38]; };

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
extern RecoveredGlobal_8016E800_lbl_804B2E6C bm_fs_obj_kurage_resource_descriptor;
extern u32 TOKurage__static_model_resource;
u8 *get_bml_motion(s32, s32);
s32 TObjFish__sub_8001EDB0(int, int);
s32 get_bml_model(int, int);
extern s32 __vt__8TOKurage[];
extern s32 TOKurage__name;
s32 is_current_room(void *);
void debug_printf_at(s32 id, const char *fmt, ...);
extern const char lbl_80441EA0[];
extern const char lbl_80441EB0[];
extern const char lbl_80441EBC[];
void TLobby__sub_8001FE7C(void*, int);
s32 is_any_player_within_radius_xz(f32);
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(int);

void TOKurage::check_player_distance() {
    if ((xyz_distance((u8 *)&this->m_e4, (u8 *)&this->position) > this->target_scale) && ((u8) this->m_100 != 4)) {
        this->m_100 = 3U;
    }
}

void TOKurage::update_state() {
    f32 temp_f0;

    temp_f0 = this->scale;
    if (is_any_player_within_radius_xz(temp_f0 * temp_f0) == 1) {
        this->m_100 = 4;
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
    VecCopy((Vec *)&this->_padCC, (const Vec *)&this->position);
    VecCopy((Vec *)&this->m_e4, (const Vec *)&this->position);
    *(f32 *)&this->m_d8 = (f32) (0.0f);
    *(f32 *)&this->unk_DC = (f32) (0.0f);
    this->m_e0 = (f32) (0.0f);
    this->m_f8 = (f32) (0.0f);
    this->m_100 = 0;
    this->m_101 = 0;
    this->m_fc = 0x1E;
    this->m_fe = 0;
    *(f32 *)&this->m_104 = (f32) (1.0f);
    *(f32 *)&this->unk_108 = (f32) (1.0f);
    this->m_10c = (f32) (1.0f);
    *(f32 *)&this->unk_110 = (f32) (1.0f);
}

#pragma push
#pragma fp_contract on
void TOKurage::run_task() {
    TOKurage_8016DB24 *o = (TOKurage_8016DB24 *)this;
    f32 y;
    VecCopy((Vec *)&o->prev, (const Vec *)&o->pos);
    if (TObjPlayer::check_demo_mode() == 1) {
        debug_print_ranges();
        return;
    }
    if (o->anim != 0) {
        ((TUnk_804AFBF8 *)o)->update_anim_phase();
    }
    y = 3.2f * sin_table_lookup(o->phase) + o->baseY;
    if (o->rising == 0) {
        o->lift = 5.0f * (y - o->pos.y);
        if (o->lift < 0.1f) {
            o->lift = 0.1f;
        } else if (o->lift > 4.0f) {
            o->lift = 4.0f;
        }
        o->bobSpeed = 2.0f * (0.01f * o->lift) + 0.3f;
        o->vel.y = 0.1f * (0.027f * o->lift) + o->vel.y;
        o->vel.y = o->vel.y - 0.027f;
    } else {
        o->lift = -7.0f * (y - o->pos.y);
        if (o->lift < 0.1f) {
            o->lift = 0.1f;
        } else if (o->lift > 4.0f) {
            o->lift = 4.0f;
        }
        o->bobSpeed = 2.0f * (0.1f * o->lift) + 0.32f;
        o->vel.y = o->vel.y - 0.5f * (0.027f * o->lift);
        o->vel.y = o->vel.y - 0.027f;
        o->bobPos = o->bobPos + o->bobSpeed;
        if (o->bobPos > 5.0f) {
            o->bobPos = 0.0f;
            o->rising = 0;
        }
    }
    switch (o->state) {
    case 0:
        o->vel.x *= 0.8f;
        o->vel.z *= 0.8f;
        break;
    case 1:
        if (o->rising == 0) {
            Vec_8016DB24 dir;
            Vec_8016DB24 out;
            dir.x = 2.0f * (0.0015f * (2.0f * (3.0517578125e-05f * (f32)rand()) - 1.0f));
            dir.y = 0.0f;
            dir.z = 2.0f * (0.0015f * (3.0517578125e-05f * (f32)rand())) + 0.05f;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, o->angle);
            rotate_vector_by_matrix(0, &dir, &out);
            pop_matrices(1);
            o->vel.x += out.x;
            o->vel.z += out.z;
            o->vel.x *= 0.72f;
            o->vel.z *= 0.72f;
        } else {
            o->vel.x *= 0.85f;
            o->vel.z *= 0.85f;
        }
        break;
    case 2:
        if (o->turnDir == 0) {
            o->angle = (f32)o->angle + (200.0f * (3.0517578125e-05f * (f32)rand()) + 200.0f);
        } else {
            o->angle = (f32)o->angle - (200.0f * (3.0517578125e-05f * (f32)rand()) + 200.0f);
        }
        if (o->rising == 0) {
            Vec_8016DB24 dir;
            Vec_8016DB24 out;
            dir.x = 2.0f * (0.025f * (2.0f * (3.0517578125e-05f * (f32)rand()) - 1.0f));
            dir.y = 0.0f;
            dir.z = 2.0f * (0.025f * (3.0517578125e-05f * (f32)rand())) + 0.05f;
            push_matrix_from(identity_matrix);
            rotate_matrix_y(0, o->angle);
            rotate_vector_by_matrix(0, &dir, &out);
            pop_matrices(1);
            o->vel.x += out.x;
            o->vel.z += out.z;
            o->vel.x *= 0.85f;
            o->vel.z *= 0.85f;
        } else {
            o->vel.x *= 0.75f;
            o->vel.z *= 0.75f;
        }
        break;
    case 3: {
        Vec_8016DB24 d;
        VecCopy((Vec *)&d, (const Vec *)&o->home);
        subtract_vector(&d, &o->pos);
        normalize_vector(&d);
        d.x /= 5.0f;
        d.y /= 5.0f;
        d.z /= 5.0f;
        VecCopy((Vec *)&o->vel, (const Vec *)&d);
        if (xyz_distance(&o->home, &o->pos) < o->radius / 5.0f) {
            o->state = 1;
        }
        break;
    }
    case 4: {
        Vec_8016DB24 d;
        VecCopy((Vec *)&d, (const Vec *)&o->pos);
        subtract_vector(&d, &o->home);
        normalize_vector(&d);
        d.x /= 5.0f;
        d.y /= 5.0f;
        d.z /= 5.0f;
        VecCopy((Vec *)&o->vel, (const Vec *)&d);
        break;
    }
    }
    vec3_add_to(&o->pos, &o->vel);
    if (o->pos.y > 12.0f + y) {
        o->pos.y = 12.0f + y;
    } else if (o->pos.y < y - 6.0f) {
        o->pos.y = y - 6.0f;
    }
    if (o->timer != 0) {
        o->timer--;
    } else {
        switch (o->state) {
        case 0:
            o->state = 1;
            o->timer = 2.0f * (20.0f * (3.0517578125e-05f * (f32)rand())) + 20.0f;
            break;
        case 1:
            if (3.0517578125e-05f * (f32)rand() < 0.5f) {
                o->state = 2;
                o->timer = 50.0f * (3.0517578125e-05f * (f32)rand()) + 50.0f;
                if (3.0517578125e-05f * (f32)rand() < 0.5f) {
                    o->turnDir = 0;
                } else {
                    o->turnDir = 1;
                }
            } else {
                o->state = 0;
                o->timer = 30.0f * (3.0517578125e-05f * (f32)rand()) + 30.0f;
            }
            break;
        case 2:
            if (3.0517578125e-05f * (f32)rand() < 0.4f) {
                o->state = 2;
                o->timer = 50.0f * (3.0517578125e-05f * (f32)rand()) + 50.0f;
                if (3.0517578125e-05f * (f32)rand() < 0.5f) {
                    o->turnDir = 0;
                } else {
                    o->turnDir = 1;
                }
            } else {
                o->state = 1;
                o->timer = 2.0f * (30.0f * (3.0517578125e-05f * (f32)rand())) + 30.0f;
            }
            break;
        case 3:
            if (o->turnDir == 0) {
                o->angle = (f32)o->angle + (200.0f * (3.0517578125e-05f * (f32)rand()) + 200.0f);
            } else {
                o->angle = (f32)o->angle - (200.0f * (3.0517578125e-05f * (f32)rand()) + 200.0f);
            }
            if (o->rising == 0) {
                push_matrix_from(identity_matrix);
                rotate_matrix_y(0, o->angle);
                pop_matrices(1);
            }
            if (xyz_distance(&o->home, &o->pos) < o->radius / 5.0f) {
                o->state = 1;
            }
            break;
        case 4: {
            Vec_8016DB24 d;
            VecCopy((Vec *)&d, (const Vec *)&o->pos);
            subtract_vector(&d, &o->home);
            normalize_vector(&d);
            d.x /= 5.0f;
            d.y /= 5.0f;
            d.z /= 5.0f;
            VecCopy((Vec *)&o->vel, (const Vec *)&d);
            break;
        }
        }
    }
    check_player_distance();
    update_state();
    ((TOKurage *)o)->sub_8016D8F8();
    o->phase += (s32)(40.0f * (3.0517578125e-05f * (f32)rand()) + 160.0f);
}
#pragma pop

void TOKurage::render() {
    u8 *arg0 = (u8 *)this;
    if (((VObj_18_26a62c *)(arg0))->m8(*(f32 *)(arg0 + 0xC0), *(f32 *)(arg0 + 0xC4)) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_zyx(0, *(s32 *)(arg0 + 0x5C), *(s32 *)(arg0 + 0x60), *(s32 *)(arg0 + 0x64));
        TObjFish::set_global_param(*(s32 *)(arg0 + 0x24));
        switch (*(u8 *)(arg0 + 0x100)) {
        case 4:
            saved_model_render_flags = model_render_flags;
            model_render_flags |= 0x10;
            if (*(f32 *)(arg0 + 0x104) < (0.0f)) {
                *(u8 *)(arg0 + 0x100) = 3;
            } else {
                *(f32 *)(arg0 + 0x104) -= (0.01f);
            }
            break;
        default:
            if (((s32 (*)(void *, f32))is_any_player_within_radius_xz)(arg0, *(f32 *)(arg0 + 0x70) * *(f32 *)(arg0 + 0x70)) == 0 &&
                *(f32 *)(arg0 + 0x104) < (0.0f)) {
                *(f32 *)(arg0 + 0x104) = (1.0f);
            }
            saved_model_render_flags = model_render_flags;
            model_render_flags |= 0x10;
            break;
        }
        set_constant_material((const NJS_ARGB *)(((f32 *)&this->m_104)));
        TObjEneSlimeOne__sub_803E4B54((void *)(*(s32 *)(arg0 + 0x34)), (void *)(*(s32 *)(arg0 + 0xBC)), (void *)(*(s32 *)(arg0 + 0xC8)), *(f32 *)(arg0 + 0xB0));
        set_constant_material((const NJS_ARGB *)chunk_material_color_half_alpha_f32);
        model_render_flags = saved_model_render_flags;
        pop_matrix();
    }
}

extern void *tl_05;

void *TOKurage::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0x114);
    if (o != NULL) {
        o = TOKurage__ct((TOKurage *)((u8 *)o), (s32)tl_05, (s32)arg0);
    }
    return o;
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

void *__dt__8TOKurageFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__8TOKurage;
        ((TUnk_804AFBF8 *)arg0)->destroy_key_base(0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}
u8 *TOKurage__ct(TOKurage *arg0, s32 arg1, s32 arg2) {
    init_map_object_base((arg0));
    *(s32 **)((s8 *)arg0 + 0x18) = &(*(RecoveredGlobal_8016E8A8___vt__8TOKurage *)&__vt__8TOKurage).value;
    *(s32 *)((s8 *)arg0 + 0) = (s32) TOKurage__name;
    ((TOKurage *)(arg0))->apply_object_set_data((void *)arg2);
    *(s32 *)((s8 *)arg0 + 0x34) = get_bml_model((int) ((*(s32 *)&TOKurage__static_model_resource)), 0);
    arg0->texture_id = TObjFish__sub_8001EDB0((int) ((*(s32 *)&TOKurage__static_model_resource)), 0);
    *(u8 **)((s8 *)arg0 + 0xBC) = get_bml_motion((*(s32 *)&TOKurage__static_model_resource), 0);
    *(u8 **)((s8 *)arg0 + 0xC8) = get_bml_motion((*(s32 *)&TOKurage__static_model_resource), 1);
    arg0->m_b8 = (f32) (0.5f);
    *(f32 *)((s8 *)arg0 + 0xB4) = (f32) ((f32) *(u32 *)((s8 *)(*(u8 **)((s8 *)arg0 + 0xBC)) + 4) - (1.0f));
    arg0->m_c0 = (f32) (5e+02f);
    *(f32 *)((s8 *)arg0 + 0xC4) = (f32) (1e+02f);
    arg0->init();
    return (u8 *)arg0;
}

}
