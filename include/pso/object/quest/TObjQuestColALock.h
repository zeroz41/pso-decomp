#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLALOCK_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLALOCK_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColALock : public TObjQuestColBase {
    virtual ~TObjQuestColALock();
    virtual int vfunc_15();
    virtual int vfunc_16();
    virtual void update_room_id_check();
};

typedef char TObjQuestColALock_size[sizeof(TObjQuestColALock) == 0xBC ? 1 : -1];
#endif
