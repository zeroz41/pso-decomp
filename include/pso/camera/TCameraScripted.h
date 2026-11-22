#ifndef PSO_CAMERA_TCAMERASCRIPTED_H
#define PSO_CAMERA_TCAMERASCRIPTED_H
#include "types.h"
#include "pso/camera/TCameraController.h"
#include "pso/camera/CameraAngles.h"
#include "pso/camera/CameraPlayback.h"
#include <dolphin/mtx.h>

// One camera motion of a loaded bank file.
struct CameraMotionData {
    void *keys;
    u32 frame_count;
};

// The root of a loaded camera bank file: its motions, indexed by
// CameraPlayback::index.
struct CameraMotionDirectory {
    CameraMotionData **motions;
};

// A camera bank file of a floor (CommonCam.rel, Bo01OpCam.rel...). The flags apply to
// every motion in it: 4 the motion is in world space (else relative to the
// scripted camera's origin and yaw), 0x80 look along the motion from 40 units
// behind it, 0x20 loop.
struct CameraBankFile {
    const char *filename;
    u32 flags;
};

struct CameraBankList {
    CameraBankFile *files;
    u32 count;
};

// A loaded camera bank file and the buffer it was loaded into.
struct CameraBank {
    CameraMotionDirectory *directory;
    void *buffer;
};

// The bank files of each floor area (get_current_floor_area()).
extern CameraBankList camera_path_bank_table[36];
// The floor's bank files, loaded by TCameraCtrl::load_camera_banks.
extern CameraBank camera_banks[8];

// The camera's projection angle when a scripted camera playback started, and the
// angle the playback asked for.
extern s32 saved_projection_angle;
extern s32 scripted_camera_projection_angle;

// What sample_camera_motion fills: a pointer per channel, then the channels.
struct CameraMotionSample {
    void *channels[4];
    Vec position;
    Vec direction;
    s32 roll;
    Vec channel_3;
    u8 defaults[0x2C]; // copied to a channel the motion has no keys for
};

// Camera mode 5: plays a motion of a loaded camera bank (boss intros and
// deaths), started through CameraPlayback::cache_target_and_forward.
class TCameraScripted : public TCameraController {
public:
    TCameraScripted();
    virtual ~TCameraScripted();
    static TCameraController *create();
    virtual void post_update_view();
    virtual void run_task();
    Vec position_origin;
    Vec target_origin;
    CameraAngles angles;
    CameraMotionData *motion;
    CameraBankFile *bank_file;
    CameraPlayback playback;
};
LAYOUT_ASSERT(TCameraScripted_size, sizeof(TCameraScripted) == 0xA4);
LAYOUT_ASSERT(TCameraScripted_position_origin, offsetof(TCameraScripted, position_origin) == 0x6C);
LAYOUT_ASSERT(TCameraScripted_playback, offsetof(TCameraScripted, playback) == 0x98);

#endif
