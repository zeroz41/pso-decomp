#ifndef PSO_RENDER_ALTMODEL_H
#define PSO_RENDER_ALTMODEL_H

#include "types.h"
#include "pso/system/NinjaTypes.h"

// The alt model's one chunk strip: a diffuse material chunk and the end marker.
struct AltChunkStrips {
    s16 header;
    s16 size;
    s32 diffuse;
    s16 end[2];
};

// The alt model: a one-strip chunk object drawn in front of a model to override
// its diffuse colour (set_alt_model_flag .. clear_alt_model_flag).
void update_lights();
void begin_alt_model_draw();
void clear_alt_model_flag();
void set_alt_model_flag();
NJS_OBJECT *prepend_alt_model(NJS_OBJECT *next, s32 diffuse);
void init_alt_model();
s32 split_screen_active();

#endif
