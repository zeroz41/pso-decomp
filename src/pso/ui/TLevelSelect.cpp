#define TOBJECT_OUT_OF_LINE_HELPERS
#include "pso/ui/frontend/TAdTitleTexGC.h"
#include "pso/ui/frontend/TAdTitleGC.h"
#include "pso/ui/frontend/TAdRayGC.h"
#include "pso/ui/frontend/TAdGuideTxtGC.h"
#include "pso/ui/frontend/TAdSelectCurGC.h"
#include "pso/ui/frontend/TAdSelectTxtGC.h"
#include "pso/ui/TLevelSelect.h"
#include "pso/ui/frontend/TitleBackgroundStorage.h"
#include "pso/ui/frontend/TAdDrawLineCtrl.h"
#include "pso/ui/keyboard/TKeyBoardControl_8000F824.h"
#include "pso/unk/TLobby_80132ED0.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801334D4.h"

#include "types.h"
#include "pso/ui/frontend/TAdBackTxtGC.h"
#include "pso/ui/frontend/TAdBackGC.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"
#include "pso/system/NinjaTypes.h"
#include "pso/system/ControllerInput.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off

const char *level_select_class_name = "TLevelSelect";

s32 game_difficulty_selection;

void TLevelSelect::render() {  }
int TLevelSelect::count_unlocked_difficulties(void) {
    u8 f;
    int n;
    f = 0;
    if (TLevelSelect::get_difficulty_flag_bit(0, 0x35) != 0 || TLevelSelect::get_difficulty_flag_bit(0, 0x57) != 0) {
        f = 1;
    }
    n = f;
    f = 0;
    if (TLevelSelect::get_difficulty_flag_bit(1, 0x37) != 0 || TLevelSelect::get_difficulty_flag_bit(1, 0x57) != 0) {
        f = 1;
    }
    n += f;
    f = 0;
    if (TLevelSelect::get_difficulty_flag_bit(2, 0x37) != 0 || TLevelSelect::get_difficulty_flag_bit(2, 0x57) != 0) {
        f = 1;
    }
    n += f;
    return n;
}
void TLevelSelect::run_task() {
    TAdMultiChgGameModeGC::set_default_camera();
    if (game_difficulty_selection != m_cursor->selection_index()) {
        m_guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0xD, m_cursor->selection_index() + 1)));
    }
    game_difficulty_selection = m_cursor->selection_index();
    switch (m_cursor->confirmation_result()) {
    case 1:
        request_main_phase(0xE);
        break;
    case 0:
    default:
        if (test_pressed_buttons_packed(&controller_physical_port_bank.controllers[0], 2) != 0 ||
            test_controller_flag_4c_color(&controller_input_state.keyboard, 2) != 0) {
            queue_destruction();
            TAdMultiChgGameModeGC::set_game_mode_changed();
        }
        break;
    }
}
TLevelSelect::~TLevelSelect() {}
TLevelSelect::TLevelSelect() : TObject(tl_01) {
    u32 i;
    m_name = level_select_class_name;
    TKeyBoardControl__sub_8000F90C(2);
    game_difficulty_selection = 0;
    m_unlocked_count = count_unlocked_difficulties();
    if (m_unlocked_count == 0) {
        request_main_phase(0xE);
        queue_destruction();
        return;
    }
    new TAdBackGC(this);
    new TAdBackTxtGC(this);
    new TAdRayGC(this);
    new TAdTitleGC(this, 2);
    new TAdTitleTexGC(this);
    {
        TAdSelectTxtLayout layouts[4] = {
            { 0x44FFFFFF, 238.0f, 145.0f }, { 0x44FFFFFF, 208.0f, 197.0f },
            { 0x44FFFFFF, 178.0f, 249.0f }, { 0x44FFFFFF, 148.0f, 301.0f },
        };
        for (i = 0; i < m_unlocked_count + 1; i++) {
            layouts[i].text_id = -1;
        }
        new TAdSelectTxtGC(this, &layouts[0], 0);
        new TAdSelectTxtGC(this, &layouts[1], 1);
        new TAdSelectTxtGC(this, &layouts[2], 2);
        new TAdSelectTxtGC(this, &layouts[3], 3);
        {
            NJS_POINT2 pos = { 302.0f, 28.0f };
            NJS_POINT2 entries[4] = { { 215.0f, 146.0f }, { 185.0f, 198.0f }, { 155.0f, 250.0f }, { 125.0f, 302.0f } };
            m_cursor = new TAdSelectCurGC(this, entries, &pos);
            m_cursor->append_entry(&entries[0]);
            m_guide = new TAdGuideTxtGC(this);
            m_guide->set_line(0, reinterpret_cast<const char *>(get_localized_text_entry(0xD, 0)));
            m_guide->set_line(1, reinterpret_cast<const char *>(get_localized_text_entry(0xD, 1)));
            switch (m_unlocked_count) {
            case 1:
                m_cursor->append_entry(&entries[1]);
                break;
            case 2:
                m_cursor->append_entry(&entries[1]);
                m_cursor->append_entry(&entries[2]);
                break;
            case 3:
                m_cursor->append_entry(&entries[1]);
                m_cursor->append_entry(&entries[2]);
                m_cursor->append_entry(&entries[3]);
                break;
            }
        }
    }
    create_draw_line_ctrl(this, 2, 0.0f);
}
