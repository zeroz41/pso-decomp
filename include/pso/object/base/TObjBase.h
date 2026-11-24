#ifndef PSO_OBJECT_BASE_TOBJBASE_H
#define PSO_OBJECT_BASE_TOBJBASE_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx/GeoTypes.h>

struct CameraAngles;
struct NJS_TEXLIST;

class TObjBase : public TObject {
public:
    TObjBase(TObject *parent);
    virtual ~TObjBase();
    virtual void vfunc_6(s16 *, s32);
    virtual void apply_object_set_data(void *);
    virtual void reset_motion_fields();
    virtual void *get_center();
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
    s32 mask_object_set_row_flags(s32);
    s32 set_event_source_flag(s32);
    void set_entity_id(u16 id);
    u16 get_entity_id();
    int set_position_from(void *pos);
    void save_previous_position();
    CameraAngles *get_rotation();
    NJS_TEXLIST *get_texlist();
    s32 is_alive();
    s32 is_active();
    u16 entity_id;  // the object table id, 0xFFFF while unregistered
    s16 visibility; // update_object_view_visibility: 0 culled, 1 visible, 2 near
    s32 m_20;
    NJS_TEXLIST *texlist;  // its texture list, made current before it draws
    // Copied from the object's set entry when it is spawned; see
    // TLobby::link_matching_objects.
    s16 room;
    s16 set_group;  // the object's group, or an enemy's wave number
    s16 set_index;  // index of its set entry, -1 for none
    s16 alt_room;   // the room set_room keeps for the key and quest states
    u32 actorFlags;
    void* model;
    Vec position;
    Vec prev_position;  // where it stood before this frame's move
    Vec home_position;  // the set position it returns to
    s32 rotation_x;
    s32 rotation_y;
    s32 rotation_z;
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

#endif
