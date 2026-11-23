#include "types.h"
#include "pso/ui/city/TShopItemTecSequence.h"
#include "pso/ui/city/TShopEquipmentGearSequence_8021E3A4.h"
#include "pso/ui/city/TShopEquipmentGearSequence.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

extern "C" {



void *TShopEquipmentGearSequence::create_instance(void *player) {
    return new TShopEquipmentGearSequence(tl_05, (TObjPlayer *)player);
}
}

    extern int TShopEquipmentGearSequence__window_slot_table[];
int get_equipment_gear_shop_window_slot(int a0) {  return TShopEquipmentGearSequence__window_slot_table[a0]; }

void *create_shop_item_tec_sequence(void *player) {
    return new TShopItemTecSequence(tl_05, (TObjPlayer *)player);
}

    extern int TShopItemTecSequence__slot_table[];
int get_item_technique_shop_slot(int a0) {  return TShopItemTecSequence__slot_table[a0]; }
