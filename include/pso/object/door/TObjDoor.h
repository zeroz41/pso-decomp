#ifndef PSO_OBJECT_DOOR_TOBJDOOR_H
#define PSO_OBJECT_DOOR_TOBJDOOR_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"
struct TObjDoor : public TObjCollidable {
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
    s32 is_visible(f32 farg0, f32 farg1);
    void update_state();
    static void free_resources();
    static void load_resources();
    static void set_main_warp_id(int a0);
    static void *create(void *set_data);
};
LAYOUT_ASSERT(TObjDoor_size, sizeof(TObjDoor)==0xD4);
extern "C" s32 TObjDoor__data_805D5BC8;
#endif
