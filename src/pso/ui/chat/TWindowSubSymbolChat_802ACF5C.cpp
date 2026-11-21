#include "types.h"
#include "pso/unk/text_8026CB5C.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"

void *create_callback_at_zero_vec2(void *callback) {
    s32 zero_vec2;

    zero_vec2 = (s32)get_zero_vec2();
    return TAdEnterSerialAccessGC::create_callback((void *)(get_zero_vec2()), (void *)zero_vec2, callback);
}
