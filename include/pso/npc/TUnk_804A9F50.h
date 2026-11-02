#ifndef PSO_NPC_TUNK_804A9F50_H
#define PSO_NPC_TUNK_804A9F50_H
#include "types.h"
#include "pso/npc/TObjNpcBase.h"

class TUnk_804A9F50 : public TObjNpcBase {
public:
    virtual ~TUnk_804A9F50();
    virtual void request_action(s32 action);
};

extern "C" void *__dt__13TUnk_804A9F50Fv(void *, s16);

#endif
