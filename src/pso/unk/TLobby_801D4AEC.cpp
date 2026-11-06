#include "types.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"

struct Base_801D4AEC { char pad[0x18]; };
#define CAT2(a,b) a##b
#define CAT(a,b) CAT2(a,b)
#define VA virtual void CAT(f,__LINE__)();
struct VObj_801D4AEC : Base_801D4AEC {
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
VA
    virtual void m27(s16);
VA
VA
VA
VA
VA
VA
    virtual s32 m34();
    virtual void m35(s32);
};

extern "C" {

void TLobby__sub_801D4C28(void* a0, int a1, int a2, int a3);
s32 try_spend_actor_meseta(u8 *arg0, s32 arg1);
s32 is_item_equipped(void *);
int TObjPlayer__sub_801D52A8(void*);
s32 queue_destruction__7TObjectFv(s32);
s32 start_inventory_update__10TObjPlayerFi(s32, s32);
s32 unequip_item__10TObjPlayerFiPv(s32, void *);

void TLobby::reduce_item_amount(s32 arg1, s32 arg2, s32 arg3) {
    s16 temp_r4;
    VObj_801D4AEC *player;

    player = (VObj_801D4AEC *)((TObjPlayer *)arg2)->get_owner_if_alive();
    if ((player != NULL) && (arg3 >= 0)) {
        if ((player->m34() - arg3) > 0) {
            player->m35(arg3);
            return;
        }
        if (is_item_equipped(player) != 0) {
            unequip_item__10TObjPlayerFiPv(arg1, player);
        }
        temp_r4 = *(s16 *)((s8 *)this + 0x1C);
        *(s16 *)((s8 *)this + 0x1C) = (temp_r4 - 1);
        player->m27(temp_r4);
        queue_destruction__7TObjectFv(arg2);
    }
}

s32 TLobby::use_item(s32 arg1, s32 arg2, s32 arg3) {
    s32 arg0 = (s32)this;
    s32 temp_r3;

    if (arg2 == -1) {
        try_spend_actor_meseta((u8 *)arg1, arg3);
        return 1;
    }
    temp_r3 = start_inventory_update__10TObjPlayerFi(arg0, arg2);
    if (temp_r3 == 0) {
        return 0;
    }
    reduce_item_amount(arg1, temp_r3, arg3);
    return 1;
}

    extern int item_reduce_target_player;
    extern unsigned char item_reduce_owner_match_field_ec;
    extern unsigned char reduce_owner_match_id;
void TLobby__sub_801D4C28(void* a0, int a1, int a2, int a3) { item_reduce_target_player = a1; item_reduce_owner_match_field_ec = a2; reduce_owner_match_id = a3; ((TLobby *)(*(int*)((char*)a0 + 0x1c4)))->reduce_owner_matched_items(); }

void TLobby::set_globals_and_update(int a1, int a2) { item_reduce_target_player = a1; item_reduce_owner_match_field_ec = a2; ((TLobby *)(*(int*)((char*)this + 0x1c4)))->reduce_child_item_amounts(); }

    extern int player_item_collect_cursor;
    extern int inventory_walk_visit_count;
int TLobby::set_globals_and_notify(int a1, int a2) { player_item_collect_cursor = a2; inventory_walk_visit_count = 0; TObjPlayer__sub_801D52A8((void*)(*(int*)((char*)this + 0x1c4))); return inventory_walk_visit_count; }

}
