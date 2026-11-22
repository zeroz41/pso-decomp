#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/ui/keyboard/TKeyBoardControl_803F0C50.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/unk/text_803F1804.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/task/TObject.h"

void TKeyBoardControl::render() {}

void TKeyBoardControl::run_task() {
    s32 port;
    port = is_player_input_active(m_1e);
    if (m_1c & 1) {
        if (TWindowShortListCtrl__check_controller_button(&controller_input_state.controllers[port], 0x200) != 0) {
            m_1c = (u16) (m_1c & 0xFFFE);
            m_hard->sub_8025EC04();
            if (m_soft != NULL) {
                window_request_show(m_soft);
            }
        }
    } else if (m_hard->is_key_held() == 0) {
        m_1c = (u16) (m_1c | 1);
        if (m_soft != NULL) {
            m_soft->request_close();
        }
    }
}

TKeyBoardControl::~TKeyBoardControl() {
    if (m_soft != NULL) { m_soft->close(); }
    if (m_hard != NULL) { m_hard->close(); }
    if (m_base != NULL) { m_base->close(); }
}

const char *TKeyBoardControl__class_name = "TKeyBoardControl";

TKeyBoardControl::TKeyBoardControl(TObject *parent, u32 width, u32 lines, u8 mode, s32 client) : TObject(parent) {
    m_name = TKeyBoardControl__class_name;
    m_1c = 0;
    m_1e = client;
    m_base = new TWindowKeyBoardBase();
    m_base->init_keyboard_text_field(width, lines);
    m_base->set_flag62_bit8();
    m_hard = new TWindowKeyBoardHard(m_base);
    m_hard->sub_8025EC04();
    m_soft = new TWindowKeyBoardSoft(m_base, client);
    switch (mode) {
    case 0:
        m_1c |= 2;
        m_base->set_mode0();
        m_hard->set_mode0();
        m_soft->set_mode0();
        break;
    case 1:
        m_1c |= 2;
        m_1c |= 8;
        m_hard->set_mode1();
        m_soft->set_mode1();
        m_base->set_mode1();
        break;
    case 2:
        m_1c |= 2;
        m_1c |= 0x10;
        m_hard->set_mode2();
        m_soft->set_mode2();
        m_base->set_mode2();
        break;
    case 3:
        m_1c |= 0x20;
        m_hard->set_mode3();
        m_soft->set_mode3();
        m_base->set_mode3();
        break;
    }
}
