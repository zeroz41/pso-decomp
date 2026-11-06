#include "types.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"

void TWindowSubSymbolChat::update_display(s32 arg0) {
    s32 zero_vec2;

    zero_vec2 = (s32)get_zero_vec2();
    TAdEnterSerialAccessGC::create_callback((void *)(get_zero_vec2()), (void *)zero_vec2, (void *)arg0);
}
