#ifndef PSO_UI_CITY_TSHOPEQUIPMENTSEQUENCE_H
#define PSO_UI_CITY_TSHOPEQUIPMENTSEQUENCE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TShopEquipmentSequence : public TShopSequence {
    virtual ~TShopEquipmentSequence();
    void vfunc_11();
    s32 handle_confirm();
    s32 close_if_done();
    void update_buy_sell_choice();
    s32 open_greeting();
    static void *create_instance(void *arg0);
    u8 unk_1C[0x4];
    u32 m_20;
    u8 unk_24[0x8];
    u32 m_2c;
    s32 m_30;
    u8 unk_34[0x4];
    void open_sell_window();
    void open_buy_window();
};

typedef char TShopEquipmentSequence_size[sizeof(TShopEquipmentSequence) == 0x38 ? 1 : -1];

extern "C" {
u8 *TShopEquipmentSequence__ct(u8 *arg0, s32 arg1, s32 arg2);
s32 TShopEquipmentSequence__sub_8021D65C(void);
void TShopEquipmentSequence__sub_8021DBE0(void);
void TShopEquipmentSequence__sub_8021DC08(void);
u8 *__dt__22TShopEquipmentSequenceFv(TShopEquipmentSequence *arg0, s16 arg1);
void exit__22TShopEquipmentSequenceFPv(void *arg0);
void init_window__22TShopEquipmentSequenceFPv(void *arg0);
}

// --- C functions defined in TShopEquipmentSequence.cpp ---
extern "C" {
u8 *TShopEquipmentSequence__ct(u8 *shop_equipment_sequence, s32 arg1, s32 arg2);
s32 TShopEquipmentSequence__sub_8021D65C(void);
void TShopEquipmentSequence__sub_8021DBE0(void);
void TShopEquipmentSequence__sub_8021DC08(void);
u8 *__dt__22TShopEquipmentSequenceFv(TShopEquipmentSequence *arg0, s16 arg1);
void exit__22TShopEquipmentSequenceFPv(void *shop_window_base);
void init_window__22TShopEquipmentSequenceFPv(void *shop_window_base);
}
// --- end of C functions

#endif
