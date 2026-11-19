#include "types.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/frontend/TAdSinglePlyChrSelectGC.h"

s32 TAdPlayerLoadGC::get_instance() {
    return card_load_sequence_state;
}
