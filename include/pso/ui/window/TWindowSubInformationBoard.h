#ifndef PSO_UI_WINDOW_TWINDOWSUBINFORMATIONBOARD_H
#define PSO_UI_WINDOW_TWINDOWSUBINFORMATIONBOARD_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowSubInformationBoard : public TObject {
    TWindowSubInformationBoard(TObject *arg1, void *arg2);
    virtual ~TWindowSubInformationBoard();
    void open_card_info_window();
    u8 m_1c;
    u8 _pad1D[0x3];
    u32 m_20;
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    u32 m_34;
    u32 m_38;
    u32 m_3c;
    void* m_40;
    virtual void render();
    virtual void run_task();
    static void clear_if_current(u32 arg0);
    void set_page(s32 arg1);
    void set_message_index(s32 arg1);
    static s32 open_keyboard(s32 arg0);
    void show_card_a7();
    u8 unk_44[0x8D0];
};

typedef char TWindowSubInformationBoard_size[sizeof(TWindowSubInformationBoard) == 0x914 ? 1 : -1];

extern "C" {
void *__dt__26TWindowSubInformationBoardFv(TWindowSubInformationBoard *arg0, s16 arg1);
}

// --- C functions defined in TWindowSubInformationBoard.cpp ---
extern "C" {
void *__dt__26TWindowSubInformationBoardFv(TWindowSubInformationBoard *arg0, s16 arg1);
}
// --- end of C functions

#endif
