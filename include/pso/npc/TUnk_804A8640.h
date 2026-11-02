#ifndef PSO_NPC_TUNK_804A8640_H
#define PSO_NPC_TUNK_804A8640_H
#include "types.h"
#include "pso/npc/TObjNpcBase.h"

class TUnk_804A8640 : public TObjNpcBase {
public:
    virtual ~TUnk_804A8640();
    virtual void request_action(s32 action);
    u8 *construct_female_base();
    void *destroy_npc_female_base(s16);
};

#endif
