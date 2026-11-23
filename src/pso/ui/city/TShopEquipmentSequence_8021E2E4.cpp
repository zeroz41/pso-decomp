#include "types.h"
#include "pso/ui/city/TMedicalCenterSequence.h"
#include "pso/ui/city/TShopEquipmentSequence_8021E2E4.h"
#include "pso/ui/city/TShopEquipmentSequence.h"
#include "pso/system/task/TObject.h"
#include "pso/system/task/TMainTask.h"

extern "C" {

void *TShopEquipmentSequence::create_instance(void *player) {
    return new TShopEquipmentSequence(tl_05, (TObjPlayer *)player);
}
}

    extern int TShopEquipmentSequence__slot_active_flags[];
int get_equipment_shop_slot_active_flag(int a0) {  return TShopEquipmentSequence__slot_active_flags[a0]; }

void *create_medical_center_sequence(void *player) {
    return new TMedicalCenterSequence(tl_05, (TObjPlayer *)player);
}

    extern int TMedicalCenterSequence__data_80513E90[];

int TMedicalCenterSequence__sub_8021E390(int a0) {  return TMedicalCenterSequence__data_80513E90[a0]; }
