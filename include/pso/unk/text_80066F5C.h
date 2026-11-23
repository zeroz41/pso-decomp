#ifndef PSO_UNK_TEXT_80066F5C_H
#define PSO_UNK_TEXT_80066F5C_H

#include "types.h"

struct NJS_OBJECT;
struct NJS_TEXLIST;

// Draws object, its children and its siblings, each visible node also as a projected-shadow receiver.
void draw_shadowed_node_tree(NJS_OBJECT *object);
// Draws object's tree with shadows, its textures taken from texlist.
void draw_shadowed_object(NJS_TEXLIST *texlist, NJS_OBJECT *object);

#endif
