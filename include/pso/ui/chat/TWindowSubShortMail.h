#ifndef PSO_UI_CHAT_TWINDOWSUBSHORTMAIL_H
#define PSO_UI_CHAT_TWINDOWSUBSHORTMAIL_H

#include <stddef.h>
#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowMainMenu;
class TWindowMenuIconLine;
struct TWindowMessage;

class TKeyBoardControl;

struct TWindowSubShortMail : public TObject {
    TWindowSubShortMail(TWindowMainMenu *parent, s32 client_id);
    virtual ~TWindowSubShortMail();
    virtual void run_task();
    virtual void render();
    TWindowMenuIconLine *create_list_item();
    static TKeyBoardControl *create_keyboard();
    static saddr open_confirm_prompt(void *parent, int client_id);
    saddr open_confirm_dialog();
    saddr open_delete_confirm_dialog();
    void find_target_user();
    static s32 is_active();
    void close();
    void update_mail_count();
    s32 refresh_mail_list(TWindowMenuIconLine *list);
    saddr create_menu();
    saddr build_menu();
    saddr create_confirm_menu_window();
    saddr create_window();
    static saddr open_menu();

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
    void *main_menu;
    void *action_menu;
    void *auto_reply_window;
    void *auto_reply_menu;
    void *confirm_window;
    void *card_list;
    void *card_window;
    TKeyBoardControl *keyboard;
};

LAYOUT_ASSERT(TWindowSubShortMailKeyboardOffset, offsetof(TWindowSubShortMail, keyboard) == 0x5C);
LAYOUT_ASSERT(TWindowSubShortMail_size, sizeof(TWindowSubShortMail) == 0x60);
#endif
