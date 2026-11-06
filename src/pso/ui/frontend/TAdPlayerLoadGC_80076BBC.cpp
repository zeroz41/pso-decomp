#include "types.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"

extern s32 card_load_sequence_state;

s32 TAdPlayerLoadGC::get_instance() {
    return card_load_sequence_state;
}
