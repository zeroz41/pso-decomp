#include "types.h"
#include "pso/boss/darkfalz/TBoss4Fade.h"
#include "pso/unk/text_8035966C.h"
#include "pso/ui/window/TWindowCtrlMain.h"

extern TObject *tl_clipout;
TBoss4Fade *create_boss4_fade() {
    TBoss4Fade *temp_r3;
    TBoss4Fade *var_r0;
    TObject *instance;
    instance = reinterpret_cast<TObject *>(TWindowCtrlMain::get_instance());
    if (instance == 0) {
        instance = tl_clipout;
    }
    temp_r3 = static_cast<TBoss4Fade *>(TObject::operator new(sizeof(TBoss4Fade)));
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = __ct__10TBoss4FadeFv(temp_r3, instance);
    }
    return var_r0;
}
