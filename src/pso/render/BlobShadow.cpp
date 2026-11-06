#include <stddef.h>
#include "types.h"
#include "pso/object/base/TObjMotion.h"
#include "pso/render/BlobShadow.h"
#include "pso/player/TObjPlayer_800F0810.h"
#include "pso/render/ModelDrawContext.h"
#include "pso/render/render_util.h"
#include "pso/player/TObjPlayer.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/render/GinjaTexture.h"
#include "pso/system/TLanguage_801E4874.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

#pragma readonly_strings on

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
RecoveredGlobal_800F09E8_lbl_804976B0 blob_shadow_rect_desc = {
    0x00050005,
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x05, 0x00, 0xFD, 0x00, 0xFD,
      0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 },
};
u32 blob_shadow_texture_list;

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
        stack.sp8 = -4.9910388f;
        stack.spC = 0.0f;
        stack.sp10 = 0.0f;
        stack.sp14 = 1.0f;
        stack.sp18 = 1.0f;
        stack.sp1C = 0;
        stack.sp20 = blob_shadow_texture_list;
        stack.sp24 = &blob_shadow_rect_desc.value;
        set_depth_buffer_settings_1();
        set_color_blending_mode(0, 8);
        set_color_blending_mode(1, 6);
        TParticleCtrl::begin_effect_render();
        ((TObjPlayer *)(&stack.sp8))->draw_shadow_quad(0, 0x20);
        stack.sp8 = 0.0f;
        stack.spC = 0.0f;
        ((TObjPlayer *)(&stack.sp8))->draw_shadow_quad(0, 0x24);
        stack.sp8 = -4.9910388f;
        stack.spC = -4.9910388f;
        ((TObjPlayer *)(&stack.sp8))->draw_shadow_quad(0, 0x28);
        stack.sp8 = 0.0f;
        stack.spC = -4.9910388f;
        ((TObjPlayer *)(&stack.sp8))->draw_shadow_quad(0, 0x2C);
        TParticleCtrl::end_effect_render();
        restore_saved_depth_alpha_state();
    }
}
#pragma pop

void release_blob_shadow_texture(void) {
    if (blob_shadow_texture_list != 0U) {
        release_texture_list((GinjaTextureList *)blob_shadow_texture_list);
        TAdSinglePlyChrSelectGC::safe_free(blob_shadow_texture_list);
        blob_shadow_texture_list = 0U;
    }
}
}

void load_ha_u032_kage(void) { blob_shadow_texture_list = (u32)load_gvm_texture_file((s32)"ha_u032_kage.gvm"); }
