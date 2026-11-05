#ifndef PSO_MISC_TWINDOWMESSAGEQUEST_H
#define PSO_MISC_TWINDOWMESSAGEQUEST_H

#include "types.h"
#include "pso/misc/TWindowMessage.h"

struct TWindowMessageQuest : public TWindowMessage {
    virtual ~TWindowMessageQuest();
    virtual void render();
    u8 unk_90[0x4];
};

typedef char TWindowMessageQuest_size[sizeof(TWindowMessageQuest) == 0x94 ? 1 : -1];

extern "C" {
void *__dt__19TWindowMessageQuestFv(void *arg0, s16 arg1);
}

extern "C" {
u8 *TWindowMessageQuest__ct(u8 *arg0, s32 arg1);
}

#endif
