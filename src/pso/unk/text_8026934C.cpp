#include "pso/ui/window/TWindowMeseta.h"
#include "types.h"
#include "pso/unk/text_8026934C.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

extern "C" {
saddr get_window_layout_position(int);
#pragma push
#pragma scheduling off
TWindowMeseta *create_meseta_window(s32 client) {
    return new TWindowMeseta((void *)get_window_layout_position(0x28), client,
                             reinterpret_cast<saddr>(TWindowSubStatusDisp::get_message_10(0x82)));
}
#pragma pop

}
