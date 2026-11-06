#ifndef PSO_OBJECT_QUEST_TOBJQUESTCOLAPCINW_H
#define PSO_OBJECT_QUEST_TOBJQUESTCOLAPCINW_H

#include "types.h"
#include "pso/object/quest/TObjQuestColBase.h"

struct TObjQuestColApcINW : public TObjQuestColBase {
    virtual ~TObjQuestColApcINW();
    virtual int vfunc_15();
    virtual int vfunc_16();
    u8 unk_BC[0x4];
    void* m_c0;
    u8 unk_C4[0x4];
    f32 m_c8;
};

typedef char TObjQuestColApcINW_size[sizeof(TObjQuestColApcINW) == 0xCC ? 1 : -1];

extern "C" {
void *TObjQuestColApcINW__ct(TObjQuestColApcINW *arg0);
}

#endif
