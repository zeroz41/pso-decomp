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
    // The three steps run_task calls on this.
    void update_toggle_state();
    void update_live_camera();
    void choose_next_camera_shot();
    s16 pad_1c;
    s16 pad_1e;
    s32 pad_20;
    u8 pad_24[0x4];
    s32 m_28;
    s32 pad_2c;
    f32 pad_30;
    f32 vector_34[3];
    f32 vector_40[3];
    s32 slot_index;
    TObject *camera_object;
    u8 rng[0xE8];  // a SubtractiveRng: the ctor runs __ct__14SubtractiveRngFv on it

public:
    static s32 get_table_entry(s32 arg0);
};

#include <stddef.h>
typedef char TObjLiveCameraCtrl_vector_34_offset[offsetof(TObjLiveCameraCtrl, vector_34) == 0x34 ? 1 : -1];
typedef char TObjLiveCameraCtrl_vector_40_offset[offsetof(TObjLiveCameraCtrl, vector_40) == 0x40 ? 1 : -1];
typedef char TObjLiveCameraCtrl_slot_index_offset[offsetof(TObjLiveCameraCtrl, slot_index) == 0x4c ? 1 : -1];
typedef char TObjLiveCameraCtrl_camera_object_offset[offsetof(TObjLiveCameraCtrl, camera_object) == 0x50 ? 1 : -1];
// create_boss8_demo_objects allocates 0x13C for it.
typedef char TObjLiveCameraCtrl_size[sizeof(TObjLiveCameraCtrl) == 0x13C ? 1 : -1];

#endif
