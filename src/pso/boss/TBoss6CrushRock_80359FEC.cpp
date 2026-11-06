#include "types.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/system/GinjaMaterial.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/boss/TBoss6CrushRock.h"
#include "pso/object/TObjFish.h"

extern "C" {
int is_falz_alive__15TBoss6CrushRockFv(void*);
f32 vec3_add_to(void *, void *);
f32 vector_length(void *);
extern const f32 lbl_805E00B8;
extern const f32 lbl_805E00BC;
extern const f32 lbl_805E00C0;
extern const f32 lbl_805E00C4;
int post_translate_matrix(void*);
int rotate_matrix_z(void*, void*);
int rotate_matrix_x(void*, void*);
int rotate_matrix_y(void*, void*);
int push_matrix(void);

void TBoss6CrushRock::render() { if (is_falz_alive__15TBoss6CrushRockFv(this) != 0) { push_matrix(); post_translate_matrix((char*)this + 0x24); rotate_matrix_y((void*)0, *(void**)((char*)this + 0x40)); rotate_matrix_x((void*)0, *(void**)((char*)this + 0x3c)); rotate_matrix_z((void*)0, *(void**)((char*)this + 0x44)); TObjFish::set_global_param((s32)(*(void**)((char*)this + 0x20))); draw_ginja_object(*(void**)((char*)this + 0x1c)); pop_matrix(); } }
#pragma push
#pragma opt_common_subs off
void TBoss6CrushRock::run_task() {
    u8 *arg0 = (u8 *)this;
    if (((s32)is_falz_alive__15TBoss6CrushRockFv(arg0)) == 0) {
        queue_destruction__7TObjectFv((arg0));
        return;
    }
    *(s32 *)((s8 *)arg0 + 0x3C) = (s32) (*(s32 *)((s8 *)arg0 + 0x3C) + *(s32 *)((s8 *)arg0 + 0x48));
    *(s32 *)((s8 *)arg0 + 0x40) = (s32) (*(s32 *)((s8 *)arg0 + 0x40) + *(s32 *)((s8 *)arg0 + 0x4C));
    *(s32 *)((s8 *)arg0 + 0x44) = (s32) (*(s32 *)((s8 *)arg0 + 0x44) + *(s32 *)((s8 *)arg0 + 0x50));
    *(f32 *)((s8 *)arg0 + 0x34) = (f32) (*(f32 *)((s8 *)arg0 + 0x34) + lbl_805E00B8);
    vec3_add_to(arg0 + 0x24, arg0 + 0x30);
    if (*(f32 *)((s8 *)arg0 + 0x28) < lbl_805E00BC) {
        *(f32 *)((s8 *)arg0 + 0x28) = (f32) lbl_805E00BC;
        *(f32 *)((s8 *)arg0 + 0x30) = (f32) (*(f32 *)((s8 *)arg0 + 0x30) * lbl_805E00C0);
        *(f32 *)((s8 *)arg0 + 0x34) = (f32) (*(f32 *)((s8 *)arg0 + 0x34) * lbl_805E00B8);
        *(f32 *)((s8 *)arg0 + 0x38) = (f32) (*(f32 *)((s8 *)arg0 + 0x38) * lbl_805E00C0);
        if (vector_length(arg0 + 0x30) < lbl_805E00C4) {
            queue_destruction__7TObjectFv((arg0));
        }
    }
}
#pragma pop

}
