#ifndef PSO_OBJECT_AMBIENT_TOBJLIGHT_H
#define PSO_OBJECT_AMBIENT_TOBJLIGHT_H

#include "types.h"
#include "pso/system/NinjaTypes.h"
#include "pso/object/base/TObjMotion.h"

struct TObjLightSceneLightState;
struct PointLight;

struct TObjLight : public TObjBase {
    TObjLight(TObject *parent, u8 *set_data);
    virtual ~TObjLight();
    static void *create(void *set_data);
    void *init_from_source(void *, int, int);
    u32 light_room;  // the set entry's room
    s32 oscillation;   // 0x94: the swing of a pulsing light, in degrees
    f32 radius;        // 0x98: how far from the light a player picks up its colour
    s32 phase;         // 0x9C: the pulse angle
    u32 flags;         // 0xA0: bit 0 colour channel 0 offset by 10000, bit 1 channel 1
    u32 increment;     // 0xA4: how far the angle or phase moves per frame
    f32 strength;      // 0xA8: how fast the blend towards this light rises with closeness
    u8 _padAC[0x4];
    Vec color;         // 0xB0: this light's colour
    NJS_ARGB scene_color; // 0xBC: the scene light's colour when the light was set up
    Vec direction;     // 0xCC: this light's direction
    Vec scene_direction; // 0xD8: the scene light's view direction
    virtual void render();
    virtual void run_task();
    static PointLight *alloc_light_slot();
    void sub_8013379C(TObjLightSceneLightState *state);
    void init_directional_light();
    void debug_scene_light_hook();
    static void free_shared_data();
    static void apply_distant_light();
    static void find_light_params(f32 *dir, f32 *color, u32 id);
    static void init_light_tables();
    // What register_actor_light hands to an actor in range: the scene light blended toward this one.
    Vec actor_direction; // 0xE4
    NJS_ARGB actor_color; // 0xF0
};

LAYOUT_ASSERT(TObjLight_size, sizeof(TObjLight) == 0x100);

#endif
