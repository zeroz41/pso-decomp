#ifndef PSO_NPC_TOBJNPCNGCBASE_H
#define PSO_NPC_TOBJNPCNGCBASE_H

#include "types.h"
#include "pso/npc/TObjNpcMale.h"

struct BmlResource;
struct BmlResourceDescriptor;

// One body resource to load: the slot of TObjNpcNgcBase::body_resources it fills.
struct NpcBodyResourceSlot {
    s32 slot;
    BmlResourceDescriptor *descriptor;
};

// The GameCube-only story NPCs: one class, a body model per NPC type loaded per area.
struct TObjNpcNgcBase : public TObjNpcMale {
    TObjNpcNgcBase(TObject *parent, void *set_data, BmlResource *resource);
    virtual ~TObjNpcNgcBase();
    static void free_shared_resources();
    static void load_resources();
    static void *create_kenkyuw2(void *set_data);
    static void *create_nctrunk2(void *set_data);
    static void *create_nctrunk(void *set_data);
    static void *create_gunsinei(void *set_data);
    static void *create_ncman(void *set_data);
    static void *create_ncwoman(void *set_data);
    static void *create_ncchild(void *set_data);
    static void *create_elly_t(void *set_data);
    static void *create_nol_t(void *set_data);
    static void *create_delta_w(void *set_data);
    static void *create_paganini_t(void *set_data);
    static void *create_leo_w(void *set_data);
    static void *create_karen_t(void *set_data);
    static void *create_michel_t(void *set_data);

    static const char *class_name;

    // The loaded body BMLs by NPC slot (0 michel_t .. 13 kenkyuw2), NULL when not on this floor.
    static BmlResource *body_resources[14];
};

LAYOUT_ASSERT(TObjNpcNgcBase_size, sizeof(TObjNpcNgcBase) == 0x3B8);

#endif
