#include "types.h"
#include "pso/ui/window/TWindowDD.h"
#include "pso/ui/window/WindowTextEntry.h"


void measure_message_text_width_default(void *entry) {
    static_cast<WindowTextEntry *>(entry)->measure_text(1000000.0f);
}
