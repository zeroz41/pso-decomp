#ifndef PSO_UI_CITY_TSHOPITEMTECSEQUENCE_H
#define PSO_UI_CITY_TSHOPITEMTECSEQUENCE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

class TWindowBase;

struct TShopItemTecSequence : public TShopSequence {
    TShopItemTecSequence(TObject *parent, TObjPlayer *player);
    virtual ~TShopItemTecSequence();
    virtual void vfunc_11();
    TWindowBase *meseta_window;     // 0x2C: create_meseta_window
    TWindowBase *choice_menu;       // 0x30: the buy/sell create_window_menu
    TObject *counter_camera;        // 0x34: set_service_counter_camera
    s32 handle_select();
    s32 close_if_done();
    void open_sell_window();
    void open_item_list_window();
    void update_buy_sell_choice();
    s32 open_greeting();
};

LAYOUT_ASSERT(TShopItemTecSequence_size, sizeof(TShopItemTecSequence) == 0x38);

extern "C" {
int TShopItemTecSequence__sub_8021FE6C(int a0);
void TShopItemTecSequence__sub_80220538(void);
void TShopItemTecSequence__sub_80220560(void);
void close__20TShopItemTecSequenceFPv(void *arg0);
void select_and_advance__20TShopItemTecSequenceFPv(void *arg0);
void set_judgment_target_flag(void *arg0, void *arg1);
}

// --- C functions defined in TShopItemTecSequence.cpp ---
extern "C" {
int TShopItemTecSequence__sub_8021FE6C(int a0);
void TShopItemTecSequence__sub_80220538(void);
void TShopItemTecSequence__sub_80220560(void);
void close__20TShopItemTecSequenceFPv(void *shop_window_base);
void select_and_advance__20TShopItemTecSequenceFPv(void *shop_window_base);
void set_judgment_target_flag(void *arg0, void *arg1);
}
// --- end of C functions

#endif
