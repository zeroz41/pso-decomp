#ifndef PSO_UNK_TEXT_802F0E24_H
#define PSO_UNK_TEXT_802F0E24_H

#include "types.h"

struct BmlResource;
struct NJS_TEXLIST;

// bm_obj_boss7_common, loaded by load_boss7_common_resources, and its texture list.
extern BmlResource *boss7_common_bml_resource;
extern NJS_TEXLIST *boss7_common_texture_list;

// Shared by the Boss7 dust, raft splash and tunnel objects: the Boss7 tunnel clamps
// scroll_speed to it and the dust/splash objects drift by it each frame.
extern const f32 boss7_tunnel_max_scroll_speed;

void free_boss7_common_resources(void);
void load_boss7_common_resources(void);

#endif
