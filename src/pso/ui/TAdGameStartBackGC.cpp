#include "pso/TAdGameStartBackGC.h"
#include "pso/misc/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/TAdGameStartBackGC.h"
#include "pso/items/TItemWeapon.h"
#include "pso/player/TUnk_804E70A8.h"

#include "types.h"
#include "pso/TMainTask.h"
#include "pso/misc/TWindowSubStatusDisp.h"
#include "pso/object/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/player/TObjPlayer_80141D1C.h"

struct RecoveredGlobal_803074FC___vt__18TAdGameStartBackGC {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_803074FC___vt__18TAdGameStartBackGC __vt__18TAdGameStartBackGC;
extern s32 TAdGameStartBackGC__class_name;
extern s32 game_start_background_texture_list;
extern const f32 lbl_805DF07C;
extern const f32 lbl_805DF084;
extern const f32 lbl_805DF088;
extern const f32 lbl_805DF08C;
extern const f32 lbl_805DF090;
extern const f32 lbl_805DF094;
extern const f32 lbl_805DF098;
extern const f32 lbl_805DF09C;
extern const f32 lbl_805DF0A0;
extern const f32 lbl_805DF080;

extern const f32 lbl_805DF078;

void TAdGameStartBackGC::render_background_status() {
    u8 *arg0 = (u8 *)this;
    begin_screen_draw(1);
    TObjFish::set_global_param(game_start_background_texture_list);
    set_draw_texture_and_color(0, ((*(s32 *)((s8 *)arg0 + 0x78) << 0x18) | 0xFF0000 | 0xFFFF));
    draw_textured_quad_at_depth((f32 *)(arg0 + 0x3C), lbl_805DF078);
    TWindowSubStatusDisp::get_player();
}

void TAdGameStartBackGC::render() { if (TMainTask::get_render_pass() != 1) { set_additive_blend(); render_background_status(); set_default_alpha_blend(); } }

#pragma push
#pragma fp_contract on
typedef char RecoveredGlobal_803074FC___vt__18TAdGameStartBackGC_size[sizeof(RecoveredGlobal_803074FC___vt__18TAdGameStartBackGC) == 0x18 ? 1 : -1];

#pragma push
#pragma fp_contract on
void TAdGameStartBackGC::run_task() {
    u8 *arg0 = (u8 *)this;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    s32 temp_r4;
    s32 var_r0;
    *(s32 *)((s8 *)arg0 + 0x7C) = (s32) (*(s32 *)((s8 *)arg0 + 0x7C) + 1);
    temp_r4 = *(s32 *)((s8 *)arg0 + 0x7C);
    if (temp_r4 < 0xA) {
        *(f32 *)((s8 *)arg0 + 0x6C) = (f32) -((lbl_805DF080 * (f32) temp_r4) - lbl_805DF07C);
        *(f32 *)((s8 *)arg0 + 0x70) = (f32) -((lbl_805DF080 * (f32) *(s32 *)((s8 *)arg0 + 0x7C)) - lbl_805DF07C);
    } else if (temp_r4 > 0x1C) {
        *(s32 *)((s8 *)arg0 + 0x78) = (s32) (*(s32 *)((s8 *)arg0 + 0x78) - 0x19);
        var_r0 = *(s32 *)((s8 *)arg0 + 0x78);
        if (var_r0 < 0) {
            var_r0 = 0;
        }
        *(s32 *)((s8 *)arg0 + 0x78) = var_r0;
    }
    temp_f2 = *(f32 *)((s8 *)arg0 + 0x64);
    *(f32 *)((s8 *)arg0 + 0x3C) = (f32) ((*(f32 *)((s8 *)arg0 + 0x6C) * (*(f32 *)((s8 *)arg0 + 0x1C) - temp_f2)) + temp_f2);
    temp_f2_2 = *(f32 *)((s8 *)arg0 + 0x68);
    *(f32 *)((s8 *)arg0 + 0x40) = (f32) ((*(f32 *)((s8 *)arg0 + 0x70) * (*(f32 *)((s8 *)arg0 + 0x20) - temp_f2_2)) + temp_f2_2);
    temp_f2_3 = *(f32 *)((s8 *)arg0 + 0x64);
    *(f32 *)((s8 *)arg0 + 0x44) = (f32) ((*(f32 *)((s8 *)arg0 + 0x6C) * (*(f32 *)((s8 *)arg0 + 0x24) - temp_f2_3)) + temp_f2_3);
    temp_f2_4 = *(f32 *)((s8 *)arg0 + 0x68);
    *(f32 *)((s8 *)arg0 + 0x48) = (f32) ((*(f32 *)((s8 *)arg0 + 0x70) * (*(f32 *)((s8 *)arg0 + 0x28) - temp_f2_4)) + temp_f2_4);
}
#pragma pop

TAdGameStartBackGC::~TAdGameStartBackGC() {}
u8 *__ct__18TAdGameStartBackGCFv(u8 *object, u8 *arg1) {
    f32 temp_f5;
    f32 temp_f5_2;
    __ct__7TObjectFP7TObject(object, arg1);
    *(s32 **)((s8 *)object + 0x18) = &__vt__18TAdGameStartBackGC.value;
    *(s32 *)((s8 *)object + 0) = (s32) TAdGameStartBackGC__class_name;
    *(f32 *)((s8 *)object + 0x5C) = (f32) lbl_805DF084;
    *(f32 *)((s8 *)object + 0x60) = (f32) lbl_805DF088;
    *(s32 *)((s8 *)object + 0x78) = 0xFF;
    *(s32 *)((s8 *)object + 0x7C) = -1;
    *(f32 *)((s8 *)object + 0x6C) = (f32) lbl_805DF07C;
    *(f32 *)((s8 *)object + 0x70) = (f32) lbl_805DF07C;
    game_start_background_texture_list = TObjPlayer::get_instance();
    *(f32 *)((s8 *)object + 0x1C) = (f32) *(f32 *)((s8 *)object + 0x5C);
    *(f32 *)((s8 *)object + 0x20) = (f32) *(f32 *)((s8 *)object + 0x60);
    *(f32 *)((s8 *)object + 0x24) = (f32) (lbl_805DF08C + *(f32 *)((s8 *)object + 0x5C));
    *(f32 *)((s8 *)object + 0x28) = (f32) (lbl_805DF090 + *(f32 *)((s8 *)object + 0x60));
    temp_f5 = *(f32 *)((s8 *)object + 0x1C);
    *(f32 *)((s8 *)object + 0x64) = (f32) ((lbl_805DF094 * (*(f32 *)((s8 *)object + 0x24) - temp_f5)) + temp_f5);
    temp_f5_2 = *(f32 *)((s8 *)object + 0x20);
    *(f32 *)((s8 *)object + 0x68) = (f32) ((lbl_805DF094 * (*(f32 *)((s8 *)object + 0x28) - temp_f5_2)) + temp_f5_2);
    *(f32 *)((s8 *)object + 0x4C) = (f32) lbl_805DF098;
    *(f32 *)((s8 *)object + 0x50) = (f32) lbl_805DF09C;
    *(f32 *)((s8 *)object + 0x54) = (f32) lbl_805DF0A0;
    *(f32 *)((s8 *)object + 0x58) = (f32) lbl_805DF094;
    return object;
}
#pragma pop

void TUnk_804E70A8::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x1F8) = 5;
    ((TItemWeapon *)arg0)->clear_weapon_flags(0x800U);
}

}
