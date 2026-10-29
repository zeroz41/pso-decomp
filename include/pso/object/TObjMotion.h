#ifndef PSO_OBJECT_TOBJMOTION_H
#define PSO_OBJECT_TOBJMOTION_H
#include "pso/TObject.h"
#include "pso/object/CursorAction.h"
#include "pso/system/FlagWord.h"
#include <stddef.h>
#include <dolphin/mtx/GeoTypes.h>
#include "pso/system/NinjaTypes.h"
struct BmlMotionEntry;
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
    void obj_clearFlags30(u32);
    s16 get_room();
    void set_room(s16 room);
    // Gives it count + 1 consecutive ids from the pool its actorFlags type
    // bits pick, unless it already has one; returns its id.
    u16 get_or_assign_entity_id(s32 count);
    s32 mask_object_set_row_flags(s32);
    s32 set_event_source_flag(s32);
    void set_entity_id(u16 id);
    int set_position_from(void *pos);
    s32 get_texlist();
    s32 is_alive();
    u16 entity_id;  // the object table id, 0xFFFF while unregistered
    s16 visibility; // update_object_view_visibility: 0 culled, 1 visible, 2 near
    s32 m_20;
    s32 texlist;  // its texture list, made current before it draws
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
// The entity id pools (TObjBase's TU): ids below 0x1000 are players and
// the like, 0x1000-0x3FFF enemies, 0x4000 and up objects.
extern "C" {
u16 fn_801A210C(s32 n);
u16 TLobby__sub_801A20C8(s32 arg);
void TLobby__sub_801A2550(void);
void TLobby__sub_801A2554(void);
}
void advance_enemy_id_counter(s32 arg0);
void advance_object_id_counter(s32 arg0);

// The derived destructors still written out by hand call the base ones by
// their symbols.
extern "C" void *__dt__8TObjBaseFv(void *, s16);
extern "C" void *__dt__14TObjCollidableFv(void *, s16);

// One collision body of an actor (TObjCollidable::bodies points at the actor's
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

