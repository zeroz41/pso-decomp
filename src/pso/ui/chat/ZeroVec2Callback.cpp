#include "types.h"
#include "pso/math/Vec2Constants.h"
#include "pso/ui/chat/TWindowSubSymbolChat.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"

void *create_callback_at_zero_vec2(WindowCallback callback) {
    const NJS_POINT2 *zero_vec2;

    zero_vec2 = get_zero_vec2();
    return TAdEnterSerialAccessGC::create_callback(get_zero_vec2(), zero_vec2, callback);
}
