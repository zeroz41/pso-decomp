#include "types.h"
#include "pso/item/TItem.h"
#include "pso/unk/TUnk_804F0FF0.h"

#include <stddef.h>
#include "pso/item/TItemProShield.h"
#include "pso/player/TObjPlayer.h"
struct Stack_80352A54 {
    s8 sp8;
    s8 sp9;
    s8 spA;
    u8 trailing_storage[0x11];
};

void TUnk_804F0FF0::vfunc_44() {
    s32 arg0 = (s32)this;
    typedef char sp8_offset[(offsetof(Stack_80352A54, sp8) == 0x0) ? 1 : -1];
    typedef char sp9_offset[(offsetof(Stack_80352A54, sp9) == 0x1) ? 1 : -1];
    typedef char spA_offset[(offsetof(Stack_80352A54, spA) == 0x2) ? 1 : -1];
    Stack_80352A54 stack;
    if ((((TItem *)arg0)->get_item_index() == 0) && (((TItem *)arg0)->get_item_flags() & 0x100)) {
        stack.sp8 = 3;
        stack.sp9 = 0x17;
        stack.spA = ((TItem *)arg0)->get_kill_count();
        replace_item_with_new_code((const TItemData *)&stack.sp8, (TItem *)arg0);
    }
}
