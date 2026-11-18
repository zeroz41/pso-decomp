#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOL_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOL_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestCol : public TObjQuestColBase {
    TObjQuestCol(TObject *parent, void *set_data);
    virtual int vfunc_15();
    virtual TQuestThread *vfunc_16();
};

typedef char TObjQuestCol_size[sizeof(TObjQuestCol) == 0xBC ? 1 : -1];

#endif
