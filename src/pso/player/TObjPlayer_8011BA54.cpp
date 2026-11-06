#include "types.h"
#include "pso/player/TObjPlayer_8011BA54.h"

extern "C" {
s32 __ct__15TItemShootModelFPvPC3VecPC3Vecf(int, void *, void *, void *, f32);
s32 __nw__7TObjectFUl(int);
extern const f32 lbl_805DAC60;
s32 create_shoot_model__10TObjPlayerFUiiif(u32 owner, s32 arg1, s32 arg2, f32 farg0) {
    s32 temp_r3;
    s32 var_r0;
    s32 var_r3;
    var_r3 = 0;
    if ((lbl_805DAC60 != farg0) && (owner != 0U)) {
        temp_r3 = __nw__7TObjectFUl(0x6C);
        var_r0 = temp_r3;
        if (var_r0 != 0) {
            var_r0 = __ct__15TItemShootModelFPvPC3VecPC3Vecf((int)temp_r3, (void *)owner, (void *)arg1, (void *)arg2, (f32)farg0);
        }
        var_r3 = var_r0;
    }
    return var_r3;
}

}
