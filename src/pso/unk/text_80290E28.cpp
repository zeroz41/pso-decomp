#pragma opt_lifetimes off
#include "types.h"
#include "pso/misc/TRaderMapCore.h"
#include "pso/player/TUnk_80494AE0.h"
#include "pso/boss/TBoss2DeRolLe.h"
#include "pso/system/ChunkMaterialState.h"
#include "pso/unk/text_80290E28.h"

#include <stddef.h>
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
struct Stack_80290E28 {
    s32 sp8;
    s32 spC;
    f32 sp10;
    f32 sp14;
};

struct Quad_80290F10 { f32 x; f32 y; f32 z; f32 w; f32 h; f32 d; void *tbl; };

struct Stack_80290F10 { Quad_80290F10 q; u8 *table; };

extern "C" {
s32 draw_ui_sprite_scaled(f32, f32, void *, void *, void *);
void TCharaMaking__resolve_creation_sprite_table(u8 * *table, s32 *id);
extern s32 creation_sprite_table[];
extern s32 saved_model_draw_color[];
extern s32 model_material_color[];
extern const f32 ui_sprite_scale;
extern const f32 lbl_805DD960;
#pragma push
#pragma opt_common_subs off
void draw_creation_sprite_offset(s32 arg0, s32 arg1, s32 alpha, f32 farg0, f32 farg1) {
    typedef char sp8_offset[(offsetof(Stack_80290E28, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80290E28, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80290E28, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80290E28, sp14) == 0xC) ? 1 : -1];
    Stack_80290E28 stack;
    u8 *temp_r6;
    ((TWindowSubSymbolChatPartsSet *)(&stack.sp10))->copy_vec2((void *)arg1);
    stack.sp8 = arg0;
    TCharaMaking__resolve_creation_sprite_table((u8 * *)(&stack.spC), &stack.sp8);
    temp_r6 = (u8 *)(stack.spC + (stack.sp8 * 0x14));
    stack.sp10 += (f32) *(s16 *)((s8 *)temp_r6 + 4);
    stack.sp14 += (f32) *(s16 *)((s8 *)temp_r6 + 6);
    draw_ui_sprite_scaled((f32)farg0, (f32)farg1, (void *)arg0, &stack.sp10, (void *)alpha);
}
#pragma pop

void draw_ui_sprite_tinted(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 farg0) {
    Stack_80290F10 st;
    if (!(arg3[0] <= lbl_805DD960)) {
        st.q.x = arg1[0];
        st.q.y = ui_sprite_scale * arg1[1];
        st.q.w = arg2[0];
        st.q.h = ui_sprite_scale * arg2[1];
        st.q.tbl = creation_sprite_table;
        TCharaMaking__resolve_creation_sprite_table(&st.table, &arg0);
        ((TRaderMapCore *)saved_model_draw_color)->copy_vec4(model_material_color);
        set_constant_material((const NJS_ARGB *)arg3);
        TLobby::draw_with_camera((s32)&st.q, (s32)arg0, 0x22, (f32)farg0);
        ((TRaderMapCore *)model_material_color)->copy_vec4(saved_model_draw_color);
    }
}

}
