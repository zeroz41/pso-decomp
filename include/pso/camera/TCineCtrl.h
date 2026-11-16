#ifndef PSO_CAMERA_TCINECTRL_H
#define PSO_CAMERA_TCINECTRL_H

#include "types.h"
#include "pso/system/task/TObject.h"

struct TCineCtrl : public TObject {
    TCineCtrl();
    virtual ~TCineCtrl();
    void update_letterbox_show();
    void render();
    static void reset_state(s32 arg0);
    static void reset(s32 arg0);
    void run_task();
    u8 unk_1C[0x4];
    f32 m_20;
    u8 unk_24[0x3];
    s8 m_27;
    u8 unk_28[0x8];
    void update_letterbox_hide();
};

typedef char TCineCtrl_size[sizeof(TCineCtrl) == 0x30 ? 1 : -1];

#endif
