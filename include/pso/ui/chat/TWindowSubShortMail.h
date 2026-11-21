#ifndef PSO_UI_CHAT_TWINDOWSUBSHORTMAIL_H
#define PSO_UI_CHAT_TWINDOWSUBSHORTMAIL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TWindowSubShortMail : public TObject {
    TWindowSubShortMail(TObject *arg1, void *arg2);
    virtual ~TWindowSubShortMail();
    s32 create_list_item();
    s32 open_confirm_dialog();
    s32 open_delete_confirm_dialog();
    u8 m_1c;
    u8 _pad1D[0x3];
    uaddr m_20;
    u32 m_24;
    u32 m_28;
    u32 m_2c;
    u32 m_30;
    u32 m_34;
    uaddr m_38;
    uaddr m_3c;
    uaddr m_40;
    uaddr m_44;
    uaddr m_48;
    uaddr m_4c;
    uaddr m_50;
    uaddr m_54;
    uaddr m_58;
    uaddr m_5c;
    static s32 is_active();
    void close();
    void update_mail_count();
    s32 refresh_mail_list(void *arg1);
    virtual void render();
    virtual void run_task();
    void advance_line(s32 arg1);
    static u8 get_field_cc(void* p);
    static void *get_mail_ptr(void* p);
    static s32 create_menu();
    static s32 build_menu();
    static s32 create_keyboard();
    static s32 create_confirm_menu_window();
    static s32 create_window();
    static s32 open_menu();
};

LAYOUT_ASSERT(TWindowSubShortMail_size, sizeof(TWindowSubShortMail) == 0x60);
#endif
