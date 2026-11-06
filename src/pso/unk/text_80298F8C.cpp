#include "types.h"
#include "pso/ui/charcreate/CreationInput.h"

s32 creation_direction_repeated(s32 mask) {
    return (u8) ((creation_input_state.repeated_buttons & mask) != 0);
}
