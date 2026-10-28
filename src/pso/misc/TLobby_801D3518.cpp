#include "types.h"
#include "pso/quest/TQuestListVM_8007EAF8.h"
#include "pso/misc/TLobby.h"
#include "pso/TItemList.h"
#include "pso/player/TObjPlayer.h"

s32 TLobby::free_if_positive(s32 arg0, s16 arg1) {
    if ((arg0 != 0) && (arg1 > 0)) {
        __dl__FPv();
    }
    return arg0;
}
