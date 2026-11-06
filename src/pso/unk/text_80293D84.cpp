#include "types.h"
#include "pso/unk/text_80293D84.h"
#include "pso/misc/TWindowCtrlMain.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"
#include <stddef.h>
#include "pso/ui/TChCrEffFade.h"

struct V2_80293D84 {
    f32 x;
    f32 y;
};

struct Prim_80293D84 {
    V2_80293D84 *pts;
    u32 *colors;
    s32 start;
    s32 count;
};

struct V2_80293E58 {
    f32 x;
    f32 y;
};

extern "C" {
u32 __cvt_fp2unsigned(f32);
extern V2_80293D84 lbl_80464ED8[6];

extern const f32 lbl_80464F10[];
extern const f32 lbl_80464F18[];

#pragma push
#pragma fp_contract on
void fn_80293D84(void *arg0, void *arg1, u32 color, f32 scale, f32 alpha) {
    V2_80293D84 *pos = (V2_80293D84 *)arg1;
    Prim_80293D84 prim;
    u32 colors[6];
    V2_80293D84 pts[6];
    s32 i;
    u32 c;
    for (i = 0; i < 6; i++) {
        pts[i].x = scale * lbl_80464ED8[i].x + pos->x;
        pts[i].y = scale * lbl_80464ED8[i].y + pos->y;
    }
    c = (color & 0x00FFFFFF) | (__cvt_fp2unsigned(255.0f * alpha) << 24);
    for (i = 0; i < 6; i++) {
        colors[i] = c;
    }
    prim.colors = colors;
    prim.start = 0;
    prim.count = 6;
    prim.pts = pts;
    ((TWindowCtrlMain *)(&prim))->draw_strip_swap_color(6, 6, (-1.5f));
}
#pragma pop

void fn_80293E58(void *arg0, f32 scale) {
    V2_80293E58 p;
    f32 s = 12.0f * scale;
    s32 odd = 1;
    ((TWindowSubSymbolChatPartsSet *)(&p))->copy_vec2((void *)lbl_80464F10);
    for (; p.y < lbl_80464F18[1]; p.y += 10.38f) {
        p.x = lbl_80464F10[0];
        if (odd == 0) {
            p.x += -18.0f;
        }
        for (; p.x < lbl_80464F18[0]; p.x += 36.0f) {
            fn_80293D84(arg0, &p, 0, s, scale);
        }
        odd ^= 1;
    }
}

}

struct Stack_80293F98 {
    s32 * sp8;
    s32 * spC;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
};

struct RecoveredGlobal_80293F98_lbl_804DB900 {
    s32 value;
    u8 remaining[0x1C];
};

extern "C" {

extern RecoveredGlobal_80293F98_lbl_804DB900 chcr_eff_fade_strip_rect;

typedef char RecoveredGlobal_80293F98_lbl_804DB900_size[sizeof(RecoveredGlobal_80293F98_lbl_804DB900) == 0x20 ? 1 : -1];
void TChCrEffFade::draw_fade_strip(f32 farg0) {
    typedef char sp8_offset[(offsetof(Stack_80293F98, sp8) == 0x0) ? 1 : -1];
    typedef char spC_offset[(offsetof(Stack_80293F98, spC) == 0x4) ? 1 : -1];
    typedef char sp10_offset[(offsetof(Stack_80293F98, sp10) == 0x8) ? 1 : -1];
    typedef char sp14_offset[(offsetof(Stack_80293F98, sp14) == 0xC) ? 1 : -1];
    typedef char sp18_offset[(offsetof(Stack_80293F98, sp18) == 0x10) ? 1 : -1];
    typedef char sp1C_offset[(offsetof(Stack_80293F98, sp1C) == 0x14) ? 1 : -1];
    typedef char sp20_offset[(offsetof(Stack_80293F98, sp20) == 0x18) ? 1 : -1];
    typedef char sp24_offset[(offsetof(Stack_80293F98, sp24) == 0x1C) ? 1 : -1];
    Stack_80293F98 stack;
    s32 temp_r9;
    temp_r9 = __cvt_fp2unsigned((f32) (255.0f * farg0)) << 0x18;
    stack.sp24 = temp_r9;
    stack.sp20 = temp_r9;
    stack.sp1C = temp_r9;
    stack.sp18 = temp_r9;
    stack.spC = &stack.sp18;
    stack.sp10 = 0;
    stack.sp14 = 4;
    stack.sp8 = &chcr_eff_fade_strip_rect.value;
    ((TWindowCtrlMain *)(&stack.sp8))->draw_strip_swap_color(4, 6, (-1.5f));
}

}
