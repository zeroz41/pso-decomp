#ifndef PSO_UNK_TOBJCITYAIRCAR_CAR_H
#define PSO_UNK_TOBJCITYAIRCAR_CAR_H
#include "types.h"
#include "pso/object/TObjMotion.h"

class TObjCityAirCar_Car : public TObjBase {
public:
    virtual ~TObjCityAirCar_Car();
    virtual void run_task();
    s32 update_path_motion();
    u8 unk_90[0x4];
    f32 m_94;
    u8 unk_98[0x4];
    s32 m_9c;
    u8 unk_A0[0x4];
    s32 m_a4;
    u8 unk_A8[0x4];
};
typedef char TObjCityAirCar_Car_size[sizeof(TObjCityAirCar_Car) == 0xAC ? 1 : -1];

#endif
