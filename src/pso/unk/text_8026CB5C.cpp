#include "types.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/system/NinjaTypes.h"

// The constant points the window code takes by address, defined in this order.
static const NJS_POINT2 zero_vec2 = {0.0f, 0.0f};
static const NJS_POINT2 one_vec2 = {1.0f, 1.0f};
static const NJS_POINT2 large_vec2 = {10000.0f, 10000.0f};

const NJS_POINT2 *get_large_vec2(void) {
    return &large_vec2;
}

const NJS_POINT2 *get_one_vec2(void) {
    return &one_vec2;
}
const NJS_POINT2 *get_zero_vec2(void) {
    return &zero_vec2;
}
