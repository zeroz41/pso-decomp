#define TOBJECT_OUT_OF_LINE_HELPERS
#include "types.h"
#include "pso/ui/window/TWindowCtrl_8024A054.h"
#include "pso/system/task/TObject_80019A50.h"
#include "pso/ui/window/TWindowCtrl.h"
#include "pso/ui/frontend/TAdMultiChgGameModeGC.h"
#include "pso/system/task/TObject.h"

extern "C" {
extern struct Obj054_8024A054 *TWindowCtrl__active_window;
extern u16 lbl_805D63FC;
struct Obj054_8024A054 { char pad[0x38]; u32 field38; };

s32 get_multiplayer_controller_active_index(s32);
u32 get_player_by_client_id(s32);
s32 get_map_id__13TRaderMapCoreFv();

void TWindowCtrl::clear_flag() {
    if ((TWindowCtrl__active_window != NULL) && (TWindowCtrl__active_window->field38 != 0U)) {
        ((TWindowCtrl *)((void*)TWindowCtrl__active_window->field38))->clear_flag1e_bit8();
    }
}

void TWindowCtrl__sub_8024A08C(void) {
    u8 *object;
    lbl_805D63FC &= 0xFFFFFFFD;
    if ((void *) (*(u8 * *)&TWindowCtrl__active_window) != NULL) {
        object = (u8 *)(*(u8 **)((s8 *)(*(u8 * *)&TWindowCtrl__active_window) + 0x3C));
        if (object != NULL) {
            ((TObject *)object)->queue_destruction();
            *(u8 **)((s8 *)(*(u8 * *)&TWindowCtrl__active_window) + 0x3C) = NULL;
        }
    }
}

s32 is_player_input_active(s32 param_1) {
    if (param_1 >= 4) {
        return 0;
    }
    if (TAdMultiChgGameModeGC::is_input_phase_active() != 0) {
        return get_multiplayer_controller_active_index(param_1);
    }
    if (get_player_by_client_id(param_1) == 0U) {
        return 0;
    }
    return get_map_id__13TRaderMapCoreFv();
}

}
