#ifndef PSO_NPC_TOBJNPCENEMY_H
#define PSO_NPC_TOBJNPCENEMY_H

#include "types.h"
#include "pso/npc/NpcAnimationBinding.h"
#include "pso/npc/TObjNpcBase.h"

struct NJS_OBJECT;
struct NJS_TEXLIST;

// One slot of TObjNpcEnemy::entry_table (0x24 B), filled by the register functions
// below and read by TObjNpcEnemy::set_npc_data, which copies its fields into the NPC.
struct TObjNpcEnemyEntry {
    s16 id;            // 0 marks a free slot; slots are sorted by id
    u16 kind;          // 0 chunk model, 1 animated chunk, 2 Ginja model, 3 animated Ginja, 4 empty
    f32 y_offset;      // render height above the object (translate_matrix y)
    NJS_OBJECT *model;
    NJS_TEXLIST *texlist;
    f32 radius;        // copied to the first collision body radius
    NpcAnimationBinding animation;

    void reset();
};

LAYOUT_ASSERT(NpcEnemyEntrySize, sizeof(TObjNpcEnemyEntry) == 0x24);
LAYOUT_ASSERT(NpcEnemyEntryModelOffset, offsetof(TObjNpcEnemyEntry, model) == 0x8);
LAYOUT_ASSERT(NpcEnemyEntryTextureOffset, offsetof(TObjNpcEnemyEntry, texlist) == 0xC);
LAYOUT_ASSERT(NpcEnemyEntryAnimationOffset, offsetof(TObjNpcEnemyEntry, animation) == 0x14);

struct TObjNpcEnemy : public TObjNpcBase {
    TObjNpcEnemy(TObject *parent, void *set_data);
    virtual ~TObjNpcEnemy();
    virtual void draw_debug_info();
    virtual void request_action(s32);
    // The jungle grass (entry 0x3F) draws without model_render_flags bit 0.
    s32 is_not_jungle_grass();
    TObjNpcEnemyEntry *entry; // 0x3B8: the slot set_npc_data shows
    static TObjNpcEnemyEntry *get_entry_by_index(s16 index);
    static TObjNpcEnemyEntry *insert_slot_by_id(s16 id);
    static void register_chunk(s16 id, NJS_OBJECT *model, NJS_TEXLIST *texlist, f32 radius, f32 y_offset);
    static void register_animated_chunk(s16 id, NJS_OBJECT *model, NJS_TEXLIST *texlist,
                                        const NpcAnimationBinding *animation, f32 radius, f32 y_offset);
    static void register_ginja(s16 id, NJS_OBJECT *model, NJS_TEXLIST *texlist, f32 radius, f32 y_offset);
    static void register_animated_ginja(s16 id, NJS_OBJECT *model, NJS_TEXLIST *texlist,
                                        const NpcAnimationBinding *animation, f32 radius, f32 y_offset);
    static void reset_all_anim_fields();
    void set_npc_data(TObjNpcEnemyEntry *data);
    void update_state();
    virtual void render();
    static void set_global_count(s32 global_count);
    static void *create(void *set_data);

    static const char *name;
    static CollisionBody collision_body_parts;
    static TObjNpcEnemyEntry entry_table[16];
};

LAYOUT_ASSERT(TObjNpcEnemy_size, sizeof(TObjNpcEnemy) == 0x3BC);

#endif
