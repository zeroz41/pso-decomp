#include "types.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/player/TObjPlayer_801D4CB8.h"
#include "pso/player/TObjPlayer.h"

    extern s32 inventory_walk_visit_count;
    extern s32 player_owner_collect_cursor;
int TObjPlayer::count_matching_items(int a1) { player_owner_collect_cursor = a1; inventory_walk_visit_count = 0; ((TObjPlayer *)(*(int *)&this->unk_1C4))->collect_item_owners_recursive(); return inventory_walk_visit_count; }

int TObjPlayer::apply_shop_judgment(int a1) { player_owner_collect_cursor = a1; inventory_walk_visit_count = 0; ((TObjPlayer *)(*(int *)&this->unk_1C4))->collect_alive_owners(); return inventory_walk_visit_count; }

    extern s32 item_reduce_target_player;
void TObjPlayer::set_flag_and_update(int a1) { item_reduce_target_player = a1; ((TObjPlayer *)(*(int *)&this->unk_1C4))->unequip_invalid_items_recursive(); }

struct Base_801D4D48 { char pad[0x18]; };
struct VObj_801D4D48 : Base_801D4D48 {
#define V8(b) virtual void b##0(); virtual void b##1(); virtual void b##2(); virtual void b##3(); virtual void b##4(); virtual void b##5(); virtual void b##6(); virtual void b##7();
    V8(a) V8(b) V8(c) V8(d)
    virtual void p32(); virtual void p33();
    virtual s32 m34();
};

extern "C" {

s32 lookup_item_def__9TItemDataFPv(s32);
void *get_owner_if_alive__10TObjPlayerFv(void *);
s32 all_parents_unqueued_for_destruction__7TObjectFv();

extern s32 inventory_search_item_data;

s32 TObjPlayer::count_items_by_id(s32 arg1) {
    void *temp_r3;

    if (lookup_item_def__9TItemDataFPv(arg1) != 0) {
        if (((u32 (*)(void *, s32))set_mode_and_refresh_object__10TObjPlayerFPvi)(this, arg1) != 0U) {
            temp_r3 = ((void *(*)())get_owner_if_alive__10TObjPlayerFv)();
            if ((temp_r3 != NULL) && (all_parents_unqueued_for_destruction__7TObjectFv() != 0)) {
                return ((VObj_801D4D48 *)temp_r3)->m34();
            }
        }
        return 0;
    }
    inventory_search_item_data = arg1;
    inventory_walk_visit_count = 0;
    ((TObjPlayer *)(*(s32 *)&this->unk_1C4))->count_items_recursive();
    return inventory_walk_visit_count;
}

}

#include "pso/system/task/TObject.h"

struct VB_801D4E94 { u8 pad[0x18]; };

struct V_801D4E94 : VB_801D4E94 {
    virtual void m0(); virtual void m1(); virtual void m2(); virtual void m3();
    virtual void m4(); virtual void m5(); virtual void m6(); virtual void m7();
    virtual void m8(); virtual void m9(); virtual void m10(); virtual void m11();
    virtual void m12(); virtual void m13(); virtual void m14(); virtual void m15();
    virtual void m16(); virtual void m17(); virtual void m18(); virtual void m19();
    virtual void m20(); virtual void m21(); virtual void m22(); virtual void m23();
    virtual void m24(); virtual void m25(); virtual void m26(); virtual void m27();
};

extern "C" {
s32 is_item_valid__9TItemListFl(void *);
int find_matching_inventory_item_node(void*);

void TObjPlayer::find_first_inventory_entry(int a1) { inventory_search_item_data = a1; ((TObjPlayer *)(*(int *)&this->unk_1C4))->find_inventory_item_matching_data(); }

void set_mode_and_refresh_object__10TObjPlayerFPvi(void* a0, int a1) { inventory_search_item_data = a1; find_matching_inventory_item_node((void*)(*(int*)((char*)a0 + 0x1c4))); }

    extern s32 inventory_walk_progress_count;
void TObjPlayer::destroy_subobjects(int a1) { item_reduce_target_player = a1; inventory_walk_progress_count = 0; ((TObjPlayer *)(*(int *)&this->unk_1C4))->destroy_subobjects_recursive(); queue_destruction__7TObjectFv((void *)(*(int *)&this->unk_1C4)); ((TObject *)(this->m_1c8))->run_tasks(); ((TObject *)(this->m_1c8))->run_tasks(); queue_destruction__7TObjectFv((void *)this->m_1c8); }

    extern s32 inventory_update_field_d8_key;

void TObjPlayer::destroy_subobjects_recursive() {
    u8 *p;
    V_801D4E94 *o;
    p = *(u8 * *)&this->m_down;
    while (p != NULL) {
        if (is_item_valid__9TItemListFl(p) != 0) {
            o = (V_801D4E94 *)get_owner_if_alive__10TObjPlayerFv(p);
            if (o != NULL && all_parents_unqueued_for_destruction__7TObjectFv() != 0) {
                o->m27();
            }
        }
        ((TObjPlayer *)p)->destroy_subobjects_recursive();
        p = *(u8 **)(p + 0xC);
    }
}

void TObjPlayer::start_inventory_update(int a1) { inventory_update_field_d8_key = a1; inventory_walk_progress_count = 0; ((TObjPlayer *)(*(int *)&this->unk_1C4))->find_inventory_item_by_field_d8(); }

}
