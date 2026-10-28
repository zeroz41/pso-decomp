#include "types.h"
#include "pso/misc/TPlyGuildCardTag_8013ABCC.h"
#include "pso/TShopWindowBase.h"
#include "pso/TPlyGuildCardTag.h"
#include "pso/quest/TQuestListVM.h"

    extern int item_drop_server_seed;
    extern int area_random_seed;
extern u8 *TQuestListOnline__instance;

void *TPlyGuildCardTag::copy_full(void *arg1) {
    copy(arg1);
    ((TPlyGuildCardTag *)((char *)this + 36))->copy((void *)((char *)arg1 + 36));
    return this;
}
void*TPlyGuildCardTag::copy(void* a1) { *(void**)(this) = *(void**)((char*)a1 + 0x0); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x4), (void *)((char*)a1 + 0x4)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x8), (void *)((char*)a1 + 0x8)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0xc), (void *)((char*)a1 + 0xc)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x10), (void *)((char*)a1 + 0x10)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x14), (void *)((char*)a1 + 0x14)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x18), (void *)((char*)a1 + 0x18)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x1c), (void *)((char*)a1 + 0x1c)); TPlyGuildCardTag__sub_8013ACA4((void *)((char*)this + 0x20), (void *)((char*)a1 + 0x20)); return this; }
void TPlyGuildCardTag__sub_8013ACA4(void *arg0, void *arg1) {
    *(u8 *)((s8 *)arg0 + 0) = (u8) *(u8 *)((s8 *)arg1 + 0);
    *(u8 *)((s8 *)arg0 + 1) = (u8) *(u8 *)((s8 *)arg1 + 1);
    *(s16 *)((s8 *)arg0 + 2) = (s16) *(s16 *)((s8 *)arg1 + 2);
}
void __ct__16TPlyGuildCardTagFRC16TPlyGuildCardTag(void *arg0, void *arg1) {
    *(u8 *)((s8 *)arg0 + 0) = (u8) *(u8 *)((s8 *)arg1 + 0);
    *(u8 *)((s8 *)arg0 + 1) = (u8) *(u8 *)((s8 *)arg1 + 1);
    *(u16 *)((s8 *)arg0 + 2) = (u16) *(u16 *)((s8 *)arg1 + 2);
    *(s32 *)((s8 *)arg0 + 4) = (s32) *(s32 *)((s8 *)arg1 + 4);
}
void fn_8013ACE4(int a0) { item_drop_server_seed = a0; }
void set_area_random_seed(int a0) { area_random_seed = a0; }

void TQuestListOnline__sub_8013ACF4(s32 arg0) {
    if ((void *) TQuestListOnline__instance != NULL) {
        ((TShopWindowBase *)TQuestListOnline__instance)->set_field_20(arg0);
    }
}
