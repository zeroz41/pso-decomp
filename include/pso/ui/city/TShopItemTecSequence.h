#ifndef PSO_UI_CITY_TSHOPITEMTECSEQUENCE_H
#define PSO_UI_CITY_TSHOPITEMTECSEQUENCE_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TObjPlayer;
class TWindowBase;
struct TWindowMenu;
struct TShopJudgmentItemWindow;
struct TItemData;

struct TShopItemTecSequence : public TShopSequence {
    TShopItemTecSequence(TObject *parent, TObjPlayer *player);
    virtual ~TShopItemTecSequence();
    virtual void update_state();
    TWindowBase *meseta_window;     // 0x2C: create_meseta_window
    TWindowMenu *choice_menu;       // 0x30: the buy/sell create_window_menu
    TObject *counter_camera;        // 0x34: set_service_counter_camera
    void handle_select();
    void close_if_done();
    void open_sell_window();
    void open_item_list_window();
    void update_buy_sell_choice();
    void open_greeting();
};

LAYOUT_ASSERT(TShopItemTecSequence_size, sizeof(TShopItemTecSequence) == 0x38);
LAYOUT_ASSERT(TShopItemTecSequence_choice_menu_offset, offsetof(TShopItemTecSequence, choice_menu) == 0x30);

extern "C" {
int TShopItemTecSequence__sub_8021FE6C(int a0);
void TShopItemTecSequence__sub_80220538(void);
void TShopItemTecSequence__sub_80220560(void);
void close__20TShopItemTecSequenceFPv(TShopWindowBase *window);
void select_and_advance__20TShopItemTecSequenceFPv(TShopWindowBase *window);
void set_judgment_target_flag(TShopJudgmentItemWindow *window, TItemData *item);
}

#endif
