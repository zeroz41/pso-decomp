#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/render/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/system/BmlResourceDescriptor.h"
#include "pso/object/TObjChip.h"
#include "pso/object/wreck/TOWreckAncient.h"
#include "pso/object/wreck/TOWreckAncient01.h"
#include "pso/object/wreck/TOWreckAncient04.h"
#include "pso/object/wreck/TOWreckAncient05.h"
#include "pso/object/wreck/TOWreckAncient06.h"
#include "pso/object/wreck/TOWreckAncient07.h"
#include "pso/object/wreck/TOWreckAncientBrakable.h"
#include "pso/object/wreck/TOWreckAncientBrakable05.h"
#include "pso/object/wreck/TOWreckAncientBrakable_8017D444.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"
#include "pso/system/task/TObject.h"

// The wreck family is one TU built with -inline off,deferred: its code runs Brakable05, Brakable, 07, 06, 05,
// 04, 01, TOWreckAncient while its strings, name pointers and vtables run the other way, so the source is
// written last function first.

struct Base1_8017dce0 { char pad[0x18]; };
struct VObj1_8017dce0 : Base1_8017dce0 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

struct RecoveredGlobal_8017DE94___vt__14TOWreckAncient {
    s32 value;
    u8 remaining[0x38];
};
typedef char RecoveredGlobal_8017DE94___vt__14TOWreckAncient_size[sizeof(RecoveredGlobal_8017DE94___vt__14TOWreckAncient) == 0x3C ? 1 : -1];

struct Vec_8017D448 { f32 x, y, z; };

struct Arr_8017D448 { Vec_8017D448 v[9]; };

// Same layout as TObjChipParams (TObjChip.h).
struct Param_8017D448 {
    f32 f0;
    f32 f4;
    f32 f8;
    Vec_8017D448 pos;
    f32 f18[3];
    s32 f24[3];
    s32 f30[2];
    f32 f38;
    f32 f3c;
    s32 f40;
    s32 f44;
    s32 f48;
};

const char *bm_o_wreck_ancient_model_names[8] = {
    "fe_obj_o_zangai02.gj",
    "fe_obj_o_zangai01.gj",
    "fe_obj_o_zangai03.gj",
    "fe_obj_o_zangai05.gj",
    "fe_obj_o_zangai04.gj",
    "fe_obj_o_zangai07.gj",
    "fe_obj_o_zangai06.gj",
    NULL,
};
const char *bm_o_wreck_ancient_motion_names[1] = {NULL};
BmlResourceDescriptor bm_o_wreck_ancient_resource_descriptor = {
    "bm_o_wreck_ancient.bml", bm_o_wreck_ancient_model_names, bm_o_wreck_ancient_motion_names, 7, 0,
};
const char *bm_fe_obj_o_hahen_model_names[10] = {
    "fe_obj_o_hahen01.gj",
    "fe_obj_o_hahen02.gj",
    "fe_obj_o_hahen03.gj",
    "fe_obj_o_hahen04.gj",
    "fe_obj_o_hahen05.gj",
    "fe_obj_o_hahen06.gj",
    "fe_obj_o_hahen07.gj",
    "fe_obj_o_hahen08.gj",
    "fe_obj_o_hahen09.gj",
    NULL,
};
const char *bm_fe_obj_o_hahen_motion_names[1] = {NULL};
BmlResourceDescriptor TOWreckAncient__resource_descriptor = {
    "bm_fe_obj_o_hahen.bml", bm_fe_obj_o_hahen_model_names, bm_fe_obj_o_hahen_motion_names, 9, 0,
};
const char *TOWreckAncient__name = "TOWreckAncient";

// One sphere per wreck model: the subclass passes its model's entry (TOWreckAncient02/03 use it too).
CollisionBody TOWreckAncient__collision_body_templates[7] = {
    { { 0.0f, 0.0f, 0.0f }, 20.0f, 0.0f, 0, 0x10003 },
    { { 0.0f, 0.0f, 0.0f }, 12.0f, 0.0f, 0, 0x10003 },
    { { 0.0f, 0.0f, 0.0f }, 30.0f, 0.0f, 0, 0x10003 },
    { { 0.0f, 0.0f, 0.0f }, 17.0f, 0.0f, 0, 0x10003 },
    { { 0.0f, 0.0f, 0.0f }, 23.0f, 0.0f, 0, 0x10003 },
    { { 0.0f, 0.0f, 0.0f }, 18.0f, 0.0f, 0, 0x10003 },
    { { 0.0f, 0.0f, 0.0f }, 15.0f, 0.0f, 0, 0x10003 },
};

