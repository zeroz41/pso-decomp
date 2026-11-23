#ifndef PSO_CAMERA_TCAMERASCRIPTED_H
#define PSO_CAMERA_TCAMERASCRIPTED_H
#include "types.h"
#include "pso/camera/TCameraController.h"
#include "pso/camera/CameraAngles.h"
#include "pso/camera/CameraPlayback.h"
#include "pso/system/NinjaTypes.h"
#include "pso/animation/MotionContext.h"
#include <dolphin/mtx.h>

// The root of a loaded camera bank file: its motions, indexed by
// CameraPlayback::index.
struct CameraMotionDirectory {
    NJS_MOTION **motions;
};

// A camera bank file of a floor (CommonCam.rel, Bo01OpCam.rel...). The flags apply to
// every motion in it: 4 the motion is in world space (else relative to the
// scripted camera's origin and yaw), 0x80 look along the motion from 40 units
// behind it, 0x20 loop. The banks set 0x8 or 0x40 as well, which nothing reads,
// and none sets 0x80 or 0x20.
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
// The floor's bank files, loaded by load_camera_banks.
extern CameraBank camera_banks[8];

// The floor resource callbacks of the camera banks: load the current floor area's
// bank files, and free them.
void load_camera_banks();
void free_camera_banks();

// The camera's field of view when a scripted camera playback started, and the
// one the playback asked for.
extern s32 scripted_camera_saved_fov;
extern s32 scripted_camera_fov;

// What sample_camera_motion fills: a pointer per channel, then the channels.
struct CameraMotionSample {
    CameraMotionTargets channels;
    Vec position;
    Vec direction;
    s32 roll;
    s32 angle;
    u8 pad_30[0x8];
    CameraMotionPose defaults; // copied to a channel the motion has no keys for
    u8 pad_58[0xC];
};

// Camera mode 5: plays a motion of a loaded camera bank (boss intros and
// deaths), started through CameraPlayback::play.
class TCameraScripted : public TCameraController {
public:
    TCameraScripted();
    virtual ~TCameraScripted();
    static TCameraController *create();
    virtual void post_update_view();
    virtual void run_task();
    Vec position_origin;
    Vec target_origin; // set with position_origin, never read
    CameraAngles angles;
    NJS_MOTION *motion;
    CameraBankFile *bank_file;
    CameraPlayback playback;
};
LAYOUT_ASSERT(TCameraScripted_size, sizeof(TCameraScripted) == 0xA4);
LAYOUT_ASSERT(TCameraScripted_position_origin, offsetof(TCameraScripted, position_origin) == 0x6C);
LAYOUT_ASSERT(TCameraScripted_playback, offsetof(TCameraScripted, playback) == 0x98);

#endif
