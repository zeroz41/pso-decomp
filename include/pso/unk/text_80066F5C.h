#ifndef PSO_UNK_TEXT_80066F5C_H
#define PSO_UNK_TEXT_80066F5C_H

#include "types.h"

struct NJS_OBJECT;

// Draws object, its children and its siblings, each visible node also as a projected-shadow receiver.
void draw_shadowed_node_tree(NJS_OBJECT *object);

#endif
