#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLAPC_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLAPC_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColApc : public TObjQuestColBase {
    TObjQuestColApc(TObject *parent, void *set_data);
    virtual int vfunc_15();
    virtual TQuestThread *vfunc_16();
};

LAYOUT_ASSERT(TObjQuestColApc_size, sizeof(TObjQuestColApc) == 0xBC);

#endif
