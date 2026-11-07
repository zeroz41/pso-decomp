#include "types.h"
#include "pso/object/TObjChip.h"
#include "pso/object/wreck/TOWreckAncientBrakable_8017D444.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/system/vector.h"
#include "pso/object/wreck/TOWreckAncientBrakable.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/unk/text_80087278.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/text_803D8F74.h"
#include "pso/system/SoundEffect.h"

#pragma readonly_strings on

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
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

extern "C" {
void *TOWreckAncientBrakable__name = (char *)"TOWreckAncientBrakable";
}

// Class name of TOWreckAncientBrakable05 (TOWreckAncientBrakable05__name points here).
extern const char TOWreckAncientBrakable05__class_name_string[] = "TOWreckAncientBrakable05";

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

extern "C" {
s32 TObjFish__sub_8001EDB0(void *, int);
s32 get_bml_model(void *, int);
void *__nw__7TObjectFUl(u32);
void vec3_add_to(Vec_8017D448 *, Vec_8017D448 *);
void rotate_vector_by_matrix(int, Vec_8017D448 *, Vec_8017D448 *);
extern u8 identity_matrix[];
extern void *wreck_ancient_brakable_bml_resource;
extern s32 tl_05;

void TOWreckAncientBrakable__sub_8017D444(void *) {  }
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
        p.f40 = get_bml_model(wreck_ancient_brakable_bml_resource, i);
        p.f44 = TObjFish__sub_8001EDB0(wreck_ancient_brakable_bml_resource, i);
        obj = __nw__7TObjectFUl(0x234);
        if (obj != 0) {
            __ct__8TObjChipFP7TObjectP14TObjChipParams((u8 *)obj, (u8 *)tl_05, (u8 *)&p);
        }
    }
}

}

extern "C" {

u8 is_current_floor_switch_set(u16);

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
        queue_destruction__7TObjectFv(arg0);
        break;
    }
}

}

extern "C" {

void *TOWreckAncientBrakable__ct(TOWreckAncientBrakable *arg0);
void *__dt__22TOWreckAncientBrakableFv(void *arg0, s16 arg1);
void TOWreckAncient__ct(void *);
void __dl__7TObjectFPv(void *);
void *__dt__14TOWreckAncientFv(void *arg0, s16 arg1);

extern s32 __vt__22TOWreckAncientBrakable[];

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

void *TOWreckAncientBrakable__ct(TOWreckAncientBrakable *wreck_ancient_brakable) {
    TOWreckAncient__ct(wreck_ancient_brakable);
    *(s32 **)((s8 *)wreck_ancient_brakable + 0x18) = __vt__22TOWreckAncientBrakable;
    *(void * *)&wreck_ancient_brakable->m_name = TOWreckAncientBrakable__name;
    wreck_ancient_brakable->m_b4 = 0;
    wreck_ancient_brakable->m_b8 = -1;
    return wreck_ancient_brakable;
}

}
