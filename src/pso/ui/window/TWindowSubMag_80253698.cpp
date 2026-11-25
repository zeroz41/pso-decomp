#include "types.h"
#include "pso/unk/TWindowLayoutEntry.h"
#include "pso/ui/window/TWindowSubMag_80253698.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowSubStatusDisp.h"

#pragma push
#pragma opt_propagation off
s32 are_status_entries_ready__13TWindowSubMagFi(saddr help) {
    s32 window;
    saddr var_r3;
    s32 var_r4;
    TWindowLayoutEntry *entry_e;
    TWindowLayoutEntry *entry_5;
    TWindowLayoutEntry *entry_8;
    TWindowLayoutEntry *entry_b;
    var_r4 = 5;
    window = help;
    entry_5 = static_cast<TWindowLayoutEntry *>(((TWindowBase *)help)->get_array_entry(5));
    var_r3 = window;
    var_r4 = 8;
    entry_8 = static_cast<TWindowLayoutEntry *>(((TWindowBase *)var_r3)->get_array_entry(8));
    var_r3 = window;
    var_r4 = 0xB;
    entry_b = static_cast<TWindowLayoutEntry *>(((TWindowBase *)var_r3)->get_array_entry(0xB));
    var_r3 = window;
    var_r4 = 0xE;
    entry_e = static_cast<TWindowLayoutEntry *>(((TWindowBase *)var_r3)->get_array_entry(0xE));
    if (!(entry_5->flags & 4)) {
        var_r3 = 0;
        return 0;
    }
    if (!(entry_8->flags & 4)) {
        var_r3 = 0;
        return 0;
    }
    if (!(entry_b->flags & 4)) {
        var_r3 = 0;
        return 0;
    }
    var_r3 = (entry_e->flags >> 2U) & 1;
    return var_r3;
}
#pragma pop
