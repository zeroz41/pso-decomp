#include "pso/ui/frontend/TAdGameStartBackGC.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/weapon/TItemWeapon.h"
#include "pso/weapon/TUnk_804E70A8.h"

#include "types.h"
#include "pso/system/task/TMainTask.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/object/ambient/TObjFish.h"
#include "pso/player/TObjPlayer.h"
#include "pso/render/render_util.h"

struct RecoveredGlobal_803074FC___vt__18TAdGameStartBackGC {
    s32 value;
    u8 remaining[0x14];
};

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
extern RecoveredGlobal_803074FC___vt__18TAdGameStartBackGC __vt__18TAdGameStartBackGC;
extern s32 TAdGameStartBackGC__class_name;
s32 game_start_background_texture_list;
void TAdGameStartBackGC::render_background_status() {
    u8 *arg0 = (u8 *)this;
    begin_screen_draw(1);
    TObjFish::set_global_param(game_start_background_texture_list);
    set_draw_texture_and_color(0, ((*(s32 *)((s8 *)arg0 + 0x78) << 0x18) | 0xFF0000 | 0xFFFF));
    draw_textured_quad_at_depth((f32 *)(arg0 + 0x3C), 0.79f);
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
        *(f32 *)((s8 *)arg0 + 0x6C) = (f32) (5.0f - 0.4f * (f32) temp_r4);
        *(f32 *)((s8 *)arg0 + 0x70) = (f32) (5.0f - 0.4f * (f32) *(s32 *)((s8 *)arg0 + 0x7C));
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
    *(f32 *)((s8 *)object + 0x5C) = 106.0f;
    *(f32 *)((s8 *)object + 0x60) = 192.0f;
    *(s32 *)((s8 *)object + 0x78) = 0xFF;
    *(s32 *)((s8 *)object + 0x7C) = -1;
    *(f32 *)((s8 *)object + 0x6C) = 5.0f;
    *(f32 *)((s8 *)object + 0x70) = 5.0f;
    game_start_background_texture_list = TObjPlayer::get_instance();
    *(f32 *)((s8 *)object + 0x1C) = (f32) *(f32 *)((s8 *)object + 0x5C);
    *(f32 *)((s8 *)object + 0x20) = (f32) *(f32 *)((s8 *)object + 0x60);
    *(f32 *)((s8 *)object + 0x24) = (f32) (512.0f + *(f32 *)((s8 *)object + 0x5C));
    *(f32 *)((s8 *)object + 0x28) = (f32) (128.0f + *(f32 *)((s8 *)object + 0x60));
    temp_f5 = *(f32 *)((s8 *)object + 0x1C);
    *(f32 *)((s8 *)object + 0x64) = (f32) ((0.5f * (*(f32 *)((s8 *)object + 0x24) - temp_f5)) + temp_f5);
    temp_f5_2 = *(f32 *)((s8 *)object + 0x20);
    *(f32 *)((s8 *)object + 0x68) = (f32) ((0.5f * (*(f32 *)((s8 *)object + 0x28) - temp_f5_2)) + temp_f5_2);
    *(f32 *)((s8 *)object + 0x4C) = 0.0f;
    *(f32 *)((s8 *)object + 0x50) = 0.25f;
    *(f32 *)((s8 *)object + 0x54) = 1.0f;
    *(f32 *)((s8 *)object + 0x58) = 0.5f;
    return object;
}
#pragma pop

void TUnk_804E70A8::emit_marker_effects() {
    u8 *arg0 = (u8 *)this;
    *(s32 *)((s8 *)arg0 + 0x1F8) = 5;
    ((TItemWeapon *)arg0)->clear_weapon_flags(0x800U);
}

}
