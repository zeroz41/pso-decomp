#include "pso/ui/frontend/TAdDrawLineTask.h"
#include "pso/unk/text_8001A3BC.h"

extern const f32 lbl_805D7DDC;

u8 *fn_8001A3BC(s32 parent, DrawLineRecord *draw_line_record, s32 arg2) {
    TAdDrawLineCtrl *controller = (TAdDrawLineCtrl *)arg2;
    DrawLineRecord *record = draw_line_record;
    if (record != NULL && lbl_805D7DDC != record->speed) {
        return (u8 *)new TAdDrawLineTask((TObject *)parent, record, controller);
    }
    return NULL;
}
