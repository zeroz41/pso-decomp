#ifndef PSO_OBJECT_DOOR_TOBJDOOR_H
#define PSO_OBJECT_DOOR_TOBJDOOR_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct CollisionBody;
struct NJS_MOTION;
struct NJS_OBJECT;
struct NJS_TEXLIST;
struct NJS_ARGB;

// The door BML's models, named after their files.
struct DoorModelSet {
    NJS_OBJECT *body;          // taiki_fe_obj_doa_oya: the door, opened by motion 0
    NJS_OBJECT *laser;         // taiki_fe_obj_doa_laz_oya: animated by motion 1
    NJS_OBJECT *sign;          // fe_obj_doa_kanban: drawn in the door's label colour
    NJS_OBJECT *signal_front;  // fs_obj_doa_shingo_omote
    NJS_OBJECT *signal_back;   // fs_obj_doa_shingo_ura
};

struct TObjDoor : public TObjCollidable {
    TObjDoor(TObject *parent, ObjectSetData *set_data);
    virtual ~TObjDoor();
    virtual void render();
    virtual void run_task();
    s32 state;
    s32 behavior;
    f32 frame;
    f32 accentFrame;
    s8 cameraMode;
    u8 padBD[3];
    s32 cameraTicks;
    f32 glow;
    s32 phase;
    s32 switchId;
    s32 label;
    static void reset_instance();
    s32 is_visible(f32 far_dist, f32 near_dist);
    // render's draw per state (0 locked .. 5 open).
    void draw_locked();
    void update_timer();
    void draw_closed();
    void draw_closing();
    void draw_opening();
    void draw_model();
    // run_task's update per state.
    void update_locked_pulse();
    void update_anim();
    void draw_closed_glow();
    void update_closing();
    void update_opening_glow();
    void update_open();
    void update_state();
    static void free_resources();
    static void load_resources();
    static void set_main_warp_id(int main_warp_id);
    static void *create(ObjectSetData *set_data);

    static CollisionBody collision_desc;
    static NJS_ARGB label_color_table[10];
    static const char *name;
    static NJS_MOTION *motion_table[2];
    static DoorModelSet model_resource_ptrs;
    static NJS_TEXLIST *resource_param;
};
LAYOUT_ASSERT(TObjDoor_size, sizeof(TObjDoor)==0xD4);
// Set by the quest opcode masterkey_on; doors then run in state 0.
extern s32 door_masterkey_on;
// 1 when no player on this floor is within radius of the door (expect_clear 1), or when one is (expect_clear 0).
s32 check_player_door_proximity(TObjDoor *door, s32 expect_clear, f32 radius);
#endif
