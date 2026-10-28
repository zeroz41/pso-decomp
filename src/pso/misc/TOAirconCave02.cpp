#include "types.h"
#include "pso/misc/TOAirconCave02_801571A0.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TOAirconCave02.h"
#include "pso/object/TObjFish.h"

extern "C" {

struct VBase570D4_801570d4 { char pad[0x18]; };
struct VObj570D4_801570d4 : VBase570D4_801570d4 {
    virtual s32 m0();
    virtual s32 m1();
    virtual s32 m2();
    virtual s32 m3();
    virtual s32 m4();
    virtual s32 m5();
    virtual s32 m6();
    virtual s32 m7();
    virtual s32 m8(f32, f32);
};

s32 post_translate_matrix(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();
void *__nw__7TObjectFUl(int);

extern u8 *TOAirconCave02__bml_resource;

void TOAirconCave02::render() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r31;

    temp_r31 = *(s32 *)((s8 *)((unsigned char *) (*(void **)((s8 *)TOAirconCave02__bml_resource + 0x42C))) + 8);
    if (((VObj570D4_801570d4 *) arg0)->m8(this->m_c0, *(f32 *)&this->m_c4) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object((void *)temp_r31);
        pop_matrix();
    }
}

extern void *tl_05;

void *TOAirconCave02::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC8);
    if (o != NULL) {
        o = TOAirconCave02__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

}
