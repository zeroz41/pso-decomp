#include "types.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/object/TObjTombstone.h"
#include "pso/object/TObjFish.h"

extern "C" {

s32 PPCSync();
s32 scroll_ginja_mesh_uvs(void *, int, int, int, int);
s32 post_translate_matrix(void *);
s32 rotate_matrix_y(int, int);
s32 push_matrix();

extern u32 TObjTombstone__shared_resource_object;
extern s32 tombstone_first_run_flag;

void TObjTombstone::update_render_flags() {
    u8 *temp_r3;
    s32 *temp_r4;

    if ((u32) TObjTombstone__shared_resource_object != 0U) {
        if ((s32) tombstone_first_run_flag == 0) {
            scroll_ginja_mesh_uvs((void *) (*(s32 *)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)this->model + 0x2C)) + 0x30)) + 4)), -8, 0, 0, 1);
            tombstone_first_run_flag = 1;
            PPCSync();
        }
        temp_r3 = (unsigned char *) (*(void **)((s8 *)(*(void **)((s8 *)(*(void **)((s8 *)this->model + 0x2C)) + 0x30)) + 0x30));
        temp_r4 = *(s32 **)((s8 *)temp_r3 + 0x30);
        if (this->m_230 & 0x10) {
            *(s32 *)((s8 *)temp_r3 + 0) = (s32) (*(s32 *)((s8 *)temp_r3 + 0) & 0xFFFFFFF7);
            *temp_r4 |= 8;
        } else {
            *(s32 *)((s8 *)temp_r3 + 0) = (s32) (*(s32 *)((s8 *)temp_r3 + 0) | 8);
            *temp_r4 &= 0xFFFFFFF7;
        }
        push_matrix();
        post_translate_matrix((u8 *)&this->position);
        rotate_matrix_y(0, this->rotation_y);
        TObjFish::set_global_param(this->texlist);
        draw_ginja_object((this->model));
        pop_matrix();
    }
}

}
