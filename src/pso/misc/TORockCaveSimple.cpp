#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TORockCaveSimple.h"
#include "pso/object/TObjFish.h"

struct Base1_80175024 { char pad[0x18]; };
struct VObj1_80175024 : Base1_80175024 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual s32 m8(f32, f32);
};

extern "C" {

void *TORockCaveSimple__ct(void *arg0);
void *__dt__16TORockCaveSimpleFv(void *arg0, s16 arg1);
s32 post_translate_matrix(void *);
void *__ct__10TORockCaveFv(void *arg0);
s32 rotate_matrix_y(s32, s32);
s32 push_matrix();
void __dl__7TObjectFPv(void *);
void *__dt__10TORockCaveFv(void *arg0, s16 arg1);

void TORockCaveSimple::render() {
    u8 *arg0 = (u8 *)this;
    VObj1_80175024 *self = (VObj1_80175024 *)arg0;
    if (self->m8(*(f32 *)&this->unk_AC, this->m_b0) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object(this->model);
        pop_matrix();
    }
}

extern s32 __vt__16TORockCaveSimple[];

void *__dt__16TORockCaveSimpleFv(void *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__16TORockCaveSimple;
        __dt__10TORockCaveFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *TORockCaveSimple__class_name;

void *TORockCaveSimple__ct(void *rock_cave_simple) {
    __ct__10TORockCaveFv(rock_cave_simple);
    *(s32 **)((s8 *)rock_cave_simple + 0x18) = __vt__16TORockCaveSimple;
    *(void * *)&((TORockCaveSimple *)rock_cave_simple)->m_name = TORockCaveSimple__class_name;
    return rock_cave_simple;
}

}
