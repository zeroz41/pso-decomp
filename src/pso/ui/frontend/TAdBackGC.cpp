#include "types.h"
#include "pso/ui/frontend/TAdBackGC.h"

extern "C" {

int draw_title_background_quads(void*, int, int, int);

int draw_title_background_layer(void* p, int a1, int a2, f32 a3) { return draw_title_background_quads(p, a1, a2, 1); }
int render_logo_with_default(void* p, int a1, int a2, f32 a3) { return draw_title_background_quads(p, a1, a2, 0); }

}
