#include "types.h"
#include "pso/unk/text_8014618C.h"
#include "pso/ui/frontend/TAdTrialModemChkGC.h"

// Nonzero when the network adapter reports type 1; TAdExNetConfirmGC::vfunc_7 picks its
// message text by it.
s32 is_confirmed() {
    s32 adapter_type;

    get_network_adapter_type(&adapter_type);
    return (u32) __cntlzw(1 - adapter_type) >> 5;
}

s32 TLobby__sub_8014618C(void) {
    s32 status;

    get_network_adapter_type(&status);
    switch (status) {
    case 0:
    case 1:
    case 2:
        return 0;
    case 4:
    case 5:
        return 1;
    default:
        return 0;
    }
}
