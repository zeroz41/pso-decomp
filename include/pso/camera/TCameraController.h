#ifndef PSO_CAMERA_TCAMERACONTROLLER_H
#define PSO_CAMERA_TCAMERACONTROLLER_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class TCameraController : public TObject {
public:
    TCameraController();
    virtual ~TCameraController();
    void set_target(uaddr);
    virtual void vfunc_6();
    virtual void reset_state();
    virtual void vfunc_8(void *);
    virtual void vfunc_9(u8 *, u8 *);
    virtual void vfunc_10();
    virtual void post_update_view();
    virtual void run_task();
    uaddr actor; // inferred: set_target stores the followed object and m_20 its entity id
    u16 m_20;
    u8 unk_22[0x2];
    s32 m_24;
    u8 unk_28[0x4];
    s32 m_2c;
    s32 yaw; // inferred: the rotate_matrix_y angle TUnk_80488838 copies from the player's facing
    s32 m_34;
    s32 m_38;
    Vec position;
    Vec target;
    s32 projection_angle;
    f32 m_58;
    u8 unk_5C[0x4];
    f32 m_60;
    u8 unk_64[0x4];
    f32 m_68;
};

#endif
