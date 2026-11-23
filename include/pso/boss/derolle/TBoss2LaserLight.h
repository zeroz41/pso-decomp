#ifndef PSO_BOSS_DEROLLE_TBOSS2LASERLIGHT_H
#define PSO_BOSS_DEROLLE_TBOSS2LASERLIGHT_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

struct PointLight;

// De Rol Le's laser glow: a light that fades in to range 60 on turn_on and back out on turn_off,
// following the point it was given (the Barba Ray twin is TBoss7LaserLight).
class TBoss2LaserLight : public TObject {
public:
    enum State { OFF, FADE_IN, ON, FADE_OUT };
    enum Request { REQUEST_NONE, REQUEST_ON, REQUEST_OFF };

    Vec *m_position;
    s32 m_state;
    u32 m_request;
    f32 m_color[4];
    f32 m_range[2];
    PointLight *m_light;

    TBoss2LaserLight(TObject *parent, Vec *position);
    virtual ~TBoss2LaserLight();
    virtual void render();
    virtual void run_task();

    void turn_off();
    void turn_on();
};

LAYOUT_ASSERT(TBoss2LaserLight_size, sizeof(TBoss2LaserLight) == 0x44);

#endif
