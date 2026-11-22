#ifndef PSO_BOSS_DRAGON_TOBJBOSS1MOKOHILL_SOLO_H
#define PSO_BOSS_DRAGON_TOBJBOSS1MOKOHILL_SOLO_H
#include "types.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject.h"

// One mound of earth left behind on the Dragon's burrow path: it rises to peak_height, stays for
// hold_time frames, then sinks and destroys itself (TObjBoss1MokoHill_SoloM spawns it).
class TObjBoss1MokoHill_Solo : public TObject {
public:
    TObjBoss1MokoHill_Solo(TObject *parent, s32 hold_time);
    virtual ~TObjBoss1MokoHill_Solo();
    virtual void render();
    virtual void run_task();
    Vec *get_source_position();

    u8 pad_1C[0xC];
    Vec position;
    f32 height;      // 0x34: drawn height, -32 when it starts
    f32 peak_height; // 0x38
    s32 pad_3C;      // set to a random 20..40, never read
    s32 timer;       // 0x40: frames held at peak_height
    s32 state;       // 0x44: 0 rising, 1 holding, 2 sinking
    s32 v2_mode;     // 0x48: TObjEneDD::check_v2_mode() at creation; picks the material override in render
    s32 hold_time;   // 0x4C
};
LAYOUT_ASSERT(TObjBoss1MokoHill_Solo_size, sizeof(TObjBoss1MokoHill_Solo) == 0x50);

#endif
