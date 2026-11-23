#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLA_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLA_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColA : public TObjQuestColBase {
    TObjQuestColA(TObject *parent, void *set_data);
    virtual int vfunc_15();
    virtual TQuestThread *vfunc_16();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TObjQuestColA_size, sizeof(TObjQuestColA) == 0xBC);

#endif
