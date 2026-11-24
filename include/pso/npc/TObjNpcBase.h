#ifndef PSO_NPC_TOBJNPCBASE_H
#define PSO_NPC_TOBJNPCBASE_H

#include "types.h"
#include "pso/enemy/TObjEnemy.h"

class TQuestThread;

// What TObjEnemy::movementParameters points at for the town NPCs.
struct NpcMovementParameters {
    f32 search_range;  // find_nearest_visible_player range
    f32 speed;       // walking speed (enemy_set_heading_velocity)
    s32 turn_speed;  // largest turn per frame (approach_angle_limited)
    u32 pad_0C[4];
};

struct TObjNpcBase : public TObjEnemy {
    TObjNpcBase(TObject *parent);
    virtual ~TObjNpcBase();
    virtual void run_task();
    virtual void render();
    virtual void interact(u16 client);
    virtual void update_idle();
    virtual void update_standing();
    virtual void update_wandering();
    virtual void update_conversation();
    virtual void apply_set_params(s32, s32);
    virtual void request_action(s32 action);
    virtual void debug_draw_talk();
    virtual void play_voice();
    virtual void vfunc_91();
    virtual void vfunc_92();
    virtual void draw_debug_info();
    void set_message_label(s32 label);
    void set_object_number(s32 number);
    virtual void run_move_action();
    virtual void run_idle_action();
    virtual s32 is_target_in_attack_range() { return 0; }
    virtual void refresh_target();
    u8 pad_374[0x10];
    s32 home_rotation_y;        // rotation_y on setup; update_standing turns back to it
    s32 m_388;
    s32 uses_area_flags;        // disp flags >= 1000: read from the area quest's registers
    s32 visible;                // the disp on/off quest registers allow drawing
    s32 draws_chunk_model;      // lobby NPCs draw `model` as a chunk object
    f32 view_distance;
    f32 view_radius;
    s32 disp_on_flag;           // quest register that shows the NPC (0: always shown)
    s32 disp_off_flag;          // quest register that hides the NPC
    s32 message_label;          // quest label run on talk; <= 0 cannot be talked to
    s32 object_number;          // conversation camera / quest thread selector
    TQuestThread *quest_thread; // the conversation's running quest thread
    TObject *conversation_camera;
    static const char *class_name;
    static void load_resources();
    static void free_static();
    void setup_common();
};

extern player_stats npc_default_battle_stats;
extern NpcMovementParameters npc_movement_parameters;
extern CollisionBody npc_base_collision_body_desc;
// PlyMotionNpcTown.cpt, the walk/talk motions the town NPCs share.
extern uaddr npc_town_motion_data;
// The shared resource of the plain town NPCs (TObjNpcFemale, TObjNpcMale, TObjNpcFomarl); nothing assigns it.
extern u32 town_npc_shared_resource;

LAYOUT_ASSERT(NpcBaseHomeRotation, offsetof(TObjNpcBase, home_rotation_y) == 0x384);
LAYOUT_ASSERT(NpcBaseVisible, offsetof(TObjNpcBase, visible) == 0x390);
LAYOUT_ASSERT(NpcBaseViewDistance, offsetof(TObjNpcBase, view_distance) == 0x398);
LAYOUT_ASSERT(NpcBaseMessageLabel, offsetof(TObjNpcBase, message_label) == 0x3A8);
LAYOUT_ASSERT(NpcBaseConversationCamera, offsetof(TObjNpcBase, conversation_camera) == 0x3B4);
LAYOUT_ASSERT(NpcBaseSize, sizeof(TObjNpcBase) == 0x3B8);

#endif
