#include "types.h"
#include "pso/ui/window/TWindowDD.h"

extern "C" {

s32 measure_message_text_width(void *entry, f32 max_width);

void measure_message_text_width_default(void *entry) {
    measure_message_text_width(entry, 1000000.0f);
}

}
