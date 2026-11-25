#ifndef PSO_OBJECT_DOOR_TODOORJUNGLEMAIN_H
#define PSO_OBJECT_DOOR_TODOORJUNGLEMAIN_H

#include "types.h"
#include "pso/object/door/TODoorBase.h"

struct TObjMapCsn;

struct TODoorJungleMain : public TODoorBase {
    virtual ~TODoorJungleMain();
    virtual s32 update_object_view_visibility(f32, f32);
    virtual void vfunc_6(s16 *, s32);
    virtual void update_door_switch_state();
    s32 switch_count;      // how many of the three switches are set
    s32 sparkle_counter;   // frames of the open animation, counted for the particle burst
    TObjMapCsn *m_dc;
    static void free_static_resources();
    static void load_resources();
    virtual void render();
    virtual void run_task();
    static void *create(void *set_data);
};

LAYOUT_ASSERT(TODoorJungleMain_size, sizeof(TODoorJungleMain) == 0xE0);
extern "C" void TLobby__sub_8029B2A4(void *p);
#endif
