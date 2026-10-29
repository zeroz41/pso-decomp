#include "types.h"
#include "pso/ui/TAdMultiPlyChrSelectGC_802E0FC8.h"
#include "pso/ui/TUnk_804E3008.h"
#include "pso/ui/TAdMultiPlyChrSelectGC.h"

// The hand-written constructors below call the base one by its symbol.
extern "C" u8 *__ct__10TObjMotionFP7TObject(u8 *self);

struct RecoveredGlobal_802E1024_lbl_804E2F68 {
    s32 value;
    u8 remaining[0xC];
};

extern "C" {
s32 __nw__7TObjectFUl(int);
extern RecoveredGlobal_802E1024_lbl_804E2F68 multi_chr_select_player_slot_table;
void TLobby__sub_8001FE7C(void*, int);

extern s32 multi_chr_select_player_actor_ops[];

void *TUnk_804E3008::init_player(void *arg1, void *arg2, void *arg3, void *arg4) {
    __ct__10TObjMotionFP7TObject((u8 *)this);
    *(s32 **)((s8 *)this + 0x18) = multi_chr_select_player_actor_ops;
    *(void **)((s8 *)this + 0x10C) = arg4;
    this->m_108 = arg3;
    sub_802E0F58((s32)arg2);
    return this;
}

extern u32 TAdMultiPlyChrSelectGC__resource_bundle;

typedef char RecoveredGlobal_802E1024_lbl_804E2F68_size[sizeof(RecoveredGlobal_802E1024_lbl_804E2F68) == 0x10 ? 1 : -1];
s32 get_or_create_player__22TAdMultiPlyChrSelectGCFiiii(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_r30;
    s32 temp_r3;
    s32 var_r0;
    temp_r30 = arg3 * 4;
    if ((u32) *(s32 *)((s8 *)&multi_chr_select_player_slot_table.value + temp_r30) == 0U) {
        temp_r3 = __nw__7TObjectFUl(0x174);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = ((s32)((TUnk_804E3008 *)temp_r3)->init_player((void *)arg0, (void *)arg1, (void *)arg2, (void *)arg3));
        }
        *(s32 *)((s8 *)&multi_chr_select_player_slot_table.value + temp_r30) = var_r0;
    }
    return *(s32 *)((s8 *)&multi_chr_select_player_slot_table.value + temp_r30);
}

void TAdChrSelPlayerGC__sub_802E10A0(void) {
    if ((u32) TAdMultiPlyChrSelectGC__resource_bundle != 0U) {
        TLobby__sub_8001FE7C((void*)TAdMultiPlyChrSelectGC__resource_bundle, 1);
        TAdMultiPlyChrSelectGC__resource_bundle = 0U;
    }
}

}
