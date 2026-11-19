#include "types.h"
#include "pso/ui/window/TWindowCallBack.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"
#include "pso/system/task/TObject.h"

extern "C" {


void *TAdEnterSerialAccessGC::create_callback(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = new TWindowCallBack((s32)arg0, (u8 *)arg1, (s32)arg2);
    return o;
}

}
