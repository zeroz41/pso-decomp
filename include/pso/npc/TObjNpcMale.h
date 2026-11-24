#ifndef PSO_NPC_TOBJNPCMALE_H
#define PSO_NPC_TOBJNPCMALE_H
#include "types.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/object/base/TObjMotion.h"

// Base of the male town NPCs: idle and talk motions from PlyMotionNpcTown.
class TObjNpcMale : public TObjNpcBase {
public:
    TObjNpcMale(TObject *parent);
    virtual ~TObjNpcMale();
    virtual void request_action(s32 action);
    static void free_resources();
    static void load_resources();
    static const TObjMotionAction action_table[2];
    static u32 shared_resource;
};

#endif
