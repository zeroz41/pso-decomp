#ifndef PSO_BOSS_DARKFALZ_TBOSS4ZAKO_H
#define PSO_BOSS_DARKFALZ_TBOSS4ZAKO_H
#include "types.h"
#include <stddef.h>
#include "pso/enemy/TObjEnemy.h"

struct BmlResource;
struct CollisionBody;
class TParticleCtrl;
struct TBoss4DarkFalz;

// What create hands the constructor: the Dark Falz that spawned the minion, then the
// enemy set entry (from set_index on) passed to apply_set_data. The spawners fill it
// from a template with copy_set_entry and number it with
// TBoss4DarkFalz::alloc_child_ids; the entry has TBoss6MineSetData's layout.
struct TBoss4ZakoSetData {
    TBoss4DarkFalz *owner;
    s16 set_index;
    u8 pad_06[0x4];
    s16 entity_id;
    s16 unk_0C;
    u8 pad_0E[0x6];
    Vec position;
    u8 pad_20[0x28];
};

// Dark Falz's first-form minion. TBoss4Uro and TBoss4Bishi derive from it and keep
// its fields; field names inferred from their uses in TBoss4Zako.cpp.
struct TBoss4Zako : public TObjEnemy {
    TBoss4Zako(TObject *parent, TBoss4ZakoSetData *set_data);
    virtual ~TBoss4Zako();
    virtual void run_task();
    virtual void render();
    virtual void run_death_reaction();
    static TBoss4Zako *create(TBoss4ZakoSetData *set_data);
    s32 is_hunting();
    s32 is_not_sinking();
    void apply_contact_damage();
    void set_state3();
    void update_rise_state();
    void update_move_to_target_state();
    void update_surround_player_state();
    void update_sink_state();
    static s32 queue_entry(void *v, s32 a, s32 b);

    s32 state;
    TBoss4DarkFalz *owner;
    s32 charge_timer;   // TBoss4Bishi's frames left before it sinks
    BmlResource *archive;
    CollisionBody *collision;
    s32 target_id;      // client id of the player it follows, 0xFFFF for none
    Vec velocity;
    f32 speed;
    f32 max_speed;      // TLobby::dispatch_shared_handler_a(0x35)
    f32 max_speed_alt;  // TLobby::dispatch_shared_handler_a(0x39)
    s32 state_timer;
    s32 surfaced;       // collision on and drawn on the minimap while set
    s32 surface_timer;
    f32 spin_ratio;
    TParticleCtrl *emitter;
    s32 frame_count;
    s32 bob_angle;
    s32 bob_angle_step;
};
LAYOUT_ASSERT(TBoss4ZakoSetData_position, offsetof(TBoss4ZakoSetData, position) == 0x14);
LAYOUT_ASSERT(TBoss4ZakoSetData_size, sizeof(TBoss4ZakoSetData) == 0x48);
LAYOUT_ASSERT(TBoss4Zako_state, offsetof(TBoss4Zako, state) == 0x374);
LAYOUT_ASSERT(TBoss4Zako_velocity, offsetof(TBoss4Zako, velocity) == 0x38C);
LAYOUT_ASSERT(TBoss4Zako_emitter, offsetof(TBoss4Zako, emitter) == 0x3B4);
LAYOUT_ASSERT(TBoss4Zako_size, sizeof(TBoss4Zako) == 0x3C4);
#endif
