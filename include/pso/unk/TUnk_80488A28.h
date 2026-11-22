#ifndef PSO_UNK_TUNK_80488A28_H
#define PSO_UNK_TUNK_80488A28_H
#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

class TUnk_80488A28 : public TObject {
public:
    TUnk_80488A28();
    virtual ~TUnk_80488A28();
    void set_target(uaddr);
    void set_target_pos(Vec *pos);
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
    s32 yaw; // inferred: the rotate_matrix_y angle TCameraOrbit copies from the player's facing
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
