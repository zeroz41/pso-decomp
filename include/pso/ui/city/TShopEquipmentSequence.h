#ifndef PSO_UI_CITY_TSHOPEQUIPMENTSEQUENCE_H
#define PSO_UI_CITY_TSHOPEQUIPMENTSEQUENCE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

class TWindowBase;

struct TShopEquipmentSequence : public TShopSequence {
    TShopEquipmentSequence(TObject *parent, TObjPlayer *player);
    virtual ~TShopEquipmentSequence();
    void vfunc_11();
    s32 handle_confirm();
    s32 close_if_done();
    void update_buy_sell_choice();
    s32 open_greeting();
    static void *create_instance(void *arg0);
    TWindowBase *choice_menu;   // 0x2C: the buy/sell create_window_menu
    TWindowBase *meseta_window; // 0x30: create_meseta_window
    TObject *counter_camera; // 0x34: set_service_counter_camera
    void open_sell_window();
    void open_buy_window();
};

LAYOUT_ASSERT(TShopEquipmentSequence_size, sizeof(TShopEquipmentSequence) == 0x38);

// --- C functions defined in TShopEquipmentSequence.cpp ---
extern "C" {
s32 TShopEquipmentSequence__sub_8021D65C(void);
void TShopEquipmentSequence__sub_8021DBE0(void);
void TShopEquipmentSequence__sub_8021DC08(void);
void exit__22TShopEquipmentSequenceFPv(void *shop_window_base);
void init_window__22TShopEquipmentSequenceFPv(void *shop_window_base);
}
// --- end of C functions

#endif
