#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/misc/TOAirconCave02.h"
#include "pso/object/TObjFish.h"

extern "C" {

s32 post_translate_matrix(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();

extern u8 *TOAirconCave02__bml_resource;
extern void *tl_05;
}

void TOAirconCave02::render() {
    s32 temp_r31;

    temp_r31 = *(s32 *)((s8 *)((unsigned char *) (*(void **)((s8 *)TOAirconCave02__bml_resource + 0x42C))) + 8);
    if (update_object_view_visibility(m_c0, model_radius) != 0) {
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object((void *)temp_r31);
        pop_matrix();
    }
}

void *TOAirconCave02::create(void *arg0) {
    return new TOAirconCave02((TObject *)tl_05, arg0);
}
