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
    u32 m_90;
    u32 m_94;
    u8 _pad98[0x4];
    u32 m_9c;
    u32 m_a0;
    u32 m_a4;
    u8 _padA8[0x14];
    NJS_ARGB scene_color; // 0xBC: the scene light's colour when the light was set up
    void* m_cc;
    u8 _padD0[0x8];
    Vec scene_direction; // 0xD8: the scene light's view direction
    virtual void render();
    virtual void run_task();
    static PointLight *alloc_light_slot();
    void sub_8013379C(TObjLightSceneLightState *state);
    void init_directional_light();
    void sub_801337F8();
    static void free_shared_data();
    static void apply_distant_light();
    static void find_light_params(f32 *dir, f32 *color, u32 id);
    static void init_light_tables();
    static void assert_light_id(s32 idx);
    // What register_actor_light hands to an actor in range: the scene light blended toward this one.
    Vec actor_direction; // 0xE4
    NJS_ARGB actor_color; // 0xF0
};

LAYOUT_ASSERT(TObjLight_size, sizeof(TObjLight) == 0x100);

extern "C" {
void *__dt__9TObjLightFv(void *arg0, s16 arg1);
}

#endif
