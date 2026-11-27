#ifndef PSO_OBJECT_DOOR_TODOORJUNGLEMAIN_H
#define PSO_OBJECT_DOOR_TODOORJUNGLEMAIN_H

#include "types.h"
#include "pso/object/door/TODoorBase.h"

struct TObjMapCsn;
struct BmlResource;

struct TODoorJungleMain : public TODoorBase {
    TODoorJungleMain(TObject *parent, ObjectSetData *set_data);
    virtual ~TODoorJungleMain();
    virtual s32 update_object_view_visibility(f32, f32);
    virtual void apply_saved_state(s16 *, s32);
    virtual void update_door_switch_state();
    s32 switch_count;     // how many of the three jungle switches are set
    s32 smoke_timer;      // frames the opening door has smoked; a puff every 30
    TObjMapCsn *map_csn;  // the closed door's collision, dropped as it opens
    static void free_static_resources();
    static void load_resources();
    virtual void render();
    virtual void run_task();
    static void *create(ObjectSetData *set_data);
    static const char *class_name;
    static BmlResource *bml_resource;
};

LAYOUT_ASSERT(TODoorJungleMain_size, sizeof(TODoorJungleMain) == 0xE0);
#endif
