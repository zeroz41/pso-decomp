#ifndef PSO_MISC_TOSENSORANCIENT01_H
#define PSO_MISC_TOSENSORANCIENT01_H

#include "types.h"
#include "pso/misc/TOSensor.h"

struct TOSensorAncient01 : public TOSensor {
    virtual ~TOSensorAncient01();
    void update_pulse_value();
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void vfunc_25();
    void render();
    static void *create(void *arg0);
    static void destroy();
    static void load_resources();
    s32 m_e8;
    u8 unk_EC[0x4];
    f32 m_f0;
    u8 unk_F4[0x4];
};

typedef char TOSensorAncient01_size[sizeof(TOSensorAncient01) == 0xF8 ? 1 : -1];
#endif
