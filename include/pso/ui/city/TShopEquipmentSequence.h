#ifndef PSO_UI_CITY_TSHOPEQUIPMENTSEQUENCE_H
#define PSO_UI_CITY_TSHOPEQUIPMENTSEQUENCE_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TObjPlayer;
class TWindowBase;
struct TWindowMenu;

struct TShopEquipmentSequence : public TShopSequence {
    TShopEquipmentSequence(TObject *parent, TObjPlayer *player);
    virtual ~TShopEquipmentSequence();
    void update_state();
    void handle_confirm();
    void close_if_done();
    void update_buy_sell_choice();
    void open_greeting();
    static void *create_instance(void *player);
    TWindowMenu *choice_menu;   // 0x2C: the buy/sell create_window_menu
    TWindowBase *meseta_window; // 0x30: create_meseta_window
    TObject *counter_camera; // 0x34: set_service_counter_camera
    void open_sell_window();
    void open_buy_window();
};

LAYOUT_ASSERT(TShopEquipmentSequence_size, sizeof(TShopEquipmentSequence) == 0x38);
LAYOUT_ASSERT(TShopEquipmentSequence_choice_menu_offset, offsetof(TShopEquipmentSequence, choice_menu) == 0x2C);

// --- C functions defined in TShopEquipmentSequence.cpp ---
extern "C" {
void TShopEquipmentSequence__sub_8021D65C(void);
void TShopEquipmentSequence__sub_8021DBE0(void);
void TShopEquipmentSequence__sub_8021DC08(void);
void exit__22TShopEquipmentSequenceFPv(TShopWindowBase *window);
void init_window__22TShopEquipmentSequenceFPv(TShopWindowBase *window);
}

#endif
