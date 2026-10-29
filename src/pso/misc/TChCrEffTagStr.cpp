#include "pso/TChCrEffTagStr.h"
#include "pso/misc/TChCrEffTagStr.h"
#include "pso/render/render_util.h"


#include "types.h"
#include "pso/misc/TWindowSubSymbolChatPartsSet.h"

struct Stack_8029AEDC {
    f32 sp8;
    f32 spC;
};

#pragma readonly_strings on
const char *TChCrEffTagStr__name = "TChCrEffTagStr";

extern "C" {
s32 draw_creation_sprite_offset(s32, void *, f32 *, f32, f32, f32, f32, f32);
s32 queue_destruction__7TObjectFv();

void TChCrEffTagStr__sub_8029AED0(void* p) { *(s32*)((char*)p + 0x1c) = 1; }

#pragma push
#pragma fp_contract on
void TChCrEffTagStr::render() {
    u8 *arg0 = (u8 *)this;
    Stack_8029AEDC stack;
    f32 temp_f2;
    f32 temp_f3;
    set_depth_buffer_settings_1();
    temp_f2 = *(f32 *)((s8 *)arg0 + 0x24);
    temp_f3 = 1.0f - temp_f2;
    stack.spC = temp_f2 * temp_f2;
    stack.sp8 = (0.5f * temp_f3) + 1.0f;
    draw_creation_sprite_offset(*(s32 *)((s8 *)arg0 + 0x20), arg0 + 0x28, &stack.sp8, -2.4375f, temp_f2, temp_f3, 1.0f, 0.5f);
    restore_saved_depth_alpha_state();
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TChCrEffTagStr::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 step0 = 0.13333334f;
    f32 step1 = -0.06666667f;
    switch (*(s32 *)((s8 *)arg0 + 0x1C)) {
    case 0:
        temp_f2 = *(f32 *)((s8 *)arg0 + 0x24);
        if (!(temp_f2 >= 1.0f)) {
            temp_f0 = temp_f2 + step0;
            *(f32 *)((s8 *)arg0 + 0x24) = temp_f0;
            if (temp_f0 >= 1.0f) {
                *(f32 *)((s8 *)arg0 + 0x24) = 1.0f;
                break;
            }
        }
        break;
    case 1:
        temp_f1 = *(f32 *)((s8 *)arg0 + 0x24) + step1;
        *(f32 *)((s8 *)arg0 + 0x24) = temp_f1;
        if (temp_f1 <= 0.0f) {
            *(f32 *)((s8 *)arg0 + 0x24) = 0.0f;
            queue_destruction__7TObjectFv();
        }
        break;
    }
}
#pragma pop

TChCrEffTagStr::~TChCrEffTagStr() {}
}
TChCrEffTagStr::TChCrEffTagStr(TObject *object, void *arg2, void *arg3) : TObject(object) {
    m_name = TChCrEffTagStr__name;
    *(void **)((s8 *)this + 0x20) = arg2;
    ((TWindowSubSymbolChatPartsSet *)((char *)this + 40))->copy_vec2(arg3);
    *(u32 *)((s8 *)this + 0x1C) = 0;
    *(f32 *)((s8 *)this + 0x24) = 0.0f;
}
