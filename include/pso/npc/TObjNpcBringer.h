#ifndef PSO_NPC_TOBJNPCBRINGER_H
#define PSO_NPC_TOBJNPCBRINGER_H
#include "types.h"
#include "pso/npc/TObjNpcBase.h"

class TObjNpcBringer : public TObjNpcBase {
public:
    TObjNpcBringer(TObject *parent, void *set_data);
    virtual ~TObjNpcBringer();
    virtual void request_action(s32);
public:
    static void *create(void *arg0);
};
typedef char TObjNpcBringer_size[sizeof(TObjNpcBringer) == 0x3B8 ? 1 : -1];

#endif
