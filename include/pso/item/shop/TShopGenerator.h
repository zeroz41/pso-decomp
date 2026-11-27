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
    bool is_player_in_service_range(TObjBase *player, f32 range);
    virtual void run_task();
    u32 m_90;
    s32 service_check_delay; // frames to wait before the first service check (the constructor sets 5)
    static s32 is_no_service_active(void *self, TObjBase *player);
    static int is_slot_active(u16 client);
    static void clear_slot_active(u16 client);
    static void run_fn_table_reverse();
    static void run_fn_table_forward();
    static void *create(void *set_data);

    static ShopService service_dispatch_table[7];
    static const char *class_name;
    // One flag per client, indexed by get_client_split_screen_slot(entity id).
    static s32 slot_active_table[4];
};

LAYOUT_ASSERT(TShopGenerator_size, sizeof(TShopGenerator) == 0x98);

void set_shop_slot_active(u16 client);

// The service_dispatch_table entries: a counter's sequence factory and its per-slot active flag.
void *create_medical_center_sequence(void *player);
void *create_shop_item_tec_sequence(void *player);
int get_equipment_shop_slot_active_flag(int slot);
int get_medical_center_slot_active_flag(int slot);
int get_equipment_gear_shop_window_slot(int slot);
int get_item_technique_shop_slot(int slot);
int get_check_room_slot_active_flag(int slot);
int get_judgment_shop_slot_flags(int slot);

#endif
