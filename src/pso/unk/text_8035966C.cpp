#include "types.h"
#include "pso/unk/text_8035966C.h"
#include "pso/ui/window/TWindowCtrlMain.h"

extern "C" {
s32 __nw__7TObjectFUl(int);
s32 __ct__10TBoss4FadeFv(int, int);
}
extern s32 tl_clipout;
s32 create_boss4_fade(void) {
    s32 temp_r3;
    s32 var_r0;
    s32 instance;
    instance = TWindowCtrlMain::get_instance();
    if (instance == 0) {
        instance = tl_clipout;
    }
    temp_r3 = __nw__7TObjectFUl(0x38);
    var_r0 = temp_r3;
    if (var_r0 != 0) {
        var_r0 = __ct__10TBoss4FadeFv(temp_r3, instance);
    }
    return var_r0;
}
