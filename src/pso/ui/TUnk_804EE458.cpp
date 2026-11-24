#include "pso/system/SoundEffect.h"
#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/render/model_render_state.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/system/main_loop.h"
#include "pso/ui/frontend/TAdTrialAgreementGC.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdScrollWinGC.h"
#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/NinjaTypes.h"
#include "pso/ui/frontend/TAdPlayerLoadGC_801E0C30.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdAgreementBaseGC.h"
#include "pso/ui/frontend/TAdTrialAgreementGC_8033573C.h"
#include "pso/ui/frontend/TAdTrialAgreementGC_80335958.h"
#include "pso/unk/TLobby.h"
#include "pso/ui/hud/TRaderMapCore.h"
#include "pso/render/MaterialColorFade.h"
#include "pso/boss/derolle/TBoss2DeRolLe.h"
#include "pso/unk/TLobby_80335E08.h"
#include "pso/render/ChunkMaterialState.h"
#include "pso/ui/TUnk_804EE458.h"
#include "pso/ui/window/TWindowChoiceSetting.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/system/task/TMainTask.h"
#include "pso/effect/particle/TParticleCtrl.h"
#include "pso/camera/TCameraCtrl.h"
#include "pso/player/TObjPlayer.h"
#include "pso/unk/TUnk_804EE470.h"
#include "pso/ui/window/TWindowSubStatusDisp_803DEE6C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"
#include "pso/render/render_util.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"
#include "pso/math/AngleLookup.h"

void TUnk_804EE458::draw_record_with_camera(s32 record, s32 camera) {
    TLobby::draw_with_camera(TLobby::get_record(record), camera, 0x20, (-1e+01f));
}

extern "C" {



s32 TAdTrialAgreementGC__sub_80335958(TUnk_804EE458 *controller) {
    return controller->state == 2;
}

s32 TUnk_804EE458::sub_8033596C() { return cursor; }

void TUnk_804EE458::update_title_prompt() {
    u8 *arg0 = (u8 *)this;
  float new_var;
  if ((test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 8) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0))
  {
    play_sound_effect(0x52D01, 0, 0, 0);
    state = 1;
  }
  new_var = 1.0f + sin_table_lookup((s32) (182.04445f * ((f32) ((frame % 120) * 3))));
  color.a = (f32) (new_var / 2.0f);
}

void TUnk_804EE458::handle_cursor_input() {
    u8 *input;
    input = (u8 *)&controller_physical_port_bank.controllers[0];
    color.a = 1.0f;
    if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)input, 0x10, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x10, 6, 1) != 0)) {
        cursor = cursor - 1;
        if (cursor < 0) {
            cursor = 3;
        }
        play_sound_effect(0x54100, 0, 0, 0);
    }
    if ((TAdMultiPlyChrSelectGC::dispatch_draw_command((saddr)input, 0x20, 6, 1) != 0) || (test_buttons_press_or_repeat(&controller_input_state.keyboard, 0x20, 6, 1) != 0)) {
        cursor = cursor + 1;
        if (cursor >= 4) {
            cursor = 0;
        }
        play_sound_effect(0x54100, 0, 0, 0);
    }
    if ((test_pressed_buttons_packed(input, 4) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 4) != 0)) {
        state = 2;
        play_sound_effect(0x40042309, 0, 0, 0);
    }
}

void TUnk_804EE458::render() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r0;
    s32 temp_r31;
    s32 i;
    if (TMainTask::get_render_pass() != 0) {
        TParticleCtrl::begin_effect_render();
        TCameraCtrl::restore_full_screen_view();
        saved_model_render_flags = model_render_flags;
        copy_argb(&saved_model_draw_color, &model_material_color);
        if (state == 0) {
            model_render_flags |= 0x10;
            set_constant_material(&color);
            bind_title_texture_list();
            TLobby::draw_with_camera(TLobby::get_record(0xA), 0xA, 0x22, (-1e+01f));
        }
        temp_r0 = state;
        if ((temp_r0 == 1) || (temp_r0 == 2)) {
            i = 0xB;
            do {
                draw_record_with_camera(i, i);
                i += 1;
            } while (i != 0xF);
            bind_title_texture_list();
            set_additive_blend();
            temp_r31 = sub_8033596C();
            if (state == 1) {
                draw_record_with_camera(temp_r31 + 0xF, 0xF);
                draw_record_with_camera(temp_r31 + 0x13, 0x13);
                draw_record_with_camera(temp_r31 + 0x17, 0x17);
            }
            if (state == 2) {
                draw_record_with_camera(temp_r31 + 0x1B, 0x1B);
                draw_record_with_camera(temp_r31 + 0x1F, 0x1F);
                draw_record_with_camera(temp_r31 + 0x23, 0x23);
            }
            set_default_alpha_blend();
        }
        copy_argb(&model_material_color, &saved_model_draw_color);
        model_render_flags = saved_model_render_flags;
        TCameraCtrl::restore_saved_view();
        TParticleCtrl::end_effect_render();
    }
}

void TUnk_804EE458::run_task() {

    switch (state) {
    case 0:
        update_title_prompt();
        break;
    case 1:
        handle_cursor_input();
        break;
    case 2:
        break;
    }
    frame++;
}

}

TUnk_804EE458::~TUnk_804EE458() {}

TUnk_804EE458::TUnk_804EE458(TObject *parent) : TObject(parent) {
    owner = parent;
    cursor = 0;
    state = 0;
    color.a = 0.0f;
    color.r = 1.0f;
    color.g = 1.0f;
    color.b = 1.0f;
    frame = 0;
}

void TLobby__sub_80335E74(void) {  }
void TLobby__sub_80335E78(void) {  }
