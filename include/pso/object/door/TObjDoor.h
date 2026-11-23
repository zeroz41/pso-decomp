#ifndef PSO_OBJECT_DOOR_TOBJDOOR_H
#define PSO_OBJECT_DOOR_TOBJDOOR_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"
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
    void fn_8018E40C();
    void draw_model();
    // run_task's update per state.
    void update_locked_pulse();
    void update_anim();
    void draw_closed_glow();
    void fn_8018E8BC();
    void update_opening_glow();
    void fn_8018E890();
    void update_state();
    static void free_resources();
    static void load_resources();
    static void set_main_warp_id(int a0);
    static void *create(void *set_data);
};
LAYOUT_ASSERT(TObjDoor_size, sizeof(TObjDoor)==0xD4);
extern "C" s32 TObjDoor__data_805D5BC8;
#endif
