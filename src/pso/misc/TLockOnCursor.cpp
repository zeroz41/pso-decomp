#include "types.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/misc/TLockOnCursor.h"

extern "C" {

s32 __dt__13TLockOnCursorFis(s32 arg0, s16 arg1);

s32 TLockOnCursor::free_if_owned(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

s32 __dt__13TLockOnCursorFis(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}

}
