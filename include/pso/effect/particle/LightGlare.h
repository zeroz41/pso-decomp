#ifndef PSO_EFFECT_PARTICLE_LIGHTGLARE_H
#define PSO_EFFECT_PARTICLE_LIGHTGLARE_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

// Map object 0x001E: the screen glare of a light source at its position (particle definition 31), larger the
// more the camera faces it and dimmed while the map hides it. scale.x picks the tint (below 0 grey, 10 and up
// dark orange, orange otherwise).
class TLightGlare : public TObjBase {
public:
    TLightGlare(void *set_data, TObject *parent);
    virtual ~TLightGlare();
    virtual void render();
    virtual void run_task();
    // The object factory entry; none in split screen.
    static void *create(void *set_data);
    f32 glare_size;          // 0x90, 25 to 55: half the sprite size in definition units
    f32 facing;              // 0x94, dot of the camera's forward axis and the direction to the glare
    s32 occluded;            // 0x98, the map lies between the camera and the glare
    f32 screen_position[2];  // 0x9C
    f32 alpha;               // 0xA4, eases towards 225 (50 while occluded)
    u8 pad_A8[4];
};
LAYOUT_ASSERT(TLightGlare_size, sizeof(TLightGlare) == 0xAC);

// Map object 0x01A8: turns the light glares on (scale.x above 0) or off when the local player comes within 20
// units; drawn as a sphere in demo mode.
class TLightGlareSwitch : public TObjBase {
public:
    TLightGlareSwitch(void *set_data, TObject *parent);
    virtual ~TLightGlareSwitch();
    virtual void render();
    virtual void run_task();
    // The object factory entry; none in split screen.
    static void *create(void *set_data);
};
LAYOUT_ASSERT(TLightGlareSwitch_size, sizeof(TLightGlareSwitch) == 0x90);

// The glares draw only while this is set; TLightGlareSwitch switches it.
extern s32 light_glare_enabled;

#endif
