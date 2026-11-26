#include "types.h"
#include "pso/unk/text_80145A44.h"
#include "pso/unk/text_803F4D84.h"
#include <string.h>


BOOL read_dial_prefix(char *dst) {
    if (get_network_config_outside_line_number(dst, 0x20) == 0) {
        return strlen(dst) != 0 ? TRUE : FALSE;
    }
    return FALSE;
}

