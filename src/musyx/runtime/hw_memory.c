#include "musyx/runtime/musyx_internal.h"

extern "C" {

f32* salMalloc(s32 bytes) {
    return (f32 *)salHooks.malloc(bytes);
}

void salFree(saddr addr) {
    salHooks.free((void *)addr);
}

}
