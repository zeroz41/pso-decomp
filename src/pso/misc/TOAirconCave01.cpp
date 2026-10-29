#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TOAirconCave01.h"
#include "pso/object/TObjFish.h"

extern "C" {

s32 post_translate_matrix(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix(int);

extern u8 *TOAirconCave01__model_archive;
extern void *tl_05;
}

void TOAirconCave01::render() {
    s32 temp_r3;
    u8 *temp_r31;
    u8 *temp_r4;

    temp_r4 = (unsigned char *) (*(void **)((s8 *)TOAirconCave01__model_archive + 0x42C));
    temp_r31 = (unsigned char *) (*(void **)((s8 *)temp_r4 + 8));
    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        temp_r3 = *(s32 *)&this->rotation_x;
        *(s32 *)&this->rotation_x = (temp_r3 + 0x106);
        push_matrix(temp_r3);
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_model((*(s32 *)((s8 *)temp_r31 + 4)));
        pop_matrix();
    }
}

void *TOAirconCave01::create(void *arg0) {
    return new TOAirconCave01((TObject *)tl_05, arg0);
}
