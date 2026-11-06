#include "types.h"
#include "pso/ui/window/TWindowCallBack.h"
#include "pso/ui/frontend/TAdEnterSerialAccessGC.h"

extern "C" {

void *__nw__7TObjectFUl(int);

void *TAdEnterSerialAccessGC::create_callback(void *arg0, void *arg1, void *arg2) {
    void *o;
    o = __nw__7TObjectFUl(0x64);
    if (o != NULL) {
        o = TWindowCallBack__ct((u8 *)o, (s32)arg0, (u8 *)arg1, (s32)arg2);
    }
    return o;
}

}