class TObjCollidable : public TObjBase {
public:
    TObjCollidable(TObject *parent);
    virtual ~TObjCollidable();
    virtual void reset_motion_fields();
    void*find_actor_body_contact(u8*, f32);
    void set_indexed_flags(s32, s32);
    void clear_player_status_flag(s32, u32);
    s32 obj_testFlags30(u32);
    s32 access_object_saved_state(void *, s16);
    void sub_80156A68();
    void*set_collision_body(void*);
    void clear_collision_bodies();
    u32 check_actor_body_contact(void *, f32);
    void mark_enemy_body_contacts();
    void update_enemy_collision_flags();
    void check_object_collisions();
    void refresh_collision_body_centers();
    // Gives it an entity id if it has none and enters it in the id-sorted
    // entity table (unregister_object_by_id takes it out).
    void register_object_by_id();
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
// The actor and collision body a weapon's hit reports.
struct ActorBodyHit {
    TObjCollidable *target;
    s32 body;  // index into target->bodies
};

// One entry of TObjMotion::action_table: what an action plays and how.
struct TObjMotionAction {
    s16 mode;    // the TObjMotion::play_mode it plays in
    s16 next;    // the action MOTION_MODE_CHAIN goes on to
    s32 motion;  // index into motion_list
    f32 speed;
    u32 flags;   // ACTION_*
};

// TObjMotion::motion_flags.
enum {
    MOTION_NO_BLEND = 0x1,       // switch actions without blending
    MOTION_STARTED_BLEND = 0x2,  // a blend started this frame
    MOTION_BLENDING = 0x4,       // blend.motion[0] into blend.motion[1]
    MOTION_BLEND_DONE = 0x8,     // a blend finished this frame
    MOTION_HELD = 0x10,          // MOTION_MODE_ONCE reached its last frame
    MOTION_ENDED = 0x20,         // ... this frame
    MOTION_PAUSED = 0x40,
    MOTION_KEEP_FRAME = 0x80,    // the next action starts at blend.frame[0]
    MOTION_OVERRIDE_SPEED = 0x100,        // once: play at override_speed
    MOTION_OVERRIDE_BLEND_SPEED = 0x200,  // once: blend at override_blend_speed
    MOTION_DRAW_UNBLENDED = 0x400,
    MOTION_CHAINED = 0x800       // an action chained to its next this frame
};

// TObjMotionAction::flags.
enum {
    ACTION_INTERPOLATE = 0x20000000,  // sets the motion's interpolation bit
    ACTION_NO_BLEND_OUT = 0x40000000,
    ACTION_NO_BLEND_IN = 0x80000000
};

// TObjMotion::play_mode.
enum {
    MOTION_MODE_LOOP = 1,
    MOTION_MODE_CHAIN = 2,  // at the end, go on to the action's next
    MOTION_MODE_ONCE = 3,   // stop on the last frame
    MOTION_MODE_BLEND = 4,
    MOTION_MODE_STOPPED = 5
};

// An actor that plays motions on its model: actions from action_table pick
// a motion from motion_list and a play mode, and changing action blends
// from the old motion into the new one.
class TObjMotion : public TObjCollidable {
public:
    TObjMotion(TObject *parent);
    virtual ~TObjMotion();
    void draw();
    virtual void reset_motion_fields();
    void set_animation(s16 action);
    void set_field_d8(s32);
    void set_field_dc(s32);
    void set_field_b8(s16);
    TObjMotionAction *get_anim_entry(int action);
    int test_motion_flags(s32 flags);
    void clear_motion_flags(s32 flags);
    // The motion an action plays.
    NJS_MOTION *get_action_motion(s16 action);
    f32 get_action_frame_count(s16 action);
    // Makes the action's motion current.
    void set_action_motion(s32 action);
    s32 get_item_ptr(s32);
    void set_motion_interpolation_flag();
    // Sets both tables and starts the action.
    void init_motion(TObjMotionAction *actions, BmlMotionEntry *motions, s16 action);
    // Switches to the action, blending from the current one unless either
    // side or MOTION_NO_BLEND forbids it.
    void change_action(s16 action);
    // Steps the frame and the play mode; every actor calls it each update.
    void update_motion();
    s32 is_anim_finished();
    // The current action has reached its last frame (MOTION_MODE_ONCE).
    int is_motion_held();
    // True on the frame the motion passes `frame` (not while blending).
    int is_passing_frame(f32 frame);
    f32 get_frame();
    // frame, or 0 while blending.
    f32 get_motion_frame();
    // How far the root node moves forward between this frame and the next,
    // split along the actor's facing into *dx and *dz.
    f32 get_root_motion_step(f32 *dx, f32 *dz);
    // Walk the model through a motion without drawing, storing every
    // node's matrix (into anim_model_matrix_array for the current motion).
    s32 calc_joint_matrices(f32 frame);
    s32 calc_joint_matrices(NJS_MOTION *motion, f32 frame, s32 matrices);
    // Draw the model in its current motion (blended if blending).
    void draw_motion_model();
    void draw_ginja_motion_model();
    // ... storing every node's matrix into joint_matrices as it goes.
    void draw_saving_joints();
    void draw_saving_joints_checked();
    u32 extra;  // left to the subclass (a bomb's thrower, ...)
    u32 motion_flags;      // MOTION_*
    u32 action_flags;      // the current action's TObjMotionAction::flags
    s16 requested_action;  // update_motion changes to it when it differs
    s16 current_action;
    s16 previous_action;   // the action a blend comes from
    u8 pad_BE[0x2];
    f32 frame;
    f32 frame_count;
    f32 play_speed;         // frames per update
    f32 blend_speed;        // blend weight per update
    f32 override_speed;     // see MOTION_OVERRIDE_SPEED
    f32 override_blend_speed;
    TObjMotionAction *action_table;
    BmlMotionEntry *motion_list;
    void *joint_matrices;   // where draw_saving_joints stores node matrices
    NJS_MOTION_LINK blend;  // motion[0] blends into motion[1]
    s16 play_mode;          // MOTION_MODE_*
    s16 next_play_mode;     // the play mode after a blend
    NJS_MOTION *current_motion;
};

// Empty in the release build; TObjMotion::draw brackets its draw with them.
void setup_actor_draw_lighting();
void restore_actor_draw_lighting(const char *name);

// The model node table make_node_flag_table writes: one entry per node in
// tree order, a NULL object ending it.
struct NodeFlagEntry {
    NJS_OBJECT *object;
    u32 flags;  // NODE_*
};
enum {
    NODE_HAS_POS = 0x1,
    NODE_HAS_ANG = 0x2,
    NODE_HAS_SCL = 0x4,
    NODE_HAS_MODEL = 0x8,
    NODE_HAS_VERTICES = 0x10,
    NODE_HAS_POLYGONS = 0x20,
    NODE_HAS_CHILD = 0x40,
    NODE_HAS_SIBLING = 0x80
};
void write_node_flags(NJS_OBJECT *object);
void make_node_flag_table(NJS_OBJECT *object, NodeFlagEntry *table);
// The model node callback that stores each node's matrix at
// player_joint_matrix_write_ptr and steps it on.
void save_joint_matrix_callback();

extern NodeFlagEntry *node_flag_cursor;

// The name every TObjMotion constructor gives the object.
extern const char *TObjMotion__class_name;

typedef char TObjBaseSize[sizeof(TObjBase)==0x90?1:-1];
typedef char TObjCollidableSize[sizeof(TObjCollidable)==0xAC?1:-1];
typedef char CollisionBodySize[sizeof(CollisionBody)==0x2C?1:-1];
typedef char TObjMotionSize[sizeof(TObjMotion)==0xFC?1:-1];
typedef char WorldActorModelOffset[offsetof(TObjBase,model)==0x34?1:-1];
typedef char MotionActionsOffset[offsetof(TObjMotion,action_table)==0xD8?1:-1];
typedef char MotionListOffset[offsetof(TObjMotion,motion_list)==0xDC?1:-1];
typedef char JointMatricesOffset[offsetof(TObjMotion,joint_matrices)==0xE0?1:-1];
#endif
