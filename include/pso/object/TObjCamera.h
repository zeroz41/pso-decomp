#ifndef PSO_OBJECT_TOBJCAMERA_H
#define PSO_OBJECT_TOBJCAMERA_H

#include "types.h"
#include "pso/misc/TUnk_804AFBF8.h"

struct TObjCamera : public TUnk_804AFBF8 {
    TObjCamera(TObject *parent, void *set_data);
    virtual ~TObjCamera();
    virtual s32 update_object_view_visibility(f32, f32);
    virtual void run_task();
    s32 lights_visible;  // 1 while the local player is near enough to see its lights
    void queue_target_destruction();
    virtual void render();
    static void *create(void *arg0);
    static void release_static_resource();
    static void load_shared_resource();
    static void update_camera_slots();
    void *lights[8];  // its TEffStarLight2D lights, none in split screen
    u8 unk_EC[0xC0];
};

typedef char TObjCamera_size[sizeof(TObjCamera) == 0x1AC ? 1 : -1];
#endif
