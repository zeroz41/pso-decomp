#ifndef PSO_UI_WINDOW_TWINDOWSUBINFORMATIONBOARD_H
#define PSO_UI_WINDOW_TWINDOWSUBINFORMATIONBOARD_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowSubInformationBoard : public TObject {
    TWindowSubInformationBoard(TObject *arg1, void *arg2);
    virtual ~TWindowSubInformationBoard();
    u32 open_card_info_window();
    u8 m_1c;
    u8 _pad1D[0x3];
    u32 m_20;
    u32 shown_index;    // index set_page/set_message_index last showed; -1 after a new message window
    u32 m_28;
    u32 menu_window;    // create_info_board_menu (TWindowMenu)
    u32 page_menu;      // sub_8034CDE0: one entry per info-board page, picks set_page
    u32 message_window; // TWindowMessage::create (open_card_info_window, show_card_a7)
    u32 m_38;
    u32 keyboard;       // open_keyboard
    void* m_40;
    virtual void render();
    virtual void run_task();
    static void clear_if_current(u32 arg0);
    void set_page(s32 arg1);
    void set_message_index(s32 arg1);
    static s32 open_keyboard(s32 arg0);
    u32 show_card_a7();
    u32 create_info_board_menu();
    u32 sub_8034CDE0();
    u8 unk_44[0x8D0];
};

typedef char TWindowSubInformationBoard_size[sizeof(TWindowSubInformationBoard) == 0x914 ? 1 : -1];

#endif
