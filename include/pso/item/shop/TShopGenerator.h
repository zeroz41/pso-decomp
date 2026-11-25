#ifndef PSO_ITEM_SHOP_TSHOPGENERATOR_H
#define PSO_ITEM_SHOP_TSHOPGENERATOR_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

// One shop counter of the generator's set (set_params[0] picks it). Field names follow the targets and the
// callers: run_fn_table_forward/run_fn_table_reverse call the two hooks, run_task opens the counter's sequence
// through create and checks the per-client flag through get_slot_flag.
struct ShopService {
    const char *name;
    void (*forward_fn)();
    void (*reverse_fn)();
    void *(*create)(void *player);
    int (*get_slot_flag)(int slot);
};

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
    static ShopService service_dispatch_table[7];
    static const char *class_name;
    static s32 slot_active_table[4];
};

LAYOUT_ASSERT(TShopGenerator_size, sizeof(TShopGenerator) == 0x98);

void set_shop_slot_active(u16 client);

// One flag per client, indexed by get_client_split_screen_slot(entity id).

#endif
