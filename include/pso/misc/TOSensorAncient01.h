#ifndef PSO_MISC_TOSENSORANCIENT01_H
#define PSO_MISC_TOSENSORANCIENT01_H

#include "types.h"
#include "pso/misc/TOSensor.h"

struct BmlResource;

// The ruins sensor (fs_obj_o_sensor01): once on, its three lamps light one
// by one over two seconds, its head spins and its four fins pulse, then it
// rises out of the floor.
class TOSensorAncient01 : public TOSensor {
public:
    TOSensorAncient01(TObject *parent, void *set_data);
    virtual ~TOSensorAncient01();
    virtual void render();
    virtual void update_switch_on();
    virtual void update_switch_off();
    virtual void vfunc_25();
    // Swings pulse_offset between 0 and 4.
    void update_pulse_value();
    static void *create(void *set_data);
    static void destroy();
    static void load_resources();

    s32 lamp_timer;    // frames left while on (from 120); lamps lit below 30, 60, 90
    s32 spin_angle;    // the head's y rotation
    f32 pulse_offset;  // how far the fins stand out
    s32 pulse_flags;   // bit 0: pulse_offset rising
};

typedef char TOSensorAncient01_size[sizeof(TOSensorAncient01) == 0xF8 ? 1 : -1];

// set_params[2] picks the pair: the red texture list and the plain one.
struct TOSensorAncient01Textures {
    s32 red;
    s32 plain;
};

extern const char *TOSensorAncient01__class_name;
extern BmlResource *sensor_ancient01_model_resource;
extern TOSensorAncient01Textures *ancient_sensor_resource_pair_table;
extern s32 sensor_texture_table_index;

#endif
