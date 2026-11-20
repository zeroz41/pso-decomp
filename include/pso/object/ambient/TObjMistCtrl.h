#ifndef PSO_OBJECT_AMBIENT_TOBJMISTCTRL_H
#define PSO_OBJECT_AMBIENT_TOBJMISTCTRL_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct TObjMistCtrl : public TObjBase {
    TObjMistCtrl(saddr parent, uaddr);
    virtual ~TObjMistCtrl();
    void sub_802AF64C();
    void run_task();
    u8 unk_90[0x4];
};

LAYOUT_ASSERT(TObjMistCtrl_size, sizeof(TObjMistCtrl) == 0x94);

extern "C" {
void *__dt__12TObjMistCtrlFv(void *arg0, s16 arg1);
}

#endif
