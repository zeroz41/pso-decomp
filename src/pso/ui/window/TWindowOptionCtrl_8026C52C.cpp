#include "types.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/window/TWindowOptionCtrl_8026C52C.h"
#include "pso/ui/window/TWindowOptionCtrl.h"

extern "C" {

void __ct__7TObjectFP7TObject(void *);
void *__nw__7TObjectFUl(int);

extern s32 __vt__17TWindowOptionCtrl[];
extern void *lbl_805D39A8;

void *TWindowOptionCtrl__ct(TWindowOptionCtrl *window_option_ctrl) {
    __ct__7TObjectFP7TObject(window_option_ctrl);
    *(s32 **)((s8 *)window_option_ctrl + 0x18) = __vt__17TWindowOptionCtrl;
    *(void * *)&window_option_ctrl->m_name = lbl_805D39A8;
    window_option_ctrl->m_28 = 0;
    window_option_ctrl->m_2c = 0;
    window_option_ctrl->m_30 = 0;
    window_option_ctrl->m_34 = 0;
    window_option_ctrl->m_38 = 0;
    window_option_ctrl->m_3c = 0;
    window_option_ctrl->m_40 = 0;
    window_option_ctrl->m_44 = 0;
    window_option_ctrl->m_48 = 0;
    window_option_ctrl->player_load = new TAdPlayerLoadGC(window_option_ctrl, 2);
    window_option_ctrl->init_selection_indices();
    window_option_ctrl->m_24 = 4;
    window_option_ctrl->m_1d = 0;
    *(u8 *)((s8 *)window_option_ctrl + 0x1C) = 0;
    return window_option_ctrl;
}

}
