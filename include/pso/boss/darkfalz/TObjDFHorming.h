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
    TParticleCtrl *effects[2]; // create_particle_emitter per particle_emitter_id_table entry
    s32 damage;                // the shared table's attack power, sent with the hit
    f32 homing_rate;           // 0..1 from the shared table, sets how hard it turns (steer_homing_direction)
    s32 state;                 // 0 levels out, 1 steers, 2 waits for check_attack_trigger
    Vec target_position;       // the target's body_center, refreshed each frame
    f32 lock_distance;         // steering locks on once target_distance is inside it
    f32 target_distance;
    static const char *name;
    static s32 particle_emitter_id_table[2];
};

LAYOUT_ASSERT(TObjDFHorming_velocity_offset, offsetof(TObjDFHorming, velocity) == 0x348);
LAYOUT_ASSERT(TObjDFHorming_effects_offset, offsetof(TObjDFHorming, effects) == 0x358);
LAYOUT_ASSERT(TObjDFHorming_size, sizeof(TObjDFHorming) == 0x380);

struct TBoss4DarkFalz;
// Copies one 0x40-byte enemy set entry (see TBoss4DarkFalzSetEntry) field by field. Name inferred
// from that body; every boss spawner that clones a set entry template calls it.
void copy_set_entry(void *dst, void *src);

// One arena zone of the fight (push_players_out_of_zone): players farther than radius from the center of
// the zone being entered who stand inside another zone land at landing, spread from it along their offset
// from that zone's center.
struct DarkFalzPushZone { Vec center; f32 radius; Vec landing; f32 spread; };

struct SetEntryWords3 { u32 w[3]; };
struct SetEntryWords5 { u32 w[5]; };
struct SetEntryCopy {
  s16 set_index;
  s16 kind;
  s16 unknown_04;
  u16 entity_id;
  s16 room;
  s16 wave;
  s16 unknown_0C;
  s16 unknown_0E;
  struct SetEntryWords3 position;
  struct SetEntryWords3 rotation;
  struct SetEntryWords5 params;
  s16 param_3C;
  s16 param_3E;
};

#endif
