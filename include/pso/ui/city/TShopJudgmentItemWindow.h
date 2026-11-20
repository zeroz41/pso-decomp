#ifndef PSO_UI_CITY_TSHOPJUDGMENTITEMWINDOW_H
#define PSO_UI_CITY_TSHOPJUDGMENTITEMWINDOW_H

#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"

struct TShopJudgmentItemWindow : public TShopWindowBase {
    TShopJudgmentItemWindow(void *arg1, void *arg2, void *arg3);
    virtual ~TShopJudgmentItemWindow();
    virtual void vfunc_11();
    virtual void vfunc_8();
    virtual void display_message(const char *text, s32 flags);
    u8 _pad1C[0x4];
    u32 m_20;
    uaddr m_24;
    u8 unk_28[0xC];
    s32 m_34;
    u8 unk_38[0x18];
    uaddr m_50;
    u8 unk_54[0x1E];
    s16 m_72;
    u8 unk_74[0x2];
    s16 m_76;
    u8 unk_78[0xCC];
    u32 m_144;
    u32 m_148;
    u8 _pad14C[0x4];
    u32 m_150;
    uaddr m_154;
    uaddr m_158;
    uaddr m_15c;
    uaddr m_160;
    uaddr m_164;
    u8 _pad168[0x4];
    u32 m_16c;
    u32 m_170;
    u32 m_174;
    void invoke_callback_174_and_destroy();
    void invoke_callback_16C_and_destroy();
    void invoke_callback_170_and_destroy();
    void update();
    void handle_equip_prompt();
    void create_result_windows();
    void handle_input();
    static s32 build_item_list(void *arg0);
    void close();
    static void open_default(s32 a);
    void add_list_entry(saddr arg1, s32 arg2);
    void handle_pay_confirm();
    static int get_item_record(void* p);
    void update_judge_confirm();
    void handle_judge_confirm();
};

LAYOUT_ASSERT(TShopJudgmentItemWindow_size, sizeof(TShopJudgmentItemWindow) == 0x178);
#endif
