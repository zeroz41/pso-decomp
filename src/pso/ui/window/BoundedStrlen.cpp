#include "types.h"
#include "pso/ui/window/BoundedStrlen.h"

s32 bounded_strlen(const char *str, u32 max) {
    u32 i;
    if (str == 0) {
        return 0;
    }
    i = 0;
    while (*str != 0) {
        if (i >= max) {
            return max;
        }
        str++;
        i++;
    }
    return i;
}
