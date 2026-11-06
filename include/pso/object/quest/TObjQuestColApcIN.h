#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLAPCIN_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLAPCIN_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColApcIN : public TObjQuestColBase {
    virtual ~TObjQuestColApcIN();
    virtual int vfunc_15();
    virtual int vfunc_16();
    u8 unk_BC[0x4];
};

typedef char TObjQuestColApcIN_size[sizeof(TObjQuestColApcIN) == 0xC0 ? 1 : -1];

extern "C" {
void *TObjQuestColApcIN__ct(void *arg0);
}

#endif