const char *TOWreckAncient01__name = "TOWreckAncient01";
const char *TOWreckAncient04__name = "TOWreckAncient04";
const char *TOWreckAncient05__name = "TOWreckAncient05";
const char *TOWreckAncient06__name = "TOWreckAncient06";
const char *TOWreckAncient07__name = "TOWreckAncient07";
const char *TOWreckAncientBrakable__name = "TOWreckAncientBrakable";
const char *TOWreckAncientBrakable05__name = "TOWreckAncientBrakable05";

const Arr_8017D448 TOWreckAncientBrakable__debris_table = {
    {
        { -7.0f, 12.0f, 9.0f },
        { 0.0f, 25.0f, -5.0f },
        { -8.0f, 12.0f, -6.0f },
        { -8.0f, 27.0f, 5.0f },
        { 8.0f, 14.0f, -6.0f },
        { 8.0f, 15.0f, 9.0f },
        { 4.0f, 30.0f, 9.0f },
        { -7.0f, 32.0f, 4.0f },
        { 3.0f, 29.0f, -1.0f },
    }
};

const Param_8017D448 TOWreckAncientBrakable__debris_param_table = {
    0.25f, 0.07f, 0.26f,
    { 0.0f, 0.0f, 0.0f },
    { 5.0f, 7.5f, 5.0f },
    { 0x400, 0x100, 0x400 },
    { 1, 30 },
    0.0f, 0.6f,
    0, 0, 30,
};

u32 wreck_ancient_bml_resource;
u32 wreck_ancient_brakable_bml_resource;

extern "C" {
u8 * load_resource_from_descriptor(void *, s32, void *, s32, s32, s32);
s32 __ct__14TObjCollidableFP7TObject(void *, int);
s32 TObjFish__sub_8001EDB0(void *, s32);
s32 get_bml_model(void *, s32);
extern s32 __vt__14TOWreckAncient[];
extern s32 __vt__16TOWreckAncient01[];
extern s32 __vt__16TOWreckAncient04[];
extern s32 __vt__16TOWreckAncient05[];
extern s32 __vt__16TOWreckAncient06[];
extern s32 __vt__16TOWreckAncient07[];
extern s32 __vt__22TOWreckAncientBrakable[];
extern s32 __vt__24TOWreckAncientBrakable05[];
extern s32 tl_05;
u8 *TOWreckAncient__ct(u8 *arg0, s32 arg1);
void *__dt__14TOWreckAncientFv(void *arg0, s16 arg1);
void *TOWreckAncientBrakable__ct(TOWreckAncientBrakable *arg0, s32 arg1);
void *__dt__22TOWreckAncientBrakableFv(void *arg0, s16 arg1);
void *TOWreckAncientBrakable05__create(void *arg0);
void *__dt__24TOWreckAncientBrakable05Fv(void *arg0, s16 arg1);
u8 *TOWreckAncient04__ct(u8 *wreck_ancient, s32 arg1);
u8 *TOWreckAncient05__ct(u8 *wreck_ancient, s32 arg1);
u8 *TOWreckAncient06__ct(u8 *wreck_ancient, s32 arg1);
u8 *TOWreckAncient07__ct(u8 *wreck_ancient, s32 arg1);
void free_bin_model_request(void*, int);
s32 post_translate_matrix(void *);
s32 free_collision_body_parts(void *);
s32 init_collision_body_parts(void *, CollisionBody *, s32);
s32 push_matrix();
void __dl__7TObjectFPv(void *);
void *__nw__7TObjectFUl(u32);
void vec3_add_to(Vec_8017D448 *, Vec_8017D448 *);
void rotate_vector_by_matrix(int, Vec_8017D448 *, Vec_8017D448 *);
extern u8 identity_matrix[];
u8 is_current_floor_switch_set(u16);
}

// --- TOWreckAncient ---

