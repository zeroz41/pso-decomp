#ifndef PSO_UI_CITY_TSHOPEQUIPMENTGEARSEQUENCE_H
#define PSO_UI_CITY_TSHOPEQUIPMENTGEARSEQUENCE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TShopEquipmentGearSequence : public TShopSequence {
    TShopEquipmentGearSequence(TObject *parent, TObjPlayer *player);
    virtual ~TShopEquipmentGearSequence();
    virtual void vfunc_11();
    u32 m_2c;
    s32 m_30;
    TObject *counter_camera; // 0x34: set_service_counter_camera
    void open_gear_shop();
    void enter_quest_list();
    void handle_confirm();
    void try_close();
    void open_sell_window();
    void open_armor_list_window();
    static void update_buy_sell_choice(void *self);
    s32 open_greeting();
    static void clear_window_slots();
    static void clear_window_slot_table();
    static void *create_instance(void *arg0);
};

typedef char TShopEquipmentGearSequence_size[sizeof(TShopEquipmentGearSequence) == 0x38 ? 1 : -1];
#endif
