#ifndef PSO_NPC_TOBJNPCFOMARL_H
#define PSO_NPC_TOBJNPCFOMARL_H
#include "types.h"
#include "pso/npc/TObjNpcBase.h"
#include "pso/object/base/TObjMotion.h"

// Base of the FOmarl-model town NPCs (HFW00/HFW01): talk motion 3.
class TObjNpcFomarl : public TObjNpcBase {
public:
    TObjNpcFomarl(TObject *parent);
    virtual ~TObjNpcFomarl();
    virtual void request_action(s32 action);
    static void free_resources();
    static void load_resources();
    static const TObjMotionAction action_table[2];
    static u32 shared_resource;
};

#endif
