#ifndef PSO_MISC_TWINDOWSUBSHORTMAIL_H
#define PSO_MISC_TWINDOWSUBSHORTMAIL_H

#include "types.h"
#include "pso/TObject.h"

struct TWindowSubShortMail : public TObject {
    TWindowSubShortMail(TObject *arg1, void *arg2);
    virtual ~TWindowSubShortMail();
    s32 create_list_item();
    s32 open_confirm_dialog();
    s32 open_delete_confirm_dialog();
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
    u32 m_40;
    u32 m_44;
    u32 m_48;
    u32 m_4c;
    u32 m_50;
    u32 m_54;
    u32 m_58;
    u32 m_5c;
    void hide_window();
    void set_position(void *arg1);
    static s32 is_active();
    void close();
    void update_mail_count();
    s32 refresh_mail_list(void *arg1);
    virtual void render();
    virtual void run_task();
    void notify_warp_flag70();
    void advance_line(s32 arg1);
};

typedef char TWindowSubShortMail_size[sizeof(TWindowSubShortMail) == 0x60 ? 1 : -1];
u8 *construct_status_category_window(u8 *arg0, s32 arg1, s32 arg2);
#endif
