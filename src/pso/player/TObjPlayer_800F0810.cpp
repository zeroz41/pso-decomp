#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/system/ModelDrawContext.h"
#include "pso/render/render_util.h"

#include "pso/enemy/TObjEneDD_ST.h"

/* Ninja chunk strips, model and object used to override the material of the next drawn model. */
struct AltChunkStrips {
    s16 header;
    s16 size;
    s32 diffuse;
    s16 end[2];
};

struct AltChunkModel {
    s32 *vlist;
    s16 *plist;
    f32 center[3];
    f32 radius;
};

struct AltChunkObject {
    u32 eval_flags;
    AltChunkModel *model;
    f32 position[3];
    s32 angle[3];
    f32 scale[3];
    AltChunkObject *child;
    AltChunkObject *sibling;
    u8 pad34[4];
};

#include <stddef.h>
#include "pso/player/TObjPlayer.h"
#include "pso/TParticleCtrl.h"
struct Stack_800F09E8 {
    f32 sp8;
    f32 spC;
    f32 sp10;
    f32 sp14;
    f32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 * sp24;
};

struct RecoveredGlobal_800F09E8_lbl_804976B0 {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void set_chunk_material_override_pair(s32 arg0, s32 arg1);
extern s32 model_render_flags;
s32 is_split_screen();
extern RecoveredGlobal_800F09E8_lbl_804976B0 blob_shadow_rect_desc;
extern s32 blob_shadow_texture_list;
extern const f32 lbl_805DA7F8;
extern const f32 lbl_805DA7FC;
extern const f32 lbl_805DA800;
int init_directional_light__9TObjLightFv(void*);
int TObjLight__sub_801337F8(void*);

    extern int current_scene_light;
void TObjPlayer::update_lights() { init_directional_light__9TObjLightFv((void*)current_scene_light); TObjLight__sub_801337F8((void*)current_scene_light); }

void TObjPlayer__sub_800F083C(void) {  }

void TObjPlayer::clear_alt_model_flag() {
    model_render_flags &= 0xFFFFF7FF;
    set_chunk_material_override_pair(0xFF00, 0);
}
void TObjPlayer::set_alt_model_flag() { (*(int *)&model_render_flags) = ((*(int *)&model_render_flags) | 0x800); set_chunk_material_override_pair((s32)((void*)-513), (s32)((void*)0)); }
AltChunkObject alt_model_object;
AltChunkModel alt_model;
AltChunkStrips alt_model_strips;

AltChunkObject *TObjPlayer__sub_800F08AC(AltChunkObject *next, s32 diffuse) {
    alt_model_strips.diffuse = diffuse;
    alt_model_object.sibling = next;
    return &alt_model_object;
}
void TObjEneDD_ST::draw_with_alt_model(s32 arg1) {
    s32 temp_r31;
    temp_r31 = *(s32 *)&this->model;
    TObjPlayer::set_alt_model_flag();
    TObjPlayer__sub_800F083C();
    *(s32 *)&this->model = (s32)TObjPlayer__sub_800F08AC((AltChunkObject *)temp_r31, arg1);
    draw();
    TObjPlayer::update_lights();
    TObjPlayer::clear_alt_model_flag();
    *(s32 *)&this->model = temp_r31;
}
void TObjPlayer__sub_800F0928(void) {
    s16 *strips = (s16 *)&alt_model_strips;
    AltChunkObject *object = &alt_model_object;
    strips[0] = 0x2514;
    strips[1] = 2;
    strips[2] = 0;
    strips[3] = 0xAFF;
    strips[4] = 0xFF;
    strips[5] = 0xFF;
    alt_model.vlist = NULL;
    alt_model.plist = strips;
    alt_model.center[0] = 0.0f;
    alt_model.center[1] = 0.0f;
    alt_model.center[2] = 0.0f;
    alt_model.radius = 0.0f;
    object->eval_flags = 0x57;
    object->model = &alt_model;
    object->position[0] = 0.0f;
    object->position[1] = 0.0f;
    object->position[2] = 0.0f;
    object->angle[0] = 0;
    object->angle[1] = 0;
    object->angle[2] = 0;
    object->scale[0] = 0.0f;
    object->scale[1] = 0.0f;
    object->scale[2] = 0.0f;
    object->child = NULL;
    object->sibling = NULL;
}

s32 is_split_screen__10TObjPlayerFv(void) {
    return is_split_screen() ? 1 : 0;
}
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
void draw_blob_shadow(s32 arg0) {
    typedef char sp8_offset[(offsetof(Stack_800F09E8, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_800F09E8, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_800F09E8, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_800F09E8, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_800F09E8, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_800F09E8, sp1C) == 0x14) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_800F09E8, sp20) == 0x18) ? 1 : -1];
    typedef char sp24_offset[(offsetof(Stack_800F09E8, sp24) == 0x1C) ? 1 : -1];
    Stack_800F09E8 stack;
    if (arg0 == 0) {
        if (is_split_screen__10TObjPlayerFv() != 0) {
            goto block_2;
        }
    } else {
block_2:
        stack.sp8 = lbl_805DA7F8;
        stack.spC = lbl_805DA7FC;
        stack.sp10 = lbl_805DA7FC;
        stack.sp14 = lbl_805DA800;
        stack.sp18 = lbl_805DA800;
        stack.sp1C = 0;
        stack.sp20 = blob_shadow_texture_list;
        stack.sp24 = &blob_shadow_rect_desc.value;
        set_depth_buffer_settings_1();
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        TParticleCtrl::begin_effect_render();
        ((TObjPlayer *)(&stack.sp8))->draw_shadow_quad(0, 0x20);
        stack.sp8 = lbl_805DA7FC;
        stack.spC = lbl_805DA7FC;
        ((TObjPlayer *)(&stack.sp8))->draw_shadow_quad(0, 0x24);
        stack.sp8 = lbl_805DA7F8;
        stack.spC = lbl_805DA7F8;
        ((TObjPlayer *)(&stack.sp8))->draw_shadow_quad(0, 0x28);
        stack.sp8 = lbl_805DA7FC;
        stack.spC = lbl_805DA7F8;
        ((TObjPlayer *)(&stack.sp8))->draw_shadow_quad(0, 0x2C);
        TParticleCtrl::end_effect_render();
        restore_saved_depth_alpha_state();
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma pop

#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
typedef char RecoveredGlobal_800F09E8_lbl_804976B0_size[sizeof(RecoveredGlobal_800F09E8_lbl_804976B0) == 0x18 ? 1 : -1];
#pragma pop

}
