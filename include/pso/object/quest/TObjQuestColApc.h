#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLAPC_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLAPC_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColApc : public TObjQuestColBase {
    TObjQuestColApc(TObject *parent, void *set_data);
    virtual int is_triggered();
    virtual TQuestThread *start_quest_thread();
};

LAYOUT_ASSERT(TObjQuestColApc_size, sizeof(TObjQuestColApc) == 0xBC);

#endif
