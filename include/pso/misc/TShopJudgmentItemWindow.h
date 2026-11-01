#ifndef PSO_MISC_TSHOPJUDGMENTITEMWINDOW_H
#define PSO_MISC_TSHOPJUDGMENTITEMWINDOW_H

#include "types.h"
#include "pso/TShopWindowBase.h"

struct TShopJudgmentItemWindow : public TShopWindowBase {
    virtual ~TShopJudgmentItemWindow();
    virtual void vfunc_11();
    virtual void vfunc_8();
    virtual void display_message(const char *text, s32 flags);
    u8 _pad1C[0x4];
    u32 m_20;
    u32 m_24;
    u8 unk_28[0xC];
    s32 m_34;
    u8 unk_38[0x18];
    u32 m_50;
    u8 unk_54[0x1E];
    s16 m_72;
    u8 unk_74[0x2];
    s16 m_76;
    u8 unk_78[0xCC];
    u32 m_144;
    u32 m_148;
    u8 _pad14C[0x4];
    u32 m_150;
    u32 m_154;
    u32 m_158;
    u32 m_15c;
    u32 m_160;
    u32 m_164;
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
    void add_list_entry(s32 arg1, s32 arg2);
    void handle_pay_confirm();
    static int get_item_record(void* p);
    void update_judge_confirm();
    void handle_judge_confirm();
};

typedef char TShopJudgmentItemWindow_size[sizeof(TShopJudgmentItemWindow) == 0x178 ? 1 : -1];
#endif
