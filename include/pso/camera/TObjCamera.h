#ifndef PSO_CAMERA_TOBJCAMERA_H
#define PSO_CAMERA_TOBJCAMERA_H

#include "types.h"
#include "pso/object/base/TObjMapObject.h"
#include "pso/effect/TEffStarLight2D.h"
#include <dolphin/mtx/GeoTypes.h>

struct BmlResource;

// A sound the camera plays once per motion loop, when its frame comes up.
struct CameraSoundEvent {
    Vec position;  // relative to the camera until init_sound_events places it
    f32 frame;
    s32 sound_id;
    u32 played;
};

LAYOUT_ASSERT(CameraSoundEventSize, sizeof(CameraSoundEvent) == 0x18);

// The security camera map object (set id 0x190): a model with eight star
// lights on its lamps, shown while the local player is near.
struct TObjCamera : public TObjMapObject {
    TObjCamera(TObject *parent, void *set_data);
    virtual ~TObjCamera();
    virtual s32 update_object_view_visibility(f32 radius, f32 depth);
    virtual void run_task();
    virtual void render();
    void play_sound_events();
    void reset_sound_events();
    void init_sound_events();
    static void *create(void *set_data);
    static void free_resources();
    static void load_resources();
    // The model node callback of render: records the view position of each
    // lamp node in camera_lamp_positions.
    static void record_lamp_positions(NJS_OBJECT *node);

    static BmlResource *model_resource;
    static s32 node_scan_index; // the model node record_lamp_positions is at

    s32 lights_visible;  // 1 while the local player is near enough to see its lights
    TEffStarLight2D *lights[8];  // its TEffStarLight2D lights, none in split screen
    CameraSoundEvent sound_events[8];
};

LAYOUT_ASSERT(TObjCamera_size, sizeof(TObjCamera) == 0x1AC);
#endif
