#include "types.h"
#include "pso/misc/TOAirconCave01_80156F64.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TOAirconCave01.h"
#include "pso/object/TObjFish.h"

extern "C" {

struct AirBase_80156e8c { char pad[0x18]; };
struct AirV_80156e8c : AirBase_80156e8c {
    virtual s32 m0(); virtual s32 m1(); virtual s32 m2();
    virtual s32 m3(); virtual s32 m4(); virtual s32 m5();
    virtual s32 m6(); virtual s32 m7();
    virtual s32 m8(void *a, f32 b, f32 c);
};

s32 post_translate_matrix(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix(int);
void *__nw__7TObjectFUl(int);

extern u8 *TOAirconCave01__model_archive;

void TOAirconCave01::render() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r3;
    u8 *temp_r31;
    u8 *temp_r4;

    temp_r4 = (unsigned char *) (*(void **)((s8 *)TOAirconCave01__model_archive + 0x42C));
    temp_r31 = (unsigned char *) (*(void **)((s8 *)temp_r4 + 8));
    if (((AirV_80156e8c *)arg0)->m8(temp_r4, this->m_c0, *(f32 *)&this->m_c4) != 0) {
        temp_r3 = *(s32 *)&this->rotation_x;
        *(s32 *)&this->rotation_x = (temp_r3 + 0x106);
        push_matrix(temp_r3);
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texture_id);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
        pop_matrix();
    }
}

extern void *tl_05;

void *TOAirconCave01::create(void *arg0) {
    void *o = __nw__7TObjectFUl(0xC8);
    if (o != NULL) {
        o = TOAirconCave01__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

}
