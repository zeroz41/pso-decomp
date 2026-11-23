#ifndef PSO_OBJECT_AMBIENT_TOBJLIGHT_80235C44_H
#define PSO_OBJECT_AMBIENT_TOBJLIGHT_80235C44_H

#include "types.h"

class TObject;
class TObjBase;
class TActorLight;
struct NJS_ARGB;
struct Vec;

// --- C functions defined in TObjLight_80235C44.cpp ---
extern "C" {
TActorLight *construct_actor_light_task(TActorLight *light, NJS_ARGB *color, Vec *desired, s32 duration,
                                          TObjBase *source, f32 step, TObject *parent);
}
// --- end of C functions

// technique_contact_query_results: layout known from its uses only.
struct TechniqueContactQueryResults { s32 value; u8 remaining[0x84]; };
extern TechniqueContactQueryResults technique_contact_query_results;

#endif
