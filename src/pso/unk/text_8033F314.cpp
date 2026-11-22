#include "types.h"
#include "pso/unk/text_8033F314.h"
#include "pso/system/task/TObject.h"

extern "C" {
s32 __ct__12TAdMcCheckGCFP7TObjectl(int, void *, s32);
extern s32 memcard_cursor_instance_table[];
s32 fn_8033F314(saddr arg0, saddr arg1) {
    s32 temp_r30;
    s32 temp_r3;
    s32 var_r0;
    temp_r30 = arg1 * 4;
    if ((u32) *(s32 *)((s8 *)memcard_cursor_instance_table + temp_r30) == 0U) {
        temp_r3 = (saddr)TObject::operator new(0x3c);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = __ct__12TAdMcCheckGCFP7TObjectl((int)temp_r3, (void *)arg0, arg1);
        }
        *(s32 *)((s8 *)memcard_cursor_instance_table + temp_r30) = var_r0;
    }
    return *(s32 *)((s8 *)memcard_cursor_instance_table + temp_r30);
}

}
