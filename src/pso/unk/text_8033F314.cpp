#include "types.h"
#include "pso/unk/text_8033F314.h"

extern "C" {
s32 __nw__7TObjectFUl(int);
s32 __ct__12TAdMcCheckGCFP7TObjectPv(int, void *, void *);
struct MemcardCursorInstanceTable { s32 value; u8 remaining[0x8]; };
extern MemcardCursorInstanceTable memcard_cursor_instance_table;
s32 fn_8033F314(s32 arg0, s32 arg1) {
    s32 temp_r30;
    s32 temp_r3;
    s32 var_r0;
    temp_r30 = arg1 * 4;
    if ((u32) *(s32 *)((s8 *)&memcard_cursor_instance_table.value + temp_r30) == 0U) {
        temp_r3 = __nw__7TObjectFUl(0x3c);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = __ct__12TAdMcCheckGCFP7TObjectPv((int)temp_r3, (void *)arg0, (void *)arg1);
        }
        *(s32 *)((s8 *)&memcard_cursor_instance_table.value + temp_r30) = var_r0;
    }
    return *(s32 *)((s8 *)&memcard_cursor_instance_table.value + temp_r30);
}

}
