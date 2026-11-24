#include "pso/item/TItemLockCountCtrl.h"
#include "pso/boss/darkfalz/TOBoss4Rock.h"


TItemLockCountCtrl::~TItemLockCountCtrl() {
    mem_free(this->m_20);
}

#include "types.h"
#include <string.h>

#pragma readonly_strings on


const char *lbl_805D2BF8 = "TItemLockCountCtrl";

#define arg0 ((u8 *)this)
TItemLockCountCtrl::TItemLockCountCtrl(TObject *parent, s32 arg2, TItemLockCountCallback arg3, TItemLockCountCallback arg4) : TObject(parent) {
    s32 size;

    size = arg2 * 4;
    ((TItemLockCountCtrl *)arg0)->m_name = lbl_805D2BF8;
    *(s32 *)((s8 *)arg0 + 0x1C) = arg2;
    *(s32 *)((s8 *)arg0 + 0x20) = (saddr)mem_alloc(size);
    *(TItemLockCountCallback *)((s8 *)arg0 + 0x24) = arg3;
    *(TItemLockCountCallback *)((s8 *)arg0 + 0x28) = arg4;
    memset(*(void **)((s8 *)arg0 + 0x20), 0, size);
}
#undef arg0
