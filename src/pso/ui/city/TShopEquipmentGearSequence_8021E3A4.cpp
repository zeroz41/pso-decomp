#include "types.h"
#include "pso/ui/city/TShopEquipmentGearSequence_8021B438.h"
#include "pso/ui/city/TShopItemTecSequence.h"
#include "pso/ui/city/TShopEquipmentGearSequence_8021E3A4.h"
#include "pso/ui/city/TShopEquipmentGearSequence.h"

extern "C" {

void *__nw__7TObjectFUl(int);

extern void *tl_05;

void *TShopEquipmentGearSequence::create_instance(void *arg0) {
    void *o = __nw__7TObjectFUl(0x38);
    if (o != NULL) {
        o = TShopEquipmentGearSequence__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}
}

    extern int TShopEquipmentGearSequence__window_slot_table[];
int get_equipment_gear_shop_window_slot(int a0) {  return TShopEquipmentGearSequence__window_slot_table[a0]; }

void *create_shop_item_tec_sequence(void *arg0) {
    void *o = __nw__7TObjectFUl(0x38);
    if (o != NULL) {
        o = TShopItemTecSequence__ct((u8 *)o, (s32)tl_05, (s32)arg0);
    }
    return o;
}

    extern int TShopItemTecSequence__slot_table[];
int get_item_technique_shop_slot(int a0) {  return TShopItemTecSequence__slot_table[a0]; }
