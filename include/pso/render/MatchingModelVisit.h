#ifndef PSO_RENDER_MATCHINGMODELVISIT_H
#define PSO_RENDER_MATCHINGMODELVISIT_H

#include "types.h"

struct NJS_OBJECT;
class UvScrollBuffer;

void visit_matching_models(UvScrollBuffer *buffer, NJS_OBJECT *root, s32 texture_id);

#endif
