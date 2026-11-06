#ifndef PSO_CAMERA_TOBJLIVECAMERACTRL_H
#define PSO_CAMERA_TOBJLIVECAMERACTRL_H

#include "pso/system/task/TObject.h"
#include "types.h"

class TObjLiveCameraCtrl : public TObject {
public:
    TObjLiveCameraCtrl(TObject *parent);
    virtual ~TObjLiveCameraCtrl();
    void sub_8030B818(int);
    virtual void run_task();
    u8 unk_1C[0xC];
    s32 m_28;
    u8 unk_2C[0x8];
    f32 vector_34[3];
    f32 vector_40[3];
    s32 slot_index;
    TObject *camera_object;

public:
    static s32 get_table_entry(s32 arg0);
};

#include <stddef.h>
typedef char TObjLiveCameraCtrl_vector_34_offset[offsetof(TObjLiveCameraCtrl, vector_34) == 0x34 ? 1 : -1];
typedef char TObjLiveCameraCtrl_vector_40_offset[offsetof(TObjLiveCameraCtrl, vector_40) == 0x40 ? 1 : -1];
typedef char TObjLiveCameraCtrl_slot_index_offset[offsetof(TObjLiveCameraCtrl, slot_index) == 0x4c ? 1 : -1];
typedef char TObjLiveCameraCtrl_camera_object_offset[offsetof(TObjLiveCameraCtrl, camera_object) == 0x50 ? 1 : -1];

#endif
