#include "pso/ui/city/THunterGuildWarning.h"
#include "pso/system/task/TObject_80019A50.h"

#include "types.h"

extern THunterGuildWarning *THunterGuildWarning__instance;

struct HGW_802119F0 { u8 pad[0x1c]; s32 state; s32 timer; };

void THunterGuildWarning::run_task() {
    HGW_802119F0 *self = (HGW_802119F0 *)this;
    switch (self->state) {
    case 0:
    case 1:
        if (--self->timer < 0) {
            queue_destruction__7TObjectFv(self);
        }
        break;
    case 2:
        break;
    }
}

THunterGuildWarning::~THunterGuildWarning() {
    close_windows();
    THunterGuildWarning__instance = NULL;
}

extern "C" {

void THunterGuildWarning__sub_802119CC(void *);

extern const char *THunterGuildWarning__name;

}
THunterGuildWarning::THunterGuildWarning(TObject *object, void *arg2) : TObject(object) {
    m_name = THunterGuildWarning__name;
    *(void **)((s8 *)this + 0x1C) = arg2;
    *(u32 *)((s8 *)this + 0x20) = 90;
    THunterGuildWarning__sub_802119CC(this);
    sub_80211774(*(void **)((s8 *)this + 0x1C));
    THunterGuildWarning__instance = this;
}
