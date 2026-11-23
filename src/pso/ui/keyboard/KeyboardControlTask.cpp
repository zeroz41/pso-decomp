#include "types.h"
#include "pso/system/ControllerInput.h"
#include "pso/system/ControllerInputState.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/keyboard/TKeyBoardControl.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/ui/keyboard/KeyboardDeviceDriver.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowKeyBoardBase.h"
#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "pso/ui/window/TWindowKeyBoardSoft.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/window/TWindowLockOn.h"
#include "pso/ui/window/TWindowMakeTeam.h"
#include "pso/enemy/morfos/TWindowSubTradeMain.h"
#include "pso/unk/text_803F1804.h"

void TKeyBoardControl::render() {}

void TKeyBoardControl::run_task() {
    s32 port;
    port = is_player_input_active(client_index);
    if (flags & 1) {
        if (test_pressed_buttons_packed(&controller_input_state.controllers[port], 0x200) != 0) {
            flags = (u16)(flags & 0xFFFE);
            m_hard->sub_8025EC04();
            if (m_soft != NULL) {
                window_request_show(m_soft);
            }
        }
    } else if (m_hard->is_key_held() == 0) {
        flags = (u16)(flags | 1);
        if (m_soft != NULL) {
            m_soft->request_close();
        }
    }
}

TKeyBoardControl::~TKeyBoardControl() {
    if (m_soft != NULL) {
        m_soft->close();
    }
    if (m_hard != NULL) {
        m_hard->close();
    }
    if (m_base != NULL) {
        m_base->close();
    }
}

const char *keyboard_control_class_name = "TKeyBoardControl";

TKeyBoardControl::TKeyBoardControl(TObject *parent, u32 width, u32 lines, u8 mode, s32 client) : TObject(parent) {
    m_name = keyboard_control_class_name;
    flags = 0;
    client_index = client;
    m_base = new TWindowKeyBoardBase();
    m_base->init_keyboard_text_field(width, lines);
    m_base->set_flag62_bit8();
    m_hard = new TWindowKeyBoardHard(m_base);
    m_hard->sub_8025EC04();
    m_soft = new TWindowKeyBoardSoft(m_base, client);
    switch (mode) {
    case 0:
        flags |= 2;
        m_base->set_mode0();
        m_hard->set_mode0();
        m_soft->set_mode0();
        break;
    case 1:
        flags |= 2;
        flags |= 8;
        m_hard->set_mode1();
        m_soft->set_mode1();
        m_base->set_mode1();
        break;
    case 2:
        flags |= 2;
        flags |= 0x10;
        m_hard->set_mode2();
        m_soft->set_mode2();
        m_base->set_mode2();
        break;
    case 3:
        flags |= 0x20;
        m_hard->set_mode3();
        m_soft->set_mode3();
        m_base->set_mode3();
        break;
    }
}
