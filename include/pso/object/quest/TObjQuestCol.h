#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOL_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOL_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestCol : public TObjQuestColBase {
    virtual ~TObjQuestCol();
    virtual int vfunc_15();
    virtual int vfunc_16();
};

typedef char TObjQuestCol_size[sizeof(TObjQuestCol) == 0xBC ? 1 : -1];
#endif
