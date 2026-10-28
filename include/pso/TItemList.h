#ifndef PSO_TITEMLIST_H
#define PSO_TITEMLIST_H
#include "pso/TObject.h"
#include "types.h"

class TItemList : public TObject {
public:
    virtual ~TItemList();
public:
    static u8 is_item_valid(s32 arg0);
    void *dt(s16 arg1);
    void *init_items();
    void *init_array();
    static void *create_node(void *arg0, void *arg1, void *arg2, s8 arg3);
    void *destroy(s16 arg1);
    int copy_item_data();
    void lookup_entry_by_count(s32 arg1);
    u8 get_item_count();
    void run_item_count_update();
public:
    u8 *ct_init_placement_ring(u8 *arg1, s32 arg2, u8 *arg3, u8 *arg4, s8 arg5);
};

#endif
