#include "musyx/runtime/musyx_runtime_b.h"

extern "C" {

f32* salMalloc(s32 bytes) {
    return (f32 *)salHooks.malloc(bytes);
}

void salFree(s32 arg0) {
    salHooks.free((void *)arg0);
}

}
