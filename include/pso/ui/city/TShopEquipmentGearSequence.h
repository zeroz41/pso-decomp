#ifndef PSO_UI_CITY_TSHOPEQUIPMENTGEARSEQUENCE_H
#define PSO_UI_CITY_TSHOPEQUIPMENTGEARSEQUENCE_H

#include <stddef.h>
#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TObjPlayer;
class TWindowBase;
struct TWindowMenu;

struct TShopEquipmentGearSequence : public TShopSequence {
    TShopEquipmentGearSequence(TObject *parent, TObjPlayer *player);
    virtual ~TShopEquipmentGearSequence();
    virtual void update_state();
    TWindowMenu *choice_menu;   // 0x2C: the buy/sell create_window_menu
    TWindowBase *meseta_window; // 0x30: create_meseta_window
    TObject *counter_camera;    // 0x34: set_service_counter_camera
    static void open_gear_shop(TShopWindowBase *sequence);   // the sell window's callbacks
    static void enter_quest_list(TShopWindowBase *sequence);
    void handle_confirm();
    void try_close();
    void open_sell_window();
    void open_armor_list_window();
    static void update_buy_sell_choice(void *self);
    void open_greeting();
    static void clear_window_slots();
    static void clear_window_slot_table();
    static void *create_instance(void *player);
};

LAYOUT_ASSERT(TShopEquipmentGearSequence_size, sizeof(TShopEquipmentGearSequence) == 0x38);
LAYOUT_ASSERT(TShopEquipmentGearSequence_choice_menu_offset, offsetof(TShopEquipmentGearSequence, choice_menu) == 0x2C);
#endif
