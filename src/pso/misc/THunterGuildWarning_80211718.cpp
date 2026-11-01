#include "types.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubComCard_80244774.h"
#include "pso/THunterGuildWarning.h"
struct Obj_802119CC { u8 pad[0x24]; s32 a[4]; };

struct S_80211718 { u8 pad[0x24]; u32 w[4]; };

extern "C" {
void THunterGuildWarning__sub_802119CC(Obj_802119CC *self);

void THunterGuildWarning::close_windows() {
    S_80211718 *self = (S_80211718 *)this;
    s32 i = 0;
    do {
        if (self->w[i] != 0) {
            ((TWindowBase *)(self->w[i]))->close();
            self->w[i] = 0;
        }
        i++;
    } while (i < 4);
}

void THunterGuildWarning__sub_802119CC(Obj_802119CC *self) {
    s32 i;
    for (i = 0; i < 4; i++) self->a[i] = 0;
}

}
