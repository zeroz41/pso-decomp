#ifndef PSO_OBJECT_TOBJMOTION_H
#define PSO_OBJECT_TOBJMOTION_H
#include "pso/TObject.h"
#include "pso/object/CursorAction.h"
#include "pso/system/FlagWord.h"
#include <stddef.h>
#include <dolphin/mtx/GeoTypes.h>
class TUnk_804B9870 : public TObject {
public:
    TUnk_804B9870(TObject *parent);
    virtual ~TUnk_804B9870();
    virtual void vfunc_6(s16 *, s32);
    virtual void apply_object_set_data(void *);
    virtual void reset_motion_fields();
    virtual void*vfunc_9();
    virtual s32 update_object_view_visibility(f32, f32);
    virtual s16 classify_actor_view_detail(f32, f32, f32);
    virtual const char *get_name();
    void obj_clearFlags30(u32);
    s16 get_stat_by_key_state();
    s32 mask_object_set_row_flags(s32);
    s32 set_event_source_flag(s32);
    void set_entity_id(u16 id);
    int set_position_from(void *pos);
    u16 entity_id;  // the object table id, 0xFFFF while unregistered
    s16 visibility; // update_object_view_visibility: 0 culled, 1 visible, 2 near
    s32 m_20;
    s32 texture_id;
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
// The derived destructors still written out by hand call the base ones by
// their symbols.
extern "C" void *__dt__13TUnk_804B9870Fv(void *, s16);
extern "C" void *__dt__13TUnk_804AF8A0Fv(void *, s16);

// One collision body of an actor (TUnk_804AF8A0::bodies points at the actor's
// array of them); init_collision_body_parts copies a static table of these.
struct CollisionBody {
    Vec offset;      // from the actor's position, turned by its y rotation
    f32 radius;      // a sphere's radius, a box's half depth (z)
    f32 half_width;  // a box's half width (x)
    s32 shape;       // 0 sphere, 1 box
    u32 flags;
    Vec center;      // offset placed in the world by refresh_collision_body_centers
    f32 unk_28;
};
// *dst = *src, the copy CodeWarrior 1.3.2 generates (TBoss1DragonColli's TU).
extern "C" void copy_collision_body(CollisionBody *dst, const CollisionBody *src);

class TUnk_804AF8A0 : public TUnk_804B9870 {
public:
    TUnk_804AF8A0(TObject *parent);
    virtual ~TUnk_804AF8A0();
    virtual void reset_motion_fields();
    void*find_actor_body_contact(u8*, f32);
    void set_indexed_flags(s32, s32);
    void clear_player_status_flag(s32, u32);
    s32 obj_testFlags30(u32);
    s32 access_object_saved_state(void *, s16);
    void sub_80156A68();
    void*initialize_linked_object_reference(void*);
    void clear_obj_links();
    u32 check_actor_body_contact(void *, f32);
    void mark_enemy_body_contacts();
    void refresh_collision_body_centers();
    u16 unregister_object_by_id();
    void send_object_state_update(void *);
    // A player (client id, 0xFFFF for none) uses the action button on it.
    virtual void interact(s32 client);
    s32 set_flag8();
    s32 has_interactor();
    s32 get_cursor_action();
    void set_shadow_flag();
    void clear_shadow_flag();
    // The ground polygons project_actor_to_ground last found (csnVectorUnder's
    // cache), NULL to query without one.
    void *ground_cache;
    u16 interactor;  // client id of the player interacting, 0xFFFF for none
    u8 unk_96[0x2];
    CursorAction cursor_action;
    FlagWord *body_flags;  // one word per collision body
    FlagWord own_body_flags;  // body_flags of an actor with a single body
    CollisionBody *bodies;
    s32 body_count;
};
// One entry of TObjMotion::action_table.
struct TObjMotionAction {
    s16 mode;
    s16 next;
    s32 motion;
    f32 speed;
    u32 flags;
};

class TObjMotion : public TUnk_804AF8A0 {
public:
    virtual ~TObjMotion();
    void draw();
    virtual void reset_motion_fields();
    void set_animation(s16);
    void set_field_d8(s32);
    void set_field_dc(s32);
    void*get_anim_entry(int);
    u8 sub_80143960(s32);
    s32 get_anim_entry_value(s16);
    void update_animation_frame(s32);
    s32 get_item_ptr(s32);
    void sub_800E2DE4(s32);
    void set_motion_interpolation_flag();
    void set_field_b8(s16);
    u32 unknownAC;
    u32 animationFlags;
    u32 m_b4;
    s16 m_b8;
    short m_ba;
    u32 m_bc;
    f32 m_c0;
    union {
        u8 unk_C4[0x4];
        f32 anim_end_frame;
    };
    f32 m_c8;
    u8 unk_CC[0x4];
    f32 m_d0;
    u8 unk_D4[0x4];
    void* action_table;
    void* motion_list;
    void* motion_buffer;
    u8 unk_E4[0x3];
    u8 m_e7;
    u8 unk_E8[0x4];
    s32 m_ec;
    u8 unk_F0[0x4];
    void * m_f4;
    u32 unknownF8;
};
typedef char TUnk_804B9870Size[sizeof(TUnk_804B9870)==0x90?1:-1];
typedef char TUnk_804AF8A0Size[sizeof(TUnk_804AF8A0)==0xAC?1:-1];
typedef char CollisionBodySize[sizeof(CollisionBody)==0x2C?1:-1];
typedef char TObjMotionSize[sizeof(TObjMotion)==0xFC?1:-1];
typedef char WorldActorModelOffset[offsetof(TUnk_804B9870,model)==0x34?1:-1];
typedef char MotionActionsOffset[offsetof(TObjMotion,action_table)==0xD8?1:-1];
typedef char MotionListOffset[offsetof(TObjMotion,motion_list)==0xDC?1:-1];
typedef char MotionBufferOffset[offsetof(TObjMotion,motion_buffer)==0xE0?1:-1];
#endif
