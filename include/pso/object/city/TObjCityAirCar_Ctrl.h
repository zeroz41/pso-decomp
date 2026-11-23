#ifndef PSO_OBJECT_CITY_TOBJCITYAIRCAR_CTRL_H
#define PSO_OBJECT_CITY_TOBJCITYAIRCAR_CTRL_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TObjCityAirCar_Car;

// Spawns the city's air cars, at most two per lane.
class TObjCityAirCar_Ctrl : public TObject {
public:
    struct Lane {
        s32 timer;  // frames to the next spawn
        s32 count;
        TObjCityAirCar_Car *cars[2];
    };

    TObjCityAirCar_Ctrl(TObject *parent);
    virtual ~TObjCityAirCar_Ctrl();
    virtual void render();
    virtual void run_task();

    s32 pad_1C;
    f32 pad_20;
    s32 rare_car_counter;  // lanes 1 and 2 let car type 4 through once every 40 spawns
    Lane lanes[5];
};
LAYOUT_ASSERT(TObjCityAirCar_Ctrl_size, sizeof(TObjCityAirCar_Ctrl) == 0x78);

#endif
