#include "types.h"
#include "pso/ui/window/TWindowBase.h"
#include "pso/ui/window/TWindowOptionCtrl_8026C40C.h"
#include "pso/ui/window/TWindowSubComCard_80244774.h"
#include "pso/ui/window/TWindowOptionCtrl.h"
#include "pso/ui/window/TWindowSubComCard.h"
#include "pso/ui/frontend/TAdPlayerLoadGC.h"
#include "pso/ui/window/TWindowOptionCtrl_8026C52C.h"

extern "C" {

extern s32 __vt__17TWindowOptionCtrl[];

s32 __dl__7TObjectFPv(void *);
s32 __dt__7TObjectFv(void *, s32);


void *__dt__17TWindowOptionCtrlFv(TWindowOptionCtrl *window_option_ctrl, s16 arg1) {
    if (window_option_ctrl != NULL) {
        *(void **)((s8 *)window_option_ctrl + 0x18) = (void *) __vt__17TWindowOptionCtrl;
        window_option_ctrl->apply_selection_change();
        if ((u32) window_option_ctrl->m_44 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)window_option_ctrl + 0x44)))->close();
            window_option_ctrl->m_44 = 0U;
        }
        if ((u32) window_option_ctrl->m_40 != 0U) {
            ((TWindowSubComCard *)(*(void **)((s8 *)window_option_ctrl + 0x40)))->close();
            window_option_ctrl->m_40 = 0U;
        }
        if ((u32) window_option_ctrl->m_3c != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)window_option_ctrl + 0x3C)))->close();
            window_option_ctrl->m_3c = 0U;
        }
        if ((u32) window_option_ctrl->m_38 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)window_option_ctrl + 0x38)))->close();
            window_option_ctrl->m_38 = 0U;
        }
        if ((u32) window_option_ctrl->m_34 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)window_option_ctrl + 0x34)))->close();
            window_option_ctrl->m_34 = 0U;
        }
        if ((u32) window_option_ctrl->m_30 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)window_option_ctrl + 0x30)))->close();
            window_option_ctrl->m_30 = 0U;
        }
        if ((u32) window_option_ctrl->m_2c != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)window_option_ctrl + 0x2C)))->close();
            window_option_ctrl->m_2c = 0U;
        }
        if ((u32) window_option_ctrl->m_28 != 0U) {
            ((TWindowBase *)(*(void **)((s8 *)window_option_ctrl + 0x28)))->close();
            window_option_ctrl->m_28 = 0U;
        }
        __dt__7TObjectFv(window_option_ctrl, 0);
        if (arg1 > 0) {
            __dl__7TObjectFPv(window_option_ctrl);
        }
    }
    return window_option_ctrl;
}

void __ct__7TObjectFP7TObject(void *);

const char *lbl_805D39A8 = "TWindowOptionCtrl";

void *TWindowOptionCtrl__ct(TWindowOptionCtrl *window_option_ctrl) {
    __ct__7TObjectFP7TObject(window_option_ctrl);
    *(s32 **)((s8 *)window_option_ctrl + 0x18) = __vt__17TWindowOptionCtrl;
    window_option_ctrl->m_name = lbl_805D39A8;
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
