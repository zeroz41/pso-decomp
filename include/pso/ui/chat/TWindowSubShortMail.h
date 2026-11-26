#ifndef PSO_UI_CHAT_TWINDOWSUBSHORTMAIL_H
#define PSO_UI_CHAT_TWINDOWSUBSHORTMAIL_H

#include <stddef.h>
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
class TWindowMenuIconLine;
struct TWindowMessage;
struct TWindowMenu;
struct TWindowComCard;
struct TWindowMessageYesNo;

class TKeyBoardControl;

struct TWindowSubShortMail : public TObject {
    TWindowSubShortMail(TWindowMainMenu *parent, s32 client_id);
    virtual ~TWindowSubShortMail();
    virtual void run_task();
    virtual void render();
    TWindowMenuIconLine *create_list_item();
    static TKeyBoardControl *create_keyboard();
    static saddr open_confirm_prompt(TObject *parent, int client_id);
    TWindowMessageYesNo *open_confirm_dialog();
    TWindowMessageYesNo *open_delete_confirm_dialog();
    void find_target_user();
    static s32 is_active();
    void close();
    void update_mail_count();
    s32 refresh_mail_list(TWindowMenuIconLine *list);
    TWindowMenu *create_menu();
    TWindowMenu *build_menu();
    TWindowMenu *create_confirm_menu_window();
    TWindowMenu *create_window();
    static TWindowMenu *open_menu();

    static const char *class_name;

    u8 state;
    u8 pad_1d[0x3];
    s32 client_id;
    u32 mail_id;
    s32 card_index;
    s32 target_card_id;
    u32 reply_mail_id;
    TWindowMainMenu *parent;
    TWindowMenuIconLine *mail_list;
    TWindowMessage *message_window;
    TWindowMenu *main_menu;
    TWindowMenu *action_menu;
    TWindowMenu *auto_reply_window;
    TWindowMenu *auto_reply_menu;
    TWindowMessageYesNo *confirm_window;
    TWindowMenu *card_list;
    TWindowComCard *card_window;
    TKeyBoardControl *keyboard;
};

LAYOUT_ASSERT(TWindowSubShortMailKeyboardOffset, offsetof(TWindowSubShortMail, keyboard) == 0x5C);
LAYOUT_ASSERT(TWindowSubShortMail_size, sizeof(TWindowSubShortMail) == 0x60);
#endif
