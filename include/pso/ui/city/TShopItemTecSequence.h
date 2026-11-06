#ifndef PSO_UI_CITY_TSHOPITEMTECSEQUENCE_H
#define PSO_UI_CITY_TSHOPITEMTECSEQUENCE_H

#include "types.h"
#include "pso/ui/city/TShopSequence.h"

struct TShopItemTecSequence : public TShopSequence {
    virtual ~TShopItemTecSequence();
    virtual void vfunc_11();
    u8 unk_1C[0x4];
    u32 m_20;
    u8 unk_24[0x8];
    s32 m_2c;
    u8 unk_30[0x4];
    s32 m_34;
    s32 handle_select();
    s32 close_if_done();
    void open_sell_window();
    void open_item_list_window();
    void update_buy_sell_choice();
    s32 open_greeting();
};

typedef char TShopItemTecSequence_size[sizeof(TShopItemTecSequence) == 0x38 ? 1 : -1];

extern "C" {
u8 *TShopItemTecSequence__ct(u8 *arg0, s32 arg1, s32 arg2);
int TShopItemTecSequence__sub_8021FE6C(int a0);
void TShopItemTecSequence__sub_80220538(void);
void TShopItemTecSequence__sub_80220560(void);
u8 *__dt__20TShopItemTecSequenceFv(TShopItemTecSequence *arg0, s16 arg1);
void close__20TShopItemTecSequenceFPv(void *arg0);
void select_and_advance__20TShopItemTecSequenceFPv(void *arg0);
void set_judgment_target_flag(void *arg0, void *arg1);
}

// --- C functions defined in TShopItemTecSequence.cpp ---
extern "C" {
u8 *TShopItemTecSequence__ct(u8 *shop_item_tec_sequence, s32 arg1, s32 arg2);
int TShopItemTecSequence__sub_8021FE6C(int a0);
void TShopItemTecSequence__sub_80220538(void);
void TShopItemTecSequence__sub_80220560(void);
u8 *__dt__20TShopItemTecSequenceFv(TShopItemTecSequence *arg0, s16 arg1);
void close__20TShopItemTecSequenceFPv(void *shop_window_base);
void select_and_advance__20TShopItemTecSequenceFPv(void *shop_window_base);
void set_judgment_target_flag(void *arg0, void *arg1);
}
// --- end of C functions

#endif
