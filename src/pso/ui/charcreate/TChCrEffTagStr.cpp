#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/charcreate/TChCrEffTagStr.h"
#include "pso/render/render_util.h"


#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/task/TObject.h"

struct Stack_8029AEDC {
    f32 sp8;
    f32 spC;
};

#pragma readonly_strings on
const char *TChCrEffTagStr__name = "TChCrEffTagStr";

extern "C" {
s32 draw_creation_sprite_offset(s32, vec2f *, f32 *, f32, f32, f32, f32, f32);

void TChCrEffTagStr__sub_8029AED0(TChCrEffTagStr *p) { p->state = 1; }

#pragma push
#pragma fp_contract on
void TChCrEffTagStr::render() {
    Stack_8029AEDC stack;
    f32 temp_f2;
    f32 temp_f3;
    set_depth_buffer_settings_1();
    temp_f2 = fade;
    temp_f3 = 1.0f - temp_f2;
    stack.spC = temp_f2 * temp_f2;
    stack.sp8 = (0.5f * temp_f3) + 1.0f;
    draw_creation_sprite_offset(sprite_id, &pos, &stack.sp8, -2.4375f, temp_f2, temp_f3, 1.0f, 0.5f);
    restore_saved_depth_alpha_state();
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TChCrEffTagStr::run_task() {
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 step0 = 0.13333334f;
    f32 step1 = -0.06666667f;
    switch (state) {
    case 0:
        temp_f2 = fade;
        if (!(temp_f2 >= 1.0f)) {
            temp_f0 = temp_f2 + step0;
            fade = temp_f0;
            if (temp_f0 >= 1.0f) {
                fade = 1.0f;
                break;
            }
        }
        break;
    case 1:
        temp_f1 = fade + step1;
        fade = temp_f1;
        if (temp_f1 <= 0.0f) {
            fade = 0.0f;
            queue_destruction();
        }
        break;
    }
}
#pragma pop

TChCrEffTagStr::~TChCrEffTagStr() {}
}
TChCrEffTagStr::TChCrEffTagStr(TObject *object, void *arg2, void *arg3) : TObject(object) {
    m_name = TChCrEffTagStr__name;
    sprite_id = (s32)arg2;
    ((TWindowSubSymbolChatPartsSet *)&pos)->copy_vec2(arg3);
    state = 0;
    fade = 0.0f;
}
