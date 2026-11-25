#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/ui/frontend/TAdMcCheckGC.h"

TAdMcCheckGC *TAdMcCheckGC::get_instance(TObject *parent, s32 slot) {
    if (memcard_cursor_instance_table[slot] == NULL) {
        memcard_cursor_instance_table[slot] = new TAdMcCheckGC(parent, slot);
    }
    return memcard_cursor_instance_table[slot];
}
