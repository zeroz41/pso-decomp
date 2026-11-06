#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLAPC_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLAPC_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColApc : public TObjQuestColBase {
    virtual ~TObjQuestColApc();
    virtual int vfunc_15();
    virtual int vfunc_16();
};

typedef char TObjQuestColApc_size[sizeof(TObjQuestColApc) == 0xBC ? 1 : -1];

extern "C" {
void *TObjQuestColApc__ct(void *arg0);
}

#endif
