#ifndef PSO_OBJECT_CITY_TOBJCITYAIRCAR_CAR_H
#define PSO_OBJECT_CITY_TOBJCITYAIRCAR_CAR_H
#include "types.h"
#include "pso/object/base/TObjMotion.h"

class TParticleCtrl;

// One air car of the city traffic: flies along its lane's path motion.
class TObjCityAirCar_Car : public TObjBase {
public:
    TObjCityAirCar_Car(TObject *parent, s32 lane, s32 model_type, f32 path_speed);
    virtual ~TObjCityAirCar_Car();
    virtual void run_task();
    virtual void render();
    s32 update_path_motion();

    f32 path_frame;
    f32 path_speed;
    s32 lane;
    s32 model_type;
    s32 uv_scroll;
    s32 light_blink;  // 0..39; the light texture swaps for the second half
    TParticleCtrl *light;
};
LAYOUT_ASSERT(TObjCityAirCar_Car_size, sizeof(TObjCityAirCar_Car) == 0xAC);

#endif