u8 *TOWreckAncient__ct(u8 *wreck_ancient, s32 arg1) {
    __ct__14TObjCollidableFP7TObject(wreck_ancient, tl_05);
    *(s32 **)((s8 *)wreck_ancient + 0x18) = &(*(RecoveredGlobal_8017DE94___vt__14TOWreckAncient *)&__vt__14TOWreckAncient).value;
    *(s32 *)((s8 *)wreck_ancient + 0) = (s32) TOWreckAncient__name;
    *(s32 *)((s8 *)wreck_ancient + 0x34) = get_bml_model((void *) wreck_ancient_bml_resource, arg1);
    ((TOWreckAncient *)wreck_ancient)->texlist = TObjFish__sub_8001EDB0((void *) wreck_ancient_bml_resource, arg1);
    *(f32 *)((s8 *)wreck_ancient + 0xAC) = 400.0f;
    ((TOWreckAncient *)wreck_ancient)->m_b0 = 40.0f;
    return wreck_ancient;
}

void *__dt__14TOWreckAncientFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__14TOWreckAncient;
        ((TObjCollidable *)arg0)->unregister_object_by_id();
        free_collision_body_parts(arg0);
        __dt__14TObjCollidableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TOWreckAncient::load_resources() {
    s32 temp_r3;
    s32 temp_r3_2;
    s32 var_r0;
    s32 var_r0_2;
    temp_r3 = (int)::operator new(0x440);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = (long) (load_resource_from_descriptor((void *) temp_r3, 1, &bm_o_wreck_ancient_resource_descriptor, 0, 0, 0));
    }
    wreck_ancient_bml_resource = var_r0;
    temp_r3_2 = (int)::operator new(0x440);
    var_r0_2 = temp_r3_2;
    if (var_r0_2 != 0) {
        var_r0_2 = (long) (load_resource_from_descriptor((void *) temp_r3_2, 1, &TOWreckAncient__resource_descriptor, 0, 0, 0));
    }
    wreck_ancient_brakable_bml_resource = var_r0_2;
}

void TOWreckAncient::free_statics() {
    if (wreck_ancient_bml_resource != 0U) {
        free_bin_model_request((void*)wreck_ancient_bml_resource, 1);
        wreck_ancient_bml_resource = 0U;
    }
    if (wreck_ancient_brakable_bml_resource != 0U) {
        free_bin_model_request((void*)wreck_ancient_brakable_bml_resource, 1);
        wreck_ancient_brakable_bml_resource = 0U;
    }
}

void TOWreckAncient::render() {
    u8 *arg0 = (u8 *)this;
    VObj1_8017dce0 *self = (VObj1_8017dce0 *)arg0;
    if (self->m8(*(f32 *)&this->unk_AC, this->m_b0) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object(this->model);
        pop_matrix();
    }
}

// --- TOWreckAncient01 ---

u8 *TOWreckAncient01__ct(u8 *wreck_ancient, s32 arg1) {
    TOWreckAncient__ct(wreck_ancient, 1);
    *(s32 **)((s8 *)wreck_ancient + 0x18) = __vt__16TOWreckAncient01;
    *(s32 *)((s8 *)wreck_ancient + 0) = (s32) TOWreckAncient01__name;
    ((TOWreckAncient01 *)(wreck_ancient))->apply_object_set_data((void *)arg1);
    init_collision_body_parts(wreck_ancient, &TOWreckAncient__collision_body_templates[1], 1);
    ((TObjPlayer *)wreck_ancient)->register_object_by_id();
    return wreck_ancient;
}

