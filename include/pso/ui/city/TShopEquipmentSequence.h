#ifndef PSO_UI_CITY_TSHOPEQUIPMENTSEQUENCE_H
#define PSO_UI_CITY_TSHOPEQUIPMENTSEQUENCE_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TObjPlayer;
class TWindowBase;
struct TWindowMenu;

struct TShopEquipmentSequence : public TShopSequence {
    static s32 slot_active_flags[4];
    TShopEquipmentSequence(TObject *parent, TObjPlayer *player);
    virtual ~TShopEquipmentSequence();
    void update_state();
    void handle_confirm();
    void close_if_done();
    void update_buy_sell_choice();
    void open_greeting();
    static void *create_instance(TObjPlayer *player);
    TWindowMenu *choice_menu;   // 0x2C: the buy/sell create_window_menu
    TWindowBase *meseta_window; // 0x30: create_meseta_window
    TObject *counter_camera; // 0x34: set_service_counter_camera
    void open_sell_window();
    void open_buy_window();
    // Window callbacks: the player left the window / has nothing the shop buys.
    static void exit(TShopWindowBase *window);
    static void init_window(TShopWindowBase *window);
    static void init_slot_active_flags();
    static void release_slot_active_flags();
};

LAYOUT_ASSERT(TShopEquipmentSequence_size, sizeof(TShopEquipmentSequence) == 0x38);
LAYOUT_ASSERT(TShopEquipmentSequence_choice_menu_offset, offsetof(TShopEquipmentSequence, choice_menu) == 0x2C);

// --- C functions defined in TShopEquipmentSequence.cpp ---
void equipment_shop_state_stub(void);

#endif
