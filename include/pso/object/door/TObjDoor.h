#ifndef PSO_OBJECT_DOOR_TOBJDOOR_H
#define PSO_OBJECT_DOOR_TOBJDOOR_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct CollisionBody;
struct DoorModelSet;
struct DoorMotionHeader;
struct NJS_TEXLIST;
struct NJS_ARGB;

struct TObjDoor : public TObjCollidable {
    TObjDoor(TObject *parent, void *set_data);
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
    static void *create(void *set_data);

    static CollisionBody collision_desc;
    static NJS_ARGB label_color_table[10];
    static const char *name;
    static DoorMotionHeader *motion_table[2];
    static DoorModelSet model_resource_ptrs;
    static NJS_TEXLIST *resource_param;
};
LAYOUT_ASSERT(TObjDoor_size, sizeof(TObjDoor)==0xD4);
extern "C" s32 TObjDoor__data_805D5BC8;
#endif
