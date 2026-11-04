#include "types.h"
#include "pso/unk/text_80145A44.h"
#include "pso/unk/text_803F4D84.h"
#include <string.h>

extern "C" {
BOOL fn_80145A44(char *dst) {
    if (TLobby__sub_803F524C(dst, 0x20) == 0) {
        return strlen(dst) != 0 ? TRUE : FALSE;
    }
    return FALSE;
}

}
