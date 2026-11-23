#include "types.h"
#include "pso/ui/window/TWindowCallBack.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/system/task/TObject.h"

extern "C" {


TWindowCallBack *TAdEnterSerialAccessGC::create_callback(void *position, void *scale, WindowCallback callback) {
    return new TWindowCallBack((u8 *)position, (u8 *)scale, callback);
}

}
