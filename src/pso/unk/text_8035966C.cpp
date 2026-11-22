#include "types.h"
#include "pso/boss/darkfalz/TBoss4Fade.h"
#include "pso/unk/text_8035966C.h"
#include "pso/ui/window/TWindowCtrlMain.h"
#include "pso/system/task/TObject.h"

extern TObject *tl_clipout;
TBoss4Fade *create_boss4_fade() {
    TObject *parent = reinterpret_cast<TObject *>(TWindowCtrlMain::get_instance());
    if (parent == NULL) {
        parent = tl_clipout;
    }
    return new TBoss4Fade(parent);
}
