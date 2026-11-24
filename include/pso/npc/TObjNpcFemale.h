#ifndef PSO_NPC_TOBJNPCFEMALE_H
#define PSO_NPC_TOBJNPCFEMALE_H
#include "types.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/object/base/TObjMotion.h"

// Base of the female town NPCs: idle and talk motions from PlyMotionNpcTown.
class TObjNpcFemale : public TObjNpcBase {
public:
    TObjNpcFemale(TObject *parent);
    virtual ~TObjNpcFemale();
    virtual void request_action(s32 action);
    static void free_resources();
    static void load_resources();
    static const TObjMotionAction action_table[2];
    static u32 shared_resource;
};

#endif
