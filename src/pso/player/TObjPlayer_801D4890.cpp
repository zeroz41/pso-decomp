#include "types.h"
#include "pso/object/TObjMotion.h"
#include "pso/player/TObjPlayer.h"

#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
struct Base_A_801d48f8 { char pad[0x18]; };
struct V_A_801d48f8 : Base_A_801d48f8 {
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual void CAT(f,__LINE__)();
    virtual s32 m34();
    virtual void m35(s32);
};

extern "C" {
void remove_equipped_item__10TObjPlayerFPvii(void *, s32, s32);
s32 start_inventory_update__10TObjPlayerFi(void *, s32);
s32 TObjPlayer__sub_801D49F4(void *arg0, void *arg1, s32 *arg2, s32 arg3);
s32 place_on_ground__5TItemFsPfl(void *, s16, s32, s32);
void unequip_item__10TObjPlayerFiPv(s32 arg0, void *arg1);
s32 is_item_equipped(void *);
void *get_owner_if_alive__10TObjPlayerFv();
s32 queue_destruction__7TObjectFv(s32, s16);

    extern int TObjPlayer__owner_field_write_cursor;
    extern int inventory_walk_visit_count;
int TObjPlayer::run_and_get_result(int a1) { TObjPlayer__owner_field_write_cursor = a1; inventory_walk_visit_count = 0; ((TObjPlayer *)(*(int *)&this->unk_1C4))->collect_owner_fields_recursive(); return inventory_walk_visit_count; }

    extern int owned_item_export_cursor;
int TObjPlayer::run_state_query(int a1) { owned_item_export_cursor = a1; inventory_walk_visit_count = 0; ((TObjPlayer *)(*(int *)&this->unk_1C4))->count_owned_items(); return inventory_walk_visit_count; }

s32 TObjPlayer::update_inventory_item(s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 client) {
    s16 temp_r4;
    void *temp_r3_2;
    s32 temp_r3;

    if (arg4 < 0) {
        return 0;
    }
    temp_r3 = start_inventory_update__10TObjPlayerFi(this, arg2);
    if (temp_r3 == 0) {
        return 0;
    }
    temp_r3_2 = get_owner_if_alive__10TObjPlayerFv();
    if (temp_r3_2 == NULL) {
        return 0;
    }
    if ((((V_A_801d48f8 *) temp_r3_2)->m34() - arg4) > 0) {
        ((V_A_801d48f8 *) temp_r3_2)->m35(arg4);
        return 1;
    }
    if (is_item_equipped(temp_r3_2) != 0) {
        unequip_item__10TObjPlayerFiPv(arg1, temp_r3_2);
    }
    *(s16 *)((s8 *)temp_r3_2 + 0x28) = ((TObjBase *)arg1)->get_room();
    place_on_ground__5TItemFsPfl(temp_r3_2, client, arg3, 0);
    temp_r4 = *(s16 *)&this->entity_id;
    *(s16 *)&this->entity_id = (temp_r4 - 1);
    queue_destruction__7TObjectFv(temp_r3, temp_r4);
    return 1;
}
s32 TObjPlayer__sub_801D49F4(void *player, void *arg1, s32 *arg2, s32 arg3) {
    s32 i;
    s32 r;
    for (i = 0; i < arg3; arg2++, i++) {
        r = start_inventory_update__10TObjPlayerFi(player, *arg2);
        if (r == 0) {
            return 0;
        }
        ((void (*)(void *, void *, int)) remove_equipped_item__10TObjPlayerFPvii)(player, arg1, r);
    }
    return 1;
}

}

struct Base_801D4A6C { char pad[0x18]; };
struct VObj_801D4A6C : Base_801D4A6C {
    virtual void m0();
    virtual void m1();
    virtual void m2();
    virtual void m3();
    virtual void m4();
    virtual void m5();
    virtual void m6();
    virtual void m7();
    virtual void m8();
    virtual void m9();
    virtual void m10();
    virtual void m11();
    virtual void m12();
    virtual void m13();
    virtual void m14();
    virtual void m15();
    virtual void m16();
    virtual void m17();
    virtual void m18();
    virtual void m19();
    virtual void m20();
    virtual void m21();
    virtual void m22();
    virtual void m23();
    virtual void m24();
    virtual void m25();
    virtual void m26();
    virtual void m27(s16);
};

void remove_equipped_item__10TObjPlayerFPvii(void *arg0, s32 arg1, s32 arg2) {
    s16 temp_r4;
    void *temp_r3;

    temp_r3 = ((void *(*)(s32)) get_owner_if_alive__10TObjPlayerFv)(arg2);
    if (temp_r3 != NULL) {
        if (((s32 (*)()) is_item_equipped)() != 0) {
            unequip_item__10TObjPlayerFiPv(arg1, temp_r3);
        }
        temp_r4 = *(s16 *)((s8 *)arg0 + 0x1C);
        *(s16 *)((s8 *)arg0 + 0x1C) = (temp_r4 - 1);
        ((VObj_801D4A6C *)temp_r3)->m27(temp_r4);
        ((s32 (*)(s32)) queue_destruction__7TObjectFv)(arg2);
    }
}
