#include "types.h"
#include "pso/ui/frontend/TAdSubPlyItemGC.h"

extern "C" {

int draw_menu_font_string(void*, int, int);

int TAdSubPlyItemGC::render_status_line(int a1) { return draw_menu_font_string(this, a1, 0); }

}
