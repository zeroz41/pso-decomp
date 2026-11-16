#include "types.h"
#include "pso/player/TObjPlayer.h"
#include "pso/system/task/TObject.h"

extern "C" {

void *TTecJelin__ct(void *, void *, void *, void *, void *);

void TObjPlayer::create_tec_jelin(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *o;
    o = TObject::operator new(0x14C);
    if (o != NULL) {
        TTecJelin__ct(o, arg0, arg1, arg2, arg3);
    }
}

}
