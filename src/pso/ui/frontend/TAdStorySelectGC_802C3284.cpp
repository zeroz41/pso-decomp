#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/system/SoundEffect.h"
#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdRayGC.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "pso/ui/frontend/TAdStorySelectGC.h"
#include "pso/ui/frontend/TitleBackgroundStorage.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"
#include "pso/unk/text_80299420.h"
#include "pso/object/TObjPathObj.h"

#include "types.h"
#include "pso/ui/frontend/TAdSelectTxtGC.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdSelectGameModeGC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/ControllerInput.h"

struct B_802C3400 { NJS_POINT2 e[2]; };

struct C_802C3400 { TAdSelectTxtLayout e[2]; };

__declspec(section ".rodata") extern const char TAdStorySelectGC__class_name_string[] = "TAdStorySelectGC";
const char *TAdStorySelectGC__class_name = TAdStorySelectGC__class_name_string;

s32 story_select_cursor;
extern "C" {
void TAdStorySelectGC::render() {  }
void TAdStorySelectGC::run_task() {
    TAdMultiChgGameModeGC::set_default_camera();
    if (story_select_cursor != cursor->selection_index()) {
        guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x14, cursor->selection_index() + 1)));
    }
    story_select_cursor = cursor->selection_index();
    switch (cursor->confirmation_result()) {
    case 1:
        switch (TAdStorySelectGC::get_story_select()) {
        case 0:
            TAdStorySelectGC::set_state(0);
            break;
        case 1:
            TAdStorySelectGC::set_state(1);
            break;
        }
        queue_destruction();
        TAdMultiChgGameModeGC::set_change_mode_flags();
        break;
    case 0:
    default:
        if (test_pressed_buttons_packed(&controller_input_state.controllers[0], 2) != 0 ||
            test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            play_sound_effect(0x52F16, 0, 0, 0);
            TAdMultiChgGameModeGC::set_game_mode();
        }
        break;
    }
}
TAdStorySelectGC::~TAdStorySelectGC() {}
TAdStorySelectGC::TAdStorySelectGC(TObject *parent) : TObject(parent) {
    m_name = TAdStorySelectGC__class_name;
    story_select_cursor = 0;
    cursor = 0;
    guide = 0;
    if (TAdSinglePlyChrSelectGC::get_data() == 0) {
        TAdMultiChgGameModeGC::request_transition();
        queue_destruction();
        return;
    }
    if (TAdSelectGameModeGC::get_mode_data() == 1) {
        TAdStorySelectGC::set_state(0);
        queue_destruction();
        if (TAdMultiPlyChrSelectGC__sub_80299454() != 0) {
            TAdMultiChgGameModeGC::set_change_game_mode();
        } else {
            TAdMultiChgGameModeGC::set_change_mode_flags();
        }
        return;
    }
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    new TAdRayGC(this);
    new TAdTitleGC(this, 1);
    new TAdTitleTexGC(this);
    {
        C_802C3400 c = {{{-1, 208.0f, 197.0f}, {-1, 178.0f, 249.0f}}};
        new TAdSelectTxtGC(this, &c.e[0], 4);
        new TAdSelectTxtGC(this, &c.e[1], 5);
        {
        NJS_POINT2 a = {302.0f, 28.0f};
        B_802C3400 b = {{{185.0f, 198.0f}, {155.0f, 250.0f}}};
        cursor = new TAdSelectCurGC(this, reinterpret_cast<const NJS_POINT2 *>(&b), &a);
        cursor->append_entry(&b.e[0]);
        cursor->append_entry(&b.e[1]);
        }
    }
    guide = new TAdGuideTxtGC(this);
    guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0x14, 0)));
    guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0x14, 1)));
    create_draw_line_ctrl(this, 0xA, 0.0f);
}

}
