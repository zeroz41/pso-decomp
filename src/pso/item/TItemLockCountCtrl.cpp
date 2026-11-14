#include "pso/item/TItemLockCountCtrl.h"

extern "C" void mem_free(void*);

TItemLockCountCtrl::~TItemLockCountCtrl() {
    mem_free(this->m_20);
}

#include "types.h"

#pragma readonly_strings on

extern "C" {

s32 __ct__7TObjectFP7TObject();
void *mem_alloc(u32 size);
s32 memset(s32, s32, s32);

extern s32 __vt__18TItemLockCountCtrl[];
const char *lbl_805D2BF8 = "TItemLockCountCtrl";

void *TItemLockCountCtrl__ct(void *arg0, s32 arg1, s32 arg2, TItemLockCountCallback arg3, TItemLockCountCallback arg4) {
    s32 temp_r31;

    __ct__7TObjectFP7TObject();
    temp_r31 = arg2 * 4;
    *(s32 **)((s8 *)arg0 + 0x18) = __vt__18TItemLockCountCtrl;
    *(const char **)((s8 *)arg0 + 0) = lbl_805D2BF8;
    *(s32 *)((s8 *)arg0 + 0x1C) = arg2;
    *(s32 *)((s8 *)arg0 + 0x20) = (s32)mem_alloc(temp_r31);
    *(TItemLockCountCallback *)((s8 *)arg0 + 0x24) = arg3;
    *(TItemLockCountCallback *)((s8 *)arg0 + 0x28) = arg4;
    memset(*(s32 *)((s8 *)arg0 + 0x20), 0, temp_r31);
    return arg0;
}

}
