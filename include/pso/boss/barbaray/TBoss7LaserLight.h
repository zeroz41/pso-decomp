#ifndef PSO_BOSS_BARBARAY_TBOSS7LASERLIGHT_H
#define PSO_BOSS_BARBARAY_TBOSS7LASERLIGHT_H

#include "types.h"
#include "pso/system/task/TObject.h"
#include <dolphin/mtx.h>

struct TObjLight;

extern const char *TBoss7LaserLight_name;

class TBoss7LaserLight : public TObject {
public:
    enum State { OFF, FADE_IN, ON, FADE_OUT };
    enum Request { REQUEST_NONE, REQUEST_ON, REQUEST_OFF };

    Vec *m_position;
    s32 m_state;
    u32 m_request;
    f32 m_color[4];
    f32 m_range[2];
    TObjLight *m_light;

    TBoss7LaserLight(TObject *parent, Vec *position);
    virtual ~TBoss7LaserLight();
    virtual void run_task();
    virtual void render();

    void turn_off();
    void turn_on();
};
typedef char TBoss7LaserLight_size[sizeof(TBoss7LaserLight) == 0x44 ? 1 : -1];

#endif
