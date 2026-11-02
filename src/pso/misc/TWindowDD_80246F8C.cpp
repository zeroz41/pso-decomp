#include "types.h"
#include "pso/misc/TWindowDD.h"

extern "C" {

s32 measure_message_text_width(f32);


void TWindowDD::refresh_status_display() {
    measure_message_text_width(1000000.0f);
}

}
