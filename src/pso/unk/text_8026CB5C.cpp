#include "types.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/system/NinjaTypes.h"

// The constant points the window code takes by address, defined in this order.
static const NJS_POINT2 zero_vec2 = {0.0f, 0.0f};
static const NJS_POINT2 lbl_8044F4D0 = {1.0f, 1.0f};
static const NJS_POINT2 lbl_8044F4D8 = {10000.0f, 10000.0f};

const NJS_POINT2 *fn_8026CB5C(void) {
    return &lbl_8044F4D8;
}

const NJS_POINT2 *fn_8026CB68(void) {
    return &lbl_8044F4D0;
}
const NJS_POINT2 *get_zero_vec2(void) {
    return &zero_vec2;
}
