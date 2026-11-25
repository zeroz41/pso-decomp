#include "types.h"
#include "pso/ui/window/TWindowCheckBox.h"
#include "pso/ui/window/TWindowSubStatusDisp_80248BE8.h"
#include "pso/ui/window/TWindowSubStatusDisp_802671F0.h"

TWindowCheckBox *create_check_box_window_on_layer(const NJS_POINT2 *position, s32 size, s32 client) {
    TWindowCheckBox *window;

    TAdVIConfigGC__sub_80267704(0x23);
    window = TWindowCheckBox::create(position, size, client);
    TAdVIConfigGC__sub_80267704(3);
    return window;
}
