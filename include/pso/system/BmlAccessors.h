#ifndef PSO_SYSTEM_BMLACCESSORS_H
#define PSO_SYSTEM_BMLACCESSORS_H

#include "types.h"

struct AnimationMotion;
struct BmlResource;
struct NJS_TEXLIST;
struct NJS_OBJECT;

AnimationMotion *get_bml_motion(BmlResource *resource, s32 index);
NJS_OBJECT *get_bml_model(BmlResource *resource, s32 index);
NJS_TEXLIST *get_bml_texlist(BmlResource *resource, s32 index);
// Whether the archive has finished loading (set_flag_and_notify sets 0x400 in its flags).
s32 is_bml_loaded(BmlResource *resource);

#endif
