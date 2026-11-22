#ifndef PSO_BOSS_DARKFALZ_TOBJDFHORMING_H
#define PSO_BOSS_DARKFALZ_TOBJDFHORMING_H

#include "types.h"
#include "pso/object/base/TObjChara.h"
#include <dolphin/mtx.h>
#include <stddef.h>

class TParticleCtrl;

// Dark Falz's homing shot (TBoss4Type3::create_horming): it dives, steers onto the player it chases and hits it.
struct TObjDFHorming : public TObjChara {
    TObjDFHorming(TObject *parent, const Vec *position, u16 target_id);
    virtual ~TObjDFHorming();
    virtual void run_task();
    void approach_target_height();
    void steer_homing_direction();
    void check_attack_trigger();
    static s32 is_boss_active();
    static void queue_destruction(TObject *object);
    using TObject::queue_destruction;

    u16 target_id; // client id of the player it homes on
    u8 _pad336[0x2];
    s32 lifetime;              // 150 frames, 300 on difficulty 3
    Vec spawn_position;        // copied with prev_position and body_center from the spawn point
    Vec velocity;              // normalised and scaled by speed each frame, added to body_center
    f32 speed;
    TParticleCtrl *effects[2]; // create_particle_emitter per TObjDFJisin__particle_emitter_id_table entry
    s32 damage;                // the shared table's attack power, sent with the hit
    f32 homing_rate;           // 0..1 from the shared table, sets how hard it turns (steer_homing_direction)
    s32 state;                 // 0 levels out, 1 steers, 2 waits for check_attack_trigger
    Vec target_position;       // the target's body_center, refreshed each frame
    f32 lock_distance;         // steering locks on once target_distance is inside it
    f32 target_distance;
};

LAYOUT_ASSERT(TObjDFHorming_velocity_offset, offsetof(TObjDFHorming, velocity) == 0x348);
LAYOUT_ASSERT(TObjDFHorming_effects_offset, offsetof(TObjDFHorming, effects) == 0x358);
LAYOUT_ASSERT(TObjDFHorming_size, sizeof(TObjDFHorming) == 0x380);

struct TBoss4DarkFalz;
// Copies one 0x40-byte enemy set entry (see TBoss4DarkFalzSetEntry) field by field. Name inferred
// from that body; every boss spawner that clones a set entry template calls it.
extern "C" void copy_set_entry(void *dst, void *src);

#endif
