#ifndef PSO_NPC_TOBJNPCENEMY_H
#define PSO_NPC_TOBJNPCENEMY_H

#include "types.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/npc/TObjNpcBase.h"

// One slot of TObjNpcEnemy__entry_table (0x24 B), filled by the spawners
// (TObjEneSlime::spawn_child, TLobby::spawn_npc_enemy, TMotorcycle::add_entry,
// NpcModelRegistry::register_animated_ginja) and read by TObjNpcEnemy::set_npc_data.
// Field names are inferred from where set_npc_data copies them.
struct TObjNpcEnemyEntry {
    s16 id;            // 0 marks a free slot; slots are sorted by id
    u16 kind;          // 0 slime, 1 lobby, 2 motorcycle, 3 stelth, 4 empty
    f32 y_offset;      // render height above the object (translate_matrix y)
    saddr model;
    NJS_TEXLIST *texlist;
    f32 radius;        // copied to the first collision body radius
    NpcAnimationBinding animation;

    void reset();
};

LAYOUT_ASSERT(NpcEnemyEntrySize, sizeof(TObjNpcEnemyEntry) == 0x24);
LAYOUT_ASSERT(NpcEnemyEntryAnimationOffset, offsetof(TObjNpcEnemyEntry, animation) == 0x14);

struct TObjNpcEnemy : public TObjNpcBase {
    TObjNpcEnemy(TObject *parent, void *set_data);
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
    static void set_global_count(s32 global_count);
};

LAYOUT_ASSERT(TObjNpcEnemy_size, sizeof(TObjNpcEnemy) == 0x3BC);

extern TObjNpcEnemyEntry TObjNpcEnemy__entry_table[16];

#endif
