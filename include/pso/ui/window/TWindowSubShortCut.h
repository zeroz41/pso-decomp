#ifndef PSO_UI_WINDOW_TWINDOWSUBSHORTCUT_H
#define PSO_UI_WINDOW_TWINDOWSUBSHORTCUT_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/CharacterSaveRecordLookup.h"

struct TWindowMainMenu;

struct TWindowSubShortCutList;
struct TWindowMenu;
struct TWindowMessageYesNo;
class TWindowChat;
struct TWindowShortCut;

struct TWindowSubShortCut : public TObject {
    TWindowSubShortCut(TObject *parent, s32 client);
    virtual ~TWindowSubShortCut();
    static const char *class_name;
    TWindowSubShortCutList *open_com_card_list();
    u8 state;
    u8 pad_1D[0x1];
    u16 m_1e;
    uaddr client_id;
    uaddr shortcut_slot;
    TWindowMainMenu *parent_menu;
    TWindowSubShortCutList *com_card_list;
    TWindowMenu *menu;
    TWindowMessageYesNo *confirm_window;
    TWindowChat *chat_window;
    TWindowShortCut *shortcut_window;
    ChatShortcut chat_submission; // written by the chat window, saved by store_chat_shortcut
    TWindowMessageYesNo *open_confirm_message();
    TWindowMessageYesNo *open_confirm_prompt();
    TWindowMenu *open_menu();
    virtual void render();
    virtual void run_task();
};

LAYOUT_ASSERT(TWindowSubShortCut_size, sizeof(TWindowSubShortCut) == 0x94);
#endif
