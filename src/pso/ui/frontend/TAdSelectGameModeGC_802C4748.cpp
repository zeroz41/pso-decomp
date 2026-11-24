#include "pso/system/SoundEffect.h"
#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdRayGC.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/ui/frontend/TitleBackgroundStorage.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/ui/frontend/TAdChrSelPlyPlateGC.h"
#include "pso/ui/frontend/TAdSelectGameModeGC_802C4748.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"
#include "pso/ui/frontend/TAdPlyChrSelPlateGC.h"
#include "pso/ui/frontend/TAdChrMoveEffectGC.h"
#include "pso/ui/charcreate/TObjCMHairMenu.h"

#include "types.h"
#include "pso/ui/frontend/TAdSelectTxtGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/ui/window/TWindowActionPalette.h"
#include "pso/player/TObjPlayer.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"
#include "pso/system/scene/OfflineGameScene.h"


struct S8_802C4944 { f32 a, b; };

struct S16_802C4944 { S8_802C4944 x[2]; };

struct S24_802C4944 { TAdSelectTxtLayout t[2]; };

const char *TAdSelectGameModeGC__name = "TAdSelectGameModeGC";
const S24_802C4944 select_game_mode_text_layout = {{{-1, 208.0f, 197.0f}, {-1, 178.0f, 249.0f}}};
const S8_802C4944 lbl_80471A44 = {302.0f, 28.0f};
const S16_802C4944 select_game_mode_button_rect = {{{185.0f, 198.0f}, {155.0f, 250.0f}}};

s32 TAdSelectGameModeGC__cached_mode_value;
extern "C" {

int sync_char_select_state__10TObjPlayerFv(void*);

int fn_802C4748(void* p) { return sync_char_select_state__10TObjPlayerFv(p); }

void TAdSelectGameModeGC::render() {  }

void TAdSelectGameModeGC::call_enable_camera(void* p) { TAdSelectGameModeGC::enable_camera(); }
void TAdSelectGameModeGC__sub_802C478C(void) {
    s32 mode_data;
    if (get_main_phase() == 0xE) {
        mode_data = TAdSelectGameModeGC::get_mode_data();
        switch (mode_data) {
        case 0:
            TAdSelectGameModeGC::enable_camera();
            return;
        case 1:
            set_split_screen_views(TAdMultiPlyChrSelectGC::count_selected_slots());
            return;
        }
    } else {
        TAdSelectGameModeGC::enable_camera();
    }
}
void TAdSelectGameModeGC::run_task() {
    s32 mode_data;
    TAdMultiChgGameModeGC::set_default_camera();
    if ((s32) TAdSelectGameModeGC__cached_mode_value != cursor->selection_index()) {
        guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x15, cursor->selection_index() + 1)));
    }
    TAdSelectGameModeGC__cached_mode_value = cursor->selection_index();
    if ((test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0) || (test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0)) {
        play_sound_effect(0x52F16, 0, 0, 0);
        TAdMultiChgGameModeGC::request_scene_change();
        return;
    }
    if (cursor->confirmation_result() == 1) {
        mode_data = TAdSelectGameModeGC::get_mode_data();
        switch (mode_data) {
        case 0:
            TAdMultiChgGameModeGC::set_game_mode();
            return;
        case 1:
            TAdMultiChgGameModeGC::set_change_game_mode();
            break;
        }
    }
}
TAdSelectGameModeGC::~TAdSelectGameModeGC() {}

TAdSelectGameModeGC::TAdSelectGameModeGC(TObject *parent) : TObject(parent) {
    m_name = TAdSelectGameModeGC__name;
    TAdSelectGameModeGC__cached_mode_value = 0;
    cursor = 0;
    guide = 0;
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    new TAdRayGC(this);
    new TAdTitleGC(this, 4);
    new TAdTitleTexGC(this);
    {
        S24_802C4944 txt = select_game_mode_text_layout;
        new TAdSelectTxtGC(this, &txt.t[0], 6);
        new TAdSelectTxtGC(this, &txt.t[1], 7);
    }
    {
        S8_802C4944 a = lbl_80471A44;
        S16_802C4944 b = select_game_mode_button_rect;
        cursor = new TAdSelectCurGC(this, reinterpret_cast<const NJS_POINT2 *>(&b), reinterpret_cast<const NJS_POINT2 *>(&a));
        cursor->append_entry(&b.x[0]);
        cursor->append_entry(&b.x[1]);
    }
    guide = new TAdGuideTxtGC(this);
    guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x15, 0)));
    guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x15, 1)));
    create_draw_line_ctrl(this, 0xA, 0.0f);
}

}
