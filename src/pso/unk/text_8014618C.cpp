#include "types.h"
#include "pso/unk/text_8014618C.h"
#include "pso/unk/text_8042EE4C.h"


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
