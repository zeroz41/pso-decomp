#include "types.h"
struct GetValidatedArrayValueObject { u8 pad[0x20]; s8 arr[1]; };

extern "C" {
u8 get_validated_array_value(GetValidatedArrayValueObject *p, s32 i);
u8 get_validated_array_value(GetValidatedArrayValueObject *p, s32 i) {
    s8 v = p->arr[i];
    if (v < 0 || v > 20) {
        p->arr[i] = 0;
    }
    return p->arr[i];
}

}
