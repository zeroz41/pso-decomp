#ifndef PSO_UI_CITY_TSHOPJUDGMENTITEMWINDOW_H
#define PSO_UI_CITY_TSHOPJUDGMENTITEMWINDOW_H

#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"

struct TShopJudgmentItemWindow : public TShopWindowBase {
    TShopJudgmentItemWindow(void *arg1, void *arg2, void *arg3);
    virtual ~TShopJudgmentItemWindow();
    virtual void vfunc_11();
    virtual void send_message(s32 id, s32 flags);
    virtual void display_message(const char *text, s32 flags);
    u8 unk_28[0xC];
    s32 m_34;
    u8 unk_38[0x18];
    uaddr result_item;
    u8 unk_54[0x1E];
    s16 m_72;
    u8 unk_74[0x2];
    s16 m_76;
    u8 unk_78[0xCC];
    u32 m_144;
    u32 item_count;
    s32 timer;  // frames left before the result can be dismissed
    u32 m_150;
    uaddr item_list;
    uaddr yes_no_menu;
    uaddr help_window;
    uaddr texture_window;
    TShopWindowBase *sequence;  // the TJudgmentSequence that opened it; messages go to it
    s32 at_tekker;
    void (*m_16c)(TShopWindowBase *sequence);
    void (*m_170)(TShopWindowBase *sequence);
    void (*m_174)(TShopWindowBase *sequence);
    void invoke_callback_174_and_destroy();
    void invoke_callback_16C_and_destroy();
    void invoke_callback_170_and_destroy();
    void update();
    void handle_equip_prompt();
    void create_result_windows();
    void handle_input();
    static void build_item_list(void *arg0);
    void close();
    static u8 *open_default(s32 a);
    void add_list_entry(saddr item, s32 arg2);
    void handle_pay_confirm();
    void update_judge_confirm();
    void handle_judge_confirm();
};

LAYOUT_ASSERT(TShopJudgmentItemWindow_size, sizeof(TShopJudgmentItemWindow) == 0x178);
#endif
