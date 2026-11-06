#include "types.h"
#include "pso/item/TItemList.h"
#include "pso/item/TItemList_801D57B0.h"
#include "pso/player/TObjPlayer_801D3554.h"
#include "pso/unk/TLobby.h"
#include "pso/player/TObjPlayer.h"

#pragma inline_depth(1)
#pragma auto_inline off
#pragma dont_inline off
typedef struct Rec_801D35FC {
    u8 b[0x1C];
} Rec_801D35FC;

struct ByteBlock_14 { u8 bytes[0x14]; };

extern "C" {
int TItemList__sub_801D5868(void*, void*);
void create_drop_nodes__9TItemListFPvPvPvPvi(void *arg0, void *arg1, void *arg2, Rec_801D35FC *arg3, s32 arg4);
s32 TItemList__sub_801D5854(s32, s32);
s32 copy_item_data__9TItemListFv(s32, s32);
s32 create_node__9TItemListFPvPvPvSc(s32, s32, s32, s32);

void insert_item_node__10TObjPlayerFiiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 temp_r31;
    s32 temp_r30;

    temp_r31 = TItemList__sub_801D5868((void*)arg0, (void*)(0));
    temp_r30 = TItemList__sub_801D5854(arg0, 0);
    if (TItemList__sub_801D5844((void *)temp_r31) != 0) {
        TItemList__sub_801D5838((void *)temp_r31);
        ((TObjPlayer *)temp_r30)->set_field4(arg4);
        copy_item_data__9TItemListFv(temp_r30, arg3);
        create_node__9TItemListFPvPvPvSc(arg0, arg2, arg1, 0);
        TItemList__sub_801D5804((s32 *)arg0);
    }
}

void create_drop_nodes__9TItemListFPvPvPvPvi(void *arg0, void *arg1, void *arg2, Rec_801D35FC *arg3, s32 arg4) {
    s32 i;
    u8 *p;
    Rec_801D35FC *q;

    p = (u8 *)TItemList__sub_801D5868(arg0, 0);
    q = (Rec_801D35FC *)((void *(*)(void *, s32))TItemList__sub_801D5854)(arg0, 0);
    for (i = 0; i < arg4; i++) {
        if (TItemList__sub_801D5844(p) != 0) {
            TItemList__sub_801D5838(p);
            ((void (*)(void *, void *))copy_drop_node)(q, arg3);
            ((void (*)(void *, void *, void *, s32))create_node__9TItemListFPvPvPvSc)(arg0, arg2, arg1, i);
            TItemList__sub_801D5804((s32 *)arg0);
            p += 4;
            q++;
            arg3++;
        }
    }
}
}

u8 *copy_drop_node(u8 *arg0, u8 *arg1) {
    u8 *temp_r4;
    u8 *temp_r5;
    fn_801D371C(arg0, arg1);
    temp_r5 = (arg0 + 4);
    temp_r4 = (arg1 + 4);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
    *(ByteBlock_14 *)((s32) temp_r5 + 4) = *(const ByteBlock_14 *)((s32) temp_r4 + 4);
    return arg0;
}

void fn_801D371C(void* p, void* q) { *(u32*)((char*)p + 0x0) = *(u32*)((char*)q + 0x0); }
void start_placement_search(s32 arg0, s32 arg1, s32 arg2) {
    TItemList__sub_801D5838(((void *)((s32)TItemList__sub_801D5868((void*)arg0, (void*)(0)))));
    TItemList__sub_801D3B00((void *)arg0, (void *)arg2, (void *)arg1, 0);
    TItemList__sub_801D5804((s32 *)arg0);
}
