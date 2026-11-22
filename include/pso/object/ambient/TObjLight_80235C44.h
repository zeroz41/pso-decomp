#ifndef PSO_OBJECT_AMBIENT_TOBJLIGHT_80235C44_H
#define PSO_OBJECT_AMBIENT_TOBJLIGHT_80235C44_H

#include "types.h"

// --- C functions defined in TObjLight_80235C44.cpp ---
extern "C" {
u8 *construct_actor_light_task(u8 *arg0, NJS_ARGB *arg1, u8 *arg2, s32 arg3, u8 *arg4, u8 *parent, f32 farg0);
}
// --- end of C functions

// technique_contact_query_results: layout known from its uses only.
struct TechniqueContactQueryResults { s32 value; u8 remaining[0x84]; };
extern TechniqueContactQueryResults technique_contact_query_results;

#endif
