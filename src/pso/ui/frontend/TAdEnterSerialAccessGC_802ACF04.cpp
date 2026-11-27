#include "types.h"
#include "pso/ui/window/TWindowCallBack.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/system/task/TObject.h"


TWindowCallBack *TAdEnterSerialAccessGC::create_callback(const NJS_POINT2 *position, const NJS_POINT2 *scale, WindowCallback callback) {
    return new TWindowCallBack((u8 *)position, (u8 *)scale, callback);
}

