#ifndef PSO_OBJECT_CITY_TOBJCITYAIRCAR_CTRL_H
#define PSO_OBJECT_CITY_TOBJCITYAIRCAR_CTRL_H
#include "types.h"
#include "pso/system/task/TObject.h"

class TObjCityAirCar_Ctrl : public TObject {
public:
    virtual ~TObjCityAirCar_Ctrl();
    virtual void render();
    virtual void run_task();
    u8 unk_1C[0x5C];
};
typedef char TObjCityAirCar_Ctrl_size[sizeof(TObjCityAirCar_Ctrl) == 0x78 ? 1 : -1];

#endif
