#ifndef PSO_ITEM_DROP_TITEMDROP_H
#define PSO_ITEM_DROP_TITEMDROP_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TItemDrop : public TObject {
    virtual ~TItemDrop();
    u32 m_1c;
    u32 m_20;
    static s32 run_step(s32 arg0);
    static void clear_item_if_player_picked_up(void* p, void* a1);
    static s32 calc_drop_offset(s32 arg0);
    static void set_drop_index(void *arg0, void *arg1);
    void select_unit_drop(u8 kind, u8 *item);
    static void init_drop_table();
    static void count_unit_star_buckets();
    static void refresh_drop_table_if_changed();
};

typedef char TItemDrop_size[sizeof(TItemDrop) == 0x24 ? 1 : -1];
#endif
