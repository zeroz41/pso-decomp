#ifndef PSO_UI_FRONTEND_TADDRAWLINECTRL_H
#define PSO_UI_FRONTEND_TADDRAWLINECTRL_H
#include "pso/system/task/TObject.h"
#include <stddef.h>
#include "pso/ui/frontend/DrawLineResource.h"

class TAdDrawLineCtrl : public TObject {
public:
    TAdDrawLineCtrl(TObject *parent, void *data, f32 depth);
    virtual ~TAdDrawLineCtrl();
    void start_lines_for_key(s32);
    void set_depth_all_nodes(f32);
    void start_line(s32);
    virtual void run_task();
    virtual void render();
    DrawLineGroup *line_data;
    TObject *child_root;
    f32 line_depth;
    s32 render_mode;
};
typedef char TAdDrawLineCtrlSize[sizeof(TAdDrawLineCtrl) == 0x2C ? 1 : -1];
typedef char TAdDrawLineCtrlDataOffset[offsetof(TAdDrawLineCtrl, line_data) == 0x1C ? 1 : -1];
typedef char TAdDrawLineCtrlRootOffset[offsetof(TAdDrawLineCtrl, child_root) == 0x20 ? 1 : -1];
typedef char TAdDrawLineCtrlDepthOffset[offsetof(TAdDrawLineCtrl, line_depth) == 0x24 ? 1 : -1];
typedef char TAdDrawLineCtrlModeOffset[offsetof(TAdDrawLineCtrl, render_mode) == 0x28 ? 1 : -1];

TAdDrawLineCtrl *create_draw_line_ctrl(TObject *parent, s32 group_index, f32 depth);

#endif
