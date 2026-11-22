#ifndef PSO_BOSS_DRAGON_TOBJBOSS1MOKOHILL_SOLOM_H
#define PSO_BOSS_DRAGON_TOBJBOSS1MOKOHILL_SOLOM_H
#include "types.h"
#include "pso/system/vector.h"
#include "pso/system/task/TObject.h"

// The mound that follows the burrowing Dragon (TBoss1Dragon::moko_hill). While active it raises the trail
// model under the Dragon's position, leaves a TObjBoss1MokoHill_Solo every 10 units it travels and throws
// rocks ahead of it. The static load/free pair builds and releases the run-time trail meshes.
class TObjBoss1MokoHill_SoloM : public TObject {
public:
    TObjBoss1MokoHill_SoloM(TObject *parent, Vec *position, s32 *heading);
    virtual ~TObjBoss1MokoHill_SoloM();
    virtual void render();
    virtual void run_task();
    void start_without_hold();
    void start();
    void stop();
    s32 is_dragon_trail_damaging();
    static void free_resources();
    static void load_resources();

    s32 active;          // 0x1C
    Vec last_position;   // 0x20: source position when travel_distance was last advanced
    f32 travel_distance; // 0x2C: distance since the last TObjBoss1MokoHill_Solo
    f32 base_height;     // 0x30: rises to 0 while active, -30 when stopped
    f32 height;          // 0x34: drawn height, held lower near craters
    s32 v2_mode;         // 0x38: TObjEneDD::check_v2_mode() at creation; picks the material override in render
    s32 no_hold;         // 0x3C: the mounds it leaves sink at once instead of holding 30 frames
};
LAYOUT_ASSERT(TObjBoss1MokoHill_SoloM_size, sizeof(TObjBoss1MokoHill_SoloM) == 0x40);

// Shifts the trail model's texture coordinates by position's x and z, so the ground texture stays put.
void update_dragon_trail_uvs(Vec *position);

#endif
