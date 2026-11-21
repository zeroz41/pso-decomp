#ifndef PSO_OBJECT_MINE_TODRAGONFLYMACHINE01_H
#define PSO_OBJECT_MINE_TODRAGONFLYMACHINE01_H

#include "types.h"

struct NJS_OBJECT;
#include "pso/object/TODragonfly.h"

struct BmlResource;

// The mechanical dragonfly: a TODragonfly whose head swings from side to
// side while it idles or rests.
struct NJS_OBJECT;

struct TODragonflyMachine01 : public TODragonfly {
    TODragonflyMachine01(void *set_data);
    virtual ~TODragonflyMachine01();
    virtual void render();
    virtual void run_task();
    void update_yaw_animation();
    // The model-node callback render installs: turns node 6 (the head).
    static void rotate_animated_node(NJS_OBJECT *);
    static void *create(void *set_data);
    static void unload_static_data();
    static void load_resources();

    static const char *class_name;
    static BmlResource *model_resource;
    static s32 node_index;  // the node rotate_animated_node is called for
    static s32 node_yaw;    // the head yaw render draws with

    s16 yaw_animation_state;
    s16 yaw_animation_cycles;
    int animation_yaw;
};

LAYOUT_ASSERT(TODragonflyMachine01_size, sizeof(TODragonflyMachine01) == 0x108);

#endif
