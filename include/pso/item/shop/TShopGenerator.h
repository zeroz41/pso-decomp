#ifndef PSO_ITEM_SHOP_TSHOPGENERATOR_H
#define PSO_ITEM_SHOP_TSHOPGENERATOR_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TShopGenerator : public TObjBase {
    TShopGenerator(saddr);
    virtual ~TShopGenerator();
    bool is_player_in_service_range(u8 *, f32);
    virtual void run_task();
    u32 m_90;
    s32 m_94; // frames to wait before the first service check (the constructor sets 5)
    static s32 is_no_service_active(void *self, saddr player);
    static int is_slot_active(u16 client);
    static void clear_slot_active(u16 client);
    static void run_fn_table_reverse();
    static void run_fn_table_forward();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TShopGenerator_size, sizeof(TShopGenerator) == 0x98);

extern "C" {
void THunterGuildSeqOffline__sub_8021E180(u16 client);
}

// One flag per client, indexed by get_client_split_screen_slot(entity id).
extern s32 TShopGenerator__slot_active_table[4];

#endif
