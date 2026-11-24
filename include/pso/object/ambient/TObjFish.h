#ifndef PSO_OBJECT_AMBIENT_TOBJFISH_H
#define PSO_OBJECT_AMBIENT_TOBJFISH_H

#include "types.h"

struct NJS_OBJECT;
struct NJS_TEXLIST;
#include "pso/object/base/TObjMotion.h"
#include <stddef.h>

// One fish of a school (0x44 bytes; init_fish_school allocates m_94 of them at m_a0).
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
    TObjFish(TObject *parent, void *set_data);
    virtual ~TObjFish();
    s32 init_fish_school(Vec *bounds, s32, s32);
    s32 update_state();
    virtual void render();
    virtual void run_task();
    s16 m_90;
    s16 m_92;
    u32 m_94;              // fish count
    u32 m_98;              // frame counter
    f32 m_9c;
    TObjFishEntry *m_a0;   // the fish
    static void reset_fish_globals();
    static void free_resource();
    static void load_area_resource();
    static s32 set_global_param(NJS_TEXLIST *texlist);
    static void *create(void *set_data);
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
#endif
