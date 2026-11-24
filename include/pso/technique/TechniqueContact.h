#ifndef PSO_TECHNIQUE_CONTACT_H
#define PSO_TECHNIQUE_CONTACT_H
#include "types.h"

struct TechniqueContactActor;
struct TechniqueContactBody;
class TObjCollidable;
struct CollisionBody;

struct TechniqueContactList {
    TObjCollidable *actors[16];
    CollisionBody *bodies[16];
    s32 count;
    u32 reserved84;
};
// The contacts the last technique contact query found (TActorLight.cpp).
extern TechniqueContactList technique_contact_query_results;
struct TechniqueContactProjectile;
struct TechniqueContactVtable {
    u8 beforeWall[0x18];
    void (*wall)(TechniqueContactProjectile*);
    u32 unknown1c;
    void (*hit)(TechniqueContactProjectile*, TechniqueContactActor*);
};
struct TechniqueContactProjectile {
    u8 task[0x18];
    TechniqueContactVtable* vtable;
    TechniqueContactActor* source;
    u8 beforeBody[0xd8];
    TechniqueContactBody* contact;
    u8 beforeProxy[0x2c];
    TechniqueContactActor* proxy;
};
struct TechniqueContactPlayerSource {
    u8 beforeTargetMode[0x828];
    s32 targetMode;
};
LAYOUT_ASSERT(TechniqueContactList_size, sizeof(TechniqueContactList)==0x88);
LAYOUT_ASSERT(TechniqueContactProjectile_size, sizeof(TechniqueContactProjectile)==0x12c);
#endif
