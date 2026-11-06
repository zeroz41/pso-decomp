#ifndef PSO_ITEM_TITEMLOAD_H
#define PSO_ITEM_TITEMLOAD_H

#include "pso/TObject.h"
#include "types.h"

class TItemLoad : public TObject {
public:
    virtual ~TItemLoad();
    virtual void run_task();
public:
    int update_item();
    void clear_slots();
    int get_ring_lobby();
    static void update_all();
    static void free_all_models();
    void start_load_with_id(s32 id, s32 arg2);
    void begin_load_if_pending(s32 arg1, s32 arg2);
    void reload_item();
    void reset_ring_state();
    void update_state();
    s32 begin_load(s32 arg1);
    void reset_state();
    void update_ring();
    void update_load_state();
    void advance_load_state();
    static s32 decompress_buffer(u32 arg0);
    static void free_boss4_rock();
    static void alloc_work_buffer();
    void request_load(s32 arg1);
    void free_texture();
    u32 load_data(s32 arg1);
    static s32 has_resource_id(s32 id);
    static void get_data_entry(s32 arg0, s32 *arg1);
    static void lookup_item_data(s32 arg0, s32 *arg1);
    static void get_item_params(s32 *arg0, s32 *arg1, s32 *arg2);
    static void get_model_ids(u8 arg0, s32 *arg1, s32 *arg2);
    static void *find_node_by_id(s32 id);
    static void release_resource_by_id(s32 id);
    static void update();
    static void free_all();
    static void init_resources();
    static void create();
};

extern "C" {
s32 TItemLoad__sub_801107DC(void *p);
s32 TItemLoad__sub_801107E4(void *p);
void *TItemLoad__sub_801107EC(void *p);
int TItemLoad__sub_801107F4(void *p);
}

#endif
