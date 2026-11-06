#include "types.h"
#include "pso/unk/text_8042EE4C.h"
#include "pso/ui/frontend/TAdExNetConfirmGC.h"

s32 TAdExNetConfirmGC::is_confirmed() {
    s32 sp8;

    TLobby__sub_8042EE4C(&sp8);
    return (u32) __cntlzw(1 - sp8) >> 5;
}
