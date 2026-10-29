#ifndef PSO_MISC_TOSENSORGENERAL01_H
#define PSO_MISC_TOSENSORGENERAL01_H

#include "types.h"
#include "pso/misc/TOSensor.h"

struct BmlResource;

// The general sensor (fs_obj_sensor): once on, its three lamps light one by
// one over 1.5 seconds while it turns, then it spins fast and rises out of
// the floor. Its head turns all the time.
class TOSensorGeneral01 : public TOSensor {
public:
    TOSensorGeneral01(TObject *parent, void *set_data);
    virtual ~TOSensorGeneral01();
    virtual void render();
    virtual void update_switch_on();
    virtual void update_switch_off();
    static void *create(void *set_data);
    static void free_assets();
    static void load_assets();

    s32 head_angle;  // the head's y rotation
    s32 lamps_dark;  // 3 to 0: lamp n is lit once lamps_dark < n
    s32 lamp_timer;  // frames left while on (from 90)
};

typedef char TOSensorGeneral01_size[sizeof(TOSensorGeneral01) == 0xF4 ? 1 : -1];

extern const char *TOSensorGeneral01__class_name;
extern BmlResource *sensor_general_shared_bml_archive;
// The red texture list, then the model's own (lit).
extern s32 *TOSensorGeneral01__texture_lists;

#endif
