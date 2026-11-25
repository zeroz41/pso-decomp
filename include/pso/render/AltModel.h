#ifndef PSO_RENDER_ALTMODEL_H
#define PSO_RENDER_ALTMODEL_H

#include "types.h"

struct AltChunkObject;

// The alt model: a one-strip chunk object drawn in front of a model to override
// its diffuse colour (set_alt_model_flag .. clear_alt_model_flag).
void update_lights();
void begin_alt_model_draw();
void clear_alt_model_flag();
void set_alt_model_flag();
AltChunkObject *prepend_alt_model(AltChunkObject *next, s32 diffuse);
void init_alt_model();
s32 split_screen_active();

#endif
