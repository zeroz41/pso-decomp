#include "pso/ui/frontend/TAdDrawLineTask.h"
#include "pso/unk/text_8001A3BC.h"

extern const f32 lbl_805D7DDC;

extern "C" u8 *fn_8001A3BC(s32 arg0, u8 *arg1, s32 arg2) {
    TAdDrawLineCtrl *controller = (TAdDrawLineCtrl *)arg2;
    DrawLineRecord *record = (DrawLineRecord *)arg1;
    if (record != NULL && lbl_805D7DDC != record->speed) {
        return (u8 *)new TAdDrawLineTask((TObject *)arg0, record, controller);
    }
    return NULL;
}
