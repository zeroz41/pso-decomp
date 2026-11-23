#ifndef PSO_UI_TLOGO_8001C134_H
#define PSO_UI_TLOGO_8001C134_H

#include "types.h"

struct NJS_TEXLIST;

extern NJS_TEXLIST texture_logo_e_descriptor;
extern NJS_TEXLIST *logo_texture_e_handle;

NJS_TEXLIST *get_logo_texture_e_handle(void);
void register_texture_logo_e(void);

#endif