void *__dt__16TOWreckAncient01Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TOWreckAncient01;
        __dt__14TOWreckAncientFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TOWreckAncient01__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB4);
    if (o != NULL) {
        o = TOWreckAncient01__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

// --- TOWreckAncient04 ---

u8 *TOWreckAncient04__ct(u8 *wreck_ancient, s32 arg1) {
    TOWreckAncient__ct(wreck_ancient, 4);
    *(s32 **)((s8 *)wreck_ancient + 0x18) = __vt__16TOWreckAncient04;
    *(s32 *)((s8 *)wreck_ancient + 0) = (s32) TOWreckAncient04__name;
    ((TOWreckAncient04 *)(wreck_ancient))->apply_object_set_data((void *)arg1);
    init_collision_body_parts(wreck_ancient, &TOWreckAncient__collision_body_templates[4], 1);
    ((TObjPlayer *)wreck_ancient)->register_object_by_id();
    return wreck_ancient;
}

void *__dt__16TOWreckAncient04Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TOWreckAncient04;
        __dt__14TOWreckAncientFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TOWreckAncient04__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB4);
    if (o != NULL) {
        o = TOWreckAncient04__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

// --- TOWreckAncient05 ---

u8 *TOWreckAncient05__ct(u8 *wreck_ancient, s32 arg1) {
    TOWreckAncient__ct(wreck_ancient, 3);
    *(s32 **)((s8 *)wreck_ancient + 0x18) = __vt__16TOWreckAncient05;
    *(s32 *)((s8 *)wreck_ancient + 0) = (s32) TOWreckAncient05__name;
    ((TOWreckAncient05 *)(wreck_ancient))->apply_object_set_data((void *)arg1);
    init_collision_body_parts(wreck_ancient, &TOWreckAncient__collision_body_templates[3], 1);
    ((TObjPlayer *)wreck_ancient)->register_object_by_id();
    return wreck_ancient;
}

void *__dt__16TOWreckAncient05Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TOWreckAncient05;
        __dt__14TOWreckAncientFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TOWreckAncient05__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB4);
    if (o != NULL) {
        o = TOWreckAncient05__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

// --- TOWreckAncient06 ---

u8 *TOWreckAncient06__ct(u8 *wreck_ancient, s32 arg1) {
    TOWreckAncient__ct(wreck_ancient, 6);
    *(s32 **)((s8 *)wreck_ancient + 0x18) = __vt__16TOWreckAncient06;
    *(s32 *)((s8 *)wreck_ancient + 0) = (s32) TOWreckAncient06__name;
    ((TOWreckAncient06 *)(wreck_ancient))->apply_object_set_data((void *)arg1);
    init_collision_body_parts(wreck_ancient, &TOWreckAncient__collision_body_templates[6], 1);
    ((TObjPlayer *)wreck_ancient)->register_object_by_id();
    return wreck_ancient;
}

void *__dt__16TOWreckAncient06Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TOWreckAncient06;
        __dt__14TOWreckAncientFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TOWreckAncient06__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB4);
    if (o != NULL) {
        o = TOWreckAncient06__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

// --- TOWreckAncient07 ---

u8 *TOWreckAncient07__ct(u8 *wreck_ancient, s32 arg1) {
    TOWreckAncient__ct(wreck_ancient, 5);
    *(s32 **)((s8 *)wreck_ancient + 0x18) = __vt__16TOWreckAncient07;
    *(s32 *)((s8 *)wreck_ancient + 0) = (s32) TOWreckAncient07__name;
    ((TOWreckAncient07 *)(wreck_ancient))->apply_object_set_data((void *)arg1);
    init_collision_body_parts(wreck_ancient, &TOWreckAncient__collision_body_templates[5], 1);
    ((TObjPlayer *)wreck_ancient)->register_object_by_id();
    return wreck_ancient;
}

void *__dt__16TOWreckAncient07Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TOWreckAncient07;
        __dt__14TOWreckAncientFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TOWreckAncient07__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xB4);
    if (o != NULL) {
        o = TOWreckAncient07__ct((u8 *)o, (s32)arg0);
    }
    return o;
}

// --- TOWreckAncientBrakable ---


void *TOWreckAncientBrakable__ct(TOWreckAncientBrakable *wreck_ancient_brakable, s32 model) {
    TOWreckAncient__ct((u8 *)wreck_ancient_brakable, model);
    *(s32 **)((s8 *)wreck_ancient_brakable + 0x18) = __vt__22TOWreckAncientBrakable;
    wreck_ancient_brakable->m_name = TOWreckAncientBrakable__name;
    wreck_ancient_brakable->m_b4 = 0;
    wreck_ancient_brakable->m_b8 = -1;
    return wreck_ancient_brakable;
}

void *__dt__22TOWreckAncientBrakableFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__22TOWreckAncientBrakable;
        __dt__14TOWreckAncientFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void TOWreckAncientBrakable::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0_2;

    if (TObjPlayer::check_demo_mode() == 1) {
        TOWreckAncientBrakable__sub_8017D444(arg0);
        return;
    }
    switch (this->m_b4) {
    default:
        this->m_b4 = 0;
    case 0:
        temp_r0_2 = this->m_b8;
        if ((temp_r0_2 >= 0) && (temp_r0_2 < 0x100) && (is_current_floor_switch_set((u16) temp_r0_2) == 1)) {
            this->m_b4 = 1;
            play_sound_effect(0x43C11, (u8 *)&this->position, 0, 0);
            spawn_particle_effect(&this->position, 0x45);
            spawn_particle_effect(&this->position, 0x46);
            ((TOWreckAncientBrakable *)arg0)->spawn_debris();
        }
        return;
    case 1:
        ((TObjCollidable *)arg0)->set_flag8();
        ((TObject *)arg0)->queue_destruction();
        break;
    }
}

void TOWreckAncientBrakable::spawn_debris() {
    u8 *arg0 = (u8 *)this;
    Vec_8017D448 tmp;
    Arr_8017D448 arr = TOWreckAncientBrakable__debris_table;
    Param_8017D448 p = TOWreckAncientBrakable__debris_param_table;
    s32 i;
    void *obj;
    p.pos.x = *(f32 *)(arg0 + 0x38);
    p.pos.y = *(f32 *)(arg0 + 0x3C);
    p.pos.z = *(f32 *)(arg0 + 0x40);
    p.f38 = p.pos.y;
    for (i = 0; i < 9; i++) {
        VecCopy((Vec *)&tmp, (const Vec *)&arr.v[i]);
        push_matrix_from(identity_matrix);
        rotate_matrix_y(0, *(s32 *)(arg0 + 0x60));
        rotate_vector_by_matrix(0, &tmp, &tmp);
        pop_matrix();
        VecCopy((Vec *)&p.pos, (const Vec *)((Vec_8017D448 *)(arg0 + 0x38)));
        vec3_add_to(&p.pos, &tmp);
        p.f40 = get_bml_model((void *) wreck_ancient_brakable_bml_resource, i);
        p.f44 = TObjFish__sub_8001EDB0((void *) wreck_ancient_brakable_bml_resource, i);
        obj = __nw__7TObjectFUl(0x234);
        if (obj != 0) {
            __ct__8TObjChipFP7TObjectPC14TObjChipParams((u8 *)obj, (u8 *)tl_05, (u8 *)&p);
        }
    }
}

void TOWreckAncientBrakable__sub_8017D444(void *) {  }


// --- TOWreckAncientBrakable05 ---

u8 *TOWreckAncientBrakable05__ct(TOWreckAncientBrakable05 *wreck_ancient_brakable05, s32 arg1) {
    s32 temp_r0;
    TOWreckAncientBrakable__ct(wreck_ancient_brakable05, 3);
    *(s32 **)((s8 *)wreck_ancient_brakable05 + 0x18) = __vt__24TOWreckAncientBrakable05;
    *(s32 *)((s8 *)wreck_ancient_brakable05 + 0) = (s32) TOWreckAncientBrakable05__name;
    ((TOWreckAncientBrakable05 *)(wreck_ancient_brakable05))->apply_object_set_data((void *)arg1);
    init_collision_body_parts(wreck_ancient_brakable05, &TOWreckAncient__collision_body_templates[3], 1);
    ((TObjPlayer *)wreck_ancient_brakable05)->register_object_by_id();
    wreck_ancient_brakable05->m_b8 = (s32) wreck_ancient_brakable05->set_params[0];
    temp_r0 = wreck_ancient_brakable05->m_b8;
    if ((temp_r0 < 0) || (temp_r0 >= 0x100)) {
        wreck_ancient_brakable05->m_b8 = -1;
    }
    return (u8 *)wreck_ancient_brakable05;
}

void *__dt__24TOWreckAncientBrakable05Fv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__24TOWreckAncientBrakable05;
        __dt__22TOWreckAncientBrakableFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

void *TOWreckAncientBrakable05__create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xBC);
    if (o != NULL) {
        o = TOWreckAncientBrakable05__ct((TOWreckAncientBrakable05 *)((u8 *)o), (s32)arg0);
    }
    return o;
}
