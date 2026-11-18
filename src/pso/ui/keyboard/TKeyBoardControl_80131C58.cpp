#include "pso/ui/window/TWindowKeyBoardHard.h"
#include "types.h"
#include "pso/system/ControllerInputState.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/keyboard/TKeyBoardControl_80131C58.h"
#include "pso/ui/keyboard/TKeyBoardControl_8025EC04.h"
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
#include "pso/ui/window/TWindowKeyBoardHard_802601D4.h"
#include "pso/ui/window/TWindowKeyBoardSoft_80261440.h"
#include "pso/ui/keyboard/TKeyBoardControl_8025CB70.h"
#include "pso/unk/text_8025FF8C.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC_801A6D60.h"
#include "pso/system/task/TObject.h"

extern "C" {
void render__16TKeyBoardControlFv(void) {  }

void run_task__16TKeyBoardControlFv(TKeyBoardControl *key_board_control) {
    s32 temp_r3;
    s32 temp_r5;
    temp_r3 = is_player_input_active((key_board_control->m_1e));
    if (key_board_control->m_1c & 1) {
        temp_r5 = temp_r3 * 0x50;
        if (TWindowShortListCtrl__check_controller_button((void *) ((u8 *)&controller_input_state + temp_r5 + 0x20), 0x200) != 0) {
            key_board_control->m_1c = (u16) (key_board_control->m_1c & 0xFFFE);
            TKeyBoardControl__sub_8025EC04((u8 *)key_board_control->m_24);
            if ((u32) key_board_control->m_28 != 0U) {
                window_request_show(*(void **)((s8 *)key_board_control + 0x28));
            }
        }
    } else if (((s32)((TKeyBoardControl *)(key_board_control->m_24))->is_key_held()) == 0) {
        key_board_control->m_1c = (u16) (key_board_control->m_1c | 1);
        if ((u32) key_board_control->m_28 != 0U) {
            ((TWindowLockOn *)(*(void **)((s8 *)key_board_control + 0x28)))->request_close();
        }
    }
}

}
TKeyBoardControl::~TKeyBoardControl() {
    if (*(void **)((s8 *)this + 0x28) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x28)))->close(); }
    if (*(void **)((s8 *)this + 0x24) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x24)))->close(); }
    if (*(void **)((s8 *)this + 0x20) != NULL) { ((TWindowBase *)(*(void **)((s8 *)this + 0x20)))->close(); }
}

extern "C" {
void __ct__7TObjectFP7TObject(void *, void *);
u8 *__ct__19TWindowKeyBoardBaseFv(u8 *arg0);
void TKeyBoardControl__sub_802613A4(TKeyBoardControl *arg0);
extern s32 __vt__16TKeyBoardControl[];
const char *TKeyBoardControl__class_name = "TKeyBoardControl";

TKeyBoardControl *TKeyBoardControl__ct(TKeyBoardControl *self, TObject *parent, u32 arg2, u32 arg3, u8 mode, s16 client) {
    TKeyBoardControl *kb;
    void *o;

    __ct__7TObjectFP7TObject(self, parent);
    kb = self;
    *(s32 **)((u8 *)kb + 0x18) = __vt__16TKeyBoardControl;
    ((TKeyBoardControl *)self)->m_name = TKeyBoardControl__class_name;
    self->m_1c = 0;
    self->m_1e = client;
    o = new TWindowKeyBoardBase();
    self->m_20 = (u32)o;
    ((TWindowKeyBoardBase *)self->m_20)->init_keyboard_text_field(arg2, arg3);
    ((TKeyBoardControl *)self->m_20)->set_flag62_bit8();
    o = new TWindowKeyBoardHard(self->m_20);
    self->m_24 = (u32)o;
    TKeyBoardControl__sub_8025EC04((u8 *)self->m_24);
    o = TObject::operator new(0x70);
    if (o != NULL) {
        o = TWindowKeyBoardSoft__ct((u8 *)o, self->m_20, client);
    }
    self->m_28 = (u32)o;
    switch (mode) {
    case 0:
        self->m_1c |= 2;
        TKeyBoardControl__sub_8025CC3C((void *)self->m_20);
        fn_8025FF8C((void *)self->m_24);
        ((TKeyBoardControl *)self->m_28)->release();
        break;
    case 1:
        self->m_1c |= 2;
        self->m_1c |= 8;
        ((TKeyBoardControl *)self->m_24)->enable_caps_led();
        TKeyBoardControl__sub_802613A4((TKeyBoardControl *)self->m_28);
        TKeyBoardControl__sub_8025CC04((u8 *)self->m_20);
        break;
    case 2:
        self->m_1c |= 2;
        self->m_1c |= 0x10;
        ((TKeyBoardControl *)self->m_24)->enable_kana_led();
        ((TKeyBoardControl *)self->m_28)->release_input();
        TKeyBoardControl__sub_8025CBCC((u8 *)self->m_20);
        break;
    case 3:
        kb = self;
        kb->m_1c |= 0x20;
        ((TKeyBoardControl *)self->m_24)->enable_keyboard_led();
        ((TKeyBoardControl *)self->m_28)->close();
        TKeyBoardControl__sub_8025CBC0((void *)self->m_20);
        break;
    }
    return kb;
}
}
