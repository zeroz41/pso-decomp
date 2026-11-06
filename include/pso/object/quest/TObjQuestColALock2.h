#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLALOCK2_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLALOCK2_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColALock2 : public TObjQuestColBase {
    virtual ~TObjQuestColALock2();
    virtual int vfunc_15();
    virtual void update_room_id_check();
    u8 unk_BC[0x4];
    s32 m_c0;
};

typedef char TObjQuestColALock2_size[sizeof(TObjQuestColALock2) == 0xC4 ? 1 : -1];
#endif
