#ifndef PSO_UI_FRONTEND_TADDRAWLINECTRL_H
#define PSO_UI_FRONTEND_TADDRAWLINECTRL_H
#include "pso/system/task/TObject.h"
#include <stddef.h>

class TAdDrawLineCtrl : public TObject {
public:
    TAdDrawLineCtrl(TObject *arg1, void *arg2, f32 farg0);
    virtual ~TAdDrawLineCtrl();
    void sub_80019B08(s32);
    void set_draw_line_param_all_nodes(f32);
    void sub_80019B78(s32);
    virtual void run_task();
    virtual void render();
    void *line_data;
    TObject *child_root;
    u8 unknown_24[4];
    s32 render_mode;
};
typedef char TAdDrawLineCtrlSize[sizeof(TAdDrawLineCtrl) == 0x2C ? 1 : -1];
typedef char TAdDrawLineCtrlDataOffset[offsetof(TAdDrawLineCtrl, line_data) == 0x1C ? 1 : -1];
typedef char TAdDrawLineCtrlRootOffset[offsetof(TAdDrawLineCtrl, child_root) == 0x20 ? 1 : -1];
typedef char TAdDrawLineCtrlModeOffset[offsetof(TAdDrawLineCtrl, render_mode) == 0x28 ? 1 : -1];

extern "C" {
u8 *create_draw_line_ctrl__13TAdMcSelectGCFiif(s32 arg0, s32 arg1, f32 farg0);
}

#endif
