#ifndef PSO_UI_CITY_TSHOPJUDGMENTITEMWINDOW_H
#define PSO_UI_CITY_TSHOPJUDGMENTITEMWINDOW_H

#include "types.h"
#include "pso/ui/city/TShopWindowBase.h"
#include "pso/item/TItemData.h"

struct TItem;
class TWindowMenuIconLine;
class TWindowShop;
struct TWindowMenu;
struct TWindowHelpItem;
struct TWindowLoadItemTexture;

// One row of the judgment list: an unidentified inventory item and its index in the list.
struct TShopJudgmentItemEntry {
    void set(TItem *item, s32 index);
    TItem *item;
    s32 index;
};

// The tekker's item list: picks an unidentified item, charges 100 meseta and swaps it for the
// identified one.
struct TShopJudgmentItemWindow : public TShopWindowBase {
    TShopJudgmentItemWindow(TObject *parent, TShopWindowBase *sequence, TObjPlayer *player);
    virtual ~TShopJudgmentItemWindow();
    virtual void update_state();
    virtual void send_message(s32 id, s32 flags);
    virtual void display_message(const char *text, s32 flags);
    TItemData judged_item;    // the selected item after the appraisal
    TItemData selected_item;  // the selected item as it was
    TItem *result_item;       // shown in the result list
    TShopJudgmentItemEntry entries[30];
    u32 pad_144;
    s32 item_count;
    s32 timer;  // frames left before the result can be dismissed
    u32 pad_150;
    TWindowMenuIconLine *item_list;
    TWindowMenu *yes_no_menu;
    TWindowHelpItem *help_window;
    TWindowLoadItemTexture *texture_window;
    TShopWindowBase *sequence;  // the TJudgmentSequence that opened it; messages go to it
    s32 at_tekker;
    void (*m_16c)(TShopWindowBase *sequence);
    void (*on_cancel)(TShopWindowBase *sequence); // state 10: the player backed out of the list
    void (*on_close)(TShopWindowBase *sequence);  // state 11: nothing to judge, no meseta, or done
    void invoke_callback_174_and_destroy();
    void invoke_callback_16C_and_destroy();
    void invoke_callback_170_and_destroy();
    void update();
    void handle_equip_prompt();
    void create_result_windows();
    void handle_input();
    void build_item_list();
    void close();
    static TWindowShop *open_default(s32 title);
    void handle_pay_confirm();
    void update_judge_confirm();
    void handle_judge_confirm();
};

LAYOUT_ASSERT(TShopJudgmentItemWindow_size, sizeof(TShopJudgmentItemWindow) == 0x178);
#endif
