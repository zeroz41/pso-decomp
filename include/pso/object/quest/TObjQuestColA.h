#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLA_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLA_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColA : public TObjQuestColBase {
    TObjQuestColA(TObject *parent, void *set_data);
    virtual int vfunc_15();
    virtual TQuestThread *vfunc_16();
};

typedef char TObjQuestColA_size[sizeof(TObjQuestColA) == 0xBC ? 1 : -1];

#endif
