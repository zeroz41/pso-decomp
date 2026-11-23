#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOL_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOL_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestCol : public TObjQuestColBase {
    TObjQuestCol(TObject *parent, void *set_data);
    virtual int vfunc_15();
    virtual TQuestThread *vfunc_16();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjQuestCol_size, sizeof(TObjQuestCol) == 0xBC);

#endif
