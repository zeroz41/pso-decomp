#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/charcreate/TChCrEffTagStr.h"
#include "pso/render/render_util.h"


#include "types.h"
#include "pso/ui/chat/TWindowSubSymbolChatPartsSet.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/charcreate/TChCrEffTag.h"
#include "pso/system/vector.h"

#pragma readonly_strings on
const char *TChCrEffTagStr__name = "TChCrEffTagStr";

extern "C" {
s32 draw_creation_sprite_offset(s32, vec2f *, f32 *, f32, f32, f32, f32, f32);

void TChCrEffTagStr__sub_8029AED0(TChCrEffTagStr *p) { p->state = 1; }

#pragma push
#pragma fp_contract on
void TChCrEffTagStr::render() {
    NJS_POINT2 scale;
    f32 fade_value;
    f32 inv_fade;
    set_depth_buffer_settings_1();
    fade_value = fade;
    inv_fade = 1.0f - fade_value;
    scale.y = fade_value * fade_value;
    scale.x = (0.5f * inv_fade) + 1.0f;
    draw_creation_sprite_offset(sprite_id, &pos, &scale.x, -2.4375f, fade_value, inv_fade, 1.0f, 0.5f);
    restore_saved_depth_alpha_state();
}
#pragma pop

#pragma push
#pragma opt_common_subs off
void TChCrEffTagStr::run_task() {
    f32 grown;
    f32 shrunk;
    f32 current;
    f32 step0 = 0.13333334f;
    f32 step1 = -0.06666667f;
    switch (state) {
    case 0:
        current = fade;
        if (!(current >= 1.0f)) {
            grown = current + step0;
            fade = grown;
            if (grown >= 1.0f) {
                fade = 1.0f;
                break;
            }
        }
        break;
    case 1:
        shrunk = fade + step1;
        fade = shrunk;
        if (shrunk <= 0.0f) {
            fade = 0.0f;
            queue_destruction();
        }
        break;
    }
}
#pragma pop

TChCrEffTagStr::~TChCrEffTagStr() {}
}
TChCrEffTagStr::TChCrEffTagStr(TObject *object, void *sprite, void *position) : TObject(object) {
    m_name = TChCrEffTagStr__name;
    sprite_id = (saddr)sprite;
    copy_vec2(&pos, position);
    state = 0;
    fade = 0.0f;
}

void *TChCrEffTag::create_str(void *parent, void *sprite, void *position) {
    return new TChCrEffTagStr((TObject *)parent, sprite, position);
}
