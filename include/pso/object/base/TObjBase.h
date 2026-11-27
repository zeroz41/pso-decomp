#ifndef PSO_OBJECT_BASE_TOBJBASE_H
#define PSO_OBJECT_BASE_TOBJBASE_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include "pso/system/NinjaTypes.h"
#include <dolphin/mtx/GeoTypes.h>

struct QuestObjectEntry;

struct NJS_OBJECT;
struct NJS_TEXLIST;
struct NJS_OBJECT;
struct ObjectSetData;

class TObjBase : public TObject {
public:
    TObjBase(TObject *parent);
    virtual ~TObjBase();
    virtual void apply_saved_state(QuestObjectEntry *state, s32 live);
    virtual void apply_object_set_data(ObjectSetData *set_data);
    virtual void reset_motion_fields();
    virtual Vec *get_center();
    virtual s32 update_object_view_visibility(f32, f32);
    virtual s32 classify_actor_view_detail(f32, f32, f32);
    virtual const char *get_name();
    // actorFlags |= flags.
    void set_actor_flags(s32 flags);
    // actorFlags &= ~flags.
    void clear_actor_flags(u32 flags);
    s16 get_room();
    void set_room(s16 room);
    // Gives it count + 1 consecutive ids from the pool its actorFlags type
    // bits pick, unless it already has one; returns its id.
    u16 get_or_assign_entity_id(s32 count);
    s32 mask_object_set_row_flags(s32 mask);
    s32 set_event_source_flag(s32);
    void set_entity_id(u16 id);
    u16 get_entity_id();
    Vec *set_position_from(const Vec *pos);
    void save_previous_position();
    Angle3 *get_rotation();
    NJS_TEXLIST *get_texlist();
    s32 is_alive();
    s32 is_active();
    u16 entity_id;  // the object table id, 0xFFFF while unregistered
    s16 visibility; // update_object_view_visibility: 0 culled, 1 visible, 2 near
    s32 pad_20;
    NJS_TEXLIST *texlist;  // its texture list, made current before it draws
    // Copied from the object's set entry when it is spawned; see
    // link_matching_objects.
    s16 room;
    s16 set_group;  // the object's group, or an enemy's wave number
    s16 set_index;  // index of its set entry, -1 for none
    s16 alt_room;   // the room set_room keeps for the key and quest states
    u32 actorFlags;
    NJS_OBJECT *model;
    Vec position;
    Vec prev_position;  // where it stood before this frame's move
    Vec home_position;  // the set position it returns to
    Angle3 rotation;
    Vec scale;        // the set entry's params 1-3, a scale for most objects
    Vec center;         // the point the virtual center getter returns
    void *set_entry;    // its row of the floor's object or enemy set
    s32 set_params[3];  // the set entry's params 4-6
};

// The entity id pools: ids below 0x1000 are players and the like,
// 0x1000-0x3FFF enemies, 0x4000 and up objects. A floor's set files take the
// first ids of the enemy and object pools (advance_*_id_counter); ids handed
// out later wrap around to just after them.
u16 alloc_player_ids(s32 count);
u16 alloc_enemy_ids(s32 count);
u16 alloc_object_ids(s32 count);
void advance_enemy_id_counter(s32 count);
void advance_object_id_counter(s32 count);
// Restarts the enemy and object pools when an area is reloaded.
void reset_enemy_and_object_ids();
// The scene setup/teardown pair for the pools.
void reset_id_counters();
void free_id_counters();

extern u16 next_player_id;
extern u16 next_enemy_id;
extern u16 next_object_id;
extern u16 first_free_object_id;
extern u16 first_free_enemy_id;

// A camera-space probe point and where it lands on screen.
struct ViewProbe {
    f32 screen[2];
    Vec point;
};

#endif
