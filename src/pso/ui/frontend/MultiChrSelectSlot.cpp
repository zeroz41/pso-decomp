#include "types.h"
#include "pso/ui/charcreate/CreationInput.h"
#include "pso/ui/frontend/MultiChrSelectSlot.h"
#include "pso/ui/frontend/TAdMultiPlyChrSelectGC.h"

void copy_creation_input_state(CreationInputState *dst, CreationInputState *src) {
    dst->reserved_0 = src->reserved_0;
    dst->repeat_direction = src->repeat_direction;
    dst->repeat_frames = src->repeat_frames;
    dst->held_buttons = src->held_buttons;
    dst->pressed_buttons = src->pressed_buttons;
    dst->repeated_buttons = src->repeated_buttons;
}

int is_multi_chr_select_slot_chosen() { return multi_chr_select_slot_chosen; }
