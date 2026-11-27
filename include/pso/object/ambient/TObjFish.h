#ifndef PSO_OBJECT_AMBIENT_TOBJFISH_H
#define PSO_OBJECT_AMBIENT_TOBJFISH_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/object/base/TObjMotion.h"
#include <stddef.h>
#include "pso/system/BmlResourceDescriptor.h"

// One fish of a school (0x44 bytes; init_fish_school allocates fish_count of them at fish).
struct TObjFishEntry {
    Vec pos;         // relative to the school's position
    Vec target;
    Vec velocity;
    s32 yaw;
    f32 frame;
    s16 angle;
    s16 target_angle;
    s16 anim;
    s16 timer;
    s32 seen;        // render sets it when it retargets the fish at the camera; run_task clears it
    s32 mode;        // 1 while it swims back to its target
    u8 pad_3c[0x8];
};

struct TObjFish : public TObjBase {
    TObjFish(TObject *parent, ObjectSetData *data);
    virtual ~TObjFish();
    s32 init_fish_school(Vec *bounds, s32 anim0_count, s32 anim1_count);
    s32 update_state();
    virtual void render();
    virtual void run_task();
    s16 school_state;
    s16 state_timer;
    u32 fish_count;              // fish count
    u32 frame_counter;              // frame counter
    f32 school_radius;     // the larger of scale.x and scale.y
    TObjFishEntry *fish;   // the fish
    static void free_resource();
    static void load_area_resource();
    static void *create(ObjectSetData *set_data);
};

LAYOUT_ASSERT(TObjFishEntry_size, sizeof(TObjFishEntry) == 0x44);
LAYOUT_ASSERT(TObjFishEntry_target_offset, offsetof(TObjFishEntry, target) == 0xC);
LAYOUT_ASSERT(TObjFishEntry_velocity_offset, offsetof(TObjFishEntry, velocity) == 0x18);
LAYOUT_ASSERT(TObjFishEntry_yaw_offset, offsetof(TObjFishEntry, yaw) == 0x24);
LAYOUT_ASSERT(TObjFishEntry_frame_offset, offsetof(TObjFishEntry, frame) == 0x28);
LAYOUT_ASSERT(TObjFishEntry_angle_offset, offsetof(TObjFishEntry, angle) == 0x2C);
LAYOUT_ASSERT(TObjFishEntry_target_angle_offset, offsetof(TObjFishEntry, target_angle) == 0x2E);
LAYOUT_ASSERT(TObjFishEntry_anim_offset, offsetof(TObjFishEntry, anim) == 0x30);
LAYOUT_ASSERT(TObjFishEntry_timer_offset, offsetof(TObjFishEntry, timer) == 0x32);
LAYOUT_ASSERT(TObjFishEntry_seen_offset, offsetof(TObjFishEntry, seen) == 0x34);
LAYOUT_ASSERT(TObjFishEntry_mode_offset, offsetof(TObjFishEntry, mode) == 0x38);
LAYOUT_ASSERT(TObjFish_size, sizeof(TObjFish) == 0xA4);

struct TObjFishAreaResource {
    const char *models[4];
    const char *motions[4];
    BmlResourceDescriptor descriptor;
};

#endif
