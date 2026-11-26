#ifndef PSO_OBJECT_TOBIND_H
#define PSO_OBJECT_TOBIND_H

#include "types.h"
#include "pso/object/base/TObjMotion.h"

struct AnimationMotion;
struct NJS_TEXLIST;

struct BmlResource;

struct TOBind : public TObjCollidable {
    TOBind(void *set_data);
    virtual ~TOBind();
    void run_task_stub();
    void update_motion();
    u8 pad_AC[0x4];
    u32 triggered;
    u32 index;
    f32 motion_frame;
    f32 motion_end_frame;
    f32 motion_step;
    NJS_OBJECT *animated_model;
    NJS_TEXLIST *animated_textures;
    AnimationMotion *motion;
    virtual void run_task();
    virtual void render();
    static void *create(void *set_data);
    static void free_static_model();
    static void load_static_resource();
    f32 draw_distance;
    f32 visibility_radius;
    static const char *class_name;
    static BmlResource *static_model_resource;
};

LAYOUT_ASSERT(TOBind_motion_frame_offset, offsetof(TOBind, motion_frame) == 0xB8);
LAYOUT_ASSERT(TOBind_animated_model_offset, offsetof(TOBind, animated_model) == 0xC4);
LAYOUT_ASSERT(TOBind_motion_offset, offsetof(TOBind, motion) == 0xCC);
LAYOUT_ASSERT(TOBind_size, sizeof(TOBind) == 0xD8);
#endif
