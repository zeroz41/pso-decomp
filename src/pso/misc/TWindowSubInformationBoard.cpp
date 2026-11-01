#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/object/TObject_80019A50.h"
#include "pso/misc/TWindowSubInformationBoard.h"
#include "pso/misc/TWindowMenu.h"
#include "pso/misc/TLobby.h"
#include "pso/misc/TWindowSubComCard.h"

struct VBase_18_204a81 { char pad[0x18]; };

struct VObj_18_204a81 : VBase_18_204a81 {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual s32 m7();
};

extern "C" {
void mem_free(void *p);
s32 test_flag_4c__23TAdSinglePlyChrSelectGCFv(void *, int);
s32 TWindowShortListCtrl__check_controller_button(void *, int);
s32 play_sound_effect(int, int, int, int);
s32 get_cursor_pos__20TWindowShortListCtrlFv(int);
s32 set_info_board_text__6TLobbyFv();
s32 set_message_index__26TWindowSubInformationBoardFl(void *, s16);
u32 show_card_a7__26TWindowSubInformationBoardFv(void *);
u32 open_card_info_window__26TWindowSubInformationBoardFv(void *);
u32 TWindowSubComCard__sub_8034CDE0(void *);
u32 create_info_board_menu(void *);
extern s32 controller_input_state[];
void __dl__7TObjectFPv(void *);
void __dt__7TObjectFv(void *, int);

void TWindowSubInformationBoard::render() {  }

extern s32 __vt__26TWindowSubInformationBoard[];

void TWindowSubInformationBoard::run_task() {
    u8 *arg0 = (u8 *)this;
    s32 temp_r30;
    u8 temp_r0;
    switch (this->m_1c) {
    case 0:
    case 1:
        if ((u32) this->m_2c == 0U) {
            this->m_2c = create_info_board_menu((void *)arg0);
        }
        if ((u32) this->m_34 == 0U) {
            this->m_34 = open_card_info_window__26TWindowSubInformationBoardFv((void *)arg0);
        }
        ((TWindowSubComCard *)(this->m_2c))->clear_flag_and_release();
        this->m_1c = 2U;
    case 2:
        set_message_index__26TWindowSubInformationBoardFl((void *)arg0, (get_cursor_pos__20TWindowShortListCtrlFv((int)this->m_2c)));
        if (((TWindowMenu *)(this->m_2c))->is_cancelled() != 0) {
            ((VObj_18_204a81 *)(this->m_28))->m7();
            this->m_1c = 0xCU;
        } else if (((TWindowMenu *)(this->m_2c))->is_decided() != 0) {
            if ((u32) this->m_34 != 0U) {
                ((TWindowBase *)this->m_34)->close();
                this->m_34 = 0U;
            }
            this->m_1c = ((TWindowMenu *)this->m_2c)->get_selected_value();
        }
        break;
    case 3:
        TLobby::init_once_data((u32)((void *) ((u8 *)arg0 + 0x40)));
        this->m_1c = 4U;
    case 4:
        if ((TWindowShortListCtrl__check_controller_button((void *) ((u8 *)controller_input_state + 0x20), 2) != 0) || (test_flag_4c__23TAdSinglePlyChrSelectGCFv((void *) ((u8 *)controller_input_state + 0x160), 2) != 0)) {
            play_sound_effect(0x52F16, 0, 0, 0);
            this->m_1c = 5U;
        }
        if (TLobby::get_info_board_ptr() != 0U) {
            this->m_1c = 6U;
            break;
        }
        break;
    case 5:
        TWindowSubInformationBoard::clear_if_current((u32)((void *) ((u8 *)arg0 + 0x40)));
        this->m_1c = 1U;
        break;
    case 6:
        if ((u32) this->m_30 == 0U) {
            this->m_30 = TWindowSubComCard__sub_8034CDE0(arg0);
        }
        if ((u32) this->m_34 == 0U) {
            this->m_34 = show_card_a7__26TWindowSubInformationBoardFv((void *)arg0);
        }
        this->m_1c = 7U;
    case 7:
        ((TWindowSubInformationBoard *)arg0)->set_page((int) (((TWindowMenu *)this->m_30)->get_selected_value()));
        if (((TWindowMenu *)(this->m_30))->is_cancelled() != 0) {
            this->m_1c = 8U;
            break;
        }
        break;
    case 8:
        if ((u32) this->m_30 != 0U) {
            ((TWindowBase *)this->m_30)->close();
            this->m_30 = 0U;
        }
        this->m_1c = 5U;
        break;
    case 9:
        if ((u32) this->m_2c != 0U) {
            ((TWindowBase *)this->m_2c)->close();
            this->m_2c = 0U;
        }
        if ((u32) this->m_3c == 0U) {
            this->m_3c = TWindowSubInformationBoard::open_keyboard((s32)((void *)arg0));
        }
        this->m_1c = 0xAU;
    case 10:
        if (((TWindowSubComCard *)(this->m_3c))->is_keyboard_active() != 0) {
            this->m_1c = 0xBU;
            break;
        }
        if (((TWindowSubComCard *)(this->m_3c))->update_keyboard() != 0) {
            temp_r30 = ((TWindowSubComCard *)(this->m_3c))->realloc_buffer();
            set_info_board_text__6TLobbyFv();
            TLobby::flush_pending_send();
            mem_free((void *)temp_r30);
            this->m_1c = 0xBU;
            break;
        }
        break;
    case 11:
        if ((u32) this->m_3c != 0U) {
            queue_destruction__7TObjectFv(*(void * *)&this->m_3c);
            this->m_3c = 0U;
        }
        this->m_1c = 1U;
        break;
    case 12:
        break;
    }
}

void *__dt__26TWindowSubInformationBoardFv(TWindowSubInformationBoard *arg0, s16 arg1) {
    if (arg0 != NULL) {
        *(s32 **)((s8 *)arg0 + 0x18) = __vt__26TWindowSubInformationBoard;
        if (*(void **)((s8 *)arg0 + 0x3C) != NULL) { queue_destruction__7TObjectFv(*(void **)((s8 *)arg0 + 0x3C)); arg0->m_3c = 0; }
        if (*(void **)((s8 *)arg0 + 0x38) != NULL) { ((TWindowSubComCard *)(*(void **)((s8 *)arg0 + 0x38)))->close(); arg0->m_38 = 0; }
        if (*(void **)((s8 *)arg0 + 0x34) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x34)))->close(); arg0->m_34 = 0; }
        if (*(void **)((s8 *)arg0 + 0x30) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x30)))->close(); arg0->m_30 = 0; }
        if (*(void **)((s8 *)arg0 + 0x2C) != NULL) { ((TWindowBase *)(*(void **)((s8 *)arg0 + 0x2C)))->close(); arg0->m_2c = 0; }
        TWindowSubInformationBoard::clear_if_current((u32)((s8 *)arg0 + 0x40));
        __dt__7TObjectFv(arg0, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(arg0);
        }
    }
    return arg0;
}

extern void *lbl_805D4348;

}
TWindowSubInformationBoard::TWindowSubInformationBoard(TObject *object, void *arg2) : TObject(object) {
    *(void * *)&this->m_name = lbl_805D4348;
    *(void **)((s8 *)this + 0x20) = arg2;
    this->m_24 = -1;
    *(void **)((s8 *)this + 0x28) = object;
    this->m_2c = 0;
    this->m_30 = 0;
    this->m_34 = 0;
    this->m_38 = 0;
    this->m_3c = 0;
    this->m_1c = 0;
}
