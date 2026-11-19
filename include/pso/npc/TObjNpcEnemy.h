#ifndef PSO_NPC_TOBJNPCENEMY_H
#define PSO_NPC_TOBJNPCENEMY_H

#include "types.h"
#include "pso/npc/TObjNpcBase.h"

// One slot of TObjNpcEnemy__entry_table (0x24 B), filled by the spawners
// (TObjEneSlime::spawn_child, TLobby::spawn_npc_enemy, TMotorcycle::add_entry,
// TObjEneMe3Stelth::spawn_attack) and read by TObjNpcEnemy::set_npc_data.
// Field names are inferred from where set_npc_data copies them.
struct TObjNpcEnemyEntryMotion {
    s32 motion_entry;  // 0x14: BmlMotionEntry * handed to TObjMotion::init_motion
    s32 motion_action; // 0x18: TObjMotionAction * handed to TObjMotion::init_motion
    s16 action;        // 0x1C: requested_action outside mode 2
    s16 action_mode2;  // 0x1E: requested_action in mode 2
    s16 action_count;  // 0x20: bound of the debug motion test index
};

struct TObjNpcEnemyEntry {
    s16 id;            // 0 marks a free slot; slots are sorted by id
    u16 kind;          // 0 slime, 1 lobby, 2 motorcycle, 3 stelth, 4 empty
    f32 y_offset;      // render height above the object (translate_matrix y)
    s32 model;
    s32 texlist;
    f32 radius;        // copied to the first collision body radius
    TObjNpcEnemyEntryMotion motion;
};

void copy_position_data(void *dst, void *src);

struct TObjNpcEnemy : public TObjNpcBase {
    virtual ~TObjNpcEnemy();
    virtual void draw_debug_info();
    virtual void request_action(s32);
    s32 sub_802D7444();
    TObjNpcEnemyEntry *entry; // 0x3B8: slot set by set_npc_data (name inferred)
    static TObjNpcEnemyEntry *get_entry_by_index(s16 arg0);
    static TObjNpcEnemyEntry *insert_slot_by_id(s16 arg0);
    static void reset_all_anim_fields();
    void set_npc_data(void *arg1);
    void update_state();
    virtual void render();
    void reset_anim_fields();
    static void set_global_count(s32 arg0);
};

typedef char TObjNpcEnemy_size[sizeof(TObjNpcEnemy) == 0x3BC ? 1 : -1];

extern TObjNpcEnemyEntry TObjNpcEnemy__entry_table[16];

#endif
