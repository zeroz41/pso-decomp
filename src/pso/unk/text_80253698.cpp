#include "types.h"
#include "pso/unk/text_80253698.h"
#include "pso/misc/TWindowBase.h"
#include "pso/misc/TWindowSubStatusDisp.h"

#pragma push
#pragma opt_propagation off
s32 are_status_entries_ready__13TWindowSubMagFi(s32 arg0) {
    s32 var_r28;
    s32 var_r3;
    s32 var_r4;
    u16 *temp_r3;
    u16 *var_r29;
    u16 *var_r30;
    u16 *var_r31;
    var_r4 = 5;
    var_r28 = arg0;
    var_r29 = (u16 *)(((TWindowBase *)arg0)->get_array_entry(5));
    var_r3 = var_r28;
    var_r4 = 8;
    var_r30 = (u16 *)(((TWindowBase *)var_r3)->get_array_entry(8));
    var_r3 = var_r28;
    var_r4 = 0xB;
    var_r31 = (u16 *)(((TWindowBase *)var_r3)->get_array_entry(0xB));
    var_r3 = var_r28;
    var_r4 = 0xE;
    temp_r3 = (u16 *)(((TWindowBase *)var_r3)->get_array_entry(0xE));
    if (!(*var_r29 & 4)) {
        var_r3 = 0;
        return 0;
    }
    if (!(*var_r30 & 4)) {
        var_r3 = 0;
        return 0;
    }
    if (!(*var_r31 & 4)) {
        var_r3 = 0;
        return 0;
    }
    var_r3 = ((u16) *temp_r3 >> 2U) & 1;
    return var_r3;
}
#pragma pop
