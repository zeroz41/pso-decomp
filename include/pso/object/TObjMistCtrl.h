#ifndef PSO_OBJECT_TOBJMISTCTRL_H
#define PSO_OBJECT_TOBJMISTCTRL_H

#include "types.h"
#include "pso/object/TObjMotion.h"

struct TObjMistCtrl : public TObjBase {
    virtual ~TObjMistCtrl();
    void sub_802AF64C();
    void run_task();
    u8 unk_90[0x4];
};

typedef char TObjMistCtrl_size[sizeof(TObjMistCtrl) == 0x94 ? 1 : -1];

extern "C" {
u8 *TObjMistCtrl__ct(u8 *arg0, s32 parent, u32 arg2);
void *__dt__12TObjMistCtrlFv(void *arg0, s16 arg1);
}

#endif
