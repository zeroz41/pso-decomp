#include "types.h"
#include "pso/math/MatrixTransforms.h"
#include "pso/unk/text_803D96A8.h"
#include "pso/unk/text_803E2D70.h"
#include "pso/boss/TObjBoss1Floor.h"
#include "pso/boss/TObjBoss1MokoHill_Solo.h"
#include "pso/object/TObjFish.h"

extern "C" {

void TObjBoss1Floor__sub_8002CB40(void);
void TObjBoss1Floor__sub_8002CB78(void);
s32 update_dragon_trail_uvs(void *);
s32 push_matrix();
s32 set_chunk_material_override_pair(int, int, void *, void *);

void TObjBoss1Floor__sub_8002CB40(void) {  }

extern s32 tl_02;

void TObjBoss1Floor::create_instance() {
    void* obj = new TObjBoss1Floor((TObject *)tl_02);
}

void TObjBoss1Floor__sub_8002CB78(void) {  }

extern u8 *lbl_805D4B50;
extern s32 dragon_common_texture_list;
extern s32 saved_model_render_flags;
extern s32 saved_chunk_polygon_flags_and_mask;
extern s32 saved_chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_or_mask;
extern s32 chunk_polygon_flags_and_mask;
extern s32 model_render_flags;

void TObjBoss1MokoHill_Solo::render() {
    u8 *arg0 = (u8 *)this;
    TObjFish::set_global_param(dragon_common_texture_list);
    update_dragon_trail_uvs((u8 *)&this->m_28);
    push_matrix();
    translate_matrix(0, this->m_28, (f32) (*(f32 *)((s8 *)arg0 + 0x34)), this->m_30);
    if ((s32) this->m_48 != 0) {
        saved_model_render_flags = model_render_flags;
        saved_chunk_polygon_flags_and_mask = chunk_polygon_flags_and_mask;
        saved_chunk_polygon_flags_or_mask = chunk_polygon_flags_or_mask;
        model_render_flags |= 0x800;
        set_chunk_material_override_pair(0xFF00, 0x100, (void *)chunk_polygon_flags_or_mask, (void *)chunk_polygon_flags_and_mask);
        draw_chunk_object((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)lbl_805D4B50 + 0x42C)) + 0x38)));
        chunk_polygon_flags_and_mask = saved_chunk_polygon_flags_and_mask;
        chunk_polygon_flags_or_mask = saved_chunk_polygon_flags_or_mask;
        model_render_flags = saved_model_render_flags;
    } else {
        draw_chunk_object((void *)(*(s32 *)((s8 *)(*(void **)((s8 *)lbl_805D4B50 + 0x42C)) + 0x38)));
    }
    pop_matrix();
}

}
